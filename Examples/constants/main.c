/* preprocessor constants, and C const variables
 * C const: is still a variable, but you can not assign a new value
 * after initialisation. You can not use it for the size of an array!
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200
#define MIN_SIZE (MAX_SIZE - 10)
#define MAX_TEMPERATURE_CELSIUS (10.55 / 2)
#define MESSAGE1 "hello"
#define MESSAGE2 "bye"

int main(void)
{
  int var = 10;
  const int MAX = var;
  const int MIN = (MAX < -100) ? MAX/3 : MAX;
  char text[MAX_SIZE] = "more data";

  /* char text2[MAX] = ""; ==> C compiler error */
  /* MAX = 200; ==> compiler error */

  printf("- %s\n", (MAX < 100) ? MESSAGE1 : MESSAGE2);
  printf("- %d\n", MIN);
  printf("- %s\n", text);
  printf("- %s\n", (strlen(text) > 5) ? text + 5 : text);

  return 0;
}
