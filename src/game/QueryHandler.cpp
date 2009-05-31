/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Common.h"
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "Database/DatabaseImpl.h"
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

void WorldSession::SendNameQueryOpcode(Player *p)
{
    if(!p)
        return;

                                                            // guess size
    WorldPacket data( SMSG_NAME_QUERY_RESPONSE, (8+1+4+4+4+10) );
    data << p->GetGUID();
    data << p->GetName();
    data << uint8(0);                                       // realm name for cross realm BG usage
    data << uint32(p->getRace());
    data << uint32(p->getGender());
    data << uint32(p->getClass());
    if(DeclinedName const* names = p->GetDeclinedNames())
    {
        data << uint8(1);                                   // is declined
        for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << names->name[i];
    }
    else
        data << uint8(0);                                   // is not declined

    SendPacket(&data);
}

void WorldSession::SendNameQueryOpcodeFromDB(uint64 guid)
{
    CharacterDatabase.AsyncPQuery(&WorldSession::SendNameQueryOpcodeFromDBCallBack, GetAccountId(),
        !sWorld.getConfig(CONFIG_DECLINED_NAMES_USED) ?
    //   ------- Query Without Declined Names --------
    //          0                1     2
        "SELECT guid, name, SUBSTRING(data, LENGTH(SUBSTRING_INDEX(data, ' ', '%u'))+2, LENGTH(SUBSTRING_INDEX(data, ' ', '%u')) - LENGTH(SUBSTRING_INDEX(data, ' ', '%u'))-1) "
        "FROM characters WHERE guid = '%u'"
        :
    //   --------- Query With Declined Names ---------
    //          0                1     2
        "SELECT characters.guid, name, SUBSTRING(data, LENGTH(SUBSTRING_INDEX(data, ' ', '%u'))+2, LENGTH(SUBSTRING_INDEX(data, ' ', '%u')) - LENGTH(SUBSTRING_INDEX(data, ' ', '%u'))-1), "
    //   3         4       5           6             7
        "genitive, dative, accusative, instrumental, prepositional "
        "FROM characters LEFT JOIN character_declinedname ON characters.guid = character_declinedname.guid WHERE characters.guid = '%u'",
        UNIT_FIELD_BYTES_0, UNIT_FIELD_BYTES_0+1, UNIT_FIELD_BYTES_0, GUID_LOPART(guid));
}

void WorldSession::SendNameQueryOpcodeFromDBCallBack(QueryResult *result, uint32 accountId)
{
    if(!result)
        return;

    WorldSession * session = sWorld.FindSession(accountId);
    if(!session)
    {
        delete result;
        return;
    }

    Field *fields = result->Fetch();
    uint32 guid      = fields[0].GetUInt32();
    std::string name = fields[1].GetCppString();
    uint32 field     = 0;
    if(name == "")
        name         = session->GetTrinityString(LANG_NON_EXIST_CHARACTER);
    else
        field        = fields[2].GetUInt32();

                                                        // guess size
    WorldPacket data( SMSG_NAME_QUERY_RESPONSE, (8+1+4+4+4+10) );
    data << MAKE_NEW_GUID(guid, 0, HIGHGUID_PLAYER);
    data << name;
    data << uint8(0);
    data << uint32(field & 0xFF);
    data << uint32((field >> 16) & 0xFF);
    data << uint32((field >> 8) & 0xFF);

    // if the first declined name field (3) is empty, the rest must be too
    if(sWorld.getConfig(CONFIG_DECLINED_NAMES_USED) && fields[3].GetCppString() != "")
    {
        data << uint8(1);                                   // is declined
        for(int i = 3; i < MAX_DECLINED_NAME_CASES+3; ++i)
            data << fields[i].GetCppString();
    }
    else
        data << uint8(0);                                   // is declined

    session->SendPacket( &data );
    delete result;
}

void WorldSession::HandleNameQueryOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;

    recv_data >> guid;

    Player *pChar = objmgr.GetPlayer(guid);

    if (pChar)
        SendNameQueryOpcode(pChar);
    else
        SendNameQueryOpcodeFromDB(guid);
}

void WorldSession::HandleQueryTimeOpcode( WorldPacket & /*recv_data*/ )
{
    WorldPacket data( SMSG_QUERY_TIME_RESPONSE, 4+4 );
    data << (uint32)time(NULL);
    data << (uint32)0;
    SendPacket( &data );
}

/// Only _static_ data send in this packet !!!
void WorldSession::HandleCreatureQueryOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+8);

    uint32 entry;
    recv_data >> entry;

    CreatureInfo const *ci = objmgr.GetCreatureTemplate(entry);
    if (ci)
    {

        std::string Name, SubName;
        Name = ci->Name;
        SubName = ci->SubName;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            CreatureLocale const *cl = objmgr.GetCreatureLocale(entry);
            if (cl)
            {
                if (cl->Name.size() > loc_idx && !cl->Name[loc_idx].empty())
                    Name = cl->Name[loc_idx];
                if (cl->SubName.size() > loc_idx && !cl->SubName[loc_idx].empty())
                    SubName = cl->SubName[loc_idx];
            }
        }
        sLog.outDetail("WORLD: CMSG_CREATURE_QUERY '%s' - Entry: %u.", ci->Name, entry);
                                                            // guess size
        WorldPacket data( SMSG_CREATURE_QUERY_RESPONSE, 100 );
        data << uint32(entry);                              // creature entry
        data << Name;
        data << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4, always empty
        data << SubName;
        data << ci->IconName;                               // "Directions" for guard, string for Icons 2.3.0
        data << uint32(ci->type_flags);                     // flags
        data << uint32(ci->type);                           // CreatureType.dbc
        data << uint32(ci->family);                         // CreatureFamily.dbc
        data << uint32(ci->rank);                           // Creature Rank (elite, boss, etc)
        data << uint32(ci->PetSpellDataId);                 // Id from CreatureSpellData.dbc    wdbField12
        data << (uint32)ci->Modelid_A1;                     // Modelid_A1
        data << (uint32)ci->Modelid_A2;                     // Modelid_A2
        data << (uint32)ci->Modelid_H1;                     // Modelid_H1
        data << (uint32)ci->Modelid_H2;                     // Modelid_H2
        data << float(ci->unk17);                           // unk
        data << uint8(ci->RacialLeader);
        SendPacket( &data );
        sLog.outDebug( "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE" );
    }
    else
    {
        uint64 guid;
        recv_data >> guid;

        sLog.outDebug("WORLD: CMSG_CREATURE_QUERY - NO CREATURE INFO! (GUID: %u, ENTRY: %u)",
            GUID_LOPART(guid), entry);
        WorldPacket data( SMSG_CREATURE_QUERY_RESPONSE, 4 );
        data << uint32(entry | 0x80000000);
        SendPacket( &data );
        sLog.outDebug( "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE" );
    }
}

/// Only _static_ data send in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+8);

    uint32 entryID;
    recv_data >> entryID;

    const GameObjectInfo *info = objmgr.GetGameObjectInfo(entryID);
    if(info)
    {
        std::string Name;
        std::string IconName;
        std::string CastBarCaption;

        Name = info->name;
        IconName = info->IconName;
        CastBarCaption = info->castBarCaption;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            GameObjectLocale const *gl = objmgr.GetGameObjectLocale(entryID);
            if (gl)
            {
                if (gl->Name.size() > loc_idx && !gl->Name[loc_idx].empty())
                    Name = gl->Name[loc_idx];
                if (gl->CastBarCaption.size() > loc_idx && !gl->CastBarCaption[loc_idx].empty())
                    CastBarCaption = gl->CastBarCaption[loc_idx];
            }
        }
        sLog.outDetail("WORLD: CMSG_GAMEOBJECT_QUERY '%s' - Entry: %u. ", info->name, entryID);
        WorldPacket data ( SMSG_GAMEOBJECT_QUERY_RESPONSE, 150 );
        data << uint32(entryID);
        data << uint32(info->type);
        data << uint32(info->displayId);
        data << Name;
        data << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4
        data << IconName;                                   // 2.0.3, string. Icon name to use instead of default icon for go's (ex: "Attack" makes sword)
        data << CastBarCaption;                             // 2.0.3, string. Text will appear in Cast Bar when using GO (ex: "Collecting")
        data << uint8(0);                                   // 2.0.3, string
        data.append(info->raw.data, 24);
        data << float(info->size);                          // go size
        SendPacket( &data );
        sLog.outDebug( "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE" );
    }
    else
    {

        uint64 guid;
        recv_data >> guid;

        sLog.outDebug(  "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for (GUID: %u, ENTRY: %u)",
            GUID_LOPART(guid), entryID );
        WorldPacket data ( SMSG_GAMEOBJECT_QUERY_RESPONSE, 4 );
        data << uint32(entryID | 0x80000000);
        SendPacket( &data );
        sLog.outDebug( "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE" );
    }
}

void WorldSession::HandleCorpseQueryOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDetail("WORLD: Received MSG_CORPSE_QUERY");

    Corpse *corpse = GetPlayer()->GetCorpse();

    if(!corpse)
    {
        WorldPacket data(MSG_CORPSE_QUERY, 1);
        data << uint8(0);                                   // corpse not found
        SendPacket(&data);
        return;
    }

    int32 mapid = corpse->GetMapId();
    float x = corpse->GetPositionX();
    float y = corpse->GetPositionY();
    float z = corpse->GetPositionZ();
    int32 corpsemapid = _player->GetMapId();

    if(Map *map = MapManager::Instance().FindMap(corpse->GetMapId(), corpse->GetInstanceId()))
    {
        if(map->IsDungeon())
        {
            if(!map->GetEntrancePos(mapid, x, y))
                return;

            Map *entrance_map = MapManager::Instance().GetMap(mapid, _player);
            if(!entrance_map)
                return;

            z = entrance_map->GetHeight(x, y, MAX_HEIGHT);
            corpsemapid = corpse->GetMapId();
        }
    }

    WorldPacket data(MSG_CORPSE_QUERY, 1+(5*4));
    data << uint8(1);                                       // corpse found
    data << int32(mapid);
    data << float(x);
    data << float(y);
    data << float(z);
    data << int32(corpsemapid);
    SendPacket(&data);
}

void WorldSession::HandleNpcTextQueryOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4 + 8);

    uint32 textID;
    uint64 guid;

    recv_data >> textID;
    sLog.outDetail("WORLD: CMSG_NPC_TEXT_QUERY ID '%u'", textID);

    recv_data >> guid;
    GetPlayer()->SetUInt64Value(UNIT_FIELD_TARGET, guid);

    GossipText const* pGossip = objmgr.GetGossipText(textID);

    WorldPacket data( SMSG_NPC_TEXT_UPDATE, 100 );          // guess size
    data << textID;

    if (!pGossip)
    {
        for(uint32 i = 0; i < 8; ++i)
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
    else
    {
        std::string Text_0[8], Text_1[8];
        for (int i = 0; i < 8; ++i)
        {
            Text_0[i]=pGossip->Options[i].Text_0;
            Text_1[i]=pGossip->Options[i].Text_1;
        }

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            NpcTextLocale const *nl = objmgr.GetNpcTextLocale(textID);
            if (nl)
            {
                for (int i = 0; i < 8; ++i)
                {
                    if (nl->Text_0[i].size() > loc_idx && !nl->Text_0[i][loc_idx].empty())
                        Text_0[i]=nl->Text_0[i][loc_idx];
                    if (nl->Text_1[i].size() > loc_idx && !nl->Text_1[i][loc_idx].empty())
                        Text_1[i]=nl->Text_1[i][loc_idx];
                }
            }
        }

        for (int i = 0; i < 8; ++i)
        {
            data << pGossip->Options[i].Probability;

            if ( Text_0[i].empty() )
                data << Text_1[i];
            else
                data << Text_0[i];

            if ( Text_1[i].empty() )
                data << Text_0[i];
            else
                data << Text_1[i];

            data << pGossip->Options[i].Language;

            for(int j = 0; j < 3; ++j)
            {
                data << pGossip->Options[i].Emotes[j]._Delay;
                data << pGossip->Options[i].Emotes[j]._Emote;
            }
        }
    }

    SendPacket( &data );

    sLog.outDebug( "WORLD: Sent SMSG_NPC_TEXT_UPDATE" );
}

void WorldSession::HandlePageTextQueryOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4);

    uint32 pageID;

    recv_data >> pageID;
    sLog.outDetail("WORLD: Received CMSG_PAGE_TEXT_QUERY for pageID '%u'", pageID);

    while (pageID)
    {
        PageText const *pPage = sPageTextStore.LookupEntry<PageText>( pageID );
                                                            // guess size
        WorldPacket data( SMSG_PAGE_TEXT_QUERY_RESPONSE, 50 );
        data << pageID;

        if (!pPage)
        {
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
                PageTextLocale const *pl = objmgr.GetPageTextLocale(pageID);
                if (pl)
                {
                    if (pl->Text.size() > loc_idx && !pl->Text[loc_idx].empty())
                        Text = pl->Text[loc_idx];
                }
            }

            data << Text;
            data << uint32(pPage->Next_Page);
            pageID = pPage->Next_Page;
        }
        SendPacket( &data );

        sLog.outDebug( "WORLD: Sent SMSG_PAGE_TEXT_QUERY_RESPONSE" );
    }
}

