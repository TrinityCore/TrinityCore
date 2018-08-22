/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef HALLS_OF_ORIGINATION_H
#define HALLS_OF_ORIGINATION_H

#include "CreatureAIImpl.h"

#define DataHeader "HOO"
#define HoOScriptName "instance_halls_of_origination"

uint32 const EncounterCount = 12;

enum HOOData
{
    // Bosses
    DATA_TEMPLE_GUARDIAN_ANHUUR,
    DATA_EARTHRAGER_PTAH,
    DATA_ANRAPHET,
    DATA_ISISET,
    DATA_AMMUNAE,
    DATA_SETESH,
    DATA_RAJH,

    // Temple Guardian Anhuur
    DATA_ANHUUR_DOOR,
    DATA_HANDLE_SHIELD_VISUAL,
    DATA_HANDLE_BEAM_OF_LIGHT,

    // Anraphet
    DATA_BRANN_0,
    DATA_VAULT_OF_LIGHTS_DOOR,
    DATA_DEAD_ELEMENTALS,
    DATA_LIGHTMACHINE_EARTH,
    DATA_LIGHTMACHINE_AIR,
    DATA_LIGHTMACHINE_FIRE,
    DATA_LIGHTMACHINE_WATER,
    DATA_LASERBEAMS_EARTH,
    DATA_LASERBEAMS_AIR,
    DATA_LASERBEAMS_FIRE,
    DATA_LASERBEAMS_WATER,
    DATA_UPDATE_LASERBEAMS,
    DATA_ANRAPHET_SUN_MIRROR,
    DATA_ANRAPHET_DOOR,
    DATA_VAULT_OF_LIGHTS,

    // Earthrager Ptah
    DATA_SUMMON_SANDSTORM_ADDS,

    // Isiset
    DATA_ISISET_PHASE,
    DATA_ISISET_ASTRAL_RAIN_ALIVE,
    DATA_ISISET_CELESTIAL_CALL_ALIVE,
    DATA_ISISET_VEIL_OF_SKY_ALIVE,

    // Ammunae

    // Setesh
    DATA_SETESH_ADD_STALKER,

    // Misc
    DATA_LIFT_OF_THE_MAKERS
};

enum HOOCreatures
{
    BOSS_TEMPLE_GUARDIAN_ANHUUR     = 39425,
    NPC_CAVE_IN_STALKER             = 40183,
    NPC_SEARING_LIGHT               = 40283,

    BOSS_EARTHRAGER_PTAH            = 39428,
    NPC_BEETLE_STALKER              = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_JEWELED_SCARAB              = 40458, // Summoned by spell: 75462 Summon Jeweled Scarab
    NPC_DUSTBONE_HORROR             = 40450, // Summoned by spell: 75521 Summon Dustbone Horror
    NPC_QUICKSAND                   = 40503, // Summoned by spell: 75550 (server-side, not in dbc)
    NPC_HOO_CAMEL                   = 39443,

    BOSS_ANRAPHET                   = 39788,
    NPC_FIRE_WARDEN                 = 39800,
    NPC_EARTH_WARDEN                = 39801,
    NPC_WATER_WARDEN                = 39802,
    NPC_AIR_WARDEN                  = 39803,

    WARDEN_ENTRY_MAX_COUNT          = 4,

    NPC_BRANN_BRONZEBEARD_0         = 39908,
    NPC_OMEGA_STANCE                = 41194,
    NPC_ALPHA_BEAM                  = 41144,
    NPC_STONE_TROGG_PILLAGER        = 39804,
    NPC_STONE_TROGG_BRUTE           = 40251,
    NPC_STONE_TROGG_ROCK_FLINGER    = 40252,

    BOSS_ISISET                     = 39587,
    NPC_SPATIAL_FLUX_TRASH          = 39612, // Isiset trash
    NPC_ENERGY_FLUX_TRASH           = 44015,
    NPC_SPATIAL_ANOMALY             = 40170,
    NPC_FLUX_ANIMATOR               = 40033,
    NPC_STAR_SHARD                  = 40106,

    BOSS_AMMUNAE                    = 39731,

    BOSS_SETESH                     = 39732,
    NPC_SETESH_CHAOS_SEED           = 41126,
    NPC_SETESH_CHAOS_BLAST          = 41041,
    NPC_SETESH_CHAOS_PORTAL         = 41055,
    NPC_SETESH_ADD_STALKER          = 41479,
    NPC_SETESH_VOID_RIFT            = 39266, // Setesh trash

    BOSS_RAJH                       = 39378,
    NPC_INFERNO_LEAP                = 47040,
    NPC_BLAZING_INFERNO             = 40927,
};

enum HOOGameObjects
{
    GO_ANHUURS_BRIDGE               = 206506,
    GO_DOODAD_ULDUM_ELEVATOR_COL01  = 207725,
    GO_DOODAD_ULDUM_DOOR_14         = 202306,
    GO_DOODAD_ULDUM_DOOR_15         = 202307,

    GO_VAULT_OF_LIGHTS_DOOR         = 202313,
    GO_SUN_MIRROR                   = 207726,
    GO_ANRAPHET_DOOR                = 202314,

    GO_DOODAD_ULDUM_LIGHTMACHINE_02 = 207374, // South-West
    GO_DOODAD_ULDUM_LIGHTMACHINE_01 = 207375, // South-East
    GO_DOODAD_ULDUM_LIGHTMACHINE_04 = 207376, // North-West
    GO_DOODAD_ULDUM_LIGHTMACHINE_03 = 207377, // North-East

    GO_DOODAD_ULDUM_LASERBEAMS01    = 207662, // South-West
    GO_DOODAD_ULDUM_LASERBEAMS_01   = 207663, // South-East
    GO_DOODAD_ULDUM_LASERBEAMS_02   = 207664, // North-West
    GO_DOODAD_ULDUM_LASERBEAMS_03   = 207665, // North-East

    GO_ULDUM_TEMPLE                 = 207802,
    GO_REORIGINATION_MECHANISM_1    = 207445,
    GO_REORIGINATION_MECHANISM_2    = 207449,
    GO_REORIGINATION_MECHANISM_3    = 207452,
    GO_REORIGINATION_MECHANISM_4    = 207454,
    GO_REORIGINATION_MECHANISM_5    = 207456,

    GO_HOO_TRANSIT_DEVICE           = 204979, // Spell ID: 82916 - Teleports the caster to the lower floor of Halls of Origination.
    GO_HOO_TRANSIT_DEVICE_2         = 204972, // Spell ID: 82900 - Teleports the caster to the upper floor of Halls of Origination. (dbc desc is wrong)
    GO_LIFT_OF_THE_MAKERS           = 207547,
    GO_LIFT_GLASS_STAR              = 207673,
    GO_LIFT_GLASS_STAR_2            = 207674
};

enum Achievements
{
    //    I Hate That Song
    // Achievement.db2 ID 5293: ParentTree 19724
    // CriteriaTree.db2 ID 19725: ParentTree 19724 - Criteria 15988
    // Criteria.db2 ID 15988: on Anhuur kill, world state 5638 = value 0
    //CRITERIA_I_HATE_THAT_SONG         = 15988,
    WS_I_HATE_THIS_SONG                 =  5638,
    
    //    Straw That Broke the Camel's Back
    // Achievement.db2 ID 5294: ParentTree 18221
    // CriteriaTree.db2 ID 18222: ParentTree 18221 - Criteria 15989
    // Criteria.db2 ID 15989: on Ptah kill, tree 2838?
    CRITERIA_STRAW_BROKE_CAMELS_BACK    = 15989,

    //    Faster Than The Speed Of Light
    // Achievement.db2 ID 5296: ParentTree  17685
    // CriteriaTree.db2 ID 17686: ParentTree 17685 - Criteria 16008
    // Criteria.db2 ID 16008: spell 94067, startEvent 24212, tree 2615?, world state 5653 = value 0, type 69
    ACHIEV_VAULT_OF_LIGHTS_START_EVENT  = 24212,
    SPELL_VAULT_OF_LIGHTS_CREDIT        = 94067  // Achievement aura, not in DBC
};

enum HOOMisc
{
    AREA_TOMB_OF_THE_EARTHRAGER         = 4945,
    SPELL_ZERO_ENERGY_NO_REGEN_AURA     = 72242, // Zero Energy + Zero Regen (used by some npcs in HoO)
//  SPELL_SHRINK                        = 59632, // Used by static NPCs, summoned by bosses in The Four Seats (not in DBC!)

    // Cave In Stalker (beacons)
    SPELL_SHIELD_VISUAL_LEFT            = 83697,
    SPELL_SHIELD_VISUAL_RIGHT           = 83698,
    SPELL_BEAM_OF_LIGHT_LEFT            = 74930,
    SPELL_BEAM_OF_LIGHT_RIGHT           = 76573,

    // Beetle Stalker
    SPELL_BEETLE_BURROW                 = 75463, // Visual
    SPELL_SUMMON_JEWELED_SCARAB         = 75462,
    SPELL_SUMMON_DUSTBONE_HORROR        = 75521
};

enum HOOGlobalActions
{
    ACTION_PTAH_ADD_DIED,
    ACTION_ANRAPHET_INTRO,
    ACTION_ELEMENTAL_DIED,
    ACTION_ANRAPHET_DIED,
    ACTION_OMEGA_TRIGGER
};

enum HoODataStates
{
    ACTIVATE_SHIELD_OF_LIGHT = 0,
    DISABLE_SHIELD_OF_LIGHT
};

enum HoOEvents
{
    EVENT_RESPAWN_ANRAPHET = 1
};

Position const AnraphetSpawnPos     = { -90.2726f, 366.339f, 89.8639f,  3.14159f  };
Position const AnraphetRespawnPos   = { -193.656f, 366.689f, 75.91001f, 3.138207f };

template<typename AI>
inline AI* GetHallsOfOriginationAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, HoOScriptName);
}

#define RegisterHallsOfOriginationCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfOriginationAI)

template<typename AI>
inline AI* GetHallsOfOriginationAI(GameObject* go)
{
    return GetInstanceAI<AI>(go, HoOScriptName);
}

#endif // HALLS_OF_ORIGINATION_H
