/* The program gets the bookInfo structure by including BookInfo.h
 * and asks the user to fill in three structures and then prints them.
 *
 * First include the header file with the structure definition.
*/

#include "BookInfo.h"
#include <stdio.h>

#define NUMBER_OF_BOOKS 3

int main()
{
   int ctr = 0;
   bookInfo_t books[NUMBER_OF_BOOKS]; // Array of structure variables.

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

   // Print a header line and then loop through and print the info.
   printf("\n\nHere is the collection of books: \n");
   for (ctr = 0; ctr < NUMBER_OF_BOOKS; ctr++)
   {
      printf("#%d: %s by %s", (ctr + 1), books[ctr].title,
             books[ctr].author);
      printf("\nIt is %d pages and costs $%.2f", books[ctr].pages,
             books[ctr].price);
      printf("\n\n");
   }

   return(0);
}
