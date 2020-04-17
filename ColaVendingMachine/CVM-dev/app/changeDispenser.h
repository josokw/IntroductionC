#ifndef CHANGEDISPENSER_H
#define CHANGEDISPENSER_H

//------------------------------------------------------------- CHange Dispenser

#define MAX_AVAILABLE_CHANGE 1000

/// Initialises the Change Dispenser (CHD) subsystem and executes a selftest.
/// Asks for initial value of available change.
void CHDinitialise(void);

/// Gets available change.
int CHDgetAvailableChange(void);

/// Sets available change.
void CHDsetAvailableChange(int avcg);

/// Dispenses change.
void CHDdispenseChange(int change);

#endif
