/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Realm.h"
#include "ScriptMgr.h"
#include "SupportMgr.h"
#include "World.h"
#include "WorldSession.h"

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

    static bool HandleTicketResetAllCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (sSupportMgr->GetOpenTicketCount<BugTicket>() || sSupportMgr->GetOpenTicketCount<ComplaintTicket>() || sSupportMgr->GetOpenTicketCount<SuggestionTicket>())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETPENDING);
            return true;
        }
        else
        {
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

    static bool AddonHandleGMTicketCreate(ChatHandler* handler, char const* args)
    {
        auto replaceAll = [](std::string& str, const std::string& from, const std::string& to) {
            if (from.empty())
                return;
            size_t start_pos = 0;
            while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
                str.replace(start_pos, from.length(), to);
                start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            }
        };

        // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
        if (sSupportMgr->GetSupportSystemStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
            return true;

        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return true;

        std::string message = args;
        replaceAll(message, "$$n", "\n");

        GMTicketResponse response = GMTICKET_RESPONSE_CREATE_ERROR;
        // Player must not have opened ticket
        if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
        {
            if (!ticket->IsClosed())
                response = GMTICKET_RESPONSE_ALREADY_EXIST;

            sSupportMgr->CloseTicket<SuggestionTicket>(ticket->GetId(), player->GetGUID());
        }

        SuggestionTicket* ticket = new SuggestionTicket(player);
        ticket->SetPosition(player->GetMapId(), player->GetPosition());
        ticket->SetFacing(player->GetOrientation());
        ticket->SetNote(message);
        sSupportMgr->AddTicket(ticket);

        sWorld->SendGMText(LANG_COMMAND_TICKETNEW, player->GetName().c_str(), ticket->GetId());

        //sSupportMgr->SendTicket(handler->GetSession(), newTicket);
        response = GMTICKET_RESPONSE_CREATE_SUCCESS;

        handler->GetSession()->SendTicketStatusUpdate(response);
        return true;
    }

    static bool AddonHandleGMTicketUpdate(ChatHandler* handler, char const* args)
    {
        auto replaceAll = [](std::string& str, const std::string& from, const std::string& to) {
            if (from.empty())
                return;
            size_t start_pos = 0;
            while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
                str.replace(start_pos, from.length(), to);
                start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            }
        };

        // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
        if (sSupportMgr->GetSupportSystemStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
            return true;

        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return true;

        std::string message = args;
        replaceAll(message, "$$n", "\n");

        GMTicketResponse response = GMTICKET_RESPONSE_UPDATE_ERROR;
        if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
        {
            ticket->SetNote(message);
            ticket->SaveToDB();

            sWorld->SendGMText(LANG_COMMAND_TICKETUPDATED, player->GetName().c_str(), ticket->GetId());

            sSupportMgr->SendTicket(handler->GetSession(), ticket);
            response = GMTICKET_RESPONSE_UPDATE_SUCCESS;
        }

        handler->GetSession()->SendTicketStatusUpdate(response);

        return true;
    }

    static bool AddonHandleGMTicketAppend(ChatHandler* handler, char const* args)
    {
        auto replaceAll = [](std::string& str, const std::string& from, const std::string& to) {
            if (from.empty())
                return;
            size_t start_pos = 0;
            while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
                str.replace(start_pos, from.length(), to);
                start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            }
        };

        // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
        if (sSupportMgr->GetSupportSystemStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
            return true;

        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return true;

        std::string message = args;
        replaceAll(message, "$$n", "\n");

        GMTicketResponse response = GMTICKET_RESPONSE_UPDATE_ERROR;
        if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
        {
            ticket->SetNote(ticket->GetNote() + message);
            ticket->SaveToDB();
        }

        handler->GetSession()->SendTicketStatusUpdate(response);

        return true;
    }

    static bool AddonHandleGMTicketEnd(ChatHandler* handler, char const* /*args*/)
    {
        // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
        if (sSupportMgr->GetSupportSystemStatus() == GMTICKET_QUEUE_STATUS_DISABLED)
            return true;

        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return true;

        if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
            sSupportMgr->SendTicket(handler->GetSession(), ticket);

        return true;
    }

    static bool AddonHandleGMTicketDelete(ChatHandler* handler, char const* /*args*/)
    {
        if (Player* player = handler->GetSession()->GetPlayer())
        {
            if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
            {
                handler->GetSession()->SendTicketStatusUpdate(GMTICKET_RESPONSE_TICKET_DELETED);

                sWorld->SendGMText(LANG_COMMAND_TICKETPLAYERABANDON, player->GetName().c_str(), ticket->GetId());

                sSupportMgr->CloseTicket<SuggestionTicket>(ticket->GetId(), player->GetGUID());
                sSupportMgr->SendTicket(handler->GetSession(), nullptr);
            }
        }

        return true;
    }

    static bool AddonHandleGMTicketGet(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return true;

        handler->GetSession()->OnGMTicketGetTicketEvent();

        return true;
    }

    static bool AddonHandleGMResponseResolve(ChatHandler* handler, char const* /*args*/)
    {
        if (Player* player = handler->GetSession()->GetPlayer())
        {
            if (SuggestionTicket* ticket = sSupportMgr->GetOpenSuggestionByPlayerGuid(player->GetGUID()))
            {
                handler->GetSession()->SendTicketStatusUpdate(GMTICKET_RESPONSE_TICKET_DELETED);

                ObjectGuid closedByGuid;
                if (player)
                    closedByGuid = player->GetGUID();
                else
                    closedByGuid.SetRawValue(0, uint64(-1));

                sSupportMgr->CloseTicket<SuggestionTicket>(ticket->GetId(), closedByGuid);
                sSupportMgr->SendTicket(handler->GetSession(), NULL);
            }
        }

        return true;
    }

    std::vector<ChatCommand> GetCommands() const override;
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
    if (!AccountMgr::HasPermission(accountId, rbac::RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET, realm.Id.Realm))
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
        handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    // Assign ticket
    ticket->SetAssignedTo(targetGuid);

    ticket->SaveToDB();

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, target.c_str(), NULL, NULL);
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

    std::string msg = ticket->FormatViewMessageString(*handler, player ? player->GetName().c_str() : "Console", NULL, NULL, NULL);
    handler->SendGlobalGMSysMessage(msg.c_str());

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

    ticket->SetComment(comment);
    ticket->SaveToDB();
    sSupportMgr->UpdateLastChange();

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, ticket->GetAssignedToName().c_str(), NULL, NULL);
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

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console");
    handler->SendGlobalGMSysMessage(msg.c_str());

    sSupportMgr->RemoveTicket<T>(ticket->GetId());

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
        security = AccountMgr::GetSecurity(accountId, realm.Id.Realm);
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
    ticket->SetUnassigned();
    ticket->SaveToDB();

    std::string msg = ticket->FormatViewMessageString(*handler, NULL, assignedTo.c_str(), handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL);
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

std::vector<ChatCommand> ticket_commandscript::GetCommands() const
{
    static std::vector<ChatCommand> ticketBugCommandTable =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_BUG_ASSIGN,      true, &HandleTicketAssignToCommand<BugTicket>,      "" },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_BUG_CLOSE,       true, &HandleTicketCloseByIdCommand<BugTicket>,     "" },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_BUG_CLOSEDLIST,  true, &HandleTicketListClosedCommand<BugTicket>,    "" },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_BUG_COMMENT,     true, &HandleTicketCommentCommand<BugTicket>,       "" },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_BUG_DELETE,      true, &HandleTicketDeleteByIdCommand<BugTicket>,    "" },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_BUG_LIST,        true, &HandleTicketListCommand<BugTicket>,          "" },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_BUG_UNASSIGN,    true, &HandleTicketUnAssignCommand<BugTicket>,      "" },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_BUG_VIEW,        true, &HandleTicketGetByIdCommand<BugTicket>,       "" },
    };
    static std::vector<ChatCommand> ticketComplaintCommandTable =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_ASSIGN,        true, &HandleTicketAssignToCommand<ComplaintTicket>,    "" },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_CLOSE,         true, &HandleTicketCloseByIdCommand<ComplaintTicket>,   "" },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_CLOSEDLIST,    true, &HandleTicketListClosedCommand<ComplaintTicket>,  "" },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_COMMENT,       true, &HandleTicketCommentCommand<ComplaintTicket>,     "" },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_DELETE,        true, &HandleTicketDeleteByIdCommand<ComplaintTicket>,  "" },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_LIST,          true, &HandleTicketListCommand<ComplaintTicket>,        "" },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_UNASSIGN,      true, &HandleTicketUnAssignCommand<ComplaintTicket>,    "" },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT_VIEW,          true, &HandleTicketGetByIdCommand<ComplaintTicket>,     "" },
    };
    static std::vector<ChatCommand> ticketSuggestionCommandTable =
    {
        { "assign",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_ASSIGN,       true, &HandleTicketAssignToCommand<SuggestionTicket>,   "" },
        { "close",      rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_CLOSE,        true, &HandleTicketCloseByIdCommand<SuggestionTicket>,  "" },
        { "closedlist", rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_CLOSEDLIST,   true, &HandleTicketListClosedCommand<SuggestionTicket>, "" },
        { "comment",    rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_COMMENT,      true, &HandleTicketCommentCommand<SuggestionTicket>,    "" },
        { "delete",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_DELETE,       true, &HandleTicketDeleteByIdCommand<SuggestionTicket>, "" },
        { "list",       rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_LIST,         true, &HandleTicketListCommand<SuggestionTicket>,       "" },
        { "unassign",   rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_UNASSIGN,     true, &HandleTicketUnAssignCommand<SuggestionTicket>,   "" },
        { "view",       rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION_VIEW,         true, &HandleTicketGetByIdCommand<SuggestionTicket>,    "" },
    };
    static std::vector<ChatCommand> ticketResetCommandTable =
    {
        { "all",        rbac::RBAC_PERM_COMMAND_TICKET_RESET_ALL,           true, &HandleTicketResetAllCommand,                 "" },
        { "bug",        rbac::RBAC_PERM_COMMAND_TICKET_RESET_BUG,           true, &HandleTicketResetCommand<BugTicket>,         "" },
        { "complaint",  rbac::RBAC_PERM_COMMAND_TICKET_RESET_COMPLAINT,     true, &HandleTicketResetCommand<ComplaintTicket>,   "" },
        { "suggestion", rbac::RBAC_PERM_COMMAND_TICKET_RESET_SUGGESTION,    true, &HandleTicketResetCommand<SuggestionTicket>,  "" },
    };

    static std::vector<ChatCommand> ticketAddonCommandTable =
    {
        { "create",      rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketCreate,                "" },
        { "update",      rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketUpdate,                "" },
        { "append",      rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketAppend,                "" },
        { "end",         rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketEnd,                   "" },
        { "delete",      rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketDelete,                "" },
        { "ticketget",   rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMTicketGet,                   "" },
        { "ticketres",   rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  &AddonHandleGMResponseResolve,             "" }
    };

    static std::vector<ChatCommand> ticketCommandTable =
    {
        { "bug",            rbac::RBAC_PERM_COMMAND_TICKET_BUG,             true,   nullptr,    "", ticketBugCommandTable           },
        { "complaint",      rbac::RBAC_PERM_COMMAND_TICKET_COMPLAINT,       true,   nullptr,    "", ticketComplaintCommandTable     },
        { "reset",          rbac::RBAC_PERM_COMMAND_TICKET_RESET,           true,   nullptr,    "", ticketResetCommandTable         },
        { "suggestion",     rbac::RBAC_PERM_COMMAND_TICKET_SUGGESTION,      true,   nullptr,    "", ticketSuggestionCommandTable    },
        { "addon",          rbac::RBAC_PERM_COMMAND_TICKET_ADDON,           false,  nullptr,    "", ticketAddonCommandTable         },
        { "togglesystem",   rbac::RBAC_PERM_COMMAND_TICKET_TOGGLESYSTEM,    true, &HandleToggleGMTicketSystem,                   "" },
    };
    static std::vector<ChatCommand> commandTable =
    {
        { "ticket", rbac::RBAC_PERM_COMMAND_TICKET, false, NULL, "", ticketCommandTable },
    };
    return commandTable;
}

void AddSC_ticket_commandscript()
{
    new ticket_commandscript();
}
