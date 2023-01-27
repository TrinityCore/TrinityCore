#include "botpch.h"
#include "../../playerbot.h"
#include "CombatStrategy.h"

using namespace ai;

void CombatStrategy::InitTriggers(list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "invalid target",
        NextAction::array(0, new NextAction("drop target", 59), NULL)));
}
