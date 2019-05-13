#include <stdio.h>

int main()
{
   puts("Type:            Size (bytes):\n");
   printf("char             %d\n", sizeof(char));
   printf("unsigned char    %d\n", sizeof(unsigned char));
   printf("short int        %d\n", sizeof(short int));
   printf("short            %d\n", sizeof(short));
   printf("int              %d\n", sizeof(int));
   printf("unsigned int     %d\n", sizeof(unsigned int));
   printf("float            %d\n", sizeof(float));
   printf("double           %d\n", sizeof(double));

   puts("\nPointer type:    Size (bytes):\n");
   printf("char*            %d\n", sizeof(char*));
   printf("unsigned char*   %d\n", sizeof(unsigned char*));
   printf("short int*       %d\n", sizeof(short int*));
   printf("short*           %d\n", sizeof(short*));
   printf("int*             %d\n", sizeof(int*));
   printf("unsigned int*    %d\n", sizeof(unsigned int*));
   printf("float*           %d\n", sizeof(float*));
   printf("double*          %d\n", sizeof(double*));
   printf("\n");

   return 0;
}
