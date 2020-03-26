#ifndef PRNG_H
#define PRNG_H

#define PRNG_MAX 32767lu

int prng(void);
void setSeed(unsigned long int seed);

#endif
