/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_OLD_HILLSBRAD_H
#define DEF_OLD_HILLSBRAD_H

#include "CreatureAIImpl.h"

#define OHScriptName "instance_old_hillsbrad"
#define DataHeader "OH"

enum OHDataTypes
{
    TYPE_BARREL_DIVERSION   = 1,
    TYPE_THRALL_EVENT       = 2,
    TYPE_THRALL_PART1       = 3,
    TYPE_THRALL_PART2       = 4,
    TYPE_THRALL_PART3       = 5,
    TYPE_THRALL_PART4       = 6,

    DATA_THRALL             = 7,
    DATA_TARETHA            = 8,
    DATA_EPOCH              = 9

};

enum OHWorldStateIds
{
    WORLD_STATE_OH              = 2436
};


template<typename AI>
inline AI* GetOldHillsbradAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, OHScriptName);
}


#endif
