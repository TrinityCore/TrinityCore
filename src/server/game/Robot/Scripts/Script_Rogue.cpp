#include "Script_Rogue.h"

Script_Rogue::Script_Rogue(Player* pmMe) :Script_Base(pmMe)
{

}

bool Script_Rogue::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Rogue::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Rogue::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting)
{
    if (!me)
    {
        return false;
    }
    if (me->GetHealthPct() < 20.0f)
    {
        UseHealingPotion();
    }
    uint32 characterTalentTab = me->GetMaxTalentCountTab();
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank, pmInterruptTargetCasting);
    }
    case 1:
    {
        return DPS_Combat(pmTarget, pmChase, pmAOE, pmTank, pmInterruptTargetCasting);
    }
    case 2:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank, pmInterruptTargetCasting);
    }
    default:
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank, pmInterruptTargetCasting);
    }
}

bool Script_Rogue::DPS_Combat(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (pmChase)
    {
        if (targetDistance > ATTACK_RANGE_LIMIT)
        {
            return false;
        }
        if (!Chase(pmTarget))
        {
            return false;
        }
    }
    else
    {
        if (targetDistance > RANGED_MAX_DISTANCE)
        {
            return false;
        }
        if (!me->isInFront(pmTarget, M_PI / 16))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    uint32 energy = me->GetPower(Powers::POWER_ENERGY);
    if (pmInterruptTargetCasting)
    {
        if (energy > 25)
        {
            if (pmTarget->IsNonMeleeSpellCast(false))
            {
                if (CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
                {
                    return true;
                }
            }
        }
    }
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 10.0f)
    {
        if (CastSpell(pmTarget, "Adrenaline Rush", MELEE_MAX_DISTANCE))
        {
            me->Yell("ADRENALINE RUSH !", Language::LANG_UNIVERSAL);
            return true;
        }
        if (energy > 25)
        {
            if (CastSpell(pmTarget, "Blade Flurry", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }

    if (energy > 10)
    {
        if (CastSpell(pmTarget, "Riposte", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (energy > 50)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting)
{
    return DPS_Combat(pmTarget, pmChase, pmAOE, pmTank, pmInterruptTargetCasting);
}

bool Script_Rogue::Attack(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (me->GetHealthPct() < 20.0f)
    {
        UseHealingPotion();
    }
    uint32 characterTalentTab = me->GetMaxTalentCountTab();
    switch (characterTalentTab)
    {
    case 0:
    {
        return Attack_Common(pmTarget);
    }
    case 1:
    {
        return Attack_Combat(pmTarget);
    }
    case 2:
    {
        return Attack_Common(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Rogue::Attack_Combat(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }


    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (!Chase(pmTarget))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    uint32 energy = me->GetPower(Powers::POWER_ENERGY);
    if (energy > 25)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 10.0f)
    {
        if (CastSpell(pmTarget, "Adrenaline Rush", MELEE_MAX_DISTANCE))
        {
            me->Yell("ADRENALINE RUSH !", Language::LANG_UNIVERSAL);
            return true;
        }
        if (energy > 25)
        {
            if (CastSpell(pmTarget, "Blade Flurry", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }

    if (energy > 10)
    {
        if (CastSpell(pmTarget, "Riposte", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (energy > 50)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::Attack_Common(Unit* pmTarget)
{
    return Attack_Combat(pmTarget);
}

bool Script_Rogue::Buff(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Rogue::InterruptCasting(Unit* pmTarget)
{
    if (me)
    {
        uint32 energy = me->GetPower(Powers::POWER_ENERGY);
        if (energy > 25)
        {
            if (pmTarget->IsNonMeleeSpellCast(false))
            {
                if (CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
