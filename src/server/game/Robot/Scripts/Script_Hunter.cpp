#include "Script_Hunter.h"

#ifndef HUNTER_PREPARE_DISTANCE
# define HUNTER_PREPARE_DISTANCE 9
#endif

#ifndef HUNTER_CLOSER_DISTANCE
# define HUNTER_CLOSER_DISTANCE 30
#endif

#ifndef HUNTER_RANGE_DISTANCE
# define HUNTER_RANGE_DISTANCE 35
#endif

Script_Hunter::Script_Hunter(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Hunter::HealMe()
{
    return false;
}

bool Script_Hunter::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Hunter::Healer(Unit* pmTarget)
{
    return false;
}

bool Script_Hunter::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Hunter::DPS_Common(Unit* pmTarget)
{
    Player* me = sourceAI->sourcePlayer;
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->CanAttack(pmTarget))
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
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        sourceAI->CastSpell(pmTarget, "Raptor Strike");
        sourceAI->CastSpell(pmTarget, "Mongoose Bite");
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Hunter::Attack_Common(Unit* pmTarget)
{
    Player* me = sourceAI->sourcePlayer;
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->CanAttack(pmTarget))
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
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        sourceAI->CastSpell(pmTarget, "Raptor Strike");
        sourceAI->CastSpell(pmTarget, "Mongoose Bite");
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Buff(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
	Unit* pet = me->GetPet();
	if (!pet)
	{
		if (sourceAI->CastSpell(me, "Call Pet"))
		{
			return true;
		}
	}
	else  if (!pet->IsAlive())
	{
		if (sourceAI->CastSpell(me, "Revive Pet"))
		{
			return true;
		}
	}

	return false;
}