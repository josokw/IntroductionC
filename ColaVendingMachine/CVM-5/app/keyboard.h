#ifndef KEYBOARD_H
#define KEYBOARD_H

//--------------------------------------------------------------------- KeYBoard

void KYBinitialise(void);
/// Empty input buffer
void KYBclear(void);
char KYBgetchar(void);
int KYBgetint(int ifWrongValue);

#endif
