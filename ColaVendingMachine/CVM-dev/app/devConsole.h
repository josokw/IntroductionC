#ifndef DEVCONSOLE_H
#define DEVCONSOLE_H

/// Shows debug related message, below the display.
/// Has printf() interface.
void DCSdebugSystemInfo(const char fmt[], ...);

/// Shows simulation related text, below the display.
/// Has printf() interface.
void DCSsimulationSystemInfo(const char fmt[], ...);

/// Shows system error related text, below the display.
/// Has printf() interface.
/// If a system error is detected, most of the time the system needs to
/// shutdown (if still possible) or will run at some reduced level of
/// performance (graceful degradation).
void DCSshowSystemError(const char fmt[], ...);

#endif
