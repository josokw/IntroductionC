/* gets() is function that misbehaves badly. You should not use it.
 * It has no internal checks, there is no bounds checking for the
 * limited size of the target char array.
 * Use: fgets().
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 10

int main(void)
{
   size_t index = 0;
   char line[MAXLINE] = "";

   /* Do not use gets(), is a banned function! */
   puts("\nWill replace lowercase by uppercase characters.\n"
        "No buffer overflow will occur!\n");

   printf("Enter text line(s), may contain spaces and tabs:\n");
   /* NULL is the NULL pointer, stdin: keyboard */
   while (fgets(line, MAXLINE, stdin) != NULL
          && line[0] != '\n')
   {
      for (index = 0; index < strlen(line); index++)
      {
         line[index] = toupper(line[index]);
      }
      printf("Result: ");
      fputs(line, stdout);
      fflush(stdin);
   }

   return 0;
}
