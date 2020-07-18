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

#ifndef RUBY_SANCTUM_H_
#define RUBY_SANCTUM_H_

#include "CreatureAIImpl.h"

#define RSScriptName "instance_ruby_sanctum"
#define DataHeader "RS"

uint32 const EncounterCount = 4;

enum RSDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_BALTHARUS_THE_WARBORN              = 0,
    DATA_GENERAL_ZARITHRIAN                 = 1,
    DATA_SAVIANA_RAGEFIRE                   = 2,
    DATA_HALION                             = 3,

    // Etc
    DATA_TWILIGHT_HALION                    = 4,
    DATA_XERESTRASZA                        = 5,
    DATA_CRYSTAL_CHANNEL_TARGET             = 6,
    DATA_BALTHARUS_SHARED_HEALTH            = 7,
    DATA_ZARITHRIAN_SPAWN_STALKER_1         = 8,
    DATA_ZARITHRIAN_SPAWN_STALKER_2         = 9,
    DATA_HALION_CONTROLLER                  = 10,
    DATA_ORB_CARRIER                        = 11,
    DATA_ORB_ROTATION_FOCUS                 = 12,
    DATA_BURNING_TREE_1                     = 13,
    DATA_BURNING_TREE_2                     = 14,
    DATA_BURNING_TREE_3                     = 15,
    DATA_BURNING_TREE_4                     = 16,
    DATA_FLAME_RING                         = 17,
    DATA_TWILIGHT_FLAME_RING                = 18,
    DATA_BALTHARUS_CLONE                    = 19,
    DATA_FLAME_WALLS                        = 20
};

enum RSSharedActions
{
    ACTION_INTRO_BALTHARUS                  = -3975101,
    ACTION_BALTHARUS_DEATH                  = -3975102,
    ACTION_INTRO_HALION                     = -4014601,
    ACTION_INTRO_HALION_2                   = -4014602
};

enum RSCreaturesIds
{
    // Baltharus the Warborn
    NPC_BALTHARUS_THE_WARBORN               = 39751,
    NPC_BALTHARUS_THE_WARBORN_CLONE         = 39899,
    NPC_BALTHARUS_TARGET                    = 26712,

    // General Zarithrian
    NPC_GENERAL_ZARITHRIAN                  = 39746,
    NPC_ONYX_FLAMECALLER                    = 39814,
    NPC_ZARITHRIAN_SPAWN_STALKER            = 39794,

    // Saviana Ragefire
    NPC_SAVIANA_RAGEFIRE                    = 39747,

    // Halion
    NPC_HALION                              = 39863,
    NPC_TWILIGHT_HALION                     = 40142,
    NPC_HALION_CONTROLLER                   = 40146,
    NPC_LIVING_INFERNO                      = 40681,
    NPC_LIVING_EMBER                        = 40683,
    NPC_ORB_CARRIER                         = 40081,
    NPC_ORB_ROTATION_FOCUS                  = 40091,
    NPC_SHADOW_ORB_N                        = 40083,
    NPC_SHADOW_ORB_S                        = 40100,
    NPC_SHADOW_ORB_E                        = 40468,
    NPC_SHADOW_ORB_W                        = 40469,
    NPC_METEOR_STRIKE_MARK                  = 40029,
    NPC_METEOR_STRIKE_NORTH                 = 40041,
    NPC_METEOR_STRIKE_EAST                  = 40042,
    NPC_METEOR_STRIKE_WEST                  = 40043,
    NPC_METEOR_STRIKE_SOUTH                 = 40044,
    NPC_METEOR_STRIKE_FLAME                 = 40055,
    NPC_COMBUSTION                          = 40001,
    NPC_CONSUMPTION                         = 40135,
    NPC_COMBAT_STALKER                      = 40151, // Seen in sniffs but not used, so no wonder.

    // Xerestrasza
    NPC_XERESTRASZA                         = 40429
};

enum RSGameObjectsIds
{
    GO_HALION_PORTAL_1                      = 202794,   // Unknown spell 75074, should be somehow be linked to 74807
    GO_HALION_PORTAL_2                      = 202795,   // Also spell 75074
    GO_HALION_PORTAL_EXIT                   = 202796,   // Leave Twilight Realm (74812)
    GO_FIRE_FIELD                           = 203005,
    GO_FLAME_WALLS                          = 203006,
    GO_FLAME_RING                           = 203007,
    GO_TWILIGHT_FLAME_RING                  = 203624,
    GO_BURNING_TREE_1                       = 203034,
    GO_BURNING_TREE_2                       = 203035,
    GO_BURNING_TREE_3                       = 203036,
    GO_BURNING_TREE_4                       = 203037
};

enum RSWorldStatesRS
{
    WORLDSTATE_CORPOREALITY_MATERIAL = 5049,
    WORLDSTATE_CORPOREALITY_TWILIGHT = 5050,
    WORLDSTATE_CORPOREALITY_TOGGLE   = 5051
};

enum RSInstanceSpell
{
    SPELL_BERSERK                       = 26662
};

template <class AI, class T>
inline AI* GetRubySanctumAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RSScriptName);
}

#endif // RUBY_SANCTUM_H_
