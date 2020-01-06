#include "Script_Druid.h"

#ifndef DRUID_PREPARE_DISTANCE
# define DRUID_PREPARE_DISTANCE 10
#endif

#ifndef DRUID_CLOSER_DISTANCE
# define DRUID_CLOSER_DISTANCE 20
#endif

#ifndef DRUID_RANGE_DISTANCE
# define DRUID_RANGE_DISTANCE 25
#endif

Script_Druid::Script_Druid(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Druid::DPS(Unit* pmTarget)
{
	switch (sourceAI->characterType)
	{
	case 0:
	{
		return DPS_Balance(pmTarget);
	}
	case 1:
	{
		return DPS_Feral(pmTarget);
	}
	default:
	{
		break;
	}
	}

	return false;
}

bool Script_Druid::DPS_Balance(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}

	if (me->GetShapeshiftForm() == ShapeshiftForm::FORM_NONE)
	{
		if (sourceAI->CastSpell(me, "Moonkin Form"))
		{
			return true;
		}
	}
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
	{
		if (sourceAI->CastSpell(me, "Innervate", DRUID_RANGE_DISTANCE, false, false, true))
		{
			return true;
		}
	}
	sourceAI->BaseMove(pmTarget, DRUID_CLOSER_DISTANCE, false);
	if (!pmTarget->HasTarget())
	{
		if (sourceAI->CastSpell(pmTarget, "Starfire", DRUID_RANGE_DISTANCE))
		{
			return true;
		}
	}
	else
	{
		if (sourceAI->CastSpell(pmTarget, "Moonfire", DRUID_RANGE_DISTANCE, true, true))
		{
			return true;
		}
		if (me->GetObjectGuid() != pmTarget->GetSelectionGuid())
		{
			if (sourceAI->CastSpell(pmTarget, "Starfire", DRUID_RANGE_DISTANCE))
			{
				return true;
			}
		}
	}
	if (sourceAI->CastSpell(pmTarget, "Wrath", DRUID_RANGE_DISTANCE))
	{
		return true;
	}

	return true;
}

bool Script_Druid::DPS_Feral(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}

	switch (me->GetShapeshiftForm())
	{
	case ShapeshiftForm::FORM_NONE:
	{
		sourceAI->CastSpell(me, "Cat Form");
		break;
	}
	case ShapeshiftForm::FORM_CAT:
	{
		sourceAI->BaseMove(pmTarget);
		sourceAI->CastSpell(me, "Dash");
		uint32 energy = me->GetPower(Powers::POWER_ENERGY);
		if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
		{
			return true;
		}
		if (targetDistance < DRUID_PREPARE_DISTANCE)
		{
			if (energy > 20)
			{
				if (sourceAI->CastSpell(me, "Tiger's Fury", MELEE_MAX_DISTANCE, true))
				{
					return true;
				}
			}
		}
		if (energy > 35)
		{
			uint32 spellID = sourceAI->FindSpellID("Rip");
			if (spellID != 0)
			{
				uint8 comboPoints = me->GetComboPoints();
				if (sourceAI->HasAura(pmTarget, "Rip", true))
				{
					if (urand(1, 5) <= comboPoints)
					{
						sourceAI->CastSpell(pmTarget, "Ferocious Bite", MELEE_MAX_DISTANCE);
						return true;
					}
				}
				else
				{
					if (urand(1, 5) <= comboPoints)
					{
						sourceAI->CastSpell(pmTarget, "Rip", MELEE_MAX_DISTANCE);
						return true;
					}
				}
			}
		}
		if (energy > 45)
		{
			if (sourceAI->CastSpell(pmTarget, "Rake", MELEE_MAX_DISTANCE, true, true))
			{
				return true;
			}
			if (sourceAI->CastSpell(pmTarget, "Claw", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
		break;
	}
	default:
	{
		sourceAI->ClearShapeshift();
		break;
	}
	}

	return true;
}

bool Script_Druid::Tank(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}

	switch (me->GetShapeshiftForm())
	{
	case ShapeshiftForm::FORM_NONE:
	{
		if (sourceAI->CastSpell(me, "Dire Bear Form"))
		{
			break;
		}
		if (sourceAI->CastSpell(me, "Bear Form"))
		{
			break;
		}
		break;
	}
	case ShapeshiftForm::FORM_DIREBEAR:
	{
		if (me->GetHealthPercent() < 80)
		{
			sourceAI->CastSpell(me, "Barkskin");
		}
		sourceAI->BaseMove(pmTarget);
		sourceAI->CastSpell(me, "Enrage");
		sourceAI->CastSpell(pmTarget, "Growl");
		uint32 rage = me->GetPower(Powers::POWER_RAGE);
		if (rage > 500)
		{
			if (me->GetHealthPercent() < 60)
			{
				if (sourceAI->CastSpell(me, "Frenzied Regeneration"))
				{
					return true;
				}
			}
		}
		if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
		{
			return true;
		}
		if (rage > 100)
		{
			if (sourceAI->CastSpell(pmTarget, "Demoralizing Roar", MELEE_MAX_DISTANCE, true))
			{
				return true;
			}
			if (pmTarget->IsNonMeleeSpellCasted(false))
			{
				if (sourceAI->CastSpell(pmTarget, "Bash", MELEE_MAX_DISTANCE))
				{
					return true;
				}
			}
		}
		uint16 validAttackerCount = 0;
		for (Unit::AttackerSet::const_iterator itr = me->getAttackers().begin(); itr != me->getAttackers().end(); ++itr)
		{
			float distance = me->GetDistance((*itr));
			if (distance <= 5)
			{
				validAttackerCount++;
			}
		}
		if (validAttackerCount > 1)
		{
			if (rage > 150)
			{
				if (me->GetDistance(pmTarget) < DRUID_PREPARE_DISTANCE)
				{
					if (sourceAI->CastSpell(me, "Challenging Roar"))
					{
						return true;
					}
				}
			}
			if (rage > 200)
			{
				if (sourceAI->CastSpell(pmTarget, "Swipe", MELEE_MAX_DISTANCE))
				{
					return true;
				}
			}
		}
		if (rage > 200)
		{
			if (sourceAI->CastSpell(pmTarget, "Maul", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
		break;
	}
	case ShapeshiftForm::FORM_BEAR:
	{
		if (me->GetHealthPercent() < 80)
		{
			sourceAI->CastSpell(me, "Barkskin");
		}
		sourceAI->BaseMove(pmTarget);
		sourceAI->CastSpell(me, "Enrage");
		sourceAI->CastSpell(pmTarget, "Growl");
		uint32 rage = me->GetPower(Powers::POWER_RAGE);
		if (rage > 500)
		{
			if (me->GetHealthPercent() < 60)
			{
				if (sourceAI->CastSpell(me, "Frenzied Regeneration"))
				{
					return true;
				}
			}
		}
		if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
		{
			return true;
		}
		if (rage > 100)
		{
			if (sourceAI->CastSpell(pmTarget, "Demoralizing Roar", MELEE_MAX_DISTANCE, true))
			{
				return true;
			}
			if (pmTarget->IsNonMeleeSpellCasted(false))
			{
				if (sourceAI->CastSpell(pmTarget, "Bash", MELEE_MAX_DISTANCE))
				{
					return true;
				}
			}
		}
		uint16 validAttackerCount = 0;
		for (Unit::AttackerSet::const_iterator itr = me->getAttackers().begin(); itr != me->getAttackers().end(); ++itr)
		{
			float distance = me->GetDistance((*itr));
			if (distance <= 5)
			{
				validAttackerCount++;
			}
		}
		if (validAttackerCount > 1)
		{
			if (rage > 150)
			{
				if (me->GetDistance(pmTarget) < DRUID_PREPARE_DISTANCE)
				{
					if (sourceAI->CastSpell(me, "Challenging Roar"))
					{
						return true;
					}
				}
			}
			if (rage > 200)
			{
				if (sourceAI->CastSpell(pmTarget, "Swipe", MELEE_MAX_DISTANCE))
				{
					return true;
				}
			}
		}
		if (rage > 200)
		{
			if (sourceAI->CastSpell(pmTarget, "Maul", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
		break;
	}
	default:
	{
		sourceAI->ClearShapeshift();
		break;
	}
	}

	return true;
}

bool Script_Druid::Attack(Unit* pmTarget)
{
	switch (sourceAI->characterType)
	{
	case 0:
	{
		return Attack_Balance(pmTarget);
	}
	case 1:
	{
		return Attack_Feral(pmTarget);
	}
	case 2:
	{
		return Attack_Restoration(pmTarget);
	}
	default:
	{
		break;
	}
	}

	return false;
}

bool Script_Druid::Attack_Balance(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}

	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
	{
		if (sourceAI->CastSpell(me, "Innervate", DRUID_RANGE_DISTANCE, false, false, true))
		{
			return true;
		}
	}
	if (me->GetShapeshiftForm() == ShapeshiftForm::FORM_NONE)
	{
		if (sourceAI->CastSpell(me, "Moonkin Form"))
		{
			return true;
		}
	}
	sourceAI->BaseMove(pmTarget, DRUID_CLOSER_DISTANCE, false);
	if (pmTarget->GetSelectionGuid().IsEmpty())
	{
		if (sourceAI->CastSpell(pmTarget, "Starfire", DRUID_RANGE_DISTANCE))
		{
			return true;
		}
	}
	else
	{
		if (sourceAI->CastSpell(pmTarget, "Moonfire", DRUID_RANGE_DISTANCE, true, true))
		{
			return true;
		}
		if (me->GetObjectGuid() != pmTarget->GetSelectionGuid())
		{
			if (sourceAI->CastSpell(pmTarget, "Starfire", DRUID_RANGE_DISTANCE))
			{
				return true;
			}
		}
	}
	if (sourceAI->CastSpell(pmTarget, "Wrath", DRUID_RANGE_DISTANCE))
	{
		return true;
	}

	return true;
}

bool Script_Druid::Attack_Feral(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
	switch (me->GetShapeshiftForm())
	{
	case ShapeshiftForm::FORM_NONE:
	{
		if (urand(0, 1) == 1)
		{
			if (sourceAI->CastSpell(me, "Cat Form"))
			{
				break;
			}
		}
		if (sourceAI->CastSpell(me, "Dire Bear Form"))
		{
			break;
		}
		if (sourceAI->CastSpell(me, "Bear Form"))
		{
			break;
		}
		break;
	}
	case ShapeshiftForm::FORM_CAT:
	{
		return Attack_Feral_Cat(pmTarget);
	}
	case ShapeshiftForm::FORM_DIREBEAR:
	{
		return Attack_Feral_Bear(pmTarget);
	}
	case ShapeshiftForm::FORM_BEAR:
	{
		return Attack_Feral_Bear(pmTarget);
	}
	default:
	{
		sourceAI->ClearShapeshift();
		return true;
	}
	}

	return true;
}

bool Script_Druid::Attack_Feral_Cat(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}
	sourceAI->CastSpell(me, "Dash");
	uint32 energy = me->GetPower(Powers::POWER_ENERGY);
	if (sourceAI->FindSpellID("Pounce") > 0)
	{
		if (targetDistance > DRUID_PREPARE_DISTANCE)
		{
			sourceAI->BaseMove(pmTarget, MELEE_MAX_DISTANCE, true, false);
			if (targetDistance < DRUID_RANGE_DISTANCE)
			{
				if (sourceAI->CastSpell(me, "Prowl", MELEE_MAX_DISTANCE, true))
				{
					return true;
				}
			}
		}
		else
		{
			if (sourceAI->HasAura(me, "Prowl"))
			{
				sourceAI->BaseMove(pmTarget, MELEE_MAX_DISTANCE, true, false);
				if (energy > 50)
				{
					if (sourceAI->CastSpell(pmTarget, "Pounce", MELEE_MAX_DISTANCE))
					{
						return true;
					}
				}
			}
			else
			{
				sourceAI->BaseMove(pmTarget);
				if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
				{
					return true;
				}
				if (energy > 20)
				{
					if (sourceAI->CastSpell(me, "Tiger's Fury", MELEE_MAX_DISTANCE, true))
					{
						return true;
					}
				}
				if (energy > 35)
				{
					uint32 spellID = sourceAI->FindSpellID("Rip");
					if (spellID != 0)
					{
						uint8 comboPoints = me->GetComboPoints();
						if (sourceAI->HasAura(pmTarget, "Rip", true))
						{
							if (urand(1, 5) <= comboPoints)
							{
								sourceAI->CastSpell(pmTarget, "Ferocious Bite", MELEE_MAX_DISTANCE);
								return true;
							}
						}
						else
						{
							if (urand(1, 5) <= comboPoints)
							{
								sourceAI->CastSpell(pmTarget, "Rip", MELEE_MAX_DISTANCE);
								return true;
							}
						}
					}
				}
				if (energy > 45)
				{
					if (sourceAI->CastSpell(pmTarget, "Rake", MELEE_MAX_DISTANCE, true, true))
					{
						return true;
					}
					if (sourceAI->CastSpell(pmTarget, "Claw", MELEE_MAX_DISTANCE))
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
		if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
		{
			return true;
		}
		if (targetDistance < DRUID_PREPARE_DISTANCE)
		{
			if (energy > 20)
			{
				if (sourceAI->CastSpell(me, "Tiger's Fury", MELEE_MAX_DISTANCE, true))
				{
					return true;
				}
			}
		}
		if (energy > 35)
		{
			uint32 spellID = sourceAI->FindSpellID("Rip");
			if (spellID != 0)
			{
				uint8 comboPoints = me->GetComboPoints();
				if (sourceAI->HasAura(pmTarget, "Rip", true))
				{
					if (urand(1, 5) <= comboPoints)
					{
						sourceAI->CastSpell(pmTarget, "Ferocious Bite", MELEE_MAX_DISTANCE);
						return true;
					}
				}
				else
				{
					if (urand(1, 5) <= comboPoints)
					{
						sourceAI->CastSpell(pmTarget, "Rip", MELEE_MAX_DISTANCE);
						return true;
					}
				}
			}
		}
		if (energy > 45)
		{
			if (sourceAI->CastSpell(pmTarget, "Rake", MELEE_MAX_DISTANCE, true, true))
			{
				return true;
			}
			if (sourceAI->CastSpell(pmTarget, "Claw", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
	}

	return true;
}

bool Script_Druid::Attack_Feral_Bear(Unit* pmTarget)
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
	else if (!pmTarget->isAlive())
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}

	sourceAI->BaseMove(pmTarget);
	if (sourceAI->CastSpell(me, "Enrage"))
	{
		return true;
	}
	uint32 rage = me->GetPower(Powers::POWER_RAGE);
	if (rage > 50)
	{
		if (sourceAI->CastSpell(pmTarget, "Feral Charge - Bear", DRUID_RANGE_DISTANCE))
		{
			return true;
		}
	}
	if (rage > 500)
	{
		if (me->GetHealthPercent() < 60)
		{
			if (sourceAI->CastSpell(me, "Frenzied Regeneration"))
			{
				return true;
			}
		}
	}
	if (sourceAI->CastSpell(pmTarget, "Faerie Fire (Feral)", DRUID_RANGE_DISTANCE, true))
	{
		return true;
	}
	if (rage > 100)
	{
		if (sourceAI->CastSpell(pmTarget, "Demoralizing Roar", MELEE_MAX_DISTANCE, true))
		{
			return true;
		}
		if (pmTarget->IsNonMeleeSpellCasted(false))
		{
			if (sourceAI->CastSpell(pmTarget, "Bash", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
	}
	uint16 validAttackerCount = 0;
	for (Unit::AttackerSet::const_iterator itr = me->getAttackers().begin(); itr != me->getAttackers().end(); ++itr)
	{
		float distance = me->GetDistance((*itr));
		if (distance <= 5)
		{
			validAttackerCount++;
		}
	}
	if (validAttackerCount > 1)
	{
		if (rage > 200)
		{
			if (sourceAI->CastSpell(pmTarget, "Swipe", MELEE_MAX_DISTANCE))
			{
				return true;
			}
		}
	}
	if (rage > 200)
	{
		if (sourceAI->CastSpell(pmTarget, "Maul", MELEE_MAX_DISTANCE))
		{
			return true;
		}
	}

	return true;
}

bool Script_Druid::Attack_Restoration(Unit* pmTarget)
{
	return Attack_Balance(pmTarget);
}

bool Script_Druid::Healer(Unit* pmTarget)
{
	if (!pmTarget)
	{
		return false;
	}
	if (!pmTarget->isAlive())
	{
		return false;
	}
	Player* me = sourceAI->sourcePlayer;
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}
	if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
	{
		if (sourceAI->CastSpell(me, "Innervate", DRUID_RANGE_DISTANCE, false, false, true))
		{
			return true;
		}
	}
	sourceAI->BaseMove(pmTarget, DRUID_CLOSER_DISTANCE, false);
	if (pmTarget->getAttackers().size() > 3)
	{
		if (sourceAI->CastSpell(me, "Tranquility"))
		{
			return true;
		}
	}
	float healthPCT = pmTarget->GetHealthPercent();
	if (healthPCT < 90)
	{
		if (!sourceAI->HasAura(pmTarget, "Rejuvenation", false))
		{
			if (sourceAI->CastSpell(pmTarget, "Rejuvenation", DRUID_RANGE_DISTANCE, true, false, true))
			{
				return true;
			}
		}
	}
	if (healthPCT < 70)
	{
		if (sourceAI->CastSpell(pmTarget, "Regrowth", DRUID_RANGE_DISTANCE, true, true, true))
		{
			return true;
		}
	}
	if (healthPCT < 60)
	{
		if (sourceAI->CastSpell(pmTarget, "Healing Touch", DRUID_RANGE_DISTANCE, false, false, true))
		{
			return true;
		}
	}

	for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
	{
		std::list<Aura*> auraList = pmTarget->GetAurasByType((AuraType)type);
		for (std::list<Aura*>::const_iterator auraIT = auraList.begin(); auraIT != auraList.end(); auraIT++)
		{
			const SpellEntry* pSE = (*auraIT)->GetSpellProto();
			if (!IsPositiveSpell(pSE))
			{
				if (pSE->Dispel == DispelType::DISPEL_POISON)
				{
					if (sourceAI->CastSpell(pmTarget, "Cure Poison"))
					{
						return true;
					}
				}
				else if (pSE->Dispel == DispelType::DISPEL_CURSE)
				{
					if (sourceAI->CastSpell(pmTarget, "Remove Curse"))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Script_Druid::HealMe()
{
	Player* me = sourceAI->sourcePlayer;
	float healthPCT = me->GetHealthPercent();
	if (healthPCT < 20)
	{
		if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 20)
		{
			if (sourceAI->CastSpell(me, "Innervate", DRUID_RANGE_DISTANCE, false, false, true))
			{
				return true;
			}
		}
		sourceAI->CastSpell(me, "Barkskin");
		if (sourceAI->CastSpell(me, "Healing Touch"))
		{
			return true;
		}
	}

	for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
	{
		std::list<Aura*> auraList = me->GetAurasByType((AuraType)type);
		for (std::list<Aura*>::const_iterator auraIT = auraList.begin(); auraIT != auraList.end(); auraIT++)
		{
			const SpellEntry* pSE = (*auraIT)->GetSpellProto();
			if (!IsPositiveSpell(pSE))
			{
				if (pSE->Dispel == DispelType::DISPEL_POISON)
				{
					if (sourceAI->CastSpell(me, "Cure Poison"))
					{
						return true;
					}
				}
				else if (pSE->Dispel == DispelType::DISPEL_CURSE)
				{
					if (sourceAI->CastSpell(me, "Remove Curse"))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Script_Druid::Buff(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
	if (!pmTarget)
	{
		return false;
	}
	float targetDistance = me->GetDistance(pmTarget);
	if (targetDistance > 200)
	{
		return false;
	}
	if (!pmTarget->isAlive())
	{
		return false;
	}
	else
	{
		if (!sourceAI->HasAura(pmTarget, "Mark of the Wild", false))
		{
			if (sourceAI->CastSpell(pmTarget, "Mark of the Wild", DRUID_RANGE_DISTANCE, true, false, true))
			{
				return true;
			}
		}
		if (!sourceAI->HasAura(pmTarget, "Thorns", false))
		{
			if (sourceAI->CastSpell(pmTarget, "Thorns", DRUID_RANGE_DISTANCE, true, false, true))
			{
				return true;
			}
		}
	}

	return false;
}
