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
#include "tol_dagor.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells {
    SPELL_SANDSTORM = 257495,

    SPELL_UPHEAVAL_TARGET_SELECTOR = 257612,
    SPELL_UPHEAVAL_CAST    = 257608,
    SPELL_UPHEAVAL_DAMAGE  = 257617,
    SPELL_UPHEAVAL_JUMP_TO_TARGET = 257615,

    //Sandtrap
    SPELL_SAND_TRAP = 257092,
    SPELL_SAND_TRAP_AREATRIGGER = 257093,
    SPELL_SAND_TRAP_DAMAGE = 257119,
};

enum Events{
    EVENT_SAND_TRAP = 1,
    EVENT_UPHEAVAL = 2,
    EVENT_SANDSTORM = 3,
    EVENT_UPHEAVAL_TARGET_SELECTION = 4,
    EVENT_UPHEAVAL_DAMAGE = 5,
};

void AddSC_boss_the_sand_queen()
{
   
}
