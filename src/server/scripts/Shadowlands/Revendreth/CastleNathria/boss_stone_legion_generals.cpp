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
    //Grashaal
    SPELL_STONE_SPIKE_MISSILE = 170926,
    SPELL_STONE_BREAKERS_COMBO = 339645,
    SPELL_CRYSTALIZE_CHANNEL = 339690,
    SPELL_CRYSTALLINE_BURST_DAMAGE = 339693,
    SPELL_PULVERIZING_METEOR_MISSILE = 342544,
    SPELL_STONE_FIST = 342425,
    SPELL_SEISMIC_UPHEAVAL_MISSILE = 337595,
    SPELL_REVERBERATING_ERUPTION_MARK = 344496,
    SPELL_REVERBERATING_ERUPTION_DAMAGE_SUMMON = 344500,
    //Kaaal
    SPELL_SERRATED_SWIPE = 334929,
    SPELL_HEART_REND = 334765,
    SPELL_HEART_HEMORRAGE = 334771, //triggers from rend after dispel and expire
    SPELL_WICKED_BLADE = 333387,
    SPELL_HARDENED_STONEFORM = 329636,
    SPELL_ANIMA_ORB_CREATE_AT = 332393, //20793
    EVENT_STONEFORM_ADDS = 1,
    ACTION_PHASE_TWO = 2,
    ACTION_PHASE_THREE,
    SPELL_RICOCHETING_SHURIKEN = 343086,
    //Prince Renathal
    SPELL_SHATTERING_BLAST = 332683,
    //Stalker
    SPELL_UNSTABLE_GROUND_APPLY_AT = 344503,//21991
    SPELL_ECHOING_ANNIHILATION = 344721,
    SPELL_REVERBERATING_VULNERABILITY = 344655,
    SPELL_ECHOING_BLAST = 344740,
    SPELL_SOLDIERS_OATH = 336212,
};

void AddSC_boss_stone_legion_generals()
{
  
}