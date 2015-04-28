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

#include "zlib.h"
#include "Common.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "SupportMgr.h"
#include "TicketPackets.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

void WorldSession::HandleGMTicketCreateOpcode(WorldPackets::Ticket::GMTicketCreate& packet)
{
    // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
    if (sSupportMgr->GetSupportSystemStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
        return;

    if (GetPlayer()->getLevel() < sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TICKET_REQ), sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ));
        return;
    }

    GMTicketResponse response = GMTICKET_RESPONSE_CREATE_ERROR;
    GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(GetPlayer()->GetGUID());

    if (ticket && ticket->IsCompleted())
        sSupportMgr->CloseTicket<GmTicket>(ticket->GetId(), GetPlayer()->GetGUID());

    // Player must not have ticket
    if (!ticket || ticket->IsClosed())
    {
        std::string chatLog;

        if (packet.DataLength > 0 && packet.ChatHistoryData.DecompressedSize < 0xFFFF)
        {
            ByteBuffer dest;
            dest.resize(size_t(packet.ChatHistoryData.DecompressedSize));

            uLongf realSize = packet.ChatHistoryData.DecompressedSize;

            if (uncompress(dest.contents(), &realSize, packet.ChatHistoryData.Data.contents(), packet.ChatHistoryData.Data.size()) == Z_OK)
                dest >> chatLog;
            else
            {
                TC_LOG_ERROR("network", "CMSG_GM_TICKET_CREATE possibly corrupt. Uncompression failed.");
                return;
            }
        }

        ticket = new GmTicket(GetPlayer());
        ticket->SetPosition(packet.Map, packet.Pos);
        ticket->SetDescription(packet.Description);
        ticket->SetGmAction(packet.NeedResponse, packet.NeedMoreHelp);

        //TODO: more reasearch needed
        //if (!chatLog.empty())
            //ticket->SetChatLog(times, chatLog);

        sSupportMgr->AddTicket(ticket);
        sSupportMgr->UpdateLastChange();

        sWorld->SendGMText(LANG_COMMAND_TICKETNEW, GetPlayer()->GetName().c_str(), ticket->GetId());

        response = GMTICKET_RESPONSE_CREATE_SUCCESS;
    }
    sSupportMgr->SendGmTicketUpdate(this, response);
}

void WorldSession::HandleGMTicketUpdateTextOpcode(WorldPackets::Ticket::GMTicketUpdateText& packet)
{
    GMTicketResponse response = GMTICKET_RESPONSE_UPDATE_ERROR;
    if (GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(GetPlayer()->GetGUID()))
    {
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetDescription(packet.Description);
        ticket->SaveToDB(trans);

        sWorld->SendGMText(LANG_COMMAND_TICKETUPDATED, GetPlayer()->GetName().c_str(), ticket->GetId());

        response = GMTICKET_RESPONSE_UPDATE_SUCCESS;
    }
    sSupportMgr->SendGmTicketUpdate(this, response);
}

void WorldSession::HandleGMTicketDeleteOpcode(WorldPackets::Ticket::GMTicketDelete& /*packet*/)
{
    if (GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(GetPlayer()->GetGUID()))
    {
        sSupportMgr->SendGmTicketUpdate(this, GMTICKET_RESPONSE_TICKET_DELETED);

        sWorld->SendGMText(LANG_COMMAND_TICKETPLAYERABANDON, GetPlayer()->GetName().c_str(), ticket->GetId());

        sSupportMgr->CloseTicket<GmTicket>(ticket->GetId(), GetPlayer()->GetGUID());
        sSupportMgr->SendGmTicket(this, NULL);
    }
}

void WorldSession::HandleGMTicketGetCaseStatusOpcode(WorldPackets::Ticket::GMTicketGetCaseStatus& /*packet*/)
{
    // TODO: Implement GmCase and handle this packet properly
    WorldPackets::Ticket::GMTicketCaseStatus status;
    status.OldestTicketTime = time(nullptr);
    SendPacket(status.Write());
}

void WorldSession::HandleGMTicketGetTicketOpcode(WorldPackets::Ticket::GMTicketGetTicket& /*packet*/)
{
    SendQueryTimeResponse();

    if (GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(GetPlayer()->GetGUID()))
    {
        if (ticket->IsCompleted())
            ticket->SendResponse(this);
        else
            sSupportMgr->SendGmTicket(this, ticket);
    }
    else
        sSupportMgr->SendGmTicket(this, NULL);
}

void WorldSession::HandleGMTicketSystemStatusOpcode(WorldPackets::Ticket::GMTicketGetSystemStatus& /*packet*/)
{
    // Note: This only disables the ticket UI at client side and is not fully reliable
    // Note: This disables the whole customer support UI after trying to send a ticket in disabled state (MessageBox: "GM Help Tickets are currently unavaiable."). UI remains disabled until the character relogs.
    WorldPackets::Ticket::GMTicketSystemStatus response;
    response.Status = sSupportMgr->GetSupportSystemStatus() ? GMTICKET_QUEUE_STATUS_ENABLED : GMTICKET_QUEUE_STATUS_DISABLED;
    SendPacket(response.Write());
}

void WorldSession::HandleGMSurveySubmit(WorldPackets::Ticket::GMSurveySubmit& /*packet*/)
{
    /*uint32 nextSurveyID = sSupportMgr->GetNextSurveyID();

    std::unordered_set<uint32> surveyIds;
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (auto const& q : packet.SurveyQuestion)
    {
        if (!q.QuestionID)
            break;

        // make sure the same sub survey is not added to DB twice
        if (!surveyIds.insert(q.QuestionID).second)
            continue;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GM_SUBSURVEY);
        stmt->setUInt32(0, nextSurveyID);
        stmt->setUInt32(1, q.QuestionID); // ref to i'th GMSurveySurveys.dbc field (all fields in that dbc point to fields in GMSurveyQuestions.dbc)
        stmt->setUInt32(2, q.Answer); // probably some sort of ref to GMSurveyAnswers.dbc
        stmt->setString(3, q.AnswerComment); // comment ("Usage: GMSurveyAnswerSubmit(question, rank, comment)")
        trans->Append(stmt);
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GM_SURVEY);
    stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
    stmt->setUInt32(1, nextSurveyID);
    stmt->setUInt32(2, packet.SurveyID); // GMSurveyCurrentSurvey.dbc, column 1 (all 9) ref to GMSurveySurveys.dbc
    stmt->setString(3, packet.Comment);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);*/
}

void WorldSession::HandleGMResponseResolve(WorldPackets::Ticket::GMTicketResponseResolve& /*packet*/)
{
    if (GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(GetPlayer()->GetGUID()))
    {
        bool showSurvey = false;
        if (float(rand_chance()) < sWorld->getFloatConfig(CONFIG_CHANCE_OF_GM_SURVEY))
            showSurvey = true;

        WorldPackets::Ticket::GMTicketResolveResponse response;
        response.ShowSurvey = showSurvey;
        SendPacket(response.Write());

        sSupportMgr->SendGmTicketUpdate(this, GMTICKET_RESPONSE_TICKET_DELETED);

        sSupportMgr->CloseTicket<GmTicket>(ticket->GetId(), GetPlayer()->GetGUID());
        sSupportMgr->SendGmTicket(this, NULL);
    }
}

void WorldSession::HandleSupportTicketSubmitBug(WorldPackets::Ticket::SupportTicketSubmitBug& packet)
{
    if (!sSupportMgr->GetBugSystemStatus())
        return;

    BugTicket* ticket = new BugTicket(GetPlayer());
    ticket->SetPosition(packet.Header.MapID, packet.Header.Position);
    ticket->SetFacing(packet.Header.Facing);
    ticket->SetNote(packet.Note);

    sSupportMgr->AddTicket(ticket);
}

void WorldSession::HandleSupportTicketSubmitSuggestion(WorldPackets::Ticket::SupportTicketSubmitSuggestion& packet)
{
    if (!sSupportMgr->GetSuggestionSystemStatus())
        return;

    SuggestionTicket* ticket = new SuggestionTicket(GetPlayer());
    ticket->SetPosition(packet.Header.MapID, packet.Header.Position);
    ticket->SetFacing(packet.Header.Facing);
    ticket->SetNote(packet.Note);

    sSupportMgr->AddTicket(ticket);
}

void WorldSession::HandleSupportTicketSubmitComplaint(WorldPackets::Ticket::SupportTicketSubmitComplaint& packet)
{
    if (!sSupportMgr->GetComplaintSystemStatus())
        return;

    ComplaintTicket* comp = new ComplaintTicket(GetPlayer());
    comp->SetPosition(packet.Header.MapID, packet.Header.Position);
    comp->SetFacing(packet.Header.Facing);
    comp->SetChatLog(packet.ChatLog);
    comp->SetTargetCharacterGuid(packet.TargetCharacterGUID);
    comp->SetComplaintType(GMSupportComplaintType(packet.ComplaintType));
    comp->SetNote(packet.Note);

    sSupportMgr->AddTicket(comp);
}

void WorldSession::HandleBugReportOpcode(WorldPackets::Ticket::BugReport& bugReport)
{
    // Note: There is no way to trigger this with standard UI except /script ReportBug("text")
    if (!sSupportMgr->GetBugSystemStatus())
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BUG_REPORT);
    stmt->setString(0, bugReport.Text);
    stmt->setString(1, bugReport.DiagInfo);
    CharacterDatabase.Execute(stmt);
}
