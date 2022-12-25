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
#include "GameObject.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"

enum Spells
{
    SpellSlam = 205862,
    SpellSlamATRight = 205880,
    SpellSlamATLeft = 205881,
    SpellSlamTriggerOnCircles = 205863,
    SpellSlamTriggerAOE = 225362,
    SpellSlamSmash = 205875,

    SpellSearingBrand = 206677,

    SpellFelBurst = 206620,

    SpellFelBeamController = 205383,
    SpellFelBeam = 205370,
    SpellFelBeamDamage = 205391,

    SpellOrbDestruction = 205344,
    SpellOrbDestructionCast = 205361,

    SpellBurningPitchPrecast = 205420,
    SpellBurningPitchVisual = 206307,
    SpellBurningPitchVisual2 = 206281,
    SpellBurningPitchSummon = 206350,
    SpellBurningPitchDamage = 206376,
    SpellBurningPitchModDamage = 215944, //Deprecated?

    SpellIsolatedRageAura = 208201,
    SpellIsolatedRageDmg1 = 208203,
    SpellIsolatedRageDmg2 = 208194,

    SpellFelBlast = 209017,
    SpellFelBlust = 206351,
    SpellAccelerate = 209006,
    SpellBurnout = 214141,

    //Christmas
    SPELL_CHRISTMAS_CAP = 220518
};

Position const movementPositions[] =
{
    { -96.519f, 2794.32f, 3.659f },
    { -71.430f, 2809.25f, 3.659f },
    { -46.430f, 2824.25f, 3.659f },
    { -21.430f, 2839.25f, 3.659f },
};

Position const slamAtPositions[] =
{
    { -101.97f, 2783.92f, 3.16f },
    {  -75.62f, 2799.22f, 3.16f },
    {  -48.81f, 2813.67f, 3.16f },
    {  -22.03f, 2828.23f, 3.16f },

    { -108.36f, 2795.58f, 3.16f },
    {  -81.57f, 2809.99f, 3.16f },
    {  -55.22f, 2825.28f, 3.16f },
    {  -29.28f, 2841.07f, 3.16f }
};

struct BurningPitchData
{
    Position PosMin;
    Position PosMax;
};

BurningPitchData burningPitches[] =
{
    { { -107.091537f, 2780.961914f }, { -15.032656f, 2848.733643f } },
    { { -80.678909f, 2797.868408f }, { -17.259027f, 2848.385010f } },
    { { -58.884304f, 2809.939209f }, { -16.224754f, 2849.433594f } },
    { { -38.795380f, 2816.897949f }, { -11.434778f, 2850.490723f } }
};

struct LinesData
{
    Position Pos1;
    Position Pos2;
    Position Pos3;
    Position Pos4;
};

LinesData LinezCrossData[] =
{
    { { -28.321032f, 2848.733643f, 3.17f }, { -15.032656f, 2824.966309f, 3.17f }, { -92.455811f, 2780.961914f, 3.17f }, { -107.091537f, 2804.419189f, 3.17f } },
    { { -31.217550f, 2848.385010f, 3.17f }, { -17.259027f, 2827.575684f, 3.17f }, { -65.974739f, 2797.868408f, 3.17f }, { -80.678909f, 2818.099121f, 3.17f } },
    { { -28.304945f, 2849.433594f, 3.17f }, { -16.224754f, 2826.051514f, 3.17f }, { -47.342018f, 2809.939209f, 3.17f }, { -58.884304f, 2834.493408f, 3.17f } },
    { { -22.711079f, 2850.490723f, 3.17f }, { -11.434778f, 2828.723633f, 3.17f }, { -25.173914f, 2816.897949f, 3.17f }, { -38.795380f, 2846.193604f, 3.17f } }
};

Position const PlatformMid[] =
{
    { -62.388672f, 2814.183105f, 3.17f },
    { -51.350227f, 2820.720215f, 3.17f },
    { -37.900650f, 2828.584717f, 3.17f },
    { -23.073122f, 2837.892090f, 3.17f }
};

Position const lineBeamPos[2] =
{
    {-111.67f, 2785.84f, 3.16f},
    {-12.48f, 2843.19f, 3.24f}
};

struct Lines
{
    Position Pos1;
    Position Pos2;
};

void AddSC_boss_krosus()
{
    
}
