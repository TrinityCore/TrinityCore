#ifndef JADE_FOREST_H
#define JADE_FOREST_H

enum eSpells
{
    SPELL_DEAFENED                  = 108918,
    SPELL_SHA_BOLT                  = 126139,
    SPELL_GROWING_DOUBT             = 126147,
    SPELL_SHADOWBOLT                = 125212,
    SPELL_VOIDCLOUD                 = 125241,
    SPELL_BLADE_FURY                = 125370,
    SPELL_STEALTH                   = 128933,
    SPELL_TORNADO                   = 125398,
    SPELL_TORNADO_DMG               = 131693,
    SPELL_WINDSONG                  = 125373,
    SPELL_GOING_BANANAS             = 125363,
    SPELL_BANANARANG                = 125311,
    SPELL_TOSS_FILTH                = 125365,
    SPELL_BOUCLIER_D_EAU            = 79892,
    SPELL_BOUCLIER_D_EAU_2          = 34828,
    SPELL_BOUCLIER_DE_TERRE         = 79927,
    SPELL_CARAPACE_BOUCLIER         = 83488,
    SPELL_MOT_DE_POUVOIR            = 11835,
    SPELL_SHOOT                     = 23337,
    SPELL_CLEAVE                    = 40505,
    SPELL_SWAMP_FEVER               = 116026,
    SPELL_BLOODY_PREY               = 131145,
    SPELL_CLAW_RIP                  = 131130,
    SPELL_GROWL                     = 2649,
    SPELL_HOWL_OF_THE_DENMOTHER     = 131199,
    SPELL_ROAR_OF_COURAGE           = 93435,
    SPELL_CLAW_SLASH                = 131133,
    SPELL_BLOOD_CRAZED              = 131150,
    SPELL_BLOODTHIRST               = 131141,
    SPELL_FRENZY                    =  19615,
    SPELL_SHADOW_CLAW               = 116128,
    SPELL_OVERWHELMING_GUILT        = 131150,
    SPELL_THUNDERING_PALM           = 109497,
    SPELL_WIND_SWORD                = 113504,
    SPELL_WINDFUR_PUNCH             = 105497, // Needs to be scripted
    SPELL_ROLL                      = 113512,
    SPELL_STAFF_STRIKE              = 84647,
    SPELL_THROW_BRAMBLESTAFF        = 106763,
    SPELL_WHIRLWIND                 = 15576, // Needs to be scripted
    SPELL_WHIRLWIND_2               = 17207, // Needs to be scripted
    SPELL_EXPLOSIVE_LAGER           = 104909,
    SPELL_FIRE_ALE                  = 105091,
    SPELL_FORCE_BURST               = 129858,
    SPELL_KNOCK_AWAY                = 129837,
    SPELL_PULL_CLOSE                = 129839,
    SPELL_RACE_AGAINST_THE_CLOCK    = 129772,
    SPELL_WAR_STOMP                 = 129831,
    SPELL_FRENZY_2                  = 19615,
    SPELL_SPIRIT_BEAST_BLESSING     = 127830,
    SPELL_SPIRIT_HEAL_2             = 138477,
    SPELL_SPIRIT_MEND               = 90361,
    SPELL_STRONG_WILL               = 138472,
    SPELL_GIFT_OF_CHI_JI            = 129929,
    SPELL_BLESSING_OF_CHI_JI        = 129919,
    SPELL_WRATH_OF_CHI_JI           = 129917,
    SPELL_BLACKOUT_KICK             = 129112,
    SPELL_FLYING_SERPENT_KICK       = 119500,
    SPELL_JAB                       = 119007,
    SPELL_MIGHTY_CHOP               = 129636,
    SPELL_STRIKE_FROM_THE_HEAVENS   = 129869
};

enum eEvents
{
    EVENT_DEAFENED                  = 1,
    EVENT_GROWING_DOUBT             = 2,
    EVENT_SHA_BOLT                  = 3,
    EVENT_SHADOWBOLT                = 4,
    EVENT_VOIDCLOUD                 = 5,
    EVENT_BLADE_FURY                = 6,
    EVENT_TORNADO                   = 7,
    EVENT_WINDSONG                  = 8,
    EVENT_GOING_BANANAS             = 9,
    EVENT_BANANARANG                = 10,
    EVENT_TOSS_FILTH                = 11,
    EVENT_BOUCLIER_D_EAU            = 12,
    EVENT_BOUCLIER_D_EAU_2          = 13,
    EVENT_BOUCLIER_DE_TERRE         = 14,
    EVENT_CARAPACE_BOUCLIER         = 15,
    EVENT_MOT_DE_POUVOIR            = 16,
    EVENT_SHOOT                     = 17,
    EVENT_CLEAVE                    = 18,
    EVENT_SWAMP_FEVER               = 19,
    EVENT_BLOODY_PREY               = 20,
    EVENT_CLAW_RIP                  = 21,
    EVENT_GROWL                     = 22,
    EVENT_HOWL_OF_THE_DENMOTHER     = 23,
    EVENT_ROAR_OF_COURAGE           = 24,
    EVENT_BLOOD_CRAZED              = 25,
    EVENT_BLOODTHIRST               = 26,
    EVENT_CLAW_SLASH                = 27,
    EVENT_FRENZY                    = 28,
    EVENT_SHADOW_CLAW               = 29,
    EVENT_OVERWHELMING_GUILT        = 30,
    EVENT_THUNDERING_PALM           = 31,
    EVENT_WIND_SWORD                = 32,
    EVENT_WINDFUR_PUNCH             = 33, // Script needed
    EVENT_ROLL                      = 34,
    EVENT_STAFF_STRIKE              = 35,
    EVENT_THROW_BRAMBLESTAFF        = 36,
    EVENT_WHIRLWIND                 = 37, // Script needed
    EVENT_WHIRLWIND_2               = 38, // Script needed
    EVENT_EXPLOSIVE_LAGER           = 39,
    EVENT_FIRE_ALE                  = 40,
    EVENT_FORCE_BURST               = 41,
    EVENT_KNOCK_AWAY                = 42,
    EVENT_PULL_CLOSE                = 43,
    EVENT_WAR_STOMP                 = 44,
    EVENT_FRENZY_2                  = 45,
    EVENT_SPIRIT_BEAST_BLESSING     = 46,
    EVENT_SPIRIT_HEAL               = 47,
    EVENT_CHECK_PLAYER              = 48,
    EVENT_CHECK_TARGET              = 49,
    EVENT_GIFT_OF_CHI_JI            = 50,
    EVENT_BLESSING_OF_CHI_JI        = 51,
    EVENT_WRATH_OF_CHI_JI           = 52,
    EVENT_BLACKOUT_KICK             = 53,
    EVENT_FLYING_SERPENT_KICK       = 54,
    EVENT_JAB                       = 55,
    EVENT_MIGHTY_CHOP               = 56,
    EVENT_STRIKE_FROM_THE_HEAVENS   = 57,
    EVENT_DESPAWN                   = 58
};

enum eQuests
{
    QUEST_GETTING_PERMISSION        = 29920,
    QUEST_TRAINER_S_CHALLENGE       = 31718,
    QUEST_RIDING_THE_SKIES_FIRST    = 31811,
    QUEST_RIDING_THE_SKIES_SECOND   = 31810,
    QUEST_RIDING_THE_SKIES_THIRD    = 30188
};

enum eActions
{
    ACTION_SET_FLAG     = 1,
    ACTION_REINITIALIZE = 2,
    ACTION_REMOVE_FLAG  = 3
};

enum eCreatures
{
    NPC_PANDRIARCH_WINDFUR      = 56206,
    NPC_PANDRIARCH_BRAMBLESTAFF = 56209,
    NPC_PANDRIARCH_GOLDENDRAFT  = 56210,
    MOB_BIG_BAO                 = 58508,
    NPC_INSTRUCTOR_WINDBLADE    = 58594
};

#endif
