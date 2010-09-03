/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org>
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
#include "TicketMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"
#include "Util.h"

void WorldSession::HandleGMTicketCreateOpcode(WorldPacket & recv_data)
{
    if (GetPlayer()->getLevel() < sWorld.getIntConfig(CONFIG_TICKET_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TICKET_REQ), sWorld.getIntConfig(CONFIG_TICKET_LEVEL_REQ));
        return;
    }

    if (sTicketMgr.GetGMTicketByPlayer(GetPlayer()->GetGUID()))
    {
        WorldPacket data(SMSG_GMTICKET_CREATE, 4);
        data << uint32(GMTICKET_RESPONSE_FAILURE); // You already have GM ticket
        SendPacket(&data);
        return;
    }

    uint32 map, unk1;
    uint8 needResponse; // ignored
    float x, y, z;
    std::string ticketText, ticketText2;

    SendQueryTimeResponse();

    recv_data >> map;
    recv_data >> x;
    recv_data >> y;
    recv_data >> z;
    recv_data >> ticketText;
    recv_data >> unk1; // not sure what this is... replyTo?
    recv_data >> needResponse; // always 1/0 -- not sure what retail does with this

    GM_Ticket *ticket = new GM_Ticket;
    ticket->name = GetPlayer()->GetName();
    ticket->guid = sTicketMgr.GenerateGMTicketId();
    ticket->playerGuid = GetPlayer()->GetGUID();
    ticket->message = ticketText;
    ticket->createtime = time(NULL);
    ticket->map = map;
    ticket->pos_x = x;
    ticket->pos_y = y;
    ticket->pos_z = z;
    ticket->timestamp = time(NULL);
    ticket->closed = 0;
    ticket->assignedToGM = 0;
    ticket->comment = "";
    ticket->completed = false;
    ticket->escalated = TICKET_UNASSIGNED;
    ticket->response = "";

    sTicketMgr.AddOrUpdateGMTicket(*ticket, true);

    WorldPacket data(SMSG_GMTICKET_CREATE, 4);
    data << uint32(GMTICKET_RESPONSE_SUCCESS);
    SendPacket(&data);

    sWorld.SendGMText(LANG_COMMAND_TICKETNEW, GetPlayer()->GetName(), ticket->guid);
}

void WorldSession::HandleGMTicketUpdateOpcode(WorldPacket & recv_data)
{
    std::string message;
    recv_data >> message;

    GM_Ticket *ticket = sTicketMgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());
    if (!ticket)
    {
        WorldPacket data(SMSG_GMTICKET_UPDATETEXT, 4);
        data << uint32(GMTICKET_RESPONSE_FAILURE);
        SendPacket(&data);
        return;
    }

    ticket->message = message;
    ticket->timestamp = time(NULL);

    sTicketMgr.AddOrUpdateGMTicket(*ticket);

    WorldPacket data(SMSG_GMTICKET_UPDATETEXT, 4);
    data << uint32(GMTICKET_RESPONSE_SUCCESS);
    SendPacket(&data);

    sWorld.SendGMText(LANG_COMMAND_TICKETUPDATED, GetPlayer()->GetName(), ticket->guid);
}

void WorldSession::HandleGMTicketDeleteOpcode(WorldPacket & /*recv_data*/)
{
    GM_Ticket* ticket = sTicketMgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());

    if (ticket)
    {
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
        SendPacket(&data);

        sWorld.SendGMText(LANG_COMMAND_TICKETPLAYERABANDON, GetPlayer()->GetName(), ticket->guid);
        sTicketMgr.RemoveGMTicket(ticket, GetPlayer()->GetGUID(), false);
        SendGMTicketGetTicket(GMTICKET_STATUS_DEFAULT, NULL);
    }
}

void WorldSession::HandleGMTicketGetTicketOpcode(WorldPacket & /*recv_data*/)
{
    SendQueryTimeResponse();

    if (GM_Ticket *ticket = sTicketMgr.GetGMTicketByPlayer(GetPlayer()->GetGUID()))
    {
        if (ticket->completed)
            SendGMTicketResponse(ticket);
        else
            SendGMTicketGetTicket(GMTICKET_STATUS_HASTEXT, ticket->message.c_str(), ticket);
    }
    else
        SendGMTicketGetTicket(GMTICKET_STATUS_DEFAULT, NULL);
}

void WorldSession::HandleGMTicketSystemStatusOpcode(WorldPacket & /*recv_data*/)
{
    WorldPacket data(SMSG_GMTICKET_SYSTEMSTATUS, 4);
    // are we sure this is a uint32? Should ask Zor
    data << uint32(sTicketMgr.GetStatus() ? GMTICKET_QUEUE_STATUS_ENABLED : GMTICKET_QUEUE_STATUS_DISABLED);
    SendPacket(&data);
}

void WorldSession::SendGMTicketGetTicket(uint32 status, char const* text, GM_Ticket *ticket /* = NULL */)
{
    int len = text ? strlen(text) : 0;
    WorldPacket data(SMSG_GMTICKET_GETTICKET, (4+4+((status == GMTICKET_STATUS_HASTEXT) ? (len+1+4+4+4+1+1) : 0)));
    data << uint32(status); // standard 0x0A, 0x06 if text present
    data << uint32(1);      // g_HasActiveGMTicket -- not a flag

    if (status == GMTICKET_STATUS_HASTEXT)
    {
        data << text; // ticket text
        data << uint8(0x7); // ticket category; why is this hardcoded? does it make a diff re: client?

        // we've got the easy stuff done by now.
        // Now we need to go through the client logic for displaying various levels of ticket load
        if (ticket)
        {
            // get ticketage, but it's stored in seconds so we have to do it in days
            float ticketAge = (float)time(NULL) - (float)ticket->timestamp;
            ticketAge /= DAY;

            data << float(ticketAge); // ticketAge (days)
            if (GM_Ticket *oldestTicket = sTicketMgr.GetOldestOpenGMTicket())
            {
                // get ticketage, but it's stored in seconds so we have to do it in days
                float oldestTicketAge = (float)time(NULL) - (float)oldestTicket->timestamp;
                oldestTicketAge /= DAY;
                data << float(oldestTicketAge);
            }
            else
                data << float(0);

            // I am not sure how blizzlike this is, and we don't really have a way to find out
            int64 lastChange = int64(sTicketMgr.GetLastChange());
            float timeDiff = float(int64(time(NULL)) - lastChange);
            timeDiff /= DAY;
            data << float(timeDiff);

            data << uint8(std::min(ticket->escalated, uint8(TICKET_IN_ESCALATION_QUEUE))); // escalated data
            data << uint8(ticket->viewed ? GMTICKET_OPENEDBYGM_STATUS_OPENED : GMTICKET_OPENEDBYGM_STATUS_NOT_OPENED); // whether or not it has been viewed
        }
        else
        {
            // we can't actually get any numbers here...
            data << float(0);
            data << float(0);
            data << float(1);
            data << uint8(0);
            data << uint8(0);
        }
    }

    SendPacket(&data);
}

void WorldSession::SendGMTicketResponse(GM_Ticket *ticket)
{
    if (!ticket)
        return;

    WorldPacket data(SMSG_GMRESPONSE_RECEIVED);
    data << uint32(1); // unk? Zor says "hasActiveTicket"
    data << uint32(0); // can-edit - always 1 or 0, not flags
    data << ticket->message.c_str();
    data << ticket->response.c_str();
    for (int8 j = 0; j < 3; j++)
        data << uint8(0); // 3 null strings
    SendPacket(&data);
}

void WorldSession::HandleGMSurveySubmit(WorldPacket& recv_data)
{
    uint64 nextSurveyID = sTicketMgr.GetNextSurveyID();
    // just put the survey into the database
    std::ostringstream ss;
    uint32 mainSurvey; // GMSurveyCurrentSurvey.dbc, column 1 (all 9) ref to GMSurveySurveys.dbc
    recv_data >> mainSurvey;

    ss << "INSERT INTO gm_surveys (player, surveyid, mainSurvey, overall_comment, timestamp) VALUES (";
    ss << GetPlayer()->GetGUID() << ", ";
    ss << nextSurveyID << ", ";
    ss << mainSurvey << ", ";

    // sub_survey1, r1, comment1, sub_survey2, r2, comment2, sub_survey3, r3, comment3, sub_survey4, r4, comment4, sub_survey5, r5, comment5, sub_survey6, r6, comment6, sub_survey7, r7, comment7, sub_survey8, r8, comment8, sub_survey9, r9, comment9, sub_survey10, r10, comment10, 

    for (uint8 i = 0; i < 10; i++)
    {
        std::ostringstream os;
        os << "INSERT INTO gm_subsurveys (surveyid, subsurveyid, rank, comment) VALUES (";
        uint32 subSurveyId; // ref to i'th GMSurveySurveys.dbc field (all fields in that dbc point to fields in GMSurveyQuestions.dbc)
        recv_data >> subSurveyId;
        if(!subSurveyId)
            break;

        uint8 rank; // probably some sort of ref to GMSurveyAnswers.dbc
        std::string comment; // comment ("Usage: GMSurveyAnswerSubmit(question, rank, comment)")
        recv_data >> rank;
        recv_data >> comment;

        os << nextSurveyID << " ";
        os << subSurveyId << ", ";
        os << rank << ", '";
        CharacterDatabase.escape_string(comment);
        os << comment << "');";
        CharacterDatabase.PExecute(os.str().c_str());
    }

    std::string comment; // just a guess
    recv_data >> comment;
    CharacterDatabase.escape_string(comment);
    ss << "'" << comment << "', ";
    ss << int64(time_t(NULL)) << ");";

    CharacterDatabase.PExecute(ss.str().c_str());
}

void WorldSession::HandleReportLag(WorldPacket& recv_data)
{
    // just put the lag report into the database...
    // can't think of anything else to do with it
    uint32 lagType, mapId;
    float x, y, z;
    recv_data >> lagType;
    recv_data >> mapId;
    recv_data >> x;
    recv_data >> y;
    recv_data >> z;

    // build and execute query
    std::ostringstream os;
    os << "INSERT INTO lag_reports (player, lag_type, map, posX, posY, posZ) VALUES (";
    os << GetPlayer()->GetGUID() << ", ";
    os << lagType << ", ";
    os << mapId << ", ";
    os << x << ", ";
    os << y << ", ";
    os << z << ");";

    CharacterDatabase.Execute(os.str().c_str());
}

void WorldSession::HandleGMResponseResolve(WorldPacket& /*recvPacket*/)
{
    // empty packet
    GM_Ticket* ticket = sTicketMgr.GetGMTicketByPlayer(GetPlayer()->GetGUID());

    if (ticket)
    {
        uint8 getSurvey = 0;
        if ((float)rand_chance() < sWorld.getFloatConfig(CONFIG_CHANCE_OF_GM_SURVEY))
            getSurvey = 1;

        WorldPacket data(SMSG_GMRESPONSE_STATUS_UPDATE, 4);
        data << uint8(getSurvey);
        SendPacket(&data);

        WorldPacket data2(SMSG_GMTICKET_DELETETICKET, 4);
        data2 << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
        SendPacket(&data2);
        sTicketMgr.RemoveGMTicket(ticket, GetPlayer()->GetGUID(), true);
        SendGMTicketGetTicket(GMTICKET_STATUS_DEFAULT, NULL);
    }
}
