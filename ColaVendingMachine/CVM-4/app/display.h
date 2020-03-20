#ifndef DISPLAY_H
#define DISPLAY_H

//---------------------------------------------------------------------- DiSPlay

/// Initialises the Display (DSP) subsystem and draws an empty display
/// (no text).
void DSPinitialise(void);

/// Clears full display (terminal) by executing a terminal command.
void DSPclear(void);

/// Clears a full line in the display.
/// \param row display row index [1, DSP_HEIGHT-2]
/// \pre   0 < row < DSP_HEIGHT-2
void DSPclearLine(int row);

/// Shows full display contents.
void DSPshowDisplay(void);

/// Updates one line in the display.
/// \param text update text
/// \param row display row index
void DSPshow(const char text[], int row);

/// Add new text to display in row, deletes all subsequent lines.
void DSPshowDelete(const char text[], int row);

/// Shows debug related message, below the display.
void DSPdebugSystemInfo(const char text[]);

/// Shows simulation related text, below the display.
void DSPsimulationSystemInfo(const char text[]);

/// Shows error related text, below the display.
void DSPshowSystemError(const char text[]);

#endif
