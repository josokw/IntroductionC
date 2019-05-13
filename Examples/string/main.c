#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 20

void analyseString(const char text[]);

int main()
{
   char text1[STRING_SIZE] = "abc,\t123, ABC.";
   char text2[STRING_SIZE] = "TEXT";
   char* pText = NULL;

   printf("String is: %s\n", text1);
   analyseString(text1);
   puts("\n");

   text1[0] = toupper(text1[0]);
   text1[strlen(text1) - 1] = tolower(text1[strlen(text1) - 1]);
   analyseString(text1);

   /* copying of strings */
   printf("\n%s\n", text2);
   strcpy(text2, text1);
   printf("%s\n", text2);
   strcpy(text2 + 5, " qwerty");
   printf("%s\n", text2);

   /* concatenation of strings */
   strcat(text2, " extra");
   printf("%s\n", text2);

   strcpy(text2, "stop");
   printf("%s\n", text2);
   if (strcmp(text2, "stop") == 0)
   {
      printf("-- String equals 'stop'\n");
   }

   /* searching for substrings */
   pText = strstr(text1, "23");
   printf("Found substring (first appearance) '%s'\n\n", pText);

   return 0;
}

void analyseString(const char text[])
{
   int i = 0;

   for (i = 0; i < strlen(text); i++)
   {
      if (isdigit(text[i]))
      {
         printf("text[%2d] '%c' is a digit\n", i, text[i]);
      }
      else if (isalpha(text[i]))
      {
         printf("text[%2d] '%c' is alphabetic character\n", i, text[i]);
      }
      else if(isspace(text[i]))
      {
         /* white-space: space or tab */
         printf("text[%2d] '%c' is white-space\n", i, text[i]);
      }
      else if (ispunct(text[i]))
      {
         printf("text[%2d] '%c' is a punctuation character\n", i, text[i]);
      }
   }
}
