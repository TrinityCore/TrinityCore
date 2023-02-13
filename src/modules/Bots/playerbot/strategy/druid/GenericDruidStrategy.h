#pragma once

#include "../Strategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class AiObjectContext;

    class GenericDruidStrategy : public CombatStrategy
    {
    protected:
        GenericDruidStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

    class DruidCureStrategy : public Strategy
    {
    public:
        DruidCureStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "cure"; }
    };
}
