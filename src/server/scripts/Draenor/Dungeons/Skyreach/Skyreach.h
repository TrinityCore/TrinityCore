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

#ifndef SKYREACH_H
#define SKYREACH_H

#define DataHeader "SR"

uint32 const EncounterCount       = 4;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_ARAKNATH                 = 0,
    DATA_RANJIT                   = 1,
    DATA_RUKHRAN                  = 2,
    DATA_VIRYX                    = 3
};

enum CreatureIds
{
    BOSS_ARAKNATH                  = 76141,
    BOSS_RANJIT                    = 75964,
    BOSS_RUKHRAN                   = 76143,
    BOSS_VIRYX                     = 76266
};

enum GameObjectIds
{
};

#endif
