#include <stdio.h>

/* Formatted output of doubles, readable output format */
int main()
{
   double d1 = 1.1;
   double d2 = 22.22;
   double d3 = -333.33333;

   /* default precision 6 */
   printf("Standard format: '%lf' '%lf' '%lf'\n", d1, d2, d3);

   printf("9 positions    : '%9lf' '%9lf' '%9lf'\n", d1, d2, d3);

   printf("var positions  : '%*.*lf' '%*.*lf' '%*.*lf'\n",
          9, 1, d1, 9, 2, d2, 9, 3, d3);

   printf("10 pos 2 digits: '%10.2lf' '%10.2lf' '%10.2lf'\n", d1, d2, d3);

   printf("left alligned  : '%-10.2lf' '%-10.2lf' '%-10.2lf'\n", d1, d2, d3);

   printf("+ sign         : '%+10.2lf' '%+10.2lf' '%+10.2lf'\n", d1, d2, d3);

   printf("+ leading 0    : '%+010.2lf' '%+010.2lf' '%+010.2lf'\n", d1, d2, d3);

   printf("pos <          : '%1.3lf' '%1.3lf' '%1.3lf'\n", d1, d2, d3);

   printf("exponential    : '%12.0e' '%12.1e' '%12.2e'\n", d1, d2, d3);

   return 0;
}
