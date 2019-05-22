/* The program demonstrates passing a variable to a function by
 * value.
*/

#include <stdio.h>

// Prototype of function(s).
void half(int v);

int main()
{
   int i = 0;
   printf("Please enter an integer... ");
   scanf(" %d", &i);

   // Now call the half function, passing the value of i.
   // Call by value, function copies i (actual parameter).
   half(i);
   // Input parameter: constant 222.
   half(222);
   // Input parameter: expression.
   half(i * 4 + 100);
   // Shows that the function did not alter i's value.
   printf("\nIn main(), i is still %d.\n\n", i);

   return 0;
}

/******************************************************************************/

/* Sometimes putting dividers like the one above is a nice break
 * between your different functions.
*/
void half(int v) // v is a formal parameter.
{
   v = v / 2;
   printf("half() input value halved is %d.\n", v);
}
