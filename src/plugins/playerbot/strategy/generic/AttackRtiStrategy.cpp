#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackRtiStrategy.h"

using namespace ai;


void AttackRtiStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no attackers",
        NextAction::array(0, new NextAction("attack rti target", 60.0f), NULL)));
}

