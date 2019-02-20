/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#include "CreatureAIImpl.h"

#define DMScriptName "instance_deadmines"
#define DataHeader "DM"

enum DMCannonState
{
    CANNON_NOT_USED,
    CANNON_GUNPOWDER_USED,
    CANNON_BLAST_INITIATED,
    PIRATES_ATTACK,
    SMITE_ALARMED,
    EVENT_DONE
};

enum DMData
{
    EVENT_STATE,
    EVENT_RHAHKZOR,

    DATA_MR_SMITE = 0,  // not currently used
    DATA_VANCLEEF = 1
};

enum DMData64
{
    DATA_SMITE_CHEST
};

enum DMGameObjects
{
    GO_FACTORY_DOOR                                        = 13965,
    GO_IRONCLAD_DOOR                                       = 16397,
    GO_DEFIAS_CANNON                                       = 16398,
    GO_DOOR_LEVER                                          = 101833,
    GO_MR_SMITE_CHEST                                      = 144111
};

enum DMCreaturesIds
{
    NPC_MR_SMITE   = 646,
    NPC_BLACKGUARD = 636
};

enum DMInstanceTexts
{
    SAY_ALARM1 = 0,
    SAY_ALARM2 = 1
};

template <class AI, class T>
inline AI* GetDeadminesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, DMScriptName);
}

#define RegisterDeadminesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDeadminesAI)

#endif
