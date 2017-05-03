#include "../generic/NonCombatStrategy.h"
#pragma once

namespace ai
{
    class AttackWeakStrategy : public NonCombatStrategy
    {
    public:
        AttackWeakStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "attack weak"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

}
