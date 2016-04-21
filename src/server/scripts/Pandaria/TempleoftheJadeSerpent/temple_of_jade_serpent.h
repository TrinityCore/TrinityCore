#ifndef DEF_TEMPLE_OF_JADE_SERPENT_H
#define DEF_TEMPLE_OF_JADE_SERPENT_H

enum eSpells
{
    SPELL_CORRUPTED_WATERS      = 106778,

};

enum eCreatures
{
    CREATURE_WISE_MARI              = 56448,

    CREATURE_LOREWALKTER_STONESTEP  = 56843,
    CREATURE_SCROLL                 = 57080,


    CREATURE_JIANG                  = 59547,
    CREATURE_XIANG                  = 65317,

    CREATURE_ZAO_SUNSEEKER          = 58826,
    CREATURE_SUN                    = 56915,
    CREATURE_SUN_2                  = 58815,
    CREATURE_HAUNTING_SHA           = 58865,


    CREATURE_OSONG                  = 56872,
    CREATURE_STRIFE                 = 59726,
    CREATURE_PERIL                  = 59051,

    CREATURE_MINION_OF_DOUBTS       = 57109,
    CREATURE_LIU_FLAMEHEART         = 56732,
    CREATURE_YU_LON                 = 56762,
    CREATURE_JADE_FIRE              = 56893,

    CREATURE_FIGMENT_OF_DOUBT       = 56792,
    CREATURE_SHA_OF_DOUBT           = 56439,
};

enum eGameObjects
{
    GAMEOBJECT_DOOR_WISE_MARI           = 213550,
    GAMEOBJECT_DOOR_WISE_MARI_ENTRANCE  = 211280,
    GAMEOBJECT_DOOR_LOREWALKER_STONSTEP = 213549,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART      = 213548,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART_2    = 213544,
    GAMEOBJECT_DOOR_SHA_OF_DOUBT        = 999999, //Todo : find the good value
};

enum eData
{
    DATA_WISE_MARI_EVENT = 0,
    DATA_LOREWALKER_STONESTEP_EVENT = 1,
    DATA_LIU_FLAMEHEART_EVENT = 2,
    DATA_SHA_OF_DOUBT_EVENT = 3
};

#endif