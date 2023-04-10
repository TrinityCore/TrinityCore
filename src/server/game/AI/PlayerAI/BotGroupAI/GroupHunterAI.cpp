
#include "BotGroupClassAI.h"
#include "BotBGAIMovement.h"
#include "PlayerBotSession.h"
#include "Pet.h"
#include "Group.h"
#include <BotHunterAI.h>

void GroupHunterAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupHunterAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    //m_IsSupplemented = false;
    m_IsReviveManaModel = false;
    UpdateTalentType();
    InitializeSpells(me);
    //if (Pet* pet = me->GetPet())
    //{
    //	if (pet->m_spells.empty())
    //		pet->InitPetCreateSpells();
    //	pet->FlushTalentsByPoints();
    //	pet->SettingAllSpellAutocast(true);
    //}
    if (HunterShot_QMLShot == 0 && m_BotTalentType == 1 && me->getLevel() == 80)
    {
        me->LearnSpell(53209, false);
        HunterShot_QMLShot = BotUtility::FindMaxRankSpellByExist(me, 53209);
    }
}

uint32 GroupHunterAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 5;
}

void GroupHunterAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
    if (Pet* pet = me->GetPet())
    {
        //pet->FlushTalentsByPoints();
        pet->InitLevelupSpellsForLevel();
        //pet->SettingAllSpellAutocast(true);
    }
    //m_IsSupplemented = false;
}

uint32 GroupHunterAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool GroupHunterAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void GroupHunterAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    PetAction(me->GetPet(), NULL);
    if (ProcessAura(true))
        return;
    if (HunterAssist_ClearRoot && HasRootMechanic() && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (HunterAssist_Mislead && BotUtility::SpellHasReady(me, HunterAssist_Mislead))
    {
        Group* pGroup = me->GetGroup();
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive())
                    continue;
                if (BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(player->GetAI()))
                {
                    if (pAI->IsTankBotAI())
                    {
                        TryCastSpell(HunterAssist_Mislead, player);
                        break;
                    }
                }
            }
        }
    }
    //Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pTarget->HasUnitState(UNIT_STATE_CASTING))
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastMeleeSpell(pTarget))
        return;
    if (CastRangeSpell(pTarget))
        return;
}

void GroupHunterAI::ProcessFlee()
{
    FleeMovement();

    Unit* pSelectTarget = me->GetSelectedUnit();
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.empty())
        return;
    if (!pSelectTarget && !enemys.empty())
        pSelectTarget = enemys[urand(0, enemys.size() - 1)];
    if (!pSelectTarget)
        return;
    Pet* pPet = me->GetPet();
    if (TargetIsSuppress(pSelectTarget))
    {
        if (pPet)
        {
            pPet->AttackStop();
            pPet->SetTarget(ObjectGuid::Empty);
        }
        me->AttackStop();
        return;
    }
    if (pPet)
    {
        Unit* pPetTarget = pPet->GetVictim();
        if (pPetTarget && pPetTarget != pSelectTarget)
            PetAction(pPet, pSelectTarget);
    }

    if (enemys.size() > 1 && TryCastSpell(HunterTrap_Ice, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    else if (TryCastSpell(HunterTrap_Frozen, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessAura(true))
        return;
    if (enemys.size() > 1 && TryCastSpell(HunterMelee_NoDamage, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    bool hasRoot = HasRootMechanic();
    if (hasRoot && HunterAssist_ClearRoot && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (enemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pCastEnemy)
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (m_BotTalentType == 0)
    {
        if (hasRoot && HunterAssist_PetRage && TryCastSpell(HunterAssist_PetRage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterAssist_PetStun, pSelectTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastMeleeSpell(pSelectTarget))
        return;
    if (CastRangeSpell(pSelectTarget))
        return;

    uint32 minLifePct = 100;
    Unit* pMinUnit = NULL;
    Unit* pMeleeUnit = NULL;
    enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pSelectTarget || TargetIsSuppress(pUnit))
            continue;
        if (!pUnit->IsInCombat())
            continue;
        float dist = me->GetDistance(pUnit->GetPosition());
        if (dist <= 9)
        {
            if (dist < 7)
                pMeleeUnit = pUnit;
            continue;
        }
        uint32 lifePct = uint32(pUnit->GetHealthPct());
        if (!pMinUnit || lifePct < minLifePct)
        {
            pMinUnit = pUnit;
            minLifePct = lifePct;
        }
    }
    if (pMinUnit && CastRangeSpell(pMinUnit))
        return;
    if (pMeleeUnit && CastMeleeSpell(pMeleeUnit))
        return;
}

bool GroupHunterAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    /*if (!m_IsSupplemented)
    {
        m_IsSupplemented = true;
        std::lock_guard<std::mutex> lock(m_ItemLock);
        me->SupplementAmmo();
        return true;
    }*/

    //if (me->GetPetGUID().IsEmpty() && CanCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
    //	return false;
    if (!me->HasAura(m_UseMountID))
    {
        Pet* pPet = me->GetPet();
        if (pPet && !pPet->IsAlive())
        {
            m_Movement->ClearMovement();
            TryCastSpell(HunterIDLE_RevivePet, pPet);
            return true;
        }
        else if (pPet && pPet->GetHealthPct() < 85 && !pPet->HasAura(HunterAssist_HealPet))
        {
            if (TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        {
            return false;
        }
        else if (me->GetPetGUID().IsEmpty())
        {
            //TC_LOG_INFO("BotBGAI", "Hunter Ai check pet, is no pet!");
            PlayerBotSetting::CheckHunterPet(me);
            return true;
        }
        PetAction(pPet, NULL);
    }
    if (me->HasAura(m_UseMountID))
        return false;
    if (m_BotTalentType == 1)
    {
        if (HunterIDLE_ShotAura && !me->HasAura(HunterIDLE_ShotAura) && TryCastSpell(HunterIDLE_ShotAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    if (HunterIDLE_DragonAura)
    {
        if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else
    {
        if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }

    return TryUpMount();
}

void GroupHunterAI::ProcessMeleeSpell(Unit* pTarget)
{
    CastMeleeSpell(pTarget);

    uint32 minLifePct = 100;
    Unit* pMinUnit = NULL;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget || TargetIsSuppress(pUnit))
            continue;
        if (me->GetDistance(pUnit->GetPosition()) <= 9)
            continue;
        uint32 lifePct = uint32(pUnit->GetHealthPct());
        if (!pMinUnit || lifePct < minLifePct)
        {
            pMinUnit = pUnit;
            minLifePct = lifePct;
        }
    }
    if (pMinUnit && CastRangeSpell(pMinUnit))
        return;
}

void GroupHunterAI::ProcessRangeSpell(Unit* pTarget)
{
    uint32 manaPct = GetManaPowerPer();
    Pet* pPet = me->GetPet();
    if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    PetAction(pPet, pTarget);
    if (pPet && pPet->IsAlive() && manaPct > 15)
    {
        if (pPet->GetHealthPct() < 75 && !pPet->HasAura(HunterAssist_HealPet) && TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessAura(false))
        return;

    NearUnitVec selMeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (selMeEnemys.size() > 0)
    {
        if (selMeEnemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        Unit* pRndPlayer = selMeEnemys[urand(0, selMeEnemys.size() - 1)];
        if (HunterTrap_FarFrozen && pRndPlayer != pTarget && TryCastSpell(HunterTrap_FarFrozen, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterDebug_Sleep && pRndPlayer != pTarget && TryCastSpell(HunterDebug_Sleep, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pCastEnemy)
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (!pTarget->HasAura(HunterAssist_Stamp) && TryCastSpell(HunterAssist_Stamp, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (CastRangeSpell(pTarget))
        return;

    uint32 minLifePct = 100;
    Unit* pMinUnit = NULL;
    Unit* pMeleeUnit = NULL;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget || TargetIsSuppress(pUnit))
            continue;
        float dist = me->GetDistance(pUnit->GetPosition());
        if (dist <= 9)
        {
            if (dist < 7)
                pMeleeUnit = pUnit;
            continue;
        }
        uint32 lifePct = uint32(pUnit->GetHealthPct());
        if (!pMinUnit || lifePct < minLifePct)
        {
            pMinUnit = pUnit;
            minLifePct = lifePct;
        }
    }
    if (pMinUnit && CastRangeSpell(pMinUnit))
        return;
    if (pMeleeUnit && CastMeleeSpell(pMeleeUnit))
        return;
}

bool GroupHunterAI::ProcessAura(bool isFlee)
{
    /*if (HunterIDLE_ManaAura && CheckManaModel())
    {
        if (!me->HasAura(HunterIDLE_ManaAura) && TryCastSpell(HunterIDLE_ManaAura, me, true) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else*/
    {
        if (HunterIDLE_DragonAura)
        {
            if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (isFlee)
            {
                if (!me->HasAura(HunterIDLE_DodgeAura) && TryCastSpell(HunterIDLE_DodgeAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else
            {
                if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

bool GroupHunterAI::CastRangeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (me->GetDistance(pTarget->GetPosition()) <= 9)
        return false;
    NearUnitVec targetRanges = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (targetRanges.size() > 3)
    {
        if (HunterShot_MulShot && TryCastSpell(HunterShot_MulShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (HunterShot_AOEShot && TryCastSpell(HunterShot_AOEShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    if (HunterShot_KillShot && pTarget->GetHealthPct() < 20 && TryCastSpell(HunterShot_KillShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (CheckManaModel())
    {
        if (!pTarget->HasAura(HunterDebug_Mana, me->GetGUID()) && !pTarget->HasAura(HunterDebug_Damage, me->GetGUID()) && TryCastSpell(HunterDebug_Mana, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (!pTarget->HasAura(HunterDebug_Mana, me->GetGUID()) && !pTarget->HasAura(HunterDebug_Damage, me->GetGUID()) && TryCastSpell(HunterDebug_Damage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (me->InArena() && TryCastSpell(HunterShot_MulShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (!pTarget->HasAura(HunterMelee_DecSpeed) && !pTarget->HasAura(HunterShot_Shock) && !TargetIsSuppress(pTarget))
    {
        if (TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_Cast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupHunterAI::CastMeleeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (m_BotTalentType == 2 && HunterDebug_Sleep && me->GetDistance(pTarget->GetPosition()) < 12)
    {
        if (!TargetIsSuppress(pTarget) && TryCastSpell(HunterDebug_Sleep, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!pTarget->HasAura(HunterMelee_DecSpeed) && !pTarget->HasAura(HunterShot_Shock) && !TargetIsSuppress(pTarget))
    {
        if (TryCastSpell(HunterMelee_DecSpeed, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!me->HasAura(HunterMelee_NextAtt))
        TryCastSpell(HunterMelee_NextAtt, pTarget);
    if (TryCastSpell(HunterMelee_MeleeAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (m_BotTalentType == 2 && HunterMelee_BackRoot)
    {
        if (TryCastSpell(HunterMelee_BackRoot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void GroupHunterAI::PetAction(Pet* pPet, Unit* pTarget)
{
    Position pos;
    if (!pPet)
        return;
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool GroupHunterAI::HasRootMechanic()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}

bool GroupHunterAI::TargetIsSuppress(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}

bool GroupHunterAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterIDLE_EagleAura, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

bool GroupHunterAI::CheckManaModel()
{
    uint32 manaPct = GetManaPowerPer();
    if (m_IsReviveManaModel)
    {
        if (manaPct > 70)
            m_IsReviveManaModel = false;
    }
    else
    {
        if (manaPct < 8)
            m_IsReviveManaModel = true;
    }
    return m_IsReviveManaModel;
}

void GroupHunterAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 700) + power);
}
