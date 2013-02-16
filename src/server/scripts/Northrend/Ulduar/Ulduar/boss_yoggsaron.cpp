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

#include "ScriptMgr.h"
#include "ulduar.h"
#include <limits>

enum Texts
{
    SAY_SARA_PREFIGHT                           = 0,
    SAY_SARA_AGGRO                              = 1,
    SAY_SARA_PHASE1                             = 2,
    SAY_SARA_PHASE2                             = 3,
    SAY_SARA_SLAY                               = 4,
    SAY_SARA_PHASE2_1                           = 5,
    SAY_SARA_PHASE2_2                           = 6,
    SAY_SARA_PHASE2_3                           = 7,
    SAY_SARA_PHASE2_4                           = 8,

    SAY_FREYA_HELP                              = 0,
    SAY_MIMIRON_HELP                            = 0,
    SAY_THORIM_HELP                             = 0,
    SAY_HODIR_HELP                              = 0,

    SAY_PHASE3                                  = 0,
    SAY_VISION                                  = 1,
    SAY_PORTAL                                  = 2,
    SAY_SLAY                                    = 3,
    SAY_DEAFENING_ROAR                          = 4,
    WHISP_INSANITY                              = 5,
    SAY_DEATH                                   = 6,

    // Madness texts, at these orders
    // King Llane
    SAY_YOGGSARON_1_VISION_1                    = 7,
    SAY_YOGGSARON_2_VISION_1                    = 8,
    SAY_YOGGSARON_3_VISION_1                    = 9,
    SAY_GARONA_4_VISION_1                       = 0,
    SAY_GARONA_5_VISION_1                       = 1,
    SAY_GARONA_6_VISION_1                       = 2,
    SAY_KING_LLANE_7_VISION_1                   = 0,
    SAY_GARONA_8_VISION_1                       = 3,

    // Lichking
    SAY_CHAMP_1_VISION_2                        = 0,
    SAY_LICHKING_2_VISION_2                     = 0,
    SAY_CHAMP_3_VISION_2                        = 1,
    SAY_LICHKING_4_VISION_2                     = 1,
    SAY_YOGGSARON_5_VISION_2                    = 11,
    SAY_YOGGSARON_6_VISION_2                    = 12,

    // Dragon Soul
    SAY_NELTHARION_1_VISION_3                   = 0,
    SAY_YSERA_2_VISION_3                        = 0,
    SAY_NELTHARION_3_VISION_3                   = 1,
    SAY_MALYGOS_4_VISION_3                      = 0,
    SAY_YOGGSARON_5_VISION_3                    = 10
};

enum Achievements
{
    ACHIEV_TIMED_START_EVENT                      = 21001
};

enum Achievments
{
    // Sara
    ACHIEVMENT_KISS_AND_MAKE_UP_10              = 3009,
    ACHIEVMENT_KISS_AND_MAKE_UP_25              = 3011,
    ACHIEVMENT_DRIVE_ME_CRAZY_10                = 3008,
    ACHIEVMENT_DRIVE_ME_CRAZY_25                = 3010,
    ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_10    = 3012,
    ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_25    = 3013,

    // Heroic Mode
    ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_10  = 3157,
    ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_10    = 3141,
    ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_10    = 3158,
    ACHIEVMENT_ALONE_IN_THE_DARKNESS_10         = 3159,
    ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_25  = 3161,
    ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_25    = 3162,
    ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_25    = 3163,
    ACHIEVMENT_ALONE_IN_THE_DARKNESS_25         = 3164,

    // Realm First - 0 Keeper - 25
    ACHIEVMENT_REALM_FIRST_DEATHS_DEMISE        = 3117
};

enum Entries
{
    NPC_HELP_KEEPER_FREYA                       = 33241,
    NPC_HELP_KEEPER_MIMIRON                     = 33244,
    NPC_HELP_KEEPER_THORIM                      = 33242,
    NPC_HELP_KEEPER_HODIR                       = 33213,
    // All Phases
    NPC_KEEPER_FREYA                            = 33410,
    NPC_KEEPER_HODIR                            = 33411,
    NPC_KEEPER_MIMIRON                          = 33412,
    NPC_KEEPER_THORIM                           = 33413,
    NPC_BUNNY_SANITY_WELL                       = 33991,
    // Phase 1
    // NPC_SARA                                    = 33134,
    NPC_OMINOUS_CLOUD                           = 33292,
    NPC_GUARDIAN_OF_YOGG_SARON                  = 33136,
    // Phase 2
    NPC_YOGG_SARON                              = 33288,
    NPC_BRAIN_OF_YOGG_SARON                     = 33890,
    NPC_BUNNY_DEATH_RAY                         = 33881,
    NPC_BUNNY_DEATH_ORB                         = 33882,
    //  Tentakles
    NPC_CRUSHER_TENTACLE                        = 33966,
    NPC_CORRUPTOR_TENTACLE                      = 33985,
    NPC_CONSTRICTOR_TENTACLE                    = 33983,
    //  Brain
    //  All Vision
    NPC_BRAIN_PORTAL                            = 34072,
    NPC_INFULENCE_TENTACLE                      = 33943,
    NPC_LAUGHING_SKULL                          = 33990,
    //  Vision Dragon Soul
    NPC_RUBY_CONSORT                            = 33716, // 2 on Roomexit (l & r)
    NPC_OBSIDIAN_CONSORT                        = 33720, // 2 on End of the Room (l & r)
    NPC_EMERALD_CONSORT                         = 33719, // 2 on North West of the room
    NPC_AZURE_CONSORT                           = 33717, // 2 on North East of the room
    NPC_NELTHARION_VISION                       = 33523,
    NPC_YSERA_VISION                            = 33495,
    NPC_MALYGOS_VISION                          = 33535,
    //  Vision Llane
    NPC_SUIT_OF_ARMOR                           = 33433, // around the Room
    NPC_BUNNY_GARONA_VISION                     = 33436,
    NPC_KING_LLANE                              = 33437,
    //  Vision Lich King
    NPC_DEATHSWORN_ZEALOT                       = 33567, // 3 Groups of 3 ... left middle right
    NPC_LICHKING_VISION                         = 33441,
    NPC_IMMOLATED_CHAMPION_VISION               = 33442,
    NPC_TURNED_CHAMPION_VISION                  = 33962,
    // Phase 3
    NPC_IMMORTAL_GUARDIAN                       = 33988,

    OBJECT_THE_DRAGON_SOUL                      = 194462,
    OBJECT_FLEE_TO_SURFACE                      = 194625
};

enum MindlessSpell
{
    BRAIN_LINK      = 0,
    MALADY_OF_MIND  = 1,
    DEATH_RAY       = 2
};

enum EncounterConstants
{
    CONSTANT_MAX_LLIANE_TENTACLE_SPAWNS         = 8,
    CONSTANT_MAX_LICHKING_TENTACLE_SPAWNS       = 9,
    CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS     = 8
};

enum Actions
{
    ACTION_ENTER_COMBAT                             = 0,
    ACTION_WIPE                                     = 1,
    ACTION_ACTIVATE_YOGG                            = 2,
    ACTION_START_SARA                               = 3,
    ACTION_DO_CHANGE_PHASE                          = 4,
    ACTION_MADNESS_STARTED                          = 5,
    ACTION_APPLY_SHATTERED_ILLUSIONS                = 6,
    ACTION_REMOVE_SHATTERED_ILLUSIONS               = 7,
    ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE  = 8,
    ACTION_ACTIVATE_CLOUDS                          = 9,
    ACTION_PORTAL_TO_MADNESS_STORMWIND              = 10,
    ACTION_PORTAL_TO_MADNESS_DRAGON                 = 11,
    ACTION_PORTAL_TO_MADNESS_LICHKING               = 12,
    ACTION_BRAIN_UNDER_30_PERCENT                   = 13,
    ACTION_YOGGSARON_START_PHASE2                   = 14,
    ACTION_YOGGSARON_START_PHASE3                   = 15,
    ACTION_YOGGSARON_KILLED                         = 16,
    ACTION_DEATH_RAY_MOVE                           = 17,
    ACTION_USED_MINDCONTROL                         = 18,
    ACTION_MODIFY_SANITY                            = 19
};

enum Events
{
    // Yogg-saron controller
    EVENT_ENRAGE                                    = 1,
    EVENT_DESCENT_TO_MADNESS_BEGIN                  = 2,
    EVENT_DESCENT_TO_MADNESS_END                    = 3,

    // Sara
    EVENT_SARAHS_HELP                               = 4,
    EVENT_PSYCHOSIS                                 = 5,
    EVENT_MINDSPELL                                 = 6,
    EVENT_RANDOM_YELL                               = 7,
    EVENT_SPEAKING                                  = 8,
    EVENT_EVTSPEAKING                               = 9,

    // Yogg-saron
    EVENT_SANITY_CHECK                              = 10,
    EVENT_TENTACLE                                  = 11,
    EVENT_TENTACLE_1                                = 12,
    EVENT_SUMMON_GUARDIAN_YOGG                      = 13,
    EVENT_DEAFENING_ROAR                            = 14,
    EVENT_SHADOW_BEACON                             = 15,
    EVENT_LUNATIC_GAZE                              = 16
};

enum Spells
{
    SPELL_IN_THE_MAWS_OF_THE_OLD_GOD            = 64184,
    // All Phases
    // Keeper Freya
    SPELL_RESILIENCE_OF_NATURE                  = 62670,
    SPELL_SANITY_WELL                           = 64170, // Send Script Effect ... Scripted in Keeper Script (Summon)
    SPELL_SANITY_WELL_OPTIC                     = 63288, // Optical Effect ... Green Light
    SPELL_SANITY_WELL_DEBUFF                    = 64169, // Damage Debuff if you stand in the well
    // Keeper Thorim
    SPELL_FURY_OF_THE_STORM                     = 62702,
    SPELL_TITANIC_STORM                         = 64171, // Triggers 64172
    SPELL_TITANIC_STORM_DUMMY                   = 64172, // Dummy Spell ... kills weakend guardians
    // Keeper Mimiron
    SPELL_SPEED_OF_INVENTION                    = 62671,
    SPELL_DESTABILIZATION_MATRIX                = 65210, // No AoE ... Target every Tentakle or Guardian Random
    // Keeper Hodir
    SPELL_FORTITUDE_OF_FROST                    = 62650,
    SPELL_HODIRS_PROTECTIVE_GAZE                = 64174,
    SPELL_FLASH_FREEZE                          = 64175,
    SPELL_FLASH_FREEZE_COOLDOWN                 = 64176,
    // Sanity
    SPELL_SANITY                                = 63050,
    SPELL_INSANE                                = 63120, // MindControl
    SPELL_INSANE_2                              = 64464, // Let all player looks like FacelessOnes
    //Phase 1:
    SPELL_SUMMON_GUARDIAN                       = 63031,
    SPELL_OMINOUS_CLOUD                         = 60977,
    SPELL_OMINOUS_CLOUD_TRIGGER                 = 60978,
    SPELL_OMINOUS_CLOUD_DAMAGE                  = 60984,
    SPELL_OMINOUS_CLOUD_EFFECT                  = 63084,
    //  Sara
    SPELL_SARAS_FERVOR                          = 63138, // On Player
    SPELL_SARAS_BLESSING                        = 63134, // On Player
    SPELL_SARAS_ANGER                           = 63147, // On "Enemy"
    //  Guardians of Yogg-Saron
    SPELL_DOMINATE_MIND                         = 63042, // Removed by blizz, Needs Sanity Scripting
    SPELL_DARK_VOLLEY                           = 63038, // Needs Sanity Scripting
    SPELL_SHADOW_NOVA                           = 62714, // On Death
    SPELL_SHADOW_NOVA_SARA                      = 65719, // this Shadow Nova hits only Sara
    //Phase 2:64146
    SPELL_SARA_TRANSFORMATION                   = 65157,
    //  Sara - She spams Psychosis without pause on random raid members unless she casts something else. The other three abilities each have a 30 second cooldown, and are used randomly when available.
    SPELL_PSYCHOSIS                             = 65301, // Needs Sanity Scripting
    SPELL_BRAIN_LINK                            = 63802, // Only Apply Aura
    SPELL_BRAIN_LINK_DAMAGE                     = 63803, // Needs Sanity Scripting
    SPELL_BRAIN_LINK_DUMMY                      = 63804, // Dummy Effekt
    SPELL_MALADY_OF_MIND                        = 63830, // Needs Sanity Scripting, Trigger 63881 on remove
    SPELL_DEATH_RAY_SUMMON                      = 63891, // Summond 1 33882 (controll deathray)
    SPELL_DEATH_RAY_DAMAGE_VISUAL               = 63886, // Damage visual Effekt of 33881 (triggered with periodic)
    SPELL_DEATH_RAY_PERIODIC                    = 63883, // Trigger 63884
    SPELL_DEATH_RAY_ORIGIN_VISUAL               = 63893, // Visual Effekt of 33882
    SPELL_DEATH_RAY_WARNING_VISUAL              = 63882,
    SPELL_SARA_SHADOWY_BARRIER                  = 64775,
    // Tentacle
    SPELL_ERUPT                                 = 64144,
    SPELL_TENTACLE_VOID_ZONE                    = 64017,
    //  Crusher Tentacle
    SPELL_DIMISH_POWER                          = 64145, // Aura around Caster
    SPELL_FOCUS_ANGER                           = 57688, // Trigger 57689
    SPELL_CRUSH                                 = 64146,
    //  Corruptor Tentacle
    SPELL_DRAINING_POISON                       = 64152,
    SPELL_BLACK_PLAGUE                          = 64153, // Trigger 64155
    SPELL_APATHY                                = 64156,
    SPELL_CURSE_OF_DOOM                         = 64157,
    //  Constrictor Tentacles
    SPELL_LUNGE                                 = 64123, // Need Vehicle
    SPELL_SQUEEZE_10                            = 64125, // Until killed
    SPELL_SQUEEZE_25                            = 64126,
    //  Influence Tentacle
    SPELL_GRIM_REPRISAL                         = 63305, // Dummy aura
    SPELL_GRIM_REPRISAL_DAMAGE                  = 64039, // Damage 1
    //  Yogg-Saron
    SPELL_EXTINGUISH_ALL_LIFE                   = 64166, // After 15 Minutes
    SPELL_SHADOWY_BARRIER                       = 63894,
    SPELL_SUMMON_CRUSHER_TENTACLE               = 64139,
    SPELL_SUMMON_CURRUPTOR_TENTACLE             = 64143,
    SPELL_SUMMON_CONSTRICTOR_TENTACLES          = 64133,
    //  Brain of Yogg-Sauron
    SPELL_INDUCE_MADNESS                        = 64059,
    SPELL_SHATTERED_ILLUSIONS                   = 64173,
    SPELL_BRAIN_HURT_VISUAL                     = 64361,
    //  Mind Portal
    SPELL_TELEPORT                              = 64027, // Not Used
    SPELL_ILLUSION_ROOM                         = 63988, // Must be removed if not in Room
    //  Lauthing Skull
    SPELL_LS_LUNATIC_GAZE                       = 64167,
    SPELL_LS_LUNATIC_GAZE_EFFECT                = 64168,
    //Phase 3:
    SPELL_YOGG_SARON_TRANSFORMATION             = 63895,
    //  Yogg-Saron
    SPELL_DEAFENING_ROAR                        = 64189, // Cast only on 25plr Mode and only with 0-3 Keepers active
    SPELL_SUMMON_IMMORTAL_GUARDIAN              = 64158,

    SPELL_SHADOW_BEACON                         = 64465, // Casted on Immortal Guardian - trigger 64466
    SPELL_EMPOWERING_SHADOWS_SCRP_1             = 64466, // Script Effekt ... as index 64467
    SPELL_EMPOWERING_SHADOWS_SCRP_2             = 64467, // I dont need this
    SPELL_EMPOWERING_SHADOWS_HEAL_10            = 64468, // 10plr Heal
    SPELL_EMPOWERING_SHADOWS_HEAL_25            = 64486, // 20plr Heal

    SPELL_LUNATIC_GAZE                          = 64163, // Triggers 4 Times 64164
    SPELL_LUNATIC_GAZE_EFFECT                   = 64164, // Needs Sanity Scripting

    //  Immortal Guardian - under 1% no damage
    SPELL_DRAIN_LIFE_10                         = 64159,
    SPELL_DRAIN_LIFE_25                         = 64160,

    SPELL_WEAKENED                              = 64162, // Dummy on low health for Titan Storm and Shadow Beacon
    SPELL_EMPOWERED                             = 65294  // stacks 9 times ... on 100% hp it have 9 stacks .. but with <10% it havent any
};

enum Phases
{
    PHASE_NONE  = 0,
    PHASE_SARA  = 1,
    PHASE_BRAIN = 2,
    PHASE_YOGG  = 3
};

enum TentacleType
{
    CRUSHER_TENTACLE        = 0,
    CORRUPTOR_TENTACLE      = 1,
    CONSTRICTOR_TENTACLE    = 2
};

enum BrainEventPhase
{
    PORTAL_PHASE_KING_LLIANE = 0,
    PORTAL_PHASE_DRAGON_SOUL = 1,
    PORTAL_PHASE_LICH_KING   = 2,
    PORTAL_PHASE_BRAIN_NONE  = 3
};

enum Grp
{
    ID_GROUP_NON_SHATTERED = 42
};

const Position InnerBrainLocation[3] =
{
    {1944.87f,  37.22f, 239.7f, (0.66f*M_PI)}, //King Lliane
    {2045.97f, -25.45f, 239.8f, 0.0f        }, //Dragon Soul
    {1953.41f, -73.73f, 240.0f, (1.33f*M_PI)}  //Lich King
};

const Position BrainPortalLocation[10] =
{
    {1970.48f,   -9.75f, 325.5f, 0},
    {1992.76f,  -10.21f, 325.5f, 0},
    {1995.53f,  -39.78f, 325.5f, 0},
    {1969.25f,  -42.00f, 325.5f, 0},
    {1960.62f,  -32.00f, 325.5f, 0},
    {1981.98f,  -5.69f,  325.5f, 0},
    {1982.78f,  -45.73f, 325.5f, 0},
    {2000.66f,  -29.68f, 325.5f, 0},
    {1999.88f,  -19.61f, 325.5f, 0},
    {1961.37f,  -19.54f, 325.5f, 0}
};

const Position KingLlaneTentacleLocation[CONSTANT_MAX_LLIANE_TENTACLE_SPAWNS] =
{
    {1949.82f,   50.77f, 239.70f, (0.8f*M_PI)},
    {1955.24f,   72.08f, 239.70f, (1.04f*M_PI)},
    {1944.51f,   90.88f, 239.70f, (1.3f*M_PI)},
    {1923.46f,   96.71f, 239.70f, (1.53f*M_PI)},
    {1904.14f,   85.99f, 239.70f, (1.78f*M_PI)},
    {1898.78f,   64.62f, 239.70f, (0.05f*M_PI)},
    {1909.74f,   45.15f, 239.70f, (0.31f*M_PI)},
    {1931.01f,   39.85f, 239.70f, (0.55f*M_PI)}
};

const Position DragonSoulTentacleLocation[CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS] =
{
    // ENTRY_RUBY_CONSORT
    {2061.44f,  -11.83f, 239.80f, 0.0f},
    {2059.87f,  -37.77f, 239.80f, 0.0f},
    // ENTRY_AZURE_CONSORT
    {2105.42f,  -71.81f, 239.80f, (0.51f*M_PI)},
    {2131.29f,  -60.90f, 239.80f, (0.68f*M_PI)},
    // ENTRY_OBSIDIAN_CONSORT
    {2147.62f,  -42.06f, 239.80f, M_PI},
    {2147.62f,   -6.91f, 239.80f, M_PI},
    //ENTRY_EMERAL_CONSORT
    {2125.64f,   17.08f, 239.80f, (1.35f*M_PI)},
    {2109.06f,   22.69f, 239.80f, (1.42f*M_PI)}
};

const Position LichKingTentacleLocation[CONSTANT_MAX_LICHKING_TENTACLE_SPAWNS] =
{
    {1944.20f,  -136.72f, 240.00f, (1.35f*M_PI)},
    {1950.06f,  -139.36f, 240.00f, (1.35f*M_PI)},
    {1948.23f,  -129.44f, 240.00f, (1.35f*M_PI)},

    {1920.34f,  -136.38f, 240.00f, (1.35f*M_PI)},
    {1914.44f,  -132.35f, 240.00f, (1.35f*M_PI)},
    {1919.69f,  -129.47f, 240.00f, (1.35f*M_PI)},

    {1909.49f,  -111.84f, 240.00f, (1.35f*M_PI)},
    {1902.02f,  -107.69f, 240.00f, (1.35f*M_PI)},
    {1910.28f,  -102.96f, 240.00f, (1.35f*M_PI)}
};

const Position BrainLocation = {1980.01f, -25.36f, 260.00f, M_PI};
const Position SaraLocation = {1980.28f, -25.58f, 325.00f, M_PI};

const Position InnerBrainTeleportLocation[3] =
{
    {2001.40f, -59.66f, 245.07f, 0},
    {1941.61f, -25.88f, 244.98f, 0},
    {2001.18f,  9.409f, 245.24f, 0}
};

const Position KeeperSpawnLocation[4] =
{
    {1939.15f,  42.47f, 338.46f, 1.7f*M_PI}, // Mimiron
    {2037.09f,  25.43f, 338.46f, 1.3f*M_PI}, // Freya
    {2036.88f, -73.66f, 338.46f, 0.7f*M_PI}, // Thorim
    {1939.94f, -90.49f, 338.46f, 0.3f*M_PI}  // Hodir
};

const Position FreyaSanityWellLocation[5] =
{
    {1901.21f, -48.69f, 332.00f, 0.0f},
    {1901.90f,  -2.78f, 332.30f, 0.0f},
    {1993.58f,  45.56f, 332.00f, 0.0f},
    {1985.87f, -91.10f, 330.20f, 0.0f},
    {2040.12f, -39.16f, 329.00f, 0.0f}
};

const Position KingLlaneSkullLocation[3] =
{
    {1929.41f,  45.27f, 239.70f, 0.0f},
    {1902.31f,  72.53f, 239.70f, 0.0f},
    {1925.10f,  91.52f, 239.70f, 0.0f}
};

const Position LichkingSkullLocation[3] =
{
    {1955.12f, -111.96f,  240.00f, 0.0f},
    {1919.55f, -131.94f,  240.00f, 0.0f},
    {1921.03f,  -93.46f,  240.00f, 0.0f}
};

const Position DragonSoulSkullLocation[4] =
{
    {2115.89f,   4.63f,  239.80f, 0.0f},
    {2080.65f,  37.47f,  244.3f,  0.0f},
    {2170.20f, -33.31f,  244.3f,  0.0f},
    {2090.49f, -57.40f,  239.8f,  0.0f}
};

const Position EventNpcLocation[9] =
{
    { 1928.23f,  66.81f,  242.40f, 5.207f }, // King Llane
    { 1929.78f,  63.60f,  242.40f, 2.124f }, // Garona - kneeling
    { 2103.87f, -13.13f,  242.65f, 4.692f }, // Ysera
    { 2118.68f, -25.56f,  242.65f, M_PI},    // Neltharion
    { 2095.87f, -34.47f,  242.65f, 0.836f }, // Malygos
    { 2104.61f, -25.36f,  242.65f, 0.0f },   // The Dragon Soul
    { 1903.41f, -160.21f, 239.99f, 1.114f }, // Immolated Champion
    { 1909.31f, -155.88f, 239.99f, 4.222f }, // Turned Champion
    { 1907.02f, -153.92f, 239.99f, 4.187f }  // The Lich King
};

struct EventNPC
{
    uint32 entry;
    uint64 guid;
};

struct EventSpeech
{
    uint32 npc_entry;
    int32 speech_entry;
    uint32 next_speech;
};

const uint32 EventNpcEntrys[9] =
{
    NPC_KING_LLANE,
    NPC_BUNNY_GARONA_VISION,
    NPC_YSERA_VISION,
    NPC_NELTHARION_VISION,
    NPC_MALYGOS_VISION,
    OBJECT_THE_DRAGON_SOUL,
    NPC_IMMOLATED_CHAMPION_VISION,
    NPC_TURNED_CHAMPION_VISION,
    NPC_LICHKING_VISION
};

const EventSpeech EventNpcSpeaching[19] =
{
    {NPC_YOGG_SARON, SAY_YOGGSARON_1_VISION_1, 3000},
    {NPC_YOGG_SARON, SAY_YOGGSARON_2_VISION_1, 3000},
    {NPC_YOGG_SARON, SAY_YOGGSARON_3_VISION_1, 5000},
    {NPC_BUNNY_GARONA_VISION, SAY_GARONA_4_VISION_1, 2000},
    {NPC_BUNNY_GARONA_VISION, SAY_GARONA_5_VISION_1, 8000},
    {NPC_BUNNY_GARONA_VISION, SAY_GARONA_6_VISION_1, 10000},
    {NPC_KING_LLANE, SAY_KING_LLANE_7_VISION_1, 10000},
    {NPC_BUNNY_GARONA_VISION, SAY_GARONA_8_VISION_1, 7000},

    {NPC_IMMOLATED_CHAMPION_VISION, SAY_CHAMP_1_VISION_2, 5000},/*8*/
    {NPC_LICHKING_VISION, SAY_LICHKING_2_VISION_2, 7000},
    {NPC_IMMOLATED_CHAMPION_VISION, SAY_CHAMP_3_VISION_2, 5000},
    {NPC_LICHKING_VISION, SAY_LICHKING_4_VISION_2, 7000},
    {NPC_YOGG_SARON, SAY_YOGGSARON_5_VISION_2, 5000},
    {NPC_YOGG_SARON, SAY_YOGGSARON_6_VISION_2, 5000},

    {NPC_NELTHARION_VISION, SAY_NELTHARION_1_VISION_3, 9000},/*14*/
    {NPC_YSERA_VISION, SAY_YSERA_2_VISION_3, 4000},
    {NPC_NELTHARION_VISION, SAY_NELTHARION_3_VISION_3, 3000},
    {NPC_MALYGOS_VISION, SAY_MALYGOS_4_VISION_3, 8000},
    {NPC_YOGG_SARON, SAY_YOGGSARON_5_VISION_3, 6000}
};

enum Disabler
{ 
    SPELL_DEATH_GRIP = 49560 
};

Player* SelectPlayerTargetInRange(Creature* me, float range)
{
    Player* target = NULL;
    Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
    Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
    me->VisitNearbyObject(range, searcher);
    return target;
}

uint32 Entry_2_ID(uint32 entry)
{
    switch (entry)
    {
        case NPC_HELP_KEEPER_FREYA:     return BOSS_FREYA;
        case NPC_HELP_KEEPER_HODIR:     return BOSS_HODIR;
        case NPC_HELP_KEEPER_MIMIRON:   return BOSS_MIMIRON;
        case NPC_HELP_KEEPER_THORIM:    return BOSS_THORIM;
        default: break;
    }
    return 0;
}

bool IsPlayerInBrainRoom(const Player* pPlayer)
{
    return pPlayer->GetPositionZ() < 300.0f;
}

class IsNotLookingDirectlyInGaze : public std::unary_function<WorldObject*, bool>
{
    public:
        IsNotLookingDirectlyInGaze(WorldObject* caster) : __caster(caster) {}

        bool operator() (WorldObject* unit)
        {
            Position pos;
            __caster->GetPosition(&pos);
            return !unit->HasInArc(static_cast<float>(M_PI), &pos);
        }

    private:
        WorldObject* __caster;
};

class NotIsWeakenedImmortalCheck : public std::unary_function<WorldObject*, bool>
{
    public:
        NotIsWeakenedImmortalCheck() {}

        bool operator() (WorldObject* unit)
        {
            return !(unit->ToUnit()->HasAura(SPELL_WEAKENED));
        }
};

class BrainLinkTargetSelector : public std::unary_function<WorldObject*, bool> 
{
    public:
        bool operator() (WorldObject* unit)
        {
            return unit->GetPositionZ() < 300.0f;
        }
};

class DistancePredicate : std::binary_function<Player*, Player*, bool>
{
    public:
        DistancePredicate(Unit* base, bool descending, bool dim3) : __base(base), __descending(descending), __dim3(dim3) {}   // descending = absteigend
        bool operator()(Player* first, Player* second)
        {
            float distFirst = 0.0f, distSecond = 0.0f;
            if (__dim3)
            {
                distFirst = __base->GetDistance(first);
                distSecond = __base->GetDistance(second);
            }
            else
            {
                distFirst = __base->GetDistance2d(first);
                distSecond = __base->GetDistance2d(second);
            }

            return ( __descending ? distFirst >= distSecond : distFirst <= distSecond );
        }

    private:
        Unit* __base;
        bool __descending;
        bool __dim3;
};

class GetNearestPlayers : std::binary_function<std::list<Player*>&, Creature*, void>
{
    public:
        GetNearestPlayers(float distance, uint32 cap) : __distance(distance), __cap(cap) {}

        void operator()(std::list<Player*>& listp, Creature* base)
        {
            if (!base)
                return;

            if (Map* map = base->GetMap())
            {
                const Map::PlayerList& players = map->GetPlayers();
                uint32 counter = 0;
                __cap = __cap == 0 ? players.getSize(): __cap;  // __cap = 0 indicates no cap
                for (MapRefManager::const_iterator it = players.begin(); it != players.end() && counter < __cap; ++it, counter++)
                {
                    if (__distance != 0.0f) // Check range enabled if __distance is no 0.0f
                    {
                        if (base->GetDistance2d(it->getSource()) <= __distance)
                        {
                            listp.push_back(it->getSource());
                        }
                    }
                    else
                        listp.push_back(it->getSource());

                }
                listp.sort(DistancePredicate(base, false, false));
            }
        }

    private:
        uint32 __cap;
        float __distance;
};

struct InsaneCandidatePredicate : std::unary_function<Player*, bool>
{
    bool operator()(Player* p)
    {
        if ( p->isAlive() && !p->isGameMaster() && !p->HasAura(SPELL_SANITY) && !p->HasAura(SPELL_INSANE) )
            return true;
        return false;
    }
};

template<typename Predicate>
class GetPlayersByCondition : std::unary_function<Creature*, void>
{
    public:
        GetPlayersByCondition(std::list<Player*>& plist) : __plist(plist) {}

        void operator()(Creature* base)
        {
            if (base)
                if (Map* map = base->GetMap())
                {
                    const Map::PlayerList& players = map->GetPlayers();
                    for (MapRefManager::const_iterator it = players.begin(); it != players.end(); ++it)
                    {
                        if ( __pred(it->getSource()) )
                            __plist.push_back(it->getSource());
                    }
                }
        }

    private:
        Predicate __pred;
        std::list<Player*>& __plist;
};

class AllSaronitCreaturesInRange : std::unary_function<Unit*, bool>
{
    public:
        AllSaronitCreaturesInRange(const WorldObject* pObject, float fMaxRange) : m_pObject(pObject), m_fRange(fMaxRange) {}
        bool operator()(Unit* pUnit)
        {
            if (IsSaronitEntry(pUnit->GetEntry()) && m_pObject->IsWithinDist(pUnit, m_fRange, false) && pUnit->isAlive())
                return true;

            return false;
        }

    private:
        const WorldObject* m_pObject;
        float m_fRange;

        bool IsSaronitEntry(uint32 entry)
        {
            switch (entry)
            {
                case NPC_GUARDIAN_OF_YOGG_SARON:
                case NPC_CONSTRICTOR_TENTACLE:
                case NPC_CORRUPTOR_TENTACLE:
                case NPC_CRUSHER_TENTACLE:
                case NPC_IMMORTAL_GUARDIAN:
                    return true;
                default:
                    break;
            }
            return false;
        }
};

class npc_yogg_saron_encounter_controller : public CreatureScript   // Should be NPC 29224 (Presence of Yogg-Saron) or 33552.
{
    public:
        npc_yogg_saron_encounter_controller() : CreatureScript("npc_yogg_saron_encounter_controller") {}

        struct npc_yogg_saron_encounter_controllerAI : public BossAI
        {
            npc_yogg_saron_encounter_controllerAI(Creature* c) : BossAI(c, BOSS_YOGGSARON), _guidEventTentacles(me), _guidEventSkulls(me)
            {
                me->SetCanFly(true);
                me->SetVisible(false);
                _guidYogg = 0;
                _guidYoggBrain = 0;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_YOGGSARON_KILLED:
                        if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            yogg->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                        if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                            me->Kill(sara);

                        if (events.GetNextEventTime(EVENT_ENRAGE) >= 8*MINUTE*IN_MILLISECONDS)
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_10, ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_25));
                        if (!_usedMindcontrol)
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_DRIVE_ME_CRAZY_10, ACHIEVMENT_DRIVE_ME_CRAZY_25));
                        if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL && !CountKeepersActive())
                            instance->DoCompleteAchievement(ACHIEVMENT_REALM_FIRST_DEATHS_DEMISE);
                        switch (CountKeepersActive())
                        {
                            case 0:
                                instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_ALONE_IN_THE_DARKNESS_10, ACHIEVMENT_ALONE_IN_THE_DARKNESS_25));
                            case 1:
                                instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_10, ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_25));
                            case 2:
                                instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_10, ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_25));
                            case 3:
                                instance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_10, ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_25));
                                break;
                            default: 
                                break;
                        }
                        me->Kill(me);   // Should call JustDied();
                        break;
                    case ACTION_BRAIN_UNDER_30_PERCENT:
                        UpdatePhase(PHASE_YOGG);
                        break;
                    case ACTION_USED_MINDCONTROL:
                        _usedMindcontrol = true;
                        break;
                    case ACTION_WIPE:
                        instance->SetBossState(BOSS_YOGGSARON, FAIL);
                        if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            yogg->DespawnOrUnsummon();
                        if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                            yoggbrain->DespawnOrUnsummon();
                        Reset();
                        break;
                    case ACTION_ACTIVATE_YOGG:
                        if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                        {
                            yogg->AI()->SetData(ACTION_DO_CHANGE_PHASE, PHASE_BRAIN);
                            yogg->CastSpell(yogg, SPELL_SHADOWY_BARRIER, false);
                            yogg->SetStandState(UNIT_STAND_STATE_STAND);
                            yogg->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            yogg->CastSpell(yogg, SPELL_SUMMON_CURRUPTOR_TENTACLE, true);
                            yogg->AI()->Talk(SAY_PHASE3);
                        }

                        OnRemove_ShatteredIllusions(false);
                        break;
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_ENRAGE, 15*MINUTE*IN_MILLISECONDS);
            }

            uint32 GetData(uint32 data) const
            {
                switch (data)
                {
                    case DATA_PORTAL_PHASE:
                        return _currentBrainEventPhase;
                    case DATA_IS_ENCOUNTER_IN_PROGRESS:
                        return static_cast<uint32>(IsEncounterInProgress());
                    case DATA_BRAIN_EVT_CNT:
                        return _brainEventsCount;
                    case DATA_KEEPER_CNT:
                        return CountKeepersActive();
                    default:
                        break;
                }
                return 0;
            }

            uint64 GetGUID(int32 which) const
            {
                return GetEventNPCGuid(static_cast<uint32>(which)); // cast is safe since controlled by myself, it's just an int32 due to signature match
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                SetSanityAura(true);
            } 

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_YOGG_SARON:
                        _guidYogg = summon->GetGUID();
                        summon->SetReactState(REACT_PASSIVE);
                        summon->SetStandState(UNIT_STAND_STATE_SUBMERGED);
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        summon->SetFloatValue(UNIT_FIELD_COMBATREACH, 20.0f);
                        summon->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 20.0f);
                        return; 
                    case NPC_BRAIN_OF_YOGG_SARON:
                        _guidYoggBrain = summon->GetGUID();
                        summon->setActive(true);
                        summon->SetFloatValue(UNIT_FIELD_COMBATREACH, 25.0f);
                        summon->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 25.0f);
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    case NPC_KEEPER_FREYA:
                    case NPC_KEEPER_HODIR:
                    case NPC_KEEPER_MIMIRON:
                    case NPC_KEEPER_THORIM:
                        summon->setActive(true);
                        break;
                    case NPC_GUARDIAN_OF_YOGG_SARON:
                        summon->setFaction(FACTION_HOSTILE);
                        summon->AI()->AttackStart(SelectPlayerTargetInRange(me, 100.0f));
                        break;
                    case NPC_RUBY_CONSORT:
                    case NPC_OBSIDIAN_CONSORT:
                    case NPC_AZURE_CONSORT:
                    case NPC_EMERALD_CONSORT:
                    case NPC_DEATHSWORN_ZEALOT:
                    case NPC_SUIT_OF_ARMOR:
                        summon->SetReactState(REACT_DEFENSIVE);
                        summon->setFaction(15);
                        break;
                    case NPC_LAUGHING_SKULL:
                        summon->setFaction(FACTION_HOSTILE);
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
                if (!(summon->GetEntry() == NPC_YOGG_SARON)) // Do Not Save Yoggy in summons because he shouldn't despawn on encounter finish
                    summons.Summon(summon);
            }

            void MoveInLineOfSight(Unit* target)
            {
                if (_phase == PHASE_NONE)
                {
                    if (target && me->GetDistance2d(target) <= 40.0f && target->ToPlayer() && !target->ToPlayer()->isGameMaster() && me->IsWithinLOSInMap(target))
                    {
                        if (instance->GetBossState(BOSS_VEZAX) == DONE)
                        {
                            UpdatePhase(PHASE_SARA);

                            if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                                sara->AI()->DoAction(ACTION_START_SARA);

                            if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            {
                                yogg->AI()->DoAction(ACTION_ENTER_COMBAT);  // Workaround, since we cannot attack players.
                                EnterCombat(target);
                            }
                        }
                    }
                }
            }

            void Reset()
            {
                _Reset();
                _phase = PHASE_NONE;
                SpawnClouds(true, 6);

                if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                    yogg->DespawnOrUnsummon();
                if (Creature* yogg = DoSummon(NPC_YOGG_SARON, SaraLocation, 0, TEMPSUMMON_MANUAL_DESPAWN))
                    yogg->SetLootMode(LOOT_MODE_DEFAULT);
                if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                    yoggbrain->DespawnOrUnsummon();
                DoSummon(NPC_BRAIN_OF_YOGG_SARON, BrainLocation, 0, TEMPSUMMON_MANUAL_DESPAWN);

                _usedMindcontrol = false;
                _lastBrainAction = Actions(0);
                _listEventNPCs.clear();
                _guidEventSkulls.DespawnAll();
                _guidEventTentacles.DespawnAll();
                _currentBrainEventPhase = PORTAL_PHASE_BRAIN_NONE;
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 30.0f);
            }

            void SetData(uint32 type, uint32 val)
            {
                switch (type)
                {
                    case ACTION_DO_CHANGE_PHASE:
                        UpdatePhase(static_cast<Phases>(val));
                        break;
                    default:
                        break;
                }
            }

            void SummonedCreatureDies(Creature* creature, Unit* /* killer */)
            {
                SummonedCreatureDespawn(creature);
            }

            void SummonedCreatureDespawn(Creature* creature)
            {
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_RUBY_CONSORT:        // From phase PORTAL_PHASE_DRAGON_SOUL
                    case NPC_AZURE_CONSORT:
                    case NPC_OBSIDIAN_CONSORT:
                    case NPC_EMERALD_CONSORT:
                    case NPC_DEATHSWORN_ZEALOT:   // From phase PORTAL_PHASE_LICH_KING
                    case NPC_SUIT_OF_ARMOR:       // From phase PORTAL_PHASE_KING_LLIANE
                    case NPC_INFULENCE_TENTACLE:
                        _guidEventTentacles.Despawn(creature);
                        if (_guidEventTentacles.empty()) // All are dead or despawned
                        {
                            if (!me->HasAura(SPELL_SHATTERED_ILLUSIONS)) // Just for the case, it should _not_ be there !
                            {
                                if (_currentBrainEventPhase != PORTAL_PHASE_BRAIN_NONE)
                                {
                                    switch (_currentBrainEventPhase)
                                    {
                                        case PORTAL_PHASE_DRAGON_SOUL:
                                            instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_1), true);
                                            break;
                                        case PORTAL_PHASE_LICH_KING:
                                            instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_2), true);
                                            break;
                                        case PORTAL_PHASE_KING_LLIANE:
                                            instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_3), true);
                                            break;
                                        default:
                                            break;
                                    }
                                    _currentBrainEventPhase = PORTAL_PHASE_BRAIN_NONE;

                                    OnApply_ShatteredIllusions();
                                    _guidEventSkulls.DespawnAll();
                                }
                            }
                        }
                        break;
                    case NPC_LAUGHING_SKULL:      // From all phases
                        _guidEventSkulls.Despawn(creature);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() && _phase == PHASE_NONE)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            {
                                yogg->InterruptNonMeleeSpells(false);
                                yogg->CastSpell(yogg, SPELL_EXTINGUISH_ALL_LIFE, false);
                                if (SelectPlayerTargetInRange(me, 500.0f))  // If anyone survived this, try again :)
                                    events.ScheduleEvent(EVENT_ENRAGE, 1*IN_MILLISECONDS);
                            }
                            return;
                        case EVENT_DESCENT_TO_MADNESS_BEGIN:
                            if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            {
                                yogg->AI()->Talk(SAY_PORTAL);
                                DoMadness();
                            }

                            events.ScheduleEvent(EVENT_DESCENT_TO_MADNESS_BEGIN, 1.5*MINUTE*IN_MILLISECONDS, 0, PHASE_BRAIN);
                            events.ScheduleEvent(EVENT_DESCENT_TO_MADNESS_END, 1*MINUTE*IN_MILLISECONDS, 0, PHASE_BRAIN); // End of cast SPELL_INDUCE_MADNESS
                            return;
                        case EVENT_DESCENT_TO_MADNESS_END:
                            OnRemove_ShatteredIllusions(false);
                            return;
                        default:
                            return;
                    }
                }

                if (!CheckBoundary(me->getVictim()))
                    EnterEvadeMode();
            }

            /************************************************************************/
            /*                         Custom stuff                                 */
            /************************************************************************/
            void SpawnClouds(bool spawn, uint8 amount = 1)
            {
                if (spawn)
                {
                    // spawn clouds randomly around Sara (6 at reset)
                    for (uint8 i = 0; i < amount; i++)
                        if (Creature* summon = me->SummonCreature(NPC_OMINOUS_CLOUD, me->GetPositionX() + frand(0.f, 80.f) - 40.f , me->GetPositionY() + frand(0.f,80.f) - 40.f, me->GetPositionZ()))
                            summon->AI()->DoAction(ACTION_ACTIVATE_CLOUDS);
                }
                else
                {
                    std::list<Creature*> CloudList;
                    me->GetCreatureListWithEntryInGrid(CloudList, NPC_OMINOUS_CLOUD, 100.0f);
                    if (!CloudList.empty())
                        for (std::list<Creature*>::iterator itr = CloudList.begin(); itr != CloudList.end(); itr++)
                            (*itr)->DespawnOrUnsummon();
                }
            }

            uint32 CountKeepersActive() const
            {
                uint32 count = 0;
                uint32 supportFlag = instance->GetData(DATA_KEEPER_SUPPORT_YOGG);

                if (supportFlag & MIMIRON_SUPPORT)
                    count++;
                if (supportFlag & FREYA_SUPPORT)
                    count++;
                if (supportFlag & THORIM_SUPPORT)
                    count++;
                if (supportFlag & HODIR_SUPPORT)
                    count++;
                return count;
            }

            void DoMadness()
            {
                instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_1), false);
                instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_2), false);
                instance->HandleGameObject(instance->GetData64(DATA_BRAIN_DOOR_3), false);

                Actions tempAction;
                switch (_lastBrainAction)
                {
                    case ACTION_PORTAL_TO_MADNESS_STORMWIND:
                        tempAction = ACTION_PORTAL_TO_MADNESS_DRAGON;
                        break;
                    case ACTION_PORTAL_TO_MADNESS_DRAGON:
                        tempAction = ACTION_PORTAL_TO_MADNESS_LICHKING;
                        break;
                    case ACTION_PORTAL_TO_MADNESS_LICHKING:
                        tempAction = ACTION_PORTAL_TO_MADNESS_STORMWIND;
                        break;
                    default:
                        RAND(ACTION_PORTAL_TO_MADNESS_STORMWIND, ACTION_PORTAL_TO_MADNESS_DRAGON, ACTION_PORTAL_TO_MADNESS_LICHKING);
                        break;
                }
                _lastBrainAction = tempAction;

                // Spawn Portal
                for(uint8 i = 0; i < RAID_MODE(4, 10); i++)
                    if (Creature* portal = DoSummon(NPC_BRAIN_PORTAL, BrainPortalLocation[i], 40*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                        portal->AI()->DoAction(tempAction);

                // Spawn Event Tentacle
                switch (tempAction)
                {
                    case ACTION_PORTAL_TO_MADNESS_STORMWIND:
                        _currentBrainEventPhase = PORTAL_PHASE_KING_LLIANE;
                        _guidEventTentacles.DespawnAll();
                        _guidEventSkulls.DespawnAll();
                        for (uint32 i = 0; i < CONSTANT_MAX_LLIANE_TENTACLE_SPAWNS; i++)
                        {
                            if (Creature* summon = DoSummon(NPC_SUIT_OF_ARMOR, KingLlaneTentacleLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventTentacles.Summon(summon);
                        }
                        for (uint8 i = 0; i < 3; i++)
                        {
                            if (Creature* summon = DoSummon(NPC_LAUGHING_SKULL, KingLlaneSkullLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventSkulls.Summon(summon);
                        }
                        break;
                    case ACTION_PORTAL_TO_MADNESS_DRAGON:
                        _currentBrainEventPhase = PORTAL_PHASE_DRAGON_SOUL;
                        _guidEventTentacles.DespawnAll();
                        _guidEventSkulls.DespawnAll();
                        uint32 entry;
                        for (uint32 i = 0; i < CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS; i++)
                        {
                            switch (i)
                            {
                                case 0:
                                case 1: entry = NPC_RUBY_CONSORT; break;
                                case 2:
                                case 3: entry = NPC_AZURE_CONSORT; break;
                                case 4:
                                case 5: entry = NPC_OBSIDIAN_CONSORT; break;
                                case 6:
                                case 7: entry = NPC_EMERALD_CONSORT; break;
                                default: break;
                            }
                            if (Creature* summon = DoSummon(entry, DragonSoulTentacleLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventTentacles.Summon(summon);
                        }
                        for (uint8 i = 0; i < 4; i++)
                        {
                            if (Creature* summon = DoSummon(NPC_LAUGHING_SKULL, DragonSoulSkullLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventSkulls.Summon(summon);
                        }
                        break;
                    case ACTION_PORTAL_TO_MADNESS_LICHKING:
                        _currentBrainEventPhase = PORTAL_PHASE_LICH_KING;
                        _guidEventTentacles.DespawnAll();
                        _guidEventSkulls.DespawnAll();
                        for (uint32 i = 0; i < CONSTANT_MAX_LICHKING_TENTACLE_SPAWNS; i++)
                        {
                            if (Creature* summon = DoSummon(NPC_DEATHSWORN_ZEALOT, LichKingTentacleLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventTentacles.Summon(summon);
                        }
                        for (uint8 i = 0; i < 3; i++)
                        {
                            if (Creature* summon = DoSummon(NPC_LAUGHING_SKULL, LichkingSkullLocation[i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                _guidEventSkulls.Summon(summon);
                        }
                        break;
                    default:
                        break;
                }

                if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                {
                    yoggbrain->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    yoggbrain->CastSpell(yoggbrain, SPELL_INDUCE_MADNESS, false);   // Takes about one minute; Corresponding event is scheduled in UpdateAI
                }

                SummonMadnessEventNPCs();
                if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                    sara->AI()->DoAction(ACTION_MADNESS_STARTED);
                _brainEventsCount++;
            }

            void DoSpawnKeeperForSupport() // Despawn on Sara Reset
            {
                uint32 supportFlag = instance->GetData(DATA_KEEPER_SUPPORT_YOGG);

                if ((supportFlag & MIMIRON_SUPPORT) == MIMIRON_SUPPORT)
                    DoSummon(NPC_KEEPER_MIMIRON, KeeperSpawnLocation[0], 0, TEMPSUMMON_MANUAL_DESPAWN);
                if ((supportFlag & FREYA_SUPPORT) == FREYA_SUPPORT)
                    DoSummon(NPC_KEEPER_FREYA, KeeperSpawnLocation[1], 0, TEMPSUMMON_MANUAL_DESPAWN);
                if ((supportFlag & THORIM_SUPPORT) == THORIM_SUPPORT)
                    DoSummon(NPC_KEEPER_THORIM, KeeperSpawnLocation[2], 0, TEMPSUMMON_MANUAL_DESPAWN);
                if ((supportFlag & HODIR_SUPPORT) == HODIR_SUPPORT)
                    DoSummon(NPC_KEEPER_HODIR, KeeperSpawnLocation[3], 0, TEMPSUMMON_MANUAL_DESPAWN);
            }

            uint64 GetEventNPCGuid(uint32 entry) const
            {
                for (std::list<EventNPC>::const_iterator itr = _listEventNPCs.begin(); itr != _listEventNPCs.end(); ++itr)
                {
                    if (itr->entry == entry)
                        return itr->guid;
                }
                return 0;
            }

            bool IsEncounterInProgress() const
            {
                if (me->GetMap())
                {
                    if (me->GetMap()->IsDungeon())
                    {
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        if (!players.isEmpty())
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* plr = itr->getSource())
                                    if (plr->isAlive() && !plr->isGameMaster() && !plr->HasAura(SPELL_INSANE))
                                        return true;
                    }
                }

                return false;
            } 

            void ModifySanity(Player* target, int8 amount)  // TODO: Check if stack-amount-handling by Freyas Well works correctly
            {
                if (target)
                    if (target->isAlive())
                    {
                        int32 newamount;
                        if (Aura* aur = target->GetAura(SPELL_SANITY, me->GetGUID()))
                        {
                            newamount = aur->GetStackAmount();
                            if (newamount > 0)
                                newamount += amount;

                            if (newamount > 100)
                                newamount = 100;

                            if (newamount <= 0)
                                target->RemoveAurasDueToSpell(SPELL_SANITY);
                            else
                                aur->SetStackAmount(newamount);
                        }
                    }
            }

            void OnApply_ShatteredIllusions()
            {
                if (_phase == PHASE_BRAIN)
                {
                    // Apply aura to all npc in the area except the brain, since this is still casting. The aura can only be applied in Phase 2.
                    if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                        yogg->AI()->DoAction(ACTION_APPLY_SHATTERED_ILLUSIONS);

                    if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                        yoggbrain->AI()->DoAction(ACTION_APPLY_SHATTERED_ILLUSIONS);

                    if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                        sara->AI()->DoAction(ACTION_APPLY_SHATTERED_ILLUSIONS);

                    // search for tentacles manually, they have been summoned by spells
                    std::list<Creature*> TentacleList;
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CORRUPTOR_TENTACLE, 100.0f);
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CRUSHER_TENTACLE, 100.0f);
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CONSTRICTOR_TENTACLE, 100.0f);

                    if (!TentacleList.empty())
                        for (std::list<Creature*>::iterator itr = TentacleList.begin(); itr != TentacleList.end(); itr++)
                            me->AddAura(SPELL_SHATTERED_ILLUSIONS, (*itr));
                }
            }

            void OnRemove_ShatteredIllusions(bool causedByPhaseChange)
            {
                if (_phase == PHASE_BRAIN)
                {
                    if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                        yoggbrain->AI()->DoAction(causedByPhaseChange ? ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE : ACTION_REMOVE_SHATTERED_ILLUSIONS);

                    if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                        yogg->AI()->DoAction(causedByPhaseChange ? ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE : ACTION_REMOVE_SHATTERED_ILLUSIONS);
                    
                    if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                        sara->AI()->DoAction(causedByPhaseChange ? ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE : ACTION_REMOVE_SHATTERED_ILLUSIONS);

                    // search for tentacles manually, they have been summoned by spells
                    std::list<Creature*> TentacleList;
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CORRUPTOR_TENTACLE, 100.0f);
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CRUSHER_TENTACLE, 100.0f);
                    me->GetCreatureListWithEntryInGrid(TentacleList, NPC_CONSTRICTOR_TENTACLE, 100.0f);

                    if (!TentacleList.empty())
                        for (std::list<Creature*>::iterator itr = TentacleList.begin(); itr != TentacleList.end(); itr++)
                            (*itr)->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                }
            }

            void SetSanityAura(bool remove = false)
            {
                if (me->GetMap())
                    if (me->GetMap()->IsDungeon())
                    {
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        if (!players.isEmpty())
                            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* player = itr->getSource())
                                {
                                    if (player->isAlive())
                                    {
                                        if (!remove)
                                        {
                                            me->AddAura(SPELL_SANITY, player);
                                            me->SetAuraStack(SPELL_SANITY, player, 100);
                                        }
                                        else
                                        {
                                            player->RemoveAurasDueToSpell(SPELL_SANITY);
                                        }
                                    }
                                }
                    }
            }

            void SummonMadnessEventNPCs()
            {
                _listEventNPCs.clear();
                uint32 npcIndex = 0, npcAmount = 0;

                switch (_currentBrainEventPhase)
                {
                    case PORTAL_PHASE_KING_LLIANE:
                        npcIndex = 0;
                        npcAmount = 2;
                        break;
                    case PORTAL_PHASE_DRAGON_SOUL:
                        npcIndex = 2;
                        npcAmount = 4;
                        break;
                    case PORTAL_PHASE_LICH_KING:
                        npcIndex = 6;
                        npcAmount = 3;
                        break;
                    default:
                        break;
                }

                for (uint8 i = 0; i < npcAmount; i++)
                {
                    if (EventNpcEntrys[npcIndex+i] == OBJECT_THE_DRAGON_SOUL)
                    {
                        if (GameObject* obj = me->SummonGameObject(EventNpcEntrys[npcIndex+i], EventNpcLocation[npcIndex+i].GetPositionX(), EventNpcLocation[npcIndex+i].GetPositionY(), EventNpcLocation[npcIndex+i].GetPositionZ(), 0, 0, 0, 0, 0, 40*IN_MILLISECONDS))
                        {
                            obj->setActive(true);
                            EventNPC info = { obj->GetEntry(), obj->GetGUID() };
                            _listEventNPCs.push_back(info);
                        }
                    }
                    else
                    {
                        if (Creature* temp = DoSummon(EventNpcEntrys[npcIndex+i], EventNpcLocation[npcIndex+i], 1*MINUTE*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                        {
                            temp->setActive(true);
                            EventNPC info = { temp->GetEntry(), temp->GetGUID() };
                            switch (info.entry)
                            {
                                case NPC_BUNNY_GARONA_VISION:
                                    temp->SetStandState(UNIT_STAND_STATE_KNEEL);
                                    break;
                                default:
                                    break;
                            }
                            _listEventNPCs.push_back(info);
                        }
                    }
                }
            }

            void UpdatePhase(Phases newPhase)
            {
                if (_phase == newPhase)
                    return;

                // events.Reset(); // Clear on phase change
                events.SetPhase(newPhase);

                switch (newPhase)
                {
                    case PHASE_SARA:
                        {
                            DoSpawnKeeperForSupport();
                            SetSanityAura();
                            _keeperActiveCnt = CountKeepersActive();
                            if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            {
                                yogg->SetLootMode(LOOT_MODE_DEFAULT);
                                if (_keeperActiveCnt <= 3)
                                    yogg->AddLootMode(LOOT_MODE_HARD_MODE_1);
                                if (_keeperActiveCnt <= 2)
                                    yogg->AddLootMode(LOOT_MODE_HARD_MODE_2);
                                if (_keeperActiveCnt <= 1)
                                    yogg->AddLootMode(LOOT_MODE_HARD_MODE_3);
                                if (_keeperActiveCnt == 0)
                                    yogg->AddLootMode(LOOT_MODE_HARD_MODE_4);
                                yogg->AI()->SetData(ACTION_DO_CHANGE_PHASE, PHASE_SARA);
                            }
                        }
                        break;
                    case PHASE_BRAIN:
                        SpawnClouds(false);
                        _brainEventsCount = 0;
                        events.ScheduleEvent(EVENT_DESCENT_TO_MADNESS_BEGIN, 1.5*MINUTE*IN_MILLISECONDS, 0, newPhase);
                        if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                            sara->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case PHASE_YOGG:
                        if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                            sara->AI()->SetData(ACTION_DO_CHANGE_PHASE, PHASE_YOGG);
                        if (Creature* yogg = ObjectAccessor::GetCreature(*me, _guidYogg))
                            yogg->AI()->SetData(ACTION_DO_CHANGE_PHASE, PHASE_YOGG);
                        if (Creature* yoggbrain = ObjectAccessor::GetCreature(*me, _guidYoggBrain))
                            yoggbrain->InterruptNonMeleeSpells(true); 
                        OnRemove_ShatteredIllusions(true);
                        break;
                    default:
                        break;
                }
                _phase = newPhase;
            }

            private:
                Phases _phase;
                std::list<EventNPC> _listEventNPCs;
                SummonList _guidEventTentacles;
                SummonList _guidEventSkulls;
                bool _usedMindcontrol;
                uint64 _guidYogg;
                uint64 _guidYoggBrain;
                uint32 _keeperActiveCnt;

                // Phase 2
                Actions _lastBrainAction;
                uint32 _brainEventsCount;
                BrainEventPhase _currentBrainEventPhase;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_yogg_saron_encounter_controllerAI>(pCreature);
        }
};

class boss_sara : public CreatureScript
{
    public:
        boss_sara() : CreatureScript("boss_sara") {}

        struct boss_saraAI : public BossAI
        {
            boss_saraAI(Creature *c) : BossAI(c, BOSS_SARA)
            {
                me->SetCanFly(true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_DEATH_GRIP, true); 
            }

            void Reset()
            {
                _Reset();

                me->InterruptNonMeleeSpells(false);
                me->GetMotionMaster()->MoveTargetedHome();

                me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                me->RemoveAurasDueToSpell(SPELL_SARA_SHADOWY_BARRIER);

                // Remove Random MoveMaster
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveIdle();

                // Reset Display
                me->setFaction(FACTION_FRIENDLY);
                me->SetVisible(true);
                me->SetDisplayId(me->GetNativeDisplayId());
                me->RemoveAurasDueToSpell(SPELL_SARA_TRANSFORMATION);
                // Reset Health
                me->SetHealth(me->GetMaxHealth());
                // Remove Not Attackable Flags
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                // Reset Phase
                _phase = PHASE_NONE;

                if (instance->GetBossState(BOSS_VEZAX) == DONE)
                    events.ScheduleEvent(EVENT_RANDOM_YELL, urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS));
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }

            void ReceiveEmote(Player* pPlayer, uint32 emote)
            {
                if (_phase >= PHASE_BRAIN)
                {
                    if (emote == TEXT_EMOTE_KISS)
                    {
                        if (pPlayer->HasAchieved(RAID_MODE(ACHIEVMENT_KISS_AND_MAKE_UP_10, ACHIEVMENT_KISS_AND_MAKE_UP_25)))
                            return;

                        if (me->IsWithinLOS(pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ()) && me->IsWithinDistInMap(pPlayer, 30.0f))
                        {
                            if (AchievementEntry const* achievKissAndMakeUp = GetAchievementStore()->LookupEntry(RAID_MODE(ACHIEVMENT_KISS_AND_MAKE_UP_10, ACHIEVMENT_KISS_AND_MAKE_UP_25)))
                                pPlayer->CompletedAchievement(achievKissAndMakeUp);
                        }
                    }
                }
            }

            void DamageTaken(Unit* /*dealer*/, uint32 &damage)
            {
                if (damage > me->GetHealth())
                    damage = me->GetHealth() - 1;
            }                        

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SARA_SLAY);
            }

            void EnterCombat(Unit* /*target*/)
            {
                me->setActive(true);
                DoZoneInCombat();
                _guidYogg = instance->GetData64(BOSS_YOGGSARON);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (target)
                    if (target->ToPlayer())
                    {
                        switch (spell->Id)
                        {
                            case SPELL_PSYCHOSIS:
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(), -12);
                                break;
                            case SPELL_BRAIN_LINK_DAMAGE:
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(), -2);
                                break;
                            case SPELL_MALADY_OF_MIND:
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(), -3);
                                break;
                            default:
                                break;
                        }
                    }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (!spell)
                    return;

                if (spell->Id == SPELL_SHADOW_NOVA_SARA)
                {
                    if (_phase != PHASE_SARA)
                        return;

                    if (Creature* sara = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_SARA)))
                    {
                        if (sara->GetHealth() <= 1.f)
                        {
                            if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                ctrl->AI()->SetData(ACTION_DO_CHANGE_PHASE, PHASE_BRAIN);
                            UpdatePhase(PHASE_BRAIN);
                        }
                    }
                }
            }

            void MovementInform(uint32 type, uint32 i)
            {
                if (type == POINT_MOTION_TYPE && i == 1)
                {
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                }
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_START_SARA:
                        UpdatePhase(PHASE_SARA);
                        break;
                    case ACTION_MADNESS_STARTED:
                        _eventSpeakingPhase = 0;
                        events.ScheduleEvent(EVENT_EVTSPEAKING, 6*IN_MILLISECONDS);
                        break;  
                    case ACTION_APPLY_SHATTERED_ILLUSIONS:
                        me->AddAura(SPELL_SHATTERED_ILLUSIONS, me);
                        events.CancelEventGroup(ID_GROUP_NON_SHATTERED);
                        break;
                    case ACTION_REMOVE_SHATTERED_ILLUSIONS:
                        me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                        events.ScheduleEvent(EVENT_PSYCHOSIS, 5*IN_MILLISECONDS, ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                        events.ScheduleEvent(EVENT_MINDSPELL, 30*IN_MILLISECONDS, ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                        break;
                    case ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE:    // Nothing special to be done
                        me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 val)
            {
                switch (type)
                {
                    case ACTION_DO_CHANGE_PHASE:
                        UpdatePhase(static_cast<Phases>(val));
                        break;
                    default:
                        break;
                }
            }
            
            void UpdatePhase(Phases newPhase)
            {
                if (_phase == newPhase)
                    return;

                // events.Reset(); // Clear on phase change
                events.SetPhase(newPhase);

                switch (newPhase)
                {
                    case PHASE_SARA:
                        Talk(SAY_SARA_AGGRO);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        events.ScheduleEvent(EVENT_SARAHS_HELP, urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS), 0, PHASE_SARA);
                        break;
                    case PHASE_BRAIN:
                        me->SetHealth(me->GetMaxHealth());
                        _speakingPhase = 0;
                        events.ScheduleEvent(EVENT_SPEAKING, 1*IN_MILLISECONDS, 0, newPhase);
                        _eventSpeakingPhase = 0;
                        events.ScheduleEvent(EVENT_RANDOM_YELL, 35*IN_MILLISECONDS);
                        if (Player* target = SelectPlayerTargetInRange(me, 100.0f))
                            EnterCombat(target);
                        break;
                    case PHASE_YOGG:
                        me->SetVisible(false);
                        summons.DespawnEntry(NPC_BRAIN_PORTAL);
                        break;
                    default:
                        break;
                }
                _phase = newPhase;
            }

            void SaraRandomYell()
            {
                switch (_phase)
                {
                    case PHASE_NONE: 
                        Talk(SAY_SARA_PREFIGHT);
                        break;
                    case PHASE_SARA: 
                        Talk(SAY_SARA_PHASE1);
                        break;
                    case PHASE_BRAIN:
                        Talk(SAY_SARA_PHASE2);
                        break;
                    default:
                        break;
                }
            }

            Creature* GetRandomEntryTarget(uint32 entry, float range = 100.0f)
            {
                std::list<Creature*> TargetList;
                me->GetCreatureListWithEntryInGrid(TargetList, entry, range);
                if (TargetList.empty())
                    return 0;

                std::list<Creature*>::iterator itr = TargetList.begin();
                advance(itr, urand(0, TargetList.size()-1));
                return (*itr);
            }

            uint32 DoEventSpeaking(BrainEventPhase phase, uint32 part)
            {
                uint64 npcguid = 0;
                uint32 speachindex = 0;
                switch (phase)
                {
                    case PORTAL_PHASE_KING_LLIANE:
                        speachindex = 0;
                        break;
                    case PORTAL_PHASE_LICH_KING:
                        speachindex = 8;
                        break;
                    case PORTAL_PHASE_DRAGON_SOUL:
                        speachindex = 14;
                        break;
                    default:
                        break;
                }

                if (phase + speachindex > 18)
                    return 5000;

                if (EventNpcSpeaching[speachindex+part].npc_entry != NPC_YOGG_SARON)
                {
                    if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                        npcguid = ctrl->AI()->GetGUID(EventNpcSpeaching[speachindex + part].npc_entry);
                }
                else
                    npcguid = _guidYogg;

                if (Creature* speaker = ObjectAccessor::GetCreature(*me, npcguid))
                    speaker->AI()->Talk(EventNpcSpeaching[speachindex + part].speech_entry);

                return EventNpcSpeaching[speachindex+part].next_speech;
            }

            void UpdateAI(const uint32 diff)
            {
                if (_phase == PHASE_NONE)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Events in any phase
                        case EVENT_RANDOM_YELL:
                            SaraRandomYell();
                            events.ScheduleEvent(EVENT_RANDOM_YELL, urand(40*IN_MILLISECONDS, 60*IN_MILLISECONDS));
                            return;
                        
                        // Events in PHASE_SARA
                        case EVENT_SARAHS_HELP:
                            switch (urand(0,2))
                            {
                                case 0:
                                    if (Player* target = SelectPlayerTargetInRange(me, 500.0f))
                                        if (!IsPlayerInBrainRoom(target))
                                            DoCast(target, SPELL_SARAS_FERVOR, true);
                                    break;
                                case 1:
                                    if (Player* target = SelectPlayerTargetInRange(me, 500.0f))
                                        if (!IsPlayerInBrainRoom(target))
                                            DoCast(target, SPELL_SARAS_BLESSING, true);
                                    break;
                                case 2:
                                    if (Unit* target = GetRandomEntryTarget(NPC_GUARDIAN_OF_YOGG_SARON, 500.0f))
                                        DoCast(target, SPELL_SARAS_ANGER, true);
                                    break;
                                default: 
                                    break;
                            }
                            events.ScheduleEvent(EVENT_SARAHS_HELP, urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS), 0, PHASE_SARA);
                            return;

                        // events in PHASE_BRAIN
                        case EVENT_SPEAKING:
                            {
                                events.CancelEvent(EVENT_RANDOM_YELL);
                                uint32 nextEventTime = 0;
                                switch (_speakingPhase)
                                {
                                    case 0:
                                        Talk(SAY_SARA_PHASE2_1);
                                        nextEventTime = 5*IN_MILLISECONDS;
                                        break;
                                    case 1:
                                        Talk(SAY_SARA_PHASE2_2);
                                        nextEventTime = 5*IN_MILLISECONDS;
                                        break;
                                    case 2:
                                        Talk(SAY_SARA_PHASE2_3);
                                        nextEventTime = 4*IN_MILLISECONDS;
                                        break;
                                    case 3:
                                        Talk(SAY_SARA_PHASE2_4);
                                        nextEventTime = 4*IN_MILLISECONDS;
                                        break;
                                    case 4:
                                        me->AddAura(SPELL_SARA_TRANSFORMATION, me);
                                        DoCast(me,SPELL_SARA_SHADOWY_BARRIER, false);
                                        me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+20);
                                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                        if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                            ctrl->AI()->DoAction(ACTION_ACTIVATE_YOGG);

                                        me->setFaction(FACTION_HOSTILE);
                                        break;
                                    default:
                                        break;
                                }
                                if (_speakingPhase < 4)
                                    events.ScheduleEvent(EVENT_SPEAKING, nextEventTime);
                                _speakingPhase++;
                            }
                            return;
                        case EVENT_EVTSPEAKING:
                            if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                                events.RescheduleEvent(EVENT_EVTSPEAKING, DoEventSpeaking(static_cast<BrainEventPhase>(ctrl->AI()->GetData(DATA_PORTAL_PHASE)), _eventSpeakingPhase), 0, PHASE_BRAIN);
                            _eventSpeakingPhase++;
                            return;
                        case EVENT_PSYCHOSIS:
                            if (Player* target = SelectPlayerTargetInRange(me, 500.0f))
                                if (!IsPlayerInBrainRoom(target))
                                    DoCast(target, SPELL_PSYCHOSIS, false);
                            events.ScheduleEvent(EVENT_PSYCHOSIS, 5*IN_MILLISECONDS, 0, PHASE_BRAIN);
                            return;
                        case EVENT_MINDSPELL:
                            switch (urand(0, 2))
                            {
                                case 0:
                                    DoCast(SPELL_MALADY_OF_MIND);
                                    break;
                                case 1:
                                    DoCast(SPELL_BRAIN_LINK);
                                    break;
                                case 2:
                                    DoCast(SPELL_DEATH_RAY_SUMMON);
                                    break;
                            }
                            events.ScheduleEvent(EVENT_MINDSPELL, 30*IN_MILLISECONDS, 0, PHASE_BRAIN);
                            return;
                        default:
                            return;
                    }
                }

                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_YOGGSARON_CTRL)))
                    if (_phase != PHASE_NONE && !(ctrl->AI()->GetData(DATA_IS_ENCOUNTER_IN_PROGRESS)))
                    {
                        ctrl->AI()->DoAction(ACTION_WIPE);
                        EnterEvadeMode();
                    }

                // temporary
                if (_phase == PHASE_NONE && me->isInCombat())
                    EnterEvadeMode();
            }

            private:
                Phases _phase;

                uint64 _guidYogg;
                uint64 _guidYoggBrain;

                // Phase 2
                uint32 _speakingPhase;

                uint32 _eventSpeakingPhase;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<boss_saraAI>(pCreature);
        }
};

class npc_ominous_cloud : public CreatureScript
{
    public:
        npc_ominous_cloud() : CreatureScript("npc_ominous_cloud") {}

        struct npc_ominous_cloudAI : public ScriptedAI
        {
            npc_ominous_cloudAI(Creature* c) : ScriptedAI(c)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_DEATH_GRIP, true); 
                _instance = c->GetInstanceScript();
            }

            void Reset()
            {
                me->RemoveAurasDueToSpell(SPELL_SUMMON_GUARDIAN);
                me->RemoveAurasDueToSpell(SPELL_OMINOUS_CLOUD_EFFECT);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->GetMotionMaster()->MoveRandom(25.0f);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                _spawned = false;
                _dying = false;
            }

            void MoveInLineOfSight(Unit* target)
            {
                if (_instance && _instance->GetBossState(BOSS_YOGGSARON) == IN_PROGRESS)
                    if (target && me->GetDistance2d(target) <= 9.f && target->ToPlayer() && !target->ToPlayer()->isGameMaster() && !target->HasAura(SPELL_FLASH_FREEZE))
                        TriggerGuardianSpawn();
            }

            void AttackStart(Unit* /*attacker*/) {}

            void DoAction(const int32 action)
            {
                switch(action)
                {
                    case ACTION_ACTIVATE_CLOUDS:
                        Reset();
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoCast(me, SPELL_OMINOUS_CLOUD_EFFECT, true);
                        break;
                    default:
                        break;
                }
            }

            void TriggerGuardianSpawn()
            {
                if (!_spawned)
                {
                    if (!me->HasAura(SPELL_SUMMON_GUARDIAN))
                    {
                        DoCast(me, SPELL_SUMMON_GUARDIAN, true);
                        _spawned = true;
                    }
                }
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                if (!me->HasAura(SPELL_SUMMON_GUARDIAN) && _spawned && !_dying)
                {
                    me->RemoveAurasDueToSpell(SPELL_OMINOUS_CLOUD_EFFECT);
                    me->DespawnOrUnsummon(2*IN_MILLISECONDS);
                    _dying = true;
                    if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                        CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->SpawnClouds(true);
                }
            }

            private:
                InstanceScript* _instance;
                bool _spawned;
                bool _dying;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_ominous_cloudAI>(pCreature);
        }
};

class npc_guardian_of_yogg_saron : public CreatureScript
{
    public:
        npc_guardian_of_yogg_saron() : CreatureScript("npc_guardian_of_yogg_saron") {}

        struct npc_guardian_of_yogg_saronAI : public ScriptedAI
        {
            npc_guardian_of_yogg_saronAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                me->setFaction(FACTION_HOSTILE);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (target)
                    if (target->ToPlayer())
                    {
                        switch (spell->Id)
                        {
                            case SPELL_DARK_VOLLEY:
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(), -2);
                                break;
                            default:
                                break;
                        }
                    }
            }

            void JustDied(Unit* /*killer*/)
            {
                DoCast(me, SPELL_SHADOW_NOVA, true);
                DoCast(me, SPELL_SHADOW_NOVA_SARA, true);
                me->DespawnOrUnsummon(5*IN_MILLISECONDS);
            }

            void Reset()
            {
                _darkVolleyTimer = urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                if (Player* target = SelectPlayerTargetInRange(me, 100.0f))
                    me->AI()->AttackStart(target);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    me->DealDamage(me, me->GetMaxHealth());
                    me->RemoveCorpse();
                    return;
                }

                if (_darkVolleyTimer <= diff)
                {
                    DoCast(SPELL_DARK_VOLLEY);
                    _darkVolleyTimer = urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                }
                else 
                    _darkVolleyTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _darkVolleyTimer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_guardian_of_yogg_saronAI>(pCreature);
        }
};

class npc_yogg_saron_tentacle : public CreatureScript
{
    public:
        npc_yogg_saron_tentacle() : CreatureScript("npc_yogg_saron_tentacle") {}

        struct npc_yogg_saron_tentacleAI : public ScriptedAI
        {
            npc_yogg_saron_tentacleAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                SetTentacleType(c->GetEntry());
                _once = false;
                me->setFaction(FACTION_HOSTILE);
                me->SetCanFly(true);
            }
        
            void SetTentacleType(uint32 entry)
            {
                switch(entry)
                {
                    case NPC_CRUSHER_TENTACLE: 
                        _tentacleType = CRUSHER_TENTACLE;
                        break;
                    case NPC_CORRUPTOR_TENTACLE: 
                        _tentacleType = CORRUPTOR_TENTACLE;
                        break;
                    case NPC_CONSTRICTOR_TENTACLE: 
                        _tentacleType = CONSTRICTOR_TENTACLE;
                        break;
                    default: 
                        _tentacleType = CORRUPTOR_TENTACLE;
                        break;
                }
            }

            void MoveInLineOfSight(Unit* target)
            {
                // TODO: Check if this does not lead to a target-selection-lock
                if (target && (me->GetDistance2d(target) <= me->GetMeleeReach()) && target->ToPlayer() && !target->ToPlayer()->isGameMaster())
                    AttackStartNoMove(target);
            }

            void AttackStart(Unit* /*target*/) {}

            void JustDied(Unit* /*killer*/)
            {
                me->RemoveAurasDueToSpell(SPELL_TENTACLE_VOID_ZONE);
                me->DespawnOrUnsummon(5*IN_MILLISECONDS);
            }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
            {
                if (apply)
                    who->CastSpell(who, RAID_MODE(SPELL_SQUEEZE_10, SPELL_SQUEEZE_25), true, NULL, NULL, me->GetGUID());
                else
                    who->RemoveAurasDueToSpell(RAID_MODE(SPELL_SQUEEZE_10, SPELL_SQUEEZE_25));
            }

            void Reset()
            {
                if (Unit* target = SelectPlayerTargetInRange(me, 500.0f))
                    AttackStartNoMove(target);
                DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();
                _tentacleSpellTimer = urand(5*IN_MILLISECONDS,10*IN_MILLISECONDS);
                switch(_tentacleType)
                {
                    case CRUSHER_TENTACLE:
                        DoCast(me, SPELL_CRUSH, true);
                        DoCast(SPELL_FOCUS_ANGER);
                        break;
                    case CONSTRICTOR_TENTACLE:
                        _tentacleSpellTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                {
                    me->DealDamage(me,me->GetMaxHealth());
                    me->RemoveCorpse();
                }

                if (!_once)
                {
                    DoCast(SPELL_ERUPT);
                    _once = true;
                }

                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (_tentacleSpellTimer <= diff)
                {
                    switch(_tentacleType)
                    {
                        case CRUSHER_TENTACLE:
                            if (!me->HasAura(SPELL_DIMISH_POWER))
                                DoCast(SPELL_DIMISH_POWER);
                            return;
                        case CORRUPTOR_TENTACLE:
                            if (Unit* target = SelectPlayerTargetInRange(me, 500.0f))
                                DoCast(target, RAND(SPELL_DRAINING_POISON, SPELL_BLACK_PLAGUE, SPELL_APATHY, SPELL_CURSE_OF_DOOM), false);
                            return;
                        case CONSTRICTOR_TENTACLE:
                            if (Unit* target =  SelectPlayerTargetInRange(me, 50.0f))
                                target->CastSpell(me, SPELL_LUNGE, true);
                            return;
                        default:
                            return;
                    }
                    _tentacleSpellTimer = urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS);
                }
                else 
                    _tentacleSpellTimer -= diff;

                if (_tentacleType == CRUSHER_TENTACLE)
                    DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                TentacleType _tentacleType;
                bool _once;
                uint32 _tentacleSpellTimer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_yogg_saron_tentacleAI>(pCreature);
        }
};

class npc_descend_into_madness : public CreatureScript
{
    public:
        npc_descend_into_madness() : CreatureScript("npc_descend_into_madness") { }

        bool OnGossipHello(Player* pPlayer,Creature* pCreature)
        {
            pPlayer->PlayerTalkClass->ClearMenus();

            bool AcceptTeleport = false;
            Position posTeleportPosition;
            //pPlayer->NearTeleportTo();
            BrainEventPhase pTemp = PORTAL_PHASE_BRAIN_NONE;
            if (pCreature && pCreature->AI())
                pTemp = CAST_AI(npc_descend_into_madnessAI, pCreature->AI())->bPhase;

            switch(pTemp)
            {
                case PORTAL_PHASE_KING_LLIANE:
                case PORTAL_PHASE_DRAGON_SOUL:
                case PORTAL_PHASE_LICH_KING:
                    AcceptTeleport = true;
                    posTeleportPosition = InnerBrainLocation[pTemp];
                    break;
                default: 
                    AcceptTeleport = false; 
                    break;
            }

            if (AcceptTeleport)
            {
                if (pPlayer)
                {
                    pPlayer->RemoveAurasDueToSpell(SPELL_BRAIN_LINK);
                    pCreature->AddAura(SPELL_ILLUSION_ROOM, pPlayer);
                    pPlayer->NearTeleportTo(posTeleportPosition.m_positionX, posTeleportPosition.m_positionY, posTeleportPosition.m_positionZ, posTeleportPosition.m_orientation, true);
                    //pPlayer->CastSpell(pPlayer,SPELL_TELEPORT,true);
                    CAST_AI(npc_descend_into_madnessAI, pCreature->AI())->bPhase = PORTAL_PHASE_BRAIN_NONE;
                    AcceptTeleport = false;
                    pPlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_ILLUSION_ROOM);
                    pCreature->DespawnOrUnsummon(0.5*IN_MILLISECONDS);
                }
            }

            return true;
        };

        struct npc_descend_into_madnessAI : public ScriptedAI
        {
            npc_descend_into_madnessAI(Creature *c) : ScriptedAI(c) {}

            BrainEventPhase bPhase;

            void DoAction(const int32 action)
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                switch(action)
                {
                    case ACTION_PORTAL_TO_MADNESS_STORMWIND:
                        bPhase = PORTAL_PHASE_KING_LLIANE;
                        break;
                    case ACTION_PORTAL_TO_MADNESS_DRAGON:
                        bPhase = PORTAL_PHASE_DRAGON_SOUL;
                        break;
                    case ACTION_PORTAL_TO_MADNESS_LICHKING:
                        bPhase = PORTAL_PHASE_LICH_KING;
                        break;
                    default:
                        break;
                }
            }

            void Reset()
            {
                bPhase = PORTAL_PHASE_BRAIN_NONE;
            }

            void UpdateAI(uint32 const /*diff*/) {}
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_descend_into_madnessAI>(pCreature);
        }
};

class boss_brain_of_yogg_saron : public CreatureScript
{
    public:
        boss_brain_of_yogg_saron() : CreatureScript("boss_brain_of_yogg_saron") {}

        struct boss_brain_of_yogg_saronAI : public ScriptedAI
        {
            boss_brain_of_yogg_saronAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(FACTION_HOSTILE);
                me->SetCanFly(true);
                me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY);
            }

            void Reset()
            {
                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                {
                    if (ctrl->isInCombat())
                        EnterCombat(ctrl->getVictim());
                }
            }

            void DamageTaken(Unit* /*dealer*/, uint32 &damage)
            {
                if (HealthBelowPct(31)) // "immortality" is not granted if not yet in phase 3 (starts when health gets below 31%)
                    if (damage > me->GetHealth())
                        damage = me->GetHealth()-1;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_APPLY_SHATTERED_ILLUSIONS:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    case ACTION_REMOVE_SHATTERED_ILLUSIONS:
                    case ACTION_REMOVE_SHATTERED_ILLUSIONS_PHASE_CHANGE:
                        me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                        me->InterruptNonMeleeSpells(true);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (!target->ToPlayer())
                    return;

                if (spell->Id == SPELL_INDUCE_MADNESS)
                {
                    if (IsPlayerInBrainRoom(target->ToPlayer()))
                        target->RemoveAurasDueToSpell(SPELL_SANITY);
                }
            }            

            void UpdateAI(uint32 const /*diff*/)
            {
                if (HealthBelowPct(31))
                {
                    if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                            ctrl->AI()->DoAction(ACTION_BRAIN_UNDER_30_PERCENT);

                    if (!me->HasAura(SPELL_BRAIN_HURT_VISUAL))
                        DoCast(me, SPELL_BRAIN_HURT_VISUAL, true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<boss_brain_of_yogg_saronAI>(pCreature);
        }
};

class boss_yogg_saron : public CreatureScript
{
    public:
        boss_yogg_saron() : CreatureScript("boss_yogg_saron") {}    

        struct boss_yogg_saronAI : public ScriptedAI
        {
            boss_yogg_saronAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_SWIMMING);
            }            

            void Reset()
            {
                _events.Reset();
                _events.SetPhase(PHASE_NONE);
                _usedMindcontrol = false;
                _phase = PHASE_NONE;
                _events.ScheduleEvent(EVENT_SANITY_CHECK, 1*IN_MILLISECONDS);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                    ctrl->AI()->DoAction(ACTION_YOGGSARON_KILLED);
                Talk(SAY_DEATH);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_ENTER_COMBAT:
                        if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                            EnterCombat(ctrl->getVictim());
                        break;
                    case ACTION_APPLY_SHATTERED_ILLUSIONS:
                        me->AddAura(SPELL_SHATTERED_ILLUSIONS, me);
                        _events.CancelEvent(ID_GROUP_NON_SHATTERED);
                        break;
                    case ACTION_REMOVE_SHATTERED_ILLUSIONS:
                        me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                        _events.RescheduleEvent(EVENT_TENTACLE, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS), ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                        _events.RescheduleEvent(EVENT_TENTACLE_1, 1*IN_MILLISECONDS, ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void SetData(uint32 type, uint32 val)
            {
                switch (type)
                {
                    case ACTION_DO_CHANGE_PHASE:
                        switch (val)
                        {
                            case PHASE_SARA:
                                _phase = PHASE_SARA;
                                break;
                            case PHASE_BRAIN:
                                _phase = PHASE_BRAIN;
                                _events.SetPhase(_phase);
                                _events.ScheduleEvent(EVENT_TENTACLE, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS), ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                                _events.ScheduleEvent(EVENT_TENTACLE_1, 1*IN_MILLISECONDS, ID_GROUP_NON_SHATTERED, PHASE_BRAIN);
                                break;
                            case PHASE_YOGG:
                                // Publicly visible phase-change
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                me->LowerPlayerDamageReq(static_cast<uint32>(me->GetMaxHealth() * 0.3f));
                                me->SetHealth(me->CountPctFromMaxHealth(30));
                                me->RemoveAurasDueToSpell(SPELL_SHADOWY_BARRIER);
                                me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                                Talk(SAY_VISION);
                                me->AddAura(SPELL_YOGG_SARON_TRANSFORMATION, me);

                                // Internal phase-change
                                _phase = PHASE_YOGG;
                                _events.SetPhase(PHASE_YOGG);
                                _events.ScheduleEvent(EVENT_LUNATIC_GAZE, 12*IN_MILLISECONDS, 0, _phase);
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL && ctrl->AI()->GetData(DATA_KEEPER_CNT) < 4)
                                        _events.ScheduleEvent(EVENT_DEAFENING_ROAR, urand(30*IN_MILLISECONDS, 60*IN_MILLISECONDS), 0, _phase);
                                _events.ScheduleEvent(EVENT_SHADOW_BEACON, 30*IN_MILLISECONDS, 0, _phase);
                                _events.ScheduleEvent(EVENT_SUMMON_GUARDIAN_YOGG, 20*IN_MILLISECONDS, 0, _phase);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (!_instance)
                    return;

                if (target)
                    if (target->ToPlayer())
                    {
                        switch(spell->Id)
                        {
                            case SPELL_LUNATIC_GAZE_EFFECT:
                                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(), -4);
                                break;
                            default:
                                break;
                        }
                    }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_IN_THE_MAWS_OF_THE_OLD_GOD)
                    me->AddLootMode(LOOT_MODE_HARD_MODE_4);
            }

            void UpdateAI(const uint32 diff)
            {
                if ((_instance && _instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS) || _phase == PHASE_NONE )
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SANITY_CHECK:
                            if (me->GetMap())
                                if (me->GetMap()->IsDungeon())
                                {
                                    std::list<Player*> players;
                                    GetPlayersByCondition<InsaneCandidatePredicate> pred(players);
                                    pred(me);

                                    if (!players.empty())
                                        for (std::list<Player*>::iterator plr = players.begin(); plr != players.end(); ++plr)
                                        {
                                            // Tell Sara we used Mindcontrol - for Archievment ... we need only one mind-controlled Player to cancel Achievment
                                            if (!_usedMindcontrol)
                                            {
                                                if (Creature* cSara = ObjectAccessor::GetCreature(*me, _instance->GetData64(BOSS_SARA)))
                                                    cSara->AI()->DoAction(ACTION_USED_MINDCONTROL);
                                                _usedMindcontrol = true;
                                            }

                                            if (IsPlayerInBrainRoom((*plr)))
                                            {
                                                (*plr)->RemoveAurasDueToSpell(SPELL_ILLUSION_ROOM);
                                                (*plr)->NearTeleportTo(SaraLocation.GetPositionX(), SaraLocation.GetPositionY(), SaraLocation.GetPositionZ(), M_PI, false);
                                            }

                                            me->AddAura(SPELL_INSANE, (*plr));
                                            me->AddAura(SPELL_INSANE_2, (*plr));
                                            Talk(WHISP_INSANITY, (*plr)->GetUInt64Value(0));
                                        }
                                }
                            _events.ScheduleEvent(EVENT_SANITY_CHECK, 1*IN_MILLISECONDS);
                            return;
                        case EVENT_TENTACLE:
                            if (urand(0, 1) == 0)
                            {
                                if (Player* target = SelectPlayerTargetInRange(me, 500.0f))
                                    if (!IsPlayerInBrainRoom(target))
                                        target->CastSpell(target, SPELL_SUMMON_CONSTRICTOR_TENTACLES, true);
                            }
                            else
                                me->CastSpell(me, SPELL_SUMMON_CURRUPTOR_TENTACLE, true);
                            if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                            {
                                if (ctrl->AI()->GetData(DATA_BRAIN_EVT_CNT) < 4)
                                    _events.ScheduleEvent(EVENT_TENTACLE, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS), 0, PHASE_BRAIN);
                                else
                                    _events.ScheduleEvent(EVENT_TENTACLE, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS), 0, PHASE_BRAIN);
                            }
                            else
                                _events.ScheduleEvent(EVENT_TENTACLE, urand(3.5*IN_MILLISECONDS, 7.5*IN_MILLISECONDS), 0, PHASE_BRAIN);
                            return;
                        case EVENT_TENTACLE_1:
                            me->CastSpell(me, SPELL_SUMMON_CRUSHER_TENTACLE, true);
                            if (Creature* ctrl = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_YOGGSARON_CTRL)))
                            {
                                if (ctrl->AI()->GetData(DATA_BRAIN_EVT_CNT) < 4)
                                    _events.ScheduleEvent(EVENT_TENTACLE_1, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS), 0, PHASE_BRAIN);
                                else
                                    _events.ScheduleEvent(EVENT_TENTACLE_1, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS), 0, PHASE_BRAIN);
                            }
                            else
                                _events.ScheduleEvent(EVENT_TENTACLE_1, urand(20*IN_MILLISECONDS, 27.5*IN_MILLISECONDS), 0, PHASE_BRAIN);
                            return;
                        case EVENT_SUMMON_GUARDIAN_YOGG:
                            me->CastSpell(me, SPELL_SUMMON_IMMORTAL_GUARDIAN, true);
                            _events.ScheduleEvent(EVENT_SUMMON_GUARDIAN_YOGG, 15*IN_MILLISECONDS, 0, PHASE_YOGG);
                            return;
                        case EVENT_LUNATIC_GAZE:
                            me->CastSpell(me, SPELL_LUNATIC_GAZE, me);
                            _events.ScheduleEvent(EVENT_LUNATIC_GAZE, 12*IN_MILLISECONDS, 0, PHASE_YOGG);
                            return;
                        case EVENT_DEAFENING_ROAR:
                            Talk(SAY_DEAFENING_ROAR);
                            me->CastSpell(me, SPELL_DEAFENING_ROAR, false);
                            _events.ScheduleEvent(EVENT_DEAFENING_ROAR, 1*MINUTE*IN_MILLISECONDS, 0, PHASE_YOGG);
                            return;
                        case EVENT_SHADOW_BEACON:
                            me->CastSpell(me, SPELL_SHADOW_BEACON, false);
                            _events.ScheduleEvent(EVENT_SHADOW_BEACON, 3*IN_MILLISECONDS, 0, PHASE_YOGG);
                            return;
                        default:
                            return;
                    }
                }
            }

            private:
                Phases _phase;
                EventMap _events;
                InstanceScript* _instance;
                bool _usedMindcontrol;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<boss_yogg_saronAI>(pCreature);
        }
};

class npc_influence_tentacle : public CreatureScript
{
    public:
        npc_influence_tentacle() : CreatureScript("npc_influence_tentacle") {}

        struct npc_influence_tentacleAI : public ScriptedAI
        {
            npc_influence_tentacleAI(Creature *c) : ScriptedAI(c)
            {
                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->RemoveAurasDueToSpell(SPELL_TENTACLE_VOID_ZONE);
            }

            void Reset() {}

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (attacker->ToPlayer())
                    me->CastCustomSpell(SPELL_GRIM_REPRISAL_DAMAGE, SPELLVALUE_BASE_POINT0, int32(damage *0.6), attacker, true);
            }

            void EnterCombat(Unit* /*attacker*/)
            {
                if (me->GetEntry() != NPC_INFULENCE_TENTACLE)
                {
                    me->UpdateEntry(NPC_INFULENCE_TENTACLE);
                    me->setFaction(FACTION_HOSTILE);
                    //me->setRegeneratingHealth(false); // TODO: Maybe add this function
                    DoCast(SPELL_GRIM_REPRISAL);
                    DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_influence_tentacleAI>(pCreature);
        }
};

class npc_immortal_guardian : public CreatureScript
{
    public:
        npc_immortal_guardian() : CreatureScript("npc_immortal_guardian") {}

        struct npc_immortal_guardianAI : public ScriptedAI
        {
            npc_immortal_guardianAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                me->setFaction(FACTION_HOSTILE);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_DEATH_GRIP, true);
            }

            void Reset()
            {
                if (Unit* target = SelectPlayerTargetInRange(me, 100.0f))
                    me->AI()->AttackStart(target);

                _drainLifeTimer = 10*IN_MILLISECONDS;
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(5*IN_MILLISECONDS);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->Id == 64172) // Titanic Storm
                {
                    if (me->HasAura(SPELL_WEAKENED))
                        me->DealDamage(me, me->GetHealth());
                }
            }

            void DamageTaken(Unit* dealer, uint32 &damage)
            {
                if (dealer->GetGUID() == me->GetGUID())
                    return;

                if (me->GetHealth() < damage)
                    damage = me->GetHealth()-1;
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                {
                    me->DealDamage(me,me->GetMaxHealth());
                    me->RemoveCorpse();
                }

                // Note : 1 Stack is spent per 10% health; If healt is below 10%, we are no longer empowered
                uint32 stacks = std::min(uint32(me->GetHealthPct() / 10), uint32(9));
                if (stacks > 0)
                {
                    me->RemoveAurasDueToSpell(SPELL_WEAKENED);
                    if (!me->HasAura(SPELL_EMPOWERED))
                        me->AddAura(SPELL_EMPOWERED, me);
                    me->SetAuraStack(SPELL_EMPOWERED, me, stacks);
                }
                else
                {
                    me->RemoveAurasDueToSpell(SPELL_EMPOWERED);
                    if (!me->HasAura(SPELL_WEAKENED))
                        me->AddAura(SPELL_WEAKENED, me);
                }

                if (_instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                    return;

                if (!UpdateVictim())
                    return;

                if (_drainLifeTimer < diff)
                {
                    DoCast(me->getVictim(), RAID_MODE(SPELL_DRAIN_LIFE_10, SPELL_DRAIN_LIFE_25));
                    _drainLifeTimer = 35*IN_MILLISECONDS;
                }
                else 
                    _drainLifeTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _drainLifeTimer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_immortal_guardianAI>(pCreature);
        }
};

class npc_support_keeper : public CreatureScript
{
    public:
        npc_support_keeper() : CreatureScript("npc_support_keeper") {}

        struct npc_support_keeperAI : public ScriptedAI
        {
            npc_support_keeperAI(Creature *c) : ScriptedAI(c) , _summons(me)
            {
                _instance = c->GetInstanceScript();
            }

            void AttackStart(Unit* /*attacker*/) {}

            void Reset()
            {
                me->SetVisible(true);
                me->setActive(true);

                uint32 auraspell = 0;
                switch(me->GetEntry())
                {
                    case NPC_KEEPER_HODIR:
                        auraspell = SPELL_FORTITUDE_OF_FROST;
                        break;
                    case NPC_KEEPER_FREYA:
                        auraspell = SPELL_RESILIENCE_OF_NATURE;
                        break;
                    case NPC_KEEPER_THORIM:
                        auraspell = SPELL_FURY_OF_THE_STORM;
                        break;
                    case NPC_KEEPER_MIMIRON:
                        auraspell = SPELL_SPEED_OF_INVENTION;
                        break;
                    default:
                        break;
                }
                DoCast(auraspell);

                _summoning = false;
                _summoned = false;

                _secondarySpellTimer = 10*IN_MILLISECONDS;
            }

            void JustSummoned(Creature* pSummoned)
            {
                _summons.Summon(pSummoned);
            }

            void DoSummonSanityWells()
            {
                for(uint8 i = 0; i < 5 ; i++)
                    DoSummon(NPC_BUNNY_SANITY_WELL, FreyaSanityWellLocation[i], 0, TEMPSUMMON_MANUAL_DESPAWN);
            }

            void GetAliveSaronitCreatureListInGrid(std::list<Creature*>& lList, float fMaxSearchRange)
            {
                CellCoord pair(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
                Cell cell(pair);
                cell.SetNoCreate();

                AllSaronitCreaturesInRange check(me, fMaxSearchRange);
                Trinity::CreatureListSearcher<AllSaronitCreaturesInRange> searcher(me, lList, check);
                TypeContainerVisitor<Trinity::CreatureListSearcher<AllSaronitCreaturesInRange>, GridTypeMapContainer> visitor(searcher);

                cell.Visit(pair, visitor, *(me->GetMap()), *me, SIZE_OF_GRIDS);
            }

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (_secondarySpellTimer <= diff)
                {
                    switch (me->GetEntry())
                    {
                        case NPC_KEEPER_THORIM:   // Hm... what's up with killing the Undying in Phase 3? Dealt with by spell ? 
                            if (!me->HasAura(SPELL_TITANIC_STORM))
                                DoCast(SPELL_TITANIC_STORM);
                            _secondarySpellTimer = 10*IN_MILLISECONDS;
                            return;
                        case NPC_KEEPER_FREYA:
                            if (!_summoned)
                            {
                                if (!_summoning)
                                {
                                    DoCast(SPELL_SANITY_WELL);
                                    _secondarySpellTimer = 5*IN_MILLISECONDS;
                                    _summoning = true;
                                }
                                else
                                {
                                    DoSummonSanityWells();
                                    _summoned = true;
                                }
                            }
                            return;
                        case NPC_KEEPER_MIMIRON:
                            {
                                std::list<Creature*> creatureList;
                                GetAliveSaronitCreatureListInGrid(creatureList, 5*IN_MILLISECONDS);
                                if (!creatureList.empty())
                                {
                                    std::list<Creature*>::iterator itr = creatureList.begin();
                                    std::advance(itr, urand(0, creatureList.size() - 1));
                                    DoCast((*itr), SPELL_DESTABILIZATION_MATRIX, false);
                                }
                                _secondarySpellTimer = 30*IN_MILLISECONDS;
                            }
                            return;
                        case NPC_KEEPER_HODIR:
                            {
                                if (!me->HasAura(SPELL_HODIRS_PROTECTIVE_GAZE))
                                    DoCast(me, SPELL_HODIRS_PROTECTIVE_GAZE, false);
                                _secondarySpellTimer = 25*IN_MILLISECONDS;
                            }
                            return;
                        default:
                            return;
                    }
                }
                else
                {
                    if (me->GetEntry() == NPC_KEEPER_HODIR)
                    {
                        if (!me->HasAura(SPELL_HODIRS_PROTECTIVE_GAZE))  // In this case, the timer works as a cooldown manager ... check if this is correct :s
                            _secondarySpellTimer -= diff;
                    }
                    else 
                        _secondarySpellTimer -= diff;
                }
            }

            private:
                SummonList _summons;
                InstanceScript* _instance;
                uint32 _secondarySpellTimer;
                bool _summoning;
                bool _summoned;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_support_keeperAI>(pCreature);
        }
};

class npc_sanity_well : public CreatureScript
{
    public:
        npc_sanity_well() : CreatureScript("npc_sanity_well") {}

        struct npc_sanity_wellAI : public ScriptedAI
        {
            npc_sanity_wellAI(Creature *c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
            }

            void Reset()
            {
                DoCast(SPELL_SANITY_WELL_OPTIC);
                _sanityTickTimer = 2*IN_MILLISECONDS;
                me->AddAura(SPELL_SANITY_WELL_DEBUFF, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(const uint32 diff)
            {
                if (_instance && _instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                {
                    me->DealDamage(me, me->GetMaxHealth());
                    me->RemoveCorpse();
                }

                if (_sanityTickTimer <= diff)
                {
                    std::list<Player*> plrList;
                    GetNearestPlayers(10.0f, 0)(plrList, me);   // Select all players in 10.0 ::TODO: Check what was meant by GetNearestPlayers: 10.0 distance or 10 players

                    for (std::list<Player*>::const_iterator itr = plrList.begin(); itr != plrList.end(); ++itr)
                    {
                        if ((*itr))
                        {
                            if ((*itr)->HasAura(SPELL_SANITY_WELL_DEBUFF))
                            {
                                if (Creature* ctrl = ObjectAccessor::GetCreature((*me), _instance->GetData64(NPC_YOGGSARON_CTRL)))
                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity((*itr), 10);
                            }
                        }
                    }
                    _sanityTickTimer = 2*IN_MILLISECONDS;
                }
                else 
                    _sanityTickTimer -= diff;
            }

            private:
                InstanceScript* _instance;
                uint32 _sanityTickTimer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_sanity_wellAI>(pCreature);
        }
};

class npc_laughting_skull : public CreatureScript
{
    public:
        npc_laughting_skull() : CreatureScript("npc_laughting_skull") {}

        struct npc_laughting_skullAI : public ScriptedAI
        {
            npc_laughting_skullAI(Creature *c) : ScriptedAI(c)
            {
                instance = c->GetInstanceScript();
            }

            void Reset()
            {
                DoCast(SPELL_LS_LUNATIC_GAZE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (target && spell)
                    if (instance)
                        if (target->ToPlayer())
                        {
                            switch (spell->Id)
                            {
                                case SPELL_LS_LUNATIC_GAZE_EFFECT:
                                    if (Creature* ctrl = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_YOGGSARON_CTRL)))
                                        CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, ctrl->AI())->ModifySanity(target->ToPlayer(),-2);
                                    break;
                                default:
                                    break;
                            }
                        }
            }

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(uint32 const /*diff*/) {}

            private:
                InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_laughting_skullAI>(pCreature);
        }
};

class npc_death_orb : public CreatureScript
{
    public:
        npc_death_orb() : CreatureScript("npc_death_orb") {}

        struct npc_death_orbAI : public ScriptedAI
        {
            npc_death_orbAI(Creature *c) : ScriptedAI(c) , _summons(me)
            {
                _instance = c->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }        

            void Reset()
            {
                me->SetCanFly(true);
                me->setFaction(FACTION_HOSTILE);
                prepaired = false;
                _summons.DespawnAll();
                SummonDeathRays();
                _reathRayEffektTimer = 5*IN_MILLISECONDS;
                DoCast(me, SPELL_DEATH_RAY_ORIGIN_VISUAL, true);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
            }

            void SummonDeathRays()
            {
                for(uint8 i = 0; i < 4; i++)
                {
                    Position pos;
                    me->GetNearPoint2D(pos.m_positionX, pos.m_positionY, float(rand_norm()*10 + 30), float(2*M_PI*rand_norm()));
                    pos.m_positionZ = me->GetPositionZ();
                    pos.m_positionZ = me->GetMap()->GetHeight(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, 500.0f);
                    DoSummon(NPC_BUNNY_DEATH_RAY, pos, 20*IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN);
                }
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                _summons.Despawn(summon);
            }

            void JustSummoned(Creature* pSummoned)
            {
                switch(pSummoned->GetEntry())
                {
                    case NPC_BUNNY_DEATH_RAY:
                        pSummoned->setFaction(FACTION_HOSTILE);
                        pSummoned->CastSpell(pSummoned, SPELL_DEATH_RAY_WARNING_VISUAL, true, 0, 0, me->GetGUID());
                        pSummoned->SetReactState(REACT_PASSIVE);
                        pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
                _summons.Summon(pSummoned);
            }

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(const uint32 diff)
            {
                if (_reathRayEffektTimer <= diff)
                {
                    for(std::list<uint64>::iterator itr = _summons.begin(); itr != _summons.end(); ++itr)
                    {
                        if (Creature* temp = ObjectAccessor::GetCreature(*me,*itr))
                        {
                            temp->CastSpell(temp, SPELL_DEATH_RAY_PERIODIC, true);
                            temp->CastSpell(temp, SPELL_DEATH_RAY_DAMAGE_VISUAL, true, 0, 0, me->GetGUID());
                            temp->AI()->DoAction(ACTION_DEATH_RAY_MOVE);
                        }
                    }
                    _reathRayEffektTimer = 30*IN_MILLISECONDS;
                }
                else 
                    _reathRayEffektTimer -= diff;
            }

            private:
                SummonList _summons;
                InstanceScript* _instance;
                bool prepaired;
                uint32 _reathRayEffektTimer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_death_orbAI>(pCreature);
        }
};

class npc_death_ray : public CreatureScript
{
    public:
        npc_death_ray() : CreatureScript("npc_death_ray") {}

        struct npc_death_rayAI : public ScriptedAI
        {
            npc_death_rayAI(Creature *c) : ScriptedAI(c) {}

            void Reset()
            {
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->SendMovementFlagUpdate();
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_DEATH_RAY_MOVE)
                    _movingDisabled = false;
            }

            void DoRandomMove()
            {
                Position pos;
                me->GetNearPoint2D(pos.m_positionX, pos.m_positionY, 10.0f, static_cast<float>(2*M_PI*rand_norm()));
                pos.m_positionZ = me->GetPositionZ();
                pos.m_positionZ = me->GetMap()->GetHeight(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, 50.0f);
                me->GetMotionMaster()->MovePoint(1, pos);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == 1)
                    _movingDisabled = false;
            }

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!_movingDisabled)
                {
                    DoRandomMove();
                    _movingDisabled = true;
                }
            }

            private:
                bool _movingDisabled;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_death_rayAI>(pCreature);
        }
};

class go_flee_to_surface : public GameObjectScript
{
    public:
        go_flee_to_surface() : GameObjectScript("go_flee_to_surface") {}

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->RemoveAurasDueToSpell(SPELL_ILLUSION_ROOM);
            player->NearTeleportTo(SaraLocation.GetPositionX(), SaraLocation.GetPositionY(), SaraLocation.GetPositionZ(), M_PI, false);
            player->JumpTo(40.0f, 15.0f, true);
            return false;
        }
};

class spell_keeper_support_aura_targeting : public SpellScriptLoader
{
    public:
        spell_keeper_support_aura_targeting() : SpellScriptLoader("spell_keeper_support_aura_targeting") {}

        class spell_keeper_support_aura_targeting_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_keeper_support_aura_targeting_AuraScript)
            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                std::list<Unit*> targetList;
                aurEff->GetTargetList(targetList);

                for (std::list<Unit*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
                    if (!(*iter)->ToPlayer() && (*iter)->GetGUID() != GetCasterGUID() )
                        (*iter)->RemoveAurasDueToSpell(GetSpellInfo()->Id);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_keeper_support_aura_targeting_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_keeper_support_aura_targeting_AuraScript();
        }
};

class spell_lunatic_gaze_targeting : public SpellScriptLoader
{
    public:
        spell_lunatic_gaze_targeting() : SpellScriptLoader("spell_lunatic_gaze_targeting") {}

        class spell_lunatic_gaze_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lunatic_gaze_targeting_SpellScript)

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if (IsNotLookingDirectlyInGaze(GetCaster()));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lunatic_gaze_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lunatic_gaze_targeting_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lunatic_gaze_targeting_SpellScript();
        }
};

class spell_brain_link_periodic_dummy : public SpellScriptLoader
{
    public:
        spell_brain_link_periodic_dummy() : SpellScriptLoader("spell_brain_link_periodic_dummy") {}

        class spell_brain_link_periodic_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brain_link_periodic_dummy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if (BrainLinkTargetSelector());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_brain_link_periodic_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        class spell_brain_link_periodic_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brain_link_periodic_dummy_AuraScript)

            void HandlePeriodicDummy(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (Unit* trigger = GetTarget())
                {
                    if (trigger->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (!trigger->GetMap()->IsDungeon())
                            return;

                        Map::PlayerList const &players = trigger->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player* player = itr->getSource())
                            {
                                if (player->HasAura(SPELL_BRAIN_LINK) && player->GetGUID() != trigger->GetGUID())
                                {
                                    if (Unit* caster = GetCaster())
                                    {
                                        if (!player->IsWithinDist(trigger, float(aurEff->GetAmount())))
                                        {
                                            trigger->CastSpell(player, SPELL_BRAIN_LINK_DAMAGE, true);
                                            if (InstanceScript* pInstance = caster->GetInstanceScript())
                                                if (caster->ToCreature() && caster->GetGUID() == pInstance->GetData64(NPC_YOGGSARON_CTRL))
                                                    CAST_AI(npc_yogg_saron_encounter_controller::npc_yogg_saron_encounter_controllerAI, caster->ToCreature()->AI())->ModifySanity(player,-2);
                                        }
                                        else
                                            trigger->CastSpell(player, SPELL_BRAIN_LINK_DUMMY, true);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_brain_link_periodic_dummy_AuraScript::HandlePeriodicDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_brain_link_periodic_dummy_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_brain_link_periodic_dummy_AuraScript();
        }
};

class spell_titanic_storm_targeting : public SpellScriptLoader
{
    public:
        spell_titanic_storm_targeting() : SpellScriptLoader("spell_titanic_storm_targeting") {}

        class spell_titanic_storm_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_titanic_storm_targeting_SpellScript)

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if (NotIsWeakenedImmortalCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_titanic_storm_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_titanic_storm_targeting_SpellScript();
        }
};

class spell_insane_death_effekt : public SpellScriptLoader
{
    public:
        spell_insane_death_effekt() : SpellScriptLoader("spell_insane_death_effekt") {}

        class spell_insane_death_effekt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_insane_death_effekt_AuraScript)

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    if (target->ToPlayer() && target->isAlive())
                        target->DealDamage(target, target->GetHealth());
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_insane_death_effekt_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_insane_death_effekt_AuraScript();
        }
};

class spell_summon_tentacle_position : public SpellScriptLoader
{
    public:
        spell_summon_tentacle_position() : SpellScriptLoader("spell_summon_tentacle_position") {}

        class spell_summon_tentacle_position_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_summon_tentacle_position_SpellScript);

            void ChangeSummonPos(SpellEffIndex /*effIndex*/)
            {
                if (GetExplTargetDest())    // Check for non-nullptr, since dereferencing a nullptr may cause a crash
                {
                    WorldLocation summonPos(*GetExplTargetDest());
                    if (Unit* caster = GetCaster())
                        summonPos.m_positionZ = caster->GetMap()->GetHeight(summonPos.GetPositionX(), summonPos.GetPositionY(), summonPos.GetPositionZ());

                    SetExplTargetDest(summonPos);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_summon_tentacle_position_SpellScript::ChangeSummonPos, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_summon_tentacle_position_SpellScript();
        }
};

class spell_empowering_shadows : public SpellScriptLoader
{
    public:
        spell_empowering_shadows() : SpellScriptLoader("spell_empowering_shadows") {}

        class spell_empowering_shadows_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_empowering_shadows_SpellScript)

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (Map* map = target->GetMap())
                        if (uint32 spell = map->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? SPELL_EMPOWERING_SHADOWS_HEAL_10 : (map->GetDifficulty()==RAID_DIFFICULTY_25MAN_NORMAL ? SPELL_EMPOWERING_SHADOWS_HEAL_25 : 0))
                            GetCaster()->CastSpell(target, spell, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_empowering_shadows_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_empowering_shadows_SpellScript();
        }
};

class spell_hodir_protective_gaze : public SpellScriptLoader
{
    public:
        spell_hodir_protective_gaze() : SpellScriptLoader("spell_hodir_protective_gaze") {}

        class spell_hodir_protective_gaze_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hodir_protective_gaze_AuraScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                return sSpellMgr->GetSpellInfo(SPELL_FLASH_FREEZE_COOLDOWN);
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                std::list<Unit*> targetList;
                aurEff->GetTargetList(targetList);

                for (std::list<Unit*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
                    if (!(*iter)->ToPlayer() && (*iter)->GetGUID() != GetCasterGUID())
                        (*iter)->RemoveAurasDueToSpell(GetSpellInfo()->Id);
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = std::numeric_limits<int32>::max();
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                Unit* target = GetTarget();

                if (dmgInfo.GetDamage() < target->GetHealth())
                {
                    absorbAmount = 0;
                    return;
                }

                target->CastSpell(target, SPELL_FLASH_FREEZE, true);

                // absorb hp till 1 hp
                absorbAmount = dmgInfo.GetDamage() - target->GetHealth() + 1;

                // Remove Aura from Hodir
                if (GetCaster()) 
                    if (GetCaster()->ToCreature())
                        GetCaster()->ToCreature()->RemoveAurasDueToSpell(SPELL_HODIRS_PROTECTIVE_GAZE);
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hodir_protective_gaze_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_hodir_protective_gaze_AuraScript::Absorb, EFFECT_0);
                OnEffectApply += AuraEffectApplyFn(spell_hodir_protective_gaze_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_hodir_protective_gaze_AuraScript();
        }
};

#define GOSSIP_KEEPER_HELP                  "Lend us your aid, keeper. Together we shall defeat Yogg-Saron."

class npc_keeper_help : public CreatureScript
{
    public:
        npc_keeper_help() : CreatureScript("npc_keeper_help") {}

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                uint32 supportFlag = instance->GetData(DATA_KEEPER_SUPPORT_YOGG);

                switch (creature->GetEntry())
                {
                    // Since the flags are binary, a simple bool check fulfills the requirements - no need to check against the flag again.
                    case NPC_HELP_KEEPER_FREYA:
                        if (supportFlag & FREYA_SUPPORT)
                            return false;
                        break;
                    case NPC_HELP_KEEPER_MIMIRON:
                        if (supportFlag & MIMIRON_SUPPORT)
                            return false;
                        break;
                    case NPC_HELP_KEEPER_THORIM:
                        if (supportFlag & THORIM_SUPPORT)
                            return false;
                        break;
                    case NPC_HELP_KEEPER_HODIR:
                        if (supportFlag & HODIR_SUPPORT)
                            return false;
                        break;
                    default:
                        break;
                }

                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_KEEPER_HELP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            }
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->CLOSE_GOSSIP_MENU();

            if (InstanceScript* instance = creature->GetInstanceScript())
                if ( action == GOSSIP_ACTION_INFO_DEF + 1)
                {
                    switch(creature->GetEntry())
                    {
                        case NPC_HELP_KEEPER_FREYA:
                            creature->AI()->Talk(SAY_FREYA_HELP, player->GetUInt64Value(0));
                            instance->SetData(DATA_ADD_HELP_FLAG, FREYA_SUPPORT);
                            break;
                        case NPC_HELP_KEEPER_MIMIRON:
                            creature->AI()->Talk(SAY_MIMIRON_HELP, player->GetUInt64Value(0));
                            instance->SetData(DATA_ADD_HELP_FLAG, MIMIRON_SUPPORT);
                            break;
                        case NPC_HELP_KEEPER_THORIM:
                            creature->AI()->Talk(SAY_THORIM_HELP, player->GetUInt64Value(0));
                            instance->SetData(DATA_ADD_HELP_FLAG, THORIM_SUPPORT);
                            break;
                        case NPC_HELP_KEEPER_HODIR:
                            creature->AI()->Talk(SAY_HODIR_HELP, player->GetUInt64Value(0));
                            instance->SetData(DATA_ADD_HELP_FLAG, HODIR_SUPPORT);
                            break;
                        default:
                            break;
                    }
                    instance->SaveToDB();
                }

            return true;
        }

        struct npc_keeper_helpAI : public ScriptedAI
        {
            npc_keeper_helpAI(Creature *c) : ScriptedAI(c)
            {
                instance = c->GetInstanceScript();
                me->setFaction(FACTION_FRIENDLY);
            }

            void AttackStart(Unit* /*who*/) {} // Should be overwritten, but has no effect

            void UpdateAI(const uint32 /*diff*/)
            {
                if (instance)
                    me->SetVisible( (instance->GetBossState(Entry_2_ID(me->GetEntry())) == DONE) && (instance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS) );
            }

            private:
                InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_keeper_helpAI>(pCreature);
        }
};

class spell_sara_psychosis : public SpellScriptLoader
{
    public:
        spell_sara_psychosis() : SpellScriptLoader("spell_sara_psychosis") {}

        class spell_sara_psychosis_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sara_psychosis_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (WorldObject* _target = Trinity::Containers::SelectRandomContainerElement(targets))
                {
                    targets.clear();
                    targets.push_back(_target);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sara_psychosis_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sara_psychosis_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sara_psychosis_SpellScript();
        }
};

class item_unbound_fragments_of_valanyr : public ItemScript
{
    public:
        item_unbound_fragments_of_valanyr() : ItemScript("item_unbound_fragments_of_valanyr") {}

        bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& /*targets*/)
        {
            if (Creature* yogg = pPlayer->FindNearestCreature(NPC_YOGG_SARON, 20.0f))
            {
                if (yogg->FindCurrentSpellBySpellId(SPELL_DEAFENING_ROAR))
                    return false;
            }

            pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, pItem, NULL);
            return true;
        }
};

void AddSC_boss_yoggsaron()
{
    new npc_yogg_saron_encounter_controller();
    new boss_sara();
    new npc_ominous_cloud();
    new npc_guardian_of_yogg_saron();
    new npc_yogg_saron_tentacle();
    new npc_descend_into_madness();
    new npc_influence_tentacle();
    new boss_brain_of_yogg_saron();
    new boss_yogg_saron();
    new npc_immortal_guardian();
    new npc_support_keeper();
    new npc_sanity_well();
    new npc_laughting_skull();
    new npc_death_orb();
    new npc_death_ray();
    new npc_keeper_help();
    new go_flee_to_surface();
    new item_unbound_fragments_of_valanyr();

    new spell_keeper_support_aura_targeting();
    new spell_lunatic_gaze_targeting();
    new spell_brain_link_periodic_dummy();
    new spell_titanic_storm_targeting();
    new spell_insane_death_effekt();
    new spell_summon_tentacle_position();
    new spell_empowering_shadows();
    new spell_hodir_protective_gaze();
    new spell_sara_psychosis();
}
