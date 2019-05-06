/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_THE_BOTANICA_H
#define DEF_THE_BOTANICA_H

#include "CreatureAIImpl.h"

#define BotanicaScriptName "instance_the_botanica"
#define DataHeader "BC"

uint32 const EncounterCount = 5;

enum BCDataTypes
{
    DATA_COMMANDER_SARANNIS             = 0,
    DATA_HIGH_BOTANIST_FREYWINN         = 1,
    DATA_THORNGRIN_THE_TENDER           = 2,
    DATA_LAJ                            = 3,
    DATA_WARP_SPLINTER                  = 4
};

enum BCCreatureIds
{
    NPC_COMMANDER_SARANNIS              = 17976,
    NPC_HIGH_BOTANIST_FREYWINN          = 17975,
    NPC_THORNGRIN_THE_TENDER            = 17978,
    NPC_LAJ                             = 17980,
    NPC_WARP_SPLINTER                   = 17977
};

template <class AI, class T>
inline AI* GetBotanicaAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BotanicaScriptName);
}

#endif
