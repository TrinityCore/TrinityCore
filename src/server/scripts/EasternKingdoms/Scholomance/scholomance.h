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

#ifndef DEF_SCHOLOMANCE_H
#define DEF_SCHOLOMANCE_H

uint32 const MAX_ENCOUNTER = 2;

enum DataTypes
{
    TYPE_GANDLING                       = 1,
    DATA_DOCTORTHEOLENKRASTINOV         = 2,
    DATA_INSTRUCTORMALICIA              = 3,
    DATA_LADYILLUCIABAROV               = 4,
    DATA_LORDALEXEIBAROV                = 5,
    DATA_LOREKEEPERPOLKELT              = 6,
    DATA_THERAVENIAN                    = 7,
    TYPE_KIRTONOS                       = 8
};

enum GameobjectIds
{
    GO_GATE_KIRTONOS                    = 175570,
    GO_GATE_GANDLING                    = 177374,
    GO_GATE_MALICIA                     = 177375,
    GO_GATE_THEOLEN                     = 177377,
    GO_GATE_POLKELT                     = 177376,
    GO_GATE_RAVENIAN                    = 177372,
    GO_GATE_BAROV                       = 177373,
    GO_GATE_ILLUCIA                     = 177371,
    GO_BRAZIER_OF_THE_HERALD            = 175564
};

#endif
