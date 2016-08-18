/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "BattlegroundEY.h"
#include "WorldPacket.h"
#include "BattlegroundMgr.h"
#include "Creature.h"
#include "Language.h"
#include "Player.h"
#include "Util.h"
#include "ObjectAccessor.h"

BattlegroundGOSpawnPoint const BG_EY_GameObjects[BG_EY_OBJECT_MAX] =
{
    // doors
    { BG_OBJECT_A_DOOR_EY_ENTRY,           { 2527.600000f, 1596.910000f, 1262.130000f, -3.124140f }, { -0.173642f, -0.001515f,  0.9847700f, -0.008594f }, RESPAWN_IMMEDIATELY },
    { BG_OBJECT_H_DOOR_EY_ENTRY,           { 1803.210000f, 1539.490000f, 1261.090000f,  3.141590f }, {  0.173648f,  0.000000f,  0.9848080f,  0.000000f }, RESPAWN_IMMEDIATELY },
    // banners (alliance)
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2057.460000f, 1735.070000f, 1187.910000f, -0.925024f }, {  0.000000f,  0.000000f,  0.4461980f, -0.894934f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2032.250000f, 1729.530000f, 1190.330000f,  1.867500f }, {  0.000000f,  0.000000f,  0.8038570f,  0.594823f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2092.350000f, 1775.460000f, 1187.080000f, -0.401426f }, {  0.000000f,  0.000000f,  0.1993680f, -0.979925f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2047.190000f, 1349.190000f, 1189.000000f, -1.623160f }, {  0.000000f,  0.000000f,  0.7253740f, -0.688354f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2074.320000f, 1385.780000f, 1194.720000f,  0.488692f }, {  0.000000f,  0.000000f,  0.2419220f,  0.970296f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2025.130000f, 1386.120000f, 1192.740000f,  2.391100f }, {  0.000000f,  0.000000f,  0.9304180f,  0.366501f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2276.800000f, 1400.410000f, 1196.330000f,  2.443460f }, {  0.000000f,  0.000000f,  0.9396930f,  0.342020f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2305.780000f, 1404.560000f, 1199.380000f,  1.745330f }, {  0.000000f,  0.000000f,  0.7660440f,  0.642788f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2245.400000f, 1366.410000f, 1195.280000f,  2.216570f }, {  0.000000f,  0.000000f,  0.8949340f,  0.446198f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2270.840000f, 1784.080000f, 1186.760000f,  2.426010f }, {  0.000000f,  0.000000f,  0.9366720f,  0.350207f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2269.130000f, 1737.700000f, 1186.660000f,  0.994838f }, {  0.000000f,  0.000000f,  0.4771590f,  0.878817f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_A_BANNER_EY_ENTRY,         { 2300.860000f, 1741.250000f, 1187.700000f, -0.785398f }, {  0.000000f,  0.000000f,  0.3826830f, -0.923880f }, RESPAWN_ONE_DAY     },
    // banners (horde)
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2057.460000f, 1735.070000f, 1187.910000f, -0.925024f }, {  0.000000f,  0.000000f,  0.4461980f, -0.894934f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2032.250000f, 1729.530000f, 1190.330000f,  1.867500f }, {  0.000000f,  0.000000f,  0.8038570f,  0.594823f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2092.350000f, 1775.460000f, 1187.080000f, -0.401426f }, {  0.000000f,  0.000000f,  0.1993680f, -0.979925f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2047.190000f, 1349.190000f, 1189.000000f, -1.623160f }, {  0.000000f,  0.000000f,  0.7253740f, -0.688354f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2074.320000f, 1385.780000f, 1194.720000f,  0.488692f }, {  0.000000f,  0.000000f,  0.2419220f,  0.970296f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2025.130000f, 1386.120000f, 1192.740000f,  2.391100f }, {  0.000000f,  0.000000f,  0.9304180f,  0.366501f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2276.800000f, 1400.410000f, 1196.330000f,  2.443460f }, {  0.000000f,  0.000000f,  0.9396930f,  0.342020f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2305.780000f, 1404.560000f, 1199.380000f,  1.745330f }, {  0.000000f,  0.000000f,  0.7660440f,  0.642788f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2245.400000f, 1366.410000f, 1195.280000f,  2.216570f }, {  0.000000f,  0.000000f,  0.8949340f,  0.446198f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2270.840000f, 1784.080000f, 1186.760000f,  2.426010f }, {  0.000000f,  0.000000f,  0.9366720f,  0.350207f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2269.130000f, 1737.700000f, 1186.660000f,  0.994838f }, {  0.000000f,  0.000000f,  0.4771590f,  0.878817f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_H_BANNER_EY_ENTRY,         { 2300.860000f, 1741.250000f, 1187.700000f, -0.785398f }, {  0.000000f,  0.000000f,  0.3826830f, -0.923880f }, RESPAWN_ONE_DAY     },
    // banners (natural)
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2057.460000f, 1735.070000f, 1187.910000f, -0.925024f }, {  0.000000f,  0.000000f,  0.4461980f, -0.894934f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2032.250000f, 1729.530000f, 1190.330000f,  1.867500f }, {  0.000000f,  0.000000f,  0.8038570f,  0.594823f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2092.350000f, 1775.460000f, 1187.080000f, -0.401426f }, {  0.000000f,  0.000000f,  0.1993680f, -0.979925f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2047.190000f, 1349.190000f, 1189.000000f, -1.623160f }, {  0.000000f,  0.000000f,  0.7253740f, -0.688354f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2074.320000f, 1385.780000f, 1194.720000f,  0.488692f }, {  0.000000f,  0.000000f,  0.2419220f,  0.970296f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2025.130000f, 1386.120000f, 1192.740000f,  2.391100f }, {  0.000000f,  0.000000f,  0.9304180f,  0.366501f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2276.800000f, 1400.410000f, 1196.330000f,  2.443460f }, {  0.000000f,  0.000000f,  0.9396930f,  0.342020f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2305.780000f, 1404.560000f, 1199.380000f,  1.745330f }, {  0.000000f,  0.000000f,  0.7660440f,  0.642788f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2245.400000f, 1366.410000f, 1195.280000f,  2.216570f }, {  0.000000f,  0.000000f,  0.8949340f,  0.446198f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2270.840000f, 1784.080000f, 1186.760000f,  2.426010f }, {  0.000000f,  0.000000f,  0.9366720f,  0.350207f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2269.130000f, 1737.700000f, 1186.660000f,  0.994838f }, {  0.000000f,  0.000000f,  0.4771590f,  0.878817f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_N_BANNER_EY_ENTRY,         { 2300.860000f, 1741.250000f, 1187.700000f, -0.785398f }, {  0.000000f,  0.000000f,  0.3826830f, -0.923880f }, RESPAWN_ONE_DAY     },
    // tower cap
    { BG_OBJECT_FR_TOWER_CAP_EY_ENTRY,     { 2024.600708f, 1742.819580f, 1195.157715f,  2.443461f }, {  0.000000f,  0.000000f,  0.9396930f,  0.342020f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_BE_TOWER_CAP_EY_ENTRY,     { 2050.493164f, 1372.235962f, 1194.563477f,  1.710423f }, {  0.000000f,  0.000000f,  0.7547100f,  0.656059f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_DR_TOWER_CAP_EY_ENTRY,     { 2301.010498f, 1386.931641f, 1197.183472f,  1.570796f }, {  0.000000f,  0.000000f,  0.7071070f,  0.707107f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_HU_TOWER_CAP_EY_ENTRY,     { 2282.121582f, 1760.006958f, 1189.707153f,  1.919862f }, {  0.000000f,  0.000000f,  0.8191520f,  0.573576f }, RESPAWN_ONE_DAY     },
    // flags
    { BG_OBJECT_FLAG2_EY_ENTRY,            { 2174.782227f, 1569.054688f, 1160.361938f, -1.448624f }, {  0.000000f,  0.000000f,  0.6626200f, -0.748956f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_FLAG1_EY_ENTRY,            { 2044.280000f, 1729.680000f, 1189.960000f, -0.017453f }, {  0.000000f,  0.000000f,  0.0087270f, -0.999962f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_FLAG1_EY_ENTRY,            { 2048.830000f, 1393.650000f, 1194.490000f,  0.209440f }, {  0.000000f,  0.000000f,  0.1045280f,  0.994522f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_FLAG1_EY_ENTRY,            { 2286.560000f, 1402.360000f, 1197.110000f,  3.723810f }, {  0.000000f,  0.000000f,  0.9579260f, -0.287016f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_FLAG1_EY_ENTRY,            { 2284.480000f, 1731.230000f, 1189.990000f,  2.897250f }, {  0.000000f,  0.000000f,  0.9925460f,  0.121869f }, RESPAWN_ONE_DAY     },
    // buffs
    { BG_OBJECT_SPEED_BUFF_BLOOD_ELF,      { 2050.468000f, 1372.202000f, 1194.563000f,  1.675514f }, {  0.000000f,  0.000000f,  0.7431440f, 0.6691315f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_RESTORATION_BLOOD_ELF,     { 2050.468000f, 1372.202000f, 1194.563000f,  1.675514f }, {  0.000000f,  0.000000f,  0.7431440f, 0.6691315f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_BERSERK_BLOOD_ELF,         { 2050.468000f, 1372.202000f, 1194.563000f,  1.675514f }, {  0.000000f,  0.000000f,  0.7431440f, 0.6691315f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_SPEED_BUFF_FEL_REAVER,     { 2046.463000f, 1749.167000f, 1190.010000f,  5.410522f }, {  0.000000f,  0.000000f, -0.4226179f, 0.9063079f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_RESTORATION_FEL_REAVER,    { 2046.463000f, 1749.167000f, 1190.010000f,  5.410522f }, {  0.000000f,  0.000000f, -0.4226179f, 0.9063079f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_BERSERK_FEL_REAVER,        { 2046.463000f, 1749.167000f, 1190.010000f,  5.410522f }, {  0.000000f,  0.000000f, -0.4226179f, 0.9063079f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_SPEED_BUFF_MAGE_TOWER,     { 2283.710000f, 1748.870000f, 1189.707000f, -1.500983f }, {  0.000000f,  0.000000f, -0.6819983f, 0.7313538f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_RESTORATION_MAGE_TOWER,    { 2283.710000f, 1748.870000f, 1189.707000f, -1.500983f }, {  0.000000f,  0.000000f, -0.6819983f, 0.7313538f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_BERSERK_MAGE_TOWER,        { 2283.710000f, 1748.870000f, 1189.707000f, -1.500983f }, {  0.000000f,  0.000000f, -0.6819983f, 0.7313538f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_SPEED_BUFF_DRAENEI_RUINS,  { 2302.477000f, 1391.245000f, 1197.736000f,  1.762782f }, {  0.000000f,  0.000000f,  0.7716246f, 0.6360782f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_RESTORATION_DRAENEI_RUINS, { 2302.477000f, 1391.245000f, 1197.736000f,  1.762782f }, {  0.000000f,  0.000000f,  0.7716246f, 0.6360782f }, RESPAWN_ONE_DAY     },
    { BG_OBJECT_BERSERK_DRAENEI_RUINS,     { 2302.477000f, 1391.245000f, 1197.736000f,  1.762782f }, {  0.000000f,  0.000000f,  0.7716246f, 0.6360782f }, RESPAWN_ONE_DAY     }
};

std::vector<BattlegroundBuffEntries> const buffEntries =
{
    { BG_OBJECT_SPEED_BUFF_BLOOD_ELF,     BG_OBJECT_RESTORATION_BLOOD_ELF,     BG_OBJECT_BERSERK_BLOOD_ELF     },
    { BG_OBJECT_SPEED_BUFF_FEL_REAVER,    BG_OBJECT_RESTORATION_FEL_REAVER,    BG_OBJECT_BERSERK_FEL_REAVER    },
    { BG_OBJECT_SPEED_BUFF_MAGE_TOWER,    BG_OBJECT_RESTORATION_MAGE_TOWER,    BG_OBJECT_BERSERK_MAGE_TOWER    },
    { BG_OBJECT_SPEED_BUFF_DRAENEI_RUINS, BG_OBJECT_RESTORATION_DRAENEI_RUINS, BG_OBJECT_BERSERK_DRAENEI_RUINS }
};

// these variables aren't used outside of this file, so declare them only here
uint32 BG_EY_HonorScoreTicks[BG_HONOR_MODE_NUM] =
{
    260, // normal honor
    160  // holiday
};

Position const BG_EY_TriggerPositions[EY_POINTS_MAX] =
{
    { 2044.28f, 1729.68f, 1189.96f, 0.017453f },  // FEL_REAVER center
    { 2048.83f, 1393.65f, 1194.49f, 0.20944f },   // BLOOD_ELF center
    { 2286.56f, 1402.36f, 1197.11f, 3.72381f },   // DRAENEI_RUINS center
    { 2284.48f, 1731.23f, 1189.99f, 2.89725f }    // MAGE_TOWER center
};

uint8  const BG_EY_TickPoints[EY_POINTS_MAX] = { 1, 2, 5, 10 };
uint32 const BG_EY_FlagPoints[EY_POINTS_MAX] = { 75, 85, 100, 500 };

//constant arrays:
BattlegroundEYPointIconsStruct const m_PointsIconStruct[EY_POINTS_MAX] =
{
    { FEL_REAVER_UNCONTROL,    FEL_REAVER_ALLIANCE_CONTROL,    FEL_REAVER_HORDE_CONTROL    },
    { BLOOD_ELF_UNCONTROL,     BLOOD_ELF_ALLIANCE_CONTROL,     BLOOD_ELF_HORDE_CONTROL     },
    { DRAENEI_RUINS_UNCONTROL, DRAENEI_RUINS_ALLIANCE_CONTROL, DRAENEI_RUINS_HORDE_CONTROL },
    { MAGE_TOWER_UNCONTROL,    MAGE_TOWER_ALLIANCE_CONTROL,    MAGE_TOWER_HORDE_CONTROL    }
};

BattlegroundEYLosingPointStruct const m_LosingPointTypes[EY_POINTS_MAX] =
{
    { BG_EY_OBJECT_N_BANNER_FEL_REAVER_CENTER,    BG_EY_OBJECT_A_BANNER_FEL_REAVER_CENTER,    LANG_BG_EY_HAS_LOST_A_F_RUINS, BG_EY_OBJECT_H_BANNER_FEL_REAVER_CENTER,    LANG_BG_EY_HAS_LOST_H_F_RUINS },
    { BG_EY_OBJECT_N_BANNER_BLOOD_ELF_CENTER,     BG_EY_OBJECT_A_BANNER_BLOOD_ELF_CENTER,     LANG_BG_EY_HAS_LOST_A_B_TOWER, BG_EY_OBJECT_H_BANNER_BLOOD_ELF_CENTER,     LANG_BG_EY_HAS_LOST_H_B_TOWER },
    { BG_EY_OBJECT_N_BANNER_DRAENEI_RUINS_CENTER, BG_EY_OBJECT_A_BANNER_DRAENEI_RUINS_CENTER, LANG_BG_EY_HAS_LOST_A_D_RUINS, BG_EY_OBJECT_H_BANNER_DRAENEI_RUINS_CENTER, LANG_BG_EY_HAS_LOST_H_D_RUINS },
    { BG_EY_OBJECT_N_BANNER_MAGE_TOWER_CENTER,    BG_EY_OBJECT_A_BANNER_MAGE_TOWER_CENTER,    LANG_BG_EY_HAS_LOST_A_M_TOWER, BG_EY_OBJECT_H_BANNER_MAGE_TOWER_CENTER,    LANG_BG_EY_HAS_LOST_H_M_TOWER }
};

BattlegroundEYCapturingPointStruct const m_CapturingPointTypes[EY_POINTS_MAX] =
{
    { BG_EY_OBJECT_N_BANNER_FEL_REAVER_CENTER,    BG_EY_OBJECT_A_BANNER_FEL_REAVER_CENTER,    LANG_BG_EY_HAS_TAKEN_A_F_RUINS, BG_EY_OBJECT_H_BANNER_FEL_REAVER_CENTER,    LANG_BG_EY_HAS_TAKEN_H_F_RUINS, EY_GRAVEYARD_FEL_REAVER    },
    { BG_EY_OBJECT_N_BANNER_BLOOD_ELF_CENTER,     BG_EY_OBJECT_A_BANNER_BLOOD_ELF_CENTER,     LANG_BG_EY_HAS_TAKEN_A_B_TOWER, BG_EY_OBJECT_H_BANNER_BLOOD_ELF_CENTER,     LANG_BG_EY_HAS_TAKEN_H_B_TOWER, EY_GRAVEYARD_BLOOD_ELF     },
    { BG_EY_OBJECT_N_BANNER_DRAENEI_RUINS_CENTER, BG_EY_OBJECT_A_BANNER_DRAENEI_RUINS_CENTER, LANG_BG_EY_HAS_TAKEN_A_D_RUINS, BG_EY_OBJECT_H_BANNER_DRAENEI_RUINS_CENTER, LANG_BG_EY_HAS_TAKEN_H_D_RUINS, EY_GRAVEYARD_DRAENEI_RUINS },
    { BG_EY_OBJECT_N_BANNER_MAGE_TOWER_CENTER,    BG_EY_OBJECT_A_BANNER_MAGE_TOWER_CENTER,    LANG_BG_EY_HAS_TAKEN_A_M_TOWER, BG_EY_OBJECT_H_BANNER_MAGE_TOWER_CENTER,    LANG_BG_EY_HAS_TAKEN_H_M_TOWER, EY_GRAVEYARD_MAGE_TOWER    }
};

BattlegroundEY::BattlegroundEY()
{
    SetChangeBuffs(true, &buffEntries);

    SetGameObjectsNumber(BG_EY_OBJECT_MAX);
    SetCreaturesNumber(BG_EY_CREATURES_MAX);

    m_Points_Trigger[FEL_REAVER] = TR_FEL_REAVER_BUFF;
    m_Points_Trigger[BLOOD_ELF] = TR_BLOOD_ELF_BUFF;
    m_Points_Trigger[DRAENEI_RUINS] = TR_DRAENEI_RUINS_BUFF;
    m_Points_Trigger[MAGE_TOWER] = TR_MAGE_TOWER_BUFF;
    m_HonorScoreTics[TEAM_ALLIANCE] = 0;
    m_HonorScoreTics[TEAM_HORDE] = 0;
    m_TeamPointsCount[TEAM_ALLIANCE] = 0;
    m_TeamPointsCount[TEAM_HORDE] = 0;
    m_FlagKeeper.Clear();
    m_DroppedFlagGUID.Clear();
    m_FlagCapturedBgObjectType = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    m_FlagsTimer = 0;
    m_TowerCapCheckTimer = 0;
    m_PointAddingTimer = 0;
    m_HonorTics = 0;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        m_PointOwnedByTeam[i] = EY_POINT_NO_OWNER;
        m_PointState[i] = EY_POINT_STATE_UNCONTROLLED;
        m_PointBarStatus[i] = BG_EY_PROGRESS_BAR_STATE_MIDDLE;
    }

    for (uint8 i = 0; i < BG_TEAMS_COUNT * EY_POINTS_MAX; ++i)
        m_CurrentPointPlayersCount[i] = 0;

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_EY_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_EY_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_EY_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_EY_HAS_BEGUN;
}

BattlegroundEY::~BattlegroundEY() { }

void BattlegroundEY::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        m_PointAddingTimer -= diff;
        if (m_PointAddingTimer <= 0)
        {
            m_PointAddingTimer = BG_EY_FPOINTS_TICK_TIME;
            if (m_TeamPointsCount[TEAM_ALLIANCE] > 0)
                AddPoints(ALLIANCE, BG_EY_TickPoints[m_TeamPointsCount[TEAM_ALLIANCE] - 1]);
            if (m_TeamPointsCount[TEAM_HORDE] > 0)
                AddPoints(HORDE, BG_EY_TickPoints[m_TeamPointsCount[TEAM_HORDE] - 1]);
        }

        if (m_FlagState == BG_EY_FLAG_STATE_WAIT_RESPAWN || m_FlagState == BG_EY_FLAG_STATE_ON_GROUND)
        {
            m_FlagsTimer -= diff;

            if (m_FlagsTimer < 0)
            {
                m_FlagsTimer = 0;
                if (m_FlagState == BG_EY_FLAG_STATE_WAIT_RESPAWN)
                    RespawnFlag(true);
                else
                    RespawnFlagAfterDrop();
            }
        }

        m_TowerCapCheckTimer -= diff;
        if (m_TowerCapCheckTimer <= 0)
        {
            //check if player joined point
            /*I used this order of calls, because although we will check if one player is in gameobject's distance 2 times
              but we can count of players on current point in CheckSomeoneLeftPoint
            */
            CheckSomeoneJoinedPoint();
            //check if player left point
            CheckSomeoneLeftPoint();
            UpdatePointStatuses();
            m_TowerCapCheckTimer = BG_EY_FPOINTS_TICK_TIME;
        }
    }
}

void BattlegroundEY::StartingEventCloseDoors()
{
    SpawnBGObject(BG_EY_OBJECT_DOOR_A, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_EY_OBJECT_DOOR_H, RESPAWN_IMMEDIATELY);

    for (uint32 i = BG_EY_OBJECT_A_BANNER_FEL_REAVER_CENTER; i < BG_EY_OBJECT_MAX; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);
}

void BattlegroundEY::StartingEventOpenDoors()
{
    SpawnBGObject(BG_EY_OBJECT_DOOR_A, RESPAWN_ONE_DAY);
    SpawnBGObject(BG_EY_OBJECT_DOOR_H, RESPAWN_ONE_DAY);

    for (uint32 i = BG_EY_OBJECT_N_BANNER_FEL_REAVER_CENTER; i <= BG_EY_OBJECT_FLAG_NETHERSTORM; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);

    for (uint32 i = 0; i < EY_POINTS_MAX; ++i)
    {
        //randomly spawn buff
        uint8 buff = urand(0, BG_MAX_BUFFS - 1);
        SpawnBGObject(BG_EY_OBJECT_SPEEDBUFF_BLOOD_ELF + i * BG_MAX_BUFFS + buff, RESPAWN_IMMEDIATELY);
    }

    // Achievement: Flurry
    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, BG_EY_EVENT_START_BATTLE);
}

void BattlegroundEY::AddPoints(uint32 Team, uint32 Points)
{
    TeamId team_index = GetTeamIndexByTeamId(Team);
    m_TeamScores[team_index] += Points;
    m_HonorScoreTics[team_index] += Points;
    if (m_HonorScoreTics[team_index] >= m_HonorTics)
    {
        RewardHonorToTeam(GetBonusHonorFromKill(1), Team);
        m_HonorScoreTics[team_index] -= m_HonorTics;
    }
    UpdateTeamScore(team_index);
}

void BattlegroundEY::CheckSomeoneJoinedPoint()
{
    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        if (GameObject* obj = GetBGObject(BG_EY_OBJECT_TOWER_CAP_FEL_REAVER + i))
        {
            uint8 j = 0;
            while (j < m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].size())
            {
                Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS][j]);
                if (!player)
                {
                    TC_LOG_ERROR("bg.battleground", "BattlegroundEY:CheckSomeoneJoinedPoint: Player (%s) could not be found!", m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS][j].ToString().c_str());
                    ++j;
                    continue;
                }
                if (player->CanCaptureTowerPoint() && player->IsWithinDistInMap(obj, BG_EY_POINT_RADIUS))
                {
                    //player joined point!
                    //show progress bar
                    UpdateWorldStateForPlayer(PROGRESS_BAR_PERCENT_GREY, BG_EY_PROGRESS_BAR_PERCENT_GREY, player);
                    UpdateWorldStateForPlayer(PROGRESS_BAR_STATUS, m_PointBarStatus[i], player);
                    UpdateWorldStateForPlayer(PROGRESS_BAR_SHOW, BG_EY_PROGRESS_BAR_SHOW, player);
                    //add player to point
                    m_PlayersNearPoint[i].push_back(m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS][j]);
                    //remove player from "free space"
                    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].erase(m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].begin() + j);
                }
                else
                    ++j;
            }
        }
    }
}

void BattlegroundEY::CheckSomeoneLeftPoint()
{
    //reset current point counts
    for (uint8 i = 0; i < BG_TEAMS_COUNT * EY_POINTS_MAX; ++i)
        m_CurrentPointPlayersCount[i] = 0;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        if (GameObject* obj = GetBGObject(BG_EY_OBJECT_TOWER_CAP_FEL_REAVER + i))
        {
            uint8 j = 0;
            while (j < m_PlayersNearPoint[i].size())
            {
                Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[i][j]);
                if (!player)
                {
                    //move non-existing players to "free space" - this will cause many errors showing in log, but it is a very important bug
                    TC_LOG_ERROR("bg.battleground", "BattlegroundEY:CheckSomeoneLeftPoint Player (%s) could not be found!", m_PlayersNearPoint[i][j].ToString().c_str());
                    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].push_back(m_PlayersNearPoint[i][j]);
                    m_PlayersNearPoint[i].erase(m_PlayersNearPoint[i].begin() + j);
                    continue;
                }

                if (!player->CanCaptureTowerPoint() || !player->IsWithinDistInMap(obj, BG_EY_POINT_RADIUS))
                {
                    //move player out of point (add him to players that are out of points
                    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].push_back(m_PlayersNearPoint[i][j]);
                    m_PlayersNearPoint[i].erase(m_PlayersNearPoint[i].begin() + j);
                    UpdateWorldStateForPlayer(PROGRESS_BAR_SHOW, BG_EY_PROGRESS_BAR_DONT_SHOW, player);
                }
                else
                {
                    //player is near flag, so update count
                    ++m_CurrentPointPlayersCount[BG_TEAMS_COUNT * i + GetTeamIndexByTeamId(player->GetTeam())];
                    ++j;
                }
            }
        }
    }
}

void BattlegroundEY::UpdatePointStatuses()
{
    for (uint8 point = 0; point < EY_POINTS_MAX; ++point)
    {
        if (m_PlayersNearPoint[point].empty())
            continue;

        int32 allianceCount = m_CurrentPointPlayersCount[BG_TEAMS_COUNT * point + TEAM_ALLIANCE];
        int32 hordeCount = m_CurrentPointPlayersCount[BG_TEAMS_COUNT * point + TEAM_HORDE];

        //count new point bar status:
        m_PointBarStatus[point] += std::min<int32>(allianceCount - hordeCount, BG_EY_POINT_MAX_CAPTURERS_COUNT);

        if (m_PointBarStatus[point] > BG_EY_PROGRESS_BAR_ALI_CONTROLLED)
            //point is fully alliance's
            m_PointBarStatus[point] = BG_EY_PROGRESS_BAR_ALI_CONTROLLED;
        if (m_PointBarStatus[point] < BG_EY_PROGRESS_BAR_HORDE_CONTROLLED)
            //point is fully horde's
            m_PointBarStatus[point] = BG_EY_PROGRESS_BAR_HORDE_CONTROLLED;

        uint32 pointOwnerTeamId = 0;
        //find which team should own this point
        if (m_PointBarStatus[point] <= BG_EY_PROGRESS_BAR_NEUTRAL_LOW)
            pointOwnerTeamId = HORDE;
        else if (m_PointBarStatus[point] >= BG_EY_PROGRESS_BAR_NEUTRAL_HIGH)
            pointOwnerTeamId = ALLIANCE;
        else
            pointOwnerTeamId = EY_POINT_NO_OWNER;

        for (uint8 i = 0; i < m_PlayersNearPoint[point].size(); ++i)
        {
            Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[point][i]);
            if (player)
            {
                UpdateWorldStateForPlayer(PROGRESS_BAR_STATUS, m_PointBarStatus[point], player);
                //if point owner changed we must evoke event!
                if (pointOwnerTeamId != m_PointOwnedByTeam[point])
                {
                    //point was uncontrolled and player is from team which captured point
                    if (m_PointState[point] == EY_POINT_STATE_UNCONTROLLED && player->GetTeam() == pointOwnerTeamId)
                        EventTeamCapturedPoint(player, EYBattlegroundPoints(point));

                    //point was under control and player isn't from team which controlled it
                    if (m_PointState[point] == EY_POINT_UNDER_CONTROL && player->GetTeam() != m_PointOwnedByTeam[point])
                        EventTeamLostPoint(player, EYBattlegroundPoints(point));
                }

                /// @workaround The original AreaTrigger is covered by a bigger one and not triggered on client side.
                if (point == FEL_REAVER && m_PointOwnedByTeam[point] == player->GetTeam())
                    if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                        if (player->GetDistance(2044.0f, 1729.729f, 1190.03f) < 3.0f)
                            EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_FEL_REAVER);
            }
        }
    }
}

void BattlegroundEY::UpdateTeamScore(uint32 Team)
{
    uint32 score = GetTeamScore(Team);
    /// @todo there should be some sound played when one team is near victory!! - and define variables
    /*if (!m_IsInformedNearVictory && score >= BG_EY_WARNING_NEAR_VICTORY_SCORE)
    {
        if (Team == ALLIANCE)
            SendMessageToAll(LANG_BG_EY_A_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        else
            SendMessageToAll(LANG_BG_EY_H_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        PlaySoundToAll(BG_EY_SOUND_NEAR_VICTORY);
        m_IsInformedNearVictory = true;
    }*/

    if (score >= BG_EY_MAX_TEAM_SCORE)
    {
        score = BG_EY_MAX_TEAM_SCORE;
        if (Team == TEAM_ALLIANCE)
            EndBattleground(ALLIANCE);
        else
            EndBattleground(HORDE);
    }

    if (Team == TEAM_ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_RESOURCES, score);
    else
        UpdateWorldState(EY_HORDE_RESOURCES, score);
}

void BattlegroundEY::EndBattleground(uint32 winner)
{
    // Win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    // Complete map reward
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundEY::UpdatePointsCount(uint32 Team)
{
    if (Team == ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_BASE, m_TeamPointsCount[TEAM_ALLIANCE]);
    else
        UpdateWorldState(EY_HORDE_BASE, m_TeamPointsCount[TEAM_HORDE]);
}

void BattlegroundEY::UpdatePointsIcons(uint32 Team, EYBattlegroundPoints Point)
{
    //we MUST firstly send 0, after that we can send 1!!!
    if (m_PointState[Point] == EY_POINT_UNDER_CONTROL)
    {
        UpdateWorldState(m_PointsIconStruct[Point].WorldStateControlIndex, 0);
        if (Team == ALLIANCE)
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateAllianceControlledIndex, 1);
        else
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateHordeControlledIndex, 1);
    }
    else
    {
        if (Team == ALLIANCE)
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateAllianceControlledIndex, 0);
        else
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateHordeControlledIndex, 0);
        UpdateWorldState(m_PointsIconStruct[Point].WorldStateControlIndex, 1);
    }
}

void BattlegroundEY::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID().GetCounter()] = new BattlegroundEYScore(player->GetGUID());

    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].push_back(player->GetGUID());
}

void BattlegroundEY::RemovePlayer(Player* player, ObjectGuid guid, uint32 /*team*/)
{
    // sometimes flag aura not removed :(
    for (int32 j = EY_PLAYERS_OUT_OF_POINTS; j >= 0; --j)
    {
        for (size_t i = 0; i < m_PlayersNearPoint[j].size(); ++i)
            if (m_PlayersNearPoint[j][i] == guid)
                m_PlayersNearPoint[j].erase(m_PlayersNearPoint[j].begin() + i);
    }

    if (IsFlagPickedup())
    {
        if (m_FlagKeeper == guid)
        {
            if (player)
                EventPlayerDroppedFlag(player);
            else
            {
                SetFlagPicker(ObjectGuid::Empty);
                RespawnFlag(true);
            }
        }
    }
}

void BattlegroundEY::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!player->IsAlive())                                  //hack code, must be removed later
        return;

    switch (trigger)
    {
        case TR_BLOOD_ELF_POINT:
            if (m_PointState[BLOOD_ELF] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[BLOOD_ELF] == player->GetTeam())
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_BLOOD_ELF);
            break;
        case TR_FEL_REAVER_POINT:
            if (m_PointState[FEL_REAVER] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[FEL_REAVER] == player->GetTeam())
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_FEL_REAVER);
            break;
        case TR_MAGE_TOWER_POINT:
            if (m_PointState[MAGE_TOWER] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[MAGE_TOWER] == player->GetTeam())
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_MAGE_TOWER);
            break;
        case TR_DRAENEI_RUINS_POINT:
            if (m_PointState[DRAENEI_RUINS] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[DRAENEI_RUINS] == player->GetTeam())
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_DRAENEI_RUINS);
            break;
        case 4512:
        case 4515:
        case 4517:
        case 4519:
        case 4530:
        case 4531:
        case 4568:
        case 4569:
        case 4570:
        case 4571:
        case 5866:
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

bool BattlegroundEY::SetupBattleground()
{
    for (uint32 i = 0; i < BG_EY_OBJECT_MAX; ++i)
    {
        BattlegroundGOSpawnPoint const& object = BG_EY_GameObjects[i];
        if (!AddObject(i, object.Entry, object.Pos, object.Rot, object.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundEY: Failed to spawn GameObject! (Entry: %u). Battleground not created!", object.Entry);
            return false;
        }
    }

    WorldSafeLocsEntry const* sg = nullptr;
    sg = sWorldSafeLocsStore.LookupEntry(EY_GRAVEYARD_MAIN_ALLIANCE);
    if (!sg || !AddSpiritGuide(EY_SPIRIT_MAIN_ALLIANCE, Position(sg->x, sg->y, sg->z, 3.124139f), TEAM_ALLIANCE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundEY: Failed to spawn spirit guide. The battleground was not created.");
        return false;
    }

    sg = sWorldSafeLocsStore.LookupEntry(EY_GRAVEYARD_MAIN_HORDE);
    if (!sg || !AddSpiritGuide(EY_SPIRIT_MAIN_HORDE, Position(sg->x, sg->y, sg->z, 3.193953f), TEAM_HORDE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundEY: Failed to spawn spirit guide. The battleground was not created.");
        return false;
    }

    return true;
}

void BattlegroundEY::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[TEAM_ALLIANCE] = 0;
    m_TeamScores[TEAM_HORDE] = 0;
    m_TeamPointsCount[TEAM_ALLIANCE] = 0;
    m_TeamPointsCount[TEAM_HORDE] = 0;
    m_HonorScoreTics[TEAM_ALLIANCE] = 0;
    m_HonorScoreTics[TEAM_HORDE] = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    m_FlagCapturedBgObjectType = 0;
    m_FlagKeeper.Clear();
    m_DroppedFlagGUID.Clear();
    m_PointAddingTimer = 0;
    m_TowerCapCheckTimer = 0;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_EY_EYWeekendHonorTicks : BG_EY_NotEYWeekendHonorTicks;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        m_PointOwnedByTeam[i] = EY_POINT_NO_OWNER;
        m_PointState[i] = EY_POINT_STATE_UNCONTROLLED;
        m_PointBarStatus[i] = BG_EY_PROGRESS_BAR_STATE_MIDDLE;
        m_PlayersNearPoint[i].clear();
        m_PlayersNearPoint[i].reserve(15);                  //tip size
    }
    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].clear();
    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].reserve(30);
}

void BattlegroundEY::RespawnFlag(bool send_message)
{
    if (m_FlagCapturedBgObjectType > 0)
        SpawnBGObject(m_FlagCapturedBgObjectType, RESPAWN_ONE_DAY);

    m_FlagCapturedBgObjectType = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    SpawnBGObject(BG_EY_OBJECT_FLAG_NETHERSTORM, RESPAWN_IMMEDIATELY);

    if (send_message)
    {
        SendMessageToAll(LANG_BG_EY_RESETED_FLAG, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        PlaySoundToAll(BG_EY_SOUND_FLAG_RESET);             // flags respawned sound...
    }

    UpdateWorldState(NETHERSTORM_FLAG, 1);
}

void BattlegroundEY::RespawnFlagAfterDrop()
{
    RespawnFlag(true);

    GameObject* obj = GetBgMap()->GetGameObject(GetDroppedFlagGUID());

    if (obj)
        obj->Delete();
    else
        TC_LOG_ERROR("bg.battleground", "BattlegroundEY: Unknown dropped flag (%s).", GetDroppedFlagGUID().ToString().c_str());

    SetDroppedFlagGUID(ObjectGuid::Empty);
}

void BattlegroundEY::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
    EventPlayerDroppedFlag(player);
}

void BattlegroundEY::EventPlayerDroppedFlag(Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
    {
        // if not running, do not cast things at the dropper player, neither send unnecessary messages
        // just take off the aura
        if (IsFlagPickedup() && GetFlagPickerGUID() == player->GetGUID())
        {
            SetFlagPicker(ObjectGuid::Empty);
            player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
        }
        return;
    }

    if (!IsFlagPickedup())
        return;

    if (GetFlagPickerGUID() != player->GetGUID())
        return;

    SetFlagPicker(ObjectGuid::Empty);
    player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
    m_FlagState = BG_EY_FLAG_STATE_ON_GROUND;
    m_FlagsTimer = BG_EY_FLAG_RESPAWN_TIME;
    player->CastSpell(player, SPELL_RECENTLY_DROPPED_FLAG, true);
    player->CastSpell(player, BG_EY_PLAYER_DROPPED_FLAG_SPELL, true);
    //this does not work correctly :((it should remove flag carrier name)
    UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_WAIT_RESPAWN);
    UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_WAIT_RESPAWN);

    if (player->GetTeam() == ALLIANCE)
        SendMessageToAll(LANG_BG_EY_DROPPED_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, nullptr);
    else
        SendMessageToAll(LANG_BG_EY_DROPPED_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, nullptr);
}

void BattlegroundEY::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS || IsFlagPickedup() || !player->IsWithinDistInMap(target_obj, 10))
        return;

    if (player->GetTeam() == ALLIANCE)
    {
        UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_PLAYER);
        PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE);
    }
    else
    {
        UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_PLAYER);
        PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_HORDE);
    }

    if (m_FlagState == BG_EY_FLAG_STATE_ON_BASE)
        UpdateWorldState(NETHERSTORM_FLAG, 0);
    m_FlagState = BG_EY_FLAG_STATE_ON_PLAYER;

    SpawnBGObject(BG_EY_OBJECT_FLAG_NETHERSTORM, RESPAWN_ONE_DAY);
    SetFlagPicker(player->GetGUID());
    //get flag aura on player
    player->CastSpell(player, BG_EY_NETHERSTORM_FLAG_SPELL, true);
    player->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);

    if (player->GetTeam() == ALLIANCE)
        PSendMessageToAll(LANG_BG_EY_HAS_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, nullptr, player->GetName().c_str());
    else
        PSendMessageToAll(LANG_BG_EY_HAS_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, nullptr, player->GetName().c_str());
}

void BattlegroundEY::EventTeamLostPoint(Player* player, EYBattlegroundPoints Point)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    //Natural point
    uint32 Team = m_PointOwnedByTeam[Point];

    if (!Team)
        return;

    if (Team == ALLIANCE)
    {
        --m_TeamPointsCount[TEAM_ALLIANCE];
        for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
            SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeAlliance + i, RESPAWN_ONE_DAY);
    }
    else
    {
        --m_TeamPointsCount[TEAM_HORDE];
        for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
            SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeHorde + i, RESPAWN_ONE_DAY);
    }

    for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
        SpawnBGObject(m_LosingPointTypes[Point].SpawnNeutralObjectType + i, RESPAWN_IMMEDIATELY);

    //buff isn't despawned

    m_PointOwnedByTeam[Point] = EY_POINT_NO_OWNER;
    m_PointState[Point] = EY_POINT_NO_OWNER;

    if (Team == ALLIANCE)
        SendMessageToAll(m_LosingPointTypes[Point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendMessageToAll(m_LosingPointTypes[Point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);

    UpdatePointsIcons(Team, Point);
    UpdatePointsCount(Team);

    //remove bonus honor aura trigger creature when node is lost
     if (Point < EY_POINTS_MAX)
         DelCreature(Point + 6); //NULL checks are in DelCreature! 0-5 spirit guides
}

void BattlegroundEY::EventTeamCapturedPoint(Player* player, EYBattlegroundPoints Point)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (Point >= EY_POINTS_MAX)
        return;

    uint32 Team = player->GetTeam();

    for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
        SpawnBGObject(m_CapturingPointTypes[Point].DespawnNeutralObjectType + i, RESPAWN_ONE_DAY);

    if (Team == ALLIANCE)
    {
        ++m_TeamPointsCount[TEAM_ALLIANCE];
        for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
            SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeAlliance + i, RESPAWN_IMMEDIATELY);
    }
    else
    {
        ++m_TeamPointsCount[TEAM_HORDE];
        for (uint32 i = 0; i < BG_EY_POINT_BANNERS; ++i)
            SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeHorde + i, RESPAWN_IMMEDIATELY);
    }

    //buff isn't respawned

    m_PointOwnedByTeam[Point] = Team;
    m_PointState[Point] = EY_POINT_UNDER_CONTROL;

    if (Team == ALLIANCE)
        SendMessageToAll(m_CapturingPointTypes[Point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendMessageToAll(m_CapturingPointTypes[Point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);

    DelCreature(Point);

    WorldSafeLocsEntry const* sg = nullptr;
    sg = sWorldSafeLocsStore.LookupEntry(m_CapturingPointTypes[Point].GraveYardId);
    if (!sg || !AddSpiritGuide(Point, Position(sg->x, sg->y, sg->z, 3.124139f), GetTeamIndexByTeamId(Team)))
        TC_LOG_ERROR("bg.battleground", "BatteGroundEY: Failed to spawn spirit guide. point: %u, team: %u, graveyard_id: %u",
            Point, Team, m_CapturingPointTypes[Point].GraveYardId);

    // SpawnBGCreature(Point, RESPAWN_IMMEDIATELY);

    UpdatePointsIcons(Team, Point);
    UpdatePointsCount(Team);

    Creature* trigger = GetBGCreature(Point - EY_SPIRIT_FEL_REAVER + EY_TRIGGER_FEL_REAVER, false);
    if (!trigger)
        trigger = AddCreature(WORLD_TRIGGER, Point - EY_SPIRIT_FEL_REAVER + EY_TRIGGER_FEL_REAVER, BG_EY_TriggerPositions[Point]);

    //add bonus honor aura trigger creature when node is accupied
    //cast bonus aura (+50% honor in 25yards)
    //aura should only apply to players who have accupied the node, set correct faction for trigger
    if (trigger)
    {
        trigger->setFaction(Team == ALLIANCE ? 84 : 83);
        trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
    }
}

void BattlegroundEY::EventPlayerCapturedFlag(Player* player, uint32 BgObjectType)
{
    if (GetStatus() != STATUS_IN_PROGRESS || GetFlagPickerGUID() != player->GetGUID())
        return;

    SetFlagPicker(ObjectGuid::Empty);
    m_FlagState = BG_EY_FLAG_STATE_WAIT_RESPAWN;
    player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);

    player->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);

    if (player->GetTeam() == ALLIANCE)
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE);
    else
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_HORDE);

    SpawnBGObject(BgObjectType, RESPAWN_IMMEDIATELY);

    m_FlagsTimer = BG_EY_FLAG_RESPAWN_TIME;
    m_FlagCapturedBgObjectType = BgObjectType;

    uint8 team_id = 0;
    if (player->GetTeam() == ALLIANCE)
    {
        team_id = TEAM_ALLIANCE;
        SendMessageToAll(LANG_BG_EY_CAPTURED_FLAG_A, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    }
    else
    {
        team_id = TEAM_HORDE;
        SendMessageToAll(LANG_BG_EY_CAPTURED_FLAG_H, CHAT_MSG_BG_SYSTEM_HORDE, player);
    }

    if (m_TeamPointsCount[team_id] > 0)
        AddPoints(player->GetTeam(), BG_EY_FlagPoints[m_TeamPointsCount[team_id] - 1]);

    UpdatePlayerScore(player, SCORE_FLAG_CAPTURES, 1);
}

bool BattlegroundEY::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_FLAG_CAPTURES:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, EY_OBJECTIVE_CAPTURE_FLAG);
            break;
        default:
            break;
    }
    return true;
}

void BattlegroundEY::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(EY_HORDE_BASE) << uint32(m_TeamPointsCount[TEAM_HORDE]);
    data << uint32(EY_ALLIANCE_BASE) << uint32(m_TeamPointsCount[TEAM_ALLIANCE]);
    data << uint32(0xab6) << uint32(0x0);
    data << uint32(0xab5) << uint32(0x0);
    data << uint32(0xab4) << uint32(0x0);
    data << uint32(0xab3) << uint32(0x0);
    data << uint32(0xab2) << uint32(0x0);
    data << uint32(0xab1) << uint32(0x0);
    data << uint32(0xab0) << uint32(0x0);
    data << uint32(0xaaf) << uint32(0x0);

    data << uint32(DRAENEI_RUINS_HORDE_CONTROL)     << uint32(m_PointOwnedByTeam[DRAENEI_RUINS] == HORDE && m_PointState[DRAENEI_RUINS] == EY_POINT_UNDER_CONTROL);

    data << uint32(DRAENEI_RUINS_ALLIANCE_CONTROL)  << uint32(m_PointOwnedByTeam[DRAENEI_RUINS] == ALLIANCE && m_PointState[DRAENEI_RUINS] == EY_POINT_UNDER_CONTROL);

    data << uint32(DRAENEI_RUINS_UNCONTROL)         << uint32(m_PointState[DRAENEI_RUINS] != EY_POINT_UNDER_CONTROL);

    data << uint32(MAGE_TOWER_ALLIANCE_CONTROL)     << uint32(m_PointOwnedByTeam[MAGE_TOWER] == ALLIANCE && m_PointState[MAGE_TOWER] == EY_POINT_UNDER_CONTROL);

    data << uint32(MAGE_TOWER_HORDE_CONTROL)        << uint32(m_PointOwnedByTeam[MAGE_TOWER] == HORDE && m_PointState[MAGE_TOWER] == EY_POINT_UNDER_CONTROL);

    data << uint32(MAGE_TOWER_UNCONTROL)            << uint32(m_PointState[MAGE_TOWER] != EY_POINT_UNDER_CONTROL);

    data << uint32(FEL_REAVER_HORDE_CONTROL)        << uint32(m_PointOwnedByTeam[FEL_REAVER] == HORDE && m_PointState[FEL_REAVER] == EY_POINT_UNDER_CONTROL);

    data << uint32(FEL_REAVER_ALLIANCE_CONTROL)     << uint32(m_PointOwnedByTeam[FEL_REAVER] == ALLIANCE && m_PointState[FEL_REAVER] == EY_POINT_UNDER_CONTROL);

    data << uint32(FEL_REAVER_UNCONTROL)            << uint32(m_PointState[FEL_REAVER] != EY_POINT_UNDER_CONTROL);

    data << uint32(BLOOD_ELF_HORDE_CONTROL)         << uint32(m_PointOwnedByTeam[BLOOD_ELF] == HORDE && m_PointState[BLOOD_ELF] == EY_POINT_UNDER_CONTROL);

    data << uint32(BLOOD_ELF_ALLIANCE_CONTROL)      << uint32(m_PointOwnedByTeam[BLOOD_ELF] == ALLIANCE && m_PointState[BLOOD_ELF] == EY_POINT_UNDER_CONTROL);

    data << uint32(BLOOD_ELF_UNCONTROL)             << uint32(m_PointState[BLOOD_ELF] != EY_POINT_UNDER_CONTROL);

    data << uint32(NETHERSTORM_FLAG)                << uint32(m_FlagState == BG_EY_FLAG_STATE_ON_BASE);

    data << uint32(0xad2) << uint32(0x1);
    data << uint32(0xad1) << uint32(0x1);
    data << uint32(0xabe) << uint32(GetTeamScore(TEAM_HORDE));
    data << uint32(0xabd) << uint32(GetTeamScore(TEAM_ALLIANCE));
    data << uint32(0xa05) << uint32(0x8e);
    data << uint32(0xaa0) << uint32(0x0);
    data << uint32(0xa9f) << uint32(0x0);
    data << uint32(0xa9e) << uint32(0x0);
    data << uint32(0xc0d) << uint32(0x17b);
}

WorldSafeLocsEntry const* BattlegroundEY::GetClosestGraveYard(Player* player)
{
    uint32 g_id = 0;

    switch (player->GetTeam())
    {
        case ALLIANCE: g_id = EY_GRAVEYARD_MAIN_ALLIANCE; break;
        case HORDE:    g_id = EY_GRAVEYARD_MAIN_HORDE;    break;
        default:       return nullptr;
    }

    float distance, nearestDistance;

    WorldSafeLocsEntry const* entry = nullptr;
    WorldSafeLocsEntry const* nearestEntry = nullptr;
    entry = sWorldSafeLocsStore.LookupEntry(g_id);
    nearestEntry = entry;

    if (!entry)
    {
        TC_LOG_ERROR("bg.battleground", "BattlegroundEY: The main team graveyard could not be found. The graveyard system will not be operational!");
        return nullptr;
    }

    float plr_x = player->GetPositionX();
    float plr_y = player->GetPositionY();
    float plr_z = player->GetPositionZ();

    distance = (entry->x - plr_x)*(entry->x - plr_x) + (entry->y - plr_y)*(entry->y - plr_y) + (entry->z - plr_z)*(entry->z - plr_z);
    nearestDistance = distance;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        if (m_PointOwnedByTeam[i] == player->GetTeam() && m_PointState[i] == EY_POINT_UNDER_CONTROL)
        {
            entry = sWorldSafeLocsStore.LookupEntry(m_CapturingPointTypes[i].GraveYardId);
            if (!entry)
                TC_LOG_ERROR("bg.battleground", "BattlegroundEY: Graveyard %u could not be found.", m_CapturingPointTypes[i].GraveYardId);
            else
            {
                distance = (entry->x - plr_x)*(entry->x - plr_x) + (entry->y - plr_y)*(entry->y - plr_y) + (entry->z - plr_z)*(entry->z - plr_z);
                if (distance < nearestDistance)
                {
                    nearestDistance = distance;
                    nearestEntry = entry;
                }
            }
        }
    }

    return nearestEntry;
}

bool BattlegroundEY::IsAllNodesControlledByTeam(uint32 team) const
{
    uint32 count = 0;
    for (uint32 i = 0; i < EY_POINTS_MAX; ++i)
        if (m_PointOwnedByTeam[i] == team && m_PointState[i] == EY_POINT_UNDER_CONTROL)
            ++count;

    return count == EY_POINTS_MAX;
}

uint32 BattlegroundEY::GetPrematureWinner()
{
    if (GetTeamScore(TEAM_ALLIANCE) > GetTeamScore(TEAM_HORDE))
        return ALLIANCE;
    else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))
        return HORDE;

    return Battleground::GetPrematureWinner();
}
