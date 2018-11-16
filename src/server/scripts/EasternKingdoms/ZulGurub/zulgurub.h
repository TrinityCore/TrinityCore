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

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

#include "CreatureAIImpl.h"

#define DataHeader "ZG"
#define ZGScriptName "instance_zulgurub"

uint32 const EncounterCount = 5;

enum ZGDataTypes
{
    // Bosses
    DATA_HIGH_PRIEST_VENOXIS        = 0,
    DATA_BLOODLORD_MANDOKIR         = 1,
    DATA_HIGH_PRIESTESS_KILNARA     = 2,
    DATA_ZANZIL                     = 3,
    DATA_JINDO_THE_GODBREAKER       = 4,

    // Cache of Madness
    DATA_HAZZARAH                   = 5,
    DATA_RENATAKI                   = 6,
    DATA_WUSHOOLAY                  = 7,
    DATA_GRILEK                     = 8,

    // Bloodlord Mandokir
    DATA_OHGAN                      = 9,

    // High Priestess Kilnara
    DATA_CAST_CAVE_IN_VISUAL        = 10,

    // Jin'do the Godbreaker
    DATA_JINDOR_TRIGGER
};

enum ZGCreatureIds
{
    // Bosses
    BOSS_HIGH_PRIEST_VENOXIS        = 52155,
    BOSS_BLOODLORD_MANDOKIR         = 52151,
    BOSS_HIGH_PRIESTESS_KILNARA     = 52059,
    BOSS_ZANZIL                     = 52053,
    BOSS_JINDO_THE_GODBREAKER       = 52148,

    // High Priest Venoxis
    NPC_GENERAL_PURPOSE_DUMMY_JMF   = 45979,
    NPC_VENOMOUS_EFFUSION_STALKER   = 52302,
    NPC_VENOMOUS_EFFUSION           = 52288,
    NPC_POOL_OF_ACRID_TEARS         = 52197,
    NPC_BLOODVENOM                  = 52525,

    // Cache of Madness
    NPC_HAZZARAH                    = 52271,
    NPC_RENATAKI                    = 52269,
    NPC_WUSHOOLAY                   = 52286,
    NPC_GRILEK                      = 52258,

    // Bloodlord Mandokir
    NPC_CHAINED_SPIRIT              = 52156,
    NPC_OHGAN                       = 52157,
    NPC_DEVASTATING_SLAM            = 52324,

    // High Priestess Kilnara
    NPC_WAVE_OF_AGONY_1             = 52160,
    NPC_WAVE_OF_AGONY_2             = 52147,
    NPC_PRIDE_OF_BETHEKK            = 52061,
    NPC_CAVE_IN_STALKER             = 52387,

    // Jin'do the Godbreaker
    NPC_JINDO_TRIGGER               = 52150,
    NPC_SPIRIT_OF_HAKKAR            = 52222,
    NPC_SHADOW_OF_HAKKAR            = 52650,

    // Zanzil
    NPC_ZANZILI_BERSERKER           = 52054,
    NPC_ZANZILI_ZOMBIE              = 52055,
    NPC_ZANZILS_TOXIC_GAS           = 52062,

    // Generic Creatures
    NPC_TOXIC_VENOMSPITTER          = 52332,
    NPC_MUTATED_OVERGROWTH          = 52331
};

enum ZGGameObjectIds
{
    // High Priest Venoxis
    GO_VENOXIS_COIL                 = 208844,

    // Bloodlord Mandokir
    GO_ARENA_DOOR_1                 = 208845,
    GO_ARENA_DOOR_2                 = 208847,
    GO_ARENA_DOOR_3                 = 208848,
    GO_ARENA_DOOR_4                 = 208846,
    GO_ARENA_DOOR_5                 = 208849,

    // High Priestess Kilnara
    GO_FORCEFIELD                   = 180497,

    // Zanzil
    GO_ZANZIL_DOOR                  = 208850,

    // Cache of Madness
    GO_THE_CACHE_OF_MADNESS_DOOR    = 208843
};

enum ZGActions
{
    ACTION_TRIGGER_JINDO_INTRO = 0
};

enum ZGSpells
{
    SPELL_CAVE_IN_VISUAL                = 96935,
    SPELL_POISON_CLOUD                  = 96729,
    SPELL_COSMETIC_ALPHA_STATE_25_PCT   = 82978
};

template <class AI, class T>
inline AI* GetZulGurubAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ZGScriptName);
}

#define RegisterZulGurubCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetZulGurubAI)

#endif
