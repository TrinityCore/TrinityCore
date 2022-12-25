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

#include "vault_of_the_wardens.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_DARKSTRIKES = 1,
    SAY_FURIOUS = 2,
    SAY_METAMORPH = 3,
    SAY_EVADE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_DARKSTRIKES = 191941,
    SPELL_DARKSTRIKES_DMG = 191948,
    SPELL_DARK_ENERGIES_ABSORB = 191999,
    SPELL_SWOOP = 191765,
    SPELL_SWOOP_JUMP = 191766,
    SPELL_FURIOUS_BLAST = 191823,
    SPELL_FEL_MORTAR = 202913,

    //Second Phase 50% HP
    SPELL_METAMORPHOSIS_HAVOC = 192504,
    SPELL_METAMORPHOSIS_VENGEANCE = 202740,
    //Havoc
    SPELL_SUMMON_LASER_BEAM = 202780,
    SPELL_LASER_BEAM_AT = 190830, //Hatred. Dmg 190836
    SPELL_LASER_BEAM_VISUAL = 190833,
    SPELL_LASER_BEAM_BETWEEN_DMG = 202862,

    //Other
    SPELL_JUMP_DOWN = 199132,
    SPELL_DUAL_WIELD = 42459,
};

//to-do: 191641 spell on trash

enum eEvents
{
    EVENT_DARKSTRIKES = 1,
    EVENT_SWOOP = 2,
    EVENT_METAMORPHOSIS = 3,
    EVENT_FEL_MORTAR = 4,
    EVENT_LASER_BEAM = 5,
};

enum Misc
{
    ACTION_1 = 1,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
};

void AddSC_boss_tirathon_saltheril()
{
   
}
