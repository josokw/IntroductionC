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

   availableChange = TUIsimulationSystemInputInteger(
      "Initial value amount of change?", 0, MAX_AVAILABLE_CHANGE);
}

int CHDgetAvailableChange(void)
{
   return availableChange;
}

void CHDsetAvailableChange(int avcg)
{
   availableChange = avcg;
}

void CHDdispenseChange(int change)
{
   char info[100];

   snprintf(info, 100, "%s%d", "Change Dispenser: dispensed change = ", change);
   DSPdebugSystemInfo(info);

   DSPshowDelete("Please, take your change", 5);
}
