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
            dbReply.Timestamp = GameTime::GetGameTime();
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
    SendPacket(WorldPackets::Hotfix::AvailableHotfixes(version, sDB2Manager.GetHotfixCount(), sDB2Manager.GetHotfixData()).Write());
}

void WorldSession::HandleHotfixRequest(WorldPackets::Hotfix::HotfixRequest& hotfixQuery)
{
    DB2Manager::HotfixContainer const& hotfixes = sDB2Manager.GetHotfixData();
    WorldPackets::Hotfix::HotfixResponse hotfixQueryResponse;
    hotfixQueryResponse.Hotfixes.reserve(hotfixQuery.Hotfixes.size());
    for (DB2Manager::HotfixRecord const& hotfixRecord : hotfixQuery.Hotfixes)
    {
        if (hotfixes.find(hotfixRecord) != hotfixes.end())
        {
            DB2StorageBase const* storage = sDB2Manager.GetStorage(hotfixRecord.TableHash);

            WorldPackets::Hotfix::HotfixResponse::HotfixData hotfixData;
            hotfixData.Record = hotfixRecord;
            if (storage && storage->HasRecord(uint32(hotfixRecord.RecordID)))
            {
                std::size_t pos = hotfixQueryResponse.HotfixContent.size();
                storage->WriteRecord(uint32(hotfixRecord.RecordID), GetSessionDbcLocale(), hotfixQueryResponse.HotfixContent);
                hotfixData.Size = hotfixQueryResponse.HotfixContent.size() - pos;
            }
            else if (std::vector<uint8> const* blobData = sDB2Manager.GetHotfixBlobData(hotfixRecord.TableHash, hotfixRecord.RecordID, GetSessionDbcLocale()))
            {
                hotfixData.Size = blobData->size();
                hotfixQueryResponse.HotfixContent.append(blobData->data(), blobData->size());
            }

            hotfixQueryResponse.Hotfixes.emplace_back(std::move(hotfixData));
        }
    }

    SendPacket(hotfixQueryResponse.Write());
}
