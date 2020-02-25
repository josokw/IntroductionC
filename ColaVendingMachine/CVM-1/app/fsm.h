#ifndef FSM_H
#define FSM_H

#include "events.h"

/// Because we do not buffer events in an event queue, we send in the
/// current state, #currentState, only events that can be handled
/// according to the state chart diagram.
/// Implementing buffering, using a queue and multi-threading is outside
/// the scope of this introduction to C programming.
/// \return Generated event for the eventHandler() function.
event_e generateEvent(void);

/// Uses the global variable #currentState to determine how to process the
/// received #event.
/// If an #event is received that should not be in handled in the
/// currentState this is considered as a system error.
/// The switch statements use the default case to show an appropriate
/// message to the display. It is necessary to give in all default cases
/// the nextState an appropriate value to avoid undefined behaviour. 
/// \post Updated #currentState by nextSate.
void eventHandler(event_e currentEvent);

/// Initialises all subsystems.
/// \post All subsystems initialised.
void CVMinitialiseSubSystems(void);

/// Shutdowns all subsystems.
/// \todo implement a shutdown function for every subsystem. 
void CVMshutdownSubSystems(void);

/// Checks if the full price of the Cola is paid.
event_e CVMcheckEnoughCents(int coinValue);

#endif // FSM_H
