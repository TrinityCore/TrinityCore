
#include "BotPriestAI.h"
#include "Group.h"

void BotPriestAI::InitializeSpells()
{
    PriestIDLE_AllHardRes = FindMaxRankSpellByExist(43939);
    PriestIDLE_HardRes = FindMaxRankSpellByExist(23948);
    PriestIDLE_SoulFire = FindMaxRankSpellByExist(48168);
    PriestIDLE_AllSpiritRes = FindMaxRankSpellByExist(43939);
    PriestIDLE_SpiritRes = FindMaxRankSpellByExist(23948);
    PriestIDLE_Bloodsucker = FindMaxRankSpellByExist(15286);
    PriestIDLE_AllShadowRes = FindMaxRankSpellByExist(53915);
    PriestIDLE_ShadowRes = FindMaxRankSpellByExist(53915);
    PriestIDLE_ShadowStatus = FindMaxRankSpellByExist(16592);

    PriestGuard_ShadowFear = FindMaxRankSpellByExist(34984);
    PriestGuard_AOEFear = FindMaxRankSpellByExist(8122);
    PriestGuard_DefFear = FindMaxRankSpellByExist(65544);
    PriestGuard_RecoverMana = FindMaxRankSpellByExist(65544);
    PriestGuard_DmgAnnul = FindMaxRankSpellByExist(33206);
    PriestGuard_DefShield = FindMaxRankSpellByExist(17);
    PriestGuard_SelfHealth = FindMaxRankSpellByExist(19236);
    PriestGuard_GuardSoul = FindMaxRankSpellByExist(47788);

    PriestAssist_SoulAbs = FindMaxRankSpellByExist(196762);
    PriestAssist_AddHolyPower = FindMaxRankSpellByExist(10060);
    PriestAssist_AllDispel = FindMaxRankSpellByExist(4526);
    PriestAssist_Dispel = FindMaxRankSpellByExist(528);
    PriestAssist_ShadowDemon = FindMaxRankSpellByExist(10060);
    PriestAssist_Silence = FindMaxRankSpellByExist(8988);
    PriestAssist_AllResMana = FindMaxRankSpellByExist(64843);
    PriestAssist_AllResLife = FindMaxRankSpellByExist(64843);

    PriestDebuf_Ache = FindMaxRankSpellByExist(11639);
    PriestDebuf_Drown = FindMaxRankSpellByExist(41375);
    PriestDebuf_Plague = FindMaxRankSpellByExist(138490);
    PriestAOE_ShadowExplode = FindMaxRankSpellByExist(138490);
    PriestAOE_HolyNova = FindMaxRankSpellByExist(20694);

    PriestShadow_ShadowTouch = FindMaxRankSpellByExist(18152);
    PriestShadow_Knocking = FindMaxRankSpellByExist(17194);
    PriestShadow_Lech = FindMaxRankSpellByExist(15407);
    PriestHoly_Smite = FindMaxRankSpellByExist(585);
    PriestHoly_BigFire = FindMaxRankSpellByExist(17141);
    PriestPrecept_ManaBurn = FindMaxRankSpellByExist(2691);

    PriestHeal_LowHeal = FindMaxRankSpellByExist(8812);
    PriestHeal_Resume = FindMaxRankSpellByExist(27606);
    PriestHeal_FastHeal = FindMaxRankSpellByExist(27608);
    PriestHeal_BigHeal = FindMaxRankSpellByExist(34119);
    PriestHeal_LinkHeal = FindMaxRankSpellByExist(32546);
    PriestHeal_UnionHeal = FindMaxRankSpellByExist(225275);
    PriestHeal_RingHeal = FindMaxRankSpellByExist(49306);
    PriestHeal_AOEHeal = FindMaxRankSpellByExist(596);
    PriestHeal_Awareness = FindMaxRankSpellByExist(47540);

    PriestFlag_DeadSoul = 20711;
    PriestFlag_NonShield = 6788;
}

void BotPriestAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotPriestAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    m_ReadyCurrentPrayer = 0;
    InitializeSpells();
    if (PriestGuard_GuardSoul == 0 && m_BotTalentType == 1 && me->getLevel() == 80)
    {
        me->LearnSpell(47788, false);
        PriestGuard_GuardSoul = FindMaxRankSpellByExist(47788);
    }
    if (PriestGuard_RecoverMana == 0 && m_BotTalentType == 2 && me->getLevel() == 80)
    {
        me->LearnSpell(47585, false);
        PriestGuard_RecoverMana = FindMaxRankSpellByExist(47585);
    }
}

uint32 BotPriestAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool BotPriestAI::HaveManaStore()
{
    return GetManaPowerPer() >= 5;
}

bool BotPriestAI::CastBuffPrayer()
{
    Group* pGroup = me->GetGroup();
    if (PriestIDLE_AllShadowRes)
    {
        if (!me->HasAura(PriestIDLE_AllShadowRes))
        {
            TryCastSpell(PriestIDLE_AllShadowRes, me, true);
            return true;
        }
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld() || me->GetDistance(player) > BOTAI_RANGESPELL_DISTANCE)
                    continue;
                if (!player->HasAura(PriestIDLE_AllShadowRes) && TryCastSpell(PriestIDLE_AllShadowRes, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    if (PriestIDLE_AllSpiritRes)
    {
        if (!me->HasAura(PriestIDLE_AllSpiritRes))
        {
            TryCastSpell(PriestIDLE_AllSpiritRes, me, true);
            return true;
        }
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld() || me->GetDistance(player) > BOTAI_RANGESPELL_DISTANCE)
                    continue;
                if (!player->HasAura(PriestIDLE_AllSpiritRes) && TryCastSpell(PriestIDLE_AllSpiritRes, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    if (PriestIDLE_AllHardRes)
    {
        if (!me->HasAura(PriestIDLE_AllHardRes))
        {
            TryCastSpell(PriestIDLE_AllHardRes, me, true);
            return true;
        }
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld() || me->GetDistance(player) > BOTAI_RANGESPELL_DISTANCE)
                    continue;
                if (!player->HasAura(PriestIDLE_AllHardRes) && TryCastSpell(PriestIDLE_AllHardRes, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

bool BotPriestAI::NeedWaitSpecialSpell(uint32 diff)
{
    if (BotBGAI::NeedWaitSpecialSpell(diff))
        return true;
    return false;
}

void BotPriestAI::EachTick()
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
            me->SetPower(Powers::POWER_MANA, (max / 600) + power);
            return;
        }
    }
    else
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 400) + power);
}

bool BotPriestAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    NearUnitVec nearEnemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (me->InArena())
    {
        for (Unit* pUnit : nearEnemys)
        {
            if (m_NeedFlee.TargetHasFleeAura(pUnit))
            {
                me->SetSelection(pUnit->GetGUID());
                return true;
            }
        }
    }
    else if (nearEnemys.size() > 0)
    {
        Unit* pNear = nearEnemys[urand(0, nearEnemys.size() - 1)];
        me->SetSelection(pNear->GetGUID());
        return true;
    }
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    if (me->InArena() && !IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void BotPriestAI::ProcessReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (!me->HasAura(PriestIDLE_SoulFire) && TryCastSpell(PriestIDLE_SoulFire, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2)
    {
        if (!me->HasAura(PriestIDLE_Bloodsucker) && TryCastSpell(PriestIDLE_Bloodsucker, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    CastBuffPrayer();
}

bool BotPriestAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return false;
    return true;
}

bool BotPriestAI::IsAttacker()
{
    return (m_BotTalentType == 2);
}

bool BotPriestAI::ProcessNormalSpell()
{
    if (!me->HasAura(PriestIDLE_SoulFire) && TryCastSpell(PriestIDLE_SoulFire, me) == SpellCastResult::SPELL_CAST_OK)
        return false;
    if (GetManaPowerPer() < 20)
        return TryUpMount();
    if (CastBuffPrayer())
        return false;

    if (me->HasAura(m_UseMountID))
        return false;
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

void BotPriestAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    else
        return;

    if (!me->HasAura(PriestIDLE_SoulFire) && TryCastSpell(PriestIDLE_SoulFire, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    float healthPct = me->GetHealthPct();
    NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 1)
    {
        if (TryCastSpell(PriestGuard_AOEFear, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    NearUnitVec rangeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (rangeEnemys.size() > 0 && healthPct < 80)
    {
        if (!me->HasAura(PriestGuard_DefShield) && !me->HasAura(PriestFlag_NonShield))
        {
            if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
                me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            if (TryCastSpell(PriestGuard_DefShield, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!me->HasAura(PriestHeal_Resume, me->GetGUID()))
        {
            if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
                me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            if (TryCastSpell(PriestHeal_Resume, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }

    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (!pTarget->HasAura(PriestDebuf_Ache, me->GetGUID()) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague, me->GetGUID()) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0)
    {
        if (healthPct < 30 && rangeEnemys.size() > 0 && TryCastSpell(PriestGuard_DmgAnnul, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (m_BotTalentType == 1)
    {
        if (PriestHeal_RingHeal)
        {
            NearUnitVec needHeals = SearchLifePctByFriendRange(me, 75);
            if (needHeals.size() > 1)
            {
                if (TryCastSpell(PriestHeal_RingHeal, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
                Unit* rndNeedHealPlayer = needHeals[urand(0, needHeals.size() - 1)];
                if (!rndNeedHealPlayer->HasAura(PriestHeal_Resume, me->GetGUID()) && TryCastSpell(PriestHeal_Resume, rndNeedHealPlayer) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (healthPct < 60 && rangeEnemys.size() > 0 && TryCastSpell(PriestGuard_SelfHealth, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 8 && rangeEnemys.size() > 0 && me->getLevel() == 80 && TryCastSpell(PriestGuard_GuardSoul, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (PriestAssist_ShadowDemon && GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_ShadowDemon, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessManaRevive())
        return;

    ProcessDispel();
}

void BotPriestAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (me->GetDistance(pTarget) > 30)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;
    if (me->HasUnitState(UNIT_STATE_MOVING))
        me->StopMoving();
    if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
    {
        me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    }
    if (SearchLifePctByFriendRange(pTarget, 70).size() > 2)
    {
        if (m_BotTalentType == 1 && PriestHeal_RingHeal && TryCastSpell(PriestHeal_RingHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_AOEHeal && TryCastSpell(PriestHeal_AOEHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (SearchLifePctByFriendRange(me, 70).size() > 2)
    {
        if (PriestAssist_AllResLife && TryCastSpell(PriestAssist_AllResLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    float selfLifePct = me->GetHealthPct();
    float healthPct = pTarget->GetHealthPct();
    if (PriestHeal_LinkHeal && me != pTarget && selfLifePct < 75 && healthPct < 75)
    {
        if (TryCastSpell(PriestHeal_LinkHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 0 && PriestAssist_SoulAbs && manaPct < 40 && !me->HasAura(PriestAssist_SoulAbs) && BotUtility::SpellHasReady(me, PriestAssist_SoulAbs))
    {
        if (TryCastSpell(PriestAssist_SoulAbs, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 0 && PriestAssist_AddHolyPower && manaPct < 40 && !me->HasAura(PriestAssist_AddHolyPower) && BotUtility::SpellHasReady(me, PriestAssist_AddHolyPower))
    {
        if (TryCastSpell(PriestAssist_AddHolyPower, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 20)
    {
        if (m_BotTalentType == 1 && PriestGuard_GuardSoul && me->getLevel() == 80 && TryCastSpell(PriestGuard_GuardSoul, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestGuard_DmgAnnul && TryCastSpell(PriestGuard_DmgAnnul, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!pTarget->HasAura(PriestFlag_NonShield) && TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal && TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (healthPct >= 20 && healthPct < 65)
    {
        if (!pTarget->HasAura(PriestFlag_NonShield) && TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_BigHeal && TryCastSpell(PriestHeal_BigHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (healthPct >= 65 && healthPct < 90)
    {
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!pTarget->HasAura(PriestHeal_Resume, me->GetGUID()) && TryCastSpell(PriestHeal_Resume, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal && TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_AllResMana, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    ProcessDispel();
}

void BotPriestAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{
}

void BotPriestAI::ProcessRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestGuard_DefFear) && TryCastSpell(PriestGuard_DefFear, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 8 && TryCastSpell(PriestDebuf_Drown, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Ache, me->GetGUID()) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague, me->GetGUID()) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_ShadowDemon && GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_ShadowDemon, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_AllResMana, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() < 30)
    {
        ProcessHealthSpell(me);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
    }

    switch (m_BotTalentType)
    {
    case 0:
    case 1:
        ProcessNormalRangeSpell(pTarget);
        break;
    case 2:
        ProcessShadowRangeSpell(pTarget);
        break;
    }
}

void BotPriestAI::ProcessNormalRangeSpell(Unit* pTarget)
{
    if (ProcessManaBurn())
        return;
    if (TryCastSpell(PriestHoly_BigFire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestHoly_Smite, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotPriestAI::ProcessShadowRangeSpell(Unit* pTarget)
{
    if (ProcessArenaHealthMember())
        return;
    if (ProcessManaRevive())
        return;
    if (!me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me, true) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_Silence && pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(PriestAssist_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAOE_ShadowExplode && RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 4 && TryCastSpell(PriestAOE_ShadowExplode, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    uint32 rate = urand(0, 99);
    if (rate < 30 && TryCastSpell(PriestShadow_ShadowTouch, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Lech, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool BotPriestAI::ProcessArenaHealthMember()
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
        if (healPct > 40)
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

bool BotPriestAI::ProcessManaBurn()
{
    if (!me->InArena() || !PriestPrecept_ManaBurn)
        return false;
    if (GetManaPowerPer() < 30)
        return false;
    NearUnitVec minorUnits;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : enemys)
    {
        if (!TargetCanManaBurn(pUnit->ToPlayer()))
            continue;
        if (TargetIsHealth(pUnit->ToPlayer()))
        {
            if (TryCastSpell(PriestPrecept_ManaBurn, pUnit) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
        else
            minorUnits.push_back(pUnit);
    }
    for (Unit* pUnit : minorUnits)
    {
        if (TryCastSpell(PriestPrecept_ManaBurn, pUnit) == SpellCastResult::SPELL_CAST_OK)
        {
            return true;
        }
    }
    return false;
}

bool BotPriestAI::ProcessManaRevive()
{
    if (m_BotTalentType != 2 || me->getLevel() != 80 || !PriestGuard_RecoverMana)
        return false;
    uint32 manaPct = GetManaPowerPer();
    uint32 lifePct = uint32(me->GetHealthPct());
    if (manaPct < 8 || (lifePct < 8 && manaPct < 60 && RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() > 0))
    {
        if (TryCastSpell(PriestGuard_RecoverMana, me) == SpellCastResult::SPELL_CAST_OK)
        {
            return true;
        }
    }
    return false;
}

bool BotPriestAI::ProcessDispel()
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
            if (TryCastSpell(PriestAssist_Dispel, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}
