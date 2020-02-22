#ifndef COINACCEPTOR_H
#define COINACCEPTOR_H

#include "events.h"

//---------------------------------------------------------------- CoiN Acceptor

/// Initialises the Coin Acceptor (CNA) subsystem and executes a selftest.
void CNAinitialise(void);

/// Checks in a loop if the input of a coin code is correct.
/// If the entered value is not correct this function will ask again for
/// input.
/// \return Entered coin code.
char CNAinputCoin(void);

/// Simulates the entering of coins.
/// \return Generated CNA subsystem event.
event_e CNAcheckCoins(void);

#endif
