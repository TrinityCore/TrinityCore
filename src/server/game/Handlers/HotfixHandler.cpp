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

#include "WorldSession.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "HotfixPackets.h"
#include "Log.h"
#include "ObjectDefines.h"
#include "World.h"

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

void WorldSession::SendAvailableHotfixes(int32 version)
{
    SendPacket(WorldPackets::Hotfix::AvailableHotfixes(version, sDB2Manager.GetHotfixData()).Write());
}

void WorldSession::HandleHotfixRequest(WorldPackets::Hotfix::HotfixRequest& hotfixQuery)
{
    std::map<uint64, int32> const& hotfixes = sDB2Manager.GetHotfixData();
    WorldPackets::Hotfix::HotfixResponse hotfixQueryResponse;
    hotfixQueryResponse.Hotfixes.reserve(hotfixQuery.Hotfixes.size());
    for (uint64 hotfixId : hotfixQuery.Hotfixes)
    {
        if (int32 const* hotfix = Trinity::Containers::MapGetValuePtr(hotfixes, hotfixId))
        {
            DB2StorageBase const* storage = sDB2Manager.GetStorage(PAIR64_HIPART(hotfixId));

            WorldPackets::Hotfix::HotfixResponse::HotfixData hotfixData;
            hotfixData.ID = hotfixId;
            hotfixData.RecordID = *hotfix;
            if (storage->HasRecord(hotfixData.RecordID))
            {
                hotfixData.Data = boost::in_place();
                storage->WriteRecord(hotfixData.RecordID, GetSessionDbcLocale(), *hotfixData.Data);
            }

            hotfixQueryResponse.Hotfixes.emplace_back(std::move(hotfixData));
        }
    }

    SendPacket(hotfixQueryResponse.Write());
}
