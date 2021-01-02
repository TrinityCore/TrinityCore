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
#include "Guild.h"
#include "GuildMgr.h"
#include "GuildPackets.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldPacket.h"

void WorldSession::HandleGuildQueryOpcode(WorldPackets::Guild::QueryGuildInfo& query)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY [%s]: Guild: %u", GetPlayerInfo().c_str(), query.GuildId);
    if (!query.GuildId)
        return;

    if (Guild* guild = sGuildMgr->GetGuildById(query.GuildId))
        guild->HandleQuery(this);
}

void WorldSession::HandleGuildCreateOpcode(WorldPackets::Guild::GuildCreate& packet)
{
    TC_LOG_ERROR("entities.player.cheat", "CMSG_GUILD_CREATE: Possible hacking-attempt: %s tried to create a guild [Name: %s] using cheats", GetPlayerInfo().c_str(), packet.GuildName.c_str());
}

void WorldSession::HandleGuildInviteOpcode(WorldPackets::Guild::GuildInviteByName& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_INVITE [%s]: Invited: %s", GetPlayerInfo().c_str(), packet.Name.c_str());
    if (normalizePlayerName(packet.Name))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleInviteMember(this, packet.Name);
}

void WorldSession::HandleGuildRemoveOpcode(WorldPackets::Guild::GuildOfficerRemoveMember& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_REMOVE [%s]: Target: %s", GetPlayerInfo().c_str(), packet.Removee.c_str());

    if (normalizePlayerName(packet.Removee))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleRemoveMember(this, packet.Removee);
}

void WorldSession::HandleGuildAcceptOpcode(WorldPackets::Guild::AcceptGuildInvite& /*invite*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ACCEPT [%s]", GetPlayer()->GetName().c_str());

    if (!GetPlayer()->GetGuildId())
        if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildIdInvited()))
            guild->HandleAcceptMember(this);
}

void WorldSession::HandleGuildDeclineOpcode(WorldPackets::Guild::GuildDeclineInvitation& /*decline*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DECLINE [%s]", GetPlayerInfo().c_str());

    GetPlayer()->SetGuildIdInvited(0);
    GetPlayer()->SetInGuild(0);
}

void WorldSession::HandleGuildInfoOpcode(WorldPackets::Guild::GuildGetInfo& /*packet*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_INFO [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendInfo(this);
}

void WorldSession::HandleGuildRosterOpcode(WorldPackets::Guild::GuildGetRoster& /*packet*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ROSTER [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRoster(this);
    else
        Guild::SendCommandResult(this, GUILD_COMMAND_ROSTER, ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPackets::Guild::GuildPromoteMember& promote)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_PROMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), promote.Promotee.c_str());

    if (normalizePlayerName(promote.Promotee))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleUpdateMemberRank(this, promote.Promotee, false);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPackets::Guild::GuildDemoteMember& demote)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), demote.Demotee.c_str());

    if (normalizePlayerName(demote.Demotee))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleUpdateMemberRank(this, demote.Demotee, true);
}

void WorldSession::HandleGuildLeaveOpcode(WorldPackets::Guild::GuildLeave& /*leave*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_LEAVE [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleLeaveMember(this);
}

void WorldSession::HandleGuildDelete(WorldPackets::Guild::GuildDelete& /*packet*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DISBAND [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleDisband(this);
}

void WorldSession::HandleGuildSetGuildMaster(WorldPackets::Guild::GuildSetGuildMaster& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_LEADER [%s]: Target: %s", GetPlayerInfo().c_str(), packet.NewMasterName.c_str());

    if (normalizePlayerName(packet.NewMasterName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetLeader(this, packet.NewMasterName);
}

void WorldSession::HandleGuildUpdateMotdText(WorldPackets::Guild::GuildUpdateMotdText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_MOTD [%s]: MOTD: %s", GetPlayerInfo().c_str(), packet.MotdText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMOTD(this, packet.MotdText);
}

void WorldSession::HandleGuildSetPublicNoteOpcode(WorldPackets::Guild::GuildSetMemberNote& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_PUBLIC_NOTE [%s]: Target: %s, Note: %s",
         GetPlayerInfo().c_str(), packet.NoteeName.c_str(), packet.Note.c_str());

    if (normalizePlayerName(packet.NoteeName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetMemberNote(this, packet.NoteeName, packet.Note, false);
}

void WorldSession::HandleGuildSetOfficerNoteOpcode(WorldPackets::Guild::GuildSetMemberNote& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_OFFICER_NOTE [%s]: Target: %s, Note: %s",
         GetPlayerInfo().c_str(), packet.NoteeName.c_str(), packet.Note.c_str());

    if (normalizePlayerName(packet.NoteeName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetMemberNote(this, packet.NoteeName, packet.Note, true);
}

void WorldSession::HandleGuildSetRankPermissions(WorldPackets::Guild::GuildSetRankPermissions& packet)
{
    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
        return;

    std::array<GuildBankRightsAndSlots, GUILD_BANK_MAX_TABS> rightsAndSlots;
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
        rightsAndSlots[tabId] = GuildBankRightsAndSlots(tabId, uint8(packet.TabFlags[tabId]), uint32(packet.TabWithdrawItemLimit[tabId]));

    TC_LOG_DEBUG("guild", "CMSG_GUILD_RANK [%s]: Rank: %s (%u)", GetPlayerInfo().c_str(), packet.RankName.c_str(), packet.RankID);

    guild->HandleSetRankInfo(this, packet.RankID, packet.RankName, packet.Flags, packet.WithdrawGoldLimit, rightsAndSlots);
}

void WorldSession::HandleGuildAddRankOpcode(WorldPackets::Guild::GuildAddRank& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ADD_RANK [%s]: Rank: %s", GetPlayerInfo().c_str(), packet.Name.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleAddNewRank(this, packet.Name);
}

void WorldSession::HandleGuildDeleteRank(WorldPackets::Guild::GuildDeleteRank& /*packet*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEL_RANK [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveLowestRank(this);
}

void WorldSession::HandleGuildUpdateInfoText(WorldPackets::Guild::GuildUpdateInfoText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_INFO_TEXT [%s]: %s", GetPlayerInfo().c_str(), packet.InfoText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetInfo(this, packet.InfoText);
}

void WorldSession::HandleSaveGuildEmblemOpcode(WorldPackets::Guild::SaveGuildEmblem& packet)
{
    EmblemInfo emblemInfo;
    emblemInfo.ReadPacket(packet);

    TC_LOG_DEBUG("guild", "MSG_SAVE_GUILD_EMBLEM [%s]: Guid: [%s] Style: %d, Color: %d, BorderStyle: %d, BorderColor: %d, BackgroundColor: %d"
        , GetPlayerInfo().c_str(), packet.Vendor.ToString().c_str(), emblemInfo.GetStyle()
        , emblemInfo.GetColor(), emblemInfo.GetBorderStyle()
        , emblemInfo.GetBorderColor(), emblemInfo.GetBackgroundColor());

    if (GetPlayer()->GetNPCIfCanInteractWith(packet.Vendor, UNIT_NPC_FLAG_TABARDDESIGNER))
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

void WorldSession::HandleGuildEventLogQueryOpcode(WorldPackets::Guild::GuildEventLogQuery& /*packet*/)
{
    TC_LOG_DEBUG("guild", "MSG_GUILD_EVENT_LOG_QUERY [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendEventLog(this);
}

void WorldSession::HandleGuildBankMoneyWithdrawn(WorldPackets::Guild::GuildBankRemainingWithdrawMoneyQuery& /*packet*/)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendMoneyInfo(this);
}

void WorldSession::HandleGuildPermissionsQuery(WorldPackets::Guild::GuildPermissionsQuery& /* packet */)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendPermissions(this);
}

// Called when clicking on Guild bank gameobject
void WorldSession::HandleGuildBankActivate(WorldPackets::Guild::GuildBankActivate& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANKER_ACTIVATE [%s]: [%s] AllSlots: %u"
        , GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.FullUpdate);

    GameObject const* const go = GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK);
    if (!go)
        return;

    Guild* const guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_VIEW_TAB, ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    guild->SendBankTabsInfo(this, packet.FullUpdate);
}

// Called when opening guild bank tab only (first one)
void WorldSession::HandleGuildBankQueryTab(WorldPackets::Guild::GuildBankQueryTab& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_QUERY_TAB [%s]: %s, TabId: %u, ShowTabs: %u"
        , GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Tab, packet.FullUpdate);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->SendBankTabData(this, packet.Tab, true /*packet.FullUpdate*/);
                                                          // HACK: client doesn't query entire tab content if it had received SMSG_GUILD_BANK_LIST in this session
                                                          // but we broadcast bank updates to entire guild when *ANYONE* changes anything, incorrectly initializing clients
                                                          // tab content with only data for that change
}

void WorldSession::HandleGuildBankDepositMoney(WorldPackets::Guild::GuildBankDepositMoney& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_DEPOSIT_MONEY [%s]: [%s], money: %u",
        GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Money);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (packet.Money && GetPlayer()->HasEnoughMoney(packet.Money))
            if (Guild* guild = GetPlayer()->GetGuild())
                guild->HandleMemberDepositMoney(this, packet.Money);
}

void WorldSession::HandleGuildBankWithdrawMoney(WorldPackets::Guild::GuildBankWithdrawMoney& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_WITHDRAW_MONEY [%s]: [%s], money: %u",
        GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Money);

    if (packet.Money && GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleMemberWithdrawMoney(this, packet.Money);
}

void WorldSession::HandleGuildBankSwapItems(WorldPackets::Guild::GuildBankSwapItems& packet)
{
    if (!GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
        return;

    if (packet.BankOnly)
        guild->SwapItems(GetPlayer(), packet.BankTab1, packet.BankSlot1, packet.BankTab, packet.BankSlot, packet.BankItemCount);
    else
    {
        uint8 playerBag = NULL_BAG;
        uint8 playerSlotId = NULL_SLOT;
        uint8 toChar = 1;
        uint32 splitedAmount = 0;

        if (!packet.AutoStore)
        {
            playerBag = packet.ContainerSlot;
            playerSlotId = packet.ContainerItemSlot;
            toChar = packet.ToSlot;
            splitedAmount = packet.StackCount;
        }

        // Player <-> Bank
        // Allow to work with inventory only
        if (!Player::IsInventoryPos(playerBag, playerSlotId) && !(playerBag == NULL_BAG && playerSlotId == NULL_SLOT))
            GetPlayer()->SendEquipError(EQUIP_ERR_NONE, nullptr);
        else
            guild->SwapItemsWithInventory(GetPlayer(), toChar != 0, packet.BankTab, packet.BankSlot, playerBag, playerSlotId, splitedAmount);
    }
}

void WorldSession::HandleGuildBankBuyTab(WorldPackets::Guild::GuildBankBuyTab& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_BUY_TAB [%s]: [%s[, TabId: %u", GetPlayerInfo().c_str(), packet.Banker .ToString().c_str(), packet.BankTab);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleBuyBankTab(this, packet.BankTab);
}

void WorldSession::HandleGuildBankUpdateTab(WorldPackets::Guild::GuildBankUpdateTab& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_UPDATE_TAB [%s]: [%s], TabId: %u, Name: %s, Icon: %s"
        , GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.BankTab, packet.Name.c_str(), packet.Icon.c_str());

    if (!packet.Name.empty() && !packet.Icon.empty())
        if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
            if (Guild* guild = GetPlayer()->GetGuild())
                guild->HandleSetBankTabInfo(this, packet.BankTab, packet.Name, packet.Icon);
}

void WorldSession::HandleGuildBankLogQuery(WorldPackets::Guild::GuildBankLogQuery& packet)
{
    TC_LOG_DEBUG("guild", "MSG_GUILD_BANK_LOG_QUERY [%s]: TabId: %u", GetPlayerInfo().c_str(), packet.Tab);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankLog(this, packet.Tab);
}

void WorldSession::HandleGuildBankTextQuery(WorldPackets::Guild::GuildBankTextQuery& packet)
{
    TC_LOG_DEBUG("guild", "MSG_QUERY_GUILD_BANK_TEXT [%s]: TabId: %u", GetPlayerInfo().c_str(), packet.Tab);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankTabText(this, packet.Tab);
}

void WorldSession::HandleGuildBankSetTabText(WorldPackets::Guild::GuildBankSetTabText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_SET_GUILD_BANK_TEXT [%s]: TabId: %u, Text: %s", GetPlayerInfo().c_str(), packet.Tab, packet.TabText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SetBankTabText(packet.Tab, packet.TabText);
}
