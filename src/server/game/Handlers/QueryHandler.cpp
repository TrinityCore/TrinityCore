/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "Common.h"
#include "Corpse.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "MapManager.h"
#include "NPCHandler.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryPackets.h"
#include "Realm.h"
#include "World.h"
#include "WorldPacket.h"

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

        stats.Leader = creatureInfo->RacialLeader;

        stats.Name[0] = creatureInfo->Name;
        stats.NameAlt[0] = creatureInfo->FemaleName;

        stats.Flags[0] = creatureInfo->type_flags;
        stats.Flags[1] = creatureInfo->type_flags2;

        stats.CreatureType = creatureInfo->type;
        stats.CreatureFamily = creatureInfo->family;
        stats.Classification = creatureInfo->rank;

        for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
            stats.ProxyCreatureID[i] = creatureInfo->KillCredit[i];

        stats.CreatureDisplayID[0] = creatureInfo->Modelid1;
        stats.CreatureDisplayID[1] = creatureInfo->Modelid2;
        stats.CreatureDisplayID[2] = creatureInfo->Modelid3;
        stats.CreatureDisplayID[3] = creatureInfo->Modelid4;

        stats.HpMulti = creatureInfo->ModHealth;
        stats.EnergyMulti = creatureInfo->ModMana;

        stats.CreatureMovementInfoID = creatureInfo->movementId;
        stats.RequiredExpansion = creatureInfo->RequiredExpansion;
        stats.HealthScalingExpansion = creatureInfo->HealthScalingExpansion;
        stats.VignetteID = creatureInfo->VignetteID;

        stats.Title = creatureInfo->SubName;
        stats.TitleAlt = creatureInfo->TitleAlt;
        stats.CursorName = creatureInfo->IconName;

        if (std::vector<uint32> const* items = sObjectMgr->GetCreatureQuestItemList(packet.CreatureID))
            for (uint32 item : *items)
                stats.QuestItems.push_back(item);

        LocaleConstant localeConstant = GetSessionDbLocaleIndex();
        if (localeConstant != LOCALE_enUS)
            if (CreatureLocale const* creatureLocale = sObjectMgr->GetCreatureLocale(packet.CreatureID))
            {
                ObjectMgr::GetLocaleString(creatureLocale->Name, localeConstant, stats.Name[0]);
                ObjectMgr::GetLocaleString(creatureLocale->NameAlt, localeConstant, stats.NameAlt[0]);
                ObjectMgr::GetLocaleString(creatureLocale->Title, localeConstant, stats.Title);
                ObjectMgr::GetLocaleString(creatureLocale->TitleAlt, localeConstant, stats.TitleAlt);
            }
    }

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

        stats.Type = gameObjectInfo->type;
        stats.DisplayID = gameObjectInfo->displayId;

        stats.Name[0] = gameObjectInfo->name;
        stats.IconName = gameObjectInfo->IconName;
        stats.CastBarCaption = gameObjectInfo->castBarCaption;
        stats.UnkString = gameObjectInfo->unk1;

        LocaleConstant localeConstant = GetSessionDbLocaleIndex();
        if (localeConstant != LOCALE_enUS)
            if (GameObjectLocale const* gameObjectLocale = sObjectMgr->GetGameObjectLocale(packet.GameObjectID))
            {
                ObjectMgr::GetLocaleString(gameObjectLocale->Name, localeConstant, stats.Name[0]);
                ObjectMgr::GetLocaleString(gameObjectLocale->CastBarCaption, localeConstant, stats.CastBarCaption);
                ObjectMgr::GetLocaleString(gameObjectLocale->Unk1, localeConstant, stats.UnkString);
            }

        stats.Size = gameObjectInfo->size;

        if (std::vector<uint32> const* items = sObjectMgr->GetGameObjectQuestItemList(packet.GameObjectID))
            for (int32 item : *items)
                stats.QuestItems.push_back(item);

        memcpy(stats.Data, gameObjectInfo->raw.data, MAX_GAMEOBJECT_DATA * sizeof(int32));
        stats.RequiredLevel = gameObjectInfo->RequiredLevel;
    }

    SendPacket(response.Write());
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
                if (Map const* entranceMap = sMapMgr->CreateBaseMap(corpseMapEntry->CorpseMapID))
                {
                    mapID = corpseMapEntry->CorpseMapID;
                    x = corpseMapEntry->Corpse.X;
                    y = corpseMapEntry->Corpse.Y;
                    z = entranceMap->GetHeight(player->GetPhaseShift(), x, y, MAX_HEIGHT);
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
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: %u", packet.TextID);

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
        TC_LOG_ERROR("sql.sql", "HandleNpcTextQueryOpcode: no BroadcastTextID found for text %u in `npc_text table`", packet.TextID);

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
            TC_LOG_DEBUG("network", "WORLD: Unknown quest %u in CMSG_QUERY_QUEST_COMPLETION_NPCS by %s", questID, _player->GetGUID().ToString().c_str());
            continue;
        }

        questCompletionNPC.QuestID = questID;

        auto creatures = sObjectMgr->GetCreatureQuestInvolvedRelationReverseBounds(questID);
        for (auto it = creatures.first; it != creatures.second; ++it)
            questCompletionNPC.NPCs.push_back(it->second);

        auto gos = sObjectMgr->GetGOQuestInvolvedRelationReverseBounds(questID);
        for (auto it = gos.first; it != gos.second; ++it)
            questCompletionNPC.NPCs.push_back(it->second | 0x80000000); // GO mask

        response.QuestCompletionNPCs.push_back(questCompletionNPC);
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

    for (auto itr = questIds.begin(); itr != questIds.end(); ++itr)
    {
        int32 QuestID = *itr;

        bool questOk = false;

        uint16 questSlot = _player->FindQuestSlot(uint32(QuestID));

        if (questSlot != MAX_QUEST_LOG_SIZE)
            questOk = _player->GetQuestSlotQuestId(questSlot) == uint32(QuestID);

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
                    questPOIBlobData.AlwaysAllowMergingBlobs = data->AlwaysAllowMergingBlobs;

                    for (QuestPOIPoint const& point : data->points)
                    {
                        WorldPackets::Query::QuestPOIBlobPoint questPOIBlobPoint;

                        questPOIBlobPoint.X = point.X;
                        questPOIBlobPoint.Y = point.Y;

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

    Battlenet::RealmHandle realmHandle(queryRealmName.VirtualRealmAddress);
    if (sObjectMgr->GetRealmName(realmHandle.Realm, realmQueryResponse.NameInfo.RealmNameActual, realmQueryResponse.NameInfo.RealmNameNormalized))
    {
        realmQueryResponse.LookupState = RESPONSE_SUCCESS;
        realmQueryResponse.NameInfo.IsInternalRealm = false;
        realmQueryResponse.NameInfo.IsLocal = queryRealmName.VirtualRealmAddress == realm.Id.GetAddress();
    }
    else
        realmQueryResponse.LookupState = RESPONSE_FAILURE;
}
