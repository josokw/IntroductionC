/* -----------------------------------------------------------------------------
 * This ANSI-C program contains some compile time errors and several
 * run time errors (bugs). Solve these errors.
 *
 * C does not do any run time time checking for array boundaries.
 * Do not use any C++ language features!!
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS 10

int maxOf(int i1, int i2);
int findMax(const int data[], int size);
double average3ints(int i1, int i2, int i3);
double average(const int data[], int size);

int main(void)
{
   int data1[10] = {1, 2, 150, -10, 0, 20, -50};
   int data2[6] = {0, 1, 0, 0, 1, 1};
   char text[MAXCHARS] = "abcdef";

   puts("Program started with testing --------------------------------\n");

   printf("maxOf(0, 3) = %d\n", maxOf(0, 3));
   printf("maxOf(-2, 2) = %d\n", maxOf(-2, 2));
   printf("maxOf(-10, -5) = %d\n\n", maxOf(-10, -5));

   printf("findMax(data1, 10) = %d\n", findMax(data1, 10));
   printf("findMax(data2, 10) = %d\n\n", findMax(data2, 10));

   printf("average3ints(1, 2, 3) = %lf\n", average3ints(1, 2, 3));
   printf("average3ints(-1, 2, -3) = %lf\n\n", average3ints(-1, 2, -3));

   printf("average(data2, 6) = %lf\n\n", average(data1, 6));

   puts("\nProgram ready ---------------------------------------------\n");

   return 0;
}

/* Implementation of functions ------------------------------------------*/

int maxOf(int i1, int i2)
{
   int max;

   if (i2 < max)
   {
      max = i2;
   }
   return max;
}

int findMax(const int data[], int size)
{
   int max = INT_MIN;
   int i = 0;

   for (i = 0; i <= size; i++)
   {
      max = maxOf(max, data[i]);
   }
   return max;
}

double average3ints(int i1, int i2, int i3)
{
   return i1 + i2 + i3 / 3;
}

double average(const int data[], int size)
{
   double averageResult = 0.0;
   int i = 0;

   for (i = 1; i < size; i++)
   {
      averageResult = data[i];
   }
   averageResult /= size;
   return averageResult;
}

