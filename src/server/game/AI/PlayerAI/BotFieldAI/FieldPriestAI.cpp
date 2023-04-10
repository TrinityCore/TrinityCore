
#include "BotFieldClassAI.h"

void FieldPriestAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldPriestAI::ResetBotAI()
{
    UpdateTalentType();
    BotFieldAI::ResetBotAI();
    m_ReadyCurrentPrayer = 0;
    InitializeSpells(me);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(PriestIDLE_AllShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_AllSpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_AllHardRes);
    m_WishStore.RegisterWish(PriestIDLE_ShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_SpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_HardRes);
}

void FieldPriestAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(PriestIDLE_AllShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_AllSpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_AllHardRes);
    m_WishStore.RegisterWish(PriestIDLE_ShadowRes);
    m_WishStore.RegisterWish(PriestIDLE_SpiritRes);
    m_WishStore.RegisterWish(PriestIDLE_HardRes);
}

uint32 FieldPriestAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool FieldPriestAI::CastBuffPrayer()
{
    //Group* pGroup = me->GetGroup();
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
        if (!me->HasAura(PriestIDLE_ShadowRes))
        {
            TryCastSpell(PriestIDLE_ShadowRes, me, true);
            return true;
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
        if (!me->HasAura(PriestIDLE_SpiritRes))
        {
            TryCastSpell(PriestIDLE_SpiritRes, me, true);
            return true;
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
        if (!me->HasAura(PriestIDLE_HardRes))
        {
            TryCastSpell(PriestIDLE_HardRes, me, true);
            return true;
        }
    }
    return false;
}

bool FieldPriestAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget || pTarget->ToCreature())
        return false;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

uint32 FieldPriestAI::GetReviveSpell()
{
    return PriestIDLE_Revive;
}

bool FieldPriestAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return false;
    return true;
}

bool FieldPriestAI::IsAttacker()
{
    return (m_BotTalentType == 2);
}

bool FieldPriestAI::ProcessNormalSpell()
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

void FieldPriestAI::ProcessFlee()
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
    if (rangeEnemys.size() > 0 && healthPct < 80 && !me->HasAura(PriestIDLE_ShadowStatus))
    {
        if (!me->HasAura(PriestGuard_DefShield) && TryCastSpell(PriestGuard_DefShield, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!me->HasAura(PriestHeal_Resume) && TryCastSpell(PriestHeal_Resume, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    Unit* pTarget = me->GetSelectedUnit();
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
                if (!rndNeedHealPlayer->HasAura(PriestHeal_Resume) && TryCastSpell(PriestHeal_Resume, rndNeedHealPlayer) == SpellCastResult::SPELL_CAST_OK)
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

    ProcessDispel();
}

void FieldPriestAI::ProcessHealthSpell(Unit* pTarget)
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
        if (TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal)
        {
            if (TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_LowHeal)
        {
            if (TryCastSpell(PriestHeal_LowHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_ZeroHeal)
        {
            if (TryCastSpell(PriestHeal_ZeroHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else if (healthPct >= 20 && healthPct < 65)
    {
        if (TryCastSpell(PriestGuard_DefShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_BigHeal && TryCastSpell(PriestHeal_BigHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal)
        {
            if (TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_LowHeal)
        {
            if (TryCastSpell(PriestHeal_LowHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (PriestHeal_ZeroHeal)
        {
            if (TryCastSpell(PriestHeal_ZeroHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else if (healthPct >= 65 && healthPct < 85)
    {
        if (PriestHeal_UnionHeal && TryCastSpell(PriestHeal_UnionHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 0 && PriestHeal_Awareness && TryCastSpell(PriestHeal_Awareness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!pTarget->HasAura(PriestHeal_Resume) && TryCastSpell(PriestHeal_Resume, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PriestHeal_FastHeal && TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_AllResMana, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    ProcessDispel();
}

void FieldPriestAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{
    ProcessDispel();
}

void FieldPriestAI::ProcessRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestGuard_DefFear) && TryCastSpell(PriestGuard_DefFear, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 8 && TryCastSpell(PriestDebuf_Drown, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Ache) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
        if (!ProcessDispel())// && GetManaPowerPer() >= 90)
            ProcessNormalRangeSpell(pTarget);
        break;
    case 2:
        ProcessShadowRangeSpell(pTarget);
        break;
    }
}

void FieldPriestAI::ProcessNormalRangeSpell(Unit* pTarget)
{
    if (TryCastSpell(PriestHoly_BigFire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestHoly_Smite, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void FieldPriestAI::ProcessShadowRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_Silence && pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(PriestAssist_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAOE_ShadowExplode && RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 4 && TryCastSpell(PriestAOE_ShadowExplode, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    uint32 rate = urand(0, 99);
    if (rate < 30 && TryCastSpell(PriestShadow_ShadowTouch, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Lech, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool FieldPriestAI::ProcessDispel()
{
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

void FieldPriestAI::UpEnergy()
{
}
