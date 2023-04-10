#include "BotDuelClassAI.h"

void DuelPriestAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelPriestAI::ResetBotAI()
{
    UpdateTalentType();
    BotDuelAI::ResetBotAI();
    InitializeSpells(me);
}

uint32 DuelPriestAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool DuelPriestAI::HaveManaStore()
{
    return GetManaPowerPer() >= 5;
}

void DuelPriestAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 400) + power);
}

bool DuelPriestAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    if (m_NeedFlee.TargetHasFleeAura(pTarget))
    {
        return true;
    }
    if (!IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

bool DuelPriestAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return false;
    return true;
}

bool DuelPriestAI::IsAttacker()
{
    return (m_BotTalentType == 2);
}

void DuelPriestAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    else
        return;

    if (!me->HasAura(PriestIDLE_SoulFire) && TryCastSpell(PriestIDLE_SoulFire, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    float healthPct = me->GetHealthPct();
    if (me->GetDistance(pTarget->GetPosition()) < 8 && TryCastSpell(PriestGuard_AOEFear, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 80)
    {
        if (!me->HasAura(PriestGuard_DefShield) && !me->HasAura(PriestFlag_NonShield))
        {
            if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
                me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            if (TryCastSpell(PriestGuard_DefShield, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!me->HasAura(PriestHeal_Resume))
        {
            if (PriestIDLE_ShadowStatus && me->HasAura(PriestIDLE_ShadowStatus))
                me->RemoveOwnedAura(PriestIDLE_ShadowStatus, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
            if (TryCastSpell(PriestHeal_Resume, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }

    if (!pTarget->HasAura(PriestDebuf_Ache) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0)
    {
        if (healthPct < 30 && TryCastSpell(PriestGuard_DmgAnnul, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (m_BotTalentType == 1)
    {
        if (PriestHeal_RingHeal)
        {
            if (TryCastSpell(PriestHeal_RingHeal, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (healthPct < 60 && TryCastSpell(PriestGuard_SelfHealth, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 8 && TryCastSpell(PriestGuard_GuardSoul, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (PriestAssist_ShadowDemon && GetManaPowerPer() < 20 && TryCastSpell(PriestAssist_ShadowDemon, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    ProcessDispel();
}

void DuelPriestAI::ProcessHealthSpell(Unit* pTarget)
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
    if (m_BotTalentType == 1 && PriestHeal_RingHeal && TryCastSpell(PriestHeal_RingHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
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
        if (PriestHeal_FastHeal && TryCastSpell(PriestHeal_FastHeal, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
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
    }
    else if (healthPct >= 65 && healthPct < 90)
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

void DuelPriestAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{
}

void DuelPriestAI::ProcessRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestGuard_DefFear) && TryCastSpell(PriestGuard_DefFear, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 8 && TryCastSpell(PriestDebuf_Drown, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Ache) && TryCastSpell(PriestDebuf_Ache, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(PriestDebuf_Plague) && TryCastSpell(PriestDebuf_Plague, pTarget) == SpellCastResult::SPELL_CAST_OK)
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

void DuelPriestAI::ProcessNormalRangeSpell(Unit* pTarget)
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

void DuelPriestAI::ProcessShadowRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(PriestIDLE_ShadowStatus) && TryCastSpell(PriestIDLE_ShadowStatus, me, true) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PriestAssist_Silence && pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(PriestAssist_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    uint32 rate = urand(0, 99);
    if (rate < 30 && TryCastSpell(PriestShadow_ShadowTouch, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Knocking, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(PriestShadow_Lech, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool DuelPriestAI::ProcessManaBurn()
{
    if (!PriestPrecept_ManaBurn)
        return false;
    if (GetManaPowerPer() < 25)
        return false;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    if (!TargetCanManaBurn(pTarget->ToPlayer()))
        return false;
    if (TargetIsHealth(pTarget->ToPlayer()))
    {
        if (TryCastSpell(PriestPrecept_ManaBurn, pTarget) == SpellCastResult::SPELL_CAST_OK)
        {
            return true;
        }
    }
    return false;
}

bool DuelPriestAI::ProcessDispel()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SNARE))
        if (TryCastSpell(PriestAssist_Dispel, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    return false;
}
