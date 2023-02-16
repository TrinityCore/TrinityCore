#include "botpch.h"
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
       "often",
       NextAction::array(0, new NextAction("apply poison", 1.0f), NULL)));


}
