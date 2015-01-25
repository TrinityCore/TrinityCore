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

#ifndef DEF_SHATTERED_H
#define DEF_SHATTERED_H

#define DataHeader "SH"

uint32 const EncounterCount          = 3;

enum DataTypes
{
    DATA_NETHEKURSE                  = 1,
    DATA_OMROGG                      = 2,
    DATA_KARGATH                     = 3
};

enum CreatureIds
{
    NPC_GRAND_WARLOCK_NETHEKURSE     = 16807
};

enum GameobjectIds
{
    GO_GRAND_WARLOCK_CHAMBER_DOOR_1  = 182539,
    GO_GRAND_WARLOCK_CHAMBER_DOOR_2  = 182540
};

#endif
