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

#ifndef SETHEKK_HALLS_H_
#define SETHEKK_HALLS_H_

#include "CreatureAIImpl.h"

#define SHScriptName "instance_sethekk_halls"
#define DataHeader "SH"

uint32 const EncounterCount             = 3;

enum SHDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_DARKWEAVER_SYTH                = 0,
    DATA_TALON_KING_IKISS               = 1,
    DATA_ANZU                           = 2,

    // Additional Data
    DATA_TALON_KING_COFFER              = 3
};

enum SHCreatureIds
{
    NPC_ANZU                            = 23035,
    NPC_BROOD_OF_ANZU                   = 23132
};

enum SHGameObjectIds
{
    GO_IKISS_DOOR                       = 177203,
    GO_TALON_KING_COFFER                = 187372
};

template <class AI, class T>
inline AI* GetSethekkHallsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SHScriptName);
}

#endif // SETHEKK_HALLS_H_
