/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_DIREMAUL_H
#define DEF_DIREMAUL_H

#include "CreatureAIImpl.h"

#define DiremaulScriptName "instance_diremaul"
#define DataHeader "DM"

enum DMDataTypes
{
    DATA_PUSILLIN                       = 0,
    DATA_LETHTENDRIS                    = 1,
    DATA_HYDROSPAWN                     = 2,
    DATA_ZEVRIM_THORNHOOF               = 3,
    DATA_ALZZIN_THE_WILDSHAPER          = 4,
    DATA_TENDRIS_WARPWOOD               = 5,
    DATA_MAGISTER_KALENDRIS             = 6,
    DATA_TSU_ZEE                        = 7,
    DATA_ILLYANNA_RAVENOAK              = 8,
    DATA_IMMOLTHAR                      = 9,
    DATA_PRINCE_TORTHELDRIN             = 10,
    DATA_GUARD_MOLDAR                   = 11,
    DATA_STOMPER_KREEG                  = 12,
    DATA_GUARD_FENGUS                   = 13,
    DATA_GUARD_SLIPKIK                  = 14,
    DATA_CAPTAIN_KROMCRUSH              = 15,
    DATA_KING_GORDOK                    = 16,
    DATA_CRYSTAL_01                     = 17,
    DATA_CRYSTAL_02                     = 18,
    DATA_CRYSTAL_03                     = 19,
    DATA_CRYSTAL_04                     = 20,
    DATA_CRYSTAL_05                     = 21,
    DATA_FORCEFIELD                     = 22,
    DATA_CHO_RUSH_THE_OBSERVER          = 23,

    MAX_ENCOUNTER
};

enum DMCreatureIds
{
    NPC_IMMOLTHAR                       = 11496,
    NPC_TORTHELDRIN                     = 11486,
    NPC_ARCANE_ABERRATION               = 11480,
    NPC_MANA_REMNANT                    = 11483,
    NPC_CHO_RUSH                        = 14324
};

enum DMGameobjectIds
{
    GO_FORCEFIELD                       = 179503,
    GO_CRYSTAL_01                       = 177259,
    GO_CRYSTAL_02                       = 177257,
    GO_CRYSTAL_03                       = 177258,
    GO_CRYSTAL_04                       = 179504,
    GO_CRYSTAL_05                       = 179505
};

template <class AI, class T>
inline AI* GetDiremaulAI(T* obj)
{
    return GetInstanceAI<AI>(obj, DiremaulScriptName);
}

#endif
