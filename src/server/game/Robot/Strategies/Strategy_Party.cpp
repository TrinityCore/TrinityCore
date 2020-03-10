#include "Strategy_Party.h"
#include "RobotManager.h"
#include "MotionMaster.h"
#include "Pet.h"
#include "GridNotifiers.h"
#include "GroupMgr.h"
#include "FollowMovementGenerator.h"
#include "Map.h"
#include "SpellMgr.h"
#include "ThreatManager.h"

Strategy_Party::Strategy_Party(uint32 pmID)
{
    realPrevTime = getMSTime();
    partyID = pmID;
    memberMap.clear();
}

void Strategy_Party::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                uint32 memberLowGUID = member->GetGUID().GetCounter();
                if (memberMap.find(memberLowGUID) != memberMap.end())
                {
                    if (!memberMap[memberLowGUID].isRobot)
                    {
                        continue;
                    }
                    if (memberMap[memberLowGUID].instruction.instructionType != RobotPartyInstructionType::RobotPartyInstructionType_None)
                    {
                        switch (memberMap[memberLowGUID].instruction.instructionType)
                        {
                        case RobotPartyInstructionType::RobotPartyInstructionType_Attack:
                        {
                            if (memberMap[memberLowGUID].partyRole == PartyRole::PartyRole_Healer)
                            {
                                memberMap[memberLowGUID].instruction.Clear();
                            }
                            else
                            {
                                if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Unit)
                                {
                                    if (Map* currentMap = member->GetMap())
                                    {
                                        if (Creature* targetCreature = currentMap->GetCreature(memberMap[memberLowGUID].instruction.targetOG))
                                        {
                                            if (!memberMap[memberLowGUID].sb.Attack(targetCreature))
                                            {
                                                memberMap[memberLowGUID].instruction.Clear();
                                            }
                                        }
                                    }
                                }
                                else if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Player)
                                {
                                    if (Player* targetPlayer = ObjectAccessor::FindConnectedPlayer(memberMap[memberLowGUID].instruction.targetOG))
                                    {
                                        if (!memberMap[memberLowGUID].sb.Attack(targetPlayer))
                                        {
                                            memberMap[memberLowGUID].instruction.Clear();
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case RobotPartyInstructionType::RobotPartyInstructionType_Engage:
                        {
                            if (memberMap[memberLowGUID].partyRole == PartyRole::PartyRole_Healer)
                            {
                                memberMap[memberLowGUID].instruction.Clear();
                            }
                            else
                            {
                                if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Unit)
                                {
                                    if (Map* currentMap = member->GetMap())
                                    {
                                        if (Creature* targetCreature = currentMap->GetCreature(memberMap[memberLowGUID].instruction.targetOG))
                                        {
                                            if (member->GetThreatManager().GetThreatenedByMeList().find(targetCreature->GetGUID()) != member->GetThreatManager().GetThreatenedByMeList().end())
                                            {
                                                memberMap[memberLowGUID].instruction.Clear();
                                            }
                                        }
                                    }
                                }
                                else if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Player)
                                {
                                    if (member->IsInCombat())
                                    {
                                        memberMap[memberLowGUID].instruction.Clear();
                                    }
                                }
                            }
                            break;
                        }
                        case RobotPartyInstructionType::RobotPartyInstructionType_Follow:
                        {
                            if (member->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::FOLLOW_MOTION_TYPE)
                            {
                                FollowMovementGenerator* mg = (FollowMovementGenerator*)member->GetMotionMaster()->GetCurrentMovementGenerator();
                                if (mg)
                                {
                                    if (mg->GetTarget())
                                    {
                                        if (mg->GetTarget()->GetGUID() == party->GetLeaderGUID())
                                        {
                                            memberMap[memberLowGUID].instruction.Clear();
                                            break;
                                        }
                                    }
                                }
                            }
                            if (Player* targetPlayer = ObjectAccessor::FindConnectedPlayer(party->GetLeaderGUID()))
                            {
                                member->StopMoving();
                                member->GetMotionMaster()->MoveFollow(targetPlayer, memberMap[memberLowGUID].followDistance, ChaseAngle(0, 2 * M_PI));
                            }
                            break;
                        }
                        case RobotPartyInstructionType::RobotPartyInstructionType_Tank:
                        {
                            if (memberMap[memberLowGUID].partyRole != PartyRole::PartyRole_Tank)
                            {
                                memberMap[memberLowGUID].instruction.Clear();
                            }
                            else
                            {
                                if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Unit)
                                {
                                    if (Map* currentMap = member->GetMap())
                                    {
                                        if (Creature* targetCreature = currentMap->GetCreature(memberMap[memberLowGUID].instruction.targetOG))
                                        {
                                            if (member->GetThreatManager().GetThreatenedByMeList().find(targetCreature->GetGUID()) != member->GetThreatManager().GetThreatenedByMeList().end())
                                            {
                                                memberMap[memberLowGUID].instruction.Clear();
                                            }
                                        }
                                    }
                                }
                                else if (memberMap[memberLowGUID].instruction.targetOG.GetHigh() == HighGuid::Player)
                                {
                                    if (member->IsInCombat())
                                    {
                                        memberMap[memberLowGUID].instruction.Clear();
                                    }
                                }
                            }
                            break;
                        }
                        case RobotPartyInstructionType::RobotPartyInstructionType_Rest:
                        {
                            if (member->IsInCombat())
                            {
                                memberMap[memberLowGUID].instruction.Clear();
                            }
                            else
                            {
                                if (memberMap[memberLowGUID].sb.Rest())
                                {
                                    memberMap[memberLowGUID].restDelay = 20 * TimeConstants::IN_MILLISECONDS;
                                }
                                memberMap[memberLowGUID].instruction.Clear();
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
                        if (memberMap[memberLowGUID].staying)
                        {
                            continue;
                        }
                        if (member->IsInCombat())
                        {
                            memberMap[memberLowGUID].restDelay = 0;
                        }
                        if (memberMap[memberLowGUID].restDelay > 0)
                        {
                            memberMap[memberLowGUID].restDelay -= diff;
                            continue;
                        }
                        switch (memberMap[memberLowGUID].partyRole)
                        {
                        case PartyRole::PartyRole_DPS:
                        {
                            if (PartyInCombat(member))
                            {
                                memberMap[memberLowGUID].combatTime += diff;
                                if (memberMap[memberLowGUID].combatTime > memberMap[memberLowGUID].dpsDelay)
                                {
                                    if (Unit* tankVictim = GetTankVictim(member))
                                    {
                                        if (memberMap[memberLowGUID].sb.DPS(tankVictim))
                                        {
                                            break;
                                        }
                                    }
                                    if (Unit* myVictim = member->GetVictim())
                                    {
                                        if (memberMap[memberLowGUID].sb.DPS(myVictim))
                                        {
                                            break;
                                        }
                                    }
                                    if (Unit* partyVictim = GetPartyVictim(member))
                                    {
                                        if (memberMap[memberLowGUID].sb.DPS(partyVictim))
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                memberMap[memberLowGUID].combatTime = 0;
                                if (Buff(member))
                                {
                                    break;
                                }
                            }
                            if (Follow(member))
                            {
                                break;
                            }
                            break;
                        }
                        case PartyRole::PartyRole_Healer:
                        {
                            if (Heal(member))
                            {
                                break;
                            }
                            if (!member->IsInCombat())
                            {
                                if (Buff(member))
                                {
                                    break;
                                }
                            }
                            if (Follow(member))
                            {
                                break;
                            }
                            break;
                        }
                        case PartyRole::PartyRole_Tank:
                        {
                            if (Unit* myVictim = member->GetVictim())
                            {
                                if (myVictim->GetTarget() != member->GetGUID())
                                {
                                    if (memberMap[memberLowGUID].sb.Tank(myVictim))
                                    {
                                        break;
                                    }
                                }
                            }
                            // check OT
                            if (PartyInCombat(member))
                            {
                                bool otHandled = false;
                                for (GroupReference* otCheckRef = party->GetFirstMember(); otCheckRef != nullptr; otCheckRef = otCheckRef->next())
                                {
                                    if (Player* otMember = otCheckRef->GetSource())
                                    {
                                        for (Unit::AttackerSet::const_iterator attackerIT = otMember->getAttackers().begin(); attackerIT != otMember->getAttackers().end(); ++attackerIT)
                                        {
                                            if (Unit* eachAttackerVictim = (*attackerIT)->GetVictim())
                                            {
                                                if (eachAttackerVictim->GetGUID() != member->GetGUID())
                                                {
                                                    if (member->GetDistance(*attackerIT) < RANGED_MAX_DISTANCE)
                                                    {
                                                        if (memberMap[memberLowGUID].sb.Tank(*attackerIT))
                                                        {
                                                            otHandled = true;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (otHandled)
                                        {
                                            break;
                                        }
                                    }
                                }
                                if (otHandled)
                                {
                                    break;
                                }
                                if (Unit* myVictim = member->GetVictim())
                                {
                                    if (memberMap[memberLowGUID].sb.Tank(myVictim))
                                    {
                                        break;
                                    }
                                }
                                if (Unit* partyVictim = GetPartyVictim(member))
                                {
                                    if (memberMap[memberLowGUID].sb.DPS(partyVictim))
                                    {
                                        break;
                                    }
                                }
                            }
                            else if (Buff(member))
                            {
                                break;
                            }
                            if (Follow(member))
                            {
                                break;
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
                else
                {
                    PartyMember pm(memberLowGUID, sRobotManager->IsRobot(member->GetSession()->GetAccountId()));
                    memberMap[memberLowGUID] = pm;
                }
            }
        }
    }
}

Unit* Strategy_Party::GetTankVictim(Player* pmChecker)
{
    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsInCombat())
                {
                    if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                    {
                        uint32 memberLowGUID = member->GetGUID().GetCounter();
                        if (memberMap.find(memberLowGUID) != memberMap.end())
                        {
                            if (memberMap[memberLowGUID].partyRole == PartyRole::PartyRole_Tank)
                            {
                                if (Unit* tankVictim = member->GetVictim())
                                {
                                    if (pmChecker->GetDistance(tankVictim) < ATTACK_RANGE_LIMIT)
                                    {
                                        return tankVictim;
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

Unit* Strategy_Party::GetPartyVictim(Player* pmChecker)
{
    Unit* closestVictim = NULL;
    float closestDistance = ATTACK_RANGE_LIMIT;
    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsInCombat())
                {
                    if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                    {
                        for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); ++attackerIT)
                        {
                            float eachDistance = pmChecker->GetDistance(*attackerIT);
                            if (eachDistance < closestDistance)
                            {
                                closestDistance = eachDistance;
                                closestVictim = *attackerIT;
                            }
                        }
                    }
                }
            }
        }
    }

    return closestVictim;
}

bool Strategy_Party::PartyInCombat(Player* pmChecker)
{
    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->IsInCombat())
                {
                    if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Strategy_Party::Rest(Player* pmChecker)
{
    bool canTry = false;
    if (pmChecker->GetHealthPct() < 40.0f)
    {
        canTry = true;
    }
    if (pmChecker->GetPowerType() == Powers::POWER_MANA)
    {
        if (pmChecker->GetPower(Powers::POWER_MANA) / pmChecker->GetMaxPower(Powers::POWER_MANA) < 0.4f)
        {
            canTry = true;
        }
    }
    if (canTry)
    {
        if (memberMap.find(pmChecker->GetGUID().GetCounter()) != memberMap.end())
        {
            return memberMap[pmChecker->GetGUID().GetCounter()].sb.Rest();
        }
    }
}

bool Strategy_Party::Heal(Player* pmChecker)
{
    uint32 checkerLowGUID = pmChecker->GetGUID().GetCounter();

    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                {
                    uint32 memberLowGUID = member->GetGUID().GetCounter();
                    if (memberMap.find(memberLowGUID) != memberMap.end())
                    {
                        if (memberMap[memberLowGUID].partyRole == PartyRole::PartyRole_Tank)
                        {
                            if (memberMap.find(checkerLowGUID) != memberMap.end())
                            {
                                if (memberMap[checkerLowGUID].sb.Heal(member, memberMap[checkerLowGUID].cure))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                {
                    if (member->GetHealthPct() < 50.0f)
                    {
                        if (memberMap.find(checkerLowGUID) != memberMap.end())
                        {
                            if (memberMap[checkerLowGUID].sb.Heal(member, memberMap[checkerLowGUID].cure))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Strategy_Party::Buff(Player* pmChecker)
{
    uint32 checkerLowGUID = pmChecker->GetGUID().GetCounter();

    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        for (GroupReference* groupRef = party->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (pmChecker->GetDistance(member) < ATTACK_RANGE_LIMIT)
                {
                    if (member->GetHealthPct() < 50.0f)
                    {
                        if (memberMap.find(checkerLowGUID) != memberMap.end())
                        {
                            if (memberMap[checkerLowGUID].sb.Buff(member, memberMap[checkerLowGUID].cure))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Strategy_Party::Follow(Player* pmChecker)
{
    if (Group* party = sGroupMgr->GetGroupByGUID(partyID))
    {
        uint32 checkerLowGUID = pmChecker->GetGUID().GetCounter();
        if (pmChecker->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::FOLLOW_MOTION_TYPE)
        {
            FollowMovementGenerator* mg = (FollowMovementGenerator*)pmChecker->GetMotionMaster()->GetCurrentMovementGenerator();
            if (mg)
            {
                if (mg->GetTarget())
                {
                    if (mg->GetTarget()->GetGUID() == party->GetLeaderGUID())
                    {
                        return true;
                    }
                }
            }
        }
        if (Player* targetPlayer = ObjectAccessor::FindConnectedPlayer(party->GetLeaderGUID()))
        {
            pmChecker->StopMoving();
            pmChecker->GetMotionMaster()->MoveFollow(targetPlayer, memberMap[checkerLowGUID].followDistance, ChaseAngle(0, 2 * M_PI));
        }
    }
    return false;
}

void Strategy_Party::HandleChatCommand(Player* pmSender, std::string pmCMD, Player* pmReceiver)
{
    std::vector<std::string> commandVector = sRobotManager->SplitString(pmCMD, " ", true);
    std::string commandName = commandVector.at(0);
    if (commandName == "role")
    {
        std::ostringstream replyStream;
        if (commandVector.size() > 1)
        {
            std::string newRole = commandVector.at(1);
            for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                if (!pmIT->second.isRobot)
                {
                    continue;
                }
                if (pmReceiver)
                {
                    if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                    {
                        continue;
                    }
                }
                if (newRole == "dps")
                {
                    pmIT->second.partyRole = PartyRole::PartyRole_DPS;
                }
                else if (newRole == "tank")
                {
                    pmIT->second.partyRole = PartyRole::PartyRole_Tank;
                }
                else if (newRole == "healer")
                {
                    pmIT->second.partyRole = PartyRole::PartyRole_Healer;
                }

                replyStream << "My group role is ";
                switch (pmIT->second.partyRole)
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
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "follow")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->GetMotionMaster()->Clear();
                pmIT->second.restDelay = 0;
                pmIT->second.staying = false;
                pmIT->second.holding = false;
                if (commandVector.size() > 1)
                {
                    std::string cmdDistanceStr = commandVector.at(1);
                    float cmdDistance = atof(cmdDistanceStr.c_str());
                    if (cmdDistance > FOLLOW_MIN_DISTANCE&& cmdDistance < FOLLOW_MAX_DISTANCE)
                    {
                        pmIT->second.followDistance = cmdDistance;
                    }
                    else
                    {
                        pmIT->second.sb.WhisperTo("Follow distance is invalid", Language::LANG_UNIVERSAL, pmSender);
                    }
                }
                pmIT->second.instruction.instructionType = RobotPartyInstructionType::RobotPartyInstructionType_Follow;
                pmIT->second.sb.WhisperTo("I try to follow party leader", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "stay")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->GetMotionMaster()->Clear();
                pmIT->second.staying = true;
                pmIT->second.sb.WhisperTo("Staying", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "hold")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->GetMotionMaster()->Clear();
                pmIT->second.staying = false;
                pmIT->second.holding = true;
                pmIT->second.sb.WhisperTo("Holding", Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "attack")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                pmIT->second.staying = false;
                if (pmIT->second.partyRole == PartyRole::PartyRole_Healer)
                {
                    continue;
                }
                if (!pmSender->GetTarget().IsEmpty())
                {
                    pmIT->second.instruction.instructionType = RobotPartyInstructionType::RobotPartyInstructionType_Attack;
                    pmIT->second.instruction.targetOG = pmSender->GetTarget();
                    pmIT->second.sb.WhisperTo("Try to attack your target", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second.sb.WhisperTo("No target", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "rest")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                if (member->IsInCombat())
                {
                    pmIT->second.sb.WhisperTo("I am in combat", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                pmIT->second.instruction.instructionType = RobotPartyInstructionType::RobotPartyInstructionType_Rest;
            }
        }
    }
    else if (commandName == "who")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                pmIT->second.sb.WhisperTo(sRobotManager->characterTalentTabNameMap[member->GetClass()][pmIT->second.sb.characterTalentTab], Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "assemble")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (pmIT->second.assembleDelay > 0)
                {
                    pmIT->second.sb.WhisperTo("I am coming", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                if (member->IsAlive())
                {
                    if (member->GetDistance(pmSender) < 50.0f)
                    {
                        if (member->HasUnitState(UnitState::UNIT_STATE_NOT_MOVE))
                        {
                            pmIT->second.sb.WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
                        {
                            pmIT->second.sb.WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        {
                            pmIT->second.sb.WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        if (member->IsNonMeleeSpellCast(false, false, true))
                        {
                            pmIT->second.sb.WhisperTo("I can not move", Language::LANG_UNIVERSAL, pmSender);
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
                        pmIT->second.sb.WhisperTo("We are close, I will be ready in 5 seconds", Language::LANG_UNIVERSAL, pmSender);
                    }
                    else
                    {
                        pmIT->second.assembleDelay = 30 * TimeConstants::IN_MILLISECONDS;
                        pmIT->second.sb.WhisperTo("I will come to you in 30 seconds", Language::LANG_UNIVERSAL, pmSender);
                    }
                }
                else
                {
                    pmIT->second.assembleDelay = 60 * TimeConstants::IN_MILLISECONDS;
                    pmIT->second.sb.WhisperTo("I will revive and come to you in 60 seconds", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "tank")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                pmIT->second.staying = false;
                if (pmIT->second.partyRole != PartyRole::PartyRole_Tank)
                {
                    continue;
                }
                if (!pmSender->GetTarget().IsEmpty())
                {
                    pmIT->second.instruction.instructionType = RobotPartyInstructionType::RobotPartyInstructionType_Tank;
                    pmIT->second.instruction.targetOG = pmSender->GetTarget();
                    pmIT->second.sb.WhisperTo("Try to tank your target", Language::LANG_UNIVERSAL, pmSender);
                }
                else
                {
                    pmIT->second.sb.WhisperTo("No target", Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "prepare")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            pmIT->second.sb.Prepare();
            pmIT->second.sb.WhisperTo("I am prepared", Language::LANG_UNIVERSAL, pmSender);
        }
    }
    else if (commandName == "switch")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (member->GetClass() == Classes::CLASS_WARLOCK || member->GetClass() == Classes::CLASS_HUNTER)
                {
                    Pet* checkPet = member->GetPet();
                    if (!checkPet)
                    {
                        pmIT->second.sb.WhisperTo("I do not have an active pet", Language::LANG_UNIVERSAL, pmSender);
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
                                            pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                                            continue;
                                        }
                                    }
                                }
                            }
                            pmIT->second.sb.WhisperTo("Spell not found", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                        else
                        {
                            pmIT->second.sb.WhisperTo("No spell name", Language::LANG_UNIVERSAL, pmSender);
                            continue;
                        }
                    }
                    else
                    {
                        pmIT->second.sb.WhisperTo("No auto state", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                }
                else
                {
                    pmIT->second.sb.WhisperTo("I am not hunter or a warlock", Language::LANG_UNIVERSAL, pmSender);
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
            for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                if (!pmIT->second.isRobot)
                {
                    continue;
                }
                if (pmReceiver)
                {
                    if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                    {
                        continue;
                    }
                }
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    Unit* senderTarget = pmSender->GetSelectedUnit();
                    if (!senderTarget)
                    {
                        pmIT->second.sb.WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    if (pmIT->second.sb.CastSpell(senderTarget, spellName))
                    {
                        replyStream << "Cast spell " << spellName << " on " << senderTarget->GetName();
                    }
                    else
                    {
                        replyStream << "Can not cast spell " << spellName << " on " << senderTarget->GetName();
                    }
                    pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
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
            for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                if (!pmIT->second.isRobot)
                {
                    continue;
                }
                if (pmReceiver)
                {
                    if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                    {
                        continue;
                    }
                }
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    Unit* senderTarget = pmSender->GetSelectedUnit();
                    if (!senderTarget)
                    {
                        pmIT->second.sb.WhisperTo("You do not have a target", Language::LANG_UNIVERSAL, pmSender);
                        continue;
                    }
                    if (pmIT->second.sb.CancelAura(spellName))
                    {
                        replyStream << "Cancel aura " << spellName;
                    }
                    else
                    {
                        replyStream << "Unknown spell " << spellName;
                    }
                    pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "use")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
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
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "stop")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                member->StopMoving();
                member->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                member->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                std::ostringstream replyStream;
                replyStream << "Stopped";
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "delay")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    int delayMS = std::stoi(commandVector.at(1));
                    pmIT->second.dpsDelay = delayMS;
                    replyStream << "DPS delay set to : " << delayMS;
                }
                else
                {
                    replyStream << "Missing time";
                }
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "threat")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (!member->IsAlive())
                {
                    pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
                    continue;
                }
                std::ostringstream replyStream;
                replyStream << "Threat list : ";
                for (auto& pair : member->GetThreatManager().GetThreatenedByMeList())
                {
                    replyStream << pair.second->GetOwner()->GetName() << ", ";
                }
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "revive")
    {
        std::unordered_map<uint32, uint32> deadMap;
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
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
            for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
            {
                if (!pmIT->second.isRobot)
                {
                    continue;
                }
                if (pmReceiver)
                {
                    if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                    {
                        continue;
                    }
                }
                ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
                if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
                {
                    if (!member->IsAlive())
                    {
                        pmIT->second.sb.WhisperTo("I am dead", Language::LANG_UNIVERSAL, pmSender);
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
                                    if (pmIT->second.sb.CastSpell(dead, reviveSpellName.str(), RANGED_MAX_DISTANCE))
                                    {
                                        replyStream << "Reviving " << member->GetName();
                                        reviveIndex++;
                                    }
                                }
                            }
                        }
                    }
                    pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
                }
            }
        }
    }
    else if (commandName == "cure")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
            if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
            {
                std::ostringstream replyStream;
                if (commandVector.size() > 1)
                {
                    std::string cureCMD = commandVector.at(1);
                    if (cureCMD == "on")
                    {
                        pmIT->second.cure = true;
                        replyStream << "Auto cure set to on";
                    }
                    else if (cureCMD == "off")
                    {
                        pmIT->second.cure = false;
                        replyStream << "Auto cure set to off";
                    }
                    else
                    {
                        replyStream << "Unknown state";
                    }
                }
                else
                {
                    if (pmIT->second.cure)
                    {
                        replyStream << "Auto cure is on";
                    }
                    else
                    {
                        replyStream << "Auto cure is off";
                    }
                }
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
    else if (commandName == "emote")
    {
        for (std::unordered_map<uint32, PartyMember>::iterator pmIT = memberMap.begin(); pmIT != memberMap.end(); pmIT++)
        {
            if (!pmIT->second.isRobot)
            {
                continue;
            }
            if (pmReceiver)
            {
                if (pmIT->second.character != pmReceiver->GetGUID().GetCounter())
                {
                    continue;
                }
            }
            ObjectGuid guid = ObjectGuid(HighGuid::Player, pmIT->second.character);
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
                pmIT->second.sb.WhisperTo(replyStream.str(), Language::LANG_UNIVERSAL, pmSender);
            }
        }
    }
}
