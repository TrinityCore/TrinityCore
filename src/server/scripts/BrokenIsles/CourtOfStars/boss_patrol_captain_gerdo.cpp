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
#include "court_of_stars.h"
#include "ScriptedGossip.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ARCANE_LOCKDOWN = 1,
    SAY_SIGNAL = 2,
    SAY_FLASK = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_RESONANT_SLASH = 207261,
    SPELL_RESONANT_SLASH_FRONT = 206574,
    SPELL_RESONANT_SLASH_BACK = 206580,
    SPELL_ARCANE_LOCKDOWN = 207278,
    SPELL_SIGNAL_BEACON = 207806,
    SPELL_SUM_VIGILANT_NIGHTWATCH = 210435,
    SPELL_FLASK_SOLEMN_NIGHT = 207815,
    SPELL_STREETSWEEPER = 219488,

    //Guards
    SPELL_HINDER = 215204,

    //Streetsweeper
    SPELL_STREETSWEEPER_VISUAL = 219475,
    SPELL_STREETSWEEPER_VISUAL_BEAM = 219483,
    SPELL_STREETSWEEPER_AT = 219477,

    //Beacon
    SPELL_WATCHPOST_VICINITY = 212479, //?
    SPELL_WATCHPOST_VICINITY_AT = 212480, //?
    SPELL_CAST_DISABLE_BEACON = 210253,
    SPELL_BEACON_DISABLED = 210257,
};

enum eEvents
{
    EVENT_RESONANT_SLASH = 1,
    EVENT_ARCANE_LOCKDOWN = 2,
    EVENT_SIGNAL_BEACON = 3,
    EVENT_FLASK_SOLEMN_NIGHT = 4,
    EVENT_FLASK_SOLEMN_NIGHT_END = 5,
    EVENT_STREETSWEEPER = 6,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const flaskPos = { 1308.29f, 3537.42f, 20.76f };

void AddSC_boss_patrol_captain_gerdo()
{
    
}
