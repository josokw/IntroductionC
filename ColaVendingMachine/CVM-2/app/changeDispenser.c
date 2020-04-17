#include "changeDispenser.h"
#include "TUI.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//------------------------------------------------------------- CHange Dispenser

static int availableChange = MAX_AVAILABLE_CHANGE;

void CHDinitialise(void)
{
   DSPdebugSystemInfo("Change Dispenser: initialised");

   if (TUIsimulationSystemInputYN("Selftest Change Dispenser: init error"))
   {
      setSystemErrorBit(ERR_INIT_CHD);
      DSPshowDisplay();
   }
}

int CHDgetAvailableChange(void)
{
   return availableChange;
}

void CHDdispenseChange(int change)
{
   char info[100];

   snprintf(info, 100, "%s%d", "Change Dispenser: dispensed change = ", change);
   DSPdebugSystemInfo(info);

   DSPshowDelete("Please, take your change", 5);
}
