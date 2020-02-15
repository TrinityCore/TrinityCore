#include "Script_Priest.h"

#include "Group.h"

#ifndef PRIEST_CLOSER_DISTANCE
# define PRIEST_CLOSER_DISTANCE 25
#endif

#ifndef PRIEST_RANGE_DISTANCE
# define PRIEST_RANGE_DISTANCE 30
#endif

Script_Priest::Script_Priest(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Priest::HealMe()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    float healthPCT = me->GetHealthPct();
    if (healthPCT < 90)
    {
        if (!sourceAI->HasAura(me, "Weakened Soul"))
        {
            if (sourceAI->CastSpell(me, "Power Word: Shield"))
            {
                return true;
            }
        }
        if (sourceAI->CastSpell(me, "Renew", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }
    }
    if (healthPCT < 50)
    {
        if (sourceAI->CastSpell(me, "Heal"))
        {
            return true;
        }
    }

    return false;
}

bool Script_Priest::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Priest::Healer()
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
        float targetDistance = me->GetDistance(tank);
        if (targetDistance > 200)
        {
            return false;
        }
        sourceAI->BaseMove(tank, PRIEST_RANGE_DISTANCE, false);
        Unit* tankTarget = tank->GetSelectedUnit();
        if (tankTarget)
        {
            // when facing boss
            if (tankTarget->GetMaxHealth() / me->GetMaxHealth() > 4)
            {
                if (sourceAI->CastSpell(tank, "Lightwell", PRIEST_RANGE_DISTANCE))
                {
                    me->Say("BOSS RUSH !", Language::LANG_UNIVERSAL);
                    return true;
                }
            }
        }        

        float healthPCT = tank->GetHealthPct();
        if (healthPCT < 30)
        {
            if (sourceAI->CastSpell(tank, "Desperate Prayer", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (healthPCT < 60)
        {
            if (sourceAI->CastSpell(tank, "Greater Heal", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
            if (sourceAI->CastSpell(tank, "Heal", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (healthPCT < 80)
        {
            if (sourceAI->CastSpell(tank, "Flash Heal", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (healthPCT < 90)
        {
            if (!sourceAI->HasAura(tank, "Weakened Soul"))
            {
                if (sourceAI->CastSpell(tank, "Power Word: Shield", PRIEST_RANGE_DISTANCE))
                {
                    return true;
                }
            }
            if (sourceAI->CastSpell(tank, "Renew", PRIEST_RANGE_DISTANCE, true))
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
                    if (pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (sourceAI->CastSpell(tank, "Cure Disease"))
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
        if (sourceAI->CastSpell(lowestMember, "Renew", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }
    }

    return false;
}

bool Script_Priest::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Priest::DPS_Common(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, PRIEST_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Priest::Attack_Common(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, PRIEST_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Buff()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member)
            {
                float targetDistance = me->GetDistance(member);
                if (targetDistance < 200)
                {
                    if (sourceAI->CastSpell(member, "Power Word: Fortitude", PRIEST_RANGE_DISTANCE, true))
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
                                if (pST->Dispel == DispelType::DISPEL_DISEASE)
                                {
                                    if (sourceAI->CastSpell(member, "Cure Disease"))
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
    else
    {
        if (sourceAI->CastSpell(me, "Power Word: Fortitude", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }

        for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
        {
            std::list<AuraEffect*> auraList = me->GetAuraEffectsByType((AuraType)type);
            for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
            {
                const SpellInfo* pST = (*auraIT)->GetSpellInfo();
                if (!pST->IsPositive())
                {
                    if (pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (sourceAI->CastSpell(me, "Cure Disease"))
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
