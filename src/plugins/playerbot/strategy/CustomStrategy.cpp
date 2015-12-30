#include "../../pchdef.h"
#include "../playerbot.h"
#include "CustomStrategy.h"

using namespace ai;

void CustomStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
}

CustomStrategy::CustomStrategy(PlayerbotAI* ai) : Strategy(ai), Qualified()
{
}
