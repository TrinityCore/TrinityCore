/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"

/*
LandofLegends - Entwicklungsnotizen:

Allgemein:
Loot

Script ist zu 97% fertig.

Phase 1 ist komplett
Phase 2 ist fast fertig
  Allgemein:
    Die kleinen Geschichten (visual spells finden)
  YoggSauron:
Phase 3 fertig
*/

enum Sara_Yells
{
    SAY_SARA_PREFIGHT_1                         = -1603310,
    SAY_SARA_PREFIGHT_2                         = -1603311,
    SAY_SARA_AGGRO_1                            = -1603312,
    SAY_SARA_AGGRO_2                            = -1603313,
    SAY_SARA_AGGRO_3                            = -1603314,
    SAY_SARA_SLAY_1                             = -1603315,
    SAY_SARA_SLAY_2                             = -1603316,
    WHISP_SARA_INSANITY                         = -1603317,
    SAY_SARA_PHASE2_1                           = -1603318,
    SAY_SARA_PHASE2_2                           = -1603319,
};

enum KeepersHelpSays
{
    SAY_FREYA_HELP                              = -1603189,
    SAY_MIMIRON_HELP                            = -1603259,
    SAY_THORIM_HELP                             = -1603287,
    SAY_HODIR_HELP                              = -1603217,
};

enum YoggSaron_Yells
{
    SAY_PHASE2_1                                = -1603330,
    SAY_PHASE2_2                                = -1603331,
    SAY_PHASE2_3                                = -1603332,
    SAY_PHASE2_4                                = -1603333,
    SAY_PHASE2_5                                = -1603334,
    SAY_PHASE3                                  = -1603335,
    SAY_VISION                                  = -1603336,
    SAY_LUNCATIC_GLAZE                          = -1603337,
    SAY_DEAFENING_ROAR                          = -1603338,
    WHISP_INSANITY_1                            = -1603339,
    WHISP_INSANITY_2                            = -1603340,
    SAY_DEATH                                   = -1603341,
};

enum Vision_Says
{
    // King Llane
    SAY_GARONA_1_VISION_1                       = -1603342,
    SAY_GARONA_2_VISION_1                       = -1603343,
    SAY_GARONA_3_VISION_1                       = -1603344,
    SAY_YOGGSARON_4_VISION_1                    = -1603345,
    SAY_YOGGSARON_5_VISION_1                    = -1603346,
    SAY_LLANE_6_VISION_1                        = -1603347,
    SAY_GARONA_7_VISION_1                       = -1603348,
    SAY_YOGGSARON_8_VISION_1                    = -1603349,
    // Lichking
    SAY_LICHKING_1_VISION_2                     = -1603350,
    SAY_CHAMP_2_VISION_2                        = -1603351,
    SAY_CHAMP_3_VISION_2                        = -1603352,
    SAY_LICHKING_4_VISION_2                     = -1603353,
    SAY_YOGGSARON_5_VISION_2                    = -1603354,
    SAY_YOGGSARON_6_VISION_2                    = -1603355,
    // Dragon Soul
    SAY_NELTHARION_1_VISION_3                   = -1603356,
    SAY_YSERA_2_VISION_3                        = -1603357,
    SAY_NELTHARION_3_VISION_3                   = -1603358,
    SAY_MALYGOS_4_VISION_3                      = -1603359,
    SAY_YOGGSARON_5_VISION_3                    = -1603360
};

enum Events
{
    ACHIEV_TIMED_START_EVENT                    = 21001, // Dont Need this
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
    ACHIEVMENT_REALM_FIRST_DEATHS_DEMISE        = 3117,
};

enum Entrys
{
    NPC_HELP_KEEPER_FREYA                       = 33241,
    NPC_HELP_KEEPER_MIMIRON                     = 33244,
    NPC_HELP_KEEPER_THORIM                      = 33242,
    NPC_HELP_KEEPER_HODIR                       = 33213,
    // All Phases
    ENTRY_KEEPER_FREYA                          = 33410,
    ENTRY_KEEPER_HODIR                          = 33411,
    ENTRY_KEEPER_MIMIRON                        = 33412,
    ENTRY_KEEPER_THORIM                         = 33413,
    ENTRY_SANITY_WELL                           = 33991,
    // Phase 1
    ENTRY_SARA                                  = 33134,
    ENTRY_OMINOUS_CLOUD                         = 33292,
    ENTRY_GUARDIAN_OF_YOGG_SARON                = 33136,
    // Phase 2
    ENTRY_YOGG_SARON                            = 33288,
    ENTRY_BRAIN_OF_YOGG_SARON                   = 33890,
    ENTRY_DEATH_RAY                             = 33881,
    ENTRY_DEATH_ORB                             = 33882,
    //  Tentakles
    ENTRY_CRUSHER_TENTACLE                      = 33966,
    ENTRY_CORRUPTOR_TENTACLE                    = 33985,
    ENTRY_CONSTRICTOR_TENTACLE                  = 33983,
    //  Brain
    //  All Vision
    ENTRY_BRAIN_PORTAL                          = 34072,
    ENTRY_INFULENCE_TENTACLE                    = 33943,
    ENTRY_LAUGHING_SKULL                        = 33990,
    //  Vision Dragon Soul
    ENTRY_RUBY_CONSORT                          = 33716, // 2 on Roomexit (l & r)
    ENTRY_OBSIDIAN_CONSORT                      = 33720, // 2 on End of the Room (l & r)
    ENTRY_EMERAL_CONSORT                        = 33719, // 2 on North West of the room
    ENTRY_AZURE_CONSORT                         = 33717, // 2 on North East of the room
    ENTRY_NELTHARION_VISION                     = 33523,
    ENTRY_YSERA_VISION                          = 33495,
    ENTRY_MALYGOS_VISION                        = 33535,
    //  Vision Llane
    ENTRY_SUIT_OF_ARMOR                         = 33433, // around the Room
    ENTRY_GARONA_VISION                         = 33436,
    ENTRY_KING_LLANE                            = 33437,
    //  Vision Lich King
    ENTRY_DEATHSWORN_ZEALOT                     = 33567, // 3 Groups of 3 ... left middle right
    ENTRY_LICHKING_VISION                       = 33441,
    ENTRY_IMMOLATED_CHAMPION_VISION             = 33442,
    ENTRY_TURNED_CHAMPION_VISION                = 33962,
    // Phase 3
    ENTRY_IMMORTAL_GUARDIAN                     = 33988,

    OBJECT_THE_DRAGON_SOUL                      = 194462,
    OBJECT_FLEE_TO_SURFACE                      = 194625,
};

//enum ModelIds
//{
//    SARA_NORMAL                                 = 29117,
//    SARA_TRANSFORM                              = 29182,
//    YOGGSARON_NORMAL                            = 28817,
//    YOGGSARON_TRANSFORM                         = 28945
//};

enum MindlessSpell
{
    BRAIN_LINK = 0,
    MALADY_OF_MIND = 1,
    DEATH_RAY = 2
};

enum EncounterConstants
{
    CONSTANT_MAX_NOVA_HITS = 8,
    CONSTANT_MAX_LLIANE_TENTACLE_SPAWNS = 8,
    CONSTANT_MAX_LICHKING_TENTACLE_SPAWNS = 9,
    CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS = 8
};

enum Actions
{
    ACTION_NOVA_HIT = 0,
    ACTION_ACTIVATE_CLOUDS = 1,
    ACTION_DEACTIVATE_CLOUDS = 2,
    ACTION_PORTAL_TO_MADNESS_STORMWIND = 3,
    ACTION_PORTAL_TO_MADNESS_DRAGON = 4,
    ACTION_PORTAL_TO_MADNESS_LICHKING = 5,
    ACTION_BRAIN_UNDER_30_PERCENT = 6,
    ACTION_YOGGSARON_KILLED = 7,
    ACTION_DEATH_RAY_MOVE = 8,
    ACTION_USED_MINDCONTROL = 9,
    ACTION_MODIFY_SANITY = 10,
};

enum Spells
{
    SPELL_IN_THE_MAWS_OF_THE_OLD_GOD            = 64184,
    //All Phases
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
    SPELL_SHADOW_NOVA                           = 65209, // On Death
    //Phase 2:
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
    SPELL_EMPOWERED                             = 65294, // stacks 9 times ... on 100% hp it have 9 stacks .. but with <10% it havent any
};

enum BossPhase
{
    PHASE_NONE = 0,
    PHASE_SARA = 1,
    PHASE_BRAIN = 2,
    PHASE_YOGG = 3
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
    PORTAL_PHASE_BRAIN_NONE = 3
};

const Position InnerBrainLocation[3] =
{
    {1944.87f,  37.22f, 239.7f, (0.66f*M_PI)}, //King Lliane
    {2045.97f, -25.45f, 239.8f, 0           }, //Dragon Soul
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
    {1931.01f,   39.85f, 239.70f, (0.55f*M_PI)},
};

const Position DragonSoulTentacleLocation[CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS] =
{
    // ENTRY_RUBY_CONSORT
    {2061.44f,  -11.83f, 239.80f, 0},
    {2059.87f,  -37.77f, 239.80f, 0},
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
    {1939.94f, -90.49f, 338.46f, 0.3f*M_PI} // Hodir
};

const Position FreyaSanityWellLocation[5] =
{
    {1901.21f, -48.69f, 332.00f, 0},
    {1901.90f,  -2.78f, 332.30f, 0},
    {1993.58f,  45.56f, 332.00f, 0},
    {1985.87f, -91.10f, 330.20f, 0},
    {2040.12f, -39.16f, 329.00f, 0},
};

const Position KingLlaneSkullLocation[3] =
{
    {1929.41f,  45.27f, 239.70f, 0},
    {1902.31f,  72.53f, 239.70f, 0},
    {1925.10f,  91.52f, 239.70f, 0}
};

const Position LichkingSkullLocation[3] =
{
    {1955.12f, -111.96f,  240.00f, 0},
    {1919.55f, -131.94f,  240.00f, 0},
    {1921.03f,  -93.46f,  240.00f, 0}
};

const Position DragonSoulSkullLocation[4] =
{
    {2115.89f,   4.63f,  239.80f, 0},
    {2080.65f,  37.47f,  244.3f, 0},
    {2170.20f, -33.31f,  244.3f, 0},
    {2090.49f, -57.40f,  239.8f, 0}
};

const Position EventNpcLocation[9] =
{
    { 1928.23f, 66.81f, 242.40f, 5.207f }, // King Llane
    { 1929.78f, 63.60f, 242.40f, 2.124f }, // Garona - kneeling
    { 2103.87f, -13.13f, 242.65f, 4.692f }, // Ysera
    { 2118.68f, -25.56f, 242.65f, M_PI}, // Neltharion
    { 2095.87f, -34.47f, 242.65f, 0.836f }, // Malygos
    { 2104.61f, -25.36f, 242.65f, 0.0f }, // The Dragon Soul
    { 1903.41f, -160.21f, 239.99f, 1.114f }, // Immolated Champion
    { 1909.31f, -155.88f, 239.99f, 4.222f }, // Turned Champion
    { 1907.02f, -153.92f, 239.99f, 4.187f }, // The Lich King

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
    bool isSpeaking;
};

const uint32  EventNpcEntrys[9] =
{
    ENTRY_KING_LLANE,
    ENTRY_GARONA_VISION,
    ENTRY_YSERA_VISION,
    ENTRY_NELTHARION_VISION,
    ENTRY_MALYGOS_VISION,
    OBJECT_THE_DRAGON_SOUL,
    ENTRY_IMMOLATED_CHAMPION_VISION,
    ENTRY_TURNED_CHAMPION_VISION,
    ENTRY_LICHKING_VISION,
};

const EventSpeech EventNpcSpeaching[19] =
{
    {ENTRY_GARONA_VISION,SAY_GARONA_1_VISION_1,3000,true},
    {ENTRY_GARONA_VISION,SAY_GARONA_2_VISION_1,5000,true},
    {ENTRY_GARONA_VISION,SAY_GARONA_3_VISION_1,5000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_4_VISION_1,3000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_5_VISION_1,3000,true},
    {ENTRY_KING_LLANE,SAY_LLANE_6_VISION_1,5000,true},
    {ENTRY_GARONA_VISION,SAY_GARONA_7_VISION_1,5000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_8_VISION_1,5000,false},

    {ENTRY_LICHKING_VISION,SAY_LICHKING_1_VISION_2,5000,true},/*8*/
    {ENTRY_IMMOLATED_CHAMPION_VISION,SAY_CHAMP_2_VISION_2,5000,true},
    {ENTRY_IMMOLATED_CHAMPION_VISION,SAY_CHAMP_3_VISION_2,5000,true},
    {ENTRY_LICHKING_VISION,SAY_LICHKING_4_VISION_2,5000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_5_VISION_2,5000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_6_VISION_2,5000,false},

    {ENTRY_NELTHARION_VISION,SAY_NELTHARION_1_VISION_3,5000,true},/*14*/
    {ENTRY_YSERA_VISION,SAY_YSERA_2_VISION_3,5000,true},
    {ENTRY_NELTHARION_VISION,SAY_NELTHARION_3_VISION_3,5000,true},
    {ENTRY_MALYGOS_VISION,SAY_MALYGOS_4_VISION_3,5000,true},
    {ENTRY_YOGG_SARON,SAY_YOGGSARON_5_VISION_3,5000,false},
};

bool IsPlayerInBrainRoom(const Player* pPlayer)
{
    return pPlayer->GetPositionZ() < 300;
}

class boss_sara : public CreatureScript
{
public:
    boss_sara() : CreatureScript("boss_sara") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_saraAI (pCreature);
    }

    struct boss_saraAI : public ScriptedAI
    {
        boss_saraAI(Creature *c) : ScriptedAI(c), Summons(me)
        {
            m_pInstance = c->GetInstanceScript();
            me->SetFlying(true);
            SetImmuneToPushPullEffects(true);
        }

        InstanceScript* m_pInstance;
        SummonList Summons;

        BossPhase m_Phase;
        uint32 uiAmountKeeperActive;

        uint64 guidYogg;
        uint64 guidYoggBrain;
        std::list<uint64> guidEventTentacles;
        std::list<uint64> guidEventSkulls;
        std::list<EventNPC> listEventNPCs;

        bool bUsedMindcontroll;

        // Phase 1
        uint32 uiSarasHelp_Timer;

        uint32 uiGuardianSummon_Timer;
        uint32 uilastGuardianSummon_Timer;
        uint32 uiRandomYell_Timer;

        uint32 NovaHitCounter;
        // Phase 2
        Actions lastBrainAction;
        bool IsSpeaking;
        uint32 SpeakingPhase;
        uint32 uiSpeaking_Timer;

        uint32 uiPsychosis_Timer;
        uint32 uiMindSpell_Timer;
        uint32 uiTentacle_Timer;
        uint32 uiTentacle1_Timer;

        uint32 uiEnrage_Timer;
        uint32 uiMadness_Timer;

        uint32 uiBrainEvents_Count;
        BrainEventPhase currentBrainEventPhase;

        bool IsEventSpeaking;
        uint32 EventSpeakingPhase;

        // Phase 3
        uint32 uiDeafeningRoar_Timer;
        uint32 uiShadowBeacon_Timer;
        uint32 uiLunaticGaze_Timer;

        void CloudHandling(bool remove)
        {
            std::list<Creature*> CloudList;
            me->GetCreatureListWithEntryInGrid(CloudList,ENTRY_OMINOUS_CLOUD,100.0f);
            if(!CloudList.empty())
            {
                for(std::list<Creature*>::iterator itr = CloudList.begin(); itr != CloudList.end(); itr++)
                {
                    if(remove) (*itr)->AI()->DoAction(ACTION_DEACTIVATE_CLOUDS);
                    else (*itr)->AI()->DoAction(ACTION_ACTIVATE_CLOUDS);
                }
            }
        }

        void Reset()
        {
            Summons.DespawnAll();
            guidEventTentacles = std::list<uint64>();
            guidEventSkulls = std::list<uint64>();
            listEventNPCs = std::list<EventNPC>();

            me->InterruptNonMeleeSpells(false);
            // Zurueck an Home ... muss nicht sein ist aber besser so
            Position pos = me->GetHomePosition();
            me->NearTeleportTo(pos.m_positionX,pos.m_positionY,pos.m_positionZ,pos.m_orientation);
            me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
            me->RemoveAurasDueToSpell(SPELL_SARA_SHADOWY_BARRIER);

            // Remove Random MoveMaster
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MoveIdle();

            // Reset Display
            me->setFaction(35);
            me->SetVisible(true);
            //me->SetDisplayId(me->GetNativeDisplayId());
            me->RemoveAurasDueToSpell(SPELL_SARA_TRANSFORMATION);
            // Reset Health
            me->SetHealth(me->GetMaxHealth());
            // Remove Not Attackable Flags
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            // Reset Phase
            m_Phase = PHASE_NONE;
            // Respawn Clouds
            CloudHandling(false);
            SetSanityAura(true);
            // Reset HitCounter Phase 1
            NovaHitCounter = CONSTANT_MAX_NOVA_HITS;
            currentBrainEventPhase = PORTAL_PHASE_BRAIN_NONE;

            // Spawn Yoggy if not spawned
            Creature* yogg = me->GetCreature(*me,guidYogg);
            if(yogg) yogg->DespawnOrUnsummon();
            if(yogg = DoSummon(ENTRY_YOGG_SARON,SaraLocation,0,TEMPSUMMON_MANUAL_DESPAWN))
                yogg->SetLootMode(LOOT_MODE_DEFAULT);

            Creature* yoggbrain = me->GetCreature(*me,guidYoggBrain);
            if(yoggbrain) yoggbrain->DespawnOrUnsummon();
            DoSummon(ENTRY_BRAIN_OF_YOGG_SARON,BrainLocation,0,TEMPSUMMON_MANUAL_DESPAWN);

            if(m_pInstance)
                m_pInstance->SetBossState(BOSS_YOGGSARON,NOT_STARTED);

            uiRandomYell_Timer = urand(10000,20000);

            bUsedMindcontroll = false;
            uiAmountKeeperActive = -1;
        }

        void JustDied(Unit* /*killer*/)
        {
            if(m_pInstance)
                m_pInstance->SetBossState(BOSS_YOGGSARON,DONE);

            SetSanityAura(true);
            Summons.DespawnAll();
        }

        void DoSpawnKeeperForSupport() // Despawn on Sara Reset
        {
            if(m_pInstance)
            {
                uint32 supportFlag = m_pInstance->GetData(DATA_KEEPER_SUPPORT_YOGG);

                if((supportFlag & MIMIRON_SUPPORT) == MIMIRON_SUPPORT)
                    DoSummon(ENTRY_KEEPER_MIMIRON,KeeperSpawnLocation[0],0,TEMPSUMMON_MANUAL_DESPAWN);
                if((supportFlag & FREYA_SUPPORT) == FREYA_SUPPORT)
                    DoSummon(ENTRY_KEEPER_FREYA,KeeperSpawnLocation[1],0,TEMPSUMMON_MANUAL_DESPAWN);
                if((supportFlag & THORIM_SUPPORT) == THORIM_SUPPORT)
                    DoSummon(ENTRY_KEEPER_THORIM,KeeperSpawnLocation[2],0,TEMPSUMMON_MANUAL_DESPAWN);
                if((supportFlag & HODIR_SUPPORT) == HODIR_SUPPORT)
                    DoSummon(ENTRY_KEEPER_HODIR,KeeperSpawnLocation[3],0,TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            uiSarasHelp_Timer = urand(5000,6000);
            uiGuardianSummon_Timer = 10000;
            uilastGuardianSummon_Timer = 35000;

            uiPsychosis_Timer = urand(5000,5000);
            uiMindSpell_Timer = urand(30000,30000);
            uiTentacle_Timer = urand(3000,5000);
            uiTentacle1_Timer = 1000;
            uiMadness_Timer = 60000;

            uiDeafeningRoar_Timer = urand(30000,60000);
            uiShadowBeacon_Timer = 30000;
            uiLunaticGaze_Timer = 12000;

            uiEnrage_Timer = 900000;

            if(Creature* yogg = me->GetCreature(*me,guidYogg))
                DoZoneInCombat(yogg);

            if(m_pInstance)
                m_pInstance->SetBossState(BOSS_YOGGSARON,IN_PROGRESS);

            lastBrainAction = Actions(0);
        }

        void ReceiveEmote(Player* pPlayer, uint32 emote)
        {
            if(m_Phase >= PHASE_BRAIN)
            {
                if(emote == TEXT_EMOTE_KISS)
                {
                    if(pPlayer->HasAchieved(RAID_MODE(ACHIEVMENT_KISS_AND_MAKE_UP_10,ACHIEVMENT_KISS_AND_MAKE_UP_25)))
                        return;

                    if (me->IsWithinLOS(pPlayer->GetPositionX(),pPlayer->GetPositionY(),pPlayer->GetPositionZ()) && me->IsWithinDistInMap(pPlayer,30.0f))
                    {
                        if(AchievementEntry const *achievKissAndMakeUp = GetAchievementStore()->LookupEntry(RAID_MODE(ACHIEVMENT_KISS_AND_MAKE_UP_10,ACHIEVMENT_KISS_AND_MAKE_UP_25)))
                            pPlayer->CompletedAchievement(achievKissAndMakeUp);
                    }
                }
            }
        }

        void DamageTaken(Unit* dealer, uint32 &damage)
        {
            if(dealer->GetEntry() == ENTRY_GUARDIAN_OF_YOGG_SARON)
            {
                damage = 0;
                return;
            }

            if(damage > me->GetHealth())
                damage = me->GetHealth()-1;
        }

        uint32 CountKeepersActive()
        {
            uint32 count = 0;
            if(m_pInstance)
            {
                uint32 supportFlag = m_pInstance->GetData(DATA_KEEPER_SUPPORT_YOGG);

                if(supportFlag & MIMIRON_SUPPORT)
                    count++;
                if(supportFlag & FREYA_SUPPORT)
                    count++;
                if(supportFlag & THORIM_SUPPORT)
                    count++;
                if(supportFlag & HODIR_SUPPORT)
                    count++;
            }
            return count;
        }

        void ModifySanity(Player* target, int8 amount)
        {
            if(target && target->isAlive())
            {
                int32 newamount;
                if(Aura* aur = target->GetAura(SPELL_SANITY, GetGUID()))
                {
                    newamount = aur->GetStackAmount();
                    if(newamount > 0)
                        newamount += amount;

                    if(newamount > 100)
                        newamount = 100;

                    if(newamount <= 0)
                        target->RemoveAurasDueToSpell(SPELL_SANITY);
                    else
                        aur->SetStackAmount(newamount);
                }
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if(target && target->ToPlayer())
            {
                switch(spell->Id)
                {
                case SPELL_PSYCHOSIS:
                    ModifySanity(target->ToPlayer(),-12);
                    break;
                case SPELL_BRAIN_LINK_DAMAGE:
                    ModifySanity(target->ToPlayer(),-2);
                    break;
                case SPELL_MALADY_OF_MIND:
                    ModifySanity(target->ToPlayer(),-3);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 i)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if(i == 1)
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveIdle();
            }
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
            case ACTION_NOVA_HIT:
                if(m_Phase != PHASE_SARA)
                    return;

                NovaHitCounter--;

                if(NovaHitCounter <= 0)
                    SetPhase(PHASE_BRAIN);
                else me->ModifyHealth(-25000);
                break;
            case ACTION_BRAIN_UNDER_30_PERCENT:
                SetPhase(PHASE_YOGG);
                break;
            case ACTION_YOGGSARON_KILLED:
                if(Creature* yogg = me->GetCreature(*me,guidYogg))
                    yogg->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                if(uiEnrage_Timer >= 480000)
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_10,ACHIEVMENT_HE_S_NOT_GETTING_ANY_OLDER_25));
                if(!bUsedMindcontroll)
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_DRIVE_ME_CRAZY_10,ACHIEVMENT_DRIVE_ME_CRAZY_25));
                if(GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL && uiAmountKeeperActive == 0)
                    m_pInstance->DoCompleteAchievement(ACHIEVMENT_REALM_FIRST_DEATHS_DEMISE);
                switch(uiAmountKeeperActive)
                {
                case 0:
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_ALONE_IN_THE_DARKNESS_10,ACHIEVMENT_ALONE_IN_THE_DARKNESS_25));
                case 1:
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_10,ACHIEVMENT_ONE_LIGHTS_IN_THE_DARKNESS_25));
                case 2:
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_10,ACHIEVMENT_TWO_LIGHTS_IN_THE_DARKNESS_25));
                case 3:
                    m_pInstance->DoCompleteAchievement(RAID_MODE(ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_10,ACHIEVMENT_THREE_LIGHTS_IN_THE_DARKNESS_25));
                    break;
                default: break;
                }
                me->Kill(me);
                break;
            case ACTION_USED_MINDCONTROL:
                bUsedMindcontroll = true;
                break;
            }
        }

        uint32 GetData(uint32 data)
        {
            switch(data)
            {
            case DATA_PORTAL_PHASE:
                return currentBrainEventPhase;
            }
            return 0;
        }

        void SetPhase(BossPhase newPhase)
        {
            if(m_Phase == newPhase)
                return;

            switch(newPhase)
            {
            case PHASE_SARA:
                DoScriptText(SAY_SARA_AGGRO_1,me);
                DoSpawnKeeperForSupport();
                SetSanityAura();
                uiAmountKeeperActive = CountKeepersActive();
                if(Creature* yogg = me->GetCreature(*me,guidYogg))
                {
                    yogg->SetLootMode(LOOT_MODE_DEFAULT);
                    if(uiAmountKeeperActive <= 1)
                        yogg->AddLootMode(LOOT_MODE_HARD_MODE_1);
                    if(uiAmountKeeperActive == 0)
                        yogg->AddLootMode(LOOT_MODE_HARD_MODE_2);
                }

                break;
            case PHASE_BRAIN:
                me->SetHealth(me->GetMaxHealth());
                IsSpeaking = true;
                SpeakingPhase = 0;
                uiSpeaking_Timer = 1000;
                IsEventSpeaking = false;
                EventSpeakingPhase = 0;
                //me->SetDisplayId(SARA_TRANSFORM);
                CloudHandling(true);
                uiRandomYell_Timer = 35000;
                uiBrainEvents_Count = 0;
                break;
            case PHASE_YOGG:
                me->SetVisible(false);
                if(Creature* yogg = me->GetCreature(*me,guidYogg))
                {
                    yogg->LowerPlayerDamageReq(uint32(yogg->GetMaxHealth()*0.3f));
                    yogg->SetHealth(yogg->CountPctFromMaxHealth(30));
                    yogg->RemoveAurasDueToSpell(SPELL_SHADOWY_BARRIER);
                    yogg->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                    DoScriptText(SAY_PHASE3,yogg);
                    me->AddAura(SPELL_YOGG_SARON_TRANSFORMATION,yogg);
                }

                // Not blizzlike
                //if(me->GetMap() && me->GetMap()->IsDungeon())
                //{
                //    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                //    if (!players.isEmpty())
                //        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                //            if (Player* plr = itr->getSource())
                //                if(plr->isAlive() && IsPlayerInBrainRoom(plr))
                //                {
                //                    plr->NearTeleportTo(SaraLocation.GetPositionX(),SaraLocation.GetPositionY(),SaraLocation.GetPositionZ(),M_PI,false);
                //                    plr->JumpTo(30.0f,5.0f,true);
                //                }
                //}

                for(std::list<uint64>::iterator itr = Summons.begin(); itr != Summons.end(); ++itr)
                {
                    if(Creature* temp = Creature::GetCreature(*me,*itr))
                    {
                        switch(temp->GetEntry())
                        {
                        case ENTRY_CONSTRICTOR_TENTACLE:
                        case ENTRY_CORRUPTOR_TENTACLE:
                        case ENTRY_CRUSHER_TENTACLE:
                                temp->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                            break;
                        }
                    }
                }

                Summons.DespawnEntry(ENTRY_BRAIN_PORTAL);

                if(Creature* yoggbrain = me->GetCreature(*me,guidYoggBrain))
                    yoggbrain->InterruptNonMeleeSpells(false);

                uiGuardianSummon_Timer = 20000;
                uilastGuardianSummon_Timer = 35000;
                break;
            }

            m_Phase = newPhase;
        }

        void SaraRandomYell()
        {
            switch(m_Phase)
            {
            case PHASE_NONE: DoScriptText(RAND(SAY_SARA_PREFIGHT_1,SAY_SARA_PREFIGHT_2),me); break;
            case PHASE_SARA: DoScriptText(RAND(SAY_SARA_AGGRO_2,SAY_SARA_AGGRO_3),me); break;
            case PHASE_BRAIN: DoScriptText(RAND(SAY_SARA_PHASE2_1,SAY_SARA_PHASE2_2,SAY_SARA_AGGRO_3),me); break;
            }
        }

        void MoveInLineOfSight(Unit* target)
        {
            if(m_Phase == PHASE_NONE)
            {
                if(target && me->GetDistance2d(target) <= 100 && target->ToPlayer() && !target->ToPlayer()->isGameMaster() && me->IsWithinLOSInMap(target))
                {
                    if(m_pInstance && m_pInstance->GetBossState(BOSS_VEZAX) == DONE)
                    {
                        SetPhase(PHASE_SARA);
                        EnterCombat(target);
                    }
                }
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            switch(pSummoned->GetEntry())
            {
            case ENTRY_GUARDIAN_OF_YOGG_SARON:
                pSummoned->setFaction(14);
                pSummoned->AI()->AttackStart(SelectPlayerTargetInRange(100.0f));
                break;
            case ENTRY_YOGG_SARON:
                guidYogg = pSummoned->GetGUID();
                pSummoned->SetReactState(REACT_PASSIVE);
                pSummoned->setFaction(14);
                //pSummoned->SetVisible(false);
                pSummoned->SetStandState(UNIT_STAND_STATE_SUBMERGED);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pSummoned->SetFloatValue(UNIT_FIELD_COMBATREACH, 20.0f);
                pSummoned->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 20.0f);
                return; // Do Not Save Yoggy in Summons because he shouldnt despawnt on Encount Finished
            case ENTRY_BRAIN_OF_YOGG_SARON:
                guidYoggBrain = pSummoned->GetGUID();
                pSummoned->setActive(true);
                pSummoned->SetFloatValue(UNIT_FIELD_COMBATREACH, 25.0f);
                pSummoned->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 25.0f);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                break;
            case ENTRY_RUBY_CONSORT:
            case ENTRY_OBSIDIAN_CONSORT:
            case ENTRY_AZURE_CONSORT:
            case ENTRY_EMERAL_CONSORT:
            case ENTRY_DEATHSWORN_ZEALOT:
            case ENTRY_SUIT_OF_ARMOR:
                pSummoned->SetReactState(REACT_DEFENSIVE);
                pSummoned->setFaction(15);
                break;
            case ENTRY_KEEPER_FREYA:
            case ENTRY_KEEPER_HODIR:
            case ENTRY_KEEPER_MIMIRON:
            case ENTRY_KEEPER_THORIM:
                pSummoned->setActive(true);
                break;
            case ENTRY_LAUGHING_SKULL:
                pSummoned->setFaction(14);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                break;
            }

            Summons.Summon(pSummoned);
        }

        bool IsEncounterInProgress()
        {
            if(me->GetMap() && me->GetMap()->IsDungeon())
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* plr = itr->getSource())
                            if(plr->isAlive() && !plr->isGameMaster() && !plr->HasAura(SPELL_INSANE))
                                return true;
            }
            return false;
        }

        void SetSanityAura(bool remove = false)
        {
            if(me->GetMap() && me->GetMap()->IsDungeon())
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* plr = itr->getSource())
                            if(plr->isAlive())
                            {
                                if(!remove)
                                {
                                    me->AddAura(SPELL_SANITY,plr);
                                    me->SetAuraStack(SPELL_SANITY,plr,100);
                                }else
                                {
                                    plr->RemoveAurasDueToSpell(SPELL_SANITY);
                                }
                            }
            }
        }

        Player* SelectPlayerTargetInRange(float range)
        {
            Player *target = NULL;
            Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
            Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
            me->VisitNearbyObject(range, searcher);
            return target;
        }

        Creature* GetRandomEntryTarget(uint32 entry, float range = 100.0f)
        {
            std::list<Creature*> TargetList;
            me->GetCreatureListWithEntryInGrid(TargetList,entry, range);
            if(TargetList.empty())
                return NULL;

            std::list<Creature*>::iterator itr = TargetList.begin();
            advance(itr, urand(0, TargetList.size()-1));
            return (*itr);
        }

        // For Gardian Summon
        Creature* GetRandomCloudTarget(float range = 100.0f)
        {
            return GetRandomEntryTarget(ENTRY_OMINOUS_CLOUD);
        }

        // For Immortal Guardian Heal
        Creature* GetRandomGuardianTarget(float range = 100.0f)
        {
            return GetRandomEntryTarget(ENTRY_IMMORTAL_GUARDIAN);
        }

        bool AllSpawnsDeadOrDespawned(std::list<uint64> GuidListe)
        {
            for(std::list<uint64>::iterator itr = GuidListe.begin(); itr != GuidListe.end(); ++itr)
            {
                Creature* temp = me->GetCreature(*me,*itr);
                if(temp && temp->isAlive())
                    return false;
            }

            return true;
        }

        void DoKillAndDespawnGUIDs(std::list<uint64> GuidListe)
        {
            for(std::list<uint64>::iterator itr = GuidListe.begin(); itr != GuidListe.end(); ++itr)
            {
                Creature* temp = me->GetCreature(*me,*itr);
                if(temp && temp->isAlive())
                {
                    temp->DealDamage(temp,temp->GetHealth());
                    temp->RemoveCorpse();
                }
            }
        }

        void SummonMadnessEventNPCs()
        {
            listEventNPCs.clear();
            uint32 npcIndex = 0;
            uint32 npcAmount = 0;

            switch(currentBrainEventPhase)
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
            }

            Creature* temp;

            for(uint8 i = 0; i < npcAmount; i++)
            {
                if(EventNpcEntrys[npcIndex+i] == OBJECT_THE_DRAGON_SOUL)
                {
                    if(GameObject* obj = me->SummonGameObject(EventNpcEntrys[npcIndex+i],EventNpcLocation[npcIndex+i].GetPositionX(),EventNpcLocation[npcIndex+i].GetPositionY(),EventNpcLocation[npcIndex+i].GetPositionZ(),0,0,0,0,0,40000))
                    {
                        obj->setActive(true);
                        EventNPC *info = new EventNPC();
                        info->entry = obj->GetEntry();
                        info->guid = obj->GetGUID();

                        listEventNPCs.push_back(*info);
                    }
                }
                else
                {
                    if(temp = DoSummon(EventNpcEntrys[npcIndex+i],EventNpcLocation[npcIndex+i],40000,TEMPSUMMON_TIMED_DESPAWN))
                    {
                        temp->setActive(true);
                        EventNPC *info = new EventNPC();
                        info->entry = temp->GetEntry();
                        info->guid = temp->GetGUID();
                        switch(info->entry)
                        {
                        case ENTRY_GARONA_VISION:
                            temp->SetStandState(UNIT_STAND_STATE_KNEEL);
                            break;
                        }
                        listEventNPCs.push_back(*info);
                    }
                }
            }
        }

        uint64 GetEventNPCGuid(uint32 entry)
        {
            for(std::list<EventNPC>::iterator itr = listEventNPCs.begin(); itr != listEventNPCs.end(); ++itr)
            {
                if(itr->entry == entry)
                    return itr->guid;
            }
            return 0;
        }

        void DoMadness()
        {
            if(m_pInstance)
            {
                m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_1),false);
                m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_2),false);
                m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_3),false);
            }

            Actions tempAction;
            switch(lastBrainAction)
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
                tempAction = RAND(ACTION_PORTAL_TO_MADNESS_STORMWIND,ACTION_PORTAL_TO_MADNESS_DRAGON,ACTION_PORTAL_TO_MADNESS_LICHKING);
                break;
            }
            lastBrainAction = tempAction;

            // Spawn Portal
            int max = RAID_MODE(4,10);
            for(int i = 0; i < max; ++i)
            {
                if(Creature* portal = DoSummon(ENTRY_BRAIN_PORTAL,BrainPortalLocation[i],40000,TEMPSUMMON_TIMED_DESPAWN))
                    portal->AI()->DoAction(tempAction);
            }

            // Spawn Event Tentacle
            switch(tempAction)
            {
            case ACTION_PORTAL_TO_MADNESS_DRAGON:
                currentBrainEventPhase = PORTAL_PHASE_DRAGON_SOUL;
                guidEventTentacles.clear();
                guidEventSkulls.clear();
                uint32 entry;
                for(int i = 0; i < CONSTANT_MAX_DRAGONSOUL_TENTACLE_SPAWNS; ++i)
                {
                    switch(i)
                    {
                    case 0:
                    case 1: entry = ENTRY_RUBY_CONSORT; break;
                    case 2:
                    case 3: entry = ENTRY_AZURE_CONSORT; break;
                    case 4:
                    case 5: entry = ENTRY_OBSIDIAN_CONSORT; break;
                    case 6:
                    case 7: entry = ENTRY_EMERAL_CONSORT; break;
                    }
                    if(Creature* summon = DoSummon(entry,DragonSoulTentacleLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventTentacles.push_back(summon->GetGUID());
                }
                for(int i = 0; i < 4; ++i)
                {
                    if(Creature* summon = DoSummon(ENTRY_LAUGHING_SKULL,DragonSoulSkullLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventSkulls.push_back(summon->GetGUID());
                }
                break;
            case ACTION_PORTAL_TO_MADNESS_LICHKING:
                currentBrainEventPhase = PORTAL_PHASE_LICH_KING;
                guidEventTentacles.clear();
                guidEventSkulls.clear();
                for(int i = 0; i < CONSTANT_MAX_LICHKING_TENTACLE_SPAWNS; ++i)
                {
                    if(Creature* summon = DoSummon(ENTRY_DEATHSWORN_ZEALOT,LichKingTentacleLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventTentacles.push_back(summon->GetGUID());
                }
                for(int i = 0; i < 3; ++i)
                {
                    if(Creature* summon = DoSummon(ENTRY_LAUGHING_SKULL,LichkingSkullLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventSkulls.push_back(summon->GetGUID());
                }
                break;
            case ACTION_PORTAL_TO_MADNESS_STORMWIND:
                currentBrainEventPhase = PORTAL_PHASE_KING_LLIANE;
                guidEventTentacles.clear();
                guidEventSkulls.clear();
                for(int i = 0; i < CONSTANT_MAX_LLIANE_TENTACLE_SPAWNS; ++i)
                {
                    if(Creature* summon = DoSummon(ENTRY_SUIT_OF_ARMOR,KingLlaneTentacleLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventTentacles.push_back(summon->GetGUID());
                }
                for(int i = 0; i < 3; ++i)
                {
                    if(Creature* summon = DoSummon(ENTRY_LAUGHING_SKULL,KingLlaneSkullLocation[i],60000,TEMPSUMMON_TIMED_DESPAWN))
                        guidEventSkulls.push_back(summon->GetGUID());
                }
                break;
            }

            if(Creature* yoggbrain = me->GetCreature(*me,guidYoggBrain))
            {
                yoggbrain->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                yoggbrain->CastSpell(yoggbrain,SPELL_INDUCE_MADNESS,false);
            }

            SummonMadnessEventNPCs();
            IsEventSpeaking = true;
            EventSpeakingPhase = 0;
            uiSpeaking_Timer = 5000;

            uiBrainEvents_Count++;
        }

        uint32 DoEventSpeaking(BrainEventPhase phase, uint32 part)
        {
            uint64 npcguid = 0;
            uint32 speachindex = 0;
            switch(phase)
            {
            case PORTAL_PHASE_KING_LLIANE:
                speachindex = 0;
                break;
            case PORTAL_PHASE_LICH_KING:
                speachindex = 8;
                break;
            case PORTAL_PHASE_DRAGON_SOUL:
                speachindex = 14;
            }

            if(phase+speachindex > 18)
                return 5000;

            if(EventNpcSpeaching[speachindex+part].npc_entry != ENTRY_YOGG_SARON)
                npcguid = GetEventNPCGuid(EventNpcSpeaching[speachindex+part].npc_entry);
            else
                npcguid = guidYogg;

            if(Creature* speaker = Creature::GetCreature(*me,npcguid))
                DoScriptText(EventNpcSpeaching[speachindex+part].speech_entry,speaker);
            IsEventSpeaking = EventNpcSpeaching[speachindex+part].isSpeaking;
            return EventNpcSpeaching[speachindex+part].next_speech;
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_VEZAX) == DONE)
                if(uiRandomYell_Timer <= diff)
                {
                    SaraRandomYell();
                    uiRandomYell_Timer = urand(40000,60000);
                }else uiRandomYell_Timer -= diff;

            switch(m_Phase)
            {
                case PHASE_SARA:
                    if(uiGuardianSummon_Timer <= diff)
                    {
                        if(Creature* target = GetRandomCloudTarget(500.0f))
                            target->CastSpell(target,SPELL_SUMMON_GUARDIAN,true);

                        uilastGuardianSummon_Timer = uilastGuardianSummon_Timer-5000 <= 10000 ? 10000 : uilastGuardianSummon_Timer - 5000;
                        uiGuardianSummon_Timer = uilastGuardianSummon_Timer;
                    }else uiGuardianSummon_Timer -= diff;

                    if(uiSarasHelp_Timer <= diff)
                    {
                        switch(urand(0,2))
                        {
                        case 0:
                            if(Player* target = SelectPlayerTargetInRange(500.0f))
                                if(!IsPlayerInBrainRoom(target))
                                DoCast(target,SPELL_SARAS_FERVOR,false);
                            break;
                        case 1:
                            if(Player* target = SelectPlayerTargetInRange(500.0f))
                                if(!IsPlayerInBrainRoom(target))
                                    DoCast(target,SPELL_SARAS_BLESSING,false);
                        case 2:
                            if(Unit* target = GetRandomEntryTarget(ENTRY_GUARDIAN_OF_YOGG_SARON,500.0f))
                                DoCast(target, SPELL_SARAS_ANGER, false);
                            break;
                        default: break;
                        }
                        uiSarasHelp_Timer = urand(5000,6000);
                    }else uiSarasHelp_Timer -= diff;

                    break;
                case PHASE_BRAIN:
                    if(IsSpeaking)
                    {
                        if(uiSpeaking_Timer <= diff)
                        {
                            switch(SpeakingPhase)
                            {
                            case 0:
                                //if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                //    yogg->SetVisible(true);

                                DoScriptText(SAY_PHASE2_1,me);
                                uiSpeaking_Timer = 5000;
                                break;
                            case 1:
                                DoScriptText(SAY_PHASE2_2,me);
                                uiSpeaking_Timer = 5000;
                                break;
                            case 2:
                                DoScriptText(SAY_PHASE2_3,me);
                                uiSpeaking_Timer = 4000;
                                break;
                            case 3:
                                DoScriptText(SAY_PHASE2_4,me);
                                uiSpeaking_Timer = 4000;
                                break;
                            case 4:
                                //me->SetDisplayId(SARA_TRANSFORM);
                                me->AddAura(SPELL_SARA_TRANSFORMATION,me);
                                DoCast(me,SPELL_SARA_SHADOWY_BARRIER,false);
                                me->GetMotionMaster()->MovePoint(1,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ()+20);
                                if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                {
                                    //yogg->SetDisplayId(YOGGSARON_NORMAL);
                                    yogg->CastSpell(yogg,SPELL_SHADOWY_BARRIER,false);
                                    yogg->SetStandState(UNIT_STAND_STATE_STAND);
                                    yogg->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    yogg->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    DoScriptText(SAY_PHASE2_5,yogg);

                                    yogg->CastSpell(yogg,SPELL_SUMMON_CURRUPTOR_TENTACLE,true);
                                }
                                me->setFaction(14);
                                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                uiSpeaking_Timer = 5000;
                                IsSpeaking = false;
                                break;
                            }
                            SpeakingPhase++;
                        }else uiSpeaking_Timer -= diff;
                    }else
                    {
                        if(IsEventSpeaking)
                        {
                            if(uiSpeaking_Timer <= diff)
                            {
                                uiSpeaking_Timer = DoEventSpeaking(currentBrainEventPhase,EventSpeakingPhase);
                                EventSpeakingPhase++;
                            }else uiSpeaking_Timer -= diff;
                        }

                        if(!me->HasAura(SPELL_SHATTERED_ILLUSIONS))
                        {
                            if(uiPsychosis_Timer <= diff)
                            {
                                if(Player* target = SelectPlayerTargetInRange(500.0f))
                                    if(!IsPlayerInBrainRoom(target))
                                        DoCast(target,SPELL_PSYCHOSIS,false);
                                uiPsychosis_Timer = urand(5000,5000);
                            }else uiPsychosis_Timer -= diff;

                            if(uiMindSpell_Timer <= diff)
                            {
                                if(!me->IsNonMeleeSpellCasted(false))
                                {
                                    switch(urand(0,2))
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
                                    uiMindSpell_Timer = 30000;
                                }
                            }else uiMindSpell_Timer -= diff;

                            if(uiTentacle_Timer <= diff)
                            {
                                if(urand(0,1) == 0)
                                {
                                    if(Player* target = SelectPlayerTargetInRange(500.0f))
                                        if(!IsPlayerInBrainRoom(target))
                                            target->CastSpell(target,SPELL_SUMMON_CONSTRICTOR_TENTACLES,true);
                                }else
                                {
                                    if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                        yogg->CastSpell(yogg,SPELL_SUMMON_CURRUPTOR_TENTACLE,true);
                                }
                                uiTentacle_Timer =  uiBrainEvents_Count < 4 ? urand(5000,10000) : urand(2000,5000);
                            }else uiTentacle_Timer -= diff;

                            if(uiTentacle1_Timer <= diff)
                            {
                                if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                    yogg->CastSpell(yogg,SPELL_SUMMON_CRUSHER_TENTACLE,true);
                                uiTentacle1_Timer = uiBrainEvents_Count < 4 ? urand(30000,40000) : urand(10000,15000);
                            }else uiTentacle1_Timer -= diff;


                        }else
                        {
                            if(Creature* yoggbrain = me->GetCreature(*me,guidYoggBrain))
                                if(!yoggbrain->IsNonMeleeSpellCasted(false))
                                {
                                    if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                        yogg->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                                    me->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);

                                    for(std::list<uint64>::iterator itr = Summons.begin(); itr != Summons.end(); ++itr)
                                    {
                                        if(Creature* temp = Creature::GetCreature(*me,*itr))
                                        {
                                            switch(temp->GetEntry())
                                            {
                                            case ENTRY_CONSTRICTOR_TENTACLE:
                                            case ENTRY_CORRUPTOR_TENTACLE:
                                            case ENTRY_CRUSHER_TENTACLE:
                                                    temp->RemoveAurasDueToSpell(SPELL_SHATTERED_ILLUSIONS);
                                                break;
                                            }
                                        }
                                    }
                                }
                        }

                        if(uiMadness_Timer <= diff)
                        {
                            if(Creature* yogg = me->GetCreature(*me,guidYogg))
                            {
                                DoScriptText(SAY_VISION,yogg);
                                DoMadness();
                            }

                            //Say YoggSaron to Open Portals
                            uiMadness_Timer = 80000;
                        }else uiMadness_Timer -= diff;

                        if(!me->HasAura(SPELL_SHATTERED_ILLUSIONS))
                        {
                            if(currentBrainEventPhase != PORTAL_PHASE_BRAIN_NONE)
                            {
                                if(AllSpawnsDeadOrDespawned(guidEventTentacles))
                                {
                                    switch(currentBrainEventPhase)
                                    {
                                    case PORTAL_PHASE_DRAGON_SOUL: if(m_pInstance) m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_1),true); break;
                                    case PORTAL_PHASE_LICH_KING: if(m_pInstance) m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_2),true); break;
                                    case PORTAL_PHASE_KING_LLIANE: if(m_pInstance) m_pInstance->HandleGameObject(m_pInstance->GetData64(TYPE_BRAIN_DOOR_3),true); break;
                                    }
                                    currentBrainEventPhase = PORTAL_PHASE_BRAIN_NONE;
                                    IsEventSpeaking = false;
                                    if(Creature* yogg = me->GetCreature(*me,guidYogg))
                                        me->AddAura(SPELL_SHATTERED_ILLUSIONS,yogg);
                                    me->AddAura(SPELL_SHATTERED_ILLUSIONS,me);

                                    if(Creature* yoggbrain = me->GetCreature(*me,guidYoggBrain))
                                        yoggbrain->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                                    for(std::list<uint64>::iterator itr = Summons.begin(); itr != Summons.end(); ++itr)
                                    {
                                        if(Creature* temp = Creature::GetCreature(*me,*itr))
                                        {
                                            switch(temp->GetEntry())
                                            {
                                            case ENTRY_CONSTRICTOR_TENTACLE:
                                            case ENTRY_CORRUPTOR_TENTACLE:
                                            case ENTRY_CRUSHER_TENTACLE:
                                                    me->AddAura(SPELL_SHATTERED_ILLUSIONS,temp);
                                                break;
                                            }
                                        }
                                    }
                                    DoKillAndDespawnGUIDs(guidEventSkulls);
                                }
                            }
                        }
                    }
                    break;
                case PHASE_YOGG:
                    if(uiGuardianSummon_Timer <= diff)
                    {
                        if(Creature* yogg = me->GetCreature(*me,guidYogg))
                            yogg->CastSpell(yogg,SPELL_SUMMON_IMMORTAL_GUARDIAN,true);

                        uilastGuardianSummon_Timer = uilastGuardianSummon_Timer-5000 <= 10000 ? 10000 : uilastGuardianSummon_Timer - 5000;
                        uiGuardianSummon_Timer = uilastGuardianSummon_Timer;
                    }else uiGuardianSummon_Timer -= diff;

                    if(uiLunaticGaze_Timer <= diff)
                    {
                        if(Creature* yogg = me->GetCreature(*me,guidYogg))
                        {
                            if(!yogg->IsNonMeleeSpellCasted(false))
                            {
                                DoScriptText(SAY_LUNCATIC_GLAZE,yogg,0);
                                yogg->CastSpell(yogg,SPELL_LUNATIC_GAZE,false);
                                uiLunaticGaze_Timer = 12000;
                            }
                        }
                    }else uiLunaticGaze_Timer -= diff;

                    if(GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL && uiAmountKeeperActive < 4)
                        if(uiDeafeningRoar_Timer <= diff)
                        {
                            if(Creature* yogg = me->GetCreature(*me,guidYogg))
                            {
                                if(!yogg->IsNonMeleeSpellCasted(false))
                                {
                                    DoScriptText(SAY_DEAFENING_ROAR,yogg,0);
                                    yogg->CastSpell(yogg,SPELL_DEAFENING_ROAR,false);
                                    uiDeafeningRoar_Timer = 60000;
                                }
                            }
                        }else uiDeafeningRoar_Timer -= diff;

                    if(uiShadowBeacon_Timer <= diff)
                    {
                        if(Creature* yogg = me->GetCreature(*me,guidYogg))
                        {
                            if(!yogg->IsNonMeleeSpellCasted(false))
                            {
                                yogg->CastSpell(yogg,SPELL_SHADOW_BEACON,false);
                                uiShadowBeacon_Timer = 30000;
                            }
                        }
                    }else uiShadowBeacon_Timer -= diff;

                    break;
            }

            if(m_Phase != PHASE_NONE)
            {
                if(uiEnrage_Timer <= diff)
                {
                    if(Creature* yogg = me->GetCreature(*me,guidYogg))
                    {
                        yogg->InterruptNonMeleeSpells(false);
                        yogg->CastSpell(yogg,SPELL_EXTINGUISH_ALL_LIFE,false);
                    }
                    uiEnrage_Timer = 5000;
                }else uiEnrage_Timer -= diff;
            }

            if(m_Phase != PHASE_NONE && !IsEncounterInProgress())
                EnterEvadeMode();

            // temporary
            if (m_Phase == PHASE_NONE && me->isInCombat())
                EnterEvadeMode();
        }
    };
};

class npc_ominous_cloud : public CreatureScript
{
public:
    npc_ominous_cloud() : CreatureScript("npc_ominous_cloud") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ominous_cloudAI (pCreature);
    }

    struct npc_ominous_cloudAI : public ScriptedAI
    {
        npc_ominous_cloudAI(Creature *c) : ScriptedAI(c)
        {
            SetImmuneToPushPullEffects(true);
            m_pInstance = c->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        void MoveInLineOfSight(Unit* target)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) == IN_PROGRESS)
                if(target && me->GetDistance2d(target) <= 5 && target->ToPlayer() && !target->ToPlayer()->isGameMaster() && !target->HasAura(SPELL_FLASH_FREEZE))
                    TriggerGuardianSpawn();
        }

        void AttackStart(Unit* /*attacker*/) {}

        void DoAction(const int32 action)
        {
            switch(action)
            {
            case ACTION_DEACTIVATE_CLOUDS:
                me->RemoveAurasDueToSpell(SPELL_SUMMON_GUARDIAN);
                me->RemoveAurasDueToSpell(SPELL_OMINOUS_CLOUD_EFFECT);
                me->SetReactState(REACT_PASSIVE);
                break;
            case ACTION_ACTIVATE_CLOUDS:
                Reset();
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            }
        }

        void TriggerGuardianSpawn()
        {
            if(!me->HasAura(SPELL_SUMMON_GUARDIAN))
                DoCast(me,SPELL_SUMMON_GUARDIAN,true);
        }

        void Reset()
        {
            DoCast(me,SPELL_OMINOUS_CLOUD_EFFECT,true);
            me->RemoveAurasDueToSpell(SPELL_SUMMON_GUARDIAN);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            //me->SetReactState(REACT_PASSIVE); //Prevent MoveInLineOfSight

            me->GetMotionMaster()->MoveRandom(25.0f);
        }

        void UpdateAI(const uint32 diff) {}
    };
};

class npc_guardian_of_yogg_saron : public CreatureScript
{
public:
    npc_guardian_of_yogg_saron() : CreatureScript("npc_guardian_of_yogg_saron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_guardian_of_yogg_saronAI (pCreature);
    }

    struct npc_guardian_of_yogg_saronAI : public ScriptedAI
    {
        npc_guardian_of_yogg_saronAI(Creature *c) : ScriptedAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            me->setFaction(14);

            //SpellInfo *TempSpell;
            //TempSpell = GET_SPELL(SPELL_SHADOW_NOVA);
            //if (TempSpell)
            //    TempSpell->Effect[1] = 0;
        }

        InstanceScript* m_pInstance;
        uint32 uiDarkVolley_Timer;

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if(target && target->ToPlayer())
            {
                switch(spell->Id)
                {
                case SPELL_DARK_VOLLEY:
                    if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                        CAST_AI(boss_sara::boss_saraAI,cSara->AI())->ModifySanity(target->ToPlayer(),-2);
                    break;
                }
            }
        }

        Unit* SelectPlayerTargetInRange(float range)
        {
            Player *target = NULL;
            Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
            Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
            me->VisitNearbyObject(range, searcher);
            return target;
        }

        void JustDied(Unit* /*killer*/)
        {
            DoCast(me,SPELL_SHADOW_NOVA,true);
            if(m_pInstance)
            {
                if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                    if(me->GetDistance2d(cSara) <= 15)
                        cSara->AI()->DoAction(ACTION_NOVA_HIT);
            }

            me->DespawnOrUnsummon(5000);
        }

        void Reset()
        {
            uiDarkVolley_Timer = urand(20000,30000);
            if(Unit* target = SelectPlayerTargetInRange(100.0f))
                me->AI()->AttackStart(target);
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
            {
                me->DealDamage(me,me->GetMaxHealth());
                me->RemoveCorpse();
            }

            if (!UpdateVictim())
                return;

            if(uiDarkVolley_Timer <= diff)
            {
                DoCast(SPELL_DARK_VOLLEY);
                uiDarkVolley_Timer = urand(20000,30000);
            }else uiDarkVolley_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_yogg_saron_tentacle : public CreatureScript
{
public:
    npc_yogg_saron_tentacle() : CreatureScript("npc_yogg_saron_tentacle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_yogg_saron_tentacleAI (pCreature);
    }

    struct npc_yogg_saron_tentacleAI : public Scripted_NoMovementAI
    {
        npc_yogg_saron_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            SetTentacleType(c->GetEntry());
            once = false;
            me->setFaction(14);
            me->SetFlying(true);
            if(m_pInstance)
            {
                if(Creature* sara = Creature::GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                    sara->AI()->JustSummoned(me);
            }
        }

        InstanceScript* m_pInstance;
        TentacleType t_Type;
        bool once;
        uint32 uiTentacleSpell_Timer;

        void SetTentacleType(uint32 entry)
        {
            switch(entry)
            {
            case ENTRY_CRUSHER_TENTACLE : t_Type = CRUSHER_TENTACLE; break;
            case ENTRY_CORRUPTOR_TENTACLE : t_Type = CORRUPTOR_TENTACLE; break;
            case ENTRY_CONSTRICTOR_TENTACLE : t_Type = CONSTRICTOR_TENTACLE; break;
            default: t_Type = CORRUPTOR_TENTACLE; break;
            }
        }

        void MoveInLineOfSight(Unit* target)
        {
            if(target && me->GetDistance2d(target) <= me->GetMeleeReach() && target->ToPlayer() && !target->ToPlayer()->isGameMaster())
                AttackStartNoMove(target);
        }

        void AttackStart(Unit* /*target*/) {}

        Unit* SelectPlayerTargetInRange(float range)
        {
            Player *target = NULL;
            Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
            Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
            me->VisitNearbyObject(range, searcher);
            return target;
        }

        void JustDied(Unit* /*killer*/)
        {
            me->RemoveAurasDueToSpell(SPELL_TENTACLE_VOID_ZONE);

            me->DespawnOrUnsummon(5000);
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
            if(Unit* target = SelectPlayerTargetInRange(500.0f))
                AttackStartNoMove(target);

            DoCast(me,SPELL_TENTACLE_VOID_ZONE,true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();

            uiTentacleSpell_Timer = urand(5000,10000);
            switch(t_Type)
            {
            case CRUSHER_TENTACLE:
                DoCast(me,SPELL_CRUSH,true);
                DoCast(SPELL_FOCUS_ANGER);
                break;
            case CONSTRICTOR_TENTACLE:
                uiTentacleSpell_Timer = urand(20000,30000);
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
            {
                me->DealDamage(me,me->GetMaxHealth());
                me->RemoveCorpse();
            }

            if(!once)
            {
                DoCast(SPELL_ERUPT);
                once = true;
            }

            if (!UpdateVictim())
                return;

            if(uiTentacleSpell_Timer <= diff)
            {
                switch(t_Type)
                {
                case CRUSHER_TENTACLE:
                    if(!me->HasAura(SPELL_DIMISH_POWER))
                        DoCast(SPELL_DIMISH_POWER);
                    break;
                case CORRUPTOR_TENTACLE:
                    if(Unit* target = SelectPlayerTargetInRange(500.0f))
                        DoCast(target,RAND(SPELL_DRAINING_POISON,SPELL_BLACK_PLAGUE,SPELL_APATHY,SPELL_CURSE_OF_DOOM),false);
                    break;
                case CONSTRICTOR_TENTACLE:
                    if (Unit* target =  me->FindNearestPlayer(50.0f, true))
                        target->CastSpell(me, SPELL_LUNGE, true);
                    break;
                }
                uiTentacleSpell_Timer = urand(5000,7000);
            }else uiTentacleSpell_Timer -= diff;

            if(t_Type == CRUSHER_TENTACLE)
                DoMeleeAttackIfReady();
        }
    };
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
        if(pCreature && pCreature->AI())
            pTemp = CAST_AI(npc_descend_into_madnessAI,pCreature->AI())->bPhase;

        switch(pTemp)
        {
        case PORTAL_PHASE_KING_LLIANE:
        case PORTAL_PHASE_DRAGON_SOUL:
        case PORTAL_PHASE_LICH_KING:
            AcceptTeleport = true;
            posTeleportPosition = InnerBrainLocation[pTemp];
            break;
        default: AcceptTeleport = false; break;
        }

        if(AcceptTeleport)
        {
            if(pPlayer)
            {
                pPlayer->RemoveAurasDueToSpell(SPELL_BRAIN_LINK);
                pCreature->AddAura(SPELL_ILLUSION_ROOM,pPlayer);
                pPlayer->NearTeleportTo(posTeleportPosition.m_positionX,posTeleportPosition.m_positionY,posTeleportPosition.m_positionZ,posTeleportPosition.m_orientation,true);
                //pPlayer->CastSpell(pPlayer,SPELL_TELEPORT,true);
                CAST_AI(npc_descend_into_madnessAI,pCreature->AI())->bPhase = PORTAL_PHASE_BRAIN_NONE;
                AcceptTeleport = false;
                pPlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2,SPELL_ILLUSION_ROOM);
                pCreature->DespawnOrUnsummon(500);
            }

        }

        return true;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_descend_into_madnessAI (pCreature);
    }

    struct npc_descend_into_madnessAI : public Scripted_NoMovementAI
    {
        npc_descend_into_madnessAI(Creature *c) : Scripted_NoMovementAI(c)
        {
        }

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
            }
        }

        void Reset()
        {
            bPhase = PORTAL_PHASE_BRAIN_NONE;
        }

        void UpdateAI(uint32 const /*diff*/) {}
    };
};


class npc_brain_of_yogg_saron : public CreatureScript
{
public:
    npc_brain_of_yogg_saron() : CreatureScript("npc_brain_of_yogg_saron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_brain_of_yogg_saronAI (pCreature);
    }

    struct npc_brain_of_yogg_saronAI : public Scripted_NoMovementAI
    {
        npc_brain_of_yogg_saronAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->setFaction(14);
            me->SetFlying(true);
        }

        void DamageTaken(Unit* /*dealer*/, uint32 &damage)
        {
            if(damage > me->GetHealth())
                damage = me->GetHealth()-1;
        }

        void SpellHitTarget(Unit *target, const SpellInfo *spell)
        {
            if(!target->ToPlayer())
                return;

            if(spell->Id == SPELL_INDUCE_MADNESS)
            {
                if(IsPlayerInBrainRoom(target->ToPlayer()))
                    target->RemoveAurasDueToSpell(SPELL_SANITY);
            }
        }

        InstanceScript* m_pInstance;

        void UpdateAI(uint32 const /*diff*/)
        {
            if(HealthBelowPct(31))
            {
                if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                        cSara->AI()->DoAction(ACTION_BRAIN_UNDER_30_PERCENT);

                if(!me->HasAura(SPELL_BRAIN_HURT_VISUAL))
                    DoCast(me,SPELL_BRAIN_HURT_VISUAL,true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }
    };
};

class boss_yogg_saron : public CreatureScript
{
public:
    boss_yogg_saron() : CreatureScript("boss_yogg_saron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_yogg_saronAI (pCreature);
    }

    struct boss_yogg_saronAI : public Scripted_NoMovementAI
    {
        boss_yogg_saronAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING | MOVEMENTFLAG_SWIMMING);
        }

        InstanceScript* m_pInstance;
        uint32 uiSanityCheck_Timer;
        bool bUsedMindControll;

        void Reset()
        {
            uiSanityCheck_Timer = 1000;
            bUsedMindControll = false;
        }

        void JustDied(Unit* killer)
        {
            if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                cSara->AI()->DoAction(ACTION_YOGGSARON_KILLED);

            DoScriptText(SAY_DEATH,me);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if(!m_pInstance) return;

            if(target && target->ToPlayer())
            {
                switch(spell->Id)
                {
                case SPELL_LUNATIC_GAZE_EFFECT:
                    if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                        CAST_AI(boss_sara::boss_saraAI,cSara->AI())->ModifySanity(target->ToPlayer(),-4);
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
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                return;

            if(uiSanityCheck_Timer <= diff)
            {
                if(me->GetMap() && me->GetMap()->IsDungeon())
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (!players.isEmpty())
                        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            if (Player* plr = itr->getSource())
                                if(plr->isAlive() && !plr->isGameMaster())
                                    if(!plr->HasAura(SPELL_SANITY) && !plr->HasAura(SPELL_INSANE))
                                    {
                                        // Dont make GMs Insane
                                        if(plr->GetSession()->GetSecurity() > SEC_PLAYER)
                                            continue;

                                        // Say Sara we used Mindcontrol - for Archievment ... we need only one mindecontrolled Player to cancel Achievment
                                        if(!bUsedMindControll)
                                        {
                                            if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                                                cSara->AI()->DoAction(ACTION_USED_MINDCONTROL);
                                            bUsedMindControll = true;
                                        }

                                        // Do Not Cast because its AoE and need better targeting scripting
                                        //DoCast(plr,SPELL_INSANE,true);
                                        //DoCast(plr,SPELL_INSANE_2,true);
                                        if(IsPlayerInBrainRoom(plr))
                                        {
                                            plr->RemoveAurasDueToSpell(SPELL_ILLUSION_ROOM);
                                            plr->NearTeleportTo(SaraLocation.GetPositionX(),SaraLocation.GetPositionY(),SaraLocation.GetPositionZ(),M_PI,false);
                                        }

                                        me->AddAura(SPELL_INSANE,plr);
                                        me->AddAura(SPELL_INSANE_2,plr);
                                        DoScriptText(RAND(WHISP_INSANITY_1,WHISP_INSANITY_2),me,plr);
                                    }
                }

                uiSanityCheck_Timer = 1000;
            }else uiSanityCheck_Timer -= diff;
        }
    };
};

class npc_influence_tentacle : public CreatureScript
{
public:
    npc_influence_tentacle() : CreatureScript("npc_influence_tentacle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_influence_tentacleAI (pCreature);
    }

    struct npc_influence_tentacleAI : public Scripted_NoMovementAI
    {
        npc_influence_tentacleAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->RemoveAurasDueToSpell(SPELL_TENTACLE_VOID_ZONE);
        }

        void Reset()
        {
        }

        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            if(attacker->ToPlayer())
                me->CastCustomSpell(SPELL_GRIM_REPRISAL_DAMAGE, SPELLVALUE_BASE_POINT0, int32(damage *0.60), attacker,true);
        }

        void EnterCombat(Unit* /*attacker*/)
        {
            if(me->GetEntry() != ENTRY_INFULENCE_TENTACLE)
            {
                me->UpdateEntry(ENTRY_INFULENCE_TENTACLE);
                me->setFaction(14);
                me->setRegeneratingHealth(false);
                DoCast(SPELL_GRIM_REPRISAL);

                DoCast(me,SPELL_TENTACLE_VOID_ZONE,true);
            }
        }
    };
};

class npc_immortal_guardian : public CreatureScript
{
public:
    npc_immortal_guardian() : CreatureScript("npc_immortal_guardian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_immortal_guardianAI (pCreature);
    }

    struct npc_immortal_guardianAI : public ScriptedAI
    {
        npc_immortal_guardianAI(Creature *c) : ScriptedAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            me->setFaction(14);
            SetImmuneToPushPullEffects(true);
        }

        InstanceScript* m_pInstance;

        uint32 uiDrainLife_Timer;

        Unit* SelectPlayerTargetInRange(float range)
        {
            Player *target = NULL;
            Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
            Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
            me->VisitNearbyObject(range, searcher);
            return target;
        }

        void Reset()
        {
            if(Unit* target = SelectPlayerTargetInRange(100.0f))
                me->AI()->AttackStart(target);

            uiDrainLife_Timer = 10000;
        }

        void JustDied(Unit* /*killer*/)
        {
            me->DespawnOrUnsummon(5000);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
        {
            if(spell->Id == 64172) // Titanic Storm
            {
                if(me->HasAura(SPELL_WEAKENED))
                    me->DealDamage(me,me->GetHealth());
            }
        }

        void DamageTaken(Unit* dealer, uint32 &damage)
        {
            if(dealer->GetGUID() == me->GetGUID())
                return;

            if(me->GetHealth() < damage)
                damage = me->GetHealth()-1;
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
            {
                me->DealDamage(me,me->GetMaxHealth());
                me->RemoveCorpse();
            }

            {
                int8 stacks = int8(uint32(me->GetHealthPct()) / 10);
                if(stacks > 9) stacks = 9;

                if(stacks > 0)
                {
                    me->RemoveAurasDueToSpell(SPELL_WEAKENED);
                    if(!me->HasAura(SPELL_EMPOWERED))
                        me->AddAura(SPELL_EMPOWERED,me);
                    me->SetAuraStack(SPELL_EMPOWERED,me,stacks);
                }else
                {
                    me->RemoveAurasDueToSpell(SPELL_EMPOWERED);
                    if(!me->HasAura(SPELL_WEAKENED))
                        me->AddAura(SPELL_WEAKENED,me);
                }
            }

            if(m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
                return;

            if (!UpdateVictim())
                return;

            if(uiDrainLife_Timer < diff)
            {
                DoCast(me->getVictim(),RAID_MODE(SPELL_DRAIN_LIFE_10,SPELL_DRAIN_LIFE_25));
                uiDrainLife_Timer = 35000;
            }else uiDrainLife_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class AllSaronitCreaturesInRange
{
    public:
        AllSaronitCreaturesInRange(const WorldObject* pObject, float fMaxRange) : m_pObject(pObject), m_fRange(fMaxRange) {}
        bool operator() (Unit* pUnit)
        {
            if (IsSaronitEntry(pUnit->GetEntry()) && m_pObject->IsWithinDist(pUnit,m_fRange,false) && pUnit->isAlive())
                return true;

            return false;
        }

    private:
        const WorldObject* m_pObject;
        float m_fRange;

        bool IsSaronitEntry(uint32 entry)
        {
            switch(entry)
            {
            case ENTRY_GUARDIAN_OF_YOGG_SARON:
            case ENTRY_CONSTRICTOR_TENTACLE:
            case ENTRY_CORRUPTOR_TENTACLE:
            case ENTRY_CRUSHER_TENTACLE:
            case ENTRY_IMMORTAL_GUARDIAN:
                return true;
            }
            return false;
        }
};

class npc_support_keeper : public CreatureScript
{
public:
    npc_support_keeper() : CreatureScript("npc_support_keeper") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_support_keeperAI (pCreature);
    }

    struct npc_support_keeperAI : public Scripted_NoMovementAI
    {
        npc_support_keeperAI(Creature *c) : Scripted_NoMovementAI(c) , Summons(me)
        {
            m_pInstance = c->GetInstanceScript();
        }

        SummonList Summons;
        InstanceScript* m_pInstance;

        uint32 uiSecondarySpell_Timer;

        bool summoning;
        bool summoned;

        void AttackStart(Unit *attacker) {}

        void Reset()
        {
            uint32 auraspell = 0;
            switch(me->GetEntry())
            {
            case ENTRY_KEEPER_HODIR:
                auraspell = SPELL_FORTITUDE_OF_FROST;
                break;
            case ENTRY_KEEPER_FREYA:
                auraspell = SPELL_RESILIENCE_OF_NATURE;
                break;
            case ENTRY_KEEPER_THORIM:
                auraspell = SPELL_FURY_OF_THE_STORM;
                break;
            case ENTRY_KEEPER_MIMIRON:
                auraspell = SPELL_SPEED_OF_INVENTION;
                break;
            }
            DoCast(auraspell);

            summoning = false;
            summoned = false;

            uiSecondarySpell_Timer = 10000;
        }

        void JustSummoned(Creature* pSummoned)
        {
            Summons.Summon(pSummoned);
        }

        void DoSummonSanityWells()
        {
            for(uint8 i = 0; i < 5 ; i++)
                DoSummon(ENTRY_SANITY_WELL,FreyaSanityWellLocation[i],0,TEMPSUMMON_MANUAL_DESPAWN);
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
            if(uiSecondarySpell_Timer <= diff)
            {
                switch(me->GetEntry())
                {
                case ENTRY_KEEPER_THORIM:
                    if(!me->HasAura(SPELL_TITANIC_STORM))
                        DoCast(SPELL_TITANIC_STORM);

                    uiSecondarySpell_Timer = 10000;
                    return;
                case ENTRY_KEEPER_FREYA:
                    if(!summoned)
                    {
                        if(!summoning)
                        {
                            DoCast(SPELL_SANITY_WELL);
                            uiSecondarySpell_Timer = 3000;
                            summoning = true;
                        }else
                        {
                            DoSummonSanityWells();
                            summoned = true;
                        }
                    }
                    return;
                case ENTRY_KEEPER_MIMIRON:
                    {
                        std::list<Creature*> creatureList;
                        GetAliveSaronitCreatureListInGrid(creatureList,5000);
                        if(!creatureList.empty())
                        {
                            std::list<Creature*>::iterator itr = creatureList.begin();
                            advance(itr, urand(0, creatureList.size()-1));
                            DoCast((*itr),SPELL_DESTABILIZATION_MATRIX,false);
                        }
                    }
                    uiSecondarySpell_Timer = 30000;
                    return;
                case ENTRY_KEEPER_HODIR:
                    {
                        if(!me->HasAura(SPELL_HODIRS_PROTECTIVE_GAZE))
                            DoCast(me,SPELL_HODIRS_PROTECTIVE_GAZE,false);
                        uiSecondarySpell_Timer = 25000;
                    }
                }
                uiSecondarySpell_Timer = 10000;
            }else
            {
                if(me->GetEntry() == ENTRY_KEEPER_HODIR)
                {
                    if(!me->HasAura(SPELL_HODIRS_PROTECTIVE_GAZE))
                        uiSecondarySpell_Timer -= diff;
                }else uiSecondarySpell_Timer -= diff;
            }
        }
    };
};

class npc_sanity_well : public CreatureScript
{
public:
    npc_sanity_well() : CreatureScript("npc_sanity_well") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_sanity_wellAI (pCreature);
    }

    struct npc_sanity_wellAI : public Scripted_NoMovementAI
    {
        npc_sanity_wellAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 uiSanityTick_Timer;

        void Reset()
        {
            DoCast(SPELL_SANITY_WELL_OPTIC);
            uiSanityTick_Timer = 2000;
        }

        void AttackStart(Unit* /*who*/) {}

        void MoveInLineOfSight(Unit *mover)
        {
            if(mover && mover->ToPlayer() )
                if(me->IsWithinDist2d(mover,6))
                {
                    if(!mover->HasAura(SPELL_SANITY_WELL_DEBUFF))
                        me->AddAura(SPELL_SANITY_WELL_DEBUFF,mover);
                }else
                {
                    if(mover->HasAura(SPELL_SANITY_WELL_DEBUFF))
                        mover->RemoveAurasDueToSpell(SPELL_SANITY_WELL_DEBUFF);
                }
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetBossState(BOSS_YOGGSARON) != IN_PROGRESS)
            {
                me->DealDamage(me,me->GetMaxHealth());
                me->RemoveCorpse();
            }

            if(uiSanityTick_Timer <= diff)
            {
                std::list<Player*> plrList = me->GetNearestPlayersList(10);
                for (std::list<Player*>::const_iterator itr = plrList.begin(); itr != plrList.end(); ++itr)
                {
                    if((*itr))
                    {
                        if((*itr)->HasAura(SPELL_SANITY_WELL_DEBUFF))
                        {
                            if(Creature* sara = Creature::GetCreature((*me),m_pInstance->GetData64(TYPE_SARA)))
                                CAST_AI(boss_sara::boss_saraAI,sara->AI())->ModifySanity((*itr),10);
                        }
                    }
                }
                uiSanityTick_Timer = 2000;
            }else uiSanityTick_Timer -= diff;
        }
    };
};

class npc_laughting_skull : public CreatureScript
{
public:
    npc_laughting_skull() : CreatureScript("npc_laughting_skull") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_laughting_skullAI (pCreature);
    }

    struct npc_laughting_skullAI : public Scripted_NoMovementAI
    {
        npc_laughting_skullAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        void Reset()
        {
            DoCast(SPELL_LS_LUNATIC_GAZE);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if(!m_pInstance) return;

            if(target && target->ToPlayer())
            {
                switch(spell->Id)
                {
                case SPELL_LS_LUNATIC_GAZE_EFFECT:
                    if(Creature* cSara = me->GetCreature(*me,m_pInstance->GetData64(TYPE_SARA)))
                        CAST_AI(boss_sara::boss_saraAI,cSara->AI())->ModifySanity(target->ToPlayer(),-2);
                    break;
                }
            }
        }

        void AttackStart(Unit* /*who*/) {}

        void UpdateAI(uint32 const /*diff*/)
        {
        }
    };
};

class npc_death_orb : public CreatureScript
{
public:
    npc_death_orb() : CreatureScript("npc_death_orb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_death_orbAI (pCreature);
    }

    struct npc_death_orbAI : public Scripted_NoMovementAI
    {
        npc_death_orbAI(Creature *c) : Scripted_NoMovementAI(c) , Summons(me)
        {
            m_pInstance = c->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }

        SummonList Summons;
        InstanceScript* m_pInstance;
        bool prepaired;
        uint32 uiReathRayEffekt_Timer;

        void Reset()
        {
            me->SetFlying(true);
            me->setFaction(14);
            prepaired = false;
            Summons.DespawnAll();
            SummonDeathRays();
            uiReathRayEffekt_Timer = 5000;
            DoCast(me,SPELL_DEATH_RAY_ORIGIN_VISUAL,true);
        }

        void SummonDeathRays()
        {
            for(uint8 i = 0; i < 4; i++)
            {
                Position pos;
                me->GetNearPoint2D(pos.m_positionX,pos.m_positionY,float(rand_norm()*10 + 30),float(2*M_PI*rand_norm()));
                pos.m_positionZ = me->GetPositionZ();
                pos.m_positionZ = me->GetMap()->GetHeight(pos.GetPositionX(),pos.GetPositionY(),pos.GetPositionZ(),true,500.0f);

                DoSummon(ENTRY_DEATH_RAY,pos,20000,TEMPSUMMON_TIMED_DESPAWN);
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            switch(pSummoned->GetEntry())
            {
            case ENTRY_DEATH_RAY:
                pSummoned->setFaction(14);
                pSummoned->CastSpell(pSummoned,SPELL_DEATH_RAY_WARNING_VISUAL,true,0,0,me->GetGUID());
                pSummoned->SetReactState(REACT_PASSIVE);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                break;
            }

            Summons.Summon(pSummoned);
        }

        void AttackStart(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if(uiReathRayEffekt_Timer <= diff)
            {
                for(std::list<uint64>::iterator itr = Summons.begin(); itr != Summons.end(); ++itr)
                {
                    if(Creature* temp = me->GetCreature(*me,*itr))
                    {
                        temp->CastSpell(temp,SPELL_DEATH_RAY_PERIODIC,true);
                        temp->CastSpell(temp,SPELL_DEATH_RAY_DAMAGE_VISUAL,true,0,0,me->GetGUID());

                        temp->AI()->DoAction(ACTION_DEATH_RAY_MOVE);
                    }
                }
                uiReathRayEffekt_Timer = 30000;
            }else uiReathRayEffekt_Timer -= diff;
        }
    };
};

class npc_death_ray : public CreatureScript
{
public:
    npc_death_ray() : CreatureScript("npc_death_ray") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_death_rayAI (pCreature);
    }

    struct npc_death_rayAI : public ScriptedAI
    {
        npc_death_rayAI(Creature *c) : ScriptedAI(c)
        {
        }

        bool moving;

        void Reset()
        {
            moving = true;
        }

        void DoAction(const int32 action)
        {
            if(action == ACTION_DEATH_RAY_MOVE)
                moving = false;
        }

        void DoRandomMove()
        {
            Position pos;
            me->GetNearPoint2D(pos.m_positionX,pos.m_positionY,10,float(2*M_PI*rand_norm()));
            pos.m_positionZ = me->GetPositionZ();
            pos.m_positionZ = me->GetMap()->GetHeight(pos.GetPositionX(),pos.GetPositionY(),pos.GetPositionZ(),true,50.0f);
            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
            me->GetMotionMaster()->MovePoint(1,pos);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if(id != 1)
                return;

            moving = false;
        }

        void AttackStart(Unit* /*who*/) {}

        void UpdateAI(uint32 const /*diff*/)
        {
            if(!moving)
            {
                DoRandomMove();
                moving = true;
            }
        }
    };
};

class go_flee_to_surface : public GameObjectScript
{
public:
    go_flee_to_surface() : GameObjectScript("go_flee_to_surface") { }

    bool OnGossipHello(Player *pPlayer, GameObject * /*pGO*/)
    {
        pPlayer->RemoveAurasDueToSpell(SPELL_ILLUSION_ROOM);
        pPlayer->NearTeleportTo(SaraLocation.GetPositionX(),SaraLocation.GetPositionY(),SaraLocation.GetPositionZ(),M_PI,false);
        pPlayer->JumpTo(40.0f,15.0f,true);
        return false;
    }
};

class spell_keeper_support_aura_targeting : public SpellScriptLoader
{
    public:
        spell_keeper_support_aura_targeting() : SpellScriptLoader("spell_keeper_support_aura_targeting") { }

    class spell_keeper_support_aura_targeting_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_keeper_support_aura_targeting_AuraScript)
        void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            std::list<Unit*> targetList;
            aurEff->GetTargetList(targetList);

            for(std::list<Unit*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
                if(!(*iter)->ToPlayer() && (*iter)->GetGUID() != GetCasterGUID() )
                    (*iter)->RemoveAurasDueToSpell(GetSpellInfo()->Id);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_keeper_support_aura_targeting_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_keeper_support_aura_targeting_AuraScript();
    }
};

class DontLooksDirectlyInGazeCheck
{
    public:
        DontLooksDirectlyInGazeCheck(Unit* caster) : _caster(caster) { }

        bool operator() (Unit* unit)
        {
            Position pos;
            _caster->GetPosition(&pos);
            return !unit->HasInArc(static_cast<float>(M_PI), &pos);
        }

    private:
        Unit* _caster;
};

class spell_lunatic_gaze_targeting : public SpellScriptLoader
{
    public:
        spell_lunatic_gaze_targeting() : SpellScriptLoader("spell_lunatic_gaze_targeting") { }

        class spell_lunatic_gaze_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lunatic_gaze_targeting_SpellScript)

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(DontLooksDirectlyInGazeCheck(GetCaster()));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_lunatic_gaze_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_lunatic_gaze_targeting_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        // function which creates SpellScript
        SpellScript *GetSpellScript() const
        {
            return new spell_lunatic_gaze_targeting_SpellScript();
        }
};

class spell_brain_link_periodic_dummy : public SpellScriptLoader
{
    public:
        spell_brain_link_periodic_dummy() : SpellScriptLoader("spell_brain_link_periodic_dummy") { }

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
                    if(!trigger->GetMap()->IsDungeon())
                        return;

                    Map::PlayerList const &players = trigger->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->getSource())
                            if(player->HasAura(SPELL_BRAIN_LINK) && player->GetGUID() != trigger->GetGUID() )
                            {
                                trigger->CastSpell(player, SPELL_BRAIN_LINK_DUMMY, true);
                                if(Unit* caster = GetCaster())
                                if (!player->IsWithinDist(trigger, float(aurEff->GetAmount())))
                                {
                                    caster->CastSpell(trigger, SPELL_BRAIN_LINK_DAMAGE, true);
                                    if(InstanceScript* pInstance = caster->GetInstanceScript())
                                        if(caster->ToCreature() && caster->GetGUID() == pInstance->GetData64(TYPE_SARA))
                                            CAST_AI(boss_sara::boss_saraAI,caster->ToCreature()->AI())->ModifySanity(player,-2);
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

    AuraScript *GetAuraScript() const
    {
        return new spell_brain_link_periodic_dummy_AuraScript();
    }
};

class NotIsWeakenedImmortalCheck
{
    public:
        NotIsWeakenedImmortalCheck() { }

        bool operator() (Unit* unit)
        {
            return !(unit->HasAura(SPELL_WEAKENED));
        }
};

class spell_titanic_storm_targeting : public SpellScriptLoader
{
    public:
        spell_titanic_storm_targeting() : SpellScriptLoader("spell_titanic_storm_targeting") { }

        class spell_titanic_storm_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_titanic_storm_targeting_SpellScript)

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(NotIsWeakenedImmortalCheck());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_titanic_storm_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        // function which creates SpellScript
        SpellScript *GetSpellScript() const
        {
            return new spell_titanic_storm_targeting_SpellScript();
        }
};

class spell_insane_death_effekt : public SpellScriptLoader
{
    public:
        spell_insane_death_effekt() : SpellScriptLoader("spell_insane_death_effekt") { }

        class spell_insane_death_effekt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_insane_death_effekt_AuraScript)

            void HandleEffectRemove(AuraEffect const * /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if(Unit * target = GetTarget())
                    if(target->ToPlayer() && target->isAlive())
                        target->DealDamage(target,target->GetHealth());
            }

            // function registering
            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_insane_death_effekt_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_insane_death_effekt_AuraScript();
        }
};

class spell_summon_tentacle_position : public SpellScriptLoader
{
    public:
        spell_summon_tentacle_position() : SpellScriptLoader("spell_summon_tentacle_position") { }

        class spell_summon_tentacle_position_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_summon_tentacle_position_SpellScript);

            void ChangeSummonPos(SpellEffIndex /*effIndex*/)
            {
                WorldLocation summonPos = *GetTargetDest();
                if (Unit* caster = GetCaster())
                    summonPos.m_positionZ = caster->GetMap()->GetHeight(summonPos.GetPositionX(), summonPos.GetPositionY(), summonPos.GetPositionZ());

                SetTargetDest(summonPos);
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
        spell_empowering_shadows() : SpellScriptLoader("spell_empowering_shadows") { }

        class spell_empowering_shadows_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_empowering_shadows_SpellScript)

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit * target = GetHitUnit())
                {
                    uint32 spell = 0;
                    switch(target->GetMap()->GetDifficulty())
                    {
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                        spell = SPELL_EMPOWERING_SHADOWS_HEAL_10;
                        break;
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                        spell = SPELL_EMPOWERING_SHADOWS_HEAL_25;
                        break;
                    }
                    if(spell)
                        GetCaster()->CastSpell(target, spell, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_empowering_shadows_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        // function which creates SpellScript
        SpellScript *GetSpellScript() const
        {
            return new spell_empowering_shadows_SpellScript();
        }
};

// Hodir's Protective Gaze
class spell_hodir_protective_gaze : public SpellScriptLoader
{
public:
    spell_hodir_protective_gaze() : SpellScriptLoader("spell_hodir_protective_gaze") { }

    class spell_hodir_protective_gaze_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hodir_protective_gaze_AuraScript);

        bool Validate(SpellInfo const * /*spellEntry*/)
        {
            return sSpellMgr->GetSpellInfo(SPELL_FLASH_FREEZE_COOLDOWN);
        }

        //bool Load()
        //{
        //    return GetOwner()->ToPlayer();
        //}

        void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            std::list<Unit*> targetList;
            aurEff->GetTargetList(targetList);

            for(std::list<Unit*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
                if(!(*iter)->ToPlayer() && (*iter)->GetGUID() != GetCasterGUID() )
                    (*iter)->RemoveAurasDueToSpell(GetSpellInfo()->Id);
        }

        void CalculateAmount(AuraEffect const * /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            // Set absorbtion amount to unlimited
            amount = -1;
        }

        void Absorb(AuraEffect * /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            Unit * target = GetTarget();
            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            target->CastSpell(target, SPELL_FLASH_FREEZE, true);

            // absorb hp till 1 hp
            absorbAmount = dmgInfo.GetDamage() - target->GetHealth() + 1;

            // Remove Aura from Hodir
            if(GetCaster() && GetCaster()->ToCreature())
                GetCaster()->ToCreature()->RemoveAurasDueToSpell(SPELL_HODIRS_PROTECTIVE_GAZE);
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hodir_protective_gaze_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_hodir_protective_gaze_AuraScript::Absorb, EFFECT_0);
            OnEffectApply += AuraEffectApplyFn(spell_hodir_protective_gaze_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_hodir_protective_gaze_AuraScript();
    }
};

#define GOSSIP_KEEPER_HELP                  "Lend us your aid, keeper. Together we shall defeat Yogg-Saron."

class npc_keeper_help : public CreatureScript
{
public:
    npc_keeper_help() : CreatureScript("npc_keeper_help") { }

    bool OnGossipHello(Player* player, Creature* _Creature)
    {
        if(InstanceScript* m_pInstance = _Creature->GetInstanceScript())
        {
            uint32 supportFlag = m_pInstance->GetData(DATA_KEEPER_SUPPORT_YOGG);
            switch(_Creature->GetEntry())
            {
            case NPC_HELP_KEEPER_FREYA:
                if((supportFlag & FREYA_SUPPORT) == FREYA_SUPPORT)
                    return false;
                break;
            case NPC_HELP_KEEPER_MIMIRON:
                if((supportFlag & MIMIRON_SUPPORT) == MIMIRON_SUPPORT)
                    return false;
                break;
            case NPC_HELP_KEEPER_THORIM:
                if((supportFlag & THORIM_SUPPORT) == THORIM_SUPPORT)
                    return false;
                break;
            case NPC_HELP_KEEPER_HODIR:
                if((supportFlag & HODIR_SUPPORT) == HODIR_SUPPORT)
                    return false;
                break;
            }

            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_KEEPER_HELP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(_Creature), _Creature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* _Creature, uint32 sender, uint32 action)
    {
        player->CLOSE_GOSSIP_MENU();

        InstanceScript* instance = _Creature->GetInstanceScript();

        if(!instance) return false;

        if( action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            switch(_Creature->GetEntry())
            {
            case NPC_HELP_KEEPER_FREYA:
                DoScriptText(SAY_FREYA_HELP,_Creature,player);
                instance->SetData(DATA_ADD_HELP_FLAG,FREYA_SUPPORT);
                break;
            case NPC_HELP_KEEPER_MIMIRON:
                DoScriptText(SAY_MIMIRON_HELP,_Creature,player);
                instance->SetData(DATA_ADD_HELP_FLAG,MIMIRON_SUPPORT);
                break;
            case NPC_HELP_KEEPER_THORIM:
                DoScriptText(SAY_THORIM_HELP,_Creature,player);
                instance->SetData(DATA_ADD_HELP_FLAG,THORIM_SUPPORT);
                break;
            case NPC_HELP_KEEPER_HODIR:
                DoScriptText(SAY_HODIR_HELP,_Creature,player);
                instance->SetData(DATA_ADD_HELP_FLAG,HODIR_SUPPORT);
                break;
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_keeper_helpAI (pCreature);
    }

    struct npc_keeper_helpAI : public Scripted_NoMovementAI
    {
        npc_keeper_helpAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            m_pInstance = c->GetInstanceScript();
            me->setFaction(35);
        }

        InstanceScript* m_pInstance;

        void AttackStart(Unit *who) {}

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance)
            {
                if(m_pInstance->GetBossState(BOSS_YOGGSARON) == IN_PROGRESS)
                {
                    me->SetVisible(false);
                    return;
                }

                switch(me->GetEntry())
                {
                case NPC_HELP_KEEPER_FREYA:
                    me->SetVisible(m_pInstance->GetBossState(BOSS_FREYA) == DONE);
                    break;
                case NPC_HELP_KEEPER_MIMIRON:
                    me->SetVisible(m_pInstance->GetBossState(BOSS_MIMIRON) == DONE);
                    break;
                case NPC_HELP_KEEPER_THORIM:
                    me->SetVisible(m_pInstance->GetBossState(BOSS_THORIM) == DONE);
                    break;
                case NPC_HELP_KEEPER_HODIR:
                    me->SetVisible(m_pInstance->GetBossState(BOSS_HODIR) == DONE);
                    break;
                }
            }
        }
    };
};

class item_unbound_fragments_of_valanyr : public ItemScript
{
public:
    item_unbound_fragments_of_valanyr() : ItemScript("item_unbound_fragments_of_valanyr") { }

    bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& /*targets*/)
    {
        if(Creature* yogg = pPlayer->FindNearestCreature(ENTRY_YOGG_SARON,20))
        {
            if(yogg->FindCurrentSpellBySpellId(SPELL_DEAFENING_ROAR))
                return false;
        }

        pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW,pItem,NULL);
        return true;
    }
};

void AddSC_boss_yoggsaron()
{
    new boss_sara();
    new npc_ominous_cloud();
    new npc_guardian_of_yogg_saron();
    new npc_yogg_saron_tentacle();
    new npc_descend_into_madness();
    new npc_influence_tentacle();
    new npc_brain_of_yogg_saron();
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
}
