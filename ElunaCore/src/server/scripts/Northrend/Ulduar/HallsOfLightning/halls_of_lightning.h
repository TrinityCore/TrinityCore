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

#ifndef DEF_HALLS_OF_LIGHTNING_H
#define DEF_HALLS_OF_LIGHTNING_H

enum eTypes
{
    MAX_ENCOUNTER           = 4,

    DATA_BJARNGRIM          = 1,
    DATA_IONAR              = 2,
    DATA_LOKEN              = 3,
    DATA_VOLKHAN            = 4,

    TYPE_BJARNGRIM          = 10,
    TYPE_IONAR              = 11,
    TYPE_LOKEN              = 12,
    TYPE_VOLKHAN            = 13,

    NPC_BJARNGRIM           = 28586,
    NPC_VOLKHAN             = 28587,
    NPC_IONAR               = 28546,
    NPC_LOKEN               = 28923,

    GO_BJARNGRIM_DOOR       = 191416,                       //_doors10
    GO_VOLKHAN_DOOR         = 191325,                       //_doors07
    GO_IONAR_DOOR           = 191326,                       //_doors05
    GO_LOKEN_DOOR           = 191324,                       //_doors02
    GO_LOKEN_THRONE         = 192654
};

#endif
