#include "events.h"

const char *eventText(event_e event)
{
   switch (event)
   {
      case E_NO:
         return "E_NO";
      case E_START:
         return "E_START";
      case E_CONFIG:
         return "E_CONFIG";
      case E_CONFIG_READY:
         return "E_CONFIG_READY";
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
      case E_CHANGE_DISPENSE:
         return "E_CHANGE_DISPENSE";
      case E_NO_CHANGE_DISPENSE:
         return "E_NO_CHANGE_DISPENSE";
   }
   return "<event not defined>";
}
