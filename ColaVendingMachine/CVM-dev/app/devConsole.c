#include "devConsole.h"
#include "display.h"
#include "keyboard.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DCSinitialise(void)
{
   DSPinitialise();
   KYBinitialise();
   DCSdebugSystemInfo("Development Console: initialised");
}

int DCSsimulationSystemInputYN(const char questionText[])
{
   char input = '\0';

   printf("\n-- SIMULATION  %s [y/n]? ", questionText);

   scanf("%c", &input);
   input = toupper(input);
   KYBclear();

   return (input == '\n' || input == 'Y');
}

char DCSsimulationSystemInputChar(const char text[], const char chrs[])
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

int DCSsimulationSystemInputInteger(const char text[], int min, int max)
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

void DCSdebugSystemInfo(const char fmt[], ...)
{
   va_list arg;

   printf("\n-- DEBUG  ");
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
}

void DCSsimulationSystemInfo(const char fmt[], ...)
{
   va_list arg;

   printf("\n-- SIMULATION  ");
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
}

void DCSshowSystemError(const char fmt[], ...)
{
   va_list arg;

   printf("\n-- SYSTEM ERROR  ");
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
}
