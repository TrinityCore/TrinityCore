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
    else if (commandName == "prepare")
    {
        sb->Prepare();
        sb->WhisperTo("I am prepared", Language::LANG_UNIVERSAL, pmSender);
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
    aoeDelay = sRobotConfig->AOEDelay;
    dpsDelay = sRobotConfig->DPSDelay;
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

void RobotStrategy_Group::Update(uint32 pmDiff)
{
    if (!me)
    {
        return;
    }
    sb->Update(pmDiff);
    if (Group* myGroup = me->GetGroup())
    {
        if (!me->GetSession()->isRobotSession)
        {
            return;
        }
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
                        me->SpawnCorpseBones();
                    }
                    me->ClearInCombat();
                    me->TeleportTo(leaderPlayer->GetWorldLocation());
                    sb->WhisperTo("I have come", Language::LANG_UNIVERSAL, leaderPlayer);
                }
            }
        }
        if (moveDelay > 0)
        {
            moveDelay -= pmDiff;
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
                if (sb->DPS(engageTarget, !holding, false, NULL))
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
                if (sb->Tank(engageTarget, !holding))
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
                    if (member->groupRole == pmGroupRole)
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
        return sb->Tank(pmTarget, !holding);
    }
    case GroupRole::GroupRole_DPS:
    {
        return sb->DPS(pmTarget, !holding, false, NULL);
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
            if (sb->DPS(mainTank->GetSelectedUnit(), !holding, aoe, mainTank))
            {
                return true;
            }
        }
        Unit* closestVictim = NULL;
        float closestDistance = ATTACK_RANGE_LIMIT;
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
                                float eachAttackerDistance = me->GetDistance(eachAttacker);
                                if (eachAttackerDistance < closestDistance)
                                {
                                    closestVictim = eachAttacker;
                                    closestDistance = eachAttackerDistance;
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
                                        float eachAttackerDistance = me->GetDistance(eachAttacker);
                                        if (eachAttackerDistance < closestDistance)
                                        {
                                            closestVictim = eachAttacker;
                                            closestDistance = eachAttackerDistance;
                                        }
                                    }
                                }
                            }
                        }
                    }            
                }
            }
        }
        if (sb->DPS(me->GetSelectedUnit(), !holding, aoe, mainTank))
        {
            return true;
        }
        if (sb->DPS(closestVictim, !holding, aoe, mainTank))
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
                    if (sb->Tank(myTarget, !holding))
                    {
                        return true;
                    }
                }
            }
        }
    }
    Unit* closestVictim = NULL;
    float closestDistance = ATTACK_RANGE_LIMIT;
    if (Group* myGroup = me->GetGroup())
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                {
                    if (Unit* eachAttacker = *attackerIT)
                    {
                        // tank can only cover 30.0f range
                        if (me->GetDistance(eachAttacker) < RANGED_MAX_DISTANCE)
                        {
                            if (eachAttacker->GetTarget() != me->GetGUID())
                            {
                                sb->Taunt(eachAttacker);
                                if (sb->Tank(eachAttacker, !holding))
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
                if (Pet* memberPet = member->GetPet())
                {
                    if (memberPet->IsAlive())
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                        {
                            if (Unit* eachAttacker = *attackerIT)
                            {
                                // tank can only cover 30.0f range
                                if (me->GetDistance(eachAttacker) < RANGED_MAX_DISTANCE)
                                {
                                    if (eachAttacker->GetTarget() != me->GetGUID())
                                    {
                                        sb->Taunt(eachAttacker);
                                        if (sb->Tank(eachAttacker, !holding))
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
                    }
                }
            }
        }
    }

    if (Unit* myTarget = me->GetSelectedUnit())
    {
        if (me->IsValidAttackTarget(myTarget))
        {
            if (sb->Tank(myTarget, !holding))
            {
                return true;
            }
        }
    }
    if (sb->Tank(closestVictim, !holding))
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
        return sb->Tank(pmTarget, !holding);
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

std::unordered_map<ObjectGuid, Unit*> RobotStrategy_Group::GetAddsMap(uint32 pmBossEntry)
{
    std::unordered_map<ObjectGuid, Unit*> addsMap;
    addsMap.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                    {
                        if (Unit* eachAttacker = *attackerIT)
                        {
                            if (eachAttacker->GetEntry() != pmBossEntry)
                            {
                                if (addsMap.find(eachAttacker->GetGUID()) == addsMap.end())
                                {
                                    addsMap[eachAttacker->GetGUID()] = eachAttacker;
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
                                    if (eachAttacker->GetEntry() != pmBossEntry)
                                    {
                                        if (addsMap.find(eachAttacker->GetGUID()) == addsMap.end())
                                        {
                                            addsMap[eachAttacker->GetGUID()] = eachAttacker;
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

    return addsMap;
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
                    for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                    {
                        if (Unit* eachAttacker = *attackerIT)
                        {
                            if (attackerMap.find(eachAttacker->GetGUID()) == attackerMap.end())
                            {
                                attackerMap[eachAttacker->GetGUID()] = eachAttacker;
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

    return attackerMap;
}

std::unordered_map<uint32, Unit*> RobotStrategy_Group::GetBossMap()
{
    std::unordered_map<uint32, Unit*> bossMap;
    bossMap.clear();
    if (me)
    {
        if (Group* myGroup = me->GetGroup())
        {
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                if (Player* member = groupRef->GetSource())
                {
                    for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                    {
                        if (Unit* eachAttacker = *attackerIT)
                        {
                            bool isBoss = false;
                            if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath)
                            {
                                isBoss = true;
                            }
                            else if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth)
                            {
                                isBoss = true;
                            }
                            else if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend)
                            {
                                isBoss = true;
                            }
                            if (isBoss)
                            {
                                if (bossMap.find(eachAttacker->GetEntry()) == bossMap.end())
                                {
                                    bossMap[eachAttacker->GetEntry()] = eachAttacker;
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
                                    bool isBoss = false;
                                    if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath)
                                    {
                                        isBoss = true;
                                    }
                                    else if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth)
                                    {
                                        isBoss = true;
                                    }
                                    else if (eachAttacker->GetEntry() == CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend)
                                    {
                                        isBoss = true;
                                    }
                                    if (isBoss)
                                    {
                                        if (bossMap.find(eachAttacker->GetEntry()) == bossMap.end())
                                        {
                                            bossMap[eachAttacker->GetEntry()] = eachAttacker;
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

    return bossMap;
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
    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_None;
    actionDelay = 0;
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
    std::unordered_map<uint32, Unit*> bossMap = GetBossMap();
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth) != bossMap.end())
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
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath) != bossMap.end())
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
    if (combatTime > dpsDelay)
    {
        if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth) != bossMap.end())
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
                    actionDelay = 3000;
                    return true;
                }
                if (sb->DPS(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth], !holding, false, NULL))
                {
                    return true;
                }
            }
        }
        if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath) != bossMap.end())
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
                if (sb->DPS(addsTank->GetSelectedUnit(), !holding, false, NULL))
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
    std::unordered_map<uint32, Unit*> bossMap = GetBossMap();
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth) != bossMap.end())
    {
        if (me->GetDistance(dpsGythPos) > 3.0f)
        {
            actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
            actionDelay = 3000;
            return true;
        }
    }
    else if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath) != bossMap.end())
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
        return sb->DPS(pmTarget, !holding, false, NULL);
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
        return sb->Tank(pmTarget, !holding);
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
    std::unordered_map<uint32, Unit*> bossMap = GetBossMap();
    Player* mainTank = GetMainTank();
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth) != bossMap.end())
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth]->GetTarget() != me->GetGUID())
            {
                sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth]);
                if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth], !holding))
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
            sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth]);
            if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Gyth], !holding))
            {
                return true;
            }
        }
    }
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend) != bossMap.end())
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
        {
            if (bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend]->GetTarget() != me->GetGUID())
            {
                sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend]);
                if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend], !holding, true))
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
            sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend]);
            if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Rend], !holding, true))
            {
                return true;
            }
        }
    }
    if (bossMap.find(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath) != bossMap.end())
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            if (bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]->GetTarget() != me->GetGUID())
            {
                sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]);
                if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath], !holding, true))
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
            sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]);
            if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath], !holding, true))
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
                if (bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]->GetTarget() != me->GetGUID())
                {
                    sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]);
                    if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath], !holding, true))
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
                sb->Taunt(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]);
                if (sb->Tank(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath], !holding, true))
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
                if (!me->isInFront(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]))
                {
                    me->SetFacingToObject(bossMap[CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath]);
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
            std::unordered_map<ObjectGuid, Unit*> addsMap = GetAddsMap(CreatureEntry_Blackrock_Spire::CreatureEntry_Blackrock_Spire_Drakkisath);
            if (addsMap.size() > 0)
            {
                Unit* closestAdds = NULL;
                float closestAddsDistance = ATTACK_RANGE_LIMIT;
                for (std::unordered_map<ObjectGuid, Unit*>::iterator addsIT = addsMap.begin(); addsIT != addsMap.end(); addsIT++)
                {
                    if (addsIT->second->GetTarget() != me->GetGUID())
                    {
                        sb->Taunt(addsIT->second);
                        if (sb->Tank(addsIT->second, !holding))
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
                        if (sb->Tank(myTarget, !holding))
                        {
                            return true;
                        }
                    }
                }
                sb->Taunt(closestAdds);
                if (sb->Tank(closestAdds, !holding))
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
    if (!me)
    {
        return;
    }
    sb->Update(pmDiff);
    if (Group* myGroup = me->GetGroup())
    {
        if (!me->GetSession()->isRobotSession)
        {
            return;
        }
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
                        me->SpawnCorpseBones();
                    }
                    me->ClearInCombat();
                    me->TeleportTo(leaderPlayer->GetWorldLocation());
                    sb->WhisperTo("I have come", Language::LANG_UNIVERSAL, leaderPlayer);
                }
            }
        }
        if (moveDelay > 0)
        {
            moveDelay -= pmDiff;
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
                if (sb->DPS(engageTarget, !holding, false, NULL))
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
                if (sb->Tank(engageTarget, !holding))
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
                if (sb->Tank(engageTarget, !holding))
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
                if (sb->Tank(engageTarget, !holding))
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
                if (eachAttacker->GetEntry() == CreatureEntry_Alcaz_Island::CreatureEntry_Alcaz_Island_Doctor_Weavil)
                {
                    if (sb->DPS(eachAttacker, !holding, false, NULL))
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
                        if (eachAttacker->GetEntry() == CreatureEntry_Alcaz_Island::CreatureEntry_Alcaz_Island_Doctor_Weavil)
                        {
                            if (sb->DPS(eachAttacker, !holding, false, NULL))
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
            if (eachAttacker->GetEntry() == CreatureEntry_Alcaz_Island::CreatureEntry_Alcaz_Island_Doctor_Weavil)
            {
                if (sb->Tank(eachAttacker, !holding, true))
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
                    if (eachAttacker->GetEntry() == CreatureEntry_Alcaz_Island::CreatureEntry_Alcaz_Island_Doctor_Weavil)
                    {
                        if (sb->Tank(eachAttacker, !holding, true))
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
