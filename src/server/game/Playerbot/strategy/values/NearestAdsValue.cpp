#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestAdsValue.h"

using namespace ai;

bool NearestAdsValue::AcceptUnit(Unit* unit)
{
    Unit* target = AI_VALUE(Unit*, "current target");
    return unit != target;
}
