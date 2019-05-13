/* scanf() reads until space, tab or newline, stdin buffered input!!          */

#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10

int main()
{
   int index = 0;
   double epsilon = 0.0;
   char c = '\0';
   char string[MAXLENGTH] = "";
   int integer1 = 0;
   int integer2 = 0;
   int nCorrect = 0;  /* prefix character n 'number of' */

   printf("Enter one integer: ");
   scanf("%d", &index);
   printf("Enter one floating point double: ");
   scanf("%lf", &epsilon);
   /* Newline remains in input buffer stdin after <ENTER> */
   printf("Enter one character: ");
   scanf(" %c", &c);
   /*     ^ extra space! scanf() will ignore newline char in input buffer */

   /* Empty input buffer by reading all remaining entered characters */
   while ((c = getchar()) != EOF && c != '\n')
   { }

   /* scanf() no run time checking array upper bound, use fscanf() */
   printf("Enter string (max. %d characters): ", MAXLENGTH - 1);
   scanf("%s", string);     /* no address-operator & for arrays!! */
   printf("String: %s\n", string);

   /* Enter a string reading spaces and tabs */
   printf("Enter string using spaces and tabs (max. %d characters): ",
          MAXLENGTH - 1);
   scanf(" %[^\n]%*c", string);
   printf("String: %s\n", string);

   printf("\n%d %lf %c %s\n\n", index, epsilon, c, string);
   printf("Length of the string in 'string'' is: %d\n\n", strlen(string));

   printf("Enter two integers, value between 1 and 100: ");
   /* scanf() reads until wrong decimal character: 2 33da ==> 2 33 */
   nCorrect = scanf("%2d%2d", &integer1, &integer2);
   if (nCorrect == 2)
   {
      printf("Result: %2d + %2d = %3d\n",
             integer1, integer2, integer1 + integer2);
   }
   else
   {
      printf("Input format 2 integers not correct!\n");
      /* empty input buffer by reading all entered characters */
      while ((c = getchar()) != EOF && c != '\n')
      { }
   }

   printf("Enter + or - sign: ");
   nCorrect = scanf(" %[+-]", &c);
   if (nCorrect == 1)
   {
      printf("Result is ok: %c\n", c);
   }
   else
   {
      printf("Input format not correct, expected + or - sign!\n");
   }

   return 0;
}
