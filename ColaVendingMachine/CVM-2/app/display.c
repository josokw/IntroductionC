#include "display.h"
#include "appInfo.h"
#include "systemErrors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------- DiSPlay

#define DSP_HEIGHT 10 ///< The number of available display rows
#define DSP_WIDTH 70  ///< The number of available display columns

static char display[DSP_HEIGHT][DSP_WIDTH + 1] = {{0}};
static char topDisplay[DSP_WIDTH] = {0};

void DSPinitialise(void)
{
   for (int i = 0; i < DSP_WIDTH; i++)
   {
      topDisplay[i] = '=';
   }
   strncpy(display[0], topDisplay, DSP_WIDTH);
   strncpy(display[DSP_HEIGHT - 1], topDisplay, DSP_WIDTH);
   for (int i = 1; i < DSP_HEIGHT - 1; i++)
   {
      display[i][0] = '|';
   }
   strncpy(&display[1][1], " " APP " v" VERSION, DSP_WIDTH - 5);

   DSPshowDisplay();
   DSPdebugSystemInfo("Display: initialised");
}

void DSPclear(void)
{
   if (!system(NULL))
   {
      printf("\nERROR command processor is not available\n\n");
      exit(EXIT_FAILURE); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   }

#ifdef _WIN32
   int error = system("cls"); // Execute WIN32 cls command
#endif
#ifdef __linux__
   int error = system("clear"); // Execute Linux clear command
#endif

   if (error != 0)
   {
      printf("\nERROR terminal command fails\n\n");
   }
}

void DSPclearLine(int row)
{
   strcpy(display[row], "| ");
}

void DSPshowSystemErrorBits(void)
{
   printf("|  System error bits: %s\n", getSystemErrorBitsString());
   printf("%s\n", display[0]);
}

void DSPshowDisplay(void)
{
   DSPclear();
   for (int row = 0; row < DSP_HEIGHT; row++)
   {
      printf("%s\n", display[row]);
   }
   DSPshowSystemErrorBits();
}

void DSPshow(const char text[], int row)
{
   DSPdebugSystemInfo("** Press <Enter>, for update display **");
   getchar();
   DSPclearLine(row);
   strncpy(&display[row][2], text, DSP_WIDTH - 2);
   DSPshowDisplay();
}

void DSPshowDelete(const char text[], int row)
{
   DSPdebugSystemInfo("** Press <Enter>, for update display **");
   getchar();
   for (int r = row; r < DSP_HEIGHT - 1; r++)
   {
      DSPclearLine(r);
   }
   strncpy(&display[row][2], text, DSP_WIDTH - 2);
   DSPshowDisplay();
}

void DSPdebugSystemInfo(const char text[])
{
   printf("\n-- DEBUG  %s   ", text);
}

void DSPsimulationSystemInfo(const char text[])
{
   printf("\n-- SIMULATION  %s   ", text);
}

void DSPshowSystemError(const char text[])
{
   printf("\n** SYSTEM ERROR  %s   ", text);
}
