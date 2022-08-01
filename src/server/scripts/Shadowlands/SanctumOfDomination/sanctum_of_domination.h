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

#define DataHeader "SD"
#define SDScriptName "instance_sanctum_of_domination"

Position const SylvanasPlatformRevivePos = { 265.834f, -799.287f, 4104.977f, 3.811291f };

uint32 const EncounterCount = 10;

enum SanctumOfDominationDataTypes
{
    DATA_SYLVANAS_WINDRUNNER                        = 9,

    // Encounter-related data

    // Sylvanas Windrunner
    DATA_SYLVANAS_INTRO,
    DATA_BOLVAR_FORDRAGON_PINNACLE,
    DATA_JAINA_PROUDMOORE_PINNACLE,
    DATA_THRALL_PINNACLE,
    DATA_ANDUIN_CRUCIBLE,
    DATA_DOMINATION_ARROW,

    DATA_SYLVANAS_SHADOWCOPY_01                     = 20,
    DATA_SYLVANAS_SHADOWCOPY_02,
    DATA_SYLVANAS_SHADOWCOPY_03,
    DATA_SYLVANAS_SHADOWCOPY_04,
    DATA_SYLVANAS_SHADOWCOPY_05,
    DATA_SYLVANAS_SHADOWCOPY_06,
    DATA_SYLVANAS_SHADOWCOPY_07,
    DATA_SYLVANAS_SHADOWCOPY_08,
    DATA_SYLVANAS_SHADOWCOPY_09,
    DATA_SYLVANAS_SHADOWCOPY_10,
    DATA_SYLVANAS_SHADOWCOPY_11,
    DATA_SYLVANAS_SHADOWCOPY_12,
    DATA_SYLVANAS_SHADOWCOPY_13
};

enum SanctumOfDominationCreatureIds
{
    // Bosses
    BOSS_SYLVANAS_WINDRUNNER                        = 175732,

    // Sylvanas Windrunner
    NPC_BOLVAR_FORDRAGON_PINNACLE                   = 178081,
    NPC_JAINA_PROUDMOORE_PINNACLE                   = 176533,
    NPC_THRALL_PINNACLE                             = 176532,
    NPC_ANDUIN_CRUCIBLE                             = 178072,

    NPC_SYLVANAS_SHADOWCOPY_RIDING                  = 178355,
    NPC_SYLVANAS_SHADOWCOPY_FIGHTER                 = 176369,
    NPC_SYLVANAS_JAILER_SOUL                        = 179262,

    NPC_DOMINATION_ARROW                            = 176920
};

enum SanctumOfDominationGameObjectIds
{
    GAMEOBJECT_TORGHAST_SPIKE_01                    = 368743,
    GAMEOBJECT_TORGHAST_SPIKE_02                    = 368744,
    GAMEOBJECT_TORGHAST_SPIKE_03                    = 368745,
    GAMEOBJECT_TORGHAST_SPIKE_04                    = 368746,
    GAMEOBJECT_TORGHAST_SPIKE_05                    = 368747,
    GAMEOBJECT_TORGHAST_SPIKE_06                    = 368748,
    GAMEOBJECT_TORGHAST_SPIKE_07                    = 368749,
    GAMEOBJECT_TORGHAST_SPIKE_08                    = 368750,
    GAMEOBJECT_TORGHAST_SPIKE_09                    = 368751,
    GAMEOBJECT_TORGHAST_SPIKE_10                    = 368752,
    GAMEOBJECT_TORGHAST_SPIKE_11                    = 368753,
    GAMEOBJECT_TORGHAST_SPIKE_12                    = 368754,
    GAMEOBJECT_INVISIBLE_WALL_PHASE_2               = 369242
};

enum SanctumOfDominationEvents
{
    EVENT_RESET_PLAYERS_ON_SYLVANAS                 = 1
};

enum SanctumOfDominationActions
{
    ACTION_START_SYLVANAS_INTRO                     = 50
};

enum SanctumOfDominationAreas
{
    AREA_PINNACLE_OF_DOMINANCE                      = 13653,
    AREA_EDGE_OF_THE_ABYSS                          = 13654,
    AREA_THE_CRUCIBLE                               = 13655
};

template <class AI, class T>
inline AI* GetSanctumOfDominationAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SDScriptName);
}

#define RegisterSanctumOfDominationCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSanctumOfDominationAI)

#endif
