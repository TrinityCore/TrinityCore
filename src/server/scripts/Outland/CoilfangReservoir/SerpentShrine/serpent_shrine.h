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

#ifndef DEF_SERPENT_SHRINE_H
#define DEF_SERPENT_SHRINE_H

#define DataHeader "SS"

enum WaterEventState
{
    WATERSTATE_NONE     = 0,
    WATERSTATE_FRENZY   = 1,
    WATERSTATE_SCALDING = 2
};

enum DataTypes
{
    DATA_CANSTARTPHASE3             = 1,
    DATA_CARIBDIS                   = 2,
    DATA_HYDROSSTHEUNSTABLEEVENT    = 3,
    DATA_KARATHRESS                 = 4,
    DATA_KARATHRESSEVENT            = 5,
    DATA_KARATHRESSEVENT_STARTER    = 6,
    DATA_LADYVASHJ                  = 7,
    DATA_LADYVASHJEVENT             = 8,
    DATA_LEOTHERASTHEBLINDEVENT     = 9,
    DATA_MOROGRIMTIDEWALKEREVENT    = 10,
    DATA_SHARKKIS                   = 11,
    DATA_SHIELDGENERATOR1           = 12,
    DATA_SHIELDGENERATOR2           = 13,
    DATA_SHIELDGENERATOR3           = 14,
    DATA_SHIELDGENERATOR4           = 15,
    DATA_THELURKERBELOW             = 16,
    DATA_THELURKERBELOWEVENT        = 17,
    DATA_TIDALVESS                  = 18,
    DATA_FATHOMLORDKARATHRESSEVENT  = 19,
    DATA_LEOTHERAS                  = 20,
    DATA_LEOTHERAS_EVENT_STARTER    = 21,
    DATA_CONTROL_CONSOLE            = 22,
    DATA_STRANGE_POOL               = 23,
    DATA_WATER                      = 24,
    DATA_TRASH                      = 25,
};

#endif

