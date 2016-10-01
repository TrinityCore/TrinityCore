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

#include "BattlegroundAV.h"

#include "ObjectMgr.h"
#include "WorldPacket.h"

#include "GameObject.h"
#include "Language.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "WorldSession.h"

BattlegroundGOSpawnPoint const BG_AV_GameObjects[BG_AV_OBJECT_MAX] =
{
    { BG_AV_OBJECTID_GATE,                             {  794.6431f, -493.4745f,  99.77789f,  6.16101300f }, { 0.f, 0.f, -0.06104851f, 0.998134800f }, RESPAWN_IMMEDIATELY },
    { BG_AV_OBJECTID_GATE,                             { -1382.057f, -545.9169f,  54.90467f,  0.76794390f }, { 0.f, 0.f,  0.37460610f, 0.927184000f }, RESPAWN_IMMEDIATELY },
    { BG_AV_GHOST_GATE,                                {  794.6349f, -493.6433f,  98.60200f,  3.03683800f }, { 0.f, 0.f,  0.99862860f, 0.052353220f }, RESPAWN_IMMEDIATELY },
    { BG_AV_GHOST_GATE,                                { -1382.432f, -545.4144f,  54.83085f,  3.90954100f }, { 0.f, 0.f, -0.92718320f, 0.374608300f }, RESPAWN_IMMEDIATELY },

    { BG_AV_OBJECTID_BANNER_A_AID_STATION,             {  638.5921f, -32.42204f,  46.06084f, -1.62315600f }, { 0.f, 0.f, -0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_BANNER_A_STORMPIKE,               {  669.0073f, -294.0783f,  30.29091f,  2.77506900f }, { 0.f, 0.f,  0.98325440f, 0.182238000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_BANNER_A_STONEHEARTH_GRAVE,       {  77.50445f, -404.5873f,  46.78254f,  2.28637900f }, { 0.f, 0.f,  0.90996070f, 0.414694400f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_BANNER_A_SNOWFALL_GRAVE,          { -202.2778f, -113.2084f,  78.47941f,  5.02654900f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_BANNER_A_ICEBLOOD_GRAVE,          { -612.9139f, -396.8383f,  60.85839f,  3.10665200f }, { 0.f, 0.f,  0.99984740f, 0.017469280f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_BANNER_A_FROSTWOLF_GRAVE,         { -1082.428f, -346.7917f,  54.92648f, -1.51843600f }, { 0.f, 0.f, -0.68835450f, 0.725374500f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_BANNER_A_FROSTWOLF_HUT,           { -1402.210f, -307.4312f,  89.44242f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut
    { BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_S,            {  553.7794f, -78.65658f,  51.93779f, -1.22172900f }, { 0.f, 0.f, -0.57357600f, 0.819152400f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_N,            {  674.0006f, -143.1251f,  63.66151f,  0.99483720f }, { 0.f, 0.f,  0.47715850f, 0.878817300f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_BANNER_A_ICEWING_BUNKER,          {  203.2385f, -360.2642f,  56.38615f, -0.87266390f }, { 0.f, 0.f, -0.42261790f, 0.906307900f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_BANNER_A_STONEHEARTH_BUNKER,      { -152.4339f, -441.6148f,  40.39709f, -1.93731600f }, { 0.f, 0.f, -0.82412620f, 0.566406100f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_BANNER_CONT_A_AID_STATION,        {  638.4788f, -31.21739f,  46.24166f,  1.62315600f }, { 0.f, 0.f,  0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_BANNER_CONT_A_STORMPIKE,          {  669.0321f, -294.0603f,  30.29091f,  2.77506900f }, { 0.f, 0.f,  0.98325440f, 0.182238000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_BANNER_CONT_A_STONEHEARTH_GRAVE,  {  78.38553f, -405.4505f,  46.60544f, -0.85521050f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_BANNER_CONT_A_SNOWFALL,           { -202.5808f, -112.7303f,  78.48758f, -0.71558490f }, { 0.f, 0.f, -0.35020730f, 0.936672200f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GRAVE,     { -611.5228f, -396.8190f,  60.85839f,  6.24827900f }, { 0.f, 0.f, -0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_GRAVE,    { -1082.448f, -346.8234f,  54.92188f, -1.53589000f }, { 0.f, 0.f, -0.69465830f, 0.719339800f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_HUT,      { -1402.278f, -307.3798f,  89.44196f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut
    { BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GARRISON,  { -571.8568f, -262.7909f,  75.00867f, -0.78539680f }, { 0.f, 0.f, -0.38268280f, 0.923879800f }, RESPAWN_ONE_DAY     }, // iceblood garrison
    { BG_AV_OBJECTID_BANNER_CONT_A_TOWER_POINT,        { -768.0753f, -362.6295f,  90.89486f,  1.15191600f }, { 0.f, 0.f,  0.54463860f, 0.838670800f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_E,        { -1302.900f, -316.9811f,  113.8671f,  2.00712800f }, { 0.f, 0.f,  0.84339140f, 0.537299600f }, RESPAWN_ONE_DAY     }, // frostwolf etower
    { BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_W,        { -1297.695f, -266.7301f,  114.1512f, -2.93213900f }, { 0.f, 0.f, -0.99452110f, 0.104535500f }, RESPAWN_ONE_DAY     }, // frostwolf wtower

    { BG_AV_OBJECTID_BANNER_CONT_H_AID_STATION,        {  638.6570f, -32.22944f,  46.09035f,  4.66003000f }, { 0.f, 0.f, -0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_BANNER_CONT_H_STORMPIKE,          {  669.2953f, -294.0375f,  30.28969f,  5.91666800f }, { 0.f, 0.f, -0.18223480f, 0.983255000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_GRAVE,  {  77.80132f, -404.6999f,  46.75493f, -0.87266390f }, { 0.f, 0.f, -0.42261790f, 0.906307900f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_BANNER_CONT_H_SNOWFALL,           { -202.6516f, -112.8073f,  78.48706f, -1.09955600f }, { 0.f, 0.f, -0.52249810f, 0.852640500f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_BANNER_CONT_H_ICEBLOOD_GRAVE,     { -612.6615f, -396.6992f,  60.85839f,  6.24827900f }, { 0.f, 0.f, -0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_GRAVE,    { -1082.536f, -346.5672f,  54.97722f,  4.72984400f }, { 0.f, 0.f, -0.70090870f, 0.713251100f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_HUT,      { -1402.176f, -307.3057f,  89.44698f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut
    { BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_S,       {  553.8216f, -78.76752f,  51.93868f,  5.21853600f }, { 0.f, 0.f, -0.50753780f, 0.861629400f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_N,       {  674.0469f, -143.1559f,  63.66140f,  0.99483720f }, { 0.f, 0.f,  0.47715850f, 0.878817300f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_BANNER_CONT_H_ICEWING_BUNKER,     {  203.2809f, -360.3663f,  56.38691f,  5.35816200f }, { 0.f, 0.f, -0.44619750f, 0.894934500f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_BUNKER, { -152.4373f, -441.7582f,  40.39823f, -1.95476600f }, { 0.f, 0.f, -0.82903670f, 0.559194100f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_BANNER_H_AID_STATION,             {  638.6057f, -32.15061f,  46.09934f,  4.67748400f }, { 0.f, 0.f, -0.71933940f, 0.694658800f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_BANNER_H_STORMPIKE,               {  669.3167f, -294.0553f,  30.28967f, -0.36651760f }, { 0.f, 0.f, -0.18223480f, 0.983255000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_BANNER_H_STONEHEARTH_GRAVE,       {  77.79785f, -404.6955f,  46.91283f,  5.42797500f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_BANNER_H_SNOWFALL,                { -202.6227f, -112.5515f,  78.49015f, -1.25663600f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GRAVE,          { -612.6716f, -396.6933f,  60.85839f,  3.08918300f }, { 0.f, 0.f,  0.99965670f, 0.026201650f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_BANNER_H_FROSTWOLF_GRAVE,         { -1082.529f, -346.5670f,  54.97712f,  4.72984400f }, { 0.f, 0.f, -0.70090870f, 0.713251100f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_BANNER_H_FROSTWOLF_HUT,           { -1402.192f, -307.4671f,  89.44189f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut
    { BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GARRISON,       { -571.8796f, -262.7768f,  75.00867f, -0.80285090f }, { 0.f, 0.f, -0.39073090f, 0.920505000f }, RESPAWN_ONE_DAY     }, // iceblood garrison
    { BG_AV_OBJECTID_BANNER_H_TOWER_POINT,             { -768.0873f, -362.6661f,  90.89486f,  1.11700900f }, { 0.f, 0.f,  0.52991870f, 0.848048400f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_BANNER_H_FROSTWOLF_E,             { -1302.868f, -316.9684f,  113.8671f,  2.00712800f }, { 0.f, 0.f,  0.84339140f, 0.537299600f }, RESPAWN_ONE_DAY     }, // frostwolf etower
    { BG_AV_OBJECTID_BANNER_H_FROSTWOLF_W,             { -1297.715f, -266.7415f,  114.1512f, -2.96704100f }, { 0.f, 0.f, -0.99619390f, 0.087165040f }, RESPAWN_ONE_DAY     }, // frostwolf wtower

    { BG_AV_OBJECTID_BANNER_SNOWFALL_N,                { -202.6107f, -112.7780f,  78.48716f,  5.13126900f }, { 0.f, 0.f, -0.54463860f, 0.838670800f }, RESPAWN_ONE_DAY     }, // snowfall (duh)

    { BG_AV_OBJECTID_AURA_N_S,                         {  638.4788f, -31.21739f,  46.24166f,  1.62315600f }, { 0.f, 0.f,  0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         {  638.6570f, -32.22944f,  46.09035f,  4.66003000f }, { 0.f, 0.f, -0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         {  669.0321f, -294.0603f,  30.29091f,  2.77506900f }, { 0.f, 0.f,  0.98325440f, 0.182238000f }, RESPAWN_ONE_DAY     }, // stormpike (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         {  669.2953f, -294.0375f,  30.28969f,  5.91666800f }, { 0.f, 0.f, -0.18223480f, 0.983255000f }, RESPAWN_ONE_DAY     }, // stormpike (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         {  78.38553f, -405.4505f,  46.60544f, -0.85521050f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     }, // stonehearth grave (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         {  77.80132f, -404.6999f,  46.75493f, -0.87266390f }, { 0.f, 0.f, -0.42261790f, 0.906307900f }, RESPAWN_ONE_DAY     }, // stonehearth grave (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -202.5808f, -112.7303f,  78.48758f, -0.71558490f }, { 0.f, 0.f, -0.35020730f, 0.936672200f }, RESPAWN_ONE_DAY     }, // snowfall (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -202.6516f, -112.8073f,  78.48706f, -1.09955600f }, { 0.f, 0.f, -0.52249810f, 0.852640500f }, RESPAWN_ONE_DAY     }, // snowfall (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -611.5228f, -396.8190f,  60.85839f, -0.03490625f }, { 0.f, 0.f, -0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     }, // iceblood grave (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -612.6615f, -396.6992f,  60.85839f,  6.24827900f }, { 0.f, 0.f, -0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     }, // iceblood grave (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -1082.448f, -346.8234f,  54.92188f, -1.53589000f }, { 0.f, 0.f, -0.69465830f, 0.719339800f }, RESPAWN_ONE_DAY     }, // frostwolf grave (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -1082.536f, -346.5672f,  54.97722f, -1.55334100f }, { 0.f, 0.f, -0.70090870f, 0.713251100f }, RESPAWN_ONE_DAY     }, // frostwolf grave (Horde contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -1402.278f, -307.3798f,  89.44196f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut (Alliance contested)
    { BG_AV_OBJECTID_AURA_N_S,                         { -1402.176f, -307.3057f,  89.44698f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut (Horde contested)

    { BG_AV_OBJECTID_AURA_N_S,                         { -202.3944f, -113.0329f,  78.48245f,  5.02654900f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall (Initial)

    { BG_AV_OBJECTID_AURA_A_S,                         {  638.5921f, -32.42204f,  46.06084f, -1.62315600f }, { 0.f, 0.f, -0.72537420f, 0.688354700f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_AURA_A_S,                         {  669.0073f, -294.0783f,  30.29091f,  2.77506900f }, { 0.f, 0.f,  0.98325440f, 0.182238000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_AURA_A_S,                         {  77.50445f, -404.5873f,  46.78254f,  2.28637900f }, { 0.f, 0.f,  0.90996070f, 0.414694400f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_AURA_A_S,                         { -202.2778f, -113.2084f,  78.47941f,  5.02654900f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_AURA_A_S,                         { -612.9139f, -396.8383f,  60.85839f,  3.10665200f }, { 0.f, 0.f,  0.99984740f, 0.017469280f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_AURA_A_S,                         { -1082.428f, -346.7917f,  54.92648f, -1.51843600f }, { 0.f, 0.f, -0.68835450f, 0.725374500f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_AURA_A_S,                         { -1402.210f, -307.4312f,  89.44242f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut

    { BG_AV_OBJECTID_AURA_H_S,                         {  638.6057f, -32.15061f,  46.09934f,  4.67748400f }, { 0.f, 0.f, -0.71933940f, 0.694658800f }, RESPAWN_ONE_DAY     }, // aid station
    { BG_AV_OBJECTID_AURA_H_S,                         {  669.3167f, -294.0553f,  30.28967f,  5.91666800f }, { 0.f, 0.f, -0.18223480f, 0.983255000f }, RESPAWN_ONE_DAY     }, // stormpike
    { BG_AV_OBJECTID_AURA_H_S,                         {  77.79785f, -404.6955f,  46.91283f,  5.42797500f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     }, // stonehearth grave
    { BG_AV_OBJECTID_AURA_H_S,                         { -202.6227f, -112.5515f,  78.49015f, -1.25663600f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_AURA_H_S,                         { -612.6716f, -396.6933f,  60.85839f,  3.08918300f }, { 0.f, 0.f,  0.99965670f, 0.026201650f }, RESPAWN_ONE_DAY     }, // iceblood grave
    { BG_AV_OBJECTID_AURA_H_S,                         { -1082.529f, -346.5670f,  54.97712f,  4.72984400f }, { 0.f, 0.f, -0.70090870f, 0.713251100f }, RESPAWN_ONE_DAY     }, // frostwolf grave
    { BG_AV_OBJECTID_AURA_H_S,                         { -1402.192f, -307.4671f,  89.44189f,  0.19198520f }, { 0.f, 0.f,  0.09584522f, 0.995396300f }, RESPAWN_ONE_DAY     }, // frostwolf hut

    { BG_AV_OBJECTID_TOWER_BANNER_A,                   {  557.2267f, -86.85205f,  62.17670f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_TOWER_BANNER_A_B,                 {  679.3392f, -136.4678f,  73.96262f, -2.16420600f }, { 0.f, 0.f, -0.88294700f, 0.469472700f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_TOWER_BANNER_A_C,                 {  208.9728f, -365.9713f,  66.74092f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_TOWER_BANNER_A_D,                 { -156.4697f, -449.9531f,  50.66824f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_TOWER_BANNER_H_D,                 { -572.3289f, -262.4763f,  88.64957f, -0.57595730f }, { 0.f, 0.f, -0.28401470f, 0.958819900f }, RESPAWN_ONE_DAY     }, // iceblood tower
    { BG_AV_OBJECTID_TOWER_BANNER_H_C,                 { -768.1990f, -363.1053f,  104.5372f,  0.10471930f }, { 0.f, 0.f,  0.05233574f, 0.998629600f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_TOWER_BANNER_H_B,                 { -1302.735f, -316.6303f,  127.5032f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // frostwolf etower
    { BG_AV_OBJECTID_TOWER_BANNER_H,                   { -1297.786f, -266.7428f,  127.7904f,  0.06981169f }, { 0.f, 0.f,  0.03489876f, 0.999390800f }, RESPAWN_ONE_DAY     }, // frostwolf wtower

    { BG_AV_OBJECTID_TOWER_BANNER_PH,                  {  555.8476f, -84.41515f,  64.43967f,  3.12412300f }, { 0.f, 0.f,  0.99996190f, 0.008734641f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_TOWER_BANNER_PH_B,                {  677.5917f, -139.0343f,  76.21964f, -1.98967200f }, { 0.f, 0.f, -0.83866980f, 0.544640200f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_TOWER_BANNER_PH_C,                {  202.5412f, -361.8576f,  67.73707f,  0.61086350f }, { 0.f, 0.f,  0.30070500f, 0.953717200f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_TOWER_BANNER_PH_D,                { -155.8325f, -449.4009f,  52.73059f,  0.61086350f }, { 0.f, 0.f,  0.30070500f, 0.953717200f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_TOWER_BANNER_PA_D,                { -572.2054f, -262.4762f,  88.66471f, -0.59341200f }, { 0.f, 0.f, -0.29237170f, 0.956304700f }, RESPAWN_ONE_DAY     }, // iceblood tower
    { BG_AV_OBJECTID_TOWER_BANNER_PA_C,                { -768.1541f, -363.1023f,  104.5346f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_TOWER_BANNER_PA,                  { -1297.869f, -266.7623f,  127.7958f,  0.06981169f }, { 0.f, 0.f,  0.03489876f, 0.999390800f }, RESPAWN_ONE_DAY     }, // frostwolf wtower
    { BG_AV_OBJECTID_TOWER_BANNER_PA_B,                { -1302.835f, -316.5819f,  127.5164f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // frostwolf etower

    { BG_AV_OBJECTID_AURA_A,                           {  557.2267f, -86.85205f,  62.17670f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_AURA_A,                           {  679.3392f, -136.4678f,  73.96262f, -2.16420600f }, { 0.f, 0.f, -0.88294700f, 0.469472700f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_AURA_A,                           {  208.9728f, -365.9713f,  66.74092f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_AURA_A,                           { -156.4697f, -449.9531f,  50.66824f, -0.24434560f }, { 0.f, 0.f, -0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_AURA_H,                           { -572.3289f, -262.4763f,  88.64957f, -0.57595730f }, { 0.f, 0.f, -0.28401470f, 0.958819900f }, RESPAWN_ONE_DAY     }, // iceblood tower
    { BG_AV_OBJECTID_AURA_H,                           { -768.1990f, -363.1053f,  104.5372f,  0.10471930f }, { 0.f, 0.f,  0.05233574f, 0.998629600f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_AURA_H,                           { -1302.735f, -316.6303f,  127.5032f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // frostwolf etower
    { BG_AV_OBJECTID_AURA_H,                           { -1297.786f, -266.7428f,  127.7904f,  0.06981169f }, { 0.f, 0.f,  0.03489876f, 0.999390800f }, RESPAWN_ONE_DAY     }, // frostwolf wtower

    { BG_AV_OBJECTID_AURA_N,                           {  555.8476f, -84.41515f,  64.43967f,  3.12412300f }, { 0.f, 0.f,  0.99996190f, 0.008734641f }, RESPAWN_ONE_DAY     }, // dun baldar south
    { BG_AV_OBJECTID_AURA_N,                           {  677.5917f, -139.0343f,  76.21964f, -1.98967200f }, { 0.f, 0.f, -0.83866980f, 0.544640200f }, RESPAWN_ONE_DAY     }, // dun baldar north
    { BG_AV_OBJECTID_AURA_N,                           {  202.5412f, -361.8576f,  67.73707f,  0.61086350f }, { 0.f, 0.f,  0.30070500f, 0.953717200f }, RESPAWN_ONE_DAY     }, // icewing bunker
    { BG_AV_OBJECTID_AURA_N,                           { -155.8325f, -449.4009f,  52.73059f,  0.61086350f }, { 0.f, 0.f,  0.30070500f, 0.953717200f }, RESPAWN_ONE_DAY     }, // stonehearth bunker

    { BG_AV_OBJECTID_AURA_N,                           { -572.2054f, -262.4762f,  88.66471f, -0.59341200f }, { 0.f, 0.f, -0.29237170f, 0.956304700f }, RESPAWN_ONE_DAY     }, // iceblood tower
    { BG_AV_OBJECTID_AURA_N,                           { -768.1541f, -363.1023f,  104.5346f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // tower point
    { BG_AV_OBJECTID_AURA_N,                           { -1302.835f, -316.5819f,  127.5164f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     }, // frostwolf etower
    { BG_AV_OBJECTID_AURA_N,                           { -1297.869f, -266.7623f,  127.7958f,  0.06981169f }, { 0.f, 0.f,  0.03489876f, 0.999390800f }, RESPAWN_ONE_DAY     }, // frostwolf wtower

    //duns
    { BG_AV_OBJECTID_FIRE,                             {  562.6321f, -88.18148f,  61.99303f,  0.38397100f }, { 0.f, 0.f,  0.19080830f, 0.981627300f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  562.5229f, -74.50277f,  37.94744f,  6.23082600f }, { 0.f, 0.f, -0.02617645f, 0.999657300f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  558.0970f, -70.98416f,  52.48756f,  0.82030330f }, { 0.f, 0.f,  0.39874840f, 0.917060400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  578.1671f, -71.81907f,  38.15139f,  2.72271300f }, { 0.f, 0.f,  0.97814750f, 0.207912100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  556.0278f, -94.92421f,  44.81911f,  3.05432700f }, { 0.f, 0.f,  0.99904820f, 0.043619260f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  572.4509f, -94.36546f,  37.94425f,  4.55531100f }, { 0.f, 0.f, -0.76040550f, 0.649448500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  549.2629f, -79.36453f,  44.81911f,  0.43633160f }, { 0.f, 0.f,  0.21643920f, 0.976296100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  543.5127f, -94.40055f,  52.48191f,  0.03490625f }, { 0.f, 0.f,  0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  572.1493f, -93.78619f,  52.57261f,  0.54105060f }, { 0.f, 0.f,  0.26723770f, 0.963630700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  582.1619f, -81.23753f,  37.92165f,  0.08726600f }, { 0.f, 0.f,  0.04361916f, 0.999048200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  584.4066f, -40.02517f,  38.67543f,  3.21141900f }, { 0.f, 0.f, -0.99939060f, 0.034906130f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  601.4236f, -8.087348f,  41.99544f,  5.95157500f }, { 0.f, 0.f, -0.16504670f, 0.986285700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  619.4541f, -31.87424f,  45.79620f,  0.75049080f }, { 0.f, 0.f,  0.36650090f, 0.930417700f }, RESPAWN_ONE_DAY     },
    //dunn
    { BG_AV_OBJECTID_FIRE,                             {  618.9584f, -91.44927f,  46.20158f, -0.55850390f }, { 0.f, 0.f, -0.27563670f, 0.961261900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  629.0031f, -137.6802f,  39.66906f,  2.12930100f }, { 0.f, 0.f,  0.87461950f, 0.484810100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  637.6774f, -22.12961f,  45.83825f,  5.41052200f }, { 0.f, 0.f, -0.42261790f, 0.906307900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  649.8859f, -60.90945f,  41.65714f,  5.82940100f }, { 0.f, 0.f, -0.22495080f, 0.974370100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  664.7972f, -143.6502f,  64.17843f,  5.82940100f }, { 0.f, 0.f, -0.22495080f, 0.974370100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  664.5048f, -139.4516f,  49.66956f,  6.24827900f }, { 0.f, 0.f, -0.01745224f, 0.999847700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  676.0670f, -124.3193f,  49.67263f,  5.27089600f }, { 0.f, 0.f, -0.48480890f, 0.874620100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  693.0043f, -144.0251f,  64.17549f,  2.44346000f }, { 0.f, 0.f,  0.93969250f, 0.342020500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  661.1747f, -117.6908f,  49.64495f,  1.91986200f }, { 0.f, 0.f,  0.81915190f, 0.573576700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  684.4229f, -146.5821f,  63.66625f,  0.99483720f }, { 0.f, 0.f,  0.47715850f, 0.878817300f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  682.7908f, -127.7686f,  62.41549f,  1.09955600f }, { 0.f, 0.f,  0.52249810f, 0.852640500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  674.5763f, -147.1012f,  56.54253f,  4.67748400f }, { 0.f, 0.f, -0.71933940f, 0.694658800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  655.7191f, -126.6733f,  49.81384f,  2.80997500f }, { 0.f, 0.f,  0.98628520f, 0.165049900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  680.2628f, -118.5916f,  64.33633f,  2.54817900f }, { 0.f, 0.f,  0.95630460f, 0.292372300f }, RESPAWN_ONE_DAY     },
    //icew
    { BG_AV_OBJECTID_FIRE,                             {  231.5031f, -356.6881f,  42.37038f,  0.29670520f }, { 0.f, 0.f,  0.14780900f, 0.989015900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  224.9886f, -348.1752f,  42.56070f,  1.50098300f }, { 0.f, 0.f,  0.68199830f, 0.731353800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  205.7818f, -351.3352f,  56.89980f,  1.01228900f }, { 0.f, 0.f,  0.48480890f, 0.874620100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  196.6049f, -369.1871f,  56.39142f,  2.46091300f }, { 0.f, 0.f,  0.94264130f, 0.333807600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  210.6188f, -376.9375f,  49.26771f,  2.86233500f }, { 0.f, 0.f,  0.99026780f, 0.139175400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  209.6469f, -352.6320f,  42.39587f, -0.69813150f }, { 0.f, 0.f, -0.34202000f, 0.939692700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  220.6500f, -368.1324f,  42.39781f, -0.26179820f }, { 0.f, 0.f, -0.13052560f, 0.991444900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  224.6821f, -374.0315f,  57.06791f,  0.54105060f }, { 0.f, 0.f,  0.26723770f, 0.963630700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  200.2596f, -359.9676f,  49.26771f,  3.38594000f }, { 0.f, 0.f, -0.99254610f, 0.121870000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             {  196.6188f, -378.0163f,  56.91305f,  1.01228900f }, { 0.f, 0.f,  0.48480890f, 0.874620100f }, RESPAWN_ONE_DAY     },
    //stone
    { BG_AV_OBJECTID_FIRE,                             { -155.4875f, -437.3559f,  33.27962f,  2.60053500f }, { 0.f, 0.f,  0.96362970f, 0.267241000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -163.4411f, -454.1876f,  33.27962f,  1.93731200f }, { 0.f, 0.f,  0.82412530f, 0.566407600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -143.9772f, -445.1482f,  26.40972f, -1.86750200f }, { 0.f, 0.f, -0.80385680f, 0.594822800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -135.7640f, -464.7083f,  26.38227f,  2.25147300f }, { 0.f, 0.f,  0.90258500f, 0.430511700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -154.0755f, -466.9290f,  41.06355f, -1.86750200f }, { 0.f, 0.f, -0.80385680f, 0.594822800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -149.9082f, -460.3317f,  26.40835f, -2.09439300f }, { 0.f, 0.f, -0.86602500f, 0.500000800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -151.6378f, -439.5213f,  40.37969f,  0.43633160f }, { 0.f, 0.f,  0.21643920f, 0.976296100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -131.3010f, -454.9045f,  26.57706f,  2.93213900f }, { 0.f, 0.f,  0.99452110f, 0.104535500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -171.2910f, -444.6835f,  40.92113f,  2.30383100f }, { 0.f, 0.f,  0.91354470f, 0.406738400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -143.5915f, -439.7497f,  40.92749f, -1.72787500f }, { 0.f, 0.f, -0.76040550f, 0.649448500f }, RESPAWN_ONE_DAY     },
    //iceblood
    { BG_AV_OBJECTID_FIRE,                             { -572.6668f, -267.9235f,  56.85421f,  2.35619500f }, { 0.f, 0.f,  0.92387960f, 0.382683200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -561.0214f, -262.6891f,  68.45891f,  1.37880900f }, { 0.f, 0.f,  0.63607790f, 0.771624900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -572.5383f, -262.6493f,  88.61970f,  1.83259500f }, { 0.f, 0.f,  0.79335310f, 0.608761700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -574.7702f, -251.4500f,  74.94216f, -1.18682300f }, { 0.f, 0.f, -0.55919270f, 0.829037700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -578.6250f, -267.5710f,  68.46957f,  0.50614460f }, { 0.f, 0.f,  0.25037960f, 0.968147800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -571.4759f, -257.2344f,  63.32225f,  3.10665200f }, { 0.f, 0.f,  0.99984740f, 0.017469280f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -566.0350f, -273.9073f,  52.95818f, -0.89011660f }, { 0.f, 0.f, -0.43051050f, 0.902585600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -580.9479f, -259.7702f,  68.46957f,  1.46607600f }, { 0.f, 0.f,  0.66913030f, 0.743145000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -568.3178f, -267.0998f,  75.00077f,  1.01228900f }, { 0.f, 0.f,  0.48480890f, 0.874620100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -559.6212f, -268.5967f,  52.89864f,  0.05235888f }, { 0.f, 0.f,  0.02617645f, 0.999657300f }, RESPAWN_ONE_DAY     },
    //towerp
    { BG_AV_OBJECTID_FIRE,                             { -776.0723f, -368.0464f,  84.35575f,  2.63544400f }, { 0.f, 0.f,  0.96814730f, 0.250381400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -777.5636f, -368.5211f,  90.67014f,  1.72787500f }, { 0.f, 0.f,  0.76040550f, 0.649448500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -765.4605f, -357.7114f,  90.88798f,  0.31415840f }, { 0.f, 0.f,  0.15643410f, 0.987688400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -768.7630f, -362.7349f,  104.6117f,  1.81514200f }, { 0.f, 0.f,  0.78801060f, 0.615661700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -760.3559f, -358.8957f,  84.35575f,  2.12930100f }, { 0.f, 0.f,  0.87461950f, 0.484810100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -771.9675f, -352.8380f,  84.34844f,  1.74532700f }, { 0.f, 0.f,  0.76604370f, 0.642788600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -773.3331f, -364.6527f,  79.23515f, -1.64061000f }, { 0.f, 0.f, -0.73135380f, 0.681998300f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -764.1089f, -366.0693f,  70.09341f,  0.38397100f }, { 0.f, 0.f,  0.19080830f, 0.981627300f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -767.1028f, -350.7370f,  68.79333f,  2.80997500f }, { 0.f, 0.f,  0.98628520f, 0.165049900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -760.1155f, -353.8446f,  68.86332f,  1.79768900f }, { 0.f, 0.f,  0.78260800f, 0.622514800f }, RESPAWN_ONE_DAY     },
    //roste
    { BG_AV_OBJECTID_FIRE,                             { -1304.866f, -304.5249f,  91.83665f, -0.68067870f }, { 0.f, 0.f, -0.33380700f, 0.942641400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1301.774f, -310.9737f,  95.82520f,  0.90757020f }, { 0.f, 0.f,  0.43837070f, 0.898794200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1305.578f, -320.6247f,  102.1660f, -0.55850390f }, { 0.f, 0.f, -0.27563670f, 0.961261900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1294.266f, -323.4676f,  113.8926f, -1.67551400f }, { 0.f, 0.f, -0.74314400f, 0.669131500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1302.655f, -317.1923f,  127.4872f,  2.30383100f }, { 0.f, 0.f,  0.91354470f, 0.406738400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1293.895f, -313.4777f,  107.3280f,  1.60570200f }, { 0.f, 0.f,  0.71933940f, 0.694658800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1312.407f, -312.9988f,  107.3280f,  1.57079600f }, { 0.f, 0.f,  0.70710660f, 0.707106900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1311.567f, -308.0797f,  91.76656f, -1.85004900f }, { 0.f, 0.f, -0.79863550f, 0.601815000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1314.703f, -322.1310f,  107.3602f,  0.64577170f }, { 0.f, 0.f,  0.31730460f, 0.948323700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1304.598f, -310.7538f,  113.8587f, -0.40142490f }, { 0.f, 0.f, -0.19936750f, 0.979924800f }, RESPAWN_ONE_DAY     },
    //rostw
    { BG_AV_OBJECTID_FIRE,                             { -1308.240f, -273.2603f,  92.05140f, -0.13962450f }, { 0.f, 0.f, -0.06975555f, 0.997564100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1302.255f, -262.8577f,  95.92690f,  0.41887860f }, { 0.f, 0.f,  0.20791150f, 0.978147600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1297.277f, -267.7726f,  126.7559f,  2.23401800f }, { 0.f, 0.f,  0.89879320f, 0.438372800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1299.078f, -256.8899f,  114.1078f, -2.44346000f }, { 0.f, 0.f, -0.93969250f, 0.342020500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1303.405f, -268.2369f,  114.1512f, -1.23918300f }, { 0.f, 0.f, -0.58070280f, 0.814115600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1304.434f, -273.6819f,  107.6121f,  0.24434560f }, { 0.f, 0.f,  0.12186910f, 0.992546200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1309.534f, -265.9505f,  92.14181f, -2.49581800f }, { 0.f, 0.f, -0.94832320f, 0.317305900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1295.553f, -263.8651f,  105.0332f,  0.92502390f }, { 0.f, 0.f,  0.44619750f, 0.894934500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1294.712f, -281.4657f,  107.6638f, -1.50098300f }, { 0.f, 0.f, -0.68199830f, 0.731353800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -1289.693f, -259.5211f,  107.6121f, -2.19911500f }, { 0.f, 0.f, -0.89100650f, 0.453990600f }, RESPAWN_ONE_DAY     },
    //the two buildings of the captains
    //alliance
    { BG_AV_OBJECTID_SMOKE,                            { -64.49870f, -289.3301f,  33.46157f, -2.82743000f }, { 0.f, 0.f, -0.98768810f, 0.156436200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -5.980252f, -326.1439f,  38.85382f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -2.678928f, -306.9978f,  33.41654f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -60.25000f, -309.2321f,  50.24081f, -1.46607600f }, { 0.f, 0.f, -0.66913030f, 0.743145000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -48.79406f, -266.5331f,  47.79163f,  2.44346000f }, { 0.f, 0.f,  0.93969250f, 0.342020500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -3.409288f, -306.2875f,  33.33995f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -48.61903f, -266.9165f,  47.81679f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -62.94738f, -286.2120f,  66.72883f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -5.051324f, -325.3230f,  38.85361f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -64.26768f, -289.4115f,  33.46896f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    //horde
    { BG_AV_OBJECTID_SMOKE,                            { -524.2758f, -199.6001f,  82.87331f, -1.46607600f }, { 0.f, 0.f, -0.66913030f, 0.743145000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -518.1959f, -173.0849f,  102.4304f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -500.7317f, -145.3579f,  88.53374f,  2.44346000f }, { 0.f, 0.f,  0.93969250f, 0.342020500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -501.0836f, -150.7837f,  80.85061f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_SMOKE,                            { -518.3091f, -163.9635f,  102.5210f,  2.96704100f }, { 0.f, 0.f,  0.99619390f, 0.087165040f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -517.0532f, -200.4287f,  80.75904f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -514.3606f, -163.8640f,  104.1627f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -568.0396f, -188.7069f,  81.54996f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -501.7748f, -151.5809f,  81.20268f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_FIRE,                             { -509.9745f, -191.6520f,  83.29779f,  0.00000000f }, { 0.f, 0.f,  0.00000000f, 1.000000000f }, RESPAWN_ONE_DAY     },

    { BG_AV_OBJECTID_SNOWFALL_CANDY_A,                 { -201.2841f, -134.5703f,  78.84847f,  5.46288200f }, { 0.f, 0.f, -0.39874840f, 0.917060400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_A,                 { -216.2120f, -90.70644f,  79.80706f,  1.16936900f }, { 0.f, 0.f,  0.55193610f, 0.833886400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_A,                 { -200.4646f, -96.41797f,  79.75871f,  1.36135600f }, { 0.f, 0.f,  0.62932010f, 0.777146200f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_A,                 { -191.0167f, -129.9633f,  78.86423f,  5.23598800f }, { 0.f, 0.f, -0.50000000f, 0.866025400f }, RESPAWN_ONE_DAY     }, // snowfall

    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -200.7387f, -96.67969f,  79.78001f, -2.00712800f }, { 0.f, 0.f, -0.84339140f, 0.537299600f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -201.2817f, -134.3188f,  78.67534f, -0.94247660f }, { 0.f, 0.f, -0.45399000f, 0.891006800f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -191.1531f, -129.8684f,  78.55949f, -1.25663600f }, { 0.f, 0.f, -0.58778480f, 0.809017400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -215.9809f, -91.41010f,  80.87022f, -1.74532700f }, { 0.f, 0.f, -0.76604370f, 0.642788600f }, RESPAWN_ONE_DAY     }, // snowfall

    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -200.6661f, -96.65804f,  79.77298f,  1.34390100f }, { 0.f, 0.f,  0.62251380f, 0.782608800f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -215.9373f, -91.30605f,  80.23534f,  1.16936900f }, { 0.f, 0.f,  0.55193610f, 0.833886400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -201.4963f, -134.6260f,  78.95821f,  5.48033400f }, { 0.f, 0.f, -0.39073090f, 0.920505000f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PA,                { -191.1726f, -130.1024f,  78.74232f,  5.23598800f }, { 0.f, 0.f, -0.50000000f, 0.866025400f }, RESPAWN_ONE_DAY     }, // snowfall

    { BG_AV_OBJECTID_SNOWFALL_CANDY_H,                 { -215.7410f, -90.99729f,  80.08942f,  1.16936900f }, { 0.f, 0.f,  0.55193610f, 0.833886400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_H,                 { -200.4294f, -96.50825f,  79.75236f,  1.34390100f }, { 0.f, 0.f,  0.62251380f, 0.782608800f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_H,                 { -190.9410f, -129.8694f,  78.93259f, -1.06465000f }, { 0.f, 0.f, -0.50753780f, 0.861629400f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_H,                 { -201.4437f, -134.4444f,  78.93211f, -0.85521050f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     }, // snowfall

    { BG_AV_OBJECTID_SNOWFALL_CANDY_PH,                { -201.1786f, -134.2669f,  78.67773f, -0.99483720f }, { 0.f, 0.f, -0.47715850f, 0.878817300f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PH,                { -191.1758f, -129.9295f,  78.67520f, -1.20427700f }, { 0.f, 0.f, -0.56640630f, 0.824126200f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PH,                { -200.6963f, -96.61768f,  79.70095f, -2.09439300f }, { 0.f, 0.f, -0.86602500f, 0.500000800f }, RESPAWN_ONE_DAY     }, // snowfall
    { BG_AV_OBJECTID_SNOWFALL_CANDY_PH,                { -216.1583f, -91.62186f,  80.86039f, -1.72787500f }, { 0.f, 0.f, -0.76040550f, 0.649448500f }, RESPAWN_ONE_DAY     }, // snowfall

    { BG_AV_OBJECTID_MINE_N,                           {  817.5092f, -457.3312f,  48.46665f,  2.07693900f }, { 0.f, 0.f,  0.86162850f, 0.507539400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  837.1170f, -452.5559f,  47.23311f, -3.12412300f }, { 0.f, 0.f, -0.99996190f, 0.008734641f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  854.4492f, -442.2549f,  50.65888f,  0.40142490f }, { 0.f, 0.f,  0.19936750f, 0.979924800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  857.2037f, -371.4503f,  47.59510f,  1.27408800f }, { 0.f, 0.f,  0.59482190f, 0.803857400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  869.7550f, -448.8668f,  52.54475f, -0.85521050f }, { 0.f, 0.f, -0.41469290f, 0.909961500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  886.6847f, -442.3580f,  54.69622f, -1.22172900f }, { 0.f, 0.f, -0.57357600f, 0.819152400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  900.3499f, -479.0240f,  58.35533f,  0.12217300f }, { 0.f, 0.f,  0.06104851f, 0.998134800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  946.5957f, -390.4882f,  63.11241f,  3.97935500f }, { 0.f, 0.f, -0.91354470f, 0.406738400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  949.8772f, -458.1977f,  56.48738f,  0.31415840f }, { 0.f, 0.f,  0.15643410f, 0.987688400f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_N,                           {  964.2702f, -441.8705f,  56.02847f,  1.79768900f }, { 0.f, 0.f,  0.78260800f, 0.622514800f }, RESPAWN_ONE_DAY     },

    { BG_AV_OBJECTID_MINE_S,                           { -975.8557f, -82.54964f,  80.48984f,  5.55014700f }, { 0.f, 0.f, -0.35836790f, 0.933580500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -975.8557f, -82.54964f,  80.48984f, -0.73303820f }, { 0.f, 0.f, -0.35836790f, 0.933580500f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -951.3943f, -193.6948f,  67.63397f,  0.80285090f }, { 0.f, 0.f,  0.39073090f, 0.920505000f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -947.6424f, -208.8073f,  77.01006f,  1.36135600f }, { 0.f, 0.f,  0.62932010f, 0.777146200f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -934.2118f, -57.35167f,  80.27698f, -0.01745246f }, { 0.f, 0.f, -0.00872612f, 0.999961900f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -925.8670f, -127.2934f,  61.32328f,  5.49778900f }, { 0.f, 0.f, -0.38268280f, 0.923879800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -902.7300f, -103.8680f,  75.43777f,  4.69493700f }, { 0.f, 0.f, -0.71325020f, 0.700909600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -862.8824f, -0.353299f,  72.15256f,  3.76991200f }, { 0.f, 0.f, -0.95105650f, 0.309017100f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -854.9325f, -85.91835f,  68.60560f,  4.24115000f }, { 0.f, 0.f, -0.85264020f, 0.522498600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -854.9325f, -85.91835f,  68.60560f, -2.04203500f }, { 0.f, 0.f, -0.85264020f, 0.522498600f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -851.8329f, -118.9587f,  63.86718f,  6.21337400f }, { 0.f, 0.f, -0.03489876f, 0.999390800f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -849.8320f, -20.84207f,  70.46720f,  4.46804300f }, { 0.f, 0.f, -0.78801060f, 0.615661700f }, RESPAWN_ONE_DAY     },
    { BG_AV_OBJECTID_MINE_S,                           { -831.7468f, -154.6468f,  62.59975f,  1.44862200f }, { 0.f, 0.f,  0.66261960f, 0.748956100f }, RESPAWN_ONE_DAY     }
};

// used for iterating, because not all nodes have 10 GO each
uint32 const BG_AV_FlameIndices[BG_AV_DESTRUCTIBLE_MAX + 1] =
{
    BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH,
    BG_AV_OBJECT_BURN_DUNBALDAR_NORTH,
    BG_AV_OBJECT_BURN_ICEWING_BUNKER,
    BG_AV_OBJECT_BURN_STONEHEART_BUNKER,
    BG_AV_OBJECT_BURN_ICEBLOOD_TOWER,
    BG_AV_OBJECT_BURN_TOWER_POINT,
    BG_AV_OBJECT_BURN_FROSTWOLF_ETOWER,
    BG_AV_OBJECT_BURN_FROSTWOLF_WTOWER,
    BG_AV_OBJECT_BURN_BUILDING_ALLIANCE,
    BG_AV_OBJECT_BURN_BUILDING_HORDE,

    BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH + BG_AV_FIRE_SMOKE_COUNT
};

Position const BG_AV_CreaturePos[AV_CPLACE_MAX] =
{
    //spiritguides
    {643.000000f, 44.000000f, 69.740196f, -0.001854f},
    {676.000000f, -374.000000f, 30.000000f, -0.001854f},
    {73.417755f, -496.433105f, 48.731918f, -0.001854f},
    {-157.409195f, 31.206272f, 77.050598f, -0.001854f},
    {-531.217834f, -405.231384f, 49.551376f, -0.001854f},
    {-1090.476807f, -253.308670f, 57.672371f, -0.001854f},
    {-1496.065063f, -333.338409f, 101.134804f, -0.001854f},
    {873.001770f, -491.283630f, 96.541931f, -0.001854f},
    {-1437.670044f, -610.088989f, 51.161900f, -0.001854f},
 //grave
 //aid
    {635.17f, -29.5594f, 46.5056f, 4.81711f},
    {642.488f, -32.9437f, 46.365f, 4.67748f},
    {642.326f, -27.9442f, 46.9211f, 4.59022f},
    {635.945f, -33.6171f, 45.7164f, 4.97419f},
   //stormpike
    {669.272f, -297.304f, 30.291f, 4.66604f},
    {674.08f, -292.328f, 30.4817f, 0.0918785f},
    {667.01f, -288.532f, 29.8809f, 1.81583f},
    {664.153f, -294.042f, 30.2851f, 3.28531f},
  //stone
    {81.7027f, -406.135f, 47.7843f, 0.598464f},
    {78.1431f, -409.215f, 48.0401f, 5.05953f},
    {73.4135f, -407.035f, 46.7527f, 3.34736f},
    {78.2258f, -401.859f, 46.4202f, 2.05852f},
  //snowfall
    {-207.412f, -110.616f, 78.7959f, 2.43251f},
    {-197.95f, -112.205f, 78.5686f, 6.22441f},
    {-202.709f, -116.829f, 78.4358f, 5.13742f},
    {-202.059f, -108.314f, 78.5783f, 5.91968f},
  //ice
    {-615.501f, -393.802f, 60.4299f, 3.06147f},
    {-608.513f, -392.717f, 62.5724f, 2.06323f},
    {-609.769f, -400.072f, 60.7174f, 5.22367f},
    {-616.093f, -398.293f, 60.5628f, 3.73613f},
  //frost
    {-1077.7f, -340.21f, 55.4682f, 6.25569f},
    {-1082.74f, -333.821f, 54.7962f, 2.05459f},
    {-1090.66f, -341.267f, 54.6768f, 3.27746f},
    {-1081.58f, -344.63f, 55.256f, 4.75636f},
  //frost hut
    {-1408.95f, -311.69f, 89.2536f, 4.49954f},
    {-1407.15f, -305.323f, 89.1993f, 2.86827f},
    {-1400.64f, -304.3f, 89.7008f, 1.0595f},
    {-1400.4f, -311.35f, 89.3028f, 4.99434f},
  //towers
  //dun south - OK
    {569.395f, -101.064f, 52.8296f, 2.34974f},
    {574.85f, -92.9842f, 52.5869f, 3.09325f},
    {575.411f, -83.597f, 52.3626f, 6.26573f},
    {571.352f, -75.6582f, 52.479f, 0.523599f},
    //dun north - OK
    {668.60f, -122.53f, 64.12f, 2.34f}, /// @todo: To be confirm - Not completely okay
    {662.253f, -129.105f, 64.1794f, 2.77507f},
    {661.209f, -138.877f, 64.2251f, 3.38594f},
    {665.481f, -146.857f, 64.1271f, 3.75246f},
    //icewing - OK
    {225.228f, -368.909f, 56.9983f, 6.23806f},
    {191.36f, -369.899f, 57.1524f, 3.24631f},
    {215.518f, -384.019f, 56.9889f, 5.09636f},
    {199.625f, -382.177f, 56.8691f, 4.08407f},
    //stone
    {-172.851f, -452.366f, 40.8725f, 3.31829f},
    {-147.147f, -435.053f, 40.8022f, 0.599238f},
    {-169.456f, -440.325f, 40.985f, 2.59101f},
    {-163.494f, -434.904f, 41.0725f, 1.84174f},
    //ice - OK
    {-573.522f, -271.854f, 75.0078f, 3.9619f},
    {-565.616f, -269.051f, 74.9952f, 5.02655f},
    {-562.825f, -261.087f, 74.9898f, 5.95157f},
    {-569.176f, -254.446f, 74.8771f, 0.820305f},
    //towerpoint
    {-763.04f, -371.032f, 90.7933f, 5.25979f},
    {-759.764f, -358.264f, 90.8681f, 0.289795f},
    {-768.808f, -353.056f, 90.8811f, 1.52601f},
    {-775.944f, -362.639f, 90.8949f, 2.59573f},
    //frost etower
    {-1294.13f, -313.045f, 107.328f, 0.270162f},
    {-1306.5f, -308.105f, 113.767f, 1.78755f},
    {-1294.78f, -319.966f, 113.79f, 5.94545f},
    {-1294.83f, -312.241f, 113.799f, 0.295293f},
    //frost wtower
    {-1300.96f, -275.111f, 114.058f, 4.12804f},
    {-1302.41f, -259.256f, 114.065f, 1.67602f},
    {-1287.97f, -262.087f, 114.165f, 6.18264f},
    {-1291.59f, -271.166f, 114.151f, 5.28257f},

    //alliance marshall
    {721.104f, -7.64155f, 50.7046f, 3.45575f}, // south
    {723.058f, -14.1548f, 50.7046f, 3.40339f}, // north
    {715.691f, -4.72233f, 50.2187f, 3.47321f}, // icewing
    {720.046f, -19.9413f, 50.2187f, 3.36849f}, // stone
/// horde @todo: Confirm positions
    {-1363.99f, -221.99f, 98.4053f, 4.93012f},
    {-1370.96f, -223.532f, 98.4266f, 4.93012f},
    {-1378.37f, -228.614f, 99.3546f, 5.38565f},
    {-1358.02f, -228.998f, 98.868f, 3.87768f},

 //irondeep mine
 //Irondeep Trogg
    {971.671f, -442.657f, 57.6951f, 3.1765f},
    {969.979f, -457.148f, 58.1119f, 4.5204f},
    {958.692f, -333.477f, 63.2276f, 5.77704f},
    {957.113f, -325.92f, 61.7589f, 1.13446f},
    {948.25f, -448.268f, 56.9009f, 5.60251f},
    {934.727f, -385.802f, 63.0344f, 3.75246f},
    {931.751f, -403.458f, 59.6737f, 5.63741f},
    {931.146f, -359.666f, 66.0294f, 3.9619f},
    {929.702f, -412.401f, 56.8776f, 5.89921f},
    {926.849f, -379.074f, 63.5286f, 2.0944f},
    {921.972f, -358.597f, 66.4313f, 2.93215f},
    {921.449f, -341.981f, 67.1264f, 3.4383f},
    {921.1f, -395.812f, 60.4615f, 2.71695f},
    {919.274f, -394.986f, 60.3478f, 2.71696f},
    {916.852f, -393.891f, 60.1726f, 2.71695f},
    {914.568f, -326.21f, 66.1733f, 2.25147f},
    {913.064f, -395.773f, 60.1364f, 4.41568f},
    {909.246f, -474.576f, 58.2067f, 0.226893f},
    {909.246f, -474.576f, 58.2901f, 0.226893f},
    {907.209f, -428.267f, 59.8065f, 1.8675f},
    {905.973f, -459.528f, 58.7594f, 1.37189f},
    {905.067f, -396.074f, 60.2085f, 5.07891f},
    {901.809f, -457.709f, 59.0116f, 3.52557f},
    {900.962f, -427.44f, 59.0842f, 1.50098f},
    {897.929f, -471.742f, 59.7729f, 2.54818f},
    {893.376f, -343.171f, 68.1499f, 5.35816f},
    {890.584f, -406.049f, 61.1925f, 5.67232f},
    {888.208f, -332.564f, 68.148f, 1.93732f},
    {887.647f, -391.537f, 61.8734f, 1.37881f},
    {885.109f, -343.338f, 67.0867f, 3.78979f},
    {881.618f, -419.948f, 53.5228f, 0.593412f},
    {878.675f, -345.36f, 66.1052f, 3.45651f},
    {877.127f, -351.8f, 66.5296f, 5.74213f},
    {876.778f, -345.97f, 65.7724f, 3.45262f},
    {874.577f, -414.786f, 52.7817f, 1.67552f},
    {868.247f, -343.136f, 64.9894f, 1.6057f},
    {859.03f, -367.231f, 47.4655f, 0.0174533f},
    {857.513f, -351.817f, 65.1867f, 4.39823f},
    {852.632f, -372.416f, 48.1657f, 3.66519f},
    {849.86f, -340.944f, 66.2447f, 0.401426f},
    {847.99f, -386.287f, 60.9277f, 2.32374f},
    {847.601f, -423.072f, 50.0852f, 4.57276f},
    {847.135f, -411.307f, 50.2106f, 1.5708f},
    {835.077f, -379.418f, 48.2755f, 5.93412f},
    {834.87f, -453.304f, 47.9075f, 0.226893f},
    {834.634f, -365.981f, 62.8801f, 1.32645f},
    {834.354f, -355.526f, 48.1491f, 6.07375f},
    {833.702f, -327.506f, 65.0439f, 0.331613f},
    {833.151f, -374.228f, 63.0938f, 3.66519f},
    {831.711f, -346.785f, 47.2975f, 0.226893f},
    {827.874f, -413.624f, 48.5818f, 1.49241f},
    {827.728f, -415.483f, 48.5593f, 1.49238f},
    {827.016f, -424.543f, 48.2856f, 1.49236f},
    {823.222f, -334.283f, 65.6306f, 4.88692f},
    {821.892f, -464.723f, 48.9451f, 4.66003f},
    {821.006f, -387.635f, 49.0728f, 3.15905f},
    {817.26f, -447.432f, 49.4308f, 2.18166f},
    {805.399f, -320.146f, 52.7712f, 0.296706f},
    {801.405f, -328.055f, 53.0195f, 4.31096f},
    //irondeep skullthumber irondeep shaman
    {955.812f, -440.302f, 55.3411f, 3.19395f},
    {937.378f, -377.816f, 65.3919f, 3.56047f},
    {925.059f, -331.347f, 65.7564f, 3.66519f},
    {922.918f, -396.634f, 60.3942f, 2.71695f},
    {909.99f, -462.154f, 59.0811f, 3.7001f},
    {907.893f, -388.787f, 61.7923f, 5.74213f},
    {898.801f, -437.105f, 58.5266f, 0.959931f},
    {884.237f, -407.597f, 61.566f, 0.820305f},
    {880.744f, -344.683f, 66.4086f, 3.4644f},
    {876.047f, -341.857f, 65.8743f, 4.45059f},
    {874.674f, -402.077f, 61.7573f, 0.26341f},
    {871.914f, -404.209f, 62.1269f, 6.06163f},
    {871.606f, -403.665f, 62.0795f, 0.765774f},
    {871.561f, -404.114f, 62.1297f, 0.00981727f},
    {871.528f, -404.248f, 62.1455f, 0.498032f},
    {871.493f, -404.122f, 62.1331f, 5.65727f},
    {871.282f, -403.843f, 62.1108f, 0.788382f},
    {868.294f, -392.395f, 61.4772f, 4.38685f},
    {868.256f, -392.363f, 61.4803f, 0.732738f},
    {867.804f, -392.51f, 61.5089f, 2.30167f},
    {867.612f, -392.371f, 61.524f, 2.86149f},
    {858.593f, -439.614f, 50.2184f, 0.872665f},
    {851.471f, -362.52f, 47.314f, 4.06662f},
    {846.939f, -347.279f, 66.2876f, 0.942478f},
    {842.08f, -421.775f, 48.2659f, 1.0821f},
    {838.358f, -371.212f, 63.3299f, 4.04916f},
    {827.57f, -417.483f, 48.4538f, 1.49237f},
    {827.012f, -457.397f, 48.9331f, 2.35619f},
    {825.535f, -322.373f, 63.9357f, 4.76475f},
    {867.635f, -443.605f, 51.3347f, 1.38626f},
    {957.293f, -455.039f, 56.7395f, 5.79449f},
    {950.077f, -326.672f, 61.6552f, 5.48033f},
    {936.692f, -356.78f, 65.9835f, 2.75762f},
    {926.475f, -419.345f, 56.1833f, 2.0944f},
    {924.729f, -397.453f, 60.213f, 2.71695f},
    {902.195f, -475.891f, 58.312f, 1.39626f},
    {897.464f, -338.758f, 68.1715f, 2.94961f},
    {884.237f, -407.597f, 61.566f, 0.820305f},
    {882.517f, -344.111f, 66.7887f, 3.46962f},
    {881.437f, -400.254f, 61.2028f, 0.263427f},
    {880.156f, -400.678f, 61.3113f, 3.41373f},
    {877.989f, -418.051f, 52.9753f, 4.46804f},
    {871.212f, -404.12f, 62.1433f, 3.6554f},
    {871.036f, -404.119f, 62.2237f, 4.50295f},
    {857.396f, -395.766f, 61.263f, 4.78684f},
    {857.276f, -395.395f, 61.2418f, 0.0845553f},
    {857.231f, -394.577f, 61.2174f, 1.96817f},
    {857.108f, -395.682f, 61.2317f, 4.87022f},
    {856.709f, -395.28f, 61.1814f, 2.54913f},
    {850.922f, -390.399f, 60.8771f, 2.85405f},
    {847.556f, -388.228f, 60.9438f, 2.56872f},
    {842.031f, -384.663f, 61.6028f, 2.56871f},
    {832.035f, -389.301f, 47.5567f, 2.11185f},
    {827.415f, -419.468f, 48.3322f, 1.49232f},
    {826.402f, -349.454f, 47.2722f, 1.51844f},
    {817.83f, -455.715f, 48.4207f, 0.925025f},
    {808.953f, -325.964f, 52.4043f, 3.01942f},
    // Morloch
    {865.554f, -438.735f, 50.7333f, 2.12431f},
    //coldtooth mine
    //miner/digger
    {-917.648f, -46.8922f, 77.0872f, 5.27089f},
    {-912.689f, -45.4494f, 76.2277f, 4.60767f},
    {-905.455f, -84.5179f, 75.3642f, 3.29867f},
    {-904.332f, -111.509f, 75.5925f, 2.47837f},
    {-904.27f, -160.419f, 61.9876f, 3.61192f},
    {-904.023f, -90.4558f, 75.3706f, 3.40339f},
    {-978.678f, -37.3136f, 75.8364f, 2.84489f},
    {-973.076f, -36.5013f, 77.5047f, 1.0821f},
    {-963.951f, -87.734f, 81.5555f, 0.575959f},
    {-961.941f, -90.7252f, 81.6629f, 0.820305f},
    {-957.623f, -186.582f, 66.6021f, 1.95477f},
    {-952.476f, -179.778f, 78.6771f, 4.5204f},
    {-950.427f, -115.007f, 79.6127f, 3.68264f},
    {-950.25f, -151.95f, 79.4598f, -1.81423f},
    {-950.169f, -188.099f, 66.6184f, 5.55015f},
    {-949.944f, -142.977f, 80.5382f, 2.70526f},
    {-947.854f, -170.5f, 79.7618f, 0.942478f},
    {-946.738f, -139.567f, 80.0904f, 2.3911f},
    {-945.503f, -65.0654f, 79.7907f, 5.02655f},
    {-943.678f, -110.986f, 80.2557f, 0.959931f},
    {-942.993f, -56.9881f, 79.8915f, 5.65487f},
    {-938.197f, -155.838f, 61.3111f, 1.65806f},
    {-930.488f, -214.524f, 72.1431f, 2.1236f},
    {-929.947f, -154.449f, 61.5084f, 1.67552f},
    {-927.412f, -135.313f, 61.1987f, 3.29867f},
    {-920.677f, -156.859f, 62.8033f, 3.15306f},
    {-916.75f, -136.094f, 62.2357f, 0.0698132f},
    {-915.319f, -132.718f, 62.562f, 1.16984f},
    {-913.589f, -146.794f, 76.9366f, 1.8675f},
    {-907.572f, -148.937f, 76.6898f, 4.76475f},
    {-902.02f, -64.6174f, 73.9707f, 1.19169f},
    {-899.489f, -61.7252f, 73.2498f, 5.09636f},
    {-894.792f, -127.141f, 75.3834f, 6.14356f},
    {-892.408f, -162.525f, 64.1212f, 2.69884f},
    {-892.326f, -123.158f, 76.0318f, 5.5676f},
    {-888.468f, -148.462f, 61.8012f, 1.65806f},
    {-883.268f, -159.738f, 63.5311f, 5.20108f},
    {-877.76f, -118.07f, 65.215f, 2.94961f},
    {-876.792f, -128.646f, 64.1045f, 3.40339f},
    {-874.901f, -36.6579f, 69.4246f, 2.00713f},
    {-874.856f, -151.351f, 62.7537f, 3.57875f},
    {-872.135f, -150.08f, 62.7513f, 3.57201f},
    {-870.288f, -149.217f, 62.5413f, 3.56624f},
    {-870.03f, -6.27443f, 70.3867f, 2.3911f},
    {-869.023f, -82.2118f, 69.5848f, 3.22886f},
    {-866.354f, -40.2455f, 70.842f, 0.0698132f},
    {-865.305f, -152.302f, 63.5044f, 4.86947f},
    {-861.926f, -79.0519f, 71.4178f, 0.20944f},
    {-857.292f, -152.277f, 63.2114f, 4.18879f},
    {-853.357f, -0.696194f, 72.0655f, 0.994838f},
    {-850.685f, -14.2596f, 70.2298f, 0.20944f},
    {-839.987f, -67.7695f, 72.7916f, 4.93928f},
    {-839.199f, -57.0558f, 73.4891f, 1.67552f},
    {-836.963f, -153.224f, 63.3821f, 4.46804f},
    {-832.721f, -67.7555f, 72.9062f, 4.99164f},
    {-821.496f, -143.095f, 63.1292f, 0.541052f},
    {-818.829f, -153.004f, 62.1757f, 6.12611f},
    //special
    {-954.622f, -110.958f, 80.7911f, 6.24828f},
    {-951.477f, -53.9647f, 80.0235f, 5.32325f},
    {-946.812f, -126.04f, 78.8601f, 5.15265f},
    {-940.689f, -140.707f, 79.9225f, 2.79253f},
    {-933.954f, -159.632f, 60.778f, 2.56563f},
    {-922.537f, -130.291f, 61.3756f, 4.95674f},
    {-915.862f, -151.74f, 76.9427f, 0.942478f},
    {-888.321f, -159.831f, 62.5303f, 1.20428f},
    {-874.361f, -42.4751f, 69.4316f, 0.785398f},
    {-873.19f, -50.4899f, 70.0568f, -2.41288f},
    {-868.511f, -148.386f, 62.3547f, 3.57875f},
    {-868.44f, -121.649f, 64.5056f, 3.33358f},
    {-868.324f, -77.7196f, 71.4768f, 5.41052f},
    {-859.846f, -19.6549f, 70.7304f, 1.97222f},
    {-828.05f, -150.508f, 62.2019f, 2.14675f},
    {-826.254f, -58.6911f, 72.0041f, 3.68264f},
    {-976.086f, -44.1775f, 76.029f, 1.46608f},
    {-971.864f, -87.4223f, 81.4954f, 5.8294f},
    {-966.551f, -74.1111f, 80.0243f, 4.2129f},
    {-958.509f, -173.652f, 77.9013f, 6.24828f},
    {-951.511f, -181.242f, 65.529f, 4.39823f},
    {-940.967f, -186.243f, 77.698f, 1.28164f},
    {-930.004f, -65.0898f, 79.077f, 0.0581657f},
    {-920.864f, -40.2009f, 78.256f, 5.16617f},
    {-919.089f, -148.021f, 62.0317f, 2.59327f},
    {-901.516f, -116.329f, 75.6876f, 0.471239f},
    {-897.864f, -84.4348f, 74.083f, 3.00197f},
    {-897.617f, -52.0457f, 71.9503f, 4.36332f},
    {-894.891f, -153.951f, 61.6827f, 3.23569f},
    {-893.933f, -111.625f, 75.6591f, 4.22536f},
    {-883.265f, -152.854f, 61.8384f, 0.0941087f},
    {-868.293f, -147.243f, 62.1097f, 3.2056f},
    {-867.501f, -11.8709f, 70.018f, 6.14356f},
    {-866.699f, -147.54f, 62.1646f, 3.57878f},
    {-866.566f, -91.1916f, 67.4414f, 4.56707f},
    {-857.272f, -141.142f, 61.7356f, 4.17134f},
    {-847.446f, -98.0061f, 68.5131f, 3.24631f},
    {-837.026f, -140.729f, 62.5141f, 5.51524f},
    {-824.204f, -65.053f, 72.3381f, 3.01942f},
    //vermin (s.th special for this mine)
    {-951.955f, -197.5f, 77.212f, 5.63741f},
    {-944.837f, -199.608f, 77.0737f, 4.97419f},
    {-933.494f, -209.063f, 73.7803f, 5.88176f},
    {-929.666f, -201.308f, 73.7032f, 5.02655f},
    {-978.997f, -249.356f, 65.4345f, 5.05464f},
    {-974.565f, -224.828f, 69.5858f, 4.88846f},
    {-946.514f, -259.239f, 66.0874f, 3.78132f},
    {-918.402f, -250.439f, 69.5271f, 2.21352f},
    {-910.14f, -229.959f, 72.9279f, 0.27677f},
    {-851.563f, -88.6527f, 68.5983f, 3.61896f},
    //boss
    {-848.902f, -92.931f, 68.6325f, 3.33350f},
    //herald
    {-48.459f, -288.802f, 55.47f, 1.0f},
    //triggers
    {637.083f, -32.6603f, 45.9715f, 1.14353f},         //aid_station
    {669.007f, -294.078f, 30.2909f, 2.77507f},     //stormpike_grave
    {77.8013f, -404.7f, 46.7549f, -0.872665f},     //stoneheart_grave
    {-202.581f, -112.73f, 78.4876f, -0.715585f},   //snowfall_grave
    {-611.962f, -396.17f, 60.8351f, 2.53682f},     //iceblood_grave
    {-1082.45f, -346.823f, 54.9219f, -1.53589f},   //frostwolf_grave
    {-1402.21f, -307.431f, 89.4424f, 0.191986f},   //frostwolf_hut
    {553.779f, -78.6566f, 51.9378f, -1.22173f},    //dunbaldar_south
    {674.001f, -143.125f, 63.6615f, 0.994838f},    //dunbaldar_north
    {203.281f, -360.366f, 56.3869f, -0.925024f},    //icewing_bunker
    {-152.437f, -441.758f, 40.3982f, -1.95477f},   //stoneheart_bunker
    {-571.88f, -262.777f, 75.0087f, -0.802851f},   //iceblood_tower
    {-768.907f, -363.71f, 90.8949f, 1.07991f},     //tower_point
    {-1302.9f, -316.981f, 113.867f, 2.00713f},     //frostwolf_etower
    {-1297.5f, -266.767f, 114.15f, 3.31044f},      //frostwolf_wtower
    {-57.7891f, -286.597f, 15.6479f, 6.02139f},    //AV_NPC_A_CAPTAIN balinda
    {722.43f, -10.9982f, 50.7046f, 3.42085f},      //AV_NPC_A_BOSS vanndar
    {-545.23f, -165.35f, 57.7886f, 3.01145f},      //AV_NPC_H_CAPTAIN galvangar
    {-1370.9f, -219.793f, 98.4258f, 5.04381f}      //AV_NPC_H_BOSS drek thar
};

//entry, team, minlevel, maxlevel
/// @todo: this array should be removed, the only needed things are the entrys (for spawning(?) and handlekillunit)
uint32 const BG_AV_CreatureInfo[AV_NPC_INFO_MAX] =
{
    13358, // Stormpike Bowman /// @todo: Confirm if this is correct. Author assumpted 60, 61 & 69, 70, but wouldn't work here
    12050, // Stormpike Defender
    13326, // Seasoned Defender
    13331, // Veteran Defender
    13422, // Champion Defender
    11949, // Captain Balinda Stonehearth: spawned with BG_AB_Creatures
    11948, // Vanndar Stormpike: spawned with BG_AB_Creatures

    13359, // Frostwolf Bowman
    12053, // Frostwolf Guardian
    13328, // Seasoned Guardian
    13332, // Veteran Guardian
    13421, // Champion Guardian
    11947, // Captain Galvangar: spawned with BG_AB_Creatures
    11946, // Drek'Thar: spawned with BG_AB_Creatures

    14763, // Dun Baldar South Marshal
    14762, // Dun Baldar North Marshal
    14764, // Icewing Marshal
    14765, // Stonehearth Marshal

    14773, // Iceblood Warmaster
    14776, // Tower Point Warmaster
    14772, // East Frostwolf Warmaster
    14777, // West Frostwolf Warmaster

    10987, // Irondeep Trogg
    11600, // Irondeep Shaman
    11602, // Irondeep Skullthumper
    11657, // Morloch

    13396, // irondeep alliance /// @todo: Correct and give correct ids
    13080,
    13098,
    13078,

    13397, // irondeep horde
    13099,
    13081,
    13079,

    11603, // south mine neutral
    11604,
    11605,
    11677,
    10982, // vermin

    13317, // alliance
    13096, // explorer
    13087, // invader
    13086,

    13316, // horde
    13097, // surveypr
    13089, // guard
    13088,

    14848  // Herald
};

BattlegroundSpawnPoint const BG_AV_Creatures[AV_STATICCPLACE_MAX] =
{
    { 2225,  { -1235.31f, -340.777f,  60.50880f,  3.316130f }, RESPAWN_IMMEDIATELY }, // 2225 - Zora Guthrek
    { 3343,  { -1244.02f, -323.795f,  61.04850f,  5.218530f }, RESPAWN_IMMEDIATELY }, // 3343 - Grelkor
    { 3625,  { -1235.16f, -332.302f,  60.29850f,  2.967060f }, RESPAWN_IMMEDIATELY }, // 3625 - Rarck
    { 4255,  {  587.303f, -42.8257f,  37.56150f,  5.235990f }, RESPAWN_IMMEDIATELY }, // 4255 - Brogus Thunderbrew
    { 4257,  {  643.635f, -58.3987f,  41.74050f,  4.729840f }, RESPAWN_IMMEDIATELY }, // 4257 - Lana Thunderbrew
    { 5134,  {  591.464f, -44.4520f,  37.61660f,  5.654870f }, RESPAWN_IMMEDIATELY }, // 5134 - Jonivera Farmountain
    { 5135,  {  608.515f, -33.3935f,  42.00030f,  5.410520f }, RESPAWN_IMMEDIATELY }, // 5135 - Svalbrad Farmountain
    { 5139,  {  617.656f, -32.0701f,  42.71680f,  4.066620f }, RESPAWN_IMMEDIATELY }, // 5139 - Kurdrum Barleybeard
    { 10364, { -1183.76f, -268.295f,  72.82330f,  3.281220f }, RESPAWN_IMMEDIATELY }, // 10364 - Yaelika Farclaw
    { 10367, { -1187.86f, -275.310f,  73.04810f,  3.630280f }, RESPAWN_IMMEDIATELY }, // 10367 - Shrye Ragefist
    { 10981, { -1008.42f, -368.006f,  55.34260f,  5.956470f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -1091.92f, -424.280f,  53.01390f,  2.939580f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -558.455f, -198.768f,  58.17550f,  4.979460f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -861.247f, -312.510f,  55.14270f,  3.353820f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -1003.81f, -395.913f,  50.47360f,  2.856310f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -904.500f, -289.815f,  65.12220f,  5.784700f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10981, { -1064.41f, -438.839f,  51.36140f,  1.888570f }, RESPAWN_IMMEDIATELY }, // 10981 - Frostwolf
    { 10986, {  258.814f,  76.2017f,  18.64680f,  6.190520f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10986, {  265.838f, -315.846f, -16.54290f,  3.159170f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10986, {  426.485f, -51.1927f, -5.662860f,  1.603470f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10986, {  452.044f, -33.9594f, -0.044651f,  2.728150f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10986, {  266.032f, -315.639f, -16.54290f,  4.679620f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10986, {  532.640f, -54.5863f,  20.70240f,  2.932150f }, RESPAWN_IMMEDIATELY }, // 10986 - Snowblind Harpy
    { 10990, {  295.183f, -299.908f, -34.61230f,  0.135851f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  421.080f, -225.006f, -23.73000f,  0.166754f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, { -55.7766f, -192.498f,  20.43520f,  6.122210f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  527.887f, -477.223f,  62.35590f,  0.170935f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  389.144f, -346.508f, -30.33400f,  4.141170f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  108.121f, -322.248f,  37.56550f,  4.467880f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  507.479f, -67.9403f,  10.35710f,  3.263040f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  329.071f, -185.016f, -29.15420f,  0.356943f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  252.449f, -422.313f,  35.14040f,  4.537710f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  358.882f, -118.061f, -24.91190f,  2.292570f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  487.151f, -174.229f,  14.75580f,  4.731920f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  449.652f, -123.561f,  6.142730f,  6.120290f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  272.419f, -261.802f, -41.88350f,  3.665590f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  359.021f, -210.954f, -29.34830f,  4.313390f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  450.598f, -318.048f, -37.75480f,  0.655219f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  509.333f, -218.200f,  3.054390f,  3.662920f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  485.771f, -223.613f, -1.530000f,  2.048620f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  486.636f, -452.172f,  39.65920f,  2.334100f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  702.783f, -257.494f,  25.97770f,  1.683290f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  460.942f, -199.263f, -6.014900f,  0.380506f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  483.108f, -115.307f,  10.10560f,  3.697010f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  471.601f, -154.174f,  14.07020f,  5.580700f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  213.938f, -420.793f,  41.25490f,  5.713940f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  289.387f, -294.685f, -33.90730f,  0.555494f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  155.649f, -402.891f,  43.39150f,  5.948380f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  517.184f, -295.105f, -9.781950f,  6.056680f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  102.334f, -332.165f,  38.98120f,  3.314450f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 10990, {  320.244f, -107.793f, -42.63570f, -1.003110f }, RESPAWN_IMMEDIATELY }, // 10990 - Alterac Ram
    { 11675, {  217.976f,  110.774f,  15.76030f,  4.567930f }, RESPAWN_IMMEDIATELY }, // 11675 - Snowblind Windcaller
    { 11675, {  269.872f,  6.66684f,  20.75920f,  0.381212f }, RESPAWN_IMMEDIATELY }, // 11675 - Snowblind Windcaller
    { 11675, {  313.528f, -319.041f, -27.23730f,  0.554098f }, RESPAWN_IMMEDIATELY }, // 11675 - Snowblind Windcaller
    { 11675, {  435.441f, -39.9289f, -0.169651f,  0.549454f }, RESPAWN_IMMEDIATELY }, // 11675 - Snowblind Windcaller
    { 11675, {  315.115f, -317.620f, -29.11230f,  0.901110f }, RESPAWN_IMMEDIATELY }, // 11675 - Snowblind Windcaller
    { 11678, {  428.091f, -122.731f,  3.403320f,  6.059010f }, RESPAWN_IMMEDIATELY }, // 11678 - Snowblind Ambusher
    { 11678, {  235.050f,  85.5705f,  18.30790f, -0.914255f }, RESPAWN_IMMEDIATELY }, // 11678 - Snowblind Ambusher
    { 11839, { -1553.04f, -344.342f,  64.41630f,  6.099330f }, RESPAWN_IMMEDIATELY }, // 11839 - Wildpaw Brute
    { 11947, { -545.230f, -165.350f,  57.78860f,  3.011450f }, RESPAWN_IMMEDIATELY }, // 11947 - Captain Galvangar
    { 11948, {  722.430f, -10.9982f,  50.70460f,  3.420850f }, RESPAWN_IMMEDIATELY }, // 11948 - Vanndar Stormpike
    { 11949, { -57.7891f, -286.597f,  15.64790f,  6.021390f }, RESPAWN_IMMEDIATELY }, // 11949 - Captain Balinda Stonehearth
    { 11997, {  930.498f, -520.755f,  93.73340f,  1.832600f }, RESPAWN_IMMEDIATELY }, // 11997 - Stormpike Herald
    { 12051, { -776.092f, -345.161f,  67.40920f,  1.892570f }, RESPAWN_IMMEDIATELY }, // 12051 - Frostwolf Legionnaire
    { 12051, { -1224.63f, -308.144f,  65.00870f,  4.011390f }, RESPAWN_IMMEDIATELY }, // 12051 - Frostwolf Legionnaire
    { 12051, { -713.039f, -442.515f,  82.86380f,  0.687240f }, RESPAWN_IMMEDIATELY }, // 12051 - Frostwolf Legionnaire
    { 12051, { -711.783f, -444.061f,  82.70390f,  0.683494f }, RESPAWN_IMMEDIATELY }, // 12051 - Frostwolf Legionnaire
    { 12096, {  587.633f, -45.9816f,  37.54380f,  5.811950f }, RESPAWN_IMMEDIATELY }, // 12096 - Stormpike Quartermaster
    { 12097, { -1293.79f, -194.407f,  72.43980f,  5.846850f }, RESPAWN_IMMEDIATELY }, // 12097 - Frostwolf Quartermaster
    { 12127, {  446.163f, -377.119f, -1.127250f,  0.209526f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  549.348f, -399.254f,  53.35370f,  3.247290f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  549.801f, -401.217f,  53.83050f,  3.247290f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  192.704f, -406.874f,  42.91830f,  6.106960f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  441.305f, -435.765f,  28.23850f,  2.144720f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  192.982f, -404.891f,  43.01320f,  6.106100f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  355.342f, -391.989f, -0.486707f,  3.006430f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  446.035f, -375.104f, -1.127250f,  0.210330f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  697.864f, -433.238f,  62.79140f,  1.657760f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  610.740f, -331.585f,  30.80210f,  5.142530f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  609.815f, -329.775f,  30.92710f, -2.388290f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  695.874f, -433.434f,  62.85430f,  1.657760f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 12127, {  443.337f, -435.283f,  28.68420f,  2.137680f }, RESPAWN_IMMEDIATELY }, // 12127 - Stormpike Guardsman
    { 13176, { -1251.50f, -316.327f,  62.65650f,  5.026550f }, RESPAWN_IMMEDIATELY }, // 13176 - Smith Regzar
    { 13179, { -1332.00f, -331.243f,  91.26310f,  1.500980f }, RESPAWN_IMMEDIATELY }, // 13179 - Wing Commander Guse
    { 13216, {  569.983f, -94.9992f,  38.03250f,  1.396260f }, RESPAWN_IMMEDIATELY }, // 13216 - Gaelden Hammersmith
    { 13218, { -1244.92f, -308.916f,  63.25250f,  1.623160f }, RESPAWN_IMMEDIATELY }, // 13218 - Grunnda Wolfheart
    { 13236, { -1319.56f, -342.675f,  60.34040f,  1.204280f }, RESPAWN_IMMEDIATELY }, // 13236 - Primalist Thurloga
    { 13257, {  647.610f, -61.1548f,  41.74050f,  4.241150f }, RESPAWN_IMMEDIATELY }, // 13257 - Murgot Deepforge
    { 13284, { -1321.64f, -343.730f,  60.48330f,  1.012290f }, RESPAWN_IMMEDIATELY }, // 13284 - Frostwolf Shaman
    { 13284, { -1317.61f, -342.853f,  60.37260f,  2.478370f }, RESPAWN_IMMEDIATELY }, // 13284 - Frostwolf Shaman
    { 13284, { -1319.31f, -344.475f,  60.38250f,  1.727880f }, RESPAWN_IMMEDIATELY }, // 13284 - Frostwolf Shaman
    { 13438, {  569.963f, -42.0218f,  37.75810f,  4.276060f }, RESPAWN_IMMEDIATELY }, // 13438 - Wing Commander Slidore
    { 13442, {  729.200f, -78.8120f,  51.63350f,  3.979350f }, RESPAWN_IMMEDIATELY }, // 13442 - Arch Druid Renferal
    { 13443, {  729.118f, -82.8713f,  51.63350f,  2.530730f }, RESPAWN_IMMEDIATELY }, // 13443 - Druid of the Grove
    { 13443, {  725.554f, -79.4973f,  51.63350f,  5.270890f }, RESPAWN_IMMEDIATELY }, // 13443 - Druid of the Grove
    { 13443, {  724.768f, -84.1642f,  51.63350f,  0.733038f }, RESPAWN_IMMEDIATELY }, // 13443 - Druid of the Grove
    { 13447, {  596.680f, -83.0633f,  39.00510f,  6.248280f }, RESPAWN_IMMEDIATELY }, // 13447 - Corporal Noreg Stormpike
    { 13577, {  600.032f, -2.92475f,  42.07880f,  5.009090f }, RESPAWN_IMMEDIATELY }, // 13577 - Stormpike Ram Rider Commander
    { 13617, {  610.239f, -21.8454f,  43.27200f,  4.904380f }, RESPAWN_IMMEDIATELY }, // 13617 - Stormpike Stable Master
    { 13797, {  613.422f, -150.764f,  33.45170f,  5.550150f }, RESPAWN_IMMEDIATELY }, // 13797 - Mountaineer Boombellow
    { 13798, { -1213.91f, -370.619f,  56.44550f,  0.837758f }, RESPAWN_IMMEDIATELY }, // 13798 - Jotek
    { 13816, {  704.350f, -22.9071f,  50.21870f,  0.785398f }, RESPAWN_IMMEDIATELY }, // 13816 - Prospector Stonehewer
    { 14185, { -1271.24f, -335.766f,  62.39710f,  5.759590f }, RESPAWN_IMMEDIATELY }, // 14185 - Najak Hexxen
    { 14186, { -1268.64f, -332.688f,  62.61710f,  5.288350f }, RESPAWN_IMMEDIATELY }, // 14186 - Ravak Grimtotem
    { 14187, {  648.363f, -65.2233f,  41.74050f,  3.124140f }, RESPAWN_IMMEDIATELY }, // 14187 - Athramanis
    { 14188, {  648.238f, -67.8931f,  41.74050f,  2.600540f }, RESPAWN_IMMEDIATELY }, // 14188 - Dirk Swindle
    { 14282, { -1223.44f, -309.833f,  64.93310f,  4.013100f }, RESPAWN_IMMEDIATELY }, // 14282 - Frostwolf Bloodhound
    { 14282, { -1226.40f, -307.136f,  64.97060f,  4.014500f }, RESPAWN_IMMEDIATELY }, // 14282 - Frostwolf Bloodhound
    { 14283, {  356.001f, -389.969f, -0.438796f,  3.033400f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14283, {  355.835f, -394.005f, -0.601490f,  3.024980f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14283, {  882.266f, -496.378f,  96.77070f,  4.832480f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14283, {  878.649f, -495.917f,  96.61710f,  4.676930f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14283, {  932.851f, -511.017f,  93.67480f,  3.610040f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14283, {  935.806f, -513.983f,  93.74360f,  3.617880f }, RESPAWN_IMMEDIATELY }, // 14283 - Stormpike Owl
    { 14284, {  947.412f, -509.982f,  95.10980f,  2.827430f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  934.557f, -512.395f,  93.66200f,  3.610040f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  939.420f, -502.777f,  94.58870f,  5.148720f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  854.276f, -494.241f,  96.80170f,  5.445430f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  776.621f, -487.775f,  99.40490f,  3.508110f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  880.169f, -495.699f,  96.62040f,  4.832500f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  773.651f, -497.482f,  99.04080f,  2.111850f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 14284, {  949.100f, -506.913f,  95.42370f,  3.316130f }, RESPAWN_IMMEDIATELY }, // 14284 - Stormpike Battleguard
    { 11946, { -1370.90f, -219.793f,  98.42580f,  5.043810f }, RESPAWN_IMMEDIATELY }  // 11946 - Drek'Thar
};

//alliance_control neutral_control horde_control
uint32 const BG_AV_MineWorldStates[2][3] =
{
    { 1358, 1360, 1359 },
    { 1355, 1357, 1356 }
};

uint32 const BG_AV_GraveyardIds[9] =
{
    AV_GRAVE_STORM_AID,
    AV_GRAVE_STORM_GRAVE,
    AV_GRAVE_STONE_GRAVE,
    AV_GRAVE_SNOWFALL,
    AV_GRAVE_ICE_GRAVE,
    AV_GRAVE_FROSTWOLF,
    AV_GRAVE_FROST_HUT,
    AV_GRAVE_MAIN_ALLIANCE,
    AV_GRAVE_MAIN_HORDE
};

StaticNodeInfo const BG_AV_NodeInfo[BG_AV_NODES_MAX] =
{
    { { 47, 48, 45, 46 }, { 1325, 1326, 1327, 1328 } }, // Stormpike First Aid Station
    { {  1,  2,  3,  4 }, { 1333, 1335, 1334, 1336 } }, // Stormpike Graveyard
    { { 55, 56, 53, 54 }, { 1302, 1304, 1301, 1303 } }, // Stoneheart Graveyard
    { {  5,  6,  7,  8 }, { 1341, 1343, 1342, 1344 } }, // Snowfall Graveyard
    { { 59, 60, 57, 58 }, { 1346, 1348, 1347, 1349 } }, // Iceblood Graveyard
    { {  9, 10, 11, 12 }, { 1337, 1339, 1338, 1340 } }, // Frostwolf Graveyard
    { { 51, 52, 49, 50 }, { 1329, 1331, 1330, 1332 } }, // Frostwolf Hut
    { { 16, 15, 14, 13 }, { 1361, 1375, 1370, 1378 } }, // Dunbaldar South Bunker
    { { 20, 19, 18, 17 }, { 1362, 1374, 1371, 1379 } }, // Dunbaldar North Bunker
    { { 24, 23, 22, 21 }, { 1363, 1376, 1372, 1380 } }, // Icewing Bunker
    { { 28, 27, 26, 25 }, { 1364, 1377, 1373, 1381 } }, // Stoneheart Bunker
    { { 44, 43, 42, 41 }, { 1368, 1390, 1385, 1395 } }, // Iceblood Tower
    { { 40, 39, 38, 37 }, { 1367, 1389, 1384, 1394 } }, // Tower Point
    { { 36, 35, 34, 33 }, { 1366, 1388, 1383, 1393 } }, // Frostwolf East Tower
    { { 32, 31, 30, 29 }, { 1365, 1387, 1382, 1392 } }  // Frostwolf West Tower
};

BattlegroundAV::BattlegroundAV()
{
    SetGameObjectsNumber(BG_AV_OBJECT_MAX);
    SetCreaturesNumber(AV_CPLACE_MAX + AV_STATICCPLACE_MAX);

    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        for (uint8 j = 0; j < 9; j++)
            m_Team_QuestStatus[i][j] = 0;

        m_Team_Scores[i] = 0;
        m_IsInformedNearVictory[i] = false;
        m_CaptainAlive[i] = true;
        m_CaptainBuffTimer[i] = 0;
    }

    for (uint8 i = 0; i < 2; ++i)
    {
        m_Mine_Owner[i] = 0;
        m_Mine_PrevOwner[i] = 0;
        m_Mine_Reclaim_Timer[i] = 0;
    }

    m_Mine_Timer = 0;

    for (BG_AV_Nodes i = BG_AV_NODES_AID_STATION; i < BG_AV_NODES_MAX; ++i)
        InitNode(i, 0, false);

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_AV_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_AV_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_AV_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_AV_HAS_BEGUN;
}

BattlegroundAV::~BattlegroundAV() { }

void BattlegroundAV::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
    UpdateScore(player->GetTeam(), -1);
}

void BattlegroundAV::HandleKillUnit(Creature* unit, Player* killer)
{
    TC_LOG_DEBUG("bg.battleground", "bg_av HandleKillUnit %i", unit->GetEntry());
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
    uint32 entry = unit->GetEntry();

    if (entry == BG_AV_CreatureInfo[AV_NPC_A_BOSS])
    {
        CastSpellOnTeam(23658, HORDE); //this is a spell which finishes a quest where a player has to kill the boss
        RewardReputationToTeam(729, 730, BG_AV_REP_BOSS, killer->GetTeam() == ALLIANCE ? ALLIANCE : HORDE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_BOSS), HORDE);
        EndBattleground(HORDE);
        DelCreature(AV_CPLACE_TRIGGER17);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_H_BOSS])
    {
        CastSpellOnTeam(23658, ALLIANCE); //this is a spell which finishes a quest where a player has to kill the boss
        RewardReputationToTeam(729, 730, BG_AV_REP_BOSS, killer->GetTeam() == ALLIANCE ? ALLIANCE : HORDE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_BOSS), ALLIANCE);
        EndBattleground(ALLIANCE);
        DelCreature(AV_CPLACE_TRIGGER19);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_A_CAPTAIN])
    {
        if (!m_CaptainAlive[TEAM_ALLIANCE])
        {
            TC_LOG_ERROR("bg.battleground", "Killed a Captain twice, please report this bug, if you haven't done \".respawn\"");
            return;
        }
        m_CaptainAlive[TEAM_ALLIANCE] = false;
        RewardReputationToTeam(729, 730, BG_AV_REP_CAPTAIN, killer->GetTeam() == ALLIANCE ? ALLIANCE : HORDE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_CAPTAIN), HORDE);
        UpdateScore(ALLIANCE, (-1)*BG_AV_RES_CAPTAIN);

        //spawn destroyed aura
        uint32 const lowerBound = BG_AV_FlameIndices[BG_AV_DESTRUCTIBLE_BUILDING_ALLIANCE];
        uint32 const upperBound = BG_AV_FlameIndices[BG_AV_DESTRUCTIBLE_BUILDING_ALLIANCE + 1];

        for (uint32 i = lowerBound; i < upperBound; ++i)
            SpawnBGObject(i, RESPAWN_IMMEDIATELY);

        DelCreature(AV_CPLACE_TRIGGER16);

        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
            herald->AI()->Talk(TEXT_STORMPIKE_GENERAL_DEAD);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_H_CAPTAIN])
    {
        if (!m_CaptainAlive[TEAM_HORDE])
        {
            TC_LOG_ERROR("bg.battleground", "Killed a Captain twice, please report this bug, if you haven't done \".respawn\"");
            return;
        }
        m_CaptainAlive[TEAM_HORDE] = false;
        RewardReputationToTeam(729, 730, BG_AV_REP_CAPTAIN, killer->GetTeam() == ALLIANCE ? ALLIANCE : HORDE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_CAPTAIN), ALLIANCE);
        UpdateScore(HORDE, (-1)*BG_AV_RES_CAPTAIN);

        //spawn destroyed aura
        uint32 const lowerBound = BG_AV_FlameIndices[BG_AV_DESTRUCTIBLE_BUILDING_HORDE];
        uint32 const upperBound = BG_AV_FlameIndices[BG_AV_DESTRUCTIBLE_BUILDING_HORDE + 1];

        for (uint32 i = lowerBound; i < upperBound; ++i)
            SpawnBGObject(i, RESPAWN_IMMEDIATELY);

        DelCreature(AV_CPLACE_TRIGGER18);

        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
            herald->AI()->Talk(TEXT_FROSTWOLF_GENERAL_DEAD);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_N_4] || entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_A_4] || entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_H_4])
        ChangeMineOwner(AV_NORTH_MINE, killer->GetTeam());
    else if (entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_N_4] || entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_A_4] || entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_H_4])
        ChangeMineOwner(AV_SOUTH_MINE, killer->GetTeam());
}

void BattlegroundAV::HandleQuestComplete(uint32 questid, Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;//maybe we should log this, cause this must be a cheater or a big bug
    uint8 team = GetTeamIndexByTeamId(player->GetTeam());
    uint8 CFSteam = GetTeamIndexByTeamId(GetOtherTeam(player->GetTeam()));
    /// @todo add reputation, events (including quest not available anymore, next quest available, go/npc de/spawning)and maybe honor
    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed", questid);
    switch (questid)
    {
        case AV_QUEST_A_SCRAPS1:
        case AV_QUEST_A_SCRAPS2:
        case AV_QUEST_H_SCRAPS1:
        case AV_QUEST_H_SCRAPS2:
            m_Team_QuestStatus[team][0]+=20;
            if (m_Team_QuestStatus[team][0] == 500 || m_Team_QuestStatus[team][0] == 1000 || m_Team_QuestStatus[team][0] == 1500) //25, 50, 75 turn ins
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed starting with unit upgrading..", questid);
                for (BG_AV_Nodes i = BG_AV_NODES_AID_STATION; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i)
                    if (m_Nodes[i].Owner == player->GetTeam() && m_Nodes[i].State == POINT_CONTROLED)
                    {
                        DePopulateNode(i);
                        PopulateNode(i);
                            //maybe this is bad, because it will instantly respawn all creatures on every grave..
                     }
            }
            break;
        case AV_QUEST_A_COMMANDER1:
        case AV_QUEST_H_COMMANDER1:
            m_Team_QuestStatus[team][1]++;
            RewardReputationToTeam(team, CFSteam, 1, player->GetTeam());
            if (m_Team_QuestStatus[team][1] == 30)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER2:
        case AV_QUEST_H_COMMANDER2:
            m_Team_QuestStatus[team][2]++;
            RewardReputationToTeam(team, CFSteam, 1, player->GetTeam());
            if (m_Team_QuestStatus[team][2] == 60)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER3:
        case AV_QUEST_H_COMMANDER3:
            m_Team_QuestStatus[team][3]++;
            RewardReputationToTeam(team, CFSteam, 1, player->GetTeam());
            if (m_Team_QuestStatus[team][3] == 120)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_BOSS1:
        case AV_QUEST_H_BOSS1:
            m_Team_QuestStatus[team][4] += 9; //you can turn in 10 or 1 item..
        case AV_QUEST_A_BOSS2:
        case AV_QUEST_H_BOSS2:
            m_Team_QuestStatus[team][4]++;
            if (m_Team_QuestStatus[team][4] >= 200)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_NEAR_MINE:
        case AV_QUEST_H_NEAR_MINE:
            m_Team_QuestStatus[team][5]++;
            if (m_Team_QuestStatus[team][5] == 28)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[team][6] == 7)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_OTHER_MINE:
        case AV_QUEST_H_OTHER_MINE:
            m_Team_QuestStatus[team][6]++;
            if (m_Team_QuestStatus[team][6] == 7)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[team][5] == 20)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_HIDE:
        case AV_QUEST_H_RIDER_HIDE:
            m_Team_QuestStatus[team][7]++;
            if (m_Team_QuestStatus[team][7] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[team][8] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_TAME:
        case AV_QUEST_H_RIDER_TAME:
            m_Team_QuestStatus[team][8]++;
            if (m_Team_QuestStatus[team][8] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[team][7] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        default:
            TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed but is not interesting at all", questid);
            return; //was no interesting quest at all
            break;
    }
}

//note: to remove reinforcements points must be negative, for adding reinforcements points must be positive
void BattlegroundAV::UpdateScore(uint16 team, int16 points)
{
    ASSERT(team == ALLIANCE || team == HORDE);
    uint8 teamindex = GetTeamIndexByTeamId(team); //0=ally 1=horde
    m_Team_Scores[teamindex] += points;

    UpdateWorldState(((teamindex == TEAM_HORDE) ? AV_Horde_Score : AV_Alliance_Score), m_Team_Scores[teamindex]);
    if (points < 0)
    {
        if (m_Team_Scores[teamindex] < 1)
        {
            m_Team_Scores[teamindex] = 0;
            EndBattleground(((teamindex == TEAM_HORDE) ? ALLIANCE : HORDE));
        }
        else if (!m_IsInformedNearVictory[teamindex] && m_Team_Scores[teamindex] < SEND_MSG_NEAR_LOSE)
        {
            SendMessageToAll(teamindex == TEAM_HORDE ? LANG_BG_AV_H_NEAR_LOSE : LANG_BG_AV_A_NEAR_LOSE, teamindex == TEAM_HORDE ? CHAT_MSG_BG_SYSTEM_HORDE : CHAT_MSG_BG_SYSTEM_ALLIANCE);
            PlaySoundToAll(AV_SOUND_NEAR_VICTORY);
            m_IsInformedNearVictory[teamindex] = true;
        }
    }
}

Creature* BattlegroundAV::AddAVCreature(uint16 cinfoid, uint16 type)
{
    bool isStatic = false;
    Creature* creature = nullptr;
    ASSERT(type <= AV_CPLACE_MAX + AV_STATICCPLACE_MAX);
    if (type >= AV_CPLACE_MAX) //static
    {
        BattlegroundSpawnPoint const& spawnPoint = BG_AV_Creatures[type - AV_CPLACE_MAX];
        creature = AddCreature(spawnPoint.Entry, type, spawnPoint.Pos, spawnPoint.SpawnTime);
        isStatic = true;
    }
    else
        creature = AddCreature(BG_AV_CreatureInfo[cinfoid], type, BG_AV_CreaturePos[type]);

    if (!creature)
        return nullptr;

    if (cinfoid == AV_NPC_A_CAPTAIN || cinfoid == AV_NPC_H_CAPTAIN)
        creature->SetRespawnDelay(RESPAWN_ONE_DAY); /// @todo look if this can be done by database + also add this for the wingcommanders

    if ((isStatic && cinfoid >= 10 && cinfoid <= 14) || (!isStatic && ((cinfoid >= AV_NPC_A_GRAVEDEFENSE0 && cinfoid <= AV_NPC_A_GRAVEDEFENSE3) ||
        (cinfoid >= AV_NPC_H_GRAVEDEFENSE0 && cinfoid <= AV_NPC_H_GRAVEDEFENSE3))))
    {
        if (!isStatic && ((cinfoid >= AV_NPC_A_GRAVEDEFENSE0 && cinfoid <= AV_NPC_A_GRAVEDEFENSE3)
            || (cinfoid >= AV_NPC_H_GRAVEDEFENSE0 && cinfoid <= AV_NPC_H_GRAVEDEFENSE3)))
            creature->SetRespawnRadius(5.f);
        else
            creature->SetRespawnRadius(15.f);

        /// @todo find a way to add a motionmaster without killing the creature
        creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
        creature->GetMotionMaster()->Initialize();
        creature->Respawn(true);
    }

    uint32 triggerSpawnID = 0;
    uint32 newFaction = 0;
    switch (cinfoid)
    {
        case AV_NPC_A_CAPTAIN:
            triggerSpawnID = AV_CPLACE_TRIGGER16;
            newFaction = 84;
            break;
        case AV_NPC_A_BOSS:
            triggerSpawnID = AV_CPLACE_TRIGGER17;
            newFaction = 84;
            break;
        case AV_NPC_H_CAPTAIN:
            triggerSpawnID = AV_CPLACE_TRIGGER18;
            newFaction = 83;
            break;
        case AV_NPC_H_BOSS:
            triggerSpawnID = AV_CPLACE_TRIGGER19;
            newFaction = 83;
            break;
        default:
            break;
    }

    if (triggerSpawnID && newFaction)
    {
        if (Creature* trigger = AddCreature(WORLD_TRIGGER, triggerSpawnID, BG_AV_CreaturePos[triggerSpawnID]))
        {
            trigger->setFaction(newFaction);
            trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
        }
    }

    return creature;
}

void BattlegroundAV::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)//0=alliance, 1=horde
        {
            if (!m_CaptainAlive[i])
                continue;

            if (m_CaptainBuffTimer[i] > diff)
                m_CaptainBuffTimer[i] -= diff;
            else
            {
                if (i == TEAM_ALLIANCE)
                {
                    CastSpellOnTeam(AV_BUFF_A_CAPTAIN, ALLIANCE);
                    if (Creature* creature = GetBGCreature(AV_CPLACE_MAX + 61))
                        creature->AI()->DoAction(ACTION_BUFF_YELL);
                }
                else
                {
                    CastSpellOnTeam(AV_BUFF_H_CAPTAIN, HORDE);
                    if (Creature* creature = GetBGCreature(AV_CPLACE_MAX + 59))
                        creature->AI()->DoAction(ACTION_BUFF_YELL);
                }

                m_CaptainBuffTimer[i] = urand(2, 6) * MINUTE * IN_MILLISECONDS; // as far as i could see, the buff is random so i make 2 minutes (that's the duration of the buff itself) + 0-4 minutes @todo get the right times
            }
        }

        //add points from mine owning, and look if the neutral team wants to reclaim the mine
        m_Mine_Timer -= diff;
        for (uint8 mine = AV_NORTH_MINE; mine <= AV_SOUTH_MINE; ++mine)
        {
            if (m_Mine_Owner[mine] == ALLIANCE || m_Mine_Owner[mine] == HORDE)
            {
                if (m_Mine_Timer <= 0)
                    UpdateScore(m_Mine_Owner[mine], 1);

                if (m_Mine_Reclaim_Timer[mine])
                {
                    if (m_Mine_Reclaim_Timer[mine] <= diff)
                        ChangeMineOwner(mine, AV_NEUTRAL_TEAM);
                    else
                        m_Mine_Reclaim_Timer[mine] -= diff;
                }
            }
        }

        if (m_Mine_Timer <= 0)
            m_Mine_Timer = AV_MINE_TICK_TIMER; //this is at the end, cause we need to update both mines

        //looks for all timers of the nodes and destroy the building (for graveyards the building wont get destroyed, it goes just to the other team
        for (BG_AV_Nodes i = BG_AV_NODES_AID_STATION; i < BG_AV_NODES_MAX; ++i)
        {
            if (m_Nodes[i].State == POINT_ASSAULTED) //maybe remove this
            {
                if (m_Nodes[i].Timer > diff)
                    m_Nodes[i].Timer -= diff;
                else
                    EventPlayerDestroyedPoint(i);
            }
        }
    }
}

void BattlegroundAV::StartingEventCloseDoors()
{
    for (uint32 i = BG_AV_OBJECT_DOOR_A; i <= BG_AV_GHOST_GATE_H; ++i)
    {
        DoorClose(i);
        SpawnBGObject(i, BG_AV_GameObjects[i].SpawnTime);
    }
}

void BattlegroundAV::StartingEventOpenDoors()
{
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning mine stuff");
    for (uint32 i = BG_AV_OBJECT_MINE_SUPPLY_N_MIN; i <= BG_AV_OBJECT_MINE_SUPPLY_N_MAX; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
    for (uint32 i = BG_AV_OBJECT_MINE_SUPPLY_S_MIN; i <= BG_AV_OBJECT_MINE_SUPPLY_S_MAX; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
    for (uint8 mine = AV_NORTH_MINE; mine <= AV_SOUTH_MINE; ++mine) //mine population
        ChangeMineOwner(mine, AV_NEUTRAL_TEAM, true);

    UpdateWorldState(AV_SHOW_H_SCORE, 1);
    UpdateWorldState(AV_SHOW_A_SCORE, 1);

    for (uint32 i = BG_AV_OBJECT_DOOR_A; i <= BG_AV_GHOST_GATE_H; ++i)
        DoorOpen(i);

    for (uint32 i = BG_AV_GHOST_GATE_A; i <= BG_AV_GHOST_GATE_H; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);

    // Achievement: The Alterac Blitz
    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, BG_AV_EVENT_START_BATTLE);
}

void BattlegroundAV::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID().GetCounter()] = new BattlegroundAVScore(player->GetGUID());
}

void BattlegroundAV::EndBattleground(uint32 winner)
{
    //calculate bonuskills for both teams:
    //first towers:
    uint8 kills[2] = {0, 0}; // 0 = Alliance 1 = Horde
    uint8 rep[2] = {0, 0};   // 0 = Alliance 1 = Horde
    for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i)
    {
        if (m_Nodes[i].State == POINT_CONTROLED)
        {
            if (m_Nodes[i].Owner == ALLIANCE)
            {
                rep[0]   += BG_AV_REP_SURVIVING_TOWER;
                kills[0] += BG_AV_KILL_SURVIVING_TOWER;
            }
            else
            {
                rep[0]   += BG_AV_KILL_SURVIVING_TOWER;
                kills[1] += BG_AV_KILL_SURVIVING_TOWER;
            }
        }
    }

    for (uint8 i = 0; i <= BG_TEAMS_COUNT; ++i)
    {
        if (m_CaptainAlive[i])
        {
            kills[i] += BG_AV_KILL_SURVIVING_CAPTAIN;
            rep[i]   += BG_AV_REP_SURVIVING_CAPTAIN;
        }

        if (rep[i] != 0)
            RewardReputationToTeam(729, 730, 10, i == ALLIANCE ? ALLIANCE : HORDE);

        if (kills[i] != 0)
            RewardHonorToTeam(GetBonusHonorFromKill(kills[i]), i == 0 ? ALLIANCE : HORDE);
    }

    /// @todo add enterevademode for all attacking creatures
    Battleground::EndBattleground(winner);
}

void BattlegroundAV::RemovePlayer(Player* player, ObjectGuid /*guid*/, uint32 /*team*/)
{
   if (!player)
    {
        TC_LOG_ERROR("bg.battleground", "bg_AV no player at remove");
        return;
    }

    /// @todo search more buffs
    player->RemoveAurasDueToSpell(AV_BUFF_ARMOR);
    player->RemoveAurasDueToSpell(AV_BUFF_A_CAPTAIN);
    player->RemoveAurasDueToSpell(AV_BUFF_H_CAPTAIN);
}

void BattlegroundAV::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 95:
        case 2608:
            if (player->GetTeam() != ALLIANCE)
                player->GetSession()->SendAreaTriggerMessage("Only The Alliance can use that portal");
            else
                player->LeaveBattleground();
            break;
        case 2606:
            if (player->GetTeam() != HORDE)
                player->GetSession()->SendAreaTriggerMessage("Only The Horde can use that portal");
            else
                player->LeaveBattleground();
            break;
        case 3326:
        case 3327:
        case 3328:
        case 3329:
        case 3330:
        case 3331:
            //Source->Unmount();
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

bool BattlegroundAV::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_GRAVEYARDS_ASSAULTED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_ASSAULT_GRAVEYARD);
            break;
        case SCORE_GRAVEYARDS_DEFENDED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_DEFEND_GRAVEYARD);
            break;
        case SCORE_TOWERS_ASSAULTED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_ASSAULT_TOWER);
            break;
        case SCORE_TOWERS_DEFENDED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_DEFEND_TOWER);
            break;
        default:
            break;
    }
    return true;
}

void BattlegroundAV::EventPlayerDestroyedPoint(BG_AV_Nodes node)
{
    uint32 object = GetObjectThroughNode(node);
    TC_LOG_DEBUG("bg.battleground", "bg_av: player destroyed point node %i object %i", node, object);

    //despawn banner
    SpawnBGObject(object, RESPAWN_ONE_DAY);
    DestroyNode(node);
    UpdateNodeWorldState(node);

    uint32 owner = m_Nodes[node].Owner;
    if (IsTower(node))
    {
        uint8 tmp = node - BG_AV_NODES_DUNBALDAR_SOUTH;
        //despawn marshal
        if (!GetBGCreature(AV_CPLACE_A_MARSHAL_SOUTH + tmp, false))
            TC_LOG_ERROR("bg.battleground", "BG_AV: playerdestroyedpoint: marshal %i doesn't exist", AV_CPLACE_A_MARSHAL_SOUTH + tmp);
        else
            DelCreature(AV_CPLACE_A_MARSHAL_SOUTH + tmp);

        uint32 const lowerBound = BG_AV_FlameIndices[tmp];
        uint32 const upperBound = BG_AV_FlameIndices[tmp + 1];

        // spawn destroyed aura
        for (uint32 i = lowerBound; i < upperBound; ++i)
            SpawnBGObject(i, RESPAWN_IMMEDIATELY);

        UpdateScore((owner == ALLIANCE) ? HORDE : ALLIANCE, -1 * BG_AV_RES_TOWER);
        RewardReputationToTeam(729, 730, BG_AV_REP_TOWER, owner);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_TOWER), owner);

        SpawnBGObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH + tmp, RESPAWN_ONE_DAY);
        SpawnBGObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH + tmp, RESPAWN_ONE_DAY);
    }
    else
    {
        uint32 const hordeDelta = BG_AV_OBJECT_AURA_A_FROSTWOLF_HUT - BG_AV_OBJECT_AURA_A_AID_STATION + 1;

        if (owner == ALLIANCE)
            SpawnBGObject(object + BG_AV_OBJECT_FLAG_A_AID_STATION - BG_AV_OBJECT_FLAG_C_A_AID_STATION, RESPAWN_IMMEDIATELY); // contested by alliance, spawn alliance banner
        else
            SpawnBGObject(object + BG_AV_OBJECT_FLAG_H_AID_STATION - BG_AV_OBJECT_FLAG_C_H_AID_STATION, RESPAWN_IMMEDIATELY); // contested by horde, spawn horde banner

        SpawnBGObject(BG_AV_OBJECT_AURA_N_AID_STATION_CONT_A + BG_TEAMS_COUNT * node + GetTeamIndexByTeamId(owner), RESPAWN_ONE_DAY);
        SpawnBGObject(BG_AV_OBJECT_AURA_A_AID_STATION + GetTeamIndexByTeamId(owner) * hordeDelta + node, RESPAWN_IMMEDIATELY);
        PopulateNode(node);

        if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall eyecandy
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                SpawnBGObject((owner == ALLIANCE ? BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_PH) + i, RESPAWN_ONE_DAY);
                SpawnBGObject((owner == ALLIANCE ? BG_AV_OBJECT_SNOW_EYECANDY_A : BG_AV_OBJECT_SNOW_EYECANDY_H) + i, RESPAWN_IMMEDIATELY);
            }
        }
    }

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
            herald->AI()->Talk(owner == ALLIANCE ? nodeInfo->TextIds.AllianceCapture : nodeInfo->TextIds.HordeCapture);
}

void BattlegroundAV::ChangeMineOwner(uint8 mine, uint32 team, bool initial)
{
    // mine=0 northmine mine=1 southmin
    // changing the owner results in setting respawntim to infinite for current creatures,
    // spawning new mine owners creatures and changing the chest-objects so that the current owning team can use them
    ASSERT(mine == AV_NORTH_MINE || mine == AV_SOUTH_MINE);
    if (team != ALLIANCE && team != HORDE)
        team = AV_NEUTRAL_TEAM;

    if (m_Mine_Owner[mine] == team && !initial)
        return;

    m_Mine_PrevOwner[mine] = m_Mine_Owner[mine];
    m_Mine_Owner[mine] = team;

    if (!initial)
    {
        TC_LOG_DEBUG("bg.battleground", "bg_av depopulating mine %i (0=north, 1=south)", mine);
        if (mine == AV_SOUTH_MINE)
            for (uint16 i = AV_CPLACE_MINE_S_S_MIN; i <= AV_CPLACE_MINE_S_S_MAX; ++i)
                DelCreature(i); /// @todo just set the respawntime to 999999

        for (uint16 i = ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_1_MIN : AV_CPLACE_MINE_S_1_MIN); i <= ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_3 : AV_CPLACE_MINE_S_3); ++i)
            DelCreature(i); /// @todo here also
    }

    SendMineWorldStates(mine);

    TC_LOG_DEBUG("bg.battleground", "bg_av populating mine %i (0=north, 1=south)", mine);
    uint16 miner;
    //also neutral team exists.. after a big time, the neutral team tries to conquer the mine
    if (mine == AV_NORTH_MINE)
    {
        if (team == ALLIANCE)
            miner = AV_NPC_N_MINE_A_1;
        else if (team == HORDE)
            miner = AV_NPC_N_MINE_H_1;
        else
            miner = AV_NPC_N_MINE_N_1;
    }
    else
    {
        uint16 cinfo;
        if (team == ALLIANCE)
            miner = AV_NPC_S_MINE_A_1;
        else if (team == HORDE)
            miner = AV_NPC_S_MINE_H_1;
        else
            miner = AV_NPC_S_MINE_N_1;

        //vermin
        TC_LOG_DEBUG("bg.battleground", "spawning vermin");
        if (team == ALLIANCE)
            cinfo = AV_NPC_S_MINE_A_3;
        else if (team == HORDE)
            cinfo = AV_NPC_S_MINE_H_3;
        else
            cinfo = AV_NPC_S_MINE_N_S;

        for (uint16 i = AV_CPLACE_MINE_S_S_MIN; i <= AV_CPLACE_MINE_S_S_MAX; ++i)
            AddAVCreature(cinfo, i);
    }
    for (uint16 i = ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_1_MIN : AV_CPLACE_MINE_S_1_MIN); i <= ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_1_MAX : AV_CPLACE_MINE_S_1_MAX); ++i)
        AddAVCreature(miner, i);

    //the next chooses randomly between 2 cretures
    for (uint16 i = ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_2_MIN : AV_CPLACE_MINE_S_2_MIN); i <= ((mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_2_MAX : AV_CPLACE_MINE_S_2_MAX); ++i)
        AddAVCreature(miner + (urand(1, 2)), i);

    AddAVCreature(miner + 3, (mine == AV_NORTH_MINE) ? AV_CPLACE_MINE_N_3 : AV_CPLACE_MINE_S_3);

    if (team == ALLIANCE || team == HORDE)
    {
        m_Mine_Reclaim_Timer[mine] = AV_MINE_RECLAIM_TIMER;

        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
        {
            if (mine == AV_NORTH_MINE)
                herald->AI()->Talk(team == ALLIANCE ? TEXT_IRONDEEP_MINE_ALLIANCE_TAKEN : TEXT_IRONDEEP_MINE_HORDE_TAKEN);
            else if (mine == AV_SOUTH_MINE)
                herald->AI()->Talk(team == ALLIANCE ? TEXT_COLDTOOTH_MINE_ALLIANCE_TAKEN : TEXT_COLDTOOTH_MINE_HORDE_TAKEN);
        }
    }
    else
    {
        // disable timer
        m_Mine_Reclaim_Timer[mine] = 0;

        if (mine == AV_SOUTH_MINE)
        {
            if (Creature* creature = GetBGCreature(AV_CPLACE_MINE_S_3))
                creature->AI()->Talk(TEXT_SNIVVLE_RANDOM);
        }
    }
}

bool BattlegroundAV::CanActivateGO(int32 GOId, uint32 team) const
{
    if (GOId == BG_AV_OBJECTID_MINE_N)
         return (m_Mine_Owner[AV_NORTH_MINE] == team);
    if (GOId == BG_AV_OBJECTID_MINE_S)
         return (m_Mine_Owner[AV_SOUTH_MINE] == team);
    return true; // cause it's no mine'object it is ok if this is true
}

void BattlegroundAV::PopulateNode(BG_AV_Nodes node)
{
    uint32 owner = m_Nodes[node].Owner;
    ASSERT(owner);

    uint32 c_place = AV_CPLACE_DEFENSE_STORM_AID + (4 * node);
    uint32 creatureid;
    if (IsTower(node))
        creatureid = (owner == ALLIANCE) ? AV_NPC_A_TOWERDEFENSE : AV_NPC_H_TOWERDEFENSE;
    else
    {
        uint8 team = GetTeamIndexByTeamId(owner);
        if (m_Team_QuestStatus[team][0] < 500)
            creatureid = (owner == ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE0 : AV_NPC_H_GRAVEDEFENSE0;
        else if (m_Team_QuestStatus[team][0] < 1000)
            creatureid = (owner == ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE1 : AV_NPC_H_GRAVEDEFENSE1;
        else if (m_Team_QuestStatus[team][0] < 1500)
            creatureid = (owner == ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE2 : AV_NPC_H_GRAVEDEFENSE2;
        else
            creatureid = (owner == ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE3 : AV_NPC_H_GRAVEDEFENSE3;

        // spiritguide
        if (node <= BG_AV_NODES_FROSTWOLF_HUT)
        {
            DelCreature(node);
            if (!AddSpiritGuide(node, BG_AV_CreaturePos[node], GetTeamIndexByTeamId(owner)))
                TC_LOG_ERROR("bg.battleground", "AV: couldn't spawn spiritguide at node %i", node);
        }
    }

    for (uint32 i = 0; i < 4; ++i)
        AddAVCreature(creatureid, c_place + i);

    if (node >= BG_AV_NODES_MAX) // fail safe
        return;

    Creature* trigger = GetBGCreature(node + AV_CPLACE_TRIGGER01, false); // 0-302 other creatures
    if (!trigger)
        trigger = AddCreature(WORLD_TRIGGER, node + AV_CPLACE_TRIGGER01, BG_AV_CreaturePos[node + AV_CPLACE_TRIGGER01]);

    // add bonus honor aura trigger creature when node is accupied
    // cast bonus aura (+50% honor in 25yards)
    // aura should only apply to players who have accupied the node, set correct faction for trigger
    if (trigger)
    {
        if (owner != ALLIANCE && owner != HORDE) // node can be neutral, remove trigger
        {
            DelCreature(node + AV_CPLACE_TRIGGER01);
            return;
        }

        trigger->setFaction(owner == ALLIANCE ? 84 : 83);
        trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
    }
}

void BattlegroundAV::DePopulateNode(BG_AV_Nodes node)
{
    uint32 c_place = AV_CPLACE_DEFENSE_STORM_AID + (4 * node);
    for (uint32 i = 0; i < 4; ++i)
        DelCreature(c_place + i);

    // spirit guide
    if (!IsTower(node) && node <= BG_AV_NODES_FROSTWOLF_HUT)
        DelCreature(node);

    // remove bonus honor aura trigger creature when node is lost
    if (node < BG_AV_NODES_MAX) //fail safe
        DelCreature(node + AV_CPLACE_TRIGGER01); // NULL checks are in DelCreature! 0-302 spirit guides
}

BG_AV_Nodes BattlegroundAV::GetNodeThroughObject(uint32 object)
{
    TC_LOG_DEBUG("bg.battleground", "bg_AV getnodethroughobject %i", object);
    if (object < BG_AV_OBJECT_FLAG_A_AID_STATION)
    {
        TC_LOG_ERROR("bg.battleground", "BattlegroundAV: ERROR! GetPlace got a wrong object (%u) :(", object);
        ABORT();
        return BG_AV_Nodes(0);
    }
    if (object <= BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER)
        return BG_AV_Nodes(object - BG_AV_OBJECT_FLAG_A_AID_STATION);
    if (object <= BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_HUT)
        return BG_AV_Nodes(object - BG_AV_OBJECT_FLAG_C_A_AID_STATION);
    if (object <= BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_WTOWER)
        return BG_AV_Nodes(object + BG_AV_NODES_ICEBLOOD_TOWER - BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_TOWER);
    if (object <= BG_AV_OBJECT_FLAG_C_H_STONEHEART_BUNKER)
        return BG_AV_Nodes(object - BG_AV_OBJECT_FLAG_C_H_AID_STATION);
    if (object <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT)
        return BG_AV_Nodes(object - BG_AV_OBJECT_FLAG_H_AID_STATION);
    if (object <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER)
        return BG_AV_Nodes(object + BG_AV_NODES_ICEBLOOD_TOWER - BG_AV_OBJECT_FLAG_H_ICEBLOOD_TOWER);
    if (object == BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE)
        return BG_AV_NODES_SNOWFALL_GRAVE;
    TC_LOG_ERROR("bg.battleground", "BattlegroundAV: ERROR! GetPlace got a wrong object (%u) :(", object);
    ABORT();
    return BG_AV_Nodes(0);
}

// this function is the counterpart to GetNodeThroughObject()
uint32 BattlegroundAV::GetObjectThroughNode(BG_AV_Nodes node)
{
    TC_LOG_DEBUG("bg.battleground", "bg_AV GetObjectThroughNode %u", node);
    if (m_Nodes[node].Owner == ALLIANCE)
    {
        if (m_Nodes[node].State == POINT_ASSAULTED)
        {
            if (node <= BG_AV_NODES_FROSTWOLF_HUT)
                return node + BG_AV_OBJECT_FLAG_C_A_AID_STATION;
            if (node >= BG_AV_NODES_ICEBLOOD_TOWER && node <= BG_AV_NODES_FROSTWOLF_WTOWER)
                return node + BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_TOWER - BG_AV_NODES_ICEBLOOD_TOWER;
        }
        else if (m_Nodes[node].State == POINT_CONTROLED)
            if (node <= BG_AV_NODES_STONEHEART_BUNKER)
                return node + BG_AV_OBJECT_FLAG_A_AID_STATION;
    }
    else if (m_Nodes[node].Owner == HORDE)
    {
        if (m_Nodes[node].State == POINT_ASSAULTED)
        {
            if (node <= BG_AV_NODES_STONEHEART_BUNKER)
                return node + BG_AV_OBJECT_FLAG_C_H_AID_STATION;
        }
        else if (m_Nodes[node].State == POINT_CONTROLED)
        {
            if (node <= BG_AV_NODES_FROSTWOLF_HUT)
                return node + BG_AV_OBJECT_FLAG_H_AID_STATION;
            if (node >= BG_AV_NODES_ICEBLOOD_TOWER && node <= BG_AV_NODES_FROSTWOLF_WTOWER)
                return node + BG_AV_OBJECT_FLAG_H_ICEBLOOD_TOWER - BG_AV_NODES_ICEBLOOD_TOWER;
        }
    }
    else if (m_Nodes[node].Owner == AV_NEUTRAL_TEAM)
        return BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE;

    TC_LOG_ERROR("bg.battleground", "BattlegroundAV: Error! GetPlaceNode couldn't resolve node %u", node);
    ABORT();
    return 0;
}

//called when using banner
void BattlegroundAV::EventPlayerClickedOnFlag(Player* source, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    int32 object = GetObjectType(target_obj->GetGUID());
    TC_LOG_DEBUG("bg.battleground", "BG_AV using gameobject %i with type %i", target_obj->GetEntry(), object);
    if (object < 0)
        return;

    switch (target_obj->GetEntry())
    {
        case BG_AV_OBJECTID_BANNER_A_AID_STATION:
        case BG_AV_OBJECTID_BANNER_A_STORMPIKE:
        case BG_AV_OBJECTID_BANNER_A_STONEHEARTH_GRAVE:
        case BG_AV_OBJECTID_BANNER_A_SNOWFALL_GRAVE:
        case BG_AV_OBJECTID_BANNER_A_ICEBLOOD_GRAVE:
        case BG_AV_OBJECTID_BANNER_A_FROSTWOLF_GRAVE:
        case BG_AV_OBJECTID_BANNER_A_FROSTWOLF_HUT:
        case BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_S:
        case BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_N:
        case BG_AV_OBJECTID_BANNER_A_ICEWING_BUNKER:
        case BG_AV_OBJECTID_BANNER_A_STONEHEARTH_BUNKER:
        case BG_AV_OBJECTID_BANNER_H_AID_STATION:
        case BG_AV_OBJECTID_BANNER_H_STORMPIKE:
        case BG_AV_OBJECTID_BANNER_H_STONEHEARTH_GRAVE:
        case BG_AV_OBJECTID_BANNER_H_SNOWFALL:
        case BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GRAVE:
        case BG_AV_OBJECTID_BANNER_H_FROSTWOLF_GRAVE:
        case BG_AV_OBJECTID_BANNER_H_FROSTWOLF_HUT:
        case BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GARRISON:
        case BG_AV_OBJECTID_BANNER_H_TOWER_POINT:
        case BG_AV_OBJECTID_BANNER_H_FROSTWOLF_E:
        case BG_AV_OBJECTID_BANNER_H_FROSTWOLF_W:
        case BG_AV_OBJECTID_BANNER_SNOWFALL_N:
            EventPlayerAssaultsPoint(source, object);
            break;
        case BG_AV_OBJECTID_BANNER_CONT_A_AID_STATION:
        case BG_AV_OBJECTID_BANNER_CONT_A_STORMPIKE:
        case BG_AV_OBJECTID_BANNER_CONT_A_STONEHEARTH_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_A_SNOWFALL:
        case BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_HUT:
        case BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GARRISON:
        case BG_AV_OBJECTID_BANNER_CONT_A_TOWER_POINT:
        case BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_E:
        case BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_W:
        case BG_AV_OBJECTID_BANNER_CONT_H_AID_STATION:
        case BG_AV_OBJECTID_BANNER_CONT_H_STORMPIKE:
        case BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_H_SNOWFALL:
        case BG_AV_OBJECTID_BANNER_CONT_H_ICEBLOOD_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_GRAVE:
        case BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_HUT:
        case BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_S:
        case BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_N:
        case BG_AV_OBJECTID_BANNER_CONT_H_ICEWING_BUNKER:
        case BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_BUNKER:
            EventPlayerDefendsPoint(source, object);
            break;
        default:
            break;
    }
}

void BattlegroundAV::EventPlayerDefendsPoint(Player* player, uint32 object)
{
    ASSERT(GetStatus() == STATUS_IN_PROGRESS);
    BG_AV_Nodes node = GetNodeThroughObject(object);

    uint32 owner = m_Nodes[node].Owner; //maybe should name it prevowner
    uint32 team = player->GetTeam();

    if (owner == player->GetTeam() || m_Nodes[node].State != POINT_ASSAULTED)
        return;

    //until snowfall doesn't belong to anyone it is better handled in assault-code
    if (m_Nodes[node].TotalOwner == AV_NEUTRAL_TEAM)
    {
        ASSERT(node == BG_AV_NODES_SNOWFALL_GRAVE); //currently the only neutral grave
        EventPlayerAssaultsPoint(player, object);
        return;
    }

    TC_LOG_DEBUG("bg.battleground", "player defends point object: %i node: %i", object, node);
    if (m_Nodes[node].PrevOwner != team)
    {
        TC_LOG_ERROR("bg.battleground", "BG_AV: player defends point which doesn't belong to his team %i", node);
        return;
    }

    //spawn new go :)
    if (m_Nodes[node].Owner == ALLIANCE)
        SpawnBGObject(object + BG_AV_OBJECT_FLAG_H_AID_STATION - BG_AV_OBJECT_FLAG_C_A_AID_STATION, RESPAWN_IMMEDIATELY); // flag is contested alliance, spawn horde banner
    else
        SpawnBGObject(object + BG_AV_OBJECT_FLAG_A_AID_STATION - BG_AV_OBJECT_FLAG_C_H_AID_STATION, RESPAWN_IMMEDIATELY); // flag is contested horde, spawn alliance banner

    if (!IsTower(node))
    {
        // how much we have to offset in case team == horde
        uint32 const hordeDelta = BG_AV_OBJECT_AURA_A_FROSTWOLF_HUT - BG_AV_OBJECT_AURA_A_AID_STATION + 1;

        // remove contested ("neutral") aura, it will correspond to attacker team
        SpawnBGObject(BG_AV_OBJECT_AURA_N_AID_STATION_CONT_A + BG_TEAMS_COUNT * node + GetTeamIndexByTeamId(GetOtherTeam(team)), RESPAWN_ONE_DAY);
        // note: snowfall initial neutral aura is handled in EventPlayerAssaultsPoint, as it'll only appear before first assault.

        // now make corresponding aura visible
        SpawnBGObject(BG_AV_OBJECT_AURA_A_AID_STATION + GetTeamIndexByTeamId(team) * hordeDelta + node, RESPAWN_IMMEDIATELY);
    }
    // despawn old go
    SpawnBGObject(object, RESPAWN_ONE_DAY);

    DefendNode(node, team);
    PopulateNode(node);
    UpdateNodeWorldState(node);

    if (IsTower(node))
    {
        //spawn big flag + aura on top of tower
        SpawnBGObject(BG_AV_OBJECT_TAURA_N_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_ONE_DAY);
        SpawnBGObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_IMMEDIATELY);

        SpawnBGObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_ONE_DAY);
        SpawnBGObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_IMMEDIATELY);

    }
    else if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall eyecandy
    {
        for (uint32 i = 0; i < 4; ++i)
        {
            SpawnBGObject((team == ALLIANCE ? BG_AV_OBJECT_SNOW_EYECANDY_PH : BG_AV_OBJECT_SNOW_EYECANDY_PA) + i, RESPAWN_ONE_DAY);
            SpawnBGObject((team == ALLIANCE ? BG_AV_OBJECT_SNOW_EYECANDY_A : BG_AV_OBJECT_SNOW_EYECANDY_H) + i, RESPAWN_IMMEDIATELY);
        }
    }

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
            herald->AI()->Talk(team == ALLIANCE ? nodeInfo->TextIds.AllianceCapture : nodeInfo->TextIds.HordeCapture);

    // update the statistic for the defending player
    UpdatePlayerScore(player, IsTower(node) ? SCORE_TOWERS_DEFENDED : SCORE_GRAVEYARDS_DEFENDED, 1);
}

void BattlegroundAV::EventPlayerAssaultsPoint(Player* player, uint32 object)
{
    ASSERT(GetStatus() == STATUS_IN_PROGRESS);

    BG_AV_Nodes node = GetNodeThroughObject(object);
    uint32 owner = m_Nodes[node].Owner; //maybe name it prevowner
    uint32 team = player->GetTeam();
    TC_LOG_DEBUG("bg.battleground", "bg_av: player assaults point object %i node %i", object, node);
    if (owner == team || team == m_Nodes[node].TotalOwner)
        return; //surely a gm used this object

    if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall is a bit special in capping + it gets eyecandy stuff
    {
        if (object == BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE) //initial capping
        {
            if (!(owner == AV_NEUTRAL_TEAM && m_Nodes[node].TotalOwner == AV_NEUTRAL_TEAM))
                return;

            // despawn initial neutral aura
            SpawnBGObject(BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_N, RESPAWN_ONE_DAY);

            // spawn capping team banner + aura
            SpawnBGObject(team == ALLIANCE ? BG_AV_OBJECT_FLAG_C_A_SNOWFALL_GRAVE : BG_AV_OBJECT_FLAG_C_H_SNOWFALL_GRAVE, RESPAWN_IMMEDIATELY);
            SpawnBGObject(team == ALLIANCE ? BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_A : BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_H, RESPAWN_IMMEDIATELY);
        }
        else if (m_Nodes[node].TotalOwner == AV_NEUTRAL_TEAM) // recapping, when no team owns this node really
        {
            if (!(m_Nodes[node].State != POINT_CONTROLED))
                return;

            // swap banner
            SpawnBGObject(BG_AV_OBJECT_FLAG_C_A_SNOWFALL_GRAVE, team == ALLIANCE ? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            SpawnBGObject(BG_AV_OBJECT_FLAG_C_H_SNOWFALL_GRAVE, team == ALLIANCE ? RESPAWN_ONE_DAY : RESPAWN_IMMEDIATELY);

            // swap aura
            SpawnBGObject(BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_A, team == ALLIANCE ? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            SpawnBGObject(BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_H, team == ALLIANCE ? RESPAWN_ONE_DAY : RESPAWN_IMMEDIATELY);
        }

        // eyecandy
        uint32 despawnId;
        switch (team)
        {
            case ALLIANCE:
                despawnId = m_Nodes[BG_AV_NODES_SNOWFALL_GRAVE].State == POINT_ASSAULTED ? BG_AV_OBJECT_SNOW_EYECANDY_PH : BG_AV_OBJECT_SNOW_EYECANDY_H;
                break;
            case HORDE:
                despawnId = m_Nodes[BG_AV_NODES_SNOWFALL_GRAVE].State == POINT_ASSAULTED ? BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_A;
                break;
            default:
                ABORT();
                break;
        }

        uint32 spawnId = team == ALLIANCE ? BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_PH;
        for (uint32 i = 0; i < 4; ++i)
        {
            SpawnBGObject(despawnId + i, RESPAWN_ONE_DAY);
            SpawnBGObject(spawnId + i, RESPAWN_IMMEDIATELY);
        }
    }

    //if snowfall gots capped it can be handled like all other graveyards
    if (m_Nodes[node].TotalOwner != AV_NEUTRAL_TEAM)
    {
        ASSERT(owner != AV_NEUTRAL_TEAM);
        if (team == ALLIANCE)
            SpawnBGObject(object + BG_AV_OBJECT_FLAG_C_A_AID_STATION - BG_AV_OBJECT_FLAG_H_AID_STATION, RESPAWN_IMMEDIATELY); // banner is horde, spawn contested alliance flag
        else
            SpawnBGObject(object + BG_AV_OBJECT_FLAG_C_H_AID_STATION - BG_AV_OBJECT_FLAG_A_AID_STATION, RESPAWN_IMMEDIATELY); // banner is alliance, spawn contested horde flag

        // spawning/despawning of big flag + aura
        if (IsTower(node))
        {
            //spawn big flag + aura on top of tower
            SpawnBGObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_ONE_DAY);
            SpawnBGObject(BG_AV_OBJECT_TAURA_N_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_IMMEDIATELY);

            SpawnBGObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_ONE_DAY);
            SpawnBGObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH + node - BG_AV_NODES_DUNBALDAR_SOUTH, RESPAWN_IMMEDIATELY);
        }
        else
        {
            // spawning / despawning of aura
            // how much we have to offset in case team == horde
            uint32 const hordeDelta = BG_AV_OBJECT_AURA_A_FROSTWOLF_HUT - BG_AV_OBJECT_AURA_A_AID_STATION + 1;

            // team aura despawn
            SpawnBGObject(BG_AV_OBJECT_AURA_A_AID_STATION + GetTeamIndexByTeamId(owner) * hordeDelta + node, RESPAWN_ONE_DAY);

            // neutral aura spawn
            SpawnBGObject(BG_AV_OBJECT_AURA_N_AID_STATION_CONT_A + BG_TEAMS_COUNT * node + GetTeamIndexByTeamId(team), RESPAWN_IMMEDIATELY);

            // relocate ghosts
            if (Creature* spiritGuide = GetBGCreature(node))
                RelocateDeadPlayers(spiritGuide->GetGUID());
        }

        DePopulateNode(node);
    }

    // delete old banner
    SpawnBGObject(object, RESPAWN_ONE_DAY);
    AssaultNode(node, team);
    UpdateNodeWorldState(node);

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herald = GetBGCreature(AV_CPLACE_HERALD))
            herald->AI()->Talk(team == ALLIANCE ? nodeInfo->TextIds.AllianceAttack : nodeInfo->TextIds.HordeAttack);

    // update the statistic for the assaulting player
    UpdatePlayerScore(player, (IsTower(node)) ? SCORE_TOWERS_ASSAULTED : SCORE_GRAVEYARDS_ASSAULTED, 1);
}

void BattlegroundAV::FillInitialWorldStates(WorldPacket& data)
{
    for (uint32 i = BG_AV_NODES_AID_STATION; i < BG_AV_NODES_MAX; ++i)
    {
        uint16 owner = m_Nodes[i].Owner;
        BG_AV_States state = m_Nodes[i].State;

        data << uint32(BG_AV_NodeInfo[i].WorldStateIds.AllianceAssault) << uint32(owner == ALLIANCE && state == POINT_ASSAULTED);
        data << uint32(BG_AV_NodeInfo[i].WorldStateIds.AllianceControl) << uint32(owner == ALLIANCE && state >= POINT_DESTROYED);
        data << uint32(BG_AV_NodeInfo[i].WorldStateIds.HordeAssault) << uint32(owner == HORDE && state == POINT_ASSAULTED);
        data << uint32(BG_AV_NodeInfo[i].WorldStateIds.HordeControl) << uint32(owner == HORDE && state >= POINT_DESTROYED);
    }

    data << uint32(AV_SNOWFALL_N) << uint32(m_Nodes[BG_AV_NODES_SNOWFALL_GRAVE].Owner == AV_NEUTRAL_TEAM);

    data << uint32(AV_Alliance_Score) << uint32(m_Team_Scores[0]);
    data << uint32(AV_Horde_Score) << uint32(m_Team_Scores[1]);
    if (GetStatus() == STATUS_IN_PROGRESS) { //only if game started the teamscores are displayed
        data << uint32(AV_SHOW_A_SCORE) << uint32(1);
        data << uint32(AV_SHOW_H_SCORE) << uint32(1);
    }
    else
    {
        data << uint32(AV_SHOW_A_SCORE) << uint32(0);
        data << uint32(AV_SHOW_H_SCORE) << uint32(0);
    }

    SendMineWorldStates(AV_NORTH_MINE);
    SendMineWorldStates(AV_SOUTH_MINE);
}

void BattlegroundAV::UpdateNodeWorldState(BG_AV_Nodes node)
{
    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
    {
        uint16 owner = m_Nodes[node].Owner;
        BG_AV_States state = m_Nodes[node].State;

        UpdateWorldState(nodeInfo->WorldStateIds.AllianceAssault, owner == ALLIANCE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.AllianceControl, owner == ALLIANCE && state >= POINT_DESTROYED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeAssault, owner == HORDE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeControl, owner == HORDE && state >= POINT_DESTROYED);
    }

    if (node == BG_AV_NODES_SNOWFALL_GRAVE)
        UpdateWorldState(AV_SNOWFALL_N, m_Nodes[node].Owner == AV_NEUTRAL_TEAM);
}

void BattlegroundAV::SendMineWorldStates(uint32 mine)
{
    ASSERT(mine == AV_NORTH_MINE || mine == AV_SOUTH_MINE);
    // currently i'm sure, that this works (:
    //    ASSERT(m_Mine_PrevOwner[mine] == ALLIANCE || m_Mine_PrevOwner[mine] == HORDE || m_Mine_PrevOwner[mine] == AV_NEUTRAL_TEAM);
    //    ASSERT(m_Mine_Owner[mine] == ALLIANCE || m_Mine_Owner[mine] == HORDE || m_Mine_Owner[mine] == AV_NEUTRAL_TEAM);

    uint8 owner, prevowner, mine2; //those variables are needed to access the right worldstate in the BG_AV_MineWorldStates array
    mine2 = (mine == AV_NORTH_MINE) ? 0 : 1;
    if (m_Mine_PrevOwner[mine] == ALLIANCE)
        prevowner = 0;
    else if (m_Mine_PrevOwner[mine] == HORDE)
        prevowner = 2;
    else
        prevowner = 1;
    if (m_Mine_Owner[mine] == ALLIANCE)
        owner = 0;
    else if (m_Mine_Owner[mine] == HORDE)
        owner = 2;
    else
        owner = 1;

    UpdateWorldState(BG_AV_MineWorldStates[mine2][owner], 1);
    if (prevowner != owner)
        UpdateWorldState(BG_AV_MineWorldStates[mine2][prevowner], 0);
}

WorldSafeLocsEntry const* BattlegroundAV::GetClosestGraveYard(Player* player)
{
    WorldSafeLocsEntry const* pGraveyard = nullptr;
    WorldSafeLocsEntry const* entry = nullptr;
    float dist = 0;
    float minDist = 0;
    float x, y;

    player->GetPosition(x, y);

    pGraveyard = sWorldSafeLocsStore.LookupEntry(BG_AV_GraveyardIds[AV_CPLACE_SPIRIT_MAIN_ALLIANCE + GetTeamIndexByTeamId(player->GetTeam())]);
    minDist = (pGraveyard->x - x) * (pGraveyard->x - x) + (pGraveyard->y - y) * (pGraveyard->y - y);

    for (uint32 i = BG_AV_NODES_AID_STATION; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i)
    {
        if (m_Nodes[i].Owner == player->GetTeam() && m_Nodes[i].State == POINT_CONTROLED)
        {
            entry = sWorldSafeLocsStore.LookupEntry(BG_AV_GraveyardIds[i]);
            if (entry)
            {
                dist = (entry->x - x) * (entry->x - x) + (entry->y - y) * (entry->y - y);
                if (dist < minDist)
                {
                    minDist = dist;
                    pGraveyard = entry;
                }
            }
        }
    }

    return pGraveyard;
}

bool BattlegroundAV::SetupBattleground()
{
    // Create starting objects
    for (uint32 i = 0; i < BG_AV_OBJECT_MAX; ++i)
    {
        BattlegroundGOSpawnPoint const& object = BG_AV_GameObjects[i];
        if (!AddObject(i, object.Entry, object.Pos, object.Rot, object.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundAV: Failed to spawn GameObject (Entry: %u). Battleground not created!", object.Entry);
            return false;
        }
    }

    TC_LOG_DEBUG("bg.battleground", "Alterac Valley: entering state STATUS_WAIT_JOIN ...");
    // Initial Nodes
    for (uint32 i = 0; i < BG_AV_OBJECT_MAX; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);

    for (uint32 i = BG_AV_OBJECT_FLAG_A_AID_STATION; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE; ++i)
    {
        SpawnBGObject(BG_AV_OBJECT_AURA_A_AID_STATION + GetNodeThroughObject(i), RESPAWN_IMMEDIATELY);
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
    }

    for (uint32 i = BG_AV_OBJECT_FLAG_A_DUNBALDAR_SOUTH; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);

    for (uint32 i = BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE; i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER; ++i)
    {
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
        if (i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT)
            SpawnBGObject(BG_AV_OBJECT_AURA_H_AID_STATION + GetNodeThroughObject(i), RESPAWN_IMMEDIATELY);
    }

    for (uint32 i = BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH; i <= BG_AV_OBJECT_TFLAG_A_STONEHEART_BUNKER; ++i)
    {
        SpawnBGObject(i, RESPAWN_IMMEDIATELY); //flag
        SpawnBGObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH + (i - BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH), RESPAWN_IMMEDIATELY); //aura
    }

    for (uint32 i = BG_AV_OBJECT_TFLAG_H_ICEBLOOD_TOWER; i <= BG_AV_OBJECT_TFLAG_H_FROSTWOLF_WTOWER; ++i)
    {
        SpawnBGObject(i, RESPAWN_IMMEDIATELY); //flag
        SpawnBGObject(BG_AV_OBJECT_TAURA_H_ICEBLOOD_TOWER + (i - BG_AV_OBJECT_TFLAG_H_ICEBLOOD_TOWER), RESPAWN_IMMEDIATELY); //aura
    }

    //snowfall and the doors
    SpawnBGObject(BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_N, RESPAWN_IMMEDIATELY);

    SpawnBGObject(BG_AV_OBJECT_DOOR_A, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_AV_OBJECT_DOOR_H, RESPAWN_IMMEDIATELY);
    
    //creatures
    TC_LOG_DEBUG("bg.battleground", "BG_AV start poputlating nodes");
    for (BG_AV_Nodes n = BG_AV_NODES_AID_STATION; n < BG_AV_NODES_MAX; ++n)
    {
        if (m_Nodes[n].Owner)
            PopulateNode(n);
    }

    //all creatures which don't get despawned through the script are static
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning static creatures");
    for (uint32 i = 0; i < AV_STATICCPLACE_MAX; ++i)
        AddAVCreature(0, i + AV_CPLACE_MAX);

    //mainspiritguides:
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning spiritguides creatures");
    AddSpiritGuide(AV_CPLACE_SPIRIT_MAIN_ALLIANCE, BG_AV_CreaturePos[AV_CPLACE_SPIRIT_MAIN_ALLIANCE], TEAM_ALLIANCE);
    AddSpiritGuide(AV_CPLACE_SPIRIT_MAIN_HORDE, BG_AV_CreaturePos[AV_CPLACE_SPIRIT_MAIN_HORDE], TEAM_HORDE);

    //spawn the marshals (those who get deleted, if a tower gets destroyed)
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning marshal creatures");
    for (uint32 i = AV_NPC_A_MARSHAL_SOUTH; i <= AV_NPC_H_MARSHAL_WTOWER; ++i)
        AddAVCreature(i, AV_CPLACE_A_MARSHAL_SOUTH + (i - AV_NPC_A_MARSHAL_SOUTH));

    AddAVCreature(AV_NPC_HERALD, AV_CPLACE_HERALD);
    return true;
}

void BattlegroundAV::AssaultNode(BG_AV_Nodes node, uint16 team)
{
    if (m_Nodes[node].TotalOwner == team)
    {
        TC_LOG_FATAL("bg.battleground", "Assaulting team is TotalOwner of node");
        ABORT();
    }
    if (m_Nodes[node].Owner == team)
    {
        TC_LOG_FATAL("bg.battleground", "Assaulting team is owner of node");
        ABORT();
    }
    if (m_Nodes[node].State == POINT_DESTROYED)
    {
        TC_LOG_FATAL("bg.battleground", "Destroyed node is being assaulted");
        ABORT();
    }
    if (m_Nodes[node].State == POINT_ASSAULTED && m_Nodes[node].TotalOwner) //only assault an assaulted node if no totalowner exists
    {
        TC_LOG_FATAL("bg.battleground", "Assault on an not assaulted node with total owner");
        ABORT();
    }

    // the timer gets another time, if the previous owner was 0 == Neutral
    // no longer true since Patch 2.3.0:
    /// The time required for the first capture of Snowfall graveyard has been reduced from five minutes to four.
    m_Nodes[node].Timer      = BG_AV_CAPTIME;
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_ASSAULTED;
}

void BattlegroundAV::DestroyNode(BG_AV_Nodes node)
{
    ASSERT(m_Nodes[node].State == POINT_ASSAULTED);

    m_Nodes[node].TotalOwner = m_Nodes[node].Owner;
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = (m_Nodes[node].Tower) ? POINT_DESTROYED : POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
}

void BattlegroundAV::InitNode(BG_AV_Nodes node, uint16 team, bool tower)
{
    m_Nodes[node].TotalOwner = team;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevOwner  = 0;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
    m_Nodes[node].Tower      = tower;
}

void BattlegroundAV::DefendNode(BG_AV_Nodes node, uint16 team)
{
    ASSERT(m_Nodes[node].TotalOwner == team);
    ASSERT(m_Nodes[node].Owner != team);
    ASSERT(m_Nodes[node].State != POINT_CONTROLED && m_Nodes[node].State != POINT_DESTROYED);
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
}

void BattlegroundAV::ResetBGSubclass()
{
    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i) //forloop for both teams (it just make 0 == alliance and 1 == horde also for both mines 0=north 1=south
    {
        for (uint8 j = 0; j < 9; ++j)
            m_Team_QuestStatus[i][j] = 0;

        m_Team_Scores[i] = BG_AV_SCORE_INITIAL_POINTS;
        m_IsInformedNearVictory[i] = false;
        m_CaptainAlive[i] = true;
        m_CaptainBuffTimer[i] = urand(2, 6) * MINUTE * IN_MILLISECONDS; // as far as i could see, the buff is random so i make 2 minutes (that's the duration of the buff itself) + 0-4 minutes @todo get the right times
        m_Mine_Owner[i] = AV_NEUTRAL_TEAM;
        m_Mine_PrevOwner[i] = m_Mine_Owner[i];
    }

    for (BG_AV_Nodes i = BG_AV_NODES_AID_STATION; i <= BG_AV_NODES_STONEHEART_GRAVE; ++i) //alliance graves
        InitNode(i, ALLIANCE, false);

    for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) //alliance towers
        InitNode(i, ALLIANCE, true);

    for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_GRAVE; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i) //horde graves
        InitNode(i, HORDE, false);

    for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) //horde towers
        InitNode(i, HORDE, true);

    InitNode(BG_AV_NODES_SNOWFALL_GRAVE, AV_NEUTRAL_TEAM, false); //give snowfall neutral owner

    m_Mine_Timer = AV_MINE_TICK_TIMER;
    for (uint16 i = 0; i < AV_CPLACE_MAX + AV_STATICCPLACE_MAX; ++i)
        DelCreature(i);
}

bool BattlegroundAV::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target, uint32 miscValue)
{
    uint32 team = source->GetTeam();
    switch (criteriaId)
    {
        case BG_CRITERIA_CHECK_EVERYTHING_COUNTS:
            for (uint8 mine = 0; mine < 2; ++mine)
                if (m_Mine_Owner[mine] != team)
                    return false;

            return true;
        case BG_CRITERIA_CHECK_AV_PERFECTION:
        {
            if (team == ALLIANCE)
            {
                for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) // alliance towers controlled
                {
                    if (m_Nodes[i].State == POINT_CONTROLED)
                    {
                        if (m_Nodes[i].Owner != ALLIANCE)
                            return false;
                    }
                    else
                        return false;
                }

                for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) // horde towers destroyed
                    if (m_Nodes[i].State != POINT_DESTROYED)
                        return false;

                if (!m_CaptainAlive[0])
                    return false;

                return true;
            }
            else if (team == HORDE)
            {
                for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) // horde towers controlled
                {
                    if (m_Nodes[i].State == POINT_CONTROLED)
                    {
                        if (m_Nodes[i].Owner != HORDE)
                            return false;
                    }
                    else
                        return false;
                }

                for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) // alliance towers destroyed
                    if (m_Nodes[i].State != POINT_DESTROYED)
                        return false;

                if (!m_CaptainAlive[1])
                    return false;

                return true;
            }
        }
    }

    return Battleground::CheckAchievementCriteriaMeet(criteriaId, source, target, miscValue);
}

uint32 BattlegroundAV::GetPrematureWinner()
{
    uint32 allianceScore = m_Team_Scores[GetTeamIndexByTeamId(ALLIANCE)];
    uint32 hordeScore = m_Team_Scores[GetTeamIndexByTeamId(HORDE)];

    if (allianceScore > hordeScore)
        return ALLIANCE;
    else if (hordeScore > allianceScore)
        return HORDE;

    return Battleground::GetPrematureWinner();
}

StaticNodeInfo const* BattlegroundAV::GetStaticNodeInfo(uint8 node)
{
    if (node >= BG_AV_NODES_MAX)
        return nullptr;

    return &BG_AV_NodeInfo[node];
}
