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

#ifndef DEF_THE_EYE_H
#define DEF_THE_EYE_H

#include "CreatureAIImpl.h"

#define TheEyeScriptName "instance_the_eye"
#define DataHeader "TE"

uint32 const EncounterCount = 4;

enum TEDataTypes
{
    // Encounter States
    DATA_ALAR                           = 0,
    DATA_VOID_REAVER                    = 1,
    DATA_SOLARIAN                       = 2,
    DATA_KAELTHAS                       = 3,

    // Additional Data
    DATA_CAPERNIAN                      = 4,
    DATA_SANGUINAR                      = 5,
    DATA_TELONICUS                      = 6,
    DATA_THALADRED                      = 7,

    DATA_KAEL_STATUE_LEFT               = 8,
    DATA_KAEL_STATUE_RIGHT              = 9,
    DATA_TEMPEST_BRIDGE_WINDOW          = 10
};

enum TECreatureIds
{
    NPC_ALAR                            = 19514,
    NPC_VOID_REAVER                     = 19516,
    NPC_SOLARIAN                        = 18805,
    NPC_KAELTHAS                        = 19622,
    NPC_SANGUINAR                       = 20060,
    NPC_CAPERNIAN                       = 20062,
    NPC_TELONICUS                       = 20063,
    NPC_THALADRED                       = 20064
};

enum TEGameObjectIds
{
    GO_TEMPEST_BRIDDGE_WINDOW           = 184069,
    GO_KAEL_STATUE_RIGHT                = 184596,
    GO_KAEL_STATUE_LEFT                 = 184597,
    GO_ARCANE_DOOR_LEFT                 = 184324,
    GO_ARCANE_DOOR_RIGHT                = 184325
};

template <class AI, class T>
inline AI* GetTheEyeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TheEyeScriptName);
}

#define RegisterTheEyeCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTheEyeAI)

#endif
