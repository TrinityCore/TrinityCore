/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"

#define RSScriptName "instance_ruby_sanctum"
uint32 const EncounterCount = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_BALTHARUS_THE_WARBORN              = 0,
    DATA_GENERAL_ZARITHRIAN                 = 1,
    DATA_SAVIANA_RAGEFIRE                   = 2,
    DATA_HALION                             = 3,

    // Etc
    DATA_XERESTRASZA                        = 4,
    DATA_CRYSTAL_CHANNEL_TARGET             = 5,
    DATA_BALTHARUS_SHARED_HEALTH            = 6,
};

enum SharedActions
{
    ACTION_INTRO_TRIGGER                    = -3975101,
    ACTION_BALTHARUS_DEATH                  = -3975102,
};

enum CreaturesIds
{
    // Baltharus the Warborn
    NPC_BALTHARUS_THE_WARBORN               = 39751,
    NPC_BALTHARUS_THE_WARBORN_CLONE         = 39899,
    NPC_BALTHARUS_TARGET                    = 26712,

    // General Zarithrian
    NPC_GENERAL_ZARITHRIAN                  = 39746,
    NPC_ONYX_FLAMECALLER                    = 39814,
    NPC_ZARITHIAN_SPAWN_STALKER             = 39794,

    // Saviana Ragefire
    NPC_SAVIANA_RAGEFIRE                    = 39747,

    // Halion
    NPC_HALION                              = 39863,
    NPC_HALION_TWILIGHT                     = 40142,
    NPC_HALION_CONTROLLER                   = 40146,
    NPC_LIVING_INFERNO                      = 40681,
    NPC_LIVING_EMBER                        = 40683,
    NPC_ORB_CARRIER                         = 40081,
    NPC_ORB_ROTATION_FOCUS                  = 40091,
    NPC_SHADOW_ORB_N                        = 40083,
    NPC_SHADOW_ORB_S                        = 40100,

    // Xerestrasza
    NPC_XERESTRASZA                         = 40429,
};

enum GameObjectsIds
{
    GO_HALION_PORTAL_1                      = 202794,   // Unknown spell 75074, should be somehow be linked to 74807
    GO_HALION_PORTAL_2                      = 202795,   // Also spell 75074
    GO_HALION_PORTAL_EXIT                   = 202796,   // Leave Twilight Realm (74812)
    GO_FIRE_FIELD                           = 203005,
    GO_FLAME_WALLS                          = 203006,
    GO_FLAME_RING                           = 203007,
};

enum WorldStatesRS
{
    WORLDSTATE_UNK_1                = 5049, // Halion corporeality amount - normal phase
    WORLDSTATE_UNK_2                = 5050, // Halion corporeality amount - twilight phase
    WORLDSTATE_UNK_3                = 5051, // Halion corporeality toggle show
};

template<class AI>
CreatureAI* GetRubySanctumAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == GetScriptId(RSScriptName))
                return new AI(creature);
    return NULL;
}

#endif // RUBY_SANCTUM_H_
