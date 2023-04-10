
#include "BotFieldAI.h"
#include "MoveSplineInit.h"
#include "BotBGAIMovement.h"
#include "PlayerBotMgr.h"
#include "FieldBotMgr.h"
#include "PlayerBotSession.h"
#include "Spell.h"
#include "Pet.h"
#include "BotFieldClassAI.h"
#include "Group.h"
#include "WorldSession.h"
#include "PartyPackets.h"
#include "MiscPackets.h"
#include "CharmInfo.h"
#include <corecrt_math_defines.h>

BotFieldAI* BotFieldAI::debugFieldAI = NULL;

BotFieldAI* BotFieldAI::CreateBotFieldAIByPlayerClass(Player* player)
{
    PlayerBotSetting::ClearUnknowMount(player);
    BotFieldAI* pAI = NULL;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
        pAI = new FieldWarriorAI(player);
        break;
    case CLASS_MAGE:
        pAI = new FieldMageAI(player);
        break;
    case CLASS_PRIEST:
        pAI = new FieldPriestAI(player);
        break;
    case CLASS_HUNTER:
        pAI = new FieldHunterAI(player);
        break;
    case CLASS_WARLOCK:
        pAI = new FieldWarlockAI(player);
        break;
    case CLASS_PALADIN:
        pAI = new FieldPaladinAI(player);
        break;
    case CLASS_ROGUE:
        pAI = new FieldRogueAI(player);
        break;
    case CLASS_SHAMAN:
        pAI = new FieldShamanAI(player);
        break;
    case CLASS_DRUID:
        pAI = new FieldDruidAI(player);
        break;
    case CLASS_DEATH_KNIGHT:
        pAI = new FieldDeathknightAI(player);
        break;
    }
    if (!pAI)
        pAI = new BotFieldAI(player);
    pAI->ResetBotAI();
    return pAI;
}

BotFieldAI::BotFieldAI(Player* player) :
    PlayerAI(player),
    m_UpdateTick(BOTAI_UPDATE_TICK),
    m_DrivingPVP(false),
    m_Movement(new BotBGAIMovement(player, this)),
    m_UseMountID(PlayerBotSetting::RandomMountByLevel(player->getLevel())),
    m_WarfareTargetID(ObjectGuid::Empty),
    m_Guild(player),
    pHorrorState(NULL),
    m_CheckStoped(player),
    m_Teleporting(player),
    m_UseFood(player),
    m_UsePotion(player),
    m_FindLoot(player),
    m_AITrade(player),
    m_Revive(player),
    m_Flee(player),
    m_IDLE(player),
    m_CruxMovement(player),
    m_WishStore(player),
    m_CheckSetting(player),
    m_CastRecords(player),
    m_CheckDuel(player),
    m_HasReset(false)
{
    if (!me->IsPvP())
    {
        BotUtility::PlayerBotTogglePVP(player, true);
    }
}

BotFieldAI::~BotFieldAI()
{

}

void BotFieldAI::UpdateAI(uint32 diff)
{
    m_UpdateTick -= diff;
    if (m_UpdateTick > 0)
        return;
    m_UpdateTick = BOTAI_UPDATE_TICK;

    if (!me->IsSettingFinish())
        return;
    UpdateTeleport(BOTAI_UPDATE_TICK);
    if (!m_Teleporting.CanMovement())
        return;
    me->UpdateObjectVisibility(false);
    m_Guild.UpdateGuildProcess();
    if (ProcessGroupInvite())
        return;
    if (IsBGSchedule())
    {
        BotUtility::TryTeleportHome(this);
        return;
    }

    if (!m_HasReset)
        ResetBotAI();
    if (me->IsAlive())
    {
        m_CheckStoped.UpdatePosition(diff);
        BotUtility::TryTeleportPlayerPet(me);
        ClearMechanicAura();
        if (!IsNotMovement())
            ProcessHorror(diff);
        if (NeedWaitSpecialSpell(BOTAI_UPDATE_TICK))
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        if (!m_CruxMovement.HasCruxMovement() && NonCombatProcess())
            return;

        if (!me->IsInCombat() && ProcessNormalSpell())
            return;
        //m_Movement->SyncPosition(me->GetPosition());
        if (TryUpMount())
            return;
        if (!me->HasAura(m_UseMountID) && !me->HasUnitState(UNIT_STATE_CASTING))
            m_UsePotion.TryUsePotion();
        if (me->IsInCombat())
            UpEnergy();
        Unit* pTarget = GetBotAIValidSelectedUnit();
        if (m_CruxMovement.HasCruxMovement())
        {
            m_CruxMovement.UpdateCruxMovement(m_Movement);
        }
        else if (pTarget && pTarget->IsAlive() && !IsInvincible(pTarget))
        {
            float distance = me->GetDistance(pTarget->GetPosition());
            if (distance < BOTAI_SEARCH_RANGE)
            {
                if (IsHealerBotAI() && me->getLevel() >= 10)
                    ProcessHealth();
                else
                    ProcessCombat(pTarget);
            }
            else if (distance > BOTAI_SEARCH_RANGE * 2.5f || me->GetMap() != pTarget->GetMap())
            {
                //me->StopMoving();
                me->SetSelection(ObjectGuid::Empty);
            }
            else
            {
                m_Movement->MovementToTarget();
            }
        }
        else if (pTarget = GetCombatTarget())
        {
            me->AttackStop();
            me->SetSelection(pTarget->GetGUID());
        }
        else
        {
            me->SetSelection(ObjectGuid::Empty);
            ProcessIDLE();
        }
    }
    else
    {
        m_CastRecords.ClearRecordSpell();
        m_WishStore.ClearStores();
        m_CruxMovement.ClearMovement();
        me->SetSelection(ObjectGuid::Empty);
        m_Revive.UpdateRevive(BOTAI_UPDATE_TICK, m_Teleporting);
    }
}

void BotFieldAI::ResetBotAI()
{
    PlayerBotSetting::ClearUnknowMount(me);
    m_Movement->ClearMovement();
    if (m_UseMountID != 0)
    {
        if (!me->HasSpell(m_UseMountID))
            me->LearnSpell(m_UseMountID, false);
    }
    m_IsMeleeBot = IsMeleeBotAI();
    m_IsRangeBot = IsRangeBotAI();
    m_IsHealerBot = IsHealerBotAI();
    m_HasReset = true;

    m_CastRecords.ClearRecordSpell();
}

void BotFieldAI::SetDrivingPVP(bool driving)
{
    if (m_DrivingPVP != driving)
    {
        m_DrivingPVP = driving;
        me->SetSelection(ObjectGuid::Empty);
        me->CombatStop(true);
    }
}

void BotFieldAI::SetWarfareTarget(Unit* pTarget)
{
    if (pTarget)
        m_WarfareTargetID = pTarget->GetGUID();
    else
        m_WarfareTargetID = ObjectGuid::Empty;
}

void BotFieldAI::SetCruxMovement(Position& pos)
{
    me->SetSelection(ObjectGuid::Empty);
    m_CruxMovement.SetMovement(pos);
}

bool BotFieldAI::ProcessGroupInvite()
{
    if (Group* pGroup = me->GetGroup())
    {
        //if (pGroup->isLFGGroup())
        {
            m_Movement->ClearMovement();
            PlayerBotMgr::SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_GROUP, true);
            return true;
        }
        //return false;
    }
    WorldSession* pWorldSession = me->GetSession();
    if (!pWorldSession)
        return false;
    PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
    if (!pSession || pSession->HasSchedules())
        return false;
    if (me->IsInWorld() && me->GetMap()->IsDungeon())
    {
        BotUtility::TryTeleportHome(this);
        return true;
    }
    Group* pGroup = me->GetGroupInvite();
    if (!pGroup)
        return false;
    WorldPacket opcode(CMSG_PARTY_INVITE_RESPONSE);
    if (pSession->HasSchedules() || me->InBattleground())
    {
        WorldPackets::Party::PartyInviteResponse packet(std::move(opcode));
        packet.Accept = 0;
        //pWorldSession->HandlePartyInviteResponse(packet);
    }
    else
    {
        WorldPackets::Party::PartyInviteResponse packet(std::move(opcode));
        packet.Accept = 1;
        //pWorldSession->HandlePartyInviteResponse(packet);
        m_Movement->ClearMovement();
        PlayerBotMgr::SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_GROUP, true);
    }
    return true;
}

bool BotFieldAI::IsNotSelect(Unit* pTarget)
{
    if (!pTarget || !pTarget->IsAlive())
        return true;
    if (pTarget->HasAura(27827)) // (27827 救赎之魂 神牧死亡后)
        return true;
    return false;
}

bool BotFieldAI::IsIDLEBot()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    if (me->IsInCombat() || !me->IsAlive())
        return false;
    if (!m_Teleporting.CanMovement())
        return false;
    if (m_UseFood.HasFoodState())
        return false;
    if (m_FindLoot.HasLoot())
        return false;

    return true;
}

bool BotFieldAI::TryUpMount()
{
    if (me->IsInCombat() || me->GetSelectedUnit() || me->HasAura(m_UseMountID) || me->getLevel() < 20)
        return false;
   /* if (!me->GetMap()->IsOutdoors(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
        return false;*/
    if (me->IsMounted())
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    m_Movement->ClearMovement();
    return (TryCastSpell(m_UseMountID, me) == SPELL_CAST_OK);
}

void BotFieldAI::Dismount()
{
    if (!me->HasAura(m_UseMountID))
        return;
    me->RemoveOwnedAura(m_UseMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
}

void BotFieldAI::ProcessHorror(uint32 diff)
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
    {
        if (!pHorrorState)
        {
            pHorrorState = new BotAIHorrorState(me);
            me->GetMotionMaster()->Clear();
            m_Movement->ClearMovement();
            me->UpdatePosition(me->GetPosition(), true);
            //m_Movement->SyncPosition(me->GetPosition(), true);
            me->SetSelection(ObjectGuid::Empty);
        }
        pHorrorState->UpdateHorror(diff, m_Movement);
    }
    else if (pHorrorState)
    {
        delete pHorrorState;
        pHorrorState = NULL;
        m_Movement->ClearMovement();
    }
}

bool BotFieldAI::HasAuraMechanic(Unit* pTarget, Mechanics mask)
{
    if (!pTarget)
        return false;
    return (pTarget->HasAuraWithMechanic(1i64 << mask));
}

bool BotFieldAI::IsNotMovement()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
    {
        me->StopMoving();
        return true;
    }
    if (IsNotSelect(me))
    {
        me->StopMoving();
        return true;
    }
    //if (me->IsStopped())
    return false;
    //return true;
}

bool BotFieldAI::IsInvincible(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
    {
        return true;
    }
    //if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD))
    //{
    //	return true;
    //}
    return false;
}

bool BotFieldAI::IsBGSchedule()
{
    if (me->GetSession()->HasBGSchedule() || me->InBattleground() || me->isUsingLfg())
        return true;
    return false;
}

bool BotFieldAI::CanSelectPlayerEnemy(Player* player)
{
    if (!player || player->GetTeamId() == me->GetTeamId() || IsNotSelect(player))
        return false;
    if (!m_DrivingPVP && !FieldBotMgr::FIELDBOT_DRIVING && !player->IsPvP())
        return false;
    if (TargetIsStealth(player))
        return false;
    if (m_DrivingPVP || FieldBotMgr::FIELDBOT_DRIVING)
    {
        return true;
    }
    else
    {
        Player* pTarget = player->GetSelectedPlayer();
        if (!pTarget)
            return false;
        if (pTarget->GetTeamId() == me->GetTeamId())
        {
            return true;
        }
    }
    return false;
}

Unit* BotFieldAI::GetCombatTarget(float range)
{
    NearUnitVec validTarget;
    NearPlayerList playersNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (CanSelectPlayerEnemy(pVisionPlayer))
            validTarget.push_back(pVisionPlayer);
    }
    bool hasPlayerEnemy = validTarget.empty() ? false : true;
    if (!hasPlayerEnemy)
    {
        NearCreatureVec creatures;
        SearchCreatureListFromRange(me, creatures, range, false);
        for (Creature* pCreature : creatures)
        {
            if (hasPlayerEnemy)
            {
                ObjectGuid guid = pCreature->GetTarget();//GetTargetGUID
                if (guid == ObjectGuid::Empty)
                    continue;
                if (guid != me->GetGUID())
                    continue;
            }
            validTarget.push_back(pCreature);
        }
    }
    if (validTarget.empty())
        return NULL;
    return validTarget[urand(0, validTarget.size() - 1)];
}

bool BotFieldAI::NonCombatProcess()
{
    {
        std::lock_guard<std::mutex> lock(m_ItemLock);
        if (m_CheckDuel.CheckDuel())
            sPlayerBotMgr->SwitchPlayerBotAI(me, PlayerBotAIType::PBAIT_DUEL, true);
        m_CheckSetting.UpdateCheckSetting();
        //m_Guild.UpdateGuildProcess();
        if (m_AITrade.ProcessTrade())
            return true;
        if (m_UseFood.UpdateBotFood(BOTAI_UPDATE_TICK, m_UseMountID))
            return true;
        if (m_FindLoot.DoFindLoot(BOTAI_UPDATE_TICK, m_Movement, m_UseMountID))
            return true;
        //if (ProcessGroupInvite())
        //	return true;
        m_WishStore.UpdateWishStore();
    }
    return false;
}

bool BotFieldAI::DoFaceToTarget(Unit* pTarget)
{
    float relative = me->GetRelativeAngle(pTarget->GetPositionX(), pTarget->GetPositionY());
    if (relative >= M_PI_2 && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
    {
        //me->SetInFront(pTarget);
        //me->SetFacingToObject(pTarget);
        Movement::MoveSplineInit init(me);
        //init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
        init.SetFacing(pTarget);
        init.SetOrientationFixed(true);
        init.Launch();
        return true;
    }
    return false;
}

SpellCastResult BotFieldAI::TryCastSpell(uint32 spellID, Unit* pTarget, bool /*force*/, bool dismount)
{
    if (!spellID || !me->HasSpell(spellID))
    {
        if (spellID)
            SetResetAI();
        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
    }
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    if (!m_WishStore.CanWishStore(spellID, pTarget))
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    /*TriggerCastData data;
    data.triggerFlags = force ? TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM) : TriggerCastFlags::TRIGGERED_NONE;
    Spell* spell = new Spell(me, spellInfo, data);
    spell->m_CastItem = NULL;
    SpellCastTargets targets;
    targets.SetUnitTarget(pTarget);*/
    //spell->InitExplicitTargets(targets);
    //SpellCastResult castResult = spell->CheckCast(true);
    //if (castResult != SpellCastResult::SPELL_CAST_OK)
    //{
    //	spell->finish(false);
    //	delete spell;
    //	return castResult;
    //}
    if (dismount)
        Dismount();
    //SpellCastResult castResult = spell->prepare(targets);
    //if (castResult != SpellCastResult::SPELL_CAST_OK)
    //{
    //    if (castResult == SpellCastResult::SPELL_FAILED_NOT_MOUNTED)
    //        PlayerBotSetting::ClearUnknowMount(me);
    //    else if (castResult == SpellCastResult::SPELL_FAILED_BAD_TARGETS)
    //    {
    //        if (pTarget && me->GetTarget() == pTarget->GetGUID())
    //            me->SetTarget(ObjectGuid::Empty);
    //        if (pTarget && pTarget->ToPlayer() && !pTarget->IsPlayerBot() && !pTarget->IsPvP())
    //        {
    //            WorldPacket opcode(CMSG_TOGGLE_PVP);
    //            WorldPackets::Misc::TogglePvP packet(std::move(opcode));
    //            pTarget->ToPlayer()->GetSession()->HandleTogglePvP(packet);
    //        }
    //    }
    //    //spell->finish(false);
    //    //delete spell;
    //    return castResult;
    //}
    m_WishStore.TryWishStore(spellID, pTarget);
    return SpellCastResult::SPELL_CAST_OK;
}

SpellCastResult BotFieldAI::TryCastPullSpell(uint32 spellID, Unit* /*pTarget*/)
{
    if (!spellID || !me->HasSpell(spellID))
        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_40);
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    //TriggerCastData data;
    //data.triggerFlags = TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
    //Spell* spell = new Spell(me, spellInfo, data);
    //spell->m_CastItem = NULL;
    //SpellCastTargets targets;
    //targets.SetUnitTarget(pTarget);
    //spell->InitExplicitTargets(targets);
    //SpellCastResult castResult = spell->CheckCast(true);
    //if (castResult != SpellCastResult::SPELL_CAST_OK)
    //{
    //	spell->finish(false);
    //	delete spell;
    //	return castResult;
    //}
    Dismount();
    //SpellCastResult castResult = spell->prepare(targets);
    //if (castResult != SpellCastResult::SPELL_CAST_OK)
    //{
    //    //spell->finish(false);
    //    //delete spell;
    //    return castResult;
    //}
    return SpellCastResult::SPELL_CAST_OK;
}

SpellCastResult BotFieldAI::PetTryCastSpell(uint32 spellID, Unit* /*pTarget*/, bool /*force*/)
{
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    if (!spellID || !pPet->HasSpell(spellID))
        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_40);
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    /*TriggerCastData data;
    Spell* spell = new Spell(pPet, spellInfo, data);
    pTarget = pTarget ? pTarget : pPet;
    SpellCastResult castResult = spell->CheckPetCast(pTarget);*/
    //if (castResult == SPELL_FAILED_UNIT_NOT_INFRONT && !pPet->isPossessed() && !pPet->IsVehicle())
    //{
    //    if (pTarget && pTarget != pPet)
    //    {
    //        pPet->SetInFront(pTarget);
    //        if (Player* player = pTarget->ToPlayer())
    //            pPet->SendUpdateToPlayer(player);
    //    }
    //    else if (Unit* unit_target2 = spell->m_targets.GetUnitTarget())
    //    {
    //        pPet->SetInFront(unit_target2);
    //        if (Player* player = unit_target2->ToPlayer())
    //            pPet->SendUpdateToPlayer(player);
    //    }

    //    if (Unit* powner = pPet->GetCharmerOrOwner())
    //        if (Player* player = powner->ToPlayer())
    //            pPet->SendUpdateToPlayer(player);

    //    castResult = SPELL_CAST_OK;
    //}
    //if (castResult == SPELL_CAST_OK)
    //{
    //    pTarget = spell->m_targets.GetUnitTarget();

    //    //10% chance to play special pet attack talk, else growl
    //    //actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
    //    if (pPet->IsPet() && (((Pet*)pPet)->getPetType() == SUMMON_PET) && (pPet != pTarget) && (urand(0, 100) < 10))
    //        pPet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
    //    else
    //    {
    //        pPet->SendPetAIReaction(me->GetPetGUID());
    //    }

    //    if (pTarget && !pPet->isPossessed() && !pPet->IsVehicle())
    //    {
    //        // This is true if pet has no target or has target but targets differs.
    //        if (pPet->GetVictim() != pTarget)
    //        {
    //            if (pPet->GetVictim())
    //                pPet->AttackStop();
    //            pPet->GetMotionMaster()->Clear();
    //            if (pPet->ToCreature()->IsAIEnabled())
    //                pPet->ToCreature()->AI()->AttackStart(pTarget);
    //        }
    //    }

    //    return spell->prepare(spell->m_targets);
    //}
    //else
    {
        //spell->SendCastResult(me, spellInfo, castResult);

        /*if (!pPet->HasSpellCooldown(spellID))
            pPet->RemoveCreatureSpellCooldown(spellID);*/

        //spell->finish();
        //delete spell;

        // reset specific flags in case of spell fail. AI will reset other flags
        if (pPet->GetCharmInfo())
            pPet->GetCharmInfo()->SetIsCommandAttack(false);
    }

    //return castResult;
    SpellCastResult castResult = SPELL_CAST_OK;
    return castResult;//I
}

void BotFieldAI::SettingPetAutoCastSpell(uint32 spellID, bool autoCast)
{
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return;
    if (!spellID || !pPet->HasSpell(spellID))
        return;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, DIFFICULTY_40);
    if (!spellInfo || spellInfo->IsPassive() || !spellInfo->IsAutocastable())
        return;
    CharmInfo* charmInfo = pPet->GetCharmInfo();
    if (!charmInfo)
        return;
    if (pPet->IsPet())
        pPet->ToggleAutocast(spellInfo, autoCast);
    else
        pPet->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, autoCast);

    charmInfo->SetSpellAutocast(spellInfo, autoCast);
}

bool BotFieldAI::NeedWaitSpecialSpell(uint32 /*diff*/)
{
    if (IsNotSelect(me))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
    {
        //me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE))
    {
        me->StopMoving();
        return true;
    }
    //if (HasAuraMechanic(me, Mechanics::MECHANIC_KNOCKOUT))
    //{
    //	me->StopMoving();
    //	return true;
    //}
    if (HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_BANISH))
    {
        me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR))
    {
        //me->StopMoving();
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_SAPPED))
    {
        me->StopMoving();
        return true;
    }
    return false;
}

bool BotFieldAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (IsMeleeBotAI())
    {
        if (me->GetHealthPct() < 25)
            return true;
    }
    return false;
}

void BotFieldAI::FleeMovement()
{
    if (/*me->IsStopped() && */!IsNotMovement())
    {
        NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
        Unit* selectEnemy = NULL;
        if (enemys.empty())
        {
            selectEnemy = me->GetSelectedUnit();
            if (!selectEnemy || me->GetDistance(selectEnemy->GetPosition()) > BOTAI_FLEE_JUDGE + 5.0f)
            {
                m_Flee.Clear();
                return;
            }
        }
        if (!selectEnemy && !enemys.empty())
            selectEnemy = enemys[urand(0, enemys.size() - 1)];
        m_Flee.UpdateFleeMovementByPVP(selectEnemy, m_Movement);
    }
    else
        m_Flee.Clear();
}

void BotFieldAI::ProcessFlee()
{
    FleeMovement();
}

void BotFieldAI::ProcessIDLE()
{
    if (!ProcessWarfare())
        m_IDLE.UpdateIDLEMovement(m_Movement);
    else
        m_IDLE.Clear();
}

void BotFieldAI::ProcessHealth()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    NearUnitVec needHealth = SearchNeedHealth(BOTAI_SEARCH_RANGE * 1.5);
    if (needHealth.empty())
    {
        ProcessCombat(me->GetSelectedUnit());
        return;
    }
    Unit* healthPlayer = needHealth[urand(0, needHealth.size() - 1)];
    bool inView = me->IsWithinLOSInMap(healthPlayer);
    if (inView)
    {
        if (me->GetDistance(healthPlayer) > BOTAI_RANGESPELL_DISTANCE - 3)
        {
            if (!IsNotMovement())
                m_Movement->MovementTo(healthPlayer->GetPositionX(), healthPlayer->GetPositionY(), healthPlayer->GetPositionZ());
            return;
        }
        else
        {
            m_Movement->ClearMovement();
            me->SetInFront(healthPlayer);
            //me->SetFacingToObject(healthPlayer);
            ProcessHealthSpell(healthPlayer);
            return;
        }
    }
    else if (!IsNotMovement())
    {
        m_Movement->MovementTo(healthPlayer->GetGUID());
        return;
    }
    if (NeedFlee())
    {
        ProcessFlee();
        return;
    }
}

void BotFieldAI::ProcessCombat(Unit* pTarget)
{
    if (!pTarget)
        return;
    if (TargetIsStealth(pTarget->ToPlayer()))
    {
        me->SetSelection(ObjectGuid::Empty);
        return;
    }
    bool inView = me->IsWithinLOSInMap(pTarget);
    if (inView)
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        if (m_IsRangeBot)
        {
            if (NeedFlee())
            {
                Unit* pVictim = me->GetVictim();
                if (!pVictim || pVictim != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->Attack(pTarget, true);
                ProcessFlee();
                if (!IsNotSelect(pTarget))
                    ProcessMeleeSpell(pTarget);
            }
            else if (me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE)
            {
                Unit* pVictim = me->GetVictim();
                if (!pVictim || pVictim != pTarget)
                    me->Attack(pTarget, false);
                if (!IsNotSelect(pTarget))// && !DoFaceToTarget(pTarget))
                {
                    me->SetInFront(pTarget);
                    me->SetFacingToObject(pTarget);
                    if (me->getClass() != Classes::CLASS_HUNTER)
                        m_Movement->ClearMovement();
                    ChaseTarget(pTarget, false, BOTAI_RANGESPELL_DISTANCE);
                    ProcessRangeSpell(pTarget);
                    if (!me->HasUnitState(UNIT_STATE_CASTING))
                        DoRangedAttackIfReady();
                }
            }
            else if (!IsNotMovement())
            {
                m_Movement->MovementToTarget();
            }
        }
        else
        {
            if (me->IsWithinMeleeRange(pTarget))
            {
                me->SetInFront(pTarget);
                me->SetFacingToObject(pTarget);
                //if (!DoFaceToTarget(pTarget))
                {
                    Unit* pVictim = me->GetVictim();
                    if (!pVictim || pVictim != pTarget)
                        me->Attack(pTarget, true);
                    if (!IsNotMovement())
                        ChaseTarget(pTarget, true);
                    if (!IsNotSelect(pTarget))
                        ProcessMeleeSpell(pTarget);
                }
            }
            else
            {
                if (!IsNotMovement())
                    m_Movement->MovementToTarget();
                if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE && pTarget->IsAlive() && !me->IsVehicle())
                {
                    ProcessRangeSpell(pTarget);
                }
            }
        }
    }
    else if (!IsNotMovement())
        m_Movement->MovementToTarget();
}

bool BotFieldAI::ProcessWarfare()
{
    if (m_WarfareTargetID != ObjectGuid::Empty)
    {
        Player* pTarget = ObjectAccessor::FindPlayer(m_WarfareTargetID);
        if (pTarget)
        {
            if (pTarget->GetMapId() == me->GetMapId() && !pTarget->InBattleground())
            {
                if (me->GetDistance(pTarget->GetPosition()) > BOTAI_RANGESPELL_DISTANCE)
                {
                    m_Movement->MovementTo(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 20);
                    return true;
                }
            }
        }
        else
        {
            SetWarfareTarget(NULL);
            return false;
        }
    }
    return false;
}

void BotFieldAI::ChaseTarget(Unit* pTarget, bool isMelee, float range)
{
    if (IsNotSelect(pTarget))
        return;
    if (isMelee && pTarget->ToPlayer())
    {
        if (me->IsStopped())
        {
            Position targetPos = pTarget->GetPosition();
            float rndOffset = frand(-float(M_PI_4) * 0.75f, float(M_PI_4) * 0.75f);
            Position pos = me->GetFirstCollisionPosition(me->GetDistance(targetPos) + range, me->GetRelativeAngle(&targetPos) + rndOffset);
            m_Movement->MovementTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
            //me->GetMotionMaster()->MovePoint(0, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        }
    }
    else
    {
        //if (me->isInBack(pTarget) && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
        //{
        //	Movement::MoveSplineInit init(me);
        //	init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
        //	init.SetFacing(pTarget);
        //	init.SetOrientationFixed(true);
        //	init.Launch();
        //}
        //else// if (!IsNotMovement())
        if (me->GetDistance(pTarget->GetPosition()) > range)
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(pTarget, range);
        }
        else
            m_Movement->ClearMovement();
    }
}

void BotFieldAI::SearchCreatureListFromRange(Unit* center, NearCreatureVec& nearCreatures, float range, bool selfFaction)
{
    NearCreatureList nearCreature;
    Trinity::AllWorldObjectsInRange checker(center, range);
    Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(center, nearCreature, checker);
    //center->VisitNearbyGridObject(range, searcher);
    for (Creature* pCreature : nearCreature)
    {
        if (!pCreature->IsAlive() || pCreature->IsPet())// || pCreature->IsTotem())
            continue;
        if (pCreature->IsInEvadeMode())
            continue;
        if (selfFaction && me->IsValidAttackTarget(pCreature))
            continue;
        if (!selfFaction && !me->IsValidAttackTarget(pCreature))
            continue;
        if (FieldBotMgr::FIELDBOT_CREATURE || selfFaction)
        {
            nearCreatures.push_back(pCreature);
        }
        else if (!selfFaction)
        {
            ObjectGuid targetGUID = pCreature->GetTarget();
            if (targetGUID != ObjectGuid::Empty)
                nearCreatures.push_back(pCreature);
        }
    }
}

NearUnitVec BotFieldAI::SearchFriend(float range)
{
    NearPlayerList playersNearby;
    NearUnitVec friendNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
        {
            friendNearby.push_back(pVisionPlayer);
        }
    }
    //NearCreatureVec creatures;
    //SearchCreatureListFromRange(me, creatures, range, true);
    //for (Creature* pCreature : creatures)
    //	friendNearby.push_back(pCreature);
    return friendNearby;
}

NearPlayerVec BotFieldAI::SearchFarFriend(float minRange, float maxRange, bool isIDLE)
{
    NearPlayerList playersNearby;
    NearPlayerVec friendNearby;
    me->GetPlayerListInGrid(playersNearby, maxRange);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
        {
            if (me->GetDistance(pVisionPlayer->GetPosition()) > minRange)
            {
                if (isIDLE)
                {
                    if (pVisionPlayer->GetSelectedUnit() == NULL || !pVisionPlayer->IsInCombat())
                        friendNearby.push_back(pVisionPlayer);
                }
                else
                    friendNearby.push_back(pVisionPlayer);
            }
        }
    }
    return friendNearby;
}

NearPlayerVec BotFieldAI::ExistFriendAttacker(float range /* = BOTAI_RANGESPELL_DISTANCE */)
{
    NearPlayerList playersNearby;
    NearPlayerVec friendNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId() && IsAttacker())
        {
            friendNearby.push_back(pVisionPlayer);
        }
    }

    return friendNearby;
}

NearUnitVec BotFieldAI::SearchNeedHealth(float range /* = BOTAI_SEARCH_RANGE */)
{
    NearPlayerList playersNearby;
    NearUnitVec lifeTo25, life25To55, life55To80;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
        {
            float healthPct = pVisionPlayer->GetHealthPct();
            if (healthPct < 25)
                lifeTo25.push_back(pVisionPlayer);
            else if (healthPct >= 25 && healthPct < 55)
                life25To55.push_back(pVisionPlayer);
            else if (healthPct >= 55 && healthPct < 80)
                life55To80.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, range, true);
    for (Creature* pCreature : creatures)
    {
        float healthPct = pCreature->GetHealthPct();
        if (healthPct < 25)
            lifeTo25.push_back(pCreature);
        else if (healthPct >= 25 && healthPct < 55)
            life25To55.push_back(pCreature);
        else if (healthPct >= 55 && healthPct < 80)
            life55To80.push_back(pCreature);
    }

    uint32 rate = urand(0, 99);
    if (rate >= 85 && life55To80.size() > 0)
        return life55To80;
    else if (rate < 85 && rate >= 55 && life25To55.size() > 0)
        return life25To55;
    else if (lifeTo25.size() > 0)
        return lifeTo25;
    else if (life25To55.size() > 0)
        return life25To55;
    return life55To80;
}

NearUnitVec BotFieldAI::SearchLifePctByFriendRange(Unit* pTarget, float lifePct, float range /* = NEEDFLEE_CHECKRANGE */)
{
    NearPlayerList playersNearby;
    NearUnitVec lifePctPlayers;
    pTarget->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
        {
            float healthPct = pVisionPlayer->GetHealthPct();
            if (healthPct <= lifePct)
                lifePctPlayers.push_back(pVisionPlayer);
        }
    }
    //NearCreatureVec creatures;
    //SearchCreatureListFromRange(me, creatures, range, true);
    //for (Creature* pCreature : creatures)
    //{
    //	float healthPct = pCreature->GetHealthPct();
    //	if (healthPct <= lifePct)
    //		lifePctPlayers.push_back(pCreature);
    //}

    return lifePctPlayers;
}

Unit* BotFieldAI::RandomRangeEnemyByCasting(float range)
{
    NearUnitVec enemyPlayers;
    NearPlayerList playersNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
        {
            if (pVisionPlayer->HasUnitState(UNIT_STATE_CASTING))
                enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, range, false);
    for (Creature* pCreature : creatures)
    {
        if (pCreature->HasUnitState(UNIT_STATE_CASTING))
            enemyPlayers.push_back(pCreature);
    }
    if (!enemyPlayers.empty())
    {
        uint32 index = urand(0, enemyPlayers.size() - 1);
        return enemyPlayers[index];
    }
    return NULL;
}

NearUnitVec BotFieldAI::RangeEnemyListByHasAura(uint32 aura, float range)
{
    NearUnitVec enemyPlayers;
    NearPlayerList playersNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
        {
            if (TargetIsStealth(pVisionPlayer))
                continue;
            if (aura == 0 || pVisionPlayer->HasAura(aura))
                enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, range, false);
    for (Creature* pCreature : creatures)
    {
        if (aura == 0 || pCreature->HasAura(aura))
            enemyPlayers.push_back(pCreature);
    }
    return enemyPlayers;
}

NearUnitVec BotFieldAI::RangeEnemyListByNonAura(uint32 aura, float range)
{
    NearUnitVec enemyPlayers;
    if (aura == 0)
        return enemyPlayers;
    NearPlayerList playersNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
        {
            if (TargetIsStealth(pVisionPlayer))
                continue;
            if (!pVisionPlayer->HasAura(aura))
                enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, range, false);
    for (Creature* pCreature : creatures)
    {
        if (!pCreature->HasAura(aura))
            enemyPlayers.push_back(pCreature);
    }
    return enemyPlayers;
}

NearUnitVec BotFieldAI::RangeEnemyListByTargetIsMe(float range)
{
    NearUnitVec enemyPlayers;
    NearPlayerList playersNearby;
    me->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
        {
            if (TargetIsStealth(pVisionPlayer))
                continue;
            Unit* pUnit = pVisionPlayer->GetSelectedUnit();
            if (pUnit && pUnit->GetGUID() == me->GetGUID())
                enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, range, false);
    for (Creature* pCreature : creatures)
    {
        if (pCreature->GetTarget() == me->GetGUID())
            enemyPlayers.push_back(pCreature);
    }
    return enemyPlayers;
}

NearUnitVec BotFieldAI::RangeListByTargetIsTarget(Unit* pTarget, float range)
{
    NearUnitVec enemyPlayers;
    NearPlayerList playersNearby;
    pTarget->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() == me->GetTeamId())
        {
            if (TargetIsStealth(pVisionPlayer))
                continue;
            if (pVisionPlayer->GetSelectedUnit() == pTarget)
                enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(pTarget, creatures, range, false);
    for (Creature* pCreature : creatures)
    {
        if (pCreature->GetTarget() == pTarget->GetGUID())
            enemyPlayers.push_back(pCreature);
    }
    return enemyPlayers;
}

NearUnitVec BotFieldAI::RangeEnemyListByTargetRange(Unit* pTarget, float range)
{
    NearUnitVec enemyPlayers;
    NearPlayerList playersNearby;
    pTarget->GetPlayerListInGrid(playersNearby, range);
    for (Player* pVisionPlayer : playersNearby)
    {
        if (!IsNotSelect(pVisionPlayer) && pVisionPlayer->GetTeamId() != me->GetTeamId())
        {
            if (TargetIsStealth(pVisionPlayer))
                continue;
            enemyPlayers.push_back(pVisionPlayer);
        }
    }
    NearCreatureVec creatures;
    SearchCreatureListFromRange(pTarget, creatures, range, false);
    for (Creature* pCreature : creatures)
        enemyPlayers.push_back(pCreature);
    return enemyPlayers;
}

NearUnitVec BotFieldAI::SearchFarEnemy(float minRange, float maxRange)
{
    NearUnitVec enemyNearby;
    NearCreatureVec creatures;
    SearchCreatureListFromRange(me, creatures, maxRange, false);
    for (Creature* pCreature : creatures)
    {
        if (me->GetDistance(pCreature->GetPosition()) > minRange)
            enemyNearby.push_back(pCreature);
    }
    return enemyNearby;
}

bool BotFieldAI::IsMeleeBotAI()
{
    switch (me->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_HUNTER:
        return false;
    }
    return true;
}

bool BotFieldAI::IsRangeBotAI()
{
    switch (me->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_HUNTER:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool BotFieldAI::IsHealerBotAI()
{
    switch (me->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_HUNTER:
        return false;
    case CLASS_PALADIN:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

Unit* BotFieldAI::GetBotAIValidSelectedUnit()
{
    Unit* pTarget = me->GetSelectedUnit();
    bool isValid = true;
    if (!pTarget)
        isValid = false;
    if (isValid && !pTarget->IsVisible())
        isValid = false;
    /*if (isValid && !me->InSamePhase(pTarget->GetPhaseMask()))
        isValid = false;*/
    if (isValid && IsNotSelect(pTarget))
        isValid = false;
    if (isValid && pTarget->ToCreature() && pTarget->ToCreature()->IsInEvadeMode())
        isValid = false;
    if (!isValid)
    {
        me->AttackStop();
        me->SetSelection(ObjectGuid::Empty);
        return NULL;
    }
    return pTarget;
}

bool BotFieldAI::TargetIsRange(Player* pTarget)
{
    if (!pTarget)
        return false;
    switch (pTarget->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_HUNTER:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool BotFieldAI::TargetIsMagic(Player* pTarget)
{
    if (!pTarget)
        return false;
    switch (pTarget->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
        return false;
    case CLASS_PALADIN:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_HUNTER:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool BotFieldAI::TargetIsCastMagic(Player* pTarget)
{
    if (!pTarget)
        return false;
    switch (pTarget->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_PALADIN:
    case CLASS_HUNTER:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool BotFieldAI::TargetIsStealth(Player* pTarget)
{
    if (!pTarget)
        return false;
    // (1784 盗贼潜行 || 5215 德鲁伊潜行 || 66 法师隐形 || 58984 暗夜隐遁)
    if (pTarget->HasAura(1784) || pTarget->HasAura(5215) ||
        pTarget->HasAura(66) || pTarget->HasAura(58984))
    {
        if (!me->CanSeeOrDetect(pTarget, false, true)) // 侦测潜行
            return true;
    }
    return false;
}
