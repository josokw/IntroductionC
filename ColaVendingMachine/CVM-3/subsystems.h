#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

#include "events.h"
#include "fsm.h"

//--------------------------------------------------------------- CoLa Dispenser

void CLDinitialise(void);
void CLDdispenseCola(void);

//------------------------------------------------------------- CHange Dispenser

void CHDinitialise(void);
void CHDdispenseChange(int change);

#endif
