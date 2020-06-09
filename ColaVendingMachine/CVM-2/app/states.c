#include "states.h"

const char *stateText(state_e state)
{
   switch (state)
   {
      case S_NO:
         return "S_NO";
      case S_START:
         return "S_START";
      case S_INITIALISED_SUBSYSTEMS:
         return "S_INITIALISED_SUBSYSTEMS";
      case S_CONFIGURE: 
         return "S_CONFIGURE";
      case S_WAIT_FOR_COINS:
         return "S_WAIT_FOR_COINS";
      case S_DETECTED_20C:
         return "S_DETECTED_20C";
      case S_DETECTED_50C:
         return "S_DETECTED_50C";
   }
   return "<state not defined>";
}