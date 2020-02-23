#include "coinAcceptor.h"
#include "TUI.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//---------------------------------------------------------------- CoiN Acceptor

void CNAinitialise(void)
{
   DSPdebugSystemInfo("Coin Acceptor: initialised");
   if (TUIaskforYN("Selftest: init error"))
   {
      setSystemErrorBit(ERR_INIT_CNA);
      DSPshowDisplay();
   }
}

event_e CNAinputCoins(void)
{
   char coin = '0';
   event_e event = E_NO;

   DSPshowDelete("Enter your coins please", 3);
   coin = TUIsimulationSystemInputChar("Enter a coin: <1> 20c  <2> 50c", "12");
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
