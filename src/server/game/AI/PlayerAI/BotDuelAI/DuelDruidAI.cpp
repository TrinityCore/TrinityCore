
#include "BotDuelClassAI.h"
#include "Group.h"

void DuelDruidAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelDruidAI::EachTick()
{
    BotDuelAI::EachTick();
    if (me->HasAura(DruidStatus_Cat))
        UpEnergy();
    else if (me->HasAura(DruidStatus_Bear))
        UpPower();
    else
        UpMana();
}

void DuelDruidAI::ResetBotAI()
{
    UpdateTalentType();
    BotDuelAI::ResetBotAI();
    InitializeSpells(me);
    SwitchStatus(0);
}

uint32 DuelDruidAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

uint32 DuelDruidAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

uint32 DuelDruidAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

bool DuelDruidAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (m_NeedFlee.TargetHasFleeAura(pTarget))
        return true;
    if (m_BotTalentType == 1)
        return false;
    if (!pTarget)
        return false;
    if (!IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void DuelDruidAI::ProcessFlee()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    FleeMovement();

    if (DruidGuard_Harden && me->GetHealthPct() < 60 && TryCastSpell(DruidGuard_Harden, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(DruidGuard_AutoTwine, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && DruidGuard_TreeMan && TryCastSpell(DruidGuard_TreeMan, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(DruidStatus_Travel))
    {
        if (HasAuraMechanic(me, Mechanics::MECHANIC_SNARE) || HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
        {
            SwitchStatus(0);
        }
    }
    else
    {
        Unit* pTarget = me->GetSelectedUnit();
        float healthPct = me->GetHealthPct();
        bool hasRelife = me->HasAura(DruidHeal_Relife);
        bool hasBurst = me->HasAura(DruidHeal_LifeBurst);
        bool hasMF = (pTarget && pTarget->HasAura(DruidCast_Moonfire)) ? true : false;
        bool hasIns = (pTarget && m_BotTalentType == 0 && pTarget->HasAura(DruidCast_Insect)) ? true : false;
        if (pTarget && (!hasRelife || !hasBurst || !hasMF || (m_BotTalentType == 0 && !hasIns)))
            SwitchStatus(0);
        //else if (me->GetMap()->IsOutdoors(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
        //{
        //    SwitchStatus(DruidStatus_Travel);
        //    return;
        //}
        if (healthPct < 80 && !hasRelife && TryCastSpell(DruidHeal_Relife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 80 && !hasBurst && TryCastSpell(DruidHeal_LifeBurst, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (pTarget && !hasMF && TryCastSpell(DruidCast_Moonfire, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (pTarget && m_BotTalentType == 0 && !hasIns && TryCastSpell(DruidCast_Insect, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool DuelDruidAI::ProcessSneak()
{
    if (m_BotTalentType != 1)
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;

    Unit* pUnit = me->GetSelectedUnit();
    if (pUnit && pUnit->IsAlive() && pUnit->ToPlayer() && pUnit->ToPlayer()->GetTeamId() != me->GetTeamId())
    {
        if (!me->IsInCombat() && DruidStatus_Cat && DruidGuard_Sneak && !me->HasAura(DruidGuard_Sneak))
        {
            if (!me->HasAura(DruidStatus_Cat))
            {
                SwitchStatus(DruidStatus_Cat);
            }
            if (TryCastSpell(DruidGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastSneak();
                return false;
            }
        }
        if (me->HasAura(DruidStatus_Cat) && !me->HasAura(DruidGuard_Sneak))
        {
            if (TryCastSpell(DruidCat_FastMove, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
            if (TryCastSpell(DruidCat_Charge, pUnit) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pUnit);
                return false;
            }
        }
    }
    else
    {
        if (me->HasAura(DruidGuard_Sneak))
        {
            me->RemoveOwnedAura(DruidGuard_Sneak, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
    return false;
}

void DuelDruidAI::ProcessHealthSpell(Unit* pTarget)
{
    if (pTarget != me)
        return;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (me->GetDistance(pTarget) > 30)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;

    if (m_BotTalentType == 2 && DruidStatus_Tree && me->IsInCombat())
    {
        if (!me->HasAura(DruidStatus_Tree))
            SwitchStatus(DruidStatus_Tree);
    }
    else
        SwitchStatus(0);
    if (ProcessActive())
        return;
    if (m_BotTalentType == 2 && DruidHeal_AOEFerity && TryCastSpell(DruidHeal_AOEFerity, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    float healthPct = pTarget->GetHealthPct();
    bool hasRelife = pTarget->HasAura(DruidHeal_Relife);
    bool hasBurst = pTarget->HasAura(DruidHeal_LifeBurst);
    bool hasCoale = pTarget->HasAura(DruidHeal_Coalescence);
    if (healthPct < 30)
    {
        if (DruidHeal_MomentHeal && me->HasAura(DruidHeal_MomentHeal) && TryCastSpell(DruidHeal_Touch, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (DruidHeal_MomentHeal && TryCastSpell(DruidHeal_MomentHeal, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 40 && m_BotTalentType == 2 && DruidHeal_MergerLife && (hasRelife || hasCoale))
    {
        if (TryCastSpell(DruidHeal_MergerLife, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!hasRelife && TryCastSpell(DruidHeal_Relife, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 75 && !hasBurst && TryCastSpell(DruidHeal_LifeBurst, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 75 && !hasCoale)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Coalescence, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 75 && DruidHeal_Nourishing && (hasRelife || hasCoale))
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Nourishing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 60)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Touch, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void DuelDruidAI::ProcessMeleeSpell(Unit* pTarget)
{
    ProcessSneak();
    if (me->HasAura(DruidStatus_Bear))
        ProcessBearCombat(pTarget);
    else if (me->HasAura(DruidStatus_Cat))
        ProcessCatCombat(pTarget);
    else if (CanMeleeHealthMe())
        ProcessHealthSpell(me);
    else if (m_BotTalentType == 1)
    {
        if (me->GetHealthPct() < 40)
        {
            SwitchStatus(DruidStatus_Bear);
            return;
        }
        else
        {
            SwitchStatus(DruidStatus_Cat);
            return;
        }
    }
    else
    {
        if (TargetHasMechanic(pTarget))
            return;
        if (TargetIsMelee(pTarget->ToPlayer()))
        {
            if (!BotUtility::ControllSpellDiminishing /*|| TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_ROOT)*/)
            {
                if (TryCastSpell(DruidGuard_Twine, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
}

void DuelDruidAI::ProcessBearCombat(Unit* pTarget)
{
    if (CanMeleeHealthMe())
    {
        me->RemoveOwnedAura(DruidStatus_Bear, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        return;
    }
    uint32 rage = GetRagePowerPer();
    if (me->GetHealthPct() < 40)
    {
        if (rage > 40 && TryCastSpell(DruidBear_PowerLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (DruidGuard_Harden && TryCastSpell(DruidGuard_Harden, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() > 65)
    {
        SwitchStatus(DruidStatus_Cat);
        return;
    }
    if (!pTarget->HasAuraState(AURA_STATE_FAERIE_FIRE) && TryCastSpell(DruidAssist_BeastSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (rage < 10 && TryCastSpell(DruidBear_AddPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (rage > 65 && !pTarget->HasAura(DruidBear_DecAtt) && TryCastSpell(DruidBear_DecAtt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(DruidBear_Sweep) && TryCastSpell(DruidBear_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DruidBear_Laceration && TryCastSpell(DruidBear_Laceration, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!TargetHasMechanic(pTarget))
    {
        if (TryCastSpell(DruidBear_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (rage > 60)
        TryCastSpell(DruidBear_NextAtt, pTarget);
    if (rage > 40 && TryCastSpell(DruidBear_Attack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelDruidAI::ProcessCatCombat(Unit* pTarget)
{
    if (CanMeleeHealthMe())
    {
        me->RemoveOwnedAura(DruidStatus_Cat, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        return;
    }
    if (me->HasAura(DruidGuard_Sneak))
    {
        if (HasAuraMechanic(pTarget, MECHANIC_STUN))
        {
            if (TryCastSpell(DruidCat_Sack, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (TryCastSpell(DruidCat_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else
    {
        if (!pTarget->HasAuraState(AURA_STATE_FAERIE_FIRE) && TryCastSpell(DruidAssist_BeastSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (me->GetHealthPct() < 40)
        {
            SwitchStatus(DruidStatus_Bear);
            return;
        }
        if (CanConsumeCombo(pTarget))
        {
            if (DruidCat_Roar && !HasAuraMechanic(me, Mechanics::MECHANIC_ENRAGED))
            {
                if (TryCastSpell(DruidCat_Roar, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (!TargetHasMechanic(pTarget))
            {
                if (TryCastSpell(DruidCat_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (DruidCat_Separate && !pTarget->HasAura(DruidCat_Separate))
            {
                if (TryCastSpell(DruidCat_Separate, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (DruidCat_Bite && TryCastSpell(DruidCat_Bite, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (HasEnergyStore())
        {
            if (TryCastSpell(DruidCat_Tiger, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (!pTarget->HasAura(DruidCat_Sweep) && TryCastSpell(DruidCat_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (DruidCat_Laceration && TryCastSpell(DruidCat_Laceration, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            uint32 rate = urand(0, 99);
            if (rate < 10)
            {
                if (TryCastSpell(DruidCat_Claw, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            else if (rate >= 10 && rate < 55)
            {
                if (TryCastSpell(DruidCat_BackStab, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            else
            {
                if (DruidCat_Attack && TryCastSpell(DruidCat_Attack, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
                if (TryCastSpell(DruidCat_BackStab, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
}

void DuelDruidAI::ProcessRangeSpell(Unit* pTarget)
{
    if (m_BotTalentType == 0 || m_BotTalentType == 2)
        ProcessBalanceCombat(pTarget);
    else if (m_BotTalentType == 1)
        ProcessSneak();
}

void DuelDruidAI::ProcessBalanceCombat(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (m_BotTalentType == 0 && DruidStatus_Bird && me->IsInCombat() && !me->HasAura(DruidStatus_Bird))
    {
        SwitchStatus(DruidStatus_Bird);
        return;
    }
    else if (me->HasAura(DruidStatus_Travel))
        SwitchStatus(0);
    if (ProcessActive())
        return;
    if (!pTarget->HasAura(DruidAssist_PersonSpirit) && TryCastSpell(DruidAssist_PersonSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (m_BotTalentType == 0 && DruidAOE_FallStar && TryCastSpell(DruidAOE_FallStar, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && DruidGuard_TreeMan && TryCastSpell(DruidGuard_TreeMan, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessControl(pTarget))
        return;
    if (!pTarget->HasAura(DruidCast_Moonfire) && TryCastSpell(DruidCast_Moonfire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && !pTarget->HasAura(DruidCast_Insect) && TryCastSpell(DruidCast_Insect, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() > 65)
    {
        if (TryCastSpell(DruidCast_Spark, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(DruidCast_Anger, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool DuelDruidAI::ProcessActive()
{
    if (!DruidAssist_Active)
        return false;
    if (GetManaPowerPer() < 10)
    {
        if (TryCastSpell(DruidAssist_Active, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelDruidAI::CanMeleeHealthMe()
{
    if (GetManaPowerPer() > 15 && me->GetHealthPct() < 60 &&
        !HasAuraMechanic(me, Mechanics::MECHANIC_SILENCE))
    {
        Unit* target = GetDuelEnemy();
        if (!target || me->GetDistance(target->GetPosition()) > NEEDFLEE_CHECKRANGE)
            return true;
    }
    return false;
}

bool DuelDruidAI::CanConsumeCombo(Unit* pTarget)
{
    uint8 combo = me->GetComboPoints();
    if (combo == 0)
        return false;
    float targetLife = pTarget->GetHealthPct();
    if (targetLife < 10)
        return true;
    else if (targetLife < 60 && combo > 2)
        return true;
    else if (combo >= 4)
        return true;
    return false;
}

bool DuelDruidAI::TargetHasMechanic(Unit* pTarget)
{
    if (/*HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT) ||*/
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}

bool DuelDruidAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool DuelDruidAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool DuelDruidAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool DuelDruidAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool DuelDruidAI::HasEnergyStore()
{
    return GetEnergyPowerPer() >= 60;
}

void DuelDruidAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 20) + power);
}

void DuelDruidAI::UpPower()
{
    uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
    uint32 power = me->GetPower(Powers::POWER_RAGE);
    me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
}

void DuelDruidAI::UpMana()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 550) + power);
}

void DuelDruidAI::SwitchStatus(uint32 status)
{
    if (status != DruidStatus_Travel && me->HasAura(DruidStatus_Travel))
        me->RemoveOwnedAura(DruidStatus_Travel, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Bear && me->HasAura(DruidStatus_Bear))
        me->RemoveOwnedAura(DruidStatus_Bear, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Cat && me->HasAura(DruidStatus_Cat))
        me->RemoveOwnedAura(DruidStatus_Cat, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Bird && me->HasAura(DruidStatus_Bird))
        me->RemoveOwnedAura(DruidStatus_Bird, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Tree && me->HasAura(DruidStatus_Tree))
        me->RemoveOwnedAura(DruidStatus_Tree, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);

    if (status == DruidStatus_Travel)
        TryCastSpell(DruidStatus_Travel, me, true);
    else if (status == DruidStatus_Bear)
        TryCastSpell(DruidStatus_Bear, me, true);
    else if (status == DruidStatus_Cat)
        TryCastSpell(DruidStatus_Cat, me, true);
    else if (status == DruidStatus_Bird)
        TryCastSpell(DruidStatus_Bird, me, true);
    else if (status == DruidStatus_Tree)
        TryCastSpell(DruidStatus_Tree, me, true);
}

bool DuelDruidAI::CanAttackSpell()
{
    if (me->HasAura(DruidStatus_Travel))
        return false;
    if (me->HasAura(DruidStatus_Bear))
        return false;
    if (me->HasAura(DruidStatus_Cat))
        return false;
    if (me->HasAura(DruidStatus_Tree))
        return false;
    return true;
}

bool DuelDruidAI::ProcessControl(Unit* /*pTarget*/)
{
    if (!CanAttackSpell())
        return false;
    if (Unit* player = GetDuelEnemy())
    {
        if (TargetIsMelee(player->ToPlayer()))
        {
            if (BotUtility::ControllSpellDiminishing /*&& !TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_ROOT)*/)
                return false;
            if (TryCastSpell(DruidGuard_Twine, player) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
    }
    return false;
}

void DuelDruidAI::OnCastSneak()
{
    Unit* target = GetDuelEnemy();
    if (target)
        target->SetTarget(ObjectGuid::Empty);
}

void DuelDruidAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    me->StopMoving();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
}
