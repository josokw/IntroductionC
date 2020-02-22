#include "coinAcceptor.h"
#include "display.h"
#include "keyboard.h"
#include "systemErrors.h"

#include <stdio.h>

//---------------------------------------------------------------- CoiN Acceptor

void CNAinitialise(void)
{
   DSPdebugSystemInfo("Coin Acceptor: initialised");
   if (KYBaskforYN("Selftest: init error"))
   {
      setSystemErrorBit(ERR_INIT_CNA);
      DSPshowDisplay();
   }
}

char CNAinputCoin(void)
{
   int coinIsOK = 0;
   char coin = '0';
   while (!coinIsOK)
   {
      coin = KYBgetchar();
      switch (coin)
      {
         case '1':
         case '2':
            coinIsOK = 1;
            DSPclearLine(5);
            break;
         default:
            DSPdebugSystemInfo("Coin Acceptor: unknown coin");
            DSPshow("     unknown coin", 5);
            DSPsimulationSystemInfo("Enter a coin: <1> 10c  <2> 20c");
            break;
      }
   }
   return coin;
}

event_e CNAcheckCoins(void)
{
   char coin = '0';
   event_e event = E_NO;

   DSPsimulationSystemInfo("Enter a coin: <1> 10c  <2> 20c");
   coin = CNAinputCoin();
   switch (coin)
   {
      case '1':
         event = E_10C;
         break;
      case '2':
         event = E_20C;
         break;
   }
   return event;
}
