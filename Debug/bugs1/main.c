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

/*!
 * Returns the largets of i1 and i2. If both are equivalent i1 is returned.
 */
int maxOf(int i1, int i2);
/*!
 * Returns the largetst value in data array.
 * \pre size >= 1
 */
int findMax(const int data[], int size);
/*!
 * Returns the average value of i1, i2 and i3.
 */
double average3ints(int i1, int i2, int i3);
/*!
 * Returns the average value of all values in data array.
 * \pre size >= 1
 */
double average(const int data[], int size);

int main(void)
{
   int data1[7] = {1, 2, 150, -10, 0, 20, -50};
   int data2[6] = {0, 1, 0, 0, 1, 1};
   int i = 0;

   puts("Program debug1 started with testing ------------------------------\n");

   printf("maxOf(0, 3) = %d\n", maxOf(0, 3));
   printf("maxOf(-2, 2) = %d\n", maxOf(-2, 2));
   printf("maxOf(-10, -5) = %d\n\n", maxOf(-10, -5));

   printf("data1 = ");
   for (i = 0; i < 7; i++)
   {
      printf("%d ", data1[i]);
   }
   printf("\nfindMax(data1, 7) = %d\n\n", findMax(data1, 7));

   printf("data2 = ");
   for (i = 0; i < 6; i++)
   {
      printf("%d ", data2[i]);
   }
   printf("\nfindMax(data2, 6) = %d\n\n", findMax(data2, 6));

   printf("average3ints(1, 2, 3) = %lf\n", average3ints(1, 2, 3));
   printf("average3ints(-1, 2, -3) = %lf\n\n", average3ints(-1, 2, -3));

   printf("average(data1, 7) = %lf\n", average(data1, 6));
   printf("average(data2, 6) = %lf\n", average(data2, 6));
   
   puts("\nProgram ready --------------------------------------------------\n");

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

   return averageResult += size;
}
