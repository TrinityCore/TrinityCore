#pragma once

#include "RangedCombatStrategy.h"

namespace ai
{
    class PullStrategy : public RangedCombatStrategy
    {
    public:
        PullStrategy(PlayerbotAI* ai, string action) : RangedCombatStrategy(ai) 
        {
            this->action = action;
        }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual void InitMultipliers(std::list<Multiplier*> &multipliers);
        virtual string getName() { return "pull"; }
        virtual NextAction** getDefaultActions();

    private:
        string action;
    };
}
