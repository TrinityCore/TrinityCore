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

#include "PetBattlePackets.h"
#include "ObjectAccessor.h"

#ifndef PetBattle_h__
#define PetBattle_h__

class Player;
class WildBattlePet;

enum PetBattleType
{
    PET_BATTLE_PVE  = 0,
    PET_BATTLE_PVP  = 1,
};

enum PetBattleTrapStatus
{
    PET_BATTLE_TRAP_STATUS_CAN_LAUNCH       = 1,
    PET_BATTLE_TRAP_STATUS_HEALTH_TOO_HIGH  = 4,
    PET_BATTLE_TRAP_STATUS_ALREADY_LAUNCHED = 8,
};

class PetBattle
{
public:
    PetBattle(uint64 battleID, Player* player1, Player* player2, ObjectGuid wildBattlePet);
    ~PetBattle() { }

    void Start();

    void BuildPlayerUpdate(uint8 index, WorldPackets::PetBattle::PetBattlePlayerUpdate& playerUpdate);
    void FillPlayerUpdate(Player* player, WorldPackets::PetBattle::PetBattlePlayerUpdate& playerUpdate);
    void FillPlayerUpdate(WildBattlePet* wildBattlePet, WorldPackets::PetBattle::PetBattlePlayerUpdate& playerUpdate);

    void End();

    uint64 GetBattleId() { return m_battleId; }
    uint32 GetCurrentRound() { return m_currentRound; }

    Player* GetPlayer1() { return ObjectAccessor::FindPlayer(m_player1); }
    Player* GetPlayer2() { return ObjectAccessor::FindPlayer(m_player2); }
    WildBattlePet* GetOriginalWildPet();

private:
    PetBattleType m_battleType;

    uint64 m_battleId;
    uint32 m_currentRound;

    ObjectGuid m_player1;
    ObjectGuid m_player2;
    ObjectGuid m_wildBattlePet;

    PetBattleTrapStatus trapStatus[2];
};

#endif // PetBattle_h__
