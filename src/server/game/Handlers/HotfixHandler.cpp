/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameTime.h"
#include "HotfixPackets.h"
#include "Log.h"
#include "ObjectDefines.h"
#include "Realm.h"
#include "World.h"

void WorldSession::HandleDBQueryBulk(WorldPackets::Hotfix::DBQueryBulk& dbQuery)
{
    DB2StorageBase const* store = sDB2Manager.GetStorage(dbQuery.TableHash);
    for (WorldPackets::Hotfix::DBQueryBulk::DBQueryRecord const& record : dbQuery.Queries)
    {
        WorldPackets::Hotfix::DBReply dbReply;
        dbReply.TableHash = dbQuery.TableHash;
        dbReply.RecordID = record.RecordID;

        if (store && store->HasRecord(record.RecordID))
        {
            dbReply.Status = DB2Manager::HotfixRecord::Status::Valid;
            dbReply.Timestamp = GameTime::GetGameTime();
            store->WriteRecord(record.RecordID, GetSessionDbcLocale(), dbReply.Data);

            if (std::vector<DB2Manager::HotfixOptionalData> const* optionalDataEntries = sDB2Manager.GetHotfixOptionalData(dbQuery.TableHash, record.RecordID, GetSessionDbcLocale()))
            {
                for (DB2Manager::HotfixOptionalData const& optionalData : *optionalDataEntries)
                {
                    dbReply.Data << uint32(optionalData.Key);
                    dbReply.Data.append(optionalData.Data.data(), optionalData.Data.size());
                }
            }
        }
        else
        {
            TC_LOG_TRACE("network", "CMSG_DB_QUERY_BULK: %s requested non-existing entry %u in datastore: %u", GetPlayerInfo().c_str(), record.RecordID, dbQuery.TableHash);
            dbReply.Timestamp = GameTime::GetGameTime();
        }

        SendPacket(dbReply.Write());
    }
}

void WorldSession::SendAvailableHotfixes()
{
    SendPacket(WorldPackets::Hotfix::AvailableHotfixes(realm.Id.GetAddress(), sDB2Manager.GetHotfixData()).Write());
}

void WorldSession::HandleHotfixRequest(WorldPackets::Hotfix::HotfixRequest& hotfixQuery)
{
    DB2Manager::HotfixContainer const& hotfixes = sDB2Manager.GetHotfixData();
    WorldPackets::Hotfix::HotfixConnect hotfixQueryResponse;
    hotfixQueryResponse.Hotfixes.reserve(hotfixQuery.Hotfixes.size());
    for (int32 hotfixId : hotfixQuery.Hotfixes)
    {
        if (std::vector<DB2Manager::HotfixRecord> const* hotfixRecords = Trinity::Containers::MapGetValuePtr(hotfixes, hotfixId))
        {
            for (DB2Manager::HotfixRecord const& hotfixRecord : *hotfixRecords)
            {
                hotfixQueryResponse.Hotfixes.emplace_back();

                WorldPackets::Hotfix::HotfixConnect::HotfixData& hotfixData = hotfixQueryResponse.Hotfixes.back();
                hotfixData.Record = hotfixRecord;
                if (hotfixRecord.HotfixStatus == DB2Manager::HotfixRecord::Status::Valid)
                {
                    DB2StorageBase const* storage = sDB2Manager.GetStorage(hotfixRecord.TableHash);
                    if (storage && storage->HasRecord(uint32(hotfixRecord.RecordID)))
                    {
                        std::size_t pos = hotfixQueryResponse.HotfixContent.size();
                        storage->WriteRecord(uint32(hotfixRecord.RecordID), GetSessionDbcLocale(), hotfixQueryResponse.HotfixContent);

                        if (std::vector<DB2Manager::HotfixOptionalData> const* optionalDataEntries = sDB2Manager.GetHotfixOptionalData(hotfixRecord.TableHash, hotfixRecord.RecordID, GetSessionDbcLocale()))
                        {
                            for (DB2Manager::HotfixOptionalData const& optionalData : *optionalDataEntries)
                            {
                                hotfixQueryResponse.HotfixContent << uint32(optionalData.Key);
                                hotfixQueryResponse.HotfixContent.append(optionalData.Data.data(), optionalData.Data.size());
                            }
                        }

                        hotfixData.Size = hotfixQueryResponse.HotfixContent.size() - pos;
                    }
                    else if (std::vector<uint8> const* blobData = sDB2Manager.GetHotfixBlobData(hotfixRecord.TableHash, hotfixRecord.RecordID, GetSessionDbcLocale()))
                    {
                        hotfixData.Size = blobData->size();
                        hotfixQueryResponse.HotfixContent.append(blobData->data(), blobData->size());
                    }
                }
            }
        }
    }

    SendPacket(hotfixQueryResponse.Write());
}
