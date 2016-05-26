/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "GuildMgr.h"
#include "Log.h"
#include "Guild.h"

void WorldSession::HandleGuildQueryOpcode(WorldPacket& recvPacket)
{
    uint32 guildId;
    recvPacket >> guildId;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY [%s]: Guild: %u", GetPlayerInfo().c_str(), guildId);
    if (!guildId)
        return;

    if (Guild* guild = sGuildMgr->GetGuildById(guildId))
        guild->HandleQuery(this);
}

void WorldSession::HandleGuildCreateOpcode(WorldPacket& recvPacket)
{
    std::string name;
    recvPacket >> name;

    TC_LOG_ERROR("guild", "CMSG_GUILD_CREATE: Possible hacking-attempt: %s tried to create a guild [Name: %s] using cheats", GetPlayerInfo().c_str(), name.c_str());
}

void WorldSession::HandleGuildInviteOpcode(WorldPacket& recvPacket)
{
    std::string invitedName;
    recvPacket >> invitedName;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_INVITE [%s]: Invited: %s", GetPlayerInfo().c_str(), invitedName.c_str());
    if (normalizePlayerName(invitedName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleInviteMember(this, invitedName);
}

void WorldSession::HandleGuildRemoveOpcode(WorldPacket& recvPacket)
{
    std::string playerName;
    recvPacket >> playerName;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_REMOVE [%s]: Target: %s", GetPlayerInfo().c_str(), playerName.c_str());

    if (normalizePlayerName(playerName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleRemoveMember(this, playerName);
}

void WorldSession::HandleGuildAcceptOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ACCEPT [%s]", GetPlayer()->GetName().c_str());

    if (!GetPlayer()->GetGuildId())
        if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildIdInvited()))
            guild->HandleAcceptMember(this);
}

void WorldSession::HandleGuildDeclineOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DECLINE [%s]", GetPlayerInfo().c_str());

    GetPlayer()->SetGuildIdInvited(0);
    GetPlayer()->SetInGuild(0);
}

void WorldSession::HandleGuildInfoOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_INFO [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendInfo(this);
}

void WorldSession::HandleGuildRosterOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ROSTER [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRoster(this);
    else
        Guild::SendCommandResult(this, GUILD_COMMAND_ROSTER, ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPacket& recvPacket)
{
    std::string playerName;
    recvPacket >> playerName;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_PROMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), playerName.c_str());

    if (normalizePlayerName(playerName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleUpdateMemberRank(this, playerName, false);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPacket& recvPacket)
{
    std::string playerName;
    recvPacket >> playerName;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), playerName.c_str());

    if (normalizePlayerName(playerName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleUpdateMemberRank(this, playerName, true);
}

void WorldSession::HandleGuildLeaveOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_LEAVE [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleLeaveMember(this);
}

void WorldSession::HandleGuildDisbandOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DISBAND [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleDisband(this);
}

void WorldSession::HandleGuildLeaderOpcode(WorldPacket& recvPacket)
{
    std::string name;
    recvPacket >> name;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_LEADER [%s]: Target: %s", GetPlayerInfo().c_str(), name.c_str());

    if (normalizePlayerName(name))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetLeader(this, name);
}

void WorldSession::HandleGuildMOTDOpcode(WorldPacket& recvPacket)
{
    std::string motd;
    recvPacket >> motd;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_MOTD [%s]: MOTD: %s", GetPlayerInfo().c_str(), motd.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMOTD(this, motd);
}

void WorldSession::HandleGuildSetPublicNoteOpcode(WorldPacket& recvPacket)
{
    std::string playerName;
    std::string note;
    recvPacket >> playerName >> note;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_PUBLIC_NOTE [%s]: Target: %s, Note: %s",
         GetPlayerInfo().c_str(), playerName.c_str(), note.c_str());

    if (normalizePlayerName(playerName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetMemberNote(this, playerName, note, true);
}

void WorldSession::HandleGuildSetOfficerNoteOpcode(WorldPacket& recvPacket)
{
    std::string playerName;
    std::string note;
    recvPacket >> playerName >> note;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_OFFICER_NOTE [%s]: Target: %s, Note: %s",
         GetPlayerInfo().c_str(), playerName.c_str(), note.c_str());

    if (normalizePlayerName(playerName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetMemberNote(this, playerName, note, false);
}

void WorldSession::HandleGuildRankOpcode(WorldPacket& recvPacket)
{
    uint32 rankId;
    recvPacket >> rankId;

    uint32 rights;
    recvPacket >> rights;

    std::string rankName;
    recvPacket >> rankName;

    uint32 money;
    recvPacket >> money;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_RANK [%s]: Rank: %s (%u)", GetPlayerInfo().c_str(), rankName.c_str(), rankId);

    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        recvPacket.rpos(recvPacket.wpos());
        return;
    }

    GuildBankRightsAndSlotsVec rightsAndSlots(GUILD_BANK_MAX_TABS);

    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        uint32 bankRights;
        uint32 slots;

        recvPacket >> bankRights;
        recvPacket >> slots;

        rightsAndSlots[tabId] = GuildBankRightsAndSlots(tabId, bankRights, slots);
    }

    guild->HandleSetRankInfo(this, rankId, rankName, rights, money, rightsAndSlots);
}

void WorldSession::HandleGuildAddRankOpcode(WorldPacket& recvPacket)
{
    std::string rankName;
    recvPacket >> rankName;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_ADD_RANK [%s]: Rank: %s", GetPlayerInfo().c_str(), rankName.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleAddNewRank(this, rankName);
}

void WorldSession::HandleGuildDelRankOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEL_RANK [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveLowestRank(this);
}

void WorldSession::HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket)
{
    std::string info;
    recvPacket >> info;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_INFO_TEXT [%s]: %s", GetPlayerInfo().c_str(), info.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetInfo(this, info);
}

void WorldSession::HandleSaveGuildEmblemOpcode(WorldPacket& recvPacket)
{
    ObjectGuid vendorGuid;
    recvPacket >> vendorGuid;

    EmblemInfo emblemInfo;
    emblemInfo.ReadPacket(recvPacket);

    TC_LOG_DEBUG("guild", "MSG_SAVE_GUILD_EMBLEM [%s]: Guid: [%s] Style: %d, Color: %d, BorderStyle: %d, BorderColor: %d, BackgroundColor: %d"
        , GetPlayerInfo().c_str(), vendorGuid.ToString().c_str(), emblemInfo.GetStyle()
        , emblemInfo.GetColor(), emblemInfo.GetBorderStyle()
        , emblemInfo.GetBorderColor(), emblemInfo.GetBackgroundColor());

    if (GetPlayer()->GetNPCIfCanInteractWith(vendorGuid, UNIT_NPC_FLAG_TABARDDESIGNER))
    {
        // Remove fake death
        if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
            GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetEmblem(this, emblemInfo);
        else
            Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_NOGUILD); // "You are not part of a guild!";
    }
    else
        Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_INVALIDVENDOR); // "That's not an emblem vendor!"
}

void WorldSession::HandleGuildEventLogQueryOpcode(WorldPacket& /* recvPacket */)
{
    TC_LOG_DEBUG("guild", "MSG_GUILD_EVENT_LOG_QUERY [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendEventLog(this);
}

void WorldSession::HandleGuildBankMoneyWithdrawn(WorldPacket & /* recvData */)
{
    TC_LOG_DEBUG("guild", "MSG_GUILD_BANK_MONEY_WITHDRAWN [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendMoneyInfo(this);
}

void WorldSession::HandleGuildPermissions(WorldPacket& /* recvData */)
{
    TC_LOG_DEBUG("guild", "MSG_GUILD_PERMISSIONS [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendPermissions(this);
}

// Called when clicking on Guild bank gameobject
void WorldSession::HandleGuildBankerActivate(WorldPacket& recvData)
{
    ObjectGuid guid;
    bool sendAllSlots;
    recvData >> guid >> sendAllSlots;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANKER_ACTIVATE [%s]: [%s] AllSlots: %u"
        , GetPlayerInfo().c_str(), guid.ToString().c_str(), sendAllSlots);

    Guild* const guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_VIEW_TAB, ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    guild->SendBankTabsInfo(this, sendAllSlots);
}

// Called when opening guild bank tab only (first one)
void WorldSession::HandleGuildBankQueryTab(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint8 tabId;
    bool full;

    recvData >> guid >> tabId >> full;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_QUERY_TAB [%s]: %s, TabId: %u, ShowTabs: %u"
        , GetPlayerInfo().c_str(), guid.ToString().c_str(), tabId, full);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->SendBankTabData(this, tabId);
}

void WorldSession::HandleGuildBankDepositMoney(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint32 money;
    recvData >> guid >> money;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_DEPOSIT_MONEY [%s]: [%s], money: %u",
        GetPlayerInfo().c_str(), guid.ToString().c_str(), money);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (money && GetPlayer()->HasEnoughMoney(money))
            if (Guild* guild = GetPlayer()->GetGuild())
                guild->HandleMemberDepositMoney(this, money);
}

void WorldSession::HandleGuildBankWithdrawMoney(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint32 money;
    recvData >> guid >> money;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_WITHDRAW_MONEY [%s]: [%s], money: %u",
        GetPlayerInfo().c_str(), guid.ToString().c_str(), money);

    if (money && GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleMemberWithdrawMoney(this, money);
}

void WorldSession::HandleGuildBankSwapItems(WorldPacket& recvData)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_SWAP_ITEMS [%s]", GetPlayerInfo().c_str());

    ObjectGuid GoGuid;
    recvData >> GoGuid;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
    {
        recvData.rfinish();                   // Prevent additional spam at rejected packet
        return;
    }

    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        recvData.rfinish();                   // Prevent additional spam at rejected packet
        return;
    }

    uint8 bankToBank;
    recvData >> bankToBank;

    uint8 tabId;
    uint8 slotId;
    uint32 itemEntry;
    uint32 splitedAmount = 0;

    if (bankToBank)
    {
        uint8 destTabId;
        recvData >> destTabId;

        uint8 destSlotId;
        recvData >> destSlotId;
        recvData.read_skip<uint32>();                      // Always 0

        recvData >> tabId;
        recvData >> slotId;
        recvData >> itemEntry;
        recvData.read_skip<uint8>();                       // Always 0

        recvData >> splitedAmount;

        guild->SwapItems(GetPlayer(), tabId, slotId, destTabId, destSlotId, splitedAmount);
    }
    else
    {
        uint8 playerBag = NULL_BAG;
        uint8 playerSlotId = NULL_SLOT;
        uint8 toChar = 1;

        recvData >> tabId;
        recvData >> slotId;
        recvData >> itemEntry;

        uint8 autoStore;
        recvData >> autoStore;
        if (autoStore)
        {
            recvData.read_skip<uint32>();                  // autoStoreCount
            recvData.read_skip<uint8>();                   // ToChar (?), always and expected to be 1 (autostore only triggered in Bank -> Char)
            recvData.read_skip<uint32>();                  // Always 0
        }
        else
        {
            recvData >> playerBag;
            recvData >> playerSlotId;
            recvData >> toChar;
            recvData >> splitedAmount;
        }

        // Player <-> Bank
        // Allow to work with inventory only
        if (!Player::IsInventoryPos(playerBag, playerSlotId) && !(playerBag == NULL_BAG && playerSlotId == NULL_SLOT))
            GetPlayer()->SendEquipError(EQUIP_ERR_NONE, NULL);
        else
            guild->SwapItemsWithInventory(GetPlayer(), toChar != 0, tabId, slotId, playerBag, playerSlotId, splitedAmount);
    }
}

void WorldSession::HandleGuildBankBuyTab(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint8 tabId;

    recvData >> guid >> tabId;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_BUY_TAB [%s]: [%s[, TabId: %u", GetPlayerInfo().c_str(), guid.ToString().c_str(), tabId);


    if (GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleBuyBankTab(this, tabId);
}

void WorldSession::HandleGuildBankUpdateTab(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint8 tabId;
    std::string name, icon;

    recvData >> guid >> tabId >> name >> icon;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_UPDATE_TAB [%s]: [%s], TabId: %u, Name: %s, Icon: %s"
        , GetPlayerInfo().c_str(), guid.ToString().c_str(), tabId, name.c_str(), icon.c_str());

    if (!name.empty() && !icon.empty())
        if (GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_GUILD_BANK))
            if (Guild* guild = GetPlayer()->GetGuild())
                guild->HandleSetBankTabInfo(this, tabId, name, icon);
}

void WorldSession::HandleGuildBankLogQuery(WorldPacket& recvData)
{
    uint8 tabId;
    recvData >> tabId;

    TC_LOG_DEBUG("guild", "MSG_GUILD_BANK_LOG_QUERY [%s]: TabId: %u", GetPlayerInfo().c_str(), tabId);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankLog(this, tabId);
}

void WorldSession::HandleQueryGuildBankTabText(WorldPacket &recvData)
{
    uint8 tabId;
    recvData >> tabId;

    TC_LOG_DEBUG("guild", "MSG_QUERY_GUILD_BANK_TEXT [%s]: TabId: %u", GetPlayerInfo().c_str(), tabId);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankTabText(this, tabId);
}

void WorldSession::HandleSetGuildBankTabText(WorldPacket &recvData)
{
    uint8 tabId;
    std::string text;
    recvData >> tabId >> text;

    TC_LOG_DEBUG("guild", "CMSG_SET_GUILD_BANK_TEXT [%s]: TabId: %u, Text: %s", GetPlayerInfo().c_str(), tabId, text.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SetBankTabText(tabId, text);
}
