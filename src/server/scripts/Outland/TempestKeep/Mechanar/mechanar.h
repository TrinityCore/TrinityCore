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

#ifndef DEF_MECHANAR_H
#define DEF_MECHANAR_H

#include "CreatureAIImpl.h"

#define MechanarScriptName "instance_mechanar"
#define DataHeader "MR"

uint32 const EncounterCount             = 5;

enum MRDataTypes
{
    DATA_GATEWATCHER_GYROKILL           = 0,
    DATA_GATEWATCHER_IRON_HAND          = 1,
    DATA_MECHANOLORD_CAPACITUS          = 2,
    DATA_NETHERMANCER_SEPRETHREA        = 3,
    DATA_PATHALEON_THE_CALCULATOR       = 4
};

enum MRGameobjectIds
{
    GO_DOOR_MOARG_1                     = 184632,
    GO_DOOR_MOARG_2                     = 184322,
    GO_DOOR_NETHERMANCER                = 184449
};

template <class AI, class T>
inline AI* GetMechanarAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MechanarScriptName);
}

#endif
