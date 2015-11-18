#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackWeakStrategy.h"

using namespace ai;

void AttackWeakStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "not least hp target active",
        NextAction::array(0, new NextAction("attack least hp target", 60.0f), NULL)));
}

