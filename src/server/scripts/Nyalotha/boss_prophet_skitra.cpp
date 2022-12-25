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
#include "nyalotha.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

const Position middle_pos = { -1487.0f, -580.0f, -518.4f, 4.71f };

enum Texts
{
    SAY_MINDQUAKE,
    SAY_AGGRO = 2,
    SAY_SHRED_PSYCHE,
    SAY_ILLUSIONARY_PROJECTIONS,
};

enum Spells
{
    SPELL_SHADOW_SHOCK = 307977,
    SPELL_SHADOW_SHOCK_DEBUFF = 308059,
    SPELL_SHRED_PSYCHE_DUMMY = 307937,
    SPELL_SHRED_PSYCHE_AURA = 308065,
    SPELL_SHRED_PSYCHE_SUMMON = 309680,
    SPELL_ILLUSIONARY_PROJECTION_DUMMY = 307445,
    SPELL_ILLUSIONARY_PROJECTION_DISAPPEAR = 307725,
    SPELL_PROPHET_ILLUSION = 307713,
    SPELL_CLOUDED_MIND = 307784,
    SPELL_TWISTED_MIND = 307785,
    SPELL_DARK_RITUAL = 309657,
    SPELL_MINDQUAKE = 307864,
    SPELL_RAGE_OF_THE_CORRUPTOR = 317669,
    
    NPC_SHREDDED_PSYCHE = 158781,
    SPELL_PSYCHIC_OUTBURST = 309687,
    SPELL_PSYCHIC_REVERBERATIONS = 312721,
        
    SPELL_INTANGIBLE_ILLUSION = 313208,
    SPELL_SURGING_IMAGES_CREATE_AT = 313210,
    SPELL_SURGING_IMAGES_AT_DAMAGE = 313215,
};

enum Events
{
    EVENT_SHADOW_SHOCK = 1,
    EVENT_SHRED_PSYCHE,
    EVENT_PSYCHIC_OUTBURST,
    EVENT_PSYCHIC_REVERBERATIONS,
    EVENT_MIND,
    EVENT_PROJECTIONS,
    EVENT_ABSOLUTIONS,
    EVENT_BERSERK,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO,
};

void AddSC_prophet_skitra()
{
   
};
