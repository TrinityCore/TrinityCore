#include "Script_Rogue.h"

#ifndef ROGUE_PREPARE_DISTANCE
# define ROGUE_PREPARE_DISTANCE 10
#endif

#ifndef ROGUE_RANGE_DISTANCE
# define ROGUE_RANGE_DISTANCE 25
#endif

Script_Rogue::Script_Rogue(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Rogue::HealMe()
{
	return false;
}

bool Script_Rogue::Tank(Unit* pmTarget)
{
	return false;
}

bool Script_Rogue::Healer(Unit* pmTarget)
{
	return false;
}

bool Script_Rogue::DPS(Unit* pmTarget)
{
	return DPS_Common(pmTarget);
}

bool Script_Rogue::DPS_Common(Unit* pmTarget)
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

	sourceAI->BaseMove(pmTarget);

	uint32 energy = me->GetPower(Powers::POWER_ENERGY);
	if (energy > 25)
	{
		if (pmTarget->IsNonMeleeSpellCast(false))
		{
			if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
	}
	if (energy > 50)
	{
		uint8 comboPoints = me->GetComboPoints();
		if (urand(1, 5) <= comboPoints)
		{
			sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
			return true;
		}
		if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
		{
			return true;
		}
	}

	return true;
}

bool Script_Rogue::Attack(Unit* pmTarget)
{
	return Attack_Common(pmTarget);
}

bool Script_Rogue::Attack_Common(Unit* pmTarget)
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
	uint32 energy = me->GetPower(Powers::POWER_ENERGY);
	if (sourceAI->FindSpellID("Cheap Shot") > 0)
	{
		if (targetDistance > ROGUE_PREPARE_DISTANCE)
		{
			sourceAI->BaseMove(pmTarget, MELEE_MAX_DISTANCE, true);
			if (targetDistance < ROGUE_RANGE_DISTANCE)
			{
				if (sourceAI->CastSpell(me, "Stealth", MELEE_MAX_DISTANCE, true))
				{
					return true;
				}
			}
		}
		else
		{
			if (sourceAI->HasAura(me, "Stealth"))
			{
				sourceAI->BaseMove(pmTarget, MELEE_MAX_DISTANCE, true);
				if (energy > 60)
				{
					if (sourceAI->CastSpell(pmTarget, "Cheap Shot", MELEE_MAX_DISTANCE))
					{
						return true;
					}
				}
			}
			else
			{
				sourceAI->BaseMove(pmTarget);
				if (energy > 25)
				{
					if (pmTarget->IsNonMeleeSpellCast(false))
					{
						if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
						{
							return true;
						}
					}
				}
				if (energy > 45)
				{
					uint8 comboPoints = me->GetComboPoints();
					if (urand(1, 5) <= comboPoints)
					{
						sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
						return true;
					}
					if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		sourceAI->BaseMove(pmTarget);
		if (energy > 25)
		{
			if (pmTarget->IsNonMeleeSpellCast(false))
			{
				if (sourceAI->CastSpell(pmTarget, "Kick", MELEE_MAX_DISTANCE))
				{
					return true;
				}
			}
		}
		if (energy > 45)
		{
			uint8 comboPoints = me->GetComboPoints();
			if (urand(1, 5) <= comboPoints)
			{
				sourceAI->CastSpell(pmTarget, "Eviscerate", MELEE_MAX_DISTANCE);
				return true;
			}
			if (sourceAI->CastSpell(pmTarget, "Sinister Strike", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
	}

	return true;
}

bool Script_Rogue::Buff(Unit* pmTarget)
{
	return false;
}
