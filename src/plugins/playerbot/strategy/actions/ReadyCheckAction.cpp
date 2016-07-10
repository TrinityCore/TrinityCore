#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ReadyCheckAction.h"
#include "../../PlayerbotAIConfig.h"
#include "../../../Entities/Pet/Pet.h"

using namespace ai;

bool ReadyCheckAction::Execute(Event event)
{
    WorldPacket &p = event.getPacket();
	ObjectGuid player;
	p.rpos(0);
    if (!p.empty())
        p >> player;

	if (player.GetRawValue() == bot->GetGUID())
        return false;

	return ReadyCheck();
}

bool ReadyCheckAction::ReadyCheck()
{

    WorldPacket* const packet = new WorldPacket(MSG_RAID_READY_CHECK);
    *packet << bot->GetGUID();
    *packet << uint8(1);
    bot->GetSession()->QueuePacket(packet);

    ai->ChangeStrategy("-ready check", BOT_STATE_NON_COMBAT);

    return true;
}

bool FinishReadyCheckAction::Execute(Event event)
{
    return ReadyCheck();
}
