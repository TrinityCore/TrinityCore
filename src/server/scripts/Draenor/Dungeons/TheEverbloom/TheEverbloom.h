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

#ifndef THEEVERBLOOM_H
#define THEEVERBLOOM_H

#define DataHeader "TEB"

uint32 const EncounterCount       = 7;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_ANCIENTPROTECTOR         = 0,
    DATA_PROTECTORDULHU           = 1,
    DATA_PROTECTORGOLA            = 2,
    DATA_ARCHMAGESOL              = 3,
    DATA_WITHERBARK               = 4,
    DATA_XERITAC                  = 5,
    DATA_YALNU                    = 6
};

enum CreatureIds
{
    BOSS_ANCIENTPROTECTOR          = 83893,
    BOSS_PROTECTORDULHU            = 83894,
    BOSS_PROTECTORGOLA             = 83892,
    BOSS_ARCHMAGESOL               = 82682,
    BOSS_WITHERBARK                = 81522,
    BOSS_XERITAC                   = 84550,
    BOSS_YALNU                     = 83846
};

enum GameObjectIds
{
};

#endif
