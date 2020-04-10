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

/*!
 * Counts the number of c characters in the input string text.
 */
int countChar(const char text[], char c);

/*!
 * Reverses the contents of the input string text.
 * Example: "123" becomes "321"
 */
void reverseString(char text[]);

int main(void)
{
   char text1[MAXCHARS] = "abcdef";
   char text2[MAXCHARS] = "123";

   puts(
      "Program bugs2 started with testing "
      "-------------------------------\n");

   printf("countChar(\"abbccc\", 'a') = %d\n", countChar("abbccc", 'a'));
   printf("countChar(\"abbccc\", 'x') = %d\n\n", countChar("abbccc", 'x'));

   printf("String text1 = %s\n", text1);
   reverseString(text1);
   printf("reverseString(text1) = %s\n\n", text1);

   printf("String text2 = %s\n", text2);
   reverseString(text2);
   printf("reverseString(text2) = %s\n\n", text2);

   puts(
      "\nProgram ready "
      "--------------------------------------------------\n");

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
   size_t begin = 1;
   size_t end = strlen(text);

   while (begin <= end)
   {
      char temp = text[end]; /* temp: temporary */

      text[end] = text[begin];
      text[begin] = temp;
      begin++;
      end--;
   }
}
