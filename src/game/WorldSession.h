/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/// \addtogroup u2w
/// @{
/// \file

#ifndef __WORLDSESSION_H
#define __WORLDSESSION_H

#include "Common.h"
#include "SharedDefines.h"

class MailItemsInfo;
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
class WorldPacket;
class WorldSocket;
class WorldSession;
class QueryResult;
class LoginQueryHolder;
class CharacterHandler;
struct AreaTableEntry;

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

struct AddonInfo
{
    AddonInfo(const std::string& name, uint8 enabled, uint32 crc)
    {
        Name = name;
        Enabled = enabled;
        CRC = crc;
    }

    std::string Name;
    uint8 Enabled;
    uint32 CRC;
};

typedef std::list<AddonInfo> AddonsList;

enum PartyOperation
{
    PARTY_OP_INVITE = 0,
    PARTY_OP_LEAVE = 2
};

enum PartyResult
{
    PARTY_RESULT_OK                   = 0,
    PARTY_RESULT_CANT_FIND_TARGET     = 1,
    PARTY_RESULT_NOT_IN_YOUR_PARTY    = 2,
    PARTY_RESULT_NOT_IN_YOUR_INSTANCE = 3,
    PARTY_RESULT_PARTY_FULL           = 4,
    PARTY_RESULT_ALREADY_IN_GROUP     = 5,
    PARTY_RESULT_YOU_NOT_IN_GROUP     = 6,
    PARTY_RESULT_YOU_NOT_LEADER       = 7,
    PARTY_RESULT_TARGET_UNFRIENDLY    = 8,
    PARTY_RESULT_TARGET_IGNORE_YOU    = 9,
    PARTY_RESULT_INVITE_RESTRICTED    = 13
};

/// Player session in the World
class TRINITY_DLL_SPEC WorldSession
{
    friend class CharacterHandler;
    public:
        WorldSession(uint32 id, WorldSocket *sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale);
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
        void SendNotification(int32 string_id,...);
        void SendPetNameInvalid(uint32 error, const std::string& name, DeclinedName *declinedName);
        void SendLfgResult(uint32 type, uint32 entry, uint8 lfg_type);
        void SendLfgUpdate(uint8 unk1, uint8 unk2, uint8 unk3);
        void SendPartyResult(PartyOperation operation, const std::string& member, PartyResult res);
        void SendAreaTriggerMessage(const char* Text, ...) ATTR_PRINTF(2,3);
        void SendSetPhaseShift(uint32 phaseShift);

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
        bool Update(uint32 diff);

        /// Handle the authentication waiting queue (to be completed)
        void SendAuthWaitQue(uint32 position);

        //void SendTestCreatureQueryOpcode( uint32 entry, uint64 guid, uint32 testvalue );
        void SendNameQueryOpcode(Player* p);
        void SendNameQueryOpcodeFromDB(uint64 guid);
        static void SendNameQueryOpcodeFromDBCallBack(QueryResult *result, uint32 accountId);

        void SendTrainerList( uint64 guid );
        void SendTrainerList( uint64 guid, const std::string& strTitle );
        void SendListInventory( uint64 guid );
        void SendShowBank( uint64 guid );
        void SendTabardVendorActivate( uint64 guid );
        void SendSpiritResurrect();
        void SendBindPoint(Creature* npc);

        void SendAttackStop(Unit const* enemy);

        void SendBattlegGroundList( uint64 guid, BattleGroundTypeId bgTypeId );

        void SendTradeStatus(uint32 status);
        void SendCancelTrade();

        void SendStablePet(uint64 guid );
        void SendPetitionQueryOpcode( uint64 petitionguid);
        void SendUpdateTrade();

        //pet
        void SendPetNameQuery(uint64 guid, uint32 petnumber);

        // Account Data
        AccountData *GetAccountData(AccountDataType type) { return &m_accountData[type]; }
        void SetAccountData(AccountDataType type, time_t time_, std::string data);
        void SendAccountDataTimes(uint32 mask);
        void LoadGlobalAccountData();
        void LoadAccountData(QueryResult* result, uint32 mask);
        void LoadTutorialsData();
        void SendTutorialsData();
        void SaveTutorialsData();
        uint32 GetTutorialInt(uint32 intId )
        {
            return m_Tutorials[intId];
        }

        void SetTutorialInt(uint32 intId, uint32 value)
        {
            if(m_Tutorials[intId] != value)
            {
                m_Tutorials[intId] = value;
                m_TutorialsChanged = true;
            }
        }

        //mail
                                                            //used with item_page table
        bool SendItemInfo( uint32 itemid, WorldPacket data );
        static void SendReturnToSender(uint8 messageType, uint32 sender_acc, uint32 sender_guid, uint32 receiver_guid, const std::string& subject, uint32 itemTextId, MailItemsInfo *mi, uint32 money, uint16 mailTemplateId = 0);
        static void SendMailTo(Player* receiver, uint8 messageType, uint8 stationery, uint32 sender_guidlow_or_entry, uint32 received_guidlow, std::string subject, uint32 itemTextId, MailItemsInfo* mi, uint32 money, uint32 COD, uint32 checked, uint32 deliver_delay = 0, uint16 mailTemplateId = 0);

        //auction
        void SendAuctionHello( uint64 guid, Creature * unit );
        void SendAuctionCommandResult( uint32 auctionId, uint32 Action, uint32 ErrorCode, uint32 bidError = 0);
        void SendAuctionBidderNotification( uint32 location, uint32 auctionId, uint64 bidder, uint32 bidSum, uint32 diff, uint32 item_template);
        void SendAuctionOwnerNotification( AuctionEntry * auction );
        void SendAuctionOutbiddedMail( AuctionEntry * auction, uint32 newPrice );
        void SendAuctionCancelledToBidderMail( AuctionEntry* auction );

        //Item Enchantment
        void SendEnchantmentLog(uint64 Target, uint64 Caster,uint32 ItemID,uint32 SpellID);
        void SendItemEnchantTimeUpdate(uint64 Playerguid, uint64 Itemguid,uint32 slot,uint32 Duration);

        //Taxi
        void SendTaxiStatus( uint64 guid );
        void SendTaxiMenu( Creature* unit );
        void SendDoFlight( uint32 mountDisplayId, uint32 path, uint32 pathNode = 0 );
        bool SendLearnNewTaxiNode( Creature* unit );

        // Guild/Arena Team
        void SendGuildCommandResult(uint32 typecmd, const std::string& str, uint32 cmdresult);
        void SendArenaTeamCommandResult(uint32 team_action, const std::string& team, const std::string& player, uint32 error_id);
        void BuildArenaTeamEventPacket(WorldPacket *data, uint8 eventid, uint8 str_count, const std::string& str1, const std::string& str2, const std::string& str3);
        void SendNotInArenaTeamPacket(uint8 type);
        void SendPetitionShowList( uint64 guid );
        void SendSaveGuildEmblem( uint32 msg );
        void SendBattleGroundOrArenaJoinError(uint8 err);

        // Looking For Group
        // TRUE values set by client sending CMSG_LFG_SET_AUTOJOIN and CMSG_LFM_CLEAR_AUTOFILL before player login
        bool LookingForGroup_auto_join;
        bool LookingForGroup_auto_add;

        void BuildPartyMemberStatsChangedPacket(Player *player, WorldPacket *data);

        void DoLootRelease( uint64 lguid );

        // Account mute time
        time_t m_muteTime;

        // Locales
        LocaleConstant GetSessionDbcLocale() const { return m_sessionDbcLocale; }
        int GetSessionDbLocaleIndex() const { return m_sessionDbLocaleIndex; }
        const char *GetTrinityString(int32 entry) const;

        uint32 GetLatency() const { return m_latency; }
        void SetLatency(uint32 latency) { m_latency = latency; }
        uint32 getDialogStatus(Player *pPlayer, Object* questgiver, uint32 defstatus);

    public:                                                 // opcodes handlers

        void Handle_NULL(WorldPacket& recvPacket);          // not used
        void Handle_EarlyProccess( WorldPacket& recvPacket);// just mark packets processed in WorldSocket::OnRead
        void Handle_ServerSide(WorldPacket& recvPacket);    // sever side only, can't be accepted from client
        void Handle_Deprecated(WorldPacket& recvPacket);    // never used anymore by client

        void HandleCharEnumOpcode(WorldPacket& recvPacket);
        void HandleCharDeleteOpcode(WorldPacket& recvPacket);
        void HandleCharCreateOpcode(WorldPacket& recvPacket);
        void HandlePlayerLoginOpcode(WorldPacket& recvPacket);
        void HandleCharEnum(QueryResult * result);
        void HandlePlayerLogin(LoginQueryHolder * holder);

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

        void HandleMoveHoverAck( WorldPacket & recv_data );

        void HandleMountSpecialAnimOpcode(WorldPacket &recvdata);

        // character view
        void HandleShowingHelmOpcode(WorldPacket& recv_data);
        void HandleShowingCloakOpcode(WorldPacket& recv_data);

        // repair
        void HandleRepairItemOpcode(WorldPacket& recvPacket);

        // Knockback
        void HandleMoveKnockBackAck(WorldPacket& recvPacket);

        void HandleMoveTeleportAck(WorldPacket& recvPacket);
        void HandleForceSpeedChangeAck( WorldPacket & recv_data );

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
        void SendGMTicketGetTicket(uint32 status, char const* text);

        //void HandleGMSurveySubmit(WorldPacket& recvPacket);

        void HandleTogglePvP(WorldPacket& recvPacket);

        void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
        void HandleSetTargetOpcode(WorldPacket& recvPacket);
        void HandleSetSelectionOpcode(WorldPacket& recvPacket);
        void HandleStandStateChangeOpcode(WorldPacket& recvPacket);
        void HandleEmoteOpcode(WorldPacket& recvPacket);
        void HandleContactListOpcode(WorldPacket& recvPacket);
        void HandleAddFriendOpcode(WorldPacket& recvPacket);
        static void HandleAddFriendOpcodeCallBack(QueryResult *result, uint32 accountId, std::string friendNote);
        void HandleDelFriendOpcode(WorldPacket& recvPacket);
        void HandleAddIgnoreOpcode(WorldPacket& recvPacket);
        static void HandleAddIgnoreOpcodeCallBack(QueryResult *result, uint32 accountId);
        void HandleDelIgnoreOpcode(WorldPacket& recvPacket);
        void HandleSetContactNotesOpcode(WorldPacket& recvPacket);
        void HandleBugOpcode(WorldPacket& recvPacket);
        void HandleSetAmmoOpcode(WorldPacket& recvPacket);
        void HandleItemNameQueryOpcode(WorldPacket& recvPacket);

        void HandleAreaTriggerOpcode(WorldPacket& recvPacket);

        void HandleSetFactionAtWar( WorldPacket & recv_data );
        void HandleSetFactionCheat( WorldPacket & recv_data );
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

        void HandleRequestRaidInfoOpcode( WorldPacket & recv_data );

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
        void HandleOptOutOfLootOpcode( WorldPacket &recv_data );
        void HandleLootMethodOpcode(WorldPacket& recvPacket);
        void HandleLootRoll( WorldPacket &recv_data );
        void HandleRequestPartyMemberStatsOpcode( WorldPacket &recv_data );
        void HandleRaidTargetUpdateOpcode( WorldPacket & recv_data );
        void HandleRaidReadyCheckOpcode( WorldPacket & recv_data );
        void HandleRaidReadyCheckFinishedOpcode( WorldPacket & recv_data );
        void HandleGroupRaidConvertOpcode( WorldPacket & recv_data );
        void HandleGroupChangeSubGroupOpcode( WorldPacket & recv_data );
        void HandleGroupAssistantLeaderOpcode( WorldPacket & recv_data );
        void HandlePartyAssignmentOpcode( WorldPacket & recv_data );

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
        void HandleAuctionListItems( WorldPacket & recv_data );
        void HandleAuctionListBidderItems( WorldPacket & recv_data );
        void HandleAuctionSellItem( WorldPacket & recv_data );
        void HandleAuctionRemoveItem( WorldPacket & recv_data );
        void HandleAuctionListOwnerItems( WorldPacket & recv_data );
        void HandleAuctionPlaceBid( WorldPacket & recv_data );
        void HandleAuctionListPendingSales( WorldPacket & recv_data );

        void HandleGetMailList( WorldPacket & recv_data );
        void HandleSendMail( WorldPacket & recv_data );
        void HandleMailTakeMoney( WorldPacket & recv_data );
        void HandleMailTakeItem( WorldPacket & recv_data );
        void HandleMailMarkAsRead( WorldPacket & recv_data );
        void HandleMailReturnToSender( WorldPacket & recv_data );
        void HandleMailDelete( WorldPacket & recv_data );
        void HandleItemTextQuery( WorldPacket & recv_data);
        void HandleMailCreateTextItem(WorldPacket & recv_data );
        void HandleQueryNextMailTime(WorldPacket & recv_data );
        void HandleCancelChanneling(WorldPacket & recv_data );

        void SendItemPageInfo( ItemPrototype *itemProto );
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
        void HandleSwapItem( WorldPacket & recvPacket);
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
        void HandleQuestgiverCancel(WorldPacket& recv_data );
        void HandleQuestLogSwapQuest(WorldPacket& recv_data );
        void HandleQuestLogRemoveQuest(WorldPacket& recv_data);
        void HandleQuestConfirmAccept(WorldPacket& recv_data);
        void HandleQuestgiverCompleteQuest(WorldPacket& recv_data);
        void HandleQuestgiverQuestAutoLaunch(WorldPacket& recvPacket);
        void HandlePushQuestToParty(WorldPacket& recvPacket);
        void HandleQuestPushResult(WorldPacket& recvPacket);

        bool processChatmessageFurtherAfterSecurityChecks(std::string&, uint32);
        void HandleMessagechatOpcode(WorldPacket& recvPacket);
        void HandleTextEmoteOpcode(WorldPacket& recvPacket);
        void HandleChatIgnoredOpcode(WorldPacket& recvPacket);

        void HandleReclaimCorpseOpcode( WorldPacket& recvPacket );
        void HandleCorpseQueryOpcode( WorldPacket& recvPacket );
        void HandleCorpseMapPositionQuery( WorldPacket& recvPacket );
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

        void HandleTutorialFlag ( WorldPacket & recv_data );
        void HandleTutorialClear( WorldPacket & recv_data );
        void HandleTutorialReset( WorldPacket & recv_data );

        //Pet
        void HandlePetAction( WorldPacket & recv_data );
        void HandlePetActionHelper(Unit *pet, uint64 guid1, uint16 spellid, uint16 flag, uint64 guid2);
        void HandlePetNameQuery( WorldPacket & recv_data );
        void HandlePetSetAction( WorldPacket & recv_data );
        void HandlePetAbandon( WorldPacket & recv_data );
        void HandlePetRename( WorldPacket & recv_data );
        void HandlePetCancelAuraOpcode( WorldPacket& recvPacket );
        void HandlePetUnlearnOpcode( WorldPacket& recvPacket );
        void HandlePetSpellAutocastOpcode( WorldPacket& recvPacket );
        void HandlePetCastSpellOpcode( WorldPacket& recvPacket );
        void HandlePetLearnTalent( WorldPacket& recvPacket );
        void HandleLearnPreviewTalentsPet( WorldPacket& recvPacket );

        void HandleSetActionBarToggles(WorldPacket& recv_data);

        void HandleCharRenameOpcode(WorldPacket& recv_data);
        static void HandleChangePlayerNameOpcodeCallBack(QueryResult *result, uint32 accountId, std::string newname);
        void HandleSetPlayerDeclinedNames(WorldPacket& recv_data);

        void HandleTotemDestroyed(WorldPacket& recv_data);

        //BattleGround
        void HandleBattlemasterHelloOpcode(WorldPacket &recv_data);
        void HandleBattlemasterJoinOpcode(WorldPacket &recv_data);
        void HandleBattleGroundPlayerPositionsOpcode(WorldPacket& recv_data);
        void HandlePVPLogDataOpcode( WorldPacket &recv_data );
        void HandleBattleFieldPortOpcode( WorldPacket &recv_data );
        void HandleBattlefieldListOpcode( WorldPacket &recv_data );
        void HandleLeaveBattlefieldOpcode( WorldPacket &recv_data );
        void HandleBattlemasterJoinArena( WorldPacket &recv_data );
        void HandleReportPvPAFK( WorldPacket &recv_data );

        void HandleWardenDataOpcode(WorldPacket& recv_data);
        void HandleWorldTeleportOpcode(WorldPacket& recv_data);
        void HandleMinimapPingOpcode(WorldPacket& recv_data);
        void HandleRandomRollOpcode(WorldPacket& recv_data);
        void HandleFarSightOpcode(WorldPacket& recv_data);
        void HandleSetLfgOpcode(WorldPacket& recv_data);
        void HandleSetDungeonDifficultyOpcode(WorldPacket& recv_data);
        void HandleSetRaidDifficultyOpcode(WorldPacket& recv_data);
        void HandleMoveSetCanFlyAckOpcode(WorldPacket& recv_data);
        void HandleLfgSetAutoJoinOpcode(WorldPacket& recv_data);
        void HandleLfgClearAutoJoinOpcode(WorldPacket& recv_data);
        void HandleLfmSetAutoFillOpcode(WorldPacket& recv_data);
        void HandleLfmClearAutoFillOpcode(WorldPacket& recv_data);
        void HandleLfgClearOpcode(WorldPacket& recv_data);
        void HandleLfmClearOpcode(WorldPacket& recv_data);
        void HandleSetLfmOpcode(WorldPacket& recv_data);
        void HandleSetLfgCommentOpcode(WorldPacket& recv_data);
        void HandleLfgSetRoles(WorldPacket& recv_data);
        void HandleSetTitleOpcode(WorldPacket& recv_data);
        void HandleRealmSplitOpcode(WorldPacket& recv_data);
        void HandleTimeSyncResp(WorldPacket& recv_data);
        void HandleWhoisOpcode(WorldPacket& recv_data);
        void HandleResetInstancesOpcode(WorldPacket& recv_data);

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
        void HandleMirrrorImageDataRequest( WorldPacket & recv_data );
        void HandleAlterAppearance(WorldPacket& recv_data);
        void HandleRemoveGlyph(WorldPacket& recv_data);
        void HandleCharCustomize(WorldPacket& recv_data);
        void HandleQueryInspectAchievements(WorldPacket& recv_data);
        void HandleEquipmentSetSave(WorldPacket& recv_data);
        void HandleEquipmentSetDelete(WorldPacket& recv_data);
        void HandleEquipmentSetUse(WorldPacket& recv_data);
        void HandleWorldStateUITimerUpdate(WorldPacket& recv_data);
        void HandleOnPVPKill(Player *killed);
        bool HandleOnPlayerChat(const char *text);
        uint32 HandleOnGetXP(uint32 amount);
        int32 HandleOnGetMoney(int32 amount);
        void HandleOnAreaChange(AreaTableEntry const *pArea);
        bool HandleOnItemClick(Item *pItem);
        bool HandleOnItemOpen(Item *pItem);
        bool HandleOnGoClick(GameObject *pGameObject);
        void HandleOnCreatureKill(Creature *pCreature);
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
        int m_sessionDbLocaleIndex;
        uint32 m_latency;
        AccountData m_accountData[NUM_ACCOUNT_DATA_TYPES];
        uint32 m_Tutorials[8];
        bool   m_TutorialsChanged;
        AddonsList m_addonsList;
        ACE_Based::LockedQueue<WorldPacket*, ACE_Thread_Mutex> _recvQueue;
};
#endif
/// @}
