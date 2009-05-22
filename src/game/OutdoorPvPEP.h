/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef OUTDOOR_PVP_EP_
#define OUTDOOR_PVP_EP_

#include "OutdoorPvPImpl.h"

#include "DBCStructure.h"

const uint32 EP_AllianceBuffs[4] = {11413, 11414, 11415, 1386};

const uint32 EP_HordeBuffs[4] = {30880, 30683, 30682, 29520};

const uint32 EP_GraveYardZone = 139;

const uint32 EP_GraveYardId = 927;

const uint32 EPBuffZonesNum = 3;

const uint32 EP_EWT_CM = 17690;
const uint32 EP_CGT_CM = 17689;
const uint32 EP_NPT_CM = 17696;
const uint32 EP_PWT_CM = 17698;

const uint32 EPBuffZones[EPBuffZonesNum] = {139, 2017, 2057};

enum EP_TaxiNodes {
    EP_CGT_Taxi = 87,
    EP_EWT_Taxi = 86,
    EP_NPT_Taxi = 85,
    EP_PWT_Taxi = 84
};

enum EP_EastwallTowerWorldStates {
    EP_EWT_A = 2354,
    EP_EWT_H = 2356,
    EP_EWT_A_P = 2357, // ally progressing
    EP_EWT_H_P = 2358,
    EP_EWT_N_A = 2359, // ally conquested
    EP_EWT_N_H = 2360,
    EP_EWT_N = 2361
};

enum EP_NorthpassTowerWorldStates {
    EP_NPT_N = 2352,
    EP_NPT_N_A = 2362,
    EP_NPT_N_H = 2363,
    EP_NPT_A_P = 2364,
    EP_NPT_H_P = 2365,
    EP_NPT_A = 2372,
    EP_NPT_H = 2373
};

enum EP_PlagewoodTowerWorldStates {
    EP_PWT_N_A = 2366,
    EP_PWT_N_H = 2353, //2367 not present! use neutral!
    EP_PWT_A_P = 2368,
    EP_PWT_H_P = 2369,
    EP_PWT_A = 2370,
    EP_PWT_H = 2371,
    EP_PWT_N = 2353
};

enum EP_CrownGuardTowerWorldStates {
    EP_CGT_N_A = 2374,
    EP_CGT_N_H = 2375,
    EP_CGT_A_P = 2376,
    EP_CGT_H_P = 2377,
    EP_CGT_A = 2378,
    EP_CGT_H = 2379,
    EP_CGT_N = 2355
};

enum EP_WorldStates {
    EP_UI_TOWER_SLIDER_DISPLAY = 2426,
    EP_UI_TOWER_SLIDER_POS = 2427,
    EP_UI_TOWER_SLIDER_N = 2428,

    EP_UI_TOWER_COUNT_A = 2327,
    EP_UI_TOWER_COUNT_H = 2328
};

enum EP_Summons {
    EP_EWT_COMMANDER = 0,
    EP_EWT_SOLDIER1,
    EP_EWT_SOLDIER2,
    EP_EWT_SOLDIER3,
    EP_EWT_SOLDIER4,
    EP_PWT_FLIGHTMASTER,
};

enum EP_GoSummons {
    EP_NPT_BUFF = 0,
    EP_NPT_FLAGS,
    EP_EWT_FLAGS,
    EP_CGT_FLAGS,
    EP_PWT_FLAGS
};

enum EP_Towers {
    EP_EWT = 0, // plaguelands 03
    EP_NPT,// plaguelands 01
    EP_PWT,// plaguelands 04
    EP_CGT,// plaguelands 02
    EP_TOWER_NUM
};

const go_type EPCapturePoints[EP_TOWER_NUM] = {
    {182097,0,2574.51,-4794.89,144.704,-1.45003,-0.097056,0.095578,-0.656229,0.742165},
    {181899,0,3181.08,-4379.36,174.123,-2.03472,-0.065392,0.119494,-0.842275,0.521553},
    {182098,0,2962.71,-3042.31,154.789,2.08426,-0.074807,-0.113837,0.855928,0.49883},
    {182096,0,1860.85,-3731.23,196.716,-2.53214,0.033967,-0.131914,0.944741,-0.298177}
};

const go_type EPTowerFlags[EP_TOWER_NUM] = {
    {182106,0,2569.60,-4772.93,115.399,2.72271,0,0,0.978148,0.207912},
    {182106,0,3148.17,-4365.51,145.029,1.53589,0,0,0.694658,0.71934},
    {182106,0,2992.63,-3022.95,125.593,3.03687,0,0,0.99863,0.052336},
    {182106,0,1838.42,-3703.56,167.713,0.890118,0,0,0.430511,0.902585}
};

const uint32 EPTowerPlayerEnterEvents[EP_TOWER_NUM] = {10691,10699,10701,10705};

const uint32 EPTowerPlayerLeaveEvents[EP_TOWER_NUM] = {10692,10698,10700,10704};

const uint32 EP_NUM_CREATURES = 6;
const uint32 EP_EWT_NUM_CREATURES = 5;

// one lordaeron commander, 4 soldiers
// should be spawned at EWT and follow a path, but trans-grid pathing isn't safe, so summon them directly at NPT
const creature_type EP_EWT_Summons_A[EP_EWT_NUM_CREATURES] = {
    {17635,469,0, 3167.61,-4352.09,138.20,4.5811},
    {17647,469,0, 3172.74,-4352.99,139.14,4.9873},
    {17647,469,0, 3165.89,-4354.46,138.67,3.7244},
    {17647,469,0, 3164.65,-4350.26,138.22,2.4794},
    {17647,469,0, 3169.91,-4349.68,138.37,0.7444}
};

const creature_type EP_EWT_Summons_H[EP_EWT_NUM_CREATURES] = {
    {17995,67,0, 3167.61,-4352.09,138.20,4.5811},
    {17996,67,0, 3172.74,-4352.99,139.14,4.9873},
    {17996,67,0, 3165.89,-4354.46,138.67,3.7244},
    {17996,67,0, 3164.65,-4350.26,138.22,2.4794},
    {17996,67,0, 3169.91,-4349.68,138.37,0.7444}
};

enum EP_TowerStates {
    EP_TS_N = 1,
    EP_TS_N_A = 2,
    EP_TS_N_H = 4,
    EP_TS_A_P = 8,
    EP_TS_H_P = 16,
    EP_TS_A = 32,
    EP_TS_H = 64
};

// when spawning, pay attention at setting the faction manually!
const creature_type EP_PWT_FlightMaster = {17209,0,0,2987.5,-3049.11,120.126,5.75959};

// after spawning, modify the faction so that only the controller will be able to use it with SetUInt32Value(GAMEOBJECT_FACTION, faction_id);
const go_type EP_NPT_LordaeronShrine = {181682,0,3167.72,-4355.91,138.785,1.69297,0,0,0.748956,0.66262};

class OutdoorPvPEP;

class OutdoorPvPObjectiveEP_EWT : public OutdoorPvPObjective
{
friend class OutdoorPvPEP;
public:
    OutdoorPvPObjectiveEP_EWT(OutdoorPvP * pvp);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
protected:
    bool HandleCapturePointEvent(Player * plr, uint32 eventId);
    void SummonSupportUnitAtNorthpassTower(uint32 team);
    void UpdateTowerState();
protected:
    uint32 m_TowerState;
    uint32 m_UnitsSummonedSide;
};

class OutdoorPvPObjectiveEP_NPT : public OutdoorPvPObjective
{
friend class OutdoorPvPEP;
public:
    OutdoorPvPObjectiveEP_NPT(OutdoorPvP * pvp);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
protected:
    bool HandleCapturePointEvent(Player * plr, uint32 eventId);
    void SummonGO(uint32 team);
    void UpdateTowerState();
protected:
    uint32 m_TowerState;
    uint32 m_SummonedGOSide;
};

class OutdoorPvPObjectiveEP_CGT : public OutdoorPvPObjective
{
friend class OutdoorPvPEP;
public:
    OutdoorPvPObjectiveEP_CGT(OutdoorPvP * pvp);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
protected:
    bool HandleCapturePointEvent(Player * plr, uint32 eventId);
    void LinkGraveYard(uint32 team);
    void UpdateTowerState();
protected:
    uint32 m_TowerState;
    uint32 m_GraveyardSide;
};

class OutdoorPvPObjectiveEP_PWT : public OutdoorPvPObjective
{
friend class OutdoorPvPEP;
public:
    OutdoorPvPObjectiveEP_PWT(OutdoorPvP * pvp);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
    bool HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid);
    bool CanTalkTo(Player * plr, Creature * c, GossipOption &gso);
protected:
    bool HandleCapturePointEvent(Player * plr, uint32 eventId);
    void SummonFlightMaster(uint32 team);
    void UpdateTowerState();
protected:
    uint32 m_FlightMasterSpawned;
    uint32 m_TowerState;
};

class OutdoorPvPEP : public OutdoorPvP
{
friend class OutdoorPvPObjectiveEP_EWT;
friend class OutdoorPvPObjectiveEP_NPT;
friend class OutdoorPvPObjectiveEP_PWT;
friend class OutdoorPvPObjectiveEP_CGT;
public:
    OutdoorPvPEP();
    bool SetupOutdoorPvP();
    void HandlePlayerEnterZone(Player *plr, uint32 zone);
    void HandlePlayerLeaveZone(Player *plr, uint32 zone);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket &data);
    void SendRemoveWorldStates(Player * plr);
    void BuffTeams();
private:
    // how many towers are controlled
    uint32 EP_Controls[EP_TOWER_NUM];
    uint32 m_AllianceTowersControlled;
    uint32 m_HordeTowersControlled;
};

#endif

