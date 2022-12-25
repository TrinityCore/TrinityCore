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

#include "new_karazhan.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_SPECIAL_ARCANE = 1,
    SAY_SPECIAL_FROST = 2,
    SAY_SPECIAL_FIRE = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_ARCANE_CHANNEL_VIS = 189573,
    SPELL_MANA_REGEN = 228582,
    SPELL_VO_CONTROLLER = 232314,
    SPELL_FROSTBITE = 227592,
    SPELL_INFERNO_BOLT = 227615,
    SPELL_INFERNO_BOLT_VIS = 228249,
    SPELL_PIERCING_MISSILES = 227628,
    SPELL_PIERCING_MISSILES_DMG = 227641,
    SPELL_PIERCING_MISSILES_VIS = 227644,

    //Special Arcane Ability
    SPELL_GUARDIAN_IMAGE = 228334,
    SPELL_GUARDIAN_IMAGE_SUM = 228338,
    SPELL_DISSOLVE = 228572,
    SPELL_REFORM_VISUAL_STATE_1 = 228568,
    SPELL_REFORM_VISUAL_STATE_2 = 228569,

    //Special Fire Ability
    SPELL_FLAME_WREATH_FILTER = 228269,
    SPELL_FLAME_WREATH_AT = 228257,

    //Special Frost Ability
    SPELL_CEASELESS_WINTER_AT = 227779,

    //Summons
    SPELL_ARCANE_DISSOLVE = 228343,
    SPELL_SHIMMER = 228521,
    SPELL_ARCANE_BOLT = 228991,
    SPELL_REFORM_VISUAL = 228558,

    //Other
    SPELL_DIMENSION_FALL = 231851,
    SPELL_DIMENSION_FALL_MID_FALL = 232630,
    SPELL_SAFE_FALL = 231462,
};

enum eEvents
{
    EVENT_ALTERNATING_ABILITY = 1,
    EVENT_SPECIAL_FROST = 2,
    EVENT_SPECIAL_FIRE = 3,
    EVENT_SPECIAL_ARCANE = 4,
    
    EVENT_1,
    EVENT_2,
};

enum Actions
{
    ACTION_1 = 1,
};

void AddSC_boss_shade_of_medivh()
{
    
}
