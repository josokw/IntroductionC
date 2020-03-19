// Bitwise operations

#include <stdio.h>

int main(void)
{
   unsigned char b1 = 0;
   unsigned char b2 = 0;
   unsigned char result = 0;

   b1 = 0b00000001;
   b2 = 0b10000001;

   // Bitwise AND
   result = b1 & b2;
   printf("result = b1 & b2  0x%02X = 0x%02X & 0x%02X \n", result, b1, b2);

   // Bitwise OR
   result = b1 | b2;
   printf("result = b1 | b2  0x%02X = 0x%02X | 0x%02X \n", result, b1, b2);

   // Bitwise XOR
   result = b1 ^ b2;
   printf("result = b1 ^ b2  0x%02X = 0x%02X ^ 0x%02X \n", result, b1, b2);

   // Bitwise NOT (flip bits)
   result = ~b1;
   printf("result = ~b1      0x%02X = ~0x%02X\n\n", result, b1);

   // Bit shifting to the left
   b1 = 0b00000001;
   result = b1 << 1;
   printf("result = b1 << 1  0x%02X = 0x%02X << 1\n", result, b1);
   result = b1 << 2;
   printf("result = b1 << 2  0x%02X = 0x%02X << 2\n", result, b1);
   result = b1 << 4;
   printf("result = b1 << 4  0x%02X = 0x%02X << 4\n\n", result, b1);

   // Bit shifting to the right
   b1 = 0b10000001;
   result = b1 >> 1;
   printf("result = b1 >> 1  0x%02X = 0x%02X >> 1\n", result, b1);
   result = b1 >> 2;
   printf("result = b1 >> 2  0x%02X = 0x%02X >> 2\n", result, b1);
   result = b1 >> 10;
   printf("result = b1 >> 10 0x%02X = 0x%02X >> 10\n", result, b1);

   return 0;
}
