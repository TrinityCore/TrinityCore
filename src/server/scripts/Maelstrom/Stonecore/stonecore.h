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

#ifndef DEF_STONECORE_H
#define DEF_STONECORE_H

#include "CreatureAIImpl.h"
#include "Position.h"

#define SCScriptName "instance_stonecore"
#define DataHeader "SC"

enum SCDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_CORBORUS,
    DATA_SLABHIDE,
    DATA_OZRUK,
    DATA_HIGH_PRIESTESS_AZIL,

    // Additional Data
    DATA_MILLHOUSE_MANASTORM,
    DATA_MILLHOUSE_EVENT_FACE,
    DATA_HANDLE_CORBORUS_ROCKDOOR,
    DATA_MILLHOUSE_EVENT_KNOCKBACK,
    DATA_MILLHOUSE_EVENT_DESPAWN,
    DATA_SLABHIDE_ROCK_WALL,
    DATA_EVENT_PROGRESS,

    // Teleporters
    DATA_STONECORE_TELEPORTER_1,
    DATA_STONECORE_TELEPORTER_2,
};

enum SCCreatureIds
{
    // Bosses
    BOSS_CORBORUS                   = 43438,
    BOSS_SLABHIDE                   = 43214,
    BOSS_OZRUK                      = 42188,
    BOSS_HIGH_PRIESTESS_AZIL        = 42333,

    // Corborus
    NPC_WORLDTRIGGER                = 22515,
    NPC_MILLHOUSE_MANASTORM         = 43391,
    NPC_TRASHING_CHARGE             = 43743,
    NPC_CRYSTAL_SHARD               = 49267,

    // Slabhide
    NPC_LAVA_FISSURE                = 43242,
    NPC_STALACTITE_TRIGGER_GROUND   = 43357,
    NPC_STALACTITE_TRIGGER          = 43159,

    // Ozruk
    NPC_BOUNCER_SPIKE               = 42189,
    NPC_RUPTURE_CONTROLLER          = 49597,
    NPC_RUPTURE                     = 49576,

    // High Priestess Azil
    NPC_DEVOUT_FOLLOWER             = 42428,
    NPC_SEISMIC_SHARD               = 42355,

    // Generic Creatures
    NPC_STONECORE_TELEPORTER_1      = 51396,
    NPC_STONECORE_TELEPORTER_2      = 51397
};

enum SCGameobjectIds
{
    GAMEOBJECT_TWILIGHT_DOCUMENTS   = 207415,
    GAMEOBJECT_CORBORUS_ROCKDOOR    = 207343,
    GAMEOBJECT_SLABHIDE_ROCK_WALL   = 204381,
    GO_STALACTITE                   = 204337
};

enum SCMisc
{
    ACTION_CORBORUS_INTRO                           = 1,
    ACTION_SLABHIDE_INTRO                           = 2,

    // Stonecore Teleporter misc
    MAX_STONECORE_TELEPORTERS                       = 2,
    SPELL_RING_WYRM_KNOCKBACK                       = 81235,

    // Creature Formation IDs
    CREATURE_FORMATION_MILLHOUSE_EVENT_TRASH        = 340418,
    CREATURE_FORMATION_MILLHOUSE_EVENT_LAST_GROUP   = 340492
};

enum SCEvents
{
    EVENT_RESPAWN_CORBORUS = 1,
    EVENT_RESPAWN_SLABHIDE,
};

enum SCEventIndex
{
    EVENT_INDEX_NONE            = 0,
    EVENT_INDEX_CORBORUS_INTRO  = 1,
    EVENT_INDEX_SLABHIDE_INTRO  = 2
};

Position const CorborusRespawnPos   = { 1154.55f,  878.843f,  284.963f,  3.176499f };
Position const CorborusSpawnPos     = { 1150.34f,  947.063f,  283.89f,   4.69494f  };
Position const SlabhideRespawnPos   = { 1292.352f, 1226.478f, 247.6368f, 3.630285f };
Position const SlabhideSpawnPos     = { 1191.1f,   1154.01f,  270.759f,  4.69494f  };

template <class AI, class T>
inline AI* GetStonecoreAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SCScriptName);
}

#define RegisterStonecoreCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetStonecoreAI)

#endif // DEF_STONECORE
