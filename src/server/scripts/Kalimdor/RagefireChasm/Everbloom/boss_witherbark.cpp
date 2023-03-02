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
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "the_everbloom.h"

enum eWitherbarkTalks
{
    WitherbarkAggro   = 4, ///< So... Thirsty(45108)
    WitherbarkKill01  = 5, ///< Return to the earth...(45110)
    WitherbarkKill02  = 6, ///< Feed my roots.(45111) 
    WitherbarkSpell01 = 7, ///< Refreshed.(45112)
    WitherbarkSpell02 = 8, ///< I Cannot Be Stopped.(45113)
    WitherbarkDeath   = 9 ///< Arghh...(45109)
};

Position PositionAqueousMobs[6] =
{
    { 376.2222f, 1636.727f, 86.56787f, 0.000000f },
    { 349.9809f, 1594.229f, 86.56787f, 0.000000f },
    { 362.7083f, 1599.984f, 86.56787f, 0.000000f },
    { 366.5365f, 1614.205f, 86.56787f, 0.000000f },
    { 434.3351f, 1661.589f, 86.56787f, 0.000000f },
    { 387.4913f, 1650.116f, 86.56787f, 0.000000f },
};

enum WitherbarkEnums
{
    SPELL_PETRIFIED_BARK            = 164713,
    SPELL_CANCEL_PETRIFIED_BARK     = 164719,
    SPELL_ENERGIZE                  = 164438,
    SPELL_PARCHED_GASP              = 164357,
    SPELL_BRITTLE_BARK              = 164275,
    SPELsummon_AQUEOUS_GLOBULE      = 164437,
    SPELL_NOXIOUS_VINES             = 164712,
};

void AddSC_boss_witherbark()
{
   
}
