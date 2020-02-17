#include "Script_Paladin.h"

#ifndef PALADIN_CLOSER_DISTANCE
# define PALADIN_CLOSER_DISTANCE 25
#endif

#ifndef PALADIN_RANGE_DISTANCE
# define PALADIN_RANGE_DISTANCE 30
#endif

Script_Paladin::Script_Paladin(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Paladin::HealMe()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    float healthPCT = me->GetHealthPct();
    if (healthPCT < 20)
    {
        if (!sourceAI->HasAura(me, "Forbearance"))
        {
            if (sourceAI->CastSpell(me, "Lay on Hands"))
            {
                return true;
            }
        }
    }
    if (healthPCT < 40)
    {
        if (sourceAI->CastSpell(me, "Holy Light"))
        {
            return true;
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

bool Script_Paladin::Healer()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    Player* tank = NULL;
    Player* lowestMember = NULL;
    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member->groupRole == 1)
            {
                tank = member;
                break;
            }
            else
            {
                if (member->GetHealthPct() < 50.0f)
                {
                    if (lowestMember)
                    {
                        if (member->GetHealthPct() < lowestMember->GetHealthPct())
                        {
                            lowestMember = member;
                        }
                    }
                    else
                    {
                        lowestMember = member;
                    }
                }
            }
        }
    }

    if (tank)
    {
        if (!tank->IsAlive())
        {
            return false;
        }
        sourceAI->BaseMove(tank, PALADIN_RANGE_DISTANCE, false);
        float healthPCT = tank->GetHealthPct();
        if (healthPCT < 20)
        {
            if (!sourceAI->HasAura(tank, "Forbearance"))
            {
                if (sourceAI->CastSpell(tank, "Lay on Hands", PALADIN_RANGE_DISTANCE))
                {
                    return true;
                }
            }
        }
        if (healthPCT < 60)
        {
            if (sourceAI->CastSpell(tank, "Holy Light", PALADIN_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (healthPCT < 80)
        {
            if (sourceAI->CastSpell(tank, "Flash of Light", PALADIN_RANGE_DISTANCE))
            {
                return true;
            }
        }

        for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
        {
            std::list<AuraEffect*> auraList = tank->GetAuraEffectsByType((AuraType)type);
            for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
            {
                const SpellInfo* pST = (*auraIT)->GetSpellInfo();
                if (!pST->IsPositive())
                {
                    if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (sourceAI->CastSpell(tank, "Purify"))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    if (lowestMember)
    {
        sourceAI->BaseMove(lowestMember, PALADIN_RANGE_DISTANCE, false);
        if (sourceAI->CastSpell(lowestMember, "Holy Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }

    return false;
}

bool Script_Paladin::DPS(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget);
    }
    case 1:
    {
        return DPS_Common(pmTarget);
    }
    case 2:
    {
        return DPS_Retribution(pmTarget);
    }
    default:
        return DPS_Common(pmTarget);
    }
}

bool Script_Paladin::DPS_Retribution(Unit* pmTarget)
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

    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member->groupRole == 1)
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
                                if (sourceAI->CastSpell((*i), "Consecration", MELEE_MAX_DISTANCE))
                                {
                                    return true;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }

    if (sourceAI->CastSpell(pmTarget, "Judgement of Wisdom", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (sourceAI->CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Paladin::DPS_Common(Unit* pmTarget)
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
    switch (sourceAI->characterTalentTab)
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
        return Attack_Common(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Paladin::Attack_Common(Unit* pmTarget)
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

    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (sourceAI->CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Paladin::Buff()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (sourceAI->CastSpell(me, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
    {
        return true;
    }
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        if (sourceAI->CastSpell(me, "Concentration Aura", PALADIN_RANGE_DISTANCE, true))
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
        break;
    }
    case 2:
    {
        if (sourceAI->CastSpell(me, "Retribution Aura", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
        break;
    }
    default:
    {
        if (sourceAI->CastSpell(me, "Devotion Aura", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
        break;
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

    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member)
            {
                if (member->GetGUID() == me->GetGUID())
                {
                    continue;
                }
                float targetDistance = me->GetDistance(member);
                if (targetDistance < PALADIN_RANGE_DISTANCE)
                {
                    if (sourceAI->CastSpell(member, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
                    {
                        return true;
                    }
                    for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
                    {
                        std::list<AuraEffect*> auraList = member->GetAuraEffectsByType((AuraType)type);
                        for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
                        {
                            const SpellInfo* pST = (*auraIT)->GetSpellInfo();
                            if (!pST->IsPositive())
                            {
                                if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                                {
                                    if (sourceAI->CastSpell(member, "Purify"))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}
