/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "BattlePet.h"
#include "BattlePetMgr.h"
#include "PetBattle.h"
#include "PetBattlePackets.h"

#ifndef PetBattleMgr_h__
#define PetBattleMgr_h__

enum PetBattleRequestResult
{
    PET_BATTLE_REQUEST_CREATE_FAILED            = 0,
    PET_BATTLE_REQUEST_NOT_HERE                 = 1,
    PET_BATTLE_REQUEST_NOT_HERE_ON_TRANSPORT    = 2,
    PET_BATTLE_REQUEST_NOT_HERE_UNEVEN_GROUND   = 3,
    PET_BATTLE_REQUEST_NOT_HERE_OBSTRUCTED      = 4,
    PET_BATTLE_REQUEST_NOT_WHILE_IN_COMBAT      = 5,
    PET_BATTLE_REQUEST_NOT_WHILE_DEAD           = 6,
    PET_BATTLE_REQUEST_NOT_WHILE_FLYING         = 7,
    PET_BATTLE_REQUEST_TARGET_INVALID           = 8,
    PET_BATTLE_REQUEST_TARGET_OUT_OF_RANGE      = 9,
    PET_BATTLE_REQUEST_TARGET_NOT_CAPTURABLE    = 10,
    PET_BATTLE_REQUEST_NOT_A_TRAINER            = 11,
    PET_BATTLE_REQUEST_DECLINED                 = 12,
    PET_BATTLE_REQUEST_IN_BATTLE                = 13,
    PET_BATTLE_REQUEST_INVALID_LOADOUT          = 14,
    PET_BATTLE_REQUEST_ALL_PETS_DEAD            = 15,
    PET_BATTLE_REQUEST_NO_PETS_IN_SLOT          = 16,
    PET_BATTLE_REQUEST_NO_ACCOUNT_LOCK          = 17,
    PET_BATTLE_REQUEST_WILD_PET_TAPPED          = 18,

    /// Custom value
    PET_BATTLE_REQUEST_OK                       = 0xFF
};

enum PetBattleTeam
{
    PET_BATTLE_TEAM_1   = 0,
    PET_BATTLE_TEAM_2   = 1,

    PET_BATTLE_TEAM_PVE = 1,
};

struct PetBattleRequest
{
    ObjectGuid playerGUID;
    ObjectGuid opponentGUID;
    WorldPackets::PetBattle::PetBattleLocation Location;
};

class PetBattleMgr
{
public:
    PetBattleMgr();

    void HandleWildRequest(Player* player, PetBattleRequest request);
    void StartPetBattle(Player* player, PetBattleRequest request);
    void EndPetBattle(uint64 petBattleId);

    PetBattleRequestResult CanPlayerEnterInPetBattle(Player* player, PetBattleRequest& request);

    void DoCapture(Player* player, WildBattlePet* wildBattlePet);

    void SendRequestFailed(Player* player, PetBattleRequestResult reason);
    void SendFinalizeLocation(Player* player, PetBattleRequest request);

    static PetBattleMgr* Instance();
private:

    uint64 m_MaxPetBattleID;
    std::map<uint64 /*battleID*/, PetBattle*> m_petBattles;
};

#define sPetBattleMgr PetBattleMgr::Instance()

#endif // PetBattleMgr_h__
