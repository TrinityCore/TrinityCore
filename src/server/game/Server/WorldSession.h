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

/// \addtogroup u2w
/// @{
/// \file

#ifndef __WORLDSESSION_H
#define __WORLDSESSION_H

#include "Common.h"
#include "SharedDefines.h"
#include "AddonMgr.h"
#include "DatabaseEnv.h"
#include "World.h"

struct ItemPrototype;
struct AuctionEntry;
struct DeclinedName;
struct MovementInfo;

class Creature;
class Item;
class Object;
class Player;
class Unit;
class GameObject;
class Quest;
class WorldPacket;
class WorldSocket;
class LoginQueryHolder;
class CharacterHandler;
class SpellCastTargets;
struct AreaTableEntry;
struct GM_Ticket;
struct LfgJoinResultData;
struct LfgLockStatus;
struct LfgPlayerBoot;
struct LfgProposal;
struct LfgReward;
struct LfgRoleCheck;
struct LfgUpdateData;

enum AccountDataType
{
    GLOBAL_CONFIG_CACHE             = 0,                    // 0x01 g
    PER_CHARACTER_CONFIG_CACHE      = 1,                    // 0x02 p
    GLOBAL_BINDINGS_CACHE           = 2,                    // 0x04 g
    PER_CHARACTER_BINDINGS_CACHE    = 3,                    // 0x08 p
    GLOBAL_MACROS_CACHE             = 4,                    // 0x10 g
    PER_CHARACTER_MACROS_CACHE      = 5,                    // 0x20 p
    PER_CHARACTER_LAYOUT_CACHE      = 6,                    // 0x40 p
    PER_CHARACTER_CHAT_CACHE        = 7,                    // 0x80 p
};

#define NUM_ACCOUNT_DATA_TYPES        8

#define GLOBAL_CACHE_MASK           0x15
#define PER_CHARACTER_CACHE_MASK    0xEA

struct AccountData
{
    AccountData() : Time(0), Data("") {}

    time_t Time;
    std::string Data;
};

enum PartyOperation
{
    PARTY_OP_INVITE = 0,
    PARTY_OP_UNINVITE = 1,
    PARTY_OP_LEAVE = 2,
    PARTY_OP_SWAP = 4
};

enum PartyResult
{
    ERR_PARTY_RESULT_OK                 = 0,
    ERR_BAD_PLAYER_NAME_S               = 1,
    ERR_TARGET_NOT_IN_GROUP_S           = 2,
    ERR_TARGET_NOT_IN_INSTANCE_S        = 3,
    ERR_GROUP_FULL                      = 4,
    ERR_ALREADY_IN_GROUP_S              = 5,
    ERR_NOT_IN_GROUP                    = 6,
    ERR_NOT_LEADER                      = 7,
    ERR_PLAYER_WRONG_FACTION            = 8,
    ERR_IGNORING_YOU_S                  = 9,
    ERR_LFG_PENDING                     = 12,
    ERR_INVITE_RESTRICTED               = 13,
    ERR_GROUP_SWAP_FAILED               = 14,               // if (PartyOperation == PARTY_OP_SWAP) ERR_GROUP_SWAP_FAILED else ERR_INVITE_IN_COMBAT
    ERR_INVITE_UNKNOWN_REALM            = 15,
    ERR_INVITE_NO_PARTY_SERVER          = 16,
    ERR_INVITE_PARTY_BUSY               = 17,
    ERR_PARTY_TARGET_AMBIGUOUS          = 18,
    ERR_PARTY_LFG_INVITE_RAID_LOCKED    = 19,
    ERR_PARTY_LFG_BOOT_LIMIT            = 20,
    ERR_PARTY_LFG_BOOT_COOLDOWN_S       = 21,
    ERR_PARTY_LFG_BOOT_IN_PROGRESS      = 22,
    ERR_PARTY_LFG_BOOT_TOO_FEW_PLAYERS  = 23,
    ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S   = 24,
    ERR_RAID_DISALLOWED_BY_LEVEL        = 25,
    ERR_PARTY_LFG_BOOT_IN_COMBAT        = 26,
    ERR_VOTE_KICK_REASON_NEEDED         = 27,
    ERR_PARTY_LFG_BOOT_DUNGEON_COMPLETE = 28,
    ERR_PARTY_LFG_BOOT_LOOT_ROLLS       = 29,
    ERR_PARTY_LFG_TELEPORT_IN_COMBAT    = 30
};

enum ChatRestrictionType
{
    ERR_CHAT_RESTRICTED = 0,
    ERR_CHAT_THROTTLED  = 1,
    ERR_USER_SQUELCHED  = 2,
    ERR_YELL_RESTRICTED = 3
};

enum CharterTypes
{
    GUILD_CHARTER_TYPE                            = 9,
    ARENA_TEAM_CHARTER_2v2_TYPE                   = 2,
    ARENA_TEAM_CHARTER_3v3_TYPE                   = 3,
    ARENA_TEAM_CHARTER_5v5_TYPE                   = 5
};

//class to deal with packet processing
//allows to determine if next packet is safe to be processed
class PacketFilter
{
public:
    explicit PacketFilter(WorldSession * pSession) : m_pSession(pSession) {}
    virtual ~PacketFilter() {}

    virtual bool Process(WorldPacket * /*packet*/) { return true; }
    virtual bool ProcessLogout() const { return true; }

protected:
    WorldSession * const m_pSession;
};
//process only thread-safe packets in Map::Update()
class MapSessionFilter : public PacketFilter
{
public:
    explicit MapSessionFilter(WorldSession * pSession) : PacketFilter(pSession) {}
    ~MapSessionFilter() {}

    virtual bool Process(WorldPacket * packet);
    //in Map::Update() we do not process player logout!
    virtual bool ProcessLogout() const { return false; }
};

//class used to filer only thread-unsafe packets from queue
//in order to update only be used in World::UpdateSessions()
class WorldSessionFilter : public PacketFilter
{
public:
    explicit WorldSessionFilter(WorldSession * pSession) : PacketFilter(pSession) {}
    ~WorldSessionFilter() {}

    virtual bool Process(WorldPacket* packet);
};

/// Player session in the World
class WorldSession
{
    friend class CharacterHandler;
    public:
        WorldSession(uint32 id, WorldSocket *sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter);
        ~WorldSession();

        bool PlayerLoading() const { return m_playerLoading; }
        bool PlayerLogout() const { return m_playerLogout; }
        bool PlayerLogoutWithSave() const { return m_playerLogout && m_playerSave; }

        void SizeError(WorldPacket const& packet, uint32 size) const;

        void ReadAddonsInfo(WorldPacket &data);
        void SendAddonsInfo();

        void ReadMovementInfo(WorldPacket &data, MovementInfo *mi);
        void WriteMovementInfo(WorldPacket *data, MovementInfo *mi);

        void SendPacket(WorldPacket const* packet);
        void SendNotification(const char *format,...) ATTR_PRINTF(2,3);
        void SendNotification(uint32 string_id,...);
        void SendPetNameInvalid(uint32 error, const std::string& name, DeclinedName *declinedName);
        void SendPartyResult(PartyOperation operation, const std::string& member, PartyResult res, uint32 val = 0);
        void SendAreaTriggerMessage(const char* Text, ...) ATTR_PRINTF(2,3);
        void SendSetPhaseShift(uint32 phaseShift);
        void SendQueryTimeResponse();

        void SendAuthResponse(uint8 code, bool shortForm, uint32 queuePos = 0);
        void SendClientCacheVersion(uint32 version);

        AccountTypes GetSecurity() const { return _security; }
        uint32 GetAccountId() const { return _accountId; }
        Player* GetPlayer() const { return _player; }
        char const* GetPlayerName() const;
        void SetSecurity(AccountTypes security) { _security = security; }
        std::string const& GetRemoteAddress() { return m_Address; }
        void SetPlayer(Player *plr);
        uint8 Expansion() const { return m_expansion; }

        /// Session in auth.queue currently
        void SetInQueue(bool state) { m_inQueue = state; }

        /// Is the user engaged in a log out process?
        bool isLogingOut() const { return _logoutTime || m_playerLogout; }

        /// Engage the logout process for the user
        void LogoutRequest(time_t requestTime)
        {
            _logoutTime = requestTime;
        }

        /// Is logout cooldown expired?
        bool ShouldLogOut(time_t currTime) const
        {
            return (_logoutTime > 0 && currTime >= _logoutTime + 20);
        }

        void LogoutPlayer(bool Save);
        void KickPlayer();

        void QueuePacket(WorldPacket* new_packet);
        bool Update(uint32 diff, PacketFilter& updater);

        /// Handle the authentication waiting queue (to be completed)
        void SendAuthWaitQue(uint32 position);

        //void SendTestCreatureQueryOpcode(uint32 entry, uint64 guid, uint32 testvalue);
        void SendNameQueryOpcode(Player* p);
        void SendNameQueryOpcodeFromDB(uint64 guid);
        void SendNameQueryOpcodeFromDBCallBack(QueryResult result);

        void SendTrainerList(uint64 guid);
        void SendTrainerList(uint64 guid, const std::string& strTitle);
        void SendListInventory(uint64 guid);
        void SendShowBank(uint64 guid);
        void SendTabardVendorActivate(uint64 guid);
        void SendSpiritResurrect();
        void SendBindPoint(Creature* npc);

        void SendAttackStop(Unit const* enemy);

        void SendBattlegGroundList(uint64 guid, BattlegroundTypeId bgTypeId);

        void SendTradeStatus(TradeStatus status);
        void SendUpdateTrade(bool trader_data = true);
        void SendCancelTrade();

        void SendPetitionQueryOpcode(uint64 petitionguid);

        // Spell
        void HandleClientCastFlags(WorldPacket& recvPacket, uint8 castFlags, SpellCastTargets & targets);

        // Pet
        void SendPetNameQuery(uint64 guid, uint32 petnumber);
        void SendStablePet(uint64 guid);
        void SendStablePetCallback(QueryResult result, uint64 guid);
        void SendStableResult(uint8 guid);
        bool CheckStableMaster(uint64 guid);

        // Account Data
        AccountData *GetAccountData(AccountDataType type) { return &m_accountData[type]; }
        void SetAccountData(AccountDataType type, time_t time_, std::string data);
        void SendAccountDataTimes(uint32 mask);
        void LoadGlobalAccountData();
        void LoadAccountData(PreparedQueryResult result, uint32 mask);
        void LoadTutorialsData();
        void SendTutorialsData();
        void SaveTutorialsData(SQLTransaction& trans);
        uint32 GetTutorialInt(uint32 intId)
        {
            return m_Tutorials[intId];
        }

        void SetTutorialInt(uint32 intId, uint32 value)
        {
            if (m_Tutorials[intId] != value)
            {
                m_Tutorials[intId] = value;
                m_TutorialsChanged = true;
            }
        }
        //used with item_page table
        bool SendItemInfo(uint32 itemid, WorldPacket data);
        //auction
        void SendAuctionHello(uint64 guid, Creature * unit);
        void SendAuctionCommandResult(uint32 auctionId, uint32 Action, uint32 ErrorCode, uint32 bidError = 0);
        void SendAuctionBidderNotification(uint32 location, uint32 auctionId, uint64 bidder, uint32 bidSum, uint32 diff, uint32 item_template);
        void SendAuctionOwnerNotification(AuctionEntry * auction);

        //Item Enchantment
        void SendEnchantmentLog(uint64 Target, uint64 Caster,uint32 ItemID,uint32 SpellID);
        void SendItemEnchantTimeUpdate(uint64 Playerguid, uint64 Itemguid,uint32 slot,uint32 Duration);

        //Taxi
        void SendTaxiStatus(uint64 guid);
        void SendTaxiMenu(Creature* unit);
        void SendDoFlight(uint32 mountDisplayId, uint32 path, uint32 pathNode = 0);
        bool SendLearnNewTaxiNode(Creature* unit);
        void SendDiscoverNewTaxiNode(uint32 nodeid);

        // Guild/Arena Team
        void SendArenaTeamCommandResult(uint32 team_action, const std::string& team, const std::string& player, uint32 error_id);
        void SendNotInArenaTeamPacket(uint8 type);
        void SendPetitionShowList(uint64 guid);

        void BuildPartyMemberStatsChangedPacket(Player *player, WorldPacket *data);

        void DoLootRelease(uint64 lguid);

        // Account mute time
        time_t m_muteTime;

        // Locales
        LocaleConstant GetSessionDbcLocale() const { return m_sessionDbcLocale; }
        LocaleConstant GetSessionDbLocaleIndex() const { return m_sessionDbLocaleIndex; }
        const char *GetTrinityString(int32 entry) const;

        uint32 GetLatency() const { return m_latency; }
        void SetLatency(uint32 latency) { m_latency = latency; }
        uint32 getDialogStatus(Player *pPlayer, Object* questgiver, uint32 defstatus);

        time_t m_timeOutTime;
        void UpdateTimeOutTime(uint32 diff)
        {
            if (time_t(diff) > m_timeOutTime)
                m_timeOutTime = 0;
            else
                m_timeOutTime -= diff;
        }
        void ResetTimeOutTime()
        {
            m_timeOutTime = sWorld.getIntConfig(CONFIG_SOCKET_TIMEOUTTIME);
        }
        bool IsConnectionIdle() const
        {
            if (m_timeOutTime <= 0 && !m_inQueue)
                return true;
            return false;
        }

        // Recruit-A-Friend Handling
        uint32 GetRecruiterId() { return recruiterId; }

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPacket& recvPacket);          // not used
        void Handle_EarlyProccess(WorldPacket& recvPacket);// just mark packets processed in WorldSocket::OnRead
        void Handle_ServerSide(WorldPacket& recvPacket);    // sever side only, can't be accepted from client
        void Handle_Deprecated(WorldPacket& recvPacket);    // never used anymore by client

        void HandleCharEnumOpcode(WorldPacket& recvPacket);
        void HandleCharDeleteOpcode(WorldPacket& recvPacket);
        void HandleCharCreateOpcode(WorldPacket& recvPacket);
        void HandlePlayerLoginOpcode(WorldPacket& recvPacket);
        void HandleCharEnum(QueryResult result);
        void HandlePlayerLogin(LoginQueryHolder * holder);
        void HandleCharFactionOrRaceChange(WorldPacket& recv_data);

        // played time
        void HandlePlayedTime(WorldPacket& recvPacket);

        // new
        void HandleMoveUnRootAck(WorldPacket& recvPacket);
        void HandleMoveRootAck(WorldPacket& recvPacket);
        void HandleLookingForGroup(WorldPacket& recvPacket);

        // new inspect
        void HandleInspectOpcode(WorldPacket& recvPacket);

        // new party stats
        void HandleInspectHonorStatsOpcode(WorldPacket& recvPacket);

        void HandleMoveWaterWalkAck(WorldPacket& recvPacket);
        void HandleFeatherFallAck(WorldPacket &recv_data);

        void HandleMoveHoverAck(WorldPacket & recv_data);

        void HandleMountSpecialAnimOpcode(WorldPacket &recvdata);

        // character view
        void HandleShowingHelmOpcode(WorldPacket& recv_data);
        void HandleShowingCloakOpcode(WorldPacket& recv_data);

        // repair
        void HandleRepairItemOpcode(WorldPacket& recvPacket);

        // Knockback
        void HandleMoveKnockBackAck(WorldPacket& recvPacket);

        void HandleMoveTeleportAck(WorldPacket& recvPacket);
        void HandleForceSpeedChangeAck(WorldPacket & recv_data);

        void HandlePingOpcode(WorldPacket& recvPacket);
        void HandleAuthSessionOpcode(WorldPacket& recvPacket);
        void HandleRepopRequestOpcode(WorldPacket& recvPacket);
        void HandleAutostoreLootItemOpcode(WorldPacket& recvPacket);
        void HandleLootMoneyOpcode(WorldPacket& recvPacket);
        void HandleLootOpcode(WorldPacket& recvPacket);
        void HandleLootReleaseOpcode(WorldPacket& recvPacket);
        void HandleLootMasterGiveOpcode(WorldPacket& recvPacket);
        void HandleWhoOpcode(WorldPacket& recvPacket);
        void HandleLogoutRequestOpcode(WorldPacket& recvPacket);
        void HandlePlayerLogoutOpcode(WorldPacket& recvPacket);
        void HandleLogoutCancelOpcode(WorldPacket& recvPacket);

        // GM Ticket opcodes
        void HandleGMTicketCreateOpcode(WorldPacket& recvPacket);
        void HandleGMTicketUpdateOpcode(WorldPacket& recvPacket);
        void HandleGMTicketDeleteOpcode(WorldPacket& recvPacket);
        void HandleGMTicketGetTicketOpcode(WorldPacket& recvPacket);
        void HandleGMTicketSystemStatusOpcode(WorldPacket& recvPacket);
        void SendGMTicketGetTicket(uint32 status, char const* text, GM_Ticket *ticket = NULL);
        void SendGMTicketResponse(GM_Ticket *ticket);
        void HandleGMSurveySubmit(WorldPacket& recvPacket);
        void HandleReportLag(WorldPacket& recvPacket);
        void HandleGMResponseResolve(WorldPacket& recvPacket);

        void HandleTogglePvP(WorldPacket& recvPacket);

        void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
        void HandleSetTargetOpcode(WorldPacket& recvPacket);
        void HandleSetSelectionOpcode(WorldPacket& recvPacket);
        void HandleStandStateChangeOpcode(WorldPacket& recvPacket);
        void HandleEmoteOpcode(WorldPacket& recvPacket);
        void HandleContactListOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcodeCallBack(QueryResult result, std::string friendNote);
        void HandleDelFriendOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcodeCallBack(QueryResult result);
        void HandleDelIgnoreOpcode(WorldPacket& recvPacket);
        void HandleSetContactNotesOpcode(WorldPacket& recvPacket);
        void HandleBugOpcode(WorldPacket& recvPacket);
        void HandleSetAmmoOpcode(WorldPacket& recvPacket);
        void HandleItemNameQueryOpcode(WorldPacket& recvPacket);

        void HandleAreaTriggerOpcode(WorldPacket& recvPacket);

        void HandleSetFactionAtWar(WorldPacket & recv_data);
        void HandleSetFactionCheat(WorldPacket & recv_data);
        void HandleSetWatchedFactionOpcode(WorldPacket & recv_data);
        void HandleSetFactionInactiveOpcode(WorldPacket & recv_data);

        void HandleUpdateAccountData(WorldPacket& recvPacket);
        void HandleRequestAccountData(WorldPacket& recvPacket);
        void HandleSetActionButtonOpcode(WorldPacket& recvPacket);

        void HandleGameObjectUseOpcode(WorldPacket& recPacket);
        void HandleMeetingStoneInfo(WorldPacket& recPacket);
        void HandleGameobjectReportUse(WorldPacket& recvPacket);

        void HandleNameQueryOpcode(WorldPacket& recvPacket);

        void HandleQueryTimeOpcode(WorldPacket& recvPacket);

        void HandleCreatureQueryOpcode(WorldPacket& recvPacket);

        void HandleGameObjectQueryOpcode(WorldPacket& recvPacket);

        void HandleMoveWorldportAckOpcode(WorldPacket& recvPacket);
        void HandleMoveWorldportAckOpcode();                // for server-side calls

        void HandleMovementOpcodes(WorldPacket& recvPacket);
        void HandleSetActiveMoverOpcode(WorldPacket &recv_data);
        void HandleMoveNotActiveMover(WorldPacket &recv_data);
        void HandleDismissControlledVehicle(WorldPacket &recv_data);
        void HandleRequestVehicleExit(WorldPacket &recv_data);
        void HandleChangeSeatsOnControlledVehicle(WorldPacket &recv_data);
        void HandleMoveTimeSkippedOpcode(WorldPacket &recv_data);

        void HandleRequestRaidInfoOpcode(WorldPacket & recv_data);

        void HandleBattlefieldStatusOpcode(WorldPacket &recv_data);
        void HandleBattleMasterHelloOpcode(WorldPacket &recv_data);

        void HandleGroupInviteOpcode(WorldPacket& recvPacket);
        //void HandleGroupCancelOpcode(WorldPacket& recvPacket);
        void HandleGroupAcceptOpcode(WorldPacket& recvPacket);
        void HandleGroupDeclineOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteGuidOpcode(WorldPacket& recvPacket);
        void HandleGroupSetLeaderOpcode(WorldPacket& recvPacket);
        void HandleGroupDisbandOpcode(WorldPacket& recvPacket);
        void HandleOptOutOfLootOpcode(WorldPacket &recv_data);
        void HandleLootMethodOpcode(WorldPacket& recvPacket);
        void HandleLootRoll(WorldPacket &recv_data);
        void HandleRequestPartyMemberStatsOpcode(WorldPacket &recv_data);
        void HandleRaidTargetUpdateOpcode(WorldPacket & recv_data);
        void HandleRaidReadyCheckOpcode(WorldPacket & recv_data);
        void HandleRaidReadyCheckFinishedOpcode(WorldPacket & recv_data);
        void HandleGroupRaidConvertOpcode(WorldPacket & recv_data);
        void HandleGroupChangeSubGroupOpcode(WorldPacket & recv_data);
        void HandleGroupAssistantLeaderOpcode(WorldPacket & recv_data);
        void HandlePartyAssignmentOpcode(WorldPacket & recv_data);

        void HandlePetitionBuyOpcode(WorldPacket& recv_data);
        void HandlePetitionShowSignOpcode(WorldPacket& recv_data);
        void HandlePetitionQueryOpcode(WorldPacket& recv_data);
        void HandlePetitionRenameOpcode(WorldPacket& recv_data);
        void HandlePetitionSignOpcode(WorldPacket& recv_data);
        void HandlePetitionDeclineOpcode(WorldPacket& recv_data);
        void HandleOfferPetitionOpcode(WorldPacket& recv_data);
        void HandleTurnInPetitionOpcode(WorldPacket& recv_data);

        void HandleGuildQueryOpcode(WorldPacket& recvPacket);
        void HandleGuildCreateOpcode(WorldPacket& recvPacket);
        void HandleGuildInviteOpcode(WorldPacket& recvPacket);
        void HandleGuildRemoveOpcode(WorldPacket& recvPacket);
        void HandleGuildAcceptOpcode(WorldPacket& recvPacket);
        void HandleGuildDeclineOpcode(WorldPacket& recvPacket);
        void HandleGuildInfoOpcode(WorldPacket& recvPacket);
        void HandleGuildEventLogQueryOpcode(WorldPacket& recvPacket);
        void HandleGuildRosterOpcode(WorldPacket& recvPacket);
        void HandleGuildPromoteOpcode(WorldPacket& recvPacket);
        void HandleGuildDemoteOpcode(WorldPacket& recvPacket);
        void HandleGuildLeaveOpcode(WorldPacket& recvPacket);
        void HandleGuildDisbandOpcode(WorldPacket& recvPacket);
        void HandleGuildLeaderOpcode(WorldPacket& recvPacket);
        void HandleGuildMOTDOpcode(WorldPacket& recvPacket);
        void HandleGuildSetPublicNoteOpcode(WorldPacket& recvPacket);
        void HandleGuildSetOfficerNoteOpcode(WorldPacket& recvPacket);
        void HandleGuildRankOpcode(WorldPacket& recvPacket);
        void HandleGuildAddRankOpcode(WorldPacket& recvPacket);
        void HandleGuildDelRankOpcode(WorldPacket& recvPacket);
        void HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket);
        void HandleSaveGuildEmblemOpcode(WorldPacket& recvPacket);

        void HandleTaxiNodeStatusQueryOpcode(WorldPacket& recvPacket);
        void HandleTaxiQueryAvailableNodes(WorldPacket& recvPacket);
        void HandleActivateTaxiOpcode(WorldPacket& recvPacket);
        void HandleActivateTaxiExpressOpcode(WorldPacket& recvPacket);
        void HandleMoveSplineDoneOpcode(WorldPacket& recvPacket);

        void HandleTabardVendorActivateOpcode(WorldPacket& recvPacket);
        void HandleBankerActivateOpcode(WorldPacket& recvPacket);
        void HandleBuyBankSlotOpcode(WorldPacket& recvPacket);
        void HandleTrainerListOpcode(WorldPacket& recvPacket);
        void HandleTrainerBuySpellOpcode(WorldPacket& recvPacket);
        void HandlePetitionShowListOpcode(WorldPacket& recvPacket);
        void HandleGossipHelloOpcode(WorldPacket& recvPacket);
        void HandleGossipSelectOptionOpcode(WorldPacket& recvPacket);
        void HandleSpiritHealerActivateOpcode(WorldPacket& recvPacket);
        void HandleNpcTextQueryOpcode(WorldPacket& recvPacket);
        void HandleBinderActivateOpcode(WorldPacket& recvPacket);
        void HandleListStabledPetsOpcode(WorldPacket& recvPacket);
        void HandleStablePet(WorldPacket& recvPacket);
        void HandleStablePetCallback(QueryResult result);
        void HandleUnstablePet(WorldPacket& recvPacket);
        void HandleUnstablePetCallback(QueryResult result, uint32 petnumber);
        void HandleBuyStableSlot(WorldPacket& recvPacket);
        void HandleStableRevivePet(WorldPacket& recvPacket);
        void HandleStableSwapPet(WorldPacket& recvPacket);
        void HandleStableSwapPetCallback(QueryResult result, uint32 petnumber);

        void HandleDuelAcceptedOpcode(WorldPacket& recvPacket);
        void HandleDuelCancelledOpcode(WorldPacket& recvPacket);

        void HandleAcceptTradeOpcode(WorldPacket& recvPacket);
        void HandleBeginTradeOpcode(WorldPacket& recvPacket);
        void HandleBusyTradeOpcode(WorldPacket& recvPacket);
        void HandleCancelTradeOpcode(WorldPacket& recvPacket);
        void HandleClearTradeItemOpcode(WorldPacket& recvPacket);
        void HandleIgnoreTradeOpcode(WorldPacket& recvPacket);
        void HandleInitiateTradeOpcode(WorldPacket& recvPacket);
        void HandleSetTradeGoldOpcode(WorldPacket& recvPacket);
        void HandleSetTradeItemOpcode(WorldPacket& recvPacket);
        void HandleUnacceptTradeOpcode(WorldPacket& recvPacket);

        void HandleAuctionHelloOpcode(WorldPacket& recvPacket);
        void HandleAuctionListItems(WorldPacket & recv_data);
        void HandleAuctionListBidderItems(WorldPacket & recv_data);
        void HandleAuctionSellItem(WorldPacket & recv_data);
        void HandleAuctionRemoveItem(WorldPacket & recv_data);
        void HandleAuctionListOwnerItems(WorldPacket & recv_data);
        void HandleAuctionPlaceBid(WorldPacket & recv_data);
        void HandleAuctionListPendingSales(WorldPacket & recv_data);

        void HandleGetMailList(WorldPacket & recv_data);
        void HandleSendMail(WorldPacket & recv_data);
        void HandleMailTakeMoney(WorldPacket & recv_data);
        void HandleMailTakeItem(WorldPacket & recv_data);
        void HandleMailMarkAsRead(WorldPacket & recv_data);
        void HandleMailReturnToSender(WorldPacket & recv_data);
        void HandleMailDelete(WorldPacket & recv_data);
        void HandleItemTextQuery(WorldPacket & recv_data);
        void HandleMailCreateTextItem(WorldPacket & recv_data);
        void HandleQueryNextMailTime(WorldPacket & recv_data);
        void HandleCancelChanneling(WorldPacket & recv_data);

        void SendItemPageInfo(ItemPrototype *itemProto);
        void HandleSplitItemOpcode(WorldPacket& recvPacket);
        void HandleSwapInvItemOpcode(WorldPacket& recvPacket);
        void HandleDestroyItemOpcode(WorldPacket& recvPacket);
        void HandleAutoEquipItemOpcode(WorldPacket& recvPacket);
        void HandleItemQuerySingleOpcode(WorldPacket& recvPacket);
        void HandleSellItemOpcode(WorldPacket& recvPacket);
        void HandleBuyItemInSlotOpcode(WorldPacket& recvPacket);
        void HandleBuyItemOpcode(WorldPacket& recvPacket);
        void HandleListInventoryOpcode(WorldPacket& recvPacket);
        void HandleAutoStoreBagItemOpcode(WorldPacket& recvPacket);
        void HandleReadItem(WorldPacket& recvPacket);
        void HandleAutoEquipItemSlotOpcode(WorldPacket & recvPacket);
        void HandleSwapItem(WorldPacket & recvPacket);
        void HandleBuybackItem(WorldPacket & recvPacket);
        void HandleAutoBankItemOpcode(WorldPacket& recvPacket);
        void HandleAutoStoreBankItemOpcode(WorldPacket& recvPacket);
        void HandleWrapItemOpcode(WorldPacket& recvPacket);

        void HandleAttackSwingOpcode(WorldPacket& recvPacket);
        void HandleAttackStopOpcode(WorldPacket& recvPacket);
        void HandleSetSheathedOpcode(WorldPacket& recvPacket);

        void HandleUseItemOpcode(WorldPacket& recvPacket);
        void HandleOpenItemOpcode(WorldPacket& recvPacket);
        void HandleCastSpellOpcode(WorldPacket& recvPacket);
        void HandleCancelCastOpcode(WorldPacket& recvPacket);
        void HandleCancelAuraOpcode(WorldPacket& recvPacket);
        void HandleCancelGrowthAuraOpcode(WorldPacket& recvPacket);
        void HandleCancelAutoRepeatSpellOpcode(WorldPacket& recvPacket);

        void HandleLearnTalentOpcode(WorldPacket& recvPacket);
        void HandleLearnPreviewTalents(WorldPacket& recvPacket);
        void HandleTalentWipeConfirmOpcode(WorldPacket& recvPacket);
        void HandleUnlearnSkillOpcode(WorldPacket& recvPacket);

        void HandleQuestgiverStatusQueryOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverStatusMultipleQuery(WorldPacket& recvPacket);
        void HandleQuestgiverHelloOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverAcceptQuestOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverQueryQuestOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverChooseRewardOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverRequestRewardOpcode(WorldPacket& recvPacket);
        void HandleQuestQueryOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverCancel(WorldPacket& recv_data);
        void HandleQuestLogSwapQuest(WorldPacket& recv_data);
        void HandleQuestLogRemoveQuest(WorldPacket& recv_data);
        void HandleQuestConfirmAccept(WorldPacket& recv_data);
        void HandleQuestgiverCompleteQuest(WorldPacket& recv_data);
        void HandleQuestgiverQuestAutoLaunch(WorldPacket& recvPacket);
        void HandlePushQuestToParty(WorldPacket& recvPacket);
        void HandleQuestPushResult(WorldPacket& recvPacket);

        bool processChatmessageFurtherAfterSecurityChecks(std::string&, uint32);
        void HandleMessagechatOpcode(WorldPacket& recvPacket);
        void SendPlayerNotFoundNotice(std::string name);
        void SendPlayerAmbiguousNotice(std::string name);
        void SendWrongFactionNotice();
        void SendChatRestrictedNotice(ChatRestrictionType restriction);
        void HandleTextEmoteOpcode(WorldPacket& recvPacket);
        void HandleChatIgnoredOpcode(WorldPacket& recvPacket);

        void HandleReclaimCorpseOpcode(WorldPacket& recvPacket);
        void HandleCorpseQueryOpcode(WorldPacket& recvPacket);
        void HandleCorpseMapPositionQuery(WorldPacket& recvPacket);
        void HandleResurrectResponseOpcode(WorldPacket& recvPacket);
        void HandleSummonResponseOpcode(WorldPacket& recv_data);

        void HandleJoinChannel(WorldPacket& recvPacket);
        void HandleLeaveChannel(WorldPacket& recvPacket);
        void HandleChannelList(WorldPacket& recvPacket);
        void HandleChannelPassword(WorldPacket& recvPacket);
        void HandleChannelSetOwner(WorldPacket& recvPacket);
        void HandleChannelOwner(WorldPacket& recvPacket);
        void HandleChannelModerator(WorldPacket& recvPacket);
        void HandleChannelUnmoderator(WorldPacket& recvPacket);
        void HandleChannelMute(WorldPacket& recvPacket);
        void HandleChannelUnmute(WorldPacket& recvPacket);
        void HandleChannelInvite(WorldPacket& recvPacket);
        void HandleChannelKick(WorldPacket& recvPacket);
        void HandleChannelBan(WorldPacket& recvPacket);
        void HandleChannelUnban(WorldPacket& recvPacket);
        void HandleChannelAnnouncements(WorldPacket& recvPacket);
        void HandleChannelModerate(WorldPacket& recvPacket);
        void HandleChannelDeclineInvite(WorldPacket& recvPacket);
        void HandleChannelDisplayListQuery(WorldPacket& recvPacket);
        void HandleGetChannelMemberCount(WorldPacket& recvPacket);
        void HandleSetChannelWatch(WorldPacket& recvPacket);

        void HandleCompleteCinematic(WorldPacket& recvPacket);
        void HandleNextCinematicCamera(WorldPacket& recvPacket);

        void HandlePageQuerySkippedOpcode(WorldPacket& recvPacket);
        void HandlePageTextQueryOpcode(WorldPacket& recvPacket);

        void HandleTutorialFlag (WorldPacket & recv_data);
        void HandleTutorialClear(WorldPacket & recv_data);
        void HandleTutorialReset(WorldPacket & recv_data);

        //Pet
        void HandlePetAction(WorldPacket & recv_data);
        void HandlePetStopAttack(WorldPacket& recv_data);
        void HandlePetActionHelper(Unit *pet, uint64 guid1, uint16 spellid, uint16 flag, uint64 guid2);
        void HandlePetNameQuery(WorldPacket & recv_data);
        void HandlePetSetAction(WorldPacket & recv_data);
        void HandlePetAbandon(WorldPacket & recv_data);
        void HandlePetRename(WorldPacket & recv_data);
        void HandlePetCancelAuraOpcode(WorldPacket& recvPacket);
        void HandlePetUnlearnOpcode(WorldPacket& recvPacket);
        void HandlePetSpellAutocastOpcode(WorldPacket& recvPacket);
        void HandlePetCastSpellOpcode(WorldPacket& recvPacket);
        void HandlePetLearnTalent(WorldPacket& recvPacket);
        void HandleLearnPreviewTalentsPet(WorldPacket& recvPacket);

        void HandleSetActionBarToggles(WorldPacket& recv_data);

        void HandleCharRenameOpcode(WorldPacket& recv_data);
        void HandleChangePlayerNameOpcodeCallBack(QueryResult result, std::string newname);
        void HandleSetPlayerDeclinedNames(WorldPacket& recv_data);

        void HandleTotemDestroyed(WorldPacket& recv_data);
        void HandleDismissCritter(WorldPacket& recv_data);

        //Battleground
        void HandleBattlemasterHelloOpcode(WorldPacket &recv_data);
        void HandleBattlemasterJoinOpcode(WorldPacket &recv_data);
        void HandleBattlegroundPlayerPositionsOpcode(WorldPacket& recv_data);
        void HandlePVPLogDataOpcode(WorldPacket &recv_data);
        void HandleBattleFieldPortOpcode(WorldPacket &recv_data);
        void HandleBattlefieldListOpcode(WorldPacket &recv_data);
        void HandleLeaveBattlefieldOpcode(WorldPacket &recv_data);
        void HandleBattlemasterJoinArena(WorldPacket &recv_data);
        void HandleReportPvPAFK(WorldPacket &recv_data);

        void HandleWardenDataOpcode(WorldPacket& recv_data);
        void HandleWorldTeleportOpcode(WorldPacket& recv_data);
        void HandleMinimapPingOpcode(WorldPacket& recv_data);
        void HandleRandomRollOpcode(WorldPacket& recv_data);
        void HandleFarSightOpcode(WorldPacket& recv_data);
        void HandleSetDungeonDifficultyOpcode(WorldPacket& recv_data);
        void HandleSetRaidDifficultyOpcode(WorldPacket& recv_data);
        void HandleMoveSetCanFlyAckOpcode(WorldPacket& recv_data);
        void HandleSetTitleOpcode(WorldPacket& recv_data);
        void HandleRealmSplitOpcode(WorldPacket& recv_data);
        void HandleTimeSyncResp(WorldPacket& recv_data);
        void HandleWhoisOpcode(WorldPacket& recv_data);
        void HandleResetInstancesOpcode(WorldPacket& recv_data);
        void HandleHearthAndResurrect(WorldPacket& recv_data);

        // Looking for Dungeon/Raid
        void HandleLfgSetCommentOpcode(WorldPacket & recv_data);
        void HandleLfgPlayerLockInfoRequestOpcode(WorldPacket& recv_data);
        void HandleLfgPartyLockInfoRequestOpcode(WorldPacket& recv_data);
        void HandleLfgJoinOpcode(WorldPacket &recv_data);
        void HandleLfgLeaveOpcode(WorldPacket & /*recv_data*/);
        void HandleLfgSetRolesOpcode(WorldPacket &recv_data);
        void HandleLfgProposalResultOpcode(WorldPacket &recv_data);
        void HandleLfgSetBootVoteOpcode(WorldPacket &recv_data);
        void HandleLfgTeleportOpcode(WorldPacket &recv_data);
        void HandleLfrSearchOpcode(WorldPacket &recv_data);
        void HandleLfrLeaveOpcode(WorldPacket &recv_data);

        void SendLfgUpdatePlayer(LfgUpdateData& updateData);
        void SendLfgUpdateParty(LfgUpdateData& updateData);
        void SendLfgRoleChosen(uint64 guid, uint8 roles);
        void SendLfgRoleCheckUpdate(LfgRoleCheck *pRoleCheck);
        void SendLfgUpdateSearch(bool update);
        void SendLfgJoinResult(LfgJoinResultData& joinData);
        void SendLfgQueueStatus(uint32 dungeon, int32 waitTime, int32 avgWaitTime, int32 waitTimeTanks, int32 waitTimeHealer, int32 waitTimeDps, uint32 queuedTime, uint8 tanks, uint8 healers, uint8 dps);
        void SendLfgPlayerReward(uint32 rdungeonEntry, uint32 sdungeonEntry, uint8 done, const LfgReward *reward, const Quest *qRew);
        void SendLfgBootPlayer(LfgPlayerBoot *pBoot);
        void SendLfgUpdateProposal(uint32 proposalId, LfgProposal *pProp);
        void SendLfgDisabled();
        void SendLfgOfferContinue(uint32 dungeonEntry);
        void SendLfgTeleportError(uint8 err);

        // Arena Team
        void HandleInspectArenaTeamsOpcode(WorldPacket& recv_data);
        void HandleArenaTeamQueryOpcode(WorldPacket& recv_data);
        void HandleArenaTeamRosterOpcode(WorldPacket& recv_data);
        void HandleArenaTeamInviteOpcode(WorldPacket& recv_data);
        void HandleArenaTeamAcceptOpcode(WorldPacket& recv_data);
        void HandleArenaTeamDeclineOpcode(WorldPacket& recv_data);
        void HandleArenaTeamLeaveOpcode(WorldPacket& recv_data);
        void HandleArenaTeamRemoveOpcode(WorldPacket& recv_data);
        void HandleArenaTeamDisbandOpcode(WorldPacket& recv_data);
        void HandleArenaTeamLeaderOpcode(WorldPacket& recv_data);

        void HandleAreaSpiritHealerQueryOpcode(WorldPacket& recv_data);
        void HandleAreaSpiritHealerQueueOpcode(WorldPacket& recv_data);
        void HandleCancelMountAuraOpcode(WorldPacket& recv_data);
        void HandleSelfResOpcode(WorldPacket& recv_data);
        void HandleComplainOpcode(WorldPacket& recv_data);
        void HandleRequestPetInfoOpcode(WorldPacket& recv_data);

        // Socket gem
        void HandleSocketOpcode(WorldPacket& recv_data);

        void HandleCancelTempEnchantmentOpcode(WorldPacket& recv_data);

        void HandleItemRefundInfoRequest(WorldPacket& recv_data);
        void HandleItemRefund(WorldPacket& recv_data);

        void HandleChannelVoiceOnOpcode(WorldPacket & recv_data);
        void HandleVoiceSessionEnableOpcode(WorldPacket& recv_data);
        void HandleSetActiveVoiceChannel(WorldPacket& recv_data);
        void HandleSetTaxiBenchmarkOpcode(WorldPacket& recv_data);

        // Guild Bank
        void HandleGuildPermissions(WorldPacket& recv_data);
        void HandleGuildBankMoneyWithdrawn(WorldPacket& recv_data);
        void HandleGuildBankerActivate(WorldPacket& recv_data);
        void HandleGuildBankQueryTab(WorldPacket& recv_data);
        void HandleGuildBankLogQuery(WorldPacket& recv_data);
        void HandleGuildBankDepositMoney(WorldPacket& recv_data);
        void HandleGuildBankWithdrawMoney(WorldPacket& recv_data);
        void HandleGuildBankSwapItems(WorldPacket& recv_data);

        void HandleGuildBankUpdateTab(WorldPacket& recv_data);
        void HandleGuildBankBuyTab(WorldPacket& recv_data);
        void HandleQueryGuildBankTabText(WorldPacket& recv_data);
        void HandleSetGuildBankTabText(WorldPacket& recv_data);

        // Calendar
        void HandleCalendarGetCalendar(WorldPacket& recv_data);
        void HandleCalendarGetEvent(WorldPacket& recv_data);
        void HandleCalendarGuildFilter(WorldPacket& recv_data);
        void HandleCalendarArenaTeam(WorldPacket& recv_data);
        void HandleCalendarAddEvent(WorldPacket& recv_data);
        void HandleCalendarUpdateEvent(WorldPacket& recv_data);
        void HandleCalendarRemoveEvent(WorldPacket& recv_data);
        void HandleCalendarCopyEvent(WorldPacket& recv_data);
        void HandleCalendarEventInvite(WorldPacket& recv_data);
        void HandleCalendarEventRsvp(WorldPacket& recv_data);
        void HandleCalendarEventRemoveInvite(WorldPacket& recv_data);
        void HandleCalendarEventStatus(WorldPacket& recv_data);
        void HandleCalendarEventModeratorStatus(WorldPacket& recv_data);
        void HandleCalendarComplain(WorldPacket& recv_data);
        void HandleCalendarGetNumPending(WorldPacket& recv_data);

        void HandleSpellClick(WorldPacket& recv_data);
        void HandleMirrrorImageDataRequest(WorldPacket & recv_data);
        void HandleAlterAppearance(WorldPacket& recv_data);
        void HandleRemoveGlyph(WorldPacket& recv_data);
        void HandleCharCustomize(WorldPacket& recv_data);
        void HandleQueryInspectAchievements(WorldPacket& recv_data);
        void HandleEquipmentSetSave(WorldPacket& recv_data);
        void HandleEquipmentSetDelete(WorldPacket& recv_data);
        void HandleEquipmentSetUse(WorldPacket& recv_data);
        void HandleWorldStateUITimerUpdate(WorldPacket& recv_data);
        void HandleReadyForAccountDataTimes(WorldPacket& recv_data);
        void HandleQueryQuestsCompleted(WorldPacket& recv_data);
        void HandleQuestPOIQuery(WorldPacket& recv_data);
        void HandleEjectPassenger(WorldPacket &data);
        void HandleEnterPlayerVehicle(WorldPacket &data);

    private:
        void ProcessQueryCallbacks();

        ACE_Future_Set<QueryResult> m_nameQueryCallbacks;
        QueryResultFuture m_charEnumCallback;
        QueryResultFuture m_addIgnoreCallback;
        QueryResultFuture m_stablePetCallback;
        QueryCallback<std::string> m_charRenameCallback;
        QueryCallback<std::string> m_addFriendCallback;
        QueryCallback<uint32> m_unstablePetCallback;
        QueryCallback<uint32> m_stableSwapCallback;
        QueryCallback<uint64> m_sendStabledPetCallback;
        QueryResultHolderFuture m_charLoginCallback;

    private:
        // private trade methods
        void moveItems(Item* myItems[], Item* hisItems[]);

        // logging helper
        void LogUnexpectedOpcode(WorldPacket *packet, const char * reason);
        void LogUnprocessedTail(WorldPacket *packet);

        uint32 m_GUIDLow;                                   // set loggined or recently logout player (while m_playerRecentlyLogout set)
        Player *_player;
        WorldSocket *m_Socket;
        std::string m_Address;

        AccountTypes _security;
        uint32 _accountId;
        uint8 m_expansion;

        time_t _logoutTime;
        bool m_inQueue;                                     // session wait in auth.queue
        bool m_playerLoading;                               // code processed in LoginPlayer
        bool m_playerLogout;                                // code processed in LogoutPlayer
        bool m_playerRecentlyLogout;
        bool m_playerSave;
        LocaleConstant m_sessionDbcLocale;
        LocaleConstant m_sessionDbLocaleIndex;
        uint32 m_latency;
        AccountData m_accountData[NUM_ACCOUNT_DATA_TYPES];
        uint32 m_Tutorials[MAX_CHARACTER_TUTORIAL_VALUES];
        bool   m_TutorialsChanged;
        AddonsList m_addonsList;
        uint32 recruiterId;
        ACE_Based::LockedQueue<WorldPacket*, ACE_Thread_Mutex> _recvQueue;
};
#endif
/// @}
