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

#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
// 143948
// 149189
// 140708

enum ScriptedTexts
{
    SAY_CHO_INTRO_1 = 0,
    SAY_CHO_INTRO_2 = 1,
    SAY_CHO_INTRO_3 = 2,
    SAY_CHO_INTRO_4 = 3,
    SAY_CHO_INTRO_5 = 4,
    SAY_CHO_INTRO_6 = 5,
};

enum Spells
{
    SPELL_COSMETIC_CHANNEL_1 = 147449, // on target, blue beam
    SPELL_COSMETIC_CHANNEL_2 = 147392, // on caster, big blue pool

    SPELL_SPAWN = 146920,
    SPELL_OOZE_SPAWN_MISSILE = 146944,
    SPELL_OOZE_SPAWN_DUMMY = 147166,
    SPELL_OOZE_SPAWN_1 = 146949, // summons sha puddle
    SPELL_OOZE_SPAWN_2 = 147141, // summons contaminated puddle

    SPELL_LESSER_SHA_RESIDUE = 147083,
    SPELL_LESSER_PURIFIED_RESIDUE = 147155,

    SPELL_BOOBLE_SHIELD_1 = 147333,

    SPELL_BOOBLE_SHIELD_2 = 147450,
    SPELL_CORRUPTED_WATER = 147351,
    SPELL_WATER_BOLT = 147398,

    SPELL_RUSHING_WATERS = 147185,
    SPELL_RUSHING_WATERS_DMG_1 = 149164, // from creature
    SPELL_RUSHING_WATERS_DMG_2 = 147213, // periodic from areatriggers
    SPELL_SWIRL_ZONE = 147184,
    SPELL_SWIRL_ZONE_NE = 147181,
    SPELL_SWIRL_ZONE_N = 147178,
    SPELL_SWIRL_ZONE_NW = 147182,
    SPELL_SWIRL_ZONE_SW = 147191,
    SPELL_SWIRL_ZONE_SE = 147189,

    // Fragment of Pride
    SPELL_GROWING_PRIDE = 145818,

    // Amalgamated Hubris
    SPELL_SHA_NOVA = 145989,

    // Vanity
    SPELL_SELF_ABSORBED = 145861,

    // Arrogance
    SPELL_OVERCONFIDANCE = 145893,
    SPELL_OVERCONFIDANCE_2 = 145894, // removes 145940, forces 145893
    SPELL_OVERCONFIDANCE_FORCE = 145895, // triggers 146009
    SPELL_OVERCONFIDANCE_REMOVE = 145897, // from all in 50000 yards
    SPELL_GROWING_OVERCONFIDANCE = 145940,
    SPELL_IMPENDING_OVERCONFIDANCE = 146009, // triggered by 145895
    SPELL_OVERCONFIDANCE_DMG = 145891,

    // Zeal
    SPELL_ARROGANCE = 145941,
    SPELL_VANITY = 145942,
    SPELL_SHA_SPLASH = 145944,
};

enum Events
{
    EVENT_BOOBLE_SHIELD = 1,
    EVENT_CORRUPTED_WATER,
    EVENT_WATER_BOLT,
    EVENT_RUSHING_WATERS,

    EVENT_CHO_TALK_INTRO_1,
    EVENT_CHO_TALK_INTRO_2,
    EVENT_CHO_TALK_INTRO_3,
    EVENT_CHO_TALK_INTRO_4,
    EVENT_CHO_TALK_INTRO_5,
    EVENT_CHO_TALK_INTRO_6,

    // Fragment of Pride
    EVENT_GROWING_PRIDE,

    // Amalgamated Hubris
    EVENT_SHA_NOVA,

    // Vanity
    EVENT_SELF_ABSORBED,

    // Zeal
    EVENT_SHA_SPLASH,

};

enum Adds
{
    NPC_OOZE_CONTROLLER = 73222,

    NPC_LESSER_SHA_PUDDLE_1 = 73226, // summoned by spell 146949
    NPC_LESSER_SHA_PUDDLE_2 = 73197,
    NPC_LESSER_CONTAMINATED_PUDDLE_1 = 73283, // summoned by spell 147141
    NPC_LESSER_CONTAMINATED_PUDDLE_2 = 73260,

    NPC_TORMENTED_INITIATE = 73349,
    NPC_FALLEN_POOL_TENDER = 73342,
    NPC_AQUEUOS_DEFENDER = 73191,

    NPC_FRAGMENT_OF_PRIDE = 72655,
    NPC_AMALGAMATED_HUBRIS = 72658,
    NPC_SHA_INFUSED_DEFENDER = 72788,
};

enum Actions
{
    ACTION_CHO_TALK_INTRO = 1,
    ACTION_CHO_TALK_INTRO_IMMERSEUS,
    ACTION_CHO_TALK_OUTRO_IMMERSEUS,
};

enum eData
{
    DATA_VANITY_ALIVE = 1,
    DATA_ARROGANCE_ALIVE,
};

void AddSC_siege_of_orgrimmar_part_a()
{
    
}
