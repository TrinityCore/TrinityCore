/*
 * Copyright (C) 2005-2008 MaNGOS 
 *
 * Copyright (C) 2008 Trinity 
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
#include "Language.h"
#include "WorldPacket.h"
#include "Log.h"
#include "GMTicketMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Chat.h"

void WorldSession::SendGMTicketGetTicket(uint32 status, char const* text)
{
    int len = text ? strlen(text) : 0;
    WorldPacket data( SMSG_GMTICKET_GETTICKET, (4+len+1+4+2+4+4) );
    data << uint32(status);                                 // standard 0x0A, 0x06 if text present
    if(status == 6)
    {
        data << text;                                       // ticket text
        data << uint8(0x7);                                 // ticket category
        data << float(0);                                   // time from ticket creation?
        data << float(0);                                   // const
        data << float(0);                                   // const
        data << uint8(0);                                   // const
        data << uint8(0);                                   // const
    }
    SendPacket( &data );
}

void WorldSession::HandleGMTicketGetTicketOpcode( WorldPacket & /*recv_data*/ )
{
    WorldPacket data( SMSG_QUERY_TIME_RESPONSE, 4+4 );
    data << (uint32)time(NULL);
    data << (uint32)0;
    SendPacket( &data );

    GMTicket* ticket = ticketmgr.GetGMTicket(GetPlayer()->GetGUIDLow());
    if(ticket)
        SendGMTicketGetTicket(0x06,ticket->GetText());
    else
        SendGMTicketGetTicket(0x0A,0);
}

void WorldSession::HandleGMTicketUpdateTextOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,1);

    std::string ticketText;
    recv_data >> ticketText;

    if(GMTicket* ticket = ticketmgr.GetGMTicket(GetPlayer()->GetGUIDLow()))
        ticket->SetText(ticketText.c_str());
    else
        sLog.outError("Ticket update: Player %s (GUID: %u) doesn't have active ticket", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow());
}

void WorldSession::HandleGMTicketDeleteOpcode( WorldPacket & /*recv_data*/ )
{
    ticketmgr.Delete(GetPlayer()->GetGUIDLow());

    WorldPacket data( SMSG_GMTICKET_DELETETICKET, 4 );
    data << uint32(9);
    SendPacket( &data );

    SendGMTicketGetTicket(0x0A, 0);
}

void WorldSession::HandleGMTicketCreateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4*4+1+2*4);

    uint32 map;
    float x, y, z;
    std::string ticketText = "";
    uint32 unk1, unk2;

    recv_data >> map >> x >> y >> z;                        // last check 2.4.3
    recv_data >> ticketText;

    // recheck
    CHECK_PACKET_SIZE(recv_data,4*4+(ticketText.size()+1)+2*4);

    recv_data >> unk1 >> unk2;
    // note: the packet might contain more data, but the exact structure of that is unknown

    sLog.outDebug("TicketCreate: map %u, x %f, y %f, z %f, text %s, unk1 %u, unk2 %u", map, x, y, z, ticketText.c_str(), unk1, unk2);

    if(ticketmgr.GetGMTicket(GetPlayer()->GetGUIDLow()))
    {
        WorldPacket data( SMSG_GMTICKET_CREATE, 4 );
        data << uint32(1);
        SendPacket( &data );
        return;
    }

    ticketmgr.Create(_player->GetGUIDLow(), ticketText.c_str());

    WorldPacket data( SMSG_QUERY_TIME_RESPONSE, 4+4 );
    data << (uint32)time(NULL);
    data << (uint32)0;
    SendPacket( &data );

    data.Initialize( SMSG_GMTICKET_CREATE, 4 );
    data << uint32(2);
    SendPacket( &data );
    DEBUG_LOG("update the ticket\n");

    //TODO: Guard player map
    HashMapHolder<Player>::MapType &m = ObjectAccessor::Instance().GetPlayers();
    for(HashMapHolder<Player>::MapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if(itr->second->GetSession()->GetSecurity() >= SEC_GAMEMASTER && itr->second->isAcceptTickets())
            ChatHandler(itr->second).PSendSysMessage(LANG_COMMAND_TICKETNEW,GetPlayer()->GetName());
    }
}

void WorldSession::HandleGMTicketSystemStatusOpcode( WorldPacket & /*recv_data*/ )
{
    WorldPacket data( SMSG_GMTICKET_SYSTEMSTATUS,4 );
    data << uint32(1);                                      // we can also disable ticket system by sending 0 value

    SendPacket( &data );
}

void WorldSession::HandleGMSurveySubmit( WorldPacket & recv_data)
{
    // GM survey is shown after SMSG_GM_TICKET_STATUS_UPDATE with status = 3
    CHECK_PACKET_SIZE(recv_data,4+4);
    uint32 x;
    recv_data >> x;                                         // answer range? (6 = 0-5?)
    sLog.outDebug("SURVEY: X = %u", x);

    uint8 result[10];
    memset(result, 0, sizeof(result));
    for( int i = 0; i < 10; ++i)
    {
        CHECK_PACKET_SIZE(recv_data,recv_data.rpos()+4);
        uint32 questionID;
        recv_data >> questionID;                            // GMSurveyQuestions.dbc
        if (!questionID)
            break;

        CHECK_PACKET_SIZE(recv_data,recv_data.rpos()+1+1);
        uint8 value;
        std::string unk_text;
        recv_data >> value;                                 // answer
        recv_data >> unk_text;                              // always empty?

        result[i] = value;
        sLog.outDebug("SURVEY: ID %u, value %u, text %s", questionID, value, unk_text.c_str());
    }

    CHECK_PACKET_SIZE(recv_data,recv_data.rpos()+1);
    std::string comment;
    recv_data >> comment;                                   // addional comment
    sLog.outDebug("SURVEY: comment %s", comment.c_str());

    // TODO: chart this data in some way
}
