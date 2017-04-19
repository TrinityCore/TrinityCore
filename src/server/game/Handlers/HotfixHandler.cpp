/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "HotfixPackets.h"
#include "Log.h"

void WorldSession::HandleDBQueryBulk(WorldPackets::Hotfix::DBQueryBulk& dbQuery)
{
    DB2StorageBase const* store = sDB2Manager.GetStorage(dbQuery.TableHash);
    if (!store)
    {
        TC_LOG_ERROR("network", "CMSG_DB_QUERY_BULK: %s requested unsupported unknown hotfix type: %u", GetPlayerInfo().c_str(), dbQuery.TableHash);
        return;
    }

    for (WorldPackets::Hotfix::DBQueryBulk::DBQueryRecord const& record : dbQuery.Queries)
    {
        WorldPackets::Hotfix::DBReply dbReply;
        dbReply.TableHash = dbQuery.TableHash;
        dbReply.RecordID = record.RecordID;

        if (store->HasRecord(record.RecordID))
        {
            dbReply.Allow = true;
            dbReply.Timestamp = sWorld->GetGameTime();
            store->WriteRecord(record.RecordID, GetSessionDbcLocale(), dbReply.Data);
        }
        else
        {
            TC_LOG_TRACE("network", "CMSG_DB_QUERY_BULK: %s requested non-existing entry %u in datastore: %u", GetPlayerInfo().c_str(), record.RecordID, dbQuery.TableHash);
            dbReply.Timestamp = time(NULL);
        }

        SendPacket(dbReply.Write());
    }
}

void WorldSession::SendHotfixList(int32 version)
{
    SendPacket(WorldPackets::Hotfix::HotfixList(version, sDB2Manager.GetHotfixData()).Write());
}

void WorldSession::HandleHotfixQuery(WorldPackets::Hotfix::HotfixQuery& hotfixQuery)
{
    std::map<int32, HotfixData> const& hotfixes = sDB2Manager.GetHotfixData();
    WorldPackets::Hotfix::HotfixQueryResponse hotfixQueryResponse;
    hotfixQueryResponse.Hotfixes.reserve(hotfixQuery.Hotfixes.size());
    for (int32 hotfixId : hotfixQuery.Hotfixes)
    {
        if (HotfixData const* hotfix = Trinity::Containers::MapGetValuePtr(hotfixes, hotfixId))
        {
            WorldPackets::Hotfix::HotfixQueryResponse::HotfixData hotfixData;
            hotfixData.ID = hotfix->Id;

            for (HotfixRecord const& hotfixRecord : hotfix->Records)
            {
                DB2StorageBase const* storage = sDB2Manager.GetStorage(hotfixRecord.TableHash);

                WorldPackets::Hotfix::HotfixQueryResponse::HotfixRecord record;
                record.TableHash = hotfixRecord.TableHash;
                record.RecordID = hotfixRecord.RecordId;
                if (storage->HasRecord(hotfixRecord.RecordId))
                {
                    record.HotfixData = boost::in_place();
                    storage->WriteRecord(hotfixRecord.RecordId, GetSessionDbcLocale(), *record.HotfixData);
                }

                hotfixData.Records.emplace_back(std::move(record));
            }

            hotfixQueryResponse.Hotfixes.emplace_back(std::move(hotfixData));
        }
    }

    SendPacket(hotfixQueryResponse.Write());
}
