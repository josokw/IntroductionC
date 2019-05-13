/* Test integer limits in <limits.h> header */

#include <stdio.h>
#include <limits.h>

int main()
{
   printf("int max             = %13d\n", INT_MAX);
   printf("int min             = %13d\n", INT_MIN);
   printf("unsigned int max    = %13u\n\n", UINT_MAX);

   printf("long max            = %13ld\n", LONG_MAX);
   printf("long min            = %13ld\n", LONG_MIN);
   printf("unsigned long max   = %13lu\n\n", ULONG_MAX);

   printf("Bits in char        = %13d\n", CHAR_BIT);
   printf("char max            = %13d\n", CHAR_MAX);
   printf("char min            = %13d\n", CHAR_MIN);
   printf("signed char max     = %13d\n", SCHAR_MAX);
   printf("signed char min     = %13d\n", SCHAR_MIN);
   printf("unsigned char max   = %13u\n\n", UCHAR_MAX);

   return 0;
}
