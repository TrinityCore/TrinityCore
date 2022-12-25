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
    EVENT_GAIN_ENERGY = 1,
    SPELL_LOOSE_ANIMA_PERIODIC_DAMAGE = 325184, //when player interact with container
    SPELL_CONTAINER_BREACH = 325225, //when container reach full energy
    SPELL_FOCUS_ANIMA_CREATE_AT = 331844, // 1409
    SPELL_EXPOSE_DESIRES = 325379,
    SPELL_EXPOSE_DESIRES_DAMAGE = 341621,
    SPELL_WARPED_DESIRES_DEBUFF = 325382,
    SPELL_EXPOSE_COGNITION = 341623,
    SPELL_SHARED_COGNITION = 325908,
    //Exposed
    SPELL_CHANGE_OF_HEART_TRIGGER = 340452,
    SPELL_BOTTLED_ANIMA_CAST = 339557,
    SPELL_BOTTLED_ANIMA = 342280,
    SPELL_BOTTLED_ANIMA_MISSILE = 339556,
    SPELL_BOTTLED_ANIMA_CREATE_AT = 329620, //24398
    SPELL_UNLEASHED_VOLATILY = 329618,
    SPELL_LINGERING_ANIMA_CREATE_AT = 325718, //24030
    SPELL_LINGERING_ANIMA_AT_DAMAGE = 325713,
    SPELL_LESSER_SINS_AND_SUFFERING = 342287,
    SPELL_ANIMA_WEB = 326139, //166766
    SPELL_SINS_OF_THE_PAST_DAMAGE = 326040,
    SPELL_INDEMNIFICATION_PERIODIC_DAMAGE = 331527,
    SPELL_SHARED_SUFFERING = 324983, // spellmisc 21630, missing data
    SPELL_GREATER_SINS_OF_SUFFERING = 342290,
    SPELL_LIGHTLY_CONCETRATED_ANIMA = 342320,
    SPELL_CONCENTRATED_ANIMA = 342321,
    SPELL_ROOTED_IN_ANIMA = 341746,
    EVENT_EXPOSED_COGNITION = 2,
    EVENT_EXPOSED_HEART,
    SPELL_CHANGE_OF_HEART_DAMAGE = 325384,
    EVENT_BOTTLED_ANIMA = 4,
    EVENT_LINGERING_ANIMA,
    EVENT_REPLICATING_ANIMA,
    SPELL_ANIMA_WEB_CREATE_AT = 339614, //21556, missing data
    SPELL_ANIMA_WEB_CREATE_AT_2 = 326094, //20155, missing data
    SPELL_ANIMA_WEB_AT_DAMAGE = 339612,
    EVENT_LIGHTLY_CONCETRATED_ANIMA = 7,
    EVENT_CONCENTRATED_ANIMA,
    EVENT_HIGHLY_CONCENTRATED_ANIMA,
    SPELL_CONCETRATED_ANIMA_PERIODIC_DAMAGE = 332664,
    SPELL_HIGHLY_CONCETRATED_ANIMA_CAST = 342322,
    SPELL_FRAGMENTS_OF_SHADOW_DAMAGE = 325596,
    SPELL_FRAGHMENTS_OF_SHADOW_CREATE_AT = 327125,
};

void AddSC_boss_lady_inerva_darkvein()
{
   
}