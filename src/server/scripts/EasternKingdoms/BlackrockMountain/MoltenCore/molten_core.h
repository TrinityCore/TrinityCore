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

#ifndef DEF_MOLTEN_CORE_H
#define DEF_MOLTEN_CORE_H

#include "CreatureAIImpl.h"

#define MCScriptName "instance_molten_core"
#define DataHeader "MC"

uint32 constexpr EncounterCount = 10;

enum MCEncounters
{
    BOSS_LUCIFRON                   = 0,
    BOSS_MAGMADAR                   = 1,
    BOSS_GEHENNAS                   = 2,
    BOSS_GARR                       = 3,
    BOSS_SHAZZRAH                   = 4,
    BOSS_BARON_GEDDON               = 5,
    BOSS_SULFURON_HARBINGER         = 6,
    BOSS_GOLEMAGG_THE_INCINERATOR   = 7,
    BOSS_MAJORDOMO_EXECUTUS         = 8,
    BOSS_RAGNAROS                   = 9
};

enum MCDataTypes
{
    DATA_RUNE_OF_KORO,
    DATA_RUNE_OF_ZETH,
    DATA_RUNE_OF_MAZJ,
    DATA_RUNE_OF_THERI,
    DATA_RUNE_OF_BLAZ,
    DATA_RUNE_OF_KRESS,
    DATA_RUNE_OF_MOHN
};

enum MCCreatures
{
    NPC_LUCIFRON                    = 12118,
    NPC_MAGMADAR                    = 11982,
    NPC_GEHENNAS                    = 12259,
    NPC_GARR                        = 12057,
    NPC_SHAZZRAH                    = 12264,
    NPC_BARON_GEDDON                = 12056,
    NPC_SULFURON_HARBINGER          = 12098,
    NPC_GOLEMAGG_THE_INCINERATOR    = 11988,
    NPC_MAJORDOMO_EXECUTUS          = 12018,
    NPC_RAGNAROS                    = 11502,

    NPC_FLAMEWAKER_HEALER           = 11663,
    NPC_FLAMEWAKER_ELITE            = 11664
};

enum MCGameObjects
{
    GO_RUNE_OF_KORO                 = 176951,
    GO_RUNE_OF_ZETH                 = 176952,
    GO_RUNE_OF_MAZJ                 = 176953,
    GO_RUNE_OF_THERI                = 176954,
    GO_RUNE_OF_BLAZ                 = 176955,
    GO_RUNE_OF_KRESS                = 176956,
    GO_RUNE_OF_MOHN                 = 176957
};

enum MCSpawnGroups
{
    SPAWN_GROUP_CACHE               = 335,
    SPAWN_GROUP_MAJORDOMO           = 336,
    SPAWN_GROUP_FLAMEWAKERS         = 337,
    SPAWN_GROUP_RAGNAROS            = 338,
    SPAWN_GROUP_MAJORDOMO_ALT       = 339,
    SPAWN_GROUP_LAVA_STEAM          = 340,
    SPAWN_GROUP_LAVA_SPLASH         = 341
};

enum MCActions
{
    ACTION_FLAMEWAKER_DIES          = 0
};

template <class AI, class T>
inline AI* GetMoltenCoreAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MCScriptName);
}

#define RegisterMoltenCoreCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMoltenCoreAI)
#define RegisterMoltenCoreGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetMoltenCoreAI)

#endif
