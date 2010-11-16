/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

std::string ChatHandler::PGetParseString(int32 entry, ...)
{
    const char *format = GetTrinityString(entry);
    va_list ap;
    char str [1024];
    va_start(ap, entry);
    vsnprintf(str,1024,format, ap);
    va_end(ap);
    return (std::string)str;
}

bool ChatHandler::HandleGMTicketListCommand(const char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_TICKETSHOWLIST);
    for (GmTicketList::iterator itr = sTicketMgr.m_GMTicketList.begin(); itr != sTicketMgr.m_GMTicketList.end(); ++itr)
    {
        if ((*itr)->closed != 0 || (*itr)->completed)
            continue;
        std::string gmname;
        std::stringstream ss;
        ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, (*itr)->guid);
        ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, (*itr)->name.c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - (*itr)->createtime, true, false)).c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - (*itr)->timestamp, true, false)).c_str());

        if (sObjectMgr.GetPlayerNameByGUID((*itr)->assignedToGM, gmname))
            ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());

        SendSysMessage(ss.str().c_str());
    }
    return true;
}

bool ChatHandler::HandleGMTicketListOnlineCommand(const char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_TICKETSHOWONLINELIST);
    for (GmTicketList::iterator itr = sTicketMgr.m_GMTicketList.begin(); itr != sTicketMgr.m_GMTicketList.end(); ++itr)
    {
        if ((*itr)->closed != 0 || (*itr)->completed || !sObjectMgr.GetPlayer((*itr)->playerGuid))
            continue;

        std::string gmname;
        std::stringstream ss;
        ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, (*itr)->guid);
        ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, (*itr)->name.c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - (*itr)->createtime, true, false)).c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - (*itr)->timestamp, true, false)).c_str());
        if (sObjectMgr.GetPlayerNameByGUID((*itr)->assignedToGM, gmname))
            ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());
        SendSysMessage(ss.str().c_str());
    }
    return true;
}

bool ChatHandler::HandleGMTicketListClosedCommand(const char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_TICKETSHOWCLOSEDLIST);
    for (GmTicketList::iterator itr = sTicketMgr.m_GMTicketList.begin(); itr != sTicketMgr.m_GMTicketList.end(); ++itr)
    {
        if ((*itr)->closed == 0)
            continue;

        std::string gmname;
        std::stringstream ss;
        ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, (*itr)->guid);
        ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, (*itr)->name.c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - (*itr)->createtime, true, false)).c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - (*itr)->timestamp, true, false)).c_str());
        if (sObjectMgr.GetPlayerNameByGUID((*itr)->assignedToGM, gmname))
            ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());

        SendSysMessage(ss.str().c_str());
    }
    return true;
}

bool ChatHandler::HandleGMTicketListEscalatedCommand(const char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_TICKETSHOWESCALATEDLIST);
    for (GmTicketList::iterator itr = sTicketMgr.m_GMTicketList.begin(); itr != sTicketMgr.m_GMTicketList.end(); ++itr)
    {
        if (!((*itr)->escalated == TICKET_IN_ESCALATION_QUEUE) || (*itr)->closed != 0)
            continue;

        std::string gmname;
        std::stringstream ss;
        ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, (*itr)->guid);
        ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, (*itr)->name.c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - (*itr)->createtime, true, false)).c_str());
        ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - (*itr)->timestamp, true, false)).c_str());
        SendSysMessage(ss.str().c_str());
    }
    return true;
}

bool ChatHandler::HandleGMTicketGetByIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint64 tguid = atoi(args);
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(tguid);
    if (!ticket || ticket->closed != 0 || ticket->completed)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    ticket->viewed = true;

    std::string gmname;
    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - ticket->createtime, true, false)).c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - ticket->timestamp, true, false)).c_str());

    if (sObjectMgr.GetPlayerNameByGUID(ticket->assignedToGM, gmname))
        ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());

    ss <<  PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, ticket->message.c_str());

    if (strlen(ticket->comment.c_str()) != 0)
        ss <<  PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, ticket->comment.c_str());

    SendSysMessage(ss.str().c_str());
    return true;
}

bool ChatHandler::HandleGMTicketGetByNameCommand(const char* args)
{
    if (!*args)
        return false;

    std::string name = (char*)args;
    normalizePlayerName(name);

    Player *plr = sObjectMgr.GetPlayer(name.c_str());
    if (!plr)
    {
        SendSysMessage(LANG_NO_PLAYERS_FOUND);
        return true;
    }

    GM_Ticket *ticket = sTicketMgr.GetGMTicketByPlayer(plr->GetGUID());
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    ticket->viewed = true;

    std::string gmname;
    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTAGECREATE, (secsToTimeString(time(NULL) - ticket->createtime, true, false)).c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTAGE, (secsToTimeString(time(NULL) - ticket->timestamp, true, false)).c_str());

    if (sObjectMgr.GetPlayerNameByGUID(ticket->assignedToGM, gmname))
        ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());

    ss <<  PGetParseString(LANG_COMMAND_TICKETLISTMESSAGE, ticket->message.c_str());

    if (strlen(ticket->comment.c_str()) != 0)
        ss <<  PGetParseString(LANG_COMMAND_TICKETLISTCOMMENT, ticket->comment.c_str());

    SendSysMessage(ss.str().c_str());

    return true;
}

bool ChatHandler::HandleGMTicketCloseByIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint64 tguid = atoi(args);
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(tguid);
    if (!ticket || ticket->closed != 0 || ticket->completed)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (ticket && ticket->assignedToGM != 0 && ticket->assignedToGM != m_session->GetPlayer()->GetGUID())
    {
        PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->guid);
        return true;
    }

    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETCLOSED, m_session->GetPlayer()->GetName());
    SendGlobalGMSysMessage(ss.str().c_str());
    Player *plr = sObjectMgr.GetPlayer(ticket->playerGuid);
    sTicketMgr.RemoveGMTicket(ticket, m_session->GetPlayer()->GetGUID());

    if (!plr || !plr->IsInWorld())
        return true;

    // send abandon ticket
    WorldPacket deleteTicket(SMSG_GMTICKET_DELETETICKET, 4);
    deleteTicket << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
    plr->GetSession()->SendPacket(&deleteTicket);

    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketAssignToCommand(const char* args)
{
    if (!*args)
        return false;

    char* tguid = strtok((char*)args, " ");
    uint64 ticketGuid = atoi(tguid);
    char* targetgm = strtok(NULL, " ");

    if (!targetgm)
        return false;

    std::string targm = targetgm;
    if (!normalizePlayerName(targm))
        return false;

    Player *cplr = m_session->GetPlayer();
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);

    if (!ticket || ticket->closed != 0)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    uint64 tarGUID = sObjectMgr.GetPlayerGUIDByName(targm.c_str());
    uint64 accid = sObjectMgr.GetPlayerAccountIdByGUID(tarGUID);
    uint32 gmlevel = sAccountMgr.GetSecurity(accid, realmID);

    if (!tarGUID || gmlevel == SEC_PLAYER)
    {
        SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        return true;
    }

    if (ticket->assignedToGM == tarGUID)
    {
        PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->guid);
        return true;
    }

    std::string gmname;
    sObjectMgr.GetPlayerNameByGUID(tarGUID, gmname);
    if (ticket->assignedToGM != 0 && ticket->assignedToGM != cplr->GetGUID())
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->guid, gmname.c_str());
        return true;
    }

    ticket->assignedToGM = tarGUID;

    if (gmlevel == SEC_ADMINISTRATOR && ticket->escalated == TICKET_IN_ESCALATION_QUEUE)
        ticket->escalated = TICKET_ESCALATED_ASSIGNED;
    else if (ticket->escalated == TICKET_UNASSIGNED)
        ticket->escalated = TICKET_ASSIGNED;

    sTicketMgr.AddOrUpdateGMTicket(*ticket);

    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());
    SendGlobalGMSysMessage(ss.str().c_str());

    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketUnAssignCommand(const char* args)
{
    if (!*args)
        return false;

    uint64 ticketGuid = atoi(args);
    Player *cplr = m_session->GetPlayer();
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);

    if (!ticket|| ticket->closed != 0)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    if (ticket->assignedToGM == 0)
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->guid);
        return true;
    }

    std::string gmname;
    sObjectMgr.GetPlayerNameByGUID(ticket->assignedToGM, gmname);
    Player *plr = sObjectMgr.GetPlayer(ticket->assignedToGM);
    if (plr && plr->IsInWorld() && plr->GetSession()->GetSecurity() > cplr->GetSession()->GetSecurity())
    {
        SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
        return true;
    }

    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETLISTUNASSIGNED, cplr->GetName());
    SendGlobalGMSysMessage(ss.str().c_str());
    ticket->assignedToGM = 0;
    if (ticket->escalated != TICKET_UNASSIGNED && ticket->escalated != TICKET_IN_ESCALATION_QUEUE)
        ticket->escalated--;
    sTicketMgr.AddOrUpdateGMTicket(*ticket);
    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketCommentCommand(const char* args)
{
    if (!*args)
        return false;

    char* tguid = strtok((char*)args, " ");
    uint64 ticketGuid = atoi(tguid);
    char* comment = strtok(NULL, "\n");

    if (!comment)
        return false;

    Player *cplr = m_session->GetPlayer();
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);

    if (!ticket || ticket->closed != 0)
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    if (ticket->assignedToGM != 0 && ticket->assignedToGM != cplr->GetGUID())
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->guid);
        return true;
    }

    std::string gmname;
    sObjectMgr.GetPlayerNameByGUID(ticket->assignedToGM, gmname);
    ticket->comment = comment;
    sTicketMgr.AddOrUpdateGMTicket(*ticket);
    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());

    if (sObjectMgr.GetPlayerNameByGUID(ticket->assignedToGM, gmname))
        ss << PGetParseString(LANG_COMMAND_TICKETLISTASSIGNEDTO, gmname.c_str());

    ss << PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, cplr->GetName(), ticket->comment.c_str());
    SendGlobalGMSysMessage(ss.str().c_str());
    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketDeleteByIdCommand(const char* args)
{
    if (!*args)
        return false;
    uint64 ticketGuid = atoi(args);
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);

    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    if (ticket->closed == 0)
    {
        SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
        return true;
    }

    std::stringstream ss;
    ss << PGetParseString(LANG_COMMAND_TICKETLISTGUID, ticket->guid);
    ss << PGetParseString(LANG_COMMAND_TICKETLISTNAME, ticket->name.c_str());
    ss << PGetParseString(LANG_COMMAND_TICKETDELETED, m_session->GetPlayer()->GetName());
    SendGlobalGMSysMessage(ss.str().c_str());
    Player *plr = sObjectMgr.GetPlayer(ticket->playerGuid);
    sTicketMgr.RemoveGMTicket(ticket, -1, true); // we don't need to care about who deleted it...
    if (plr && plr->IsInWorld())
    {
        // Force abandon ticket
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
        plr->GetSession()->SendPacket(&data);
    }

    ticket = NULL;
    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleToggleGMTicketSystem(const char* /* args */)
{
    sTicketMgr.SetStatus(!sTicketMgr.GetStatus());
    if(sTicketMgr.GetStatus())
        PSendSysMessage(LANG_ALLOW_TICKETS);
    else
        PSendSysMessage(LANG_DISALLOW_TICKETS);

    return true;
}

bool ChatHandler::HandleGMTicketEscalateCommand(const char *args)
{
    if (!*args)
        return false;

    uint64 tguid = atoi(args);
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(tguid);
    if (!ticket || ticket->closed != 0 || ticket->completed || ticket->escalated != TICKET_UNASSIGNED)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    ticket->escalated = TICKET_IN_ESCALATION_QUEUE;

    Player *plr = sObjectMgr.GetPlayer(ticket->playerGuid);
    if (plr && plr->IsInWorld())
        plr->GetSession()->SendGMTicketGetTicket(GMTICKET_STATUS_HASTEXT, ticket->message.c_str(), ticket);
    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketCompleteCommand(const char* args)
{
    if (!*args)
        return false;

    uint64 tguid = atoi(args);
    GM_Ticket *ticket = sTicketMgr.GetGMTicket(tguid);
    if (!ticket || ticket->closed != 0 || ticket->completed)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    Player *plr = sObjectMgr.GetPlayer(ticket->playerGuid);
    if (plr && plr->IsInWorld())
        plr->GetSession()->SendGMTicketResponse(ticket);
    sTicketMgr.UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketResponseAppendCommand(const char* args)
{
    if (!*args)
        return false;

    char* tguid = strtok((char*)args, " ");
    uint64 ticketGuid = atoi(tguid);
    char* response = strtok(NULL, "\n");

    if (!response)
        return false;

    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);
    Player *cplr = m_session->GetPlayer();

    if (!ticket || ticket->closed != 0)
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (ticket->assignedToGM != 0 && ticket->assignedToGM != cplr->GetGUID())
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->guid);
        return true;
    }

    std::stringstream ss;
    ss << ticket->response;
    ss << response;
    ticket->response = ss.str();
    sTicketMgr.AddOrUpdateGMTicket(*ticket);
    return true;
}

bool ChatHandler::HandleGMTicketResponseAppendLnCommand(const char* args)
{
    if (!*args)
        return false;

    char* tguid = strtok((char*)args, " ");
    uint64 ticketGuid = atoi(tguid);
    char* response = strtok(NULL, "\n");

    if (!response)
        return false;

    GM_Ticket *ticket = sTicketMgr.GetGMTicket(ticketGuid);
    Player *cplr = m_session->GetPlayer();

    if (!ticket || ticket->closed != 0)
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (ticket->assignedToGM != 0 && ticket->assignedToGM != cplr->GetGUID())
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->guid);
        return true;
    }

    std::stringstream ss;
    ss << ticket->response;
    ss << response;
    ss << "\n";
    ticket->response = ss.str();
    sTicketMgr.AddOrUpdateGMTicket(*ticket);
    return true;
}
