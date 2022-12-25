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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "uldir.h"

const Position middle_pos = { -268.0f, -255.0f, 695.302f, 3.27f };
const Position cudgel_retrive_pos = { -296.0f, -250.0f, 695.538f, 3.14f };

//Weapon ID 160116

enum Texts
{
    SAY_DEPLOY_CUDGEL = 1,
    SAY_RETRIEVE_CUDGEL = 0,
    SAY_POWERED_DOWN = 2,
    SAY_DEATH,
    SAY_AGGRO = 4,
    SAY_PLASMA_DISCHARGE,
    SAY_POWERED_DOWN_ENDS = 7,
    SAY_WIPE = 9,
};

enum Spells
{
    //Phase one
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
	SPELL_PLASMA_DISHARGE_DUMMY = 271222,
    SPELL_PLASMA_DISCHARGE_PERIODIC = 278889, //137578
    SPELL_PLASMA_AT_DAMAGE = 271225,
	SPELL_BLOOD_STORM_AT_DAMAGE = 270290,
	SPELL_CUDGEL_OF_GORE_CHARGE  = 271296, //138017
    SPELL_CUDGEL_OF_GORE_DAMAGE_KNOCK = 271811,
	SPELL_SANGUINE_STATIC = 272582,
	SPELL_POWERED_DOWN    = 271965,
    //Phase two
	SPELL_RETRIEVE_CUDGEL = 271728,	
	SPELL_COMBUSTIBLE_FUEL = 272584,
	SPELL_SLOUGH_OFF       = 273179,
    SPELL_ULDIR_DEFENSIVE_BEAM_MAIN = 275441, //npc 1402846 is using this // visual which triggering also fast periodic aura damage
	SPELL_ULDIR_DEFENSIVE_BEAM_CREATE_AT = 274921,
    SPELL_ULDIR_DEFENSIVE_BEAM_DAMAGE = 268253,
    //Mythic
    SPELL_ENLARGED_HEART = 275205, //tank
    SPELL_HARDENED_ARTERIES_DEBUFF = 275189,
    SPELL_HARDENED_ARTERIES_EXP = 275193,
};

enum Events
{
    EVENT_PLASMA_DISCHARGE = 1,
    EVENT_CUDGEL_OF_GORE,
    EVENT_INIT_PHASE_TWO,
    EVENT_MYTHIC_MECHANICS,
    EVENT_ULDIR_DEFENSIVE_BEAM
};

void AddSC_boss_taloc()
{
    
}