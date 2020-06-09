#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
   E_NO,                ///< Used for initialisation of an event variable
   E_START,             ///< First event after CVM is switched on
   E_CONFIG,            ///< Ask for next config step
   E_CONFIG_READY,      ///< Configuring ready
   E_CONTINUE,          ///< Initialising subsystems is ready
   E_20C,               ///< 20C coin inserted
   E_50C,               ///< 50C coin inserted
   E_NOT_ENOUGH,        ///< Not enough coins inserted
   E_ENOUGH            ///< Enough coins inserted
} event_e;

const char* eventText(event_e);

#endif
