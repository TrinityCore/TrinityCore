/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TERRACE_OF_ENDLESS_SPRING_H_
#define TERRACE_OF_ENDLESS_SPRING_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
    DATA_KAOLAN             = 0,
    DATA_REGAIL             = 1,
    DATA_ASANI              = 2,
    DATA_TSULONG            = 3,
    DATA_LEI_SHI            = 4,
    DATA_SHA_OF_FEAR        = 5,

    MAX_DATA                = 6
};

enum eCreatures
{
    // Protectors
    NPC_KAOLAN              = 60583,
    NPC_REGAIL              = 60585,
    NPC_ASANI               = 60586,

    NPC_TSULONG             = 62442,

    NPC_LEI_SHI             = 62983,

    NPC_SHA_OF_FEAR         = 60999
};

enum eGameObjects
{
};

enum eAchievementData
{
};

#endif // TERRACE_OF_ENDLESS_SPRING_H_
