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

#include "cathedral_of_eternal_night.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_DEMONIC_UPHEAVAL = 233196,  // 27 + script on remove (236370)
    SPELL_DARK_SOLITUDE = 234817, // 12   
    SPELL_CARRION_SWARM = 233155, // 18 + script on line attack (233175) + at (233177)
    SPELL_SHADOW_FADE = 233206,

    // while invis Phase 2
    SPELL_CREEPING_SHADOWS = 234369,
    SPELL_SHADOW_FADE_VISUAL_DEST = 239454,
    SPELL_INVIS_HIDE = 239428,
    SPELL_CONVERSATION_INVIS = 242457,
    SPELL_INVIS_REMOVED = 234705,

    SPELL_ADD_DESPAWN = 243090,
    SPELL_SHADOW_HIT_EGIDA = 234413,
    SPELL_SHADOW_HIT_PLR = 236242,
    SPELL_SHADOW_HIT_ILLIDAN = 234018,

    // illidan (117855)
    SPELL_ILLIDAN_SPAWN = 239484,
    SPELL_PREPARE = 234875,
    SPELL_FOUND_MEPHISTROTH = 234217,
    SPELL_CONVERSATION_FOUND = 242456,
    SPELL_ILLIDAN_DESPAWN = 239485,

    SPELL_EGIDA_BUFF = 234083, //  (234114)
    SPELL_EGIDA_OVERRIDE = 234114, //  (234114)

};

enum eEvents
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_DEMONIC_UPHEAVAL,
    EVENT_DARK_SOLITUDE,
    EVENT_CARRION_SWARM,
    EVENT_PHASE_TWO_TICK,

    EVENT_1,
};

Position const adds_pos[8]
{
    {-515.09f, 2511.28f, 533.94f, 2.64f},
    {-530.12f, 2496.94f, 533.94f, 1.95f},
    {-552.74f, 2496.88f, 533.94f, 1.24f},
    {-570.11f, 2510.35f, 533.94f, 0.50f},
    {-570.77f, 2541.98f, 533.94f, 5.77f},
    {-555.74f, 2555.67f, 533.94f, 5.11f},
    {-531.29f, 2555.90f, 533.94f, 4.36f},
    {-515.62f, 2545.86f, 533.94f, 3.79f}
};

void AddSC_boss_mephistroth()
{
    
}
