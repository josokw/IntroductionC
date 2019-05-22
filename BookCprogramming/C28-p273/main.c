/* The program takes the book info file from the first example of
 * chapter 28; also reads each line from the file and outputs it to the
 * screen.
 *
 * Data file must be available in the directory containing the excutable.
*/

#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 100
#define BOOKS_FILENAME "BookInfo.txt"

int main()
{
   char fileLine[LINE_SIZE]; // Will hold each line of input.
   FILE *pFile;

   pFile = fopen(BOOKS_FILENAME, "r");
   if (pFile != NULL)
   {
      while (!feof(pFile))
      {
         // gets() is a banned function, not runtime safe! ==> use fgets()
         fgets(fileLine, LINE_SIZE, pFile);  // Checks for array boundary!
         if (!feof(pFile))
         {
            puts(fileLine);
         }
      }
   }
   else
   {
      printf("\n\tError opening %s file.\n\n", BOOKS_FILENAME);
   }
   fclose(pFile); // Always close your files!

   return(0);
}
