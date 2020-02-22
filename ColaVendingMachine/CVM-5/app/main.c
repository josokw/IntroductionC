// Cola Vending Machine --------------------------------------------------------

#include "fsm.h"

/// Executes the state machine (FSM: Finite State Machine) in an endless loop 
/// processing the generated events by the subsystems.
/// The state machine is executed by the function #eventHandler.
/// \author Jos Onokiewicz
int main(void)
{
   event_e currentEvent = E_START;

   eventHandler(currentEvent);
   // Endless loop
   while (1)
   {
      currentEvent = generateEvent();
      eventHandler(currentEvent);
   }

   return 0;
}
