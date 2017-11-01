#pragma once

#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericRogueNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericRogueNonCombatStrategy(PlayerbotAI* ai);
        virtual string getName() { return "nc"; }
    
	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers)
		{
			NonCombatStrategy::InitTriggers(triggers);

			triggers.push_back(new TriggerNode(
				"in battleground without flag",
				NextAction::array(0, new NextAction("stealth", 20.0f), NULL)));
		};
    };
}
