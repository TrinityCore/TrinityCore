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

#ifndef DEF_THE_STONEVAULT_H_
#define DEF_THE_STONEVAULT_H_

#include "CreatureAIImpl.h"

#define TSVScriptName "instance_the_stonevault"
#define DataHeader "TheStonevault"

constexpr uint32 EncounterCount = 4;

enum TheStonevaultDataTypes
{
    // Encounters
    DATA_EDNA                = 0,
    DATA_SKARMORAK           = 1,
    DATA_MASTER_MACHINISTS   = 2,
    DATA_VOID_SPEAKER_EIRICH = 3,

    // Additional Data
    DATA_SPEAKER_DORLITA,
    DATA_SPEAKER_BROKK,
    DATA_EDNA_INTRO_STATE
};

enum TheStonevaultCreatureIds
{
    // Bosses
    BOSS_EDNA                = 210108,
    BOSS_SKARMORAX           = 210156,
    BOSS_SPEAKER_DORLITA     = 213216,
    BOSS_SPEAKER_BROKK       = 213217,
    BOSS_VOID_SPEAKER_EIRICH = 213119
};

enum TheStonevaultGameObjectIds
{
    GO_FOUNDRY_DOOR_ENTRANCE            = 440236,
    GO_FOUNDRY_DOOR_TOWARDS_SKARMORAK   = 440235,
    GO_FOUNDRY_DOOR_TOWARDS_MACHINISTS  = 440239
};

enum TheStonevaultSharedActions
{
    ACTION_START_EDNA_INTRO = 0
};

template <class AI, class T>
inline AI* GetTheStonevaultAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TSVScriptName);
}

#define RegisterTheStonevaultCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTheStonevaultAI)

#endif
