#pragma once

#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericWarriorNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericWarriorNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "nc"; }
    public:
       virtual void InitTriggers(std::list<TriggerNode*> &triggers);
   };
}