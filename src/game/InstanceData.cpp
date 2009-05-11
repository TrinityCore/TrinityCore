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
#include "GameObject.h"
#include "Creature.h"

void InstanceData::SaveToDB()
{
    std::string data = GetSaveData();
    if(data.empty())
        return;
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
    OnCreatureCreate(creature, creature->GetEntry());
}

void InstanceData::LoadDoorData(const DoorData *data)
{
    while(data->entry)
    {
        if(data->bossId < bosses.size())
            doors.insert(std::make_pair(data->entry, DoorInfo(&bosses[data->bossId], data->type)));

        ++data;
    }
    sLog.outDebug("InstanceData::LoadDoorData: %u doors loaded.", doors.size());
}

void InstanceData::UpdateDoorState(GameObject *door)
{
    DoorInfoMap::iterator lower = doors.lower_bound(door->GetEntry());
    DoorInfoMap::iterator upper = doors.upper_bound(door->GetEntry());
    if(lower == upper)
        return;

    bool open = true;
    for(DoorInfoMap::iterator itr = lower; itr != upper; ++itr)
    {
        if(itr->second.type == DOOR_TYPE_ROOM)
        {
            if(itr->second.bossInfo->state == IN_PROGRESS)
            {
                open = false;
                break;
            }
        }
        else if(itr->second.type == DOOR_TYPE_PASSAGE)
        {
            if(itr->second.bossInfo->state != DONE)
            {
                open = false;
                break;
            }
        }
    }

    door->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
}

void InstanceData::AddDoor(GameObject *door, bool add)
{
    DoorInfoMap::iterator lower = doors.lower_bound(door->GetEntry());
    DoorInfoMap::iterator upper = doors.upper_bound(door->GetEntry());
    if(lower == upper)
        return;

    for(DoorInfoMap::iterator itr = lower; itr != upper; ++itr)
    {
        if(add)
            itr->second.bossInfo->door[itr->second.type].insert(door);
        else
            itr->second.bossInfo->door[itr->second.type].erase(door);
    }

    if(add)
        UpdateDoorState(door);
}

void InstanceData::SetBossState(uint32 id, EncounterState state)
{
    if(id < bosses.size())
    {
        BossInfo *bossInfo = &bosses[id];
        if(bossInfo->state == TO_BE_DECIDED) // loading
            bossInfo->state = state;
        else
        {
            if(bossInfo->state == state)
                return;
            bossInfo->state = state;
            SaveToDB();
        }
        
        for(uint32 type = 0; type < MAX_DOOR_TYPES; ++type)
            for(DoorSet::iterator i = bossInfo->door[type].begin(); i != bossInfo->door[type].end(); ++i)
                UpdateDoorState(*i);
    }
}

std::string InstanceData::LoadBossState(const char * data)
{
    if(!data) return NULL;
    std::istringstream loadStream(data);
    uint32 buff;
    uint32 bossId = 0;
    for(std::vector<BossInfo>::iterator i = bosses.begin(); i != bosses.end(); ++i, ++bossId)
    {
        loadStream >> buff;
        if(buff < TO_BE_DECIDED)
            SetBossState(bossId, (EncounterState)buff);
    }
    return loadStream.str();
}

std::string InstanceData::GetBossSaveData()
{
    std::ostringstream saveStream;
    for(std::vector<BossInfo>::iterator i = bosses.begin(); i != bosses.end(); ++i)
        saveStream << (uint32)i->state << " ";
    return saveStream.str();
}   
