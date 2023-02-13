#include "botpch.h"
#include "../../playerbot.h"
#include "PositionValue.h"

using namespace ai;

PositionValue::PositionValue(PlayerbotAI* ai)
    : ManualSetValue<ai::PositionMap&>(ai, positions)
{
}
