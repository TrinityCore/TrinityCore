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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "G3DPosition.hpp"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "UpdateFields.h"
#include "G3D/Vector2.h"
#include "sanctum_of_domination.h"

enum SylvanasSpells
{
    // Stances
    SPELL_RANGER_BOW_STANCE                                       = 347560,
    SPELL_RANGER_DAGGERS_STANCE                                   = 348010,

    // Ranger Shot
    SPELL_RANGER_SHOT                                             = 347548,

    // Ranger Strike
    SPELL_RANGER_STRIKE                                           = 348299,

    // Windrunner
    SPELL_WINDRUNNER                                              = 347504,
    SPELL_WINDRUNNER_DISAPPEAR_01                                 = 352303,
    SPELL_WINDRUNNER_DISAPPEAR_02                                 = 358975,
    SPELL_WINDRUNNER_SPIN                                         = 351187,
    SPELL_WINDRUNNER_MOVE                                         = 347606,
    SPELL_WINDRUNNER_SHOT_01                                      = 347604, // Not on the sniff
    SPELL_WINDRUNNER_JUMP_02                                      = 347605, // Not on the sniff
    SPELL_WINDRUNNER_DAGGER_01                                    = 350737, // Not on the sniff
    SPELL_WINDRUNNER_BANSHEE                                      = 352211,

    // Shadow Dagger
    SPELL_SHADOW_DAGGER_COPY                                      = 358964,
    SPELL_SHADOW_DAGGER                                           = 347670,
    SPELL_SHADOW_DAGGER_MISSILE                                   = 348089,
    SPELL_SHADOW_DAGGER_PHASE_THREE                               = 353935,

    // Withering Fire
    SPELL_WITHERING_FIRE_COPY                                     = 358981,
    SPELL_WITHERING_FIRE                                          = 347928,
    SPELL_BARBED_ARROW                                            = 347807,

    // Desecrating Shot
    SPELL_DESECRATING_SHOT                                        = 350652,
    SPELL_DESECRATING_SHOT_AREATRIGGER                            = 348626,
    SPELL_DESECRATING_SHOT_JUMP_FRONT                             = 347957,
    SPELL_DESECRATING_SHOT_JUMP_LEFT                              = 356191,
    SPELL_DESECRATING_SHOT_TRIGGERED                              = 348627,

    // Ranger Heartseeker
    SPELL_RANGER_HEARTSEEKER_AURA                                 = 352649,
    SPELL_RANGER_HEARTSEEKER_CHARGE                               = 352650,
    SPELL_RANGER_HEARTSEEKER                                      = 352663,
    SPELL_RANGER_HEARTSEEKER_PHYSICAL_DAMAGE                      = 352651,
    SPELL_RANGER_HEARTSEEKER_SHADOW_DAMAGE                        = 352652,
    SPELL_BANSHEE_MARK                                            = 347607,

    // Wailing Arrow
    SPELL_WAILING_ARROW_POINTER                                   = 348064,
    SPELL_WAILING_ARROW                                           = 347609,
    SPELL_WAILING_ARROW_VISUAL_MYTHIC                             = 358993,

    // Domination Chains
    SPELL_DOMINATION_CHAINS                                       = 349419,
    SPELL_DOMINATION_CHAINS_JUMP                                  = 347602,
    SPELL_DOMINATION_ARROW_SHOT_VISUAL                            = 350426,
    SPELL_DOMINATION_ARROW_FALL                                   = 352317,
    SPELL_DOMINATION_ARROW_FALL_AND_VISUAL                        = 352319,
    SPELL_DOMINATION_ARROW_ACTIVATE                               = 356650,
    SPELL_DOMINATION_ARROW_CALAMITY_VISUAL                        = 356769,
    SPELL_DOMINATION_ARROW_CALAMITY_AREATRIGGER                   = 356624,
    SPELL_DOMINATION_ARROW_CALAMITY_DAMAGE                        = 356649,

    SPELL_DOMINATION_CHAIN_PLAYER                                 = 349451,
    SPELL_DOMINATION_CHAIN_PERIODIC                               = 349458,

    // Veil of Darkness (Generic)
    SPELL_VEIL_OF_DARKNESS_SEARCHER                               = 347720, // Note: this spell should be used as the target searcher for all phases.
    SPELL_VEIL_OF_DARKNESS_DESELECT                               = 354366,
    SPELL_VEIL_OF_DARKNESS_SCREEN_FOG                             = 354580,
    SPELL_VEIL_OF_DARKNESS_ABSORB_AURA                            = 347704,
    SPELL_VEIL_OF_DARKNESS_VISUAL_DUMMY                           = 355749,
    SPELL_VEIL_OF_DARKNESS_DAMAGE                                 = 350777,

    // Veil of Darkness (Phase 1)
    SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE                           = 352470,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW                           = 350335,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_AREA                           = 357726,
    SPELL_VEIL_OF_DARKNESS_PHASE_1                                = 347726,

    // Banshee Shroud
    SPELL_BANSHEE_SHROUD                                          = 350857,

    // Rive
    SPELL_RIVE_DISAPPEAR                                          = 353519,
    SPELL_RIVE                                                    = 353417,
    SPELL_RIVE_FAST                                               = 353418,
    SPELL_RIVE_MARKER_AREATRIGGER                                 = 353419,
    SPELL_RIVE_CHAIN                                              = 353504,
    SPELL_RIVE_CHAIN_FAST                                         = 353510,
    SPELL_RIVE_AREATRIGGER                                        = 353375,
    SPELL_RIVE_DAMAGE                                             = 348145,
    SPELL_RIVEN_DEBRIS                                            = 353413,
    SPELL_RIVE_MYTHIC_COPY                                        = 358431,

    // Banshee Wail
    SPELL_BANSHEE_WAIL                                            = 348094,
    SPELL_BANSHEE_WAIL_TRIGGERED_MISSILE                          = 348108,
    SPELL_BANSHEE_WAIL_MISSILE                                    = 348133,
    SPELL_BANSHEE_WAIL_SILENCE                                    = 351253,
    SPELL_BANSHEE_WAIL_MARKER                                     = 357719,
    SPELL_BANSHEE_WAIL_EXPIRE                                     = 355489,

    SPELL_TELEPORT_TO_PHASE_TWO                                   = 350903,
    SPELL_TELEPORT_NO_IDEA                                        = 350905, // TARGET_DEST_DB, not sniffed

    // Banshee Form
    SPELL_BANSHEE_FORM                                            = 348146,
    SPELL_BANSHEE_READY_STANCE                                    = 357758,

    // Haunting Wave
    SPELL_HAUNTING_WAVE                                           = 352271,
    SPELL_HAUNTING_WAVE_DAMAGE                                    = 351870,

    SPELL_CALL_EARTH_DEBRIS                                       = 355491,

    // Ruin
    SPELL_RUIN                                                    = 355540,
    SPELL_RUIN_VISUAL                                             = 358990,

    // Veil of Darkness (Phase 2)
    SPELL_VEIL_OF_DARKNESS_PHASE_2_FADE                           = 353273,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_GROW                           = 352239,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA                           = 352225,
    SPELL_VEIL_OF_DARKNESS_PHASE_2                                = 347741,

    // Invigorating Field
    SPELL_INVIGORATING_FIELD_ACTIVATE                             = 353660,
    SPELL_INVIGORATING_FIELD                                      = 354175,
    SPELL_INVIGORATING_FIELD_JUMP                                 = 353642,

    // Platform Change
    SPELL_STOMP_MOVEMENT_FORCE_AURA                               = 354141,

    // Banshee's Heartseeker
    SPELL_BANSHEE_HEARTSEEKER_AURA                                = 353966,
    SPELL_BANSHEE_HEARTSEEKER_CHARGE                              = 353965,
    SPELL_BANSHEE_HEARTSEEKER                                     = 353969,
    SPELL_BANSHEE_HEARTSEEKER_PHYSICAL_DAMAGE                     = 353968,
    SPELL_BANSHEE_HEARTSEEKER_SHADOW_DAMAGE                       = 353967,

    // Banshee's Bane
    SPELL_BANSHEES_BANE                                           = 353929,
    SPELL_BANSHEES_BANE_AREATRIGGER                               = 353930,

    // Bane Arrows
    SPELL_BANE_ARROWS                                             = 354011,
    SPELL_BANE_ARROWS_DAMAGE                                      = 353972,

    // Banshee's Blades
    SPELL_BANSHEE_BLADE_PHYSICAL_DAMAGE                           = 358182,
    SPELL_BANSHEE_BLADE_SHADOW_DAMAGE                             = 358183,

    // Banshee Scream
    SPELL_BANSHEE_SCREAM                                          = 353952,

    // Veil of Darkness (Phase 3)
    SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE                           = 354168,
    SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW                           = 354143,
    SPELL_VEIL_OF_DARKNESS_PHASE_3                                = 354142,
    SPELL_VEIL_OF_DARKNESS_PHASE_3_MARKER                         = 357876,

    // Banshee's Fury
    SPELL_BANSHEES_FURY                                           = 354068,
    SPELL_BANSHEES_FURY_EXPLODE                                   = 357526,
    SPELL_BANSHEES_FURY_SCALE                                     = 357692,

    // Raze
    SPELL_RAZE                                                    = 354147,
    SPELL_RAZE_PERIODIC                                           = 354146,

    // The Jailer
    SPELL_JAILER_GROW_SOULS                                       = 355347,
    SPELL_JAILER_CAST_SOULS                                       = 355348,
    SPELL_JAILER_SOUL_SMALL                                       = 353687,
    SPELL_JAILER_SOUL_BIG                                         = 355369,

    // Anduin Wrynn
    SPELL_FOCUSING_PRISM_AURA                                     = 358166, // Related to the achievement

    // Miscelanea
    SPELL_GENERIC_ANCHOR_HERE                                     = 45313,
    SPELL_GENERIC_DUAL_WIELD                                      = 42459,
    SPELL_SYLVANAS_ROOT                                           = 347608,
    SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING                        = 352311,
    SPELL_SYLVANAS_POWER_ENERGIZE_AURA                            = 352312,

    SPELL_INTERMISSION_SCENE_AND_STUN                             = 355488,
    SPELL_INTERMISSION_SCENE                                      = 359062,
    SPELL_INTERMISSION_STUN                                       = 358550,
    SPELL_PLATFORMS_SCENE                                         = 350943,
    SPELL_FINAL_SCENE                                             = 358806,
    SPELL_FINAL_CINEMATIC                                         = 358985,
    SPELL_SYLVANAS_REWARD_ACHIEVEMENT                             = 358178,
    SPELL_SYLVANAS_FEIGN_DEATH                                    = 358844,

    SPELL_HEALTH_PCT_CHECK_INTERMISSION                           = 358794,
    SPELL_ACTIVATE_INTERMISSION                                   = 359429,
    SPELL_HEALTH_PCT_CHECK_FINISH                                 = 359430,
    SPELL_ACTIVATE_FINISH                                         = 359431
};

enum SylvanasPhases
{
    PHASE_ONE                                                     = 1,
    PHASE_INTERMISSION                                            = 4,
    PHASE_TWO                                                     = 2,
    PHASE_THREE                                                   = 3,
    PHASE_INTERMISSION_WORLD_STATE                                = 11
};

enum SylvanasEventGroups
{
    EVENT_GROUP_NORMAL_EVENTS                                     = 1,
    EVENT_GROUP_WINDRUNNER_EVENTS                                 = 2
};

enum SylvanasEvents
{
    EVENT_INTRODUCTION                                            = 1,
    EVENT_WINDRUNNER                                              = 22,
    EVENT_WITHERING_FIRE                                          = 34,
    EVENT_SHADOW_DAGGER                                           = 62,
    EVENT_SHADOW_DAGGER_TALK                                      = 80,
    EVENT_DESECRATING_SHOT                                        = 81,
    EVENT_DESECRATING_SHOT_LAUNCH                                 = 82,
    EVENT_DESECRATING_SHOT_LAUNCH_TALK                            = 83,
    EVENT_DOMINATION_CHAINS                                       = 84,
    EVENT_DOMINATION_CHAINS_JUMP                                  = 97,
    EVENT_WAILING_ARROW                                           = 150,
    EVENT_WAILING_ARROW_MARKER                                    = 151,
    EVENT_VEIL_OF_DARKNESS                                        = 152,
    EVENT_RIVE                                                    = 158,
    EVENT_FINISH_INTERMISSION                                     = 170,
    EVENT_BANE_ARROWS                                             = 200,
    EVENT_RAZE,
    EVENT_BANSHEE_SCREAM,
    EVENT_BANSHEES_FURY,
    EVENT_BLACK_ARROW                                             = 210,
    EVENT_MERCILESS                                               = 290,
    EVENT_SWITCH_PLATFORM                                         = 299,
    EVENT_SIZE_MAX                                                = 300
};

enum SylvanasEventCounterValues
{
    EVENT_COUNTER_WINDRUNNER                                      = 0,
    EVENT_COUNTER_DOMINATION_CHAINS                               = 1,
    EVENT_COUNTER_WAILING_ARROW                                   = 2,
    EVENT_COUNTER_WAILING_ARROW_MARKER                            = 3,
    EVENT_COUNTER_VEIL_OF_DARKNESS                                = 4,
    EVENT_COUNTER_RANGER_HEARTSEEKER                              = 5,
    EVENT_COUNTER_DESECRATING_SHOT                                = 6,
    EVENT_COUNTER_DESECRATING_SHOT_PATTERN                        = 7,
    EVENT_COUNTER_RIVE                                            = 8,
    EVENT_COUNTER_HAUNTING_WAVE                                   = 9,
    EVENT_COUNTER_MELEE_COMBO                                     = 10,
    EVENT_COUNTER_BANE_ARROWS                                     = 11,
    EVENT_COUNTER_SHADOW_DAGGER                                   = 12,
    EVENT_COUNTER_BANSHEE_SCREAM                                  = 13,
    EVENT_COUNTER_RAZE                                            = 14,
    EVENT_COUNTER_BANSHEES_FURY                                   = 15,
    EVENT_COUNTER_BLACK_ARROW                                     = 16,
    EVENT_COUNTER_DEATH_KNIVES                                    = 17,
    EVENT_COUNTER_MERCILESS                                       = 18,
    EVENT_COUNTER_MAX                                             = 18
};

enum SylvanasActions
{
    ACTION_RESET_MELEE_KIT                                        = 1,
    ACTION_ACTIVATE_DOMINATION_ARROW,
    ACTION_RANGER_HEARTSEEKER,
    ACTION_START_WITHERING_FIRE,
    ACTION_START_SHADOW_DAGGER,
    ACTION_START_DOMINATION_CHAINS,
    ACTION_CALCULATE_ARROWS,
    ACTION_FINISH_DOMINATION_CHAINS,
    ACTION_WAILING_ARROW,
    ACTION_PREPARE_INTERMISSION,
    ACTION_OPEN_PORTAL_TO_PHASE_TWO,
    ACTION_START_PHASE_TWO,
    ACTION_HAUNTING_WAVE_SECOND_CHAIN,
    ACTION_START_VEIL_OF_DARKNESS,
    ACTION_WINDS_OF_ICECROWN_PRE,
    ACTION_PREPARE_PHASE_THREE,
    ACTION_OPEN_PORTAL_TO_PHASE_THREE,
    ACTION_INITIATE_PHASE_THREE,
    ACTION_START_TIMERS_PHASE_THREE                               = 25,
    ACTION_START_PHASE_THREE,
    ACTION_SWITCH_PLATFORM,
    ACTION_PREPARE_FINISH_BOSS
};

enum SylvanasTexts
{
    TALK_AGGRO                                                    = 0,
    TALK_SLAY                                                     = 1,
    TALK_DISENGAGE                                                = 2,
    TALK_WINDRUNNER_ANNOUNCE                                      = 3,
    TALK_SHADOW_DAGGER                                            = 4,
    TALK_DESECRATING_SHOT                                         = 5,
    TALK_WAILING_ARROW                                            = 6,
    TALK_WAILING_ARROW_ANNOUNCE                                   = 7,
    TALK_WAILING_ARROW_ANNOUNCE_AFFECTED                          = 8,
    TALK_DOMINATION_CHAINS                                        = 9,
    TALK_DOMINATION_CHAINS_ANNOUNCE                               = 10,
    TALK_VEIL_OF_DARKNESS_ANNOUNCE                                = 11,
    TALK_VEIL_OF_DARKNESS_PHASE_ONE                               = 12,
    TALK_INTERMISSION_BEGIN                                       = 13,
    TALK_BANSHEE_WAIL_ANNOUNCE                                    = 14,
    TALK_INTERMISSION_END                                         = 15,
    TALK_HAUNTING_WAVE_ANNOUNCE                                   = 16,
    TALK_RUIN_ANNOUNCE                                            = 17,
    TALK_WINDS_OF_ICECROWN_AFTER_01                               = 18,
    TALK_VEIL_OF_DARKNESS_PHASE_TWO_AND_THREE                     = 19,
    TALK_BANSHEE_SCREAM                                           = 20,
    TALK_BANSHEE_SCREAM_ANNOUNCE                                  = 21,
    TALK_WINDS_OF_ICECROWN_AFTER_02                               = 22,
    TALK_START_PHASE_THREE                                        = 23,
    TALK_BANSHEES_FURY                                            = 24,
    TALK_RAZE_ANNOUNCE                                            = 25,
    TALK_BLACK_ARROW                                              = 26,
    TALK_BLACK_ARROW_ANNOUNCE                                     = 27,
    TALK_BLACK_ARROW_ANNOUNCE_AFFECTED                            = 28,
    TALK_RIVE_ONE                                                 = 29,
    TALK_RIVE_TWO                                                 = 30
};

enum SylvanasConversations
{
    CONVERSATION_SYLVANAS_INTRODUCTION                            = 17368,
    CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_SYLVANAS_ID          = 0,
    CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID            = 1
};

enum SylvanasSpawnGroups
{
    SPAWN_GROUP_CHAMPIONS_FIRST_PHASE                             = 0,
    SPAWN_GROUP_CHAMPIONS_THIRD_PHASE,
    SPAWN_GROUP_CHAMPIONS_OUTRODUCTION
};

enum SylvanasPoints
{
    POINT_INTRODUCTION                                            = 1
};

enum SylvanasSpellVisualKits
{
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01                = 150067,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02                = 150068,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03                = 150069,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04                = 150071,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05                = 150072,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06                = 150070,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07                = 150074,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08                = 150077,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09                = 150076,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10                = 150075,
    SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01                  = 150073,

    SPELL_VISUAL_KIT_SYLVANAS_DOMINATION_CHAINS_FINISH            = 142405,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW                       = 143939,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN                  = 142389,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS                   = 143940,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN              = 142388,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_ONE          = 142021,
    SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK                          = 145541,
    SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK_FAST                     = 145608,
    SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_BANSHEE              = 146063,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE               = 148298,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE_MYTHIC        = 142507,
    SPELL_VISUAL_KIT_SYLVANAS_WINDS_01                            = 149160,
    SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED                    = 145486,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_TELEPORT                    = 148270,
    SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_HUMAN                = 146626,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER                       = 145482,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER_SOUND                 = 145850,
    SPELL_VISUAL_KIT_SYLVANAS_WITHERING_FIRE_PHASE_TWO            = 149795,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_TWO_COPY     = 144927,
    SPELL_VISUAL_KIT_SYLVANAS_WINDS_02                            = 149161,
    SPELL_VISUAL_KIT_SYLVANAS_DARK_FOG                            = 150066,
    SPELL_VISUAL_KIT_SYLVANAS_STOMP                               = 148200,
    SPELL_VISUAL_KIT_SYLVANAS_SWITCH_PLATFORM                     = 149580,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM                      = 146059,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_BANE_ARROWS                 = 145872,
    SPELL_VISUAL_KIT_SYLVANAS_BLACKEN_WITH_DAGGERS                = 149487, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_DISAPPEAR_MODEL                     = 149491, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_TELEPORT                            = 150078,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE        = 148193,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE_FLOOR  = 148191,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE_FINISH = 148192,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_FURY_END                    = 148130,

    SPELL_VISUAL_KIT_JAINA_KNEEL_THEN_STAND                       = 146285,
    SPELL_VISUAL_KIT_JAINA_FROZEN_BRIDGE                          = 142472, // NOT ON SNIFF

    SPELL_VISUAL_KIT_THRALL_KNEEL_THEN_STAND                      = 147632,
    SPELL_VISUAL_KIT_THRALL_EARTHEN_BRIDGE                        = 142473,

    SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY                      = 148315,

    SPELL_VISUAL_KIT_JAILER_IDK_01                                = 149329,

    SPELL_VISUAL_KIT_PLAYER_ACTIVATE_FIELDS                       = 144754,

    SPELL_VISUAL_KIT_GENERIC_TELEPORT                             = 147629,
    SPELL_VISUAL_KIT_GENERIC_CHEERS                               = 147631,
};

enum SylvanasSpellVisuals
{
    SPELL_VISUAL_RANGER_STRIKE_RIGHT                              = 106153, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_LEFT                               = 106160, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_FAST_RIGHT                         = 106165, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_FAST_LEFT                          = 106161, // At 1.0f
    SPELL_VISUAL_WINDRUNNER_01                                    = 107722, // At 0.5f
    SPELL_VISUAL_WINDRUNNER_02                                    = 110312, // At 0.25f
    SPELL_VISUAL_WINDRUNNER_03                                    = 107920, // At 0.25f
    SPELL_VISUAL_DESECRATING_ARROW                                = 106363, // At 0.40f - 0.12f
    SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE                         = 105944, // At 48.0f, false as time
    SPELL_VISUAL_HEARTSEEKER                                      = 107607, // At 36f, false as time
    SPELL_VISUAL_DOMINATION_ARROW                                 = 107501, // At 2.5f
    SPELL_VISUAL_DOMINATION_ARROW_SPAWN                           = 109620, // At 2.5f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_LFR_AND_NM            = 109159, // At 5.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_HC                    = 107567, // At 5.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_MM                    = 109161, // At 5.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_SPREAD                          = 108092, // At 0.64f - 0.52f
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK                             = 108070,
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST                        = 108071,
    SPELL_VISUAL_RIVEN_DEBRIS                                     = 107877, // At 2.203702926635742187f - 1.52007603645324707f
    SPELL_VISUAL_WITHERING_FIRE_PHASE_TWO                         = 110435, // At 4.128731250762939453f - 1.461606025695800781f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_LFR_AND_NM            = 109371, // At 3.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_HC                    = 105852, // At 3.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_MM                    = 109368, // At 3.0f
    SPELL_VISUAL_BANE_ARROWS_NM_AND_HC                            = 108112, // At 3.240910291671752929f - 2.04f
    SPELL_VISUAL_BANE_ARROWS_MM                                   = 110644, // At 2.609101772308349609f - 1.790414214134216308f
    SPELL_VISUAL_BANSHEE_FURY                                     = 108130, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE                                             = 110336, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE_MISSILE                                     = 108154, // At 0.33f - 0.14f
    SPELL_VISUAL_BLASPHEMY                                        = 109680, // At 1.0f - 2.0f
    SPELL_VISUAL_JAILER_BOLT                                      = 107337, // At 90.0f, false as time
    SPELL_VISUAL_BANSHEES_BANE_ABSORB                             = 108093, // At 0.5f
    SPELL_VISUAL_BANSHEES_BANE_DROP                               = 107839, // At 0.349999994039535522f
    SPELL_VISUAL_SHADOW_DAGGER_PHASE_THREE                        = 108096, // At 100.0f, false as time
    SPELL_VISUAL_SHADOW_DAGGER_MARKER_PHASE_THREE                 = 108094, // At 1.5f

    SPELL_VISUAL_UNK01_177054                                     = 107069, // At 1.0f
    SPELL_VISUAL_BANSHEE_FURY_IDK                                 = 107476, // At 1.5f
    SPELL_VISUAL_UNK01_177787                                     = 107063  // At 1.0f
};

enum SylvanasPlatforms : uint8
{
    PLATFORM_MALDRAXXI                                            = 0,
    PLATFORM_NIGHTFAE                                             = 1,
    PLATFORM_KYRIAN                                               = 2,
    PLATFORM_VENTHYR                                              = 3,
    PLATFORM_MAX                                                  = 4
};

enum SylvanasMiscellanea
{
    DATA_INDEX_00                                                 = 0,
    DATA_INDEX_01                                                 = 1,
    DATA_INDEX_02                                                 = 2,
    DATA_INDEX_03                                                 = 3,
    DATA_INDEX_04                                                 = 4,
    DATA_INDEX_05                                                 = 5,

    DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL                            = 101311,
    DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL                        = 101310,

    DATA_DISPLAY_ID_SYLVANAS_DAGGER                               = 185997,
    DATA_DISPLAY_ID_SYLVANAS_BOW                                  = 181374,

    DATA_MELEE_COMBO_SWITCH_TO_MELEE                              = 0,
    DATA_MELEE_COMBO_RANGER_STRIKE_01                             = 1,
    DATA_MELEE_COMBO_RANGER_STRIKE_02                             = 2,
    DATA_MELEE_COMBO_SWITCH_TO_RANGED                             = 3,
    DATA_MELEE_COMBO_FINISH                                       = 4,

    DATA_CHANGE_SHEATHE_TO_UNARMED                                = 0,
    DATA_CHANGE_SHEATHE_TO_MELEE                                  = 1,
    DATA_CHANGE_SHEATHE_TO_RANGED                                 = 2,
    DATA_CHANGE_NAMEPLATE_TO_COPY                                 = 3,
    DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY                          = 4,
    DATA_CHANGE_NAMEPLATE_TO_SYLVANAS                             = 5,
    DATA_CHANGE_ATTACK_SPEED_TO_LOWEST                            = 6,
    DATA_CHANGE_ATTACK_SPEED_TO_HIGHEST                           = 7,

    DATA_EVENT_TYPE_SHADOWCOPY                                    = 1,
    DATA_EVENT_COPY_NO_EVENT                                      = 1,
    DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT                        = 2,

    DATA_AREATRIGGER_DOMINATION_ARROW                             = 27683,
    DATA_AREATRIGGER_SYLVANAS_PUSH                                = 27887,

    DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR                        = 1,

    DATA_WINDRUNNER_COUNTER_ONE                                   = 1,
    DATA_WINDRUNNER_COUNTER_TWO                                   = 2,
    DATA_WINDRUNNER_COUNTER_THREE                                 = 3,
    DATA_WINDRUNNER_COUNTER_FOUR                                  = 4,
    DATA_WINDRUNNER_COUNTER_FIVE                                  = 5,

    DATA_DESECRATING_SHOT_PATTERN_STRAIGHT                        = 1,
    DATA_DESECRATING_SHOT_PATTERN_SCATTERED                       = 2,
    DATA_DESECRATING_SHOT_PATTERN_WAVE                            = 3,
    DATA_DESECRATING_SHOT_PATTERN_SPIRAL                          = 4,
    DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED                 = 5,
    DATA_DESECRATING_SHOT_PATTERN_JAR                             = 6,

    DATA_JUMP_TIME_CERO                                           = 0,
    DATA_JUMP_TIME_ONE                                            = 1,
    DATA_JUMP_TIME_TWO                                            = 2,
    DATA_JUMP_TIME_THREE                                          = 3,
    DATA_JUMP_TIME_FOUR                                           = 4,

    DATA_BRIDGE_PHASE_TWO_1                                       = 1,
    DATA_BRIDGE_PHASE_TWO_2                                       = 2,
    DATA_BRIDGE_PHASE_TWO_3                                       = 3,

    DATA_BRIDGE_PHASE_TWO_COUNT_1                                 = 1,
    DATA_BRIDGE_PHASE_TWO_COUNT_2                                 = 2,
    DATA_BRIDGE_PHASE_TWO_COUNT_3                                 = 3,
    DATA_BRIDGE_PHASE_TWO_COUNT_4                                 = 4,
    DATA_BRIDGE_PHASE_TWO_COUNT_5                                 = 5,
    DATA_BRIDGE_PHASE_TWO_COUNT_6                                 = 6,

    DATA_MIDDLE_POS_OUTTER_PLATFORM                               = 0,
    DATA_UPPER_INNER_RIGHT_POS_VERTEX_PLATFORM                    = 1,
    DATA_BOTTOM_INNER_LEFT_POS_VERTEX_PLATFORM                    = 2,
    DATA_UPPER_OUTTER_RIGHT_POS_VERTEX_PLATFORM                   = 3,
    DATA_BOTTOM_OUTTER_LEFT_POS_VERTEX_PLATFORM                   = 4,

    DATA_INNER_PLATFORM                                           = 0,
    DATA_OUTTER_PLATFORM                                          = 1,

    DATA_PLATFORM_MIDDLE_POINT                                    = 0,
    DATA_PLATFORM_RANDOM_POINT                                    = 1
};

Position const SylvanasFirstPhasePlatformCenter = { 234.9542f, -829.9804f, 4104.986f };

constexpr float PLATFORM_RADIUS = 75.0f;

Position const SylvanasIntroPos[4] =
{
    { 231.15799f, -832.816f,   4105.0386f          },
    { 242.00348f, -840.51215f, 4105.0386f          },
    { 241.23091f, -830.0955f,  4105.0386f          },
    { 225.73611f, -844.0746f,  4104.9882f, 1.3613f }
};

/* Note: any timer that's set to 90000 means it hasn't been obtained because either there's no proof in sniffs
 * due to the fact that there's no raid group taking so long to switch phase or because DBM or BigWigs do not show
 * timers. Also, it can mean it hasn't been calculated (Black Arrow or Wailing Arrow). We will wait for Dragonflight
 * to correctly obtain the missing ones.
 */

uint32 const EventTimersPhaseOne[4][6][11] =
{
    // Looking for Raid
    {
        { 8900, 62000, 62000, 61000, 90000                }, // Windrunner
        { 29000, 63900, 63900, 63000, 90000               }, // Domination Chains
        { 34250, 40250, 30250, 33250, 90000               }, // Wailing Arrow (Marker)
        { 40000, 46000, 36500, 39000, 90000               }, // Wailing Arrow
        { 56600, 59300, 59300, 57000, 90000               }  // Veil of Darkness
    },

    // Normal
    {
        { 7800, 54750, 56650, 56400, 90000                }, // Windrunner
        { 25600, 59250, 57150, 57350, 90000               }, // Domination Chains
        { 28350, 40300, 28300, 32100, 90000               }, // Wailing Arrow (Marker)
        { 34350, 46300, 34300, 38100, 90000               }, // Wailing Arrow
        { 50000, 52300, 54800, 55000, 90000               }  // Veil of Darkness
    },

    // Heroic
    {
        { 7000, 51300, 48800, 47500, 52700                }, // Windrunner
        { 23600, 53400, 49600, 53900, 90000               }, // Domination Chains
        { 28900, 32000, 24500, 25700, 31700               }, // Wailing Arrow (Marker)
        { 34900, 38000, 30500, 31700, 37700, 31700        }, // Wailing Arrow
        { 44900, 49400, 46500, 46300, 90000               },  // Veil of Darkness
        { 20100, 19100, 17100, 29900, 4800, 32200, 16100, 12000, 25700, 20600, 4700 } // Ranger's Heartseeker
    },

    // Mythic
    {
        { 6500, 57000, 55100, 56200, 90000                }, // Windrunner
        { 29000, 55000, 64100, 90000, 90000               }, // Domination Chains
        { 34600, 57300, 57300,                            }, // Black Arrow (Marker)
        { 40600, 63300, 63300                             }, // Black Arrow
        { 48000, 43400, 46500, 52400, 90000               }, // Veil of Darkness
        { 20000, 17000, 25000, 17000, 23000, 4000, 31000, 20000, 3000, 8000 } // Ranger's Heartseeker
    }
};

uint32 const EventTimersPhaseTwo[4][6][11] =
{
    // Looking for Raid
    {
        { 8900, 62000, 62000, 61000, 90000                }, // Banshee Wave
        { 29000, 63900, 63900, 63000, 90000               }, // Shadow Dagger
        { 34000, 40000, 30000, 33000, 90000               }, // Ruin
        { 40000, 46000, 36500, 39000, 90000               }, // Banshee's Wail
        { 56600, 59300, 59300, 57000, 90000               }, // Veil of Darkness
        { 22200, 19300, 18700, 19700, 20800, 18800, 18700, 19400 } // Ranger's Heartseeker
    },

    // Normal
    {
        { 8900, 62000, 62000, 61000, 90000                }, // Banshee Wave
        { 29000, 63900, 63900, 63000, 90000               }, // Shadow Dagger
        { 34000, 40000, 30000, 33000, 90000               }, // Ruin
        { 40000, 46000, 36500, 39000, 90000               }, // Banshee's Wail
        { 56600, 59300, 59300, 57000, 90000               }, // Veil of Darkness
        { 22200, 19300, 18700, 19700, 20800, 18800, 18700, 19400 } // Ranger's Heartseeker
    },

    // Heroic
    {
        { 8900, 62000, 62000, 61000, 90000                }, // Banshee Wave
        { 29000, 63900, 63900, 63000, 90000               }, // Shadow Dagger
        { 34000, 40000, 30000, 33000, 90000               }, // Ruin
        { 40000, 46000, 36500, 39000, 90000               }, // Banshee's Wail
        { 56600, 59300, 59300, 57000, 90000               }, // Veil of Darkness
        { 22200, 19300, 18700, 19700, 20800, 18800, 18700, 19400 } // Ranger's Heartseeker
    },

    // Mythic
    {
        { 8900, 62000, 62000, 61000, 90000                }, // Banshee Wave
        { 29000, 63900, 63900, 63000, 90000               }, // Shadow Dagger
        { 34000, 40000, 30000, 33000, 90000               }, // Ruin
        { 40000, 46000, 36500, 39000, 90000               }, // Banshee's Wail
        { 56600, 59300, 59300, 57000, 90000               }, // Veil of Darkness
        { 22200, 19300, 18700, 19700, 20800, 18800, 18700, 19400 } // Ranger's Heartseeker
    }
};

uint32 const EventTimersPhaseThree[4][10][11] =
{
    // Looking for Raid
    {
        { 36100, 87800, 87900, 88800, 87900               }, // Bane Arrows
        { 54000, 89100, 93200, 84800                      }, // Shadow Dagger
        { 84600, 63300, 63400, 62900, 63500               }, // Wailing Arrow (Marker)
        { 86100, 64800, 64900, 64400, 65000               }, // Wailing Arrow
        { 44000, 68700, 66200, 67200, 67400, 67400,       }, // Veil of Darkness
        { 105700, 62100, 62000, 63100, 59900              }, // Banshee Scream
        { 95200, 89400, 86500, 90100                      }  // Raze
    },

    // Normal
    {
        { 30700, 80400, 79200, 79300, 78600               }, // Bane Arrows
        { 48100, 81000, 83600, 76900, 87600               }, // Shadow Dagger
        { 69500, 50300, 50100, 51100, 50700, 51800        }, // Wailing Arrow (Marker)
        { 77000, 57800, 57600, 58600, 58200, 59300        }, // Wailing Arrow
        { 41800, 64300, 68600, 46500, 62700, 57500, 61900 }, // Veil of Darkness
        { 96600, 52000, 55700, 55700, 58200, 59800        }, // Banshee Scream
        { 86000, 76100, 78200, 85400                      }  // Raze
    },

    // Heroic
    {
        { 29100, 76800, 73200, 76100, 74500               }, // Bane Arrows
        { 45500, 77400, 79900, 73400                      }, // Shadow Dagger
        { 72200, 54300, 52200, 53500, 56300               }, // Wailing Arrow (Marker)
        { 73700, 55800, 53700, 55000, 57800               }, // Wailing Arrow
        { 41600, 61600, 50400, 58000, 61900               }, // Veil of Darkness
        { 93300, 47400, 54500, 52000, 54900               }, // Banshee Scream
        { 82700, 73600, 71300, 81200                      }, // Raze
        { 17200, 49400, 49600, 52600, 47400, 47800, 58000 }  // Banshee's Fury
    },

    // Mythic
    {
        { 15400, 93900, 100000, 93000                     }, // Bane Arrows
        { 45500, 77400, 79900, 73400                      }, // Shadow Dagger
        { 58000, 68000, 66500, 67500, 67500               }, // Wailing Arrow (Marker)
        { 59500, 69500, 68000, 69000, 69000               }, // Wailing Arrow
        { 23500, 58000, 55000, 55000, 57000, 57000, 63000 }, // Veil of Darkness
        { 71600, 111000, 112000                           }, // Banshee Scream
        { 45400, 105000, 106000, 104000                   }, // Raze
        { 38300, 60800, 64000, 58000, 62000, 66000        }, // Banshee's Fury
        { 65700, 54700, 54300, 55000, 54000, 50000        }, // Death Knives
        { 17200, 49400, 49600, 52600, 47400, 47800, 58000 }  // Merciless
    }
};

float const DesecratingShotNormalSpiralDistance[10] =
{
    0.0f,
    3.750014f,
    7.464427f,
    11.092868f,
    14.568754f,
    17.0809464f,
    20.716787f,
    23.179819f,
    25.079182f,
    26.294075f
};

float const DesecratingShotSpiralEnclosedDistance[10] =
{
    0.0f,
    3.749988f,
    7.448239f,
    10.986361f,
    14.186308f,
    16.796705f,
    18.506325f,
    18.985258f,
    17.966669f,
    15.394481f
};

static constexpr float Magnitude = 1.0f;  // Maximum wave outbreak

static Position GetSineWavePoint(Position const& origin, float angle, uint32 tickNumber, float frequency)
{
    float distance = static_cast<float>(tickNumber);
    Position point = origin;
    point.m_positionX += std::cos(angle) * distance;
    point.m_positionY += std::sin(angle) * distance;

    G3D::Vector2 perpendicularDirection(point.GetPositionY() - origin.GetPositionY(), -(point.GetPositionX() - origin.GetPositionX()));

    point.m_positionX += perpendicularDirection.direction().x * std::sin(tickNumber * frequency) * Magnitude;
    point.m_positionY += perpendicularDirection.direction().y * std::sin(tickNumber * frequency) * Magnitude;

    return point;
}

std::array<Position, 8> const RiveThrowPos =
{
    {
        { 166.617f, -856.656f, 4113.2285f },
        { 208.542f, -761.602f, 4113.2285f },
        { 303.332f, -803.056f, 4113.2285f },
        { 302.793f, -858.021f, 4113.2285f },
        { 183.836f, -777.633f, 4113.2285f },
        { 206.884f, -897.526f, 4113.2285f },
        { 261.473f, -898.365f, 4113.2285f },
        { 287.948f, -778.238f, 4113.2285f }
    }
};

Position const SylvanasIntermissionFinishPos = { 235.1163f, -829.901f,  4105.0386f, 5.4824f };

Position const SylvanasPhase2PrePos = { -14.5625f, -943.441f,   4999.990f,  0.8928f };

Position const SylvanasHauntingWavePos[10] =
{
    { 133.5104f, -829.4792f, 4999.968f, 0.4383f },
    { 91.66666f, -835.0868f, 4999.968f, 0.4383f },
    { 92.41319f, -883.3455f, 4999.968f, 1.2723f },
    { 56.42536f, -902.6979f, 4999.968f, 1.1349f },
    { 19.02257f, -892.4983f, 4999.968f, 0.3612f }
};

Position const SylvanasPhase3PrePos = { -258.991f, -1265.996f,  5667.114f,  0.3118f };

Position const SylvanasPhase3Pos = { -280.646f, -1245.48f,   5672.13f,   2.3046f };

// Note: middle is 0, top right is 1, bottom left is 2. Points 3 and 4 are 2.0f wider for visual stuff.
Position const CovenantPlatformPos[5][5] =
{
    // Maldraxxi
    {
        { -289.9608f, -1236.4189f, 5671.9052f, float(M_PI / 2) },
        { -271.2141f, -1255.5200f, 5671.6704f, 0.00f },
        { -308.6874f, -1218.0043f, 5671.6704f, 0.00f },
        { -267.6961f, -1259.1510f, 5671.6704f, 0.00f },
        { -312.4027f, -1214.2728f, 5671.6704f, 0.00f }
    },

    // Nightfae
    {
        { -290.2621f, -1316.9971f, 5671.9067f, float(M_PI / 2) },
        { -271.2889f, -1335.1152f, 5671.6704f, 0.00f },
        { -308.4179f, -1297.5373f, 5671.6704f, 0.00f },
        { -266.7198f, -1338.2843f, 5671.6704f, 0.00f },
        { -312.8737f, -1293.4848f, 5671.6704f, 0.00f }
    },

    // Kyrian
    {
        { -209.5206f, -1316.5284f, 5671.9052f, float(M_PI / 2) },
        { -191.8095f, -1334.5333f, 5671.6704f, 0.00f },
        { -228.8465f, -1297.1842f, 5671.6704f, 0.00f },
        { -186.1904f, -1339.5640f, 5671.6704f, 0.00f },
        { -233.6290f, -1292.2752f, 5671.6704f, 0.00f }
    },

    // Venthyr
    {
        { -210.2180f, -1236.2922f, 5671.9067f, float(M_PI / 2) },
        { -192.2238f, -1254.8327f, 5671.6704f, 0.00f },
        { -229.1900f, -1217.7504f, 5671.6704f, 0.00f },
        { -186.5198f, -1260.0155f, 5671.6704f, 0.00f },
        { -234.8589f, -1211.8824f, 5671.6704f, 0.00f }
    },

    // Middle
    {
        { -249.8170f, -1276.3758f, 5667.1162f, float(M_PI / 2) },
        { -285.9056f, -1276.4102f, 5667.1166f, 0.00f }
    }
};

// Note: from left to right, starting on Maldraxxi platform.
Position const InvigoratingFieldPos[8] =
{
    { -268.229f, -1236.99f, 5671.67f, 0.0f     },
    { -289.297f, -1258.25f, 5671.67f, 4.71239f },
    { -289.569f, -1294.9f,  5671.67f, 1.5708f  },
    { -268.229f, -1316.38f, 5671.67f, 0.0f     },
    { -231.528f, -1315.5f,  5671.67f, 3.14159f },
    { -210.512f, -1294.48f, 5671.67f, 1.5708f  },
    { -210.795f, -1257.88f, 5671.67f, 4.71239f },
    { -231.528f, -1236.39f, 5671.67f, 3.14159f }
};

Position const SylvanasEncounterFinishPos = { -249.876f, -1252.4791f, 5667.1157f, 3.3742f };

Creature* GetShadowcopy(InstanceScript* instance, uint8 copyIndex)
{
    Creature* shadowCopy = instance->instance->GetCreature(instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_00 + copyIndex));
    if (!shadowCopy)
        return nullptr;

    return shadowCopy;
}

UnitAI* GetShadowcopyAI(InstanceScript* instance, uint8 copyIndex)
{
    Creature* shadowCopy = GetShadowcopy(instance, copyIndex);
    if (!shadowCopy)
        return nullptr;

    return shadowCopy->AI();
}

class SylvanasNonMeleeSelector
{
public:
    SylvanasNonMeleeSelector(Player const* obj) : _sourceObj(obj) { }

    bool operator()(Player* player) const
    {
        if (player->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee))
            return false;

        return true;
    }

private:
    Player const* _sourceObj;
};

class PauseAttackStateOrResetAttackTimer : public BasicEvent
{
public:
    PauseAttackStateOrResetAttackTimer(Unit* actor, bool paused, bool resetAttackTimer = false) : _actor(actor), _paused(paused),
        _resetAttackTimer(resetAttackTimer) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        if (_paused)
        {
            _actor->InterruptNonMeleeSpells(false);
            _actor->GetMotionMaster()->Clear();
            _actor->StopMoving();

            if (_actor->GetEntry() != BOSS_SYLVANAS_WINDRUNNER)
                _actor->AttackStop();
            else
            {
                if (_resetAttackTimer)
                    _actor->setAttackTimer(WeaponAttackType::BASE_ATTACK, 0);
            }

            _actor->ToCreature()->SetReactState(REACT_PASSIVE);
        }
        else
        {
            if (_actor->ToCreature()->GetReactState() != REACT_AGGRESSIVE)
                _actor->ToCreature()->SetReactState(REACT_AGGRESSIVE);

            if (_actor->GetEntry() == BOSS_SYLVANAS_WINDRUNNER)
            {
                if (!_actor->GetVictim())
                    if (Unit* target = _actor->GetAI()->SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true))
                        _actor->GetAI()->AttackStart(target);

                if (_resetAttackTimer)
                    _actor->setAttackTimer(WeaponAttackType::BASE_ATTACK, 0);
            }
        }

        return true;
    }

private:
    Unit* _actor;
    bool _paused;
    bool _resetAttackTimer;
};

class SetSheatheOrNameplateOrAttackSpeed : public BasicEvent
{
public:
    SetSheatheOrNameplateOrAttackSpeed(Unit* actor, uint8 event, uint8 copyIndex) : _actor(actor), _event(event), _copyIndex(copyIndex) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        switch (_event)
        {
            case DATA_CHANGE_SHEATHE_TO_UNARMED:
                _actor->SetSheath(SHEATH_STATE_UNARMED);
                break;

            case DATA_CHANGE_SHEATHE_TO_MELEE:
                _actor->SetSheath(SHEATH_STATE_MELEE);
                break;

            case DATA_CHANGE_SHEATHE_TO_RANGED:
                _actor->SetSheath(SHEATH_STATE_RANGED);
                break;

            case DATA_CHANGE_NAMEPLATE_TO_COPY:
                if (Creature* shadowCopy = GetShadowcopy(_actor->GetInstanceScript(), _copyIndex))
                    _actor->SetNameplateAttachToGUID(shadowCopy->GetGUID());
                break;

            case DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY:
                if (Creature* ridingCopy = _actor->GetInstanceScript()->GetCreature(DATA_SYLVANAS_SHADOWCOPY_RIDING))
                    _actor->SetNameplateAttachToGUID(ridingCopy->GetGUID());
                break;

            case DATA_CHANGE_NAMEPLATE_TO_SYLVANAS:
                _actor->SetNameplateAttachToGUID(ObjectGuid::Empty);
                break;

            case DATA_CHANGE_ATTACK_SPEED_TO_LOWEST:
                _actor->SetBaseAttackTime(BASE_ATTACK, 900);
                break;

            case DATA_CHANGE_ATTACK_SPEED_TO_HIGHEST:
                _actor->SetBaseAttackTime(BASE_ATTACK, 1750);
                break;

            default:
                break;
        }

        return true;
    }

private:
    Unit* _actor;
    uint8 _event;
    uint8 _copyIndex;
};

struct DesecratingShotsStorage
{
    DesecratingShotsStorage(Position pos, uint8 step, float travelSpeed) : Pos(pos), Step(step), TravelSpeed(travelSpeed) { }

    Position Pos;
    uint8 Step;
    float TravelSpeed;
};

namespace SylvanasEventHelpers
{
    uint8 const GetDifficultyForTimer(Creature* creature)
    {
        uint8 difficulty = 0;

        switch (creature->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
                difficulty = 0;
                break;
            case DIFFICULTY_NORMAL_RAID:
                difficulty = 1;
                break;
            case DIFFICULTY_HEROIC_RAID:
                difficulty = 2;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                difficulty = 3;
                break;
            default:
                break;
        }

        return difficulty;
    }

    uint8 const GetWorldStatePhase(Unit* unit)
    {
        return unit->GetMap()->GetWorldStateValue(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE);
    }
}

namespace SylvanasPositionHelpers
{
    Position const GetWindrunnerPosition(Unit* unit, float dist)
    {
        Position pos = unit->GetNearPosition(-dist, 0.0f);
        pos.m_positionZ = SylvanasEventHelpers::GetWorldStatePhase(unit) == PHASE_THREE ? 5671.90f : 4105.00f;
        return pos;
    }

    Position const GetDominationChainsJumpPosition(Creature* unit, uint8 jumpCount)
    {
        /* Note: we create one cluster per player found. Each player will compare itself with the rest and adding neighbours
         * if they're at 15.0f yards or closer. Then, we iterate through all clusters and only set the biggest size. Then,
         * we iterate through all clusters again until we find the same one. Finally, we get all the players' positionX
         * and positionY of such cluster and divide them by the cluster's size to obtain the middle common point of the cluster.
         * Lastly, we relocate taking middle of platform into account and return it as usable position.
         */

        using Cluster = std::set<Player*>;

        std::list<Player*> targets;

        unit->GetPlayerListInGrid(targets, 175.0f);

        std::map<ObjectGuid, Cluster> clusterMap;

        // Note: we compare every player with one another; if they find any at float(neighboorDistance) or closer, they're considered "neighbours".
        for (Player* player : targets)
        {
            Cluster neighboor;

            for (Player* secondPlayer : targets)
            {
                if (player->IsWithinDist(secondPlayer, 15.0f))
                    neighboor.insert(secondPlayer);
            }

            clusterMap[player->GetGUID()] = Cluster();
            clusterMap[player->GetGUID()].insert(player);

            for (Player* secondPlayer : neighboor)
                clusterMap[player->GetGUID()].insert(secondPlayer);
        }

        size_t clusterSize = 0;

        // Note: let's compare each cluster's size in our clusterMap and set the biggest one as our variable.
        for (auto const& cluster : clusterMap)
        {
            if (cluster.second.size() > clusterSize)
                clusterSize = cluster.second.size();
        }

        Position clusterPos;

        // Note: let's find our biggest cluster and get the middle points of each player inside the cluster.
        for (auto const& cluster : clusterMap)
        {
            if (clusterSize && cluster.second.size() != clusterSize)
                continue;

            float posX = 0.0f;
            float posY = 0.0f;

            for (Player* player : cluster.second)
            {
                posX += player->GetPositionX();
                posY += player->GetPositionY();
            }

            posX /= uint32(clusterSize);
            posY /= uint32(clusterSize);

            clusterPos.m_positionX = posX;
            clusterPos.m_positionY = posY;
            clusterPos.m_positionZ = unit->GetPositionZ();
        }

        SylvanasFirstPhasePlatformCenter.RelocatePositionByAngle(clusterPos, float(frand(10.0f, 12.5f) * jumpCount), clusterPos.GetAbsoluteAngle(&SylvanasFirstPhasePlatformCenter) + frand(-1.0f, 1.0f), true);

        return clusterPos;
    }

    Position const GetRandomPointInSquaredArea(uint8 platformType, Position const& a, Position const& b, float c)
    {
        if (platformType == DATA_INNER_PLATFORM)
        {
            // Note: points must be converted because the middle platform is rotated by 45 degrees.
            G3D::Vector3 point;
            G3D::CoordinateFrame{ G3D::Matrix3::fromEulerAnglesZYX(DegToRad(-45.0f), 0.0f, 0.0f), { CovenantPlatformPos[4][1].GetPositionX(), CovenantPlatformPos[4][1].GetPositionY(), CovenantPlatformPos[4][1].GetPositionZ() } }
            .toWorldSpace(G3D::Box{ { 0.0f, 0.0f, 0.0f }, { 50.0f, 50.0f, 0.0f } }).getRandomSurfacePoint(point);

            Position position = Vector3ToPosition(point);

            return position;
        }
        else
        {
            // Note: these stay the same because the outter platforms aren't rotated at all.
            float x = frand(std::min(a.GetPositionX(), b.GetPositionX()), std::max(a.GetPositionX(), b.GetPositionX()));
            float y = frand(std::min(a.GetPositionY(), b.GetPositionY()), std::max(a.GetPositionY(), b.GetPositionY()));
            float z = c;

            return Position(x, y, z);
        }

        return { };
    }

    Position const GetRandomPointInNonDesecratedPlatform(Unit* unit, uint8 platformIndex, bool isCombatArea = true)
    {
        return SylvanasPositionHelpers::GetRandomPointInSquaredArea(DATA_OUTTER_PLATFORM, CovenantPlatformPos[platformIndex][isCombatArea ? DATA_BOTTOM_INNER_LEFT_POS_VERTEX_PLATFORM : DATA_BOTTOM_OUTTER_LEFT_POS_VERTEX_PLATFORM],
            CovenantPlatformPos[platformIndex][isCombatArea ? DATA_UPPER_INNER_RIGHT_POS_VERTEX_PLATFORM : DATA_UPPER_OUTTER_RIGHT_POS_VERTEX_PLATFORM], unit->GetPositionZ());

        return { };
    }

    Position const GetPointInCurrentPlatform(Unit* unit, uint8 pointType, bool isCombatArea = true)
    {
        for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
        {
            if (!unit->IsWithinBox(CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 16.0f, 16.0f, 16.0f))
                continue;

            if (pointType == DATA_PLATFORM_MIDDLE_POINT)
                return CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM];
            else
                return SylvanasPositionHelpers::GetRandomPointInSquaredArea(DATA_OUTTER_PLATFORM, CovenantPlatformPos[platform][isCombatArea ? DATA_BOTTOM_INNER_LEFT_POS_VERTEX_PLATFORM : DATA_BOTTOM_OUTTER_LEFT_POS_VERTEX_PLATFORM],
                    CovenantPlatformPos[platform][isCombatArea ? DATA_UPPER_INNER_RIGHT_POS_VERTEX_PLATFORM : DATA_UPPER_OUTTER_RIGHT_POS_VERTEX_PLATFORM], unit->GetPositionZ());
        }

        return { };
    }
};

// 176369 - Sylvanas Shadowcopy (Fight)
struct npc_sylvanas_windrunner_shadowcopy : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()),
        _onDominationChains(false), _jumpCount(0), _totalWitheringFires(0) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUninteractible(true);
        me->SetReactState(REACT_PASSIVE);

        SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);

        _events.SetPhase(PHASE_ONE);
    }

    void Reset() override
    {
        _onDominationChains = false;
        _jumpCount = 0;
        _totalWitheringFires = 0;

        _events.Reset();
    }

    uint32 GetData(uint32 id) const override
    {
        if (id == DATA_EVENT_TYPE_SHADOWCOPY)
            return _onDominationChains ? DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT : DATA_EVENT_COPY_NO_EVENT;

        return 0;
    }

    void SetData(uint32 id, uint32 value) override
    {
        if (id == DATA_EVENT_TYPE_SHADOWCOPY)
        {
            switch (value)
            {
                case DATA_EVENT_COPY_NO_EVENT:
                    _onDominationChains = false;
                    break;
                case DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT:
                    _onDominationChains = true;
                    break;
                default:
                    break;
            }

        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        if (id == EVENT_JUMP)
        {
            DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);

            if (_onDominationChains)
                _events.ScheduleEvent(EVENT_DOMINATION_CHAINS_JUMP, 150ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
        }
    }

    void DoAction(int32 action) override
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        switch (action)
        {
            // TESTING: remove unitlist.
            case ACTION_START_WITHERING_FIRE:
            {
                switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                {
                    case PHASE_ONE:
                    {
                        // Note: we need to find a way to make this dynamic because the size changes per windrunner cast, difficulty and raid size.
                        std::list<Unit*> witheringFireTargets;
                        sylvanas->GetAI()->SelectTargetList(witheringFireTargets, 5, SelectTargetMethod::Random, 0, 500.0f, false, true);

                        for (Unit* target : witheringFireTargets)
                            _witheringFireTargetGUIDs.push_back(target->GetGUID());

                        Trinity::Containers::RandomShuffle(_witheringFireTargetGUIDs);

                        if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[0]))
                            TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f), SPELL_VISUAL_WINDRUNNER_02);

                        _events.ScheduleEvent(EVENT_WITHERING_FIRE, 48ms, 1, PHASE_ONE);
                        break;
                    }

                    case PHASE_THREE:
                    {
                        // Note: we need to find a way to make this dynamic because the size changes per raid size and difficulty cast.
                        std::list<Unit*> witheringFireTargets;
                        sylvanas->GetAI()->SelectTargetList(witheringFireTargets, 3, SelectTargetMethod::Random, 0, 500.0f, false, true);

                        for (Unit* target : witheringFireTargets)
                            _witheringFireTargetGUIDs.push_back(target->GetGUID());

                        Trinity::Containers::RandomShuffle(_witheringFireTargetGUIDs);

                        for (uint8 witheringCount = _witheringFireTargetGUIDs.size(); witheringCount > 0; witheringCount--)
                        {
                            if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_00 + witheringCount)))
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[witheringCount]))
                                    shadowCopyAI->ExecuteWitheringFirePhaseThree(_witheringFireTargetGUIDs, witheringCount);
                            }
                        }
                        break;
                    }

                    default:
                        break;
                }
                break;
            }

            // TESTING: remove unitlist.
            case ACTION_START_SHADOW_DAGGER:
            {
                std::list<Unit*> shadowDaggerTargets;
                sylvanas->GetAI()->SelectTargetList(shadowDaggerTargets, 5, SelectTargetMethod::Random, 0, 500.0f, false, true);

                for (Unit* target : shadowDaggerTargets)
                    _shadowDaggerTargetGUIDs.push_back(target->GetGUID());

                Trinity::Containers::RandomShuffle(_shadowDaggerTargetGUIDs);

                if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[0]))
                    TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 3.5f), SPELL_VISUAL_WINDRUNNER_01);
                _events.ScheduleEvent(EVENT_SHADOW_DAGGER, 48ms, 1, PHASE_ONE);
                break;
            }

            case ACTION_START_DOMINATION_CHAINS:
            {
                SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT);
                DoAction(ACTION_CALCULATE_ARROWS);
                sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_02);
                _events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 20ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                break;
            }

            case ACTION_CALCULATE_ARROWS:
            {
                // Note: number of arrows spawned is dependent on raid's difficulty and size: min. 4, max. 10 (unless on intermission, which is every player alive).
                uint8 arrowsToSpawn = _events.IsInPhase(PHASE_INTERMISSION) ? me->GetMap()->GetPlayersCountExceptGMs()
                    : std::min<uint8>(std::max<uint8>(static_cast<uint8>(std::ceil(me->GetMap()->GetPlayersCountExceptGMs() / 3)), 4), 10);
                _selectedArrowCountsPerJump = SplitArrowCasts(arrowsToSpawn);
                _jumpCount = 0;
                break;
            }

            case ACTION_PREPARE_INTERMISSION:
            {
                _events.CancelEventGroup(EVENT_GROUP_NORMAL_EVENTS);
                _events.SetPhase(PHASE_INTERMISSION);
                break;
            }

            case ACTION_START_PHASE_TWO:
            {
                _events.SetPhase(PHASE_TWO);
                break;
            }

            case ACTION_START_PHASE_THREE:
            {
                _events.SetPhase(PHASE_THREE);
                break;
            }

            // TESTING: remove unitlist.
            case ACTION_START_VEIL_OF_DARKNESS:
            {
                _veilOfDarknessPos.clear();

                uint8 targetSize = me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 3 : 2;

                std::list<Unit*> veilOfDarknessTargets;
                sylvanas->GetAI()->SelectTargetList(veilOfDarknessTargets, targetSize, SelectTargetMethod::Random, 0, 500.0f, false, false);

                for (Unit* target : veilOfDarknessTargets)
                    _veilOfDarknessPos.push_back(target->GetPosition());

                Trinity::Containers::RandomShuffle(_veilOfDarknessPos);

                _events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, 343ms, 1, _events.IsInPhase(PHASE_TWO) ? PHASE_TWO : PHASE_THREE);
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        _scheduler.Update(diff);

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WITHERING_FIRE:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[0]))
                        me->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 1, 204ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 1:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[1]))
                        TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 10.0f), SPELL_VISUAL_WINDRUNNER_02);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 2, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 2:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[1]))
                        me->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 3, 219ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 3:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[2]))
                        TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 10.0f), SPELL_VISUAL_WINDRUNNER_02);
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[0]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f));
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 4, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 4:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->ExecuteWitheringFirePhaseOne(DATA_JUMP_TIME_CERO);
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[2]))
                        me->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        shadowCopy1->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 5, 234ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 5:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[3]))
                        TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 10.0f), SPELL_VISUAL_WINDRUNNER_02);
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[1]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f));
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 6, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 6:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->ExecuteWitheringFirePhaseOne(DATA_JUMP_TIME_ONE);
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[3]))
                        me->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        shadowCopy1->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 7, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 7:
                    TeleportShadowcopyToPosition(sylvanas->GetPosition());
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 8, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 8:
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[2]))
                        me->CastSpell(SylvanasPositionHelpers::GetWindrunnerPosition(target, 10.0f), SPELL_WINDRUNNER_MOVE);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 9, 175ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 9:
                    ExecuteWitheringFirePhaseOne(DATA_JUMP_TIME_TWO);
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[4]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f), SPELL_VISUAL_WINDRUNNER_02);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 10, 100ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 10:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[4]))
                        if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                            shadowCopy1->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
                    me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 11, 103ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 11:
                    me->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 12, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 12:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[3]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f));
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 13, 140ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 13:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->ExecuteWitheringFirePhaseOne(DATA_JUMP_TIME_THREE);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        shadowCopy1->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 14, 125ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 14:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireTargetGUIDs[4]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 15.0f));
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 15, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 15:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->ExecuteWitheringFirePhaseOne(DATA_JUMP_TIME_FOUR);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        shadowCopy1->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 16, 100ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 16:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->TeleportShadowcopyToPosition(sylvanas->GetPosition());
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 17, 100ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 17:
                    _witheringFireTargetGUIDs.clear();
                    break;

                case EVENT_SHADOW_DAGGER:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[0]))
                        me->CastSpell(target->GetPosition(), SPELL_SHADOW_DAGGER_COPY, true);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 1, 78ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 1:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[1]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                            shadowCopy1AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 3.5f));
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 2, 16ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 2:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[1]))
                        if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                            shadowCopy1->CastSpell(target->GetPosition(), SPELL_SHADOW_DAGGER_COPY, true);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 3, 78ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 3:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[2]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_02)))
                            shadowCopy2AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 3.5f));
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 4, 31ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 4:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[2]))
                        if (Creature* shadowCopy2 = GetShadowcopy(_instance, DATA_INDEX_02))
                            shadowCopy2->CastSpell(target->GetPosition(), SPELL_SHADOW_DAGGER_COPY, true);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 5, 31ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 5:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[0]))
                        sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        me->SendPlayOrphanSpellVisual(shadowCopy1->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 6, 63ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 6:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[3]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy3AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_03)))
                            shadowCopy3AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 3.5f));
                    if (Creature* shadowCopy4 = GetShadowcopy(_instance, DATA_INDEX_04))
                    {
                        sylvanas->SetNameplateAttachToGUID(shadowCopy4->GetGUID());

                        if (Creature* shadowCopy2 = GetShadowcopy(_instance, DATA_INDEX_02))
                            shadowCopy4->CastSpell(shadowCopy2->GetPosition(), SPELL_WINDRUNNER_MOVE);
                    }
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 7, 15ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 7:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[3]))
                        if (Creature* shadowCopy3 = GetShadowcopy(_instance, DATA_INDEX_03))
                            shadowCopy3->CastSpell(target->GetPosition(), SPELL_SHADOW_DAGGER_COPY, true);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 8, 32ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 8:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[1]))
                        sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        if (Creature* shadowCopy2 = GetShadowcopy(_instance, DATA_INDEX_02))
                            shadowCopy1->SendPlayOrphanSpellVisual(shadowCopy2->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 9, 62ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 9:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[4]))
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopy5AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_05)))
                            shadowCopy5AI->TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 3.5f));
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 10, 16ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 10:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[4]))
                        if (Creature* shadowCopy5 = GetShadowcopy(_instance, DATA_INDEX_05))
                            shadowCopy5->CastSpell(target->GetPosition(), SPELL_SHADOW_DAGGER_COPY, true);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 11, 31ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 11:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[2]))
                        sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    if (Creature* shadowCopy2 = GetShadowcopy(_instance, DATA_INDEX_02))
                        if (Creature* shadowCopy3 = GetShadowcopy(_instance, DATA_INDEX_03))
                            shadowCopy2->SendPlayOrphanSpellVisual(shadowCopy3->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 12, 109ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 12:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[3]))
                        sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    if (Creature* shadowCopy3 = GetShadowcopy(_instance, DATA_INDEX_03))
                        if (Creature* shadowCopy5 = GetShadowcopy(_instance, DATA_INDEX_05))
                            shadowCopy3->SendPlayOrphanSpellVisual(shadowCopy5->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 13, 78ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 13:
                    if (Creature* shadowCopy4 = GetShadowcopy(_instance, DATA_INDEX_04))
                        shadowCopy4->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 14, 32ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 14:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _shadowDaggerTargetGUIDs[4]))
                        sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    if (Creature* shadowCopy5 = GetShadowcopy(_instance, DATA_INDEX_05))
                        shadowCopy5->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 15, 172ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 15:
                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    _events.ScheduleEvent(EVENT_SHADOW_DAGGER + 16, 20ms, 1, PHASE_ONE);
                    break;

                case EVENT_SHADOW_DAGGER + 16:
                    _shadowDaggerTargetGUIDs.clear();
                    break;

                case EVENT_DOMINATION_CHAINS:
                    sylvanas->CastSpell(sylvanas, SPELL_DOMINATION_CHAINS);
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 1, 15ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 1:
                    _dominationChainJumpPos = SylvanasPositionHelpers::GetDominationChainsJumpPosition(sylvanas, DATA_JUMP_TIME_ONE);
                    JumpShadowcopyToPosition(_dominationChainJumpPos, SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 2, 120ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 2:
                    sylvanas->AI()->Talk(TALK_DOMINATION_CHAINS_ANNOUNCE);
                    sylvanas->AI()->Talk(_events.IsInPhase(PHASE_ONE) ? TALK_DOMINATION_CHAINS : TALK_INTERMISSION_BEGIN);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 3, 616ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 3:
                    sylvanas->NearTeleportTo(_dominationChainJumpPos, true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 4, 62ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 4:
                    _dominationChainJumpPos = SylvanasPositionHelpers::GetDominationChainsJumpPosition(sylvanas, DATA_JUMP_TIME_TWO);
                    JumpShadowcopyToPosition(_dominationChainJumpPos, SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 5, 750ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 5:
                    sylvanas->NearTeleportTo(_dominationChainJumpPos, true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 6, 63ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 6:
                    _dominationChainJumpPos = SylvanasPositionHelpers::GetDominationChainsJumpPosition(sylvanas, DATA_JUMP_TIME_THREE);
                    JumpShadowcopyToPosition(_dominationChainJumpPos, SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 7, 560ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 7:
                    sylvanas->NearTeleportTo(_dominationChainJumpPos, true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 8, 80ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 8:
                    TeleportShadowcopyToPosition(sylvanas->GetPosition());
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 9, 220ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 9:
                    sylvanas->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 10, 5s, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 10:
                    sylvanas->GetAI()->DoAction(ACTION_FINISH_DOMINATION_CHAINS);
                    break;

                case EVENT_DOMINATION_CHAINS_JUMP:
                    DoCastSelf(SPELL_DOMINATION_ARROW_SHOT_VISUAL, true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS_JUMP + 1, 50ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS_JUMP + 1:
                {
                    for (uint8 i = 0; i < 5; i++)
                    {
                        Position const falseArrowPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(2.5f, 55.0f));

                        me->SendPlaySpellVisual(falseArrowPos, SPELL_VISUAL_DOMINATION_ARROW, 0, 0, 2.0f, true);

                        _scheduler.Schedule(2s, [this, falseArrowPos](TaskContext /*task*/)
                        {
                            if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                            sylvanas->CastSpell(falseArrowPos, SPELL_DOMINATION_ARROW_FALL, true);
                        });
                    }

                    for (uint32 i = 0; i < _selectedArrowCountsPerJump[_jumpCount]; ++i)
                    {
                        Position const arrowPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(2.5f, 55.0f));

                        if (Creature* dominationArrow = sylvanas->SummonCreature(NPC_DOMINATION_ARROW, arrowPos, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            me->SendPlaySpellVisual(arrowPos, SPELL_VISUAL_DOMINATION_ARROW_SPAWN, 0, 0, 2.0f, true);

                            ObjectGuid dominationArrowGUID = dominationArrow->GetGUID();

                            _scheduler.Schedule(2s, [this, dominationArrowGUID](TaskContext /*task*/)
                            {
                                if (Unit* dominationArrow = ObjectAccessor::GetUnit(*me, dominationArrowGUID))
                                {
                                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                        sylvanas->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_FALL_AND_VISUAL, true);

                                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                                        dominationArrow->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_CALAMITY_VISUAL);
                                }
                            });
                        }
                    }

                    ++_jumpCount;
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS:
                    StartVeilOfDarkness(_veilOfDarknessPos, DATA_INDEX_00);
                    _events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 1, 313ms, 1, PHASE_TWO);
                    break;

                case EVENT_VEIL_OF_DARKNESS + 1:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_01)))
                        shadowCopy1AI->StartVeilOfDarkness(_veilOfDarknessPos, DATA_INDEX_01);
                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                        _events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 2, 313ms, 1, PHASE_TWO);
                    break;

                case EVENT_VEIL_OF_DARKNESS + 2:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_02)))
                        shadowCopy2AI->StartVeilOfDarkness(_veilOfDarknessPos, DATA_INDEX_02);
                    break;

                default:
                    break;
            }
        }
    }

    void TeleportShadowcopyToPosition(Position chosenPos, uint32 spellVisual = 0)
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        // HACKFIX: remove orientation when SPELL_ATTR12_UNK11 (Face Destination) is implemented.
        me->NearTeleportTo(chosenPos.GetPositionX(), chosenPos.GetPositionY(), chosenPos.GetPositionZ(), chosenPos.GetAbsoluteAngle(sylvanas->GetPosition()));

        if (spellVisual > 0)
        {
            float speed = spellVisual == SPELL_VISUAL_WINDRUNNER_01 ? 0.5f : 0.25f;

            sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
        }
    }

    void JumpShadowcopyToPosition(Position chosenPos, uint32 spellVisual)
    {
        me->CastSpell(chosenPos, SPELL_DOMINATION_CHAINS_JUMP);

        float speed = spellVisual == SPELL_VISUAL_WINDRUNNER_01 ? 0.5f : 0.25f;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
    }

    void ExecuteWitheringFirePhaseOne(uint8 jumpTime)
    {
        uint32 currentWitheringFires = 0;

        // TESTING: remove false param and playerlist.
        // Note: number of casts is dependent on raid's difficulty and size: if mythic, 15; if not, half the raid (min. 5, max. 15).
        //_totalWitheringFires = me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 15 : std::max<uint8>(5, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 2));
        _totalWitheringFires = 15;

        std::list<Unit*> witheringFireTargetList;
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->GetAI()->SelectTargetList(witheringFireTargetList, _totalWitheringFires, SelectTargetMethod::Random, 0, 500.0f, false, true);

        for (Unit* target : witheringFireTargetList)
            _witheringFireExecuteTargetGUIDs.push_back(target->GetGUID());

        // Note: each copy (of a total of 5) casts up to 2 Withering Fires (if _totalWitheringFires is higher than 11), except the third (index starts at 0),
        // which casts the remaining because that's the copy where Sylvanas cosmetically jumps to.
        if (jumpTime == DATA_JUMP_TIME_TWO)
            currentWitheringFires = _totalWitheringFires > 11 ? _totalWitheringFires - 8 : _totalWitheringFires - 4;
        else
            currentWitheringFires = _totalWitheringFires > 11 ? 2 : 1;

        std::vector<Unit*> targetedPlayers;
        for (uint8 itr = currentWitheringFires; itr > 0 && !_witheringFireExecuteTargetGUIDs.empty(); itr--)
        {
            if (Unit* target = ObjectAccessor::GetUnit(*me, _witheringFireExecuteTargetGUIDs.front()))
                targetedPlayers.push_back(target);

            _witheringFireExecuteTargetGUIDs.erase(std::remove(_witheringFireExecuteTargetGUIDs.begin(), _witheringFireExecuteTargetGUIDs.end(), _witheringFireExecuteTargetGUIDs.front()), _witheringFireExecuteTargetGUIDs.end());
        }

        for (Unit* target : targetedPlayers)
        {
            float speed = 48.0f;

            me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE, 0, 0, speed, false);

            ObjectGuid targetGUID = target->GetGUID();

            uint32 timer = uint32(me->GetDistance(target) * 0.02083 * 1000);

            _scheduler.Schedule(Milliseconds(timer), [this, targetGUID](TaskContext /*task*/)
            {
                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                    sylvanas->CastSpell(target, SPELL_WITHERING_FIRE);
            });
        }
    }

    void StoreDesecratingShots(Position pos, uint8 step, float travelSpeed)
    {
        _desecratingShotStorage.emplace_back(pos, step, travelSpeed);
    }

    void StartDesecratingShotEvent(uint8 pattern, uint8 copyIndex)
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                sylvanas->CastSpell(sylvanas, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2550));
                sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 633));

                me->NearTeleportTo(sylvanas->GetNearPosition(-5.0f, 0.0f));

                _scheduler.Schedule(5ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 5.048f, me->GetOrientation());
                });

                _scheduler.Schedule(15ms, [this, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlayOrphanSpellVisual(me->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true);
                });

                _scheduler.Schedule(63ms, [this, sylvanas](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_DESECRATING_SHOT_JUMP_FRONT);

                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                });

                _scheduler.Schedule(146ms, [this, sylvanas](TaskContext /*task*/)
                {
                    me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                });

                _scheduler.Schedule(193ms, [this](TaskContext /*task*/)
                {
                    ReleaseDesecratingShots();
                });

                _scheduler.Schedule(633ms, [this, sylvanas](TaskContext /*task*/)
                {
                    _desecratingShotStorage.clear();

                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                });
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED:
            {
                uint8 shootingPointIndex = pattern == DATA_DESECRATING_SHOT_PATTERN_WAVE ? 0 : 27;

                Position shootingPos(_desecratingShotStorage[shootingPointIndex].Pos.GetPositionX(), _desecratingShotStorage[shootingPointIndex].Pos.GetPositionY(), 4112.0386f);

                me->NearTeleportTo(shootingPos);

                if (copyIndex == 2)
                {
                    sylvanas->CastSpell(sylvanas, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2950));
                    sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1204));

                    sylvanas->SendPlayOrphanSpellVisual(shootingPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }
                else if (copyIndex == 1)
                {
                    if (Creature* shadowCopy2 = GetShadowcopy(_instance, DATA_INDEX_02))
                        shadowCopy2->SendPlayOrphanSpellVisual(shootingPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }
                else
                {
                    if (Creature* shadowCopy1 = GetShadowcopy(_instance, DATA_INDEX_01))
                        shadowCopy1->SendPlayOrphanSpellVisual(shootingPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }

                _scheduler.Schedule(215ms, [this, shootingPos, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                me->CastSpell(shootingPos, SPELL_DESECRATING_SHOT_JUMP_FRONT, true);
                });

                _scheduler.Schedule(240ms, [this](TaskContext /*task*/)
                {
                    ReleaseDesecratingShots();
                });

                _scheduler.Schedule(450ms, [this, sylvanas, copyIndex](TaskContext /*task*/)
                {
                    _desecratingShotStorage.clear();

                if (copyIndex == 0)
                {
                    me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.5f, true, false);

                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                }
                });
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
                break;

            default:
                break;
        }
    }

    void ReleaseDesecratingShots()
    {
        for (DesecratingShotsStorage const& desecratingShot : _desecratingShotStorage)
        {
            float travelSpeed = desecratingShot.TravelSpeed;

            if (desecratingShot.Step >= 2)
                travelSpeed += float((me->GetExactDist(desecratingShot.Pos) * (0.016465054083896f * desecratingShot.Step) / 46.5));

            me->SendPlaySpellVisual(desecratingShot.Pos, SPELL_VISUAL_DESECRATING_ARROW, 0, 0, travelSpeed, true);

            uint32 timer = uint32(travelSpeed * 1000);

            _scheduler.Schedule(Milliseconds(timer), [this, desecratingShot](TaskContext /*task*/)
            {
                Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
            if (!sylvanas)
                return;

            sylvanas->CastSpell(desecratingShot.Pos, SPELL_DESECRATING_SHOT_TRIGGERED, true);

            std::vector<AreaTrigger*> desecratingShots = sylvanas->GetAreaTriggers(SPELL_DESECRATING_SHOT_AREATRIGGER);

            for (AreaTrigger* desecratingAreatrigger : desecratingShots)
            {
                if (desecratingAreatrigger->GetPosition() != desecratingShot.Pos)
                    continue;

                desecratingAreatrigger->Remove();
            }
            });
        }
    }

    void StartVeilOfDarkness(std::vector<Position> vectorPos, uint8 targetCount)
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        uint32 spellVisual = 0;

        switch (me->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_HEROIC_RAID:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_HC;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_MM;
                break;
            default:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_LFR_AND_NM;
                break;
        }

        Position targetPos = vectorPos[targetCount].GetPosition();

        if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00 + targetCount))
            shadowCopy->NearTeleportTo(targetPos);

        sylvanas->SendPlayOrphanSpellVisual(Position(targetPos.GetPositionX(), targetPos.GetPositionY(), targetPos.GetPositionZ() + 0.05f), spellVisual, 3.0f, true, false);

        _scheduler.Schedule(828ms, [this, vectorPos, targetCount](TaskContext /*task*/)
        {
            if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_00 + targetCount)))
                shadowCopyAI->SendVeilOfDarkness(vectorPos, targetCount);
        });
    }

    void SendVeilOfDarkness(std::vector<Position> vectorPos, uint8 targetCount)
    {
        if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00 + targetCount))
            shadowCopy->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_TWO_COPY, 0, 0);

        _scheduler.Schedule(2s, [this, vectorPos, targetCount](TaskContext /*task*/)
        {
            if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, DATA_INDEX_00 + targetCount)))
                shadowCopyAI->ExecuteVeilOfDarkness(vectorPos, targetCount);
        });
    }

    void ExecuteVeilOfDarkness(std::vector<Position> vectorPos, uint8 targetCount)
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        Position targetPos = vectorPos[targetCount].GetPosition();

        sylvanas->CastSpell(targetPos, SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA, true);
    }

    void ExecuteWitheringFirePhaseThree(std::vector<ObjectGuid> witheringFireGuids, uint8 targetCount)
    {
        uint32 additionalTimer = 150 * targetCount;

        if (Unit* target = ObjectAccessor::GetUnit(*me, witheringFireGuids[targetCount]))
            TeleportShadowcopyToPosition(SylvanasPositionHelpers::GetWindrunnerPosition(target, 25.0f), SPELL_VISUAL_WINDRUNNER_02);

        _scheduler.Schedule(Milliseconds(50 + additionalTimer), [this, witheringFireGuids, targetCount](TaskContext /*task*/)
        {
            if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00 + targetCount))
                if (Unit* target = ObjectAccessor::GetUnit(*me, witheringFireGuids[targetCount]))
                    me->CastSpell(target->GetPosition(), SPELL_WITHERING_FIRE_COPY, true);
        });

        _scheduler.Schedule(Milliseconds(573 + additionalTimer), [this, witheringFireGuids, targetCount](TaskContext /*task*/)
        {
            if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00 + targetCount))
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, witheringFireGuids[targetCount]))
                {
                    float speed = 48.0f;

                    me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE, 0, 0, speed, false);

                    ObjectGuid targetGUID = target->GetGUID();

                    uint32 timer = uint32(me->GetDistance(target) * 0.02083 * 1000);

                    _scheduler.Schedule(Milliseconds(timer), [this, targetGUID](TaskContext /*task*/)
                    {
                        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                            if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                                sylvanas->CastSpell(target, SPELL_WITHERING_FIRE);
                    });
                }
            }
        });
    }

    std::array<uint32, 3> SplitArrowCasts(uint32 totalArrows)
    {
        std::array<uint32, 3> arrowsPerWave = { };

        uint32 baseArrowsPerWave = totalArrows / 3;

        arrowsPerWave.fill(baseArrowsPerWave);

        uint32 remainder = totalArrows - baseArrowsPerWave * 3;

        for (uint32 i = 0; i < remainder; ++i)
            ++arrowsPerWave[i];

        Trinity::Containers::RandomShuffle(arrowsPerWave);

        return arrowsPerWave;
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
    std::vector<ObjectGuid> _witheringFireExecuteTargetGUIDs;
    std::vector<ObjectGuid> _witheringFireTargetGUIDs;
    std::vector<ObjectGuid> _shadowDaggerTargetGUIDs;
    std::vector<DesecratingShotsStorage> _desecratingShotStorage;
    std::vector<Position> _veilOfDarknessPos;
    Position _dominationChainJumpPos;
    bool _onDominationChains;
    uint8 _jumpCount;
    uint32 _totalWitheringFires;
    std::array<uint32, 3> _selectedArrowCountsPerJump = { };
};

// 178355 - Sylvanas Shadowcopy (Riding)
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUninteractible(true);
        me->SetReactState(REACT_PASSIVE);
    }
};

npc_sylvanas_windrunner_shadowcopy* GetShadowcopyCastAI(InstanceScript* instance, uint8 copyIndex)
{
    Creature* shadowCopy = GetShadowcopy(instance, copyIndex);

    if (!shadowCopy)
        return nullptr;

    return CAST_AI(npc_sylvanas_windrunner_shadowcopy, shadowCopy->AI());
}

// 175732 - Sylvanas Windrunner
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

        DoCastSelf(SPELL_GENERIC_DUAL_WIELD, true);
        DoCastSelf(SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING, true);

        me->SetPower(me->GetPowerType(), 0);

        if (instance->GetData(DATA_SYLVANAS_INTRODUCTION) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(false);
            me->SetSpeed(MOVE_RUN, 14.0f);
        }
        else
        {
            me->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(true);
            me->SetSpeed(MOVE_RUN, 4.0f);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(TALK_DISENGAGE);

        _EnterEvadeMode();

        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        CleanUpEncounter();

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        _desecratedPlatforms = 0;
        _lastSlayTalk = 0;
        _ruinInterrupted = 0;

        // Note: every creature involved in the fight adds UNIT_FLAG_PET_IN_COMBAT or UNIT_FLAG_RENAME when engaging, meaning they're most likely summoned by Sylvanas.
        me->SummonCreatureGroup(SPAWN_GROUP_CHAMPIONS_FIRST_PHASE);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.Reset();

        // Note: Rive positions must be randomized.
        for (uint8 i = 0; i < RiveThrowPos.size(); i++)
            _selectedRivePos.push_back(RiveThrowPos[i]);

        Trinity::Containers::RandomShuffle(_selectedRivePos);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SYLVANAS_SHADOWCOPY_FIGHTER:
                _shadowCopyGUID.push_back(summon->GetGUID());
                break;
            default:
                break;
        }
    }

    void JustRegisteredAreaTrigger(AreaTrigger* areaTrigger) override
    {
        switch (areaTrigger->GetSpellId())
        {
            case SPELL_INVIGORATING_FIELD_ACTIVATE:
                _invigoratingFieldGUID.push_back(areaTrigger->GetGUID());
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_INTRODUCTION)
            DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer() || (time(nullptr) < (_lastSlayTalk + 5)))
            return;

        BossAI::KilledUnit(victim);

        _lastSlayTalk = time(nullptr);

        Talk(TALK_SLAY);
    }

    void OnSpellFailed(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RUIN)
        {
            ++_ruinInterrupted;

            if (_ruinInterrupted == DATA_INDEX_01 || _ruinInterrupted == DATA_INDEX_05)
                if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    bolvar->GetAI()->DoAction(ACTION_WINDS_OF_ICECROWN_PRE);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        // Note: it is safe to assume that these are summoned by a serverside spell.
        for (uint8 i = 0; i < 6; ++i)
            me->SummonCreature(NPC_SYLVANAS_SHADOWCOPY_FIGHTER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);

        Talk(TALK_AGGRO);

        HandlePhaseOne();

        DoCastSelf(SPELL_SYLVANAS_POWER_ENERGIZE_AURA, true);
        DoCastSelf(SPELL_RANGER_HEARTSEEKER_AURA, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_INTERMISSION, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_FINISH, true);

        // Note: Sylvanas uses her root with 2s at the beginning of the encounter, most likely to avoid her moving when engaging at stance switch.
        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2000));
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RESET_MELEE_KIT:
                _eventCounter[EVENT_COUNTER_MELEE_COMBO] = 0;
                break;

            case ACTION_FINISH_DOMINATION_CHAINS:
            {
                TeleportShadowcopiesToMe();

                for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                        shadowCopy->GetAI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);

                if (events.IsInPhase(PHASE_ONE))
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false, true), me->m_Events.CalculateTime(1s + 500ms));
                else
                {
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true, false), me->m_Events.CalculateTime(0ms));
                    TeleportShadowcopiesToMe();
                    events.ScheduleEvent(EVENT_RIVE, 641ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                }
                break;
            }

            // TODO: move this to an event because the transition shouldn't happen at all until on-going events are done.
            case ACTION_PREPARE_INTERMISSION:
            {
                events.CancelEventGroup(EVENT_GROUP_NORMAL_EVENTS);
                events.CancelEventGroup(EVENT_GROUP_WINDRUNNER_EVENTS);
                scheduler.CancelAll();

                HandlePhaseIntermission();

                events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                break;
            }

            case ACTION_START_PHASE_TWO_ON_SYLVANAS:
            {
                if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                {
                    jaina->GetAI()->DoAction(ACTION_OPEN_PORTAL_TO_PHASE_TWO);

                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INTERMISSION_STUN);

                    HandlePhaseTwo();
                }
                break;
            }

            case ACTION_HAUNTING_WAVE_SECOND_CHAIN:
            {
                if (_eventCounter[EVENT_COUNTER_HAUNTING_WAVE] < 5)
                {
                    scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, true);
                    DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 7000));
                    });

                    scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasHauntingWavePos[_eventCounter[EVENT_COUNTER_HAUNTING_WAVE]], SPELL_VISUAL_WINDRUNNER_02, 0.25f, true);
                    });

                    scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(SylvanasHauntingWavePos[_eventCounter[EVENT_COUNTER_HAUNTING_WAVE]]);
                    me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                    });

                    scheduler.Schedule(1s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_HAUNTING_WAVE);

                    if (_eventCounter[EVENT_COUNTER_HAUNTING_WAVE] == 0)
                        Talk(TALK_HAUNTING_WAVE_ANNOUNCE);
                    });

                    scheduler.Schedule(5s + 500ms, [this](TaskContext /*task*/)
                    {
                        _eventCounter[EVENT_COUNTER_HAUNTING_WAVE]++;

                    DoAction(ACTION_HAUNTING_WAVE_SECOND_CHAIN);
                    });
                }
                else
                {
                    scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, true);
                    });

                    scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasPhase2PrePos, SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    });

                    scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(SylvanasPhase2PrePos);
                    me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                    });

                    scheduler.Schedule(5s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_RUIN);

                    Talk(TALK_RUIN_ANNOUNCE);
                    });
                }
                break;
            }

            case ACTION_PREPARE_PHASE_THREE:
            {
                me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(0ms));

                me->SummonCreatureGroup(SPAWN_GROUP_CHAMPIONS_THIRD_PHASE);

                if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                {
                    jaina->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(jaina, true), jaina->m_Events.CalculateTime(0ms));

                    jaina->GetAI()->DoAction(ACTION_OPEN_PORTAL_TO_PHASE_THREE);
                }

                if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    bolvar->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(bolvar, true), bolvar->m_Events.CalculateTime(0ms));

                if (Creature* thrall = instance->GetCreature(DATA_THRALL_PINNACLE))
                    thrall->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(thrall, true), thrall->m_Events.CalculateTime(0ms));
                break;
            }

            case ACTION_INITIATE_PHASE_THREE:
            {
                me->NearTeleportTo(SylvanasPhase3PrePos);

                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);
                });

                scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    TeleportShadowcopiesToMe();

                DoCastSelf(SPELL_RANGER_BOW_STANCE, true);

                me->m_Events.KillAllEvents(true);

                me->RemoveAura(SPELL_RANGER_HEARTSEEKER_AURA);
                me->RemoveAura(SPELL_RANGER_HEARTSEEKER_CHARGE);
                });
                break;
            }

            case ACTION_START_TIMERS_PHASE_THREE:
            {
                HandlePhaseThree();
                break;
            }

            case ACTION_START_PHASE_THREE:
            {
                DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 650));
                DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1750));

                if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                {
                    me->SetNameplateAttachToGUID(shadowCopy->GetGUID());

                    shadowCopy->CastSpell(SylvanasPhase3Pos, SPELL_DOMINATION_CHAINS_JUMP, true);

                    me->SendPlayOrphanSpellVisual(SylvanasPhase3Pos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }

                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    Talk(TALK_START_PHASE_THREE);
                });

                scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(SylvanasPhase3Pos);

                me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                });

                scheduler.Schedule(1s, [this](TaskContext /*task*/)
                {
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false), me->m_Events.CalculateTime(0ms));

                me->SetPower(me->GetPowerType(), 0);
                DoCastSelf(SPELL_BANSHEE_HEARTSEEKER_AURA, true);
                });
                break;
            }

            case ACTION_SWITCH_PLATFORM:
                me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(0ms));
                events.ScheduleEvent(EVENT_SWITCH_PLATFORM, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WINDRUNNER:
                {
                    Talk(TALK_WINDRUNNER_ANNOUNCE);

                    // Note: no SPELL_START or SPELL_GO in the sniff.
                    me->AddAura(SPELL_RANGER_BOW_STANCE, me);

                    HandleWindrunner();
                    break;
                }

                case EVENT_WITHERING_FIRE:
                {
                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                        {
                            TeleportShadowcopiesToMe();
                            DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 2062));
                            DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3800));
                            if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                                shadowCopy->GetAI()->DoAction(ACTION_START_WITHERING_FIRE);
                            break;
                        }

                        case PHASE_TWO:
                        {
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WITHERING_FIRE_PHASE_TWO, 0, 0);

                            scheduler.Schedule(312ms, [this](TaskContext /*task*/)
                            {
                                uint32 targetSize = 5;

                            switch (me->GetMap()->GetDifficultyID())
                            {
                                case DIFFICULTY_NORMAL_RAID:
                                case DIFFICULTY_MYTHIC_RAID:
                                    targetSize = 4; break;
                                default:
                                    break;
                            }

                            std::list<Unit*> targets;
                            SelectTargetList(targets, targetSize, SelectTargetMethod::Random, 0, 500.0f, false, true);

                            for (Unit* target : targets)
                            {
                                float speed = frand(1.461606025695800781f, 4.128731250762939453f);

                                me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_TWO, 0, 0, speed, true);

                                ObjectGuid targetGUID = target->GetGUID();

                                uint32 timer = uint32(speed * 1000);

                                scheduler.Schedule(Milliseconds(timer), [this, targetGUID](TaskContext /*task*/)
                                {
                                    if (Player* target = ObjectAccessor::GetPlayer(*me, targetGUID))
                                    me->CastSpell(target, SPELL_WITHERING_FIRE);
                                });
                            }
                            });
                            break;
                        }

                        case PHASE_THREE:
                        {
                            TeleportShadowcopiesToMe();
                            if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                                shadowCopy->GetAI()->DoAction(ACTION_START_WITHERING_FIRE);
                            events.Repeat(9s);
                            break;
                        }

                        default:
                            break;
                    }

                    break;
                }

                case EVENT_SHADOW_DAGGER:
                {
                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                        {
                            TeleportShadowcopiesToMe();
                            DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 1500));
                            DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3200));
                            if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                                shadowCopy->GetAI()->DoAction(ACTION_START_SHADOW_DAGGER);
                            break;
                        }

                        case PHASE_TWO:
                        {
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER_SOUND, 0, 0);
                            std::list<Player*> targetList;
                            GetPlayerListInGrid(targetList, me, 500.0f);
                            for (Player* target : targetList)
                                me->CastSpell(target, SPELL_SHADOW_DAGGER_MISSILE, true);
                            break;
                        }

                        case PHASE_THREE:
                        {
                            DoCastSelf(SPELL_SHADOW_DAGGER_PHASE_THREE);
                            events.Repeat(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][1][_eventCounter[EVENT_COUNTER_SHADOW_DAGGER]]));
                            break;
                        }

                        default:
                            break;
                    }

                    break;
                }

                case EVENT_DESECRATING_SHOT:
                {
                    _eventCounter[EVENT_COUNTER_DESECRATING_SHOT]++;

                    switch (_eventCounter[EVENT_COUNTER_WINDRUNNER])
                    {
                        case DATA_WINDRUNNER_COUNTER_ONE:
                            _eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN] = _eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 1 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_STRAIGHT;
                            break;
                        case DATA_WINDRUNNER_COUNTER_TWO:
                            _eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN] = _eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 3 ? DATA_DESECRATING_SHOT_PATTERN_WAVE : DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED;
                            break;
                        case DATA_WINDRUNNER_COUNTER_THREE:
                            _eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN] = _eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 5 ? DATA_DESECRATING_SHOT_PATTERN_SPIRAL : DATA_DESECRATING_SHOT_PATTERN_SCATTERED;
                            break;
                        case DATA_WINDRUNNER_COUNTER_FOUR:
                            _eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN] = _eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 7 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_JAR;
                            break;
                        case DATA_WINDRUNNER_COUNTER_FIVE:
                            _eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN] = 0;
                            break;
                        default:
                            break;
                    }

                    ChooseDesecratingShotPattern(_eventCounter[EVENT_COUNTER_DESECRATING_SHOT_PATTERN]);
                    break;
                }

                case EVENT_DESECRATING_SHOT_LAUNCH:
                {
                    TeleportShadowcopiesToMe();

                    switch (_eventCounter[EVENT_COUNTER_WINDRUNNER])
                    {
                        case DATA_WINDRUNNER_COUNTER_ONE:
                            StartDesecratingShotPattern(_eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 1 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_STRAIGHT);
                            break;
                        case DATA_WINDRUNNER_COUNTER_TWO:
                            StartDesecratingShotPattern(_eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 3 ? DATA_DESECRATING_SHOT_PATTERN_WAVE : DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED);
                            break;
                        case DATA_WINDRUNNER_COUNTER_THREE:
                            StartDesecratingShotPattern(_eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 5 ? DATA_DESECRATING_SHOT_PATTERN_SPIRAL : DATA_DESECRATING_SHOT_PATTERN_SCATTERED);
                            break;
                        case DATA_WINDRUNNER_COUNTER_FOUR:
                            StartDesecratingShotPattern(_eventCounter[EVENT_COUNTER_DESECRATING_SHOT] == 7 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_JAR);
                            break;
                        case DATA_WINDRUNNER_COUNTER_FIVE:
                            StartDesecratingShotPattern(0);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_DOMINATION_CHAINS:
                {
                    TeleportShadowcopiesToMe();
                    me->m_Events.KillAllEvents(true);
                    me->AddAura(SPELL_RANGER_BOW_STANCE, me);
                    if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                        shadowCopy->GetAI()->DoAction(ACTION_START_DOMINATION_CHAINS);
                    _eventCounter[EVENT_COUNTER_DOMINATION_CHAINS]++;
                    if (events.IsInPhase(PHASE_ONE))
                        events.Repeat(Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][1][_eventCounter[EVENT_COUNTER_DOMINATION_CHAINS]]));
                    break;
                }

                case EVENT_WAILING_ARROW_MARKER:
                {
                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                        {
                            scheduler.Schedule(Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][2][_eventCounter[EVENT_COUNTER_WAILING_ARROW_MARKER]]), [this](TaskContext /*task*/)
                            {
                                std::list<Player*> everyPlayerButCurrentTank;
                            GetPlayerListInGrid(everyPlayerButCurrentTank, me, 500.0f);

                            if (Unit* currentTank = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true, true))
                            {
                                _arrowTargetGUID = currentTank->GetGUID();

                                Talk(TALK_WAILING_ARROW_ANNOUNCE_AFFECTED, currentTank);

                                me->CastSpell(currentTank, SPELL_WAILING_ARROW_POINTER, true);

                                if (Player* currentTankToPlayer = currentTank->ToPlayer())
                                    everyPlayerButCurrentTank.remove(currentTankToPlayer);

                                if (events.IsInPhase(PHASE_ONE))
                                    for (Player* nonTank : everyPlayerButCurrentTank)
                                        Talk(TALK_WAILING_ARROW_ANNOUNCE, nonTank);

                                ++_eventCounter[EVENT_COUNTER_WAILING_ARROW_MARKER];
                            }
                            });
                            break;
                        }

                        case PHASE_THREE:
                        {
                            scheduler.Schedule(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][2][_eventCounter[EVENT_COUNTER_WAILING_ARROW_MARKER]]), [this](TaskContext /*task*/)
                            {
                                std::list<Player*> everyPlayerButCurrentTank;
                            GetPlayerListInGrid(everyPlayerButCurrentTank, me, 500.0f);

                            if (Unit* currentTank = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true, true))
                            {
                                _arrowTargetGUID = currentTank->GetGUID();

                                Talk(TALK_WAILING_ARROW_ANNOUNCE_AFFECTED, currentTank);

                                me->CastSpell(currentTank, SPELL_WAILING_ARROW_POINTER, true);

                                if (Player* currentTankToPlayer = currentTank->ToPlayer())
                                    everyPlayerButCurrentTank.remove(currentTankToPlayer);

                                if (events.IsInPhase(PHASE_ONE))
                                    for (Player* nonTank : everyPlayerButCurrentTank)
                                        Talk(TALK_WAILING_ARROW_ANNOUNCE, nonTank);

                                ++_eventCounter[EVENT_COUNTER_WAILING_ARROW_MARKER];
                            }
                            });
                            break;
                        }

                        default:
                            break;
                    }

                    break;
                }

                case EVENT_WAILING_ARROW:
                {
                    // Note: we must ensure Ranger Shot doesn't reset AttackTimer incorrectly.
                    me->m_Events.KillAllEvents(true);

                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                        {
                            Talk(TALK_WAILING_ARROW);

                            if (Player* target = ObjectAccessor::GetPlayer(*me, _arrowTargetGUID))
                                me->CastSpell(target, SPELL_WAILING_ARROW);
                            else
                                if (Unit* newTarget = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true))
                                    me->CastSpell(newTarget, SPELL_WAILING_ARROW);

                            me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false, true), me->m_Events.CalculateTime(4s + 484ms));

                            ++_eventCounter[EVENT_COUNTER_WAILING_ARROW];

                            events.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, Milliseconds(0), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            events.ScheduleEvent(EVENT_WAILING_ARROW, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][3][_eventCounter[EVENT_COUNTER_WAILING_ARROW]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        }

                        case PHASE_THREE:
                        {
                            Talk(TALK_WAILING_ARROW);

                            if (Player* target = ObjectAccessor::GetPlayer(*me, _arrowTargetGUID))
                                me->CastSpell(target, SPELL_WAILING_ARROW);
                            else
                                if (Unit* newTarget = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true))
                                    me->CastSpell(newTarget, SPELL_WAILING_ARROW);

                            me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false, true), me->m_Events.CalculateTime(3s));

                            ++_eventCounter[EVENT_COUNTER_WAILING_ARROW];

                            events.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, Milliseconds(0), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            events.ScheduleEvent(EVENT_WAILING_ARROW, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][3][_eventCounter[EVENT_COUNTER_WAILING_ARROW]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        }

                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS:
                {
                    // Note: we must ensure Ranger Shot doesn't reset AttackTimer incorrectly.
                    me->m_Events.KillAllEvents(true);
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(5ms));
                    Talk(TALK_VEIL_OF_DARKNESS_ANNOUNCE);

                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                            Talk(TALK_VEIL_OF_DARKNESS_PHASE_ONE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 1, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        case PHASE_TWO:
                            Talk(TALK_VEIL_OF_DARKNESS_PHASE_TWO_AND_THREE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 1, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            break;
                        case PHASE_THREE:
                            Talk(TALK_VEIL_OF_DARKNESS_PHASE_TWO_AND_THREE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 1, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS + 1:
                {
                    _eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]++;

                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][4][_eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 2, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        case PHASE_TWO:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_2_FADE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, Milliseconds(EventTimersPhaseTwo[SylvanasEventHelpers::GetDifficultyForTimer(me)][4][_eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 2, 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            break;
                        case PHASE_THREE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][4][_eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 2, 50ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS + 2:
                {
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 100.0f, me->GetOrientation());

                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 3, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        case PHASE_TWO:
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 3, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            break;
                        case PHASE_THREE:
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 3, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS + 3:
                {
                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 4, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        case PHASE_TWO:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
                                me->NearTeleportTo(target->GetPosition());
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 4, 250ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            break;
                        case PHASE_THREE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 4, 750ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS + 4:
                {
                    switch (SylvanasEventHelpers::GetWorldStatePhase(me))
                    {
                        case PHASE_ONE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 5, 1s, EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
                            break;
                        case PHASE_TWO:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_2_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 3000));
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_2);
                            if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                                shadowCopy->GetAI()->DoAction(ACTION_START_VEIL_OF_DARKNESS);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 5, 4s, EVENT_GROUP_NORMAL_EVENTS, PHASE_TWO);
                            break;
                        case PHASE_THREE:
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_3);
                            events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS + 5, 1s + 50ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS + 5:
                {
                    TeleportShadowcopiesToMe();
                    break;
                }

                case EVENT_RIVE:
                {
                    if (_eventCounter[EVENT_COUNTER_RIVE] < 8)
                    {
                        if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                            shadowCopy->NearTeleportTo(_selectedRivePos[_eventCounter[EVENT_COUNTER_RIVE]]);

                        if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                            shadowCopy2->NearTeleportTo(_selectedRivePos[_eventCounter[EVENT_COUNTER_RIVE]]);

                        if (Creature* shadowCopy3 = GetShadowcopy(instance, DATA_INDEX_03))
                            shadowCopy3->NearTeleportTo(_selectedRivePos[_eventCounter[EVENT_COUNTER_RIVE]]);

                        events.ScheduleEvent(EVENT_RIVE + 1, 600ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    }
                    else
                    {
                        for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                            {
                                shadowCopy->NearTeleportTo(me->GetPosition());

                                shadowCopy->GetAI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);
                            }
                        }

                        events.ScheduleEvent(EVENT_FINISH_INTERMISSION, 1s + 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    }
                    break;
                }

                case EVENT_RIVE + 1:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
                    {
                        _arrowTargetGUID = target->GetGUID();

                        if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                            shadowCopy->SetFacingToObject(target);

                        if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                            shadowCopy2->SetFacingToObject(target);

                        if (Creature* shadowCopy3 = GetShadowcopy(instance, DATA_INDEX_03))
                            shadowCopy3->SetFacingToObject(target);
                    }

                    events.ScheduleEvent(EVENT_RIVE + 2, 10ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;
                }

                case EVENT_RIVE + 2:
                    if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                        shadowCopy2->NearTeleportTo(shadowCopy2->GetPositionX(), shadowCopy2->GetPositionY(), 4105.00f, shadowCopy2->GetOrientation());
                    events.ScheduleEvent(EVENT_RIVE + 3, 10ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_RIVE + 3:
                    if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                        shadowCopy2->NearTeleportTo(shadowCopy2->GetNearPosition(24.4f, 0.0));
                    events.ScheduleEvent(EVENT_RIVE + 4, 10ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_RIVE + 4:
                {
                    DoCastSelf(SPELL_RIVE_DISAPPEAR, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 500));

                    if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                    {
                        me->SendPlayOrphanSpellVisual(shadowCopy2->GetPosition(), SPELL_VISUAL_WINDRUNNER_03, 0.25f, true, false);

                        if (Creature* shadowCopy1 = GetShadowcopy(instance, DATA_INDEX_01))
                        {
                            me->SetNameplateAttachToGUID(shadowCopy1->GetGUID());

                            shadowCopy1->CastSpell(shadowCopy2->GetPosition(), SPELL_DOMINATION_CHAINS_JUMP, true);
                        }
                    }
                    events.ScheduleEvent(EVENT_RIVE + 5, 10ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;
                }

                case EVENT_RIVE + 5:
                    if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                        me->NearTeleportTo(shadowCopy2->GetPosition());
                    DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
                    events.ScheduleEvent(EVENT_RIVE + 6, 10ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_RIVE + 6:
                {
                    if (Player* target = ObjectAccessor::GetPlayer(*me, _arrowTargetGUID))
                    {
                        if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                            shadowCopy->SetFacingToObject(target);

                        // HACKFIX: remove orientation when SPELL_ATTR12_UNK11 (Face Destination) is implemented.
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_RIVE + 7, 35ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    }
                    break;
                }

                case EVENT_RIVE + 7:
                {
                    scheduler.Schedule(445ms, [this](TaskContext /*task*/)
                    {
                        me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    });

                    if (_eventCounter[EVENT_COUNTER_RIVE] == 0 || _eventCounter[EVENT_COUNTER_RIVE] == 5)
                    {
                        DoCastSelf(SPELL_RIVE);

                        scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                        {
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK, 0, 0);
                        });

                        scheduler.Schedule(2s + 484ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                            me->CastSpell(me->GetNearPosition(9.0f, 0.0f), SPELL_RIVE_MARKER_AREATRIGGER, true);
                        });

                        events.ScheduleEvent(EVENT_RIVE, 4s + 500ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    }
                    else
                    {
                        DoCastSelf(SPELL_RIVE_FAST);

                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK_FAST, 0, 0);

                        if (Creature* shadowCopy2 = GetShadowcopy(instance, DATA_INDEX_02))
                            me->CastSpell(me->GetNearPosition(9.0f, 0.0f), SPELL_RIVE_MARKER_AREATRIGGER, true);

                        events.ScheduleEvent(EVENT_RIVE, 2s, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    }

                    _eventCounter[EVENT_COUNTER_RIVE]++;
                    break;
                }

                case EVENT_FINISH_INTERMISSION:
                    DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));
                    me->SendPlayOrphanSpellVisual(SylvanasIntermissionFinishPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                        shadowCopy->CastSpell(SylvanasIntermissionFinishPos, SPELL_DOMINATION_CHAINS_JUMP, true);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 1, 100ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 1:
                    if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                        me->SetNameplateAttachToGUID(shadowCopy->GetGUID());
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 2, 400ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 2:
                    me->NearTeleportTo(SylvanasIntermissionFinishPos);
                    me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 3, 1s + 200ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 3:
                    Talk(TALK_INTERMISSION_END);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 4, 700ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 4:
                    DoCastSelf(SPELL_BANSHEE_WAIL, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));
                    Talk(TALK_BANSHEE_WAIL_ANNOUNCE);
                    scheduler.Schedule(4s, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_BANSHEE, 0, 0);
                    });
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 5, 6s + 100ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 5:
                    instance->DoCastSpellOnPlayers(SPELL_INTERMISSION_SCENE_AND_STUN);
                    instance->DoCastSpellOnPlayers(SPELL_INTERMISSION_SCENE);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION + 6, 900ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_INTERMISSION);
                    break;

                case EVENT_FINISH_INTERMISSION + 6:
                    me->SendPlayOrphanSpellVisual(SylvanasPhase2PrePos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    me->NearTeleportTo(SylvanasPhase2PrePos);
                    break;

                case EVENT_BANE_ARROWS:
                {
                    DoCastSelf(SPELL_BANE_ARROWS);
                    events.Repeat(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][0][_eventCounter[EVENT_COUNTER_BANE_ARROWS]]));
                    break;
                }

                case EVENT_RAZE:
                {
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(0ms));

                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_DARK_FOG, 0, 0);

                    scheduler.Schedule(50ms, [this](TaskContext /*task*/)
                    {
                        me->CastSpell(SylvanasPositionHelpers::GetPointInCurrentPlatform(me, DATA_PLATFORM_MIDDLE_POINT), SPELL_RAZE);
                    });

                    events.Repeat(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][6][_eventCounter[EVENT_COUNTER_RAZE]]));
                    break;
                }

                case EVENT_BANSHEE_SCREAM:
                {
                    Talk(TALK_BANSHEE_SCREAM);
                    DoCastSelf(SPELL_BANSHEE_SCREAM);
                    events.Repeat(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][2][_eventCounter[EVENT_COUNTER_BANSHEE_SCREAM]]));
                    break;
                }

                case EVENT_BANSHEES_FURY:
                {
                    Talk(TALK_BANSHEES_FURY);

                    if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                        shadowCopy->NearTeleportTo(me->GetPosition());

                    me->m_Events.KillAllEvents(true);
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(0ms));

                    scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));

                    me->SendPlayOrphanSpellVisual(SylvanasPositionHelpers::GetPointInCurrentPlatform(me, DATA_PLATFORM_MIDDLE_POINT), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                    if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
                    {
                        me->SetNameplateAttachToGUID(shadowCopy->GetGUID());

                        shadowCopy->CastSpell(SylvanasPositionHelpers::GetPointInCurrentPlatform(me, DATA_PLATFORM_MIDDLE_POINT), SPELL_DOMINATION_CHAINS_JUMP);
                    }
                    });

                    scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                    {
                        me->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

                    for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
                        me->SetVirtualItem(virtualItem, 0);

                    me->NearTeleportTo(SylvanasPositionHelpers::GetPointInCurrentPlatform(me, DATA_PLATFORM_MIDDLE_POINT));

                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_TELEPORT, 0, 0);

                    me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    });

                    scheduler.Schedule(800ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* ridingCopy = me->FindNearestCreature(NPC_SYLVANAS_SHADOWCOPY_RIDING, 10.0f, true))
                        me->SetNameplateAttachToGUID(ridingCopy->GetGUID());
                    });

                    scheduler.Schedule(850ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_BANSHEES_FURY);

                    events.Repeat(Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][7][_eventCounter[EVENT_COUNTER_BANSHEES_FURY]]));
                    });

                    break;
                }

                case EVENT_SWITCH_PLATFORM:
                {
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 100.0f, me->GetOrientation());
                    events.ScheduleEvent(EVENT_SWITCH_PLATFORM + 1, 3s, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                    break;
                }

                case EVENT_SWITCH_PLATFORM + 1:
                {
                    for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
                    {
                        if (IsPlatformDesecrated(SylvanasPlatforms(platform)))
                            continue;

                        Position nextPlatformPos = CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM];

                        me->NearTeleportTo(nextPlatformPos.GetPositionX(), nextPlatformPos.GetPositionY(), nextPlatformPos.GetPositionZ(), nextPlatformPos.GetOrientation());

                        events.ScheduleEvent(EVENT_SWITCH_PLATFORM + 2, 16ms, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
                        break;
                    }
                    break;
                }

                case EVENT_SWITCH_PLATFORM + 2:
                {
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false, true), me->m_Events.CalculateTime(1s + 500ms));
                    me->CastSpell(me, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2750));
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SWITCH_PLATFORM, 0, 0);

                    std::list<Player*> targetList;
                    GetPlayerListInGrid(targetList, me, 5.0f);

                    for (Player* target : targetList)
                        target->AddAura(SPELL_STOMP_MOVEMENT_FORCE_AURA, target);
                    break;
                }

                case EVENT_SHADOW_DAGGER_TALK:
                    Talk(TALK_SHADOW_DAGGER);
                    break;

                case EVENT_DESECRATING_SHOT_LAUNCH_TALK:
                    Talk(TALK_DESECRATING_SHOT);
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoSylvanasAttackIfReady();
    }

    void DoSylvanasAttackIfReady()
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_WINDRUNNER) || me->HasReactState(REACT_PASSIVE))
            return;

        IncomingEventAndRangeCheck();

        if (me->isAttackReady(BASE_ATTACK))
        {
            switch (_eventCounter[EVENT_COUNTER_MELEE_COMBO])
            {
                case DATA_MELEE_COMBO_SWITCH_TO_MELEE:
                    DoCastSelf(SPELL_RANGER_DAGGERS_STANCE);
                    _eventCounter[EVENT_COUNTER_MELEE_COMBO]++;
                    break;

                case DATA_MELEE_COMBO_RANGER_STRIKE_01:
                    DoCastVictim(SPELL_RANGER_STRIKE);
                    if (roll_chance_i(70))
                        _eventCounter[EVENT_COUNTER_MELEE_COMBO]++;
                    else
                        _eventCounter[EVENT_COUNTER_MELEE_COMBO] = DATA_MELEE_COMBO_SWITCH_TO_RANGED;
                    break;

                case DATA_MELEE_COMBO_RANGER_STRIKE_02:
                    DoCastVictim(SPELL_RANGER_STRIKE);
                    _eventCounter[EVENT_COUNTER_MELEE_COMBO]++;
                    break;

                case DATA_MELEE_COMBO_SWITCH_TO_RANGED:
                    DoCastSelf(SPELL_RANGER_BOW_STANCE);
                    _eventCounter[EVENT_COUNTER_MELEE_COMBO]++;
                    break;

                case DATA_MELEE_COMBO_FINISH:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat, 0))
                    {
                        Aura* heartseekerAura = me->GetAura(SylvanasEventHelpers::GetWorldStatePhase(me) == PHASE_THREE ? SPELL_BANSHEE_HEARTSEEKER_CHARGE : SPELL_RANGER_HEARTSEEKER_CHARGE);

                        if (heartseekerAura && heartseekerAura->GetStackAmount() >= 3)
                            me->CastSpell(target, SylvanasEventHelpers::GetWorldStatePhase(me) == PHASE_THREE ? SPELL_BANSHEE_HEARTSEEKER : SPELL_RANGER_HEARTSEEKER, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 550));
                        else
                            me->CastSpell(target, SPELL_RANGER_SHOT);
                    }

                    if (roll_chance_i(65))
                        if (me->IsWithinCombatRange(me->GetVictim(), 4.0f))
                            DoAction(ACTION_RESET_MELEE_KIT);
                    break;
                }
                default:
                    break;
            }

            me->resetAttackTimer(BASE_ATTACK);
        }
    }

    void IncomingEventAndRangeCheck()
    {
        for (uint32 incomingEvents = EVENT_WINDRUNNER; incomingEvents < EVENT_SIZE_MAX; incomingEvents++)
        {
            if (incomingEvents != EVENT_WINDRUNNER && incomingEvents != EVENT_DOMINATION_CHAINS && incomingEvents != EVENT_VEIL_OF_DARKNESS)
                continue;

            if (events.GetTimeUntilEvent(incomingEvents) <= Milliseconds(500))
                _eventCounter[EVENT_COUNTER_MELEE_COMBO] = DATA_MELEE_COMBO_SWITCH_TO_RANGED;
            else
            {
                Aura* heartseekerAura = me->GetAura(SylvanasEventHelpers::GetWorldStatePhase(me) == PHASE_THREE ? SPELL_BANSHEE_HEARTSEEKER_CHARGE : SPELL_RANGER_HEARTSEEKER_CHARGE);
                if (heartseekerAura && heartseekerAura->GetStackAmount() >= 3)
                    _eventCounter[EVENT_COUNTER_MELEE_COMBO] = DATA_MELEE_COMBO_FINISH;
                else if (!me->IsWithinCombatRange(me->GetVictim(), 4.0f))
                {
                    if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                        _eventCounter[EVENT_COUNTER_MELEE_COMBO] = DATA_MELEE_COMBO_SWITCH_TO_RANGED;
                    else
                        _eventCounter[EVENT_COUNTER_MELEE_COMBO] = DATA_MELEE_COMBO_FINISH;
                }
            }
        }
    }

    void ChooseDesecratingShotPattern(uint8 pattern)
    {
        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            {
                int8 step = 1;

                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
                    while (step < 30 && DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_STRAIGHT, 0, step, me->GetPosition(), me->GetAbsoluteAngle(target)))
                        ++step;
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                int8 targetSize = std::max<uint8>(4, static_cast<uint8>(std::ceil(me->GetMap()->GetPlayersCountExceptGMs()) / 3));

                // TESTING: remove false and playerlist.
                std::list<Unit*> targets;
                SelectTargetList(targets, targetSize, SelectTargetMethod::Random, 0, 500.0f, false, true);

                for (Unit* target : targets)
                {
                    int8 step = 1;

                    while (step > 0 && DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_SCATTERED, targetSize, step, target->GetPosition(), target->GetOrientation()))
                        --step;
                }
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            {
                int8 copyIndex = 2;

                Position pos = me->GetPosition();

                float orientation = me->GetOrientation();

                for (uint8 i = 3; i > 0; --i)
                {
                    int8 step = 0;

                    Position convertedPos(pos.GetPosition());

                    switch (i)
                    {
                        case 1:
                            convertedPos.m_positionX += std::cos(orientation + float(M_PI)) * 9.999982f;
                            convertedPos.m_positionY += std::sin(orientation + float(M_PI)) * 9.999982f;
                            break;
                        case 2:
                            convertedPos.m_positionX += std::cos(orientation + float(M_PI)) * 5.000011f;
                            convertedPos.m_positionY += std::sin(orientation + float(M_PI)) * 5.000011f;
                            break;
                        default:
                            break;
                    }

                    while (step < 30 && DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_WAVE, copyIndex, step, convertedPos, orientation))
                        ++step;

                    --copyIndex;
                }
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED:
            {
                // TODO: remove false and playerlist, it's for testing.
                std::list<Unit*> targets;
                SelectTargetList(targets, 3, SelectTargetMethod::Random, 0, 500.0f, false, true);

                int8 copyIndex = 2;

                for (Unit* target : targets)
                {
                    int8 step = 10;

                    Position targetPos = target->GetPosition();

                    while (step > 0 && DrawDesecratingShotPattern(pattern == DATA_DESECRATING_SHOT_PATTERN_SPIRAL ? DATA_DESECRATING_SHOT_PATTERN_SPIRAL : DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED, copyIndex, step, targetPos, target->GetOrientation()))
                        --step;

                    --copyIndex;
                }
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
                break;

            default:
                break;
        }
    }

    bool DrawDesecratingShotPattern(uint8 pattern, int8 amount, int8 step, Position pos, float orientation)
    {
        std::vector<Position> arrowPositions;

        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            {
                float distance = 7.0f * step;

                Position arrowCenter(me->GetPositionX() + (std::cos(orientation) * distance), me->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

                if (IsArrowPositionValid(arrowCenter, step, 25))
                    arrowPositions.push_back(arrowCenter);

                Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * float(M_PI) / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * float(M_PI) / 180) * 2.8284f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowInnerLeft, step, 35))
                    arrowPositions.push_back(arrowInnerLeft);

                Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * float(M_PI) / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * float(M_PI) / 180) * 2.8284f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowInnerRight, step, 35))
                    arrowPositions.push_back(arrowInnerRight);

                Position arrowOuterLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * float(M_PI) / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * float(M_PI) / 180) * 5.6568f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowOuterLeft, step, 50))
                    arrowPositions.push_back(arrowOuterLeft);

                Position arrowOuterRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * float(M_PI) / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * float(M_PI) / 180) * 5.6568f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowOuterRight, step, 50))
                    arrowPositions.push_back(arrowOuterRight);

                // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                constexpr std::array<float, 5> travelSpeed = { 0.245000004768371f, 0.384000003337860f, 0.358999997377395f, 0.517000019550323f, 0.470999985933303f };

                for (uint8 i = 0; i < arrowPositions.size(); i++)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, DATA_INDEX_00))
                        shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed[i]);
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                Position arrowCenter(pos.GetPositionX() + (std::cos(orientation)), pos.GetPositionY() + (std::sin(orientation)), me->GetPositionZ());

                if (IsArrowPositionValid(arrowCenter, step, 5))
                    arrowPositions.push_back(arrowCenter);

                Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * float(M_PI) / 180) * 5.196156f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * float(M_PI) / 180) * 5.196156f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowInnerLeft, step, 500))
                    arrowPositions.push_back(arrowInnerLeft);

                Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * float(M_PI) / 180) * 5.196156f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * float(M_PI) / 180) * 5.196156f), arrowCenter.GetPositionZ());

                if (IsArrowPositionValid(arrowInnerRight, step, 1000))
                    arrowPositions.push_back(arrowInnerRight);

                // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                constexpr std::array<float, 3> travelSpeed = { 0.245000004768371f, 0.384000003337860f, 0.470999985933303f };

                for (uint8 i = 0; i < arrowPositions.size(); i++)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, DATA_INDEX_00))
                        shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed[i]);
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            {
                float pointDistance = 3.999978f * step;

                uint32 additionalMilliseconds = step <= 1 ? step + 5 : step + 15;

                if (step == 0)
                {
                    // Note: amount refers to DATA_INDEX_NUMBER passed for GetShadowcopyCastAI();
                    if (amount == 2)
                    {
                        if (SylvanasFirstPhasePlatformCenter.IsInDist2d(&pos, PLATFORM_RADIUS))
                        {
                            arrowPositions.push_back(pos);

                            me->CastSpell(pos, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                        }
                    }
                    else if (amount == 1)
                    {
                        if (SylvanasFirstPhasePlatformCenter.IsInDist2d(&pos, PLATFORM_RADIUS))
                        {
                            arrowPositions.push_back(pos);

                            scheduler.Schedule(47ms, [this, pos](TaskContext /*task*/)
                            {
                                me->CastSpell(pos, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                            });
                        }
                    }
                    else
                    {
                        if (SylvanasFirstPhasePlatformCenter.IsInDist2d(&pos, PLATFORM_RADIUS))
                        {
                            arrowPositions.push_back(pos);

                            scheduler.Schedule(78ms, [this, pos](TaskContext /*task*/)
                            {
                                me->CastSpell(pos, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                            });
                        }
                    }
                }
                else
                {
                    if (amount == 2)
                    {
                        Position rightLineFront(pos.GetPositionX() + (std::cos(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(rightLineFront, 50, additionalMilliseconds))
                            arrowPositions.push_back(rightLineFront);

                        Position rightLineBack(pos.GetPositionX() + (std::cos(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(rightLineBack, 50, additionalMilliseconds))
                            arrowPositions.push_back(rightLineBack);
                    }
                    else if (amount == 1)
                    {
                        Position middleLineFront(pos.GetPositionX() + (std::cos(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(middleLineFront, 60, additionalMilliseconds))
                            arrowPositions.push_back(middleLineFront);

                        Position middleLineBack(pos.GetPositionX() + (std::cos(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(middleLineBack, 60, additionalMilliseconds))
                            arrowPositions.push_back(middleLineBack);
                    }
                    else
                    {
                        Position leftLineFront(pos.GetPositionX() + (std::cos(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + 90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(leftLineFront, 70, additionalMilliseconds))
                            arrowPositions.push_back(leftLineFront);

                        Position leftLineBack(pos.GetPositionX() + (std::cos(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionY() + (std::sin(orientation + -90.0f * float(M_PI) / 180) * pointDistance), pos.GetPositionZ());

                        if (IsArrowPositionValid(leftLineBack, 70, additionalMilliseconds))
                            arrowPositions.push_back(leftLineBack);
                    }
                }

                // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                float travelSpeed = 0.245000004768371f;

                for (uint8 i = 0; i < arrowPositions.size(); ++i)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, amount))
                        shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed + float(travelSpeed * (step * 0.025)));
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED:
            {
                float distance = pattern == DATA_DESECRATING_SHOT_PATTERN_SPIRAL ? DesecratingShotNormalSpiralDistance[step - 1] : DesecratingShotSpiralEnclosedDistance[step - 1];

                if (step != 1)
                {
                    Position spiralLeft(pos.GetPositionX() + (std::cos((orientation + 120.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionY() + (std::sin((orientation + 120.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionZ());

                    if (IsArrowPositionValid(spiralLeft, step, 24))
                        arrowPositions.push_back(spiralLeft);

                    Position spiralRight(pos.GetPositionX() + (std::cos((orientation + 240.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionY() + (std::sin((orientation + 240.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionZ());

                    if (IsArrowPositionValid(spiralRight, step, 24))
                        arrowPositions.push_back(spiralRight);

                    Position spiralFront(pos.GetPositionX() + (std::cos((orientation + 360.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionY() + (std::sin((orientation + 360.0f + float(10 * step)) * float(M_PI) / 180) * distance), pos.GetPositionZ());

                    if (IsArrowPositionValid(spiralFront, step, 24))
                        arrowPositions.push_back(spiralFront);
                }
                else
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, amount))
                    {
                        shadowCopyAI->StoreDesecratingShots(pos, 0, 0.165999993681907653);

                        scheduler.Schedule(Milliseconds(step * 16), [this, pos](TaskContext /*task*/)
                        {
                            me->CastSpell(pos, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                        });
                    }
                }

                // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                float travelSpeed = 0.245000004768371f;

                for (uint8 i = 0; i < arrowPositions.size(); ++i)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, amount))
                        shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed + float(travelSpeed * (step * 0.1)));
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
                return true;

            default:
                break;
        }

        return true;
    }

    bool IsArrowPositionValid(Position arrowPosition, uint8 step, uint32 additionalMilliseconds)
    {
        if (SylvanasFirstPhasePlatformCenter.IsInDist2d(&arrowPosition, PLATFORM_RADIUS))
        {
            scheduler.Schedule(Milliseconds(step * additionalMilliseconds), [this, arrowPosition](TaskContext /*task*/)
            {
                me->CastSpell(arrowPosition, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            });

            return true;
        }

        return false;
    }

    void StartDesecratingShotPattern(uint8 pattern)
    {
        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, DATA_INDEX_00))
                    shadowCopyAI->StartDesecratingShotEvent(pattern, 0);
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL_ENCLOSED:
            {
                if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = GetShadowcopyCastAI(instance, DATA_INDEX_02))
                    shadowCopy2AI->StartDesecratingShotEvent(pattern, 2);

                scheduler.Schedule(300ms, [this, pattern](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = GetShadowcopyCastAI(instance, DATA_INDEX_01))
                    shadowCopy1AI->StartDesecratingShotEvent(pattern, 1);
                });

                scheduler.Schedule(600ms, [this, pattern](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, DATA_INDEX_00))
                    shadowCopyAI->StartDesecratingShotEvent(pattern, 0);
                });
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
            {
                break;
            }

            default:
                break;
        }
    }

    void HandlePhaseOne()
    {
        events.SetPhase(PHASE_ONE);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.ScheduleEvent(EVENT_WINDRUNNER, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][0][_eventCounter[EVENT_COUNTER_WINDRUNNER]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
        events.ScheduleEvent(EVENT_DOMINATION_CHAINS, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][1][_eventCounter[EVENT_COUNTER_DOMINATION_CHAINS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
        events.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, Milliseconds(0), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
        events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][4][_eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);

        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            events.ScheduleEvent(EVENT_BLACK_ARROW, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][3][_eventCounter[EVENT_COUNTER_BLACK_ARROW]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
        else
            events.ScheduleEvent(EVENT_WAILING_ARROW, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][3][_eventCounter[EVENT_COUNTER_WAILING_ARROW]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
    }

    void HandlePhaseIntermission()
    {
        events.SetPhase(PHASE_INTERMISSION);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_INTERMISSION_WORLD_STATE);

        for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                shadowCopy->GetAI()->DoAction(ACTION_PREPARE_INTERMISSION);
    }

    void HandlePhaseTwo()
    {
        events.SetPhase(PHASE_TWO);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_TWO);

        // Note: we need to reset the counters since these are used in other phases.
        _eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS] = 0;

        for (ObjectGuid const& shadowCopiesGUID : _shadowCopyGUID)
        {
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, shadowCopiesGUID))
                shadowCopy->GetAI()->DoAction(ACTION_START_PHASE_TWO);
        }
    }

    void HandlePhaseThree()
    {
        events.SetPhase(PHASE_THREE);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_THREE);

        // Note: we need to reset the counters since these are used in other phases.
        _eventCounter[EVENT_COUNTER_WAILING_ARROW_MARKER] = 0;
        _eventCounter[EVENT_COUNTER_WAILING_ARROW] = 0;
        _eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS] = 0;

        events.ScheduleEvent(EVENT_BANE_ARROWS, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][0][_eventCounter[EVENT_COUNTER_BANE_ARROWS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_SHADOW_DAGGER, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][1][_eventCounter[EVENT_COUNTER_SHADOW_DAGGER]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, Milliseconds(0), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_WAILING_ARROW, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][3][_eventCounter[EVENT_COUNTER_WAILING_ARROW]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][4][_eventCounter[EVENT_COUNTER_VEIL_OF_DARKNESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_BANSHEE_SCREAM, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][5][_eventCounter[EVENT_COUNTER_BANSHEE_SCREAM]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_RAZE, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][6][_eventCounter[EVENT_COUNTER_RAZE]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);
        events.ScheduleEvent(EVENT_WITHERING_FIRE, 25s, EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);

        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            events.ScheduleEvent(EVENT_BANSHEES_FURY, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][7][_eventCounter[EVENT_COUNTER_BANSHEES_FURY]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);

        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            events.ScheduleEvent(EVENT_MERCILESS, Milliseconds(EventTimersPhaseThree[SylvanasEventHelpers::GetDifficultyForTimer(me)][8][_eventCounter[EVENT_COUNTER_MERCILESS]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_THREE);

        for (ObjectGuid const& shadowCopiesGUID : _shadowCopyGUID)
        {
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, shadowCopiesGUID))
                shadowCopy->GetAI()->DoAction(ACTION_START_PHASE_THREE);
        }
    }

    void HandleWindrunner()
    {
        // Note: any Windrunner from fifth cast is always the same.
        if (_eventCounter[EVENT_COUNTER_WINDRUNNER] < 5)
            _eventCounter[EVENT_COUNTER_WINDRUNNER]++;

        ScheduleWindrunnerTexts();

        // Note: first cast is 11s and every following cast has 2 additional seconds.
        uint32 newDuration = 9000 + uint32(2000 * _eventCounter[EVENT_COUNTER_WINDRUNNER]);

        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, newDuration));

        switch (_eventCounter[EVENT_COUNTER_WINDRUNNER])
        {
            case DATA_WINDRUNNER_COUNTER_ONE:
            {
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_SHADOW_DAGGER, 3s + 141ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 5s + 797ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 7s + 750ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s + 200ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 10s + 391ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;
            }

            case DATA_WINDRUNNER_COUNTER_TWO:
            {
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_SHADOW_DAGGER, 3s + 31ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 31ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 6s + 31ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 8s + 422ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s + 422ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 11s + 156ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;
            }

            case DATA_WINDRUNNER_COUNTER_THREE:
            {
                events.ScheduleEvent(EVENT_SHADOW_DAGGER, 1ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 2s + 750ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 5s + 438ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_SHADOW_DAGGER, 8s + 594ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 9s, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 11s + 219ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 13s + 78ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;
            }

            case DATA_WINDRUNNER_COUNTER_FOUR:
            {
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_SHADOW_DAGGER, 500ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 5ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_WITHERING_FIRE, 5ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;
            }

            case DATA_WINDRUNNER_COUNTER_FIVE:
            {
                break;
            }

            default:
                break;
        }

        events.ScheduleEvent(EVENT_WINDRUNNER, Milliseconds(EventTimersPhaseOne[SylvanasEventHelpers::GetDifficultyForTimer(me)][0][_eventCounter[EVENT_COUNTER_WINDRUNNER]]), EVENT_GROUP_NORMAL_EVENTS, PHASE_ONE);
    }

    void ScheduleWindrunnerTexts()
    {
        switch (_eventCounter[EVENT_COUNTER_WINDRUNNER])
        {
            case DATA_WINDRUNNER_COUNTER_ONE:
                events.ScheduleEvent(EVENT_SHADOW_DAGGER_TALK, 3s + 501ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH_TALK, 10s + 491ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;

            case DATA_WINDRUNNER_COUNTER_TWO:
                events.ScheduleEvent(EVENT_SHADOW_DAGGER_TALK, 3s + 391ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH_TALK, 11s + 256ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;

            case DATA_WINDRUNNER_COUNTER_THREE:
                events.ScheduleEvent(EVENT_SHADOW_DAGGER_TALK, 361ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH_TALK, 11s + 319ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;

            case DATA_WINDRUNNER_COUNTER_FOUR:
                events.ScheduleEvent(EVENT_SHADOW_DAGGER_TALK, 860ms, EVENT_GROUP_WINDRUNNER_EVENTS, PHASE_ONE);
                break;

            case DATA_WINDRUNNER_COUNTER_FIVE:
                break;

            default:
                break;
        }
    }

    void TeleportShadowcopiesToMe()
    {
        for (ObjectGuid const& shadowCopiesGUID : _shadowCopyGUID)
        {
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, shadowCopiesGUID))
                shadowCopy->NearTeleportTo(me->GetPosition());
        }
    }

    void CleanUpEncounter()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BARBED_ARROW);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANSHEE_MARK);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_CHAIN_PLAYER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_CHAIN_PERIODIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VEIL_OF_DARKNESS_ABSORB_AURA);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PLATFORMS_SCENE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANSHEES_BANE);
    }

    void DesecratePlatform(SylvanasPlatforms platformIndex)
    {
        _desecratedPlatforms |= (1 << platformIndex);

        std::vector<ObjectGuid> invigoratingFieldToDesecrateGUID;

        switch (platformIndex)
        {
            case PLATFORM_MALDRAXXI:
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[0]);
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[1]);
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[2]);
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[7]);
                break;

            case PLATFORM_NIGHTFAE:
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[3]);
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[4]);
                break;

            case PLATFORM_KYRIAN:
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[5]);
                invigoratingFieldToDesecrateGUID.push_back(_invigoratingFieldGUID[6]);
                break;

            default:
                break;
        }

        for (ObjectGuid const& invigoratingFieldGUID : invigoratingFieldToDesecrateGUID)
        {
            if (AreaTrigger* invigoratingField = ObjectAccessor::GetAreaTrigger(*me, invigoratingFieldGUID))
                invigoratingField->Remove();
        }
    }

    bool IsPlatformDesecrated(SylvanasPlatforms platformIndex)
    {
        return _desecratedPlatforms & (1 << platformIndex);
    }

private:
    std::array<uint8, EVENT_COUNTER_MAX> _eventCounter = { };
    std::vector<Position> _selectedRivePos;
    std::vector<ObjectGuid> _shadowCopyGUID;
    std::vector<ObjectGuid> _invigoratingFieldGUID;
    ObjectGuid _arrowTargetGUID;
    time_t _lastSlayTalk = 0;
    uint8 _ruinInterrupted = 0;
    uint8 _desecratedPlatforms;
};

// 176920 - Domination Arrow
struct npc_sylvanas_windrunner_domination_arrow : public ScriptedAI
{
    npc_sylvanas_windrunner_domination_arrow(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoZoneInCombat();

        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_DOMINATION_ARROW:
            {
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

                me->RemoveAura(SPELL_DOMINATION_ARROW_CALAMITY_VISUAL);

                DoCastSelf(SPELL_DOMINATION_ARROW_ACTIVATE, true);

                // TODO: the target check should prioritize players at the MinDistance with no SPELL_DOMINATION_CHAIN_PLAYER.
                // If the condition cannot be met, it should choose people with the least amounts of SPELL_DOMINATION_CHAIN_PLAYER.
                // Why? Intermission can trigger right after Domination Chains, and every new Domination Chain chooses even the ones already affected.
                if (Unit* target = SelectTarget(SelectTargetMethod::MinDistance, 0, 500.0f, true, true, -SPELL_DOMINATION_CHAIN_PLAYER))
                {
                    _playerGUID = target->GetGUID();

                    me->CastSpell(target, SPELL_DOMINATION_CHAIN_PLAYER);

                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                        target->CastSpell(me, SPELL_DOMINATION_ARROW_CALAMITY_AREATRIGGER, true);
                }
                break;
            }

            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Player* chainedPlayer = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            if (chainedPlayer->HasAura(SPELL_DOMINATION_CHAIN_PLAYER, me->GetGUID()))
                chainedPlayer->RemoveAura(SPELL_DOMINATION_CHAIN_PLAYER);
        }
    }

private:
    InstanceScript* _instance;
    ObjectGuid _playerGUID;
};

// 347560 - Ranger (Bow)
class spell_sylvanas_windrunner_ranger_bow : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT, SPELL_RANGER_DAGGERS_STANCE });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();

        caster->RemoveAura(SPELL_RANGER_DAGGERS_STANCE);

        caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1600));

        caster->SendPlaySpellVisualKit(RAND(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW, SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN), 0, 0);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(16ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_RANGED, 0), caster->m_Events.CalculateTime(359ms));

        if (caster->IsInCombat())
            caster->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(caster, false, true), caster->m_Events.CalculateTime(859ms));
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_sylvanas_windrunner_ranger_bow::HandleOnCast);
    }
};

class spell_sylvanas_windrunner_ranger_bow_aura : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetTarget(), DATA_CHANGE_ATTACK_SPEED_TO_HIGHEST, 0), GetTarget()->m_Events.CalculateTime(0ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_ranger_bow_aura::OnApply, EFFECT_0, SPELL_AURA_ANIM_REPLACEMENT_SET, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 348010 - Ranger (Dagger)
class spell_sylvanas_windrunner_ranger_dagger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RANGER_BOW_STANCE });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();

        caster->RemoveAura(SPELL_RANGER_BOW_STANCE);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_ATTACK_SPEED_TO_LOWEST, 0), caster->m_Events.CalculateTime(0ms));

        caster->SendPlaySpellVisualKit(RAND(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS, SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN), 0, 0);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(16ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_MELEE, 0), caster->m_Events.CalculateTime(281ms));

        if (caster->IsInCombat())
            caster->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(caster, false, true), caster->m_Events.CalculateTime(828ms));
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_sylvanas_windrunner_ranger_dagger::HandleOnCast);
    }
};

// 347548 - Ranger Shot
class spell_sylvanas_windrunner_ranger_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(GetCaster(), false, true), GetCaster()->m_Events.CalculateTime(1750ms));

        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));
    }

    void Register() override { }
};

// 348299 - Ranger Strike
class spell_sylvanas_windrunner_ranger_strike : public SpellScript
{
    void HandleLaunchTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->SendPlaySpellVisual(GetHitUnit(), RAND(SPELL_VISUAL_RANGER_STRIKE_RIGHT, SPELL_VISUAL_RANGER_STRIKE_LEFT,
            SPELL_VISUAL_RANGER_STRIKE_FAST_RIGHT, SPELL_VISUAL_RANGER_STRIKE_FAST_LEFT), 0, 0, 1.0f, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_strike::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

// 347504 - Windrunner
class spell_sylvanas_windrunner_windrunner : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->setAttackTimer(WeaponAttackType::BASE_ATTACK, 500);

        target->GetAI()->DoAction(ACTION_RESET_MELEE_KIT);

        target->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(target, false, true), target->m_Events.CalculateTime(500ms));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_windrunner::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352303 - Windrunner (Disappear 01)
// 358975 - Windrunner (Disappear 02)
class spell_sylvanas_windrunner_disappear : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (GetSpellInfo()->Id == SPELL_WINDRUNNER_DISAPPEAR_02)
        {
            if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyCastAI(instance, DATA_INDEX_00))
            {
                if (SylvanasEventHelpers::GetWorldStatePhase(target) == PHASE_ONE || shadowCopyAI->GetData(DATA_EVENT_TYPE_SHADOWCOPY) == DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT)
                    target->CastSpell(target, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3600));
                else if (SylvanasEventHelpers::GetWorldStatePhase(target) == PHASE_THREE)
                    target->CastSpell(target, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4280));
                else
                    target->CastSpell(target, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1750));
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_disappear::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347928 - Withering Fire
class spell_sylvanas_windrunner_withering_fire : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (SylvanasEventHelpers::GetWorldStatePhase(GetCaster()) == PHASE_ONE)
                sylvanas->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_withering_fire::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 348627 - Desecrating Shot
class spell_sylvanas_windrunner_desecrating_shot : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_desecrating_shot::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 352663 - Ranger's Heartseeker
// 353969 - Banshee's Heartseeker
class spell_sylvanas_windrunner_heartseeker : public SpellScript
{
    class HeartseekerDamageEvent : public BasicEvent
    {
    public:
        HeartseekerDamageEvent(Unit* actor, Unit* victim) : _actor(actor), _victim(victim) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_victim, SylvanasEventHelpers::GetWorldStatePhase(_actor) == PHASE_THREE ? SPELL_BANSHEE_HEARTSEEKER_PHYSICAL_DAMAGE : SPELL_RANGER_HEARTSEEKER_PHYSICAL_DAMAGE, true);
            _actor->CastSpell(_victim, SylvanasEventHelpers::GetWorldStatePhase(_actor) == PHASE_THREE ? SPELL_BANSHEE_HEARTSEEKER_SHADOW_DAMAGE : SPELL_RANGER_HEARTSEEKER_SHADOW_DAMAGE, true);

            return true;
        }

private:
        Unit* _actor;
        Unit* _victim;
    };

    class HeartseekerMissileEvent : public BasicEvent
    {
    public:
        HeartseekerMissileEvent(Unit* actor, Unit* victim) : _actor(actor), _victim(victim) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->SendPlaySpellVisual(_victim, SPELL_VISUAL_HEARTSEEKER, 0, 0, 36.0f, false);

            uint32 timer = uint32(_actor->GetDistance(_victim) * 0.0277 * 1000);

            if (Aura* heartseeker = _actor->GetAura(_actor->GetAreaId() == AREA_PINNACLE_OF_DOMINANCE ? SPELL_RANGER_HEARTSEEKER_CHARGE : SPELL_BANSHEE_HEARTSEEKER_CHARGE))
                heartseeker->ModStackAmount(-1, AuraRemoveMode::AURA_REMOVE_BY_DEFAULT);

            _actor->m_Events.AddEvent(new HeartseekerDamageEvent(_actor, _victim), _actor->m_Events.CalculateTime(Milliseconds(timer)));

            return true;
        }

private:
        Unit* _actor;
        Unit* _victim;
    };

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_RANGER_BOW_STANCE, SPELL_SYLVANAS_ROOT });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();

        // Note: according to sniff, there's only a SMSG_AURA_UPDATE sent after SMSG_SPELL_START. There's no SMSG_SPELL_START or SMSG_SPELL_GO for this case.
        caster->AddAura(SPELL_RANGER_BOW_STANCE, caster);

        caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3750));

        if (Unit* victim = caster->GetVictim())
            caster->SetInFront(victim);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(31ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_RANGED, 0), caster->m_Events.CalculateTime(297ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), caster->m_Events.CalculateTime(406ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), caster->m_Events.CalculateTime(1s + 953ms));

        caster->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(caster, false, true), caster->m_Events.CalculateTime(2s + 984ms));
    }

    void HandleMissiles(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        caster->SetInFront(target);

        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, target), caster->m_Events.CalculateTime(0ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, target), caster->m_Events.CalculateTime(265ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, target), caster->m_Events.CalculateTime(562ms));
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_heartseeker::HandleMissiles, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 352652 - Ranger's Heartseeker (Shadow damage)
class spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BANSHEE_MARK });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_MARK, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 353967 - Banshees's Heartseeker (Shadow damage)
class spell_sylvanas_windrunner_banshee_heartseeker_shadow_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BANSHEES_BANE });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEES_BANE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_heartseeker_shadow_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 349419 - Domination Chains
class spell_sylvanas_windrunner_domination_chains : public SpellScript
{
    void OnCast(SpellMissInfo /*missInfo*/)
    {
        GetCaster()->GetAI()->DoAction(ACTION_RESET_MELEE_KIT);

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_DOMINATION_CHAINS_FINISH, 0, 0);
    }

    void HandleAfterCast()
    {
        if (!GetCaster())
            return;

        std::list<Creature*> arrowList;
        GetCreatureListWithEntryInGrid(arrowList, GetCaster(), NPC_DOMINATION_ARROW, 500.0f);

        for (Creature* arrow : arrowList)
            arrow->GetAI()->DoAction(ACTION_ACTIVATE_DOMINATION_ARROW);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_domination_chains::OnCast);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_domination_chains::HandleAfterCast);
    }
};

// 352317 - Domination Arrow (Fall)
// 352319 - Domination Arrow (Fall and Spawn)
class spell_sylvanas_windrunner_domination_arrow : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_domination_arrow::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 349451 - Domination Chain (Player)
class spell_sylvanas_windrunner_domination_chain : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BARBED_ARROW, SPELL_DOMINATION_CHAIN_PERIODIC });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        _playerGUID = GetTarget()->GetGUID();

        GetTarget()->RemoveAura(SPELL_BARBED_ARROW);

        sylvanas->CastSpell(GetTarget(), SPELL_DOMINATION_CHAIN_PERIODIC, true);

        _arrowAreaTriggerGUID = AreaTrigger::CreateNewMovementForceId(caster->GetMap(), DATA_AREATRIGGER_DOMINATION_ARROW);

        GetTarget()->ApplyMovementForce(_arrowAreaTriggerGUID, caster->GetPosition(), 3.20000004768371582f, MovementForceType::Gravity);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DOMINATION_CHAIN_PERIODIC);

        GetTarget()->RemoveMovementForce(_arrowAreaTriggerGUID);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_domination_chain::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_domination_chain::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    ObjectGuid _playerGUID;
    ObjectGuid _arrowAreaTriggerGUID;
};

// 349458 - Domination Chain (Periodic)
class spell_sylvanas_windrunner_domination_chain_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINATION_CHAIN_PERIODIC });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (aurEff->GetTickNumber() == 3)
            caster->CastSpell(GetTarget(), SPELL_DOMINATION_CHAIN_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_domination_chain_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 347609 - Wailing Arrow
class spell_sylvanas_windrunner_wailing_arrow : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    int32 CalcCastTime(int32 castTime) override
    {
        if (SylvanasEventHelpers::GetWorldStatePhase(GetCaster()) == PHASE_THREE)
            return 1500;

        return castTime;
    }

    void OnPrecast() override
    {
        if (SylvanasEventHelpers::GetWorldStatePhase(GetCaster()) == PHASE_ONE)
        {
            GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), GetCaster()->m_Events.CalculateTime(1s + 531ms));
            GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), GetCaster()->m_Events.CalculateTime(3s + 331ms));
        }
    }

    void HandleLaunchTarget(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 348056 - Wailing Arrow (Trigger)
class spell_sylvanas_windrunner_wailing_arrow_trigger : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_trigger::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 357618 - Wailing Arrow (Raid damage)
class spell_sylvanas_windrunner_wailing_arrow_raid_damage : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        // Note: this is completely based off research on different sniffs. The reduction might be inaccurate, but it's pretty close to Blizzard's.
        int32 damage = GetHitDamage();

        float distanceDmgMod = GetCaster()->GetExactDist2d(GetHitUnit()) / 4.5f;

        if (distanceDmgMod < 1.0f)
            return;

        damage /= uint32(distanceDmgMod);

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_raid_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 352470 - Veil of Darkness (Fade - Phase 1)
// 353273 - Veil of Darkness (Fade - Phase 2)
// 354168 - Veil of Darkness (Fade - Phase 3)
class spell_sylvanas_windrunner_veil_of_darkness_fade : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_SYLVANAS_ROOT,
            SPELL_VEIL_OF_DARKNESS_DESELECT,
            SPELL_VEIL_OF_DARKNESS_SCREEN_FOG
        });
    }

    void OnPrecast() override
    {
        uint32 duration = 0;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE:
                duration = 9750;
                break;
            case SPELL_VEIL_OF_DARKNESS_PHASE_2_FADE:
                duration = 7750;
                break;
            case SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE:
                duration = 5750;
                break;
            default:
                break;
        }

        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, duration));
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        instance->DoCastSpellOnPlayers(SPELL_VEIL_OF_DARKNESS_SCREEN_FOG);

        GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_DARKNESS_DESELECT, true);
        GetCaster()->SetPower(GetCaster()->GetPowerType(), 0);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_veil_of_darkness_fade::OnCast);
    }
};

// 350335 - Veil of Darkness (Grow - Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1 : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);
        target->SetHover(true);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), target->m_Events.CalculateTime(0ms));

        // TODO: on mythic it prefers rangers. There's some posibility is chooses the biggest clump of rangers instead.
        if (Unit* darknessTarget = target->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
        {
            Position darknessTargetPos(darknessTarget->GetPositionX(), darknessTarget->GetPositionY(), darknessTarget->GetPositionZ());

            uint32 spellVisual = 0;

            switch (target->GetMap()->GetDifficultyID())
            {
                case DIFFICULTY_HEROIC_RAID:
                    spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_HC;
                    break;
                case DIFFICULTY_MYTHIC_RAID:
                    spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_MM;
                    break;
                default:
                    spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_ONE_LFR_AND_NM;
                    break;
            }

            target->SendPlayOrphanSpellVisual(Position(darknessTargetPos.GetPositionX(), darknessTargetPos.GetPositionY(), darknessTargetPos.GetPositionZ() + 0.05f), spellVisual, 5.0f, true, false);

            target->NearTeleportTo(darknessTargetPos);
        }

        target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_ONE, 0, 0);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);
        target->SetHover(false);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);

        target->SetVirtualItem(0, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(1, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(2, DATA_DISPLAY_ID_SYLVANAS_BOW);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), target->m_Events.CalculateTime(0ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347726 - Veil of Darkness (Cast - Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_phase_1 : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    int32 CalcCastTime(int32 castTime) override
    {
        if (SylvanasEventHelpers::GetWorldStatePhase(GetCaster()) == PHASE_ONE)
            return 4000;

        return castTime;
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void HandleAfterCast()
    {
        GetCaster()->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(GetCaster(), false, true), GetCaster()->m_Events.CalculateTime(1s + 985ms));

        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3750));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleAfterCast);
    }
};

// 350777 - Veil of Darkness (Damage)
class spell_sylvanas_windrunner_veil_of_darkness_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VEIL_OF_DARKNESS_ABSORB_AURA })
            && ValidateSpellEffect({ { SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, EFFECT_4 } });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (caster->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID || caster->GetMap()->GetDifficultyID() != DIFFICULTY_HEROIC_RAID)
            return;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, GetCastDifficulty());

        uint8 stackAmount = spellInfo->GetEffect(EFFECT_4).CalcValue() - 1;

        for (stackAmount; stackAmount > 0; stackAmount--)
            caster->CastSpell(GetHitUnit(), SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 355749 - Veil of Darkness (Periodic)
class spell_sylvanas_windrunner_veil_of_darkness_periodic : public AuraScript
{
    class VeilOfDarknessSpreadEvent : public BasicEvent
    {
    public:
        VeilOfDarknessSpreadEvent(Unit* actor, Unit* target) : _actor(actor), _target(target) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (Creature* sylvanas = _actor->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                sylvanas->CastSpell(_target, SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, true);
            return true;
        }

private:
        Unit* _actor;
        Unit* _target;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VEIL_OF_DARKNESS_ABSORB_AURA })
            && ValidateSpellEffect({ { SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, EFFECT_0 }, { SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, EFFECT_3 } });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Aura* veilOfDarknessDebuff = target->GetAura(SPELL_VEIL_OF_DARKNESS_ABSORB_AURA);
        if (!veilOfDarknessDebuff || veilOfDarknessDebuff->GetStackAmount() == 1)
            return;

        float radius = veilOfDarknessDebuff->GetSpellInfo()->GetEffect(EFFECT_3).CalcValue();
        uint8 targetSize = veilOfDarknessDebuff->GetSpellInfo()->GetEffect(EFFECT_0).CalcValue();

        std::list<Player*> playerList;
        target->GetPlayerListInGrid(playerList, radius);
        playerList.resize(targetSize);

        for (Player* spreadTarget : playerList)
        {
            target->SendPlaySpellVisual(spreadTarget, SPELL_VISUAL_VEIL_OF_DARKNESS_SPREAD, 0, 0, 0.60f, true);
            target->m_Events.AddEvent(new VeilOfDarknessSpreadEvent(target, spreadTarget), target->m_Events.CalculateTime(600ms));
        }

        veilOfDarknessDebuff->ModStackAmount(veilOfDarknessDebuff->GetStackAmount() - targetSize);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_veil_of_darkness_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 347704 - Veil of Darkness (Absorb)
class spell_sylvanas_windrunner_veil_of_darkness_debuff : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VEIL_OF_DARKNESS_VISUAL_DUMMY });
    }

    void OnHealAbsorb(AuraEffect* /*aurEff*/, HealInfo& healInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(healInfo.GetHeal(), GetEffectInfo(EFFECT_2).CalcValue());
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID && GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_HEROIC_RAID)
            return;

        if (GetStackAmount() == 1)
            GetTarget()->RemoveAurasDueToSpell(SPELL_VEIL_OF_DARKNESS_VISUAL_DUMMY);
    }

    void Register() override
    {
        OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(spell_sylvanas_windrunner_veil_of_darkness_debuff::OnHealAbsorb, EFFECT_1);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_debuff::AfterRemove, EFFECT_1, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 353417 - Rive
// 353418 - Rive (Fast)
class spell_sylvanas_windrunner_rive : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RIVE_CHAIN,
            SPELL_RIVE_CHAIN_FAST,
            SPELL_VISUAL_TORGHAST_SPIRE_BREAK,
            SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (Creature* shadowCopy3 = GetShadowcopy(instance, DATA_INDEX_03))
        {
            shadowCopy3->CastSpell(sylvanas, GetSpellInfo()->Id == SPELL_RIVE ? SPELL_RIVE_CHAIN : SPELL_RIVE_CHAIN_FAST);

            for (uint32 platformSpireIndex = GAMEOBJECT_TORGHAST_SPIKE_01; platformSpireIndex < GAMEOBJECT_TORGHAST_SPIKE_12 + 1; platformSpireIndex++)
            {
                std::list<GameObject*> platformSpire;
                shadowCopy3->GetGameObjectListWithEntryInGrid(platformSpire, platformSpireIndex, 10.0f);

                if (platformSpire.empty())
                    continue;

                if (GameObject* nearestPlatformSpire = platformSpire.front())
                    nearestPlatformSpire->SetSpellVisualId(GetSpellInfo()->Id == SPELL_RIVE ? SPELL_VISUAL_TORGHAST_SPIRE_BREAK : SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST, sylvanas->GetGUID());
            }
        }
    }

    void HandleAfterCast()
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (Creature* shadowCopy = GetShadowcopy(instance, DATA_INDEX_00))
            sylvanas->CastSpell(shadowCopy->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_rive::HandleAfterCast);
    }
};

// 353375 - Rive (Areatrigger)
class spell_sylvanas_windrunner_rive_areatrigger : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 0.0f, float(M_PI + 0.040f) });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_sylvanas_windrunner_rive_areatrigger::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 348094 - Banshee Wail
class spell_sylvanas_windrunner_banshee_wail : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            SPELL_BANSHEE_WAIL_EXPIRE,
            SPELL_BANSHEE_WAIL_MARKER,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BANSHEE_WAIL_EXPIRE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 500.0f);

        for (Player* target : targetList)
            GetCaster()->CastSpell(target, SPELL_BANSHEE_WAIL_MARKER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4650));
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, caster, 500.0f);

        for (Player* target : targetList)
            caster->CastSpell(target, GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_banshee_wail::HandleAfterCast);
    }
};

// 357719 - Banshee Wail (Marker)
class spell_sylvanas_windrunner_banshee_wail_marker : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SendPlaySpellVisualKit(GetTarget()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ?
            SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE_MYTHIC : SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE, 0, 0);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_wail_marker::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 348108 - Banshee Wail (Triggered Missile)
class spell_sylvanas_windrunner_banshee_wail_triggered_missile : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_triggered_missile::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_triggered_missile::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 351252 - Banshee Wail (Interrupt)
class spell_sylvanas_windrunner_banshee_wail_interrupt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BANSHEE_WAIL_SILENCE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->HasUnitState(UNIT_STATE_CASTING))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_WAIL_SILENCE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_interrupt::HandleHit, EFFECT_0, SPELL_EFFECT_INTERRUPT_CAST);
    }
};

// 348146 - Banshee Form
class spell_sylvanas_windrunner_banshee_form : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);
        target->SetHover(true);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), target->m_Events.CalculateTime(0ms));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);
        target->SetHover(false);

        target->SetVirtualItem(0, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(1, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(2, DATA_DISPLAY_ID_SYLVANAS_BOW);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), target->m_Events.CalculateTime(0ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_banshee_form::OnApply, EFFECT_0, SPELL_AURA_FLY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_form::AfterRemove, EFFECT_0, SPELL_AURA_FLY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352271 - Haunting Wave
class spell_sylvanas_windrunner_haunting_wave : public SpellScript
{
    class HauntingWaveEvent : public BasicEvent
    {
    public:
        HauntingWaveEvent(Unit* actor, Position const hauntingWaveDest, uint32 hauntingWaveAreaTriggerSpell) : _actor(actor),
            _hauntingWaveDest(hauntingWaveDest), _hauntingWaveAreaTriggerSpell(hauntingWaveAreaTriggerSpell) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_hauntingWaveDest, _hauntingWaveAreaTriggerSpell, true);

            return true;
        }

    private:
        Unit* _actor;
        Position _hauntingWaveDest;
        uint32 _hauntingWaveAreaTriggerSpell;
    };

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();

        uint8 waveBarrage = caster->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID && caster->GetEntry() == BOSS_SYLVANAS_WINDRUNNER ? 3 : 2;

        for (uint8 itr = 0; itr < waveBarrage; itr++)
        {
            for (uint8 i = 0; i < _waveCount; i++)
            {
                float angle = 0.0f;

                switch (itr)
                {
                    case 0:
                        angle = _angleOffset * i;
                        break;
                    case 1:
                        angle = 3.0f + _angleOffset * i;
                        break;
                    case 2:
                        angle = 6.0f + _angleOffset * i;
                        break;
                    default:
                        break;
                }

                Position dest = { caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), angle };

                if (itr == 0)
                    caster->m_Events.AddEvent(new HauntingWaveEvent(caster, dest, GetEffectInfo(effIndex).TriggerSpell), caster->m_Events.CalculateTime(26ms));
                else if (itr == 1)
                    caster->m_Events.AddEvent(new HauntingWaveEvent(caster, dest, GetEffectInfo(effIndex).TriggerSpell), caster->m_Events.CalculateTime(658ms));
                else
                    caster->m_Events.AddEvent(new HauntingWaveEvent(caster, dest, GetEffectInfo(effIndex).TriggerSpell), caster->m_Events.CalculateTime(1316ms));
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_haunting_wave::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint8 _waveCount = 12;
    float _angleOffset = float(M_PI * 2) / _waveCount;
};

// 355540 - Ruin
class spell_sylvanas_windrunner_ruin : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_RUIN_VISUAL, spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Unit*> targets;
        caster->GetAI()->SelectTargetList(targets, 2, SelectTargetMethod::Random, 0, 500.0f, true, true);

        for (Unit* target : targets)
        {
            caster->CastSpell(*target, SPELL_RUIN_VISUAL, true);
            caster->CastSpell(*target, aurEff->GetSpellEffectInfo().TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_ruin::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 352239 - Veil of Darkness (Grow - Phase 2)
class spell_sylvanas_windrunner_veil_of_darkness_grow_phase_2 : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), target->m_Events.CalculateTime(0ms));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);

        target->SetVirtualItem(0, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(1, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(2, DATA_DISPLAY_ID_SYLVANAS_BOW);

        target->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(target, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), target->m_Events.CalculateTime(0ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_2::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_2::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347741 - Veil of Darkness (Cast - Phase 2)
class spell_sylvanas_windrunner_veil_of_darkness_phase_2 : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA });
    }

    void OnPrecast() override
    {
        uint32 spellVisual = 0;

        switch (GetCaster()->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_HEROIC_RAID:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_HC;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_MM;
                break;
            default:
                spellVisual = SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_TWO_LFR_AND_NM;
                break;
        }

        GetCaster()->SendPlayOrphanSpellVisual(Position(GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ() + 0.05f), spellVisual, 3.0f, true, false);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();

        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA, true);
    }

    void HandleAfterCast()
    {
        GetCaster()->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(GetCaster(), false), GetCaster()->m_Events.CalculateTime(500ms));
        GetCaster()->resetAttackTimer(BASE_ATTACK);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_2::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_2::HandleAfterCast);
    }
};

// 352225 - Veil of Darkness (Area - Phase 2)
class spell_sylvanas_windrunner_veil_of_darkness_area_phase_2 : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_area_phase_2::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_area_phase_2::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 354011 - Bane Arrows
class spell_sylvanas_windrunner_bane_arrows : public SpellScript
{
    class BaneArrowEvent : public BasicEvent
    {
    public:
        BaneArrowEvent(Unit* actor, Position const arrowDestPos) : _actor(actor), _arrowDestPos(arrowDestPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_arrowDestPos, SPELL_BANE_ARROWS_DAMAGE, true);
            _actor->CastSpell(_arrowDestPos, SPELL_BANSHEES_BANE_AREATRIGGER, true);

            return true;
        }

    private:
        Unit* _actor;
        Position _arrowDestPos;
    };

    void OnPrecast() override
    {
        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_BANE_ARROWS, 0, 0);
    }

    void HandleAfterCast()
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (boss_sylvanas_windrunner* sylvanasAI = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
        {
            for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
            {
                if (sylvanasAI->IsPlatformDesecrated(SylvanasPlatforms(platform)))
                    continue;

                for (uint8 i = 0; i < 7; i++)
                {
                    Position const baneArrowPos = SylvanasPositionHelpers::GetRandomPointInNonDesecratedPlatform(sylvanas, platform);

                    uint32 visual = 0;
                    float speed = 0;

                    switch (sylvanas->GetMap()->GetDifficultyID())
                    {
                        case DIFFICULTY_MYTHIC_RAID:
                            visual = SPELL_VISUAL_BANE_ARROWS_MM;
                            speed = frand(1.790414214134216308f, 2.609101772308349609f);
                            break;
                        default:
                            visual = SPELL_VISUAL_BANE_ARROWS_NM_AND_HC;
                            speed = frand(2.04f, 3.240910291671752929f);
                            break;
                    }

                    sylvanas->SendPlaySpellVisual(baneArrowPos, 0.0f, visual, 0, 0, speed, true);

                    uint32 timer = uint32(speed * 1000);

                    sylvanas->m_Events.AddEvent(new BaneArrowEvent(sylvanas, baneArrowPos), sylvanas->m_Events.CalculateTime(Milliseconds(timer)));
                }
            }
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_bane_arrows::HandleAfterCast);
    }
};

std::vector<Position> FlyingBaneAts;

// 353929 - Banshee's Bane
class spell_sylvanas_windrunner_banshee_bane : public AuraScript
{
    class BansheeBaneEvent : public BasicEvent
    {
    public:
        BansheeBaneEvent(Unit* actor, Position const bansheeBanePos) : _actor(actor), _bansheeBanePos(bansheeBanePos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_bansheeBanePos, SPELL_BANSHEES_BANE_AREATRIGGER, true);
            FlyingBaneAts.erase(std::remove(FlyingBaneAts.begin(), FlyingBaneAts.end(), _bansheeBanePos));

            return true;
        }

    private:
        Unit* _actor;
        Position _bansheeBanePos;
    };

    class BansheeBaneVisualEvent : public BasicEvent
    {
    public:
        BansheeBaneVisualEvent(Unit* actor, Position const bansheeBanePos, Unit* secondActor) : _actor(actor), _bansheeBanePos(bansheeBanePos), _secondActor(secondActor) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->SendPlaySpellVisual(_bansheeBanePos, SPELL_VISUAL_BANSHEES_BANE_DROP, 0, 0, 0.349999994039535522f, true);
            _secondActor->m_Events.AddEvent(new BansheeBaneEvent(_secondActor, _bansheeBanePos), _secondActor->m_Events.CalculateTime(349ms));

            return true;
        }

private:
        Unit* _actor;
        Position _bansheeBanePos;
        Unit* _secondActor;
    };

    std::vector<Position> GetAllBanePositions(Unit* unit)
    {
        std::vector<Position> posVec;

        Creature* sylvanas = unit->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return posVec;

        std::vector<AreaTrigger*> baneAreaTriggers = sylvanas->GetAreaTriggers(SPELL_BANSHEES_BANE_AREATRIGGER);
        for (AreaTrigger* at : baneAreaTriggers)
            posVec.push_back(at->GetPosition());
        for (Position& pos : FlyingBaneAts)
            posVec.push_back(pos);

        return posVec;
    }

    bool IsPositionWithinBaneAreaTriggers(Unit* unit, Position const& targetPos)
    {
        for (Position const& pos : GetAllBanePositions(unit))
        {
            if (pos.GetExactDist(targetPos) <= 2.6f)
                return true;
        }

        return false;
    }

    Position GetClosestNonDesecratedPlatformOrigin(Unit* unit, Position bansheeBanePos)
    {
        float closestDist = 1000.0f;
        Position closestPos;

        if (Creature* sylvanas = unit->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (boss_sylvanas_windrunner* sylvanasAI = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
            {
                for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
                {
                    if (sylvanasAI->IsPlatformDesecrated(SylvanasPlatforms(platform)))
                        continue;

                    Position pos = CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM];

                    float dist = pos.GetExactDist(bansheeBanePos);
                    if (dist >= closestDist)
                        continue;

                    closestDist = dist;
                    closestPos = pos;
                }
            }
        }

        return closestPos;
    }

    bool FindClosestPositionFromAreaTrigger(Unit* unit, Position const& origin, Position const& pos, Position& outPos, Position const& platformOrigin)
    {
        static constexpr float MAX_ORIENTATION_OFFSET = float(M_PI / 4);
        float atOrientation = origin.GetAbsoluteAngle(pos);
        float offsetOrientation = -MAX_ORIENTATION_OFFSET;

        do
        {
            offsetOrientation += float(MAX_ORIENTATION_OFFSET / 2);

            float dist = 3.6f * 2;
            float angle = atOrientation + offsetOrientation;
            Position offsetPos(origin.m_positionX + dist * std::cos(angle), origin.m_positionY + dist * std::sin(angle), origin.GetPositionZ());

            if (IsPositionWithinBaneAreaTriggers(unit, offsetPos))
                continue;

            if (!offsetPos.IsWithinBox(platformOrigin, 17.0f, 17.0f, 17.0f))
                continue;

            outPos = offsetPos;

            return true;

        } while (offsetOrientation < 2 * M_PI);

        return false;
    }

    Position const TranslocateBanePosition(Position bansheeBanePos, Position closestPlatformOrigin)
    {
        float angle = bansheeBanePos.GetAbsoluteAngle(closestPlatformOrigin);
        float dist = 1.0f;
        Position offsetPos;
        do
        {
            offsetPos.Relocate(bansheeBanePos.GetPositionX() + dist * std::cos(angle), bansheeBanePos.GetPositionY() + dist * std::sin(angle), 5671.90f);
            dist += 1.0f;
        } while (!offsetPos.IsWithinBox(closestPlatformOrigin, 17.0f, 17.0f, 17.0f));

        return offsetPos;
    }

    Position const GetClosestPossibleBanePosition(Unit* unit)
    {
        Position bansheeBanePos = unit->GetRandomNearPosition(2.0f);

        // Note: let's obtain the closest non-desecrated platform origin.
        Position closestPlatformOrigin = GetClosestNonDesecratedPlatformOrigin(unit, bansheeBanePos);

        // Note: if it's not within the boundaries, we need to translocate.
        if (!bansheeBanePos.IsWithinBox(closestPlatformOrigin, 17.0f, 17.0f, 17.0f))
            bansheeBanePos = TranslocateBanePosition(bansheeBanePos, closestPlatformOrigin);

        std::vector<Position> banePositions = GetAllBanePositions(unit);

        // Note: no areatriggers created yet, just return pos.
        if (banePositions.empty())
            return bansheeBanePos;

        // Note: now order by distance ascending.
        std::sort(banePositions.begin(), banePositions.end(), [bansheeBanePos](Position const& lhs, Position const& rhs)
        {
            return bansheeBanePos.GetExactDist(lhs) < bansheeBanePos.GetExactDist(rhs);
        });

        // Note: it is not within the nearest areatrigger, it can return.
        if (bansheeBanePos.GetExactDist(banePositions[0]) > 2.6f)
            return bansheeBanePos;

        for (Position const& pos : banePositions)
        {
            Position outPos;
            if (FindClosestPositionFromAreaTrigger(unit, pos, bansheeBanePos, outPos, closestPlatformOrigin))
                return outPos;
        }

        return bansheeBanePos;
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
        if (mode == AURA_REMOVE_BY_ENEMY_SPELL || mode == AURA_REMOVE_BY_DEATH)
        {
            for (uint8 stackAmount = GetStackAmount(); stackAmount > 0; stackAmount--)
            {
                Position bansheeBanePos = GetClosestPossibleBanePosition(GetTarget());

                FlyingBaneAts.push_back(bansheeBanePos);

                GetTarget()->m_Events.AddEvent(new BansheeBaneVisualEvent(GetTarget(), bansheeBanePos, GetTarget()), GetTarget()->m_Events.CalculateTime(0ms));
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_bane::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 354068 - Banshee's Fury
class spell_sylvanas_windrunner_banshee_fury : public AuraScript
{
    class BansheesFuryEvent : public BasicEvent
    {
    public:
        BansheesFuryEvent(Unit* actor, uint8 platform) : _actor(actor), _platform(platform) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_actor->HasAura(SPELL_BANSHEES_FURY))
                _actor->SendPlaySpellVisual(SylvanasPositionHelpers::GetRandomPointInNonDesecratedPlatform(_actor, _platform, false), SPELL_VISUAL_BANSHEE_FURY, 0, 0, 0.100000001490116119f, true);

            return true;
        }

    private:
        Unit* _actor;
        uint8 _platform;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT, SPELL_BANSHEES_FURY_SCALE, SPELL_BANSHEES_FURY_EXPLODE });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));
        GetTarget()->CastSpell(GetTarget(), SPELL_BANSHEES_FURY_SCALE, TRIGGERED_FULL_MASK);
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (boss_sylvanas_windrunner* sylvanasAI = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
        {
            for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
            {
                if (sylvanasAI->IsPlatformDesecrated(SylvanasPlatforms(platform)))
                    continue;

                for (uint8 i = 0; i < 80; i++)
                    GetTarget()->m_Events.AddEvent(new BansheesFuryEvent(GetTarget(), platform), GetTarget()->m_Events.CalculateTime(40ms * i));
            }
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);

        target->SetVirtualItem(0, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(1, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(2, DATA_DISPLAY_ID_SYLVANAS_BOW);

        target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_FURY_END, 0, 0);

        target->SetNameplateAttachToGUID(ObjectGuid::Empty);

        target->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(target, false, true), target->m_Events.CalculateTime(1s + 500ms));

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, target, 300.0f);

        for (Player* player : playerList)
        {
            if (!player->HasAura(SPELL_BANSHEES_BANE))
                continue;

            target->CastSpell(player->GetPosition(), SPELL_BANSHEES_FURY_EXPLODE, TRIGGERED_FULL_MASK);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_banshee_fury::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_banshee_fury::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_fury::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 354147 - Raze
class spell_sylvanas_windrunner_raze : public SpellScript
{
    class RazeEvent : public BasicEvent
    {
    public:
        RazeEvent(Unit* actor) : _actor(actor) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->SendPlaySpellVisual(SylvanasPositionHelpers::GetPointInCurrentPlatform(_actor, DATA_PLATFORM_RANDOM_POINT, false), SPELL_VISUAL_RAZE, 0, 0, 0.100000001490116119f, true);

            return true;
        }

    private:
        Unit* _actor;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WINDRUNNER_DISAPPEAR_02 });
    }

    void OnPrecast() override
    {
        for (uint8 i = 0; i < 100; i++)
            GetCaster()->m_Events.AddEvent(new RazeEvent(GetCaster()), GetCaster()->m_Events.CalculateTime(50ms * i));
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WINDRUNNER_DISAPPEAR_02, true);

        GetCaster()->GetAI()->DoAction(ACTION_SWITCH_PLATFORM);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_raze::HandleAfterCast);
    }
};

// 354141 - Sylvanas' Push
class spell_sylvanas_windrunner_sylvanas_push : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        _playerGUID = GetTarget()->GetGUID();

        _sylvanasPushAreaTriggerGUID = AreaTrigger::CreateNewMovementForceId(GetTarget()->GetMap(), DATA_AREATRIGGER_SYLVANAS_PUSH);

        GetTarget()->ApplyMovementForce(_sylvanasPushAreaTriggerGUID, sylvanas->GetPosition(), -14.0f, MovementForceType::Gravity);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveMovementForce(_sylvanasPushAreaTriggerGUID);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_sylvanas_push::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_sylvanas_push::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    ObjectGuid _playerGUID;
    ObjectGuid _sylvanasPushAreaTriggerGUID;
};

// 353935 - Shadow Dagger
class spell_sylvanas_shadow_dagger_phase_three : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RANGER_DAGGERS_STANCE, SPELL_SHADOW_DAGGER });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();

        caster->CastSpell(caster, SPELL_RANGER_DAGGERS_STANCE, true);

        for (uint8 i = 0; i < _visualCount; i++)
        {
            float angle = _angleOffset * i;

            Position visualPos(caster->GetPositionX() + (std::cos(angle) * 10.0f), caster->GetPositionY() + (std::sin(angle) * 10.0f), caster->GetPositionZ());

            caster->SendPlaySpellVisual(visualPos, SPELL_VISUAL_SHADOW_DAGGER_MARKER_PHASE_THREE, 0, 0, 1.5f, true);

            Position nextFirstVisualPos(caster->GetPositionX() + (std::cos(angle) * 8.0f), caster->GetPositionY() + (std::sin(angle) * 8.0f), caster->GetPositionZ());
            _visualDestPos.push_back(nextFirstVisualPos);

            Position nextSecondVisualPos(caster->GetPositionX() + (std::cos(angle) * 16.0f), caster->GetPositionY() + (std::sin(angle) * 16.0f), caster->GetPositionZ());
            _visualDestPos.push_back(nextSecondVisualPos);

            Position nextThirdVisualPos(caster->GetPositionX() + (std::cos(angle) * 24.0f), caster->GetPositionY() + (std::sin(angle) * 24.0f), caster->GetPositionZ());
            _visualDestPos.push_back(nextThirdVisualPos);

            Position nextFourthVisualPos(caster->GetPositionX() + (std::cos(angle) * 32.0f), caster->GetPositionY() + (std::sin(angle) * 32.0f), caster->GetPositionZ());
            _visualDestPos.push_back(nextFourthVisualPos);

            Position finalDestPos(caster->GetPositionX() + (std::cos(angle) * 53.0f), caster->GetPositionY() + (std::sin(angle) * 53.0f), caster->GetPositionZ());
            _finalDestPos.push_back(finalDestPos);
        }
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
        caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER_SOUND, 0, 0);

        for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
        {
            // Note: let's find out current platform.
            if (!caster->IsWithinBox(CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 17.0f, 17.0f, 17.0f))
                continue;

            for (Position& destPos : _visualDestPos)
            {
                // Note: Sylvanas doesn't send visuals to points that are outside the current platform.
                if (!destPos.IsWithinBox(CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 17.0f, 17.0f, 17.0f))
                    continue;

                caster->SendPlaySpellVisual(destPos, SPELL_VISUAL_SHADOW_DAGGER_PHASE_THREE, 0, 0, 100.0f, false);
            }
        }

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, caster, 53.0f);

        for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
        {
            for (Player* player : playerList)
            {
                // Note: Sylvanas doesn't hit anyone who's not in the current platform.
                if (!player->IsWithinBox(CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 17.0f, 17.0f, 17.0f))
                    continue;

                for (uint8 i = 0; i < _visualCount; i++)
                {
                    if (player->IsInBetween(caster->GetPosition(), _finalDestPos[i], 1.0f))
                        caster->CastSpell(player, SPELL_SHADOW_DAGGER, true);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_shadow_dagger_phase_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint8 _visualCount = 8;
    float _angleOffset = float(M_PI * 2) / _visualCount;
    std::vector<Position> _visualDestPos;
    std::vector<Position> _finalDestPos;
};

// 354143 - Veil of Darkness (Grow - Phase 3)
class spell_sylvanas_windrunner_veil_of_darkness_grow_phase_3 : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);

        target->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);

        target->SetVirtualItem(0, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(1, DATA_DISPLAY_ID_SYLVANAS_DAGGER);
        target->SetVirtualItem(2, DATA_DISPLAY_ID_SYLVANAS_BOW);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_3::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_3::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 354142 - Veil of Darkness (Cast - Phase 3)
class spell_sylvanas_windrunner_veil_of_darkness_phase_3 : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_VEIL_OF_DARKNESS_PHASE_3_MARKER,
            SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW,
            SPELL_VEIL_OF_DARKNESS_DAMAGE,
            SPELL_VEIL_OF_DARKNESS_ABSORB_AURA,
            SPELL_STOMP_MOVEMENT_FORCE_AURA
        });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();

        if (Unit* target = caster->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
        {
            _targetGUID = target->GetGUID();

            target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE, 0, 0);
            target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE_FLOOR, 0, 0);

            target->CastSpell(target, SPELL_VEIL_OF_DARKNESS_PHASE_3_MARKER, true);
        }

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), caster->m_Events.CalculateTime(0ms));
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_STOMP, 0, 0);

        caster->RemoveAura(SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW);

        if (Player* target = ObjectAccessor::GetPlayer(*caster, _targetGUID))
        {
            target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_PHASE_THREE_FINISH, 0, 0);

            caster->NearTeleportTo(target->GetPosition());
        }
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, caster, 5.0f);

        for (Player* player : playerList)
        {
            uint8 auraCount = 1;

            switch (caster->GetMap()->GetDifficultyID())
            {
                case DIFFICULTY_HEROIC_RAID:
                    auraCount = 5;
                    break;
                case DIFFICULTY_MYTHIC_RAID:
                    auraCount = 6;
                    break;
                default:
                    break;
            }

            for (auraCount; auraCount > 0; auraCount--)
                caster->CastSpell(player, SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, true);

            caster->CastSpell(player, SPELL_VEIL_OF_DARKNESS_DAMAGE, true);

            player->AddAura(SPELL_STOMP_MOVEMENT_FORCE_AURA, player);
        }

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), caster->m_Events.CalculateTime(0ms));

        caster->setAttackTimer(WeaponAttackType::BASE_ATTACK, 1500);

        caster->GetAI()->DoAction(ACTION_RESET_MELEE_KIT);

        caster->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(caster, false, true), caster->m_Events.CalculateTime(1s + 500ms));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_3::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_3::HandleAfterCast);
    }

private:
    ObjectGuid _targetGUID;
};

enum BolvarSpells
{
    SPELL_RUNIC_MARK                  = 354926,
    SPELL_RUNIC_MARK_TRIGGERED        = 354927,
    SPELL_GLYPH_OF_DESINTEGRATION     = 354932,
    SPELL_CHARGE_TOWARDS_SYLVANAS     = 357046,
    SPELL_WINDS_OF_ICECROWN           = 356941,
    SPELL_WINDS_OF_ICECROWN_INTERRUPT = 356986
};

enum BolvarEvents
{
    EVENT_RUNIC_MARK                  = 1,
    EVENT_GLYPH_OF_DESINTEGRATION
};

enum BolvarActions
{
    ACTION_WINDS_OF_ICECROWN          = 1
};

enum BolvarTexts
{
    TALK_FIRST_CHAIN                  = 0,
    TALK_SECOND_CHAIN                 = 1,
    TALK_FIRST_RUIN                   = 2,
    TALK_WINDS_OF_ICECROWN_01         = 3,
    TALK_THIRD_CHAIN_START            = 4,
    TALK_THIRD_CHAIN_FINISH           = 5,
    TALK_WINDS_OF_ICECROWN_02         = 9,
    TALK_PREPARE_PHASE_THREE          = 11
};

enum BolvarMisc
{
    POINT_JUMP_SECOND_CHAIN           = 2
};

Position const BolvarPrePhaseTwoPos = { 204.64757f, -842.77606f, 4999.9956f,  0.7806f };

// HACKFIX: Vmaps on gameobjects is NYI, I'm adding custom points for jumping from one chain to the other.
Position const BolvarPhaseTwoPos[10] =
{
    { 204.6475f, -842.7760f, 4999.995f, 0.7806f },
    { 205.5017f, -839.9323f, 5000.162f, 0.9862f },
    { 195.3038f, -843.8055f, 5000.038f, 3.0062f },
    { 112.9909f, -821.6018f, 4999.974f, 3.9780f }, // HACKFIX
    { 48.6562f,  -877.9184f, 5000.093f, 3.9858f }
};

Position const BolvarPrePhaseThreePos = { -249.54861f, -1278.5382f, 5667.1157f, 1.5865f };

// 178081 - Highlord Bolvar Fordragon
struct npc_sylvanas_windrunner_bolvar : public ScriptedAI
{
    npc_sylvanas_windrunner_bolvar(Creature* creature) : ScriptedAI(creature, DATA_BOLVAR_FORDRAGON_PINNACLE),
        _instance(creature->GetInstanceScript()), _windsOfIcecrown(0) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
    }

    void Reset() override
    {
        _events.Reset();

        _windsOfIcecrown = 0;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_JUMP_SECOND_CHAIN)
            me->GetMotionMaster()->MovePoint(0, BolvarPhaseTwoPos[4], false);
    }

    void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_WINDS_OF_ICECROWN)
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (_windsOfIcecrown == 1)
            {
                sylvanas->RemoveAura(SPELL_BANSHEE_READY_STANCE);
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WINDS_01, 0, 0);

                me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false), me->m_Events.CalculateTime(1ms));

                _scheduler.Schedule(47ms, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED, 0, 0);
                });

                _scheduler.Schedule(1s, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(sylvanas, false), sylvanas->m_Events.CalculateTime(1ms));
                });

                _scheduler.Schedule(1s + 454ms, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->AI()->Talk(TALK_WINDS_OF_ICECROWN_AFTER_01);
                });
            }
            else
            {
                sylvanas->RemoveAura(SPELL_BANSHEE_READY_STANCE);
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WINDS_02, 0, 0);

                me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false), me->m_Events.CalculateTime(1ms));

                _scheduler.Schedule(47ms, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED, 0, 0);
                });

                _scheduler.Schedule(1s, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(sylvanas, false), sylvanas->m_Events.CalculateTime(1ms));
                });

                _scheduler.Schedule(1s + 454ms, [sylvanas](TaskContext /*task*/)
                {
                    sylvanas->AI()->Talk(TALK_WINDS_OF_ICECROWN_AFTER_02);
                });
            }
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            me->GetAI()->AttackStart(sylvanas);

        _events.ScheduleEvent(EVENT_RUNIC_MARK, 1s, PHASE_ONE);
        _events.ScheduleEvent(EVENT_GLYPH_OF_DESINTEGRATION, 5s, PHASE_ONE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_WINDS_OF_ICECROWN_PRE:
            {
                // HACKFIX: GameObject pathing NYI.
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (_windsOfIcecrown == 0)
                        Talk(TALK_WINDS_OF_ICECROWN_01);
                    else
                        Talk(TALK_WINDS_OF_ICECROWN_02);

                    me->CastSpell(sylvanas, SPELL_CHARGE_TOWARDS_SYLVANAS);

                    _windsOfIcecrown++;
                }
                break;
            }

            case ACTION_WINDS_OF_ICECROWN:
            {
                _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        me->CastSpell(sylvanas, SPELL_WINDS_OF_ICECROWN);
                });

                // HACKFIX: GameObject pathing NYI.
                _scheduler.Schedule(1s, [this](TaskContext /*task*/)
                {
                    me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                });
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RUNIC_MARK:
                    DoCastVictim(!me->IsWithinMeleeRange(me->GetVictim()) ? SPELL_RUNIC_MARK : SPELL_RUNIC_MARK_TRIGGERED);
                    _events.Repeat(6s, 8s);
                    break;

                case EVENT_GLYPH_OF_DESINTEGRATION:
                    DoCastVictim(SPELL_GLYPH_OF_DESINTEGRATION);
                    _events.Repeat(10s, 12s);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
    uint8 _windsOfIcecrown;
};

// 354928 - Runic Mark (Triggered)
class spell_sylvanas_windrunner_runic_mark_triggered : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_runic_mark_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357046 - Charge Towards Sylvanas
class spell_sylvanas_windrunner_charge_towards_sylvanas : public SpellScript
{
    void HandleCharge(SpellEffIndex /*effIndex*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            bolvar->GetAI()->DoAction(ACTION_WINDS_OF_ICECROWN);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_charge_towards_sylvanas::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

// 356941 - Winds of Icecrown
class spell_sylvanas_windrunner_winds_of_icecrown : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WINDS_OF_ICECROWN_INTERRUPT });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WINDS_OF_ICECROWN_INTERRUPT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_winds_of_icecrown::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum ThrallSpells
{
    SPELL_FLAMEAXE                  = 354898,
    SPELL_PULVERIZE                 = 354918,
    SPELL_STONECRASH                = 357139,
    SPELL_EARTHEN_GRASP             = 354900,

    SPELL_JUMP_PHASE_TWO_MASTER     = 351862,
    SPELL_CALL_EARTH                = 352842,
    SPELL_CALL_EARTH_AREATRIGGER_01 = 354576,
    SPELL_CALL_EARTH_AREATRIGGER_02 = 354575,
    SPELL_CALL_EARTH_AREATRIGGER_03 = 354577,
    SPELL_CALL_EARTH_BRIDGE_01      = 351840,
    SPELL_CALL_EARTH_BRIDGE_02      = 348093,
    SPELL_CALL_EARTH_BRIDGE_03      = 351841
};

enum ThrallEvents
{
    EVENT_FLAMEAXE                  = 1,
    EVENT_PULVERIZE,
    EVENT_STONECRASH_PHASE_ONE_AND_THREE,
    EVENT_EARTHEN_GRASP
};

enum ThrallActions
{
    ACTION_PREPARE_EARTH_BRIDGE_1   = 1
};

enum ThrallTexts
{
    TALK_CROSSING_FIRST_BRIDGE      = 0,
    TALK_FORMING_SECOND_BRIDGE      = 1
};

Position const ThrallPrePhaseTwoPos = { 209.80556f, -823.7917f, 4999.985f, 4.52320f };

// HACKFIX: pathfinding on gameobject is NYI, I'm adding custom points for jumping from one chain to the other
Position const ThrallPhaseTwoPos[10] =
{
    { 207.5f,    -831.4184f, 5000.203f, -1.399f },
    { 198.9548f, -845.8125f, 5000.038f, -1.399f },
    { 120.4910f, -820.9802f, 4999.974f, 3.9544f }, // HACKFIX
    { 55.6406f,  -878.5989f, 5000.149f, 3.9858f },
    { 45.70656f, -885.2656f, 5000.005f, 3.7368f }
};

Position const ThrallCallEarthTargetPos[3] =
{
    { 13.3576f, -913.349f, 4999.5f, 5.4977f },
    {  },
    {  }
};

Position const ThrallPrePhaseThreePos = { -242.277f, -1282.972f, 5667.1157f, 1.53310f };

// 176532 - Thrall
struct npc_sylvanas_windrunner_thrall : public ScriptedAI
{
    npc_sylvanas_windrunner_thrall(Creature* creature) : ScriptedAI(creature, DATA_THRALL_PINNACLE),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_JUMP_SECOND_CHAIN)
            me->GetMotionMaster()->MovePoint(0, ThrallPhaseTwoPos[3], false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            me->GetAI()->AttackStart(sylvanas);

        _events.ScheduleEvent(EVENT_FLAMEAXE, 6s + 300ms, 1);
        _events.ScheduleEvent(EVENT_PULVERIZE, 9s, 1);
        //_events.ScheduleEvent(EVENT_STONECRASH_PHASE_ONE_AND_THREE, 8s + 400ms, 1, PHASE_ONE);

        if (me->GetAreaId() != AREA_THE_CRUCIBLE)
            _events.ScheduleEvent(EVENT_EARTHEN_GRASP, 11s + 800ms, 1);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PREPARE_EARTH_BRIDGE_1:
            {
                FormEarthBridge(ThrallPhaseTwoPos[4], ThrallCallEarthTargetPos[0]);

                _scheduler.Schedule(4s + 281ms, [this](TaskContext /*task*/)
                {
                    Talk(TALK_FORMING_SECOND_BRIDGE);
                });

                _scheduler.Schedule(8s + 47ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->AI()->Talk(TALK_FIRST_RUIN);
                });
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FLAMEAXE:
                    DoCastSelf(SPELL_FLAMEAXE);
                    _events.Repeat(18s, 20s);
                    break;

                case EVENT_PULVERIZE:
                    DoCastVictim(SPELL_PULVERIZE);
                    _events.Repeat(9s + 750ms, 15s + 800ms);
                    break;

                case EVENT_STONECRASH_PHASE_ONE_AND_THREE:
                    DoCastVictim(SPELL_STONECRASH);
                    _events.Repeat(12s, 18s);
                    break;

                case EVENT_EARTHEN_GRASP:
                    DoCastVictim(SPELL_EARTHEN_GRASP);
                    if (me->GetAreaId() != AREA_THE_CRUCIBLE)
                        _events.Repeat(8s, 10s);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void FormEarthBridge(Position jumpPos, Position bridgePos)
    {
        me->CastSpell(jumpPos, SPELL_JUMP_PHASE_TWO_MASTER);

        uint32 bridgeAreaTriggerSpell = 0;
        uint32 bridgeGameObjectSpell = 0;

        switch (uint8 randomBridge = urand(DATA_BRIDGE_PHASE_TWO_1, DATA_BRIDGE_PHASE_TWO_3))
        {
            case DATA_BRIDGE_PHASE_TWO_1:
                bridgeAreaTriggerSpell = SPELL_CALL_EARTH_AREATRIGGER_01;
                bridgeGameObjectSpell = SPELL_CALL_EARTH_BRIDGE_01;
                break;
            case DATA_BRIDGE_PHASE_TWO_2:
                bridgeAreaTriggerSpell = SPELL_CALL_EARTH_AREATRIGGER_02;
                bridgeGameObjectSpell = SPELL_CALL_EARTH_BRIDGE_02;
                break;
            case DATA_BRIDGE_PHASE_TWO_3:
                bridgeAreaTriggerSpell = SPELL_CALL_EARTH_AREATRIGGER_03;
                bridgeGameObjectSpell = SPELL_CALL_EARTH_BRIDGE_03;
                break;
            default:
                break;
        }

        _scheduler.Schedule(1s + 266ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_CALL_EARTH);
        });

        _scheduler.Schedule(2s + 250ms, [this, bridgePos, bridgeAreaTriggerSpell](TaskContext /*task*/)
        {
            me->CastSpell(bridgePos, bridgeAreaTriggerSpell, true);
        });

        _scheduler.Schedule(6s + 266ms, [this, bridgePos, bridgeGameObjectSpell](TaskContext /*task*/)
        {
            me->CastSpell(bridgePos, bridgeGameObjectSpell, true);
        });
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// 354918 - Pulverize
class spell_sylvanas_windrunner_pulverize : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_pulverize::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 354923 - Pulverize (triggered)
class spell_sylvanas_windrunner_pulverize_triggered : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_pulverize_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357139 - Stonecrash (Phase 1 and 3)
class spell_sylvanas_windrunner_stonecrash_phase_one_and_three : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_stonecrash_phase_one_and_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357137 - Stonecrash (Phase 2)
class spell_sylvanas_windrunner_stonecrash_phase_two : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_stonecrash_phase_two::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum JainaSpells
{
    SPELL_ICE_BOLT                          = 350002,
    SPELL_COMET_BARRAGE                     = 354938,
    SPELL_FRIGID_SHARDS                     = 354933,
    SPELL_CONE_OF_COLD                      = 350003,
    SPELL_SEARING_BLAST                     = 355507,
    SPELL_BLINK                             = 362844,

    SPELL_TELEPORT_TO_PHASE_2               = 355073,
    SPELL_TELEPORT_PHASE_TWO_MASTER         = 351890,
    SPELL_CHANNEL_ICE                       = 352843,
    SPELL_CHANNEL_ICE_AREATRIGGER_01        = 354476,
    SPELL_CHANNEL_ICE_AREATRIGGER_02        = 354573,
    SPELL_CHANNEL_ICE_AREATRIGGER_03        = 354574,
    SPELL_CHANNEL_ICE_BRIDGE_01             = 348148,
    SPELL_CHANNEL_ICE_BRIDGE_02             = 351837,
    SPELL_CHANNEL_ICE_BRIDGE_03             = 351838,
    SPELL_PORTAL_TO_ORIBOS_PHASE_3          = 357102,
    SPELL_TELEPORT_TO_PHASE_3               = 350906,
    SPELL_TELEPORT_TO_PHASE_3_DEST          = 357103,
    SPELL_FROZEN_SHELL                      = 351762,
    SPELL_BLASPHEMY_STUN                    = 357728
};

enum JainaEvents
{
    EVENT_FRIGID_SHARDS                     = 1,
    EVENT_CONE_OF_COLD,
    EVENT_COMET_BARRAGE,
    EVENT_BLINK,
    EVENT_RANDOM_MOVEMENT
};

enum JainaActions
{
    ACTION_PREPARE_ICE_BRIDGE_1             = 1,
    ACTION_PREPARE_ICE_BRIDGE_2,
    ACTION_PREPARE_ICE_BRIDGE_3
};

enum JainaTexts
{
    TALK_PREPARE_PHASE_TWO                  = 0,
    TALK_START_PHASE_TWO                    = 1,
    TALK_CALL_FOR_AID                       = 2,
    TALK_OVERRUN                            = 3,
    TALK_THANKS                             = 4,
    TALK_ENCOURAGE_PLAYERS                  = 5,
    TALK_AID_THRALL                         = 6,
    TALK_FIGHTING_SYLVANAS                  = 7,
    TALK_ASK_FOR_ANDUIN                     = 8,
    TALK_PREPARING_PORTAL_TO_PHASE_THREE    = 9,
    TALK_FINISHING_PORTAL_TO_PHASE_THREE    = 10,
    TALK_FINISHED_PORTAL_TO_PHASE_THREE     = 11
};

enum JainaVisuals
{
    SPELL_VISUAL_KIT_JAINA_BREAK_BLASPHEMY  = 149324,
    SPELL_VISUAL_KIT_JAINA_TELEPORT_PLAYERS = 149323
};

enum JainaPoints
{
    POINT_TELEPORT_TO_THIRD_CHAIN           = 1,
    POINT_TELEPORT_TO_SIXTH_CHAIN           = 2
};

enum JainaData
{
    DATA_CASTER_NON_POWERFUL_SPELL_01       = 0,
    DATA_CASTER_POWERFUL_SPELL_01           = 1,
    DATA_CASTER_NON_POWERFUL_SPELL_02       = 2,
    DATA_CASTER_POWERFUL_SPELL_02           = 3,
    DATA_CASTER_NON_POWERFUL_SPELL_03       = 4
};

Position const JainaPhaseTwoPos[10] =
{
    { 216.5781f, -831.4253f, 4999.991f, 3.7259f },
    { 211.3368f, -836.1528f, 5000.154f, 2.7889f },
    { 194.3541f, -846.6875f, 4999.989f, 2.7889f }, // Channel Ice 1
    { 182.8524f, -884.8073f, 5000.056f, 4.0016f },
    { 127.7951f, -944.7674f, 5000.001f, 3.6245f },
    { 38.60067f, -1026.189f, 5000.003f, 3.9523f }, // Channel Ice 2
    { -65.3701f, -1113.404f, 4999.985f, 3.8916f },
    { -83.2934f, -1126.055f, 4999.991f, 2.8005f }, // Channel Ice 3
    { -96.5086f, -1169.178f, 4999.938f, 3.9523f },
    { -153.118f, -1222.013f, 4999.987f, 3.7989f }
};

Position const JainaChannelIceTargetPos[3] =
{
    { 158.634f, -832.84f,  4999.5f, 4.3633f },
    { 15.0278f, -1055.03f, 4999.5f, 2.3561f },
    { -121.38f, -1112.85f, 4999.5f, 4.3633f }
};

Position const JainaPrePhaseThreePos = { -258.666f, -1284.191f, 5667.1157f, 1.58863f };

Position const PlayerPrePhaseThreePos = { -250.200f, -1292.985f, 5667.1147f, 1.53310f };

// 176533 - Jaina Proudmoore
struct npc_sylvanas_windrunner_jaina : public ScriptedAI
{
    npc_sylvanas_windrunner_jaina(Creature* creature) : ScriptedAI(creature, DATA_JAINA_PROUDMOORE_PINNACLE),
        _instance(creature->GetInstanceScript()), _casterKitCombo(0) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
    }

    void Reset() override
    {
        _events.Reset();

        _casterKitCombo = 0;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_TELEPORT_TO_THIRD_CHAIN)
            me->CastSpell(JainaPhaseTwoPos[4], SPELL_TELEPORT_PHASE_TWO_MASTER, true);
        else if (id == POINT_TELEPORT_TO_SIXTH_CHAIN)
            me->CastSpell(JainaPhaseTwoPos[8], SPELL_TELEPORT_PHASE_TWO_MASTER, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            me->GetAI()->AttackStartCaster(sylvanas, 25.0f);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OPEN_PORTAL_TO_PHASE_TWO:
            {
                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(1ms));

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 500.0f);

                    me->NearTeleportTo(JainaPhaseTwoPos[0]);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->NearTeleportTo(BolvarPrePhaseTwoPos);

                        bolvar->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), bolvar->m_Events.CalculateTime(1ms));
                    }

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        thrall->NearTeleportTo(ThrallPrePhaseTwoPos);

                        thrall->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(thrall, true), thrall->m_Events.CalculateTime(1ms));
                    }

                    _scheduler.Schedule(50ms, [playerList](TaskContext /*task*/)
                    {
                        for (Player* player : playerList)
                            player->CastSpell(player, SPELL_TELEPORT_TO_PHASE_TWO, true);
                    });

                    _scheduler.Schedule(100ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);

                        me->HandleEmoteCommand(EMOTE_STATE_READY1H_ALLOW_MOVEMENT);

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->CastSpell(bolvar, SPELL_GENERIC_ANCHOR_HERE, true);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                            thrall->CastSpell(thrall, SPELL_GENERIC_ANCHOR_HERE, true);
                    });

                    _scheduler.Schedule(150ms, [this, playerList](TaskContext /*task*/)
                    {
                        for (Player* player : playerList)
                        player->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);

                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_JAINA_KNEEL_THEN_STAND, 0, 0);

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        {
                            thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                            thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_THRALL_KNEEL_THEN_STAND, 0, 0);
                        }
                    });

                    _scheduler.Schedule(1s, [sylvanas](TaskContext /*task*/)
                    {
                        if (boss_sylvanas_windrunner* sylvanasAI = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                            sylvanasAI->TeleportShadowcopiesToMe();
                    });

                    _scheduler.Schedule(2s + 750ms, [this](TaskContext /*task*/)
                    {
                        Talk(TALK_PREPARE_PHASE_TWO);
                    });

                    _scheduler.Schedule(3s + 500ms, [this, sylvanas](TaskContext /*task*/)
                    {
                        if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00))
                            sylvanas->SetNameplateAttachToGUID(shadowCopy->GetGUID());

                        sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));

                        sylvanas->SendPlayOrphanSpellVisual(SylvanasHauntingWavePos[0], SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        if (Creature* shadowCopy = GetShadowcopy(_instance, DATA_INDEX_00))
                            shadowCopy->CastSpell(SylvanasHauntingWavePos[0], SPELL_WINDRUNNER_MOVE, true);
                    });

                    _scheduler.Schedule(4s, [this, sylvanas](TaskContext /*task*/)
                    {
                        sylvanas->NearTeleportTo(SylvanasHauntingWavePos[0]);

                        sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);

                        sylvanas->CastSpell(sylvanas, SPELL_BANSHEE_READY_STANCE, true);

                        if (Creature* jaina = _instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                            sylvanas->SetFacingToObject(jaina);

                        sylvanas->CastSpell(sylvanas, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 25050));
                    });

                    _scheduler.Schedule(5s + 578ms, [this](TaskContext /*task*/)
                    {
                        me->GetMotionMaster()->MovePoint(0, JainaPhaseTwoPos[1], false);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                            thrall->GetMotionMaster()->MovePoint(0, ThrallPhaseTwoPos[0], false);
                    });

                    _scheduler.Schedule(6s + 200ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->AI()->Talk(TALK_FIRST_CHAIN);
                    });

                    _scheduler.Schedule(6s + 890ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->GetMotionMaster()->MovePoint(0, BolvarPhaseTwoPos[1], false);
                    });

                    _scheduler.Schedule(8s + 93ms, [this](TaskContext /*task*/)
                    {
                        DoAction(ACTION_PREPARE_ICE_BRIDGE_1);
                    });
                }
                break;
            }

            case ACTION_PREPARE_ICE_BRIDGE_1:
            {
                FormFrozenBridge(JainaPhaseTwoPos[2], JainaChannelIceTargetPos[0]);

                _scheduler.Schedule(493ms, [this](TaskContext /*task*/)
                {
                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->GetMotionMaster()->MovePoint(0, ThrallPhaseTwoPos[1], false);
                });

                _scheduler.Schedule(900ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->GetMotionMaster()->MovePoint(0, BolvarPhaseTwoPos[2], false);
                });

                _scheduler.Schedule(3s + 322ms, [this](TaskContext /*task*/)
                {
                    Talk(TALK_START_PHASE_TWO);
                });

                _scheduler.Schedule(5s + 593ms, [this](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->GetAI()->DoAction(ACTION_HAUNTING_WAVE_SECOND_CHAIN);
                });

                _scheduler.Schedule(6s + 811ms, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePoint(POINT_TELEPORT_TO_THIRD_CHAIN, JainaPhaseTwoPos[3], false);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->GetMotionMaster()->MoveJump(BolvarPhaseTwoPos[3], bolvar->GetSpeed(MOVE_RUN), Movement::gravity * 1.4125f, POINT_JUMP_SECOND_CHAIN);

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->GetMotionMaster()->MoveJump(ThrallPhaseTwoPos[2], thrall->GetSpeed(MOVE_RUN), Movement::gravity * 1.4125f, POINT_JUMP_SECOND_CHAIN);
                });

                _scheduler.Schedule(10s + 639ms, [this](TaskContext /*task*/)
                {
                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        thrall->AI()->Talk(TALK_CROSSING_FIRST_BRIDGE);

                        thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_CHEERS, 0, 0);
                    }
                });

                _scheduler.Schedule(20s + 639ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->AI()->Talk(TALK_SECOND_CHAIN);
                });

                _scheduler.Schedule(29s + 685ms, [this](TaskContext /*task*/)
                {
                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->GetAI()->DoAction(ACTION_PREPARE_EARTH_BRIDGE_1);
                });
                break;
            }

            case ACTION_OPEN_PORTAL_TO_PHASE_THREE:
            {
                me->setActive(true);

                Talk(TALK_PREPARING_PORTAL_TO_PHASE_THREE);

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 250.0f);

                _scheduler.Schedule(500ms, [this, playerList](TaskContext /*task*/)
                {
                    Position dest(-233.971f, -1304.676f, 4999.984f);

                    me->NearTeleportTo(dest);

                    for (Player* player : playerList)
                        player->NearTeleportTo(dest);
                });

                _scheduler.Schedule(980ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
                });

                _scheduler.Schedule(1s + 800ms, [this](TaskContext /*task*/)
                {
                    Position const frontJainaPos = me->GetNearPosition(5.0f, 0.0f);

                    me->CastSpell(frontJainaPos, SPELL_PORTAL_TO_ORIBOS_PHASE_3);
                });

                _scheduler.Schedule(5s, [this](TaskContext /*task*/)
                {
                    Talk(TALK_FINISHING_PORTAL_TO_PHASE_THREE);

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->GetAI()->DoAction(ACTION_INITIATE_PHASE_THREE);
                });

                _scheduler.Schedule(12s, [this](TaskContext /*task*/)
                {
                    Talk(TALK_FINISHED_PORTAL_TO_PHASE_THREE);

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->SetFacingTo(4.8989f);
                });

                _scheduler.Schedule(12s + 250ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                    me->NearTeleportTo(JainaPrePhaseThreePos);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                        bolvar->NearTeleportTo(BolvarPrePhaseThreePos);
                    }

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                        thrall->NearTeleportTo(ThrallPrePhaseThreePos);
                    }
                });

                _scheduler.Schedule(12s + 300ms, [this, playerList](TaskContext /*task*/)
                {
                    for (Player* player : playerList)
                        player->CastSpell(me->GetPosition(), SPELL_TELEPORT_TO_PHASE_3, true);
                });

                _scheduler.Schedule(13s, [this, playerList](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        me->SetFacingToObject(sylvanas);

                    DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
                });

                _scheduler.Schedule(13s + 200ms, [this, playerList](TaskContext /*task*/)
                {
                    for (Player* player : playerList)
                        player->CastSpell(player, SPELL_PLATFORMS_SCENE, true);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                        anduin->GetAI()->DoAction(ACTION_INITIATE_PHASE_THREE);

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->GetAI()->DoAction(ACTION_START_TIMERS_PHASE_THREE);
                });

                _scheduler.Schedule(15s, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->AI()->Talk(TALK_PREPARE_PHASE_THREE);
                });

                _scheduler.Schedule(18s + 950ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_FROZEN_SHELL);
                });

                _scheduler.Schedule(20s, [this](TaskContext /*task*/)
                {
                    me->RemoveAura(SPELL_BLASPHEMY_STUN);
                });

                _scheduler.Schedule(20s + 200ms, [this](TaskContext /*task*/)
                {
                    me->CastStop();
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_JAINA_BREAK_BLASPHEMY, 0, 0);
                });

                _scheduler.Schedule(20s + 950ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_JAINA_TELEPORT_PLAYERS, 0, 0);
                });

                _scheduler.Schedule(22s + 122ms, [this](TaskContext /*task*/)
                {
                    Talk(TALK_ENCOURAGE_PLAYERS);
                });

                _scheduler.Schedule(23s + 122ms, [this, playerList](TaskContext /*task*/)  // CHANGE
                {
                    for (Player* player : playerList)
                    {
                        player->CastSpell(CovenantPlatformPos[0][0].GetPositionWithOffset(frand(3.0f, 10.0f)), SPELL_TELEPORT_TO_PHASE_3_DEST, true);
                        player->RemoveAura(SPELL_BLASPHEMY_STUN);
                    }

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->RemoveAura(SPELL_BLASPHEMY_STUN);

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->RemoveAura(SPELL_BLASPHEMY_STUN);
                });

                _scheduler.Schedule(24s, [this, playerList](TaskContext /*task*/)
                {
                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                    {
                        me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false), me->m_Events.CalculateTime(0ms));
                        me->GetThreatManager().ResetAllThreat();
                        me->GetThreatManager().AddThreat(anduin, 1000000);
                        AttackStartCaster(anduin, 25.0f);

                        me->CastSpell(anduin, SPELL_SEARING_BLAST);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        {
                            thrall->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(thrall, false), thrall->m_Events.CalculateTime(0ms));
                            thrall->GetThreatManager().ResetAllThreat();
                            thrall->GetThreatManager().AddThreat(anduin, 1000000);
                            thrall->GetAI()->AttackStart(anduin);
                        }

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        {
                            bolvar->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(bolvar, false), bolvar->m_Events.CalculateTime(0ms));
                            bolvar->GetThreatManager().ResetAllThreat();
                            bolvar->GetThreatManager().AddThreat(anduin, 1000000);
                            bolvar->GetAI()->AttackStart(anduin);
                        }

                        anduin->GetAI()->AttackStart(me);
                    }
                });

                _scheduler.Schedule(25s + 522ms, [this, playerList](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        sylvanas->GetAI()->DoAction(ACTION_START_PHASE_THREE);

                        for (uint8 i = 0; i < 8; i++)
                            sylvanas->CastSpell(InvigoratingFieldPos[i], SPELL_INVIGORATING_FIELD_ACTIVATE, true);
                    }

                    for (Player* player : playerList)
                        player->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_PLAYER_ACTIVATE_FIELDS, 0, 0);
                });
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoJainaAttackIfReady();
    }

    void DoJainaAttackIfReady()
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasReactState(REACT_PASSIVE))
            return;

        if (me->isAttackReady(BASE_ATTACK))
        {
            switch (_casterKitCombo)
            {
                case DATA_CASTER_NON_POWERFUL_SPELL_01:
                case DATA_CASTER_NON_POWERFUL_SPELL_02:
                case DATA_CASTER_NON_POWERFUL_SPELL_03:
                    DoCastVictim(SPELL_ICE_BOLT);
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_POWERFUL_SPELL_01:
                    DoCastVictim(SPELL_COMET_BARRAGE);
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_POWERFUL_SPELL_02:
                    DoCastVictim(me->GetDistance(me->GetVictim()) > 8.0f ? SPELL_FRIGID_SHARDS : SPELL_CONE_OF_COLD);
                    _casterKitCombo = 0;
                    break;

                default:
                    break;
            }

            me->resetAttackTimer(BASE_ATTACK);
        }
    }

    void FormFrozenBridge(Position teleportPos, Position bridgePos)
    {
        me->CastSpell(teleportPos, SPELL_TELEPORT_PHASE_TWO_MASTER);

        uint32 bridgeAreaTriggerSpell = 0;
        uint32 bridgeGameObjectSpell = 0;

        switch (uint8 randomBridge = urand(DATA_BRIDGE_PHASE_TWO_1, DATA_BRIDGE_PHASE_TWO_3))
        {
            case DATA_BRIDGE_PHASE_TWO_1:
                bridgeAreaTriggerSpell = SPELL_CHANNEL_ICE_AREATRIGGER_01;
                bridgeGameObjectSpell = SPELL_CHANNEL_ICE_BRIDGE_01;
                break;
            case DATA_BRIDGE_PHASE_TWO_2:
                bridgeAreaTriggerSpell = SPELL_CHANNEL_ICE_AREATRIGGER_02;
                bridgeGameObjectSpell = SPELL_CHANNEL_ICE_BRIDGE_02;
                break;
            case DATA_BRIDGE_PHASE_TWO_3:
                bridgeAreaTriggerSpell = SPELL_CHANNEL_ICE_AREATRIGGER_03;
                bridgeGameObjectSpell = SPELL_CHANNEL_ICE_BRIDGE_03;
                break;
            default:
                break;
        }

        _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_CHANNEL_ICE);
        });

        _scheduler.Schedule(1s + 500ms, [this, bridgePos, bridgeAreaTriggerSpell](TaskContext /*task*/)
        {
            me->CastSpell(bridgePos, bridgeAreaTriggerSpell, true);
        });

        _scheduler.Schedule(5s + 500ms, [this, bridgePos, bridgeGameObjectSpell](TaskContext /*task*/)
        {
            me->CastSpell(bridgePos, bridgeGameObjectSpell, true);
        });
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
    uint8 _casterKitCombo;
};

// 354933 - Frigid Shards
class spell_sylvanas_windrunner_frigid_shards : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_frigid_shards::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 354938 - Comet Barrage
class spell_sylvanas_windrunner_comet_barrage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_comet_barrage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 350903 - Teleport to Phase Two
class spell_sylvanas_windrunner_teleport_to_phase_two : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
            GetCaster()->CastSpell(jaina->GetRandomPoint(jaina->GetPosition(), frand(2.0f, 8.0f)), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_two::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 350906 - Teleport to Phase Three
class spell_sylvanas_windrunner_teleport_to_phase_three : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
            GetCaster()->CastSpell(jaina->GetRandomPoint(jaina->GetPosition(), frand(3.0f, 10.0f)), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357103 - Teleport
class spell_sylvanas_windrunner_teleport : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum AnduinSpells
{
    SPELL_BLASPHEMY_PRE           = 357729,
    SPELL_BLASPHEMY               = 357730,
    SPELL_BLASPHEMY_DAMAGE        = 357731,
    SPELL_CRIPPLING_DEFEAT        = 354176,

    SPELL_BREAK_PLAYER_TARGETTING = 140562
};

enum AnduinEvents
{
    EVENT_BLASPHEMY               = 1,
    EVENT_LIGHT_BLAST             = 2,
    EVENT_CRIPPLING_DEFEAT        = 3
};

// 178072 - Anduin Wrynn
struct npc_sylvanas_windrunner_anduin : public ScriptedAI
{
    npc_sylvanas_windrunner_anduin(Creature* creature) : ScriptedAI(creature, DATA_ANDUIN_CRUCIBLE),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();

        me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, true), me->m_Events.CalculateTime(0ms));
    }

    void Reset() override
    {
        _events.Reset();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 0 && roll_chance_f(20))
            DoCastSelf(SPELL_BLASPHEMY);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INITIATE_PHASE_THREE:
            {
                _events.SetPhase(PHASE_THREE);

                me->RemoveUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);

                DoCastSelf(SPELL_BLASPHEMY_PRE);

                _scheduler.Schedule(11s + 800ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_BREAK_PLAYER_TARGETTING, true);
                });

                _scheduler.Schedule(12s, [this](TaskContext /*task*/)
                {
                    me->SetUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);

                    me->m_Events.AddEvent(new PauseAttackStateOrResetAttackTimer(me, false), me->m_Events.CalculateTime(0ms));

                    _events.ScheduleEvent(EVENT_RANDOM_MOVEMENT, 18s, 20s, PHASE_THREE);
                });
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CRIPPLING_DEFEAT:
                    DoCastVictim(SPELL_CRIPPLING_DEFEAT);
                    break;

                case EVENT_RANDOM_MOVEMENT:
                    me->GetMotionMaster()->MovePoint(0, SylvanasPositionHelpers::GetRandomPointInSquaredArea(0, 0, 0, 0), false);
                    _events.Repeat(4s, 8s);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// 357729 - Blasphemy
// 357730 - Blasphemy
class spell_sylvanas_windrunner_blasphemy : public AuraScript
{
    class BlasphemyEvent : public BasicEvent
    {
    public:
        BlasphemyEvent(Unit* actor, Position const blasphemyDestPos, uint8 queuedSpell) : _actor(actor), _blasphemyDestPos(blasphemyDestPos), _queuedSpell(queuedSpell) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_queuedSpell == 0)
                _actor->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);
            else
                _actor->CastSpell(_blasphemyDestPos, SPELL_BLASPHEMY_DAMAGE, true);

            return true;
        }

    private:
        Unit* _actor;
        Position _blasphemyDestPos;
        uint8 _queuedSpell;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VISUAL_BLASPHEMY });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->m_Events.AddEvent(new BlasphemyEvent(GetTarget(), GetTarget()->GetPosition(), 0), GetTarget()->m_Events.CalculateTime(5s));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        for (uint8 i = 0; i < 20; i++)
        {
            Position blasphemyDestPos = SylvanasPositionHelpers::GetRandomPointInSquaredArea(DATA_INNER_PLATFORM, 0, 0, 0);

            float speed = 1.0f + float((0.1f * GetTarget()->GetExactDist(blasphemyDestPos)) / 3);

            GetTarget()->SendPlaySpellVisual(blasphemyDestPos, SPELL_VISUAL_BLASPHEMY, 0, 0, speed, true);

            uint32 timer = uint32(speed * 1000);

            GetTarget()->m_Events.AddEvent(new BlasphemyEvent(GetTarget(), blasphemyDestPos, 1), GetTarget()->m_Events.CalculateTime(Milliseconds(timer)));
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_blasphemy::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_blasphemy::AfterRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352312 - Energize Power Aura (Sylvanas)
class spell_sylvanas_windrunner_energize_power_aura : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        uint8 powerRegenCycle = 0;
        uint32 powerGained = 0;

        powerGained = _sylvanasPowerRegenCycle[powerRegenCycle++];

        if (powerRegenCycle >= 3)
            powerRegenCycle = 0;

        GetTarget()->ModifyPower(GetTarget()->GetPowerType(), powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_energize_power_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    // Note: Sylvanas regenerates 10 energy points every 3s roughly.
    static constexpr std::array<int32, 3> _sylvanasPowerRegenCycle = { 3, 3, 4 };
};

// 359429 - Activate Phase Intermission
class spell_sylvanas_windrunner_activate_phase_intermission : public SpellScript
{
    void OnCast(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->GetAI()->DoAction(ACTION_PREPARE_INTERMISSION);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_phase_intermission::OnCast);
    }
};

// 359431 - Activate Finish Boss
class spell_sylvanas_windrunner_activate_finish_boss : public SpellScript
{
    void OnCast(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->GetAI()->DoAction(ACTION_PREPARE_FINISH_BOSS);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_finish_boss::OnCast);
    }
};

// 355537 - Modify Champions' Faction
class spell_sylvanas_windrunner_modify_champions_faction : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_modify_champions_faction::OnApply, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_modify_champions_faction::OnRemove, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
    }
};

// 23389 - Calamity
struct at_sylvanas_windrunner_calamity : AreaTriggerAI
{
    at_sylvanas_windrunner_calamity(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        if (!_instance)
            return;
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || unit->GetGUID() != at->GetCasterGuid())
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            sylvanas->CastSpell(unit, SPELL_DOMINATION_ARROW_CALAMITY_DAMAGE, true);

            at->GetTarget()->KillSelf();

            at->Remove();
        }
    }

private:
    InstanceScript* _instance;
};

// 23028 - Rive
struct at_sylvanas_windrunner_rive : AreaTriggerAI
{
    at_sylvanas_windrunner_rive(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    class DebrisEvent : public BasicEvent
    {
    public:
        DebrisEvent(Unit* actor, Position const debrisDestPos) : _actor(actor), _debrisDestPos(debrisDestPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_debrisDestPos, SPELL_RIVEN_DEBRIS, true);

            return true;
        }

    private:
        Unit* _actor;
        Position _debrisDestPos;
    };

    void OnSplineIndexReached(int splineIndex) override
    {
        if (!_instance)
            return;

        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (splineIndex != 0 && splineIndex != 14)
        {
            for (uint8 i = 0; i < 2; i++)
            {
                Position const debrisPos = at->GetRandomNearPosition(25.0f);

                if (SylvanasFirstPhasePlatformCenter.IsInDist2d(&debrisPos, PLATFORM_RADIUS))
                {
                    float speed = frand(1.52007603645324707f, 2.203702926635742187f);

                    at->SendPlayOrphanSpellVisual(debrisPos, SPELL_VISUAL_RIVEN_DEBRIS, speed, true, false);

                    uint32 timer = uint32(speed * 1000);

                    sylvanas->m_Events.AddEvent(new DebrisEvent(sylvanas, debrisPos), sylvanas->m_Events.CalculateTime(Milliseconds(timer)));
                }
            }
        }

        if (splineIndex == 14)
            at->Remove();
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(unit, SPELL_RIVE_DAMAGE, true);
    }

private:
    InstanceScript* _instance;
};

// 5428 - Frozen Bridge, 5428 - Earthen Bridge
struct at_sylvanas_windrunner_bridges : AreaTriggerAI
{
    at_sylvanas_windrunner_bridges(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        if (!_instance)
            return;

        // Note: we modify the duration as it lasts for the rest of the encounter.
        at->SetDuration(-1);
    }

private:
    InstanceScript* _instance;
};

// 22874, 23694, 23693, 23673 - Haunting Wave
struct at_sylvanas_windrunner_haunting_wave : AreaTriggerAI
{
    at_sylvanas_windrunner_haunting_wave(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnInitialize() override
    {
        if (!_instance)
            return;

        Position originPos = at->GetPosition();

        // Note: max. distance at which the Haunting Wave travels to is 100.0f.
        float hauntingWaveXOffSet = 100.0f;

        Position destPos(originPos.GetPositionX() + (std::cos(originPos.GetOrientation()) * hauntingWaveXOffSet), originPos.GetPositionY() + (std::sin(originPos.GetOrientation()) * hauntingWaveXOffSet), originPos.GetPositionZ());

        _lastPointPos = destPos.GetPosition();

        Movement::PointsArray hauntingWaveSplinePoints;

        hauntingWaveSplinePoints.push_back(PositionToVector3(at));
        hauntingWaveSplinePoints.push_back(PositionToVector3(destPos));

        // Note: mythic difficulty has a duration of 10s, whereas the rest has a duration of 14s + 286ms.
        uint32 timeToTarget = at->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 10000 : 14286;

        uint32 millisecondsPerYard = uint32(timeToTarget / hauntingWaveXOffSet);

        at->InitSplines(hauntingWaveSplinePoints, uint32(at->GetDistance(destPos) * millisecondsPerYard));
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        float magnitude = 0.0f;

        switch (at->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
                magnitude = 4.0f;
                break;
            case DIFFICULTY_NORMAL_RAID:
                magnitude = 5.0f;
                break;
            case DIFFICULTY_HEROIC_RAID:
                magnitude = 6.0f;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                magnitude = 8.0f;
                break;
            default:
                break;
        }

        Position currentPos = at->GetPosition();

        Position vectorPos = { _lastPointPos.GetPositionX() - currentPos.GetPositionX(), _lastPointPos.GetPositionY() - currentPos.GetPositionY(), _lastPointPos.GetPositionZ() - currentPos.GetPositionZ() };

        // Note: according to Jackpoz, we need to normalize it so that it get to be 1.0f on m_positionX, but if we use this calculation on _directionPos, the force is almost completely neglected.
        //_distanceMagnitude = std::sqrt(_vectorPos.GetPositionX()  * _vectorPos.GetPositionX() + _vectorPos.GetPositionY() * _vectorPos.GetPositionY() + _vectorPos.GetPositionZ() * _vectorPos.GetPositionZ());

        Position directionPos = { vectorPos.GetPositionX() / magnitude, vectorPos.GetPositionY() / magnitude, vectorPos.GetPositionZ() / magnitude };

        unit->ApplyMovementForce(at->GetGUID(), currentPos, magnitude, MovementForceType::SingleDirectional, directionPos);

        sylvanas->CastSpell(unit, SPELL_HAUNTING_WAVE_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        unit->RemoveMovementForce(at->GetGUID());
    }

private:
    InstanceScript* _instance;
    Position _lastPointPos;
};

// 23506 - Blasphemy
struct at_sylvanas_windrunner_blasphemy : AreaTriggerAI
{
    at_sylvanas_windrunner_blasphemy(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance)
            return;

        if (unit->IsPlayer() || (!unit->IsPlayer() && (unit->GetEntry() == NPC_BOLVAR_FORDRAGON_PINNACLE || unit->GetEntry() == NPC_JAINA_PROUDMOORE_PINNACLE || unit->GetEntry() == NPC_THRALL_PINNACLE)))
        {
            if (unit->IsWithinBox(CovenantPlatformPos[4][0], 35.121147f, 35.121147f, 35.121147f) && unit->GetPositionZ() < 5668.432617f && unit->GetPositionZ() > at->GetCaster()->GetPositionZ())
                at->GetCaster()->CastSpell(unit, SPELL_BLASPHEMY_STUN, true);
        }
    }

private:
    InstanceScript* _instance;
};

// 27461 - Banshee's Bane
struct at_sylvanas_windrunner_banshee_bane : AreaTriggerAI
{
    at_sylvanas_windrunner_banshee_bane(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _readyToPick(false), _updateDiff(0) { }

    class BansheeBanePickEvent : public BasicEvent
    {
    public:
        BansheeBanePickEvent(Unit* actor, Unit* secondActor) : _actor(actor), _secondActor(secondActor) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_secondActor, SPELL_BANSHEES_BANE, true);

            return true;
        }

    private:
        Unit* _actor;
        Unit* _secondActor;
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || !_readyToPick)
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            unit->SendPlaySpellVisual(at->GetPosition(), SPELL_VISUAL_BANSHEES_BANE_ABSORB, 0, 0, 0.5f, true);

            sylvanas->m_Events.AddEvent(new BansheeBanePickEvent(sylvanas, unit), sylvanas->m_Events.CalculateTime(500ms));

            at->Remove();
        }
    }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        _scheduler.Update(diff);

        if (!_readyToPick)
        {
            _scheduler.Schedule(1s + 500ms, [this](TaskContext /*task*/)
            {
                _readyToPick = true;
            });
        }
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    bool _readyToPick;
    uint32 _updateDiff;
};

// 23117 - Raze
struct at_sylvanas_windrunner_raze : AreaTriggerAI
{
    at_sylvanas_windrunner_raze(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        for (uint8 platform = PLATFORM_MALDRAXXI; platform < PLATFORM_MAX; platform++)
        {
            if (!at->IsWithinBox(CovenantPlatformPos[platform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 17.0f, 17.0f, 17.0f))
                continue;

            if (boss_sylvanas_windrunner* sylvanasAI = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                sylvanasAI->DesecratePlatform(SylvanasPlatforms(platform));
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        at->GetCaster()->CastSpell(unit, SPELL_RAZE_PERIODIC, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        if (unit->HasAura(SPELL_RAZE_PERIODIC))
            unit->RemoveAura(SPELL_RAZE_PERIODIC);
    }

private:
    InstanceScript* _instance;
};

// 40001 - Invigorating Field
struct at_sylvanas_windrunner_invigorating_field : AreaTriggerAI
{
    at_sylvanas_windrunner_invigorating_field(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || unit->HasAura(SPELL_INVIGORATING_FIELD_JUMP))
            return;

        Position dest = unit->GetPosition();

        if ((at->GetPositionX() == -268.229f && at->GetPositionY() == -1236.99f) || (at->GetPositionX() == -268.229f && at->GetPositionY() == -1316.38f))
            dest.m_positionX += 45.0f;
        else if ((at->GetPositionX() == -289.297f && at->GetPositionY() == -1258.25f) || (at->GetPositionX() == -210.795f && at->GetPositionY() == -1257.88f))
            dest.m_positionY += -45.0f;
        else if ((at->GetPositionX() == -289.569f && at->GetPositionY() == -1294.9f) || (at->GetPositionX() == -210.512f && at->GetPositionY() == -1294.48f))
            dest.m_positionY += 45.0f;
        else
            dest.m_positionX += -45.0f;

        unit->CastSpell(Position(dest.GetPositionX(), dest.GetPositionY(), 5671.9052f), SPELL_INVIGORATING_FIELD_JUMP, true);
    }

private:
    InstanceScript* _instance;
};

// 45 - Sylvanas Windrunner's Position Z Check (Serverside)
struct at_sylvanas_windrunner_z_check : AreaTriggerAI
{
    at_sylvanas_windrunner_z_check(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsAlive())
            return;

        if (Player* player = unit->ToPlayer())
        {
            if (player->IsGameMaster())
                return;

            if (player->IsAlive())
                player->KillSelf(false);
        }
    }
};

// 46 - Sylvanas Windrunner's Conversation Introduction (Serverside)
struct at_sylvanas_windrunner_introduction : AreaTriggerAI
{
    at_sylvanas_windrunner_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)  { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            Conversation::CreateConversation(CONVERSATION_SYLVANAS_INTRODUCTION, sylvanas, sylvanas->GetPosition(), ObjectGuid::Empty);

        // Note: we're removing it to improve performance since AreaTrigger keeps using GridSearcher even if we return Update.
        at->Remove();
    }
};

// 17368 - Sylvanas Windrunner's Introduction (Conversation)
class conversation_sylvanas_windrunner_introduction : public ConversationScript
{
public:
    conversation_sylvanas_windrunner_introduction() : ConversationScript("conversation_sylvanas_windrunner_introduction") {}

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        InstanceScript* instance = creator->GetInstanceScript();
        if (!instance)
            return;

        Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE);
        if (!bolvar)
            return;

        instance->SetData(DATA_SYLVANAS_INTRODUCTION, IN_PROGRESS);

        conversation->AddActor(NPC_BOLVAR_FORDRAGON_PINNACLE, CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID, bolvar->GetGUID());

        _events.ScheduleEvent(EVENT_INTRODUCTION, 5s + 500ms);
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        uint32 eventId = _events.ExecuteEvent();

        Creature* sylvanas = nullptr;
        Creature* bolvar = nullptr;

        if (eventId)
        {
            sylvanas = conversation->GetActorCreature(CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_SYLVANAS_ID);
            if (!sylvanas)
                return;

            bolvar = conversation->GetActorCreature(CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID);
            if (!bolvar)
                return;
        }

        switch (eventId)
        {
            case EVENT_INTRODUCTION:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01, 0, 0);
                sylvanas->SetFacingToObject(bolvar);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 1, 1s + 140ms);
                break;

            case EVENT_INTRODUCTION + 1:
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[0], false);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 2, 1s + 500ms);
                break;

            case EVENT_INTRODUCTION + 2:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 3, 3s + 360ms);
                break;

            case EVENT_INTRODUCTION + 3:
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[1], false);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 4, 469ms);
                break;

            case EVENT_INTRODUCTION + 4:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 5, 3s + 500ms);
                break;

            case EVENT_INTRODUCTION + 5:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 6, 2s);
                break;

            case EVENT_INTRODUCTION + 6:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 7, 5s);
                break;

            case EVENT_INTRODUCTION + 7:
                sylvanas->SetFacingToObject(bolvar);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 8, 750ms);
                break;

            case EVENT_INTRODUCTION + 8:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 9, 457ms);
                break;

            case EVENT_INTRODUCTION + 9:
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[2], false);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 10, 5s + 89ms);
                break;

            case EVENT_INTRODUCTION + 10:
                bolvar->SetFacingToObject(sylvanas);
                bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 11, 13s + 567ms);
                break;

            case EVENT_INTRODUCTION + 11:
                sylvanas->SetFacingToObject(bolvar);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 12, 484ms);
                break;

            case EVENT_INTRODUCTION + 12:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 13, 5s + 516ms);
                break;

            case EVENT_INTRODUCTION + 13:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 14, 1s + 516ms);
                break;

            case EVENT_INTRODUCTION + 14:
                sylvanas->NearTeleportTo(SylvanasIntroPos[3], false);
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 15, 1s + 265ms);
                break;

            case EVENT_INTRODUCTION + 15:
                sylvanas->SetFacingToObject(bolvar);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 16, 969ms);
                break;

            case EVENT_INTRODUCTION + 16:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 17, 4s + 766ms);
                break;

            case EVENT_INTRODUCTION + 17:
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10, 0, 0);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 18, 3s + 250ms);
                break;

            case EVENT_INTRODUCTION + 18:
                sylvanas->CastSpell(sylvanas, SPELL_RANGER_BOW_STANCE);
                _events.ScheduleEvent(EVENT_INTRODUCTION + 19, 16ms);
                break;

            case EVENT_INTRODUCTION + 19:
                sylvanas->CastSpell(sylvanas, SPELL_GENERIC_ANCHOR_HERE);
                if (InstanceScript* instance = sylvanas->GetInstanceScript())
                    instance->SetData(DATA_SYLVANAS_INTRODUCTION, DONE);
                break;

            default:
                break;
        }
    }

private:
    EventMap _events;
};
 
// 2799 - Sylvanas Windrunner's Intermission Scene
class scene_sylvanas_windrunner_intermission : public SceneScript
{
public:
    scene_sylvanas_windrunner_intermission() : SceneScript("scene_sylvanas_windrunner_intermission") { }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
            return;

        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(DATA_SYLVANAS_INTERMISSION_FINISH, 1);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
            return;

        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(DATA_SYLVANAS_INTERMISSION_FINISH, 1);
    }
};

// 2798 - Sylvanas Windrunner's Finish Scene
class scene_sylvanas_windrunner_finish : public SceneScript
{
public:
    scene_sylvanas_windrunner_finish() : SceneScript("scene_sylvanas_windrunner_finish") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->GetAreaId() != AREA_THE_CRUCIBLE)
            return;

        player->CastSpell(player, SPELL_FINAL_CINEMATIC, true);
    }
};

void AddSC_boss_sylvanas_windrunner()
{
    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy_riding);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_domination_arrow);

    RegisterSpellAndAuraScriptPair(spell_sylvanas_windrunner_ranger_bow, spell_sylvanas_windrunner_ranger_bow_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_dagger);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_shot);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_strike);
    RegisterSpellScript(spell_sylvanas_windrunner_windrunner);
    RegisterSpellScript(spell_sylvanas_windrunner_disappear);
    RegisterSpellScript(spell_sylvanas_windrunner_withering_fire);
    RegisterSpellScript(spell_sylvanas_windrunner_desecrating_shot);
    RegisterSpellScript(spell_sylvanas_windrunner_heartseeker);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chains);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_trigger);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_raid_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_debuff);
    RegisterSpellScript(spell_sylvanas_windrunner_rive);
    RegisterSpellScript(spell_sylvanas_windrunner_rive_areatrigger);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_marker);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_triggered_missile);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_interrupt);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_form);
    RegisterSpellScript(spell_sylvanas_windrunner_haunting_wave);
    RegisterSpellScript(spell_sylvanas_windrunner_ruin);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_2);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_2);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_area_phase_2);
    RegisterSpellScript(spell_sylvanas_windrunner_bane_arrows);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_bane);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_fury);
    RegisterSpellScript(spell_sylvanas_windrunner_raze);
    RegisterSpellScript(spell_sylvanas_windrunner_sylvanas_push);
    RegisterSpellScript(spell_sylvanas_shadow_dagger_phase_three);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_3);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_3);

    RegisterSpellScript(spell_sylvanas_windrunner_energize_power_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_phase_intermission);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_finish_boss);
    RegisterSpellScript(spell_sylvanas_windrunner_modify_champions_faction);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_bolvar);
    RegisterSpellScript(spell_sylvanas_windrunner_runic_mark_triggered);
    RegisterSpellScript(spell_sylvanas_windrunner_charge_towards_sylvanas);
    RegisterSpellScript(spell_sylvanas_windrunner_winds_of_icecrown);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_thrall);
    RegisterSpellScript(spell_sylvanas_windrunner_pulverize);
    RegisterSpellScript(spell_sylvanas_windrunner_pulverize_triggered);
    RegisterSpellScript(spell_sylvanas_windrunner_stonecrash_phase_one_and_three);
    RegisterSpellScript(spell_sylvanas_windrunner_stonecrash_phase_two);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_jaina);
    RegisterSpellScript(spell_sylvanas_windrunner_frigid_shards);
    RegisterSpellScript(spell_sylvanas_windrunner_comet_barrage);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_two);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_three);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_anduin);
    RegisterSpellScript(spell_sylvanas_windrunner_blasphemy);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_calamity);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_rive);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_bridges);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_haunting_wave);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_blasphemy);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_banshee_bane);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_raze);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_invigorating_field);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_introduction);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_z_check);

    new conversation_sylvanas_windrunner_introduction();
    new scene_sylvanas_windrunner_intermission();
    new scene_sylvanas_windrunner_finish();
}
