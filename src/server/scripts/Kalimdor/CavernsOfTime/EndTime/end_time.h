/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

#include "Map.h"
#include "CreatureAI.h"
#include "ObjectMgr.h"

#ifndef DEF_END_TIME_H
#define DEF_END_TIME_H

#define EndTimeScriptName "instance_end_time"

enum DataTypes
{
    DATA_BAINE = 0,
    DATA_JAINA,
    DATA_SYLVANAS,
    DATA_TYRANDE,
    DATA_MUROZOND,
    FIRST_BOSS,
    SECOND_BOSS,
    DATA_MUROZOND_TRASH,
    DATA_MUROZOND_STARTED,
    DATA_BOSS_COUNT,
};

enum Npcs
{
    NPC_ECHO_OF_BAINE       = 54431,
    NPC_ECHO_OF_JAINA       = 54445,
    NPC_ECHO_OF_SYLVANAS    = 54123,
    NPC_ECHO_OF_TYRANDE     = 54544,
    NPC_ECHO_OF_MUROZOND    = 54432,
};

enum TeleporterSpells
{
    AZURE_DRAGONSHIRINE_TELEPORT    = 102126,
    RUBY_DRAGONSHIRINE_TELEPORT     = 102579,
    BLACK_DRAGONSHIRINE_TELEPORT    = 103868,
    EMERALD_DRAGONSHIRINE_TELEPORT  = 104761,
    BRONZE_DRAGONSHIRINE_TELEPORT   = 104764
};

enum CreaturesIds
{
    NPC_INFINITE_SUPPRESSOR             = 54920,
    NPC_INFINITE_WARDEN                 = 54923,
    NPC_TRIGGER_HOURGLASS_TIME          = 54928,
    NPC_BOSS_MUROZOND                   = 54432,
};

enum Actions
{
    ACTION_MUROZOND_START                   = -500000,
    ACTION_MUROZOND_REMOVE_TEMPORAL_BOMB    = -500001,
    ACTION_MUROZOND_REMOVE_HOURGLASS_BAR    = -500002,
    ACTION_TYRANDE_START                    = -500003,
};

template<class AI>
CreatureAI* GetEndTimelAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(EndTimeScriptName))
                return new AI(creature);
    return NULL;
}

#endif // DEF_END_TIME_H
