/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "Language.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "UpdateMask.h"
#include "NPCHandler.h"
#include "Pet.h"
#include "MapManager.h"
#include "CharacterPackets.h"
#include "QueryPackets.h"

void WorldSession::SendNameQueryOpcode(ObjectGuid guid)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);

    WorldPackets::Query::QueryPlayerNameResponse response;
    response.Player = guid;

    if (response.Data.Initialize(guid, player))
        response.Result = RESPONSE_SUCCESS; // name known
    else
        response.Result = RESPONSE_FAILURE; // name unknown

    SendPacket(response.Write());
}

void WorldSession::HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& packet)
{
    SendNameQueryOpcode(packet.Player);
}

void WorldSession::HandleQueryTimeOpcode(WorldPackets::Query::QueryTime& /*queryTime*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPackets::Query::QueryTimeResponse queryTimeResponse;
    queryTimeResponse.CurrentTime = time(nullptr);
    queryTimeResponse.TimeOutRequest = sWorld->GetNextDailyQuestsResetTime() - queryTimeResponse.CurrentTime;
    SendPacket(queryTimeResponse.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleCreatureQuery(WorldPackets::Query::QueryCreature& packet)
{
    WorldPackets::Query::QueryCreatureResponse response;

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(packet.CreatureID);

    response.CreatureID = packet.CreatureID;

    if (creatureInfo)
    {
        response.Allow = true;

        WorldPackets::Query::CreatureStats& stats = response.Stats;

        stats.Title = creatureInfo->SubName;
        stats.CursorName = creatureInfo->IconName;
        stats.CreatureType = creatureInfo->type;
        stats.CreatureFamily = creatureInfo->family;
        stats.Classification = creatureInfo->rank;
        stats.HpMulti = creatureInfo->ModHealth;
        stats.EnergyMulti = creatureInfo->ModMana;
        stats.Leader = creatureInfo->RacialLeader;

        CreatureQuestItemList* items = sObjectMgr->GetCreatureQuestItemList(packet.CreatureID);
        if (items)
            for (uint32 item : *items)
                stats.QuestItems.push_back(item);

        stats.CreatureMovementInfoID = creatureInfo->movementId;
        stats.RequiredExpansion = creatureInfo->expansionUnknown;
        stats.Flags[0] = creatureInfo->type_flags;
        stats.Flags[1] = creatureInfo->type_flags2;
        for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
            stats.ProxyCreatureID[i] = creatureInfo->KillCredit[i];
        stats.CreatureDisplayID[0] = creatureInfo->Modelid1;
        stats.CreatureDisplayID[1] = creatureInfo->Modelid2;
        stats.CreatureDisplayID[2] = creatureInfo->Modelid3;
        stats.CreatureDisplayID[3] = creatureInfo->Modelid4;
        stats.Name[0] = creatureInfo->Name;
        stats.NameAlt[0] = creatureInfo->FemaleName;
    }
    else
        response.Allow = false;

    SendPacket(response.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& packet)
{
    WorldPackets::Query::QueryGameObjectResponse response;

    response.GameObjectID = packet.GameObjectID;

    if (GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate(packet.GameObjectID))
    {
        response.Allow = true;
        WorldPackets::Query::GameObjectStats& stats = response.Stats;

        stats.CastBarCaption = gameObjectInfo->castBarCaption;
        stats.DisplayID = gameObjectInfo->displayId;
        stats.IconName = gameObjectInfo->IconName;
        stats.Name[0] = gameObjectInfo->name;

        GameObjectQuestItemList* items = sObjectMgr->GetGameObjectQuestItemList(packet.GameObjectID);
        if (items)
            for (uint32 item : *items)
                stats.QuestItems.push_back(item);

        for (uint32 i = 0; i < MAX_GAMEOBJECT_DATA; i++)
            stats.Data[i] = gameObjectInfo->raw.data[i];

        stats.Size = gameObjectInfo->size;
        stats.Type = gameObjectInfo->type;
        stats.UnkString = gameObjectInfo->unk1;
        stats.Expansion = 0;
    }
    else
        response.Allow = false;

    SendPacket(response.Write());
}

void WorldSession::HandleQueryCorpseLocation(WorldPackets::Query::QueryCorpseLocationFromClient& /*packet*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUERY_CORPSE_LOCATION_FROM_CLIENT");

    Corpse* corpse = GetPlayer()->GetCorpse();

    if (!corpse)
    {
        WorldPackets::Query::CorpseLocation packet;
        packet.Valid = false;                               // corpse not found
        SendPacket(packet.Write());
        return;
    }

    uint32 mapID = corpse->GetMapId();
    float x = corpse->GetPositionX();
    float y = corpse->GetPositionY();
    float z = corpse->GetPositionZ();
    uint32 corpseMapID = mapID;

    // if corpse at different map
    if (mapID != _player->GetMapId())
    {
        // search entrance map for proper show entrance
        if (MapEntry const* corpseMapEntry = sMapStore.LookupEntry(mapID))
        {
            if (corpseMapEntry->IsDungeon() && corpseMapEntry->CorpseMapID >= 0)
            {
                // if corpse map have entrance
                if (Map const* entranceMap = sMapMgr->CreateBaseMap(corpseMapEntry->CorpseMapID))
                {
                    mapID = corpseMapEntry->CorpseMapID;
                    x = corpseMapEntry->CorpsePos.X;
                    y = corpseMapEntry->CorpsePos.Y;
                    z = entranceMap->GetHeight(GetPlayer()->GetPhaseMask(), x, y, MAX_HEIGHT);
                }
            }
        }
    }

    WorldPackets::Query::CorpseLocation packet;
    packet.Valid = true;
    packet.MapID = corpseMapID;
    packet.ActualMapID = mapID;
    packet.Position = G3D::Vector3(x, y, z);
    packet.Transport = corpse->GetTransGUID();
    SendPacket(packet.Write());
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: %u", packet.TextID);

    GossipText const* gossip = sObjectMgr->GetGossipText(packet.TextID);

    WorldPackets::Query::QueryNPCTextResponse response;
    response.TextID = packet.TextID;

    bool hasText = false;
    if (gossip)
    {
        for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
        {
            response.Probabilities[i] = gossip->Options[i].Probability;
            response.BroadcastTextID[i] = gossip->Options[i].BroadcastTextID;
            if (!hasText && gossip->Options[i].BroadcastTextID)
                hasText = true;
        }

        response.Allow = true;
    }
    if (hasText)
        SendPacket(response.Write());
    else
        TC_LOG_ERROR("sql.sql", "HandleNpcTextQueryOpcode: no BroadcastTextID found for text %u in `npc_text table`", packet.TextID);
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_NPC_TEXT_UPDATE");
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandlePageTextQueryOpcode(WorldPackets::Query::QueryPageText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_PAGE_TEXT_QUERY");

    uint32 pageID = packet.PageTextID;

    while (pageID)
    {
        PageText const* pageText = sObjectMgr->GetPageText(pageID);

        WorldPackets::Query::QueryPageTextResponse response;
        response.PageTextID = pageID;

        if (!pageText)
        {
            response.Allow = false;
            pageID = 0;
        }
        else
        {
            response.Allow = true;
            response.Info.ID = pageID;

            int loc_idx = GetSessionDbLocaleIndex();
            if (loc_idx >= 0)
                if (PageTextLocale const* player = sObjectMgr->GetPageTextLocale(pageID))
                    ObjectMgr::GetLocaleString(player->Text, loc_idx, response.Info.Text);

            response.Info.NextPageID = pageText->NextPageID;
            pageID = pageText->NextPageID;
        }

        SendPacket(response.Write());

        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_PAGE_TEXT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleQueryCorpseTransport(WorldPackets::Query::QueryCorpseTransport& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_QUERY_CORPSE_TRANSPORT");

    Corpse* corpse = _player->GetCorpse();

    WorldPackets::Query::CorpseTransportQuery response;
    if (!corpse || corpse->GetTransGUID().IsEmpty() || corpse->GetTransGUID() != packet.Transport)
    {
        response.Position = G3D::Vector3(0.0f, 0.0f, 0.0f);
        response.Facing = 0.0f;
    }
    else
    {
        response.Position = G3D::Vector3(corpse->GetTransOffsetX(), corpse->GetTransOffsetY(), corpse->GetTransOffsetZ());
        response.Facing = corpse->GetTransOffsetO();
    }

    SendPacket(response.Write());
}

void WorldSession::HandleQuestNPCQuery(WorldPacket& recvData)
{
    uint32 count = recvData.ReadBits(24);
    std::map<uint32, std::vector<uint32>> quests;

    for (uint32 i = 0; i < count; ++i)
    {
        uint32 questId;
        recvData >> questId;

        if (!sObjectMgr->GetQuestTemplate(questId))
        {
            TC_LOG_DEBUG("network", "WORLD: Unknown quest %u in CMSG_QUERY_QUEST_COMPLETION_NPCS by %s", questId, _player->GetGUID().ToString().c_str());
            continue;
        }

        auto creatures = sObjectMgr->GetCreatureQuestInvolvedRelationReverseBounds(questId);
        for (auto it = creatures.first; it != creatures.second; ++it)
            quests[questId].push_back(it->second);

        auto gos = sObjectMgr->GetGOQuestInvolvedRelationReverseBounds(questId);
        for (auto it = gos.first; it != gos.second; ++it)
            quests[questId].push_back(it->second | 0x80000000); // GO mask
    }

    WorldPacket data(SMSG_QUEST_COMPLETION_NPC_RESPONSE, 3 + quests.size() * 14);
    data.WriteBits(quests.size(), 23);

    for (auto it = quests.begin(); it != quests.end(); ++it)
        data.WriteBits(it->second.size(), 24);

    for (auto it = quests.begin(); it != quests.end(); ++it)
    {
        data << uint32(it->first);
        for (const auto& entry : it->second)
            data << uint32(entry);
    }

    SendPacket(&data);
}

void WorldSession::HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& packet)
{
    if (packet.MissingQuestCount > MAX_QUEST_LOG_SIZE)
        return;

    // Read quest ids and add the in a unordered_set so we don't send POIs for the same quest multiple times
    std::unordered_set<int32> questIds;
    for (int32 i = 0; i < packet.MissingQuestCount; ++i)
        questIds.insert(packet.MissingQuestPOIs[i]); // QuestID

    WorldPackets::Query::QuestPOIQueryResponse response;

    for (auto itr = questIds.begin(); itr != questIds.end(); ++itr)
    {
        int32 QuestID = *itr;

        bool questOk = false;

        uint16 questSlot = _player->FindQuestSlot(uint32(QuestID));

        if (questSlot != MAX_QUEST_LOG_SIZE)
            questOk = _player->GetQuestSlotQuestId(questSlot) == QuestID;

        if (questOk)
        {
            QuestPOIVector const* poiData = sObjectMgr->GetQuestPOIVector(QuestID);
            if (poiData)
            {
                WorldPackets::Query::QuestPOIData questPOIData;

                questPOIData.QuestID = QuestID;

                for (auto data = poiData->begin(); data != poiData->end(); ++data)
                {
                    WorldPackets::Query::QuestPOIBlobData questPOIBlobData;

                    questPOIBlobData.BlobIndex          = data->BlobIndex;
                    questPOIBlobData.ObjectiveIndex     = data->ObjectiveIndex;
                    questPOIBlobData.QuestObjectiveID   = data->QuestObjectiveID;
                    questPOIBlobData.QuestObjectID      = data->QuestObjectID;
                    questPOIBlobData.MapID              = data->MapID;
                    questPOIBlobData.WorldMapAreaID     = data->WorldMapAreaID;
                    questPOIBlobData.Floor              = data->Floor;
                    questPOIBlobData.Priority           = data->Priority;
                    questPOIBlobData.Flags              = data->Flags;
                    questPOIBlobData.WorldEffectID      = data->WorldEffectID;
                    questPOIBlobData.PlayerConditionID  = data->PlayerConditionID;
                    questPOIBlobData.UnkWoD1            = data->UnkWoD1;

                    for (auto points = data->points.begin(); points != data->points.end(); ++points)
                    {
                        WorldPackets::Query::QuestPOIBlobPoint questPOIBlobPoint;

                        questPOIBlobPoint.X = points->X;
                        questPOIBlobPoint.Y = points->Y;

                        TC_LOG_ERROR("misc", "Quest: %i BlobIndex: %i X/Y: %i/%i", QuestID, data->BlobIndex, points->X, points->Y);

                        questPOIBlobData.QuestPOIBlobPointStats.push_back(questPOIBlobPoint);
                    }

                    questPOIData.QuestPOIBlobDataStats.push_back(questPOIBlobData);
                }

                response.QuestPOIDataStats.push_back(questPOIData);
            }
        }
    }

    SendPacket(response.Write());
}

void WorldSession::HandleDBQueryBulk(WorldPackets::Query::DBQueryBulk& packet)
{
    DB2StorageBase const* store = sDB2Manager.GetStorage(packet.TableHash);
    if (!store)
    {
        TC_LOG_ERROR("network", "CMSG_DB_QUERY_BULK: %s requested unsupported unknown hotfix type: %u", GetPlayerInfo().c_str(), packet.TableHash);
        return;
    }

    for (WorldPackets::Query::DBQueryBulk::DBQueryRecord const& rec : packet.Queries)
    {
        WorldPackets::Query::DBReply response;
        response.TableHash = packet.TableHash;

        if (store->HasRecord(rec.RecordID))
        {
            response.RecordID = rec.RecordID;
            response.Timestamp = sDB2Manager.GetHotfixDate(rec.RecordID, packet.TableHash);
            store->WriteRecord(rec.RecordID, GetSessionDbcLocale(), response.Data);
        }
        else
        {
            TC_LOG_TRACE("network", "CMSG_DB_QUERY_BULK: %s requested non-existing entry %u in datastore: %u", GetPlayerInfo().c_str(), rec.RecordID, packet.TableHash);
            response.RecordID = -int32(rec.RecordID);
            response.Timestamp = time(NULL);
        }

        SendPacket(response.Write());
    }
}
