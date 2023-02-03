#include "botpch.h"
#include "../../playerbot.h"
#include "LootNonCombatStrategy.h"

using namespace ai;

void LootNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "loot available",
        NextAction::array(0, new NextAction("loot", 6.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "far from loot target",
        NextAction::array(0, new NextAction("move to loot", 7.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "can loot",
        NextAction::array(0, new NextAction("open loot", 8.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "often",
        NextAction::array(0, new NextAction("add all loot", 1.0f), NULL)));
}

void GatherStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "timer",
        NextAction::array(0, new NextAction("add gathering loot", 2.0f), NULL)));
}

void RevealStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "often",
        NextAction::array(0, new NextAction("reveal gathering item", 50.0f), NULL)));
}


