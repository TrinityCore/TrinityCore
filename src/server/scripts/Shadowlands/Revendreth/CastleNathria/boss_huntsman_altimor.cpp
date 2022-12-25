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

enum HuntsmanAltimor
{
    SPELL_SPREADSHOT = 334404,
    SPELL_SINSEEKER = 335114, // every 45s, 3 targets
    SPELL_SINSEEKER_PERIODIC_DAMAGE = 335304,
    SPELL_SINSEEKER_INIT_DAMAGE = 335116,
    SPELL_SINSEEKER_CONVERSATION = 335488,
    SPELL_HUNTSMAN_BLOOD = 334504,

    //Margore 165067
    SPELL_JAGGED_CLAWS = 334971, // 10s, 20s, tank
    SPELL_VICIOUS_LUNGE_CIRCLE = 334939,
    SPELL_VICIOUS_LUNGE_MARK = 334945,
    SPELL_VICIOUS_LUNGE_CHARGE = 266947, // there is instakill

    //Bargast 169457
    SPELL_RIP_SOUL = 334797,
    SPELL_DEVOUR_SOUL = 334884,
    SPELL_SHADES_OF_BARGAST = 334757,
    SPELL_DEATHLY_ROAR = 334708,
    SPELL_DESTABILIZE = 334695,

    //Hecutis 169458
    SPELL_CRUSHING_STONE = 334860,
    SPELL_PETRIFYING_HOWL = 334852,
    SPELL_PETRIFYING_HOWL_CREATE_AT = 334889, //21100
    SPELL_STONE_SHARDS_AT_DAMAGE = 334893,
    SPELL_CHARGE = 343259,

    //Heroic
    SPELL_VICIOUS_WOUND = 334960,
    SPELL_RIPPED_SOUL_AOE = 339638,
    //Mythic
    SPELL_SHATTER_SHOT_DAMAGE = 338593,
};

void AddSC_boss_huntsman_altimor()
{
    
}
