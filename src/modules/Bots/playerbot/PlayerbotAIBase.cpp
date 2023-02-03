#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"

using namespace ai;
using namespace std;

PlayerbotAIBase::PlayerbotAIBase() : nextAICheckDelay(0)
{
}

void PlayerbotAIBase::UpdateAI(uint32 elapsed)
{
    if (nextAICheckDelay > elapsed)
        nextAICheckDelay -= elapsed;
    else
        nextAICheckDelay = 0;

    if (!CanUpdateAI())
        return;

    UpdateAIInternal(elapsed);
    YieldThread();
}

void PlayerbotAIBase::SetNextCheckDelay(const uint32 delay)
{
    if (nextAICheckDelay < delay)
        sLog.outDebug("Setting lesser delay %d -> %d", nextAICheckDelay, delay);

    nextAICheckDelay = delay;

    if (nextAICheckDelay > sPlayerbotAIConfig.globalCoolDown)
        sLog.outDebug( "set next check delay: %d", nextAICheckDelay);
}

void PlayerbotAIBase::IncreaseNextCheckDelay(uint32 delay)
{
    nextAICheckDelay += delay;

    if (nextAICheckDelay > sPlayerbotAIConfig.globalCoolDown)
        sLog.outDebug( "increase next check delay: %d", nextAICheckDelay);
}

bool PlayerbotAIBase::CanUpdateAI()
{
    return nextAICheckDelay < 100;
}

void PlayerbotAIBase::YieldThread()
{
    if (nextAICheckDelay < sPlayerbotAIConfig.reactDelay)
        nextAICheckDelay = sPlayerbotAIConfig.reactDelay;
}

bool PlayerbotAIBase::IsActive()
{
    return (int)nextAICheckDelay < (int)sPlayerbotAIConfig.maxWaitForMove;
}
