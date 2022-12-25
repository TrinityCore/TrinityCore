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

enum Says
{
    SAY_AGGRO = 1,
    SAY_MAGIC = 2,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_SPAWN_VISUAL = 202679, //Hit npc 98734
    SPELL_ARCANE_BLAST = 196357,
    SPELL_VOLATILE_MAGIC = 196562,
    SPELL_OVERCHARGE_MANA = 196392,
    SPELL_OVERCHARGE = 196396,
    SPELL_NETHER_LINK = 196804,
    SPELL_WITHERING_CONSUMPTION = 196549,
    SPELL_CONSUME_ESSENCE = 196877,
    SPELL_CHARGED_BOLT = 220581,
    SPELL_CHARGED_BOLT_AT = 220569,
};

enum eEvents
{
    EVENT_VOLATILE_MAGIC = 1,
    EVENT_OVERCHARGE_MANA = 2,
    EVENT_NETHER_LINK = 3,
    EVENT_WITHERING_CONSUMPTION = 4,
    EVENT_CONSUME_ESSENCE = 5,

    DATA_OVERCHARGE,
};

enum Achieve
{
    ACHIEVEMENTDATA,
};

void AddSC_boss_ivanyr()
{
    
}
