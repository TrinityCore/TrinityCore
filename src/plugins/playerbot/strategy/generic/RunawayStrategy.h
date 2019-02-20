#include "../generic/NonCombatStrategy.h"
#pragma once

namespace ai
{
    class RunawayStrategy : public NonCombatStrategy
       {
       public:
           RunawayStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
           virtual string getName() { return "runaway"; }
           virtual NextAction** getDefaultActions();
           virtual void InitTriggers(std::list<TriggerNode*> &triggers);
       };


}
