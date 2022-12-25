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
#include "the_motherlode.h"
#include "AreaTrigger.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_CHEMICAL_BURN_MISSILE = 259856,

    SPELL_AZERITE_CATALYST_AURA = 259533,
    SPELL_AZERITE_CATALYST_MISSILE = 259327,
    SPELL_AZERITE_CATALYST_AT = 259023, // 259787 ?! or this

    SPELL_PROPELLANT_BLAST_PUSHBACK = 270075,
    SPELL_PROPELLANT_BLAST_AURA = 260103,
    SPELL_PROPELLANT_BLAST	= 260669, // also AT

	SPELL_TOXIC_SLUDGE = 269831,
    SPELL_SEARING_REAGENT	= 280497,
	
};

enum Events
{
    EVENT_PROPELLANT_BLAST = 1,
    EVENT_CHEMICAL_BURN,
    EVENT_AZERITE_CATALYST,
    EVENT_SEARING_REAGENT,

    EVENT_CATALYST_PATCHES,
};

enum Timers
{
    TIMER_PROPELLANT_BLAST = 20 * IN_MILLISECONDS,
    TIMER_CHEMICAL_BURN = 30 * IN_MILLISECONDS,
    TIMER_SEARING_REAGENT = 2 * IN_MILLISECONDS,
    TIMER_AZERITE_CATALYST = 12 * IN_MILLISECONDS,

    TIMER_CATALYST_PATCHES = 40 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_RIXXA_FLUXFLAME = 129231,

    NPC_CATALYST_PIPE_STALKER = 141160,
    NPC_SPRAY_STALKER = 137452,
};

const Position centerPos = { 1273.14f, -3698.62f, 26.71f }; //40 y

#define AGGRO_TEXT "If you want a job done right... use bigger explosives!"
#define AZERITE_CATALYST "Lookin' for Azerite? Have a face full!"
#define PROPELLANT_BLAST "Safety first!"
#define DEATH_TEXT "I shoulda... gotten... hazzard pay.."

void AddSC_boss_rixxafluxflame()
{
    
}
