/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "Opcodes.h"
#include "WorldPacket.h"
#include "Cryptography/BigNumber.h"
#include "Opcodes.h"
#include "AccountMgr.h"
#include <unordered_set>

class Channel;
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
class WorldSession;
class WorldSocket;
struct AreaTableEntry;
struct AuctionEntry;
struct DeclinedName;
struct ItemTemplate;
struct MovementInfo;
struct TradeStatusInfo;

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
    namespace Achievement
    {
        class GuildSetFocusedAchievement;
    }

    namespace AuctionHouse
    {
        class AuctionHelloRequest;
    }

    namespace Auth
    {
        enum class ConnectToSerial : uint32;
    }

    namespace BlackMarket
    {
        class BlackMarketOpen;
    }

    namespace Character
    {
        struct CharacterCreateInfo;
        struct CharacterRenameInfo;
        struct CharCustomizeInfo;
        struct CharRaceOrFactionChangeInfo;
        struct CharacterUndeleteInfo;

        class EnumCharacters;
        class CreateChar;
        class DeleteChar;
        class CharacterRenameRequest;
        class CharCustomize;
        class CharRaceOrFactionChange;
        class GenerateRandomCharacterName;
        class GetUndeleteCooldownStatus;
        class ReorderCharacters;
        class UndeleteCharacter;
        class PlayerLogin;
        class LogoutRequest;
        class LogoutCancel;
        class LoadingScreenNotify;
        class SetActionBarToggles;
        class PlayedTimeClient;
        class ShowingCloak;
        class ShowingHelm;

        enum class LoginFailureReason : uint8;
    }

    namespace ClientConfig
    {
        class RequestAccountData;
        class UserClientUpdateAccountData;
    }

    namespace Channel
    {
        class ChannelPlayerCommand;
        class JoinChannel;
        class LeaveChannel;
    }

    namespace Chat
    {
        class ChatMessage;
        class ChatMessageWhisper;
        class ChatMessageChannel;
        class ChatAddonMessage;
        class ChatAddonMessageWhisper;
        class ChatMessageAFK;
        class ChatMessageDND;
        class ChatMessageEmote;
        class CTextEmote;
        class EmoteClient;
    }

    namespace Combat
    {
        class AttackSwing;
        class AttackStop;
        class SetSheathed;
    }

    namespace Duel
    {
        class DuelResponse;
    }

    namespace EquipmentSet
    {
        class SaveEquipmentSet;
    }

    namespace GameObject
    {
        class GameObjectReportUse;
        class GameObjectUse;
    }

    namespace Guild
    {
        class QueryGuildInfo;
        class GuildInviteByName;
        class AcceptGuildInvite;
        class DeclineGuildInvites;
        class GuildDeclineInvitation;
        class GuildGetRoster;
        class GuildPromoteMember;
        class GuildDemoteMember;
        class GuildOfficerRemoveMember;
        class GuildAssignMemberRank;
        class GuildLeave;
        class GuildDelete;
        class GuildUpdateMotdText;
        class GuildGetRanks;
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
        class RequestGuildPartyState;
        class RequestGuildRewardsList;
        class GuildQueryNews;
        class GuildNewsUpdateSticky;
        class GuildSetGuildMaster;
        class GuildChallengeUpdateRequest;
        class SaveGuildEmblem;
    }

    namespace Inspect
    {
        class Inspect;
        class InspectPVPRequest;
        class QueryInspectAchievements;
        class RequestHonorStats;
    }

    namespace Item
    {
        class AutoEquipItem;
        class AutoStoreBagItem;
        class BuyItem;
        class BuyBackItem;
        class DestroyItem;
        class GetItemPurchaseData;
        class RepairItem;
        class SellItem;
        class SplitItem;
        class SwapInvItem;
        class SwapItem;
    }

    namespace Loot
    {
        class LootUnit;
        class AutoStoreLootItem;
        class LootRelease;
        class LootMoney;
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
        class AreaTrigger;
        class SetSelection;
        class ViolenceLevel;
        class TimeSyncResponse;
        class TutorialSetFlag;
        class SetDungeonDifficulty;
        class SetRaidDifficulty;
        class PortGraveyard;
        class ReclaimCorpse;
        class RepopRequest;
        class RequestCemeteryList;
        class ResurrectResponse;
        class StandStateChange;
        class UITimeRequest;
    }

    namespace Movement
    {
        class ClientPlayerMovement;
        class WorldPortAck;
        class MoveTeleportAck;
    }

    namespace NPC
    {
        class Hello;
        class GossipSelectOption;
    }

    namespace Petition
    {
        class DeclinePetition;
        class OfferPetition;
        class PetitionBuy;
        class PetitionRenameGuild;
        class PetitionShowList;
        class PetitionShowSignatures;
        class QueryPetition;
        class SignPetition;
        class TurnInPetition;
    }

    namespace Query
    {
        class QueryCreature;
        class QueryPlayerName;
        class QueryPageText;
        class QueryNPCText;
        class DBQueryBulk;
        class QueryGameObject;
        class QueryCorpseLocationFromClient;
        class QueryCorpseTransport;
        class QueryTime;
    }

    namespace Quest
    {
        class QuestGiverStatusQuery;
        class QuestGiverStatusMultipleQuery;
        class QuestGiverHello;
        class QueryQuestInfo;
        class QuestGiverChooseReward;
        class QuestGiverCompleteQuest;
        class QuestGiverRequestReward;
        class QuestGiverQueryQuest;
    }

    namespace Social
    {
        class AddFriend;
        class AddIgnore;
        class DelFriend;
        class DelIgnore;
        class SendContactList;
        class SetContactNotes;
    }

    namespace Spells
    {
        class CancelAura;
        class CastSpell;
        class PetCastSpell;
        class UseItem;
        class SetActionButton;
    }

    namespace Talent
    {
        class SetSpecialization;
        class LearnTalents;
    }

    namespace Ticket
    {
        class GMSurveySubmit;
        class GMTicketAcknowledgeSurvey;
        class GMTicketCreate;
        class GMTicketDelete;
        class GMTicketGetSystemStatus;
        class GMTicketGetCaseStatus;
        class GMTicketGetTicket;
        class GMTicketResponseResolve;
        class GMTicketUpdateText;
        class SupportTicketSubmitBug;
        class SupportTicketSubmitSuggestion;
        class SupportTicketSubmitComplaint;
    }

    namespace Trade
    {
        class CancelTrade;
    }

    namespace Who
    {
        class WhoIsRequest;
        class WhoRequestPkt;
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

#define REGISTERED_ADDON_PREFIX_SOFTCAP 64

enum TutorialAction
{
    TUTORIAL_ACTION_UPDATE = 0,
    TUTORIAL_ACTION_CLEAR  = 1,
    TUTORIAL_ACTION_RESET  = 2
};

/*
enum Tutorials
{
    TUTORIAL_TALENT                   = 0,
    TUTORIAL_SPEC                     = 1,
    TUTORIAL_GLYPH                    = 2,
    TUTORIAL_SPELLBOOK                = 3,
    TUTORIAL_PROFESSIONS              = 4,
    TUTORIAL_CORE_ABILITITES          = 5,
    TUTORIAL_PET_JOURNAL              = 6,
    TUTORIAL_WHAT_HAS_CHANGED         = 7,
    TUTORIAL_GARRISON_BUILDING        = 8,
    TUTORIAL_GARRISON_MISSION_LIST    = 9,
    TUTORIAL_GARRISON_MISSION_PAGE    = 10,
    TUTORIAL_GARRISON_LANDING         = 11,
    TUTORIAL_GARRISON_ZONE_ABILITY    = 12,
    TUTORIAL_WORLD_MAP_FRAME          = 13,
    TUTORIAL_CLEAN_UP_BAGS            = 14,
    TUTORIAL_BAG_SETTINGS             = 15,
    TUTORIAL_REAGENT_BANK_UNLOCK      = 16,
    TUTORIAL_TOYBOX_FAVORITE          = 17,
    TUTORIAL_TOYBOX_MOUSEWHEEL_PAGING = 18,
    TUTORIAL_LFG_LIST                 = 19
};
*/

#define MAX_ACCOUNT_TUTORIAL_VALUES 8

struct AccountData
{
    time_t Time = 0;
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

enum CharterTypes
{
    GUILD_CHARTER_TYPE                            = 4,
    ARENA_TEAM_CHARTER_2v2_TYPE                   = 2,
    ARENA_TEAM_CHARTER_3v3_TYPE                   = 3,
    ARENA_TEAM_CHARTER_5v5_TYPE                   = 5,
};

enum DeclinedNameResult
{
    DECLINED_NAMES_RESULT_SUCCESS = 0,
    DECLINED_NAMES_RESULT_ERROR   = 1
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
    virtual bool ProcessLogout() const override { return false; }
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

struct PacketCounter
{
    time_t lastReceiveTime;
    uint32 amountCounter;
};

/// Player session in the World
class WorldSession
{
    public:
        WorldSession(uint32 id, uint32 battlenetAccountId, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter);
        ~WorldSession();

        bool PlayerLoading() const { return !m_playerLoading.IsEmpty(); }
        bool PlayerLogout() const { return m_playerLogout; }
        bool PlayerLogoutWithSave() const { return m_playerLogout && m_playerSave; }
        bool PlayerRecentlyLoggedOut() const { return m_playerRecentlyLogout; }

        void ReadAddonsInfo(ByteBuffer& data);
        void SendAddonsInfo();
        bool IsAddonRegistered(const std::string& prefix) const;

        void SendPacket(WorldPacket const* packet, bool forced = false);
        void AddInstanceConnection(std::shared_ptr<WorldSocket> sock) { m_Socket[1] = sock; }

        void SendNotification(char const* format, ...) ATTR_PRINTF(2, 3);
        void SendNotification(uint32 stringId, ...);
        void SendPetNameInvalid(uint32 error, std::string const& name, DeclinedName *declinedName);
        void SendPartyResult(PartyOperation operation, std::string const& member, PartyResult res, uint32 val = 0);
        void SendAreaTriggerMessage(const char* Text, ...) ATTR_PRINTF(2, 3);
        void SendSetPhaseShift(std::set<uint32> const& phaseIds, std::set<uint32> const& terrainswaps, std::set<uint32> const& worldMapAreaSwaps);
        void SendQueryTimeResponse();

        void SendAuthResponse(uint8 code, bool queued, uint32 queuePos = 0);
        void SendClientCacheVersion(uint32 version);

        rbac::RBACData* GetRBACData();
        bool HasPermission(uint32 permissionId);
        void LoadPermissions();
        void InvalidateRBACData(); // Used to force LoadPermissions at next HasPermission check

        AccountTypes GetSecurity() const { return _security; }
        uint32 GetAccountId() const { return _accountId; }
        ObjectGuid GetAccountGUID() const { return ObjectGuid::Create<HighGuid::WowAccount>(GetAccountId()); }
        uint32 GetBattlenetAccountId() const { return _battlenetAccountId; }
        ObjectGuid GetBattlenetAccountGUID() const { return ObjectGuid::Create<HighGuid::BNetAccount>(GetBattlenetAccountId()); }
        Player* GetPlayer() const { return _player; }
        std::string const& GetPlayerName() const;
        std::string GetPlayerInfo() const;

        void SetSecurity(AccountTypes security) { _security = security; }
        std::string const& GetRemoteAddress() { return m_Address; }
        void SetPlayer(Player* player);
        uint8 GetExpansion() const { return m_expansion; }

        void InitWarden(BigNumber* k, std::string const& os);

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
        void KickPlayer();

        void QueuePacket(WorldPacket* new_packet);
        bool Update(uint32 diff, PacketFilter& updater);

        /// Handle the authentication waiting queue (to be completed)
        void SendAuthWaitQue(uint32 position);

        void SendSetTimeZoneInformation();
        void SendFeatureSystemStatus();
        void SendFeatureSystemStatusGlueScreen();

        void SendNameQueryOpcode(ObjectGuid guid);

        void SendTrainerList(ObjectGuid guid);
        void SendTrainerList(ObjectGuid guid, std::string const& strTitle);
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
        void SendPetNameQuery(ObjectGuid guid, uint32 petnumber);
        void SendStablePet(ObjectGuid guid);
        void SendStablePetCallback(PreparedQueryResult result, ObjectGuid guid);
        void SendPetStableResult(uint8 guid);
        bool CheckStableMaster(ObjectGuid guid);

        // Account Data
        AccountData const* GetAccountData(AccountDataType type) const { return &_accountData[type]; }
        void SetAccountData(AccountDataType type, uint32 time, std::string const& data);
        void LoadGlobalAccountData();
        void LoadAccountData(PreparedQueryResult result, uint32 mask);

        void LoadTutorialsData();
        void SendTutorialsData();
        void SaveTutorialsData(SQLTransaction& trans);
        uint32 GetTutorialInt(uint8 index) const { return _tutorials[index]; }
        void SetTutorialInt(uint8 index, uint32 value)
        {
            if (_tutorials[index] != value)
            {
                _tutorials[index] = value;
                _tutorialsChanged = true;
            }
        }
        //used with item_page table
        bool SendItemInfo(uint32 itemid, WorldPacket data);
        //auction
        void SendAuctionHello(ObjectGuid guid, Creature* unit);

        /**
         * @fn  void WorldSession::SendAuctionCommandResult(AuctionEntry* auction, uint32 Action, uint32 ErrorCode, uint32 bidError = 0);
         *
         * @brief   Notifies the client of the result of his last auction operation. It is called when the player bids, creates, or deletes an auction
         *
         * @param   auction         The relevant auction object
         * @param   Action          The action that was performed.
         * @param   ErrorCode       The resulting error code.
         * @param   bidError        (Optional) the bid error.
         */
        void SendAuctionCommandResult(AuctionEntry* auction, uint32 Action, uint32 ErrorCode, uint32 bidError = 0);

        void SendAuctionBidderNotification(uint32 location, uint32 auctionId, ObjectGuid bidder, uint32 bidSum, uint32 diff, uint32 item_template);
        void SendAuctionOwnerNotification(AuctionEntry* auction);
        void SendAuctionRemovedNotification(uint32 auctionId, uint32 itemEntry, int32 randomPropertyId);

        // Black Market
        void SendBlackMarketOpenResult(ObjectGuid guid, Creature* auctioneer);

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
        time_t m_muteTime;

        // Locales
        LocaleConstant GetSessionDbcLocale() const { return m_sessionDbcLocale; }
        LocaleConstant GetSessionDbLocaleIndex() const { return m_sessionDbLocaleIndex; }
        char const* GetTrinityString(uint32 entry) const;

        uint32 GetLatency() const { return m_latency; }
        void SetLatency(uint32 latency) { m_latency = latency; }
        void ResetClientTimeDelay() { m_clientTimeDelay = 0; }

        std::atomic<int32> m_timeOutTime;

        void UpdateTimeOutTime(uint32 diff)
        {
            m_timeOutTime -= int32(diff);
        }

        void ResetTimeOutTime()
        {
            m_timeOutTime = int32(sWorld->getIntConfig(CONFIG_SOCKET_TIMEOUTTIME));
        }

        bool IsConnectionIdle() const
        {
            return m_timeOutTime <= 0 && !m_inQueue;
        }

        // Recruit-A-Friend Handling
        uint32 GetRecruiterId() const { return recruiterId; }
        bool IsARecruiter() const { return isRecruiter; }

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPacket& recvPacket);          // not used
        void Handle_EarlyProccess(WorldPacket& recvPacket); // just mark packets processed in WorldSocket::OnRead
        void Handle_ServerSide(WorldPacket& recvPacket);    // sever side only, can't be accepted from client

        void HandleCharEnum(PreparedQueryResult result);
        void HandleCharEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/);
        void HandleCharUndeleteEnum(PreparedQueryResult result);
        void HandleCharUndeleteEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/);
        void HandleCharDeleteOpcode(WorldPackets::Character::DeleteChar& charDelete);
        void HandleCharCreateOpcode(WorldPackets::Character::CreateChar& charCreate);
        void HandleCharCreateCallback(PreparedQueryResult result, WorldPackets::Character::CharacterCreateInfo* createInfo);
        void HandlePlayerLoginOpcode(WorldPackets::Character::PlayerLogin& playerLogin);

        void SendConnectToInstance(WorldPackets::Auth::ConnectToSerial serial);
        void HandleContinuePlayerLogin();
        void AbortLogin(WorldPackets::Character::LoginFailureReason reason);
        void HandleLoadScreenOpcode(WorldPackets::Character::LoadingScreenNotify& loadingScreenNotify);
        void HandlePlayerLogin(LoginQueryHolder * holder);
        void HandleCharRenameOpcode(WorldPackets::Character::CharacterRenameRequest& request);
        void HandleCharRenameCallBack(PreparedQueryResult result, WorldPackets::Character::CharacterRenameInfo* renameInfo);
        void HandleSetPlayerDeclinedNames(WorldPacket& recvData);
        void HandleAlterAppearance(WorldPacket& recvData);
        void HandleCharCustomizeOpcode(WorldPackets::Character::CharCustomize& packet);
        void HandleCharCustomizeCallback(PreparedQueryResult result, WorldPackets::Character::CharCustomizeInfo* customizeInfo);
        void HandleCharRaceOrFactionChangeOpcode(WorldPackets::Character::CharRaceOrFactionChange& packet);
        void HandleCharRaceOrFactionChangeCallback(PreparedQueryResult result, WorldPackets::Character::CharRaceOrFactionChangeInfo* factionChangeInfo);
        void HandleRandomizeCharNameOpcode(WorldPackets::Character::GenerateRandomCharacterName& packet);
        void HandleReorderCharacters(WorldPackets::Character::ReorderCharacters& reorderChars);
        void HandleOpeningCinematic(WorldPacket& recvData);
        void HandleGetUndeleteCooldownStatus(WorldPackets::Character::GetUndeleteCooldownStatus& /*getCooldown*/);
        void HandleUndeleteCooldownStatusCallback(PreparedQueryResult result);
        void HandleCharUndeleteOpcode(WorldPackets::Character::UndeleteCharacter& undeleteInfo);
        void HandleCharUndeleteCallback(PreparedQueryResult result, WorldPackets::Character::CharacterUndeleteInfo* undeleteInfo);

        void SendCharCreate(ResponseCodes result);
        void SendCharDelete(ResponseCodes result);
        void SendCharRename(ResponseCodes result, WorldPackets::Character::CharacterRenameInfo const* renameInfo);
        void SendCharCustomize(ResponseCodes result, WorldPackets::Character::CharCustomizeInfo const* customizeInfo);
        void SendCharFactionChange(ResponseCodes result, WorldPackets::Character::CharRaceOrFactionChangeInfo const* factionChangeInfo);
        void SendSetPlayerDeclinedNamesResult(DeclinedNameResult result, ObjectGuid guid);
        void SendBarberShopResult(BarberShopResult result);
        void SendUndeleteCooldownStatusResponse(uint32 currentCooldown, uint32 maxCooldown);
        void SendUndeleteCharacterResponse(CharacterUndeleteResult result, WorldPackets::Character::CharacterUndeleteInfo const* undeleteInfo);

        // played time
        void HandlePlayedTime(WorldPackets::Character::PlayedTimeClient& packet);

        // new
        void HandleMoveUnRootAck(WorldPacket& recvPacket);
        void HandleMoveRootAck(WorldPacket& recvPacket);
        void HandleLookingForGroup(WorldPacket& recvPacket);

        // cemetery/graveyard related
        void HandlePortGraveyard(WorldPackets::Misc::PortGraveyard& packet);
        void HandleRequestCemeteryList(WorldPackets::Misc::RequestCemeteryList& packet);

        // Inspect
        void HandleInspectOpcode(WorldPackets::Inspect::Inspect& inspect);
        void HandleRequestHonorStatsOpcode(WorldPackets::Inspect::RequestHonorStats& request);
        void HandleInspectPVP(WorldPackets::Inspect::InspectPVPRequest& request);
        void HandleQueryInspectAchievements(WorldPackets::Inspect::QueryInspectAchievements& inspect);

        void HandleMoveWaterWalkAck(WorldPacket& recvPacket);
        void HandleFeatherFallAck(WorldPacket& recvData);

        void HandleMoveHoverAck(WorldPacket& recvData);

        void HandleMountSpecialAnimOpcode(WorldPacket& recvdata);

        // character view
        void HandleShowingHelmOpcode(WorldPackets::Character::ShowingHelm& packet);
        void HandleShowingCloakOpcode(WorldPackets::Character::ShowingCloak& packet);

        // repair
        void HandleRepairItemOpcode(WorldPackets::Item::RepairItem& packet);

        // Knockback
        void HandleMoveKnockBackAck(WorldPacket& recvPacket);

        void HandleMoveTeleportAck(WorldPackets::Movement::MoveTeleportAck& packet);
        void HandleForceSpeedChangeAck(WorldPacket& recvData);
        void HandleSetCollisionHeightAck(WorldPacket& recvPacket);

        void HandlePingOpcode(WorldPacket& recvPacket);
        void HandleRepopRequest(WorldPackets::Misc::RepopRequest& packet);
        void HandleAutostoreLootItemOpcode(WorldPackets::Loot::AutoStoreLootItem& packet);
        void HandleLootMoneyOpcode(WorldPackets::Loot::LootMoney& packet);
        void HandleLootOpcode(WorldPackets::Loot::LootUnit& packet);
        void HandleLootReleaseOpcode(WorldPackets::Loot::LootRelease& packet);
        void HandleLootMasterGiveOpcode(WorldPacket& recvPacket);
        void HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest);
        void HandleLogoutRequestOpcode(WorldPackets::Character::LogoutRequest& logoutRequest);
        void HandleLogoutCancelOpcode(WorldPackets::Character::LogoutCancel& logoutCancel);

        // GM Ticket opcodes
        void HandleGMTicketCreateOpcode(WorldPackets::Ticket::GMTicketCreate& packet);
        void HandleGMTicketUpdateTextOpcode(WorldPackets::Ticket::GMTicketUpdateText& packet);
        void HandleGMTicketDeleteOpcode(WorldPackets::Ticket::GMTicketDelete& packet);
        void HandleGMTicketGetCaseStatusOpcode(WorldPackets::Ticket::GMTicketGetCaseStatus& packet);
        void HandleGMTicketGetTicketOpcode(WorldPackets::Ticket::GMTicketGetTicket& packet);
        void HandleGMTicketSystemStatusOpcode(WorldPackets::Ticket::GMTicketGetSystemStatus& packet);
        void HandleGMSurveySubmit(WorldPackets::Ticket::GMSurveySubmit& packet);
        void HandleGMResponseResolve(WorldPackets::Ticket::GMTicketResponseResolve& packet);
        void HandleSupportTicketSubmitBug(WorldPackets::Ticket::SupportTicketSubmitBug& packet);
        void HandleSupportTicketSubmitSuggestion(WorldPackets::Ticket::SupportTicketSubmitSuggestion& packet);
        void HandleSupportTicketSubmitComplaint(WorldPackets::Ticket::SupportTicketSubmitComplaint& packet);

        void HandleTogglePvP(WorldPacket& recvPacket);

        void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
        void HandleSetSelectionOpcode(WorldPackets::Misc::SetSelection& packet);
        void HandleStandStateChangeOpcode(WorldPackets::Misc::StandStateChange& packet);
        void HandleEmoteOpcode(WorldPackets::Chat::EmoteClient& packet);

        // Social
        void HandleContactListOpcode(WorldPackets::Social::SendContactList& packet);
        void HandleAddFriendOpcode(WorldPackets::Social::AddFriend& packet);
        void HandleAddFriendOpcodeCallBack(PreparedQueryResult result, std::string const& friendNote);
        void HandleDelFriendOpcode(WorldPackets::Social::DelFriend& packet);
        void HandleAddIgnoreOpcode(WorldPackets::Social::AddIgnore& packet);
        void HandleAddIgnoreOpcodeCallBack(PreparedQueryResult result);
        void HandleDelIgnoreOpcode(WorldPackets::Social::DelIgnore& packet);
        void HandleSetContactNotesOpcode(WorldPackets::Social::SetContactNotes& packet);

        void HandleBugReportOpcode(WorldPacket& recvPacket);

        void HandleAreaTriggerOpcode(WorldPackets::Misc::AreaTrigger& packet);

        void HandleSetFactionAtWar(WorldPacket& recvData);
        void HandleSetFactionCheat(WorldPacket& recvData);
        void HandleSetWatchedFactionOpcode(WorldPacket& recvData);
        void HandleSetFactionInactiveOpcode(WorldPacket& recvData);

        void HandleUpdateAccountData(WorldPackets::ClientConfig::UserClientUpdateAccountData& packet);
        void HandleRequestAccountData(WorldPackets::ClientConfig::RequestAccountData& request);
        void HandleSetActionButtonOpcode(WorldPackets::Spells::SetActionButton& packet);

        void HandleGameObjectUseOpcode(WorldPackets::GameObject::GameObjectUse& packet);
        void HandleMeetingStoneInfo(WorldPacket& recPacket);
        void HandleGameobjectReportUse(WorldPackets::GameObject::GameObjectReportUse& packet);

        void HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& packet);
        void HandleQueryTimeOpcode(WorldPackets::Query::QueryTime& queryTime);
        void HandleCreatureQuery(WorldPackets::Query::QueryCreature& packet);
        void HandleDBQueryBulk(WorldPackets::Query::DBQueryBulk& packet);

        void HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& packet);

        void HandleMoveWorldportAckOpcode(WorldPackets::Movement::WorldPortAck& packet);
        void HandleMoveWorldportAckOpcode();                // for server-side calls

        void HandleMovementOpcodes(WorldPackets::Movement::ClientPlayerMovement& packet);
        void HandleSetActiveMoverOpcode(WorldPacket& recvData);
        void HandleMoveNotActiveMover(WorldPacket& recvData);
        void HandleDismissControlledVehicle(WorldPacket& recvData);
        void HandleRequestVehicleExit(WorldPacket& recvData);
        void HandleChangeSeatsOnControlledVehicle(WorldPacket& recvData);
        void HandleMoveTimeSkippedOpcode(WorldPacket& recvData);

        void HandleRequestRaidInfoOpcode(WorldPacket& recvData);

        void HandleRequestBattlefieldStatusOpcode(WorldPacket& recvData);
        void HandleBattleMasterHelloOpcode(WorldPacket& recvData);

        void HandleGroupInviteOpcode(WorldPacket& recvPacket);
        //void HandleGroupCancelOpcode(WorldPacket& recvPacket);
        void HandleGroupInviteResponseOpcode(WorldPacket& recvPacket);
        void HandleGroupUninviteOpcode(WorldPacket& recvPacket);
        void HandleGroupSetLeaderOpcode(WorldPacket& recvPacket);
        void HandleGroupSetRolesOpcode(WorldPacket& recvData);
        void HandleGroupDisbandOpcode(WorldPacket& recvPacket);
        void HandleOptOutOfLootOpcode(WorldPacket& recvData);
        void HandleLootMethodOpcode(WorldPacket& recvPacket);
        void HandleLootRoll(WorldPacket& recvData);
        void HandleRequestPartyMemberStatsOpcode(WorldPacket& recvData);
        void HandleRaidTargetUpdateOpcode(WorldPacket& recvData);
        void HandleRaidReadyCheckOpcode(WorldPacket& recvData);
        void HandleGroupRaidConvertOpcode(WorldPacket& recvData);
        void HandleGroupRequestJoinUpdates(WorldPacket& recvData);
        void HandleGroupChangeSubGroupOpcode(WorldPacket& recvData);
        void HandleGroupSwapSubGroupOpcode(WorldPacket& recvData);
        void HandleGroupAssistantLeaderOpcode(WorldPacket& recvData);
        void HandlePartyAssignmentOpcode(WorldPacket& recvData);
        void HandleRolePollBeginOpcode(WorldPacket& recvData);

        void HandleDeclinePetition(WorldPackets::Petition::DeclinePetition& packet);
        void HandleOfferPetition(WorldPackets::Petition::OfferPetition& packet);
        void HandlePetitionBuy(WorldPackets::Petition::PetitionBuy& packet);
        void HandlePetitionShowSignatures(WorldPackets::Petition::PetitionShowSignatures& packet);
        void HandleQueryPetition(WorldPackets::Petition::QueryPetition& packet);
        void HandlePetitionRenameGuild(WorldPackets::Petition::PetitionRenameGuild& packet);
        void HandleSignPetition(WorldPackets::Petition::SignPetition& packet);
        void HandleTurnInPetition(WorldPackets::Petition::TurnInPetition& packet);

        void HandleGuildQueryOpcode(WorldPackets::Guild::QueryGuildInfo& query);
        void HandleGuildInviteByName(WorldPackets::Guild::GuildInviteByName& packet);
        void HandleGuildOfficerRemoveMember(WorldPackets::Guild::GuildOfficerRemoveMember& packet);
        void HandleGuildAcceptInvite(WorldPackets::Guild::AcceptGuildInvite& invite);
        void HandleGuildDeclineInvitation(WorldPackets::Guild::GuildDeclineInvitation& decline);
        void HandleGuildEventLogQuery(WorldPackets::Guild::GuildEventLogQuery& packet);
        void HandleGuildGetRoster(WorldPackets::Guild::GuildGetRoster& packet);
        void HandleRequestGuildRewardsList(WorldPackets::Guild::RequestGuildRewardsList& packet);
        void HandleGuildPromoteMember(WorldPackets::Guild::GuildPromoteMember& promote);
        void HandleGuildDemoteMember(WorldPackets::Guild::GuildDemoteMember& demote);
        void HandleGuildAssignRank(WorldPackets::Guild::GuildAssignMemberRank& packet);
        void HandleGuildLeave(WorldPackets::Guild::GuildLeave& leave);
        void HandleGuildDelete(WorldPackets::Guild::GuildDelete& packet);
        void HandleGuildSetAchievementTracking(WorldPacket& recvPacket);
        void HandleGuildSetGuildMaster(WorldPackets::Guild::GuildSetGuildMaster& packet);
        void HandleGuildUpdateMotdText(WorldPackets::Guild::GuildUpdateMotdText& packet);
        void HandleGuildNewsUpdateSticky(WorldPackets::Guild::GuildNewsUpdateSticky& packet);
        void HandleGuildSetMemberNote(WorldPackets::Guild::GuildSetMemberNote& packet);
        void HandleGuildGetRanks(WorldPackets::Guild::GuildGetRanks& packet);
        void HandleGuildQueryNews(WorldPackets::Guild::GuildQueryNews& newsQuery);
        void HandleGuildSetRankPermissions(WorldPackets::Guild::GuildSetRankPermissions& packet);
        void HandleGuildAddRank(WorldPackets::Guild::GuildAddRank& packet);
        void HandleGuildDeleteRank(WorldPackets::Guild::GuildDeleteRank& packet);
        void HandleGuildUpdateInfoText(WorldPackets::Guild::GuildUpdateInfoText& packet);
        void HandleSaveGuildEmblem(WorldPackets::Guild::SaveGuildEmblem& packet);
        void HandleGuildRequestPartyState(WorldPackets::Guild::RequestGuildPartyState& packet);
        void HandleGuildChallengeUpdateRequest(WorldPackets::Guild::GuildChallengeUpdateRequest& packet);
        void HandleDeclineGuildInvites(WorldPackets::Guild::DeclineGuildInvites& packet);

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

        void HandleTabardVendorActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleBankerActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleBuyBankSlotOpcode(WorldPacket& recvPacket);
        void HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet);
        void HandleTrainerBuySpellOpcode(WorldPacket& recvPacket);
        void HandlePetitionShowList(WorldPackets::Petition::PetitionShowList& packet);
        void HandleGossipHelloOpcode(WorldPackets::NPC::Hello& packet);
        void HandleGossipSelectOptionOpcode(WorldPackets::NPC::GossipSelectOption& packet);
        void HandleSpiritHealerActivateOpcode(WorldPacket& recvPacket);
        void HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet);
        void HandleBinderActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleListStabledPetsOpcode(WorldPacket& recvPacket);
        void HandleStablePet(WorldPacket& recvPacket);
        void HandleStablePetCallback(PreparedQueryResult result);
        void HandleUnstablePet(WorldPacket& recvPacket);
        void HandleUnstablePetCallback(PreparedQueryResult result, uint32 petId);
        void HandleBuyStableSlot(WorldPacket& recvPacket);
        void HandleStableRevivePet(WorldPacket& recvPacket);
        void HandleStableSwapPet(WorldPacket& recvPacket);
        void HandleStableSwapPetCallback(PreparedQueryResult result, uint32 petId);
        void SendTrainerBuyFailed(ObjectGuid guid, uint32 spellId, uint32 reason);

        void HandleDuelResponseOpcode(WorldPackets::Duel::DuelResponse& duelResponse);
        void HandleDuelAccepted();
        void HandleDuelCancelled();

        void HandleAcceptTradeOpcode(WorldPacket& recvPacket);
        void HandleBeginTradeOpcode(WorldPacket& recvPacket);
        void HandleBusyTradeOpcode(WorldPacket& recvPacket);
        void HandleCancelTradeOpcode(WorldPackets::Trade::CancelTrade& cancelTrade);
        void HandleClearTradeItemOpcode(WorldPacket& recvPacket);
        void HandleIgnoreTradeOpcode(WorldPacket& recvPacket);
        void HandleInitiateTradeOpcode(WorldPacket& recvPacket);
        void HandleSetTradeGoldOpcode(WorldPacket& recvPacket);
        void HandleSetTradeItemOpcode(WorldPacket& recvPacket);
        void HandleUnacceptTradeOpcode(WorldPacket& recvPacket);

        void HandleAuctionHelloOpcode(WorldPackets::AuctionHouse::AuctionHelloRequest& packet);
        void HandleAuctionListItems(WorldPacket& recvData);
        void HandleAuctionListBidderItems(WorldPacket& recvData);
        void HandleAuctionSellItem(WorldPacket& recvData);
        void HandleAuctionRemoveItem(WorldPacket& recvData);
        void HandleAuctionListOwnerItems(WorldPacket& recvData);
        void HandleAuctionPlaceBid(WorldPacket& recvData);
        void HandleAuctionListPendingSales(WorldPacket& recvData);

        // Black Market
        void HandleBlackMarketOpen(WorldPackets::BlackMarket::BlackMarketOpen& packet);

        void HandleGetMailList(WorldPackets::Mail::MailGetList& packet);
        void HandleSendMail(WorldPackets::Mail::SendMail& packet);
        void HandleMailTakeMoney(WorldPackets::Mail::MailTakeMoney& packet);
        void HandleMailTakeItem(WorldPackets::Mail::MailTakeItem& packet);
        void HandleMailMarkAsRead(WorldPackets::Mail::MailMarkAsRead& packet);
        void HandleMailReturnToSender(WorldPackets::Mail::MailReturnToSender& packet);
        void HandleMailDelete(WorldPackets::Mail::MailDelete& packet);
        void HandleItemTextQuery(WorldPacket& recvData);
        void HandleMailCreateTextItem(WorldPackets::Mail::MailCreateTextItem& packet);
        void HandleQueryNextMailTime(WorldPackets::Mail::MailQueryNextMailTime& packet);
        void HandleCancelChanneling(WorldPacket& recvData);

        void SendItemPageInfo(ItemTemplate* itemProto);
        void HandleSplitItemOpcode(WorldPackets::Item::SplitItem& splitItem);
        void HandleSwapInvItemOpcode(WorldPackets::Item::SwapInvItem& swapInvItem);
        void HandleDestroyItemOpcode(WorldPackets::Item::DestroyItem& destroyItem);
        void HandleAutoEquipItemOpcode(WorldPackets::Item::AutoEquipItem& autoEquipItem);
        void HandleSellItemOpcode(WorldPackets::Item::SellItem& packet);
        void HandleBuyItemInSlotOpcode(WorldPacket& recvPacket);
        void HandleBuyItemOpcode(WorldPackets::Item::BuyItem& packet);
        void HandleListInventoryOpcode(WorldPackets::NPC::Hello& packet);
        void HandleAutoStoreBagItemOpcode(WorldPackets::Item::AutoStoreBagItem& packet);
        void HandleReadItem(WorldPacket& recvPacket);
        void HandleAutoEquipItemSlotOpcode(WorldPacket& recvPacket);
        void HandleSwapItem(WorldPackets::Item::SwapItem& swapItem);
        void HandleBuybackItem(WorldPackets::Item::BuyBackItem& packet);
        void HandleAutoBankItemOpcode(WorldPacket& recvPacket);
        void HandleAutoStoreBankItemOpcode(WorldPacket& recvPacket);
        void HandleWrapItemOpcode(WorldPacket& recvPacket);

        void HandleAttackSwingOpcode(WorldPackets::Combat::AttackSwing& packet);
        void HandleAttackStopOpcode(WorldPackets::Combat::AttackStop& packet);
        void HandleSetSheathedOpcode(WorldPackets::Combat::SetSheathed& packet);

        void HandleUseItemOpcode(WorldPackets::Spells::UseItem& packet);
        void HandleOpenItemOpcode(WorldPacket& recvPacket);
        void HandleCastSpellOpcode(WorldPackets::Spells::CastSpell& castRequest);
        void HandleCancelCastOpcode(WorldPacket& recvPacket);
        void HandleCancelAuraOpcode(WorldPackets::Spells::CancelAura& cancelAura);
        void HandleCancelGrowthAuraOpcode(WorldPacket& recvPacket);
        void HandleCancelAutoRepeatSpellOpcode(WorldPacket& recvPacket);

        void HandleLearnTalentsOpcode(WorldPackets::Talent::LearnTalents& packet);
        void HandleConfirmRespecWipeOpcode(WorldPacket& recvPacket);
        void HandleUnlearnSkillOpcode(WorldPacket& recvPacket);
        void HandleSetSpecializationOpcode(WorldPackets::Talent::SetSpecialization& packet);

        void HandleQuestgiverStatusQueryOpcode(WorldPackets::Quest::QuestGiverStatusQuery& packet);
        void HandleQuestgiverStatusMultipleQuery(WorldPackets::Quest::QuestGiverStatusMultipleQuery& packet);
        void HandleQuestgiverHelloOpcode(WorldPackets::Quest::QuestGiverHello& packet);
        void HandleQuestgiverAcceptQuestOpcode(WorldPacket& recvPacket);
        void HandleQuestgiverQueryQuestOpcode(WorldPackets::Quest::QuestGiverQueryQuest& packet);
        void HandleQuestgiverChooseRewardOpcode(WorldPackets::Quest::QuestGiverChooseReward& packet);
        void HandleQuestgiverRequestRewardOpcode(WorldPackets::Quest::QuestGiverRequestReward& packet);
        void HandleQuestQueryOpcode(WorldPackets::Quest::QueryQuestInfo& packet);
        void HandleQuestgiverCancel(WorldPacket& recvData);
        void HandleQuestLogSwapQuest(WorldPacket& recvData);
        void HandleQuestLogRemoveQuest(WorldPacket& recvData);
        void HandleQuestConfirmAccept(WorldPacket& recvData);
        void HandleQuestgiverCompleteQuest(WorldPackets::Quest::QuestGiverCompleteQuest& packet);
        void HandleQuestgiverQuestAutoLaunch(WorldPacket& recvPacket);
        void HandlePushQuestToParty(WorldPacket& recvPacket);
        void HandleQuestPushResult(WorldPacket& recvPacket);

        void HandleChatMessageOpcode(WorldPackets::Chat::ChatMessage& packet);
        void HandleChatMessageWhisperOpcode(WorldPackets::Chat::ChatMessageWhisper& packet);
        void HandleChatMessageChannelOpcode(WorldPackets::Chat::ChatMessageChannel& packet);
        void HandleChatMessage(ChatMsg type, uint32 lang, std::string msg, std::string target = "");
        void HandleChatAddonMessageOpcode(WorldPackets::Chat::ChatAddonMessage& packet);
        void HandleChatAddonMessageWhisperOpcode(WorldPackets::Chat::ChatAddonMessageWhisper& packet);
        void HandleChatAddonMessage(ChatMsg type, std::string prefix, std::string text, std::string target = "");
        void HandleChatMessageAFKOpcode(WorldPackets::Chat::ChatMessageAFK& packet);
        void HandleChatMessageDNDOpcode(WorldPackets::Chat::ChatMessageDND& packet);
        void HandleChatMessageEmoteOpcode(WorldPackets::Chat::ChatMessageEmote& packet);
        void SendPlayerNotFoundNotice(std::string const& name);
        void SendPlayerAmbiguousNotice(std::string const& name);
        void SendWrongFactionNotice();
        void SendChatRestrictedNotice(ChatRestrictionType restriction);
        void HandleTextEmoteOpcode(WorldPackets::Chat::CTextEmote& packet);
        void HandleChatIgnoredOpcode(WorldPacket& recvPacket);

        void HandleUnregisterAddonPrefixesOpcode(WorldPacket& recvPacket);
        void HandleAddonRegisteredPrefixesOpcode(WorldPacket& recvPacket);

        void HandleReclaimCorpse(WorldPackets::Misc::ReclaimCorpse& packet);
        void HandleQueryCorpseLocation(WorldPackets::Query::QueryCorpseLocationFromClient& packet);
        void HandleQueryCorpseTransport(WorldPackets::Query::QueryCorpseTransport& packet);
        void HandleResurrectResponse(WorldPackets::Misc::ResurrectResponse& packet);
        void HandleSummonResponseOpcode(WorldPacket& recvData);

        void HandleJoinChannel(WorldPackets::Channel::JoinChannel& packet);
        void HandleLeaveChannel(WorldPackets::Channel::LeaveChannel& packet);

        template<void(Channel::*CommandFunction)(Player const*)>
        void HandleChannelCommand(WorldPackets::Channel::ChannelPlayerCommand& packet);

        template<void(Channel::*CommandFunction)(Player const*, std::string const&)>
        void HandleChannelPlayerCommand(WorldPackets::Channel::ChannelPlayerCommand& packet);

        void HandleVoiceSessionEnableOpcode(WorldPacket& recvData);
        void HandleSetActiveVoiceChannel(WorldPacket& recvData);

        void HandleCompleteCinematic(WorldPacket& recvPacket);
        void HandleNextCinematicCamera(WorldPacket& recvPacket);

        void HandlePageTextQueryOpcode(WorldPackets::Query::QueryPageText& packet);

        void HandleTutorialFlag(WorldPackets::Misc::TutorialSetFlag& packet);

        //Pet
        void HandlePetAction(WorldPacket& recvData);
        void HandlePetStopAttack(WorldPacket& recvData);
        void HandlePetActionHelper(Unit* pet, ObjectGuid guid1, uint32 spellid, uint16 flag, ObjectGuid guid2, float x, float y, float z);
        void HandlePetNameQuery(WorldPacket& recvData);
        void HandlePetSetAction(WorldPacket& recvData);
        void HandlePetAbandon(WorldPacket& recvData);
        void HandlePetRename(WorldPacket& recvData);
        void HandlePetCancelAuraOpcode(WorldPacket& recvPacket);
        void HandlePetSpellAutocastOpcode(WorldPacket& recvPacket);
        void HandlePetCastSpellOpcode(WorldPackets::Spells::PetCastSpell& castRequest);
        void HandlePetLearnTalent(WorldPacket& recvPacket);

        void HandleSetActionBarToggles(WorldPackets::Character::SetActionBarToggles& packet);

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
        void HandleRequestRatedBattlefieldInfo(WorldPacket& recvData);
        void HandleRequestPvpOptions(WorldPacket& recvData);
        void HandleRequestPvpReward(WorldPacket& recvData);
        void HandleRequestRatedBgStats(WorldPacket& recvData);

        // Battlefield
        void SendBfInvitePlayerToWar(ObjectGuid guid, uint32 zoneId, uint32 time);
        void SendBfInvitePlayerToQueue(ObjectGuid guid);
        void SendBfQueueInviteResponse(ObjectGuid guid, uint32 zoneId, bool canQueue = true, bool full = false);
        void SendBfEntered(ObjectGuid guid);
        void SendBfLeaveMessage(ObjectGuid guid, BFLeaveReason reason = BF_LEAVE_REASON_EXITED);
        void HandleBfQueueInviteResponse(WorldPacket& recvData);
        void HandleBfEntryInviteResponse(WorldPacket& recvData);
        void HandleBfExitRequest(WorldPacket& recvData);

        void HandleWardenDataOpcode(WorldPacket& recvData);
        void HandleWorldTeleportOpcode(WorldPacket& recvData);
        void HandleMinimapPingOpcode(WorldPacket& recvData);
        void HandleRandomRollOpcode(WorldPacket& recvData);
        void HandleFarSightOpcode(WorldPacket& recvData);
        void HandleSetDungeonDifficultyOpcode(WorldPackets::Misc::SetDungeonDifficulty& setDungeonDifficulty);
        void HandleSetRaidDifficultyOpcode(WorldPackets::Misc::SetRaidDifficulty& setRaidDifficulty);
        void HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData);
        void HandleSetTitleOpcode(WorldPacket& recvData);
        void HandleRealmSplitOpcode(WorldPacket& recvData);
        void HandleTimeSyncResponse(WorldPackets::Misc::TimeSyncResponse& packet);
        void HandleWhoisOpcode(WorldPackets::Who::WhoIsRequest& packet);
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

        void HandleGetItemPurchaseData(WorldPackets::Item::GetItemPurchaseData& packet);
        void HandleItemRefund(WorldPacket& recvData);

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

        // Void Storage
        void HandleVoidStorageUnlock(WorldPacket& recvData);
        void HandleVoidStorageQuery(WorldPacket& recvData);
        void HandleVoidStorageTransfer(WorldPacket& recvData);
        void HandleVoidSwapItem(WorldPacket& recvData);
        void SendVoidStorageTransferResult(VoidTransferError result);

        // Transmogrification
        void HandleTransmogrifyItems(WorldPacket& recvData);

        // Miscellaneous
        void HandleSpellClick(WorldPacket& recvData);
        void HandleMirrorImageDataRequest(WorldPacket& recvData);
        void HandleRemoveGlyph(WorldPacket& recvData);
        void HandleGuildSetFocusedAchievement(WorldPackets::Achievement::GuildSetFocusedAchievement& setFocusedAchievement);
        void HandleEquipmentSetSave(WorldPackets::EquipmentSet::SaveEquipmentSet& packet);
        void HandleEquipmentSetDelete(WorldPacket& recvData);
        void HandleEquipmentSetUse(WorldPacket& recvData);
        void HandleUITimeRequest(WorldPackets::Misc::UITimeRequest& /*request*/);
        void HandleQuestNPCQuery(WorldPacket& recvData);
        void HandleQuestPOIQuery(WorldPacket& recvData);
        void HandleEjectPassenger(WorldPacket& data);
        void HandleEnterPlayerVehicle(WorldPacket& data);
        void HandleUpdateProjectilePosition(WorldPacket& recvPacket);
        void HandleUpdateMissileTrajectory(WorldPacket& recvPacket);
        void HandleViolenceLevel(WorldPackets::Misc::ViolenceLevel& violenceLevel);
        void HandleObjectUpdateFailedOpcode(WorldPacket& recvPacket);
        void HandleRequestCategoryCooldowns(WorldPacket& recvPacket);

        void SendSpellCategoryCooldowns();

        int32 HandleEnableNagleAlgorithm();

        // Compact Unit Frames (4.x)
        void HandleSaveCUFProfiles(WorldPacket& recvPacket);
        void SendLoadCUFProfiles();

    private:
        void InitializeQueryCallbackParameters();
        void ProcessQueryCallbacks();

        PreparedQueryResultFuture _addIgnoreCallback;
        PreparedQueryResultFuture _stablePetCallback;
        QueryCallback<PreparedQueryResult, bool> _charEnumCallback;
        QueryCallback<PreparedQueryResult, std::string> _addFriendCallback;
        QueryCallback<PreparedQueryResult, uint32> _unstablePetCallback;
        QueryCallback<PreparedQueryResult, uint32> _stableSwapCallback;
        QueryCallback<PreparedQueryResult, ObjectGuid> _sendStabledPetCallback;
        QueryCallback<PreparedQueryResult, std::shared_ptr<WorldPackets::Character::CharacterCreateInfo>, true> _charCreateCallback;
        QueryCallback<PreparedQueryResult, std::shared_ptr<WorldPackets::Character::CharacterRenameInfo>> _charRenameCallback;
        QueryCallback<PreparedQueryResult, std::shared_ptr<WorldPackets::Character::CharCustomizeInfo>> _charCustomizeCallback;
        QueryCallback<PreparedQueryResult, std::shared_ptr<WorldPackets::Character::CharRaceOrFactionChangeInfo>> _charFactionChangeCallback;
        QueryCallback<PreparedQueryResult, bool, true> _undeleteCooldownStatusCallback;
        QueryCallback<PreparedQueryResult, std::shared_ptr<WorldPackets::Character::CharacterUndeleteInfo>, true> _charUndeleteCallback;
        QueryResultHolderFuture _charLoginCallback;

    friend class World;
    protected:
        class DosProtection
        {
            friend class World;
            public:
                DosProtection(WorldSession* s) : Session(s), _policy((Policy)sWorld->getIntConfig(CONFIG_PACKET_SPOOF_POLICY)) { }
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
        void LogUnexpectedOpcode(WorldPacket* packet, const char* status, const char *reason);
        void LogUnprocessedTail(WorldPacket* packet);

        // EnumData helpers
        bool IsLegitCharacterForAccount(ObjectGuid lowGUID)
        {
            return _legitCharacters.find(lowGUID) != _legitCharacters.end();
        }

        // this stores the GUIDs of the characters who can login
        // characters who failed on Player::BuildEnumData shouldn't login
        GuidSet _legitCharacters;

        ObjectGuid::LowType m_GUIDLow;                      // set logined or recently logout player (while m_playerRecentlyLogout set)
        Player* _player;
        std::shared_ptr<WorldSocket> m_Socket[MAX_CONNECTION_TYPES];
        std::string m_Address;                              // Current Remote Address
     // std::string m_LAddress;                             // Last Attempted Remote Adress - we can not set attempted ip for a non-existing session!

        AccountTypes _security;
        uint32 _accountId;
        uint32 _battlenetAccountId;
        uint8 m_expansion;

        typedef std::list<AddonInfo> AddonsList;

        // Warden
        Warden* _warden;                                    // Remains NULL if Warden system is not enabled by config

        time_t _logoutTime;
        bool m_inQueue;                                     // session wait in auth.queue
        ObjectGuid m_playerLoading;                         // code processed in LoginPlayer
        bool m_playerLogout;                                // code processed in LogoutPlayer
        bool m_playerRecentlyLogout;
        bool m_playerSave;
        LocaleConstant m_sessionDbcLocale;
        LocaleConstant m_sessionDbLocaleIndex;
        std::atomic<uint32> m_latency;
        std::atomic<uint32> m_clientTimeDelay;
        AccountData _accountData[NUM_ACCOUNT_DATA_TYPES];
        uint32 _tutorials[MAX_ACCOUNT_TUTORIAL_VALUES];
        bool   _tutorialsChanged;
        AddonsList m_addonsList;
        std::vector<std::string> _registeredAddonPrefixes;
        bool _filterAddonMessages;
        uint32 recruiterId;
        bool isRecruiter;
        LockedQueue<WorldPacket*> _recvQueue;
        rbac::RBACData* _RBACData;
        uint32 expireTime;
        bool forceExit;
        ObjectGuid m_currentBankerGUID;

        WorldSession(WorldSession const& right) = delete;
        WorldSession& operator=(WorldSession const& right) = delete;
};

#endif
/// @}
