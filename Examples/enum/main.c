#include <stdio.h>

/* Avoid this coding approach, use an enumeration */
#define START 0
#define STOP 1
#define FASTER 2
#define SLOWER 3

/* Enumeration of constants: enumerated data type
 *                0        1        2         3   */
enum command {CMD_START, CMD_STOP, CMD_FASTER, CMD_SLOWER};
enum day {D_SUNDAY, D_MONDAY, D_TUESDAY, D_WEDNESDAY, D_THURSDAY,
          D_FRIDAY, D_SATURDAY};
enum coin {C_10C = 10, C_20C = 20, C_50C = 50, C_1EURO = 100, C_2EURO = 200};

int main()
{
   enum command cmd = CMD_START;
   enum day today = D_SATURDAY;
   enum coin money = C_20C;

   printf("  cmd = %d, today = %d, money = %d\n\n", cmd, today, money);
   cmd = 1234;  /* this is allowed, but is not correct */
   if (today == D_SATURDAY)
   {
      today = D_SUNDAY;
   }
   else
   {
      today++;  /* do not increment D_SATURDAY */
   }
   money = C_2EURO;
   printf("  cmd = %d, today = %d, money = %d\n\n", cmd, today, money);

   return 0;
}
