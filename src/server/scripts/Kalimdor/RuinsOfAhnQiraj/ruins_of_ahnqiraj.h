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

#ifndef DEF_RUINS_OF_AHNQIRAJ_H
#define DEF_RUINS_OF_AHNQIRAJ_H

#include "CreatureAIImpl.h"

#define AQ20ScriptName "instance_ruins_of_ahnqiraj"
#define DataHeader "AQR"

uint32 constexpr EncounterCount = 6;

enum AQRDataTypes
{
    DATA_KURINNAXX              = 0,
    DATA_RAJAXX                 = 1,
    DATA_MOAM                   = 2,
    DATA_BURU                   = 3,
    DATA_AYAMISS                = 4,
    DATA_OSSIRIAN               = 5,

    DATA_ANDOROV_EVENT_STATE,
    DATA_ANDOROV,
    DATA_PARALYZED
};

enum AQRCreatures
{
    NPC_KURINAXX                = 15348,
    NPC_RAJAXX                  = 15341,
    NPC_MOAM                    = 15340,
    NPC_BURU                    = 15370,
    NPC_AYAMISS                 = 15369,
    NPC_OSSIRIAN                = 15339,

    NPC_ANDOROV                 = 15471
};

enum AQRGameObjectIds
{
    GO_OSSIRIAN_CRYSTAL         = 180619
};

enum AQRSpawnGroups
{
    SPAWN_GROUP_ANDOROV         = 333
};

enum AQRActionIds
{
    ACTION_WAVE_STARTS_3        = 0,
    ACTION_WAVE_STARTS_4        = 1,
    ACTION_WAVE_STARTS_5        = 2,
    ACTION_WAVE_STARTS_6        = 3,
    ACTION_WAVE_STARTS_7        = 4,
    ACTION_RAJAXX_ENTER         = 5,
    ACTION_KURINNAXX_DEFEATED   = 6,
    ACTION_RAJAXX_DEFEATED      = 7
};

template <class AI, class T>
inline AI* GetAQ20AI(T* obj)
{
    return GetInstanceAI<AI>(obj, AQ20ScriptName);
}

#define RegisterAQ20CreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAQ20AI)

#endif
