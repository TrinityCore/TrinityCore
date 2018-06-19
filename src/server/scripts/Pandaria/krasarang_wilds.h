#ifndef KRASARANG_WILDS_H
#define KRASARANG_WILDS_H

enum eSpells
{
    SPELL_GRAPPLING_HOOK         = 125623,
    SPELL_VANISH                 = 125632,
    SPELL_VICIOUS_REND           = 125624,
    SPELL_SHADOWBOLT             = 125212,
    SPELL_VOIDCLOUD              = 125241,
    SPELL_DEVASTATING_ARC        = 124946,
    SPELL_SUMMON_QUILEN          = 124980,
    SPELL_TITANIC_STRENGTH       = 124976,
    SPELL_BLADE_FURY             = 125370,
    SPELL_TORNADO                = 125398,
    SPELL_TORNADO_DMG            = 131693,
    SPELL_WINDSONG               = 125373,
    SPELL_BELLOWING_RAGE         = 124297,
    SPELL_RUSHING_CHARGE         = 124302,
    SPELL_YAUNGOL_STOMP          = 124289,
    SPELL_CHI_TORPEDO            = 119539,
    SPELL_FLYING_SERPENT_KICK    = 119500,
    SPELL_HUNDRED_HAND_SLAP      = 119074,
    SPELL_SPINNING_CRANE_KICK    = 119018,
    SPELL_UPPERCUT               = 119498,
    SPELL_WHEELBARROW_ROLL       = 119520,
    SPELL_JAB                    = 119007,
    SPELL_KICK                   = 119008,
    SPELL_CRY_OUT_IN_DESPAIR     = 132095,
    SPELL_SHA_BLAST              = 117009,
    SPELL_SHA_SPIKE              = 117010,
    SPELL_FIERCE_JAB             = 119004,
    SPELL_FIERCE_KICK            = 119006,
    SPELL_FISTS_OF_FURY          = 119014,
    SPELL_VICIOUS_KICK           = 119010,
    SPELL_BREATH_OF_FIRE         = 132165,
    SPELL_STORM_STOUT            = 119070,
    SPELL_FAT_LONG_FLOP          = 119057,
    SPELL_WHEELBARROW_ROLL_2     = 119517,
    SPELL_WHEEL_PUNCH            = 119526,
    SPELL_ROLLING_THROW          = 67546,
    SPELL_EVASION                = 90958,
    SPELL_FLUID_LIKE_WATR        = 119077,
    SPELL_STILL_WATERS_RUN_DEEP  = 119078,
    SPELL_SOOTHING_MIST          = 132218,
    SPELL_PAW_PUNCH              = 119496,
    SPELL_SUNFLARE_KICK          = 119535,
    SPELL_SUNSTRIKE              = 119538,
    SPELL_POUND_YOU              = 119510,
    SPELL_KICK_YOU               = 119506,
    SPELL_PUNCH_YOU              = 119504
};

enum eEvents
{
    EVENT_GRAPPLING_HOOK         = 1,
    EVENT_VANISH                 = 2,
    EVENT_VICIOUS_REND           = 3,
    EVENT_SHADOWBOLT             = 4,
    EVENT_VOIDCLOUD              = 5,
    EVENT_DEVASTATING_ARC        = 6,
    EVENT_SUMMON_QUILEN          = 7,
    EVENT_TITANIC_STRENGTH       = 8,
    EVENT_BLADE_FURY             = 9,
    EVENT_TORNADO                = 10,
    EVENT_WINDSONG               = 11,
    EVENT_BELLOWING_RAGE         = 12,
    EVENT_RUSHING_CHARGE         = 13,
    EVENT_YAUNGOL_STOMP          = 14,
    EVENT_CHI_TORPEDO            = 15,
    EVENT_FLYING_SERPENT_KICK    = 16,
    EVENT_HUNDRED_HAND_SLAP      = 17,
    EVENT_SPINNING_CRANE_KICK    = 18,
    EVENT_UPPERCUT               = 19,
    EVENT_WHEELBARROW_ROLL       = 20,
    EVENT_JAB                    = 21,
    EVENT_KICK                   = 22,
    EVENT_CRY_OUT_IN_DESPAIR     = 23,
    EVENT_SHA_BLAST              = 24,
    EVENT_SHA_SPIKE              = 25,
    EVENT_FIERCE_JAB             = 26,
    EVENT_FIERCE_KICK            = 27,
    EVENT_FISTS_OF_FURY          = 28,
    EVENT_VICIOUS_KICK           = 29,
    EVENT_FIERCE_JAB_2           = 30,
    EVENT_BREATH_OF_FIRE         = 31,
    EVENT_STORM_STOUT            = 32,
    EVENT_FAT_LONG_FLOP          = 33,
    EVENT_BREATH_OF_FIRE_2       = 34,
    EVENT_STORM_STOUT_2          = 35,
    EVENT_WHEELBARROW_ROLL_2     = 36,
    EVENT_WHEEL_PUNCH            = 37,
    EVENT_ROLLING_THROW          = 38,
    EVENT_EVASION                = 39,
    EVENT_FLUID_LIKE_WATR        = 40,
    EVENT_STILL_WATERS_RUN_DEEP  = 41,
    EVENT_SOOTHING_MIST          = 42,
    EVENT_FLYING_SERPENT_KICK_2  = 43,
    EVENT_PAW_PUNCH              = 44,
    EVENT_UPPERCUT_2             = 45,
    EVENT_SUNFLARE_KICK          = 46,
    EVENT_SUNSTRIKE              = 47,
    EVENT_POUND_YOU              = 48,
    EVENT_KICK_YOU               = 49,
    EVENT_PUNCH_YOU              = 50,
    EVENT_DESPAWN                = 51,
    EVENT_CHECK_TARGET           = 52
};

enum eQuests
{
    QuestChasingHope             = 30716,
    QuestInTheHouseOfTheRedCrane = 30273,
    QuestAKingAmonMen            = 32247
};

enum eActions
{
    ACTION_REMOVE_FLAG          = 1,
    ACTION_REINITIALIZE         = 2
};

enum eCreatures
{
    MOB_TORNADO         = 64267,
    NPC_ANDUIN_WRYNN    = 66975
};

#endif
