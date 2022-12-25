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

#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"

enum Spells
{
    SPELL_GOROTH_ENERGIZE = 237333,
    SPELL_BURNING_ARMOR = 231363,
    SPELL_BURNING_ERUPTION = 231395,
    SPELL_BURNING_ERUPTION_DUMMY = 233025,
    SPELL_CRASHING_COMET_FILTER = 232249, //Caster Boss
    SPELL_CRASHING_COMET_LFR_FILTER = 244548, //Caster Boss. Only LFR
    SPELL_CRASHING_COMET_FILTER2 = 232254, //Caster Ember Stalker - 115892
    SPELL_CRASHING_COMET_LFR_FILTER2 = 244580, //Caster Ember Stalker - 115892. Only LFR
    SPELL_CRASHING_COMET_MISSILE = 230339,
    SPELL_CRASHING_COMET_LFR_MISSILE = 244581,
    SPELL_INFERNAL_SPIKE_FILTER = 233050,
    SPELL_INFERNAL_SPIKE_SUMMON = 233055,
    SPELL_INFERNAL_SPIKE_AT = 233019,
    SPELL_INFERNAL_SPIKE_PROTECTION = 234475,
    SPELL_SHATTERING_STAR_FILTER = 233269,
    SPELL_SHATTERING_STAR_MARK = 233272,
    SPELL_SHATTERING_STAR_AURA = 233289, //unk
    SPELL_SHATTERING_STAR_SPEED = 233290,
    SPELL_SHATTERING_STAR_HIT = 233274,
    SPELL_SHATTERING_STAR_AT = 233279,
    SPELL_SHATTERING_NOVA = 233283,
    SPELL_STAR_BURN = 236329,
    SPELL_INFERNAL_BURNING = 233062,
    SPELL_INFERNAL_DETONATION = 233900, //Mythic
    SPELL_RAIN_OF_BRIMSTONE_DUMMY = 233285, //Mythic
    SPELL_RAIN_OF_BRIMSTONE_MISSILE = 238587, //Mythic
    SPELL_RAIN_OF_BRIMSTONE_SUMMON = 233266, //Mythic
    SPELL_RAIN_OF_BRIMSTONE_SPIKE_DESTROY = 238659, //Mythic

    //Lava Stalker
    SPELL_FEL_PERIODIC_TRIGGER = 234386,
    SPELL_FEL_ERUPTION_TELEGRAPH = 234366,
    SPELL_FEL_ERUPTION_DUMMY = 234368,
    SPELL_FEL_ERUPTION_MISSILE = 234387,
    SPELL_FEL_ERUPTION_AT = 234330,

    //Brimstone Infernal
    SPELL_FEL_FIRE = 241455,
};

enum eEvents
{
    EVENT_BURNING_ARMOR = 1,
    EVENT_CRASHING_COMET = 2,
    EVENT_INFERNAL_SPIKE = 3,
    EVENT_SHATTERING_STAR = 4,
    EVENT_RAIN_OF_BRIMSTONE = 5,
};

enum Misc
{
    SPELLVISUAL_INFERNAL_SPIKE_DESTROY = 66119,
    DATA_SPIKES_COUNTER,
};

Position const centrPos = { 6101.30f, -795.72f, 2971.72f };

enum Misc2
{
    ACTION_1 = 1,
    ACTION_2,
};

void AddSC_boss_goroth()
{
    
}
