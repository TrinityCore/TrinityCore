#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "FleeStrategy.h"

using namespace ai;

void FleeStrategy::InitTriggers(list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "panic",
        NextAction::array(0, new NextAction("flee", ACTION_EMERGENCY + 9), NULL)));

    triggers.push_back(new TriggerNode(
       "critical health",
       NextAction::array(0, new NextAction("flee", ACTION_MOVE + 9), NULL)));

   triggers.push_back(new TriggerNode(
       "low mana",
       NextAction::array(0,  new NextAction("flee", ACTION_MOVE + 9), NULL)));}

void FleeFromAddsStrategy::InitTriggers(list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "has nearest adds",
        NextAction::array(0, new NextAction("runaway", 50.0f), NULL)));
}
