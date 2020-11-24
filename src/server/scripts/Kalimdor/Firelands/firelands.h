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

#ifndef FIRELANDS_H_
#define FIRELANDS_H_

#include "CreatureAIImpl.h"

#define DataHeader "FL"
#define FirelandsScriptName "instance_firelands"

uint32 const EncounterCount = 7;

enum FLDataTypes
{
    // Bosses
    DATA_BETHTILAC          = 0,
    DATA_LORD_RHYOLITH      = 1,
    DATA_SHANNOX            = 2,
    DATA_ALYSRAZOR          = 3,
    DATA_BALEROC            = 4,
    DATA_MAJORDOMO_STAGHELM = 5,
    DATA_RAGNAROS           = 6
};

enum FLCreatureIds
{
    //Bosses
    BOSS_SHANNOX                    = 53691,
    BOSS_LORD_RHYOLITH              = 52558,
    BOSS_BETHTILAC                  = 52498,
    BOSS_ALYSRAZOR                  = 52530,
    BOSS_BALEROC                    = 53494,
    BOSS_MAJORDOMO_STAGHELM         = 52571,
    BOSS_RAGNAROS                   = 52409,

    //Alysrazor
    NPC_BLAZING_MONSTROSITY_LEFT    = 53786,
    NPC_BLAZING_MONSTROSITY_RIGHT   = 53791,
    NPC_EGG_PILE                    = 53795,
    NPC_HARBINGER_OF_FLAME          = 53793,
    NPC_MOLTEN_EGG_TRASH            = 53914,
    NPC_SMOULDERING_HATCHLING       = 53794,

    // Majordomo Staghelm
    NPC_SPIRIT_OF_THE_FLAME         = 52593,
    NPC_BURNING_ORB                 = 53216,
    NPC_DRUID_OF_THE_FLAME          = 53619
};

enum GameobjectIds
{
    GO_LORD_RHYOLITH_BRIDGE         = 209255,
    GO_BETH_TILAC_DOOR              = 208877,
    GO_BALEROC_FIREWALL             = 209066,
    GO_MAJORDOMO_FIREWALL           = 208906,
    GO_RAGNAROS_DOOR                = 209073,
};

template <class AI, class T>
inline AI* GetFirelandsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, FirelandsScriptName);
}

#define RegisterFirelandsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetFirelandsAI)

#endif // FIRELANDS_H_
