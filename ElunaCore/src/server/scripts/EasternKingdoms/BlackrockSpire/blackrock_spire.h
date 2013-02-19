/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_BLACKROCK_SPIRE_H
#define DEF_BLACKROCK_SPIRE_H

enum Data
{
    DATA_OMOKK,
    DATA_SHADOW_HUNTER_VOSHGAJIN,
    DATA_WARMASTER_VOONE,
    DATA_MOTHER_SMOLDERWEB,
    DATA_UROK_DOOMHOWL,                       // not scripted
    DATA_QUARTERMASTER_ZIGRIS,
    DATA_GIZRUL_THE_SLAVENER,                 // not scripted
    DATA_HALYCON,
    DATA_OVERLORD_WYRMTHALAK,
    DATA_PYROGAURD_EMBERSEER,
    DATA_WARCHIEF_REND_BLACKHAND,
    DATA_GYTH,
    DATA_THE_BEAST,
    DATA_GENERAL_DRAKKISATH,
    DATA_DRAGONSPIRE_ROOM,
};
enum Npc
{
    NPC_OMOKK                       = 9196,
    NPC_SHADOW_HUNTER_VOSHGAJIN     = 9236,
    NPC_WARMASTER_VOONE             = 9237,
    NPC_MOTHER_SMOLDERWEB           = 10596,
    NPC_UROK_DOOMHOWL               = 10584,
    NPC_QUARTERMASTER_ZIGRIS        = 9736,
    NPC_GIZRUL_THE_SLAVENER         = 10268,
    NPC_HALYCON                     = 10220,
    NPC_OVERLORD_WYRMTHALAK         = 9568,
    NPC_PYROGAURD_EMBERSEER         = 9816,
    NPC_WARCHIEF_REND_BLACKHAND     = 10429,
    NPC_GYTH                        = 10339,
    NPC_THE_BEAST                   = 10430,
    NPC_GENERAL_DRAKKISATH          = 10363,
    NPC_BLACKHAND_DREADWEAVER       = 9817,
    NPC_BLACKHAND_SUMMONER          = 9818,
    NPC_BLACKHAND_VETERAN           = 9819,
};

enum AdditionalData
{
    SPELL_SUMMON_ROOKERY_WHELP      = 15745,
    MAX_ENCOUNTER                   = 14,
    MAX_DRAGONSPIRE_HALL_RUNES      = 7,
    EVENT_PYROGUARD_EMBERSEER       = 4884,
    AREATRIGGER_ENTER_UBRS          = 2046,
    AREATRIGGER_STADIUM             = 2026,
};

enum GameObjects
{
    GO_WHELP_SPAWNER                = 175622, // trap spawned by go id 175124

    // Doors
    GO_EMBERSEER_IN                 = 175244, // First door to Pyroguard Emberseer
    GO_DOORS                        = 175705, // Second door to Pyroguard Emberseer
    GO_EMBERSEER_OUT                = 175153, // Door after Pyroguard Emberseer event
    GO_GYTH_ENTRY_DOOR              = 164726,
    GO_GYTH_COMBAT_DOOR             = 175185,
    GO_GYTH_EXIT_DOOR               = 175186,
    GO_DRAKKISATH_DOOR_1            = 175946,
    GO_DRAKKISATH_DOOR_2            = 175947,

    // Runes
    GO_ROOM_1_RUNE                  = 175197,
    GO_ROOM_2_RUNE                  = 175199,
    GO_ROOM_3_RUNE                  = 175195,
    GO_ROOM_4_RUNE                  = 175200,
    GO_ROOM_5_RUNE                  = 175198,
    GO_ROOM_6_RUNE                  = 175196,
    GO_ROOM_7_RUNE                  = 175194,

    GO_EMBERSEER_RUNE_1             = 175266,
    GO_EMBERSEER_RUNE_2             = 175267,
    GO_EMBERSEER_RUNE_3             = 175268,
    GO_EMBERSEER_RUNE_4             = 175269,
    GO_EMBERSEER_RUNE_5             = 175270,
    GO_EMBERSEER_RUNE_6             = 175271,
    GO_EMBERSEER_RUNE_7             = 175272,
};

#endif

