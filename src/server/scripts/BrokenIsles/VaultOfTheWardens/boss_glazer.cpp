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
#include "vault_of_the_wardens.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_LINGERING = 1,
    SAY_ENERGIZE = 2,
    SAY_STOP_ENERGIZE = 3,
    SAY_PULSE = 5,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_PULSE = 194849,
    SPELL_PULSE_AT = 194853,
    SPELL_LINGERING_GAZE = 194942,
    SPELL_TELEPORT_CENTR = 194149,
    SPELL_ENERGIZE = 193443,
    SPELL_FOCUSED = 194289,
    SPELL_FOCUSED_AURA = 194323,
    SPELL_BEAM_CHECK_BW = 194463,
    SPELL_BEAM_VIS_1 = 194261,
    SPELL_BEAM_VIS_2 = 201042,

    //Lens
    SPELL_ACTIVATE_GO = 197151,
    SPELL_DEACTIVATE_GO = 198165,
    SPELL_LENS_SPAWN_VIS = 203926, //Visual spawn
    SPELL_BEAM_VIS_3 = 193373,
    SPELL_BEAM_VIS_4 = 194333, //Target boss
    SPELL_BEAM_CHECK_PLR_1 = 194523,
    SPELL_BEAM_CHECK_PLR_2 = 194468,
    SPELL_BEAM_DMG = 202046,
};

enum eEvents
{
    EVENT_PULSE = 1,
    EVENT_LINGERING_GAZE = 2,
    EVENT_TELEPORT = 3,
    EVENT_ENERGIZE = 4,
    EVENT_FOCUSED = 5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const beamPos[4] =
{
    //Version 1
    {4486.56f, -708.61f, 117.23f},
    {4507.93f, -669.62f, 117.54f},

    //Version 2
    {4451.38f, -628.36f, 117.81f},
    {4421.46f, -643.74f, 117.46f}
};

Position const lensPos[8] =
{
    //Version 1
    {4451.21f, -638.68f, 117.23f, 0.78f},
    {4433.92f, -655.97f, 117.23f, 2.35f},
    {4485.78f, -673.26f, 117.23f, 5.49f},

    //Version 2
    {4451.21f, -707.84f, 117.23f, 5.49f},
    {4468.50f, -690.55f, 117.23f, 0.78f},
    {4433.92f, -655.97f, 117.23f, 3.14f},
    {4442.56f, -699.19f, 117.23f, 1.26f},
    {4468.50f, -655.97f, 117.23f, 0.0f},
};

void AddSC_boss_glazer()
{
    
}
