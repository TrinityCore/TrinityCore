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

#include "GameTables.h"
#include "halls_of_valor.h"
#include "ScenarioMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_EXPEL_LIGHT = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_ASCENDANCE = 191475,
    SPELL_ASCENDANCE_JUMP = 191478,
    SPELL_EMPOWERMENT_TRACKER = 192130,
    SPELL_EXPEL_LIGHT = 192044,
    SPELL_EXPEL_LIGHT_DMG = 192067,
    SPELL_EXPEL_LIGHT_CONFUSE = 192070,
    SPELL_EXPEL_LIGHT_DUMMY = 192095,
    SPELL_SHIELD_OF_LIGHT = 192018,
    SPELL_MYSTIC_MOD_DMG_THUNDER = 192132,
    SPELL_MYSTIC_MOD_DMG_HOLY = 192133,

    //Special Ability
    SPELL_EYE_OF_THE_STORM = 192304,
    SPELL_EYE_OF_THE_STORM_DMG = 200901,
    SPELL_EYE_OF_THE_STORM_AT = 203955,
    SPELL_ARCING_BOLT_FILTER = 191978,
    SPELL_SANCTIFY_TICK = 192158,
    SPELL_SANCTIFY_AT = 192163,

    //Defender
    SPELL_OLMYR_VISUAL = 191899,
    SPELL_SOLSTEN_VISUAL = 192147,
    SPELL_OLMYR_LIGHT = 192288,

    SPELL_CONVERSATION = 198226,
};

enum eEvents
{
    EVENT_EXPEL_LIGHT = 1,
    EVENT_SHIELD_OF_LIGHT = 2,
    EVENT_SPECIAL_ABILITY = 3,
    EVENT_ARCING_BOLT = 4,

    EVENT_2,
    EVENT_1,
};

void AddSC_boss_hyrja()
{
    
}
