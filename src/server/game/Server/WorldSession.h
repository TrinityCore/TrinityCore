/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "Cryptography/BigNumber.h"
#include "Opcodes.h"
#include "AccountMgr.h"

class Creature;
class GameObject;
class InstanceSave;
class Item;
class LoginQueryHolder;
class Object;
class Player;
class Quest;
class SpellCastTargets;
class Unit;
class Warden;
class WorldPacket;
class WorldSocket;
struct AreaTableEntry;
struct AuctionEntry;
struct DeclinedName;
struct ItemTemplate;
struct MovementInfo;

namespace lfg
{
struct LfgJoinResultData;
struct LfgPlayerBoot;
struct LfgProposal;
struct LfgQueueStatusData;
struct LfgPlayerRewardData;
struct LfgRoleCheck;
struct LfgUpdateData;
}

namespace rbac
{
class RBACData;
}

enum AccountDataType
{
    GLOBAL_CONFIG_CACHE             = 0,                    // 0x01 g
    PER_CHARACTER_CONFIG_CACHE      = 1,                    // 0x02 p
    GLOBAL_BINDINGS_CACHE           = 2,                    // 0x04 g
    PER_CHARACTER_BINDINGS_CACHE    = 3,                    // 0x08 p
    GLOBAL_MACROS_CACHE             = 4,                    // 0x10 g
    PER_CHARACTER_MACROS_CACHE      = 5,                    // 0x20 p
    PER_CHARACTER_LAYOUT_CACHE      = 6,                    // 0x40 p
    PER_CHARACTER_CHAT_CACHE        = 7                     // 0x80 p
};

#define NUM_ACCOUNT_DATA_TYPES        8

#define GLOBAL_CACHE_MASK           0x15
#define PER_CHARACTER_CACHE_MASK    0xEA

#define REGISTERED_ADDON_PREFIX_SOFTCAP 64

struct AccountData
{
    AccountData() : Time(0), Data("") { }

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

enum BFLeaveReason
{
    BF_LEAVE_REASON_CLOSE     = 0x00000001,
    //BF_LEAVE_REASON_UNK1      = 0x00000002, (not used)
    //BF_LEAVE_REASON_UNK2      = 0x00000004, (not used)
    BF_LEAVE_REASON_EXITED    = 0x00000008,
    BF_LEAVE_REASON_LOW_LEVEL = 0x00000010
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
    GUILD_CHARTER_TYPE                            = 4,
    ARENA_TEAM_CHARTER_2v2_TYPE                   = 2,
    ARENA_TEAM_CHARTER_3v3_TYPE                   = 3,
    ARENA_TEAM_CHARTER_5v5_TYPE                   = 5,
};

#define DB2_REPLY_SPARSE 2442913102
#define DB2_REPLY_ITEM   1344507586

//class to deal with packet processing
//allows to determine if next packet is safe to be processed
class PacketFilter
{
public:
    explicit PacketFilter(WorldSession* pSession) : m_pSession(pSession) { }
    virtual ~PacketFilter() { }

    virtual bool Process(WorldPacket* /*packet*/) { return true; }
    virtual bool ProcessLogout() const { return true; }
    static Opcodes DropHighBytes(Opcodes opcode) { return Opcodes(opcode & 0xFFFF); }

protected:
    WorldSession* const m_pSession;

private:
    PacketFilter(PacketFilter const& right) = delete;
    PacketFilter& operator=(PacketFilter const& right) = delete;
};
//process only thread-safe packets in Map::Update()
class MapSessionFilter : public PacketFilter
{
public:
    explicit MapSessionFilter(WorldSession* pSession) : PacketFilter(pSession) { }
    ~MapSessionFilter() { }

    virtual bool Process(WorldPacket* packet);
    //in Map::Update() we do not process player logout!
    virtual bool ProcessLogout() const { return false; }
};

//class used to filer only thread-unsafe packets from queue
//in order to update only be used in World::UpdateSessions()
class WorldSessionFilter : public PacketFilter
{
public:
    explicit WorldSessionFilter(WorldSession* pSession) : PacketFilter(pSession) { }
    ~WorldSessionFilter() { }

    virtual bool Process(WorldPacket* packet);
};

// Proxy structure to contain data passed to callback function,
// only to prevent bloating the parameter list
class CharacterCreateInfo
{
    friend class WorldSession;
    friend class Player;

    protected:
        CharacterCreateInfo(std::string const& name, uint8 race, uint8 cclass, uint8 gender, uint8 skin, uint8 face, uint8 hairStyle, uint8 hairColor, uint8 facialHair, uint8 outfitId,
        WorldPacket& data) : Name(name), Race(race), Class(cclass), Gender(gender), Skin(skin), Face(face), HairStyle(hairStyle), HairColor(hairColor), FacialHair(facialHair),
        OutfitId(outfitId), Data(data), CharCount(0)
        { }

        /// User specified variables
        std::string Name;
        uint8 Race;
        uint8 Class;
        uint8 Gender;
        uint8 Skin;
        uint8 Face;
        uint8 HairStyle;
        uint8 HairColor;
        uint8 FacialHair;
        uint8 OutfitId;
        WorldPacket Data;

        /// Server side data
        uint8 CharCount;
};

/// Player session in the World
class WorldSession
{
    public:
        WorldSession(uint32 id, WorldSocket* sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter);
        ~WorldSession();

        bool PlayerLoading() const { return m_playerLoading; }
        bool PlayerLogout() const { return m_playerLogout; }
        bool PlayerLogoutWithSave() const { return m_playerLogout && m_playerSave; }
        bool PlayerRecentlyLoggedOut() const { return m_playerRecentlyLogout; }

        void ReadAddonsInfo(WorldPacket& data);
        void SendAddonsInfo();
        bool IsAddonRegistered(const std::string& prefix) const;

        void SendPacket(WorldPacket const* packet, bool forced = false);
        void SendNotification(const char *format, ...) ATTR_PRINTF(2, 3);
        void SendNotification(uint32 string_id, ...);
        void SendPetNameInvalid(uint32 error, std::string const& name, DeclinedName *declinedName);
        void SendPartyResult(PartyOperation operation, std::string const& member, PartyResult res, uint32 val = 0);
        void SendAreaTriggerMessage(const char* Text, ...) ATTR_PRINTF(2, 3);
        void SendSetPhaseShift(std::set<uint32> const& phaseIds, std::set<uint32> const& terrainswaps);
        void SendQueryTimeResponse();

        void SendAuthResponse(uint8 code, bool queued, uint32 queuePos = 0);
        void SendClientCacheVersion(uint32 version);

        rbac::RBACData* GetRBACData();
        bool HasPermission(uint32 permissionId);
        void LoadPermissions();
        void InvalidateRBACData(); // Used to force LoadPermissions at next HasPermission check

        AccountTypes GetSecurity() const { return _security; }
        uint32 GetAccountId() const { return _accountId; }
        Player* GetPlayer() const { return _player; }
        std::string const& GetPlayerName() const;
        std::string GetPlayerInfo() const;

        uint32 GetGuidLow() const;
        void SetSecurity(AccountTypes security) { _security = security; }
        std::string const& GetRemoteAddress() { return m_Address; }
        void SetPlayer(Player* player);
        uint8 Expansion() const { return m_expansion; }

        void InitWarden(BigNumber* k, std::string const& os);

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

        void LogoutPlayer(bool save);
        void KickPlayer();

        void QueuePacket(WorldPacket* new_packet);
        bool Update(uint32 diff, PacketFilter& updater);

        /// Handle the authentication waiting queue (to be completed)
        void SendAuthWaitQue(uint32 position);

        //void SendTestCreatureQueryOpcode(uint32 entry, uint64 guid, uint32 testvalue);
        void SendNameQueryOpcode(uint64 guid);

        bool CanOpenMailBox(uint64 guid);

        void SendTrainerList(uint64 guid);
        void SendTrainerList(uint64 guid, std::string const& strTitle);
        void SendListInventory(uint64 guid);
        void SendShowBank(uint64 guid);
        void SendTabardVendorActivate(uint64 guid);
        void SendSpiritResurrect();
        void SendBindPoint(Creature* npc);

        void SendAttackStop(Unit const* enemy);

        void SendBattleGroundList(uint64 guid, BattlegroundTypeId bgTypeId = BATTLEGROUND_RB);

        void SendTradeStatus(TradeStatus status);
        void SendUpdateTrade(bool trader_data = true);
        void SendCancelTrade();

        void SendPetitionQueryOpcode(uint64 petitionguid);

        // Spell
        void HandleClientCastFlags(WorldPacket& recvPacket, uint8 castFlags, SpellCastTargets & targets);

        // Pet
        void SendPetNameQuery(uint64 guid, uint32 petnumber);
        void SendStablePet(uint64 guid);
        void SendStablePetCallback(PreparedQueryResult result, uint64 guid);
        void SendStableResult(uint8 guid);
        bool CheckStableMaster(uint64 guid);

        // Account Data
        AccountData* GetAccountData(AccountDataType type) { return &m_accountData[type]; }
        void SetAccountData(AccountDataType type, time_t tm, std::string const& data);
        void SendAccountDataTimes(uint32 mask);
        void LoadGlobalAccountData();
        void LoadAccountData(PreparedQueryResult result, uint32 mask);

        void LoadTutorialsData();
        void SendTutorialsData();
        void SaveTutorialsData(SQLTransaction& trans);
        uint32 GetTutorialInt(uint8 index) const { return m_Tutorials[index]; }
        void SetTutorialInt(uint8 index, uint32 value)
        {
            if (m_Tutorials[index] != value)
            {
                m_Tutorials[index] = value;
                m_TutorialsChanged = true;
            }
        }
        //used with item_page table
        bool SendItemInfo(uint32 itemid, WorldPacket data);
        //auction
        void SendAuctionHello(uint64 guid, Creature* unit);
        void SendAuctionCommandResult(AuctionEntry* auction, uint32 Action, uint32 ErrorCode, uint32 bidError = 0);
        void SendAuctionBidderNotification(uint32 location, uint32 auctionId, uint64 bidder, uint32 bidSum, uint32 diff, uint32 item_template);
        void SendAuctionOwnerNotification(AuctionEntry* auction);
        void SendAuctionRemovedNotification(uint32 auctionId, uint32 itemEntry, int32 randomPropertyId);

        //Item Enchantment
        void SendEnchantmentLog(uint64 target, uint64 caster, uint32 itemId, uint32 enchantId);
        void SendItemEnchantTimeUpdate(uint64 Playerguid, uint64 Itemguid, uint32 slot, uint32 Duration);

        //Taxi
        void SendTaxiStatus(uint64 guid);
        void SendTaxiMenu(Creature* unit);
        void SendDoFlight(uint32 mountDisplayId, uint32 path, uint32 pathNode = 0);
        bool SendLearnNewTaxiNode(Creature* unit);
        void SendDiscoverNewTaxiNode(uint32 nodeid);

        // Guild/Arena Team
        void SendArenaTeamCommandResult(uint32 team_action, std::string const& team, std::string const& player, uint32 error_id = 0);
        void SendNotInArenaTeamPacket(uint8 type);
        void SendPetitionShowList(uint64 guid);

        void BuildPartyMemberStatsChangedPacket(Player* player, WorldPacket* data);

        void DoLootRelease(uint64 lguid);

        // Account mute time
        time_t m_muteTime;

        // Locales
        LocaleConstant GetSessionDbcLocale() const { return m_sessionDbcLocale; }
        LocaleConstant GetSessionDbLocaleIndex() const { return m_sessionDbLocaleIndex; }
        const char *GetTrinityString(int32 entry) const;

        uint32 GetLatency() const { return m_latency; }
        void SetLatency(uint32 latency) { m_latency = latency; }
        void ResetClientTimeDelay() { m_clientTimeDelay = 0; }

        ACE_Atomic_Op<ACE_Thread_Mutex, time_t> m_timeOutTime;
        void UpdateTimeOutTime(uint32 diff)
        {
            if (time_t(diff) > m_timeOutTime.value())
                m_timeOutTime = 0;
            else
                m_timeOutTime -= diff;
        }
        void ResetTimeOutTime() { m_timeOutTime = sWorld->getIntConfig(CONFIG_SOCKET_TIMEOUTTIME); }
        bool IsConnectionIdle() const { return (m_timeOutTime <= 0 && !m_inQueue); }

        // Recruit-A-Friend Handling
        uint32 GetRecruiterId() const { return recruiterId; }
        bool IsARecruiter() const { return isRecruiter; }

        z_stream_s* GetCompressionStream() { return _compressionStream; }

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPacket& recvPacket);          // not used
        void Handle_EarlyProccess(WorldPacket& recvPacket); // just mark packets processed in WorldSocket::OnRead
        void Handle_ServerSide(WorldPacket& recvPacket);    // sever side only, can't be accepted from client
        void Handle_Deprecated(WorldPacket& recvPacket);    // never used anymore by client

        void HandleCharEnumOpcode(WorldPacket& recvPacket);
        void HandleCharDeleteOpcode(WorldPacket& recvPacket);
        void HandleCharCreateOpcode(WorldPacket& recvPacket);
        void HandleCharCreateCallback(PreparedQueryResult result, CharacterCreateInfo* createInfo);
        void HandlePlayerLoginOpcode(WorldPacket& recvPacket);
        void HandleLoadScreenOpcode(WorldPacket& recvPacket);
        void HandleCharEnum(PreparedQueryResult result);
        void HandlePlayerLogin(LoginQueryHolder * holder);
        void HandleCharFactionOrRaceChange(WorldPacket& recvData);
        void HandleRandomizeCharNameOpcode(WorldPacket& recvData);
        void HandleReorderCharacters(WorldPacket& recvData);
        void HandleOpeningCinematic(WorldPacket& recvData);

        // played time
        void HandlePlayedTime(WorldPacket& recvPacket);

        // new
        void HandleMoveUnRootAck(WorldPacket& recvPacket);
        void HandleMoveRootAck(WorldPacket& recvPacket);
        void HandleLookingForGroup(WorldPacket& recvPacket);
        void HandleReturnToGraveyard(WorldPacket& recvPacket);

        // new inspect
        void HandleInspectOpcode(WorldPacket& recvPacket);

        // new party stats
        void HandleInspectHonorStatsOpcode(WorldPacket& recvPacket);

        void HandleMoveWaterWalkAck(WorldPacket& recvPacket);
        void HandleFeatherFallAck(WorldPacket& recvData);

        void HandleMoveHoverAck(WorldPacket& recvData);

        void HandleMountSpecialAnimOpcode(WorldPacket& recvdata);

        // character view
        void HandleShowingHelmOpcode(WorldPacket& recvData);
        void HandleShowingCloakOpcode(WorldPacket& recvData);

        // repair
        void HandleRepairItemOpcode(WorldPacket& recvPacket);

        // Knockback
        void HandleMoveKnockBackAck(WorldPacket& recvPacket);

        void HandleMoveTeleportAck(WorldPacket& recvPacket);
        void HandleForceSpeedChangeAck(WorldPacket& recvData);
        void HandleSetCollisionHeightAck(WorldPacket& recvPacket);

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
        void HandleGMSurveySubmit(WorldPacket& recvPacket);
        void HandleReportLag(WorldPacket& recvPacket);
        void HandleGMResponseResolve(WorldPacket& recvPacket);

        void HandleTogglePvP(WorldPacket& recvPacket);

        void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
        void HandleSetSelectionOpcode(WorldPacket& recvPacket);
        void HandleStandStateChangeOpcode(WorldPacket& recvPacket);
        void HandleEmoteOpcode(WorldPacket& recvPacket);
        void HandleContactListOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcodeCallBack(PreparedQueryResult result, std::string const& friendNote);
        void HandleDelFriendOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcodeCallBack(PreparedQueryResult result);
        void HandleDelIgnoreOpcode(WorldPacket& recvPacket);
        void HandleSetContactNotesOpcode(WorldPacket& recvPacket);
        void HandleBugOpcode(WorldPacket& recvPacket);

        void HandleAreaTriggerOpcode(WorldPacket& recvPacket);

        void HandleSetFactionAtWar(WorldPacket& recvData);
        void HandleSetFactionCheat(WorldPacket& recvData);
        void HandleSetWatchedFactionOpcode(WorldPacket& recvData);
        void HandleSetFactionInactiveOpcode(WorldPacket& recvData);

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
        void HandleSetActiveMoverOpcode(WorldPacket& recvData);
        void HandleMoveNotActiveMover(WorldPacket& recvData);
        void HandleDismissControlledVehicle(WorldPacket& recvData);
        void HandleRequestVehicleExit(WorldPacket& recvData);
        void HandleChangeSeatsOnControlledVehicle(WorldPacket& recvData);
        void HandleMoveTimeSkippedOpcode(WorldPacket& recvData);

        void HandleRequestRaidInfoOpcode(WorldPacket& recvData);

        void HandleBattlefieldStatusOpcode(WorldPacket& recvData);
        void HandleBattleMasterHelloOpcode(WorldPacket& recvData);

        void HandleGroupInviteOpcode(WorldPacket& recvPacket);
        //void HandleGroupCancelOpcode(WorldPacket& recvPacket);
        void HandleGroupInviteResponseOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteGuidOpcode(WorldPacket& recvPacket);
        void HandleGroupSetLeaderOpcode(WorldPacket& recvPacket);
        void HandleGroupSetRolesOpcode(WorldPacket& recvData);
        void HandleGroupDisbandOpcode(WorldPacket& recvPacket);
        void HandleOptOutOfLootOpcode(WorldPacket& recvData);
        void HandleLootMethodOpcode(WorldPacket& recvPacket);
        void HandleLootRoll(WorldPacket& recvData);
        void HandleRequestPartyMemberStatsOpcode(WorldPacket& recvData);
        void HandleRaidTargetUpdateOpcode(WorldPacket& recvData);
        void HandleRaidReadyCheckOpcode(WorldPacket& recvData);
        void HandleRaidReadyCheckFinishedOpcode(WorldPacket& recvData);
        void HandleGroupRaidConvertOpcode(WorldPacket& recvData);
        void HandleGroupChangeSubGroupOpcode(WorldPacket& recvData);
        void HandleGroupSwapSubGroupOpcode(WorldPacket& recvData);
        void HandleGroupAssistantLeaderOpcode(WorldPacket& recvData);
        void HandlePartyAssignmentOpcode(WorldPacket& recvData);

        void HandlePetitionBuyOpcode(WorldPacket& recvData);
        void HandlePetitionShowSignOpcode(WorldPacket& recvData);
        void HandlePetitionQueryOpcode(WorldPacket& recvData);
        void HandlePetitionRenameOpcode(WorldPacket& recvData);
        void HandlePetitionSignOpcode(WorldPacket& recvData);
        void HandlePetitionDeclineOpcode(WorldPacket& recvData);
        void HandleOfferPetitionOpcode(WorldPacket& recvData);
        void HandleTurnInPetitionOpcode(WorldPacket& recvData);

        void HandleGuildQueryOpcode(WorldPacket& recvPacket);
        void HandleGuildInviteOpcode(WorldPacket& recvPacket);
        void HandleGuildRemoveOpcode(WorldPacket& recvPacket);
        void HandleGuildAcceptOpcode(WorldPacket& recvPacket);
        void HandleGuildDeclineOpcode(WorldPacket& recvPacket);
        void HandleGuildEventLogQueryOpcode(WorldPacket& recvPacket);
        void HandleGuildRosterOpcode(WorldPacket& recvPacket);
        void HandleGuildRewardsQueryOpcode(WorldPacket& recvPacket);
        void HandleGuildPromoteOpcode(WorldPacket& recvPacket);
        void HandleGuildDemoteOpcode(WorldPacket& recvPacket);
        void HandleGuildAssignRankOpcode(WorldPacket& recvPacket);
        void HandleGuildLeaveOpcode(WorldPacket& recvPacket);
        void HandleGuildDisbandOpcode(WorldPacket& recvPacket);
        void HandleGuildSetGuildMaster(WorldPacket& recvPacket);
        void HandleGuildMOTDOpcode(WorldPacket& recvPacket);
        void HandleGuildNewsUpdateStickyOpcode(WorldPacket& recvPacket);
        void HandleGuildSetNoteOpcode(WorldPacket& recvPacket);
        void HandleGuildQueryRanksOpcode(WorldPacket& recvPacket);
        void HandleGuildQueryNewsOpcode(WorldPacket& recvPacket);
        void HandleGuildSetRankPermissionsOpcode(WorldPacket& recvPacket);
        void HandleGuildAddRankOpcode(WorldPacket& recvPacket);
        void HandleGuildDelRankOpcode(WorldPacket& recvPacket);
        void HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket);
        void HandleSaveGuildEmblemOpcode(WorldPacket& recvPacket);
        void HandleGuildRequestPartyState(WorldPacket& recvPacket);
        void HandleGuildRequestMaxDailyXP(WorldPacket& recvPacket);
        void HandleAutoDeclineGuildInvites(WorldPacket& recvPacket);

        void HandleGuildFinderAddRecruit(WorldPacket& recvPacket);
        void HandleGuildFinderBrowse(WorldPacket& recvPacket);
        void HandleGuildFinderDeclineRecruit(WorldPacket& recvPacket);
        void HandleGuildFinderGetApplications(WorldPacket& recvPacket);
        void HandleGuildFinderGetRecruits(WorldPacket& recvPacket);
        void HandleGuildFinderPostRequest(WorldPacket& recvPacket);
        void HandleGuildFinderRemoveRecruit(WorldPacket& recvPacket);
        void HandleGuildFinderSetGuildPost(WorldPacket& recvPacket);

        void HandleTaxiNodeStatusQueryOpcode(WorldPacket& recvPacket);
        void HandleTaxiQueryAvailableNodes(WorldPacket& recvPacket);
        void HandleActivateTaxiOpcode(WorldPacket& recvPacket);
        void HandleActivateTaxiExpressOpcode(WorldPacket& recvPacket);
        void HandleMoveSplineDoneOpcode(WorldPacket& recvPacket);
        void SendActivateTaxiReply(ActivateTaxiReply reply);

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
        void HandleStablePetCallback(PreparedQueryResult result);
        void HandleUnstablePet(WorldPacket& recvPacket);
        void HandleUnstablePetCallback(PreparedQueryResult result, uint32 petId);
        void HandleBuyStableSlot(WorldPacket& recvPacket);
        void HandleStableRevivePet(WorldPacket& recvPacket);
        void HandleStableSwapPet(WorldPacket& recvPacket);
        void HandleStableSwapPetCallback(PreparedQueryResult result, uint32 petId);
        void SendTrainerBuyFailed(uint64 guid, uint32 spellId, uint32 reason);

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
        void HandleAuctionListItems(WorldPacket& recvData);
        void HandleAuctionListBidderItems(WorldPacket& recvData);
        void HandleAuctionSellItem(WorldPacket& recvData);
        void HandleAuctionRemoveItem(WorldPacket& recvData);
        void HandleAuctionListOwnerItems(WorldPacket& recvData);
        void HandleAuctionPlaceBid(WorldPacket& recvData);
        void HandleAuctionListPendingSales(WorldPacket& recvData);

        void HandleGetMailList(WorldPacket& recvData);
        void HandleSendMail(WorldPacket& recvData);
        void HandleMailTakeMoney(WorldPacket& recvData);
        void HandleMailTakeItem(WorldPacket& recvData);
        void HandleMailMarkAsRead(WorldPacket& recvData);
        void HandleMailReturnToSender(WorldPacket& recvData);
        void HandleMailDelete(WorldPacket& recvData);
        void HandleItemTextQuery(WorldPacket& recvData);
        void HandleMailCreateTextItem(WorldPacket& recvData);
        void HandleQueryNextMailTime(WorldPacket& recvData);
        void HandleCancelChanneling(WorldPacket& recvData);
        void SendShowMailBox(uint64 guid);

        void SendItemPageInfo(ItemTemplate* itemProto);
        void HandleSplitItemOpcode(WorldPacket& recvPacket);
        void HandleSwapInvItemOpcode(WorldPacket& recvPacket);
        void HandleDestroyItemOpcode(WorldPacket& recvPacket);
        void HandleAutoEquipItemOpcode(WorldPacket& recvPacket);
        void HandleSellItemOpcode(WorldPacket& recvPacket);
        void HandleBuyItemInSlotOpcode(WorldPacket& recvPacket);
        void HandleBuyItemOpcode(WorldPacket& recvPacket);
        void HandleListInventoryOpcode(WorldPacket& recvPacket);
        void HandleAutoStoreBagItemOpcode(WorldPacket& recvPacket);
        void HandleReadItem(WorldPacket& recvPacket);
        void HandleAutoEquipItemSlotOpcode(WorldPacket& recvPacket);
        void HandleSwapItem(WorldPacket& recvPacket);
        void HandleBuybackItem(WorldPacket& recvPacket);
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
        void HandleQuestgiverCancel(WorldPacket& recvData);
        void HandleQuestLogSwapQuest(WorldPacket& recvData);
        void HandleQuestLogRemoveQuest(WorldPacket& recvData);
        void HandleQuestConfirmAccept(WorldPacket& recvData);
        void HandleQuestgiverCompleteQuest(WorldPacket& recvData);
        void HandleQuestgiverQuestAutoLaunch(WorldPacket& recvPacket);
        void HandlePushQuestToParty(WorldPacket& recvPacket);
        void HandleQuestPushResult(WorldPacket& recvPacket);

        void HandleMessagechatOpcode(WorldPacket& recvPacket);
        void HandleAddonMessagechatOpcode(WorldPacket& recvPacket);
        void SendPlayerNotFoundNotice(std::string const& name);
        void SendPlayerAmbiguousNotice(std::string const& name);
        void SendWrongFactionNotice();
        void SendChatRestrictedNotice(ChatRestrictionType restriction);
        void HandleTextEmoteOpcode(WorldPacket& recvPacket);
        void HandleChatIgnoredOpcode(WorldPacket& recvPacket);

        void HandleUnregisterAddonPrefixesOpcode(WorldPacket& recvPacket);
        void HandleAddonRegisteredPrefixesOpcode(WorldPacket& recvPacket);

        void HandleReclaimCorpseOpcode(WorldPacket& recvPacket);
        void HandleCorpseQueryOpcode(WorldPacket& recvPacket);
        void HandleCorpseMapPositionQuery(WorldPacket& recvPacket);
        void HandleResurrectResponseOpcode(WorldPacket& recvPacket);
        void HandleSummonResponseOpcode(WorldPacket& recvData);

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

        void HandlePageTextQueryOpcode(WorldPacket& recvPacket);

        void HandleTutorialFlag (WorldPacket& recvData);
        void HandleTutorialClear(WorldPacket& recvData);
        void HandleTutorialReset(WorldPacket& recvData);

        //Pet
        void HandlePetAction(WorldPacket& recvData);
        void HandlePetStopAttack(WorldPacket& recvData);
        void HandlePetActionHelper(Unit* pet, uint64 guid1, uint32 spellid, uint16 flag, uint64 guid2, float x, float y, float z);
        void HandlePetNameQuery(WorldPacket& recvData);
        void HandlePetSetAction(WorldPacket& recvData);
        void HandlePetAbandon(WorldPacket& recvData);
        void HandlePetRename(WorldPacket& recvData);
        void HandlePetCancelAuraOpcode(WorldPacket& recvPacket);
        void HandlePetSpellAutocastOpcode(WorldPacket& recvPacket);
        void HandlePetCastSpellOpcode(WorldPacket& recvPacket);
        void HandlePetLearnTalent(WorldPacket& recvPacket);
        void HandleLearnPreviewTalentsPet(WorldPacket& recvPacket);

        void HandleSetActionBarToggles(WorldPacket& recvData);

        void HandleCharRenameOpcode(WorldPacket& recvData);
        void HandleChangePlayerNameOpcodeCallBack(PreparedQueryResult result, std::string const& newName);
        void HandleSetPlayerDeclinedNames(WorldPacket& recvData);

        void HandleTotemDestroyed(WorldPacket& recvData);
        void HandleDismissCritter(WorldPacket& recvData);

        //Battleground
        void HandleBattlemasterHelloOpcode(WorldPacket& recvData);
        void HandleBattlemasterJoinOpcode(WorldPacket& recvData);
        void HandleBattlegroundPlayerPositionsOpcode(WorldPacket& recvData);
        void HandlePVPLogDataOpcode(WorldPacket& recvData);
        void HandleBattleFieldPortOpcode(WorldPacket& recvData);
        void HandleBattlefieldListOpcode(WorldPacket& recvData);
        void HandleBattlefieldLeaveOpcode(WorldPacket& recvData);
        void HandleBattlemasterJoinArena(WorldPacket& recvData);
        void HandleReportPvPAFK(WorldPacket& recvData);
        void HandleRequestRatedBgInfo(WorldPacket& recvData);
        void HandleRequestPvpOptions(WorldPacket& recvData);
        void HandleRequestPvpReward(WorldPacket& recvData);
        void HandleRequestRatedBgStats(WorldPacket& recvData);

        // Battlefield
        void SendBfInvitePlayerToWar(uint64 guid, uint32 zoneId, uint32 time);
        void SendBfInvitePlayerToQueue(uint64 guid);
        void SendBfQueueInviteResponse(uint64 guid, uint32 zoneId, bool canQueue = true, bool full = false);
        void SendBfEntered(uint64 guid);
        void SendBfLeaveMessage(uint64 guid, BFLeaveReason reason = BF_LEAVE_REASON_EXITED);
        void HandleBfQueueInviteResponse(WorldPacket& recvData);
        void HandleBfEntryInviteResponse(WorldPacket& recvData);
        void HandleBfExitRequest(WorldPacket& recvData);

        void HandleWardenDataOpcode(WorldPacket& recvData);
        void HandleWorldTeleportOpcode(WorldPacket& recvData);
        void HandleMinimapPingOpcode(WorldPacket& recvData);
        void HandleRandomRollOpcode(WorldPacket& recvData);
        void HandleFarSightOpcode(WorldPacket& recvData);
        void HandleSetDungeonDifficultyOpcode(WorldPacket& recvData);
        void HandleSetRaidDifficultyOpcode(WorldPacket& recvData);
        void HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData);
        void HandleSetTitleOpcode(WorldPacket& recvData);
        void HandleRealmSplitOpcode(WorldPacket& recvData);
        void HandleTimeSyncResp(WorldPacket& recvData);
        void HandleWhoisOpcode(WorldPacket& recvData);
        void HandleResetInstancesOpcode(WorldPacket& recvData);
        void HandleHearthAndResurrect(WorldPacket& recvData);
        void HandleInstanceLockResponse(WorldPacket& recvPacket);

        // Looking for Dungeon/Raid
        void HandleLfgSetCommentOpcode(WorldPacket& recvData);
        void HandleLfgGetLockInfoOpcode(WorldPacket& recvData);
        void SendLfgPlayerLockInfo();
        void SendLfgPartyLockInfo();
        void HandleLfgJoinOpcode(WorldPacket& recvData);
        void HandleLfgLeaveOpcode(WorldPacket& recvData);
        void HandleLfgSetRolesOpcode(WorldPacket& recvData);
        void HandleLfgProposalResultOpcode(WorldPacket& recvData);
        void HandleLfgSetBootVoteOpcode(WorldPacket& recvData);
        void HandleLfgTeleportOpcode(WorldPacket& recvData);
        void HandleLfrJoinOpcode(WorldPacket& recvData);
        void HandleLfrLeaveOpcode(WorldPacket& recvData);
        void HandleLfgGetStatus(WorldPacket& recvData);

        void SendLfgUpdateStatus(lfg::LfgUpdateData const& updateData, bool party);
        void SendLfgRoleChosen(uint64 guid, uint8 roles);
        void SendLfgRoleCheckUpdate(lfg::LfgRoleCheck const& pRoleCheck);
        void SendLfgLfrList(bool update);
        void SendLfgJoinResult(lfg::LfgJoinResultData const& joinData);
        void SendLfgQueueStatus(lfg::LfgQueueStatusData const& queueData);
        void SendLfgPlayerReward(lfg::LfgPlayerRewardData const& lfgPlayerRewardData);
        void SendLfgBootProposalUpdate(lfg::LfgPlayerBoot const& boot);
        void SendLfgUpdateProposal(lfg::LfgProposal const& proposal);
        void SendLfgDisabled();
        void SendLfgOfferContinue(uint32 dungeonEntry);
        void SendLfgTeleportError(uint8 err);

        // Arena Team
        void HandleInspectArenaTeamsOpcode(WorldPacket& recvData);
        void HandleArenaTeamQueryOpcode(WorldPacket& recvData);
        void HandleArenaTeamRosterOpcode(WorldPacket& recvData);
        void HandleArenaTeamCreateOpcode(WorldPacket& recvData);
        void HandleArenaTeamInviteOpcode(WorldPacket& recvData);
        void HandleArenaTeamAcceptOpcode(WorldPacket& recvData);
        void HandleArenaTeamDeclineOpcode(WorldPacket& recvData);
        void HandleArenaTeamLeaveOpcode(WorldPacket& recvData);
        void HandleArenaTeamRemoveOpcode(WorldPacket& recvData);
        void HandleArenaTeamDisbandOpcode(WorldPacket& recvData);
        void HandleArenaTeamLeaderOpcode(WorldPacket& recvData);

        void HandleAreaSpiritHealerQueryOpcode(WorldPacket& recvData);
        void HandleAreaSpiritHealerQueueOpcode(WorldPacket& recvData);
        void HandleCancelMountAuraOpcode(WorldPacket& recvData);
        void HandleSelfResOpcode(WorldPacket& recvData);
        void HandleComplainOpcode(WorldPacket& recvData);
        void HandleRequestPetInfoOpcode(WorldPacket& recvData);

        // Socket gem
        void HandleSocketOpcode(WorldPacket& recvData);

        void HandleCancelTempEnchantmentOpcode(WorldPacket& recvData);

        void HandleItemRefundInfoRequest(WorldPacket& recvData);
        void HandleItemRefund(WorldPacket& recvData);

        void HandleChannelVoiceOnOpcode(WorldPacket& recvData);
        void HandleVoiceSessionEnableOpcode(WorldPacket& recvData);
        void HandleSetActiveVoiceChannel(WorldPacket& recvData);
        void HandleSetTaxiBenchmarkOpcode(WorldPacket& recvData);

        // Guild Bank
        void HandleGuildPermissions(WorldPacket& recvData);
        void HandleGuildBankMoneyWithdrawn(WorldPacket& recvData);
        void HandleGuildBankerActivate(WorldPacket& recvData);
        void HandleGuildBankQueryTab(WorldPacket& recvData);
        void HandleGuildBankLogQuery(WorldPacket& recvData);
        void HandleGuildBankDepositMoney(WorldPacket& recvData);
        void HandleGuildBankWithdrawMoney(WorldPacket& recvData);
        void HandleGuildBankSwapItems(WorldPacket& recvData);

        void HandleGuildBankUpdateTab(WorldPacket& recvData);
        void HandleGuildBankBuyTab(WorldPacket& recvData);
        void HandleQueryGuildBankTabText(WorldPacket& recvData);
        void HandleSetGuildBankTabText(WorldPacket& recvData);
        void HandleGuildQueryXPOpcode(WorldPacket& recvData);

        // Refer-a-Friend
        void HandleGrantLevel(WorldPacket& recvData);
        void HandleAcceptGrantLevel(WorldPacket& recvData);

        // Calendar
        void HandleCalendarGetCalendar(WorldPacket& recvData);
        void HandleCalendarGetEvent(WorldPacket& recvData);
        void HandleCalendarGuildFilter(WorldPacket& recvData);
        void HandleCalendarArenaTeam(WorldPacket& recvData);
        void HandleCalendarAddEvent(WorldPacket& recvData);
        void HandleCalendarUpdateEvent(WorldPacket& recvData);
        void HandleCalendarRemoveEvent(WorldPacket& recvData);
        void HandleCalendarCopyEvent(WorldPacket& recvData);
        void HandleCalendarEventInvite(WorldPacket& recvData);
        void HandleCalendarEventRsvp(WorldPacket& recvData);
        void HandleCalendarEventRemoveInvite(WorldPacket& recvData);
        void HandleCalendarEventStatus(WorldPacket& recvData);
        void HandleCalendarEventModeratorStatus(WorldPacket& recvData);
        void HandleCalendarComplain(WorldPacket& recvData);
        void HandleCalendarGetNumPending(WorldPacket& recvData);
        void HandleCalendarEventSignup(WorldPacket& recvData);

        void SendCalendarRaidLockout(InstanceSave const* save, bool add);
        void SendCalendarRaidLockoutUpdated(InstanceSave const* save);
        void HandleSetSavedInstanceExtend(WorldPacket& recvData);

        // Void Storage
        void HandleVoidStorageUnlock(WorldPacket& recvData);
        void HandleVoidStorageQuery(WorldPacket& recvData);
        void HandleVoidStorageTransfer(WorldPacket& recvData);
        void HandleVoidSwapItem(WorldPacket& recvData);
        void SendVoidStorageTransferResult(VoidTransferError result);

        // Transmogrification
        void HandleTransmogrifyItems(WorldPacket& recvData);

        // Reforge
        void HandleReforgeItemOpcode(WorldPacket& recvData);
        void SendReforgeResult(bool success);

        // Miscellaneous
        void HandleSpellClick(WorldPacket& recvData);
        void HandleMirrorImageDataRequest(WorldPacket& recvData);
        void HandleAlterAppearance(WorldPacket& recvData);
        void HandleRemoveGlyph(WorldPacket& recvData);
        void HandleCharCustomize(WorldPacket& recvData);
        void HandleQueryInspectAchievements(WorldPacket& recvData);
        void HandleGuildAchievementProgressQuery(WorldPacket& recvData);
        void HandleEquipmentSetSave(WorldPacket& recvData);
        void HandleEquipmentSetDelete(WorldPacket& recvData);
        void HandleEquipmentSetUse(WorldPacket& recvData);
        void HandleWorldStateUITimerUpdate(WorldPacket& recvData);
        void HandleReadyForAccountDataTimes(WorldPacket& recvData);
        void HandleQueryQuestsCompleted(WorldPacket& recvData);
        void HandleQuestPOIQuery(WorldPacket& recvData);
        void HandleEjectPassenger(WorldPacket& data);
        void HandleEnterPlayerVehicle(WorldPacket& data);
        void HandleUpdateProjectilePosition(WorldPacket& recvPacket);
        void HandleRequestHotfix(WorldPacket& recvPacket);
        void HandleUpdateMissileTrajectory(WorldPacket& recvPacket);
        void HandleViolenceLevel(WorldPacket& recvPacket);
        void HandleObjectUpdateFailedOpcode(WorldPacket& recvPacket);
        void HandleRequestCategoryCooldowns(WorldPacket& recvPacket);
        int32 HandleEnableNagleAlgorithm();

        // Compact Unit Frames (4.x)
        void HandleSaveCUFProfiles(WorldPacket& recvPacket);
        void SendLoadCUFProfiles();

    private:
        void InitializeQueryCallbackParameters();
        void ProcessQueryCallbacks();

        PreparedQueryResultFuture _charEnumCallback;
        PreparedQueryResultFuture _addIgnoreCallback;
        PreparedQueryResultFuture _stablePetCallback;
        QueryCallback<PreparedQueryResult, std::string> _charRenameCallback;
        QueryCallback<PreparedQueryResult, std::string> _addFriendCallback;
        QueryCallback<PreparedQueryResult, uint32> _unstablePetCallback;
        QueryCallback<PreparedQueryResult, uint32> _stableSwapCallback;
        QueryCallback<PreparedQueryResult, uint64> _sendStabledPetCallback;
        QueryCallback<PreparedQueryResult, CharacterCreateInfo*, true> _charCreateCallback;
        QueryResultHolderFuture _charLoginCallback;

    friend class World;
    protected:
        class DosProtection
        {
            friend class World;
            public:
                DosProtection(WorldSession* s) : Session(s), _policy((Policy)sWorld->getIntConfig(CONFIG_PACKET_SPOOF_POLICY)) { }
                bool EvaluateOpcode(WorldPacket& p) const;
                void AllowOpcode(uint16 opcode, bool allow) { _isOpcodeAllowed[opcode] = allow; }
            protected:
                enum Policy
                {
                    POLICY_LOG,
                    POLICY_KICK,
                    POLICY_BAN,
                };

                bool IsOpcodeAllowed(uint16 opcode) const
                {
                    OpcodeStatusMap::const_iterator itr = _isOpcodeAllowed.find(opcode);
                    if (itr == _isOpcodeAllowed.end())
                        return true;    // No presence in the map indicates this is the first time the opcode was sent this session, so allow

                    return itr->second;
                }

                WorldSession* Session;

            private:
                typedef UNORDERED_MAP<uint16, bool> OpcodeStatusMap;
                OpcodeStatusMap _isOpcodeAllowed; // could be bool array, but wouldn't be practical for game versions with non-linear opcodes
                Policy _policy;

                DosProtection(DosProtection const& right) = delete;
                DosProtection& operator=(DosProtection const& right) = delete;
        } AntiDOS;

    private:
        // private trade methods
        void moveItems(Item* myItems[], Item* hisItems[]);

        // logging helper
        void LogUnexpectedOpcode(WorldPacket* packet, const char* status, const char *reason);
        void LogUnprocessedTail(WorldPacket* packet);

        // EnumData helpers
        bool IsLegitCharacterForAccount(uint32 lowGUID)
        {
            return _legitCharacters.find(lowGUID) != _legitCharacters.end();
        }

        // this stores the GUIDs of the characters who can login
        // characters who failed on Player::BuildEnumData shouldn't login
        std::set<uint32> _legitCharacters;

        uint32 m_GUIDLow;                                   // set loggined or recently logout player (while m_playerRecentlyLogout set)
        Player* _player;
        WorldSocket* m_Socket;
        std::string m_Address;

        AccountTypes _security;
        uint32 _accountId;
        uint8 m_expansion;

        typedef std::list<AddonInfo> AddonsList;

        // Warden
        Warden* _warden;                                    // Remains NULL if Warden system is not enabled by config

        time_t _logoutTime;
        bool m_inQueue;                                     // session wait in auth.queue
        bool m_playerLoading;                               // code processed in LoginPlayer
        bool m_playerLogout;                                // code processed in LogoutPlayer
        bool m_playerRecentlyLogout;
        bool m_playerSave;
        LocaleConstant m_sessionDbcLocale;
        LocaleConstant m_sessionDbLocaleIndex;
        uint32 m_latency;
        uint32 m_clientTimeDelay;
        AccountData m_accountData[NUM_ACCOUNT_DATA_TYPES];
        uint32 m_Tutorials[MAX_ACCOUNT_TUTORIAL_VALUES];
        bool   m_TutorialsChanged;
        AddonsList m_addonsList;
        std::vector<std::string> _registeredAddonPrefixes;
        bool _filterAddonMessages;
        uint32 recruiterId;
        bool isRecruiter;
        ACE_Based::LockedQueue<WorldPacket*, ACE_Thread_Mutex> _recvQueue;
        time_t timeLastWhoCommand;
        z_stream_s* _compressionStream;
        rbac::RBACData* _RBACData;

        WorldSession(WorldSession const& right) = delete;
        WorldSession& operator=(WorldSession const& right) = delete;
};
#endif
/// @}
