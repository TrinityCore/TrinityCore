#include "../generic/NonCombatStrategy.h"
#pragma once

namespace ai
{
    class GuardStrategy : public NonCombatStrategy
    {
    public:
        GuardStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "guard"; }
        NextAction** getDefaultActions();

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };



}
