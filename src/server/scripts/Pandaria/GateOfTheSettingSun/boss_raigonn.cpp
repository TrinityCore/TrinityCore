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
#include "Vehicle.h"
#include "Spline.h"

enum eSpells
{
    // Raigonn
    SPELL_IMPERVIOUS_CARAPACE = 107118,

    SPELL_BATTERING_HEADBUTT_EMOTE = 118685,
    SPELL_BATTERING_HEADBUTT = 111668,
    SPELL_BATTERING_STUN = 130772,

    SPELL_BROKEN_CARAPACE = 111742,
    SPELL_BROKEN_CARAPACE_DAMAGE = 107146,
    SPELL_FIXATE = 78617,
    SPELL_STOMP = 34716,

    // Protectorat
    SPELL_HIVE_MIND = 107314,

    // Engulfer
    SPELL_ENGULFING_WINDS = 107274,

    // Swarm Bringer
    SPELL_SCREECHING_SWARM = 111600
};

enum ePhases
{
    PHASE_WEAK_SPOT = 1,
    PHASE_VULNERABILITY = 2
};

enum eActions
{
    ACTION_WEAK_SPOT_DEAD = 1
};

enum eEvents
{
    EVENT_CHECK_WIPE = 1,
    EVENT_RAIGONN_CHARGE = 2,

    EVENT_SUMMON_PROTECTORAT = 3,
    EVENT_SUMMON_ENGULFER = 4,
    EVENT_SUMMON_SWARM_BRINGER = 5,

    EVENT_FIXATE = 6,
    EVENT_FIXATE_STOP = 7,

    EVENT_STOMP = 8
};

enum eMovements
{
    POINT_MAIN_DOOR = 1,
    POINT_HERSE = 2
};

Position chargePos[4] =
{
    { 958.30f, 2386.92f, 297.43f, 0.0f },
    { 958.30f, 2458.59f, 300.29f, 0.0f },
    { 958.30f, 2241.68f, 296.10f, 0.0f },
    { 958.30f, 2330.15f, 296.18f, 0.0f }
};

void AddSC_boss_raigonn()
{
    
}
