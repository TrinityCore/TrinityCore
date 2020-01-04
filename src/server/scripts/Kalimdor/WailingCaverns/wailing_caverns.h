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

#define DataHeader "WC"
#define WCScriptName "instance_wailing_caverns"

uint32 const EncounterCount = 8;

enum Data
{
    DATA_LORD_COBRAHN          = 1,
    DATA_LORD_PYTHAS           = 2,
    DATA_LADY_ANACONDRA        = 3,
    DATA_LORD_SERPENTIS        = 4,
    DATA_NARALEX_EVENT         = 5,
    DATA_NARALEX_PART1         = 6,
    DATA_NARALEX_PART2         = 7,
    DATA_NARALEX_PART3         = 8,
    DATA_MUTANUS_THE_DEVOURER  = 9,
    DATA_NARALEX_YELLED        = 10,
    DATA_NARALEX               = 11,
    DATA_SKUM                  = 12,
    DATA_KRESH                 = 13,
    DATA_VERDAN_THE_EVERLIVING = 14
};

enum Creatures
{
    // Bosses
    NPC_LADY_ANACONDRA           = 3671,
    NPC_LORD_COBRAHN             = 3669,
    NPC_KRESH                    = 3653,
    NPC_LORD_PYTHAS              = 3670,
    NPC_SKUM                     = 3674,
    NPC_LORD_SERPENTIS           = 3673,
    NPC_VERDAN_THE_EVERLIVING    = 5775,
    NPC_MUTANUS_THE_DEVOURER     = 3654,
    NPC_NARALEX                  = 3679,

    // Adds
    NPC_DEVIATE_RAVAGER          = 3636,
    NPC_DEVIATE_VIPER            = 5755,
    NPC_DEVIATE_MOCCASIN         = 5762,
    NPC_NIGHTMARE_ECTOPLASM      = 5763,
    NPC_DRUID_OF_THE_FANG        = 3840,
};

template <class AI, class T>
inline AI* GetWailingCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WCScriptName);
}

#endif // WAILING_CAVERNS_H
