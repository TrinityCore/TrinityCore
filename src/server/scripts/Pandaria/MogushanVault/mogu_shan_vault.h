/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef MOGUSHAN_VAULT_H_
#define MOGUSHAN_VAULT_H_

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "Group.h"
#include "GameObject.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum eData
{
    DATA_STONE_GUARD                = 0,
    DATA_FENG                       = 1,
    DATA_GARAJAL                    = 2,
    DATA_SPIRIT_KINGS               = 3,
    DATA_ELEGON                     = 4,
    DATA_WILL_OF_EMPEROR            = 5,
    DATA_MAX_BOSS_DATA              = 6
};

enum eActions
{
    ACTION_ENTER_COMBAT                     = 1,
    ACTION_FAIL                             = 2,

    // Stone Guard
    ACTION_GUARDIAN_DIED                    = 3,
    ACTION_PETRIFICATION                    = 4,

    // Feng
    ACTION_SPARK                            = 5,

    // Spirit Kings
    ACTION_FIRST_FIGHT                      = 6,
    ACTION_FLANKING_MOGU                    = 7,
    ACTION_SAY_INTRO_FOR_NEXT_SPIRIT_IF_ANY = 8,
    ACTION_SPIRIT_KILLED                    = 9,

    ACTION_CONTINUE_ESCORT                  = 10,
    ACTION_RUN                              = 11,
    ACTION_SAY_ZANDALARI_BEGIN              = 12,
    ACTION_SAY_ZANDALARI_DEATH              = 13,

    ACTION_SET_GHOST_VISUAL                 = 14,
    ACTION_SET_NATIVE_DISPLAYID             = 15,

    ACTION_SETDISPLAYID_QIANG               = 16,
    ACTION_SETDISPLAYID_SUBETAI             = 17,
    ACTION_SETDISPLAYID_ZIAN                = 18,
    ACTION_SETDISPLAYID_MENG                = 19,

    ACTION_BEFORE_COMBAT                    = 20,
    ACTION_START_FIRST_COMBAT               = 21,
    ACTION_END_FIRST_COMBAT                 = 22,
    ACTION_START_SECOND_COMBAT              = 23,
    ACTION_END_SECOND_COMBAT                = 24,
    ACTION_START_THIRD_COMBAT               = 25,
    ACTION_END_THIRD_COMBAT                 = 26,
    ACTION_START_FOURTH_COMBAT              = 27,
    ACTION_END_FOURTH_COMBAT                = 28,

    ACTION_KEEPER_ENTER_COMBAT              = 29,
    ACTION_KEEPER_DIED                      = 30,
    ACTION_ELEGON_GOB_ACTIVATION            = 31,
    ACTION_TALK_WILL_OF_EMPEROR             = 32,
    ACTION_EMPERORS_DEATH                   = 33,
    ACTION_ACTIVATE_SPIRIT                  = 34,

    // Heroic Feng
    ACTION_SCHEDULE_SHIELD                  = 35,

    // Heroic Stone Guard
    ACTION_POWER_DOWN                       = 36,
    ACTION_TILING                           = 37,
    ACTION_UNTILING                         = 38,

    ACTION_OPEN_STONEGUARD_DOOR             = 39,
    ACTION_REACH_HOME                       = 40,

    ACTION_CHECK_SPIRITKINGS                = 41,
    ACTION_STOP_PETRIFY                     = 42,
    ACTION_EVENT_WIPE                       = 43
};

enum eCreatures
{
    // The Stone Guard
    NPC_STONE_GUARD_CONTROLER       = 60089,
    NPC_JASPER                      = 59915,
    NPC_JADE                        = 60043,
    NPC_AMETHYST                    = 60047,
    NPC_COBALT                      = 60051,
    NPC_COBALT_MINE                 = 65803,
    NPC_TILING_CREATURE             = 62026,
    NPC_LIVING_COBALT_CRYSTAL       = 60304,
    NPC_LIVING_JADE_CRYSTAL         = 60306,
    NPC_LIVING_JASPER_CRYSTAL       = 60307,
    NPC_LIVING_AMETHYST_CRYSTAL     = 60308,

    // Feng
    NPC_CURSED_MOGU_SCULPTURE_1     = 61989,
    NPC_CURSED_MOGU_SCULPTURE_2     = 61334,
    NPC_GHOST_ESSENCE               = 62004,
    NPC_FENG                        = 60009,
    NPC_PHASE_CONTROLER             = 61124,
    NPC_WILDFIRE_SPARK              = 60438,
    NPC_SIPHONING_SHIELD            = 60627,
    NPC_SOUL_FRAGMENT               = 60781,

    // Garajal
    NPC_GARAJAL                     = 60143,
    NPC_SHADOWY_MINION_REAL         = 60940,
    NPC_SHADOWY_MINION_SPIRIT       = 60184,
    NPC_SOUL_CUTTER                 = 62003,
    NPC_SPIRIT_TOTEM                = 60240,
    NPC_SPIRIT_TOTEM_INTRO          = 60512,
    NPC_SPIRIT_TOTEM_SKULL_INTRO    = 60513,
    NPC_SPIRITUAL_PORTAL            = 61172,

    // Spirit kings
    NPC_SPIRIT_GUID_CONTROLER       = 60984,

    NPC_ZIAN                        = 60701,
    NPC_MENG                        = 60708,
    NPC_QIANG                       = 60709,
    NPC_SUBETAI                     = 60710,

    NPC_FLANKING_MOGU               = 60847,
    NPC_PINNING_ARROW               = 60958,

    NPC_UNDYING_SHADOW              = 60731,

    // Elegon
    NPC_ELEGON                      = 60410,

    NPC_EMPYREAL_FOCUS              = 60776,
    NPC_CELESTIAL_PROTECTOR         = 60793,
    NPC_INFINITE_ENERGY             = 65293,
    NPC_ENERGY_CHARGE               = 60913,

    // Will of Emperor
    NPC_QIN_XI                      = 60399,
    NPC_JAN_XI                      = 60400,

    NPC_EMPEROR_RAGE                = 60396,
    NPC_EMPEROR_STRENGHT            = 60397,
    NPC_EMPEROR_COURAGE             = 60398,
    NPC_TITAN_SPARK                 = 60480,
    NPC_LOREWALKER_CHO              = 61348,
    NPC_MOGUSHAN_WARDEN             = 64947,
    NPC_MOGUSHAN_WARDEN_2           = 64061,

    NPC_SORCERER_MOGU               = 61250,
    NPC_MOGU_ARCHER                 = 61345,
    NPC_KINGSGUARD                  = 61347,
    NPC_MOUNTED_MOGU                = 61341,
    NPC_ZANDALARI_SKULLCHARGER      = 60375,
    NPC_ZANDALARI_INFILTRATOR       = 60381,
    NPC_ZANDALARI_FIREDANCER        = 60402,
    NPC_MOGU_SECRET_KEEPER          = 61131,
    NPC_MOGUSHAN_ENGINE_KEEPER      = 64068,
    NPC_MOGUSHAN_ARCANIST           = 64063,

    MOB_SUBETAI                     = 61427,
    MOB_MENG                        = 61429,
    MOB_ZIAN                        = 61421,
    MOB_QIANG                       = 61423,

    NPC_GENERAL_PURPOSE_BUNNY_JMF   = 55091,
    NPC_ANCIENT_MOGU_MACHINE        = 60648
};

enum eGameObjects
{
    GOB_STONE_GUARD_DOOR_ENTRANCE   = 214497,
    GOB_STONE_GUARD_DOOR_EXIT       = 214526,
    GOB_FENG_DOOR_FENCE             = 214452, // Both entrance and exit
    GOB_FENG_DOOR_EXIT              = 214696,
    GOB_GARAJAL_FENCE               = 213933, // Both entrance and exit
    GOB_GARAJAL_EXIT                = 213285,
    GOB_SPIRIT_KINGS_WIND_WALL      = 215114,
    GOB_SPIRIT_KINGS_EXIT           = 213373,

    // Elegon
    GOB_CELESTIAL_DOOR              = 214412,
    GOB_ELEGON_DOOR_ENTRANCE        = 213244,
    GOB_ELEGON_CELESTIAL_DOOR       = 214412,
    GOB_WILL_OF_EMPEROR_ENTRANCE    = 213258,
    GOB_ELEGON_CHEST                = 214383,
    GOB_ELEGON_CHEST_HEROIC         = 470000, // Custom entry

    // Feng
    GOB_SPEAR_STATUE                = 213245,
    GOB_FIST_STATUE                 = 213246,
    GOB_SHIELD_STATUE               = 213247,
    GOB_STAFF_STATUE                = 213248,

    GOB_INVERSION                   = 211628,
    GOB_CANCEL                      = 211626,

    // Elegon
    GOB_ENERGY_PLATFORM             = 213526,
    GOB_ENERGY_TITAN_DISK           = 213506,
    GOB_ENERGY_TITAN_CIRCLE_1       = 213528,
    GOB_ENERGY_TITAN_CIRCLE_2       = 213527,
    GOB_ENERGY_TITAN_CIRCLE_3       = 213529,
    GOB_CELESTIAL_COMMAND           = 211650,

    GOB_MOGU_RUNE_FIRST             = 213937,
    GOB_MOGU_RUNE_END               = 213955,

    // Will of Emperor
    GOB_ANCIENT_CONTROL_CONSOLE     = 211584
};

enum ePhases
{
    PHASE_WOE_RAGE                  = 1, // WOE = Will Of Emperor
    PHASE_WOE_STRENGHT              = 2,
    PHASE_WOE_COURAGE               = 3,
    PHASE_WOE_GAZ                   = 4
};

enum eAchievementData
{
    // Dummy spells
    ACHIEVEMENT_STONE_GUARD_KILL    = 128288
};

enum sharedSpells
{
    SPELL_BERSERK   = 26662
};

#endif // MOGUSHAN_VAULT_H_
