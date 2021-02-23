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

#ifndef HALLS_OF_ORIGINATION_H
#define HALLS_OF_ORIGINATION_H

#include "CreatureAIImpl.h"
#include "Position.h"
#include "Creature.h"

#define DataHeader "HOO"
#define HoOScriptName "instance_halls_of_origination"

uint32 const EncounterCount = 12;

enum HOOData
{
    // Bosses
    DATA_TEMPLE_GUARDIAN_ANHUUR = 0,
    DATA_EARTHRAGER_PTAH        = 1,
    DATA_ANRAPHET               = 2,
    DATA_ISISET                 = 3,
    DATA_AMMUNAE                = 4,
    DATA_SETESH                 = 5,
    DATA_RAJH                   = 6,

    // Temple Guardian Anhuur
    DATA_ANHUUR_DOOR,
    DATA_HANDLE_SHIELD_VISUAL,
    DATA_HANDLE_BEAM_OF_LIGHT,

    // Anraphet
    DATA_BRANN_0,
    DATA_VAULT_OF_LIGHTS_ENTRANCE_DOOR,
    DATA_LIGHT_MACHINE_1,
    DATA_LIGHT_MACHINE_2,
    DATA_LIGHT_MACHINE_3,
    DATA_LIGHT_MACHINE_4,
    DATA_LASER_BEAMS_1,
    DATA_LASER_BEAMS_2,
    DATA_LASER_BEAMS_3,
    DATA_LASER_BEAMS_4,
    DATA_SUN_MIRROR,
    DATA_VAULT_OF_LIGHTS_BOSS_DOOR,
    DATA_WARDEN_1_DIED,
    DATA_WARDEN_2_DIED,
    DATA_WARDEN_3_DIED,
    DATA_WARDEN_4_DIED,
    DATA_WARDEN_NUMBER,
    DATA_VAULT_OF_LIGHTS,

    // Earthrager Ptah
    DATA_SUMMON_SANDSTORM_ADDS,

    // Isiset
    DATA_ISISET_PHASE,
    DATA_ISISET_ASTRAL_RAIN_ALIVE,
    DATA_ISISET_CELESTIAL_CALL_ALIVE,
    DATA_ISISET_VEIL_OF_SKY_ALIVE,

    // Setesh
    DATA_SETESH_ADD_STALKER,

    // Misc
    DATA_LIFT_OF_THE_MAKERS
};

enum HOOCreatures
{
    // Bosses
    BOSS_TEMPLE_GUARDIAN_ANHUUR     = 39425,
    BOSS_EARTHRAGER_PTAH            = 39428,
    BOSS_ANRAPHET                   = 39788,
    BOSS_ISISET                     = 39587,
    BOSS_AMMUNAE                    = 39731,
    BOSS_SETESH                     = 39732,
    BOSS_RAJH                       = 39378,

    // Encounter Related Creatues
    /*Temple Guardian Anhuur*/
    NPC_CAVE_IN_STALKER             = 40183,
    NPC_SEARING_LIGHT               = 40283,
    NPC_PIT_VIPER                   = 39444,

    /*Earthrager Ptah*/
    NPC_BEETLE_STALKER              = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_JEWELED_SCARAB              = 40458, // Summoned by spell: 75462 Summon Jeweled Scarab
    NPC_DUSTBONE_HORROR             = 40450, // Summoned by spell: 75521 Summon Dustbone Horror
    NPC_QUICKSAND                   = 40503, // Summoned by spell: 75550 (server-side, not in dbc)
    NPC_HOO_CAMEL                   = 39443,
    NPC_TUMULTOUS_EARTHSTORM        = 40406,

    /*Anraphet*/
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

    /*Isiset*/
    NPC_SPATIAL_FLUX_TRASH          = 39612, // Isiset trash
    NPC_ENERGY_FLUX_TRASH           = 44015,
    NPC_SPATIAL_ANOMALY             = 40170,
    NPC_FLUX_ANIMATOR               = 40033,
    NPC_STAR_SHARD                  = 40106,

    /*Ammunae*/
    NPC_SEEDLING_POD_VISUAL         = 40592,
    NPC_BLOODPETAL_BLOSSOM          = 40620,
    NPC_BLOODPETAL_BLOSSOM_VISUAL   = 40622,
    NPC_BLOODPETAL_SPROUT           = 40630,

    /*Setesh*/
    NPC_SETESH_CHAOS_SEED           = 41126,
    NPC_SETESH_CHAOS_BLAST          = 41041,
    NPC_SETESH_CHAOS_PORTAL         = 41055,
    NPC_SETESH_ADD_STALKER          = 41479,
    NPC_SETESH_VOID_RIFT            = 39266, // Setesh trash

    /*Rajh*/
    NPC_INFERNO_LEAP                = 47040,
    NPC_BLAZING_INFERNO             = 40927,
    NPC_SUN_TOUCHED_SERVANT         = 39366,
    NPC_SUN_TOUCHED_SPRITE          = 39369,
    NPC_SUN_TOUCHED_SPRITELING      = 39370
};

enum HOOGameObjects
{
    GO_ANHUURS_BRIDGE                   = 206506,
    GO_BEACON_OF_LIGHT_NORMAL_1         = 203136,
    GO_BEACON_OF_LIGHT_NORMAL_2         = 203133,
    GO_BEACON_OF_LIGHT_HEROIC_1         = 207219,
    GO_BEACON_OF_LIGHT_HEROIC_2         = 207218,

    GO_DOODAD_ULDUM_ELEVATOR_COL01      = 207725,
    GO_DOODAD_ULDUM_DOOR_14             = 202306,
    GO_DOODAD_ULDUM_DOOR_15             = 202307,

    GO_VAULT_OF_LIGHTS_ENTRANCE_DOOR    = 202313,
    GO_SUN_MIRROR                       = 207726,
    GO_VAULT_OF_LIGHTS_BOSS_DOOR        = 202314,

    GO_DOODAD_ULDUM_LIGHTMACHINE_02     = 207374, // South-West
    GO_DOODAD_ULDUM_LIGHTMACHINE_01     = 207375, // South-East
    GO_DOODAD_ULDUM_LIGHTMACHINE_04     = 207376, // North-West
    GO_DOODAD_ULDUM_LIGHTMACHINE_03     = 207377, // North-East

    GO_DOODAD_ULDUM_LASERBEAMS01        = 207662, // South-West
    GO_DOODAD_ULDUM_LASERBEAMS_01       = 207663, // South-East
    GO_DOODAD_ULDUM_LASERBEAMS_02       = 207664, // North-West
    GO_DOODAD_ULDUM_LASERBEAMS_03       = 207665, // North-East

    GO_ULDUM_TEMPLE                     = 207802,
    GO_REORIGINATION_MECHANISM_1        = 207445,
    GO_REORIGINATION_MECHANISM_2        = 207449,
    GO_REORIGINATION_MECHANISM_3        = 207452,
    GO_REORIGINATION_MECHANISM_4        = 207454,
    GO_REORIGINATION_MECHANISM_5        = 207456,

    GO_HOO_TRANSIT_DEVICE               = 204979, // Spell ID: 82916 - Teleports the caster to the lower floor of Halls of Origination.
    GO_HOO_TRANSIT_DEVICE_2             = 204972, // Spell ID: 82900 - Teleports the caster to the upper floor of Halls of Origination. (dbc desc is wrong)
    GO_LIFT_OF_THE_MAKERS               = 207547,
    GO_LIFT_GLASS_STAR                  = 207673,
    GO_LIFT_GLASS_STAR_2                = 207674
};

enum Achievements
{
    WS_I_HATE_THIS_SONG                 = 5638,
    CRITERIA_STRAW_BROKE_CAMELS_BACK    = 15989,
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

enum HOOActions
{
    ACTION_PTAH_ADD_DIED,
    ACTION_ANRAPHET_INTRO,
    ACTION_ANRAPHET_DIED,
    ACTION_OMEGA_TRIGGER
};

enum HoODataStates
{
    ACTIVATE_SHIELD_OF_LIGHT = 0,
    DISABLE_SHIELD_OF_LIGHT
};

Position const AnraphetSpawnPos     = { -90.2726f, 366.339f, 89.8639f,  3.14159f  };
Position const AnraphetRespawnPos   = { -193.656f, 366.689f, 75.91001f, 3.138207f };

template<typename AI, class T>
inline AI* GetHallsOfOriginationAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HoOScriptName);
}

#define RegisterHallsOfOriginationCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfOriginationAI)


#endif // HALLS_OF_ORIGINATION_H
