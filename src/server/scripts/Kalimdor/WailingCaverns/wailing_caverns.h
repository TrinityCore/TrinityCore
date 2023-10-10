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

#ifndef DEF_WAILING_CAVERNS_H
#define DEF_WAILING_CAVERNS_H

#include "CreatureAIImpl.h"

#define WCScriptName "instance_wailing_caverns"
#define DataHeader "WC"

enum WCBossIds
{
    BOSS_LORD_COBRAHN           = 0,
    BOSS_LORD_PYTHAS            = 1,
    BOSS_LADY_ANACONDRA         = 2,
    BOSS_LORD_SERPENTIS         = 3,
    BOSS_MUTANUS_THE_DEVOURER   = 8,
    BOSS_KRESH                  = 9,
    BOSS_SKUM                   = 10,
    BOSS_VERDAN_THE_EVERLIVING  = 11,

    MAX_ENCOUNTER
};

enum WCDataTypes
{
    TYPE_LORD_COBRAHN         = 1,
    TYPE_LORD_PYTHAS          = 2,
    TYPE_LADY_ANACONDRA       = 3,
    TYPE_LORD_SERPENTIS       = 4,
    TYPE_NARALEX_EVENT        = 5,
    TYPE_NARALEX_PART1        = 6,
    TYPE_NARALEX_PART2        = 7,
    TYPE_NARALEX_PART3        = 8,
    TYPE_MUTANUS_THE_DEVOURER = 9,
    TYPE_NARALEX_YELLED       = 10,

    DATA_NARALEX              = 3679,
};

enum WCCreatureIds
{
    NPC_KRESH                   = 3653,
    NPC_SKUM                    = 3674,
    NPC_VERDAN_THE_EVERLIVING   = 5775
};

template <class AI, class T>
inline AI* GetWailingCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WCScriptName);
}

#endif
