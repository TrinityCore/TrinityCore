/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
        go = instance->GetGameObjectInMap(GUID);
    if(go)
        go->SetGoState(open ? 0 : 1);
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

void InstanceData::AddBossRoomDoor(uint32 id, GameObject *door)
{
    if(id < bosses.size())
    {
        BossInfo *bossInfo = &bosses[id];
        bossInfo->roomDoor.insert(door);
        // Room door is only closed when encounter is in progress
        if(bossInfo->state == IN_PROGRESS)
            door->SetGoState(1);
        else
            door->SetGoState(0);
    }
}

void InstanceData::AddBossPassageDoor(uint32 id, GameObject *door)
{
    if(id < bosses.size())
    {
        BossInfo *bossInfo = &bosses[id];
        bossInfo->passageDoor.insert(door);
        // Passage door is only opened when boss is defeated
        if(bossInfo->state == DONE)
            door->SetGoState(0);
        else
            door->SetGoState(1);
    }
}

void InstanceData::RemoveBossRoomDoor(uint32 id, GameObject *door)
{
    if(id < bosses.size())
    {
        bosses[id].roomDoor.erase(door);
    }
}

void InstanceData::RemoveBossPassageDoor(uint32 id, GameObject *door)
{
    if(id < bosses.size())
    {
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
                (*i)->SetGoState(0);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(1);
            break;
        case IN_PROGRESS:
            // Close all doors
            for(DoorSet::iterator i = bossInfo->roomDoor.begin(); i != bossInfo->roomDoor.end(); ++i)
                (*i)->SetGoState(1);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(1);
            break;
        case DONE:
            // Open all doors
            for(DoorSet::iterator i = bossInfo->roomDoor.begin(); i != bossInfo->roomDoor.end(); ++i)
                (*i)->SetGoState(0);
            for(DoorSet::iterator i = bossInfo->passageDoor.begin(); i != bossInfo->passageDoor.end(); ++i)
                (*i)->SetGoState(0);
            break;
        default:
            break;
        }
    }
}

