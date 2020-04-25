#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "Group.h"
#include "DatabaseEnv.h"
#include "Mail.h"

enum NPCs
{
    NPC_ANDUIN_WRYNN        = 100041,
    NPC_JAINA_PROUDMOORE_D  = 100042,
    NPC_KALEC               = 100001,
    NPC_JAINA_PROUDMOORE    = 100038,
    NPC_INVISIBLE_STALKER   = 32780,
    NPC_KEL_THUZAD          = 20350,
    NPC_GHOUL               = 28405,
    NPC_WOUNDED_DALARAN     = 32493,
    NPC_KAEL_THAS           = 100043,
    NPC_BLOOD_ELF           = 100044,
    NPC_AETHAS_SUNREAVER    = 30116,
    NPC_SUNREAVER_MAGE      = 29255,
    NPC_SUNREAVER_GUARDIAN  = 33543,
    NPC_DRAGONHAWK          = 35148,
};

enum Spells
{
    SPELL_SIMPLE_TELEPORT   = 100032,
    SPELL_TELEPORT          = 51347,
    SPELL_TELEPORT_EFFECT   = 70525,
    SPELL_TELEPORT_ANIM     = 70527,
    SPELL_REMEMBER_SHADOW   = 100042,
    SPELL_REMEMBER_SUMMON   = 23017,
    SPELL_ALPHA_75_PCT      = 44822,
    SPELL_SPOT_SCALED       = 50236,
    SPELL_MAGIC_TRACKS      = 100049,
    SPELL_DETECT_MAGIC      = 100045
};

enum Misc
{
    SOUND_REUNION_MUSIC         = 28092,
    SOUND_JAINA_DARNA_MUSIC     = 28096,

    GOB_ANTONIDAS_STATUE        = 500011,
    GOB_PORTAL_TO_DALARAN       = 500013,

    MOUNT_WHITE_STEED           = 14338,

    PHASEMASK_DALARAN           = 4,
    PHASEMASK_DALARAN_A         = 12,
    PHASEMASK_DARNASSUS         = 17,

    QUEST_THE_FATE_OF_DALARAN   = 80012,
    QUEST_DARNASSUS_ATTACKED    = 80013,
    QUEST_TRACKING_THE_THIEVES  = 80014,
    QUEST_JAINAS_RESOLUTION     = 80015,

    MAP_KALIMDOR                = 1,
    MAP_DALARAN_INSTANCED       = 727,

    MAIL_DARNASSUS_ENTRY        = 293,
    MAIL_DELIVER_DELAY_MIN      = 1 * MINUTE,
    MAIL_DELIVER_DELAY_MAX      = 2 * MINUTE
};

enum Events
{
    ACTION_INTRO_TELEPORT   = 1,
    ACTION_START_REUNION    = 2,
    ACTION_INTRO_DARNASSUS  = 3,
    ACTION_OUTRO_REUNION    = 4,

    EVENT_TALK_SCENE,
    EVENT_SPAWN_SCENE,
    EVENT_DESPAWN_SCENE,

    // Events
    EVENT_TELEPORT,
    EVENT_INTRO_1,
    EVENT_INTRO_2,

    EVENT_REUNION_1,
    EVENT_REUNION_2,
    EVENT_REUNION_3,
    EVENT_REUNION_4,
    EVENT_REUNION_5,
    EVENT_REUNION_6,
    EVENT_REUNION_7,
    EVENT_REUNION_8,
    EVENT_REUNION_9,
    EVENT_REUNION_10,
    EVENT_REUNION_11,
    EVENT_REUNION_12,

    EVENT_DARNASSUS_1,
    EVENT_DARNASSUS_2,
    EVENT_DARNASSUS_3,
    EVENT_DARNASSUS_4,
    EVENT_DARNASSUS_5,
    EVENT_DARNASSUS_6,
    EVENT_DARNASSUS_7,
    EVENT_DARNASSUS_8,

    EVENT_CHECK_SPEED,

    EVENT_OUTRO_REUNION_1,
    EVENT_OUTRO_REUNION_2,
    EVENT_OUTRO_REUNION_3,
    EVENT_OUTRO_REUNION_4,
    EVENT_OUTRO_REUNION_5,
    EVENT_OUTRO_REUNION_6,
    EVENT_OUTRO_REUNION_7,
    EVENT_OUTRO_REUNION_8,
    EVENT_OUTRO_REUNION_9,
    EVENT_OUTRO_REUNION_10
};

enum Phases
{
    PHASE_NONE              = 1,
    PHASE_NOT_STARTED,
    PHASE_STARTED
};

enum Texts
{
    SAY_ANDUIN_0            = 0,
    SAY_JAINA_1             = 0,

    SAY_JAINA_2             = 1,
    SAY_JAINA_3             = 2,
    SAY_JAINA_4             = 3,
    SAY_ANDUIN_5            = 1,
    SAY_JAINA_6             = 4,    // Auto
    SAY_JAINA_7             = 5,    // Auto
    SAY_JAINA_8             = 6,    // Auto
    SAY_JAINA_9             = 7,
    SAY_JAINA_10            = 8,
    SAY_JAINA_11            = 9,    // Auto
    SAY_JAINA_12            = 10,
    SAY_JAINA_13            = 11,   // Auto
    SAY_JAINA_14            = 12,
    SAY_ANDUIN_15           = 2,
    SAY_JAINA_16            = 13,

    SAY_JAINA_DARNASSUS_1   = 14,
    SAY_JAINA_DARNASSUS_2   = 15,
    SAY_JAINA_DARNASSUS_3   = 16,
    SAY_JAINA_DARNASSUS_4   = 17,
    SAY_JAINA_DARNASSUS_5   = 18,
    SAY_JAINA_DARNASSUS_6   = 19,
};

#pragma region SCENES_CONSTANTS

constexpr int INSIDE_PATH_SIZE           = 11;
constexpr int SCENE_KALECGOS_COUNT       = 4;
constexpr int SCENE_KEL_THUZAD_COUNT     = 3;
constexpr int SCENE_KAEL_THAS_COUNT      = 6;
constexpr int SCENE_AETHAS_COUNT         = 4;
constexpr int SCENE_ANTONIDAS_COUNT      = 1;
constexpr int TOTAL_SCENES_COUNT         = 5;
constexpr int TOTAL_TRACKERS_COUNT       = 108;

const Position centerPos = { 5848.36f, 853.19f, 843.21f, 4.10f };

const Position pathInsideJaina[INSIDE_PATH_SIZE] =
{
    { 5848.97f, 830.92f, 846.33f, 1.41f },
    { 5849.97f, 832.90f, 846.33f, 1.67f },
    { 5849.71f, 835.38f, 846.34f, 1.62f },
    { 5849.54f, 837.88f, 846.20f, 1.64f },
    { 5849.27f, 841.62f, 843.84f, 1.64f },
    { 5849.03f, 844.95f, 843.45f, 1.75f },
    { 5848.12f, 847.74f, 843.21f, 2.06f },
    { 5845.63f, 850.74f, 843.21f, 2.48f },
    { 5843.53f, 852.08f, 843.21f, 2.68f },
    { 5840.31f, 853.33f, 843.29f, 2.88f },
    { 5836.37f, 853.11f, 843.72f, 0.00f }
};

const Position pathInsideAnduin[INSIDE_PATH_SIZE] =
{
    { 5850.91f, 831.14f, 846.33f, 1.81f },
    { 5849.97f, 832.90f, 846.33f, 1.67f },
    { 5849.71f, 835.38f, 846.34f, 1.62f },
    { 5849.54f, 837.88f, 846.20f, 1.64f },
    { 5849.27f, 841.62f, 843.84f, 1.64f },
    { 5849.03f, 844.95f, 843.45f, 1.75f },
    { 5848.12f, 847.74f, 843.21f, 2.06f },
    { 5845.63f, 850.74f, 843.21f, 2.48f },
    { 5843.53f, 852.08f, 843.21f, 2.68f },
    { 5840.31f, 853.33f, 843.29f, 2.88f },
    { 5836.55f, 851.01f, 843.72f, 1.55f }
};

struct Scene
{
    public:
    uint8 Type;
    uint32 Entry;
    Emote Emote;
    uint32 Spell;
    const Position Spawn;
    const QuaternionData Rotation;
};

const Scene Kalecgos[SCENE_KALECGOS_COUNT] =
{
    { 1, NPC_JAINA_PROUDMOORE,  EMOTE_STATE_TALK,     0,       { 5849.48f, 855.61f, 843.21f, 4.63f }, QuaternionData::QuaternionData() },
    { 1, NPC_KALEC,             EMOTE_STATE_TALK,     0,       { 5849.49f, 852.97f, 843.21f, 1.50f }, QuaternionData::QuaternionData() },
    { 2, 500007,                EMOTE_ONESHOT_NONE,   0,       { 5852.70f, 853.97f, 843.21f, 3.23f }, { 0.f, 0.f, -0.99f, 0.04f } },
    { 2, 500001,                EMOTE_ONESHOT_NONE,   0,       { 5851.70f, 857.49f, 843.21f, 3.83f }, { 0.f, 0.f, -0.94f, 0.33f } }
};

const Scene Kelthuzad[SCENE_KEL_THUZAD_COUNT] =
{
    { 1, NPC_KEL_THUZAD,        EMOTE_ONESHOT_NONE,   100043,  { 5848.40f, 853.14f, 843.21f, 2.63f }, QuaternionData::QuaternionData() },
    { 1, NPC_WOUNDED_DALARAN,   EMOTE_ONESHOT_NONE,   27965,   { 5846.39f, 852.60f, 843.21f, 4.53f }, QuaternionData::QuaternionData() },
    { 2, 181756,                EMOTE_ONESHOT_NONE,   0,       { 5849.65f, 857.74f, 843.21f, 2.24f }, { 0.f, 0.f, -0.90f, -0.43f } }
};

const Scene Kaelthas[SCENE_KAEL_THAS_COUNT] =
{
    { 1, NPC_KAEL_THAS,         EMOTE_STATE_SPELL_CHANNEL_DIRECTED, 0,      { 5851.68f, 859.24f, 843.22f, 4.18f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5851.73f, 849.30f, 843.21f, 1.71f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5848.67f, 848.25f, 843.21f, 1.35f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5842.58f, 853.39f, 843.21f, 0.70f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5844.27f, 850.18f, 843.21f, 0.70f }, QuaternionData::QuaternionData() },
    { 1, NPC_INVISIBLE_STALKER, EMOTE_STATE_KNEEL,                  71183,  { 5848.36f, 853.19f, 843.21f, 4.10f }, QuaternionData::QuaternionData() }
};

const Scene Aethas[SCENE_AETHAS_COUNT] =
{
    { 1, NPC_AETHAS_SUNREAVER,      EMOTE_ONESHOT_NONE, 0, { 5847.70f, 855.39f, 843.21f, 3.17f }, QuaternionData::QuaternionData() },
    { 1, NPC_SUNREAVER_MAGE,        EMOTE_ONESHOT_NONE, 0, { 5850.47f, 849.40f, 843.21f, 2.76f }, QuaternionData::QuaternionData() },
    { 1, NPC_SUNREAVER_GUARDIAN,    EMOTE_ONESHOT_NONE, 0, { 5848.48f, 848.52f, 843.21f, 2.33f }, QuaternionData::QuaternionData() },
    { 1, NPC_DRAGONHAWK,            EMOTE_ONESHOT_NONE, 0, { 5850.83f, 856.70f, 843.21f, 3.14f }, QuaternionData::QuaternionData() }
};

const Scene Antonidas[SCENE_ANTONIDAS_COUNT]
{
    { 2, GOB_ANTONIDAS_STATUE,      EMOTE_ONESHOT_NONE, 0, { 5848.40f, 853.14f, 843.21f, 2.63f  }, { 0.f, 0.f, -0.99f, 0.f } }
};

const uint8  Sizes[TOTAL_SCENES_COUNT]  = { SCENE_KALECGOS_COUNT, SCENE_KEL_THUZAD_COUNT, SCENE_KAEL_THAS_COUNT, SCENE_AETHAS_COUNT, SCENE_ANTONIDAS_COUNT };
const Scene* Scenes[TOTAL_SCENES_COUNT] = { Kalecgos, Kelthuzad, Kaelthas, Aethas, Antonidas };

const Position MagicTracksPos[TOTAL_TRACKERS_COUNT] =
{
    { 10126.02f, 2579.14f, 1324.95f, 4.88f },
    { 10127.75f, 2572.54f, 1323.80f, 5.33f },
    { 10132.48f, 2565.88f, 1322.61f, 5.30f },
    { 10134.47f, 2559.67f, 1322.09f, 4.95f },
    { 10133.65f, 2551.92f, 1321.84f, 4.51f },
    { 10129.78f, 2544.76f, 1321.81f, 4.16f },
    { 10122.78f, 2540.33f, 1321.75f, 3.63f },
    { 10113.11f, 2539.82f, 1321.03f, 3.23f },
    { 10107.79f, 2539.20f, 1320.32f, 3.38f },
    { 10101.59f, 2534.91f, 1319.52f, 3.99f },
    { 10099.31f, 2528.13f, 1319.57f, 4.54f },
    { 10099.48f, 2520.97f, 1319.41f, 4.87f },
    { 10098.27f, 2509.61f, 1317.57f, 4.67f },
    { 10098.42f, 2506.12f, 1317.56f, 4.74f },
    { 10100.55f, 2496.57f, 1317.55f, 5.14f },
    { 10103.17f, 2491.35f, 1317.60f, 5.07f },
    { 10105.36f, 2480.79f, 1317.57f, 4.77f },
    { 10103.35f, 2471.99f, 1317.26f, 4.36f },
    { 10099.02f, 2464.09f, 1317.68f, 4.04f },
    { 10094.46f, 2458.78f, 1318.09f, 4.02f },
    { 10088.37f, 2453.39f, 1318.11f, 3.71f },
    { 10080.11f, 2449.62f, 1317.82f, 3.53f },
    { 10075.10f, 2448.58f, 1317.38f, 3.32f },
    { 10065.25f, 2444.59f, 1317.72f, 3.68f },
    { 10056.24f, 2439.21f, 1317.82f, 3.65f },
    { 10049.11f, 2435.51f, 1317.51f, 3.88f },
    { 10043.51f, 2431.52f, 1316.37f, 3.25f },
    { 10037.92f, 2429.89f, 1315.42f, 3.87f },
    { 10032.19f, 2425.60f, 1315.99f, 3.53f },
    { 10025.14f, 2420.69f, 1316.34f, 4.05f },
    { 10021.73f, 2410.25f, 1316.86f, 4.70f },
    { 10024.95f, 2399.95f, 1318.01f, 4.78f },
    { 10023.16f, 2392.66f, 1317.99f, 4.84f },
    { 10025.43f, 2386.42f, 1316.36f, 5.10f },
    { 10025.87f, 2380.42f, 1316.64f, 4.57f },
    { 10022.63f, 2372.01f, 1315.79f, 4.12f },
    { 10016.81f, 2365.65f, 1318.03f, 3.72f },
    { 10009.34f, 2359.53f, 1318.01f, 4.23f },
    { 10005.48f, 2353.50f, 1317.05f, 3.91f },
    { 9999.99f, 2345.53f, 1317.07f, 4.34f },
    { 10001.24f, 2341.47f, 1317.68f, 5.63f },
    { 10009.21f, 2329.43f, 1317.56f, 5.05f },
    { 10015.70f, 2318.72f, 1317.86f, 5.55f },
    { 10022.21f, 2314.66f, 1319.02f, 5.81f },
    { 10027.83f, 2309.30f, 1322.55f, 5.42f },
    { 10030.11f, 2306.65f, 1324.40f, 5.42f },
    { 10034.84f, 2301.49f, 1327.53f, 5.48f },
    { 10041.68f, 2292.43f, 1329.58f, 5.13f },
    { 10042.93f, 2284.58f, 1328.78f, 4.60f },
    { 10035.46f, 2269.86f, 1329.89f, 3.93f },
    { 10032.34f, 2265.96f, 1330.13f, 4.24f },
    { 10029.86f, 2256.36f, 1329.45f, 4.74f },
    { 10030.08f, 2250.88f, 1328.55f, 4.66f },
    { 10029.38f, 2243.91f, 1328.54f, 4.55f },
    { 10025.93f, 2234.35f, 1329.08f, 4.06f },
    { 10021.26f, 2229.16f, 1328.80f, 3.84f },
    { 10015.74f, 2225.95f, 1328.93f, 3.51f },
    { 10007.56f, 2223.68f, 1329.99f, 3.29f },
    { 9997.16f, 2222.21f, 1329.36f, 3.27f },
    { 9990.33f, 2220.76f, 1328.77f, 3.46f },
    { 9980.87f, 2217.47f, 1328.79f, 3.69f },
    { 9975.09f, 2213.52f, 1329.31f, 3.74f },
    { 9966.68f, 2205.85f, 1329.06f, 3.95f },
    { 9961.09f, 2198.71f, 1328.17f, 4.29f },
    { 9958.50f, 2189.77f, 1327.85f, 4.59f },
    { 9958.09f, 2183.26f, 1327.63f, 4.57f },
    { 9954.52f, 2173.43f, 1327.45f, 4.29f },
    { 9952.43f, 2168.49f, 1327.45f, 4.40f },
    { 9951.06f, 2160.82f, 1327.49f, 4.70f },
    { 9953.24f, 2150.09f, 1327.72f, 4.95f },
    { 9953.94f, 2139.77f, 1327.64f, 4.52f },
    { 9951.07f, 2129.68f, 1327.66f, 4.40f },
    { 9951.21f, 2117.33f, 1327.64f, 4.98f },
    { 9952.97f, 2110.80f, 1327.69f, 4.89f },
    { 9953.38f, 2107.32f, 1327.72f, 4.80f },
    { 9953.00f, 2100.02f, 1327.74f, 4.49f },
    { 9948.14f, 2092.85f, 1327.83f, 3.89f },
    { 9942.98f, 2086.69f, 1328.16f, 4.13f },
    { 9939.71f, 2078.11f, 1327.84f, 5.09f },
    { 9940.26f, 2065.24f, 1329.54f, 4.85f },
    { 9939.65f, 2057.14f, 1331.51f, 4.19f },
    { 9933.86f, 2048.27f, 1333.82f, 4.02f },
    { 9926.91f, 2039.94f, 1336.57f, 3.95f },
    { 9924.58f, 2037.01f, 1338.31f, 4.17f },
    { 9922.07f, 2027.62f, 1341.94f, 4.44f },
    { 9923.49f, 2018.94f, 1342.99f, 4.99f },
    { 9927.34f, 2010.15f, 1343.21f, 5.29f },
    { 9929.35f, 2005.21f, 1343.46f, 5.07f },
    { 9929.53f, 1993.66f, 1345.21f, 4.49f },
    { 9928.55f, 1986.73f, 1345.00f, 4.62f },
    { 9928.81f, 1981.62f, 1344.53f, 4.82f },
    { 9929.74f, 1972.81f, 1343.08f, 4.72f },
    { 9928.46f, 1962.31f, 1340.40f, 4.76f },
    { 9928.78f, 1955.32f, 1337.24f, 4.73f },
    { 9931.17f, 1946.36f, 1333.96f, 5.11f },
    { 9933.27f, 1939.73f, 1331.74f, 4.77f },
    { 9932.42f, 1933.28f, 1330.61f, 4.47f },
    { 9930.50f, 1924.75f, 1329.66f, 4.39f },
    { 9924.03f, 1915.42f, 1328.22f, 4.05f },
    { 9920.55f, 1910.06f, 1327.38f, 4.33f },
    { 9920.62f, 1903.27f, 1326.70f, 5.09f },
    { 9923.68f, 1895.58f, 1326.60f, 4.92f },
    { 9923.56f, 1891.07f, 1326.21f, 4.35f },
    { 9919.73f, 1885.09f, 1324.56f, 3.61f },
    { 9916.19f, 1878.50f, 1322.66f, 4.66f },
    { 9908.96f, 1867.44f, 1320.71f, 3.76f },
    { 9899.47f, 1866.62f, 1319.49f, 3.16f },
    { 9892.66f, 1865.71f, 1318.80f, 3.32f }
};

#pragma endregion

class JainaArrivesEvent : public BasicEvent
{
public:
    JainaArrivesEvent(Creature* owner, Player* player) : owner(owner), stage(0), player(player) { }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        switch (stage)
        {
            case 0:
                owner->AI()->Talk(SAY_JAINA_DARNASSUS_1);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 3000);
                return false;
            case 1:
                owner->SetFacingToObject(player);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 2000);
                return false;
            case 2:
                owner->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                return true;
            default:
                break;
        }
        return true;
    }

private:
    Creature* owner;
    Player* player;
    uint8 stage;
};

class AnduinLeavesEvent : public BasicEvent
{
public:
    AnduinLeavesEvent(Creature* owner, Player* player, GameObject* portal) : owner(owner), stage(0), player(player), portal(portal)
    {
        owner->SetWalk(true);
        owner->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        switch (stage)
        {
            case 0:
                owner->GetMotionMaster()->MovePoint(0, portal->GetPosition());
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 9000);
                return false;
            case 1:
                owner->CastSpell(owner, SPELL_TELEPORT);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 2000);
                return false;
            case 2:
                owner->SetVisible(false);
                player->SetPhaseMask(1, true);
                portal->SetPhaseMask(1, true);
                stage++;
                owner->m_Events.AddEvent(this, eventTime + 1000);
                return false;
            case 3:
                portal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                break;
            default:
                break;
        }
        return true;
    }

private:
    Creature* owner;
    Player* player;
    uint8 stage;
    GameObject* portal;
};

class dalaran_jaina_anduin : public CreatureScript
{
    public:
    dalaran_jaina_anduin() : CreatureScript("dalaran_jaina_anduin") {}

    struct dalaran_jaina_anduinAI : public ScriptedAI
    {
        dalaran_jaina_anduinAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            sceneIndex = 0;
            magicTracks = 0;
            talkIndex = SAY_JAINA_6;
            player = nullptr;
            anduin = nullptr;
            phase = PHASE_NONE;
        }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
            {
                player->PrepareQuestMenu(me->GetGUID());
                SendGossipMenuFor(player, 100002, me->GetGUID());
                return true;
            }

            if (player->GetQuestStatus(QUEST_THE_FATE_OF_DALARAN) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, 57022, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 100001, me->GetGUID());
                return true;
            }

            SendGossipMenuFor(player, 100000, me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    SetData(ACTION_START_REUNION, 1U);
                    break;
            }

            CloseGossipMenuFor(player);
            return true;
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_TRACKING_THE_THIEVES:
                    SetData(ACTION_INTRO_DARNASSUS, 0);
                    break;

                case QUEST_JAINAS_RESOLUTION:
                    if (portal)
                        portal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    player->SetPhaseMask(16, true);
                    break;
            }
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case ACTION_INTRO_TELEPORT:
                    anduin = GetClosestCreatureWithEntry(me, NPC_ANDUIN_WRYNN, 10.f);
                    if (!player) player = me->SelectNearestPlayer(50.f);
                    anduin->AI()->Talk(SAY_ANDUIN_0);
                    events.ScheduleEvent(EVENT_INTRO_1,  5s);
                    events.ScheduleEvent(EVENT_TELEPORT, 5ms);
                    break;

                case ACTION_START_REUNION:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    anduin->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    anduin->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    phase = PHASE_STARTED;
                    events.CancelEvent(EVENT_TELEPORT);
                    events.ScheduleEvent(EVENT_REUNION_1, 2s);
                    break;

                case ACTION_INTRO_DARNASSUS:
                    if (!player) player = me->SelectNearestPlayer(50.f);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    phase = PHASE_STARTED;
                    events.ScheduleEvent(EVENT_DARNASSUS_1, 1s);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || phase != PHASE_NONE)
                return;

            player = who->ToPlayer();
            if (player->IsGameMaster())
                return;

            switch (me->GetMapId())
            {
                case MAP_DALARAN_INSTANCED:
                {
                    if (player->GetPhaseMask() == PHASEMASK_DALARAN && me->IsFriendlyTo(player) && me->IsWithinDist(player, 6.f, false))
                    {
                        phase = PHASE_NOT_STARTED;
                        SetData(ACTION_INTRO_TELEPORT, 1U);
                    }
                    break;
                }

                case MAP_KALIMDOR:
                {
                    if (player->GetPhaseMask() == PHASEMASK_DARNASSUS && me->IsFriendlyTo(player) && me->IsWithinDist(player, 30.f))
                    {
                        phase = PHASE_NOT_STARTED;
                        me->PlayDirectMusic(SOUND_JAINA_DARNA_MUSIC);
                        me->m_Events.AddEvent(new JainaArrivesEvent(me, player), me->m_Events.CalculateTime(3000));
                    }
                    break;
                }
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            if (me->GetMapId() == MAP_KALIMDOR)
            {
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Event : TELEPORT
                    #pragma region TELEPORT

                    case EVENT_INTRO_1:
                        Talk(SAY_JAINA_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 4s);
                        break;

                    case EVENT_INTRO_2:
                        anduin->SetFacingToObject(player ? player->ToUnit() : me);
                        anduin->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFacingToObject(player ? player->ToUnit() : anduin);
                        break;

                    case EVENT_TELEPORT:
                    {
                        if (!player)
                            player = me->SelectNearestPlayer(10.f);

                        if (player && player->GetPositionZ() < 840.f)
                        {
                            me->CastSpell(me, SPELL_TELEPORT_ANIM, true);
                            me->CastSpell(player, SPELL_TELEPORT_EFFECT);
                        }

                        events.RescheduleEvent(EVENT_TELEPORT, 5ms);
                        break;
                    }

                    #pragma endregion

                    // Event : REUNION
                    #pragma region REUNION

                    case EVENT_REUNION_1:
                        center = me->SummonCreature(NPC_INVISIBLE_STALKER, centerPos, TEMPSUMMON_MANUAL_DESPAWN);
                        center->SetObjectScale(5.6f);
                        Talk(SAY_JAINA_2);
                        events.ScheduleEvent(EVENT_REUNION_2, 6s);
                        break;

                    case EVENT_REUNION_2:
                        Talk(SAY_JAINA_3);
                        me->GetMotionMaster()->MoveSmoothPath(0, pathInsideJaina, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_3, 3s);
                        break;

                    case EVENT_REUNION_3:
                        anduin->GetMotionMaster()->MoveSmoothPath(0, pathInsideAnduin, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_4, 3s);
                        break;

                    case EVENT_REUNION_4:
                        Talk(SAY_JAINA_4);
                        events.ScheduleEvent(EVENT_REUNION_5, 10s);
                        break;

                    case EVENT_REUNION_5:
                        anduin->AI()->Talk(SAY_ANDUIN_5);
                        me->SetFacingToObject(anduin);
                        anduin->SetFacingToObject(me);
                        events.ScheduleEvent(EVENT_REUNION_6, 1s);
                        break;

                    case EVENT_REUNION_6:
                        me->PlayDirectMusic(SOUND_REUNION_MUSIC);
                        center->AddAura(SPELL_SPOT_SCALED, center);
                        player->AddAura(SPELL_REMEMBER_SHADOW, player);
                        me->SetFacingToObject(center);
                        anduin->SetFacingToObject(center);
                        events.ScheduleEvent(EVENT_TALK_SCENE, 60ms);
                        break;

                    case EVENT_REUNION_7:
                        Talk(SAY_JAINA_9);
                        player->RemoveAurasDueToSpell(SPELL_REMEMBER_SHADOW);
                        events.ScheduleEvent(EVENT_REUNION_8, 5s);
                        break;

                    case EVENT_REUNION_8:
                        Talk(SAY_JAINA_10);
                        talkIndex = SAY_JAINA_11;
                        events.ScheduleEvent(EVENT_TALK_SCENE, 6s);
                        break;

                    case EVENT_REUNION_9:
                        Talk(SAY_JAINA_12);
                        talkIndex = SAY_JAINA_13;
                        events.ScheduleEvent(EVENT_TALK_SCENE, 6s);
                        break;

                    case EVENT_REUNION_10:
                        Talk(SAY_JAINA_14);
                        events.ScheduleEvent(EVENT_REUNION_11, 6s);
                        break;

                    case EVENT_REUNION_11:
                        anduin->AI()->Talk(SAY_ANDUIN_15);
                        events.ScheduleEvent(EVENT_REUNION_12, 3s);
                        break;

                    case EVENT_REUNION_12:
                        Talk(SAY_JAINA_16);
                        player->CompleteQuest(QUEST_THE_FATE_OF_DALARAN);
                        anduin->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;

                    // Events : SCENES

                    case EVENT_TALK_SCENE:
                        Talk(talkIndex++);
                        events.ScheduleEvent(EVENT_SPAWN_SCENE, 2s);
                        break;

                    case EVENT_SPAWN_SCENE:
                        SummonScene();
                        SummonSceneAddon();
                        events.ScheduleEvent(EVENT_DESPAWN_SCENE, 8s);
                        break;

                    case EVENT_DESPAWN_SCENE:
                        DespawnScene();
                        sceneIndex++;
                        switch (sceneIndex)
                        {
                            // Kalecgos, Kel'thuzad, Kael'thas
                            case 3:
                                events.ScheduleEvent(EVENT_REUNION_7, 3s);
                                break;

                            // Sunreavers
                            case 4:
                                events.ScheduleEvent(EVENT_REUNION_9, 3s);
                                break;

                            // Antonidas
                            case 5:
                                center->DespawnOrUnsummon();
                                events.ScheduleEvent(EVENT_REUNION_10, 3s);
                                break;

                            default:
                                events.ScheduleEvent(EVENT_TALK_SCENE, 2s);
                                break;
                        }
                        break;

                    #pragma endregion

                    // Event : Darnassus
                    #pragma region DARNASSUS

                    case EVENT_DARNASSUS_1:
                        me->SetFacingTo(4.41f);
                        events.ScheduleEvent(EVENT_DARNASSUS_2, 2s);
                        break;

                    case EVENT_DARNASSUS_2:
                        DoCast(SPELL_DETECT_MAGIC);
                        events.ScheduleEvent(EVENT_DARNASSUS_3, 5ms);
                        events.ScheduleEvent(EVENT_DARNASSUS_4, 1s);
                        break;

                    case EVENT_DARNASSUS_3:
                        if (Creature * track = me->SummonCreature(NPC_INVISIBLE_STALKER, MagicTracksPos[magicTracks], TEMPSUMMON_MANUAL_DESPAWN))
                            track->CastSpell(track, SPELL_MAGIC_TRACKS);
                        magicTracks++;
                        if (magicTracks >= TOTAL_TRACKERS_COUNT)
                            events.CancelEvent(EVENT_DARNASSUS_3);
                        else
                            events.RescheduleEvent(EVENT_DARNASSUS_3, 1ms);
                        break;

                    case EVENT_DARNASSUS_4:
                        me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_DIST);
                        events.ScheduleEvent(EVENT_DARNASSUS_5, 20s);
                        events.ScheduleEvent(EVENT_DARNASSUS_6, 50s);
                        events.ScheduleEvent(EVENT_CHECK_SPEED, 1s);
                        break;

                    case EVENT_DARNASSUS_5:
                        Talk(SAY_JAINA_DARNASSUS_2);
                        break;

                    case EVENT_DARNASSUS_6:
                        Talk(SAY_JAINA_DARNASSUS_3);
                        break;

                    case EVENT_DARNASSUS_7:
                        Talk(SAY_JAINA_DARNASSUS_5);
                        me->SetFacingToObject(player);
                        player->CompleteQuest(QUEST_TRACKING_THE_THIEVES);
                        events.ScheduleEvent(EVENT_DARNASSUS_8, 9s);
                        break;

                    case EVENT_DARNASSUS_8:
                        Talk(SAY_JAINA_DARNASSUS_6);
                        me->SetFacingToObject(player);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;

                    case EVENT_CHECK_SPEED:
                    {
                        if (portal = GetClosestGameObjectWithEntry(me, GOB_PORTAL_TO_DALARAN, 30.f))
                        {
                            portal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            me->Dismount();
                            me->SetSpeedRate(MOVE_RUN, 1);
                            me->GetMotionMaster()->Clear();

                            Talk(SAY_JAINA_DARNASSUS_4);

                            float distanceToTravel = me->GetExactDist2d(portal->GetPosition()) - 3.f;
                            float angle = me->GetAbsoluteAngle(portal);
                            float destx = me->GetPositionX() + distanceToTravel * cosf(angle);
                            float desty = me->GetPositionY() + distanceToTravel * sinf(angle);
                            float time = (distanceToTravel / me->GetSpeed(MOVE_RUN)) * IN_MILLISECONDS;
                            me->GetMotionMaster()->MovePoint(0, destx, desty, portal->GetPositionZ(), true, 5.51f);

                            events.CancelEvent(EVENT_CHECK_SPEED);
                            events.ScheduleEvent(EVENT_DARNASSUS_7, time + 500);

                            break;
                        }

                        UpdateSpeed();

                        events.RescheduleEvent(EVENT_CHECK_SPEED, 1s);
                        break;
                    }

                    #pragma endregion

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Creature* anduin;
        Creature* center;
        GameObject* portal;
        GuidList guids;
        Phases phase;
        Player* player;
        float startOrientation;
        int sceneIndex;
        int talkIndex;
        int magicTracks;

        void SummonScene()
        {
            DoCast(SPELL_REMEMBER_SUMMON);

            guids.clear();

            ObjectGuid guid = ObjectGuid::Empty;

            for (int i = 0; i < Sizes[sceneIndex]; ++i)
            {
                switch (Scenes[sceneIndex][i].Type)
                {
                    case 1:
                    {
                        Unit* c = me->SummonCreature(Scenes[sceneIndex][i].Entry, Scenes[sceneIndex][i].Spawn, TEMPSUMMON_MANUAL_DESPAWN);
                        c->AddAura(SPELL_ALPHA_75_PCT, c);
                        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        c->SetSheath(SHEATH_STATE_UNARMED);
                        c->SetFaction(35);

                        if (Scenes[sceneIndex][i].Spell)
                            c->CastSpell(c, Scenes[sceneIndex][i].Spell);

                        switch (Scenes[sceneIndex][i].Emote)
                        {
                            case EMOTE_ONESHOT_NONE:
                                break;

                            case EMOTE_STATE_KNEEL:
                                c->SetStandState(UNIT_STAND_STATE_KNEEL);
                                break;

                            default:
                                c->SetUInt32Value(UNIT_NPC_EMOTESTATE, Scenes[sceneIndex][i].Emote);
                                break;
                        }

                        guid = c->GetGUID();
                        break;
                    }

                    case 2:
                    {
                        GameObject* o = me->SummonGameObject(Scenes[sceneIndex][i].Entry, Scenes[sceneIndex][i].Spawn, Scenes[sceneIndex][i].Rotation, 0);
                        o->EnableCollision(false);
                        guid = o->GetGUID();
                        break;
                    }
                }

                guids.push_back(guid);
            }
        }

        void SummonSceneAddon()
        {
            if (Creature * temp = GetCreatureInScene(NPC_KAEL_THAS))
            {
                temp->SetWalk(true);
                temp->GetMotionMaster()->MovePoint(0, 5849.86f, 856.02f, 843.21f);
            }

            if (Creature * temp = GetCreatureInScene(NPC_KEL_THUZAD))
            {
                for (int i = 0; i < 8; ++i)
                {
                    float angle = float(rand_norm() * 2 * M_PI);
                    float dist = frand(1, 5);
                    const Position pos = { temp->GetPositionX() + cos(angle) * dist, temp->GetPositionY() + sin(angle) * dist, temp->GetPositionZ(), angle };
                    if (Creature * ghoul = temp->SummonCreature(NPC_GHOUL, pos, TEMPSUMMON_TIMED_DESPAWN, 8s))
                    {
                        ghoul->AddAura(SPELL_ALPHA_75_PCT, ghoul);
                        ghoul->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        ghoul->SetSheath(SHEATH_STATE_UNARMED);
                        ghoul->SetFaction(35);
                    }
                }
            }

            if (GameObject * temp = GetGameObjectInScene(GOB_ANTONIDAS_STATUE))
                center->SetObjectScale(2);
        }

        Creature* GetCreatureInScene(uint32 entry)
        {
            for (ObjectGuid guid : guids)
            {
                if (WorldObject * o = ObjectAccessor::GetWorldObject(*me, guid))
                {
                    switch (o->GetTypeId())
                    {
                        case TYPEID_UNIT:
                        {
                            if (Creature * temp = o->ToCreature())
                            {
                                if (temp->GetEntry() == entry)
                                {
                                    return temp;
                                }
                            }
                        }
                    }
                }
            }

            return nullptr;
        }
        GameObject* GetGameObjectInScene(uint32 entry)
        {
            for (ObjectGuid guid : guids)
            {
                if (WorldObject * o = ObjectAccessor::GetWorldObject(*me, guid))
                {
                    switch (o->GetTypeId())
                    {
                        case TYPEID_GAMEOBJECT:
                        {
                            if (GameObject * temp = o->ToGameObject())
                            {
                                if (temp->GetEntry() == entry)
                                {
                                    return temp;
                                }
                            }
                        }
                    }
                }
            }

            return nullptr;
        }

        void DespawnScene()
        {
            me->RemoveAurasDueToSpell(SPELL_REMEMBER_SUMMON);
            for (ObjectGuid guid : guids)
            {
                WorldObject* o = ObjectAccessor::GetWorldObject(*me, guid);
                if (!o)
                    continue;

                switch (o->GetTypeId())
                {
                    case TYPEID_UNIT:
                        o->ToCreature()->DespawnOrUnsummon();
                        break;

                    case TYPEID_GAMEOBJECT:
                        o->ToGameObject()->Delete();
                        break;
                }
            }
        }

        void UpdateSpeed()
        {
            if (player->IsMounted())
                me->Mount(MOUNT_WHITE_STEED);
            else
                me->Dismount();

            me->SetSpeed(MOVE_RUN, player->GetSpeed(MOVE_RUN));
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new dalaran_jaina_anduinAI(creature);
    }
};

class dalaran_anduin_wrynn : public CreatureScript
{
    public:
    dalaran_anduin_wrynn() : CreatureScript("dalaran_anduin_wrynn") {}

    struct dalaran_anduin_wrynnAI : public ScriptedAI
    {
        dalaran_anduin_wrynnAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {

        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_DARNASSUS_ATTACKED:
                    player->SetPhaseMask(PHASEMASK_DARNASSUS, true);
                    break;
            }
        }

        void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_THE_FATE_OF_DALARAN:
                    SendMailToPlayer(player);
                    if (GameObject* portal = me->SummonGameObject(190960, 5858.08f, 858.45f, 843.80f, 3.64f, QuaternionData(), 0))
                    {
                        portal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        me->m_Events.AddEvent(new AnduinLeavesEvent(me, player, portal), me->m_Events.CalculateTime(3000));
                    }
                    break;
            }
        }

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void SendMailToPlayer(Player* player) const
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            int16 deliverDelay = irand(MAIL_DELIVER_DELAY_MIN, MAIL_DELIVER_DELAY_MAX);
            MailDraft(MAIL_DARNASSUS_ENTRY, true).SendMailTo(trans, MailReceiver(player), MailSender(MAIL_CREATURE, me->GetEntry()), MAIL_CHECK_MASK_NONE, deliverDelay);
            CharacterDatabase.CommitTransaction(trans);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new dalaran_anduin_wrynnAI(creature);
    }
};

void AddSC_dalaran_jaina_anduin()
{
    new dalaran_jaina_anduin();
    new dalaran_anduin_wrynn();
}
