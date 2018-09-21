/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_MOLTEN_CORE_H
#define DEF_MOLTEN_CORE_H

#include "CreatureAIImpl.h"

struct Position;

#define MCScriptName "instance_molten_core"
#define DataHeader "MC"

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
    BOSS_RAGNAROS                   = 9,
    MAX_ENCOUNTER,
};

enum MCActions
{
    ACTION_START_RAGNAROS       = 0,
    ACTION_START_RAGNAROS_ALT   = 1,
};

extern Position const RagnarosTelePos;
extern Position const RagnarosSummonPos;

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
    NPC_FLAMEWAKER_ELITE            = 11664,
};

enum MCGameObjects
{
    GO_CACHE_OF_THE_FIRELORD        = 179703,
};

enum MCData
{
    DATA_RAGNAROS_ADDS  = 0,
};

template <class AI, class T>
inline AI* GetMoltenCoreAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MCScriptName);
}

#define RegisterMoltenCoreCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMoltenCoreAI)

#endif
