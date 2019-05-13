#include <stdio.h>

int main(void)
{
   int i1 = 0;
   int i2 = 1;
   int data[3] = {10, 20, 30};
   double d = 1.123;
   int *pInt = data;

   printf("\n"
          "\tint i1 = 0;\n"
          "\tint i2 = 1;\n"
          "\tint data[3] = {10, 20, 30};\n"
          "\tdouble d = 1.123;\n"
          "\tint *pInt = data;\n\n");

   printf("   Address   Var  Size       Value\n\n");
   printf("0x%p    i1   %3d %11d\n",
          &i1, sizeof(i1), i1);
   printf("0x%p    i2   %3d %11d\n",
          &i2, sizeof(i2), i2);
   printf("0x%p  data   %3d %3d,%3d,%3d\n",
          data, sizeof(data), data[0], data[1], data[2]);
   printf("0x%p     d   %3d %11.3lf\n",
          &d, sizeof(d), d);
   printf("0x%p  pInt   %3d  0x%p\n",
          &pInt, sizeof(pInt), pInt);
   printf("           *pInt   %3d %11d\n",
          sizeof(*pInt), *pInt);

   pInt++;

   printf("\npInt++;\n\n");
   printf("0x%p  pInt   %3d  0x%p\n",
          &pInt, sizeof(pInt), pInt);
   printf("           *pInt   %3d %11d\n",
          sizeof(*pInt), *pInt);
   printf("       *(pInt+1)   %3d %11d\n",
          sizeof(*(pInt+1)), *(pInt+1));
   printf("         pInt[1]   %3d %11d\n",
          sizeof(pInt[1]), pInt[1]);

   printf("\n");

   return 0;
}


