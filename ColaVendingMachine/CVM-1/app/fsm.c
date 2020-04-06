#include "fsm.h"
#include "TUI.h"
#include "coinAcceptor.h"
#include "colaDispenser.h"
#include "display.h"
#include "events.h"
#include "states.h"
#include "systemErrors.h"

#include <stdlib.h>

// static will limit the scope of global vars to this file
static state_e currentState = S_START;
static int insertedMoney = 0;
static int priceCola = 0;

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
      default:
         DSPshowSystemError("State panic: current state is not defined");
         event = E_NO;
         break;
   }

   DSPdebugSystemInfo(eventText(event));

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
         switch (event)
         {
            case E_CONTINUE:
               // Check condition for state transition
               if (getSystemErrorBit(ERR_INIT_CNA))
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
               DSPshowDelete("Please, take your cola", 3);
               CLDdispenseCola();
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError(
                  "State S_DETECTED_20C received unknown event");
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
               DSPshowDelete("Please, take your cola", 3);
               CLDdispenseCola();
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError("State S_DETECTED_50C received unkown event");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
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
   if (insertedMoney >= priceCola)
   {
      return E_ENOUGH;
   }
   return E_NOT_ENOUGH;
}
