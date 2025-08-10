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

#ifndef DEF_SEPULCHER_OF_THE_FIRST_ONES_H_
#define DEF_SEPULCHER_OF_THE_FIRST_ONES_H_

#include "CreatureAIImpl.h"

#define DataHeader "SepulcherOfTheFirstOnes"
#define SFOScriptName "instance_sepulcher_of_the_first_ones"

uint32 const EncounterCount = 11;

enum SepulcherOfTheFirstOnesDataTypes
{
    // Bosses
    DATA_VIGILANT_CUSTODIAN         = 0,
    DATA_SKOLEX                     = 1,
    DATA_ARTIFICER_XYMOX            = 2,
    DATA_HALONDRUS                  = 3,
    DATA_DAUSEGNE                   = 4,
    DATA_PROTOTYPE_PANTHEON         = 5,
    DATA_LIHUVIM                    = 6,
    DATA_ANDUIN_WRYNN               = 7,
    DATA_LORDS_OF_DREAD             = 8,
    DATA_RYGELON                    = 10,
    DATA_JAILER                     = 11,

    // Anduin Wrynn Encounter
    DATA_ANDUIN_WRYNN_INTRODUCTION,
    DATA_REMNANT_OF_A_FALLEN_KING,
    DATA_SYLVANAS_WINDRUNNER_ANDUIN,
    DATA_ANDUIN_SOUL,
    DATA_BEACON_OF_HOPE,
    DATA_JAINA_PROUDMOORE_ANDUIN,
    DATA_UTHER_THE_LIGHTBRINGER_ANDUIN,
    DATA_FIRIM_ANDUIN,
    DATA_ANDUIN_TREASURE,
    DATA_BOLVAR_FORDRAGON_ANDUIN,
    DATA_THRALL_ANDUIN,
    DATA_QUARTERMASTER_RAHM_ANDUIN,
};

enum SepulcherOfTheFirstOnesCreatureIds
{
    // Bosses
    BOSS_VIGILANT_CUSTODIAN             = 184522,
    BOSS_VIGILANT_GUARDIAN              = 180773,
    BOSS_ANDUIN_WRYNN                   = 181954,
    BOSS_REMNANT_OF_A_FALLEN_KING       = 183463,

    // Anduin Wrynn Encounter
    NPC_LADY_JAINA_PROUDMOORE_ANDUIN    = 183664,
    NPC_UTHER_THE_LIGHTBRINGER_ANDUIN   = 183665,
    NPC_SYLVANAS_WINDRUNNER_ANDUIN      = 183666,
    NPC_FIRIM_ANDUIN                    = 184589,
    NPC_BEFOULED_BARRIER                = 184585,
    NPC_ANDUIN_SOUL                     = 184519,
    NPC_ANDUIN_DESPAIR                  = 184520,
    NPC_ANDUIN_HOPE                     = 184493,
    NPC_ANDUIN_DOUBT                    = 184494,
    NPC_EMPTY_VESSEL                    = 183452,
    NPC_LOST_SOUL                       = 185607,
    NPC_MONSTROUS_SOUL                  = 183671,
    NPC_FIENDISH_SOUL                   = 183669,
    NPC_MARCH_OF_THE_DAMNED             = 183793,
    NPC_GRIM_REFLECTION                 = 183033,
    NPC_BEACON_OF_HOPE                  = 184830,
    NPC_BOLVAR_FORDRAGON_ANDUIN         = 184601,
    NPC_QUARTERMASTER_RAHM_ANDUIN       = 186785,
    NPC_THRALL_ANDUIN                   = 184599,
    NPC_KNIGHT_OF_EBON_BLADE_ANDUIN     = 184613,
};

enum SepulcherOfTheFirstOnesTranslocatorIds
{
    NPC_ANCIENT_TRANSLOCATOR = 182431,
};

enum SepulcherOfTheFirstOnesGameObjectIds
{
    GAMEOBJECT_BRIDGE_TO_ANDUIN     = 375110,
    GAMEOBJECT_BRIDGE_AFTER_ANDUIN  = 375035,
    GAMEOBJECT_ANDUIN_CHEST_LOOT    = 375901,
};

enum SepulcherOfTheFirstOnesEvents
{
    EVENT_RESET_PLAYERS_ON_TRANSLOCATOR = 1
};

enum SepulcherOfTheFirstOnesActions
{
    ACTION_START_ANDUIN_OUTRODUCTION = 1,
};

enum SepulcherOfTheFirstOnesAreas
{
    AREA_DOMINATION_GRASP               = 13965,
    AREA_SEPULCHER_OF_THE_FIRST_ONES    = 13742,
};

enum SepulcherOfTheFirstOnesWorldStates
{
    WORLD_STATE_ANDUIN_ENCOUNTER_STARTED    = 21243,
    WORLD_STATE_ANDUIN_INTERMISSION         = 21433,
    WORLD_STATE_ANDUIN_ENCOUNTER_COMPLETED  = 21242,
};

template <class AI, class T>
inline AI* GetSepulcherOfTheFirstOnesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SFOScriptName);
}

#define RegisterSepulcherOfTheFirstOnesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSepulcherOfTheFirstOnesAI)

#endif
