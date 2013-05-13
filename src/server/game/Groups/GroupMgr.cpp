/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "GroupMgr.h"
#include "InstanceSaveMgr.h"
#include "World.h"
#include "DBCStores.h"

GroupMgr::GroupMgr()
{
    NextGroupDbStoreId = 1;
    NextGroupId = 1;
}

GroupMgr::~GroupMgr()
{
    for (GroupContainer::iterator itr = GroupStore.begin(); itr != GroupStore.end(); ++itr)
        delete itr->second;
}

uint32 GroupMgr::GenerateNewGroupDbStoreId()
{
    uint32 newStorageId = NextGroupDbStoreId;

    for (uint32 i = ++NextGroupDbStoreId; i < 0xFFFFFFFF; ++i)
    {
        if ((i < GroupDbStore.size() && GroupDbStore[i] == NULL) || i >= GroupDbStore.size())
        {
            NextGroupDbStoreId = i;
            break;
        }
    }

    if (newStorageId == NextGroupDbStoreId)
    {
        TC_LOG_ERROR(LOG_FILTER_GENERAL, "Group storage ID overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }

    return newStorageId;
}

void GroupMgr::RegisterGroupDbStoreId(uint32 storageId, Group* group)
{
    // Allocate space if necessary.
    if (storageId >= uint32(GroupDbStore.size()))
        GroupDbStore.resize(storageId + 1);

    GroupDbStore[storageId] = group;
}

void GroupMgr::FreeGroupDbStoreId(Group* group)
{
    uint32 storageId = group->GetDbStoreId();

    if (storageId < NextGroupDbStoreId)
        NextGroupDbStoreId = storageId;

    GroupDbStore[storageId] = NULL;
}

Group* GroupMgr::GetGroupByDbStoreId(uint32 storageId) const
{
    if (storageId < GroupDbStore.size())
        return GroupDbStore[storageId];

    return NULL;
}

uint32 GroupMgr::GenerateGroupId()
{
    if (NextGroupId >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR(LOG_FILTER_GENERAL, "Group guid overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return NextGroupId++;
}

Group* GroupMgr::GetGroupByGUID(uint32 groupId) const
{
    GroupContainer::const_iterator itr = GroupStore.find(groupId);
    if (itr != GroupStore.end())
        return itr->second;

    return NULL;
}

void GroupMgr::AddGroup(Group* group)
{
    GroupStore[group->GetLowGUID()] = group;
}

void GroupMgr::RemoveGroup(Group* group)
{
    GroupStore.erase(group->GetLowGUID());
}

void GroupMgr::LoadGroups()
{
    {
        uint32 oldMSTime = getMSTime();

        // Delete all groups whose leader does not exist
        CharacterDatabase.DirectExecute("DELETE FROM groups WHERE leaderGuid NOT IN (SELECT guid FROM characters)");
        // Delete all groups with less than 2 members
        CharacterDatabase.DirectExecute("DELETE FROM groups WHERE guid NOT IN (SELECT guid FROM group_member GROUP BY guid HAVING COUNT(guid) > 1)");

        //                                                        0              1           2             3                 4      5          6      7         8       9
        QueryResult result = CharacterDatabase.Query("SELECT g.leaderGuid, g.lootMethod, g.looterGuid, g.lootThreshold, g.icon1, g.icon2, g.icon3, g.icon4, g.icon5, g.icon6"
            //  10         11          12         13              14            15         16           17
            ", g.icon7, g.icon8, g.groupType, g.difficulty, g.raiddifficulty, g.guid, lfg.dungeon, lfg.state FROM groups g LEFT JOIN lfg_data lfg ON lfg.guid = g.guid ORDER BY g.guid ASC");
        if (!result)
        {
            TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 group definitions. DB table `groups` is empty!");
            return;
        }

        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();
            Group* group = new Group;
            group->LoadGroupFromDB(fields);
            AddGroup(group);

            // Get the ID used for storing the group in the database and register it in the pool.
            uint32 storageId = group->GetDbStoreId();

            RegisterGroupDbStoreId(storageId, group);

            // Increase the next available storage ID
            if (storageId == NextGroupDbStoreId)
                NextGroupDbStoreId++;

            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u group definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Loading Group members...");
    {
        uint32 oldMSTime = getMSTime();

        // Delete all rows from group_member or group_instance with no group
        CharacterDatabase.DirectExecute("DELETE FROM group_member WHERE guid NOT IN (SELECT guid FROM groups)");
        CharacterDatabase.DirectExecute("DELETE FROM group_instance WHERE guid NOT IN (SELECT guid FROM groups)");
        // Delete all members that does not exist
        CharacterDatabase.DirectExecute("DELETE FROM group_member WHERE memberGuid NOT IN (SELECT guid FROM characters)");

        //                                                    0        1           2            3       4
        QueryResult result = CharacterDatabase.Query("SELECT guid, memberGuid, memberFlags, subgroup, roles FROM group_member ORDER BY guid");
        if (!result)
        {
            TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 group members. DB table `group_member` is empty!");
            return;
        }

        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();
            Group* group = GetGroupByDbStoreId(fields[0].GetUInt32());

            if (group)
                group->LoadMemberFromDB(fields[1].GetUInt32(), fields[2].GetUInt8(), fields[3].GetUInt8(), fields[4].GetUInt8());
            else
                TC_LOG_ERROR(LOG_FILTER_GENERAL, "GroupMgr::LoadGroups: Consistency failed, can't find group (storage id: %u)", fields[0].GetUInt32());

            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u group members in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Loading Group instance saves...");
    {
        uint32 oldMSTime = getMSTime();
        //                                                   0           1        2              3             4             5            6
        QueryResult result = CharacterDatabase.Query("SELECT gi.guid, i.map, gi.instance, gi.permanent, i.difficulty, i.resettime, COUNT(g.guid) "
            "FROM group_instance gi INNER JOIN instance i ON gi.instance = i.id "
            "LEFT JOIN character_instance ci LEFT JOIN groups g ON g.leaderGuid = ci.guid ON ci.instance = gi.instance AND ci.permanent = 1 GROUP BY gi.instance ORDER BY gi.guid");
        if (!result)
        {
            TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 group-instance saves. DB table `group_instance` is empty!");
            return;
        }

        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();
            Group* group = GetGroupByDbStoreId(fields[0].GetUInt32());
            // group will never be NULL (we have run consistency sql's before loading)

            MapEntry const* mapEntry = sMapStore.LookupEntry(fields[1].GetUInt16());
            if (!mapEntry || !mapEntry->IsDungeon())
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Incorrect entry in group_instance table : no dungeon map %d", fields[1].GetUInt16());
                continue;
            }

            uint32 diff = fields[4].GetUInt8();
            if (diff >= uint32(mapEntry->IsRaid() ? MAX_RAID_DIFFICULTY : MAX_DUNGEON_DIFFICULTY))
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Wrong dungeon difficulty use in group_instance table: %d", diff + 1);
                diff = 0;                                   // default for both difficaly types
            }

            InstanceSave* save = sInstanceSaveMgr->AddInstanceSave(mapEntry->MapID, fields[2].GetUInt32(), Difficulty(diff), time_t(fields[5].GetUInt32()), (bool)fields[6].GetUInt64(), true);
            group->BindToInstance(save, fields[3].GetBool(), true);
            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u group-instance saves in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
}
