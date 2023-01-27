/*
    https://uwow.biz/
*/

#ifndef ArmyTrainingH_
#define ArmyTrainingH_



enum eCreatures
{
    NPC_WITHERED_SPELL_CLICK        = 110141,

    NPC_COMMON_MINION               = 109011,
    NPC_BERSERK                     = 109012,
    NPC_WANTED_MANA                 = 109013,
    NPC_MAGE                        = 109014,
};


enum eSpells
{
    SPELL_COUNT_MINIONS     = 227261,
    SPELL_STARTED_OVERRIDE  = 216942,
    SPELL_SUMMON_CLICK      = 219220,

    SPELL_TELE_END          = 218193,
    SPELL_TELE_BEACON       = 218193,
    
    SPELL_SUMMON_COMMON     = 216747,
    SPELL_SUMMON_BERSERK    = 216750,
    SPELL_SUMMON_MAGE       = 216753,
    SPELL_SUMMON_WANTED_MANA = 216752,
    
    SPELL_OPEN_BERSERK      = 218195,
    SPELL_OPEN_MAGE         = 218270, // can find secret chests
    SPELL_OPEN_WANTED_MANA  = 218259,
    SPELL_OPEN_HP           = 218194,
    SPELL_OPEN_DMG          = 223740,
    SPELL_OPEN_EFFICIENT    = 218254,
    SPELL_OPEN_BRAVE        = 218252,

    SPELL_AURA_RAGE_MODE    = 216937,
    SPELL_AURA_FOLLOW_MODE  = 216938,

    SPELL_ADDITIONAL_HP     = 223762,
    SPELL_ADDITIONAL_DMG    = 223761,
    SPELL_JUMP_BACK         = 138439,
    SPELL_VISUAL_PICKUP_CHEST = 218088,

    SPELL_FEARED            = 218958,
};

enum Criterias
{
    CRITERIA_FIRST          = 52565,
    CRITERIA_SECOND         = 52566,
};

enum Convers
{
    CONV_FEARED             = 3436,
    CONV_WEB                = 3433, // ???
    CONV_GUARD              = 3435,
    CONV_ELFOLOM            = 3434,
    CONV_CHEST              = 3431,
    CONV_END                = 3439,
    CONV_TELE               = 3430,
};


#endif
