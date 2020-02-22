#ifndef STATES_H
#define STATES_H

typedef enum {
   S_NO,
   S_START, ///< Initial state
   S_INITIALISED,
   S_WAIT_FOR_COINS,
   S_DETECTED_20C,
   S_DETECTED_50C
} state_e;

#endif