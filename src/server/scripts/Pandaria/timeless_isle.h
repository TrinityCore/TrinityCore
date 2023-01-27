#ifndef TIMELESS_ISLE_H
#define TIMELESS_ISLE_H

const Position summonPos[4] =
{
    {-553.17f, -4949.02f, -6.27f, -2.30f},
    {-740.80f, -4955.08f, -6.27f, 5.63f},
    {-746.32f, -5078.48f, -6.27f, 0.69f},
    {-551.16f, -5080.01f, -6.27f, 2.28f}
};

const Position CentrPos[1] =
{
    {-650.14f, -5024.67f, -6.27f}
};

const Position WallPos[7] =
{
    {-680.63f, -5091.60f, -6.19f, 1.58f},
    {-713.89f, -5091.50f, -6.19f, 1.57f},
    {-580.55f, -5091.66f, -6.19f, 1.58f},
    {-613.91f, -5091.65f, -6.19f, 1.54f},
    {-547.26f, -5091.75f, -6.19f, 1.56f},
    {-647.20f, -5091.63f, -6.19f, 1.57f},
    {-747.19f, -5091.65f, -6.19f, 1.59f}
};

Position const niuzaoWP[8] =
{
    { -573.247f, -5024.76f, -6.27667f, 0.0f },
    { -574.627f, -5074.96f, -6.27667f, 0.0f },
    { -674.698f, -5074.79f, -6.27722f, 0.0f },
    { -741.14f, -5074.97f, -6.27722f, 0.0f },
    { -741.446f, -5017.58f, -6.27723f, 0.0f },
    { -741.128f, -4958.48f, -6.27723f, 0.0f },
    { -652.9f, -4958.67f, -6.27723f, 0.0f },
    { -572.782f, -4960.81f, -6.27723f, 0.0f }
};

enum eQuests
{
    QUEST_TIME_KEEPER_KAIROZ_H       = 33156,
    QUEST_TIME_KEEPER_KAIROZ_A       = 33160
};

enum eCreatures
{
    NPC_PRINCE_ANDUIN       = 73061,
    NPC_KAIROZ              = 72870,
    NPC_JADEFIRE_WALL       = 72020,
    NPC_SHAOHAO             = 73303,
    NPC_CHIJI               = 71952,
    NPC_XUEN                = 71953,
    NPC_YULON               = 71955,
    NPC_NIUZAO              = 71954
};

enum eActions
{
    ACTION_PRINCE_TALK_1      = 1,
    ACTION_PRINCE_TALK_2      = 2,
    ACTION_PRINCE_TALK_3      = 3,
    ACTION_PRINCE_TALK_4      = 4,
    ACTION_PRINCE_TALK_5      = 5,
    ACTION_KAIROZ_TALK_1      = 6,
    ACTION_KAIROZ_TALK_2      = 7,
    ACTION_KAIROZ_TALK_3      = 8,
    ACTION_KAIROZ_TALK_4      = 9,
    ACTION_KAIROZ_TALK_5      = 10,
    ACTION_CONVERSATION       = 11,
    ACTION_MOVE_CENTR_POSS    = 12,
    ACTION_CHIJI_END          = 13,
    ACTION_CHIJI_FAIL         = 14,
    ACTION_XUEN_END           = 15,
    ACTION_XUEN_FAIL          = 16,
    ACTION_YULON_END          = 17,
    ACTION_YULON_FAIL         = 18,
    ACTION_NIUZAO_END         = 19,
    ACTION_NIUZAO_FAIL        = 20
};

enum eEvents
{
    EVENT_PRINCE_TALK_1    = 1,
    EVENT_PRINCE_TALK_2    = 2,
    EVENT_PRINCE_TALK_3    = 3,
    EVENT_PRINCE_TALK_4    = 4,
    EVENT_PRINCE_TALK_5    = 5,
    EVENT_KAIROZ_TALK_1    = 6,
    EVENT_KAIROZ_TALK_2    = 7,
    EVENT_KAIROZ_TALK_3    = 8,
    EVENT_KAIROZ_TALK_4    = 9,
    EVENT_KAIROZ_TALK_5    = 10,
    //Annoncer
    EVENT_CHIJI_START = 1,
    EVENT_XUEN_START = 2,
    EVENT_YULON_START = 3,
    EVENT_NIUZAO_START = 4,
    EVENT_CHIJI_END = 5,
    EVENT_XUEN_END = 6,
    EVENT_YULON_END = 7,
    EVENT_NIUZAO_END = 8,
    //ChiJi
    EVENT_FIRESTORM = 3,
    EVENT_INSPIRING_SONG = 4,
    EVENT_BEACON = 5,
    EVENT_BLAZING_SONG = 6,
    //Xuen
    EVENT_CHI_BARRAGE = 3,
    EVENT_LIGHTNING = 4,
    EVENT_LEAP = 5,
    EVENT_SPECTRAL_SWIPE = 6,
    EVENT_AGILITY = 7,
    //Yulon
    EVENT_JADEFLAME_BUFFET = 3,
    EVENT_JADEFIRE_BREATH = 4,
    EVENT_JADEFIRE_BOLT = 5,
    EVENT_FIRE_WALL = 6,
    //Niuzao
    EVENT_MASSIVE_QUAKE = 3,
    EVENT_OXEN_FORTITUDE = 4,
    EVENT_HEADBUTT = 5,
    EVENT_MOVE_PATH_1 = 6,
    EVENT_MOVE_PATH_2 = 7
};

enum Spells
{
    SPELL_CELESTIAL_SPAWN = 149307,
    //ChiJi
    SPELL_FIRESTORM = 144461,
    SPELL_FIRESTORM_AURA = 144463,
    SPELL_INSPIRING_SONG = 144468,
    SPELL_BEACON_OF_HOPE = 144473,
    SPELL_BEACON_OF_HOPE_AURA = 144474,
    SPELL_BLAZING_SONG = 144471,
    SPELL_BLAZING_NOVA = 144493,
    SPELL_CRANE_RUSH = 144470,
    //Xuen
    SPELL_CHI_BARRAGE = 144642,
    SPELL_CRACKLING_LIGHTNING = 144635,
    SPELL_LEAP = 144640,
    SPELL_SPECTRAL_SWIPE = 144638,
    SPELL_AGILITY = 144631,
    //Yulon
    SPELL_JADEFLAME_BUFFET = 144630,
    SPELL_JADEFIRE_BREATH = 144530,
    SPELL_JADEFIRE_BOLT = 144545,
    SPELL_JADEFIRE_BLAZE = 144537,
    SPELL_JADEFIRE_WALL = 144533,
    //Niuzao
    SPELL_MASSIVE_QUAKE = 144611,
    SPELL_OXEN_FORTITUDE = 144606,
    SPELL_HEADBUTT = 144610,
    SPELL_CHARGE = 144608,

    //Ordos
    SPELL_BANISHMENT = 148705,

    //Other
    SPELL_GHOSTLY_VOID = 147495,
    SPELL_DESATURATE = 129290,
    SPELL_SPIRIT_STRANGLE = 144059
};

enum Says
{
    //Annoncer
    SAY_CHIJI_START = 0,
    SAY_CHIJI_FINISH = 1,
    SAY_XUEN_START = 2,
    SAY_XUEN_FINISH = 3,
    SAY_YULON_START = 4,
    SAY_YULON_FINISH = 5,
    SAY_NIUZAO_START = 6,
    SAY_NIUZAO_FINISH = 7,

    //Misc
    SAY_ENTER_POS = 0,
    SAY_AGGRO = 1,

    //ChiJi
    SAY_CHIJI_BEACON = 2,
    SAY_CHIJI_RUSH_1 = 4,
    SAY_CHIJI_BLAZ_SONG = 3,
    SAY_CHIJI_RUSH_2 = 5,
    SAY_CHIJI_END = 6,

    //Xuen
    SAY_XUEN_BARRAGE = 2,
    SAY_XUEN_LIGHTNING = 3,
    SAY_XUEN_PLAYER_DEATH = 4,
    SAY_XUEN_AGGILITY = 5,
    SAY_XUEN_END = 6,

    //Yulon
    SAY_YULON_PLAYER_DEATH = 2,
    SAY_YULON_WALL_1 = 3,
    SAY_YULON_WALL_2 = 4,
    SAY_YULON_END = 5,

    //Niuzao
    SAY_NIUZAO_CHARGE_1 = 2,
    SAY_NIUZAO_PLAYER_DEATH = 3,
    SAY_NIUZAO_QUAKE = 4,
    SAY_NIUZAO_CHARGE_2 = 5,
    SAY_NIUZAO_END = 6
};

#endif
