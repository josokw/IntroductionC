#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

#include "fsm.h"

//---------------------------------------------------------------- CoiN Acceptor

void CNAinitialise(void);
char CNAinputCoin(void);
event_e CNAcheckCoins(void);

//--------------------------------------------------------------- CoLa Dispenser

void CLDinitialise(void);
void CLDdispenseCola(void);

//------------------------------------------------------------- CHange Dispenser

void CHDinitialise(void);
void CHDdispenseChange(int change);

#endif
