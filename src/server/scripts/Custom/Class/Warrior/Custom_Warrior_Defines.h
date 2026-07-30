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

#ifndef CUSTOM_WARRIOR_DEFINES_H
#define CUSTOM_WARRIOR_DEFINES_H

#include "Define.h"

namespace Scripts::Custom::Warrior
{
    namespace Spells
    {
        // Core warrior spells
        static constexpr uint32 BERSERKER_RAGE                    = 18499;
        static constexpr uint32 ENRAGE                            = 184362;
        static constexpr uint32 SHIELD_WALL                       = 871;
        static constexpr uint32 REND                              = 772;
        static constexpr uint32 REND_AURA                         = 388539;
        static constexpr uint32 CLEAVE                            = 845;
        static constexpr uint32 IMPROVED_WHIRLWIND                = 12950;
        static constexpr uint32 WHIRLWIND_CLEAVE_AURA             = 85739;
        static constexpr uint32 MEAT_CLEAVER_TALENT               = 280392;
        static constexpr uint32 RAVAGER                           = 228920;
        static constexpr uint32 EXECUTE                           = 20647;

        // Sweeping Strikes
        static constexpr uint32 SWEEPING_STRIKES                  = 260708;
        static constexpr uint32 COLLATERAL_DAMAGE                 = 334779; 
        static constexpr uint32 COLLATERAL_DAMAGE_BUFF            = 334783;

        // Bladestorm
        static constexpr uint32 BLADESTORM_PERIODIC_WHIRLWIND     = 50622;

        // Thirst for Battle
        static constexpr uint32 THIRST_FOR_BATTLE                 = 199202;
        static constexpr uint32 THIRST_FOR_BATTLE_BUFF            = 199203;

        // Slam / Fervor of Battle
        static constexpr uint32 SLAM_ARMS                         = 1464;
        static constexpr uint32 FERVOR_OF_BATTLE                  = 202316;

        // Wrecking Ball
        static constexpr uint32 WRECKING_BALL_EFFECT              = 215570;

        // Second Wind
        static constexpr uint32 SECOND_WIND_6PC                   = 202147; // 202149;
        static constexpr uint32 SECOND_WIND_2PC                   = 458245;

        // Indomitable
        static constexpr uint32 INDOMITABLE_HEAL                  = 316643;

        // Champion's Spear
        static constexpr uint32 CHAMPIONS_SPEAR_AURA              = 376080;
        static constexpr uint32 CHAMPIONS_SPEAR_CHAIN_VISUAL      = 376085;
        static constexpr uint32 CHAMPIONS_SPEAR_PULL              = 376084;

        // Ravager
        static constexpr uint32 RAVAGER_RAGE_GAIN                 = 334934;
        static constexpr uint32 RAVAGER_PERIODIC_DAMAGE           = 156287;
        static constexpr uint32 RAVAGER_SUMMON                    = 227876;

        // Honed Reflexes affected spells
        static constexpr uint32 DIE_BY_THE_SWORD                  = 118038;
        static constexpr uint32 ENRAGED_REGENERATION              = 184364;
        static constexpr uint32 INTERVENE                         = 3411;
        static constexpr uint32 SPELL_REFLECTION                  = 23920;
        static constexpr uint32 STORM_BOLT                        = 107570;
        static constexpr uint32 PUMMEL                            = 6552;

        // Crushing Combo
        static constexpr uint32 CRUSHING_COMBO_BUFF               = 1261189;

        // Dreadnaught
        static constexpr uint32 DREADNAUGHT                       = 262150;
        static constexpr uint32 DREADNAUGHT_DAMAGE                = 315961;

        // Fearless (Berserker Rage talent)
        static constexpr uint32 FEARLESS                          = 1271925;

        // Wrecking Throw
        static constexpr uint32 WRECKING_THROW_DAMAGE             = 394354;

        // Defensive Stance
        static constexpr uint32 DEFENSIVE_STANCE                  = 386208;
        static constexpr uint32 DEFENSIVE_STANCE_SPIKE_TALENT     = 1280961;

        // Shattering Throw
        static constexpr uint32 SHATTERING_THROW_DISPEL           = 64380;

        // Legendary - Unbreakable Will
        static constexpr uint32 UNBREAKABLE_WILL                  = 335629;
        static constexpr uint32 UNBREAKABLE_WILL_PROC             = 335635;

        // Misc Visuals
        static constexpr uint32 SPELL_VISUAL_RAVAGER = 36990;
    }
}

#endif // CUSTOM_WARRIOR_DEFINES_H
