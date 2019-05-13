#include <stdio.h>

int func1();  // Taking an unspecified number of arguments of unspecified type.
int func2(void);  // It explicitly says: no parameters allowed.

int main()
{
   char c = 'a';

   printf("func1()      = %d\n", func1());
   // These lines will compile
   printf("func1(13)    = %d\n", func1(13));
   printf("func1(c, 1)  = %d\n", func1(c, 1));

   printf("func2()      = %d\n", func2());
   // These function calls will generate a compiler error.
   // printf("func2(13) = %d\n", func2(13));
   // printf("func2(c)  = %d\n", func2(c));

   return 0;
}

int func1()
{
   return 100;
}

int func2(void)
{
   return 200;
}
