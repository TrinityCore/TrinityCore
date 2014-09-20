#pragma once

#include "GenericPaladinStrategy.h"

namespace ai
{
    class DpsPaladinStrategy : public GenericPaladinStrategy
    {
    public:
        DpsPaladinStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps"; }
        virtual NextAction** getDefaultActions();
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };
}
