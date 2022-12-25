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

#include "thenighthold.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells
{
    SPELL_ENERGIZE = 204277,
    SPELL_FOCUSED_BLAST = 204468,
    SPELL_FOCUSED_BLAST_AT = 204471,
    SPELL_CALL_SCORPID = 204371,
    SPELL_SHOCKWAVE = 204316,
    SPELL_EXOSKELETON = 204448,
    SPELL_EXOSKELETAL_VULNERABILITY = 204459,
    SPELL_INFUSED_EXOSKELETON = 205947,
    SPELL_ARCANOSLASH_DUMMY = 205200,
    SPELL_FRAGMENTS_FILTER = 209696,
    SPELL_CRYSTALL_FRAGMENTS = 204509,
    SPELL_VOLATILE_FRAGMENTS = 214663,
    SPELL_ACIDIC_FRAGMENTS = 214657,
    SPELL_REMOVE_ACIDIC = 204381,
    SPELL_VOLATILE_RESONANCE = 226229, //Mythic

    SPELL_BLUE_TRANSFORM = 215055,
    SPELL_RED_TRANSFORM = 214800,
    SPELL_GREEN_TRANSFORM = 215042,

    SPELL_ARCANE_TETHER = 204378,
    SPELL_ARCANE_TETHER_AURA = 204531,

    //Summons
    SPELL_AVAILABLE = 228943,
    SPELL_SHROUDED = 205900,
    SPELL_BURROW = 204732,
    SPELL_ENERGY_SURGE = 204766,
    SPELL_BOON_SCORPID = 205289,
    SPELL_SCORPID_SWARM_AT = 204697,
    SPELL_VOLATILE_CHITIN_VIS = 210165,
    SPELL_VOLATILE_CHITIN_DMG = 204733,
    SPELL_TOXIC_CHITIN = 204748,
    SPELL_TOXIC_CHITIN_AT = 204742,

    SPELL_BROKEN_SHARD = 204284,
    SPELL_LOS_BLOCKER = 204289,
    SPELL_CRYSTALL_FRAGMENTS_AT = 204306,
    SPELL_VOLATILE_FRAGMENTS_AT = 214661,
    SPELL_ACIDIC_FRAGMENTS_AT = 214652,
    SPELL_ACIDIC_FRAGMENTS_AURA = 214718,
};

enum eEvents
{
    EVENT_FOCUSED_BLAST = 1,
    EVENT_CALL_SCORPID = 2,
    EVENT_VULNERABILITY = 3,
    EVENT_ARCANOSLASH = 4,
};

enum eSpellVisual
{
    VISUAL_BLAST_1 = 53760,
    VISUAL_BLAST_2 = 53762,
    VISUAL_BLAST_3 = 53763,
    VISUAL_BLAST_4 = 53780,

    VISUAL_KIT_BLAST = 67693
};

enum eColor
{
    BLUE_MODE = 1,
    RED_MODE,
    GREEN_MODE
};

enum eText
{
    SAY_BLAST = 0,
    SAY_SHOCKWAVE = 1,

    EVENT_1,
    EVENT_2,
    EVENT_3,

    ACTION_1,
    ACTION_2,
};

void AddSC_boss_skorpyron()
{
    
}
