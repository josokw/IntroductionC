#include <stdio.h>

#define N_DATA 10

int main()
{
   int i = 0;
   double data[N_DATA] = {1.1, 2.2, 3.3};

   FILE* dataFile = fopen("storeData.txt", "w");
   if (dataFile != NULL)
   {
      for(i = 0; i < N_DATA; i++)
      {
         fprintf(dataFile, "%lf\n", data[i]);
      }
   }
   fclose(dataFile);

   dataFile = fopen("storeData.txt", "r");
   if (dataFile != NULL)
   {
      for(i = 0; i < N_DATA; i++)
      {
         fscanf(dataFile, "%lf\n", &data[i]);
         printf(" data[%d] = %lf\n", i, data[i]);
      }
   }
   fclose(dataFile);

   return 0;
}
