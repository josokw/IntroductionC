/* The program is a simple demonstration of the difference between
 * global variables and local variables.
 *
 * Software engineering guideline:
 *   you should always try to avoid the usage of global variables.
*/

#include <stdio.h>

// Always add prototypes of functions above main() for compiler checking
// of function calls, this will solve compiler warnings.
void prAgain();

int global1 = 10;

int main()
{
   float local1 = 9.0;

   printf("%d %.2f\n", global1, local1); // Prints the 1st global and first
                                         // local variable.
   prAgain(); // Calls our first function.

   return 0;
}

float global2 = 19.0;

// Implementation of function prAgain(), void: returns no value.
void prAgain()
{
   int local2 = 5;  // Local to function
   // Can't print local1: it is local to main()
   printf("%d %.2f %d\n", local2, global2, global1);
   return;  // Can be left away!
}

// In ANSI C (C89 or C90) you should use an additional void:
//   void prAgain(void);
// Neccessary for compiler checking of the parameter list of function calls.
