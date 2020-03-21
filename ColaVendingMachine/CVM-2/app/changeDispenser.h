#ifndef CHANGEDISPENSER_H
#define CHANGEDISPENSER_H

//------------------------------------------------------------- CHange Dispenser

#define MAX_AVAILABLE_CHANGE 1000

/// Initialises the Change Dispenser (CHD) subsystem and executes a selftest.
void CHDinitialise(void);

/// Gets available change.
int CHDgetAvailableChange(void);

/// Dispenses change.
void CHDdispenseChange(int change);

#endif
