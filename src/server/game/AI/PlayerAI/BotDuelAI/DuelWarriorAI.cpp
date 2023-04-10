
#include "BotDuelClassAI.h"

uint32 DuelWarriorAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

void DuelWarriorAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
    uint32 power = me->GetPower(Powers::POWER_RAGE);
    me->SetPower(Powers::POWER_RAGE, (max / 35) + power);
}

void DuelWarriorAI::ClearMechanicAura()
{
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN) || HasAuraMechanic(me, Mechanics::MECHANIC_FEAR);
    if (stun && TryCastSpell(WarriorCommon_ClearCtrl, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (root && TryCastSpell(WarriorRage_ReIntercept, me) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool DuelWarriorAI::NeedWaitSpecialSpell(uint32 diff)
{
    m_ChargeWaitTick -= diff;
    if (m_ChargeWaitTick < 0)
        m_ChargeWaitTick = 0;
    if (BotDuelAI::NeedWaitSpecialSpell(diff))
        return true;

    if (m_ChargeWaitTick > 0)
        return true;
    return false;
}

void DuelWarriorAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();
}

void DuelWarriorAI::ResetBotAI()
{
    BotDuelAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
    if (WarriorWeapon_SwordStorm == 0 && m_BotTalentType == 0 && me->getLevel() == 80)
    {
        me->LearnSpell(46924, false);
        WarriorWeapon_SwordStorm = BotUtility::FindMaxRankSpellByExist(me, 46924);
    }
}

void DuelWarriorAI::ProcessMeleeSpell(Unit* pTarget)
{
    UpdateWarriorPose();
    //uint32 triggerRate = urand(0, 99);
    uint32 ragePer = GetRagePowerPer();
    if (ragePer < 8 && TryCastSpell(WarriorCommon_AddPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 75 && !me->HasAura(WarriorCommon_PowerAtt))
        TryCastSpell(WarriorCommon_PowerAtt, pTarget);
    if (ProcessSurviveSpell())
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessWeaponMeleeSpell(pTarget);
        break;
    case 1:
        ProcessRageMeleeSpell(pTarget);
        break;
    case 2:
        ProcessDefanceMeleeSpell(pTarget);
        break;
    }
}

void DuelWarriorAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->GetDistance(pTarget) > 9)
    {
        if (m_BotTalentType == 2)
        {
            if (BotUtility::SpellHasReady(me, WarriorWeapon_Charge) && TryCastSpell(WarriorWeapon_Charge, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept) && TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
        }
        else if (m_BotTalentType == 0)
        {
            if (BotUtility::SpellHasReady(me, WarriorWeapon_Charge))
            {
                if (!me->HasAura(WarriorWeapon_Status))
                    me->CastSpell(me, WarriorWeapon_Status, true);
                if (TryCastSpell(WarriorWeapon_Charge, pTarget) == SpellCastResult::SPELL_CAST_OK)
                {
                    OnCastCharge(pTarget);
                    return;
                }
            }
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept))
            {
                if (!me->HasAura(WarriorRage_Status))
                    me->CastSpell(me, WarriorRage_Status, true);
                if (TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
                {
                    OnCastCharge(pTarget);
                    return;
                }
            }
        }
        else
        {
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept) && TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
        }
    }
    UpdateWarriorPose();
    if (IsInvincible(pTarget) && TryCastSpell(WarriorWeapon_HighThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (IsNotMovement() && TryCastSpell(WarriorCommon_PowerThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && WarriorIDLE_AOEAddLife && !me->HasAura(WarriorIDLE_AOEAddLife) && TryCastSpell(WarriorIDLE_AOEAddLife, me))
        return;
    if (m_BotTalentType != 2 && WarriorIDLE_AOEAddPower && !me->HasAura(WarriorIDLE_AOEAddPower) && TryCastSpell(WarriorIDLE_AOEAddPower, me))
        return;
    if (ProcessSurviveSpell())
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessWeaponRangeSpell(pTarget);
        break;
    case 1:
        ProcessRageRangeSpell(pTarget);
        break;
    case 2:
        ProcessDefanceRangeSpell(pTarget);
        break;
    }
}

void DuelWarriorAI::ProcessFlee()
{
    //Unit* pTarget = me->GetSelectedUnit();
    FleeMovement();
    ProcessSurviveSpell();
}

void DuelWarriorAI::UpdateWarriorPose()
{
    if (!me->IsInCombat())
    {
        if (!me->HasAura(WarriorWeapon_Status))
            me->CastSpell(me, WarriorWeapon_Status, true);
    }
    else
    {
        switch (m_BotTalentType)
        {
        case 0:
            if (!me->HasAura(WarriorWeapon_Status))
                me->CastSpell(me, WarriorWeapon_Status, true);
            break;
        case 1:
            if (!me->HasAura(WarriorRage_Status))
                me->CastSpell(me, WarriorRage_Status, true);
            break;
        case 2:
            if (!me->HasAura(WarriorDefance_Status))
                me->CastSpell(me, WarriorDefance_Status, true);
            break;
        }
    }
}

void DuelWarriorAI::ProcessWeaponMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    if (TryCastSpell(WarriorWeaponRage_WinAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TargetIsMelee(pTarget->ToPlayer()) && TryCastSpell(WarriorWeapon_Backstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeapon_DeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeapon_Suppress, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeaponRage_FullKill, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorWeapon_SwordStorm && me->getLevel() == 80)
    {
        if (TryCastSpell(WarriorWeapon_SwordStorm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 30 && !pTarget->HasAura(WarriorWeaponDefance_AOEAtt) && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelWarriorAI::ProcessWeaponRangeSpell(Unit* /*pTarget*/)
{
}

void DuelWarriorAI::ProcessRageMeleeSpell(Unit* pTarget)
{
    //uint32 ragePer = GetRagePowerPer();
    if (TryCastSpell(WarriorWeaponRage_WinAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(WarriorRage_HeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorRage_Bloodthirsty, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeaponRage_FullKill, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorRage_Harsh) && TryCastSpell(WarriorRage_Harsh, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorRage_Needdead, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorRage_Whirlwind, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorRage_Impertinency, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelWarriorAI::ProcessRageRangeSpell(Unit* /*pTarget*/)
{
}

void DuelWarriorAI::ProcessDefanceMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    float healthPct = me->GetHealthPct();
    if (healthPct <= 10.0f && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING))
    {
        if (TryCastSpell(WarriorWeaponDefance_ShieldHit, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(WarriorWeaponDefance_SpellReflect, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TargetIsMelee(pTarget->ToPlayer()) && !pTarget->HasAura(WarriorDefance_Disarm) && TryCastSpell(WarriorDefance_Disarm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorDefance_ShieldAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorDefance_Fuchou, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorDefance_ShieldBlock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) && TryCastSpell(WarriorDefance_AOEConk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) && TryCastSpell(WarriorDefance_Conk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct <= 15 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 30 && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 40 && TryCastSpell(WarriorDefance_HPojia, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelWarriorAI::ProcessDefanceRangeSpell(Unit* /*pTarget*/)
{
}

bool DuelWarriorAI::ProcessSurviveSpell()
{
    if (m_BotTalentType == 2)
    {
        float healthPct = me->GetHealthPct();
        if (healthPct < 19)
        {
            if (!me->HasAura(WarriorDefance_Status))
                me->CastSpell(me, WarriorDefance_Status, true);
            if (TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

void DuelWarriorAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    //me->AttackStop();
    //m_ChargeWaitTick = 2000;
    me->StopMoving();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
    //me->GetMotionMaster()->MoveCharge(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPEED_CHARGE);
}
