#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NonCombatStrategy.h"

using namespace ai;

void NonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "timer",
        NextAction::array(0, new NextAction("check mount state", 1.0f), NULL)));
}


void LfgStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no possible targets",
        NextAction::array(0, new NextAction("lfg join", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "lfg proposal",
        NextAction::array(0, new NextAction("lfg accept", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "lfg proposal active",
        NextAction::array(0, new NextAction("lfg accept", 1.0f), NULL)));
}
