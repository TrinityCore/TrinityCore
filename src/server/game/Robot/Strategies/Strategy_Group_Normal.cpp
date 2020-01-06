#include "Strategy_Group_Normal.h"

Strategy_Group_Normal::Strategy_Group_Normal(RobotAI* pmSourceAI)
{
	sourceAI = pmSourceAI;
	staying = false;
	memberNumber = 0;

	instruction = Group_Instruction::Group_Instruction_None;

	assembleDelay = 0;
	restDelay = 0;
}

void Strategy_Group_Normal::Update(uint32 pmDiff)
{
	Player* me = sourceAI->sourcePlayer;
	Player* master = sourceAI->masterPlayer;
	if (!me->IsInGroup(master))
	{
		me->RemoveFromGroup();
		sourceAI->ResetStrategy();
		return;
	}
	if (restDelay > 0)
	{
		restDelay -= pmDiff;
		if (restDelay == 0)
		{
			restDelay = -1;
		}
	}
	if (assembleDelay > 0)
	{
		assembleDelay -= pmDiff;
		if (assembleDelay == 0)
		{
			assembleDelay = -1;
		}
		if (assembleDelay < 0)
		{
			if (master) {
				sourceAI->WhisperTo("I have come", Language::LANG_UNIVERSAL, master);
				if (!me->isAlive())
				{
					me->ResurrectPlayer(0.1f);
				}
				instruction = Group_Instruction::Group_Instruction_Wander;
				me->ClearInCombat();
				me->getThreatManager().clearReferences();
				me->GetMotionMaster()->Clear();
				me->StopMoving();
				me->TeleportTo(master->GetMapId(), master->GetPositionX(), master->GetPositionY(), master->GetPositionZ(), master->GetOrientation());
			}
			assembleDelay = 0;
			return;
		}
	}
	if (me->IsBeingTeleported())
	{
		return;
	}
	if (!me->isAlive())
	{
		restDelay = 0;
		return;
	}
	Group* myGroup = me->GetGroup();
	if (!master)
	{
		sourceAI->ResetStrategy();
		me->Say("I do not have a master. I will reset my strategy", Language::LANG_UNIVERSAL);
		return;
	}
	if (!myGroup)
	{
		sourceAI->ResetStrategy();
		sourceAI->masterPlayer = NULL;
		me->Say("I am not in a group. I will reset my strategy", Language::LANG_UNIVERSAL);
		return;
	}
	if (staying)
	{
		return;
	}
	if (me->IsNonMeleeSpellCasted(false, false, true))
	{
		return;
	}
	if (GroupInCombat())
	{
		restDelay = 0;
		forceResting = false;
		eating = false;
		drinking = false;
		instruction = Group_Instruction::Group_Instruction_Battle;
	}
	switch (instruction)
	{
	case Group_Instruction::Group_Instruction_None:
	{
		instruction = Group_Instruction::Group_Instruction_Wander;
		break;
	}
	case Group_Instruction::Group_Instruction_Wander:
	{
		if (Rest())
		{
			return;
		}
		if (Buff())
		{
			return;
		}
		if (Follow())
		{
			return;
		}
		break;
	}
	case Group_Instruction::Group_Instruction_Battle:
	{
		if (Rest())
		{			
			return;
		}
		if (Battle())
		{
			return;
		}
		instruction = Group_Instruction::Group_Instruction_Wander;
		break;
	}
	case Group_Instruction::Group_Instruction_Rest:
	{
		if (restDelay <= 0)
		{
			restDelay = 0;
			forceResting = false;
			eating = false;
			drinking = false;
			instruction = Group_Instruction::Group_Instruction_Wander;
			return;
		}
		else
		{
			// check again
			if (restDelay < 28)
			{
				if (!eating)
				{
					Eat();
				}
				if (!drinking)
				{
					Drink();
				}
			}
		}
	}
	default:
	{
		break;
	}
	}
}

bool Strategy_Group_Normal::Rest(bool pmForce)
{
	if (pmForce)
	{
		forceResting = true;
	}
	bool result = Eat();
	if (!result)
	{
		result = Drink();
	}
	return result;
}

bool Strategy_Group_Normal::Eat(bool pmForce)
{
	Player* me = sourceAI->sourcePlayer;
	if (GroupInCombat())
	{
		return false;
	}
	else
	{
		if (pmForce)
		{
			forceResting = true;
		}
		if (!forceResting)
		{
			float hpRate = me->GetHealthPercent();
			if (hpRate > 30)
			{
				return false;
			}
		}
		uint32 foodEntry = 0;
		Player* me = sourceAI->sourcePlayer;
		if (me->getLevel() >= 55)
		{
			foodEntry = 21023;
		}
		else if (me->getLevel() >= 45)
		{
			foodEntry = 8932;
		}
		else if (me->getLevel() >= 35)
		{
			foodEntry = 3927;
		}
		else if (me->getLevel() >= 25)
		{
			foodEntry = 1707;
		}
		else if (me->getLevel() >= 15)
		{
			foodEntry = 422;
		}
		else
		{
			return false;
		}

		if (!me->HasItemCount(foodEntry, 1))
		{
			me->StoreNewItemInBestSlots(foodEntry, 20);
		}

		me->CombatStop(true);
		me->GetMotionMaster()->Clear();
		me->StopMoving();
		me->SetSelectionGuid(ObjectGuid());

		sourceAI->ClearShapeshift();
		Item* pFood = sourceAI->GetItemInInventory(foodEntry);
		if (pFood && !pFood->IsInTrade())
		{
			if (sourceAI->UseItem(pFood, me))
			{
				instruction = Group_Instruction::Group_Instruction_Rest;
				restDelay = 30;
				eating = true;
				return true;
			}
		}
	}

	return false;
}

bool Strategy_Group_Normal::Drink(bool pmForce)
{
	Player* me = sourceAI->sourcePlayer;
	if (GroupInCombat())
	{
		return false;
	}
	else
	{
		if (pmForce)
		{
			forceResting = true;
		}
		if (!forceResting)
		{
			float mpRate = 100;
			if (me->GetPowerType() == Powers::POWER_MANA)
			{
				mpRate = me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA);
			}
			if (mpRate > 30)
			{
				return false;
			}
		}
		uint32 drinkEntry = 0;
		Player* me = sourceAI->sourcePlayer;
		if (me->getLevel() >= 55)
		{
			drinkEntry = 18300;
		}
		else if (me->getLevel() >= 45)
		{
			drinkEntry = 8766;
		}
		else if (me->getLevel() >= 35)
		{
			drinkEntry = 1645;
		}
		else if (me->getLevel() >= 25)
		{
			drinkEntry = 1708;
		}
		else if (me->getLevel() >= 15)
		{
			drinkEntry = 1205;
		}
		else
		{
			return false;
		}

		if (!me->HasItemCount(drinkEntry, 1))
		{
			me->StoreNewItemInBestSlots(drinkEntry, 20);
		}

		me->CombatStop(true);
		me->GetMotionMaster()->Clear();
		me->StopMoving();
		me->SetSelectionGuid(ObjectGuid());

		sourceAI->ClearShapeshift();
		Item* pDrink = sourceAI->GetItemInInventory(drinkEntry);
		if (pDrink && !pDrink->IsInTrade())
		{
			if (sourceAI->UseItem(pDrink, me))
			{
				instruction = Group_Instruction::Group_Instruction_Rest;
				restDelay = 30;
				drinking = true;
				return true;
			}
		}
	}

	return false;
}

bool Strategy_Group_Normal::Buff()
{
	Player* me = sourceAI->sourcePlayer;
	Group* myGroup = me->GetGroup();
	for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
	{
		Player* member = groupRef->getSource();
		if (Buff(member))
		{
			return true;
		}
	}
	return false;
}

bool Strategy_Group_Normal::Buff(Player* pmTarget)
{
	return sourceAI->s_base->Buff(pmTarget);
}

bool Strategy_Group_Normal::Battle()
{
	bool result = false;
	Player* me = sourceAI->sourcePlayer;
	switch (me->groupRole)
	{
	case 0:
	{
		result = DPS();
		break;
	}
	case 1:
	{
		result = Tank();
		break;
	}
	case 2:
	{
		result = Healer();
		break;
	}
	default:
	{
		break;
	}
	}
	if (result)
	{
		instruction = Group_Instruction::Group_Instruction_Battle;
	}
	else
	{
		me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
	}

	return result;
}

bool Strategy_Group_Normal::DPS()
{
	bool result = false;
	Player* me = sourceAI->sourcePlayer;
	if (!result)
	{
		if (GroupInCombat())
		{
			Group* myGroup = me->GetGroup();
			for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
			{
				Player* member = groupRef->getSource();
				if (member->groupRole == 1)
				{
					Unit* tankTarget = member->GetTarget();
					if (DPS(tankTarget))
					{
						result = true;
						break;
					}
				}
			}
		}
	}

	if (!result)
	{
		if (sourceAI->masterPlayer)
		{
			Unit* masterTarget = sourceAI->masterPlayer->GetTarget();
			if (DPS(masterTarget))
			{
				result = true;
			}
		}
	}

	if (!result)
	{
		Unit* myTarget = me->GetTarget();
		if (DPS(myTarget))
		{
			result = true;
		}
	}

	if (!result)
	{
		Unit* closestAttacker = NULL;
		float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
		Group* myGroup = me->GetGroup();
		for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
		{
			Player* member = groupRef->getSource();
			if (Unit* memberAttacker = member->getAttackerForHelper())
			{
				float distance = me->GetDistance(memberAttacker);
				if (distance < closestDistance)
				{
					closestDistance = distance;
					closestAttacker = memberAttacker;
				}
			}
		}

		if (DPS(closestAttacker))
		{
			result = true;
		}
	}

	if (!result)
	{
		Unit* closestAttacker = NULL;
		float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
		Group* myGroup = me->GetGroup();
		for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
		{
			Player* member = groupRef->getSource();
			Pet* memberPet = member->GetPet();
			if (memberPet)
			{
				if (Unit* memberPetAttacker = memberPet->getAttackerForHelper())
				{
					float distance = me->GetDistance(memberPetAttacker);
					if (distance < closestDistance)
					{
						closestDistance = distance;
						closestAttacker = memberPetAttacker;
					}
				}
			}
		}

		if (DPS(closestAttacker))
		{
			result = true;
		}
	}

	return result;
}

bool Strategy_Group_Normal::DPS(Unit* pmTarget)
{
	return sourceAI->s_base->DPS(pmTarget);
}

bool Strategy_Group_Normal::Tank()
{
	bool result = false;
	Player* me = sourceAI->sourcePlayer;
	Group* myGroup = me->GetGroup();
	// tank OT target first
	for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
	{
		Player* member = groupRef->getSource();
		if (member->getAttackers().size() > 0)
		{
			for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); attackerIT++)
			{
				Unit* pTarget = *attackerIT;
				if (!pTarget)
				{
					continue;
				}
				float distance = me->GetDistance(pTarget);
				if (distance < DEFAULT_VISIBILITY_DISTANCE)
				{
					if (pTarget->GetSelectionGuid() != me->GetObjectGuid())
					{
						if (Tank(pTarget))
						{
							result = true;
							break;
						}
					}
				}
			}
			if (result)
			{
				break;
			}
		}
	}

	if (!result)
	{
		if (sourceAI->masterPlayer)
		{
			Unit* masterTarget = sourceAI->masterPlayer->GetTarget();
			if (Tank(masterTarget))
			{
				result = true;
			}
		}
	}

	if (!result)
	{
		Unit* myTarget = me->GetTarget();
		if (Tank(myTarget))
		{
			result = true;
		}
	}

	if (!result)
	{
		Unit* closestAttacker = NULL;
		float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
		Group* myGroup = me->GetGroup();
		for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
		{
			Player* member = groupRef->getSource();
			if (Unit* memberAttacker = member->getAttackerForHelper())
			{
				float distance = me->GetDistance(memberAttacker);
				if (distance < closestDistance)
				{
					closestDistance = distance;
					closestAttacker = memberAttacker;
				}
			}
		}

		if (Tank(closestAttacker))
		{
			result = true;
		}
	}

	if (!result)
	{
		Unit* closestAttacker = NULL;
		float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
		Group* myGroup = me->GetGroup();
		for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
		{
			Player* member = groupRef->getSource();
			Pet* memberPet = member->GetPet();
			if (memberPet)
			{
				if (Unit* memberPetAttacker = memberPet->getAttackerForHelper())
				{
					float distance = me->GetDistance(memberPetAttacker);
					if (distance < closestDistance)
					{
						closestDistance = distance;
						closestAttacker = memberPetAttacker;
					}
				}
			}
		}

		if (Tank(closestAttacker))
		{
			result = true;
		}
	}

	return result;
}

bool Strategy_Group_Normal::Tank(Unit* pmTarget)
{
	return sourceAI->s_base->Tank(pmTarget);
}

bool Strategy_Group_Normal::Attack(Unit* pmTarget)
{
	Player* me = sourceAI->sourcePlayer;
	switch (me->groupRole)
	{
	case 0:
	{
		return DPS(pmTarget);
	}
	case 1:
	{
		return Tank(pmTarget);
	}
	default:
	{
		break;
	}
	}

	return false;
}

bool Strategy_Group_Normal::Healer()
{
	bool result = false;
	Player* me = sourceAI->sourcePlayer;
	//Player* master = sourceAI->masterPlayer;
	Group* myGroup = me->GetGroup();
	Player* tank = NULL;
	Player* lowestMember = NULL;
	float lowestPCT = 50;
	if (!result)
	{
		for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
		{
			Player* member = groupRef->getSource();
			if (!member->isAlive())
			{
				continue;
			}
			if (member->groupRole == 1)
			{
				tank = member;
			}
			else
			{
				float eachPCT = member->GetHealthPercent();
				if (eachPCT < lowestPCT)
				{
					lowestPCT = eachPCT;
					lowestMember = member;
				}
			}
		}
	}
	if (!result)
	{
		if (tank)
		{
			if (tank->GetHealthPercent() < 80)
			{
				if (Healer(tank))
				{
					result = true;
				}
			}
		}
	}
	if (!result)
	{
		if (lowestMember)
		{
			if (Healer(lowestMember))
			{
				result = true;
			}
		}
	}

	if (GroupInCombat())
	{
		result = true;
	}

	return result;
}

bool Strategy_Group_Normal::Healer(Unit* pmTarget)
{
	return sourceAI->s_base->Healer(pmTarget);
}

bool Strategy_Group_Normal::GroupInCombat()
{
	Player* me = sourceAI->sourcePlayer;
	Group* myGroup = me->GetGroup();
	for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
	{
		Player* member = groupRef->getSource();
		if (me->GetDistance(member) < 100)
		{
			if (member->isAlive())
			{
				if (member->isInCombat())
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Strategy_Group_Normal::Follow()
{
	Player* me = sourceAI->sourcePlayer;
	if (!me->isAlive())
	{
		return false;
	}
	if (!sourceAI->masterPlayer)
	{
		return false;
	}
	Player* tank = NULL;
	Group* myGroup = me->GetGroup();
	for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
	{
		Player* member = groupRef->getSource();
		if (member->groupRole == 1)
		{
			tank = member;
			break;
		}
	}
	bool followTank = false;
	float followDistance = MELEE_COMBAT_DISTANCE;
	float targetDistance = 0;
	if (me->groupRole == 0 || me->groupRole == 2)
	{
		if (tank)
		{
			if (me->GetMapId() == tank->GetMapId())
			{
				float tankDistance = me->GetDistance(tank);
				if (tankDistance < 200)
				{
					targetDistance = tankDistance;
					followTank = true;
				}
			}
		}
	}
	if (followTank)
	{
		uint8 myClass = me->getClass();
		if (myClass == Classes::CLASS_HUNTER || myClass == Classes::CLASS_MAGE || myClass == Classes::CLASS_PRIEST || myClass == Classes::CLASS_WARLOCK)
		{
			followDistance = 20;
		}
	}
	else
	{
		if (me->GetMapId() == sourceAI->masterPlayer->GetMapId())
		{
			targetDistance = me->GetDistance(sourceAI->masterPlayer);			
			if (targetDistance > 200)
			{
				return false;
			}
		}		
	}
	if (targetDistance > followDistance + MELEE_COMBAT_DISTANCE)
	{
		if (me->getStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
		{
			me->SetStandState(UNIT_STAND_STATE_STAND);
		}
		if (!me->hasUnitState(UnitState::UNIT_STAT_RUNNING))
		{
			me->addUnitState(UnitState::UNIT_STAT_RUNNING);
		}
		if (followTank)
		{
			if (me->GetMapId() == tank->GetMapId())
			{
				sourceAI->MoveCLose(tank, followDistance);
			}
		}
		else
		{
			if (me->GetMapId() == sourceAI->masterPlayer->GetMapId())
			{
				sourceAI->MoveCLose(sourceAI->masterPlayer, followDistance);
			}
		}
	}
	else if (targetDistance < followDistance)
	{
		if (me->IsMoving())
		{
			me->StopMoving();
			me->GetMotionMaster()->Clear();
		}
	}

	return true;
}

bool Strategy_Group_Normal::Stay()
{
	Player* me = sourceAI->sourcePlayer;
	me->StopMoving();
	me->GetMotionMaster()->Clear();
	return true;
}
