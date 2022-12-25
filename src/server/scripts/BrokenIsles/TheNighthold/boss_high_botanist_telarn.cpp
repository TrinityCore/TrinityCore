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

enum Says
{
    //Botanist
    SAY_AGGRO                   = 0,
    SAY_SOLAR_COLLAPSE          = 1,
    SAY_PARASITIC_FETTER        = 2,
    SAY_CONTROLLED_CHAOS        = 3,
    SAY_CALL_OF_NIGHT_WARN      = 4,
    SAY_CALL_OF_NIGHT           = 5,
    SAY_PHASE_2                 = 6,
    SAY_PHASE_3                 = 7,
    SAY_DEATH                   = 8,
    SAY_KILL_PLAYER             = 9,

    //Solarist
    SAY_S_PLASMA_SPHERES        = 0,
    SAY_S_SOLAR_COLLAPSE        = 1,

    //Arcanist
    SAY_A_UNK0                  = 0,
    SAY_A_AGGRO                 = 1,
    SAY_A_CALL_OF_NIGHT_WARN    = 2,
    SAY_A_CALL_OF_NIGHT         = 3,
    SAY_A_CONTROLLED_CHAOS      = 4,

    //Naturalist
    SAY_N_PARASITIC_FETTER      = 0,
    SAY_N_GRACE_OF_NATURE       = 1
};

enum Spells
{
    SPELL_BERSERK                   = 62535,
    SPELL_SHARE_HEALTH              = 216897,
    SPELL_SHARE_HEALTH_SCRIPT       = 216898,

    //Phase 1
    SPELL_RECURSIVE_STRIKES         = 218502,
    SPELL_RECURSIVE_STRIKES_DUMMY   = 218503,
    SPELL_RECURSIVE_STRIKES_DMG     = 218508,
    SPELL_CONTROLLED_CHAOS_FILTER   = 218438,
    SPELL_SUM_CONTROLLED_CHAOS      = 218447,
    SPELL_CONTROLLED_CHAOS_DMG_10   = 218463,
    SPELL_CONTROLLED_CHAOS_DMG_20   = 218466,
    SPELL_CONTROLLED_CHAOS_DMG_30   = 218470,
    SPELL_CONTROLLED_CHAOS_DMG_MASS = 219950,
    SPELL_PARASITIC_FETTER_FILTER   = 218424,
    SPELL_PARASITIC_FETTER_DOT      = 218304,
    SPELL_PARASITIC_FETTER_MARK     = 219278,
    SPELL_PARASITIC_FETTER_ROOT     = 219340,
    SPELL_SOLAR_COLLAPSE_FILTER     = 218148,

    //Phase 2
    SPELL_NIGHTOSIS_SUM_SOLARIST    = 216830,
    SPELL_TRANSFORM_NATURALIST      = 216832,

    //Phase 3
    SPELL_NIGHTOSIS_SUM_NATURALIST  = 216877,
    SPELL_TRANSFORM_ARCANIST        = 216878,
    SPELL_NIGHTOSIS_INIT_IMAGES     = 219334,
    SPELL_CALL_OF_NIGHT_FILTER      = 218807,
    SPELL_CALL_OF_NIGHT_AURA        = 218809,
    SPELL_CALL_OF_NIGHT_SCALE       = 218821,
    SPELL_CALL_OF_NIGHT_VISUAL_1    = 220249,
    SPELL_CALL_OF_NIGHT_VISUAL_2    = 220250,
    SPELL_CALL_OF_NIGHT_VISUAL_3    = 220251,
    SPELL_ARCANE_ECLIPSE            = 218838,

    //Solarist Telarn
    SPELL_ARCANE_DISSOLVE_IN        = 228343,
    SPELL_FLARE                     = 218806,
    SPELL_SUM_PLASMA_SPHERES        = 218774,
    SPELL_COLLAPSE_OF_NIGHT         = 223437,
    SPELL_SOLAR_INFUSION            = 222010,

    //Arcanist Telarn
    SPELL_ARCANE_INFUSION           = 222021,
    SPELL_SUMMON_CHAOS_SPHERES      = 223034,

    //Naturalist Telarn
    SPELL_TOXIC_SPORES_FILTER       = 219049,
    SPELL_TOXIC_SPORES_SUM          = 219231,
    SPELL_GRACE_OF_NATURE_AT        = 218927,
    SPELL_SUM_CHAOTIC_SPHERE_NATURE = 223219,
    SPELL_CHAOTIC_NATURE_10         = 223386,
    SPELL_CHAOTIC_NATURE_20         = 223387,
    SPELL_CHAOTIC_NATURE_30         = 223389,
    SPELL_NATURE_INFUSION           = 222020,

    //Controlled Chaos Stalker
    SPELL_CONTROLLED_CHAOS_VISUAL   = 239551,

    //Parasitic Lasher
    SPELL_PARASITIC_FIXATE          = 218342,
    SPELL_PARASITIC_FETTER_AT       = 218357,
    SPELL_RAMPANT_GROWTH            = 219248,

    //Solar Collapse Stalker
    SPELL_SOLAR_COLLAPSE_MISSLE_1   = 218152,
    SPELL_SOLAR_COLLAPSE_MISSLE_2   = 223734,

    //Plasma Sphere
    SPELL_PLASMA_SPHERE             = 218520,
    SPELL_PLASMA_EXPLOSION          = 218780,

    //Toxic Spore
    SPELL_TOXIC_SPORE_AT            = 219234,
    SPELL_TOXIC_SPORE_DMG           = 219235,

    //Other Trash
    SPELL_MANA_ORB_VISUAL           = 224840,
    SPELL_ARCANE_CHANNEL            = 224861,
    SPELL_ARCANE_CHANNEL_MISSILE    = 224885,
};

enum eEvents
{
    //Botanist
    EVENT_CONTROLLED_CHAOS          = 1,
    EVENT_PARASITIC_FETTER          = 2,
    EVENT_SOLAR_COLLAPSE            = 3,
    EVENT_PHASE_2                   = 4,
    EVENT_PHASE_3                   = 5,
    EVENT_CALL_OF_NIGHT             = 6,

    //Solarist
    EVENT_FLARE,
    EVENT_SUM_PLASMA_SPHERES,
    EVENT_COLLAPSE_OF_NIGHT,

    //Naturalist
    EVENT_TOXIC_SPORES,
    EVENT_GRACE_OF_NATURE,
    EVENT_CHAOTIC_SPHERE_NATURE,

    //Arcanist
    EVENT_SUMMON_CHAOS_SPHERES
};

Position const trashPos[10] =
{
    {635.94f, 2793.02f, 133.21f, 1.35f},
    {651.15f, 2788.29f, 125.40f, 2.74f},
    {653.66f, 2795.79f, 125.40f, 3.21f},
    {635.13f, 2776.43f, 125.40f, 1.50f},
    {632.93f, 2809.71f, 125.40f, 5.01f},
    {627.40f, 2777.16f, 125.40f, 1.09f},
    {625.17f, 2808.27f, 125.40f, 5.46f},
    {623.03f, 2783.73f, 125.40f, 0.68f},
    {621.46f, 2801.45f, 125.40f, 5.91f},
    {649.50f, 2802.33f, 125.40f, 3.67f}
};

Position const spherePos[3] =
{
    {655.05f, 2777.77f, 125.39f},
    {610.0f,  2787.85f, 125.40f},
    {640.28f, 2817.88f, 125.39f}
};

Position const botanistPos[3] =
{
    {684.93f, 2764.22f, 125.33f, 2.84f},
    {680.03f, 2756.45f, 125.33f, 2.34f},
    {672.75f, 2751.25f, 125.33f, 1.76f}
};

uint32 const botanistsEntry[3] =
{
    NPC_SOLARIST_TELARN,
    NPC_ARCANIST_TELARN,
    NPC_NATURALIST_TELARN
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,

    ACTION_1,
    ACTION_2,
    ACTION_3,
};

void AddSC_boss_high_botanist_telarn()
{
    
}
