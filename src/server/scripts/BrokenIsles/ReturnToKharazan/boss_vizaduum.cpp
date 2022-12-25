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

#include "new_karazhan.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_AGGRO_2 = 1,
    SAY_COMMAND_FEL_BEAM = 2,
    SAY_COMMAND_FEL_BEAM_WARN = 3,
    SAY_DEMONIC_PORTAL = 4,
    SAY_DEMONIC_PORTAL_WARN = 5,
    SAY_MOVING_TO_SHIP = 6,
    SAY_MOVING_TO_SHIP_2 = 7,
    SAY_STABILIZE_RIFT = 8,
    SAY_DEATH = 9,
};

enum Spells
{
    SPELL_BURNING_BLAST = 229083,
    SPELL_COMMAND_FEL_BEAM = 229242,
    SPELL_FEL_BEAM_AT = 229244,
    SPELL_FEL_FLAMES_AT = 229249,
    SPELL_COMMAND_BOMBARDMENT = 229284,
    SPELL_DISINTEGRATE_FILTER = 229153,
    SPELL_DISINTEGRATE = 229151,
    SPELL_CHAOTIC_SHADOWS = 229159,

    SPELL_SOUL_HARVEST = 229906,
    SPELL_STABILIZE_RIFT = 230084,

    SPELL_LEGION_SPAWN = 230280,

    //Change phase
    SPELL_DEMONIC_PORTAL_SUM = 229607,
    SPELL_DEMONIC_PORTAL_AT = 229610,
    SPELL_DEMONIC_PORTAL_SCALE = 229598,

    //Summons
    SPELL_BOMBARDMENT_AURA_1 = 229287,
    SPELL_BOMBARDMENT_AURA_2 = 229288,

    //Khadgar & Medivh
    SPELL_ENERGY_PORTAL_SPAWN = 229651,
    SPELL_RAVEN_FORM = 229645,
};

enum eEvents
{
    EVENT_BURNING_BLAST = 1,
    EVENT_COMMAND_FEL_BEAM = 2,
    EVENT_DISINTEGRATE = 3,
    EVENT_CHAOTIC_SHADOWS = 4,
    EVENT_COMMAND_BOMBARDMENT = 5,
    EVENT_DEMONIC_PORTAL_1 = 6,
    EVENT_DEMONIC_PORTAL_2 = 7,
    EVENT_DEMONIC_PORTAL_3 = 8,
    EVENT_CHECK_PLAYER = 9,
    EVENT_STABILIZE_RIFT = 10,
    EVENT_SUMMON_GUARD = 11,

    EVENT_1,
    EVENT_2,
};

enum ePhase
{
    PHASE_1 = 1,
    PHASE_2 = 2,
    PHASE_3 = 3,
    PHASE_CHANGE,
};

void AddSC_boss_vizaduum()
{
   
}
