#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ResetAiAction.h"

using namespace ai;

bool ResetAiAction::Execute(Event event)
{
    ai->ResetStrategies();
    ai->TellMaster("AI was reset to defaults");
    return true;
}
