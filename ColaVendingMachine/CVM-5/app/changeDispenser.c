#include "changeDispenser.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//------------------------------------------------------------- CHange Dispenser

void CHDinitialise(void)
{
   DSPdebugSystemInfo("Change Dispenser: initialised");
   if (KYBaskforYN("Selftest: init error"))
   {
      setSystemErrorBit(ERR_INIT_CHD);
      DSPshowDisplay();
   }
}

void CHDdispenseChange(int change)
{
   char info[100];

   snprintf(info, 100, "%s%d", "Change Dispenser: dispensed change = ", change);
   DSPdebugSystemInfo(info);
}
