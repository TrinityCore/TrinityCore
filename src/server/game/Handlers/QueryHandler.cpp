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
#include "BattlenetAccountMgr.h"
#include "CharacterPackets.h"
#include "QueryPackets.h"

void WorldSession::SendNameQueryOpcode(ObjectGuid guid)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid);

    WorldPackets::Query::QueryPlayerNameResponse response;
    response.Player = guid;

    if (characterInfo)
    {
        uint32 accountId = player ? player->GetSession()->GetAccountId() : ObjectMgr::GetPlayerAccountIdByGUID(guid);
        uint32 bnetAccountId = player ? player->GetSession()->GetBattlenetAccountId() : Battlenet::AccountMgr::GetIdByGameAccount(accountId);

        response.Result             = RESPONSE_SUCCESS; // name known
        response.Data.IsDeleted     = characterInfo->IsDeleted;
        response.Data.AccountID     = ObjectGuid::Create<HighGuid::WowAccount>(accountId);
        response.Data.BnetAccountID = ObjectGuid::Create<HighGuid::BNetAccount>(bnetAccountId);
        response.Data.Name          = characterInfo->Name;
        response.Data.VirtualRealmAddress = GetVirtualRealmAddress();
        response.Data.Race          = characterInfo->Race;
        response.Data.Sex           = characterInfo->Sex;
        response.Data.ClassID       = characterInfo->Class;
        response.Data.Level         = characterInfo->Level;

        if (DeclinedName const* names = (player ? player->GetDeclinedNames() : nullptr))
            for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
                response.Data.DeclinedNames.name[i] = names->name[i];
    }
    else
        response.Result = RESPONSE_FAILURE; // name unknown

    SendPacket(response.Write());
}

void WorldSession::HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& packet)
{
    SendNameQueryOpcode(packet.Player);
}

void WorldSession::HandleQueryTimeOpcode(WorldPacket & /*recvData*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPacket data(SMSG_QUERY_TIME_RESPONSE, 4+4);
    data << uint32(time(NULL));
    data << uint32(sWorld->GetNextDailyQuestsResetTime() - time(NULL));
    SendPacket(&data);
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
        for (uint8 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
            if (creatureInfo->questItems[i])
                stats.QuestItems.push_back(creatureInfo->questItems[i]);
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

        for (uint8 i = 0; i < MAX_GAMEOBJECT_QUEST_ITEMS; i++)
            if (gameObjectInfo->questItems[i])
                stats.QuestItems.push_back(gameObjectInfo->questItems[i]);
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
    packet.Transport = ObjectGuid::Empty;                   // NYI
    SendPacket(packet.Write());
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: %u", packet.TextID);

    GossipText const* gossip = sObjectMgr->GetGossipText(packet.TextID);

    WorldPackets::Query::QueryNPCTextResponse response;
    response.TextID = packet.TextID;

    if (gossip)
    {
        for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
        {
            response.Probabilities[i] = gossip->Options[i].Probability;
            response.BroadcastTextID[i] = gossip->Options[i].BroadcastTextID;
        }

        response.Allow = true;
    }

    SendPacket(response.Write());

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

    WorldPackets::Query::CorpseTransportQuery response;
    response.Position = G3D::Vector3(0.0f, 0.0f, 0.0f);
    response.Facing = 0.0f;
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
            TC_LOG_DEBUG("network", "WORLD: Unknown quest %u in CMSG_QUEST_NPC_QUERY by %s", questId, _player->GetGUID().ToString().c_str());
            continue;
        }

        auto creatures = sObjectMgr->GetCreatureQuestInvolvedRelationReverseBounds(questId);
        for (auto it = creatures.first; it != creatures.second; ++it)
            quests[questId].push_back(it->second);

        auto gos = sObjectMgr->GetGOQuestInvolvedRelationReverseBounds(questId);
        for (auto it = gos.first; it != gos.second; ++it)
            quests[questId].push_back(it->second | 0x80000000); // GO mask
    }

    WorldPacket data(SMSG_QUEST_NPC_QUERY_RESPONSE, 3 + quests.size() * 14);
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

void WorldSession::HandleQuestPOIQuery(WorldPacket& recvData)
{
    uint32 count;
    recvData >> count; // quest count, max=25

    if (count > MAX_QUEST_LOG_SIZE)
    {
        recvData.rfinish();
        return;
    }

    // Read quest ids and add the in a unordered_set so we don't send POIs for the same quest multiple times
    std::unordered_set<uint32> questIds;
    for (uint32 i = 0; i < count; ++i)
        questIds.insert(recvData.read<uint32>()); // quest id

    WorldPacket data(SMSG_QUEST_POI_QUERY_RESPONSE, 4 + (4 + 4)*questIds.size());
    data << uint32(questIds.size()); // count

    for (auto itr = questIds.begin(); itr != questIds.end(); ++itr)
    {
        uint32 questId = *itr;

        bool questOk = false;

        uint16 questSlot = _player->FindQuestSlot(questId);

        if (questSlot != MAX_QUEST_LOG_SIZE)
            questOk =_player->GetQuestSlotQuestId(questSlot) == questId;

        if (questOk)
        {
            QuestPOIVector const* POI = sObjectMgr->GetQuestPOIVector(questId);

            if (POI)
            {
                data << uint32(questId); // quest ID
                data << uint32(POI->size()); // POI count

                for (QuestPOIVector::const_iterator itr = POI->begin(); itr != POI->end(); ++itr)
                {
                    data << uint32(itr->Id);                // POI index
                    data << int32(itr->ObjectiveIndex);     // objective index
                    data << uint32(itr->MapId);             // mapid
                    data << uint32(itr->AreaId);            // areaid
                    data << uint32(itr->FloorId);           // floorid
                    data << uint32(itr->Unk3);              // unknown
                    data << uint32(itr->Unk4);              // unknown
                    data << uint32(itr->points.size());     // POI points count

                    for (std::vector<QuestPOIPoint>::const_iterator itr2 = itr->points.begin(); itr2 != itr->points.end(); ++itr2)
                    {
                        data << int32(itr2->x); // POI point x
                        data << int32(itr2->y); // POI point y
                    }
                }
            }
            else
            {
                data << uint32(questId); // quest ID
                data << uint32(0); // POI count
            }
        }
        else
        {
            data << uint32(questId); // quest ID
            data << uint32(0); // POI count
        }
    }

    SendPacket(&data);
}

void WorldSession::HandleDBQueryBulk(WorldPackets::Query::DBQueryBulk& packet)
{
    DB2StorageBase const* store = sDB2Manager.GetStorage(packet.TableHash);
    if (!store)
    {
        TC_LOG_ERROR("network", "CMSG_DB_QUERY_BULK: Received unknown hotfix type: %u", packet.TableHash);
        return;
    }

    for (WorldPackets::Query::DBQueryBulk::DBQueryRecord const& rec : packet.Queries)
    {
        WorldPackets::Query::DBReply response;
        response.TableHash = packet.TableHash;

        if (store->HasRecord(rec.RecordID))
        {
            response.RecordID = rec.RecordID;
            response.Locale = GetSessionDbcLocale();
            response.Timestamp = sDB2Manager.GetHotfixDate(rec.RecordID, packet.TableHash);
            response.Data = store;
        }
        else
        {
            TC_LOG_ERROR("network", "CMSG_DB_QUERY_BULK: Entry %u does not exist in datastore: %u", rec.RecordID, packet.TableHash);
            response.RecordID = -int32(rec.RecordID);
            response.Timestamp = time(NULL);
        }

        SendPacket(response.Write());
    }
}
