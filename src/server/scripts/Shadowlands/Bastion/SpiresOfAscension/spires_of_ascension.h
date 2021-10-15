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

#ifndef DEF_SPIRES_OF_ASCENSION_H_
#define DEF_SPIRES_OF_ASCENSION_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_spires_of_ascension"


template <class AI, class T>
inline AI* GetSpiresOfAscensionAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterSpiresOfAscensionCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSpiresOfAscensionAI)

#endif
