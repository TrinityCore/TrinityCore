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

#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerAI.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>
#include "AreaTrigger.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_TIDE_FIST = 296566,
    SPELL_RADIANT_FURY = 299093,
    SPELL_ARCANADO_BURST_CAST = 304065,
    SPELL_ARCANADO_MISSILE = 304066,
    SPELL_ARCANADO_HIT = 304067,
    SPELL_ARCANADO_AT_DAMAGE = 304070,
    SPELL_ARCANADO_AT = 304068,
    SPELL_ARCANE_BOMB_VEH = 304026,
    SPELL_ARCANE_BOMB_VIS = 192711, //temp
    SPELL_ARCANE_BOMB_CAST = 304025,
    SPELL_ARCANE_BOMB_DAMAGE = 296746,
    SPELL_RIDE_VEHICLE = 46598,
    SPELL_UNSHACKLED_POWER = 296894,
    SPELL_SQUALL_TRAP_DAMAGE = 296509,
    SPELL_SQUALL_TRAP_ARMING = 296459,
    SPELL_SQUALL_TRAP_MISSILE = 296506,
    SPELL_SQUALL_TRAP_AT = 296460,
    SPELL_ANCIENT_TEMPEST_DUMMY = 300307,
    SPELL_ANCIENT_TEMPEST_AT = 296342,
    SPELL_ANCIENT_TEMPEST_DAMAGE = 295921,
    SPELL_ANCIENT_TEMPEST_PERIODIC = 295920,
    SPELL_ANCIENT_TEMPEST_VISUAL_AT = 296341,
    SPELL_ANCIENT_TEMPEST_BOSS = 295916,
    SPELL_GALE_BUFFET = 296701,
    SPELL_FOCUS_POWER = 304951,
    SPELL_SWIRLING_WINDS = 296389,
    SPELL_CHAIN_LIGHTNING = 296673,
};

enum Events
{
    EVENT_ENERGY_CHECK = 1,
    EVENT_PHASE_CHANGE,
    EVENT_ARCANE_BOMB,
    EVENT_UNSHACKLED_POWER,
    EVENT_TIDE_FIST,
    EVENT_ARCANADO_BURST,
    EVENT_SQAULL_TRAP,
    EVENT_SUMMON_STORMLINGS,
    EVENT_ANCIENT_TEMPEST,
    EVENT_GALE_BUFFET,
    EVENT_CHAIN_LIGHTNING,
};

enum Timers
{
    TIMER_ENERGY_CHECK = 1 * IN_MILLISECONDS,
    TIMER_PHASE_CHANGE = 105 * IN_MILLISECONDS,
    TIMER_GALE_BUFFET = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_STORMLINGS = 20 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING = 10 * IN_MILLISECONDS,
    TIMER_ARCANE_BOMB = 17 * IN_MILLISECONDS,
    TIMER_SQUALL_RAP = 2 * IN_MILLISECONDS,
    TIMER_TIDE_FIST = 18 * IN_MILLISECONDS,
    TIMER_ARCANADO_BURST = 25 * IN_MILLISECONDS,
    TIMER_UNSHACKLED_POWER = 20 * IN_MILLISECONDS,
};

const Position squallTrapPosition[3][17] =
{
    // FIRST
    {
    {845.45f, 623.99f, 1295.96f},
    {838.16f, 623.64f, 1295.96f},
    {831.01f, 623.29f, 1295.96f},
    {825.02f, 622.99f, 1295.96f},
    {818.60f, 622.68f, 1295.96f},
    {811.80f, 622.34f, 1295.96f},
     {804.77f, 622.02f, 1295.96f},
     },

     //SECOND
     {
     {771.90f, 600.62f, 1295.96f},
     {770.58f, 593.38f, 1295.96f},
     {769.34f, 586.53f, 1295.96f},
     {768.00f, 579.16f, 1295.96f},
     {766.57f, 571.25f, 1296.20f},
     },

     //THIRD
     {
     {739.56f, 656.40f, 1295.96f},
     {732.63f, 661.55f, 1295.96f},
     {726.31f, 666.24f, 1295.96f},
     {720.05f, 670.88f, 1295.96f},
     {713.98f, 675.49f, 1296.92f},
     },
};

void AddSC_boss_radiance_of_azshara()
{
  
}
