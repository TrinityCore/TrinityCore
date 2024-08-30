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
#include "Common.h"
#include "Corpse.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Item.h"
#include "Log.h"
#include "Map.h"
#include "NPCHandler.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryPackets.h"
#include "RealmList.h"
#include "TerrainMgr.h"
#include "World.h"

void WorldSession::BuildNameQueryData(ObjectGuid guid, WorldPackets::Query::NameCacheLookupResult& lookupData)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);

    lookupData.Player = guid;

    lookupData.Data.emplace();
    if (lookupData.Data->Initialize(guid, player))
        lookupData.Result = RESPONSE_SUCCESS; // name known
    else
        lookupData.Result = RESPONSE_FAILURE; // name unknown
}

void WorldSession::HandleQueryPlayerNames(WorldPackets::Query::QueryPlayerNames& queryPlayerNames)
{
    WorldPackets::Query::QueryPlayerNamesResponse response;
    for (ObjectGuid guid : queryPlayerNames.Players)
        BuildNameQueryData(guid, response.Players.emplace_back());

    SendPacket(response.Write());
}

void WorldSession::HandleQueryTimeOpcode(WorldPackets::Query::QueryTime& /*queryTime*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPackets::Query::QueryTimeResponse queryTimeResponse;
    queryTimeResponse.CurrentTime = GameTime::GetSystemTime();
    SendPacket(queryTimeResponse.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleCreatureQuery(WorldPackets::Query::QueryCreature& packet)
{
    if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(packet.CreatureID))
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_QUERY_CREATURE '{}' - Entry: {}.", ci->Name, packet.CreatureID);

        Difficulty difficulty = _player->GetMap()->GetDifficultyID();

        // Cache only exists for difficulty base
        if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES) && difficulty == DIFFICULTY_NONE)
            SendPacket(&ci->QueryData[static_cast<uint32>(GetSessionDbLocaleIndex())]);
        else
        {
            WorldPacket response = ci->BuildQueryData(GetSessionDbLocaleIndex(), difficulty);
            SendPacket(&response);
        }
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUERY_CREATURE_RESPONSE");
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_QUERY_CREATURE - NO CREATURE INFO! (ENTRY: {})", packet.CreatureID);

        WorldPackets::Query::QueryCreatureResponse response;
        response.CreatureID = packet.CreatureID;
        SendPacket(response.Write());
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUERY_CREATURE_RESPONSE");
    }
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& packet)
{
    if (GameObjectTemplate const* info = sObjectMgr->GetGameObjectTemplate(packet.GameObjectID))
    {
        if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
            SendPacket(&info->QueryData[static_cast<uint32>(GetSessionDbLocaleIndex())]);
        else
        {
            WorldPacket response = info->BuildQueryData(GetSessionDbLocaleIndex());
            SendPacket(&response);
        }
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for (ENTRY: {})", packet.GameObjectID);

        WorldPackets::Query::QueryGameObjectResponse response;
        response.GameObjectID = packet.GameObjectID;
        response.Guid = packet.Guid;
        SendPacket(response.Write());
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleQueryCorpseLocation(WorldPackets::Query::QueryCorpseLocationFromClient& queryCorpseLocation)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(queryCorpseLocation.Player);
    if (!player || !player->HasCorpse() || !_player->IsInSameRaidWith(player))
    {
        WorldPackets::Query::CorpseLocation packet;
        packet.Valid = false;                               // corpse not found
        packet.Player = queryCorpseLocation.Player;
        SendPacket(packet.Write());
        return;
    }

    WorldLocation corpseLocation = player->GetCorpseLocation();
    uint32 corpseMapID = corpseLocation.GetMapId();
    uint32 mapID = corpseLocation.GetMapId();
    float x = corpseLocation.GetPositionX();
    float y = corpseLocation.GetPositionY();
    float z = corpseLocation.GetPositionZ();

    // if corpse at different map
    if (mapID != player->GetMapId())
    {
        // search entrance map for proper show entrance
        if (MapEntry const* corpseMapEntry = sMapStore.LookupEntry(mapID))
        {
            if (corpseMapEntry->IsDungeon() && corpseMapEntry->CorpseMapID >= 0)
            {
                // if corpse map have entrance
                if (std::shared_ptr<TerrainInfo> entranceTerrain = sTerrainMgr.LoadTerrain(corpseMapEntry->CorpseMapID))
                {
                    mapID = corpseMapEntry->CorpseMapID;
                    x = corpseMapEntry->Corpse.X;
                    y = corpseMapEntry->Corpse.Y;
                    z = entranceTerrain->GetStaticHeight(player->GetPhaseShift(), mapID, x, y, MAX_HEIGHT);
                }
            }
        }
    }

    WorldPackets::Query::CorpseLocation packet;
    packet.Valid = true;
    packet.Player = queryCorpseLocation.Player;
    packet.MapID = corpseMapID;
    packet.ActualMapID = mapID;
    packet.Position = Position(x, y, z);
    packet.Transport = ObjectGuid::Empty;
    SendPacket(packet.Write());
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: {}", packet.TextID);

    NpcText const* npcText = sObjectMgr->GetNpcText(packet.TextID);

    WorldPackets::Query::QueryNPCTextResponse response;
    response.TextID = packet.TextID;

    if (npcText)
    {
        for (uint8 i = 0; i < MAX_NPC_TEXT_OPTIONS; ++i)
        {
            response.Probabilities[i] = npcText->Data[i].Probability;
            response.BroadcastTextID[i] = npcText->Data[i].BroadcastTextID;
            if (!response.Allow && npcText->Data[i].BroadcastTextID)
                response.Allow = true;
        }
    }

    if (!response.Allow)
        TC_LOG_ERROR("sql.sql", "HandleNpcTextQueryOpcode: no BroadcastTextID found for text {} in `npc_text table`", packet.TextID);

    SendPacket(response.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleQueryPageText(WorldPackets::Query::QueryPageText& packet)
{
    WorldPackets::Query::QueryPageTextResponse response;
    response.PageTextID = packet.PageTextID;

    uint32 pageID = packet.PageTextID;
    while (pageID)
    {
        PageText const* pageText = sObjectMgr->GetPageText(pageID);
        if (!pageText)
            break;

        WorldPackets::Query::QueryPageTextResponse::PageTextInfo page;
        page.ID = pageID;
        page.NextPageID = pageText->NextPageID;
        page.Text = pageText->Text;
        page.PlayerConditionID = pageText->PlayerConditionID;
        page.Flags = pageText->Flags;

        LocaleConstant locale = GetSessionDbLocaleIndex();
        if (locale != LOCALE_enUS)
            if (PageTextLocale const* pageTextLocale = sObjectMgr->GetPageTextLocale(pageID))
                ObjectMgr::GetLocaleString(pageTextLocale->Text, locale, page.Text);

        response.Pages.push_back(page);
        pageID = pageText->NextPageID;
    }

    response.Allow = !response.Pages.empty();

    SendPacket(response.Write());
}

void WorldSession::HandleQueryCorpseTransport(WorldPackets::Query::QueryCorpseTransport& queryCorpseTransport)
{
    WorldPackets::Query::CorpseTransportQuery response;
    response.Player = queryCorpseTransport.Player;
    if (Player* player = ObjectAccessor::FindConnectedPlayer(queryCorpseTransport.Player))
    {
        Corpse* corpse = player->GetCorpse();
        if (_player->IsInSameRaidWith(player) && corpse && !corpse->GetTransGUID().IsEmpty() && corpse->GetTransGUID() == queryCorpseTransport.Transport)
        {
            response.Position = corpse->GetTransOffset();
            response.Facing = corpse->GetTransOffsetO();
        }
    }

    SendPacket(response.Write());
}

void WorldSession::HandleQueryQuestCompletionNPCs(WorldPackets::Query::QueryQuestCompletionNPCs& queryQuestCompletionNPCs)
{
    WorldPackets::Query::QuestCompletionNPCResponse response;

    for (int32& questID : queryQuestCompletionNPCs.QuestCompletionNPCs)
    {
        WorldPackets::Query::QuestCompletionNPC questCompletionNPC;

        if (!sObjectMgr->GetQuestTemplate(questID))
        {
            TC_LOG_DEBUG("network", "WORLD: Unknown quest {} in CMSG_QUERY_QUEST_COMPLETION_NPCS by {}", questID, _player->GetGUID().ToString());
            continue;
        }

        questCompletionNPC.QuestID = questID;

        for (auto const& creatures : sObjectMgr->GetCreatureQuestInvolvedRelationReverseBounds(questID))
            questCompletionNPC.NPCs.push_back(creatures.second);

        for (auto const& gos : sObjectMgr->GetGOQuestInvolvedRelationReverseBounds(questID))
            questCompletionNPC.NPCs.push_back(gos.second | 0x80000000); // GO mask

        response.QuestCompletionNPCs.push_back(std::move(questCompletionNPC));
    }

    SendPacket(response.Write());
}

void WorldSession::HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& questPoiQuery)
{
    if (questPoiQuery.MissingQuestCount > MAX_QUEST_LOG_SIZE)
        return;

    // Read quest ids and add the in a unordered_set so we don't send POIs for the same quest multiple times
    std::unordered_set<int32> questIds;
    for (int32 i = 0; i < questPoiQuery.MissingQuestCount; ++i)
        questIds.insert(questPoiQuery.MissingQuestPOIs[i]); // QuestID

    WorldPackets::Query::QuestPOIQueryResponse response;

    for (uint32 questId : questIds)
        if (_player->FindQuestSlot(questId) != MAX_QUEST_LOG_SIZE)
            if (QuestPOIData const* poiData = sObjectMgr->GetQuestPOIData(questId))
                response.QuestPOIDataStats.push_back(poiData);

    SendPacket(response.Write());
}

/**
* Handles the packet sent by the client when requesting information about item text.
*
* This function is called when player clicks on item which has some flag set
*/
void WorldSession::HandleItemTextQuery(WorldPackets::Query::ItemTextQuery& itemTextQuery)
{
    WorldPackets::Query::QueryItemTextResponse queryItemTextResponse;
    queryItemTextResponse.Id = itemTextQuery.Id;

    if (Item* item = _player->GetItemByGuid(itemTextQuery.Id))
    {
        queryItemTextResponse.Valid = true;
        queryItemTextResponse.Item.Text = item->GetText();
    }

    SendPacket(queryItemTextResponse.Write());
}

void WorldSession::HandleQueryRealmName(WorldPackets::Query::QueryRealmName& queryRealmName)
{
    WorldPackets::Query::RealmQueryResponse realmQueryResponse;
    realmQueryResponse.VirtualRealmAddress = queryRealmName.VirtualRealmAddress;

    if (std::shared_ptr<Realm const> realm = sRealmList->GetRealm(queryRealmName.VirtualRealmAddress))
    {
        realmQueryResponse.LookupState = RESPONSE_SUCCESS;
        realmQueryResponse.NameInfo.IsInternalRealm = false;
        realmQueryResponse.NameInfo.IsLocal = queryRealmName.VirtualRealmAddress == GetVirtualRealmAddress();
        realmQueryResponse.NameInfo.RealmNameActual = realm->Name;
        realmQueryResponse.NameInfo.RealmNameNormalized = realm->NormalizedName;
    }
    else
        realmQueryResponse.LookupState = RESPONSE_FAILURE;

    SendPacket(realmQueryResponse.Write());
}
