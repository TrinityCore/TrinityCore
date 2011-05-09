/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "TicketMgr.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "Player.h"

bool ChatHandler::HandleGMTicketListCommand(const char* /*args*/)
{
    sTicketMgr->ShowList(*this, false);
    return true;
}

bool ChatHandler::HandleGMTicketListOnlineCommand(const char* /*args*/)
{
    sTicketMgr->ShowList(*this, true);
    return true;
}

bool ChatHandler::HandleGMTicketListClosedCommand(const char* /*args*/)
{
    sTicketMgr->ShowClosedList(*this);
    return true;
}

bool ChatHandler::HandleGMTicketListEscalatedCommand(const char* /*args*/)
{
    sTicketMgr->ShowEscalatedList(*this);
    return true;
}

bool ChatHandler::HandleGMTicketGetByIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket *ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetViewed();
    ticket->SaveToDB(trans);

    SendSysMessage(ticket->FormatMessageString(*this, true).c_str());
    return true;
}

bool ChatHandler::HandleGMTicketGetByNameCommand(const char* args)
{
    if (!*args)
        return false;

    std::string name(args);
    if (!normalizePlayerName(name))
        return false;

    // Detect target's GUID
    uint64 guid = 0;
    if (Player *player = sObjectMgr->GetPlayer(name.c_str()))
        guid = player->GetGUID();
    else
        guid = sObjectMgr->GetPlayerGUIDByName(name);
    // Target must exist
    if (!guid)
    {
        SendSysMessage(LANG_NO_PLAYERS_FOUND);
        return true;
    }
    // Ticket must exist
    GmTicket *ticket = sTicketMgr->GetTicketByPlayer(guid);
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetViewed();
    ticket->SaveToDB(trans);

    SendSysMessage(ticket->FormatMessageString(*this, true).c_str());
    return true;
}

bool ChatHandler::HandleGMTicketCloseByIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Ticket must be assigned to player, who tries to close it.
    uint64 guid = m_session->GetPlayer()->GetGUID();
    if (ticket->IsAssignedNotTo(guid))
    {
        PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetId());
        return true;
    }
    sTicketMgr->CloseTicket(ticket->GetId(), guid);
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, m_session->GetPlayer()->GetName(), NULL, NULL, NULL);
    SendGlobalGMSysMessage(msg.c_str());

    // Inform player, who submitted this ticket, that it is closed
    if (Player *player = ticket->GetPlayer())
        if (player->IsInWorld())
        {
            WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
            data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
            player->GetSession()->SendPacket(&data);
        }
    return true;
}

bool ChatHandler::HandleGMTicketAssignToCommand(const char* args)
{
    if (!*args)
        return false;

    char* sTicketId = strtok((char*)args, " ");
    uint32 ticketId = atoi(sTicketId);

    char* sTarget = strtok(NULL, " ");
    if (!sTarget)
        return false;

    std::string target(sTarget);
    if (!normalizePlayerName(target))
        return false;

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Get target information
    uint64 targetGuid = sObjectMgr->GetPlayerGUIDByName(target.c_str());
    uint64 targetAccId = sObjectMgr->GetPlayerAccountIdByGUID(targetGuid);
    uint32 targetGmLevel = sAccountMgr->GetSecurity(targetAccId, realmID);
    // Target must exist and have administrative rights
    if (!targetGuid || targetGmLevel == SEC_PLAYER)
    {
        SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        return true;
    }
    // If already assigned, leave
    if (ticket->IsAssignedTo(targetGuid))
    {
        PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetId());
        return true;
    }
    // If assigned to different player other than current, leave
    Player *player = m_session->GetPlayer();
    if (ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId(), target.c_str());
        return true;
    }
    // Assign ticket
    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetAssignedTo(targetGuid, targetGmLevel == SEC_ADMINISTRATOR);
    ticket->SaveToDB(trans);
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, NULL, target.c_str(), NULL, NULL);
    SendGlobalGMSysMessage(msg.c_str());
    return true;
}

bool ChatHandler::HandleGMTicketUnAssignCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket *ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Ticket must be assigned
    if (!ticket->IsAssigned())
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->GetId());
        return true;
    }
    // Get security level of player, whom this ticket is assigned to
    uint32 security = SEC_PLAYER;
    Player* assignedPlayer = ticket->GetAssignedPlayer();
    if (assignedPlayer && assignedPlayer->IsInWorld())
        security = assignedPlayer->GetSession()->GetSecurity();
    else
    {
        uint64 guid = ticket->GetAssignedToGUID();
        uint32 accountId = sObjectMgr->GetPlayerAccountIdByGUID(guid);
        security = sAccountMgr->GetSecurity(accountId, realmID);
    }
    // Check security
    Player *player = m_session->GetPlayer();
    if (security > uint32(player->GetSession()->GetSecurity()))
    {
        SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetUnassigned();
    ticket->SaveToDB(trans);
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, NULL, ticket->GetAssignedToName(), player->GetName(), NULL);
    SendGlobalGMSysMessage(msg.c_str());
    return true;
}

bool ChatHandler::HandleGMTicketCommentCommand(const char* args)
{
    if (!*args)
        return false;

    char* tguid = strtok((char*)args, " ");
    uint32 ticketId = atoi(tguid);

    char* comment = strtok(NULL, "\n");
    if (!comment)
        return false;

    GmTicket *ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Cannot comment ticket assigned to someone else
    Player* player = m_session->GetPlayer();
    if (ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetComment(comment);
    ticket->SaveToDB(trans);
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, NULL, ticket->GetAssignedToName(), NULL, NULL);
    msg += PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, player->GetName(), comment);
    SendGlobalGMSysMessage(msg.c_str());

    return true;
}

bool ChatHandler::HandleGMTicketDeleteByIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    if (!ticket->IsClosed())
    {
        SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
        return true;
    }

    std::string msg = ticket->FormatMessageString(*this, NULL, NULL, NULL, m_session->GetPlayer()->GetName());
    SendGlobalGMSysMessage(msg.c_str());

    sTicketMgr->RemoveTicket(ticket->GetId());
    sTicketMgr->UpdateLastChange();

    if (Player* player = ticket->GetPlayer())
        if (player->IsInWorld())
        {
            // Force abandon ticket
            WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
            data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
            player->GetSession()->SendPacket(&data);
        }
    return true;
}

bool ChatHandler::HandleToggleGMTicketSystem(const char* /* args */)
{
    bool status = !sTicketMgr->GetStatus();
    sTicketMgr->SetStatus(status);
    PSendSysMessage(status ? LANG_ALLOW_TICKETS : LANG_DISALLOW_TICKETS);
    return true;
}

bool ChatHandler::HandleGMTicketEscalateCommand(const char *args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || !ticket->IsClosed() || ticket->IsCompleted() || ticket->GetEscalatedStatus() != TICKET_UNASSIGNED)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    ticket->SetEscalatedStatus(TICKET_IN_ESCALATION_QUEUE);

    if (Player* player = ticket->GetPlayer())
        if (player->IsInWorld())
            sTicketMgr->SendTicket(player->GetSession(), ticket);

    sTicketMgr->UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketCompleteCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || !ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (Player *player = ticket->GetPlayer())
        if (player->IsInWorld())
            ticket->SendResponse(player->GetSession());

    sTicketMgr->UpdateLastChange();
    return true;
}

inline bool ChatHandler::_HandleGMTicketResponseAppendCommand(const char* args, bool newLine)
{
    if (!*args)
        return false;

    char* sTicketId = strtok((char*)args, " ");
    uint32 ticketId = atoi(sTicketId);

    char* response = strtok(NULL, "\n");
    if (!response)
        return false;

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || !ticket->IsClosed())
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Cannot add response to ticket, assigned to someone else
    Player* player = m_session->GetPlayer();
    if (ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->AppendResponse(response);
    if (newLine)
        ticket->AppendResponse("\n");
    ticket->SaveToDB(trans);

    return true;
}

bool ChatHandler::HandleGMTicketResponseAppendCommand(const char* args)
{
    return _HandleGMTicketResponseAppendCommand(args, false);
}

bool ChatHandler::HandleGMTicketResponseAppendLnCommand(const char* args)
{
    return _HandleGMTicketResponseAppendCommand(args, true);
}
