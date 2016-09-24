#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "MoveRandomStrategy.h"

using namespace ai;

void MoveRandomStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "often",
        NextAction::array(0, new NextAction("move random", 1.5f), NULL)));
}

