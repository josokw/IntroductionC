#include "prng.h"

#include <stdio.h>

static unsigned long int next = 1;

int randomLCG(void)
{
   next = next * 1103515245 + 12345;

   return (next / 65536) % (PRNG_MAX + 1);
}

void setSeed(unsigned long int seed)
{
   next = seed;
}
