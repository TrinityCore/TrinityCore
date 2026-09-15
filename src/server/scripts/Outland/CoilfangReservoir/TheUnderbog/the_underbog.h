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

#ifndef DEF_THE_UNDERBOG_H
#define DEF_THE_UNDERBOG_H

#include "CreatureAIImpl.h"

#define DataHeader "UBOG"
#define UBOGScriptName "instance_the_underbog"

constexpr uint32 EncounterCount = 4;

enum UBOGDataTypes
{
    DATA_HUNGARFEN          = 0,
    DATA_GHAZAN             = 1,
    DATA_SWAMPLORD_MUSELEK  = 2,
    DATA_THE_BLACK_STALKER  = 3
};

enum UBOGCreatureIds
{
    NPC_GHAZAN              = 18105
};

template <class AI, class T>
inline AI* GetTheUnderbogAI(T* obj)
{
    return GetInstanceAI<AI>(obj, UBOGScriptName);
}

#define RegisterTheUnderbogCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTheUnderbogAI)

#endif // DEF_THE_UNDERBOG_H
