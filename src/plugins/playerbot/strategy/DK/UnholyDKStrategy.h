#pragma once

#include "GenericDKStrategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class UnholyDKStrategy : public GenericDKStrategy
    {
    public:
        UnholyDKStrategy(PlayerbotAI* ai) : GenericDKStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "unholy"; }
		virtual NextAction** getDefaultActions();
		virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class UnholyDKAoeStrategy : public CombatStrategy
    {
    public:
        UnholyDKAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "unholy aoe"; }
    };
}
