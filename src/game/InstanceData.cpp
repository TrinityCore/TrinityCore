/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "InstanceData.h"
#include "Database/DatabaseEnv.h"
#include "Map.h"

void InstanceData::SaveToDB()
{
    if(!Save()) return;
    std::string data = Save();
    CharacterDatabase.escape_string(data);
    CharacterDatabase.PExecute("UPDATE instance SET data = '%s' WHERE id = '%d'", data.c_str(), instance->GetInstanceId());
}

void InstanceData::HandleGameObject(uint64 GUID, bool open, GameObject *go)
{
    if(!go)
        go = instance->GetGameObject(GUID);
    if(go)
        go->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    else
        debug_log("TSCR: InstanceData: HandleGameObject failed");
}

bool InstanceData::IsEncounterInProgress() const
{
    for(std::vector<BossInfo>::const_iterator itr = bosses.begin(); itr != bosses.end(); ++itr)
        if(itr->state == IN_PROGRESS)
            return true;

    return false;
}

//This will be removed in the future, just compitiable with Mangos
void InstanceData::OnCreatureCreate(Creature *creature, bool add)
{
    OnCreatureCreate(creature, creature->GetEntry(), add);
}

void InstanceData::SetBossRoomDoor(uint32 id, GameObject *door, bool add)
{
    if(id < bosses.size())
    {
        if(add)
        {
            BossInfo *bossInfo = &bosses[id];
            bossInfo->roomDoor.insert(door);
            // Room door is only closed when encounter is in progress
            if(bossInfo->state == IN_PROGRESS)
                door->SetGoState(GO_STATE_READY);
            else
                door->SetGoState(GO_STATE_ACTIVE);
        }
        else
            bosses[id].roomDoor.erase(door);
    }
}

void InstanceData::SetBossPassageDoor(uint32 id, GameObject *door, bool add)
{
    if(id < bosses.size())
    {
        if(add)
        {
            BossInfo *bossInfo = &bosses[id];
            bossInfo->passageDoor.insert(door);
            // Passage door is only opened when boss is defeated
            if(bossInfo->state == DONE)
                door->SetGoState(GO_STATE_ACTIVE);
            else
                door->SetGoState(GO_STATE_READY);
        }
        else
            bosses[id].passageDoor.erase(door);
    }
}

void InstanceData::SetBossState(uint32 id, EncounterState state)
{
    if(id < bosses.size())
    {
        BossInfo *bossInfo = &bosses[id];
        bossInfo->state = state;
        switch(state)
        {
        case NOT_STARTED:
            // Open all room doors, close all passage doors
            for(DoorSet::iterator i = bossInfo->roomDoor.begin(); i != bossInfo->roomDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_ACTIVE);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_READY);
            break;
        case IN_PROGRESS:
            // Close all doors
            for(DoorSet::iterator i = bossInfo->roomDoor.begin(); i != bossInfo->roomDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_READY);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_READY);
            break;
        case DONE:
            // Open all doors
            for(DoorSet::iterator i = bossInfo->roomDoor.begin(); i != bossInfo->roomDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_ACTIVE);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(GO_STATE_ACTIVE);
            break;
        default:
            break;
        }
    }
}

