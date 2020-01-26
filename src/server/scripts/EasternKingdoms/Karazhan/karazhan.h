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

#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

#include "CreatureAIImpl.h"

#define KZScriptName "instance_karazhan"
#define DataHeader "KZ"

uint32 const EncounterCount = 12;

enum KZDataTypes
{
    DATA_ATTUMEN                    = 0,
    DATA_MOROES                     = 1,
    DATA_MAIDEN_OF_VIRTUE           = 2,
    DATA_OPTIONAL_BOSS              = 3,
    DATA_OPERA_PERFORMANCE          = 4,
    DATA_CURATOR                    = 5,
    DATA_ARAN                       = 6,
    DATA_TERESTIAN                  = 7,
    DATA_NETHERSPITE                = 8,
    DATA_CHESS                      = 9,
    DATA_MALCHEZZAR                 = 10,
    DATA_NIGHTBANE                  = 11,

    DATA_OPERA_OZ_DEATHCOUNT        = 14,

    DATA_KILREK                     = 15,
    DATA_GO_CURTAINS                = 18,
    DATA_GO_STAGEDOORLEFT           = 19,
    DATA_GO_STAGEDOORRIGHT          = 20,
    DATA_GO_LIBRARY_DOOR            = 21,
    DATA_GO_MASSIVE_DOOR            = 22,
    DATA_GO_NETHER_DOOR             = 23,
    DATA_GO_GAME_DOOR               = 24,
    DATA_GO_GAME_EXIT_DOOR          = 25,

    DATA_IMAGE_OF_MEDIVH            = 26,
    DATA_MASTERS_TERRACE_DOOR_1     = 27,
    DATA_MASTERS_TERRACE_DOOR_2     = 28,
    DATA_GO_SIDE_ENTRANCE_DOOR      = 29,
    DATA_GO_BLACKENED_URN           = 30
};

enum KZOperaEvents
{
    EVENT_OZ                        = 1,
    EVENT_HOOD                      = 2,
    EVENT_RAJ                       = 3
};

enum KZMiscCreatures
{
    NPC_HYAKISS_THE_LURKER          = 16179,
    NPC_ROKAD_THE_RAVAGER           = 16181,
    NPC_SHADIKITH_THE_GLIDER        = 16180,
    NPC_TERESTIAN_ILLHOOF           = 15688,
    NPC_MOROES                      = 15687,
    NPC_NIGHTBANE                   = 17225,
    NPC_ATTUMEN_UNMOUNTED           = 15550,
    NPC_ATTUMEN_MOUNTED             = 16152,
    NPC_MIDNIGHT                    = 16151,

    // Trash
    NPC_COLDMIST_WIDOW              = 16171,
    NPC_COLDMIST_STALKER            = 16170,
    NPC_SHADOWBAT                   = 16173,
    NPC_VAMPIRIC_SHADOWBAT          = 16175,
    NPC_GREATER_SHADOWBAT           = 16174,
    NPC_PHASE_HOUND                 = 16178,
    NPC_DREADBEAST                  = 16177,
    NPC_SHADOWBEAST                 = 16176,
    NPC_KILREK                      = 17229
};

enum KZGameObjectIds
{
    GO_STAGE_CURTAIN                = 183932,
    GO_STAGE_DOOR_LEFT              = 184278,
    GO_STAGE_DOOR_RIGHT             = 184279,
    GO_PRIVATE_LIBRARY_DOOR         = 184517,
    GO_MASSIVE_DOOR                 = 185521,
    GO_GAMESMAN_HALL_DOOR           = 184276,
    GO_GAMESMAN_HALL_EXIT_DOOR      = 184277,
    GO_NETHERSPACE_DOOR             = 185134,
    GO_MASTERS_TERRACE_DOOR         = 184274,
    GO_MASTERS_TERRACE_DOOR2        = 184280,
    GO_SIDE_ENTRANCE_DOOR           = 184275,
    GO_DUST_COVERED_CHEST           = 185119,
    GO_BLACKENED_URN                = 194092
};

enum KZMisc
{
    OPTIONAL_BOSS_REQUIRED_DEATH_COUNT = 50
};

template<typename AI>
inline AI* GetKarazhanAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, KZScriptName);
}

#endif
