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

#ifndef DEF_ULDAMAN_H
#define DEF_ULDAMAN_H

#include "CreatureAIImpl.h"

#define UldamanScriptName "instance_uldaman"
#define DataHeader "UD"

enum UDBossIds
{
    BOSS_REVELOSH               = 0,
    BOSS_THE_LOST_DWARVES       = 1,
    BOSS_IRONAYA                = 2,
    BOSS_ANCIENT_STONE_KEEPER   = 3,
    BOSS_GALGANN_FIREHAMMER     = 4,
    BOSS_GRIMLOK                = 5,
    BOSS_ARCHAEDAS              = 6,
    BOSS_OBSIDIAN_SENTINEL      = 7,

    MAX_ENCOUNTER
};

enum UDDataTypes
{
    DATA_ALTAR_DOORS                    = 1,
    DATA_IRONAYA_DOOR                   = 3,
    DATA_STONE_KEEPERS                  = 4,
    DATA_MINIONS                        = 5,
    DATA_IRONAYA_SEAL                   = 6,
};

enum UDCreatureIds
{
    NPC_REVELOSH                = 6910,
    NPC_ANCIENT_STONE_KEEPER    = 7206,
    NPC_GALGANN_FIREHAMMER      = 7291,
    NPC_GRIMLOK                 = 4854,
    NPC_OBSIDIAN_SENTINEL       = 7023,
};

enum UDGameObjectIds
{
    GO_ARCHAEDAS_TEMPLE_DOOR            = 141869,
    GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR  = 124367,
    GO_ANCIENT_VAULT_DOOR               = 124369,
    GO_IRONAYA_SEAL_DOOR                = 124372,
    GO_KEYSTONE                         = 124371,
};

template <class AI, class T>
inline AI* GetUldamanAI(T* obj)
{
    return GetInstanceAI<AI>(obj, UldamanScriptName);
}

#define RegisterUldamanCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetUldamanAI)

#endif
