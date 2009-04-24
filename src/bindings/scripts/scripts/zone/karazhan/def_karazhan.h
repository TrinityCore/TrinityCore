/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_KARAZHAN_H
#define DEF_KARAZHAN_H

#define DATA_ATTUMEN_EVENT               1
#define DATA_MOROES_EVENT                2
#define DATA_MAIDENOFVIRTUE_EVENT        3
#define DATA_OPTIONAL_BOSS_EVENT         4
#define DATA_OPERA_EVENT                 5
#define DATA_CURATOR_EVENT               6
#define DATA_SHADEOFARAN_EVENT           7
#define DATA_TERESTIAN_EVENT             8
#define DATA_NETHERSPITE_EVENT           9
#define DATA_CHESS_EVENT                10
#define DATA_MALCHEZZAR_EVENT           11
#define DATA_NIGHTBANE_EVENT            12
#define DATA_OPERA_PERFORMANCE          13
#define DATA_OPERA_OZ_DEATHCOUNT        14
#define DATA_KILREK                     15
#define DATA_TERESTIAN                  16
#define DATA_MOROES                     17
#define DATA_GAMEOBJECT_CURTAINS        18
#define DATA_GAMEOBJECT_STAGEDOORLEFT   19
#define DATA_GAMEOBJECT_STAGEDOORRIGHT  20
#define DATA_GAMEOBJECT_LIBRARY_DOOR    21
#define DATA_GAMEOBJECT_MASSIVE_DOOR    22
#define DATA_GAMEOBJECT_NETHER_DOOR     23
#define DATA_GAMEOBJECT_GAME_DOOR       24
#define DATA_GAMEOBJECT_GAME_EXIT_DOOR  25
#define DATA_IMAGE_OF_MEDIVH            26
#define DATA_MASTERS_TERRACE_DOOR_1     27
#define DATA_MASTERS_TERRACE_DOOR_2     28

// Opera Performances
#define EVENT_OZ        1
#define EVENT_HOOD      2
#define EVENT_RAJ       3

#define ERROR_INST_DATA(a)     error_log("TSCR: Instance Data for Karazhan not set properly. Encounter for Creature Entry %u may not work properly.", a->GetEntry());
#endif

