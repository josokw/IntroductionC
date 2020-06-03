#include "changeDispenser.h"
#include "devConsole.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//------------------------------------------------------------- CHange Dispenser

static int availableChange = MAX_AVAILABLE_CHANGE;

void CHDinitialise(void)
{
   DCSdebugSystemInfo("Change Dispenser: initialised");

   if (DCSsimulationSystemInputYN("Selftest Change Dispenser: init error"))
   {
      setSystemErrorBit(ERR_INIT_CHD);
      DSPshowDisplay();
   }

   availableChange = DCSsimulationSystemInputInteger(
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
   DCSdebugSystemInfo("Change Dispenser: dispensed change = %d", change);

   DSPshowDelete(5, "Please, take your change");
}
