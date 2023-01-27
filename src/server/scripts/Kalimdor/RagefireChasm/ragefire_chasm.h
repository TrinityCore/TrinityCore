/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_RAGEFIRECHASM_H
#define DEF_RAGEFIRECHASM_H

#define RCScriptName "instance_ragefire_chasm"

// enumerate all bosses 0-x
enum Bosses
{
    BOSS_OGGLEFLINT = 0,
    BOSS_JERGOSH_THE_INVOKER,
    BOSS_BAZZALAN,
    BOSS_TARAGAMAN_THE_HUNGERER,
    MAX_BOSS_ENCOUNTER
};

// enumerate all npc where you want to store GUID
enum Data64
{
    DATA_OGGLEFLINT = 0,
    DATA_JERGOSH_THE_INVOKER,
    DATA_BAZZALAN,
    DATA_TARAGAMAN_THE_HUNGERER,
    MAX_DATA_ENCOUNTER
};

// enumerate all gameobject and the entry's 
enum GameObjectsIds
{
    GO_ = 12345,

};

// enumerate all creatures and the entry's 
enum CreatureIds
{
    NPC_OGGLEFLINT = 11517,
    NPC_JERGOSH_THE_INVOKER = 11518,
    NPC_BAZZALAN = 11519,
    NPC_TARAGAMAN_THE_HUNGERER = 11520,
};

template<class AI>
CreatureAI* GetRagefireChasmAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
//            if (instance->GetScriptId() == sObjectMgr->GetScriptId(RCScriptName))
                return new AI(creature);

    return NULL;
}

template<class AI, class T>
AI* GetRagefireChasmAI(T* obj)
{
    return GetInstanceAI<AI, T>(obj, RCScriptName);
}

#endif
