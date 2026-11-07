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
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "Random.h"
#include "TicketMgr.h"
#include "TicketPackets.h"
#include "World.h"
#include <zlib.h>

void WorldSession::HandleGMTicketCreateOpcode(WorldPackets::Ticket::GMTicketCreate& gmTicketCreate)
{
    // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
    if (sTicketMgr->GetStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
        return;

    if (GetPlayer()->GetLevel() < sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TICKET_REQ), sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ));
        return;
    }

    WorldPackets::Ticket::GMTicketCreateResponse gmTicketCreateResponse;
    gmTicketCreateResponse.Result = GMTICKET_RESPONSE_CREATE_ERROR;
    GmTicket* ticket = sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID());

    if (ticket && ticket->IsCompleted())
        sTicketMgr->CloseTicket(ticket->GetId(), GetPlayer()->GetGUID());

    // Player must not have ticket
    if (!ticket || ticket->IsClosed())
    {
        std::string chatLog;

        if (!ValidateHyperlinksAndMaybeKick(gmTicketCreate.Description))
            return;

        if (!gmTicketCreate.ChatTimes.empty() && gmTicketCreate.DecompressedSize && gmTicketCreate.DecompressedSize < 0xFFFF)
        {
            chatLog.resize(gmTicketCreate.DecompressedSize);

            uLongf realSize = gmTicketCreate.DecompressedSize;
            if (uncompress(reinterpret_cast<Bytef*>(chatLog.data()), &realSize, gmTicketCreate.ChatLines.data(), gmTicketCreate.ChatLines.size()) != Z_OK)
            {
                TC_LOG_ERROR("network", "CMSG_GM_TICKET_CREATE possibly corrupt. Uncompression failed.");
                return;
            }

            // client sends text with null terminator and we get another one from std::string (remove all unwanted ones)
            while (!chatLog.empty() && chatLog.back() == '\0')
                chatLog.pop_back();
        }

        if (!chatLog.empty() && !ValidateHyperlinksAndMaybeKick(chatLog))
            return;

        ticket = new GmTicket(GetPlayer());
        ticket->SetPosition(gmTicketCreate.Header.MapID, gmTicketCreate.Header.Position);
        ticket->SetDescription(gmTicketCreate.Description);
        ticket->SetGmAction(gmTicketCreate.NeedResponse, gmTicketCreate.NeedMoreHelp);
        if (!chatLog.empty())
            ticket->SetChatLog(gmTicketCreate.ChatTimes, chatLog);

        sTicketMgr->AddTicket(ticket);
        sTicketMgr->UpdateLastChange();

        sWorld->SendGMText(LANG_COMMAND_TICKETNEW, GetPlayer()->GetName().c_str(), ticket->GetId());

        gmTicketCreateResponse.Result = GMTICKET_RESPONSE_CREATE_SUCCESS;
    }

    SendPacket(gmTicketCreateResponse.Write());
}

void WorldSession::HandleGMTicketUpdateTextOpcode(WorldPackets::Ticket::GMTicketUpdateText& gmTicketUpdateText)
{
    if (!ValidateHyperlinksAndMaybeKick(gmTicketUpdateText.Description))
        return;

    WorldPackets::Ticket::GMTicketUpdate gmTicketUpdate;
    gmTicketUpdate.Result = GMTICKET_RESPONSE_UPDATE_ERROR;
    if (GmTicket* ticket = sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID()))
    {
        CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
        ticket->SetDescription(gmTicketUpdateText.Description);
        ticket->SaveToDB(trans);

        sWorld->SendGMText(LANG_COMMAND_TICKETUPDATED, GetPlayer()->GetName().c_str(), ticket->GetId());

        gmTicketUpdate.Result = GMTICKET_RESPONSE_UPDATE_SUCCESS;
    }

    SendPacket(gmTicketUpdate.Write());
}

void WorldSession::HandleGMTicketDeleteOpcode(WorldPackets::Ticket::GMTicketDelete& /*gmTicketDelete*/)
{
    if (GmTicket* ticket = sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID()))
    {
        WorldPackets::Ticket::GMTicketDeleteResponse gmTicketDeleteResponse;
        gmTicketDeleteResponse.Result = GMTICKET_RESPONSE_TICKET_DELETED;
        SendPacket(gmTicketDeleteResponse.Write());

        sWorld->SendGMText(LANG_COMMAND_TICKETPLAYERABANDON, GetPlayer()->GetName().c_str(), ticket->GetId());

        sTicketMgr->CloseTicket(ticket->GetId(), GetPlayer()->GetGUID());
        sTicketMgr->SendTicket(this, nullptr);
    }
}

void WorldSession::HandleGMTicketGetTicketOpcode(WorldPackets::Ticket::GMTicketGetTicket& /*packet*/)
{
    SendQueryTimeResponse();

    if (GmTicket* ticket = sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID()))
    {
        if (ticket->IsCompleted())
            ticket->SendResponse(this);
        else
            sTicketMgr->SendTicket(this, ticket);
    }
    else
        sTicketMgr->SendTicket(this, nullptr);
}

void WorldSession::HandleGMTicketSystemStatusOpcode(WorldPackets::Ticket::GMTicketGetSystemStatus& /*packet*/)
{
    // Note: This only disables the ticket UI at client side and is not fully reliable
    // Note: This disables the whole customer support UI after trying to send a ticket in disabled state (MessageBox: "GM Help Tickets are currently unavaiable."). UI remains disabled until the character relogs.
    WorldPackets::Ticket::GMTicketSystemStatus response;
    response.Status = sTicketMgr->GetStatus() ? GMTICKET_QUEUE_STATUS_ENABLED : GMTICKET_QUEUE_STATUS_DISABLED;
    SendPacket(response.Write());
}

void WorldSession::HandleGMSurveySubmit(WorldPackets::Ticket::GMSurveySubmit& gmSurveySubmit)
{
    uint32 nextSurveyID = sTicketMgr->GetNextSurveyID();
    // just put the survey into the database

    std::unordered_set<uint32> surveyIds;
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (WorldPackets::Ticket::GMSurveyQuestion const& surveyQuestion : gmSurveySubmit.SurveyQuestion)
    {
        // make sure the same sub survey is not added to DB twice
        if (!surveyIds.insert(surveyQuestion.QuestionID).second)
            continue;

        if (!ValidateHyperlinksAndMaybeKick(surveyQuestion.AnswerComment))
            return;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GM_SUBSURVEY);
        stmt->setUInt32(0, nextSurveyID);
        stmt->setUInt32(1, surveyQuestion.QuestionID);
        stmt->setUInt32(2, surveyQuestion.Answer);
        stmt->setString(3, surveyQuestion.AnswerComment);
        trans->Append(stmt);
    }

    if (!ValidateHyperlinksAndMaybeKick(gmSurveySubmit.Comment))
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GM_SURVEY);
    stmt->setUInt32(0, GetPlayer()->GetGUID().GetCounter());
    stmt->setUInt32(1, nextSurveyID);
    stmt->setUInt32(2, gmSurveySubmit.SurveyID);
    stmt->setString(3, gmSurveySubmit.Comment);

    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandleGMLagReport(WorldPackets::Ticket::GMLagReport& gmLagReport)
{
    // just put the lag report into the database...
    // can't think of anything else to do with it
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_LAG_REPORT);
    stmt->setUInt32(0, GetPlayer()->GetGUID().GetCounter());
    stmt->setUInt8 (1, gmLagReport.LagKind);
    stmt->setUInt16(2, gmLagReport.Header.MapID);
    stmt->setFloat (3, gmLagReport.Header.Position.Pos.GetPositionX());
    stmt->setFloat (4, gmLagReport.Header.Position.Pos.GetPositionY());
    stmt->setFloat (5, gmLagReport.Header.Position.Pos.GetPositionZ());
    stmt->setUInt32(6, GetLatency());
    stmt->setUInt32(7, GameTime::GetGameTime());
    CharacterDatabase.Execute(stmt);
}

void WorldSession::HandleGMResponseResolve(WorldPackets::Ticket::GMTicketResponseResolve& /*gmTicketResponseResolve*/)
{
    // empty packet
    if (GmTicket* ticket = sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID()))
    {
        WorldPackets::Ticket::GMTicketResolveResponse gmTicketResolveResponse;
        gmTicketResolveResponse.ShowSurvey = roll_chance_f(sWorld->getFloatConfig(CONFIG_CHANCE_OF_GM_SURVEY));
        SendPacket(gmTicketResolveResponse.Write());

        WorldPackets::Ticket::GMTicketDeleteResponse gmTicketDeleteResponse;
        gmTicketDeleteResponse.Result = GMTICKET_RESPONSE_TICKET_DELETED;
        SendPacket(gmTicketDeleteResponse.Write());

        sTicketMgr->CloseTicket(ticket->GetId(), GetPlayer()->GetGUID());
        sTicketMgr->SendTicket(this, nullptr);
    }
}
