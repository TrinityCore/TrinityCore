#pragma once

#include "GenericMageStrategy.h"
#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericMageNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericMageNonCombatStrategy(PlayerbotAI* ai);
        virtual string getName() { return "nc"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

    class MageBuffManaStrategy : public Strategy
    {
    public:
        MageBuffManaStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bmana"; }
    };

    class MageBuffDpsStrategy : public Strategy
    {
    public:
        MageBuffDpsStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bdps"; }
    };
}
