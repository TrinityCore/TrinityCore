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

#include "violet_hold_assault.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "LFGMgr.h"
#include "Group.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_START = 0,
    SAY_AGGRO = 1,
    SAY_EVADE = 2,
    SAY_EXECUTION = 3,
    SAY_EXECUTION_EMOTE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_ARMED = 179670,
    SPELL_CHAOTIC_ENGERY = 203622,
    SPELL_FEL_SLASH = 203637,
    SPELL_MIGHTY_SMASH = 202328,
    SPELL_MIGHTY_SMASH_JUMP_1 = 202339, //Прыгает босс
    SPELL_MIGHTY_SMASH_JUMP_2 = 202340, //Прыгают все игроки, кроме одного.
    SPELL_MIGHTY_SMASH_JUMP_3 = 202343, //Прыгает один игрок
    SPELL_EXECUTION = 202361,
    SPELL_EXECUTION_ROOT_PLR = 205233,
    SPELL_STASIS_CRYSTAL_SUM = 205230,
    SPELL_STASIS_CRYSTAL_VIS = 205225,

    //Heroic+
    SPELL_SEED_OF_DESTRUCTION = 210879,
    SPELL_WAKE_OF_DESTRUCTION_AT = 210913, //210916 dmg
};

enum eEvents
{
    EVENT_PRE_FIGHT = 1,
    EVENT_CHAOTIC_ENGERY = 2,
    EVENT_FEL_SLASH = 3,
    EVENT_MIGHTY_SMASH = 4,
    EVENT_EXECUTION = 5,
    EVENT_SEED_OF_DESTRUCTION = 6,

    ACTION_CRYSTAL_DESTROYED
};

Position const jumpPos[4] =
{
    {4679.24f, 4014.53f, 91.75f},
    {4634.82f, 3965.24f, 86.98f},
    {4596.65f, 4015.52f, 83.31f},
    {4623.35f, 4058.62f, 82.64f},
};

void AddSC_boss_fel_lord_betrug()
{
    
}
