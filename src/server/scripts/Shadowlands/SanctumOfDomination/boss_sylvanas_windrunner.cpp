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
#include "CellImpl.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
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
    // General Visuals
    SPELL_VISUAL_DISAPPEAR_LONG                         = 358975,

    // Stances
    SPELL_RANGER_BOW_STANCE                             = 347560,
    SPELL_RANGER_DAGGERS_STANCE                         = 348010,

    // Ranger Shot
    SPELL_RANGER_SHOT                                   = 347548,

    // Ranger Strike
    SPELL_RANGER_STRIKE                                 = 348299,

    // Windrunner
    SPELL_WINDRUNNER                                    = 347504,
    SPELL_WINDRUNNER_DISAPPEAR                          = 352303,
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
    SPELL_DESECRATING_SHOT_DAMAGE                       = 356377,

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
    SPELL_WAILING_ARROW_CAST_JUMP                       = 355839,
    SPELL_WAILING_ARROW_MISSILE                         = 348055,
    SPELL_WAILING_ARROW_DAMAGE                          = 348056,
    SPELL_WAILING_ARROW_TARGET_DAMAGE                   = 357617,
    SPELL_WAILING_ARROW_AOE_DAMAGE                      = 357618,

    // Domination Chains
    SPELL_DOMINATION_CHAINS_SPIN                        = 351187,
    SPELL_DOMINATION_CHAINS_JUMP                        = 347602,
    SPELL_DOMINATION_CHAINS                             = 349419,
    SPELL_DOMINATION_ARROW_SHOT_VISUAL                  = 350426,
    SPELL_DOMINATION_ARROW_FALL                         = 352317, 
    SPELL_DOMINATION_ARROW_FALL_AND_VISUAL              = 352319,
    SPELL_DOMINATION_ARROW_DAMAGE                       = 352318,
    SPELL_DOMINATION_ARROW_ACTIVATE                     = 356650,
    SPELL_DOMINATION_ARROW_CALAMITY_AREA                = 356769,
    SPELL_DOMINATION_ARROW_CALAMITY_AREATRIGGER         = 356624,
    SPELL_DOMINATION_ARROW_CALAMITY_DAMAGE              = 356649,

    SPELL_DOMINATION_CHAIN_PLAYER                       = 349451,
    SPELL_DOMINATION_CHAIN_PERIODIC                     = 349458,

    // Veil of Darkness (Generic)
    SPELL_VEIL_OF_DARKNESS_DESELECT                     = 354366,
    SPELL_VEIL_OF_DARKNESS_SCREEN_FOG                   = 354580,
    SPELL_VEIL_OF_DARKNESS_ABSORB_AURA                  = 347704,
    SPELL_VEIL_OF_DARKNESS_DAMAGE                       = 350777,

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
    SPELL_RIVE_MARKER                                   = 353419,
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
    SPELL_BANSHEE_WAIL_DAMAGE                           = 348109,
    SPELL_BANSHEE_WAIL_INTERRUPT                        = 351252,
    SPELL_BANSHEE_WAIL_SILENCE                          = 351253,
    SPELL_BANSHEE_WAIL_MARKER                           = 357719,
    SPELL_BANSHEE_WAIL_MASTER                           = 355489,

    SPELL_TELEPORT_TO_PHASE_TWO_01                      = 350903,
    SPELL_TELEPORT_TO_PHASE_TWO_02                      = 350904, // This one has a spell trigger, research further
    SPELL_TELEPORT_NO_IDEA                              = 350905, // TARGET_DEST_DB, not sniffed
    SPELL_TELEPORT_TO_PHASE_THREE                       = 350906, // TARGET_DEST_NEARBY_ENTRY

    // Banshee Form
    SPELL_BANSHEE_FORM                                  = 348146,

    SPELL_BANSHEE_READY_STANCE                          = 357758,


    SPELL_CALL_EARTH_DEBRIS                             = 355491,

    // Ruin
    SPELL_RUIN                                          = 355540,

    // Veil of Darkness (Phase 2)
    SPELL_VEIL_OF_DARKNESS_PHASE_2_FADE                 = 353273,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_GROW                 = 352239,
    SPELL_VEIL_OF_DARKNESS_PHASE_2_AREA                 = 352225,
    SPELL_VEIL_OF_DARKNESS_PHASE_2                      = 347741,

    // Bane Arrows


    // Banshee's Blades
    SPELL_BANSHEE_BLADE_PHYSICAL_DAMAGE                 = 358182,
    SPELL_BANSHEE_BLADE_SHADOW_DAMAGE                   = 358183,

    // Veil of Darkness (Phase 3)
    SPELL_VEIL_OF_DARKNESS_PHASE_3_FADE                 = 354168,
    SPELL_VEIL_OF_DARKNESS_PHASE_3_GROW                 = 354143,
    SPELL_VEIL_OF_DARKNESS_PHASE_3                      = 354142,

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

    SPELL_INTERMISSION_SCENE                            = 359062,

    SPELL_FINAL_SCENE                                   = 358806,
    SPELL_FINAL_CINEMATIC                               = 358985,
    SPELL_SYLVANAS_FEIGN_DEATH                          = 358844,

    SPELL_TELEPORT_TO_PHASE_3_RANDOM_POS                = 357101,

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
    EVENT_FINISH_INTERMISSION
};

enum Actions
{                    
    ACTION_PAUSE_ATTACK_FOR_EVENT                       = 1,
    ACTION_ACTIVATE_ATTACK_FOR_EVENT,
    ACTION_WINDRUNNER_MODEL,
    ACTION_DESECRATING_SHOT_LAUNCH,
    ACTION_ACTIVATE_DOMINATION_ARROW,
    ACTION_WAILING_ARROW,
    ACTION_PREPARE_INTERMISSION,
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
    SAY_VEIL_OF_DARKNESS                                = 12,
    SAY_INTERMISSION_BEGIN                              = 13,
    SAY_INTERMISSION_END                                = 14,

    SAY_START_PHASE_THREE                               = 25
};

enum Conversations
{
    CONVERSATION_INTRO                                  = 17368
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
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TELEPORT     = 150078,
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
    SPELL_VISUAL_KIT_SYLVANAS_UNK_17                    = 149160, // Does nothing
    SPELL_VISUAL_KIT_SYLVANAS_RUIN_INTERRUPTED          = 145486,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_WAVE              = 148270,
    SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_HUMAN      = 146626,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER             = 145482,
    SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER_SOUND       = 145850,
    SPELL_VISUAL_KIT_SYLVANAS_SHOOT                     = 149795, // Withering Fire on phase 2?
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_VEIL_OF_DARKNESS1 = 144927,
    SPELL_VISUAL_KIT_SYLVANAS_UNK_18                    = 149161, // Does nothing
    SPELL_VISUAL_KIT_SYLVANAS_DARK_FOG                  = 150066,
    SPELL_VISUAL_KIT_SYLVANAS_STOMP                     = 148200,
    SPELL_VISUAL_KIT_SYLVANAS_SWITCH_PLATFORM           = 149580,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_SCREAM            = 146059,
    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_BANE              = 145872,
    SPELL_VISUAL_KIT_SYLVANAS_BLACKEN_WITH_DAGGERS      = 149487, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_DISAPPEAR_MODEL           = 149491, // NOT SNIFFED
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_01     = 148191,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_02     = 148193,
    SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS_3_03     = 148192,

    SPELL_VISUAL_KIT_SYLVANAS_BANSHEE_VEIL_OF_DARKNESS2 = 144927, // Same as 17

    SPELL_VISUAL_KIT_JAINA_KNEEL_THEN_STAND             = 146285,
    SPELL_VISUAL_KIT_JAINA_CHEERS                       = 147631,
    SPELL_VISUAL_KIT_JAINA_FROZEN_BRIDGE                = 142472, // NOT ON SNIFF

    SPELL_VISUAL_KIT_THRALL_KNEEL_THEN_STAND            = 147632,
    SPELL_VISUAL_KIT_THRALL_EARTHEN_BRIDGE              = 142473,

    SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY            = 148315,

    SPELL_VISUAL_KIT_JAILER_IDK_01                      = 149329,

    SPELL_VISUAL_KIT_PLAYER_ACTIVATE_FIELDS             = 144754,

    SPELL_VISUAL_KIT_GENERIC_TELEPORT_APPEAR            = 147629,
};

enum SpellVisuals
{
    SPELL_VISUAL_RANGER_STRIKE_01                       = 106165, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_02                       = 106153, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_03                       = 106161, // At 1.0f
    SPELL_VISUAL_RANGER_STRIKE_04                       = 106160, // At 1.0f
    SPELL_VISUAL_WINDRUNNER_01                          = 107722, // At 0.5f
    SPELL_VISUAL_WINDRUNNER_02                          = 110312, // At 0.25f
    SPELL_VISUAL_WINDRUNNER_03                          = 107920, // At 0.25f
    SPELL_VISUAL_DESECRATING_ARROW                      = 106363, // At 0.40f - 0.12f
    SPELL_VISUAL_WITHERING_FIRE                         = 105944, // At 48.0f, false as time
    SPELL_VISUAL_RANGER_HEARTSEEKER                     = 107607, // At 36f, false as time
    SPELL_VISUAL_DOMINATION_ARROW                       = 107501, // At 2.5f
    SPELL_VISUAL_DOMINATION_ARROW_SPAWN                 = 109620, // At 2.5f
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01              = 109159, // At 5.0f
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK                   = 108070,
    SPELL_VISUAL_TORGHAST_SPIRE_BREAK_FAST              = 108071,
    SPELL_VISUAL_RIVEN_DEBRIS                           = 107877, // At 1.744643688201904296f - 1.616904616355895996f, apparently dynamic
    SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_02_03           = 109371, // At 3.0f
    SPELL_VISUAL_BANE_ARROW                             = 108112, // At 3.2f
    SPELL_VISUAL_BLASPHEMY                              = 109680, // At 1.0f
    SPELL_VISUAL_JAILER_BOLT                            = 107337  // At 90.0f, false as time
};

enum Miscelanea
{
    DISPLAYID_SYLVANAS_ELF_MODEL                        = 101311,
    DISPLAYID_SYLVANAS_BANSHEE_MODEL                    = 100930,

    DATA_AREATRIGGER_DOMINATION_ARROW                   = 27683,
    DATA_AREATRIGGER_RIVE_MARKER                        = 6197,

    DATA_SPLINEPOINT_RIVE_MARKER_DISAPPEAR              = 2,

    DATA_RANGER_STRIKE_01                               = 0,
    DATA_RANGER_STRIKE_02                               = 1,
    DATA_RANGER_STRIKE_03                               = 2,
    DATA_RANGER_STRIKE_04                               = 3,

    DATA_DESECRATING_SHOT_PATTERN_STRAIGHT              = 0,
    DATA_DESECRATING_SHOT_PATTERN_SCATTERED             = 1,
    DATA_DESECRATING_SHOT_PATTERN_WAVE                  = 2,
    DATA_DESECRATING_SHOT_PATTERN_SPIRAL                = 3,
    DATA_DESECRATING_SHOT_PATTERN_JAR                   = 4
};

Position const SylvanasFirstPhasePlatformCenter = { 234.9542f, -829.9804f, 4104.986f };

constexpr float PLATFORM_RADIUS = 75.0f;

Position const SylvanasIntro[4] =
{
    { 231.15799f, -832.816f,   4105.0386f          },
    { 242.00348f, -840.51215f, 4105.0386f          },
    { 241.23091f, -830.0955f,  4105.0386f          },
    { 225.73611f, -844.0746f,  4104.9882f, 1.3613f }
};

Position const SylvanasVeilOfDarknessPos = { 255.0392f, -824.69995f, 4205.122f };

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

Position const RiveFinish =            { 235.1163f, -829.90106f, 4105.0386f, 5.4824f   };

Position const SylvanasPhase2Pre =     { -14.5625f, -943.441f,   4999.990f,  0.8928f   };

Position const SylvanasPhase3Pre =     { -258.991f, -1265.9966f, 5667.114f,  0.3118f   };

Position const SylvanasPlaform1Pos =   { -280.646f, -1245.48f,   5672.13f,   2.3046f   };

Position const PlaformsMiddlePos[4] =
{
    { -289.503f, -1237.0555f, 5671.9053f, 5.5017f },
    { 0.f },
    { 0.f },
    { 0.f }
};

Position const SylvanasUnconciousPos = { -249.876f, -1252.4791f, 5667.1157f, 3.3742f   };

// Sylvanas Windrunner - 175732
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER), _windrunnerActive(false), _sayDaggersOnCD(false),
        _sayDesecratingOnCD(false), _lastSpellUsed(0), _windrunnerCastTimes(0), _riveCastTimes(0) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

        if (Creature* ridingCopy = me->FindNearestCreature(NPC_SYLVANAS_SHADOW_COPY_RIDING, 10.0f, true))
        {
            ridingCopy->SetReactState(REACT_PASSIVE);

            ridingCopy->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            ridingCopy->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            ridingCopy->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

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

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        _windrunnerActive = false;
        _sayDaggersOnCD = false;
        _sayDesecratingOnCD = false;
        _lastSpellUsed = 0;
        _windrunnerCastTimes = 0;
        _riveCastTimes = 0;
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SYLVANAS_SHADOW_COPY_FIGHTERS:
            {
                _shadowCopyGUID.push_back(summon->GetGUID());

                summon->SetReactState(REACT_PASSIVE);

                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                break;
            }

            case NPC_DOMINATION_ARROW:
            {
                summon->SetReactState(REACT_PASSIVE);

                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                summon->SetUnitFlags2(UNIT_FLAG2_DISABLE_TURN);

                break;
            }

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

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        Talk(SAY_AGGRO);

        for (uint8 i = 0; i < 4; i++)
            me->SummonCreature(NPC_SYLVANAS_SHADOW_COPY_FIGHTERS, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);

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
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_01, SylvanasIntro[0], false);
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
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_02, SylvanasIntro[1], false);
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
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_03, SylvanasIntro[2], false);
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
                    me->NearTeleportTo(SylvanasIntro[3], false);
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TELEPORT, 0, 0);
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

            case ACTION_PAUSE_ATTACK_FOR_EVENT:
            {
                me->InterruptNonMeleeSpells(true);
                me->GetMotionMaster()->Clear();
                me->StopMoving();
                me->AttackStop();

                me->SetReactState(REACT_PASSIVE);
                break;
            }

            case ACTION_ACTIVATE_ATTACK_FOR_EVENT:
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0, 150.0f, true, true))
                    AttackStart(target);

                break;
            }

            case ACTION_WINDRUNNER_MODEL:
            {
                DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                // HACKFIX: apparently, sylvanas is the one doing the visual stuff here, but I haven't found the spellId or whatever makes her black, further research needed
                me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
                DoCastSelf(SPELL_RIVE_DISAPPEAR, true);

                me->HandleEmoteCommand(EMOTE_ONESHOT_DODGE);

                scheduler.Schedule(650ms, [this](TaskContext /*task*/)
                {
                     me->HandleEmoteCommand(EMOTE_ONESHOT_PARRY1H);
                });

                scheduler.Schedule(1s, [this](TaskContext /*task*/)
                {
                     DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);
                });

                break;
            }

            case ACTION_DESECRATING_SHOT_LAUNCH:
            {
                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                {
                    shadowCopy->NearTeleportTo(me->GetNearPosition(5.0f, float(M_PI)), false);

                    scheduler.Schedule(50ms, [shadowCopy](TaskContext /*task*/)
                    {
                         shadowCopy->NearTeleportTo(shadowCopy->GetPositionX(), shadowCopy->GetPositionY(), shadowCopy->GetPositionZ() + 5.0f, shadowCopy->GetOrientation(), false);
                    });

                    scheduler.Schedule(150ms, [this, shadowCopy](TaskContext /*task*/)
                    {
                         if (!_sayDesecratingOnCD)
                         {
                             _sayDesecratingOnCD = true;

                             Talk(SAY_DESECRATING_SHOT);
                         }

                         DoAction(ACTION_WINDRUNNER_MODEL);

                         me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                         shadowCopy->CastSpell(shadowCopy, SPELL_DESECRATING_SHOT_JUMP_FRONT, true);
                    });

                    scheduler.Schedule(450ms, [this, shadowCopy](TaskContext /*task*/)
                    {
                         shadowCopy->CastSpell(me->GetPosition(), SPELL_WINDRUNNER_MOVE, true);
                    });

                    scheduler.Schedule(650ms, [this](TaskContext /*task*/)
                    {
                         me->SetNameplateAttachToGUID(ObjectGuid::Empty);

                         me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
                    });
                }

                break;
            }

            case ACTION_PREPARE_INTERMISSION:
            {
                _specialEvents.CancelEventGroup(1);
                events.CancelEventGroup(1);

                _specialEvents.SetPhase(PHASE_INTERMISSION);
                events.SetPhase(PHASE_INTERMISSION);
                events.ScheduleEvent(EVENT_DOMINATION_CHAINS, 1s, PHASE_INTERMISSION);
                break;
            }

            case ACTION_PREPARE_PHASE_THREE:
            {
                DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                DoCastSelf(SPELL_BANSHEE_SHROUD, true);

                if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                {
                    if (jaina->IsAIEnabled())
                        jaina->AI()->DoAction(ACTION_OPEN_PORTAL_TO_PHASE_THREE);
                }

                break;
            }

            case ACTION_INITIATE_PHASE_THREE:
            {
                me->NearTeleportTo(SylvanasPhase3Pre, false);

                for (ObjectGuid const& guid : _shadowCopyGUID)
                {
                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, guid))
                        shadowCopy->NearTeleportTo(me->GetPosition(), false);
                }

                DoCastSelf(SPELL_RANGER_BOW_STANCE, true);
                break;
            }

            case ACTION_START_PHASE_THREE:
            {
                DoCastSelf(SPELL_RIVE_DISAPPEAR, true);

                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                {
                    me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                    shadowCopy->CastSpell(SylvanasPlaform1Pos, SPELL_DOMINATION_CHAINS_JUMP, true);

                    me->SendPlayOrphanSpellVisual(SylvanasPlaform1Pos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                }

                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    Talk(SAY_START_PHASE_THREE);
                });

                scheduler.Schedule(525ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(SylvanasPlaform1Pos, false);
                });

                scheduler.Schedule(1s, [this](TaskContext /*task*/)
                {
                    DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);

                    DoCastSelf(SPELL_DOMINATION_CHAINS_SPIN, true);

                    me->RemoveAura(SPELL_BANSHEE_SHROUD);
                });

                break;
            }

            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_RANGER_SHOT:
            {
                _lastSpellUsed = spell->Id;
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
                    if (_windrunnerActive)
                        return;

                    std::list<WorldObject*> everyPlayerButCurrentVictim;

                    if (WorldObject* currentTank = me->GetVictim())
                        everyPlayerButCurrentVictim.remove(currentTank);

                    for (auto itr = everyPlayerButCurrentVictim.begin(); itr != everyPlayerButCurrentVictim.end(); itr++)
                        Talk(SAY_ANNOUNCE_WAILING_ARROW, *itr);

                    if (Unit* currentTank = SelectTarget(SELECT_TARGET_MAXTHREAT, 0, 250.0f, true, true))
                    {
                        Talk(SAY_ANNOUNCE_WAILING_ARROW_TANK, currentTank);

                        me->CastSpell(currentTank, SPELL_WAILING_ARROW_POINTER, true);
                    }

                    scheduler.Schedule(4s, [this](TaskContext /*task*/)
                    {
                        if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                            DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                    });

                    events.ScheduleEvent(EVENT_WAILING_ARROW, 5s + 500ms, 1, PHASE_ONE);
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

                    for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                            shadowCopy->NearTeleportTo(me->GetPosition(), false);
                    }

                    _windrunnerActive = true;
                    _sayDaggersOnCD = false;
                    _sayDesecratingOnCD = false;

                    if (!me->HasAura(SPELL_RANGER_DAGGERS_STANCE))
                        DoCastSelf(SPELL_RANGER_DAGGERS_STANCE, false);

                    if (_windrunnerCastTimes == 0)
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 11000));

                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 1s + 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 2s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 6s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 7s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 7s + 500ms, 2, PHASE_ONE);

                        scheduler.Schedule(11s + 500ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else if (_windrunnerCastTimes == 1)
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 13000));

                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 2s + 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 3s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 7s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 8s, 2, PHASE_ONE);

                        scheduler.Schedule(13s + 500ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else if (_windrunnerCastTimes == 2)
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 15000));

                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 500ms, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 5s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOW_DAGGERS, 7s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_DESECRATING_SHOT, 9s, 2, PHASE_ONE);
                        events.ScheduleEvent(EVENT_WITHERING_FIRE, 13s, 2, PHASE_ONE);

                        scheduler.Schedule(15s + 500ms, [this](TaskContext /*task*/)
                        {
                            _windrunnerActive = false;
                        });
                    }
                    else
                    {
                        DoCastSelf(SPELL_WINDRUNNER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 17000));

                        scheduler.Schedule(17s + 500ms, [this](TaskContext /*task*/)
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
                    for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                            shadowCopy->NearTeleportTo(me->GetPosition(), false);
                    }

                    // Number of casts is dependent on raid's difficulty and size: if mythic, 15 casts; if not, half the raid (min. 5, max. 15)
                    uint8 castTimes = me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 15 :
                        std::max<uint8>(5, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 2));

                    for (uint8 itr = 0; itr < 3; itr++)
                    {
                        scheduler.Schedule(Milliseconds(100 * itr), [this, castTimes, itr](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[itr]))
                            {
                                Position const witheringCastPos = me->GetNearPosition(frand(30.0f, 40.0f), frand(0.0f, 3.5f));

                                if (itr == 1)
                                {
                                    DoAction(ACTION_WINDRUNNER_MODEL);

                                    me->SetNameplateAttachToGUID(_shadowCopyGUID[itr]);
                                }

                                scheduler.Schedule(50ms, [this, shadowCopy, witheringCastPos](TaskContext /*task*/)
                                {
                                    me->SendPlayOrphanSpellVisual(witheringCastPos, SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);

                                    shadowCopy->CastSpell(witheringCastPos, SPELL_WINDRUNNER_MOVE, true);
                                });

                                scheduler.Schedule(350ms, [this, shadowCopy](TaskContext /*task*/)
                                {
                                    shadowCopy->SetFacingToObject(me);
                                });

                                scheduler.Schedule(350ms, [this, shadowCopy](TaskContext /*task*/)
                                {
                                    shadowCopy->SetFacingToObject(me);
                                });

                                scheduler.Schedule(400ms, [shadowCopy](TaskContext /*task*/)
                                {
                                    shadowCopy->CastSpell(shadowCopy, SPELL_WITHERING_FIRE_COPY, true);
                                });

                                scheduler.Schedule(450ms, [this, shadowCopy, castTimes, itr](TaskContext /*task*/)
                                {
                                    std::list<Player*> targetList;
                                    GetPlayerListInGrid(targetList, me, 250.0f);

                                    if (itr == 1)
                                    {
                                        if (targetList.size() > castTimes - 3)
                                            Trinity::Containers::RandomResize(targetList, castTimes - 3);
                                    }
                                    else
                                    {
                                        if (targetList.size() > 1)
                                            Trinity::Containers::RandomResize(targetList, 1);
                                    }

                                    for (Player* target : targetList)
                                    {
                                        shadowCopy->SendPlaySpellVisual(target, SPELL_VISUAL_WITHERING_FIRE, 0, 0, 48.0f, false);

                                        uint32 timeToCast = shadowCopy->GetDistance(target) * 0.0208;

                                        scheduler.Schedule(Seconds(timeToCast), [this, target](TaskContext /*task*/)
                                        {
                                            me->CastSpell(target, SPELL_WITHERING_FIRE, true);
                                        });
                                    }
                                });

                                scheduler.Schedule(1s, [this, shadowCopy](TaskContext /*task*/)
                                {
                                    shadowCopy->SendPlayOrphanSpellVisual(me->GetPosition(), SPELL_VISUAL_WINDRUNNER_02, 0.25f, true, false);

                                    shadowCopy->CastSpell(me->GetPosition(), SPELL_WINDRUNNER_MOVE, true);
                                });

                                scheduler.Schedule(1s + 250ms, [this, shadowCopy, itr](TaskContext /*task*/)
                                {
                                    if (itr == 1)
                                        me->SetNameplateAttachToGUID(ObjectGuid::Empty);

                                    shadowCopy->SetOrientation(me->GetOrientation());
                                });
                            }
                        });
                    }

                    break;
                }

                case EVENT_SHADOW_DAGGERS:
                {
                    for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                            shadowCopy->NearTeleportTo(me->GetPosition(), false);
                    }

                    if (!_sayDaggersOnCD)
                    {
                        _sayDaggersOnCD = true;

                        Talk(SAY_SHADOW_DAGGER);
                    }

                    DoAction(ACTION_WINDRUNNER_MODEL);

                    for (uint8 i = 0; i < 4; i++)
                    {
                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[i]))
                        {
                            shadowCopy->NearTeleportTo(me->GetPosition(), false);

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250.0f, true, true))
                            {
                                Position targetPos = target->GetNearPosition(frand(1.5f, 2.5f), frand(0.0f, 6.0f));

                                me->SendPlayOrphanSpellVisual(targetPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                                if (i == 0)
                                    me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                                shadowCopy->CastSpell(targetPos, SPELL_WINDRUNNER_MOVE, true);

                                scheduler.Schedule(100ms, [shadowCopy, target](TaskContext /*task*/)
                                {
                                    shadowCopy->SetFacingToObject(target);
                                });

                                scheduler.Schedule(250ms, [this, shadowCopy, target](TaskContext /*task*/)
                                {
                                    shadowCopy->CastSpell(shadowCopy, SPELL_SHADOW_DAGGER_COPY, true);

                                    me->CastSpell(target, SPELL_SHADOW_DAGGER, true);
                                });

                                scheduler.Schedule(600ms, [this, shadowCopy](TaskContext /*task*/)
                                {
                                    shadowCopy->SendPlayOrphanSpellVisual(me->GetPosition(), SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                                    shadowCopy->CastSpell(me->GetPosition(), SPELL_WINDRUNNER_MOVE, true);
                                });

                                scheduler.Schedule(850ms, [this](TaskContext /*task*/)
                                {
                                    me->SetNameplateAttachToGUID(ObjectGuid::Empty);

                                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
                                });
                            }
                        }
                    }

                    break;
                }

                case EVENT_DESECRATING_SHOT:
                {
                    switch (urand(0, 1))
                    {
                        case DATA_DESECRATING_SHOT_PATTERN_STRAIGHT:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true, true))
                            {
                                float orientation = me->GetAbsoluteAngle(target);

                                int32 step = 1;

                                while (DrawDesecratingShotStraight(step, orientation))
                                    ++step;

                                scheduler.Schedule(2s + 750ms, [this](TaskContext /*task*/)
                                {
                                    DoAction(ACTION_DESECRATING_SHOT_LAUNCH);
                                });
                            }

                            break;
                        }

                        case DATA_DESECRATING_SHOT_PATTERN_SCATTERED:
                        {
                            DrawDesecratingShotScattered();

                            scheduler.Schedule(2s + 750ms, [this](TaskContext /*task*/)
                            {
                                DoAction(ACTION_DESECRATING_SHOT_LAUNCH);
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

                    DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                    if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    {
                        DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                        events.Repeat(1s + 750ms);
                    }
                    else
                    {
                        Position const jumpFirstPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));
                        Position const jumpSecondPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));
                        Position const jumpThirdPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(25.0f, 35.0f));

                        Talk(SAY_ANNOUNCE_DOMINATION_CHAINS);

                        if (events.GetPhaseMask() == PHASE_ONE)
                            Talk(SAY_DOMINATION_CHAINS);
                        else
                            Talk(SAY_INTERMISSION_BEGIN);

                        DoCastSelf(SPELL_DOMINATION_CHAINS_SPIN, true);

                        if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                        {
                            if (shadowCopy->IsAIEnabled())
                                shadowCopy->AI()->SetData(1, 2);

                            shadowCopy->NearTeleportTo(me->GetPosition(), false);
                        }

                        scheduler.Schedule(50ms, [this](TaskContext /*task*/)
                        {
                            DoCastSelf(SPELL_RIVE_DISAPPEAR, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3000));
                            DoCastSelf(SPELL_DOMINATION_CHAINS, false);

                            me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);
                        });

                        scheduler.Schedule(550ms, [this, jumpFirstPos](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                shadowCopy->CastSpell(jumpFirstPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                            me->SendPlayOrphanSpellVisual(jumpFirstPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                        });

                        scheduler.Schedule(1s + 285ms, [this, jumpFirstPos](TaskContext /*task*/)
                        {
                            me->NearTeleportTo(jumpFirstPos, true);

                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                me->SetFacingTo(shadowCopy->GetOrientation());
                        });

                        scheduler.Schedule(1s + 347ms, [this, jumpSecondPos](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                shadowCopy->CastSpell(jumpSecondPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                            me->SendPlayOrphanSpellVisual(jumpSecondPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                        });

                        scheduler.Schedule(2s + 97ms, [this, jumpSecondPos](TaskContext /*task*/)
                        {
                            me->NearTeleportTo(jumpSecondPos, true);

                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                me->SetFacingTo(shadowCopy->GetOrientation());
                        });

                        scheduler.Schedule(2s + 160ms, [this, jumpThirdPos](TaskContext /*task*/)
                        {
                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                shadowCopy->CastSpell(jumpThirdPos, SPELL_DOMINATION_CHAINS_JUMP, true);

                            me->SendPlayOrphanSpellVisual(jumpThirdPos, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);
                        });

                        scheduler.Schedule(2s + 720ms, [this, jumpThirdPos](TaskContext /*task*/)
                        {
                            me->NearTeleportTo(jumpThirdPos, true);

                            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                                me->SetFacingTo(shadowCopy->GetOrientation());
                        });

                        scheduler.Schedule(2s + 800ms, [this](TaskContext /*task*/)
                        {
                            for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                            {
                                if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                                    shadowCopy->NearTeleportTo(me->GetPosition(), false);
                            }

                            me->SetNameplateAttachToGUID(ObjectGuid::Empty);

                            me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_SHADOW_DAGGER, 0, 0);
                        });

                        scheduler.Schedule(9s + 500ms, [this](TaskContext /*task*/)
                        {
                            if (events.GetPhaseMask() == PHASE_ONE)
                            {
                                DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);

                                for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                                {
                                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                                    {
                                        shadowCopy->NearTeleportTo(me->GetPosition(), false);

                                        if (shadowCopy->IsAIEnabled())
                                            shadowCopy->AI()->SetData(1, 1);
                                    }
                                }

                                if (events.GetTimeUntilEvent(EVENT_VEIL_OF_DARKNESS) <= 2500)
                                    events.RescheduleEvent(EVENT_VEIL_OF_DARKNESS, 3s, 1, PHASE_ONE);
                            }
                            else
                            {
                                for (ObjectGuid const& copiesGUID : _shadowCopyGUID)
                                {
                                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, copiesGUID))
                                    {
                                        shadowCopy->NearTeleportTo(me->GetPosition(), false);

                                        if (shadowCopy->IsAIEnabled())
                                            shadowCopy->AI()->SetData(1, 3);
                                    }
                                }

                                events.ScheduleEvent(EVENT_RIVE, 1s, PHASE_INTERMISSION);
                            }
                        });

                        if (events.GetPhaseMask() == PHASE_ONE)
                            events.Repeat(54s);
                    }

                    break;
                }

                case EVENT_WAILING_ARROW:
                {
                    Talk(SAY_WAILING_ARROW);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250.0f, true, true, SPELL_WAILING_ARROW_POINTER))
                        me->CastSpell(target, SPELL_WAILING_ARROW, false);

                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_CHARGE, 0, 0);

                    scheduler.Schedule(1s + 300ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_JUMP, 0, 0);
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_WAILING_ARROW_EFFECT, 0, 0);
                    });

                    scheduler.Schedule(3s + 500ms, [this](TaskContext /*task*/)
                    {
                        DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);

                        _specialEvents.ScheduleEvent(EVENT_WAILING_ARROW_MARKER, 33s, PHASE_ONE);
                    });

                    break;
                }

                case EVENT_VEIL_OF_DARKNESS:
                {
                    if (_windrunnerActive)
                        return;

                    DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                    if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    {
                        DoCastSelf(SPELL_RANGER_BOW_STANCE, false);

                        events.Repeat(1s + 750ms);
                    }
                    else
                    {
                        me->SetPower(me->GetPowerType(), 0);

                        Talk(SAY_ANNOUNCE_VEIL_OF_DARKNESS);
                        Talk(SAY_VEIL_OF_DARKNESS);

                        scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                        {
                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1_FADE, true);
                            me->NearTeleportTo(SylvanasVeilOfDarknessPos, false);
                        });

                        scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true, true))
                                me->NearTeleportTo(target->GetPosition(), false);

                            DoCastSelf(SPELL_VEIL_OF_DARKNESS_PHASE_1, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 4000));
                        });

                        scheduler.Schedule(9s, [this](TaskContext /*task*/)
                        {
                            DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);
                        });

                        events.Repeat(48s);
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
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250.0f, true, true))
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
                                    shadowCopy->AI()->SetData(1, 4);
                            }
                        }

                        events.ScheduleEvent(EVENT_FINISH_INTERMISSION, 1s + 500ms, PHASE_INTERMISSION);
                    }

                    break;
                }

                case EVENT_FINISH_INTERMISSION:
                {
                    DoCastSelf(SPELL_RIVE_DISAPPEAR, true);

                    me->SendPlayOrphanSpellVisual(RiveFinish, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                    me->SetNameplateAttachToGUID(_shadowCopyGUID[0]);

                    if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, _shadowCopyGUID[0]))
                        shadowCopy->CastSpell(RiveFinish, SPELL_DOMINATION_CHAINS_JUMP, true);

                    scheduler.Schedule(600ms, [this](TaskContext /*task*/)
                    {
                        me->NearTeleportTo(RiveFinish, false);

                        me->SetNameplateAttachToGUID(ObjectGuid::Empty);
                    });

                    scheduler.Schedule(1s + 100ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN, 0, 0);
                    });

                    scheduler.Schedule(1s + 700ms, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_INTERMISSION_END);
                    });

                    scheduler.Schedule(2s + 400ms, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_BANSHEE_WAIL, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));
                    });

                    scheduler.Schedule(6s + 400ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TRANSFORM_INTO_BANSHEE, 0, 0);
                    });

                    scheduler.Schedule(9s + 400ms, [this](TaskContext /*task*/)
                    {
                        me->SendPlayOrphanSpellVisual(SylvanasPhase2Pre, SPELL_VISUAL_WINDRUNNER_01, 0.5f, true, false);

                        me->NearTeleportTo(SylvanasPhase2Pre, false);
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
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_WINDRUNNER) || IsAnyEventIncoming())
            return;

        Unit* victim = me->GetVictim();

        Aura* rangerHeartseekerCharge = me->GetAura(SPELL_RANGER_HEARTSEEKER_CHARGE);

        if (rangerHeartseekerCharge && rangerHeartseekerCharge->GetStackAmount() >= 3)
        {
            if (me->isAttackReady(RANGED_ATTACK))
            {
                if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                {
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                    me->resetAttackTimer(RANGED_ATTACK);
                }
                else
                {
                    DoCastVictim(SPELL_RANGER_HEARTSEEKER, false);
                    me->resetAttackTimer(RANGED_ATTACK);
                }
            }
        }
        else
        {
            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                if (me->isAttackReady(RANGED_ATTACK))
                {
                    if (!me->HasAura(SPELL_RANGER_BOW_STANCE))
                    {
                        DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                        me->resetAttackTimer(RANGED_ATTACK);
                    }
                    else
                    {
                        DoCastVictim(SPELL_RANGER_SHOT, false);
                        me->resetAttackTimer(RANGED_ATTACK);
                    }
                }

            }
            else
            {
                if (me->isAttackReady(BASE_ATTACK))
                {
                    if (!me->HasAura(SPELL_RANGER_DAGGERS_STANCE))
                    {
                        DoCastSelf(SPELL_RANGER_DAGGERS_STANCE, false);
                        me->resetAttackTimer(BASE_ATTACK);
                    }
                    else
                    {
                        DoSpellAttackIfReady(SPELL_RANGER_STRIKE);
                        me->resetAttackTimer(BASE_ATTACK);

                        if (me->isAttackReady(OFF_ATTACK))
                        {
                            me->AttackerStateUpdate(victim, OFF_ATTACK);
                            me->resetAttackTimer(OFF_ATTACK);
                        }
                    }
                }
            }
        }
    }

    bool DrawDesecratingShotStraight(int32 step, float orientation)
    {
        float distance = 7.0f * step;

        // Let's obtain the arrow's center so we can stop summoning arrows if it goes beyond the boundaries of the platform
        Position arrowCenter(me->GetPositionX() + (std::cos(orientation) * distance), me->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

        if (!SylvanasFirstPhasePlatformCenter.IsInDist2d(&arrowCenter, PLATFORM_RADIUS))
            return false;

        scheduler.Schedule(Milliseconds(step * 10), [this, arrowCenter](TaskContext /*task*/)
        {
            me->CastSpell(arrowCenter, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
        });

        Position arrowInnerLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());
        Position arrowInnerRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 2.8284f), arrowCenter.GetPositionZ());

        scheduler.Schedule(Milliseconds(step * 10 + 50), [this, arrowInnerLeft, arrowInnerRight](TaskContext /*task*/)
        {
            me->CastSpell(arrowInnerLeft, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
            me->CastSpell(arrowInnerRight, SPELL_DESECRATING_SHOT_AREATRIGGER, true);
        });

        Position arrowOuterLeft(arrowCenter.GetPositionX() + (std::cos(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + 135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());
        Position arrowOuterRight(arrowCenter.GetPositionX() + (std::cos(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionY() + (std::sin(orientation + -135.0f * M_PI / 180) * 5.6568f), arrowCenter.GetPositionZ());

        scheduler.Schedule(Milliseconds(step * 10 + 75), [this, arrowOuterLeft, arrowOuterRight](TaskContext /*task*/)
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

    bool DrawDesecratingShowWaveSecond(int32 step, Position pos, float orientation)
    {

        return true;
    }

    void DrawDesecratingShotScattered()
    {
        for (uint8 i = 0; i < 8; i++)
        {
            for (uint8 i = 0; i < 2; i++)
            {
                scheduler.Schedule(250ms, [this](TaskContext /*task*/)
                {
                    me->CastSpell(me->GetRandomPoint(me->GetPosition(), frand(0.0f, 40.0f)), SPELL_DESECRATING_SHOT_AREATRIGGER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3000));
                });
            }
        }

        for (uint8 desecratingShotOnPlayer = std::max<uint8>(4, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 3)) / 3.0f; desecratingShotOnPlayer > 0; desecratingShotOnPlayer--)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true, true))
            {
                for (uint8 i = 0; i < 2; i++)
                {
                    scheduler.Schedule(250ms, [this, target](TaskContext /*task*/)
                    {
                        me->CastSpell(target->GetRandomPoint(target->GetPosition(), frand(1.0f, 2.5f)), SPELL_DESECRATING_SHOT_AREATRIGGER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3000));
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

    ObjectGuid GetShadowCopyJumperGuid(int32 index)
    {
        return _shadowCopyGUID[index];
    }

    bool IsAnyEventIncoming()
    {
        // Let's avoid cases where Sylvanas could launch any spell just after launching any of the main events
        if (events.GetTimeUntilEvent(EVENT_WINDRUNNER) <= 1000)
            return true;

        if (events.GetTimeUntilEvent(EVENT_DOMINATION_CHAINS) <= 1000)
            return true;

        if (events.GetTimeUntilEvent(EVENT_WAILING_ARROW) <= 1000)
            return true;

        if (events.GetTimeUntilEvent(EVENT_VEIL_OF_DARKNESS) <= 1000)
            return true;

        return false;
    }

private:
    EventMap _specialEvents;
    std::vector<ObjectGuid> _shadowCopyGUID;
    bool _windrunnerActive;
    bool _sayDaggersOnCD;
    bool _sayDesecratingOnCD;
    uint32 _lastSpellUsed;
    uint8 _windrunnerCastTimes;
    uint8 _riveCastTimes;
};

// Sylvanas (Copy Fight) - 176369
struct npc_sylvanas_windrunner_sylvanas : public ScriptedAI
{
    npc_sylvanas_windrunner_sylvanas(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()),
        _onPhaseOne(true), _onChainsOfDomination(false), _onRiveEvent(false) { }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == 1)
        {
            switch (value)
            {
                case 1:
                {
                    _onPhaseOne = true;
                    _onChainsOfDomination = false;
                    _onRiveEvent = false;
                    break;
                }

                case 2:
                {
                    _onPhaseOne = false;
                    _onChainsOfDomination = true;
                    _onRiveEvent = false;
                    break;
                }

                case 3:
                {
                    _onPhaseOne = false;
                    _onChainsOfDomination = false;
                    _onRiveEvent = true;
                    break;
                }

                case 4:
                {
                    _onPhaseOne = false;
                    _onChainsOfDomination = false;
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

                if (_onChainsOfDomination)
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

                                me->SendPlaySpellVisual(falseArrowPos, 0.0f, SPELL_VISUAL_DOMINATION_ARROW, 0, 0, 2.5f, true);

                                _scheduler.Schedule(2s + 500ms, [sylvanas, falseArrowPos](TaskContext /*task*/)
                                {
                                    sylvanas->CastSpell(falseArrowPos, SPELL_DOMINATION_ARROW_FALL, true);
                                });
                            }

                            // Number of arrows spawned is dependent on raid's difficulty and size: min. 4, max. 10
                            for (uint8 arrowsToSpawn = std::max<uint8>(4, std::ceil(float(me->GetMap()->GetPlayersCountExceptGMs()) / 3)) / 3.0f; arrowsToSpawn > 0; arrowsToSpawn--)
                            {
                                Position const arrowPos = me->GetRandomPoint(SylvanasFirstPhasePlatformCenter, frand(2.5f, 40.0f));

                                if (Creature* dominationArrow = sylvanas->SummonCreature(NPC_DOMINATION_ARROW, arrowPos, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    me->SendPlaySpellVisual(dominationArrow, SPELL_VISUAL_DOMINATION_ARROW_SPAWN, 0, 0, 2.5f, true);

                                    _scheduler.Schedule(2s + 500ms, [sylvanas, dominationArrow](TaskContext /*task*/)
                                    {
                                        sylvanas->CastSpell(dominationArrow, SPELL_DOMINATION_ARROW_FALL_AND_VISUAL, true);
                                    });
                                }
                            }
                        }
                    });
                }

                if (_onRiveEvent)
                    DoCastSelf(SPELL_ANCHOR_HERE, true);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    bool _onPhaseOne;
    bool _onChainsOfDomination;
    bool _onRiveEvent;
};

// Domination Arrow - 176920
struct npc_sylvanas_windrunner_domination_arrow : public ScriptedAI
{
    npc_sylvanas_windrunner_domination_arrow(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoZoneInCombat();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_DOMINATION_ARROW:
            {
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                    DoCastSelf(SPELL_DOMINATION_ARROW_CALAMITY_AREA, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, -1));

                if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 250.0f, true, true, -SPELL_DOMINATION_CHAIN_PLAYER))
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

enum BolvarSpells
{
    SPELL_RUNIC_MARK                            = 354926,
    SPELL_GLYPH_OF_DESINTEGRATION               = 354932,
    SPELL_WINDS_OF_ICECROWN                     = 356941,
    SPELL_WINDS_OF_ICECROWN_INTERRUPT           = 356986,
};

enum Bolvarvents
{

};

enum BolvarActions
{

};

enum BolvarTexts
{
    SAY_PREPARE_PHASE_THREE                     = 12
};

Position const BolvarPrePhaseThreePos = { -249.54861f, -1278.5382f, 5667.1157f, 1.5865f };

// Highlord Bolvar Fordragon - 178081
struct npc_sylvanas_windrunner_bolvar : public ScriptedAI
{
    npc_sylvanas_windrunner_bolvar(Creature* creature) : ScriptedAI(creature, DATA_BOLVAR_FORDRAGON_PINNACLE),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
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

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.SetPhase(PHASE_ONE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PAUSE_ATTACK_FOR_EVENT:
            {
                me->InterruptNonMeleeSpells(true);
                me->GetMotionMaster()->Clear();
                me->StopMoving();

                me->SetReactState(REACT_PASSIVE);
                break;
            }

            case ACTION_ACTIVATE_ATTACK_FOR_EVENT:
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    AttackStart(sylvanas);

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

        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
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
    SPELL_FLAMEAXE                              = 354898,
    SPELL_PULVERIZE                             = 354918
};

enum ThrallEvents
{

};

enum ThrallActions
{

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
        _events.SetPhase(PHASE_ONE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PAUSE_ATTACK_FOR_EVENT:
            {
                me->InterruptNonMeleeSpells(true);
                me->GetMotionMaster()->Clear();
                me->StopMoving();

                me->SetReactState(REACT_PASSIVE);
                break;
            }

            case ACTION_ACTIVATE_ATTACK_FOR_EVENT:
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    AttackStart(sylvanas);
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

        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

enum JainaSpells
{
    SPELL_ICE_BOLT                              = 350002,
    SPELL_COMET_BARRAGE                         = 354938,
    SPELL_COMET_BARRAGE_MISSILE                 = 354936,
    SPELL_FRIGID_SHARDS                         = 354933,
    SPELL_FRIGID_SHARDS_MISSILE                 = 354934,
    SPELL_CONE_OF_COLD                          = 350003,
    SPELL_SEARING_BLAST                         = 355507,

    SPELL_PORTAL_TO_ORIBOS_PHASE_3              = 357102,
    SPELL_TELEPORT_TO_PHASE_3                   = 350906,
    SPELL_TELEPORT_TO_PHASE_3_RANDOM_POSITION   = 357103,
    SPELL_TELEPORT_TO_PHASE_3_MISSILE           = 357101,
    SPELL_FROZEN_SHELL                          = 351762,
    SPELL_BLASPHEMY_STUN                        = 357728
};

enum JainaEvents
{
    EVENT_FRIGID_SHARDS                         = 1,
    EVENT_CONE_OF_COLD,
    EVENT_COMET_BARRAGE
};

enum JainaActions
{

};

enum JainaTexts
{
    SAY_PREPARING_PORTAL_TO_PHASE_THREE         = 9,
    SAY_FINISHING_PORTAL_TO_PHASE_THREE,
    SAY_FINISHED_PORTAL_TO_PHASE_THREE,
    SAY_FREED_PLAYERS_ON_PHASE_THREE
};

enum JainaVisuals
{
    SPELL_VISUAL_KIT_JAINA_BREAK_BLASPHEMY            = 149324,
    SPELL_VISUAL_KIT_JAINA_TELEPORT_PLAYERS           = 149323,
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
        _events.SetPhase(PHASE_THREE);
        _events.ScheduleEvent(EVENT_FRIGID_SHARDS, 5s, 1, PHASE_THREE);
        _events.ScheduleEvent(EVENT_CONE_OF_COLD, 8s, 1, PHASE_THREE);
        _events.ScheduleEvent(EVENT_COMET_BARRAGE, 14s, 1, PHASE_THREE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PAUSE_ATTACK_FOR_EVENT:
            {
                me->InterruptNonMeleeSpells(true);
                me->GetMotionMaster()->Clear();
                me->StopMoving();

                me->SetReactState(REACT_PASSIVE);
                break;
            }

            case ACTION_ACTIVATE_ATTACK_FOR_EVENT:
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    AttackStart(sylvanas);
                break;
            }

            case ACTION_OPEN_PORTAL_TO_PHASE_THREE:
            {
                DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                {
                    if (bolvar->IsAIEnabled())
                        bolvar->AI()->DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);
                }

                if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                {
                    if (thrall->IsAIEnabled())
                        thrall->AI()->DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);
                }

                me->setActive(true);

                Talk(SAY_PREPARING_PORTAL_TO_PHASE_THREE);

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 200.0f);

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
                });

                _scheduler.Schedule(12s + 250ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(JainaPrePhaseThreePos, false);

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->NearTeleportTo(BolvarPrePhaseThreePos, false);

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->NearTeleportTo(ThrallPrePhaseThreePos, false);
                });

                _scheduler.Schedule(12s + 500ms, [this, playerList](TaskContext /*task*/)
                {
                    for (auto i = playerList.begin(); i != playerList.end(); i++)
                        (*i)->NearTeleportTo(me->GetNearPosition(frand(1.5f, 2.5f), frand(1.5f, 2.5f)), false);
                });

                _scheduler.Schedule(13s, [this, playerList](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_ANCHOR_HERE, true);

                    for (auto i = playerList.begin(); i != playerList.end(); i++)
                        (*i)->CastSpell(me, SPELL_TELEPORT_TO_PHASE_3, true);
                });

                _scheduler.Schedule(13s + 200ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_CHAMPIONS_MOD_FACTION, true);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                    {
                        if (anduin->IsAIEnabled())
                            anduin->AI()->DoAction(ACTION_INITIATE_PHASE_THREE);
                    }
                });

                _scheduler.Schedule(14s, [this](TaskContext /*task*/)
                {
                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        if (bolvar->IsAIEnabled())
                            bolvar->AI()->Talk(SAY_PREPARE_PHASE_THREE);
                    }
                });

                _scheduler.Schedule(17s + 950ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_FROZEN_SHELL, false);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                        anduin->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);
                });

                _scheduler.Schedule(19s, [this](TaskContext /*task*/)
                {
                    me->RemoveAura(SPELL_BLASPHEMY_STUN);
                });

                _scheduler.Schedule(19s + 200ms, [this](TaskContext /*task*/)
                {
                    me->CastStop();
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_JAINA_BREAK_BLASPHEMY, 0, 0);
                });

                _scheduler.Schedule(19s + 950ms, [this](TaskContext /*task*/)
                {
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_JAINA_TELEPORT_PLAYERS, 0, 0);
                });

                _scheduler.Schedule(21s + 122ms, [this](TaskContext /*task*/)
                {
                    Talk(SAY_FREED_PLAYERS_ON_PHASE_THREE);
                });

                _scheduler.Schedule(22s + 122ms, [this, playerList](TaskContext /*task*/)  // CHANGE
                {
                    for (auto i = playerList.begin(); i != playerList.end(); i++)
                    {
                        (*i)->CastSpell(PlaformsMiddlePos[0].GetPositionWithOffset(frand(2.0f, 8.0f)), SPELL_TELEPORT_TO_PHASE_3, true);
                        (*i)->RemoveAura(SPELL_BLASPHEMY_STUN);
                    }

                    if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        bolvar->RemoveAura(SPELL_BLASPHEMY_STUN);

                    if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        thrall->RemoveAura(SPELL_BLASPHEMY_STUN);
                });

                _scheduler.Schedule(23s, [this, playerList](TaskContext /*task*/)
                {
                    DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);

                    if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_CRUCIBLE))
                    {
                        AttackStart(anduin);

                        me->CastSpell(anduin, SPELL_SEARING_BLAST, false);

                        if (Creature* thrall = _instance->GetCreature(DATA_THRALL_PINNACLE))
                        {
                            if (thrall->IsAIEnabled())
                            {
                                thrall->AI()->DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);
                                thrall->AI()->AttackStart(anduin);
                            }
                        }

                        if (Creature* bolvar = _instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        {
                            if (bolvar->IsAIEnabled())
                            {
                                bolvar->AI()->DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);
                                bolvar->AI()->AttackStart(anduin);
                            }
                        }
                    }
                });

                _scheduler.Schedule(24s + 522ms, [this, playerList](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->DoAction(ACTION_START_PHASE_THREE);
                    }

                    for (auto i = playerList.begin(); i != playerList.end(); i++)
                        (*i)->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_PLAYER_ACTIVATE_FIELDS, 0, 0);
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

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// Frigid Shards - 354933
class spell_sylvanas_windrunner_frigid_shards : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_frigid_shards);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FRIGID_SHARDS_MISSILE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetCaster()->GetVictim(), SPELL_FRIGID_SHARDS_MISSILE, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COMET_BARRAGE_MISSILE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_COMET_BARRAGE_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_comet_barrage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum AnduinSpells
{
    SPELL_BLASPHEMY_PRE                         = 357729,
    SPELL_BLASPHEMY                             = 357730,
    SPELL_BLASPHEMY_DAMAGE                      = 357731,
    SPELL_CRIPPLING_DEFEAT                      = 354176,

    SPELL_BREAK_PLAYER_TARGETTING               = 140562,
};

enum AnduinEvents
{
    EVENT_BLASPHEMY                             = 1,
    EVENT_LIGHT_BLAST                           = 2,
    EVENT_CRIPPLING_DEFEAT                      = 3
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

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.SetPhase(PHASE_THREE);

        _events.ScheduleEvent(EVENT_LIGHT_BLAST, 8s, 12s, PHASE_THREE);
        _events.ScheduleEvent(EVENT_BLASPHEMY, 18s, 20s, PHASE_THREE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PAUSE_ATTACK_FOR_EVENT:
            {
                me->InterruptNonMeleeSpells(true);
                me->GetMotionMaster()->Clear();
                me->StopMoving();

                me->SetReactState(REACT_PASSIVE);
                break;
            }

            case ACTION_ACTIVATE_ATTACK_FOR_EVENT:
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Creature* jaina = _instance->GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                    AttackStart(jaina);

                break;
            }

            case ACTION_INITIATE_PHASE_THREE:
            {
                DoAction(ACTION_PAUSE_ATTACK_FOR_EVENT);

                DoCastSelf(SPELL_BLASPHEMY_PRE, false);

                _scheduler.Schedule(12s, [this](TaskContext /*task*/)
                {
                    DoAction(ACTION_ACTIVATE_ATTACK_FOR_EVENT);

                    DoCastSelf(SPELL_BREAK_PLAYER_TARGETTING, true);
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

class BlasphemyEvent : public BasicEvent
{
    public:
        BlasphemyEvent(Unit* owner, Position const blasphemyDestPos) : _owner(owner), _blasphemyDestPos(blasphemyDestPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_blasphemyDestPos, SPELL_BLASPHEMY_DAMAGE, true);
            return true;
        }

    private:
        Unit* _owner;
        Position _blasphemyDestPos;
};

// Blasphemy - 357729 
class spell_sylvanas_windrunner_blasphemy_pre : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_blasphemy_pre);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);

        for (uint8 i = 0; i < 20; i++)
        {
            Position const blasphemyDestPos = GetCaster()->GetRandomPoint(GetCaster()->GetPosition(), frand(5.0f, 40.0f));

            GetCaster()->SendPlaySpellVisual(blasphemyDestPos, 0.0f, SPELL_VISUAL_BLASPHEMY, 0, 0, 1.0f, true);

            GetCaster()->m_Events.AddEvent(new BlasphemyEvent(GetCaster(), blasphemyDestPos), GetCaster()->m_Events.CalculateTime(1000));
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_blasphemy_pre::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Blasphemy - 357730  
class spell_sylvanas_windrunner_blasphemy : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_blasphemy);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_ANDUIN_FINISH_BLASPHEMY, 0, 0);

        for (uint8 i = 0; i < 20; i++)
        {
            Position const blasphemyDestPos = GetCaster()->GetRandomPoint(GetCaster()->GetPosition(), frand(5.0f, 40.0f));

            GetCaster()->SendPlaySpellVisual(blasphemyDestPos, 0.0f, SPELL_VISUAL_BLASPHEMY, 0, 0, 1.0f, true);

            GetCaster()->m_Events.AddEvent(new BlasphemyEvent(GetCaster(), blasphemyDestPos), GetCaster()->m_Events.CalculateTime(1000));
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_blasphemy::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Ranger (Bow) - 347560 
class spell_sylvanas_windrunner_ranger_bow : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_bow);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->HasAura(SPELL_RANGER_DAGGERS_STANCE))
            GetCaster()->RemoveAura(SPELL_RANGER_DAGGERS_STANCE);

        if (urand(0, 1))
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW, 0, 0);
        else
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_BOW_SPIN, 0, 0);

        GetCaster()->SetSheath(SheathState::SHEATH_STATE_RANGED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_bow::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// Ranger (Dagger) - 348010
class spell_sylvanas_windrunner_ranger_dagger : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_dagger);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->HasAura(SPELL_RANGER_BOW_STANCE))
            GetCaster()->RemoveAura(SPELL_RANGER_BOW_STANCE);

        if (GetCaster()->HasAura(SPELL_RANGER_SHOT))
            GetCaster()->RemoveAura(SPELL_RANGER_SHOT);

        if (urand(0, 1))
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS, 0, 0);
        else
            GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_UNSHEATHE_DAGGERS_SPIN, 0, 0);

        GetCaster()->SetSheath(SheathState::SHEATH_STATE_MELEE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_dagger::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// Ranger Strike - 348299
class spell_sylvanas_windrunner_ranger_strike : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_ranger_strike);

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        switch (urand(0, 3))
        {
            case DATA_RANGER_STRIKE_01:
            {
                GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_01, 0, 0, 1.0f, true);
                break;
            }

            case DATA_RANGER_STRIKE_02:
            {
                GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_02, 0, 0, 1.0f, true);
                break;
            }

            case DATA_RANGER_STRIKE_03:
            {
                GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_03, 0, 0, 1.0f, true);
                break;
            }

            case DATA_RANGER_STRIKE_04:
            {
                GetCaster()->SendPlaySpellVisual(GetCaster()->GetVictim(), SPELL_VISUAL_RANGER_STRIKE_04, 0, 0, 1.0f, true);
                break;
            }

            default:
                break;
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_ranger_strike::OnCast);
    }
};

// Withering Fire - 347928
class spell_sylvanas_windrunner_withering_fire : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_withering_fire);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BARBED_ARROW });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                sylvanas->CastSpell(GetHitUnit(), SPELL_BARBED_ARROW, true);
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

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DESECRATING_SHOT_DAMAGE, true);
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
class spell_sylvanas_windrunner_ranger_heartseeker : public AuraScript
{
    PrepareAuraScript(spell_sylvanas_windrunner_ranger_heartseeker);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(0));
        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(281));
        GetCaster()->m_Events.AddEvent(new RangerHeartseekerMissileEvent(GetCaster(), GetCaster()->GetVictim()), GetCaster()->m_Events.CalculateTime(562));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_ranger_heartseeker::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Ranger's Heartseeker (Shadow damage) - 352652
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
            arrow->CastSpell(arrow, SPELL_DOMINATION_ARROW_ACTIVATE, true);

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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINATION_ARROW_DAMAGE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DOMINATION_ARROW_DAMAGE, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WAILING_ARROW_MISSILE });
    }

    void OnCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WAILING_ARROW_MISSILE, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WAILING_ARROW_TARGET_DAMAGE,
            SPELL_WAILING_ARROW_AOE_DAMAGE
        });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (effIndex == 0)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WAILING_ARROW_TARGET_DAMAGE, true);

        if (effIndex == 1)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WAILING_ARROW_AOE_DAMAGE, true);
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
            SPELL_VEIL_OF_DARKNESS_DESELECT,
            SPELL_VEIL_OF_DARKNESS_SCREEN_FOG
        });
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        GetCaster()->GetInstanceScript()->DoCastSpellOnPlayers(SPELL_VEIL_OF_DARKNESS_SCREEN_FOG);
        GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_DARKNESS_DESELECT, true);

        GetCaster()->SetDisableGravity(true);
        GetCaster()->SetCanFly(true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW,
            SPELL_VEIL_OF_DARKNESS_ABSORB_AURA,
            SPELL_VEIL_OF_DARKNESS_DAMAGE
        });
    }

    bool Load() override
    {
        GetCaster()->SetPlayHoverAnim(true);
        GetCaster()->SetDisableGravity(false);
        GetCaster()->SetCanFly(false);

        GetCaster()->SetDisplayId(DISPLAYID_SYLVANAS_BANSHEE_MODEL);

        GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));

        GetCaster()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_VEIL_OF_DARKNESS, 0, 0);

        // TODO: find out why this OrphanSpellVisual is smaller than Blizzlike (the size is dependent on the sender's scale), it's 6 yards shorter than expected
        if (Creature* ridingCopy = GetCaster()->FindNearestCreature(NPC_SYLVANAS_SHADOW_COPY_RIDING, 20.0f, true))
        {
            ridingCopy->CastSpell(ridingCopy, SPELL_VEIL_OF_DARKNESS_PHASE_1_GROW, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));
            ridingCopy->SendPlaySpellVisualKit(147440, 0, 0);
            // ridingCopy->SendPlayOrphanSpellVisual(ridingCopy->GetGUID(), SPELL_VISUAL_VEIL_OF_DARKNESS_PHASE_01, 5.0f, true);
        }

        return true;
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (effIndex == 0)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_VEIL_OF_DARKNESS_ABSORB_AURA, true);

        if (effIndex == 1)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_VEIL_OF_DARKNESS_DAMAGE, true);
    }

    void HandleAfterCast()
    {
        GetCaster()->SetPlayHoverAnim(false);
        GetCaster()->SetDisplayId(DISPLAYID_SYLVANAS_ELF_MODEL);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RIVE_CHAIN,
            SPELL_RIVE_AREATRIGGER
        });
    }

    bool Load() override
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

        return true;
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
                        sylvanas->CastSpell(shadowCopy->GetPosition(), SPELL_RIVE_AREATRIGGER, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RIVE_CHAIN_FAST,
            SPELL_RIVE_AREATRIGGER
        });
    }

    bool Load() override
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

        return true;
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
                        sylvanas->CastSpell(shadowCopy->GetPosition(), SPELL_RIVE_AREATRIGGER, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_BANSHEE_WAIL_MARKER,
            SPELL_BANSHEE_FORM,
            SPELL_BANSHEE_SHROUD,
            SPELL_SYLVANAS_ROOT,
            SPELL_BANSHEE_WAIL_MISSILE
         });
    }

    bool Load() override
    {
        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 250.0f);

        for (auto itr = targetList.begin(); itr != targetList.end(); itr++)
            GetCaster()->CastSpell(*itr, SPELL_BANSHEE_WAIL_MARKER, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 4650));

        return true;
    }

    void HandleAfterCast()
    {
        // HACKFIX: SPELL_AURA_TRIGGER_SPELL_ON_EXPIRE is not implemented, this is a workaround
        GetCaster()->CastSpell(GetCaster(), SPELL_BANSHEE_FORM, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_BANSHEE_SHROUD, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_SYLVANAS_ROOT, true);

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 200.0f);

        for (auto itr = targetList.begin(); itr != targetList.end(); itr++)
            GetCaster()->CastSpell(*itr, SPELL_BANSHEE_WAIL_MISSILE, true);
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

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_BANSHEE_WAIL_DAMAGE,
            SPELL_BANSHEE_WAIL_INTERRUPT
        });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (effIndex == 0)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_WAIL_DAMAGE, true);

        if (effIndex == 1)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_BANSHEE_WAIL_INTERRUPT, true);
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

// Teleport (Master - To Phase 3) - 350906
// TODO: find out what Entry the spell looks for TARGET_DEST_NEARBY_ENTRY
class spell_sylvanas_windrunner_teleport_to_phase_3_master : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_teleport_to_phase_3_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_TO_PHASE_3_RANDOM_POSITION });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_TELEPORT_TO_PHASE_3_RANDOM_POSITION, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_3_master::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Teleport (Random Position) - 357103
class spell_sylvanas_windrunner_teleport_to_phase_3_random_position : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_teleport_to_phase_3_random_position);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_TO_PHASE_3_MISSILE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_TELEPORT_TO_PHASE_3_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_teleport_to_phase_3_random_position::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
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

        if (_updateDiff >= 3150)
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
            if (boss_sylvanas_windrunner* ai = CAST_AI(boss_sylvanas_windrunner, sylvanas->AI()))
            {
                for (uint8 i = 0; i < 5; i++)
                {
                    Position const debrisPos = at->GetRandomNearPosition(30.0f);

                    at->SendPlayOrphanSpellVisual(debrisPos, SPELL_VISUAL_RIVEN_DEBRIS, 1.50f, true, false);

                    sylvanas->m_Events.AddEvent(new DebrisEvent(sylvanas, debrisPos), sylvanas->m_Events.CalculateTime(1500));
                }
            }

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

void AddSC_boss_sylvanas_windrunner()
{
    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_sylvanas);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_domination_arrow);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_bolvar);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_jaina);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_thrall);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_anduin);

    RegisterSpellScript(spell_sylvanas_windrunner_ranger_bow);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_dagger);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_strike);
    RegisterSpellScript(spell_sylvanas_windrunner_withering_fire);
    RegisterSpellScript(spell_sylvanas_windrunner_desecrating_shot);
    RegisterAuraScript(spell_sylvanas_windrunner_ranger_heartseeker);
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

    RegisterAuraScript(spell_sylvanas_windrunner_frigid_shards);
    RegisterSpellScript(spell_sylvanas_windrunner_comet_barrage);
    RegisterSpellScript(spell_sylvanas_windrunner_winds_of_icecrown);

    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_3_master);
    RegisterSpellScript(spell_sylvanas_windrunner_teleport_to_phase_3_random_position);
    RegisterAuraScript(spell_sylvanas_windrunner_blasphemy_pre);
    RegisterAuraScript(spell_sylvanas_windrunner_blasphemy);

    RegisterAuraScript(spell_sylvanas_windrunner_energize_power_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_phase_intermission);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_finish_boss);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_disecrating_shot);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_rive);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_blasphemy_pre);
}
