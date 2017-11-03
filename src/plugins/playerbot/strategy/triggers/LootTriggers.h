#pragma once
#include "../Trigger.h"
#include "../values/LastMovementValue.h"

namespace ai
{
    class LootAvailableTrigger : public Trigger
    {
    public:
        LootAvailableTrigger(PlayerbotAI* ai) : Trigger(ai, "loot available") {}

        virtual bool IsActive();
    };

    class FarFromCurrentLootTrigger : public Trigger
    {
    public:
        FarFromCurrentLootTrigger(PlayerbotAI* ai) : Trigger(ai, "far from current loot") {}

        virtual bool IsActive();
    };

    class CanLootTrigger : public Trigger
    {
    public:
        CanLootTrigger(PlayerbotAI* ai) : Trigger(ai, "can loot") {}

        virtual bool IsActive();
    };
}
