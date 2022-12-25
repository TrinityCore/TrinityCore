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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"

enum eSpells
{
    SPELL_CRUSH = 137504,
    SPELL_ALPHA_MALE = 138391, // Boss Passive Aura. Triggers 138390 Tank Threat Multiplier.
    SPELL_FRILL_BLAST = 137505,
    SPELL_GROWING_FURY = 137502,
    SPELL_PIERCING_ROAR = 137457,
    SPELL_SPIRITFIRE_BEAM = 137511  // Or 137508??
};

enum eEvents
{
    EVENT_CRUSH = 1,            // 60s from start. Every 25 - 30s.
    EVENT_FRILL_BLAST,          // 40s from start. Every 25 - 30s.
    EVENT_GROWING_FURY,         // Every 30s.
    EVENT_PIERCING_ROAR,        // 20s from start. Every 25 - 30s.
    EVENT_SPIRITFIRE_BEAM       // 15s from start. Every 25 - 30s.
};

void AddSC_boss_oondasta()
{
    
}
