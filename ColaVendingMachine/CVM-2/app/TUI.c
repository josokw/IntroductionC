#include "TUI.h"
#include "display.h"
#include "keyboard.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void TUIinitialise(void)
{
   DSPinitialise();
   KYBinitialise();
   DSPdebugSystemInfo("TUI: initialised");
}

int TUIsimulationSystemInputYN(const char questionText[])
{
   char input = '\0';

   printf("\n-- SIMULATION  %s [y/n]? ", questionText);

   scanf("%c", &input);
   input = toupper(input);
   KYBclear();

   return (input == '\n' || input == 'Y');
}

char TUIsimulationSystemInputChar(const char text[], const char chrs[])
{
   char input = '\0';
   int again = 0;

   do
   {
      printf("\n-- SIMULATION  %s   ", text);
      if (again)
      {
         printf("AGAIN   ");
      }
      input = KYBgetchar();
      again = 1;
   } while (strchr(chrs, input) == NULL);

   return input;
}

int TUIsimulationSystemInputInteger(const char text[], int min, int max)
{
   int input = 0;
   int again = 0;

   do
   {
      printf("\n-- SIMULATION  %s   ", text);
      if (again)
      {
         printf("AGAIN   ");
      }
      input = KYBgetint(min - 1);
      again = 1;
   } while (input < min || input > max);

   return input;
}
