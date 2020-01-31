#include "Script_Warrior.h"

#ifndef WARRIOR_CHARGE_DISTANCE
# define WARRIOR_CHARGE_DISTANCE 10
#endif

#ifndef WARRIOR_RANGE_DISTANCE
# define WARRIOR_RANGE_DISTANCE 25
#endif

Script_Warrior::Script_Warrior(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Warrior::HealMe()
{
    return false;
}

bool Script_Warrior::Tank(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE && targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (sourceAI->CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }

    sourceAI->BaseMove(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (sourceAI->CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 500)
    {
        if (sourceAI->CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 150)
    {
        if (sourceAI->CastSpell(pmTarget, "Thunder Clap", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        if (sourceAI->CastSpell(pmTarget, "Sunder Armor", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }

    return true;
}

bool Script_Warrior::Healer(Unit* pmTarget)
{
    return false;
}

bool Script_Warrior::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Warrior::DPS_Common(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE && targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (sourceAI->CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }

    sourceAI->BaseMove(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (sourceAI->CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (sourceAI->CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (sourceAI->CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        sourceAI->CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
    }

    return true;
}

bool Script_Warrior::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Warrior::Attack_Common(Unit* pmTarget)
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
    else if (targetDistance > WARRIOR_CHARGE_DISTANCE && targetDistance < WARRIOR_RANGE_DISTANCE)
    {
        if (sourceAI->CastSpell(pmTarget, "Charge", WARRIOR_RANGE_DISTANCE))
        {
            return true;
        }
    }
    sourceAI->BaseMove(pmTarget);
    uint32 rage = me->GetPower(Powers::POWER_RAGE);
    if (rage > 100)
    {
        if (sourceAI->CastSpell(me, "Battle Shout", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
        //if (sourceAI->CastSpell(pmTarget, "Demoralizing Shout", MELEE_MAX_DISTANCE, true))
        //{
        //	return true;
        //}
        if (sourceAI->CastSpell(pmTarget, "Rend", MELEE_MAX_DISTANCE, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Hamstring", MELEE_MAX_DISTANCE, true))
        {
            return true;
        }
    }
    if (rage > 200)
    {
        sourceAI->CastSpell(pmTarget, "Heroic Strike", MELEE_MAX_DISTANCE);
    }

    return true;
}

bool Script_Warrior::Buff(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    switch (me->groupRole)
    {
        //case 1:
        //{
        //    if (sourceAI->CastSpell(me, "Defensive Stance", MELEE_MAX_DISTANCE, true))
        //    {
        //        return true;
        //    }
        //    break;
        //}    
    }

    if (sourceAI->CastSpell(me, "Battle Stance", MELEE_MAX_DISTANCE, true))
    {
        return true;
    }

    return false;
}
