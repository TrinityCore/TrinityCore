#include "botpch.h"
#include "../../playerbot.h"
#include "WarriorMultipliers.h"
#include "GenericWarriorNonCombatStrategy.h"

using namespace ai;

void GenericWarriorNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
   NonCombatStrategy::InitTriggers(triggers);

   triggers.push_back(new TriggerNode(
      "often",
      NextAction::array(0, new NextAction("apply stone", 1.0f), NULL)));


}


