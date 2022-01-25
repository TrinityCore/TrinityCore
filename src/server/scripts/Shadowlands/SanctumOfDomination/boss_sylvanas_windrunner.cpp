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
    SPELL_WINDRUNNER_DISAPPEAR_01                       = 352303, // 2 SpellXSpellVisual
    SPELL_WINDRUNNER_DISAPPEAR_02                       = 358975, // 2 SpellXSpellVisual
    SPELL_WINDRUNNER_SPIN                               = 351187,
    SPELL_WINDRUNNER_MOVE                               = 347606,
    SPELL_WINDRUNNER_SHOT_01                            = 347604, // Not on the sniff
    SPELL_WINDRUNNER_JUMP_02                            = 347605, // Not on the sniff
    SPELL_WINDRUNNER_DAGGER_01                          = 350737, // Not on the sniff
    SPELL_WINDRUNNER_BANSHEE                            = 352211,

    // Shadow Dagger
    SPELL_SHADOW_DAGGER_COPY                            = 358964,
    SPELL_SHADOW_DAGGER                                 = 347670,
    SPELL_SHADOW_DAGGER_AOE                             = 353935, // 2 SpellXSpellVisual
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
    SPELL_WAILING_ARROW                                 = 347609, // 2 SpellXSpellVisual
    SPELL_WAILING_ARROW_CAST_JUMP                       = 355839,

    // Domination Chains
    SPELL_DOMINATION_CHAINS_JUMP                        = 347602,
    SPELL_DOMINATION_CHAINS                             = 349419,
    SPELL_DOMINATION_ARROW_SHOT_VISUAL                  = 350426,
    SPELL_DOMINATION_ARROW_FALL                         = 352317,
    SPELL_DOMINATION_ARROW_FALL_AND_VISUAL              = 352319,
    SPELL_DOMINATION_ARROW_ACTIVATE                     = 356650,
    SPELL_DOMINATION_ARROW_CALAMITY_AREA                = 356769,
    SPELL_DOMINATION_ARROW_CALAMITY_AREATRIGGER         = 356624, // 2 SpellXSpellVisual
    SPELL_DOMINATION_ARROW_CALAMITY_DAMAGE              = 356649,

    SPELL_DOMINATION_CHAIN_PLAYER                       = 349451,
    SPELL_DOMINATION_CHAIN_PERIODIC                     = 349458,

    // Veil of Darkness (Generic)
    SPELL_VEIL_OF_DARKNESS_DESELECT                     = 354366,
    SPELL_VEIL_OF_DARKNESS_SCREEN_FOG                   = 354580,
    SPELL_VEIL_OF_DARKNESS_ABSORB_AURA                  = 347704,

    // Veil of Darkness (Phase 1)
    SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE                 = 352470,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW                 = 350335,
    SPELL_VEIL_OF_DARKNESS_PHASE_1_AREA                 = 357726,
    SPELL_VEIL_OF_DARKNESS_PHASE_1                      = 347726, // 4 SpellXSpellVisual

    // Banshee Shroud
    SPELL_BANSHEE_SHROUD                                = 350857,

    // Rive
    SPELL_RIVE_DISAPPEAR                                = 353519,
    SPELL_RIVE                                          = 353417,
    SPELL_RIVE_FAST                                     = 353418,
    SPELL_RIVE_MARKER                                   = 353419,
    SPELL_RIVE_CHAIN                                    = 353504,
    SPELL_RIVE_CHAIN_FAST                               = 353510,
    SPELL_RIVE_AREATRIGGER                              = 353375,
    SPELL_RIVE_DAMAGE                                   = 348145,
    SPELL_RIVEN_DEBRIS                                  = 353413,
    SPELL_RIVE_MYTHIC_COPY                              = 358431,

    // Banshee Wail
    SPELL_BANSHEE_WAIL                                  = 348094, // 3 SpellXSpellVisual
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
    SPELL_SWITCH_PLATFORM_STOMP                         = 354141, // 27887 areatrigger forces MovementForce on Players for 150ms

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
    SPELL_CHAMPIONS_MOD_FACTION                         = 355537,

    SPELL_INTERMISSION_STUN                             = 355488,
    SPELL_INTERMISSION_SCENE                            = 359062,
    SPELL_PLATFORMS_SCENE                               = 350943,
    SPELL_FINAL_SCENE                                   = 358806,
    SPELL_FINAL_CINEMATIC                               = 358985,
    SPELL_SYLVANAS_FEIGN_DEATH                          = 358844,

    SPELL_HEALTH_PCT_CHECK_INTERMISSION                 = 358794,
    SPELL_ACTIVATE_INTERMISSION                         = 359429,
    SPELL_HEALTH_PCT_CHECK_FINISH                       = 359430,
    SPELL_ACTIVATE_FINISH                               = 359431
};

enum Phases
{
    PHASE_ONE                                           = 1,
    PHASE_INTERMISSION                                  = 2,
    PHASE_TWO                                           = 3,
    PHASE_THREE                                         = 4
};

enum Events
{
    EVENT_WINDRUNNER                                    = 1,
    EVENT_WITHERING_FIRE,
    EVENT_SHADOW_DAGGERS,
    EVENT_DESECRATING_SHOT,
    EVENT_DESECRATING_SHOT_LAUNCH,
    EVENT_DOMINATION_CHAINS,
    EVENT_WAILING_ARROW_MARKER,
    EVENT_WAILING_ARROW,
    EVENT_VEIL_OF_DARKNESS,
    EVENT_RIVE,
    EVENT_FINISH_INTERMISSION,
    EVENT_BANE_ARROWS,
    EVENT_RAZE,
    EVENT_BANSHEE_SCREAM,
    EVENT_BANSHEES_FURY
};

enum Actions
{ 
    ACTION_WINDRUNNER_MODEL_ACTIVATE                    = 1,
    ACTION_WINDRUNNER_MODEL_DEACTIVATE,
    ACTION_RESET_MELEE_KIT,
    ACTION_RANGER_SHOT,
    ACTION_ACTIVATE_DOMINATION_ARROW,
    ACTION_RANGER_HEARTSEEKER,
    ACTION_CALCULATE_ARROWS,
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
    SAY_ANNOUNCE_WAILING_ARROW_TANK                     = 7,
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

    SPELL_VISUAL_KIT_SYLVANAS_NORMAL_CAST               = 142405,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW             = 143939,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN        = 142389,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS         = 143940,
    SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN    = 142388,
    SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_CHARGE      = 142447,
    SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_JUMP        = 145145,
    SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_EFFECT      = 146199,
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
    SPELL_VISUAL_UNK                                    = 106112,
    SPELL_VISUAL_RANGER_STRIKE_RIGHT                    = 106153, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_LEFT                     = 106160, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_01                       = 106165, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_03                       = 106161, // At 1.0f
    SPELL_VISUAL_WINDRUNNER_SPIN                        = 105759,
    SPELL_VISUAL_WINDRUNNER_01                          = 107722, // At 0.5f
    SPELL_VISUAL_WINDRUNNER_02                          = 110312, // At 0.25f
    SPELL_VISUAL_WINDRUNNER_03                          = 107920, // At 0.25f
    SPELL_VISUAL_DESECRATING_ARROW                      = 106363, // At 0.40f - 0.12f
    SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE               = 105944, // At 48.0f, false as time
    SPELL_VISUAL_RANGER_HEARTSEEKER                     = 107607, // At 36f, false as time
    SPELL_VISUAL_DOMINATION_ARROW                       = 107501, // At 2.5f
    SPELL_VISUAL_DOMINATION_ARROW_SPAWN                 = 109620, // At 2.5f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_NM           = 109159, // At 5.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_HC           = 107567, // At 5.0f
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK                   = 108070,
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST              = 108071,
    SPELL_VISUAL_RIVEN_DEBRIS                           = 107877, // At 1.744643688201904296f - 1.616904616355895996f, dynamic
    SPELL_VISUAL_WITHERING_FIRE_PHASE_TWO               = 110435, // At 3.5f - 2.7f, dynamic
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_02_03           = 109371, // At 3.0f
    SPELL_VISUAL_BANE_ARROW                             = 108112, // At 3.2f - 2.04f, dynamic
    SPELL_VISUAL_BANSHEE_FURY                           = 108130, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE                                   = 110336, // At 0.100000001490116119f
    SPELL_VISUAL_RAZE_MISSILE                           = 108154, // At 0.33f - 0.14f
    SPELL_VISUAL_BLASPHEMY                              = 109680, // At 1.0f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_3_HC            = 105852, // At 3.0f
    SPELL_VISUAL_JAILER_BOLT                            = 107337, // At 90.0f, false as time
    SPELL_VISUAL_BANSHEES_BANE_ABSORB                   = 108093, // At 0.5f

    SPELL_VISUAL_UNK02_PLAYER                           = 107839, // At 0.349999994039535522f
    SPELL_VISUAL_UNK_02                                 = 108094, // At 1.5f
    SPELL_VISUAL_SHADOW_DAGGER                          = 108096, // At 100.0f, false
    SPELL_VISUAL_MOST_LIKELY_SPREAD_OUT_FOG             = 108092, // At 0.64f - 0.52f
    SPELL_VISUAL_UNK01_177054                           = 107069, // At 1.0f
    SPELL_VISUAL_BANSHEE_FURY_IDK                       = 107476, // At 1.5f
    SPELL_VISUAL_UNK01_177787                           = 107063, // At 1.0f
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

    DATA_CHANGE_SHEATHE_UNARMED                         = 0,                 
    DATA_CHANGE_SHEATHE_DAGGERS                         = 1,
    DATA_CHANGE_SHEATHE_BOW                             = 2,
    DATA_CHANGE_NAMEPLATE_TO_COPY                       = 3,
    DATA_CHANGE_NAMEPLATE_TO_SYLVANAS                   = 4,

    DATA_EVENT_TYPE_SHADOWCOPY                          = 1,
    DATA_EVENT_COPY_NO_EVENT                            = 1,
    DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT              = 2,
    DATA_EVENT_COPY_RIVE_EVENT                          = 3,
    DATA_EVENT_COPY_FINISH_INTERMISSION_EVENT           = 4,
    DATA_EVENT_COPY_DOMINATION_CHAIN_BEFORE_RIVE_EVENT  = 5,

    DATA_AREATRIGGER_DOMINATION_ARROW                   = 27683,
    DATA_AREATRIGGER_RIVE_MARKER                        = 6197,

    DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR              = 1,

    DATA_DESECRATING_SHOT_PATTERN_STRAIGHT              = 0,
    DATA_DESECRATING_SHOT_PATTERN_SCATTERED             = 1,
    DATA_DESECRATING_SHOT_PATTERN_WAVE                  = 2,
    DATA_DESECRATING_SHOT_PATTERN_SPIRAL                = 3,
    DATA_DESECRATING_SHOT_PATTERN_JAR                   = 4,

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

// Middle is 0, top right is 1, bottom left is 2
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

static Position GetRandomPointInCovenantPlatform(Position const& a, Position const& b, float c)
{
    float x = frand(std::min(a.GetPositionX(), b.GetPositionX()), std::max(a.GetPositionX(), b.GetPositionX()));
    float y = frand(std::min(a.GetPositionY(), b.GetPositionY()), std::max(a.GetPositionY(), b.GetPositionY()));
    float z = c;

    return Position(x, y, z);
}

Position const SylvanasVeilThreePos = { -286.978f, -1245.2378f, 5772.0347f, 0.0f       };

Position const SylvanasEndPos =       { -249.876f, -1252.4791f, 5667.1157f, 3.3742f    };

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
        PauseAttackState(Creature* owner, bool paused) : _owner(owner), _paused(paused) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_paused)
            {
                _owner->InterruptNonMeleeSpells(true);
                _owner->GetMotionMaster()->Clear();
                _owner->StopMoving();
                _owner->AttackStop();

                _owner->SetReactState(REACT_PASSIVE);
            }
            else
            {
                _owner->SetReactState(REACT_AGGRESSIVE);

                if (_owner->GetEntry() == BOSS_SYLVANAS_WINDRUNNER)
                {
                    if (Unit* target = _owner->AI()->SelectTarget(SelectTargetMethod::MaxThreat, 0, 250.0f, true))
                        _owner->AI()->AttackStart(target);

                    if (_owner->IsAIEnabled())
                        _owner->ToCreature()->AI()->DoAction(ACTION_RESET_MELEE_KIT);
                }
            }

            return true;
        }

    private:
        Creature* _owner;
        bool _paused;
};

class SetSheatheStateOrNameplate : public BasicEvent
{
    public:
        SetSheatheStateOrNameplate(Unit* owner, uint8 event) : _owner(owner), _event(event) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            switch (_event)
            {
                case DATA_CHANGE_SHEATHE_UNARMED:
                    _owner->SetSheath(SHEATH_STATE_UNARMED);
                    break;

                case DATA_CHANGE_SHEATHE_DAGGERS:
                    _owner->SetSheath(SHEATH_STATE_MELEE);
                    break;

                case DATA_CHANGE_SHEATHE_BOW:
                    _owner->SetSheath(SHEATH_STATE_RANGED);
                    break;

                case DATA_CHANGE_NAMEPLATE_TO_COPY:
                    if (Creature* ridingCopy = _owner->FindNearestCreature(NPC_SYLVANAS_SHADOW_COPY_RIDING, 10.0f, true))
                        _owner->SetNameplateAttachToGUID(ridingCopy->GetGUID());
                    break;

                case DATA_CHANGE_NAMEPLATE_TO_SYLVANAS:
                    _owner->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    break;

                default:
                    break;
            }

            return true;
        }

    private:
        Unit* _owner;
        uint8 _event;
};

// Sylvanas Shadowcopy (Fight) - 176369
struct npc_sylvanas_windrunner_shadowcopy : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()),
        _onPhaseOne(true), _onDominationChains(false), _onDominationChainsBeforeRive(false), _onRiveEvent(false), _sayDaggers(0),
        _sayDesecrating(0), _jumpCount(0) { }

    void JustAppeared() override
    {
        DoZoneInCombat();

        me->SetReactState(REACT_PASSIVE);

        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
    }

    void Reset() override
    {
        _onPhaseOne = true;
        _onDominationChains = false;
        _onDominationChainsBeforeRive = false;
        _onRiveEvent = false;
        _sayDaggers = 0;
        _sayDesecrating = 0;
        _jumpCount = 0;
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EVENT_TYPE_SHADOWCOPY)
        {
            switch (value)
            {
                case DATA_EVENT_COPY_NO_EVENT:
                {
                    _onPhaseOne = true;
                    _onDominationChains = false;
                    _onDominationChainsBeforeRive = false;
                    _onRiveEvent = false;
                    break;
                }

                case DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT:
                {
                    _onPhaseOne = false;
                    _onDominationChains = true;
                    _onDominationChainsBeforeRive = false;
                    _onRiveEvent = false;
                    break;
                }

                case DATA_EVENT_COPY_DOMINATION_CHAIN_BEFORE_RIVE_EVENT:
                {
                    _onDominationChainsBeforeRive = true;
                    break;
                }

                case DATA_EVENT_COPY_RIVE_EVENT:
                {
                    _onPhaseOne = false;
                    _onDominationChains = false;
                    _onDominationChainsBeforeRive = false;
                    _onRiveEvent = true;
                    break;
                }

                case DATA_EVENT_COPY_FINISH_INTERMISSION_EVENT:
                {
                    _onPhaseOne = false;
                    _onDominationChains = false;
                    _onDominationChainsBeforeRive = false;
                    _onRiveEvent = false;
                    break;
                }

                default:
                    break;
            }

        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == EFFECT_MOTION_TYPE)
        {
            if (id == EVENT_JUMP)
            {
                if (_onPhaseOne)
                {
                    me->StopMoving();

                    _scheduler.Schedule(50ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                            me->SetFacingToObject(sylvanas);

                        DoCastSelf(SPELL_ANCHOR_HERE, true);
                    });
                }

                if (_onDominationChains)
                {
                    _scheduler.Schedule(150ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_DOMINATION_ARROW_SHOT_VISUAL, true);

                        DoCastSelf(SPELL_ANCHOR_HERE, true);
                    });

                    _scheduler.Schedule(200ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        {
                            for (uint8 i = 0; i < 5; i++)
                            {
                                Position const falseArrowPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(2.5f, 40.0f));

                                me->SendPlaySpellVisual(falseArrowPos, 0.0f, SPELL_VISUAL_DOMINATION_ARROW, 0, 0, 2.0f, true);

                                _scheduler.Schedule(2s, [sylvanas, falseArrowPos](TaskContext /*task*/)
                                {
                                    sylvanas->CastSpell(falseArrowPos, SPELL_DOMINATION_ARROW_FALL, true);
                                });
                            }

                            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                            {
                                // TODO: on mythic, there are 4 spots on which arrows fall on
                            }
                            else
                            {
                                for (uint32 i = 0; i < _selectedArrowCountsPerJump[_jumpCount]; ++i)
                                {
                                    Position const arrowPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(2.5f, 40.0f));

                                    if (Creature* dominationArrow = sylvanas->SummonCreature(NPC_DOMINATION_ARROW, arrowPos, TEMPSUMMON_MANUAL_DESPAWN))
                                    {
                                        me->SendPlaySpellVisual(arrowPos, 0.0f, SPELL_VISUAL_DOMINATION_ARROW_SPAWN, 0, 0, 2.0f, true);

                                        _scheduler.Schedule(2s, [sylvanas, dominationArrow](TaskContext /*task*/)
                                        {
                                            sylvanas->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_FALL_AND_VISUAL, true);
                                        });
                                    }
                                }

                                ++_jumpCount;
                            }
                        }
                    });
                }

                if (_onRiveEvent)
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CALCULATE_ARROWS:
            {
                uint8 arrowsToSpawn;

                // Number of arrows spawned is dependent on raid's difficulty and size: min. 4, max. 10 (unless on intermission, which is every player alive)
                if (_onDominationChainsBeforeRive)
                    arrowsToSpawn = me->GetMap()->GetPlayersCountExceptGMs();
                else
                    arrowsToSpawn = std::min<uint8>(std::max<uint8>(std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs() / 3.0f)), 4), 10);

                _selectedArrowCountsPerJump = SplitArrowCasts(arrowsToSpawn);

                _jumpCount = 0;
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void StartWitheringFireEvent(bool chooseMe)
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            uint8 castTimes = 1;

            Position const witheringCastPos = me->GetNearPosition(frand(20.0f, 30.0f), frand(0.0f, 3.5f));

            if (chooseMe)
            {
                sylvanas->SetNameplateAttachToGUID(me->GetGUID());

                // Number of casts is dependent on raid's difficulty and size: if mythic, 15; if not, half the raid (min. 5, max. 15)
                castTimes = me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 15 :
                    std::max<uint8>(5, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 2));;
            }

            _scheduler.Schedule(50ms, [this, witheringCastPos, sylvanas, chooseMe](TaskContext /*task*/)
            {
                sylvanas->SendPlayOrphanSpellVisual(witheringCastPos, SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);

                if (chooseMe)
                    me->CastSpell(witheringCastPos, SPELL_WINDRUNNER_MOVE, false);
                else
                    me->NearTeleportTo(witheringCastPos, false);
            });

            _scheduler.Schedule(350ms, [this, sylvanas](TaskContext /*task*/)
            {
                 me->SetFacingToObject(sylvanas);
            });

            _scheduler.Schedule(400ms, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_WITHERING_FIRE_COPY, true);
            });

            _scheduler.Schedule(750ms, [this, castTimes, sylvanas, chooseMe](TaskContext /*task*/)
            {
                std::list<Player*> targetList;
                GetPlayerListInGrid(targetList, me, 250.0f);

                Trinity::Containers::RandomResize(targetList, chooseMe ? castTimes - 3 : castTimes);

                for (Player* target : targetList)
                {
                    me->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE_PHASE_ONE, 0, 0, 48.0f, false);

                    uint32 timeToCast = me->GetDistance(target) * 0.0208;

                    _scheduler.Schedule(Seconds(timeToCast), [sylvanas, target](TaskContext /*task*/)
                    {
                        sylvanas->CastSpell(target, SPELL_WITHERING_FIRE, true);
                    });
                }
            });

            _scheduler.Schedule(800ms, [this, sylvanas](TaskContext /*task*/)
            {
                me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);

                me->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE, true);
            });

            _scheduler.Schedule(2s + 62ms, [this, sylvanas, chooseMe](TaskContext /*task*/)
            {
                if (chooseMe)
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_DEACTIVATE);
                }
            });
        }
    }

    void StartShadowDaggersEvent(bool chooseMe)
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
            {
                Position const shadowdaggerPos = target->GetNearPosition(frand(2.5f, 3.0f), frand(0.0f, 6.0f));

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

                _scheduler.Schedule(202ms, [this, target](TaskContext /*task*/)
                {
                    me->SetFacingToObject(target);
                });

                _scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_SHADOW_DAGGER_COPY, true);
                });

                _scheduler.Schedule(500ms, [target, sylvanas](TaskContext /*task*/)
                {
                    sylvanas->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                });

                _scheduler.Schedule(600ms, [this, sylvanas, chooseMe](TaskContext /*task*/)
                {
                    me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                    if (chooseMe)
                        me->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE, false);
                    else
                        me->NearTeleportTo(sylvanas->GetPosition(), false);
                });

                _scheduler.Schedule(1s + 500ms, [this, sylvanas, chooseMe](TaskContext /*task*/)
                {
                    if (chooseMe)
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_DEACTIVATE);
                    }
                });
            }
        }
    }

    void StartDesecratingShotEvent()
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            me->NearTeleportTo(sylvanas->GetNearPosition(5.0f, float(M_PI)), false);

            _scheduler.Schedule(50ms, [this](TaskContext /*task*/)
            {
                me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 5.0f, me->GetOrientation(), false);
            });

            _scheduler.Schedule(100ms, [this, sylvanas](TaskContext /*task*/)
            {
                if (sylvanas->IsAIEnabled())
                {
                    sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_ACTIVATE);
                    me->CastSpell(me, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2550));

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

                sylvanas->SetNameplateAttachToGUID(me->GetGUID());

                DoCastSelf(SPELL_DESECRATING_SHOT_JUMP_FRONT, false);
            });

            _scheduler.Schedule(550ms, [this, sylvanas](TaskContext /*task*/)
            {
                me->CastSpell(sylvanas->GetPosition(), SPELL_WINDRUNNER_MOVE, false);
            });

            _scheduler.Schedule(797ms, [sylvanas](TaskContext /*task*/)
            {
                if (sylvanas->IsAIEnabled())
                    sylvanas->AI()->DoAction(ACTION_WINDRUNNER_MODEL_DEACTIVATE);
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
    TaskScheduler _scheduler;
    bool _onPhaseOne;
    bool _onDominationChains;
    bool _onDominationChainsBeforeRive;
    bool _onRiveEvent;
    uint8 _sayDaggers;
    uint8 _sayDesecrating;
    std::array<uint32, 3> _selectedArrowCountsPerJump;
    uint8 _jumpCount;
};

// Sylvanas Shadowcopy (Riding) - 178355
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);

        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// Sylvanas Windrunner - 175732
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER), _windrunnerActive(false), _rangerShotOnCD(false), _maldraxxiDesecrated(false),
        _nightfaeDesecrated(false), _kyrianDesecrated(false), _venthyrDesecrated(false), _meleeKitCombo(0), _windrunnerCastTimes(0), _riveCastTimes(0), _hauntingWaveTimes(0) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

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

        if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            bolvar->DespawnOrUnsummon();

        if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
            jaina->DespawnOrUnsummon();

        if (Creature* thrall = instance->GetCreature(DATA_THRALL_PINNACLE))
            thrall->DespawnOrUnsummon();

        if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
            anduin->DespawnOrUnsummon();

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        me->SummonCreatureGroup(SPAWN_GROUP_INITIAL);

        events.Reset();
        _specialEvents.Reset();

        _windrunnerActive = false;
        _rangerShotOnCD = false;
        _maldraxxiDesecrated = false;
        _nightfaeDesecrated = false;
        _kyrianDesecrated = false;
        _venthyrDesecrated = false;
        _meleeKitCombo = 0;
        _windrunnerCastTimes = 0;
        _riveCastTimes = 0;
        _hauntingWaveTimes = 0;
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SYLVANAS_SHADOW_COPY_FIGHTERS:
                _shadowCopyGUID.push_back(summon->GetGUID());
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void OnSpellCastInterrupt(SpellInfo const* spell)
    {
        if (spell->Id == SPELL_RUIN)
        {
            // TODO: change this since she's interrupted 5 times
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

        for (uint8 i = 0; i < 4; i++)
            me->SummonCreature(NPC_SYLVANAS_SHADOW_COPY_FIGHTERS, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);

        DoAction(ACTION_PREPARE_PHASE_THREE);

        /*
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_WINDRUNNER, 7s + 500ms, 1, PHASE_ONE);
        events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 26s, 1, PHASE_ONE);
        events.ScheduleEvent(EVENT_VEIL_OF_DARKNESS, 45s, 1, PHASE_ONE);
        // We need a separated event handler for this because Wailing Arrow is triggered even if Sylvanas is casting
        _specialEvents.SetPhase(PHASE_ONE);
        _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, 33s, 1, PHASE_ONE);
        DoCastSelf(SPELL_SYLVANAS_POWER_ENERGIZE_AURA, true);
        DoCastSelf(SPELL_RANGER_HEARTSEEKER_AURA, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_INTERMISSION, true);
        DoCastSelf(SPELL_HEALTH_PCT_CHECK_FINISH, true);
        */
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
            {
                me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_01, false);
                break;
            }

            case ACTION_WINDRUNNER_MODEL_DEACTIVATE:
            {
                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_01);
                break;
            }

            case ACTION_RESET_MELEE_KIT:
            {
                _meleeKitCombo = 0;
                break;
            }

            case ACTION_RANGER_SHOT:
            {
                DoCastVictim(SPELL_RANGER_SHOT, false);

                if (!_rangerShotOnCD)
                    _rangerShotOnCD = true;

                _meleeKitCombo = 0;

                scheduler.Schedule(750ms, [this](TaskContext /*task*/)
                {
                    me->resetAttackTimer();
                });

                scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                {
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoAction(ACTION_RANGER_SHOT);
                    else
                        _rangerShotOnCD = false;
                });
                break;
            }

            case ACTION_PREPARE_INTERMISSION:
            {
                _specialEvents.CancelEventGroup(1);
                events.CancelEventGroup(1);

                me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                _specialEvents.SetPhase(PHASE_INTERMISSION);
                events.SetPhase(PHASE_INTERMISSION);
                events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 1s, PHASE_INTERMISSION);
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
                    _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, 60s, 1, PHASE_THREE);
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
                case EVENT_WAILING_ARROW_MARKER:
                {
                    std::list<Player*> everyPlayerButCurrentTank;
                    GetPlayerListInGrid(everyPlayerButCurrentTank, me, 250.0f);

                    if (Unit* currentTank = SelectTarget(SelectTargetMethod::MaxThreat, 0, 250.0f, true, true))
                    {
                        Talk(SAY_ANNOUNCE_WAILING_ARROW_TANK, currentTank);

                        me->CastSpell(currentTank, SPELL_WAILING_ARROW_POINTER, true);

                        if (Player* currentTankToPlayer = currentTank->ToPlayer())
                            everyPlayerButCurrentTank.remove(currentTankToPlayer);
                    }

                    for (Unit* nonTank : everyPlayerButCurrentTank)
                        Talk(SAY_ANNOUNCE_WAILING_ARROW, nonTank);

                    events.ScheduleEvent(EVENT_WAILING_ARROW, 4s + 500ms, 1, PHASE_ONE);
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

                    _windrunnerActive = true;

                    if (_windrunnerCastTimes == 0)
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 11000));

                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 1ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 3s + 141ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s + 141ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 7s + 750ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 9s + 281ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 9s + 281ms, 2, PHASE_ONE);

                        scheduler.Schedule(11s + 250ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else if (_windrunnerCastTimes == 1) // TODO: fix timers
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 13000));

                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 2s + 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 7s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s, 2, PHASE_ONE);

                        scheduler.Schedule(13s + 250ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else if (_windrunnerCastTimes == 2) // TODO: fix timers
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 15000));

                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 5s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 7s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 9s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 13s, 2, PHASE_ONE);

                        scheduler.Schedule(15s + 250ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else // TODO: fix timers
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 17000));

                        scheduler.Schedule(17s + 250ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }

                    _windrunnerCastTimes++;

                    events.Repeat(51s);
                    break;
                }

                case EVENT_WITHERING_FIRE:
                {
                    TeleportShadowcopiesToMe();

                    if (events.IsInPhase(PHASE_ONE))
                    {
                        DoAction(ACTION_WINDRUNNER_MODEL_ACTIVATE);
                        me->CastSpell(me, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3800));

                        uint8 randomCopy = urand(0, 4);

                        for (uint8 itr = 0; itr < 4; itr++)
                        {
                            scheduler.Schedule(Milliseconds(100 * itr), [this, itr, randomCopy](TaskContext /*task*/)
                            {
                                if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(itr))
                                    ai->StartWitheringFireEvent(itr == randomCopy);
                            });
                        }

                    }
                    else if (events.IsInPhase(PHASE_TWO))
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

                                scheduler.Schedule(Milliseconds(randomSpeed), [this, target](TaskContext /*task*/)
                                {
                                     me->CastSpell(target, SPELL_WITHERING_FIRE, true);
                                });
                            }
                        });
                    }
                    else if (events.IsInPhase(PHASE_THREE))
                    {

                    }
                    break;
                }

                case EVENT_SHADOW_DAGGERS:
                {
                    if (events.IsInPhase(PHASE_ONE))
                    {
                        TeleportShadowcopiesToMe();

                        DoAction(ACTION_WINDRUNNER_MODEL_ACTIVATE);
                        me->CastSpell(me, SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3200));

                        uint8 randomCopy = urand(0, 4);

                        for (uint8 itr = 0; itr < 4; itr++)
                        {
                            scheduler.Schedule(Milliseconds(100 * itr), [this, itr, randomCopy](TaskContext /*task*/)
                            {
                                if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(itr))
                                    ai->StartShadowDaggersEvent(itr == randomCopy);
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
                    switch (urand(DATA_DESECRATING_SHOT_PATTERN_STRAIGHT, DATA_DESECRATING_SHOT_PATTERN_SCATTERED))
                    {
                        case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
                        {
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
                            {
                                float orientation = me->GetAbsoluteAngle(target);

                                int32 step = 1;

                                while (DrawDesecratingShotStraight(step, orientation))
                                    ++step;

                                scheduler.Schedule(2s + 300ms, [this](TaskContext /*task*/)
                                {
                                    if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                                        ai->StartDesecratingShotEvent();
                                });
                            }
                            break;
                        }

                        case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
                        {
                            DrawDesecratingShotScattered();

                            scheduler.Schedule(2s + 300ms, [this](TaskContext /*task*/)
                            {
                                if (npc_sylvanas_windrunner_shadowcopy* ai = GetSylvanasCopyAI(0))
                                    ai->StartDesecratingShotEvent();
                            });
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }

                case EVENT_DOMINATION_CHAINS:
                {
                    if (_windrunnerActive)
                        return;

                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                    Position const jumpFirstPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));
                    Position const jumpSecondPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));
                    Position const jumpThirdPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));

                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                    {
                        if (shadowCopy->IsAIEnabled())
                        {
                            shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_DOMINATION_CHAIN_EVENT);

                            shadowCopy->AI()->DoAction(ACTION_CALCULATE_ARROWS);

                            if (events.GetPhaseMask() == PHASE_INTERMISSION)
                                shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_DOMINATION_CHAIN_BEFORE_RIVE_EVENT);
                        }

                        shadowCopy->NearTeleportTo(me->GetPosition(), false);
                    }

                    DoCastSelf(SPELL_WINDRUNNER_DISAPPEAR_02, true);

                    scheduler.Schedule(15ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_DOMINATION_CHAINS, false);

                        me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);
                    });

                    scheduler.Schedule(31ms, [this, jumpFirstPos](TaskContext /*task*/)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            shadowCopy->CastSpell(jumpFirstPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                        me->SendPlayOrphanSpellVisual(jumpFirstPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    });

                    scheduler.Schedule(151ms, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_ANNOUNCE_DOMINATION_CHAINS);

                        if (events.GetPhaseMask() == PHASE_ONE)
                            Talk(SAY_DOMINATION_CHAINS);
                        else
                            Talk(SAY_INTERMISSION_BEGIN);
                    });

                    scheduler.Schedule(766ms, [this, jumpFirstPos](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(jumpFirstPos, true);

                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            me->SetFacingTo(shadowCopy->GetOrientation());
                    });

                    scheduler.Schedule(828ms, [this, jumpSecondPos](TaskContext /*task*/)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            shadowCopy->CastSpell(jumpSecondPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                        me->SendPlayOrphanSpellVisual(jumpSecondPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    });

                    scheduler.Schedule(1s + 578ms, [this, jumpSecondPos](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(jumpSecondPos, true);

                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            me->SetFacingTo(shadowCopy->GetOrientation());
                    });

                    scheduler.Schedule(1s + 641ms, [this, jumpThirdPos](TaskContext /*task*/)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            shadowCopy->CastSpell(jumpThirdPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                        me->SendPlayOrphanSpellVisual(jumpThirdPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                    });

                    scheduler.Schedule(2s + 201ms, [this, jumpThirdPos](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(jumpThirdPos, true);

                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                            me->SetFacingTo(shadowCopy->GetOrientation());
                    });

                    scheduler.Schedule(2s + 281ms, [this](TaskContext /*task*/)
                    {
                        TeleportShadowcopiesToMe();
                    });

                    scheduler.Schedule(2s + 500ms, [this](TaskContext /*task*/)
                    {
                        me->RemoveAura(SPELL_WINDRUNNER_DISAPPEAR_02);
                        me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    });

                    scheduler.Schedule(7s + 500ms, [this](TaskContext /*task*/)
                    {
                        if (events.GetPhaseMask() == PHASE_ONE)
                        {
                            me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                            for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                            {
                                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                                {
                                    if (shadowCopy->IsAIEnabled())
                                        shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_NO_EVENT);
                                }
                            }

                            DoAction(ACTION_RESET_MELEE_KIT);

                            if (events.GetTimeUntilEvent(EVENT_VEIL_OF_DARKNESS) <= 2s + 500ms)
                                events.RescheduleEvent(EVENT_VEIL_OF_DARKNESS, 3s + 500ms, 1, PHASE_ONE);

                            events.Repeat(54s);
                        }
                        else
                        {
                            for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                            {
                                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                                {
                                    if (shadowCopy->IsAIEnabled())
                                        shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_RIVE_EVENT);
                                }
                            }

                            events.ScheduleEvent(EVENT_RIVE, 1s, PHASE_INTERMISSION);
                        }
                    });
                    break;
                }

                case EVENT_WAILING_ARROW:
                {
                    me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));

                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                    scheduler.Schedule(1s, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_WAILING_ARROW);

                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true, SPELL_WAILING_ARROW_POINTER))
                            me->CastSpell(target, SPELL_WAILING_ARROW, false);

                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_CHARGE, 0, 0);
                    });

                    scheduler.Schedule(2s + 600ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_JUMP, 0, 0);
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_EFFECT, 0, 0);
                    });

                    scheduler.Schedule(4s + 500ms, [this](TaskContext /*task*/)
                    {
                        me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));

                        _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, 33s, PHASE_ONE);
                    });

                    break;
                }

                case EVENT_VEIL_OF_DARKNESS:
                {
                    if (events.IsInPhase(PHASE_ONE))
                    {
                        if (_windrunnerActive)
                            return;

                        me->m_Events.AddEvent(new PauseAttackState(me, true), me->m_Events.CalculateTime(1ms));
                        DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                        scheduler.Schedule(1s, [this](TaskContext /*task*/)
                        {
                            me->SetPower(me->GetPowerType(), 0);

                            Talk(SAY_ANNOUNCE_VEIL_OF_DARKNESS);
                            Talk(SAY_VEIL_OF_DARKNESS_PHASE_ONE);

                            scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                            {
                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE, true);
                                me->NearTeleportTo(SylvanasVeilOnePos, false);
                            });

                            scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                            {
                                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                                {
                                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, SylvanasNonMeleeSelector(me)))
                                        me->NearTeleportTo(target->GetPosition(), false);
                                }
                                else
                                {
                                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true, true))
                                        me->NearTeleportTo(target->GetPosition(), false);
                                }

                                DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 4000));
                            });

                            scheduler.Schedule(2s, [this](TaskContext /*task*/)
                            {
                                TeleportShadowcopiesToMe();
                            });

                            scheduler.Schedule(9s, [this](TaskContext /*task*/)
                            {
                                me->m_Events.AddEvent(new PauseAttackState(me, false), me->m_Events.CalculateTime(1ms));
                                DoAction(ACTION_RESET_MELEE_KIT);
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
                                me->CastSpell(shadowCopy2->GetNearPosition(9.0f, 0.0f), SPELL_RIVE_MARKER, true);

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
                                    shadowCopy->AI()->SetData(DATA_EVENT_TYPE_SHADOWCOPY, DATA_EVENT_COPY_FINISH_INTERMISSION_EVENT);
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
                    });

                    scheduler.Schedule(9s + 400ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasPhase2PrePos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        me->NearTeleportTo(SylvanasPhase2PrePos, false);
                    });

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
                {
                    DoCastSelf(SPELL_BANE_ARROWS, false);
                    events.Repeat(76s);
                    break;
                }

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
                {
                    Talk(SAY_BANSHEE_SCREAM);
                    DoCastSelf(SPELL_BANSHEE_SCREAM, false);
                    events.Repeat(80s);
                    break;
                }

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

                        me->m_Events.AddEvent(new SetSheatheStateOrNameplate(me, DATA_CHANGE_SHEATHE_UNARMED), me->m_Events.CalculateTime(16ms));

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
                        if (Creature* ridingCopy = me->FindNearestCreature(NPC_SYLVANAS_SHADOW_COPY_RIDING, 10.0f, true))
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
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_WINDRUNNER))
            return;

        Aura* rangerHeartseekerCharge = me->GetAura(SPELL_RANGER_HEARTSEEKER_CHARGE);

        if (rangerHeartseekerCharge && rangerHeartseekerCharge->GetStackAmount() >= 3)
        {
            if (me->isAttackReady(BASE_ATTACK))
            {
                if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                else
                    DoCastVictim(SPELL_RANGER_HEARTSEEKER, false);

                me->resetAttackTimer(BASE_ATTACK);
            }
        }
        else
        {
            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                else
                {
                    if (!_rangerShotOnCD)
                        DoAction(ACTION_RANGER_SHOT);
                }
            }
            else
            {
                if (me->isAttackReady(BASE_ATTACK))
                {
                    switch (_meleeKitCombo)
                    {
                        case DATA_MELEE_COMBO_SWITCH_TO_MELEE:
                        {
                            if (!me->HasAura(SPELL_RANGER_DAGGERS_STANCE))
                                DoCastSelf(SPELL_RANGER_DAGGERS_STANCE, false);

                            me->resetAttackTimer();
                            _meleeKitCombo++;
                            break;
                        }

                        case DATA_MELEE_COMBO_RANGER_STRIKE_01:
                        case DATA_MELEE_COMBO_RANGER_STRIKE_02:
                        {
                            DoCastVictim(SPELL_RANGER_STRIKE, false);

                            me->resetAttackTimer();
                            _meleeKitCombo++;
                            break;
                        }

                        case DATA_MELEE_COMBO_SWITCH_TO_RANGED:
                        {
                            if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                                DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                            me->resetAttackTimer();
                            _meleeKitCombo++;
                            break;
                        }

                        case DATA_MELEE_COMBO_FINISH:
                            DoAction(ACTION_RANGER_SHOT);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    // TODO: synthetize all of it in a single bool.
    bool DrawDesecratingShotStraight(int32 step, float orientation)
    {
        float distance = 7.0f * step;

        // Let's obtain the arrow's center so we can stop summoning arrows if it goes beyond the boundaries of the platform
        Position arrowCenter(me->GetPositionX() + (std::cos(orientation) * distance), me->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

        if (!SylvanasFirstPhasePlatformCenter.IsInDist2d(&arrowCenter, PLATFORM_RADIUS))
            return false;

        scheduler.Schedule(Milliseconds(step * 5), [this, arrowCenter](TaskContext /*task*/)
        {
            me->CastSpell(arrowCenter, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
        });

        Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
        Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());

        scheduler.Schedule(Milliseconds(step * 25), [this, arrowInnerLeft, arrowInnerRight](TaskContext /*task*/)
        {
            me->CastSpell(arrowInnerLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            me->CastSpell(arrowInnerRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
        });

        Position arrowOuterLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());
        Position arrowOuterRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());

        scheduler.Schedule(Milliseconds(step * 50), [this, arrowOuterLeft, arrowOuterRight](TaskContext /*task*/)
        {
            me->CastSpell(arrowOuterLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            me->CastSpell(arrowOuterRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
        });

        return true;
    }

    void DrawDesecratingShotWaveFirst(int32 step, Position pos, float orientation)
    {
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
            scheduler.Schedule(50ms, [this, pos, orientation, distance](TaskContext /*task*/)
            {
                Position rightLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * 4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * 4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                me->CastSpell(rightLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            });

            scheduler.Schedule(75ms, [this, pos, orientation, distance](TaskContext /*task*/)
            {
                Position leftLine(pos.GetPositionX() + (std::cos(orientation - (M_PI / 2)) * -4.0f) + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation - (M_PI / 2)) * -4.0f) + (std::sin(orientation) * distance), pos.GetPositionZ());

                me->CastSpell(leftLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            });

            scheduler.Schedule(100ms, [this, pos, orientation, distance](TaskContext /*task*/)
            {
                Position middleLine(pos.GetPositionX() + (std::cos(orientation) * distance), pos.GetPositionY() + (std::sin(orientation) * distance), pos.GetPositionZ());

                me->CastSpell(middleLine, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            });
        }
    }

    void DrawDesecratingShotScattered()
    {
        for (uint8 i = 0; i < 8; i++)
        {
            for (uint8 i = 0; i < 2; i++)
            {
                scheduler.Schedule(15ms, [this](TaskContext /*task*/)
                {
                    me->CastSpell(me->GetRandomPoint(me->GetPosition(), frand(0.0f, 40.0f)), SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                });
            }
        }

        for (uint8 desecratingShotOnPlayer = std::max<uint8>(4, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 3)) / 3.0f; desecratingShotOnPlayer > 0; desecratingShotOnPlayer--)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 150.0f, true, true))
            {
                for (uint8 i = 0; i < 2; i++)
                {
                    scheduler.Schedule(15ms, [this, target](TaskContext /*task*/)
                    {
                        me->CastSpell(target->GetRandomPoint(target->GetPosition(), frand(1.0f, 2.5f)), SPELL_DESECRATING_SHOT_AREATRIGGER, true);
                    });
                }
            }
        }
    }

    void DrawDesecratingShotSpiral()
    {
        // Three casts
    }

    void DrawDesecratingShotJar()
    {

    }

    void TeleportShadowcopiesToMe()
    {
        for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
        {
            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                shadowCopy->NearTeleportTo(me->GetPosition(), false);
        }
    }

    ObjectGuid GetShadowCopyJumperGuid(int32 index)
    {
        return _shadowCopyGUID[index];
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

    Position const GeRandomPointInCurrentPlatform()
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
    bool _windrunnerActive;
    bool _rangerShotOnCD;
    bool _maldraxxiDesecrated;
    bool _nightfaeDesecrated;
    bool _kyrianDesecrated;
    bool _venthyrDesecrated;
    uint8 _meleeKitCombo;
    uint8 _windrunnerCastTimes;
    uint8 _riveCastTimes;
    uint8 _hauntingWaveTimes;
};

// Domination Arrow - 176920
struct npc_sylvanas_windrunner_domination_arrow : public ScriptedAI
{
    npc_sylvanas_windrunner_domination_arrow(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoZoneInCombat();

        me->SetReactState(REACT_PASSIVE);

        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_DOMINATION_ARROW:
            {
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

                DoCastSelf(SPELL_DOMINATION_ARROW_ACTIVATE, true);

                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                    DoCastSelf(SPELL_DOMINATION_ARROW_CALAMITY_AREA, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, -1));

                if (Unit* target = SelectTarget(SelectTargetMethod::MinDistance, 0, 250.0f, true, true, -SPELL_DOMINATION_CHAIN_PLAYER))
                {
                    _playerGUID = target->GetGUID();

                    me->CastSpell(target, SPELL_DOMINATION_CHAIN_PLAYER, false);
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

// Ranger (Bow) - 347560
class spell_sylvanas_windrunner_ranger_bow : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_bow);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1600));

        if (GetCaster()->HasAura(SPELL_RANGER_DAGGERS_STANCE))
            GetCaster()->RemoveAura(SPELL_RANGER_DAGGERS_STANCE);
        
        if (urand(0, 1))
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN, 0, 0);
        else
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW, 0, 0);

        GetCaster()->ApplyAttackTimePercentMod(WeaponAttackType::MAX_ATTACK, 1.494999885559082031f, true);

        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_UNARMED), GetCaster()->m_Events.CalculateTime(16ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_BOW), GetCaster()->m_Events.CalculateTime(328ms));
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_bow::OnCast);
    }
};

// Ranger (Dagger) - 348010
class spell_sylvanas_windrunner_ranger_dagger : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_dagger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));

        if (GetCaster()->HasAura(SPELL_RANGER_BOW_STANCE))
            GetCaster()->RemoveAura(SPELL_RANGER_BOW_STANCE);

        if (urand(0, 1))
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN, 0, 0);
        else
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS, 0, 0);

        GetCaster()->ApplyAttackTimePercentMod(WeaponAttackType::MAX_ATTACK, 1.149999976158142089f, true);

        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_UNARMED), GetCaster()->m_Events.CalculateTime(16ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_DAGGERS), GetCaster()->m_Events.CalculateTime(313ms));
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_dagger::OnCast);
    }
};

// Ranger Shot - 347548
class spell_sylvanas_windrunner_ranger_shot : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_shot);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));
    }

    void Register() override { }
};

// Ranger Strike - 348299
class spell_sylvanas_windrunner_ranger_strike : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_strike);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        if (urand(0, 1))
            GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_RIGHT, 0, 0, 1.0f, true);
        else
            GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_LEFT, 0, 0, 1.0f, true);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_strike::OnCast);
    }
};

// Windrunner (Disappear 01) - 352303
// Windrunner (Disappear 02) - 358975
class spell_sylvanas_windrunner_disappear : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_disappear);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SYLVANAS_ROOT });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        // TODO: the first one is used for Windrunner, the duration is dynamic, most likely dependent on the action performed
        // whereas the second is only for Domination Chains and rest of the phases
        if (GetSpellInfo()->Id == SPELL_WINDRUNNER_DISAPPEAR_02)
            GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3600));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_disappear::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Withering Fire - 347928
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

// Desecrating Shot - 348627
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

class RangerHeartseekerMissileEvent : public BasicEvent
{
    public:
        RangerHeartseekerMissileEvent(Unit* caster, Unit* victim) : _caster(caster), _victim(victim) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _caster->SendPlaySpellVisual(_victim, SPELL_VISUAL_RANGER_HEARTSEEKER, 0, 0, 36.0f, false);

            _caster->CastSpell(_victim, SPELL_RANGER_HEARTSEEKER_PHYSICAL_DAMAGE, true);
            _caster->CastSpell(_victim, SPELL_RANGER_HEARTSEEKER_SHADOW_DAMAGE, true);

            if (Aura* rangerHeartseeker = _caster->GetAura(SPELL_RANGER_HEARTSEEKER_CHARGE))
                rangerHeartseeker->ModStackAmount(-1, AuraRemoveMode::AURA_REMOVE_BY_DEFAULT);
            return true;
        }

    private:
        Unit* _caster;
        Unit* _victim;
};

// Ranger's Heartseeker - 352663
class spell_sylvanas_windrunner_ranger_heartseeker : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_heartseeker);

    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_UNARMED), GetCaster()->m_Events.CalculateTime(16ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_SHEATHE_BOW), GetCaster()->m_Events.CalculateTime(328ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_COPY), GetCaster()->m_Events.CalculateTime(343ms));
        GetCaster()->m_Events.AddEvent(new SetSheatheStateOrNameplate(GetCaster(), DATA_CHANGE_NAMEPLATE_TO_SYLVANAS), GetCaster()->m_Events.CalculateTime(2s));
    }

    void Register() override { }
};

class spell_sylvanas_windrunner_ranger_heartseeker_aura : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_ranger_heartseeker_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(1ms));
        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(281ms));
        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(562ms));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_ranger_heartseeker_aura::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Ranger's Heartseeker (Shadow damage) - 352652
class spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_BANSHEE_MARK,
            SPELL_BANSHEES_BANE
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->GetAreaId() != AREA_THE_CRUCIBLE)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_MARK, true);
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEES_BANE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Domination Chains - 349419
class spell_sylvanas_windrunner_domination_chains : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_domination_chains);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_DOMINATION_ARROW_ACTIVATE });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        std::list<Creature*> arrowList;
        GetCreatureListWithEntryInGrid(arrowList, GetCaster(), NPC_DOMINATION_ARROW, 250.0f);

        for (Creature* arrow : arrowList)
        {
            if (arrow->IsAIEnabled())
                arrow->AI()->DoAction(ACTION_ACTIVATE_DOMINATION_ARROW);
        }
    }

    void HandleAfterCast()
    {
        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_NORMAL_CAST, 0, 0);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_domination_chains::OnCast);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_domination_chains::HandleAfterCast);
    }
};

// Domination Arrow (Fall) - 352317
// Domination Arrow (Fall and Spawn) - 352319
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

// Domination Chain (Player) - 349451
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
        if (!GetCaster())
            return;

        if (Player* chainedPlayer = ObjectAccessor::GetPlayer(*GetCaster(), _playerGUID))
        {
            chainedPlayer->RemoveAurasDueToSpell(SPELL_DOMINATION_CHAIN_PERIODIC);

            chainedPlayer->RemoveMovementForce(_arrowAreaTriggerGUID);
        }
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

// Domination Chain (Periodic) - 349458
class spell_sylvanas_windrunner_domination_chain_periodic : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_domination_chain_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINATION_CHAIN_PERIODIC });
    }

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

// Wailing Arrow - 347609
class spell_sylvanas_windrunner_wailing_arrow : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_wailing_arrow);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow::OnCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Wailing Arrow (Damage) - 348056
class spell_sylvanas_windrunner_wailing_arrow_damage : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_wailing_arrow_damage);

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
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_damage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_damage::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// Veil of Darkness (Phase 1 - Fade) - 352470
// Veil of Darkness (Phase 2 - Fade) - 353273
// Veil of Darkness (Phase 3 - Fade) - 354168
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
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_veil_of_darkness_fade::OnCast);
    }
};

// Veil of Darkness (Phase 1) - 347726
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
        GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));

        GetCaster()->SetPlayHoverAnim(true);

        GetCaster()->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_BANSHEE_MODEL);

        GetCaster()->SendPlayOrphanSpellVisual(GetCaster()->GetGUID(), SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01_HC, 5.0f, true);

        // TODO: Set AnimTier 3 when it gets implemented

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS, 0, 0);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void HandleAfterCast()
    {
        GetCaster()->SetPlayHoverAnim(false);
        GetCaster()->SetDisplayId(DATA_DISPLAY_ID_SYLVANAS_ELF_MODEL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleAfterCast);
    }
};

// Rive - 353417
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
                    if (Creature* shadowCopy3 = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(3)))
                    {
                        shadowCopy3->CastSpell(sylvanas, SPELL_RIVE_CHAIN, false);

                        if (GameObject* platformSpear = shadowCopy3->FindNearestGameObjectOfType(GameobjectTypes::GAMEOBJECT_TYPE_GOOBER, 15.0f))
                            platformSpear->SetSpellVisualId(SPELL_VISUAL_TORGHAST_SPIRE_BREAK, sylvanas->GetGUID());
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
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(0)))
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

// Rive (Fast) - 353418
class spell_sylvanas_windrunner_rive_fast : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_rive_fast);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RIVE_CHAIN_FAST,
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
                    if (Creature* shadowCopy3 = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(3)))
                    {
                        shadowCopy3->CastSpell(sylvanas, SPELL_RIVE_CHAIN_FAST, false);

                        if (GameObject* platformSpear = shadowCopy3->FindNearestGameObjectOfType(GameobjectTypes::GAMEOBJECT_TYPE_GOOBER, 15.0f))
                            platformSpear->SetSpellVisualId(SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST, sylvanas->GetGUID());
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
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(0)))
                        sylvanas->CastSpell(shadowCopy->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
                }
            }
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_rive_fast::HandleAfterCast);
    }
};

// Banshee Wail - 348094
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
        GetCaster()->CastSpell(GetCaster(), SPELL_BANSHEE_WAIL_EXPIRE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 250.0f);

        for (Player* target : targetList)
            GetCaster()->CastSpell(target, SPELL_BANSHEE_WAIL_MARKER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4650));
    }

    void HandleAfterCast()
    {
        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 200.0f);

        for (Player* target : targetList)
            GetCaster()->CastSpell(target, GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_banshee_wail::HandleAfterCast);
    }
};

// Banshee Wail (Marker) - 357719
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

// Banshee Wail (Triggered Missile) - 348108
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

// Banshee Wail (Interrupt) - 351252
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
        HauntingWaveEvent(Unit* owner, Position const hauntingWaveDest, uint32 hauntingWaveAreaTriggerSpell) : _owner(owner),
            _hauntingWaveDest(hauntingWaveDest), _hauntingWaveAreaTriggerSpell(hauntingWaveAreaTriggerSpell) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_hauntingWaveDest, _hauntingWaveAreaTriggerSpell, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _hauntingWaveDest;
        uint32 _hauntingWaveAreaTriggerSpell;
};

// Haunting Wave - 352271
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

// Ruin - 355540
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

class BaneArrowEvent : public BasicEvent
{
    public:
        BaneArrowEvent(Unit* owner, Position const arrowDestPos) : _owner(owner), _arrowDestPos(arrowDestPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_arrowDestPos, SPELL_BANE_ARROWS_DAMAGE, true);
            _owner->CastSpell(_arrowDestPos, SPELL_BANSHEES_BANE_AREATRIGGER, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _arrowDestPos;
};

// Bane Arrows - 354011
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
                        {
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
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_bane_arrows::HandleAfterCast);
    }
};

class BansheeBaneEvent : public BasicEvent
{
    public:
        BansheeBaneEvent(Unit* owner, Position const bansheeBanePos) : _owner(owner), _bansheeBanePos(bansheeBanePos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_bansheeBanePos, SPELL_BANSHEES_BANE_AREATRIGGER, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _bansheeBanePos;
};

// Banshee's Bane - 353929
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
                    if (sylvanas->IsInCombat())
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
        BansheesFuryEvent(Unit* owner, uint8 covenantPlatform) : _owner(owner), _covenantPlatform(covenantPlatform) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (InstanceScript* instance = _owner->GetInstanceScript())
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
        Unit* _owner;
        uint8 _covenantPlatform;
};

// Banshee's Fury - 354068
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

        // TODO: check on every player if Banshee's Bane is on; if yes, trigger explode on them
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
                        if (!ai->IsPlatformDesecrated(covenantPlatform))
                        {
                            for (uint8 i = 0; i < 10; i++)
                                GetCaster()->m_Events.AddEvent(new BansheesFuryEvent(GetCaster(), covenantPlatform), GetCaster()->m_Events.CalculateTime(50ms * i));
                        }
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
        RazeEvent(Unit* owner) : _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (InstanceScript* instance = _owner->GetInstanceScript())
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                        sylvanas->SendPlaySpellVisual(ai->GeRandomPointInCurrentPlatform(), 0.0f, SPELL_VISUAL_RAZE, 0, 0, 0.100000001490116119f, true);
                }
            }

            return true;
        }

    private:
        Unit* _owner;
};

// Raze - 354147
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

// HACKFIX: pathfinding on gameobject is NYI, I'm adding custom points for jumping from one chain to the other
Position const BolvarPhaseTwoPos[10] =
{
    { 204.6475f, -842.7760f, 4999.995f, 0.7806f },
    { 205.5017f, -839.9323f, 5000.162f, 0.9862f },
    { 195.3038f, -843.8055f, 5000.038f, 3.0062f },
    { 112.9909f, -821.6018f, 4999.974f, 3.9780f }, // HACKFIX
    { 48.6562f,  -877.9184f, 5000.093f, 3.9858f }
};

Position const BolvarPrePhaseThreePos = { -249.54861f, -1278.5382f, 5667.1157f, 1.5865f };

// Highlord Bolvar Fordragon - 178081
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

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_JUMP_SECOND_CHAIN)
            me->GetMotionMaster()->MovePoint(0, BolvarPhaseTwoPos[4], false);
    }

    void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_WINDS_OF_ICECROWN)
        {
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
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
        _events.ScheduleEvent(EVENT_RUNIC_MARK, 1s, 1);
        _events.ScheduleEvent(EVENT_GLYPH_OF_DESINTEGRATION, 5s, 1);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_WINDS_OF_ICECROWN_PRE:
            {
                // HACKFIX: GameObject pathing NYI
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

                // HACKFIX: GameObject pathing NYI
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
                {
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastVictim(SPELL_RUNIC_MARK, false);
                    else
                        DoCastVictim(SPELL_RUNIC_MARK_TRIGGERED, false);

                    _events.Repeat(6s, 8s);
                    break;
                }

                case EVENT_GLYPH_OF_DESINTEGRATION:
                {
                    DoCastVictim(SPELL_GLYPH_OF_DESINTEGRATION, false);
                    _events.Repeat(10s, 12s);
                    break;
                }

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

// Runic Mark (Triggered) - 354928
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

// Charge Towards Sylvanas - 357046
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

// Winds of Icecrown - 356941
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

// Thrall - 176532
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

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_JUMP_SECOND_CHAIN)
            me->GetMotionMaster()->MovePoint(0, ThrallPhaseTwoPos[3], false);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
                {
                    DoCastSelf(SPELL_FLAMEAXE, false);
                    _events.Repeat(18s, 20s);
                    break;
                }

                case EVENT_PULVERIZE:
                {
                    DoCastVictim(SPELL_PULVERIZE, false);
                    _events.Repeat(9s + 750ms, 15s + 800ms);
                    break;
                }

                case EVENT_STONECRASH_PHASE_ONE_AND_THREE:
                {
                    DoCastVictim(SPELL_STONECRASH, false);
                    _events.Repeat(12s, 18s);
                    break;
                }

                case EVENT_EARTHEN_GRASP:
                {
                    DoCastVictim(SPELL_EARTHEN_GRASP, false);
                    _events.Repeat(8s, 10s);
                    break;
                }
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

// Pulverize - 354918
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

// Pulverize (triggered) - 354923
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

// Stonecrash (Phase 1 and 3) - 357139
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

// Stonecrash (Phase 2) - 357137
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

// Jaina Proudmoore - 176533
struct npc_sylvanas_windrunner_jaina : public ScriptedAI
{
    npc_sylvanas_windrunner_jaina(Creature* creature) : ScriptedAI(creature, DATA_JAINA_PROUDMOORE_PINNACLE),
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
        if (type == POINT_MOTION_TYPE)
        {
            if (id == POINT_TELEPORT_TO_THIRD_CHAIN)
                me->CastSpell(JainaPhaseTwoPos[4], SPELL_TELEPORT_PHASE_TWO_MASTER, true);

            if (id == POINT_TELEPORT_TO_SIXTH_CHAIN)
                me->CastSpell(JainaPhaseTwoPos[8], SPELL_TELEPORT_PHASE_TWO_MASTER, true);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
        _events.ScheduleEvent(EVENT_COMET_BARRAGE, 5s, 1);
        _events.ScheduleEvent(EVENT_FRIGID_SHARDS, 10s, 1);
        _events.ScheduleEvent(EVENT_CONE_OF_COLD, 14s, 1);
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
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(0)))
                                sylvanas->SetNameplateAttachToGUID(ai->GetShadowCopyJumperGuid(0));

                            sylvanas->CastSpell(sylvanas, SPELL_WINDRUNNER_DISAPPEAR_02, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));

                            sylvanas->SendPlayOrphanSpellVisual(SylvanasWavePos[0], SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*sylvanas, ai->GetShadowCopyJumperGuid(0)))
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
                    DoCastSelf(SPELL_CHAMPIONS_MOD_FACTION, true);

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

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FRIGID_SHARDS:
                {
                    DoCastVictim(SPELL_FRIGID_SHARDS, false);
                    _events.Repeat(6s, 8s);
                    break;
                }

                case EVENT_CONE_OF_COLD:
                {
                    DoCastVictim(SPELL_CONE_OF_COLD, false);
                    _events.Repeat(12s, 13s);
                    break;
                }

                case EVENT_COMET_BARRAGE:
                {
                    DoCastVictim(SPELL_COMET_BARRAGE, false);
                    _events.Repeat(16s, 18s);
                    break;
                }

                default:
                    break;
            }
        }

        DoSpellAttackIfReady(SPELL_ICE_BOLT);
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
};

// Frigid Shards - 354933
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

// Comet Barrage - 354938
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

// Teleport to Phase Two - 350903
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

// Teleport to Phase Three - 350906
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

// Teleport - 357103
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

enum AnduinActions
{

};

// Anduin Wrynn - 178072
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

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
                    me->AddUnitFlag2(UNIT_FLAG2_UNTARGETABLE_BY_CLIENT);

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
                {
                    DoCastSelf(SPELL_BLASPHEMY, false);

                    _events.Repeat(25s, 45s);
                    break;
                }

                case EVENT_LIGHT_BLAST:
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);

                    _events.Repeat(8s, 12s);
                    break;
                }

                case EVENT_CRIPPLING_DEFEAT:
                {
                    DoCastVictim(SPELL_CRIPPLING_DEFEAT, false);
                    break;
                }

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
        BlasphemyEvent(Unit* owner, Position const blasphemyDestPos, uint8 queuedSpell) : _owner(owner), _blasphemyDestPos(blasphemyDestPos),
            _queuedSpell(queuedSpell) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_queuedSpell == 0)
                _owner->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);
            else
                _owner->CastSpell(_blasphemyDestPos, SPELL_BLASPHEMY_DAMAGE, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _blasphemyDestPos;
        uint8 _queuedSpell;
};

// Blasphemy - 357729
class spell_sylvanas_windrunner_blasphemy_pre : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_blasphemy_pre);

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
        AfterEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_blasphemy_pre::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_blasphemy_pre::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Blasphemy - 357730
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

/// Regenates 10 energy every 3s roughly
static std::array<int32, 3> _sylvanasPowerRegenCycle =
{
    3, 3, 4
};

// Energize Power Aura (Sylvanas) - 352312
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
};

// Activate Phase Intermission - 359429
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

// Activate Finish Boss - 359431
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

// Activate Invigorating Fields - 353660 NYI
class spell_sylvanas_windrunner_activate_invigorating_fields : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_activate_invigorating_fields);

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            // HACKFIX: the caster is an AIGroup; we don't know much about these, so we set Sylvanas as caster
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                for (uint8 i = 0; i < 8; i++)
                    AreaTrigger::CreateAreaTrigger(40001, sylvanas, nullptr, GetSpellInfo(), InvigoratingFieldPos[i], -1, GetSpell()->m_SpellVisual, ObjectGuid::Empty);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_activate_invigorating_fields::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Desecrating Shot - 22400
struct at_sylvanas_windrunner_disecrating_shot : AreaTriggerAI
{
    at_sylvanas_windrunner_disecrating_shot(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _updateDiff(0) { }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        _updateDiff += diff;

        if (_updateDiff >= 2500)
        {
            if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
                {
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*at, ai->GetShadowCopyJumperGuid(0)))
                        shadowCopy->SendPlaySpellVisual(at->GetPosition(), 0, SPELL_VISUAL_DESECRATING_ARROW, 0, 0, 0.280999988317489624f, true);

                    sylvanas->CastSpell(at->GetPosition(), SPELL_DESECRATING_SHOT_TRIGGERED, true);

                    at->Remove();
                }
            }
        }
    }

private:
    InstanceScript* _instance;
    uint32 _updateDiff;
};

class DebrisEvent : public BasicEvent
{
    public:
        DebrisEvent(Unit* owner, Position const debrisDestPos) : _owner(owner), _debrisDestPos(debrisDestPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_debrisDestPos, SPELL_RIVEN_DEBRIS, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _debrisDestPos;
};

// Rive - 23028
struct at_sylvanas_windrunner_rive : AreaTriggerAI
{
    at_sylvanas_windrunner_rive(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnSplineIndexReached(int splineIndex) override
    {
        if (!_instance)
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (splineIndex == DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR)
            {
                std::list<WorldObject*> riveMarkerAreaTriggers;
                Trinity::AllWorldObjectsInRange objects(sylvanas, 250.0f);
                Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(sylvanas, riveMarkerAreaTriggers, objects);
                Cell::VisitAllObjects(sylvanas, searcher, 250.0f);

                for (std::list<WorldObject*>::const_iterator itr = riveMarkerAreaTriggers.begin(); itr != riveMarkerAreaTriggers.end(); ++itr)
                {
                    if (AreaTrigger* riveMarkerAreaTrigger = (*itr)->ToAreaTrigger())
                    {
                        if (riveMarkerAreaTrigger->GetEntry() == DATA_AREATRIGGER_RIVE_MARKER)
                            riveMarkerAreaTrigger->Remove();
                    }
                }
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

// Frozen Bridge - 5428, Earthen Bridge - 5428
struct at_sylvanas_windrunner_bridges : AreaTriggerAI
{
    at_sylvanas_windrunner_bridges(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate() override
    {
        if (!_instance)
            return;

        at->SetDuration(-1);
    }

private:
    InstanceScript* _instance;
};

// Haunting Wave - 22874, 23694, 23693, 23673
struct at_sylvanas_windrunner_haunting_wave : AreaTriggerAI
{
    at_sylvanas_windrunner_haunting_wave(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

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

// Blasphemy (Pre-Phase 3) - 23506
struct at_sylvanas_windrunner_blasphemy_pre : AreaTriggerAI
{
    at_sylvanas_windrunner_blasphemy_pre(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance)
            return;

        if (unit->GetEntry() == NPC_BOLVAR_FORDRAGON_PINNACLE || unit->GetEntry() == NPC_JAINA_PROUDMOORE_PINNACLE || unit->GetEntry() == NPC_THRALL_PINNACLE)
        {
            if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                anduin->CastSpell(unit, SPELL_BLASPHEMY_STUN, true);
        }

        if (unit->IsPlayer())
        {
            if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                anduin->CastSpell(unit, SPELL_BLASPHEMY_STUN, true);
        }
    }

private:
    InstanceScript* _instance;
};

// Banshee's Bane - 27461
struct at_sylvanas_windrunner_banshee_bane : AreaTriggerAI
{
    at_sylvanas_windrunner_banshee_bane(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _readyToPick(false), _updateDiff(0) { }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        _updateDiff += diff;

        if (_updateDiff >= 1000 && !_readyToPick)
            _readyToPick = true;
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || !_readyToPick)
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(unit, SPELL_BANSHEES_BANE, true);

        unit->SendPlaySpellVisual(at->GetPosition(), 0.0f, SPELL_VISUAL_UNK02_PLAYER, 0, 0, 0.5f, true);

        at->Remove();
    }

private:
    InstanceScript* _instance;
    bool _readyToPick;
    uint32 _updateDiff;
};

// Raze - 23117
struct at_sylvanas_windrunner_raze : AreaTriggerAI
{
    at_sylvanas_windrunner_raze(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(unit, SPELL_RAZE_PERIODIC, true);
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
    RegisterAuraScript(spell_sylvanas_windrunner_disappear);
    RegisterSpellScript(spell_sylvanas_windrunner_withering_fire);
    RegisterSpellScript(spell_sylvanas_windrunner_desecrating_shot);
    RegisterSpellAndAuraScriptPair(spell_sylvanas_windrunner_ranger_heartseeker, spell_sylvanas_windrunner_ranger_heartseeker_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chains);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_arrow);
    RegisterAuraScript(spell_sylvanas_windrunner_domination_chain);
    RegisterAuraScript(spell_sylvanas_windrunner_domination_chain_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_rive);
    RegisterSpellScript(spell_sylvanas_windrunner_rive_fast);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail);
    RegisterAuraScript(spell_sylvanas_windrunner_banshee_wail_marker);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_triggered_missile);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_interrupt);
    RegisterSpellScript(spell_sylvanas_windrunner_haunting_wave);
    RegisterAuraScript(spell_sylvanas_windrunner_ruin);
    RegisterSpellScript(spell_sylvanas_windrunner_bane_arrows);
    RegisterAuraScript(spell_sylvanas_windrunner_banshee_bane);
    RegisterAuraScript(spell_sylvanas_windrunner_banshee_fury);
    RegisterSpellScript(spell_sylvanas_windrunner_raze);

    RegisterAuraScript(spell_sylvanas_windrunner_energize_power_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_phase_intermission);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_finish_boss);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_invigorating_fields);

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
    RegisterAuraScript(spell_sylvanas_windrunner_frigid_shards);
    RegisterSpellScript(spell_sylvanas_windrunner_comet_barrage);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_two);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_three);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_anduin);
    RegisterAuraScript(spell_sylvanas_windrunner_blasphemy_pre);
    RegisterAuraScript(spell_sylvanas_windrunner_blasphemy);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_disecrating_shot);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_rive);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_bridges);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_blasphemy_pre);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_banshee_bane);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_raze);
}
