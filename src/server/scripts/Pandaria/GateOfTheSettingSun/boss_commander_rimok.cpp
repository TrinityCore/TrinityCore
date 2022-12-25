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
#include "gate_setting_sun.h"

enum eSpells
{
    // Commander Rimok
    SPELL_VISCOUS_FLUID_SUMMON = 107078,
    SPELL_VISCOUS_FLUID_DMG_UP = 107091,
    SPELL_VISCOUS_FLUID_DMG_DOWN = 107122,
    SPELL_FRENZIED_ASSAULT = 107120,

    // Add Generator
    SPELL_PERIODIC_SPAWN_SWARMER = 115052,
    SPELL_PERIODIC_SPAWN_SABOTEUR = 116621,

    // Saboteur
    SPELL_BOMBARD = 120559
};

enum eEvents
{
    EVENT_FRENZIED_ASSAULT = 1,
    EVENT_VISCOUS_FLUID = 2
};

void AddSC_boss_commander_rimok()
{
    
}
