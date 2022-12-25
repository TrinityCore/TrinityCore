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
    SPELL_INFUSED = 332535,
    SPELL_DANSE_MACABRE_MOD_DAMAGE_TAKEN = 330959,
    SPELL_DANSE_MACABRE_DUMMY = 328497,
    SPELL_DANSE_MACABRE_CREATE_AT = 328485,//20402
    SPELL_DANSE_MACABRE_AURA = 328495,
    SPELL_DANSE_MACABRE_CREATE_AT_TWO = 344181,//21954
    SPELL_OPRESSIVE_ATMOSPHERE = 334909,
    EVENT_DANSE_MACABRE = 2,

    //Baroness Frieda
    SPELL_DREADBOLT_VOLLEY = 337110,
    SPELL_DRAIN_ESSENCE_CHANNEL = 346654,
    SPELL_DRAIN_ESSENCE_PERIODIC_DAMAGE = 346651,
    SPELL_DRAIN_ESSENCE_MOD_HEALTH = 327773,

    //Prideful Eruption
    SPELL_PRIDEFUL_ERUPTION_CAST = 346657,
    SPELL_PRIDEFUL_ERUPTION_MISSILE = 346661,
    SPELL_PRIDEFUL_ERUPTION_DAMAGE = 346660,
    //Soul Spikes
    SPELL_SOUL_SPIKES_DEBUFF = 346681,
    SPELL_SOUL_SPIKES_PERIODIC_DUMMY = 346762,
    SPELL_SOUL_SPIKES_DAMAGE = 346685,

    //Castellan Niklaus
    SPELL_DUELIST_RISPOSE = 346690,
    SPELL_UNDYING_SHIELD = 346694,

    SPELL_DREDGER_SERVANT = 330978,
    SPELL_THROW_FOOD = 330968,
    SPELL_CASTELLANS_CADRE = 330965,
    SPELL_BERSERK = 26662,

    //Lord Stavros
    SPELL_EVASIVE_LUNGE_DAMAGE = 327610,
    SPELL_EVASIVE_LUNGE_TELEPORT = 327497,
    SPELL_DARK_RECITAL = 331634,
    SPELL_DARK_RECITAL_TRIGGER = 334741,
    SPELL_WALTZ_OF_BLOOD_STUN = 327619,
    SPELL_DANCING_FOOLS = 330964,
    SPELL_VIOLENT_UPROAR = 346303,

    //Heroic
    SPELL_MANIFEST_PAIN_CREATE_AT = 346944, //22212
    SPELL_MANIFEST_PAIN_AT_DAMAGE = 346945,
    SPELL_TWISTED_PAIN = 346939,
    SPELL_TWISTED_PAIN_CREATE_AT_APPLY_AIRA = 346937, //22211
    SPELL_CASTELLANS_FURY = 346934,
    SPELL_TWO_LEFT_FEET = 346932,
    //Mythic
    EVENT_DANCING_FEVER = 1,
    SPELL_DANCING_FEVER_AURA = 347350,

    //Frieda
    ACTION_PRIDEFUL_ERUPTION = 1,
    ACTION_SOUL_SPIKES,
    //Niklaus
    ACTION_DREDGER_SERVANT, // begrudging waiter 
    ACTION_CASTELLANS_CADRE,
    //Lord
    ACTION_WALTZ_OF_BLOOD,
    ACTION_DANCING_FOOLS
};

void AddSC_boss_council_of_blood()
{
   
}