#include "AppInfo.h"
#include "calculator.h"
#include <stdio.h>

int main()
{
   int result = 0;

   printf("----- Application: " APPNAME_VERSION " started\n\n");

   result = add(2, 4);
   printf("result = %d\n", result);

   result = add(multiply(2, 2), multiply(3, 3));
   printf("result = %d\n", result);

   printf("sqr(10) = %d\n", sqr(10));

   return 0;
}
