#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SayStrategy.h"

using namespace ai;


void SayStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("say::critical health", 99.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("say::low health", 99.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("say::low mana", 99.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "tank aoe",
        NextAction::array(0, new NextAction("say::taunt", 99.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("say::aoe", 99.0f), NULL)));
}
