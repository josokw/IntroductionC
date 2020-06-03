#include "coinAcceptor.h"
#include "devConsole.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//---------------------------------------------------------------- CoiN Acceptor

void CNAinitialise(void)
{
   DCSdebugSystemInfo("Coin Acceptor: initialised");
   if (DCSsimulationSystemInputYN("Selftest Coin Acceptor: init error"))
   {
      setSystemErrorBit(ERR_INIT_CNA);
      DSPshowDisplay();
   }
}

event_e CNAinputCoins(void)
{
   char coin = '0';
   event_e event = E_NO;

   DSPshowDelete(3, "Enter your coins please");
   coin = DCSsimulationSystemInputChar("Enter a coin: <1> 20c  <2> 50c", "12");
   switch (coin)
   {
      case '1':
         event = E_20C;
         break;
      case '2':
         event = E_50C;
         break;
   }
   return event;
}
