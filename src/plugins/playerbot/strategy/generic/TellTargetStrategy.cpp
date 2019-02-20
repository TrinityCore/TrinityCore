#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TellTargetStrategy.h"

using namespace ai;


void TellTargetStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "target changed",
        NextAction::array(0, new NextAction("tell target", 51.0f), NULL)));
}
