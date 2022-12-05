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
#include "AchievementMgr.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "GuildPackets.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryCallback.h"
#include "SpellAuraDefines.h"
#include "World.h"
#include "WorldPacket.h"

void WorldSession::HandleGuildQueryOpcode(WorldPacket& recvPacket)
{
    ObjectGuid guildGuid, playerGuid;
    recvPacket >> guildGuid >> playerGuid;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY [%s]: Guild: %s Target: %s",
        GetPlayerInfo().c_str(), guildGuid.ToString().c_str(), playerGuid.ToString().c_str());

    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildGuid))
        if (guild->IsMember(playerGuid))
            guild->SendQueryResponse(this);
}

void WorldSession::HandleGuildInviteOpcode(WorldPacket& recvPacket)
{
    uint32 nameLength = recvPacket.ReadBits(7);
    std::string invitedName = recvPacket.ReadString(nameLength);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_INVITE [%s]: Invited: %s", GetPlayerInfo().c_str(), invitedName.c_str());
    if (normalizePlayerName(invitedName))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleInviteMember(this, invitedName);
}

void WorldSession::HandleGuildRemoveOpcode(WorldPacket& recvPacket)
{
    ObjectGuid playerGuid;

    playerGuid[6] = recvPacket.ReadBit();
    playerGuid[5] = recvPacket.ReadBit();
    playerGuid[4] = recvPacket.ReadBit();
    playerGuid[0] = recvPacket.ReadBit();
    playerGuid[1] = recvPacket.ReadBit();
    playerGuid[3] = recvPacket.ReadBit();
    playerGuid[7] = recvPacket.ReadBit();
    playerGuid[2] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(playerGuid[2]);
    recvPacket.ReadByteSeq(playerGuid[6]);
    recvPacket.ReadByteSeq(playerGuid[5]);
    recvPacket.ReadByteSeq(playerGuid[7]);
    recvPacket.ReadByteSeq(playerGuid[1]);
    recvPacket.ReadByteSeq(playerGuid[4]);
    recvPacket.ReadByteSeq(playerGuid[3]);
    recvPacket.ReadByteSeq(playerGuid[0]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_REMOVE [%s]: Target: %s", GetPlayerInfo().c_str(), playerGuid.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveMember(this, playerGuid);
}

void WorldSession::HandleGuildAcceptOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ACCEPT [%s]", GetPlayerInfo().c_str());

    if (!GetPlayer()->GetGuildId())
        if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildIdInvited()))
            guild->HandleAcceptMember(this);
}

void WorldSession::HandleGuildDeclineOpcode(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DECLINE [%s]", GetPlayerInfo().c_str());
    if (GetPlayer()->GetGuildId())
        return;

    GetPlayer()->SetGuildIdInvited(0);
}

void WorldSession::HandleGuildGetRosterOpcode(WorldPackets::Guild::GuildGetRoster& /*packet*/)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRoster(this);
    else
        Guild::SendCommandResult(this, GUILD_COMMAND_ROSTER, ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPacket& recvPacket)
{
    ObjectGuid targetGuid;

    targetGuid[7] = recvPacket.ReadBit();
    targetGuid[2] = recvPacket.ReadBit();
    targetGuid[5] = recvPacket.ReadBit();
    targetGuid[6] = recvPacket.ReadBit();
    targetGuid[1] = recvPacket.ReadBit();
    targetGuid[0] = recvPacket.ReadBit();
    targetGuid[3] = recvPacket.ReadBit();
    targetGuid[4] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(targetGuid[0]);
    recvPacket.ReadByteSeq(targetGuid[5]);
    recvPacket.ReadByteSeq(targetGuid[2]);
    recvPacket.ReadByteSeq(targetGuid[3]);
    recvPacket.ReadByteSeq(targetGuid[6]);
    recvPacket.ReadByteSeq(targetGuid[4]);
    recvPacket.ReadByteSeq(targetGuid[1]);
    recvPacket.ReadByteSeq(targetGuid[7]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_PROMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), targetGuid.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleUpdateMemberRank(this, targetGuid, false);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPacket& recvPacket)
{
    ObjectGuid targetGuid;

    targetGuid[7] = recvPacket.ReadBit();
    targetGuid[1] = recvPacket.ReadBit();
    targetGuid[5] = recvPacket.ReadBit();
    targetGuid[6] = recvPacket.ReadBit();
    targetGuid[2] = recvPacket.ReadBit();
    targetGuid[3] = recvPacket.ReadBit();
    targetGuid[0] = recvPacket.ReadBit();
    targetGuid[4] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(targetGuid[1]);
    recvPacket.ReadByteSeq(targetGuid[2]);
    recvPacket.ReadByteSeq(targetGuid[7]);
    recvPacket.ReadByteSeq(targetGuid[5]);
    recvPacket.ReadByteSeq(targetGuid[6]);
    recvPacket.ReadByteSeq(targetGuid[0]);
    recvPacket.ReadByteSeq(targetGuid[4]);
    recvPacket.ReadByteSeq(targetGuid[3]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), targetGuid.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleUpdateMemberRank(this, targetGuid, true);
}

void WorldSession::HandleGuildAssignRankOpcode(WorldPacket& recvPacket)
{
    ObjectGuid targetGuid;
    ObjectGuid setterGuid;

    uint32 rankId;
    recvPacket >> rankId;

    targetGuid[1] = recvPacket.ReadBit();
    targetGuid[7] = recvPacket.ReadBit();
    setterGuid[4] = recvPacket.ReadBit();
    setterGuid[2] = recvPacket.ReadBit();
    targetGuid[4] = recvPacket.ReadBit();
    targetGuid[5] = recvPacket.ReadBit();
    targetGuid[6] = recvPacket.ReadBit();
    setterGuid[1] = recvPacket.ReadBit();
    setterGuid[7] = recvPacket.ReadBit();
    targetGuid[2] = recvPacket.ReadBit();
    targetGuid[3] = recvPacket.ReadBit();
    targetGuid[0] = recvPacket.ReadBit();
    setterGuid[6] = recvPacket.ReadBit();
    setterGuid[3] = recvPacket.ReadBit();
    setterGuid[0] = recvPacket.ReadBit();
    setterGuid[5] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(targetGuid[0]);
    recvPacket.ReadByteSeq(setterGuid[1]);
    recvPacket.ReadByteSeq(setterGuid[3]);
    recvPacket.ReadByteSeq(setterGuid[5]);
    recvPacket.ReadByteSeq(targetGuid[7]);
    recvPacket.ReadByteSeq(targetGuid[3]);
    recvPacket.ReadByteSeq(setterGuid[0]);
    recvPacket.ReadByteSeq(targetGuid[1]);
    recvPacket.ReadByteSeq(setterGuid[6]);
    recvPacket.ReadByteSeq(targetGuid[2]);
    recvPacket.ReadByteSeq(targetGuid[5]);
    recvPacket.ReadByteSeq(targetGuid[4]);
    recvPacket.ReadByteSeq(setterGuid[2]);
    recvPacket.ReadByteSeq(setterGuid[4]);
    recvPacket.ReadByteSeq(targetGuid[6]);
    recvPacket.ReadByteSeq(setterGuid[7]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_ASSIGN_MEMBER_RANK [%s]: Target: %s Rank: %u, Issuer: %s",
        GetPlayerInfo().c_str(), targetGuid.ToString().c_str(), rankId, setterGuid.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMemberRank(this, targetGuid, setterGuid, rankId);
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

void WorldSession::HandleGuildMOTDOpcode(WorldPacket& recvPacket)
{
    uint32 motdLength = recvPacket.ReadBits(11);
    std::string motd = recvPacket.ReadString(motdLength);
    TC_LOG_DEBUG("guild", "CMSG_GUILD_MOTD [%s]: MOTD: %s", GetPlayerInfo().c_str(), motd.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMOTD(this, motd);
}

void WorldSession::HandleGuildSetNoteOpcode(WorldPacket& recvPacket)
{
    ObjectGuid playerGuid;

    playerGuid[1] = recvPacket.ReadBit();
    playerGuid[4] = recvPacket.ReadBit();
    playerGuid[5] = recvPacket.ReadBit();
    playerGuid[3] = recvPacket.ReadBit();
    playerGuid[0] = recvPacket.ReadBit();
    playerGuid[7] = recvPacket.ReadBit();
    bool ispublic = recvPacket.ReadBit();      // 0 == Officer, 1 == Public
    playerGuid[6] = recvPacket.ReadBit();
    uint32 noteLength = recvPacket.ReadBits(8);
    playerGuid[2] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(playerGuid[4]);
    recvPacket.ReadByteSeq(playerGuid[5]);
    recvPacket.ReadByteSeq(playerGuid[0]);
    recvPacket.ReadByteSeq(playerGuid[3]);
    recvPacket.ReadByteSeq(playerGuid[1]);
    recvPacket.ReadByteSeq(playerGuid[6]);
    recvPacket.ReadByteSeq(playerGuid[7]);
    std::string note = recvPacket.ReadString(noteLength);
    recvPacket.ReadByteSeq(playerGuid[2]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_NOTE [%s]: Target: %s, Note: %s, Public: %u",
        GetPlayerInfo().c_str(), playerGuid.ToString().c_str(), note.c_str(), ispublic);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMemberNote(this, note, playerGuid, ispublic);
}

void WorldSession::HandleGuildQueryRanksOpcode(WorldPacket& recvPacket)
{
    ObjectGuid guildGuid;

    guildGuid[2] = recvPacket.ReadBit();
    guildGuid[3] = recvPacket.ReadBit();
    guildGuid[0] = recvPacket.ReadBit();
    guildGuid[6] = recvPacket.ReadBit();
    guildGuid[4] = recvPacket.ReadBit();
    guildGuid[7] = recvPacket.ReadBit();
    guildGuid[5] = recvPacket.ReadBit();
    guildGuid[1] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guildGuid[3]);
    recvPacket.ReadByteSeq(guildGuid[4]);
    recvPacket.ReadByteSeq(guildGuid[5]);
    recvPacket.ReadByteSeq(guildGuid[7]);
    recvPacket.ReadByteSeq(guildGuid[1]);
    recvPacket.ReadByteSeq(guildGuid[0]);
    recvPacket.ReadByteSeq(guildGuid[6]);
    recvPacket.ReadByteSeq(guildGuid[2]);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY_RANKS [%s]: Guild: %s",
        GetPlayerInfo().c_str(), guildGuid.ToString().c_str());

    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildGuid))
        if (guild->IsMember(_player->GetGUID()))
            guild->SendGuildRankInfo(this);
}

void WorldSession::HandleGuildAddRankOpcode(WorldPacket& recvPacket)
{
    uint32 rankId;
    recvPacket >> rankId;

    uint32 length = recvPacket.ReadBits(7);
    std::string rankName = recvPacket.ReadString(length);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_ADD_RANK [%s]: Rank: %s", GetPlayerInfo().c_str(), rankName.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleAddNewRank(this, rankName);
}

void WorldSession::HandleGuildDelRankOpcode(WorldPacket& recvPacket)
{
    uint32 rankId;
    recvPacket >> rankId;

    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEL_RANK [%s]: Rank: %u", GetPlayerInfo().c_str(), rankId);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveRank(this, rankId);
}

void WorldSession::HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket)
{
    uint32 length = recvPacket.ReadBits(12);
    std::string info = recvPacket.ReadString(length);

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
        {
            guild->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_TABARD, 0, 0, 0, nullptr, GetPlayer());
            guild->HandleSetEmblem(this, emblemInfo);
        }
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

void WorldSession::HandleGuildBankMoneyWithdrawn(WorldPackets::Guild::GuildBankRemainingWithdrawMoneyQuery& /*recvPacket */)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY_QUERY [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendMoneyInfo(this);
}

void WorldSession::HandleGuildPermissionsQuery(WorldPackets::Guild::GuildPermissionsQuery& /*packet*/)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_PERMISSIONS_QUERY [%s]", GetPlayerInfo().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendPermissions(this);
}

// Called when clicking on Guild bank gameobject
void WorldSession::HandleGuildBankActivate(WorldPackets::Guild::GuildBankActivate& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_ACTIVATE [%s]: [%s] AllSlots: %u"
        , GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.FullUpdate);

    GameObject const* const go = GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK);
    if (!go)
        return;

    Guild const* guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_VIEW_TAB, ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    guild->SendBankList(this, 0, packet.FullUpdate);
}

// Called when opening guild bank tab only (first one)
void WorldSession::HandleGuildBankQueryTab(WorldPackets::Guild::GuildBankQueryTab& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_QUERY_TAB [%s]: %s, TabId: %u, ShowTabs: %u"
        , GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Tab, packet.FullUpdate);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->SendBankList(this, packet.Tab, packet.FullUpdate);
}

void WorldSession::HandleGuildBankDepositMoney(WorldPackets::Guild::GuildBankDepositMoney& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_DEPOSIT_MONEY [%s]: [%s], money: " UI64FMTD,
        GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Money);

    if (GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (packet.Money && GetPlayer()->HasEnoughMoney(packet.Money))
            if (Guild* guild = GetPlayer()->GetGuild())
                guild->HandleMemberDepositMoney(this, packet.Money);
}

void WorldSession::HandleGuildBankWithdrawMoney(WorldPackets::Guild::GuildBankWithdrawMoney& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_WITHDRAW_MONEY [%s]: [%s], money: " UI64FMTD,
        GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.Money);

    if (packet.Money && GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleMemberWithdrawMoney(this, packet.Money);
}

void WorldSession::HandleGuildBankSwapItems(WorldPackets::Guild::GuildBankSwapItems& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_SWAP_ITEMS [%s]", GetPlayerInfo().c_str());

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
        return;

    if (packet.BankOnly)
    {
        guild->SwapItems(GetPlayer(), packet.BankTab1, packet.BankSlot1, packet.BankTab, packet.BankSlot, packet.StackCount);
    }
    else
    {
        // Player <-> Bank
        // Allow to work with inventory only
        if (!Player::IsInventoryPos(packet.ContainerSlot, packet.ContainerItemSlot) && !packet.AutoStore)
            GetPlayer()->SendEquipError(EQUIP_ERR_INTERNAL_BAG_ERROR, nullptr);
        else
            guild->SwapItemsWithInventory(GetPlayer(), packet.ToSlot != 0, packet.BankTab, packet.BankSlot, packet.ContainerSlot, packet.ContainerItemSlot, packet.StackCount);
    }
}

void WorldSession::HandleGuildBankBuyTab(WorldPackets::Guild::GuildBankBuyTab& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_BUY_TAB [%s]: [%s[, TabId: %u", GetPlayerInfo().c_str(), packet.Banker.ToString().c_str(), packet.BankTab);

    if (!packet.Banker || GetPlayer()->GetGameObjectIfCanInteractWith(packet.Banker, GAMEOBJECT_TYPE_GUILD_BANK))
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
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_LOG_QUERY [%s]: TabId: %u", GetPlayerInfo().c_str(), packet.Tab);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankLog(this, packet.Tab);
}

void WorldSession::HandleGuildBankTextQuery(WorldPackets::Guild::GuildBankTextQuery& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_TEXT_QUERY [%s]: TabId: %u", GetPlayerInfo().c_str(), packet.Tab);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankTabText(this, packet.Tab);
}

void WorldSession::HandleGuildBankSetTabText(WorldPackets::Guild::GuildBankSetTabText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_SET_GUILD_BANK_TEXT [%s]: TabId: %u, Text: %s", GetPlayerInfo().c_str(), packet.Tab, packet.TabText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SetBankTabText(packet.Tab, packet.TabText);
}

void WorldSession::HandleGuildXPQueryOpcode(WorldPackets::Guild::GuildXPQuery& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_QUERY_GUILD_XP [%s]: Guild: %s", GetPlayerInfo().c_str(), packet.GuildGUID.ToString().c_str());

    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        if (guild->IsMember(_player->GetGUID()))
            guild->SendGuildXP(this);
}

void WorldSession::HandleGuildSetRankPermissionsOpcode(WorldPacket& recvPacket)
{
    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
    {
        recvPacket.rfinish();
        return;
    }

    uint32 oldRankId;
    uint32 newRankId;
    uint32 oldRights;
    uint32 newRights;
    uint32 moneyPerDay;

    recvPacket >> oldRankId;
    recvPacket >> oldRights;
    recvPacket >> newRights;

    GuildBankRightsAndSlotsVec rightsAndSlots(GUILD_BANK_MAX_TABS);
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        uint32 bankRights;
        uint32 slots;

        recvPacket >> bankRights;
        recvPacket >> slots;

        rightsAndSlots[tabId] = GuildBankRightsAndSlots(tabId, uint8(bankRights), slots);
    }

    recvPacket >> moneyPerDay;
    recvPacket >> newRankId;
    uint32 nameLength = recvPacket.ReadBits(7);
    std::string rankName = recvPacket.ReadString(nameLength);

    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_RANK_PERMISSIONS [%s]: Rank: %s (%u)", GetPlayerInfo().c_str(), rankName.c_str(), newRankId);

    guild->HandleSetRankInfo(this, newRankId, rankName, newRights, moneyPerDay, rightsAndSlots);
}

void WorldSession::HandleGuildRequestPartyState(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_GUILD_REQUEST_PARTY_STATE");

    ObjectGuid guildGuid;

    guildGuid[0] = recvPacket.ReadBit();
    guildGuid[6] = recvPacket.ReadBit();
    guildGuid[7] = recvPacket.ReadBit();
    guildGuid[3] = recvPacket.ReadBit();
    guildGuid[5] = recvPacket.ReadBit();
    guildGuid[1] = recvPacket.ReadBit();
    guildGuid[2] = recvPacket.ReadBit();
    guildGuid[4] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guildGuid[6]);
    recvPacket.ReadByteSeq(guildGuid[3]);
    recvPacket.ReadByteSeq(guildGuid[2]);
    recvPacket.ReadByteSeq(guildGuid[1]);
    recvPacket.ReadByteSeq(guildGuid[5]);
    recvPacket.ReadByteSeq(guildGuid[0]);
    recvPacket.ReadByteSeq(guildGuid[7]);
    recvPacket.ReadByteSeq(guildGuid[4]);

    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildGuid))
        guild->HandleGuildPartyRequest(this);
}

void WorldSession::HandleGuildRequestChallengeUpdate(WorldPackets::Guild::GuildChallengeUpdateRequest& /*packet*/)
{
    if (Guild* guild = _player->GetGuild())
        guild->HandleGuildRequestChallengeUpdate(this);
}

void WorldSession::HandleGuildRequestMaxDailyXP(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    guid[0] = recvPacket.ReadBit();
    guid[3] = recvPacket.ReadBit();
    guid[5] = recvPacket.ReadBit();
    guid[1] = recvPacket.ReadBit();
    guid[4] = recvPacket.ReadBit();
    guid[6] = recvPacket.ReadBit();
    guid[7] = recvPacket.ReadBit();
    guid[2] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guid[7]);
    recvPacket.ReadByteSeq(guid[4]);
    recvPacket.ReadByteSeq(guid[3]);
    recvPacket.ReadByteSeq(guid[5]);
    recvPacket.ReadByteSeq(guid[1]);
    recvPacket.ReadByteSeq(guid[2]);
    recvPacket.ReadByteSeq(guid[6]);
    recvPacket.ReadByteSeq(guid[0]);

    if (Guild* guild = sGuildMgr->GetGuildByGuid(guid))
    {
        if (guild->IsMember(_player->GetGUID()))
        {
            WorldPacket data(SMSG_GUILD_MAX_DAILY_XP, 8);
            data << uint64(sWorld->getIntConfig(CONFIG_GUILD_DAILY_XP_CAP));
            SendPacket(&data);
        }
    }
}

void WorldSession::HandleAutoDeclineGuildInvites(WorldPacket& recvPacket)
{
    uint8 enable;
    recvPacket >> enable;

    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_AUTO_DECLINE_GUILD, enable != 0);
}

void WorldSession::HandleRequestGuildRewardsList(WorldPackets::Guild::RequestGuildRewardsList& /*packet*/)
{
    if (sGuildMgr->GetGuildById(_player->GetGuildId()))
    {
        std::vector<GuildReward> const& rewards = sGuildMgr->GetGuildRewards();

        WorldPackets::Guild::GuildRewardList rewardList;
        rewardList.Version = uint32(GameTime::GetGameTime());
        rewardList.RewardItems.reserve(rewards.size());

        for (uint32 i = 0; i < rewards.size(); i++)
        {
            WorldPackets::Guild::GuildRewardItem rewardItem;
            rewardItem.ItemID = rewards[i].Entry;
            rewardItem.RaceMask = rewards[i].Racemask;
            rewardItem.MinGuildRep = rewards[i].Standing;
            rewardItem.AchievementRequired = rewards[i].AchievementId;
            rewardItem.Cost = rewards[i].Price;
            rewardList.RewardItems.push_back(rewardItem);
        }

        SendPacket(rewardList.Write());
    }
}

void WorldSession::HandleGuildQueryNewsOpcode(WorldPacket& recvPacket)
{
    recvPacket.read_skip<uint32>();
    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY_NEWS [%s]", GetPlayerInfo().c_str());
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendNewsUpdate(this);
}

void WorldSession::HandleGuildNewsUpdateStickyOpcode(WorldPacket& recvPacket)
{
    uint32 newsId;
    bool sticky;
    ObjectGuid guid;

    recvPacket >> newsId;

    guid[2] = recvPacket.ReadBit();
    guid[4] = recvPacket.ReadBit();
    guid[3] = recvPacket.ReadBit();
    guid[0] = recvPacket.ReadBit();
    sticky = recvPacket.ReadBit();
    guid[6] = recvPacket.ReadBit();
    guid[7] = recvPacket.ReadBit();
    guid[1] = recvPacket.ReadBit();
    guid[5] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guid[6]);
    recvPacket.ReadByteSeq(guid[2]);
    recvPacket.ReadByteSeq(guid[1]);
    recvPacket.ReadByteSeq(guid[0]);
    recvPacket.ReadByteSeq(guid[5]);
    recvPacket.ReadByteSeq(guid[3]);
    recvPacket.ReadByteSeq(guid[7]);
    recvPacket.ReadByteSeq(guid[4]);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleNewsSetSticky(this, newsId, sticky);
}

void WorldSession::HandleGuildReplaceGuildMaster(WorldPackets::Guild::ReplaceGuildMaster& /*packet */)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetNewGuildMaster(this, "", true);
}

void WorldSession::HandleGuildSetGuildMaster(WorldPackets::Guild::SetGuildMaster& packet)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetNewGuildMaster(this, packet.NewMasterName, packet.IsDethrone);
}

void WorldSession::HandleGuildSetAchievementTracking(WorldPacket& recvPacket)
{
    uint32 count = recvPacket.ReadBits(24);
    std::set<uint32> achievementIds;

    for (uint32 i = 0; i < count; ++i)
    {
        uint32 achievementId;
        recvPacket >> achievementId;
        achievementIds.insert(achievementId);
    }

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetAchievementTracking(this, achievementIds);
}

void WorldSession::HandleGuildSwitchRank(WorldPacket& recvPacket)
{
    /*

    To-do: handle this

    uint32 rank;
    bool direction;                 // if its true, then the rank rises, if no, it goes down

    recvPacket >> rank;
    direction = recvPacket.ReadBit();
    */

    recvPacket.rfinish();

    Guild* guild = GetPlayer()->GetGuild();

    if (!guild)
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE, ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (GetPlayer()->GetGUID() != guild->GetLeaderGUID())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE, ERR_GUILD_PERMISSIONS);
        return;
    }
}

void WorldSession::HandleGuildAchievementMembers(WorldPacket& recvPacket)
{
    uint32 achievementId;
    ObjectGuid guildGuid;
    ObjectGuid playerGuid;

    recvPacket >> achievementId;

    guildGuid[0] = recvPacket.ReadBit();
    playerGuid[5] = recvPacket.ReadBit();
    playerGuid[4] = recvPacket.ReadBit();
    playerGuid[7] = recvPacket.ReadBit();
    playerGuid[0] = recvPacket.ReadBit();
    guildGuid[5] = recvPacket.ReadBit();
    guildGuid[7] = recvPacket.ReadBit();
    playerGuid[3] = recvPacket.ReadBit();
    guildGuid[3] = recvPacket.ReadBit();
    playerGuid[2] = recvPacket.ReadBit();
    guildGuid[4] = recvPacket.ReadBit();
    guildGuid[1] = recvPacket.ReadBit();
    guildGuid[6] = recvPacket.ReadBit();
    playerGuid[6] = recvPacket.ReadBit();
    guildGuid[2] = recvPacket.ReadBit();
    playerGuid[1] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guildGuid[0]);
    recvPacket.ReadByteSeq(guildGuid[3]);
    recvPacket.ReadByteSeq(playerGuid[2]);
    recvPacket.ReadByteSeq(guildGuid[7]);
    recvPacket.ReadByteSeq(guildGuid[2]);
    recvPacket.ReadByteSeq(playerGuid[5]);
    recvPacket.ReadByteSeq(playerGuid[0]);
    recvPacket.ReadByteSeq(playerGuid[3]);
    recvPacket.ReadByteSeq(guildGuid[5]);
    recvPacket.ReadByteSeq(guildGuid[1]);
    recvPacket.ReadByteSeq(playerGuid[4]);
    recvPacket.ReadByteSeq(playerGuid[1]);
    recvPacket.ReadByteSeq(playerGuid[6]);
    recvPacket.ReadByteSeq(playerGuid[7]);
    recvPacket.ReadByteSeq(guildGuid[4]);
    recvPacket.ReadByteSeq(guildGuid[6]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_GUILD_ACHIEVEMENT_MEMBERS");

    if(Guild* pGuild = sGuildMgr->GetGuildByGuid(guildGuid))
    {
        if(pGuild->GetAchievementMgr().HasAchieved(achievementId))
        {
            ObjectGuid gguid = pGuild->GetGUID();
            CompletedAchievementData* achievement = pGuild->GetAchievementMgr().GetCompletedDataForAchievement(achievementId);
            WorldPacket data(SMSG_GUILD_ACHIEVEMENT_MEMBERS);

            data.WriteBit(gguid[3]);
            data.WriteBit(gguid[4]);
            data.WriteBit(gguid[7]);
            data.WriteBit(gguid[0]);

            data.WriteBits(achievement->guids.size(),26);

            for(std::set<ObjectGuid>::iterator itr = achievement->guids.begin(); itr != achievement->guids.end(); ++itr)
            {
                ObjectGuid pguid = (*itr);

                data.WriteBit(pguid[3]);
                data.WriteBit(pguid[1]);
                data.WriteBit(pguid[4]);
                data.WriteBit(pguid[5]);
                data.WriteBit(pguid[7]);
                data.WriteBit(pguid[0]);
                data.WriteBit(pguid[6]);
                data.WriteBit(pguid[2]);
            }

            data.WriteBit(gguid[2]);
            data.WriteBit(gguid[6]);
            data.WriteBit(gguid[5]);
            data.WriteBit(gguid[1]);

            data.FlushBits();

            data.WriteByteSeq(gguid[5]);

            for(std::set<ObjectGuid>::iterator itr = achievement->guids.begin(); itr != achievement->guids.end(); ++itr)
            {
                ObjectGuid pguid = (*itr);

                data.WriteByteSeq(pguid[1]);
                data.WriteByteSeq(pguid[5]);
                data.WriteByteSeq(pguid[7]);
                data.WriteByteSeq(pguid[0]);
                data.WriteByteSeq(pguid[6]);
                data.WriteByteSeq(pguid[4]);
                data.WriteByteSeq(pguid[3]);
                data.WriteByteSeq(pguid[2]);
            }

            data.WriteByteSeq(gguid[7]);
            data.WriteByteSeq(gguid[2]);
            data.WriteByteSeq(gguid[4]);
            data.WriteByteSeq(gguid[3]);
            data.WriteByteSeq(gguid[6]);
            data.WriteByteSeq(gguid[0]);

            data << achievementId;

            data.WriteByteSeq(gguid[1]);

            SendPacket(&data);
        }
    }
}

void WorldSession::HandleGuildRenameRequest(WorldPacket& recvPacket)
{
    uint32 lenght;
    std::string newName;

    lenght = recvPacket.ReadBits(8);
    newName = recvPacket.ReadString(lenght);

    Guild* pGuild = GetPlayer()->GetGuild();

    if(pGuild)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_NAME);

        stmt->setUInt32(1, pGuild->GetId());
        stmt->setString(0, newName);

        _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleGuildRenameCallback, this, newName, std::placeholders::_1)));

        WorldPacket data(SMSG_GUILD_FLAGGED_FOR_RENAME,1);

        data.WriteBit(true);            // it may send false also, but we don't know how to handle exeptions by the DB layer
        data.FlushBits();

        pGuild->BroadcastPacket(&data);
    }
}

void WorldSession::HandleGuildRenameCallback(std::string newName, PreparedQueryResult result)
{
    Guild* pGuild = GetPlayer()->GetGuild();

    bool hasRenamed = (result && result->GetRowCount() > 0);

    WorldPacket data(SMSG_GUILD_CHANGE_NAME_RESULT, 1);
    data.WriteBit(hasRenamed);
    data.FlushBits();

    SendPacket(&data);

    if(pGuild && hasRenamed)
        pGuild->SetName(newName);
}

void WorldSession::HandleGuildQueryRecipesOpcode(WorldPackets::Guild::GuildQueryRecipes& packet)
{
    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        if (guild->IsMember(_player->GetGUID()))
            guild->SendKnownRecipes(_player);
}

void WorldSession::HandleGuildQueryMembersForRecipe(WorldPackets::Guild::GuildQueryMembersForRecipe& packet)
{
    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        if (guild->IsMember(_player->GetGUID()))
            guild->SendMembersForRecipe(_player, packet.SkillLineID, packet.SpellID, packet.UniqueBit);
}

void WorldSession::HandleGuildQueryMemberRecipe(WorldPackets::Guild::GuildQueryMemberRecipes& packet)
{
    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        if (guild->IsMember(_player->GetGUID()) && guild->IsMember(packet.GuildMember))
            guild->SendRecipesOfMember(_player, packet.SkillLineID, packet.GuildMember);
}
