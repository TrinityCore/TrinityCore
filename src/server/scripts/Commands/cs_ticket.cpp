/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
Name: ticket_commandscript
%Complete: 100
Comment: All ticket related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "Chat.h"
#include "Config.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SupportMgr.h"

class ticket_commandscript : public CommandScript
{
public:
    ticket_commandscript() : CommandScript("ticket_commandscript") { }

    template<typename T>
    static bool HandleTicketAssignToCommand(ChatHandler* handler, char const* args);

    template<typename T>
    static bool HandleTicketCloseByIdCommand(ChatHandler* handler, char const* args);

    template<typename T>
    static bool HandleTicketCommentCommand(ChatHandler* handler, char const* args);

    template<typename T>
    static bool HandleTicketDeleteByIdCommand(ChatHandler* handler, char const* args);

    template<typename T>
    static bool HandleTicketListCommand(ChatHandler* handler, char const* /*args*/);

    template<typename T>
    static bool HandleTicketListClosedCommand(ChatHandler* handler, char const* /*args*/);

    template<typename T>
    static bool HandleTicketResetCommand(ChatHandler* handler, char const* /*args*/);

    template<typename T>
    static bool HandleTicketUnAssignCommand(ChatHandler* handler, char const* args);

    template<typename T>
    static bool HandleTicketGetByIdCommand(ChatHandler* handler, char const* args);

    static bool HandleGMTicketCompleteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        if (Player* player = ticket->GetPlayer())
            ticket->SendResponse(player->GetSession());

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetCompleted();
        ticket->SaveToDB(trans);

        std::string msg = ticket->FormatViewMessageString(*handler, NULL, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console");
        handler->SendGlobalGMSysMessage(msg.c_str());
        sSupportMgr->UpdateLastChange();
        return true;
    }

    static bool HandleGMTicketEscalateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted() || ticket->GetEscalatedStatus() != TICKET_UNASSIGNED)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        ticket->SetEscalatedStatus(TICKET_IN_ESCALATION_QUEUE);

        if (Player* player = ticket->GetPlayer())
            sSupportMgr->SendGmTicket(player->GetSession(), ticket);

        sSupportMgr->UpdateLastChange();
        return true;
    }

    static bool HandleGMTicketListEscalatedCommand(ChatHandler* handler, char const* /*args*/)
    {
        sSupportMgr->ShowGmEscalatedList(*handler);
        return true;
    }

    static bool HandleGMTicketListOnlineCommand(ChatHandler* handler, char const* /*args*/)
    {
        sSupportMgr->ShowList<GmTicket>(*handler, true);
        return true;
    }

    static bool HandleTicketResetAllCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (sSupportMgr->GetOpenTicketCount<GmTicket>() || sSupportMgr->GetOpenTicketCount<BugTicket>() 
            || sSupportMgr->GetOpenTicketCount<ComplaintTicket>() || sSupportMgr->GetOpenTicketCount<SuggestionTicket>())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETPENDING);
            return true;
        }
        else
        {
            sSupportMgr->ResetTickets<GmTicket>();
            sSupportMgr->ResetTickets<BugTicket>();
            sSupportMgr->ResetTickets<ComplaintTicket>();
            sSupportMgr->ResetTickets<SuggestionTicket>();
            handler->SendSysMessage(LANG_COMMAND_TICKETRESET);
        }
        return true;
    }

    static bool HandleToggleGMTicketSystem(ChatHandler* handler, char const* /*args*/)
    {
        if (!sWorld->getBoolConfig(CONFIG_SUPPORT_TICKETS_ENABLED))
        {
            handler->SendSysMessage(LANG_DISALLOW_TICKETS_CONFIG);
            return true;
        }

        bool status = !sSupportMgr->GetSupportSystemStatus();
        sSupportMgr->SetSupportSystemStatus(status);
        handler->PSendSysMessage(status ? LANG_ALLOW_TICKETS : LANG_DISALLOW_TICKETS);
        return true;
    }

    static bool HandleGMTicketGetByNameCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string name(args);
        if (!normalizePlayerName(name))
            return false;

        // Detect target's GUID
        ObjectGuid guid;
        if (Player* player = ObjectAccessor::FindPlayerByName(name))
            guid = player->GetGUID();
        else
            guid = ObjectMgr::GetPlayerGUIDByName(name);

        // Target must exist
        if (!guid)
        {
            handler->SendSysMessage(LANG_NO_PLAYERS_FOUND);
            return true;
        }

        // Ticket must exist
        GmTicket* ticket = sSupportMgr->GetGmTicketByPlayerGuid(guid);
        if (!ticket)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetViewed();
        ticket->SaveToDB(trans);

        handler->SendSysMessage(ticket->FormatViewMessageString(*handler, true).c_str());
        return true;
    }

    static bool _HandleGMTicketResponseAppendCommand(char const* args, bool newLine, ChatHandler* handler)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* response = strtok(NULL, "\n");
        if (!response)
            return false;

        GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Cannot add response to ticket, assigned to someone else
        //! Console excluded
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->AppendResponse(response);
        if (newLine)
            ticket->AppendResponse("\n");
        ticket->SaveToDB(trans);

        return true;
    }

    static bool HandleGMTicketResponseAppendCommand(ChatHandler* handler, char const* args)
    {
        return _HandleGMTicketResponseAppendCommand(args, false, handler);
    }

    static bool HandleGMTicketResponseAppendLnCommand(ChatHandler* handler, char const* args)
    {
        return _HandleGMTicketResponseAppendCommand(args, true, handler);
    }

    ChatCommand* GetCommands() const override;
};

template<typename T>
bool ticket_commandscript::HandleTicketAssignToCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    char* targetStr = strtok(NULL, " ");
    if (!targetStr)
        return false;

    std::string target(targetStr);
    if (!normalizePlayerName(target))
        return false;

    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    ObjectGuid targetGuid = ObjectMgr::GetPlayerGUIDByName(target);
    uint32 accountId = ObjectMgr::GetPlayerAccountIdByGUID(targetGuid);
    // Target must exist and have administrative rights
    if (!AccountMgr::HasPermission(accountId, rbac::RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET, realmHandle.Index))
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        return true;
    }

    // If already assigned, leave
    if (ticket->IsAssignedTo(targetGuid))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetId());
        return true;
    }

    // If assigned to different player other than current, leave
    //! Console can override though
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId(), target.c_str());
        return true;
    }

    // Assign ticket
    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SetAssignedTo(targetGuid);

    ticket->SaveToDB(trans);

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, target.c_str(), NULL, NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());
    return true;
}

template<>
bool ticket_commandscript::HandleTicketAssignToCommand<GmTicket>(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    char* targetStr = strtok(NULL, " ");
    if (!targetStr)
        return false;

    std::string target(targetStr);
    if (!normalizePlayerName(target))
        return false;

    GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    ObjectGuid targetGuid = ObjectMgr::GetPlayerGUIDByName(target);
    uint32 accountId = ObjectMgr::GetPlayerAccountIdByGUID(targetGuid);
    // Target must exist and have administrative rights
    if (!AccountMgr::HasPermission(accountId, rbac::RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET, realmHandle.Index))
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        return true;
    }

    // If already assigned, leave
    if (ticket->IsAssignedTo(targetGuid))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetId());
        return true;
    }

    // If assigned to different player other than current, leave
    //! Console can override though
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId(), target.c_str());
        return true;
    }

    // Assign ticket
    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SetAssignedTo(targetGuid, AccountMgr::IsAdminAccount(AccountMgr::GetSecurity(accountId, realmHandle.Index)));
    sSupportMgr->UpdateLastChange();

    ticket->SaveToDB(trans);

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, target.c_str(), NULL, NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());
    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketCloseByIdCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Ticket should be assigned to the player who tries to close it.
    // Console can override though
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetId());
        return true;
    }

    ObjectGuid closedByGuid;
    if (player)
        closedByGuid = player->GetGUID();
    else
        closedByGuid.SetRawValue(0, uint64(-1));

    sSupportMgr->CloseTicket<T>(ticket->GetId(), closedByGuid);

    std::string msg = ticket->FormatViewMessageString(*handler, player ? player->GetName().c_str() : "Console", NULL, NULL, NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

    return true;
}

template<>
bool ticket_commandscript::HandleTicketCloseByIdCommand<GmTicket>(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
    if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Ticket should be assigned to the player who tries to close it.
    // Console can override though
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetId());
        return true;
    }

    ObjectGuid closedByGuid;
    if (player)
        closedByGuid = player->GetGUID();
    else
        closedByGuid.SetRawValue(0, uint64(-1));

    std::string msg = ticket->FormatViewMessageString(*handler, player ? player->GetName().c_str() : "Console", NULL, NULL, NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());


    sSupportMgr->CloseTicket<GmTicket>(ticket->GetId(), closedByGuid);
    sSupportMgr->UpdateLastChange();

    // Inform player, who submitted this ticket, that it is closed
    if (Player* submitter = ticket->GetPlayer())
        sSupportMgr->SendGmTicketUpdate(submitter->GetSession(), GMTICKET_RESPONSE_TICKET_DELETED);

    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketCommentCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    char* comment = strtok(NULL, "\n");
    if (!comment)
        return false;

    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Cannot comment ticket assigned to someone else
    //! Console excluded
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    SQLTransaction trans = SQLTransaction(nullptr);
    ticket->SetComment(comment);
    ticket->SaveToDB(trans);
    sSupportMgr->UpdateLastChange();

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, ticket->GetAssignedToName().c_str(), NULL, NULL, NULL);
    msg += handler->PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, player ? player->GetName().c_str() : "Console", comment);
    handler->SendGlobalGMSysMessage(msg.c_str());

    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketListCommand(ChatHandler* handler, char const* /*args*/)
{
    sSupportMgr->ShowList<T>(*handler);
    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketListClosedCommand(ChatHandler* handler, char const* /*args*/)
{
    sSupportMgr->ShowClosedList<T>(*handler);
    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketDeleteByIdCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket)
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (!ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
        return true;
    }

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

    sSupportMgr->RemoveTicket<T>(ticket->GetId());

    return true;
}

template<>
bool ticket_commandscript::HandleTicketDeleteByIdCommand<GmTicket>(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
    if (!ticket)
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (!ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
        return true;
    }

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

    sSupportMgr->RemoveTicket<GmTicket>(ticket->GetId());
    sSupportMgr->UpdateLastChange();

    if (Player* player = ticket->GetPlayer())
        sSupportMgr->SendGmTicketUpdate(player->GetSession(), GMTICKET_RESPONSE_TICKET_DELETED);

    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketResetCommand(ChatHandler* handler, char const* /*args*/)
{
    if (sSupportMgr->GetOpenTicketCount<T>())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETPENDING);
        return true;
    }
    else
    {
        sSupportMgr->ResetTickets<T>();
        handler->SendSysMessage(LANG_COMMAND_TICKETRESET);
    }
    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketUnAssignCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Ticket must be assigned
    if (!ticket->IsAssigned())
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->GetId());
        return true;
    }

    // Get security level of player, whom this ticket is assigned to
    uint32 security = SEC_PLAYER;
    Player* assignedPlayer = ticket->GetAssignedPlayer();
    if (assignedPlayer)
        security = assignedPlayer->GetSession()->GetSecurity();
    else
    {
        ObjectGuid guid = ticket->GetAssignedToGUID();
        uint32 accountId = ObjectMgr::GetPlayerAccountIdByGUID(guid);
        security = AccountMgr::GetSecurity(accountId, realmHandle.Index);
    }

    // Check security
    //! If no m_session present it means we're issuing this command from the console
    uint32 mySecurity = handler->GetSession() ? handler->GetSession()->GetSecurity() : SEC_CONSOLE;
    if (security > mySecurity)
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
        return true;
    }

    std::string assignedTo = ticket->GetAssignedToName(); // copy assignedto name because we need it after the ticket has been unnassigned
    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetUnassigned();
    ticket->SaveToDB(trans);

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, assignedTo.c_str(), handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

    return true;
}

template<>
bool ticket_commandscript::HandleTicketUnAssignCommand<GmTicket>(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    // Ticket must be assigned
    if (!ticket->IsAssigned())
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->GetId());
        return true;
    }

    // Get security level of player, whom this ticket is assigned to
    uint32 security = SEC_PLAYER;
    Player* assignedPlayer = ticket->GetAssignedPlayer();
    if (assignedPlayer)
        security = assignedPlayer->GetSession()->GetSecurity();
    else
    {
        ObjectGuid guid = ticket->GetAssignedToGUID();
        uint32 accountId = ObjectMgr::GetPlayerAccountIdByGUID(guid);
        security = AccountMgr::GetSecurity(accountId, realmHandle.Index);
    }

    // Check security
    //! If no m_session present it means we're issuing this command from the console
    uint32 mySecurity = handler->GetSession() ? handler->GetSession()->GetSecurity() : SEC_CONSOLE;
    if (security > mySecurity)
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
        return true;
    }

    std::string assignedTo = ticket->GetAssignedToName(); // copy assignedto name because we need it after the ticket has been unnassigned
    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetUnassigned();
    ticket->SaveToDB(trans);
    sSupportMgr->UpdateLastChange();

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, assignedTo.c_str(), handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

    return true;
}

template<typename T>
bool ticket_commandscript::HandleTicketGetByIdCommand(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    T* ticket = sSupportMgr->GetTicket<T>(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    handler->SendSysMessage(ticket->FormatViewMessageString(*handler, true).c_str());
    return true;
}

template<>
bool ticket_commandscript::HandleTicketGetByIdCommand<GmTicket>(ChatHandler* handler, char const* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sSupportMgr->GetTicket<GmTicket>(ticketId);
    if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
    {
        handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    SQLTransaction trans = SQLTransaction(NULL);
    ticket->SetViewed();
    ticket->SaveToDB(trans);

    handler->SendSysMessage(ticket->FormatViewMessageString(*handler, true).c_str());
    return true;
}

ChatCommand* ticket_commandscript::GetCommands() const
{
    static ChatCommand ticketBugCommandTable[] =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_BUG_ASSIGN,      true, &HandleTicketAssignToCommand<BugTicket>,      "", NULL },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_BUG_CLOSE,       true, &HandleTicketCloseByIdCommand<BugTicket>,     "", NULL },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_BUG_CLOSEDLIST,  true, &HandleTicketListClosedCommand<BugTicket>,    "", NULL },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_BUG_COMMENT,     true, &HandleTicketCommentCommand<BugTicket>,       "", NULL },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_BUG_DELETE,      true, &HandleTicketDeleteByIdCommand<BugTicket>,    "", NULL },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_BUG_LIST,        true, &HandleTicketListCommand<BugTicket>,          "", NULL },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_BUG_UNASSIGN,    true, &HandleTicketUnAssignCommand<BugTicket>,      "", NULL },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_BUG_VIEW,        true, &HandleTicketGetByIdCommand<BugTicket>,       "", NULL },
        { NULL,         0,                                              false, NULL,                                        "", NULL }
    };
    static ChatCommand ticketComplaintCommandTable[] =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_ASSIGN,        true, &HandleTicketAssignToCommand<ComplaintTicket>,    "", NULL },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_CLOSE,         true, &HandleTicketCloseByIdCommand<ComplaintTicket>,   "", NULL },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_CLOSEDLIST,    true, &HandleTicketListClosedCommand<ComplaintTicket>,  "", NULL },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_COMMENT,       true, &HandleTicketCommentCommand<ComplaintTicket>,     "", NULL },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_DELETE,        true, &HandleTicketDeleteByIdCommand<ComplaintTicket>,  "", NULL },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_LIST,          true, &HandleTicketListCommand<ComplaintTicket>,        "", NULL },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_UNASSIGN,      true, &HandleTicketUnAssignCommand<ComplaintTicket>,    "", NULL },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_VIEW,          true, &HandleTicketGetByIdCommand<ComplaintTicket>,     "", NULL },
        { NULL,         0,                                                      false, NULL,                                            "", NULL }
    };
    static ChatCommand ticketSuggestionCommandTable[] =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_ASSIGN,       true, &HandleTicketAssignToCommand<SuggestionTicket>,   "", NULL },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_CLOSE,        true, &HandleTicketCloseByIdCommand<SuggestionTicket>,  "", NULL },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_CLOSEDLIST,   true, &HandleTicketListClosedCommand<SuggestionTicket>, "", NULL },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_COMMENT,      true, &HandleTicketCommentCommand<SuggestionTicket>,    "", NULL },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_DELETE,       true, &HandleTicketDeleteByIdCommand<SuggestionTicket>, "", NULL },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_LIST,         true, &HandleTicketListCommand<SuggestionTicket>,       "", NULL },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_UNASSIGN,     true, &HandleTicketUnAssignCommand<SuggestionTicket>,   "", NULL },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_VIEW,         true, &HandleTicketGetByIdCommand<SuggestionTicket>,    "", NULL },
        { NULL,         0,                                                      false, NULL,                                            "", NULL }
    };
    static ChatCommand ticketResetCommandTable[] =
    {
        { "all",        rbac::RBAC_PERM_COMMAND_TICKET_RESET_ALL,           true, &HandleTicketResetAllCommand,                 "", NULL },
        { "gm",         rbac::RBAC_PERM_COMMAND_TICKET_RESET_GM,            true, &HandleTicketResetCommand<GmTicket>,          "", NULL },
        { "bug",        rbac::RBAC_PERM_COMMAND_TICKET_RESET_BUG,           true, &HandleTicketResetCommand<BugTicket>,         "", NULL },
        { "complaint",  rbac::RBAC_PERM_COMMAND_TICKET_RESET_COMPLAINT,     true, &HandleTicketResetCommand<ComplaintTicket>,   "", NULL },
        { "suggestion", rbac::RBAC_PERM_COMMAND_TICKET_RESET_SUGGESTION,    true, &HandleTicketResetCommand<SuggestionTicket>,  "", NULL },
        { NULL,         0,                                                  false, NULL,                                        "", NULL }
    };
    static ChatCommand ticketResponseCommandTable[] =
    {
        { "append",     rbac::RBAC_PERM_COMMAND_TICKET_RESPONSE_APPEND,     true, &HandleGMTicketResponseAppendCommand,     "", NULL },
        { "appendln",   rbac::RBAC_PERM_COMMAND_TICKET_RESPONSE_APPENDLN,   true, &HandleGMTicketResponseAppendLnCommand,   "", NULL },
        { NULL,         0,                                                  false, NULL,                                    "", NULL }
    };
    static ChatCommand ticketCommandTable[] =
    {
        { "assign",         rbac::RBAC_PERM_COMMAND_TICKET_ASSIGN,          true, &HandleTicketAssignToCommand<GmTicket>,   "", NULL },
        { "bug",            rbac::RBAC_PERM_COMMAND_TICKET_BUG,             true, NULL, "", ticketBugCommandTable },
        { "close",          rbac::RBAC_PERM_COMMAND_TICKET_CLOSE,           true, &HandleTicketCloseByIdCommand<GmTicket>,  "", NULL },
        { "closedlist",     rbac::RBAC_PERM_COMMAND_TICKET_CLOSEDLIST,      true, &HandleTicketListClosedCommand<GmTicket>, "", NULL },
        { "comment",        rbac::RBAC_PERM_COMMAND_TICKET_COMMENT,         true, &HandleTicketCommentCommand<GmTicket>,    "", NULL },
        { "complaint",      rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT,       true, NULL,              "", ticketComplaintCommandTable },
        { "complete",       rbac::RBAC_PERM_COMMAND_TICKET_COMPLETE,        true, &HandleGMTicketCompleteCommand,           "", NULL },
        { "delete",         rbac::RBAC_PERM_COMMAND_TICKET_DELETE,          true, &HandleTicketDeleteByIdCommand<GmTicket>, "", NULL },
        { "escalate",       rbac::RBAC_PERM_COMMAND_TICKET_ESCALATE,        true, &HandleGMTicketEscalateCommand,           "", NULL },
        { "escalatedlist",  rbac::RBAC_PERM_COMMAND_TICKET_ESCALATEDLIST,   true, &HandleGMTicketListEscalatedCommand,      "", NULL },
        { "list",           rbac::RBAC_PERM_COMMAND_TICKET_LIST,            true, &HandleTicketListCommand<GmTicket>,       "", NULL },
        { "onlinelist",     rbac::RBAC_PERM_COMMAND_TICKET_ONLINELIST,      true, &HandleGMTicketListOnlineCommand,         "", NULL },
        { "reset",          rbac::RBAC_PERM_COMMAND_TICKET_RESET,           true, NULL,                  "", ticketResetCommandTable },
        { "response",       rbac::RBAC_PERM_COMMAND_TICKET_RESPONSE,        true, NULL,               "", ticketResponseCommandTable },
        { "suggestion",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION,      true, NULL,             "", ticketSuggestionCommandTable },
        { "togglesystem",   rbac::RBAC_PERM_COMMAND_TICKET_TOGGLESYSTEM,    true, &HandleToggleGMTicketSystem,              "", NULL },
        { "unassign",       rbac::RBAC_PERM_COMMAND_TICKET_UNASSIGN,        true, &HandleTicketUnAssignCommand<GmTicket>,   "", NULL },
        { "viewid",         rbac::RBAC_PERM_COMMAND_TICKET_VIEWID,          true, &HandleTicketGetByIdCommand<GmTicket>,    "", NULL },
        { "viewname",       rbac::RBAC_PERM_COMMAND_TICKET_VIEWNAME,        true, &HandleGMTicketGetByNameCommand,          "", NULL },
        { NULL,             0,                                              false, NULL,                                    "", NULL }
    };
    static ChatCommand commandTable[] =
    {
        { "ticket", rbac::RBAC_PERM_COMMAND_TICKET, false, NULL, "", ticketCommandTable },
        { NULL, 0, false, NULL, "", NULL }
    };
    return commandTable;
}

void AddSC_ticket_commandscript()
{
    new ticket_commandscript();
}
