#pragma once

#include "GenericDKStrategy.h"

namespace ai
{
    class BloodDKStrategy : public GenericDKStrategy
    {
    public:
        BloodDKStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "tank"; }
        virtual NextAction** getDefaultActions();
		virtual int GetType() { return STRATEGY_TYPE_TANK | STRATEGY_TYPE_MELEE; }
	};

	class BloodDKAoeStrategy : public CombatStrategy
	{
	public:
		BloodDKAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "tank aoe"; }
	};
}
