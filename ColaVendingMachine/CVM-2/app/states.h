#ifndef STATES_H
#define STATES_H

typedef enum {
   S_NO,    ///< Used for initialisation if state is not yet known
   S_START, ///< Initial state
   S_INITIALISED_SUBSYSTEMS, ///< All subsystems initialised
   S_CONFIGURE,              ///< Configure CVM by administrator
   S_WAIT_FOR_COINS,         ///< Wait for coin inserts
   S_DETECTED_20C,           ///< Detected 20 cents coin insert
   S_DETECTED_50C            ///< Detected 50 cents coin insert
} state_e;

const char *stateText(state_e state);

#endif
