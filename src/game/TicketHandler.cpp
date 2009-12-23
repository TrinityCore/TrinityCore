/*
 * Copyright (C) 2005-2009 MaNGOS
 *
 * Copyright (C) 2008-2009 Trinity
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

#include "Language.h"
#include "WorldPacket.h"
#include "Common.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "TimeMgr.h"

void WorldSession::HandleGMTicketCreateOpcode( WorldPacket & recv_data )
{
    if(GM_Ticket *ticket = objmgr.GetGMTicketByPlayer(GetPlayer()->GetGUID()))
    {
        WorldPacket data( SMSG_GMTICKET_CREATE, 4 );
        data << uint32(1); // 1 - You already have GM ticket
        SendPacket( &data );
        return;
    }

    uint32 map;
    float x, y, z;
    std::string ticketText, ticketText2;

    WorldPacket data(SMSG_GMTICKET_CREATE, 4);
    recv_data >> map;
    recv_data >> x;
    recv_data >> y;
    recv_data >> z;
    recv_data >> ticketText;
    recv_data >> ticketText2;

    GM_Ticket *ticket = new GM_Ticket;
    ticket->name = GetPlayer()->GetName();
    ticket->guid = objmgr.GenerateGMTicketId();
    ticket->playerGuid = GetPlayer()->GetGUID();
    ticket->message = ticketText;
    ticket->createtime = sGameTime.GetGameTime();
    ticket->map = map;
    ticket->pos_x = x;
    ticket->pos_y = y;
    ticket->pos_z = z;
    ticket->timestamp = sGameTime.GetGameTime();
    ticket->closed = 0;
    ticket->assignedToGM = 0;
    ticket->comment = "";

    objmgr.AddOrUpdateGMTicket(*ticket, true);

    data << uint32(2);
    SendPacket(&data);

    sWorld.SendGMText(LANG_COMMAND_TICKETNEW, GetPlayer()->GetName(), ticket->guid);

}

void WorldSession::HandleGMTicketUpdateOpcode( WorldPacket & recv_data)
{
    WorldPacket data(SMSG_GMTICKET_UPDATETEXT, 4);

    std::string message;
    recv_data >> message;

    GM_Ticket *ticket = objmgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());
    if(!ticket)
    {
        data << uint32(1);
        SendPacket(&data);
        return;
    }

    ticket->message = message;
    ticket->timestamp = sGameTime.GetGameTime();

    objmgr.AddOrUpdateGMTicket(*ticket);

    data << uint32(2);
    SendPacket(&data);

    sWorld.SendGMText(LANG_COMMAND_TICKETUPDATED, GetPlayer()->GetName(), ticket->guid);

}

void WorldSession::HandleGMTicketDeleteOpcode( WorldPacket & /*recv_data*/)
{
    GM_Ticket* ticket = objmgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());

    if(ticket)
    {
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(9);
        SendPacket(&data);

        sWorld.SendGMText(LANG_COMMAND_TICKETPLAYERABANDON, GetPlayer()->GetName(), ticket->guid );
        objmgr.RemoveGMTicket(ticket, GetPlayer()->GetGUID(), false);
        SendGMTicketGetTicket(0x0A, 0);
    }
}

void WorldSession::HandleGMTicketGetTicketOpcode( WorldPacket & /*recv_data*/)
{
    WorldPacket data( SMSG_QUERY_TIME_RESPONSE, 4+4 );
    data << (uint32)sGameTime.GetGameTime();
    data << (uint32)0;
    SendPacket( &data );

    GM_Ticket *ticket = objmgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());
    if(ticket)
        SendGMTicketGetTicket(0x06, ticket->message.c_str());
    else
        SendGMTicketGetTicket(0x0A, 0);

}

void WorldSession::HandleGMTicketSystemStatusOpcode( WorldPacket & /*recv_data*/)
{
    WorldPacket data(SMSG_GMTICKET_SYSTEMSTATUS, 4);
    data << uint32(1);
    SendPacket(&data);
}

void WorldSession::SendGMTicketGetTicket(uint32 status, char const* text)
{
    int len = text ? strlen(text) : 0;
    WorldPacket data( SMSG_GMTICKET_GETTICKET, (4+len+1+4+2+4+4) );
    data << uint32(status); // standard 0x0A, 0x06 if text present
    if(status == 6)
    {
        data << text; // ticket text
        data << uint8(0x7); // ticket category
        data << float(0); // tickets in queue?
        data << float(0); // if > "tickets in queue" then "We are currently experiencing a high volume of petitions."
        data << float(0); // 0 - "Your ticket will be serviced soon", 1 - "Wait time currently unavailable"
        data << uint8(0); // if == 2 and next field == 1 then "Your ticket has been escalated"
        data << uint8(0); // const
    }
    SendPacket( &data );
}
