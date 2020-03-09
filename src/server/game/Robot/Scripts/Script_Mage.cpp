#include "Script_Mage.h"
#include "Group.h"
#include "RobotManager.h"

Script_Mage::Script_Mage(uint32 pmCharacterID) :Script_Base()
{
    character = pmCharacterID;
}

bool Script_Mage::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Mage::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Mage::DPS(Unit* pmTarget)
{
    switch (characterTalentTab)
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Arcane Missiles", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Fire(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Fireball", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Frost(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        if (myGroup->isRaidGroup())
        {
            if (sRobotManager->raidStrategyMap.find(myGroup->GetLowGUID()) != sRobotManager->raidStrategyMap.end())
            {
                for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = sRobotManager->raidStrategyMap[myGroup->GetLowGUID()]->memberMap.begin(); pmIT != sRobotManager->raidStrategyMap[myGroup->GetLowGUID()]->memberMap.end(); pmIT++)
                {
                    if (pmIT->second->raidRole == RaidRole::RaidRole_Tank)
                    {
                        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
                        if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
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
                                            if (CastSpell((*i), "Blizzard", MAGE_RANGE_DISTANCE))
                                            {
                                                return true;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            if (sRobotManager->partyStrategyMap.find(myGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
            {
                for (std::unordered_map<uint32, PartyMember*>::iterator pmIT = sRobotManager->partyStrategyMap[myGroup->GetLowGUID()]->memberMap.begin(); pmIT != sRobotManager->partyStrategyMap[myGroup->GetLowGUID()]->memberMap.end(); pmIT++)
                {
                    if (pmIT->second->partyRole == PartyRole::PartyRole_Tank)
                    {
                        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
                        if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
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
                                            if (CastSpell((*i), "Blizzard", MAGE_RANGE_DISTANCE))
                                            {
                                                return true;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    if (CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::DPS_Common(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack(Unit* pmTarget)
{
    switch (characterTalentTab)
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Arcane Missiles", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Fire(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Fireball", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Frost(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }

    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (CastSpell(me, "Evocation", MAGE_RANGE_DISTANCE))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Attack_Common(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    Chase(pmTarget, false, MAGE_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", MAGE_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Frostbolt", MAGE_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Mage::Buff(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    if (me->GetDistance(pmTarget) < MAGE_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Arcane Intellect", MAGE_RANGE_DISTANCE, true))
        {
            return true;
        }
    }

    return false;
}
