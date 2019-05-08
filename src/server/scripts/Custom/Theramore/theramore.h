#ifndef THERAMORE_H
#define THERAMORE_H

enum NPCs
{
    NPC_JAINA_PROUDMOORE            = 100000,
    NPC_KALECGOS                    = 100001,
    NPC_KALECGOS_DRAGON             = 100016,
    NPC_KINNDY_SPARKSHINE           = 100002,
    NPC_ARCHMAGE_TERVOSH            = 100003,
    NPC_LIEUTENANT_ADEN             = 100004,
    NPC_PAINED                      = 100021,
    NPC_MYSTERIOUS_TAUREN           = 100022,
    NPC_PERITH_STORMHOOF            = 100023,

    // Archmages
    NPC_RHONIN                      = 100005,
    NPC_VEREESA_WINDRUNNER          = 100006,
    NPC_TARI_COGG                   = 100007,
    NPC_AMARA_LEESON                = 100008,
    NPC_THODER_WINDERMERE           = 100009,
    NPC_THALEN_SONGWEAVER           = 100010,
    NPC_WATER_ELEMENTAL             = 100011,

    // Misc
    NPC_INVISIBLE_STALKER           = 32780,
    NPC_ZEALOUS_THERAMORE_GUARD     = 100024,
    NPC_THERAMORE_GUARD             = 100012,
    NPC_WAVES_INVOKER               = 100017,
    NPC_THERAMORE_MEDIC             = 100033,
    NPC_WOUNDED_THERAMORE_GUARD     = 100037,
    NPC_WOUNDED_DUMMY               = 100018
};

enum Misc
{
    // GameObjects
    GOB_FIRE_THERAMORE              = 182592,
    GOB_THERAMORE_GATE              = 500000,
    GOB_LOW_CHAIR                   = 169285,

    // Zone
    ZONE_THERAMORE_ISLE             = 6042,

    // Quests
    QUEST_LOOKING_FOR_THE_ARTEFACT  = 80000,
    QUEST_EVACUATION                = 80001,
    QUEST_PREPARE_FOR_WAR           = 80006,
    QUEST_LIMIT_THE_NUKE            = 80007
};

enum Events
{
    // Starters
    EVENT_START_CONVO       = 1,
    EVENT_END_CONVO         = 2,
    EVENT_START_WARN        = 3,
    EVENT_START_PRE_BATTLE  = 4,
    EVENT_START_BATTLE      = 5,
    EVENT_START_EVACUATION  = 6,
    EVENT_START_POST_BATTLE = 7,
    EVENT_STOP_KALECGOS     = 8,
    EVENT_SET_END           = 9,
    EVENT_START_END         = 10,

    // Events
    // Convo
    EVENT_CONVO_1,
    EVENT_CONVO_2,
    EVENT_CONVO_3,
    EVENT_CONVO_4,
    EVENT_CONVO_5,
    EVENT_CONVO_6,
    EVENT_CONVO_7,
    EVENT_CONVO_8,
    EVENT_CONVO_9,
    EVENT_CONVO_10,
    EVENT_CONVO_11,
    EVENT_CONVO_12,
    EVENT_CONVO_13,
    EVENT_CONVO_14,
    EVENT_CONVO_15,
    EVENT_CONVO_16,
    EVENT_CONVO_17,
    EVENT_CONVO_18,
    EVENT_CONVO_19,
    EVENT_CONVO_20,
    EVENT_CONVO_21,
    EVENT_CONVO_22,
    EVENT_CONVO_23,

    EVENT_WARN_1,
    EVENT_WARN_2,
    EVENT_WARN_3,
    EVENT_WARN_4,
    EVENT_WARN_5,
    EVENT_WARN_6,
    EVENT_WARN_7,
    EVENT_WARN_8,
    EVENT_WARN_9,
    EVENT_WARN_10,
    EVENT_WARN_11,
    EVENT_WARN_12,
    EVENT_WARN_13,
    EVENT_WARN_14,
    EVENT_WARN_15,
    EVENT_WARN_16,
    EVENT_WARN_17,
    EVENT_WARN_18,
    EVENT_WARN_19,
    EVENT_WARN_20,
    EVENT_WARN_21,
    EVENT_WARN_22,
    EVENT_WARN_23,
    EVENT_WARN_24,
    EVENT_WARN_25,
    EVENT_WARN_26,
    EVENT_WARN_27,
    EVENT_WARN_28,
    EVENT_WARN_29,
    EVENT_WARN_30,
    EVENT_WARN_31,
    EVENT_WARN_32,
    EVENT_WARN_33,
    EVENT_WARN_34,
    EVENT_WARN_35,
    EVENT_WARN_36,
    EVENT_WARN_37,
    EVENT_WARN_38,
    EVENT_WARN_39,
    EVENT_WARN_40,
    EVENT_WARN_41,
    EVENT_WARN_42,
    EVENT_WARN_43,
    EVENT_WARN_44,
    EVENT_WARN_45,
    EVENT_WARN_46,
    EVENT_WARN_47,
    EVENT_WARN_48,
    EVENT_WARN_49,

    EVENT_EVACUATION_1,

    EVENT_SHAKER,

    EVENT_PRE_BATTLE_1,
    EVENT_PRE_BATTLE_2,
    EVENT_PRE_BATTLE_3,
    EVENT_PRE_BATTLE_4,
    EVENT_PRE_BATTLE_5,
    EVENT_PRE_BATTLE_6,
    EVENT_PRE_BATTLE_7,
    EVENT_PRE_BATTLE_8,
    EVENT_PRE_BATTLE_9,
    EVENT_PRE_BATTLE_10,
    EVENT_PRE_BATTLE_11,
    EVENT_PRE_BATTLE_12,
    EVENT_PRE_BATTLE_13,
    EVENT_PRE_BATTLE_14,
    EVENT_PRE_BATTLE_15,
    EVENT_PRE_BATTLE_16,
    EVENT_PRE_BATTLE_17,
    EVENT_PRE_BATTLE_18,
    EVENT_PRE_BATTLE_19,
    EVENT_PRE_BATTLE_20,
    EVENT_PRE_BATTLE_21,
    EVENT_PRE_BATTLE_22,

    EVENT_POST_BATTLE_1,
    EVENT_POST_BATTLE_2,
    EVENT_POST_BATTLE_3,
    EVENT_POST_BATTLE_4,
    EVENT_POST_BATTLE_5,
    EVENT_POST_BATTLE_6,
    EVENT_POST_BATTLE_7,
    EVENT_POST_BATTLE_8,
    EVENT_POST_BATTLE_9,
    EVENT_POST_BATTLE_10,
    EVENT_POST_BATTLE_11,
    EVENT_POST_BATTLE_12,
    EVENT_POST_BATTLE_13,
    EVENT_POST_BATTLE_14,
    EVENT_POST_BATTLE_15,
    EVENT_POST_BATTLE_16,
    EVENT_POST_BATTLE_17,
    EVENT_POST_BATTLE_18,
    EVENT_POST_BATTLE_19,
    EVENT_POST_BATTLE_20,

    EVENT_END_1,
    EVENT_END_2,
    EVENT_END_3,
    EVENT_END_4,
    EVENT_END_5,
    EVENT_END_6,
    EVENT_END_7,
    EVENT_END_8,
    EVENT_END_9,
    EVENT_END_10,
    EVENT_END_11,
    EVENT_END_12
};

enum Phases
{
    PHASE_CONVO,
    PHASE_WARN,
    PHASE_PRE_BATTLE,
    PHASE_BATTLE,
    PHASE_POST_BATTLE,
    PHASE_END
};

enum Spells
{
    SPELL_FIREBALL                  = 100002,
    SPELL_BLIZZARD                  = 100001,
    SPELL_FROST_BREEZE              = 100033,

    SPELL_SIMPLE_TELEPORT           = 100032,
    SPELL_ICE_NOVA                  = 56935,
    SPELL_ICE_BLOCK                 = 45776,
    SPELL_TELEPORT                  = 51347,
    SPELL_POWER_BALL_VISUAL         = 54139,
    SPELL_VANISH                    = 36747,
    SPELL_CHAINS                    = 68341,
    SPELL_PORTAL                    = 57687
};

enum Text
{
    SAY_CONVO_1         = 0,
    SAY_CONVO_2         = 0,
    SAY_CONVO_3         = 1,
    SAY_CONVO_4         = 1,
    SAY_CONVO_5         = 2,
    SAY_CONVO_6         = 0,
    SAY_CONVO_7         = 0,
    SAY_CONVO_8         = 1,
    SAY_CONVO_9         = 1,
    SAY_CONVO_9_BIS     = 2,
    SAY_CONVO_10        = 3,
    SAY_CONVO_11        = 2,
    SAY_CONVO_12        = 4,
    SAY_CONVO_13        = 3,
    SAY_CONVO_14        = 3,
    SAY_CONVO_15        = 5,
    SAY_CONVO_16        = 4,
    SAY_CONVO_17        = 5,

    SAY_WARN_1          = 0,
    SAY_WARN_2          = 15,
    SAY_WARN_3          = 1,
    SAY_WARN_4          = 2,
    SAY_WARN_5          = 16,
    SAY_WARN_6          = 3,
    SAY_WARN_7          = 4,
    SAY_WARN_8          = 17,
    SAY_WARN_9          = 18,
    SAY_WARN_10         = 5,
    SAY_WARN_11         = 19,
    SAY_WARN_13         = 20,
    SAY_WARN_14         = 0,
    SAY_WARN_15         = 21,
    SAY_WARN_16         = 1,
    SAY_WARN_17         = 2,
    SAY_WARN_18         = 3,
    SAY_WARN_19         = 22,
    SAY_WARN_20         = 4,
    SAY_WARN_21         = 23,
    SAY_WARN_22         = 5,
    SAY_WARN_23         = 6,
    SAY_WARN_24         = 24,
    SAY_WARN_25         = 7,
    SAY_WARN_26         = 25,
    SAY_WARN_27         = 26,
    SAY_WARN_28         = 27,
    SAY_WARN_29         = 8,
    SAY_WARN_30         = 9,
    SAY_WARN_31         = 28,
    SAY_WARN_32         = 10,
    SAY_WARN_33         = 29,
    SAY_WARN_34         = 11,
    SAY_WARN_35         = 30,
    SAY_WARN_36         = 6,
    SAY_WARN_37         = 31,

    SAY_EVENT_SHAKER    = 0,

    SAY_PRE_BATTLE_1    = 6,
    SAY_PRE_BATTLE_2    = 1,
    SAY_PRE_BATTLE_3    = 7,
    SAY_PRE_BATTLE_4    = 0,
    SAY_PRE_BATTLE_5    = 8,
    SAY_PRE_BATTLE_6    = 9,
    SAY_PRE_BATTLE_7    = 0,
    SAY_PRE_BATTLE_8    = 10,
    SAY_PRE_BATTLE_9    = 11,
    SAY_PRE_BATTLE_10   = 1,
    SAY_PRE_BATTLE_11   = 12,
    SAY_PRE_BATTLE_12   = 0,
    SAY_PRE_BATTLE_13   = 13,
    SAY_PRE_BATTLE_14   = 14,

    SAY_POST_BATTLE_1   = 40,
    SAY_POST_BATTLE_2   = 2,
    SAY_POST_BATTLE_3   = 41,
    SAY_POST_BATTLE_4   = 4,
    SAY_POST_BATTLE_5   = 42,
    SAY_POST_BATTLE_6   = 5,
    SAY_POST_BATTLE_7   = 43,
    SAY_POST_BATTLE_8   = 6,
    SAY_POST_BATTLE_9   = 44,
    SAY_POST_BATTLE_10  = 45,
    SAY_POST_BATTLE_11  = 7,
    SAY_POST_BATTLE_12  = 46,
    SAY_POST_BATTLE_13  = 47,
    SAY_POST_BATTLE_14  = 8,
    SAY_POST_BATTLE_15  = 48,
    SAY_POST_BATTLE_16  = 49,

    SAY_END_1           = 60,
    SAY_END_2           = 2,
    SAY_END_3           = 3,
    SAY_END_4           = 61,
    SAY_END_5           = 62,
    SAY_END_6           = 4,
    SAY_END_7           = 5,
    SAY_END_8           = 63,
    SAY_END_9           = 6,
    SAY_END_10          = 64,
    SAY_END_11          = 7
};

const float FireLocation[35][4] =
{
    { -3665.85f, -4486.16f, 11.07f, 3.5946f },
    { -3645.48f, -4520.75f,  9.49f, 5.0731f },
    { -3783.41f, -4373.28f, 16.78f, 4.6534f },
    { -3775.22f, -4333.53f, 11.28f, 2.1618f },
    { -3762.54f, -4348.24f, 11.13f, 2.1735f },
    { -3743.14f, -4344.01f, 11.41f, 3.9171f },
    { -3732.43f, -4332.31f, 11.75f, 3.8288f },
    { -3708.37f, -4337.79f, 10.91f, 0.7127f },
    { -3701.79f, -4345.72f, 16.68f, 0.0000f },
    { -3731.25f, -4412.55f, 26.87f, 4.3923f },
    { -3715.47f, -4474.48f, 44.50f, 0.0000f },
    { -3720.81f, -4477.59f, 31.13f, 0.3063f },
    { -3698.33f, -4547.57f, 37.80f, 5.9886f },
    { -3696.88f, -4513.77f, 11.84f, 4.1742f },
    { -3676.81f, -4529.64f, 10.33f, 4.0027f },
    { -3870.74f, -4562.49f,  8.35f, 2.2128f },
    { -3846.46f, -4577.59f,  8.19f, 0.0000f },
    { -3893.06f, -4595.04f,  9.23f, 0.0000f },
    { -3844.41f, -4630.65f,  9.25f, 4.7987f },
    { -3886.46f, -4457.42f, 43.65f, 2.0793f },
    { -3852.64f, -4497.29f, 29.97f, 1.6022f },
    { -3842.07f, -4460.03f, 25.87f, 0.0000f },
    { -3738.28f, -4435.75f, 77.07f, 5.3937f },
    { -3737.87f, -4434.29f, 37.12f, 0.0000f },
    { -3653.61f, -4361.11f,  9.67f, 0.6832f },
    { -3643.00f, -4374.14f, 10.17f, 0.6832f },
    { -3652.12f, -4379.96f, 10.84f, 4.1743f },
    { -3676.51f, -4368.60f, 11.63f, 3.2495f },
    { -3630.37f, -4374.75f, 32.74f, 0.0000f },
    { -3622.40f, -4391.60f, 42.40f, 0.0000f },
    { -3629.11f, -4443.47f, 14.38f, 0.0235f },
    { -3613.41f, -4408.58f, 16.86f, 1.7848f },
    { -3611.27f, -4403.01f, 27.29f, 0.0000f },
    { -3660.06f, -4442.44f, 11.33f, 0.8482f },
    { -3750.13f, -4322.90f, 30.38f, 4.6809f }
};

struct Location
{
    uint32 entry;
    Position position;
};

const Location ArchmagesLocation[6] =
{
    { NPC_RHONIN,		        { -3718.51f, -4542.53f, 25.82f, 3.59f } },
    { NPC_TARI_COGG,		    { -3717.86f, -4539.88f, 25.82f, 3.59f } },
    { NPC_AMARA_LEESON,         { -3716.01f, -4540.03f, 25.82f, 3.59f } },
    { NPC_THODER_WINDERMERE,	{ -3717.01f, -4538.31f, 25.82f, 3.59f } },
    { NPC_THALEN_SONGWEAVER,    { -3715.66f, -4544.08f, 25.82f, 3.59f } },
    { NPC_VEREESA_WINDRUNNER,	{ -3716.33f, -4543.03f, 25.82f, 3.59f } }
};

const float ArchmagesRelocate[6][4] =
{
    { -3677.44f, -4521.55f, 10.21f, 0.50f }, // Rhonin
    { -3809.58f, -4544.42f, 10.75f, 3.09f }, // Tari
    { -3649.58f, -4369.21f,  9.57f, 0.69f }, // Amara
    { -3680.96f, -4505.57f, 11.48f, 6.23f }, // Thoder
    { -3652.05f, -4365.66f,  9.53f, 0.71f }, // Thalen
    { -3833.79f, -4545.92f,  9.22f, 0.75f }  // Vereesa
};

const Location WarnLocation[4] =
{
    { NPC_PAINED,                   { -3732.55f, -4423.45f, 30.51f, 3.94f } },
    { NPC_MYSTERIOUS_TAUREN,        { -3731.33f, -4422.18f, 30.47f, 3.94f } },
    { NPC_ZEALOUS_THERAMORE_GUARD,  { -3731.17f, -4420.68f, 30.44f, 3.94f } },
    { NPC_THERAMORE_GUARD,          { -3729.32f, -4422.18f, 30.44f, 3.94f } }
};

const Position WarnDestination[4] =
{
    { -3747.11f, -4438.24f, 30.55f, 3.94f },
    { -3742.56f, -4433.60f, 30.55f, 3.94f },
    { -3741.11f, -4430.64f, 30.55f, 3.91f },
    { -3739.63f, -4432.15f, 30.55f, 3.91f }
};

const Position PortalPosition = { -3712.42f, -4539.62f, 25.82f, 3.59f };

#endif
