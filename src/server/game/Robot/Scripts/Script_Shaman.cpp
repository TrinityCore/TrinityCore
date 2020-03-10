#include "Script_Shaman.h"

Script_Shaman::Script_Shaman(uint32 pmCharacterID) :Script_Base()
{
    character = pmCharacterID;
}

bool Script_Shaman::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Shaman::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Shaman::DPS(Unit* pmTarget, bool pmChase)
{
    return DPS_Common(pmTarget, pmChase);
}

bool Script_Shaman::DPS_Common(Unit* pmTarget, bool pmChase)
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
    if (pmChase)
    {
        Chase(pmTarget, SHAMAN_RANGE_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if (CastSpell(pmTarget, "Lightning Bolt", SHAMAN_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Shaman::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Shaman::Attack_Common(Unit* pmTarget)
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
    Chase(pmTarget, SHAMAN_RANGE_DISTANCE);
    if (CastSpell(pmTarget, "Lightning Bolt", SHAMAN_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Shaman::Buff(Unit* pmTarget, bool pmCure)
{
    return false;
}
