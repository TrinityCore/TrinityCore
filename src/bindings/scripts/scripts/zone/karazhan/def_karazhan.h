/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */


#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

enum
{
    DATA_ATTUMEN_EVENT              = 1,
    DATA_MOROES_EVENT               = 2,
    DATA_MAIDENOFVIRTUE_EVENT       = 3,
    DATA_OPTIONAL_BOSS_EVENT        = 4,
    DATA_OPERA_EVENT                = 5,
    DATA_CURATOR_EVENT              = 6,
    DATA_SHADEOFARAN_EVENT          = 7,
    DATA_TERESTIAN_EVENT            = 8,
    DATA_NETHERSPITE_EVENT          = 9,
    DATA_CHESS_EVENT                = 10,
    DATA_MALCHEZZAR_EVENT           = 11,
    DATA_NIGHTBANE_EVENT            = 12,
    DATA_OPERA_PERFORMANCE          = 13,
    DATA_OPERA_OZ_DEATHCOUNT        = 14,
    DATA_KILREK                     = 15,
    DATA_TERESTIAN                  = 16,
    DATA_MOROES                     = 17,
    DATA_GAMEOBJECT_CURTAINS        = 18,
    DATA_GAMEOBJECT_STAGEDOORLEFT   = 19,
    DATA_GAMEOBJECT_STAGEDOORRIGHT  = 20,
    DATA_GAMEOBJECT_LIBRARY_DOOR    = 21,
    DATA_GAMEOBJECT_MASSIVE_DOOR    = 22,
    DATA_GAMEOBJECT_NETHER_DOOR     = 23,
    DATA_GAMEOBJECT_GAME_DOOR       = 24,
    DATA_GAMEOBJECT_GAME_EXIT_DOOR  = 25,
    DATA_IMAGE_OF_MEDIVH            = 26,
    DATA_MASTERS_TERRACE_DOOR_1     = 27,
    DATA_MASTERS_TERRACE_DOOR_2     = 28,
    DATA_GO_SIDE_ENTRANCE_DOOR      = 29
};

enum OperaEvents
{
    EVENT_OZ                        = 1,
    EVENT_HOOD                      = 2,
    EVENT_RAJ                       = 3
};

#define ERROR_INST_DATA(a)          error_log("TSCR: Instance Data for Karazhan not set properly. Encounter for Creature Entry %u may not work properly.", a->GetEntry());
#endif

