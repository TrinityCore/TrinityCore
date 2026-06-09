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

#ifndef DEF_THEBLACKMORASS_H
#define DEF_THEBLACKMORASS_H

#include "CreatureAIImpl.h"

#define TBMScriptName "instance_the_black_morass"
#define DataHeader "TBM"

uint32 constexpr EncounterCount         = 3;

enum TBMDataTypes
{
    DATA_DEJA                           = 0,
    DATA_TEMPORUS                       = 1,
    DATA_AEONUS                         = 2,

    DATA_MEDIVH,
    DATA_SAAT,
    DATA_EVENT,
    DATA_RIFT,
    DATA_RIFT_COUNT,
    DATA_SHIELD_PCT
};

enum TBMWorldStateIds
{
    WORLD_STATE_BM                      = 2541,
    WORLD_STATE_BM_SHIELD               = 2540,
    WORLD_STATE_BM_RIFT                 = 2784
};

enum TBMSpellIds
{
    SPELL_THE_BLACK_MORASS_COMPLETE     = 37215,
    SPELL_THE_MASTERS_TOUCH_COMPLETE    = 39539,

    SPELL_SUMMON_TIME_RIFT_EFFECT_1     = 31354,
    SPELL_SUMMON_TIME_RIFT_EFFECT_2     = 31355,
    SPELL_SUMMON_TIME_RIFT_EFFECT_3     = 31356,
    SPELL_SUMMON_TIME_RIFT_EFFECT_4     = 31357
};

enum TBMCreatureIds
{
    NPC_MEDIVH                          = 15608,
    NPC_SAAT                            = 20201,
    NPC_TIME_KEEPER                     = 17918,
    NPC_TIME_RIFT                       = 17838,
    NPC_RIFT_LORD                       = 17839,
    NPC_RIFT_LORD_ALT                   = 21140,
    NPC_RIFT_KEEPER                     = 21104,
    NPC_RIFT_KEEPER_ALT                 = 21148,
    NPC_CRONO_LORD_DEJA                 = 17879,
    NPC_TEMPORUS                        = 17880,
    NPC_AEONUS                          = 17881,
    NPC_INFINITE_CHRONO_LORD            = 21697,
    NPC_INFINITE_TIMEREAVER             = 21698,
    NPC_INFINITE_WHELP                  = 21818,
    NPC_INFINITE_ASSASIN                = 17835,
    NPC_INFINITE_ASSASIN_ALT            = 21137,
    NPC_INFINITE_CRONOMANCER            = 17892,
    NPC_INFINITE_CRONOMANCER_ALT        = 21136,
    NPC_INFINITE_EXECUTIONER            = 18994,
    NPC_INFINITE_EXECUTIONER_ALT        = 21138,
    NPC_INFINITE_VANQUISHER             = 18995,
    NPC_INFINITE_VANQUISHER_ALT         = 21139
};

enum TBMActionIds
{
    ACTION_SHIELD_75                    = 1560800,
    ACTION_SHIELD_50                    = 1560801,
    ACTION_SHIELD_25                    = 1560802,
    ACTION_SHIELD_0                     = 1560803,
    ACTION_EPILOGUE                     = 1560804
};

enum TBMEventIds
{
    EVENT_SUMMON_PORTAL                 = 1,
    EVENT_SUMMON_TIME_RIFT_1            = 11137,
    EVENT_SUMMON_TIME_RIFT_2            = 11138,
    EVENT_SUMMON_TIME_RIFT_3            = 11139,
    EVENT_SUMMON_TIME_RIFT_4            = 11140
};

static const Position PortalPosition1 = { -2030.832f, 7024.944f, 23.07182f, 3.141593f };
static const Position PortalPosition2 = { -1961.734f, 7029.528f, 21.8114f,  2.129302f };
static const Position PortalPosition3 = { -1887.695f, 7106.557f, 22.0495f,  4.956735f };
static const Position PortalPosition4 = { -1930.911f, 7183.597f, 23.00764f, 3.595378f };

template <class AI, class T>
inline AI* GetBlackMorassAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TBMScriptName);
}

#define RegisterBlackMorassCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackMorassAI)

#endif
