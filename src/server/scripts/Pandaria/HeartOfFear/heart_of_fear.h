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

#ifndef HEART_OF_FEAR_H_
#define HEART_OF_FEAR_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"


enum eData
{
    DATA_ZORLOCK            = 0,
    DATA_TAYAK              = 1,
    DATA_GARALON            = 2,
    DATA_UNSOK              = 3,
    DATA_SHEKZEER           = 4,
    DATA_MELJARAK           = 5,
    DATA_MAX_BOSS_DATA      = 6,

    // Tayak
    DATA_TAYAK_SIDE         = 7,

    MAX_DATA                = 8
};

enum eActions
{
};

enum eCreatures
{
    // Zorlock
    NPC_ZORLOCK             = 62980,
    NPC_SONIC_RING          = 62727,
    NPC_SONIC_RING_2        = 67163, // Don't know the difference between those but noted here just in case
    NPC_SONIC_RING_3        = 62726,
    NPC_SONIC_RING_4        = 67164,
    NPC_SONIC_RING_5        = 63341,
    NPC_SONIC_RING_6        = 63340,
    NPC_SONIC_RING_7        = 62689,

    // Tayak
    NPC_TAYAK               = 62543,
    NPC_TEMPEST_SLASH       = 62908,
    
    NPC_S_U_TORNADO_ALL     = 63567, // Tornado spawn under all players
    NPC_S_U_TORNADOS        = 63299, // On Offi there is 6 different tornados
    NPC_S_U_TORNADO_SPAWNER = 0,
    
    // Garalon
    NPC_GARALON             = 62164,

    // Unsok
    NPC_UNSOK               = 62397,

    // Meljarak
    NPC_MELJARAK            = 62837,

    // Shekzeer
    NPC_SHEKZEER            = 62511,
};

enum eGameObjects
{
};

enum eAchievementData
{
};

enum sharedSpells
{
};

#endif // MOGUSHAN_VAULT_H_
