#pragma once

#include "../Strategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class GenericDKStrategy : public CombatStrategy
    {
    public:
        GenericDKStrategy(PlayerbotAI* ai);
        virtual string getName() { return "DK"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

}
