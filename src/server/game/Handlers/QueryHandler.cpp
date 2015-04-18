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
#include "MapManager.h"

#include "Packets/QueryPackets.h"

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

void WorldSession::HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& query)
{
    SendNameQueryOpcode(query.Player);
}

void WorldSession::HandleQueryTimeOpcode(WorldPackets::Query::QueryTime& /*queryTime*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPackets::Query::QueryTimeResponse response;
    response.CurrentTime = time(nullptr);
    response.TimeOutRequest = sWorld->GetNextDailyQuestsResetTime() - response.CurrentTime;
    SendPacket(response.Write());
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleCreatureQueryOpcode(WorldPackets::Query::QueryCreature& query)
{
    CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(query.CreatureID);
    WorldPackets::Query::QueryCreatureResponse response;

    response.CreatureID = query.CreatureID;
    if (ci)
    {
        response.Stats.HasValue = true;
        WorldPackets::Query::QueryCreatureResponse::CreatureStats& stats = response.Stats.Value;

        stats.Name = ci->Name;
        stats.NameAlt = ci->SubName;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            if (CreatureLocale const* cl = sObjectMgr->GetCreatureLocale(query.CreatureID))
            {
                ObjectMgr::GetLocaleString(cl->Name, loc_idx, stats.Name);
                ObjectMgr::GetLocaleString(cl->SubName, loc_idx, stats.NameAlt);
            }
        }

        TC_LOG_DEBUG("network", "WORLD: CMSG_CREATURE_QUERY '%s' - Entry: %u.", ci->Name.c_str(), query.CreatureID);
        stats.CursorName = ci->IconName;
        stats.Flags = ci->type_flags;
        stats.CreatureType = ci->type;
        stats.CreatureFamily = ci->family;
        stats.Classification = ci->rank;
        memcpy(stats.ProxyCreatureID, ci->KillCredit, sizeof(uint32) * MAX_KILL_CREDIT);
        stats.CreatureDisplayID[0] = ci->Modelid1;
        stats.CreatureDisplayID[1] = ci->Modelid2;
        stats.CreatureDisplayID[2] = ci->Modelid3;
        stats.CreatureDisplayID[3] = ci->Modelid4;
        stats.HpMulti = ci->ModHealth;
        stats.EnergyMulti = ci->ModMana;
        stats.Leader = ci->RacialLeader;
        memcpy(stats.QuestItems, ci->questItems, sizeof(uint32) * MAX_CREATURE_QUEST_ITEMS);
        stats.CreatureMovementInfoID = ci->movementId;
    }
    else
        TC_LOG_DEBUG("network", "WORLD: CMSG_CREATURE_QUERY - NO CREATURE INFO! (%s, ENTRY: %u)", query.Guid.ToString().c_str(), query.CreatureID);

    SendPacket(response.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& packet)
{
    const GameObjectTemplate* info = sObjectMgr->GetGameObjectTemplate(packet.GameObjectID);
    WorldPackets::Query::QueryGameObjectResponse response;

    response.GameObjectID = packet.GameObjectID;
    if (info)
    {
        response.Stats.HasValue = true;
        WorldPackets::Query::QueryGameObjectResponse::GameObjectStats& stats = response.Stats.Value;

        stats.Name = info->name;
        stats.IconName = info->IconName;
        stats.CastBarCaption = info->castBarCaption;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            if (GameObjectLocale const* gl = sObjectMgr->GetGameObjectLocale(packet.GameObjectID))
            {
                ObjectMgr::GetLocaleString(gl->Name, loc_idx, stats.Name);
                ObjectMgr::GetLocaleString(gl->CastBarCaption, loc_idx, stats.CastBarCaption);
            }
        }
        TC_LOG_DEBUG("network", "WORLD: CMSG_GAMEOBJECT_QUERY '%s' - Entry: %u. ", info->name.c_str(), packet.GameObjectID);
        stats.Type = info->type;
        stats.DisplayID = info->displayId;
        stats.UnkString = info->unk1;
        memcpy(stats.Data, info->raw.data, sizeof(uint32) * MAX_GAMEOBJECT_DATA);
        stats.Size = info->size;
        memcpy(stats.QuestItems, info->questItems, sizeof(uint32) * MAX_GAMEOBJECT_QUEST_ITEMS);
    }
    else
        TC_LOG_DEBUG("network", "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for (%s, ENTRY: %u)", packet.Guid.ToString().c_str(), packet.GameObjectID);

    SendPacket(response.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
}

void WorldSession::HandleCorpseQueryOpcode(WorldPackets::Query::QueryCorpseLocation& /*packet*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_CORPSE_QUERY");

    Corpse* corpse = GetPlayer()->GetCorpse();
    WorldPackets::Query::QueryCorpseLocationResponse response;

    if (!corpse)
    {
        SendPacket(response.Write());                       // corpse not found
        return;
    }

    response.Location.HasValue = true;
    WorldPackets::Query::QueryCorpseLocationResponse::CorpseLoc& loc = response.Location.Value;
    loc.MapID = corpse->GetMapId();
    loc.Position.x = corpse->GetPositionX();
    loc.Position.y = corpse->GetPositionY();
    loc.Position.z = corpse->GetPositionZ();
    loc.ActualMapID = loc.MapID;

    // if corpse at different map
    if (loc.MapID != _player->GetMapId())
    {
        // search entrance map for proper show entrance
        if (MapEntry const* corpseMapEntry = sMapStore.LookupEntry(loc.MapID))
        {
            if (corpseMapEntry->IsDungeon() && corpseMapEntry->entrance_map >= 0)
            {
                // if corpse map have entrance
                if (Map const* entranceMap = sMapMgr->CreateBaseMap(corpseMapEntry->entrance_map))
                {
                    loc.MapID = corpseMapEntry->entrance_map;
                    loc.Position.x = corpseMapEntry->entrance_x;
                    loc.Position.y = corpseMapEntry->entrance_y;
                    loc.Position.z = entranceMap->GetHeight(GetPlayer()->GetPhaseMask(), loc.Position.x, loc.Position.y, MAX_HEIGHT);
                }
            }
        }
    }

    SendPacket(response.Write());
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: %u", packet.TextID);
    GossipText const* gossip = sObjectMgr->GetGossipText(packet.TextID);

    WorldPackets::Query::QueryNPCTextResponse response;
    response.TextID = packet.TextID;

    if (!gossip)
        response.Allow = false;
    else
    {
        response.Allow = true;

        std::string text0[MAX_GOSSIP_TEXT_OPTIONS], text1[MAX_GOSSIP_TEXT_OPTIONS];
        LocaleConstant locale = GetSessionDbLocaleIndex();

        for (uint8 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
        {
            BroadcastText const* bct = sObjectMgr->GetBroadcastText(gossip->Options[i].BroadcastTextID);
            if (bct)
            {
                text0[i] = bct->GetText(locale, GENDER_MALE, true);
                text1[i] = bct->GetText(locale, GENDER_FEMALE, true);
            }
            else
            {
                text0[i] = gossip->Options[i].Text_0;
                text1[i] = gossip->Options[i].Text_1;
            }

            if (locale != DEFAULT_LOCALE && !bct)
            {
                if (NpcTextLocale const* npcTextLocale = sObjectMgr->GetNpcTextLocale(packet.TextID))
                {
                    ObjectMgr::GetLocaleString(npcTextLocale->Text_0[i], locale, text0[i]);
                    ObjectMgr::GetLocaleString(npcTextLocale->Text_1[i], locale, text1[i]);
                }
            }

            response.Probabilities[i] = gossip->Options[i].Probability;
            response.Languages[i] = gossip->Options[i].Language;

            memcpy(response.Emotes[i], gossip->Options[i].Emotes, MAX_GOSSIP_TEXT_EMOTES * sizeof(QEmote));
        }

        std::copy(text0, &text0[MAX_GOSSIP_TEXT_OPTIONS], response.Texts[0]);
        std::copy(text1, &text1[MAX_GOSSIP_TEXT_OPTIONS], response.Texts[1]);
    }

    SendPacket(response.Write());

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_NPC_TEXT_UPDATE");
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandlePageTextQueryOpcode(WorldPackets::Query::QueryPageText& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_PAGE_TEXT_QUERY");

    uint32 pageID = packet.PageID;

    while (pageID)
    {
        PageText const* pageText = sObjectMgr->GetPageText(pageID);
        WorldPackets::Query::QueryPageTextResponse response;
        response.Page.ID = pageID;

        if (!pageText)
        {
            response.Allow = false;
            pageID = 0;
        }
        else
        {
            response.Allow = true;
            response.Page.Text = pageText->Text;

            LocaleConstant loc_idx = GetSessionDbLocaleIndex();
            if (loc_idx != DEFAULT_LOCALE)
                if (PageTextLocale const* textLoc = sObjectMgr->GetPageTextLocale(pageID))
                    ObjectMgr::GetLocaleString(textLoc->Text, loc_idx, response.Page.Text);
            
            response.Page.NextPageID = pageText->NextPage;
            pageID = pageText->NextPage;
        }

        SendPacket(response.Write());

        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_PAGE_TEXT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleCorpseMapPositionQuery(WorldPackets::Query::QueryCorpseMapPosition& /*packet*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_CORPSE_MAP_POSITION_QUERY");
    WorldPackets::Query::QueryCorpseMapPositionResponse response;
    SendPacket(response.Write());
}

void WorldSession::HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& packet)
{
    if (packet.MissingQuestCount > MAX_QUEST_LOG_SIZE)
        return;

    // Read quest ids and add the in a unordered_set so we don't send POIs for the same quest multiple times
    std::unordered_set<uint32> questIds;
    for (uint32 i = 0; i < packet.MissingQuestCount; ++i)
        questIds.insert(packet.MissingQuestPOIs[i]); // quest id

    WorldPackets::Query::QuestPOIQueryResponse response;

    for (uint32 QuestID : questIds)
    {
        bool questOk = false;

        uint16 questSlot = _player->FindQuestSlot(QuestID);

        if (questSlot != MAX_QUEST_LOG_SIZE)
            questOk = _player->GetQuestSlotQuestId(questSlot) == QuestID;

        if (questOk)
        {
            QuestPOIVector const* poiData = sObjectMgr->GetQuestPOIVector(QuestID);

            if (poiData)
            {
                WorldPackets::Query::QuestPOIQueryResponse::QuestPOIData questPOIData;

                questPOIData.QuestID = QuestID;

                for (auto data = poiData->cbegin(); data != poiData->cend(); ++data)
                {
                    WorldPackets::Query::QuestPOIQueryResponse::QuestPOIBlobData questPOIBlobData;

                    questPOIBlobData.BlobIndex      = data->Id;                // POI index
                    questPOIBlobData.ObjectiveIndex = data->ObjectiveIndex;    // objective index
                    questPOIBlobData.MapID          = data->MapId;             // mapid
                    questPOIBlobData.WorldMapAreaID = data->AreaId;            // areaid
                    questPOIBlobData.Floor          = data->FloorId;           // floorid
                    questPOIBlobData.Unk3           = data->Unk3;              // unknown
                    questPOIBlobData.Unk4           = data->Unk4;              // unknown

                    for (auto points = data->points.cbegin(); points != data->points.cend(); ++points)
                    {
                        WorldPackets::Query::QuestPOIQueryResponse::QuestPOIBlobPoint questPOIBlobPoint;

                        questPOIBlobPoint.X = points->x; // POI point x
                        questPOIBlobPoint.Y = points->y; // POI point y

                        TC_LOG_TRACE("misc", "Quest: %i BlobIndex: %i X/Y: %i/%i", QuestID, data->Id, points->x, points->y);

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
