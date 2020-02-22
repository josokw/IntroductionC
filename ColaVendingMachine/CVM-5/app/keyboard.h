#ifndef KEYBOARD_H
#define KEYBOARD_H

//--------------------------------------------------------------------- KeYBoard

/// Initialises the keyboard (KYB) subsystem.
void KYBinitialise(void);

/// Empty input buffer (stdin).
void KYBclear(void);

/// Read one character, remaining buffered characters will be deleted.
char KYBgetchar(void);

/// Read one integer value, remaining buffered characters will be deleted.
/// \return the read in integer value, or if input is not an integer
/// ifWrongValue will be returned.
int KYBgetint(int ifWrongValue);

/// Read one double value, remaining buffered characters will be deleted.
/// \return the read in double value, or if input is not a double ifWrongValue
/// will be returned.
double KYBgetdouble(double ifWrongValue);

/// Show questionText extended with '[Y/n]'. User can enter Y by only pressing
/// \<enter\>.
/// \return boolean value, equals true if Y has been chosen.
int KYBaskforYN(const char questionText[]);

#endif
