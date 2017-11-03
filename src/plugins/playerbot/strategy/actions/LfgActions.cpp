#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LfgActions.h"
#include "../../AiFactory.h"
#include "../../PlayerbotAIConfig.h"
#include "../ItemVisitors.h"
#include "../../RandomPlayerbotMgr.h"
#include "LFGMgr.h"
#include "LFG.h"
#include "DBCStores.h"

using namespace ai;
using namespace lfg;

bool LfgJoinAction::Execute(Event event)
{
	if (bot->InBattleground())
		return false;

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

    Group* group = bot->GetGroup();
    if (group && name == "lfg join") //stop the spam
       return false;

    Map* map = bot->GetMap();
    if (map && map->Instanceable())
        return false;

    return JoinProposal();
}

uint8 LfgJoinAction::GetRoles()
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
    {
        if (ai->IsTank(bot))
            return PLAYER_ROLE_TANK;
        if (ai->IsHeal(bot))
            return PLAYER_ROLE_HEALER;
        else return PLAYER_ROLE_DAMAGE;
    }

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
    bool raid = !heroic && (urand(0, 100) < 50 && visitor.count[ITEM_QUALITY_EPIC] >= 5 && (bot->getLevel() == 60 || bot->getLevel() == 70 || bot->getLevel() == 80));

    LfgDungeonSet list;
    vector<uint32> idx;
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

        if (random && dungeon->type != LFG_TYPE_RANDOM)
            continue;

        if (!random && !raid && !heroic && dungeon->type != LFG_TYPE_DUNGEON)
            continue;

        if (!random)
            list.insert(dungeon->ID);
        else
            idx.push_back(dungeon->ID);
    }

    if (list.empty())
        return false;

    uint8 roles = GetRoles();
    if (random)
    {
        list.insert(idx[urand(0, idx.size() - 1)]);
        sLFGMgr->JoinLfg(bot, roles, list, "bot");

        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_RANDOM as %d", bot->GetName().c_str(), (uint32)roles);
        return true;
    }
    else if (heroic)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_HEROIC_DUNGEON as %d", bot->GetName().c_str(), (uint32)roles);
    }
    else if (raid)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_RAID as %d", bot->GetName().c_str(), (uint32)roles);
    }
    else
    {
        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined to LFG_TYPE_DUNGEON as %d", bot->GetName().c_str(), (uint32)roles);
    }

    sLFGMgr->JoinLfg(bot, roles, list, "bot");
    return true;
}

bool LfgRoleCheckAction::Execute(Event event)
{
    Group* group = bot->GetGroup();
    if (group)
    {
        uint8 currentRoles = sLFGMgr->GetRoles(bot->GetGUID());
        uint8 newRoles = GetRoles();
        if (currentRoles == newRoles) return false;

        sLFGMgr->UpdateRoleCheck(group->GetGUID(), bot->GetGUID(), newRoles);
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

        if (bot->IsInCombat() || bot->isDead() || bot->IsFalling())
        {
            sLFGMgr->UpdateProposal(id, bot->GetGUID(), false);
            return true;
        }

        ai->ChangeStrategy("-grind", BOT_STATE_NON_COMBAT);

        if (sRandomPlayerbotMgr.IsRandomBot(bot) && !bot->GetGroup())
            ai->ChangeStrategy("-grind", BOT_STATE_NON_COMBAT);

        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s updated proposal %d", bot->GetName().c_str(), id);
        ai->GetAiObjectContext()->GetValue<uint32>("lfg proposal")->Set(0);
        bot->ClearUnitState(UNIT_STATE_ALL_STATE_SUPPORTED);
        sLFGMgr->UpdateProposal(id, bot->GetGUID(), true);

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

bool LfgTeleportAction::Execute(Event event)
{
    bool out = false;

    WorldPacket p(event.getPacket());
    if (!p.empty())
    {
        p.rpos(0);
        p >> out;
    }

    bot->ClearUnitState(UNIT_STATE_ALL_STATE_SUPPORTED);
    sLFGMgr->TeleportPlayer(bot, out);
    return true;
}

bool BGJoinAction::Execute(Event event)
{
    TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is running BGJoinAction::Execute", bot->GetName().c_str(), bot->GetGUID().GetCounter());
	if (!sPlayerbotAIConfig.randomBotJoinBG)
		return false;

	if (bot->isDead())
		return false;

	if (bot->getLevel() < 10)
		return false;

	if (!sRandomPlayerbotMgr.IsRandomBot(bot))
		return false;

	if (bot->InBattlegroundQueue())
		return false;

	if (bot->IsBeingTeleported())
		return false;

	Map* map = bot->GetMap();
	if (map && map->Instanceable())
		return false;

	return JoinProposal();
}

int j = 0;

bool BGJoinAction::JoinProposal()
{
    TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is running BGJoinAction::JoinProposal", bot->GetName().c_str(), bot->GetGUID().GetCounter());
	ai->GetAiObjectContext()->GetValue<uint32>("lfg proposal")->Set(1);

	if (bot->isUsingLfg())
	{
		// player is using dungeon finder or raid finder
		return false;
	}

	// warsong only at start
	// nyi: cycle based on time frame through AB and WS
	BattlegroundTypeId bgTypeId = BattlegroundTypeId::BATTLEGROUND_WS;

	// can do this, since it's battleground, not arena
	BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId,0);

	// ignore if player is already in BG
	if (bot->InBattleground())
		return false;

	Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
	if (!bg)
		return false;

	// expected bracket entry
	PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), bot->getLevel());
	if (!bracketEntry)
		return false;

	GroupJoinBattlegroundResult err;

	// check Deserter debuff
	if (!bot->CanJoinToBattleground(bg))
	{
		return false;
	}

	// check if already in queue
	if (bot->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
		// player is already in this queue
		return false;

	// check if has free queue slots
	if (!bot->HasFreeBattlegroundQueueId())
	{
		return false;
	}

	// check Freeze debuff
	if (bot->HasAura(9454))
		return false;

	BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
	if (bgQueue.m_QueuedPlayers.size()>0)
	{
		GroupQueueInfo* ginfo = bgQueue.AddGroup(bot, NULL, bgTypeId, bracketEntry, 0, false, false, 0, 0);
		uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
		// already checked if queueSlot is valid, now just get it
		uint32 queueSlot = bot->AddBattlegroundQueueId(bgQueueTypeId);

		sLog->outMessage("bg.battleground", LogLevel::LOG_LEVEL_DEBUG, "Battleground: player joined queue for bg queue type %u bg type %u: GUID %u, NAME %s",
			bgQueueTypeId, bgTypeId, bot->GetGUID().GetCounter(), bot->GetName().c_str());
		return true;
	}
	return false;
}

bool BGStatusAction::Execute(Event event)
{
    TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is running BGStatusAction::Execute", bot->GetName().c_str(), bot->GetGUID().GetCounter());

	uint32 QueueSlot;
	uint8 arenatype;
	uint8 arenaByte;
	uint32 battleId;
	uint16 x1f90;
	uint8 minlevel;
	uint8 maxlevel;
	uint32 instanceId;
	uint8 isRated;
	uint32 statusid;

	WorldPacket p(event.getPacket());
	statusid = 0;

	//on status 0, the packet has a uint64 as payload only. Took me two suicide tries and a gnomen porn video to find out
	p >> QueueSlot >> arenatype >> arenaByte >> battleId >> x1f90;
	if (x1f90!=0)
		p >> minlevel >> maxlevel >> instanceId >> isRated >> statusid;

	if (statusid == STATUS_WAIT_LEAVE) //battleground is over, bot needs to leave
	{
		TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is going to leave battleground (%u).", bot->GetName().c_str(), bot->GetGUID().GetCounter(), battleId);
		bot->LeaveBattleground(true);
		ai->ResetStrategies();
	}
	if (statusid == STATUS_WAIT_QUEUE) //bot is in queue
	{
		TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is still in queue (%u).", bot->GetName().c_str(), bot->GetGUID().GetCounter(), battleId);
	}
	if (statusid == STATUS_WAIT_JOIN) //bot may join
	{
		if (bot->InBattleground())
		{
			TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) is in battleground already. (%u, %u).", bot->GetName().c_str(), bot->GetGUID().GetCounter(), battleId, instanceId);
			return false;
		}

		TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) received a invite to a battleground (%u, %u).", bot->GetName().c_str(), bot->GetGUID().GetCounter(), battleId, instanceId);

		bot->CombatStop(true);

		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s is going to join BG %d", bot->GetName().c_str(), battleId);

		bot->ClearUnitState(UNIT_STATE_ALL_STATE_SUPPORTED);

		//get GroupQueueInfo from BattlegroundQueue
		BattlegroundTypeId bgTypeId = BattlegroundTypeId(battleId);
		BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, 0);
		BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
		//we must use temporary variable, because GroupQueueInfo pointer can be deleted in BattlegroundQueue::RemovePlayer() function
		GroupQueueInfo ginfo;
		if (!bgQueue.GetPlayerGroupInfoData(bot->GetGUID(), &ginfo))
		{
			sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s was not in queue to join BG %d", bot->GetName().c_str(), battleId);
			return false;
		}
		// if action == 1, then instanceId is required
		if (!ginfo.IsInvitedToBGInstanceGUID)
		{
			sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s had no instanceID to join BG %d", bot->GetName().c_str(), battleId);
			return false;
		}

		Battleground* bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
		if (!bg)
		{
			bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
			if (!bg)
			{
				sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s could find no template for Battleground %d", bot->GetName().c_str(), battleId);
				return false;
			}
		}

		// expected bracket entry
		PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), bot->getLevel());
		if (!bracketEntry)
		{
			sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s has no bracket (%d) available to join BG %d", bot->GetName().c_str(), bot->getLevel(), battleId);
			return false;
		}

		//some checks if player isn't cheating - it is not exactly cheating, but we cannot allow it
		if (ginfo.ArenaType == 0)
		{
			//if player is trying to enter battleground (not arena!) and he has deserter debuff, we must just remove him from queue
			if (!bot->CanJoinToBattleground(bg))
			{
				sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s cant join BG %d because it has the deserter debuf", bot->GetName().c_str(), battleId);
				return false;
			}
			//if player don't match battleground max level, then do not allow him to enter! (this might happen when player leveled up during his waiting in queue
			if (bot->getLevel() > bg->GetMaxLevel())
			{
				sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s cant join BG %d because its level does not fit", bot->GetName().c_str(), battleId);
				return false;
			}
		}
		uint32 queueSlot = bot->GetBattlegroundQueueIndex(bgQueueTypeId);
		// check Freeze debuff
		if (bot->HasAura(9454))
		{
			sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s cant join BG %d because it is freezed", bot->GetName().c_str(), battleId);
			return false;
		}

		if (!bot->IsInvitedForBattlegroundQueueType(bgQueueTypeId))
		{
			sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s cant join BG %d because it was not invited to join", bot->GetName().c_str(), battleId);
			return false;                                 // cheating? No, bots dont cheat. They just try very hard.
		}

		if (!bot->InBattleground())
			bot->SetBattlegroundEntryPoint();

		// resurrect the player
		if (!bot->IsAlive())
		{
			bot->ResurrectPlayer(1.0f);
			bot->SpawnCorpseBones();
		}
		// stop taxi flight at port
		bot->GetMotionMaster()->MovementExpired();
		if (bot->IsInFlight())
		{
			bot->CleanupAfterTaxiFlight();
		}

		// remove battleground queue status from BGmgr
		bgQueue.RemovePlayer(bot->GetGUID(), false);
		// this is still needed here if battleground "jumping" shouldn't add deserter debuff
		// also this is required to prevent stuck at old battleground after SetBattlegroundId set to new
		if (Battleground* currentBg = bot->GetBattleground())
			currentBg->RemovePlayerAtLeave(bot->GetGUID(), false, true);

		// set the destination instance id
		bot->SetBattlegroundId(bg->GetInstanceID(), bgTypeId);
		// set the destination team
		bot->SetBGTeam(ginfo.Team);

		// bg->HandleBeforeTeleportToBattleground(_player);
		sBattlegroundMgr->SendToBattleground(bot, ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
		ai->ResetStrategies();
		// add only in HandleMoveWorldPortAck()
		// bg->AddPlayer(_player, team);
		TC_LOG_DEBUG("bg.battleground", "Battleground: player (bot) %s (%u) joined battle for bg %u, bgtype %u, queue type %u.", bot->GetName().c_str(), bot->GetGUID().GetCounter(), bg->GetInstanceID(), bg->GetTypeID(), bgQueueTypeId);
		sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Bot %s joined BG %d", bot->GetName().c_str(), battleId);
	}
	return true;
}


//consume healthy, if low on health
bool BGTacticsWS::consumeHealthy(Battleground *bg)
{

	//alliance healthy
	if (bot->HealthBelowPct(50))
	{
		Position posH1 = Position(1111.526733f, 1352.458130f, 316.567047f, 0);
		Position posA1 = Position(1320.670288f, 1549.642700f, 313.501404f, 0);


		if (bot->GetDistance(posH1)<40)
		{
			return MoveTo(bg->GetMapId(), posH1.m_positionX, posH1.m_positionY, posH1.m_positionZ);
		}
		if (bot->GetDistance(posA1)<40)
		{
			return MoveTo(bg->GetMapId(), posH1.m_positionX, posH1.m_positionY, posH1.m_positionZ);
		}
	}
	return false;

}

//run to enemy flag if not taken yet
bool BGTacticsWS::moveTowardsEnemyFlag(BattlegroundWS *bg)
{
	//If no flag is spawned, do something else
	if (!(bg->GetFlagState(bg->GetOtherTeam(bot->GetTeam())) == BG_WS_FLAG_STATE_ON_BASE ||
		bg->GetFlagState(bg->GetOtherTeam(bot->GetTeam())) == BG_WS_FLAG_STATE_ON_GROUND))
		return false;
	if (bg->GetFlagState(bot->GetTeam()) == BG_WS_FLAG_STATE_WAIT_RESPAWN)
		return false;
	GameObject* target_obj = bg->GetBgMap()->GetGameObject(bg->GetDroppedFlagGUID(bg->GetOtherTeam(bot->GetTeam()) == ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE));
	if (target_obj == NULL)
	{
		if (bot->GetTeam() == HORDE)
			target_obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_A_FLAG]);
		else
			target_obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_H_FLAG]);
	}
	//Direct Movement, if we are close
	/*if (bot->IsWithinDist(target_obj, 40))
	{
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Bot %s attempting to chase to enemy flag", bot->GetName().c_str());
		ChaseTo(target_obj);
		return true;
	}*/
	GameObject* obj = bg->GetBgMap()->GetGameObject(bg->GetFlagPickerGUID(bot->GetTeam() == ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE));
	if (obj == NULL)
	{
		if (bot->GetTeamId() == TeamId::TEAM_HORDE)
			obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_A_FLAG]);
		else
			obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_H_FLAG]);
	}
	return runPathTo(obj, bg);
}

//if we have the flag, run home
bool BGTacticsWS::homerun(BattlegroundWS *bg)
{
	if (!(bg->GetFlagState(bg->GetOtherTeam(bot->GetTeam())) == BG_WS_FLAG_STATE_ON_PLAYER))
		return false;
	if (bot->GetGUID() == bg->GetFlagPickerGUID(bg->GetOtherTeam(bot->GetTeam()) == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE)) //flag-Carrier, bring it home
	{
		GameObject* obj = bg->GetBgMap()->GetGameObject(bg->GetFlagPickerGUID(bot->GetTeam() == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE));
		if (obj == NULL)
		{
			if (bot->GetTeamId() == TeamId::TEAM_HORDE)
				obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_H_FLAG]);
			else
				obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_A_FLAG]);
		}
		if (bot->IsWithinDistInMap(obj, 10) && (bg->GetFlagState(bot->GetTeam()) == BG_WS_FLAG_STATE_ON_BASE))
		{
			bg->EventPlayerCapturedFlag(bot);
			return true;
		}
		return runPathTo(obj, bg);
	}
	else {
		bool supporter = bot->Preference <5;
		//random choice if defense or offense
		if (supporter || (bg->GetFlagState(bot->GetTeam()) != BG_WS_FLAG_STATE_ON_PLAYER))
		{
			ObjectGuid guid = bg->GetFlagPickerGUID(bg->GetOtherTeam(bot->GetTeam()) == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE);
			Player* ourGuy = ObjectAccessor::FindPlayer(guid);
			if (ourGuy != NULL)
			{
				if (!bot->IsWithinDist(ourGuy, 40))
					return runPathTo(ourGuy,bg);
				return Follow(ourGuy);
			}
		}
		else { //as a none supporter, attack their flag, if they carry it
			ObjectGuid guid = bg->GetFlagPickerGUID(bot->GetTeam() == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE);
			Player* theirGuy = ObjectAccessor::FindPlayer(guid);
			if (theirGuy != NULL)
			{
				return runPathTo(theirGuy,bg);
			}
		}
	}
	return false;
}

//the alliance base entrance is at x=1351.759155 , y=1462.368042, z = 323.673737
//the horde base entrance is at x=1125.778076, y=1452.059937, z =315.698883
//left center of the battlefield is at x=1239.085693,y=1541.408569,z=306.491791
//middle center of the battlefield is at x=1227.446289,y=1476.235718,z=307.484589
//right center of the battlefield is at x=1269.962158,y=1382.655640,z=308.545288
//the alliance flag is at x=1538.387207,y=1480.903198,z=352.576385
//the horde flag is at x=919.161316,x=1433.871338,z=345.902771

//horde healthy is at x=1111.526733,y=1352.458130,z=316.567047
//alliance healthy is at x=1320.670288,y=1549.642700, z=313.501404

//alliance fasty is at x=1449.574219,y=1470.698608, z=342.675476
//horde fasty is at x=1006.590210,y=1450.435059, z=335.721283

//alliance graveyard is at x=1370.087769, y=1539.914551, z=321.451538

//Alliance wants to move towards a lower x value

//get back to alliance base

//cross the battleground to get to flags or flag carriers
bool BGTacticsWS::runPathTo(WorldObject *unit,Battleground *bg)
{
	if (unit == NULL)
		return false;
	//if (unit->IsWithinDist(bot, 40))
	//	return ChaseTo(unit);
	if (unit->m_positionX > bot->m_positionX) //He's somewhere at the alliance side
	{
		if (bot->Preference < 4) //preference < 4 = move through tunnel
		{
			if (bot->m_positionX < 1006) //to the fasty
			{
				MoveTo(bg->GetMapId(), 1006.590210f, 1450.435059f, 335.721283f);
				return  true;
			}
			else if (bot->m_positionX < 1125) //to the horde entrance
			{
				if (bot->m_positionY < 1400)
					MoveTo(bg->GetMapId(), 1125.778076f, bot->m_positionY, 316.567047f);
				else
					MoveTo(bg->GetMapId(), 1125.778076f, 1452.059937f, 315.698883f);
				return  true;
			}
		}
		else if(bot->Preference<7) { // preference < 7 = move through graveyard
			if (bot->m_positionX < 985) //to the gate at the upper tunnel
			{
				MoveTo(bg->GetMapId(), 985.940125f,1423.260254f,345.418121f);
				return  true;
			}
			else if (bot->m_positionX < 1054.5) //to the gate at the upper tunnel
			{
				MoveTo(bg->GetMapId(), 1055.182251f,1396.967529f,339.361511f);
				return  true;
			}
			else if (bot->m_positionX < 1125) //to the horde entrance
			{
				MoveTo(bg->GetMapId(), 1125.778076f, bot->m_positionY, 316.567047f);
				return  true;
			}
		}
		else { //all other preference: run down the ramp 
			if (bot->m_positionX < 985) //to the gate at the upper tunnel
			{
				MoveTo(bg->GetMapId(), 985.940125f, 1423.260254f, 345.418121f);
				return  true;
			}
			else if (bot->m_positionX < 1031) //to the first step of the ramp from the tunnel
			{
				MoveTo(bg->GetMapId(), 1031.764282f, 1454.516235f, 343.337860f);
				return  true;
			}
			else if (bot->m_positionX < 1051 && bot->m_positionY < 1494) //to the second step of the ramp from the tunnel
			{
				MoveTo(bg->GetMapId(), 1051.304810f, 1494.917725f, 342.043518f);
				return  true;
			}
			else if (bot->m_positionX < 1050 && bot->m_positionY < 1538) //down the ramp
			{
				MoveTo(bg->GetMapId(), 1050.089478f, 1538.054443f, 332.460388f);
				return  true;
			}
			else if (bot->m_positionX < 1050 && bot->m_positionY < 1560) //down the ramp
			{
				MoveTo(bg->GetMapId(), 1050.089478f, 1560.054443f, 332.460388f);
				return  true;
			}
			else if (bot->m_positionX < 1098) //at the ground now
			{
				MoveTo(bg->GetMapId(), 1098.716797f, 1535.618652f, 315.727539f);
				return  true;
			}
			else if (bot->m_positionX < 1239)
			{
				MoveTo(bg->GetMapId(), 1239.085693f, 1541.408569f + frand(-2, +2), 306.491791f);
				return  true;
			}
		}
		if (bot->m_positionX < 1227) //move to a more random location in the middle part
		{
			if (bot->m_positionY < 1400)
				MoveTo(bg->GetMapId(), 1269.962158f, 1382.655640f + frand(-2, +2), 308.545288f);
			else
				MoveTo(bg->GetMapId(), 1227.446289f, 1476.235718f + frand(-2, +2), 307.484589f);
			return  true;
		}
		if (bot->Preference < 5) //through the tunnel
		{
			if (bot->m_positionX < 1351) //move to the alliance entrance
			{
				MoveTo(bg->GetMapId(), 1351.759155f + frand(0, 2), 1462.368042f + frand(-2, +2), 323.673737f);
				return  true;
			}
			else if (bot->m_positionX < 1449) //move to the alliance fasty
			{
				MoveTo(bg->GetMapId(), 1449.574219f, 1470.698608f, 342.675476f);
				return  true;
			}
			else { //move to the flag position
				MoveTo(bg->GetMapId(), 1538.387207f, 1480.903198f, 352.576385f);
				return  true;
			}
		}
		else { //up the ramp
			if (bot->m_positionX < 1360) //gate at the ramp
			{
				MoveTo(bg->GetMapId(), 1360.088501f, 1393.451660f + frand(-2, +2), 326.183624f);
				return  true;
			}
			if (bot->m_positionX < 1399) //half way up
			{
				MoveTo(bg->GetMapId(), 1399.362061f, 1405.105347f + frand(-2, +2), 341.481476f);
				return  true;
			}
			if (bot->m_positionX < 1417) //first halway
			{
				MoveTo(bg->GetMapId(), 1417.096191f, 1459.552368f + frand(-2, +2), 349.591827f);
				return  true;
			}
			if (bot->m_positionX < 1505.2) //gate to the flag room
			{
				MoveTo(bg->GetMapId(), 1505.045654f, 1493.787231f, 352.017670f);
				return  true;
			}
			else { //move to the flag position
				MoveTo(bg->GetMapId(), 1538.387207f, 1480.903198f, 352.576385f);
				bot->Preference = urand(0, 9); //reset preference
				return  true;
			}
		}
	} 
	else //move towards horde base
	{
		if (bot->Preference < 4) //through the tunnel
		{
			if (bot->m_positionX > 1449.7) //to the fasty
			{
				MoveTo(bg->GetMapId(), 1449.574219f, 1470.698608f, 342.675476f);
				return  true;
			}
			else if (bot->m_positionX > 1443.9) { // moving from the fasty to the gate directly is bugged.. moving back to the tunnel first
				MoveTo(bg->GetMapId(), 1443.761963f, 1459.581909f, 342.115417f);
			}
			else if (bot->m_positionX > 1380.9) { // move into the tunnel
				MoveTo(bg->GetMapId(), 1380.761963f, 1457.581909f, 329.115417f);
			}
			else if (bot->m_positionX > 1351.9) //to the alliance entrance
			{
				if (bot->m_positionY > 1500)
					MoveTo(bg->GetMapId(), 1125.778076f, bot->m_positionY, 315.698883f);
				else
					MoveTo(bg->GetMapId(), 1125.778076f, 1452.059937f, 315.698883f);
				return  true;
			}
			if (bot->m_positionX > 1240) //move to a more random location in the middle part
			{
				if (bot->m_positionY > 1500)
					MoveTo(bg->GetMapId(), 1239.085693f, 1541.408569f + frand(-2, +2), 306.491791f);
				else
					MoveTo(bg->GetMapId(), 1227.446289f, 1476.235718f + frand(-2, +2), 307.484589f);
				return  true;
			}
		}
		else if (bot->Preference < 7) // through the graveyard
		{
			if (bot->m_positionX > 1505.2) //To the first gate
			{
				MoveTo(bg->GetMapId(), 1505.045654f, 1493.787231f, 352.017670f);
				return  true;
			}
			else if (bot->m_positionX > 1460) //to the second gate
			{
				MoveTo(bg->GetMapId(), 1459.490234f, 1494.175072f, 351.565155f);
				return  true;
			}
			else if (bot->m_positionX > 1424) //to the graveyard
			{
				MoveTo(bg->GetMapId(), 1423.106201f + frand(-2, +2), 1532.851196f, 342.152100f);
				return  true;
			}
			else if (bot->m_positionX > 1345) // to the field
			{
				MoveTo(bg->GetMapId(), 1344.334595f + frand(-2, +2), 1514.917236f, 319.081726f);
				return  true;
			}
		}
		else
		{
			if (bot->m_positionX > 1505.2) //To the first gate
			{
				MoveTo(bg->GetMapId(), 1505.045654f, 1493.787231f, 352.017670f);
				return  true;
			}
			else if (bot->m_positionX > 1460) //to the second gate
			{
				MoveTo(bg->GetMapId(), 1459.490234f, 1494.175072f, 351.565155f);
				return  true;
			}
			else if (bot->m_positionX > 1418) //half on the upper ramp
			{
				MoveTo(bg->GetMapId(), 1417.096191f, 1459.552368f, 349.591827f);
				return  true;
			}
			else if (bot->m_positionX > 1400) //middle down the ramp
			{
				MoveTo(bg->GetMapId(), 1399.362061f, 1405.105347f, 341.481476f);
				return  true;
			}
			else if (bot->m_positionX > 1357) //at the gate
			{
				MoveTo(bg->GetMapId(), 1356.088501f, 1393.451660f, 326.183624f);
				return  true;
			}
			else if (bot->m_positionX > 1270) // run the gate side way to the middle field
			{
				MoveTo(bg->GetMapId(), 1269.962158f, 1382.655640f + frand(-2, +2), 308.545288f);
				return true;
			}
		}
		if (bot->Preference < 5) //horde ramp
		{
			if (bot->m_positionX > 1099) //move to the horde ramp gate
			{
				MoveTo(bg->GetMapId(), 1096.716797f, 1535.618652f, 315.727539f);
				return  true;
			}
			if (bot->m_positionX > 1071) //move the ramp up a piece
			{
				MoveTo(bg->GetMapId(), 1070.089478f, 1538.054443f, 332.460388f);
				return  true;
			}
			if (bot->m_positionX > 1050.2) //move the ramp up a piece
			{
				MoveTo(bg->GetMapId(), 1050.089478f, 1538.054443f, 332.460388f);
				return  true;
			}
			if (bot->m_positionX > 1032) //up in front of first entrance
			{
				MoveTo(bg->GetMapId(), 1031.764282f, 1454.516235f, 343.337860f);
				return  true;
			}
			if (bot->m_positionX > 986) //up in front of first entrance
			{
				MoveTo(bg->GetMapId(), 985.940125f, 1423.260254f, 345.418121f);
				return  true;
			}
			MoveTo(bg->GetMapId(), 919.161316f, 1433.871338f, 345.902771f);
			return  true;
		}
		else { //horde tunnel

			if (bot->m_positionX > 1125.9f) //move to the horde entrance
			{
				MoveTo(bg->GetMapId(), 1125.778076f, 1452.059937f, 315.698883f);
				return  true;
			}
			else if (bot->m_positionX > 1006.7f) //move to the horde fasty
			{
				MoveTo(bg->GetMapId(), 1006.590210f, 1450.435059f, 335.721283f);
				return  true;
			}
			else { //move to the flag position
				MoveTo(bg->GetMapId(), 919.161316f, 1433.871338f, 345.902771f);
				bot->Preference = urand(0, 9); //reset preference
				return  true;
			}
		}
	}
	return false;
}

//is being called, when flag "+warsong" is set
bool BGTacticsWS::Execute(Event event)
{
	if (!bot->InBattleground())
		return false;
	if (bot->isDead())
	{
		bot->GetMotionMaster()->MovementExpired();
	}
	//Check for Warsong.
	if (bot->GetBattleground()->GetTypeID() == BattlegroundTypeId::BATTLEGROUND_WS)
	{
		ai->SetMaster(NULL);
		if (bot->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
			bot->RemoveAurasByType(SPELL_AURA_SPIRIT_OF_REDEMPTION);
		if (bot->IsInCombat())
		{
			if (!wasInCombat)
				bot->GetMotionMaster()->MovementExpired();
		}
		wasInCombat = bot->IsInCombat();
		//In Warsong, the bots run to the other flag and take it, try to get back and protect each other.
		//If our flag was taken, pures will try to get it back
		BattlegroundWS* bg = (BattlegroundWS *)bot->GetBattleground();
		if (bg != NULL && !bot->isDead())
		{
			//If flag is close, always click it.
			bool alreadyHasFlag = bg->GetFlagState(bg->GetOtherTeam(bot->GetTeam())) == BG_WS_FLAG_STATE_ON_PLAYER;
			if (!alreadyHasFlag)
			{
				GameObject* target_obj = bg->GetBgMap()->GetGameObject(bg->GetDroppedFlagGUID(bg->GetOtherTeam(bot->GetTeam()) == ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE));
				if (target_obj == NULL)
				{
					if (bot->GetTeam() == HORDE)
					{
						target_obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_A_FLAG]);
					}
					else
					{
						target_obj = bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_H_FLAG]);
					}
				}
				if (bot->IsWithinDistInMap(target_obj, 10))
				{
					bg->EventPlayerClickedOnFlag(bot, target_obj);
					return true;
				}
			}
			// startup phase
			if (bg->GetStartDelayTime()>0)
			{
				if (bot->GetTeam() == ALLIANCE) //you.. may... NOT.. PASS!
				{
					if (bot->m_positionX <1507)
					{
						bot->GetMotionMaster()->MovementExpired();
						MoveTo(bg->GetMapId(), 1510, bot->m_positionY, bot->m_positionZ);
						return false;
					}
				}
				else {
					if (bot->m_positionX > 947)
					{
						bot->GetMotionMaster()->MovementExpired();
						MoveTo(bg->GetMapId(), 950, bot->m_positionY, bot->m_positionZ);
						return false;
					}
				}
				if (!bot->IsInCombat())
				{
					Position const* pos = bg->GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(bot->GetTeam()));
					for (std::map<ObjectGuid, BattlegroundPlayer>::const_iterator itr = bg->GetPlayers().begin(); itr != bg->GetPlayers().end(); ++itr)
					{
						if (urand(0, 100) < 2)
							return MoveNear(bg->GetMapId(),pos->m_positionX,pos->m_positionY,pos->m_positionZ, frand(1.0, 5.0));
					}
				}
				return true;
			}
			//check if we are moving or in combat
			if (!IsMovingAllowed() || bot->isMoving())
				return false;
			bool moving = false;
			//Only go for directive, if not in combat
			if (!bot->IsInCombat())
			{
				moving = consumeHealthy(bg);
				if (!moving)
					moving = moveTowardsEnemyFlag(bg);
				if (!moving)
					moving = homerun(bg);
			}
			if (!moving)
			{
				if (bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_A_FLAG]) == NULL &&
					bg->GetBgMap()->GetGameObject(bg->BgObjects[BG_WS_OBJECT_H_FLAG]) == NULL)
				{
					float distance = sPlayerbotAIConfig.tooCloseDistance + sPlayerbotAIConfig.grindDistance * urand(3, 10) / 10.0f;

					Map* map = bot->GetMap();

					for (int i = 0; i < 10; ++i)
					{
						float x = bot->GetPositionX();
						float y = bot->GetPositionY();
						float z = bot->GetPositionZ();
						x += urand(0, distance) - distance / 2;
						y += urand(0, distance) - distance / 2;
						bot->UpdateGroundPositionZ(x, y, z);

						if (map->IsInWater(x, y, z))
							continue;

						bool moved = MoveNear(bot->GetMapId(), x, y, z);
						if (moved)
							break;
					}
				}
				else 
				{
					AttackAnythingAction* action = new AttackAnythingAction(ai);
					action->Execute(event);
				}
			}
		}
	}
	return true;
}
