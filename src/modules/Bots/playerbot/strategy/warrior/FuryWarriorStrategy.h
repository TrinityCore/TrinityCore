#pragma once

#include "GenericWarriorStrategy.h"

namespace ai
{
    class FuryWarriorStrategy : public GenericWarriorStrategy
    {
    public:
        FuryWarriorStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "fury dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class FuryWarriorAoeStrategy : public CombatStrategy
    {
    public:
        FuryWarriorAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "fury aoe"; }
    };
}
