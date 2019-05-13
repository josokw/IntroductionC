#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 64

int main(void)
{
   time_t time_start;
   time_t time_now;
   struct tm *pTime;
   char time_str[MAX_SIZE];

   /* Get time in seconds */
   time(&time_start);

   /* Display local time */
   printf("Local time: %s\n", asctime(localtime(&time_start)));
   /* Custom build the format of the date/time */
   pTime = localtime(&time_start);
   strftime(time_str, MAX_SIZE, "%H:%M:%S", pTime);

   /* Display new format string */
   printf("Local time: %s, press a key ", time_str);

   /* Introduce some delay, wait for a keypress */
   getchar();

   /* Get time in seconds */
   time(&time_now);
   pTime = localtime(&time_now);
   strftime(time_str, MAX_SIZE, "%H:%M:%S", pTime);

   /* Display time and eleapsed time in seconds */
   printf("Local time: %s\n-- Elapsed time = %d sec.\n\n",
          time_str, (int)difftime(time_now, time_start));

   return 0;
}

