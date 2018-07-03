/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_ZULAMAN_H
#define DEF_ZULAMAN_H

#include "CreatureAIImpl.h"

uint32 const EncounterCount = 6;
#define ZulAmanScriptName "instance_zulaman"
#define DataHeader "ZA"

enum ZADataTypes
{
    // BossState
    DATA_AKILZON                = 0,
    DATA_NALORAKK               = 1,
    DATA_JANALAI                = 2,
    DATA_HALAZZI                = 3,
    DATA_HEXLORD                = 4,
    DATA_DAAKARA                = 5,

    // Data64
    DATA_HEXLORD_TRIGGER,

    DATA_STRANGE_GONG,
    DATA_MASSIVE_GATE,

    // SetData
    DATA_ZULAMAN_STATE
};

enum ZACreatureIds
{
    NPC_AKILZON                 = 23574,
    NPC_NALORAKK                = 23576,
    NPC_JANALAI                 = 23578,
    NPC_HALAZZI                 = 23577,
    NPC_HEXLORD                 = 24239,
    NPC_DAAKARA                 = 23863,

    NPC_VOLJIN                  = 52924,
    NPC_HEXLORD_TRIGGER         = 24363
};

enum ZAGameObjectIds
{
    GO_STRANGE_GONG             = 187359,
    GO_MASSIVE_GATE             = 186728,
};

enum ZAEvents
{
    EVENT_START_ZULAMAN         = 15897,
    EVENT_UPDATE_ZULAMAN_TIMER  = 1,
};

enum ZAAction
{
    ACTION_START_ZULAMAN        = 1
};

enum ZAWorldStates
{
    WORLD_STATE_ZULAMAN_TIMER_ENABLED   = 3104,
    WORLD_STATE_ZULAMAN_TIMER           = 3106,
};

template<typename AI>
CreatureAI* GetZulAmanAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, ZulAmanScriptName);
}

#endif
