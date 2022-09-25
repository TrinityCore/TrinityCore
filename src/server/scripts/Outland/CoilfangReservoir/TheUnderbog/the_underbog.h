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

#ifndef the_underbog_h__
#define the_underbog_h__

#include "CreatureAIImpl.h"

#define TheUndebogDataHeader "UBOG"
#define TheUndebogScriptName "instance_the_underbog"

constexpr uint32 TheUnderbogBossCount = 4;

enum TheUnderbogDataId
{
    DATA_HUNGARFEN          = 0,
    DATA_GHAZAN             = 1,
    DATA_SWAMPLORD_MUSELEK  = 2,
    DATA_THE_BLACK_STALKER  = 3
};

enum TheUnderbogCreatureId
{
    NPC_GHAZAN              = 18105,
    NPC_SWAMPLORD_MUSELEK   = 17826
};

template <class AI, class T>
inline AI* GetTheUnderbogAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TheUndebogScriptName);
}

#define RegisterTheUnderbogCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTheUnderbogAI)

#endif // the_underbog_h__
