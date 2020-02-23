/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

#include "CreatureAIImpl.h"

#define STScriptName "instance_sunken_temple"
#define DataHeader "ST"

enum STEvents
{
    EVENT_STATE = 1,
    // EJ script
    DOWSE_ETERNAL_FLAME = 2,
    HAKKAR_SUMMONED = 3,
};

// EJ scripts
enum SUNKEN_TEMPLE_NPC
{
    NPC_ZOLO = 5712,
    NPC_GASHER = 5713,
    NPC_LORO = 5714,
    NPC_HUKKU = 5715,
    NPC_ZULLOR = 5716,
    NPC_MIJAN = 5717,

    NPC_JAMMALAN = 5710,

    NPC_MORPHAZ = 5719,
    NPC_HAZZAS = 5722,
    NPC_NIGHTMARE_SCALEBANE = 5277,
    NPC_NIGHTMARE_WYRMKIN = 5280,
    NPC_NIGHTMARE_WANDERER = 5283,
    NPC_NIGHTMARE_WHELP = 8319,
    NPC_SHADE_OF_ERANIKUS = 5709,

    NPC_DREAM_SCYTHE = 5721,
    NPC_WEAVER = 5720,
    
    NPC_BLOODKEEPER = 8438,                           // Spawned rarely and contains the hakkari blood -> used to extinguish the flames
    NPC_HAKKARI_MINION = 8437,                           // Npc randomly spawned during the event = trash
    NPC_NIGHTMARE_SUPPRESSOR = 8497,                           // Npc summoned at one of the two doors and moves to the boss;

    NPC_AVATAR_OF_HAKKAR = 8443,
};

enum SUNKEN_TEMPLE_GO
{
    GO_ETERNAL_FLAME_1 = 148418,
    GO_ETERNAL_FLAME_2 = 148419,
    GO_ETERNAL_FLAME_3 = 148420,
    GO_ETERNAL_FLAME_4 = 148421,
    GO_EVIL_CIRCLE = 148998,                         // Objects used at the avatar event. they are spawned when the event starts, and the mobs are summon atop of them
    GO_HAKKAR_DOOR_1 = 149432,                         // Combat doors
    GO_HAKKAR_DOOR_2 = 149433,

    GO_JAMMALAN_BARRIER = 149431,
};

enum SUNKEN_TEMPLE_DATA_BOSS
{
    BOSS_ZOLO = 0,
    BOSS_GASHER = 1,
    BOSS_LORO = 2,
    BOSS_HUKKU = 3,
    BOSS_ZULLOR = 4,
    BOSS_MIJAN = 5,

    BOSS_JAMMALAN = 6,
    BOSS_SHADE_OF_ERANIKUS = 7,
    BOSS_DREAM_SCYTHE = 8,
    BOSS_WEAVER = 9,

    BOSS_AVATAR_OF_HAKKAR = 10,

    BOSS_COUNT = 11
};

enum SUNKEN_TEMPLE_DATA_SPELL
{
    SPELL_DOWSE_ETERNAL_FLAME = 12253,
    SPELL_SUMMON_AVATAR = 12639,                          // Cast by the shade of hakkar, updates entry to avatar
    SPELL_AVATAR_SUMMONED = 12948,
    SPELL_SUPPRESSION = 12623,
};

enum SUNKEN_TEMPLE_LINES_JAMMALAN
{
    JAMMALAN_LINE_0 = 0,
};

enum SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR
{
    HAKKAR_AVATAR_LINE_0 = 0,
    HAKKAR_AVATAR_LINE_1 = 1,
    HAKKAR_AVATAR_LINE_2 = 2,
    HAKKAR_AVATAR_LINE_3 = 3,
    HAKKAR_AVATAR_LINE_4 = 4,
};

struct SummonLocations
{
    float m_fX, m_fY, m_fZ, m_fO;
};

static const SummonLocations aHakkariDoorLocations[2] =
{
    { -420.629f, 276.682f, -90.827f, 0.0f},
    { -512.015f, 276.134f, -90.827f, 0.0f}
};

template <class AI, class T>
inline AI* GetSunkenTempleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, STScriptName);
}

#endif
