#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
   E_NO,         ///< Used for initialisation of an event variable.
   E_START,      ///< first event after CVM is switched on.
   E_CONTINUE,   ///< Initialising subsystems is ready.
   E_20C,        ///< 20C coin.
   E_50C,        ///< 50C coin.
   E_NOT_ENOUGH, ///< Not enough coins inserted
   E_ENOUGH      ///< Enough coins inserted
} event_e;

#endif
