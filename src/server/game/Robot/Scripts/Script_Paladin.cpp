#include "Script_Paladin.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "SpellAuraEffects.h"
#include "RobotManager.h"
#include "Group.h"

Script_Paladin::Script_Paladin(Player* pmMe) :Script_Base(pmMe)
{
    
}

bool Script_Paladin::Heal(Unit* pmTarget, bool pmCure)
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
    if (me->GetDistance(pmTarget) > PALADIN_RANGE_DISTANCE)
    {
        return false;
    }
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT < 20.0f)
    {
        if (!HasAura(pmTarget, "Forbearance"))
        {
            if (CastSpell(pmTarget, "Lay on Hands", PALADIN_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (healthPCT < 60.0f)
    {
        if (CastSpell(pmTarget, "Holy Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 80.0f)
    {
        if (CastSpell(pmTarget, "Flash of Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }

    if (pmCure)
    {
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
                        if (CastSpell(pmTarget, "Purify"))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool Script_Paladin::Tank(Unit* pmTarget)
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
    me->Attack(pmTarget, true);
    Chase(pmTarget);

    return true;
}

bool Script_Paladin::DPS(Unit* pmTarget, bool pmChase, bool pmAOE)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE);
    }
    case 1:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE);
    }
    case 2:
    {
        return DPS_Retribution(pmTarget, pmChase, pmAOE);
    }
    default:
        return DPS_Common(pmTarget, pmChase, pmAOE);
    }
}

bool Script_Paladin::DPS_Retribution(Unit* pmTarget, bool pmChase, bool pmAOE)
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
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
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
    if (pmAOE)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->groupRole == GroupRole::GroupRole_Tank)
                    {
                        if (member->getAttackers().size() >= 3)
                        {
                            uint32 inRangeCount = 0;
                            for (std::set<Unit*>::const_iterator i = member->getAttackers().begin(); i != member->getAttackers().end(); ++i)
                            {
                                if ((*i)->GetDistance(member) < AOE_TARGETS_RANGE)
                                {
                                    inRangeCount++;
                                    if (inRangeCount >= 3)
                                    {
                                        if (CastSpell((*i), "Consecration", MELEE_MAX_DISTANCE))
                                        {
                                            return true;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }        
    }
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (me->HasAura(AURA_THE_ART_OF_WAR_1) || me->HasAura(AURA_THE_ART_OF_WAR_2))
    {
        if (CastSpell(pmTarget, "Exorcism", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Wisdom", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Crusader Strike", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    return true;
}

bool Script_Paladin::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE)
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
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
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
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Paladin::Attack(Unit* pmTarget)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return Attack_Common(pmTarget);
    }
    case 1:
    {
        return Attack_Common(pmTarget);
    }
    case 2:
    {
        return Attack_Retribution(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Paladin::Attack_Retribution(Unit* pmTarget)
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
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (me->HasAura(AURA_THE_ART_OF_WAR_1) || me->HasAura(AURA_THE_ART_OF_WAR_2))
    {
        if (CastSpell(pmTarget, "Exorcism", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Light", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Crusader Strike", MELEE_MAX_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Paladin::Attack_Common(Unit* pmTarget)
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
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Light", MELEE_MAX_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Paladin::Buff(Unit* pmTarget, bool pmCure)
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
    if (me->GetGUID() == pmTarget->GetGUID())
    {
        switch (characterTalentTab)
        {
        case 0:
        {
            if (CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (CastSpell(me, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (CastSpell(me, "Concentration Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case 1:
        {
            if (CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (CastSpell(me, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (CastSpell(me, "Devotion Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        case 2:
        {
            if (FindSpellID("Seal of Command"))
            {
                if (CastSpell(me, "Seal of Command", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            else
            {
                if (CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            if (CastSpell(me, "Blessing of Might", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            if (CastSpell(me, "Retribution Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        default:
        {
            if (CastSpell(me, "Devotion Aura", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
            break;
        }
        }
    }
    else if (me->GetDistance(pmTarget) < PALADIN_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
    }
    if (pmCure)
    {
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
                        if (CastSpell(pmTarget, "Purify"))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}
