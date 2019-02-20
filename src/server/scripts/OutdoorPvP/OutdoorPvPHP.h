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

#ifndef OUTDOOR_PVP_HP_
#define OUTDOOR_PVP_HP_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_OVERLOOK_TAKEN_ALLIANCE        = 14841, // '|cffffff00The Overlook has been taken by the Alliance!|r'
    TEXT_OVERLOOK_TAKEN_HORDE           = 14842, // '|cffffff00The Overlook has been taken by the Horde!|r'
    TEXT_STADIUM_TAKEN_ALLIANCE         = 14843, // '|cffffff00The Stadium has been taken by the Alliance!|r'
    TEXT_STADIUM_TAKEN_HORDE            = 14844, // '|cffffff00The Stadium has been taken by the Horde!|r'
    TEXT_BROKEN_HILL_TAKEN_ALLIANCE     = 14845, // '|cffffff00Broken Hill has been taken by the Alliance!|r'
    TEXT_BROKEN_HILL_TAKEN_HORDE        = 14846, // '|cffffff00Broken Hill has been taken by the Horde!|r'
};

enum OutdoorPvPHPSpells
{
    AlliancePlayerKillReward = 32155,
    HordePlayerKillReward = 32158,
    AllianceBuff = 32071,
    HordeBuff = 32049
};

enum OutdoorPvPHPTowerType
{
    HP_TOWER_BROKEN_HILL = 0,
    HP_TOWER_OVERLOOK = 1,
    HP_TOWER_STADIUM = 2,
    HP_TOWER_NUM = 3
};

enum OutdoorPvPHPWorldStates
{
    HP_UI_TOWER_DISPLAY_A = 0x9ba,
    HP_UI_TOWER_DISPLAY_H = 0x9b9,

    HP_UI_TOWER_COUNT_H = 0x9ae,
    HP_UI_TOWER_COUNT_A = 0x9ac
};

class OPvPCapturePointHP : public OPvPCapturePoint
{
    public:
        OPvPCapturePointHP(OutdoorPvP* pvp, OutdoorPvPHPTowerType type);

        void ChangeState() override;

        void FillInitialWorldStates(WorldPacket & data) override;

    private:
        OutdoorPvPHPTowerType m_TowerType;
};

class OutdoorPvPHP : public OutdoorPvP
{
    public:
        OutdoorPvPHP();

        bool SetupOutdoorPvP() override;

        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;

        bool Update(uint32 diff) override;

        void FillInitialWorldStates(WorldPacket &data) override;

        void SendRemoveWorldStates(Player* player) override;

        void HandleKillImpl(Player* player, Unit* killed) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);

        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);

    private:
        // how many towers are controlled
        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
};

#endif
