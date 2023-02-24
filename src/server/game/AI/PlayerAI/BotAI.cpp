//
//#include "BotAI.h"
////#include "PathfindingMgr.h"
//#include "WorldSession.h"
//#include "Player.h"
////#include "CommandBG.h"
//#include "Battlefield.h"
//#include "BattlefieldMgr.h"
////#include "BotBGAIMovement.h"
//#include "MoveSplineInit.h"
//#include "Spell.h"
//#include "Pet.h"
//#include "CreatureAI.h"
//
////#include "BotWarriorAI.h"
////#include "BotMageAI.h"
////#include "BotPriestAI.h"
////#include "BotHunterAI.h"
////#include "BotWarlockAI.h"
////#include "BotPaladinAI.h"
////#include "BotRogueAI.h"
////#include "BotShamanAI.h"
////#include "BotDruidAI.h"
////#include "BotDemonHunterAI.h"
////#include "BotMonkAI.h"
////#include "BotDeathknightAI.h"
//#include "Cell.h"
//#include "CellImpl.h"
//#include "GridDefines.h"
//#include "GridNotifiers.h"
//#include "GridNotifiersImpl.h"
//#include "MotionMaster.h"
//#include "SpellHistory.h"
//#include "MiscPackets.h"
//#include "MovementPackets.h"
//
////#define THREAD_PATHFINDING
//#ifdef _DEBUG
////#define EXCLUDE_PLAYER
//#endif
//#include <Battlegrounds\Battleground.h>
//
//BotBGAI* BotBGAI::debugBGAI = NULL;
//
//BotBGAI* BotBGAI::CreateBotBGAIByPlayerClass(Player* player)
//{
//	PlayerBotSetting::ClearUnknowMount(player);
//	switch (player->getClass())
//	{
//	case CLASS_WARRIOR:
//		return new BotWarriorAI(player);
//	case CLASS_MAGE:
//		return new BotMageAI(player);
//	case CLASS_PRIEST:
//		return new BotPriestAI(player);
//	case CLASS_HUNTER:
//		return new BotHunterAI(player);
//	case CLASS_WARLOCK:
//		return new BotWarlockAI(player);
//	case CLASS_PALADIN:
//		return new BotPaladinAI(player);
//	case CLASS_ROGUE:
//		return new BotRogueAI(player);
//	case CLASS_SHAMAN:
//		return new BotShamanAI(player);
//	case CLASS_DRUID:
//		return new BotDruidAI(player);
//	case CLASS_DEATH_KNIGHT:
//        return new BotDeathknightAI(player);
//        break;
//    case CLASS_DEMON_HUNTER:
//        return new BotDemonHunterAI(player);
//    case CLASS_MONK:
//        return new BotMonkAI(player);
//        break;
//	}
//	return new BotBGAI(player);
//}
//
//BotBGAI::BotBGAI(Player* player) :
//PlayerAI(player),
//m_NeedFindpathSearch(false),
//m_UpmountTick(0),
//m_Movement(new BotBGAIMovement(player, this)),
//m_CurrentTargetTick(0),
//m_UseMountID(PlayerBotSetting::RandomMountByLevel(player->getLevel())),
//pHorrorState(NULL),
//m_CheckStoped(player),
//m_Teleporting(player),
//m_UsePotion(player),
//m_Flee(player),
//m_NeedFlee(player),
//m_CastRecords(player),
//m_FastAid(player),
//m_GroupLeader(player),
//m_MovetoUseGO(player),
//m_AIBGStateType(BotAIBGState::AIBGState_Leave),
//m_UpdateTick(BOTAI_UPDATE_TICK),
//m_CanDireFlee(0),
//m_CruxControlTarget(ObjectGuid::Empty),
//m_LastControlTarget(ObjectGuid::Empty),
//m_NeedReserveCtrlSpell(false),
//m_InitRndPos(),
//m_lastClearCtrlTick(0)
//{
//	m_FilterCreatureEntrys.clear();
//	m_FilterCreatureEntrys.insert(14848);
//	m_FilterCreatureEntrys.insert(11603);
//	m_FilterCreatureEntrys.insert(11604);
//	m_FilterCreatureEntrys.insert(11605);
//	m_FilterCreatureEntrys.insert(11677);
//	m_FilterCreatureEntrys.insert(10982);
//	m_FilterCreatureEntrys.insert(10987);
//	m_FilterCreatureEntrys.insert(11600);
//	m_FilterCreatureEntrys.insert(11602);
//	m_FilterCreatureEntrys.insert(11657);
//	m_FilterCreatureEntrys.insert(10990);
//	m_FilterCreatureEntrys.insert(10981);
//}
//
//BotBGAI::~BotBGAI()
//{
//	delete m_Movement;
//}
//
//void BotBGAI::ProcessBotCommand(Player* srcPlayer, std::string cmd)
//{
//	if (srcPlayer->GetMap() != me->GetMap())
//		return;
//	std::string param;
//	if (!CanReciveCommand(cmd, param))
//		return;
//	if (cmd == "rite")
//		ProcessSummonRiteSpell(srcPlayer);
//	else if (cmd == "attack")
//		ProcessAttackCommand(srcPlayer);
//}
//
//bool BotBGAI::CanReciveCommand(std::string& cmd, std::string& param)
//{
//	if (cmd.empty())
//		return false;
//	if (cmd[0] == '@')
//	{
//		int32 firstEndIndex = cmd.find(' ');
//		if (firstEndIndex <= 1)
//			return false;
//		std::string target = cmd.substr(1, firstEndIndex - 1);
//		std::string realCmd = cmd.substr(firstEndIndex + 1);
//		if (realCmd.empty())
//			return false;
//		if (target == "tank")
//		{
//			return false;
//		}
//		else if (target == "melee")
//		{
//			if (!IsMeleeBotAI() || IsHealerBotAI())
//				return false;
//		}
//		else if (target == "ranged")
//		{
//			if (!IsRangeBotAI() || IsHealerBotAI())
//				return false;
//		}
//		else if (target == "dps")
//		{
//			if (IsHealerBotAI())
//				return false;
//		}
//		else if (target == "heal")
//		{
//			if (!IsHealerBotAI())
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_WARRIOR)
//		{
//			if (target != "zs")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_PALADIN)
//		{
//			if (target != "qs")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_HUNTER)
//		{
//			if (target != "lr")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_ROGUE)
//		{
//			if (target != "dz")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_PRIEST)
//		{
//			if (target != "ms")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_DEATH_KNIGHT)
//		{
//			if (target != "dk")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_SHAMAN)
//		{
//			if (target != "sm")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_MAGE)
//		{
//			if (target != "fs")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_WARLOCK)
//		{
//			if (target != "ss")
//				return false;
//		}
//		else if (me->getClass() == Classes::CLASS_DRUID)
//		{
//			if (target != "xd")
//				return false;
//		}
//        else if (me->getClass() == Classes::CLASS_DEMON_HUNTER)
//        {
//            if (target != "dh")
//                return false;
//        }
//        else if (me->getClass() == Classes::CLASS_MONK)
//        {
//            if (target != "ws")
//                return false;
//        }
//		int32 secondEndIndex = realCmd.find(' ');
//		if (secondEndIndex <= 0)
//			cmd = realCmd;
//		else
//		{
//			cmd = realCmd.substr(0, secondEndIndex);
//			param = realCmd.substr(secondEndIndex + 1);
//		}
//	}
//	else
//	{
//		int32 firstEndIndex = cmd.find(' ');
//		if (firstEndIndex < 0)
//			return true;
//		std::string realCmd = cmd.substr(0, firstEndIndex);
//		param = cmd.substr(firstEndIndex + 1);
//		cmd = realCmd;
//	}
//	return true;
//}
//
//void BotBGAI::ProcessSummonRiteSpell(Player* srcPlayer)
//{
//	Battleground* pBattleground = me->GetBattleground();
//	if (!pBattleground || pBattleground->GetStatus() != BattlegroundStatus::STATUS_WAIT_JOIN)
//		return;
//	if (!srcPlayer || !srcPlayer->IsInWorld() || me->GetMap() != srcPlayer->GetMap())
//		return;
//	if (srcPlayer->GetDistance(me->GetPosition()) > BOTAI_RANGESPELL_DISTANCE)
//		return;
//	if (!m_MovetoUseGO.CanCastSummonRite())
//	{
//		std::string outString;
//        consoleToUtf8(std::string("目前无法开始召唤仪式！"), outString);
//		me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//		return;
//	}
//	uint32 castSpellID = TryCastSummonRiteSpell();
//	if (castSpellID)
//	{
//		m_MovetoUseGO.StartSummonRite(castSpellID);
//		std::string outString;
//        consoleToUtf8(std::string("召唤仪式启动！"), outString);
//		me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//	}
//	else
//	{
//		std::string outString;
//        consoleToUtf8(std::string("目前无法开始召唤仪式！"), outString);
//		me->Whisper(outString, Language::LANG_COMMON, srcPlayer);
//	}
//}
//
//void BotBGAI::ProcessAttackCommand(Player* srcPlayer)
//{
//	if (!srcPlayer || srcPlayer->IsPlayerBot())
//		return;
//	Unit* pMasterTarget = srcPlayer->GetSelectedUnit();
//	if (!pMasterTarget || !pMasterTarget->IsAlive())
//		return;
//	if (!me->IsValidAttackTarget(pMasterTarget))
//		return;
//	if (me->GetDistance(pMasterTarget->GetPosition()) > BOTAI_SEARCH_RANGE)
//		return;
//	me->SetSelection(pMasterTarget->GetGUID());
//}
//
//void BotBGAI::EachTick()
//{
//	m_RangeCreatureLists.clear();
//	m_RangePlayerLists.clear();
//	me->UpdateObjectVisibility(true);
//}
//
//bool BotBGAI::InBattleground()
//{
//	Player* pBot = dynamic_cast<Player*>(me);
//	if (!pBot || !pBot->InBattleground() || !me->IsInWorld())
//		return false;
//	Map* pMap = me->GetMap();
//	Battleground* pBG = pBot->GetBattleground();
//	if (!pBG || !pMap || pBG->FindBgMap() != pMap)
//		return false;
//	if (pBG->GetStatus() == BattlegroundStatus::STATUS_NONE || pBG->GetStatus() == BattlegroundStatus::STATUS_WAIT_LEAVE)
//		return false;
//	return true;
//}
//
//void BotBGAI::BattlegroundRevive()
//{
//  
//    if (me->InArena())
//        return;
//		
//    if (!me->IsPlayerBot() || !me->InBattleground())
//        return;
//
//	Player* player = dynamic_cast<Player*>(me);
//	if (!player || player->IsAlive())
//		return;
//	CommandBG* bgCommander = player->GetMap()->GetCommander(player->GetTeamId());
//    if (!bgCommander) 
//        return;
//
//	if (player->getDeathState() == DeathState::CORPSE && !player->HasPlayerFlag(PLAYER_FLAGS_GHOST)) // need release soul
//	{
//		//m_IsFlagTarget = false;
//		m_Movement->ClearMovement();
//		//bgCommander->OnPlayerDead(player->GetGUID());
//
//        WorldPacket packet;
//        WorldPackets::Misc::RepopRequest RepopPacket(std::move(packet));
//        player->GetSession()->HandleRepopRequest(RepopPacket);
//
//        WorldPacket packet2;
//        WorldPackets::Movement::MoveTeleportAck Movepacket(std::move(packet2));
//        Movepacket.MoverGUID = player->GetGUID();
//        Movepacket.MoveTime = 100;
//		player->GetSession()->HandleMoveTeleportAck(Movepacket);
//
//		//const Creature* pCreature = bgCommander->GetMatchGraveyardNPC(player);
//		//if (!pCreature || !pCreature->IsSpiritService())	// it's not spirit service
//			//return;
//	//	player->GetBattleground()->AddPlayerToResurrectQueue(pCreature->GetGUID(), player->GetGUID());
//		//if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId()))
//		//	bf->AddPlayerToResurrectQueue(pCreature->GetGUID(), player->GetGUID());
//	}
//	else if (!player->GetBattleground()->HasJoinNearGrave(player))
//	{
//		//const Creature* pCreature = bgCommander->GetMatchGraveyardNPC(player);
//		////if (!pCreature || !pCreature->IsSpiritService())	// it's not spirit service
//			return;
//	//	player->GetBattleground()->AddPlayerToResurrectQueue(pCreature->GetGUID(), player->GetGUID());
//	}
//}
//
//void BotBGAI::DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
//{
//	//if (!victim || !me->IsInWorld() || damage == 0)
//	//	return;
//	//if (!me->InBattleground())
//	//	return;
//	//Player* vicPlayer = victim->ToPlayer();
//	//if (!vicPlayer)
//	//	return;
//
//	//int32 meCP = me->GetEquipCombatPower();
//	//int32 vicCP = vicPlayer->GetEquipCombatPower();
//	//int32 cpGap = meCP - vicCP;
//	//if (cpGap == 0)
//	//	return;
//	//float addion = 0;
//	//if (cpGap > 0 && meCP > 0)
//	//{
//	//	addion = float(cpGap) / float(meCP);
//	//	addion = 1.0f - addion;
//	//}
//	//else if (cpGap < 0 && vicCP > 0)
//	//{
//	//	addion = float(cpGap * (-1.0f)) / float(vicCP);
//	//	addion += 1.0f;
//	//}
//	//if (addion <= 0)
//	//	return;
//	//float result = float(damage);
//	//switch (damageType)
//	//{
//	//case DamageEffectType::DIRECT_DAMAGE:
//	//case DamageEffectType::SPELL_DIRECT_DAMAGE:
//	//case DamageEffectType::DOT:
//	//	result *= addion;
//	//	break;
//	//default:
//	//	return;
//	//}
//	//damage = uint32(result);
//}
//
//void BotBGAI::DamageEndure(Unit* attacker, uint32& damage, DamageEffectType damageType)
//{
//	//if (!attacker || !me->IsInWorld() || damage == 0)
//	//	return;
//	//if (!me->InBattleground())
//	//	return;
//	//Player* attPlayer = attacker->ToPlayer();
//	//if (!attPlayer)
//	//	return;
//	//int32 meCP = me->GetEquipCombatPower();
//	//int32 attCP = attPlayer->GetEquipCombatPower();
//	//int32 cpGap = attCP - meCP;
//	//if (cpGap == 0)
//	//	return;
//	//float addion = 0;
//	//if (cpGap > 0)
//	//{
//	//	addion = float(cpGap) / float(attPlayer->GetEquipCombatPower());
//	//	addion = 1.0f - addion;
//	//}
//	//else
//	//{
//	//	addion = float(cpGap * (-1.0f)) / float(me->GetEquipCombatPower());
//	//	addion += 1.0f;
//	//}
//	//if (addion <= 0)
//	//	return;
//	//float result = float(damage);
//	//switch (damageType)
//	//{
//	//case DamageEffectType::DIRECT_DAMAGE:
//	//case DamageEffectType::SPELL_DIRECT_DAMAGE:
//	//case DamageEffectType::DOT:
//	//	result *= addion;
//	//	break;
//	//default:
//	//	return;
//	//}
//	//damage = uint32(result);
//}
//
//void BotBGAI::UpdateAI(uint32 diff)
//{
//	m_UpdateTick -= diff;
//
//	if (m_UpdateTick <= 0)
//	{
//		m_UpdateTick = BOTAI_UPDATE_TICK;
//		if (!InBattleground())
//			return;
//		if (IsAlive())
//		{
//			if (me->HasAura(BattlegroundSpells::SPELL_WAITING_FOR_RESURRECT))
//			{
//                me->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);
//                Player* player = dynamic_cast<Player*>(me);
//            //    if(CommandBG* bgCommander = player->GetMap()->GetCommander(player->GetTeamId()))
//                //    bgCommander->OnPlayerRevive(player);
//			}
//			if (m_Teleporting.CanMovement())
//				UpdateBotAI(BOTAI_UPDATE_TICK);
//			else
//				m_Teleporting.Update(diff, m_Movement);
//		}
//        else if (me->InBattleground())
//        {
//            m_MovetoUseGO.ClearUseGO();
//            m_CastRecords.ClearRecordSpell();
//            m_Teleporting.ClearTeleport();
//            me->SetSelection(ObjectGuid::Empty);
//            BattlegroundRevive();
//        }
//
//		//{
//		//	std::lock_guard<std::mutex> lock(m_movQueueLock);
//		//	if (!m_pfFinishQueue.empty())
//		//	{
//		//		PathParameter* parameter = m_pfFinishQueue.front();
//		//		m_pfFinishQueue.pop();
//		//		m_Movement->ApplyFinishPath(parameter);
//		//		delete parameter;
//		//	}
//		//}
//	}
//}
//
//void BotBGAI::ProcessHealth()
//{
//	if (me->HasUnitState(UNIT_STATE_CASTING))
//		return;
//	if (NeedFlee())
//	{
//		//Dismount();
//		ProcessFlee();
//		return;
//	}
//	//Dismount();
//	float searchDist = (me->InArena()) ? (BOTAI_SEARCH_RANGE * 3) : (BOTAI_SEARCH_RANGE * 1.5);
//	NearUnitVec& needHealth = SearchNeedHealth(searchDist);
//	if (needHealth.empty())
//	{
//		ProcessCombat(me->GetSelectedUnit());
//		return;
//	}
//	Unit* healthPlayer = needHealth[urand(0, needHealth.size() - 1)];
//	bool inView = me->IsWithinLOSInMap(healthPlayer);
//	if (inView)
//	{
//		if (me->GetDistance(healthPlayer) > BOTAI_RANGESPELL_DISTANCE - 3)
//		{
//			ChaseTarget(healthPlayer, false, BOTAI_RANGESPELL_DISTANCE - 3);
//		}
//		else
//		{
//			me->StopMoving();
//			ProcessHealthSpell(healthPlayer);
//		}
//	}
//	else if (!IsNotMovement())
//	{
//		m_Movement->MovementTo(healthPlayer->GetGUID());
//	}
//}
//
//void BotBGAI::ProcessCombat(Unit* pTarget)
//{
//	if (!pTarget)
//		return;
//	bool inView = me->IsWithinLOSInMap(pTarget);
//	if (inView)
//	{
//		if (me->HasUnitState(UNIT_STATE_CASTING))
//			return;
//		if (m_IsRangeBot)
//		{
//			if (NeedFlee())
//			{
//				if (pTarget->GetGUID() != me->GetTarget())
//				{
//					pTarget = me->GetSelectedUnit();
//					if (!pTarget)
//						return;
//				}
//				//Dismount();
//				if (me->GetVictim() != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
//					me->Attack(pTarget, true);
//				ProcessFlee();
//				if (!IsNotSelect(pTarget))
//					ProcessMeleeSpell(pTarget);
//				//ChaseTarget(pTarget, true);
//			}
//			else if (me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE)
//			{
//				//Dismount();
//				if (me->GetVictim() != pTarget)// || me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
//					me->Attack(pTarget, false);
//				if (!IsNotSelect(pTarget))// && !DoFaceToTarget(pTarget))
//				{
//					me->SetInFront(pTarget);
//					me->SetFacingToObject(pTarget);
//					if (me->getClass() != Classes::CLASS_HUNTER)
//						m_Movement->ClearMovement();
//					ChaseTarget(pTarget, false, BOTAI_RANGESPELL_DISTANCE);
//					ProcessRangeSpell(pTarget);
//					if (!me->HasUnitState(UNIT_STATE_CASTING))
//						DoRangedAttackIfReady();
//				}
//			}
//			else if (!IsNotMovement())
//			{
//				if (me->GetVictim() != pTarget)// || me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
//					me->Attack(pTarget, false);
//				m_Movement->MovementToTarget();
//			}
//		}
//		else
//		{
//			if (NeedFlee())
//			{
//				if (me->GetVictim() != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
//					me->Attack(pTarget, true);
//				ProcessFlee();
//				if (!IsNotSelect(pTarget))
//					ProcessMeleeSpell(pTarget);
//			}
//			else if (me->IsWithinMeleeRange(pTarget))
//			{
//				//Dismount();
//				if (!me->GetVictim() && !me->IsVehicle())
//					me->Attack(pTarget, true);
//				if (!IsNotMovement())
//					ChaseTarget(pTarget, true);
//				if (!IsNotSelect(pTarget) && !me->IsVehicle())
//					ProcessMeleeSpell(pTarget);
//			}
//			else
//			{
//				if (!IsNotMovement())
//					m_Movement->MovementToTarget();
//				if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE && pTarget->IsAlive())
//				{
//					//Dismount();
//					ProcessRangeSpell(pTarget);
//				}
//			}
//		}
//	}
//	else if (!IsNotMovement())
//		m_Movement->MovementToTarget();
//}
//
//void BotBGAI::Dismount()
//{
//	if (!me->HasAura(m_UseMountID))
//		return;
//	m_UpmountTick = 0;
//	me->RemoveOwnedAura(m_UseMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
//}
//
//DiminishingGroup BotBGAI::GetControlSpellDiminishingGroup()
//{
//	switch (me->getClass())
//	{
//	case Classes::CLASS_PALADIN:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_ROGUE:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_DRUID:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_HUNTER:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_SHAMAN:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_MAGE:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	case Classes::CLASS_WARLOCK:
//		return DiminishingGroup::DIMINISHING_DISORIENT;
//	}
//	return DIMINISHING_NONE;
//}
//
//void BotBGAI::ProcessReady()
//{
//
//}
//
//void BotBGAI::ChaseTarget(Unit* pTarget, bool isMelee, float range)
//{
//	if (IsNotSelect(pTarget))
//		return;
//	if (isMelee)
//	{
//		if (me->IsStopped())
//		{
//			Position& targetPos = pTarget->GetPosition();
//			float rndOffset = frand(-float(M_PI_4) * 0.75f, float(M_PI_4) * 0.75f);
//			Position& pos = me->GetFirstCollisionPosition(me->GetDistance(targetPos) + range, me->GetRelativeAngle(&targetPos) + rndOffset);
//			m_Movement->MovementTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
//			//me->GetMotionMaster()->MovePoint(0, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
//		}
//	}
//	else
//	{
//		//if (me->isInBack(pTarget) && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
//		//{
//		//	Movement::MoveSplineInit init(me);
//		//	init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
//		//	init.SetFacing(pTarget);
//		//	init.SetOrientationFixed(true);
//		//	init.Launch();
//		//}
//		//else// if (!IsNotMovement())
//		{
//			me->GetMotionMaster()->Clear();
//			me->GetMotionMaster()->MoveChase(pTarget, range);
//		}
//	}
//}
//
//void BotBGAI::SearchCreatureListFromRange(Unit* center, NearCreatureVec& nearCreatures, float range, bool selfFaction)
//{
//	NearCreatureList nearCreature;
//	//if (center == me)
//	//	QueryNearCreatureList(range, nearCreature);
//	//else
//	{
//		Trinity::AllWorldObjectsInRange checker(center, range);
//		Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(center, nearCreature, checker);
//        Cell::VisitGridObjects(center, searcher, range);
//	}
//	for (Creature* pCreature : nearCreature)
//	{
//		if (IsFilterCreatureByEntry(pCreature->GetEntry()))
//			continue;
//		if (pCreature->IsPet() || pCreature->IsTotem() || pCreature->IsSummon())
//			continue;
//		if (pCreature->IsInEvadeMode())
//			continue;
//		if (selfFaction && center->IsValidAttackTarget(pCreature))
//			continue;
//		if (!selfFaction && !center->IsValidAttackTarget(pCreature))
//			continue;
//		nearCreatures.push_back(pCreature);
//	}
//}
//
//Unit* BotBGAI::SearchEnemy(float range)
//{
//	NearPlayerList playersNearby;
//	QueryNearPlayerList(range, playersNearby);
//	NearPlayerVec enemyPlayers, invinciblePlayers;
//	Player* minHealthPlayer = NULL;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if(TargetIsStealth(pVisionPlayer))
//			continue;
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (IsInvincible(pVisionPlayer) || HasAuraMechanic(pVisionPlayer, Mechanics::MECHANIC_POLYMORPH))
//			{
//				invinciblePlayers.push_back(pVisionPlayer);
//			}
//			else
//			{
//				float hp = pVisionPlayer->GetHealthPct();
//				if (hp < 80.0f)
//				{
//					if (!minHealthPlayer)
//						minHealthPlayer = pVisionPlayer;
//					else if (hp < minHealthPlayer->GetHealthPct())
//						minHealthPlayer = pVisionPlayer;
//				}
//				if (m_NeedFindpathSearch)
//				{
//					if (m_Movement->CanMovementTo(pVisionPlayer->GetPositionX(), pVisionPlayer->GetPositionY(), pVisionPlayer->GetPositionZ()))
//						enemyPlayers.push_back(pVisionPlayer);
//				}
//				else
//					enemyPlayers.push_back(pVisionPlayer);
//			}
//		}
//	}
//	if (enemyPlayers.empty())
//	{
//		NearCreatureVec creatures;
//		SearchCreatureListFromRange(me, creatures, range, false);
//		if (!creatures.empty())
//		{
//			uint32 index = urand(0, creatures.size() - 1);
//			return creatures[index];
//		}
//		if (invinciblePlayers.empty())
//			return NULL;
//		uint32 index = urand(0, invinciblePlayers.size() - 1);
//		Player* pVisionPlayer = invinciblePlayers[index];
//		return pVisionPlayer;
//	}
//	if (!minHealthPlayer)
//	{
//		uint32 index = urand(0, enemyPlayers.size() - 1);
//		Player* pVisionPlayer = enemyPlayers[index];
//		return pVisionPlayer;
//	}
//	return minHealthPlayer;
//}
//
//NearObjectList BotBGAI::SearchGameObject(float range)
//{
//	std::list<GameObject*> results;
//	Position& pos = me->GetPosition();
//	Trinity::GameObjectInRangeCheck checker(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), range);
//	Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(me, results, checker);
//    Cell::VisitGridObjects(me, searcher, range);
//	return results;
//}
//
//NearUnitVec BotBGAI::SearchFriend(float range)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec friendNearby;
//	QueryNearPlayerList(range, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			friendNearby.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, true);
//	for (Creature* pCreature : creatures)
//		friendNearby.push_back(pCreature);
//	return friendNearby;
//}
//
//NearUnitVec BotBGAI::SearchFriendTargetIsTarget(Unit* pTarget, float range)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec friendNearby;
//	if (pTarget == me)
//		QueryNearPlayerList(range, playersNearby);
//	else
//		pTarget->GetPlayerListInGrid(playersNearby, range);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//		if (pVisionPlayer->GetTarget() != pTarget->GetGUID())
//			continue;
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			friendNearby.push_back(pVisionPlayer);
//		}
//	}
//	return friendNearby;
//}
//
//NearPlayerVec BotBGAI::SearchFarFriend(float minRange, float maxRange, bool isIDLE)
//{
//	NearPlayerList playersNearby;
//	NearPlayerVec friendNearby;
//	QueryNearPlayerList(maxRange, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			if (me->GetDistance(pVisionPlayer->GetPosition()) > minRange)
//			{
//				if (isIDLE)
//				{
//					if (pVisionPlayer->GetSelectedUnit() == NULL || !pVisionPlayer->IsInCombat())
//						friendNearby.push_back(pVisionPlayer);
//				}
//				else
//					friendNearby.push_back(pVisionPlayer);
//			}
//		}
//	}
//	return friendNearby;
//}
//
//NearPlayerVec BotBGAI::ExistFriendAttacker(float range /* = BOTAI_RANGESPELL_DISTANCE */)
//{
//	NearPlayerList playersNearby;
//	NearPlayerVec friendNearby;
//	QueryNearPlayerList(range, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId() && IsAttacker())
//		{
//			friendNearby.push_back(pVisionPlayer);
//		}
//	}
//
//	return friendNearby;
//}
//
//NearUnitVec BotBGAI::SearchNeedHealth(float range /* = BOTAI_SEARCH_RANGE */)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec lifeTo25, life25To55, life55To80;
//	QueryNearPlayerList(range, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			float healthPct = pVisionPlayer->GetHealthPct();
//			if (healthPct < 25)
//				lifeTo25.push_back(pVisionPlayer);
//			else if (healthPct >= 25 && healthPct < 55)
//				life25To55.push_back(pVisionPlayer);
//			else if (healthPct >= 55 && healthPct < 80)
//				life55To80.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, true);
//	for (Creature* pCreature : creatures)
//	{
//		float healthPct = pCreature->GetHealthPct();
//		if (healthPct < 25)
//			lifeTo25.push_back(pCreature);
//		else if (healthPct >= 25 && healthPct < 55)
//			life25To55.push_back(pCreature);
//		else if (healthPct >= 55 && healthPct < 80)
//			life55To80.push_back(pCreature);
//	}
//
//	uint32 rate = urand(0, 99);
//	if (rate >= 85 && life55To80.size() > 0)
//		return life55To80;
//	else if (rate < 85 && rate >= 55 && life25To55.size() > 0)
//		return life25To55;
//	else if (lifeTo25.size() > 0)
//		return lifeTo25;
//	else if (life25To55.size() > 0)
//		return life25To55;
//	return life55To80;
//}
//
//NearUnitVec BotBGAI::BeforeSearchNeedHealth(float range, float minHeal)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec minLife;
//	QueryNearPlayerList(range, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			float healthPct = pVisionPlayer->GetHealthPct();
//			if (healthPct < minHeal)
//				minLife.push_back(pVisionPlayer);
//		}
//	}
//	return minLife;
//}
//
//NearUnitVec BotBGAI::SearchLifePctByFriendRange(Unit* pTarget, float lifePct, float range /* = NEEDFLEE_CHECKRANGE */)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec lifePctPlayers;
//	if (pTarget == me)
//		QueryNearPlayerList(range, playersNearby);
//	else
//		pTarget->GetPlayerListInGrid(playersNearby, range);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
//		{
//			float healthPct = pVisionPlayer->GetHealthPct();
//			if (healthPct <= lifePct)
//				lifePctPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, true);
//	for (Creature* pCreature : creatures)
//	{
//		float healthPct = pCreature->GetHealthPct();
//		if (healthPct <= lifePct)
//			lifePctPlayers.push_back(pCreature);
//	}
//
//	return lifePctPlayers;
//}
//
//bool BotBGAI::NeedDireFlee()
//{
//	if (m_CanDireFlee == 0)
//	{
//		if (Map* pMap = me->GetMap())
//		{
//			if (CommandBG* bgCommander = pMap->GetCommander(me->GetTeamId()))
//			{
//				//if (bgCommander->CanDireFlee())
//				//	m_CanDireFlee = 1;
//				//else
//					m_CanDireFlee = -1;
//			}
//		}
//	}
//	if (m_CanDireFlee <= 0)
//		return false;
//	if (me->GetHealthPct() < 20 && RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE * 0.6f).size() > 0)
//		return true;
//	NearPlayerVec& rangeFriends = ExistFriendAttacker(BOTAI_SEARCH_RANGE * 0.6f);
//	NearUnitVec& rangeEnemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE * 0.6f);
//	int32 enemyCount = int32(rangeEnemys.size());
//	int32 friendCount = int32(rangeFriends.size());
//	float gap = (float)(enemyCount - friendCount);
//	if (gap < 2)
//		return false;
//	if (friendCount <= 0)
//		return true;
//	float rate = gap / ((float)friendCount);
//	return rate > 0.2f;
//}
//
//bool BotBGAI::DoDireFlee()
//{
//	if (IsNotMovement())
//		return false;
//	NearUnitVec& enemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE * 0.6f);
//	if (enemys.empty())
//		return false;
//	NearPlayerVec& friends = SearchFarFriend(BOTAI_SEARCH_RANGE * 0.8f, BOTAI_SEARCH_RANGE * 1.4f, true);
//	if (friends.empty())
//		return false;
//	Unit* nearFriend = NULL;
//	float nearDistance = 0;
//	for (Player* player : friends)
//	{
//		float distance = me->GetDistance(player->GetPosition());
//		if (nearFriend == NULL)
//		{
//			nearFriend = player;
//			nearDistance = distance;
//		}
//		else if (distance < nearDistance)
//		{
//			nearFriend = player;
//			nearDistance = distance;
//		}
//		if (player->GetSelectedUnit() == NULL)
//		{
//			player->StopMoving();
//			uint32 index = urand(0, enemys.size() - 1);
//			player->SetSelection(enemys[index]->GetGUID());
//		}
//	}
//	if (nearFriend)
//	{
//		me->AttackStop();
//		//me->SetSelection(ObjectGuid::Empty);
//		m_Movement->MovementTo(nearFriend->GetPositionX(), nearFriend->GetPositionY(), nearFriend->GetPositionZ(), 3.0f);
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::DoFaceToTarget(Unit* pTarget)
//{
//	float relative = me->GetRelativeAngle(pTarget->GetPositionX(), pTarget->GetPositionY());
//	if (relative > M_PI_4 && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
//	{
//		//me->SetFacingToObject(pTarget);
//		Movement::MoveSplineInit init(me);
//		init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
//		init.SetFacing(pTarget);
//		init.SetOrientationFixed(true);
//		init.Launch();
//		return true;
//	}
//	return false;
//}
//
//SpellCastResult BotBGAI::TryCastSpell(uint32 spellID, Unit* pTarget, bool force, bool dismount)
//{
//	if (!spellID || !me->HasSpell(spellID))
//	{
//        if (spellID)
//            me->LearnSpell(spellID, false);
//
//		return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//	}
//	if (spellID == BotCommon_ClearAllCtrl)
//	{
//		uint32 curTick = getMSTime();
//		if (m_lastClearCtrlTick + 120000 > curTick)
//		{
//			return SpellCastResult::SPELL_FAILED_NOT_READY;
//		}
//		m_lastClearCtrlTick = curTick;
//	}
//
//	SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//	if (!spellInfo || spellInfo->IsPassive())
//		return SpellCastResult::SPELL_FAILED_UNKNOWN;
//	Spell* spell = new Spell(me, spellInfo,
//		force ? TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM) : TriggerCastFlags::TRIGGERED_NONE, ObjectGuid::Empty);
//	spell->m_CastItem = NULL;
//	SpellCastTargets targets;
//	targets.SetUnitTarget(pTarget);
//	//spell->InitExplicitTargets(targets);
//	//SpellCastResult castResult = spell->CheckCast(true);
//	//if (castResult != SpellCastResult::SPELL_CAST_OK)
//	//{
//	//	spell->finish(false);
//	//	delete spell;
//	//	return castResult;
//	//}
//	if (dismount)
//		Dismount();
//    SpellCastResult castResult;// = spell->prepare(&targets, NULL);
//	if (castResult != SpellCastResult::SPELL_CAST_OK)
//	{
//		if (castResult == SpellCastResult::SPELL_FAILED_NOT_MOUNTED)
//			PlayerBotSetting::ClearUnknowMount(me);
//		//spell->finish(false);
//		//delete spell;
//		return castResult;
//	}
//	return SpellCastResult::SPELL_CAST_OK;
//}
//
//SpellCastResult BotBGAI::PetTryCastSpell(uint32 spellID, Unit* pTarget, bool force)
//{
//	Pet* pPet = me->GetPet();
//	if (!pPet || !pPet->IsAlive())
//		return SpellCastResult::SPELL_FAILED_UNKNOWN;
//	if (!spellID || !pPet->HasSpell(spellID))
//		return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
//	SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//	if (!spellInfo || spellInfo->IsPassive())
//		return SpellCastResult::SPELL_FAILED_UNKNOWN;
//	Spell* spell = new Spell(pPet, spellInfo, TRIGGERED_NONE);
//	pTarget = pTarget ? pTarget : pPet;
//	SpellCastResult castResult = spell->CheckPetCast(pTarget);
//	if (castResult == SPELL_FAILED_UNIT_NOT_INFRONT && !pPet->isPossessed() && !pPet->IsVehicle())
//	{
//		if (pTarget && pTarget != pPet)
//		{
//			pPet->SetInFront(pTarget);
//			if (Player* player = pTarget->ToPlayer())
//				pPet->SendUpdateToPlayer(player);
//		}
//		else if (Unit* unit_target2 = spell->m_targets.GetUnitTarget())
//		{
//			pPet->SetInFront(unit_target2);
//			if (Player* player = unit_target2->ToPlayer())
//				pPet->SendUpdateToPlayer(player);
//		}
//
//		if (Unit* powner = pPet->GetCharmerOrOwner())
//			if (Player* player = powner->ToPlayer())
//				pPet->SendUpdateToPlayer(player);
//
//		castResult = SPELL_CAST_OK;
//	}
//	if (castResult == SPELL_CAST_OK)
//	{
//		pTarget = spell->m_targets.GetUnitTarget();
//
//		//10% chance to play special pet attack talk, else growl
//		//actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
//		if (pPet->IsPet() && (((Pet*)pPet)->getPetType() == SUMMON_PET) && (pPet != pTarget) && (urand(0, 100) < 10))
//			pPet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
//		else
//		{
//			pPet->SendPetAIReaction(me->GetPetGUID());
//		}
//
//		if (pTarget && !pPet->isPossessed() && !pPet->IsVehicle())
//		{
//			// This is true if pet has no target or has target but targets differs.
//			if (pPet->GetVictim() != pTarget)
//			{
//				if (pPet->GetVictim())
//					pPet->AttackStop();
//				pPet->GetMotionMaster()->Clear();
//				if (pPet->ToCreature()->IsAIEnabled)
//					pPet->ToCreature()->AI()->AttackStart(pTarget);
//			}
//		}
//
//		//return spell->prepare(&(spell->m_targets));
//	}
//	else
//	{
//		//if (pPet->isPossessed() || pPet->IsVehicle()) /// @todo: confirm this check
//		//	Spell::SendCastResult(me, spellInfo, 0, ObjectGuid::Empty, castResult);
//		//else
//			spell->SendPetCastResult(castResult);
//
//		if (!pPet->GetSpellHistory()->HasCooldown(spellID))
//			pPet->GetSpellHistory()->ResetCooldown(spellID, true);
//
//		spell->finish(false);
//		delete spell;
//
//		// reset specific flags in case of spell fail. AI will reset other flags
//		if (pPet->GetCharmInfo())
//			pPet->GetCharmInfo()->SetIsCommandAttack(false);
//	}
//
//	return castResult;
//}
//
//void BotBGAI::SettingPetAutoCastSpell(uint32 spellID, bool autoCast)
//{
//	Pet* pPet = me->GetPet();
//	if (!pPet || !pPet->IsAlive())
//		return;
//	if (!spellID || !pPet->HasSpell(spellID))
//		return;
//	SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_NONE);
//	if (!spellInfo || spellInfo->IsPassive() || !spellInfo->IsAutocastable())
//		return;
//	CharmInfo* charmInfo = pPet->GetCharmInfo();
//	if (!charmInfo)
//		return;
//	if (pPet->IsPet())
//		pPet->ToggleAutocast(spellInfo, autoCast);
//	else
//		pPet->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, autoCast);
//
//	charmInfo->SetSpellAutocast(spellInfo, autoCast);
//}
//
//Unit* BotBGAI::RandomRangeEnemyByCasting(float range)
//{
//	NearPlayerList playersNearby;
//	QueryNearPlayerList(range, playersNearby);
//	NearPlayerVec enemyPlayers;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (pVisionPlayer->HasUnitState(UNIT_STATE_CASTING))
//				enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	if (enemyPlayers.empty())
//	{
//		NearCreatureVec creatures;
//		SearchCreatureListFromRange(me, creatures, range, false);
//		if (!creatures.empty())
//		{
//			uint32 index = urand(0, creatures.size() - 1);
//			return creatures[index];
//		}
//		return NULL;
//	}
//	uint32 count = enemyPlayers.size();
//	uint32 index = urand(0, count - 1);
//	return enemyPlayers[index];
//}
//
//NearUnitVec BotBGAI::RangeEnemyListByHasAura(uint32 aura, float range)
//{
//	NearPlayerList playersNearby;
//	QueryNearPlayerList(range, playersNearby);
//	NearUnitVec enemyPlayers;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (TargetIsStealth(pVisionPlayer))
//				continue;
//			if (aura == 0 || pVisionPlayer->HasAura(aura))
//				enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, false);
//	for (Creature* pCreature : creatures)
//	{
//		if (aura == 0 || pCreature->HasAura(aura))
//			enemyPlayers.push_back(pCreature);
//	}
//	return enemyPlayers;
//}
//
//NearUnitVec BotBGAI::RangeEnemyListByNonAura(uint32 aura, float range)
//{
//	NearUnitVec enemyPlayers;
//	if (aura == 0)
//		return enemyPlayers;
//	NearPlayerList playersNearby;
//	QueryNearPlayerList(range, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (TargetIsStealth(pVisionPlayer))
//				continue;
//			if (!pVisionPlayer->HasAura(aura))
//				enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, false);
//	for (Creature* pCreature : creatures)
//	{
//		if (!pCreature->HasAura(aura))
//			enemyPlayers.push_back(pCreature);
//	}
//	return enemyPlayers;
//}
//
//NearUnitVec BotBGAI::RangeEnemyListByTargetIsMe(float range)
//{
//	NearPlayerList playersNearby;
//	QueryNearPlayerList(range, playersNearby);
//	NearUnitVec enemyPlayers;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (TargetIsStealth(pVisionPlayer))
//				continue;
//			Unit* pUnit = pVisionPlayer->GetSelectedUnit();
//			if (pUnit && pUnit->GetGUID() == me->GetGUID())
//				enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, range, false);
//	for (Creature* pCreature : creatures)
//	{
//		if (pCreature->GetTarget() == me->GetGUID())
//			enemyPlayers.push_back(pCreature);
//	}
//	return enemyPlayers;
//}
//
//NearUnitVec BotBGAI::RangeListByTargetIsTarget(Unit* pTarget, float range)
//{
//	NearPlayerList playersNearby;
//	if (pTarget == me)
//		QueryNearPlayerList(range, playersNearby);
//	else
//		pTarget->GetPlayerListInGrid(playersNearby, range);
//	NearUnitVec enemyPlayers;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (pVisionPlayer->GetTarget() != pTarget->GetGUID())
//			continue;
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (TargetIsStealth(pVisionPlayer))
//				continue;
//			enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(pTarget, creatures, range, true);
//	for (Creature* pCreature : creatures)
//	{
//		if (pCreature->GetTarget() == pTarget->GetGUID())
//			enemyPlayers.push_back(pCreature);
//	}
//	return enemyPlayers;
//}
//
//NearUnitVec BotBGAI::RangeEnemyListByTargetRange(Unit* pTarget, float range)
//{
//	NearPlayerList playersNearby;
//	if (pTarget == me)
//		QueryNearPlayerList(range, playersNearby);
//	else
//		pTarget->GetPlayerListInGrid(playersNearby, range);
//	NearUnitVec enemyPlayers;
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (TargetIsStealth(pVisionPlayer))
//				continue;
//			enemyPlayers.push_back(pVisionPlayer);
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(pTarget, creatures, range, false);
//	for (Creature* pCreature : creatures)
//		enemyPlayers.push_back(pCreature);
//	return enemyPlayers;
//}
//
//NearUnitVec BotBGAI::SearchFarEnemy(float minRange, float maxRange)
//{
//	NearPlayerList playersNearby;
//	NearUnitVec enemyNearby;
//	QueryNearPlayerList(maxRange, playersNearby);
//	for (Player* pVisionPlayer : playersNearby)
//	{
//#ifdef EXCLUDE_PLAYER
//		if (!pVisionPlayer->IsPlayerBot())
//			continue;
//#endif
//		if (TargetIsStealth(pVisionPlayer))
//			continue;
//		if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (me->GetDistance(pVisionPlayer->GetPosition()) > minRange)
//			{
//				enemyNearby.push_back(pVisionPlayer);
//			}
//		}
//	}
//	NearCreatureVec creatures;
//	SearchCreatureListFromRange(me, creatures, maxRange, false);
//	for (Creature* pCreature : creatures)
//	{
//		if (me->GetDistance(pCreature->GetPosition()) > minRange)
//			enemyNearby.push_back(pCreature);
//	}
//	return enemyNearby;
//}
//
//void BotBGAI::UpdateBotAI(uint32 diff)
//{
//	EachTick();
//	if (me->HasUnitState(UNIT_STATE_CASTING))
//	{
//		m_MovetoUseGO.ProcessMovetoUseGO(m_Movement);
//		return;
//	}
//	m_CheckStoped.UpdatePosition(diff);
//
//	ClearMechanicAura();
//	if (!IsNotMovement())
//		ProcessHorror(diff);
//	if (NeedWaitSpecialSpell(BOTAI_UPDATE_TICK))
//		return;
//	if (m_FastAid.TryDoingFastAidForMe())
//		return;
//	if (!me->IsInCombat() && ProcessNormalSpell())
//		return;
//
//	Battleground* pBattleground = me->GetBattleground();
//	BattlegroundStatus bgStatus = pBattleground->GetStatus();
//	if (m_AIBGStateType == BotAIBGState::AIBGState_Ready && bgStatus == BattlegroundStatus::STATUS_WAIT_JOIN)
//	{
//		if (m_InitRndPos.GetPositionZ() != 0)
//		{
//			CommandBG* pBGCommand = pBattleground->GetBgMap()->GetCommander(me->GetTeamId());
//            AIWaypoint* pAIWP;// = pBGCommand ? pBGCommand->GetReadyPosition() : NULL;
//			if (pAIWP)
//				m_InitRndPos = pAIWP->GetPosition();
//			else
//				m_InitRndPos = me->GetPosition();
//			if (me->InArena())
//			{
//				m_InitRndPos = BotAIHorrorState::GetNewHorrorPosByRange(me, 3.0f);
//			}
//			else
//			{
//				float randomOffset = 5.0f;
//				m_InitRndPos.m_positionX += frand(-randomOffset, randomOffset);
//				m_InitRndPos.m_positionY += frand(-randomOffset, randomOffset);
//			}
//			m_Movement->MovementTo(m_InitRndPos.GetPositionX(), m_InitRndPos.GetPositionY(), m_InitRndPos.GetPositionZ());
//			m_InitRndPos.m_positionZ = 0;
//		}
//		else if (me->IsStopped())
//		{
//			if (m_MovetoUseGO.ProcessMovetoUseGO(m_Movement))
//				return;
//			ProcessReady();
//			m_GroupLeader.ProcessGroupLeader();
//		}
//		else
//		{
//			if (m_MovetoUseGO.ProcessMovetoUseGO(m_Movement))
//				return;
//		}
//	}
//	else if (m_AIBGStateType == BotAIBGState::AIBGState_Start && bgStatus == BattlegroundStatus::STATUS_IN_PROGRESS)
//	{
//		BotUtility::TryTeleportPlayerPet(me);
//		m_Movement->SyncPosition(me->GetPosition());
//		if (m_Movement->ExecuteCruxMovementCommand())
//			return;
//		bool inArena = me->InArena();
//		if (!inArena)
//		{
//			if (!me->HasAura(m_UseMountID) && !me->HasUnitState(UNIT_STATE_CASTING))
//				m_UsePotion.TryUsePotion();
//		}
//		else if (TryStartControlCommand())
//			return;
//		Unit* pSelect = GetBotAIValidSelectedUnit();
//		if (pSelect && TargetIsStealth(pSelect->ToPlayer()))
//		{
//			me->SetSelection(ObjectGuid::Empty);
//			if (!me->InArena() && !IsNotMovement())
//				m_Movement->ExecuteMovementCommand();
//		}
//		else if (pSelect && !IsInvincible(pSelect) && !HasAuraMechanic(pSelect, Mechanics::MECHANIC_POLYMORPH))
//		{
//			float distance = me->GetDistance(pSelect->GetPosition());
//			if (distance < BOTAI_SEARCH_RANGE || inArena)
//			{
//				if (m_CurrentTargetTick < BOTAI_MAXTARGET_TICKTIME || inArena)
//				{
//					m_CurrentTargetTick += diff;
//					if (inArena || !NeedDireFlee() || !DoDireFlee())
//					{
//						if (IsHealerBotAI() && HaveManaStore())
//							ProcessHealth();
//						else
//							ProcessCombat(pSelect);
//					}
//					else
//						ProcessFlee();
//				}
//				else
//				{
//					m_Movement->ClearMovement();
//					me->SetSelection(ObjectGuid::Empty);
//				}
//			}
//			else if (distance > BOTAI_SEARCH_RANGE * 1.7f || me->GetMap() != pSelect->GetMap())
//			{
//				//me->StopMoving();
//				me->SetSelection(ObjectGuid::Empty);
//			}
//			else
//			{
//				m_Movement->MovementToTarget();
//			}
//		}
//		else
//		{
//			m_CurrentTargetTick = 0;
//			if (pSelect)
//			{
//				me->AttackStop();
//				//me->SetSelection(ObjectGuid::Empty);
//			}
//			//else
//			//{
//			//	m_MovementTick = 0;
//			//}
//			if (Unit* enemy = SearchEnemy(inArena ? 200 : BOTAI_SEARCH_RANGE))
//			{
//				me->SetSelection(enemy->GetGUID());
//				//me->Attack(enemy, true);
//			}
//			else
//			{
//				me->SetSelection(ObjectGuid::Empty);
//				if (!me->InArena() && !IsNotMovement())
//					m_Movement->ExecuteMovementCommand();
//			}
//		}
//	}
//	else if (m_AIBGStateType == BotAIBGState::AIBGState_Leave)
//	{
//		m_CruxControlTarget = ObjectGuid::Empty;
//		m_LastControlTarget = ObjectGuid::Empty;
//		me->AttackStop();
//		me->SetSelection(ObjectGuid::Empty);
//	}
//}
//
//void BotBGAI::ResetBotAI()
//{
//	PlayerBotSetting::ClearUnknowMount(me);
//	if (m_UseMountID != 0)
//	{
//		if (!me->HasSpell(m_UseMountID))
//			me->LearnSpell(m_UseMountID, false);
//	}
//	m_IsMeleeBot = IsMeleeBotAI();
//	m_IsRangeBot = IsRangeBotAI();
//	m_IsHealerBot = IsHealerBotAI();
//
//	if (!me->IsStandState())
//		me->SetStandState(UNIT_STAND_STATE_STAND);
//
//	BotCommon_ClearAllCtrl = FindMaxRankSpellByExist(59752);
//	if (BotCommon_ClearAllCtrl == 0)
//	{
//		me->LearnSpell(59752, false);
//		BotCommon_ClearAllCtrl = FindMaxRankSpellByExist(59752);
//	}
//	m_CastRecords.ClearRecordSpell();
//	m_FastAid.CheckPlayerFastAid();
//}
//
//bool BotBGAI::IsAlive()
//{
//	return me->IsAlive();
//}
//
//bool BotBGAI::IsNotSelect(Unit* pTarget)
//{
//	if (!pTarget || !pTarget->IsAlive())
//		return true;
//	Player* pPlayer = pTarget->ToPlayer();
//	if (pPlayer)
//	{
//		if (pPlayer->GetVehicleKit())
//			return true;
//		if (pPlayer->GetTeamId() != me->GetTeamId())
//		{
//			if (pPlayer->GetGUID() == m_CruxControlTarget || pPlayer->GetGUID() == m_LastControlTarget)
//				return true;
//		}
//	}
//	if (pTarget->HasAura(27827)) // (27827 救赎之魂 神牧死亡后)
//		return true;
//	return false;
//}
//
//bool BotBGAI::TryUpMount()
//{
//	if (m_AIBGStateType != BotAIBGState::AIBGState_Start)
//		return false;
//	if (me->IsInCombat() || me->GetSelectedUnit() || me->HasAura(m_UseMountID) || me->getLevel() < 20)
//		return false;
//	if (!me->GetMap()->IsOutdoors(me->GetPhaseShift(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
//		return false;
//	if (RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE).size() > 0)
//		return false;
//	if (me->IsMounted())
//		return false;
//	if (me->HasUnitState(UNIT_STATE_CASTING))
//		return false;
//	ObjectGuid& tarGUID = m_Movement->GetTargetObjectID();
//	if (!tarGUID.IsEmpty() && tarGUID.IsGameObject())
//	{
//		if (GameObject* pObject = me->GetMap()->GetGameObject(tarGUID))
//		{
//			if (me->GetPosition().GetExactDist(&pObject->GetPosition()) < NEEDFLEE_CHECKRANGE)
//				return false;
//		}
//	}
//	CommandBG* bgCommander = me->GetMap()->GetCommander(me->GetTeamId());
//	//if (bgCommander && !bgCommander->CanUpMount(me))
//	//	return false;
//	if (!me->InArena())
//	{
//		++m_UpmountTick;
//		if (m_UpmountTick < 3)
//			return false;
//	}
//	m_Movement->ClearMovement();
//	bool okUp = (TryCastSpell(m_UseMountID, me) == SPELL_CAST_OK);
//	if (okUp)
//		m_UpmountTick = 0;
//	return okUp;
//}
//
//void BotBGAI::ProcessHorror(uint32 diff)
//{
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
//		HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED) ||
//		HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
//	{
//		if (!pHorrorState)
//		{
//			pHorrorState = new BotAIHorrorState(me);
//			me->GetMotionMaster()->Clear();
//			m_Movement->ClearMovement();
//			me->UpdatePosition(me->GetPosition(), true);
//			m_Movement->SyncPosition(me->GetPosition(), true);
//			me->SetSelection(ObjectGuid::Empty);
//			return;
//		}
//		pHorrorState->UpdateHorror(diff, m_Movement);
//	}
//	else if (pHorrorState)
//	{
//		delete pHorrorState;
//		pHorrorState = NULL;
//		me->StopMoving();
//	}
//}
//
//bool BotBGAI::TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType)
//{
//	if (!pTarget)
//		return false;
//	if (diType < 1 || diType > 20)
//		return false;
//	DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
//	return diLevel < 1;
//}
//
//bool BotBGAI::TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType)
//{
//	if (!pTarget)
//		return false;
//	if (diType < 1 || diType > 20)
//		return false;
//	DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
//	return diLevel < 2;
//}
//
//bool BotBGAI::HasAuraMechanic(Unit* pTarget, Mechanics mask)
//{
//	if (!pTarget)
//		return false;
//	return (pTarget->HasAuraWithMechanic(1 << mask));
//}
//
//bool BotBGAI::NeedWaitSpecialSpell(uint32 diff)
//{
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM))
//	{
//		me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED))
//	{
//		me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
//	{
//		//me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP))
//	{
//		me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
//	{
//		me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE))
//	{
//		me->StopMoving();
//		//if (BotCommon_ClearAllCtrl)
//		//	TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_KNOCKOUT))
//	{
//		me->StopMoving();
//		//if (BotCommon_ClearAllCtrl)
//		//	TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH))
//	{
//		me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_BANISH))
//	{
//		me->StopMoving();
//		//if (BotCommon_ClearAllCtrl)
//		//	TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR))
//	{
//		//me->StopMoving();
//		if (BotCommon_ClearAllCtrl)
//			TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_SAPPED))
//	{
//		me->StopMoving();
//		//if (BotCommon_ClearAllCtrl)
//		//	TryCastSpell(BotCommon_ClearAllCtrl, me);
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::NeedFlee()
//{
//	return m_NeedFlee.TargetHasFleeAura();
//}
//
//void BotBGAI::FleeMovement()
//{
//	//if (me->IsStopped() && !IsNotMovement())
//	//{
//	//	NearUnitVec& enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
//	//	if (enemys.empty())
//	//		return;
//	//	Unit* selectEnemy = enemys[urand(0, enemys.size() - 1)];
//	//	G3D::Vector3 dir = (me->GetVector3() - selectEnemy->GetVector3()).direction();
//	//	Position targetPos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE * 0.5, selectEnemy->GetRelativeAngle(&me->GetPosition()));
//	//	if ((targetPos.GetVector3() - me->GetVector3()).length() <= 5.0f)
//	//	{
//	//		targetPos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE * 0.5, frand(0.1f, float(M_PI) * 2.0f - 0.1f));
//	//	}
//	//	m_Movement->MovementTo(targetPos.GetPositionX(), targetPos.GetPositionY(), targetPos.GetPositionZ());
//	//}
//	if (/*me->IsStopped() && */!IsNotMovement())
//	{
//		NearUnitVec& enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
//		Unit* selectEnemy = NULL;
//		if (enemys.empty())
//		{
//			selectEnemy = me->GetSelectedUnit();
//			if (!selectEnemy || me->GetDistance(selectEnemy->GetPosition()) > BOTAI_FLEE_JUDGE + 5.0f)
//			{
//				m_Flee.Clear();
//				return;
//			}
//		}
//		if (!selectEnemy && !enemys.empty())
//			selectEnemy = enemys[urand(0, enemys.size() - 1)];
//		m_Flee.UpdateFleeMovementByPVP(selectEnemy, m_Movement);
//	}
//	else
//		m_Flee.Clear();
//}
//
//bool BotBGAI::IsNotMovement()
//{
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
//	{
//		me->StopMoving();
//		return true;
//	}
//	if (IsNotSelect(me))
//	{
//		me->StopMoving();
//		return true;
//	}
//	//if (me->IsStopped())
//		return false;
//	//return true;
//}
//
//bool BotBGAI::IsInvincible(Unit* pTarget)
//{
//	if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
//	{
//		return true;
//	}
//	if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD))
//	{
//		return true;
//	}
//	return false;
//}
//
//uint32 BotBGAI::FindMaxRankSpellByExist(uint32 spellID)
//{
//	if (spellID == 0)
//		return 0;
//    return spellID;
//	uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
//	if (selectSpell == 0)
//	{
//		if (me->HasSpell(spellID))
//			return spellID;
//		return 0;
//	}
//	while (!me->HasSpell(selectSpell))
//	{
//		selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
//		if (selectSpell == 0)
//			return 0;
//	}
//	return selectSpell;
//}
//
//uint32 BotBGAI::FindPetMaxRankSpellByExist(uint32 spellID)
//{
//	if (spellID == 0)
//		return 0;
//	Pet* pPet = me->GetPet();
//	if (!pPet)
//		return 0;
//	uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
//	if (selectSpell == 0)
//	{
//		if (pPet->HasSpell(spellID))
//			return spellID;
//		return 0;
//	}
//	while (!pPet->HasSpell(selectSpell))
//	{
//		selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
//		if (selectSpell == 0)
//			return 0;
//	}
//	return selectSpell;
//}
//
//void BotBGAI::ReadyBattleground()
//{
//	m_AIBGStateType = BotAIBGState::AIBGState_Ready;
//	m_InitRndPos = me->GetPosition();
//}
//
//void BotBGAI::PushFinishQueue(PathParameter* pathParam)
//{
//    return;
//	if (!pathParam)
//		return;
//	std::lock_guard<std::mutex> lock(m_movQueueLock);
//	m_pfFinishQueue.push(pathParam);
//}
//
//bool BotBGAI::CanUseBGObject()
//{
//	if (me->HasAura(27827)) // (27827 救赎之魂 神牧死亡后)
//		return true;
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_BANISH))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_IMMUNE_SHIELD))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_KNOCKOUT))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR))
//	{
//		return false;
//	}
//	if (HasAuraMechanic(me, Mechanics::MECHANIC_SAPPED))
//	{
//		return false;
//	}
//	return true;
//}
//
//bool BotBGAI::IsMeleeBotAI()
//{
//	switch (me->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_PALADIN:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//		return true;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_PRIEST:
//	case CLASS_HUNTER:
//		return false;
//	}
//	return true;
//}
//
//bool BotBGAI::IsRangeBotAI()
//{
//	switch (me->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_PALADIN:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//		return false;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_PRIEST:
//	case CLASS_HUNTER:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::IsHealerBotAI()
//{
//    switch (me->getClass())
//    {
//    case CLASS_WARRIOR:
//    case CLASS_ROGUE:
//    case CLASS_DEATH_KNIGHT:
//    case CLASS_MAGE:
//    case CLASS_WARLOCK:
//    case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//        return false;
//    case CLASS_PALADIN:
//        if (me->GetSpecializationId() == TALENT_SPEC_PALADIN_HOLY)
//            return true;
//    case CLASS_PRIEST:
//        if (me->GetSpecializationId() == TALENT_SPEC_PRIEST_HOLY)
//            return true;
//    case CLASS_SHAMAN:
//        if (me->GetSpecializationId() == TALENT_SPEC_SHAMAN_RESTORATION)
//            return true;
//    case CLASS_DRUID:
//        if (me->GetSpecializationId() == TALENT_SPEC_DRUID_RESTORATION)
//            return true;
//    case CLASS_MONK:
//        if (me->GetSpecializationId() == TALENT_SPEC_MONK_MISTWEAVER)
//            return true;
//    }
//    return false;
//}
//
//Unit* BotBGAI::GetBotAIValidSelectedUnit()
//{
//	Unit* pTarget = me->GetSelectedUnit();
//	bool isValid = true;
//	if (!pTarget)
//		isValid = false;
//	if (isValid && !pTarget->IsVisible())
//		isValid = false;
//	if (isValid && !me->IsInPhase(pTarget))
//		isValid = false;
//	if (isValid && IsNotSelect(pTarget))
//		isValid = false;
//	if (isValid && pTarget->ToCreature() && pTarget->ToCreature()->IsInEvadeMode())
//		isValid = false;
//    if (isValid && pTarget->ToCreature())
//    {
//        if (me->GetDistanceZ(pTarget) > 15.0f && !TargetIsRange(me))
//            isValid = false;
//        if (me->GetDistanceZ(pTarget) > 25.0f && TargetIsRange(me))
//            isValid = false;
//    }
//	if (!isValid)
//	{
//		me->AttackStop();
//		me->SetSelection(ObjectGuid::Empty);
//		return NULL;
//	}
//	return pTarget;
//}
//
//bool BotBGAI::TargetIsControl(Unit* pTarget)
//{
//	if (!pTarget)
//		return false;
//	if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISTRACT) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
//		//HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
//		HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD))
//		return true;
//	return false;
//}
//
//bool BotBGAI::TargetIsMelee(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	switch (pTarget->getClass())
//	{
//	case CLASS_PALADIN:
//		return (pTarget->FindTalentType() != 0);
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//		return true;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_HUNTER:
//	case CLASS_PRIEST:
//	case CLASS_DRUID:
//    case CLASS_MONK:
//		return false;
//	case CLASS_SHAMAN:
//		return (pTarget->FindTalentType() == 1);
//	}
//	return false;
//}
//
//bool BotBGAI::TargetIsRange(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	switch (pTarget->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_PALADIN:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//		return false;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_HUNTER:
//	case CLASS_PRIEST:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::TargetIsMagic(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	switch (pTarget->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//		return false;
//	case CLASS_PALADIN:
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_HUNTER:
//	case CLASS_PRIEST:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::TargetIsHealth(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	switch (pTarget->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//		return false;
//	case CLASS_PALADIN:
//		return (pTarget->FindTalentType() == 0);
//	case CLASS_PRIEST:
//		return (pTarget->FindTalentType() != 2);
//	case CLASS_SHAMAN:
//		return (pTarget->FindTalentType() == 2);
//	case CLASS_DRUID:
//		return (pTarget->FindTalentType() == 2);
//    case CLASS_MONK:
//        return (pTarget->FindTalentType() == 2);
//	}
//	return false;
//}
//
//bool BotBGAI::TargetCanManaBurn(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	uint32 minManaPct = 8;
//	switch (pTarget->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//	case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//		return false;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_PALADIN:
//	case CLASS_PRIEST:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//    case CLASS_MONK:
//		return (TargetManaPCT(pTarget) > minManaPct);
//	}
//	return false;
//}
//
//bool BotBGAI::TargetIsCastMagic(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	switch (pTarget->getClass())
//	{
//	case CLASS_WARRIOR:
//	case CLASS_ROGUE:
//	case CLASS_DEATH_KNIGHT:
//	case CLASS_PALADIN:
//	case CLASS_HUNTER:
//    case CLASS_DEMON_HUNTER:
//    case CLASS_MONK:
//		return false;
//	case CLASS_MAGE:
//	case CLASS_WARLOCK:
//	case CLASS_PRIEST:
//	case CLASS_SHAMAN:
//	case CLASS_DRUID:
//		return true;
//	}
//	return false;
//}
//
//bool BotBGAI::TargetIsStealth(Player* pTarget)
//{
//	if (!pTarget)
//		return false;
//	// (1784 盗贼潜行 || 5215 德鲁伊潜行 || 66 法师隐形 || 58984 暗夜隐遁)
//	if (pTarget->HasAura(1784) || pTarget->HasAura(5215) ||
//		pTarget->HasAura(66) || pTarget->HasAura(58984))
//	{
//		if (!me->CanSeeOrDetect(pTarget, false, true)) // 侦测潜行
//			return true;
//	}
//	return false;
//}
//
//uint32 BotBGAI::TargetManaPCT(Unit* pTarget)
//{
//	if (!pTarget)
//		return 0;
//	float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
//	return (uint32)(per * 100);
//}
//
//bool BotBGAI::IsSelfFaction(Unit* pTarget, uint32 faction)
//{
//	if (!pTarget)
//		return false;
//	if (pTarget->ToPlayer())
//	{
//		if (pTarget->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
//		{
//			if (faction == c_Alliance_Faction)
//				return true;
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(1))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(3))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(4))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(7))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(11))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//		}
//		else
//		{
//			if (faction == c_Horde_Faction)
//				return true;
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(2))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(5))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(6))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(8))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//			if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(10))
//			{
//				if (rEntry->FactionID == faction)
//					return true;
//			}
//		}
//	}
//	else if (pTarget->ToCreature())
//	{
//		if (faction == c_Alliance_Faction && pTarget->GetFaction() == c_Alliance_Faction)
//			return true;
//		if (faction == c_Horde_Faction && pTarget->GetFaction() == c_Horde_Faction)
//			return true;
//	}
//	return false;
//}
//
//bool BotBGAI::IsFilterCreatureByEntry(uint32 entry)
//{
//	if (m_FilterCreatureEntrys.find(entry) != m_FilterCreatureEntrys.end())
//		return true;
//	//for (uint32 ids : m_FilterCreatureEntrys)
//	//{
//	//	if (ids == entry)
//	//		return true;
//	//}
//	return false;
//}
//
//bool BotBGAI::IsFleeTargetByRangeBot(Unit* pTarget)
//{
//	if (!pTarget || !pTarget->ToPlayer())
//		return false;
//	if (me->getClass() == Classes::CLASS_HUNTER)
//		return true;
//	if (pTarget->GetTarget() != me->GetGUID())
//		return false;
//	if (IsHealerBotAI())
//	{
//		if (BeforeSearchNeedHealth(BOTAI_SEARCH_RANGE * 3, 70).size() > 0)
//			return false;
//	}
//	if (BotBGAI* pBotAI = dynamic_cast<BotBGAI*>(pTarget->GetAI()))
//	{
//		if (!pBotAI->IsMeleeBotAI())
//			return false;
//		return true;
//	}
//	else if (!pTarget->IsPlayerBot())
//	{
//		Player* player = pTarget->ToPlayer();
//		Classes cls = Classes(player->getClass());
//		switch (cls)
//		{
//		case CLASS_PALADIN:
//			return (player->FindTalentType() == 2);
//		case CLASS_WARRIOR:
//		case CLASS_ROGUE:
//		case CLASS_DEATH_KNIGHT:
//        case CLASS_DEMON_HUNTER:
//			return true;
//		case CLASS_MAGE:
//		case CLASS_WARLOCK:
//		case CLASS_PRIEST:
//		case CLASS_HUNTER:
//			return false;
//		case CLASS_SHAMAN:
//			return (player->FindTalentType() == 1);
//		case CLASS_DRUID:
//			return (player->FindTalentType() == 1);
//        case CLASS_MONK:
//            return (player->FindTalentType() == 2);
//		}
//	}
//	return false;
//}
//
//void BotBGAI::QueryNearCreatureList(float range, NearCreatureList& creatureList)
//{
//	std::map<float, NearCreatureList>::iterator itMap = m_RangeCreatureLists.find(range);
//	if (itMap != m_RangeCreatureLists.end())
//	{
//		creatureList = itMap->second;
//		return;
//	}
//
//	NearCreatureList& nearCreature = m_RangeCreatureLists[range];
//	Trinity::AllWorldObjectsInRange checker(me, range);
//	Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, nearCreature, checker);
//    Cell::VisitGridObjects(me, searcher, range);
//	creatureList = m_RangeCreatureLists[range];
//}
//
//void BotBGAI::QueryNearPlayerList(float range, NearPlayerList& playerList)
//{
//	std::map<float, NearPlayerList>::iterator itMap = m_RangePlayerLists.find(range);
//	if (itMap != m_RangePlayerLists.end())
//	{
//		playerList = itMap->second;
//		return;
//	}
//
//	NearPlayerList& nearPlayer = m_RangePlayerLists[range];
//	me->GetPlayerListInGrid(nearPlayer, range);
//	playerList = m_RangePlayerLists[range];
//}
