#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
#include "SceneHelper.h"

#define THOK_POWER_TYPE POWER_MANA
#define THOK_POWER_MAX 100

#define ENERGY_UPDATE_TIMER 500 // in milliseconds
#define DEFAULT_ENERGY_REGEN_DURATION 12000 // in milliseconds
#define MINIMUM_ENERGY_REGEN_DURATION 1000

// The boss regenerates 100 energy in 12 seconds at the beginning
// Each acceleration increase regeneration rate to -2 seconds

enum ScriptedTexts
{
    SAY_AKOLIK_1 = 0,
    SAY_AKOLIK_2 = 1,
    SAY_AKOLIK_3 = 2,

    SAY_GORAI_1 = 0,

    SAY_MONTAK_1 = 0,
};

enum Spells
{
    // Intro
    SPELL_LIGHTNING_CHAIN = 147987,
    SPELL_KILL_JAILERS = 147994,

    SPELL_ZERO_MANA_REGEN = 96301,

    SPELL_BERSERK = 26662,

    SPELL_POWER_REGEN_AURA = 143345,
    SPELL_POWER_REGEN = 143409, // triggered by 143345
    SPELL_CLUMP_CHECK = 143430, // triggered by 143345 and by 143991, used to check for bloodied targets count

    SPELL_FEARSOME_ROAR = 143426,
    SPELL_PANIC = 143766,

    SPELL_TAIL_LASH = 143428,

    SPELL_DEAFENING_SCREECH = 143343,
    SPELL_ACCELERATION = 143411,

    SPELL_SHOCK_BLAST_PERIODIC = 143991, // ?
    SPELL_SHOCK_BLAST_FORCE = 143706, // casted on shock collar
    SPELL_SHOCK_BLAST_DMG = 143707, // casted by shock collar

    SPELL_BLOODIED_WOUNDS = 143451,
    SPELL_BLOODIED = 143452,

    SPELL_BLOOD_FRENZY_KNOCKBACK = 144067,
    SPELL_BLOOD_FRENZY = 143440,
    SPELL_BLOOD_FRENZY_SPEED = 143442,

    SPELL_FIXATE_AOE = 143445,
    SPELL_ATTACK_ME = 146539,
    SPELL_FIXATE_IMMUNITY = 146540,
    SPELL_FIXATE_DUMMY = 146581,

    SPELL_CHOMP_CHECKER = 126100,
    SPELL_CHOMP = 143465,
    SPELL_CHOMP_2 = 147996, // casted by npc when thok eats him
    SPELL_MEAT_EXPLOSION = 130620, // casted by npc when he dies

    SPELL_MENDING = 149569, // in heroic, boss casts the spell after eating npc

    SPELL_SKELETON_KEY = 146589,
    SPELL_UNLOCKING = 143917,

    // Acid
    SPELL_ACID_BREATH = 143780,
    SPELL_CORROSIVE_BLOOD_FORCE = 143795, // casted on shock collar
    SPELL_CORROSIVE_BLOOD_DMG = 143791,

    // Ice
    SPELL_FREEZING_BREATH = 143773,
    SPELL_ICY_BLOOD_FORCE = 143801, // casted on shock collar
    SPELL_ICY_BLOOD_DMG = 143800,
    SPELL_FROZEN_SOLID_STUN_1 = 143775,
    SPELL_FROZEN_SOLID_SUMMON = 143776,
    SPELL_FROZEN_SOLID_STUN_2 = 143777,

    // Fire
    SPELL_SCORCHING_BREATH = 143767,
    SPELL_BURNING_BLOOD_FORCE = 143781, // casted on shock collar
    SPELL_BURNING_BLOOD_AOE = 143782,
    SPELL_BURNING_BLOOD_DMG = 143783,
    SPELL_BURNING_BLOOD_PERIODIC = 143784,

    // Kor'kron Jailer
    SPELL_ENRAGE = 145974,

    // AKolik
    SPELL_AKOLIKS_INCANTATION = 144016,

    // Waterspeaker Gorai
    SPELL_WATER_OF_PURITY = 144013,
    SPELL_RESTORATIVE_WATERS = 144117,
    SPELL_RESTORATIVE_WATERS_HEAL = 144118,

    // Montak
    SPELL_FIRE_OF_THE_SPIRITS = 144014,
    SPELL_FLAME_COATING = 144115,
    SPELL_FLAME_COATING_DMG = 144116,

    // Captive Cave Bat
    SPELL_VAMPIRIC_FRENZY_AURA = 147980,
    SPELL_VAMPIRIC_FRENZY_DMG_1 = 147978, // triggered every second by 147980
    SPELL_VAMPIRIC_FRENZY_DMG_2 = 147981, // second dmg spell, same as 147978 but not triggered

    // Starved Yeti
    SPELL_WRECKING_BALL_VISUAL = 147946, // red beam at the dest
    SPELL_WRECKING_BALL_DUMMY = 147952,
    SPELL_WRECKING_BALL_AURA = 148144, // while moving
    SPELL_WRECKING_BALL_DMG_1 = 148143, // while moving
    SPELL_WRECKING_BALL_DMG_2 = 148145, // at the end
};

enum Adds
{
    NPC_SHOCK_COLLAR = 71645,
    NPC_FOOTS_COLLAR = 73200,
    NPC_KORKRON_JAILER = 71658,
    NPC_ICE_TOMB = 71720,
    NPC_AKOLIK = 71742,
    NPC_SKUMBLADE_CAPTIVE = 71744,
    NPC_WATERSPEAKER_GORAI = 71749,
    NPC_INKGILL_CAPTIVE = 71753,
    NPC_MONTAK = 71763,
    NPC_GAI_CHO_REFUGEE = 71764,

    NPC_STARVED_YETI = 73526, // in heroic, 1273.469, -5200.588, -232.0436, 2.026163
    NPC_CAPTIVE_CAVE_BAT = 73522, // in heroic
};

enum Events
{
    EVENT_FEARSOME_ROAR = 1,
    EVENT_DEAFENING_SCREECH,
    EVENT_TAIL_LASH,
    EVENT_SHOCK_BLAST,
    EVENT_BLOODIED_CHECK,
    EVENT_BLOOD_FRENZY_INIT,
    EVENT_BLOOD_FRENZY_FIXATE,
    EVENT_BLOOD_FRENZY_MOVE,
    EVENT_BERSERK,

    // Starved Yeti
    EVENT_WRECKING_BALL,
};

enum Actions
{
    ACTION_FULL_POWER = 1,
    ACTION_RESET_POWER,
    ACTION_BLOOD_FRENZY,
    ACTION_ATTACK_PRISONER,
    ACTION_CONTINUE_ATTACKING,
    ACTION_CONTINUE_ATTACKING_ACID,
    ACTION_CONTINUE_ATTACKING_FROST,
    ACTION_CONTINUE_ATTACKING_FIRE,

    ACTION_SAUROK_OPEN,
    ACTION_YAUNGOL_OPEN,
    ACTION_JINYU_OPEN,

    ACTION_PRISONER_RELEASED,

    ACTION_RELEASE_BEAST,
    ACTION_WRECKING_BALL,
};

enum Timers
{
    TIMER_BERSERK = 10 * MINUTE * IN_MILLISECONDS,

    TIMER_FEARSOME_ROAR_FIRST = 11 * IN_MILLISECONDS,
    TIMER_FEARSOME_ROAR = 11 * IN_MILLISECONDS,
    TIMER_TAIL_LASH_FIRST = 8 * IN_MILLISECONDS,
    TIMER_TAIL_LASH = 15 * IN_MILLISECONDS,
    TIMER_SHOCK_BLAST = 5 * IN_MILLISECONDS,
    TIMER_BLOODIED = 2 * IN_MILLISECONDS,
    TIMER_FIXATE_FIRST = 5 * IN_MILLISECONDS,
    TIMER_FIXATE = 14 * IN_MILLISECONDS,

    // Starved Yeti
    TIMER_WRECKING_BALL_FIRST = 4 * IN_MILLISECONDS,
    TIMER_WRECKING_BALL = 19 * IN_MILLISECONDS, // 15 secs stun after dmg + 4 secs
};

enum eData
{
    DATA_THOK_IS_INTRO = 1,
    DATA_DEAFENING_SCREECH_COUNT,
    DATA_FIXATE_GUID,
    DATA_PRISONER_GUID,
    DATA_NPC_NUMBER,

    POINT_WRECKING_BALL,
};

enum Phases : int
{
    PHASE_NONE = 0,
    PHASE_NORMAL = 1,
    PHASE_ACID = 2,
    PHASE_FROST = 3,
    PHASE_FIRE = 4,
    PHASE_FRENZY = 5,
};

enum VehicleSeats
{
    SEAT_SHOCK_COLLAR = 0,
    SEAT_RIGHT_FOOT = 4,
    SEAT_LEFT_FOOT = 5,
    SEAT_FACE = 6,
};

enum Points
{
    POINT_THOK_POS = 1,
    POINT_PRISONER,

    POINT_OUT_OF_PRISON,


};

enum Items
{
    ITEM_SKELETON_KEY = 100948,
};

#define BLOODIED_PLAYERS_COUNT_10 5
#define BLOODIED_PLAYERS_COUNT_25 15

#define CAPTIVE_CAVE_BATS_COUNT 7
const Position captiveCaveBatPos[CAPTIVE_CAVE_BATS_COUNT] =
{
    { 1278.523f, -5191.788f, -280.8389f, 2.180029f },
    { 1260.793f, -5212.596f, -276.4608f, 1.922045f },
    { 1263.5f, -5214.085f, -259.1307f, 1.941185f },
    { 1255.297f, -5211.448f, -259.1628f, 1.874746f },
    { 1280.135f, -5199.753f, -280.7762f, 2.147932f },
    { 1279.668f, -5200.719f, -272.6732f, 2.138875f },
    { 1280.45f, -5200.299f, -251.0793f, 2.147595f }
};

#define WRECING_BALL_POS_COUNT 8
const Position wreckingBallPos[WRECING_BALL_POS_COUNT] =
{
    { 1165.089722f, -5056.974121f, -290.45f, 3.885522f },
    { 1136.564819f, -5100.233398f, -290.45f, 4.554421f },
    { 1148.650146f, -5152.220703f, -290.45f, 5.299671f },
    { 1192.260132f, -5181.404297f, -290.45f, 6.273988f },
    { 1245.067261f, -5168.517090f, -290.45f, 0.699406f },
    { 1273.747681f, -5122.564941f, -290.44f, 1.313326f },
    { 1266.348022f, -5071.812500f, -290.50f, 2.079967f },
    { 1219.368896f, -5044.836914f, -290.44f, 3.005437f }
};

const Position thokPos = { 1183.07f, -5125.92f, -289.94f, 0.58f };
const Position starvedYetiPos = { 1273.469f, -5200.588f, -232.0436f, 2.026163f };
const Position jailerPos = { 1295.988f, -5050.776f, -290.38f, 3.70f };

enum Prisoners : int
{
    PRISONER_AKOLIK = 0,
    PRISONER_GORAI = 1,
    PRISONER_MONTAK = 2,
};

#define PRISONERS_COUNT 3
const Position prisonersPos[PRISONERS_COUNT][2] =
{
    {
        { 1311.245f, -5145.018f, -288.02f, 3.118788f }, // Akolik start position
        { 1275.661f, -5124.638f, -290.44f, 2.799044f }  // Akolik position after
    },
    {
        { 1228.625f, -4995.946f, -288.35f, 4.3426f },   // Gorai start position
        { 1218.651f, -5040.521f, -290.34f, 4.5910f }    // Gorai position after
    },
    {
        { 1089.359f, -5087.655f, -288.42f, 6.054901f }, // Montak start position
        { 1133.783f, -5096.753f, -290.40f, 6.069799f }  // Montak position after
    }
};

#define SKUMBLADE_CAPTIVE_COUNT 4
const Position skumbladePos[SKUMBLADE_CAPTIVE_COUNT][2] =
{
    {
        { 1314.161f, -5118.792f, -288.5541f, 2.954293f },
        { 1276.336f, -5137.182f, -290.1734f, 2.820425f }
    },
    {
        { 1319.276f, -5131.729f, -288.3864f, 2.235062f },
        { 1278.192f, -5131.603f, -290.1211f, 2.820425f }
    },
    {
        { 1322.847f, -5118.474f, -288.832f, 1.456779f },
        {1273.7095f, -5130.111f, -290.449f, 2.805153f},
    },
    {
        { 1318.3f, -5147.077f, -288.0766f, 3.108934f },
        { 1279.9f, -5121.639f, -290.1472f, 2.799044f }
    }
};

#define INKGILL_CAPTIVE_COUNT 5
const Position inkgillPos[INKGILL_CAPTIVE_COUNT][2] =
{
    {
        { 1231.823f, -5000.554f, -288.4443f, 1.753894f },
        { 1228.401f, -5038.873f, -290.0691f, 4.600235f }
    },
    {
        { 1225.957f, -5001.205f, -288.2832f, 1.100402f },
        { 1223.537f, -5038.280f, -290.0912f, 4.591072f }
    },
    {
        { 1220.72f, -4993.896f, -288.1514f, 0.136699f },
        { 1220.93f, -5037.962f, -290.1045f, 4.591072f }
    },
    {
        { 1236.137f, -4996.323f, -288.5711f, 2.5672f },
        { 1217.957f, -5036.330f, -290.0172f, 4.5910f }
    },
    {
        { 1222.25f, -4997.592f, -288.1912f, 0.5543658f },
        { 1214.96f, -5037.903f, -290.1876f, 4.591072f  }
    }
};

#define GAI_CHO_CAPTIVE_COUNT 3
const Position gaichoPos[GAI_CHO_CAPTIVE_COUNT][2] =
{
    {
        { 1091.905f, -5081.665f, -288.6278f, 5.608939f },
        { 1130.083f, -5096.790f, -290.1282f, 6.103397f }
    },
    {
        { 1094.582f, -5088.113f, -287.8883f, 5.498443f },
        { 1129.364f, -5100.679f, -290.1301f, 6.100343f }
    },
    {
        { 1088.113f, -5092.963f, -288.2752f, 5.436639f },
        { 1130.882f, -5092.471f, -290.1244f, 6.100343f }
    }
};

void AddSC_boss_thok_the_bloodthirsty()
{
    
}
