
#include "BotGroupClassAI.h"
#include "Group.h"

void GroupPriestAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupPriestAI::ResetBotAI()
{
    UpdateTalentType();
    BotGroupAI::ResetBotAI();
    m_ReadyCurrentPrayer = 0;
    InitializeSpells(me);

    if (PriestGuard_GuardSoul == 0 && m_BotTalentType == 1 && me->getLevel() == 80)
    {
        me->LearnSpell(47788, false);
        PriestGuard_GuardSoul = BotUtility::FindMaxRankSpellByExist(me, 47788);
    }
    if (PriestGuard_RecoverMana == 0 && m_BotTalentType == 2 && me->getLevel() == 80)
    {
        me->LearnSpell(47585, false);
        PriestGuard_RecoverMana = BotUtility::FindMaxRankSpellByExist(me, 47585);
    }

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(PriestIDLE_AllShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_AllSpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_AllHardRes);
    m_WishStore.RegisterWish(PriestIDLE_ShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_SpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_HardRes);
}

uint32 GroupPriestAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 2;
}

void GroupPriestAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.RegisterWish(PriestIDLE_AllShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_AllSpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_AllHardRes);
    m_WishStore.RegisterWish(PriestIDLE_ShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_SpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_HardRes);
}

uint32 GroupPriestAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool GroupPriestAI::CastBuffPrayer()
{
    Group* pGroup = me->GetGroup();
    if (PriestIDLE_AllShadowRes)
    {
        if (!me->HasAura(PriestIDLE_AllShadowRes))
        {
            TryCastSpell(PriestIDLE_AllShadowRes, me, true);
            return true;
        }
    }
    else if (PriestIDLE_ShadowRes)
    {
        if (pGroup && !pGroup->isBGGroup() && !pGroup->isBFGroup())
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                    continue;
                if (!player->HasAura(PriestIDLE_ShadowRes) && TryCastSpell(PriestIDLE_ShadowRes, player, true) == SpellCastResult::SPELL_CAST_OK)
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
    }
    else if (PriestIDLE_SpiritRes)
    {
        if (pGroup && !pGroup->isBGGroup() && !pGroup->isBFGroup())
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                    continue;
                if (!player->HasAura(PriestIDLE_SpiritRes) && TryCastSpell(PriestIDLE_SpiritRes, player, true) == SpellCastResult::SPELL_CAST_OK)
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
    }
    else if (PriestIDLE_HardRes)
    {
        if (pGroup && !pGroup->isBGGroup() && !pGroup->isBFGroup())
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                    continue;
                if (!player->HasAura(PriestIDLE_HardRes) && TryCastSpell(PriestIDLE_HardRes, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

bool GroupPriestAI::NeedFlee()
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

void GroupPriestAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    if (PriestDebuf_Ache && !pTarget->HasAura(PriestDebuf_Ache, me->GetGUID()) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestDebuf_Plague && !pTarget->HasAura(PriestDebuf_Plague, me->GetGUID()) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

uint32 GroupPriestAI::GetReviveSpell()
{
    return PriestIDLE_Revive;
}

bool GroupPriestAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return false;
    return true;
}

bool GroupPriestAI::IsAttacker()
{
    return (m_BotTalentType == 2);
}

bool GroupPriestAI::ProcessNormalSpell()
{
    if (!me->IsMounted())
    {
        if (PriestIDLE_SoulFire && !me->HasAura(PriestIDLE_SoulFire) && TryCastSpell(PriestIDLE_SoulFire, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
        if (m_BotTalentType == 2)
        {
            if (PriestIDLE_Bloodsucker && !me->HasAura(PriestIDLE_Bloodsucker) && TryCastSpell(PriestIDLE_Bloodsucker, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
            if (PriestIDLE_ShadowStatus && !me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        CastBuffPrayer();
    }

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

void GroupPriestAI::ProcessFlee()
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
        if (PriestGuard_GuardSoul && healthPct < 8 && rangeEnemys.size() > 0 && TryCastSpell(PriestGuard_GuardSoul, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (PriestAssist_ShadowDemon && GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_ShadowDemon, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (ProcessManaRevive())
        return;
    ProcessDispel();
    ProcessCruel();
}

void GroupPriestAI::ProcessPrepareHealthSpell(Unit* pTarget)
{
    if (!pTarget || GetManaPowerPer() < 5)
        return;
    if (ProcessDispel())
        return;
    if (PriestHeal_BigHeal)
    {
        if (TryCastSpellByLifePCTInterrupt(PriestHeal_BigHeal, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (PriestHeal_FastHeal)
    {
        if (TryCastSpellByLifePCTInterrupt(PriestHeal_FastHeal, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (PriestHeal_LowHeal)
    {
        if (TryCastSpellByLifePCTInterrupt(PriestHeal_LowHeal, pTarget, 80) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (PriestHeal_ZeroHeal)
    {
        if (TryCastSpellByLifePCTInterrupt(PriestHeal_ZeroHeal, pTarget, 75) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupPriestAI::ProcessHealthSpell(Unit* pTarget)
{
    if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
    {
        me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    }
    uint32 range30Friends = SearchLifePctByFriendRange(pTarget, BOTAI_RANGESPELL_DISTANCE).size();
    if (range30Friends > 2)
    {
        if (m_BotTalentType == 1 && PriestHeal_RingHeal && TryCastSpell(PriestHeal_RingHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestAssist_AllResLife && TryCastSpell(PriestAssist_AllResLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_AOEHeal && TryCastSpell(PriestHeal_AOEHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    float selfLifePct = me->GetHealthPct();
    float healthPct = pTarget->GetHealthPct();
    if (PriestHeal_LinkHeal && me != pTarget && selfLifePct < 75 && healthPct < 75)
    {
        if (TryCastSpell(PriestHeal_LinkHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 20)
    {
        if (m_BotTalentType == 1 && PriestGuard_GuardSoul && TryCastSpell(PriestGuard_GuardSoul, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestGuard_DmgAnnul && TryCastSpell(PriestGuard_DmgAnnul, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!pTarget->HasAura(PriestFlag_NonShield) && TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_FastHeal, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_LowHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_LowHeal, pTarget, 80) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_ZeroHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_ZeroHeal, pTarget, 75) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else if (healthPct >= 20 && healthPct < 65)
    {
        if (!pTarget->HasAura(PriestFlag_NonShield) && TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_BigHeal && TryCastSpellByLifePCTInterrupt(PriestHeal_BigHeal, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_FastHeal, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_LowHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_LowHeal, pTarget, 80) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_ZeroHeal)
        {
            if (TryCastSpellByLifePCTInterrupt(PriestHeal_ZeroHeal, pTarget, 75) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else if ((healthPct >= 65 && healthPct < 85) || (pTarget->GetGUID() == m_CruxHealTarget))
    {
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!pTarget->HasAura(PriestHeal_Resume, me->GetGUID()) && TryCastSpell(PriestHeal_Resume, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal && TryCastSpellByLifePCTInterrupt(PriestHeal_FastHeal, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_AllResMana, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    ProcessDispel();
    ProcessCruel();
}

void GroupPriestAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{
    ProcessDispel();
    ProcessCruel();
}

void GroupPriestAI::ProcessRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestGuard_DefFear) && TryCastSpell(PriestGuard_DefFear, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 8 && TryCastSpell(PriestDebuf_Drown, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Ache, me->GetGUID()) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague, me->GetGUID()) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_ShadowDemon && GetManaPowerPer() < 40 && TryCastSpell(PriestAssist_ShadowDemon, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
        if (!ProcessDispel() && GetManaPowerPer() >= 90)
            ProcessNormalRangeSpell(pTarget);
        break;
    case 2:
        ProcessShadowRangeSpell(pTarget);
        break;
    }
}

void GroupPriestAI::ProcessNormalRangeSpell(Unit* pTarget)
{
    if (TryCastSpell(PriestHoly_BigFire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestHoly_Smite, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupPriestAI::ProcessShadowRangeSpell(Unit* pTarget)
{
    if (ProcessManaRevive())
        return;
    if (!me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_Silence && pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(PriestAssist_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAOE_ShadowExplode && RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 3 && TryCastSpell(PriestAOE_ShadowExplode, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    uint32 rate = urand(0, 99);
    if (rate < 30 && TryCastSpell(PriestShadow_ShadowTouch, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Lech, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupPriestAI::ProcessFullDispel()
{
    if (!m_FullDispel)
        return false;
    if (me->IsMounted())
    {
        m_FullDispel = 0;
        return false;
    }
    if (ProcessDispel())
        return true;
    if (ProcessCruel())
        return true;
    if (PriestAssist_Dispel != 0)
    {
        if (!BotUtility::SpellHasReady(me, PriestAssist_Dispel))
            return true;
    }
    if (PriestAssist_DecIllness != 0)
    {
        if (!BotUtility::SpellHasReady(me, PriestAssist_DecIllness))
            return true;
    }
    if (m_FullDispel < getMSTime())
        m_FullDispel = 0;
    return false;
}

bool GroupPriestAI::ProcessDispel()
{
    if (PriestAssist_Dispel == 0 || !BotUtility::SpellHasReady(me, PriestAssist_Dispel))
        return false;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        {
            if (TryCastSpell(PriestAssist_Dispel, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupPriestAI::ProcessCruel()
{
    if (PriestAssist_DecIllness == 0 || !BotUtility::SpellHasReady(me, PriestAssist_DecIllness))
        return false;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        if (player->HasAura(PriestAssist_DecIllness))
            continue;
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        {
            if (TryCastSpell(PriestAssist_DecIllness, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupPriestAI::ProcessManaRevive()
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

void GroupPriestAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 600) + power);
}
