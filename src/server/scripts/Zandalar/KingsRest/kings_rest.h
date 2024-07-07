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

#ifndef DEF_KINGS_REST_H_
#define DEF_KINGS_REST_H_

#include "CreatureAIImpl.h"

#define DataHeader "KingsRest"
#define KingsRestScriptName "instance_kings_rest"

uint32 const EncounterCount = 4;

enum KingsRestDataTypes
{
    // Encounters
    DATA_GOLDEN_SERPENT        = 0,
    DATA_MCHIMBA_THE_EMBALMER,
    DATA_COUNCIL_OF_TRIBES,
    DATA_KING_DAZAR,

    // Council of Tribes
    DATA_AKAALI_THE_CONQUEROR,
    DATA_ZANAZAL_THE_WISE,
    DATA_KULA_THE_BUTCHER,

    // GameObjects
    DATA_KINGS_REST_INTRO_DOOR,
    DATA_KINGS_REST_LIQUID_POOL,
};

enum KingsRestCreatureIds
{
    // Bosses
    BOSS_GOLDEN_SERPENT         = 135322,
    BOSS_AKAALI_THE_CONQUEROR   = 135470,
    BOSS_ZANAZAL_THE_WISE       = 135472,
    BOSS_KULA_THE_BUTCHER       = 135475,
    BOSS_MCHIMBA_THE_EMBALMER   = 134993,
    BOSS_KING_DAZAR             = 136160
};

enum KingsRestGameObjectIds
{
    GO_KINGS_REST_ENTRYWAY_DOOR          = 282652,
    GO_KINGS_REST_SERPENT_POST_DOOR      = 287392,
    GO_KINGS_REST_LIQUID_GOLD_POOL       = 289347
};

template <class AI, class T>
inline AI* GetKingsRestAI(T* obj)
{
    return GetInstanceAI<AI>(obj, KingsRestScriptName);
}

#define RegisterKingsRestCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetKingsRestAI)

#endif
