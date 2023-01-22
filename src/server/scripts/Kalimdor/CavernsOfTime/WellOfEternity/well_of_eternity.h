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

#ifndef DEF_WELLOFETERNITY_H
#define DEF_WELLOFETERNITY_H

#include "CreatureAIImpl.h"
#include "Define.h"

#define DataHeader "WOE"
#define WOEScriptName "instance_well_of_eternity"

uint32 const EncounterCount = 3;

enum WOEDataTypes
{
    // Bosses
    BOSS_PEROTHARN              = 0,
    BOSS_QUEEN_AZSHARA          = 1,
    BOSS_MANNOROTH_AND_VAROTHEN = 2,

    // Misc
    DATA_WOE_COURTYARD_DOOR01,
};

enum WOECreatures
{
    NPC_PEROTHARN = 55085
};

enum WOEGameObjectIds
{
    GO_WOE_COURTYARD_DOOR01 = 210084,
    GO_LARGE_FIREWALL_DOOR  = 210234,
    GO_SMALL_FIREWALL_DOOR  = 210130,
};

template<class AI>
AI* GetWellOfEternityAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, WOEScriptName);
}

#define RegisterWellOfEternityCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetWellOfEternityAI)

#endif // DEF_WELLOFETERNITY_H
