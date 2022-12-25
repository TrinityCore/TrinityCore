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
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "uldir.h"

enum Definitions
{
    SAY_AGGRO = 0,
    SAY_SANITIZING_STRIKE,
    SAY_PURIFYING_FLAME,
    SAY_ULDIR_DEFENSIVE_BEAM,
    SAY_CLEANSING_PURGE,
    SAY_WIND_TUNNEL,
    SAY_KILL,
    SAY_WIPE,
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    EVENT_ENERGIZE = 1,
    EVENT_CLEANSING_PURGE,
    EVENT_SANITIZING_STRIKE,
    EVENT_PURIFYING_FLAME,
    EVENT_WIND_TUNNEL,
    EVENT_ULDIR_DEFENSIVE_BEAM,
    //Rooms
    SPELL_FIRST_ROOM_OCCUPANT = 267814,
    SPELL_SECOND_ROOM_OCCUPANT = 267817,
    SPELL_THIRD_ROOM_OCCUPANT = 267819,
    //Depleted Energy
    SPELL_DEPLETED_ENERGY = 274205,
    //Cleansing Purge
    SPELL_CLEANSING_PURGE_AT = 268089,
    SPELL_CLEANSING_PURGE_AURA = 268277,
    //Purifying Flame
    SPELL_PURIFYING_FLAME_SUMMON = 267802,
    SPELL_PURIFYING_FLAME_DAMAGE = 267803,
    SPELL_PURIFYING_FLAME_AT = 267887,
    //Sanitizing Strike
    SPELL_SANITIZING_STRIKE = 267787,
    //Wind Tunnel
    SPELL_WIND_TUNNEL_AT_R_TO_L = 267885,
    SPELL_WIND_TUNNEL_AT_L_TO_R = 267878,
    //275919 Wind Tunnel
    //Defense Grid
    SPELL_DEFENSE_GRID_DAMAGE = 267821,
    //136298 npc, Defense Grid
    SPELL_DEFENSE_GRID_MISSILE_SUMMON = 267832,    
    //Uldir Defensive Beams
    SPELL_ULDIR_DEFENSE_BEAM_H_AT_M = 275228, //npc 136554, from top to ground
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_M = 277961, //wall
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_R = 281642,
    SPELL_ULDIR_DEFENSE_BEAM_V_AT_L = 281644,
    SPELL_ULDIR_DEFENSE_BEAM_AT_DAMAGE = 275432,
    NPC_SURGICAL_GRID = 136554,
    MOTHER_ENCOUNTER = 2141,
};

const Position middle_of_the_room_pos = { -135.431f, -255.882f, 733.840f, 0.0f };
const Position final_pos = { 70.888f, -255.695f, 704.580f, 0.04f };

void AddSC_boss_mother()
{
    
}
