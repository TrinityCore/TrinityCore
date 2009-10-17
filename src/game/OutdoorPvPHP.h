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
#ifndef OUTDOOR_PVP_HP_
#define OUTDOOR_PVP_HP_
#include "OutdoorPvPImpl.h"
#define OutdoorPvPHPBuffZonesNum 6
                                                         //  HP, citadel, ramparts, blood furnace, shattered halls, mag's lair
const uint32 OutdoorPvPHPBuffZones[OutdoorPvPHPBuffZonesNum] = { 3483, 3563, 3562, 3713, 3714, 3836 };
enum OutdoorPvPHPSpells
{
    AlliancePlayerKillReward = 32155,
    HordePlayerKillReward = 32158,
    AllianceBuff = 32071,
    HordeBuff = 32049
};
enum OutdoorPvPHPTowerType{
    HP_TOWER_BROKEN_HILL = 0,
    HP_TOWER_OVERLOOK = 1,
    HP_TOWER_STADIUM = 2,
    HP_TOWER_NUM = 3
};
const uint32 HP_CREDITMARKER[HP_TOWER_NUM] = {19032,19028,19029};
const uint32 HP_CapturePointEvent_Enter[HP_TOWER_NUM] = {11404,11396,11388};
const uint32 HP_CapturePointEvent_Leave[HP_TOWER_NUM] = {11403,11395,11387};
enum OutdoorPvPHPWorldStates{
    HP_UI_TOWER_DISPLAY_A = 0x9ba,
    HP_UI_TOWER_DISPLAY_H = 0x9b9,
    HP_UI_TOWER_COUNT_H = 0x9ae,
    HP_UI_TOWER_COUNT_A = 0x9ac,
    HP_UI_TOWER_SLIDER_N = 2475,
    HP_UI_TOWER_SLIDER_POS = 2474,
    HP_UI_TOWER_SLIDER_DISPLAY = 2473
};
const uint32 HP_MAP_N[HP_TOWER_NUM] = {0x9b5,0x9b2,0x9a8};
const uint32 HP_MAP_A[HP_TOWER_NUM] = {0x9b3,0x9b0,0x9a7};
const uint32 HP_MAP_H[HP_TOWER_NUM] = {0x9b4,0x9b1,0x9a6};
const uint32 HP_TowerArtKit_A[HP_TOWER_NUM] = {65,62,67};
const uint32 HP_TowerArtKit_H[HP_TOWER_NUM] = {64,61,68};
const uint32 HP_TowerArtKit_N[HP_TOWER_NUM] = {66,63,69};
const go_type HPCapturePoints[HP_TOWER_NUM] = {
    {182175,530,-471.462,3451.09,34.6432,0.174533,0,0,0.087156,0.996195},      // 0 - Broken Hill
    {182174,530,-184.889,3476.93,38.205,-0.017453,0,0,0.008727,-0.999962},     // 1 - Overlook
    {182173,530,-290.016,3702.42,56.6729,0.034907,0,0,0.017452,0.999848}     // 2 - Stadium
};
const go_type HPTowerFlags[HP_TOWER_NUM] = {
    {183514,530,-467.078,3528.17,64.7121,3.14159,0,0,1,0},  // 0 broken hill
    {182525,530,-187.887,3459.38,60.0403,-3.12414,0,0,0.999962,-0.008727}, // 1 overlook
    {183515,530,-289.610,3696.83,75.9447,3.12414,0,0,0.999962,0.008727} // 2 stadium
};
class OPvPCapturePointHP : public OPvPCapturePoint
{
public:
    OPvPCapturePointHP(OutdoorPvP * pvp, OutdoorPvPHPTowerType type);
    void ChangeState();
    void SendChangePhase();
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
private:
    OutdoorPvPHPTowerType m_TowerType;
};
class OutdoorPvPHP : public OutdoorPvP
{
friend class OPvPCapturePointHP;
public:
    OutdoorPvPHP();
    bool SetupOutdoorPvP();
    void HandlePlayerEnterZone(Player *plr, uint32 zone);
    void HandlePlayerLeaveZone(Player *plr, uint32 zone);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket &data);
    void SendRemoveWorldStates(Player * plr);
    void HandleKillImpl(Player * plr, Unit * killed);
private:
    // how many towers are controlled
    uint32 m_AllianceTowersControlled;
    uint32 m_HordeTowersControlled;
};
#endif

