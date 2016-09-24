#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DpsAoeStrategy.h"

using namespace ai;

void DpsAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "timer",
        NextAction::array(0, new NextAction("dps assist", 50.0f), NULL)));
}
