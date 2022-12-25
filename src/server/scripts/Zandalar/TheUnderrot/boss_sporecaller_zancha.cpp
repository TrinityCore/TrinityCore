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
#include "the_underrot.h"

enum Spells
{
    SPELL_FESTERING_HARVEST = 259888,
    SPELL_FESTERING_HARVEST_DAMAGE = 259732,
    SPELL_SPORE_POD_SUMMON_SPELL_DEST = 259621,
    SPELL_BOUNDLESS_ROT_ENTER_COMBAT = 277732,
    SPELL_BOUNDLESS_ROT = 259830,
    SPELL_BOUNDLESS_ROT_AT = 259727, // on npc
    SPELL_SHOCKWAVE = 272457,
    SPELL_UPHEAVAL_TARGET = 259718, // arrow
    SPELL_UPHEAVAL = 274213,
    SPELL_UPHEAVAL_DAMAGE = 259720,
    SPELL_DECAYING_SPORE = 259714,
    SPELL_VOLATILE_POD = 273271,
    SPELL_VOLATILE_POD_EXPLOSION_VISUAL = 273285,
    SPELL_VOLATILE_POD_AT = 273300, // ball
    SPELL_SPORE_HIT_VISUAL = 259862,
    SPELL_SPORE_BEAM = 259968,
    SPELL_SPORE_DETONATION = 259668,
    SPELL_SPORE_BIG_DETONATION = 259958,
};

enum Events
{
    EVENT_SHOCKWAVE = 1,
    EVENT_SPAWN_SPORE,
    EVENT_FESTERING_HARVEST,
    EVENT_UPHEAVAL,
    EVENT_VOLATILE_PODS,
    EVENT_ENERGY_REGEN,
    EVENT_SPAWN_VOLATILE_SPORE,

    EVENT_VOLATILE_PODS_EXPLODE,
};

enum Timers
{
    TIMER_ENERGY_REGEN = 3 * IN_MILLISECONDS,
    TIMER_SPAWN_SPORE = 7 * IN_MILLISECONDS,
    TIMER_SHOCKWAVE = 15 * IN_MILLISECONDS,
    TIMER_UPHEAVAL = 19 * IN_MILLISECONDS,
    TIMER_SPAWN_VOLATILE_SPORE = 30 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_SPORECALLER_ZANCHA = 131383,

    NPC_SPORE_POD_TRIGGER = 131597,
    NPC_VOLATILE_POD_TRIGGER = 139127,
};

Position volatilePodsPositions[6] =
{
    { 1029.872f, 1034.783f, 33.64273f, 1.443645f },
    { 1013.984f, 1074.379f, 33.12016f, 5.567164f },
    { 1007.908f, 1051.262f, 32.98660f, 0.226441f },
    { 1052.523f, 1072.844f, 32.91686f, 3.785604f },
    { 1049.149f, 1043.300f, 33.95835f, 2.441262f },
    { 1035.661f, 1082.078f, 32.73851f, 4.595759f },
};

const Position centerPlatform { 1032.69f, 1058.84f, 33.33f }; // 15 yards min 20 yards max spore spawn, cheaters 30yards

void AddSC_boss_sporecaller_zancha()
{
    
}
