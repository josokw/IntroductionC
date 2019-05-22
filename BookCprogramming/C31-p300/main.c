/* The program demonstrates passing multiple variables to a function.
 *
 * Software engineering guideline:
 *   passing arrays to functions needs a size parameter (except strings).
*/

#include <stdio.h>

#define SIZE_ARRAY 5

// The following statement is explained in Chapter 32.
void changeSome(int offset, float *pFlt, int data[], int sizeData);

int main()
{
   int i = 10;
   int ctr = 0;
   float x = 20.5;
   int iAry[] = {10, 20, 30, 40, 50};

   puts("Here are main()'s locall variables before the function call:");
   printf("  i is %d\n", i);
   printf("  x is %.1f\n", x);

   for (ctr = 0; ctr < SIZE_ARRAY; ctr++)
   {
      printf("  iAry[%d] is %d\n", ctr, iAry[ctr]);
   }

   // Now call the changeSome function, passing the value of i
   // and the address of x (hence, the &).
   changeSome(i, &x, iAry, SIZE_ARRAY);

   puts("\n\nHere are main()'s variables after the function call:");
   printf("  i is %d\n", i);
   printf("  x is %.1f\n", x);

   for (ctr = 0; ctr < 5; ctr++)
   {
      printf("  iAry[%d] is %d\n", ctr, iAry[ctr]);
   }

   return 0;
}

/******************************************************************************/

void changeSome (int offset, float *pFlt, int data[], int sizeData)
{
   // All variables are changes, except offset and size.
   int i = 0;

   *pFlt = sizeData * 97.6;
   for (i = 0; i < sizeData; i++)
   {
      data[i] = 100 * i + offset;
   }
}
