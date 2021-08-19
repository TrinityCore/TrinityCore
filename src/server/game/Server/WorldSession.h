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

/// \addtogroup u2w
/// @{
/// \file

#ifndef __WORLDSESSION_H
#define __WORLDSESSION_H

#include "Common.h"
#include "AsyncCallbackProcessor.h"
#include "AuthDefines.h"
#include "DatabaseEnvFwd.h"
#include "LockedQueue.h"
#include "ObjectGuid.h"
#include "Packet.h"
#include "SharedDefines.h"
#include <string>
#include <map>
#include <memory>
#include <unordered_map>
#include <boost/circular_buffer.hpp>

class Creature;
class GameClient;
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
struct AddonInfo;
struct AreaTableEntry;
struct AuctionEntry;
struct DeclinedName;
struct ItemTemplate;
struct MovementInfo;
struct Petition;
struct TradeStatusInfo;
enum AuctionAction : uint8;
enum AuctionError : uint8;
enum InventoryResult : uint8;

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

namespace WorldPackets
{
    namespace Bank
    {
        class AutoBankItem;
        class AutoStoreBankItem;
        class BuyBankSlot;
    }

    namespace Character
    {
        class LogoutCancel;
        class LogoutRequest;
        class ShowingCloak;
        class ShowingHelm;
        class PlayerLogout;
        class PlayedTimeClient;
    }

    namespace Chat
    {
        class EmoteClient;
    }
    namespace Combat
    {
        class AttackSwing;
        class AttackStop;
        class SetSheathed;
    }
    namespace Guild
    {
        class QueryGuildInfo;
        class GuildCreate;
        class GuildInviteByName;
        class AcceptGuildInvite;
        class GuildDeclineInvitation;
        class GuildGetInfo;
        class GuildGetRoster;
        class GuildPromoteMember;
        class GuildDemoteMember;
        class GuildOfficerRemoveMember;
        class GuildLeave;
        class GuildDelete;
        class GuildUpdateMotdText;
        class GuildAddRank;
        class GuildDeleteRank;
        class GuildUpdateInfoText;
        class GuildSetMemberNote;
        class GuildEventLogQuery;
        class GuildBankRemainingWithdrawMoneyQuery;
        class GuildPermissionsQuery;
        class GuildSetRankPermissions;
        class GuildBankActivate;
        class GuildBankQueryTab;
        class GuildBankDepositMoney;
        class GuildBankWithdrawMoney;
        class GuildBankSwapItems;
        class GuildBankBuyTab;
        class GuildBankUpdateTab;
        class GuildBankLogQuery;
        class GuildBankTextQuery;
        class GuildBankSetTabText;
        class GuildSetGuildMaster;
        class SaveGuildEmblem;
    }

    namespace LFG
    {
        class LFGJoin;
        class LFGLeave;
    }

    namespace Mail
    {
        class MailCreateTextItem;
        class MailDelete;
        class MailGetList;
        class MailMarkAsRead;
        class MailQueryNextMailTime;
        class MailReturnToSender;
        class MailTakeItem;
        class MailTakeMoney;
        class SendMail;
    }

    namespace Misc
    {
        class CompleteCinematic;
        class CompleteMovie;
        class NextCinematicCamera;
        class OpeningCinematic;
        class RandomRollClient;
        class TogglePvP;
        class WorldTeleport;
        class ReclaimCorpse;
        class RepopRequest;
        class ResurrectResponse;
    }

    namespace NPC
    {
        class Hello;
        class TrainerBuySpell;
    }

    namespace Pet
    {
        class DismissCritter;
        class PetAbandon;
        class PetStopAttack;
        class PetSpellAutocast;
        class RequestPetInfo;
    }

    namespace Query
    {
        class QueryCreature;
        class QueryGameObject;
        class QueryItemSingle;
        class QuestPOIQuery;
    }
    namespace Quest
    {
        class QueryQuestInfo;
    }
    namespace Spells
    {
        class CancelCast;
        class CancelAura;
        class PetCancelAura;
        class CancelGrowthAura;
        class CancelMountAura;
        class CancelAutoRepeatSpell;
        class CancelChannelling;
    }
    namespace Totem
    {
        class TotemDestroyed;
    }
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

uint32 constexpr MAX_CHARACTERS_PER_REALM = 10; // max supported by client in char enum

struct AccountData
{
    AccountData() : Time(0), Data("") { }

    time_t Time;
    std::string Data;
};

enum PartyOperation
{
    PARTY_OP_INVITE   = 0,
    PARTY_OP_UNINVITE = 1,
    PARTY_OP_LEAVE    = 2,
    PARTY_OP_SWAP     = 4
};

enum BarberShopResult
{
    BARBER_SHOP_RESULT_SUCCESS      = 0,
    BARBER_SHOP_RESULT_NO_MONEY     = 1,
    BARBER_SHOP_RESULT_NOT_ON_CHAIR = 2,
    BARBER_SHOP_RESULT_NO_MONEY_2   = 3
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

enum DeclinedNameResult
{
    DECLINED_NAMES_RESULT_SUCCESS = 0,
    DECLINED_NAMES_RESULT_ERROR   = 1
};

enum TutorialsFlag : uint8
{
    TUTORIALS_FLAG_NONE                           = 0x00,
    TUTORIALS_FLAG_CHANGED                        = 0x01,
    TUTORIALS_FLAG_LOADED_FROM_DB                 = 0x02
};

//class to deal with packet processing
//allows to determine if next packet is safe to be processed
class PacketFilter
{
public:
    explicit PacketFilter(WorldSession* pSession) : m_pSession(pSession) { }
    virtual ~PacketFilter() { }

    virtual bool Process(WorldPacket* /*packet*/) { return true; }
    virtual bool ProcessUnsafe() const { return true; }

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

    virtual bool Process(WorldPacket* packet) override;
    //in Map::Update() we do not process player logout!
    virtual bool ProcessUnsafe() const override { return false; }
};

//class used to filer only thread-unsafe packets from queue
//in order to update only be used in World::UpdateSessions()
class WorldSessionFilter : public PacketFilter
{
public:
    explicit WorldSessionFilter(WorldSession* pSession) : PacketFilter(pSession) { }
    ~WorldSessionFilter() { }

    virtual bool Process(WorldPacket* packet) override;
};

// Proxy structure to contain data passed to callback function,
// only to prevent bloating the parameter list
class CharacterCreateInfo
{
    friend class WorldSession;
    friend class Player;

    protected:
        /// User specified variables
        std::string Name;
        uint8 Race       = 0;
        uint8 Class      = 0;
        uint8 Gender     = GENDER_NONE;
        uint8 Skin       = 0;
        uint8 Face       = 0;
        uint8 HairStyle  = 0;
        uint8 HairColor  = 0;
        uint8 FacialHair = 0;
        uint8 OutfitId   = 0;

        /// Server side data
        uint8 CharCount = 0;
};

struct CharacterRenameInfo
{
    friend class WorldSession;

    protected:
        ObjectGuid Guid;
        std::string Name;
};

struct CharacterCustomizeInfo : public CharacterRenameInfo
{
    friend class Player;
    friend class WorldSession;

    protected:
        uint8 Gender     = GENDER_NONE;
        uint8 Skin       = 0;
        uint8 Face       = 0;
        uint8 HairStyle  = 0;
        uint8 HairColor  = 0;
        uint8 FacialHair = 0;
};

struct CharacterFactionChangeInfo : public CharacterCustomizeInfo
{
    friend class Player;
    friend class WorldSession;

    protected:
        uint8 Race = 0;
        bool FactionChange = false;
};

struct PacketCounter
{
    time_t lastReceiveTime;
    uint32 amountCounter;
};

/// Player session in the World
class TC_GAME_API WorldSession
{
    public:
        WorldSession(uint32 id, std::string&& name, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter);
        ~WorldSession();

        bool PlayerLoading() const { return m_playerLoading; }
        bool PlayerLogout() const { return m_playerLogout; }
        bool PlayerLogoutWithSave() const { return m_playerLogout && m_playerSave; }
        bool PlayerRecentlyLoggedOut() const { return m_playerRecentlyLogout; }
        bool PlayerDisconnected() const { return !m_Socket; }

        void ReadAddonsInfo(ByteBuffer& data);
        void SendAddonsInfo();

        void ReadMovementInfo(WorldPacket& data, MovementInfo* mi);
        void static WriteMovementInfo(WorldPacket* data, MovementInfo* mi);

        void SendPacket(WorldPacket const* packet);
        void SendNotification(const char *format, ...) ATTR_PRINTF(2, 3);
        void SendNotification(uint32 string_id, ...);
        void SendPetNameInvalid(uint32 error, std::string const& name, DeclinedName *declinedName);
        void SendPartyResult(PartyOperation operation, std::string const& member, PartyResult res, uint32 val = 0);
        void SendAreaTriggerMessage(char const* Text, ...) ATTR_PRINTF(2, 3);
        void SendSetPhaseShift(uint32 phaseShift);
        void SendQueryTimeResponse();

        void SendAuthResponse(uint8 code, bool shortForm, uint32 queuePos = 0);
        void SendClientCacheVersion(uint32 version);

        void InitializeSession();
        void InitializeSessionCallback(CharacterDatabaseQueryHolder const& realmHolder);

        GameClient* GetGameClient() const { return _gameClient; };

        rbac::RBACData* GetRBACData();
        bool HasPermission(uint32 permissionId);
        void LoadPermissions();
        QueryCallback LoadPermissionsAsync();
        void InvalidateRBACData(); // Used to force LoadPermissions at next HasPermission check

        AccountTypes GetSecurity() const { return _security; }
        uint32 GetAccountId() const { return _accountId; }
        std::string const& GetAccountName() const { return _accountName; }
        Player* GetPlayer() const { return _player; }
        std::string const& GetPlayerName() const;
        std::string GetPlayerInfo() const;

        ObjectGuid::LowType GetGUIDLow() const;
        void SetSecurity(AccountTypes security) { _security = security; }
        std::string const& GetRemoteAddress() const { return m_Address; }
        void SetPlayer(Player* player);
        uint8 Expansion() const { return m_expansion; }

        void InitWarden(SessionKey const& k, std::string const& os);
        Warden* GetWarden() { return _warden.get(); }
        Warden const* GetWarden() const { return _warden.get(); }

        /// Session in auth.queue currently
        void SetInQueue(bool state) { m_inQueue = state; }

        /// Is the user engaged in a log out process?
        bool isLogingOut() const { return _logoutTime || m_playerLogout; }

        /// Engage the logout process for the user
        void SetLogoutStartTime(time_t requestTime)
        {
            _logoutTime = requestTime;
        }

        /// Is logout cooldown expired?
        bool ShouldLogOut(time_t currTime) const
        {
            return (_logoutTime > 0 && currTime >= _logoutTime + 20);
        }

        void LogoutPlayer(bool save);
        void KickPlayer(std::string const& reason);
        // Returns true if all contained hyperlinks are valid
        // May kick player on false depending on world config (handler should abort)
        bool ValidateHyperlinksAndMaybeKick(std::string const& str);
        // Returns true if the message contains no hyperlinks
        // May kick player on false depending on world config (handler should abort)
        bool DisallowHyperlinksAndMaybeKick(std::string const& str);

        void QueuePacket(WorldPacket* new_packet);
        bool Update(uint32 diff, PacketFilter& updater);

        /// Handle the authentication waiting queue (to be completed)
        void SendAuthWaitQueue(uint32 position);

        void SendFeatureSystemStatus();

        void SendNameQueryOpcode(ObjectGuid guid);

        void SendTrainerList(Creature* npc);
        void SendListInventory(ObjectGuid guid);
        void SendShowBank(ObjectGuid guid);
        bool CanOpenMailBox(ObjectGuid guid);
        void SendShowMailBox(ObjectGuid guid);
        void SendTabardVendorActivate(ObjectGuid guid);
        void SendSpiritResurrect();
        void SendBindPoint(Creature* npc);

        void SendAttackStop(Unit const* enemy);

        void SendBattleGroundList(ObjectGuid guid, BattlegroundTypeId bgTypeId = BATTLEGROUND_RB);

        void SendTradeStatus(TradeStatusInfo const& status);
        void SendUpdateTrade(bool trader_data = true);
        void SendCancelTrade();

        void SendPetitionQueryOpcode(ObjectGuid petitionguid);

        // Spell
        void HandleClientCastFlags(WorldPacket& recvPacket, uint8 castFlags, SpellCastTargets& targets);

        // Pet
        void SendQueryPetNameResponse(ObjectGuid guid, uint32 petnumber);
        void SendStablePet(ObjectGuid guid);
        void SendPetStableResult(uint8 guid);
        bool CheckStableMaster(ObjectGuid guid);

        // Account Data
        AccountData* GetAccountData(AccountDataType type) { return &m_accountData[type]; }
        void SetAccountData(AccountDataType type, time_t tm, std::string const& data);
        void SendAccountDataTimes(uint32 mask);
        void LoadAccountData(PreparedQueryResult result, uint32 mask);

        void LoadTutorialsData(PreparedQueryResult result);
        void SendTutorialsData();
        void SaveTutorialsData(CharacterDatabaseTransaction trans);
        uint32 GetTutorialInt(uint8 index) const { return m_Tutorials[index]; }
        void SetTutorialInt(uint8 index, uint32 value)
        {
            if (m_Tutorials[index] != value)
            {
                m_Tutorials[index] = value;
                m_TutorialsChanged |= TUTORIALS_FLAG_CHANGED;
            }
        }
        //auction
        void SendAuctionHello(ObjectGuid guid, Creature* unit);
        void SendAuctionCommandResult(uint32 auctionItemId, AuctionAction command, AuctionError errorCode, InventoryResult bagResult = InventoryResult(0));
        void SendAuctionBidderNotification(uint32 location, uint32 auctionId, ObjectGuid bidder, uint32 bidSum, uint32 diff, uint32 item_template);
        void SendAuctionOwnerNotification(AuctionEntry* auction);

        //Item Enchantment
        void SendEnchantmentLog(ObjectGuid target, ObjectGuid caster, uint32 itemId, uint32 enchantId);
        void SendItemEnchantTimeUpdate(ObjectGuid Playerguid, ObjectGuid Itemguid, uint32 slot, uint32 Duration);

        //Taxi
        void SendTaxiStatus(ObjectGuid guid);
        void SendTaxiMenu(Creature* unit);
        void SendDoFlight(uint32 mountDisplayId, uint32 path, uint32 pathNode = 0);
        bool SendLearnNewTaxiNode(Creature* unit);
        void SendDiscoverNewTaxiNode(uint32 nodeid);

        // Guild/Arena Team
        void SendArenaTeamCommandResult(uint32 team_action, std::string const& team, std::string const& player, uint32 error_id = 0);
        void SendNotInArenaTeamPacket(uint8 type);
        void SendPetitionShowList(ObjectGuid guid);

        void BuildPartyMemberStatsChangedPacket(Player* player, WorldPacket* data);

        void DoLootRelease(ObjectGuid lguid);

        // Account mute time
        bool CanSpeak() const;
        time_t m_muteTime;

        // Locales
        LocaleConstant GetSessionDbcLocale() const { return m_sessionDbcLocale; }
        LocaleConstant GetSessionDbLocaleIndex() const { return m_sessionDbLocaleIndex; }
        char const* GetTrinityString(uint32 entry) const;

        uint32 GetLatency() const { return m_latency; }
        void SetLatency(uint32 latency) { m_latency = latency; }

        std::atomic<time_t> m_timeOutTime;

        void ResetTimeOutTime(bool onlyActive);

        bool IsConnectionIdle() const;

        // Recruit-A-Friend Handling
        uint32 GetRecruiterId() const { return recruiterId; }
        bool IsARecruiter() const { return isRecruiter; }

        // Time Synchronisation
        void ResetTimeSync();
        void SendTimeSync();

        // Packets cooldown
        time_t GetCalendarEventCreationCooldown() const { return _calendarEventCreationCooldown; }
        void SetCalendarEventCreationCooldown(time_t cooldown) { _calendarEventCreationCooldown = cooldown; }

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPacket& recvPacket);          // not used
        void Handle_EarlyProccess(WorldPacket& recvPacket); // just mark packets processed in WorldSocket::ReadDataHandler
        void Handle_ServerSide(WorldPacket& recvPacket);    // sever side only, can't be accepted from client
        void Handle_Deprecated(WorldPacket& recvPacket);    // never used anymore by client

        void HandleCharEnumOpcode(WorldPacket& recvPacket);
        void HandleCharDeleteOpcode(WorldPacket& recvPacket);
        void HandleCharCreateOpcode(WorldPacket& recvPacket);
        void HandlePlayerLoginOpcode(WorldPacket& recvPacket);
        void HandleCharEnum(PreparedQueryResult result);
        void HandlePlayerLogin(LoginQueryHolder const& holder);
        void HandleCharFactionOrRaceChange(WorldPacket& recvData);
        void HandleCharFactionOrRaceChangeCallback(std::shared_ptr<CharacterFactionChangeInfo> factionChangeInfo, PreparedQueryResult result);
        void HandleCharRenameOpcode(WorldPacket& recvData);
        void HandleCharRenameCallBack(std::shared_ptr<CharacterRenameInfo> renameInfo, PreparedQueryResult result);
        void HandleSetPlayerDeclinedNames(WorldPacket& recvData);
        void HandleAlterAppearance(WorldPacket& recvData);
        void HandleCharCustomize(WorldPacket& recvData);
        void HandleCharCustomizeCallback(std::shared_ptr<CharacterCustomizeInfo> customizeInfo, PreparedQueryResult result);
        void HandleOpeningCinematic(WorldPackets::Misc::OpeningCinematic& packet);

        void SendCharCreate(ResponseCodes result);
        void SendCharDelete(ResponseCodes result);
        void SendCharRename(ResponseCodes result, CharacterRenameInfo const* renameInfo);
        void SendCharCustomize(ResponseCodes result, CharacterCustomizeInfo const* customizeInfo);
        void SendCharFactionChange(ResponseCodes result, CharacterFactionChangeInfo const* factionChangeInfo);
        void SendSetPlayerDeclinedNamesResult(DeclinedNameResult result, ObjectGuid guid);
        void SendBarberShopResult(BarberShopResult result);

        // played time
        void HandlePlayedTime(WorldPackets::Character::PlayedTimeClient& packet);

        // new inspect
        void HandleInspectOpcode(WorldPacket& recvPacket);

        // new party stats
        void HandleInspectHonorStatsOpcode(WorldPacket& recvPacket);

        void HandleForceSpeedChangeAck(WorldPacket& recvData);
        void HandleMoveKnockBackAck(WorldPacket& recvPacket);
        void HandleMoveTeleportAck(WorldPacket& recvPacket);
        void HandleMoveWaterWalkAck(WorldPacket& recvPacket);
        void HandleFeatherFallAck(WorldPacket& recvData);
        void HandleMoveHoverAck(WorldPacket& recvData);
        void HandleMoveUnRootAck(WorldPacket& recvPacket);
        void HandleMoveRootAck(WorldPacket& recvPacket);
        void HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData);
        void HandleMoveSetCanTransitionBetweenSwinAndFlyAck(WorldPacket& recvData);
        void HandleMoveGravityDisableAck(WorldPacket& recvData);
        void HandleMoveGravityEnableAck(WorldPacket& recvData);
        void HandleMoveSetCollisionHgtAck(WorldPacket& recvData);

        void HandleMountSpecialAnimOpcode(WorldPacket& recvdata);

        // character view
        void HandleShowingHelmOpcode(WorldPackets::Character::ShowingHelm& packet);
        void HandleShowingCloakOpcode(WorldPackets::Character::ShowingCloak& packet);

        // repair
        void HandleRepairItemOpcode(WorldPacket& recvPacket);

        void HandleRepopRequest(WorldPackets::Misc::RepopRequest& packet);
        void HandleAutostoreLootItemOpcode(WorldPacket& recvPacket);
        void HandleLootMoneyOpcode(WorldPacket& recvPacket);
        void HandleLootOpcode(WorldPacket& recvPacket);
        void HandleLootReleaseOpcode(WorldPacket& recvPacket);
        void HandleLootMasterGiveOpcode(WorldPacket& recvPacket);
        void HandleWhoOpcode(WorldPacket& recvPacket);
        void HandleLogoutRequestOpcode(WorldPackets::Character::LogoutRequest& logoutRequest);
        void HandlePlayerLogoutOpcode(WorldPackets::Character::PlayerLogout& playerLogout);
        void HandleLogoutCancelOpcode(WorldPackets::Character::LogoutCancel& logoutCancel);

        // GM Ticket opcodes
        void HandleGMTicketCreateOpcode(WorldPacket& recvPacket);
        void HandleGMTicketUpdateOpcode(WorldPacket& recvPacket);
        void HandleGMTicketDeleteOpcode(WorldPacket& recvPacket);
        void HandleGMTicketGetTicketOpcode(WorldPacket& recvPacket);
        void HandleGMTicketSystemStatusOpcode(WorldPacket& recvPacket);
        void HandleGMSurveySubmit(WorldPacket& recvPacket);
        void HandleReportLag(WorldPacket& recvPacket);
        void HandleGMResponseResolve(WorldPacket& recvPacket);

        void HandleTogglePvP(WorldPackets::Misc::TogglePvP& togglePvP);

        void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
        void HandleSetSelectionOpcode(WorldPacket& recvPacket);
        void HandleStandStateChangeOpcode(WorldPacket& recvPacket);
        void HandleEmoteOpcode(WorldPackets::Chat::EmoteClient& packet);

        // Social
        void HandleContactListOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcode(WorldPacket& recvPacket);
        void HandleDelFriendOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcode(WorldPacket& recvPacket);
        void HandleDelIgnoreOpcode(WorldPacket& recvPacket);
        void HandleSetContactNotesOpcode(WorldPacket& recvPacket);
        void HandleBugOpcode(WorldPacket& recvPacket);
        void HandleSetAmmoOpcode(WorldPacket& recvPacket);
        void HandleItemNameQueryOpcode(WorldPacket& recvPacket);

        void HandleAreaTriggerOpcode(WorldPacket& recvPacket);

        void HandleSetFactionAtWar(WorldPacket& recvData);
        void HandleSetFactionCheat(WorldPacket& recvData);
        void HandleSetWatchedFactionOpcode(WorldPacket& recvData);
        void HandleSetFactionInactiveOpcode(WorldPacket& recvData);

        void HandleUpdateAccountData(WorldPacket& recvPacket);
        void HandleRequestAccountData(WorldPacket& recvPacket);
        void HandleSetActionButtonOpcode(WorldPacket& recvPacket);

        void HandleGameObjectUseOpcode(WorldPacket& recPacket);
        void HandleGameobjectReportUse(WorldPacket& recvPacket);

        void HandleNameQueryOpcode(WorldPacket& recvPacket);

        void HandleQueryTimeOpcode(WorldPacket& recvPacket);

        void HandleCreatureQueryOpcode(WorldPackets::Query::QueryCreature& query);

        void HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& query);

        void HandleMoveWorldportAckOpcode(WorldPacket& recvPacket);
        void HandleMoveWorldportAck();                // for server-side calls

        void HandleMovementOpcodes(WorldPacket& recvPacket);
        void HandleSetActiveMoverOpcode(WorldPacket& recvData);
        void HandleMoveNotActiveMover(WorldPacket& recvData);
        void HandleDismissControlledVehicle(WorldPacket& recvData);
        void HandleRequestVehicleExit(WorldPacket& recvData);
        void HandleChangeSeatsOnControlledVehicle(WorldPacket& recvData);
        void HandleMoveTimeSkippedOpcode(WorldPacket& recvData);

        void HandleRequestRaidInfoOpcode(WorldPacket& recvData);

        void HandleBattlefieldStatusOpcode(WorldPacket& recvData);

        void HandleGroupInviteOpcode(WorldPacket& recvPacket);
        void HandleGroupAcceptOpcode(WorldPacket& recvPacket);
        void HandleGroupDeclineOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteGuidOpcode(WorldPacket& recvPacket);
        void HandleGroupSetLeaderOpcode(WorldPacket& recvPacket);
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
        void HandleGroupAssistantLeaderOpcode(WorldPacket& recvData);
        void HandlePartyAssignmentOpcode(WorldPacket& recvData);

        void HandlePetitionBuyOpcode(WorldPacket& recvData);
        void HandlePetitionShowSignatures(WorldPacket& recvData);
        void SendPetitionSigns(Petition const* petition, Player* sendTo);
        void HandleQueryPetition(WorldPacket& recvData);
        void HandlePetitionRenameGuild(WorldPacket& recvData);
        void HandleSignPetition(WorldPacket& recvData);
        void HandleDeclinePetition(WorldPacket& recvData);
        void HandleOfferPetitionOpcode(WorldPacket& recvData);
        void HandleTurnInPetitionOpcode(WorldPacket& recvData);

        void HandleGuildQueryOpcode(WorldPackets::Guild::QueryGuildInfo& query);
        void HandleGuildCreateOpcode(WorldPackets::Guild::GuildCreate& packet);
        void HandleGuildInviteOpcode(WorldPackets::Guild::GuildInviteByName& packet);
        void HandleGuildRemoveOpcode(WorldPackets::Guild::GuildOfficerRemoveMember& packet);
        void HandleGuildAcceptOpcode(WorldPackets::Guild::AcceptGuildInvite& invite);
        void HandleGuildDeclineOpcode(WorldPackets::Guild::GuildDeclineInvitation& decline);
        void HandleGuildInfoOpcode(WorldPackets::Guild::GuildGetInfo& packet);
        void HandleGuildEventLogQueryOpcode(WorldPackets::Guild::GuildEventLogQuery& packet);
        void HandleGuildRosterOpcode(WorldPackets::Guild::GuildGetRoster& packet);
        void HandleGuildPromoteOpcode(WorldPackets::Guild::GuildPromoteMember& promote);
        void HandleGuildDemoteOpcode(WorldPackets::Guild::GuildDemoteMember& demote);
        void HandleGuildLeaveOpcode(WorldPackets::Guild::GuildLeave& leave);
        void HandleGuildDelete(WorldPackets::Guild::GuildDelete& packet);
        void HandleGuildSetGuildMaster(WorldPackets::Guild::GuildSetGuildMaster& packet);
        void HandleGuildUpdateMotdText(WorldPackets::Guild::GuildUpdateMotdText& packet);
        void HandleGuildSetPublicNoteOpcode(WorldPackets::Guild::GuildSetMemberNote& packet);
        void HandleGuildSetOfficerNoteOpcode(WorldPackets::Guild::GuildSetMemberNote& packet);
        void HandleGuildSetRankPermissions(WorldPackets::Guild::GuildSetRankPermissions& packet);
        void HandleGuildAddRankOpcode(WorldPackets::Guild::GuildAddRank& packet);
        void HandleGuildDeleteRank(WorldPackets::Guild::GuildDeleteRank& packet);
        void HandleGuildUpdateInfoText(WorldPackets::Guild::GuildUpdateInfoText& packet);
        void HandleSaveGuildEmblemOpcode(WorldPackets::Guild::SaveGuildEmblem& packet);

        void HandleTaxiNodeStatusQueryOpcode(WorldPacket& recvPacket);
        void HandleTaxiQueryAvailableNodes(WorldPacket& recvPacket);
        void HandleActivateTaxiOpcode(WorldPacket& recvPacket);
        void HandleActivateTaxiExpressOpcode(WorldPacket& recvPacket);
        void HandleMoveSplineDoneOpcode(WorldPacket& recvPacket);
        void SendActivateTaxiReply(ActivateTaxiReply reply);

        void HandleTabardVendorActivateOpcode(WorldPacket& recvPacket);
        void HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet);
        void HandleTrainerBuySpellOpcode(WorldPackets::NPC::TrainerBuySpell& packet);
        void HandlePetitionShowListOpcode(WorldPacket& recvPacket);
        void HandleGossipHelloOpcode(WorldPacket& recvPacket);
        void HandleGossipSelectOptionOpcode(WorldPacket& recvPacket);
        void HandleSpiritHealerActivateOpcode(WorldPacket& recvPacket);
        void HandleNpcTextQueryOpcode(WorldPacket& recvPacket);
        void HandleBinderActivateOpcode(WorldPacket& recvPacket);
        void HandleRequestStabledPets(WorldPacket& recvPacket);
        void HandleStablePet(WorldPacket& recvPacket);
        void HandleUnstablePet(WorldPacket& recvPacket);
        void HandleBuyStableSlot(WorldPacket& recvPacket);
        void HandleStableRevivePet(WorldPacket& recvPacket);
        void HandleStableSwapPet(WorldPacket& recvPacket);

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

        // Bank
        void HandleBankerActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleAutoBankItemOpcode(WorldPackets::Bank::AutoBankItem& packet);
        void HandleAutoStoreBankItemOpcode(WorldPackets::Bank::AutoStoreBankItem& packet);
        void HandleBuyBankSlotOpcode(WorldPackets::Bank::BuyBankSlot& buyBankSlot);

        void HandleGetMailList(WorldPackets::Mail::MailGetList& getList);
        void HandleSendMail(WorldPackets::Mail::SendMail& sendMail);
        void HandleMailTakeMoney(WorldPackets::Mail::MailTakeMoney& takeMoney);
        void HandleMailTakeItem(WorldPackets::Mail::MailTakeItem& takeItem);
        void HandleMailMarkAsRead(WorldPackets::Mail::MailMarkAsRead& markAsRead);
        void HandleMailReturnToSender(WorldPackets::Mail::MailReturnToSender& returnToSender);
        void HandleMailDelete(WorldPackets::Mail::MailDelete& mailDelete);
        void HandleItemTextQuery(WorldPacket& recvData);
        void HandleMailCreateTextItem(WorldPackets::Mail::MailCreateTextItem& createTextItem);
        void HandleQueryNextMailTime(WorldPackets::Mail::MailQueryNextMailTime& queryNextMailTime);

        void HandleSplitItemOpcode(WorldPacket& recvPacket);
        void HandleSwapInvItemOpcode(WorldPacket& recvPacket);
        void HandleDestroyItemOpcode(WorldPacket& recvPacket);
        void HandleAutoEquipItemOpcode(WorldPacket& recvPacket);
        void HandleItemQuerySingleOpcode(WorldPackets::Query::QueryItemSingle& query);
        void HandleSellItemOpcode(WorldPacket& recvPacket);
        void HandleBuyItemInSlotOpcode(WorldPacket& recvPacket);
        void HandleBuyItemOpcode(WorldPacket& recvPacket);
        void HandleListInventoryOpcode(WorldPacket& recvPacket);
        void HandleAutoStoreBagItemOpcode(WorldPacket& recvPacket);
        void HandleReadItem(WorldPacket& recvPacket);
        void HandleAutoEquipItemSlotOpcode(WorldPacket& recvPacket);
        void HandleSwapItem(WorldPacket& recvPacket);
        void HandleBuybackItem(WorldPacket& recvPacket);
        void HandleWrapItemOpcode(WorldPacket& recvPacket);

        void HandleAttackSwingOpcode(WorldPackets::Combat::AttackSwing& packet);
        void HandleAttackStopOpcode(WorldPackets::Combat::AttackStop& packet);
        void HandleSetSheathedOpcode(WorldPackets::Combat::SetSheathed& packet);

        void HandleUseItemOpcode(WorldPacket& recvPacket);
        void HandleOpenItemOpcode(WorldPacket& recvPacket);
        void HandleOpenWrappedItemCallback(uint16 pos, ObjectGuid itemGuid, PreparedQueryResult result);
        void HandleCastSpellOpcode(WorldPacket& recvPacket);
        void HandleCancelCastOpcode(WorldPackets::Spells::CancelCast& cancelCast);
        void HandleCancelAuraOpcode(WorldPackets::Spells::CancelAura& cancelAura);
        void HandleCancelGrowthAuraOpcode(WorldPackets::Spells::CancelGrowthAura& cancelGrowthAura);
        void HandleCancelMountAuraOpcode(WorldPackets::Spells::CancelMountAura& cancelMountAura);
        void HandleCancelAutoRepeatSpellOpcode(WorldPackets::Spells::CancelAutoRepeatSpell& cancelAutoRepeatSpell);
        void HandleCancelChanneling(WorldPackets::Spells::CancelChannelling& cancelChanneling);

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
        void HandleQuestQueryOpcode(WorldPackets::Quest::QueryQuestInfo& query);
        void HandleQuestgiverCancel(WorldPacket& recvData);
        void HandleQuestLogSwapQuest(WorldPacket& recvData);
        void HandleQuestLogRemoveQuest(WorldPacket& recvData);
        void HandleQuestConfirmAccept(WorldPacket& recvData);
        void HandleQuestgiverCompleteQuest(WorldPacket& recvData);
        void HandleQuestgiverQuestAutoLaunch(WorldPacket& recvPacket);
        void HandlePushQuestToParty(WorldPacket& recvPacket);
        void HandleQuestPushResult(WorldPacket& recvPacket);

        void HandleMessagechatOpcode(WorldPacket& recvPacket);
        void SendPlayerNotFoundNotice(std::string const& name);
        void SendPlayerAmbiguousNotice(std::string const& name);
        void SendWrongFactionNotice();
        void SendChatRestrictedNotice(ChatRestrictionType restriction);
        void HandleTextEmoteOpcode(WorldPacket& recvPacket);
        void HandleChatIgnoredOpcode(WorldPacket& recvPacket);

        void HandleReclaimCorpse(WorldPackets::Misc::ReclaimCorpse& packet);
        void HandleCorpseQueryOpcode(WorldPacket& recvPacket);
        void HandleCorpseMapPositionQuery(WorldPacket& recvPacket);
        void HandleResurrectResponse(WorldPackets::Misc::ResurrectResponse& packet);
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
        void HandleChannelDeclineInvite(WorldPacket& recvPacket);
        void HandleChannelDisplayListQuery(WorldPacket& recvPacket);
        void HandleGetChannelMemberCount(WorldPacket& recvPacket);
        void HandleSetChannelWatch(WorldPacket& recvPacket);

        void HandleCompleteCinematic(WorldPackets::Misc::CompleteCinematic& packet);
        void HandleNextCinematicCamera(WorldPackets::Misc::NextCinematicCamera& packet);
        void HandleCompleteMovie(WorldPackets::Misc::CompleteMovie& packet);

        void HandleQueryPageText(WorldPacket& recvPacket);

        void HandleTutorialFlag (WorldPacket& recvData);
        void HandleTutorialClear(WorldPacket& recvData);
        void HandleTutorialReset(WorldPacket& recvData);

        //Pet
        void HandlePetAction(WorldPacket& recvData);
        void HandlePetStopAttack(WorldPackets::Pet::PetStopAttack& packet);
        void HandlePetActionHelper(Unit* pet, ObjectGuid guid1, uint32 spellid, uint16 flag, ObjectGuid guid2);
        void HandleQueryPetName(WorldPacket& recvData);
        void HandlePetSetAction(WorldPacket& recvData);
        void HandlePetAbandon(WorldPackets::Pet::PetAbandon& packet);
        void HandlePetRename(WorldPacket& recvData);
        void HandlePetCancelAuraOpcode(WorldPackets::Spells::PetCancelAura& packet);
        void HandlePetSpellAutocastOpcode(WorldPackets::Pet::PetSpellAutocast& packet);
        void HandlePetCastSpellOpcode(WorldPacket& recvPacket);
        void HandlePetLearnTalent(WorldPacket& recvPacket);
        void HandleLearnPreviewTalentsPet(WorldPacket& recvPacket);

        void HandleSetActionBarToggles(WorldPacket& recvData);

        void HandleTotemDestroyed(WorldPackets::Totem::TotemDestroyed& totemDestroyed);
        void HandleDismissCritter(WorldPackets::Pet::DismissCritter& dismissCritter);

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

        // Battlefield
        void SendBfInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 time);
        void SendBfInvitePlayerToQueue(uint32 battleId);
        void SendBfQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue = true, bool full = false);
        void SendBfEntered(uint32 battleId);
        void SendBfLeaveMessage(uint32 battleId, BFLeaveReason reason = BF_LEAVE_REASON_EXITED);
        void HandleBfQueueInviteResponse(WorldPacket& recvData);
        void HandleBfEntryInviteResponse(WorldPacket& recvData);
        void HandleBfQueueExitRequest(WorldPacket& recvData);

        void HandleWardenDataOpcode(WorldPacket& recvData);
        void HandleWorldTeleportOpcode(WorldPackets::Misc::WorldTeleport& worldTeleport);
        void HandleMinimapPingOpcode(WorldPacket& recvData);
        void HandleRandomRollOpcode(WorldPackets::Misc::RandomRollClient& packet);
        void HandleFarSightOpcode(WorldPacket& recvData);
        void HandleSetDungeonDifficultyOpcode(WorldPacket& recvData);
        void HandleSetRaidDifficultyOpcode(WorldPacket& recvData);
        void HandleSetTitleOpcode(WorldPacket& recvData);
        void HandleRealmSplitOpcode(WorldPacket& recvData);
        void HandleTimeSyncResponse(WorldPacket& recvData);
        void HandleWhoIsOpcode(WorldPacket& recvData);
        void HandleResetInstancesOpcode(WorldPacket& recvData);
        void HandleHearthAndResurrect(WorldPacket& recvData);
        void HandleInstanceLockResponse(WorldPacket& recvPacket);

        // Looking for Dungeon/Raid
        void HandleLfgSetCommentOpcode(WorldPacket& recvData);
        void HandleLfgPlayerLockInfoRequestOpcode(WorldPacket& recvData);
        void HandleLfgPartyLockInfoRequestOpcode(WorldPacket& recvData);
        void HandleLfgJoinOpcode(WorldPackets::LFG::LFGJoin& lfgJoin);
        void HandleLfgLeaveOpcode(WorldPackets::LFG::LFGLeave& lfgleave);
        void HandleLfgSetRolesOpcode(WorldPacket& recvData);
        void HandleLfgProposalResultOpcode(WorldPacket& recvData);
        void HandleLfgSetBootVoteOpcode(WorldPacket& recvData);
        void HandleLfgTeleportOpcode(WorldPacket& recvData);
        void HandleLfrJoinOpcode(WorldPacket& recvData);
        void HandleLfrLeaveOpcode(WorldPacket& recvData);
        void HandleLfgGetStatus(WorldPacket& recvData);

        void SendLfgUpdatePlayer(lfg::LfgUpdateData const& updateData);
        void SendLfgUpdateParty(lfg::LfgUpdateData const& updateData);
        void SendLfgRoleChosen(ObjectGuid guid, uint8 roles);
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
        void HandleArenaTeamInviteOpcode(WorldPacket& recvData);
        void HandleArenaTeamAcceptOpcode(WorldPacket& recvData);
        void HandleArenaTeamDeclineOpcode(WorldPacket& recvData);
        void HandleArenaTeamLeaveOpcode(WorldPacket& recvData);
        void HandleArenaTeamRemoveOpcode(WorldPacket& recvData);
        void HandleArenaTeamDisbandOpcode(WorldPacket& recvData);
        void HandleArenaTeamLeaderOpcode(WorldPacket& recvData);

        void HandleAreaSpiritHealerQueryOpcode(WorldPacket& recvData);
        void HandleAreaSpiritHealerQueueOpcode(WorldPacket& recvData);
        void HandleSelfResOpcode(WorldPacket& recvData);
        void HandleComplainOpcode(WorldPacket& recvData);
        void HandleRequestPetInfo(WorldPackets::Pet::RequestPetInfo& packet);

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
        void HandleGuildPermissionsQuery(WorldPackets::Guild::GuildPermissionsQuery& packet);
        void HandleGuildBankMoneyWithdrawn(WorldPackets::Guild::GuildBankRemainingWithdrawMoneyQuery& packet);
        void HandleGuildBankActivate(WorldPackets::Guild::GuildBankActivate& packet);
        void HandleGuildBankQueryTab(WorldPackets::Guild::GuildBankQueryTab& packet);
        void HandleGuildBankLogQuery(WorldPackets::Guild::GuildBankLogQuery& packet);
        void HandleGuildBankDepositMoney(WorldPackets::Guild::GuildBankDepositMoney& packet);
        void HandleGuildBankWithdrawMoney(WorldPackets::Guild::GuildBankWithdrawMoney& packet);
        void HandleGuildBankSwapItems(WorldPackets::Guild::GuildBankSwapItems& packet);

        void HandleGuildBankUpdateTab(WorldPackets::Guild::GuildBankUpdateTab& packet);
        void HandleGuildBankBuyTab(WorldPackets::Guild::GuildBankBuyTab& packet);
        void HandleGuildBankTextQuery(WorldPackets::Guild::GuildBankTextQuery& packet);
        void HandleGuildBankSetTabText(WorldPackets::Guild::GuildBankSetTabText& packet);

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

        void HandleSpellClick(WorldPacket& recvData);
        void HandleMirrorImageDataRequest(WorldPacket& recvData);
        void HandleRemoveGlyph(WorldPacket& recvData);
        void HandleQueryInspectAchievements(WorldPacket& recvData);
        void HandleEquipmentSetSave(WorldPacket& recvData);
        void HandleEquipmentSetDelete(WorldPacket& recvData);
        void HandleEquipmentSetUse(WorldPacket& recvData);
        void HandleWorldStateUITimerUpdate(WorldPacket& recvData);
        void HandleReadyForAccountDataTimes(WorldPacket& recvData);
        void HandleQueryQuestsCompleted(WorldPacket& recvData);
        void HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& query);
        void HandleEjectPassenger(WorldPacket& data);
        void HandleEnterPlayerVehicle(WorldPacket& data);
        void HandleUpdateProjectilePosition(WorldPacket& recvPacket);
        void HandleUpdateMissileTrajectory(WorldPacket& recvPacket);

    public:
        QueryCallbackProcessor& GetQueryProcessor() { return _queryProcessor; }
        TransactionCallback& AddTransactionCallback(TransactionCallback&& callback);
        SQLQueryHolderCallback& AddQueryHolderCallback(SQLQueryHolderCallback&& callback);

    private:
        void ProcessQueryCallbacks();

        QueryCallbackProcessor _queryProcessor;
        AsyncCallbackProcessor<TransactionCallback> _transactionCallbacks;
        AsyncCallbackProcessor<SQLQueryHolderCallback> _queryHolderProcessor;

    friend class World;
    protected:
        class DosProtection
        {
            friend class World;
            public:
                DosProtection(WorldSession* s);
                bool EvaluateOpcode(WorldPacket& p, time_t time) const;
            protected:
                enum Policy
                {
                    POLICY_LOG,
                    POLICY_KICK,
                    POLICY_BAN,
                };

                uint32 GetMaxPacketCounterAllowed(uint16 opcode) const;

                WorldSession* Session;

            private:
                Policy _policy;
                typedef std::unordered_map<uint16, PacketCounter> PacketThrottlingMap;
                // mark this member as "mutable" so it can be modified even in const functions
                mutable PacketThrottlingMap _PacketThrottlingMap;

                DosProtection(DosProtection const& right) = delete;
                DosProtection& operator=(DosProtection const& right) = delete;
        } AntiDOS;

    private:
        // private trade methods
        void moveItems(Item* myItems[], Item* hisItems[]);

        bool CanUseBank(ObjectGuid bankerGUID = ObjectGuid::Empty) const;

        // logging helper
        void LogUnexpectedOpcode(WorldPacket* packet, char const* status, const char *reason);
        void LogUnprocessedTail(WorldPacket* packet);

        // EnumData helpers
        bool IsLegitCharacterForAccount(ObjectGuid lowGUID)
        {
            return _legitCharacters.find(lowGUID) != _legitCharacters.end();
        }

        // Movement helpers
        bool IsRightUnitBeingMoved(ObjectGuid guid);

        // this stores the GUIDs of the characters who can login
        // characters who failed on Player::BuildEnumData shouldn't login
        GuidSet _legitCharacters;

        ObjectGuid::LowType m_GUIDLow;                      // set logined or recently logout player (while m_playerRecentlyLogout set)
        Player* _player;
        std::shared_ptr<WorldSocket> m_Socket;
        std::string m_Address;                              // Current Remote Address
     // std::string m_LAddress;                             // Last Attempted Remote Adress - we can not set attempted ip for a non-existing session!

        AccountTypes _security;
        uint32 _accountId;
        std::string _accountName;
        uint8 m_expansion;

        // Warden
        std::unique_ptr<Warden> _warden;                                    // Remains NULL if Warden system is not enabled by config

        time_t _logoutTime;
        bool m_inQueue;                                     // session wait in auth.queue
        bool m_playerLoading;                               // code processed in LoginPlayer
        bool m_playerLogout;                                // code processed in LogoutPlayer
        bool m_playerRecentlyLogout;
        bool m_playerSave;
        LocaleConstant m_sessionDbcLocale;
        LocaleConstant m_sessionDbLocaleIndex;
        std::atomic<uint32> m_latency;
        AccountData m_accountData[NUM_ACCOUNT_DATA_TYPES];
        uint32 m_Tutorials[MAX_ACCOUNT_TUTORIAL_VALUES];
        uint8  m_TutorialsChanged;
        struct Addons
        {
            struct SecureAddonInfo
            {
                enum SecureAddonStatus : uint8
                {
                    BANNED          = 0,
                    SECURE_VISIBLE  = 1,
                    SECURE_HIDDEN   = 2
                };

                std::string Name;
                SecureAddonStatus Status = BANNED;
                bool HasKey = false;
            };

            static uint32 constexpr MaxSecureAddons = 25;

            std::vector<SecureAddonInfo> SecureAddons;
            uint32 LastBannedAddOnTimestamp = 0;
        } _addons;
        uint32 recruiterId;
        bool isRecruiter;
        LockedQueue<WorldPacket*> _recvQueue;
        rbac::RBACData* _RBACData;
        uint32 expireTime;
        bool forceExit;
        ObjectGuid m_currentBankerGUID;

        boost::circular_buffer<std::pair<int64, uint32>> _timeSyncClockDeltaQueue; // first member: clockDelta. Second member: latency of the packet exchange that was used to compute that clockDelta.
        int64 _timeSyncClockDelta;
        void ComputeNewClockDelta();

        std::map<uint32, uint32> _pendingTimeSyncRequests; // key: counter. value: server time when packet with that counter was sent.
        uint32 _timeSyncNextCounter;
        uint32 _timeSyncTimer;

        // Packets cooldown
        time_t _calendarEventCreationCooldown;
        GameClient* _gameClient;

        WorldSession(WorldSession const& right) = delete;
        WorldSession& operator=(WorldSession const& right) = delete;
};
#endif
/// @}
