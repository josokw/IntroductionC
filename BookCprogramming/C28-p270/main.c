/* The program takes the book info program from chapter 27 and
 * writes the info to a file named bookinfo.txt.
 *
 * Software engineering guideline:
 *   avoid "magic numbers", use named constants (#define).
*/

#include "BookInfo.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BOOKS 3
#define BOOKS_FILENAME "BookInfo.txt"

int main()
{
   int ctr = 0;
   bookInfo_t books[NUMBER_OF_BOOKS]; // Array of structure variables
   FILE *pFile = NULL;

   // Get the information about each book from the user.
   for (ctr = 0; ctr < NUMBER_OF_BOOKS; ctr++)
   {
      printf("What is the name of the book #%d?\n", (ctr + 1));
      gets(books[ctr].title);
      puts("Who is the author? ");
      gets(books[ctr].author);
      puts("How much did the book cost? ");
      scanf(" $%f", &books[ctr].price);
      puts("How many pages in the book? ");
      scanf(" %d", &books[ctr].pages);
      getchar(); // Clears last newline for next loop.
   }

   // Remember when typing your filename path to double up the
   // backslashes or C will think you are putting in a conversion
   // character. "C:\\dir1\\subdir\\..."
   //
   // The data file can be found in the directory containing the executable.
   pFile = fopen(BOOKS_FILENAME, "w");

   // Test to ensure that the file opened.
   if (pFile == NULL)
   {
      printf("Error--file %s could not be opened.\n", BOOKS_FILENAME);
      exit(1);
   }

   // Print a header line and then loop through and print the info
   // to your file, but this time this printout will be in your
   // file and not on the screen.
   fprintf(pFile, "\n\nHere is the collection of books: \n");

   for (ctr = 0; ctr < NUMBER_OF_BOOKS; ctr++)
   {
      fprintf(pFile, "#%d: %s by %s", (ctr + 1), books[ctr].title,
              books[ctr].author);
      fprintf(pFile, "\nIt is %d pages and costs $%.2f",
              books[ctr].pages, books[ctr].price);
      fprintf(pFile, "\n\n");
   }
   fclose(pFile); // Always close your files.

   return(0);
}
