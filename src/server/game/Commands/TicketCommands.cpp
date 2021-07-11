#include "AccountMgr.h"
#include "Chat.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "GMTicketMgr.h"
#include "World.h"

bool ChatHandler::HandleGMTicketAssignToCommand(char* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    std::string target(GetSession() ? GetSession()->GetPlayerName() : "");
    char* targetStr = strtok(nullptr, " ");
    if (targetStr)
        target = targetStr;
    if (target.empty())
        return false;

    if (!normalizePlayerName(target))
        return false;

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    ObjectGuid targetGuid = sObjectMgr.GetPlayerGuidByName(target);
    uint32 accountId = sObjectMgr.GetPlayerAccountIdByGUID(targetGuid);

    // If already assigned, leave
    if (ticket->IsAssignedTo(targetGuid))
    {
        PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetId());
        return true;
    }

    // If assigned to different player other than current, leave
    //! Console can override though
    Player* player = GetSession() ? GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId(), target.c_str());
        return true;
    }

    // Assign ticket
    ticket->SetAssignedTo(targetGuid, sAccountMgr.GetSecurity(accountId) == sWorld.getConfig(CONFIG_UINT32_GMTICKETS_ADMIN_SECURITY));
    ticket->SaveToDB();
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, nullptr, target.c_str(), nullptr, nullptr, nullptr);
    sWorld.SendGMTicketText(msg.c_str());
    return true;
}

bool ChatHandler::HandleGMTicketCloseByIdCommand(char* args)
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
    if (ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETARCHIVED);
        return true;
    }

    // Ticket should be assigned to the player who tries to close it.
    // Console can override though
    Player* player = GetSession() ? GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetId());
        return true;
    }

    sTicketMgr->CloseTicket(ticket->GetId(), player ? player->GetObjectGuid() : ObjectGuid(uint64(-1)));
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, player ? player->GetName() : "Console", nullptr, nullptr, nullptr, nullptr);
    sWorld.SendGMTicketText(msg.c_str());

    // Inform player, who submitted this ticket, that it is closed
    if (Player* submitter = ticket->GetPlayer())
    {
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
        submitter->GetSession()->SendPacket(&data);
    }
    return true;
}

bool ChatHandler::HandleGMTicketCommentCommand(char* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    char const* comment = strtok(nullptr, "\n");
    if (!comment)
        comment = "";

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Cannot comment ticket assigned to someone else
    //! Console excluded
    Player* player = GetSession() ? GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    ticket->SetComment(comment);
    ticket->SaveToDB();
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, nullptr, ticket->GetAssignedToName().c_str(), nullptr, nullptr, nullptr);
    msg += PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, player ? player->GetName() : "Console", comment);
    sWorld.SendGMTicketText(msg.c_str());

    return true;
}

bool ChatHandler::HandleGMTicketListClosedCommand(char* /*args*/)
{
    sTicketMgr->ShowClosedList(*this);
    return true;
}

bool ChatHandler::HandleGMTicketCompleteCommand(char* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    if (ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETARCHIVED);
        return true;
    }

    char* response = strtok(nullptr, "\n");
    if (response)
    {
        // Cannot add response to ticket, assigned to someone else
        //! Console excluded
        Player* player = GetSession() ? GetSession()->GetPlayer() : nullptr;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
            return true;
        }

        ticket->AppendResponse(response);
    }


    ticket->SetCompleted();
    if (GetSession() && GetSession()->GetPlayer() && !ticket->GetAssignedToGUID())
        ticket->SetAssignedTo(GetSession()->GetPlayer()->GetObjectGuid(), true);
    ticket->SaveToDB();

    if (Player* player = ticket->GetPlayer())
        ticket->SendResponse(player->GetSession());

    std::string msg = ticket->FormatMessageString(*this, nullptr, nullptr,
        nullptr, nullptr, GetSession() ? GetSession()->GetPlayer()->GetName() : "Console");
    sWorld.SendGMTicketText(msg.c_str());
    sTicketMgr->UpdateLastChange();
    return true;
}

bool ChatHandler::HandleGMTicketDeleteByIdCommand(char* args)
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

    std::string msg = ticket->FormatMessageString(*this, nullptr, nullptr, nullptr, GetSession() ? GetSession()->GetPlayer()->GetName() : "Console", nullptr);
    sWorld.SendGMTicketText(msg.c_str());

    sTicketMgr->RemoveTicket(ticket->GetId());
    sTicketMgr->UpdateLastChange();

    if (Player* player = ticket->GetPlayer())
    {
        // Force abandon ticket
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
        player->GetSession()->SendPacket(&data);
    }

    return true;
}

bool ChatHandler::HandleGMTicketEscalateCommand(char* args)
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
    if (ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETARCHIVED);
        return true;
    }
    if (ticket->GetEscalatedStatus() != TICKET_UNASSIGNED)
    {
        SendSysMessage(LANG_COMMAND_TICKETASSIGNED);
        return true;
    }

    ticket->SetEscalatedStatus(TICKET_IN_ESCALATION_QUEUE);
    ticket->SetNeededSecurityLevel(GetSession()->GetSecurity() + 1);

    if (Player* player = ticket->GetPlayer())
        sTicketMgr->SendTicket(player->GetSession(), ticket);

    sTicketMgr->UpdateLastChange();
    PSendSysMessage(LANG_COMMAND_TICKETESCALATED, ticketId);
    return true;
}

bool ChatHandler::HandleGMTicketListEscalatedCommand(char* /*args*/)
{
    sTicketMgr->ShowEscalatedList(*this);
    return true;
}

bool ChatHandler::HandleGMTicketListCommand(char* args)
{
    static std::unordered_map<std::string, uint8> const categories
    {
        { "stuck", 1 },{ "behavior", 2 },{ "harassment", 2 },{ "guild", 3 },
        { "item", 4 },{ "environment", 5 },{ "world", 5 },{ "npc", 6 },
        { "creature", 6 },{ "creep", 6 },{ "quest", 7 },{ "questnpc", 7 },
        { "technical", 8 },{ "account", 9 },{ "billing", 9 },{ "character", 10 }
    };

    auto it = categories.find(args);

    if (it == categories.end())
        sTicketMgr->ShowList(*this, false);
    else
        sTicketMgr->ShowList(*this, false, it->second);

    return true;
}

bool ChatHandler::HandleGMTicketListOnlineCommand(char* args)
{
    static std::unordered_map<std::string, uint8> const categories
    {
        { "stuck", 1 },{ "behavior", 2 },{ "harassment", 2 },{ "guild", 3 },
        { "item", 4 },{ "environment", 5 },{ "world", 5 },{ "npc", 6 },
        { "creature", 6 },{ "creep", 6 },{ "quest", 7 },{ "questnpc", 7 },
        { "technical", 8 },{ "account", 9 },{ "billing", 9 },{ "character", 10 }
    };

    auto it = categories.find(args);

    if (it == categories.end())
        sTicketMgr->ShowList(*this, true);
    else
        sTicketMgr->ShowList(*this, true, it->second);

    return true;
}

bool ChatHandler::HandleGMTicketResetCommand(char* /*args*/)
{
    if (sTicketMgr->GetOpenTicketCount())
    {
        SendSysMessage(LANG_COMMAND_TICKETPENDING);
        return true;
    }
    else
    {
        sTicketMgr->ResetTickets();
        SendSysMessage(LANG_COMMAND_TICKETRESET);
    }

    return true;
}

bool ChatHandler::HandleToggleGMTicketSystem(char* /*args*/)
{
    bool status = !sTicketMgr->GetStatus();
    sTicketMgr->SetStatus(status);
    PSendSysMessage(status ? LANG_ALLOW_TICKETS : LANG_DISALLOW_TICKETS);
    return true;
}

bool ChatHandler::HandleGMTicketUnAssignCommand(char* args)
{
    if (!*args)
        return false;

    uint32 ticketId = atoi(args);
    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
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
    if (assignedPlayer)
        security = assignedPlayer->GetSession()->GetSecurity();
    else
    {
        ObjectGuid guid = ticket->GetAssignedToGUID();
        uint32 accountId = sObjectMgr.GetPlayerAccountIdByGUID(guid);
        security = sAccountMgr.GetSecurity(accountId);
    }

    // Check security
    //! If no m_session present it means we're issuing this command from the console
    uint32 mySecurity = GetSession() ? GetSession()->GetSecurity() : SEC_CONSOLE;
    if (security > mySecurity)
    {
        SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
        return true;
    }

    std::string assignedTo = ticket->GetAssignedToName(); // copy assignedto name because we need it after the ticket has been unnassigned
    ticket->SetUnassigned();
    ticket->SaveToDB();
    sTicketMgr->UpdateLastChange();

    std::string msg = ticket->FormatMessageString(*this, nullptr, assignedTo.c_str(),
        GetSession() ? GetSession()->GetPlayer()->GetName() : "Console", nullptr, nullptr);
    sWorld.SendGMTicketText(msg.c_str());

    return true;
}

bool ChatHandler::ViewTicketByIdOrName(char* ticketId_c, char* name_c)
{
    GmTicket* ticket = nullptr;

    // By ticket id
    if (ticketId_c && *ticketId_c)
    {
        uint32 ticketId = atoi(ticketId_c);
        ticket = sTicketMgr->GetTicket(ticketId);
    }

    // By player name
    if (!ticket && name_c && *name_c)
    {
        std::string name(name_c);
        if (!normalizePlayerName(name))
            return false;

        // Detect target's GUID
        ObjectGuid guid;
        if (Player* player = ObjectAccessor::FindPlayerByName(name.c_str()))
            guid = player->GetGUID();
        else
            guid = sObjectMgr.GetPlayerGuidByName(name);

        // Target must exist
        if (!guid)
        {
            SendSysMessage(LANG_NO_PLAYERS_FOUND);
            return true;
        }
        ticket = sTicketMgr->GetTicketByPlayer(guid);
    }

    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    if (ticket->IsClosed() || ticket->IsCompleted())
    {
        SendSysMessage(LANG_COMMAND_TICKETARCHIVED);
        return true;
    }
    return ViewTicket(ticket);
}

bool ChatHandler::ViewTicket(GmTicket* ticket)
{
    ticket->SetViewed();
    if (Player* player = ticket->GetPlayer()) // Inform that ticket has been viewed
        sTicketMgr->SendTicket(player->GetSession(), ticket);
    ticket->SaveToDB();

    SendSysMessage(ticket->FormatMessageString(*this, true).c_str());
    return true;
}

bool ChatHandler::HandleGMTicketGetByIdOrNameCommand(char* args)
{
    return ViewTicketByIdOrName(args, args);
}

bool ChatHandler::HandleGMTicketGetByIdCommand(char* args)
{
    return ViewTicketByIdOrName(args, nullptr);
}

bool ChatHandler::HandleGMTicketGetByNameCommand(char* args)
{
    return ViewTicketByIdOrName(nullptr, args);
}

bool ChatHandler::HandleGMTicketResponseResetCommand(char* args)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Cannot add response to ticket, assigned to someone else
    //! Console excluded
    Player* player = GetSession() ? GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    ticket->ResetResponse();
    ticket->SaveToDB();
    PSendSysMessage(LANG_COMMAND_TICKET_RESPONSE_RESET, ticket->FormatMessageString(*this).c_str());
    return true;
}

bool _HandleGMTicketResponseAppendCommand(char* args, bool newLine, ChatHandler* handler)
{
    if (!*args)
        return false;

    char* ticketIdStr = strtok((char*)args, " ");
    uint32 ticketId = atoi(ticketIdStr);

    char* response = strtok(nullptr, "\n");
    if (!response)
        return false;

    GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
    if (!ticket || ticket->IsClosed())
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    // Cannot add response to ticket, assigned to someone else
    //! Console excluded
    Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr;
    if (player && ticket->IsAssignedNotTo(player->GetGUID()))
    {
        handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetId());
        return true;
    }

    ticket->AppendResponse(response);
    if (newLine)
        ticket->AppendResponse("\n");
    ticket->SaveToDB();

    return true;
}

bool ChatHandler::HandleGMTicketResponseAppendCommand(char* args)
{
    return _HandleGMTicketResponseAppendCommand(args, false, this);
}

bool ChatHandler::HandleGMTicketResponseAppendLnCommand(char* args)
{
    return _HandleGMTicketResponseAppendCommand(args, true, this);
}

bool ChatHandler::HandleGMTicketNotifyCommand(char* args)
{
    bool status = false;
    if (!ExtractOnOff(&args, status))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }
    if (status)
        SendSysMessage(LANG_GMTICKET_NOTIFY_ENABLED);
    else
        SendSysMessage(LANG_GMTICKET_NOTIFY_DISABLED);
    GetSession()->GetPlayer()->SetAcceptTicket(status);
    return true;
}

bool ChatHandler::HandleGMTicketCounterCommand(char* args)
{
    uint32 counter = 0;
    if (!ExtractUInt32(&args, counter))
        return false;
    if (counter > sTicketMgr->GetLastTicketId())
        counter = sTicketMgr->GetLastTicketId();
    GetSession()->GetPlayer()->SetGMTicketCounter(counter);
    PSendSysMessage(LANG_GMTICKET_COUNTER_SET, counter);
    return true;
}

bool ChatHandler::HandleGMTicketNextCommand(char* args)
{
    GmTicket* ticket = sTicketMgr->GetNextTicket(GetSession()->GetPlayer()->GetGMTicketCounter());
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    GetSession()->GetPlayer()->SetGMTicketCounter(ticket->GetId());
    ViewTicket(ticket);
    return true;
}

bool ChatHandler::HandleGMTicketPreviousCommand(char* args)
{
    GmTicket* ticket = sTicketMgr->GetPreviousTicket(GetSession()->GetPlayer()->GetGMTicketCounter());
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }
    GetSession()->GetPlayer()->SetGMTicketCounter(ticket->GetId());
    ViewTicket(ticket);
    return true;
}

bool ChatHandler::HandleGMTicketReloadCommand(char* args)
{
    uint32 ticketId = 0;
    if (!ExtractUInt32(&args, ticketId))
        return false;
    sTicketMgr->ReloadTicket(ticketId);
    PSendSysMessage("Ticket #%u added to reload list.", ticketId);
    return true;
}
