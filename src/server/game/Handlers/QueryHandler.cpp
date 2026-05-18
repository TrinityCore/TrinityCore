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
#include "CharacterCache.h"
#include "Common.h"
#include "Corpse.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Log.h"
#include "MapManager.h"
#include "NPCHandler.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryPackets.h"
#include "Transport.h"
#include "UpdateMask.h"
#include "World.h"

void WorldSession::SendNameQueryOpcode(ObjectGuid guid)
{
    WorldPackets::Query::QueryPlayerNameResponse response;
    response.Player = guid;

    if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid))
    {
        response.Result = RESPONSE_SUCCESS; // name known

        WorldPackets::Query::PlayerGuidLookupData& data = response.Data.emplace();
        data.Name = characterInfo->Name;
        data.Race = characterInfo->Race;
        data.Sex = characterInfo->Sex;
        data.ClassID = characterInfo->Class;

        if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
            data.DeclinedNames = player->GetDeclinedNames();
    }
    else
        response.Result = RESPONSE_FAILURE; // name unknown

    SendPacket(response.Write());
}

void WorldSession::HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& queryPlayerName)
{
    SendNameQueryOpcode(queryPlayerName.Player);
}

void WorldSession::HandleQueryTimeOpcode(WorldPacket & /*recvData*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPacket data(SMSG_QUERY_TIME_RESPONSE, 4+4);
    data << uint32(GameTime::GetGameTime());
    data << uint32(sWorld->GetNextDailyQuestsResetTime() - GameTime::GetGameTime());
    SendPacket(&data);
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleCreatureQueryOpcode(WorldPackets::Query::QueryCreature& query)
{
    if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(query.CreatureID))
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_CREATURE_QUERY '{}' - Entry: {}.", ci->Name, query.CreatureID);
        if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
            SendPacket(&ci->QueryData[static_cast<uint32>(GetSessionDbLocaleIndex())]);
        else
        {
            WorldPacket response = ci->BuildQueryData(GetSessionDbLocaleIndex());
            SendPacket(&response);
        }
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_CREATURE_QUERY - NO CREATURE INFO! ({}, ENTRY: {})",
            query.Guid.ToString(), query.CreatureID);

        WorldPackets::Query::QueryCreatureResponse response;
        response.CreatureID = query.CreatureID;
        SendPacket(response.Write());
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
    }
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& query)
{
    if (GameObjectTemplate const* info = sObjectMgr->GetGameObjectTemplate(query.GameObjectID))
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
        TC_LOG_DEBUG("network", "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for ({}, ENTRY: {})",
            query.Guid.ToString(), query.GameObjectID);

        WorldPackets::Query::QueryGameObjectResponse response;
        response.GameObjectID = query.GameObjectID;
        SendPacket(response.Write());
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleQueryCorpseLocation(WorldPackets::Query::QueryCorpseLocationFromClient& /*queryCorpseLocation*/)
{
    if (!_player->HasCorpse())
    {
        WorldPackets::Query::CorpseLocation packet;
        packet.Valid = false;                               // corpse not found
        SendPacket(packet.Write());
        return;
    }

    WorldLocation corpseLocation = _player->GetCorpseLocation();
    uint32 corpseMapID = corpseLocation.GetMapId();
    uint32 mapID = corpseLocation.GetMapId();
    float x = corpseLocation.GetPositionX();
    float y = corpseLocation.GetPositionY();
    float z = corpseLocation.GetPositionZ();

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
                    x = corpseMapEntry->Corpse.X;
                    y = corpseMapEntry->Corpse.Y;
                    z = entranceMap->GetHeight(GetPlayer()->GetPhaseMask(), x, y, MAX_HEIGHT);
                }
            }
        }
    }

    WorldPackets::Query::CorpseLocation packet;
    packet.Valid = true;
    packet.MapID = corpseMapID;
    packet.ActualMapID = mapID;
    packet.Position = Position(x, y, z);
    packet.Transport = 0;                   // TODO: If corpse is on transport, send transport offsets and transport guid
    SendPacket(packet.Write());
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: {}", packet.TextID);

    GossipText const* npcText = sObjectMgr->GetGossipText(packet.TextID);

    WorldPackets::Query::QueryNPCTextResponse response;
    response.TextID = packet.TextID;
    response.Allow = true;

    if (npcText)
    {
        LocaleConstant locale = GetSessionDbLocaleIndex();

        for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
        {
            response.Options[i].Probability = npcText->Options[i].Probability;
            if (BroadcastTextEntry const* bct = sObjectMgr->GetBroadcastText(npcText->Options[i].BroadcastTextID))
            {
                response.Options[i].Text = bct->GetText(locale, GENDER_MALE, true);
                response.Options[i].Text1 = bct->GetText(locale, GENDER_FEMALE, true);
            }
            else
            {
                response.Options[i].Text = npcText->Options[i].Text_0;
                response.Options[i].Text1 = npcText->Options[i].Text_1;

                if (locale != DEFAULT_LOCALE)
                {
                    if (NpcTextLocale const* npcTextLocale = sObjectMgr->GetNpcTextLocale(packet.TextID))
                    {
                        ObjectMgr::GetLocaleString(npcTextLocale->Text_0[i], locale, response.Options[i].Text);
                        ObjectMgr::GetLocaleString(npcTextLocale->Text_1[i], locale, response.Options[i].Text1);
                    }
                }
            }

            if (response.Options[i].Text.empty())
                response.Options[i].Text = response.Options[i].Text1;

            if (response.Options[i].Text1.empty())
                response.Options[i].Text1 = response.Options[i].Text;

            response.Options[i].LanguageID = npcText->Options[i].Language;

            for (uint8 j = 0; j < MAX_GOSSIP_TEXT_EMOTES; ++j)
            {
                response.Options[i].EmoteDelay[j] = npcText->Options[i].Emotes[j]._Delay;
                response.Options[i].EmoteID[j] = npcText->Options[i].Emotes[j]._Emote;
            }
        }
    }
    else
    {
        for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
        {
            response.Options[i].Text = "Greetings $N";
            response.Options[i].Text1 = "Greetings $N";
        }
    }

    SendPacket(response.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleQueryPageText(WorldPackets::Query::QueryPageText& packet)
{
    uint32 pageID = packet.PageTextID;
    while (pageID)
    {
        WorldPackets::Query::QueryPageTextResponse response;
        response.PageTextID = pageID;
        if (PageText const* pageText = sObjectMgr->GetPageText(pageID))
        {
            response.Allow = true;

            WorldPackets::Query::QueryPageTextResponse::PageTextInfo& page = response.Page;
            page.NextPageID = pageText->NextPageID;
            page.Text = pageText->Text;

            LocaleConstant localeConstant = GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (PageTextLocale const* pageTextLocale = sObjectMgr->GetPageTextLocale(pageID))
                    ObjectMgr::GetLocaleString(pageTextLocale->Text, localeConstant, page.Text);

            pageID = pageText->NextPageID;
        }
        else
            pageID = 0;

        SendPacket(response.Write());
    }
}

void WorldSession::HandleQueryCorpseTransport(WorldPackets::Query::QueryCorpseTransport& queryCorpseTransport)
{
    WorldPackets::Query::CorpseTransportQuery response;
    if (Corpse const* corpse = _player->GetCorpse())
    {
        if (Transport const* transport = corpse->GetTransport())
        {
            if (transport->GetGUID().GetCounter() == queryCorpseTransport.Transport)
            {
                response.Position = transport->GetPosition();
                response.Facing = transport->GetOrientation();
            }
        }
    }

    SendPacket(response.Write());
}

void WorldSession::HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& query)
{
    if (query.MissingQuestCount > MAX_QUEST_LOG_SIZE)
        return;

    // Read quest ids and add the in a unordered_set so we don't send POIs for the same quest multiple times
    std::unordered_set<uint32> questIds;
    for (uint32 i = 0; i < query.MissingQuestCount; ++i)
        questIds.insert(query.MissingQuestPOIs[i]); // quest id

    WorldPacket data(SMSG_QUEST_POI_QUERY_RESPONSE, 4 + (4 + 4 + 40) * questIds.size());
    data << uint32(questIds.size()); // count

    for (uint32 questId : questIds)
    {
        uint16 const questSlot = _player->FindQuestSlot(questId);
        if (questSlot != MAX_QUEST_LOG_SIZE && _player->GetQuestSlotQuestId(questSlot) == questId)
        {
            if (QuestPOIWrapper const* poiWrapper = sObjectMgr->GetQuestPOIWrapper(questId))
            {
                if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
                    data.append(poiWrapper->QueryDataBuffer);
                else
                {
                    ByteBuffer POIByteBuffer = poiWrapper->BuildQueryData();
                    data.append(POIByteBuffer);
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
