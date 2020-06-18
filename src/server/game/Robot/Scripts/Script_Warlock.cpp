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

bool Script_Warlock::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Warlock::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting)
{
    bool meResult = false;
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
    {
        if (me->GetHealthPct() > 50)
        {
            if (CastSpell(me, "Life Tap"))
            {
                return true;
            }
        }
    }
    uint32 characterTalentTab = me->GetMaxTalentCountTab();
    switch (characterTalentTab)
    {
    case 0:
    {
        meResult = DPS_Affliction(pmTarget, pmChase, pmAOE, pmTank);
        break;
    }
    case 1:
    {
        meResult = DPS_Demonology(pmTarget, pmChase, pmAOE, pmTank);
        break;
    }
    case 2:
    {
        meResult = DPS_Destruction(pmTarget, pmChase, pmAOE, pmTank);
        break;
    }
    default:
    {
        meResult = DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
        break;
    }
    }
    if (meResult)
    {
        PetAttack(pmTarget);
    }
    else
    {
        PetStop();
    }

    return meResult;
}

bool Script_Warlock::DPS_Affliction(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
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
    if (pmChase)
    {
        if (targetDistance > ATTACK_RANGE_LIMIT)
        {
            return false;
        }
        if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
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

bool Script_Warlock::DPS_Demonology(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
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
    if (pmChase)
    {
        if (targetDistance > ATTACK_RANGE_LIMIT)
        {
            return false;
        }
        if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
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

bool Script_Warlock::DPS_Destruction(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
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
    if (pmChase)
    {
        if (targetDistance > ATTACK_RANGE_LIMIT)
        {
            return false;
        }
        if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
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
        if (pmTank)
        {
            if (pmTank->getAttackers().size() >= 3)
            {
                uint32 inRangeCount = 0;
                for (std::set<Unit*>::const_iterator i = pmTank->getAttackers().begin(); i != pmTank->getAttackers().end(); ++i)
                {
                    if (Unit* eachAttacker = *i)
                    {
                        if (eachAttacker->GetDistance(pmTank) < AOE_TARGETS_RANGE)
                        {
                            inRangeCount++;
                            if (inRangeCount >= 3)
                            {
                                if (CastSpell(eachAttacker, "Shadowfury", WARLOCK_RANGE_DISTANCE, true))
                                {
                                    return true;
                                }
                                if (CastSpell(eachAttacker, "Rain of Fire", WARLOCK_RANGE_DISTANCE))
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
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 10.0f)
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

bool Script_Warlock::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
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
    if (pmChase)
    {
        if (targetDistance > ATTACK_RANGE_LIMIT)
        {
            return false;
        }
        if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
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
    bool meResult = false;
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
    {
        if (me->GetHealthPct() > 50)
        {
            if (CastSpell(me, "Life Tap"))
            {
                return true;
            }
        }
    }
    uint32 characterTalentTab = me->GetMaxTalentCountTab();
    switch (characterTalentTab)
    {
    case 0:
    {
        meResult = Attack_Affliction(pmTarget);
        break;
    }
    case 1:
    {
        meResult = Attack_Demonology(pmTarget);
        break;
    }
    case 2:
    {
        meResult = Attack_Destruction(pmTarget);
        break;
    }
    default:
    {
        meResult = Attack_Common(pmTarget);
        break;
    }
    }
    if (meResult)
    {
        PetAttack(pmTarget);
    }
    else
    {
        PetStop();
    }

    return meResult;
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

    if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
    {
        return false;
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

    if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
    {
        return false;
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

    if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
    {
        return false;
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
    if (!Chase(pmTarget, WARLOCK_RANGE_DISTANCE))
    {
        return false;
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
        if (petting)
        {
            Pet* myPet = me->GetPet();
            if (!myPet)
            {
                if (CastSpell(me, "Summon Imp"))
                {
                    return true;
                }
            }
        }
        else
        {
            if (Pet* myPet = me->GetPet())
            {
                myPet->DespawnOrUnsummon(500);
            }
        }
    }

    return false;
}
