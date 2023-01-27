/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ZF_H
#define DEF_ZF_H

enum zfEntries
{
    ENTRY_ZUMRAH = 7271,
    ENTRY_BLY = 7604,
    ENTRY_RAVEN = 7605,
    ENTRY_ORO = 7606,
    ENTRY_WEEGLI = 7607,
    ENTRY_MURTA = 7608,
    ENTRY_UKORZ = 7267,

    GO_END_DOOR = 146084,

    EVENT_PYRAMID = 1,
    EVENT_GAHZRILLA = 2,
    EVENT_END_DOOR = 3,
    EVENT_ZUMRAH = 4,
};

enum zfPyramidPhases
{
    PYRAMID_NOT_STARTED, //default
    PYRAMID_CAGES_OPEN, //happens in GO hello for cages
    PYRAMID_ARRIVED_AT_STAIR , //happens in Weegli's movementinform
    PYRAMID_WAVE_1,
    PYRAMID_PRE_WAVE_2,
    PYRAMID_WAVE_2,
    PYRAMID_PRE_WAVE_3,
    PYRAMID_WAVE_3,
    PYRAMID_KILLED_ALL_TROLLS,
};

#endif