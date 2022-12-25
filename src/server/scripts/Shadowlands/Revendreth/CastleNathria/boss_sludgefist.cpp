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
    SPELL_GIANT_FISTS_DUMMY = 335297,
    SPELL_GIANT_FISTS_DAMAGE = 335298,
    SPELL_HATEFUL_GAZE_MARK = 331209,
    SPELL_HEADLESS_CHARGE_MAIN = 339067,
    SPELL_HEADLESS_CHARGE_APPLY_AT = 339068, //21486
    SPELL_HEADLESS_CHARGE_CREATE_AT = 339069, //21487
    SPELL_DESTRUCTIVE_IMPACT = 332969,
    SPELL_CRUMBLING_FOUNDATION_PERIODIC = 332443,
    SPELL_CRUMBLING_FOUNDATION_DAMAGE = 332444,
    SPELL_COLLAPSING_FOUNDATION = 332197,
    SPELL_DESTRUCTIVE_STOMP = 332318,
    SPELL_FALLING_RUMBLE_MISSILE = 332552,
    SPELL_STONEQUAKE_AT_DAMAGE = 335361,
    SPELL_STONEQUAKE_CREATE_AT_ONE = 335371,//21139
    SPELL_STONEQUAKE_CREATE_AT_TWO = 348698,//22410
    SPELL_COLOSSAL_ROAR_CAST = 332687,
    SPELL_COLOSSAL_ROAR_DAMAGE = 332698,
    SPELL_GRUESOME_RAGE = 341250,
    //Heroic
    //Mythic
    SPELL_SEISMIC_SHIFT_TRIGGER = 340803,
    SPELL_SEISMIC_SHIFT_DAMAGE = 341087,
    SPELL_SEISMIC_SHIFT_TARGET_DEBUFF = 340817,
    ACTION_PILLAR_HIT,
    ACTION_WALL_HIT,
    EVENT_ENERGY_GAIN = 1,
};

void AddSC_boss_sludgefist()
{
   
}
