#include "RobotStrategy.h"
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

RobotStrategy::RobotStrategy(Player* pmMe)
{
    me = pmMe;
    engageTarget = NULL;
    restDelay = 0;
    engageDelay = 0;
    strategyType = RobotStrategyType::RobotStrategyType_Solo;
}

void RobotStrategy::Update(uint32 pmDiff)
{
    return;
}

void RobotStrategy_Solo::InitialStrategy()
{
    strategyType = RobotStrategyType::RobotStrategyType_Solo;
    soloState = RobotSoloState::RobotSoloState_Wander;

    deathDelay = 0;
    soloDelay = urand(sRobotConfig->SoloMinDelay, sRobotConfig->SoloMaxDelay);
    restDelay = 0;
    waitDelay = 0;
    strollDelay = 0;
    confuseDelay = 0;
    interestsDelay = 0;

    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        sb = new Script_Warrior(me);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        sb = new Script_Hunter(me);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        sb = new Script_Shaman(me);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        sb = new Script_Paladin(me);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        sb = new Script_Warlock(me);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        sb = new Script_Priest(me);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        sb = new Script_Rogue(me);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        sb = new Script_Mage(me);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        sb = new Script_Druid(me);
        break;
    }
    }
}

void RobotStrategy_Solo::Update(uint32 pmDiff)
{
    if (!me)
    {
        return;
    }
    if (me->GetGroup())
    {
        me->rai->GetActiveStrategy()->sb->Reset();
        me->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Group;
        return;
    }
    if (!me->GetSession()->isRobotSession)
    {
        return;
    }
    if (interestsDelay > 0)
    {
        interestsDelay -= pmDiff;
    }
    if (!me->IsAlive())
    {
        if (deathDelay > 0)
        {
            deathDelay -= pmDiff;
            if (deathDelay <= 0)
            {
                sb->RandomTeleport();
                return;
            }
        }
        else
        {
            deathDelay = urand(sRobotConfig->DeathMinDelay, sRobotConfig->DeathMaxDelay);
        }
        return;
    }
    soloDelay -= pmDiff;
    if (soloDelay < 0)
    {
        sb->RandomTeleport();
        return;
    }
    switch (soloState)
    {
    case RobotSoloState::RobotSoloState_None:
    {
        return;
    }
    case RobotSoloState::RobotSoloState_Wander:
    {
        if (me->IsInCombat())
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        if (Rest())
        {
            return;
        }
        if (Buff())
        {
            return;
        }
        if (PVP())
        {
            engageDelay = 20 * TimeConstants::IN_MILLISECONDS;
            return;
        }
        if (urand(0, 1) == 0)
        {
            if (Confuse())
            {
                return;
            }
        }
        if (urand(0, 1) == 0)
        {
            if (Stroll())
            {
                return;
            }
        }
        if (Battle())
        {
            soloState = RobotSoloState::RobotSoloState_Battle;
            engageDelay = 10 * TimeConstants::IN_MILLISECONDS;
            return;
        }
        if (Wait())
        {
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Battle:
    {
        if (me->IsInCombat())
        {
            engageDelay = 0;
            if (me->GetHealthPct() < 40.0f)
            {
                if (Heal())
                {
                    return;
                }
            }
            if (Battle())
            {
                return;
            }
            if (me->GetClass() == Classes::CLASS_HUNTER)
            {
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
            }
        }
        else
        {
            if (engageDelay > 0)
            {
                engageDelay -= pmDiff;
            }
            if (engageDelay <= 0)
            {
                engageDelay = 0;
                soloState = RobotSoloState::RobotSoloState_Wander;
                return;
            }
            if (sb->Attack(engageTarget))
            {
                return;
            }
            else
            {
                engageTarget = NULL;
                engageDelay = 0;
            }
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Rest:
    {
        if (me->IsInCombat())
        {
            restDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        restDelay -= pmDiff;
        if (restDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Wait:
    {
        if (me->IsInCombat())
        {
            waitDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        waitDelay -= pmDiff;
        if (waitDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Stroll:
    {
        if (me->IsInCombat())
        {
            strollDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        strollDelay -= pmDiff;
        if (strollDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
            return;
        }
        break;
    }
    case RobotSoloState::RobotSoloState_Confuse:
    {
        if (me->IsInCombat())
        {
            confuseDelay = 0;
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Battle;
            return;
        }
        confuseDelay -= pmDiff;
        if (confuseDelay < 0)
        {
            me->StopMoving();
            me->GetMotionMaster()->Clear();
            soloState = RobotSoloState::RobotSoloState_Wander;
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

bool RobotStrategy_Solo::Buff()
{
    if (me)
    {
        return sb->Buff(me, true);
    }
    return false;
}

bool RobotStrategy_Solo::Rest()
{
    if (!me)
    {
        return false;
    }
    if (me->IsInCombat())
    {
        return false;
    }
    else
    {
        float hpRate = me->GetHealthPct();
        float mpRate = 100;
        if (me->GetPowerType() == Powers::POWER_MANA)
        {
            mpRate = me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA);
        }
        if (hpRate > 50 && mpRate > 50)
        {
            return false;
        }
        else
        {
            if (sb->Rest())
            {
                soloState = RobotSoloState::RobotSoloState_Rest;
                restDelay = DEFAULT_REST_DELAY;
                return true;
            }
        }
    }

    return false;
}

bool RobotStrategy_Solo::Battle()
{
    if (!me)
    {
        return false;
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (Player* targetPlayer = myTarget->ToPlayer())
        {
            if (sb->Attack(targetPlayer))
            {
                engageTarget = targetPlayer;
                return true;
            }
        }
    }
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); attackerIT++)
    {
        if (Unit* pTarget = *attackerIT)
        {
            if (Player* targetPlayer = pTarget->ToPlayer())
            {
                if (sb->Attack(targetPlayer))
                {
                    engageTarget = targetPlayer;
                    return true;
                }
            }
        }
    }
    if (Pet* memberPet = me->GetPet())
    {
        if (memberPet->IsAlive())
        {
            for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
            {
                if (Unit* eachAttacker = *attackerIT)
                {
                    if (Player* targetPlayer = eachAttacker->ToPlayer())
                    {
                        if (sb->Attack(targetPlayer))
                        {
                            engageTarget = targetPlayer;
                            return true;
                        }
                    }
                }
            }
        }
    }
    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (sb->Attack(myTarget))
        {
            engageTarget = myTarget;
            return true;
        }
    }
    Unit* closestAttacker = NULL;
    float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); attackerIT++)
    {
        if (Unit* pTarget = *attackerIT)
        {
            float distance = me->GetDistance(pTarget);
            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestAttacker = pTarget;
            }
        }
    }
    if (Pet* memberPet = me->GetPet())
    {
        if (memberPet->IsAlive())
        {
            for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
            {
                if (Unit* eachAttacker = *attackerIT)
                {
                    float distance = me->GetDistance(eachAttacker);
                    if (distance < closestDistance)
                    {
                        closestDistance = distance;
                        closestAttacker = eachAttacker;
                    }
                }
            }
        }
    }
    if (sb->Attack(closestAttacker))
    {
        engageTarget = closestAttacker;
        return true;
    }

    std::list<Unit*> attackTargets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, DEFAULT_VISIBILITY_DISTANCE);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, attackTargets, u_check);
    Cell::VisitAllObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);
    Unit* nearestAttackableTarget = NULL;
    float nearestDistance = MAX_VISIBILITY_DISTANCE;
    for (std::list<Unit*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
    {
        if (Unit* eachU = *it)
        {
            if (eachU->IsPet())
            {
                if (Pet* pet = eachU->ToPet())
                {
                    if (pet->GetCharmerOrOwner())
                    {
                        continue;
                    }
                }
            }
            if (!me->IsValidAttackTarget(eachU))
            {
                continue;
            }
            if (!me->IsWithinLOSInMap(eachU))
            {
                continue;
            }
            if (eachU->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (sb->Attack(eachU))
                {
                    engageTarget = eachU;
                    return true;
                }
            }
            float checkDistance = me->GetDistance(eachU);
            if (checkDistance < nearestDistance)
            {
                nearestDistance = checkDistance;
                nearestAttackableTarget = eachU;
            }
        }
    }
    if (sb->Attack(nearestAttackableTarget))
    {
        engageTarget = nearestAttackableTarget;
        return true;
    }

    return false;
}

bool RobotStrategy_Solo::PVP()
{
    if (!me)
    {
        return false;
    }
    std::list<Player*> attackTargets;
    Trinity::AnyPlayerInObjectRangeCheck u_check(me, DEFAULT_VISIBILITY_DISTANCE);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, attackTargets, u_check);
    Cell::VisitWorldObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);
    for (std::list<Player*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
    {
        if (Player* eachPlayer = *it)
        {
            if (sb->Attack(eachPlayer))
            {
                engageTarget = eachPlayer;
                return true;
            }
        }
    }

    return false;
}

bool RobotStrategy_Solo::Heal()
{
    if (me)
    {
        return sb->Heal(me, true);
    }
    return false;
}

bool RobotStrategy_Solo::Wait()
{
    if (me)
    {
        sb->ClearTarget();
        me->AttackStop();
        me->GetMotionMaster()->Clear();
        me->StopMoving();
        waitDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Wait;
        return true;
    }
    return false;
}

bool RobotStrategy_Solo::Stroll()
{
    if (me)
    {
        float destX = 0;
        float destY = 0;
        float destZ = 0;
        Position rdp = me->GetRandomPoint(me->GetPosition(), DEFAULT_VISIBILITY_DISTANCE);
        me->GetMotionMaster()->MovePoint(0, rdp);
        strollDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Stroll;
        return true;
    }
    return false;
}

bool RobotStrategy_Solo::Confuse()
{
    // EJ confuse issue use wait instead
    return Wait();

    if (me)
    {
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveConfused();
        confuseDelay = 5 * TimeConstants::IN_MILLISECONDS;
        soloState = RobotSoloState::RobotSoloState_Confuse;
        return true;
    }
    return false;
}

void RobotStrategy_Solo::HandleChatCommand(Player* pmSender, std::string pmCMD)
{
    if (!me)
    {
        return;
    }
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "who")
    {
        sb->WhisperTo(sRobotManager->characterTalentTabNameMap[me->GetClass()][sb->characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
    }
}

void RobotStrategy_Solo::Reset()
{
    deathDelay = 0;
    confuseDelay = 0;
    engageDelay = 0;
    restDelay = 0;
    soloDelay = urand(sRobotConfig->SoloMinDelay, sRobotConfig->SoloMaxDelay);
    waitDelay = 0;
    strollDelay = 0;
    soloState = RobotSoloState::RobotSoloState_Wander;
}

void RobotStrategy_Group::InitialStrategy()
{
    strategyType = RobotStrategyType::RobotStrategyType_Group;
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
        if (!me->IsAlive())
        {
            return false;
        }
    }
    else
    {
        me->rai->GetActiveStrategy()->sb->Reset();
        me->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
        return false;
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
    else
    {
        me->rai->GetActiveStrategy()->sb->Reset();
        me->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
        return;
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
}

Creature* RobotStrategy_Group::GetNearbyCreature(uint32 pmCreatureEntry, float pmDistance)
{
    if (me)
    {
        std::list<Creature*> creatures;
        me->GetCreatureListWithEntryInGrid(creatures, pmCreatureEntry, pmDistance);
        for (Creature* eachCreature : creatures)
        {
            return eachCreature;
        }
    }

    return NULL;
}

std::string RobotStrategy_Group_Blackrock_Spire::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
    {
        return "dps";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
    {
        return "tank1";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
    {
        return "tank2";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
    {
        return "tank3";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
    {
        return "healer1";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
    {
        return "healer2";
    }
    default:
    {
        break;
    }
    }
    return "dps";
}

void RobotStrategy_Group_Blackrock_Spire::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    if (pmRoleName == "dps")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS;
    }
    else if (pmRoleName == "tank1")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1;
    }
    else if (pmRoleName == "tank2")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2;
    }
    else if (pmRoleName == "tank3")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3;
    }
    else if (pmRoleName == "healer1")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1;
    }
    else if (pmRoleName == "healer2")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2;
    }
}

void RobotStrategy_Group_Blackrock_Spire::InitialStrategy()
{
    RobotStrategy_Group::InitialStrategy();
    tankGythPos.m_positionX = 180.0f;
    tankGythPos.m_positionY = -420.0f;
    tankGythPos.m_positionZ = 110.5f;

    tankRendPos.m_positionX = 140.0f;
    tankRendPos.m_positionY = -420.0f;
    tankRendPos.m_positionZ = 110.5f;

    dpsGythPos.m_positionX = 160.0f;
    dpsGythPos.m_positionY = -420.0f;
    dpsGythPos.m_positionZ = 110.5f;

    tankDrakkisathPos1.m_positionX = 19.0f;
    tankDrakkisathPos1.m_positionY = -310.0f;
    tankDrakkisathPos1.m_positionZ = 111.0f;

    tankDrakkisathPos2.m_positionX = 7.0f;
    tankDrakkisathPos2.m_positionY = -310.0f;
    tankDrakkisathPos2.m_positionZ = 111.0f;

    tankDrakkisathAddsPos.m_positionX = 35.0f;
    tankDrakkisathAddsPos.m_positionY = -285.0f;
    tankDrakkisathAddsPos.m_positionZ = 111.0f;

    dpsDrakkisathPos.m_positionX = 12.0f;
    dpsDrakkisathPos.m_positionY = -285.0f;
    dpsDrakkisathPos.m_positionZ = 111.0f;
}

Player* RobotStrategy_Group_Blackrock_Spire::GetMainTank()
{
    if (!me)
    {
        return NULL;
    }
    if (Group* myGroup = me->GetGroup())
    {
        Player* tank1 = NULL;
        Player* tank2 = NULL;
        Player* tank3 = NULL;
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
                {
                    tank1 = member;
                }
                else if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
                {
                    tank2 = member;
                }
                else if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3)
                {
                    tank3 = member;
                }
            }
        }
        if (tank1)
        {
            if (tank1->IsAlive())
            {
                if (me->GetDistance(tank1) < ATTACK_RANGE_LIMIT)
                {
                    return tank1;
                }
            }
        }
        if (tank2)
        {
            if (tank2->IsAlive())
            {
                if (me->GetDistance(tank2) < ATTACK_RANGE_LIMIT)
                {
                    return tank2;
                }
            }
        }
        if (tank3)
        {
            if (tank3->IsAlive())
            {
                if (me->GetDistance(tank3) < ATTACK_RANGE_LIMIT)
                {
                    return tank3;
                }
            }
        }
    }

    return NULL;
}

bool RobotStrategy_Group_Blackrock_Spire::DPS()
{
    if (!me)
    {
        return false;
    }
    if (combatTime < dpsDelay)
    {
        if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
                    actionDelay = 3000;
                    return true;
                }
            }
        }
        if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
                    actionDelay = 3000;
                    return true;
                }
            }
        }
    }
    else
    {
        if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
                    actionDelay = 3000;
                    return true;
                }
                if (sb->DPS(gyth, Chasing(), false, NULL))
                {
                    return true;
                }
            }
        }
        if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
                    actionDelay = 3000;
                    return true;
                }
            }
            if (Player* addsTank = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3))
            {
                if (sb->DPS(addsTank->GetSelectedUnit(), Chasing(), false, NULL))
                {
                    return true;
                }
            }
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_Blackrock_Spire::Heal()
{
    if (!me)
    {
        return false;
    }
    if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
    {
        if (me->GetDistance(dpsGythPos) > 3.0f)
        {
            actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
            actionDelay = 3000;
            return true;
        }
    }
    else if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
    {
        if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
        {
            actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
            actionDelay = 3000;
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1)
        {
            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1))
            {
                if (tank1->IsAlive())
                {
                    if (tank1->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank1, cure))
                        {
                            return true;
                        }
                    }
                }
            }
            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2))
            {
                if (tank2->IsAlive())
                {
                    if (tank2->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank2, cure))
                        {
                            return true;
                        }
                    }
                }
            }
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2)
        {
            if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3))
            {
                if (tank3->IsAlive())
                {
                    if (tank3->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank3, cure))
                        {
                            return true;
                        }
                    }
                }
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
                                if (me->GetDistance(member) < FOLLOW_NORMAL_DISTANCE)
                                {
                                    lowMemberCount++;
                                }
                            }
                        }
                    }
                }
                if (lowMemberCount > 1)
                {
                    if (sb->GroupHeal())
                    {
                        return true;
                    }
                }
            }
            return true;
        }
    }

    return RobotStrategy_Group::Heal();
}

bool RobotStrategy_Group_Blackrock_Spire::Engage(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
    {
        return sb->DPS(pmTarget, Chasing(), false, NULL);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
    {
        return Heal();
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
    {
        return Heal();
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
    {
        return Tank(pmTarget);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
    {
        return Tank(pmTarget);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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

bool RobotStrategy_Group_Blackrock_Spire::Tank(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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

bool RobotStrategy_Group_Blackrock_Spire::Tank()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    Player* mainTank = GetMainTank();
    if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (gyth->GetTarget() != me->GetGUID())
            {
                sb->Taunt(gyth);
                if (sb->Tank(gyth, Chasing()))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankGythPos) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankGythMove;
                actionDelay = 3000;
                return true;
            }
            sb->Taunt(gyth);
            if (sb->Tank(gyth, Chasing()))
            {
                return true;
            }
        }
    }
    if (Unit* rend = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Rend))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
        {
            if (rend->GetTarget() != me->GetGUID())
            {
                sb->Taunt(rend);
                if (sb->Tank(rend, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankRendPos) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankRendMove;
                actionDelay = 3000;
                return true;
            }
            sb->Taunt(rend);
            if (sb->Tank(rend, Chasing(), true))
            {
                return true;
            }
        }
    }
    if (Unit* drakkisath = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            if (drakkisath->GetTarget() != me->GetGUID())
            {
                sb->Taunt(drakkisath);
                if (sb->Tank(drakkisath, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankDrakkisathPos1) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove1;
                actionDelay = 1000;
                return true;
            }
            sb->Taunt(drakkisath);
            if (sb->Tank(drakkisath, Chasing(), true))
            {
                return true;
            }
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            if (mainTank->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                if (drakkisath->GetTarget() != me->GetGUID())
                {
                    sb->Taunt(drakkisath);
                    if (sb->Tank(drakkisath, Chasing(), true))
                    {
                        return true;
                    }
                }
                if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2;
                    actionDelay = 1000;
                    return true;
                }
                sb->Taunt(drakkisath);
                if (sb->Tank(drakkisath, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2;
                actionDelay = 3000;
                return true;
            }
            else
            {
                if (!me->isInFront(drakkisath, M_PI / 16))
                {
                    me->SetFacingToObject(drakkisath);
                }
            }
            me->AttackStop();
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            std::unordered_map<ObjectGuid, Unit*> addsMap = GetAddsMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath);
            if (addsMap.size() > 0)
            {
                Unit* closestAdds = NULL;
                float closestAddsDistance = ATTACK_RANGE_LIMIT;
                for (std::unordered_map<ObjectGuid, Unit*>::iterator addsIT = addsMap.begin(); addsIT != addsMap.end(); addsIT++)
                {
                    if (addsIT->second->GetTarget() != me->GetGUID())
                    {
                        sb->Taunt(addsIT->second);
                        if (sb->Tank(addsIT->second, Chasing()))
                        {
                            return true;
                        }
                    }
                    float eachAddsDistance = me->GetDistance(addsIT->second);
                    if (eachAddsDistance < closestAddsDistance)
                    {
                        closestAdds = addsIT->second;
                        closestAddsDistance = eachAddsDistance;
                    }
                }
                if (me->GetDistance(tankDrakkisathAddsPos) > 1.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathAddsMove;
                    actionDelay = 1000;
                    return true;
                }
                if (Unit* myTarget = me->GetSelectedUnit())
                {
                    if (addsMap.find(myTarget->GetGUID()) != addsMap.end())
                    {
                        sb->Taunt(myTarget);
                        if (sb->Tank(myTarget, Chasing()))
                        {
                            return true;
                        }
                    }
                }
                sb->Taunt(closestAdds);
                if (sb->Tank(closestAdds, Chasing()))
                {
                    return true;
                }
            }
        }
    }

    return RobotStrategy_Group::Tank();
}

void RobotStrategy_Group_Blackrock_Spire::Update(uint32 pmDiff)
{
    if (!Update0(pmDiff))
    {
        return;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (actionDelay > 0)
        {
            actionDelay -= pmDiff;
            switch (actionType)
            {
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankGythMove:
            {
                if (me->GetDistance(tankGythPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankGythPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankRendMove:
            {
                if (me->GetDistance(tankRendPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankRendPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove:
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, dpsGythPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove1:
            {
                if (me->GetDistance(tankDrakkisathPos1) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathPos1);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2:
            {
                if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathPos2);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathAddsMove:
            {
                if (me->GetDistance(tankDrakkisathAddsPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathAddsPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove:
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, dpsDrakkisathPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return;
        }
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
            switch (me->groupRole)
            {
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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
            return;
        }
        if (groupInCombat)
        {
            switch (me->groupRole)
            {
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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
    else
    {
        me->rai->GetActiveStrategy()->sb->Reset();
        me->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
        return;
    }
}

bool RobotStrategy_Group_Alcaz_Island::DPS()
{
    if (!me)
    {
        return false;
    }
    if (combatTime > dpsDelay)
    {
        for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); ++attackerIT)
        {
            if (Unit* eachAttacker = *attackerIT)
            {
                if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                {
                    if (sb->DPS(eachAttacker, Chasing(), false, NULL))
                    {
                        return true;
                    }
                }
            }
        }
        if (Pet* memberPet = me->GetPet())
        {
            if (memberPet->IsAlive())
            {
                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                {
                    if (Unit* eachAttacker = *attackerIT)
                    {
                        if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                        {
                            if (sb->DPS(eachAttacker, Chasing(), false, NULL))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_Alcaz_Island::Tank()
{
    if (!me)
    {
        return false;
    }
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); ++attackerIT)
    {
        if (Unit* eachAttacker = *attackerIT)
        {
            if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
            {
                if (sb->Tank(eachAttacker, Chasing(), true))
                {
                    return true;
                }
            }
        }
    }
    if (Pet* memberPet = me->GetPet())
    {
        if (memberPet->IsAlive())
        {
            for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
            {
                if (Unit* eachAttacker = *attackerIT)
                {
                    if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                    {
                        if (sb->Tank(eachAttacker, Chasing(), true))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return RobotStrategy_Group::Tank();
}

void RobotStrategy_Group_EmeraldDragon::InitialStrategy()
{
    engageAngle = 0.0f;
    sideAngle = 0.0f;
    RobotStrategy_Group::InitialStrategy();
}

std::string RobotStrategy_Group_EmeraldDragon::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
    {
        return "tank1";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
    {
        return "tank2";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
    {
        return "tank3";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
    {
        return "tank4";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
    {
        return "tank5";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
    {
        return "healer1";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
    {
        return "healer2";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
    {
        return "healer3";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
    {
        return "healer4";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
    {
        return "healer5";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
    {
        return "healer6";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
    {
        return "healer7";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
    {
        return "healer8";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range:
    {
        return "dpsr";
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee:
    {
        return "dpsm";
    }
    default:
    {
        break;
    }
    }
    return "dps";
}

void RobotStrategy_Group_EmeraldDragon::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    else if (pmRoleName == "tank1")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1;
    }
    else if (pmRoleName == "tank2")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2;
    }
    else if (pmRoleName == "tank3")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3;
    }
    else if (pmRoleName == "tank4")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4;
    }
    else if (pmRoleName == "tank5")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5;
    }
    else if (pmRoleName == "healer1")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1;
    }
    else if (pmRoleName == "healer2")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2;
    }
    else if (pmRoleName == "healer3")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3;
    }
    else if (pmRoleName == "healer4")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4;
    }
    else if (pmRoleName == "healer5")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5;
    }
    else if (pmRoleName == "healer6")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6;
    }
    else if (pmRoleName == "healer7")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7;
    }
    else if (pmRoleName == "healer8")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8;
    }
    else if (pmRoleName == "dpsm")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee;
    }
    else if (pmRoleName == "dpsr")
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range;
    }
    else
    {
        me->groupRole = GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range;
    }
}

bool RobotStrategy_Group_EmeraldDragon::Stay(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5)
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

bool RobotStrategy_Group_EmeraldDragon::Hold(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4 && me->groupRole != GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5)
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

bool RobotStrategy_Group_EmeraldDragon::Engage(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
    {
        return sb->Tank(pmTarget, Chasing());
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
    {
        return Tank();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
    {
        return Heal();
    }
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
    {
        return Heal();
    }
    default:
    {
        return DPS();
    }
    }

    return false;
}

bool RobotStrategy_Group_EmeraldDragon::Follow()
{
    if (!me)
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
    if (Group* myGroup = me->GetGroup())
    {
        if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            return sb->Follow(leader, followDistance);
        }
    }
    return false;
}

void RobotStrategy_Group_EmeraldDragon::Update(uint32 pmDiff)
{
    if (!Update0(pmDiff))
    {
        return;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (actionDelay > 0)
        {
            actionDelay -= pmDiff;
            switch (actionType)
            {
            case ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove:
            {
                if (me->GetExactDist(markPos) < 0.5f)
                {
                    actionDelay = 0;
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return;
        }
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
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee:
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
            default:
            {
                break;
            }
            }
            return;
        }
        if (groupInCombat)
        {
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee:
            {
                if (DPS())
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

            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range:
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
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee:
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
    else
    {
        me->rai->GetActiveStrategy()->sb->Reset();
        me->rai->activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
        return;
    }
}

bool RobotStrategy_Group_EmeraldDragon::DPS()
{
    if (me->HasAura(24778))
    {
        return true;
    }
    //if (Creature* dreamFog = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog))
    //{
    //    if (me->GetDistance(dreamFog) < 5.0f)
    //    {
    //        if (urand(0, 1) == 0)
    //        {
    //            engageAngle = engageAngle - M_PI / 16;
    //        }
    //        else
    //        {
    //            engageAngle = engageAngle + M_PI / 16;
    //        }
    //        Position dodgePos;
    //        float currentDistance = me->GetExactDist(basePos);
    //        dodgePos.m_positionX = basePos.m_positionX + currentDistance * std::cos(engageAngle);
    //        dodgePos.m_positionY = basePos.m_positionY + currentDistance * std::sin(engageAngle);
    //        dodgePos.m_positionZ = basePos.m_positionZ + 10.0f;
    //        me->UpdateAllowedPositionZ(dodgePos.m_positionX, dodgePos.m_positionY, dodgePos.m_positionZ);
    //        markPos = dodgePos;
    //        actionDelay = 10000;
    //        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
    //        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(basePos));
    //    }
    //}
    if (Group* myGroup = me->GetGroup())
    {
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            bool chaseDPS = true;
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
            {
                chaseDPS = false;
            }
            //else if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee)
            //{
            //    if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
            //    {
            //        float currentDistance = me->GetDistance(taerar);
            //        if (currentDistance < 35.0f || currentDistance > 40.0f)
            //        {
            //            taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
            //            actionDelay = 5000;
            //            actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
            //            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
            //        }
            //    }
            //}
            if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
            {
                if (shade7->IsAlive())
                {
                    if (sb->DPS(shade7, chaseDPS, false, NULL))
                    {
                        return true;
                    }
                }
            }
            if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
            {
                if (activeTank->IsAlive())
                {
                    if (activeTank->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1)
                    {
                        if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                        {
                            if (shade5->IsAlive())
                            {
                                if (sb->DPS(shade5, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                        if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                        {
                            if (shade6->IsAlive())
                            {
                                if (sb->DPS(shade6, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                        {
                            if (shade6->IsAlive())
                            {
                                if (sb->DPS(shade6, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                        if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                        {
                            if (shade5->IsAlive())
                            {
                                if (sb->DPS(shade5, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            //return true;
        }
        if (Unit* taerar = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
        {
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
            {
                if (taerar->GetTarget() != me->GetGUID())
                {
                    bool move = false;
                    float currentDistance = me->GetDistance(taerar);
                    float currentAngle = taerar->GetAbsoluteAngle(me->GetPosition());
                    if (currentDistance < 28.0f || currentDistance > 30.0f)
                    {
                        move = true;
                    }
                    else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                    {
                        move = true;
                    }
                    if (move)
                    {
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, engageAngle);
                        //taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, taerar->GetAbsoluteAngle(me->GetPosition()));
                        actionDelay = 5000;
                        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                        return true;
                    }
                    if (combatTime > dpsDelay)
                    {
                        sb->DPS(taerar, false, false, NULL);
                    }
                }
            }
            else if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee)
            {
                float currentDistance = me->GetDistance(taerar);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                }
                //if (Player* taerarTarget = ObjectAccessor::FindConnectedPlayer(taerar->GetTarget()))
                //{
                //    if (taerarTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1)
                //    {
                //        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                //        {
                //            if (tank2->IsAlive())
                //            {
                //                markPos = tank2->GetPosition();
                //                if (me->GetExactDist(markPos) > 0.5f)
                //                {
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                //                    actionDelay = 5000;
                //                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                //                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                //                    return true;
                //                }
                //                sb->DPS(taerar, false, false, NULL);
                //            }
                //        }
                //    }
                //    else if (taerarTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2)
                //    {
                //        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                //        {
                //            if (tank1->IsAlive())
                //            {
                //                markPos = tank1->GetPosition();
                //                if (me->GetExactDist(markPos) > 0.5f)
                //                {
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                //                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                //                    actionDelay = 5000;
                //                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                //                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                //                    return true;
                //                }
                //                sb->DPS(taerar, false, false, NULL);
                //            }
                //        }
                //    }
                //}
            }
            return true;
        }
        std::unordered_map<ObjectGuid, Unit*> dementedDruidMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Demented_Druid);
        if (dementedDruidMap.size() > 0)
        {
            bool chaseDPS = true;
            float distanceLimit = VISIBILITY_DISTANCE_NORMAL;
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
            {
                chaseDPS = false;
                distanceLimit = 30.0f;
            }
            if (myGroup->groupTargetArrangementMap.find(me->GetGUID()) != myGroup->groupTargetArrangementMap.end())
            {
                ObjectGuid myDruidGUID = myGroup->groupTargetArrangementMap[me->GetGUID()];
                if (Unit* myDruid = ObjectAccessor::GetUnit(*me, myDruidGUID))
                {
                    if (myDruid->IsAlive())
                    {
                        if (me->GetDistance(myDruid) < distanceLimit)
                        {
                            if (sb->DPS(myDruid, chaseDPS, false, NULL))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
            {
                if (Unit* eachDD = ddIT->second)
                {
                    if (me->GetDistance(eachDD) < distanceLimit)
                    {
                        bool arranged = false;
                        for (std::unordered_map<ObjectGuid, ObjectGuid>::iterator arrangedIT = myGroup->groupTargetArrangementMap.begin(); arrangedIT != myGroup->groupTargetArrangementMap.end(); arrangedIT++)
                        {
                            if (eachDD->GetGUID() == arrangedIT->second)
                            {
                                arranged = true;
                                break;
                            }
                        }
                        if (!arranged)
                        {
                            myGroup->groupTargetArrangementMap[me->GetGUID()] = eachDD->GetGUID();
                            return true;
                        }
                    }
                }
            }
            for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
            {
                if (Unit* eachDD = ddIT->second)
                {
                    if (me->GetDistance(eachDD) < distanceLimit)
                    {
                        if (sb->DPS(eachDD, chaseDPS, false, NULL))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        else
        {
            myGroup->groupTargetArrangementMap.clear();
        }
        if (Unit* ysondre = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Ysondre))
        {
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
            {
                if (ysondre->GetTarget() != me->GetGUID())
                {
                    float currentDistance = me->GetDistance(ysondre);
                    if (currentDistance < 28.0f || currentDistance > 30.0f)
                    {
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, engageAngle);
                        //taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, taerar->GetAbsoluteAngle(me->GetPosition()));
                        actionDelay = 5000;
                        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                        return true;
                    }
                    if (combatTime > dpsDelay)
                    {
                        sb->DPS(ysondre, false, false, NULL);
                    }
                }
            }
            else if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee)
            {
                float currentDistance = me->GetDistance(ysondre);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                }
            }
            return true;
        }
        if (Unit* lethon = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Lethon))
        {
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Range)
            {
                if (lethon->GetTarget() != me->GetGUID())
                {
                    float currentDistance = me->GetDistance(lethon);
                    if (currentDistance < 28.0f || currentDistance > 30.0f)
                    {
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, engageAngle);
                        //taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 29.0f, taerar->GetAbsoluteAngle(me->GetPosition()));
                        actionDelay = 5000;
                        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                        return true;
                    }
                    if (combatTime > dpsDelay)
                    {
                        sb->DPS(lethon, false, false, NULL);
                    }
                }
            }
            else if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_DPS_Melee)
            {
                float currentDistance = me->GetDistance(lethon);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                }
            }
            return true;
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_EmeraldDragon::Tank()
{
    if (me->HasAura(24778))
    {
        return true;
    }
    if (Group* myGroup = me->GetGroup())
    {
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            if (Unit* firstShade = shadeOfTaerarMap.begin()->second)
            {
                int targetIcon = myGroup->GetTargetIconByOG(firstShade->GetGUID());
                if (targetIcon < 5 || targetIcon > 7)
                {
                    if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                    {
                        tankPos = activeTank->GetPosition();
                    }
                    uint32 totalMana1 = 0;
                    uint32 totalMana2 = 0;
                    if (Player* healer1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1))
                    {
                        if (healer1->IsAlive())
                        {
                            totalMana1 = totalMana1 + healer1->GetPower(Powers::POWER_MANA);
                        }
                    }
                    if (Player* healer2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2))
                    {
                        if (healer2->IsAlive())
                        {
                            totalMana1 = totalMana1 + healer2->GetPower(Powers::POWER_MANA);
                        }
                    }
                    if (Player* healer3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3))
                    {
                        if (healer3->IsAlive())
                        {
                            totalMana2 = totalMana2 + healer3->GetPower(Powers::POWER_MANA);
                        }
                    }
                    if (Player* healer4 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4))
                    {
                        if (healer4->IsAlive())
                        {
                            totalMana2 = totalMana2 + healer4->GetPower(Powers::POWER_MANA);
                        }
                    }
                    if (totalMana1 > totalMana2)
                    {
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                        {
                            if (tank1->IsAlive())
                            {
                                myGroup->SetTargetIcon(0, me->GetGUID(), tank1->GetGUID());
                            }
                        }
                    }
                    else
                    {
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                        {
                            if (tank2->IsAlive())
                            {
                                myGroup->SetTargetIcon(0, me->GetGUID(), tank2->GetGUID());
                            }
                        }
                    }
                    int checkTargetIcon = 5;
                    for (std::unordered_map<ObjectGuid, Unit*>::iterator shadeIT = shadeOfTaerarMap.begin(); shadeIT != shadeOfTaerarMap.end(); shadeIT++)
                    {
                        if (Unit* eachShade = shadeIT->second)
                        {
                            myGroup->SetTargetIcon(checkTargetIcon, me->GetGUID(), eachShade->GetGUID());
                            checkTargetIcon++;
                        }
                    }
                }
            }
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
            {
                if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                {
                    if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                    {
                        if (myShade->IsAlive())
                        {
                            if (myShade->GetTarget() == me->GetGUID())
                            {
                                bool move = true;
                                //if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                                //{
                                //    if (shade7->IsAlive())
                                //    {
                                //        move = false;
                                //    }
                                //}
                                if (move)
                                {
                                    Position shadePos = basePos;
                                    if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                                    {
                                        shadePos.m_positionX = taerar->GetPositionX() + 20.0f * std::cos(basePos.GetOrientation() + M_PI / 4);
                                        shadePos.m_positionY = taerar->GetPositionY() + 20.0f * std::sin(basePos.GetOrientation() + M_PI / 4);
                                        shadePos.m_positionZ = taerar->GetPositionZ() + 10.0f;
                                        me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                    }
                                    float shadeDistance = me->GetExactDist(shadePos);
                                    if (shadeDistance > 10.0f)
                                    {
                                        actionDelay = 3000;
                                        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                        markPos = shadePos;
                                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                        return true;
                                    }
                                }
                            }
                            sb->Taunt(myShade);
                            sb->Tank(myShade, true);
                        }
                        else
                        {
                            myGroup->SetTargetIcon(5, me->GetGUID(), ObjectGuid());
                            if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                            {
                                if (activeTankOG == me->GetGUID())
                                {
                                    if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                                    {
                                        Position frontPos;
                                        taerar->GetNearPoint(me, frontPos.m_positionX, frontPos.m_positionY, frontPos.m_positionZ, -5.0, engageAngle);
                                        if (me->GetExactDist(frontPos) > 1.0f)
                                        {
                                            actionDelay = 3000;
                                            markPos = frontPos;
                                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
            {
                if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                {
                    if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                    {
                        if (myShade->IsAlive())
                        {
                            if (myShade->GetTarget() == me->GetGUID())
                            {
                                bool move = true;
                                //if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                                //{
                                //    if (shade7->IsAlive())
                                //    {
                                //        move = false;
                                //    }
                                //}
                                //if (move)
                                //{
                                //    if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                                //    {
                                //        if (shade5->IsAlive())
                                //        {
                                //            move = false;
                                //        }
                                //    }
                                //}
                                if (move)
                                {
                                    Position shadePos = basePos;
                                    if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                                    {
                                        shadePos.m_positionX = taerar->GetPositionX() + 20.0f * std::cos(basePos.GetOrientation() + M_PI / 4);
                                        shadePos.m_positionY = taerar->GetPositionY() + 20.0f * std::sin(basePos.GetOrientation() + M_PI / 4);
                                        shadePos.m_positionZ = taerar->GetPositionZ() + 10.0f;
                                        me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                    }
                                    float shadeDistance = me->GetExactDist(shadePos);
                                    if (shadeDistance > 10.0f)
                                    {
                                        actionDelay = 3000;
                                        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                        markPos = shadePos;
                                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                        return true;
                                    }
                                }
                            }
                            sb->Taunt(myShade);
                            sb->Tank(myShade, true);
                        }
                        else
                        {
                            myGroup->SetTargetIcon(6, me->GetGUID(), ObjectGuid());
                            if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                            {
                                if (activeTankOG == me->GetGUID())
                                {
                                    if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                                    {
                                        Position frontPos;
                                        taerar->GetNearPoint(me, frontPos.m_positionX, frontPos.m_positionY, frontPos.m_positionZ, -5.0, engageAngle);
                                        if (me->GetExactDist(frontPos) > 1.0f)
                                        {
                                            actionDelay = 3000;
                                            markPos = frontPos;
                                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
            {
                if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                {
                    if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                    {
                        if (myShade->IsAlive())
                        {
                            if (myShade->GetTarget() == me->GetGUID())
                            {
                                Position shadePos = basePos;
                                if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                                {
                                    shadePos.m_positionX = taerar->GetPositionX() + 20.0f * std::cos(basePos.GetOrientation() + M_PI / 4);
                                    shadePos.m_positionY = taerar->GetPositionY() + 20.0f * std::sin(basePos.GetOrientation() + M_PI / 4);
                                    shadePos.m_positionZ = taerar->GetPositionZ() + 10.0f;
                                    me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                }
                                float shadeDistance = me->GetExactDist(shadePos);
                                if (shadeDistance > 10.0f)
                                {
                                    actionDelay = 3000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    markPos = shadePos;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(myShade);
                            sb->Tank(myShade, true);
                        }
                        else
                        {
                            myGroup->SetTargetIcon(7, me->GetGUID(), ObjectGuid());
                            if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
                            {
                                float currentDistance = me->GetDistance(taerar);
                                if (currentDistance < 35.0f || currentDistance > 40.0f)
                                {
                                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
            {
                if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                {
                    if (shade7->IsAlive())
                    {
                        if (sb->DPS(shade7, true, false, NULL))
                        {
                            return true;
                        }
                    }
                }
                if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                {
                    if (activeTank->IsAlive())
                    {
                        if (activeTank->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1)
                        {
                            if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                            {
                                if (shade5->IsAlive())
                                {
                                    if (sb->DPS(shade5, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                            if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                            {
                                if (shade6->IsAlive())
                                {
                                    if (sb->DPS(shade6, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                            {
                                if (shade6->IsAlive())
                                {
                                    if (sb->DPS(shade6, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                            if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                            {
                                if (shade5->IsAlive())
                                {
                                    if (sb->DPS(shade5, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
            {
                if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                {
                    if (shade7->IsAlive())
                    {
                        if (sb->DPS(shade7, true, false, NULL))
                        {
                            return true;
                        }
                    }
                }
                if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                {
                    if (activeTank->IsAlive())
                    {
                        if (activeTank->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1)
                        {
                            if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                            {
                                if (shade5->IsAlive())
                                {
                                    if (sb->DPS(shade5, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                            if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                            {
                                if (shade6->IsAlive())
                                {
                                    if (sb->DPS(shade6, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                            {
                                if (shade6->IsAlive())
                                {
                                    if (sb->DPS(shade6, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                            if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                            {
                                if (shade5->IsAlive())
                                {
                                    if (sb->DPS(shade5, true, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
        if (Unit* taerar = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
        {
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (taerar->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = taerar->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, taerar->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(taerar->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = taerar->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(taerar);
                            sb->Tank(taerar, false);
                        }
                        else
                        {
                            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                            {
                                if (tank2->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank2->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (taerar->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            taerar->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, taerar->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                return true;
                            }
                            sb->SubTank(taerar, false);
                        }
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                        {
                            if (tank2->IsAlive())
                            {
                                if (!tank2->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                        myGroup->SetTargetIcon(0, me->GetGUID(), me->GetGUID());
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (taerar->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = taerar->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, taerar->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(taerar->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = taerar->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(taerar);
                            sb->Tank(taerar, false);
                        }
                        else
                        {
                            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                            {
                                if (tank1->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank1->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (taerar->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            taerar->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, taerar->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                                return true;
                            }
                            sb->SubTank(taerar, false);
                        }
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                        {
                            if (tank1->IsAlive())
                            {
                                if (!tank1->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
            {
                float currentDistance = me->GetDistance(taerar);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
            {
                float currentDistance = me->GetDistance(taerar);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
            {
                float currentDistance = me->GetDistance(taerar);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
        std::unordered_map<ObjectGuid, Unit*> dementedDruidMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Demented_Druid);
        if (dementedDruidMap.size() > 0)
        {
            if (me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3 || me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4 || me->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5)
            {
                if (dementedDruidMap.find(me->GetTarget()) != dementedDruidMap.end())
                {
                    if (Unit* myDruid = me->GetSelectedUnit())
                    {
                        if (myDruid->GetTarget() != me->GetGUID())
                        {
                            sb->Taunt(me->GetSelectedUnit());
                            if (sb->Tank(me->GetSelectedUnit(), true))
                            {
                                return true;
                            }
                        }
                    }
                }
                for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
                {
                    if (Unit* eachDD = ddIT->second)
                    {
                        if (Player* ddTarget = ObjectAccessor::GetPlayer(*me, eachDD->GetTarget()))
                        {
                            if (ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7 || ddTarget->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8)
                            {
                                sb->Taunt(eachDD);
                                if (sb->Tank(eachDD, true))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
                {
                    if (Unit* eachDD = ddIT->second)
                    {
                        sb->Taunt(eachDD);
                        if (sb->Tank(eachDD, true))
                        {
                            return true;
                        }
                    }
                }
            }
            return true;
        }
        if (Unit* ysondre = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Ysondre))
        {
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (ysondre->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = ysondre->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, ysondre->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(ysondre->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = ysondre->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(ysondre);
                            sb->Tank(ysondre, false);
                        }
                        else
                        {
                            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                            {
                                if (tank2->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank2->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (ysondre->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            ysondre->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, ysondre->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                return true;
                            }
                            sb->SubTank(ysondre, false);
                        }
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                        {
                            if (tank2->IsAlive())
                            {
                                if (!tank2->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                        myGroup->SetTargetIcon(0, me->GetGUID(), me->GetGUID());
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (ysondre->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = ysondre->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, ysondre->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(ysondre->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = ysondre->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(ysondre);
                            sb->Tank(ysondre, false);
                        }
                        else
                        {
                            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                            {
                                if (tank1->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank1->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (ysondre->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            ysondre->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, ysondre->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                                return true;
                            }
                            sb->SubTank(ysondre, false);
                        }
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                        {
                            if (tank1->IsAlive())
                            {
                                if (!tank1->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
            {
                float currentDistance = me->GetDistance(ysondre);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
            {
                float currentDistance = me->GetDistance(ysondre);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
            {
                float currentDistance = me->GetDistance(ysondre);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
        if (Unit* lethon = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Lethon))
        {
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (lethon->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = lethon->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, lethon->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(lethon->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = lethon->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(lethon);
                            sb->Tank(lethon, false);
                        }
                        else
                        {
                            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                            {
                                if (tank2->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank2->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (lethon->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            lethon->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, lethon->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                return true;
                            }
                            sb->SubTank(lethon, false);
                        }
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                        {
                            if (tank2->IsAlive())
                            {
                                if (!tank2->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                        myGroup->SetTargetIcon(0, me->GetGUID(), me->GetGUID());
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        bool tanking = true;
                        if (me->GetAuraCount(24818) >= 3)
                        {
                            tanking = false;
                        }
                        if (tanking)
                        {
                            if (lethon->GetTarget() == me->GetGUID())
                            {
                                float baseDistance = lethon->GetExactDist(basePos);
                                if (baseDistance > 50.0f)
                                {
                                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, baseDistance + 20.0f, lethon->GetAbsoluteAngle(basePos));
                                    actionDelay = 10000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                    return true;
                                }
                                float extDistance = me->GetExactDist(lethon->GetPosition());
                                bool move = false;
                                if (extDistance < 14.0f)
                                {
                                    move = true;
                                }
                                else if (extDistance < 20.0f)
                                {
                                    float taerarAngle = lethon->GetOrientation();
                                    if (taerarAngle < engageAngle - M_PI / 8 || taerarAngle > engageAngle + M_PI / 8)
                                    {
                                        move = true;
                                    }
                                }
                                if (move)
                                {
                                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, -5.0f, engageAngle);
                                    actionDelay = 5000;
                                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                    return true;
                                }
                            }
                            sb->Taunt(lethon);
                            sb->Tank(lethon, false);
                        }
                        else
                        {
                            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                            {
                                if (tank1->IsAlive())
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank1->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (lethon->GetTarget() != me->GetGUID())
                        {
                            Position sidePos;
                            lethon->GetNearPoint(me, sidePos.m_positionX, sidePos.m_positionY, sidePos.m_positionZ, -5.0f, lethon->GetOrientation() + sideAngle);
                            if (me->GetExactDist(sidePos) > 1.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                markPos = sidePos;
                                actionDelay = 5000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                                return true;
                            }
                            sb->SubTank(lethon, false);
                        }
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                        {
                            if (tank1->IsAlive())
                            {
                                if (!tank1->HasAura(24778))
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3:
            {
                float currentDistance = me->GetDistance(lethon);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank4:
            {
                float currentDistance = me->GetDistance(lethon);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank5:
            {
                float currentDistance = me->GetDistance(lethon);
                if (currentDistance < 35.0f || currentDistance > 40.0f)
                {
                    lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 37.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
    }
    return RobotStrategy_Group::Tank();
}

bool RobotStrategy_Group_EmeraldDragon::Tank(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1:
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

bool RobotStrategy_Group_EmeraldDragon::Heal()
{
    if (me->HasAura(24778))
    {
        return true;
    }
    //if (Creature* dreamFog = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog))
    //{
    //    if (me->GetDistance(dreamFog) < 5.0f)
    //    {
    //        if (urand(0, 1) == 0)
    //        {
    //            engageAngle = engageAngle - M_PI / 16;
    //        }
    //        else
    //        {
    //            engageAngle = engageAngle + M_PI / 16;
    //        }
    //        Position dodgePos;
    //        float currentDistance = me->GetExactDist(basePos);
    //        dodgePos.m_positionX = basePos.m_positionX + currentDistance * std::cos(engageAngle);
    //        dodgePos.m_positionY = basePos.m_positionY + currentDistance * std::sin(engageAngle);
    //        dodgePos.m_positionZ = basePos.m_positionZ + 10.0f;
    //        me->UpdateAllowedPositionZ(dodgePos.m_positionX, dodgePos.m_positionY, dodgePos.m_positionZ);
    //        markPos = dodgePos;
    //        actionDelay = 10000;
    //        actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
    //        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(basePos));
    //    }
    //}
    if (Group* myGroup = me->GetGroup())
    {
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            if (Creature* taerar = GetNearbyCreature(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
            {
                float taeraDistance = me->GetDistance(taerar);
                if (taeraDistance < 30.0f)
                {
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, taerar->GetAbsoluteAngle(me->GetPosition()));
                    actionDelay = 2000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                    return true;
                }
            }
        }
        if (Unit* taerar = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Taerar))
        {
            float taeraDistance = me->GetDistance(taerar);
            if (taeraDistance < 30.0f)
            {
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, taerar->GetAbsoluteAngle(me->GetPosition()));
                actionDelay = 2000;
                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                return true;
            }
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            bool move = false;
                            float currentDistance = me->GetExactDist(rs->markPos);
                            float currentAngle = rs->markPos.GetAbsoluteAngle(me->GetPosition());
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                move = true;
                            }
                            else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                            {
                                move = true;
                            }
                            if (move)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
            {
                bool move = false;
                float currentDistance = me->GetDistance(taerar);
                float currentAngle = taerar->GetAbsoluteAngle(me->GetPosition());
                if (currentDistance < 30.0f || currentDistance > 35.0f)
                {
                    move = true;
                }
                else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                {
                    move = true;
                }
                if (move)
                {
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                    return true;
                }
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
            {
                bool move = false;
                float currentDistance = me->GetDistance(taerar);
                float currentAngle = taerar->GetAbsoluteAngle(me->GetPosition());
                if (currentDistance < 30.0f || currentDistance > 35.0f)
                {
                    move = true;
                }
                else if (currentAngle<engageAngle - M_PI / 16 || currentAngle>engageAngle + M_PI / 16)
                {
                    move = true;
                }
                if (move)
                {
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    taerar->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, engageAngle);
                    actionDelay = 5000;
                    actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(taerar->GetPosition()));
                    return true;
                }
            }
            default:
            {
                break;
            }
            }
        }
        if (Unit* ysondre = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Ysondre))
        {
            float ysondreDistance = me->GetDistance(ysondre);
            if (ysondreDistance < 30.0f)
            {
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                ysondre->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, ysondre->GetAbsoluteAngle(me->GetPosition()));
                actionDelay = 2000;
                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(ysondre->GetPosition()));
                return true;
            }
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
            {
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
            {
                break;
            }
            default:
            {
                break;
            }
            }
        }
        if (Unit* lethon = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Lethon))
        {
            float bossDistance = me->GetDistance(lethon);
            if (bossDistance < 30.0f)
            {
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                lethon->GetNearPoint(me, markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ, 33.0f, lethon->GetAbsoluteAngle(me->GetPosition()));
                actionDelay = 2000;
                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(lethon->GetPosition()));
                return true;
            }
            switch (me->groupRole)
            {
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank1->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank1->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (RobotStrategy_Group_EmeraldDragon* rs = (RobotStrategy_Group_EmeraldDragon*)tank2->rai->GetActiveStrategy(RobotStrategyType::RobotStrategyType_Group))
                        {
                            float currentDistance = me->GetExactDist(rs->markPos);
                            if (currentDistance < 37.0f || currentDistance > 40.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                //markPos.m_positionX = rs->markPos.m_positionX + 37.0f * std::cos(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                //markPos.m_positionY = rs->markPos.m_positionY + 37.0f * std::sin(rs->markPos.GetAbsoluteAngle(me->GetPosition()));
                                markPos.m_positionX = rs->markPos.m_positionX + 38.0f * std::cos(engageAngle);
                                markPos.m_positionY = rs->markPos.m_positionY + 38.0f * std::sin(engageAngle);
                                markPos.m_positionZ = rs->markPos.m_positionZ + 10.0f;
                                me->UpdateAllowedPositionZ(markPos.m_positionX, markPos.m_positionY, markPos.m_positionZ);
                                actionDelay = 2000;
                                actionType = ActionType_EmeraldDragon::ActionType_EmeraldDragon_MarkMove;
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(tank2->GetPosition()));
                                return true;
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
            {
                break;
            }
            case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
            {
                break;
            }
            default:
            {
                break;
            }
            }
        }
        switch (me->groupRole)
        {
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1:
        {
            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
            {
                if (tank1->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(1))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank1, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2))
                                {
                                    bool healerReady = true;
                                    if (healer2->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer2->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer2->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer2->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3))
                                {
                                    bool healerReady = true;
                                    if (healer3->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer3->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer3->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank1))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                                    {
                                        if (tank2->IsAlive())
                                        {
                                            if (tank2->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank2, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                if (!activeHealer->HasAura(24818))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(1, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2:
        {
            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
            {
                if (tank1->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(1))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank1, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3))
                                {
                                    bool healerReady = true;
                                    if (healer3->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer3->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer3->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1))
                                {
                                    bool healerReady = true;
                                    if (healer1->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer1->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer1->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer1->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank1))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                                    {
                                        if (tank2->IsAlive())
                                        {
                                            if (tank2->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank2, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(1, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer3:
        {
            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
            {
                if (tank1->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(1))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank1, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer1))
                                {
                                    bool healerReady = true;
                                    if (healer1->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer1->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer1->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer1->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer2))
                                {
                                    bool healerReady = true;
                                    if (healer2->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer2->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer2->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer2->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank1->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank1))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
                                    {
                                        if (tank2->IsAlive())
                                        {
                                            if (tank2->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank2, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(1, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4:
        {
            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
            {
                if (tank2->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(2))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank2, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer5 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5))
                                {
                                    bool healerReady = true;
                                    if (healer5->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer5->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer5->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer6 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6))
                                {
                                    bool healerReady = true;
                                    if (healer6->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer6->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer6->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank2))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                                    {
                                        if (tank1->IsAlive())
                                        {
                                            if (tank1->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank1, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(2, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5:
        {
            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
            {
                if (tank2->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(2))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank2, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer6 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6))
                                {
                                    bool healerReady = true;
                                    if (healer6->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer6->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer6->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer4 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4))
                                {
                                    bool healerReady = true;
                                    if (healer4->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer4->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer4->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer4->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank2))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                                    {
                                        if (tank1->IsAlive())
                                        {
                                            if (tank1->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank1, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(2, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer6:
        {
            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2))
            {
                if (tank2->IsAlive())
                {
                    if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(2))
                    {
                        if (activeHealerOG == me->GetGUID())
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank2, true))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                            else
                            {
                                if (Player* healer4 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer4))
                                {
                                    bool healerReady = true;
                                    if (healer4->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer4->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer4->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer4->GetGUID());
                                        return true;
                                    }
                                }
                                if (Player* healer5 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer5))
                                {
                                    bool healerReady = true;
                                    if (healer5->HasAura(24778))
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer5->GetPower(Powers::POWER_MANA) < 500)
                                    {
                                        healerReady = false;
                                    }
                                    else if (healer5->HasAura(24818))
                                    {
                                        healerReady = false;
                                    }
                                    if (healerReady)
                                    {
                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                        return true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool healing = true;
                            if (me->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healing = false;
                            }
                            else if (me->HasAura(24818))
                            {
                                healing = false;
                            }
                            if (healing)
                            {
                                if (tank2->GetHealthPct() < 90.0f)
                                {
                                    if (sb->SubHeal(tank2))
                                    {
                                        return true;
                                    }
                                }
                                if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                {
                                    if (Player* tank1 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1))
                                    {
                                        if (tank1->IsAlive())
                                        {
                                            if (tank1->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank1, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                    if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                                    {
                                        if (tank3->IsAlive())
                                        {
                                            if (tank3->GetHealthPct() < 50.0f)
                                            {
                                                if (sb->Heal(tank3, true))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (me->GetHealthPct() < 50.0f)
                                {
                                    if (sb->Heal(me, true))
                                    {
                                        return true;
                                    }
                                }
                                if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                                {
                                    if (activeHealer->IsAlive())
                                    {
                                        if (!activeHealer->HasAura(24778))
                                        {
                                            if (!activeHealer->HasAura(24818))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                                myGroup->SetTargetIcon(2, me->GetGUID(), me->GetGUID());
                            }
                        }
                    }
                    return true;
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7:
        {
            if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
            {
                if (activeHealerOG == me->GetGUID())
                {
                    bool healing = true;
                    if (me->GetPower(Powers::POWER_MANA) < 500)
                    {
                        healing = false;
                    }
                    else if (me->HasAura(24818))
                    {
                        healing = false;
                    }
                    if (healing)
                    {
                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                        {
                            if (tank3->IsAlive())
                            {
                                if (tank3->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank3, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                        {
                            if (Player* member = groupRef->GetSource())
                            {
                                if (member->IsAlive())
                                {
                                    if (member->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank1 || member->groupRole == GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank2)
                                    {
                                        continue;
                                    }
                                    if (member->GetHealthPct() < 50.0f)
                                    {
                                        if (sb->Heal(member, true))
                                        {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                        if (me->GetHealthPct() < 50.0f)
                        {
                            if (sb->Heal(me, true))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        if (Player* healer8 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8))
                        {
                            bool healerReady = true;
                            if (healer8->HasAura(24778))
                            {
                                healerReady = false;
                            }
                            else if (healer8->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healerReady = false;
                            }
                            else if (healer8->HasAura(24818))
                            {
                                healerReady = false;
                            }
                            if (healerReady)
                            {
                                myGroup->SetTargetIcon(3, me->GetGUID(), healer8->GetGUID());
                                return true;
                            }
                        }
                    }
                }
                else
                {
                    bool healing = true;
                    if (me->GetPower(Powers::POWER_MANA) < 500)
                    {
                        healing = false;
                    }
                    else if (me->HasAura(24818))
                    {
                        healing = false;
                    }
                    if (healing)
                    {
                        if (me->GetHealthPct() < 50.0f)
                        {
                            if (sb->Heal(me, true))
                            {
                                return true;
                            }
                        }
                        if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                        {
                            if (activeHealer->IsAlive())
                            {
                                if (!activeHealer->HasAura(24778))
                                {
                                    if (!activeHealer->HasAura(24818))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        myGroup->SetTargetIcon(3, me->GetGUID(), me->GetGUID());
                    }
                }
            }
            break;
        }
        case GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer8:
        {
            if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
            {
                if (activeHealerOG == me->GetGUID())
                {
                    bool healing = true;
                    if (me->GetPower(Powers::POWER_MANA) < 500)
                    {
                        healing = false;
                    }
                    else if (me->HasAura(24818))
                    {
                        healing = false;
                    }
                    if (healing)
                    {
                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Tank3))
                        {
                            if (tank3->IsAlive())
                            {
                                if (tank3->GetHealthPct() < 90.0f)
                                {
                                    if (sb->Heal(tank3, true))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        if (me->GetHealthPct() < 50.0f)
                        {
                            if (sb->Heal(me, true))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        if (Player* healer7 = GetPlayerByGroupRole(GroupRole_EmeraldDragon::GroupRole_EmeraldDragon_Healer7))
                        {
                            bool healerReady = true;
                            if (healer7->HasAura(24778))
                            {
                                healerReady = false;
                            }
                            else if (healer7->GetPower(Powers::POWER_MANA) < 500)
                            {
                                healerReady = false;
                            }
                            else if (healer7->HasAura(24818))
                            {
                                healerReady = false;
                            }
                            if (healerReady)
                            {
                                myGroup->SetTargetIcon(3, me->GetGUID(), healer7->GetGUID());
                                return true;
                            }
                        }
                    }
                }
                else
                {
                    bool healing = true;
                    if (me->GetPower(Powers::POWER_MANA) < 500)
                    {
                        healing = false;
                    }
                    else if (me->HasAura(24818))
                    {
                        healing = false;
                    }
                    if (healing)
                    {
                        if (me->GetHealthPct() < 50.0f)
                        {
                            if (sb->Heal(me, true))
                            {
                                return true;
                            }
                        }
                        if (Player* activeHealer = ObjectAccessor::GetPlayer(*me, activeHealerOG))
                        {
                            if (activeHealer->IsAlive())
                            {
                                if (!activeHealer->HasAura(24778))
                                {
                                    if (!activeHealer->HasAura(24818))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                        myGroup->SetTargetIcon(3, me->GetGUID(), me->GetGUID());
                    }
                }
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }

    return RobotStrategy_Group::Heal();
}
