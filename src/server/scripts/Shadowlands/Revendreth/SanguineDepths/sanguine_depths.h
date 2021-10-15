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

#ifndef DEF_SANGUINE_DEPTHS_H_
#define DEF_SANGUINE_DEPTHS_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_sanquine_depths"

template <class AI, class T>
inline AI* GeSanguineDepthsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterSanguineDepthsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSanguineDepthsAI)

#endif
