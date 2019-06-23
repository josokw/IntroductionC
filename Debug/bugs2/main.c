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

int countChar(const char text[], char c);
void reverseString(char text[]);

int main(void)
{
   char text[MAXCHARS] = "abcdef";

   puts("Program started with testing --------------------------------\n");

   printf("countChar(\"abbccc\", 'a') = %d\n", countChar("abbccc", 'c'));
   printf("countChar(\"abbccc\", 'x') = %d\n\n", countChar("abbccc", 'x'));

   reverseString(text);
   printf("reverseString(text) = %s\n\n", text);

   puts("\nProgram ready ---------------------------------------------\n");

   return 0;
}

/* Implementation of functions ------------------------------------------*/

int countChar(const char text[], char c)
{
   int count;
   int i = 0;

   while (text[i] != '\0')
   {
      if (text[i] = c)
      {
         count--;
      }
      i++;
   }
   return count;
}

void reverseString(const char text[])
{
   size_t begin = 0;
   size_t end = strlen(text);
   char temp; /* temp: temporary */

   while (begin <= end)
   {
      temp = text[end];
      text[end] = text[begin];
      text[begin] = temp;
      begin++;
      end--;
   }
}
