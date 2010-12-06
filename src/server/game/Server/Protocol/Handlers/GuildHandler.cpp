/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Guild.h"
#include "GossipDef.h"
#include "SocialMgr.h"

// Helper for getting guild object of session's player.
// If guild does not exist, sends error (if necessary).
inline Guild* _GetPlayerGuild(WorldSession* session, bool sendError = false)
{
    if (uint32 guildId = session->GetPlayer()->GetGuildId())    // If guild id = 0, player is not in guild
        if (Guild* pGuild = sObjectMgr.GetGuildById(guildId))   // Find guild by id
            return pGuild;
    if (sendError)
        Guild::SendCommandResult(session, GUILD_CREATE_S, ERR_GUILD_PLAYER_NOT_IN_GUILD);
    return NULL;
}

void WorldSession::HandleGuildQueryOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_QUERY");

    uint32 guildId;
    recvPacket >> guildId;
    // Use received guild id to access guild method (not player's guild id)
    if (Guild* pGuild = sObjectMgr.GetGuildById(guildId))
        pGuild->HandleQuery(this);
    else
        Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildCreateOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_CREATE");

    std::string name;
    recvPacket >> name;

    if (!GetPlayer()->GetGuildId())             // Player cannot be in guild
    {
        Guild* pGuild = new Guild();
        if (pGuild->Create(GetPlayer(), name))
            sObjectMgr.AddGuild(pGuild);
        else
            delete pGuild;
    }
}

void WorldSession::HandleGuildInviteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_INVITE");

    std::string invitedName;
    recvPacket >> invitedName;

    if (normalizePlayerName(invitedName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleInviteMember(this, invitedName);
}

void WorldSession::HandleGuildRemoveOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_REMOVE");

    std::string playerName;
    recvPacket >> playerName;

    if (normalizePlayerName(playerName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleRemoveMember(this, playerName);
}

void WorldSession::HandleGuildAcceptOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_ACCEPT");
    // Player cannot be in guild
    if (!GetPlayer()->GetGuildId())
        // Guild where player was invited must exist
        if (Guild* pGuild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildIdInvited()))
            pGuild->HandleAcceptMember(this);
}

void WorldSession::HandleGuildDeclineOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DECLINE");

    GetPlayer()->SetGuildIdInvited(0);
    GetPlayer()->SetInGuild(0);
}

void WorldSession::HandleGuildInfoOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_INFO");

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->SendInfo(this);
}

void WorldSession::HandleGuildRosterOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_ROSTER");

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->HandleRoster(this);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_PROMOTE");

    std::string playerName;
    recvPacket >> playerName;

    if (normalizePlayerName(playerName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleUpdateMemberRank(this, playerName, false);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DEMOTE");

    std::string playerName;
    recvPacket >> playerName;

    if (normalizePlayerName(playerName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleUpdateMemberRank(this, playerName, true);
}

void WorldSession::HandleGuildLeaveOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_LEAVE");

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleLeaveMember(this);
}

void WorldSession::HandleGuildDisbandOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DISBAND");

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleDisband(this);
}

void WorldSession::HandleGuildLeaderOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_LEADER");

    std::string name;
    recvPacket >> name;

    if (normalizePlayerName(name))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleSetLeader(this, name);
}

void WorldSession::HandleGuildMOTDOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_MOTD");

    std::string motd;               // Empty by default
    if (!recvPacket.empty())
        recvPacket >> motd;

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleSetMOTD(this, motd);
}

void WorldSession::HandleGuildSetPublicNoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_SET_PUBLIC_NOTE");

    std::string playerName;
    recvPacket >> playerName;

    std::string publicNote;
    recvPacket >> publicNote;

    if (normalizePlayerName(playerName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleSetMemberNote(this, playerName, publicNote, false);
}

void WorldSession::HandleGuildSetOfficerNoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_SET_OFFICER_NOTE");

    std::string playerName;
    recvPacket >> playerName;

    std::string officerNote;
    recvPacket >> officerNote;

    if (normalizePlayerName(playerName))
        if (Guild* pGuild = _GetPlayerGuild(this, true))
            pGuild->HandleSetMemberNote(this, playerName, officerNote, true);
}

void WorldSession::HandleGuildRankOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_RANK");

    Guild* pGuild = _GetPlayerGuild(this, true);
    if (!pGuild)
    {
        recvPacket.rpos(recvPacket.wpos());
        return;
    }

    uint32 rankId;
    recvPacket >> rankId;

    uint32 rights;
    recvPacket >> rights;

    std::string rankName;
    recvPacket >> rankName;

    uint32 money;
    recvPacket >> money;

    GuildBankRightsAndSlotsVec rightsAndSlots(GUILD_BANK_MAX_TABS);
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        uint32 bankRights;
        uint32 slots;

        recvPacket >> bankRights;
        recvPacket >> slots;

        rightsAndSlots[tabId] = GuildBankRightsAndSlots(uint8(bankRights), slots);
    }

    pGuild->HandleSetRankInfo(this, rankId, rankName, rights, money, rightsAndSlots);
}

void WorldSession::HandleGuildAddRankOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_ADD_RANK");

    std::string rankName;
    recvPacket >> rankName;

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleAddNewRank(this, rankName);
}

void WorldSession::HandleGuildDelRankOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DEL_RANK");

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleRemoveLowestRank(this);
}

void WorldSession::HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_INFO_TEXT");

    std::string info;
    recvPacket >> info;

    if (Guild* pGuild = _GetPlayerGuild(this, true))
        pGuild->HandleSetInfo(this, info);
}

void WorldSession::HandleSaveGuildEmblemOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received MSG_SAVE_GUILD_EMBLEM");

    uint64 vendorGuid;
    recvPacket >> vendorGuid;

    EmblemInfo emblemInfo;
    emblemInfo.ReadPacket(recvPacket);

    if (GetPlayer()->GetNPCIfCanInteractWith(vendorGuid, UNIT_NPC_FLAG_TABARDDESIGNER))
    {
        // Remove fake death
        if (GetPlayer()->hasUnitState(UNIT_STAT_DIED))
            GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

        if (Guild* pGuild = _GetPlayerGuild(this))
            pGuild->HandleSetEmblem(this, emblemInfo);
        else
            // "You are not part of a pGuild!";
            Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_NOGUILD);
    }
    else
    {
        // "That's not an emblem vendor!"
        Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_INVALIDVENDOR);
        sLog.outDebug("WORLD: HandleSaveGuildEmblemOpcode - Unit (GUID: %u) not found or you can't interact with him.", GUID_LOPART(vendorGuid));
    }
}

void WorldSession::HandleGuildEventLogQueryOpcode(WorldPacket& /* recvPacket */)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_EVENT_LOG_QUERY)");

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SendEventLog(this);
}

void WorldSession::HandleGuildBankMoneyWithdrawn(WorldPacket & /* recv_data */)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_MONEY_WITHDRAWN)");

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SendMoneyInfo(this);
}

void WorldSession::HandleGuildPermissions(WorldPacket& /* recv_data */)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_PERMISSIONS)");

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SendPermissions(this);
}

// Called when clicking on Guild bank gameobject
void WorldSession::HandleGuildBankerActivate(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANKER_ACTIVATE)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint8 unk;
    recv_data >> unk;

    if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
    {
        if (Guild* pGuild = _GetPlayerGuild(this))
            pGuild->SendBankTabsInfo(this);
        else 
            Guild::SendCommandResult(this, GUILD_UNK1, ERR_GUILD_PLAYER_NOT_IN_GUILD);
    }
}

// Called when opening pGuild bank tab only (first one)
void WorldSession::HandleGuildBankQueryTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_QUERY_TAB)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint8 tabId;
    recv_data >> tabId;

    uint8 unk1;
    recv_data >> unk1;

    if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* pGuild = _GetPlayerGuild(this))
            pGuild->SendBankTabData(this, tabId);
}

void WorldSession::HandleGuildBankDepositMoney(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_DEPOSIT_MONEY)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint32 money;
    recv_data >> money;

    if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (money && GetPlayer()->HasEnoughMoney(money))
            if (Guild* pGuild = _GetPlayerGuild(this))
                pGuild->HandleMemberDepositMoney(this, money);
}

void WorldSession::HandleGuildBankWithdrawMoney(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_WITHDRAW_MONEY)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint32 money;
    recv_data >> money;

    if (money)
        if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
            if (Guild* pGuild = _GetPlayerGuild(this))
                pGuild->HandleMemberWithdrawMoney(this, money);
}

void WorldSession::HandleGuildBankSwapItems(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_SWAP_ITEMS)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
    {
        recv_data.rpos(recv_data.wpos());                   // Prevent additional spam at rejected packet
        return;
    }

    Guild* pGuild = _GetPlayerGuild(this);
    if (!pGuild)
    {
        recv_data.rpos(recv_data.wpos());                   // Prevent additional spam at rejected packet
        return;
    }

    uint8 bankToBank;
    recv_data >> bankToBank;

    uint8 tabId;
    uint8 slotId;
    uint32 itemEntry;
    uint32 splitedAmount = 0;

    if (bankToBank)
    {
        uint8 destTabId;
        recv_data >> destTabId;

        uint8 destSlotId;
        recv_data >> destSlotId;
        recv_data.read_skip<uint32>();                      // Always 0

        recv_data >> tabId;
        recv_data >> slotId;
        recv_data >> itemEntry;
        recv_data.read_skip<uint8>();                       // Always 0

        recv_data >> splitedAmount;

        pGuild->SwapItems(GetPlayer(), tabId, slotId, destTabId, destSlotId, splitedAmount);
    }
    else
    {
        uint8 playerBag = NULL_BAG;
        uint8 playerSlotId = NULL_SLOT;
        uint8 toChar = 1;

        recv_data >> tabId;
        recv_data >> slotId;
        recv_data >> itemEntry;

        uint8 autoStore;
        recv_data >> autoStore;
        if (autoStore)
        {
            recv_data.read_skip<uint32>();                  // autoStoreCount
            recv_data.read_skip<uint8>();                   // ToChar (?), always and expected to be 1 (autostore only triggered in Bank -> Char)
            recv_data.read_skip<uint32>();                  // Always 0
        }
        else
        {
            recv_data >> playerBag;
            recv_data >> playerSlotId;
            recv_data >> toChar;
            recv_data >> splitedAmount;
        }

        // Player <-> Bank
        // Allow to work with inventory only
        if (!Player::IsInventoryPos(playerBag, playerSlotId) && !(playerBag == NULL_BAG && playerSlotId == NULL_SLOT))
            GetPlayer()->SendEquipError(EQUIP_ERR_NONE, NULL);
        else
            pGuild->SwapItemsWithInventory(GetPlayer(), toChar, tabId, slotId, playerBag, playerSlotId, splitedAmount);
    }
}

void WorldSession::HandleGuildBankBuyTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_BUY_TAB)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint8 tabId;
    recv_data >> tabId;

    if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* pGuild = _GetPlayerGuild(this))
            pGuild->HandleBuyBankTab(this, tabId);
}

void WorldSession::HandleGuildBankUpdateTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_UPDATE_TAB)");

    uint64 GoGuid;
    recv_data >> GoGuid;

    uint8 tabId;
    recv_data >> tabId;

    std::string name;
    recv_data >> name;

    std::string icon;
    recv_data >> icon;

    if (!name.empty() && !icon.empty())
        if (GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
            if (Guild* pGuild = _GetPlayerGuild(this))
                pGuild->HandleSetBankTabInfo(this, tabId, name, icon);
}

void WorldSession::HandleGuildBankLogQuery(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_LOG_QUERY)");

    uint8 tabId;
    recv_data >> tabId;

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SendBankLog(this, tabId);
}

void WorldSession::HandleQueryGuildBankTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received MSG_QUERY_GUILD_BANK_TEXT");

    uint8 tabId;
    recv_data >> tabId;

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SendBankTabText(this, tabId);
}

void WorldSession::HandleSetGuildBankTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_SET_GUILD_BANK_TEXT");

    uint8 tabId;
    recv_data >> tabId;

    std::string text;
    recv_data >> text;

    if (Guild* pGuild = _GetPlayerGuild(this))
        pGuild->SetBankTabText(tabId, text);
}
