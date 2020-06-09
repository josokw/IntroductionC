#include "fsm.h"
#include "changeDispenser.h"
#include "coinAcceptor.h"
#include "colaDispenser.h"
#include "devConsole.h"
#include "display.h"
#include "events.h"
#include "files.h"
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
      case S_CONFIGURE:
         event = CVMconfig();
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
         DCSshowSystemError("State panic: current state %s is not used",
                            stateText(currentState));
         event = E_NO;
         break;
   }

   DCSdebugSystemInfo("State %s generated event: %s", stateText(currentState),
                      eventText(event));

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
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
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
                  nextState = S_CONFIGURE;
               }
               break;
            default:
               // Ignore all unknown events
               nextState = S_CONFIGURE;
               break;
         }
         break;

      case S_CONFIGURE:
         switch (event)
         {
            case E_CONFIG:
               nextState = S_CONFIGURE;
               break;
            case E_CONFIG_READY:
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
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
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
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
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
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
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DISPENSE:
         switch (event)
         {
            case E_NO_CHANGE_DISPENSE:
               DSPshow(5, "Sorry, no change available");
               CHDdispenseChange(insertedMoney);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_UPDATE_CHANGE;
               break;
            case E_CHANGE_DISPENSE:
               DSPshow(5, "Please take your cola, your change is %d", change);
               CLDdispenseCola();
               CHDdispenseChange(change);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DCSshowSystemError(
                  "State panic: state %s received unknown event %s",
                  stateText(currentState), eventText(event));
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_WAIT_FOR_UPDATE_CHANGE:
         DSPshow(
            5, "Ask administrator to fill change storage with %d Euro ... done",
            REFILL_CHANGE_ADMIN);
         CHDsetAvailableChange(REFILL_CHANGE_ADMIN);
         nextState = S_WAIT_FOR_COINS;
         break;

      default:
         DCSshowSystemError("State panic: CVM is in unknown current state");
         nextState = S_INITIALISED_SUBSYSTEMS;
         break;
   }
   currentState = nextState;
}

void CVMinitialiseSubSystems(void)
{
   DCSinitialise();
   CNAinitialise();
   CLDinitialise();
   CHDinitialise();

   DCSdebugSystemInfo("%s() current dir:\n   %s", __func__, getCurrentDir());
}

void CVMshutdownSubSystems(void)
{
   DCSdebugSystemInfo("CVM shuts down!!\n\n");
}

event_e CVMconfig(void)
{
   DCSdebugSystemInfo("CVM configure");

   return E_CONFIG_READY;
}

event_e CVMcheckEnoughCents(int coinValue)
{
   DSPshow(5, "       %dC", coinValue);
   insertedMoney += coinValue;
   DCSdebugSystemInfo("CVM inserted money: %d", insertedMoney);
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
