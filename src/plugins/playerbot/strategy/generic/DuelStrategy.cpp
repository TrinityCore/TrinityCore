#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DuelStrategy.h"

using namespace ai;

void DuelStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    PassTroughStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "duel requested",
        NextAction::array(0, new NextAction("accept duel", relevance), NULL)));

    triggers.push_back(new TriggerNode(
        "no attackers",
        NextAction::array(0, new NextAction("attack duel opponent", 70.0f), NULL)));
}



DuelStrategy::DuelStrategy(PlayerbotAI* ai) : PassTroughStrategy(ai)
{
}
