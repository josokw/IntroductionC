#include "fsm.h"
#include "TUI.h"
#include "changeDispenser.h"
#include "coinAcceptor.h"
#include "colaDispenser.h"
#include "display.h"
#include "events.h"
#include "states.h"
#include "systemErrors.h"

#include <stdlib.h>

#define REFILL_CHANGE_ADMIN 100

// static will limit the scope of global vars to this file
static state_e currentState = S_START;
static int insertedMoney = 0;
static int priceCola = 0;
static int change = 0;

event_e generateEvent(void)
{
   event_e event = E_NO;

   switch (currentState)
   {
      case S_START: // Initial state
         event = E_START;
         break;
      case S_INITIALISED_SUBSYSTEMS:
         event = E_CONTINUE;
         break;
      case S_WAIT_FOR_COINS:
         event = CNAinputCoins();
         break;
      case S_DETECTED_20C:
         event = CVMcheckEnoughCents(20);
         break;
      case S_DETECTED_50C:
         event = CVMcheckEnoughCents(50);
         break;
      case S_DISPENSE:
         event = CVMcheckChange();
         break;
      case S_WAIT_FOR_UPDATE_CHANGE:
         break;
      default:
         DSPshowSystemError("State panic: current state is not defined");
         event = E_NO;
         break;
   }

   DSPdebugSystemInfo("Generated event: %s", eventText(event));

   return event;
}

void eventHandler(event_e event)
{
   state_e nextState = S_NO;

   switch (currentState)
   {
      case S_START:
         switch (event)
         {
            case E_START:
               CVMinitialiseSubSystems();
               nextState = S_INITIALISED_SUBSYSTEMS;
               break;
            default:
               DSPshowSystemError(
                  "State panic: state S_START received unknown event");
               exit(EXIT_FAILURE); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
         }
         break;

      case S_INITIALISED_SUBSYSTEMS:
         insertedMoney = 0;
         priceCola = 125;
         change = 0;

         switch (event)
         {
            case E_CONTINUE:
               // Check condition for state transition
               if (getSystemErrorBit(ERR_INIT_CNA) ||
                   getSystemErrorBit(ERR_INIT_CHD) ||
                   getSystemErrorBit(ERR_INIT_CLD))
               {
                  CVMshutdownSubSystems();
                  exit(EXIT_FAILURE); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
               }
               else
               {
                  nextState = S_WAIT_FOR_COINS;
               }
               break;
            default:
               // Ignore all unknown events
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_WAIT_FOR_COINS:
         switch (event)
         {
            case E_20C:
               nextState = S_DETECTED_20C;
               break;
            case E_50C:
               nextState = S_DETECTED_50C;
               break;
            default:
               DSPshowSystemError(
                  "State panic: state S_WAIT_FOR_COINS"
                  "received unknown event");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DETECTED_20C:
         switch (event)
         {
            case E_NOT_ENOUGH:
               nextState = S_WAIT_FOR_COINS;
               break;
            case E_ENOUGH:
               change = insertedMoney - priceCola;
               insertedMoney = 0;
               nextState = S_DISPENSE;
               break;
            default:
               DSPshowSystemError(
                  "State panic: stae S_DETECTED_20C received unknown event");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DETECTED_50C:
         switch (event)
         {
            case E_NOT_ENOUGH:
               nextState = S_WAIT_FOR_COINS;
               break;
            case E_ENOUGH:
               change = insertedMoney - priceCola;
               nextState = S_DISPENSE;
               break;
            default:
               DSPshowSystemError(
                  "State panic: state S_DETECTED_50C received unkown event");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DISPENSE:
         switch (event)
         {
            case E_NO_CHANGE_DISPENSE:
               DSPshow("Sorry, no change available", 5);
               CHDdispenseChange(insertedMoney);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_UPDATE_CHANGE;
               break;
            case E_CHANGE_DISPENSE:
               DSPshow("Please take your cola", 5);
               CLDdispenseCola();
               CHDdispenseChange(change);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError(
                  "S_DISPENSE received received event "
                  "not handled");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_WAIT_FOR_UPDATE_CHANGE:
         DSPshow("Ask administrator to fill change storage ... done", 5);
         CHDsetAvailableChange(REFILL_CHANGE_ADMIN);
         nextState = S_WAIT_FOR_COINS;
         break;

      default:
         DSPshowSystemError("State panic: CVM is in unknown current state");
         nextState = S_INITIALISED_SUBSYSTEMS;
         break;
   }
   currentState = nextState;
}

void CVMinitialiseSubSystems(void)
{
   TUIinitialise();
   CNAinitialise();
   CLDinitialise();
   CHDinitialise();
}

void CVMshutdownSubSystems(void)
{
   DSPdebugSystemInfo("CVM shuts down!!\n\n");
}

event_e CVMcheckEnoughCents(int coinValue)
{
   switch (coinValue)
   {
      case 20:
         DSPshow("     20C", 5);
         break;
      case 50:
         DSPshow("     50C", 5);
         break;
   }
   insertedMoney += coinValue;
   DSPdebugSystemInfo("CVM inserted money: %d", insertedMoney);
   if (insertedMoney >= priceCola)
   {
      return E_ENOUGH;
   }
   return E_NOT_ENOUGH;
}

event_e CVMcheckChange(void)
{
   change = insertedMoney - priceCola;
   if (CHDgetAvailableChange() >= change)
   {
      CHDsetAvailableChange(CHDgetAvailableChange() - change);
      return E_CHANGE_DISPENSE;
   }
   return E_NO_CHANGE_DISPENSE;
}
