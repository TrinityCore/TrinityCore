#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "throne_of_thunder.h"
#include "GameObject.h"

Position PillarPosition[4] =
{
    { 5771.50f, 4093.77f, 156.46f, 0.05f }, // North
    { 5710.80f, 4031.62f, 156.46f, 4.69f }, // East 
    { 5646.67f, 4094.85f, 156.46f, 3.12f }, // South
    { 5710.40f, 4158.81f, 156.46f, 1.53f }, // West
};

static const Position OverloadedCircuitsBouncingBall[51] =
{
    { 5741.24f, 4136.01f, 156.464f, 3.90927f },
    { 5705.91f, 4107.4f, 156.464f, 2.34397f },
    { 5710.17f, 4104.29f, 156.464f, 5.4777f },
    { 5711.01f, 4105.67f, 156.464f, 3.93283f },
    { 5723.29f, 4117.92f, 156.464f, 3.9132f },
    { 5717.49f, 4112.25f, 156.464f, 3.95247f },
    { 5730.41f, 4124.96f, 156.464f, 3.89749f },
    { 5735.79f, 4130.27f, 156.464f, 3.95246f },
    { 5736.12f, 4140.73f, 156.464f, 3.93047f },
    { 5680.94f, 4134.37f, 156.464f, 5.50519f },
    { 5684.8f, 4130.67f, 156.464f, 5.48556f },
    { 5688.54f, 4126.58f, 156.464f, 5.44629f },
    { 5691.55f, 4123.24f, 156.464f, 5.44629f },
    { 5694.56f, 4119.9f, 156.464f, 5.44629f },
    { 5697.58f, 4116.56f, 156.464f, 5.44629f },
    { 5700.59f, 4113.22f, 156.464f, 5.44629f },
    { 5729.21f, 4133.77f, 156.464f, 3.93047f },
    { 5702.1f, 4111.55f, 156.464f, 5.44236f },
    { 5724.12f, 4128.65f, 156.464f, 3.93047f },
    { 5716.46f, 4120.93f, 156.464f, 3.93047f },
    { 5709.59f, 4114.01f, 156.464f, 3.93047f },
    { 5705.67f, 4119.14f, 156.464f, 2.36752f },
    { 5700.98f, 4123.76f, 156.464f, 2.3636f },
    { 5694.00f, 4130.64f, 156.464f, 2.3636f },
    { 5688.41f, 4136.14f, 156.464f, 2.3636f },
    { 5689.2f, 4141.54f, 156.464f, 0.659281f },
    { 5695.89f, 4148.51f, 156.464f, 0.792799f },
    { 5704.04f, 4156.79f, 156.464f, 0.792799f },
    { 5710.66f, 4163.04f, 156.464f, 0.757456f },
    { 5716.71f, 4159.68f, 156.464f, 5.6662f },
    { 5720.99f, 4154.67f, 156.464f, 5.4188f },
    { 5725.21f, 4149.72f, 156.464f, 5.4188f },
    { 5729.65f, 4144.96f, 156.464f, 5.34811f },
    { 5726.8f, 4139.03f, 156.464f, 3.80481f },
    { 5721.09f, 4133.75f, 156.464f, 3.88728f },
    { 5713.34f, 4128.35f, 156.464f, 3.74983f },
    { 5704.45f, 4128.67f, 156.464f, 3.10581f },
    { 5703.42f, 4137.00f, 156.464f, 1.82561f },
    { 5694.84f, 4137.72f, 156.464f, 3.05868f },
    { 5701.94f, 4144.17f, 156.464f, 0.737831f },
    { 5708.78f, 4150.69f, 156.464f, 0.761393f },
    { 5712.07f, 4144.91f, 156.464f, 5.23031f },
    { 5716.23f, 4139.63f, 156.464f, 0.184124f },
    { 5713.06f, 4134.54f, 156.464f, 0.380474f },
    { 5721.86f, 4145.03f, 156.464f, 1.72743f },
    { 5715.73f, 4151.17f, 156.464f, 2.35575f },
    { 5710.67f, 4157.7f, 156.464f, 2.23009f },
    { 5701.75f, 4161.24f, 156.464f, 3.48673f },
    { 5695.15f, 4158.71f, 156.464f, 3.60846f },
    { 5690.09f, 4155.19f, 156.464f, 3.74983f },
    { 5710.69f, 4171.01f, 156.464f, 2.52461f },
};

static const Position OverloadedCircuitsDiffusionChain[38] =
{
    { 5716.78f, 4058.26f, 156.463f, 2.82385f },
    { 5715.94f, 4047.68f, 156.463f, 5.56489f },
    { 5710.4f, 4052.52f, 156.463f, 5.56096f },
    { 5703.89f, 4058.26f, 156.463f, 0.538339f },
    { 5698.45f, 4053.87f, 156.463f, 2.17982f },
    { 5703.97f, 4045.94f, 156.463f, 2.46649f },
    { 5710.86f, 4040.43f, 156.463f, 2.09343f },
    { 5711.7f, 4031.29f, 156.463f, 0.228107f },
    { 5706.84f, 4030.67f, 156.463f, 5.40781f },
    { 5700.52f, 4038.25f, 156.463f, 5.37247f },
    { 5693.31f, 4047.54f, 156.463f, 5.39996f },
    { 5689.26f, 4052.98f, 156.463f, 4.07264f },
    { 5696.64f, 4059.52f, 156.463f, 3.82917f },
    { 5705.19f, 4066.54f, 156.463f, 3.7074f },
    { 5713.95f, 4067.98f, 156.463f, 2.60395f },
    { 5719.12f, 4064.89f, 156.463f, 2.17983f },
    { 5724.55f, 4056.41f, 156.463f, 2.01097f },
    { 5714.89f, 4079.95f, 156.463f, 2.36047f },
    { 5719.66f, 4075.21f, 156.463f, 2.36047f },
    { 5726.52f, 4068.41f, 156.463f, 2.36047f },
    { 5730.8f, 4064.17f, 156.463f, 2.36047f },
    { 5734.62f, 4060.38f, 156.463f, 2.36047f },
    { 5738.41f, 4056.26f, 156.463f, 0.754334f },
    { 5731.47f, 4049.74f, 156.463f, 0.770042f },
    { 5724.29f, 4042.78f, 156.463f, 1.36302f },
    { 5723.69f, 4034.4f, 156.463f, 0.836801f },
    { 5717.46f, 4027.48f, 156.463f, 0.938903f },
    { 5710.11f, 4019.04f, 156.463f, 3.91949f },
    { 5701.12f, 4028.16f, 156.463f, 3.91949f },
    { 5690.9f, 4038.54f, 156.463f, 3.91949f },
    { 5678.15f, 4051.52f, 156.463f, 3.92342f },
    { 5682.44f, 4055.83f, 156.463f, 3.93912f },
    { 5686.65f, 4060.14f, 156.463f, 3.9352f },
    { 5691.54f, 4064.93f, 156.463f, 3.91556f },
    { 5697.84f, 4072.1f, 156.463f, 3.96269f },
    { 5703.2f, 4077.78f, 156.463f, 3.86451f },
    { 5708.04f, 4083.04f, 156.463f, 3.91164f },
    { 5711.04f, 4087.85f, 156.463f, 2.30549f },
};

static const Position OverloadedCircuitsStaticShock[55] =
{
    { 5755.76f, 4094.53f, 156.463f, 1.79102f },
    { 5742.07f, 4093.58f, 156.463f, 0.0592208f },
    { 5751.12f, 4089.47f, 156.463f, 2.32902f },
    { 5752.1f, 4081.79f, 156.463f, 5.02686f },
    { 5748.86f, 4096.33f, 156.463f, 4.66559f },
    { 5749.28f, 4105.21f, 156.463f, 4.66559f },
    { 5749.59f, 4111.78f, 156.463f, 4.66559f },
    { 5756.77f, 4113.79f, 156.463f, 2.73744f },
    { 5765.53f, 4110.06f, 156.463f, 2.76886f },
    { 5774.1f, 4106.6f, 156.463f, 2.59214f },
    { 5780.13f, 4102.92f, 156.463f, 2.79635f },
    { 5776.52f, 4098.91f, 156.463f, 0.821068f },
    { 5771.18f, 4093.18f, 156.463f, 0.821068f },
    { 5765.64f, 4087.23f, 156.463f, 0.821068f },
    { 5761.54f, 4082.83f, 156.463f, 0.821068f },
    { 5756.49f, 4077.39f, 156.463f, 0.958513f },
    { 5752.32f, 4072.68f, 156.463f, 5.59236f },
    { 5747.41f, 4076.74f, 156.463f, 5.60022f },
    { 5740.67f, 4082.22f, 156.463f, 5.60414f },
    { 5734.56f, 4087.13f, 156.463f, 5.612f },
    { 5729.47f, 4094.63f, 156.463f, 3.97052f },
    { 5735.00f, 4100.67f, 156.463f, 3.97052f },
    { 5739.59f, 4105.68f, 156.463f, 3.97052f },
    { 5745.31f, 4111.92f, 156.463f, 3.97052f },
    { 5750.71f, 4117.8f, 156.463f, 3.96659f },
    { 5755.09f, 4121.4f, 156.463f, 3.5464f },
    { 5757.49f, 4119.05f, 156.463f, 2.68639f },
    { 5766.46f, 4115.49f, 156.463f, 2.8709f },
    { 5774.15f, 4113.35f, 156.463f, 2.6589f },
    { 5780.01f, 4109.8f, 156.463f, 2.57643f },
    { 5785.36f, 4106.22f, 156.463f, 2.31333f },
    { 5785.65f, 4100.58f, 156.463f, 1.41797f },
    { 5783.53f, 4091.81f, 156.463f, 1.37085f },
    { 5781.62f, 4082.41f, 156.463f, 0.978148f },
    { 5774.61f, 4072.89f, 156.463f, 0.860339f },
    { 5766.67f, 4079.01f, 156.463f, 2.38794f },
    { 5759.77f, 4071.66f, 156.463f, 2.38794f },
    { 5755.99f, 4067.62f, 156.463f, 2.38794f },
    { 5751.73f, 4063.17f, 156.463f, 2.65497f },
    { 5746.16f, 4068.91f, 156.463f, 5.5099f },
    { 5741.06f, 4073.9f, 156.463f, 5.5099f },
    { 5733.99f, 4080.79f, 156.463f, 5.5099f },
    { 5728.58f, 4086.07f, 156.463f, 5.5099f },
    { 5723.83f, 4091.26f, 156.463f, 5.47456f },
    { 5720.1f, 4095.16f, 156.463f, 3.95089f },
    { 5721.35f, 4096.48f, 156.463f, 3.9234f },
    { 5727.97f, 4103.02f, 156.463f, 3.91948f },
    { 5733.31f, 4108.27f, 156.463f, 3.91948f },
    { 5739.64f, 4114.51f, 156.463f, 3.91948f },
    { 5744.83f, 4119.62f, 156.463f, 3.91948f },
    { 5749.45f, 4123.84f, 156.463f, 3.91555f },
    { 5752.12f, 4100.1f, 156.463f, 1.1038f },
    { 5757.00f, 4105.6f, 156.463f, 0.844619f },
    { 5764.9f, 4101.15f, 156.463f, 4.55563f },
    { 5763.38f, 4107.48f, 156.463f, 0.161322f },
};

static const Position OverloadedCircuitsOvercharge[40] =
{
    { 5677.79f, 4079.75f, 156.463f, 0.813231f },
    { 5671.99f, 4077.31f, 156.463f, 5.03867f },
    { 5669.53f, 4083.04f, 156.463f, 0.400895f },
    { 5661.21f, 4079.52f, 156.463f, 5.26644f },
    { 5657.29f, 4088.88f, 156.463f, 5.86334f },
    { 5649.04f, 4092.56f, 156.463f, 4.37109f },
    { 5652.32f, 4101.8f, 156.463f, 4.67739f },
    { 5665.09f, 4100.15f, 156.463f, 2.49791f },
    { 5673.04f, 4094.18f, 156.463f, 2.68248f },
    { 5681.76f, 4089.87f, 156.463f, 3.85273f },
    { 5687.23f, 4094.58f, 156.463f, 5.49813f },
    { 5679.5f, 4102.3f, 156.463f, 5.83585f },
    { 5671.61f, 4106.08f, 156.463f, 4.72452f },
    { 5671.52f, 4113.92f, 156.463f, 5.34891f },
    { 5665.18f, 4117.89f, 156.463f, 0.82893f },
    { 5660.59f, 4112.89f, 156.463f, 0.730759f },
    { 5653.12f, 4107.57f, 156.463f, 0.349841f },
    { 5645.03f, 4104.62f, 156.463f, 0.883912f },
    { 5638.6f, 4096.77f, 156.463f, 1.22556f },
    { 5635.4f, 4090.55f, 156.463f, 2.05023f },
    { 5639.23f, 4084.86f, 156.463f, 2.41544f },
    { 5646.98f, 4077.98f, 156.463f, 2.80028f },
    { 5657.01f, 4075.7f, 156.463f, 2.44686f },
    { 5666.21f, 4068.04f, 156.463f, 2.4822f },
    { 5669.21f, 4061.79f, 156.463f, 3.9666f },
    { 5675.08f, 4067.68f, 156.463f, 3.93126f },
    { 5679.84f, 4072.45f, 156.463f, 3.95089f },
    { 5683.65f, 4076.52f, 156.463f, 3.94304f },
    { 5687.67f, 4080.57f, 156.463f, 3.92733f },
    { 5692.76f, 4085.67f, 156.463f, 3.88413f },
    { 5696.88f, 4089.44f, 156.463f, 3.85272f },
    { 5700.14f, 4093.48f, 156.463f, 5.49813f },
    { 5698.65f, 4094.97f, 156.463f, 5.49813f },
    { 5695.48f, 4098.13f, 156.463f, 5.49813f },
    { 5691.62f, 4101.99f, 156.463f, 5.49813f },
    { 5686.92f, 4106.69f, 156.463f, 5.49813f },
    { 5682.22f, 4111.31f, 156.463f, 5.50598f },
    { 5677.46f, 4115.85f, 156.463f, 5.52169f },
    { 5673.45f, 4120.05f, 156.463f, 5.47849f },
    { 5669.77f, 4124.17f, 156.463f, 5.68269f },
};

enum Spells
{
    // Stage One
    SPELL_DISCHARGE_VISUAL = 134820,
    SPELL_DISCHARGE_DAMAGE_AND_STACKS = 134821,

    SPELL_DECAPITATE_MARKER = 135000,
    SPELL_DECAPITATE_MARKER_VISUAL = 134912,
    SPELL_DECAPITATE_MISSILE = 134990,

    SPELL_THUNDERSTRUCK = 135095,

    SPELL_CRASHING_THUNDER = 135150,
    SPELL_CRASHING_THUNDER_DOT = 135153,

    // Stage Two
    SPELL_FUSION_SLASH = 136478,

    SPELL_LIGHTNING_WHIP = 136850,

    SPELL_SUMMON_BALL_LIGHTNING = 136543,

    // Stage Three
    SPELL_OVERWHELMING_POWER = 136913,

    SPELL_VIOLENT_GALE_WINDS = 136889,

    // Intermissions
    SPELL_HELM_OF_COMMAND = 139011,
    SPELL_OVERLOADED_CIRCUITS = 137176,
    SPELL_SUPERCHARGE_CONDUITS = 137045,

    // Power bar
    SPELL_PB_OVERCHARGE = 139272,
    SPELL_PB_STATIC_SHOCK = 139271,
    SPELL_PB_BOUNCING_BOLT = 137581,
    SPELL_PB_DIFFUSION_CHAIN = 139273,

    SPELL_PB_PLAYER = 137607,

    // Conduits
    // North Conduit -> Static Shock
    SPELL_STATIC_SHOCK = 135695,

    // South Conduit -> Overcharge
    SPELL_LEI_SHEN_OVERCHARGE = 135682,

    SPELL_OVERCHARGED = 136295, // main spell
    SPELL_OVERCHARGE = 136326, // if player was hit by OVERCHARGED 

    // West Conduit -> Bouncing Bolt
    SPELL_LEI_SHEN_BOUNCING_BOLT = 135683,

    SPELL_BOUNCING_BOLT_MISSILE = 136361, //near
    SPELL_BOUNCING_BOLT_MISSILE_FARTHEST = 138706, // used in intermission
    SPELL_BOUNCING_BOLT_SUMMON = 136372,

    // East Conduit -> Diffusion Chain
    SPELL_LEI_SHEN_DIFFUSION_CHAIN = 135681,

    SPELL_DIFFUSION_CHAIN_SUMMON_LOW = 135992, // when power is 1
    SPELL_DIFFUSION_CHAIN_SUMMON_MINOR = 135993, // when power is 2
    SPELL_DIFFUSION_CHAIN_SUMMON_BIG = 135994, // when power is 3
    SPELL_DIFFUSION_CHAIN_DAMAGE = 135991,

    // Miscs
    // more visuals: 138974 bot
    SPELL_PILLAR_VISUALS = 134843, // for conduits 
    SPELL_PILLAR_ON_LEISHEN = 134803,

    //adds
    SPELL_CHAIN_LIGHTNING_DIFFUSION = 136018,
};

enum Creatures
{
    NPC_STATIC_SHOCK_CONDUIT = 68398,
    NPC_DIFFUSION_CHAIN_CONDUIT = 68696,
    NPC_OVERCHARGE_CONDUIT = 68697,
    NPC_BOUNCING_BOLT_CONDUIT = 68698,
    NPC_LESSER_DIFFUSED_LIGHTNING = 69012,
    NPC_DIFFUSED_LIGHTNING = 69013,
    NPC_GREATER_DIFFUSED_LIGHTNING = 69014,
    NPC_UNHARNESSED_POWER = 69133,
    NPC_BALL_LIGHTNING = 69462,

    NPC_OVERLOADED_CIRCUITS = 999277,
};

enum Miscs
{
    GO_FLOOR_NORTH = 218420,
    GO_FLOOR_SOUTH = 218419,
    GO_FLOOR_EAST = 218422,
    GO_FLOOR_WEST = 218421,

    GO_INTERMISSION = 218397,
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_THUNDERSTRUCK,
    EVENT_CRASHING_THUNDER,
    EVENT_DIFFUSION_CHAIN_PILLAR_EVENT,
    EVENT_DECAPITATE,
    EVENT_RUSH_PLAYER,
    EVENT_HELM_OF_COMMAND,
    EVENT_FIXATE_PLAYER,
    EVENT_SUMMON_BALL_LIGHTNING,
    EVENT_INTERMISSION_PILLARS,
    EVENT_STATIC_SHOCK_PILLAR_EVENT,
    EVENT_OVERCHARGED_PILLAR_EVENT,
    EVENT_BOUNCE_AGAIN,
    EVENT_LIGHTNING_WHIP,
    EVENT_DECAPITATE_SPELL,
    EVENT_TELEPORT_TO_PILLARS,
    EVENT_RETURN_TO_COMBAT,
    EVENT_OBJECT_VISUAL,
    EVENT_VIOLENT_GALE_WINDS,
    EVENT_BOUNCING_BALL_PILLAR_EVENT,
    EVENT_STATIC_SHOCK_DISABLED,
    EVENT_INTERMISSION_PILLARS_3,
    EVENT_INTERMISSION_PILLARS_4,
    EVENT_OVERCHARGED_DISABLED,
    EVENT_BOUNCING_BALL_DISABLED,
    EVENT_DIFFUSION_CHAIN_DISABLED,
    EVENT_INTERMISSION_PILLARS_2,
    EVENT_FUSION_FLASH,

    EVENT_BEGIN_PHASE_2,
    EVENT_BEGIN_PHASE_3,

    EVENT_KILL_PLAYERS_WITHOUT_PLATFORM,
};

enum Timers
{
    TIMER_BERSERK = 12 * IN_MILLISECONDS * MINUTE,

    TIMER_THUNDERSTRUCK = 25 * IN_MILLISECONDS,
    TIMER_THUNDERSTRUCK_SECOND = 45 * IN_MILLISECONDS,

    TIMER_CRASHING_THUNDER = 27 * IN_MILLISECONDS,

    TIMER_DECAPITATE = 40 * IN_MILLISECONDS,
    TIMER_DECAPITATE_SPELL = 5 * IN_MILLISECONDS,

    TIMER_CONDUIT_ABILITY = 35 * IN_MILLISECONDS,

    TIMER_SUMMON_BALL_LIGHTNING = 18 * IN_MILLISECONDS,
    TIMER_SUMMON_BALL_LIGHTNING_SECOND = 45 * IN_MILLISECONDS,

    TIMER_LIGHTNING_WHIP = 45 * IN_MILLISECONDS,
    TIMER_FUSION_FLASH = 1 * IN_MILLISECONDS * MINUTE,

    TIMER_VIOLENT_GALE_WINDS = 30 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_LEI_SHEN_NEAR_PILLAR = 1,
    ACTION_LEI_SHEN_NOT_NEAR_PILLAR = 2,
};

enum StaticShockEvents
{
    EVENT_CHECK_LEI_SHEN = 1,
    EVENT_ADD_POWERS = 2,
    EVENT_CHECK_POWER = 3,
};

enum PillarsActions
{
    ACTION_STATIC_SHOCK_ON = 1,
    ACTION_STATIC_SHOCK_OFF = 2,

    ACTION_OVERCHARGE_CONDUIT_ON = 3,
    ACTION_OVERCHARGE_OFF = 4,

    ACTION_DIFFUSION_ON = 5,
    ACTION_DIFFUSION_OFF = 6,

    ACTION_BOUNCING_ON = 7,
    ACTION_BOUNCING_OFF = 8,

    // pillars actions, acting for lei shen (req spellscripts)
    ACTION_STATIC_SHOCK_PILLAR_ON = 9,
    ACTION_STATIC_SHOCK_PILLAR_OFF = 10,

    ACTION_OVERCHARGE_PILLAR_OFF = 11,
    ACTION_OVERCHARGE_PILLAR_ON = 12,

    ACTION_BOUNCING_BOLT_PILLAR_OFF = 13,
    ACTION_BOUNCING_BOLT_PILLAR_ON = 14,

    ACTION_DIFFUSION_CHAIN_PILLAR_ON = 15,
    ACTION_DIFFUSION_CHAIN_PILLAR_OFF = 16,

    ACTION_STATIC_SHOCK_DISABLED = 17,
    ACTION_DIFFUSION_CHAIN_DISABLED = 18,
    ACTION_OVERCHARGED_DISABLED = 19,
    ACTION_BOUNCING_BALL_DISABLED = 20,
};

enum ObjectVisuals
{
    FLOOR_POWER_SHUT_DOWN = 3704, // used on JustDied
    FLOOR_POWER_CONDUIT_ELECTRIFIED = 3702, // used on conduit which has been "destroyed"
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_THUNDERSTRUCK = 2,
    TALK_LIGHTNING_WHIP = 3,
    TALK_GALE_WINDS = 4,
    TALK_P2 = 5,
    TALK_P3 = 6,
    TALK_DEATH = 7,
};
struct notValidSpec : public std::unary_function<Unit*, bool>
{
    notValidSpec() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_CAT)
            || (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ENHANCEMENT)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_ARMS)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_FURY)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_FROST)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_UNHOLY)
            || (player->getClass() == CLASS_ROGUE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BATTLEDANCER)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_HOLY));
    }
};

struct isDecapitated : public std::unary_function<Unit*, bool>
{
    isDecapitated() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_DECAPITATE_MARKER);
    }
};

struct alreadyDisable : public std::unary_function<Unit*, bool>
{
    alreadyDisable() {}

    bool operator() (const Unit* target)
    {
        return target->isDead();
    }
};

struct hasHelmActive : public std::unary_function<Unit*, bool>
{
    hasHelmActive() {}

    bool operator() (const Unit* target)
    {
        return target->HasAura(SPELL_HELM_OF_COMMAND);
    }
};

struct TargetIsGm : public std::unary_function<Unit*, bool>
{
    TargetIsGm() {}

    bool operator() (const Unit* target)
    {
        Player* player = const_cast<Player*>(target->ToPlayer());
        return player->IsGameMaster();
    }
};

class CheckIfMeleeRange
{
public:
    CheckIfMeleeRange(Unit* finder) : _finder(finder) {}

    bool operator()(WorldObject* target)
    {
        return _finder->GetDistance(target) <= 10.0f;
    }

private:
    Unit* _finder;
};

class bfa_boss_lei_shen : public CreatureScript
{
public:
    bfa_boss_lei_shen() : CreatureScript("bfa_boss_lei_shen") { }

    struct bfa_boss_lei_shenAI : public ScriptedAI
    {
        bfa_boss_lei_shenAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // clash
        }

        EventMap events;
        EventMap OOCEvents;
        EventMap BerserkEvents;
        bool firstPhase;
        uint8 update;
        bool secondPhase;
        uint8 thunders;
        bool sight;
        bool notIntermission;
        uint8 teleport;
        InstanceScript* instance;

        void Reset()
        {
            thunders = 0;
            ResetConduitViaPakcet();
            events.Reset();
            OOCEvents.Reset();
            teleport = 0;
            BerserkEvents.Reset();
            update = 0;
            firstPhase = false;
            sight = false;
            RemovePowerBarPlayers();
            secondPhase = false;
            notIntermission = false;
            ActivateObjectsIntermission();
            RespawnConduitsAtWipe();
            DeactivatePillars();
            me->SetReactState(REACT_AGGRESSIVE);
            DespawnCreature(NPC_BALL_LIGHTNING);
            DespawnCreature(NPC_DIFFUSED_LIGHTNING);
            DespawnCreature(NPC_LESSER_DIFFUSED_LIGHTNING);
            RemoveEncounterFrame(NPC_OVERCHARGE_CONDUIT);
            RemoveEncounterFrame(NPC_STATIC_SHOCK_CONDUIT);
            DespawnCreature(NPC_OVERLOADED_CIRCUITS);
            RemoveEncounterFrame(NPC_BOUNCING_BOLT_CONDUIT);
            RemoveEncounterFrame(NPC_DIFFUSION_CHAIN_CONDUIT);
            DespawnCreature(NPC_GREATER_DIFFUSED_LIGHTNING);
            DespawnCreature(NPC_UNHARNESSED_POWER);
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            if (instance)
                instance->SetBossState(DATA_LEI_SHEN, NOT_STARTED);
        }

        void ActivatePillars()
        {
            if (Creature* staticshock = GetStaticShock())
                staticshock->AI()->DoAction(ACTION_STATIC_SHOCK_ON);
            if (Creature* overcharge = GetOvercharge())
                overcharge->AI()->DoAction(ACTION_OVERCHARGE_CONDUIT_ON);
            if (Creature* diffusionchain = GetDiffusionChain())
                diffusionchain->AI()->DoAction(ACTION_DIFFUSION_ON);
            if (Creature* bouncingball = GetBouncingBall())
                bouncingball->AI()->DoAction(ACTION_BOUNCING_ON);
        }

        void DeactivatePillars()
        {
            if (Creature* staticshock = GetStaticShock())
                staticshock->AI()->DoAction(ACTION_STATIC_SHOCK_OFF);
            if (Creature* overcharge = GetOvercharge())
                overcharge->AI()->DoAction(ACTION_OVERCHARGE_OFF);
            if (Creature* diffusionchain = GetDiffusionChain())
                diffusionchain->AI()->DoAction(ACTION_DIFFUSION_OFF);
            if (Creature* bouncingball = GetBouncingBall())
                bouncingball->AI()->DoAction(ACTION_BOUNCING_OFF);
        }

        Creature* GetStaticShock()
        {
            return me->FindNearestCreature(NPC_STATIC_SHOCK_CONDUIT, 500.0f, true);
        }

        Creature* GetBouncingBall()
        {
            return me->FindNearestCreature(NPC_BOUNCING_BOLT_CONDUIT, 500.0f, true);
        }

        Creature* GetDiffusionChain()
        {
            return me->FindNearestCreature(NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f, true);
        }

        Creature* GetOvercharge()
        {
            return me->FindNearestCreature(NPC_OVERCHARGE_CONDUIT, 500.0f, true);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        void RemoveEncounterFrame(uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    (*summs)->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, (*summs)); // Remove
        }

        void EnterEvadeMode(EvadeReason)
        {

            ResetConduitViaPakcet();
            RemoveEncounterFrame(NPC_OVERCHARGE_CONDUIT);
            RemoveEncounterFrame(NPC_STATIC_SHOCK_CONDUIT);
            RespawnConduitsAtWipe();
            RemoveEncounterFrame(NPC_BOUNCING_BOLT_CONDUIT);
            DespawnCreature(NPC_OVERLOADED_CIRCUITS);
            RemoveEncounterFrame(NPC_DIFFUSION_CHAIN_CONDUIT);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (instance)
                instance->SetBossState(DATA_LEI_SHEN, FAIL);
        }

        void EnterCombat(Unit*)
        {
            BerserkEvents.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);
            DespawnCreature(NPC_UNHARNESSED_POWER);
            ActivatePillars();
            RemovePowerBarPlayers();
            RespawnConduitsAtWipe();
            OOCEvents.CancelEvent(EVENT_TELEPORT_TO_PILLARS);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_KILL_PLAYERS_WITHOUT_PLATFORM, 1000);
            events.ScheduleEvent(EVENT_DECAPITATE, TIMER_DECAPITATE);
            events.ScheduleEvent(EVENT_THUNDERSTRUCK, TIMER_THUNDERSTRUCK);
            events.ScheduleEvent(EVENT_CRASHING_THUNDER, TIMER_CRASHING_THUNDER);
            if (instance)
                instance->SetBossState(DATA_LEI_SHEN, IN_PROGRESS);
            Talk(TALK_AGGRO);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void ActivateObjectsIntermission()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            me->GetGameObjectListWithEntryInGrid(gList, GO_INTERMISSION, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void RemovePowerBarPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_PB_PLAYER);
                }
        }

        void DeactivateObjectsIntermission()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void PadActive()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_INTERMISSION, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void ShutdownConduits()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                {
                   // PacketHandler::Misc::SendClientGameObjectActivateAnimKit(me, (*itr)->GetGUID(), 0, true); // if the object already has the "destroyed" visual, remove it then add shutdown
                    //PacketHandler::Misc::SendClientGameObjectActivateAnimKit(me, (*itr)->GetGUID(), FLOOR_POWER_SHUT_DOWN, true);
                }
        }

        void ResetConduitViaPakcet()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr);
                    //PacketHandler::Misc::SendClientGameObjectActivateAnimKit(me, (*itr)->GetGUID(), 0, true);
        }

        void JustDied(Unit*)
        {
            if (GameObject* object = me->FindNearestGameObject(218553, 1000.0f))
            {
                object->SetLootState(GO_READY);
                object->UseDoorOrButton();
            }
            me->SummonCreature(999687, 5741.569336f, 4130.277832f, 156.463f, 3.17f, TEMPSUMMON_MANUAL_DESPAWN);
            ShutdownConduits();
            DespawnCreature(NPC_BALL_LIGHTNING);
            DespawnCreature(NPC_DIFFUSED_LIGHTNING);
            DespawnCreature(NPC_LESSER_DIFFUSED_LIGHTNING);
            RemoveEncounterFrame(NPC_OVERCHARGE_CONDUIT);
            RemoveEncounterFrame(NPC_STATIC_SHOCK_CONDUIT);
            RemoveEncounterFrame(NPC_BOUNCING_BOLT_CONDUIT);
            RemoveEncounterFrame(NPC_DIFFUSION_CHAIN_CONDUIT);
            DespawnCreature(NPC_GREATER_DIFFUSED_LIGHTNING);
            DespawnCreature(NPC_OVERLOADED_CIRCUITS);
            DespawnCreature(NPC_UNHARNESSED_POWER);
            RemovePowerBarPlayers();
            Talk(TALK_DEATH);
            if (instance)
                instance->SetBossState(DATA_LEI_SHEN, DONE);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            PlayMovie(me);
        }

        void PlayMovie(Creature* me)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->SendCinematicStart(272);
                }
        }

        void RespawnConduitsAtWipe()
        {
            std::list<Creature*> conduits;
            me->GetCreatureListWithEntryInGrid(conduits, NPC_BOUNCING_BOLT_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_STATIC_SHOCK_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_OVERCHARGE_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f);

            if (conduits.empty())
                return;

            for (auto pillar : conduits)
            {
                if (pillar->isDead())
                    pillar->Respawn();
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HasAura(SPELL_SUPERCHARGE_CONDUITS))
                damage = 0;

            if (me->HealthBelowPct(65) && !firstPhase)
            {
                firstPhase = true;
                notIntermission = true;
                me->RemoveAura(SPELL_DISCHARGE_VISUAL);
                events.Reset();
                me->NearTeleportTo(5710.26f, 4094.13f, 156.46f, 0.79f, false);
                update = 0;
                //me->GetMotionMaster()->MoveJump(5710.14f, 4094.36f, 156.46f, 20.0f, 20.0f);
                float ori = 0.75f;
                me->SetOrientation(ori);
                //DeactivateObjectsIntermission();
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                PadActive();
                SuperchargeConduits();
                Talk(TALK_P2);
                me->CastSpell(me, SPELL_SUPERCHARGE_CONDUITS);
                events.ScheduleEvent(EVENT_OBJECT_VISUAL, 3000);
                events.ScheduleEvent(EVENT_HELM_OF_COMMAND, 10000);
                events.ScheduleEvent(EVENT_INTERMISSION_PILLARS, 4000);
                events.ScheduleEvent(EVENT_BEGIN_PHASE_2, 45 * IN_MILLISECONDS);
                std::vector<uint32> conduitSpells;
                conduitSpells.push_back(135682);
                conduitSpells.push_back(135683);
                conduitSpells.push_back(135681);
                conduitSpells.push_back(135680);

                for (std::vector<uint32>::const_iterator itr = conduitSpells.begin(); itr != conduitSpells.end(); ++itr)
                    me->RemoveAurasDueToSpell((*itr));
            }

            if (me->HealthBelowPct(30) && !secondPhase)
            {
                secondPhase = true;
                notIntermission = true;
                me->RemoveAura(SPELL_DISCHARGE_VISUAL);
                events.Reset();
                Talk(TALK_P3);
                me->NearTeleportTo(5710.26f, 4094.13f, 156.46f, 0.79f, false);
                //me->GetMotionMaster()->MoveJump(5710.14f, 4094.36f, 156.46f, 25.0f, 30.0f);
                float ori = 0.75f;
                me->SetOrientation(ori);
                //DeactivateObjectsIntermission();
                update = 0;
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                PadActive();
                events.ScheduleEvent(EVENT_HELM_OF_COMMAND, 10000);
                events.ScheduleEvent(EVENT_INTERMISSION_PILLARS, 4000);
                events.ScheduleEvent(EVENT_OBJECT_VISUAL, 3000);
                me->CastSpell(me, SPELL_SUPERCHARGE_CONDUITS);
                events.ScheduleEvent(EVENT_BEGIN_PHASE_3, 45 * IN_MILLISECONDS);

                std::vector<uint32> conduitSpells;
                conduitSpells.push_back(135682);
                conduitSpells.push_back(135683);
                conduitSpells.push_back(135681);
                conduitSpells.push_back(135680);

                for (std::vector<uint32>::const_iterator itr = conduitSpells.begin(); itr != conduitSpells.end(); ++itr)
                    me->RemoveAurasDueToSpell((*itr));
            }
        }

        void SuperchargeConduits() // +1 alt power..
        {
            std::list<Creature*> conduits;
            me->GetCreatureListWithEntryInGrid(conduits, NPC_BOUNCING_BOLT_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_STATIC_SHOCK_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_OVERCHARGE_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f);

            if (!conduits.empty())
                for (std::list<Creature*>::iterator itr = conduits.begin(); itr != conduits.end(); ++itr)
                {
                    if (Creature* pillar = (*itr)->ToCreature())
                    {
                        pillar->SetPower(POWER_ALTERNATE_POWER, pillar->GetPower(POWER_ALTERNATE_POWER) + 1);
                    }
                }
        }

        void DisableConduitWithMostEnergyAndStacks()
        {
            std::list<Creature*> conduits;
            me->GetCreatureListWithEntryInGrid(conduits, NPC_BOUNCING_BOLT_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_STATIC_SHOCK_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_OVERCHARGE_CONDUIT, 500.0f);
            me->GetCreatureListWithEntryInGrid(conduits, NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f);

            conduits.remove_if(alreadyDisable());

            int32 powerPoints = 0;
            Creature* Goodpillar = NULL;
            if (!conduits.empty())
                for (std::list<Creature*>::iterator itr = conduits.begin(); itr != conduits.end(); ++itr)
                    if (Creature* pillar = (*itr)->ToCreature())
                    {
                        if (pillar->GetPower(POWER_ENERGY) > powerPoints)
                        {
                            powerPoints = pillar->GetPower(POWER_ENERGY);
                            Goodpillar = pillar;
                        }
                    }

            if (Goodpillar)
                Goodpillar->Kill(Goodpillar);
        }

        void DoAction(int32 action)
        {
            if (secondPhase)
                return;

            switch (action)
            {
            case ACTION_LEI_SHEN_NEAR_PILLAR:
                me->RemoveAura(SPELL_DISCHARGE_VISUAL);
                break;
            case ACTION_LEI_SHEN_NOT_NEAR_PILLAR:
                if (!notIntermission)
                {
                    me->AddAura(SPELL_DISCHARGE_VISUAL, me);
                }
                break;
            case ACTION_STATIC_SHOCK_PILLAR_ON:
                events.ScheduleEvent(EVENT_STATIC_SHOCK_PILLAR_EVENT, 15000);
                break;
            case ACTION_STATIC_SHOCK_PILLAR_OFF:
                events.CancelEvent(EVENT_STATIC_SHOCK_PILLAR_EVENT);
                break;
            case ACTION_BOUNCING_BOLT_PILLAR_OFF:
                events.CancelEvent(EVENT_BOUNCING_BALL_PILLAR_EVENT);
                break;
            case ACTION_BOUNCING_BOLT_PILLAR_ON:
                events.ScheduleEvent(EVENT_BOUNCING_BALL_PILLAR_EVENT, 15000);
                break;
            case ACTION_OVERCHARGE_PILLAR_OFF:
                events.CancelEvent(EVENT_OVERCHARGED_PILLAR_EVENT);
                break;
            case ACTION_OVERCHARGE_PILLAR_ON:
                events.ScheduleEvent(EVENT_OVERCHARGED_PILLAR_EVENT, 15000);
                break;
            case ACTION_DIFFUSION_CHAIN_PILLAR_ON:
                events.ScheduleEvent(EVENT_DIFFUSION_CHAIN_PILLAR_EVENT, 20000);
                break;
            case ACTION_DIFFUSION_CHAIN_PILLAR_OFF:
                events.CancelEvent(EVENT_DIFFUSION_CHAIN_PILLAR_EVENT);
                break;
            case ACTION_STATIC_SHOCK_DISABLED:
                events.ScheduleEvent(EVENT_STATIC_SHOCK_DISABLED, 40 * IN_MILLISECONDS);
                break;
            case ACTION_DIFFUSION_CHAIN_DISABLED:
                events.ScheduleEvent(EVENT_DIFFUSION_CHAIN_DISABLED, 40 * IN_MILLISECONDS);
                break;
            case ACTION_BOUNCING_BALL_DISABLED:
                events.ScheduleEvent(EVENT_BOUNCING_BALL_DISABLED, 40 * IN_MILLISECONDS);
                break;
            case ACTION_OVERCHARGED_DISABLED:
                events.ScheduleEvent(EVENT_OVERCHARGED_DISABLED, 40 * IN_MILLISECONDS);
                break;
            }
        }

        void CastStaticShockLevel1()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 1, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    me->CastSpell(*itr, SPELL_STATIC_SHOCK, true);
                }
        }

        void CastStaticShockLevel2()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 2, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    me->CastSpell(*itr, SPELL_STATIC_SHOCK, true);
                }
        }

        void CastStaticShockLevel3()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 3, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    me->CastSpell(*itr, SPELL_STATIC_SHOCK, true);
                }
        }

        void CastOverchargedLevel1()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 1, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            players.remove_if(hasHelmActive());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    (*itr)->AddAura(SPELL_OVERCHARGED, *itr);
                }
        }

        void CastOverchargedLevel2()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 2, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            players.remove_if(hasHelmActive());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    (*itr)->AddAura(SPELL_OVERCHARGED, *itr);
                }
        }


        void CastOverchargedLevel3()
        {
            std::list<Unit*> players;
            SelectTargetList(players, 3, SELECT_TARGET_RANDOM, 300.0f, true);
            players.remove_if(notValidSpec());
            players.remove_if(hasHelmActive());
            if (!players.empty())
                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    (*itr)->AddAura(SPELL_OVERCHARGED, *itr);
                }
        }

        void CastBouncingBallLevel1()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
        }

        void CastBouncingBallLevel2()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
        }

        void CastBouncingBallLevel3()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE, true);
        }

        void CastBouncingBallIntermissionLevel1()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
        }

        void CastBouncingBallIntermissionLevel2()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
        }

        void CastBouncingBallIntermissionLevel3()
        {
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
            me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE_FARTHEST, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER && who->IsAlive() && who->GetDistance(me) < 80.0f)
            {
                if (!sight)
                {
                    sight = true;
                    OOCEvents.ScheduleEvent(EVENT_TELEPORT_TO_PILLARS, 5000);
                }
            }
        }

        void UpdateAI(uint32 diff)
        {

            events.Update(diff);
            OOCEvents.Update(diff);
            BerserkEvents.Update(diff);

            switch (OOCEvents.ExecuteEvent())
            {
            case EVENT_TELEPORT_TO_PILLARS:
            {
                ++teleport;
                if (teleport == 1)
                    me->NearTeleportTo(PillarPosition[0].GetPositionX(), PillarPosition[0].GetPositionY(), PillarPosition[0].GetPositionZ(), PillarPosition[0].GetOrientation(), true);
                else
                    if (teleport == 2)
                        me->NearTeleportTo(PillarPosition[1].GetPositionX(), PillarPosition[1].GetPositionY(), PillarPosition[1].GetPositionZ(), PillarPosition[1].GetOrientation(), true);
                    else
                        if (teleport == 3)
                            me->NearTeleportTo(PillarPosition[2].GetPositionX(), PillarPosition[2].GetPositionY(), PillarPosition[2].GetPositionZ(), PillarPosition[2].GetOrientation(), true);
                        else
                            if (teleport == 4)
                            {
                                me->NearTeleportTo(PillarPosition[3].GetPositionX(), PillarPosition[3].GetPositionY(), PillarPosition[3].GetPositionZ(), PillarPosition[3].GetOrientation(), true);
                                teleport = 0;
                            }
                OOCEvents.ScheduleEvent(EVENT_TELEPORT_TO_PILLARS, 30000);
                break;
            }
            }

            switch (BerserkEvents.ExecuteEvent())
            {
            case EVENT_BERSERK:
                me->AddAura(SPELL_BERSERK, me);
                break;
            }

            if (!UpdateVictim())
                return;


            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_OBJECT_VISUAL:
                    DeactivateObjectsIntermission();
                    break;
                case EVENT_STATIC_SHOCK_PILLAR_EVENT:
                {
                    if (Creature* northPillar = GetStaticShock())
                    {
                        if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastStaticShockLevel1();
                        else if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastStaticShockLevel2();
                        else if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastStaticShockLevel3();
                    }
                    events.ScheduleEvent(EVENT_STATIC_SHOCK_PILLAR_EVENT, 35 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_OVERCHARGED_PILLAR_EVENT:
                {
                    if (Creature* southPillar = GetOvercharge())
                    {
                        if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastOverchargedLevel1();
                        else if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastOverchargedLevel2();
                        else if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastOverchargedLevel3();
                    }
                    events.ScheduleEvent(EVENT_OVERCHARGED_PILLAR_EVENT, 30 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_BOUNCING_BALL_PILLAR_EVENT:
                {
                    if (Creature* bouncingPillar = GetBouncingBall())
                    {
                        if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastBouncingBallLevel1();
                        else if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastBouncingBallLevel2();
                        else if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastBouncingBallLevel3();
                    }
                    events.ScheduleEvent(EVENT_BOUNCING_BALL_PILLAR_EVENT, 35 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_DIFFUSION_CHAIN_PILLAR_EVENT:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_DIFFUSION_CHAIN_DAMAGE);
                    events.ScheduleEvent(EVENT_DIFFUSION_CHAIN_PILLAR_EVENT, 40 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_BEGIN_PHASE_2:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    DisableConduitWithMostEnergyAndStacks();
                    notIntermission = false;
                    if (Unit* target = me->GetVictim())
                        me->AI()->AttackStart(target);
                    ActivateObjectsIntermission();
                    events.CancelEvent(EVENT_HELM_OF_COMMAND);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_3);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_4);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_2);
                    events.ScheduleEvent(EVENT_FUSION_FLASH, TIMER_FUSION_FLASH);
                    events.ScheduleEvent(EVENT_SUMMON_BALL_LIGHTNING, TIMER_SUMMON_BALL_LIGHTNING);
                    events.ScheduleEvent(EVENT_LIGHTNING_WHIP, TIMER_LIGHTNING_WHIP);
                    break;
                case EVENT_BEGIN_PHASE_3:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    notIntermission = false;
                    DisableConduitWithMostEnergyAndStacks();
                    if (Unit* target = me->GetVictim())
                        me->AI()->AttackStart(target);
                    ActivateObjectsIntermission();
                    events.CancelEvent(EVENT_HELM_OF_COMMAND);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_3);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_4);
                    events.CancelEvent(EVENT_INTERMISSION_PILLARS_2);
                    events.CancelEvent(EVENT_FUSION_FLASH);
                    events.CancelEvent(EVENT_LIGHTNING_WHIP);
                    events.CancelEvent(EVENT_SUMMON_BALL_LIGHTNING);
                    events.ScheduleEvent(EVENT_THUNDERSTRUCK, TIMER_THUNDERSTRUCK);
                    events.ScheduleEvent(EVENT_SUMMON_BALL_LIGHTNING, TIMER_SUMMON_BALL_LIGHTNING);
                    events.ScheduleEvent(EVENT_LIGHTNING_WHIP, TIMER_LIGHTNING_WHIP);
                    events.ScheduleEvent(EVENT_VIOLENT_GALE_WINDS, TIMER_VIOLENT_GALE_WINDS);
                    me->CastSpell(me, SPELL_OVERWHELMING_POWER);
                    break;
                case EVENT_DECAPITATE:
                    me->CastSpell(me->GetVictim(), SPELL_DECAPITATE_MARKER_VISUAL, true);
                    me->CastSpell(me->GetVictim(), SPELL_DECAPITATE_MARKER, true);
                    events.ScheduleEvent(EVENT_DECAPITATE_SPELL, TIMER_DECAPITATE_SPELL);
                    events.ScheduleEvent(EVENT_DECAPITATE, 40 * IN_MILLISECONDS);
                    break;
                case EVENT_DECAPITATE_SPELL:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_DECAPITATE_MISSILE);

                    break;
                }
                case EVENT_FUSION_FLASH:
                    if (secondPhase)
                        return; // to be sure
                    me->CastSpell(me->GetVictim(), SPELL_FUSION_SLASH);
                    events.ScheduleEvent(EVENT_FUSION_FLASH, TIMER_FUSION_FLASH);
                    break;
                case EVENT_THUNDERSTRUCK:
                    Talk(TALK_THUNDERSTRUCK);

                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                        if (!targets.empty())
                            if (targets.size() >= 1)
                                targets.resize(1);

                        for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->StopMoving();
                            std::ostringstream str;
                            str << "Lei Shen begins to cast |cFFF00000|Hspell:135095|h[Thunderstruck]|h|r on " << (*itr)->GetName() << "! Run !";
                            me->TextEmote(str.str().c_str(), 0, true);
                            if (Creature* trigger = me->SummonCreature(60942, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 8000))
                            {
                                trigger->SetDisplayId(11686);
                                trigger->SetObjectScale(2.0f);
                                me->AddAura(123795, trigger);
                                me->SetFacingToObject(trigger);
                                me->AddThreat(trigger, 9.9999999f);
                                me->CastSpell(trigger, SPELL_THUNDERSTRUCK);
                            }
                        }
                    }

                    events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 5000);
                    events.ScheduleEvent(EVENT_THUNDERSTRUCK, TIMER_THUNDERSTRUCK_SECOND);
                    break;
                case EVENT_CRASHING_THUNDER:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_CRASHING_THUNDER, true);
                    CountThunder();
                    break;
                }
                case EVENT_LIGHTNING_WHIP:
                {
                    Talk(TALK_LIGHTNING_WHIP);
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        std::ostringstream str;
                        str << "Lei Shen begins to cast |cFFF00000|Hspell:136850|h[Lightning Whip]|h|r on " << (*itr)->GetName() << "!";
                        me->TextEmote(str.str().c_str(), 0, true);
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        if (Creature* trigger = me->SummonCreature(60942, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 8000))
                        {
                            me->SetFacingToObject(trigger);
                            me->AddThreat(trigger, 9.9999999f);
                            me->CastSpell(trigger, SPELL_LIGHTNING_WHIP);
                        }
                    }
                    events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 5000);
                    events.ScheduleEvent(EVENT_LIGHTNING_WHIP, TIMER_LIGHTNING_WHIP);
                    break;
                }
                case EVENT_RETURN_TO_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_SUMMON_BALL_LIGHTNING:
                {
                    /*freakzUnitList players;
                    SelectTargetList(players, Is25ManRaid() ? 4 : 8, SELECT_TARGET_RANDOM, 300.0f, true);
                    players.remove_if(notValidSpec());
                    if (!players.empty())
                    for (freakzUnitList::iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                    me->CastSpell(*itr, SPELL_SUMMON_BALL_LIGHTNING, true);
                    }*/
                    HandleBallofLightning();
                    events.ScheduleEvent(EVENT_SUMMON_BALL_LIGHTNING, TIMER_SUMMON_BALL_LIGHTNING_SECOND);
                    break;
                }
                case EVENT_VIOLENT_GALE_WINDS:
                    Talk(TALK_GALE_WINDS);
                    me->CastSpell(me, 136869, true);
                    events.ScheduleEvent(EVENT_VIOLENT_GALE_WINDS, TIMER_VIOLENT_GALE_WINDS);
                    break;
                case EVENT_KILL_PLAYERS_WITHOUT_PLATFORM:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetPositionZ() < 155.25f)
                            {
                                player->Kill(player, true);
                            }
                        }
                    events.ScheduleEvent(EVENT_KILL_PLAYERS_WITHOUT_PLATFORM, 1000);
                    break;
                }
                case EVENT_STATIC_SHOCK_DISABLED:
                    CastStaticShockLevel1();
                    events.ScheduleEvent(EVENT_STATIC_SHOCK_DISABLED, 40 * IN_MILLISECONDS);
                    break;
                case EVENT_DIFFUSION_CHAIN_DISABLED:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_DIFFUSION_CHAIN_DAMAGE);
                    events.ScheduleEvent(EVENT_DIFFUSION_CHAIN_DISABLED, 40 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_BOUNCING_BALL_DISABLED:
                    CastBouncingBallLevel1();
                    events.ScheduleEvent(EVENT_BOUNCING_BALL_DISABLED, 40 * IN_MILLISECONDS);
                    break;
                case EVENT_OVERCHARGED_DISABLED:
                    CastOverchargedLevel1();
                    events.ScheduleEvent(EVENT_OVERCHARGED_DISABLED, 40 * IN_MILLISECONDS);
                    break;
                case EVENT_HELM_OF_COMMAND:
                {
                    if (me->GetMap()->IsHeroic())
                    {
                        std::list<Unit*> players;
                        SelectTargetList(players, Is25ManRaid() ? 3 : 1, SELECT_TARGET_RANDOM, 300.0f, true);
                        if (!players.empty())
                            for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                me->CastSpell(*itr, SPELL_HELM_OF_COMMAND, true);
                            }
                    }
                    events.ScheduleEvent(EVENT_HELM_OF_COMMAND, 20000);
                    break;
                }
                case EVENT_INTERMISSION_PILLARS:
                {
                    ++update;
                    if (update > 2)
                        return;
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_DIFFUSION_CHAIN_DAMAGE);
                    events.ScheduleEvent(EVENT_INTERMISSION_PILLARS_2, 2500);
                    break;
                }
                case EVENT_INTERMISSION_PILLARS_2:
                {
                    if (Creature* southPillar = GetOvercharge())
                    {
                        if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastOverchargedLevel1();
                        else if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastOverchargedLevel2();
                        else if (southPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastOverchargedLevel3();
                    }
                    events.ScheduleEvent(EVENT_INTERMISSION_PILLARS_3, 6000);
                    break;
                }
                case EVENT_INTERMISSION_PILLARS_3:
                {
                    if (Creature* bouncingPillar = GetBouncingBall())
                    {
                        if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastBouncingBallIntermissionLevel1();
                        else if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastBouncingBallIntermissionLevel2();
                        else if (bouncingPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastBouncingBallIntermissionLevel3();
                    }
                    events.ScheduleEvent(EVENT_INTERMISSION_PILLARS_4, 4500);
                    break;
                }
                case EVENT_INTERMISSION_PILLARS_4:
                {
                    if (Creature* northPillar = GetStaticShock())
                    {
                        if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                            CastStaticShockLevel1();
                        else if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                            CastStaticShockLevel2();
                        else if (northPillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                            CastStaticShockLevel3();
                    }
                    events.ScheduleEvent(EVENT_INTERMISSION_PILLARS, 9 * IN_MILLISECONDS);
                    events.DelayEvents(1500);
                    break;
                }
                }
            }
            if (!me->HasAura(SPELL_SUPERCHARGE_CONDUITS))
                DoMeleeAttackIfReady();
        }

        void HandleBallofLightning()
        {
            std::list<Unit*> players;
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->IsAlive() && !player->IsGameMaster())
                        players.push_back(player);

            players.remove_if(CheckIfMeleeRange(me));
            players.remove_if(notValidSpec());
            uint32 minim_players = 3;
            uint32 maxim_players = 6;

            if (players.size())
            {
                if (players.size() > maxim_players)
                    Trinity::Containers::RandomResize(players, maxim_players);
                else
                    if (players.size() < minim_players)
                        Trinity::Containers::RandomResize(players, minim_players);

                for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    me->CastSpell((*itr), SPELL_SUMMON_BALL_LIGHTNING, true);
                }
            }
        }

        void CountThunder()
        {
            ++thunders;

            if (thunders >= 3)
            {
                events.CancelEvent(EVENT_CRASHING_THUNDER);
                events.ScheduleEvent(EVENT_CRASHING_THUNDER, TIMER_CRASHING_THUNDER);
                thunders = 0;
            }
            else
                events.ScheduleEvent(EVENT_CRASHING_THUNDER, 3000);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_lei_shenAI(creature);
    }
};

#define SAFE_DISTANCE 20.0f

// 135096
class bfa_spell_thunderstruck : public SpellScriptLoader
{
public:
    bfa_spell_thunderstruck() : SpellScriptLoader("bfa_spell_thunderstruck") {}

    class bfa_spell_thunderstruck_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_thunderstruck_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    Creature* trigger = caster->FindNearestCreature(60942, 500.0f, true);
                    float distance = trigger->GetExactDist2d(target);
                    uint32 mindmg = 0, maxdmg = 0;
                    switch (caster->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_25_N:
                        mindmg = 900000;
                        maxdmg = 1000000;
                        break;
                    case DIFFICULTY_10_HC:
                    case DIFFICULTY_25_HC:
                        mindmg = 1500000;
                        maxdmg = 1600000;
                        break;
                    }

                    if (distance > SAFE_DISTANCE)
                        distance = SAFE_DISTANCE;

                    SetHitDamage(((mindmg / -SAFE_DISTANCE) * distance) + maxdmg);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_thunderstruck_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_thunderstruck_SpellScript();
    }
};

class bfa_npc_ball_lightning : public CreatureScript
{
public:
    bfa_npc_ball_lightning() : CreatureScript("bfa_npc_ball_lightning") { }

    struct bfa_npc_ball_lightningAI : public ScriptedAI
    {
        bfa_npc_ball_lightningAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(136534, me); // visual
        }

        EventMap events;

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_RUSH_PLAYER, 6000);
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
                case EVENT_RUSH_PLAYER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                    {
                        me->CastSpell(target, 136620, true); // damage spell
                        me->CastSpell(target, 136548);
                        //me->GetMotionMaster()->MoveChase(target, 50.0f, 50.0f);
                    }
                    events.ScheduleEvent(EVENT_RUSH_PLAYER, 10000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_ball_lightningAI(creature);
    }
};

// 136869
class bfa_spell_violent_gale_winds : public SpellScriptLoader
{
public:
    bfa_spell_violent_gale_winds() : SpellScriptLoader("bfa_spell_violent_gale_winds") {}

    class bfa_spell_violent_gale_winds_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_violent_gale_winds_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint32 spell = 0;
            switch (rand() % 4)
            {
            case 0:
            {
                spell = 136879;
                std::ostringstream str;
                str << "The South doors begins to open, causing |cFFF00000|Hspell:136869|h[Violent Gale Winds]|h|r !";
                caster->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 1:
            {
                spell = 136877;
                std::ostringstream str;
                str << "The East doors begins to open, causing |cFFF00000|Hspell:136869|h[Violent Gale Winds]|h|r !";
                caster->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 2:
            {
                spell = 136876;
                std::ostringstream str;
                str << "The North doors begins to open, causing |cFFF00000|Hspell:136869|h[Violent Gale Winds]|h|r !";
                caster->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 3:
            {
                spell = 136867;
                std::ostringstream str;
                str << "The West doors begins to open, causing |cFFF00000|Hspell:136869|h[Violent Gale Winds]|h|r !";
                caster->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            }

            Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(spell, player);
                    player->AddAura(136889, player);
                }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_violent_gale_winds_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_violent_gale_winds_SpellScript();
    }
};

// 136879, 136877, 136876, 136867
class bfa_spell_violent_gale_winds_pushback : public SpellScriptLoader
{
public:
    bfa_spell_violent_gale_winds_pushback() : SpellScriptLoader("bfa_spell_violent_gale_winds_pushback") {}

    class bfa_spell_violent_gale_winds_pushback_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_violent_gale_winds_pushback_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Map::PlayerList const& playerList = GetCaster()->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(136889);
                }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_violent_gale_winds_pushback_AuraScript::HandleOnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_violent_gale_winds_pushback_AuraScript::HandleOnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_violent_gale_winds_pushback_AuraScript();
    }
};

// 139011
class bfa_spell_helm_of_command : public SpellScriptLoader
{
public:
    bfa_spell_helm_of_command() : SpellScriptLoader("bfa_spell_helm_of_command") {}

    class bfa_spell_helm_of_command_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_helm_of_command_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Player* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            ForcePlayersMove(target);
        }

        void ForcePlayersMove(Player* player)
        {
            Unit* caster = GetCaster();

            Creature* ball = player->FindNearestCreature(NPC_BOUNCING_BOLT_CONDUIT, 500.0f, true);
            Creature* staticshock = player->FindNearestCreature(NPC_STATIC_SHOCK_CONDUIT, 500.0f, true);
            Creature* overcharge = player->FindNearestCreature(NPC_OVERCHARGE_CONDUIT, 500.0f, true);
            Creature* diffusion = player->FindNearestCreature(NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f, true);

            if (!ball || !staticshock || !overcharge || !diffusion || !caster)
                return;

        }


        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_helm_of_command_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_helm_of_command_AuraScript();
    }
};

class bfa_npc_static_shock : public CreatureScript
{
public:
    bfa_npc_static_shock() : CreatureScript("bfa_npc_static_shock") { }

    struct bfa_npc_static_shockAI : public ScriptedAI
    {
        bfa_npc_static_shockAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // clash
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            me->SetObjectScale(0.1f);
        }

        EventMap events;
        bool active;

        void DamageTaken(Unit* who, uint32& damage)
        {
            damage = 0;
        }

        void JustDied(Unit*)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (Creature* leishen = GetLeiShenDisabled())
                {
                    leishen->AI()->DoAction(ACTION_STATIC_SHOCK_DISABLED);
                }
            }

            if (Creature* leishenfortext = GetLeiShenDisabled())
            {
                std::ostringstream str;
                str << "The |cFFFF0000|Hspell:135682|h[North Conduit]|h|r has burned out and caused |cFFFF0000|Hspell:137176|h[Overloaded Circuits]|h|r!";
                leishenfortext->TextEmote(str.str().c_str(), 0, true);
            }

            for (uint32 i = 0; i < 55; ++i)
                me->SummonCreature(NPC_OVERLOADED_CIRCUITS, OverloadedCircuitsStaticShock[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void Reset()
        {
            events.Reset();
            active = false;
        }

        Creature* GetLeiShenDisabled()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        Creature* GetLeiShen()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 70.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_STATIC_SHOCK_ON:
                me->SetPower(POWER_ENERGY, 0);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->AddAura(SPELL_PB_STATIC_SHOCK, me);
                me->SetPower(POWER_ALTERNATE_POWER, 1);
                events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                break;
            case ACTION_STATIC_SHOCK_OFF:
                active = false;
                events.Reset();
                break;
            }
        }

        void ActivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void DeactivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_NORTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void AddPowerToPlayers()
        {
            if (active)
                return;
            events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
            events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(SPELL_PB_PLAYER, player);
                }
        }

        void RemovePowerFromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_PB_PLAYER);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_LEI_SHEN:
                {
                    if (Creature* leishen = GetLeiShen())
                    {
                        if (leishen->GetDistance2d(me) <= 45.0f)
                        {
                            AddPowerToPlayers();
                            active = true;
                            ActivateTiles();
                            me->CastSpell(leishen, SPELL_PILLAR_ON_LEISHEN);
                            me->AddAura(135680, leishen); // static shock dummy aura
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NEAR_PILLAR);
                        }
                        else if (leishen->GetDistance2d(me) >= 45.0f)
                        {
                            active = false;
                            DeactivateTiles();
                            RemovePowerFromPlayers();
                            leishen->RemoveAura(SPELL_PILLAR_ON_LEISHEN);
                            leishen->RemoveAura(135680); // static shock dummy aura
                            events.CancelEvent(EVENT_ADD_POWERS);
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NOT_NEAR_PILLAR);
                        }

                    }
                    events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                    break;
                }
                case EVENT_ADD_POWERS:
                {
                    if (Creature* leishen = GetLeiShenDisabled())
                    {
                        if (leishen->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                            return;
                    }
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ENERGY));
                    events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
                    break;
                }
                case EVENT_CHECK_POWER:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER) + 1);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                            {
                                player->RemoveAura(SPELL_PB_PLAYER);
                                player->AddAura(SPELL_PB_PLAYER, player);
                            }
                    }
                    events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_static_shockAI(creature);
    }
};

class bfa_npc_overcharge_conduit : public CreatureScript
{
public:
    bfa_npc_overcharge_conduit() : CreatureScript("bfa_npc_overcharge_conduit") { }

    struct bfa_npc_overcharge_conduitAI : public ScriptedAI
    {
        bfa_npc_overcharge_conduitAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetPowerType(POWER_ENERGY);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // clash
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            me->SetObjectScale(0.1f);
        }

        EventMap events;
        bool active;

        void DamageTaken(Unit* who, uint32& damage)
        {
            damage = 0;
        }

        void Reset()
        {
            events.Reset();
            active = false;
        }

        void JustDied(Unit*)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (Creature* leishen = GetLeiShenDisabled())
                {
                    leishen->AI()->DoAction(ACTION_OVERCHARGED_DISABLED);
                }
            }

            if (Creature* leishenfortext = GetLeiShenDisabled())
            {
                std::ostringstream str;
                str << "The |cFFFF0000|Hspell:135682|h[South Conduit]|h|r has burned out and caused |cFFFF0000|Hspell:137176|h[Overloaded Circuits]|h|r!";
                leishenfortext->TextEmote(str.str().c_str(), 0, true);
            }

            for (uint32 i = 0; i < 40; ++i)
                me->SummonCreature(NPC_OVERLOADED_CIRCUITS, OverloadedCircuitsOvercharge[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        Creature* GetLeiShenDisabled()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        Creature* GetLeiShen()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 70.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_OVERCHARGE_CONDUIT_ON:
                me->SetPower(POWER_ENERGY, 0);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->AddAura(SPELL_PB_OVERCHARGE, me);
                me->SetPower(POWER_ALTERNATE_POWER, 1);
                events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                break;
            case ACTION_OVERCHARGE_OFF:
                active = false;
                events.Reset();
                break;
            }
        }

        void ActivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void DeactivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_SOUTH, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void AddPowerToPlayers()
        {
            if (active)
                return;
            events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
            events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(SPELL_PB_PLAYER, player);
                }
        }

        void RemovePowerFromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_PB_PLAYER);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_LEI_SHEN:
                {
                    if (Creature* leishen = GetLeiShen())
                    {
                        if (leishen->GetDistance2d(me) <= 45.0f)
                        {
                            AddPowerToPlayers();
                            active = true;
                            ActivateTiles();
                            me->CastSpell(leishen, SPELL_PILLAR_ON_LEISHEN);
                            me->AddAura(135682, leishen); // overcharge aura dummy
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NEAR_PILLAR);
                        }
                        else if (leishen->GetDistance2d(me) >= 45.0f)
                        {
                            active = false;
                            DeactivateTiles();
                            RemovePowerFromPlayers();
                            leishen->RemoveAura(SPELL_PILLAR_ON_LEISHEN);
                            leishen->RemoveAura(135682); // overcharge aura dummy
                            events.CancelEvent(EVENT_ADD_POWERS);
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NOT_NEAR_PILLAR);
                        }

                    }
                    events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                    break;
                }
                case EVENT_ADD_POWERS:
                {
                    if (Creature* leishen = GetLeiShenDisabled())
                    {
                        if (leishen->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                            return;
                    }
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ENERGY));
                    events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
                    break;
                }
                case EVENT_CHECK_POWER:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER) + 1);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                            {
                                player->RemoveAura(SPELL_PB_PLAYER);
                                player->AddAura(SPELL_PB_PLAYER, player);
                            }
                    }
                    events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_overcharge_conduitAI(creature);
    }
};

class bfa_npc_diffusion_chain : public CreatureScript
{
public:
    bfa_npc_diffusion_chain() : CreatureScript("bfa_npc_diffusion_chain") { }

    struct bfa_npc_diffusion_chainAI : public ScriptedAI
    {
        bfa_npc_diffusion_chainAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // clash
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            me->SetObjectScale(0.1f);
        }

        EventMap events;
        bool active;

        void DamageTaken(Unit* who, uint32& damage)
        {
            damage = 0;
        }

        void Reset()
        {
            events.Reset();
            active = false;
        }

        void JustDied(Unit*)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (Creature* leishen = GetLeiShenDisabled())
                {
                    leishen->AI()->DoAction(ACTION_DIFFUSION_CHAIN_DISABLED);
                }
            }

            if (Creature* leishenfortext = GetLeiShenDisabled())
            {
                std::ostringstream str;
                str << "The |cFFFF0000|Hspell:135682|h[East Conduit]|h|r has burned out and caused |cFFFF0000|Hspell:137176|h[Overloaded Circuits]|h|r!";
                leishenfortext->TextEmote(str.str().c_str(), 0, true);
            }

            for (uint32 i = 0; i < 38; ++i)
                me->SummonCreature(NPC_OVERLOADED_CIRCUITS, OverloadedCircuitsDiffusionChain[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        Creature* GetLeiShenDisabled()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        Creature* GetLeiShen()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 70.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DIFFUSION_ON:
                me->SetPower(POWER_ENERGY, 0);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->AddAura(SPELL_PB_DIFFUSION_CHAIN, me);
                me->SetPower(POWER_ALTERNATE_POWER, 1);
                events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                break;
            case ACTION_DIFFUSION_OFF:
                active = false;
                events.Reset();
                break;
            }
        }

        void ActivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void DeactivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_EAST, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void AddPowerToPlayers()
        {
            if (active)
                return;
            events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
            events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(SPELL_PB_PLAYER, player);
                }
        }

        void RemovePowerFromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_PB_PLAYER);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_LEI_SHEN:
                {
                    if (Creature* leishen = GetLeiShen())
                    {
                        if (leishen->GetDistance2d(me) <= 45.0f)
                        {
                            AddPowerToPlayers();
                            active = true;
                            ActivateTiles();
                            me->CastSpell(leishen, SPELL_PILLAR_ON_LEISHEN);
                            me->AddAura(135681, leishen); // diffusion chain aura dummy
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NEAR_PILLAR);
                        }
                        else if (leishen->GetDistance2d(me) >= 45.0f)
                        {
                            active = false;
                            DeactivateTiles();
                            RemovePowerFromPlayers();
                            leishen->RemoveAura(SPELL_PILLAR_ON_LEISHEN);
                            leishen->RemoveAura(135681); // diffusion chain aura dummy
                            events.CancelEvent(EVENT_ADD_POWERS);
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NOT_NEAR_PILLAR);
                        }

                    }
                    events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                    break;
                }
                case EVENT_ADD_POWERS:
                {
                    if (Creature* leishen = GetLeiShenDisabled())
                    {
                        if (leishen->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                            return;
                    }
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ENERGY));
                    events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
                    break;
                }
                case EVENT_CHECK_POWER:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER) + 1);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                            {
                                player->RemoveAura(SPELL_PB_PLAYER);
                                player->AddAura(SPELL_PB_PLAYER, player);
                            }
                    }
                    events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_diffusion_chainAI(creature);
    }
};

class bfa_npc_bouncing_ball : public CreatureScript
{
public:
    bfa_npc_bouncing_ball() : CreatureScript("bfa_npc_bouncing_ball") { }

    struct bfa_npc_bouncing_ballAI : public ScriptedAI
    {
        bfa_npc_bouncing_ballAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // clash
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            me->SetObjectScale(0.1f);
        }

        EventMap events;
        bool active;

        void Reset()
        {
            events.Reset();
            active = false;
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            damage = 0;
        }

        void JustDied(Unit*)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (Creature* leishen = GetLeiShenDisabled())
                {
                    leishen->AI()->DoAction(ACTION_BOUNCING_BALL_DISABLED);
                }
            }

            if (Creature* leishenfortext = GetLeiShenDisabled())
            {
                std::ostringstream str;
                str << "The |cFFFF0000|Hspell:135682|h[West Conduit]|h|r has burned out and caused |cFFFF0000|Hspell:137176|h[Overloaded Circuits]|h|r!";
                leishenfortext->TextEmote(str.str().c_str(), 0, true);
            }

            for (uint32 i = 0; i < 51; ++i)
                me->SummonCreature(NPC_OVERLOADED_CIRCUITS, OverloadedCircuitsBouncingBall[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        Creature* GetLeiShenDisabled()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        Creature* GetLeiShen()
        {
            return me->FindNearestCreature(NPC_LEI_SHEN, 70.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_BOUNCING_ON:
                me->SetPower(POWER_ENERGY, 0);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->AddAura(SPELL_PB_BOUNCING_BOLT, me);
                me->SetPower(POWER_ALTERNATE_POWER, 1);
                events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                break;
            case ACTION_BOUNCING_OFF:
                active = false;
                events.Reset();
                break;
            }
        }

        void ActivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void DeactivateTiles()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, GO_FLOOR_WEST, 500.0f);

            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void AddPowerToPlayers()
        {
            if (active)
                return;
            events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
            events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(SPELL_PB_PLAYER, player);
                }
        }

        void RemovePowerFromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_PB_PLAYER);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_LEI_SHEN:
                {
                    if (Creature* leishen = GetLeiShen())
                    {
                        if (leishen->GetDistance2d(me) <= 45.0f)
                        {
                            AddPowerToPlayers();
                            active = true;
                            ActivateTiles();
                            me->CastSpell(leishen, SPELL_PILLAR_ON_LEISHEN);
                            me->AddAura(135683, leishen); // bouncing ball aura dummy
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NEAR_PILLAR);
                        }
                        else if (leishen->GetDistance2d(me) >= 45.0f)
                        {
                            active = false;
                            DeactivateTiles();
                            RemovePowerFromPlayers();
                            leishen->RemoveAura(SPELL_PILLAR_ON_LEISHEN);
                            leishen->RemoveAura(135683); // bouncing ball aura dummy
                            events.CancelEvent(EVENT_ADD_POWERS);
                            leishen->AI()->DoAction(ACTION_LEI_SHEN_NOT_NEAR_PILLAR);
                        }

                    }
                    events.ScheduleEvent(EVENT_CHECK_LEI_SHEN, 500);
                    break;
                }
                case EVENT_ADD_POWERS:
                {
                    if (Creature* leishen = GetLeiShenDisabled())
                    {
                        if (leishen->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                            return;
                    }
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ENERGY));
                    events.ScheduleEvent(EVENT_ADD_POWERS, 2000);
                    break;
                }
                case EVENT_CHECK_POWER:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER) + 1);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                            {
                                player->RemoveAura(SPELL_PB_PLAYER);
                                player->AddAura(SPELL_PB_PLAYER, player);
                            }
                    }
                    events.ScheduleEvent(EVENT_CHECK_POWER, 3000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_bouncing_ballAI(creature);
    }
};

// Static Shock handler - 135680
class bfa_spell_static_shock_handler : public SpellScriptLoader
{
public:
    bfa_spell_static_shock_handler() : SpellScriptLoader("bfa_spell_static_shock_handler") {}

    class bfa_spell_static_shock_handler_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_static_shock_handler_AuraScript);

        Creature* GetLeiShen()
        {
            return GetCaster()->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_STATIC_SHOCK_PILLAR_ON);
                }
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_STATIC_SHOCK_PILLAR_OFF);
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_static_shock_handler_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_static_shock_handler_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_static_shock_handler_AuraScript();
    }
};

// Overcharge Handler - 135682
class bfa_spell_overcharge_handler : public SpellScriptLoader
{
public:
    bfa_spell_overcharge_handler() : SpellScriptLoader("bfa_spell_overcharge_handler") {}

    class bfa_spell_overcharge_handler_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_overcharge_handler_AuraScript);

        Creature* GetLeiShen()
        {
            return GetCaster()->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_OVERCHARGE_PILLAR_ON);
                }
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_OVERCHARGE_PILLAR_OFF);
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_overcharge_handler_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_overcharge_handler_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_overcharge_handler_AuraScript();
    }
};

// Diffusion Chain handler - 135681
class bfa_spell_diffusion_chain_handler : public SpellScriptLoader
{
public:
    bfa_spell_diffusion_chain_handler() : SpellScriptLoader("bfa_spell_diffusion_chain_handler") {}

    class bfa_spell_diffusion_chain_handler_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_diffusion_chain_handler_AuraScript);

        Creature* GetLeiShen()
        {
            return GetCaster()->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_DIFFUSION_CHAIN_PILLAR_ON);
                }
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_DIFFUSION_CHAIN_PILLAR_OFF);
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_diffusion_chain_handler_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_diffusion_chain_handler_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_diffusion_chain_handler_AuraScript();
    }
};

// Bouncing Bolt handler - 135683
class bfa_spell_bouncing_bolt_handler : public SpellScriptLoader
{
public:
    bfa_spell_bouncing_bolt_handler() : SpellScriptLoader("bfa_spell_bouncing_bolt_handler") {}

    class bfa_spell_bouncing_bolt_handler_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_bouncing_bolt_handler_AuraScript);

        Creature* GetLeiShen()
        {
            return GetCaster()->FindNearestCreature(NPC_LEI_SHEN, 500.0f, true);
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_BOUNCING_BOLT_PILLAR_ON);
                }
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Creature* LeiShen = GetLeiShen())
                {
                    LeiShen->AI()->DoAction(ACTION_BOUNCING_BOLT_PILLAR_OFF);
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_bouncing_bolt_handler_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_bouncing_bolt_handler_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_bouncing_bolt_handler_AuraScript();
    }
};

// Static Shock - 135703
class bfa_spell_static_shock_damage : public SpellScriptLoader
{
public:
    bfa_spell_static_shock_damage() : SpellScriptLoader("bfa_spell_static_shock_damage") { }

    class bfa_spell_static_shock_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_static_shock_damage_SpellScript);

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

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_static_shock_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_static_shock_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_static_shock_damage_SpellScript();
    }
};

// Overcharge - 136326
class bfa_spell_overcharge_damage : public SpellScriptLoader
{
public:
    bfa_spell_overcharge_damage() : SpellScriptLoader("bfa_spell_overcharge_damage") { }

    class bfa_spell_overcharge_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_overcharge_damage_SpellScript);

        void CorrectRange(std::list<WorldObject*>& targets)
        {
            targets.clear();

            float MaxDist = 0.0f;
            float MinDist = 0.0f;

            switch (GetSpellInfo()->Id)
            {
            case SPELL_OVERCHARGE:
                targets.remove(GetCaster());
                MinDist = 8.0f;
                MaxDist = 50.0f;
                break;
            default:
                break;
            }

            Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) <= MaxDist &&
                            player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) >= MinDist)
                            targets.push_back(player);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_overcharge_damage_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_overcharge_damage_SpellScript::CorrectRange, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_overcharge_damage_SpellScript();
    }
};

// Overcharged - 136295
class bfa_spell_overcharge : public SpellScriptLoader
{
public:
    bfa_spell_overcharge() : SpellScriptLoader("bfa_spell_overcharge") { }

    class bfa_spell_overcharge_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_overcharge_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetTarget()->ToPlayer())
            {
                switch (GetSpellInfo()->Id)
                {
                case SPELL_OVERCHARGED:
                    if (Creature* stalker = caster->SummonCreature(63292, caster->GetPositionX() + 50.0f, caster->GetPositionY(), caster->GetPositionZ(), caster->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 4000))
                    {
                        caster->CastSpell(stalker, SPELL_OVERCHARGE, false);
                        caster->CastSpell(stalker, 137252);
                    }
                    caster->RemoveAura(SPELL_OVERCHARGE);
                    break;
                default:
                    break;
                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_overcharge_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_overcharge_AuraScript();
    }
};

// Diffusion Chain - 135991
class bfa_spell_diffusion_chain : public SpellScriptLoader
{
public:
    bfa_spell_diffusion_chain() : SpellScriptLoader("bfa_spell_diffusion_chain") { }

    class bfa_spell_diffusion_chain_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_diffusion_chain_SpellScript);

        Creature* GetChainPillar()
        {
            return GetCaster()->FindNearestCreature(NPC_DIFFUSION_CHAIN_CONDUIT, 500.0f, true);
        }

        void OnHit(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (Creature* pillar = GetChainPillar())
            {
                if (pillar->GetPower(POWER_ALTERNATE_POWER) == 1)
                    target->CastSpell(target, SPELL_DIFFUSION_CHAIN_SUMMON_LOW, true);
                else if (pillar->GetPower(POWER_ALTERNATE_POWER) == 2)
                    target->CastSpell(target, SPELL_DIFFUSION_CHAIN_SUMMON_MINOR, true);
                else if (pillar->GetPower(POWER_ALTERNATE_POWER) == 3)
                    target->CastSpell(target, SPELL_DIFFUSION_CHAIN_SUMMON_BIG, true);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_diffusion_chain_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_diffusion_chain_SpellScript();
    }
};

enum DiffusionEvents
{
    EVENT_DIFFUSION_CAST = 1,
};

class bfa_npc_diffusion_lightning : public CreatureScript
{
public:
    bfa_npc_diffusion_lightning() : CreatureScript("bfa_npc_diffusion_lightning") { }

    struct bfa_npc_diffusion_lightningAI : public ScriptedAI
    {
        bfa_npc_diffusion_lightningAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_FIXATE_PLAYER, 500);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_DIFFUSION_CAST, 3 * IN_MILLISECONDS);
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
                case EVENT_DIFFUSION_CAST:
                    me->CastSpell(me->GetVictim(), SPELL_CHAIN_LIGHTNING_DIFFUSION);
                    events.ScheduleEvent(EVENT_DIFFUSION_CAST, 2000);
                    break;
                case EVENT_FIXATE_PLAYER:
                {
                    std::list<Player*> players;
                    GetPlayerListInGrid(players, me, 2.0f);

                    for (auto target : players)
                    {
                        me->AddThreat(target, 9999999999.9f);
                        me->AI()->AttackStart(target);
                    }
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_diffusion_lightningAI(creature);
    }
};

// Bouncing Ball - 136366
class bfa_spell_bouncing_bolt : public SpellScriptLoader
{
public:
    bfa_spell_bouncing_bolt() : SpellScriptLoader("bfa_spell_bouncing_bolt") { }

    class bfa_spell_bouncing_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_bouncing_bolt_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.size() == 0)
                SummonAdd();
        }

        void SummonAdd()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            if (const WorldLocation* pos = GetExplTargetDest())
            {
                caster->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), SPELL_BOUNCING_BOLT_SUMMON, true);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_bouncing_bolt_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_bouncing_bolt_SpellScript();
    }
};

// Bouncing Ball - 136366
class bfa_spell_bouncing_bolt_damage : public SpellScriptLoader
{
public:
    bfa_spell_bouncing_bolt_damage() : SpellScriptLoader("bfa_spell_bouncing_bolt_damage") { }

    class bfa_spell_bouncing_bolt_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_bouncing_bolt_damage_SpellScript);

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

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_bouncing_bolt_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_bouncing_bolt_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_bouncing_bolt_damage_SpellScript();
    }
};

// Discharged Energy - 134820
class bfa_spell_discharged_energy : public SpellScriptLoader
{
public:
    bfa_spell_discharged_energy() : SpellScriptLoader("bfa_spell_discharged_energy") { }

    class bfa_spell_discharged_energy_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_discharged_energy_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (!GetCaster())
                return;

            std::list<Player*> players;
            GetPlayerListInGrid(players, GetCaster(), 200.0f);
            if (players.size())
            {
                for (auto player : players)
                {
                    if (!player->HasAura(SPELL_DISCHARGE_DAMAGE_AND_STACKS))
                    {
                        if (Aura* energy = player->AddAura(SPELL_DISCHARGE_DAMAGE_AND_STACKS, player))
                        {
                            energy->SetMaxDuration(1000);
                            energy->SetDuration(1000);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_discharged_energy_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_discharged_energy_AuraScript();
    }
};

#define SAFE_DISTANCE_DECAPITATE 50.0f

// Decapitate - 134916
class bfa_spell_decapitate : public SpellScriptLoader
{
public:
    bfa_spell_decapitate() : SpellScriptLoader("bfa_spell_decapitate") {}

    class bfa_spell_decapitate_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_decapitate_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    float distance = caster->GetExactDist(target);
                    uint32 mindmg = 0, maxdmg = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_25_N:
                        mindmg = 1500000;
                        maxdmg = 2000000;
                        break;
                    case DIFFICULTY_10_HC:
                    case DIFFICULTY_25_HC:
                        mindmg = 2500000;
                        maxdmg = 3000000;
                        break;
                    }

                    if (distance > SAFE_DISTANCE_DECAPITATE)
                        distance = SAFE_DISTANCE_DECAPITATE;

                    SetHitDamage(((mindmg / -SAFE_DISTANCE_DECAPITATE) * distance) + maxdmg);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_decapitate_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_decapitate_SpellScript();
    }
};

class bfa_npc_unharnessed_power : public CreatureScript
{
public:
    bfa_npc_unharnessed_power() : CreatureScript("bfa_npc_unharnessed_power") { }

    struct bfa_npc_unharnessed_powerAI : public ScriptedAI
    {
        bfa_npc_unharnessed_powerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_BOUNCE_AGAIN, 500);
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
                case EVENT_BOUNCE_AGAIN:
                    me->CastSpell(me, SPELL_BOUNCING_BOLT_MISSILE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_unharnessed_powerAI(creature);
    }
};

// 136850
class bfa_spell_lightning_whip : public SpellScriptLoader
{
public:
    bfa_spell_lightning_whip() : SpellScriptLoader("bfa_spell_lightning_whip") { }

    class bfa_spell_lightning_whip_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_lightning_whip_SpellScript);

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
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_lightning_whip_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_lightning_whip_SpellScript();
    }
};

// 999278
class bfa_npc_lei_shen_teleport_players : public CreatureScript
{
public:
    bfa_npc_lei_shen_teleport_players() : CreatureScript("bfa_npc_lei_shen_teleport_players") { }

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        player->NearTeleportTo(5676.32f, 4059.78f, 158.00f, 0.74f, false);
        return true;
    }
};

enum ConduitEvent
{
    EVENT_CONDUIT = 1,
};

class bfa_npc_overloaded_circuits : public CreatureScript
{
public:
    bfa_npc_overloaded_circuits() : CreatureScript("bfa_npc_overloaded_circuits") { }

    struct bfa_npc_overloaded_circuitsAI : public ScriptedAI
    {
        bfa_npc_overloaded_circuitsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_CONDUIT, 500);
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
                case EVENT_CONDUIT:
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 6.5f);

                    playerList.remove_if(TargetIsGm());

                    if (!playerList.empty())
                        for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            if (Aura* circuit = (*itr)->AddAura(SPELL_OVERLOADED_CIRCUITS, (*itr)))
                            {
                                circuit->SetMaxDuration(1 * IN_MILLISECONDS);
                                circuit->SetDuration(1 * IN_MILLISECONDS);
                            }
                        }
                    events.ScheduleEvent(EVENT_CONDUIT, 1000);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_overloaded_circuitsAI(creature);
    }
};

class bfa_spell_discharged_energy_duration : public SpellScriptLoader
{
public:
    bfa_spell_discharged_energy_duration() : SpellScriptLoader("bfa_spell_discharged_energy_duration") {}

    class bfa_spell_discharged_energy_duration_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_discharged_energy_duration_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            Player* player = caster->ToPlayer();
            if (!player)
                return;

            if (player->GetMap()->IsHeroic())
            {
                if (Aura* debuff = player->GetAura(137446))
                {
                    debuff->SetMaxDuration(60000);
                    debuff->SetDuration(60000);
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_discharged_energy_duration_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_discharged_energy_duration_AuraScript();
    }
};

class bfa_npc_lei_shen_teleport_after_encounter : public CreatureScript
{
public:
    bfa_npc_lei_shen_teleport_after_encounter() : CreatureScript("bfa_npc_lei_shen_teleport_after_encounter") { }

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        player->NearTeleportTo(5576.05322f, 4655.958984f, -0.865f, 3.14f, false);
        return true;
    }
};

void AddSC_bfa_boss_lei_shen()
{
    new bfa_boss_lei_shen;
    new bfa_npc_ball_lightning;
    new bfa_npc_static_shock;
    new bfa_npc_overcharge_conduit;
    new bfa_npc_bouncing_ball;
    new bfa_npc_diffusion_chain;
    new bfa_npc_diffusion_lightning;
    new bfa_npc_unharnessed_power;
    new bfa_npc_lei_shen_teleport_players;
    new bfa_npc_overloaded_circuits;
    new bfa_npc_lei_shen_teleport_after_encounter;

    new bfa_spell_thunderstruck;
    new bfa_spell_violent_gale_winds;
    new bfa_spell_violent_gale_winds_pushback;
    new bfa_spell_discharged_energy_duration;
    new bfa_spell_helm_of_command;
    new bfa_spell_bouncing_bolt;
    new bfa_spell_static_shock_damage;
    new bfa_spell_bouncing_bolt_handler;
    new bfa_spell_discharged_energy;
    new bfa_spell_diffusion_chain_handler;
    new bfa_spell_bouncing_bolt_damage;
    new bfa_spell_overcharge_handler;
    new bfa_spell_lightning_whip;
    new bfa_spell_decapitate;
    new bfa_spell_static_shock_handler;
    new bfa_spell_overcharge;
    new bfa_spell_diffusion_chain;
    new bfa_spell_overcharge_damage;
}
