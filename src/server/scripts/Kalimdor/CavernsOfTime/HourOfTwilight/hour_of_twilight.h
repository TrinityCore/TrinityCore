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

#ifndef DEF_HOUROFTWILIGHT_H
#define DEF_HOUROFTWILIGHT_H

#include "CreatureAIImpl.h"
#include "Define.h"

#define DataHeader "HOT"
#define HOTScriptName "instance_hour_of_twilight"

uint32 const EncounterCount = 3;

enum HOTDataTypes
{
    // Bosses
    DATA_ARCURION               = 0,
    DATA_ASIRA_DAWNSLAYER       = 1,
    DATA_ARCHBISHOP_BENEDICTUS  = 2
};

enum HOTCreatures
{
};

enum HOTGameObjectIds
{
};

template<class AI>
AI* GetHourOfTwilightAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, HOTScriptName);
}

#define RegisterHourOfTwilightCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHourOfTwilightAI)

#endif // DEF_HOUROFTWILIGHT_H
