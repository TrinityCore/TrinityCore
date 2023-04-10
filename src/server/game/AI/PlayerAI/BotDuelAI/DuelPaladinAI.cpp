
#include "BotDuelClassAI.h"

void DuelPaladinAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelPaladinAI::ResetBotAI()
{
    UpdateTalentType();
    BotDuelAI::ResetBotAI();
    InitializeSpells(me);
}

uint32 DuelPaladinAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void DuelPaladinAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool DuelPaladinAI::ProcessAura()
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
    return false;
}

void DuelPaladinAI::ProcessFlee()
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
    if (ProcessTryFullHealth())
        return;
    if (ProcessFreeAura())
        return;
    Unit* player = me->GetSelectedPlayer();
    if (player)
    {
        if (!HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_StunMace, player) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_Confession, player) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() < 40)
    {
        if (m_BotTalentType == 0 && PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

bool DuelPaladinAI::ProcessControl(Unit* pTarget)
{
    if (PaladinAssist_StunMace && !TargetIsCtrl(pTarget))
    {
        //if (!BotUtility::ControllSpellDiminishing || TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_STUN))
        //{
        //	if (TryCastSpell(PaladinAssist_StunMace, pTarget) == SpellCastResult::SPELL_CAST_OK)
        //		return true;
        //}
    }
    return false;
}

bool DuelPaladinAI::ProcessFreeAura()
{
    if (!PaladinGuard_FreeAura)
        return false;
    if (TargetNeedFree(me) && TryCastSpell(PaladinGuard_FreeAura, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

bool DuelPaladinAI::ProcessTryFullHealth()
{
    if (!PaladinHeal_FullHoly)
        return false;
    if (me->GetHealthPct() > 8)
        return false;
    if (IsInvincible(me))
        return false;
    if (TryCastSpell(PaladinHeal_FullHoly, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

void DuelPaladinAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me != pTarget)
        return;
    if (ProcessAura())
        return;
    if (me->GetDistance(pTarget) > 30)
        return;
    if (ProcessStamp())
        return;
    if (ProcessTryFullHealth())
        return;
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

void DuelPaladinAI::ProcessMeleeSpell(Unit* pTarget)
{
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

    if (TargetNeedInvincible(me))
    {
        if (TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (PaladinGuard_UnShield && !IsInvincible(me) && !me->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessTryFullHealth())
        return;
    float meLife = me->GetHealthPct();
    if (PaladinAssist_UpPower && meLife > 80 && TryCastSpell(PaladinAssist_UpPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 20)
    {
        if (TryCastSpell(PaladinMelee_KillMace, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
}

void DuelPaladinAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (ProcessAura())
        return;
    if (ProcessTryFullHealth())
        return;
    if (ProcessControl(pTarget))
        return;
    if (ProcessFreeAura())
        return;
    if (ProcessStamp())
        return;
    if (me->GetHealthPct() < 50)
        ProcessHealthSpell(me);
}

bool DuelPaladinAI::ProcessStamp()
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

bool DuelPaladinAI::ProcessDispel()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FREEZE) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
    {
        if (TryCastSpell(PaladinAssist_Dispel, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelPaladinAI::TargetNeedInvincible(Unit* player)
{
    if (player->GetHealthPct() < 15 && player->IsInCombat() && !IsInvincible(player) && !player->HasAura(PaladinFlag_Discipline))
    {
        return true;
    }
    return false;
}

bool DuelPaladinAI::TargetNeedFree(Unit* player)
{
    if (IsInvincible(player))
        return false;
    if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_DAZE))
        return true;
    return false;
}

bool DuelPaladinAI::IsHealerBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool DuelPaladinAI::IsAttacker()
{
    return (m_BotTalentType != 0);
}

bool DuelPaladinAI::TargetIsCtrl(Unit* pTarget)
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
