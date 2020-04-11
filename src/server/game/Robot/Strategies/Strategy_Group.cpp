#include "Strategy_Group.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "Group.h"
#include "MotionMaster.h"
#include "FollowMovementGenerator.h"
#include "ChaseMovementGenerator.h"
#include "GridNotifiers.h"
#include "Map.h"

Strategy_Group::Strategy_Group(Player* pmMe)
{
    me = pmMe;
    combatTime = 0;
    sideDelay = 0;
    moveAssembleDelay = 0;
    teleportAssembleDelay = 0;
    restDelay = 0;
    aoeDelay = DEFAULT_AOE_DELAY;
    dpsDelay = DEFAULT_DPS_DELAY;
    staying = false;
    holding = false;
    cure = true;
    followDistance = FOLLOW_NORMAL_DISTANCE;
    if (me)
    {
        switch (me->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            sb = new Script_Warrior(me);
            followDistance = MELEE_MIN_DISTANCE;
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            sb = new  Script_Hunter(me);
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            sb = new  Script_Shaman(me);
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            sb = new  Script_Paladin(me);
            followDistance = MELEE_MIN_DISTANCE;
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            sb = new  Script_Warlock(me);
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            sb = new  Script_Priest(me);
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            sb = new  Script_Rogue(me);
            followDistance = MELEE_MIN_DISTANCE;
            break;
        }
        case Classes::CLASS_MAGE:
        {
            sb = new  Script_Mage(me);
            break;
        }
        case Classes::CLASS_DRUID:
        {
            sb = new  Script_Druid(me);
            break;
        }
        default:
        {
            sb = new  Script_Base(me);
            break;
        }
        }
    }
}

void Strategy_Group::Update(uint32 pmDiff)
{
    if (!me)
    {
        return;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Player* leaderPlayer = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            if (WorldSession* leaderWS = leaderPlayer->GetSession())
            {
                if (leaderWS->isRobotSession)
                {
                    me->RemoveFromGroup();
                    return;
                }
            }
        }
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (teleportAssembleDelay > 0)
        {
            teleportAssembleDelay -= pmDiff;
            if (teleportAssembleDelay < 0)
            {
                if (Player* leaderPlayer = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
                {
                    if (!me->IsAlive())
                    {
                        me->ResurrectPlayer(0.2f);
                    }
                    me->TeleportTo(leaderPlayer->GetWorldLocation());
                    me->ClearInCombat();
                    sb->WhisperTo("I have come", Language::LANG_UNIVERSAL, leaderPlayer);
                }
            }
        }
        if (moveAssembleDelay > 0)
        {
            moveAssembleDelay -= pmDiff;
            return;
        }
        if (staying)
        {
            return;
        }
        if (!me->IsAlive())
        {
            return;
        }
        if (sideDelay > 0)
        {
            sideDelay -= pmDiff;
            return;
        }
        if (GroupInCombat())
        {
            restDelay = 0;
            combatTime += pmDiff;
            switch (me->groupRole)
            {
            case GroupRole::GroupRole_DPS:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole::GroupRole_Healer:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole::GroupRole_Tank:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            if (restDelay > 0)
            {
                restDelay -= pmDiff;
                return;
            }
            combatTime = 0;
            switch (me->groupRole)
            {
            case GroupRole::GroupRole_DPS:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole::GroupRole_Healer:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole::GroupRole_Tank:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        Follow();
    }
}

bool Strategy_Group::GroupInCombat()
{
    if (!me)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsInCombat())
                {
                    if (member->GetDistance(me) < ATTACK_RANGE_LIMIT)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Strategy_Group::DPS()
{
    if (!me)
    {
        return false;
    }
    if (combatTime > dpsDelay)
    {
        if (Group* myGroup = me->GetGroup())
        {
            bool aoe = combatTime > aoeDelay;
            Unit* closestVictim = NULL;
            float closestDistance = ATTACK_RANGE_LIMIT;
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->groupRole == GroupRole::GroupRole_Tank)
                    {
                        if (sb->DPS(member->GetSelectedUnit(), !holding, aoe))
                        {
                            return true;
                        }
                    }
                    for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                    {
                        float eachAttackerDistance = me->GetDistance((*attackerIT));
                        if (eachAttackerDistance < closestDistance)
                        {
                            closestVictim = *attackerIT;
                            closestDistance = eachAttackerDistance;
                        }
                    }
                }
            }
            if (sb->DPS(me->GetSelectedUnit(), !holding, aoe))
            {
                return true;
            }
            else if (sb->DPS(closestVictim, !holding, aoe))
            {
                return true;
            }
        }
    }

    return false;
}

bool Strategy_Group::Tank()
{
    if (!me)
    {
        return false;
    }
    if (Unit* myVictim = me->GetVictim())
    {
        if (Unit* victimVictim = myVictim->GetVictim())
        {
            if (victimVictim->GetGUID() != me->GetGUID())
            {
                if (sb->Tank(myVictim))
                {
                    return true;
                }
            }
        }
    }
    if (Group* myGroup = me->GetGroup())
    {
        Unit* closestVictim = NULL;
        float closestDistance = ATTACK_RANGE_LIMIT;
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                {
                    // tank can only cover 30.0f range
                    if (me->GetDistance((*attackerIT)) < RANGED_MAX_DISTANCE)
                    {
                        if (Unit* attackerVictim = (*attackerIT)->GetVictim())
                        {
                            if (attackerVictim->GetGUID() != me->GetGUID())
                            {
                                if (sb->Tank((*attackerIT)))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                    float eachAttackerDistance = me->GetDistance((*attackerIT));
                    if (eachAttackerDistance < closestDistance)
                    {
                        closestVictim = *attackerIT;
                        closestDistance = eachAttackerDistance;
                    }
                }
            }
        }
        if (sb->Tank(me->GetSelectedUnit()))
        {
            return true;
        }
        else if (sb->Tank(closestVictim))
        {
            return true;
        }
    }

    return false;
}

bool Strategy_Group::Rest()
{
    if (!me)
    {
        return false;
    }
    bool canTry = false;
    if (me->GetHealthPct() < 40.0f)
    {
        canTry = true;
    }
    if (me->GetPowerType() == Powers::POWER_MANA)
    {
        if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) < 40.0f)
        {
            canTry = true;
        }
    }
    if (canTry)
    {
        if (sb->Rest())
        {
            restDelay = DEFAULT_REST_DELAY;
            return true;
        }
    }

    return false;
}

bool Strategy_Group::Heal()
{
    if (!me)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        bool aoe = combatTime > aoeDelay;
        Unit* closestVictim = NULL;
        float closestDistance = ATTACK_RANGE_LIMIT;
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->groupRole == GroupRole::GroupRole_Tank)
                {
                    if (member->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(member, cure))
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    if (member->GetHealthPct() < 50.0f)
                    {
                        if (sb->Heal(member, cure))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool Strategy_Group::Buff()
{
    if (!me)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (sb->Buff(member, cure))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Strategy_Group::Follow()
{
    if (!me)
    {
        return false;
    }
    if (holding)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            if (me->GetDistance(leader) > ATTACK_RANGE_LIMIT)
            {
                me->StopMoving();
                me->GetMotionMaster()->Clear();
                return false;
            }
            return sb->Follow(leader, followDistance);
        }
    }
    return false;
}

bool Strategy_Group_Shadow_Labyrinth::DPS()
{
    if (!me)
    {
        return false;
    }
    if (combatTime > dpsDelay)
    {
        // void traveler first
        if (!ogVT.IsEmpty())
        {
            if (Unit* vt = me->GetMap()->GetCreature(ogVT))
            {
                if (sb->DPS(vt, true, false))
                {
                    return true;
                }
            }
            ogVT.Clear();
        }
        //if (Unit* currentTarget = me->GetSelectedUnit())
        //{
        //    if (currentTarget->GetEntry() == SHADOW_LABYRINTH_NPC::SHADOW_LABYRINTH_NPC_VOID_TRAVELER)
        //    {
        //        if (sb->DPS(currentTarget, true, false))
        //        {
        //            return true;
        //        }
        //    }
        //}
        //std::list<Unit*> attackTargets;
        //Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, DEFAULT_VISIBILITY_DISTANCE);
        //Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, attackTargets, u_check);
        //Cell::VisitAllObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);
        //Unit* nearestAttackableTarget = NULL;
        //float nearestDistance = MAX_VISIBILITY_DISTANCE;
        //for (std::list<Unit*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
        //{
        //    if ((*it)->GetEntry() == SHADOW_LABYRINTH_NPC::SHADOW_LABYRINTH_NPC_VOID_TRAVELER)
        //    {
        //        if (sb->DPS((*it), true, false))
        //        {
        //            return true;
        //        }
        //    }
        //}
        if (Group* myGroup = me->GetGroup())
        {
            bool aoe = combatTime > aoeDelay;
            Unit* closestVictim = NULL;
            float closestDistance = ATTACK_RANGE_LIMIT;
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->groupRole == GroupRole::GroupRole_Tank)
                    {
                        if (sb->DPS(member->GetSelectedUnit(), !holding, aoe))
                        {
                            return true;
                        }
                    }
                    for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                    {
                        float eachAttackerDistance = me->GetDistance((*attackerIT));
                        if (eachAttackerDistance < closestDistance)
                        {
                            closestVictim = *attackerIT;
                            closestDistance = eachAttackerDistance;
                        }
                    }
                }
            }
            if (sb->DPS(me->GetSelectedUnit(), !holding, aoe))
            {
                return true;
            }
            else if (sb->DPS(closestVictim, !holding, aoe))
            {
                return true;
            }
        }
    }

    return false;
}
