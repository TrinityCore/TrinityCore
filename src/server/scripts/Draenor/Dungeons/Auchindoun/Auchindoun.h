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

#ifndef AUCHINDOUN_H
#define AUCHINDOUN_H

#define GDScriptName "instance_Auchindoun"
#define DataHeader "AU"

uint32 const EncounterCount       = 4;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_AZZAKAEL                 = 0,
    DATA_NYAMI                    = 1,
    DATA_PROTECTOROFAUCH          = 2,
    DATA_TERONGOR                 = 3
};

enum CreatureIds
{
    BOSS_AZZAKAEL                  = 75927,
    BOSS_NYAMI                     = 76177,
    BOSS_PROTECTOROFAUCH     	   = 75839,
    BOSS_TERONGOR     		   = 77734
};

enum GameObjectIds
{
};

#endif
