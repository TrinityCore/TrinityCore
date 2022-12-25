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
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

namespace
{
    enum Says
    {
        SAY_RAID_CAST = 5,
        SAY_BERSERK
    };

    enum Spells
    {
        SpellBerserkCharge = 232173,
        SpellBrineyVolatileFoam = 228810,
        SpellBrineyVolatileFoam2 = 228811,
        SpellFlamingVolatileFoam = 228744,
        SpellFlamingVolatileFoam2 = 228794,
        SpellFlashingFangs = 227514,
        SpellGuardiansBreath = 228187,
        SpellHeadlongCharge = 227816,
        SpellHeadlongChargeAT = 227833,
        SpellHelyatosis = 231561,
        SpellOffTheLeash = 228201,
        SpellRoaringLeap = 227883,
        SpellRoaringLeapJump = 229350,
        SpellShadowyVolatileFoam = 228818,
        SpellShadowyVolatileFoam2 = 228819,
        SpellVolatileFoam = 228824,
        SpellMultyHeaded = 227642,
        SpellMultyHeadedTooltip = 227512,
        SpellHelyatosis_AddPower = 235130,
        SpellGuardiansBreath_1 = 227666,
        SpellGuardiansBreath_2 = 227669,
        SpellGuardiansBreath_3 = 227673,
        SpellClearAllDebuffs = 34098,
        SpellFlameLick = 228226,
        SpellFrostLick = 228246,
        SpellShadowLick = 228250,
        SpellFieryPhlegm = 228758,
        SpellDarkDischarge = 228769,
        SpellSaltySpittle = 228768,
        SpellBerserk = 64238,
        SpellShadowLickAura = 228253,
        SpellHeadlongChargeDmg = 229480,
        SpellFrothingRage = 228174,
        SpellFieryPhlegmAOE = 227539,
        SpellDarkDischargeAOE = 227570,
        SpellSaltySpittleAOE = 227566
    };

    enum Events
    {
        EVENT_OFF_THE_LEASH = 1,
        EVENT_HEADLONG_CHARGE = 2,
        EVENT_HEADLONG_CHARGE_WP = 3,
        EVENT_ROARING_LEAP = 4,
        EVENT_ROARING_LEAP_JUMP = 5,

        EVENT_FLAME_LICK = 6,
        EVENT_FROST_LICK = 7,
        EVENT_SHADOW_LICK = 8,

        EVENT_POINT_2 = 9,
        EVENT_POINT_3 = 10,
        EVENT_POINT_COMPLETE = 11,

        //MYTHIC
        EVENT_FLAMING_VOLATILE_FOAM = 12,
        EVENT_BRINEY_VOLATILE_FOAM = 13,
        EVENT_SHADOWY_VOLATILE_FOAM = 14
    };

    enum Phase
    {
        PHASE_1 = 1,
        PHASE_2
    };
}

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
};

uint32 RandSpellGuardiansBreath[3] =
{
    SpellGuardiansBreath_1,
    SpellGuardiansBreath_2,
    SpellGuardiansBreath_3
};

Position const WPphaseTwo[3] =
{
    { 451.0492f,    545.6583f, 3.07493f, 0.0f },
    { 476.35119f,   551.8374f, 2.42583f, 0.0f },
    { 482.3681f,    450.1896f, 5.06133f, 0.0f }
};

void AddSC_boss_garm()
{
   
}
