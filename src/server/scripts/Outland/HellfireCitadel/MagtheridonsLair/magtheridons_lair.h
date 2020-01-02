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

#define MLScriptName "instance_magtheridons_lair"
#include "CreatureAIImpl.h"

#define DataHeader "ML"

uint32 const EncounterCount = 1;

enum DataTypes
{
    DATA_MAGTHERIDON          = 0,
    DATA_WORLD_TRIGGER        = 1,
    DATA_MAGTHERIDON_HALL     = 2,
    DATA_MAGTHERIDON_COLUMN_0 = 3,
    DATA_MAGTHERIDON_COLUMN_1 = 4,
    DATA_MAGTHERIDON_COLUMN_2 = 5,
    DATA_MAGTHERIDON_COLUMN_3 = 6,
    DATA_MAGTHERIDON_COLUMN_4 = 7,
    DATA_MAGTHERIDON_COLUMN_5 = 8,
    DATA_MANTICRON_CUBE       = 9,
    DATA_COLLAPSE             = 10,
    DATA_COLLAPSE_2           = 11,
    DATA_CALL_WARDERS         = 12
};

enum Actions
{
    ACTION_ENABLE             = 1,
    ACTION_DISABLE            = 2
};

enum CreatureIds
{
    NPC_MAGTHERIDON          = 17257,
    NPC_ABYSSAL              = 17454,
    NPC_HELLFIRE_CHANNELLER  = 17256,
    NPC_TARGET_TRIGGER       = 17474,
    NPC_WORLD_TRIGGER        = 21252,
    NPC_HELFIRE_RAID_TRIGGER = 17376,
    NPC_OLDWORLD_TRIGGER     = 15384,
    NPC_MAGTHERIDON_ROOM     = 17516,
    NPC_HELLFIRE_WARDER      = 18829
};

enum GameObjectIds
{
    GO_MAGTHERIDON_DOOR      = 183847,
    GO_MANTICRON_CUBE        = 181713,
    GO_MAGTHERIDON_HALL      = 184653,
    GO_MAGTHERIDON_COLUMN_0  = 184638,
    GO_MAGTHERIDON_COLUMN_1  = 184639,
    GO_MAGTHERIDON_COLUMN_2  = 184635,
    GO_MAGTHERIDON_COLUMN_3  = 184634,
    GO_MAGTHERIDON_COLUMN_4  = 184636,
    GO_MAGTHERIDON_COLUMN_5  = 184637
};

template<typename AI>
inline AI* GetMagtheridonsLairAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, MLScriptName);
}

#endif
