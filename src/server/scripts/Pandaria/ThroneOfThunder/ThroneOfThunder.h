/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ThroneOfThunder_H
#define ThroneOfThunder_H

#define DataHeader "TOT"

uint32 const EncounterCount       = 13;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_Jinrokh                   = 0,
    DATA_Horridon                  = 1,
    DATA_Council                   = 2,
    DATA_Tortos                    = 3,
    DATA_Megaera                   = 4,
    DATA_JiKun                     = 5,
    DATA_Durumu                    = 6,
    DATA_Primordius                = 7,
    DATA_DarkAnimus                = 8,
    DATA_IronQon                   = 9,
    DATA_TwinConsorts              = 10,
    DATA_LeiShen                   = 11,
    DATA_Raden                     = 12
};

enum CreatureIds
{
    BOSS_Jinrokh                   = 69465,
    BOSS_Horridon                  = 68476,
    BOSS_Council                   = 69132,
    BOSS_Tortos                    = 67977,
    BOSS_Megaera                   = 68065,
    BOSS_JiKun                     = 69712,
    BOSS_Durumu                    = 68036,
    BOSS_Primordius                = 69017,
    BOSS_DarkAnimus                = 69427,
    BOSS_IronQon                   = 68078,
    BOSS_TwinConsorts              = 68905,
    BOSS_LeiShen                   = 68397,
    BOSS_Raden                     = 69473
};

enum GameObjectIds
{
};

#endif
