#ifndef FSM_H
#define FSM_H

typedef enum {
   S_NO, // used for initialisation of a state variable
   S_START,
   S_INITIALISED,
   S_WAIT_FOR_COINS,
   S_DETECTED_10C,
   S_DETECTED_20C,
   S_DISPENSE,
   S_WAIT_FOR_UPDATE_CHANGE
} state_e;

#endif // FSM_H
