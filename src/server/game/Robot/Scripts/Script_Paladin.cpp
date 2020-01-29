#include "Script_Paladin.h"

#ifndef PALADIN_CLOSER_DISTANCE
# define PALADIN_CLOSER_DISTANCE 20
#endif

#ifndef PALADIN_RANGE_DISTANCE
# define PALADIN_RANGE_DISTANCE 25
#endif

Script_Paladin::Script_Paladin(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Paladin::HealMe()
{    
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    float healthPCT = me->GetHealthPct();
    if (healthPCT < 30)
    {
        if (sourceAI->CastSpell(me, "Holy Light"))
        {
            return true;
        }
    }
    else if (healthPCT < 50)
    {
        if (!sourceAI->HasAura(me, "Forbearance"))
        {
            if (sourceAI->CastSpell(me, "Divine Protection"))
            {
                return true;
            }
        }
    }

    for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
    {
        std::list<AuraEffect*> auraList = me->GetAuraEffectsByType((AuraType)type);
        for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
        {
            const SpellInfo* pST = (*auraIT)->GetSpellInfo();
            if (!pST->IsPositive())
            {
                if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                {
                    if (sourceAI->CastSpell(me, "Purify"))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Script_Paladin::Tank(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
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

    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (sourceAI->CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    if (targetDistance < 10)
    {
        if (sourceAI->CastSpell(me, "Consecration", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    return true;
}

bool Script_Paladin::Healer(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
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
    sourceAI->BaseMove(pmTarget, PALADIN_CLOSER_DISTANCE, false);
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT < 30)
    {
        if (pmTarget->ToPlayer())
        {
            if (!sourceAI->HasAura(pmTarget, "Forbearance"))
            {
                if (sourceAI->CastSpell(pmTarget, "Divine Protection"))
                {
                    return true;
                }
            }
        }
    }
    else if (healthPCT < 50)
    {
        if (sourceAI->CastSpell(pmTarget, "Holy Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    else if (healthPCT < 80)
    {
        if (sourceAI->CastSpell(pmTarget, "Flash of Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }

    for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
    {
        std::list<AuraEffect*> auraList = pmTarget->GetAuraEffectsByType((AuraType)type);
        for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
        {
            const SpellInfo* pST = (*auraIT)->GetSpellInfo();
            if (!pST->IsPositive())
            {
                if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                {
                    if (sourceAI->CastSpell(pmTarget, "Purify"))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Script_Paladin::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Paladin::DPS_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
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

    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (sourceAI->CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Paladin::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Paladin::Attack_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
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

    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (sourceAI->CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Paladin::Buff(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    if (!pmTarget->IsAlive())
    {
        if (sourceAI->CastSpell(pmTarget, "Redemption", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        switch (sourceAI->characterType)
        {
        case 0:
        {
            if (sourceAI->CastSpell(me, "Concentration Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (sourceAI->CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case 1:
        {
            if (sourceAI->CastSpell(me, "Devotion Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (sourceAI->CastSpell(me, "Righteous Fury", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (sourceAI->CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case 2:
        {
            if (sourceAI->CastSpell(me, "Retribution Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (sourceAI->CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        default:
        {
            break;
        }
        }
        switch (pmTarget->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_MAGE:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case Classes::CLASS_DRUID:
        {
            if (sourceAI->CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }

    return false;
}
