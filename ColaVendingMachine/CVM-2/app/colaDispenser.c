#include "colaDispenser.h"
#include "display.h"

//--------------------------------------------------------------- CoLa Dispenser

void CLDinitialise(void)
{
   DSPdebugSystemInfo("Cola Dispenser: initialised");
}

void CLDdispenseCola(void)
{
   DSPshowDelete("Please, take your cola", 3);
   DSPdebugSystemInfo("Cola Dispenser: dispensed cola");
}
