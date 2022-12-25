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

#include "AreaTriggerAI.h"
#include "thenighthold.h"
#include "Packets/MiscPackets.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
};

enum Spells
{
    SpellStarBurst                      = 205486,
    SpellCoronalEjection                = 205554,
    SpellCoronalEjectionSummon          = 205556,
    SpellCoronalEjectionDmg             = 206464,
    SpellCoronalEjectionFilter          = 208276,
    SpellCoronalEjectionVisual          = 205563,

    SpellPhase2Conversation             = 222130,
    SpellIceBurst                       = 206921,
    SpellCometImpact                    = 206628,
    SpellAbsoluteZero                   = 206585,
    SpellChilled                        = 206589,
    SpellFrozenSolid                    = 206603,
    SpellIcyEjection                    = 206936,
    SpellShatter                        = 206938,
    SpellFrigidNove                     = 206949,
    SpellFrigidNoveDamage               = 206954,

    SpellPhase3Conversation             = 222133,
    SpellFelBurst                       = 206388,
    SpellFelEjection                    = 205649,
    SpellFelFlameAtSpawn                = 206399,
    SpellFelFlameAreaDamage             = 206398,
    SpellFelImpact                      = 208426,
    SpellFelImpactMissile               = 206433,
    SpellFelNove                        = 206517,

    SpellPhase4Conversation             = 222134,
    SpellVoidBurst                      = 214486,
    SpellVoidBurstDot                   = 206965,
    SpellVoidBurstVisual_1              = 214425,
    SpellVoidBurstVisual_2              = 214426,
    SpellVoidEjection                   = 207143,
    SpellVoidImpact                     = 207768,
    SpellWitnessTheVoid                 = 207720,
    SpellVoidShiftAT                    = 207716,
    SpellVoidShiftAT_2                  = 208438,
    SpellVoidShiftMod                   = 207714,
    SpellVoidEruption                   = 207145,
    SpellVoidNova                       = 207439,
    SpellBurstingVoid                   = 227492,

    SpellGravitationalPull              = 205984,
    SpellNetherTraversal                = 221875,
    SpellBigBang                        = 222761,

    SpellPreCombatVisual                = 232550,

    //Mythic
    SPELL_GRAND_CONJUNCTION             = 205408,
    SPELL_GRAND_TRINE                   = 207831,
    SPELL_STAR_SIGN_CRAB                = 205429,
    SPELL_STAR_SIGN_WOLF                = 205445,
    SPELL_STAR_SIGN_DRAGON              = 216344,
    SPELL_STAR_SIGN_HUNTER              = 216345,
    SPELL_FEL_EMBER_AURA                = 227446,

    //Ice Crystal
    SPELL_ICE_CRYSTAL_AURA              = 216696,

    //Eye of the Void (109082, 109088)
    SPELL_WORLD_DEVOURING_FORCE         = 216909,
    SPELL_VOID_DISSOLVE_IN              = 216900,
    SPELL_EYE_VOID_DISSOLVE             = 216984,
    SPELL_WORLD_DEVOURING_FORCE_DUMMY   = 217039,

    //Remnant of the Void
    SPELL_DEVOURING_REMNANT_FILTER      = 217048,
    SPELL_DEVOURING_REMNANT_CHANELL     = 217046,
    SPELL_DEVOURING_REMNANT_DMG         = 217054,
};

enum Phases
{
    Phase0 = 1,
    Phase1 = 2,
    Phase2 = 3,
    Phase3 = 4
};

enum MiscData
{
    AreaTiggerFelFlameID        = 10916,
    NpcThingThatShouldNotBe     = 104880,

    DATA_ETRAEUS_CONJUNCTION_COUNT
};

Position const centrPos = {607.76f, 3187.98f, 195.95f};

void AddSC_boss_star_augur_etraeus()
{
    
}
