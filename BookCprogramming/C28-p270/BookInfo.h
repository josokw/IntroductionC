#ifndef BOOKINFO_H
#define BOOKINFO_H

// This header file defines a structure for information about a book.

typedef struct {
   char title[40];
   char author[25];
   float price;
   int pages;
} bookInfo_t;

#endif // BOOKINFO_H
