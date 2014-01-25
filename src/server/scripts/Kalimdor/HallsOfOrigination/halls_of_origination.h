/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#define HoOScriptName "instance_halls_of_origination"

uint32 const EncounterCount = 12;

enum Data
{
    // Bosses
    DATA_TEMPLE_GUARDIAN_ANHUUR,
    DATA_EARTHRAGER_PTAH,
    DATA_VAULT_OF_LIGHTS,
    DATA_FIRE_WARDEN,
    DATA_EARTH_WARDEN,
    DATA_WATER_WARDEN,
    DATA_AIR_WARDEN,
    DATA_ANRAPHET,
    DATA_ISISET,
    DATA_AMMUNAE,
    DATA_SETESH,
    DATA_RAJH,

    // Temple Guardian Anhuur
    DATA_ANHUUR_GUID,
    DATA_ANHUUR_LEFT_BEACON,
    DATA_ANHUUR_RIGHT_BEACON,
    DATA_ANHUUR_BRIDGE,
    DATA_ANHUUR_DOOR,

    // Anraphet
    DATA_BRANN_0_GUID,
    DATA_DEAD_ELEMENTALS,
    DATA_ANRAPHET_GUID,
};

enum Creatures
{
    BOSS_TEMPLE_GUARDIAN_ANHUUR     = 39425,
    NPC_CAVE_IN_STALKER             = 40183,
    NPC_SEARING_LIGHT               = 40283,

    BOSS_EARTHRAGER_PTAH            = 39428,
    NPC_BEETLE_STALKER              = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_JEWELED_SCARAB              = 40458,
    NPC_DUSTBONE_HORROR             = 40450,
    NPC_QUICKSAND                   = 40503, // Summoned by a spell not in dbc (75550)

    BOSS_ANRAPHET                   = 39788,
    NPC_FIRE_WARDEN                 = 39800,
    NPC_EARTH_WARDEN                = 39801,
    NPC_WATER_WARDEN                = 39802,
    NPC_AIR_WARDEN                  = 39803,

    WARDEN_ENTRY_DATA_DELTA         = NPC_FIRE_WARDEN - DATA_FIRE_WARDEN,

    NPC_BRANN_BRONZEBEARD_0         = 39908,
    NPC_OMEGA_STANCE                = 41194,
};

enum GameObjects
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
};

enum Misc
{
    AREA_TOMB_OF_THE_EARTHRAGER     = 5610,
    ACHIEV_VAULT_OF_LIGHTS_EVENT    = 24212, // Faster Than The Speed Of Light
    SPELL_VAULT_OF_LIGHTS_CREDIT    = 94067, // Not in DBC
};

enum GlobalActions
{
    ACTION_ANRAPHET_INTRO,
    ACTION_ELEMENTAL_DIED,
    ACTION_ANRAPHET_DIED,
    ACTION_OMEGA_TRIGGER,
};

template<class AI>
CreatureAI* GetHallsOfOriginationAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(HoOScriptName))
                return new AI(creature);
    return NULL;
}

#endif // HALLS_OF_ORIGINATION_H
