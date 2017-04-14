#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DpsAssistStrategy.h"

using namespace ai;

void DpsAssistStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "not dps target active",
        NextAction::array(0, new NextAction("dps assist", 60.0f), NULL)));
}



