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
#include "violet_hold_assault.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"


#define GOSSIP_I_WANT_IN    "I'm not fighting, so send me in now!"
#define SPAWN_TIME          20000

enum Sinclari
{
    SAY_SINCLARI_1 = 0,
    SAY_SINCLARI_2 = 1,
    SAY_KEEPER = 2,
    SAY_ELITE = 3,
    SAY_GUARDIAN = 4,
};

enum VHEventsScripts
{
    EVENT_1 = 1,
    EVENT_2 = 2,
    EVENT_3 = 3,
    EVENT_4 = 4,
    EVENT_5 = 5,
    EVENT_6 = 6,
    EVENT_7 = 7,
    EVENT_8 = 8,
    EVENT_9 = 10,
    EVENT_10 = 20,
    EVENT_11 = 21,
    EVENT_12 = 22,
    EVENT_13 = 23,
    EVENT_14 = 24,
    EVENT_15 = 25,
    EVENT_16 = 26,
    EVENT_17 = 27,
    EVENT_18 = 29,
};

Position const exitPos = { 4556.62f, 4015.16f, 83.67f };
Position const plrTeleportPos = { 4577.63f, 4015.38f, 83.60f, 6.27f };
Position const movDoorPos = { 4585.82f, 4015.32f, 83.47f, 3.14f };

enum CustomActions
{
    ACTION_START_DUNGEON = 1,
};

enum CustomEvents
{
    EVENT_CALCULATE_NEXT_SPAWNING = 200,
    EVENT_CALCULATE_NEXT_BOSS,
    EVENT_CALCULATE_NEXT_FINAL_BOSS,
};

uint32 possibleBosses[6] =
{
    NPC_FESTERFACE,
    NPC_SHIVERMAW,
    NPC_PRINCESS_THALENA,
    NPC_MINDFLAYER_KAAHRJ,
    NPC_MILLIFICENT_MANASTORM,
    NPC_ANUBESSET,
};

uint32 possibleEndBosses[2] =
{
    NPC_SAELORN,
    NPC_FEL_LORD_BETRUG,
};

Position possibleSummonPosWaves[5] =
{
    { 4621.81f, 4060.18f, 91.01f },
    { 4636.62f, 3964.02f, 86.97f },
    { 4682.27f, 4013.67f, 91.87f },
    { 4653.47f, 4041.61f, 78.16f },
    { 4662.38f, 4014.96f, 82.64f },
};

uint32 possibleCombinations[4][5] =
{
    {
     NPC_PORTAL_GUARDIAN_1,
     NPC_FELGUARD_DESTROYER_1,
     NPC_INFILTRATOR_ASSASSIN,
     NPC_EREDAR_INVADER_1,
     NPC_EREDAR_SHADOW_MENDER,
    },

    {
     NPC_PORTAL_GUARDIAN_2,
     NPC_WRATHLORD_BULWARK,
     NPC_SHADOW_COUNCIL_WARLOCK,
     NPC_FELGUARD_DESTROYER_2,
     NPC_EREDAR_INVADER_1,
    },

    {
     NPC_PORTAL_KEEPER_1,
     NPC_EREDAR_INVADER_1,
     NPC_WRATHLORD_BULWARK,
     NPC_FELGUARD_DESTROYER_2,
     NPC_SHADOW_COUNCIL_WARLOCK,
    },

    {
     NPC_PORTAL_KEEPER_2,
     NPC_EREDAR_SHADOW_MENDER,
     NPC_FELSTALKER_RAVENER_2,
     NPC_FELGUARD_DESTROYER_2,
     NPC_INFILTRATOR_ASSASSIN,
    },
};

Position bossTeleportMiddle = { 4643.65f, 4017.79f, 77.96f };

void AddSC_violet_hold_assault()
{
    
}
