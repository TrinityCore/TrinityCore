/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

#include "CreatureAIImpl.h"

#define MGTScriptName "instance_magisters_terrace"
#define DataHeader "MT"

uint32 const EncounterCount = 4;

enum MTDataTypes
{
    // Encounter states
    DATA_SELIN_FIREHEART = 0,
    DATA_VEXALLUS,
    DATA_PRIESTESS_DELRISSA,
    DATA_KAELTHAS_SUNSTRIDER,

    // Encounter related
    DATA_KAELTHAS_INTRO,
    DATA_DELRISSA_DEATH_COUNT,

    // Additional data
    DATA_KALECGOS,
    DATA_ESCAPE_ORB
};

enum MTCreatureIds
{
    // Bosses
    BOSS_KAELTHAS_SUNSTRIDER    = 24664,
    BOSS_SELIN_FIREHEART        = 24723,
    BOSS_VEXALLUS               = 24744,
    BOSS_PRIESTESS_DELRISSA     = 24560,

    // Encounter related
    /*Kael'thas Sunstrider*/
    NPC_ARCANE_SPHERE           = 24708,
    NPC_FLAME_STRIKE            = 24666,
    NPC_PHOENIX                 = 24674,
    NPC_PHOENIX_EGG             = 24675,

    /*Selin Fireheart*/
    NPC_FEL_CRYSTAL             = 24722,

    // Event related
    NPC_KALECGOS                = 24844,
    NPC_HUMAN_KALECGOS          = 24848,
    NPC_COILSKAR_WITCH          = 24696,
    NPC_SUNBLADE_WARLOCK        = 24686,
    NPC_SUNBLADE_MAGE_GUARD     = 24683,
    NPC_SISTER_OF_TORMENT       = 24697,
    NPC_ETHEREUM_SMUGGLER       = 24698,
    NPC_SUNBLADE_BLOOD_KNIGHT   = 24684
};

enum MTGameObjectIds
{
    GO_ASSEMBLY_CHAMBER_DOOR    = 188065,
    GO_SUNWELL_RAID_GATE_2      = 187979,
    GO_SUNWELL_RAID_GATE_4      = 187770,
    GO_SUNWELL_RAID_GATE_5      = 187896,
    GO_ASYLUM_DOOR              = 188064,
    GO_ESCAPE_ORB               = 188173
};

enum MTInstanceEventIds
{
    EVENT_SPAWN_KALECGOS    = 16547
};

enum MTInstanceText
{
    SAY_KALECGOS_SPAWN      = 0
};

enum MTMovementData
{
    PATH_KALECGOS_FLIGHT    = 248440
};

template <class AI, class T>
inline AI* GetMagistersTerraceAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MGTScriptName);
}

#define RegisterMagistersTerraceCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMagistersTerraceAI)

#endif
