#include "PlayerBotTalkMgr.h"
#include "World.h"
#include "MapManager.h"
#include "Player.h"
#include "Guild.h"
#include "Group.h"
#include "BotFieldAI.h"
#include "BotGroupAI.h"
#include "PathfindingMgr.h"
#include "Config.h"
#include "FieldBotMgr.h"

uint32 FieldStory::LastStoryEntry = 0;
bool FieldWarfare::AID_TARGET_TEAM = false;
bool FieldBotMgr::FIELDBOT_CREATURE = true;
#ifdef INCOMPLETE_BOT
bool FieldBotMgr::FIELDBOT_DRIVING = true;
#else
bool FieldBotMgr::FIELDBOT_DRIVING = false;
#endif
uint32 FieldBotMgr::FIELDWARFARE_SIZE = 2;

void WorldPoster::SendOnceGlobalPoster()
{
	if (m_AllPosterContent.empty())
		return;
	if (sendTick < 1)
	{
		++sendTick;
		return;
	}
	sendTick = 0;

	if (currentPoster >= m_AllPosterContent.size())
		currentPoster = 0;

	sWorld->SendGlobalText(m_AllPosterContent[currentPoster].c_str(), NULL);

	++currentPoster;
}

void WorldPoster::InitializePoster()
{
	m_AllPosterContent.clear();
    PushPoster("这里是公告文本 我曰");
}

void WorldPoster::PushPoster(std::string content)
{
	if (content.empty())
		return;

	std::string allonlineText;
	consoleToUtf8(std::string("|cffff8800") + content + std::string("|r"), allonlineText);
	m_AllPosterContent.push_back(allonlineText);
}

FieldStory::FieldStory() :
FieldActing(ACTING_STORY),
m_StoryTimer(getMSTime()),
m_StoryEntry(sPlayerBotTalkMgr->RandomStoryID()),
m_StoryStep(0)
{
	int32 maxRnd = 5;
	while (m_StoryEntry == FieldStory::LastStoryEntry)
	{
		if (maxRnd <= 0)
			break;
		--maxRnd;
		m_StoryEntry = sPlayerBotTalkMgr->RandomStoryID();
	}

	FieldStory::LastStoryEntry = m_StoryEntry;
}

bool FieldStory::FieldActingIsOver()
{
	if (m_StoryEntry == -1 || m_StoryStep == -1)
		return true;
	if (!sPlayerBotTalkMgr->IsValidStoryStep(m_StoryEntry, m_StoryStep))
	{
		m_StoryEntry = -1;
		m_StoryStep = -1;
		return true;
	}
	return false;
}

void FieldStory::Update()
{
	if (!sPlayerBotTalkMgr->CanNextTalk())
		return;
	uint32 talkIndex = -1;
	std::string talkText;
	bool success = sPlayerBotTalkMgr->GetStoryByIndex(m_StoryEntry, m_StoryStep, talkIndex, talkText);
	if (!success || talkIndex == -1 || talkText.empty())
	{
		m_StoryEntry = -1;
		m_StoryStep = -1;
		return;
	}
	if (!FillNeedBotGUID(talkIndex) || m_TalkBotGUIDs.size() <= talkIndex)
	{
		m_StoryEntry = -1;
		m_StoryStep = -1;
		return;
	}
	Player* player = ObjectAccessor::FindPlayer(m_TalkBotGUIDs[talkIndex]);
	if (!player)
	{
		m_StoryEntry = -1;
		m_StoryStep = -1;
		return;
	}
	sPlayerBotTalkMgr->StoryActingTalk(player, talkText);
	++m_StoryStep;
}

bool FieldStory::FillNeedBotGUID(uint32 index)
{
	if (m_TalkBotGUIDs.size() > index)
		return true;
	std::vector<ObjectGuid> rndGUIDs;
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (itSession->second->PlayerLoading() || !itSession->second->IsBotSession())
			continue;
		Player* player = itSession->second->GetPlayer();
		if (!player || !player->IsInWorld())
			continue;
		ObjectGuid botGUID = player->GetGUID();
		if (ExistBotGUID(botGUID))
			continue;
		rndGUIDs.push_back(botGUID);
	}
	uint32 maxLoop = index + 1;
	while (m_TalkBotGUIDs.size() <= index)
	{
		if (maxLoop == 0)
			return false;
		--maxLoop;
		if (rndGUIDs.empty())
			return false;
		uint32 selIndex = urand(0, rndGUIDs.size() - 1);
		for (std::vector<ObjectGuid>::iterator itGUID = rndGUIDs.begin(); itGUID != rndGUIDs.end(); itGUID++)
		{
			if (selIndex == 0)
			{
				m_TalkBotGUIDs.push_back(*itGUID);
				rndGUIDs.erase(itGUID);
				break;
			}
			--selIndex;
		}
	}
	return true;
}

bool FieldStory::ExistBotGUID(ObjectGuid& guid)
{
	if (guid == ObjectGuid::Empty)
		return true;
	for (ObjectGuid& botGUID : m_TalkBotGUIDs)
	{
		if (botGUID == guid)
			return true;
	}
	return false;
}

FieldWarfare::FieldWarfare(Player* trigger, Player* target) :
FieldActing(ACTING_WARFARE),
m_WarfareTrigger(trigger->GetGUID()),
m_WarfareTarget(target->GetGUID()),
m_WarfareMapID(target->GetMapId()),
m_TriggerTeam(trigger->GetTeamId()),
m_TriggerTimer(getMSTime()),
m_WarfareDurable(5 * 60000),
m_WarfareStartTimer(0),
m_WarfareEndTimekeeping(0),
m_TriggerTeamKill(0),
m_AttackTeamKill(0)
{
	FieldWarfare::AID_TARGET_TEAM = false;
	UpdateWarfareDurableTimer();
#ifdef _DEBUG
	sWorld->SendGlobalText("Warfare start", NULL);
#endif
}

bool FieldWarfare::FieldActingIsOver()
{
	if (m_WarfareTrigger == ObjectGuid::Empty || m_WarfareTarget == ObjectGuid::Empty)
		return true;
	uint32 currentTick = getMSTime();
	if ((m_TriggerTimer + m_WarfareDurable) > currentTick)
		return false;
	if (m_WarfareEndTimekeeping == 0)
	{
		FieldWarfare::AID_TARGET_TEAM = false;
		uint32 endRate = 2;
		if (FieldBotMgr::FIELDWARFARE_SIZE == 2)
			endRate = 3;
		else if (FieldBotMgr::FIELDWARFARE_SIZE == 3)
			endRate = 4;
		m_WarfareEndTimekeeping = currentTick + endRate * 60000;
#ifdef _DEBUG
		sWorld->SendGlobalText("Warfare over", NULL);
#endif
		return false;
	}
	return (currentTick > m_WarfareEndTimekeeping);
}

void FieldWarfare::Update()
{
#ifndef INCOMPLETE_BOT
	Player* targetPlayer = ObjectAccessor::FindPlayer(m_WarfareTarget);
	if (!targetPlayer || m_WarfareMapID != targetPlayer->GetMapId())
	{
		OverFieldActing();
		return;
	}
	if (!targetPlayer->IsInWorld())
		return;

	if (IsWarfareStartTime())
		ProcessStart();
	else if (m_WarfareEndTimekeeping == 0)
		ProcessWarrfare(targetPlayer);
	else
		ProcessEpilog(targetPlayer);
#endif
}

void FieldWarfare::UpdateWarfareKill(Player* deather)
{
	if (!deather || m_WarfareEndTimekeeping != 0)
		return;
	if (m_TriggerTeam == TEAM_ALLIANCE)
	{
		if (deather->GetTeamId() == TEAM_ALLIANCE)
			++m_AttackTeamKill;
		else
			++m_TriggerTeamKill;
	}
	else
	{
		if (deather->GetTeamId() == TEAM_ALLIANCE)
			++m_TriggerTeamKill;
		else
			++m_AttackTeamKill;
	}
}

bool FieldWarfare::IsWarfareStartTime()
{
	if (m_TriggerTimer == 0)
		return false;
	uint32 currentTick = getMSTime();
	if (m_TriggerTimer + 30 * 1000 > currentTick)
		return true;
	return false;
}

void FieldWarfare::ProcessStart()
{
	Player* triggerPlayer = ObjectAccessor::FindPlayer(m_WarfareTrigger);
	if (!triggerPlayer || m_WarfareMapID != triggerPlayer->GetMapId())
	{
		OverFieldActing();
		return;
	}
	sPlayerBotTalkMgr->WarfareActingTalk(0, triggerPlayer);
}

void FieldWarfare::ProcessWarrfare(Player* targetPlayer)
{
	if (!targetPlayer || targetPlayer->IsFlying())
		return;
    //if(targetPlayer->getLevel()< sConfigMgr->GetIntDefault("PBot.SaveLevel", 20))
    //    return;
	int32 maxCount = GetWarfareMaxCount();
	int32 talkRate = irand(0, maxCount);
	int32 nearAlliance = 0;
	int32 nearHorde = 0;
	//NearPlayerList playersNearby;
	//targetPlayer->GetPlayerListInGrid(playersNearby, BOTAI_FIELDTELEPORT_DISTANCE * 3.0f);
	//for (Player* nearPlayer : playersNearby)
	//{
	//	if (nearPlayer->GetTeamId() == TEAM_ALLIANCE)
	//		++nearAlliance;
	//	else if (nearPlayer->GetTeamId() == TEAM_HORDE)
	//		++nearHorde;
	//	if (nearPlayer->IsAlive() && nearPlayer->IsPlayerBot())
	//	{
	//		if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(nearPlayer->GetAI()))
	//		{
	//			pFieldAI->SetDrivingPVP(true);
	//			pFieldAI->SetWarfareTarget(targetPlayer);
	//		}
	//	}
	//}
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (itSession->second->PlayerLoading() || !itSession->second->IsBotSession() || itSession->second->IsAccountBotSession())
			continue;
		Player* player = itSession->second->GetPlayer();
		if (!player)
			continue;
		if (m_WarfareMapID != targetPlayer->GetMapId() || player->InBattleground() || player->InArena() || player->InBattlegroundQueue())
			continue;
        if (player->GetMapId() != targetPlayer->GetMapId())
            TeleportToTargetVisible(player, targetPlayer);
		if (targetPlayer->GetDistance(player) > BOTAI_FIELDTELEPORT_DISTANCE * 3.0f)
			continue;
		if (player->GetTeamId() == TEAM_ALLIANCE)
			++nearAlliance;
		else if (player->GetTeamId() == TEAM_HORDE)
			++nearHorde;
		if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI()))
		{
			pFieldAI->SetDrivingPVP(true);
			pFieldAI->SetWarfareTarget(targetPlayer);

			--talkRate;
			if (talkRate < 1)
			{
				talkRate = maxCount;
				sPlayerBotTalkMgr->WarfareActingTalk(1, player);
			}
		}
	}

    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
    int32 maxNearPlayer = (int32)sPlayerBotMgr->GetAllowMaxBotCount();
    int32 maxWarrfarePlayer = (int32)sPlayerBotMgr->GetAllowMaxWarrfareBotCount();
    
    if (allianceCount + hordeCount >= maxNearPlayer)
        return;
    if (allianceCount + hordeCount >= maxWarrfarePlayer)
        return;
    if (allianceCount + hordeCount >= maxCount)
        return;
	int32 needCount = 0;
	//int32 needTargetCount = 0;
	if (m_TriggerTeam == TEAM_ALLIANCE)
	{
		int32 gap = int32(float(hordeCount) * 0.2f);
		if (gap < 5) gap = 5;
		needCount = allianceCount - (hordeCount + gap);
	}
	else if (m_TriggerTeam == TEAM_HORDE)
	{
		int32 gap = int32(float(allianceCount) * 0.2f);
		if (gap < 3) gap = 3;
		needCount = hordeCount - (allianceCount + gap);
	}
    //printf("ProcessWarrfare needCount=%d;allianceCount=%d;hordeCount=%d;maxWarrfarePlayer=%d,maxCount=%d \n", needCount, allianceCount, hordeCount, maxWarrfarePlayer, maxCount);
	if (needCount < 0)
	{
		if (m_TriggerTeam == TEAM_ALLIANCE && allianceCount < maxCount)
			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_ALLIANCE);
		else if (m_TriggerTeam == TEAM_HORDE && hordeCount < maxCount)
			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_HORDE);
	}
	else
	{
		if (m_TriggerTeam == TEAM_ALLIANCE && hordeCount < maxCount)
			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_HORDE);
		else if (m_TriggerTeam == TEAM_HORDE && allianceCount < maxCount)
			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_ALLIANCE);
	}
	//if (FieldWarfare::AID_TARGET_TEAM)
	//{
	//	if (needCount > -4)
	//	{
	//		if (m_TriggerTeam == TEAM_ALLIANCE && nearHorde < maxCount)
	//			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_HORDE);
	//		else if (m_TriggerTeam == TEAM_HORDE && nearAlliance < maxCount)
	//			AddPlayerBotToFieldWarfare(targetPlayer, TEAM_ALLIANCE);
	//	}
	//}
}

void FieldWarfare::ProcessEpilog(Player* targetPlayer)
{
	NearPlayerList playersNearby;
	targetPlayer->GetPlayerListInGrid(playersNearby, BOTAI_FIELDTELEPORT_DISTANCE * 5.0f);
	//int32 nearAlliance = 0;
	//int32 nearHorde = 0;
	TeamId weaknessTeam = GetWeaknessTeam();
	int32 talkRate = irand(0, playersNearby.size());
	for (Player* nearPlayer : playersNearby)
	{
		--talkRate;
		//if (nearPlayer->GetTeamId() == TEAM_ALLIANCE)
		//	++nearAlliance;
		//else if (nearPlayer->GetTeamId() == TEAM_HORDE)
		//	++nearHorde;
		if (nearPlayer->IsAlive() && nearPlayer->IsPlayerBot())
		{
			if (talkRate < 1)
			{
				if (nearPlayer->GetTeamId() == weaknessTeam || urand(0, 99) > 75)
				{
					talkRate = playersNearby.size();
					sPlayerBotTalkMgr->WarfareActingTalk((nearPlayer->GetTeamId() == weaknessTeam) ? 2 : 1, nearPlayer);
				}
			}
			if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(nearPlayer->GetAI()))
			{
				if (nearPlayer->GetTeamId() == weaknessTeam)
				{
					pFieldAI->SetDrivingPVP(false);
					/*if (!pFieldAI->HasCruxMovement())
						pFieldAI->SetCruxMovement(GetEvadePosition(targetPlayer, nearPlayer));*/
				}
				pFieldAI->SetWarfareTarget(NULL);
			}
		}
	}
}

void FieldWarfare::OverFieldActing()
{
	Player* targetPlayer = ObjectAccessor::FindPlayer(m_WarfareTarget);
	if (!targetPlayer)
		return;
	m_WarfareTrigger = ObjectGuid::Empty;
	m_WarfareTarget = ObjectGuid::Empty;
	m_TriggerTimer = 0;
#ifdef _DEBUG
	sWorld->SendGlobalText("Warfare end, clear player.", NULL);
#endif

	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (itSession->second->PlayerLoading() || !itSession->second->IsBotSession())
			continue;
		Player* player = itSession->second->GetPlayer();
		if (!player || player->GetGroup())
			continue;
		if (m_WarfareMapID != player->GetMapId() || player->InBattleground() || player->InBattlegroundQueue())
			continue;
		//if (targetPlayer->GetDistance(player) > BOTAI_FIELDTELEPORT_DISTANCE * 5.0f)
		//	continue;
		if (player->GetSelectedPlayer())
			player->SetSelection(ObjectGuid::Empty);
		player->CombatStop(true);
		//Position homePosition = Position(player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
		if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI()))
		{
			pFieldAI->SetDrivingPVP(false);
			pFieldAI->SetWarfareTarget(NULL);
			//pFieldAI->SetTeleport(player->m_homebindMapId, homePosition);
			sPlayerBotMgr->PlayerBotLogout(itSession->second->GetAccountId());
		}
	}
}

void FieldWarfare::AddPlayerBotToFieldWarfare(Player* target, TeamId upTeam)
{
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (!itSession->second->IsBotSession())
			continue;
		WorldSession* pSession = (WorldSession*)itSession->second;
		if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
			continue;
		Player* player = pSession->GetPlayer();
		if (!player)
		{
			sPlayerBotMgr->AddNewPlayerBot(upTeam, CLASS_NONE, 1);
			return;
		}
		else
		{
			if (!player->IsInWorld() || !player->IsSettingFinish() || player->GetTeamId() != upTeam)
				continue;
			if (player->InBattleground() || player->InBattlegroundQueue() || player->InArena() || player->GetGroup() || player->isUsingLfg())
				continue;
			if (!player->IsAlive() || !FieldBotMgr::MatchTeleportCondition(target, player))
				continue;
			TeleportToTargetVisible(player, target);
			return;
		}
	}
}

void FieldWarfare::TeleportToTargetVisible(Player* pBot, Player* pTarget)
{
	if (!pBot || !pTarget)
		return;
	BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(pBot->GetAI());
	if (!pFieldAI)
		return;
	int8 minLevel = (pTarget->getLevel() <= 4) ? 1 : pTarget->getLevel() - 3;
	int8 maxLevel = (pTarget->getLevel() >= 105) ? 110 : pTarget->getLevel() + 5;
	if (pBot->getLevel() < minLevel || pBot->getLevel() > maxLevel)
	{
		PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pBot->GetSession());
		if (!pSession || pSession->HasSchedules() || pSession->IsAccountBotSession())
			return;
		BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
		schedule2.parameter1 = minLevel;
		schedule2.parameter2 = maxLevel;
		schedule2.parameter3 = pBot->FindTalentType() + 1;
		pSession->PushScheduleToQueue(schedule2);
	}

	float distX = pTarget->GetPositionX();
	float distY = pTarget->GetPositionY();
	float distZ = pTarget->GetPositionZ();
	uint32 rndCount = 0;
	do
	{
		++rndCount;
		if (rndCount > 20)
		{
			distX = pTarget->GetPositionX();
			distY = pTarget->GetPositionY();
			distZ = pTarget->GetPositionZ();
			break;
		}
		float targetAngle = frand(0, float(M_PI) * 2.0f);
		distX = pTarget->GetPositionX() + (BOTAI_FIELDTELEPORT_DISTANCE * 1.7f) * std::cosf(targetAngle);
		distY = pTarget->GetPositionY() + (BOTAI_FIELDTELEPORT_DISTANCE * 1.7f) * std::sinf(targetAngle);
		distZ = pTarget->GetPositionZ();
		distZ = pTarget->GetMap()->GetHeight(pTarget->GetPhaseShift(), distX, distY, distZ);
	} while (!MapManager::IsValidMapCoord(pTarget->GetMapId(), distX, distY, distZ, pTarget->GetOrientation()));
	Position resultPos(distX, distY, distZ, pTarget->GetOrientation());

	pBot->CombatStop(true);
	pBot->SetSelection(ObjectGuid::Empty);
	pFieldAI->SetWarfareTarget(pTarget);
	pFieldAI->SetTeleport(pTarget->GetMapId(), resultPos);
}

TeamId FieldWarfare::GetWeaknessTeam()
{
	if (m_AttackTeamKill < m_TriggerTeamKill)
	{
		if (m_TriggerTeam == TEAM_ALLIANCE)
			return TEAM_HORDE;
		else
			return TEAM_ALLIANCE;
	}
	return m_TriggerTeam;
}

Position FieldWarfare::GetEvadePosition(Player* centerPlayer, Player* evadePlayer)
{
	float onceAngle = float(M_PI) * 2.0f / 8.0f;
	Position targetPos = evadePlayer->GetPosition();
	float maxDist = 0.0f;
	for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
	{
		float distX = evadePlayer->GetPositionX() + (BOTAI_FIELDTELEPORT_DISTANCE * 4) * std::cosf(angle);
		float distY = evadePlayer->GetPositionY() + (BOTAI_FIELDTELEPORT_DISTANCE * 4) * std::sinf(angle);
		float distZ = evadePlayer->GetPositionZ();
		distZ = evadePlayer->GetMap()->GetHeight(evadePlayer->GetPhaseShift(), distX, distY, distZ);
		Position pos(distX, distY, distZ, angle);
		if (!MapManager::IsValidMapCoord(evadePlayer->GetMapId(), distX, distY, distZ, angle))
			pos = evadePlayer->GetFirstCollisionPosition((BOTAI_FIELDTELEPORT_DISTANCE * 4), angle);
		float dist = centerPlayer->GetDistance(pos);
		if (dist > maxDist)
		{
			maxDist = dist;
			targetPos = pos;
		}
	}
	return targetPos;
}

int32 FieldWarfare::GetWarfareMaxCount()
{
	int32 baseCount = 20;
	for (uint32 i = 1; i < FieldBotMgr::FIELDWARFARE_SIZE; i++)
	{
		baseCount *= 2;
	}
	return baseCount;
}

void FieldWarfare::UpdateWarfareDurableTimer()
{
	uint32 rndTime = urand(15, 18);
	switch (FieldBotMgr::FIELDWARFARE_SIZE)
	{
	case 1:
		m_WarfareDurable = 60000 * rndTime;
		break;
	case 2:
		m_WarfareDurable = 90000 * rndTime;
		break;
	case 3:
		m_WarfareDurable = 120000 * rndTime;
		break;
	default:
		m_WarfareDurable = 0;
	}
}

FieldBotMgr::FieldBotMgr() :
m_WorldPoster(),
m_WorkTick(getMSTime()),
m_WorkPlayerGUID(ObjectGuid::Empty),
m_MaxNearPlayer(4),
m_ProbabilityWarfare(35),
m_FieldActing(NULL)
{

}

FieldBotMgr::~FieldBotMgr()
{
}

FieldBotMgr* FieldBotMgr::instance()
{
	static FieldBotMgr instance;
	return &instance;
}

void FieldBotMgr::StartStoryTalk()
{
	if (HasActing())
		return;
	m_FieldActing = new FieldStory();
}

bool FieldBotMgr::MatchTeleportCondition(Player* p1, Player* p2)
{
	if (!p1 || !p2)
		return false;
	if (!FieldBotMgr::CanExistTargetZone(p1, p2))
		return false;
	AreaTableEntry const* zone = sAreaTableStore.LookupEntry(p1->GetAreaId());
	if (zone)
	{
		if (zone->ID == 876) // is gm island
			return false;
		if ((zone->Flags[0] & AREA_FLAG_TOWN) && (zone->Flags[0] & AREA_FLAG_CAPITAL) && (zone->Flags[0] & AREA_FLAG_SLAVE_CAPITAL2) && (zone->Flags[0] & AREA_FLAG_SLAVE_CAPITAL))
		{
			if (!p1->pvpInfo.IsInHostileArea && p1->GetTeamId() != p2->GetTeamId())
				return false;
		}
	}

	if (p1->getLevel() < 20 && p1->GetTeamId() != p2->GetTeamId())
		return false;
	WorldSession* pSession = p2->GetSession();
	if (!pSession || pSession->HasSchedules() || p2->GetGroup() || p2->isUsingLfg())
		return false;
	if (p1->GetMap() != p2->GetMap())
		return true;
	if (p1->GetDistance(p2->GetPosition()) > BOTAI_FIELDTELEPORT_DISTANCE * 3.0f)
		return true;
	return false;
}

void FieldBotMgr::Update(ObjectGuid workGUID)
{
	uint32 currentWorkTick = getMSTime();
	if (m_WorkTick + 5000 > currentWorkTick)
		return;
	m_WorkTick = currentWorkTick;
#ifdef INCOMPLETE_BOT
	m_WorldPoster.SendOnceGlobalPoster();
#endif // INCOMPLETE_BOT
	if (m_WorkPlayerGUID == ObjectGuid::Empty || m_WorkPlayerGUID != workGUID)
		return;


	if (m_FieldActing)
	{
		m_FieldActing->Update();
		if (m_FieldActing->FieldActingIsOver())
		{
			m_FieldActing->OverFieldActing();
			delete m_FieldActing;
			m_FieldActing = NULL;
		}
	}
	else
	{
		//UpdateInitOnline();
		UpdateTeleport();
		RandomPlayerBotNormalTalk();
	}
}

PLAYER_LIST FieldBotMgr::GetAllRealPlayer()
{
	PLAYER_LIST realPlayers;
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (itSession->second->IsBotSession())
			continue;
		WorldSession* pSession = itSession->second;
		if (!pSession || pSession->PlayerLoading())
			continue;
		Player* player = pSession->GetPlayer();
		if (!player || !player->IsInWorld() || !player->IsSettingFinish())
			continue;
		realPlayers.push_back(player);
	}
	return realPlayers;
}

FIELDAI_LIST FieldBotMgr::GetAllFieldBotPlayer(TeamId team)
{
	FIELDAI_LIST fieldAIs;
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (!itSession->second->IsBotSession())
			continue;
		PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
		if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
			continue;
		Player* player = pSession->GetPlayer();
		if (!player || !player->IsInWorld() || !player->IsSettingFinish())
			continue;
		if (team != TEAM_NEUTRAL)
		{
			if (player->GetTeamId() != team)
				continue;
		}
		BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI());
		if (!pFieldAI)
			continue;
		fieldAIs.push_back(pFieldAI);
	}
	return fieldAIs;
}

void FieldBotMgr::TeleportToTargetVisible(BotFieldAI* pFieldAI, Player* pTarget)
{
	if (!pFieldAI || !pTarget || pFieldAI->HasTeleport() || !pFieldAI->GetAIPayer()->IsSettingFinish())
		return;
	bool needResetAI = false;
	int8 levelGap = (int8)pFieldAI->GetAIPayer()->getLevel() - (int8)pTarget->getLevel();
	if (levelGap < 0) levelGap *= (-1);
	if (levelGap > 2)
	{
		PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pFieldAI->GetAIPayer()->GetSession());
		if (!pSession || pSession->HasSchedules() || pSession->IsAccountBotSession())
			return;
		BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
		schedule2.parameter1 = pTarget->getLevel();
		schedule2.parameter2 = pTarget->getLevel();
		schedule2.parameter3 = pFieldAI->GetAIPayer()->FindTalentType() + 1;
		pSession->PushScheduleToQueue(schedule2);
		needResetAI = true;
	}

	float distX = pTarget->GetPositionX();
	float distY = pTarget->GetPositionY();
	float distZ = pTarget->GetPositionZ();
	AreaTableEntry const* zone = sAreaTableStore.LookupEntry(pTarget->GetAreaId());
	if (zone && (zone->Flags[0] & AREA_FLAG_TOWN) && (zone->Flags[0] & AREA_FLAG_CAPITAL) && (zone->Flags[0] & AREA_FLAG_SLAVE_CAPITAL2) && (zone->Flags[0] & AREA_FLAG_SLAVE_CAPITAL))
	{
		float onceAngle = float(M_PI) * 2.0f / 16.0f;
		std::vector<Position> allPosition;
		float farDist = BOTAI_FIELDTELEPORT_DISTANCE * 1.2f;
		for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
		{
			Position pos = pTarget->GetFirstCollisionPosition(farDist, angle);
			float posDist = pTarget->GetDistance(pos);
			if (posDist < farDist * 0.25f)
				continue;
			if (!pTarget->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
				continue;
			pos.m_positionZ += 0.1f;
			allPosition.push_back(pos);
		}
		if (!allPosition.empty())
		{
			Position& targetPos = allPosition[urand(0, allPosition.size() - 1)];
			distX = targetPos.GetPositionX();
			distY = targetPos.GetPositionY();
			distZ = targetPos.GetPositionZ();
		}
	}
	else
	{
		uint32 maxSearch = 0;
		do
		{
			++maxSearch;
			if (maxSearch > 30)
			{
				distX = pTarget->GetPositionX();
				distY = pTarget->GetPositionY();
				distZ = pTarget->GetPositionZ();
				break;
			}
			float targetAngle = frand(0, float(M_PI) * 2.0f);
			distX = pTarget->GetPositionX() + (BOTAI_FIELDTELEPORT_DISTANCE * 1.2f) * std::cosf(targetAngle);
			distY = pTarget->GetPositionY() + (BOTAI_FIELDTELEPORT_DISTANCE * 1.2f) * std::sinf(targetAngle);
			distZ = pTarget->GetPositionZ();
			distZ = pTarget->GetMap()->GetHeight(pTarget->GetPhaseShift(), distX, distY, distZ);
		} while (!MapManager::IsValidMapCoord(pTarget->GetMapId(), distX, distY, distZ, pTarget->GetOrientation()) ||
			!IsVaildVisiblePos(pTarget, distX, distY, distZ));
	}
	Position resultPos(distX, distY, distZ, pTarget->GetOrientation());

	pFieldAI->GetAIPayer()->CombatStop(true);
	pFieldAI->GetAIPayer()->SetSelection(ObjectGuid::Empty);
	pFieldAI->SetTeleport(pTarget->GetMapId(), resultPos);
	if (needResetAI)
		pFieldAI->SetResetAI();
}

void FieldBotMgr::UpdateInitOnline()
{
	if (FieldBotMgr::FIELDWARFARE_SIZE <= 0)
		return;
	int32 maxNearPlayer =  GetMaxNearPlayer();
	int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
	int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
	if (hordeCount > maxNearPlayer)
		hordeCount = maxNearPlayer;
	if (allianceCount > maxNearPlayer)
		allianceCount = maxNearPlayer;
	int32 needAlliance = maxNearPlayer - allianceCount;
	int32 needHorde = maxNearPlayer - hordeCount;

    //printf("FieldBotMgr GetMaxNearPlayer %d;allianceCount=%d;hordeCount=%d;needAlliance=%d;needHorde=%d\n", maxNearPlayer, allianceCount, hordeCount, needAlliance, needHorde);

	if (allianceCount <= hordeCount && needAlliance > 0)
		sPlayerBotMgr->AddNewPlayerBot(TEAM_ALLIANCE, CLASS_NONE, 1);
	else if (hordeCount < allianceCount && needHorde > 0)
		sPlayerBotMgr->AddNewPlayerBot(TEAM_HORDE, CLASS_NONE, 1);
}

bool FieldBotMgr::IsVaildVisiblePos(Player* pTarget, float x, float y, float z)
{
	uint32 sessionID = pTarget->GetSession()->GetAccountId();
	PathParameter pathParam = PathParameter(sessionID, pTarget);
	pathParam.targetPosX = x;
	pathParam.targetPosY = y;
	pathParam.targetPosZ = z;
	pathParam.offset = 0;

	Pathfinding path(&pathParam, NULL, NULL);
	float posx = pathParam.targetPosX;
	float posy = pathParam.targetPosY;
	float posz = pathParam.targetPosZ;
	path.UpdateAllowedPositionZ(posx, posy, posz);
	bool result = path.CalculatePath(posx, posy, posz);
	if (!result || (path.GetPathType() & PATHFIND_NOPATH))
	{
		return false;
	}
	return true;
}

void FieldBotMgr::UpdateTeleport()
{
	if (FieldBotMgr::FIELDWARFARE_SIZE <= 0)
		return;
	Player* workPlayer = ObjectAccessor::FindPlayer(m_WorkPlayerGUID);
	if (!workPlayer)
		return;
	if (!workPlayer->IsInWorld() || workPlayer->IsFlying() || workPlayer->InBattleground() || workPlayer->InArena() || workPlayer->GetMap()->IsDungeon())
		return;
	NearPlayerList playersNearby, needLeavePlayers;
	workPlayer->GetPlayerListInGrid(playersNearby, BOTAI_FIELDTELEPORT_DISTANCE * 3.0f);
	int32 nearAlliance = 0;
	int32 nearHorde = 0;
	for (Player* nearPlayer : playersNearby)
	{
		if (nearPlayer->GetTeamId() == TEAM_ALLIANCE)
			++nearAlliance;
		else if (nearPlayer->GetTeamId() == TEAM_HORDE)
			++nearHorde;
		if (workPlayer != nearPlayer && nearPlayer->IsPlayerBot() &&
			!nearPlayer->GetGroup() && !FieldBotMgr::CanExistTargetZone(workPlayer, nearPlayer))
			needLeavePlayers.push_back(nearPlayer);
		else if (nearPlayer->IsPlayerBot() && nearPlayer->isUsingLfg())
			needLeavePlayers.push_back(nearPlayer);
	}
	//for (Player* leavePlayer : needLeavePlayers)
	//{
	//	/*Position homePosition = Position(leavePlayer->m_homebindX, leavePlayer->m_homebindY, leavePlayer->m_homebindZ, leavePlayer->GetOrientation());
	//	if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(leavePlayer->GetAI()))
	//		pFieldAI->SetTeleport(leavePlayer->m_homebindMapId, homePosition);*/
	//}

    int maxnearplayer = sConfigMgr->GetIntDefault("PBot.MaxNearPlayer", 10);
    int savelevel = sConfigMgr->GetIntDefault("PBot.SaveLevel", 20);
    //printf("safe level = %d\n", savelevel);
    if (workPlayer->getLevel() < savelevel)
    {
        if (workPlayer->GetTeamId() == TEAM_ALLIANCE)
            nearHorde = 1000;
        else if (workPlayer->GetTeamId() == TEAM_HORDE)
            nearAlliance = 1000;
    }

	if (maxnearplayer > nearAlliance)
	{
		FIELDAI_LIST allianceBots = FieldBotMgr::GetAllFieldBotPlayer(TEAM_ALLIANCE);
		while (!allianceBots.empty())
		{
			BotFieldAI* pFieldAI = (*allianceBots.begin());
			allianceBots.erase(allianceBots.begin());
			if (pFieldAI->HasTeleport())
				continue;
			if (FieldBotMgr::MatchTeleportCondition(workPlayer, pFieldAI->GetAIPayer()))
			{
				TeleportToTargetVisible(pFieldAI, workPlayer);
				break;
			}
		}
	}
	if (maxnearplayer > nearHorde)
	{
		FIELDAI_LIST hordeBots = FieldBotMgr::GetAllFieldBotPlayer(TEAM_HORDE);
		while (!hordeBots.empty())
		{
			BotFieldAI* pFieldAI = (*hordeBots.begin());
			hordeBots.erase(hordeBots.begin());
			if (pFieldAI->HasTeleport())
				continue;
			if (FieldBotMgr::MatchTeleportCondition(workPlayer, pFieldAI->GetAIPayer()))
			{
				TeleportToTargetVisible(pFieldAI, workPlayer);
				break;
			}
		}
	}
}

void FieldBotMgr::RandomPlayerBotNormalTalk()
{
	if (HasActing())
		return;
	std::vector<Player*> rndPlayers;
	const SessionMap& allSession = sWorld->GetAllSessions();
	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
	{
		if (itSession->second->PlayerLoading() || !itSession->second->IsBotSession())
			continue;
		Player* player = itSession->second->GetPlayer();
		if (!player || !player->IsInWorld() || player->InBattleground() || player->GetGroup())
			continue;
		rndPlayers.push_back(player);
	}
	if (rndPlayers.empty())
		return;
	Player* talkPlayer = rndPlayers[urand(0, rndPlayers.size() - 1)];
	sPlayerBotTryTalk(TTT_Normal, 0, talkPlayer);
}

int32 FieldBotMgr::GetMaxNearPlayer()
{
    return sConfigMgr->GetIntDefault("PBot.MaxNearPlayer", 10);
#ifdef INCOMPLETE_BOT
	return 4;
#endif
	if(FieldBotMgr::FIELDWARFARE_SIZE <= 0)
	{
		return 0;
	}
	else if (FieldBotMgr::FIELDWARFARE_SIZE == 1)
	{
		return 4;
	}
	else if (FieldBotMgr::FIELDWARFARE_SIZE == 2)
	{
		return 12;
	}
	else
	{
		return 20;
	}
	return 0;
}

bool FieldBotMgr::CanExistTargetZone(Player* player, Player* target)
{
	if (!player || !target)
		return false;
	if (player->GetTeamId() == target->GetTeamId())
		return true;
	if (player->pvpInfo.IsInNoPvPArea)
		return false;
	return true;
}

void FieldBotMgr::OnRealPlayerLogin(Player* player)
{
	if (m_WorkPlayerGUID == ObjectGuid::Empty && player)
	{
		m_WorkPlayerGUID = player->GetGUID();
	}
}

void FieldBotMgr::OnRealPlayerLogout(ObjectGuid guid)
{
	if (m_WorkPlayerGUID == guid)
	{
		m_WorkPlayerGUID = ObjectGuid::Empty;
	}
}

bool FieldBotMgr::CanTriggerWarfare(Player* pAttacker, Player* deather)
{
	uint32 rndTrigger = urand(0, 99);
	if (rndTrigger >= m_ProbabilityWarfare)
		return false;
	if (FieldBotMgr::FIELDWARFARE_SIZE <= 0 || deather->getLevel() < 40)
		return false;
	if (HasActing() && m_FieldActing->MatchActingType(ACTING_WARFARE))
		return false;
	if (pAttacker->pvpInfo.IsInNoPvPArea || deather->pvpInfo.IsInNoPvPArea)
		return false;
	if (pAttacker == deather || !deather->IsPlayerBot() || pAttacker->GetTeamId() == deather->GetTeamId())
		return false;
	if (pAttacker->IsPlayerBot())
	{
		NearPlayerList playersNearby;
		deather->GetPlayerListInGrid(playersNearby, BOTAI_SEARCH_RANGE);
		bool hasTargetDeather = false;
		for (Player* player : playersNearby)
		{
			if (player->GetSelectedPlayer() != deather || player->IsPlayerBot())
				continue;
			if (player->GetTeamId() == deather->GetTeamId())
				continue;
			hasTargetDeather = true;
			break;
		}
		if (!hasTargetDeather)
			return false;
	}
	return true;
}

void FieldBotMgr::KillFieldPlayer(Player* pAttacker, Player* deather)
{
#ifndef INCOMPLETE_BOT
	if (!pAttacker || !deather || pAttacker->InBattleground() || deather->InBattleground())
		return;
	if (HasActing())
	{
		if (FieldWarfare* warfare = GetWarfareActing())
		{
			if (!pAttacker->InBattleground() && !deather->InBattleground() && pAttacker != deather)
				warfare->UpdateWarfareKill(deather);
			return;
		}
		else if (CanTriggerWarfare(pAttacker, deather))
		{
			//if (HasActing())
			{
				m_FieldActing->OverFieldActing();
				delete m_FieldActing;
				m_FieldActing = NULL;
			}
			BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(deather->GetAI());
			if (!pFieldAI)
				return;
			m_FieldActing = new FieldWarfare(deather, pAttacker);
			return;
		}
	}
	else if (CanTriggerWarfare(pAttacker, deather))
	{
		BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(deather->GetAI());
		if (!pFieldAI)
			return;
		m_FieldActing = new FieldWarfare(deather, pAttacker);
		return;
	}
#endif
}

FieldWarfare* FieldBotMgr::GetWarfareActing()
{
	if (ExistWarfare())
		return reinterpret_cast<FieldWarfare*>(m_FieldActing);
	return NULL;
}
