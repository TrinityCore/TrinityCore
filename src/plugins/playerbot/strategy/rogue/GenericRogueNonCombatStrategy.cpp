#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RogueTriggers.h"
#include "RogueMultipliers.h"
#include "GenericRogueNonCombatStrategy.h"
#include "RogueActions.h"

using namespace ai;

void GenericRogueNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
	{
    	NonCombatStrategy::InitTriggers(triggers);
    		triggers.push_back(new TriggerNode(
		"in battleground without flag",
			NextAction::array(0, new NextAction("mount", 1.0f), NULL)));    
	}
