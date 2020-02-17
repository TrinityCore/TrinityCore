#include "Script_Rogue.h"

#ifndef ROGUE_PREPARE_DISTANCE
# define ROGUE_PREPARE_DISTANCE 10
#endif

#ifndef ROGUE_RANGE_DISTANCE
# define ROGUE_RANGE_DISTANCE 25
#endif

Script_Rogue::Script_Rogue(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Rogue::HealMe()
{
    return false;
}

bool Script_Rogue::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Rogue::Healer()
{
    return false;
}

bool Script_Rogue::DPS(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget);
    }
    case 1:
    {
        return DPS_Combat(pmTarget);
    }
    case 2:
    {
        return DPS_Common(pmTarget);
    }
    default:
        return DPS_Common(pmTarget);
    }
}

bool Script_Rogue::DPS_Combat(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    sourceAI->BaseMove(pmTarget);

    uint32 energy = me->GetPower(Powers::POWER_ENERGY);
    if (energy > 25)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
    {
        if (sourceAI->CastSpell(pmTarget, "Adrenaline Rush", MELEE_MAX_DISTANCE))
        {
            me->Yell("BOSS RUSH !", Language::LANG_UNIVERSAL);
            return true;
        }
        if (energy > 25)
        {
            if (sourceAI->CastSpell(pmTarget, "Blade Flurry", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }

    if (energy > 10)
    {
        if (sourceAI->CastSpell(pmTarget, "Riposte", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (energy > 50)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::DPS_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    sourceAI->BaseMove(pmTarget);

    uint32 energy = me->GetPower(Powers::POWER_ENERGY);
    if (energy > 25)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }
    if (energy > 50)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::Attack(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
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
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    sourceAI->BaseMove(pmTarget);

    uint32 energy = me->GetPower(Powers::POWER_ENERGY);
    if (energy > 25)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
    {
        if (sourceAI->CastSpell(pmTarget, "Adrenaline Rush", MELEE_MAX_DISTANCE))
        {
            me->Yell("BOSS RUSH !", Language::LANG_UNIVERSAL);
            return true;
        }
        if (energy > 25)
        {
            if (sourceAI->CastSpell(pmTarget, "Blade Flurry", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }

    if (energy > 10)
    {
        if (sourceAI->CastSpell(pmTarget, "Riposte", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (energy > 50)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::Attack_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    sourceAI->BaseMove(pmTarget);
    uint32 energy = me->GetPower(Powers::POWER_ENERGY);    
    if (energy > 25)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
    }
    if (energy > 45)
    {
        uint8 comboPoints = me->GetComboPoints();
        if (urand(1, 5) <= comboPoints)
        {
            sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Rogue::Buff()
{
    return false;
}
