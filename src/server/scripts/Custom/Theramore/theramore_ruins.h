#ifndef THERAMORE_RUINS_H
#define THERAMORE_RUINS_H

enum NPCs
{
	NPC_KALECGOS                    = 100001,
    NPC_KALECGOS_DRAGON             = 100016,
    NPC_KINNDY_SPARKSHINE           = 100002,
    NPC_WATER_ELEMENTAL             = 100011,
    NPC_INVISIBLE_STALKER           = 32780,
    NPC_ARCANIC_FORM                = 100040,

    NPC_WARLORD_ROK_NAH             = 100039,
    NPC_ROK_NAH_GRUNT               = 100034,
    NPC_ROK_NAH_SOLDIER             = 100029,
    NPC_ROK_NAH_HAG                 = 100030,
    NPC_ROK_NAH_FELCASTER           = 100031,
    NPC_ROK_NAH_LOA_SINGER          = 100032,
};

enum Quests
{
    QUEST_LIMIT_THE_NUKE            = 80007,
    QUEST_RETURN_TO_THERAMORE       = 80008,
    QUEST_DESTROY_THE_DESTROYER     = 80009,
    QUEST_PROTECT_THE_ARTEFACT      = 80010
};

enum Events
{
    // Starters
    EVENT_START_RETURN              = 1,
    EVENT_START_IRIS                = 2,

	// Events
    EVENT_RETURN_1,
    EVENT_RETURN_2,
    EVENT_RETURN_3,
    EVENT_RETURN_4,
    EVENT_RETURN_5,
    EVENT_RETURN_6,
    EVENT_RETURN_7,
    EVENT_RETURN_8,
    EVENT_RETURN_9,
    EVENT_RETURN_10,
    EVENT_RETURN_11,
    EVENT_RETURN_12,
    EVENT_RETURN_13,
    EVENT_RETURN_14,
    EVENT_RETURN_15,
    EVENT_RETURN_16,
    EVENT_RETURN_17,
    EVENT_RETURN_18,

    EVENT_IRIS_1,
    EVENT_IRIS_2,
    EVENT_IRIS_3,
    EVENT_IRIS_4,
    EVENT_IRIS_5,
    EVENT_IRIS_6,
    EVENT_IRIS_7,
    EVENT_IRIS_8,
    EVENT_IRIS_9,
    EVENT_IRIS_10,
    EVENT_IRIS_11,
    EVENT_IRIS_12,
    EVENT_IRIS_13,
    EVENT_IRIS_14,
    EVENT_IRIS_15,
    EVENT_IRIS_16,
    EVENT_IRIS_17,
    EVENT_IRIS_18,
    EVENT_IRIS_19,
    EVENT_IRIS_20,
    EVENT_IRIS_21,
    EVENT_IRIS_22,
    EVENT_IRIS_23,
    EVENT_IRIS_24,
    EVENT_IRIS_25
};

enum Spells
{
    SPELL_FIREBALL                  = 100002,
    SPELL_BLIZZARD                  = 100001,
    SPELL_FROSTBOLT                 = 100006,
    SPELL_FROST_RUNE                = 100041,

    SPELL_SIMPLE_TELEPORT           = 100032,
    SPELL_ICE_NOVA                  = 56935,
    SPELL_ICE_BLOCK                 = 22856,
    SPELL_POWER_BALL_VISUAL         = 54139,
    SPELL_PORTAL                    = 57687,
    SPELL_OPENED_PORTAL             = 61236,
    SPELL_CANALISATION              = 58012,
    SPELL_ARCANE_CANALISATION       = 54219,
    SPELL_WATER_SHIELD              = 100040,
    SPELL_FROST_EXPLOSION           = 73773,
    SPELL_ARCANE_FORM               = 70573,
    SPELL_JAINAS_CALL               = 70525,
};

enum Casting
{
    CASTING_FIREBALL                = 200,
    CASTING_FROSTBOLT,
    CASTING_FROST_RUNE,
};

enum Text
{
    SAY_RETURN_1                    = 10,
    SAY_RETURN_2                    = 0,
    SAY_RETURN_3                    = 1,
    SAY_RETURN_4                    = 11,
    SAY_RETURN_5                    = 2,
    SAY_RETURN_6                    = 12,
    SAY_RETURN_7                    = 3,
    SAY_RETURN_8                    = 13,
    SAY_RETURN_9                    = 4,
    SAY_RETURN_10                   = 14,
    SAY_RETURN_11                   = 15,
    SAY_RETURN_12                   = 5,
    SAY_RETURN_13                   = 16,

    SAY_IRIS_1                      = 6,
    SAY_IRIS_2                      = 7,
    SAY_IRIS_3                      = 8,

    SAY_IRIS_4                      = 0,
    SAY_IRIS_5                      = 9,
    SAY_IRIS_6                      = 1,
    SAY_IRIS_7                      = 10,
    SAY_IRIS_8                      = 2,

    SAY_IRIS_9                      = 11,
    SAY_IRIS_10                     = 12,
};

struct Location
{
    uint32 entry;
    Position position;
};

const Position ElementalsPos[4] =
{
    { -3714.59f, -4465.40f, -19.87f, 0.04f },
    { -3714.30f, -4472.51f, -20.15f, 0.04f },

    { -3699.80f, -4453.12f, -20.12f, 6.18f },
    { -3698.08f, -4482.82f, -19.68f, 0.07f }
};

const Location Soldiers[12] =
{
    { NPC_WARLORD_ROK_NAH,  { -3642.37f, -4445.01f, -3.07f, 3.56f } },
    { 0,                    { -3644.38f, -4449.42f, -3.58f, 3.56f } },
    { 0,                    { -3645.84f, -4446.23f, -3.36f, 3.56f } },
    { 0,                    { -3647.34f, -4442.94f, -3.36f, 3.56f } },
    { 0,                    { -3642.15f, -4446.41f, -3.20f, 3.56f } },
    { 0,                    { -3643.71f, -4443.01f, -2.98f, 3.56f } },
    { 0,                    { -3653.04f, -4505.90f,  1.41f, 2.56f } },
    { 0,                    { -3652.22f, -4479.16f, -3.78f, 2.96f } },
    { 0,                    { -3635.43f, -4492.63f, -1.36f, 3.01f } },
    { 0,                    { -3635.77f, -4495.29f, -1.01f, 3.01f } },
    { 0,                    { -3632.48f, -4494.38f, -0.53f, 3.01f } },
    { 0,                    { -3632.13f, -4491.60f, -0.80f, 3.01f } }
};

#endif
