#include "Script_Warrior.h"
#include "Group.h"
#include "RobotManager.h"

Script_Warrior::Script_Warrior(uint32 pmCharacterID) :Script_Base()
{
    character = pmCharacterID;
}

bool Script_Warrior::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Warrior::Tank(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE&& targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 500)
    {
        if (CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 150)
    {
        if (CastSpell(pmTarget, "Thunder Clap", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        if (CastSpell(pmTarget, "Sunder Armor", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Warrior::DPS(Unit* pmTarget, bool pmChase)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Arms(pmTarget, pmChase);
    }
    case 1:
    {
        return DPS_Fury(pmTarget, pmChase);
    }
    case 2:
    {
        return DPS_Common(pmTarget, pmChase);
    }
    default:
        return DPS_Common(pmTarget, pmChase);
    }
}

bool Script_Warrior::DPS_Arms(Unit* pmTarget, bool pmChase)
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
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 300)
    {
        Group* myGroup = me->GetGroup();
        if (myGroup)
        {
            if (myGroup->isRaidGroup())
            {
                // todo raid aoe
            }
            else
            {
                if (sRobotManager->partyStrategyMap.find(myGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
                {
                    for (std::unordered_map<uint32, PartyMember>::iterator pmIT = sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.begin(); pmIT != sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.end(); pmIT++)
                    {
                        if (pmIT->second.partyRole == PartyRole::PartyRole_Tank)
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
                                                if (CastSpell((*i), "Bladestorm", MELEE_MAX_DISTANCE))
                                                {
                                                    return true;
                                                }
                                                if (CastSpell((*i), "Sweeping Strikes", MELEE_MAX_DISTANCE))
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

        CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
        if (CastSpell(pmTarget, "Mortal Strike", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Overpower", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (pmTarget->GetHealthPct() < 30.0f)
        {
            if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
            {
                return true;
            }
        }
    }
    CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);

    return true;
}

bool Script_Warrior::DPS_Fury(Unit* pmTarget, bool pmChase)
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
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(me, "Recklessness", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (CastSpell(pmTarget, "Pummel", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        if (pmTarget->GetHealthPct() < 30.0f)
        {
            if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
            {
                return true;
            }
        }
    }
    if (rage > 250)
    {
        if (CastSpell(pmTarget, "Bloodthirst", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Whirlwind", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Cleave", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Warrior::DPS_Common(Unit* pmTarget, bool pmChase)
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
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
    }

    return true;
}

bool Script_Warrior::Attack(Unit* pmTarget)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return Attack_Arms(pmTarget);
    }
    case 1:
    {
        return Attack_Fury(pmTarget);
    }
    case 2:
    {
        return Attack_Protection(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Warrior::Attack_Arms(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE&& targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Overpower", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (pmTarget->GetHealthPct() < 30.0f)
        {
            if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
            {
                return true;
            }
        }
    }

    if (rage > 300)
    {
        if (CastSpell(pmTarget, "Mortal Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 150)
    {
        if (CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Warrior::Attack_Fury(Unit* pmTarget)
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
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (me->GetLevel() >= 20)
        {
            if (CastSpell(me, "Berserker Stance", MELEE_MAX_DISTANCE, true))
            {
                return true;
            }
        }
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(me, "Recklessness", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        if (pmTarget->IsNonMeleeSpellCast(false))
        {
            if (CastSpell(pmTarget, "Pummel", MELEE_MAX_DISTANCE))
            {
                return true;
            }
        }
        if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 250)
    {
        if (CastSpell(pmTarget, "Bloodthirst", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Whirlwind", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Cleave", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Warrior::Attack_Protection(Unit* pmTarget)
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
    else if (targetDistance < WARRIOR_CHARGE_DISTANCE)
    {
        if (CastSpell(me, "Bloodrage", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Revenge", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
    }

    return true;
}

bool Script_Warrior::Attack_Common(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE&& targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }
    me->Attack(pmTarget, true);
    Chase(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
    }

    return true;
}

bool Script_Warrior::Buff(Unit* pmTarget, bool pmCure)
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
    if (me->GetGUID() == pmTarget->GetGUID())
    {
        Group* myGroup = me->GetGroup();
        if (myGroup)
        {
            if (myGroup->isRaidGroup())
            {
                // todo raid buff
            }
            else
            {
                if (sRobotManager->partyStrategyMap.find(myGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
                {
                    if (sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.find(character) != sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.end())
                    {
                        switch (sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap[character].partyRole)
                        {
                        case PartyRole::PartyRole_Tank:
                        {
                            if (me->GetLevel() >= 10)
                            {
                                if (CastSpell(me, "Defensive Stance", MELEE_MAX_DISTANCE, true))
                                {
                                    return true;
                                }
                            }
                            else
                            {
                                if (CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
                                {
                                    return true;
                                }
                            }
                            break;
                        }
                        default:
                        {
                            switch (characterTalentTab)
                            {
                            case 0:
                            {
                                if (CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
                                {
                                    return true;
                                }
                                break;
                            }
                            case 1:
                            {
                                if (me->GetLevel() >= 20)
                                {
                                    if (CastSpell(me, "Berserker Stance", MELEE_MAX_DISTANCE, true))
                                    {
                                        return true;
                                    }
                                }
                                else
                                {
                                    if (CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
                                    {
                                        return true;
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                if (me->GetLevel() >= 10)
                                {
                                    if (CastSpell(me, "Defensive Stance", MELEE_MAX_DISTANCE, true))
                                    {
                                        return true;
                                    }
                                }
                                else
                                {
                                    if (CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
                                    {
                                        return true;
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                if (CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
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

    return false;
}
