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

#ifndef UPPERBLACKROCKSPIRE_H
#define UPPERBLACKROCKSPIRE_H

#define DataHeader "UBRS"

uint32 const EncounterCount       = 5;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_GORASHAN                 = 0,
    DATA_KYRAK                    = 1,
    DATA_RAGEWING                 = 2,
    DATA_THARBEK                  = 3,
    DATA_ZAELA                    = 4
};

enum CreatureIds
{
    BOSS_GORASHAN                  = 76413,
    BOSS_KYRAK                     = 76021,
    BOSS_RAGEWING                  = 76585,
    BOSS_THARBEK                   = 79912,
    BOSS_ZAELA                     = 77120
};

enum GameObjectIds
{
};

#endif
