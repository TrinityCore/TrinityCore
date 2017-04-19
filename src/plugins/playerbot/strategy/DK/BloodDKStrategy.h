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
        virtual string getName() { return "blood"; }
        virtual NextAction** getDefaultActions();
    };
	class BloodDKAoeStrategy : public CombatStrategy
	{
	public:
		BloodDKAoeStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "blood aoe"; }
	};
}
