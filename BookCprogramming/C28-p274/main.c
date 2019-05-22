/* The program opens the existing book info file from the first
 * example of chapter 28, and adds a line to the end.
*/

#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 100
#define BOOKS_FILENAME "BookInfo.txt"

int main()
{
   FILE * pFile;

   // Open file in append mode.
   pFile = fopen(BOOKS_FILENAME, "a");
   if (pFile == NULL)
   {
      printf("\tError opening the %s file! Sorry!\n\n", BOOKS_FILENAME);
      exit(1);
   }

   // Adds the line at the end
   fprintf(pFile, "\nMore books to come!\n");
   fclose(pFile); // Always close your files!

   return(0);
}
