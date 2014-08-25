#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LfgActions.h"
#include "../../AiFactory.h"
#include "../../PlayerbotAIConfig.h"
#include "../ItemVisitors.h"
#include "../../RandomPlayerbotMgr.h"
#include "../../../DungeonFinding/LFGMgr.h"
#include "../../../DungeonFinding/LFG.h"

using namespace ai;
using namespace lfg;

bool LfgJoinAction::Execute(Event event)
{
    if (!sPlayerbotAIConfig.randomBotJoinLfg)
        return false;

    if (bot->isDead())
        return false;

    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return false;

    if (sLFGMgr->GetState(bot->GetGUID()) != LFG_STATE_NONE)
        return false;

    if (bot->IsBeingTeleported())
        return false;

    Map* map = bot->GetMap();
    if (map && map->Instanceable())
        return false;

    return JoinProposal();
}

uint8 LfgJoinAction::GetRoles()
{
    int spec = AiFactory::GetPlayerSpecTab(bot);
    switch (bot->getClass())
    {
    case CLASS_DRUID:
        if (spec == 2)
            return PLAYER_ROLE_HEALER;
        else if (spec == 1 && bot->getLevel() >= 40)
            return PLAYER_ROLE_TANK;
        else
            return PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_PALADIN:
        if (spec == 1)
            return PLAYER_ROLE_TANK;
        else if (spec == 0)
            return PLAYER_ROLE_HEALER;
        else
            return PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_PRIEST:
        if (spec != 2)
            return PLAYER_ROLE_HEALER;
        else
            return PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_SHAMAN:
        if (spec == 2)
            return PLAYER_ROLE_HEALER;
        else
            return PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_WARRIOR:
        if (spec == 2)
            return PLAYER_ROLE_TANK;
        else
            return PLAYER_ROLE_DAMAGE;
        break;
    default:
        return PLAYER_ROLE_DAMAGE;
        break;
    }

    return PLAYER_ROLE_DAMAGE;
}

bool LfgJoinAction::SetRoles()
{
    sLFGMgr->SetRoles(bot->GetGUID(), GetRoles());
	return true;
}

bool LfgJoinAction::JoinProposal()
{
    ItemCountByQuality visitor;
    IterateItems(&visitor, ITERATE_ITEMS_IN_EQUIP);
	bool heroic = urand(0, 100) < 50 && (visitor.count[ITEM_QUALITY_EPIC] >= 3 || visitor.count[ITEM_QUALITY_RARE] >= 10) && bot->getLevel() >= 70;
    bool random = urand(0, 100) < 25;
    bool raid = urand(0, 100) < 50 && visitor.count[ITEM_QUALITY_EPIC] >= 5 && (bot->getLevel() == 60 || bot->getLevel() == 70 || bot->getLevel() == 80);

    LfgDungeonSet list;
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon || (dungeon->type != LFG_TYPE_RANDOM && dungeon->type != LFG_TYPE_DUNGEON && dungeon->type != LFG_TYPE_HEROIC &&
                dungeon->type != LFG_TYPE_RAID))
            continue;

        int botLevel = (int)bot->getLevel();
        if (dungeon->minlevel && botLevel < (int)dungeon->minlevel)
            continue;

        if (dungeon->minlevel && botLevel > (int)dungeon->minlevel + 10)
            continue;

        if (dungeon->maxlevel && botLevel > (int)dungeon->maxlevel)
            continue;

        if (heroic && !dungeon->difficulty)
            continue;

        if (raid && dungeon->type != LFG_TYPE_RAID)
            continue;

        list.insert(dungeon->ID);
    }

    if (random)
	{
		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_RANDOM", bot->GetName());
	}
    else if (heroic)
	{
		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_HEROIC_DUNGEON", bot->GetName());
	}
    else if (raid)
	{
		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_RAID", bot->GetName());
	}
    else
	{
		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_DUNGEON", bot->GetName());
	}

    if (list.empty())
        return false;

    sLFGMgr->JoinLfg(bot, GetRoles(), list, "bot");
    return true;
}

bool LfgRoleCheckAction::Execute(Event event)
{
    Group* group = bot->GetGroup();
    if (group)
    {
        sLFGMgr->UpdateRoleCheck(group->GetGUID(), bot->GetGUID(), GetRoles());
        return true;
    }

    return false;
}

bool LfgAcceptAction::Execute(Event event)
{
    uint32 id = AI_VALUE(uint32, "lfg proposal");
    if (id)
    {
        if (urand(0, 1 + 10 / sPlayerbotAIConfig.randomChangeMultiplier))
            return false;

        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s updated proposal %d", bot->GetName(), id);
        ai->GetAiObjectContext()->GetValue<uint32>("lfg proposal")->Set(0);
        sLFGMgr->UpdateProposal(id, bot->GetGUID(), true);

        ai->Reset();
        if (sRandomPlayerbotMgr.IsRandomBot(bot) && !bot->GetGroup())
        {
            sRandomPlayerbotMgr.Refresh(bot);
            ai->ResetStrategies();
        }
        return true;
    }

    WorldPacket p(event.getPacket());

    uint32 dungeon;
    uint8 state;
    p >> dungeon >> state >> id;

    ai->GetAiObjectContext()->GetValue<uint32>("lfg proposal")->Set(id);
    return true;
}

bool LfgLeaveAction::Execute(Event event)
{
    if (sLFGMgr->GetState(bot->GetGUID()) != LFG_STATE_QUEUED)
        return false;

    sLFGMgr->LeaveLfg(bot->GetGUID());
	return true;
}
