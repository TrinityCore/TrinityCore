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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "heart_of_fear.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Spell.h"

enum eZorlokSpells
{
    SPELL_MANTID_WINGS = 126316,
    SPELL_ATTENUATION = 122440,
    SPELL_CONVERT = 122740,
    SPELL_INHALE = 122852,
    SPELL_EXHALE = 122761,
    SPELL_EXHALE_DMG = 122760,
    SPELL_PHEROMONES_OF_ZEAL = 123812,   // Aura inflicting damages to players
    SPELL_PHEROMONES_CLOUD = 123811,   // Creating Cloud of pheromones
    SPELL_FORCE_AND_VERVE = 122713,
    SPELL_NOISE_CANCELLING = 122706,
    SPELL_MISSILE_NOISE_CANC = 122707,
    SPELL_SONG_OF_THE_EMPRESS = 123791,
    SPELL_SONIC_RING_VISUAL = 122334,
    SPELL_SONIC_RING_AURA = 122336,
    SPELL_SONIC_PULSE_VISUAL = 124668,
    SPELL_SONIC_PULSE_AURA = 124673,
    SPELL_INHALE_PHEROMONES = 124018,
    SPELL_REINFORCE = 123833,
    SPELL_ZORLOK_BERSERK = 120207,
    SPELL_MAGNETIC_PULSE = 147379,    // Pull the players on the boss
    SPELL_ECHO_OF_ZORLOK = 127496,

    SPELL_VIZIER_ZORLOK_BONUS = 132194
};

enum eZorlokEvent
{
    EVENT_INHALE = 1,
    EVENT_EXHALE = 2,
    EVENT_BERSERK = 3,
    EVENT_ATTENUATION = 4,
    EVENT_SUMMON_RINGS = 5,
    EVENT_SUMMON_RINGS1 = 6,
    EVENT_SUMMON_RINGS2 = 7,
    EVENT_PHEROMONES_CLOUD = 8,
    EVENT_FORCE_AND_VERVE = 9,
    EVENT_CAST_FANDV = 10,
    EVENT_CONVERT = 11,
    EVENT_PULL_RAID = 12,
    EVENT_SONIC_PULSE = 13,
    EVENT_SUMMON_LAST_ECHO = 14,
    EVENT_SONIC_MOVE = 15
};

enum eZorlokActions
{
    ACTION_SONIC_RING = 2,
    ACTION_INHALE_PHEROMONES = 3,
    ACTION_WIPE = 4,
    ACTION_SONIC_PULSE = 5
};

enum eZorlokTypes
{
    TYPE_EXHALE_TARGET = 1,
    TYPE_PHASE_ZORLOK = 2
};

enum eZorlokAdds
{
    NPC_SONIC_RING = 62689,
    NPC_SONIC_PULSE = 63837,
    NPC_ECHO_OF_ATTENUATION = 65173,
    NPC_ECHO_OF_FORCE_AND_VERVE = 65174
};

enum eZorlokPhase
{
    PHASE_ZORLOK1 = 1,
    PHASE_ZORLOK2 = 4 // value '4' needed, DON'T CHANGE IT !!!
};

enum ePlatforms
{
    PLATFORM_ZORLOK_SW = 1,    // Platform South-west (Force and verve)
    PLATFORM_ZORLOK_NE = 2,    // Platform North-east (Attenuation)
    PLATFORM_ZORLOK_SE = 3    // Platform South-east (Convert)
};

enum eTalk
{
    TALK_AGGRO = 1,
    TALK_DEATH = 2,
    TALK_EVENT_IDLE_1A = 3,    // 1st phase of trash mobs
    TALK_EVENT_IDLE_1B = 4,
    TALK_EVENT_IDLE_1C = 5,
    TALK_EVENT_IDLE_2 = 6,    // 2nd phase of trash mobs
    TALK_EVENT_IDLE_3 = 7,    // 3rd phase of trash mobs
    TALK_EVENT_IDLE_4 = 8,    // 4th phase of trash mobs
    TALK_EVENT_PHASE_1 = 9,
    TALK_EVENT_PHASE_2 = 10,
    TALK_EVENT_PHASE_3 = 11,
    TALK_EVENT_TRASH_A_COMBAT = 12,
    TALK_EVENT_TRASH_A_DIES = 13,
    TALK_EVENT_TRASH_B_COMBAT = 14,
    TALK_EVENT_TRASH_B_DIES = 15,
    TALK_EVENT_TRASH_C_COMBAT = 16,
    TALK_EVENT_TRASH_C_DIES = 17,
    TALK_SLAY_01 = 18,   // Killing a player
    TALK_SLAY_02 = 19,
    TALK_EXHALE = 20,
    TALK_INHALE = 21,
    TALK_CONVERT = 22,
    TALK_PITCH = 23    // Echoes of power
};

Position zorlokPlatforms[3] =
{
    {-2317.21f,     300.67f,    409.90f,    0.0f},  // SW Platform
    {-2234.36f,     216.88f,    409.90f,    0.0f},  // NE Platform
    {-2315.77f,     218.20f,    409.90f,    0.0f}   // SE Platform
};

Position zorlokReachPoints[3] =
{
    {-2317.21f,     300.67f,    420.0f,     0.0f},  // NE Platform
    {-2234.36f,     216.88f,    420.0f,     0.0f},  // SW Platform
    {-2315.77f,     218.20f,    420.0f,     0.0f}   // SE Platform
};

Position oratiumCenter[2] =
{
    {-2274.80f,     259.19f,    420.0f,    0.318021f},
    {-2274.80f,     259.19f,    406.5f,    0.318021f}
};

// 212943 - Final Phase Door
Position finalPhaseWalls1[3] =
{
    {-2299.195f, 282.5938f, 408.5445f, 2.383867f},
    {-2250.401f, 234.0122f, 408.5445f, 2.333440f},
    {-2299.63f,  233.3889f, 408.5445f, 0.7598741f}
};

// 212916 - Arena Walls
Position finalPhaseWalls2[3] =
{
    {-2255.168f, 308.7326f, 406.0f,   0.7853968f},
    {-2240.0f,   294.0f,    406.0f,   0.7853968f},
    {-2225.753f, 280.1424f, 406.381f, 0.7853968f}
};

float tabCenter[3] = { -2274.8f, 259.187f, 406.5f };

float rangeAttenuation1[2][2] =
{
    {-2256.0f, -2208.0f},
    {190.0f,   240.0f}
};

float rangeAttenuation2[2][2] =
{
    // Coords to redone
    {-2297.0f, -2250.0f},
      {237.0f,   280.0f}
};

void AddSC_boss_zorlok()
{
    
}
