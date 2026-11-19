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

#ifndef DEF_SANCTUM_OF_DOMINATION_H_
#define DEF_SANCTUM_OF_DOMINATION_H_

#include "CreatureAIImpl.h"

#define DataHeader "SanctumOfDomination"
#define SODScriptName "instance_sanctum_of_domination"

uint32 const EncounterCount = 10;

Position const SylvanasRespawnPos = { 225.73611f, -844.0746f,  4104.9882f, 1.3613f };

enum SanctumOfDominationDataTypes
{
    DATA_THE_TARRAGRUE                         = 0,
    DATA_THE_EYE_OF_THE_JAILER                 = 1,
    DATA_THE_NINE                              = 2,
    DATA_REMNANT_OF_NERZHUL                    = 3,
    DATA_SOULRENDER_DORMAZAIN                  = 4,
    DATA_PAINSMITH_RAZNAL                      = 5,
    DATA_GUARDIAN_OF_THE_FIRST_ONES            = 6,
    DATA_FATESCRIBE_ROHKALO                    = 7,
    DATA_KELTHUZAD                             = 8,
    DATA_SYLVANAS_WINDRUNNER                   = 9,

    /* Encounter-related data */

    /* Sylvanas Windrunner */
    DATA_SYLVANAS_INTRODUCTION,
    DATA_SYLVANAS_SHADOWCOPY_RIDING,
    DATA_BOLVAR_FORDRAGON_PINNACLE,
    DATA_JAINA_PROUDMOORE_PINNACLE,
    DATA_THRALL_PINNACLE,
    DATA_THRONE_OF_THE_DAMNED
};

enum SanctumOfDominationCreatureIds
{
    // Bosses
    BOSS_SYLVANAS_WINDRUNNER                   = 175732,

    /* Encounter-related creatures */

    /* Sylvanas Windrunner Encounter */
    NPC_SYLVANAS_SHADOWCOPY_RIDING             = 178355,
    NPC_BOLVAR_FORDRAGON_PINNACLE              = 178081,
    NPC_JAINA_PROUDMOORE_PINNACLE              = 176533,
    NPC_THRALL_PINNACLE                        = 176532,

    NPC_THRONE_OF_THE_DAMNED                   = 180803
};

enum SanctumOfDominationGameObjectIds
{
    GAMEOBJECT_TORGHAST_SPIKE_01               = 368743,
    GAMEOBJECT_TORGHAST_SPIKE_02               = 368744,
    GAMEOBJECT_TORGHAST_SPIKE_03               = 368745,
    GAMEOBJECT_TORGHAST_SPIKE_04               = 368746,
    GAMEOBJECT_TORGHAST_SPIKE_05               = 368747,
    GAMEOBJECT_TORGHAST_SPIKE_06               = 368748,
    GAMEOBJECT_TORGHAST_SPIKE_07               = 368749,
    GAMEOBJECT_TORGHAST_SPIKE_08               = 368750,
    GAMEOBJECT_TORGHAST_SPIKE_09               = 368751,
    GAMEOBJECT_TORGHAST_SPIKE_10               = 368752,
    GAMEOBJECT_TORGHAST_SPIKE_11               = 368753,
    GAMEOBJECT_TORGHAST_SPIKE_12               = 368754
};

enum SanctumOfDominationAreas
{
    AREA_PINNACLE_OF_DOMINANCE                 = 13653,
    AREA_EDGE_OF_THE_ABYSS                     = 13654,
    AREA_THE_CRUCIBLE                          = 13655
};

enum SanctumofDominationWorldStates
{
    WORLD_STATE_SYLVANAS_ENCOUNTER_STARTED     = 20346,
    WORLD_STATE_SYLVANAS_ENCOUNTER_COMPLETED   = 20347,
    WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE       = 20348,
    WORLD_STATE_SYLVANAS_UNK_01                = 21210, // Info: sets to 0 several times on phase 3.
    WORLD_STATE_SYLVANAS_UNK_02                = 21166, // Info: sets to 1 when SPELL_FINAL_SCENE is cast on players.
    WORLD_STATE_SYLVANAS_UNK_03                = 21120, // Info: sets to 1 when 353687 spell is cast by NPC 179262.
    WORLD_STATE_SYLVANAS_ACHIEVEMENT_COMPLETED = 21134,
    WORLD_STATE_SYLVANAS_UNK_04                = 20439, // Info: this is always 1 on INIT and the following are 0.
    WORLD_STATE_SYLVANAS_UNK_05                = 20440,
    WORLD_STATE_SYLVANAS_UNK_06                = 20441,
    WORLD_STATE_SYLVANAS_UNK_07                = 20442,
    WORLD_STATE_SYLVANAS_UNK_08                = 20443
};

template <class AI, class T>
inline AI* GetSanctumOfDominationAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SODScriptName);
}

#define RegisterSanctumOfDominationCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSanctumOfDominationAI)

#endif
