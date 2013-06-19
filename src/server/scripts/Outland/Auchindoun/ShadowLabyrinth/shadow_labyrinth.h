/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_SHADOW_LABYRINTH_H
#define DEF_SHADOW_LABYRINTH_H

uint32 const EncounterCount             = 5;

enum DataTypes
{
    TYPE_HELLMAW                        = 1,
    TYPE_OVERSEER                       = 2,
    DATA_BLACKHEARTTHEINCITEREVENT      = 3,
    DATA_GRANDMASTERVORPILEVENT         = 4,
    DATA_MURMUREVENT                    = 5,
    DATA_GRANDMASTERVORPIL              = 6
};

enum Objects
{
    REFECTORY_DOOR                      = 183296, // door opened when blackheart the inciter dies
    SCREAMING_HALL_DOOR                 = 183295  // door opened when grandmaster vorpil dies
};

#endif

