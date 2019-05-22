/* The program demonstrates passing an array to a function.
 *
 * The array identifier is a pointer, a function will copy this
 * pointer.
*/

#include <stdio.h>
#include <string.h>

void change(char text[]);

int main()
{
   char name[15] = "Michael Hatton";

   printf("In main(),      the name is     %s.\n", name);
   change(name);
   printf("Back in main(), the name is now %s.\n", name);

   return 0;
}

/******************************************************************************/

void change(char text[])
{
   // Change the string stored at the address pointed to by text
   strcpy(text, "XXXXXXXXXXXXXX");
}
