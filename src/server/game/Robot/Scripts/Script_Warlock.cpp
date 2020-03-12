#include "Script_Warlock.h"
#include "Pet.h"
#include "PetAI.h"
#include "Group.h"
#include "RobotManager.h"

Script_Warlock::Script_Warlock(Player* pmMe) :Script_Base(pmMe)
{
    
}

bool Script_Warlock::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Warlock::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Warlock::DPS(Unit* pmTarget, bool pmChase, bool pmAOE)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Affliction(pmTarget, pmChase, pmAOE);
    }
    case 1:
    {
        return DPS_Demonology(pmTarget, pmChase, pmAOE);
    }
    case 2:
    {
        return DPS_Destruction(pmTarget, pmChase, pmAOE);
    }
    default:
        return DPS_Common(pmTarget, pmChase, pmAOE);
    }
}

bool Script_Warlock::DPS_Affliction(Unit* pmTarget, bool pmChase, bool pmAOE)
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
    PetAttack(me->GetPet(), pmTarget);
    if (pmChase)
    {
        Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::DPS_Demonology(Unit* pmTarget, bool pmChase, bool pmAOE)
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
    PetAttack(me->GetPet(), pmTarget);
    if (pmChase)
    {
        Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::DPS_Destruction(Unit* pmTarget, bool pmChase, bool pmAOE)
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
    PetAttack(me->GetPet(), pmTarget);
    if (pmChase)
    {
        Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
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
                                        if (CastSpell((*i), "Shadowfury", WARLOCK_RANGE_DISTANCE))
                                        {
                                            return true;
                                        }
                                        if (CastSpell((*i), "Rain of Fire", WARLOCK_RANGE_DISTANCE))
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
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3.0f)
    {
        if (CastSpell(pmTarget, "Curse of the Elements", WARLOCK_RANGE_DISTANCE, true))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Immolate", WARLOCK_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Conflagrate", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Chaos Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Incinerate", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE)
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
        Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Attack(Unit* pmTarget)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return Attack_Affliction(pmTarget);
    }
    case 1:
    {
        return Attack_Demonology(pmTarget);
    }
    case 2:
    {
        return Attack_Destruction(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Warlock::Attack_Affliction(Unit* pmTarget)
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
    PetAttack(me->GetPet(), pmTarget);
    Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Attack_Demonology(Unit* pmTarget)
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
    PetAttack(me->GetPet(), pmTarget);
    Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Attack_Destruction(Unit* pmTarget)
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
    PetAttack(me->GetPet(), pmTarget);
    Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Immolate", WARLOCK_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Conflagrate", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Chaos Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Incinerate", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Attack_Common(Unit* pmTarget)
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
    Chase(pmTarget, WARLOCK_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Buff(Unit* pmTarget, bool pmCure)
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
        if (FindSpellID("Fel Armor") > 0)
        {
            if (CastSpell(me, "Fel Armor", WARLOCK_RANGE_DISTANCE, true))
            {
                return true;
            }
        }
        else
        {
            if (CastSpell(me, "Demon Armor", WARLOCK_RANGE_DISTANCE, true))
            {
                return true;
            }
        }

        Pet* myPet = me->GetPet();
        if (!myPet)
        {
            if (CastSpell(me, "Summon Imp"))
            {
                return true;
            }
        }
    }

    return false;
}

void Script_Warlock::PetAttack(Pet* pmMyPet, Unit* pmTarget)
{
    if (pmMyPet)
    {
        if (CharmInfo* pci = pmMyPet->GetCharmInfo())
        {
            if (!pci->IsCommandAttack())
            {
                pci->SetIsCommandAttack(true);
                CreatureAI* AI = pmMyPet->ToCreature()->AI();
                if (PetAI* petAI = dynamic_cast<PetAI*>(AI))
                {
                    petAI->_AttackStart(pmTarget);
                }
                else
                {
                    AI->AttackStart(pmTarget);
                }
            }
        }
    }
}
