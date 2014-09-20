#pragma once

#include "GenericMageStrategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class FireMageStrategy : public GenericMageStrategy
    {
    public:
        FireMageStrategy(PlayerbotAI* ai) : GenericMageStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "fire"; }
        virtual NextAction** getDefaultActions();
    };

    class FireMageAoeStrategy : public CombatStrategy
    {
    public:
        FireMageAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "fire aoe"; }
    };
}
