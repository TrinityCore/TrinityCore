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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "spires_of_ascension.h"

enum Oryphrion
{
    SPELL_CHARGED_STOMP = 324608,
    SPELL_CHARGED_ANIMA = 338729,
    SPELL_PURIFYING_BLAST_DUMMY = 334053,
    SPELL_PURIFYING_BLAST_DAMAGE = 323195,
    SPELL_PURIFYING_BLAST_MISSILE = 323072,
    SPELL_EMPYREAL_ORDNANCE_VISUAL = 323375,
    SPELL_EMPYREAL_ORDNANCE_CAST = 324427,
    SPELL_EMPYREAL_ORDNANCE_MARK = 321936,
    SPELL_EMPYREAL_ORDNANCE_MISSILE = 323313,
    SPELL_EMPYREAL_ORDNANCE_DAMAGE = 323372,
    SPELL_DRAINED = 323878,
    ACTION_RESTART_EVENTS,
    //Mythic
    SPELL_RECHARGE_ANIMA = 324046,
    SPELL_ANIMA_CHARGE_EXP = 323373,
    SPELL_ANIMA_CHARGE_PERIOIDC = 331997,
    //165807
    SPELL_ANIMA_FIELD_APPLY_AT = 323791,
    SPELL_ANIMA_FIELD_DAMAGE = 323792,
};

void AddSC_boss_oryphrion()
{
    
}