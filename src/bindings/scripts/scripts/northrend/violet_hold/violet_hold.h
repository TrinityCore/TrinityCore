#ifndef DEF_VIOLET_HOLD_H
#define DEF_VIOLET_HOLD_H

enum Creatures
{
    CREATURE_TELEPORTATION_PORTAL                   = 31011,
    CREATURE_PORTAL_GUARDIAN                        = 30660,
    CREATURE_PORTAL_KEEPER                          = 30695,
    CREATURE_XEVOZZ                                 = 29266,
    CREATURE_LAVANTHOR                              = 29312,
    CREATURE_ICHORON                                = 29313,
    CREATURE_ZURAMAT                                = 29314,
    CREATURE_EREKEM                                 = 29315,
    CREATURE_EREKEM_GUARD                           = 29395,
    CREATURE_MORAGG                                 = 29316,
    CREATURE_CYANIGOSA                              = 31134,
    CREATURE_SINCLARI                               = 30658
};

enum Data
{
    DATA_1ST_BOSS_EVENT,
    DATA_2ND_BOSS_EVENT,
    DATA_CYANIGOSA_EVENT,
    DATA_WAVE_COUNT
};

enum Data64
{
    DATA_MORAGG,
    DATA_EREKEM,
    DATA_EREKEM_GUARD_1,
    DATA_EREKEM_GUARD_2,
    DATA_ICHORON,
    DATA_LAVANTHOR,
    DATA_XEVOZZ,
    DATA_ZURAMAT,
    DATA_CYANIGOSA,
    DATA_MORAGG_CELL,
    DATA_EREKEM_CELL,
    DATA_EREKEM_LEFT_GUARD_CELL,
    DATA_EREKEM_RIGHT_GUARD_CELL,
    DATA_ICHORON_CELL,
    DATA_LAVANTHOR_CELL,
    DATA_XEVOZZ_CELL,
    DATA_ZURAMAT_CELL,
    DATA_MAIN_DOOR,
    DATA_SINCLARI
};

enum WorldStates
{
    WORLD_STATE_VH          = 3816
};

#endif
