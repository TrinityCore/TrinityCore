#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TankAoeStrategy.h"

using namespace ai;

void TankAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "tank aoe",
        NextAction::array(0, new NextAction("tank assist", 50.0f), NULL)));
}
