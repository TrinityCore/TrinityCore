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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

#define ERROR_INST_DATA      "TSCR Error: Instance Data not set properly for Magister's Terrace instance (map 585). Encounters will be buggy."

enum Data
{
    DATA_SELIN_EVENT            = 0,
    DATA_VEXALLUS_EVENT         = 1,
    DATA_DELRISSA_EVENT         = 2,
    DATA_KAELTHAS_EVENT         = 3,

    DATA_SELIN                  = 4,
    DATA_FEL_CRYSTAL            = 5,
    DATA_FEL_CRYSTAL_SIZE       = 6,

    DATA_VEXALLUS_DOOR          = 7,
    DATA_SELIN_DOOR             = 8,
    DATA_DELRISSA               = 9,
    DATA_DELRISSA_DOOR          = 10,
    DATA_SELIN_ENCOUNTER_DOOR   = 11,

    DATA_KAEL_DOOR              = 12,
    DATA_KAEL_STATUE_LEFT       = 13,
    DATA_KAEL_STATUE_RIGHT      = 14,

    DATA_DELRISSA_DEATH_COUNT   = 15,

    DATA_ESCAPE_ORB             = 16
};

#endif
