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

#ifndef DEF_EYE_OF_ETERNITY_H
#define DEF_EYE_OF_ETERNITY_H

enum InstanceData
{
    DATA_MALYGOS_EVENT,
    MAX_ENCOUNTER,

    DATA_VORTEX_HANDLING,
    DATA_POWER_SPARKS_HANDLING,
    DATA_RESPAWN_IRIS
};

enum InstanceData64
{
    DATA_TRIGGER,
    DATA_MALYGOS,
    DATA_PLATFORM,
    DATA_ALEXSTRASZA_BUNNY_GUID,
    DATA_HEART_OF_MAGIC_GUID,
    DATA_FOCUSING_IRIS_GUID,
    DATA_GIFT_BOX_BUNNY_GUID
};

enum InstanceNpcs
{
    NPC_MALYGOS             = 28859,
    NPC_VORTEX_TRIGGER      = 30090,
    NPC_PORTAL_TRIGGER      = 30118,
    NPC_POWER_SPARK         = 30084,
    NPC_HOVER_DISK_MELEE    = 30234,
    NPC_HOVER_DISK_CASTER   = 30248,
    NPC_ARCANE_OVERLOAD     = 30282,
    NPC_WYRMREST_SKYTALON   = 30161,
    NPC_ALEXSTRASZA         = 32295,
    NPC_ALEXSTRASZA_BUNNY   = 31253,
    NPC_ALEXSTRASZAS_GIFT   = 32448,
    NPC_SURGE_OF_POWER      = 30334
};

enum InstanceGameObjects
{
    GO_NEXUS_RAID_PLATFORM      = 193070,
    GO_EXIT_PORTAL              = 193908,
    GO_FOCUSING_IRIS_10         = 193958,
    GO_FOCUSING_IRIS_25         = 193960,
    GO_ALEXSTRASZA_S_GIFT_10    = 193905,
    GO_ALEXSTRASZA_S_GIFT_25    = 193967,
    GO_HEART_OF_MAGIC_10        = 194158,
    GO_HEART_OF_MAGIC_25        = 194159
};

enum InstanceEvents
{
    EVENT_FOCUSING_IRIS = 20711
};

enum InstanceSpells
{
    SPELL_VORTEX_4                        = 55853, // damage | used to enter to the vehicle
    SPELL_VORTEX_5                        = 56263, // damage | used to enter to the vehicle
    SPELL_PORTAL_OPENED                   = 61236,
    SPELL_RIDE_RED_DRAGON_TRIGGERED       = 56072,
    SPELL_IRIS_OPENED                     = 61012  // visual when starting encounter
};

#endif
