#include "Strategy_Raid.h"
#include "RobotManager.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "MotionMaster.h"
#include "Pet.h"
#include "GridNotifiers.h"
#include "GroupMgr.h"
#include "FollowMovementGenerator.h"
#include "Map.h"
#include "SpellMgr.h"
#include "ThreatManager.h"

Strategy_Raid::Strategy_Raid(uint32 pmID)
{
    realPrevTime = 0;
    raidID = pmID;
    raidCombatTime = 0;
    memberMap.clear();
}

void Strategy_Raid::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    if (RaidInCombat())
    {
        raidCombatTime += diff;
    }
    else
    {
        raidCombatTime = 0;
    }

    if (Group* raid = sGroupMgr->GetGroupByGUID(raidID))
    {
        for (GroupReference* groupRef = raid->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (memberMap.find(member->GetGUID().GetCounter()) == memberMap.end())
            {
                RaidMember* pm = new RaidMember(member->GetGUID().GetCounter(), sRobotManager->IsRobot(member->GetGUID().GetCounter()));
                if (pm->isRobot)
                {
                    pm->sb->InitializeCharacter(member->GetLevel());
                }
                else
                {
                    pm->sb->InitializeValues();
                }
            }
        }
    }

    for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
    {
        if (Player* eachMember = ObjectAccessor::FindPlayerByLowGUID(pmIT->second->character))
        {
            if (Group* eachGroup = eachMember->GetGroup())
            {
                if (eachGroup->GetLowGUID() != raidID)
                {
                    delete memberMap[pmIT->second->character];
                    memberMap.erase(pmIT->second->character);
                }
            }
            else
            {
                delete memberMap[pmIT->second->character];
                memberMap.erase(pmIT->second->character);
            }
        }
        else
        {
            delete memberMap[pmIT->second->character];
            memberMap.erase(pmIT->second->character);
        }
    }

    std::unordered_map<uint32, std::unordered_map<uint32, RaidMember*>> roleMap;
    for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
    {
        if (pmIT->second->instruction.instructionType == RobotRaidInstructionType::RobotRaidInstructionType_None)
        {
            roleMap[pmIT->second->raidRole][pmIT->second->character] = pmIT->second;
        }
        else
        {
            // handle instruction
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                Unit* targetUnit = NULL;
                if (pmIT->second->instruction.targetOG.GetHigh() == HighGuid::Player)
                {
                    targetUnit = ObjectAccessor::FindConnectedPlayer(pmIT->second->instruction.targetOG);
                }
                else
                {
                    if (Map* currentMap = member->GetMap())
                    {
                        if (pmIT->second->instruction.targetOG.GetHigh() == HighGuid::Unit)
                        {
                            targetUnit = currentMap->GetCreature(pmIT->second->instruction.targetOG);
                        }
                    }
                }
                switch (pmIT->second->instruction.instructionType)
                {
                case RobotRaidInstructionType::RobotRaidInstructionType_Attack:
                {
                    if (pmIT->second->raidRole == RaidRole::RaidRole_Healer)
                    {
                        pmIT->second->instruction.Clear();
                    }
                    if (!pmIT->second->sb->Attack(targetUnit))
                    {
                        pmIT->second->instruction.Clear();
                    }
                    break;
                }
                case RobotRaidInstructionType::RobotRaidInstructionType_Engage:
                {
                    if (pmIT->second->raidRole == RaidRole::RaidRole_Healer)
                    {
                        pmIT->second->instruction.Clear();
                    }
                    if (!pmIT->second->sb->Attack(targetUnit))
                    {
                        pmIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_None;
                    }
                    else
                    {
                        if (targetUnit->CanHaveThreatList())
                        {
                            if (member->GetThreatManager().GetThreatenedByMeList().find(targetUnit->GetGUID()) != member->GetThreatManager().GetThreatenedByMeList().end())
                            {
                                pmIT->second->instruction.Clear();
                            }
                        }
                    }
                    break;
                }
                case RobotRaidInstructionType::RobotRaidInstructionType_Follow:
                {
                    if (!targetUnit)
                    {
                        pmIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_None;
                    }
                    else
                    {
                        if (member->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::FOLLOW_MOTION_TYPE)
                        {
                            FollowMovementGenerator* mg = (FollowMovementGenerator*)member->GetMotionMaster()->GetCurrentMovementGenerator();
                            if (mg)
                            {
                                if (mg->GetTarget())
                                {
                                    if (mg->GetTarget()->GetGUID() == targetUnit->GetGUID())
                                    {
                                        pmIT->second->instruction.Clear();
                                        break;
                                    }
                                }
                            }
                        }
                        member->StopMoving();
                        member->GetMotionMaster()->MoveFollow(targetUnit, pmIT->second->followDistance, ChaseAngle(0, 2 * M_PI));
                    }
                    break;
                }
                case RobotRaidInstructionType::RobotRaidInstructionType_Tank:
                {
                    if (pmIT->second->raidRole != RaidRole::RaidRole_Tank)
                    {
                        pmIT->second->instruction.Clear();
                    }
                    if (pmIT->second->raidRole != RaidRole::RaidRole_Tank)
                    {
                        pmIT->second->instruction.Clear();
                    }
                    else if (!pmIT->second->sb->Attack(targetUnit))
                    {
                        pmIT->second->instruction.Clear();
                    }
                    else
                    {
                        if (targetUnit->GetTarget() == member->GetGUID())
                        {
                            pmIT->second->instruction.Clear();

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
        }
    }

    if (roleMap.find(RaidRole::RaidRole_Healer) != roleMap.end())
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator healerIT = roleMap[RaidRole::RaidRole_Healer].begin(); healerIT != roleMap[RaidRole::RaidRole_Healer].end(); healerIT++)
        {
            if (!healerIT->second->isRobot)
            {
                continue;
            }
            ObjectGuid healerGUID = ObjectGuid(HighGuid::Player, healerIT->first);
            if (Player* healer = ObjectAccessor::FindConnectedPlayer(healerGUID))
            {
                if (healerIT->second->assembleDelay > 0)
                {
                    healerIT->second->assembleDelay -= diff;
                    if (healerIT->second->assembleDelay < 0)
                    {
                        if (Group* raid = sGroupMgr->GetGroupByGUID(raidID))
                        {
                            if (Player* master = ObjectAccessor::FindConnectedPlayer(raid->GetLeaderGUID()))
                            {
                                healer->GetThreatManager().ClearAllThreat();
                                if (!healer->IsAlive())
                                {
                                    healer->ResurrectPlayer(10.0f);
                                }
                                healer->TeleportTo(master->GetWorldLocation());
                                continue;
                            }
                        }
                    }
                }
                bool actioned = false;
                if (healer->IsInCombat())
                {
                    std::unordered_map<ObjectGuid, Unit*> otAttackers;
                    for (Unit::AttackerSet::const_iterator attackerIT = healer->getAttackers().begin(); attackerIT != healer->getAttackers().end(); attackerIT++)
                    {
                        if (Unit* eachAttacker = *attackerIT)
                        {
                            if (eachAttacker->GetTarget() == healerGUID)
                            {
                                otAttackers[eachAttacker->GetGUID()] = eachAttacker;
                            }
                        }
                    }
                    if (otAttackers.size() > 0)
                    {
                        if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                        {
                            for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                            {
                                tankIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_Tank;
                                tankIT->second->instruction.targetOG = otAttackers.begin()->first;
                            }
                        }
                    }
                    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                        {
                            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                            {
                                if (healerIT->second->sb->Heal(tank, healerIT->second->cure))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_DPS) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator dpsIT = roleMap[RaidRole::RaidRole_DPS].begin(); dpsIT != roleMap[RaidRole::RaidRole_DPS].end(); dpsIT++)
                        {
                            ObjectGuid dpsGUID = ObjectGuid(HighGuid::Player, dpsIT->first);
                            if (Player* dps = ObjectAccessor::FindConnectedPlayer(dpsGUID))
                            {
                                if (dps->GetHealthPct() < 40.0f)
                                {
                                    if (healerIT->second->sb->Heal(dps, healerIT->second->cure))
                                    {
                                        actioned = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (healerIT->second->restDelay > 0)
                    {
                        healerIT->second->restDelay -= diff;
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                        {
                            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                            {
                                if (healerIT->second->sb->Heal(tank, healerIT->second->cure))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_DPS) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator dpsIT = roleMap[RaidRole::RaidRole_DPS].begin(); dpsIT != roleMap[RaidRole::RaidRole_DPS].end(); dpsIT++)
                        {
                            ObjectGuid dpsGUID = ObjectGuid(HighGuid::Player, dpsIT->first);
                            if (Player* dps = ObjectAccessor::FindConnectedPlayer(dpsGUID))
                            {
                                if (dps->GetHealthPct() < 40.0f)
                                {
                                    if (healerIT->second->sb->Heal(dps, healerIT->second->cure))
                                    {
                                        actioned = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                        {
                            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                            {
                                if (healerIT->second->sb->Buff(tank, healerIT->second->cure))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_DPS) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator dpsIT = roleMap[RaidRole::RaidRole_DPS].begin(); dpsIT != roleMap[RaidRole::RaidRole_DPS].end(); dpsIT++)
                        {
                            ObjectGuid dpsGUID = ObjectGuid(HighGuid::Player, dpsIT->first);
                            if (Player* dps = ObjectAccessor::FindConnectedPlayer(dpsGUID))
                            {
                                if (healerIT->second->sb->Buff(dps, healerIT->second->cure))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                        {
                            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                            {
                                if (healerIT->second->sb->Follow(tank, healerIT->second->followDistance))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (roleMap.find(RaidRole::RaidRole_DPS) != roleMap.end())
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator dpsIT = roleMap[RaidRole::RaidRole_DPS].begin(); dpsIT != roleMap[RaidRole::RaidRole_DPS].end(); dpsIT++)
        {
            ObjectGuid dpsGUID = ObjectGuid(HighGuid::Player, dpsIT->first);
            if (Player* dps = ObjectAccessor::FindConnectedPlayer(dpsGUID))
            {
                if (!dpsIT->second->isRobot)
                {
                    continue;
                }
                bool actioned = false;
                if (dps->IsInCombat())
                {
                    std::unordered_map<ObjectGuid, Unit*> otAttackers;
                    for (Unit::AttackerSet::const_iterator attackerIT = dps->getAttackers().begin(); attackerIT != dps->getAttackers().end(); attackerIT++)
                    {
                        if (Unit* eachAttacker = *attackerIT)
                        {
                            if (eachAttacker->GetTarget() == dpsGUID)
                            {
                                otAttackers[eachAttacker->GetGUID()] = eachAttacker;
                            }
                        }
                    }
                    if (otAttackers.size() > 0)
                    {
                        if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                        {
                            for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                            {
                                tankIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_Tank;
                                tankIT->second->instruction.targetOG = otAttackers.begin()->first;
                            }
                        }
                    }
                    if (raidCombatTime > dpsIT->second->dpsDelay)
                    {
                        if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                        {
                            for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                            {
                                ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                                if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                                {
                                    if (Unit* tankVictim = tank->GetVictim())
                                    {
                                        if (dpsIT->second->sb->DPS(tankVictim))
                                        {
                                            actioned = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (actioned)
                        {
                            continue;
                        }
                        Unit* closestAttacker = NULL;
                        float closestDistance = 100.0f;
                        for (Unit::AttackerSet::const_iterator attackerIT = dps->getAttackers().begin(); attackerIT != dps->getAttackers().end(); attackerIT++)
                        {
                            if (dps->GetDistance(*attackerIT) < closestDistance)
                            {
                                closestAttacker = *attackerIT;
                                closestDistance = dps->GetDistance(*attackerIT);
                            }
                        }
                        dpsIT->second->sb->DPS(closestAttacker);
                    }
                }
                else
                {
                    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
                    {
                        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
                        {
                            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
                            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
                            {
                                if (dpsIT->second->sb->Follow(tank, dpsIT->second->followDistance))
                                {
                                    actioned = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (roleMap.find(RaidRole::RaidRole_Tank) != roleMap.end())
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator tankIT = roleMap[RaidRole::RaidRole_Tank].begin(); tankIT != roleMap[RaidRole::RaidRole_Tank].end(); tankIT++)
        {
            ObjectGuid tankGUID = ObjectGuid(HighGuid::Player, tankIT->first);
            if (Player* tank = ObjectAccessor::FindConnectedPlayer(tankGUID))
            {
                if (!tankIT->second->isRobot)
                {
                    continue;
                }
                bool actioned = false;
                if (tank->IsInCombat())
                {
                    if (tankIT->second->sb->Tank(tank->GetVictim()))
                    {
                        actioned = true;
                    }
                    if (actioned)
                    {
                        continue;
                    }
                    Unit* closestAttacker = NULL;
                    float closestDistance = 100.0f;
                    for (Unit::AttackerSet::const_iterator attackerIT = tank->getAttackers().begin(); attackerIT != tank->getAttackers().end(); attackerIT++)
                    {
                        if (tank->GetDistance(*attackerIT) < closestDistance)
                        {
                            closestAttacker = *attackerIT;
                            closestDistance = tank->GetDistance(*attackerIT);
                        }
                    }
                    tankIT->second->sb->Tank(closestAttacker);
                }
                else
                {
                    if (Group* memberGroup = tank->GetGroup())
                    {
                        if (Player* master = ObjectAccessor::FindConnectedPlayer(memberGroup->GetLeaderGUID()))
                        {
                            if (tankIT->second->sb->Follow(master, tankIT->second->followDistance))
                            {
                                actioned = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Strategy_Raid::RaidInCombat()
{
    for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
    {
        ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->first);
        if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
        {
            if (member->IsInCombat())
            {
                return true;
            }
        }
    }
    return false;
}

void Strategy_Raid::HandleChatCommand(Player* pmSender, std::string pmCMD)
{
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        std::ostringstream replyStream;
        if (commandVector.size() > 1)
        {
            std::string newRole = commandVector.at(1);
            for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                if (newRole == "dps")
                {
                    pmIT->second->raidRole = RaidRole::RaidRole_DPS;
                }
                else if (newRole == "tank")
                {
                    pmIT->second->raidRole = RaidRole::RaidRole_Tank;
                }
                else if (newRole == "healer")
                {
                    pmIT->second->raidRole = RaidRole::RaidRole_Healer;
                }

                replyStream << "My group role is ";
                switch (pmIT->second->raidRole)
                {
                case 0:
                {
                    replyStream << "dps";
                    break;
                }
                case 1:
                {
                    replyStream << "tank";
                    break;
                }
                case 2:
                {
                    replyStream << "healer";
                    break;
                }
                default:
                {
                    replyStream << "dps";
                    break;
                }
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "follow")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }

                pmIT->second->restDelay = 0;
                pmIT->second->staying = false;
                pmIT->second->holding = false;
                if (commandVector.size() > 1)
                {
                    std::string cmdDistanceStr = commandVector.at(1);
                    float cmdDistance = atof(cmdDistanceStr.c_str());
                    if (cmdDistance > FOLLOW_MIN_DISTANCE&& cmdDistance < FOLLOW_MAX_DISTANCE)
                    {
                        pmIT->second->followDistance = cmdDistance;
                    }
                    else
                    {
                        pmIT->second->sb->WhisperTo("Follow distance is invalid", Language::LANG_UNIVERSAL, pmSender);
                    }
                }
                if (pmIT->second->sb->Follow(pmSender, pmIT->second->followDistance))
                {
                    pmIT->second->sb->WhisperTo("Following", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second->sb->WhisperTo("I will not follow you", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "stay")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->GetMotionMaster()->Clear();
                pmIT->second->staying = true;
                pmIT->second->sb->WhisperTo("Staying", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "hold")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->GetMotionMaster()->Clear();
                pmIT->second->staying = false;
                pmIT->second->holding = true;
                pmIT->second->sb->WhisperTo("Holding", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "attack")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                pmIT->second->staying = false;
                if (pmIT->second->raidRole == RaidRole::RaidRole_Healer)
                {
                    continue;
                }
                if (!pmSender->GetTarget().IsEmpty())
                {
                    pmIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_Attack;
                    pmIT->second->instruction.targetOG = pmSender->GetTarget();
                    pmIT->second->sb->WhisperTo("Try to attack your target", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second->sb->WhisperTo("No target", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "rest")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                if (pmIT->second->sb->Rest())
                {
                    pmIT->second->restDelay = 20 * TimeConstants::IN_MILLISECONDS;
                    pmIT->second->sb->WhisperTo("Resting", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second->sb->WhisperTo("Can not rest", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "who")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                pmIT->second->sb->WhisperTo(sRobotManager->characterTalentTabNameMap[member->GetClass()][pmIT->second->sb->characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "assemble")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (pmIT->second->assembleDelay > 0)
                {
                    pmIT->second->sb->WhisperTo("I am coming", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                if (member->IsAlive())
                {
                    if (member->GetDistance(pmSender) < 50.0f)
                    {
                        if (member->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
                        {
                            pmIT->second->sb->WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
                        {
                            pmIT->second->sb->WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        {
                            pmIT->second->sb->WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->IsNonMeleeSpellCast(false, false, true))
                        {
                            pmIT->second->sb->WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->HasAuraType(SPELL_AURA_MOD_PACIFY))
                        {
                            continue;
                        }
                        if (member->GetStandState() != UnitStandStateType::UNIT_STAND_STATE_STAND)
                        {
                            member->SetStandState(UNIT_STAND_STATE_STAND);
                        }
                        if (member->IsWalking())
                        {
                            member->SetWalk(false);
                        }
                        member->StopMoving();
                        member->GetMotionMaster()->Clear();
                        member->GetMotionMaster()->MovePoint(0, pmSender->GetPosition());
                        pmIT->second->sb->WhisperTo("We are close, I will be ready in 5 seconds", Language::LANG_UNIVERSAL, pmSender);
                    }
                    else
                    {
                        pmIT->second->assembleDelay = 30 * TimeConstants::IN_MILLISECONDS;
                        pmIT->second->sb->WhisperTo("I will come to you in 30 seconds", Language::LANG_UNIVERSAL, pmSender);
                    }
                }
                else
                {
                    pmIT->second->assembleDelay = 60 * TimeConstants::IN_MILLISECONDS;
                    pmIT->second->sb->WhisperTo("I will revive and come to you in 60 seconds", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "tank")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                pmIT->second->staying = false;
                if (pmIT->second->raidRole != RaidRole::RaidRole_Tank)
                {
                    continue;
                }
                if (!pmSender->GetTarget().IsEmpty())
                {
                    pmIT->second->instruction.instructionType = RobotRaidInstructionType::RobotRaidInstructionType_Tank;
                    pmIT->second->instruction.targetOG = pmSender->GetTarget();
                    pmIT->second->sb->WhisperTo("Try to tank your target", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second->sb->WhisperTo("No target", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "prepare")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            pmIT->second->sb->Prepare();
            pmIT->second->sb->WhisperTo("I am prepared", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "switch")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (member->GetClass() == Classes::CLASS_WARLOCK || member->GetClass() == Classes::CLASS_HUNTER)
                {
                    Pet* checkPet = member->GetPet();
                    if (!checkPet)
                    {
                        pmIT->second->sb->WhisperTo("I do not have an active pet", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    if (commandVector.size() > 1)
                    {
                        std::string autoState = commandVector.at(1);
                        if (commandVector.size() > 2)
                        {
                            std::ostringstream spellNameStream;
                            uint32 checkPos = 2;
                            while (checkPos < commandVector.size())
                            {
                                spellNameStream << commandVector.at(checkPos) << " ";
                                checkPos++;
                            }
                            std::string spellName = sRobotManager->TrimString(spellNameStream.str());
                            std::unordered_map<uint32, PetSpell> petSpellMap = checkPet->m_spells;
                            for (std::unordered_map<uint32, PetSpell>::iterator it = petSpellMap.begin(); it != petSpellMap.end(); it++)
                            {
                                if (it->second.active == ACT_DISABLED || it->second.active == ACT_ENABLED)
                                {
                                    const SpellInfo* pST = sSpellMgr->GetSpellInfo(it->first);
                                    if (pST)
                                    {
                                        std::string checkNameStr = std::string(pST->SpellName[0]);
                                        if (checkNameStr == spellName)
                                        {
                                            std::ostringstream replyStream;
                                            if (autoState == "on")
                                            {
                                                checkPet->ToggleAutocast(pST, true);
                                                replyStream << "Switched " << spellName << " on";
                                            }
                                            else if (autoState == "off")
                                            {
                                                checkPet->ToggleAutocast(pST, false);
                                                replyStream << "Switched " << spellName << " off";
                                            }
                                            else
                                            {
                                                replyStream << "Wrong auto state";
                                            }
                                            pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                                            continue;
                                        }
                                    }
                                }
                            }
                            pmIT->second->sb->WhisperTo("Spell not found", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        else
                        {
                            pmIT->second->sb->WhisperTo("No spell name", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                    }
                    else
                    {
                        pmIT->second->sb->WhisperTo("No auto state", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                }
                else
                {
                    pmIT->second->sb->WhisperTo("I am not hunter or a warlock", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
            }
        }
    }
    else if (commandName == "cast")
    {
        if (commandVector.size() > 1)
        {
            std::ostringstream targetStream;
            uint8 arrayCount = 0;
            for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
            {
                if (arrayCount > 0)
                {
                    targetStream << (*it) << " ";
                }
                arrayCount++;
            }
            std::string spellName = sRobotManager->TrimString(targetStream.str());
            std::ostringstream replyStream;
            for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    Unit* senderTarget = pmSender->GetSelectedUnit();
                    if (!senderTarget)
                    {
                        pmIT->second->sb->WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    if (pmIT->second->sb->CastSpell(senderTarget, spellName))
                    {
                        replyStream << "Cast spell " << spellName << " on " << senderTarget->GetName();
                    }
                    else
                    {
                        replyStream << "Can not cast spell " << spellName << " on " << senderTarget->GetName();
                    }
                    pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "cancel")
    {
        if (commandVector.size() > 1)
        {
            std::ostringstream targetStream;
            uint8 arrayCount = 0;
            for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); it++)
            {
                if (arrayCount > 0)
                {
                    targetStream << (*it) << " ";
                }
                arrayCount++;
            }
            std::string spellName = sRobotManager->TrimString(targetStream.str());
            std::ostringstream replyStream;
            for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    Unit* senderTarget = pmSender->GetSelectedUnit();
                    if (!senderTarget)
                    {
                        pmIT->second->sb->WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    if (pmIT->second->sb->CancelAura(spellName))
                    {
                        replyStream << "Cancel aura " << spellName;
                    }
                    else
                    {
                        replyStream << "Unknown spell " << spellName;
                    }
                    pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "use")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                if (commandVector.size() > 1)
                {
                    std::string useType = commandVector.at(1);
                    if (useType == "go")
                    {
                        if (commandVector.size() > 2)
                        {
                            std::ostringstream goNameStream;
                            uint32 checkPos = 2;
                            while (checkPos < commandVector.size())
                            {
                                goNameStream << commandVector.at(checkPos) << " ";
                                checkPos++;
                            }
                            std::string goName = sRobotManager->TrimString(goNameStream.str());

                            bool validToUse = false;
                            std::list<GameObject*> nearGOList;
                            Trinity::GameObjectInRangeCheck check(member->GetPositionX(), member->GetPositionY(), member->GetPositionZ(), MELEE_MAX_DISTANCE);
                            Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(member, nearGOList, check);
                            Cell::VisitGridObjects(member, searcher, SIZE_OF_GRIDS);
                            for (std::list<GameObject*>::iterator it = nearGOList.begin(); it != nearGOList.end(); it++)
                            {
                                if ((*it)->GetName() == goName)
                                {
                                    member->SetFacingToObject((*it));
                                    member->StopMoving();
                                    member->GetMotionMaster()->Clear();
                                    (*it)->Use(member);
                                    replyStream << "Use game object : " << goName;
                                    validToUse = true;
                                    break;
                                }
                            }
                            if (!validToUse)
                            {
                                replyStream << "No go with name " << goName << " nearby";
                            }
                        }
                        else
                        {
                            replyStream << "No go name";
                        }
                    }
                    else if (useType == "item")
                    {

                    }
                    else
                    {
                        replyStream << "Unknown type";
                    }
                }
                else
                {
                    replyStream << "Use what?";
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "stop")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                std::ostringstream replyStream;
                replyStream << "Stopped";
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "delay")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    int delayMS = std::stoi(commandVector.at(1));
                    pmIT->second->dpsDelay = delayMS;
                    replyStream << "DPS delay set to : " << delayMS;
                }
                else
                {
                    replyStream << "Missing time";
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "threat")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                std::ostringstream replyStream;
                replyStream << "Threat list : ";
                for (auto& pair : member->GetThreatManager().GetThreatenedByMeList())
                {
                    replyStream << pair.second->GetOwner()->GetName() << ", ";
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "revive")
    {
        std::unordered_map<uint32, uint32> deadMap;
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    deadMap[deadMap.size()] = member->GetGUID().GetCounter();
                }
            }
        }
        if (deadMap.size() > 0)
        {
            uint32 reviveIndex = 0;
            for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second->sb->WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    std::ostringstream reviveSpellName;
                    std::ostringstream replyStream;
                    if (member->GetClass() == Classes::CLASS_DRUID || member->GetClass() == Classes::CLASS_PRIEST || member->GetClass() == Classes::CLASS_PALADIN)
                    {
                        if (member->GetClass() == Classes::CLASS_DRUID)
                        {
                            reviveSpellName << "Revive";
                        }
                        else if (member->GetClass() == Classes::CLASS_PRIEST)
                        {
                            reviveSpellName << "Resurrection";
                        }
                        else if (member->GetClass() == Classes::CLASS_PALADIN)
                        {
                            reviveSpellName << "Redemption";
                        }
                        if (deadMap.find(reviveIndex) == deadMap.end())
                        {
                            break;
                        }
                        ObjectGuid deadGUID = ObjectGuid(HighGuid::Player, deadMap[reviveIndex]);
                        if (Player* dead = ObjectAccessor::FindConnectedPlayer(deadGUID))
                        {
                            if (!dead->IsAlive())
                            {
                                if (member->GetDistance(dead) < RANGED_MAX_DISTANCE)
                                {
                                    member->SetFacingToObject(dead);
                                    if (pmIT->second->sb->CastSpell(dead, reviveSpellName.str(), RANGED_MAX_DISTANCE))
                                    {
                                        replyStream << "Reviving " << member->GetName();
                                        reviveIndex++;
                                    }
                                }
                            }
                        }
                    }
                    pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "cure")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    std::string cureCMD = commandVector.at(1);
                    if (cureCMD == "on")
                    {
                        pmIT->second->cure = true;
                        replyStream << "Auto cure set to on";
                    }
                    else if (cureCMD == "off")
                    {
                        pmIT->second->cure = false;
                        replyStream << "Auto cure set to off";
                    }
                    else
                    {
                        replyStream << "Unknown state";
                    }
                }
                else
                {
                    if (pmIT->second->cure)
                    {
                        replyStream << "Auto cure is on";
                    }
                    else
                    {
                        replyStream << "Auto cure is off";
                    }
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "emote")
    {
        for (std::unordered_map<uint32, RaidMember*>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second->character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    int emoteCMD = std::stoi(commandVector.at(1));
                    member->HandleEmoteCommand(emoteCMD);
                }
                else
                {
                    member->AttackStop();
                    member->CombatStop();
                }
                pmIT->second->sb->WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
}
