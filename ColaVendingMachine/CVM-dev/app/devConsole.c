#include "devConsole.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
