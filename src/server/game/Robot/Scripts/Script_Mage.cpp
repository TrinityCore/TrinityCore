#include "Script_Mage.h"

#ifndef MAGE_CLOSER_DISTANCE
# define MAGE_CLOSER_DISTANCE 20
#endif

#ifndef MAGE_RANGE_DISTANCE
# define MAGE_RANGE_DISTANCE 25
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
	return DPS_Common(pmTarget);
}

bool Script_Mage::DPS_Common(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
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
	return Attack_Common(pmTarget);
}

bool Script_Mage::Attack_Common(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
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
	Player* me = sourceAI->sourcePlayer;
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