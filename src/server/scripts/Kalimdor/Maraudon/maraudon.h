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

#ifndef maraudon_h__
#define maraudon_h__

#include "CreatureAIImpl.h"

#define MaraudonScriptName "instance_maraudon"

template<typename AI>
inline AI* GetMaraudonAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, MaraudonScriptName);
}

#endif // maraudon_h__
