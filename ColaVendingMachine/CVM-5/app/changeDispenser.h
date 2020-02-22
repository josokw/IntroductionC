#ifndef CHANGEDISPENSER_H
#define CHANGEDISPENSER_H

//------------------------------------------------------------- CHange Dispenser

/// Initialises the Change Dispenser (CHD) subsystem and executes a selftest.
void CHDinitialise(void);

/// Dispenses change.
void CHDdispenseChange(int change);

#endif
