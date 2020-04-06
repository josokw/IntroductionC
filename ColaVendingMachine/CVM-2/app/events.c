#include "events.h"

const char *eventText(event_e event)
{
   switch (event)
   {
      case E_NO:
         return "E_NO";
      case E_START:
         return "E_START";
      case E_CONTINUE:
         return "E_CONTINUE";
      case E_20C:
         return "E_20C";
      case E_50C:
         return "E_50C";
      case E_NOT_ENOUGH:
         return "E_NOT_ENOUGH";
      case E_ENOUGH:
         return "E_ENOUGH";
   }
   return "<not defined>";
}