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
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Object.h"
#include "GameObjectData.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "uldir.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_SHADOW_BARRAGE = 273359,
    SPELL_DARK_REVELATION_TRIGGER = 273365,
    SPELL_DARK_REVELATION_EXPLOSION = 273438,
    SPELL_DARK_REVELATION_SUMMON_MINION_OF_ZUL = 271967,
    SPELL_CALL_OF_BLOOD = 273889,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CRAWG = 273893,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CASTER_ADD = 274099,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_MELEE_ADD = 274122,
    //Phase 2
    SPELL_LOCUS_OF_CORRUPTION = 274168,
    SPELL_CORRUPTED_BLOOD_AURA = 274195,
    SPELL_RUPTURING_BLOOD_AURA = 274358,
    SPELL_RUPTURED_BLOOD_CREATE_AT = 274363,
    SPELL_DEATHWISH = 274271,
    SPELL_DEATHWISH_EXPLOSION = 275991,
    SPELL_DEATHWISH_JUMP = 274274,
    SPELL_POOL_OF_DARKNESS = 273361, //npc 139171
    SPELL_POOL_OF_DARKNESS_VISUAL_FORMING = 273360,
    SPELL_ERUPTING_DARKNESS_DAMAGE = 273363,
    SPELL_ABSORBED_DARKNESS_AURA = 274387,
    SPELL_BERSERK = 26662,
    //Minions
    SPELL_BLOODY_CLEAVE = 273316,
    SPELL_THRUMMING_PULSE = 273288,
    SPELL_BLOODSHARD = 273350,
    SPELL_CONGEAL_BLOOD = 273451, //npc 139195
    SPELL_DRIPPING_BLOOD = 274396,
    SPELL_ICHOR_TRANSFUSION = 273556,
    SPELL_HUNGERING_MAW_HEAL = 273255,
    SPELL_BLOOD_RECALL = 276659,
    SPELL_DECAYING_FLESH = 276434,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_CALL_OF_BLOOD,
    SAY_DARK_REVELATION,
    SAY_LOCUS,
    SAY_DEATHWISH,
    SAY_KILL,
    SAY_DEATH
};

enum Events
{
    EVENT_SHADOW_BARRAGE,
    EVENT_DARK_REVELATION,
    EVENT_CALL_OF_BLOOD,    
    EVENT_LOCUS_OF_CORRUPTION,
    EVENT_DEATHWISH,
    EVENT_RUPTURING_BLOOD,
    EVENT_POOL_OF_DARKNESS
};

void AddSC_boss_zul()
{
    
}
