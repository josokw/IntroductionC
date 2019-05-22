/* The program demonstrates passing a variable to a function by address.
 *
 * Software engineering guideline:
 *   use a p as prefix voor pointer variable identifiers.
*/

#include <stdio.h>

void half(int *pValue);

int main()
{
   int i = 0;

   printf("Please enter an integer... ");
   scanf(" %d", &i);
   // Now call the half function, passing the address of i (& address operator)
   half(&i);

   // half(&33); // Not possible, 33 is a constant ==> compiler error
   // half(33);  // Possible, 33 looks like a memory adddress, dangerous!!
                 // ==> compiler warning

   // Shows that the function did alter i's value.
   printf("In main(), i is now %d.\n", i);

   return 0;
}

/******************************************************************************/

void half(int *pValue) // Receives the address of pValue, formal parameter.
{
   *pValue = *pValue / 2;
   printf("Your value halved is %d.\n", *pValue);
}
