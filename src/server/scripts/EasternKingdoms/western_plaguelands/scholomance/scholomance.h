/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_SCHOLOMANCE_H
#define DEF_SCHOLOMANCE_H

enum
{
    GO_GATE_KIRTONOS        = 175570,
    GO_BRAZIER_KIRTONOS     = 175564,
    GO_GATE_GANDLING        = 177374,
    GO_GATE_MALICIA         = 177375,
    GO_GATE_THEOLEN         = 177377,
    GO_GATE_POLKELT         = 177376,
    GO_GATE_RAVENIAN        = 177372,
    GO_GATE_BAROV           = 177373,
    GO_GATE_ILLUCIA         = 177371,
    GO_VIEWING_ROOM_DOOR    = 175167,

    SOUND_SCREECH           = 557,

    NPC_KIRTONOS            = 10506,
    NPC_GANDLING            = 1853,
    NPC_VECTUS              = 10432,
    NPC_MARDUKE             = 10433,

    NPC_J_EEVEE             = 14500
};

enum
{
    TYPE_GANDLING           = 0,
    TYPE_THEOLEN            = 1,
    TYPE_MALICIA            = 2,
    TYPE_ILLUCIABAROV       = 3,
    TYPE_ALEXEIBAROV        = 4,
    TYPE_POLKELT            = 5,
    TYPE_RAVENIAN           = 6,
    TYPE_KIRTONOS           = 7,
    TYPE_VIEWING_ROOM_DOOR  = 14,
    INSTANCE_SCHOLOMANCE_MAX_ENCOUNTER =15,


    DATA_VECTUS            = 16,
    DATA_MARDUKE           = 17,
};
#endif
