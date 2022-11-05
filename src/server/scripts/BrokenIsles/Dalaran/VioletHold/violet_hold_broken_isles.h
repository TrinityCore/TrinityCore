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

#ifndef DEF_VIOLET_HOLD_BROKEN_ISLES_H
#define DEF_VIOLET_HOLD_BROKEN_ISLES_H

#include "CreatureAIImpl.h"

#define SCScriptName "instance_violet_hold_broken_isles"
#define DataHeader "VioletHoldBrokenIsles"

enum SCDataTypes
{
    // Encounter States/Boss GUIDs

    // Additional Data

};

enum SCMisc
{

};

template<typename AI>
inline AI* GetVioletHoldBrokenIslesAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SCScriptName);
}

#endif // DEF_VIOLET_HOLD_BROKEN_ISLES_H
