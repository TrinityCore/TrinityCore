#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#include "precompiled.h"

enum CannonState
{
    CANNON_NOT_USED,
    CANNON_GUNPOWDER_USED,
    CANNON_BLAST_INITIATED,
    PIRATES_ATTACK,
    EVENT_DONE
};

enum Data
{
    EVENT_STATE
};

enum Data64
{
    DATA_SMITE_CHEST
};

enum GameObjects
{
    GO_IRONCLAD_DOOR                                       = 16397,
    GO_DEFIAS_CANNON                                       = 16398,
    GO_DOOR_LEVER                                          = 101833,
    GO_MR_SMITE_CHEST                                      = 144111
};
#endif

