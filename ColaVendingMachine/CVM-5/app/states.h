#ifndef STATES_H
#define STATES_H

typedef enum {
   S_NO,
   S_START,
   S_INITIALISED,
   S_WAIT_FOR_COINS,
   S_DETECTED_10C,
   S_DETECTED_20C,
   S_DISPENSE,
   S_WAIT_FOR_UPDATE_CHANGE
} state_e;

#endif