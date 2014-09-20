#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "UsePotionsStrategy.h"

using namespace ai;

void UsePotionsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    Strategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("healing potion", ACTION_MEDIUM_HEAL), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0,  new NextAction("mana potion", ACTION_EMERGENCY), NULL)));
}
