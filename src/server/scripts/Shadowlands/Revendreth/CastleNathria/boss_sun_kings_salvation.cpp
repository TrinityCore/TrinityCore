/*
* Copyright (C) 2021 AzgathCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    SPELL_GREATER_CASTIGNATION_CAST = 328885,
    SPELL_GREATER_CASTIGNATION_PERI_DUMMY = 328889, //aura
    SPELL_GREATER_CASTIGNATION_CHANNEL = 328894,
    SPELL_GREATER_CASTIGNATION_DAMAGE = 328890,
    ACTION_SPAWN_ADDS = 1,
    SPELL_FIERY_STRIKE = 326455,
    SPELL_BURNING_REMNANTS = 326456,
    EVENT_GAIN_ENERGY = 2,
    SPELL_BLAZING_SURGE = 329518,
    SPELL_BLAZING_SURGE_MISSILE = 329515,
    SPELL_SMOLDERING_REMNANTS_AT_DAMAGE = 328579,
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_ONE = 328658,//20432
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_TWO = 328578, //20427
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_THREE = 328600, //20428
    SPELL_SMOLDERING_PLUMAGE_PERIODIC_TRIGER = 328659, // triggers smoldering remnants
    SPELL_SMOLDERING_PLUMAGE_DAMAGE = 340499,
    SPELL_EMBER_BLAST_CAST = 325877,
    SPELL_LINGERING_EMBERS_PERIODIC = 326430, //triggers from hit by ember blast
    SPELL_SOUL_INFUSION = 325665, //peri dummy
    SPELL_DRAINED_SOUL_DEBUFF = 339251,
    //Heroic
    SPELL_FRAGMENTATION = 336398,
    //Mythic
    SPELL_CLOAK_OF_FLAMES_ABSORB = 343026, //531461
    SPELL_UNLEASHED_PYROCLASM = 343025,
    SPELL_SUMMON_ESSENCE_FONT = 329565,
    SPELL_CRACKED_RESERVOIR = 329539,
    SPELL_ESSENCE_OVERFLOW = 329561,
    SPELL_PHOENIX_FLGIHT = 342474,
    SPELL_REFLECTION_OF_GUILT = 323402,
    ACTION_RESET_ENCOUNTER = 2,
};

void AddSC_boss_sun_kings_salvation()
{
  
}
