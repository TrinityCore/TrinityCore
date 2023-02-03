#pragma once

#include "../Strategy.h"
#include "PaladinAiObjectContext.h"
#include "../generic/MeleeCombatStrategy.h"

namespace ai
{
    class GenericPaladinStrategy : public MeleeCombatStrategy
    {
    public:
        GenericPaladinStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "paladin"; }
    };

    class PaladinCureStrategy : public Strategy
    {
    public:
        PaladinCureStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "cure"; }
    };
}
