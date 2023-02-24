//
//#include "PlayerBotSession.h"
//#include "Player.h"
//#include "BattlegroundMgr.h"
//#include "BotAI.h"
//#include "BotGroupAI.h"
//#include "BotFieldAI.h"
//#include "LFGMgr.h"
//#include "DB2Stores.h"
//#include "Packets/AllPackets.h"
//#include "LFGPacketsCommon.h"
//#include <Petitions\PetitionMgr.h>
//PlayerBotSession::PlayerBotSession(uint32 id, std::string &name, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter) :
//WorldSession(id, std::move(name), 0, 0, sec, expansion, mute_time, "bot", locale, recruiter, isARecruiter),
//m_LastCastTime(CAST_SCHEDULE_TICK),
//m_NoWorldTick(0),
//m_AccountBot(false),
//m_PlayOnline(false)
//{
//
//}
//
//bool PlayerBotSession::IsBotSession()
//{
//	return true;
//}
//
//bool PlayerBotSession::HasBGSchedule()
//{
//	for (BotSchedules::iterator itSc = m_Schedules.begin(); itSc != m_Schedules.end(); itSc++)
//	{
//		BotGlobleScheduleType bgsType = (*itSc).bbgType;
//		if (bgsType == BGSType_EnterBG || bgsType == BGSType_InBGQueue ||
//			bgsType == BGSType_LeaveBG || bgsType == BGSType_OutBGQueue ||
//			bgsType == BGSType_EnterAA || bgsType == BGSType_InAAQueue ||
//			bgsType == BGSType_LeaveAA || bgsType == BGSType_OutAAQueue)
//			return true;
//	}
//	return false;
//}
//
//bool PlayerBotSession::Update(uint32 diff, PacketFilter& updater)
//{
//	bool updateResult = WorldSession::Update(diff, updater);
//	ProcessNoWorld(diff);
//	m_LastCastTime -= diff;
//	if (m_LastCastTime <= 0)
//	{
//		//std::lock_guard<std::mutex> lock(m_optQueueLock);
//		CastSchedule(CAST_SCHEDULE_TICK);
//		m_LastCastTime = CAST_SCHEDULE_TICK;
//	}
//	return updateResult;
//}
//
//void PlayerBotSession::PushScheduleToQueue(BotGlobleSchedule& schedule)
//{
//	//std::lock_guard<std::mutex> lock(m_optQueueLock);
//	for (BotSchedules::iterator itSc = m_Schedules.begin(); itSc != m_Schedules.end(); itSc++)
//	{
//		if ((*itSc).bbgType == schedule.bbgType)
//			return;
//	}
//	if (schedule.bbgType == BGSType_DelayLevelup)
//	{
//		if (PlayerLoading())
//			return;
//		if (Player* player = GetPlayer())
//		{
//			if (!player->IsSettingFinish())
//				return;
//		}
//		else
//			return;
//	}
//
//	if (schedule.bbgType == BotGlobleScheduleType::BGSType_OutBGQueue)
//	{
//		RemoveScheduleByType(BotGlobleScheduleType::BGSType_InBGQueue);
//		RemoveScheduleByType(BotGlobleScheduleType::BGSType_EnterBG);
//	}
//	if (schedule.bbgType == BotGlobleScheduleType::BGSType_OutAAQueue)
//	{
//		RemoveScheduleByType(BotGlobleScheduleType::BGSType_InAAQueue);
//		RemoveScheduleByType(BotGlobleScheduleType::BGSType_EnterAA);
//	}
//	m_Schedules.push_back(schedule);
//}
//
//void PlayerBotSession::RemoveScheduleByType(BotGlobleScheduleType eType)
//{
//	for (BotSchedules::iterator itSc = m_Schedules.begin(); itSc != m_Schedules.end(); itSc++)
//	{
//		if ((*itSc).bbgType == eType)
//		{
//			m_Schedules.erase(itSc);
//			return;
//		}
//	}
//}
//
//bool PlayerBotSession::HasScheduleByType(BotGlobleScheduleType eType)
//{
//	for (BotSchedules::iterator itSc = m_Schedules.begin(); itSc != m_Schedules.end(); itSc++)
//	{
//		if ((*itSc).bbgType == eType)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//bool PlayerBotSession::HasSchedules()
//{
//	return m_Schedules.size() > 0;
//}
//
//bool PlayerBotSession::IsAccountBotSession()
//{
//	return m_AccountBot;
//}
//
//bool PlayerBotSession::PlayerOnline(BotGlobleSchedule & schedule)
//{
//    if (schedule.parameter1 <= 0)
//        return false;
//    if (PlayerLoading())
//        return false;
//    if (GetPlayer())
//        return false;
//    if (HasOnline())
//        return false;
//    PlayerBotBaseInfo* pInfo = sPlayerBotMgr->GetPlayerBotAccountInfo(GetAccountId());
//    if (!pInfo)
//    {
//        pInfo = sPlayerBotMgr->GetAccountBotAccountInfo(GetAccountId());
//        if (!pInfo)
//        {
//            ClearAllSchedule();
//            return false;
//        }
//    }
//
//    TeamId team = TEAM_ALLIANCE;
//    if (schedule.parameter1 > 1)
//        team = TEAM_HORDE;
//
//    PlayerBotCharBaseInfo& charInfo = (schedule.parameter2 == 0) ? pInfo->GetRandomCharacterByFuction(team) : pInfo->GetCharacter(team, schedule.parameter2);
//    if (charInfo.guid == 0)
//        return false;
//
//    WorldPacket packet;
//    WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
//    sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
//    HandlePlayerLoginOpcode(sPacket);
//    HandleContinuePlayerLogin();
//    SetPlayerOnline();
//    return true;
//}
//
//bool PlayerBotSession::HasOnline()
//{
//    return m_PlayOnline;
//}
//
//uint8 PlayerBotSession::GetRandomTalent(Player * player)
//{
//    if (player)
//    {
//        switch (player->getClass())
//        {
//        case CLASS_WARRIOR:
//        case CLASS_PALADIN:
//        case CLASS_HUNTER:
//        case CLASS_ROGUE:
//        case CLASS_PRIEST:
//        case CLASS_DEATH_KNIGHT:
//        case CLASS_SHAMAN:
//        case CLASS_MAGE:
//        case CLASS_WARLOCK:
//        case CLASS_MONK:
//            return urand(0, 2);
//            break;
//        case CLASS_DRUID:
//            return urand(0, 3);
//            break;
//        case CLASS_DEMON_HUNTER:
//            return urand(0, 1);
//            break;
//        default:
//            break;
//        }
//    }
//    return urand(0, 2);
//}
//
//bool PlayerBotSession::PlayerIsReady()
//{
//	Player* player = GetPlayer();
//	if (!player)
//		return true;
//	if (!player->IsSettingFinish())
//		return false;
//	BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI());
//	if (!pFieldAI)
//		return true;
//	if (pFieldAI->HasTeleport())
//		return false;
//
//	return true;
//}
//
//void PlayerBotSession::ProcessNoWorld(uint32 diff)
//{
//	if (PlayerLoading())
//		return;
//	Player* player = GetPlayer();
//	if (!player)
//		return;
//
//	if (player->IsInWorld())
//	{
//		m_NoWorldTick = 0;
//		return;
//	}
//	if (m_NoWorldTick == 0)
//	{
//		m_NoWorldTick = 2000;
//		return;
//	}
//	m_NoWorldTick -= int32(diff);
//	if (m_NoWorldTick > 0)
//		return;
//	if (BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(player->GetAI()))
//	{
//		if (pGroupAI->HasTeleport())
//			pGroupAI->UpdateTeleport(diff);
//		else
//			pGroupAI->SetTeleportToMaster();
//		m_NoWorldTick = 500;
//	}
//	else if (BotBGAI* pGroupAI = dynamic_cast<BotBGAI*>(player->GetAI()))
//	{
//		if (player->InBattleground())
//		{
//			PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_FIELD, true);
//            WorldPacket packet;
//            WorldPackets::Battleground::BattlefieldLeave sPacket(std::move(packet));
//			HandleBattlefieldLeaveOpcode(sPacket);
//		}
//		HandleMoveWorldportAck();
//		m_NoWorldTick = 500;
//	}
//	else// if (BotFieldAI* pGroupAI = dynamic_cast<BotFieldAI*>(player->GetAI()))
//	{
//		HandleMoveWorldportAck();
//		m_NoWorldTick = 500;
//	}
//}
//
//void PlayerBotSession::CastSchedule(uint32 diff)
//{
//	if (m_Schedules.empty())
//		return;
//	bool result = false;
//	BotGlobleSchedule& schedule = *m_Schedules.begin();
//	schedule.processTick += diff;
//	if (schedule.processTick > 60000 * 3)
//	{
//		m_Schedules.erase(m_Schedules.begin());
//		return;
//	}
//	if (!PlayerIsReady())
//		return;
//	switch (schedule.bbgType)
//	{
//	case BGSType_Online:
//		result = ProcessOnline(schedule);
//		break;
//	case BGSType_Online_GUID:
//		result = ProcessOnlineByGUID(schedule);
//		break;
//	case BGSType_Offline:
//		result = ProcessOffline(schedule);
//		break;
//	case BGSType_Settting:
//		result = ProcessSetting(schedule);
//		break;
//	case BGSType_InBGQueue:
//		result = ProcessInBGQueue(schedule);
//		break;
//	case BGSType_OutBGQueue:
//		result = ProcessOutBGQueue(schedule);
//		break;
//	case BGSType_EnterBG:
//		result = ProcessEnterBG(schedule);
//		break;
//	case BGSType_LeaveBG:
//		result = ProcessLeaveBG(schedule);
//		break;
//	case BGSType_InAAQueue:
//		result = ProcessInAAQueue(schedule);
//		break;
//	case BGSType_OutAAQueue:
//		result = ProcessOutAAQueue(schedule);
//		break;
//	case BGSType_EnterAA:
//		result = ProcessEnterAA(schedule);
//		break;
//	case BGSType_LeaveAA:
//		result = ProcessLeaveAA(schedule);
//		break;
//	case BGSType_DelayLevelup:
//		result = ProcessDelayLevelup(schedule);
//		break;
//	case BGSType_InLFGQueue:
//		result = ProcessInLFGQueue(schedule);
//		break;
//	case BGSType_OutLFGQueue:
//		result = ProcessOutLFGQueue(schedule);
//		break;
//	case BGSType_AcceptLFGProposal:
//		result = ProcessAcceptLFGProposal(schedule);
//		break;
//	case BGSType_OfferPetitionSign:
//		result = ProcessOfferPetitionSign(schedule);
//		break;
//	default:
//		result = true;
//		break;
//	}
//	if (result)
//	{
//		m_Schedules.erase(m_Schedules.begin());
//	}
//}
//
//bool PlayerBotSession::ProcessOnline(BotGlobleSchedule& schedule)
//{
//	if (schedule.parameter1 <= 0)
//		return true;
//	if (PlayerLoading())
//		return false;
//	if (GetPlayer())
//		return true;
//	PlayerBotBaseInfo* pInfo = sPlayerBotMgr->GetPlayerBotAccountInfo(GetAccountId());
//	if (!pInfo)
//	{
//		pInfo = sPlayerBotMgr->GetAccountBotAccountInfo(GetAccountId());
//		if (!pInfo)
//		{
//			ClearAllSchedule();
//			return false;
//		}
//	}
//
//	TeamId team = TEAM_ALLIANCE;
//	if (schedule.parameter1 > 1)
//        team = TEAM_HORDE;
//
//    PlayerBotCharBaseInfo& charInfo = (schedule.parameter2 == 0) ? pInfo->GetRandomCharacterByFuction(team) : pInfo->GetCharacter(team, schedule.parameter2);//GetRandomCharacterByFuction
//
//	if (charInfo.guid == 0)
//		return true;
//
//    WorldPacket packet;
//    WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
//    sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
//    HandlePlayerLoginOpcode(sPacket);
//    HandleContinuePlayerLogin();
//
//    if (Player* player = GetPlayer())
//    {
//        uint32 curTType = player->FindTalentType();
//
//        BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//        schedule2.parameter1 = player->getLevel();
//        schedule2.parameter2 = player->getLevel();
//        schedule2.parameter3 = curTType + 1;
//
//        PushScheduleToQueue(schedule2);
//    }
//	return false;
//}
//
//bool PlayerBotSession::ProcessOnlineByGUID(BotGlobleSchedule& schedule)
//{
//	if (schedule.parameter1 <= 0)
//		return true;
//	if (PlayerLoading())
//		return false;
//	if (GetPlayer())
//		return true;
//	WorldPacket cmd;
//    WorldPackets::Character::PlayerLogin playerLogin(std::move(cmd));
//    playerLogin.Guid = ObjectGuid::Create<HighGuid::Player>(schedule.parameter1);
//    HandlePlayerLoginOpcode(playerLogin);
//    HandleContinuePlayerLogin();
//
//    if (Player* player = GetPlayer())
//    {
//        uint32 curTType = player->FindTalentType();
//
//        BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//        schedule2.parameter1 = player->getLevel();
//        schedule2.parameter2 = player->getLevel();
//        schedule2.parameter3 = curTType + 1;
//
//        PushScheduleToQueue(schedule2);
//    }
//	return false;
//}
//
//bool PlayerBotSession::ProcessOffline(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//		return true;
//	if (schedule.scheduleState > 0)
//		return false;
//    SetLogoutStartTime(time(NULL) - 18);
//	//LogoutPlayer(false);
//	schedule.scheduleState = 1;
//    m_PlayOnline = false;
//	return false;
//}
//
//bool PlayerBotSession::ProcessSetting(BotGlobleSchedule& schedule)
//{
//	if (schedule.parameter1 <= 0 || schedule.parameter1 > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
//		return true;
//	if (schedule.parameter3 == 0 || schedule.parameter3 > 4)
//		schedule.parameter3 = 5;
//	if (schedule.parameter2 > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
//		schedule.parameter2 = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
//	if (schedule.parameter1 > schedule.parameter2)
//		schedule.parameter2 = schedule.parameter1;
//
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld() || !player->IsSettingFinish())
//		return false;
//	if (schedule.scheduleState != 0)
//		return true;
//
//   /* if (schedule.parameter4 == 0 || schedule.parameter4 == 2)
//        player->SetUpdateEquipStaute(true);
//    else
//        player->SetUpdateEquipStaute(false);*/ // TO DO THOR
//
//    //todo47 talent
//
//	uint32 flushTalent = (schedule.parameter3 > 0 && schedule.parameter3 <= 4) ? schedule.parameter3 - 1 : 4;
//    if (flushTalent == 4)
//        flushTalent = GetRandomTalent(player);
//
//	player->ResetPlayerToLevel(urand(schedule.parameter1, schedule.parameter2), flushTalent);
//	schedule.scheduleState = 1;
//	return false;
//}
//
//bool PlayerBotSession::ProcessInBGQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld())
//		return false;
//	if (player->InBattlegroundQueue())
//		return true;
//	if (player->HasAura(26013) || player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() || player->IsInCombat())
//	{
//		ClearAllSchedule();
//		return false;
//	}
//
//	Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(schedule.parameter1));
//	if (!bg)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
//	if (!bracketEntry)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//
//    WorldPacket packet;
//    WorldPackets::Battleground::BattlemasterJoin sPacket(std::move(packet));
//   // sPacket.QueueID = schedule.parameter1;
//    HandleBattlemasterJoinOpcode(sPacket);
//	return false;
//}
//
//bool PlayerBotSession::ProcessOutBGQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld() || player->InBattleground() || player->InArena() || !player->InBattlegroundQueue() || player->GetMap()->IsDungeon())
//		return true;
//
//    WorldPacket packet;
//    WorldPackets::Battleground::BattlefieldPort sPacket(std::move(packet));
//    sPacket.Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
//    sPacket.Ticket.RequesterGuid = player->GetGUID();
//    sPacket.Ticket.Id = schedule.parameter1;
//    HandleBattleFieldPortOpcode(sPacket);//todo4 ??
//	return false;
//}
//
//bool PlayerBotSession::ProcessEnterBG(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld())
//		return false;
//	if (player->GetMap()->IsDungeon() || player->IsInCombat())
//	{
//		BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutBGQueue, 0);
//		schedule1.parameter1 = schedule.parameter1;
//		ClearAllSchedule();
//		PushScheduleToQueue(schedule1);
//		return false;
//	}
//	if (player->InBattleground() || player->InArena())
//		return true;
//
//	if (player->InBattlegroundQueue())
//	{
//		for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
//		{
//			BattlegroundQueueTypeId bgQueueTypeId = player->GetBattlegroundQueueTypeId(i);
//			//if (!bgQueueTypeId)
//			//	continue;
//			if (player->IsInvitedForBattlegroundQueueType(bgQueueTypeId))
//			{
//				PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_BG, true);
//                WorldPacket packet;
//                WorldPackets::Battleground::BattlefieldPort sPacket(std::move(packet));
//                sPacket.AcceptedInvite = true;
//                sPacket.Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
//                sPacket.Ticket.RequesterGuid = player->GetGUID();
//                sPacket.Ticket.Id = i;
//                HandleBattleFieldPortOpcode(sPacket);//todo4 ??
//				HandleMoveWorldportAck();
//				break;
//			}
//		}
//	}
//	return false;
//}
//
//bool PlayerBotSession::ProcessLeaveBG(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->InBattleground())
//		return true;
//
//	PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_FIELD, true);
//
//    WorldPacket packet;
//    WorldPackets::Battleground::BattlefieldLeave sPacket(std::move(packet));
//    HandleBattlefieldLeaveOpcode(sPacket);
//	HandleMoveWorldportAck();
//	return false;
//}
//
//bool PlayerBotSession::ProcessInAAQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld())
//		return false;
//	if (player->InBattlegroundQueue())
//		return true;
//	if (player->HasAura(26013) || player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() || player->IsInCombat() || player->getLevel() < 80)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//
//	Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(schedule.parameter1));
//	if (!bg)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
//	if (!bracketEntry)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//
//	WorldPacket opcode(1);
//	opcode << player->GetGUID();
//	opcode << uint8(schedule.parameter2);
//	opcode << uint8(0);
//	opcode << uint8(schedule.parameter3);
//	//HandleBattlemasterJoinArena(opcode);todo47
//	return false;
//}
//
//bool PlayerBotSession::ProcessOutAAQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld() || player->InBattleground() || player->InArena() || !player->InBattlegroundQueue() || player->GetMap()->IsDungeon())
//		return true;
//
//    WorldPacket packet;
//    WorldPackets::Battleground::BattlefieldPort sPacket(std::move(packet));
//    sPacket.AcceptedInvite = true;
//    sPacket.Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
//    sPacket.Ticket.RequesterGuid = player->GetGUID();
//    sPacket.Ticket.Id = schedule.parameter1;
//    //HandleBattleFieldPortOpcode(sPacket);//todo4 ??
//	return false;
//}
//
//bool PlayerBotSession::ProcessEnterAA(BotGlobleSchedule& schedule)
//{
//    return false;
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->IsInWorld())
//		return false;
//	if (player->GetMap()->IsDungeon() || player->IsInCombat() || player->getLevel() < 80)
//	{
//		BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutAAQueue, 0);
//		schedule1.parameter1 = schedule.parameter1;
//		schedule1.parameter2 = schedule.parameter2;
//		schedule1.parameter3 = schedule.parameter3;
//		ClearAllSchedule();
//		PushScheduleToQueue(schedule1);
//		return false;
//	}
//	if (player->InBattleground() || player->InArena())
//		return true;
//
//	if (player->InBattlegroundQueue())
//	{
//		for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
//		{
//			BattlegroundQueueTypeId bgQueueTypeId = player->GetBattlegroundQueueTypeId(i);
//			//if (!bgQueueTypeId)
//			//	continue;
//			if (player->IsInvitedForBattlegroundQueueType(bgQueueTypeId))
//			{
//				PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_ARENA, true);
//				WorldPacket opcode(1);
//				opcode << uint8(schedule.parameter3);
//				opcode << uint8(schedule.parameter2);
//				opcode << uint32(schedule.parameter1);
//				opcode << uint16(0x1F90);
//				opcode << uint8(1);
//				//HandleBattleFieldPortOpcode(opcode);todo47
//				HandleMoveWorldportAck();
//				break;
//			}
//			else
//			{
//				Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(schedule.parameter1));
//				if (!bg_template)
//					continue;
//				BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//				PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketById(bg_template->GetMapId(), BattlegroundBracketId(schedule.parameter2));
//				if (bgQueue.ExistRealPlayer(bracketEntry, (schedule.parameter4 != 0) ? true : false))
//					continue;
//				BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutAAQueue, 0);
//				schedule1.parameter1 = schedule.parameter1;
//				schedule1.parameter2 = schedule.parameter2;
//				schedule1.parameter3 = schedule.parameter3;
//				ClearAllSchedule();
//				PushScheduleToQueue(schedule1);
//				return false;
//			}
//		}
//	}
//	return false;
//}
//
//bool PlayerBotSession::ProcessLeaveAA(BotGlobleSchedule& schedule)
//{
//    return false;
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->InBattleground())
//		return true;
//
//	PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_FIELD, true);
//	uint8 un8 = 0;
//	uint16 un16 = 0;
//	uint32 un32 = 0;
//	WorldPacket opcode(1);
//	opcode << un8;
//	opcode << un8;
//	opcode << un32;
//	opcode << un16;
//	//HandleBattlefieldLeaveOpcode(opcode);todo47
//	HandleMoveWorldportAck();
//	return false;
//}
//
//bool PlayerBotSession::ProcessDelayLevelup(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	player->OnLevelupToBotAI();
//	return true;
//}
//
//bool PlayerBotSession::ProcessInLFGQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (player->isUsingLfg())
//		return true;
//	if (schedule.parameter1 != 2 && schedule.parameter1 != 4 && schedule.parameter1 != 8)
//		return true;
//	if (schedule.parameter2 > 3 || schedule.parameter2 == 0)
//		return true;
//
//    WorldPacket packet;
//    WorldPackets::LFG::DFJoin dfJoin(std::move(packet));
//    dfJoin.Roles = schedule.parameter1;
//    dfJoin.Slots.resize(3);
//    dfJoin.Slots[0]= schedule.parameter3;
//    dfJoin.Slots[1] = schedule.parameter4;
//    dfJoin.Slots[2] = schedule.parameter5;
//	HandleLfgJoinOpcode(dfJoin);
//	return true;
//}
//
//bool PlayerBotSession::ProcessOutLFGQueue(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->isUsingLfg())
//		return true;
//
//    Group* group = GetPlayer()->GetGroup();
//    if (!group)
//        sLFGMgr->LeaveLfg(player->GetGUID());
//
//	return true;
//}
//
//bool PlayerBotSession::ProcessAcceptLFGProposal(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//	if (schedule.parameter1 == 0)
//		return true;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//	if (!player->isUsingLfg())
//		return true;
//
//	sLFGMgr->UpdateProposal(schedule.parameter1, player->GetGUID(), (schedule.parameter2 != 0) ? true : false);
//	return true;
//}
//
//bool PlayerBotSession::ProcessOfferPetitionSign(BotGlobleSchedule& schedule)
//{
//	if (PlayerLoading())
//		return false;
//    if (schedule.parameterguid == ObjectGuid::Empty)
//        return true;
//	//if (schedule.parameter1 == 0 && schedule.parameter2 == 0)
//	//	return true;
//	Player* player = GetPlayer();
//	if (!player)
//	{
//		ClearAllSchedule();
//		return false;
//	}
//    
//    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIGNATURES);
//
//    stmt->setUInt64(0, schedule.parameterguid.GetCounter());
//    stmt->setUInt64(1, schedule.parameterguid.GetCounter());
//
//    PreparedQueryResult result = CharacterDatabase.Query(stmt);
//
//    if (!result)
//    {
//        TC_LOG_ERROR("network", "Petition %s is not found for %s %s", schedule.parameterguid.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
//        return false;
//    }
//
//    Field* fields = result->Fetch();
//    ObjectGuid ownerGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
//    //uint64 signs = fields[1].GetUInt64();
//
//    if (ownerGuid == player->GetGUID())
//        return false;
//
//    // not let enemies sign guild charter
//    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != ObjectMgr::GetPlayerTeamByGUID(ownerGuid))
//    {
//        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NOT_ALLIED);
//        return false;
//    }
//
//    if (player->GetGuildId())
//    {
//        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_IN_GUILD_S, player->GetName());
//        return false;
//    }
//
//    if (player->GetGuildIdInvited())
//    {
//        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_INVITED_TO_GUILD_S, player->GetName());
//        return false;
//    }
//
//    //if (++signs > type)                                        // client signs maximum
//    //    return;
//
//    // Client doesn't allow to sign petition two times by one character, but not check sign by another character from same account
//    // not allow sign another player from already sign player account
//    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIG_BY_ACCOUNT);
//
//    stmt->setUInt32(0, GetAccountId());
//    stmt->setUInt64(1, schedule.parameterguid.GetCounter());
//
//    result = CharacterDatabase.Query(stmt);
//
//    WorldPackets::Petition::PetitionSignResults signResult;
//    signResult.Player = player->GetGUID();
//    signResult.Item = schedule.parameterguid;
//
//    if (result)
//    {
//        signResult.Error = int32(PETITION_SIGN_ALREADY_SIGNED);
//
//        // close at signer side
//        SendPacket(signResult.Write());
//        return false;
//    }
//
//    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PETITION_SIGNATURE);
//
//    stmt->setUInt64(0, ownerGuid.GetCounter());
//    stmt->setUInt64(1, schedule.parameterguid.GetCounter());
//    stmt->setUInt64(2, player->GetGUID().GetCounter());
//    stmt->setUInt32(3, GetAccountId());
//
//    CharacterDatabase.Execute(stmt);
//
//    signResult.Error = int32(PETITION_SIGN_OK);
//
//    // close at signer side
//    player->GetSession()->SendPacket(signResult.Write());
//	return true;
//}
