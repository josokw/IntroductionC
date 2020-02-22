#ifndef FSM_H
#define FSM_H

#include "events.h"

/// Because we do not buffer events in an event queue, we send in the
/// current state, #currentState, only events that can be handled.
/// Implementing buffering using a queue and multi-threading is outside
/// the scope of this introduction to C programming.
/// \return Generated event for the #eventHandler function.
event_e generateEvent(void);

/// Uses the global variable #currentState to determine how to process the
/// received #event.
/// If an #event is received that should not be in handled in the
/// currentState this is considered as a system error.
/// The switch statements use the default case to show an appropriate
/// message to the display. It is necessary to give in all default cases
/// the nextState an appropriate value to avoid undefined behaviour. \post
/// Updated #currentState by nextSate.
void eventHandler(event_e event);

/// Initialises all subsystems (devices) and puts an initial text to the
/// display.
event_e CVMinitialise(void);

/// Shutdowns all subsystems.
void CVMshutdown(void);

event_e CVMcheckCents(int coinValue);
event_e CVMcheckChange(void);

#endif // FSM_H
