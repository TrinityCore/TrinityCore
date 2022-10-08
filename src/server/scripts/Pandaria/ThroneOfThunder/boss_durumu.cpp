#include "GameObject.h"
#include "SpellAuraEffects.h"
#include "SpellAuraDefines.h"
#include "throne_of_thunder.h"

Position PlatformCenter = { 5895.829f,  4512.626f, -6.276f, 6.242f };

// clockwise
static const Position YellowEyeWay[8] =
{
    { 5833.541f,  4523.083f, -6.277f, 1.873f },
    { 5859.474f,  4563.136f, -6.277f, 1.873f },
    { 5905.615f,  4573.638f, -6.277f, 1.873f },
    { 5945.436f,  4548.107f, -6.277f, 1.873f },
    { 5955.923f,  4502.487f, -6.277f, 1.873f }, 
    { 5930.874f,  4463.088f, -6.277f, 1.873f },
    { 5886.584f,  4452.482f, -6.277f, 1.873f },
    { 5845.496f,  4476.399f, -6.277f, 1.873f },
};

// counter clockwise
static const Position YellowEyeWay2[8] =
{
    { 5845.496f,  4476.399f, -6.277f, 1.873f },
    { 5886.584f,  4452.482f, -6.277f, 1.873f },
    { 5930.874f,  4463.088f, -6.277f, 1.873f },
    { 5955.923f,  4502.487f, -6.277f, 1.873f },
    { 5945.436f,  4548.107f, -6.277f, 1.873f },
    { 5905.615f,  4573.638f, -6.277f, 1.873f },
    { 5859.474f,  4563.136f, -6.277f, 1.873f },
    { 5833.541f,  4523.083f, -6.277f, 1.873f },
};

Position WallsofIce1[5] =
{
    { 5940.07f, 4484.06f, -3.87f, 2.53f }, // x5925.18"	y"4493.79"	z"-6.27763"	o"5.61419 rotation2 0.328294 rotation3 -0.944576
    { 5927.63f, 4490.19f, -6.27f, 2.48f },
    { 5923.44f, 4498.62f, -6.27f, 2.54f },
    { 5911.40f, 4503.76f, -6.27f, 2.45f },
    { 5907.17f, 4508.19f, -6.27f, 2.58f },
};

Position WallsofIce2[4] =
{
    { 5885.82f, 4512.41f, -6.27f, 3.26f }, // x5862.33"	y"4508.2"	z"-6.27703"	o"3.28283 rotation2 0.997507 rotation3 -0.0705623
    { 5870.28f, 4510.39f, -6.27f, 3.30f },
    { 5856.52f, 4506.37f, -6.27f, 0.16f },
    { 5845.16f, 4505.20f, -6.27f, 0.19f },
};

Position WallsofIce3[4] =
{
    { 5910.73f, 4568.82f, -6.27f, 1.02f }, //  x5903.09, y4547.13, z-6.27707, o1.28039  rotation2 0.597351, rotation3 0.80198
    { 5903.07f, 4549.19f, -6.27f, 1.31f },
    { 5901.82f, 4538.36f, -6.27f, 4.53f }, //orientation
    { 5898.68f, 4523.55f, -6.27f, 1.31f },
};

enum WallsofIceObject
{
    GO_WALL_OF_ICE = 221422,
    GO_WALL_OF_ICE_1 = 999235,
    GO_WALL_OF_ICE_2 = 999236,
};

Position CriomsonFogs[3] =
{
    { 5874.76f, 4465.76f, -6.27f, 1.12f },
    { 5945.27f, 4512.17f, -6.27f, 3.11f },
    { 5914.87f, 4559.68f, -6.27f, 4.32f },
};

Position AzureFogs[3] =
{
    { 5946.81f, 4499.13f, -6.27f, 2.93f },
    { 5849.98f, 4531.87f, -6.27f, 5.91f },
    { 5879.26f, 4464.22f, -6.27f, 1.14f },
};

Position AmberFogs[2] =
{
    { 5869.07f, 4562.25f, -6.27f, 5.16f },
    { 5929.27f, 4474.55f, -6.27f, 2.45f },
};

Position firstPlatformMaze[27] =
{
    { 5948.27f, 4486.34f, -6.27782f, 2.75145f },
    { 5944.89f, 4479.75f, -6.27782f, 2.46085f },
    { 5951.67f, 4493.98f, -6.27782f, 2.74359f },
    { 5939.84f, 4474.75f, -6.27782f, 2.35089f },
    { 5934.88f, 4469.91f, -6.27782f, 2.28806f },
    { 5928.42f, 4464.68f, -6.27782f, 2.13098f },
    { 5921.72f, 4461.66f, -6.27782f, 1.95034f },
    { 5912.68f, 4458.06f, -6.27782f, 1.95034f },
    { 5940.51f, 4497.75f, -6.27782f, 4.35601f },
    { 5938.19f, 4491.52f, -6.27782f, 4.24606f },
    { 5934.97f, 4486.21f, -6.27782f, 4.04971f },
    { 5930.6f,  4481.15f, -6.27782f, 3.99474f },
    { 5926.2f,  4476.54f, -6.27782f, 3.93583f },
    { 5921.33f, 4472.27f, -6.27782f, 3.64916f },
    { 5914.34f, 4469.15f, -6.27782f, 3.50779f },
    { 5908.62f, 4466.88f, -6.27782f, 3.46067f },
    { 5930.55f, 4503.24f, -6.27723f, 4.29456f },
    { 5925.66f, 4496.61f, -6.27723f, 5.83394f },
    { 5920.11f, 4489.32f, -6.27723f, 5.67687f },
    { 5913.77f, 4484.01f, -6.27723f, 5.27632f },
    { 5906.75f, 4481.3f,  -6.27723f, 5.07998f },
    { 5900.2f,  4478.56f, -6.27723f, 5.06427f },
    { 5923.57f, 4505.54f, -6.27713f, 4.33386f },
    { 5919.4f,  4498.78f, -6.27713f, 3.99223f },
    { 5915.01f, 4493.54f, -6.27713f, 3.83907f },
    { 5908.83f, 4489.92f, -6.27713f, 3.57204f },
    { 5901.25f, 4487.07f, -6.27713f, 3.3482f },
};

Position secondPlatformMaze[17] =
{
    { 5905.89f, 4485.5f,  -6.27622f, 3.30895f },
    { 5896.51f, 4483.75f, -6.27622f, 0.0416808f },
    { 5887.8f,  4485.03f, -6.27622f, 6.15601f, },
    { 5878.75f, 4488.54f, -6.27622f, 5.66122f },
    { 5872.19f, 4494.12f, -6.27622f, 5.44916f },
    { 5904.18f, 4470.85f, -6.2768f,  0.234899f },
    { 5895.62f, 4470.25f, -6.2768f,  0.0228417f, },
    { 5887.09f, 4470.59f, -6.2768f,  6.07827f },
    { 5878.38f, 4473.12f, -6.2768f,  5.87014f, },
    { 5870.03f, 4477.61f, -6.2768f,  5.55206f },
    { 5862.55f, 4484.47f, -6.2768f,  5.40677f, },
    { 5853.93f, 4475.85f, -6.27748f, 0.631524f },
    { 5860.7f,  4468.19f, -6.27748f, 0.835728f },
    { 5870.33f, 4462.01f, -6.27748f, 1.036f },
    { 5879.51f, 4457.67f, -6.27748f, 1.1656f },
    { 5889.9f,  4455.25f, -6.27748f, 1.46405f },
    { 5900.03f, 4454.99f, -6.27748f, 1.59756f },
};

Position thirdPlatformMaze[19] =
{
    { 5867.94f, 4497.45f, -6.27642f, 5.11861f },
    { 5865.8f,  4509.83f, -6.27642f, 4.93012f },
    { 5866.84f, 4519.44f, -6.27642f, 4.48245f },
    { 5870.96f, 4528.12f, -6.27642f, 4.20364f },
    { 5876.89f, 4535.47f, -6.27642f, 3.92483f },
    { 5861.1f,  4491.03f, -6.27642f, 5.17819f },
    { 5858.3f,  4499.43f, -6.27642f, 4.71874f },
    { 5856.68f, 4508.77f, -6.27642f, 4.78551f },
    { 5856.91f, 4516.89f, -6.27642f, 4.60094f },
    { 5858.95f, 4525.15f, -6.27642f, 4.33391f },
    { 5862.61f, 4532.59f, -6.27642f, 4.21218f },
    { 5869.22f, 4541.13f, -6.27642f, 3.92944f },
    { 5859.0f,  4551.14f, -6.27642f, 5.48452f },
    { 5850.37f, 4541.51f, -6.27642f, 5.61018f },
    { 5845.19f, 4532.4f,  -6.27642f, 5.8026f },
    { 5841.43f, 4522.34f, -6.27642f, 5.94397f },
    { 5840.26f, 4512.19f, -6.27642f, 6.25419f },
    { 5841.1f,  4500.92f, -6.27642f, 0.198772f },
    { 5843.49f, 4489.4f,  -6.27642f, 0.308728f },
};

Position fourthPlatformMaze[31] =
{
    { 5902.64f, 4541.51f, -6.27684f, 2.99415f },
    { 5911.51f, 4537.12f, -6.27684f, 2.51898f },
    { 5918.19f, 4530.55f, -6.27684f, 2.25588f },
    { 5923.9f,  4521.01f, -6.27684f, 1.9535f },
    { 5923.82f, 4511.55f, -6.27684f, 1.66687f },
    { 5933.65f, 4511.61f, -6.27718f, 4.61212f },
    { 5932.67f, 4522.16f, -6.27718f, 4.87129f },
    { 5929.93f, 4530.77f, -6.27718f, 5.04015f },
    { 5924.87f, 4540.22f, -6.27718f, 5.39357f },
    { 5915.5f,  4546.92f, -6.27718f, 5.75877f },
    { 5904.92f, 4551.38f, -6.27718f, 5.97868f },
    { 5895.25f, 4552.75f, -6.27718f, 6.1711f },
    { 5885.9f,  4552.35f, -6.27718f, 0.0881835f },
    { 5876.24f, 4549.81f, -6.27718f, 0.390562f },
    { 5948.08f, 4514.54f, -6.27771f, 3.18266f },
    { 5946.25f, 4527.19f, -6.27771f, 3.36723f },
    { 5943.26f, 4536.69f, -6.27771f, 3.54787f },
    { 5937.69f, 4546.74f, -6.27771f, 3.74029f },
    { 5931.45f, 4554.32f, -6.27771f, 3.9013f },
    { 5923.56f, 4561.15f, -6.27771f, 4.10157f },
    { 5913.1f,  4566.27f, -6.27771f, 4.24687f },
    { 5902.76f, 4569.54f, -6.27771f, 4.54925f },
    { 5891.02f, 4570.13f, -6.27771f, 4.67883f },
    { 5880.83f, 4568.94f, -6.27771f, 4.9615f },
    { 5869.91f, 4565.3f,  -6.27771f, 5.07152f },
    { 5891.34f, 4541.86f, -6.27684f, 3.44968f },
    { 5882.23f, 4539.21f, -6.27684f, 3.65388f },
    { 5921.81f, 4502.19f, -6.27782f, 4.35919f },
    { 5928.02f, 4499.76f, -6.27782f, 2.71377f },
    { 5940.07f, 4494.8f,  -6.27782f, 2.73734f },
    { 5948.34f, 4491.19f, -6.27782f, 2.74912f },
};

static const Position SternPattern[4] =
{
    { 5846.17f, 4511.81f, -6.27f, 6.27f },
    { 5946.34f, 4511.34f, -6.27f, 3.09f },
    { 5895.18f, 4467.46f, -6.27f, 1.55f },
    { 5896.57f, 4554.89f, -6.27f, 4.64f },
};

enum Spells
{
    SPELL_HARD_STARE = 133765,
    SPELL_GAZE = 134029,
    SPELL_FORCE_OF_WILL = 136932,
    SPELL_FORCE_OF_WILL_KNOCKBACK = 136413,
    SPELL_LINGERING_GAZE_CAST = 138467,
    SPELL_LINGERING_GAZE_MARKER = 134626,
    SPELL_LINGERING_GAZE_DMG = 133792,
    SPELL_BERSERK_KILLALL = 137747,
    SPELL_DRAIN_LIFE_STUN = 137727,
    SPELL_DRAIN_LIFE_CHANNEL = 133795,
    SPELL_DRAIN_LIFE_DAMAGE = 133798,
    SPELL_DRAIN_LIFE_HEAL = 133807,
    SPELL_DESINTEGRATION_BEAM = 133776,
    SPELL_DESINTEGRATION_BEAM_PRECAST = 134169,
    SPELL_MIND_DAGGERS = 139108,

    // Beams
    SPELL_YELLOW_BEAM = 133740,
    SPELL_RED_BEAM = 133734,
    SPELL_BLUE_BEAM = 133672,
    SPELL_YELLOW_BEAM_DMG = 133738,
    SPELL_RED_BEAM_DMG = 133732,
    SPELL_BLUE_BEAM_DMG = 133677,
    SPELL_YELLOW_BEAM_DMG_TO_ALL = 133739,
    SPELL_RED_BEAM_DMG_TO_ALL = 133733,
    SPELL_BLUE_BEAM_DMG_TO_ALL = 133678,

    SPELL_FOG_INVISIBLE = 137092,

    SPELL_CAUSTIC_SPIKE = 136154,
    SPELL_ICY_GRASP = 136177,
    SPELL_CRIMSON_BLOOM = 136122,
    SPELL_FLASH_FREEZE = 136124,
    SPELL_AMBER_RETALIATION = 136175,
    SPELL_BURST_OF_AMBER = 136123,

    // hc spells
    SPELL_DEVOUR_PERIODIC = 134010,
    SPELL_DEVOUR_SHARED_HP = 134005,
    SPELL_DARK_PLAGUE = 133598,
    SPELL_DARK_PARASITE = 133597,

    SPELL_VOID_LINGERING_GAZE = 134040,
    SPELL_ICE_WALL = 134576, // .mod scale 0.4 for correct size

    SPELL_STERN_GAZE = 136618, // channel speLL
    SPELL_STERN_GAZE_DAMAGE = 136616,

    SPELL_MAZE_VIZUAL = 142155,
    SPELL_EYE_SORES = 134755,

    // fogs colors
    SPELL_RED_FOG = 136128,
    SPELL_BLUE_FOG = 136130,
    SPELL_YELLOW_FOG = 136129,

    // colorblind pre-cast spells
    SPELL_RED_PREBLIND = 134123,
    SPELL_BLUE_PREBLIND = 134122,
    SPELL_YELLOW_PREBLIND = 134124,
};

enum NpcEntry
{
    // Beam phase eyes
    YELLOW_EYE = 67856, // for yellow beam
    BLUE_EYE = 67854, // for blue beam
    RED_EYE = 67855, // for red beam
    YELLOW_EYE_MOVER = 67829, // yellow eye not work with player, just with invisible

    // Durumu eyes
    MIND_EYE = 67875,
    HUNGRY_EYE = 67859,
    APPRAYISYING_EYE = 67858,
    EVIL_EYE = 67860,
    STERN_EYE = 69280,
    CROSS_EYE = 67857,
    WANDERING_EYE = 68024,

    // fogs
    CRIMSON_FOG = 69050,
    AZURE_FOG = 69052,
    AMBER_FOG = 69051,

    BOSS_DURUMU = 68036,

    // custom ais
    NPC_VOID_ZONE_LINGERING_GAZE = 999249,
    NPC_WALL_OF_ICE_1 = 999250,
    NPC_WALL_OF_ICE_2 = 999251,
    NPC_WALL_OF_ICE_3 = 999252,

    NPC_MAZE_PERIODIC = 999256,
    NPC_MAZE_BEAM = 999257,

    NPC_SAFESPOT_1 = 999259,
    NPC_SAFESPOT_2 = 999260,
    NPC_SAFESPOT_3 = 999261,
    NPC_SAFESPOT_4 = 999265,
    NPC_SAFESPOT_5 = 999263,
    NPC_SAFESPOT_6 = 999266,
    NPC_SAFESPOT_7 = 999264,
};

enum Events
{
    // Durumu
    EVENT_HARD_STARE = 1,
    EVENT_GAZE,
    EVENT_BERSERK,
    EVENT_LIGHT_SPECTRUM_SAY_SUMMON,
    EVENT_LIGHT_SPECTRUM,
    EVENT_MAZE_TIME,
    EVENT_MAZE_ORIENTATION,
    EVENT_MAZE_END,
    EVENT_MIND_DAGGERS,
    EVENT_LINGERING_TRIGGERED,
    EVENT_LINGERING_MARKER,
    EVENT_WALLS_OF_ICE,

    // Eyes
    EVENT_FORCE_OF_WILL,
    EVENT_LINGERING_GAZE,
    EVENT_DRAIN_LIFE,
    EVENT_DRAIN_LIFE_TAR_CHECK,
    EVENT_EYES_ORIENTATION,
    EVENT_START_DEVOUR,
    EVENT_DEVOUR,
    // summon eyes
    EVENT_SUMMON_APPRAISIING_EYE,
    EVENT_SUMMON_EVIL_EYE,
    EVENT_SUMMON_HUNGRY_EYE,
    EVENT_SUMMON_MINDS_EYE,
    EVENT_SUMMON_CROSS_EYE,
    EVENT_SUMMON_STERN_EYE,

    // For roaming fogs and eyes
    EVENT_MOVE_RANDOM,
    EVENT_CHECK_BEAM_TARGET,

    EVENT_RED_EYE_VISUAL,
    EVENT_BLUE_EYE_VISUAL,

    // fogs
    EVENT_RED_FOG_WIND,
    EVENT_FOG_CAST,
    EVENT_DARK_PARASITE,
    // Eye mover
    EVENT_DISINTEGRATION_BEAM,
    EVENT_KILL_PLAYERS,
    EVENT_INITIALIZE_TYPE_MOVE,

    EVENT_ACTIVATE_MOVE,
    EVENT_PREACTION_TARGET,

    EVENT_DAMAGE_PLAYERS,
    EVENT_RED_EYE,
    EVENT_BLUE_EYE,
    EVENT_YELLOW_EYE,

    EVENT_CHECK_PLAYERS_FRONT,
    EVENT_DAMAGE_RAID,
    EVENT_KEEP_TARGET_MOVER,
    EVENT_DISINTEGRATION_BEAM_END,
    EVENT_HEROIC_SPECTRUM,
    EVENT_CAST_ONEYE,
    EVENT_CAUSTIC_SPIKE,
    EVENT_SUMMON_FOGS_CRIMSON,
    EVENT_SUMMON_FOGS_CRIMSON_KILLED,
    EVENT_SUMMON_FOGS_AZURE,
    EVENT_SUMMON_FOGS_AMBER,
    EVENT_CRIMSON_BLOOM,
    EVENT_ICY_GRASP,
    EVENT_FLASH_FREEZE,
    EVENT_AMBER_RETALIATION,
    EVENT_BURST_OF_AMBER,
    EVENT_STERN_GAZE,

    // maze safespot
    EVENT_CREATE_SAFESPOT,
    EVENT_CREATE_SAFESPOT_2,
    EVENT_CREATE_SAFESPOT_3,
    EVENT_CREATE_SAFESPOT_4,
    EVENT_CREATE_SAFESPOT_5,
    EVENT_CREATE_SAFESPOT_6,
    EVENT_CREATE_SAFESPOT_7,

    // movement
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_1_REVERSE,
    EVENT_2_REVERSE,
    EVENT_3_REVERSE,
    EVENT_4_REVERSE,
    EVENT_5_REVERSE,
    EVENT_6_REVERSE,
    EVENT_7_REVERSE,
    EVENT_8_REVERSE,

    // maze events
    EVENT_EYE_SORES_PLAYERS,
    EVENT_ADD_VIZUAL,
    EVENT_CHECK_PLAYERS_AND_MAKE_SAFEZONE,
    EVENT_READD_VIZUAL_MAZE,
    EVENT_SUMMON_MAZE_1,
    EVENT_SUMMON_MAZE_2,
    EVENT_ADD_WALLS_BEFORE_MAZE,
    EVENT_SUMMON_MAZE_3,
    EVENT_SUMMON_MAZE_4,
};

enum Points
{
    POINT_1 = 1,
    POINT_2 = 2,
    POINT_3 = 3,
    POINT_4 = 4,
    POINT_5 = 5,
    POINT_6 = 6,
    POINT_7 = 7,
    POINT_8 = 8,
    POINT_1_REVERSE = 9,
    POINT_2_REVERSE = 10,
    POINT_3_REVERSE = 11,
    POINT_4_REVERSE = 12,
    POINT_5_REVERSE = 13,
    POINT_6_REVERSE = 14,
    POINT_7_REVERSE = 15,
    POINT_8_REVERSE = 16,
};

enum Actions
{
    ACTION_LIGHT_SPECTRUM_DONE = 1,
    ACTION_ADD_SPECTRUM = 2,
    ACTION_CAST_SPELL_MOVER = 3,
    ACTION_ACTIVATE_WALLS = 4,
    ACTION_SPAWN_SPOTS = 5,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_HARD_STARE = 2,
    TALK_COLORBLIND = 3,
    TALK_GAZE = 4,
    TALK_DISINTEGRATION = 5,
    TALK_WIPE = 6,
    TALK_DEATH = 7,
};

#define STERN_DISTANCE 50.0f
#define IMMUNE_NPC me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC)
#define IMMUNE_PC me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC)

/*TODOS
*/

class bfa_boss_durumu : public CreatureScript
{
public:
    bfa_boss_durumu() : CreatureScript("bfa_boss_durumu") { }

    struct bfa_boss_durumuAI : public ScriptedAI
    {
        bfa_boss_durumuAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // Clash exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 126449, true); // clash exploits   
            me->AddUnitState(UNIT_STATE_ROOT);
            //set_speed(0.00001f);
            instance = creature->GetInstanceScript();
        }

        SummonList summons;
        EventMap events;
        bool firstBlind;
        bool colorBlind;
        uint8 spectrum;
        InstanceScript* instance;
        
        void Reset()
        {
            ActivateObjects();
            events.Reset();
            RemoveWalls();
            RemoveWalls2();
            RemoveWalls3();
            me->RemoveAllAreaTriggers();
            RemoveAdds();
            spectrum = 0;
            RemoveRays();
            colorBlind = false;
            firstBlind = false;

            if (instance)
                instance->SetBossState(DATA_DURUMU_THE_FORGOTTEN, NOT_STARTED);
        }

        void EnterEvadeMode(EvadeReason w)
        {
  

            Talk(TALK_WIPE);

            if (instance)
                instance->SetBossState(DATA_DURUMU_THE_FORGOTTEN, FAIL);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        void CalculateSpectrum()
        {
            ++spectrum;

            if (spectrum == 3)
            {
                me->AI()->DoAction(ACTION_LIGHT_SPECTRUM_DONE);
                spectrum = 0;
                colorBlind = false;
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ADD_SPECTRUM:
                CalculateSpectrum();
                //events.ScheduleEvent(EVENT_SUMMON_FOGS_CRIMSON_KILLED, 500, 0, 0);
                break;
            case ACTION_LIGHT_SPECTRUM_DONE:
            {
                DespawnCreature(YELLOW_EYE);
                DespawnCreature(BLUE_EYE);
                DespawnCreature(RED_EYE);
                DespawnCreature(CRIMSON_FOG); // erm, will summon it via spectrum counting
                DespawnCreature(AZURE_FOG);
                DespawnCreature(AMBER_FOG);
                events.CancelEvent(EVENT_HEROIC_SPECTRUM);
                break;
            }
            case ACTION_ACTIVATE_WALLS:
                ActivateWallsForMaze();
                break;
            case ACTION_SPAWN_SPOTS:
                SummonSafeSpots();
                break;
            }
        }

        //update ai is too messy, handle here
        void EyeDaggers(uint32 spellId, uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    if ((*summs)->IsAlive())
                        (*summs)->AddAura(spellId, *summs);
        }

        void RemoveWalls()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void RemoveWalls2()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_1, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void RemoveWalls3()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_2, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void MindDaggers()
        {
            EyeDaggers(SPELL_MIND_DAGGERS, MIND_EYE);
            EyeDaggers(SPELL_MIND_DAGGERS, STERN_EYE);
            EyeDaggers(SPELL_MIND_DAGGERS, HUNGRY_EYE);
            EyeDaggers(SPELL_MIND_DAGGERS, EVIL_EYE);
            EyeDaggers(SPELL_MIND_DAGGERS, APPRAYISYING_EYE);
        }

        void RemoveAdds()
        {
            DespawnCreature(HUNGRY_EYE);
            DespawnCreature(YELLOW_EYE);
            DespawnCreature(BLUE_EYE);
            DespawnCreature(RED_EYE);
            DespawnCreature(YELLOW_EYE_MOVER);
            DespawnCreature(MIND_EYE);
            DespawnCreature(HUNGRY_EYE);
            DespawnCreature(APPRAYISYING_EYE);
            DespawnCreature(EVIL_EYE);
            DespawnCreature(STERN_EYE);
            DespawnCreature(CROSS_EYE);
            DespawnCreature(WANDERING_EYE);
            DespawnCreature(NPC_WALL_OF_ICE_1);
            DespawnCreature(NPC_WALL_OF_ICE_2);
            DespawnCreature(NPC_WALL_OF_ICE_3);
            DespawnCreature(NPC_VOID_ZONE_LINGERING_GAZE);
            DespawnCreature(CRIMSON_FOG);
            DespawnCreature(AZURE_FOG);
            DespawnCreature(AMBER_FOG);
            DespawnCreature(NPC_MAZE_BEAM);
            DespawnCreature(NPC_MAZE_PERIODIC);
            DespawnCreature(NPC_SAFESPOT_1);
            DespawnCreature(NPC_SAFESPOT_2);
            DespawnCreature(NPC_SAFESPOT_3);
            DespawnCreature(NPC_SAFESPOT_4);
            DespawnCreature(NPC_SAFESPOT_5);
            DespawnCreature(NPC_SAFESPOT_6);
            DespawnCreature(NPC_SAFESPOT_7);
        }

        void SetFly(bool IsFlying)
        {
            me->SetDisableGravity(IsFlying);
            me->SetCanFly(IsFlying);
        }

        void JustDied(Unit* killer)
        {
            Talk(TALK_DEATH);
            RemoveAdds();
            RemoveWalls();
            RemoveWalls2();
            RemoveWalls3();
            RemoveRays();
            ActivateObjects();
            if (instance)
                instance->SetBossState(DATA_DURUMU_THE_FORGOTTEN, DONE);
        }


        void RemoveRays()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_BLUE_BEAM_DMG);
                    player->RemoveAura(SPELL_RED_BEAM_DMG);
                    player->RemoveAura(SPELL_YELLOW_BEAM_DMG);
                }
        }

        void ActivateWallsForMaze()
        {
            for (uint8 i = 0; i < 5; ++i)
            {
                me->SummonCreature(NPC_WALL_OF_ICE_1, WallsofIce1[i], TEMPSUMMON_DEAD_DESPAWN);
            }
            for (uint8 i = 0; i < 4; ++i)
            {
                me->SummonCreature(NPC_WALL_OF_ICE_2, WallsofIce2[i], TEMPSUMMON_DEAD_DESPAWN);
            }
            for (uint8 i = 0; i < 4; ++i)
            {
                me->SummonCreature(NPC_WALL_OF_ICE_3, WallsofIce3[i], TEMPSUMMON_DEAD_DESPAWN);
            }
           // me->SummonGameObject(GO_WALL_OF_ICE, 5925.18f, 4493.79f, -6.27763f);
           // me->SummonGameObject(GO_WALL_OF_ICE_2, 5862.33f, 4508.2f, -6.27703f, 3.28283f, 0.0f, 0.0f, 0.997507f, -0.0705623f, 0);
            //me->SummonGameObject(GO_WALL_OF_ICE_1, 5903.09f, 4547.13f, -6.27707f, 1.28039f, 0.0f, 0.0f, 0.597351f, 0.80198f, 0);
        }

        void ActivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218396, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218395, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void DeactivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218396, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218395, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void EnterCombat(Unit* attacker)
        {
            DeactivateObjects();
            Talk(TALK_AGGRO);
            firstBlind = true;
            events.ScheduleEvent(EVENT_HARD_STARE, 5000);
            events.ScheduleEvent(EVENT_GAZE, 7000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);

            events.ScheduleEvent(EVENT_SUMMON_MINDS_EYE, 19000, 0, 0);
            events.ScheduleEvent(EVENT_SUMMON_APPRAISIING_EYE, 15000, 0, 0);
            //events.ScheduleEvent(EVENT_SUMMON_HUNGRY_EYE, 40000, 0, 0);
            events.ScheduleEvent(EVENT_DISINTEGRATION_BEAM, 2.5 * MINUTE * IN_MILLISECONDS); // 2.5 * MINUTE * IN_MILLISECONDS
            events.ScheduleEvent(EVENT_ADD_WALLS_BEFORE_MAZE, 2.3 * MINUTE * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_LIGHT_SPECTRUM, 30000, 0, 0);
            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_SUMMON_EVIL_EYE, 90000, 0, 0);

            if (instance)
                instance->SetBossState(DATA_DURUMU_THE_FORGOTTEN, IN_PROGRESS);
        }

        void CheckPlayersInWater()
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 100.0f);
            for (auto player : PlayerList)
                if (player->IsInWater())
                    player->Kill(player);
        }

        bool CheckFlyingHacks()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive())
                    {
                        if (player->IsFlying() && !player->IsGameMaster()) // If players are flying => fuck 'em
                        {
                            player->Kill(player, true);
                            player->GetSession()->KickPlayer();
                        }
                    }
                }
            return true;
        }

        bool CheckDistanceHack()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive() && !player->IsGameMaster())
                    {
                        if (player->GetDistance(me) > 67.0f)
                        {
                            player->Kill(player, true);
                        }
                    }
                }
            return true;
        }

        void SummonSafeSpots()
        {
            me->SummonCreature(NPC_SAFESPOT_1, 5880.47f, 4519.99f, -6.27746f, 5.79017f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_2, 5891.26f, 4528.9f, -6.27746f, 4.84062f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_3, 5905.47f, 4528.13f, -6.27746f, 4.17697f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_4, 5911.43f, 4514.46f, -6.27746f, 3.23055f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_5, 5908.87f, 4501.28f, -6.27746f, 2.40432f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_6, 5893.92f, 4497.04f, -6.27746f, 1.6629f, TEMPSUMMON_TIMED_DESPAWN, 58000);
            me->SummonCreature(NPC_SAFESPOT_7, 5879.46f, 4502.67f, -6.27746f, 0.520142f, TEMPSUMMON_TIMED_DESPAWN, 58000);
        }

        void UpdateAI(uint32 diff)
        {

            // Falled to water in out of platform = die
            if (me->IsInCombat())
            {
                CheckPlayersInWater();
                CheckFlyingHacks();
                CheckDistanceHack();
            }

            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case EVENT_HARD_STARE:
                Talk(TALK_HARD_STARE);
                if (me->GetVictim())
                {
                    DoCast(me->GetVictim(), SPELL_HARD_STARE);
                }
                events.ScheduleEvent(EVENT_HARD_STARE, 18000);
                break;
            case EVENT_GAZE:
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true);
                if (!target)
                    if (!me->HasUnitState(UNIT_STATE_CASTING))
                        DoCast(SPELL_GAZE);
                events.ScheduleEvent(EVENT_GAZE, 2000);
                break;
            }
            case EVENT_BERSERK:
                DoCast(SPELL_BERSERK_KILLALL);
                break;
            case EVENT_SUMMON_APPRAISIING_EYE:
                Talk(TALK_GAZE);
                me->SummonCreature(APPRAYISYING_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                //events.ScheduleEvent(EVENT_SUMMON_APPRAISIING_EYE, 15000, 0, 0);
                break;
            case EVENT_SUMMON_MINDS_EYE:
                if (!colorBlind)
                    me->SummonCreature(MIND_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_SUMMON_MINDS_EYE, 27000, 0, 0);
                break;
            case EVENT_SUMMON_HUNGRY_EYE:
                me->SummonCreature(HUNGRY_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_SUMMON_HUNGRY_EYE, 40000, 0, 0);
                break;
            case EVENT_SUMMON_EVIL_EYE:
                me->SummonCreature(EVIL_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_SUMMON_EVIL_EYE, 90000, 0, 0);
                break;
            case EVENT_ADD_WALLS_BEFORE_MAZE:
                if (me->GetMap()->IsHeroic())
                    me->AI()->DoAction(ACTION_ACTIVATE_WALLS);
                break;
            case EVENT_DISINTEGRATION_BEAM:
            {
                Talk(TALK_DISINTEGRATION);
                if (Creature* tarMover = me->SummonCreature(NPC_MAZE_BEAM, 5838.92f, 4503.38f, -6.27f, 6.08f, TEMPSUMMON_MANUAL_DESPAWN)) //5841.55f, 4517.23f, -6.27f
                {
                    me->AddThreat(tarMover, 99999999.9f);
                    me->AI()->AttackStart(tarMover);
                    me->CastSpell(tarMover, SPELL_DESINTEGRATION_BEAM_PRECAST, true);
                }
                MindDaggers();
                me->AI()->DoAction(ACTION_SPAWN_SPOTS);
                if (me->GetMap()->IsHeroic())
                    SpawnGaze();
                //events.ScheduleEvent(EVENT_KEEP_TARGET_MOVER, 500, 0, 0);
                events.ScheduleEvent(EVENT_DISINTEGRATION_BEAM_END, 47000);
                break;
            }
            case EVENT_KEEP_TARGET_MOVER:
                if (Creature* tarMover = me->FindNearestCreature(YELLOW_EYE_MOVER, 500.0f, true))
                    me->SetFacingToObject(tarMover);
                events.ScheduleEvent(EVENT_KEEP_TARGET_MOVER, 500, 0, 0);
                break;
            case EVENT_KILL_PLAYERS:
                //TryKillPlayerInFront(); //TEMPDISABLE
                events.ScheduleEvent(EVENT_KILL_PLAYERS, 500, 0, 0);
                break;
            case EVENT_DISINTEGRATION_BEAM_END:
                events.CancelEvent(EVENT_KILL_PLAYERS);
                events.CancelEvent(EVENT_KEEP_TARGET_MOVER);
                events.ScheduleEvent(EVENT_DISINTEGRATION_BEAM, 3 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_ADD_WALLS_BEFORE_MAZE, 2.8 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_HUNGRY_EYE, 4000, 0, 0);
                break;
            case EVENT_LIGHT_SPECTRUM:
                Talk(TALK_COLORBLIND);
                colorBlind = true;
                me->SummonCreature(BLUE_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(RED_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(YELLOW_EYE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_LIGHT_SPECTRUM, 3.5 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_FOGS_CRIMSON, 500, 0, 0);
                events.ScheduleEvent(EVENT_SUMMON_FOGS_AZURE, 550, 0, 0);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_FOGS_AMBER, 600, 0, 0);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_HEROIC_SPECTRUM, 80000);
                if (!firstBlind)
                {
                    if (me->GetMap()->IsHeroic())
                        events.ScheduleEvent(EVENT_WALLS_OF_ICE, 1000);
                }
                firstBlind = false;
                break;
            case EVENT_HEROIC_SPECTRUM: // On heroic, if players doesn't complete the Light Spectrum sequences within 80 seconds, kill them ( 3 Crimson Fogs )
                if (me->FindNearestCreature(CRIMSON_FOG, 500.0f, true))
                    DoCast(SPELL_BERSERK_KILLALL);
                break;
            case EVENT_WALLS_OF_ICE:
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    me->SummonCreature(NPC_WALL_OF_ICE_1, WallsofIce1[i], TEMPSUMMON_DEAD_DESPAWN);
                }
                for (uint8 i = 0; i < 4; ++i)
                {
                    me->SummonCreature(NPC_WALL_OF_ICE_2, WallsofIce2[i], TEMPSUMMON_DEAD_DESPAWN);
                }
                for (uint8 i = 0; i < 4; ++i)
                {
                    me->SummonCreature(NPC_WALL_OF_ICE_3, WallsofIce3[i], TEMPSUMMON_DEAD_DESPAWN);
                }
                //me->SummonGameObject(GO_WALL_OF_ICE, 5925.18f, 4493.79f, -6.27763f, 5.61419f, 0.0f, 0.0f, 0.328294f, -0.944576f, 0);
                //me->SummonGameObject(GO_WALL_OF_ICE_1, 5862.33f, 4508.2f, -6.27703f, 3.28283f, 0.0f, 0.0f, 0.997507f, -0.0705623f, 0);
                //->SummonGameObject(GO_WALL_OF_ICE_2, 5903.09f, 4547.13f, -6.27707f, 1.28039f, 0.0f, 0.0f, 0.597351f, 0.80198f, 0);
                break;
            }
            case EVENT_SUMMON_FOGS_CRIMSON:
            {
                for (uint8 i = 0; i < 3; ++i)
                    me->SummonCreature(CRIMSON_FOG, CriomsonFogs[i], TEMPSUMMON_DEAD_DESPAWN);
                //me->SummonCreature(CRIMSON_FOG, CriomsonFogs[pos], TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            case EVENT_SUMMON_FOGS_CRIMSON_KILLED: // no longer used
            {
                uint8 pos = urand(1, 2);
                me->SummonCreature(CRIMSON_FOG, CriomsonFogs[pos], TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            case EVENT_SUMMON_FOGS_AZURE:
            {
                //uint8 pos = urand(0, 2);
                me->SummonCreature(AZURE_FOG, 5946.81f, 4499.13f, -6.27f, 2.93f, TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            case EVENT_SUMMON_FOGS_AMBER:
            {
                //uint8 pos = urand(0, 1);
                me->SummonCreature(AMBER_FOG, 5929.27f, 4474.55f, -6.27f, 2.45f, TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            }

            if (!me->HasUnitState(UNIT_STATE_CASTING))
                DoMeleeAttackIfReady();
        }

        void SpawnGaze()
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                me->SummonCreature(STERN_EYE, SternPattern[i], TEMPSUMMON_TIMED_DESPAWN, 50000);
            }
        }

        void TryKillPlayerInFront()
        {
            // In maze time phase all players in front of durumu beam instant killed
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 80.0f);
            for (auto player : PlayerList)
                if (me->isInFront(player, 3.14f / 2.0f))
                    me->Kill(player);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case RED_EYE:
            case BLUE_EYE:
            case YELLOW_EYE:
                summon->SetInCombatWithZone();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_durumuAI(creature);
    }
};

// Arterial Cut - 133768
class bfa_spell_arterial_cut : public SpellScriptLoader
{
public:
    bfa_spell_arterial_cut() : SpellScriptLoader("bfa_spell_arterial_cut") { }

    class bfa_spell_arterial_cut_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_arterial_cut_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (aurEff->GetTickNumber() > 1)
            {
                if (GetTarget())
                {
                    if (GetTarget()->IsFullHealth())
                    {
                        if (GetTarget()->HasAura(GetId()))
                            GetTarget()->RemoveAura(GetId());
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_arterial_cut_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_arterial_cut_AuraScript();
    }
};

class bfa_npc_hungry_eye : public CreatureScript
{
public:
    bfa_npc_hungry_eye() : CreatureScript("bfa_npc_hungry_eye") { }

    struct bfa_npc_hungry_eyeAI : public ScriptedAI
    {
        bfa_npc_hungry_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_DRAIN_LIFE, 3000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void CheckBetweenPlayerAndDmg()
        {
            std::list<Player*> PlayerList, PlayersInBetween;
            Player* DrainLifeTarget = NULL;
            GetPlayerListInGrid(PlayerList, me, 100.0f);

            uint32 oldDuration = 0;
            for (auto itr : PlayerList)
                if (Aura* aura = itr->GetAura(SPELL_DRAIN_LIFE_STUN))
                {
                    DrainLifeTarget = itr;
                    oldDuration = aura->GetDuration();
                }

            if (DrainLifeTarget != NULL)
            {
                for (auto itr : PlayerList)
                    if (itr->IsInBetween(me, DrainLifeTarget, 5.0f) && itr->GetGUID() != DrainLifeTarget->GetGUID())
                        PlayersInBetween.push_back(itr);

                Player* NearstPlayer = DrainLifeTarget;
                if (NearstPlayer)
                {
                    for (auto itr : PlayersInBetween)
                        if (itr->GetDistance(me) < NearstPlayer->GetDistance(me))
                            NearstPlayer = itr;

                    DrainLifeTarget->RemoveAura(SPELL_DRAIN_LIFE_STUN);
                    DoCast(NearstPlayer, SPELL_DRAIN_LIFE_DAMAGE, true);
                    if (NearstPlayer->HasAura(SPELL_DRAIN_LIFE_STUN))
                        return;
                    me->CastSpell(NearstPlayer, SPELL_DRAIN_LIFE_STUN);
                    if (Aura* aura = me->AddAura(SPELL_DRAIN_LIFE_STUN, NearstPlayer))
                    {
                        aura->SetDuration(oldDuration);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DRAIN_LIFE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        DoCast(target, SPELL_DRAIN_LIFE_STUN);
                        DoCast(target, SPELL_DRAIN_LIFE_CHANNEL);
                        std::ostringstream str;
                        str << "|TInterface\\Icons\\Spell_shadow_lifedrain02.blp:20|t Durumu begins charging up his Hungry Eye to cast |cFFF00000|Hspell:133795|h[Life Drain]|h|r on " << (target->GetName()) << "!|TInterface\\Icons\\Spell_shadow_lifedrain02.blp:20|t";
                        me->TextEmote(str.str().c_str(), 0, true);
                    }
                    events.ScheduleEvent(EVENT_DRAIN_LIFE_TAR_CHECK, 200, 0, 0);
                    me->DespawnOrUnsummon(10000);
                    break;
                case EVENT_DRAIN_LIFE_TAR_CHECK:
                    CheckBetweenPlayerAndDmg();
                    events.ScheduleEvent(EVENT_DRAIN_LIFE_TAR_CHECK, 1500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_hungry_eyeAI(creature);
    }
};

class bfa_npc_appraising_eye : public CreatureScript
{
public:
    bfa_npc_appraising_eye() : CreatureScript("bfa_npc_appraising_eye") { }

    struct bfa_npc_appraising_eyeAI : public ScriptedAI
    {
        bfa_npc_appraising_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_LINGERING_MARKER, 1000, 0, 0);
            events.ScheduleEvent(EVENT_LINGERING_GAZE, 2500, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);


            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LINGERING_MARKER:
                {
                    std::ostringstream str;
                    str << "|TInterface\\Icons\\Inv_misc_eye_02.blp:20|t Durumu begins charging up his Appraising Eye to cast |cFFF00000|Hspell:133792|h[Lingering Gaze]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);
                    ActivateMarkers();
                    break;
                }
                case EVENT_LINGERING_GAZE:
                    if (me->HasAura(SPELL_MIND_DAGGERS))
                        return;
                    DoCastAOE(SPELL_LINGERING_GAZE_CAST);
                    events.ScheduleEvent(EVENT_LINGERING_TRIGGERED, 500, 0, 0);
                    break;
                case EVENT_LINGERING_TRIGGERED:
                    if (me->HasAura(SPELL_MIND_DAGGERS))
                        return;
                    CastLingering();
                    events.ScheduleEvent(EVENT_LINGERING_MARKER, 15000);
                    events.ScheduleEvent(EVENT_LINGERING_GAZE, 16500);
                    break;
                }
            }
        }

        void CastLingering()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->HasAura(SPELL_LINGERING_GAZE_MARKER))
                        me->CastSpell(player, SPELL_LINGERING_GAZE_DMG);
                }
        }

        void CastMark10() // for 10 diffs
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 2, SELECT_TARGET_FARTHEST, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, SPELL_LINGERING_GAZE_MARKER, true);
        }

        void CastMark25() // for 25 diffs
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_FARTHEST, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, SPELL_LINGERING_GAZE_MARKER, true);
        }

        void ActivateMarkers()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_N:
                CastMark10();
                break;
            case DIFFICULTY_25_N:
                CastMark25();
                break;
            case DIFFICULTY_10_HC:
                CastMark10();
                break;
            case DIFFICULTY_25_HC:
                CastMark25();
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_appraising_eyeAI(creature);
    }
};

class bfa_npc_minds_eye : public CreatureScript
{
public:
    bfa_npc_minds_eye() : CreatureScript("bfa_npc_minds_eye") { }

    struct bfa_npc_minds_eyeAI : public ScriptedAI
    {
        bfa_npc_minds_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_FORCE_OF_WILL, 1000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FORCE_OF_WILL:
                {
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        if (Creature* trigger = me->SummonCreature(60942, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000))
                        {
                            std::ostringstream str;
                            str << "|TInterface\\Icons\\Ability_monk_forcesphere.blp:20|t Durumu begins charging up his Evil Eye to cast |cFFF00000|Hspell:136932|h[Force of Will]|h|r on " << (player->GetName()) << "!|TInterface\\Icons\\Ability_monk_forcesphere.blp:20|t";
                            me->TextEmote(str.str().c_str(), 0, true);
                            me->SetFacingToObject(trigger);
                            me->AddThreat(trigger, 9999999.9f);
                            me->AI()->AttackStart(trigger);
                            me->SetFacingToObject(trigger);
                            me->CastSpell(me, SPELL_FORCE_OF_WILL);
                            DoCast(SPELL_FORCE_OF_WILL);
                        }
                    }
                    //me->CastSpell(player, SPELL_FORCE_OF_WILL);
                    me->DespawnOrUnsummon(10000);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_minds_eyeAI(creature);
    }
};

// Force of Will - 136932
class bfa_spell_force_of_will : public SpellScriptLoader
{
public:
    bfa_spell_force_of_will() : SpellScriptLoader("bfa_spell_force_of_will") { }

    class bfa_spell_force_of_will_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_force_of_will_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(GetCaster(), SPELL_FORCE_OF_WILL_KNOCKBACK, true);
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_force_of_will_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_force_of_will_AuraScript();
    }
};

// Drain life dmg calculate 133798
class bfa_spell_drain_life_durumu : public SpellScriptLoader
{
public:
    bfa_spell_drain_life_durumu() : SpellScriptLoader("bfa_spell_drain_life_durumu") { }

    class bfa_spell_drain_life_durumu_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_drain_life_durumu_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            int32 amount = GetHitDamage();

            if (GetHitUnit()->HasAura(SPELL_DRAIN_LIFE_DAMAGE))
                amount += (amount * 0.40) * GetHitUnit()->GetAura(SPELL_DRAIN_LIFE_DAMAGE)->GetStackAmount();

            int32 bp = amount * 22;
            std::list<Creature*> durumu;
            GetCreatureListWithEntryInGrid(durumu, GetCaster(), 68036, 100.0f);
            for (auto durumuTarget : durumu)
                durumuTarget->CastCustomSpell(durumuTarget, SPELL_DRAIN_LIFE_HEAL, &bp, NULL, NULL, true);

            SetHitDamage(amount);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_drain_life_durumu_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_drain_life_durumu_SpellScript();
    }
};

class bfa_npc_evil_eye : public CreatureScript
{
public:
    bfa_npc_evil_eye() : CreatureScript("bfa_npc_evil_eye") { }

    struct bfa_npc_evil_eyeAI : public ScriptedAI
    {
        bfa_npc_evil_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_DARK_PARASITE, 1000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DARK_PARASITE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    {
                        me->CastSpell(target, SPELL_DARK_PARASITE);
                        std::ostringstream str;
                        str << "|TInterface\\Icons\\Spell_shadow_curseofmannoroth.blp:20|t Durumu begins charging up his Evil Eye to cast |cFFF00000|Hspell:133597|h[Dark Parasite]|h|r on " << (target->GetName()) << "!|TInterface\\Icons\\Spell_shadow_curseofmannoroth.blp:20|t";
                        me->TextEmote(str.str().c_str(), 0, true);
                    }
                    events.ScheduleEvent(EVENT_DARK_PARASITE, 7000, 0, 0);
                    me->DespawnOrUnsummon(10000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_evil_eyeAI(creature);
    }
};

// Dark Parasite - 133597
class bfa_spell_dark_parasite : public SpellScriptLoader
{
public:
    bfa_spell_dark_parasite() : SpellScriptLoader("bfa_spell_dark_parasite") { }

    class bfa_spell_dark_parasite_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_dark_parasite_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* target = GetTarget()->ToPlayer())
            {
                if (!target)
                    return;

                if (Aura* parasite = target->GetAura(SPELL_DARK_PARASITE))
                {
                    if (!parasite)
                        return;

                    uint32 amount = parasite->GetEffect(EFFECT_0)->GetAmount(); //GetSpellInfo()->Effects[EFFECT_0].BasePoints;
                    amount += amount;
                    parasite->GetEffect(EFFECT_0)->SetAmount(amount);
                }
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;
            caster->CastSpell(caster, SPELL_DARK_PLAGUE, true);
            if (Aura* plague = caster->GetAura(SPELL_DARK_PLAGUE))
            {
                uint32 duration = aurEff->GetBase()->GetDuration();
                plague->SetDuration(duration);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_dark_parasite_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_dark_parasite_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_dark_parasite_AuraScript();
    }
};

class bfa_npc_wandering_eye : public CreatureScript
{
public:
    bfa_npc_wandering_eye() : CreatureScript("bfa_npc_wandering_eye") { }

    struct bfa_npc_wandering_eyeAI : public ScriptedAI
    {
        bfa_npc_wandering_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
            owner = 0;
        }

        EventMap events;
        uint64 owner;

        void IsSummonedBy(Unit* summoner)
        {
            //owner = summoner->GetGUID();
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_START_DEVOUR, 1000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (Unit* ownerUnit = who)
                me->DealDamage(ownerUnit, damage);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_DEVOUR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->AI()->AttackStart(target);
                        me->AddThreat(target, 99999999.9f);
                    }
                    events.ScheduleEvent(EVENT_DEVOUR, 2000, 0, 0);
                    break;
                case EVENT_DEVOUR:
                    me->CastSpell(me->GetVictim(), SPELL_DEVOUR_PERIODIC);
                    events.ScheduleEvent(EVENT_DEVOUR, 2000, 0, 0);
                    me->GetMotionMaster()->MoveFollow(me->GetVictim(), 0, 0);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_wandering_eyeAI(creature);
    }
};

// durumu eyebeam mover 67829
class bfa_npc_eyebeam_target : public CreatureScript
{
public:
    bfa_npc_eyebeam_target() : CreatureScript("bfa_npc_eyebeam_target") { }

    struct bfa_npc_eyebeam_targetAI : public ScriptedAI
    {
        bfa_npc_eyebeam_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            //set_speed(0.5f);
            IMMUNE_PC;
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->SetReactState(REACT_PASSIVE);
            events.ScheduleEvent(EVENT_PREACTION_TARGET, 1000);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CAST_SPELL_MOVER:
            {
                if (Creature* yellow = me->FindNearestCreature(YELLOW_EYE, 500.0f, true))
                {
                    yellow->CastSpell(me, SPELL_YELLOW_BEAM, true);
                    yellow->AddThreat(me, 99999999.9f);
                    yellow->AI()->AttackStart(me);
                }
                if (roll_chance_f(50))
                    events.ScheduleEvent(EVENT_1, 1000, 0, 0);
                else
                    events.ScheduleEvent(EVENT_1_REVERSE, 1000, 0, 0);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PREACTION_TARGET:
                {
                    if (Creature* yellow = me->FindNearestCreature(YELLOW_EYE, 500.0f, true))
                        yellow->CastSpell(me, SPELL_YELLOW_PREBLIND);
                    events.ScheduleEvent(EVENT_ACTIVATE_MOVE, 10000);
                    break;
                }
                case EVENT_ACTIVATE_MOVE:
                    me->AI()->DoAction(ACTION_CAST_SPELL_MOVER);
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, YellowEyeWay[1]);
                    //sWorld->SendWorldText(3, "gopoint 1 c");
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, YellowEyeWay[2]);
                    //sWorld->SendWorldText(3, "gopoint 2 c");
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, YellowEyeWay[3]);
                    //sWorld->SendWorldText(3, "go point3 c");
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, YellowEyeWay[4]);
                    //sWorld->SendWorldText(3, "go point 4 c");
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, YellowEyeWay[5]);
                    //sWorld->SendWorldText(3, "go point 5 c");
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_6, YellowEyeWay[6]);
                    //sWorld->SendWorldText(3, "go point 6 c");
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_7, YellowEyeWay[7]);
                    //sWorld->SendWorldText(3, "go point 7 c");
                    break;
                case EVENT_8:
                    me->GetMotionMaster()->MovePoint(POINT_8, YellowEyeWay[8]);
                    //sWorld->SendWorldText(3, "go point 8 c");
                    break;
                case EVENT_1_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_1_REVERSE, YellowEyeWay2[1]);
                    //sWorld->SendWorldText(3, "gopoint 1 cc");
                    break;
                case EVENT_2_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_2_REVERSE, YellowEyeWay2[2]);
                    //sWorld->SendWorldText(3, "gopoint 2 cc");
                    break;
                case EVENT_3_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_3_REVERSE, YellowEyeWay2[3]);
                    //sWorld->SendWorldText(3, "gopoint 3 cc");
                    break;
                case EVENT_4_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_4_REVERSE, YellowEyeWay2[4]);
                    //sWorld->SendWorldText(3, "gopoint 4 cc");
                    break;
                case EVENT_5_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_5_REVERSE, YellowEyeWay2[5]);
                    //sWorld->SendWorldText(3, "gopoint 5 cc");
                    break;
                case EVENT_6_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_6_REVERSE, YellowEyeWay2[6]);
                    //sWorld->SendWorldText(3, "gopoint 6 cc");
                    break;
                case EVENT_7_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_7_REVERSE, YellowEyeWay2[7]);
                    //sWorld->SendWorldText(3, "gopoint 7 cc");
                    break;
                case EVENT_8_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_8_REVERSE, YellowEyeWay2[8]);
                    //sWorld->SendWorldText(3, "gopoint 8 cc");
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
                // clockwise 
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 1000, 0, 0);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 1000, 0, 0);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 1000, 0, 0);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 1000, 0, 0);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 1000, 0, 0);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_7, 1000, 0, 0);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_8, 1000, 0, 0);
                break;
            case POINT_8:
                events.ScheduleEvent(EVENT_1, 1000, 0, 0);
                break;
                // counter-clockwise
            case POINT_1_REVERSE:
                events.ScheduleEvent(EVENT_2_REVERSE, 1000, 0, 0);
                break;
            case POINT_2_REVERSE:
                events.ScheduleEvent(EVENT_3_REVERSE, 1000, 0, 0);
                break;
            case POINT_3_REVERSE:
                events.ScheduleEvent(EVENT_4_REVERSE, 1000, 0, 0);
                break;
            case POINT_4_REVERSE:
                events.ScheduleEvent(EVENT_5_REVERSE, 1000, 0, 0);
                break;
            case POINT_5_REVERSE:
                events.ScheduleEvent(EVENT_6_REVERSE, 1000, 0, 0);
                break;
            case POINT_6_REVERSE:
                events.ScheduleEvent(EVENT_7_REVERSE, 1000, 0, 0);
                break;
            case POINT_7_REVERSE:
                events.ScheduleEvent(EVENT_8_REVERSE, 1000, 0, 0);
                break;
            case POINT_8_REVERSE:
                events.ScheduleEvent(EVENT_1_REVERSE, 1000, 0, 0);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_eyebeam_targetAI(creature);
    }
};

class bfa_npc_lingering_gaze : public CreatureScript
{
public:
    bfa_npc_lingering_gaze() : CreatureScript("bfa_npc_lingering_gaze") { }

    struct bfa_npc_lingering_gazeAI : public ScriptedAI
    {
        bfa_npc_lingering_gazeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_DAMAGE_PLAYERS, 1000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DAMAGE_PLAYERS:
                    std::list<Unit*> players;
                    SelectTargetList(players, 1, SELECT_TARGET_RANDOM, 300.0f, true);
                    if (!players.empty())
                    {
                        for (auto target : players)
                        {
                            if (!target->HasAura(SPELL_VOID_LINGERING_GAZE))
                                me->CastSpell(target, SPELL_VOID_LINGERING_GAZE, true);
                        }
                    }
                    events.ScheduleEvent(EVENT_DAMAGE_PLAYERS, 1000, 0, 0);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_lingering_gazeAI(creature);
    }
};

class bfa_npc_light_spectrum_red : public CreatureScript
{
public:
    bfa_npc_light_spectrum_red() : CreatureScript("bfa_npc_light_spectrum_red") { }

    struct bfa_npc_light_spectrum_redAI : public ScriptedAI
    {
        bfa_npc_light_spectrum_redAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            IMMUNE_NPC;
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_RED_EYE, 1000, 0, 0);
            //events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 12000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            me->SetFacingToObject(me->GetVictim());

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RED_EYE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->AddThreat((*itr), 9999999.9f);
                        me->AI()->AttackStart((*itr));
                        me->CastSpell((*itr), SPELL_RED_PREBLIND, true);
                        std::ostringstream str;
                        str << "|TInterface\\Icons\\Priest_icon_chakra_red.blp:20|t Durumu begins charging up his Red Eye to cast |cFFF00000|Hspell:133732|h[Infrared Ligt]|h|r on " << (*itr)->GetName() << "!|TInterface\\Icons\\Priest_icon_chakra_red.blp:20|t";
                        me->TextEmote(str.str().c_str(), 0, true);
                    }
                    events.ScheduleEvent(EVENT_RED_EYE_VISUAL, 9500, 0, 0);
                    break;
                }
                case EVENT_RED_EYE_VISUAL:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                        return;
                    me->CastSpell(target, SPELL_RED_BEAM, true);
                    break;
                }
                case EVENT_CHECK_PLAYERS_FRONT:
                {
                    CheckPlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 2000, 0, 0);
                    break;
                }
                case EVENT_DAMAGE_RAID:
                    me->CastSpell(me, SPELL_RED_BEAM_DMG_TO_ALL, true);
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 2000, 0, 0);
                    break;
                }
            }
        }

        void CheckPlayers()
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 80.0f);
            for (auto player : PlayerList)
                if (me->isInFront(player, 3.14f / 6.0f))
                {
                    //sWorld->SendWorldText(3, "IN FRONT CHECK ACTIVE");
                    events.CancelEvent(EVENT_DAMAGE_RAID);
                }
                else
                {
                    //sWorld->SendWorldText(3, "NO PLAYERS IN FRONT");
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 500, 0, 0);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_light_spectrum_redAI(creature);
    }
};

class bfa_npc_light_spectrum_blue : public CreatureScript
{
public:
    bfa_npc_light_spectrum_blue() : CreatureScript("bfa_npc_light_spectrum_blue") { }

    struct bfa_npc_light_spectrum_blueAI : public ScriptedAI
    {
        bfa_npc_light_spectrum_blueAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            IMMUNE_NPC;
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_BLUE_EYE, 1000, 0, 0);
            //events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 12000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            me->SetFacingToObject(me->GetVictim());

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLUE_EYE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->AddThreat((*itr), 9999999.9f);
                        me->AI()->AttackStart((*itr));
                        me->CastSpell((*itr), SPELL_BLUE_PREBLIND, true);
                        std::ostringstream str;
                        str << "|TInterface\\Icons\\Priest_icon_chakra_blue.blp:20|t Durumu begins charging up his Blue Eye to cast |cFFF00000|Hspell:133677|h[Blue Rays]|h|r on " << (*itr)->GetName() << "!|TInterface\\Icons\\Priest_icon_chakra_blue.blp:20|t";
                        me->TextEmote(str.str().c_str(), 0, true);
                    }
                    events.ScheduleEvent(EVENT_BLUE_EYE_VISUAL, 9500, 0, 0);
                    break;
                }
                case EVENT_BLUE_EYE_VISUAL:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                        return;
                    me->CastSpell(target, SPELL_BLUE_BEAM, true);
                    break;
                }
                case EVENT_CHECK_PLAYERS_FRONT:
                {
                    CheckPlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 2000, 0, 0);
                    break;
                }
                case EVENT_DAMAGE_RAID:
                    me->CastSpell(me, SPELL_BLUE_BEAM_DMG_TO_ALL, true);
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 2000, 0, 0);
                    break;
                }
            }
        }

        void CheckPlayers()
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 80.0f);
            for (auto player : PlayerList)
                if (me->isInFront(player, 3.14f / 6.0f))
                {
                    //sWorld->SendWorldText(3, "IN FRONT CHECK ACTIVE");
                    events.CancelEvent(EVENT_DAMAGE_RAID);
                }
                else
                {
                    //sWorld->SendWorldText(3, "NO PLAYERS IN FRONT");
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 500, 0, 0);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_light_spectrum_blueAI(creature);
    }
};

class bfa_npc_light_spectrum_yellow : public CreatureScript
{
public:
    bfa_npc_light_spectrum_yellow() : CreatureScript("bfa_npc_light_spectrum_yellow") { }

    struct bfa_npc_light_spectrum_yellowAI : public ScriptedAI
    {
        bfa_npc_light_spectrum_yellowAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_YELLOW_EYE, 1000, 0, 0);
            //events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 12000, 0, 0);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            me->SetFacingToObject(me->GetVictim());

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_YELLOW_EYE:
                    me->SummonCreature(YELLOW_EYE_MOVER, 5841.55f, 4517.23f, -6.27f, 6.08f, TEMPSUMMON_MANUAL_DESPAWN);
                    //events.ScheduleEvent(EVENT_CAST_ONEYE, 200, 0, 0);
                    break;
                case EVENT_CAST_ONEYE:
                    if (Creature* tarMover = me->FindNearestCreature(YELLOW_EYE_MOVER, 500.0f, true))
                        tarMover->AI()->DoAction(ACTION_CAST_SPELL_MOVER);
                    //me->CastSpell(tarMover, SPELL_YELLOW_BEAM, true);
                    break;
                case EVENT_CHECK_PLAYERS_FRONT:
                {
                    CheckPlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS_FRONT, 1000, 0, 0);
                    break;
                }
                case EVENT_DAMAGE_RAID:
                    me->CastSpell(me, SPELL_YELLOW_BEAM_DMG_TO_ALL, true);
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 2000, 0, 0);
                    break;
                }
            }
        }

        void CheckPlayers()
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 80.0f);
            for (auto player : PlayerList)
                if (me->isInFront(player, 3.14f / 6.0f))
                {
                    //sWorld->SendWorldText(3, "IN FRONT CHECK ACTIVE");
                    events.CancelEvent(EVENT_DAMAGE_RAID);
                }
                else
                {
                    //sWorld->SendWorldText(3, "NO PLAYERS IN FRONT");
                    events.ScheduleEvent(EVENT_DAMAGE_RAID, 500, 0, 0);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_light_spectrum_yellowAI(creature);
    }
};

class bfa_npc_crimson_fog : public CreatureScript
{
public:
    bfa_npc_crimson_fog() : CreatureScript("bfa_npc_crimson_fog") { }

    struct bfa_npc_crimson_fogAI : public ScriptedAI
    {
        bfa_npc_crimson_fogAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        EventMap events;
        bool active;

        void Reset()
        {
            active = false;
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->CastSpell(me, SPELL_RED_FOG, true);
            me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 9000);
        }

        void IsMeInFrontOfBeam()
        {
            std::list<Creature*> beam;
            me->GetCreatureListWithEntryInGrid(beam, RED_EYE, 200.0f);
            for (auto beamEye : beam)
                if (beamEye->isInFront(me, 3.14f / 4.0f))
                {
                    active = true;
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAura(SPELL_FOG_INVISIBLE);
                    me->RestoreDisplayId();
                    events.ScheduleEvent(EVENT_CAUSTIC_SPIKE, 500);
                    events.ScheduleEvent(EVENT_CRIMSON_BLOOM, 700);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_BEAM_TARGET:
                    if (!active)
                        IsMeInFrontOfBeam();
                    events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 500);
                    break;
                case EVENT_CAUSTIC_SPIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        me->CastSpell(target, SPELL_CAUSTIC_SPIKE);
                    events.ScheduleEvent(EVENT_CAUSTIC_SPIKE, 3000);
                    break;
                case EVENT_CRIMSON_BLOOM:
                {
                    std::list<Creature*> red;
                    me->GetCreatureListWithEntryInGrid(red, RED_EYE, 200.0f);
                    for (auto redEye : red)
                        if (!redEye->isInFront(me, 3.14f / 4.0f))
                        {
                            events.CancelEvent(EVENT_CAUSTIC_SPIKE);
                            if (!me->HasAura(SPELL_FOG_INVISIBLE))
                                me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
                            active = false;
                            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(SPELL_CRIMSON_BLOOM);
                        }
                    events.ScheduleEvent(EVENT_CRIMSON_BLOOM, 700);
                    break;
                }
                }
            }
        }

        void JustDied(Unit*)
        {
            if (Creature* durumu = me->FindNearestCreature(BOSS_DURUMU, 500.0f, true))
            {
                durumu->AI()->DoAction(ACTION_ADD_SPECTRUM);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_crimson_fogAI(creature);
    }
};

class bfa_npc_azure_fog : public CreatureScript
{
public:
    bfa_npc_azure_fog() : CreatureScript("bfa_npc_azure_fog") { }

    struct bfa_npc_azure_fogAI : public ScriptedAI
    {
        bfa_npc_azure_fogAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        EventMap events;
        bool active;

        void Reset()
        {
            active = false;
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->CastSpell(me, SPELL_BLUE_FOG, true);
            me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 9000);
        }

        void IsMeInFrontOfBeam()
        {
            std::list<Creature*> beam;
            me->GetCreatureListWithEntryInGrid(beam, BLUE_EYE, 200.0f);
            for (auto beamEye : beam)
                if (beamEye->isInFront(me, 3.14f / 4.0f))
                {
                    active = true;
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAura(SPELL_FOG_INVISIBLE);
                    me->RestoreDisplayId();
                    events.ScheduleEvent(EVENT_ICY_GRASP, 500);
                    events.ScheduleEvent(EVENT_FLASH_FREEZE, 700);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_BEAM_TARGET:
                    if (!active)
                        IsMeInFrontOfBeam();
                    events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 500);
                    break;
                case EVENT_ICY_GRASP:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->HasAura(SPELL_BLUE_BEAM))
                                me->CastSpell(player, SPELL_ICY_GRASP, true);
                        }
                    events.ScheduleEvent(EVENT_ICY_GRASP, 3000);
                    break;
                }
                case EVENT_FLASH_FREEZE:
                {
                    std::list<Creature*> blue;
                    me->GetCreatureListWithEntryInGrid(blue, BLUE_EYE, 200.0f);
                    for (auto blueEye : blue)
                        if (!blueEye->isInFront(me, 3.14f / 4.0f))
                        {
                            events.CancelEvent(EVENT_ICY_GRASP);
                            if (!me->HasAura(SPELL_FOG_INVISIBLE))
                                me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
                            active = false;
                            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(SPELL_FLASH_FREEZE);
                        }
                    events.ScheduleEvent(EVENT_FLASH_FREEZE, 700);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_azure_fogAI(creature);
    }
};

class bfa_npc_amber_fog : public CreatureScript
{
public:
    bfa_npc_amber_fog() : CreatureScript("bfa_npc_amber_fog") { }

    struct bfa_npc_amber_fogAI : public ScriptedAI
    {
        bfa_npc_amber_fogAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        EventMap events;
        bool active;
        bool healthLost1;
        bool healthLost2;
        bool healthLost3;
        bool healthLost4;
        bool healthLost5;
        bool healthLost6;
        bool healthLost7;
        bool healthLost8;
        bool healthLost9;
        bool healthLost10;

        void Reset()
        {
            active = false;
            healthLost1 = false;
            healthLost2 = false;
            healthLost3 = false;
            healthLost4 = false;
            healthLost5 = false;
            healthLost6 = false;
            healthLost7 = false;
            healthLost8 = false;
            healthLost9 = false;
            healthLost10 = false;
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->CastSpell(me, SPELL_YELLOW_FOG, true);
            me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 9000);
        }

        void IsMeInFrontOfBeam()
        {
            std::list<Creature*> beam;
            me->GetCreatureListWithEntryInGrid(beam, YELLOW_EYE, 200.0f);
            for (auto beamEye : beam)
                if (beamEye->isInFront(me, 3.14f / 7.0f))
                {
                    active = true;
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAura(SPELL_FOG_INVISIBLE);
                    me->RestoreDisplayId();
                    events.ScheduleEvent(EVENT_BURST_OF_AMBER, 700);
                }
        }

        void DamageTaken(Unit*, uint32& damage)
        {
            if (me->HealthBelowPct(90) && !healthLost1)
            {
                healthLost1 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(80) && !healthLost2)
            {
                healthLost2 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(70) && !healthLost10)
            {
                healthLost10 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(60) && !healthLost3)
            {
                healthLost3 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(50) && !healthLost4)
            {
                healthLost4 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(40) && !healthLost5)
            {
                healthLost5 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(30) && !healthLost6)
            {
                healthLost6 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(20) && !healthLost7)
            {
                healthLost7 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
            if (me->HealthBelowPct(10) && !healthLost9)
            {
                healthLost9 = true;
                events.ScheduleEvent(EVENT_AMBER_RETALIATION, 100, 0, 0);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_BEAM_TARGET:
                    if (!active)
                        IsMeInFrontOfBeam();
                    events.ScheduleEvent(EVENT_CHECK_BEAM_TARGET, 500);
                    break;
                case EVENT_AMBER_RETALIATION:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->HasAura(133737))
                                me->CastSpell(player, SPELL_AMBER_RETALIATION, true);
                        }
                    break;
                }
                case EVENT_BURST_OF_AMBER:
                {
                    std::list<Creature*> yellow;
                    me->GetCreatureListWithEntryInGrid(yellow, YELLOW_EYE, 200.0f);
                    for (auto yellowEye : yellow)
                        if (!yellowEye->isInFront(me, 3.14f / 4.0f))
                        {
                            if (!me->HasAura(SPELL_FOG_INVISIBLE))
                                me->CastSpell(me, SPELL_FOG_INVISIBLE, true);
                            active = false;
                            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(SPELL_BURST_OF_AMBER);
                        }
                    events.ScheduleEvent(EVENT_BURST_OF_AMBER, 700);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_amber_fogAI(creature);
    }
};

// Lingering Gaze missile - 133793
class bfa_spell_lingering_gaze : public SpellScriptLoader
{
public:
    bfa_spell_lingering_gaze() : SpellScriptLoader("bfa_spell_lingering_gaze") { }

    class bfa_spell_lingering_gaze_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_lingering_gaze_SpellScript);

        void HandleHitScript(SpellEffIndex index)
        {
            if (!GetHitUnit())
                return;

            GetHitUnit()->SummonCreature(NPC_VOID_ZONE_LINGERING_GAZE, GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY(), GetHitUnit()->GetPositionZ(), GetHitUnit()->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 30 * MINUTE * IN_MILLISECONDS);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_lingering_gaze_SpellScript::HandleHitScript, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_lingering_gaze_SpellScript();
    }
};

// Wall of Ice - 999250
class bfa_npc_walls_of_ice_1 : public CreatureScript
{
public:
    bfa_npc_walls_of_ice_1() : CreatureScript("bfa_npc_walls_of_ice_1") { }

    struct bfa_npc_walls_of_ice_1AI : public ScriptedAI
    {
        bfa_npc_walls_of_ice_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IN_COMBAT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetObjectScale(0.4f);
            me->CastSpell(me, SPELL_ICE_WALL);
            me->SetInCombatWithZone();
            SetHealth();
        }

        void SetHealth()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(8431000);
                me->SetHealth(8431000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(25300000);
                me->SetHealth(25300000);
                break;
            }
        }

        void JustDied(Unit*)
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void RemoveWall()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            std::list<Creature*> creatures;
            me->GetCreatureListWithEntryInGrid(creatures, NPC_WALL_OF_ICE_1, 500.0f);

            bool despawn = false;
            if (damage > me->GetHealth())
            {
                RemoveWall();
                me->Kill(me);
                despawn = true;
            }

            for (auto creature : creatures)
            {
                if (creature == me)
                    continue;
                if (despawn)
                {
                    RemoveWall();
                    creature->Kill(creature);
                }
                else
                    creature->SetHealth(me->GetHealth() - damage);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_walls_of_ice_1AI(creature);
    }
};

// Wall of Ice - 999251
class bfa_npc_walls_of_ice_2 : public CreatureScript
{
public:
    bfa_npc_walls_of_ice_2() : CreatureScript("bfa_npc_walls_of_ice_2") { }

    struct bfa_npc_walls_of_ice_2AI : public ScriptedAI
    {
        bfa_npc_walls_of_ice_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IN_COMBAT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetObjectScale(0.4f);
            me->CastSpell(me, SPELL_ICE_WALL);
            me->SetInCombatWithZone();
            SetHealth();
        }

        void JustDied(Unit*)
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_2, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void SetHealth()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(8431000);
                me->SetHealth(8431000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(25300000);
                me->SetHealth(25300000);
                break;
            }
        }

        void RemoveWall()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_2, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            std::list<Creature*> creatures;
            me->GetCreatureListWithEntryInGrid(creatures, NPC_WALL_OF_ICE_2, 500.0f);

            bool despawn = false;
            if (damage > me->GetHealth())
            {
                RemoveWall();
                me->Kill(me);
                despawn = true;
            }

            for (auto creature : creatures)
            {
                if (creature == me)
                    continue;
                if (despawn)
                {
                    RemoveWall();
                    creature->Kill(creature);
                }
                else
                    creature->SetHealth(me->GetHealth() - damage);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_walls_of_ice_2AI(creature);
    }
};

// Wall of Ice - 999252
class bfa_npc_walls_of_ice_3 : public CreatureScript
{
public:
    bfa_npc_walls_of_ice_3() : CreatureScript("bfa_npc_walls_of_ice_3") { }

    struct bfa_npc_walls_of_ice_3AI : public ScriptedAI
    {
        bfa_npc_walls_of_ice_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IN_COMBAT);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->SetObjectScale(0.4f);
            me->CastSpell(me, SPELL_ICE_WALL);
            SetHealth();
        }

        void JustDied(Unit*)
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_1, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void RemoveWall()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_WALL_OF_ICE_1, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->Delete();
        }

        void SetHealth()
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(8431000);
                me->SetHealth(8431000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(25300000);
                me->SetHealth(25300000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            std::list<Creature*> creatures;
            me->GetCreatureListWithEntryInGrid(creatures, NPC_WALL_OF_ICE_3, 500.0f);

            bool despawn = false;
            if (damage > me->GetHealth())
            {
                RemoveWall();
                me->Kill(me);
                despawn = true;
            }

            for (auto creature : creatures)
            {
                if (creature == me)
                    continue;
                if (despawn)
                {
                    RemoveWall();
                    creature->Kill(creature);
                }
                else
                    creature->SetHealth(me->GetHealth() - damage);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_walls_of_ice_3AI(creature);
    }
};

// Beam divided damage - 133738, 133732, 133677
class bfa_spell_red_blue_yellow_inside_damage : public SpellScriptLoader
{
public:
    bfa_spell_red_blue_yellow_inside_damage() : SpellScriptLoader("bfa_spell_red_blue_yellow_inside_damage") { }

    class bfa_spell_red_blue_yellow_inside_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_red_blue_yellow_inside_damage_SpellScript);

        uint8 targetsPlayers;

        bool Load()
        {
            targetsPlayers = 1;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetsPlayers = targets.size();
        }

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(GetHitDamage() / targetsPlayers);
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (!caster->isInFront(*itr, 3.14f / 4.0f))
                {
                    targets.erase(itr++);
                    continue;
                }
                ++itr;
            }

            if (targets.size() < 2)
                SendFullDamage();
        }

        void SendFullDamage()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetMap()->IsLFR())
                return;

            switch (caster->GetEntry())
            {
            case RED_EYE:
                caster->CastSpell(nullptr, SPELL_RED_BEAM_DMG_TO_ALL);
                break;
            case BLUE_EYE:
                caster->CastSpell(nullptr, SPELL_BLUE_BEAM_DMG_TO_ALL);
                break;
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_red_blue_yellow_inside_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_DEST_CASTER_UNK_36);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_red_blue_yellow_inside_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_red_blue_yellow_inside_damage_SpellScript::FilterTargets, EFFECT_0, TARGET_DEST_CASTER_UNK_36);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_red_blue_yellow_inside_damage_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_red_blue_yellow_inside_damage_SpellScript();
    }
};

class bfa_spell_disintegration_beam : public SpellScriptLoader
{
public:
    bfa_spell_disintegration_beam() : SpellScriptLoader("bfa_spell_disintegration_beam") { }

    class bfa_spell_disintegration_beam_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_disintegration_beam_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            /*PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster)
                return;
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, caster, 80.0f);
            for (auto player : PlayerList)
                if (caster->isInFront(player, M_PI / 2))
                    caster->Kill(player, false);*/

            Unit* durumu = GetCaster();
            Unit* triggerTarget = GetTarget();
            Unit* targetPlayer = NULL;

            if (!durumu || !triggerTarget)
                return;

            Map::PlayerList const& playerList = durumu->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    Position dur;
                    Position trigger;
                    //durumu->GetPosition(&dur);
                    //triggerTarget->GetPosition(&trigger);
                    if (player->IsInBetween(dur, trigger, 3.5f))
                        durumu->Kill(player);
                }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_disintegration_beam_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_disintegration_beam_AuraScript;
    }
};

// Mind Daggers - 139107
class bfa_spell_mind_daggers : public SpellScriptLoader
{
public:
    bfa_spell_mind_daggers() : SpellScriptLoader("bfa_spell_mind_daggers") { }

    class bfa_spell_mind_daggers_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_mind_daggers_SpellScript);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 3 : 1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_mind_daggers_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_mind_daggers_SpellScript();
    }
};

// Stern Gaze - 136616
class bfa_spell_stern_gaze : public SpellScriptLoader
{
public:
    bfa_spell_stern_gaze() : SpellScriptLoader("bfa_spell_stern_gaze") { }

    class bfa_spell_stern_gaze_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_stern_gaze_SpellScript);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 5 : 2);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_stern_gaze_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_stern_gaze_SpellScript();
    }
};

class bfa_npc_stern_eye : public CreatureScript
{
public:
    bfa_npc_stern_eye() : CreatureScript("bfa_npc_stern_eye") { }

    struct bfa_npc_stern_eyeAI : public ScriptedAI
    {
        bfa_npc_stern_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void Reset()
        {
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_STERN_GAZE, 1000, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (Creature* durumu = me->FindNearestCreature(BOSS_DURUMU, 200.0f, true))
                me->SetFacingToObject(durumu);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STERN_GAZE:
                {
                    std::list<Player*> PlayerList;
                    GetPlayerListInGrid(PlayerList, me, 80.0f);
                    for (auto player : PlayerList)
                        if (me->isInFront(player, 3.14f / 4.0f))
                        {
                            switch (me->GetMap()->GetDifficultyID())
                            {
                            case DIFFICULTY_10_N:
                                CastStern10();
                                break;
                            case DIFFICULTY_25_N:
                                CastStern25();
                                break;
                            case DIFFICULTY_10_HC:
                                CastStern10();
                                break;
                            case DIFFICULTY_25_HC:
                                CastStern25();
                                break;
                            }
                        }
                    events.ScheduleEvent(EVENT_STERN_GAZE, 15000, 0, 0);
                    break;
                }
                }
            }
        }

        void CastStern10() // for 10 diffs
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 2, SELECT_TARGET_NEAREST, 200.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, 136616, true);
        }

        void CastStern25() // for 25 diffs
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_NEAREST, 200.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, 136616, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_stern_eyeAI(creature);
    }
};

class bfa_npc_maze : public CreatureScript
{
public:
    bfa_npc_maze() : CreatureScript("bfa_npc_maze") { }

    struct bfa_npc_mazeAI : public ScriptedAI
    {
        bfa_npc_mazeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetFaction(14);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_ADD_VIZUAL, 1000, 0, 0);
            events.ScheduleEvent(EVENT_EYE_SORES_PLAYERS, 5000, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ADD_VIZUAL:
                    me->AddAura(SPELL_MAZE_VIZUAL, me);
                    //events.ScheduleEvent(EVENT_CHECK_PLAYERS_AND_MAKE_SAFEZONE, 5000, 0, 0);
                    break;
                case EVENT_CHECK_PLAYERS_AND_MAKE_SAFEZONE:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetExactDist(me) < 10.0f)
                            {
                                me->RemoveAura(SPELL_MAZE_VIZUAL);
                                events.ScheduleEvent(EVENT_READD_VIZUAL_MAZE, 10000, 0, 0);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS_AND_MAKE_SAFEZONE, 1000, 0, 0);
                    break;
                }
                case EVENT_READD_VIZUAL_MAZE:
                    me->AddAura(SPELL_MAZE_VIZUAL, me);
                    break;
                case EVENT_EYE_SORES_PLAYERS:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 9.0f)
                            {
                                if (!player->HasAura(SPELL_EYE_SORES))
                                    me->AddAura(SPELL_EYE_SORES, player);
                            }
                        }
                    events.ScheduleEvent(EVENT_EYE_SORES_PLAYERS, 1000, 0, 0);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_mazeAI(creature);
    }
};

class bfa_spell_disintegration_beam_precast : public SpellScriptLoader
{
public:
    bfa_spell_disintegration_beam_precast() : SpellScriptLoader("bfa_spell_disintegration_beam_precast") { }

    class bfa_spell_disintegration_beam_precast_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_disintegration_beam_precast_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;
            if (aurEff->GetTickNumber() == 1)
                SummonFirstMaze();
            else if (aurEff->GetTickNumber() == 2)
                SummonSecondMaze();
            else if (aurEff->GetTickNumber() == 3)
                SummonThirdMaze();
            else if (aurEff->GetTickNumber() == 4)
                SummonForthMaze();
        }

        void SummonFirstMaze()
        {
            for (uint8 i = 0; i < 27; ++i)
            {
                GetCaster()->SummonCreature(NPC_MAZE_PERIODIC, firstPlatformMaze[i], TEMPSUMMON_TIMED_DESPAWN, 50000);
            }
        }
        void SummonSecondMaze()
        {
            for (uint8 i = 0; i < 17; ++i)
            {
                GetCaster()->SummonCreature(NPC_MAZE_PERIODIC, secondPlatformMaze[i], TEMPSUMMON_TIMED_DESPAWN, 50000);
            }
        }
        void SummonThirdMaze()
        {
            for (uint8 i = 0; i < 19; ++i)
            {
                GetCaster()->SummonCreature(NPC_MAZE_PERIODIC, thirdPlatformMaze[i], TEMPSUMMON_TIMED_DESPAWN, 50000);
            }
        }
        void SummonForthMaze()
        {
            for (uint8 i = 0; i < 31; ++i)
            {
                GetCaster()->SummonCreature(NPC_MAZE_PERIODIC, fourthPlatformMaze[i], TEMPSUMMON_TIMED_DESPAWN, 50000);
            }
        }

        void OnRemove(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            std::list<Creature*> beam;
            GetCreatureListWithEntryInGrid(beam, GetCaster(), NPC_MAZE_BEAM, 500.0f);
            for (Creature* tarBeam : beam)
                GetCaster()->CastSpell(tarBeam, SPELL_DESINTEGRATION_BEAM);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_disintegration_beam_precast_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_disintegration_beam_precast_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_disintegration_beam_precast_AuraScript;
    }
};

class bfa_npc_disintegration_beam_movement : public CreatureScript
{
public:
    bfa_npc_disintegration_beam_movement() : CreatureScript("bfa_npc_disintegration_beam_movement") { }

    struct bfa_npc_disintegration_beam_movementAI : public ScriptedAI
    {
        bfa_npc_disintegration_beam_movementAI(Creature* creature) : ScriptedAI(creature)
        {
            IMMUNE_PC;
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_DESINTEGRATION_BEAM)
            {
                events.ScheduleEvent(EVENT_1, 1000); // only clock wise
                /*if (roll_chance_f(50))
                    events.ScheduleEvent(EVENT_1, 1000, 0, 0);
                else
                    events.ScheduleEvent(EVENT_1_REVERSE, 1000, 0, 0);*/
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, YellowEyeWay[1]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, YellowEyeWay[2]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, YellowEyeWay[3]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, YellowEyeWay[4]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, YellowEyeWay[5]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_6, YellowEyeWay[6]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_7, YellowEyeWay[7]);
                    break;
                case EVENT_8:
                    me->GetMotionMaster()->MovePoint(POINT_8, YellowEyeWay[8]);
                    break;
                case EVENT_1_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_1_REVERSE, YellowEyeWay2[1]);
                    break;
                case EVENT_2_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_2_REVERSE, YellowEyeWay2[2]);
                    break;
                case EVENT_3_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_3_REVERSE, YellowEyeWay2[3]);
                    break;
                case EVENT_4_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_4_REVERSE, YellowEyeWay2[4]);
                    break;
                case EVENT_5_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_5_REVERSE, YellowEyeWay2[5]);
                    break;
                case EVENT_6_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_6_REVERSE, YellowEyeWay2[6]);
                    break;
                case EVENT_7_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_7_REVERSE, YellowEyeWay2[7]);
                    break;
                case EVENT_8_REVERSE:
                    me->GetMotionMaster()->MovePoint(POINT_8_REVERSE, YellowEyeWay2[8]);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
                // clockwise 
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 1000, 0, 0);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 1000, 0, 0);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 1000, 0, 0);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 1000, 0, 0);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 1000, 0, 0);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_7, 1000, 0, 0);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_8, 1000, 0, 0);
                break;
            case POINT_8:
                events.ScheduleEvent(EVENT_1, 1000, 0, 0);
                break;
                // counter-clockwise
            case POINT_1_REVERSE:
                events.ScheduleEvent(EVENT_2_REVERSE, 1000, 0, 0);
                break;
            case POINT_2_REVERSE:
                events.ScheduleEvent(EVENT_3_REVERSE, 1000, 0, 0);
                break;
            case POINT_3_REVERSE:
                events.ScheduleEvent(EVENT_4_REVERSE, 1000, 0, 0);
                break;
            case POINT_4_REVERSE:
                events.ScheduleEvent(EVENT_5_REVERSE, 1000, 0, 0);
                break;
            case POINT_5_REVERSE:
                events.ScheduleEvent(EVENT_6_REVERSE, 1000, 0, 0);
                break;
            case POINT_6_REVERSE:
                events.ScheduleEvent(EVENT_7_REVERSE, 1000, 0, 0);
                break;
            case POINT_7_REVERSE:
                events.ScheduleEvent(EVENT_8_REVERSE, 1000, 0, 0);
                break;
            case POINT_8_REVERSE:
                events.ScheduleEvent(EVENT_1_REVERSE, 1000, 0, 0);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_disintegration_beam_movementAI(creature);
    }
};

// Stern Gaze
class bfa_spell_stern_gaze_damage : public SpellScriptLoader
{
public:
    bfa_spell_stern_gaze_damage() : SpellScriptLoader("bfa_spell_stern_gaze_damage") { }

    class bfa_spell_stern_gaze_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_stern_gaze_damage_SpellScript);

        void DealDamage()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    float distance = caster->GetExactDist2d(target);
                    uint32 mindmg = 0, maxdmg = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                        // Can't find any proof for the base damage on each difficulty .. put on all same value atm
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_25_HC:
                    case DIFFICULTY_25_N:
                    case DIFFICULTY_10_HC:
                        mindmg = 90000;
                        maxdmg = 100000;
                        break;
                    }

                    if (distance > STERN_DISTANCE)
                        distance = STERN_DISTANCE;

                    SetHitDamage(((mindmg / +STERN_DISTANCE) * distance) + maxdmg);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_stern_gaze_damage_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_stern_gaze_damage_SpellScript();
    }
};

class bfa_spell_icy_grasp : public SpellScriptLoader
{
public:
    bfa_spell_icy_grasp() : SpellScriptLoader("bfa_spell_icy_grasp") { }

    class bfa_spell_icy_grasp_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_icy_grasp_SpellScript);

        void DealDamage()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    uint32 damage = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                        // didn't found any infos about the damage and increasing rate so: same damage as Caustic Spike and double the value at next cast
                    case DIFFICULTY_10_N:
                        damage = 56999;
                        break;
                    case DIFFICULTY_25_N:
                        damage = 91199;
                        break;
                    case DIFFICULTY_10_HC:
                        damage = 80000;
                        break;
                    case DIFFICULTY_25_HC:
                        damage = 128000;
                        break;
                    }

                    SetHitDamage(damage);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_icy_grasp_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_icy_grasp_SpellScript();
    }
};

// 999259, 999260, 999262, 999263, 999264, 999265, 999266,
class bfa_npc_maze_safespot_controler : public CreatureScript
{
public:
    bfa_npc_maze_safespot_controler() : CreatureScript("bfa_npc_maze_safespot_controler") { }

    struct bfa_npc_maze_safespot_controlerAI : public ScriptedAI
    {
        bfa_npc_maze_safespot_controlerAI(Creature* creature) : ScriptedAI(creature)
        {
            //me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            switch (me->GetEntry())
            {
            case NPC_SAFESPOT_2:
            case NPC_SAFESPOT_3:
            case NPC_SAFESPOT_4:
            case NPC_SAFESPOT_5:
            case NPC_SAFESPOT_6:
            case NPC_SAFESPOT_7:
                me->AddAura(SPELL_MAZE_VIZUAL, me);
            }
            events.ScheduleEvent(EVENT_EYE_SORES_PLAYERS, 1000);
            events.ScheduleEvent(EVENT_CREATE_SAFESPOT, 12000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_EYE_SORES_PLAYERS:
                {
                    if (me->HasAura(SPELL_MAZE_VIZUAL))
                    {
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                            {
                                if (player->GetDistance(me) < 8.0f)
                                {
                                    if (!player->HasAura(SPELL_EYE_SORES))
                                        me->AddAura(SPELL_EYE_SORES, player);
                                }
                            }
                    }
                    events.ScheduleEvent(EVENT_EYE_SORES_PLAYERS, 2000);
                    break;
                }
                case EVENT_ADD_VIZUAL:
                    //sWorld->SendWorldText(3, "new visual add");
                    me->AddAura(SPELL_MAZE_VIZUAL, me);
                    break;
                case EVENT_CREATE_SAFESPOT:
                    if (me->GetEntry() == NPC_SAFESPOT_1)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL); // checks to be sure
                        //me->MonsterYell("SAFE 1 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 9000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_2, 4000);
                    break;
                case EVENT_CREATE_SAFESPOT_2:
                    if (me->GetEntry() == NPC_SAFESPOT_2)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 2 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 14000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_3, 5000);
                    break;
                case EVENT_CREATE_SAFESPOT_3:
                    if (me->GetEntry() == NPC_SAFESPOT_3)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 3 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 14000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_4, 6000);
                    break;
                case EVENT_CREATE_SAFESPOT_4:
                    if (me->GetEntry() == NPC_SAFESPOT_4)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 4 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 14000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_5, 8000);
                    break;
                case EVENT_CREATE_SAFESPOT_5:
                    if (me->GetEntry() == NPC_SAFESPOT_5)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 5 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 14000);
                    }

                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_6, 8000);
                    break;
                case EVENT_CREATE_SAFESPOT_6:
                    if (me->GetEntry() == NPC_SAFESPOT_6)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 6 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 14000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT_7, 8000);
                    break;
                case EVENT_CREATE_SAFESPOT_7:
                    if (me->GetEntry() == NPC_SAFESPOT_7)
                    {
                        if (me->HasAura(SPELL_MAZE_VIZUAL))
                            me->RemoveAura(SPELL_MAZE_VIZUAL);
                        //me->MonsterYell("SAFE 7 ACTIVE", LANG_UNIVERSAL, NULL);
                        events.ScheduleEvent(EVENT_ADD_VIZUAL, 9000);
                    }
                    events.ScheduleEvent(EVENT_CREATE_SAFESPOT, 8000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_maze_safespot_controlerAI(creature);
    }
};

// 136413
class bfa_spell_force_of_will_pushback : public SpellScriptLoader
{
public:
    bfa_spell_force_of_will_pushback() : SpellScriptLoader("bfa_spell_force_of_will_pushback") { }

    class bfa_spell_force_of_will_pushback_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_force_of_will_pushback_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (!caster->isInFront(*itr, 3.14f / 4.0f))
                {
                    targets.erase(itr++);
                    continue;
                }
                ++itr;
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_force_of_will_pushback_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_force_of_will_pushback_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_force_of_will_pushback_SpellScript();
    }
};

// 999271
class bfa_npc_durumu_platform_teleport : public CreatureScript
{
public:
    bfa_npc_durumu_platform_teleport() : CreatureScript("bfa_npc_durumu_platform_teleport") { }

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        player->NearTeleportTo(5957.48f, 4514.05f, -6.27f, 3.21f, false);
        return true;
    }
};

// 999270
class bfa_npc_jikun_teleport_to_durumu : public CreatureScript
{
public:
    bfa_npc_jikun_teleport_to_durumu() : CreatureScript("bfa_npc_jikun_teleport_to_durumu") { }

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        player->NearTeleportTo(6096.00f, 4408.77f, -6.25f, 2.06f, false);
        return true;
    }
};

// 133738
class bfa_spell_yellow_check_amber_retaliation : public SpellScriptLoader
{
public:
    bfa_spell_yellow_check_amber_retaliation() : SpellScriptLoader("bfa_spell_yellow_check_amber_retaliation") { }

    class bfa_spell_yellow_check_amber_retaliation_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_yellow_check_amber_retaliation_SpellScript);

        void HandleOnHit()
        {
            Unit* target = GetHitUnit()->ToPlayer();
            if (!GetCaster() || !target)
                return;
            GetCaster()->AddAura(133737, target);
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_yellow_check_amber_retaliation_SpellScript::HandleOnHit);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_yellow_check_amber_retaliation_SpellScript();
    }
};

void AddSC_boss_durumu()
{
    new bfa_boss_durumu;
    new bfa_npc_minds_eye;
    new bfa_npc_hungry_eye;
    new bfa_npc_appraising_eye;
    new bfa_npc_evil_eye;
    new bfa_npc_wandering_eye;
    new bfa_npc_eyebeam_target;
    new bfa_npc_lingering_gaze;
    new bfa_npc_light_spectrum_red;
    new bfa_npc_light_spectrum_blue;
    new bfa_npc_light_spectrum_yellow;
    new bfa_npc_amber_fog;
    new bfa_npc_crimson_fog;
    new bfa_npc_azure_fog;
    new bfa_npc_walls_of_ice_1;
    new bfa_npc_walls_of_ice_2;
    new bfa_npc_walls_of_ice_3;
    new bfa_npc_stern_eye;
    new bfa_npc_maze;
    new bfa_npc_disintegration_beam_movement;
    new bfa_npc_maze_safespot_controler;
    new bfa_npc_durumu_platform_teleport;
    new bfa_npc_jikun_teleport_to_durumu;

    new bfa_spell_arterial_cut;
    new bfa_spell_force_of_will;
    new bfa_spell_dark_parasite;
    new bfa_spell_lingering_gaze;
    new bfa_spell_red_blue_yellow_inside_damage;
    new bfa_spell_drain_life_durumu;
    new bfa_spell_mind_daggers;
    new bfa_spell_stern_gaze;
    new bfa_spell_disintegration_beam_precast;
    new bfa_spell_stern_gaze_damage;
    new bfa_spell_icy_grasp;
    new bfa_spell_disintegration_beam;
    new bfa_spell_force_of_will_pushback;
    new bfa_spell_yellow_check_amber_retaliation;
}
