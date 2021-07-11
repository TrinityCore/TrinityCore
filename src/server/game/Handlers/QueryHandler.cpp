/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Database/DatabaseImpl.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "NPCHandler.h"
#include "ObjectAccessor.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ObjectGuid.h"
#include "Player.h"

void WorldSession::BuildNameQueryData(ObjectGuid guid, WorldPackets::Query::NameCacheLookupResult& lookupData)
void WorldSession::SendNameQueryOpcode(Player* p)
{
    if (!p)
        return;

    lookupData.Player = guid;
    // guess size
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
    WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + 25 + 1 + 4 + 4 + 4));   // guess size
    data << ObjectGuid(p->GetObjectGuid());
    data << p->GetName();                                   // CString(48): played name
    data << uint8(0);                                       // CString(256): realm name for cross realm BG usage
#else
    WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + 25 + 4 + 4 + 4));   // guess size
    data << ObjectGuid(p->GetObjectGuid());
    data << p->GetName();                                   // CString(48): played name
#endif
    data << uint32(p->GetRace());
    data << uint32(p->GetGender());
    data << uint32(p->GetClass());

    lookupData.Data.emplace();
    if (lookupData.Data->Initialize(guid, player))
        lookupData.Result = RESPONSE_SUCCESS; // name known
    else
        lookupData.Result = RESPONSE_FAILURE; // name unknown
}
    SendPacket(&data);
}

void WorldSession::SendNameQueryOpcodeFromDB(ObjectGuid guid)
{
    // Avec la mise en cache...
    if (PlayerCacheData* pData = sObjectMgr.GetPlayerDataByGUID(guid.GetCounter()))
    {
        std::string name = pData->sName;

#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
        WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + (name.size() + 1) + 1 + 4 + 4 + 4));
        data << ObjectGuid(HIGHGUID_PLAYER, pData->uiGuid);
        data << name;
        data << uint8(0);
#else
        WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + (name.size() + 1) + 4 + 4 + 4));
        data << ObjectGuid(HIGHGUID_PLAYER, pData->uiGuid);
        data << name;
#endif
        data << uint32(pData->uiRace);
        data << uint32(pData->uiGender);
        data << uint32(pData->uiClass);

        SendPacket(&data);
    }

void WorldSession::HandleQueryPlayerNames(WorldPackets::Query::QueryPlayerNames& queryPlayerNames)
    // Ancienne methode :
    /*
    CharacterDatabase.AsyncPQuery(&WorldSession::SendNameQueryOpcodeFromDBCallBack, GetAccountId(),
    //          0     1     2     3       4
        "SELECT guid, name, race, gender, class "
        "FROM characters WHERE guid = '%u'",
        guid.GetCounter());
    */
}

void WorldSession::SendNameQueryOpcodeFromDBCallBack(QueryResult* result, uint32 accountId)
{
    WorldPackets::Query::QueryPlayerNamesResponse response;
    for (ObjectGuid guid : queryPlayerNames.Players)
        BuildNameQueryData(guid, response.Players.emplace_back());

    SendPacket(response.Write());
}
    if (!result)
        return;

    WorldSession* session = sWorld.FindSession(accountId);
    if (!session)
    {
        delete result;
        return;
    }

    Field* fields = result->Fetch();
    uint32 lowguid      = fields[0].GetUInt32();
    std::string name = fields[1].GetCppString();
    uint8 pRace = 0, pGender = 0, pClass = 0;
    if (!name.empty())
    {
        pRace        = fields[2].GetUInt8();
        pGender      = fields[3].GetUInt8();
        pClass       = fields[4].GetUInt8();
    }

    // guess size
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
    WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + (name.size() + 1) + 1 + 4 + 4 + 4));
    data << ObjectGuid(HIGHGUID_PLAYER, lowguid);
    data << name;
    data << uint8(0);                                       // realm name for cross realm BG usage
#else
    WorldPacket data(SMSG_NAME_QUERY_RESPONSE, (8 + (name.size() + 1) + 4 + 4 + 4));
    data << ObjectGuid(HIGHGUID_PLAYER, lowguid);
    data << name;
#endif
    data << uint32(pRace);                                  // race
    data << uint32(pGender);                                // gender
    data << uint32(pClass);                                 // class

    session->SendPacket(&data);
    delete result;
}

void WorldSession::HandleNameQueryOpcode(WorldPacket& recv_data)
{
    WorldPackets::Query::QueryTimeResponse queryTimeResponse;
    queryTimeResponse.CurrentTime = GameTime::GetSystemTime();
    SendPacket(queryTimeResponse.Write());
    ObjectGuid guid;

    recv_data >> guid;

    Player* pChar = sObjectMgr.GetPlayer(guid);

    if (pChar)
        SendNameQueryOpcode(pChar);
    else
        SendNameQueryOpcodeFromDB(guid);
}

void WorldSession::HandleQueryTimeOpcode(WorldPacket& /*recv_data*/)
{
    if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(packet.CreatureID))
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_QUERY_CREATURE '{}' - Entry: {}.", ci->Name, packet.CreatureID);
        if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
            SendPacket(&ci->QueryData[static_cast<uint32>(GetSessionDbLocaleIndex())]);
        else
        {
            WorldPacket response = ci->BuildQueryData(GetSessionDbLocaleIndex());
            SendPacket(&response);
        }
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUERY_CREATURE_RESPONSE");
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_QUERY_CREATURE - NO CREATURE INFO! (ENTRY: {})", packet.CreatureID);
    SendQueryTimeResponse();
}

/// Only _static_ data send in this packet !!!
void WorldSession::HandleCreatureQueryOpcode(WorldPacket& recv_data)
{
    uint32 entry;
    ObjectGuid guid;

    recv_data >> entry;
    recv_data >> guid;

    Creature* unit = _player->GetMap()->GetAnyTypeCreature(guid);

    //if (unit == nullptr)
    //    sLog.outDebug("WORLD: HandleCreatureQueryOpcode - (%u) NO SUCH UNIT! (GUID: %u, ENTRY: %u)", uint32(GUID_LOPART(guid)), guid, entry);

    CreatureInfo const* ci = ObjectMgr::GetCreatureTemplate(entry);
    if (ci)
    {

        std::string Name, SubName;
        Name = ci->name;
        SubName = ci->subname;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            CreatureLocale const* cl = sObjectMgr.GetCreatureLocale(entry);
            if (cl)
            {
                if (cl->Name.size() > size_t(loc_idx) && !cl->Name[loc_idx].empty())
                    Name = cl->Name[loc_idx];
                if (cl->SubName.size() > size_t(loc_idx) && !cl->SubName[loc_idx].empty())
                    SubName = cl->SubName[loc_idx];
            }
        }
        DETAIL_LOG("WORLD: CMSG_CREATURE_QUERY '%s' - Entry: %u.", ci->name, entry);
        // guess size
        WorldPacket data(SMSG_CREATURE_QUERY_RESPONSE, 100);
        data << uint32(entry);                              // creature entry
        data << Name;
        data << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4, always empty
        data << SubName;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
        data << uint32(ci->type_flags);                     // flags
#else
        data << uint32(ci->type_flags << 20);               // flags
#endif
        data << uint32(ci->type);

        data << uint32(ci->pet_family);                     // CreatureFamily.dbc
        data << uint32(ci->rank);                           // Creature Rank (elite, boss, etc)
        data << uint32(0);                                  // unknown        wdbFeild11
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        data << uint32(ci->pet_spell_list_id);              // Id from CreatureSpellData.dbc    wdbField12
#endif
        if (unit)
            data << unit->GetUInt32Value(UNIT_FIELD_DISPLAYID); //DisplayID      wdbFeild13
        else
            data << uint32(ci->display_id[0]);

        data << uint8(ci->civilian);                       //wdbFeild14
        data << uint8(ci->racial_leader);
        SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
    }
    else
    {
        DEBUG_LOG("WORLD: CMSG_CREATURE_QUERY - Guid: %s Entry: %u NO CREATURE INFO!",
                  guid.GetString().c_str(), entry);
        WorldPacket data(SMSG_CREATURE_QUERY_RESPONSE, 4);
        data << uint32(entry | 0x80000000);
        SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
    }
}

/// Only _static_ data send in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPacket& recv_data)
{
    uint32 entryID;
    recv_data >> entryID;
    ObjectGuid guid;
    recv_data >> guid;

    GameObjectInfo const* info = ObjectMgr::GetGameObjectInfo(entryID);
    if (info)
    {
        std::string Name = info->name;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            GameObjectLocale const* gl = sObjectMgr.GetGameObjectLocale(entryID);
            if (gl)
            {
                if (gl->Name.size() > size_t(loc_idx) && !gl->Name[loc_idx].empty())
                    Name = gl->Name[loc_idx];
            }
        }
        DETAIL_LOG("WORLD: CMSG_GAMEOBJECT_QUERY '%s' - Entry: %u. ", info->name, entryID);
        WorldPacket data(SMSG_GAMEOBJECT_QUERY_RESPONSE, 150);
        data << uint32(entryID);
        data << uint32(info->type);
        data << uint32(info->displayId);
        data << Name;
        data << uint8(0) << uint8(0) << uint8(0);   // name2, name3, name4
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
        data << uint8(0);                           // one more name, client handles it a bit differently
        data.append(info->raw.data, 24);            // these are read as int32
#else
        data.append(info->raw.data, 16);            // these are read as int32
#endif    
        //data << float(info->size);                // [-ZERO] go size: not in Zero
        SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for (ENTRY: {})", packet.GameObjectID);

        WorldPackets::Query::QueryGameObjectResponse response;
        response.GameObjectID = packet.GameObjectID;
        response.Guid = packet.Guid;
        SendPacket(response.Write());
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
        DEBUG_LOG("WORLD: CMSG_GAMEOBJECT_QUERY - Guid: %s Entry: %u Missing gameobject info!",
                  guid.GetString().c_str(), entryID);
        WorldPacket data(SMSG_GAMEOBJECT_QUERY_RESPONSE, 4);
        data << uint32(entryID | 0x80000000);
        SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleCorpseQueryOpcode(WorldPacket& /*recv_data*/)
{
    DETAIL_LOG("WORLD: Received MSG_CORPSE_QUERY");

    Corpse* corpse = GetPlayer()->GetCorpse();

    if (!corpse)
    {
        WorldPacket data(MSG_CORPSE_QUERY, 1);
        data << uint8(0);                                   // corpse not found
        SendPacket(&data);
        return;
    }

    uint32 corpsemapid = corpse->GetMapId();
    float x = corpse->GetPositionX();
    float y = corpse->GetPositionY();
    float z = corpse->GetPositionZ();
    int32 mapid = corpsemapid;

    // if corpse at different map
    if (corpsemapid != _player->GetMapId())
    {
        // search entrance map for proper show entrance
        if (MapEntry const* temp = sMapStorage.LookupEntry<MapEntry>(mapid))
        {
            if (temp->IsDungeon() && temp->ghostEntranceMap >= 0)
            {
                // if corpse map have entrance
                if (std::shared_ptr<TerrainInfo> entranceTerrain = sTerrainMgr.LoadTerrain(corpseMapEntry->CorpseMapID))
                if (TerrainInfo const* entranceMap = sTerrainMgr.LoadTerrain(temp->ghostEntranceMap))
                {
                    mapID = corpseMapEntry->CorpseMapID;
                    x = corpseMapEntry->Corpse.X;
                    y = corpseMapEntry->Corpse.Y;
                    z = entranceTerrain->GetStaticHeight(player->GetPhaseShift(), mapID, x, y, MAX_HEIGHT);
                    mapid = temp->ghostEntranceMap;
                    x = temp->ghostEntranceX;
                    y = temp->ghostEntranceY;
                    z = entranceMap->GetHeightStatic(x, y, MAX_HEIGHT);
                }
            }
        }
    }

    WorldPacket data(MSG_CORPSE_QUERY, 1 + (5 * 4));
    data << uint8(1);                                       // corpse found
    data << int32(mapid);
    data << float(x);
    data << float(y);
    data << float(z);
    data << uint32(corpsemapid);
    SendPacket(&data);
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPacket& recv_data)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_NPC_TEXT_QUERY TextId: {}", packet.TextID);
    uint32 textID;
    ObjectGuid guid;

    recv_data >> textID;
    recv_data >> guid;

    DETAIL_LOG("WORLD: CMSG_NPC_TEXT_QUERY ID '%u'", textID);

    _player->SetTargetGuid(guid);

    NpcText const* pGossip = sObjectMgr.GetNpcText(textID);

    WorldPacket data(SMSG_NPC_TEXT_UPDATE, 100);            // guess size
    data << textID;

    if (!pGossip)
    {
        for (uint32 i = 0; i < 8; ++i)
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
            data << float(0);
            data << "Greetings $N";
            data << "Greetings $N";
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
        }
    }
    else
    {
        std::string Text_0[8], Text_1[8];
        int loc_idx = GetSessionDbLocaleIndex();
        for (int i = 0; i < 8; ++i)
        {
            BroadcastText const* bct = sObjectMgr.GetBroadcastTextLocale(pGossip->Options[i].BroadcastTextID);
            if (bct)
            {
                Text_0[i] = bct->GetText(loc_idx, GENDER_MALE, true);
                Text_1[i] = bct->GetText(loc_idx, GENDER_FEMALE, true);

                data << pGossip->Options[i].Probability;

                if (Text_0[i].empty())
                    data << Text_1[i];
                else
                    data << Text_0[i];

                if (Text_1[i].empty())
                    data << Text_0[i];
                else
                    data << Text_1[i];

                data << bct->languageId;

                data << bct->emoteDelay1;
                data << bct->emoteId1;
                data << bct->emoteDelay2;
                data << bct->emoteId2;
                data << bct->emoteDelay3;
                data << bct->emoteId3;
            }
            else
            {
                data << float(0);
                data << "Greetings $N";
                data << "Greetings $N";
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
            }
        }
    }

    SendPacket(&data);

    DEBUG_LOG("WORLD: Sent SMSG_NPC_TEXT_UPDATE");
}

void WorldSession::HandlePageTextQueryOpcode(WorldPacket& recv_data)
{
    uint32 pageID;

    recv_data >> pageID;
    DETAIL_LOG("WORLD: Received CMSG_PAGE_TEXT_QUERY for pageID '%u'", pageID);

    while (pageID)
    {
        PageText const* pPage = sPageTextStore.LookupEntry<PageText>(pageID);
        // guess size
        WorldPacket data(SMSG_PAGE_TEXT_QUERY_RESPONSE, 50);
        data << pageID;

        if (!pPage)
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
            data << "Item page missing.";
            data << uint32(0);
            pageID = 0;
        }
        else
        {
            std::string Text = pPage->Text;

            int loc_idx = GetSessionDbLocaleIndex();
            if (loc_idx >= 0)
            {
                PageTextLocale const* pl = sObjectMgr.GetPageTextLocale(pageID);
                if (pl)
                {
                    if (pl->Text.size() > size_t(loc_idx) && !pl->Text[loc_idx].empty())
                        Text = pl->Text[loc_idx];
                }
            }

            data << Text;
            data << uint32(pPage->Next_Page);
            pageID = pPage->Next_Page;
        }
        SendPacket(&data);

        DEBUG_LOG("WORLD: Sent SMSG_PAGE_TEXT_QUERY_RESPONSE");
    }
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPacket data(SMSG_QUERY_TIME_RESPONSE, 4);
    data << uint32(time(nullptr));
    SendPacket(&data);
}
