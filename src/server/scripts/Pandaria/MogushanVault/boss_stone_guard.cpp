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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Jasper
    SPELL_JASPER_OVERLOAD = 115843,
    SPELL_JASPER_PETRIFICATION = 116036,
    SPELL_JASPER_PETRIFICATION_BAR = 131270,
    SPELL_JASPER_TRUE_FORM = 115828,
    SPELL_JASPER_CHAINS = 130395,
    SPELL_JASPER_CHAINS_VISUAL = 130403,
    SPELL_JASPER_CHAINS_DAMAGE = 130404,

    // Jade
    SPELL_JADE_OVERLOAD = 115842,
    SPELL_JADE_PETRIFICATION = 116006,
    SPELL_JADE_PETRIFICATION_BAR = 131269,
    SEPLL_JADE_TRUE_FORM = 115827,
    SPELL_JADE_SHARDS = 116223,

    // Amethyst
    SPELL_AMETHYST_OVERLOAD = 115844,
    SPELL_AMETHYST_PETRIFICATION = 116057,
    SPELL_AMETHYST_PETRIFICATION_BAR = 131255,
    SPELL_AMETHYST_TRUE_FORM = 115829,
    SPELL_AMETHYST_POOL = 116235,
    SPELL_AMETHYST_AURA = 130774,

    // Cobalt
    SPELL_COBALT_OVERLOAD = 115840,
    SPELL_COBALT_PETRIFICATION = 115852,
    SPELL_COBALT_PETRIFICATION_BAR = 131268,
    SEPLL_COBALT_TRUE_FORM = 115771,
    SPELL_COBALT_MINE = 129460,

    // Shared
    SPELL_SOLID_STONE = 115745,
    SPELL_REND_FLESH = 125206,
    SPELL_ANIM_SIT = 128886,
    SPELL_ZERO_ENERGY = 72242,
    SPELL_TOTALY_PETRIFIED = 115877,
    SPELL_STONE_GUARD_BONUS = 125144,

    //  Energized Tiles
    SPELL_TILES_AURA = 116579,
    SPELL_TILES_AURA_EFFECT = 116541,
    SPELL_TILES_DISPLAYED = 116542,
    SPELL_LIVING_AMETHYST = 116322,
    SPELL_LIVING_COBALT = 116199,
    SPELL_LIVING_JADE = 116301,
    SPELL_LIVING_JASPER = 116304
};

enum eEvents
{
    // Controler
    EVENT_PETRIFICATION = 1,
    EVENT_CRYSTALS = 2,

    // Guardians
    EVENT_CHECK_NEAR_GUARDIANS = 3,
    EVENT_CHECK_ENERGY = 4,
    EVENT_REND_FLESH = 5,
    EVENT_MAIN_ATTACK = 6,
    EVENT_ENRAGE = 7,

    // Tiles
    EVENT_TILING = 8,

    // Check petrification
    EVENT_CHECK_PETRIFICATION = 9
};

uint32 guardiansEntry[4] =
{
    NPC_JASPER,
    NPC_JADE,
    NPC_AMETHYST,
    NPC_COBALT
};

uint32 crystalsEntry[4] =
{
    NPC_LIVING_AMETHYST_CRYSTAL,
    NPC_LIVING_COBALT_CRYSTAL,
    NPC_LIVING_JADE_CRYSTAL,
    NPC_LIVING_JASPER_CRYSTAL
};

// For living crystals - Stone guard
Position stoneGuardsPos[4] =
{
    {3919.89f, 1258.59f, 466.363f, 4.66991f},   // Jasper
    {3878.93f, 1258.49f, 466.363f, 4.69497f},   // Jade
    {3928.00f, 1246.34f, 466.363f, 4.71147f},   // Amethyst
    {3870.75f, 1246.28f, 466.363f, 4.54348f}    // Cobalt
};

// Specific orientation for tiles (should not be turned)
#define TILE_ORIENTATION 4.714031f

// Invisible modelID for NPC Tiling Creature 62026
#define INVISIBLE_DISPLAYID 11686

#define DATA_FIGHT 1

void AddSC_boss_stone_guard()
{
    
}
