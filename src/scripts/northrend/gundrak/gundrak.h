/*
* Copyright (C) 2009-2010 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef DEF_GUNDRAK_H
#define DEF_GUNDRAK_H

enum Data
{
    DATA_SLAD_RAN_EVENT,
    DATA_MOORABI_EVENT,
    DATA_DRAKKARI_COLOSSUS_EVENT,
    DATA_GAL_DARAH_EVENT,
    DATA_ECK_THE_FEROCIOUS_EVENT,
    DATA_ALIVE_RUIN_DWELLERS
};

enum Data64
{
    DATA_SLAD_RAN_ALTAR,
    DATA_MOORABI_ALTAR,
    DATA_DRAKKARI_COLOSSUS_ALTAR,
    DATA_SLAD_RAN_STATUE,
    DATA_MOORABI_STATUE,
    DATA_DRAKKARI_COLOSSUS_STATUE,
    DATA_DRAKKARI_COLOSSUS,
    DATA_RUIN_DWELLER_DIED
};

enum mainCreatures
{
    CREATURE_RUIN_DWELLER                         = 29920,
    CREATURE_SLAD_RAN                             = 29304,
    CREATURE_MOORABI                              = 29305,
    CREATURE_GALDARAH                             = 29306,
    CREATURE_DRAKKARICOLOSSUS                     = 29307,
    CREATURE_ECK                                  = 29932
};

#endif
