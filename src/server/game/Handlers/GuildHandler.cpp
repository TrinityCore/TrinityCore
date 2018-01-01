/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "AchievementPackets.h"
#include "Common.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "GuildPackets.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"

void WorldSession::HandleGuildQueryOpcode(WorldPackets::Guild::QueryGuildInfo& query)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_QUERY [%s]: Guild: %s Target: %s",
        GetPlayerInfo().c_str(), query.GuildGuid.ToString().c_str(), query.PlayerGuid.ToString().c_str());

    if (Guild* guild = sGuildMgr->GetGuildByGuid(query.GuildGuid))
        if (guild->IsMember(query.PlayerGuid))
        {
            guild->SendQueryResponse(this);
            return;
        }

    WorldPackets::Guild::QueryGuildInfoResponse response;
    response.GuildGuid = query.GuildGuid;
    SendPacket(response.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_QUERY_RESPONSE [%s]", GetPlayerInfo().c_str());
}

void WorldSession::HandleGuildInviteByName(WorldPackets::Guild::GuildInviteByName& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_INVITE [%s]: Invited: %s", GetPlayerInfo().c_str(), packet.Name.c_str());
    if (normalizePlayerName(packet.Name))
        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleInviteMember(this, packet.Name);
}

void WorldSession::HandleGuildOfficerRemoveMember(WorldPackets::Guild::GuildOfficerRemoveMember& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_REMOVE [%s]: Target: %s", GetPlayerInfo().c_str(), packet.Removee.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveMember(this, packet.Removee);
}

void WorldSession::HandleGuildAcceptInvite(WorldPackets::Guild::AcceptGuildInvite& /*invite*/)
{
    if (!GetPlayer()->GetGuildId())
        if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildIdInvited()))
            guild->HandleAcceptMember(this);
}

void WorldSession::HandleGuildDeclineInvitation(WorldPackets::Guild::GuildDeclineInvitation& /*decline*/)
{
    GetPlayer()->SetGuildIdInvited(UI64LIT(0));
    GetPlayer()->SetInGuild(UI64LIT(0));
}

void WorldSession::HandleGuildGetRoster(WorldPackets::Guild::GuildGetRoster& /*packet*/)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRoster(this);
    else
        Guild::SendCommandResult(this, GUILD_COMMAND_GET_ROSTER, ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildPromoteMember(WorldPackets::Guild::GuildPromoteMember& promote)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_PROMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), promote.Promotee.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleUpdateMemberRank(this, promote.Promotee, false);
}

void WorldSession::HandleGuildDemoteMember(WorldPackets::Guild::GuildDemoteMember& demote)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DEMOTE [%s]: Target: %s", GetPlayerInfo().c_str(), demote.Demotee.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleUpdateMemberRank(this, demote.Demotee, true);
}

void WorldSession::HandleGuildAssignRank(WorldPackets::Guild::GuildAssignMemberRank& packet)
{
    ObjectGuid setterGuid = GetPlayer()->GetGUID();

    TC_LOG_DEBUG("guild", "CMSG_GUILD_ASSIGN_MEMBER_RANK [%s]: Target: %s Rank: %u, Issuer: %s",
        GetPlayerInfo().c_str(), packet.Member.ToString().c_str(), packet.RankOrder, setterGuid.ToString().c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMemberRank(this, packet.Member, setterGuid, packet.RankOrder);
}

void WorldSession::HandleGuildLeave(WorldPackets::Guild::GuildLeave& /*leave*/)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleLeaveMember(this);
}

void WorldSession::HandleGuildDelete(WorldPackets::Guild::GuildDelete& /*packet*/)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleDelete(this);
}

void WorldSession::HandleGuildUpdateMotdText(WorldPackets::Guild::GuildUpdateMotdText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_UPDATE_MOTD_TEXT [%s]: MOTD: %s", GetPlayerInfo().c_str(), packet.MotdText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMOTD(this, packet.MotdText);
}

void WorldSession::HandleGuildSetMemberNote(WorldPackets::Guild::GuildSetMemberNote& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_NOTE [%s]: Target: %s, Note: %s, Public: %u",
        GetPlayerInfo().c_str(), packet.NoteeGUID.ToString().c_str(), packet.Note.c_str(), packet.IsPublic);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetMemberNote(this, packet.Note, packet.NoteeGUID, packet.IsPublic);
}

void WorldSession::HandleGuildGetRanks(WorldPackets::Guild::GuildGetRanks& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_GET_RANKS [%s]: Guild: %s",
        GetPlayerInfo().c_str(), packet.GuildGUID.ToString().c_str());

    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        if (guild->IsMember(_player->GetGUID()))
            guild->SendGuildRankInfo(this);
}

void WorldSession::HandleGuildAddRank(WorldPackets::Guild::GuildAddRank& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_ADD_RANK [%s]: Rank: %s", GetPlayerInfo().c_str(), packet.Name.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleAddNewRank(this, packet.Name);
}

void WorldSession::HandleGuildDeleteRank(WorldPackets::Guild::GuildDeleteRank& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_DELETE_RANK [%s]: Rank: %u", GetPlayerInfo().c_str(), packet.RankOrder);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleRemoveRank(this, packet.RankOrder);
}

void WorldSession::HandleGuildUpdateInfoText(WorldPackets::Guild::GuildUpdateInfoText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_GUILD_UPDATE_INFO_TEXT [%s]: %s", GetPlayerInfo().c_str(), packet.InfoText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetInfo(this, packet.InfoText);
}

void WorldSession::HandleSaveGuildEmblem(WorldPackets::Guild::SaveGuildEmblem& packet)
{
    EmblemInfo emblemInfo;
    emblemInfo.ReadPacket(packet);

    TC_LOG_DEBUG("guild", "CMSG_SAVE_GUILD_EMBLEM [%s]: Guid: [%s] Style: %d, Color: %d, BorderStyle: %d, BorderColor: %d, BackgroundColor: %d"
        , GetPlayerInfo().c_str(), packet.Vendor.ToString().c_str(), emblemInfo.GetStyle()
        , emblemInfo.GetColor(), emblemInfo.GetBorderStyle()
        , emblemInfo.GetBorderColor(), emblemInfo.GetBackgroundColor());

    if (GetPlayer()->GetNPCIfCanInteractWith(packet.Vendor, UNIT_NPC_FLAG_TABARDDESIGNER))
    {
        // Remove fake death
        if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
            GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

        if (!emblemInfo.ValidateEmblemColors())
        {
            Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_INVALID_TABARD_COLORS);
            return;
        }

        if (Guild* guild = GetPlayer()->GetGuild())
            guild->HandleSetEmblem(this, emblemInfo);
        else
            Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_NOGUILD); // "You are not part of a guild!";
    }
    else
        Guild::SendSaveEmblemResult(this, ERR_GUILDEMBLEM_INVALIDVENDOR); // "That's not an emblem vendor!"
}

void WorldSession::HandleGuildEventLogQuery(WorldPackets::Guild::GuildEventLogQuery& /*packet*/)
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
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_ACTIVATE [%s]: [%s] AllSlots: %u"
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
            GetPlayer()->SendEquipError(EQUIP_ERR_INTERNAL_BAG_ERROR, NULL);
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
    TC_LOG_DEBUG("guild", "CMSG_GUILD_BANK_QUERY_TEXT [%s]: TabId: %u", GetPlayerInfo().c_str(), packet.Tab);

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SendBankTabText(this, packet.Tab);
}

void WorldSession::HandleGuildBankSetTabText(WorldPackets::Guild::GuildBankSetTabText& packet)
{
    TC_LOG_DEBUG("guild", "CMSG_SET_GUILD_BANK_TEXT [%s]: TabId: %u, Text: %s", GetPlayerInfo().c_str(), packet.Tab, packet.TabText.c_str());

    if (Guild* guild = GetPlayer()->GetGuild())
        guild->SetBankTabText(packet.Tab, packet.TabText);
}

void WorldSession::HandleGuildSetRankPermissions(WorldPackets::Guild::GuildSetRankPermissions& packet)
{
    Guild* guild = GetPlayer()->GetGuild();
    if (!guild)
        return;

    GuildBankRightsAndSlotsVec rightsAndSlots(GUILD_BANK_MAX_TABS);
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
        rightsAndSlots[tabId] = GuildBankRightsAndSlots(tabId, uint8(packet.TabFlags[tabId]), uint32(packet.TabWithdrawItemLimit[tabId]));

    TC_LOG_DEBUG("guild", "CMSG_GUILD_SET_RANK_PERMISSIONS [%s]: Rank: %s (%u)", GetPlayerInfo().c_str(), packet.RankName.c_str(), packet.RankOrder);

    guild->HandleSetRankInfo(this, packet.RankOrder, packet.RankName, packet.Flags, packet.WithdrawGoldLimit, rightsAndSlots);
}

void WorldSession::HandleGuildRequestPartyState(WorldPackets::Guild::RequestGuildPartyState& packet)
{
    if (Guild* guild = sGuildMgr->GetGuildByGuid(packet.GuildGUID))
        guild->HandleGuildPartyRequest(this);
}

void WorldSession::HandleGuildChallengeUpdateRequest(WorldPackets::Guild::GuildChallengeUpdateRequest& /*packet*/)
{
    if (Guild* guild = _player->GetGuild())
        guild->HandleGuildRequestChallengeUpdate(this);
}

void WorldSession::HandleDeclineGuildInvites(WorldPackets::Guild::DeclineGuildInvites& packet)
{
    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_AUTO_DECLINE_GUILD, packet.Allow);
}

void WorldSession::HandleRequestGuildRewardsList(WorldPackets::Guild::RequestGuildRewardsList& /*packet*/)
{
    if (sGuildMgr->GetGuildById(_player->GetGuildId()))
    {
        std::vector<GuildReward> const& rewards = sGuildMgr->GetGuildRewards();

        WorldPackets::Guild::GuildRewardList rewardList;
        rewardList.Version = uint32(time(NULL));
        rewardList.RewardItems.reserve(rewards.size());

        for (uint32 i = 0; i < rewards.size(); i++)
        {
            WorldPackets::Guild::GuildRewardItem rewardItem;
            rewardItem.ItemID = rewards[i].ItemID;
            rewardItem.RaceMask = rewards[i].RaceMask;
            rewardItem.MinGuildLevel = 0;
            rewardItem.MinGuildRep = rewards[i].MinGuildRep;
            rewardItem.AchievementsRequired = rewards[i].AchievementsRequired;
            rewardItem.Cost = rewards[i].Cost;
            rewardList.RewardItems.push_back(rewardItem);
        }

        SendPacket(rewardList.Write());
    }
}

void WorldSession::HandleGuildQueryNews(WorldPackets::Guild::GuildQueryNews& newsQuery)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        if (guild->GetGUID() == newsQuery.GuildGUID)
            guild->SendNewsUpdate(this);
}

void WorldSession::HandleGuildNewsUpdateSticky(WorldPackets::Guild::GuildNewsUpdateSticky& packet)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleNewsSetSticky(this, packet.NewsID, packet.Sticky);
}

void WorldSession::HandleGuildSetGuildMaster(WorldPackets::Guild::GuildSetGuildMaster& packet)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetNewGuildMaster(this, packet.NewMasterName);
}

void WorldSession::HandleGuildSetAchievementTracking(WorldPackets::Guild::GuildSetAchievementTracking& packet)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleSetAchievementTracking(this, packet.AchievementIDs);
}
void WorldSession::HandleGuildGetAchievementMembers(WorldPackets::Achievement::GuildGetAchievementMembers& getAchievementMembers)
{
    if (Guild* guild = GetPlayer()->GetGuild())
        guild->HandleGetAchievementMembers(this, uint32(getAchievementMembers.AchievementID));
}
