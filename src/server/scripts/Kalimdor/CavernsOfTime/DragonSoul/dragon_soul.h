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

#ifndef DEF_DRAGONSOUL_H
#define DEF_DRAGONSOUL_H

#include "Define.h"

#define DataHeader "DS"
#define DSScriptName "instance_dragon_soul"

uint32 const EncounterCount = 8;

enum DSDataTypes
{
    // Bosses
    DATA_MORCHOK                = 0,
    DATA_WARLORD_ZONOZZ         = 1,
    DATA_YORSAHJ_THE_UNSLEEPING = 2,
    DATA_HAGARA_THE_STORMBINDER = 3,
    DATA_ULTRAXION              = 4,
    DATA_WARMASTER_BLACKHORN    = 5,
    DATA_SPINE_OF_DEATHWING     = 6,
    DATA_MADNESS_OF_DEATHWING   = 7
};

enum DSCreatures
{
};

enum DSGameObjectIds
{
};

template<class AI>
AI* GetDragonSoulAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, DSScriptName);
}

#define RegisterDragonSoulCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDragonSoulAI)

#endif // DEF_DRAGONSOUL_H
