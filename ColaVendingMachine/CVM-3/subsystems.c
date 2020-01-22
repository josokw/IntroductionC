#include "display.h"
#include "fsm.h"
#include "keyboard.h"
#include "subsystems.h"

#include <stdio.h>

//--------------------------------------------------------------- CoLa Dispenser

void CLDinitialise(void)
{
   DSPdebugSystemInfo("Cola Dispenser: initialised");
}

void CLDdispenseCola(void)
{
   DSPshow("Cola dispensed, please take your cola");
}

//------------------------------------------------------------- CHange Dispenser

void CHDinitialise(void)
{
   DSPdebugSystemInfo("Change Dispenser: initialised");
}

void CHDdispenseChange(int change)
{
   char info[DISPLAY_SIZE];
   sprintf(info, "Change dispensed, please take the change %d cents",
           change);
   DSPshow(info);
}
