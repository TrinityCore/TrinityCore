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
#include "SpellAuras.h"
#include "the_underrot.h"

enum Spells
{
    SPELL_CRAWG_EATING                  = 279156,

    SPELL_INFESTED                      = 260477,
    SPELL_CHARGE                        = 260292, // spawn 12 random pos lava, change spellinfo effect target
    SPELL_CHARGE_DAMAGE                 = 260312,
    SPELL_INDIGESTION                   = 260793,

    SPELL_TANTRUM_ENERGY_VISUAL         = 271771,
    SPELL_TANTRUM_ENERGY_PERIODIC       = 271775,
    SPELL_TANTRUM                       = 260333,

    SPELL_BLOOD_TICK_SPELL_DEST = 260391,
    SPELL_LARVA_SUMMON_VISUAL           = 260411, // visual on npc larves
    SPELL_LARVA_SUMMON_BLOOD_TICK       = 260353,
    SPELL_LARVA_METAMORPHOSIS           = 260416,
    SPELL_LARVA_METAMORPHOSIS_2         = 260766,
    SPELL_LARVA_DESTROY                 = 260418, // visual on blood is created

    SPELL_BLOOD_TICK_SPAWN              = 260768, // on blood ticks at spawn, size increase
    SPELL_BLOOD_TICK_SERRATED_FANGS     = 260455,
    SPELL_BLOOD_TICK_BLOOD_BURST        = 278641,
    SPELL_BLOOD_TICK_BLOOD_BURST_DAMAGE = 278637,
};

enum Events
{
    EVENT_ENERGY_REGEN = 1,
    EVENT_CHARGE_TARGET,
    EVENT_INDIGESTION,
    EVENT_TANTRUM,

    EVENT_METAMORPHOSIS,
    EVENT_SERRATED_FANGS,
};

enum Timers
{
    TIMER_ENERGY_REGEN = 2 * IN_MILLISECONDS,
    TIMER_CHARGE = 20 * IN_MILLISECONDS,
    TIMER_INDIGESTION = 8 * IN_MILLISECONDS,
    TIMER_SERRATED_FANGS = 3 * IN_MILLISECONDS,
    TIMER_SERRATED_FANGS_AFTER = 10 * IN_MILLISECONDS,
    TIMER_METAMORPHOSIS = 10 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_CRAGMAW_THE_INFESTED = 131817,

    NPC_BLOOD_TICK = 132051,
    NPC_LARVES = 132080,
};

enum Points
{
    POINT_ONE = 1,
    POINT_TWO = 2,
    POINT_THREE = 3,
};

const Position centerZone = { 856.38f, 981.99f, 39.14f  };

void AddSC_boss_cragmaw_infested()
{
    
}
