/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef OUTDOOR_PVP_TF_
#define OUTDOOR_PVP_TF_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_BONE_WASTES_TAKEN_ALLIANCE     = 16120, // (NYI) '|cffffff00The Alliance has taken control of The Bone Wastes!|r'
    TEXT_BONE_WASTES_TAKEN_HORDE        = 16119, // (NYI) '|cffffff00The Horde has taken control of The Bone Wastes!|r'
    TEXT_SPIRIT_TOWER_TAKEN_ALLIANCE    = 18285, // '|cffffff00The Alliance has taken control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_TAKEN_HORDE       = 18286, // '|cffffff00The Horde has taken control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_LOSE_ALLIANCE     = 18288, // '|cffffff00The Alliance has lost control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_LOSE_HORDE        = 18287  // '|cffffff00The Horde has lost control of a Spirit Tower!|r'
};

enum OutdoorPvPTF_TowerType
{
    TF_TOWER_NW = 0,
    TF_TOWER_N,
    TF_TOWER_NE,
    TF_TOWER_SE,
    TF_TOWER_S,
    TF_TOWER_NUM
};

enum TFWorldStates
{
    TF_UI_TOWER_COUNT_H = 0xa3e,
    TF_UI_TOWER_COUNT_A = 0xa3d,
    TF_UI_TOWERS_CONTROLLED_DISPLAY = 0xa3c,

    TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT = 0x9d0,
    TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT = 0x9ce,
    TF_UI_LOCKED_TIME_HOURS = 0x9cd,
    TF_UI_LOCKED_DISPLAY_NEUTRAL = 0x9cc,
    TF_UI_LOCKED_DISPLAY_HORDE = 0xad0,
    TF_UI_LOCKED_DISPLAY_ALLIANCE = 0xacf
};

enum TFTowerStates
{
    TF_TOWERSTATE_N = 1,
    TF_TOWERSTATE_H = 2,
    TF_TOWERSTATE_A = 4
};

class OPvPCapturePointTF : public OPvPCapturePoint
{
    public:
        OPvPCapturePointTF(OutdoorPvP* pvp, OutdoorPvPTF_TowerType type);

        bool Update(uint32 diff) override;
        void ChangeState() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

        void UpdateTowerState();

    protected:
        OutdoorPvPTF_TowerType m_TowerType;
        uint32 m_TowerState;
};

class OutdoorPvPTF : public OutdoorPvP
{
    public:
        OutdoorPvPTF();

        bool SetupOutdoorPvP() override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        bool Update(uint32 diff) override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        void SendRemoveWorldStates(Player* player) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);
        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);
        bool IsLocked() const;

    private:
        bool m_IsLocked;
        uint32 m_LockTimer;
        uint32 m_LockTimerUpdate;
        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
        uint32 hours_left, second_digit, first_digit;
};

#endif
