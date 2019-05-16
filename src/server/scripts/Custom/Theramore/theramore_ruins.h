#ifndef THERAMORE_RUINS_H
#define THERAMORE_RUINS_H

enum NPCs
{
	NPC_KALECGOS                    = 100001,
    NPC_KALECGOS_DRAGON             = 100016,
    NPC_KINNDY_SPARKSHINE           = 100002,
    NPC_WATER_ELEMENTAL             = 100011,
    NPC_INVISIBLE_STALKER           = 32780,
};

enum Quests
{
    QUEST_LIMIT_THE_NUKE            = 80007,
    QUEST_RETURN_TO_THERAMORE       = 80008,
    QUEST_PROTECT_THE_ARTEFACT      = 80009
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

    EVENT_IRIS_1,
    EVENT_IRIS_2,
    EVENT_IRIS_3,
    EVENT_IRIS_4,
    EVENT_IRIS_5,
    EVENT_IRIS_6,
    EVENT_IRIS_7
};

enum Spells
{
    SPELL_FIREBALL                  = 100002,
    SPELL_BLIZZARD                  = 100001,
    SPELL_FROST_BREEZE              = 100033,

    SPELL_SIMPLE_TELEPORT           = 100032,
    SPELL_ICE_NOVA                  = 56935,
    SPELL_ICE_BLOCK                 = 45776,
    SPELL_POWER_BALL_VISUAL         = 54139,
    SPELL_PORTAL                    = 57687,
    SPELL_CANALISATION              = 58012
};

enum Text
{
    SAY_RETURN_1                    = 0,
    SAY_RETURN_2                    = 1,
    SAY_RETURN_3                    = 10,
    SAY_RETURN_4                    = 2,
    SAY_RETURN_5                    = 11,
    SAY_RETURN_6                    = 3,
    SAY_RETURN_7                    = 12,
    SAY_RETURN_8                    = 4,
    SAY_RETURN_9                    = 5,

    SAY_IRIS_1                      = 6,
    SAY_IRIS_2                      = 7,
    SAY_IRIS_3                      = 8,
    SAY_IRIS_4                      = 9,
    SAY_IRIS_5                      = 10,
};

struct Location
{
    uint32 entry;
    Position position;
};

const Position ElementalsPos[2] =
{
    { -3714.59f, -4465.40f, -19.87f, 0.04f },
    { -3714.30f, -4472.51f, -20.15f, 0.04f }
};

#endif
