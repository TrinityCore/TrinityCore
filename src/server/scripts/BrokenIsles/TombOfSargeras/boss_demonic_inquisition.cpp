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

#include "tomb_of_sargeras.h"

enum Spells
{

    // 116689
    SPELL_BONE_SCYTHE = 233423, // aura
    SPELL_SCYTHE_SWEEP = 233426,

    SPELL_BONE_SAW = 233441, // 100% energy
    SPELL_BONE_SAW_ENERGY = 234550, // proc


    SPELL_DEBUFF_OVERRIDE = 233103,  // 233652
    SPELL_DEBUFF_OVER_AURA = 233104,
    SPELL_DEBUFF_OVER_AURA1 = 234364,
    SPELL_DEBUFF_UNBEAR_TOR = 233430,

    // not normal 
    SPELL_CALCIFIED_QUILS = 233431, // 233432(233435)

    // 116691
    SPELL_GET_ENERGY = 246454,
    SPELL_ECHOING_ANGUISH = 233983, // 22
    SPELL_FEL_SQUAL = 235230, // 100%
    SPELL_FEL_SQUAL_ENERGY = 235237,

    SPELL_TORMENTING_BURST = 234015, // 17
    SPELL_PANGS_OF_GUILT = 239401, // 10

    // not normal
    SPELL_SUFFOCATING_DARK = 233894, // 24

    SPELL_AOE_SILENCE = 250306, // ????
    SPELL_REGENERATE_ENERGY = 246455,
    SPELL_ENRAGE = 248671, // 720 secs

    SPELL_BELAC_PRISONER = 236283,
    SPELL_SOUL_CORRUPTION = 248713,
};

enum eEvents
{
    EVENT_SCYTHE_SWEEP = 1,
    EVENT_CALCIFIED_QUILS,

    EVENT_ECHOING_ANGUISH,
    EVENT_PANGS_OF_GUILT,
    EVENT_TORMENTING_BURST,
    EVENT_SUFFOCATING_DARK,

    EVENT_CHECK_ENERGY,
    EVENT_ENRAGE,
    EVENT_SUMMON_ADD,
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
};

std::map<uint32, uint32> hitSpells
{
    { SPELL_BONE_SAW , SPELL_BONE_SAW_ENERGY},
    { SPELL_FEL_SQUAL , SPELL_FEL_SQUAL_ENERGY}
};

void AddSC_boss_demonic_inquisition()
{

}
