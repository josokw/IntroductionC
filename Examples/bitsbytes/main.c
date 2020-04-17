/* A char is 1 byte, a group of 8 bits */

#include <stdio.h>

int main(void)
{
   unsigned char byte = 0;
   size_t sizeByte = sizeof(byte);

   printf("Size of char type variables = %ld byte(s)\n\n", sizeByte);
   printf("             binary    hexadecimal\n");

   for (byte = 0; byte < 32; byte++)
   {
      // 0b prefix in not standard C11, but available in GNU compilers
      unsigned char bitMask = 0b10000000;

      printf(" byte %2u   ", byte);

      for (size_t b = 0; b < (sizeByte * 8); b++)
      {
         if (b != 0 && b % 4 == 0)
         {
            printf(" ");
         }
         if (byte & bitMask)
         {
            printf("1");
         }
         else
         {
            printf("0");
         }
         // bit shift to the right operator >>
         bitMask = bitMask >> 1;
      }
      printf("       %02X\n", byte);
   }

   return 0;
}
