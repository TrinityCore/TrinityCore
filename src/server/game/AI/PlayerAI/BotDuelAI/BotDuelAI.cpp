
#include "BotDuelAI.h"
#include "PathfindingMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "BotBGAIMovement.h"
#include "MoveSplineInit.h"
#include "Spell.h"
#include "Pet.h"
#include "CreatureAI.h"
#include "PlayerBotMgr.h"
#include "BotDuelClassAI.h"
#include "CharmInfo.h"
#include <corecrt_math_defines.h>

BotDuelAI* BotDuelAI::CreateBotDuelAIByPlayerClass(Player* player)
{
    PlayerBotSetting::ClearUnknowMount(player);
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
        return new DuelWarriorAI(player);
    case CLASS_PALADIN:
        return new DuelPaladinAI(player);
    case CLASS_DEATH_KNIGHT:
        return new DuelDeathknightAI(player);
    case CLASS_ROGUE:
        return new DuelRogueAI(player);
    case CLASS_DRUID:
        return new DuelDruidAI(player);
    case CLASS_HUNTER:
        return new DuelHunterAI(player);
    case CLASS_SHAMAN:
        return new DuelShamanAI(player);
    case CLASS_MAGE:
        return new DuelMageAI(player);
    case CLASS_WARLOCK:
        return new DuelWarlockAI(player);
    case CLASS_PRIEST:
        return new DuelPriestAI(player);
    }
    return new BotDuelAI(player);
}

BotDuelAI::BotDuelAI(Player* player) :
    PlayerAI(player),
    m_NeedFindpathSearch(false),
    m_UpdateTick(BOTAI_UPDATE_TICK),
    m_Movement(new BotBGAIMovement(player, this)),
    m_UseMountID(PlayerBotSetting::RandomMountByLevel(player->getLevel())),
    pHorrorState(NULL),
    m_CheckStoped(player),
    m_Teleporting(player),
    m_UsePotion(player),
    m_Flee(player),
    m_NeedFlee(player),
    m_CastRecords(player),
    m_InitRndPos(),
    m_lastClearCtrlTick(0)
{
}

BotDuelAI::~BotDuelAI()
{
    delete m_Movement;
}

void BotDuelAI::EachTick()
{
    me->UpdateObjectVisibility(true);
}

void BotDuelAI::UpdateAI(uint32 diff)
{
    m_UpdateTick -= diff;

    if (m_UpdateTick <= 0)
    {
        m_UpdateTick = BOTAI_UPDATE_TICK;
        if (TryFinishDuel())
            return;
        if (!DuelIsStart())
            return;
        if (me->IsAlive())
        {
            if (m_Teleporting.CanMovement())
                UpdateBotAI(BOTAI_UPDATE_TICK);
            else
                m_Teleporting.Update(diff, m_Movement);
        }
    }
}

void BotDuelAI::ProcessHealth()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (NeedFlee())
    {
        //Dismount();
        ProcessFlee();
        return;
    }
    //Dismount();
    if (me->GetHealthPct() > 90)
    {
        ProcessCombat(me->GetSelectedUnit());
        return;
    }
    ProcessHealthSpell(me);
}

void BotDuelAI::ProcessCombat(Unit* pTarget)
{
    if (!pTarget)
        return;
    bool inView = me->IsWithinLOSInMap(pTarget);
    if (inView)
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        if (m_IsRangeBot)
        {
            if (NeedFlee())
            {
                if (pTarget->GetGUID() != me->GetTarget())//GetTargetGUID
                {
                    pTarget = me->GetSelectedUnit();
                    if (!pTarget)
                        return;
                }
                //Dismount();
                if (me->GetVictim() != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->Attack(pTarget, true);
                ProcessFlee();
                if (!IsNotSelect(pTarget))
                    ProcessMeleeSpell(pTarget);
                //ChaseTarget(pTarget, true);
            }
            else if (me->GetDistance(pTarget) <= BOTAI_RANGESPELL_DISTANCE)
            {
                //Dismount();
                if (me->GetVictim() != pTarget)// || me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
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
                if (me->GetVictim() != pTarget)// || me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->Attack(pTarget, false);
                m_Movement->MovementToTarget();
            }
        }
        else
        {
            if (NeedFlee())
            {
                if (me->GetVictim() != pTarget || !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->Attack(pTarget, true);
                ProcessFlee();
                if (!IsNotSelect(pTarget))
                    ProcessMeleeSpell(pTarget);
            }
            else if (me->IsWithinMeleeRange(pTarget))
            {
                //Dismount();
                if (!me->GetVictim() && !me->IsVehicle())
                    me->Attack(pTarget, true);
                if (!IsNotMovement())
                    ChaseTarget(pTarget, true);
                if (!IsNotSelect(pTarget) && !me->IsVehicle())
                    ProcessMeleeSpell(pTarget);
            }
            else
            {
                if (!IsNotMovement())
                    m_Movement->MovementToTarget();
                if (me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE && pTarget->IsAlive())
                {
                    //Dismount();
                    ProcessRangeSpell(pTarget);
                }
            }
        }
    }
    else if (!IsNotMovement())
        m_Movement->MovementToTarget();
}

void BotDuelAI::Dismount()
{
    if (!me->HasAura(m_UseMountID))
        return;
    me->RemoveOwnedAura(m_UseMountID, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
}

void BotDuelAI::ChaseTarget(Unit* pTarget, bool isMelee, float range)
{
    if (IsNotSelect(pTarget))
        return;
    if (isMelee)
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
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(pTarget, range);
        }
    }
}

NearObjectList BotDuelAI::SearchGameObject(float range)
{
    std::list<GameObject*> results;
    Position pos = me->GetPosition();
    Trinity::GameObjectInRangeCheck checker(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), range);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(me, results, checker);
    //me->VisitNearbyGridObject(range, searcher);
    return results;
}

bool BotDuelAI::DoFaceToTarget(Unit* pTarget)
{
    float relative = me->GetRelativeAngle(pTarget->GetPositionX(), pTarget->GetPositionY());
    if (relative > M_PI_4 && !IsNotMovement())// (fabsf(selfAngle) > M_PI_4)
    {
        //me->SetFacingToObject(pTarget);
        /*Movement::MoveSplineInit init(*me);
        init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZMinusOffset());
        init.SetFacing(pTarget);
        init.SetOrientationFixed(true);
        init.Launch();*/
        return true;
    }
    return false;
}

SpellCastResult BotDuelAI::TryCastSpell(uint32 spellID, Unit* /*pTarget*/, bool /*force*/, bool /*dismount*/)
{
    if (!spellID || !me->HasSpell(spellID))
    {
        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
    }
    if (spellID == BotCommon_ClearAllCtrl)
    {
        uint32 curTick = getMSTime();
        if (m_lastClearCtrlTick + 120000 > curTick)
        {
            return SpellCastResult::SPELL_FAILED_NOT_READY;
        }
        m_lastClearCtrlTick = curTick;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
   /* TriggerCastData data;
    data.triggerFlags = force ? TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM) : TriggerCastFlags::TRIGGERED_NONE;
    Spell* spell = new Spell(me, spellInfo, data);
    spell->m_CastItem = NULL;*/
    //SpellCastTargets targets;
    //targets.SetUnitTarget(pTarget);
    //if (dismount)
    //    Dismount();
    //SpellCastResult castResult = spell->prepare(targets);
    //if (castResult != SpellCastResult::SPELL_CAST_OK)
    //{
    //    if (castResult == SpellCastResult::SPELL_FAILED_NOT_MOUNTED)
    //        PlayerBotSetting::ClearUnknowMount(me);
    //    //spell->finish(false);
    //    //delete spell;
    //    return castResult;
    //}
    return SpellCastResult::SPELL_CAST_OK;
}

SpellCastResult BotDuelAI::PetTryCastSpell(uint32 spellID, Unit* /*pTarget*/, bool /*force*/)
{
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    if (!spellID || !pPet->HasSpell(spellID))
        return SpellCastResult::SPELL_FAILED_SPELL_LEARNED;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
   /* TriggerCastData data;
    Spell* spell = new Spell(pPet, spellInfo, data);
    pTarget = pTarget ? pTarget : pPet;
    SpellCastResult castResult = spell->CheckPetCast(pTarget);
    if (castResult == SPELL_FAILED_UNIT_NOT_INFRONT && !pPet->isPossessed() && !pPet->IsVehicle())
    {
        if (pTarget && pTarget != pPet)
        {
            pPet->SetInFront(pTarget);
            if (Player* player = pTarget->ToPlayer())
                pPet->SendUpdateToPlayer(player);
        }
        else if (Unit* unit_target2 = spell->m_targets.GetUnitTarget())
        {
            pPet->SetInFront(unit_target2);
            if (Player* player = unit_target2->ToPlayer())
                pPet->SendUpdateToPlayer(player);
        }

        if (Unit* powner = pPet->GetCharmerOrOwner())
            if (Player* player = powner->ToPlayer())
                pPet->SendUpdateToPlayer(player);

        castResult = SPELL_CAST_OK;
    }*/
    //if (castResult == SPELL_CAST_OK)
    //{
    //    pTarget = spell->m_targets.GetUnitTarget();

    //    //10% chance to play special pet attack talk, else growl
    //    //actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
    //    if (pPet->isPet() && (((Pet*)pPet)->getPetType() == SUMMON_PET) && (pPet != pTarget) && (urand(0, 100) < 10))
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
    //{/*
    //    spell->SendCastResult(me, spellInfo, castResult);

    //    if (!pPet->HasSpellCooldown(spellID))
    //        pPet->RemoveCreatureSpellCooldown(spellID);*/

    //    spell->finish();
    //    delete spell;

    //    // reset specific flags in case of spell fail. AI will reset other flags
    //    if (pPet->GetCharmInfo())
    //        pPet->GetCharmInfo()->SetIsCommandAttack(false);
    //}

    //return castResult;
    SpellCastResult castResult=SPELL_CAST_OK;//I
    return castResult;//I
}

void BotDuelAI::SettingPetAutoCastSpell(uint32 spellID, bool autoCast)
{
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return;
    if (!spellID || !pPet->HasSpell(spellID))
        return;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive() || !spellInfo->IsAutocastable())
        return;
   /* CharmInfo* charmInfo = pPet->GetCharmInfo();
    if (!charmInfo)
        return;*/
    if (pPet->IsPet())
        pPet->ToggleAutocast(spellInfo, autoCast);
    else
        pPet->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, autoCast);

    //charmInfo->SetSpellAutocast(spellInfo, autoCast);
}

Unit* BotDuelAI::GetDuelEnemy()
{/*
    DuelInfo* duel = me->duel;
    if (!duel || duel->state == DuelState::DUEL_COMPLETED)
    {
        return NULL;
    }
    Unit* pSelect = ObjectAccessor::FindUnit(duel->opponent);
    if (!pSelect)
        return NULL;*/
   /* if (!IsNotSelect(pSelect) && !IsInvincible(pSelect) &&
        !TargetIsStealth(pSelect->ToPlayer()))
    {
        if (!HasAuraMechanic(pSelect, Mechanics::MECHANIC_POLYMORPH) || me->getClass() == Classes::CLASS_SHAMAN)
            return pSelect;
    }*/
    return NULL;
}

Position BotDuelAI::GetDuelCenterPosition()
{
    if (!me->duel || !me->IsInWorld())
        return me->GetPosition();
   /* ObjectGuid duelFlagGUID = me->GetGuidValue(PLAYER_FIELD_DUEL_ARBITER);
    GameObject* obj = me->GetMap()->GetGameObject(duelFlagGUID);
    if (!obj)
        return me->GetPosition();
    return obj->GetPosition();*/
    return true;
}

void BotDuelAI::UpdateBotAI(uint32 diff)
{
    EachTick();
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    m_CheckStoped.UpdatePosition(diff);

    ClearMechanicAura();
    if (!IsNotMovement())
        ProcessHorror(diff);
    if (NeedWaitSpecialSpell(BOTAI_UPDATE_TICK))
        return;

    //m_Movement->SyncPosition(me->GetPosition());
    Unit* pSelect = GetDuelEnemy();
    if (pSelect)
    {
        if (me->GetTarget() != pSelect->GetGUID())//GetTargetGUID
            me->SetSelection(pSelect->GetGUID());
        float distance = me->GetDistance(pSelect->GetPosition());
        if (distance < BOTAI_SEARCH_RANGE)
        {
            if (IsHealerBotAI() && HaveManaStore())
                ProcessHealth();
            else
                ProcessCombat(pSelect);
        }
        else
        {
            m_Movement->MovementToTarget();
        }
    }
    else
    {
        me->AttackStop();
        me->SetSelection(ObjectGuid::Empty);
        m_Movement->ClearMovement();
    }
}

void BotDuelAI::ResetBotAI()
{
    PlayerBotSetting::ClearUnknowMount(me);
    if (m_UseMountID != 0)
    {
        if (!me->HasSpell(m_UseMountID))
            me->LearnSpell(m_UseMountID, false);
    }
    m_IsMeleeBot = IsMeleeBotAI();
    m_IsRangeBot = IsRangeBotAI();
    m_IsHealerBot = IsHealerBotAI();

    if (!me->IsStandState())
        me->SetStandState(UNIT_STAND_STATE_STAND);

    BotCommon_ClearAllCtrl = FindMaxRankSpellByExist(59752);
    if (BotCommon_ClearAllCtrl == 0)
    {
        me->LearnSpell(59752, false);
        BotCommon_ClearAllCtrl = FindMaxRankSpellByExist(59752);
    }
    m_CastRecords.ClearRecordSpell();
}

bool BotDuelAI::IsNotSelect(Unit* pTarget)
{
    if (!pTarget || !pTarget->IsAlive())
        return true;
    Player* pPlayer = pTarget->ToPlayer();
    if (pPlayer)
    {
        if (pPlayer->GetVehicleKit())
            return true;
    }
    if (pTarget->HasAura(27827)) // (27827 救赎之魂 神牧死亡后)
        return true;
    return false;
}

bool BotDuelAI::TryUpMount()
{
    if (me->IsInCombat() || me->GetSelectedUnit() || me->HasAura(m_UseMountID) || me->getLevel() < 20)
        return false;
    /*if (!me->GetMap()->IsOutdoors(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
        return false;*/
    if (me->IsMounted())
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    m_Movement->ClearMovement();
    bool okUp = (TryCastSpell(m_UseMountID, me) == SPELL_CAST_OK);
    return okUp;
}

bool BotDuelAI::TryFinishDuel()
{
   /* if (!me->duel || me->duel->state == DuelState::DUEL_COMPLETED || !me->duel->opponent || !me->duel->initiator)
    {*/
        m_Movement->ClearMovement();
        me->SetSelection(ObjectGuid::Empty);
        me->AttackStop();
        Group* pExistGroup = me->GetGroup();
        if (pExistGroup)
            sPlayerBotMgr->SwitchPlayerBotAI(me, PBAIT_GROUP, true);
        else
            sPlayerBotMgr->SwitchPlayerBotAI(me, PBAIT_FIELD, true);
        return true;
    //}
    return false;
}

bool BotDuelAI::DuelIsStart()
{
   /* if (!me->duel || me->duel->state == DuelState::DUEL_COMPLETED || !me->duel->opponent)
        return false;
    if (me->duel->state == DuelState::DUEL_STARTED)
        return false;*/

    return true;
}

void BotDuelAI::ProcessHorror(uint32 diff)
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
            return;
        }
        pHorrorState->UpdateHorror(diff, m_Movement);
    }
    else if (pHorrorState)
    {
        delete pHorrorState;
        pHorrorState = NULL;
        me->StopMoving();
    }
}

bool BotDuelAI::TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType)
{
    if (!pTarget)
        return false;
    if (diType < 1 || diType > 20)
        return false;
    DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
    return diLevel < 1;
}

bool BotDuelAI::TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType)
{
    if (!pTarget)
        return false;
    if (diType < 1 || diType > 20)
        return false;
    DiminishingLevels diLevel = pTarget->GetDiminishing(diType);
    return diLevel < 2;
}

bool BotDuelAI::HasAuraMechanic(Unit* pTarget, Mechanics mask)
{
    if (!pTarget)
        return false;
    return (pTarget->HasAuraWithMechanic(1i64 << mask));//1
}

bool BotDuelAI::NeedWaitSpecialSpell(uint32 /*diff*/)
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM))
    {
        me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_DISORIENTED))
    {
        me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_FEAR))
    {
        //me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP))
    {
        me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
    {
        me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE))
    {
        me->StopMoving();
        //if (BotCommon_ClearAllCtrl)
        //	TryCastSpell(BotCommon_ClearAllCtrl, me);
        //return true;
    }
    //if (HasAuraMechanic(me, Mechanics::MECHANIC_KNOCKOUT))
    //{
    //	me->StopMoving();
    //	//if (BotCommon_ClearAllCtrl)
    //	//	TryCastSpell(BotCommon_ClearAllCtrl, me);
    //	return true;
    //}
    if (HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH))
    {
        me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_BANISH))
    {
        me->StopMoving();
        //if (BotCommon_ClearAllCtrl)
        //	TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_HORROR))
    {
        //me->StopMoving();
        if (BotCommon_ClearAllCtrl)
            TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_SAPPED))
    {
        me->StopMoving();
        //if (BotCommon_ClearAllCtrl)
        //	TryCastSpell(BotCommon_ClearAllCtrl, me);
        return true;
    }
    return false;
}

bool BotDuelAI::NeedFlee()
{
    return m_NeedFlee.TargetHasFleeAura();
}

void BotDuelAI::FleeMovement()
{
    //if (me->IsStopped() && !IsNotMovement())
    //{
    //	NearUnitVec& enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    //	if (enemys.empty())
    //		return;
    //	Unit* selectEnemy = enemys[urand(0, enemys.size() - 1)];
    //	G3D::Vector3 dir = (me->GetVector3() - selectEnemy->GetVector3()).direction();
    //	Position targetPos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE * 0.5, selectEnemy->GetRelativeAngle(&me->GetPosition()));
    //	if ((targetPos.GetVector3() - me->GetVector3()).length() <= 5.0f)
    //	{
    //		targetPos = me->GetFirstCollisionPosition(BOTAI_SEARCH_RANGE * 0.5, frand(0.1f, float(M_PI) * 2.0f - 0.1f));
    //	}
    //	m_Movement->MovementTo(targetPos.GetPositionX(), targetPos.GetPositionY(), targetPos.GetPositionZ());
    //}
    if (!IsNotMovement())
    {
        Unit* selectEnemy = GetDuelEnemy();
        if (!selectEnemy || me->GetDistance(selectEnemy->GetPosition()) > 30)//BOTAI_FLEE_JUDGE + 5.0f)
        {
            m_Flee.Clear();
            return;
        }
        m_Flee.UpdateFleeMovementByPosition(selectEnemy, GetDuelCenterPosition(), 65, m_Movement);
    }
    else
        m_Flee.Clear();
}

bool BotDuelAI::IsNotMovement()
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

bool BotDuelAI::IsInvincible(Unit* pTarget)
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

uint32 BotDuelAI::FindMaxRankSpellByExist(uint32 spellID)
{
    if (spellID == 0)
        return 0;
    uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
    if (selectSpell == 0)
    {
        if (me->HasSpell(spellID))
            return spellID;
        return 0;
    }
    while (!me->HasSpell(selectSpell))
    {
        selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
        if (selectSpell == 0)
            return 0;
    }
    return selectSpell;
}

uint32 BotDuelAI::FindPetMaxRankSpellByExist(uint32 spellID)
{
    if (spellID == 0)
        return 0;
    Pet* pPet = me->GetPet();
    if (!pPet)
        return 0;
    uint32 selectSpell = sSpellMgr->GetLastSpellInChain(spellID);
    if (selectSpell == 0)
    {
        if (pPet->HasSpell(spellID))
            return spellID;
        return 0;
    }
    while (!pPet->HasSpell(selectSpell))
    {
        selectSpell = sSpellMgr->GetPrevSpellInChain(selectSpell);
        if (selectSpell == 0)
            return 0;
    }
    return selectSpell;
}

bool BotDuelAI::IsMeleeBotAI()
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

bool BotDuelAI::IsRangeBotAI()
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

bool BotDuelAI::IsHealerBotAI()
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

bool BotDuelAI::TargetIsMelee(Player* pTarget)
{
    if (!pTarget)
        return false;
    switch (pTarget->getClass())
    {
    case CLASS_PALADIN:
        return (pTarget->FindTalentType() != 0);
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
        return true;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_HUNTER:
    case CLASS_PRIEST:
    case CLASS_DRUID:
        return false;
    case CLASS_SHAMAN:
        return (pTarget->FindTalentType() == 1);
    }
    return false;
}

bool BotDuelAI::TargetIsRange(Player* pTarget)
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

bool BotDuelAI::TargetIsMagic(Player* pTarget)
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

bool BotDuelAI::TargetIsHealth(Player* pTarget)
{
    if (!pTarget)
        return false;
    switch (pTarget->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_HUNTER:
        return false;
    case CLASS_PALADIN:
        return (pTarget->FindTalentType() == 0);
    case CLASS_PRIEST:
        return (pTarget->FindTalentType() != 2);
    case CLASS_SHAMAN:
        return (pTarget->FindTalentType() == 2);
    case CLASS_DRUID:
        return (pTarget->FindTalentType() == 2);
    }
    return false;
}

bool BotDuelAI::TargetCanManaBurn(Player* pTarget)
{
    if (!pTarget)
        return false;
    uint32 minManaPct = 8;
    switch (pTarget->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
    case CLASS_DEATH_KNIGHT:
    case CLASS_HUNTER:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PALADIN:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return (TargetManaPCT(pTarget) > minManaPct);
    }
    return false;
}

bool BotDuelAI::TargetIsCastMagic(Player* pTarget)
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

bool BotDuelAI::TargetIsStealth(Player* pTarget)
{
    if (!pTarget)
        return false;
    if (pTarget->HasAura(1784) || pTarget->HasAura(5215) || pTarget->HasAura(66)) // (1784 盗贼潜行 || 5215 德鲁伊潜行 || 66 法师隐形)
    {
        if (!me->CanSeeOrDetect(pTarget, false, true)) // 侦测潜行
            return true;
    }
    return false;
}

uint32 BotDuelAI::TargetManaPCT(Unit* pTarget)
{
    if (!pTarget)
        return 0;
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool BotDuelAI::IsFleeTargetByRangeBot(Unit* pTarget)
{
    if (!pTarget || !pTarget->ToPlayer())
        return false;
    if (me->getClass() == Classes::CLASS_HUNTER)
        return true;
    if (pTarget->GetTarget() != me->GetGUID())//GetTargetGUID
        return false;
    if (!pTarget->IsPlayerBot())
    {
        Player* player = pTarget->ToPlayer();
        Classes cls = Classes(player->getClass());
        switch (cls)
        {
        case CLASS_PALADIN:
            return (player->FindTalentType() == 2);
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
            return true;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        case CLASS_PRIEST:
        case CLASS_HUNTER:
            return false;
        case CLASS_SHAMAN:
            return (player->FindTalentType() == 1);
        case CLASS_DRUID:
            return (player->FindTalentType() == 1);
        }
    }
    return false;
}
