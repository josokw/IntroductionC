#include "systemErrors.h"

static systemErrors_t systemErrors = 0b00000000;
static char systemErrorsString[sizeof(systemErrors) * 8 + 1] = "00000000";

int setSystemError(error_t err)
{
   int systemErrorBit = getSystemError(err);

   systemErrors |= 0x01 << err;

   return systemErrorBit;
}

int getSystemError(error_t err)
{
   return (systemErrors & (0x01 << err)) != 0;
}

systemErrors_t getSystemErrors(void)
{
   return systemErrors;
}

const char *getSystemErrorsString(void)
{
   for (int i = 0; i < sizeof(systemErrors) * 8; i++)
   {
      systemErrorsString[i] = '0';
      if (getSystemError(i))
      {
         systemErrorsString[i] = '1';
      }
   }
   return systemErrorsString;
}
