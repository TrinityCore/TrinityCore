#include "botpch.h"
#include "../../playerbot.h"
#include "RpgStrategy.h"

using namespace ai;

RpgStrategy::RpgStrategy(PlayerbotAI* ai) : Strategy(ai)
{
}

NextAction** RpgStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("rpg", 1.0f), NULL);
}

void RpgStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no rpg target",
        NextAction::array(0, new NextAction("choose rpg target", 5.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "far from rpg target",
        NextAction::array(0, new NextAction("move to rpg target", 5.0f), NULL)));
}
