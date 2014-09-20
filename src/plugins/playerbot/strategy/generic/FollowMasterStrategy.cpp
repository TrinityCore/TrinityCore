#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "FollowMasterStrategy.h"

using namespace ai;

NextAction** FollowMasterStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("follow", 1.0f), NULL);
}

void FollowMasterStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "out of react range",
        NextAction::array(0, new NextAction("tell out of react range", 10.0f), NULL)));
}
