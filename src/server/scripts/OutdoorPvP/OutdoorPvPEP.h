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

#ifndef OUTDOOR_PVP_EP_
#define OUTDOOR_PVP_EP_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_PLAGUEWOOD_TOWER_TAKEN_ALLIANCE    = 13629, // '|cffffff00The Plaguewood Tower has been taken by the Alliance!|r'
    TEXT_NORTHPASS_TOWER_TAKEN_ALLIANCE     = 13630, // '|cffffff00Northpass Tower has been taken by the Alliance!|r'
    TEXT_EASTWALL_TOWER_TAKEN_ALLIANCE      = 13631, // '|cffffff00Eastwall Tower has been taken by the Alliance!|r'
    TEXT_CROWN_GUARD_TOWER_TAKEN_ALLIANCE   = 13632, // '|cffffff00Crown Guard Tower has been taken by the Alliance!|r'
    TEXT_PLAGUEWOOD_TOWER_TAKEN_HORDE       = 13634, // '|cffffff00The Plaguewood Tower has been taken by the Horde!|r'
    TEXT_NORTHPASS_TOWER_TAKEN_HORDE        = 13635, // '|cffffff00Northpass Tower has been taken by the Horde!|r'
    TEXT_EASTWALL_TOWER_TAKEN_HORDE         = 13636, // '|cffffff00Eastwall Tower has been taken by the Horde!|r'
    TEXT_CROWN_GUARD_TOWER_TAKEN_HORDE      = 13633, // '|cffffff00Crown Guard Tower has been taken by the Horde!|r'
    TEXT_ALL_TOWERS_IN_CONTROL_ALLIANCE     = 13638, // (NYI) '|cff33ccffAll four towers are now in control of the Alliance!|r'
    TEXT_ALL_TOWERS_IN_CONTROL_HORDE        = 13637, // (NYI) '|cffff0000All four towers are now in control of the Horde!|r'
};

enum EP_TaxiNodes
{
    EP_CGT_Taxi = 87,
    EP_EWT_Taxi = 86,
    EP_NPT_Taxi = 85,
    EP_PWT_Taxi = 84
};

enum EP_EastwallTowerWorldStates
{
    EP_EWT_A = 2354,
    EP_EWT_H = 2356,
    EP_EWT_N_A = 2359, // ally conquested
    EP_EWT_N_H = 2360,
    EP_EWT_N = 2361
};

enum EP_NorthpassTowerWorldStates
{
    EP_NPT_N = 2352,
    EP_NPT_N_A = 2362,
    EP_NPT_N_H = 2363,
    EP_NPT_A = 2372,
    EP_NPT_H = 2373
};

enum EP_PlagewoodTowerWorldStates
{
    EP_PWT_N_A = 2366,
    EP_PWT_N_H = 2353, //2367 not present! use neutral!
    EP_PWT_A = 2370,
    EP_PWT_H = 2371,
    EP_PWT_N = 2353
};

enum EP_CrownGuardTowerWorldStates
{
    EP_CGT_N_A = 2374,
    EP_CGT_N_H = 2375,
    EP_CGT_A = 2378,
    EP_CGT_H = 2379,
    EP_CGT_N = 2355
};

enum EP_WorldStates
{
    EP_UI_TOWER_COUNT_A = 2327,
    EP_UI_TOWER_COUNT_H = 2328
};

enum EP_Summons
{
    EP_EWT_COMMANDER = 0,
    EP_EWT_SOLDIER1,
    EP_EWT_SOLDIER2,
    EP_EWT_SOLDIER3,
    EP_EWT_SOLDIER4,
    EP_PWT_FLIGHTMASTER,
};

enum EP_GoSummons
{
    EP_NPT_BUFF = 0,
    EP_NPT_FLAGS,
    EP_EWT_FLAGS,
    EP_CGT_FLAGS,
    EP_PWT_FLAGS
};

enum EP_Towers
{
    EP_EWT = 0, // plaguelands 03
    EP_NPT, // plaguelands 01
    EP_PWT, // plaguelands 04
    EP_CGT, // plaguelands 02
    EP_TOWER_NUM
};

enum EP_TowerStates
{
    EP_TS_N = 1,
    EP_TS_N_A = 2,
    EP_TS_N_H = 4,
    EP_TS_A_P = 8,
    EP_TS_H_P = 16,
    EP_TS_A = 32,
    EP_TS_H = 64
};

class OutdoorPvPEP;

class OPvPCapturePointEP_EWT : public OPvPCapturePoint
{
    public:
        OPvPCapturePointEP_EWT(OutdoorPvP* pvp);

        void ChangeState();

        void FillInitialWorldStates(WorldPacket & data);

    protected:
        void SummonSupportUnitAtNorthpassTower(uint32 team);

        void UpdateTowerState();

    protected:
        uint32 m_TowerState;

        uint32 m_UnitsSummonedSide;
};

class OPvPCapturePointEP_NPT : public OPvPCapturePoint
{
    public:
        OPvPCapturePointEP_NPT(OutdoorPvP* pvp);

        void ChangeState();

        void FillInitialWorldStates(WorldPacket & data);

    protected:
        void SummonGO(uint32 team);

        void UpdateTowerState();

    protected:
        uint32 m_TowerState;

        uint32 m_SummonedGOSide;
};

class OPvPCapturePointEP_CGT : public OPvPCapturePoint
{
    public:
        OPvPCapturePointEP_CGT(OutdoorPvP* pvp);

        void ChangeState();

        void FillInitialWorldStates(WorldPacket & data);

    protected:
        void LinkGraveyard(uint32 team);

        void UpdateTowerState();

    protected:
        uint32 m_TowerState;

        uint32 m_GraveyardSide;
};

class OPvPCapturePointEP_PWT : public OPvPCapturePoint
{
    public:
        OPvPCapturePointEP_PWT(OutdoorPvP* pvp);

        void ChangeState();

        void FillInitialWorldStates(WorldPacket & data);

    protected:
        void SummonFlightMaster(uint32 team);

        void UpdateTowerState();

    protected:
        uint32 m_FlightMasterSpawned;

        uint32 m_TowerState;
};

class OutdoorPvPEP : public OutdoorPvP
{
    public:
        OutdoorPvPEP();

        bool SetupOutdoorPvP();

        void HandlePlayerEnterZone(Player* player, uint32 zone);
        void HandlePlayerLeaveZone(Player* player, uint32 zone);

        bool Update(uint32 diff);

        void FillInitialWorldStates(WorldPacket &data);

        void SendRemoveWorldStates(Player* player);

        void BuffTeams();

        void SetControlledState(uint32 index, uint32 state);

    private:
        // how many towers are controlled
        uint32 EP_Controls[EP_TOWER_NUM];

        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
};

#endif
