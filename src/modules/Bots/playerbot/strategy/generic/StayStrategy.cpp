#include "botpch.h"
#include "../../playerbot.h"
#include "StayStrategy.h"

using namespace ai;

NextAction** StayStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("stay", 1.0f), NULL);
}

void SitStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "sit",
        NextAction::array(0, new NextAction("sit", 1.5f), NULL)));
}
