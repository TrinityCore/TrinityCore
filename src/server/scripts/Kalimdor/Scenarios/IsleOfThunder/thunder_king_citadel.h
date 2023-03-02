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

#ifndef THUNDER_KING_CITADEL_SCENARIO_H_
#define THUNDER_KING_CITADEL_SCENARIO_H_

#define CHAPTERS 2

const Position treasureRoomPos = { -452.01f, 1060.88f, 133.66f, 1.58f };

enum eCreatures
{
    NPC_LIGHTNING_PILLAR_MASTER_BUNNY = 70409,
    NPC_LIGHTNING_PILLAR_TARGET_BUNNY = 70410,
    NPC_STONE_SENTINEL                = 70324,
    NPC_SPEED_RUNE                    = 70405,
    NPC_SENTRY_TOTEM                  = 70413,
    NPC_STASIS_RUNE                   = 70406,
    NPC_SENTRY_BEAM_BUNNY             = 70412,
    NPC_ZANDALARI_ARCWEAVER           = 70401,
    NPC_STONE_WATCHER                 = 70327,
    NPC_STONE_SENTRY                  = 70326,
    NPC_ZANDALARI_VENOMBLADE          = 70328,
    NPC_GOD_HULK_GULKAN               = 70400,
    NPC_TAOSHI                        = 70320,
    NPC_CLOUD_TILE_TRAP_BUNNY         = 70331,
    NPC_TENWU_OF_THE_RED_SMOKE        = 70321,
};

enum eGameObjects
{
    GO_MOGU_TREASURE_CHEST        = 218757,
    GO_MOGU_GOLDEN_TREASURE_CHEST = 218772,
    GO_ANCIENT_GATE               = 218936,
    GO_ANCIENT_GATE_2             = 218935,
    GO_ANCIENT_GATE_3             = 218938,
    GO_ANCIENT_GATE_4             = 218937,
    GO_ANCIENT_GATE_5             = 218940,
    GO_ANCIENT_GATE_6             = 218934,
    GO_LEVER_1                    = 218885,
    GO_LEVER_2                    = 218886,
    GO_LEI_SHEN_BURIAL_THROVE     = 218949,
};

enum eData
{
    DATA_SPEAK_WITH_TAOSHI,  // First chapter, done when u`ll open the door
    DATA_REACH_THE_EXIT = 1, // Second chapter, done when u`ll die or time is end or u got golden chest
    DATA_OPEN_FIRST_DOOR_PACK,
    DATA_OPEN_SECOND_DOOR_PACK,
    PLAYER_DATA,
    CHEST_DATA,
    TIME_DATA,
    GOLDEN_CHEST_DATA,
};

enum MiscSpells
{
    SPELL_TENWU_EXIT_TRIGGERED_CREDIT = 139303,
    SPELL_LOOTED_GOLDEN_CHEST_ACHIEV  = 139578,
};

enum eTalks
{
    TALK_INTRO,
    TALK_PROTECTED,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
};

#endif // THUNDER_KING_CITADEL_H_