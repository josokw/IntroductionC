#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
   int i = 0;
   int dice = 0;

   printf("Always same sequence:\n");
   for (i = 0; i < 10; i++)
   {
      dice = (rand() % 6) + 1;
      printf(" random dice = %d\n", dice);
   }
   printf("\n");

   printf("Sequence seeded by time:\n");
   srand(time(NULL));
   for (i = 0; i < 10; i++)
   {
      dice = (rand() % 6) + 1;
      printf(" random dice = %d\n", dice);
   }
   printf("\n");

   return 0;
}
