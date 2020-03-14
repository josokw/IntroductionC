#ifndef DISPLAY_H
#define DISPLAY_H

//---------------------------------------------------------------------- DiSPlay

/// Initialises the Display (DSP) subsystem.
void DSPinitialise(void);

void DSPclear(void);
void DSPclearLine(int ln);
void DSPshowDisplay(void);
void DSPshow(const char *text, int row);
void DSPshowDelete(const char *text, int row);
void DSPdebugSystemInfo(const char *text);
void DSPsimulationSystemInfo(const char *text);
void DSPshowSystemError(const char *text);

#endif
