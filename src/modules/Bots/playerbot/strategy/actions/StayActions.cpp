#include "botpch.h"
#include "../../playerbot.h"
#include "StayActions.h"

#include "../../ServerFacade.h"
#include "../values/LastMovementValue.h"

using namespace ai;

bool StayActionBase::Stay()
{
    AI_VALUE(LastMovement&, "last movement").Set(NULL);

    if (!urand(0, 5000)) ai->PlaySound(TEXTEMOTE_YAWN);

    MotionMaster &mm = *bot->GetMotionMaster();
    if (mm.GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE || bot->IsFlying())
        return false;

    uint32 sitDelay = sPlayerbotAIConfig.sitDelay / 1000;
    time_t stayTime = AI_VALUE(time_t, "stay time");
    time_t now = time(0);
    if (!stayTime)
    {
        stayTime = now - urand(0, sitDelay / 2);
        context->GetValue<time_t>("stay time")->Set(stayTime);
    }

    if (!sServerFacade.isMoving(bot))
        return false;

    mm.Clear();
    bot->InterruptMoving();
	bot->clearUnitState(UNIT_STAT_CHASE);
	bot->clearUnitState(UNIT_STAT_FOLLOW);

    return true;
}

bool StayAction::Execute(Event event)
{
    return Stay();
}

bool StayAction::isUseful()
{
    return !AI_VALUE2(bool, "moving", "self target");
}

bool SitAction::Execute(Event event)
{
    if (sServerFacade.isMoving(bot))
        return false;

    bot->SetStandState(UNIT_STAND_STATE_SIT);
    return true;
}

bool SitAction::isUseful()
{
    return !AI_VALUE2(bool, "moving", "self target");
}
