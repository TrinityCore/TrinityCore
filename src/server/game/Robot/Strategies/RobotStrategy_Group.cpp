#include "RobotStrategy_Group.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "RobotConfig.h"
#include "RobotManager.h"
#include "Group.h"
#include "MotionMaster.h"
#include "FollowMovementGenerator.h"
#include "ChaseMovementGenerator.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "Pet.h"

void RobotStrategy_Group::Reset()
{
    engageDelay = 0;
    combatTime = 0;
    moveDelay = 0;
    teleportAssembleDelay = 0;
    restDelay = 0;
    readyCheckDelay = 0;
    staying = false;
    holding = false;
    following = true;
    cure = true;
    actionType = 0;
    actionDelay = 0;
}

void RobotStrategy_Group::InitialStrategy()
{
    combatTime = 0;
    moveDelay = 0;
    teleportAssembleDelay = 0;
    restDelay = 0;
    readyCheckDelay = 0;
    aoeDelay = sRobotConfig->AOEDelay;
    dpsDelay = sRobotConfig->DPSDelay;
    staying = false;
    holding = false;
    following = true;
    cure = true;
    actionType = 0;
    actionDelay = 0;
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
            followDistance = MID_RANGE;
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
            followDistance = MELEE_MIN_DISTANCE;
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

bool RobotStrategy_Group::Chasing()
{
    if (holding)
    {
        return false;
    }
    return true;
}

bool RobotStrategy_Group::Update0(uint32 pmDiff)
{
    if (!me)
    {
        return false;
    }
    sb->Update(pmDiff);

    if (Group* myGroup = me->GetGroup())
    {
        if (!me->GetSession()->isRobotSession)
        {
            return false;
        }
        if (Player* leaderPlayer = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            if (WorldSession* leaderWS = leaderPlayer->GetSession())
            {
                if (leaderWS->isRobotSession)
                {
                    me->RemoveFromGroup();
                    return false;
                }
            }
        }
        if (readyCheckDelay > 0)
        {
            readyCheckDelay -= pmDiff;
            if (readyCheckDelay <= 0)
            {
                if (Group* myGroup = me->GetGroup())
                {
                    if (Player* leaderPlayer = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
                    {
                        if (WorldSession* leaderWS = leaderPlayer->GetSession())
                        {
                            if (!leaderWS->isRobotSession)
                            {
                                uint8 readyCheckValue = 0;
                                if (!me->IsAlive())
                                {
                                    readyCheckValue = 0;
                                }
                                else if (me->GetDistance(leaderPlayer) > VISIBILITY_DISTANCE_NORMAL)
                                {
                                    readyCheckValue = 0;
                                }
                                else
                                {
                                    readyCheckValue = 1;
                                }
                                WorldPacket data(MSG_RAID_READY_CHECK, 8);
                                data << readyCheckValue;
                                if (WorldSession* myWS = me->GetSession())
                                {
                                    myWS->HandleRaidReadyCheckOpcode(data);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (teleportAssembleDelay > 0)
        {
            teleportAssembleDelay -= pmDiff;
            if (teleportAssembleDelay <= 0)
            {
                if (Player* leaderPlayer = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
                {
                    if (!me->IsAlive())
                    {
                        me->ResurrectPlayer(0.2f);
                        me->SpawnCorpseBones();
                    }
                    me->ClearInCombat();
                    me->TeleportTo(leaderPlayer->GetWorldLocation());
                    sb->WhisperTo("I have come", Language::LANG_UNIVERSAL, leaderPlayer);
                    return false;
                }
            }
        }
        if (moveDelay > 0)
        {
            moveDelay -= pmDiff;
            return false;
        }
        if (staying)
        {
            return false;
        }
    }

    return true;
}

void RobotStrategy_Group::Update(uint32 pmDiff)
{
    if (!Update0(pmDiff))
    {
        return;
    }
    if (Group* myGroup = me->GetGroup())
    {
        bool groupInCombat = GroupInCombat();
        if (groupInCombat)
        {
            restDelay = 0;
            combatTime += pmDiff;
        }
        else
        {
            combatTime = 0;
        }
        if (engageDelay > 0)
        {
            engageDelay -= pmDiff;
            if (me->IsAlive())
            {
                switch (me->groupRole)
                {
                case GroupRole::GroupRole_DPS:
                {
                    if (sb->DPS(engageTarget, Chasing(), false, NULL))
                    {
                        return;
                    }
                    else
                    {
                        engageTarget = NULL;
                        engageDelay = 0;
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
                    if (sb->Tank(engageTarget, Chasing()))
                    {
                        return;
                    }
                    else
                    {
                        engageTarget = NULL;
                        engageDelay = 0;
                    }
                    break;
                }
                default:
                {
                    break;
                }
                }
            }            
            return;
        }
        if (groupInCombat)
        {
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

bool RobotStrategy_Group::GroupInCombat()
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
                    if (me->GetDistance(member) < ATTACK_RANGE_LIMIT)
                    {
                        return true;
                    }
                }
                else if (Pet* memberPet = member->GetPet())
                {
                    if (memberPet->IsAlive())
                    {
                        if (memberPet->IsInCombat())
                        {
                            if (me->GetDistance(memberPet) < ATTACK_RANGE_LIMIT)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

Player* RobotStrategy_Group::GetPlayerByGroupRole(uint32 pmGroupRole)
{
    if (!me)
    {
        return NULL;
    }
    if (Group* myGroup = me->GetGroup())
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->groupRole == pmGroupRole)
                {
                    return member;
                }
            }
        }
    }

    return NULL;
}

std::unordered_set<Player*> RobotStrategy_Group::GetPlayerSetByGroupRoleSet(std::unordered_set<uint32> pmGroupRoleSet)
{
    std::unordered_set<Player*> resultSet;
    resultSet.clear();

    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (pmGroupRoleSet.find(member->groupRole) != pmGroupRoleSet.end())
                    {
                        resultSet.insert(member);
                    }
                }
            }
        }
    }

    return resultSet;
}

std::unordered_set<ObjectGuid> RobotStrategy_Group::GetPlayerGUIDSetByGroupRoleSet(std::unordered_set<uint32> pmGroupRoleSet)
{
    std::unordered_set<ObjectGuid> resultSet;
    resultSet.clear();

    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (pmGroupRoleSet.find(member->groupRole) != pmGroupRoleSet.end())
                    {
                        resultSet.insert(member->GetGUID());
                    }
                }
            }
        }
    }

    return resultSet;
}

Player* RobotStrategy_Group::GetMainTank()
{
    if (!me)
    {
        return NULL;
    }
    switch (me->groupRole)
    {
    case GroupRole::GroupRole_Tank:
    {
        return me;
    }
    default:
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->groupRole == GroupRole::GroupRole_Tank)
                    {
                        return member;
                    }
                }
            }
        }
        break;
    }
    }

    return NULL;
}

Player* RobotStrategy_Group::GetSubTank()
{
    return NULL;
}

bool RobotStrategy_Group::Engage(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole::GroupRole_Tank:
    {
        return sb->Tank(pmTarget, Chasing());
    }
    case GroupRole::GroupRole_DPS:
    {
        return sb->DPS(pmTarget, Chasing(), false, NULL);
    }
    case GroupRole::GroupRole_Healer:
    {
        return Heal();
    }
    default:
    {
        break;
    }
    }

    return false;
}

bool RobotStrategy_Group::DPS()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    if (combatTime > dpsDelay)
    {
        bool aoe = combatTime > aoeDelay;
        Player* mainTank = GetMainTank();
        if (mainTank)
        {
            if (sb->DPS(mainTank->GetSelectedUnit(), Chasing(), aoe, mainTank))
            {
                return true;
            }
        }
        if (sb->DPS(me->GetSelectedUnit(), Chasing(), aoe, mainTank))
        {
            return true;
        }
        Unit* closestVictim = NULL;
        float closestDistance = ATTACK_RANGE_LIMIT;
        std::unordered_map<ObjectGuid, Unit*> groupAttackerMap = GetAttackerMap();
        for (std::unordered_map<ObjectGuid, Unit*>::iterator gaIT = groupAttackerMap.begin(); gaIT != groupAttackerMap.end(); gaIT++)
        {
            if (Unit* eachAttacker = gaIT->second)
            {
                float eachAttackerDistance = me->GetDistance(eachAttacker);
                if (eachAttackerDistance < closestDistance)
                {
                    closestVictim = eachAttacker;
                    closestDistance = eachAttackerDistance;
                }
            }
        }
        if (sb->DPS(closestVictim, Chasing(), aoe, mainTank))
        {
            return true;
        }
    }

    return false;
}

bool RobotStrategy_Group::Lightwell()
{
    if (!me)
    {
        return false;
    }
    if (me->GetHealthPct() < 80.0f)
    {
        for (std::unordered_set<uint32>::iterator lightwellIT = sRobotManager->lightwellRenewSpellIDSet.begin(); lightwellIT != sRobotManager->lightwellRenewSpellIDSet.end(); lightwellIT++)
        {
            uint32 eachLightwellID = *lightwellIT;
            if (me->HasAura(eachLightwellID))
            {
                return false;
            }
        }

        std::list<Unit*> meleeRangeUnits;
        Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(me, me, NOMINAL_MELEE_RANGE);
        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, meleeRangeUnits, u_check);
        Cell::VisitAllObjects(me, searcher, NOMINAL_MELEE_RANGE);
        for (std::list<Unit*>::iterator it = meleeRangeUnits.begin(); it != meleeRangeUnits.end(); it++)
        {
            if (Unit* eachU = *it)
            {
                if (sRobotManager->lightwellUnitEntrySet.find(eachU->GetEntry()) != sRobotManager->lightwellUnitEntrySet.end())
                {
                    if (Creature* lightwellC = eachU->ToCreature())
                    {
                        lightwellC->HandleSpellClick(me);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool RobotStrategy_Group::Tank()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    if (Player* mainTank = GetMainTank())
    {
        if (mainTank->GetGUID() != me->GetGUID())
        {
            return DPS();
        }
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (me->IsValidAttackTarget(myTarget))
        {
            if (myTarget->GetTarget() != me->GetGUID())
            {
                if (me->GetDistance(myTarget) < RANGED_MAX_DISTANCE)
                {
                    sb->Taunt(myTarget);
                    if (sb->Tank(myTarget, Chasing()))
                    {
                        return true;
                    }
                }
            }
        }
    }
    Unit* closestVictim = NULL;
    float closestDistance = ATTACK_RANGE_LIMIT;
    std::unordered_map<ObjectGuid, Unit*> groupAttackerMap = GetAttackerMap();
    for (std::unordered_map<ObjectGuid, Unit*>::iterator gaIT = groupAttackerMap.begin(); gaIT != groupAttackerMap.end(); gaIT++)
    {
        if (Unit* eachAttacker = gaIT->second)
        {
            // tank can only cover 30.0f range
            if (me->GetDistance(eachAttacker) < RANGED_MAX_DISTANCE)
            {
                if (eachAttacker->GetTarget() != me->GetGUID())
                {
                    sb->Taunt(eachAttacker);
                    if (sb->Tank(eachAttacker, Chasing()))
                    {
                        return true;
                    }
                }
                float eachAttackerDistance = me->GetDistance(eachAttacker);
                if (eachAttackerDistance < closestDistance)
                {
                    closestVictim = eachAttacker;
                    closestDistance = eachAttackerDistance;
                }
            }
        }
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (me->IsValidAttackTarget(myTarget))
        {
            if (sb->Tank(myTarget, Chasing()))
            {
                return true;
            }
        }
    }
    if (sb->Tank(closestVictim, Chasing()))
    {
        return true;
    }

    return false;
}

bool RobotStrategy_Group::Tank(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole::GroupRole_Tank:
    {
        sb->ClearTarget();
        sb->ChooseTarget(pmTarget);
        return sb->Tank(pmTarget, Chasing());
    }
    default:
    {
        break;
    }
    }

    return false;
}

bool RobotStrategy_Group::Rest()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
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

bool RobotStrategy_Group::Heal()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        int lowMemberCount = 0;
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsAlive())
                {
                    if (member->GetHealthPct() < 60.0f)
                    {
                        if (me->GetDistance(member) < RANGED_MAX_DISTANCE)
                        {
                            lowMemberCount++;
                        }
                    }
                }
            }
        }
        if (lowMemberCount > 2)
        {
            if (sb->GroupHeal())
            {
                return true;
            }
        }
        if (Player* mainTank = GetMainTank())
        {
            if (mainTank->GetHealthPct() < 90.0f)
            {
                if (sb->Heal(mainTank, cure))
                {
                    return true;
                }
            }
        }
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsAlive())
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

bool RobotStrategy_Group::Buff()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
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

bool RobotStrategy_Group::Follow()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    if (holding)
    {
        return false;
    }
    if (!following)
    {
        return false;
    }
    if (Player* mainTank = GetMainTank())
    {
        if (mainTank->GetGUID() != me->GetGUID())
        {
            if (sb->Follow(mainTank, followDistance))
            {
                return true;
            }
        }
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            return sb->Follow(leader, followDistance);
        }
    }
    return false;
}

bool RobotStrategy_Group::Stay(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole::GroupRole_DPS)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole::GroupRole_Healer)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole::GroupRole_Tank)
        {
            todo = false;
        }
    }

    if (todo)
    {
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->AttackStop();
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        sb->PetStop();
        staying = true;
        return true;
    }

    return false;
}

bool RobotStrategy_Group::Hold(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole::GroupRole_DPS)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole::GroupRole_Healer)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole::GroupRole_Tank)
        {
            todo = false;
        }
    }

    if (todo)
    {
        holding = true;
        staying = false;
        return true;
    }

    return false;
}

std::string RobotStrategy_Group::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole::GroupRole_DPS:
    {
        return "dps";
    }
    case GroupRole::GroupRole_Tank:
    {
        return "tank";
    }
    case GroupRole::GroupRole_Healer:
    {
        return "healer";
    }
    default:
    {
        break;
    }
    }
    return "dps";
}

void RobotStrategy_Group::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    if (pmRoleName == "dps")
    {
        me->groupRole = GroupRole::GroupRole_DPS;
    }
    else if (pmRoleName == "tank")
    {
        me->groupRole = GroupRole::GroupRole_Tank;
    }
    else if (pmRoleName == "healer")
    {
        me->groupRole = GroupRole::GroupRole_Healer;
    }
}

std::unordered_map<ObjectGuid, Unit*> RobotStrategy_Group::GetAttackerMap()
{
    std::unordered_map<ObjectGuid, Unit*> attackerMap;
    attackerMap.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                if (eachAttacker->IsAlive())
                                {
                                    if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                    {
                                        attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                    }
                                }
                            }
                        }
                        if (Pet* memberPet = member->GetPet())
                        {
                            if (memberPet->IsAlive())
                            {
                                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                                {
                                    if (Unit* eachAttacker = *attackerIT)
                                    {
                                        if (eachAttacker->IsAlive())
                                        {
                                            if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                            {
                                                attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return attackerMap;
}

std::unordered_map<ObjectGuid, Unit*> RobotStrategy_Group::GetAddsMap(uint32 pmBossEntry)
{
    std::unordered_map<ObjectGuid, Unit*> attackerMap;
    attackerMap.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                if (eachAttacker->IsAlive())
                                {
                                    if (eachAttacker->GetEntry() == pmBossEntry)
                                    {
                                        continue;
                                    }
                                    if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                    {
                                        attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                    }
                                }
                            }
                        }
                        if (Pet* memberPet = member->GetPet())
                        {
                            if (memberPet->IsAlive())
                            {
                                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                                {
                                    if (Unit* eachAttacker = *attackerIT)
                                    {
                                        if (eachAttacker->IsAlive())
                                        {
                                            if (eachAttacker->GetEntry() == pmBossEntry)
                                            {
                                                continue;
                                            }
                                            if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                            {
                                                attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return attackerMap;
}

std::unordered_map<ObjectGuid, Unit*> RobotStrategy_Group::GetAttackerMap(uint32 pmAttackerEntry)
{
    std::unordered_map<ObjectGuid, Unit*> attackerMap;
    attackerMap.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                if (eachAttacker->IsAlive())
                                {
                                    if (eachAttacker->GetEntry() != pmAttackerEntry)
                                    {
                                        continue;
                                    }
                                    if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                    {
                                        attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                    }
                                }
                            }
                        }
                        if (Pet* memberPet = member->GetPet())
                        {
                            if (memberPet->IsAlive())
                            {
                                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                                {
                                    if (Unit* eachAttacker = *attackerIT)
                                    {
                                        if (eachAttacker->IsAlive())
                                        {
                                            if (eachAttacker->GetEntry() != pmAttackerEntry)
                                            {
                                                continue;
                                            }
                                            if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                                            {
                                                attackerMap[eachAttacker->GetGUID()] = eachAttacker;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return attackerMap;
}

Unit* RobotStrategy_Group::GetAttacker(uint32 pmAttackerEntry)
{
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    if (member->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                if (eachAttacker->IsAlive())
                                {
                                    if (eachAttacker->GetEntry() == pmAttackerEntry)
                                    {
                                        return eachAttacker;
                                    }
                                }
                            }
                        }
                        if (Pet* memberPet = member->GetPet())
                        {
                            if (memberPet->IsAlive())
                            {
                                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                                {
                                    if (Unit* eachAttacker = *attackerIT)
                                    {
                                        if (eachAttacker->IsAlive())
                                        {
                                            if (eachAttacker->GetEntry() == pmAttackerEntry)
                                            {
                                                return eachAttacker;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

bool RobotStrategy_Group::AngleInRange(float pmSourceAngle, float pmTargetAngle, float pmRange)
{
    float angleGap = std::abs(pmTargetAngle - pmSourceAngle);
    if (angleGap > M_PI)
    {
        angleGap = M_PI * 2 - angleGap;
    }
    if (angleGap < pmRange)
    {
        return true;
    }
    return false;
}

Position RobotStrategy_Group::GetNearPoint(Position pmSourcePosition, float pmDistance, float pmAbsoluteAngle)
{
    Position targetPosition;
    targetPosition.m_positionX = pmSourcePosition.GetPositionX() + pmDistance * std::cos(pmAbsoluteAngle);
    targetPosition.m_positionY = pmSourcePosition.GetPositionY() + pmDistance * std::sin(pmAbsoluteAngle);
    targetPosition.m_positionZ = pmSourcePosition.GetPositionZ() + 10.0f;
    me->UpdateAllowedPositionZ(targetPosition.m_positionX, targetPosition.m_positionY, targetPosition.m_positionZ);
    return targetPosition;
}
