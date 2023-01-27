#include "botpch.h"
#include "../../playerbot.h"
#include "EmoteStrategy.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;


void EmoteStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "random",
        NextAction::array(0, new NextAction("emote", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "seldom",
        NextAction::array(0, new NextAction("suggest what to do", 1.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "seldom",
        NextAction::array(0, new NextAction("suggest trade", 1.0f), NULL)));

if (sPlayerbotAIConfig.enableGreet)
    {
    triggers.push_back(new TriggerNode(
        "new player nearby",
        NextAction::array(0, new NextAction("greet", 1.0f), NULL)));

    }

    triggers.push_back(new TriggerNode(
        "often",
        NextAction::array(0, new NextAction("talk", 1.0f), NULL)));
}
