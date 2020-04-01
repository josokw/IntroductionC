#ifndef PRNG_H
#define PRNG_H

#define PRNG_MAX 32767lu

/// Generates the next pseudo random value.
/// Implementation: Linear Congruential Generator (Lehmer).
/// \return next pseudo random value in the range [0, PRNG_MAX].
int randomLCG(void);

/// Sets the seed value for the random generator.
/// \post pseudo random value sequence is determined.
void setSeed(unsigned long int seed);

#endif
