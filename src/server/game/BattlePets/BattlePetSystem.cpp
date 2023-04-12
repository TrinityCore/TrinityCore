/*
 * Copyright 2021 DekkCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "BattlePetSystem.h"
#include "PetBattle.h"
#include "Player.h"
#include "Position.h"
#include "ObjectAccessor.h"
#include "Position.h"
#include "Containers.h"

#define PETBATTLE_DELETE_INTERVAL (1 * 30 * IN_MILLISECONDS)
#define PETBATTLE_LFB_INTERVAL 500
#define PETBATTLE_LFB_PROPOSAL_TIMEOUT (1 * MINUTE)

struct PetBattleMembersPositions
{
    PetBattleMembersPositions(uint32 mapID, uint32 team, Position const& firstPosition, Position const& secondPosition) : MapID(mapID), Team(team)
    {
        Positions[0] = firstPosition;
        Positions[1] = secondPosition;
    }

    Position Positions[2];
    uint32 MapID;
    uint32 Team;
};

PetBattleSystem::PetBattleSystem()
{
    _maxPetBattleID = 1;
    _deleteUpdateTimer.SetInterval(PETBATTLE_DELETE_INTERVAL);
    _LFBAvgWaitTime = 0;
    _LFBNumWaitTimeAvg = 0;
    _LFBRequestsUpdateTimer.SetInterval(PETBATTLE_LFB_INTERVAL);
}

PetBattleSystem::~PetBattleSystem()
{
    for (auto& itr : _petBattles)
        delete itr.second;

    for (auto& itr : _battleRequests)
        delete itr.second;
}

PetBattleSystem* PetBattleSystem::Instance()
{
    static PetBattleSystem instance;
    return &instance;
}

PetBattle* PetBattleSystem::CreateBattle()
{
    auto battleID = ObjectGuid::Create<HighGuid::BattlePet>(++_maxPetBattleID);
    _petBattles[battleID] = new PetBattle();
    _petBattles[battleID]->ID = battleID;
    return _petBattles[battleID];
}

PetBattleRequest* PetBattleSystem::CreateRequest(ObjectGuid requesterGuid)
{
    _battleRequests[requesterGuid] = new PetBattleRequest();
    _battleRequests[requesterGuid]->RequesterGuid = requesterGuid;
    return _battleRequests[requesterGuid];
}

PetBattle* PetBattleSystem::GetBattle(ObjectGuid battleID)
{
    return Trinity::Containers::MapGetValuePtr(_petBattles, battleID);
}

PetBattleRequest* PetBattleSystem::GetRequest(ObjectGuid requesterGuid)
{
    return Trinity::Containers::MapGetValuePtr(_battleRequests, requesterGuid);
}

void PetBattleSystem::RemoveBattle(ObjectGuid battleID)
{
    if (auto battle = GetBattle(battleID))
    {
        delete battle;

        _petBattles[battleID] = nullptr;
        _petBattles.erase(battleID);
    }
}

void PetBattleSystem::RemoveRequest(ObjectGuid requesterGuid)
{
    if (auto request = GetRequest(requesterGuid))
    {
        delete request;

        _battleRequests[requesterGuid] = nullptr;
        _battleRequests.erase(requesterGuid);
    }
}

void PetBattleSystem::JoinQueue(Player* player)
{
    /// Pandaren case
    if (player->GetTeamId() == TEAM_NEUTRAL)
    {
        player->GetSession()->SendPetBattleQueueStatus(0, 1, LFBUpdateStatus::LFB_CANT_JOIN_DUE_TO_UNSELECTED_FACTION, 0);
        return;
    }

    // Load player pets
    auto petSlots = player->GetBattlePetCombatTeam();
    uint32 weight = 0;

    for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
        if (petSlots[i])
            weight += petSlots[i]->Level;

    std::lock_guard<std::mutex> l_Lock(_LFBRequestsMutex);

    if (_LFBRequests[player->GetGUID()] != nullptr)
        return;

    auto ticket = new LFBTicket();
    ticket->State = LFBState::LFB_STATE_QUEUED;
    ticket->JoinTime = time(nullptr);
    ticket->TicketID = 1;
    ticket->MatchingOpponent = nullptr;
    ticket->ProposalAnswer = LFBAnswer::LFB_ANSWER_PENDING;
    ticket->Weight = weight;
    ticket->RequesterGUID = player->GetGUID();
    ticket->TeamID = player->GetTeamId();

    player->GetSession()->SendBattlePetJournalLockAcquired();
    player->GetSession()->SendPetBattleQueueStatus(ticket->JoinTime, ticket->TicketID, LFBUpdateStatus::LFB_JOIN_QUEUE, _LFBAvgWaitTime);

    _LFBRequests[player->GetGUID()] = ticket;
}

void PetBattleSystem::ProposalResponse(Player* player, bool accepted)
{
    std::lock_guard<std::mutex> l_Lock(_LFBRequestsMutex);

    if (_LFBRequests[player->GetGUID()] == nullptr)
        return;

    auto ticket = _LFBRequests[player->GetGUID()];
    if (ticket->State != LFBState::LFB_STATE_PROPOSAL)
        return;

    ticket->ProposalAnswer = accepted ? LFBAnswer::LFB_ANSWER_AGREE : LFBAnswer::LFB_ANSWER_DENY;
}

void PetBattleSystem::LeaveQueue(Player* player)
{
    std::lock_guard<std::mutex> l_Lock(_LFBRequestsMutex);
    auto ticket = _LFBRequests[player->GetGUID()];
    if (!ticket)
        return;

    switch (ticket->State)
    {
    case LFBState::LFB_STATE_PROPOSAL:
    {
        if (ticket->MatchingOpponent)
        {
            ticket->MatchingOpponent->MatchingOpponent = nullptr;
            ticket->MatchingOpponent->State = LFBState::LFB_STATE_QUEUED;

            if (auto opponent = ObjectAccessor::FindPlayer(ticket->MatchingOpponent->RequesterGUID))
                opponent->GetSession()->SendPetBattleQueueStatus(ticket->MatchingOpponent->JoinTime, ticket->MatchingOpponent->TicketID, LFBUpdateStatus::LFB_JOIN_QUEUE, _LFBAvgWaitTime);
        }

        /// Continue to other case handlers
    }
    case LFBState::LFB_STATE_FINISHED:
    case LFBState::LFB_STATE_IN_COMBAT:
    case LFBState::LFB_STATE_QUEUED:
    {
        player->GetSession()->SendPetBattleQueueStatus(ticket->JoinTime, ticket->TicketID, LFBUpdateStatus::LFB_LEAVE_QUEUE, _LFBAvgWaitTime);
        player->GetSession()->SendBattlePetJournalLockDenied();
        player->UpdateBattlePetCombatTeam();

        delete _LFBRequests[player->GetGUID()];
        _LFBRequests[player->GetGUID()] = nullptr;

        break;
    }
    default:
        break;
    }
}

void PetBattleSystem::Update(uint32 diff)
{
    _deleteUpdateTimer.Update(diff);
    _LFBRequestsUpdateTimer.Update(diff);

    if (_deleteUpdateTimer.Passed())
    {
        _deleteUpdateTimer.Reset();

        while (!_petBattlesDeleteQueue.empty())
        {
            auto& front = _petBattlesDeleteQueue.front();
            RemoveBattle(front.first);

            _petBattlesDeleteQueue.pop();
        }
    }

    for (auto& itr : _petBattles)
    {
        auto battle = itr.second;
        if (!battle)
            continue;

        if (battle->BattleStatus == PET_BATTLE_STATUS_RUNNING)
            battle->Update(diff);
        else if (battle->BattleStatus == PET_BATTLE_STATUS_FINISHED)
        {
            battle->BattleStatus = PET_BATTLE_STATUS_PENDING_DELETE;
            _petBattlesDeleteQueue.push(std::make_pair(itr.first, itr.second));
        }
    }

    if (_LFBRequestsUpdateTimer.Passed())
    {
        _LFBRequestsUpdateTimer.Reset();

        std::lock_guard<std::mutex> l_Lock(_LFBRequestsMutex);
        std::vector<ObjectGuid> ticketsToRemove;

        for (auto pair : _LFBRequests)
        {
            auto ticket = pair.second;
            if (!ticket)
            {
                ticketsToRemove.push_back(pair.first);
                continue;
            }

            auto count = std::count_if(ticketsToRemove.begin(), ticketsToRemove.end(), [ticket](ObjectGuid const& p_Ticket) -> bool
                {
                    return p_Ticket == ticket->RequesterGUID;
                });

            if (count > 0)
                continue;

            auto queuedTime = uint32(time(nullptr) - ticket->JoinTime);
            auto oldNumber = _LFBNumWaitTimeAvg++;
            _LFBAvgWaitTime = int32((_LFBAvgWaitTime * oldNumber + queuedTime) / _LFBNumWaitTimeAvg);

            switch (ticket->State)
            {
            case LFBState::LFB_STATE_QUEUED:
            {
                if (auto player = ObjectAccessor::FindPlayer(ticket->RequesterGUID))
                {
                    player->GetSession()->SendPetBattleQueueStatus(ticket->JoinTime, ticket->TicketID, LFBUpdateStatus::LFB_UPDATE_STATUS, _LFBAvgWaitTime);

                    std::vector<LFBTicket*> possibleOpponent;
                    for (auto v : _LFBRequests)
                    {
                        auto secondTicket = v.second;

                        if (!secondTicket || secondTicket->State != LFBState::LFB_STATE_QUEUED || secondTicket->TeamID != ticket->TeamID || abs(static_cast<int>(secondTicket->Weight - ticket->Weight)) > 5)
                            continue;

                        if (secondTicket->RequesterGUID == ticket->RequesterGUID)
                            continue;

                        if (ObjectAccessor::FindPlayer(secondTicket->RequesterGUID) == nullptr)
                            continue;

                        possibleOpponent.push_back(secondTicket);
                    }

                    std::sort(possibleOpponent.begin(), possibleOpponent.end(), [](LFBTicket const* a, LFBTicket const* b)
                        {
                            return a->Weight >= b->Weight;
                        });

                    if (!possibleOpponent.empty())
                    {
                        auto l_Left = ticket;
                        auto l_Right = possibleOpponent[0];

                        auto leftPlayer = ObjectAccessor::FindPlayer(l_Left->RequesterGUID);
                        auto rightPlayer = ObjectAccessor::FindPlayer(l_Right->RequesterGUID);

                        l_Left->MatchingOpponent = l_Right;
                        l_Right->MatchingOpponent = l_Left;

                        l_Left->State = LFBState::LFB_STATE_PROPOSAL;
                        l_Right->State = LFBState::LFB_STATE_PROPOSAL;

                        l_Left->ProposalTime = time(nullptr);
                        l_Right->ProposalTime = time(nullptr);

                        leftPlayer->GetSession()->SendPetBattleQueueStatus(l_Left->JoinTime, l_Left->TicketID, LFBUpdateStatus::LFB_PROPOSAL_BEGIN, _LFBAvgWaitTime);
                        rightPlayer->GetSession()->SendPetBattleQueueStatus(l_Right->JoinTime, l_Right->TicketID, LFBUpdateStatus::LFB_PROPOSAL_BEGIN, _LFBAvgWaitTime);

                        leftPlayer->GetSession()->SendPetBattleQueueProposeMatch();
                        rightPlayer->GetSession()->SendPetBattleQueueProposeMatch();
                    }
                }
                else
                    ticketsToRemove.push_back(ticket->RequesterGUID);
                break;
            }
            case LFBState::LFB_STATE_PROPOSAL:
            {
                auto l_Left = ticket;
                auto l_Right = ticket->MatchingOpponent;

                auto leftPlayer = ObjectAccessor::FindPlayer(l_Left->RequesterGUID);
                auto rightPlayer = ObjectAccessor::FindPlayer(l_Right->RequesterGUID);

                /// Enter in combat
                if (l_Left->ProposalAnswer == LFBAnswer::LFB_ANSWER_AGREE && l_Right->ProposalAnswer == LFBAnswer::LFB_ANSWER_AGREE)
                {
                    if (leftPlayer && rightPlayer)
                    {
                        leftPlayer->GetSession()->SendPetBattleQueueStatus(l_Left->JoinTime, l_Left->TicketID, LFBUpdateStatus::LFB_PET_BATTLE_IS_STARTED, _LFBAvgWaitTime);
                        rightPlayer->GetSession()->SendPetBattleQueueStatus(l_Right->JoinTime, l_Right->TicketID, LFBUpdateStatus::LFB_PET_BATTLE_IS_STARTED, _LFBAvgWaitTime);

                        l_Left->State = LFBState::LFB_STATE_IN_COMBAT;
                        l_Right->State = LFBState::LFB_STATE_IN_COMBAT;

                        static PetBattleMembersPositions const gPetBattlePositions[7] =
                        {
                            PetBattleMembersPositions(0, TEAM_ALLIANCE, Position(-9502.376f, 114.492f, 59.822f), Position(-9493.934f, 119.854f, 58.459f)),
                            PetBattleMembersPositions(0, TEAM_ALLIANCE, Position(-10048.859f, 1231.028f, 40.881f), Position(-10054.330f, 1239.399f, 40.894f)),
                            PetBattleMembersPositions(0, TEAM_ALLIANCE, Position(-10909.911f, -362.280f, 39.643f), Position(-10899.923f, -362.773f, 39.265f)),
                            PetBattleMembersPositions(0, TEAM_ALLIANCE, Position(-10439.142f, -1939.163f, 104.313f), Position(-10439.306f, -1949.162f, 103.763f)),

                            PetBattleMembersPositions(1, TEAM_HORDE, Position(-954.766f, -3255.210f, 95.645f), Position(-958.212f, -3264.597f, 95.837f)),
                            PetBattleMembersPositions(1, TEAM_HORDE, Position(-2285.038f, -2155.838f, 95.843f), Position(-2281.738f, -2146.397f, 95.843f)),
                            //PetBattleMembersPositions(1, TEAM_HORDE, Position(-1369.247f, -2716.736f, 253.246f), Position(-1359.747f, -2713.613f, 253.390f)),
                            PetBattleMembersPositions(1, TEAM_HORDE, Position(-127.255f, -4959.972f, 20.903f), Position(-129.017f, -4950.128f, 21.378f))
                        };

                        std::vector<PetBattleMembersPositions> positions;
                        for (auto const& data : gPetBattlePositions)
                            if (data.Team == l_Left->TeamID)
                                positions.push_back(data);

                        auto location = positions[urand(0, positions.size() - 1)];
                        std::shared_ptr<BattlePetInstance> playerPets[MAX_PET_BATTLE_SLOTS];
                        std::shared_ptr<BattlePetInstance> playerOpposantPets[MAX_PET_BATTLE_SLOTS];
                        size_t playerPetCount = 0;
                        size_t playerOpposantPetCount = 0;

                        auto battle = sPetBattleSystem->CreateBattle();
                        battle->PvPMatchMakingRequest.LocationResult = 0;
                        battle->PvPMatchMakingRequest.TeamPosition[PET_BATTLE_TEAM_1] = location.Positions[0];
                        battle->PvPMatchMakingRequest.TeamPosition[PET_BATTLE_TEAM_2] = location.Positions[1];

                        Position battleCenterPosition((location.Positions[0].GetPositionX() + location.Positions[1].GetPositionX()) / 2, (location.Positions[0].GetPositionY() + location.Positions[1].GetPositionY()) / 2, (location.Positions[0].GetPositionZ() + location.Positions[1].GetPositionZ()) / 2);
                        battle->PvPMatchMakingRequest.PetBattleCenterPosition = battleCenterPosition;

                        //auto const& l_One = location.Positions[PET_BATTLE_TEAM_1];
                        //auto const& l_Second = location.Positions[PET_BATTLE_TEAM_2];

                        //float angle = atan2(l_Second.GetPositionY() - l_One.GetPositionY(), l_Second.GetPositionX() - l_One.GetPositionX());
                        //battle->PvPMatchMakingRequest.PetBattleCenterPosition.m_orientation = (angle >= 0) ? angle : 2 * M_PI + angle;

                        for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
                        {
                            playerPets[i] = nullptr;
                            playerOpposantPets[i] = nullptr;
                        }

                        // Load player pets
                        auto petSlots = leftPlayer->GetBattlePetCombatTeam();

                        for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
                        {
                            if (!petSlots[i])
                                continue;

                            if (playerPetCount >= MAX_PET_BATTLE_SLOTS || playerPetCount >= leftPlayer->GetUnlockedPetBattleSlot())
                                break;

                            playerPets[playerPetCount] = std::make_shared<BattlePetInstance>();
                            playerPets[playerPetCount]->CloneFrom(petSlots[i]);
                            playerPets[playerPetCount]->Slot = playerPetCount;
                            playerPets[playerPetCount]->OriginalBattlePet = petSlots[i];

                            ++playerPetCount;
                        }

                        auto petOpposantSlots = rightPlayer->GetBattlePetCombatTeam();

                        for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
                        {
                            if (!petOpposantSlots[i])
                                continue;

                            if (playerOpposantPetCount >= MAX_PET_BATTLE_SLOTS || playerOpposantPetCount >= rightPlayer->GetUnlockedPetBattleSlot())
                                break;

                            playerOpposantPets[playerOpposantPetCount] = std::make_shared<BattlePetInstance>();
                            playerOpposantPets[playerOpposantPetCount]->CloneFrom(petOpposantSlots[i]);
                            playerOpposantPets[playerOpposantPetCount]->Slot = playerOpposantPetCount;
                            playerOpposantPets[playerOpposantPetCount]->OriginalBattlePet = petOpposantSlots[i];

                            ++playerOpposantPetCount;
                        }

                        // Add player pets
                        battle->Teams[PET_BATTLE_TEAM_1]->OwnerGuid = leftPlayer->GetGUID();
                        battle->Teams[PET_BATTLE_TEAM_1]->PlayerGuid = leftPlayer->GetGUID();
                        battle->Teams[PET_BATTLE_TEAM_2]->OwnerGuid = rightPlayer->GetGUID();
                        battle->Teams[PET_BATTLE_TEAM_2]->PlayerGuid = rightPlayer->GetGUID();

                        for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
                        {
                            if (playerPets[i])
                                battle->AddPet(PET_BATTLE_TEAM_1, playerPets[i]);

                            if (playerOpposantPets[i])
                                battle->AddPet(PET_BATTLE_TEAM_2, playerOpposantPets[i]);
                        }

                        battle->BattleType = PET_BATTLE_TYPE_PVP_MATCHMAKING;
                        battle->PvPMatchMakingRequest.IsPvPReady[PET_BATTLE_TEAM_1] = false;
                        battle->PvPMatchMakingRequest.IsPvPReady[PET_BATTLE_TEAM_2] = false;

                        // Launch battle
                        leftPlayer->_petBattleId = battle->ID;
                        rightPlayer->_petBattleId = battle->ID;

                        leftPlayer->SetBattlegroundEntryPoint();
                        leftPlayer->ScheduleDelayedOperation(DELAYED_PET_BATTLE_INITIAL);
                        leftPlayer->SaveRecallPosition();
                        leftPlayer->TeleportTo(location.MapID, location.Positions[PET_BATTLE_TEAM_1].GetPositionX() + 0.01f, location.Positions[PET_BATTLE_TEAM_1].GetPositionY() + 0.01f, location.Positions[PET_BATTLE_TEAM_1].GetPositionZ() + 0.01f, rightPlayer->GetOrientation() - M_PI);

                        rightPlayer->SetBattlegroundEntryPoint();
                        rightPlayer->ScheduleDelayedOperation(DELAYED_PET_BATTLE_INITIAL);
                        rightPlayer->SaveRecallPosition();
                        rightPlayer->TeleportTo(location.MapID, location.Positions[PET_BATTLE_TEAM_2].GetPositionX() + 0.01f, location.Positions[PET_BATTLE_TEAM_2].GetPositionY() + 0.01f, location.Positions[PET_BATTLE_TEAM_2].GetPositionZ() + 0.01f, leftPlayer->GetOrientation() - M_PI);

                        ticketsToRemove.push_back(l_Left->RequesterGUID);
                        ticketsToRemove.push_back(l_Right->RequesterGUID);
                    }
                }
                /// Someone declined
                else if (l_Left->ProposalAnswer == LFBAnswer::LFB_ANSWER_DENY || l_Right->ProposalAnswer == LFBAnswer::LFB_ANSWER_DENY)
                {
                    bool p_LeftRemoved = false;
                    bool p_RightRemoved = false;

                    if (leftPlayer && rightPlayer)
                    {
                        if (l_Left->ProposalAnswer == LFBAnswer::LFB_ANSWER_DENY)
                        {
                            rightPlayer->GetSession()->SendPetBattleQueueStatus(l_Left->JoinTime, l_Left->TicketID, LFBUpdateStatus::LFB_OPPONENT_PROPOSAL_DECLINED, _LFBAvgWaitTime);
                            ticketsToRemove.push_back(l_Left->RequesterGUID);
                            p_LeftRemoved = true;
                        }

                        if (l_Right->ProposalAnswer == LFBAnswer::LFB_ANSWER_DENY)
                        {
                            leftPlayer->GetSession()->SendPetBattleQueueStatus(l_Left->JoinTime, l_Left->TicketID, LFBUpdateStatus::LFB_OPPONENT_PROPOSAL_DECLINED, _LFBAvgWaitTime);
                            ticketsToRemove.push_back(l_Right->RequesterGUID);
                            p_RightRemoved = true;
                        }

                        if (!p_LeftRemoved)
                        {
                            l_Left->State = LFBState::LFB_STATE_QUEUED;
                            leftPlayer->GetSession()->SendPetBattleQueueStatus(l_Left->JoinTime, l_Left->TicketID, LFBUpdateStatus::LFB_JOIN_QUEUE, _LFBAvgWaitTime);
                        }
                        if (!p_RightRemoved)
                        {
                            l_Right->State = LFBState::LFB_STATE_QUEUED;
                            rightPlayer->GetSession()->SendPetBattleQueueStatus(l_Right->JoinTime, l_Right->TicketID, LFBUpdateStatus::LFB_JOIN_QUEUE, _LFBAvgWaitTime);
                        }
                    }
                }
                /// Proposal expired
                if ((time(nullptr) - ticket->ProposalTime) > PETBATTLE_LFB_PROPOSAL_TIMEOUT)
                {
                    l_Left->MatchingOpponent = nullptr;
                    l_Right->MatchingOpponent = nullptr;

                    ticketsToRemove.push_back(l_Left->RequesterGUID);
                    ticketsToRemove.push_back(l_Right->RequesterGUID);
                }

                break;
            }
            default:
                break;
            }
        }

        for (auto& guid : ticketsToRemove)
        {
            auto ticket = _LFBRequests[guid];

            if (!ticket)
            {
                auto itr = _LFBRequests.find(guid);
                if (itr != _LFBRequests.end())
                    _LFBRequests.erase(itr);
                continue;
            }

            switch (ticket->State)
            {
            case LFBState::LFB_STATE_PROPOSAL:
            {
                if (ticket->MatchingOpponent)
                {
                    ticket->MatchingOpponent->MatchingOpponent = nullptr;
                    ticket->MatchingOpponent->State = LFBState::LFB_STATE_QUEUED;

                    if (auto opponent = ObjectAccessor::FindPlayer(ticket->MatchingOpponent->RequesterGUID))
                        opponent->GetSession()->SendPetBattleQueueStatus(ticket->MatchingOpponent->JoinTime, ticket->MatchingOpponent->TicketID, LFBUpdateStatus::LFB_JOIN_QUEUE, _LFBAvgWaitTime);
                }

                /// Continue to other case handlers
            }
            case LFBState::LFB_STATE_FINISHED:
            case LFBState::LFB_STATE_IN_COMBAT:
            case LFBState::LFB_STATE_QUEUED:
            {
                if (auto player = ObjectAccessor::FindPlayer(ticket->RequesterGUID))
                {
                    player->GetSession()->SendPetBattleQueueStatus(ticket->JoinTime, ticket->TicketID, LFBUpdateStatus::LFB_LEAVE_QUEUE, _LFBAvgWaitTime);
                    player->GetSession()->SendBattlePetJournalLockDenied();
                }

                delete _LFBRequests[guid];
                _LFBRequests[guid] = nullptr;
                break;
            }
            default:
                break;
            }
        }
    }
}

void PetBattleSystem::ForfeitBattle(ObjectGuid battleID, ObjectGuid forfeiterGuid, bool ignoreAbandonPenalty)
{
    auto battle = GetBattle(battleID);
    if (!battle)
        return;

    uint32 forfeiterTeamID;
    for (forfeiterTeamID = 0; forfeiterTeamID < MAX_PET_BATTLE_TEAM; ++forfeiterTeamID)
        if (battle->Teams[forfeiterTeamID]->OwnerGuid == forfeiterGuid)
            break;

    if (forfeiterTeamID == MAX_PET_BATTLE_TEAM)
        return;

    battle->Finish(!forfeiterTeamID, true, ignoreAbandonPenalty);
}

eBattlePetRequests PetBattleSystem::CanPlayerEnterInPetBattle(Player* player, PetBattleRequest* petBattleRequest)
{
    if (!player || !player->IsInWorld())
        return BATTLE_PET_REQUEST_CREATE_FAILED;

    if (player->isDead())
        return BATTLE_PET_REQUEST_NOT_WHILE_DEAD;

    if (petBattleRequest->OpponentGuid.IsPlayer())
    {
        if (auto player2 = ObjectAccessor::FindPlayer(petBattleRequest->OpponentGuid))
        {
            if (!player2->IsWithinDist3d(player2, INTERACTION_DISTANCE))
                return BATTLE_PET_REQUEST_TARGET_OUT_OF_RANGE;

            if (!player2->IsWithinLOSInMap(player2))
                return BATTLE_PET_REQUEST_NOT_HERE_OBSTRUCTED;
        }
    }
    else if (petBattleRequest->OpponentGuid.IsCreature())
    {
        if (!player->GetNPCIfCanInteractWith(petBattleRequest->OpponentGuid, UNIT_NPC_FLAG_NONE, UNIT_NPC_FLAG_2_NONE))
            return BATTLE_PET_REQUEST_TARGET_INVALID;

        auto creature = ObjectAccessor::GetCreature(*player, petBattleRequest->OpponentGuid);

        if (!player->IsWithinDist3d(creature, INTERACTION_DISTANCE))
            return BATTLE_PET_REQUEST_TARGET_OUT_OF_RANGE;

        if (!player->IsWithinLOSInMap(creature))
            return BATTLE_PET_REQUEST_NOT_HERE_OBSTRUCTED;
    }

    if (player->IsInCombat())
        return BATTLE_PET_REQUEST_NOT_WHILE_IN_COMBAT;

    // Check positions
    /*for (const auto& itr : petBattleRequest->TeamPosition)
        if (player->GetMap()->getObjectHitPos(player->GetPhaseShift(), petBattleRequest->PetBattleCenterPosition, itr, 0.0f))
            return BATTLE_PET_REQUEST_NOT_HERE_UNEVEN_GROUND;*/

    auto petSlots = player->GetBattlePetCombatTeam();
    size_t playerPetCount = 0;
    size_t playerDeadPetCount = 0;

    for (size_t i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
    {
        if (!petSlots[i])
            continue;

        if (playerPetCount >= MAX_PET_BATTLE_SLOTS || playerPetCount >= player->GetUnlockedPetBattleSlot())
            break;

        if (petSlots[i]->Health < 1)
            playerDeadPetCount++;

        ++playerPetCount;
    }

    if (!playerPetCount)
        return BATTLE_PET_REQUEST_NO_PETS_IN_SLOT;

    if (playerPetCount == playerDeadPetCount)
        return BATTLE_PET_REQUEST_ALL_PETS_DEAD;

    return BATTLE_PET_REQUEST_OK;
}
