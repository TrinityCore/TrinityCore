#pragma once

#include "HealPriestStrategy.h"

namespace ai
{
    class HolyPriestStrategy : public HealPriestStrategy
    {
    public:
        HolyPriestStrategy(PlayerbotAI* ai);

    public:
        virtual NextAction** getDefaultActions();
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "holy"; }
        virtual int GetType() { return STRATEGY_TYPE_DPS|STRATEGY_TYPE_RANGED; }
    };
}
