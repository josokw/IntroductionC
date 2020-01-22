// Cola Vending Machine - 3 (CVM-3) --------------------------------------------

#include "events.h"
#include "fsm.h"

#include "coinAcceptor.h"
#include "colaDispenser.h"
#include "display.h"
#include "keyboard.h"
#include "subsystems.h"

#include <ctype.h>
#include <stdio.h>

event_e generateEvent(void);
void eventHandler(event_e event);
event_e CVMinitialise(void);
event_e CVMcheckCents(const int coinValue);
event_e CVMcheckChange(void);

//------------------------------------------------------------- global variables
state_e currentState = S_START;
event_e currentEvent = E_NO;

int insertedMoney = 0;
int priceCola = 0;
int change = 0;
int availableChange = 0;

int main(void)
{ 
   //------------------------------------------------------ FSM is event handler
   eventHandler(E_START);
   // Endless loop
   while (1)
   {
      currentEvent = generateEvent();
      eventHandler(currentEvent);
   }

   return 0;
}

//------------------------------------------------------------ generating events
// Because we do not buffer events in an event queue, we send in the
// current state only events that can be handled.
// Implementing buffering using a queue is outside the scope of this
// introduction to C programming.
event_e generateEvent(void)  // external
{
   event_e nextEvent = E_NO;
   switch(currentState)
   {
      case S_NO:
         DSPshowSystemError("current state is not initialised");
         break;
      case S_START:
         nextEvent = E_START;
         break;
      case S_INITIALISED:
         nextEvent = E_CONTINUE;
         break;
      case S_WAIT_FOR_COINS:
         DSPshow("Enter your coins please");
         nextEvent = CNAcheckCoins();
         break;
      case S_DETECTED_10C:
         nextEvent = CVMcheckCents(10);
         break;
      case S_DETECTED_20C:
         nextEvent = CVMcheckCents(20);
         break;
      case S_DISPENSE:
         nextEvent = CVMcheckChange();
         break;
      case S_WAIT_FOR_UPDATE_CHANGE:
         break;
   }

   return nextEvent;
}

//----------------------------------------------------------- implementation FSM
void eventHandler(event_e event)
{
   state_e nextState = S_NO;

   switch(currentState)
   {
      case S_START:
         CVMinitialise();
         nextState = S_INITIALISED;
         break;

      case S_INITIALISED:
         insertedMoney = 0;
         priceCola = 125;
         change = 0;
         availableChange = 20;
         nextState = S_WAIT_FOR_COINS;
         break;

      case S_WAIT_FOR_COINS:
         switch (event)
         {
            case E_10C:
               nextState = S_DETECTED_10C;
               break;
            case E_20C:
               nextState = S_DETECTED_20C;
               break;
            default:
               DSPshowSystemError("S_WAIT_FOR_COINS received event "
                                  "not handled");
               nextState = S_WAIT_FOR_COINS;
         }
         break;

      case S_DETECTED_10C:
         switch (event)
         {
            case E_ENOUGH:
               nextState = S_DISPENSE;
               break;
            case E_NOT_ENOUGH:
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError("S_10C received unknown event");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DETECTED_20C:
         switch (event)
         {  
            case E_ENOUGH:
               nextState = S_DISPENSE;
               break;
            case E_NOT_ENOUGH:
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError("S_DETECTED_10C received event "
                                  "not handled");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_DISPENSE:
         switch (event)
         {
            case E_NO_CHANGE_DISPENSE:
               DSPshow("Sorry, no change available");
               CHDdispenseChange(insertedMoney);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_UPDATE_CHANGE;
               break;
            case E_CHANGE_DISPENSE:
               DSPshow("Please take your cola");
               CLDdispenseCola();
               CHDdispenseChange(change);
               insertedMoney = 0;
               nextState = S_WAIT_FOR_COINS;
               break;
            default:
               DSPshowSystemError("S_DISPENSE received received event "
                                  "not handled");
               nextState = S_WAIT_FOR_COINS;
               break;
         }
         break;

      case S_WAIT_FOR_UPDATE_CHANGE:
         DSPshow("Ask administrator to fill change storage ... done");
         availableChange = 20;
         nextState = S_WAIT_FOR_COINS;
         break;

      default:
         DSPshowSystemError("CVM in unknown current state");
         nextState = S_INITIALISED;
         break;
   }
   currentState = nextState;
}

//------------------------------------------------ CVM functions executed in FSM

event_e CVMinitialise(void)
{
   // Initialise all subsystems (devices)
   DSPinitialise();
   KYBinitialise();
   CNAinitialise();
   CLDinitialise();
   CHDinitialise();
   DSPshow("----------------------- Cola vending machine - 3 "
           "---------------------");

   return E_CONTINUE;
}

event_e CVMcheckCents(int coinValue)
{
   insertedMoney += coinValue;
   if (insertedMoney >= priceCola)
   {
      return E_ENOUGH;
   }
   return E_NOT_ENOUGH;
}

event_e CVMcheckChange(void)
{
   change = insertedMoney - priceCola;
   if (availableChange >= change)
   {
      availableChange -= change;
      return E_CHANGE_DISPENSE;
   }
   return E_NO_CHANGE_DISPENSE;
}
