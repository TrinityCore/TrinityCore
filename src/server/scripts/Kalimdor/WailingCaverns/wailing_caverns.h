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

constexpr uint32 EncounterCount = 5;

enum WCDataTypes
{
    DATA_LORD_COBRAHN         = 0,     // Used in SAI (Creature 3669)
    DATA_LORD_PYTHAS          = 1,     // Used in SAI (Creature 3670)
    DATA_LADY_ANACONDRA       = 2,     // Used in SAI (Creature 3671)
    DATA_LORD_SERPENTIS       = 3,     // Used in SAI (Creature 3673)
    DATA_MUTANUS_THE_DEVOURER = 4,     // Used in SAI (Creature 3654)

    DATA_DISCIPLE,
    DATA_NARALEX
};

enum WCCreatureIds
{
    NPC_DISCIPLE              = 3678,
    NPC_NARALEX               = 3679
};

enum WCActions
{
    ACTION_ALL_DONE           = 0
};

template <class AI, class T>
inline AI* GetWailingCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WCScriptName);
}

#define RegisterWailingCavernsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetWailingCavernsAI)

#endif
