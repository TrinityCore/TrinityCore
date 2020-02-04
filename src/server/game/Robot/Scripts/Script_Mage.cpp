#include "Script_Mage.h"

#include "Group.h"

#ifndef MAGE_AOE_TARGETS_RANGE
# define MAGE_AOE_TARGETS_RANGE 5
#endif

#ifndef MAGE_CLOSER_DISTANCE
# define MAGE_CLOSER_DISTANCE 25
#endif

#ifndef MAGE_RANGE_DISTANCE
# define MAGE_RANGE_DISTANCE 30
#endif

Script_Mage::Script_Mage(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Mage::HealMe()
{
	return false;
}

bool Script_Mage::Tank(Unit* pmTarget)
{
	return false;
}

bool Script_Mage::Healer(Unit* pmTarget)
{
	return false;
}

bool Script_Mage::DPS(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return DPS_Arcane(pmTarget);
    }
    case 1:
    {
        return DPS_Fire(pmTarget);
    }
    case 2:
    {
        return DPS_Frost(pmTarget);
    }
    default:
        return DPS_Common(pmTarget);
    }
}

bool Script_Mage::DPS_Arcane(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Arcane Missiles", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Fire(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Fireball", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Frost(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }

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
                        if ((*i)->GetDistance(member) < MAGE_AOE_TARGETS_RANGE)
                        {
                            inRangeCount++;
                            if (inRangeCount >= 3)
                            {
                                if (sourceAI->CastSpell((*i), "Blizzard", MAGE_RANGE_DISTANCE))
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

    if (sourceAI->CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Common(Unit* pmTarget)
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

	sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
	{
		if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
		{
			if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
			{
				return true;
			}
		}
	}    
	if (sourceAI->CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
	{
		return true;
	}

	return true;
}

bool Script_Mage::Attack(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return Attack_Arcane(pmTarget);
    }
    case 1:
    {
        return Attack_Fire(pmTarget);
    }
    case 2:
    {
        return Attack_Frost(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Mage::Attack_Arcane(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Arcane Missiles", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Fire(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Fireball", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Frost(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (sourceAI->CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Common(Unit* pmTarget)
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

	sourceAI->BaseMove(pmTarget, MAGE_CLOSER_DISTANCE, false);
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
	{
		if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
		{
			if (sourceAI->CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
			{
				return true;
			}
		}
	}
	if (sourceAI->CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
	{
		return true;
	}

	return true;
}

bool Script_Mage::Buff(Unit* pmTarget)
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

	if (sourceAI->CastSpell(pmTarget, "Arcane Intellect", MAGE_RANGE_DISTANCE, true))
	{
		return true;
	}

	return false;
}
