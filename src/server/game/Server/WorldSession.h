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

/// \addtogroup u2w
/// @{
/// \file

#ifndef __WORLDSESSION_H
#define __WORLDSESSION_H

#include "Common.h"
#include "DatabaseEnvFwd.h"
#include "LockedQueue.h"
#include "ObjectGuid.h"
#include "Packet.h"
#include "QueryCallbackProcessor.h"
#include "SharedDefines.h"
#include <array>
#include <unordered_map>
#include <unordered_set>

class BattlePetMgr;
class BigNumber;
class BlackMarketEntry;
class CollectionMgr;
class Creature;
class InstanceSave;
class Item;
class LoginQueryHolder;
class Player;
class Unit;
class Warden;
class WorldSession;
class WorldSocket;
struct AuctionEntry;
struct BlackMarketTemplate;
struct DeclinedName;
struct ItemTemplate;
struct MovementInfo;
struct Position;

namespace lfg
{
struct LfgJoinResultData;
struct LfgPlayerBoot;
struct LfgProposal;
struct LfgQueueStatusData;
struct LfgPlayerRewardData;
struct LfgRoleCheck;
struct LfgUpdateData;
enum LfgTeleportResult : uint8;
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
        class GuildGetAchievementMembers;
    }

    namespace AreaTrigger
    {
        class AreaTrigger;
    }

    namespace Artifact
    {
        class ArtifactAddPower;
        class ArtifactSetAppearance;
        class ConfirmArtifactRespec;
    }

    namespace AuctionHouse
    {
        class AuctionHelloRequest;
        class AuctionListBidderItems;
        class AuctionListItems;
        class AuctionListOwnerItems;
        class AuctionListPendingSales;
        class AuctionPlaceBid;
        class AuctionRemoveItem;
        class AuctionReplicateItems;
        class AuctionSellItem;
    }

    namespace Auth
    {
        enum class ConnectToSerial : uint32;
    }

    namespace Bank
    {
        class AutoBankItem;
        class AutoStoreBankItem;
        class BuyBankSlot;
    }

    namespace Battlefield
    {
        class BFMgrEntryInviteResponse;
        class BFMgrQueueInviteResponse;
        class BFMgrQueueExitRequest;
    }

    namespace Battleground
    {
        class AreaSpiritHealerQuery;
        class AreaSpiritHealerQueue;
        class HearthAndResurrect;
        class PVPLogDataRequest;
        class BattlemasterJoin;
        class BattlemasterJoinArena;
        class BattlefieldLeave;
        class BattlefieldPort;
        class BattlefieldListRequest;
        class GetPVPOptionsEnabled;
        class RequestBattlefieldStatus;
        class ReportPvPPlayerAFK;
        class RequestPVPRewards;
        class RequestRatedBattlefieldInfo;
    }

    namespace Battlenet
    {
        class Request;
        class RequestRealmListTicket;
    }

    namespace BattlePet
    {
        class BattlePetRequestJournal;
        class BattlePetSetBattleSlot;
        class BattlePetModifyName;
        class BattlePetDeletePet;
        class BattlePetSetFlags;
        class BattlePetSummon;
        class CageBattlePet;
    }

    namespace BlackMarket
    {
        class BlackMarketOpen;
        class BlackMarketRequestItems;
        class BlackMarketBidOnItem;
        class BlackMarketOutbid;
    }

    namespace Calendar
    {
        class CalendarAddEvent;
        class CalendarCopyEvent;
        class CalendarEventInvite;
        class CalendarEventModeratorStatus;
        class CalendarEventRSVP;
        class CalendarEventSignUp;
        class CalendarEventStatus;
        class CalendarGetCalendar;
        class CalendarGetEvent;
        class CalendarGetNumPending;
        class CalendarGuildFilter;
        class CalendarRemoveEvent;
        class CalendarRemoveInvite;
        class CalendarUpdateEvent;
        class SetSavedInstanceExtend;
        class CalendarComplain;
    }

    namespace Character
    {
        struct CharacterCreateInfo;
        struct CharacterRenameInfo;
        struct CharCustomizeInfo;
        struct CharRaceOrFactionChangeInfo;
        struct CharacterUndeleteInfo;

        class AlterApperance;
        class EnumCharacters;
        class CreateCharacter;
        class CharDelete;
        class CharacterRenameRequest;
        class CharCustomize;
        class CharRaceOrFactionChange;
        class GenerateRandomCharacterName;
        class GetUndeleteCharacterCooldownStatus;
        class ReorderCharacters;
        class UndeleteCharacter;
        class PlayerLogin;
        class LogoutRequest;
        class LogoutCancel;
        class LoadingScreenNotify;
        class SetActionBarToggles;
        class RequestPlayedTime;
        class SetTitle;
        class SetFactionAtWar;
        class SetFactionNotAtWar;
        class SetFactionInactive;
        class SetWatchedFaction;
        class SetPlayerDeclinedNames;

        enum class LoginFailureReason : uint8;
    }

    namespace ClientConfig
    {
        class RequestAccountData;
        class UserClientUpdateAccountData;
        class SetAdvancedCombatLogging;
    }

    namespace Channel
    {
        class ChannelCommand;
        class ChannelPlayerCommand;
        class ChannelPassword;
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
        class ChatAddonMessageChannel;
        class ChatMessageAFK;
        class ChatMessageDND;
        class ChatMessageEmote;
        class CTextEmote;
        class EmoteClient;
        class ChatRegisterAddonPrefixes;
        class ChatUnregisterAllAddonPrefixes;
        class ChatReportIgnored;
    }

    namespace Collections
    {
        class CollectionItemSetFavorite;
    }

    namespace Combat
    {
        class AttackSwing;
        class AttackStop;
        class SetSheathed;
    }

    namespace Duel
    {
        class CanDuel;
        class DuelResponse;
    }

    namespace EquipmentSet
    {
        class SaveEquipmentSet;
        class DeleteEquipmentSet;
        class UseEquipmentSet;
    }

    namespace GameObject
    {
        class GameObjReportUse;
        class GameObjUse;
    }

    namespace Garrison
    {
        class GetGarrisonInfo;
        class GarrisonPurchaseBuilding;
        class GarrisonCancelConstruction;
        class GarrisonRequestBlueprintAndSpecializationData;
        class GarrisonGetBuildingLandmarks;
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
        class GuildReplaceGuildMaster;
        class GuildSetGuildMaster;
        class GuildChallengeUpdateRequest;
        class SaveGuildEmblem;
        class GuildSetAchievementTracking;
    }

    namespace GuildFinder
    {
        class LFGuildAddRecruit;
        class LFGuildBrowse;
        class LFGuildDeclineRecruit;
        class LFGuildGetApplications;
        class LFGuildGetGuildPost;
        class LFGuildGetRecruits;
        class LFGuildRemoveRecruit;
        class LFGuildSetGuildPost;
    }

    namespace Hotfix
    {
        class DBQueryBulk;
        class HotfixRequest;
    }

    namespace Inspect
    {
        class Inspect;
        class InspectPVPRequest;
        class QueryInspectAchievements;
        class RequestHonorStats;
    }

    namespace Instance
    {
        class InstanceInfo;
        class InstanceLockResponse;
        class ResetInstances;
    }

    namespace Item
    {
        class AutoEquipItem;
        class AutoEquipItemSlot;
        class AutoStoreBagItem;
        class BuyItem;
        class BuyBackItem;
        class DestroyItem;
        class GetItemPurchaseData;
        class ItemPurchaseRefund;
        class RepairItem;
        class ReadItem;
        class SellItem;
        class SplitItem;
        class SwapInvItem;
        class SwapItem;
        class WrapItem;
        class CancelTempEnchantment;
        class UseCritterItem;
        class UpgradeItem;
        class SocketGems;
        class SortBags;
        class SortBankBags;
        class SortReagentBankBags;
        struct ItemInstance;
        class RemoveNewItem;
    }

    namespace LFG
    {
        class DFJoin;
        class DFLeave;
        class DFProposalResponse;
        class DFSetRoles;
        class DFBootPlayerVote;
        class DFTeleport;
        class DFGetSystemInfo;
        class DFGetJoinStatus;
    }

    namespace Loot
    {
        class LootUnit;
        class LootItem;
        class LootRelease;
        class LootMoney;
        class LootRoll;
        class SetLootSpecialization;
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
        class RandomRollClient;
        class ObjectUpdateFailed;
        class ObjectUpdateRescued;
        class CompleteCinematic;
        class CompleteMovie;
        class NextCinematicCamera;
        class FarSight;
        class LoadCUFProfiles;
        class SaveCUFProfiles;
        class OpeningCinematic;
        class TogglePvP;
        class SetPvP;
        class MountSpecial;
        class SetTaxiBenchmarkMode;
        class MountSetFavorite;
        class PvpPrestigeRankUp;
        class CloseInteraction;
    }

    namespace Movement
    {
        class ClientPlayerMovement;
        class WorldPortResponse;
        class MoveTeleportAck;
        class MovementAckMessage;
        class MovementSpeedAck;
        class MoveKnockBackAck;
        class SetActiveMover;
        class MoveSetCollisionHeightAck;
        class MoveTimeSkipped;
        class SummonResponse;
        class MoveSplineDone;
        class SuspendTokenResponse;
    }

    namespace NPC
    {
        class Hello;
        class GossipSelectOption;
        class SpiritHealerActivate;
        class TrainerBuySpell;
        class RequestStabledPets;
    }

    namespace Party
    {
        class PartyCommandResult;
        class PartyInviteClient;
        class PartyInvite;
        class PartyInviteResponse;
        class PartyUninvite;
        class GroupDecline;
        class RequestPartyMemberStats;
        class PartyMemberState;
        class SetPartyLeader;
        class SetPartyAssignment;
        class SetRole;
        class RoleChangedInform;
        class SetLootMethod;
        class LeaveGroup;
        class MinimapPingClient;
        class MinimapPing;
        class UpdateRaidTarget;
        class SendRaidTargetUpdateSingle;
        class SendRaidTargetUpdateAll;
        class ConvertRaid;
        class RequestPartyJoinUpdates;
        class SetAssistantLeader;
        class DoReadyCheck;
        class ReadyCheckStarted;
        class ReadyCheckResponseClient;
        class ReadyCheckResponse;
        class ReadyCheckCompleted;
        class RequestRaidInfo;
        class OptOutOfLoot;
        class InitiateRolePoll;
        class RolePollInform;
        class GroupNewLeader;
        class PartyUpdate;
        class SetEveryoneIsAssistant;
        class ChangeSubGroup;
        class SwapSubGroups;
        class RaidMarkersChanged;
        class ClearRaidMarker;
    }

    namespace Pet
    {
        class DismissCritter;
        class RequestPetInfo;
        class PetAbandon;
        class PetStopAttack;
        class PetSpellAutocast;
        class PetRename;
        class PetAction;
        class PetCancelAura;
        class PetSetAction;
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
        class QueryGameObject;
        class QueryCorpseLocationFromClient;
        class QueryCorpseTransport;
        class QueryTime;
        class QueryPetName;
        class QuestPOIQuery;
        class QueryQuestCompletionNPCs;
        class QueryRealmName;
        class ItemTextQuery;
    }

    namespace Quest
    {
        class QuestConfirmAccept;
        class QuestGiverStatusQuery;
        class QuestGiverStatusMultipleQuery;
        class QuestGiverHello;
        class QueryQuestInfo;
        class QuestGiverChooseReward;
        class QuestGiverCompleteQuest;
        class QuestGiverRequestReward;
        class QuestGiverQueryQuest;
        class QuestGiverAcceptQuest;
        class QuestLogRemoveQuest;
        class QuestPushResult;
        class PushQuestToParty;
        class RequestWorldQuestUpdate;
        class ChoiceResponse;
    }

    namespace RaF
    {
        class AcceptLevelGrant;
        class GrantLevel;
    }

    namespace Reputation
    {
        class RequestForcedReactions;
    }

    namespace Toy
    {
        class AccountToysUpdate;
        class AddToy;
        class UseToy;
    }

    namespace Scenario
    {
        class QueryScenarioPOI;
    }

    namespace Scenes
    {
        class SceneTriggerEvent;
        class ScenePlaybackComplete;
        class ScenePlaybackCanceled;
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
        class CancelAutoRepeatSpell;
        class CancelChannelling;
        class CancelGrowthAura;
        class CancelMountAura;
        class PetCancelAura;
        class RequestCategoryCooldowns;
        class CancelCast;
        class CastSpell;
        class PetCastSpell;
        class UseItem;
        class OpenItem;
        class SetActionButton;
        class UnlearnSkill;
        class SelfRes;
        class GetMirrorImageData;
        class SpellClick;
        class MissileTrajectoryCollision;
        class UpdateMissileTrajectory;
    }

    namespace Talent
    {
        class LearnTalents;
        class LearnPvpTalents;
        class ConfirmRespecWipe;
    }

    namespace Taxi
    {
        class ShowTaxiNodes;
        class TaxiNodeStatusQuery;
        class EnableTaxiNode;
        class TaxiQueryAvailableNodes;
        class ActivateTaxi;
        class TaxiRequestEarlyLanding;
    }

    namespace Ticket
    {
        class GMTicketGetSystemStatus;
        class GMTicketGetCaseStatus;
        class SupportTicketSubmitBug;
        class SupportTicketSubmitSuggestion;
        class SupportTicketSubmitComplaint;
        class BugReport;
        class Complaint;
    }

    namespace Token
    {
        class UpdateListedAuctionableTokens;
        class RequestWowTokenMarketPrice;
    }

    namespace Totem
    {
        class TotemDestroyed;
    }

    namespace Trade
    {
        class AcceptTrade;
        class BeginTrade;
        class BusyTrade;
        class CancelTrade;
        class ClearTradeItem;
        class IgnoreTrade;
        class InitiateTrade;
        class SetTradeCurrency;
        class SetTradeGold;
        class SetTradeItem;
        class UnacceptTrade;
        class TradeStatus;
    }

    namespace Transmogrification
    {
        class TransmogrifyItems;
    }

    namespace Vehicle
    {
        class MoveDismissVehicle;
        class RequestVehiclePrevSeat;
        class RequestVehicleNextSeat;
        class MoveChangeVehicleSeats;
        class RequestVehicleSwitchSeat;
        class RideVehicleInteract;
        class EjectPassenger;
        class RequestVehicleExit;
        class MoveSetVehicleRecIdAck;
    }

    namespace VoidStorage
    {
        class UnlockVoidStorage;
        class QueryVoidStorage;
        class VoidStorageTransfer;
        class SwapVoidItem;
    }

    namespace Warden
    {
        class WardenData;
    }

    namespace Who
    {
        class WhoIsRequest;
        class WhoRequestPkt;
    }

    class Null final : public ClientPacket
    {
    public:
        Null(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

        void Read() override { _worldPacket.rfinish(); }
    };
}

namespace google
{
    namespace protobuf
    {
        class Message;
    }
}

namespace pb = google::protobuf;

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

enum BFLeaveReason
{
    BF_LEAVE_REASON_CLOSE     = 1,
    //BF_LEAVE_REASON_UNK1      = 2, (not used)
    //BF_LEAVE_REASON_UNK2      = 4, (not used)
    BF_LEAVE_REASON_EXITED = 8,
    BF_LEAVE_REASON_LOW_LEVEL = 10,
    BF_LEAVE_REASON_NOT_WHILE_IN_RAID = 15,
    BF_LEAVE_REASON_DESERTER = 16
};

enum ChatRestrictionType
{
    ERR_CHAT_RESTRICTED      = 0,
    ERR_CHAT_THROTTLED       = 1,
    ERR_USER_SQUELCHED       = 2,
    ERR_YELL_RESTRICTED      = 3,
    ERR_CHAT_RAID_RESTRICTED = 4
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

//class to deal with packet processing
//allows to determine if next packet is safe to be processed
class PacketFilter
{
public:
    explicit PacketFilter(WorldSession* pSession) : m_pSession(pSession) { }
    virtual ~PacketFilter() { }

    virtual bool Process(WorldPacket* /*packet*/) = 0;
    virtual bool ProcessUnsafe() const { return false; }

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

    bool Process(WorldPacket* packet) override;
};

//class used to filer only thread-unsafe packets from queue
//in order to update only be used in World::UpdateSessions()
class WorldSessionFilter : public PacketFilter
{
public:
    explicit WorldSessionFilter(WorldSession* pSession) : PacketFilter(pSession) { }
    ~WorldSessionFilter() { }

    bool Process(WorldPacket* packet) override;
    bool ProcessUnsafe() const override { return true; }
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
        WorldSession(uint32 id, std::string&& name, uint32 battlenetAccountId, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time,
            std::string os, LocaleConstant locale, uint32 recruiter, bool isARecruiter);
        ~WorldSession();

        bool PlayerLoading() const { return !m_playerLoading.IsEmpty(); }
        bool PlayerLogout() const { return m_playerLogout; }
        bool PlayerLogoutWithSave() const { return m_playerLogout && m_playerSave; }
        bool PlayerRecentlyLoggedOut() const { return m_playerRecentlyLogout; }
        bool PlayerDisconnected() const;

        bool IsAddonRegistered(const std::string& prefix) const;

        void SendPacket(WorldPacket const* packet, bool forced = false);
        void AddInstanceConnection(std::shared_ptr<WorldSocket> sock) { m_Socket[CONNECTION_TYPE_INSTANCE] = sock; }

        void SendNotification(char const* format, ...) ATTR_PRINTF(2, 3);
        void SendNotification(uint32 stringId, ...);
        void SendPetNameInvalid(uint32 error, std::string const& name, DeclinedName *declinedName);
        void SendPartyResult(PartyOperation operation, std::string const& member, PartyResult res, uint32 val = 0);
        void SendQueryTimeResponse();

        void SendAuthResponse(uint32 code, bool queued, uint32 queuePos = 0);
        void SendClientCacheVersion(uint32 version);
        void SendAvailableHotfixes(int32 version);

        void InitializeSession();
        void InitializeSessionCallback(SQLQueryHolder* realmHolder, SQLQueryHolder* holder);

        rbac::RBACData* GetRBACData();
        bool HasPermission(uint32 permissionId);
        void LoadPermissions();
        QueryCallback LoadPermissionsAsync();
        void InvalidateRBACData(); // Used to force LoadPermissions at next HasPermission check

        AccountTypes GetSecurity() const { return _security; }
        uint32 GetAccountId() const { return _accountId; }
        ObjectGuid GetAccountGUID() const { return ObjectGuid::Create<HighGuid::WowAccount>(GetAccountId()); }
        std::string const& GetAccountName() const { return _accountName; }
        uint32 GetBattlenetAccountId() const { return _battlenetAccountId; }
        ObjectGuid GetBattlenetAccountGUID() const { return ObjectGuid::Create<HighGuid::BNetAccount>(GetBattlenetAccountId()); }
        Player* GetPlayer() const { return _player; }
        std::string const& GetPlayerName() const;
        std::string GetPlayerInfo() const;

        void SetSecurity(AccountTypes security) { _security = security; }
        std::string const& GetRemoteAddress() const { return m_Address; }
        void SetPlayer(Player* player);
        uint8 GetAccountExpansion() const { return m_accountExpansion; }
        uint8 GetExpansion() const { return m_expansion; }
        std::string const& GetOS() const { return _os; }

        void InitWarden(BigNumber* k);

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

        void SendTrainerList(Creature* npc, uint32 trainerId);
        void SendListInventory(ObjectGuid guid);
        void SendShowBank(ObjectGuid guid);
        bool CanOpenMailBox(ObjectGuid guid);
        void SendShowMailBox(ObjectGuid guid);
        void SendTabardVendorActivate(ObjectGuid guid);
        void SendSpiritResurrect();
        void SendBindPoint(Creature* npc);
        void SendOpenTransmogrifier(ObjectGuid const& guid);

        void SendAttackStop(Unit const* enemy);

        void SendTradeStatus(WorldPackets::Trade::TradeStatus& status);
        void SendUpdateTrade(bool trader_data = true);
        void SendCancelTrade();

        void SendPetitionQueryOpcode(ObjectGuid petitionguid);

        // Pet
        void SendQueryPetNameResponse(ObjectGuid guid);
        void SendStablePet(ObjectGuid guid);
        void SendStablePetCallback(ObjectGuid guid, PreparedQueryResult result);
        void SendPetStableResult(uint8 guid);
        bool CheckStableMaster(ObjectGuid guid);

        // Account Data
        AccountData const* GetAccountData(AccountDataType type) const { return &_accountData[type]; }
        void SetAccountData(AccountDataType type, uint32 time, std::string const& data);
        void LoadAccountData(PreparedQueryResult result, uint32 mask);

        void LoadTutorialsData(PreparedQueryResult result);
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
        // Auction
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
        void SendAuctionOutBidNotification(AuctionEntry const* auction, Item const* item);
        void SendAuctionClosedNotification(AuctionEntry const* auction, float mailDelay, bool sold, Item const* item);
        void SendAuctionWonNotification(AuctionEntry const* auction, Item const* item);
        void SendAuctionOwnerBidNotification(AuctionEntry const* auction, Item const* item);

        // Black Market
        void SendBlackMarketOpenResult(ObjectGuid guid, Creature* auctioneer);
        void SendBlackMarketBidOnItemResult(int32 result, int32 marketId, WorldPackets::Item::ItemInstance& item);
        void SendBlackMarketWonNotification(BlackMarketEntry const* entry, Item const* item);
        void SendBlackMarketOutbidNotification(BlackMarketTemplate const* templ);

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
        void SendNotInArenaTeamPacket(uint8 type);
        void SendPetitionShowList(ObjectGuid guid);

        void DoLootRelease(ObjectGuid lguid);
        void DoLootReleaseAll();

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

        void ResetTimeOutTime();

        bool IsConnectionIdle() const
        {
            return m_timeOutTime <= 0 && !m_inQueue;
        }

        // Recruit-A-Friend Handling
        uint32 GetRecruiterId() const { return recruiterId; }
        bool IsARecruiter() const { return isRecruiter; }

        // Battle Pets
        BattlePetMgr* GetBattlePetMgr() const { return _battlePetMgr.get(); }

        CollectionMgr* GetCollectionMgr() const { return _collectionMgr.get(); }

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPackets::Null& null);          // not used
        void Handle_EarlyProccess(WorldPacket& recvPacket); // just mark packets processed in WorldSocket::OnRead
        void LogUnprocessedTail(WorldPacket const* packet);

        void HandleCharEnum(PreparedQueryResult result);
        void HandleCharEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/);
        void HandleCharUndeleteEnum(PreparedQueryResult result);
        void HandleCharUndeleteEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/);
        void HandleCharDeleteOpcode(WorldPackets::Character::CharDelete& charDelete);
        void HandleCharCreateOpcode(WorldPackets::Character::CreateCharacter& charCreate);
        void HandlePlayerLoginOpcode(WorldPackets::Character::PlayerLogin& playerLogin);

        void SendConnectToInstance(WorldPackets::Auth::ConnectToSerial serial);
        void HandleContinuePlayerLogin();
        void AbortLogin(WorldPackets::Character::LoginFailureReason reason);
        void HandleLoadScreenOpcode(WorldPackets::Character::LoadingScreenNotify& loadingScreenNotify);
        void HandlePlayerLogin(LoginQueryHolder* holder);
        void HandleCharRenameOpcode(WorldPackets::Character::CharacterRenameRequest& request);
        void HandleCharRenameCallBack(std::shared_ptr<WorldPackets::Character::CharacterRenameInfo> renameInfo, PreparedQueryResult result);
        void HandleSetPlayerDeclinedNames(WorldPackets::Character::SetPlayerDeclinedNames& packet);
        void HandleAlterAppearance(WorldPackets::Character::AlterApperance& packet);
        void HandleCharCustomizeOpcode(WorldPackets::Character::CharCustomize& packet);
        void HandleCharCustomizeCallback(std::shared_ptr<WorldPackets::Character::CharCustomizeInfo> customizeInfo, PreparedQueryResult result);
        void HandleCharRaceOrFactionChangeOpcode(WorldPackets::Character::CharRaceOrFactionChange& packet);
        void HandleCharRaceOrFactionChangeCallback(std::shared_ptr<WorldPackets::Character::CharRaceOrFactionChangeInfo> factionChangeInfo, PreparedQueryResult result);
        void HandleRandomizeCharNameOpcode(WorldPackets::Character::GenerateRandomCharacterName& packet);
        void HandleReorderCharacters(WorldPackets::Character::ReorderCharacters& reorderChars);
        void HandleOpeningCinematic(WorldPackets::Misc::OpeningCinematic& packet);
        void HandleGetUndeleteCooldownStatus(WorldPackets::Character::GetUndeleteCharacterCooldownStatus& /*getCooldown*/);
        void HandleUndeleteCooldownStatusCallback(PreparedQueryResult result);
        void HandleCharUndeleteOpcode(WorldPackets::Character::UndeleteCharacter& undeleteInfo);

        void SendCharCreate(ResponseCodes result);
        void SendCharDelete(ResponseCodes result);
        void SendCharRename(ResponseCodes result, WorldPackets::Character::CharacterRenameInfo const* renameInfo);
        void SendCharCustomize(ResponseCodes result, WorldPackets::Character::CharCustomizeInfo const* customizeInfo);
        void SendCharFactionChange(ResponseCodes result, WorldPackets::Character::CharRaceOrFactionChangeInfo const* factionChangeInfo);
        void SendSetPlayerDeclinedNamesResult(DeclinedNameResult result, ObjectGuid guid);
        void SendUndeleteCooldownStatusResponse(uint32 currentCooldown, uint32 maxCooldown);
        void SendUndeleteCharacterResponse(CharacterUndeleteResult result, WorldPackets::Character::CharacterUndeleteInfo const* undeleteInfo);

        // played time
        void HandlePlayedTime(WorldPackets::Character::RequestPlayedTime& packet);

        // cemetery/graveyard related
        void HandlePortGraveyard(WorldPackets::Misc::PortGraveyard& packet);
        void HandleRequestCemeteryList(WorldPackets::Misc::RequestCemeteryList& packet);

        // Inspect
        void HandleInspectOpcode(WorldPackets::Inspect::Inspect& inspect);
        void HandleRequestHonorStatsOpcode(WorldPackets::Inspect::RequestHonorStats& request);
        void HandleInspectPVP(WorldPackets::Inspect::InspectPVPRequest& request);
        void HandleQueryInspectAchievements(WorldPackets::Inspect::QueryInspectAchievements& inspect);

        void HandleMountSpecialAnimOpcode(WorldPackets::Misc::MountSpecial& mountSpecial);

        // repair
        void HandleRepairItemOpcode(WorldPackets::Item::RepairItem& packet);

        // Knockback
        void HandleMoveKnockBackAck(WorldPackets::Movement::MoveKnockBackAck& movementAck);

        void HandleMoveTeleportAck(WorldPackets::Movement::MoveTeleportAck& packet);
        void HandleForceSpeedChangeAck(WorldPackets::Movement::MovementSpeedAck& packet);
        void HandleSetCollisionHeightAck(WorldPackets::Movement::MoveSetCollisionHeightAck& setCollisionHeightAck);

        void HandleRepopRequest(WorldPackets::Misc::RepopRequest& packet);
        void HandleAutostoreLootItemOpcode(WorldPackets::Loot::LootItem& packet);
        void HandleLootMoneyOpcode(WorldPackets::Loot::LootMoney& packet);
        void HandleLootOpcode(WorldPackets::Loot::LootUnit& packet);
        void HandleLootReleaseOpcode(WorldPackets::Loot::LootRelease& packet);
        void HandleLootMasterGiveOpcode(WorldPacket& recvPacket);
        void HandleSetLootSpecialization(WorldPackets::Loot::SetLootSpecialization& packet);

        void HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest);
        void HandleLogoutRequestOpcode(WorldPackets::Character::LogoutRequest& logoutRequest);
        void HandleLogoutCancelOpcode(WorldPackets::Character::LogoutCancel& logoutCancel);

        // GM Ticket opcodes
        void HandleGMTicketGetCaseStatusOpcode(WorldPackets::Ticket::GMTicketGetCaseStatus& packet);
        void HandleGMTicketSystemStatusOpcode(WorldPackets::Ticket::GMTicketGetSystemStatus& packet);
        void HandleSupportTicketSubmitBug(WorldPackets::Ticket::SupportTicketSubmitBug& packet);
        void HandleSupportTicketSubmitSuggestion(WorldPackets::Ticket::SupportTicketSubmitSuggestion& packet);
        void HandleSupportTicketSubmitComplaint(WorldPackets::Ticket::SupportTicketSubmitComplaint& packet);
        void HandleBugReportOpcode(WorldPackets::Ticket::BugReport& bugReport);
        void HandleComplaint(WorldPackets::Ticket::Complaint& packet);

        void HandleTogglePvP(WorldPackets::Misc::TogglePvP& packet);
        void HandleSetPvP(WorldPackets::Misc::SetPvP& packet);

        void HandleSetSelectionOpcode(WorldPackets::Misc::SetSelection& packet);
        void HandleStandStateChangeOpcode(WorldPackets::Misc::StandStateChange& packet);
        void HandleEmoteOpcode(WorldPackets::Chat::EmoteClient& packet);

        // Social
        void HandleContactListOpcode(WorldPackets::Social::SendContactList& packet);
        void HandleAddFriendOpcode(WorldPackets::Social::AddFriend& packet);
        void HandleAddFriendOpcodeCallBack(std::string const& friendNote, PreparedQueryResult result);
        void HandleDelFriendOpcode(WorldPackets::Social::DelFriend& packet);
        void HandleAddIgnoreOpcode(WorldPackets::Social::AddIgnore& packet);
        void HandleAddIgnoreOpcodeCallBack(PreparedQueryResult result);
        void HandleDelIgnoreOpcode(WorldPackets::Social::DelIgnore& packet);
        void HandleSetContactNotesOpcode(WorldPackets::Social::SetContactNotes& packet);

        void HandleAreaTriggerOpcode(WorldPackets::AreaTrigger::AreaTrigger& packet);

        void HandleSetFactionAtWar(WorldPackets::Character::SetFactionAtWar& packet);
        void HandleSetFactionNotAtWar(WorldPackets::Character::SetFactionNotAtWar& packet);
        void HandleSetFactionCheat(WorldPacket& recvData);
        void HandleSetWatchedFactionOpcode(WorldPackets::Character::SetWatchedFaction& packet);
        void HandleSetFactionInactiveOpcode(WorldPackets::Character::SetFactionInactive& packet);
        void HandleRequestForcedReactionsOpcode(WorldPackets::Reputation::RequestForcedReactions& requestForcedReactions);

        void HandleUpdateAccountData(WorldPackets::ClientConfig::UserClientUpdateAccountData& packet);
        void HandleRequestAccountData(WorldPackets::ClientConfig::RequestAccountData& request);
        void HandleSetAdvancedCombatLogging(WorldPackets::ClientConfig::SetAdvancedCombatLogging& setAdvancedCombatLogging);
        void HandleSetActionButtonOpcode(WorldPackets::Spells::SetActionButton& packet);

        void HandleGameObjectUseOpcode(WorldPackets::GameObject::GameObjUse& packet);
        void HandleGameobjectReportUse(WorldPackets::GameObject::GameObjReportUse& packet);

        void HandleNameQueryOpcode(WorldPackets::Query::QueryPlayerName& packet);
        void HandleQueryTimeOpcode(WorldPackets::Query::QueryTime& queryTime);
        void HandleCreatureQuery(WorldPackets::Query::QueryCreature& packet);
        void HandleGameObjectQueryOpcode(WorldPackets::Query::QueryGameObject& packet);

        void HandleDBQueryBulk(WorldPackets::Hotfix::DBQueryBulk& dbQuery);
        void HandleHotfixRequest(WorldPackets::Hotfix::HotfixRequest& hotfixQuery);

        void HandleMoveWorldportAckOpcode(WorldPackets::Movement::WorldPortResponse& packet);
        void HandleMoveWorldportAck();                // for server-side calls
        void HandleSuspendTokenResponse(WorldPackets::Movement::SuspendTokenResponse& suspendTokenResponse);

        void HandleMovementOpcodes(WorldPackets::Movement::ClientPlayerMovement& packet);
        void HandleMovementOpcode(OpcodeClient opcode, MovementInfo& movementInfo);
        void HandleSetActiveMoverOpcode(WorldPackets::Movement::SetActiveMover& packet);
        void HandleMoveDismissVehicle(WorldPackets::Vehicle::MoveDismissVehicle& moveDismissVehicle);
        void HandleRequestVehiclePrevSeat(WorldPackets::Vehicle::RequestVehiclePrevSeat& requestVehiclePrevSeat);
        void HandleRequestVehicleNextSeat(WorldPackets::Vehicle::RequestVehicleNextSeat& requestVehicleNextSeat);
        void HandleMoveChangeVehicleSeats(WorldPackets::Vehicle::MoveChangeVehicleSeats& moveChangeVehicleSeats);
        void HandleRequestVehicleSwitchSeat(WorldPackets::Vehicle::RequestVehicleSwitchSeat& requestVehicleSwitchSeat);
        void HandleRideVehicleInteract(WorldPackets::Vehicle::RideVehicleInteract& rideVehicleInteract);
        void HandleEjectPassenger(WorldPackets::Vehicle::EjectPassenger& ejectPassenger);
        void HandleRequestVehicleExit(WorldPackets::Vehicle::RequestVehicleExit& requestVehicleExit);
        void HandleMoveSetVehicleRecAck(WorldPackets::Vehicle::MoveSetVehicleRecIdAck& setVehicleRecIdAck);
        void HandleMoveTimeSkippedOpcode(WorldPackets::Movement::MoveTimeSkipped& moveTimeSkipped);
        void HandleMovementAckMessage(WorldPackets::Movement::MovementAckMessage& movementAck);

        void HandleRequestRaidInfoOpcode(WorldPackets::Party::RequestRaidInfo& packet);

        void HandlePartyInviteOpcode(WorldPackets::Party::PartyInviteClient& packet);
        //void HandleGroupCancelOpcode(WorldPacket& recvPacket);
        void HandlePartyInviteResponseOpcode(WorldPackets::Party::PartyInviteResponse& packet);
        void HandlePartyUninviteOpcode(WorldPackets::Party::PartyUninvite& packet);
        void HandleSetPartyLeaderOpcode(WorldPackets::Party::SetPartyLeader& packet);
        void HandleSetRoleOpcode(WorldPackets::Party::SetRole& packet);
        void HandleLeaveGroupOpcode(WorldPackets::Party::LeaveGroup& packet);
        void HandleOptOutOfLootOpcode(WorldPackets::Party::OptOutOfLoot& packet);
        void HandleSetLootMethodOpcode(WorldPackets::Party::SetLootMethod& packet);
        void HandleLootRoll(WorldPackets::Loot::LootRoll& packet);
        void HandleRequestPartyMemberStatsOpcode(WorldPackets::Party::RequestPartyMemberStats& packet);
        void HandleUpdateRaidTargetOpcode(WorldPackets::Party::UpdateRaidTarget& packet);
        void HandleDoReadyCheckOpcode(WorldPackets::Party::DoReadyCheck& packet);
        void HandleReadyCheckResponseOpcode(WorldPackets::Party::ReadyCheckResponseClient& packet);
        void HandleConvertRaidOpcode(WorldPackets::Party::ConvertRaid& packet);
        void HandleRequestPartyJoinUpdates(WorldPackets::Party::RequestPartyJoinUpdates& packet);
        void HandleChangeSubGroupOpcode(WorldPackets::Party::ChangeSubGroup& packet);
        void HandleSwapSubGroupsOpcode(WorldPackets::Party::SwapSubGroups& packet);
        void HandleSetAssistantLeaderOpcode(WorldPackets::Party::SetAssistantLeader& packet);
        void HandleSetPartyAssignment(WorldPackets::Party::SetPartyAssignment& packet);
        void HandleInitiateRolePoll(WorldPackets::Party::InitiateRolePoll& packet);
        void HandleSetEveryoneIsAssistant(WorldPackets::Party::SetEveryoneIsAssistant& packet);
        void HandleClearRaidMarker(WorldPackets::Party::ClearRaidMarker& packet);

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
        void HandleGuildReplaceGuildMaster(WorldPackets::Guild::GuildReplaceGuildMaster& replaceGuildMaster);
        void HandleGuildSetAchievementTracking(WorldPackets::Guild::GuildSetAchievementTracking& packet);
        void HandleGuildGetAchievementMembers(WorldPackets::Achievement::GuildGetAchievementMembers& getAchievementMembers);
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

        void HandleGuildFinderAddRecruit(WorldPackets::GuildFinder::LFGuildAddRecruit& lfGuildAddRecruit);
        void HandleGuildFinderBrowse(WorldPackets::GuildFinder::LFGuildBrowse& lfGuildBrowse);
        void HandleGuildFinderDeclineRecruit(WorldPackets::GuildFinder::LFGuildDeclineRecruit& lfGuildDeclineRecruit);
        void HandleGuildFinderGetApplications(WorldPackets::GuildFinder::LFGuildGetApplications& lfGuildGetApplications);
        void HandleGuildFinderGetGuildPost(WorldPackets::GuildFinder::LFGuildGetGuildPost& lfGuildGetGuildPost);
        void HandleGuildFinderGetRecruits(WorldPackets::GuildFinder::LFGuildGetRecruits& lfGuildGetRecruits);
        void HandleGuildFinderRemoveRecruit(WorldPackets::GuildFinder::LFGuildRemoveRecruit& lfGuildRemoveRecruit);
        void HandleGuildFinderSetGuildPost(WorldPackets::GuildFinder::LFGuildSetGuildPost& lfGuildSetGuildPost);

        void HandleEnableTaxiNodeOpcode(WorldPackets::Taxi::EnableTaxiNode& enableTaxiNode);
        void HandleTaxiNodeStatusQueryOpcode(WorldPackets::Taxi::TaxiNodeStatusQuery& taxiNodeStatusQuery);
        void HandleTaxiQueryAvailableNodesOpcode(WorldPackets::Taxi::TaxiQueryAvailableNodes& taxiQueryAvailableNodes);
        void HandleActivateTaxiOpcode(WorldPackets::Taxi::ActivateTaxi& activateTaxi);
        void HandleMoveSplineDoneOpcode(WorldPackets::Movement::MoveSplineDone& moveSplineDone);
        void SendActivateTaxiReply(ActivateTaxiReply reply);
        void HandleTaxiRequestEarlyLanding(WorldPackets::Taxi::TaxiRequestEarlyLanding& taxiRequestEarlyLanding);

        void HandleTabardVendorActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleBankerActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet);
        void HandleTrainerBuySpellOpcode(WorldPackets::NPC::TrainerBuySpell& packet);
        void HandlePetitionShowList(WorldPackets::Petition::PetitionShowList& packet);
        void HandleGossipHelloOpcode(WorldPackets::NPC::Hello& packet);
        void HandleGossipSelectOptionOpcode(WorldPackets::NPC::GossipSelectOption& packet);
        void HandleSpiritHealerActivate(WorldPackets::NPC::SpiritHealerActivate& packet);
        void HandleNpcTextQueryOpcode(WorldPackets::Query::QueryNPCText& packet);
        void HandleBinderActivateOpcode(WorldPackets::NPC::Hello& packet);
        void HandleRequestStabledPets(WorldPackets::NPC::RequestStabledPets& packet);
        void HandleStablePet(WorldPacket& recvPacket);
        void HandleStablePetCallback(PreparedQueryResult result);
        void HandleUnstablePet(WorldPacket& recvPacket);
        void HandleUnstablePetCallback(uint32 petId, PreparedQueryResult result);
        void HandleBuyStableSlot(WorldPacket& recvPacket);
        void HandleStableRevivePet(WorldPacket& recvPacket);
        void HandleStableSwapPet(WorldPacket& recvPacket);
        void HandleStableSwapPetCallback(uint32 petId, PreparedQueryResult result);

        void HandleCanDuel(WorldPackets::Duel::CanDuel& packet);
        void HandleDuelResponseOpcode(WorldPackets::Duel::DuelResponse& duelResponse);
        void HandleDuelAccepted();
        void HandleDuelCancelled();

        void HandleAcceptTradeOpcode(WorldPackets::Trade::AcceptTrade& acceptTrade);
        void HandleBeginTradeOpcode(WorldPackets::Trade::BeginTrade& beginTrade);
        void HandleBusyTradeOpcode(WorldPackets::Trade::BusyTrade& busyTrade);
        void HandleCancelTradeOpcode(WorldPackets::Trade::CancelTrade& cancelTrade);
        void HandleClearTradeItemOpcode(WorldPackets::Trade::ClearTradeItem& clearTradeItem);
        void HandleIgnoreTradeOpcode(WorldPackets::Trade::IgnoreTrade& ignoreTrade);
        void HandleInitiateTradeOpcode(WorldPackets::Trade::InitiateTrade& initiateTrade);
        void HandleSetTradeCurrencyOpcode(WorldPackets::Trade::SetTradeCurrency& setTradeCurrency);
        void HandleSetTradeGoldOpcode(WorldPackets::Trade::SetTradeGold& setTradeGold);
        void HandleSetTradeItemOpcode(WorldPackets::Trade::SetTradeItem& setTradeItem);
        void HandleUnacceptTradeOpcode(WorldPackets::Trade::UnacceptTrade& unacceptTrade);

        void HandleAuctionHelloOpcode(WorldPackets::AuctionHouse::AuctionHelloRequest& packet);
        void HandleAuctionListItems(WorldPackets::AuctionHouse::AuctionListItems& packet);
        void HandleAuctionListBidderItems(WorldPackets::AuctionHouse::AuctionListBidderItems& packet);
        void HandleAuctionSellItem(WorldPackets::AuctionHouse::AuctionSellItem& packet);
        void HandleAuctionRemoveItem(WorldPackets::AuctionHouse::AuctionRemoveItem& packet);
        void HandleAuctionListOwnerItems(WorldPackets::AuctionHouse::AuctionListOwnerItems& packet);
        void HandleAuctionPlaceBid(WorldPackets::AuctionHouse::AuctionPlaceBid& packet);
        void HandleAuctionListPendingSales(WorldPackets::AuctionHouse::AuctionListPendingSales& packet);
        void HandleReplicateItems(WorldPackets::AuctionHouse::AuctionReplicateItems& packet);

        // Bank
        void HandleAutoBankItemOpcode(WorldPackets::Bank::AutoBankItem& packet);
        void HandleAutoStoreBankItemOpcode(WorldPackets::Bank::AutoStoreBankItem& packet);
        void HandleBuyBankSlotOpcode(WorldPackets::Bank::BuyBankSlot& packet);

        // Black Market
        void HandleBlackMarketOpen(WorldPackets::BlackMarket::BlackMarketOpen& blackMarketOpen);
        void HandleBlackMarketRequestItems(WorldPackets::BlackMarket::BlackMarketRequestItems& blackMarketRequestItems);
        void HandleBlackMarketBidOnItem(WorldPackets::BlackMarket::BlackMarketBidOnItem& blackMarketBidOnItem);

        void HandleGetMailList(WorldPackets::Mail::MailGetList& packet);
        void HandleSendMail(WorldPackets::Mail::SendMail& packet);
        void HandleMailTakeMoney(WorldPackets::Mail::MailTakeMoney& packet);
        void HandleMailTakeItem(WorldPackets::Mail::MailTakeItem& packet);
        void HandleMailMarkAsRead(WorldPackets::Mail::MailMarkAsRead& packet);
        void HandleMailReturnToSender(WorldPackets::Mail::MailReturnToSender& packet);
        void HandleMailDelete(WorldPackets::Mail::MailDelete& packet);
        void HandleItemTextQuery(WorldPackets::Query::ItemTextQuery& itemTextQuery);
        void HandleMailCreateTextItem(WorldPackets::Mail::MailCreateTextItem& packet);
        void HandleQueryNextMailTime(WorldPackets::Mail::MailQueryNextMailTime& packet);
        void HandleCancelChanneling(WorldPackets::Spells::CancelChannelling& cancelChanneling);

        void HandleSplitItemOpcode(WorldPackets::Item::SplitItem& splitItem);
        void HandleSwapInvItemOpcode(WorldPackets::Item::SwapInvItem& swapInvItem);
        void HandleDestroyItemOpcode(WorldPackets::Item::DestroyItem& destroyItem);
        void HandleAutoEquipItemOpcode(WorldPackets::Item::AutoEquipItem& autoEquipItem);
        void HandleSellItemOpcode(WorldPackets::Item::SellItem& packet);
        void HandleBuyItemOpcode(WorldPackets::Item::BuyItem& packet);
        void HandleListInventoryOpcode(WorldPackets::NPC::Hello& packet);
        void HandleAutoStoreBagItemOpcode(WorldPackets::Item::AutoStoreBagItem& packet);
        void HandleReadItem(WorldPackets::Item::ReadItem& readItem);
        void HandleAutoEquipItemSlotOpcode(WorldPackets::Item::AutoEquipItemSlot& autoEquipItemSlot);
        void HandleSwapItem(WorldPackets::Item::SwapItem& swapItem);
        void HandleBuybackItem(WorldPackets::Item::BuyBackItem& packet);
        void HandleWrapItem(WorldPackets::Item::WrapItem& packet);
        void HandleUseCritterItem(WorldPackets::Item::UseCritterItem& packet);
        void HandleUpgradeItem(WorldPackets::Item::UpgradeItem& packet);

        void HandleAttackSwingOpcode(WorldPackets::Combat::AttackSwing& packet);
        void HandleAttackStopOpcode(WorldPackets::Combat::AttackStop& packet);
        void HandleSetSheathedOpcode(WorldPackets::Combat::SetSheathed& packet);

        void HandleUseItemOpcode(WorldPackets::Spells::UseItem& packet);
        void HandleOpenItemOpcode(WorldPackets::Spells::OpenItem& packet);
        void HandleCastSpellOpcode(WorldPackets::Spells::CastSpell& castRequest);
        void HandleCancelCastOpcode(WorldPackets::Spells::CancelCast& packet);
        void HandleCancelAuraOpcode(WorldPackets::Spells::CancelAura& cancelAura);
        void HandleCancelGrowthAuraOpcode(WorldPackets::Spells::CancelGrowthAura& cancelGrowthAura);
        void HandleCancelMountAuraOpcode(WorldPackets::Spells::CancelMountAura& cancelMountAura);
        void HandleCancelAutoRepeatSpellOpcode(WorldPackets::Spells::CancelAutoRepeatSpell& cancelAutoRepeatSpell);
        void HandleMissileTrajectoryCollision(WorldPackets::Spells::MissileTrajectoryCollision& packet);
        void HandleUpdateMissileTrajectory(WorldPackets::Spells::UpdateMissileTrajectory& packet);

        void HandleLearnPvpTalentsOpcode(WorldPackets::Talent::LearnPvpTalents& packet);
        void HandleLearnTalentsOpcode(WorldPackets::Talent::LearnTalents& packet);
        void HandleConfirmRespecWipeOpcode(WorldPackets::Talent::ConfirmRespecWipe& confirmRespecWipe);
        void HandleUnlearnSkillOpcode(WorldPackets::Spells::UnlearnSkill& packet);

        void HandleQuestgiverStatusQueryOpcode(WorldPackets::Quest::QuestGiverStatusQuery& packet);
        void HandleQuestgiverStatusMultipleQuery(WorldPackets::Quest::QuestGiverStatusMultipleQuery& packet);
        void HandleQuestgiverHelloOpcode(WorldPackets::Quest::QuestGiverHello& packet);
        void HandleQuestgiverAcceptQuestOpcode(WorldPackets::Quest::QuestGiverAcceptQuest& packet);
        void HandleQuestgiverQueryQuestOpcode(WorldPackets::Quest::QuestGiverQueryQuest& packet);
        void HandleQuestgiverChooseRewardOpcode(WorldPackets::Quest::QuestGiverChooseReward& packet);
        void HandleQuestgiverRequestRewardOpcode(WorldPackets::Quest::QuestGiverRequestReward& packet);
        void HandleQuestQueryOpcode(WorldPackets::Quest::QueryQuestInfo& packet);
        void HandleQuestLogRemoveQuest(WorldPackets::Quest::QuestLogRemoveQuest& packet);
        void HandleQuestConfirmAccept(WorldPackets::Quest::QuestConfirmAccept& packet);
        void HandleQuestgiverCompleteQuest(WorldPackets::Quest::QuestGiverCompleteQuest& packet);
        void HandlePushQuestToParty(WorldPackets::Quest::PushQuestToParty& packet);
        void HandleQuestPushResult(WorldPackets::Quest::QuestPushResult& packet);
        void HandleRequestWorldQuestUpdate(WorldPackets::Quest::RequestWorldQuestUpdate& packet);
        void HandlePlayerChoiceResponse(WorldPackets::Quest::ChoiceResponse& choiceResponse);

        void HandleChatMessageOpcode(WorldPackets::Chat::ChatMessage& chatMessage);
        void HandleChatMessageWhisperOpcode(WorldPackets::Chat::ChatMessageWhisper& chatMessageWhisper);
        void HandleChatMessageChannelOpcode(WorldPackets::Chat::ChatMessageChannel& chatMessageChannel);
        void HandleChatMessage(ChatMsg type, uint32 lang, std::string msg, std::string target = "");
        void HandleChatAddonMessageOpcode(WorldPackets::Chat::ChatAddonMessage& chatAddonMessage);
        void HandleChatAddonMessageWhisperOpcode(WorldPackets::Chat::ChatAddonMessageWhisper& chatAddonMessageWhisper);
        void HandleChatAddonMessageChannelOpcode(WorldPackets::Chat::ChatAddonMessageChannel& chatAddonMessageChannel);
        void HandleChatAddonMessage(ChatMsg type, std::string prefix, std::string text, std::string target = "");
        void HandleChatMessageAFKOpcode(WorldPackets::Chat::ChatMessageAFK& chatMessageAFK);
        void HandleChatMessageDNDOpcode(WorldPackets::Chat::ChatMessageDND& chatMessageDND);
        void HandleChatMessageEmoteOpcode(WorldPackets::Chat::ChatMessageEmote& chatMessageEmote);
        void SendChatPlayerNotfoundNotice(std::string const& name);
        void SendPlayerAmbiguousNotice(std::string const& name);
        void SendChatRestricted(ChatRestrictionType restriction);
        void HandleTextEmoteOpcode(WorldPackets::Chat::CTextEmote& packet);
        void HandleChatIgnoredOpcode(WorldPackets::Chat::ChatReportIgnored& chatReportIgnored);

        void HandleUnregisterAllAddonPrefixesOpcode(WorldPackets::Chat::ChatUnregisterAllAddonPrefixes& packet);
        void HandleAddonRegisteredPrefixesOpcode(WorldPackets::Chat::ChatRegisterAddonPrefixes& packet);

        void HandleReclaimCorpse(WorldPackets::Misc::ReclaimCorpse& packet);
        void HandleQueryCorpseLocation(WorldPackets::Query::QueryCorpseLocationFromClient& packet);
        void HandleQueryCorpseTransport(WorldPackets::Query::QueryCorpseTransport& packet);
        void HandleResurrectResponse(WorldPackets::Misc::ResurrectResponse& packet);
        void HandleSummonResponseOpcode(WorldPackets::Movement::SummonResponse& packet);

        void HandleJoinChannel(WorldPackets::Channel::JoinChannel& packet);
        void HandleLeaveChannel(WorldPackets::Channel::LeaveChannel& packet);
        void HandleChannelCommand(WorldPackets::Channel::ChannelCommand& packet);
        void HandleChannelPlayerCommand(WorldPackets::Channel::ChannelPlayerCommand& packet);
        void HandleChannelPassword(WorldPackets::Channel::ChannelPassword& channelPassword);

        void HandleCompleteCinematic(WorldPackets::Misc::CompleteCinematic& packet);
        void HandleNextCinematicCamera(WorldPackets::Misc::NextCinematicCamera& packet);
        void HandleCompleteMovie(WorldPackets::Misc::CompleteMovie& packet);

        void HandleQueryPageText(WorldPackets::Query::QueryPageText& packet);

        void HandleTutorialFlag(WorldPackets::Misc::TutorialSetFlag& packet);

        //Pet
        void HandlePetAction(WorldPackets::Pet::PetAction& packet);
        void HandlePetStopAttack(WorldPackets::Pet::PetStopAttack& packet);
        void HandlePetActionHelper(Unit* pet, ObjectGuid guid1, uint32 spellid, uint16 flag, ObjectGuid guid2, Position const& pos);
        void HandleQueryPetName(WorldPackets::Query::QueryPetName& packet);
        void HandlePetSetAction(WorldPackets::Pet::PetSetAction& packet);
        void HandlePetAbandon(WorldPackets::Pet::PetAbandon& packet);
        void HandlePetRename(WorldPackets::Pet::PetRename& packet);
        void HandlePetCancelAuraOpcode(WorldPackets::Spells::PetCancelAura& packet);
        void HandlePetSpellAutocastOpcode(WorldPackets::Pet::PetSpellAutocast& packet);
        void HandlePetCastSpellOpcode(WorldPackets::Spells::PetCastSpell& petCastSpell);

        void HandleSetActionBarToggles(WorldPackets::Character::SetActionBarToggles& packet);

        void HandleTotemDestroyed(WorldPackets::Totem::TotemDestroyed& totemDestroyed);
        void HandleDismissCritter(WorldPackets::Pet::DismissCritter& dismissCritter);

        //Battleground
        void HandleBattlemasterHelloOpcode(WorldPackets::NPC::Hello& hello);
        void HandleBattlemasterJoinOpcode(WorldPackets::Battleground::BattlemasterJoin& battlemasterJoin);
        void HandlePVPLogDataOpcode(WorldPackets::Battleground::PVPLogDataRequest& pvpLogDataRequest);
        void HandleBattleFieldPortOpcode(WorldPackets::Battleground::BattlefieldPort& battlefieldPort);
        void HandleBattlefieldListOpcode(WorldPackets::Battleground::BattlefieldListRequest& battlefieldList);
        void HandleBattlefieldLeaveOpcode(WorldPackets::Battleground::BattlefieldLeave& battlefieldLeave);
        void HandleBattlemasterJoinArena(WorldPackets::Battleground::BattlemasterJoinArena& packet);
        void HandleReportPvPAFK(WorldPackets::Battleground::ReportPvPPlayerAFK& reportPvPPlayerAFK);
        void HandleRequestRatedBattlefieldInfo(WorldPackets::Battleground::RequestRatedBattlefieldInfo& packet);
        void HandleGetPVPOptionsEnabled(WorldPackets::Battleground::GetPVPOptionsEnabled& getPvPOptionsEnabled);
        void HandleRequestPvpReward(WorldPackets::Battleground::RequestPVPRewards& packet);
        void HandleAreaSpiritHealerQueryOpcode(WorldPackets::Battleground::AreaSpiritHealerQuery& areaSpiritHealerQuery);
        void HandleAreaSpiritHealerQueueOpcode(WorldPackets::Battleground::AreaSpiritHealerQueue& areaSpiritHealerQueue);
        void HandleHearthAndResurrect(WorldPackets::Battleground::HearthAndResurrect& hearthAndResurrect);
        void HandleRequestBattlefieldStatusOpcode(WorldPackets::Battleground::RequestBattlefieldStatus& requestBattlefieldStatus);

        // Battlefield
        void SendBfInvitePlayerToWar(uint64 queueId, uint32 zoneId, uint32 acceptTime);
        void SendBfInvitePlayerToQueue(uint64 queueId, int8 battleState);
        void SendBfQueueInviteResponse(uint64 queueId, uint32 zoneId, int8 battleStatus, bool canQueue = true, bool loggingIn = false);
        void SendBfEntered(uint64 queueId, bool relocated, bool onOffense);
        void SendBfLeaveMessage(uint64 queueId, int8 battleState, bool relocated, BFLeaveReason reason = BF_LEAVE_REASON_EXITED);
        void HandleBfEntryInviteResponse(WorldPackets::Battlefield::BFMgrEntryInviteResponse& bfMgrEntryInviteResponse);
        void HandleBfQueueInviteResponse(WorldPackets::Battlefield::BFMgrQueueInviteResponse& bfMgrQueueInviteResponse);
        void HandleBfQueueExitRequest(WorldPackets::Battlefield::BFMgrQueueExitRequest& bfMgrQueueExitRequest);


        void HandleMinimapPingOpcode(WorldPackets::Party::MinimapPingClient& packet);
        void HandleRandomRollOpcode(WorldPackets::Misc::RandomRollClient& packet);
        void HandleFarSightOpcode(WorldPackets::Misc::FarSight& packet);
        void HandleSetDungeonDifficultyOpcode(WorldPackets::Misc::SetDungeonDifficulty& setDungeonDifficulty);
        void HandleSetRaidDifficultyOpcode(WorldPackets::Misc::SetRaidDifficulty& setRaidDifficulty);
        void HandleSetTitleOpcode(WorldPackets::Character::SetTitle& packet);
        void HandleTimeSyncResponse(WorldPackets::Misc::TimeSyncResponse& packet);
        void HandleWhoIsOpcode(WorldPackets::Who::WhoIsRequest& packet);
        void HandleResetInstancesOpcode(WorldPackets::Instance::ResetInstances& packet);
        void HandleInstanceLockResponse(WorldPackets::Instance::InstanceLockResponse& packet);

        // Looking for Dungeon/Raid
        void SendLfgPlayerLockInfo();
        void SendLfgPartyLockInfo();
        void HandleLfgJoinOpcode(WorldPackets::LFG::DFJoin& dfJoin);
        void HandleLfgLeaveOpcode(WorldPackets::LFG::DFLeave& dfLeave);
        void HandleLfgProposalResultOpcode(WorldPackets::LFG::DFProposalResponse& dfProposalResponse);
        void HandleLfgSetRolesOpcode(WorldPackets::LFG::DFSetRoles& dfSetRoles);
        void HandleLfgSetBootVoteOpcode(WorldPackets::LFG::DFBootPlayerVote& dfBootPlayerVote);
        void HandleLfgTeleportOpcode(WorldPackets::LFG::DFTeleport& dfTeleport);
        void HandleDFGetSystemInfo(WorldPackets::LFG::DFGetSystemInfo& dfGetSystemInfo);
        void HandleDFGetJoinStatus(WorldPackets::LFG::DFGetJoinStatus& dfGetJoinStatus);

        void SendLfgUpdateStatus(lfg::LfgUpdateData const& updateData, bool party);
        void SendLfgRoleChosen(ObjectGuid guid, uint8 roles);
        void SendLfgRoleCheckUpdate(lfg::LfgRoleCheck const& pRoleCheck);
        void SendLfgJoinResult(lfg::LfgJoinResultData const& joinData);
        void SendLfgQueueStatus(lfg::LfgQueueStatusData const& queueData);
        void SendLfgPlayerReward(lfg::LfgPlayerRewardData const& lfgPlayerRewardData);
        void SendLfgBootProposalUpdate(lfg::LfgPlayerBoot const& boot);
        void SendLfgUpdateProposal(lfg::LfgProposal const& proposal);
        void SendLfgDisabled();
        void SendLfgOfferContinue(uint32 dungeonEntry);
        void SendLfgTeleportError(lfg::LfgTeleportResult err);

        void HandleSelfResOpcode(WorldPackets::Spells::SelfRes& selfRes);
        void HandleRequestPetInfo(WorldPackets::Pet::RequestPetInfo& packet);

        // Socket gem
        void HandleSocketGems(WorldPackets::Item::SocketGems& socketGems);
        void HandleSortBags(WorldPackets::Item::SortBags& sortBags);
        void HandleSortBankBags(WorldPackets::Item::SortBankBags& sortBankBags);
        void HandleSortReagentBankBags(WorldPackets::Item::SortReagentBankBags& sortReagentBankBags);
        void HandleRemoveNewItem(WorldPackets::Item::RemoveNewItem& removeNewItem);

        void HandleCancelTempEnchantmentOpcode(WorldPackets::Item::CancelTempEnchantment& cancelTempEnchantment);

        void HandleGetItemPurchaseData(WorldPackets::Item::GetItemPurchaseData& packet);
        void HandleItemRefund(WorldPackets::Item::ItemPurchaseRefund& packet);

        void HandleSetTaxiBenchmark(WorldPackets::Misc::SetTaxiBenchmarkMode& packet);

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
        void HandleGrantLevel(WorldPackets::RaF::GrantLevel& grantLevel);
        void HandleAcceptGrantLevel(WorldPackets::RaF::AcceptLevelGrant& acceptLevelGrant);

        // Calendar
        void HandleCalendarGetCalendar(WorldPackets::Calendar::CalendarGetCalendar& calendarGetCalendar);
        void HandleCalendarGetEvent(WorldPackets::Calendar::CalendarGetEvent& calendarGetEvent);
        void HandleCalendarGuildFilter(WorldPackets::Calendar::CalendarGuildFilter& calendarGuildFilter);
        void HandleCalendarAddEvent(WorldPackets::Calendar::CalendarAddEvent& calendarAddEvent);
        void HandleCalendarUpdateEvent(WorldPackets::Calendar::CalendarUpdateEvent& calendarUpdateEvent);
        void HandleCalendarRemoveEvent(WorldPackets::Calendar::CalendarRemoveEvent& calendarRemoveEvent);
        void HandleCalendarCopyEvent(WorldPackets::Calendar::CalendarCopyEvent& calendarCopyEvent);
        void HandleCalendarEventInvite(WorldPackets::Calendar::CalendarEventInvite& calendarEventInvite);
        void HandleCalendarEventRsvp(WorldPackets::Calendar::CalendarEventRSVP& calendarEventRSVP);
        void HandleCalendarEventRemoveInvite(WorldPackets::Calendar::CalendarRemoveInvite& calendarRemoveInvite);
        void HandleCalendarEventStatus(WorldPackets::Calendar::CalendarEventStatus& calendarEventStatus);
        void HandleCalendarEventModeratorStatus(WorldPackets::Calendar::CalendarEventModeratorStatus& calendarEventModeratorStatus);
        void HandleCalendarComplain(WorldPackets::Calendar::CalendarComplain& calendarComplain);
        void HandleCalendarGetNumPending(WorldPackets::Calendar::CalendarGetNumPending& calendarGetNumPending);
        void HandleCalendarEventSignup(WorldPackets::Calendar::CalendarEventSignUp& calendarEventSignUp);

        void SendCalendarRaidLockout(InstanceSave const* save, bool add);
        void SendCalendarRaidLockoutUpdated(InstanceSave const* save);
        void HandleSetSavedInstanceExtend(WorldPackets::Calendar::SetSavedInstanceExtend& setSavedInstanceExtend);

        // Void Storage
        void HandleVoidStorageUnlock(WorldPackets::VoidStorage::UnlockVoidStorage& unlockVoidStorage);
        void HandleVoidStorageQuery(WorldPackets::VoidStorage::QueryVoidStorage& queryVoidStorage);
        void HandleVoidStorageTransfer(WorldPackets::VoidStorage::VoidStorageTransfer& voidStorageTransfer);
        void HandleVoidSwapItem(WorldPackets::VoidStorage::SwapVoidItem& swapVoidItem);
        void SendVoidStorageTransferResult(VoidTransferError result);

        // Collections
        void HandleCollectionItemSetFavorite(WorldPackets::Collections::CollectionItemSetFavorite& collectionItemSetFavorite);

        // Transmogrification
        void HandleTransmogrifyItems(WorldPackets::Transmogrification::TransmogrifyItems& transmogrifyItems);

        // Miscellaneous
        void HandleSpellClick(WorldPackets::Spells::SpellClick& spellClick);
        void HandleMirrorImageDataRequest(WorldPackets::Spells::GetMirrorImageData& getMirrorImageData);
        void HandleGuildSetFocusedAchievement(WorldPackets::Achievement::GuildSetFocusedAchievement& setFocusedAchievement);
        void HandleEquipmentSetSave(WorldPackets::EquipmentSet::SaveEquipmentSet& saveEquipmentSet);
        void HandleDeleteEquipmentSet(WorldPackets::EquipmentSet::DeleteEquipmentSet& deleteEquipmentSet);
        void HandleUseEquipmentSet(WorldPackets::EquipmentSet::UseEquipmentSet& useEquipmentSet);
        void HandleUITimeRequest(WorldPackets::Misc::UITimeRequest& /*request*/);
        void HandleQueryQuestCompletionNPCs(WorldPackets::Query::QueryQuestCompletionNPCs& queryQuestCompletionNPCs);
        void HandleQuestPOIQuery(WorldPackets::Query::QuestPOIQuery& questPoiQuery);
        void HandleViolenceLevel(WorldPackets::Misc::ViolenceLevel& violenceLevel);
        void HandleObjectUpdateFailedOpcode(WorldPackets::Misc::ObjectUpdateFailed& objectUpdateFailed);
        void HandleObjectUpdateRescuedOpcode(WorldPackets::Misc::ObjectUpdateRescued& objectUpdateRescued);
        void HandleRequestCategoryCooldowns(WorldPackets::Spells::RequestCategoryCooldowns& requestCategoryCooldowns);
        void HandleCloseInteraction(WorldPackets::Misc::CloseInteraction& closeInteraction);

        // Toys
        void HandleAddToy(WorldPackets::Toy::AddToy& packet);
        void HandleUseToy(WorldPackets::Toy::UseToy& packet);

        void HandleMountSetFavorite(WorldPackets::Misc::MountSetFavorite& mountSetFavorite);

        // Scenes
        void HandleSceneTriggerEvent(WorldPackets::Scenes::SceneTriggerEvent& sceneTriggerEvent);
        void HandleScenePlaybackComplete(WorldPackets::Scenes::ScenePlaybackComplete& scenePlaybackComplete);
        void HandleScenePlaybackCanceled(WorldPackets::Scenes::ScenePlaybackCanceled& scenePlaybackCanceled);

        // Token
        void HandleUpdateListedAuctionableTokens(WorldPackets::Token::UpdateListedAuctionableTokens& updateListedAuctionableTokens);
        void HandleRequestWowTokenMarketPrice(WorldPackets::Token::RequestWowTokenMarketPrice& requestWowTokenMarketPrice);

        // Compact Unit Frames (4.x)
        void HandleSaveCUFProfiles(WorldPackets::Misc::SaveCUFProfiles& packet);
        void SendLoadCUFProfiles();

        // Garrison
        void HandleGetGarrisonInfo(WorldPackets::Garrison::GetGarrisonInfo& getGarrisonInfo);
        void HandleGarrisonPurchaseBuilding(WorldPackets::Garrison::GarrisonPurchaseBuilding& garrisonPurchaseBuilding);
        void HandleGarrisonCancelConstruction(WorldPackets::Garrison::GarrisonCancelConstruction& garrisonCancelConstruction);
        void HandleGarrisonRequestBlueprintAndSpecializationData(WorldPackets::Garrison::GarrisonRequestBlueprintAndSpecializationData& garrisonRequestBlueprintAndSpecializationData);
        void HandleGarrisonGetBuildingLandmarks(WorldPackets::Garrison::GarrisonGetBuildingLandmarks& garrisonGetBuildingLandmarks);

        // Battle Pets
        void HandleBattlePetRequestJournal(WorldPackets::BattlePet::BattlePetRequestJournal& battlePetRequestJournal);
        void HandleBattlePetSetBattleSlot(WorldPackets::BattlePet::BattlePetSetBattleSlot& battlePetSetBattleSlot);
        void HandleBattlePetModifyName(WorldPackets::BattlePet::BattlePetModifyName& battlePetModifyName);
        void HandleBattlePetDeletePet(WorldPackets::BattlePet::BattlePetDeletePet& battlePetDeletePet);
        void HandleBattlePetSetFlags(WorldPackets::BattlePet::BattlePetSetFlags& battlePetSetFlags);
        void HandleBattlePetSummon(WorldPackets::BattlePet::BattlePetSummon& battlePetSummon);
        void HandleCageBattlePet(WorldPackets::BattlePet::CageBattlePet& cageBattlePet);

        // Warden
        void HandleWardenData(WorldPackets::Warden::WardenData& packet);

        // Battlenet
        void HandleBattlenetRequest(WorldPackets::Battlenet::Request& request);
        void HandleBattlenetRequestRealmListTicket(WorldPackets::Battlenet::RequestRealmListTicket& requestRealmListTicket);

        void SendBattlenetResponse(uint32 serviceHash, uint32 methodId, uint32 token, pb::Message const* response);
        void SendBattlenetResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status);
        void SendBattlenetRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request, std::function<void(MessageBuffer)> callback);
        void SendBattlenetRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request);

        std::array<uint8, 32> const& GetRealmListSecret() const { return _realmListSecret; }
        void SetRealmListSecret(std::array<uint8, 32> const& secret) { memcpy(_realmListSecret.data(), secret.data(), secret.size()); }

        std::unordered_map<uint32, uint8> const& GetRealmCharacterCounts() const { return _realmCharacterCounts; }

        void HandleQueryRealmName(WorldPackets::Query::QueryRealmName& queryRealmName);

        // Artifact
        void HandleArtifactAddPower(WorldPackets::Artifact::ArtifactAddPower& artifactAddPower);
        void HandleArtifactSetAppearance(WorldPackets::Artifact::ArtifactSetAppearance& artifactSetAppearance);
        void HandleConfirmArtifactRespec(WorldPackets::Artifact::ConfirmArtifactRespec& confirmArtifactRespec);

        // Scenario
        void HandleQueryScenarioPOI(WorldPackets::Scenario::QueryScenarioPOI& queryScenarioPOI);

        // Honor
        void HandlePvpPrestigeRankUp(WorldPackets::Misc::PvpPrestigeRankUp& /*pvpPrestigeRankUp*/);

        union ConnectToKey
        {
            struct
            {
                uint64 AccountId : 32;
                uint64 ConnectionType : 1;
                uint64 Key : 31;
            } Fields;

            uint64 Raw;
        };

        uint64 GetConnectToInstanceKey() const { return _instanceConnectKey.Raw; }
    private:
        void ProcessQueryCallbacks();

        QueryResultHolderFuture _realmAccountLoginCallback;
        QueryResultHolderFuture _accountLoginCallback;
        QueryResultHolderFuture _charLoginCallback;

        QueryCallbackProcessor _queryProcessor;

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
        void LogUnexpectedOpcode(WorldPacket* packet, const char* status, const char *reason);

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
        std::string _accountName;
        uint32 _battlenetAccountId;
        uint8 m_accountExpansion;
        uint8 m_expansion;
        std::string _os;

        std::array<uint8, 32> _realmListSecret;
        std::unordered_map<uint32 /*realmAddress*/, uint8> _realmCharacterCounts;
        std::unordered_map<uint32, std::function<void(MessageBuffer)>> _battlenetResponseCallbacks;
        uint32 _battlenetRequestToken;

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
        std::vector<std::string> _registeredAddonPrefixes;
        bool _filterAddonMessages;
        uint32 recruiterId;
        bool isRecruiter;
        LockedQueue<WorldPacket*> _recvQueue;
        rbac::RBACData* _RBACData;
        uint32 expireTime;
        bool forceExit;
        ObjectGuid m_currentBankerGUID;

        std::unique_ptr<BattlePetMgr> _battlePetMgr;

        std::unique_ptr<CollectionMgr> _collectionMgr;

        ConnectToKey _instanceConnectKey;

        WorldSession(WorldSession const& right) = delete;
        WorldSession& operator=(WorldSession const& right) = delete;
};

#endif
/// @}
