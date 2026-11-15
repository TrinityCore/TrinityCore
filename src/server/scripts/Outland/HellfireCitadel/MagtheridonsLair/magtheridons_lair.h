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

#ifndef DEF_MAGTHERIDONS_LAIR_H
#define DEF_MAGTHERIDONS_LAIR_H

#include "CreatureAIImpl.h"

#define MLScriptName "instance_magtheridons_lair"
#define DataHeader "ML"

uint32 constexpr EncounterCount = 1;

enum MLDataTypes
{
    DATA_MAGTHERIDON              = 0,

    DATA_WORLD_TRIGGER,
    DATA_MAGTHERIDON_HALL,
    DATA_MAGTHERIDON_COLUMN_0,
    DATA_MAGTHERIDON_COLUMN_1,
    DATA_MAGTHERIDON_COLUMN_2,
    DATA_MAGTHERIDON_COLUMN_3,
    DATA_MAGTHERIDON_COLUMN_4,
    DATA_MAGTHERIDON_COLUMN_5,
    DATA_MANTICRON_CUBE,
    DATA_COLLAPSE_1,
    DATA_COLLAPSE_2,
    DATA_CALL_WARDERS
};

enum MLActions
{
    ACTION_ENABLE                 = 1,
    ACTION_DISABLE                = 2
};

enum MLCreatureIds
{
    NPC_MAGTHERIDON               = 17257,
    NPC_HELLFIRE_CHANNELLER       = 17256,
    NPC_WORLD_TRIGGER             = 21252,
    NPC_HELLFIRE_WARDER           = 18829
};

enum MLGameObjectIds
{
    GO_MAGTHERIDON_DOOR           = 183847,
    GO_MANTICRON_CUBE             = 181713,
    GO_MAGTHERIDON_HALL           = 184653,
    GO_MAGTHERIDON_COLUMN_0       = 184638,
    GO_MAGTHERIDON_COLUMN_1       = 184639,
    GO_MAGTHERIDON_COLUMN_2       = 184635,
    GO_MAGTHERIDON_COLUMN_3       = 184634,
    GO_MAGTHERIDON_COLUMN_4       = 184636,
    GO_MAGTHERIDON_COLUMN_5       = 184637
};

template <class AI, class T>
inline AI* GetMagtheridonsLairAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MLScriptName);
}

#define RegisterMagtheridonsLairCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMagtheridonsLairAI)

#endif
