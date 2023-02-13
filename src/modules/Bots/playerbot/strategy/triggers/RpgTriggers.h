#pragma once
#include "../Trigger.h"

namespace ai
{
    class NoRpgTargetTrigger : public Trigger
    {
    public:
        NoRpgTargetTrigger(PlayerbotAI* ai) : Trigger(ai, "no rpg target") {}

        virtual bool IsActive();
    };

    class FarFromRpgTargetTrigger : public Trigger
    {
    public:
        FarFromRpgTargetTrigger(PlayerbotAI* ai) : Trigger(ai, "far from rpg target") {}

        virtual bool IsActive();
    };
}
