/* A macro is a fragment of code which has been given a name.
 * Whenever the name is used, it is replaced by the contents of the macro.
 * Executed by the preprocessor before compiling.
 *
 * Software engineering guidelines:
 *   Names are the heart of programming. Avoid "magic numbers".
 *   Name constants in upper-case.
*/

#include <math.h>
#include <stdio.h>

#define MAX 100
#define MIN (-10 * MAX)
#define SQRT2 sqrt(2.0)
/* long int type: postfixed by L */
#define BIGPOS 1234567890L
#define BIGNEG -BIGPOS
#define BITMASK 0xF0
#define INFO  "Hai, some information!"

/* Function macro: do not forget the parentheses (1 << (x)) */
#define BIT(x) (1 << (x))

int main()
{
  int i = 2;
  int z = 0;

  printf("-- MAX    = %d\n", MAX);
  printf("-- MIN    = %d\n", MIN);
  printf("-- SQR2   = %lf\n", SQRT2);
  printf("-- BIGNEG = %ld\n", BIGNEG);
  printf("-- INFO   = %s\n", INFO);
  /* Pi is defined in math.h */
  printf("-- PI     = %lf\n\n", M_PI);

  z = BIT(3);      /* 1 << (3) */
  printf("--      z = %5d  0x%0x\n", z, z);
  z = BIT(i * 2);  /* 1 << (i * 2) */
  printf("--      z = %5d  0x%0x\n\n", z, z);

  return 0;
}
