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

#include "Common.h"

#ifndef PetBattleSystem_h__
#define PetBattleSystem_h__

enum eBattlePetRequests
{
    BATTLE_PET_REQUEST_CREATE_FAILED            = 0,
    BATTLE_PET_REQUEST_NOT_HERE                 = 1,
    BATTLE_PET_REQUEST_NOT_HERE_ON_TRANSPORT    = 2,
    BATTLE_PET_REQUEST_NOT_HERE_UNEVEN_GROUND   = 3,
    BATTLE_PET_REQUEST_NOT_HERE_OBSTRUCTED      = 4,
    BATTLE_PET_REQUEST_NOT_WHILE_IN_COMBAT      = 5,
    BATTLE_PET_REQUEST_NOT_WHILE_DEAD           = 6,
    BATTLE_PET_REQUEST_NOT_WHILE_FLYING         = 7,
    BATTLE_PET_REQUEST_TARGET_INVALID           = 8,
    BATTLE_PET_REQUEST_TARGET_OUT_OF_RANGE      = 9,
    BATTLE_PET_REQUEST_TARGET_NOT_CAPTURABLE    = 10,
    BATTLE_PET_REQUEST_NOT_A_TRAINER            = 11,
    BATTLE_PET_REQUEST_DECLINED                 = 12,
    BATTLE_PET_REQUEST_IN_BATTLE                = 13,
    BATTLE_PET_REQUEST_INVALID_LOADOUT          = 14,
    BATTLE_PET_REQUEST_ALL_PETS_DEAD            = 15,
    BATTLE_PET_REQUEST_NO_PETS_IN_SLOT          = 16,
    BATTLE_PET_REQUEST_NO_ACCOUNT_LOCK          = 17,
    BATTLE_PET_REQUEST_WILD_PET_TAPPED          = 18,

    /// Custom value
    BATTLE_PET_REQUEST_OK                       = 0xFF
};

enum LFBAnswer : int32
{
    LFB_ANSWER_PENDING = -1,
    LFB_ANSWER_DENY = 0,
    LFB_ANSWER_AGREE = 1
};

enum LFBState : uint32
{
    LFB_STATE_NONE = 0,
    LFB_STATE_QUEUED = 1,
    LFB_STATE_PROPOSAL = 2,
    LFB_STATE_IN_COMBAT = 3,
    LFB_STATE_FINISHED = 4,
};

struct LFBTicket
{
    LFBTicket* MatchingOpponent;
    ObjectGuid RequesterGUID;
    LFBState State;
    LFBAnswer ProposalAnswer;
    uint32 JoinTime;
    uint32 TicketID;
    uint32 Weight;
    uint32 TeamID;
    uint32 ProposalTime;
};

class PetBattleSystem
{
    PetBattleSystem();
    ~PetBattleSystem();

public:
    static PetBattleSystem* Instance();

    PetBattle* CreateBattle();
    PetBattleRequest* CreateRequest(ObjectGuid requesterGuid);

    PetBattle* GetBattle(ObjectGuid battleID);
    PetBattleRequest* GetRequest(ObjectGuid requesterGuid);

    void RemoveBattle(ObjectGuid battleID);
    void RemoveRequest(ObjectGuid requesterGuid);

    void JoinQueue(Player* player);
    void ProposalResponse(Player* player, bool accept);
    void LeaveQueue(Player* player);

    void Update(uint32 diff);

    void ForfeitBattle(ObjectGuid battleID, ObjectGuid forfeiterGuid, bool ignoreAbandonPenalty);

    eBattlePetRequests CanPlayerEnterInPetBattle(Player* player, PetBattleRequest* petBattleRequest);

private:
    std::map<ObjectGuid, PetBattle*> _petBattles;           ///< All running battles
    std::map<ObjectGuid, PetBattleRequest*> _battleRequests;             ///< All pending battles request
    std::map<ObjectGuid, LFBTicket*> _LFBRequests;
    std::queue<std::pair<ObjectGuid, PetBattle*>> _petBattlesDeleteQueue;   ///< Deletion queue
    std::mutex _LFBRequestsMutex;
    IntervalTimer _LFBRequestsUpdateTimer;
    IntervalTimer _deleteUpdateTimer;        ///< Deletion queue update timer
    uint32 _LFBAvgWaitTime;
    uint32 _LFBNumWaitTimeAvg;
    uint64 _maxPetBattleID;       ///< Global battle unique id
};


#define sPetBattleSystem PetBattleSystem::Instance()

#endif // BattlePetSystem_h__
