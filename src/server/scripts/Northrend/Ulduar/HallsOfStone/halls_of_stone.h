/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef HALLS_OF_STONE_H_
#define HALLS_OF_STONE_H_

#include "CreatureAIImpl.h"

#define HoSScriptName "instance_halls_of_stone"
#define DataHeader    "HOS"

uint32 const EncounterCount = 4;

enum HOSDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_KRYSTALLUS             = 0,
    DATA_MAIDEN_OF_GRIEF        = 1,
    DATA_TRIBUNAL_OF_AGES       = 2,
    DATA_SJONNIR                = 3,

    // Additional data
    DATA_KADDRAK                = 4,
    DATA_MARNAK                 = 5,
    DATA_ABEDNEUM               = 6,
    DATA_GO_TRIBUNAL_CONSOLE    = 7,
    DATA_GO_KADDRAK             = 8,
    DATA_GO_MARNAK              = 9,
    DATA_GO_ABEDNEUM            = 10,
    DATA_GO_SKY_FLOOR           = 11
};

enum HOSCreatureIds
{
    NPC_MAIDEN                  = 27975,
    NPC_KRYSTALLUS              = 27977,
    NPC_SJONNIR                 = 27978,
    NPC_MARNAK                  = 30897,
    NPC_KADDRAK                 = 30898,
    NPC_ABEDNEUM                = 30899,
    NPC_BRANN                   = 28070
};

enum HOSGameObjectIds
{
    GO_ABEDNEUM                 = 191669,
    GO_MARNAK                   = 191670,
    GO_KADDRAK                  = 191671,
    GO_MAIDEN_DOOR              = 191292,
    GO_BRANN_DOOR               = 191295,
    GO_SJONNIR_DOOR             = 191296,
    GO_TRIBUNAL_CONSOLE         = 193907,
    GO_TRIBUNAL_CHEST           = 190586,
    GO_TRIBUNAL_CHEST_HERO      = 193996,
    GO_TRIBUNAL_SKY_FLOOR       = 191527
};

template<typename AI>
inline AI* GetHallsOfStoneAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, HoSScriptName);
}

#endif // HALLS_OF_STONE_H_
