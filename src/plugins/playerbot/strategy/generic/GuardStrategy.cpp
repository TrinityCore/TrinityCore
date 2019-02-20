#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GuardStrategy.h"

using namespace ai;


NextAction** GuardStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("guard", 4.0f), NULL);
}

void GuardStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
}

