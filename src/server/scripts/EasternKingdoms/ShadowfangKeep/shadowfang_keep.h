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

#ifndef _Shadowfang_Keep_h__
#define _Shadowfang_Keep_h__

#include "CreatureAIImpl.h"

constexpr char const* SFKScriptName = "instance_shadowfang_keep";
constexpr char const* DataHeader = "SFK";

constexpr uint32 const EncounterCount = 6;

enum SFKDataTypes
{
    // Encounters
    BOSS_BARON_ASHBURY          = 0,
    BOSS_BARON_SILVERLAINE      = 1,
    BOSS_COMMANDER_SPRINGVALE   = 2,
    BOSS_LORD_WALDEN            = 3,
    BOSS_LORD_GODFREY           = 4,
    BOSS_APOTHECARY_HUMMEL      = 5,

    // Additional data
    /*The doors within this instance are all tied to events before becoming actual doors so we have to manually manage them*/
    DATA_ARUGAL_DOOR,
    DATA_SORCERER_GATE,
    DATA_COURTYARD_DOOR
};

enum SFKCreatureIds
{
    // Bosses
    NPC_BARON_ASHBURY           = 46962,
    NPC_BARON_SILVERLAINE       = 3887,
    NPC_COMMANDER_SPRINGVALE    = 4278,
    NPC_LORD_WALDEN             = 46963,
    NPC_LORD_GODFREY            = 46964
};

enum SKGameObjectIds
{
    GO_COURTYARD_DOOR   = 18895,
    GO_SORCERERS_DOOR   = 18972,
    GO_ARUGALS_LAIR     = 18971
};

template <class AI, class T>
inline AI* GetShadowfangKeepAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SFKScriptName);
}

#define RegisterShadowfangKeepCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetShadowfangKeepAI)

#endif // _Shadowfang_Keep_h__
