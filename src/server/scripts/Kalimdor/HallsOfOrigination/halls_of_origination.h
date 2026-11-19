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

constexpr char const* DataHeader = "HOO";
#define HoOScriptName "instance_halls_of_origination"

constexpr uint32 const EncounterCount = 12;

enum HOOData
{
    // Encounters
    BOSS_TEMPLE_GUARDIAN_ANHUUR,
    BOSS_EARTHRAGER_PTAH,
    BOSS_ANRAPHET,
    BOSS_ISISET,
    BOSS_AMMUNAE,
    BOSS_SETESH,
    BOSS_RAJH,

    // Event Boss States
    BOSS_VAULT_OF_LIGHTS,
    BOSS_FIRE_WARDEN,
    BOSS_EARTH_WARDEN,
    BOSS_WATER_WARDEN,
    BOSS_AIR_WARDEN,

    // Temple Guardian Anhuur
    DATA_ANHUUR_LEFT_BEACON,
    DATA_ANHUUR_RIGHT_BEACON,
    DATA_ANHUUR_BRIDGE,
    DATA_ANHUUR_DOOR,

    // Anraphet
    DATA_DEAD_ELEMENTALS,
    DATA_BRANN_BRONZEBEARD,

    // Events
    DATA_LIFT_OF_THE_MAKERS
};

enum HOOCreatures
{
    NPC_TEMPLE_GUARDIAN_ANHUUR      = 39425,
    NPC_CAVE_IN_STALKER             = 40183,
    NPC_SEARING_LIGHT               = 40283,

    NPC_EARTHRAGER_PTAH             = 39428,
    NPC_BEETLE_STALKER              = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_JEWELED_SCARAB              = 40458,
    NPC_DUSTBONE_HORROR             = 40450,
    NPC_QUICKSAND                   = 40503, // Summoned by a spell not in dbc (75550)

    NPC_ANRAPHET                    = 39788,
    NPC_FIRE_WARDEN                 = 39800,
    NPC_EARTH_WARDEN                = 39801,
    NPC_WATER_WARDEN                = 39802,
    NPC_AIR_WARDEN                  = 39803,

    WARDEN_ENTRY_DATA_DELTA         = NPC_FIRE_WARDEN - uint8(BOSS_FIRE_WARDEN),

    NPC_BRANN_BRONZEBEARD_0         = 39908,
    NPC_OMEGA_STANCE                = 41194,
};

enum HOOGameObjects
{
    GO_ANHUURS_BRIDGE               = 206506,
    GO_DOODAD_ULDUM_ELEVATOR_COL01  = 207725,
    GO_ANHUURS_DOOR                 = 202307,
    GO_ANHUURS_RIGHT_BEACON         = 203136,
    GO_ANHUURS_LEFT_BEACON          = 203133,

    GO_VAULT_OF_LIGHTS_DOOR         = 202313,
    GO_SUN_MIRROR                   = 207726,
    GO_ANRAPHET_DOOR                = 202314,

    GO_DOODAD_ULDUM_LIGHTMACHINE_01 = 207375,
    GO_DOODAD_ULDUM_LIGHTMACHINE_02 = 207374,
    GO_DOODAD_ULDUM_LIGHTMACHINE_03 = 207377,
    GO_DOODAD_ULDUM_LIGHTMACHINE_04 = 207376,

    GO_DOODAD_ULDUM_LASERBEAMS01    = 207662, // Matches GO_DOODAD_ULDUM_LIGHTMACHINE_02
    GO_DOODAD_ULDUM_LASERBEAMS_01   = 207663, // Matches GO_DOODAD_ULDUM_LIGHTMACHINE_01
    GO_DOODAD_ULDUM_LASERBEAMS_02   = 207664, // Matches GO_DOODAD_ULDUM_LIGHTMACHINE_04
    GO_DOODAD_ULDUM_LASERBEAMS_03   = 207665, // Matches GO_DOODAD_ULDUM_LIGHTMACHINE_03

    GO_LIFT_OF_THE_MAKERS           = 207547
};

enum HOOMisc
{
    AREA_TOMB_OF_THE_EARTHRAGER     = 4945,
    ACHIEV_VAULT_OF_LIGHTS_EVENT    = 24212, // Faster Than The Speed Of Light
    SPELL_VAULT_OF_LIGHTS_CREDIT    = 94067, // Not in DBC
};

enum HOOGlobalActions
{
    ACTION_ANRAPHET_INTRO,
    ACTION_ELEMENTAL_DIED,
    ACTION_ANRAPHET_DIED,
    ACTION_OMEGA_TRIGGER,
};

template <class AI, class T>
inline AI* GetHallsOfOriginationAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HoOScriptName);
}

#define RegisterHallsOfOriginationCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfOriginationAI)
#define RegisterHallsOfOriginationGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetHallsOfOriginationAI)

#endif // HALLS_OF_ORIGINATION_H
