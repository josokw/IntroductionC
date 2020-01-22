#include "display.h"
#include "fsm.h"
#include "keyboard.h"
#include "subsystems.h"

#include <stdio.h>

//---------------------------------------------------------------- CoiN Acceptor

void CNAinitialise(void)
{
   DSPdebugSystemInfo("Coin Acceptor: initialised");
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
           break;
         default:
            DSPdebugSystemInfo("Coin Acceptor: unknown coin");
            DSPsimulationSystemInfo("Coins: <1> 10c  <2> 20c");
            break;
      }
   }
   return coin;
}

event_e CNAcheckCoins(void)
{
   char coin = '0';
   event_e event = E_NO;

   DSPsimulationSystemInfo("Coins: <1> 10c  <2> 20c");
   coin = CNAinputCoin();
   switch(coin)
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
