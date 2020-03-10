#include "Script_Rogue.h"

#ifndef ROGUE_PREPARE_DISTANCE
# define ROGUE_PREPARE_DISTANCE 10
#endif

#ifndef ROGUE_RANGE_DISTANCE
# define ROGUE_RANGE_DISTANCE 25
#endif

Script_Rogue::Script_Rogue(uint32 pmCharacterID) :Script_Base()
{
    character = pmCharacterID;
}

bool Script_Rogue::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Rogue::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Rogue::DPS(Unit* pmTarget, bool pmChase)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget, pmChase);
    }
    case 1:
    {
        return DPS_Combat(pmTarget, pmChase);
    }
    case 2:
    {
        return DPS_Common(pmTarget, pmChase);
    }
    default:
        return DPS_Common(pmTarget, pmChase);
    }
}

bool Script_Rogue::DPS_Combat(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
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
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
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

bool Script_Rogue::DPS_Common(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
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

bool Script_Rogue::Attack(Unit* pmTarget)
{
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
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    me->Attack(pmTarget, true);
    Chase(pmTarget);
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
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    me->Attack(pmTarget, true);
    Chase(pmTarget);    
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
    if (energy > 45)
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

bool Script_Rogue::Buff(Unit* pmTarget, bool pmCure)
{
    return false;
}
