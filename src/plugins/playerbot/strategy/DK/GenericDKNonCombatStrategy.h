#pragma once

#include "GenericDKStrategy.h"
#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericDKNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericDKNonCombatStrategy(PlayerbotAI* ai);
        virtual string getName() { return "nc"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

    class DKBuffDpsStrategy : public Strategy
    {
    public:
        DKBuffDpsStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bdps"; }
    };
}
