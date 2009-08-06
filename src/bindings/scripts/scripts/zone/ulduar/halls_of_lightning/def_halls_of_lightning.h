/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_HALLS_OF_LIGHTNING_H
#define DEF_HALLS_OF_LIGHTNING_H

enum
{
    MAX_ENCOUNTER           = 4,

    DATA_BJARNGRIM          = 1,
    DATA_IONAR              = 2,
    DATA_LOKEN              = 3,
    DATA_VOLKHAN            = 4,

    TYPE_BJARNGRIM          = 10,
    TYPE_IONAR              = 11,
    TYPE_LOKEN              = 12,
    TYPE_VOLKHAN            = 13,

    NPC_BJARNGRIM           = 28586,
    NPC_VOLKHAN             = 28587,
    NPC_IONAR               = 28546,
    NPC_LOKEN               = 28923,

    GO_BJARNGRIM_DOOR       = 191416,                       //_doors10
    GO_VOLKHAN_DOOR         = 191325,                       //_doors07
    GO_IONAR_DOOR           = 191326,                       //_doors05
    GO_LOKEN_DOOR           = 191324,                       //_doors02
    GO_LOKEN_THRONE         = 192654
};

#endif
