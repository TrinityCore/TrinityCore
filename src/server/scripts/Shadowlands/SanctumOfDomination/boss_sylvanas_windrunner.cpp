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
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "UpdateFields.h"
#include "G3D/Vector2.h"
#include "sanctum_of_domination.h"

enum Spells
{
    // Stances
    SPELL_RANGER_BOW_STANCE                             = 347560,
    SPELL_RANGER_DAGGERS_STANCE                         = 348010,

    // Ranger Shot
    SPELL_RANGER_SHOT                                   = 347548,

    // Ranger Strike
    SPELL_RANGER_STRIKE                                 = 348299,

    // Windrunner
    SPELL_WINDRUNNER                                    = 347504,
    SPELL_WINDRUNNER_DISAPPEAR_01                       = 352303,
    SPELL_WINDRUNNER_DISAPPEAR_02                       = 358975,
    SPELL_WINDRUNNER_SPIN                               = 351187,
    SPELL_WINDRUNNER_MOVE                               = 347606,
    SPELL_WINDRUNNER_SHOT_01                            = 347604, // Not on the sniff
    SPELL_WINDRUNNER_JUMP_02                            = 347605, // Not on the sniff
    SPELL_WINDRUNNER_DAGGER_01                          = 350737, // Not on the sniff
    SPELL_WINDRUNNER_BANSHEE                            = 352211,

    // Shadow Dagger
    SPELL_SHADOW_DAGGER_COPY                            = 358964,
    SPELL_SHADOW_DAGGER                                 = 347670,
    SPELL_SHADOW_DAGGER_AOE                             = 353935,
    SPELL_SHADOW_DAGGER_MISSILE                         = 348089,
    SPELL_SHADOW_DAGGER_PHASE_TWO_AND_THREE             = 353935,

    // Withering Fire
    SPELL_WITHERING_FIRE_COPY                           = 358981,
    SPELL_WITHERING_FIRE                                = 347928,
    SPELL_BARBED_ARROW                                  = 347807,

    // Desecrating Shot
    SPELL_DESECRATING_SHOT_AREATRIGGER                  = 348626,
    SPELL_DESECRATING_SHOT                              = 350652,
    SPELL_DESECRATING_SHOT_JUMP_FRONT                   = 347957,
    SPELL_DESECRATING_SHOT_JUMP_LEFT                    = 356191,
    SPELL_DESECRATING_SHOT_JUMP_STRAIGHT_ARROW          = 358993,
    SPELL_DESECRATING_SHOT_TRIGGERED                    = 348627,

    // Ranger Heartseeker
    SPELL_RANGER_HEARTSEEKER_AURA                       = 352649,
    SPELL_RANGER_HEARTSEEKER_CHARGE                     = 352650,
    SPELL_RANGER_HEARTSEEKER                            = 352663,
    SPELL_RANGER_HEARTSEEKER_PHYSICAL_DAMAGE            = 352651,
    SPELL_RANGER_HEARTSEEKER_SHADOW_DAMAGE              = 352652,
    SPELL_BANSHEE_MARK                                  = 347607,

    // Wailing Arrow
    SPELL_WAILING_ARROW_POINTER                         = 348064,
    SPELL_WAILING_ARROW                                 = 347609,

    // Domination Chains
    SPELL_DOMINATION_CHAINS                             = 349419,
    SPELL_DOMINATION_CHAINS_JUMP                        = 347602,
    SPELL_DOMINATION_ARROW_SHOT_VISUAL                  = 350426,
    SPELL_DOMINATION_ARROW_FALL                         = 352317,
    SPELL_DOMINATION_ARROW_FALL_AND_VISUAL              = 352319,
    SPELL_DOMINATION_ARROW_ACTIVATE                     = 356650,
    SPELL_DOMINATION_ARROW_CALAMITY_VISUAL              = 356769,
    SPELL_DOMINATION_ARROW_CALAMITY_AREATRIGGER         = 356624,
    SPELL_DOMINATION_ARROW_CALAMITY_DAMAGE              = 356649,

    SPELL_DOMINATION_CHAIN_PLAYER                       = 349451,
    SPELL_DOMINATION_CHAIN_PERIODIC                     = 349458,

    // Veil of Darkness (Generic)
    SPELL_VEIL_OF_DARKNESS_DESELECT                     = 354366,
    SPELL_VEIL_OF_DARKNESS_SCREEN_FOG                   = 354580,
    SPELL_VEIL_OF_DARKNESS_ABSORB_AURA                  = 347704,
    SPELL_VEIL_OF_DARKNESS_VISUAL_SPREAD                = 355749,

    // Veil of Darkness (Phase 1)
    SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE                 = 352470,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW                 = 350335,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_AREA                 = 357726,
    SPELL_VEIL_OF_DARKNESS_PHASE_1                      = 347726,

    // Banshee Shroud
    SPELL_BANSHEE_SHROUD                                = 350857,

    // Rive
    SPELL_RIVE_DISAPPEAR                                = 353519,
    SPELL_RIVE                                          = 353417,
    SPELL_RIVE_FAST                                     = 353418,
    SPELL_RIVE_MARKER_AREATRIGGER                       = 353419,
    SPELL_RIVE_CHAIN                                    = 353504,
    SPELL_RIVE_CHAIN_FAST                               = 353510,
    SPELL_RIVE_AREATRIGGER                              = 353375,
    SPELL_RIVE_DAMAGE                                   = 348145,
    SPELL_RIVEN_DEBRIS                                  = 353413,
    SPELL_RIVE_MYTHIC_COPY                              = 358431,

    // Banshee Wail
    SPELL_BANSHEE_WAIL                                  = 348094,
    SPELL_BANSHEE_WAIL_TRIGGERED_MISSILE                = 348108,
    SPELL_BANSHEE_WAIL_MISSILE                          = 348133,
    SPELL_BANSHEE_WAIL_SILENCE                          = 351253,
    SPELL_BANSHEE_WAIL_MARKER                           = 357719,
    SPELL_BANSHEE_WAIL_EXPIRE                           = 355489,

    SPELL_TELEPORT_TO_PHASE_TWO                         = 350903,
    SPELL_TELEPORT_NO_IDEA                              = 350905, // TARGET_DEST_DB, not sniffed

    // Banshee Form
    SPELL_BANSHEE_FORM                                  = 348146,
    SPELL_BANSHEE_READY_STANCE                          = 357758,

    // Haunting Wave
    SPELL_HAUNTING_WAVE                                 = 352271,
    SPELL_HAUNTING_WAVE_DAMAGE                          = 351870,

    SPELL_CALL_EARTH_DEBRIS                             = 355491,

    // Ruin
    SPELL_RUIN                                          = 355540,
    SPELL_RUIN_VISUAL                                   = 358990,

    // Veil of Darkness (Phase 2)
    SPELL_VEIL_OF_DARKNESS_PHASE_2_FADE                 = 353273,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_GROW                 = 352239,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA                 = 352225,
    SPELL_VEIL_OF_DARKNESS_PHASE_2                      = 347741,

    // Invigorating Field
    SPELL_INVIGORATING_FIELD_ACTIVATE                   = 353660,
    SPELL_INVIGORATING_FIELD                            = 354175,
    SPELL_INVIGORATING_FIELD_JUMP                       = 353642,

    // Platform Change
    SPELL_SWITCH_PLATFORM_STOMP                         = 354141, // 27887 areatrigger forces MovementForce 1 with Magnitude -14 on players for 150ms

    // Banshee's Heartseeker
    SPELL_BANSHEES_HEARTSEEKER_AURA                     = 353966,
    SPELL_BANSHEES_HEARTSEEKER_CHARGE                   = 353965,
    SPELL_BANSHEES_HEARTSEEKER                          = 353969,
    SPELL_BANSHEES_HEARTSEEKER_PHYSICAL_DAMAGE          = 353968,
    SPELL_BANSHEES_HEARTSEEKER_SHADOW_DAMAGE            = 353967,

    // Banshee's Bane
    SPELL_BANSHEES_BANE                                 = 353929,
    SPELL_BANSHEES_BANE_AREATRIGGER                     = 353930,

    // Bane Arrows
    SPELL_BANE_ARROWS                                   = 354011,
    SPELL_BANE_ARROWS_DAMAGE                            = 353972,

    // Banshee's Blades
    SPELL_BANSHEE_BLADE_PHYSICAL_DAMAGE                 = 358182,
    SPELL_BANSHEE_BLADE_SHADOW_DAMAGE                   = 358183,

    // Banshee Scream
    SPELL_BANSHEE_SCREAM                                = 353952,

    // Veil of Darkness (Phase 3)
    SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE                 = 354168,
    SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW                 = 354143,
    SPELL_VEIL_OF_DARKNESS_PHASE_3                      = 354142,
    SPELL_VEIL_OF_DARKNESS_PHASE_3_TARGETED             = 357876,

    // Banshee's Fury
    SPELL_BANSHEES_FURY                                 = 354068,
    SPELL_BANSHEES_FURY_EXPLODE                         = 357526,

    // Raze
    SPELL_RAZE                                          = 354147,
    SPELL_RAZE_PERIODIC                                 = 354146,

    // The Jailer
    SPELL_JAILER_GROW_SOULS                             = 355347,
    SPELL_JAILER_CAST_SOULS                             = 355348,

    // Anduin Wrynn
    SPELL_FOCUSING_PRISM_AURA                           = 358166, // Related to the achievement

    // Miscelanea
    SPELL_ANCHOR_HERE                                   = 45313,
    SPELL_SYLVANAS_ROOT                                 = 347608,
    SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING              = 352311,
    SPELL_DUAL_WIELD                                    = 42459,
    SPELL_SYLVANAS_POWER_ENERGIZE_AURA                  = 352312,

    SPELL_INTERMISSION_STUN                             = 355488,
    SPELL_INTERMISSION_SCENE                            = 359062,
    SPELL_PLATFORMS_SCENE                               = 350943,
    SPELL_FINAL_SCENE                                   = 358806,
    SPELL_FINAL_CINEMATIC                               = 358985,
    SPELL_SYLVANAS_REWARD_ACHIEVEMENT                   = 358178,
    SPELL_SYLVANAS_UNK_05                               = 353687, // NPC 179262 casts it at the end of the encounter before Sylvanas teleports to its dead pos and casts feign death
    SPELL_SYLVANAS_FEIGN_DEATH                          = 358844,

    SPELL_HEALTH_PCT_CHECK_INTERMISSION                 = 358794,
    SPELL_ACTIVATE_INTERMISSION                         = 359429,
    SPELL_HEALTH_PCT_CHECK_FINISH                       = 359430,
    SPELL_ACTIVATE_FINISH                               = 359431
};

enum Phases
{
    PHASE_NONE                                          = 0,  
    PHASE_ONE                                           = 1,
    PHASE_INTERMISSION                                  = 4,
    PHASE_TWO                                           = 2,
    PHASE_THREE                                         = 3,
    PHASE_INTERMISSION_WORLD_STATE                      = 11
};

enum Events
{
    EVENT_WINDRUNNER                                    = 1,
    EVENT_WITHERING_FIRE                                = 10,
    EVENT_SHADOW_DAGGERS                                = 30,
    EVENT_DESECRATING_SHOT,
    EVENT_DESECRATING_SHOT_LAUNCH,
    EVENT_DOMINATION_CHAINS                             = 50,
    EVENT_DOMINATION_CHAINS_JUMP                        = 65,
    EVENT_WAILING_ARROW,
    EVENT_VEIL_OF_DARKNESS,
    EVENT_RIVE,
    EVENT_FINISH_INTERMISSION,
    EVENT_BANE_ARROWS,
    EVENT_RAZE,
    EVENT_BANSHEE_SCREAM,
    EVENT_BANSHEES_FURY
};

enum GroupEvent
{
    GROUP_EVENT_NORMAL_EVENTS                           = 1,
    GROUP_EVENT_WINDRUNNER_RELATED_EVENTS               = 2,
    GROUP_EVENT_WAILING_ARROW_EVENTS                    = 3
};

enum Actions
{
    ACTION_WINDRUNNER_MODEL_ACTIVATE                    = 1,
    ACTION_WINDRUNNER_MODEL_DEACTIVATE,
    ACTION_RESET_MELEE_KIT,
    ACTION_ACTIVATE_DOMINATION_ARROW,
    ACTION_RANGER_HEARTSEEKER,
    ACTION_START_WITHERING_FIRE,
    ACTION_START_DOMINATION_CHAINS,
    ACTION_CALCULATE_ARROWS,
    ACTION_FINISH_DOMINATION_CHAINS,
    ACTION_WAILING_ARROW,
    ACTION_PREPARE_INTERMISSION,
    ACTION_OPEN_PORTAL_TO_PHASE_TWO,
    ACTION_HAUNTING_WAVE_SECOND_CHAIN,
    ACTION_WINDS_OF_ICECROWN_PRE,
    ACTION_PREPARE_PHASE_THREE,
    ACTION_OPEN_PORTAL_TO_PHASE_THREE,
    ACTION_INITIATE_PHASE_THREE,
    ACTION_START_PHASE_THREE,
    ACTION_PREPARE_FINISH_BOSS
};

enum Texts
{
    SAY_AGGRO                                           = 0,
    SAY_SLAY                                            = 1,
    SAY_DISENGAGE                                       = 2,
    SAY_ANNOUNCE_WINDRUNNER                             = 3,
    SAY_SHADOW_DAGGER                                   = 4,
    SAY_DESECRATING_SHOT                                = 5,
    SAY_ANNOUNCE_WAILING_ARROW                          = 6,
    SAY_ANNOUNCE_WAILING_ARROW_AFFECTED                 = 7,
    SAY_WAILING_ARROW                                   = 8,
    SAY_ANNOUNCE_DOMINATION_CHAINS                      = 9,
    SAY_DOMINATION_CHAINS                               = 10,
    SAY_ANNOUNCE_VEIL_OF_DARKNESS                       = 11,
    SAY_VEIL_OF_DARKNESS_PHASE_ONE                      = 12,
    SAY_INTERMISSION_BEGIN                              = 13,
    SAY_ANNOUNCE_BANSHEE_WAIL                           = 14,
    SAY_INTERMISSION_END                                = 15,
    SAY_ANNOUNCE_HAUNTING_WAVE                          = 16,
    SAY_ANNOUNCE_RUIN                                   = 17,
    SAY_WINDS_OF_ICECROWN_AFTER_01                      = 18,
    SAY_VEIL_OF_DARKNESS_PHASE_TWO_AND_THREE            = 19,
    SAY_ANNOUNCE_BANSHEE_SCREAM                         = 20,
    SAY_BANSHEE_SCREAM                                  = 21,
    SAY_WINDS_OF_ICECROWN_AFTER_02                      = 22,
    SAY_START_PHASE_THREE                               = 23,
    SAY_BANSHEES_FURY                                   = 24,
    SAY_ANNOUNCE_RAZE                                   = 25
};

enum Conversations
{
    CONVERSATION_INTRO                                  = 17368
};

enum SpawnGroups
{
    SPAWN_GROUP_INITIAL                                 = 0
};

enum Points
{
    POINT_INTRO_01                                      = 1,
    POINT_INTRO_02                                      = 2,
    POINT_INTRO_03                                      = 3,
    POINT_INTRO_FINISHED                                = 4
};

enum SpellVisualKits
{
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01      = 150067,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02      = 150068,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03      = 150069,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04      = 150071,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05      = 150072,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06      = 150070,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07      = 150074,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08      = 150077,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09      = 150076,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10      = 150075,
    SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01        = 150073,

    SPELL_VISUAL_KIT_SYLVANAS_DOMINATION_CHAINS_FINISH  = 142405,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW             = 143939,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN        = 142389,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS         = 143940,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN    = 142388,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS          = 142021,
    SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK                = 145541,
    SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK_FAST           = 145608,
    SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_BANSHEE    = 146063,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE     = 148298,
    SPELL_VISUAL_KIT_SYLVANAS_WINDS_01                  = 149160,
    SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED          = 145486,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_TELEPORT          = 148270,
    SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_HUMAN      = 146626,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER             = 145482,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER_SOUND       = 145850,
    SPELL_VISUAL_KIT_SYLVANAS_WITHERING_FIRE_PHASE_TWO  = 149795,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_VEIL_OF_DARKNESS1 = 144927,
    SPELL_VISUAL_KIT_SYLVANAS_WINDS_02                  = 149161,
    SPELL_VISUAL_KIT_SYLVANAS_DARK_FOG                  = 150066,
    SPELL_VISUAL_KIT_SYLVANAS_STOMP                     = 148200,
    SPELL_VISUAL_KIT_SYLVANAS_SWITCH_PLATFORM           = 149580,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM            = 146059,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_BANE_ARROWS       = 145872,
    SPELL_VISUAL_KIT_SYLVANAS_BLACKEN_WITH_DAGGERS      = 149487, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_DISAPPEAR_MODEL           = 149491, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_TELEPORT                  = 150078,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_01     = 148191,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_02     = 148193,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_03     = 148192,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_FURY_END          = 148130,

    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_VEIL_OF_DARKNESS2 = 144927, // Same as 17

    SPELL_VISUAL_KIT_JAINA_KNEEL_THEN_STAND             = 146285,
    SPELL_VISUAL_KIT_JAINA_FROZEN_BRIDGE                = 142472, // NOT ON SNIFF

    SPELL_VISUAL_KIT_THRALL_KNEEL_THEN_STAND            = 147632,
    SPELL_VISUAL_KIT_THRALL_EARTHEN_BRIDGE              = 142473,

    SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY            = 148315,

    SPELL_VISUAL_KIT_JAILER_IDK_01                      = 149329,

    SPELL_VISUAL_KIT_PLAYER_ACTIVATE_FIELDS             = 144754,

    SPELL_VISUAL_KIT_GENERIC_TELEPORT                   = 147629,
    SPELL_VISUAL_KIT_GENERIC_CHEERS                     = 147631,
};

enum SpellVisuals
{
    SPELL_VISUAL_RANGER_STRIKE_RIGHT                    = 106153, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_LEFT                     = 106160, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_01                       = 106165, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_03                       = 106161, // At 1.0f
    SPELL_VISUAL_WINDRUNNER_01                          = 107722, // At 0.5f
    SPELL_VISUAL_WINDRUNNER_02                          = 110312, // At 0.25f
    SPELL_VISUAL_WINDRUNNER_03                          = 107920, // At 0.25f
    SPELL_VISUAL_DESECRATING_ARROW                      = 106363, // At 0.40f - 0.12f
    SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE               = 105944, // At 48.0f, false as time
    SPELL_VISUAL_HEARTSEEKER                            = 107607, // At 36f, false as time
    SPELL_VISUAL_DOMINATION_ARROW                       = 107501, // At 2.5f
    SPELL_VISUAL_DOMINATION_ARROW_SPAWN                 = 109620, // At 2.5f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_NM           = 109159, // At 5.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_HC           = 107567, // At 5.0f
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK                   = 108070,
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST              = 108071,
    SPELL_VISUAL_RIVEN_DEBRIS                           = 107877, // At 1.744643688201904296f - 1.616904616355895996f
    SPELL_VISUAL_WITHERING_FIRE_PHASE_TWO               = 110435, // At 3.5f - 2.7f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_02_03           = 109371, // At 3.0f
    SPELL_VISUAL_BANE_ARROW                             = 108112, // At 3.2f - 2.04f
    SPELL_VISUAL_BANSHEE_FURY                           = 108130, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE                                   = 110336, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE_MISSILE                           = 108154, // At 0.33f - 0.14f
    SPELL_VISUAL_BLASPHEMY                              = 109680, // At 1.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_3_HC            = 105852, // At 3.0f
    SPELL_VISUAL_JAILER_BOLT                            = 107337, // At 90.0f, false as time
    SPELL_VISUAL_BANSHEES_BANE_ABSORB                   = 108093, // At 0.5f
    SPELL_VISUAL_BANSHEES_BANE_DROP                     = 107839, // At 0.349999994039535522f

    SPELL_VISUAL_UNK_02                                 = 108094, // At 1.5f
    SPELL_VISUAL_SHADOW_DAGGER                          = 108096, // At 100.0f, false as time
    SPELL_VISUAL_MOST_LIKELY_SPREAD_OUT_FOG             = 108092, // At 0.64f - 0.52f
    SPELL_VISUAL_UNK01_177054                           = 107069, // At 1.0f
    SPELL_VISUAL_BANSHEE_FURY_IDK                       = 107476, // At 1.5f
    SPELL_VISUAL_UNK01_177787                           = 107063  // At 1.0f
};

enum Miscellanea
{
    DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL                  = 101311,
    DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL              = 100930,

    DATA_MELEE_COMBO_SWITCH_TO_MELEE                    = 0,
    DATA_MELEE_COMBO_RANGER_STRIKE_01                   = 1,
    DATA_MELEE_COMBO_RANGER_STRIKE_02                   = 2,
    DATA_MELEE_COMBO_SWITCH_TO_RANGED                   = 3,
    DATA_MELEE_COMBO_FINISH                             = 4,

    DATA_CHANGE_SHEATHE_TO_UNARMED                      = 0,
    DATA_CHANGE_SHEATHE_TO_MELEE                        = 1,
    DATA_CHANGE_SHEATHE_TO_RANGED                       = 2,
    DATA_CHANGE_NAMEPLATE_TO_COPY                       = 3,
    DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY                = 4,
    DATA_CHANGE_NAMEPLATE_TO_SYLVANAS                   = 5,
    DATA_CHANGE_ATTACK_SPEED_TO_LOWEST                  = 6,
    DATA_CHANGE_ATTACK_SPEED_TO_HIGHEST                 = 7,

    DATA_EVENT_TYPE_SHADOWCOPY                          = 1,
    DATA_EVENT_COPY_NO_EVENT                            = 1,
    DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT              = 2,

    DATA_AREATRIGGER_DOMINATION_ARROW                   = 27683,

    DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR              = 1,

    DATA_WINDRUNNER_CAST_TIME_ONE                       = 1,
    DATA_WINDRUNNER_CAST_TIME_TWO                       = 2,
    DATA_WINDRUNNER_CAST_TIME_THREE                     = 3,
    DATA_WINDRUNNER_CAST_TIME_FOUR                      = 4,
    DATA_WINDRUNNER_CAST_TIME_FIVE                      = 5,

    DATA_DESECRATING_SHOT_PATTERN_STRAIGHT              = 1,
    DATA_DESECRATING_SHOT_PATTERN_SCATTERED             = 2,
    DATA_DESECRATING_SHOT_PATTERN_WAVE                  = 3,
    DATA_DESECRATING_SHOT_PATTERN_SPIRAL                = 4,
    DATA_DESECRATING_SHOT_PATTERN_JAR                   = 5,

    DATA_JUMP_TIME_CERO                                 = 1,
    DATA_JUMP_TIME_ONE                                  = 2,
    DATA_JUMP_TIME_TWO                                  = 3,
    DATA_JUMP_TIME_THREE                                = 4,
    DATA_JUMP_TIME_FOUR                                 = 5,

    DATA_BRIDGE_PHASE_TWO_1                             = 1,
    DATA_BRIDGE_PHASE_TWO_2                             = 2,
    DATA_BRIDGE_PHASE_TWO_3                             = 3,

    DATA_BRIDGE_PHASE_TWO_COUNT_1                       = 1,
    DATA_BRIDGE_PHASE_TWO_COUNT_2                       = 2,
    DATA_BRIDGE_PHASE_TWO_COUNT_3                       = 3,
    DATA_BRIDGE_PHASE_TWO_COUNT_4                       = 4,
    DATA_BRIDGE_PHASE_TWO_COUNT_5                       = 5,
    DATA_BRIDGE_PHASE_TWO_COUNT_6                       = 6,

    DATA_MALDRAXXI_PLATFORM                             = 0,
    DATA_NIGHTFAE_PLATFORM                              = 1,
    DATA_KYRIAN_PLATFORM                                = 2,
    DATA_VENTHYR_PLATFORM                               = 3,

    DATA_MIDDLE_POS_OUTTER_PLATFORM                     = 0,
    DATA_TOP_RIGHT_POS_VERTEX_PLATFORM                  = 1,
    DATA_BOTTOM_LEFT_POS_VERTEX_PLATFORM                = 2
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

// TODO: remove this.
Position const SylvanasWitheringFireTestPos[5] =
{
    { 253.3075f, -830.7087f, 4104.9900f },
    { 250.9643f, -820.1835f, 4104.9900f },
    { 246.7454f, -815.5137f, 4104.9900f },
    { 239.9896f, -811.9060f, 4104.9900f },
    { 232.9633f, -810.9619f, 4104.9900f }
};

Position const SylvanasVeilOnePos =   { 255.0392f, -824.6999f, 4205.122f };

Position const DesecratingShotArrowShape[5] =
{
    { -0.43609f,  4.98095f, 4105.0386f  },
    {  2.38811f,  4.82665f, 4105.0386f  },
    {  5.21233f,  4.67245f, 4105.0386f  },
    {  5.05808f,  1.84821f, 4105.0386f  },
    {  4.90381f, -0.97601f, 4105.0386f  }
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

Position LastFrontSpiralPoint = { 0.0f, 0.0f, 0.0f };
Position LastLeftSpiralPoint = { 0.0f, 0.0f, 0.0f };
Position LastRightSpiralPoint = { 0.0f, 0.0f, 0.0f };

Position const RiveThrowPos[8] =
{
    { 166.617f, -856.656f, 4113.2285f },
    { 208.542f, -761.602f, 4113.2285f },
    { 303.332f, -803.056f, 4113.2285f },
    { 302.793f, -858.021f, 4113.2285f },
    { 183.836f, -777.633f, 4113.2285f },
    { 206.884f, -897.526f, 4113.2285f },
    { 261.473f, -898.365f, 4113.2285f },
    { 287.948f, -778.238f, 4113.2285f }
};

Position const RiveFinishPos =        { 235.1163f, -829.901f,  4105.0386f, 5.4824f   };

Position const SylvanasPhase2PrePos = { -14.5625f, -943.441f,   4999.990f,  0.8928f   };

Position const SylvanasWavePos[10] =
{
    { 133.5104f, -829.4792f, 4999.968f, 0.4383f },
    { 91.66666f, -835.0868f, 4999.968f, 0.4383f },
    { 92.41319f, -883.3455f, 4999.968f, 1.2723f },
    { 56.42536f, -902.6979f, 4999.968f, 1.1349f },
    { 19.02257f, -892.4983f, 4999.968f, 0.3612f }
};

Position const SylvanasPhase3PrePos = { -258.991f, -1265.996f,  5667.114f,  0.3118f   };

Position const SylvanasPhase3Pos =    { -280.646f, -1245.48f,   5672.13f,   2.3046f   };

// Note: middle is 0, top right is 1, bottom left is 2.
Position const CovenantPlatformPos[4][3] =
{
    // Maldraxxi
    {
        { -289.9608f, -1236.4189f, 5671.9052f, 0.0f },
        { -271.2141f, -1255.5200f, 5671.6704f },
        { -308.6874f, -1218.0043f, 5671.6704f }
    },

    // Nightfae
    {
        { -290.2621f, -1316.9971f, 5671.9067f, 0.0f },
        { -271.2889f, -1335.1152f, 5671.6704f },
        { -308.4179f, -1297.5373f, 5671.6704f }
    },

    // Kyrian
    {
        { -209.5206f, -1316.5284f, 5671.9052f, 0.0f },
        { -191.8095f, -1334.5333f, 5671.6704f },
        { -228.8465f, -1297.1842f, 5671.6704f }
    },

    // Venthyr
    {
        { -210.2180f, -1236.2922f, 5671.9067f, 0.0f },
        { -192.2238f, -1254.8327f, 5671.6704f },
        { -229.1900f, -1217.7504f, 5671.6704f }
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

static Position GetRandomPointInCovenantPlatform(Position const& a, Position const& b, float c)
{
    float x = frand(std::min(a.GetPositionX(), b.GetPositionX()), std::max(a.GetPositionX(), b.GetPositionX()));
    float y = frand(std::min(a.GetPositionY(), b.GetPositionY()), std::max(a.GetPositionY(), b.GetPositionY()));
    float z = c;

    return Position(x, y, z);
}

Position const SylvanasVeilThreePos = { -286.978f, -1245.2378f, 5772.0347f, 0.0f       };

Position const SylvanasEndPos =       { -249.876f, -1252.4791f, 5667.1157f, 3.3742f    };

UnitAI* GetShadowcopyAI(InstanceScript* instance, uint8 copyIndex)
{
    Creature* shadowCopy = instance->instance->GetCreature(instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_01 + copyIndex));
    if (!shadowCopy)
        return nullptr;

    return shadowCopy->AI();
}

class SylvanasNonMeleeSelector
{
    public:
        SylvanasNonMeleeSelector(Unit const* obj) : _sourceObj(obj) { }

        bool operator()(Unit* unit) const
        {
            if (!unit->ToPlayer()->IsPlayer() || sChrSpecializationStore.AssertEntry(unit->ToPlayer()->GetPrimarySpecialization())->Flags & CHR_SPECIALIZATION_FLAG_MELEE)
                return false;
            return true;
        }

    private:
        Unit const* _sourceObj;
};

class PauseAttackState : public BasicEvent
{
    public:
        PauseAttackState(Unit* actor, bool paused) : _actor(actor), _paused(paused) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_paused)
            {
                _actor->InterruptNonMeleeSpells(false);
                _actor->GetMotionMaster()->Clear();
                _actor->StopMoving();
                if (_actor->GetEntry() != BOSS_SYLVANAS_WINDRUNNER)
                    _actor->AttackStop();

                _actor->ToCreature()->SetReactState(REACT_PASSIVE);
            }
            else
            {
                _actor->ToCreature()->SetReactState(REACT_AGGRESSIVE);

                if (_actor->GetEntry() == BOSS_SYLVANAS_WINDRUNNER)
                {
                    if (_actor->IsAIEnabled())
                    {
                        if (Unit* target = _actor->GetAI()->SelectTarget(SelectTargetMethod::MaxThreat, 0, 250.0f, true))
                            _actor->GetAI()->AttackStart(target);

                        _actor->GetAI()->DoAction(ACTION_RESET_MELEE_KIT);
                    }
                }
            }

            return true;
        }

    private:
        Unit* _actor;
        bool _paused;
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
                    if (Creature* shadowCopy = _actor->GetInstanceScript()->instance->GetCreature(_actor->GetInstanceScript()->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_01 + _copyIndex)))
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
                    _actor->SetBaseAttackTime(BASE_ATTACK, 1000);
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

// 176369 - Sylvanas Shadowcopy (Fight)
struct npc_sylvanas_windrunner_shadowcopy : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()),
        _onDominationChains(false), _sayDaggers(0), _sayDesecrating(0), _jumpCount(0), _totalWitheringFires(0) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);

        _events.SetPhase(PHASE_ONE);
    }

    void Reset() override
    {
        _onDominationChains = false;
        _sayDaggers = 0;
        _sayDesecrating = 0;
        _jumpCount = 0;
        _totalWitheringFires = 0;

        _events.Reset();
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EVENT_TYPE_SHADOWCOPY)
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
            DoCastSelf(SPELL_ANCHOR_HERE, true);

            if (_onDominationChains)
                _events.ScheduleEvent(EVENT_DOMINATION_CHAINS_JUMP, 150ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            // TODO: for testing purposes, the positioning is fixed to Sylvanas' positioning. It should be based on casters' back pos.
            case ACTION_START_WITHERING_FIRE:
                for (uint8 i = 0; i < 5; i++)
                    _randomWitheringFirePos.push_back(me->GetFirstCollisionPosition(40.0f, 2.0f * float(M_PI) - frand(-0.5f, 0.5f)));
                TeleportShadowcopyToPosition(SylvanasWitheringFireTestPos[0], SPELL_VISUAL_WINDRUNNER_02);
                _events.ScheduleEvent(EVENT_WITHERING_FIRE, 15ms, 1, PHASE_ONE);
                break;

            case ACTION_START_DOMINATION_CHAINS:
                for (uint8 i = 0; i < 3; i++)
                    _randomDominationChainsPos.push_back(me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f)));
                SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT);
                DoAction(ACTION_CALCULATE_ARROWS);
                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_02, false);
                _events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 20ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                break;

            // Note: number of arrows spawned is dependent on raid's difficulty and size: min. 4, max. 10 (unless on intermission, which is every player alive).
            case ACTION_CALCULATE_ARROWS:
            {
                uint8 arrowsToSpawn = _events.IsInPhase(PHASE_INTERMISSION) ? me->GetMap()->GetPlayersCountExceptGMs()
                    : std::min<uint8>(std::max<uint8>(std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs() / 3)), 4), 10);
                _selectedArrowCountsPerJump = SplitArrowCasts(arrowsToSpawn);
                _jumpCount = 0;
                break;
            }

            case ACTION_PREPARE_INTERMISSION:
                _events.CancelEventGroup(1);
                _events.SetPhase(PHASE_INTERMISSION);
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WITHERING_FIRE:
                    me->CastSpell(_randomWitheringFirePos[0], SPELL_WITHERING_FIRE_COPY, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 1, 204ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 1:
                    TeleportShadowcopyToPosition(_randomWitheringFirePos[1], SPELL_VISUAL_WINDRUNNER_02);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 2, 62ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 2:
                    me->CastSpell(_randomWitheringFirePos[1], SPELL_WITHERING_FIRE_COPY, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 3, 219ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 3:
                    TeleportShadowcopyToPosition(_randomWitheringFirePos[2], SPELL_VISUAL_WINDRUNNER_02);
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(_randomWitheringFirePos[0]);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 4, 16ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 4:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->ExecuteWitheringFire(DATA_JUMP_TIME_CERO);
                    me->CastSpell(_randomWitheringFirePos[2], SPELL_WITHERING_FIRE_COPY, false);
                    if (Creature* shadowCopy2 = _instance->instance->GetCreature(_instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_02)))
                        shadowCopy2->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 5, 234ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 5:
                    TeleportShadowcopyToPosition(_randomWitheringFirePos[3], SPELL_VISUAL_WINDRUNNER_02);
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(_randomWitheringFirePos[1]);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 6, 16ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 6:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->ExecuteWitheringFire(DATA_JUMP_TIME_ONE);
                    me->CastSpell(_randomWitheringFirePos[3], SPELL_WITHERING_FIRE_COPY, false);
                    if (Creature* shadowCopy2 = _instance->instance->GetCreature(_instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_02)))
                        shadowCopy2->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 7, 109ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 7:
                    TeleportShadowcopyToPosition(sylvanas->GetPosition());
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 8, 15ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 8:
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                    me->CastSpell(_randomWitheringFirePos[2], SPELL_WINDRUNNER_MOVE, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 9, 141ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 9:
                    ExecuteWitheringFire(DATA_JUMP_TIME_TWO);
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(_randomWitheringFirePos[4], SPELL_VISUAL_WINDRUNNER_02);
                    if (Creature* shadowCopy2 = _instance->instance->GetCreature(_instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_02)))
                        shadowCopy2->CastSpell(_randomWitheringFirePos[4], SPELL_WITHERING_FIRE_COPY, false);
                    me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 10, 203ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 10:
                    me->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 11, 47ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 11:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(_randomWitheringFirePos[3]);
                    if (Creature* shadowCopy2 = _instance->instance->GetCreature(_instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_02)))
                        shadowCopy2->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 12, 140ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 12:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->ExecuteWitheringFire(DATA_JUMP_TIME_THREE);
                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 13, 125ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 13:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(_randomWitheringFirePos[4]);
                    if (Creature* shadowCopy2 = _instance->instance->GetCreature(_instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_02)))
                        shadowCopy2->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 14, 75ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 14:
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->ExecuteWitheringFire(DATA_JUMP_TIME_FOUR);
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, GetShadowcopyAI(_instance, 1)))
                        shadowCopy2AI->TeleportShadowcopyToPosition(sylvanas->GetPosition());
                    _events.ScheduleEvent(EVENT_WITHERING_FIRE + 15, 456ms, 1, PHASE_ONE);
                    break;

                case EVENT_WITHERING_FIRE + 15:
                    sylvanas->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    _randomWitheringFirePos.clear();
                    break;

                case EVENT_DOMINATION_CHAINS:
                    sylvanas->CastSpell(sylvanas, SPELL_DOMINATION_CHAINS, false);
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 1, 15ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 1:
                    JumpShadowcopyToPosition(_randomDominationChainsPos[0], SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 2, 120ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 2:
                    if (sylvanas->IsAIEnabled())
                    {
                        sylvanas->AI()->Talk(SAY_ANNOUNCE_DOMINATION_CHAINS);
                        sylvanas->AI()->Talk(_events.IsInPhase(PHASE_ONE) ? SAY_DOMINATION_CHAINS : SAY_INTERMISSION_BEGIN);
                    }
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 3, 616ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 3:
                    sylvanas->NearTeleportTo(_randomDominationChainsPos[0], true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 4, 62ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 4:
                    JumpShadowcopyToPosition(_randomDominationChainsPos[1], SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 5, 750ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 5:
                    sylvanas->NearTeleportTo(_randomDominationChainsPos[1], true);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 6, 63ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 6:
                    JumpShadowcopyToPosition(_randomDominationChainsPos[2], SPELL_VISUAL_WINDRUNNER_01);
                    _events.ScheduleEvent(EVENT_DOMINATION_CHAINS + 7, 560ms, 1, _events.IsInPhase(PHASE_ONE) ? PHASE_ONE : PHASE_INTERMISSION);
                    break;

                case EVENT_DOMINATION_CHAINS + 7:
                    sylvanas->NearTeleportTo(_randomDominationChainsPos[2], true);
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
                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->DoAction(ACTION_FINISH_DOMINATION_CHAINS);
                    _randomDominationChainsPos.clear();
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

                        me->SendPlaySpellVisual(falseArrowPos, 0.0f, SPELL_VISUAL_DOMINATION_ARROW, 0, 0, 2.0f, true);

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
                            me->SendPlaySpellVisual(arrowPos, 0.0f, SPELL_VISUAL_DOMINATION_ARROW_SPAWN, 0, 0, 2.0f, true);

                            ObjectGuid dominationArrowGUID = dominationArrow->GetGUID();

                            _scheduler.Schedule(2s, [this, dominationArrowGUID](TaskContext /*task*/)
                            {
                                if (Unit* dominationArrow = ObjectAccessor::GetUnit(*me, dominationArrowGUID))
                                {
                                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                        sylvanas->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_FALL_AND_VISUAL, true);

                                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                                        dominationArrow->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_CALAMITY_VISUAL, false);
                                }
                            });
                        }
                    }

                    ++_jumpCount;
                    break;
                }

                default:
                    break;
            }
        }
    }

    void TeleportShadowcopyToPosition(Position chosenPos, uint32 spellVisual = 0)
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            // HACKFIX: remove orientation when SPELL_ATTR12_UNK11 (Face Destination) is implemented.
            me->NearTeleportTo(chosenPos.GetPositionX(), chosenPos.GetPositionY(), chosenPos.GetPositionZ(), chosenPos.GetAbsoluteAngle(sylvanas->GetPosition()), false);

            if (spellVisual > 0)
            {
                float speed = spellVisual == SPELL_VISUAL_WINDRUNNER_01 ? 0.5f : 0.25f;

                sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
            }
        }
    }

    void JumpShadowcopyToPosition(Position chosenPos, uint32 spellVisual)
    {
        me->CastSpell(chosenPos, SPELL_DOMINATION_CHAINS_JUMP, false);

        float speed = spellVisual == SPELL_VISUAL_WINDRUNNER_01 ? 0.5f : 0.25f;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
    }

    void ExecuteWitheringFire(uint8 jumpTime)
    {
        uint32 currentWitheringFires = 0;

        if (jumpTime == DATA_JUMP_TIME_CERO)
        {
            // Number of casts is dependent on raid's difficulty and size: if mythic, 15; if not, half the raid (min. 5, max. 15)
            _totalWitheringFires = me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 15 :
                std::max<uint8>(5, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 2));

            std::list<Player*> witheringFireTargetList;
            GetPlayerListInGrid(witheringFireTargetList, me, 200.0f);
            Trinity::Containers::RandomResize(witheringFireTargetList, _totalWitheringFires);

            for (Player* player : witheringFireTargetList)
                _witheringFireTargetGUIDs.push_back(player->GetGUID());
        }

        if (jumpTime == DATA_JUMP_TIME_TWO)
            currentWitheringFires = _totalWitheringFires > 11 ? _totalWitheringFires - 8 : _totalWitheringFires - 4;
        else
            currentWitheringFires = _totalWitheringFires > 11 ? 2 : 1;

        std::vector<Player*> targetedPlayers;
        for (uint8 itr = currentWitheringFires; itr > 0 && !_witheringFireTargetGUIDs.empty(); itr--)
        {
            if (Player* target = ObjectAccessor::GetPlayer(*me, _witheringFireTargetGUIDs.front()))
                targetedPlayers.push_back(target);

            _witheringFireTargetGUIDs.erase(std::remove(_witheringFireTargetGUIDs.begin(), _witheringFireTargetGUIDs.end(), _witheringFireTargetGUIDs.front()), _witheringFireTargetGUIDs.end());
        }

        for (Player* target : targetedPlayers)
        {
            uint32 timeToTarget = me->GetDistance(target) * 0.02083 * 1000;

            ObjectGuid targetGUID = target->GetGUID();

            me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE, 0, 0, 48.0f, false);

            _scheduler.Schedule(Milliseconds(timeToTarget), [this, targetGUID](TaskContext /*task*/)
            {
                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    if (Player* target = ObjectAccessor::GetPlayer(*me, targetGUID))
                        sylvanas->CastSpell(target, SPELL_WITHERING_FIRE, false);
            });
        }
    }

    void StartShadowDaggersEvent(bool chooseMe, uint8 index, Creature* nextIndex)
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            std::list<Player*> targetList;
            GetPlayerListInGrid(targetList, me, 250.0f);

            Trinity::Containers::RandomResize(targetList, 1);

            for (Player* target : targetList)
            {
                ObjectGuid targetGUID = target->GetGUID();

                Position const shadowdaggerPos = target->GetNearPosition(frand(2.5f, 3.0f), frand(0.0f, 6.0f));

                if (index == 0)
                    sylvanas->SendPlayOrphanSpellVisual(shadowdaggerPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                if (chooseMe)
                {
                    if (_sayDaggers == 0)
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(SAY_SHADOW_DAGGER);

                        _sayDaggers = 1;

                        _scheduler.Schedule(20s, [this](TaskContext /*task*/)
                        {
                            _sayDaggers = 0;
                        });
                    }

                    me->CastSpell(shadowdaggerPos, SPELL_WINDRUNNER_MOVE, false);

                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                }
                else
                    me->NearTeleportTo(shadowdaggerPos, false);

                _scheduler.Schedule(202ms, [this, targetGUID](TaskContext /*task*/)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                        me->SetFacingToObject(target);
                });

                _scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_SHADOW_DAGGER_COPY, true);
                });

                _scheduler.Schedule(550ms, [this, targetGUID](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                            sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                    }
                });

                _scheduler.Schedule(750ms, [this, index, nextIndex, chooseMe](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (index < 3)
                            me->SendPlayOrphanSpellVisual(*nextIndex, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                        else
                            me->SendPlayOrphanSpellVisual(*sylvanas, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        if (chooseMe)
                            me->CastSpell(*sylvanas, SPELL_WINDRUNNER_MOVE, false);
                        else
                            me->NearTeleportTo(*sylvanas, false);
                    }
                });

                _scheduler.Schedule(1s + 250ms, [this, chooseMe](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (chooseMe)
                        {
                            if (sylvanas->IsAIEnabled())
                                sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_DEACTIVATE);
                        }
                    }
                });
            }
        }
    }

    void StartDesecratingShotEvent(uint8 pattern, Position pos)
    {
        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        sylvanas->CastSpell(sylvanas, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2550));

        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                if (sylvanas->IsAIEnabled())
                    sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_ACTIVATE);

                me->NearTeleportTo(sylvanas->GetNearPosition(5.0f, float(M_PI)), false);

                _scheduler.Schedule(5ms, [this, sylvanas](TaskContext /*task*/)
                {
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 5.048f, sylvanas->GetOrientation(), false);
                });

                _scheduler.Schedule(15ms, [this, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlayOrphanSpellVisual(me->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                });

                _scheduler.Schedule(63ms, [this, sylvanas](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_DESECRATING_SHOT_JUMP_FRONT);

                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                });

                _scheduler.Schedule(100ms, [this, sylvanas](TaskContext /*task*/)
                {
                    if (sylvanas->IsAIEnabled())
                    {
                        // Note: TC needs to implement a cooldown in DB for creature_texts, otherwise we need to add random bools to avoid spam.
                        if (_sayDesecrating == 0)
                        {
                            sylvanas->AI()->Talk(SAY_DESECRATING_SHOT);

                            _sayDesecrating = 1;

                            _scheduler.Schedule(20s, [this](TaskContext /*task*/)
                            {
                                _sayDesecrating = 0;
                            });
                        }
                    }
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

                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_DEACTIVATE);
                });
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            {
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            {
                sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_ACTIVATE);

                me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 10.0f, false);

                _scheduler.Schedule(400ms, [this, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());

                    DoCastSelf(SPELL_DESECRATING_SHOT_JUMP_LEFT, false);
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

    void StoreDesecratingShots(Position pos, uint8 step, float travelSpeed)
    {
        _desecratingShotStorage.emplace_back(pos, step, travelSpeed);
    }

    void ReleaseDesecratingShots()
    {
        for (DesecratingShotsStorage const& desecratingShot : _desecratingShotStorage)
        {
            float travelSpeed = desecratingShot.TravelSpeed;

            if (desecratingShot.Step >= 2)
                travelSpeed += float((me->GetExactDist(desecratingShot.Pos) * (0.016465054083896f * desecratingShot.Step) / 46.5));

            me->SendPlaySpellVisual(desecratingShot.Pos, 0, SPELL_VISUAL_DESECRATING_ARROW, 0, 0, travelSpeed, true);

            uint32 timeToTarget = travelSpeed * 1000;

            _scheduler.Schedule(Milliseconds(timeToTarget), [this, desecratingShot](TaskContext /*task*/)
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

    std::array<uint32, 3> SplitArrowCasts(uint32 totalArrows)
    {
        std::array<uint32, 3> arrowsPerWave{ };

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
    uint32 _totalWitheringFires;
    std::vector<Position> _randomWitheringFirePos;
    std::vector<ObjectGuid> _witheringFireTargetGUIDs;
    std::vector<Position> _randomDominationChainsPos;
    std::vector<DesecratingShotsStorage> _desecratingShotStorage;
    bool _onDominationChains;
    uint8 _sayDaggers;
    uint8 _sayDesecrating;
    std::array<uint32, 3> _selectedArrowCountsPerJump = { };
    uint8 _jumpCount;
};

// 178355 - Sylvanas Shadowcopy (Riding)
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);
    }

private:
    InstanceScript* _instance;
};

// 175732 - Sylvanas Windrunner
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER), _maldraxxiDesecrated(false),
        _nightfaeDesecrated(false), _kyrianDesecrated(false), _venthyrDesecrated(false), _meleeKitCombo(0), _windrunnerCastTimes(0),
        _desecratingShotCastTimes(0), _desecratingShotPattern(0), _wailingArrowCastTimes(0), _riveCastTimes(0), _hauntingWaveTimes(0) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

        me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        me->SetImmuneToAll(false);

        me->SetSpeed(UnitMoveType::MOVE_RUN, 14.0f);

        DoCastSelf(SPELL_DUAL_WIELD, true);
        DoCastSelf(SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING, true);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_DISENGAGE);

        _EnterEvadeMode();

        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BARBED_ARROW);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANSHEE_MARK);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_CHAIN_PLAYER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_CHAIN_PERIODIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VEIL_OF_DARKNESS_ABSORB_AURA);

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        // Note: every creature involved in the fight adds UNIT_FLAG_PET_IN_COMBAT or UNIT_FLAG_RENAME when engaging, meaning they're most likely summoned by Sylvanas.
        me->SummonCreatureGroup(SPAWN_GROUP_INITIAL);

        me->GetInstanceScript()->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.Reset();
        _specialEvents.Reset();

        // Note: apparently Sylvanas stays 750ms roughly without acting.
        me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

        _maldraxxiDesecrated = false;
        _nightfaeDesecrated = false;
        _kyrianDesecrated = false;
        _venthyrDesecrated = false;
        _meleeKitCombo = 0;
        _windrunnerCastTimes = 0;
        _desecratingShotCastTimes = 0;
        _desecratingShotPattern = 0;
        _wailingArrowCastTimes = 0;
        _riveCastTimes = 0;
        _hauntingWaveTimes = 0;
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

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        // TODO: there should be an internal CD for this.
        Talk(SAY_SLAY);
    }

    void OnSpellFailed(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RUIN)
        {
            // TODO: she's interrupted 5 times, but only the first and fifth trigger this.
            if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            {
                if (bolvar->IsAIEnabled())
                    bolvar->AI()->DoAction(ACTION_WINDS_OF_ICECROWN_PRE);
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        // Note: it is safe to assume that these are summoned by a serverside spell.
        for (uint8 i = 0; i < 4; i++)
            me->SummonCreature(NPC_SYLVANAS_SHADOWCOPY_FIGHTER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);

        Talk(SAY_AGGRO);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        // Note: each difficulty uses different timers, so we use a method that will handle it all to avoid bloating.
        HandleCombatRelatedEventsForPhaseOne();

        DoCastSelf(SPELL_SYLVANAS_POWER_ENERGIZE_AURA, true);
        DoCastSelf(SPELL_RANGER_HEARTSEEKER_AURA, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_INTERMISSION, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_FINISH, true);

        me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(750ms));

        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2000));
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_SYLVANAS_INTRO:
            {
                scheduler.Schedule(22s + 328ms, [this](TaskContext /*task*/)
                {
                    Conversation::CreateConversation(CONVERSATION_INTRO, me, me->GetPosition(), ObjectGuid::Empty);
                });

                scheduler.Schedule(23s + 828ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01, 0, 0);

                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                });

                scheduler.Schedule(24s + 968ms, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_01, SylvanasIntroPos[0], false);
                });

                scheduler.Schedule(26s + 468ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02, 0, 0);
                });

                scheduler.Schedule(28s + 203ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
                });

                scheduler.Schedule(29s + 828ms, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_02, SylvanasIntroPos[1], false);
                });

                scheduler.Schedule(30s + 297ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03, 0, 0);
                });

                scheduler.Schedule(33s + 797ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04, 0, 0);
                });

                scheduler.Schedule(35s + 797ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05, 0, 0);
                });

                scheduler.Schedule(40s + 797ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                });

                scheduler.Schedule(41s + 547ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06, 0, 0);
                });

                scheduler.Schedule(42s, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_03, SylvanasIntroPos[2], false);
                });

                scheduler.Schedule(47s + 89ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->SetFacingToObject(me);

                        bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01, 0, 0);
                    }
                });

                scheduler.Schedule(50s + 484ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
                });

                scheduler.Schedule(60s + 656ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                });

                scheduler.Schedule(61s + 140ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07, 0, 0);
                });

                scheduler.Schedule(66s + 656ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08, 0, 0);
                });

                scheduler.Schedule(68s + 172ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(SylvanasIntroPos[3], false);
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);
                });

                scheduler.Schedule(69s + 437ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                });

                scheduler.Schedule(70s + 406ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09, 0, 0);
                });

                scheduler.Schedule(75s + 172ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10, 0, 0);
                });

                scheduler.Schedule(78s + 422ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                });

                scheduler.Schedule(78s + 437ms, [this](TaskContext /*task*/)
                {
                    me->SetHomePosition(me->GetPosition());

                    instance->SetData(DATA_SYLVANAS_INTRO, DONE);
                });

                break;
            }

            case ACTION_WINDRUNNER_MODEL_ACTIVATE:
                DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, false);
                break;

            case ACTION_WINDRUNNER_MODEL_DEACTIVATE:
                me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_01);
                break;

            case ACTION_RESET_MELEE_KIT:
                _meleeKitCombo = 0;
                break;

            case ACTION_FINISH_DOMINATION_CHAINS:
            {
                TeleportShadowcopiesToMe();

                for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                        if (shadowCopy->IsAIEnabled())
                            shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);

                if (events.IsInPhase(PHASE_ONE))
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                    DoAction(ACTION_RESET_MELEE_KIT);
                }
                else
                    events.ScheduleEvent(EVENT_RIVE, 1s, PHASE_INTERMISSION);
                break;
            }

            // TODO: move this to an event because the transition shouldn't happen at all until on-going events are done.
            case ACTION_PREPARE_INTERMISSION:
            {
                _specialEvents.CancelEventGroup(GROUP_EVENT_WAILING_ARROW_EVENTS);
                events.CancelEventGroup(GROUP_EVENT_NORMAL_EVENTS);
                events.CancelEventGroup(GROUP_EVENT_WINDRUNNER_RELATED_EVENTS);

                instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_INTERMISSION_WORLD_STATE);

                for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                        if (shadowCopy->IsAIEnabled())
                            shadowCopy->AI()->DoAction(ACTION_PREPARE_INTERMISSION);

                _specialEvents.SetPhase(PHASE_INTERMISSION);
                events.SetPhase(PHASE_INTERMISSION);
                events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 1s, GROUP_EVENT_NORMAL_EVENTS, PHASE_INTERMISSION);
                break;
            }

            case ACTION_HAUNTING_WAVE_SECOND_CHAIN:
            {
                if (_hauntingWaveTimes < 5)
                {
                    scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, true);
                        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5500));
                    });

                    scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasWavePos[_hauntingWaveTimes], SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);
                    });

                    scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(SylvanasWavePos[_hauntingWaveTimes], false);
                        me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                    });

                    scheduler.Schedule(1s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_HAUNTING_WAVE, false);

                        if (_hauntingWaveTimes == 0)
                            Talk(SAY_ANNOUNCE_HAUNTING_WAVE);
                    });

                    scheduler.Schedule(5s + 500ms, [this](TaskContext /*task*/)
                    {
                        _hauntingWaveTimes++;

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
                        me->NearTeleportTo(SylvanasPhase2PrePos, false);
                        me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                    });

                    scheduler.Schedule(5s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_RUIN, false);

                        Talk(SAY_ANNOUNCE_RUIN);
                    });
                }
                break;
            }

            case ACTION_PREPARE_PHASE_THREE:
            {
                me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                {
                    if (jaina->IsAIEnabled())
                        jaina->AI()->DoAction(ACTION_OPEN_PORTAL_TO_PHASE_THREE);
                }
                break;
            }

            case ACTION_INITIATE_PHASE_THREE:
            {
                me->NearTeleportTo(SylvanasPhase3PrePos, false);

                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);
                });

                scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    TeleportShadowcopiesToMe();

                    DoCastSelf(SPELL_RANGER_BOW_STANCE, true);

                    me->RemoveAura(SPELL_RANGER_HEARTSEEKER_AURA);
                    me->RemoveAura(SPELL_RANGER_HEARTSEEKER_CHARGE);
                });
                break;
            }

            case ACTION_START_PHASE_THREE:
            {
                DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 650));
                DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1750));

                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                {
                    me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                    shadowCopy->CastSpell(SylvanasPhase3Pos, SPELL_DOMINATION_CHAINS_JUMP, true);

                    me->SendPlayOrphanSpellVisual(SylvanasPhase3Pos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }

                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    Talk(SAY_START_PHASE_THREE);
                });

                scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(SylvanasPhase3Pos, false);

                    me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                });

                scheduler.Schedule(1s, [this](TaskContext /*task*/)
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                    me->GetInstanceScript()->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_THREE);

                    events.SetPhase(PHASE_THREE);
                    events.ScheduleEvent(EVENT_BANSHEES_FURY, 1s + 500ms, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_WITHERING_FIRE, 8s, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_BANE_ARROWS, 16s, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, 28s, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 32s, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_RAZE, 70s, 1, PHASE_THREE);
                    events.ScheduleEvent(EVENT_BANSHEE_SCREAM, 80s, 1, PHASE_THREE);

                    // We need a separated event handler for this because Wailing Arrow is triggered even if Sylvanas is casting
                    _specialEvents.SetPhase(PHASE_THREE);
                    _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW, 60s, 1, PHASE_THREE);

                    DoCastSelf(SPELL_BANSHEES_HEARTSEEKER_AURA, true);
                });
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _specialEvents.Update(diff);

        while (uint32 specialEventId = _specialEvents.ExecuteEvent())
        {
            switch (specialEventId)
            {
                case EVENT_WAILING_ARROW:
                {
                    std::list<Player*> everyPlayerButCurrentTank;
                    GetPlayerListInGrid(everyPlayerButCurrentTank, me, 250.0f);

                    if (Unit* currentTank = SelectTarget(SelectTargetMethod::MaxThreat, 0, 250.0f, true, true))
                    {
                        ObjectGuid arrowTargetGUID = currentTank->GetGUID();

                        Talk(SAY_ANNOUNCE_WAILING_ARROW_AFFECTED, currentTank);

                        me->CastSpell(currentTank, SPELL_WAILING_ARROW_POINTER, true);

                        if (Player* currentTankToPlayer = currentTank->ToPlayer())
                            everyPlayerButCurrentTank.remove(currentTankToPlayer);

                        if (events.IsInPhase(PHASE_ONE))
                            for (Unit* nonTank : everyPlayerButCurrentTank)
                                Talk(SAY_ANNOUNCE_WAILING_ARROW, nonTank);

                        scheduler.Schedule(events.IsInPhase(PHASE_ONE) ? 5s + 500ms : 6s, [this](TaskContext /*task*/)
                        {
                            me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                            if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                                DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                        });

                        scheduler.Schedule(events.IsInPhase(PHASE_ONE) ? 6s + 500ms : 7s, [this, arrowTargetGUID](TaskContext /*task*/)
                        {
                            Talk(SAY_WAILING_ARROW);

                            if (Player* target = ObjectAccessor::GetPlayer(*me, arrowTargetGUID))
                                me->CastSpell(target, SPELL_WAILING_ARROW, false);

                            _wailingArrowCastTimes++;

                            uint32 timerForWailingArrow;

                            switch (_wailingArrowCastTimes)
                            {
                                case 1:
                                    timerForWailingArrow = 31;
                                    break;
                                case 2:
                                    timerForWailingArrow = 24.5;
                                    break;
                                case 3:
                                    timerForWailingArrow = 27.5;
                                    break;
                                default:
                                    break;
                            }

                            _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW, Seconds(timerForWailingArrow), PHASE_ONE);
                        });

                        if (events.IsInPhase(PHASE_ONE))
                        {
                            scheduler.Schedule(9s, [this](TaskContext /*task*/)
                            {
                                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                            });
                        }
                    }

                    if (events.IsInPhase(PHASE_THREE))
                    {
                        Trinity::Containers::RandomResize(everyPlayerButCurrentTank, 2);

                        Unit* firstRandomPlayer = everyPlayerButCurrentTank.front();
                        Unit* secondRandomPlayer = everyPlayerButCurrentTank.back();

                        ObjectGuid arrowfirstRandomTargetGUID = firstRandomPlayer->GetGUID();
                        ObjectGuid arrowsecondRandomTargetGUID = secondRandomPlayer->GetGUID();

                        scheduler.Schedule(3s, [this, arrowfirstRandomTargetGUID](TaskContext /*task*/)
                        {
                            if (Player* target = ObjectAccessor::GetPlayer(*me, arrowfirstRandomTargetGUID))
                            {
                                Talk(SAY_ANNOUNCE_WAILING_ARROW_AFFECTED, target);

                                me->CastSpell(target, SPELL_WAILING_ARROW_POINTER, true);

                                scheduler.Schedule(7s, [this, arrowfirstRandomTargetGUID](TaskContext /*task*/)
                                {
                                    if (Player* target = ObjectAccessor::GetPlayer(*me, arrowfirstRandomTargetGUID))
                                        me->CastSpell(target, SPELL_WAILING_ARROW, false);
                                });
                            }
                        });

                        scheduler.Schedule(6s, [this, arrowsecondRandomTargetGUID](TaskContext /*task*/)
                        {
                            if (Player* target = ObjectAccessor::GetPlayer(*me, arrowsecondRandomTargetGUID))
                            {
                                Talk(SAY_ANNOUNCE_WAILING_ARROW_AFFECTED, target);

                                me->CastSpell(target, SPELL_WAILING_ARROW_POINTER, true);

                                scheduler.Schedule(7s, [this, arrowsecondRandomTargetGUID](TaskContext /*task*/)
                                {
                                    if (Player* target = ObjectAccessor::GetPlayer(*me, arrowsecondRandomTargetGUID))
                                        me->CastSpell(target, SPELL_WAILING_ARROW, false);
                                });

                                scheduler.Schedule(10s, [this](TaskContext /*task*/)
                                {
                                    me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                                    // TODO: this timer is wrong, find correct one.
                                    //_specialEvents.ScheduleEvent(EVENT_WAILING_ARROW, 33s, PHASE_THREE);
                                });
                            }
                        });
                    }

                    break;
                }

                default:
                    break;
            }
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WINDRUNNER:
                {
                    Talk(SAY_ANNOUNCE_WINDRUNNER);

                    me->AddAura(SPELL_RANGER_BOW_STANCE, me);

                    _windrunnerCastTimes++;

                    // Note: fifth cast will be ignored until I can sniff what happens on that one.
                    if (_windrunnerCastTimes == 5)
                        _windrunnerCastTimes = 1;

                    HandleWindrunnerRelatedEvents();
                    break;
                }

                case EVENT_WITHERING_FIRE:
                {
                    TeleportShadowcopiesToMe();

                    switch (events.GetPhaseMask())
                    {
                        case PHASE_ONE:
                            DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 2062));
                            DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3800));
                            if (Creature* shadowCopy1 = instance->instance->GetCreature(instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_01)))
                                if (shadowCopy1->IsAIEnabled())
                                    shadowCopy1->AI()->DoAction(ACTION_START_WITHERING_FIRE);
                            break;

                        case PHASE_TWO:
                        {
                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WITHERING_FIRE_PHASE_TWO, 0, 0);

                            scheduler.Schedule(312ms, [this](TaskContext /*task*/)
                            {
                                std::list<Player*> targetList;
                                GetPlayerListInGrid(targetList, me, 500.0f);

                                Trinity::Containers::RandomResize(targetList, 4);

                                for (Player* target : targetList)
                                {
                                    uint32 randomSpeed = urand(2700, 3500);

                                    me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_TWO, 0, 0, float(randomSpeed / 1000), true);

                                    ObjectGuid targetGUID = target->GetGUID();

                                    scheduler.Schedule(Milliseconds(randomSpeed), [this, targetGUID](TaskContext /*task*/)
                                    {
                                        if (Player* target = ObjectAccessor::GetPlayer(*me, targetGUID))
                                            me->CastSpell(target, SPELL_WITHERING_FIRE, false);
                                    });
                                }
                            });
                            break;
                        }

                        case PHASE_THREE:
                            break;

                        default:
                            break;
                    }

                    break;
                }

                case EVENT_SHADOW_DAGGERS:
                {
                    if (events.IsInPhase(PHASE_ONE))
                    {
                        TeleportShadowcopiesToMe();

                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 4000));
                        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3200));

                        uint8 randomCopy = urand(0, 4);

                        for (uint8 itr = 0; itr < 4; itr++)
                        {
                            scheduler.Schedule(Milliseconds(250 * itr), [this, itr, randomCopy](TaskContext /*task*/)
                            {
                                if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(itr))
                                {
                                    Creature* nextShadowCopy = ObjectAccessor::GetCreature(*me, GetShadowCopyGuid(itr + 1));

                                    ai->StartShadowDaggersEvent(itr == randomCopy, itr, nextShadowCopy);
                                }
                            });
                        }
                    }
                    else if (events.IsInPhase(PHASE_TWO))
                        DoCastSelf(SPELL_SHADOW_DAGGER_PHASE_TWO_AND_THREE, false);
                    else if (events.IsInPhase(PHASE_THREE))
                        DoCastSelf(SPELL_SHADOW_DAGGER_PHASE_TWO_AND_THREE, false);
                    break;
                }

                case EVENT_DESECRATING_SHOT:
                {
                    _desecratingShotCastTimes++;

                    switch (_windrunnerCastTimes)
                    {
                        case DATA_WINDRUNNER_CAST_TIME_ONE:
                            _desecratingShotPattern = _desecratingShotCastTimes == 1 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_STRAIGHT;
                            break;
                        case DATA_WINDRUNNER_CAST_TIME_TWO:
                            _desecratingShotPattern = _desecratingShotCastTimes == 3 ? DATA_DESECRATING_SHOT_PATTERN_WAVE : DATA_DESECRATING_SHOT_PATTERN_SPIRAL;
                            break;
                        case DATA_WINDRUNNER_CAST_TIME_THREE:
                            _desecratingShotPattern = _desecratingShotCastTimes == 5 ? DATA_DESECRATING_SHOT_PATTERN_SPIRAL : DATA_DESECRATING_SHOT_PATTERN_SCATTERED;
                            break;
                        case DATA_WINDRUNNER_CAST_TIME_FOUR:
                            _desecratingShotPattern = _desecratingShotCastTimes == 7 ? DATA_DESECRATING_SHOT_PATTERN_SCATTERED : DATA_DESECRATING_SHOT_PATTERN_JAR;
                            break;
                        case DATA_WINDRUNNER_CAST_TIME_FIVE:
                            _desecratingShotPattern = 0;
                            break;
                        default:
                            break;
                    }

                    ChooseDesecratingShotPattern(_desecratingShotPattern);
                    break;
                }

                case EVENT_DESECRATING_SHOT_LAUNCH:
                {
                    if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                        ai->StartDesecratingShotEvent(_desecratingShotPattern, me->GetPosition());
                    break;
                }

                case EVENT_DOMINATION_CHAINS:
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, true);
                    DoCastSelf(SPELL_DOMINATION_CHAINS);
                    TeleportShadowcopiesToMe();
                    if (Creature* shadowCopy1 = instance->instance->GetCreature(instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_01)))
                        if (shadowCopy1->IsAIEnabled())
                            shadowCopy1->AI()->DoAction(ACTION_START_DOMINATION_CHAINS);
                    if (events.IsInPhase(PHASE_ONE))
                        events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 53s, 1, PHASE_ONE);
                    break;
                }

                case EVENT_VEIL_OF_DARKNESS:
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                    if (events.IsInPhase(PHASE_ONE))
                    {
                        Talk(SAY_ANNOUNCE_VEIL_OF_DARKNESS);
                        Talk(SAY_VEIL_OF_DARKNESS_PHASE_ONE);

                        scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                        {
                            scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                            {
                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE, true);
                            });

                            scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                            {
                                me->NearTeleportTo(SylvanasVeilOnePos, false);
                            });

                            scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                            {
                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));

                                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                                {
                                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, SylvanasNonMeleeSelector(me)))
                                    {
                                        me->NearTeleportTo(target->GetPosition(), false);

                                        // TODO: find out which number for SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_MM is.
                                    }
                                }
                                else
                                {
                                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
                                    {
                                        me->NearTeleportTo(target->GetPosition(), false);

                                        float x = target->GetPositionX();
                                        float y = target->GetPositionY();
                                        float z = target->GetPositionZ() + 0.5f;

                                        me->SendPlayOrphanSpellVisual(Position{ x, y, z }, me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID ? SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_HC
                                            : SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_NM, 5.0f, true, false);
                                    }
                                }
                            });

                            scheduler.Schedule(2s, [this](TaskContext /*task*/)
                            {
                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 4000));
                            });

                            scheduler.Schedule(8s, [this](TaskContext /*task*/)
                            {
                                TeleportShadowcopiesToMe();
                            });

                            events.Repeat(48s);
                        });
                    }
                    else if (events.IsInPhase(PHASE_TWO))
                    {

                    }
                    else if (events.IsInPhase(PHASE_THREE))
                    {
                        me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                        DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                        scheduler.Schedule(1s, [this](TaskContext /*task*/)
                        {
                            me->SetPower(me->GetPowerType(), 0);

                            Talk(SAY_ANNOUNCE_VEIL_OF_DARKNESS);
                            Talk(SAY_VEIL_OF_DARKNESS_PHASE_TWO_AND_THREE);

                            scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                            {
                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE, true);
                                me->NearTeleportTo(SylvanasVeilThreePos, false);
                            });

                            scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                            {
                                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
                                    me->NearTeleportTo(target->GetPosition(), false);
                            });

                            scheduler.Schedule(5s, [this](TaskContext /*task*/)
                            {
                                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                                DoAction(ACTION_RESET_MELEE_KIT);
                            });

                            events.Repeat(48s);
                        });
                    }
                    break;
                }

                case EVENT_RIVE:
                {
                    if (_riveCastTimes < 8)
                    {
                        scheduler.Schedule(50ms, [this](TaskContext /*task*/)
                        {
                            me->SetNameplateAttachToGUID(_shadowCopyGUID[1]);

                            DoCastSelf(SPELL_RIVE_DISAPPEAR, true);
                        });

                        scheduler.Schedule(100ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                shadowCopy->NearTeleportTo(RiveThrowPos[_riveCastTimes], false);

                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                shadowCopy2->NearTeleportTo(RiveThrowPos[_riveCastTimes], false);

                            if (Creature* shadowCopy3 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[3]))
                                shadowCopy3->NearTeleportTo(RiveThrowPos[_riveCastTimes], false);
                        });

                        scheduler.Schedule(200ms, [this](TaskContext /*task*/)
                        {
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
                            {
                                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                    shadowCopy->SetFacingToObject(target);

                                if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                    shadowCopy2->SetFacingToObject(target);

                                if (Creature* shadowCopy3 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[3]))
                                    shadowCopy3->SetFacingToObject(target);
                            }
                        });

                        scheduler.Schedule(300ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                shadowCopy2->NearTeleportTo(shadowCopy2->GetPositionX(), shadowCopy2->GetPositionY(), 4105.00f, shadowCopy2->GetOrientation(), false);
                        });

                        scheduler.Schedule(400ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                shadowCopy2->NearTeleportTo(shadowCopy2->GetNearPosition(24.4f, 0.0), false);
                        });

                        scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                            {
                                me->SendPlayOrphanSpellVisual(shadowCopy2->GetPosition(), SPELL_VISUAL_WINDRUNNER_03, 0.25f, true, false);

                                if (Creature* shadowCopy1 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[1]))
                                    shadowCopy1->CastSpell(shadowCopy2->GetPosition(), SPELL_DOMINATION_CHAINS_JUMP, true);
                            }
                        });

                        scheduler.Schedule(1s, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                me->NearTeleportTo(shadowCopy2->GetPosition(), false);
                        });

                        scheduler.Schedule(1s + 150ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy2 = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[2]))
                                me->CastSpell(shadowCopy2->GetNearPosition(9.0f, 0.0f), SPELL_RIVE_MARKER_AREATRIGGER, true);

                            me->SetNameplateAttachToGUID(ObjectGuid::Empty);

                            DoCastSelf(SPELL_ANCHOR_HERE, true);
                        });

                        scheduler.Schedule(1s + 500ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                shadowCopy->SetFacingTo(shadowCopy->GetAbsoluteAngle(me) + M_PI + 0.040f);

                            if (_riveCastTimes == 0 || _riveCastTimes == 5)
                            {
                                DoCastSelf(SPELL_RIVE, false);

                                scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                                {
                                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK, 0, 0);
                                });

                                events.ScheduleEvent(EVENT_RIVE, 5s, PHASE_INTERMISSION);
                            }
                            else
                            {
                                DoCastSelf(SPELL_RIVE_FAST, false);

                                me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RIVE_BREAK_FAST, 0, 0);

                                events.ScheduleEvent(EVENT_RIVE, 2s + 500ms, PHASE_INTERMISSION);
                            }

                            _riveCastTimes++;
                        });
                    }
                    else
                    {
                        for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                            {
                                shadowCopy->NearTeleportTo(me->GetPosition(), false);

                                if (shadowCopy->IsAIEnabled())
                                    shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);
                            }
                        }

                        events.ScheduleEvent(EVENT_FINISH_INTERMISSION, 1s + 500ms, PHASE_INTERMISSION);
                    }

                    break;
                }

                case EVENT_FINISH_INTERMISSION:
                {
                    DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1000));

                    me->SendPlayOrphanSpellVisual(RiveFinishPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                    me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                        shadowCopy->CastSpell(RiveFinishPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                    scheduler.Schedule(600ms, [this](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(RiveFinishPos, false);

                        me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    });

                    scheduler.Schedule(1s + 700ms, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_INTERMISSION_END);
                    });

                    scheduler.Schedule(2s + 400ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_BANSHEE_WAIL, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));

                        Talk(SAY_ANNOUNCE_BANSHEE_WAIL);
                    });

                    scheduler.Schedule(6s + 400ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_BANSHEE, 0, 0);
                    });

                    scheduler.Schedule(8s + 500ms, [this](TaskContext /*task*/)
                    {
                        me->GetInstanceScript()->DoCastSpellOnPlayers(SPELL_INTERMISSION_STUN);
                        me->GetInstanceScript()->DoCastSpellOnPlayers(SPELL_INTERMISSION_SCENE);

                        me->GetInstanceScript()->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_TWO);

                        events.SetPhase(PHASE_TWO);
                        _specialEvents.SetPhase(PHASE_TWO);
                    });

                    scheduler.Schedule(9s + 400ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasPhase2PrePos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        me->NearTeleportTo(SylvanasPhase2PrePos, false);
                    });

                    // TODO: This timer is partially wrong because there must be a bool check to know whether everyone in the raid has skipped the scene,
                    // in which case the timer is forced to happen instantly rather than having to wait for it completely. The idea should be behind
                    // OnSceneCancel, send data anytime it happens and, in the case of equaling the raid's size, force it.
                    scheduler.Schedule(38s + 400ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                        {
                            if (jaina->IsAIEnabled())
                                jaina->AI()->DoAction(ACTION_OPEN_PORTAL_TO_PHASE_TWO);
                        }
                    });

                    break;
                }

                case EVENT_BANE_ARROWS:
                    DoCastSelf(SPELL_BANE_ARROWS, false);
                    events.Repeat(76s);
                    break;

                case EVENT_RAZE:
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_DARK_FOG, 0, 0);

                    scheduler.Schedule(50ms, [this](TaskContext /*task*/)
                    {
                        me->CastSpell(GetMiddlePointInCurrentPlatform(), SPELL_RAZE, false);
                    });

                    for (uint8 covenentPlaform = 0; covenentPlaform < 4; covenentPlaform++)
                    {
                        if (me->IsWithinBox(CovenantPlatformPos[covenentPlaform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 14.0f, 14.0f, 14.0f))
                            DesecrateCurrentPlatform(covenentPlaform);
                    }

                    break;
                }

                case EVENT_BANSHEE_SCREAM:
                    Talk(SAY_BANSHEE_SCREAM);
                    DoCastSelf(SPELL_BANSHEE_SCREAM, false);
                    events.Repeat(80s);
                    break;

                case EVENT_BANSHEES_FURY:
                {
                    Talk(SAY_BANSHEES_FURY);

                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                        shadowCopy->NearTeleportTo(me->GetPosition(), false);

                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                    scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));

                        me->SendPlayOrphanSpellVisual(GetMiddlePointInCurrentPlatform(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        me->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(me, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), me->m_Events.CalculateTime(16ms));

                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                        {
                            me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                            shadowCopy->CastSpell(GetMiddlePointInCurrentPlatform(), SPELL_DOMINATION_CHAINS_JUMP, false);
                        }
                    });

                    scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                    {
                        me->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

                        me->NearTeleportTo(GetMiddlePointInCurrentPlatform(), false);

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
                        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));

                        DoCastSelf(SPELL_BANSHEES_FURY, false);

                        events.Repeat(49s);
                    });

                    scheduler.Schedule(7s, [this](TaskContext /*task*/)
                    {
                        me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                    });
                    break;
                }

                default:
                    break;
            }
        }

        DoSylvanasAttackIfReady();
    }

    void DoSylvanasAttackIfReady()
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_WINDRUNNER) || me->HasReactState(REACT_PASSIVE))
            return;

        if (me->isAttackReady(BASE_ATTACK))
        {
            if (IsHeartseekerReady())
                DoCastVictim(events.IsInPhase(PHASE_ONE) ? SPELL_RANGER_HEARTSEEKER : SPELL_BANSHEES_HEARTSEEKER);
            else if (!me->IsWithinCombatRange(me->GetVictim(), 7.5f))
            {
                if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    DoCastSelf(SPELL_RANGER_BOW_STANCE);
                else
                    DoCastVictim(SPELL_RANGER_SHOT);
            }
            else
            {
                switch (_meleeKitCombo)
                {
                    case DATA_MELEE_COMBO_SWITCH_TO_MELEE:
                        if (!me->HasAura(SPELL_RANGER_DAGGERS_STANCE))
                            DoCastSelf(SPELL_RANGER_DAGGERS_STANCE);
                        _meleeKitCombo++;
                        break;

                    case DATA_MELEE_COMBO_RANGER_STRIKE_01:
                    case DATA_MELEE_COMBO_RANGER_STRIKE_02:
                        DoCastVictim(SPELL_RANGER_STRIKE);
                        _meleeKitCombo++;
                        break;

                    case DATA_MELEE_COMBO_SWITCH_TO_RANGED:
                        if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                            DoCastSelf(SPELL_RANGER_BOW_STANCE);
                        _meleeKitCombo++;
                        break;

                    case DATA_MELEE_COMBO_FINISH:
                        DoCastVictim(SPELL_RANGER_SHOT);
                        DoAction(ACTION_RESET_MELEE_KIT);
                        break;
                    default:
                        break;
                }
            }

            me->resetAttackTimer(BASE_ATTACK);
        }
    }

    void ChooseDesecratingShotPattern(uint8 pattern)
    {
        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            {
                int32 step = 1;

                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
                {
                    float orientation = me->GetAbsoluteAngle(target);

                    while (DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_STRAIGHT, 0, step, me->GetPosition(), orientation))
                        ++step;

                    scheduler.Schedule(2s, [this](TaskContext /*task*/)
                    {
                        if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                            ai->StartDesecratingShotEvent(DATA_DESECRATING_SHOT_PATTERN_STRAIGHT, me->GetPosition());
                    });
                }
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                int32 step = 1;

                int32 amount = std::max<uint8>(4, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 3));

                while (amount > 0 && DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_SCATTERED, amount, step, me->GetPosition(), me->GetOrientation()))
                    --amount;
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            {
                int32 step = 0;

                // WAVE

                scheduler.Schedule(2s, [this](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                        ai->StartDesecratingShotEvent(DATA_DESECRATING_SHOT_PATTERN_WAVE, me->GetPosition());
                });
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            {
                int32 step = 10;
                int32 nextCopy = 0;

                std::list<Unit*> targets;
                SelectTargetList(targets, 3, SelectTargetMethod::Random, 0, 500.0f, true, true);

                for (Unit* target : targets)
                {
                    while (step > 0 && DrawDesecratingShotPattern(DATA_DESECRATING_SHOT_PATTERN_SPIRAL, 0, step, target->GetPosition(), target->GetOrientation()))
                        --step;

                    nextCopy++;

                    scheduler.Schedule(1s + 500ms + Milliseconds(500 * nextCopy), [this, target](TaskContext /*task*/)
                    {
                        if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                            ai->StartDesecratingShotEvent(DATA_DESECRATING_SHOT_PATTERN_SPIRAL, target->GetPosition());
                    });
                }
                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
            {
                int32 step = 0;

                // JAR

                scheduler.Schedule(2s, [this](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                        ai->StartDesecratingShotEvent(DATA_DESECRATING_SHOT_PATTERN_JAR, me->GetPosition());
                });
                break;
            }

            default:
                break;
        }
    }

    bool DrawDesecratingShotPattern(uint8 pattern, uint32 amount, int32 step, Position pos, float orientation)
    {
        std::vector<Position> arrowPositions;

        switch (pattern)
        {
            case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
            {
                float distance = 7.0f * step;

                // Note: let's obtain the arrow's center so we can stop summoning arrows if it goes beyond the boundaries of the platform.
                Position arrowCenter(me->GetPositionX() + (std::cos(orientation) * distance), me->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

                if (!SylvanasFirstPhasePlatformCenter.IsInDist2d(&arrowCenter, PLATFORM_RADIUS))
                    return false;

                arrowPositions.push_back(arrowCenter);

                scheduler.Schedule(Milliseconds(step * 25), [this, arrowCenter](TaskContext /*task*/)
                {
                    me->CastSpell(arrowCenter, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                });

                Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
                arrowPositions.push_back(arrowInnerLeft);

                Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
                arrowPositions.push_back(arrowInnerRight);

                scheduler.Schedule(Milliseconds(step * 35), [this, arrowInnerLeft, arrowInnerRight](TaskContext /*task*/)
                {
                    me->CastSpell(arrowInnerLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    me->CastSpell(arrowInnerRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                });

                Position arrowOuterLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());
                arrowPositions.push_back(arrowOuterLeft);

                Position arrowOuterRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());
                arrowPositions.push_back(arrowOuterRight);


                scheduler.Schedule(Milliseconds(step * 50), [this, arrowOuterLeft, arrowOuterRight](TaskContext /*task*/)
                {
                    me->CastSpell(arrowOuterLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    me->CastSpell(arrowOuterRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                });

                // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                constexpr std::array<float, 5> travelSpeed = { 0.245000004768371f, 0.384000003337860f, 0.358999997377395f, 0.517000019550323f, 0.470999985933303f };

                for (uint8 i = 0; i < arrowPositions.size(); i++)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetSylvanasCopyAI(0))
                        shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed[i]);
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
            {
                // TODO: remove false param, it's just for testing.
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, false, true))
                {
                    float distance = frand(2.5f, 5.0f) * step;

                    // Note: let's obtain the arrow's center so we can stop summoning arrows if it goes beyond the boundaries of the platform.
                    Position arrowCenter(target->GetPositionX() + (std::cos(orientation) * distance), target->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

                    // TODO: it shouldn't return false at this point because it doesn't stop building, it's just the part that is outside won't spawn ATs and shouldn't be stored at all.
                    if (!SylvanasFirstPhasePlatformCenter.IsInDist2d(&arrowCenter, PLATFORM_RADIUS))
                        return false;

                    arrowPositions.push_back(arrowCenter);

                    scheduler.Schedule(Milliseconds(step * 5), [this, arrowCenter](TaskContext /*task*/)
                    {
                        me->CastSpell(arrowCenter, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });

                    Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
                    arrowPositions.push_back(arrowInnerLeft);

                    scheduler.Schedule(Milliseconds(step * 50), [this, arrowInnerLeft](TaskContext /*task*/)
                    {
                        me->CastSpell(arrowInnerLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });

                    Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
                    arrowPositions.push_back(arrowInnerRight);

                    scheduler.Schedule(Milliseconds(step * 100), [this, arrowInnerRight](TaskContext /*task*/)
                    {
                        me->CastSpell(arrowInnerRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });

                    // Note: after hours of research and Pitagoras, each part of the arrow has a different travelSpeed.
                    constexpr std::array<float, 3> travelSpeed = { 0.245000004768371f, 0.384000003337860f, 0.470999985933303f };

                    for (uint8 i = 0; i < arrowPositions.size(); i++)
                    {
                        if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetSylvanasCopyAI(0))
                            shadowCopyAI->StoreDesecratingShots(arrowPositions[i], step, travelSpeed[i]);
                    }
                }

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_WAVE:
            {
                /*
                float distance = -4.0f * step;

                if (step == 0)
                {
                    Position middleLine(pos.GetPositionX() + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation) * distance), pos.GetPositionZ());

                    me->CastSpell(middleLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);

                    Position rightLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * 4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * 4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                    me->CastSpell(rightLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);

                    Position leftLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * -4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * -4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                    me->CastSpell(leftLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                }
                else
                {
                    scheduler.Schedule(50ms, [this, pos, orientation, distance](TaskContext /*task*//*)
                    {
                        Position rightLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * 4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * 4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                        me->CastSpell(rightLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });

                    scheduler.Schedule(75ms, [this, pos, orientation, distance](TaskContext /*task*//*)/*
                    {
                        Position leftLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * -4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * -4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                        me->CastSpell(leftLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });

                    scheduler.Schedule(100ms, [this, pos, orientation, distance](TaskContext /*task*//*)/*
                    {
                        Position middleLine(pos.GetPositionX() + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation) * distance), pos.GetPositionZ());

                        me->CastSpell(middleLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });
                }
                */

                return true;
            }

            case DATA_DESECRATING_SHOT_PATTERN_SPIRAL:
            {
                float distance = 40.0f;

                float angle = 0.1f * (step - 1);

                uint8 spiralCount = 3;

                switch (step)
                {
                    case 1:
                    {
                        me->CastSpell(pos, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                        break;
                    }

                    case 10:
                    {
                        LastFrontSpiralPoint = { pos.GetPositionX() + (std::cos(orientation + 0.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionY() + (std::sin(orientation + 0.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionZ() };
                        LastLeftSpiralPoint = { pos.GetPositionX() + (std::cos(orientation + 120.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionY() + (std::sin(orientation + 120.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionZ() };
                        LastRightSpiralPoint = { pos.GetPositionX() + (std::cos(orientation + -120.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionY() + (std::sin(orientation + -120.0f * float(M_PI) / 180.0f) * 26.29406f), pos.GetPositionZ() };

                        scheduler.Schedule(Milliseconds(step * 25), [this](TaskContext /*task*/)
                        {
                            me->CastSpell(LastFrontSpiralPoint, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                            me->CastSpell(LastLeftSpiralPoint, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                            me->CastSpell(LastRightSpiralPoint, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                        });

                        break;
                    }

                    default:
                    {
                        Position pointToConvert;
                        Position nextPoint;

                        for (uint8 i = 0; i < spiralCount; i++)
                        {
                            switch (i)
                            {
                                case 0:
                                    pointToConvert = LastFrontSpiralPoint;

                                    nextPoint = { pointToConvert.GetPositionX() + std::cos(angle) * distance * angle / (2 * float(M_PI)), pointToConvert.GetPositionY() + std::sin(angle) * distance * angle / (2 * float(M_PI)),
                                        pointToConvert.GetPositionZ() };
                                    break;

                                case 1:
                                    pointToConvert = LastLeftSpiralPoint;

                                    nextPoint = { pointToConvert.GetPositionX() + std::cos(angle + (float(M_PI) / 1.5f)) * distance * angle / (2 * float(M_PI)), pointToConvert.GetPositionY() + std::sin(angle + (float(M_PI) / 1.5f)) * distance * angle / (2 * float(M_PI)),
                                        pointToConvert.GetPositionZ()};
                                    break;

                                case 2:
                                    pointToConvert = LastRightSpiralPoint;

                                    nextPoint = { pointToConvert.GetPositionX() + std::cos(angle - (float(M_PI) / 1.5f)) * distance * angle / (2 * float(M_PI)), pointToConvert.GetPositionY() + std::sin(angle - (float(M_PI) / 1.5f)) * distance * angle / (2 * float(M_PI)),
                                        pointToConvert.GetPositionZ() };
                                    break;

                                default:
                                    break;
                            }

                            scheduler.Schedule(Milliseconds(step * 25), [this, nextPoint](TaskContext /*task*/)
                            {
                                 me->CastSpell(nextPoint, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                            });
                        }

                        break;
                    }
                }

                break;
            }

            case DATA_DESECRATING_SHOT_PATTERN_JAR:
            {
                break;
            }

            default:
                break;
        }

        return true;
    }

    void TeleportShadowcopiesToMe()
    {
        for (ObjectGuid const& shadowCopiesGUID : _shadowCopyGUID)
        {
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, shadowCopiesGUID))
                shadowCopy->NearTeleportTo(me->GetPosition(), false);
        }
    }

    bool IsHeartseekerReady()
    {
        Aura* heartseekerCharge = me->GetAura(events.IsInPhase(PHASE_ONE) ? SPELL_RANGER_HEARTSEEKER_CHARGE : SPELL_BANSHEES_HEARTSEEKER_CHARGE);

        if (heartseekerCharge && heartseekerCharge->GetStackAmount() >= 3)
            return true;
        else
            return false;

        return true;
    }

    void HandleCombatRelatedEventsForPhaseOne()
    {
        switch (me->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
            {
                break;
            }

            case DIFFICULTY_NORMAL_RAID:
            {
                events.SetPhase(PHASE_ONE);
                events.ScheduleEvent(EVENT_WINDRUNNER, 7s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 23s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, 44s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);

                // Note: we use a different event handler for Wailing Arrow because the marker is cast during events.
                _specialEvents.SetPhase(PHASE_ONE);
                _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW, 27s + 500ms, GROUP_EVENT_WAILING_ARROW_EVENTS, PHASE_ONE);
                break;
            }

            case DIFFICULTY_HEROIC_RAID:
            {
                break;
            }

            case DIFFICULTY_MYTHIC_RAID:
            {
                break;
            }

            default:
                break;
        }
    }

    void HandleWindrunnerRelatedEvents()
    {
        switch (me->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
            {
                switch (_windrunnerCastTimes)
                {
                    case DATA_WINDRUNNER_CAST_TIME_ONE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_TWO:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_THREE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_FOUR:
                    {
                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            case DIFFICULTY_NORMAL_RAID:
            {
                switch (_windrunnerCastTimes)
                {
                    case DATA_WINDRUNNER_CAST_TIME_ONE:
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 11000));
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); 
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 3s + 141ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 5s + 797ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 7s + 750ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s + 200ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT_LAUNCH, 10s + 391ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WINDRUNNER, 55s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_TWO:
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 13000));
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 3s + 31ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // The disappear should happen at 6s + 31ms
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 8s + 422ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s + 800ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // The disappear should happen at 12s + 828ms
                        // Note: Sniffs are not consistent on the queuing of this event. May be related to a dynamic handling based on the stance Sylvanas starts the encounter.
                        events.ScheduleEvent(EVENT_WINDRUNNER, 55s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_THREE:
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 15000));
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 1ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // The disappear should happen at 2s + 750ms
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 5s + 438ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 8s + 594ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 9s, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // The disappear should happen at 11s + 219ms
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 13s + 78ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        // Note: Sniffs are not consistent on the queuing of this event. May be related to a dynamic handling based on the stance Sylvanas starts the encounter.
                        events.ScheduleEvent(EVENT_WINDRUNNER, 55s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                        break;
                    }

                    // Note: I won't update this on normal since groups do not take that long to have a fourth cast. We'll have to wait until DF.
                    case DATA_WINDRUNNER_CAST_TIME_FOUR:
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 17000));
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE); // Fixed
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 500ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 5ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 5ms, GROUP_EVENT_WINDRUNNER_RELATED_EVENTS, PHASE_ONE);
                        // Note: Sniffs are not consistent on the queuing of this event. May be related to a dynamic handling based on the stance Sylvanas starts the encounter in.
                        events.ScheduleEvent(EVENT_WINDRUNNER, 53s, GROUP_EVENT_NORMAL_EVENTS, PHASE_ONE);
                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            case DIFFICULTY_HEROIC_RAID:
            {
                switch (_windrunnerCastTimes)
                {
                    case DATA_WINDRUNNER_CAST_TIME_ONE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_TWO:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_THREE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_FOUR:
                    {
                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            case DIFFICULTY_MYTHIC_RAID:
            {
                switch (_windrunnerCastTimes)
                {
                    case DATA_WINDRUNNER_CAST_TIME_ONE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_TWO:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_THREE:
                    {
                        break;
                    }

                    case DATA_WINDRUNNER_CAST_TIME_FOUR:
                    {
                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            default:
                break;
        }
    }

    bool IsPlatformDesecrated(int8 index)
    {
        switch (index)
        {
            case DATA_MALDRAXXI_PLATFORM:
                return _maldraxxiDesecrated;
            case DATA_NIGHTFAE_PLATFORM:
                return _nightfaeDesecrated;
            case DATA_KYRIAN_PLATFORM:
                return _kyrianDesecrated;
            case DATA_VENTHYR_PLATFORM:
                return _venthyrDesecrated;
            default:
                break;
        }
        return true;
    }

    void DesecrateCurrentPlatform(int8 index)
    {
        switch (index)
        {
            case DATA_MALDRAXXI_PLATFORM:
                _maldraxxiDesecrated = true;
                break;

            case DATA_NIGHTFAE_PLATFORM:
                _nightfaeDesecrated = true;
                break;

            case DATA_KYRIAN_PLATFORM:
                _kyrianDesecrated = true;
                break;

            case DATA_VENTHYR_PLATFORM:
                _venthyrDesecrated = true;
                break;

            default:
                break;
        }
    }

    Position const GetMiddlePointInCurrentPlatform()
    {
       for (uint8 covenentPlaform = 0; covenentPlaform < 4; covenentPlaform++)
       {
           if (me->IsWithinBox(CovenantPlatformPos[covenentPlaform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 14.0f, 14.0f, 14.0f))
               return CovenantPlatformPos[covenentPlaform][DATA_MIDDLE_POS_OUTTER_PLATFORM];
       }

        return { };
    }

    Position const GetRandomPointInCurrentPlatform()
    {
        for (uint8 covenentPlaform = 0; covenentPlaform < 4; covenentPlaform++)
        {
            if (me->IsWithinBox(CovenantPlatformPos[covenentPlaform][DATA_MIDDLE_POS_OUTTER_PLATFORM], 14.0f, 14.0f, 14.0f))
                return GetRandomPointInCovenantPlatform(CovenantPlatformPos[covenentPlaform][DATA_BOTTOM_LEFT_POS_VERTEX_PLATFORM], CovenantPlatformPos[covenentPlaform][DATA_TOP_RIGHT_POS_VERTEX_PLATFORM], me->GetPositionZ());
        }

        return { };
    }

    Position const GetRandomPointInNonDesecratedPlatform(int8 index)
    {
        switch (index)
        {
            case DATA_MALDRAXXI_PLATFORM:
            case DATA_NIGHTFAE_PLATFORM:
            case DATA_KYRIAN_PLATFORM:
            case DATA_VENTHYR_PLATFORM:
                return GetRandomPointInCovenantPlatform(CovenantPlatformPos[index][DATA_BOTTOM_LEFT_POS_VERTEX_PLATFORM], CovenantPlatformPos[index][DATA_TOP_RIGHT_POS_VERTEX_PLATFORM], me->GetPositionZ());
                break;
            default:
                break;
        }

        return { };
    }

    ObjectGuid GetShadowCopyGuid(int32 index)
    {
        return _shadowCopyGUID[index];
    }

    npc_sylvanas_windrunner_shadowcopy* GetSylvanasCopyAI(int32 index)
    {
        Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[index]);

        if (!shadowCopy)
            return nullptr;

        return CAST_AI(npc_sylvanas_windrunner_shadowcopy, shadowCopy->AI());
    }

private:
    EventMap _specialEvents;
    std::vector<ObjectGuid> _shadowCopyGUID;
    std::vector<ObjectGuid> _invigoratingFieldGUID;
    std::list<Player*> _witheringFireTargetList;
    bool _maldraxxiDesecrated;
    bool _nightfaeDesecrated;
    bool _kyrianDesecrated;
    bool _venthyrDesecrated;
    uint8 _meleeKitCombo;
    uint8 _windrunnerCastTimes;
    uint8 _desecratingShotCastTimes;
    uint8 _desecratingShotPattern;
    uint8 _wailingArrowCastTimes;
    uint8 _riveCastTimes;
    uint8 _hauntingWaveTimes;
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

                if (Unit* target = SelectTarget(SelectTargetMethod::MinDistance, 0, 250.0f, true, true, -SPELL_DOMINATION_CHAIN_PLAYER))
                {
                    _playerGUID = target->GetGUID();

                    me->CastSpell(target, SPELL_DOMINATION_CHAIN_PLAYER, false);

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
            if (chainedPlayer->HasAura(SPELL_DOMINATION_CHAIN_PLAYER))
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
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_bow);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1600));

        if (caster->HasAura(SPELL_RANGER_DAGGERS_STANCE))
            caster->RemoveAura(SPELL_RANGER_DAGGERS_STANCE);

        if (urand(0, 1))
            caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN, 0, 0);
        else
            caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW, 0, 0);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(16ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_RANGED, 0), caster->m_Events.CalculateTime(328ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_ATTACK_SPEED_TO_HIGHEST, 0), caster->m_Events.CalculateTime(547ms));
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_bow::OnCast);
    }
};

// 348010 - Ranger (Dagger)
class spell_sylvanas_windrunner_ranger_dagger : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_dagger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));

        if (caster->HasAura(SPELL_RANGER_BOW_STANCE))
            caster->RemoveAura(SPELL_RANGER_BOW_STANCE);

        if (urand(0, 1))
            caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN, 0, 0);
        else
            caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS, 0, 0);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(16ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_MELEE, 0), caster->m_Events.CalculateTime(313ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_ATTACK_SPEED_TO_LOWEST, 0), caster->m_Events.CalculateTime(547ms));
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_dagger::OnCast);
    }
};

// 347548 - Ranger Shot
class spell_sylvanas_windrunner_ranger_shot : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_shot);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));
    }

    void Register() override { }
};

// 348299 - Ranger Strike
class spell_sylvanas_windrunner_ranger_strike : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_strike);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (urand(0, 1))
            caster->SendPlaySpellVisual(caster->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_RIGHT, 0, 0, 1.0f, true);
        else
            caster->SendPlaySpellVisual(caster->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_LEFT, 0, 0, 1.0f, true);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_strike::OnCast);
    }
};

// 347504 - Windrunner
class spell_sylvanas_windrunner_windrunner : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_windrunner);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        target->m_Events.AddEvent(new PauseAttackState(target, true), target->m_Events.CalculateTime(0ms));
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        target->m_Events.AddEvent(new PauseAttackState(target, false), target->m_Events.CalculateTime(0ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_windrunner::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_windrunner::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352303 - Windrunner (Disappear 01)
// 358975 - Windrunner (Disappear 02)
class spell_sylvanas_windrunner_disappear : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_disappear);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // TODO: the first one is used for Windrunner, the duration is dynamic, most likely dependent on the action performed whereas the second is only for Domination Chains and rest of the phases.
        if (GetSpellInfo()->Id == SPELL_WINDRUNNER_DISAPPEAR_02)
            caster->CastSpell(caster, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3600));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_disappear::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347928 - Withering Fire
class spell_sylvanas_windrunner_withering_fire : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_withering_fire);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (sylvanas->GetAreaId() == AREA_PINNACLE_OF_DOMINANCE)
                    sylvanas->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
            }
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
    PrepareSpellScript(spell_sylvanas_windrunner_desecrating_shot);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_desecrating_shot::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class HeartseekerDamageEvent : public BasicEvent
{
    public:
        HeartseekerDamageEvent(Unit* actor, Unit* victim) : _actor(actor), _victim(victim) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_actor->GetAreaId() == AREA_PINNACLE_OF_DOMINANCE)
            {
                _actor->CastSpell(_victim, SPELL_RANGER_HEARTSEEKER_PHYSICAL_DAMAGE, true);
                _actor->CastSpell(_victim, SPELL_RANGER_HEARTSEEKER_SHADOW_DAMAGE, true);

                return true;
            }
            else
            {
                _actor->CastSpell(_victim, SPELL_BANSHEES_HEARTSEEKER_PHYSICAL_DAMAGE, true);
                _actor->CastSpell(_victim, SPELL_BANSHEES_HEARTSEEKER_SHADOW_DAMAGE, true);

                return true;
            }

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

            uint32 timeToTarget = _actor->GetDistance(_victim) * (0.0277 * 1000);

            _actor->m_Events.AddEvent(new HeartseekerDamageEvent(_actor, _victim), _actor->m_Events.CalculateTime(Milliseconds(timeToTarget)));

            if (Aura* heartseeker = _actor->GetAura(_actor->GetAreaId() == AREA_PINNACLE_OF_DOMINANCE ? SPELL_RANGER_HEARTSEEKER_CHARGE : SPELL_BANSHEES_HEARTSEEKER_CHARGE))
                heartseeker->ModStackAmount(-1, AuraRemoveMode::AURA_REMOVE_BY_DEFAULT);

            return true;
        }

    private:
        Unit* _actor;
        Unit* _victim;
};

// 352663 - Ranger's Heartseeker
class spell_sylvanas_windrunner_ranger_heartseeker : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_heartseeker);

    void OnPrecast() override
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Note: according to sniff, there's only a SMSG_AURA_UPDATE sent after SMSG_SPELL_START. There's no SMSG_SPELL_START or SMSG_SPELL_GO for this case.
        caster->AddAura(SPELL_RANGER_BOW_STANCE, caster);

        Unit* actualTank = caster->GetVictim();
        if (!actualTank)
            return;

        caster->SetFacingToObject(actualTank);

        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_UNARMED, 0), caster->m_Events.CalculateTime(0ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_SHEATHE_TO_RANGED, 0), caster->m_Events.CalculateTime(328ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), caster->m_Events.CalculateTime(343ms));
        caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), caster->m_Events.CalculateTime(2s));
    }

    void HandleTriggerSpell(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Note: the default duration is 4s and this should be 3.75s, so we need to prevent to send the correct duration.
        PreventHitDefaultEffect(effIndex);
        caster->CastSpell(caster, GetEffectInfo().TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3750));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_heartseeker::HandleTriggerSpell, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

class spell_sylvanas_windrunner_ranger_heartseeker_aura : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_ranger_heartseeker_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* actualTank = caster->GetVictim();
        if (!actualTank)
            return;

        caster->SetFacingToObject(actualTank);

        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, actualTank), caster->m_Events.CalculateTime(1ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, actualTank), caster->m_Events.CalculateTime(281ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, actualTank), caster->m_Events.CalculateTime(562ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_ranger_heartseeker_aura::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352652 - Ranger's Heartseeker (Shadow damage)
class spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BANSHEE_MARK });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_MARK, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 349419 - Domination Chains
class spell_sylvanas_windrunner_domination_chains : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_domination_chains);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_DOMINATION_CHAINS_FINISH, 0, 0);
    }

    void HandleAfterCast()
    {
        std::list<Creature*> arrowList;
        GetCreatureListWithEntryInGrid(arrowList, GetCaster(), NPC_DOMINATION_ARROW, 500.0f);

        for (Creature* arrow : arrowList)
            if (arrow->IsAIEnabled())
                arrow->AI()->DoAction(ACTION_ACTIVATE_DOMINATION_ARROW);
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
    PrepareSpellScript(spell_sylvanas_windrunner_domination_arrow);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_domination_arrow::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 349451 - Domination Chain (Player)
class spell_sylvanas_windrunner_domination_chain : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_domination_chain);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINATION_CHAIN_PERIODIC });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        _playerGUID = GetTarget()->GetGUID();

        if (GetTarget()->HasAura(SPELL_BARBED_ARROW))
            GetTarget()->RemoveAura(SPELL_BARBED_ARROW);

        GetCaster()->CastSpell(GetTarget(), SPELL_DOMINATION_CHAIN_PERIODIC, true);

        _arrowAreaTriggerGUID = AreaTrigger::CreateNewMovementForceId(GetCaster()->GetMap(), DATA_AREATRIGGER_DOMINATION_ARROW);

        GetTarget()->ApplyMovementForce(_arrowAreaTriggerGUID, GetCaster()->GetPosition(), 3.20000004768371582f, MovementForceType::Gravity);
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
    PrepareAuraScript(spell_sylvanas_windrunner_domination_chain_periodic);

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        if (aurEff->GetTickNumber() == 3)
            GetCaster()->CastSpell(GetTarget(), SPELL_DOMINATION_CHAIN_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_domination_chain_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 347609 - Wailing Arrow
class spell_sylvanas_windrunner_wailing_arrow : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_wailing_arrow);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    int32 CalcCastTime(int32 castTime) override
    {
        if (GetCaster()->GetMap()->GetWorldStateValue(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE) == 3)
            return 1500;

        return castTime;
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetMap()->GetWorldStateValue(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE) == 1)
        {
            caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), caster->m_Events.CalculateTime(1s + 531ms));
            caster->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(caster, DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), caster->m_Events.CalculateTime(3s + 31ms));
        }
    }

    void OnCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow::OnCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 348056 - Wailing Arrow (Trigger)
class spell_sylvanas_windrunner_wailing_arrow_trigger : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_wailing_arrow_trigger);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            spellInfo->GetEffect(EFFECT_0).TriggerSpell,
            spellInfo->GetEffect(EFFECT_1).TriggerSpell
        });
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
    PrepareSpellScript(spell_sylvanas_windrunner_wailing_arrow_raid_damage);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (!caster)
            return;

        // Note: this is completely based off research on different sniffs. The reduction might be inaccurate, but it's pretty close to Blizzard's.
        uint32 damage = GetHitDamage();

        float distanceDmgMod = caster->GetExactDist2d(GetHitUnit()) / 4.5f;

        if (distanceDmgMod < 1.0f)
            return;

        damage /= distanceDmgMod;

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_raid_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 352470 - Veil of Darkness (Fase - Phase 1)
// 353273 - Veil of Darkness (Fade - Phase 2)
// 354168 - Veil of Darkness (Fase - Phase 3)
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
        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 9750));
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        GetCaster()->GetInstanceScript()->DoCastSpellOnPlayers(SPELL_VEIL_OF_DARKNESS_SCREEN_FOG);
        GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_DARKNESS_DESELECT, true);
        GetCaster()->SetPower(GetCaster()->GetPowerType(), 0);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_veil_of_darkness_fade::OnCast);
    }
};

// 347726 - Veil of Darkness (Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_phase_1 : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_1);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell,
            spellInfo->GetEffect(EFFECT_1).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        GetCaster()->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);
        GetCaster()->SetAnimTier(AnimTier::Fly);

        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_SHEATHE_TO_UNARMED, 0), GetCaster()->m_Events.CalculateTime(1ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), GetCaster()->m_Events.CalculateTime(25ms));

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS, 0, 0);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void HandleAfterCast()
    {
        GetCaster()->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);
        GetCaster()->SetAnimTier(AnimTier::Ground);

        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), GetCaster()->m_Events.CalculateTime(25ms));

        GetCaster()->m_Events.AddEvent(new PauseAttackState(GetCaster(), false), GetCaster()->m_Events.CalculateTime(250ms));
        GetCaster()->resetAttackTimer(BASE_ATTACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleAfterCast);
    }
};

// 353417 - Rive
// 353418 - Rive (Fast)
class spell_sylvanas_windrunner_rive : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_rive);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RIVE_CHAIN,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                {
                    if (Creature* shadowCopy3 = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyGuid(3)))
                    {
                        shadowCopy3->CastSpell(sylvanas, GetSpellInfo()->Id == SPELL_RIVE ? SPELL_RIVE_CHAIN : SPELL_RIVE_CHAIN_FAST, false);

                        // TODO: change the type of searching to avoid exploiting from players.
                        if (GameObject* platformSpire = shadowCopy3->FindNearestGameObjectOfType(GameobjectTypes::GAMEOBJECT_TYPE_GOOBER, 15.0f))
                            platformSpire->SetSpellVisualId(GetSpellInfo()->Id == SPELL_RIVE ? SPELL_VISUAL_TORGHAST_SPIRE_BREAK : SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST, sylvanas->GetGUID());
                    }
                }
            }
        }
    }

    void HandleAfterCast()
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                {
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyGuid(0)))
                        sylvanas->CastSpell(shadowCopy->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
                }
            }
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_rive::HandleAfterCast);
    }
};

// 348094 - Banshee Wail
class spell_sylvanas_windrunner_banshee_wail : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_banshee_wail);

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
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(caster, SPELL_BANSHEE_WAIL_EXPIRE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));

            std::list<Player*> targetList;
            GetPlayerListInGrid(targetList, caster, 250.0f);

            for (Player* target : targetList)
                caster->CastSpell(target, SPELL_BANSHEE_WAIL_MARKER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4650));
        }
    }

    void HandleAfterCast()
    {
        if (Unit* caster = GetCaster())
        {
            std::list<Player*> targetList;
            GetPlayerListInGrid(targetList, caster, 250.0f);

            for (Player* target : targetList)
                caster->CastSpell(target, GetEffectInfo(EFFECT_0).TriggerSpell, true);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_banshee_wail::HandleAfterCast);
    }
};

// 357719 - Banshee Wail (Marker)
class spell_sylvanas_windrunner_banshee_wail_marker : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_banshee_wail_marker);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM_EXPIRE, 0, 0);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_wail_marker::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 348108 - Banshee Wail (Triggered Missile)
class spell_sylvanas_windrunner_banshee_wail_triggered_missile : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_banshee_wail_triggered_missile);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            spellInfo->GetEffect(EFFECT_0).TriggerSpell,
            spellInfo->GetEffect(EFFECT_1).TriggerSpell
        });
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
    PrepareSpellScript(spell_sylvanas_windrunner_banshee_wail_interrupt);

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

// 352271 - Haunting Wave
class spell_sylvanas_windrunner_haunting_wave : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_haunting_wave);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        for (uint8 itr = 0; itr < 2; itr++)
        {
            for (uint8 i = 0; i < _waveCount; ++i)
            {
                float angle;

                if (itr == 1)
                    angle = _angleOffset * i;
                else
                    angle = 3.0f + _angleOffset * i;

                Position dest = { GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), angle };

                if (itr == 1)
                    GetCaster()->m_Events.AddEvent(new HauntingWaveEvent(GetCaster(), dest, GetEffectInfo(EFFECT_0).TriggerSpell), GetCaster()->m_Events.CalculateTime(26ms * i));
                else
                    GetCaster()->m_Events.AddEvent(new HauntingWaveEvent(GetCaster(), dest, GetEffectInfo(EFFECT_0).TriggerSpell), GetCaster()->m_Events.CalculateTime(658ms + 26ms * i));
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
class spell_sylvanas_windrunner_ruin: public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_ruin);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, GetCaster(), 500.0f);

        if (playerList.size() > 2)
            Trinity::Containers::RandomResize(playerList, 2);

        // TODO: find out why this is kinda buggy atm.
        for (Player* target : playerList)
        {
            GetCaster()->CastSpell(*target, SPELL_RUIN_VISUAL, true);
            GetCaster()->CastSpell(*target, aurEff->GetSpellEffectInfo().TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_ruin::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 353969 - Banshee's Heartseeker
class spell_sylvanas_windrunner_banshees_heartseeker : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_banshees_heartseeker);

    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_SHEATHE_TO_UNARMED, 0), GetCaster()->m_Events.CalculateTime(16ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_SHEATHE_TO_RANGED, 0), GetCaster()->m_Events.CalculateTime(328ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_RIDING_COPY, 0), GetCaster()->m_Events.CalculateTime(343ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheOrNameplateOrAttackSpeed(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_SYLVANAS, 0), GetCaster()->m_Events.CalculateTime(2s));
    }

    void Register() override { }
};

class spell_sylvanas_windrunner_banshees_heartseeker_aura : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_banshees_heartseeker_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* currentTank = caster->GetVictim();
        if (!currentTank)
            return;

        // TODO: find out if this is needed since it's a channel spell, it should be handled by spell itself.
        caster->SetFacingToObject(currentTank);

        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, currentTank), caster->m_Events.CalculateTime(1ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, currentTank), caster->m_Events.CalculateTime(281ms));
        caster->m_Events.AddEvent(new HeartseekerMissileEvent(caster, currentTank), caster->m_Events.CalculateTime(562ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_banshees_heartseeker_aura::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 353967 - Banshees's Heartseeker (Shadow damage)
class spell_sylvanas_windrunner_banshees_heartseeker_shadow_damage : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_banshees_heartseeker_shadow_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BANSHEES_BANE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEES_BANE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshees_heartseeker_shadow_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

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

// 354011 - Bane Arrows
class spell_sylvanas_windrunner_bane_arrows : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_bane_arrows);

    void OnPrecast() override
    {
        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_BANE_ARROWS, 0, 0);
    }

    void HandleAfterCast()
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                {
                    for (uint8 covenantPlatform = 0; covenantPlatform < 4; covenantPlatform++)
                    {
                        if (!ai->IsPlatformDesecrated(covenantPlatform))
                            return;

                        for (uint8 i = 0; i < 7; i++)
                        {
                            Position const baneArrowPos = ai->GetRandomPointInNonDesecratedPlatform(covenantPlatform);

                            uint32 randomSpeed = urand(2040, 3200);

                            sylvanas->SendPlaySpellVisual(baneArrowPos, 0.0f, SPELL_VISUAL_BANE_ARROW, 0, 0, float(randomSpeed / 1000), true);

                            sylvanas->m_Events.AddEvent(new BaneArrowEvent(sylvanas, baneArrowPos), sylvanas->m_Events.CalculateTime(Milliseconds(randomSpeed)));
                        }
                    }
                }
            }
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_bane_arrows::HandleAfterCast);
    }
};

class BansheeBaneEvent : public BasicEvent
{
    public:
        BansheeBaneEvent(Unit* actor, Position const bansheeBanePos) : _actor(actor), _bansheeBanePos(bansheeBanePos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _actor->CastSpell(_bansheeBanePos, SPELL_BANSHEES_BANE_AREATRIGGER, true);

            return true;
        }

    private:
        Unit* _actor;
        Position _bansheeBanePos;
};

// 353929 - Banshee's Bane
class spell_sylvanas_windrunner_banshee_bane : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_banshee_bane);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint8 stackAmount = GetStackAmount();

        float angleOffset = float(M_PI * 2) / stackAmount;

        for (uint8 i = 0; i < stackAmount; ++i)
        {
            Position bansheeBaneDest = GetTarget()->GetNearPosition(3.6f, angleOffset * i);

            if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    // TODO: not the best condition, maybe check for current boss state.
                    if (!sylvanas->IsInCombat())
                        return;

                    GetTarget()->SendPlaySpellVisual(bansheeBaneDest, 0.0f, SPELL_VISUAL_BANSHEES_BANE_DROP, 0, 0, 0.349999994039535522f, true);

                    sylvanas->m_Events.AddEvent(new BansheeBaneEvent(sylvanas, bansheeBaneDest), sylvanas->m_Events.CalculateTime(500ms));
                }
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_bane::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

class BansheesFuryEvent : public BasicEvent
{
    public:
        BansheesFuryEvent(Unit* actor, uint8 covenantPlatform) : _actor(actor), _covenantPlatform(covenantPlatform) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (InstanceScript* instance = _actor->GetInstanceScript())
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                    {
                        if (sylvanas->HasAura(SPELL_BANSHEES_FURY))
                            sylvanas->SendPlaySpellVisual(ai->GetRandomPointInNonDesecratedPlatform(_covenantPlatform), 0.0f, SPELL_VISUAL_BANSHEE_FURY, 0, 0, 0.100000001490116119f, true);
                    }
                }
            }

            return true;
        }

    private:
        Unit* _actor;
        uint8 _covenantPlatform;
};

// 354068 - Banshee's Fury
class spell_sylvanas_windrunner_banshee_fury : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_banshee_fury);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->SetNameplateAttachToGUID(ObjectGuid::Empty);
        GetCaster()->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);
        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_FURY_END, 0, 0);

        // TODO: check on every player if Banshee's Bane is on; if yes, trigger explode on them.
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                {
                    for (uint8 covenantPlatform = 0; covenantPlatform < 4; covenantPlatform++)
                    {
                        if (ai->IsPlatformDesecrated(covenantPlatform))
                            return;

                        for (uint8 i = 0; i < 10; i++)
                            GetCaster()->m_Events.AddEvent(new BansheesFuryEvent(GetCaster(), covenantPlatform), GetCaster()->m_Events.CalculateTime(50ms * i));
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_banshee_fury::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_fury::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class RazeEvent : public BasicEvent
{
    public:
        RazeEvent(Unit* actor) : _actor(actor) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (InstanceScript* instance = _actor->GetInstanceScript())
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                        sylvanas->SendPlaySpellVisual(ai->GetRandomPointInCurrentPlatform(), 0.0f, SPELL_VISUAL_RAZE, 0, 0, 0.100000001490116119f, true);
                }
            }

            return true;
        }

    private:
        Unit* _actor;
};

// 354147 - Raze
class spell_sylvanas_windrunner_raze : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_raze);

    void OnPrecast() override
    {
        for (uint8 i = 0; i < 100; i++)
            GetCaster()->m_Events.AddEvent(new RazeEvent(GetCaster()), GetCaster()->m_Events.CalculateTime(50ms * i));
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WINDRUNNER_DISAPPEAR_02, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_raze::HandleAfterCast);
    }
};

enum BolvarSpells
{
    SPELL_RUNIC_MARK                                    = 354926,
    SPELL_RUNIC_MARK_TRIGGERED                          = 354927,
    SPELL_GLYPH_OF_DESINTEGRATION                       = 354932,
    SPELL_CHARGE_TOWARDS_SYLVANAS                       = 357046,
    SPELL_WINDS_OF_ICECROWN                             = 356941,
    SPELL_WINDS_OF_ICECROWN_INTERRUPT                   = 356986
};

enum BolvarEvents
{
    EVENT_RUNIC_MARK                                    = 1,
    EVENT_GLYPH_OF_DESINTEGRATION
};

enum BolvarActions
{
    ACTION_WINDS_OF_ICECROWN                            = 1
};

enum BolvarTexts
{
    SAY_FIRST_CHAIN                                     = 0,
    SAY_SECOND_CHAIN                                    = 1,
    SAY_FIRST_RUIN                                      = 2,
    SAY_WINDS_OF_ICECROWN_01                            = 3,
    SAY_THIRD_CHAIN_START                               = 4,
    SAY_THIRD_CHAIN_FINISH                              = 5,
    SAY_WINDS_OF_ICECROWN_02                            = 9,
    SAY_PREPARE_PHASE_THREE                             = 11
};

enum BolvarMisc
{
    POINT_JUMP_SECOND_CHAIN                             = 2
};

Position const BolvarPrePhaseTwoPos =   { 204.64757f, -842.77606f, 4999.9956f,  0.7806f };

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

                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                _scheduler.Schedule(47ms, [this, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED, 0, 0);
                });

                _scheduler.Schedule(1s, [this, sylvanas](TaskContext /*task*/)
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->m_Events.AddEvent(new PauseAttackState(sylvanas, false), sylvanas->m_Events.CalculateTime(1ms));
                });

                _scheduler.Schedule(1s + 454ms, [this, sylvanas](TaskContext /*task*/)
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->Talk(SAY_WINDS_OF_ICECROWN_AFTER_01);
                });
            }
            else
            {
                sylvanas->RemoveAura(SPELL_BANSHEE_READY_STANCE);
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WINDS_02, 0, 0);

                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                _scheduler.Schedule(47ms, [this, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED, 0, 0);
                });

                _scheduler.Schedule(1s, [this, sylvanas](TaskContext /*task*/)
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->m_Events.AddEvent(new PauseAttackState(sylvanas, false), sylvanas->m_Events.CalculateTime(1ms));
                });

                _scheduler.Schedule(1s + 454ms, [this, sylvanas](TaskContext /*task*/)
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->Talk(SAY_WINDS_OF_ICECROWN_AFTER_02);
                });
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        if (me->HealthBelowPctDamaged(85.0f, damage))
            damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (me->IsAIEnabled())
                me->AI()->AttackStart(sylvanas);
        }

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
                        Talk(SAY_WINDS_OF_ICECROWN_01);
                    else
                        Talk(SAY_WINDS_OF_ICECROWN_02);

                    me->CastSpell(sylvanas, SPELL_CHARGE_TOWARDS_SYLVANAS, false);

                    _windsOfIcecrown++;
                }
                break;
            }

            case ACTION_WINDS_OF_ICECROWN:
            {
                _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        me->CastSpell(sylvanas, SPELL_WINDS_OF_ICECROWN, false);
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
    PrepareSpellScript(spell_sylvanas_windrunner_runic_mark_triggered);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, false);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_runic_mark_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357046 - Charge Towards Sylvanas
class spell_sylvanas_windrunner_charge_towards_sylvanas : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_charge_towards_sylvanas);

    void HandleCharge(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            {
                if (bolvar->IsAIEnabled())
                    bolvar->AI()->DoAction(ACTION_WINDS_OF_ICECROWN);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_charge_towards_sylvanas::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

// 356941 - Winds of Icecrown
class spell_sylvanas_windrunner_winds_of_icecrown : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_winds_of_icecrown);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WINDS_OF_ICECROWN_INTERRUPT });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
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
    SPELL_FLAMEAXE                                      = 354898,
    SPELL_PULVERIZE                                     = 354918,
    SPELL_STONECRASH                                    = 357139,
    SPELL_EARTHEN_GRASP                                 = 354900,

    SPELL_JUMP_PHASE_TWO_MASTER                         = 351862,
    SPELL_CALL_EARTH                                    = 352842,
    SPELL_CALL_EARTH_AREATRIGGER_01                     = 354576,
    SPELL_CALL_EARTH_AREATRIGGER_02                     = 354575,
    SPELL_CALL_EARTH_AREATRIGGER_03                     = 354577,
    SPELL_CALL_EARTH_BRIDGE_01                          = 351840,
    SPELL_CALL_EARTH_BRIDGE_02                          = 348093,
    SPELL_CALL_EARTH_BRIDGE_03                          = 351841
};

enum ThrallEvents
{
    EVENT_FLAMEAXE                                      = 1,
    EVENT_PULVERIZE,
    EVENT_STONECRASH_PHASE_ONE_AND_THREE,
    EVENT_EARTHEN_GRASP
};

enum ThrallActions
{
    ACTION_PREPARE_EARTH_BRIDGE_1                       = 1
};

enum ThrallTexts
{
    SAY_CROSSING_FIRST_BRIDGE                           = 0,
    SAY_FORMING_SECOND_BRIDGE                           = 1
};

Position const ThrallPrePhaseTwoPos =   { 209.80556f, -823.7917f, 4999.985f, 4.52320f };

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

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        if (me->HealthBelowPctDamaged(85.0f, damage))
            damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (me->IsAIEnabled())
                me->AI()->AttackStart(sylvanas);
        }

        _events.ScheduleEvent(EVENT_FLAMEAXE, 1s + 300ms, 1);
        _events.ScheduleEvent(EVENT_PULVERIZE, 7s, 1);
        //_events.ScheduleEvent(EVENT_STONECRASH_PHASE_ONE_AND_THREE, 8s + 400ms, 1, PHASE_ONE);
        _events.ScheduleEvent(EVENT_EARTHEN_GRASP, 9s + 800ms, 1);
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
                    Talk(SAY_FORMING_SECOND_BRIDGE);
                });

                _scheduler.Schedule(8s + 47ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        if (bolvar->IsAIEnabled())
                            bolvar->AI()->Talk(SAY_FIRST_RUIN);
                    }
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
        me->CastSpell(jumpPos, SPELL_JUMP_PHASE_TWO_MASTER, false);

        uint32 bridgeAreaTriggerSpell;
        uint32 bridgeGameObjectSpell;

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
            DoCastSelf(SPELL_CALL_EARTH, false);
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
    PrepareSpellScript(spell_sylvanas_windrunner_pulverize);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_pulverize::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 354923 - Pulverize (triggered)
class spell_sylvanas_windrunner_pulverize_triggered : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_pulverize_triggered);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_pulverize_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357139 - Stonecrash (Phase 1 and 3)
class spell_sylvanas_windrunner_stonecrash_phase_one_and_three : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_stonecrash_phase_one_and_three);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_stonecrash_phase_one_and_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357137 - Stonecrash (Phase 2)
class spell_sylvanas_windrunner_stonecrash_phase_two : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_stonecrash_phase_two);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(EFFECT_1).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_stonecrash_phase_two::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum JainaSpells
{
    SPELL_ICE_BOLT                                      = 350002,
    SPELL_COMET_BARRAGE                                 = 354938,
    SPELL_FRIGID_SHARDS                                 = 354933,
    SPELL_CONE_OF_COLD                                  = 350003,
    SPELL_SEARING_BLAST                                 = 355507,

    SPELL_TELEPORT_TO_PHASE_2                           = 355073,
    SPELL_TELEPORT_PHASE_TWO_MASTER                     = 351890,
    SPELL_CHANNEL_ICE                                   = 352843,
    SPELL_CHANNEL_ICE_AREATRIGGER_01                    = 354476,
    SPELL_CHANNEL_ICE_AREATRIGGER_02                    = 354573,
    SPELL_CHANNEL_ICE_AREATRIGGER_03                    = 354574,
    SPELL_CHANNEL_ICE_BRIDGE_01                         = 348148,
    SPELL_CHANNEL_ICE_BRIDGE_02                         = 351837,
    SPELL_CHANNEL_ICE_BRIDGE_03                         = 351838,
    SPELL_PORTAL_TO_ORIBOS_PHASE_3                      = 357102,
    SPELL_TELEPORT_TO_PHASE_3                           = 350906,
    SPELL_TELEPORT_TO_PHASE_3_DEST                      = 357103,
    SPELL_FROZEN_SHELL                                  = 351762,
    SPELL_BLASPHEMY_STUN                                = 357728
};

enum JainaEvents
{
    EVENT_FRIGID_SHARDS                                 = 1,
    EVENT_CONE_OF_COLD,
    EVENT_COMET_BARRAGE
};

enum JainaActions
{
    ACTION_PREPARE_ICE_BRIDGE_1                         = 1,
    ACTION_PREPARE_ICE_BRIDGE_2,
    ACTION_PREPARE_ICE_BRIDGE_3
};

enum JainaTexts
{
    SAY_PREPARE_PHASE_TWO                               = 0,
    SAY_START_PHASE_TWO                                 = 1,
    SAY_CALL_FOR_AID                                    = 2,
    SAY_OVERRUN                                         = 3,
    SAY_THANKS                                          = 4,
    SAY_ENCOURAGE_PLAYERS                               = 5,
    SAY_AID_THRALL                                      = 6,
    SAY_FIGHTING_SYLVANAS                               = 7,
    SAY_ASK_FOR_ANDUIN                                  = 8,
    SAY_PREPARING_PORTAL_TO_PHASE_THREE                 = 9,
    SAY_FINISHING_PORTAL_TO_PHASE_THREE                 = 10,
    SAY_FINISHED_PORTAL_TO_PHASE_THREE                  = 11
};

enum JainaVisuals
{
    SPELL_VISUAL_KIT_JAINA_BREAK_BLASPHEMY              = 149324,
    SPELL_VISUAL_KIT_JAINA_TELEPORT_PLAYERS             = 149323
};

enum JainaPoints
{
    POINT_TELEPORT_TO_THIRD_CHAIN                       = 1,
    POINT_TELEPORT_TO_SIXTH_CHAIN                       = 2
};

enum JainaData
{
    DATA_CASTER_NON_POWERFUL_SPELL_01                   = 0,
    DATA_CASTER_NON_POWERFUL_SPELL_02                   = 1,
    DATA_CASTER_POWERFUL_SPELL_01                       = 2,
    DATA_CASTER_NON_POWERFUL_SPELL_03                   = 3,
    DATA_CASTER_POWERFUL_SPELL_02                       = 4,
    DATA_CASTER_NON_POWERFUL_SPELL_04                   = 5
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

Position const JainaPrePhaseThreePos =  { -258.666f, -1284.191f, 5667.1157f, 1.58863f };

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

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        if (me->HealthBelowPctDamaged(85.0f, damage))
            damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (me->IsAIEnabled())
                me->AI()->AttackStartCaster(sylvanas, 25.0f);
        }

        me->SetBaseAttackTime(BASE_ATTACK, 250);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OPEN_PORTAL_TO_PHASE_TWO:
            {
                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 250.0f);

                    me->NearTeleportTo(JainaPhaseTwoPos[0], false);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->NearTeleportTo(BolvarPrePhaseTwoPos, false);

                        if (bolvar->IsAIEnabled())
                            bolvar->m_Events.AddEvent(new PauseAttackState(me, true), bolvar->m_Events.CalculateTime(1ms));
                    }

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        thrall->NearTeleportTo(ThrallPrePhaseTwoPos, false);

                        if (thrall->IsAIEnabled())
                            thrall->m_Events.AddEvent(new PauseAttackState(thrall, true), thrall->m_Events.CalculateTime(1ms));
                    }

                    _scheduler.Schedule(50ms, [this, playerList](TaskContext /*task*/)
                    {
                        for (Player* player : playerList)
                            player->CastSpell(player, SPELL_TELEPORT_TO_PHASE_TWO, true);
                    });

                    _scheduler.Schedule(100ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_ANCHOR_HERE, true);

                        me->HandleEmoteCommand(EMOTE_STATE_READY1H_ALLOW_MOVEMENT);

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->CastSpell(bolvar, SPELL_ANCHOR_HERE, true);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                            thrall->CastSpell(thrall, SPELL_ANCHOR_HERE, true);
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

                    _scheduler.Schedule(1s, [this, sylvanas](TaskContext /*task*/)
                    {
                        if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                            ai->TeleportShadowcopiesToMe();
                    });

                    _scheduler.Schedule(2s + 750ms, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_PREPARE_PHASE_TWO);
                    });

                    _scheduler.Schedule(3s + 500ms, [this, sylvanas](TaskContext /*task*/)
                    {
                        if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyGuid(0)))
                                sylvanas->SetNameplateAttachToGUID(ai->GetShadowCopyGuid(0));

                            sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));

                            sylvanas->SendPlayOrphanSpellVisual(SylvanasWavePos[0], SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyGuid(0)))
                                shadowCopy->CastSpell(SylvanasWavePos[0], SPELL_WINDRUNNER_MOVE, true);
                        }
                    });

                    _scheduler.Schedule(4s, [this, sylvanas](TaskContext /*task*/)
                    {
                        sylvanas->NearTeleportTo(SylvanasWavePos[0], false);

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
                            bolvar->AI()->Talk(SAY_FIRST_CHAIN);
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
                    Talk(SAY_START_PHASE_TWO);
                });

                _scheduler.Schedule(5s + 593ms, [this](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->DoAction(ACTION_HAUNTING_WAVE_SECOND_CHAIN);
                    }
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
                        if (thrall->IsAIEnabled())
                            thrall->AI()->Talk(SAY_CROSSING_FIRST_BRIDGE);

                        thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_CHEERS, 0, 0);
                    }
                });

                _scheduler.Schedule(20s + 639ms, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        if (bolvar->IsAIEnabled())
                            bolvar->AI()->Talk(SAY_SECOND_CHAIN);
                    }
                });

                _scheduler.Schedule(29s + 685ms, [this](TaskContext /*task*/)
                {
                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        if (thrall->IsAIEnabled())
                            thrall->AI()->DoAction(ACTION_PREPARE_EARTH_BRIDGE_1);
                    }
                });
                break;
            }

            case ACTION_OPEN_PORTAL_TO_PHASE_THREE:
            {
                me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                {
                    if (bolvar->IsAIEnabled())
                        bolvar->m_Events.AddEvent(new PauseAttackState(bolvar, true), bolvar->m_Events.CalculateTime(1ms));
                }

                if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                {
                    if (thrall->IsAIEnabled())
                        thrall->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                }

                me->setActive(true);

                Talk(SAY_PREPARING_PORTAL_TO_PHASE_THREE);

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 250.0f);

                _scheduler.Schedule(500ms, [this, playerList](TaskContext /*task*/)
                {
                    me->NearTeleportTo(-233.971f, -1304.676f, 4999.984f, false);

                    for (Player* player : playerList)
                        player->NearTeleportTo(-233.971f, -1304.676f, 4999.984f, false);
                });

                _scheduler.Schedule(980ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
                });

                _scheduler.Schedule(1s + 800ms, [this](TaskContext /*task*/)
                {
                    Position const frontJainaPos = me->GetNearPosition(5.0f, 0.0f);

                    me->CastSpell(frontJainaPos, SPELL_PORTAL_TO_ORIBOS_PHASE_3, false);
                });

                _scheduler.Schedule(5s, [this](TaskContext /*task*/)
                {
                    Talk(SAY_FINISHING_PORTAL_TO_PHASE_THREE);

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->DoAction(ACTION_INITIATE_PHASE_THREE);
                    }
                });

                _scheduler.Schedule(12s, [this](TaskContext /*task*/)
                {
                    Talk(SAY_FINISHED_PORTAL_TO_PHASE_THREE);

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->SetFacingTo(4.8989f);
                });

                _scheduler.Schedule(12s + 250ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                    me->NearTeleportTo(JainaPrePhaseThreePos, false);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                        bolvar->NearTeleportTo(BolvarPrePhaseThreePos, false);
                    }

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                    {
                        thrall->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_GENERIC_TELEPORT, 0, 0);
                        thrall->NearTeleportTo(ThrallPrePhaseThreePos, false);
                    }
                });

                _scheduler.Schedule(12s + 300ms, [this, playerList](TaskContext /*task*/)
                {
                    for (Player* player : playerList)
                        player->CastSpell(me->GetPosition(), SPELL_TELEPORT_TO_PHASE_3, true);
                });

                _scheduler.Schedule(13s, [this, playerList](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
                });

                _scheduler.Schedule(13s + 200ms, [this, playerList](TaskContext /*task*/)
                {
                    for (Player* player : playerList)
                        player->CastSpell(player, SPELL_PLATFORMS_SCENE, true);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                    {
                        if (anduin->IsAIEnabled())
                            anduin->AI()->DoAction(ACTION_INITIATE_PHASE_THREE);
                    }
                });

                _scheduler.Schedule(15s, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        if (bolvar->IsAIEnabled())
                            bolvar->AI()->Talk(SAY_PREPARE_PHASE_THREE);
                    }
                });

                _scheduler.Schedule(18s + 950ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_FROZEN_SHELL, false);
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
                    Talk(SAY_ENCOURAGE_PLAYERS);
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
                    me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->SetFacingTo(2.3582f);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                    {
                        AttackStart(anduin);

                        me->CastSpell(anduin, SPELL_SEARING_BLAST, false);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                            thrall->m_Events.AddEvent(new PauseAttackState(thrall, false), thrall->m_Events.CalculateTime(1ms));

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            bolvar->m_Events.AddEvent(new PauseAttackState(bolvar, false), bolvar->m_Events.CalculateTime(1ms));

                        if (anduin->IsAIEnabled())
                            anduin->AI()->AttackStart(me);
                    }
                });

                _scheduler.Schedule(25s + 522ms, [this, playerList](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->DoAction(ACTION_START_PHASE_THREE);

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
                    DoCastVictim(SPELL_ICE_BOLT, CastSpellExtraArgs(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_POWERFUL_SPELL_01:
                    DoCastVictim(SPELL_COMET_BARRAGE);
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_NON_POWERFUL_SPELL_03:
                    DoCastVictim(SPELL_ICE_BOLT, CastSpellExtraArgs(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_POWERFUL_SPELL_02:
                    DoCastVictim(me->GetDistance(me->GetVictim()) > 8.0f ? SPELL_FRIGID_SHARDS : SPELL_CONE_OF_COLD);
                    _casterKitCombo++;
                    break;

                case DATA_CASTER_NON_POWERFUL_SPELL_04:
                    DoCastVictim(SPELL_ICE_BOLT, CastSpellExtraArgs(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
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
        me->CastSpell(teleportPos, SPELL_TELEPORT_PHASE_TWO_MASTER, false);

        uint32 bridgeAreaTriggerSpell;
        uint32 bridgeGameObjectSpell;

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
            DoCastSelf(SPELL_CHANNEL_ICE, false);
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
    PrepareAuraScript(spell_sylvanas_windrunner_frigid_shards);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_frigid_shards::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 354938 - Comet Barrage
class spell_sylvanas_windrunner_comet_barrage : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_comet_barrage);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_comet_barrage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 350903 - Teleport to Phase Two
class spell_sylvanas_windrunner_teleport_to_phase_two : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_teleport_to_phase_two);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                GetCaster()->CastSpell(jaina->GetRandomPoint(jaina->GetPosition(), frand(2.0f, 8.0f)), GetEffectInfo(EFFECT_0).TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_two::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 350906 - Teleport to Phase Three
class spell_sylvanas_windrunner_teleport_to_phase_three : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_teleport_to_phase_three);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                GetCaster()->CastSpell(jaina->GetRandomPoint(jaina->GetPosition(), frand(3.0f, 10.0f)), GetEffectInfo(EFFECT_0).TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357103 - Teleport
class spell_sylvanas_windrunner_teleport : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_teleport);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_teleport::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum AnduinSpells
{
    SPELL_BLASPHEMY_PRE                                 = 357729,
    SPELL_BLASPHEMY                                     = 357730,
    SPELL_BLASPHEMY_DAMAGE                              = 357731,
    SPELL_CRIPPLING_DEFEAT                              = 354176,

    SPELL_BREAK_PLAYER_TARGETTING                       = 140562
};

enum AnduinEvents
{
    EVENT_BLASPHEMY                                     = 1,
    EVENT_LIGHT_BLAST                                   = 2,
    EVENT_CRIPPLING_DEFEAT                              = 3
};

// 178072 - Anduin Wrynn
struct npc_sylvanas_windrunner_anduin : public ScriptedAI
{
    npc_sylvanas_windrunner_anduin(Creature* creature) : ScriptedAI(creature, DATA_ANDUIN_CRUCIBLE),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();

        me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
    }

    void Reset() override
    {
        _events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        if (me->HealthBelowPctDamaged(85.0f, damage))
            damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        // HACKFIX: sparring system is not implemented yet, this is a workaround
        damage = 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INITIATE_PHASE_THREE:
            {
                _events.SetPhase(PHASE_THREE);

                me->RemoveUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);

                DoCastSelf(SPELL_BLASPHEMY_PRE, false);

                _scheduler.Schedule(11s + 800ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_BREAK_PLAYER_TARGETTING, true);
                });

                _scheduler.Schedule(12s, [this](TaskContext /*task*/)
                {
                    me->SetUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);

                    me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                    _events.ScheduleEvent(EVENT_LIGHT_BLAST, 8s, 12s, PHASE_THREE);
                    _events.ScheduleEvent(EVENT_BLASPHEMY, 18s, 20s, PHASE_THREE);
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
                case EVENT_BLASPHEMY:
                    DoCastSelf(SPELL_BLASPHEMY, false);
                    _events.Repeat(25s, 45s);
                    break;

                case EVENT_LIGHT_BLAST:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);
                    _events.Repeat(8s, 12s);
                    break;

                case EVENT_CRIPPLING_DEFEAT:
                    DoCastVictim(SPELL_CRIPPLING_DEFEAT, false);
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

Position const MiddlePlatformNegativeYVertexPos = { -285.9056f, -1276.4102f, 5666.6479f, 0.0f };

static Position GetRandomPointInMiddlePlatform()
{
    G3D::Vector3 point;
    G3D::CoordinateFrame{ G3D::Matrix3::fromEulerAnglesZYX(DegToRad(-45.0f), 0.0f, 0.0f), { MiddlePlatformNegativeYVertexPos.GetPositionX(), MiddlePlatformNegativeYVertexPos.GetPositionY(), MiddlePlatformNegativeYVertexPos.GetPositionZ()}}
        .toWorldSpace(G3D::Box{ { 0.0f, 0.0f, 0.0f }, { 50.0f, 50.0f, 0.0f } })
        .getRandomSurfacePoint(point);

    Position position = Vector3ToPosition(point);

    return Position(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ());
}

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

// 357729 - Blasphemy
// 357730 - Blasphemy
class spell_sylvanas_windrunner_blasphemy : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_blasphemy);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->m_Events.AddEvent(new BlasphemyEvent(GetCaster(), GetCaster()->GetPosition(), 0), GetCaster()->m_Events.CalculateTime(5s));
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        for (uint8 i = 0; i < 20; i++)
        {
            Position const blasphemyDestPos = GetRandomPointInMiddlePlatform();

            uint32 speedAsTime = urand(800, 1500);

            GetCaster()->SendPlaySpellVisual(blasphemyDestPos, 0.0f, SPELL_VISUAL_BLASPHEMY, 0, 0, float(speedAsTime / 1000), true);

            GetCaster()->m_Events.AddEvent(new BlasphemyEvent(GetCaster(), blasphemyDestPos, 1), GetCaster()->m_Events.CalculateTime(Milliseconds(speedAsTime)));
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_blasphemy::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_blasphemy::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352312 - Energize Power Aura (Sylvanas)
class spell_sylvanas_windrunner_energize_power_aura : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_energize_power_aura);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

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
    static constexpr std::array<int32, 3> _sylvanasPowerRegenCycle =
    {
        /// Note: Sylvanas regenerates 10 energy points every 3s roughly.
        3, 3, 4
    };
};

// 359429 - Activate Phase Intermission
class spell_sylvanas_windrunner_activate_phase_intermission : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_activate_phase_intermission);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (sylvanas->IsAIEnabled())
                    sylvanas->AI()->DoAction(ACTION_PREPARE_INTERMISSION);
            }
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_phase_intermission::OnCast);
    }
};

// 359431 - Activate Finish Boss
class spell_sylvanas_windrunner_activate_finish_boss : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_activate_finish_boss);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (sylvanas->IsAIEnabled())
                    sylvanas->AI()->DoAction(ACTION_PREPARE_FINISH_BOSS);
            }
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_finish_boss::OnCast);
    }
};

// 355537 - Modify Champions' Faction
class spell_sylvanas_windrunner_modify_champions_faction : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_modify_champions_faction);

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

    void OnCreate() override
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

// 23028 - Rive
struct at_sylvanas_windrunner_rive : AreaTriggerAI
{
    at_sylvanas_windrunner_rive(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnSplineIndexReached(int splineIndex) override
    {
        if (!_instance)
            return;

        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (splineIndex == DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR)
        {
            std::vector<AreaTrigger*> riveMarker = sylvanas->GetAreaTriggers(SPELL_RIVE_MARKER_AREATRIGGER);

            for (AreaTrigger* riveMarkerAreatrigger : riveMarker)
                riveMarkerAreatrigger->Remove();
        }
        else
        {
            for (uint8 i = 0; i < 5; i++)
            {
                Position const debrisPos = at->GetRandomNearPosition(30.0f);

                at->SendPlayOrphanSpellVisual(debrisPos, SPELL_VISUAL_RIVEN_DEBRIS, 1.50f, true, false);

                sylvanas->m_Events.AddEvent(new DebrisEvent(sylvanas, debrisPos), sylvanas->m_Events.CalculateTime(1s + 500ms));
            }
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(unit, SPELL_RIVE_DAMAGE, true);
    }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        Position areaTriggerPos(at->GetPosition());

        if (!SylvanasFirstPhasePlatformCenter.IsInDist2d(&areaTriggerPos, PLATFORM_RADIUS))
            at->Remove();
    }

private:
    InstanceScript* _instance;
};

// 5428 - Frozen Bridge, 5428 - Earthen Bridge
struct at_sylvanas_windrunner_bridges : AreaTriggerAI
{
    at_sylvanas_windrunner_bridges(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate() override
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

    void OnCreate() override
    {
        _finalDest = at->GetPosition();

        _finalDest.GetPositionX() + 100.0f * std::cos(at->GetOrientation());
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        switch (at->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
                _movementForceMagnitude = 4.0f;
                break;
            case DIFFICULTY_NORMAL_RAID:
                _movementForceMagnitude = 5.0f;
                break;
            case DIFFICULTY_HEROIC_RAID:
                _movementForceMagnitude = 6.0f;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                _movementForceMagnitude = 8.0f;
                break;
            default:
                break;
        }

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), _movementForceMagnitude, MovementForceType::SingleDirectional, _finalDest);

        at->GetCaster()->CastSpell(unit, SPELL_HAUNTING_WAVE_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        unit->RemoveMovementForce(at->GetGUID());
    }

private:
    InstanceScript* _instance;
    float _movementForceMagnitude = 0.0f;
    Position _finalDest;
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

        if (unit->IsPlayer() || !unit->IsPlayer() && (unit->GetEntry() == NPC_BOLVAR_FORDRAGON_PINNACLE || unit->GetEntry() == NPC_JAINA_PROUDMOORE_PINNACLE || unit->GetEntry() == NPC_THRALL_PINNACLE))
            at->GetCaster()->CastSpell(unit, SPELL_BLASPHEMY_STUN, true);
    }

private:
    InstanceScript* _instance;
};

// 27461 - Banshee's Bane
struct at_sylvanas_windrunner_banshee_bane : AreaTriggerAI
{
    at_sylvanas_windrunner_banshee_bane(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _readyToPick(false), _updateDiff(0) { }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        _scheduler.Update(diff);

        if (!_readyToPick)
        {
            _scheduler.Schedule(1s, [this](TaskContext /*task*/)
            {
                 _readyToPick = true;
            });
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || !_readyToPick)
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            unit->SendPlaySpellVisual(at->GetPosition(), 0.0f, SPELL_VISUAL_BANSHEES_BANE_ABSORB, 0, 0, 0.5f, true);

            _scheduler.Schedule(500ms, [this, sylvanas, unit](TaskContext /*task*/)
            {
                 sylvanas->CastSpell(unit, SPELL_BANSHEES_BANE, true);

                 at->Remove();
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

// 17368 - Sylvanas Windrunner's Introduction Conversation
class conversation_sylvanas_windrunner_introduction : public ConversationScript
{
public:
    conversation_sylvanas_windrunner_introduction() : ConversationScript("conversation_sylvanas_windrunner_introduction") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Creature* bolvar = creator->GetInstanceScript()->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            conversation->AddActor(NPC_BOLVAR_FORDRAGON_PINNACLE, 1, bolvar->GetGUID());
    }
};

void AddSC_boss_sylvanas_windrunner()
{
    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy_riding);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_domination_arrow);

    RegisterSpellScript(spell_sylvanas_windrunner_ranger_bow);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_dagger);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_shot);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_strike);
    RegisterSpellScript(spell_sylvanas_windrunner_windrunner);
    RegisterSpellScript(spell_sylvanas_windrunner_disappear);
    RegisterSpellScript(spell_sylvanas_windrunner_withering_fire);
    RegisterSpellScript(spell_sylvanas_windrunner_desecrating_shot);
    RegisterSpellAndAuraScriptPair(spell_sylvanas_windrunner_ranger_heartseeker, spell_sylvanas_windrunner_ranger_heartseeker_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chains);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_trigger);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_raid_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_rive);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_marker);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_triggered_missile);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_interrupt);
    RegisterSpellScript(spell_sylvanas_windrunner_haunting_wave);
    RegisterSpellScript(spell_sylvanas_windrunner_ruin);
    RegisterSpellAndAuraScriptPair(spell_sylvanas_windrunner_banshees_heartseeker, spell_sylvanas_windrunner_banshees_heartseeker_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_banshees_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_bane_arrows);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_bane);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_fury);
    RegisterSpellScript(spell_sylvanas_windrunner_raze);

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
    RegisterAreaTriggerAI(at_sylvanas_windrunner_blasphemy);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_banshee_bane);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_raze);

    new conversation_sylvanas_windrunner_introduction();
}
