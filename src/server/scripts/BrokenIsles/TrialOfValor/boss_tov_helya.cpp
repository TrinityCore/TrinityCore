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

#include "trial_of_valor.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_INTRO_1 = 11,
    SAY_INTRO_2,
    SAY_INTRO_3,
    SAY_AGGRO,
    SAY_BILEWATER_BREATH,
    SAY_PHASE_2 = 6,
    SAY_PHASE_3,
    SAY_ORB_OF_CORROSION,
    SAY_CORRUPTED_BREATH,
    SAY_DEATH
};

enum Spells
{
    SpellHelyaBluePower = 232229,
    SpellHelyaPurplePower = 232230,
    SpellBerserk = 64238,
    SpellBilewaterBreath = 227967,
    SpellBilewaterBreathDmg = 230229,
    SpellBilewaterBreathNpc = 230216,
    SpellBilewaterLiquefactionDmg = 227992,
    SpellBilewaterLiquefactionKill = 227993,
    SpellBilewaterRedox = 227982,
    SpellRemoveDebuffs = 34098,
    SpellHelyaImmunityDamage = 228847,
    SpellHelyaAltPower = 228372,
    SpellHelyaReuse = 200239,
    SpellCorruptedBreath = 228565,
    SpellCorruptedBreathDmg = 228566,
    SpellReanimation1 = 228104,
    SpellReanimation2 = 234199,
    SpellHelyaVisualTentacles = 228772,
    SpellHelyaVisualTentacles1 = 228778,
    SpellRideVehicleHardcoded = 46598,
    SpellFuryoftheMaw = 228032,
    SpellFuryOfTheMawAT = 230356,
    SpellFureOfTheMawLong = 228300,
    SpellRagingTempest = 201119,
    SpellHelyaAltPowerRegen = 228546,
    SpellTaintOfTheSea = 228054,
    SpellTaintOfTheSeaDmg = 228053,
    SpellOrbOfCorruption = 227903,
    SpellOrbOfCorruptionSpawnAura = 227906,
    SpellOrbOfCorruptionVisual = 227939,
    SpellOrbOfCorruptionDmg = 227930,
    SpellOrbOfCorruptionAuraProc = 227926,
    SpellOrbofCorruptionOnPlayer = 229119,
    SpellOrbOfCorrosion = 228056,
    SpellOrbOfCorrosionSpawnAura = 228057,
    SpellOrbOfCorrosionVisual = 228060,
    SpellOrbOfCorrosionAuraProc = 228061,
    SpellOrbofCorrosionOnPlayer = 230267,
    SpellOrbOfCorrosionShare = 228062,
    SpellOrbOfCorrosionDmg = 228063,
    SpellBilewaterLiquefaction = 227990,
    SpellBilewaterLiquefactionScale = 228984,
    SpellSlimey = 154241,
    SpellCorrosiveNova = 228872,
    SpellTorrent = 228514,
    SpellBuildingStorm = 228803,
    SpellAnchorSlam = 228519,
    SpellSludgeNova = 228390,
    SpellFetidRotHit = 228397,
    SpellFetidRot = 193367,
    SpellTaintedEssence = 228052,
    SpellGiveNoQuarter = 228632,
    SpellLanternOfDarkness = 228619,
    SpellDarkness = 228383,
    SpellGhostlyRage = 228611,
    SpellRallyOfTheKvaldir = 232346,
    SpellDecay = 228121,
    SpellVigor = 203816,
    SpellRabid = 202476,
    SpellTentacleSlam = 228731,
    SpellDarkHatred = 232488,
    SpellCorruptedAxion = 232418,
    SpellCorruptedAxionAOE = 232452,
    SpellCorruptedAxionAura = 232450,
    SpellCorrupted = 232350,
    SpellBleakEruption = 231862,
    SpellMistInfusion = 228854,
    SpellTentacleStrike = 228730
};

enum Events
{
    EVENT_TAINT_OF_THE_SEA = 1,
    EVENT_TENTECLE_STRIKE = 2,
    EVENT_ORB_OF_CURRUPTION = 3,
    EVENT_TORRENT = 4,
    EVENT_TELEPORT_OUTSIDE = 5,
    EVENT_TELEPORT_HOME = 6,
    EVENT_ORB_OF_CORROSION = 7,
    EVENT_FURY_OF_THE_MAW = 8,
    EVENT_FURY_OF_THE_MAW_CLEAN_AT = 9,
    EVENT_REANIMATION = 10,
    EVENT_SUMMON_SKELETION = 11,
    EVENT_BOAT = 12
};

enum Phase
{
    PHASE_1 = 1,
    PHASE_2,
    PHASE_3
};

Position const Pos_AncientBonethrall[3] =
{
    { 542.715f, 614.908f, 6.76841f, 2.33339f },
    { 539.062f, 640.273f, 3.53224f, 2.64075f },
    { 537.57f, 629.615f, 6.64555f, 3.21549f }
};

Position const Pos_DarkSeraph[4] =
{
    { 454.929f, 595.392f, 4.5516f, 4.69926f },
    { 433.75f, 673.292f, 11.1958f, 5.168f },
    { 453.01f, 676.46f, 16.4407f, 4.31975f },
    { 564.712f, 671.016f, 22.047f, 4.89319f }
};

Position const Pos_KvaldirTideWitch[5] =
{
    { 438.646f, 669.132f, 7.11206f, 4.94863f },
    { 446.311f, 669.043f, 7.02397f, 4.97584f },
    { 466.095f, 698.087f, 18.0504f, 4.31252f },
    { 564.804f, 664.471f, 18.0398f, 3.0071f },
    { 462.96f, 707.84f, 18.048f, 2.79169f }
};

Position const Pos_KvaldirReefcaller[8] =
{
    { 554.536f, 659.163f, 18.04f, 3.40563f },
    { 497.158f, 649.146f, 1.93921f, 1.00977f },
    { 502.023f, 640.695f, 1.92648f, 1.16326f },
    { 490.314f, 647.658f, 1.95429f, 0.897942f },
    { 500.812f, 646.582f, 1.92656f, 1.08693f },
    { 484.189f, 647.012f, 2.10088f, 0.805534f },
    { 575.047f, 653.731f, 18.0399f, 3.20372f },
    { 503.719f, 634.96f, 1.9753f, 1.21486f }
};

Position const Pos_DeepbrineMonstrosity[4] =
{
    { 465.504f, 641.476f, 5.21661f, 0.582881f },
    { 523.799f, 662.377f, 2.27014f, 3.65067f },
    { 500.641f, 674.398f, 2.22507f, 4.62842f },
    { 471.521f, 708.076f, 18.0694f, 0.768197f }
};

Position const StrikingTentacle[3] =
{
    //{ 466.0955f, 698.0868f, 18.05038f, 4.312522f },
    //{ 564.8038f, 664.4705f, 18.03976f, 3.007097f },
    { 525.5886f, 678.2604f, 2.877361f, 4.050999f },
    { 505.826f, 693.526f, 2.877363f, 4.66783f },
    { 475.3333f, 606.6406f, 2.891779f, 0.9923878f }
};

Position const skeletionPos[10] =
{
    { 529.276f, 702.028f, -2.0632f, 4.31416f },
    { 539.448f, 699.825f, -2.43245f, 4.31416f },
    { 522.04f, 709.505f, -2.51397f, 4.31416f },
    { 503.182f, 583.628f, -0.529175f, 1.36772f },
    { 491.255f, 586.115f, -0.529175f, 1.4199f },
    { 515.188f, 580.21f, -0.529175f, 1.33011f },
    { 482.042f, 590.741f, -0.529178f, 1.5545f },
    { 528.059f, 583.365f, -0.529168f, 1.75563f },
    { 517.481f, 719.132f, -3.38609f, 4.31416f },
    { 549.359f, 698.911f, -3.12035f, 4.31416f }
};

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
};

void AddSC_boss_helya_tov()
{
    
}
    
