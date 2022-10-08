#include "siege_of_orgrimmar.hpp"
#include "SpellAuraEffects.h"
#include "Player.h"

// Information:
// 1. There are many spells that have triggers after 'jump' effects.
// Those triggers are handled in the core but not in the 'movementinform' function.
// 2. We don't use 'death from above' jump spells, we use jumps manually to prevent some bugs (targetting, speed and etc.).
// 3. We don't spawn hungry kunchongs randomly, we use const positions because of some bugs in vmaps.

// TODO:
// Use spells instead of manual summons of paragons and the fightstarter.
// Change fist paragons every week.
// Make random spawns of hungry kunchongs
// Make player buffs gained from mantids

enum ScriptedTexts
{
    SAY_KILRUK_AGGRO    = 0,
    SAY_KILRUK_DEATH    = 1,
    SAY_KILRUK_WIPE     = 2,
    SAY_KILRUK_INTRO    = 3,
    SAY_KILRUK_KILL     = 4,
    SAY_KILRUK_SPELL    = 5,

    SAY_XARIL_AGGRO     = 0,
    SAY_XARIL_DEATH     = 1,
    SAY_XARIL_WIPE      = 2,
    SAY_XARIL_INTRO     = 3,
    SAY_XARIL_KILL      = 4,
    SAY_XARIL_SPELL     = 5,

    SAY_KAZTIK_AGGRO    = 0,
    SAY_KAZTIK_DEATH    = 1,
    SAY_KAZTIK_WIPE     = 2,
    SAY_KAZTIK_INTRO    = 3,
    SAY_KAZTIK_KILL     = 4,
    SAY_KAZTIK_SPELL    = 5,

    SAY_KORVEN_AGGRO    = 0,
    SAY_KORVEN_DEATH    = 1,
    SAY_KORVEN_WIPE     = 2,
    SAY_KORVEN_INTRO    = 3,
    SAY_KORVEN_KILL     = 4,
    SAY_KORVEN_SPELL    = 5,

    SAY_IYYOKUK_AGGRO   = 0,
    SAY_IYYOKUK_DEATH   = 1,
    SAY_IYYOKUK_WIPE    = 2,
    SAY_IYYOKUK_INTRO   = 3,
    SAY_IYYOKUK_KILL    = 4,
    SAY_IYYOKUK_SPELL   = 5,

    SAY_KAROZ_AGGRO     = 0,
    SAY_KAROZ_DEATH     = 1,
    SAY_KAROZ_WIPE      = 2,
    SAY_KAROZ_INTRO     = 3,
    SAY_KAROZ_KILL      = 4,
    SAY_KAROZ_SPELL     = 5,

    SAY_SKEER_AGGRO     = 0,
    SAY_SKEER_DEATH     = 1,
    SAY_SKEER_WIPE      = 2,
    SAY_SKEER_INTRO     = 3,
    SAY_SKEER_KILL      = 4,
    SAY_SKEER_SPELL     = 5,

    SAY_RIKKAL_AGGRO    = 0,
    SAY_RIKKAL_DEATH    = 1,
    SAY_RIKKAL_WIPE     = 2,
    SAY_RIKKAL_INTRO    = 3,
    SAY_RIKKAL_KILL     = 4,
    SAY_RIKKAL_SPELL    = 5,

    SAY_HISEK_AGGRO     = 0,
    SAY_HISEK_DEATH     = 1,
    SAY_HISEK_WIPE      = 2,
    SAY_HISEK_INTRO     = 3,
    SAY_HISEK_KILL      = 4,
    SAY_HISEK_SPELL     = 5,
};

enum Spells
{
    SPELL_ACHIEVEMENT               = 148512,
    SPELL_ZERO_ENERGY               = 72242,

    // Controller spells
    SPELL_THE_KLAXXI_PARAGONS       = 146983,
    SPELL_BERSERK                   = 146982, // triggered by 146983 after 720 seconds (periodic)
    SPELL_SUMMON_FIGHT_STARTER      = 143552,
    SPELL_SUMMON_PARAGONS           = 141804,
    SPELL_SUMMON_PARAGON_KILRUK     = 141803, // 1589.198, -5701.658, -270.516
    SPELL_SUMMON_PARAGON_XARIL      = 141800, // 1602.252, -5765.936, -291.0546
    SPELL_SUMMON_PARAGON_KAZTIK     = 141799, // 1561.88, -5608.125, -291.0987
    SPELL_SUMMON_PARAGON_KORVEN     = 141798, // 1650.016, -5732.452, -291.0862
    SPELL_SUMMON_PARAGON_IYYOKUK    = 141802, // 1570.316, -5674.297, -270.566
    SPELL_SUMMON_PARAGON_KAROZ      = 141797, // 1552.964, -5640.806, -291.1562
    SPELL_SUMMON_PARAGON_SKEER      = 141795, // 1608.894, -5740.578, -290.9958
    SPELL_SUMMON_PARAGON_RIKKAL     = 141801, // 1624.321, -5730.018, -291.0036
    SPELL_SUMMON_PARAGON_HISEK      = 141796, // 1519.401, -5637.149, -291.1007
    SPELL_PING_AURA                 = 144354, // from sniffs
    SPELL_PING                      = 144353, // triggered by 144354, target players
    SPELL_READY_TO_FIGHT            = 143542,
    SPELL_BEEN_CLICKED              = 144834, // when a player clicks on

    // Fight Starter
    SPELL_COSMETIC_FOR_FIGHT_STARTER    = 143548,

    // Shared spells
    SPELL_MANTID_WINGS              = 132441, // triggered by klaxxi auras
    SPELL_JUMP_TO_CENTER            = 143545,
    SPELL_PARAGONS_PURPOSE_AURA     = 143482,
    SPELL_PARAGONS_PURPOSE_HEAL     = 143483,
    SPELL_DEFEATED                  = 142292,
    SPELL_DESPAWN_AREATRIGGERS      = 138175,

    // Kil'ruk the Wind-reaver
    SPELL_KILRUK_THE_WIND_REAVER    = 142926,
    SPELL_RAZOR_SHARP_BLADES        = 142918,
    SPELL_RAZOR_SHARP_BLADES_DMG    = 142922,
    SPELL_EXPOSED_VEINS             = 142931,
    SPELL_GOUGE                     = 143939,
    SPELL_MUTILATE                  = 143941,
    SPELL_DEATH_FROM_ABOVE_SUMMON   = 142263,
    SPELL_DEATH_FROM_ABOVE_JUMP_1   = 142264, // the boss jumps up
    SPELL_DEATH_FROM_ABOVE_JUMP_2   = 142265, // the boss jumps down
    SPELL_DEATH_FROM_ABOVE_DMG      = 142232,
    SPELL_DEATH_FROM_ABOVE_MARK     = 144126,
    SPELL_REAVE_AOE                 = 148677, // target players
    SPELL_REAVE                     = 148681,
    SPELL_REAVE_AURA                = 148676,
    SPELL_REAVE_DMG                 = 142228,

    // Xaril the Poisoned Mind
    SPELL_XARIL_THE_POISONED_MIND   = 142932,
    SPELL_TENDERIZING_STRIKES       = 142927,
    SPELL_TENDERIZING_STRIKES_DMG   = 142929,
    SPELL_CLEAR_TENDERIZING_STRIKES = 144122, // cannot find in sniffs
    SPELL_CAUSTIC_BLOOD             = 142315,
    SPELL_BLOODY_EXPLOSION_DUMMY    = 142782,
    SPELL_BLOODY_EXPLOSION_DMG      = 142317,
    SPELL_TOXIC_INJECTION           = 142528,
    SPELL_TOXIN_BLUE                = 142532,
    SPELL_TOXIN_RED                 = 142533,
    SPELL_TOXIN_YELLOW              = 142534,
    SPELL_CATALYST_BLUE             = 142725,
    SPELL_CATALYST_RED              = 142726,
    SPELL_CATALYST_YELLOW           = 142727,
    SPELL_CATALYST_ORANGE           = 142728,
    SPELL_CATALYST_GREEN            = 142730,
    SPELL_CATALYST_PURPLE           = 142729,
    SPELL_REACTION_BLUE             = 142735,
    SPELL_REACTION_RED              = 142736,
    SPELL_REACTION_YELLOW           = 142737,
    SPELL_REACTION_ORANGE           = 142738,
    SPELL_REACTION_GREEN            = 142740,
    SPELL_REACTION_PURPLE           = 142739,
    SPELL_NOXIOUS_VAPORS            = 142797,
    SPELL_EERIE_FOG_AURA            = 142812,
    SPELL_EERIE_FOG_SUMMON          = 142813,
    SPELL_EERIE_FOG_DMG             = 142945,
    SPELL_CANNED_HEAT               = 143570,
    SPELL_CANNED_HEAT_AURA          = 143572,
    SPELL_CANNED_HEAT_AREATRIGGER   = 143575,
    SPELL_CANNED_HEAT_DMG           = 143576,

    // Kaz'tik the Manipulator
    SPELL_SONIC_PROJECTION_AOE      = 143778, // targets players
    SPELL_SONIC_PROJECTION_AREATRIGGER  = 143765,
    SPELL_SONIC_PROJECTION_DMG      = 143768,
    SPELL_SUMMON_HUNGRY_KUNCHONG    = 146891, // is not found in sniffs
    SPELL_MESMERIZE_AOE             = 142668, // targets
    SPELL_MESMERIZE                 = 142671,

    // Hungry Kunchong
    SPELL_SWIPE                     = 142655,
    SPELL_MOLT                      = 142651, // after eating players (after devour?)
    SPELL_DEVOUR_1                  = 142649,
    SPELL_DEVOUR_2                  = 142705,
    SPELL_ENERGIZE                  = 142645, // triggered by 142649 periodicaly
    SPELL_HUNGRY                    = 142630,
    SPELL_DEVOUR_KILL               = 142638, // triggered by 142630 periodicaly
    SPELL_DEVOUR_AURA               = 142636, // marks the target for devour (142638)
    SPELL_THICK_SHELL               = 142667,

    // Korven the Prime
    SPELL_ENCASE_IN_AMBER           = 142564,
    SPELL_AMBER_REGENERATION        = 144119,
    SPELL_AMBER_BARRIER             = 144120,
    SPELL_SHIELD_BASH               = 143974,
    SPELL_VICIOUS_ASSAULT_PERIODIC  = 143977, // triggered by 143974
    SPELL_VICIOUS_ASSAULT_BLEED     = 143979,
    SPELL_VICIOUS_ASSAULT_DMG_1     = 143981,
    SPELL_VICIOUS_ASSAULT_DMG_2     = 143982,
    SPELL_VICIOUS_ASSAULT_DMG_3     = 143983,
    SPELL_VICIOUS_ASSAULT_DMG_4     = 143984,
    SPELL_VICIOUS_ASSAULT_DMG_5     = 143985,

    // Iyyokuk the Lucid
    SPELL_GREEN_MANTID_WINGS        = 126316,
    SPELL_DIMINISH                  = 143666,
    SPELL_RED_MANTID                = 143620,
    SPELL_PURPLE_MANTID             = 143621,
    SPELL_BLUE_MANTID               = 143622,
    SPELL_GREEN_MANTID              = 143623,
    SPELL_YELLOW_MANTID             = 143624,
    SPELL_RED_SWORD                 = 143605,
    SPELL_PURPLE_SWORD              = 143606,
    SPELL_BLUE_SWORD                = 143607,
    SPELL_GREEN_SWORD               = 143608,
    SPELL_YELLOW_SWORD              = 143609,
    SPELL_RED_STAFF                 = 143627,
    SPELL_PURPLE_STAFF              = 143628,
    SPELL_BLUE_STAFF                = 143629,
    SPELL_GREEN_STAFF               = 143630,
    SPELL_YELLOW_STAFF              = 143631,
    SPELL_RED_DRUM                  = 143610,
    SPELL_PURPLE_DRUM               = 143611,
    SPELL_BLUE_DRUM                 = 143612,
    SPELL_GREEN_DRUM                = 143613,
    SPELL_YELLOW_DRUM               = 143614,
    SPELL_RED_BOMB                  = 143615,
    SPELL_PURPLE_BOMB               = 143616,
    SPELL_BLUE_BOMB                 = 143617,
    SPELL_GREEN_BOMB                = 143618,
    SPELL_YELLOW_BOMB               = 143619,
    SPELL_CALCULATED                = 144095,
    SPELL_INSANE_CALCULATION_FIERY_EDGE = 142416,
    SPELL_FIERY_EDGE_DUMMY_1        = 142808, // main beam
    SPELL_FIERY_EDGE_DUMMY_2        = 142811, // prepare for main beam
    SPELL_FIERY_EDGE_DMG            = 142809,

    // Ka'roz the Locust
    SPELL_STORE_KINETIC_ENERGY      = 143709,
    SPELL_FLASH_AURA                = 143700,
    SPELL_FLASH_CHARGE              = 143704,
    SPELL_FLASH_DMG                 = 148594,
    SPELL_PICK_CHARGE_TARGET        = 143710, // triggered by 148594
    SPELL_WHIRLING                  = 143701,
    SPELL_WHIRLING_DMG              = 143702,
    SPELL_DASH                      = 143722,
    SPELL_LEAP                      = 143693, // triggered by 143722
    SPELL_HURL_AMBER_PERIODIC       = 143759, // triggered by 143693
    SPELL_HURL_AMBER_AOE            = 143761, // targets players
    SPELL_HURL_AMBER_MISSILE        = 143733,
    SPELL_CAUSTIC_AMBER_AREATRIGGER = 143740,
    SPELL_CAUSTIC_AMBER_DMG         = 143735,
    SPELL_STRONG_LEGS_BUFF          = 141853,
    SPELL_STRONG_LEGS_OVERRIDE      = 143963,
    SPELL_STRONG_LEGS_JUMP_1        = 143964,
    SPELL_STRONG_LEGS_JUMP_2        = 148608,
    SPELL_STRONG_LEGS_DUMMY         = 148650, // ?
    // There is a spell '143965' that don't exists in spell.dbc. I think it's used to give 143966 spell to players.
    SPELL_HURL_AMBER_MISSILE_2      = 143966, // used by players
    SPELL_CAUSTIC_AMBER_DMG_2       = 143967,

    // Skeer the Bloodseeker
    SPELL_HEWER_OF_FOES             = 143273,
    SPELL_HEW                       = 143274,
    SPELL_HEWN_DMG                  = 143275,
    SPELL_CLEAR_HEWN                = 144124,
    SPELL_LONG_REACH                = 144325,
    SPELL_BLOODLETTING              = 143280,
    SPELL_BLOODLETTING_MISSILE_SELF = 143282,
    SPELL_BLOODLETTING_MISSILE_1    = 143284,
    SPELL_BLOODLETTING_MISSILE_2    = 143287,
    SPELL_BLOODLETTING_MISSILE_3    = 143288,
    SPELL_BLOODLETTING_MISSILE_4    = 143289,
    SPELL_BLOODLETTING_SUMMON       = 143283,
    SPELL_GROW                      = 44833, // from sniffs
    SPELL_BLOOD_INFUSION            = 143294,

    // Rik'kal the Dissector
    SPELL_MAD_SCIENTIST             = 143277,
    SPELL_GENETIC_ALTERATION        = 143278,
    SPELL_GENETIC_ALTERATION_DMG    = 143279,
    SPELL_CLEAR_GENETIC_ALTERATION  = 144123,
    SPELL_INJECTION                 = 143340,
    SPELL_INJECTION_MISSILE         = 143383,
    SPELL_INJECTION_DUMMY           = 143339,
    SPELL_BIRTH                     = 143379, // triggered by 143383
    SPELL_HUNGER                    = 143358,
    SPELL_FEED                      = 143362,
    SPELL_GENETIC_MODIFICATIONS     = 143355,
    SPELL_REGENERATE                = 143356,
    SPELL_MUTATE_AOE                = 143336,
    SPELL_MUTATE                    = 143337,
    SPELL_FAULTY_MUTATION           = 148589,
    SPELL_FAULTY_MUTATION_DMG       = 148587,
    SPELL_CLAW                      = 143338,
    SPELL_SWIPE_DMG                 = 143378,
    SPELL_STING                     = 143376,
    SPELL_PREY                      = 144286,

    // Hisek the Swarmkeeper
    SPELL_MULTI_SHOT                = 144839,
    SPELL_AIM_AOE                   = 142948,
    SPELL_POINT_BLANK_SHOT          = 143505,
    SPELL_AIM_ROOT                  = 143505,
    SPELL_FIRE                      = 142950,
    SPELL_RAPID_FIRE                = 143243,
    SPELL_SONIC_PULSE_32            = 143226, // with 32 sec duration
    SPELL_SONIC_PULSE_30            = 143227,
    SPELL_SONIC_PULSE_28            = 143228,
    SPELL_SONIC_PULSE_26            = 143229,
    SPELL_SONIC_PULSE_24            = 143230,
    SPELL_SONIC_PULSE_22            = 143231,
    SPELL_SONIC_PULSE_20            = 143232,
    SPELL_SONIC_PULSE_18            = 143233,
    SPELL_SONIC_PULSE_16            = 143234,
    SPELL_SONIC_PULSE_14            = 143236,
    SPELL_SONIC_PULSE_12            = 143237,
    SPELL_SONIC_PULSE_10            = 143238,
    SPELL_SONIC_PULSE_DMG           = 143240,
};

#define FIERY_EDGE_DAMAGE_MIN 30000
#define FIERY_EDGE_DAMAGE_MAX 100000
#define FIERY_EDGE_DAMAGE_DIST_MAX 30.f

enum Adds
{
    NPC_MANTID_AMBER        = 71628, // is used as fight starter
    NPC_IMPACT_JUMP_TARGET  = 71309, // is used as the target for 'Death From Above'
    NPC_HUNGRY_KUNCHONG     = 71420, // is spawned by 'Summon Hungry Kunchong'
    NPC_AMBER               = 71407, // is spawned by 'Encase In Amber'
    NPC_BLOOD               = 71542, // is spawned by 'Bloodletting'
    NPC_AMBER_PARASITE      = 71578, // is spawned by 'Birth'
    NPC_AMBER_BOMB          = 71691, // used to be thrown by players
    NPC_EERIE_FOG           = 71453,
};

enum Events
{
    EVENT_CHECK_PLAYERS = 1,

    // Kil'ruk the Wind-reaver
    EVENT_GOUGE,
    EVENT_DEATH_FROM_ABOVE,
    EVENT_REAVE,

    // Xaril the Poisoned Mind
    EVENT_CATALYST,

    // Kaz'tik the Manipulator
    EVENT_SONIC_PROJECTION,
    EVENT_KUNCHONGS,
    EVENT_MESMERIZE,
    EVENT_SWIPE,

    // Korven the Prime
    EVENT_SHIELD_BASH,
    EVENT_ENCASE_IN_AMBER,

    // Iyyokuk the Lucid
    EVENT_DIMINISH,
    EVENT_INSANE_CALCULATION,

    // Ka'roz the Locust
    EVENT_FLASH,
    EVENT_HURL_AMBER,
    EVENT_HURL_AMBER_END,

    // Skeer the Bloodseeker
    EVENT_BLOODLETTING,
    EVENT_CHANGE_TARGET,

    // Rik'kal the Dissector
    EVENT_HUNGER,
    EVENT_FEED,
    EVENT_MUTATE,

    // Hisek the Swarmkeeper
    EVENT_MULTI_SHOT,
    EVENT_AIM,
    EVENT_RAPID_FIRE,
};

enum Timers
{
    TIMER_CHECK_PLAYERS             = 10 * IN_MILLISECONDS,
    PARAGONS_PURPOSE_TIMER          = 50 * IN_MILLISECONDS, // for heroic

    // Kil'ruk the Wind-reaver
    TIMER_GOUGE_FIRST               = 10 * IN_MILLISECONDS,
    TIMER_GOUGE                     = 20 * IN_MILLISECONDS,
    TIMER_DEATH_FROM_ABOVE_FIRST    = 20 * IN_MILLISECONDS,
    TIMER_DEATH_FROM_ABOVE          = 34 * IN_MILLISECONDS,
    TIMER_REAVE_FIRST               = 33 * IN_MILLISECONDS,
    TIMER_REAVE                     = 38 * IN_MILLISECONDS,

    // Xaril the Poisoned Mind
    TIMER_CATALYST_FIRST            = 20 * IN_MILLISECONDS,
    TIMER_CATALYST                  = 33 * IN_MILLISECONDS,

    // Kaz'tik the Manipulator
    TIMER_KUNCHONGS                 = 2 * IN_MILLISECONDS,
    TIMER_SONIC_PROJECTION_FIRST    = 8 * IN_MILLISECONDS,
    TIMER_SONIC_PROJECTION          = 20 * IN_MILLISECONDS,
    TIMER_MESMERIZE_FIRST           = 20 * IN_MILLISECONDS,
    TIMER_MESMERIZE                 = 34 * IN_MILLISECONDS,
    TIMER_SWIPE_FIRST               = 8 * IN_MILLISECONDS,
    TIMER_SWIPE                     = 25 * IN_MILLISECONDS,

    // Korven the Prime
    TIMER_SHIELD_BASH_FIRST         = 20 * IN_MILLISECONDS,
    TIMER_SHIELD_BASH               = 17 * IN_MILLISECONDS,
    TIMER_ENCASE_IN_AMBER_FIRST     = 30 * IN_MILLISECONDS,
    TIMER_ENCASE_IN_AMBER           = 30 * IN_MILLISECONDS,

    // Iyyokuk the Lucid
    TIMER_DIMINISH_FIRST            = 15 * IN_MILLISECONDS,
    TIMER_DIMINISH                  = 20 * IN_MILLISECONDS,
    TIMER_INSANE_CALCULATION_MIN    = 25 * IN_MILLISECONDS,
    TIMER_INSANE_CALCULATION_MAX    = 50 * IN_MILLISECONDS,

    // Ka'roz the Locust
    TIMER_FLASH_FIRST               = 15 * IN_MILLISECONDS,
    //TIMER_FLASH                     = 62 * IN_MILLISECONDS,
    //TIMER_HURL_AMBER_FIRST          = 40 * IN_MILLISECONDS,
    //TIMER_HURL_AMBER                = 62 * IN_MILLISECONDS,
    TIMER_FLASH                     = 30 * IN_MILLISECONDS,
    TIMER_HURL_AMBER                = 30 * IN_MILLISECONDS,
    TIMER_HURL_AMBER_END            = 5 * IN_MILLISECONDS,

    // Skeer the Bloodseeker
    TIMER_BLOODLETTING_FIRST        = 6 * IN_MILLISECONDS,
    TIMER_BLOODLETTING              = 35 * IN_MILLISECONDS,

    // Rik'kal the Dissector
    TIMER_HUNGER                    = 1 * IN_MILLISECONDS,
    TIMER_FEED_FIRST                = 1 * IN_MILLISECONDS,
    TIMER_FEED                      = 10 * IN_MILLISECONDS,
    TIMER_MUTATE_FIRST              = 23 * IN_MILLISECONDS,
    TIMER_MUTATE                    = 32 * IN_MILLISECONDS,

    // Hisek the Swarmkeeper
    TIMER_MULTI_SHOT_FIRST          = 2 * IN_MILLISECONDS,
    TIMER_MULTI_SHOT                = 5 * IN_MILLISECONDS,
    TIMER_AIM_FIRST                 = 32 * IN_MILLISECONDS,
    TIMER_AIM                       = 40 * IN_MILLISECONDS,
    TIMER_RAPID_FIRE                = 47 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_BEGIN_BATTLE = 1,
    ACTION_NEXT_BATTLE,
    ACTION_RESET_BATTLE,
    ACTION_FINISH_BATTLE,
    ACTION_MARK_NEXT_PARAGON,
    ACTION_PARAGON_DEFEATED,

    ACTION_MESMERIZE,
    ACTION_DEVOUR,
};

enum eData : int
{
    DATA_PARAGON_IN_FIGHT   = 1,
    DATA_DEATH_FROM_ABOVE_GUID,
    DATA_ENCASE_AMBER_GUID,
    DATA_ENCASE_AMBER_TARGET_ENABLE,
    DATA_ALL_PARAGONS_DIED,
};

enum Points : int
{
    POINT_DEATH_FROM_ABOVE_1    = 1,
    POINT_DEATH_FROM_ABOVE_2,
    POINT_HURL_AMBER,
};

enum ParagonTypes
{
    PARAGON_KILRUK,
    PARAGON_XARIL,
    PARAGON_KAZTIK,
    PARAGON_KORVEN,
    PARAGON_IYYOKUK,
    PARAGON_KAROZ,
    PARAGON_SKEER,
    PARAGON_RIKKAL,
    PARAGON_HISEK,

    PARAGON_COUNT,
};

// TODO: maybe need to make random sequence
// http://wow.gamepedia.com/Paragons_of_the_Klaxxi#Activation_Order
const ParagonTypes paragonsSequence[PARAGON_COUNT] =
{
    PARAGON_SKEER,
    PARAGON_RIKKAL,
    PARAGON_HISEK,
    PARAGON_KAROZ,
    PARAGON_KORVEN,
    PARAGON_IYYOKUK,
    PARAGON_XARIL,
    PARAGON_KAZTIK,
    PARAGON_KILRUK
};

const uint32 paragonsEntries[PARAGON_COUNT] =
{
    NPC_KILRUK_THE_WIND_REAVER,
    NPC_XARIL_THE_POISONED_MIND,
    NPC_KAZTIK_THE_MANIPULATOR,
    NPC_KORVEN_THE_PRIME,
    NPC_IYYOKUK_THE_LUCID,
    NPC_KAROZ_THE_LOCUST,
    NPC_SKEER_THE_BLOODSEEKER,
    NPC_RIKKAL_THE_DISSECTOR,
    NPC_HISEK_THE_SWARMKEEPER
};

#define INSANE_CALCULATION_SPELLS_COUNT 25
const uint32 insaneCalculationSpells[INSANE_CALCULATION_SPELLS_COUNT] =
{
    SPELL_RED_MANTID,
    SPELL_PURPLE_MANTID,
    SPELL_BLUE_MANTID,
    SPELL_GREEN_MANTID,
    SPELL_YELLOW_MANTID,
    SPELL_RED_SWORD,
    SPELL_PURPLE_SWORD,
    SPELL_BLUE_SWORD,
    SPELL_GREEN_SWORD,
    SPELL_YELLOW_SWORD,
    SPELL_RED_STAFF,
    SPELL_PURPLE_STAFF,
    SPELL_BLUE_STAFF,
    SPELL_GREEN_STAFF,
    SPELL_YELLOW_STAFF,
    SPELL_RED_DRUM,
    SPELL_PURPLE_DRUM,
    SPELL_BLUE_DRUM,
    SPELL_GREEN_DRUM,
    SPELL_YELLOW_DRUM,
    SPELL_RED_BOMB,
    SPELL_PURPLE_BOMB,
    SPELL_BLUE_BOMB,
    SPELL_GREEN_BOMB,
    SPELL_YELLOW_BOMB
};

#define SONIC_PULSE_SPELLS_COUNT 12
const uint32 sonicPulseSpells[SONIC_PULSE_SPELLS_COUNT] =
{
    SPELL_SONIC_PULSE_32,
    SPELL_SONIC_PULSE_30,
    SPELL_SONIC_PULSE_28,
    SPELL_SONIC_PULSE_26,
    SPELL_SONIC_PULSE_24,
    SPELL_SONIC_PULSE_22,
    SPELL_SONIC_PULSE_20,
    SPELL_SONIC_PULSE_18,
    SPELL_SONIC_PULSE_16,
    SPELL_SONIC_PULSE_14,
    SPELL_SONIC_PULSE_12,
    SPELL_SONIC_PULSE_10,
};

#define SONIC_PULSE_COUNT 5
const uint32 sonicPulseTriggers[SONIC_PULSE_COUNT] =
{
    1012, 1014, 1015, 1026, 1027
};

const Position paragonsPos[PARAGON_COUNT] =
{
    { 1589.198f, -5701.658f, -270.516f, 3.497437f },
    { 1602.252f, -5765.936f, -291.0546f, 1.814512f },
    { 1561.88f, -5608.125f, -291.0987f, 4.969732f },
    { 1650.016f, -5732.452f, -291.0862f, 2.539645f },
    { 1570.316f, -5674.297f, -270.566f, 6.128078f },
    { 1552.964f, -5640.806f, -291.1562f, 5.289442f },
    { 1608.894f, -5740.578f, -290.9958f, 2.023022f },
    { 1624.321f, -5730.018f, -291.0036f, 2.331927f },
    { 1519.401f, -5637.149f, -291.1007f, 5.62359f }
};

#define KUNCHONG_POSITION_COUNT 7
const Position kunchongPos[KUNCHONG_POSITION_COUNT] =
{
    { 1557.860718f, -5662.815918f, -314.76f, 4.002026f },
    { 1604.425415f, -5708.747070f, -314.76f, 1.634913f },
    { 1576.648926f, -5648.898926f, -314.76f, 3.482789f },
    { 1546.280640f, -5681.856934f, -314.72f, 4.548748f },
    { 1609.594849f, -5659.476074f, -314.65f, 2.251890f },
    { 1594.268555f, -5647.822266f, -314.72f, 3.073507f },
    { 1617.234131f, -5680.670898f, -314.70f, 1.439438f }
};

const Position fightstarterPos = { 1582.37f, -5685.979f, -314.4391f, 0.0f };

const Position jumpToCenterPos = { 1582.877f, -5696.859f, -314.6728f, 0.0f };

#define IMPACT_JUMP_TARGET_OFFSET 20.0f

const Position jumpToHurlAmberPos = { 1552.96f, -5640.80f, -291.14f, 5.28f };

#define BLOODLETTING_COUNT 4
#define BLOODLETTING_10 2
#define BLOODLETTING_25 3
#define BLOODLETTING_10H 3
#define BLOODLETTING_25H 4
const Position bloodlettingPos[BLOODLETTING_COUNT] =
{
    { 1590.69f, -5631.69f, -313.679f, 0.0f },
    { 1634.86f, -5697.51f, -313.696f, 0.0f },
    { 1575.19f, -5738.07f, -313.713f, 0.0f },
    { 1531.34f, -5672.67f, -313.68f, 0.0f }
};

#define AMBER_PARASITE_COUNT 3

#define AMBER_BOMB_COUNT 7
const Position amberBombPos[AMBER_BOMB_COUNT] =
{
    { 1544.156f, -5760.478f, -298.9232f, 0.f },
    { 1576.061f, -5745.816f, -294.7451f, 0.f },
    { 1641.865f, -5701.819f, -294.7451f, 0.f },
    { 1621.507f, -5609.722f, -298.9232f, 0.f },
    { 1667.226f, -5677.514f, -298.9232f, 0.f },
    { 1498.604f, -5692.389f, -298.9232f, 0.f },
    { 1589.493f, -5624.198f, -294.7452f, 0.f }
};

bool IsAmberBombNear(WorldObject* searcher)
{
    if (searcher->FindNearestCreature(NPC_AMBER_BOMB, 2.0f))
    {
        return true;
    }

    return false;
}

class npc_klaxxi_paragons : public CreatureScript
{
    public:
        npc_klaxxi_paragons() : CreatureScript("npc_klaxxi_paragons") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_klaxxi_paragonsAI(creature);
        }

        struct npc_klaxxi_paragonsAI : public Scripted_NoMovementAI
        {
            npc_klaxxi_paragonsAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);

                me->setActive(true);
            }

            void Reset() override
            {
                InitializeParagons();
            }

            void InitializeParagons()
            {
                ResetBattle();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_BEGIN_BATTLE)
                {
                    ParagonsBeginBattle();
                }
                else if (action == ACTION_PARAGON_DEFEATED)
                {
                    ParagonsDefeated();
                    ParagonsNextBattle();
                    ++m_ParagonsDied;
                    TryFinishBattle();
                }
                else if (action == ACTION_RESET_BATTLE)
                {
                    ParagonsResetBattle();
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_ALL_PARAGONS_DIED)
                {
                    return m_ParagonsDied >= PARAGON_COUNT ? 1 : 0;
                }

                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_CHECK_PLAYERS:
                        DoCheckPlayers();
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, TIMER_CHECK_PLAYERS);
                        break;
                }
            }

            void DoCheckPlayers()
            {
                std::list<Player*> players;
                me->GetPlayerListInGrid(players, 100.0f);

                if (players.empty())
                {
                    ParagonsResetBattle();
                }
            }

            void ResetBattle()
            {
                events.Reset();
                summons.DespawnAll();

                m_CurrentSequence = 0;
                m_ParagonsDied = 0;

                ClearAurasAndCreatures();

                me->RemoveAura(SPELL_THE_KLAXXI_PARAGONS);

                if (pInstance->GetBossState(DATA_PARAGONS_OF_THE_KLAXXI) != DONE)
                {
                    SpawnParagons();
                    SpawnAmberBombs();

                    pInstance->SetBossState(DATA_PARAGONS_OF_THE_KLAXXI, NOT_STARTED);
                }
            }

            void SpawnParagons()
            {
                for (uint8 i = 0; i < PARAGON_COUNT; ++i)
                {
                    if (Creature* pParagon = me->SummonCreature(paragonsEntries[i], paragonsPos[i]))
                    {
                        if (IsFirstActivated((ParagonTypes)i))
                        {
                            me->AddAura(SPELL_READY_TO_FIGHT, pParagon);
                        }
                    }
                }

                me->SummonCreature(NPC_MANTID_AMBER, fightstarterPos);
            }

            void SpawnAmberBombs()
            {
                for (uint8 i = 0; i < AMBER_BOMB_COUNT; ++i)
                {
                    me->SummonCreature(NPC_AMBER_BOMB, amberBombPos[i]);
                }
            }

            bool IsFirstActivated(ParagonTypes paragonType)
            {
                return paragonType == paragonsSequence[0] ||
                    paragonType == paragonsSequence[1] ||
                    paragonType == paragonsSequence[2];
            }

            void ParagonsBeginBattle()
            {
                me->AddAura(SPELL_THE_KLAXXI_PARAGONS, me);

                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_BEGIN_BATTLE, pred);

                MarkNextParagon();

                events.ScheduleEvent(EVENT_CHECK_PLAYERS, TIMER_CHECK_PLAYERS);

                if (pInstance)
                    pInstance->SetBossState(DATA_PARAGONS_OF_THE_KLAXXI, IN_PROGRESS);
            }

            void ParagonsDefeated()
            {
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_PARAGON_DEFEATED, pred);
            }

            void ParagonsNextBattle()
            {
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_NEXT_BATTLE, pred);

                MarkNextParagon();
            }

            void MarkNextParagon()
            {
                if (m_CurrentSequence + 3 >= PARAGON_COUNT)
                    return;

                ParagonTypes nextParagon = paragonsSequence[m_CurrentSequence + 3];
                uint32 nextParagonEntry = paragonsEntries[(int)nextParagon];

                EntryCheckPredicate pred(nextParagonEntry);
                summons.DoAction(ACTION_MARK_NEXT_PARAGON, pred);

                ++m_CurrentSequence;
            }

            void ParagonsResetBattle()
            {
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_RESET_BATTLE, pred);

                ResetBattle();
            }

            void TryFinishBattle()
            {
                if (m_ParagonsDied >= PARAGON_COUNT)
                {
                    DummyEntryCheckPredicate pred;
                    summons.DoAction(ACTION_FINISH_BATTLE, pred);

                    events.Reset();
                    // DON'T DESPAWN summons

                    ClearAurasAndCreatures();

                    Reward();

                    if (pInstance)
                    {
                        pInstance->SetBossState(DATA_PARAGONS_OF_THE_KLAXXI, DONE);
                    }

                    //BindToInstance();
                }
            }

            void Reward()
            {
                if (pInstance)
                {
                    //pInstance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ACHIEVEMENT, me);
                    //pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT);
                    pInstance->DoModifyPlayerCurrencies(396, 4000);
                }
            }

            /*void BindToInstance()
            {
                if (pInstance)
                    pInstance->DoPermBindPlayersForRaid();
            }*/

            void ClearAurasAndCreatures()
            {
                if (pInstance)
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXPOSED_VEINS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TENDERIZING_STRIKES_DMG);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_BLUE);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_RED);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_YELLOW);

                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEWN_DMG);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GENETIC_ALTERATION_DMG);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INJECTION_DUMMY);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HUNGER);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATE);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STRONG_LEGS_BUFF);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STRONG_LEGS_OVERRIDE);
                }

                me->DespawnCreaturesInArea(NPC_AMBER_PARASITE, 200);
            }

        private:

            InstanceScript* pInstance;
            uint32 m_CurrentSequence;
            uint32 m_ParagonsDied;
        };
};

struct paragon_of_klaxxiAI : public ScriptedAI
{
    paragon_of_klaxxiAI(Creature* creature) : ScriptedAI(creature),
        m_IsDefeated(false), m_IsInCombat(false), m_ParagonsPurposeTimer(PARAGONS_PURPOSE_TIMER)
    {
        pInstance = creature->GetInstanceScript();

        me->SetReactState(REACT_PASSIVE);

        me->SetDisableGravity(true);
        me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);

        //ApplyAllImmunities(true);
    }

    void Reset() override
    {
        events.Reset();

        m_IsDefeated = false;
        m_IsInCombat = false;
        m_CheckPlayersTimer = TIMER_CHECK_PLAYERS;
        m_ParagonsPurposeTimer = PARAGONS_PURPOSE_TIMER;

        me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
        me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (me->IsInCombat())
            DoZoneInCombat(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        summons.Despawn(summon);
    }

    void DoAction(const int32 action) override
    {
        switch (action)
        {
            case ACTION_BEGIN_BATTLE:
                BeginBattle();
                break;
            case ACTION_NEXT_BATTLE:
                EnterBattle();
                break;
            case ACTION_PARAGON_DEFEATED:
                ParagonsPurpose();
                break;
            case ACTION_MARK_NEXT_PARAGON:
                MarkParagonToBattle();
                break;
            case ACTION_RESET_BATTLE:
                ResetBattle();
                break;
            case ACTION_FINISH_BATTLE:
                FinishBattle();
                break;
        }
    }

    void DamageTaken(Unit* who, uint32 &damage) override
    {
        if (m_IsDefeated)
        {
            damage = 0;
            return;
        }

        if (damage >= me->GetHealth())
        {
            SetDefeated();
            SendDefeatedToController();

            if (!IsAllParagonsKilled())
            {
                damage = 0;

                MakeDied();
            }
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_PARAGON_IN_FIGHT)
        {
            return IsInFight() ? 1 : 0;
        }
        else if (type == DATA_ENCASE_AMBER_TARGET_ENABLE)
        {
            // Prevent to be encased in amber while it's in some special states
            if (!CanBeEncasedInAmber())
                return 0;

            return 1;
        }

        return 0;
    }

    // Bosses enter fight after jumping to the center of room (first jumping spell)
    // Maybe it's bad check and we should use simple timer (3 sec).
    void MovementInform(uint32 type, uint32 id) override
    {
        if (m_IsInCombat == false && type == EFFECT_MOTION_TYPE && id == EVENT_JUMP)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            m_IsInCombat = true;

            DoEnterCombat();
        }
    }

    void OnSpellClick(Unit* who, bool& /*result*/) override
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));

        if (Player* player = who->ToPlayer())
        {
            HandlePlayerBuff(player);
        }
    }

    void JustDied(Unit* who) override
    {
        m_IsDefeated = true;
        m_IsInCombat = false;

        events.Reset();
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();

        DoLeaveCombat();

        // prevent possible bugs
        // todo fix this
        /*if (!IsAllParagonsKilled())
        {
            me->SetLootRecipient(NULL);
            return;
        }*/

        // Bonus loot roll there
        //CreatureBonusLootProcessor bonusLoot(me);
        //bonusLoot.SendBonusLootToPlayers();
    }

protected:

    void CheckBattleRange(const uint32 diff)
    {
        if (m_CheckPlayersTimer <= diff)
        {
            m_CheckPlayersTimer = TIMER_CHECK_PLAYERS;

            if (Creature* pController = GetController())
            {
                if (me->GetDistance(pController) >= 100.0f)
                {
                    pController->AI()->DoAction(ACTION_RESET_BATTLE);
                }
            }
        }
        else
        {
            m_CheckPlayersTimer -= diff;
        }
    }

    void GetParagonsPurpose(const uint32 diff)
    {
        if (!m_IsInCombat)
            return;

        if (!IsHeroic())
            return;

        if (m_ParagonsPurposeTimer <= diff)
        {
            m_ParagonsPurposeTimer = PARAGONS_PURPOSE_TIMER;

            DoCast(me, SPELL_PARAGONS_PURPOSE_AURA, true);

        }
        else
        {
            m_ParagonsPurposeTimer -= diff;
        }
    }

    virtual void DoEnterCombat() { }

    virtual void DoLeaveCombat() { }

    bool IsInFight() const { return m_IsInCombat; }

    virtual bool CanBeEncasedInAmber() const { return true; }

    bool IsDefeated() const { return m_IsDefeated; }

    virtual void HandlePlayerBuff(Player* player) { }

private:

    void BeginBattle()
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

        DoZoneInCombat();

        // DEBUG:
        //if (paragonsEntries[(int)paragonsSequence[0]] != me->GetEntry())
        //    return;

        EnterBattle();
    }

    void EnterBattle()
    {
        if (!me->HasAura(SPELL_READY_TO_FIGHT))
            return;

        me->RemoveAura(SPELL_READY_TO_FIGHT);

        me->SetDisableGravity(false);
        me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);

        me->CastSpell(jumpToCenterPos.GetPositionX(), jumpToCenterPos.GetPositionY(), jumpToCenterPos.GetPositionZ(), SPELL_JUMP_TO_CENTER, false);
    }

    void ParagonsPurpose()
    {
        if (!m_IsInCombat)
            return;

        DoCast(me, SPELL_PARAGONS_PURPOSE_HEAL, true);
        DoCast(me, SPELL_PARAGONS_PURPOSE_AURA, true);
    }

    void MarkParagonToBattle()
    {
        me->AddAura(SPELL_READY_TO_FIGHT, me);
    }

    void SetDefeated()
    {
        m_IsDefeated = true;
        m_IsInCombat = false;
    }

    void MakeDied()
    {
        m_IsDefeated = true;
        m_IsInCombat = false;

        events.Reset();
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();

        me->RemoveAllAuras();
        me->SetReactState(REACT_PASSIVE);
        me->InterruptNonMeleeSpells(true);
        me->SetFaction(35);
        me->AttackStop();
        me->DeleteThreatList();
        me->getThreatManager().clearReferences();

        DoCast(me, SPELL_DEFEATED, true);
        // FeignDeath auras works only on players now
        // Do it manually
        me->SetUnitFlags(UnitFlags(UNIT_FLAG_UNK_29));                                                // blizz like 2.0.x
        me->SetUnitFlags2(UnitFlags2(UNIT_FLAG2_FEIGN_DEATH));                                              // blizz like 2.0.x
        me->SetDynamicFlags(UNIT_DYNFLAG_DEAD);
        me->AddUnitState(UNIT_STATE_DIED);

        me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));

        DoLeaveCombat();
    }

    void SendDefeatedToController()
    {
        if (Creature* pController = GetController())
        {
            pController->AI()->DoAction(ACTION_PARAGON_DEFEATED);
        }
    }

    bool IsAllParagonsKilled()
    {
        if (Creature* controller = GetController())
        {
            return controller->AI()->GetData(DATA_ALL_PARAGONS_DIED) == 1;
        }

        return false;
    }

    void ResetBattle()
    {
        me->InterruptNonMeleeSpells(true);
        events.Reset();
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
    }

    void FinishBattle()
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    Creature* GetController()
    {
        if (pInstance)
        {
            return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_PARAGONS_OF_THE_KLAXXI));
        }

        return NULL;
    }

private:

    InstanceScript* pInstance;
    bool m_IsDefeated;
    bool m_IsInCombat;
    uint32 m_CheckPlayersTimer;
    uint32 m_ParagonsPurposeTimer;
};

class npc_kilruk_the_wind_reaver : public CreatureScript
{
    public:
        npc_kilruk_the_wind_reaver() : CreatureScript("npc_kilruk_the_wind_reaver") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kilruk_the_wind_reaverAI(creature);
        }

        struct npc_kilruk_the_wind_reaverAI : public paragon_of_klaxxiAI
        {
            npc_kilruk_the_wind_reaverAI(Creature* creature) : paragon_of_klaxxiAI(creature),
                m_IsInDeathFromAbove(false), m_LastDeathFromAboveGuid(ObjectGuid::Empty)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                DoCast(me, SPELL_KILRUK_THE_WIND_REAVER, true);

                m_IsInDeathFromAbove = false;
                m_LastDeathFromAboveGuid = ObjectGuid::Empty;
            }

            void DoEnterCombat() override
            {
                Talk(SAY_KILRUK_AGGRO);

                me->RemoveAura(SPELL_KILRUK_THE_WIND_REAVER);

                events.ScheduleEvent(EVENT_GOUGE, TIMER_GOUGE_FIRST);
                events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, TIMER_DEATH_FROM_ABOVE_FIRST);
                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_REAVE, TIMER_REAVE_FIRST);
                }
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_KILRUK_DEATH);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXPOSED_VEINS);
            }

            bool CanBeEncasedInAmber() const override
            {
                return !IsInDeathFromAbove();
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_KILRUK_KILL);
                }
            }

            void JustSummoned(Creature* creature) override
            {
                paragon_of_klaxxiAI::JustSummoned(creature);

                if (creature->GetEntry() == NPC_IMPACT_JUMP_TARGET)
                {
                    DeathFromAboveJumpUp(creature);
                }
            }

            ObjectGuid GetObjectGuid(int32 type)
            {
                if (type == DATA_DEATH_FROM_ABOVE_GUID)
                {
                    return m_LastDeathFromAboveGuid;
                }

                return ObjectGuid::Empty;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                paragon_of_klaxxiAI::MovementInform(type, id);

                if (type == EFFECT_MOTION_TYPE && id == POINT_DEATH_FROM_ABOVE_1)
                {
                    DeathFromAboveJumpDown();
                }
                else if (type == EFFECT_MOTION_TYPE && id == POINT_DEATH_FROM_ABOVE_2)
                {
                    DeathFromAboveDamage();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (IsInDeathFromAbove())
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                MeleeAttack();
            }

        private:

            void MeleeAttack()
            {
                if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCastVictim(SPELL_RAZOR_SHARP_BLADES_DMG, true);
                    me->resetAttackTimer();
                }
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_GOUGE:
                        DoGouge();
                        events.ScheduleEvent(EVENT_GOUGE, TIMER_GOUGE);
                        break;
                    case EVENT_DEATH_FROM_ABOVE:
                        DoDeathFromAbove();
                        events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, TIMER_DEATH_FROM_ABOVE);
                        break;
                    case EVENT_REAVE:
                        DoReave();
                        events.ScheduleEvent(EVENT_REAVE, TIMER_REAVE);
                        break;
                }
            }

            void DoGouge()
            {
                DoCastVictim(SPELL_GOUGE);
            }

            void DoDeathFromAbove()
            {
                if (m_IsInDeathFromAbove)
                    return;

                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true);
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                if (target)
                {
                    Talk(SAY_KILRUK_SPELL);

                    m_IsInDeathFromAbove = true;
                    m_LastDeathFromAboveGuid = target->GetGUID();

                    DoCast(target, SPELL_DEATH_FROM_ABOVE_SUMMON);
                }
            }

            void DeathFromAboveJumpUp(Creature* jumpTarget)
            {
                //DoCast(jumpTarget, SPELL_DEATH_FROM_ABOVE_JUMP_1);
                me->GetMotionMaster()->MoveJump(jumpTarget->GetPositionX(), jumpTarget->GetPositionY(), jumpTarget->GetPositionZ(), 28.f, 10.f, 10.0f, POINT_DEATH_FROM_ABOVE_1);
            }

            void DeathFromAboveJumpDown()
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, m_LastDeathFromAboveGuid))
                {
                    DoCast(target, SPELL_DEATH_FROM_ABOVE_MARK, true);

                    me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 20.f, 10.f, 10.0f, POINT_DEATH_FROM_ABOVE_2);
                }
            }

            void DeathFromAboveDamage()
            {
                DoCastAOE(SPELL_DEATH_FROM_ABOVE_DMG);

                m_IsInDeathFromAbove = false;
                m_LastDeathFromAboveGuid = ObjectGuid::Empty;
            }

            void DoReave()
            {
                DoCastAOE(SPELL_REAVE_AOE);
            }

            bool IsInDeathFromAbove() const { return m_IsInDeathFromAbove; }

        private:

            InstanceScript* pInstance;
            bool m_IsInDeathFromAbove;
            ObjectGuid m_LastDeathFromAboveGuid;
        };
};

bool TargetUsedTankAbilities(Unit* target)
{
    uint32 defendAuraId = 0;

    if (Player* player = target->ToPlayer())
    {
        switch (player->GetSpecializationId())
        {
            case TALENT_SPEC_PALADIN_PROTECTION: defendAuraId = 132403; break;
            case TALENT_SPEC_WARRIOR_PROTECTION: defendAuraId = 132404; break;
            case TALENT_SPEC_DRUID_BEAR: defendAuraId = 132402; break;
            case TALENT_SPEC_DEATHKNIGHT_BLOOD: defendAuraId = 77535; break;
            case TALENT_SPEC_MONK_BREWMASTER: defendAuraId = 115307; break;
        }
    }

    if (defendAuraId && target->HasAura(defendAuraId))
        return true;

    return false;
}

class npc_xaril_the_poisoned_mind : public CreatureScript
{
    public:
        npc_xaril_the_poisoned_mind() : CreatureScript("npc_xaril_the_poisoned_mind") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_xaril_the_poisoned_mindAI(creature);
        }

        struct npc_xaril_the_poisoned_mindAI : public paragon_of_klaxxiAI
        {
            npc_xaril_the_poisoned_mindAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                DoCast(me, SPELL_XARIL_THE_POISONED_MIND, true);
            }

            void DoEnterCombat() override
            {
                Talk(SAY_XARIL_AGGRO);

                me->RemoveAura(SPELL_XARIL_THE_POISONED_MIND);

                DoCastAOE(SPELL_TOXIC_INJECTION);

                events.ScheduleEvent(EVENT_CATALYST, TIMER_CATALYST_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_XARIL_DEATH);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_BLUE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_RED);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOXIN_YELLOW);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_XARIL_KILL);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                MeleeAttack();
            }

        private:

            void MeleeAttack()
            {
                if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCastVictim(SPELL_TENDERIZING_STRIKES_DMG, true);
                    me->resetAttackTimer();
                }
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_CATALYST:
                        DoCatalyst();
                        events.ScheduleEvent(EVENT_CATALYST, TIMER_CATALYST);
                        break;
                }
            }

            void DoCatalyst()
            {
                uint32 spellId = 0;
                switch (urand(0, 2))
                {
                    case 0: spellId = IsHeroic() ? SPELL_CATALYST_ORANGE : SPELL_CATALYST_BLUE; break;
                    case 1: spellId = IsHeroic() ? SPELL_CATALYST_GREEN : SPELL_CATALYST_RED; break;
                    case 2: spellId = IsHeroic() ? SPELL_CATALYST_PURPLE : SPELL_CATALYST_YELLOW; break;
                }

                if (spellId)
                {
                    Talk(SAY_XARIL_SPELL);

                    DoCastAOE(spellId);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class HungryKunchongSpawner
{
    public:

        HungryKunchongSpawner(Creature* owner) : m_Owner(owner) { }

        void Reset()
        {
            memset(kunchongGuids, 0, sizeof(kunchongGuids));
        }

        void SpawnKunchong()
        {
            int freePositionIndex = GetFreeSlot();
            if (freePositionIndex < 0 || freePositionIndex >= KUNCHONG_POSITION_COUNT)
                return;

            if (Creature* pKunchong = m_Owner->SummonCreature(NPC_HUNGRY_KUNCHONG, kunchongPos[freePositionIndex]))
            {
                kunchongGuids[freePositionIndex] = pKunchong->GetGUID();
            }
        }

        void KunchongDespawned(ObjectGuid guid)
        {
            FreeSlotByGuid(guid);
        }

    private:

        int GetFreeSlot()
        {
            for (uint8 i = 0; i < KUNCHONG_POSITION_COUNT; ++i)
            {
                if (kunchongGuids[i] == ObjectGuid::Empty)
                    return i;
            }

            return -1;
        }

        void FreeSlotByGuid(const ObjectGuid guid)
        {
            for (uint8 i = 0; i < KUNCHONG_POSITION_COUNT; ++i)
            {
                if (kunchongGuids[i] == guid)
                {
                    kunchongGuids[i] = ObjectGuid::Empty;
                }
            }
        }

        Creature* m_Owner;
        ObjectGuid kunchongGuids[KUNCHONG_POSITION_COUNT];
};

class npc_kaztik_the_manipulator : public CreatureScript
{
    public:
        npc_kaztik_the_manipulator() : CreatureScript("npc_kaztik_the_manipulator") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kaztik_the_manipulatorAI(creature);
        }

        struct npc_kaztik_the_manipulatorAI : public paragon_of_klaxxiAI
        {
            npc_kaztik_the_manipulatorAI(Creature* creature) : paragon_of_klaxxiAI(creature),
                m_KunchongSpawner(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                m_KunchongSpawner.Reset();
            }

            void DoEnterCombat() override
            {
                Talk(SAY_KAZTIK_AGGRO);

                // delay spawn to prevent bugs
                events.ScheduleEvent(EVENT_KUNCHONGS, TIMER_KUNCHONGS);
                events.ScheduleEvent(EVENT_SONIC_PROJECTION, TIMER_SONIC_PROJECTION_FIRST);
                events.ScheduleEvent(EVENT_MESMERIZE, TIMER_MESMERIZE_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_KAZTIK_DEATH);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MESMERIZE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEVOUR_1);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_KAZTIK_KILL);
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                paragon_of_klaxxiAI::SummonedCreatureDies(summon, killer);

                if (summon->GetEntry() == NPC_HUNGRY_KUNCHONG)
                {
                    m_KunchongSpawner.KunchongDespawned(summon->GetGUID());
                    SpawnKunchongs(1);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_KUNCHONGS:
                        SpawnKunchongs(3);
                        break;
                    case EVENT_SONIC_PROJECTION:
                        DoSonicProjection();
                        events.ScheduleEvent(EVENT_SONIC_PROJECTION, TIMER_SONIC_PROJECTION);
                        break;
                    case EVENT_MESMERIZE:
                        DoMesmerize();
                        events.ScheduleEvent(EVENT_MESMERIZE, TIMER_MESMERIZE);
                        break;
                }
            }

            void SpawnKunchongs(const uint8 count)
            {
                for (uint8 i = 0; i < count; ++i)
                {
                    // We cannot use the spell and cannot spawn it manually at random locations
                    // Because it's wrong calculations of positions based on vmaps
                    m_KunchongSpawner.SpawnKunchong();
                }
            }

            void DoSonicProjection()
            {
                //DoCastAOE(SPELL_SONIC_PROJECTION_AOE);
                // Don't use aoe spell
                // Select the target for the missile in areatrigger script
                DoCast(me, SPELL_SONIC_PROJECTION_AREATRIGGER);
            }

            void DoMesmerize()
            {
                Talk(SAY_KAZTIK_SPELL);

                DoCastAOE(SPELL_MESMERIZE_AOE);
            }

        private:

            InstanceScript* pInstance;
            HungryKunchongSpawner m_KunchongSpawner;
        };
};

class EncaseInAmberCheck
{
    public:

        EncaseInAmberCheck() {}

        bool operator()(Creature* unit) const
        {
            if (IsParagonActive(unit) && unit->GetHealthPct() <= 50.0f)
                return true;

            return false;
        }

    private:

        bool IsParagonActive(Creature* unit) const
        {
            switch (unit->GetEntry())
            {
                case NPC_KILRUK_THE_WIND_REAVER:
                case NPC_XARIL_THE_POISONED_MIND:
                case NPC_KAZTIK_THE_MANIPULATOR:
                case NPC_IYYOKUK_THE_LUCID:
                case NPC_KAROZ_THE_LOCUST:
                case NPC_SKEER_THE_BLOODSEEKER:
                case NPC_RIKKAL_THE_DISSECTOR:
                case NPC_HISEK_THE_SWARMKEEPER:
                    return ((unit->AI()->GetData(DATA_PARAGON_IN_FIGHT) > 0 && unit->AI()->GetData(DATA_ENCASE_AMBER_TARGET_ENABLE) == 1) ? true : false);
                    break;
            }

            return false;
        }
};

class npc_korven_the_prime : public CreatureScript
{
    public:
        npc_korven_the_prime() : CreatureScript("npc_korven_the_prime") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korven_the_primeAI(creature);
        }

        struct npc_korven_the_primeAI : public paragon_of_klaxxiAI
        {
            npc_korven_the_primeAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                m_LastEncaseAmberTargetGuid = ObjectGuid::Empty;
            }

            void DoEnterCombat() override
            {
                Talk(SAY_KORVEN_AGGRO);

                events.ScheduleEvent(EVENT_SHIELD_BASH, TIMER_SHIELD_BASH_FIRST);
                events.ScheduleEvent(EVENT_ENCASE_IN_AMBER, TIMER_ENCASE_IN_AMBER_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_KORVEN_DEATH);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_KORVEN_KILL);
                }
            }

            void JustSummoned(Creature* summon) override
            {
                paragon_of_klaxxiAI::JustSummoned(summon);

                if (summon->GetEntry() == NPC_AMBER)
                {
                    SendEncaseAmberTarget(summon);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_SHIELD_BASH:
                        DoShieldBash();
                        events.ScheduleEvent(EVENT_SHIELD_BASH, TIMER_SHIELD_BASH);
                        break;
                    case EVENT_ENCASE_IN_AMBER:
                        DoEncaseInAmber();
                        events.ScheduleEvent(EVENT_ENCASE_IN_AMBER, TIMER_ENCASE_IN_AMBER);
                        break;
                }
            }

            void DoShieldBash()
            {
                DoCastVictim(SPELL_SHIELD_BASH);
            }

            void DoEncaseInAmber()
            {
                if (Creature* target = GetEncaseInAmberTarget())
                {
                    Talk(SAY_KORVEN_SPELL);

                    m_LastEncaseAmberTargetGuid = target->GetGUID();

                    DoCast(target, SPELL_ENCASE_IN_AMBER);

                    target->CastStop();
                    target->CastSpell(target, SPELL_AMBER_REGENERATION);
                }
            }

            Creature* GetEncaseInAmberTarget()
            {
                Creature* target = NULL;
                EncaseInAmberCheck check;
                Trinity::CreatureSearcher<EncaseInAmberCheck> searcher(me, target, check);
                //me->VisitNearbyGridObject(60.0f, searcher);
                Cell::VisitWorldObjects(me, searcher, 60.0f);
                return target;
            }

            void SendEncaseAmberTarget(Creature* amber)
            {
                amber->AI()->SetGUID(m_LastEncaseAmberTargetGuid, DATA_ENCASE_AMBER_GUID);
            }

        private:

            InstanceScript* pInstance;
            ObjectGuid m_LastEncaseAmberTargetGuid;
        };
};

class npc_iyyokuk_the_lucid : public CreatureScript
{
    public:
        npc_iyyokuk_the_lucid() : CreatureScript("npc_iyyokuk_the_lucid") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_iyyokuk_the_lucidAI(creature);
        }

        struct npc_iyyokuk_the_lucidAI : public paragon_of_klaxxiAI
        {
            npc_iyyokuk_the_lucidAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                DoCast(me, SPELL_GREEN_MANTID_WINGS, true);
            }

            void DoEnterCombat() override
            {
                Talk(SAY_IYYOKUK_AGGRO);

                me->RemoveAura(SPELL_GREEN_MANTID_WINGS);

                InsaneCalculationInit();

                events.ScheduleEvent(EVENT_DIMINISH, TIMER_DIMINISH_FIRST);
                events.ScheduleEvent(EVENT_INSANE_CALCULATION, urand(TIMER_INSANE_CALCULATION_MIN, TIMER_INSANE_CALCULATION_MAX));
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_IYYOKUK_DEATH);

                for (uint8 i = 0; i < INSANE_CALCULATION_SPELLS_COUNT; ++i)
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(insaneCalculationSpells[i]);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_IYYOKUK_KILL);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_DIMINISH:
                        DoDiminish();
                        events.ScheduleEvent(EVENT_DIMINISH, TIMER_DIMINISH);
                        break;
                    case EVENT_INSANE_CALCULATION:
                        DoInsaneCalculation();
                        events.ScheduleEvent(EVENT_INSANE_CALCULATION, urand(TIMER_INSANE_CALCULATION_MIN, TIMER_INSANE_CALCULATION_MAX));
                        break;
                }
            }

            void InsaneCalculationInit()
            {
                std::list<Unit*> targets;
                SelectTargetList(targets, 25, SELECT_TARGET_RANDOM, 0.0f, true);

                for (std::list<Unit*>::const_iterator itrTarget = targets.begin(); itrTarget != targets.end(); ++itrTarget)
                {
                    Unit* target = (*itrTarget);

                    uint32 spellId = insaneCalculationSpells[urand(0, INSANE_CALCULATION_SPELLS_COUNT)];
                    uint8 stacks = urand(1, 5);

                    if (Aura* aur = me->AddAura(spellId, target))
                    {
                        aur->SetStackAmount(stacks);
                    }
                }
            }

            void DoDiminish()
            {
                DoCastAOE(SPELL_DIMINISH);
            }

            void DoInsaneCalculation()
            {
                DoCastAOE(SPELL_INSANE_CALCULATION_FIERY_EDGE);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_karoz_the_locust : public CreatureScript
{
    public:
        npc_karoz_the_locust() : CreatureScript("npc_karoz_the_locust") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_karoz_the_locustAI(creature);
        }

        struct npc_karoz_the_locustAI : public paragon_of_klaxxiAI
        {
            npc_karoz_the_locustAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                m_IsInFlash = false;
                m_IsInHurlAmber = false;
            }

            void DoEnterCombat() override
            {
                Talk(SAY_KAROZ_AGGRO);

                events.ScheduleEvent(EVENT_FLASH, TIMER_FLASH_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_KAROZ_DEATH);
            }

            bool CanBeEncasedInAmber() const override
            {
                return !IsInHurlAmber();
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_KAROZ_KILL);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                paragon_of_klaxxiAI::MovementInform(type, id);

                if (type == POINT_MOTION_TYPE && id == EVENT_CHARGE)
                {
                    me->GetMotionMaster()->MovementExpired(false);
                    DoFlashDmg();
                }
                else if (type == EFFECT_MOTION_TYPE && id == POINT_HURL_AMBER)
                {
                    me->GetMotionMaster()->MovementExpired(false);
                    DoHurlAmber();
                }
            }

            void GetBeforeFlashPos(Position& pos)
            {
                pos.Relocate(m_BeforeFlashPos);
            }

            void HandlePlayerBuff(Player* player) override
            {
                player->AddAura(SPELL_STRONG_LEGS_BUFF, player);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

         private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_FLASH:
                        DoFlash();
                        events.ScheduleEvent(EVENT_HURL_AMBER, TIMER_HURL_AMBER);
                        break;
                    case EVENT_HURL_AMBER:
                        DoHurlAmberJump();
                        events.ScheduleEvent(EVENT_FLASH, TIMER_FLASH);
                        break;
                    case EVENT_HURL_AMBER_END:
                        DoHurlAmberEnd();
                        break;
                }
            }

            void DoFlash()
            {
                Talk(SAY_KAROZ_SPELL);

                m_BeforeFlashPos = me->GetPosition();
                DoCastAOE(SPELL_STORE_KINETIC_ENERGY);

                m_IsInFlash = true;
            }

            void DoFlashDmg()
            {
                m_IsInFlash = false;

                me->RemoveAura(SPELL_FLASH_AURA);

                DoCast(me, SPELL_FLASH_DMG);
            }

            bool IsInFlash() const { return m_IsInFlash; }

            void DoHurlAmberJump()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();

                //DoCast(SPELL_DASH);
                float dist = me->GetDistance(jumpToHurlAmberPos);
                const float speedZ = 15.f;
                float speedXY = dist * 10.f / speedZ;

                me->GetMotionMaster()->MoveJump(jumpToHurlAmberPos, speedXY, speedZ, /*10.0f,*/ POINT_HURL_AMBER);

                m_IsInHurlAmber = true;
            }

            void DoHurlAmber()
            {
                me->SetFacingTo(jumpToHurlAmberPos.GetOrientation());

                DoCast(me, SPELL_HURL_AMBER_PERIODIC);

                events.ScheduleEvent(EVENT_HURL_AMBER_END, TIMER_HURL_AMBER_END);
            }

            void DoHurlAmberEnd()
            {
                me->InterruptNonMeleeSpells(false);

                float dist = me->GetDistance(jumpToCenterPos);
                const float speedZ = 15.f;
                float speedXY = dist * 10.f / speedZ;

                me->GetMotionMaster()->MoveJump(jumpToCenterPos, speedXY, speedZ);

                m_IsInHurlAmber = false;

                me->SetReactState(REACT_AGGRESSIVE);
            }

            bool IsInHurlAmber() const { return m_IsInHurlAmber; }

        private:

            InstanceScript* pInstance;
            bool m_IsInFlash;
            Position m_BeforeFlashPos;
            bool m_IsInHurlAmber;
        };
};

class npc_skeer_the_bloodseeker : public CreatureScript
{
    public:
        npc_skeer_the_bloodseeker() : CreatureScript("npc_skeer_the_bloodseeker") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_skeer_the_bloodseekerAI(creature);
        }

        struct npc_skeer_the_bloodseekerAI : public paragon_of_klaxxiAI
        {
            npc_skeer_the_bloodseekerAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                DoCast(me, SPELL_HEWER_OF_FOES, true);
            }

            void DoEnterCombat() override
            {
                Talk(SAY_SKEER_AGGRO);

                events.ScheduleEvent(EVENT_BLOODLETTING, TIMER_BLOODLETTING_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_SKEER_DEATH);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEWN_DMG);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_SKEER_KILL);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                MeleeAttack();
            }

        private:

            void MeleeAttack()
            {
                if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCastVictim(SPELL_HEW, true);
                    me->resetAttackTimer();
                }
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_BLOODLETTING:
                        DoBloodletting();
                        events.ScheduleEvent(EVENT_BLOODLETTING, TIMER_BLOODLETTING);
                        break;
                }
            }

            void DoBloodletting()
            {
                Talk(SAY_SKEER_SPELL);

                DoCastVictim(SPELL_BLOODLETTING);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_rikkal_the_dissector : public CreatureScript
{
    public:
        npc_rikkal_the_dissector() : CreatureScript("npc_rikkal_the_dissector") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_rikkal_the_dissectorAI(creature);
        }

        struct npc_rikkal_the_dissectorAI : public paragon_of_klaxxiAI
        {
            npc_rikkal_the_dissectorAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();

                DoCast(me, SPELL_MAD_SCIENTIST, true);
            }

            void DoEnterCombat() override
            {
                Talk(SAY_RIKKAL_AGGRO);

                events.ScheduleEvent(EVENT_MUTATE, TIMER_MUTATE_FIRST);
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_RIKKAL_DEATH);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GENETIC_ALTERATION_DMG);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INJECTION_DUMMY);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HUNGER);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATE);

                me->DespawnCreaturesInArea(NPC_AMBER_PARASITE, 200);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_RIKKAL_KILL);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                MeleeAttack();
            }

        private:

            void MeleeAttack()
            {
                if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCastVictim(SPELL_GENETIC_ALTERATION, true);
                    me->resetAttackTimer();
                }
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_MUTATE:
                        DoMutate();
                        events.ScheduleEvent(EVENT_MUTATE, TIMER_MUTATE);
                        break;
                }
            }

            void DoMutate()
            {
                Talk(SAY_RIKKAL_SPELL);

                DoCastAOE(SPELL_MUTATE_AOE);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_hisek_the_swarmkeeper : public CreatureScript
{
    public:
        npc_hisek_the_swarmkeeper() : CreatureScript("npc_hisek_the_swarmkeeper") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hisek_the_swarmkeeperAI(creature);
        }

        struct npc_hisek_the_swarmkeeperAI : public paragon_of_klaxxiAI
        {
            npc_hisek_the_swarmkeeperAI(Creature* creature) : paragon_of_klaxxiAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                paragon_of_klaxxiAI::Reset();
            }

            void AttackStart(Unit* who) override
            {
                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void DoEnterCombat() override
            {
                Talk(SAY_HISEK_AGGRO);

                events.ScheduleEvent(EVENT_MULTI_SHOT, TIMER_MULTI_SHOT_FIRST);
                events.ScheduleEvent(EVENT_AIM, TIMER_AIM_FIRST);

                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_RAPID_FIRE, TIMER_RAPID_FIRE);
                }
            }

            void DoLeaveCombat() override
            {
                Talk(SAY_HISEK_DEATH);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_HISEK_KILL);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                CheckBattleRange(diff);
                GetParagonsPurpose(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_MULTI_SHOT:
                        DoMultishot();
                        events.ScheduleEvent(EVENT_MULTI_SHOT, TIMER_MULTI_SHOT);
                        break;
                    case EVENT_AIM:
                        DoAim();
                        events.ScheduleEvent(EVENT_AIM, TIMER_AIM);
                        break;
                    case EVENT_RAPID_FIRE:
                        DoRapidFire();
                        events.ScheduleEvent(EVENT_RAPID_FIRE, TIMER_RAPID_FIRE);
                        break;
                }
            }

            void DoMultishot()
            {
                if (Unit* victim = me->GetVictim())
                {
                    me->SetFacingToObject(victim);
                }

                DoCastVictim(SPELL_MULTI_SHOT);
            }

            void DoAim()
            {
                Talk(SAY_HISEK_SPELL);

                DoCastAOE(SPELL_AIM_AOE);
            }

            void DoRapidFire()
            {
                DoCast(me, SPELL_RAPID_FIRE);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_paragons_of_the_klaxxi_mantid_amber : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_mantid_amber() : CreatureScript("npc_paragons_of_the_klaxxi_mantid_amber") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_mantid_amberAI(creature);
        }

        // Prevent gossip menu
        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            return true;
        }

        struct npc_paragons_of_the_klaxxi_mantid_amberAI : public Scripted_NoMovementAI
        {
            npc_paragons_of_the_klaxxi_mantid_amberAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                me->SetUnitFlags2(UnitFlags2(UNIT_FLAG_NOT_SELECTABLE));
            }

            void Reset() override
            {
                me->AddAura(SPELL_COSMETIC_FOR_FIGHT_STARTER, me);
            }

            void sGossipHello(Player* player) override
            {
                if (player->IsInCombat())
                    return;

                if (IsEncounterDone())
                    return;

                if (Creature* pController = GetController())
                {
                    pController->AI()->DoAction(ACTION_BEGIN_BATTLE);
                }

                me->DespawnOrUnsummon(100);
            }

        private:

            Creature* GetController()
            {
                if (pInstance)
                {
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_PARAGONS_OF_THE_KLAXXI));
                }

                return NULL;
            }

            bool IsEncounterDone()
            {
                if (pInstance)
                {
                    return pInstance->GetBossState(DATA_PARAGONS_OF_THE_KLAXXI) == DONE;
                }

                return false;
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_paragons_of_the_klaxxi_impact_jump_target : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_impact_jump_target() : CreatureScript("npc_paragons_of_the_klaxxi_impact_jump_target") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_impact_jump_targetAI(creature);
        }

        struct npc_paragons_of_the_klaxxi_impact_jump_targetAI : public Scripted_NoMovementAI
        {
            npc_paragons_of_the_klaxxi_impact_jump_targetAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetDisableGravity(true);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_paragons_of_the_klaxxi_hungry_kunchong : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_hungry_kunchong() : CreatureScript("npc_paragons_of_the_klaxxi_hungry_kunchong") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_hungry_kunchongAI(creature);
        }

        struct npc_paragons_of_the_klaxxi_hungry_kunchongAI : public ScriptedAI
        {
            npc_paragons_of_the_klaxxi_hungry_kunchongAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                //ApplyAllImmunities(true);
            }

            void Reset() override
            {
                InitPowers();

                me->SetReactState(REACT_PASSIVE);

                DoCast(me, SPELL_HUNGRY, true);

                DoCast(me, SPELL_THICK_SHELL);

                me->GetMotionMaster()->MoveRandom(5.0f);

                m_MesmerizePlayerGuid = ObjectGuid::Empty;
                m_CheckMesmerizeTargetTimer = 1000;
                m_IsMolted = false;
                m_CheckMoltTimer = 1000;
                m_PreviousHealthPct = 100.0f;
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_MESMERIZE)
                {
                    DoMesmerize();
                }
                else if (action == ACTION_DEVOUR)
                {
                    JustDevoured();
                }
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (m_MesmerizePlayerGuid != ObjectGuid::Empty && m_PreviousHealthPct - me->GetHealthPct() >= 30.f)
                {
                    StopMesmerize(true);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                CheckMesmerizeTarget(diff);

                CheckMolt(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {

                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_SWIPE:
                        DoSwipe();
                        events.ScheduleEvent(EVENT_SWIPE, TIMER_SWIPE);
                        break;
                }
            }

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_ENERGY, me);
                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                me->SetPower(POWER_ENERGY, 0);
            }

            void DoSwipe()
            {
                DoCast(SPELL_SWIPE);
            }

            void DoMesmerize()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -20.0f, true);
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                if (!target)
                    return;

                m_MesmerizePlayerGuid = target->GetGUID();
                m_PreviousHealthPct = me->GetHealthPct();

                DoCast(target, SPELL_MESMERIZE, true);
                DoCast(target, SPELL_DEVOUR_1);
                me->RemoveAura(SPELL_THICK_SHELL);
            }

            void StopMesmerize(bool restoreShield)
            {
                me->CastStop();

                me->RemoveAura(SPELL_DEVOUR_1);

                if (Unit* target = ObjectAccessor::GetUnit(*me, m_MesmerizePlayerGuid))
                {
                    target->RemoveAura(SPELL_DEVOUR_1);
                    target->RemoveAura(SPELL_MESMERIZE);
                }

                m_MesmerizePlayerGuid = ObjectGuid::Empty;

                if (restoreShield)
                {
                    DoCast(me, SPELL_THICK_SHELL);
                }
            }

            void CheckMesmerizeTarget(const uint32 diff)
            {
                if (!m_MesmerizePlayerGuid)
                    return;

                if (m_CheckMesmerizeTargetTimer <= diff)
                {
                    m_CheckMesmerizeTargetTimer = 1000;

                    if (Unit* target = ObjectAccessor::GetUnit(*me, m_MesmerizePlayerGuid))
                    {
                        if (me->GetDistance(target) <= 3.0f)
                        {
                            DevourMesmerizeTarget(target);
                        }
                    }
                }
                else
                {
                    m_CheckMesmerizeTargetTimer -= diff;
                }
            }

            void DevourMesmerizeTarget(Unit* target)
            {
                StopMesmerize(false);

                me->AddAura(SPELL_DEVOUR_AURA, target);
                DoCastAOE(SPELL_DEVOUR_KILL, true);
            }

            void JustDevoured()
            {
                if (m_IsMolted)
                    return;

                me->SetPower(POWER_ENERGY, 100);
            }

            void CheckMolt(const uint32 diff)
            {
                if (m_IsMolted)
                    return;

                if (m_CheckMoltTimer <= diff)
                {
                    m_CheckMoltTimer = 1000;

                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        DoMolt();
                    }
                }
                else
                {
                    m_CheckMoltTimer -= diff;
                }
            }

            void DoMolt()
            {
                if (m_IsMolted)
                    return;

                StopMesmerize(false);

                m_IsMolted = true;

                me->RemoveAura(SPELL_THICK_SHELL);

                DoCast(me, SPELL_MOLT, true);

                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_SWIPE, TIMER_SWIPE_FIRST);
            }

        private:

            InstanceScript* pInstance;
            ObjectGuid m_MesmerizePlayerGuid;
            uint32 m_CheckMesmerizeTargetTimer;
            bool m_IsMolted;
            uint32 m_CheckMoltTimer;
            float m_PreviousHealthPct;
        };
};

class npc_paragons_of_the_klaxxi_amber : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_amber() : CreatureScript("npc_paragons_of_the_klaxxi_amber") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_amberAI(creature);
        }

        struct npc_paragons_of_the_klaxxi_amberAI : public Scripted_NoMovementAI
        {
            npc_paragons_of_the_klaxxi_amberAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                //ApplyAllImmunities(true);
            }

            void Reset() override
            {
                DoCast(me, SPELL_AMBER_BARRIER, true);
                DoCast(me, SPELL_AMBER_REGENERATION);

                m_EncaseAmberTargetGuid = ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_ENCASE_AMBER_GUID)
                {
                    m_EncaseAmberTargetGuid = guid;
                }
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (IsHeroic())
                {
                    damage = 0;
                }
            }

            void JustDied(Unit* killer) override
            {
                InterruptEncase();
                me->DespawnOrUnsummon(100);
            }

        private:

            void InterruptEncase()
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, m_EncaseAmberTargetGuid))
                {
                    target->CastStop();
                    target->RemoveAura(SPELL_ENCASE_IN_AMBER);
                }

                me->CastStop();
            }

        private:

            InstanceScript* pInstance;
            ObjectGuid m_EncaseAmberTargetGuid;
        };
};

class NearestParagonCheck
    {
        public:
            NearestParagonCheck(WorldObject const& obj, float range)
                : i_obj(obj), i_range(range) {}

            bool operator()(Creature* u)
            {
                if (!u->IsAlive())
                    return false;

                switch (u->GetEntry())
                {
                    case NPC_KILRUK_THE_WIND_REAVER:
                    case NPC_XARIL_THE_POISONED_MIND:
                    case NPC_KAZTIK_THE_MANIPULATOR:
                    case NPC_KORVEN_THE_PRIME:
                    case NPC_IYYOKUK_THE_LUCID:
                    case NPC_KAROZ_THE_LOCUST:
                    case NPC_SKEER_THE_BLOODSEEKER:
                    case NPC_RIKKAL_THE_DISSECTOR:
                    case NPC_HISEK_THE_SWARMKEEPER:
                        if ((u->AI()->GetData(DATA_PARAGON_IN_FIGHT) > 0) &&
                            i_obj.IsWithinDistInMap(u, i_range))
                        {
                            i_range = i_obj.GetDistance(u);
                            return true;
                        }
                        break;
                }

                return false;
            }

        private:

            WorldObject const& i_obj;
            float  i_range;
    };

class npc_paragons_of_the_klaxxi_blood : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_blood() : CreatureScript("npc_paragons_of_the_klaxxi_blood") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_bloodAI(creature);
        }

        struct npc_paragons_of_the_klaxxi_bloodAI : public Scripted_NoMovementAI
        {
            npc_paragons_of_the_klaxxi_bloodAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                //ApplyAllImmunities(true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, false);

                me->SetSpeed(MOVE_RUN, 0.7142857f);
            }

            void Reset() override
            {
                DoCast(me, SPELL_GROW, true);

                m_IsFollowing = false;
                m_CurrentParagonGuid = ObjectGuid::Empty;
                m_BloodInfusionTimer = 1000;
            }

            void IsSummonedBy(Unit* owner) override
            {
                events.ScheduleEvent(EVENT_CHANGE_TARGET, 1000);
            }

            void JustDied(Unit* killer)
            {
                me->DespawnOrUnsummon(100);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (UpdateBloodInfusion(diff))
                    return;

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_CHANGE_TARGET:
                        UpdateFollowing();
                        events.ScheduleEvent(EVENT_CHANGE_TARGET, 3000);
                        break;
                }
            }

        private:

            Creature* GetNearestParagon()
            {
                Creature* target = NULL;
                NearestParagonCheck check(*me, 100.0f);
                Trinity::CreatureLastSearcher<NearestParagonCheck> searcher(me, target, check);
                //me->VisitNearbyGridObject(100.0f, searcher);
                Cell::VisitWorldObjects(me, searcher, 100.0f);
                return target;
            }

            void UpdateFollowing()
            {
                if (Creature* pParagon = GetNearestParagon())
                {
                    if (pParagon->GetGUID() == m_CurrentParagonGuid)
                        return;

                    StartFollowing(pParagon);
                }
                else
                {
                    StopFollowing();
                }
            }

            void StartFollowing(Creature* pTarget)
            {
                m_CurrentParagonGuid = pTarget->GetGUID();

                me->GetMotionMaster()->MovementExpired(false);
                me->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                m_IsFollowing = true;
            }

            void StopFollowing()
            {
                m_CurrentParagonGuid = ObjectGuid::Empty;
                me->GetMotionMaster()->MovementExpired(false);
                m_IsFollowing = false;
            }

            bool UpdateBloodInfusion(const uint32 diff)
            {
                if (!m_IsFollowing)
                    return false;

                if (m_BloodInfusionTimer <= diff)
                {
                    m_BloodInfusionTimer = 1000;

                    if (Creature* pParagon = ObjectAccessor::GetCreature(*me, m_CurrentParagonGuid))
                    {
                        if (me->GetDistance(pParagon) <= 1.f)
                        {
                            DoBloodInfusion(pParagon);
                            StopFollowing();
                            me->DespawnOrUnsummon(100);
                            return true;
                        }
                    }
                }
                else
                {
                    m_BloodInfusionTimer -= diff;
                }

                return false;
            }

            void DoBloodInfusion(Creature* pTarget)
            {
                int32 healthPct = (int32)me->GetHealthPct();
                me->CastCustomSpell(pTarget, SPELL_BLOOD_INFUSION, &healthPct, NULL, NULL, true);
            }

        private:

            InstanceScript* pInstance;
            ObjectGuid m_CurrentParagonGuid;
            bool m_IsFollowing;
            uint32 m_BloodInfusionTimer;
        };
};

class npc_paragons_of_the_klaxxi_amber_parasite : public CreatureScript
{
    public:
        npc_paragons_of_the_klaxxi_amber_parasite() : CreatureScript("npc_paragons_of_the_klaxxi_amber_parasite") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paragons_of_the_klaxxi_amber_parasiteAI(creature);
        }

        struct npc_paragons_of_the_klaxxi_amber_parasiteAI : public Scripted_NoMovementAI
        {
            npc_paragons_of_the_klaxxi_amber_parasiteAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                //ApplyAllImmunities(true);
            }

            void Reset() override
            {
                InitPowers();

                DoCast(me, SPELL_GENETIC_MODIFICATIONS, true);
            }

            void IsSummonedBy(Unit* owner)
            {
                events.ScheduleEvent(EVENT_HUNGER, TIMER_HUNGER);
            }

            void JustDied(Unit* killer)
            {
                me->DespawnOrUnsummon(100);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_ENERGY, me);
                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                me->SetPower(POWER_ENERGY, 0);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_HUNGER:
                        DoHunger();
                        events.ScheduleEvent(EVENT_FEED, TIMER_FEED_FIRST);
                        break;
                    case EVENT_FEED:
                        DoFeed();
                        events.ScheduleEvent(EVENT_FEED, TIMER_FEED);
                        break;
                }
            }

            void DoHunger()
            {
                DoCastAOE(SPELL_HUNGER);
            }

            void DoFeed()
            {
                if (me->GetPower(POWER_ENERGY) < 100)
                {
                    DoCastAOE(SPELL_FEED);
                }
                else
                {
                    DoCast(me, SPELL_REGENERATE);
                    events.RescheduleEvent(EVENT_FEED, TIMER_FEED_FIRST);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class spell_paragons_of_the_klaxxi_mutilate : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_mutilate() : SpellScriptLoader("spell_paragons_of_the_klaxxi_mutilate") { }

        class spell_paragons_of_the_klaxxi_mutilate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_mutilate_SpellScript);

            // Fix the target because there is wrong target selection in the trigger spell effect (effect 160)
            void CheckTargets(WorldObject*& target)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* victim = caster->GetVictim())
                    {
                        target = victim;
                    }
                }
            }

            void Register()
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_paragons_of_the_klaxxi_mutilate_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_mutilate_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_reave : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_reave() : SpellScriptLoader("spell_paragons_of_the_klaxxi_reave") { }

        class spell_paragons_of_the_klaxxi_reave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_reave_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_REAVE, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_reave_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_reave_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_reave_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_death_from_above_summon : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_death_from_above_summon() : SpellScriptLoader("spell_paragons_of_the_klaxxi_death_from_above_summon") { }

        class spell_paragons_of_the_klaxxi_death_from_above_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_death_from_above_summon_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                WorldLocation summonPos = *GetExplTargetDest();
                summonPos.m_positionZ += IMPACT_JUMP_TARGET_OFFSET;
                SetExplTargetDest(summonPos);

                WorldLocation* dest = GetHitDest();
                if (dest)
                {
                    dest->Relocate(summonPos);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_paragons_of_the_klaxxi_death_from_above_summon_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_death_from_above_summon_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_death_from_above_jump_2 : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_death_from_above_jump_2() : SpellScriptLoader("spell_paragons_of_the_klaxxi_death_from_above_jump_2") { }

        class spell_paragons_of_the_klaxxi_death_from_above_jump_2_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_death_from_above_jump_2_SpellScript);

            // Fix the target because there is wrong target selection in the trigger spell effect (effect 160)
            void CheckTargets(WorldObject*& target)
            {
                if (!GetCaster())
                    return;

                Creature* creatureCaster = GetCaster()->ToCreature();
                if (!creatureCaster)
                    return;

                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                {
                    ObjectGuid targetGuid = instance->GetObjectGuid(DATA_DEATH_FROM_ABOVE_GUID);
                    if (Unit* victim = ObjectAccessor::GetUnit(*creatureCaster, targetGuid))
                    {
                        target = victim;
                    }
                }
            }

            void Register()
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_paragons_of_the_klaxxi_death_from_above_jump_2_SpellScript::CheckTargets, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_death_from_above_jump_2_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_caustic_blood: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_caustic_blood() : SpellScriptLoader("spell_paragons_of_the_klaxxi_caustic_blood") { }

        class spell_paragons_of_the_klaxxi_caustic_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_caustic_blood_AuraScript);

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                uint8 stacks = this->GetStackAmount();
                if (stacks >= 10)
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BLOODY_EXPLOSION_DUMMY, true);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BLOODY_EXPLOSION_DMG, true);
                    Remove();
                }

            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_caustic_blood_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_caustic_blood_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg() : SpellScriptLoader("spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg") { }

        class spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg_SpellScript);

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (TargetUsedTankAbilities(GetHitUnit()))
                    return;

                if (Aura* aur = GetHitUnit()->GetAura(SPELL_CAUSTIC_BLOOD))
                {
                    uint8 stacks = aur->GetStackAmount();
                    if (stacks < 99)
                        aur->SetStackAmount(stacks + 1);
                }
                else
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_CAUSTIC_BLOOD, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_toxic_ejection : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_toxic_ejection() : SpellScriptLoader("spell_paragons_of_the_klaxxi_toxic_ejection") { }

        class spell_paragons_of_the_klaxxi_toxic_ejection_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_toxic_ejection_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                //std::random_shuffle(targets.begin(), targets.end());

                bool is25Raid = GetCaster()->GetMap()->Is25ManRaid();

                uint32 blueCount = is25Raid ? 5 : 2;
                uint32 redCount = is25Raid ? 12 : 5;
                uint32 yellowCount = is25Raid ? 7 : 3;

                for (std::list<WorldObject*>::const_iterator itrTarget = targets.begin(); itrTarget != targets.end(); ++itrTarget)
                {
                    Player* player = (*itrTarget)->ToPlayer();
                    if (!player)
                        continue;

                    if (redToxinGuids.size() < redCount)
                    {
                        redToxinGuids.insert(player->GetGUID());
                    }
                    else if (yellowToxinGuids.size() < yellowCount)
                    {
                        yellowToxinGuids.insert(player->GetGUID());
                    }
                    else if (blueToxinGuids.size() < blueCount)
                    {
                        blueToxinGuids.insert(player->GetGUID());
                    }
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                ObjectGuid targetGuid = GetHitUnit()->GetGUID();

                uint32 spellId = 0;

                if (redToxinGuids.find(targetGuid) != redToxinGuids.end())
                {
                    spellId = SPELL_TOXIN_RED;
                }
                else if (yellowToxinGuids.find(targetGuid) != yellowToxinGuids.end())
                {
                    spellId = SPELL_TOXIN_YELLOW;
                }
                else if (blueToxinGuids.find(targetGuid) != blueToxinGuids.end())
                {
                    spellId = SPELL_TOXIN_BLUE;
                }

                if (spellId)
                {
                    GetCaster()->CastSpell(GetHitUnit(), spellId, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_toxic_ejection_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_toxic_ejection_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            std::set<ObjectGuid> redToxinGuids;
            std::set<ObjectGuid> yellowToxinGuids;
            std::set<ObjectGuid> blueToxinGuids;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_toxic_ejection_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_catalyst : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_catalyst(const char* name, uint32 toxinSpellId, uint32 triggerSpellId) :
            SpellScriptLoader(name), m_ToxinSpellId(toxinSpellId), m_TriggerSpellId(triggerSpellId) { }

        class spell_paragons_of_the_klaxxi_catalyst_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_catalyst_SpellScript);

        public:
            spell_paragons_of_the_klaxxi_catalyst_SpellScript(uint32 toxinSpellId, uint32 triggerSpellId) :
                m_ToxinSpellId(toxinSpellId), m_TriggerSpellId(triggerSpellId) { }

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() || !obj->ToPlayer()->HasAura(m_ToxinSpellId);
                });
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), m_TriggerSpellId, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_catalyst_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_catalyst_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:

            uint32 m_ToxinSpellId;
            uint32 m_TriggerSpellId;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_catalyst_SpellScript(m_ToxinSpellId, m_TriggerSpellId);
        }

        uint32 m_ToxinSpellId;
        uint32 m_TriggerSpellId;
};

class spell_paragons_of_the_klaxxi_mesmerize_aoe : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_mesmerize_aoe() : SpellScriptLoader("spell_paragons_of_the_klaxxi_mesmerize_aoe") { }

        class spell_paragons_of_the_klaxxi_mesmerize_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_mesmerize_aoe_SpellScript);

            void FilterCreatureTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return obj->GetEntry() != NPC_HUNGRY_KUNCHONG;
                });

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitCreatureTarget(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                if (Creature* pCreature = GetHitUnit()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_MESMERIZE);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_mesmerize_aoe_SpellScript::FilterCreatureTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_mesmerize_aoe_SpellScript::HandleHitCreatureTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_mesmerize_aoe_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_devour: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_devour() : SpellScriptLoader("spell_paragons_of_the_klaxxi_devour") { }

        class spell_paragons_of_the_klaxxi_devour_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_devour_AuraScript);

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetUnitOwner()->SetUnitFlags(UnitFlags(UNIT_FLAG_PLAYER_CONTROLLED));

                GetUnitOwner()->GetMotionMaster()->MoveFollow(GetCaster(), 0.0f, 0.0f, MOTION_SLOT_CONTROLLED);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->RemoveAura(SPELL_MESMERIZE);
                GetUnitOwner()->RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);

                if (GetUnitOwner()->GetMotionMaster()->GetMotionSlot(MOTION_SLOT_CONTROLLED))
                {
                    GetUnitOwner()->GetMotionMaster()->MovementExpired(false);
                    GetUnitOwner()->GetMotionMaster()->Clear(false);
                    GetUnitOwner()->StopMoving();
                }
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_devour_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_devour_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_devour_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_devour_kill : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_devour_kill() : SpellScriptLoader("spell_paragons_of_the_klaxxi_devour_kill") { }

        class spell_paragons_of_the_klaxxi_devour_kill_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_devour_kill_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                if (Creature* pCreature = GetHitUnit()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_DEVOUR);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_devour_kill_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_devour_kill_SpellScript();
        }
};

class spel_paragons_of_the_klaxxi_shield_bash: public SpellScriptLoader
{
    public:
        spel_paragons_of_the_klaxxi_shield_bash() : SpellScriptLoader("spel_paragons_of_the_klaxxi_shield_bash") { }

        class spel_paragons_of_the_klaxxi_shield_bash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spel_paragons_of_the_klaxxi_shield_bash_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                Unit* target = GetUnitOwner()->GetVictim();
                if (!target)
                    return;

                // It's 500 msecs periodic
                // But it should trigger damage in 1000 msec
                if (aurEff->GetTickNumber() % 2)
                {
                    GetUnitOwner()->CastSpell(target, SPELL_VICIOUS_ASSAULT_DMG_1, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spel_paragons_of_the_klaxxi_shield_bash_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:

        };

        AuraScript* GetAuraScript() const
        {
            return new spel_paragons_of_the_klaxxi_shield_bash_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_vicious_assault : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_vicious_assault() : SpellScriptLoader("spell_paragons_of_the_klaxxi_vicious_assault") { }

        class spell_paragons_of_the_klaxxi_vicious_assault_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_vicious_assault_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->AddAura(SPELL_VICIOUS_ASSAULT_BLEED, GetHitUnit());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_vicious_assault_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_vicious_assault_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_diminish : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_diminish() : SpellScriptLoader("spell_paragons_of_the_klaxxi_diminish") { }

        class spell_paragons_of_the_klaxxi_diminish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_diminish_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetHitUnit()->GetHealthPct() > 25.f)
                {
                    SetHitDamage(GetHitUnit()->CountPctFromCurHealth(34));
                }
                else
                {
                    GetCaster()->Kill(GetHitUnit());
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_diminish_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_diminish_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_fiery_edge : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_fiery_edge() : SpellScriptLoader("spell_paragons_of_the_klaxxi_fiery_edge") { }

        class spell_paragons_of_the_klaxxi_fiery_edge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_fiery_edge_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                if (targets.size() > 3)
                {
                    Trinity::Containers::RandomResize(targets, 3);
                }

                for (std::list<WorldObject*>::const_iterator itrTarget = targets.begin(); itrTarget != targets.end(); ++itrTarget)
                {
                    m_EdgeGuids.insert((*itrTarget)->GetGUID());
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                Unit* caster = GetCaster();

                if (m_EdgeGuids.size() < 2)
                    return;

                std::set<ObjectGuid>::const_iterator itrTarget = m_EdgeGuids.find(GetHitUnit()->GetGUID());
                if (itrTarget == m_EdgeGuids.end())
                    return;

                ++itrTarget;

                if (itrTarget == m_EdgeGuids.end())
                    itrTarget = m_EdgeGuids.begin();

                ObjectGuid secondTargetGuid = (*itrTarget);

                Unit* secondTarget = ObjectAccessor::GetUnit(*caster, secondTargetGuid);

                if (!secondTarget)
                    return;

                GetHitUnit()->CastSpell(secondTarget, SPELL_FIERY_EDGE_DUMMY_2, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_fiery_edge_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_fiery_edge_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            std::set<ObjectGuid> m_EdgeGuids;

        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_fiery_edge_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_fiery_edge_prepare: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_fiery_edge_prepare() : SpellScriptLoader("spell_paragons_of_the_klaxxi_fiery_edge_prepare") { }

        class spell_paragons_of_the_klaxxi_fiery_edge_prepare_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_fiery_edge_prepare_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (!GetCaster()->IsAlive() || !GetUnitOwner()->IsAlive())
                    return;

                GetCaster()->CastSpell(GetUnitOwner(), SPELL_FIERY_EDGE_DUMMY_1, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_fiery_edge_prepare_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_fiery_edge_prepare_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_fiery_edge_aura: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_fiery_edge_aura() : SpellScriptLoader("spell_paragons_of_the_klaxxi_fiery_edge_aura") { }

        class spell_paragons_of_the_klaxxi_fiery_edge_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_fiery_edge_aura_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetUnitOwner()->CastSpell(GetCaster(), SPELL_FIERY_EDGE_DMG, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_paragons_of_the_klaxxi_fiery_edge_aura_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_fiery_edge_aura_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_fiery_edge_dmg : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_fiery_edge_dmg() : SpellScriptLoader("spell_paragons_of_the_klaxxi_fiery_edge_dmg") { }

        class spell_paragons_of_the_klaxxi_fiery_edge_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_fiery_edge_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                {
                    targets.clear();
                    return;
                }

                Unit* caster = GetCaster();

                if (!m_FieryEdgeCasterGuid)
                {
                    Aura* aurFieryEdge = caster->GetAura(SPELL_FIERY_EDGE_DUMMY_1);
                    if (!aurFieryEdge)
                    {
                        targets.clear();
                        return;
                    }

                    m_FieryEdgeCasterGuid = aurFieryEdge->GetCasterGUID();
                }

                Unit* fieryEdgeCaster = ObjectAccessor::GetUnit(*caster, m_FieryEdgeCasterGuid);

                // Cannot hit target if
                // 1. the target is not player.
                // 2. the target is the caster
                // 3. the targets is not between the caster and the 'fiery edge' caster
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() ||
                        obj->GetGUID() == caster->GetGUID() ||
                        (obj->GetGUID() != m_FieryEdgeCasterGuid &&
                        !obj->IsInBetween(caster, fieryEdgeCaster, 1.0f));
                });
            }

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float dist = GetCaster()->GetDistance(GetHitUnit());

                if (dist > FIERY_EDGE_DAMAGE_DIST_MAX)
                    dist = FIERY_EDGE_DAMAGE_DIST_MAX;
                else if (dist < 1.0f)
                    dist = 1.0f;

                int32 reduceDamage = dist * ((FIERY_EDGE_DAMAGE_MAX - FIERY_EDGE_DAMAGE_MIN) / FIERY_EDGE_DAMAGE_DIST_MAX);
                int32 damage = FIERY_EDGE_DAMAGE_MAX - reduceDamage;
                if (damage < FIERY_EDGE_DAMAGE_MIN)
                    damage = FIERY_EDGE_DAMAGE_MIN;

                SetHitDamage(damage);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_fiery_edge_dmg_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_fiery_edge_dmg_SpellScript::CalculateDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }

        private:

            ObjectGuid m_FieryEdgeCasterGuid = ObjectGuid::Empty;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_fiery_edge_dmg_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_store_kinetic_energy : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_store_kinetic_energy() : SpellScriptLoader("spell_paragons_of_the_klaxxi_store_kinetic_energy") { }

        class spell_paragons_of_the_klaxxi_store_kinetic_energy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_store_kinetic_energy_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                std::list<WorldObject*> rangeTargets;

                for (auto target : targets)
                {
                    if (GetCaster()->GetDistance(target) >= 15.0f)
                    {
                        rangeTargets.push_back(target);
                    }
                }

                WorldObject* target = NULL;

                if (!rangeTargets.empty())
                {
                    target = Trinity::Containers::SelectRandomContainerElement(rangeTargets);
                }
                else if (!targets.empty())
                {
                    target = Trinity::Containers::SelectRandomContainerElement(targets);
                }

                if (target)
                {
                    targets.clear();
                    targets.push_back(target);
                }

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                //GetCaster()->CastSpell(GetHitUnit(), SPELL_FLASH_CHARGE, true);
                GetCaster()->GetMotionMaster()->MoveCharge(GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY(), GetHitUnit()->GetPositionZ());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_store_kinetic_energy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_store_kinetic_energy_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_store_kinetic_energy_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_flash_dmg : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_flash_dmg() : SpellScriptLoader("spell_paragons_of_the_klaxxi_flash_dmg") { }

        class spell_paragons_of_the_klaxxi_flash_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_flash_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                Position beforeFlashPos = GetCaster()->GetPosition();
                Position afterFlashPos = GetCaster()->GetPosition();

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    if (npc_karoz_the_locust::npc_karoz_the_locustAI* karozAI = CAST_AI(npc_karoz_the_locust::npc_karoz_the_locustAI, pCreature->GetAI()))
                    {
                        karozAI->GetBeforeFlashPos(beforeFlashPos);
                    }
                }

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() ||
                        !IsInBetween(obj, &beforeFlashPos, &afterFlashPos);
                });
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_flash_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_flash_dmg_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_flash_dmg_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:

            // There is no 'IsInBetween' function for positions as arguments
            // Create local function (copy of WorldObject::IsInBetween)
            bool IsInBetween(WorldObject* target, Position* firstPos, Position* lastPos)
            {
                float dist = target->GetExactDist2d(firstPos->GetPositionX(), firstPos->GetPositionY());

                const float size = 1.0f;

                float angle = firstPos->GetAngle(lastPos);

                return (size * size) >= target->GetExactDist2dSq(firstPos->GetPositionX() + cos(angle) * dist, firstPos->GetPositionY() + sin(angle) * dist);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_flash_dmg_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_hurl_amber_aoe : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_hurl_amber_aoe() : SpellScriptLoader("spell_paragons_of_the_klaxxi_hurl_amber_aoe") { }

        class spell_paragons_of_the_klaxxi_hurl_amber_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_hurl_amber_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_HURL_AMBER_MISSILE, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_hurl_amber_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_hurl_amber_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_hurl_amber_aoe_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_bloodletting_missile_self : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_bloodletting_missile_self() : SpellScriptLoader("spell_paragons_of_the_klaxxi_bloodletting_missile_self") { }

        class spell_paragons_of_the_klaxxi_bloodletting_missile_self_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_bloodletting_missile_self_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                uint8 count = BLOODLETTING_10;
                switch (GetCaster()->GetMap()->GetDifficultyID())
                {
                    case DIFFICULTY_10_N: count = BLOODLETTING_10; break;
                    case DIFFICULTY_25_N: count = BLOODLETTING_25; break;
                    case DIFFICULTY_10_HC: count = BLOODLETTING_10H; break;
                    case DIFFICULTY_25_HC: count = BLOODLETTING_25H; break;
                }

                for (uint8 i = 0; i < count; ++i)
                {
                    GetCaster()->CastSpell(bloodlettingPos[i].GetPositionX(), bloodlettingPos[i].GetPositionY(), bloodlettingPos[i].GetPositionZ(), SPELL_BLOODLETTING_MISSILE_1, true);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_paragons_of_the_klaxxi_bloodletting_missile_self_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_bloodletting_missile_self_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_genetic_alteration : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_genetic_alteration() : SpellScriptLoader("spell_paragons_of_the_klaxxi_genetic_alteration") { }

        class spell_paragons_of_the_klaxxi_genetic_alteration_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_genetic_alteration_SpellScript);

            void HandleHitTarget(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (TargetUsedTankAbilities(GetHitUnit()))
                    return;

                if (Aura* aur = GetHitUnit()->GetAura(SPELL_INJECTION_DUMMY))
                {
                    uint8 stacks = aur->GetStackAmount();
                    if (stacks < 99)
                        aur->SetStackAmount(stacks + 1);
                }
                else
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_INJECTION_DUMMY, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_genetic_alteration_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_genetic_alteration_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_injection: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_injection() : SpellScriptLoader("spell_paragons_of_the_klaxxi_injection") { }

        class spell_paragons_of_the_klaxxi_injection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_injection_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                {
                    // Cannot use this block because it's wrong calculations of positions based on vmaps
                    /*for (uint8 i = 0; i < AMBER_PARASITE_COUNT; ++i)
                    {
                        GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_INJECTION_MISSILE, true);
                    }*/

                    if (Creature* pCreature = GetCaster()->ToCreature())
                    {
                        std::list<Unit*> targets;
                        pCreature->AI()->SelectTargetList(targets, AMBER_PARASITE_COUNT, SELECT_TARGET_RANDOM, 0.0f, true);

                        for (auto target : targets)
                        {
                            GetUnitOwner()->CastSpell(target, SPELL_INJECTION_MISSILE, true);
                        }
                    }
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_injection_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_injection_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_hunger : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_hunger() : SpellScriptLoader("spell_paragons_of_the_klaxxi_hunger") { }

        class spell_paragons_of_the_klaxxi_hunger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_hunger_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() ||
                        obj->ToPlayer()->HasAura(SPELL_HUNGER, GetCaster()->GetGUID());
                });

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_hunger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_hunger_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_feed : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_feed() : SpellScriptLoader("spell_paragons_of_the_klaxxi_feed") { }

        class spell_paragons_of_the_klaxxi_feed_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_feed_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() ||
                        !obj->ToPlayer()->HasAura(SPELL_HUNGER, GetCaster()->GetGUID());
                });

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_feed_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_feed_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_mutate_aoe : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_mutate_aoe() : SpellScriptLoader("spell_paragons_of_the_klaxxi_mutate_aoe") { }

        class spell_paragons_of_the_klaxxi_mutate_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_mutate_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                std::list<Player*> correctTargets;

                for (auto target : targets)
                {
                    if (Player* player = target->ToPlayer())
                    {
                        if (player->GetRoleForGroup() == ROLE_DAMAGE)
                        {
                            correctTargets.push_back(player);
                        }
                    }
                }

                if (correctTargets.size() > 0)
                {
                    Trinity::Containers::RandomResize(correctTargets, 1);
                    targets.clear();
                    targets.push_back(correctTargets.front());
                }
                else
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_MUTATE, true);

                if (GetCaster()->GetMap()->IsHeroic())
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FAULTY_MUTATION, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_mutate_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_mutate_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_mutate_aoe_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_aim_aoe : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_aim_aoe() : SpellScriptLoader("spell_paragons_of_the_klaxxi_aim_aoe") { }

        class spell_paragons_of_the_klaxxi_aim_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_aim_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                std::list<Player*> correctTargets;

                for (auto target : targets)
                {
                    if (Player* player = target->ToPlayer())
                    {
                        if (player->GetRoleForGroup() == ROLE_DAMAGE)
                        {
                            correctTargets.push_back(player);
                        }
                    }
                }

                if (correctTargets.size() > 0)
                {
                    Trinity::Containers::RandomResize(correctTargets, 1);
                    targets.clear();
                    targets.push_back(correctTargets.front());
                }
                else
                {
                    Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->SetFacingToObject(GetHitUnit());

                float dist = GetCaster()->GetExactDist(GetHitUnit());
                if (dist < 40.f)
                {
                    float x, y;
                    float z = GetCaster()->GetPositionZ() + 3.0f;
                    GetCaster()->GetNearPoint2D(x, y, 40.f, GetCaster()->GetAngle(GetHitUnit()));
                    GetHitUnit()->CastSpell(x, y, z, SPELL_POINT_BLANK_SHOT, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paragons_of_the_klaxxi_aim_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_aim_aoe_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        class spell_paragons_of_the_klaxxi_aim_aoe_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_aim_aoe_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetCaster()->CastSpell(GetUnitOwner(), SPELL_FIRE, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_aim_aoe_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_aim_aoe_AuraScript();
        }

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_aim_aoe_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_strong_legs_jump_1 : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_strong_legs_jump_1() : SpellScriptLoader("spell_paragons_of_the_klaxxi_strong_legs_jump_1") { }

        class spell_paragons_of_the_klaxxi_strong_legs_jump_1_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_strong_legs_jump_1_SpellScript);

            void HandleLaunch(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                // Prevent from bugs
                if (caster->GetMapId() != 1136)
                    return;

                Position const* nearestAmberPos = NULL;
                for (uint8 i = 0; i < AMBER_BOMB_COUNT; ++i)
                {
                    if (!nearestAmberPos || caster->GetDistance(*nearestAmberPos) > caster->GetDistance(amberBombPos[i]))
                        nearestAmberPos = &amberBombPos[i];
                }

                if (nearestAmberPos)
                {
                    float speedXY = caster->GetDistance(*nearestAmberPos);
                    const float speedZ = 10.f;
                    caster->GetMotionMaster()->MoveJump(*nearestAmberPos, speedXY, speedZ);
                }
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_paragons_of_the_klaxxi_strong_legs_jump_1_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_strong_legs_jump_1_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_strong_legs_override: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_strong_legs_override() : SpellScriptLoader("spell_paragons_of_the_klaxxi_strong_legs_override") { }

        class spell_paragons_of_the_klaxxi_strong_legs_override_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_strong_legs_override_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                if (Player* player = GetUnitOwner()->ToPlayer())
                {
                    player->RemoveTemporarySpell(SPELL_HURL_AMBER_MISSILE_2);
                }
            }

            /*void OnUpdate(uint32 diff, AuraEffect* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                if (m_UpdateTimer <= diff)
                {
                    m_UpdateTimer = 2000;

                    Player* player = GetUnitOwner()->ToPlayer();
                    if (!player)
                        return;

                    bool isAmberNear = IsAmberBombNear(player);

                    if (!m_IsHurlAmberSpellApplied && isAmberNear)
                    {
                        ApplyHurlAmberSpell(player, true);
                    }
                    else if (m_IsHurlAmberSpellApplied && !isAmberNear)
                    {
                        ApplyHurlAmberSpell(player, false);
                    }
                }
                else
                {
                    m_UpdateTimer -= diff;
                }
            }*/

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_paragons_of_the_klaxxi_strong_legs_override_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
                //OnEffectUpdate += AuraEffectUpdateFn(spell_paragons_of_the_klaxxi_strong_legs_override_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS);
            }

        private:

            void ApplyHurlAmberSpell(Player* player, bool value)
            {
                if (value)
                {
                    m_IsHurlAmberSpellApplied = true;
                    player->AddTemporarySpell(SPELL_HURL_AMBER_MISSILE_2);
                }
                else
                {
                    m_IsHurlAmberSpellApplied = false;
                    player->RemoveTemporarySpell(SPELL_HURL_AMBER_MISSILE_2);
                }
            }

        private:

            uint32 m_UpdateTimer = 2000;
            bool m_IsHurlAmberSpellApplied = false;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_strong_legs_override_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_hurl_amber_missile_2 : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_hurl_amber_missile_2() : SpellScriptLoader("spell_paragons_of_the_klaxxi_hurl_amber_missile_2") { }

        class spell_paragons_of_the_klaxxi_hurl_amber_missile_2_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_hurl_amber_missile_2_SpellScript);

            SpellCastResult CheckCast()
            {
                if (Unit* caster = GetCaster())
                    if (IsAmberBombNear(caster))
                        return SpellCastResult::SPELL_CAST_OK;

                return SpellCastResult::SPELL_FAILED_DONT_REPORT;
            }

            void HandleBeforeCast()
            {
                if (!GetCaster())
                    return;

                if (Creature* amberBomb = GetCaster()->FindNearestCreature(NPC_AMBER_BOMB, 2.0f))
                {
                    amberBomb->DespawnOrUnsummon();
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_paragons_of_the_klaxxi_hurl_amber_missile_2_SpellScript::CheckCast);
                BeforeCast += SpellCastFn(spell_paragons_of_the_klaxxi_hurl_amber_missile_2_SpellScript::HandleBeforeCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_hurl_amber_missile_2_SpellScript();
        }
};

class spell_paragons_of_the_klaxxi_hurl_amber_dmg_2 : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_hurl_amber_dmg_2() : SpellScriptLoader("spell_paragons_of_the_klaxxi_hurl_amber_dmg_2") { }

        class spell_paragons_of_the_klaxxi_hurl_amber_dmg_2_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_hurl_amber_dmg_2_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetHitUnit()->GetEntry() == NPC_AMBER)
                {
                    GetCaster()->Kill(GetHitUnit());
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_hurl_amber_dmg_2_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_hurl_amber_dmg_2_SpellScript();
        }
};

class spel_paragons_of_the_klaxxi_rapid_fire: public SpellScriptLoader
{
    public:
        spel_paragons_of_the_klaxxi_rapid_fire() : SpellScriptLoader("spel_paragons_of_the_klaxxi_rapid_fire") { }

        class spel_paragons_of_the_klaxxi_rapid_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spel_paragons_of_the_klaxxi_rapid_fire_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                uint32 tick = aurEff->GetTickNumber();
                if (tick < SONIC_PULSE_SPELLS_COUNT)
                {
                    float orientation = (tick + 1) * ((2 * M_PI) / SONIC_PULSE_SPELLS_COUNT);
                    GetUnitOwner()->SetFacingTo(orientation);
                    GetUnitOwner()->SetOrientation(orientation);
                    GetUnitOwner()->CastSpell(GetUnitOwner(), sonicPulseSpells[tick], true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spel_paragons_of_the_klaxxi_rapid_fire_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:

        };

        AuraScript* GetAuraScript() const
        {
            return new spel_paragons_of_the_klaxxi_rapid_fire_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_faulty_mutation: public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_faulty_mutation() : SpellScriptLoader("spell_paragons_of_the_klaxxi_faulty_mutation") { }

        class spell_paragons_of_the_klaxxi_faulty_mutation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paragons_of_the_klaxxi_faulty_mutation_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                {
                    GetCaster()->CastSpell(GetUnitOwner(), SPELL_FAULTY_MUTATION_DMG, true);
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_paragons_of_the_klaxxi_faulty_mutation_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_paragons_of_the_klaxxi_faulty_mutation_AuraScript();
        }
};

class spell_paragons_of_the_klaxxi_prey : public SpellScriptLoader
{
    public:
        spell_paragons_of_the_klaxxi_prey() : SpellScriptLoader("spell_paragons_of_the_klaxxi_prey") { }

        class spell_paragons_of_the_klaxxi_prey_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paragons_of_the_klaxxi_prey_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                GetCaster()->RemoveAura(SPELL_FAULTY_MUTATION);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_paragons_of_the_klaxxi_prey_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paragons_of_the_klaxxi_prey_SpellScript();
        }
};


struct spell_area_paragons_of_the_klaxxi_reaction_yellow : AreaTriggerAI
{
    spell_area_paragons_of_the_klaxxi_reaction_yellow(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        caster->AddAura(SPELL_NOXIOUS_VAPORS, target);
    }

    bool OnRemoveTarget(Unit* target, bool /*byExpire*/)
    {
        target->RemoveAura(SPELL_NOXIOUS_VAPORS);
    }
};



struct spell_area_paragons_of_the_klaxxi_sonic_projection : AreaTriggerAI
{
    spell_area_paragons_of_the_klaxxi_sonic_projection(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        float targetX = 0.0f;
        float targetY = 0.0f;
        caster->GetNearPoint2D(targetX, targetY, 60.0f, frand(0.0f, 2 * float(M_PI)));

        Position targetPos;
        targetPos.Relocate(targetX, targetY, caster->GetPositionZ(), 0.0f);

        at->Relocate(*caster);
        //at->SetSource(*caster);

        at->SetDestination(targetPos, 0);
        //at->SetTrajectory(AreatriggerInterpolation::AREATRIGGER_INTERPOLATION_LINEAR);
    }

    void OnUnitEnter(Unit* target)
    {
        // Enable damage after few seconds
        if (at->GetDuration() > (at->GetTotalDuration() - 2000))
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        caster->AddAura(SPELL_SONIC_PROJECTION_DMG, target);
    }

    bool OnRemoveTarget(Unit* target, bool /*byExpire*/)
    {
        target->RemoveAura(SPELL_SONIC_PROJECTION_DMG);
    }
};

struct spell_area_paragons_of_the_klaxxi_caustic_amber : AreaTriggerAI
{
    spell_area_paragons_of_the_klaxxi_caustic_amber(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        caster->AddAura(SPELL_CAUSTIC_AMBER_DMG, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_CAUSTIC_AMBER_DMG);
    }
};

struct spel_area_paragons_of_the_klaxxi_sonic_pulse : AreaTriggerAI
{
    spel_area_paragons_of_the_klaxxi_sonic_pulse(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        //Creature* pCreature = caster->ToCreature();
        Unit* pCreature = caster;
        if (!pCreature)
            return;

        int8 index = -1;
        for (uint8 i = 0; i < SONIC_PULSE_COUNT; ++i)
        {
            if (sonicPulseTriggers[i] == at->GetEntry())
            {
                index = i;
                break;
            }
        }

        if (index < 0)
            return;

        Position destPos;

        const float dist = 100.f;
        const float sector = 2 * float(M_PI) / (SONIC_PULSE_SPELLS_COUNT * SONIC_PULSE_COUNT);
        float offset = sector * index - ((sector * SONIC_PULSE_COUNT) / 2);
        float angle = pCreature->GetOrientation() + offset;

        destPos.m_positionX = pCreature->m_positionX + dist * std::cos(angle);
        destPos.m_positionY = pCreature->m_positionY + dist * std::sin(angle);
        destPos.m_positionZ = pCreature->m_positionZ;

        at->Relocate(*pCreature);
        //at->SetSource(*pCreature);

        at->SetDestination(destPos, 0);
        //at->SetTrajectory(AreatriggerInterpolation::AREATRIGGER_INTERPOLATION_LINEAR);
    }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        caster->AddAura(SPELL_SONIC_PULSE_DMG, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_SONIC_PULSE_DMG);
    }
};

void AddSC_boss_paragons_of_the_klaxxi()
{
    new npc_klaxxi_paragons();                      // 71592
    new npc_kilruk_the_wind_reaver();               // 71161
    new npc_xaril_the_poisoned_mind();              // 71157
    new npc_kaztik_the_manipulator();               // 71156
    new npc_korven_the_prime();                     // 71155
    new npc_iyyokuk_the_lucid();                    // 71160
    new npc_karoz_the_locust();                     // 71154
    new npc_skeer_the_bloodseeker();                // 71152
    new npc_rikkal_the_dissector();                 // 71158
    new npc_hisek_the_swarmkeeper();                // 71153
    new npc_paragons_of_the_klaxxi_mantid_amber();  // 71628
    new npc_paragons_of_the_klaxxi_impact_jump_target();    // 71309
    new npc_paragons_of_the_klaxxi_hungry_kunchong();   // 71420
    new npc_paragons_of_the_klaxxi_amber();             // 71407
    new npc_paragons_of_the_klaxxi_blood();         // 71542
    new npc_paragons_of_the_klaxxi_amber_parasite();    // 71578

    new spell_paragons_of_the_klaxxi_mutilate();    // 143941
    new spell_paragons_of_the_klaxxi_reave();       // 148677
    new spell_paragons_of_the_klaxxi_death_from_above_summon(); // 142263
    new spell_paragons_of_the_klaxxi_death_from_above_jump_2(); // 142265
    new spell_paragons_of_the_klaxxi_caustic_blood();   // 142315
    new spell_paragons_of_the_klaxxi_tenderizing_strikes_dmg(); // 142929
    new spell_paragons_of_the_klaxxi_toxic_ejection();  // 142528
    new spell_paragons_of_the_klaxxi_catalyst("spell_paragons_of_the_klaxxi_catalyst_blue", SPELL_TOXIN_BLUE, SPELL_REACTION_BLUE);         // 142725
    new spell_paragons_of_the_klaxxi_catalyst("spell_paragons_of_the_klaxxi_catalyst_red", SPELL_TOXIN_RED, SPELL_REACTION_RED);            // 142726
    new spell_paragons_of_the_klaxxi_catalyst("spell_paragons_of_the_klaxxi_catalyst_yellow", SPELL_TOXIN_YELLOW, SPELL_REACTION_YELLOW);   // 142727
    new spell_paragons_of_the_klaxxi_mesmerize_aoe();   // 142668
    new spell_paragons_of_the_klaxxi_devour();          // 142649
    new spell_paragons_of_the_klaxxi_devour_kill();     // 142638
    new spel_paragons_of_the_klaxxi_shield_bash();      // 143977
    new spell_paragons_of_the_klaxxi_vicious_assault(); // 143981
    new spell_paragons_of_the_klaxxi_diminish();        // 143666
    new spell_paragons_of_the_klaxxi_fiery_edge();      // 142416
    new spell_paragons_of_the_klaxxi_fiery_edge_prepare();  // 142811
    new spell_paragons_of_the_klaxxi_fiery_edge_aura(); // 142808
    new spell_paragons_of_the_klaxxi_fiery_edge_dmg();  // 142809
    new spell_paragons_of_the_klaxxi_store_kinetic_energy();    // 143709
    new spell_paragons_of_the_klaxxi_flash_dmg();       // 143701
    new spell_paragons_of_the_klaxxi_hurl_amber_aoe();  // 143761
    new spell_paragons_of_the_klaxxi_bloodletting_missile_self();   // 143282
    new spell_paragons_of_the_klaxxi_genetic_alteration();  // 143278
    new spell_paragons_of_the_klaxxi_injection();           // 143339
    new spell_paragons_of_the_klaxxi_hunger();          // 143358
    new spell_paragons_of_the_klaxxi_feed();            // 143362
    new spell_paragons_of_the_klaxxi_mutate_aoe();      // 143336
    new spell_paragons_of_the_klaxxi_aim_aoe();         // 142948
    new spell_paragons_of_the_klaxxi_strong_legs_jump_1();  // 143964
    new spell_paragons_of_the_klaxxi_strong_legs_override();    // 143963
    new spell_paragons_of_the_klaxxi_hurl_amber_missile_2();    // 143966
    new spell_paragons_of_the_klaxxi_hurl_amber_dmg_2();    // 143967
    new spel_paragons_of_the_klaxxi_rapid_fire();       // 143243
    new spell_paragons_of_the_klaxxi_faulty_mutation(); // 148589
    new spell_paragons_of_the_klaxxi_prey();            // 144286

    RegisterAreaTriggerAI(spell_area_paragons_of_the_klaxxi_reaction_yellow); // 142737
    RegisterAreaTriggerAI(spell_area_paragons_of_the_klaxxi_sonic_projection);   // 143765
    RegisterAreaTriggerAI(spell_area_paragons_of_the_klaxxi_caustic_amber);      // 143740
    RegisterAreaTriggerAI(spel_area_paragons_of_the_klaxxi_sonic_pulse); // 143226, 143227,  143228, 143229, 143230, 143231, 143232, 143233, 143234, 143236, 143237, 143238
}
