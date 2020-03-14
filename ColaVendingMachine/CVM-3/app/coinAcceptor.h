#ifndef COINACCEPTOR_H
#define COINACCEPTOR_H

#include "events.h"

//---------------------------------------------------------------- CoiN Acceptor

/// Initialises the Coin Acceptor (CNA) subsystem and executes a selftest.
/// \post System error bit set. 
void CNAinitialise(void);

/// Simulates the entering of coins.
/// \return Generated CNA subsystem event.
event_e CNAinputCoins(void);

#endif
