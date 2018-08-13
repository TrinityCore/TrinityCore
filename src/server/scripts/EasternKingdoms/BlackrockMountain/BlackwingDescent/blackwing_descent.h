#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

enum Data
{
    //Encounters
    DATA_MAGMAW,
    DATA_OMNOTRON_DEFENSE_SYSTEM,
    DATA_MALORIAK,
    DATA_CHIMAERON,
    DATA_ATRAMEDES,
    DATA_NEFARIAN,
    DATA_ABBERATIONS_LEFT,
    DATA_DRAKONID
};

enum Creatures
{
    BOSS_MAGMAW                     = 41570,
    BOSS_OMNOTRON                   = 42186,
    BOSS_MALORIAK                   = 41378,
    BOSS_ATRAMEDES                  = 41442,
    BOSS_CHIMAERON                  = 43296,
    BOSS_NEFARIAN                   = 41376,

    // Magmaw
    NPC_MAGMAWS_HEAD                = 42347,
    NPC_IGNITION_TRIGGER            = 49447,
    NPC_LAVA_PARASITE               = 41806,
    NPC_PILLAR_OF_FLAME_TRIGGER     = 41843,
    NPC_BLAZING_BONE_CONSTRUCT      = 49416,
    NPC_DRAGONID_DRUDGE             = 42362,
    NPC_MAGMAWS_HEAD2               = 48270,
    NPC_MAGMAWS_PINCER              = 41620,
    NPC_MAGMAWS_PINCER2             = 41789,
    NPC_SPIKE_STALKER               = 41767,

    // Omnotron Defense System
    // Toxitron
    NPC_TOXITRON                    = 42180,

    NPC_POISON_BOMB                 = 42897,
    NPC_POISON_CLOUD                = 42934,

    // Arcanotron
    NPC_ARCANOTRON                  = 42166,
    NPC_POWER_GENERATOR             = 42733,

    // Electron
    NPC_ELECTRON                    = 42179,

    // Magmatron
    NPC_MAGMATRON                   = 42178,

    // Chimaeron
    NPC_BILE_O_TRON                 = 44418,
    NPC_FINKLE_EINHORN = 44202,

    // Maloriak
    NPC_ABBERATON                   = 41440,
    NPC_PRIME_SUBJECT               = 41841,
    NPC_SLIME_TRIGGER               = 41377,
    NPC_FLASH_FREEZE                = 41576,
    NPC_MAGMA_JET_CONTROLLER        = 50030,
    NPC_ABSOLUTE_ZERO               = 41961,
    NPC_VILE_SWILL                  = 49811,

    // Atramedes
    // Pre Event
    NPC_PRE_MALORIAK                = 43404,
    NPC_PRE_NEFARIAN                = 49799,
    NPC_PRE_ATRAMEDES               = 43407,
    NPC_PRE_LIGHT_EFFECT            = 41525,

    NPC_SONAR_PULSE                 = 49623,
    NPC_OBNOXIOUS_FIEND             = 49740,

    // Nefarian
    NPC_ONYXIA = 41270,

    // Misc
    NPC_NEFARIAN_HELPER_HEROIC      = 49226,
    NPC_LORD_VICTOR_NEFARIAN        = 41379,
    NPC_DRAKONID_CHAIN              = 42649,
};

enum Gameobjects
{
    GOB_DOOR_PRE_BOSSES             = 402092,
    GOB_DOOR_ATRAMEDES              = 402368,
    GOB_ONYXIA_PLATFORM             = 207834,
    GOB_MALORIAKS_CAULDRON          = 203306,
    GOB_NEFARIANS_THRONE            = 202832,
};

#endif
