/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_ZF_H
#define DEF_ZF_H

#include "CreatureAIImpl.h"

#define ZFScriptName "instance_zulfarrak"
#define DataHeader "ZF"

enum ZFBossIds
{
    BOSS_HYDROMANCER_VELRATHA   = 0,
    BOSS_GAHZ_RILLA             = 1,
    BOSS_ANTU_SUL               = 2,
    BOSS_THEKA_THE_MARTYR       = 3,
    BOSS_WITCH_DOCTOR_ZUM_RAH   = 4,
    BOSS_NEKRUM_GUTCHEWER       = 5,
    BOSS_SHADOWPRIEST_SEZZ_ZIZ  = 6,
    BOSS_CHIEF_UKORZ_SANDSCALP  = 7,

    MAX_ENCOUNTER
};

enum ZFEntries
{
    ENTRY_SANDSCALP     = 7267,
    ENTRY_ZUM_RAH       = 7271,
    ENTRY_THEKA         = 7272,
    ENTRY_GAHZRILLA     = 7273,
    ENTRY_SEZZZIZ       = 7275,
    ENTRY_BLY           = 7604,
    ENTRY_RAVEN         = 7605,
    ENTRY_ORO           = 7606,
    ENTRY_WEEGLI        = 7607,
    ENTRY_MURTA         = 7608,
    ENTRY_VELRTHA       = 7795,
    ENTRY_NEKRUM        = 7796,
    ENTRY_ANTUSUL       = 8127,

    GO_END_DOOR         = 146084,

    EVENT_PYRAMID       = 1,
    EVENT_GAHZRILLA
};

enum ZFPyramidPhases
{
    PYRAMID_NOT_STARTED, //default
    PYRAMID_CAGES_OPEN, //happens in GO hello for cages
    PYRAMID_ARRIVED_AT_STAIR, //happens in Weegli's movementinform
    PYRAMID_WAVE_1,
    PYRAMID_PRE_WAVE_2,
    PYRAMID_WAVE_2,
    PYRAMID_PRE_WAVE_3,
    PYRAMID_WAVE_3,
    PYRAMID_KILLED_ALL_TROLLS,
};

template <class AI, class T>
inline AI* GetZulFarrakAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ZFScriptName);
}

#endif
