#ifndef TUI_H
#define TUI_H

/// Shows questionText extended with '[Y/n]'.
/// User can enter Y by only pressing \<enter\>.
/// \return boolean value, equals true if Y has been chosen.
int TUIaskforYN(const char questionText[]);

/// Shows text, user can enter a char. If this char is not in chrs then the user
/// gets the same text extended with AGAIN.
/// \return char value.
char TUIsimulationSystemInputChar(const char text[], const char chrs[]);

/// Shows text, user can enter an integer value. If this value is not >= min
/// and <= max, the user gets the same text extended with AGAIN. 
/// \pre min < max. 
/// \return entered int value.
int TUIsimulationSystemInputInteger(const char text[], int min, int max);

#endif
