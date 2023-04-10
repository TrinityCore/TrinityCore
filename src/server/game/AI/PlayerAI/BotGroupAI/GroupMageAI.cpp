
#include "BotGroupClassAI.h"
#include "BotBGAIMovement.h"
#include "Group.h"
#include "Pet.h"

void GroupMageAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupMageAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
    m_LastPolymorphTarget = ObjectGuid::Empty;

    if (MageConfine_Freeze == 0 && m_BotTalentType == 2 && me->getLevel() == 80)
    {
        me->LearnSpell(44572, false);
        MageConfine_Freeze = BotUtility::FindMaxRankSpellByExist(me, 44572);
    }

    m_JewelEntrys.clear();
    m_JewelEntrys.insert(5514);
    m_JewelEntrys.insert(5513);
    m_JewelEntrys.insert(8007);
    m_JewelEntrys.insert(8008);
    m_JewelEntrys.insert(22044);
    m_JewelEntrys.insert(33312);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(MageIDLE_AOEArcaneMagic);
    m_WishStore.RegisterWish(MageIDLE_ArcaneMagic);
}

uint32 GroupMageAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 3;
}

void GroupMageAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.RegisterWish(MageIDLE_AOEArcaneMagic);
    m_WishStore.RegisterWish(MageIDLE_ArcaneMagic);
}

uint32 GroupMageAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void GroupMageAI::ClearMechanicAura()
{
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) || HasAuraMechanic(me, Mechanics::MECHANIC_SNARE);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN);
    if (root || stun)
    {
        if (stun && me->GetHealthPct() < 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (MageAssist_Teleport && RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0 && TryCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastTeleport();
            return;
        }
    }
}

bool GroupMageAI::NeedWaitSpecialSpell(uint32 diff)
{
    if (BotGroupAI::NeedWaitSpecialSpell(diff))
        return true;
    if (MageFlag_Scherm)
    {
        if (me->HasAura(MageFlag_Scherm))
        {
            if (me->InArena() && RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE).empty())
            {
                me->RemoveOwnedAura(MageFlag_Scherm, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
                return false;
            }
            return true;
        }
    }
    return false;
}

bool GroupMageAI::TargetCanFreeze(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (pTarget->HasAuraState(AURA_STATE_FROZEN) || me->HasAura(MageFlag_CanFrozen))
        return true;
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE) || HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT))
        return true;
    return false;
}

bool GroupMageAI::NeedFlee()
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

void GroupMageAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (MageConfine_BreakCast && pTarget->HasUnitState(UNIT_STATE_CASTING))
    {
        if (TryCastSpell(MageConfine_BreakCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (MageFire_FireShock && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && MageArcane_Barrage && TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 1 && MageFire_FireBomb && !pTarget->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (MageFrost_IceLance && TryCastSpell(MageFrost_IceLance, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupMageAI::ProcessNormalSpell()
{
    if (me->HasAura(m_UseMountID))
        return false;
    if (MageIDLE_AOEArcaneMagic && !me->HasAura(MageIDLE_AOEArcaneMagic) && TryCastSpell(MageIDLE_AOEArcaneMagic, me, true) == SpellCastResult::SPELL_CAST_OK)
        return false;
    if (!MageIDLE_AOEArcaneMagic && MageIDLE_ArcaneMagic)
    {
        Group* pGroup = me->GetGroup();
        if (pGroup && !pGroup->isBGGroup() && !pGroup->isBFGroup())
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                    continue;
                if (!player->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
        }
    }
    if (MageIDLE_MgcArmor)
    {
        if (!me->HasAura(MageIDLE_MgcArmor) && TryCastSpell(MageIDLE_MgcArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (MageIDLE_FireArmor)
    {
        if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    if (MageIDLE_MagicAdd && !me->HasAura(MageIDLE_MagicAdd) && TryCastSpell(MageIDLE_MagicAdd, me) == SpellCastResult::SPELL_CAST_OK)
        return false;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct > 30 && !FindExistManaJewel())
    {
        m_Movement->ClearMovement();
        if (TryCastSpell(MageIDLE_ManaGem, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (MageAssist_Rouse && manaPct < 15 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
    {
        me->StopMoving();
        return true;
    }
    ProcessDispel();
    return TryUpMount();
}

void GroupMageAI::ProcessFlee()
{
    FleeMovement();
    ProcessPetAttack(me->GetSelectedUnit());
    if (me->HasAura(MageAssist_Stealth))
        return;

    if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (MageIDLE_IceArmor)
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (me->IsInCombat() && TryCastSpell(MageAssist_Mirror, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    float healthPct = me->GetHealthPct();
   NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        for (Unit* player : enemys)
        {
            if (HasAuraMechanic(player, MECHANIC_ROOT) ||
                HasAuraMechanic(player, MECHANIC_STUN))
                continue;
            {
                if (PetTryCastSpell(MagePet_FrostNova, player) == SpellCastResult::SPELL_CAST_OK)
                    break;
                if (TryCastSpell(MageGuard_FrostNova, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
                break;
            }
        }
    }
    if (healthPct <= 15 && enemys.size() > 0 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (CanCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
    //{
    //	OnCastTeleport();
    //	return;
    //}
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 60 && UseManaJewel())
        return;

    if (ProcessFreezeSpell(me->GetSelectedUnit()))
        return;
    switch (GetMageTalentType())
    {
    case 0:
        if (ProcessArcaneFlee())
            return;
        break;
    case 1:
        if (ProcessFireFlee())
            return;
        break;
    case 2:
        if (ProcessFrostFlee())
            return;
        break;
    }
    if (enemys.size() > 0 && TryCastSpell(MageAssist_Stealth, me) == SpellCastResult::SPELL_CAST_OK)
    {
       NearUnitVec cancelTargets = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
        for (Unit* target : cancelTargets)
        {
            if (Player* player = target->ToPlayer())
                player->SetSelection(ObjectGuid::Empty);
            else
                target->SetTarget(ObjectGuid::Empty);
        }
        return;
    }
    Unit* pTarget = me->GetSelectedUnit();
    if (pTarget && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageAssist_Stealth) && RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(MageAOE_ArcaneExplode, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!me->HasAura(MageAssist_Stealth))
        ProcessDispel();
}

bool GroupMageAI::ProcessArcaneFlee()
{
   NearUnitVec enemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && enemys.size() > 0 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageAssist_Grace, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->HasAura(MageAssist_Grace))
        {
            if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
    }
    if (enemys.size() > 1)
    {
        Unit* player = enemys[urand(0, enemys.size() - 1)];
        if (TargetCanPolymorph(player) && me->HasAura(MageAssist_Grace))
        {
            if (TryCastSpell(MageConfine_ToSheep, player) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastPolymorph(player);
                return true;
            }
        }
    }

    return false;
}

bool GroupMageAI::ProcessFireFlee()
{
   NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && enemys.size() > 0 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (me->GetDistance(pTarget) < 8.0f && TryCastSpell(MageGuard_FireBreath, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (enemys.size() > 1 && TryCastSpell(MageGuard_FireNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (!pTarget->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->InArena())
        {
           NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
            for (Unit* pUnit : nearEnemys)
            {
                if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_POLYMORPH))
                    continue;
                if (!pUnit->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pUnit) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }

    return false;
}

bool GroupMageAI::ProcessFrostFlee()
{
   NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (MageGuard_FrostShield)
    {
        if (enemys.size() > 0 && !me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (MageGuard_MagicShield)
    {
        if (healthPct <= 50 && enemys.size() > 0 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!BotUtility::SpellHasReady(me, MageGuard_FrostNova) && enemys.size() > 0)
    {
        if (TryCastSpell(MageAssist_FastColddown, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

void GroupMageAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (PetTryCastSpell(MagePet_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!HasAuraMechanic(pTarget, MECHANIC_ROOT) && me->GetDistance(pTarget->GetPosition()) < 8 && TryCastSpell(MageGuard_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    switch (GetMageTalentType())
    {
    case 0:
        ProcessArcaneMeleeSpell(pTarget);
        break;
    case 1:
        ProcessFireMeleeSpell(pTarget);
        break;
    case 2:
        ProcessFrostMeleeSpell(pTarget);
        break;
    }
}

void GroupMageAI::ProcessRangeSpell(Unit* pTarget)
{
    ProcessPetAttack(pTarget);
    if (!me->IsInCombat())
    {
        //if (!me->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, me) == SpellCastResult::SPELL_CAST_OK)
        //	return;
        if (MageIDLE_MgcArmor)
        {
            if (!me->HasAura(MageIDLE_MgcArmor) && TryCastSpell(MageIDLE_MgcArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (MageIDLE_FireArmor)
        {
            if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (MageIDLE_FrostArmor)
        {
            if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else
    {
        if (TryCastSpell(MageAssist_Mirror, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 8 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (manaPct < 60 && UseManaJewel())
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    Unit* castEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (castEnemy && TryCastSpell(MageConfine_BreakCast, castEnemy) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 20 && RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE).size() > 0 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (ProcessPolymorph(pTarget))
    //	return;
    //uint32 stealRate = urand(0, 99);
    //if (stealRate < 15 && TryCastSpell(MageConfine_AuraSteal, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;

    ProcessDispel();
    switch (GetMageTalentType())
    {
    case 0:
        ProcessArcaneRangeSpell(pTarget);
        break;
    case 1:
        ProcessFireRangeSpell(pTarget);
        break;
    case 2:
        ProcessFrostRangeSpell(pTarget);
        break;
    }
}

void GroupMageAI::ProcessArcaneRangeSpell(Unit* pTarget)
{
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 3 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (TryCastSpell(MageAssist_ArcanePower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (RangeEnemyListByTargetIsMe(20).size() <= 0 && TryCastSpell(MageArcane_ArcaneShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageArcane_Bullet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupMageAI::ProcessFireRangeSpell(Unit* pTarget)
{
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 3 && TryCastSpell(MageAOE_FireStorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
   NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : nearEnemys)
    {
        if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_POLYMORPH))
            continue;
        if (!pUnit->IsInCombat())
            continue;
        if (!pUnit->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!me->HasAura(MageAssist_FireCritAura) && TryCastSpell(MageAssist_FireCritAura, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFStorm))
    {
        TryCastSpell(MageAOE_FireStorm, pTarget, true);
        return;
    }
    if (MageFire_BigFireBall && me->HasAura(MageFlag_FastBFBall))
    {
        TryCastSpell(MageFire_BigFireBall, pTarget);// , true);
        return;
    }
    //if (CanCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (MageFire_Firing && urand(0, 99) < 15)
    {
        if (TryCastSpell(MageFire_Firing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupMageAI::ProcessFrostRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 3 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageAssist_CastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFFArrow))
    {
        if (MageFrost_FFArrow)
        {
            TryCastSpell(MageFrost_FFArrow, pTarget, true);
            return;
        }
        TryCastSpell(MageFire_FireArrow, pTarget, true);
        return;
    }
    if (TryCastSpell(MageAssist_FrostPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageFrost_IceArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupMageAI::ProcessArcaneMeleeSpell(Unit* /*pTarget*/)
{

}

void GroupMageAI::ProcessFireMeleeSpell(Unit* /*pTarget*/)
{

}

void GroupMageAI::ProcessFrostMeleeSpell(Unit* /*pTarget*/)
{

}

bool GroupMageAI::ProcessPolymorph(Unit* pTarget)
{
    if (!pTarget)
        return false;
   NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        if (!TargetCanPolymorph(pUnit))
            continue;
        if (TryCastSpell(MageConfine_ToSheep, pUnit) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastPolymorph(pUnit);
            return true;
        }
    }

    return false;
}

bool GroupMageAI::ProcessFreezeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (TargetCanFreeze(pTarget) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
    {
        if (m_BotTalentType == 2 && MageConfine_Freeze && me->getLevel() == 80 &&
            !pTarget->HasAura(MageConfine_Freeze) && TryCastSpell(MageConfine_Freeze, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageFrost_IceLance, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
   NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        if (!TargetCanFreeze(pUnit))
            continue;
        if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
            continue;
        if (m_BotTalentType == 2 && MageConfine_Freeze && me->getLevel() == 80 &&
            !pUnit->HasAura(MageConfine_Freeze) && TryCastSpell(MageConfine_Freeze, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageFrost_IceLance, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void GroupMageAI::ProcessPetAttack(Unit* pTarget)
{
    Pet* pPet = me->GetPet();
    if (pPet)
    {
        Position pos;
        Unit* pPetTarget = pPet->GetVictim();
        if (pPetTarget != pTarget)
        {
            WorldSession* pSession = me->GetSession();
            if (pTarget)
                pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
            else
                pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
        }
    }
}

bool GroupMageAI::ProcessFullDispel()
{
    if (!m_FullDispel)
        return false;
    if (me->IsMounted())
    {
        m_FullDispel = 0;
        return false;
    }
    if (MageAssist_DecCurse != 0)
    {
        if (ProcessDispel())
            return true;
        else if (!BotUtility::SpellHasReady(me, MageAssist_DecCurse))
            return true;
    }
    if (m_FullDispel < getMSTime())
        m_FullDispel = 0;
    return false;
}

bool GroupMageAI::ProcessDispel()
{
    if (MageAssist_DecCurse == 0 || !BotUtility::SpellHasReady(me, MageAssist_DecCurse))
        return false;
   NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT))
        {
            if (TryCastSpell(MageAssist_DecCurse, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

void GroupMageAI::OnCastPolymorph(Unit* pTarget)
{
    m_LastPolymorphTarget = pTarget->GetGUID();
    if (me->GetTarget() == m_LastPolymorphTarget)//GetTargetGUID
        me->SetSelection(ObjectGuid::Empty);
    me->AttackStop();
   NearUnitVec friends = SearchFriendTargetIsTarget(pTarget);
    for (Unit* pFriend : friends)
    {
        if (pFriend->GetTarget() == pTarget->GetTarget())//GetTargetGUID-->GetTarget
        {
            Player* player = pFriend->ToPlayer();
            if (player)
                player->SetSelection(ObjectGuid::Empty);
        }
    }
}

bool GroupMageAI::TargetCanPolymorph(Unit* pTarget)
{
    if (!MageConfine_ToSheep)
        return false;
    if (pTarget->GetHealthPct() <= 85.0f)
        return false;
    if (pTarget->HasAura(MageConfine_ToSheep))
        return false;

    if (BotUtility::ControllSpellDiminishing && !TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_DISORIENT))
        return false;
    if (m_LastPolymorphTarget != ObjectGuid::Empty)
    {
        if (Player* pPlayer = ObjectAccessor::FindPlayer(m_LastPolymorphTarget))
        {
            if (pPlayer->GetMap() != me->GetMap())
                m_LastPolymorphTarget = ObjectGuid::Empty;
            else
            {
                if (HasAuraMechanic(pPlayer, Mechanics::MECHANIC_POLYMORPH))
                    return false;
                if (pPlayer->HasAura(MageConfine_ToSheep))
                    return false;
            }
        }
        else
            m_LastPolymorphTarget = ObjectGuid::Empty;
    }

    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE))
        return false;
    //else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
    //	return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return false;

    if (SearchFriendTargetIsTarget(pTarget, NEEDFLEE_CHECKRANGE).size() > 0)
        return false;

    return true;
}

void GroupMageAI::OnCastTeleport()
{
    Position telePos = GetTeleportSpellPos();
    me->GetMotionMaster()->Clear();
    m_Movement->ClearMovement();
    SetTeleport(telePos);
}

Position GroupMageAI::GetTeleportSpellPos()
{
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = me->GetPosition();
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        Position pos = me->GetFirstCollisionPosition(BOTAI_RANGESPELL_DISTANCE, angle);
        //pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseMask(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return targetPos;
    for (Position pos : allPosition)
    {
        float dist = me->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

bool GroupMageAI::UseManaJewel()
{
    std::lock_guard<std::mutex> lock(m_ItemLock);
    Item* pItem = FindExistManaJewel();
    if (!pItem)
        return false;
    SpellCastTargets targets;
    targets.SetTargetMask(0);
    /*if (me->CastItemUseSpell(pItem, targets, 0, ObjectGuid::Empty) == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }*/
    return false;
}

Item* GroupMageAI::FindExistManaJewel()
{
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = me->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate)
            continue;
        if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
            return pItem;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = me->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = pBag->GetItemByPos(uint8(j));
                if (!pItem)
                    continue;
                const ItemTemplate* pTemplate = pItem->GetTemplate();
                if (!pTemplate)
                    continue;
                if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
                    return pItem;
            }
        }
    }
    return NULL;
}

uint32 GroupMageAI::GetMageTalentType()
{
    if (me->getLevel() < 10)
        return 1;
    return m_BotTalentType;
}

bool GroupMageAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (MageConfine_BreakCast && TryCastSpell(MageConfine_BreakCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

void GroupMageAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 550) + power);
}

uint32 GroupMageAI::TryCastSummonRiteSpell()
{
    if (MageIDLE_SummonRite == 0 || !me->HasSpell(MageIDLE_SummonRite))
        return 0;
    if (!me->IsAlive() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING))
        return 0;
    std::list<GameObject*> goResults;
    Trinity::GameObjectInRangeCheck checkerGO(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), BOTAI_SEARCH_RANGE);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcherGO(me, goResults, checkerGO);
    //me->VisitNearbyGridObject(BOTAI_SEARCH_RANGE, searcherGO);
    for (GameObject* go : goResults)
    {
        if (go->GetSpellId() == MageIDLE_SummonRite)
            return 0;
    }
    Group* pGroup = me->GetGroup();
    if (pGroup)
    {
        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
        for (Group::MemberSlot const& slot : memList)
        {
            Player* player = ObjectAccessor::FindPlayer(slot.guid);
            if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                continue;
            if (BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(me->GetAI()))
            {
                if (pAI->CastingSummonRite())
                    return 0;
            }
        }
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(MageIDLE_SummonRite,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    /*TriggerCastData data;
    data.triggerFlags = TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM);
    Spell* spell = new Spell(me, spellInfo, data);
    spell->m_CastItem = NULL;
    SpellCastTargets targets;
    targets.SetUnitTarget(me);*/
    Dismount();/*
    SpellCastResult castResult = spell->prepare(&targets);*/
    /*if (castResult == SPELL_CAST_OK)
        return MageIDLE_SummonRite;*/
    return 0;
}
