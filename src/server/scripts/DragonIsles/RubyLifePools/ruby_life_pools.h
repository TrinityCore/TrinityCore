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

#ifndef DEF_RUBY_LIFE_POOLS_H_
#define DEF_RUBY_LIFE_POOLS_H_

#include "CreatureAIImpl.h"

#define DataHeader "RLP"
#define RLPScriptName "instance_ruby_life_pools"

uint32 const EncounterCount = 3;

enum RLPDataTypes
{
    // Encounters
    DATA_MELIDRUSSA_CHILLWORN          = 0,
    DATA_KOKIA_BLAZEHOOF               = 1,
    DATA_KYRAKKA_AND_ERKHART_STORMVEIN = 2
};

enum RLPCreatureIds
{
    // Bosses
    BOSS_MELIDRUSSA_CHILLWORN   = 188252,
    BOSS_KOKIA_BLAZEHOOF        = 189232,
    BOSS_KYRAKKA                = 190484
};

enum RLPGameObjectIds
{
    GO_FIRE_WALL                = 377194
};

template <class AI, class T>
inline AI* GetRubyLifePoolsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RLPScriptName);
}

#define RegisterRubyLifePoolsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetRubyLifePoolsAI)

#endif
