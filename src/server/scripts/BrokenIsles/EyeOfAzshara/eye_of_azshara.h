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

#ifndef DEF_EYE_OF_AZSHARA_H_
#define DEF_EYE_OF_AZSHARA_H_

#include "CreatureAIImpl.h"

#define DataHeader "EyeOfAzshara"
#define EOAScriptName "instance_eye_of_azshara"

uint32 const EncounterCount = 5;

enum EOADataTypes
{
    // Encounters
    DATA_WARLORD_PARJESH  = 0,
    DATA_LADY_HATECOIL,
    DATA_KING_DEEPBEARD,
    DATA_SERPENTRIX,
    DATA_WRATH_OF_AZSHARA
};

enum EOACreatureIds
{
    // Bosses
    BOSS_WARLORD_PARJESH  = 91784,
    BOSS_LADY_HATECOIL    = 91789,
    BOSS_KING_DEEPBEARD   = 91797,
    BOSS_SERPENTRIX       = 91808,
    BOSS_WRATH_OF_AZSHARA = 96028
};

enum EOAGameObjectIds
{
    GO_WATER_DOOR_1       = 246983,
    GO_WATER_DOOR_2       = 246982
};

template <class AI, class T>
inline AI* GetEyeOfAzsharaAI(T* obj)
{
    return GetInstanceAI<AI>(obj, EOAScriptName);
}

#define RegisterEyeOfAzsharaCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetEyeOfAzsharaAI)

#endif // DEF_EYE_OF_AZSHARA_H_
