#include "Script_Warlock.h"

#ifndef WARLOCK_CLOSER_DISTANCE
# define WARLOCK_CLOSER_DISTANCE 25
#endif

#ifndef WARLOCK_RANGE_DISTANCE
# define WARLOCK_RANGE_DISTANCE 30
#endif

Script_Warlock::Script_Warlock(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Warlock::HealMe()
{
    return false;
}

bool Script_Warlock::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Warlock::Healer(Unit* pmTarget)
{
    return false;
}

bool Script_Warlock::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Warlock::DPS_Common(Unit* pmTarget)
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
    sourceAI->BaseMove(pmTarget, WARLOCK_CLOSER_DISTANCE, false);
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
	{
		if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
		{
			if (sourceAI->CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
			{
				return true;
			}
		}		
	}
	if (sourceAI->CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
	{
		return true;
	}

    return true;
}

bool Script_Warlock::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Warlock::Attack_Common(Unit* pmTarget)
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
    sourceAI->BaseMove(pmTarget, WARLOCK_CLOSER_DISTANCE, false);
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
	{
		if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
		{
			if (sourceAI->CastSpell(pmTarget, "Shoot", WARLOCK_RANGE_DISTANCE))
			{
				return true;
			}
		}
	}
    if (sourceAI->CastSpell(pmTarget, "Shadow Bolt", WARLOCK_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Warlock::Buff(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    Pet* myPet = me->GetPet();
    if (!myPet)
    {
        if (sourceAI->CastSpell(me, "Summon Imp"))
        {
            return true;
        }
    }

    return false;
}
