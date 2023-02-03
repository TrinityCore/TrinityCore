#include "botpch.h"
#include "../../playerbot.h"
#include "LootTriggers.h"

#include "../../ServerFacade.h"
using namespace ai;

bool LootAvailableTrigger::IsActive()
{
    return AI_VALUE(bool, "has available loot") && AI_VALUE(uint8, "bag space") < 80 &&
            (
                    sServerFacade.IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", "loot target"), INTERACTION_DISTANCE) ||
                    AI_VALUE(list<ObjectGuid>, "all targets").empty()
            ) &&
            !AI_VALUE2(bool, "combat", "self target") &&
            !AI_VALUE2(bool, "mounted", "self target");
}

bool FarFromCurrentLootTrigger::IsActive()
{
    return AI_VALUE2(float, "distance", "loot target") > INTERACTION_DISTANCE;
}

bool CanLootTrigger::IsActive()
{
    return AI_VALUE(bool, "can loot");
}
