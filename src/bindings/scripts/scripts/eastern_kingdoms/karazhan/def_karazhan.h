/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */


#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

enum eEnums
{
    TYPE_ATTUMEN                    = 1,
    TYPE_MOROES                     = 2,
    TYPE_MAIDEN                     = 3,
    TYPE_OPTIONAL_BOSS              = 4,
    TYPE_OPERA                      = 5,
    TYPE_CURATOR                    = 6,
    TYPE_ARAN                       = 7,
    TYPE_TERESTIAN                  = 8,
    TYPE_NETHERSPITE                = 9,
    TYPE_CHESS                      = 10,
    TYPE_MALCHEZZAR                 = 11,
    TYPE_NIGHTBANE                  = 12,

    DATA_OPERA_PERFORMANCE          = 13,
    DATA_OPERA_OZ_DEATHCOUNT        = 14,

    DATA_KILREK                     = 15,
    DATA_TERESTIAN                  = 16,
    DATA_MOROES                     = 17,
    DATA_GO_CURTAINS                = 18,
    DATA_GO_STAGEDOORLEFT           = 19,
    DATA_GO_STAGEDOORRIGHT          = 20,
    DATA_GO_LIBRARY_DOOR            = 21,
    DATA_GO_MASSIVE_DOOR            = 22,
    DATA_GO_NETHER_DOOR             = 23,
    DATA_GO_GAME_DOOR               = 24,
    DATA_GO_GAME_EXIT_DOOR          = 25,

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

