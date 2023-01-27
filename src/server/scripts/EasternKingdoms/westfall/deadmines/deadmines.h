/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

enum
{
    INSTANCE_DM_MAX_ENCOUNTER           = 1,

    TYPE_DEFIAS_ENDDOOR     = 1,
    DATA_DEFIAS_DOOR        = 2,

    INST_SAY_ALARM1         = -1036000,
    INST_SAY_ALARM2         = -1036001,

    /** Doors which need to be opened automatically once the boss before died */
    GO_DOOR1                = 13965,
    GO_DOOR2                = 17153,
    GO_DOOR3                = 26182,

    GUN_POWDER_EVENT        = 5000,

    GO_DOOR_LEVER           = 101833,
    GO_IRON_CLAD            = 16397,
    GO_DEFIAS_CANNON        = 16398,
    GO_DMF_CHEST            = 180024,
    NPC_MR_SMITE            = 646,
    NPC_PIRATE              = 657,
    NPC_SNEED               = 643,
    NPC_RHAHKZOR            = 644,
    NPC_GILDNID             = 1763,

    QUEST_FORTUNE_AWAITS    = 7938
};

#endif
