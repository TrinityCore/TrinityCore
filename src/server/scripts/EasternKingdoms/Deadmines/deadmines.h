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

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#define DataHeader "DM"
#define DMScriptName "instance_deadmines"

uint32 const EncounterCount = 6;

enum DMDataTypes
{
    // Encounters
    DATA_GLUBTOK            = 0,
    DATA_HELIX_GEARBREAKER  = 1,
    DATA_FOE_REAPER_5000    = 2,
    DATA_ADMIRAL_RIPSNARL   = 3,
    DATA_CAPTAIN_COOKIE     = 4,
    DATA_VANESSA_VAN_CLEEF  = 5,

    DATA_TEAM_IN_INSTANCE   = 6,
    DATA_FIREWALL_PLATTER   = 7,
    DATA_LUMBERING_OAF      = 8
};

enum DMCreatures
{
    // Bosses
    BOSS_GLUBTOK                    = 47162,
    BOSS_HELIX_GEARBREAKER          = 47296,

    // Horde Creatures
    NPC_SLINKY_SHARPSHIV            = 46906,
    NPC_KAGTHA                      = 46889,
    NPC_MISS_MAYHEM                 = 46902,
    NPC_SHATTERED_HAND_ASSASSIN     = 46890,
    NPC_MAYHEM_REAPER_PROTOTYPE     = 46903,

    // Alliance Creatures
    NPC_STORMWIND_INVESTIGATOR      = 46614,
    NPC_CRIME_SCENE_ALARM_O_BOT     = 46613,
    NPC_STORMWIND_DEFENDER          = 50595,
    NPC_LIEUTENANT_HORATIO_LAINE    = 46612,
    NPC_QUARTERMASTER_LEWIS         = 491,

    // Encounter Related
    NPC_GENERAL_PURPOSE_DUMMY_JMF   = 45979,
    NPC_GLUBTOK_FIREWALL_PLATTER    = 48974,
    NPC_FIREWALL_PLATTER_1A         = 48975,
    NPC_FIREWALL_PLATTER_1B         = 49039,
    NPC_FIREWALL_PLATTER_1C         = 49040,
    NPC_FIREWALL_PLATTER_2A         = 48976,
    NPC_FIREWALL_PLATTER_2B         = 49041,
    NPC_FIREWALL_PLATTER_2C         = 49042,
    NPC_GENERAL_PURPOSE_BUNNY_L2    = 47242,
    NPC_FIRE_BLOSSOM_BUNNY          = 47282,
    NPC_FROST_BLOSSOM_BUNNY         = 47284,
    NPC_LUMBERING_OAF               = 47297,
    NPC_HELIX_CREW                  = 49139,
    NPC_STICKY_BOMB                 = 47314
};

enum DMGameObjects
{
    GO_FACTORY_DOOR     = 13965,
    GO_IRONCLAD_DOOR    = 16397,
    GO_DEFIAS_CANNON    = 16398,
    GO_DOOR_LEVER       = 101833,
    GO_MAST_ROOM_DOOR   = 16400,
    GO_HEAVY_DOOR       = 17153
};


template<class AI>
AI* GetDeadminesAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, DMScriptName);
}

#endif
