#include "Script_Priest.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "SpellAuraEffects.h"
#include "RobotManager.h"
#include "Group.h"

Script_Priest::Script_Priest(Player* pmMe) :Script_Base(pmMe)
{

}

bool Script_Priest::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Priest::Heal(Unit* pmTarget, bool pmCure)
{
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    case 1:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    case 2:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    default:
        return Heal_Holy(pmTarget, pmCure);
    }

    return false;
}

bool Script_Priest::Heal_Holy(Unit* pmTarget, bool pmCure)
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
    if (me->GetDistance(pmTarget) > PRIEST_HEAL_DISTANCE)
    {
        return false;
    }
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT > 40.0f && healthPCT < 90.0f)
    {
        if (!HasAura(pmTarget, "Weakened Soul"))
        {
            if (pmTarget->IsInCombat())
            {
                if (CastSpell(pmTarget, "Power Word: Shield", PRIEST_HEAL_DISTANCE))
                {
                    return true;
                }
            }
        }
        if (CastSpell(pmTarget, "Renew", PRIEST_HEAL_DISTANCE, true, true))
        {
            return true;
        }
    }
    if (healthPCT < 40.0f)
    {
        if (CastSpell(pmTarget, "Desperate Prayer", PRIEST_HEAL_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 50.0f)
    {
        if (CastSpell(pmTarget, "Flash Heal", PRIEST_HEAL_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 80.0f)
    {
        if (CastSpell(pmTarget, "Greater Heal", PRIEST_HEAL_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Heal", PRIEST_HEAL_DISTANCE))
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
                    if (pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (CastSpell(pmTarget, "Cure Disease", PRIEST_HEAL_DISTANCE))
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

bool Script_Priest::GroupHeal()
{
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return GroupHeal_Holy();
    }
    case 1:
    {
        return GroupHeal_Holy();
    }
    case 2:
    {
        return GroupHeal_Holy();
    }
    default:
        return GroupHeal_Holy();
    }

    return false;
}

bool Script_Priest::GroupHeal_Holy()
{
    if (!me)
    {
        return false;
    }
    if (CastSpell(me, "Circle of Healing", PRIEST_HEAL_DISTANCE))
    {
        return true;
    }
    if (Group* myGroup = me->GetGroup())
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->GetHealthPct() < 60.0f)
                {
                    if (me->GetDistance(member) > MID_RANGE && me->GetDistance(member) < PRIEST_HEAL_DISTANCE)
                    {
                        if (CastSpell(me, "Prayer of Healing", PRIEST_HEAL_DISTANCE))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        if (CastSpell(me, "Holy Nova", PRIEST_HEAL_DISTANCE))
        {
            return true;
        }
    }

    return false;
}

bool Script_Priest::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 1:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 2:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
    default:
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }

    return false;
}

bool Script_Priest::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
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
    if (pmChase)
    {
        if (!Chase(pmTarget, PRIEST_RANGE_DISTANCE))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget, M_PI / 16))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Attack(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
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
        return Attack_Common(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Priest::Attack_Common(Unit* pmTarget)
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
    if (!Chase(pmTarget, PRIEST_RANGE_DISTANCE))
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Buff(Unit* pmTarget, bool pmCure)
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
    if (me->GetDistance(pmTarget) < PRIEST_RANGE_DISTANCE)
    {
        if (!HasAura(pmTarget, "Power Word: Fortitude") && !HasAura(pmTarget, "Prayer of Fortitude"))
        {
            if (FindSpellID("Prayer of Fortitude"))
            {
                if (CastSpell(pmTarget, "Prayer of Fortitude", PRIEST_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            else
            {
                if (CastSpell(pmTarget, "Power Word: Fortitude", PRIEST_RANGE_DISTANCE, true))
                {
                    return true;
                }
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
                        if (pST->Dispel == DispelType::DISPEL_DISEASE)
                        {
                            if (CastSpell(pmTarget, "Cure Disease", PRIEST_HEAL_DISTANCE))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}
