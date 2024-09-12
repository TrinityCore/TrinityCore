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

/** \file
    \ingroup u2w
*/

#include "WorldSession.h"
#include "QueryHolder.h"
#include "AccountMgr.h"
#include "AuthenticationPackets.h"
#include "BattlePetMgr.h"
#include "BattlegroundMgr.h"
#include "BattlenetPackets.h"
#include "CharacterPackets.h"
#include "ChatPackets.h"
#include "ClientConfigPackets.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Hyperlinks.h"
#include "IpAddress.h"
#include "Log.h"
#include "Map.h"
#include "Metric.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PacketUtilities.h"
#include "Player.h"
#include "QueryHolder.h"
#include "Random.h"
#include "RBAC.h"
#include "RealmList.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "WardenWin.h"
#include "World.h"
#include "WorldSocket.h"
#include <boost/circular_buffer.hpp>

namespace {

std::string const DefaultPlayerName = "<none>";

} // namespace

bool MapSessionFilter::Process(WorldPacket* packet)
{
    ClientOpcodeHandler const* opHandle = opcodeTable[static_cast<OpcodeClient>(packet->GetOpcode())];

    //let's check if our opcode can be really processed in Map::Update()
    if (opHandle->ProcessingPlace == PROCESS_INPLACE)
        return true;

    //we do not process thread-unsafe packets
    if (opHandle->ProcessingPlace == PROCESS_THREADUNSAFE)
        return false;

    Player* player = m_pSession->GetPlayer();
    if (!player)
        return false;

    //in Map::Update() we do not process packets where player is not in world!
    return player->IsInWorld();
}

//we should process ALL packets when player is not in world/logged in
//OR packet handler is not thread-safe!
bool WorldSessionFilter::Process(WorldPacket* packet)
{
    ClientOpcodeHandler const* opHandle = opcodeTable[static_cast<OpcodeClient>(packet->GetOpcode())];

    //check if packet handler is supposed to be safe
    if (opHandle->ProcessingPlace == PROCESS_INPLACE)
        return true;

    //thread-unsafe packets should be processed in World::UpdateSessions()
    if (opHandle->ProcessingPlace == PROCESS_THREADUNSAFE)
        return true;

    //no player attached? -> our client! ^^
    Player* player = m_pSession->GetPlayer();
    if (!player)
        return true;

    //lets process all packets for non-in-the-world player
    return (player->IsInWorld() == false);
}

/// WorldSession constructor
WorldSession::WorldSession(uint32 id, std::string&& name, uint32 battlenetAccountId, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time,
    std::string os, Minutes timezoneOffset, uint32 build, ClientBuild::VariantId clientBuildVariant, LocaleConstant locale, uint32 recruiter, bool isARecruiter):
    m_muteTime(mute_time),
    m_timeOutTime(0),
    AntiDOS(this),
    m_GUIDLow(UI64LIT(0)),
    _player(nullptr),
    _security(sec),
    _accountId(id),
    _accountName(std::move(name)),
    _battlenetAccountId(battlenetAccountId),
    m_accountExpansion(expansion),
    m_expansion(std::min<uint8>(expansion, sWorld->getIntConfig(CONFIG_EXPANSION))),
    _os(std::move(os)),
    _clientBuild(build),
    _clientBuildVariant(clientBuildVariant),
    _battlenetRequestToken(0),
    _logoutTime(0),
    m_inQueue(false),
    m_playerLogout(false),
    m_playerRecentlyLogout(false),
    m_playerSave(false),
    m_sessionDbcLocale(sWorld->GetAvailableDbcLocale(locale)),
    m_sessionDbLocaleIndex(locale),
    _timezoneOffset(timezoneOffset),
    m_latency(0),
    _tutorialsChanged(TUTORIALS_FLAG_NONE),
    _filterAddonMessages(false),
    recruiterId(recruiter),
    isRecruiter(isARecruiter),
    _RBACData(nullptr),
    expireTime(60000), // 1 min after socket loss, session is deleted
    forceExit(false),
    _timeSyncClockDeltaQueue(std::make_unique<boost::circular_buffer<std::pair<int64, uint32>>>(6)),
    _timeSyncClockDelta(0),
    _pendingTimeSyncRequests(),
    _timeSyncNextCounter(0),
    _timeSyncTimer(0),
    _calendarEventCreationCooldown(0),
    _battlePetMgr(std::make_unique<BattlePets::BattlePetMgr>(this)),
    _collectionMgr(std::make_unique<CollectionMgr>(this))
{
    memset(_tutorials, 0, sizeof(_tutorials));

    if (sock)
    {
        m_Address = sock->GetRemoteIpAddress().to_string();
        ResetTimeOutTime(false);
        LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = {};", GetAccountId());     // One-time query
    }

    m_Socket[CONNECTION_TYPE_REALM] = std::move(sock);
    _instanceConnectKey.Raw = UI64LIT(0);
}

/// WorldSession destructor
WorldSession::~WorldSession()
{
    ///- unload player if not unloaded
    if (_player)
        LogoutPlayer (true);

    /// - If have unclosed socket, close it
    for (uint8 i = 0; i < 2; ++i)
    {
        if (m_Socket[i])
        {
            m_Socket[i]->CloseSocket();
            m_Socket[i].reset();
        }
    }

    delete _RBACData;

    ///- empty incoming packet queue
    WorldPacket* packet = nullptr;
    while (_recvQueue.next(packet))
        delete packet;

    LoginDatabase.PExecute("UPDATE account SET online = 0 WHERE id = {};", GetAccountId());     // One-time query
}

bool WorldSession::PlayerDisconnected() const
{
    return !(m_Socket[CONNECTION_TYPE_REALM] && m_Socket[CONNECTION_TYPE_REALM]->IsOpen() &&
             m_Socket[CONNECTION_TYPE_INSTANCE] && m_Socket[CONNECTION_TYPE_INSTANCE]->IsOpen());
}

std::string const & WorldSession::GetPlayerName() const
{
    return _player != nullptr ? _player->GetName() : DefaultPlayerName;
}

std::string WorldSession::GetPlayerInfo() const
{
    if (_player)
        return Trinity::StringFormat("[Player: {} {}, Account: {}]", _player->GetName(), _player->GetGUID(), GetAccountId());

    if (!m_playerLoading.IsEmpty())
        return Trinity::StringFormat("[Player: Logging in: {}, Account: {}]", m_playerLoading, GetAccountId());

    return Trinity::StringFormat("[Player: Account: {}]", GetAccountId());
}

/// Send a packet to the client
void WorldSession::SendPacket(WorldPacket const* packet, bool forced /*= false*/)
{
    if (packet->GetOpcode() < MIN_SMSG_OPCODE_NUMBER || packet->GetOpcode() > MAX_SMSG_OPCODE_NUMBER)
    {
        char const* specialName = packet->GetOpcode() == UNKNOWN_OPCODE ? "UNKNOWN_OPCODE" : "INVALID_OPCODE";
        TC_LOG_ERROR("network.opcode", "Prevented sending of {} (0x{:04X}) to {}", specialName, packet->GetOpcode(), GetPlayerInfo());
        return;
    }

    ServerOpcodeHandler const* handler = opcodeTable[static_cast<OpcodeServer>(packet->GetOpcode())];
    if (!handler)
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of opcode {} with non existing handler to {}", packet->GetOpcode(), GetPlayerInfo());
        return;
    }

    // Default connection index defined in Opcodes.cpp table
    ConnectionType conIdx = handler->ConnectionIndex;

    // Override connection index
    if (packet->GetConnection() != CONNECTION_TYPE_DEFAULT)
    {
        if (packet->GetConnection() != CONNECTION_TYPE_INSTANCE && IsInstanceOnlyOpcode(packet->GetOpcode()))
        {
            TC_LOG_ERROR("network.opcode", "Prevented sending of instance only opcode {} with connection type {} to {}", packet->GetOpcode(), uint32(packet->GetConnection()), GetPlayerInfo());
            return;
        }

        conIdx = packet->GetConnection();
    }

    if (!m_Socket[conIdx])
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of {} to non existent socket {} to {}", GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())), uint32(conIdx), GetPlayerInfo());
        return;
    }

    if (!forced)
    {
        if (handler->Status == STATUS_UNHANDLED)
        {
            TC_LOG_ERROR("network.opcode", "Prevented sending disabled opcode {} to {}", GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())), GetPlayerInfo());
            return;
        }
    }

#ifdef TRINITY_DEBUG
    // Code for network use statistic
    static uint64 sendPacketCount = 0;
    static uint64 sendPacketBytes = 0;

    static time_t firstTime = GameTime::GetGameTime();
    static time_t lastTime = firstTime;                     // next 60 secs start time

    static uint64 sendLastPacketCount = 0;
    static uint64 sendLastPacketBytes = 0;

    time_t cur_time = GameTime::GetGameTime();

    if ((cur_time - lastTime) < 60)
    {
        sendPacketCount += 1;
        sendPacketBytes += packet->size();

        sendLastPacketCount += 1;
        sendLastPacketBytes += packet->size();
    }
    else
    {
        uint64 minTime = uint64(cur_time - lastTime);
        uint64 fullTime = uint64(lastTime - firstTime);
        TC_LOG_DEBUG("misc", "Send all time packets count: {} bytes: {} avr.count/sec: {} avr.bytes/sec: {} time: {}", sendPacketCount, sendPacketBytes, float(sendPacketCount)/fullTime, float(sendPacketBytes)/fullTime, uint32(fullTime));
        TC_LOG_DEBUG("misc", "Send last min packets count: {} bytes: {} avr.count/sec: {} avr.bytes/sec: {}", sendLastPacketCount, sendLastPacketBytes, float(sendLastPacketCount)/minTime, float(sendLastPacketBytes)/minTime);

        lastTime = cur_time;
        sendLastPacketCount = 1;
        sendLastPacketBytes = packet->wpos();               // wpos is real written size
    }
#endif                                                      // !TRINITY_DEBUG

    sScriptMgr->OnPacketSend(this, *packet);

    TC_LOG_TRACE("network.opcode", "S->C: {} {}", GetPlayerInfo(), GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())));
    m_Socket[conIdx]->SendPacket(*packet);
}

/// Add an incoming packet to the queue
void WorldSession::QueuePacket(WorldPacket* new_packet)
{
    _recvQueue.add(new_packet);
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnexpectedOpcode(WorldPacket* packet, char const* status, const char *reason)
{
    TC_LOG_ERROR("network.opcode", "Received unexpected opcode {} Status: {} Reason: {} from {}",
        GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())), status, reason, GetPlayerInfo());
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnprocessedTail(WorldPacket const* packet)
{
    if (!sLog->ShouldLog("network.opcode", LOG_LEVEL_TRACE) || packet->rpos() >= packet->wpos())
        return;

    TC_LOG_TRACE("network.opcode", "Unprocessed tail data (read stop at {} from {}) Opcode {} from {}",
        uint32(packet->rpos()), uint32(packet->wpos()), GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())), GetPlayerInfo());
    packet->print_storage();
}

/// Update the WorldSession (triggered by World update)
bool WorldSession::Update(uint32 diff, PacketFilter& updater)
{
    ///- Before we process anything:
    /// If necessary, kick the player because the client didn't send anything for too long
    /// (or they've been idling in character select)
    if (IsConnectionIdle() && !HasPermission(rbac::RBAC_PERM_IGNORE_IDLE_CONNECTION))
        m_Socket[CONNECTION_TYPE_REALM]->CloseSocket();

    ///- Retrieve packets from the receive queue and call the appropriate handlers
    /// not process packets if socket already closed
    WorldPacket* packet = nullptr;
    //! Delete packet after processing by default
    bool deletePacket = true;
    std::vector<WorldPacket*> requeuePackets;
    uint32 processedPackets = 0;
    time_t currentTime = GameTime::GetGameTime();

    constexpr uint32 MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE = 100;

    while (m_Socket[CONNECTION_TYPE_REALM] && _recvQueue.next(packet, updater))
    {
        OpcodeClient opcode = static_cast<OpcodeClient>(packet->GetOpcode());
        ClientOpcodeHandler const* opHandle = opcodeTable[opcode];
        TC_METRIC_DETAILED_TIMER("worldsession_update_opcode_time", TC_METRIC_TAG("opcode", opHandle->Name));

        try
        {
            switch (opHandle->Status)
            {
                case STATUS_LOGGEDIN:
                    if (!_player)
                    {
                        // skip STATUS_LOGGEDIN opcode unexpected errors if player logout sometime ago - this can be network lag delayed packets
                        //! If player didn't log out a while ago, it means packets are being sent while the server does not recognize
                        //! the client to be in world yet. We will re-add the packets to the bottom of the queue and process them later.
                        if (!m_playerRecentlyLogout)
                        {
                            requeuePackets.push_back(packet);
                            deletePacket = false;
                            TC_LOG_DEBUG("network", "Re-enqueueing packet with opcode {} with with status STATUS_LOGGEDIN. "
                                "Player is currently not in world yet.", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())));
                        }
                    }
                    else if (_player->IsInWorld())
                    {
                        if(AntiDOS.EvaluateOpcode(*packet, currentTime))
                        {
                            sScriptMgr->OnPacketReceive(this, *packet);
                            opHandle->Call(this, *packet);
                        }
                        else
                            processedPackets = MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE;   // break out of packet processing loop
                    }
                    // lag can cause STATUS_LOGGEDIN opcodes to arrive after the player started a transfer
                    break;
                case STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT:
                    if (!_player && !m_playerRecentlyLogout && !m_playerLogout) // There's a short delay between _player = null and m_playerRecentlyLogout = true during logout
                        LogUnexpectedOpcode(packet, "STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT",
                            "the player has not logged in yet and not recently logout");
                    else if (AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        // not expected _player or must checked in packet hanlder
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                    }
                    else
                        processedPackets = MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE;   // break out of packet processing loop
                    break;
                case STATUS_TRANSFER:
                    if (!_player)
                        LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player has not logged in yet");
                    else if (_player->IsInWorld())
                        LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player is still in world");
                    else if (AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                    }
                    else
                        processedPackets = MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE;   // break out of packet processing loop
                    break;
                case STATUS_AUTHED:
                    // prevent cheating with skip queue wait
                    if (m_inQueue)
                    {
                        LogUnexpectedOpcode(packet, "STATUS_AUTHED", "the player not pass queue yet");
                        break;
                    }

                    // some auth opcodes can be recieved before STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT opcodes
                    // however when we recieve CMSG_CHAR_ENUM we are surely no longer during the logout process.
                    if (packet->GetOpcode() == CMSG_ENUM_CHARACTERS)
                        m_playerRecentlyLogout = false;

                    if (AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                    }
                    else
                        processedPackets = MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE;   // break out of packet processing loop
                    break;
                case STATUS_NEVER:
                    TC_LOG_ERROR("network.opcode", "Received not allowed opcode {} from {}", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode()))
                        , GetPlayerInfo());
                    break;
                case STATUS_UNHANDLED:
                    TC_LOG_ERROR("network.opcode", "Received not handled opcode {} from {}", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode()))
                        , GetPlayerInfo());
                    break;
            }
        }
        catch (WorldPackets::InvalidHyperlinkException const& ihe)
        {
            TC_LOG_ERROR("network", "{} sent {} with an invalid link:\n{}", GetPlayerInfo(),
                GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())), ihe.GetInvalidValue());

            if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_KICK))
                KickPlayer("WorldSession::Update Invalid chat link");
        }
        catch (WorldPackets::IllegalHyperlinkException const& ihe)
        {
            TC_LOG_ERROR("network", "{} sent {} which illegally contained a hyperlink:\n{}", GetPlayerInfo(),
                GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())), ihe.GetInvalidValue());

            if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_KICK))
                KickPlayer("WorldSession::Update Illegal chat link");
        }
        catch (WorldPackets::PacketArrayMaxCapacityException const& pamce)
        {
            TC_LOG_ERROR("network", "PacketArrayMaxCapacityException: {} while parsing {} from {}.",
                pamce.what(), GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())), GetPlayerInfo());
        }
        catch (ByteBufferException const&)
        {
            TC_LOG_ERROR("network", "WorldSession::Update ByteBufferException occured while parsing a packet (opcode: {}) from client {}, accountid={}. Skipped packet.",
                    packet->GetOpcode(), GetRemoteAddress(), GetAccountId());
            packet->hexlike();
        }

        if (deletePacket)
            delete packet;

        deletePacket = true;

        processedPackets++;

        //process only a max amout of packets in 1 Update() call.
        //Any leftover will be processed in next update
        if (processedPackets > MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE)
            break;
    }

    TC_METRIC_VALUE("processed_packets", processedPackets);

    _recvQueue.readd(requeuePackets.begin(), requeuePackets.end());

    if (!updater.ProcessUnsafe()) // <=> updater is of type MapSessionFilter
    {
        // Send time sync packet every 10s.
        if (_timeSyncTimer > 0)
        {
            if (diff >= _timeSyncTimer)
                SendTimeSync();
            else
                _timeSyncTimer -= diff;
        }
    }

    ProcessQueryCallbacks();

    //check if we are safe to proceed with logout
    //logout procedure should happen only in World::UpdateSessions() method!!!
    if (updater.ProcessUnsafe())
    {
        if (m_Socket[CONNECTION_TYPE_REALM] && m_Socket[CONNECTION_TYPE_REALM]->IsOpen() && _warden)
            _warden->Update(diff);

        ///- If necessary, log the player out
        if (ShouldLogOut(currentTime) && m_playerLoading.IsEmpty())
            LogoutPlayer(true);

        ///- Cleanup socket pointer if need
        if ((m_Socket[CONNECTION_TYPE_REALM] && !m_Socket[CONNECTION_TYPE_REALM]->IsOpen()) ||
            (m_Socket[CONNECTION_TYPE_INSTANCE] && !m_Socket[CONNECTION_TYPE_INSTANCE]->IsOpen()))
        {
            if (GetPlayer() && _warden)
                _warden->Update(diff);

            expireTime -= expireTime > diff ? diff : expireTime;
            if (expireTime < diff || forceExit || !GetPlayer())
            {
                if (m_Socket[CONNECTION_TYPE_REALM])
                {
                    m_Socket[CONNECTION_TYPE_REALM]->CloseSocket();
                    m_Socket[CONNECTION_TYPE_REALM].reset();
                }
                if (m_Socket[CONNECTION_TYPE_INSTANCE])
                {
                    m_Socket[CONNECTION_TYPE_INSTANCE]->CloseSocket();
                    m_Socket[CONNECTION_TYPE_INSTANCE].reset();
                }
            }
        }

        if (!m_Socket[CONNECTION_TYPE_REALM])
            return false;                                       //Will remove this session from the world session map
    }

    return true;
}

/// %Log the player out
void WorldSession::LogoutPlayer(bool save)
{
    // finish pending transfers before starting the logout
    while (_player && _player->IsBeingTeleportedFar())
        HandleMoveWorldportAck();

    m_playerLogout = true;
    m_playerSave = save;

    if (_player)
    {
        if (!_player->GetLootGUID().IsEmpty())
            DoLootReleaseAll();

        ///- If the player just died before logging out, make him appear as a ghost
        if (_player->GetDeathTimer())
        {
            _player->CombatStop();
            _player->BuildPlayerRepop();
            _player->RepopAtGraveyard();
        }
        else if (_player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
        {
            // this will kill character by SPELL_AURA_SPIRIT_OF_REDEMPTION
            _player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);
            _player->KillPlayer();
            _player->BuildPlayerRepop();
            _player->RepopAtGraveyard();
        }
        else if (_player->HasPendingBind())
        {
            _player->RepopAtGraveyard();
            _player->SetPendingBind(0, 0);
        }

        //drop a flag if player is carrying it
        if (Battleground* bg = _player->GetBattleground())
            bg->EventPlayerLoggedOut(_player);

        ///- Teleport to home if the player is in an invalid instance
        if (!_player->m_InstanceValid && !_player->IsGameMaster())
            _player->TeleportTo(_player->m_homebind);

        sOutdoorPvPMgr->HandlePlayerLeaveZone(_player, _player->GetZoneId());

        for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        {
            BattlegroundQueueTypeId bgQueueTypeId = _player->GetBattlegroundQueueTypeId(i);
            if (bgQueueTypeId != BATTLEGROUND_QUEUE_NONE)
            {
                _player->RemoveBattlegroundQueueId(bgQueueTypeId);
                BattlegroundQueue& queue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
                queue.RemovePlayer(_player->GetGUID(), true);
            }
        }

        // Repop at Graveyard or other player far teleport will prevent saving player because of not present map
        // Teleport player immediately for correct player save
        while (_player->IsBeingTeleportedFar())
            HandleMoveWorldportAck();

        ///- If the player is in a guild, update the guild roster and broadcast a logout message to other guild members
        if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
            guild->HandleMemberLogout(this);

        ///- Remove pet
        _player->RemovePet(nullptr, PET_SAVE_AS_CURRENT, true);

        ///- Release battle pet journal lock
        if (_battlePetMgr->HasJournalLock())
            _battlePetMgr->ToggleJournalLock(false);

        ///- Clear whisper whitelist
        _player->ClearWhisperWhiteList();

        _player->FailQuestsWithFlag(QUEST_FLAGS_FAIL_ON_LOGOUT);

        ///- empty buyback items and save the player in the database
        // some save parts only correctly work in case player present in map/player_lists (pets, etc)
        if (save)
        {
            uint32 eslot;
            for (int j = BUYBACK_SLOT_START; j < BUYBACK_SLOT_END; ++j)
            {
                eslot = j - BUYBACK_SLOT_START;
                _player->SetInvSlot(j, ObjectGuid::Empty);
                _player->SetBuybackPrice(eslot, 0);
                _player->SetBuybackTimestamp(eslot, 0);
            }
            _player->SaveToDB();
        }

        ///- Leave all channels before player delete...
        _player->CleanupChannels();

        ///- If the player is in a group (or invited), remove him. If the group if then only 1 person, disband the group.
        _player->UninviteFromGroup();

        //! Send update to group and reset stored max enchanting level
        if (Group* group = _player->GetGroup())
        {
            group->SendUpdate();
            if (group->GetLeaderGUID() == _player->GetGUID())
                group->StartLeaderOfflineTimer();
        }

        //! Broadcast a logout message to the player's friends
        sSocialMgr->SendFriendStatus(_player, FRIEND_OFFLINE, _player->GetGUID(), true);
        _player->RemoveSocial();

        //! Call script hook before deletion
        sScriptMgr->OnPlayerLogout(_player);

        TC_METRIC_EVENT("player_events", "Logout", _player->GetName());

        //! Remove the player from the world
        // the player may not be in the world when logging out
        // e.g if he got disconnected during a transfer to another map
        // calls to GetMap in this case may cause crashes
        _player->SetDestroyedObject(true);
        _player->CleanupsBeforeDelete();
        TC_LOG_INFO("entities.player.character", "Account: {} (IP: {}) Logout Character:[{}] {} Level: {}, XP: {}/{} ({} left)",
            GetAccountId(), GetRemoteAddress(), _player->GetName(), _player->GetGUID().ToString(), _player->GetLevel(),
            _player->GetXP(), _player->GetXPForNextLevel(), std::max(0, (int32)_player->GetXPForNextLevel() - (int32)_player->GetXP()));

        if (Map* _map = _player->FindMap())
            _map->RemovePlayerFromMap(_player, true);

        SetPlayer(nullptr); //! Pointer already deleted during RemovePlayerFromMap

        //! Send the 'logout complete' packet to the client
        //! Client will respond by sending 3x CMSG_CANCEL_TRADE, which we currently dont handle
        SendPacket(WorldPackets::Character::LogoutComplete().Write());
        TC_LOG_DEBUG("network", "SESSION: Sent SMSG_LOGOUT_COMPLETE Message");

        //! Since each account can only have one online character at any given time, ensure all characters for active account are marked as offline
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ACCOUNT_ONLINE);
        stmt->setUInt32(0, GetAccountId());
        CharacterDatabase.Execute(stmt);
    }

    if (m_Socket[CONNECTION_TYPE_INSTANCE])
    {
        m_Socket[CONNECTION_TYPE_INSTANCE]->CloseSocket();
        m_Socket[CONNECTION_TYPE_INSTANCE].reset();
    }

    m_playerLogout = false;
    m_playerSave = false;
    m_playerRecentlyLogout = true;
    SetLogoutStartTime(0);
}

/// Kick a player out of the World
void WorldSession::KickPlayer(std::string const& reason)
{
    TC_LOG_INFO("network.kick", "Account: {} Character: '{}' {} kicked with reason: {}", GetAccountId(), _player ? _player->GetName() : "<none>",
        _player ? _player->GetGUID().ToString() : "", reason);

    for (uint8 i = 0; i < 2; ++i)
    {
        if (m_Socket[i])
        {
            m_Socket[i]->CloseSocket();
            forceExit = true;
        }
    }
}

bool WorldSession::ValidateHyperlinksAndMaybeKick(std::string const& str)
{
    if (Trinity::Hyperlinks::CheckAllLinks(str))
        return true;

    TC_LOG_ERROR("network", "Player {}{} sent a message with an invalid link:\n{}", GetPlayer()->GetName(),
        GetPlayer()->GetGUID().ToString(), str);

    if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_KICK))
        KickPlayer("WorldSession::ValidateHyperlinksAndMaybeKick Invalid chat link");

    return false;
}

bool WorldSession::DisallowHyperlinksAndMaybeKick(std::string const& str)
{
    if (str.find('|') == std::string::npos)
        return true;

    TC_LOG_ERROR("network", "Player {} {} sent a message which illegally contained a hyperlink:\n{}", GetPlayer()->GetName(),
                 GetPlayer()->GetGUID().ToString(), str);

    if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_KICK))
        KickPlayer("WorldSession::DisallowHyperlinksAndMaybeKick Illegal chat link");

    return false;
}

void WorldSession::SendNotification(char const* format, ...)
{
    if (format)
    {
        va_list ap;
        char szStr[1024];
        szStr[0] = '\0';
        va_start(ap, format);
        vsnprintf(szStr, 1024, format, ap);
        va_end(ap);

        SendPacket(WorldPackets::Chat::PrintNotification(szStr).Write());
    }
}

void WorldSession::SendNotification(uint32 stringId, ...)
{
    char const* format = GetTrinityString(stringId);
    if (format)
    {
        va_list ap;
        char szStr[1024];
        szStr[0] = '\0';
        va_start(ap, stringId);
        vsnprintf(szStr, 1024, format, ap);
        va_end(ap);

        SendPacket(WorldPackets::Chat::PrintNotification(szStr).Write());
    }
}

bool WorldSession::CanSpeak() const
{
    return m_muteTime <= GameTime::GetGameTime();
}

char const* WorldSession::GetTrinityString(uint32 entry) const
{
    return sObjectMgr->GetTrinityString(entry, GetSessionDbLocaleIndex());
}

void WorldSession::ResetTimeOutTime(bool onlyActive)
{
    if (GetPlayer())
        m_timeOutTime = GameTime::GetGameTime() + time_t(sWorld->getIntConfig(CONFIG_SOCKET_TIMEOUTTIME_ACTIVE));
    else if (!onlyActive)
        m_timeOutTime = GameTime::GetGameTime() + time_t(sWorld->getIntConfig(CONFIG_SOCKET_TIMEOUTTIME));
}

bool WorldSession::IsConnectionIdle() const
{
    return m_timeOutTime < GameTime::GetGameTime() && !m_inQueue;
}

void WorldSession::Handle_NULL(WorldPackets::Null& null)
{
    TC_LOG_ERROR("network.opcode", "Received unhandled opcode {} from {}", GetOpcodeNameForLogging(null.GetOpcode()), GetPlayerInfo());
}

void WorldSession::Handle_EarlyProccess(WorldPackets::Null& null)
{
    TC_LOG_ERROR("network.opcode", "Received opcode {} that must be processed in WorldSocket::ReadDataHandler from {}"
        , GetOpcodeNameForLogging(null.GetOpcode()), GetPlayerInfo());
}

void WorldSession::SendConnectToInstance(WorldPackets::Auth::ConnectToSerial serial)
{
    boost::system::error_code ignored_error;
    boost::asio::ip::address instanceAddress;
    if (std::shared_ptr<Realm const> currentRealm = sRealmList->GetCurrentRealm())
        instanceAddress = currentRealm->GetAddressForClient(Trinity::Net::make_address(GetRemoteAddress(), ignored_error));

    _instanceConnectKey.Fields.AccountId = GetAccountId();
    _instanceConnectKey.Fields.ConnectionType = CONNECTION_TYPE_INSTANCE;
    _instanceConnectKey.Fields.Key = urand(0, 0x7FFFFFFF);

    WorldPackets::Auth::ConnectTo connectTo;
    connectTo.Key = _instanceConnectKey.Raw;
    connectTo.Serial = serial;
    connectTo.Payload.Port = sWorld->getIntConfig(CONFIG_PORT_INSTANCE);
    if (instanceAddress.is_v4())
    {
        memcpy(connectTo.Payload.Where.Address.V4.data(), instanceAddress.to_v4().to_bytes().data(), 4);
        connectTo.Payload.Where.Type = WorldPackets::Auth::ConnectTo::IPv4;
    }
    else
    {
        memcpy(connectTo.Payload.Where.Address.V6.data(), instanceAddress.to_v6().to_bytes().data(), 16);
        connectTo.Payload.Where.Type = WorldPackets::Auth::ConnectTo::IPv6;
    }
    connectTo.Con = CONNECTION_TYPE_INSTANCE;

    SendPacket(connectTo.Write());
}

void WorldSession::LoadAccountData(PreparedQueryResult result, uint32 mask)
{
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        if (mask & (1 << i))
            _accountData[i] = AccountData();

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 type = fields[0].GetUInt8();
        if (type >= NUM_ACCOUNT_DATA_TYPES)
        {
            TC_LOG_ERROR("misc", "Table `{}` have invalid account data type ({}), ignore.",
                mask == GLOBAL_CACHE_MASK ? "account_data" : "character_account_data", type);
            continue;
        }

        if ((mask & (1 << type)) == 0)
        {
            TC_LOG_ERROR("misc", "Table `{}` have non appropriate for table account data type ({}), ignore.",
                mask == GLOBAL_CACHE_MASK ? "account_data" : "character_account_data", type);
            continue;
        }

        _accountData[type].Time = fields[1].GetInt64();
        _accountData[type].Data = fields[2].GetString();
    }
    while (result->NextRow());
}

void WorldSession::SetAccountData(AccountDataType type, time_t time, std::string const& data)
{
    if ((1 << type) & GLOBAL_CACHE_MASK)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_ACCOUNT_DATA);
        stmt->setUInt32(0, GetAccountId());
        stmt->setUInt8(1, type);
        stmt->setInt64(2, time);
        stmt->setString(3, data);
        CharacterDatabase.Execute(stmt);
    }
    else
    {
        // _player can be NULL and packet received after logout but m_GUID still store correct guid
        if (!m_GUIDLow)
            return;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_PLAYER_ACCOUNT_DATA);
        stmt->setUInt64(0, m_GUIDLow);
        stmt->setUInt8(1, type);
        stmt->setInt64(2, time);
        stmt->setString(3, data);
        CharacterDatabase.Execute(stmt);
    }

    _accountData[type].Time = time;
    _accountData[type].Data = data;
}

void WorldSession::SendAccountDataTimes(ObjectGuid playerGuid, uint32 mask)
{
    WorldPackets::ClientConfig::AccountDataTimes accountDataTimes;
    accountDataTimes.PlayerGuid = playerGuid;
    accountDataTimes.ServerTime = GameTime::GetSystemTime();
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        if (mask & (1 << i))
            accountDataTimes.AccountTimes[i] = GetAccountData(AccountDataType(i))->Time;

    SendPacket(accountDataTimes.Write());
}

void WorldSession::LoadTutorialsData(PreparedQueryResult result)
{
    memset(_tutorials, 0, sizeof(uint32) * MAX_ACCOUNT_TUTORIAL_VALUES);

    if (result)
    {
        for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
            _tutorials[i] = (*result)[i].GetUInt32();
        _tutorialsChanged |= TUTORIALS_FLAG_LOADED_FROM_DB;
    }

    _tutorialsChanged &= ~TUTORIALS_FLAG_CHANGED;
}

void WorldSession::SendTutorialsData()
{
    WorldPackets::Misc::TutorialFlags packet;
    memcpy(packet.TutorialData, _tutorials, sizeof(_tutorials));
    SendPacket(packet.Write());
}

void WorldSession::SaveTutorialsData(CharacterDatabaseTransaction trans)
{
    if (!(_tutorialsChanged & TUTORIALS_FLAG_CHANGED))
        return;

    bool const hasTutorialsInDB = (_tutorialsChanged & TUTORIALS_FLAG_LOADED_FROM_DB) != 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(hasTutorialsInDB ? CHAR_UPD_TUTORIALS : CHAR_INS_TUTORIALS);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        stmt->setUInt32(i, _tutorials[i]);
    stmt->setUInt32(MAX_ACCOUNT_TUTORIAL_VALUES, GetAccountId());
    trans->Append(stmt);

    // now has, set flag so next save uses update query
    if (!hasTutorialsInDB)
        _tutorialsChanged |= TUTORIALS_FLAG_LOADED_FROM_DB;

    _tutorialsChanged &= ~TUTORIALS_FLAG_CHANGED;
}

bool WorldSession::IsAddonRegistered(std::string_view prefix) const
{
    if (!_filterAddonMessages) // if we have hit the softcap (64) nothing should be filtered
        return true;

    if (_registeredAddonPrefixes.empty())
        return false;

    std::vector<std::string>::const_iterator itr = std::find(_registeredAddonPrefixes.begin(), _registeredAddonPrefixes.end(), prefix);
    return itr != _registeredAddonPrefixes.end();
}

void WorldSession::HandleUnregisterAllAddonPrefixesOpcode(WorldPackets::Chat::ChatUnregisterAllAddonPrefixes& /*packet*/) // empty packet
{
    _registeredAddonPrefixes.clear();
}

void WorldSession::HandleAddonRegisteredPrefixesOpcode(WorldPackets::Chat::ChatRegisterAddonPrefixes& packet)
{
    // This is always sent after CMSG_CHAT_UNREGISTER_ALL_ADDON_PREFIXES
    _registeredAddonPrefixes.insert(_registeredAddonPrefixes.end(), packet.Prefixes.begin(), packet.Prefixes.end());
    if (_registeredAddonPrefixes.size() > WorldPackets::Chat::ChatRegisterAddonPrefixes::MAX_PREFIXES)
    {
        _filterAddonMessages = false;
        return;
    }

    _filterAddonMessages = true;
}

void WorldSession::SetPlayer(Player* player)
{
    _player = player;

    // set m_GUID that can be used while player loggined and later until m_playerRecentlyLogout not reset
    if (_player)
        m_GUIDLow = _player->GetGUID().GetCounter();
}

void WorldSession::ProcessQueryCallbacks()
{
    _queryProcessor.ProcessReadyCallbacks();
    _transactionCallbacks.ProcessReadyCallbacks();
    _queryHolderProcessor.ProcessReadyCallbacks();
}

TransactionCallback& WorldSession::AddTransactionCallback(TransactionCallback&& callback)
{
    return _transactionCallbacks.AddCallback(std::move(callback));
}

SQLQueryHolderCallback& WorldSession::AddQueryHolderCallback(SQLQueryHolderCallback&& callback)
{
    return _queryHolderProcessor.AddCallback(std::move(callback));
}

bool WorldSession::CanAccessAlliedRaces() const
{
    return GetAccountExpansion() >= EXPANSION_BATTLE_FOR_AZEROTH;
}

void WorldSession::InitWarden(SessionKey const& k)
{
    if (_os == "Win")
    {
        _warden = std::make_unique<WardenWin>();
        _warden->Init(this, k);
    }
    else if (_os == "Wn64")
    {
        // Not implemented
    }
    else if (_os == "Mc64")
    {
        // Not implemented
    }
}

void WorldSession::LoadPermissions()
{
    uint32 id = GetAccountId();
    uint8 secLevel = GetSecurity();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: {}, Name: {}, realmId: {}, secLevel: {}]",
        id, _accountName, sRealmList->GetCurrentRealmId().Realm, secLevel);

    _RBACData = new rbac::RBACData(id, _accountName, sRealmList->GetCurrentRealmId().Realm, secLevel);
    _RBACData->LoadFromDB();
}

QueryCallback WorldSession::LoadPermissionsAsync()
{
    uint32 id = GetAccountId();
    uint8 secLevel = GetSecurity();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: {}, Name: {}, realmId: {}, secLevel: {}]",
        id, _accountName, sRealmList->GetCurrentRealmId().Realm, secLevel);

    _RBACData = new rbac::RBACData(id, _accountName, sRealmList->GetCurrentRealmId().Realm, secLevel);
    return _RBACData->LoadFromDBAsync();
}

class AccountInfoQueryHolderPerRealm : public CharacterDatabaseQueryHolder
{
public:
    enum
    {
        GLOBAL_ACCOUNT_DATA = 0,
        TUTORIALS,

        MAX_QUERIES
    };

    AccountInfoQueryHolderPerRealm() { SetSize(MAX_QUERIES); }

    bool Initialize(uint32 accountId, uint32 /*battlenetAccountId*/)
    {
        bool ok = true;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_DATA);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(GLOBAL_ACCOUNT_DATA, stmt) && ok;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_TUTORIALS);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(TUTORIALS, stmt) && ok;

        return ok;
    }
};

class AccountInfoQueryHolder : public LoginDatabaseQueryHolder
{
public:
    enum
    {
        GLOBAL_ACCOUNT_TOYS = 0,
        BATTLE_PETS,
        BATTLE_PET_SLOTS,
        GLOBAL_ACCOUNT_HEIRLOOMS,
        GLOBAL_REALM_CHARACTER_COUNTS,
        MOUNTS,
        ITEM_APPEARANCES,
        ITEM_FAVORITE_APPEARANCES,
        TRANSMOG_ILLUSIONS,

        MAX_QUERIES
    };

    AccountInfoQueryHolder() { SetSize(MAX_QUERIES); }

    bool Initialize(uint32 accountId, uint32 battlenetAccountId)
    {
        bool ok = true;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_TOYS);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(GLOBAL_ACCOUNT_TOYS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BATTLE_PETS);
        stmt->setUInt32(0, battlenetAccountId);
        stmt->setInt32(1, sRealmList->GetCurrentRealmId().Realm);
        ok = SetPreparedQuery(BATTLE_PETS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BATTLE_PET_SLOTS);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(BATTLE_PET_SLOTS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_HEIRLOOMS);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(GLOBAL_ACCOUNT_HEIRLOOMS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_MOUNTS);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(MOUNTS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_ACCOUNT_ID);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(GLOBAL_REALM_CHARACTER_COUNTS, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ITEM_APPEARANCES);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(ITEM_APPEARANCES, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ITEM_FAVORITE_APPEARANCES);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(ITEM_FAVORITE_APPEARANCES, stmt) && ok;

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_TRANSMOG_ILLUSIONS);
        stmt->setUInt32(0, battlenetAccountId);
        ok = SetPreparedQuery(TRANSMOG_ILLUSIONS, stmt) && ok;

        return ok;
    }
};

void WorldSession::InitializeSession()
{
    std::shared_ptr<AccountInfoQueryHolderPerRealm> realmHolder = std::make_shared<AccountInfoQueryHolderPerRealm>();
    if (!realmHolder->Initialize(GetAccountId(), GetBattlenetAccountId()))
    {
        SendAuthResponse(ERROR_INTERNAL, false);
        return;
    }

    std::shared_ptr<AccountInfoQueryHolder> holder = std::make_shared<AccountInfoQueryHolder>();
    if (!holder->Initialize(GetAccountId(), GetBattlenetAccountId()))
    {
        SendAuthResponse(ERROR_INTERNAL, false);
        return;
    }

    struct ForkJoinState
    {
        std::shared_ptr<AccountInfoQueryHolderPerRealm> Character;
        std::shared_ptr<AccountInfoQueryHolder> Login;
    };

    std::shared_ptr<ForkJoinState> state = std::make_shared<ForkJoinState>();

    AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(realmHolder)).AfterComplete([this, state, realmHolder](SQLQueryHolderBase const& /*result*/)
    {
        state->Character = realmHolder;
        if (state->Login && state->Character)
            InitializeSessionCallback(*state->Login, *state->Character);
    });

    AddQueryHolderCallback(LoginDatabase.DelayQueryHolder(holder)).AfterComplete([this, state, holder](SQLQueryHolderBase const& /*result*/)
    {
        state->Login = holder;
        if (state->Login && state->Character)
            InitializeSessionCallback(*state->Login, *state->Character);
    });
}

void WorldSession::InitializeSessionCallback(LoginDatabaseQueryHolder const& holder, CharacterDatabaseQueryHolder const& realmHolder)
{
    LoadAccountData(realmHolder.GetPreparedResult(AccountInfoQueryHolderPerRealm::GLOBAL_ACCOUNT_DATA), GLOBAL_CACHE_MASK);
    LoadTutorialsData(realmHolder.GetPreparedResult(AccountInfoQueryHolderPerRealm::TUTORIALS));
    _collectionMgr->LoadAccountToys(holder.GetPreparedResult(AccountInfoQueryHolder::GLOBAL_ACCOUNT_TOYS));
    _collectionMgr->LoadAccountHeirlooms(holder.GetPreparedResult(AccountInfoQueryHolder::GLOBAL_ACCOUNT_HEIRLOOMS));
    _collectionMgr->LoadAccountMounts(holder.GetPreparedResult(AccountInfoQueryHolder::MOUNTS));
    _collectionMgr->LoadAccountItemAppearances(holder.GetPreparedResult(AccountInfoQueryHolder::ITEM_APPEARANCES), holder.GetPreparedResult(AccountInfoQueryHolder::ITEM_FAVORITE_APPEARANCES));
    _collectionMgr->LoadAccountTransmogIllusions(holder.GetPreparedResult(AccountInfoQueryHolder::TRANSMOG_ILLUSIONS));

    if (!m_inQueue)
        SendAuthResponse(ERROR_OK, false);
    else
        SendAuthWaitQueue(0);

    SetInQueue(false);
    ResetTimeOutTime(false);

    SendSetTimeZoneInformation();
    SendFeatureSystemStatusGlueScreen();
    SendClientCacheVersion(sWorld->getIntConfig(CONFIG_CLIENTCACHE_VERSION));
    SendAvailableHotfixes();
    SendAccountDataTimes(ObjectGuid::Empty, GLOBAL_CACHE_MASK);
    SendTutorialsData();

    if (PreparedQueryResult characterCountsResult = holder.GetPreparedResult(AccountInfoQueryHolder::GLOBAL_REALM_CHARACTER_COUNTS))
    {
        do
        {
            Field* fields = characterCountsResult->Fetch();
            _realmCharacterCounts[Battlenet::RealmHandle{ fields[3].GetUInt8(), fields[4].GetUInt8(), fields[2].GetUInt32() }.GetAddress()] = fields[1].GetUInt8();

        } while (characterCountsResult->NextRow());
    }

    WorldPackets::Battlenet::ConnectionStatus bnetConnected;
    bnetConnected.State = 1;
    SendPacket(bnetConnected.Write());

    _battlePetMgr->LoadFromDB(holder.GetPreparedResult(AccountInfoQueryHolder::BATTLE_PETS),
                              holder.GetPreparedResult(AccountInfoQueryHolder::BATTLE_PET_SLOTS));
}

rbac::RBACData* WorldSession::GetRBACData()
{
    return _RBACData;
}

bool WorldSession::HasPermission(uint32 permission)
{
    if (!_RBACData)
        LoadPermissions();

    bool hasPermission = _RBACData->HasPermission(permission);
    TC_LOG_DEBUG("rbac", "WorldSession::HasPermission [AccountId: {}, Name: {}, realmId: {}]",
                   _RBACData->GetId(), _RBACData->GetName(), sRealmList->GetCurrentRealmId().Realm);

    return hasPermission;
}

void WorldSession::InvalidateRBACData()
{
    TC_LOG_DEBUG("rbac", "WorldSession::Invalidaterbac::RBACData [AccountId: {}, Name: {}, realmId: {}]",
                   _RBACData->GetId(), _RBACData->GetName(), sRealmList->GetCurrentRealmId().Realm);
    delete _RBACData;
    _RBACData = nullptr;
}

bool WorldSession::DosProtection::EvaluateOpcode(WorldPacket& p, time_t time) const
{
    uint32 maxPacketCounterAllowed = GetMaxPacketCounterAllowed(p.GetOpcode());

    // Return true if there no limit for the opcode
    if (!maxPacketCounterAllowed)
        return true;

    PacketCounter& packetCounter = _PacketThrottlingMap[p.GetOpcode()];
    if (packetCounter.lastReceiveTime != time)
    {
        packetCounter.lastReceiveTime = time;
        packetCounter.amountCounter = 0;
    }

    // Check if player is flooding some packets
    if (++packetCounter.amountCounter <= maxPacketCounterAllowed)
        return true;

    TC_LOG_WARN("network", "AntiDOS: Account {}, IP: {}, Ping: {}, Character: {}, flooding packet (opc: {} (0x{:X}), count: {})",
        Session->GetAccountId(), Session->GetRemoteAddress(), Session->GetLatency(), Session->GetPlayerName(),
        opcodeTable[static_cast<OpcodeClient>(p.GetOpcode())]->Name, p.GetOpcode(), packetCounter.amountCounter);

    switch (_policy)
    {
        case POLICY_LOG:
            return true;
        case POLICY_KICK:
        {
            TC_LOG_WARN("network", "AntiDOS: Player kicked!");
            Session->KickPlayer("WorldSession::DosProtection::EvaluateOpcode AntiDOS");
            return false;
        }
        case POLICY_BAN:
        {
            BanMode bm = (BanMode)sWorld->getIntConfig(CONFIG_PACKET_SPOOF_BANMODE);
            uint32 duration = sWorld->getIntConfig(CONFIG_PACKET_SPOOF_BANDURATION); // in seconds
            std::string nameOrIp = "";
            switch (bm)
            {
                case BAN_CHARACTER: // not supported, ban account
                case BAN_ACCOUNT: (void)sAccountMgr->GetName(Session->GetAccountId(), nameOrIp); break;
                case BAN_IP: nameOrIp = Session->GetRemoteAddress(); break;
            }
            sWorld->BanAccount(bm, nameOrIp, duration, "DOS (Packet Flooding/Spoofing", "Server: AutoDOS");
            TC_LOG_WARN("network", "AntiDOS: Player automatically banned for {} seconds.", duration);
            Session->KickPlayer("WorldSession::DosProtection::EvaluateOpcode AntiDOS");
            return false;
        }
        default: // invalid policy
            return true;
    }
}

uint32 WorldSession::DosProtection::GetMaxPacketCounterAllowed(uint16 opcode) const
{
    uint32 maxPacketCounterAllowed;
    switch (opcode)
    {
        // CPU usage sending 2000 packets/second on a 3.70 GHz 4 cores on Win x64
        //                                              [% CPU mysqld]   [%CPU worldserver RelWithDebInfo]
        case CMSG_PLAYER_LOGIN:                         //   0               0.5
        case CMSG_QUERY_PLAYER_NAMES:                   //   0               1
        case CMSG_QUERY_PET_NAME:                       //   0               1
        case CMSG_QUERY_NPC_TEXT:                       //   0               1
        case CMSG_ATTACK_STOP:                          //   0               1
        case CMSG_QUERY_TIME:                           //   0               1
        case CMSG_QUERY_CORPSE_TRANSPORT:               //   0               1
        case CMSG_MOVE_TIME_SKIPPED:                    //   0               1
        case CMSG_QUERY_NEXT_MAIL_TIME:                 //   0               1
        case CMSG_SET_SHEATHED:                         //   0               1
        case CMSG_UPDATE_RAID_TARGET:                   //   0               1
        case CMSG_LOGOUT_REQUEST:                       //   0               1
        case CMSG_PET_RENAME:                           //   0               1
        case CMSG_QUEST_GIVER_REQUEST_REWARD:           //   0               1
        case CMSG_COMPLETE_CINEMATIC:                   //   0               1
        case CMSG_BANKER_ACTIVATE:                      //   0               1
        case CMSG_BUY_BANK_SLOT:                        //   0               1
        case CMSG_OPT_OUT_OF_LOOT:                      //   0               1
        case CMSG_DUEL_RESPONSE:                        //   0               1
        case CMSG_CALENDAR_COMPLAIN:                    //   0               1
        case CMSG_QUERY_QUEST_INFO:                     //   0               1.5
        case CMSG_QUERY_GAME_OBJECT:                    //   0               1.5
        case CMSG_QUERY_CREATURE:                       //   0               1.5
        case CMSG_QUEST_GIVER_STATUS_QUERY:             //   0               1.5
        case CMSG_QUERY_GUILD_INFO:                     //   0               1.5
        case CMSG_TAXI_NODE_STATUS_QUERY:               //   0               1.5
        case CMSG_TAXI_QUERY_AVAILABLE_NODES:           //   0               1.5
        case CMSG_QUEST_GIVER_QUERY_QUEST:              //   0               1.5
        case CMSG_QUERY_PAGE_TEXT:                      //   0               1.5
        case CMSG_GUILD_BANK_TEXT_QUERY:                //   0               1.5
        case CMSG_QUERY_CORPSE_LOCATION_FROM_CLIENT:    //   0               1.5
        case CMSG_MOVE_SET_FACING:                      //   0               1.5
        case CMSG_MOVE_SET_FACING_HEARTBEAT:            //   0               1.5
        case CMSG_MOVE_SET_PITCH:                       //   0               1.5
        case CMSG_REQUEST_PARTY_MEMBER_STATS:           //   0               1.5
        case CMSG_QUEST_GIVER_COMPLETE_QUEST:           //   0               1.5
        case CMSG_SET_ACTION_BUTTON:                    //   0               1.5
        case CMSG_SET_ACTION_BAR_TOGGLES:               // not profiled
        case CMSG_RESET_INSTANCES:                      //   0               1.5
        case CMSG_HEARTH_AND_RESURRECT:                 //   0               1.5
        case CMSG_TOGGLE_PVP:                           //   0               1.5
        case CMSG_PET_ABANDON:                          //   0               1.5
        case CMSG_ACTIVATE_TAXI:                        //   0               1.5
        case CMSG_SELF_RES:                             //   0               1.5
        case CMSG_UNLEARN_SKILL:                        //   0               1.5
        case CMSG_SAVE_EQUIPMENT_SET:                   //   0               1.5
        case CMSG_DELETE_EQUIPMENT_SET:                 //   0               1.5
        case CMSG_DISMISS_CRITTER:                      //   0               1.5
        case CMSG_REPOP_REQUEST:                        //   0               1.5
        case CMSG_PARTY_INVITE:                         //   0               1.5
        case CMSG_PARTY_INVITE_RESPONSE:                //   0               1.5
        case CMSG_PARTY_UNINVITE:                       //   0               1.5
        case CMSG_LEAVE_GROUP:                          //   0               1.5
        case CMSG_BATTLEMASTER_JOIN_ARENA:              //   0               1.5
        case CMSG_BATTLEFIELD_LEAVE:                    //   0               1.5
        case CMSG_GUILD_BANK_LOG_QUERY:                 //   0               2
        case CMSG_LOGOUT_CANCEL:                        //   0               2
        case CMSG_ALTER_APPEARANCE:                     //   0               2
        case CMSG_QUEST_CONFIRM_ACCEPT:                 //   0               2
        case CMSG_GUILD_EVENT_LOG_QUERY:                //   0               2.5
        case CMSG_QUEST_GIVER_STATUS_MULTIPLE_QUERY:    //   0               2.5
        case CMSG_BEGIN_TRADE:                          //   0               2.5
        case CMSG_INITIATE_TRADE:                       //   0               3
        case CMSG_CHAT_ADDON_MESSAGE:                   //   0               3.5
        case CMSG_CHAT_ADDON_MESSAGE_TARGETED:          //   0               3.5
        case CMSG_CHAT_MESSAGE_AFK:                     //   0               3.5
        case CMSG_CHAT_MESSAGE_CHANNEL:                 //   0               3.5
        case CMSG_CHAT_MESSAGE_DND:                     //   0               3.5
        case CMSG_CHAT_MESSAGE_EMOTE:                   //   0               3.5
        case CMSG_CHAT_MESSAGE_GUILD:                   //   0               3.5
        case CMSG_CHAT_MESSAGE_OFFICER:                 //   0               3.5
        case CMSG_CHAT_MESSAGE_PARTY:                   //   0               3.5
        case CMSG_CHAT_MESSAGE_RAID:                    //   0               3.5
        case CMSG_CHAT_MESSAGE_RAID_WARNING:            //   0               3.5
        case CMSG_CHAT_MESSAGE_SAY:                     //   0               3.5
        case CMSG_CHAT_MESSAGE_WHISPER:                 //   0               3.5
        case CMSG_CHAT_MESSAGE_YELL:                    //   0               3.5
        case CMSG_INSPECT:                              //   0               3.5
        case CMSG_AREA_SPIRIT_HEALER_QUERY:             // not profiled
        case CMSG_STAND_STATE_CHANGE:                   // not profiled
        case CMSG_RANDOM_ROLL:                          // not profiled
        case CMSG_TIME_SYNC_RESPONSE:                   // not profiled
        case CMSG_MOVE_FORCE_RUN_SPEED_CHANGE_ACK:      // not profiled
        case CMSG_MOVE_FORCE_SWIM_SPEED_CHANGE_ACK:     // not profiled
        case CMSG_MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:// not profiled
        case CMSG_MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK: // not profiled
        case CMSG_MOVE_FORCE_FLIGHT_SPEED_CHANGE_ACK:   // not profiled
        case CMSG_MOVE_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:// not profiled
        case CMSG_MOVE_FORCE_WALK_SPEED_CHANGE_ACK:     // not profiled
        case CMSG_MOVE_FORCE_TURN_RATE_CHANGE_ACK:      // not profiled
        case CMSG_MOVE_FORCE_PITCH_RATE_CHANGE_ACK:     // not profiled
        {
            // "0" is a magic number meaning there's no limit for the opcode.
            // All the opcodes above must cause little CPU usage and no sync/async database queries at all
            maxPacketCounterAllowed = 0;
            break;
        }

        case CMSG_QUEST_GIVER_ACCEPT_QUEST:             //   0               4
        case CMSG_QUEST_LOG_REMOVE_QUEST:               //   0               4
        case CMSG_QUEST_GIVER_CHOOSE_REWARD:            //   0               4
        case CMSG_SEND_CONTACT_LIST:                    //   0               5
        case CMSG_AUTOBANK_ITEM:                        //   0               6
        case CMSG_AUTOSTORE_BANK_ITEM:                  //   0               6
        case CMSG_WHO:                                  //   0               7
        case CMSG_RIDE_VEHICLE_INTERACT:                //   0               8
        case CMSG_MOVE_HEARTBEAT:
        {
            maxPacketCounterAllowed = 200;
            break;
        }

        case CMSG_GUILD_SET_MEMBER_NOTE:                //   1               2         1 async db query
        case CMSG_SET_CONTACT_NOTES:                    //   1               2.5       1 async db query
        case CMSG_CALENDAR_GET:                         //   0               1.5       medium upload bandwidth usage
        case CMSG_GUILD_BANK_QUERY_TAB:                 //   0               3.5       medium upload bandwidth usage
        case CMSG_QUERY_INSPECT_ACHIEVEMENTS:           //   0              13         high upload bandwidth usage
        case CMSG_GAME_OBJ_REPORT_USE:                  // not profiled
        case CMSG_GAME_OBJ_USE:                         // not profiled
        case CMSG_DECLINE_PETITION:                     // not profiled
        {
            maxPacketCounterAllowed = 50;
            break;
        }

        case CMSG_QUEST_POI_QUERY:                      //   0              25         very high upload bandwidth usage
        {
            maxPacketCounterAllowed = MAX_QUEST_LOG_SIZE;
            break;
        }

        case CMSG_SPELL_CLICK:                          // not profiled
        case CMSG_MOVE_DISMISS_VEHICLE:                 // not profiled
        {
            maxPacketCounterAllowed = 20;
            break;
        }

        case CMSG_SIGN_PETITION:                        //   9               4         2 sync 1 async db queries
        case CMSG_TURN_IN_PETITION:                     //   8               5.5       2 sync db query
        case CMSG_CHANGE_SUB_GROUP:                     //   6               5         1 sync 1 async db queries
        case CMSG_QUERY_PETITION:                       //   4               3.5       1 sync db query
        case CMSG_CHAR_CUSTOMIZE:                       //   5               5         1 sync db query
        case CMSG_CHAR_RACE_OR_FACTION_CHANGE:          //   5               5         1 sync db query
        case CMSG_CHAR_DELETE:                          //   4               4         1 sync db query
        case CMSG_DEL_FRIEND:                           //   7               5         1 async db query
        case CMSG_ADD_FRIEND:                           //   6               4         1 async db query
        case CMSG_CHARACTER_RENAME_REQUEST:             //   5               3         1 async db query
        case CMSG_BUG_REPORT:                           //   1               1         1 async db query
        case CMSG_SET_PARTY_LEADER:                     //   1               2         1 async db query
        case CMSG_CONVERT_RAID:                         //   1               5         1 async db query
        case CMSG_SET_ASSISTANT_LEADER:                 //   1               2         1 async db query
        case CMSG_MOVE_CHANGE_VEHICLE_SEATS:            // not profiled
        case CMSG_PETITION_BUY:                         // not profiled                1 sync 1 async db queries
        case CMSG_REQUEST_VEHICLE_PREV_SEAT:            // not profiled
        case CMSG_REQUEST_VEHICLE_NEXT_SEAT:            // not profiled
        case CMSG_REQUEST_VEHICLE_SWITCH_SEAT:          // not profiled
        case CMSG_REQUEST_VEHICLE_EXIT:                 // not profiled
        case CMSG_EJECT_PASSENGER:                      // not profiled
        case CMSG_ITEM_PURCHASE_REFUND:                 // not profiled
        case CMSG_SOCKET_GEMS:                          // not profiled
        case CMSG_WRAP_ITEM:                            // not profiled
        case CMSG_REPORT_PVP_PLAYER_AFK:                // not profiled
        {
            maxPacketCounterAllowed = 10;
            break;
        }

        case CMSG_CREATE_CHARACTER:                     //   7               5         3 async db queries
        case CMSG_ENUM_CHARACTERS:                      //  22               3         2 async db queries
        case CMSG_ENUM_CHARACTERS_DELETED_BY_CLIENT:    //  22               3         2 async db queries
        case CMSG_SUBMIT_USER_FEEDBACK:                 // not profiled                1 async db query
        case CMSG_SUPPORT_TICKET_SUBMIT_COMPLAINT:      // not profiled                1 async db query
        case CMSG_CALENDAR_ADD_EVENT:                   //  21              10         2 async db query
        case CMSG_CALENDAR_UPDATE_EVENT:                // not profiled
        case CMSG_CALENDAR_REMOVE_EVENT:                // not profiled
        case CMSG_CALENDAR_COPY_EVENT:                  // not profiled
        case CMSG_CALENDAR_INVITE:                      // not profiled
        case CMSG_CALENDAR_EVENT_SIGN_UP:               // not profiled
        case CMSG_CALENDAR_RSVP:                        // not profiled
        case CMSG_CALENDAR_MODERATOR_STATUS:            // not profiled
        case CMSG_CALENDAR_REMOVE_INVITE:               // not profiled
        case CMSG_SET_LOOT_METHOD:                      // not profiled
        case CMSG_GUILD_INVITE_BY_NAME:                 // not profiled
        case CMSG_ACCEPT_GUILD_INVITE:                  // not profiled
        case CMSG_GUILD_DECLINE_INVITATION:             // not profiled
        case CMSG_GUILD_LEAVE:                          // not profiled
        case CMSG_GUILD_DELETE:                         // not profiled
        case CMSG_GUILD_SET_GUILD_MASTER:               // not profiled
        case CMSG_GUILD_UPDATE_MOTD_TEXT:               // not profiled
        case CMSG_GUILD_SET_RANK_PERMISSIONS:           // not profiled
        case CMSG_GUILD_ADD_RANK:                       // not profiled
        case CMSG_GUILD_DELETE_RANK:                    // not profiled
        case CMSG_GUILD_UPDATE_INFO_TEXT:               // not profiled
        case CMSG_GUILD_BANK_DEPOSIT_MONEY:             // not profiled
        case CMSG_GUILD_BANK_WITHDRAW_MONEY:            // not profiled
        case CMSG_GUILD_BANK_BUY_TAB:                   // not profiled
        case CMSG_GUILD_BANK_UPDATE_TAB:                // not profiled
        case CMSG_GUILD_BANK_SET_TAB_TEXT:              // not profiled
        case CMSG_SAVE_GUILD_EMBLEM:                    // not profiled
        case CMSG_PETITION_RENAME_GUILD:                // not profiled
        case CMSG_CONFIRM_RESPEC_WIPE:                  // not profiled
        case CMSG_SET_DUNGEON_DIFFICULTY:               // not profiled
        case CMSG_SET_RAID_DIFFICULTY:                  // not profiled
        case CMSG_SET_PARTY_ASSIGNMENT:                 // not profiled
        case CMSG_DO_READY_CHECK:                       // not profiled
        {
            maxPacketCounterAllowed = 3;
            break;
        }

        case CMSG_GET_ITEM_PURCHASE_DATA:               // not profiled
        {
            maxPacketCounterAllowed = PLAYER_SLOTS_COUNT;
            break;
        }
        case CMSG_HOTFIX_REQUEST:                       // not profiled
        {
            maxPacketCounterAllowed = 1;
            break;
        }
        default:
        {
            maxPacketCounterAllowed = 100;
            break;
        }
    }

    return maxPacketCounterAllowed;
}

WorldSession::DosProtection::DosProtection(WorldSession* s) : Session(s), _policy((Policy)sWorld->getIntConfig(CONFIG_PACKET_SPOOF_POLICY))
{
}

void WorldSession::ResetTimeSync()
{
    _timeSyncNextCounter = 0;
    _pendingTimeSyncRequests.clear();
}

void WorldSession::SendTimeSync()
{
    WorldPackets::Misc::TimeSyncRequest timeSyncRequest;
    timeSyncRequest.SequenceIndex = _timeSyncNextCounter;
    SendPacket(timeSyncRequest.Write());

    _pendingTimeSyncRequests[_timeSyncNextCounter] = getMSTime();

    // Schedule next sync in 10 sec (except for the 2 first packets, which are spaced by only 5s)
    _timeSyncTimer = _timeSyncNextCounter == 0 ? 5000 : 10000;
    _timeSyncNextCounter++;
}

uint32 WorldSession::AdjustClientMovementTime(uint32 time) const
{
    int64 movementTime = int64(time) + _timeSyncClockDelta;
    if (_timeSyncClockDelta == 0 || movementTime < 0 || movementTime > 0xFFFFFFFF)
    {
        TC_LOG_WARN("misc", "The computed movement time using clockDelta is erronous. Using fallback instead");
        return GameTime::GetGameTimeMS();
    }
    else
        return uint32(movementTime);
}
