/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef OUTDOOR_PVP_GH_
#define OUTDOOR_PVP_GH_

#include "OutdoorPvP.h"
#include "DBCStructure.h"

enum OutdoorPvPNASpells
{
    GH_VENTURE_KILL_CREDIT  = 50858,
    GH_VENTURE_PVP_MASTER   = 50857,
};

enum OutdoorPvPGHWorldStates
{
    GH_UI_TOWER_SLIDER_DISPLAY  = 3466,
    GH_UI_TOWER_SLIDER_POS      = 3467,
    GH_UI_TOWER_SLIDER_N        = 3468,

    GH_MAP_VENTURE_NEUTRAL      = 3501,
    GH_MAP_VENTURE_NEU_A        = 3501,
    GH_MAP_VENTURE_NEU_H        = 3501,
    GH_MAP_VENTURE_HORDE        = 3508,
    GH_MAP_VENTURE_ALLIANCE     = 3502
};

enum Misc
{
    GH_OUTDOORPVP_ZONE      = 394,
    GH_CONTROL_NPC_NUM      = 21,

    // Grizzly Hills text
    LANG_OPVP_GH_CAPTURE_A              = 12002,
    LANG_OPVP_GH_LOOSE_A                = 12004,
    LANG_OPVP_GH_CAPTURE_H              = 12001,
    LANG_OPVP_GH_LOOSE_H                = 12003,
};

const creature_type HordeControlNPCs[GH_CONTROL_NPC_NUM] =
{
    // soldiers
    {27748,67,571,2492.002930f,-1845.899414f,10.711608f,5.529358f},
    {27748,67,571,2498.592773f,-1837.833740f,10.552654f,5.351072f},
    {27748,67,571,2515.539307f,-1822.425171f,10.910775f,5.558418f},
    {27748,67,571,2575.352051f,-1796.180420f,10.441980f,0.377932f},
    {27748,67,571,2580.784180f,-1809.862549f,10.445493f,0.377932f},
    {27748,67,571,2552.297363f,-1831.839966f,10.495550f,2.246392f},
    {27748,67,571,2464.210693f,-1850.925415f,6.143895f,2.954036f},
    {27748,67,571,2410.525391f,-1825.168335f,1.870843f,4.718826f},
    {27748,67,571,2481.714355f,-1877.021362f,10.700072f,6.010807f},
    {27748,67,571,2479.789551f,-1905.015259f,10.398465f,0.403849f},
    {27748,67,571,2508.500244f,-1896.378784f,8.882201f,4.220098f},
    {27748,67,571,2494.566895f,-1934.060181f,12.319469f,0.606482f},
    {27748,67,571,2543.587646f,-1916.709961f,3.205774f,0.106969f},
    {27748,67,571,2545.027100f,-1930.114868f,3.636569f,0.106969f},
    {27748,67,571,2539.792236f,-1974.311035f,8.256695f,5.160220f},
    {27748,67,571,2526.169189f,-1980.855347f,8.273070f,5.160220f},
    {27748,67,571,2553.052734f,-1882.842896f,4.512696f,6.110557f},
    // captain
    {27708,67,571,2485.295898f,-1889.402344f,9.714134f,6.202426f},
    // blacksmith
    {29253,67,571,2476.218750f,-1953.859131f,10.883574f,1.297610f},
    // vendor
    {27730,67,571,2489.363770f,-1836.897095f,11.650964f,5.528555f},
    // stable master
    {29251,67,571,2551.742188f,-1835.743652f,10.553280f,2.068092f}
};

const creature_type AllianceControlNPCs[GH_CONTROL_NPC_NUM] =
{
    // soldiers
    {27758,469,571,2492.002930f,-1845.899414f,10.711608f,5.529358f},
    {27758,469,571,2498.592773f,-1837.833740f,10.552654f,5.351072f},
    {27758,469,571,2515.539307f,-1822.425171f,10.910775f,5.558418f},
    {27758,469,571,2575.352051f,-1796.180420f,10.441980f,0.377932f},
    {27758,469,571,2580.784180f,-1809.862549f,10.445493f,0.377932f},
    {27758,469,571,2552.297363f,-1831.839966f,10.495550f,2.246392f},
    {27758,469,571,2464.210693f,-1850.925415f,6.143895f,2.954036f},
    {27758,469,571,2410.525391f,-1825.168335f,1.870843f,4.718826f},
    {27758,469,571,2481.714355f,-1877.021362f,10.700072f,6.010807f},
    {27758,469,571,2479.789551f,-1905.015259f,10.398465f,0.403849f},
    {27758,469,571,2508.500244f,-1896.378784f,8.882201f,4.220098f},
    {27758,469,571,2494.566895f,-1934.060181f,12.319469f,0.606482f},
    {27758,469,571,2543.587646f,-1916.709961f,3.205774f,0.106969f},
    {27758,469,571,2545.027100f,-1930.114868f,3.636569f,0.106969f},
    {27758,469,571,2539.792236f,-1974.311035f,8.256695f,5.160220f},
    {27758,469,571,2526.169189f,-1980.855347f,8.273070f,5.160220f},
    {27758,469,571,2553.052734f,-1882.842896f,4.512696f,6.110557f},
    // captain
    {27759,469,571,2485.295898f,-1889.402344f,9.714134f,6.202426f},
    // blacksmith
    {29252,469,571,2476.218750f,-1953.859131f,10.883574f,1.297610f},
    // vendor
    {27760,469,571,2489.363770f,-1836.897095f,11.650964f,5.528555f},
    // stable master
    {29250,469,571,2551.742188f,-1835.743652f,10.553280f,2.068092f}
};

enum VentureStates
{
    VENTURE_N   = 1,
    VENTURE_N_A = 2,
    VENTURE_A   = 4,
    VENTURE_N_H = 8,
    VENTURE_H   = 16
};

class OutdoorPvPGH;

class OPvPCapturePointGH : public OPvPCapturePoint
{
    friend class OutdoorPvPGH;

    public:

        OPvPCapturePointGH(OutdoorPvP * pvp);

        bool Update(uint32 diff);

        void ChangeState();

        void SendChangePhase();

        void FillInitialWorldStates(WorldPacket & data);

        // used when player is activated/inactivated in the area
        bool HandlePlayerEnter(Player * plr);
        void HandlePlayerLeave(Player * plr);

    protected:

        // called when a faction takes control
        void FactionTakeOver(uint32 team);

        void DeSpawnNPCs();
        void SpawnNPCsForTeam(uint32 team);

        void UpdateVentureWorldState();

    private:

        bool m_capturable;

        uint32 m_ControllingFaction;
        uint32 m_VentureState;
};

class OutdoorPvPGH : public OutdoorPvP
{
    friend class OPvPCapturePointGH;

    public:

        OutdoorPvPGH();

        bool SetupOutdoorPvP();

        void HandlePlayerEnterZone(Player *plr, uint32 zone);
        void HandlePlayerLeaveZone(Player *plr, uint32 zone);

        bool Update(uint32 diff);

        void FillInitialWorldStates(WorldPacket &data);

        void SendRemoveWorldStates(Player * plr);

        void HandleKillImpl(Player * plr, Unit * killed);

    private:

        OPvPCapturePointGH * m_obj;
};

#endif