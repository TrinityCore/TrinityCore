#pragma once

#include "GenericDKStrategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class FrostDKStrategy : public GenericDKStrategy
    {
    public:
        FrostDKStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "frost"; }
        virtual NextAction** getDefaultActions();
		virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
    };

    class FrostDKAoeStrategy : public CombatStrategy
    {
    public:
        FrostDKAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "frost aoe"; }
    };
}
