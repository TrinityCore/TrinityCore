#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PositionValue.h"

using namespace ai;

PositionValue::PositionValue(PlayerbotAI* ai)
    : ManualSetValue<ai::Position&>(ai, position), Qualified()
{
}
