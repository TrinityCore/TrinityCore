#include "ReturnStrategy.h"

#include "botpch.h"
#include "../../playerbot.h"

using namespace ai;

void ReturnStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "return",
        NextAction::array(0, new NextAction("set return position", 1.5f), new NextAction("return", 1.0f), NULL)));
}

