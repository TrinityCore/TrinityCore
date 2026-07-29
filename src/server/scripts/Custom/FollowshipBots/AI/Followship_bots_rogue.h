/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Followship_bots_spells_handler.h"

enum FSB_ROGUE_SPECIAL_SPELLS
{
    // Heal
    SPELL_ROGUE_CRIMSON_VIAL = 185311, // 30s, 0f

    SPELL_ROGUE_STEALTH = 1784,
};

enum FSB_ROGUE_POISON_SPELLS
{
    SPELL_ROGUE_INSTANT_POISON = 315584, // 1h
    SPELL_ROGUE_WOUND_POISON = 8679, // 1h
    SPELL_ROGUE_DEADLY_POISON = 2823, // 1h
    SPELL_ROGUE_AMPLIFYING_POISON = 381664, // 1h

    SPELL_ROGUE_CRIPPLING_POISON = 3408, // 1h
    SPELL_ROGUE_ATROPHIC_POISON = 381637, // 1h
    SPELL_ROGUE_NUMBING_POISON = 5761, // 1h
};

enum FSB_ROGUE_COMBAT_SPELLS
{
    SPELL_ROGUE_SINISTER_STRIKE = 193315,
    SPELL_ROGUE_SHIV = 5938, // 30s, 2f
    SPELL_ROGUE_GOUGE = 1776, // 25s, 2f

    SPELL_ROGUE_AMBUSH = 8676, // 0s, 2f, stealth
    SPELL_ROGUE_CHEAP_SHOT = 1833, // 12s, 2f, stealth

    SPELL_ROGUE_KIDNEY_SHOT = 1766, // 30s, 2f, combo
    SPELL_ROGUE_SLICE_DICE = 5171, // 0s, 2f, combo
    SPELL_ROGUE_EVISCERATE = 196819, // 0s, 2f, combo

    SPELL_ROGUE_KICK = 1766, // 15s, 2f
    SPELL_ROGUE_BLIND = 2094, // 2m, 15f

    SPELL_ROGUE_EVASION = 5277, // 2m, 0f
    SPELL_ROGUE_THISTLE_TEA = 381623, // 1m, 0f
    SPELL_ROGUE_CLOAK_SHADOWS = 31224, // 2m , 0f

    // Assassin
    SPELL_ROGUE_DEATHMARK = 360194, // 2m, 2f
    SPELL_ROGUE_GARROTE = 703, // 6s, 2f
    SPELL_ROGUE_MUTILATE = 1329, // 0s, 2f
    SPELL_ROGUE_POISONED_KNIFE = 185565, // 0s, 30f

    SPELL_ROGUE_RUPTURE = 1943, // 0s, 2f, combo
    SPELL_ROGUE_ENVENOM = 32645, // 0s, 2f, combo

    SPELL_ROGUE_CRIMSON_TEMPEST = 1247227, // 0s, 5f
    SPELL_ROGUE_FAN_KNIVES = 51723, // 0s, 4f

    SPELL_ROGUE_KINGSBANE = 385627, // 1m, 2f

    // Subtlety
    SPELL_ROGUE_SHADOWSTEP = 36554, // 30s, 25f xx
    SPELL_ROGUE_SHADOW_BLADES = 121471, // 90s, 0f xx    
    
    SPELL_ROGUE_BACKSTAB = 53, // 0s, 2f xx
    SPELL_ROGUE_GLOOMBLADE = 200758, // 0s, 2f xx
    SPELL_ROGUE_GOREMAW_BITE = 426591, // 45s, 2f xx
    SPELL_ROGUE_SHURIKEN_TOSS = 114014, // 0s, 30f xx

    SPELL_ROGUE_SHADOWSTRIKE = 185438, // 0s, 2f, xx stealth

    SPELL_ROGUE_BLACK_POWDER = 319175, // 0s combo xx
    SPELL_ROGUE_SHURIKEN_STORM = 197835, // 0s 10f xx

    // Combat
    SPELL_ROGUE_RIPOSTE = 34099, // 30s, 2f
    SPELL_ROGUE_BLADE_FLURRY = 13877, // 30s, 2f
    SPELL_ROGUE_GHOSTLY_STRIKE = 31022, // 20s, 2f -> backstab
    SPELL_ROGUE_PARALYTIC_POISON = 35201, // 0s, 2f
    SPELL_ROGUE_MARKED_FOR_DEATH = 137619, // 40s, 2f
    SPELL_ROGUE_DISMANTLE = 207777, // 45s, 2f
    SPELL_ROGUE_SEPSIS = 385408, // 90s, 2f
    SPELL_ROGUE_EXPOSE_ARMOR = 8647, // 45s, 2f, 25e
    SPELL_ROGUE_DREADBLADES = 343142, // 2m, 2f

    SPELL_ROGUE_ROLL_THE_BONES = 315508, // 45s, 0f

    SPELL_ROGUE_DEADLY_THROW = 26679, // 0s, 2f combo
    //SPELL_ROGUE_ADRENALINE_RUSH = 13750, // 3m, 0f
    // Gouge
    // Evasion

    
};

extern std::vector<FSBSpellDefinition> RogueSpellsTable;

namespace FSBRogue
{
}
