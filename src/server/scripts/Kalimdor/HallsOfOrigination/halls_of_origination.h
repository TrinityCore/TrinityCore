/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 Trinity <http://www.projecttrinity.org/>
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

#ifndef DEF_HALLS_OF_ORIGINATION_H
#define DEF_HALLS_OF_ORIGINATION_H

enum Data
{
    DATA_TEMPLE_GUARDIAN_ANHUUR_EVENT,
    DATA_EARTHRAGER_PTAH_EVENT,
    DATA_ANRAPHET_EVENT,
    DATA_ISISET_EVENT,
    DATA_AMMUNAE_EVENT,
    DATA_SETESH_EVENT,
    DATA_RAJH_EVENT,
    DATA_TEAM_IN_INSTANCE,
    DATA_WATER_WARDEN,
    DATA_EARTH_WARDEN,
    DATA_FLAME_WARDEN,
    DATA_AIR_WARDEN,

    DATA_BRANN_ELEMENTALS,
    DATA_BRANN_EVENT,
    DATA_ANRAPHET_INTRO,

    // Temple Guardian Anhuur
    DATA_ANHUUR_GUID,
    DATA_ANHUUR_LEFT_BEACON,
    DATA_ANHUUR_RIGHT_BEACON,
    DATA_ANHUUR_BRIDGE,
    DATA_ANHUUR_DOOR
};

enum Data64
{
    DATA_TEMPLE_GUARDIAN_ANHUUR,
    DATA_EARTHRAGER_PTAH,
    DATA_ANRAPHET,
    DATA_ISISET,
    DATA_AMMUNAE,
    DATA_SETESH,
    DATA_RAJH,
};

enum GameObjects
{
    GO_ORIGINATION_ELEVATOR,
    GO_LARGE_STONE_OBELISK          = 207410,
    GO_ULDUM_DOOR_14                = 202306,
    GO_ANHUURS_DOOR                 = 202307,
    GO_ANHUURS_BRIDGE               = 206506,
    GO_SUN_MIRROR                   = 207726,
    GO_VAULT_OF_LIGHTS_BOSS_DOOR    = 202314,
    GO_VAULT_OF_LIGHTS_ENTRANCE     = 202313,
    GO_LIGHTMACHINE_1               = 207375,
    GO_LIGHTMACHINE_2               = 207374,
    GO_LIGHTMACHINE_3               = 207376,
    GO_LIGHTMACHINE_4               = 207377,
    GO_HOO_TELEPORTER               = 204979,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_TEMPLE_GUARDIAN_ANHUUR = 39425,
    BOSS_EARTHRAGER_PTAH        = 39428,
    BOSS_ANRAPHET               = 39788,
    BOSS_ISISET                 = 39587,
    BOSS_AMMUNAE                = 39731,
    BOSS_SETESH                 = 39732,
    BOSS_RAJH                   = 39378,

    // Trash Mobs

    NPC_BLISTERING_SCARAB       = 40310,
    NPC_BLOODPETAL_BLOSSOM      = 40620,
    NPC_DUSTBONE_TORMENTOR      = 40311,
    NPC_EARTH_WARDEN            = 39801,
    NPC_FLAME_WARDEN            = 39800,
    NPC_FLUX_ANIMATOR           = 40033,
    NPC_LIFEWARDEN_NYMPH        = 40715,
    NPC_LIVING_VINE             = 40668,
    NPC_SPATIAL_ANOMALY         = 40170,
    NPC_TEMPLE_SWIFTSTALKER     = 48139,
    NPC_TEMPLE_SHADOWLANCER     = 48141,
    NPC_TEMPLE_RUNECASTER       = 48140,
    NPC_TEMPLE_FIRESHAPER       = 48143,
    NPC_VENOMOUS_SKITTERER      = 39440,
    NPC_WATER_WARDEN            = 39802,
    NPC_AIR_WARDEN              = 39803,
    NPC_PIT_SNAKE                = 39444,
    NPC_DUSTBONE_HORROR         = 40450,
    NPC_JEWELED_SCARAB          = 40458,
    NPC_BEETLE_STALKER          = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_QUICKSAND               = 40503, // Summoned by a spell not in dbc (75550)
    NPC_INFERNO_TRIGGER         = 47040,
    NPC_SOLAR_WIND_VORTEX       = 39635,
    NPC_SOLAR_WIND              = 47922,

    // Various NPCs

    NPC_BRANN_BRONZEBEARD       = 49941,
    NPC_BRANN_ANRAPHET          = 39908,
    NPC_SEARING_LIGHT            = 40283
};

enum AreaIds
{
    AREA_TOMB_OF_THE_EARTHRAGER = 5610,
};

#endif
