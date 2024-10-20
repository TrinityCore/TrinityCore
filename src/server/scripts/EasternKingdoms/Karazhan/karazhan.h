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

#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

#include "CreatureAIImpl.h"

#define KZScriptName "instance_karazhan"
#define DataHeader "KZ"

#define M_PI_M2       6.28318530718   // 2pi
uint32 const EncounterCount = 12;

enum KZEncounter
{
    DATA_ATTUMEN               = 0,
    DATA_MOROES                = 1,
    DATA_MAIDEN_OF_VIRTUE      = 2,
    DATA_OPTIONAL_BOSS         = 3,
    DATA_OPERA_PERFORMANCE     = 4,
    DATA_CURATOR               = 5,
    DATA_ARAN                  = 6,
    DATA_TERESTIAN             = 7,
    DATA_NETHERSPITE           = 8,
    DATA_CHESS                 = 9,
    DATA_MALCHEZZAR            = 10,
    DATA_NIGHTBANE             = 11,
};

enum KZData
{
    DATA_OPERA_OZ_DEATHCOUNT         = 14,

    DATA_KILREK                      = 15,
    DATA_GO_CURTAINS                 = 18,
    DATA_GO_STAGEDOORLEFT            = 19,
    DATA_GO_STAGEDOORRIGHT           = 20,
    DATA_GO_LIBRARY_DOOR             = 21,
    DATA_GO_MASSIVE_DOOR             = 22,
    DATA_GO_NETHER_DOOR              = 23,
    DATA_GO_GAME_DOOR                = 24,
    DATA_GO_GAME_EXIT_DOOR           = 25,

    DATA_IMAGE_OF_MEDIVH             = 26,
    DATA_MASTERS_TERRACE_DOOR_1      = 27,
    DATA_MASTERS_TERRACE_DOOR_2      = 28,
    DATA_GO_SIDE_ENTRANCE_DOOR       = 29,
    DATA_GO_BLACKENED_URN            = 30,

    DATA_TEAM_IN_INSTANCE            = 31,
    DATA_CHESS_TARGET                = 32,
    DATA_CHESS_MOVEMENT_SQUARE       = 33,
    DATA_CHESS_MOVE_TO_SIDES         = 34,
    DATA_CHESS_VICTORY_CONTROLLER    = 35,
    DATA_ECHO_OF_MEDIVH              = 36
};

enum KZOperaEvents
{
    EVENT_OZ                        = 1,
    EVENT_HOOD                      = 2,
    EVENT_RAJ                       = 3
};

enum KZMiscCreatures
{
    NPC_HYAKISS_THE_LURKER          = 16179,
    NPC_ROKAD_THE_RAVAGER           = 16181,
    NPC_SHADIKITH_THE_GLIDER        = 16180,
    NPC_TERESTIAN_ILLHOOF           = 15688,
    NPC_MOROES                      = 15687,
    NPC_NIGHTBANE                   = 17225,
    NPC_ATTUMEN_UNMOUNTED           = 15550,
    NPC_ATTUMEN_MOUNTED             = 16152,
    NPC_MIDNIGHT                    = 16151,

    // Trash
    NPC_COLDMIST_WIDOW              = 16171,
    NPC_COLDMIST_STALKER            = 16170,
    NPC_SHADOWBAT                   = 16173,
    NPC_VAMPIRIC_SHADOWBAT          = 16175,
    NPC_GREATER_SHADOWBAT           = 16174,
    NPC_PHASE_HOUND                 = 16178,
    NPC_DREADBEAST                  = 16177,
    NPC_SHADOWBEAST                 = 16176,
    NPC_KILREK                      = 17229
};

enum KZChessCretures
{
    NPC_ECHO_OF_MEDIVH              = 16816,
    NPC_INVISIBLE_STALKER           = 22519,  // Placeholder for dead chess npcs
    NPC_CHESS_STATUS_BAR            = 22520,  // NPC that controls the transformation of dead pieces
    NPC_CHESS_VICTORY_CONTROLLER    = 22524,
    // NPC_CHESS_SOUND_BUNNY        = 21921,  // NPC that handles the encounter sounds
    // NPC_WAITING_ROOM_STALKER     = 17459,  // Trigger which marks the teleport location of the players; also used to cast some control spells during the game
    // NPC_SQUARE_OUTSIDE_BLACK     = 17316,  // Outside chess black square
    // NPC_SQUARE_OUTSIDE_WHITE     = 17317,  // Outside chess white square

    // Chess event
    NPC_ORC_GRUNT                   = 17469,  // Pawn
    NPC_ORC_WOLF                    = 21748,  // Knight
    NPC_ORC_WARLOCK                 = 21750,  // Queen
    NPC_ORC_NECROLYTE               = 21747,  // Bishop
    NPC_SUMMONED_DAEMON             = 21726,  // Rook
    NPC_WARCHIEF_BLACKHAND          = 21752,  // King
    NPC_HUMAN_FOOTMAN               = 17211,  // Pawn
    NPC_HUMAN_CHARGER               = 21664,  // Knight
    NPC_HUMAN_CONJURER              = 21683,  // Queen
    NPC_HUMAN_CLERIC                = 21682,  // Bishop
    NPC_CONJURED_WATER_ELEMENTAL    = 21160,  // Rook
    NPC_KING_LLANE                  = 21684,  // King
    NPC_SQUARE_WHITE                = 17208,  // White square
    NPC_SQUARE_BLACK                = 17305,  // Black square

    // Generic NPCs
    NPC_FURY_MEDIVH_VISUAL          = 22521  // Has aura 39383
};

enum KZGameObjectIds
{
    GO_STAGE_CURTAIN                = 183932,
    GO_STAGE_DOOR_LEFT              = 184278,
    GO_STAGE_DOOR_RIGHT             = 184279,
    GO_PRIVATE_LIBRARY_DOOR         = 184517,
    GO_MASSIVE_DOOR                 = 185521,
    GO_GAMESMANS_HALL_DOOR          = 184276,
    GO_GAMESMANS_HALL_EXIT_DOOR     = 184277,
    GO_NETHERSPACE_DOOR             = 185134,
    GO_MASTERS_TERRACE_DOOR         = 184274,
    GO_MASTERS_TERRACE_DOOR2        = 184280,
    GO_SIDE_ENTRANCE_DOOR           = 184275,
    GO_DUST_COVERED_CHEST           = 185119,
    GO_BLACKENED_URN                = 194092
};

enum KZChessSpells
{
    // Chess event spells
    SPELL_CLEAR_BOARD               = 37366,  // Spell cast to clear the board at the end of the event
    SPELL_GAME_IN_SESSION           = 39331,  // Debuff on players received while the game is in session
    SPELL_FORCE_KILL_BUNNY          = 45260,  // Triggers 45259
    SPELL_GAME_OVER                 = 39401,  // Cast by Medivh on game end
    SPELL_VICTORY_VISUAL            = 39395,  // Cast by the Victory controller on game end
    SPELL_IS_SQUARE_USED            = 39400,  // Cast when a chess piece moves to another square
    SPELL_CHESS_AI_ATTACK_TIMER     = 32226,  // Melee action timer - triggers 32225
    SPELL_ACTION_MELEE              = 32225,  // Handle melee attacks
    SPELL_DISABLE_SQUARE            = 32745,  // Used by the White / Black triggers on the squares when a chess piece moves into place
    SPELL_HAND_OF_MEDIVH            = 39339,

    // Spells used to transform side trigger when npc dies
    SPELL_TRANSFORM_KING_LLANE      = 39356,
    SPELL_TRANSFORM_BLACKHAND       = 39362,
    SPELL_TRANSFORM_CONJURER        = 39355,
    SPELL_TRANSFORM_WARLOCK         = 39361,
    SPELL_TRANSFORM_FOOTMAN         = 39350,
    SPELL_TRANSFORM_GRUNT           = 39357,
    SPELL_TRANSFORM_WATER_ELEM      = 39354,
    SPELL_TRANSFORM_DEAMON          = 39360,
    SPELL_TRANSFORM_CHARGER         = 39352,
    SPELL_TRANSFORM_WOLF            = 39358,
    SPELL_TRANSFORM_CLERIC          = 39353,
    SPELL_TRANSFORM_NECROLYTE       = 39359
};

enum KZChessSounds
{
    SOUND_ID_GAME_BEGIN             = 10338,
    SOUND_ID_LOSE_PAWN_PLAYER_1     = 10339,
    SOUND_ID_LOSE_PAWN_PLAYER_2     = 10340,
    SOUND_ID_LOSE_PAWN_PLAYER_3     = 10341,
    SOUND_ID_LOSE_PAWN_MEDIVH_1     = 10342,
    SOUND_ID_LOSE_PAWN_MEDIVH_2     = 10343,
    SOUND_ID_LOSE_PAWN_MEDIVH_3     = 10344,
    SOUND_ID_LOSE_ROOK_PLAYER       = 10345,
    SOUND_ID_LOSE_ROOK_MEDIVH       = 10346,
    SOUND_ID_LOSE_BISHOP_PLAYER     = 10347,
    SOUND_ID_LOSE_BISHOP_MEDIVH     = 10348,
    SOUND_ID_LOSE_KNIGHT_PLAYER     = 10349,
    SOUND_ID_LOSE_KNIGHT_MEDIVH     = 10350,
    SOUND_ID_LOSE_QUEEN_PLAYER      = 10351,
    SOUND_ID_LOSE_QUEEN_MEDIVH      = 10352,
    SOUND_ID_CHECK_PLAYER           = 10353,
    SOUND_ID_CHECK_MEDIVH           = 10354,
    SOUND_ID_WIN_PLAYER             = 10355,
    SOUND_ID_WIN_MEDIVH             = 10356,
    SOUND_ID_CHEAT_1                = 10357,
    SOUND_ID_CHEAT_2                = 10358,
    SOUND_ID_CHEAT_3                = 10359
};

enum KZMisc
{
    OPTIONAL_BOSS_REQUIRED_DEATH_COUNT = 50,

    TARGET_TYPE_HOSTILE            = 1,
    TARGET_TYPE_FRIENDLY           = 2,

    FACTION_ID_CHESS_HORDE         = 1689,
    FACTION_ID_CHESS_ALLIANCE      = 1690
};


GuidList const* GetChessPieces(InstanceScript const* scr, uint32 faciton);

template <class AI, class T>
inline AI* GetKarazhanAI(T* obj)
{
    return GetInstanceAI<AI>(obj, KZScriptName);
}
#define RegisterKarazhanCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetKarazhanAI)

#endif
