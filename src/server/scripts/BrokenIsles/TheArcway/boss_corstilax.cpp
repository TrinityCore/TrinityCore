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
#include "ScriptedCreature.h"
#include "the_arcway.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_SUPPRESSION_PROTOCOL  = 196047,
    SPELL_S_PROTOCOL_FIXATE     = 196068,
    SPELL_S_PROTOCOL_DMG        = 196070,
    SPELL_QUARANTINE            = 195791,
    SPELL_QUARANTINE_STUN       = 195804,
    SPELL_CLEANSING_FORCE       = 196115,
    SPELL_CLEANSING_FORCE_AT    = 196088,
    SPELL_DESTABILIZED_ORB      = 220481,
    SPELL_DESTABILIZED_ORB_AT   = 220482,

    SPELL_ENERGY_BURST_VISUAL   = 195516,
    SPELL_ENERGY_BURST_AT       = 195523,
    SPELL_NIGHTWELL_ENERGY      = 195362,
};

enum eEvents
{
    EVENT_PROTOCOL              = 1,
    EVENT_QUARANTINE            = 2,
    EVENT_CLEANSING_FORCE       = 3,
    EVENT_ENERGY_BURST          = 4,
    EVENT_DESTABILIZED_ORB      = 5,
    EVENT_1,
};

Position const centrPos = {3147.14f, 4887.08f, 617.62f};

void AddSC_boss_corstilax()
{
   
}