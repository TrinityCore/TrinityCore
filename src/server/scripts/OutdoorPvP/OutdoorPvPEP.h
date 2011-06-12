/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "DBCStructure.h"
#include "OutdoorPvP.h"

const uint32 EP_AllianceBuffs[4] = {11413, 11414, 11415, 1386};

const uint32 EP_HordeBuffs[4] = {30880, 30683, 30682, 29520};

const uint32 EP_GraveYardZone = 139;

const uint32 EP_GraveYardId = 927;

const uint8 EPBuffZonesNum = 3;

const uint32 EP_EWT_CM = 17690;
const uint32 EP_CGT_CM = 17689;
const uint32 EP_NPT_CM = 17696;
const uint32 EP_PWT_CM = 17698;

const uint32 EPBuffZones[EPBuffZonesNum] = {139, 2017, 2057};

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
    EP_UI_TOWER_SLIDER_DISPLAY = 2426,
    EP_UI_TOWER_SLIDER_POS = 2427,
    EP_UI_TOWER_SLIDER_N = 2428,

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

const go_type EPCapturePoints[EP_TOWER_NUM] =
{
    {182097, 0, 2574.51f, -4794.89f, 144.704f, -1.45003f, -0.097056f, 0.095578f, -0.656229f, 0.742165f},
    {181899, 0, 3181.08f, -4379.36f, 174.123f, -2.03472f, -0.065392f, 0.119494f, -0.842275f, 0.521553f},
    {182098, 0, 2962.71f, -3042.31f, 154.789f, 2.08426f, -0.074807f, -0.113837f, 0.855928f, 0.49883f},
    {182096, 0, 1860.85f, -3731.23f, 196.716f, -2.53214f, 0.033967f, -0.131914f, 0.944741f, -0.298177f}
};

const go_type EPTowerFlags[EP_TOWER_NUM] =
{
    {182106, 0, 2569.60f, -4772.93f, 115.399f, 2.72271f, 0.0f, 0.0f, 0.978148f, 0.207912f},
    {182106, 0, 3148.17f, -4365.51f, 145.029f, 1.53589f, 0.0f, 0.0f, 0.694658f, 0.71934f},
    {182106, 0, 2992.63f, -3022.95f, 125.593f, 3.03687f, 0.0f, 0.0f, 0.99863f, 0.052336f},
    {182106, 0, 1838.42f, -3703.56f, 167.713f, 0.890118f, 0.0f, 0.0f, 0.430511f, 0.902585f}
};

const uint32 EPTowerPlayerEnterEvents[EP_TOWER_NUM] = {10691, 10699, 10701, 10705};

const uint32 EPTowerPlayerLeaveEvents[EP_TOWER_NUM] = {10692, 10698, 10700, 10704};

const uint8 EP_NUM_CREATURES = 6;
const uint8 EP_EWT_NUM_CREATURES = 5;

// one lordaeron commander, 4 soldiers
// should be spawned at EWT and follow a path, but trans-grid pathing isn't safe, so summon them directly at NPT
const creature_type EP_EWT_Summons_A[EP_EWT_NUM_CREATURES] =
{
    {17635, 469, 0, 3167.61f, -4352.09f, 138.20f, 4.5811f},
    {17647, 469, 0, 3172.74f, -4352.99f, 139.14f, 4.9873f},
    {17647, 469, 0, 3165.89f, -4354.46f, 138.67f, 3.7244f},
    {17647, 469, 0, 3164.65f, -4350.26f, 138.22f, 2.4794f},
    {17647, 469, 0, 3169.91f, -4349.68f, 138.37f, 0.7444f}
};

const creature_type EP_EWT_Summons_H[EP_EWT_NUM_CREATURES] =
{
    {17995, 67, 0, 3167.61f, -4352.09f, 138.20f, 4.5811f},
    {17996, 67, 0, 3172.74f, -4352.99f, 139.14f, 4.9873f},
    {17996, 67, 0, 3165.89f, -4354.46f, 138.67f, 3.7244f},
    {17996, 67, 0, 3164.65f, -4350.26f, 138.22f, 2.4794f},
    {17996, 67, 0, 3169.91f, -4349.68f, 138.37f, 0.7444f}
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

// when spawning, pay attention at setting the faction manually!
const creature_type EP_PWT_FlightMaster = {17209, 0, 0, 2987.5f, -3049.11f, 120.126f, 5.75959f};

// after spawning, modify the faction so that only the controller will be able to use it with SetUInt32Value(GAMEOBJECT_FACTION, faction_id);
const go_type EP_NPT_LordaeronShrine = {181682, 0, 3167.72f, -4355.91f, 138.785f, 1.69297f, 0.0f, 0.0f, 0.748956f, 0.66262f};

class OutdoorPvPEP;

class OPvPCapturePointEP_EWT : public OPvPCapturePoint
{
    friend class OutdoorPvPEP;

    public:

        OPvPCapturePointEP_EWT(OutdoorPvP * pvp);

        void ChangeState();

        void SendChangePhase();

        void FillInitialWorldStates(WorldPacket & data);

        // used when player is activated/inactivated in the area
        bool HandlePlayerEnter(Player* plr);
        void HandlePlayerLeave(Player* plr);

    protected:

        void SummonSupportUnitAtNorthpassTower(uint32 team);

        void UpdateTowerState();

    protected:

        uint32 m_TowerState;

        uint32 m_UnitsSummonedSide;
};

class OPvPCapturePointEP_NPT : public OPvPCapturePoint
{
    friend class OutdoorPvPEP;

    public:

        OPvPCapturePointEP_NPT(OutdoorPvP * pvp);

        void ChangeState();

        void SendChangePhase();

        void FillInitialWorldStates(WorldPacket & data);

        // used when player is activated/inactivated in the area
        bool HandlePlayerEnter(Player* plr);
        void HandlePlayerLeave(Player* plr);

    protected:

        void SummonGO(uint32 team);

        void UpdateTowerState();

    protected:

        uint32 m_TowerState;

        uint32 m_SummonedGOSide;
};

class OPvPCapturePointEP_CGT : public OPvPCapturePoint
{
    friend class OutdoorPvPEP;

    public:

        OPvPCapturePointEP_CGT(OutdoorPvP * pvp);

        void ChangeState();

        void SendChangePhase();

        void FillInitialWorldStates(WorldPacket & data);

        // used when player is activated/inactivated in the area
        bool HandlePlayerEnter(Player* plr);
        void HandlePlayerLeave(Player* plr);

    protected:

        void LinkGraveYard(uint32 team);

        void UpdateTowerState();

    protected:

        uint32 m_TowerState;

        uint32 m_GraveyardSide;
};

class OPvPCapturePointEP_PWT : public OPvPCapturePoint
{
    friend class OutdoorPvPEP;

    public:

        OPvPCapturePointEP_PWT(OutdoorPvP * pvp);

        void ChangeState();

        void SendChangePhase();

        void FillInitialWorldStates(WorldPacket & data);

        // used when player is activated/inactivated in the area
        bool HandlePlayerEnter(Player* plr);
        void HandlePlayerLeave(Player* plr);

    protected:

        void SummonFlightMaster(uint32 team);

        void UpdateTowerState();

    protected:

        uint32 m_FlightMasterSpawned;

        uint32 m_TowerState;
};

class OutdoorPvPEP : public OutdoorPvP
{
    friend class OPvPCapturePointEP_EWT;
    friend class OPvPCapturePointEP_NPT;
    friend class OPvPCapturePointEP_PWT;
    friend class OPvPCapturePointEP_CGT;

    public:

        OutdoorPvPEP();

        bool SetupOutdoorPvP();

        void HandlePlayerEnterZone(Player *plr, uint32 zone);
        void HandlePlayerLeaveZone(Player *plr, uint32 zone);

        bool Update(uint32 diff);

        void FillInitialWorldStates(WorldPacket &data);

        void SendRemoveWorldStates(Player* plr);

        void BuffTeams();

    private:

        // how many towers are controlled
        uint32 EP_Controls[EP_TOWER_NUM];

        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
};

#endif

