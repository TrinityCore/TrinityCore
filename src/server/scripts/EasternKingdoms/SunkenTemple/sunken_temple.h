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

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

#include "CreatureAIImpl.h"

#define STScriptName "instance_sunken_temple"
#define DataHeader "ST"

uint32 const EncounterCount = 1;

enum STDataTypes
{
    DATA_AVATAR_OF_HAKKAR = 0,

    DATA_ETERNAL_FLAME    = 9,
    EVENT_STATE           = 10
};

enum STGameObjectIds
{
    GO_ATALAI_STATUE1 = 148830,
    GO_ATALAI_STATUE2 = 148831,
    GO_ATALAI_STATUE3 = 148832,
    GO_ATALAI_STATUE4 = 148833,
    GO_ATALAI_STATUE5 = 148834,
    GO_ATALAI_STATUE6 = 148835,
    GO_ATALAI_LIGHT1 = 148883,
    GO_ATALAI_LIGHT2 = 148937,

    GO_ETERNAL_FLAME_1 = 148418,
    GO_ETERNAL_FLAME_2 = 148419,
    GO_ETERNAL_FLAME_3 = 148420,
    GO_ETERNAL_FLAME_4 = 148421,
    GO_EVIL_GOD_SUMMONING_CIRCLE = 148998,
};

enum STCreatureIds
{
    NPC_HAKKARI_MINION       = 8437,
    NPC_HAKKARI_BLOODKEEPER  = 8438, //Hakkari Bloodkeeper
    NPC_SHADE_OF_HAKKAR      = 8440, //Shade of Hakkar
    NPC_AVATAR_OF_HAKKAR     = 8443,
    NPC_NIGHTMARE_SUPPRESSOR = 8497, //Nightmare Suppressor
    NPC_ATALALARION          = 8580,
};

enum STInstanceTexts
{
    // Shade of Hakkar
    SAY_SPAWN_SHADE = 0,
    SAY_ETHERNAL_FLAME_SHADE1 = 1,
    SAY_ETHERNAL_FLAME_SHADE2 = 2,
    SAY_ETHERNAL_FLAME_SHADE3 = 3,
};

enum STShareActions
{
    ACTION_FIGHT_STATE_AVATAR        = -1,
    ACTION_CAST_SUPPRESSOR_NIGHTMARE = -2,
    ACTION_REMOVE_SUPPRESSOR_AVATAR  = -3
};

enum STShareSpells
{
    SPELL_SUPPRESSION = 12623
};

//struct Position;

Position const AvatarHakkarSpawnPos = { -467.107f, 273.063f, -90.449f, 3.0f };

template <class AI, class T>
inline AI* GetSunkenTempleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, STScriptName);
}

#endif
