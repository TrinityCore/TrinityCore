#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueTriggers.h"
#include "RogueMultipliers.h"
#include "GenericRogueNonCombatStrategy.h"
#include "RogueActions.h"

using namespace ai;

class GenericRogueNonCombatStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	GenericRogueNonCombatStrategyActionNodeFactory()
	{
		
		creators["stealth"] = &stealth;
	}
private:
	static ActionNode* stealth(PlayerbotAI* ai)
	{
		return new ActionNode("stealth",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	
};


GenericRogueNonCombatStrategy::GenericRogueNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai)
{
	actionNodeFactories.Add(new GenericRogueNonCombatStrategyActionNodeFactory());
}
/*
void GenericRogueNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);
        
}
*/