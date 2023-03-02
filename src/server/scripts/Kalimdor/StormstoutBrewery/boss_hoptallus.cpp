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

#include "stormstout_brewery.h"

enum Spells
{
    SPELL_HOPPER_ANIM_REPLACEMENT = 114284,
    SPELL_HAMMER_COSMETIC_1 = 114530,
    SPELL_SUMMON_HAMMER = 114531,
    SPELL_SUMMON_HAMMER2 = 114532,
    SPELL_HAMMER_VISUAL = 114533,
    SPELL_BLINKING_COSMETIC_AURA = 114287,
    SPELL_LIT_FUSE = 114290,

    SPELL_EXPLOSIVE_BREW = 114291,

    SPELL_SMASH_AURA = 111662,
    SPELL_SMASH = 111666,

    SPELL_COSMETIC_EARTHQUAKE = 114928,
    SPELL_HOPTALLUS_INTRO_SOUND = 106790,
    SPELL_HOPTALLUS_KEG_SCENE = 114366,
    SPELL_HOPTALLUS_SCREECH = 114367,

    SPELL_FURLWIND = 112992,
    SPELL_CARROT_BREATH = 112944,
    SPELL_SUMMON_BREATH_STALKER = 112956,

    SPELL_CARROT_DOOR = 116005,

    // Achievement
    SPELL_SMASH_ACHIEVEMENT = 116286,
    SPELL_CLINGER_ACHIEVEMENT = 116271,
};

enum Misc
{
    NPC_CARROT_BREATH_STALKER = 59018
};

enum hopEvents
{
    EVENT_MOVE = 1,
    EVENT_JUMP_TO_WATER = 2,
    EVENT_CHECK_POS,
};

static const Position hoptallusHopPos = { -698.62f, 1259.4f, 162.79f, 0.24f };
static const Position hoplingSpawns[] =
{
    { -719.31f, 1248.27f, 166.8f, 0.24f },
    { -719.95f, 1250.89f, 166.8f, 0.24f },
    { -720.66f, 1253.79f, 166.8f, 0.24f },
    { -721.25f, 1256.18f, 166.8f, 0.24f },
    { -721.94f, 1259.02f, 166.8f, 0.24f }
};

static const Position hopperSpawns[] =
{
    { -726.7f, 1257.9f, 166.8f, 0.24f },
    { -720.86f, 1253.44f, 166.8f, 0.24f },
    { -726.86f, 1247.41f, 166.8f, 0.25f },
    { -719.38f, 1255.37f, 166.8f, 0.25f}
};

static const Position nibblerWaypints[] =
{
    { -704.96f, 1292.42f, 162.7f, 4.95f },
    { -698.4f, 1267.73f, 162.7f, 4.97f },
    { -690.44f, 1254.47f, 162.8f, 5.32f },
    { -683.54f, 1252.15f, 162.82f, 6.f }, // pick up here
    { -663.1f, 1256.7f, 154.8f, 5.86f },
    { -653.1f, 1242.9f, 154.8f, 4.91f },
    { -639.69f, 1192.53f, 139.15f, 0.28f }, // jump
    { -601.1f, 1201.59f, 138.5f, 4.85f },
    { -598.2f, 1188.f, 138.65f, 4.7f },
    { -598.4f, 1151.8f, 138.3f, 4.86f },
    { -592.1f, 1127.8f, 138.5f, 4.98f },
    { -566.1f, 1102.2f, 142.1f, 5.44f },
};

static const uint32 hoplings[5] = { 59461, 56631, 59459, 59458,  59460 };
static const uint32 hoppers[2] = { 56718, 59426 };

void AddSC_boss_hoptallus()
{
    
}