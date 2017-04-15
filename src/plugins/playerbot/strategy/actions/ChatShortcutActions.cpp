#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ChatShortcutActions.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

bool FollowChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("+follow,-passive", BOT_STATE_NON_COMBAT);
    ai->ChangeStrategy("-follow,-passive", BOT_STATE_COMBAT);
    if (bot->GetMapId() != master->GetMapId() || bot->GetDistance(master) > sPlayerbotAIConfig.sightDistance)
    {
        ai->TellMaster("I will not follow you - too far away");
        return true;
    }
	bot->Say("Lead the way!", LANG_UNIVERSAL);
    return true;
}

bool StayChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("+stay,-passive", BOT_STATE_NON_COMBAT);
    ai->ChangeStrategy("-follow,-passive", BOT_STATE_COMBAT);
	bot->Say("Alrigh, I stay here.", LANG_UNIVERSAL);
    return true;
}

bool FleeChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("+follow,+passive", BOT_STATE_NON_COMBAT);
    ai->ChangeStrategy("+follow,+passive", BOT_STATE_COMBAT);
    if (bot->GetMapId() != master->GetMapId() || bot->GetDistance(master) > sPlayerbotAIConfig.sightDistance)
    {
        ai->TellMaster("I will not flee with you - too far away");
        return true;
    }
	bot->Say("Run for your life!", LANG_UNIVERSAL);
    return true;
}

bool GoawayChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("+runaway", BOT_STATE_NON_COMBAT);
    ai->ChangeStrategy("+runaway", BOT_STATE_COMBAT);
	bot->Say("I'm running away!", LANG_UNIVERSAL);
    return true;
}

bool GrindChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("+grind,-passive", BOT_STATE_NON_COMBAT);
	bot->Say("Kill them all!", LANG_UNIVERSAL);
    return true;
}

bool TankAttackChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    if (!ai->IsTank(bot))
        return false;

    ai->Reset();
    ai->ChangeStrategy("-passive", BOT_STATE_NON_COMBAT);
    ai->ChangeStrategy("-passive", BOT_STATE_COMBAT);
	bot->Say("Die monster!", LANG_UNIVERSAL);
    return true;
}

bool MaxDpsChatShortcutAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    ai->Reset();
    ai->ChangeStrategy("-threat,-conserve mana,-cast time,+dps debuff", BOT_STATE_COMBAT);
    ai->TellMaster("Max DPS");
    return true;
}
