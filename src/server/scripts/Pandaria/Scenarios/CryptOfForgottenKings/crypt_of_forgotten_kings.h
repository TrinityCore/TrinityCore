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

#ifndef CRYPT_OF_FORGOTTEN_KINGS_SCENARIO_H_
#define CRYPT_OF_FORGOTTEN_KINGS_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 3

const Position JinShaExplosionPath [3] =
{
    { 743.79f, 2467.48f, 82.57f, 3.15f },
    { 718.65f, 2466.72f, 75.36f, 3.21f },
    { 701.78f, 2467.06f, 73.90f, 3.01f }
};

const Position ShaSpiritPath[3] =
{
    { 641.75f, 2354.05f, 63.37f, 6.25f },
    { 673.10f, 2354.27f, 45.03f, 6.27f },
    { 701.30f, 2354.46f, 45.11f, 3.92f },
};

enum eSpells
{
    SPELL_POOL_OF_LIFE_PROGRESS_BAR = 128864,
};

enum eCreatures
{
    NPC_NOVICE_SNOW          = 61791,
    NPC_WOUNDED_SHADO_PAN    = 66378,
    NPC_MURDERED_SHADO_PAN   = 61804,
    NPC_SPAWN_OF_ANGER       = 61709,
    NPC_SEETHING_SHA         = 61610,
    NPC_CRYPT_GUARDIAN       = 61766,
    NPC_CRYPT_GUARDIAN_2     = 61783,
    NPC_CRYPT_GUARDIAN_3     = 61418, // this npc should open the door at die
    NPC_JIN_IRONFIST         = 61814,
    NPC_FIRE_TRAP            = 71490,
    NPC_LIGHTNING_TRAP       = 65590,
    NPC_ARROW_TRAP           = 70332,
    NPC_POOL_OF_LIFE         = 61885,
    NPC_ESSENCE_OF_HATE      = 65581,
    NPC_SHA_SPIRIT           = 65607,
    NPC_QUILEN_STATUE        = 61565,
    NPC_ABOMINATION_OF_ANGER = 61707,
    NPC_SHADO_PAN_INITIATE   = 65225,
    NPC_HATEFUL_MONSTROSITY  = 65304,
    NPC_CLOUD_OF_ANGER       = 62055,
    NPC_SHADOWS_OF_ANGER     = 62009,
    NPC_BALL_LIGHTNING       = 63873,
    NPC_DARK_FIRE            = 62015,
    NPC_SPAWN_OF_ANGER_S     = 65556,
};

enum eData
{
    DATA_JIN_IRONFIST         = 0, // First chapter, done when u`ll kill 61814
    DATA_POOL_OF_LIFE         = 1, // Second chapter, done when ur progress bar`ll fully (controller: DATA_ESSENCE)
    DATA_ABOMINATION_OF_ANGER = 2, // Last chapter, done when u`ll kill 61707
    DATA_ESSENCE              = 3, // progress bar controller
};

enum eActions
{
    ACTION_CHAPTER_TWO_BEGIN = 0,
    ACTION_CHAPTER_TWO_RESET = 1,
    ACTION_GUARDIAN_INIT     = 2,
    ACTION_LIGHTNING_TRAP    = 3,
};

enum eTypes
{
    TYPE_ABOMINATION_INIT = 0,
};

enum eGameoObjects
{
    GO_GOLDEN_DOORS   = 212637,
    GO_GOLDEN_DOORS_2 = 212640, // open when pool of life data is done
    GO_GOLDEN_DOORS_3 = 212638, // open when npc 61418 has die
    GO_SHA_CORRUPTION = 214643,
};

enum worldstates
{
    WORLDSTATE_FANCY_FOORWORK = 12547,
};

enum Criteries
{
    CRITERIA_ABOMINATION_SLAIN = 19225,
};

#endif // CRYPT_OF_FORGOTTEN_KINGS_H_