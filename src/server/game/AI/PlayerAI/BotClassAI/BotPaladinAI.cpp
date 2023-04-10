
#include "BotPaladinAI.h"
#include "BotBGAIMovement.h"
#include "Group.h"

void BotPaladinAI::InitializeSpells()
{
    PaladinIDLE_MountAura = FindMaxRankSpellByExist(225454);
    PaladinIDLE_CastAura = FindMaxRankSpellByExist(81455);
    PaladinIDLE_JudgeAura = FindMaxRankSpellByExist(8990);
    PaladinIDLE_ArmorAura = FindMaxRankSpellByExist(41105);
    PaladinIDLE_AOEGuardWish = FindMaxRankSpellByExist(210256);
    PaladinIDLE_AOEKingWish = FindMaxRankSpellByExist(43223);
    PaladinIDLE_AOEWitWish = FindMaxRankSpellByExist(203539);
    PaladinIDLE_AOEStrWish = FindMaxRankSpellByExist(29381);
    PaladinIDLE_JusticeRage = FindMaxRankSpellByExist(25780);

    PaladinGuard_UnShield = FindMaxRankSpellByExist(29381);
    PaladinGuard_FreeAura = FindMaxRankSpellByExist(1044);
    PaladinGuard_Invincible = FindMaxRankSpellByExist(642);
    PaladinGuard_Sacrifice = FindMaxRankSpellByExist(187190);
    PaladinGuard_AOESacrifice = FindMaxRankSpellByExist(13903);
    PaladinGuard_BlockShield = FindMaxRankSpellByExist(31904);
    PaladinGuard_PhyImmune = FindMaxRankSpellByExist(66009);

    PaladinAssist_UpPower = FindMaxRankSpellByExist(31842);
    PaladinAssist_RevengeStamp = FindMaxRankSpellByExist(45095);
    PaladinAssist_LifeStamp = FindMaxRankSpellByExist(165745);
    PaladinAssist_ManaStamp = FindMaxRankSpellByExist(130433);
    PaladinAssist_JusticeStamp = FindMaxRankSpellByExist(38008);
    PaladinAssist_StunStamp = FindMaxRankSpellByExist(50907);
    PaladinAssist_ComStamp = FindMaxRankSpellByExist(13903);
    PaladinAssist_Confession = FindMaxRankSpellByExist(173315);
    PaladinAssist_StunMace = FindMaxRankSpellByExist(66863);
    PaladinAssist_ReviveMana = FindMaxRankSpellByExist(173521);
    PaladinAssist_HealCrit = FindMaxRankSpellByExist(210294);
    PaladinAssist_LowMana = FindMaxRankSpellByExist(20271);
    PaladinAssist_AuraUP = FindMaxRankSpellByExist(31821);
    PaladinAssist_Dispel = FindMaxRankSpellByExist(4987);

    PaladinHeal_FastHoly = FindMaxRankSpellByExist(19750);
    PaladinHeal_BigHoly = FindMaxRankSpellByExist(13952);
    PaladinHeal_FullHoly = FindMaxRankSpellByExist(9257);

    PaladinMelee_AOEOffertory = FindMaxRankSpellByExist(251152);
    PaladinMelee_KillMace = FindMaxRankSpellByExist(37259);
    PaladinMelee_FlyShield = FindMaxRankSpellByExist(31935);
    PaladinMelee_ShieldAtt = FindMaxRankSpellByExist(53600);
    PaladinMelee_MaceAtt = FindMaxRankSpellByExist(53595);
    PaladinMelee_HolyAtt = FindMaxRankSpellByExist(25914);
    PaladinMelee_LifeJudge = FindMaxRankSpellByExist(31804);
    PaladinMelee_ManaJudge = FindMaxRankSpellByExist(41368);
    PaladinMelee_FleeJudge = FindMaxRankSpellByExist(201371);
    PaladinMelee_WeaponAtt = FindMaxRankSpellByExist(213844);
    PaladinMelee_HolyStrom = FindMaxRankSpellByExist(163888);

    PaladinFlag_MomentHoly = 251152;
    PaladinFlag_Discipline = 25771;
}

void BotPaladinAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotPaladinAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    InitializeSpells();
}

uint32 BotPaladinAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void BotPaladinAI::EachTick()
{
    BotBGAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    Group* pGroup = me->GetGroup();
    if (pGroup)
    {
        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
        for (Group::MemberSlot const& slot : memList)
        {
            Player* player = ObjectAccessor::FindPlayer(slot.guid);
            if (!player || me->GetMap() != player->GetMap() || !player->IsInWorld() || player->IsPlayerBot())
                continue;
            uint32 max = me->GetMaxPower(Powers::POWER_MANA);
            uint32 power = me->GetPower(Powers::POWER_MANA);
            me->SetPower(Powers::POWER_MANA, (max / 650) + power);
            return;
        }
    }
    else
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 400) + power);
}

void BotPaladinAI::ProcessReady()
{
    ProcessNormalSpell();
}

bool BotPaladinAI::ProcessAura()
{
    if (me->IsMounted() && !me->IsInCombat())
    {
        if (PaladinIDLE_MountAura && !me->HasAura(PaladinIDLE_MountAura) && TryCastSpell(PaladinIDLE_MountAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (m_BotTalentType == 0)
        {
            if (!me->HasAura(PaladinIDLE_CastAura) && TryCastSpell(PaladinIDLE_CastAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 1)
        {
            if (!me->HasAura(PaladinIDLE_ArmorAura) && TryCastSpell(PaladinIDLE_ArmorAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 2)
        {
            if (!me->HasAura(PaladinIDLE_JudgeAura) && TryCastSpell(PaladinIDLE_JudgeAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotPaladinAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (!me->HasAura(m_UseMountID) && ProcessStamp())
        return false;

    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    for (Unit* player : friends)
    {
        if (!player->ToPlayer())
            continue;
        if (NeedUseGuardWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEGuardWish, player, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
        //if (NeedUseWitWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEWitWish, player, true) == SpellCastResult::SPELL_CAST_OK)
        //	return false;
        if (NeedUseStrWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEStrWish, player, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
        if (NeedUseKingWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEKingWish, player, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }

    if (ProcessAura())
        return true;
    if (me->HasAura(m_UseMountID))
    {
        return false;
    }
    NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
    if (needHealthPlayers.empty())
        return TryUpMount();
    //me->StopMoving();
    Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
    ProcessHealthSpell(healthPlayer);
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

void BotPaladinAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (!IsInvincible(me) && me->GetHealthPct() < 25)
        {
            me->StopMoving();
            if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
            FleeMovement();
    }
    else
        return;
    if (ProcessAura())
        return;
    if (ProcessStamp())
        return;
    if (PaladinGuard_UnShield && !me->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && me->HasAura(PaladinFlag_MomentHoly) && me->GetHealthPct() < 90)
    {
        if (TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TargetNeedInvincible(me) && TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessTryFriendImmune())
        return;
    if (ProcessFreeAura())
        return;
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        Unit* player = enemys[urand(0, enemys.size() - 1)];
        if (!HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_StunMace, player) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!m_NeedReserveCtrlSpell && !HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_Confession, player) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() < 40)
    {
        if (m_BotTalentType == 0 && PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

bool BotPaladinAI::ProcessArenaHealthMember()
{
    if (!me->InArena())
        return false;
    if (GetManaPowerPer() < 15)
        return false;
    float minLife = 100;
    Unit* minLifeUnit = NULL;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : friends)
    {
        float healPct = pUnit->GetHealthPct();
        if (healPct > 50)
            continue;
        if (minLifeUnit == NULL || healPct < minLife)
        {
            minLife = healPct;
            minLifeUnit = pUnit;
        }
    }
    if (minLifeUnit)
    {
        ProcessHealthSpell(minLifeUnit);
        return true;
    }
    return false;
}

bool BotPaladinAI::ProcessControl(Unit* pTarget)
{
    if (!pTarget)
        pTarget = me->GetSelectedUnit();
    if (pTarget && PaladinAssist_StunMace && !TargetIsCtrl(pTarget) && BotUtility::SpellHasReady(me, PaladinAssist_StunMace))
    {
        if (!BotUtility::ControllSpellDiminishing || TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_STUN))
        {
            if (TryCastSpell(PaladinAssist_StunMace, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    if (PaladinAssist_StunMace && me->InArena() && BotUtility::SpellHasReady(me, PaladinAssist_StunMace))
    {
        NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        for (Unit* pUnit : enemys)
        {
            if (pTarget == pUnit)
                continue;
            if (TargetIsCtrl(pUnit))
                continue;
            if (!BotUtility::ControllSpellDiminishing || TargetIsNotDiminishingByType(pUnit, DiminishingGroup::DIMINISHING_STUN))
            {
                if (TryCastSpell(PaladinAssist_StunMace, pUnit) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    if (m_BotTalentType == 2 && PaladinAssist_Confession && !m_NeedReserveCtrlSpell)
    {
        NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_TOTEMRANGE);
        if (enemys.size() <= 1)
            return false;
        for (Unit* pUnit : enemys)
        {
            if (me->GetTarget() == pUnit->GetGUID())//GetTargetGUID
                continue;
            if (TargetIsCtrl(pUnit))
                continue;
            if (SearchFriendTargetIsTarget(pUnit, BOTAI_SEARCH_RANGE).size() > 0)
                continue;
            if (TryCastSpell(PaladinAssist_Confession, pUnit) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotPaladinAI::ProcessFreeAura()
{
    if (!PaladinGuard_FreeAura)
        return false;
    if (TargetNeedFree(me) && TryCastSpell(PaladinGuard_FreeAura, me) == SpellCastResult::SPELL_CAST_OK)
        return true;

    if (!me->InArena())
        return false;
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        if (pUnit == me || IsInvincible(pUnit))
            continue;
        if (!TargetNeedFree(pUnit))
            continue;
        if (TryCastSpell(PaladinGuard_FreeAura, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool BotPaladinAI::ProcessTryFriendImmune()
{
    if (ProcessTryFullHealth())
        return true;
    if (!PaladinGuard_PhyImmune || !me->InArena())
        return false;
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        if (pUnit->GetHealthPct() > 12)
            continue;
        if (IsInvincible(pUnit))
            continue;
        if (!pUnit->HasAura(PaladinFlag_Discipline))
        {
            if (TryCastSpell(PaladinGuard_PhyImmune, pUnit) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotPaladinAI::ProcessTryFullHealth()
{
    if (!PaladinHeal_FullHoly || me->InArena())
        return false;
    if (me->GetHealthPct() > 8)
        return false;
    if (IsInvincible(me))
        return false;
    if (TryCastSpell(PaladinHeal_FullHoly, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

void BotPaladinAI::ProcessHealthSpell(Unit* pTarget)
{
    if (ProcessAura())
        return;
    if (me->GetDistance(pTarget) > 30)
        return;
    if (ProcessStamp())
        return;
    float manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;
    //if (pTarget != me && m_BotTalentType != 0)
    //{
    //	if (manaPct < 25)
    //		return;
    //}
    if (ProcessTryFriendImmune())
        return;
    if (ProcessControl(NULL))
        return;
    //if (PaladinGuard_UnShield && !IsInvincible(pTarget) && !pTarget->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    float life = pTarget->GetHealthPct();
    if (m_BotTalentType == 2 && me->HasAura(PaladinFlag_MomentHoly) && pTarget->GetHealthPct() < 85)
    {
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TargetNeedInvincible(me))
    {
        if (TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (life < 25)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (life >= 25 && life < 50)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(PaladinHeal_BigHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (life >= 50)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void BotPaladinAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (!pTarget)
        pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (ProcessAura())
        return;
    uint32 manaPct = GetManaPowerPer();
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (!IsInvincible(me) && me->GetHealthPct() < 40)
        {
            me->StopMoving();
            if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (IsInvincible(me) && me->GetHealthPct() < 80)
        {
            if (manaPct > 20)
            {
                me->StopMoving();
                if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (manaPct > 5)
            {
                me->StopMoving();
                if (TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
    else
        return;

    if (ProcessStamp())
        return;
    if (ProcessFreeAura())
        return;
    if (ProcessControl(pTarget))
        return;
    if (!me->InArena())
    {
        NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (enemys.size() > 2 && TryCastSpell(PaladinMelee_AOEOffertory, me, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TargetNeedInvincible(me))
    {
        if (TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (PaladinGuard_UnShield && !IsInvincible(me) && !me->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessTryFriendImmune())
        return;
    float meLife = me->GetHealthPct();
    if (PaladinAssist_UpPower && meLife > 80 && TryCastSpell(PaladinAssist_UpPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec tryKills = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : tryKills)
    {
        if (pUnit->GetHealthPct() >= 20)
            continue;
        if (TryCastSpell(PaladinMelee_KillMace, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 0 && meLife < 65)
    {
        if (PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (m_BotTalentType == 1)
    {
        if (PaladinMelee_FlyShield && TryCastSpell(PaladinMelee_FlyShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_ShieldAtt && TryCastSpell(PaladinMelee_ShieldAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_MaceAtt && TryCastSpell(PaladinMelee_MaceAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (m_BotTalentType == 2)
    {
        if (me->HasAura(PaladinFlag_MomentHoly) && meLife < 90 && TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_HolyStrom && TryCastSpell(PaladinMelee_HolyStrom, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_WeaponAtt && TryCastSpell(PaladinMelee_WeaponAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(PaladinMelee_LifeJudge, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (ProcessDispel())
        return;
    ProcessArenaHealthMember();
}

void BotPaladinAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (!pTarget)
        pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (ProcessStamp())
        return;
    if (ProcessAura())
        return;
    if (ProcessTryFriendImmune())
        return;
    if (ProcessControl(pTarget))
        return;
    if (ProcessFreeAura())
        return;
    if (me->InArena())
    {
        uint32 manaPct = GetManaPowerPer();
        if (!IsInvincible(me) && me->GetHealthPct() < 35)
        {
            me->StopMoving();
            if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (IsInvincible(me) && me->GetHealthPct() < 80)
        {
            if (manaPct > 20)
            {
                me->StopMoving();
                if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (manaPct > 5)
            {
                me->StopMoving();
                if (TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        ProcessArenaHealthMember();
    }
}

bool BotPaladinAI::ProcessStamp()
{
    float manaPct = GetManaPowerPer();
    if (manaPct < 15)
    {
        if (PaladinAssist_ReviveMana && !me->HasAura(PaladinAssist_ReviveMana) && TryCastSpell(PaladinAssist_ReviveMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (PaladinAssist_ManaStamp && !me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (PaladinMelee_ManaJudge && BotUtility::SpellHasReady(me, PaladinMelee_ManaJudge))
        {
            Unit* pTarget = me->GetSelectedUnit();
            if (pTarget && TryCastSpell(PaladinMelee_ManaJudge, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (me->InArena())
            {
                NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
                for (Unit* pUnit : enemys)
                {
                    if (TryCastSpell(PaladinMelee_ManaJudge, pUnit) == SpellCastResult::SPELL_CAST_OK)
                        return true;
                }
            }
        }
    }
    else if (manaPct > 80)
    {
        if (m_BotTalentType == 0)
        {
            if (!me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 1)
        {
            if (!me->HasAura(PaladinIDLE_JusticeRage) && TryCastSpell(PaladinIDLE_JusticeRage, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (!me->HasAura(PaladinAssist_LifeStamp) && TryCastSpell(PaladinAssist_LifeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 2)
        {
            if (PaladinAssist_ComStamp)
            {
                if (!me->HasAura(PaladinAssist_ComStamp) && TryCastSpell(PaladinAssist_ComStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else if (PaladinAssist_RevengeStamp)
            {
                if (!me->HasAura(PaladinAssist_RevengeStamp) && TryCastSpell(PaladinAssist_RevengeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else if (PaladinAssist_StunStamp)
            {
                if (!me->HasAura(PaladinAssist_StunStamp) && TryCastSpell(PaladinAssist_StunStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else
            {
                if (!me->HasAura(PaladinAssist_JusticeStamp) && TryCastSpell(PaladinAssist_JusticeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

bool BotPaladinAI::ProcessDispel()
{
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
            HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
            HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
            HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
            HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        {
            if (TryCastSpell(PaladinAssist_Dispel, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotPaladinAI::TryStartControlCommand()
{
    if (m_CruxControlTarget == ObjectGuid::Empty)
        return false;
    if (m_BotTalentType != 2 || !PaladinAssist_Confession)
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    Player* pTarget = ObjectAccessor::FindPlayer(m_CruxControlTarget);
    if (!pTarget || !TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT) || !pTarget->IsAlive() || TargetIsControl(pTarget))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        Player* pPlayer = pUnit->ToPlayer();
        if (!pPlayer)
            continue;
        if (BotBGAI* pAI = dynamic_cast<BotBGAI*>(pPlayer))
        {
            if (pAI->CastingControlCommandSpell())
            {
                m_CruxControlTarget = ObjectGuid::Empty;
                return false;
            }
        }
    }
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(PaladinAssist_Confession,DIFFICULTY_40);//DIFFICULTY_40    //I DID
    if (!spellInfo || spellInfo->IsPassive())
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }/*
    if (pTarget->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
        return true;
    if (!pTarget->HasSpellCooldown(spellInfo->Id))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }*/

    if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) < BOTAI_TOTEMRANGE)
    {
        TryCastSpell(PaladinAssist_Confession, pTarget);
    }
    else
    {
        if (!IsNotMovement())
            m_Movement->MovementTo(m_CruxControlTarget);
    }
    return true;
}

float BotPaladinAI::TryPushControlCommand(Player* pTarget)
{
    if (!pTarget || !pTarget->IsAlive() || !pTarget->IsInWorld() || me->GetMap() != pTarget->GetMap())
    {
        ClearCruxControlCommand();
        return -1;
    }
    if (m_BotTalentType != 2 || !PaladinAssist_Confession)
        return -1;
    if (!TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT))
        return -1;
    if (!BotUtility::SpellHasReady(pTarget, PaladinAssist_Confession))
        return -1;
    m_CruxControlTarget = pTarget->GetGUID();
    m_LastControlTarget = m_CruxControlTarget;
    return me->GetDistance(pTarget->GetPosition());
}

bool BotPaladinAI::TargetNeedInvincible(Unit* player)
{
    if (player->GetHealthPct() < 15 && player->IsInCombat() && !IsInvincible(player) && !player->HasAura(PaladinFlag_Discipline))
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_CHARM) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FEAR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        return true;
    }
    return false;
}

bool BotPaladinAI::TargetNeedFree(Unit* player)
{
    if (IsInvincible(player))
        return false;
    if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_DAZE))
        return true;
    return false;
}

bool BotPaladinAI::IsHealerBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool BotPaladinAI::IsAttacker()
{
    return (m_BotTalentType != 0);
}

bool BotPaladinAI::NeedUseGuardWish(Player* player)
{
    if (m_BotTalentType != 1 || !PaladinIDLE_AOEGuardWish || ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
        return true;
    case CLASS_HUNTER:
    case CLASS_ROGUE:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_DRUID:
        return false;
    }
    return false;
}

bool BotPaladinAI::NeedUseKingWish(Player* player)
{
    if (!PaladinIDLE_AOEKingWish || ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool BotPaladinAI::NeedUseWitWish(Player* player)
{
    if (!PaladinIDLE_AOEWitWish || ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_ROGUE:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
        return true;
    }
    return false;
}

bool BotPaladinAI::NeedUseStrWish(Player* player)
{
    if (!PaladinIDLE_AOEStrWish || ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
        return true;
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
        return false;
    }
    return false;
}

bool BotPaladinAI::ExistWish(Unit* player)
{
    if (PaladinIDLE_AOEGuardWish && player->HasAura(PaladinIDLE_AOEGuardWish))
        return true;
    if (PaladinIDLE_AOEKingWish && player->HasAura(PaladinIDLE_AOEKingWish))
        return true;
    if (PaladinIDLE_AOEWitWish && player->HasAura(PaladinIDLE_AOEWitWish))
        return true;
    if (PaladinIDLE_AOEStrWish && player->HasAura(PaladinIDLE_AOEStrWish))
        return true;
    return false;
}

bool BotPaladinAI::TargetIsCtrl(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE))
        return true;
    //else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
    //	return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}
