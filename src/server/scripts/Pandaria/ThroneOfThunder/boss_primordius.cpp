/*
* Copyright 2023 AzgathCore
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

#include "ScriptPCH.h"
#include "throne_of_thunder.h"
#include "SpellAuras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_PRIMORDIAL_STRIKE = 136037,
    SPELL_MALFORMED_BLOOD = 136050,
    SPELL_MUTATED_ABOMINATION = 140544,
    SPELL_EVOLUTION = 136209,

    // Evolutions for Primosdius
    //Mutation: Erupting Pustules
    SPELL_ERUPTING_PUSTULES = 136246,
    SPELL_PUSTULE_ERUPTION_MISSILE = 136248,
    //Mutation: Metabolic Boost
    SPELL_METABOLIC_BOOST = 136245,
    //Mutation: Pathogen Glands
    SPELL_PATHOGEN_GLANDS = 136225,
    SPELL_VOLATILE_PATHOGEN_DAMAGE = 136228,
    //Mutation: Acidic Spines
    SPELL_ACIDIC_SPINES = 136218,
    SPELL_ACIDIC_EXPLOSION_MISSILE = 136219,
    //Mutation: Gas Bladder
    SPELL_GAS_BLADDER = 136215,
    SPELL_CAUSTIC_GAS = 136216,
    //Mutation: Ventral SacS
    SPELL_VECTRAL_SACS = 136210,

    // living fluid
    SPELL_MUTATE_PRIMORDIUS = 136203,
    SPELL_MUTAGENIC_POOL = 136049,
    SPELL_MUTATE_PLAYER = 136178,

    // Mutation effects for players ( helpful and harmful mutation system )
    SPELL_THICK_BONES = 136184,
    SPELL_FRAGILE_BONES = 136185,

    SPELL_CLEAR_MIND = 136186,
    SPELL_CLOUDED_MIND = 136187,

    SPELL_IMPROVED_SYNAPSES = 136182,
    SPELL_DULLED_SYNAPSES = 136183,

    SPELL_KEEN_EYESIGHT = 136180,
    SPELL_IMPAIRED_EYESIGHT = 136181,

    SPELL_FULLY_MUTATED = 140546,

    SPELL_VOLATILE_POOL = 140506,
    SPELL_VOLATILE_MUTATE_PRIMORDIUS = 140509,
    SPELL_VOLATILE_MUTATE_PLAYER_PERIODIC = 140508,

    SPELL_BLACK_BLOOD = 137000,
    SPELL_DEADLY_MUTAGEN = 136995,
};

enum Creatures
{
    NPC_VISCOUS_HORROR = 69070,
    NPC_VOLATILE_POOL = 999455,
    NPC_MUTAGENIC_POOL = 999454,
    NPC_LIVING_FLUID = 70579,
    NPC_PRIMORDIUS = 69017,
};

enum Events
{
    EVENT_MALFORMED_BLOOD = 1,
    EVENT_PRIMORDIAL_STRIKE,
    EVENT_BLACK_BLOOD,
    EVENT_ENERGY_GAIN,
    EVENT_CHECK_ENERGY,
    EVENT_SUMMON_FLUIDS_SPAWNER,
    EVENT_SUMMON_HORRORS,
    EVENT_CAUSTIC_GAS,
    EVENT_VOLATILE_PATHOGEN,
    EVENT_VOLATILE_TO_BOSS,
    EVENT_HARD_ENRAGE,
    EVENT_VOLATILE_CAST_PLAYERS,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_DEATH = 2,
    TALK_EVOLUTION = 3,
    TALK_KILL_PLAYER = 4,
};

uint32 allEvolutions[6] =
{
    SPELL_VECTRAL_SACS,
    SPELL_ACIDIC_SPINES,
    SPELL_ERUPTING_PUSTULES,
    SPELL_METABOLIC_BOOST,
    SPELL_PATHOGEN_GLANDS,
    SPELL_GAS_BLADDER
};

static const std::pair<uint32, uint32> m_pMutations[4] =
{
    { SPELL_KEEN_EYESIGHT, SPELL_IMPAIRED_EYESIGHT },
    { SPELL_IMPROVED_SYNAPSES, SPELL_DULLED_SYNAPSES },
    { SPELL_THICK_BONES, SPELL_FRAGILE_BONES },
    { SPELL_CLEAR_MIND, SPELL_CLOUDED_MIND }
};

static inline const uint32 GetTotalMutations(Unit* pUnit)
{
    uint32 m_uiMutations = 0;

    Aura* pAura;

    for (uint8 i = 0; i < 4; ++i)
    {
        if (pAura = pUnit->GetAura(m_pMutations[i].first))
            m_uiMutations += pAura->GetStackAmount();
    }

    return m_uiMutations;
};

void AddSC_bfa_boss_primordius()
{
    
}
