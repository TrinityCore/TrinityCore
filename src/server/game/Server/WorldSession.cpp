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
#include "AccountMgr.h"
#include "AddonMgr.h"
#include "BattlegroundMgr.h"
#include "CharacterPackets.h"
#include "Config.h"
#include "Common.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "GameClient.h"
#include "GameTime.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Hyperlinks.h"
#include "Log.h"
#include "Map.h"
#include "Metric.h"
#include "MoveSpline.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvPMgr.h"
#include "PacketUtilities.h"
#include "Player.h"
#include "Realm.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "QueryHolder.h"
#include "Vehicle.h"
#include "WardenMac.h"
#include "WardenWin.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSocket.h"
#include <boost/circular_buffer.hpp>
#include <zlib.h>

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
WorldSession::WorldSession(uint32 id, std::string&& name, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time,
    Minutes timezoneOffset, LocaleConstant locale, uint32 recruiter, bool isARecruiter):
    m_muteTime(mute_time),
    m_timeOutTime(0),
    AntiDOS(this),
    m_GUIDLow(0),
    _player(nullptr),
    m_Socket(std::move(sock)),
    _security(sec),
    _accountId(id),
    _accountName(std::move(name)),
    m_expansion(expansion),
    _logoutTime(0),
    m_inQueue(false),
    m_playerLoading(false),
    m_playerLogout(false),
    m_playerRecentlyLogout(false),
    m_playerSave(false),
    m_sessionDbcLocale(sWorld->GetAvailableDbcLocale(locale)),
    m_sessionDbLocaleIndex(locale),
    _timezoneOffset(timezoneOffset),
    m_latency(0),
    m_TutorialsChanged(TUTORIALS_FLAG_NONE),
    recruiterId(recruiter),
    isRecruiter(isARecruiter),
    _RBACData(nullptr),
    expireTime(60000), // 1 min after socket loss, session is deleted
    forceExit(false),
    m_currentBankerGUID(),
    _timeSyncClockDeltaQueue(std::make_unique<boost::circular_buffer<std::pair<int64, uint32>>>(6)),
    _timeSyncClockDelta(0),
    _pendingTimeSyncRequests(),
    _timeSyncNextCounter(0),
    _timeSyncTimer(0),
    _calendarEventCreationCooldown(0),
    _gameClient(new GameClient(this))
{
    memset(m_Tutorials, 0, sizeof(m_Tutorials));

    if (m_Socket)
    {
        m_Address = m_Socket->GetRemoteIpAddress().to_string();
        ResetTimeOutTime(false);
        LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = {};", GetAccountId());     // One-time query
    }

}

/// WorldSession destructor
WorldSession::~WorldSession()
{
    ///- unload player if not unloaded
    if (_player)
        LogoutPlayer (true);

    /// - If have unclosed socket, close it
    if (m_Socket)
    {
        m_Socket->CloseSocket();
        m_Socket = nullptr;
    }

    delete _RBACData;

    delete _gameClient;

    ///- empty incoming packet queue
    WorldPacket* packet = nullptr;
    while (_recvQueue.next(packet))
        delete packet;

    LoginDatabase.PExecute("UPDATE account SET online = 0 WHERE id = {};", GetAccountId());     // One-time query
}

std::string const & WorldSession::GetPlayerName() const
{
    return _player != nullptr ? _player->GetName() : DefaultPlayerName;
}

std::string WorldSession::GetPlayerInfo() const
{
    std::ostringstream ss;

    ss << "[Player: ";
    if (!m_playerLoading && _player)
        ss << _player->GetName() << ' ' << _player->GetGUID().ToString() << ", ";

    ss << "Account: " << GetAccountId() << "]";

    return ss.str();
}

/// Get player guid if available. Use for logging purposes only
ObjectGuid::LowType WorldSession::GetGUIDLow() const
{
    return GetPlayer() ? GetPlayer()->GetGUID().GetCounter() : 0;
}

/// Send a packet to the client
void WorldSession::SendPacket(WorldPacket const* packet)
{
    ASSERT(packet->GetOpcode() != NULL_OPCODE);

    if (!m_Socket)
        return;

#ifdef TRINITY_DEBUG
    // Code for network use statistic
    static uint64 sendPacketCount = 0;
    static uint64 sendPacketBytes = 0;

    static time_t firstTime = time(nullptr);
    static time_t lastTime = firstTime;                     // next 60 secs start time

    static uint64 sendLastPacketCount = 0;
    static uint64 sendLastPacketBytes = 0;

    time_t cur_time = time(nullptr);

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
    m_Socket->SendPacket(*packet);
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
void WorldSession::LogUnprocessedTail(WorldPacket* packet)
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
        m_Socket->CloseSocket();

    ///- Retrieve packets from the receive queue and call the appropriate handlers
    /// not process packets if socket already closed
    WorldPacket* packet = nullptr;
    //! Delete packet after processing by default
    bool deletePacket = true;
    std::vector<WorldPacket*> requeuePackets;
    uint32 processedPackets = 0;
    time_t currentTime = GameTime::GetGameTime();

    constexpr uint32 MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE = 100;

    while (m_Socket && _recvQueue.next(packet, updater))
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
                            LogUnprocessedTail(packet);
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
                        LogUnprocessedTail(packet);
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
                        LogUnprocessedTail(packet);
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
                    if (packet->GetOpcode() == CMSG_CHAR_ENUM)
                        m_playerRecentlyLogout = false;

                    if (AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                        LogUnprocessedTail(packet);
                    }
                    else
                        processedPackets = MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE;   // break out of packet processing loop
                    break;
                case STATUS_NEVER:
                    TC_LOG_ERROR("network.opcode", "Received not allowed opcode {} from {}", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode()))
                        , GetPlayerInfo());
                    break;
                case STATUS_UNHANDLED:
                    TC_LOG_DEBUG("network.opcode", "Received not handled opcode {} from {}", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode()))
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
        if (m_Socket && m_Socket->IsOpen() && _warden)
            _warden->Update(diff);

        ///- If necessary, log the player out
        if (ShouldLogOut(currentTime) && !m_playerLoading)
            LogoutPlayer(true);

        ///- Cleanup socket pointer if need
        if (m_Socket && !m_Socket->IsOpen())
        {
            if (GetPlayer() && _warden)
                _warden->Update(diff);

            expireTime -= expireTime > diff ? diff : expireTime;
            if (expireTime < diff || forceExit || !GetPlayer())
            {
                m_Socket = nullptr;
            }
        }

        if (!m_Socket)
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
        if (ObjectGuid lguid = _player->GetLootGUID())
            DoLootRelease(lguid);

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
            _player->TeleportTo(_player->m_homebindMapId, _player->m_homebindX, _player->m_homebindY, _player->m_homebindZ, _player->GetOrientation());

        sOutdoorPvPMgr->HandlePlayerLeaveZone(_player, _player->GetZoneId());

        for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        {
            if (BattlegroundQueueTypeId bgQueueTypeId = _player->GetBattlegroundQueueTypeId(i))
            {
                // track if player logs out after invited to join BG
                if (_player->IsInvitedForBattlegroundQueueType(bgQueueTypeId) && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_TRACK_DESERTERS))
                {
                    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_DESERTER_TRACK);
                    stmt->setUInt32(0, _player->GetGUID().GetCounter());
                    stmt->setUInt8(1, BG_DESERTION_TYPE_INVITE_LOGOUT);
                    CharacterDatabase.Execute(stmt);
                }

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
        _player->RemovePet(nullptr, PET_SAVE_AS_CURRENT);

        ///- Clear whisper whitelist
        _player->ClearWhisperWhiteList();

        ///- empty buyback items and save the player in the database
        // some save parts only correctly work in case player present in map/player_lists (pets, etc)
        if (save)
        {
            uint32 eslot;
            for (int j = BUYBACK_SLOT_START; j < BUYBACK_SLOT_END; ++j)
            {
                eslot = j - BUYBACK_SLOT_START;
                _player->SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), ObjectGuid::Empty);
                _player->SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);
                _player->SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, 0);
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
            group->ResetMaxEnchantingLevel();
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

    m_playerLogout = false;
    m_playerSave = false;
    m_playerRecentlyLogout = true;
    SetLogoutStartTime(0);
}

/// Kick a player out of the World
void WorldSession::KickPlayer(std::string const& reason)
{
    if (m_Socket)
    {
        TC_LOG_INFO("network.kick", "Account: {} Character: '{}' {} kicked with reason: {}", GetAccountId(), _player ? _player->GetName() : "<none>",
            _player ? _player->GetGUID().ToString() : "", reason);

        m_Socket->CloseSocket();
        forceExit = true;
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

void WorldSession::SendNotification(const char *format, ...)
{
    if (format)
    {
        va_list ap;
        char szStr[1024];
        szStr[0] = '\0';
        va_start(ap, format);
        vsnprintf(szStr, 1024, format, ap);
        va_end(ap);

        WorldPacket data(SMSG_NOTIFICATION, (strlen(szStr) + 1));
        data << szStr;
        SendPacket(&data);
    }
}

void WorldSession::SendNotification(uint32 string_id, ...)
{
    char const* format = GetTrinityString(string_id);
    if (format)
    {
        va_list ap;
        char szStr[1024];
        szStr[0] = '\0';
        va_start(ap, string_id);
        vsnprintf(szStr, 1024, format, ap);
        va_end(ap);

        WorldPacket data(SMSG_NOTIFICATION, (strlen(szStr) + 1));
        data << szStr;
        SendPacket(&data);
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

void WorldSession::Handle_NULL(WorldPacket& null)
{
    TC_LOG_ERROR("network.opcode", "Received unhandled opcode {} from {}", GetOpcodeNameForLogging(static_cast<OpcodeClient>(null.GetOpcode())), GetPlayerInfo());
}

void WorldSession::Handle_EarlyProccess(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received opcode {} that must be processed in WorldSocket::ReadDataHandler from {}"
        , GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvPacket.GetOpcode())), GetPlayerInfo());
}

void WorldSession::Handle_ServerSide(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received server-side opcode {} from {}"
        , GetOpcodeNameForLogging(static_cast<OpcodeServer>(recvPacket.GetOpcode())), GetPlayerInfo());
}

void WorldSession::Handle_Deprecated(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received deprecated opcode {} from {}"
        , GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvPacket.GetOpcode())), GetPlayerInfo());
}

void WorldSession::SendAuthWaitQueue(uint32 position)
{
    if (position == 0)
    {
        WorldPacket packet(SMSG_AUTH_RESPONSE, 1);
        packet << uint8(AUTH_OK);
        SendPacket(&packet);
    }
    else
    {
        WorldPacket packet(SMSG_AUTH_RESPONSE, 6);
        packet << uint8(AUTH_WAIT_QUEUE);
        packet << uint32(position);
        packet << uint8(0);                                 // unk
        SendPacket(&packet);
    }
}

void WorldSession::LoadAccountData(PreparedQueryResult result, uint32 mask)
{
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        if (mask & (1 << i))
            m_accountData[i] = AccountData();

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

        m_accountData[type].Time = time_t(fields[1].GetUInt32());
        m_accountData[type].Data = fields[2].GetString();
    }
    while (result->NextRow());
}

void WorldSession::SetAccountData(AccountDataType type, time_t tm, std::string const& data)
{
    uint32 id = 0;
    CharacterDatabaseStatements index;
    if ((1 << type) & GLOBAL_CACHE_MASK)
    {
        id = GetAccountId();
        index = CHAR_REP_ACCOUNT_DATA;
    }
    else
    {
        // _player can be NULL and packet received after logout but m_GUID still store correct guid
        if (!m_GUIDLow)
            return;

        id = m_GUIDLow;
        index = CHAR_REP_PLAYER_ACCOUNT_DATA;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(index);
    stmt->setUInt32(0, id);
    stmt->setUInt8 (1, type);
    stmt->setUInt32(2, uint32(tm));
    stmt->setString(3, data);
    CharacterDatabase.Execute(stmt);

    m_accountData[type].Time = tm;
    m_accountData[type].Data = data;
}

void WorldSession::SendAccountDataTimes(uint32 mask)
{
    WorldPacket data(SMSG_ACCOUNT_DATA_TIMES, 4 + 1 + 4 + NUM_ACCOUNT_DATA_TYPES * 4);
    data << uint32(GameTime::GetGameTime());                             // Server time
    data << uint8(1);
    data << uint32(mask);                                   // type mask
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        if (mask & (1 << i))
            data << uint32(GetAccountData(AccountDataType(i))->Time);// also unix time
    SendPacket(&data);
}

void WorldSession::LoadTutorialsData(PreparedQueryResult result)
{
    memset(m_Tutorials, 0, sizeof(uint32) * MAX_ACCOUNT_TUTORIAL_VALUES);

    if (result)
    {
        for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
            m_Tutorials[i] = (*result)[i].GetUInt32();
        m_TutorialsChanged |= TUTORIALS_FLAG_LOADED_FROM_DB;
    }

    m_TutorialsChanged &= ~TUTORIALS_FLAG_CHANGED;
}

void WorldSession::SendTutorialsData()
{
    WorldPacket data(SMSG_TUTORIAL_FLAGS, 4 * MAX_ACCOUNT_TUTORIAL_VALUES);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        data << m_Tutorials[i];
    SendPacket(&data);
}

void WorldSession::SaveTutorialsData(CharacterDatabaseTransaction trans)
{
    if (!(m_TutorialsChanged & TUTORIALS_FLAG_CHANGED))
        return;

    bool const hasTutorialsInDB = (m_TutorialsChanged & TUTORIALS_FLAG_LOADED_FROM_DB) != 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(hasTutorialsInDB ? CHAR_UPD_TUTORIALS : CHAR_INS_TUTORIALS);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        stmt->setUInt32(i, m_Tutorials[i]);
    stmt->setUInt32(MAX_ACCOUNT_TUTORIAL_VALUES, GetAccountId());
    trans->Append(stmt);

    // now has, set flag so next save uses update query
    if (!hasTutorialsInDB)
        m_TutorialsChanged |= TUTORIALS_FLAG_LOADED_FROM_DB;

    m_TutorialsChanged &= ~TUTORIALS_FLAG_CHANGED;
}

void WorldSession::LoadInstanceTimeRestrictions(PreparedQueryResult result)
{
    if (!result)
        return;

    SystemTimePoint now = GameTime::GetSystemTime();
    do
    {
        Field* fields = result->Fetch();
        SystemTimePoint restrictionExpireTime = SystemTimePoint::clock::from_time_t(fields[1].GetUInt64());
        if (restrictionExpireTime > now)
            _instanceResetTimes.try_emplace(fields[0].GetUInt32(), restrictionExpireTime);
    } while (result->NextRow());
}

void WorldSession::SaveInstanceTimeRestrictions(CharacterDatabaseTransaction trans)
{
    if (_instanceResetTimes.empty())
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ACCOUNT_INSTANCE_LOCK_TIMES);
    stmt->setUInt32(0, GetAccountId());
    trans->Append(stmt);

    for (auto const& [instanceId, restrictionExpireTime] : _instanceResetTimes)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ACCOUNT_INSTANCE_LOCK_TIMES);
        stmt->setUInt32(0, GetAccountId());
        stmt->setUInt32(1, instanceId);
        stmt->setUInt64(2, SystemTimePoint::clock::to_time_t(restrictionExpireTime));
        trans->Append(stmt);
    }
}

bool WorldSession::UpdateAndCheckInstanceCount(uint32 instanceId)
{
    UpdateInstanceEnterTimes();

    if (_instanceResetTimes.size() < sWorld->getIntConfig(CONFIG_MAX_INSTANCES_PER_HOUR))
        return true;

    if (instanceId == 0)
        return false;

    return _instanceResetTimes.contains(instanceId);
}

void WorldSession::AddInstanceEnterTime(uint32 instanceId, SystemTimePoint enterTime)
{
    _instanceResetTimes.try_emplace(instanceId, enterTime + 1h);
}

void WorldSession::UpdateInstanceEnterTimes()
{
    Trinity::Containers::EraseIf(_instanceResetTimes, [now = GameTime::GetSystemTime()](std::pair<uint32 const, SystemTimePoint> const& value)
    {
        return value.second < now;
    });
}

void WorldSession::ReadMovementInfo(WorldPacket &data, MovementInfo* mi)
{
    data >> mi->flags;
    data >> mi->flags2;
    data >> mi->time;
    data >> mi->pos.PositionXYZOStream();

    if (mi->HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        data >> mi->transport.guid.ReadAsPacked();
        data >> mi->transport.pos.PositionXYZOStream();
        data >> mi->transport.time;
        data >> mi->transport.seat;

        if (mi->HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
            data >> mi->transport.time2;
    }

    if (mi->HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (mi->HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING)))
        data >> mi->pitch;

    data >> mi->fallTime;

    if (mi->HasMovementFlag(MOVEMENTFLAG_FALLING))
    {
        data >> mi->jump.zspeed;
        data >> mi->jump.sinAngle;
        data >> mi->jump.cosAngle;
        data >> mi->jump.xyspeed;
    }

    if (mi->HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
        data >> mi->splineElevation;

    //! Anti-cheat checks. Please keep them in seperate if () blocks to maintain a clear overview.
    //! Might be subject to latency, so just remove improper flags.
    #ifdef TRINITY_DEBUG
    #define REMOVE_VIOLATING_FLAGS(check, maskToRemove) \
    { \
        if (check) \
        { \
            TC_LOG_DEBUG("entities.unit", "WorldSession::ReadMovementInfo: Violation of MovementFlags found ({}). " \
                "MovementFlags: {}, MovementFlags2: {} for player {}. Mask {} will be removed.", \
                STRINGIZE(check), mi->GetMovementFlags(), mi->GetExtraMovementFlags(), GetPlayer()->GetGUID().ToString(), maskToRemove); \
            mi->RemoveMovementFlag((maskToRemove)); \
        } \
    }
    #else
    #define REMOVE_VIOLATING_FLAGS(check, maskToRemove) \
        if (check) \
            mi->RemoveMovementFlag((maskToRemove));
    #endif

    if (mi->guid.IsEmpty())
    {
        TC_LOG_ERROR("entities.unit", "WorldSession::ReadMovementInfo: mi->guid is empty, opcode {}", static_cast<uint32>(data.GetOpcode()));
        return;
    }

    Unit* mover = GetPlayer()->GetGUID() == mi->guid ? GetPlayer() : ObjectAccessor::GetUnit(*GetPlayer(), mi->guid);
    if (!mover)
    {
        TC_LOG_ERROR("entities.unit", "WorldSession::ReadMovementInfo: If the server allows the unit (GUID {}) to be moved by the client of player {}, the unit should still exist! Opcode {}",
            mi->guid.ToString(),
            GetPlayer()->GetGUID().ToString(),
            static_cast<uint32>(data.GetOpcode()));
        return;
    }

    if (!GetPlayer()->GetVehicleBase() || !(GetPlayer()->GetVehicle()->GetVehicleInfo()->Flags & VEHICLE_FLAG_FIXED_POSITION))
        REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ROOT), MOVEMENTFLAG_ROOT);

    /*! This must be a packet spoofing attempt. MOVEMENTFLAG_ROOT sent from the client is not valid
        in conjunction with any of the moving movement flags such as MOVEMENTFLAG_FORWARD.
        It will freeze clients that receive this player's movement info.
    */
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ROOT) && mi->HasMovementFlag(MOVEMENTFLAG_MASK_MOVING),
        MOVEMENTFLAG_MASK_MOVING);

    //! Cannot hover without SPELL_AURA_HOVER
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_HOVER) && !mover->HasAuraType(SPELL_AURA_HOVER),
        MOVEMENTFLAG_HOVER);

    //! Cannot ascend and descend at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ASCENDING) && mi->HasMovementFlag(MOVEMENTFLAG_DESCENDING),
        MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING);

    //! Cannot move left and right at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_LEFT) && mi->HasMovementFlag(MOVEMENTFLAG_RIGHT),
        MOVEMENTFLAG_LEFT | MOVEMENTFLAG_RIGHT);

    //! Cannot strafe left and right at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_STRAFE_LEFT) && mi->HasMovementFlag(MOVEMENTFLAG_STRAFE_RIGHT),
        MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT);

    //! Cannot pitch up and down at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_PITCH_UP) && mi->HasMovementFlag(MOVEMENTFLAG_PITCH_DOWN),
        MOVEMENTFLAG_PITCH_UP | MOVEMENTFLAG_PITCH_DOWN);

    //! Cannot move forwards and backwards at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FORWARD) && mi->HasMovementFlag(MOVEMENTFLAG_BACKWARD),
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD);

    //! Cannot walk on water without SPELL_AURA_WATER_WALK except for ghosts
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_WATERWALKING) &&
        !mover->HasAuraType(SPELL_AURA_WATER_WALK) &&
        !mover->HasAuraType(SPELL_AURA_GHOST),
        MOVEMENTFLAG_WATERWALKING);

    //! Cannot feather fall without SPELL_AURA_FEATHER_FALL
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FALLING_SLOW) && !mover->HasAuraType(SPELL_AURA_FEATHER_FALL),
        MOVEMENTFLAG_FALLING_SLOW);

    /*! Cannot fly if no fly auras present. Exception is being a GM.
        Note that we check for account level instead of Player::IsGameMaster() because in some
        situations it may be feasable to use .gm fly on as a GM without having .gm on,
        e.g. aerial combat.
    */

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY) && GetSecurity() == SEC_PLAYER &&
        !mover->HasAuraType(SPELL_AURA_FLY) &&
        !mover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED),
        MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY);

    //! Cannot fly and fall at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_DISABLE_GRAVITY) && mi->HasMovementFlag(MOVEMENTFLAG_FALLING),
        MOVEMENTFLAG_FALLING);

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_SPLINE_ENABLED) &&
        (!mover->movespline->Initialized() || mover->movespline->Finalized()), MOVEMENTFLAG_SPLINE_ENABLED);

    #undef REMOVE_VIOLATING_FLAGS
}

void WorldSession::WriteMovementInfo(WorldPacket* data, MovementInfo* mi)
{
    *data << mi->guid.WriteAsPacked();
    *data << mi->flags;
    *data << mi->flags2;
    *data << mi->time;
    *data << mi->pos.PositionXYZOStream();

    if (mi->HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
       *data << mi->transport.guid.WriteAsPacked();
       *data << mi->transport.pos.PositionXYZOStream();
       *data << mi->transport.time;
       *data << mi->transport.seat;

       if (mi->HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
           *data << mi->transport.time2;
    }

    if (mi->HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || mi->HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        *data << mi->pitch;

    *data << mi->fallTime;

    if (mi->HasMovementFlag(MOVEMENTFLAG_FALLING))
    {
        *data << mi->jump.zspeed;
        *data << mi->jump.sinAngle;
        *data << mi->jump.cosAngle;
        *data << mi->jump.xyspeed;
    }

    if (mi->HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
        *data << mi->splineElevation;
}

void WorldSession::ReadAddonsInfo(ByteBuffer &data)
{
    if (data.rpos() + 4 > data.size())
        return;

    uint32 size;
    data >> size;

    if (!size)
        return;

    if (size > 0xFFFFF)
    {
        TC_LOG_DEBUG("addon", "WorldSession::ReadAddonsInfo: AddOnInfo too big, size {}", size);
        return;
    }

    uLongf uSize = size;

    uint32 pos = data.rpos();

    ByteBuffer addonInfo;
    addonInfo.resize(size);

    if (uncompress(addonInfo.contents(), &uSize, data.contents() + pos, data.size() - pos) == Z_OK)
    {
        try
        {
            uint32 addonsCount = addonInfo.read<uint32>();
            if (addonsCount > Addons::MaxSecureAddons)
                addonsCount = Addons::MaxSecureAddons;

            _addons.SecureAddons.resize(addonsCount);

            for (uint32 i = 0; i < addonsCount; ++i)
            {
                Addons::SecureAddonInfo& addon = _addons.SecureAddons[i];
                uint32 publicKeyCrc, urlCrc;

                addonInfo >> addon.Name >> addon.HasKey;
                addonInfo >> publicKeyCrc >> urlCrc;

                TC_LOG_DEBUG("addon", "AddOn: {} (CRC: 0x{:x}) - has key: 0x{:x} - URL CRC: 0x{:x}", addon.Name, publicKeyCrc, addon.HasKey, urlCrc);

                SavedAddon const* savedAddon = AddonMgr::GetAddonInfo(addon.Name);
                if (savedAddon)
                {
                    if (publicKeyCrc != savedAddon->CRC)
                    {
                        if (addon.HasKey)
                        {
                            addon.Status = Addons::SecureAddonInfo::BANNED;
                            TC_LOG_WARN("addon", " Addon: {}: modified (CRC: 0x{:x}) - accountID {})", addon.Name, savedAddon->CRC, GetAccountId());
                        }
                        else
                            addon.Status = Addons::SecureAddonInfo::SECURE_HIDDEN;
                    }
                    else
                    {
                        addon.Status = Addons::SecureAddonInfo::SECURE_HIDDEN;
                        TC_LOG_DEBUG("addon", "Addon: {}: validated (CRC: 0x{:x}) - accountID {}", addon.Name, savedAddon->CRC, GetAccountId());
                    }
                }
                else
                {
                    addon.Status = Addons::SecureAddonInfo::BANNED;
                    TC_LOG_WARN("addon", "Addon: {}: not registered as known secure addon - accountId {}", addon.Name, GetAccountId());
                }
            }

            addonInfo.rpos(addonInfo.size() - 4);

            uint32 lastBannedAddOnTimestamp;
            addonInfo >> lastBannedAddOnTimestamp;
            TC_LOG_DEBUG("addon", "AddOn: Newest banned addon timestamp: {}", lastBannedAddOnTimestamp);
        }
        catch (ByteBufferException const& e)
        {
            TC_LOG_DEBUG("addon", "AddOn: Addon packet read error! {}", e.what());
        }
    }
    else
        TC_LOG_DEBUG("addon", "AddOn: Addon packet uncompress error!");
}

void WorldSession::SendAddonsInfo()
{
    uint8 constexpr addonPublicKey[256] =
    {
        0xC3, 0x5B, 0x50, 0x84, 0xB9, 0x3E, 0x32, 0x42, 0x8C, 0xD0, 0xC7, 0x48, 0xFA, 0x0E, 0x5D, 0x54,
        0x5A, 0xA3, 0x0E, 0x14, 0xBA, 0x9E, 0x0D, 0xB9, 0x5D, 0x8B, 0xEE, 0xB6, 0x84, 0x93, 0x45, 0x75,
        0xFF, 0x31, 0xFE, 0x2F, 0x64, 0x3F, 0x3D, 0x6D, 0x07, 0xD9, 0x44, 0x9B, 0x40, 0x85, 0x59, 0x34,
        0x4E, 0x10, 0xE1, 0xE7, 0x43, 0x69, 0xEF, 0x7C, 0x16, 0xFC, 0xB4, 0xED, 0x1B, 0x95, 0x28, 0xA8,
        0x23, 0x76, 0x51, 0x31, 0x57, 0x30, 0x2B, 0x79, 0x08, 0x50, 0x10, 0x1C, 0x4A, 0x1A, 0x2C, 0xC8,
        0x8B, 0x8F, 0x05, 0x2D, 0x22, 0x3D, 0xDB, 0x5A, 0x24, 0x7A, 0x0F, 0x13, 0x50, 0x37, 0x8F, 0x5A,
        0xCC, 0x9E, 0x04, 0x44, 0x0E, 0x87, 0x01, 0xD4, 0xA3, 0x15, 0x94, 0x16, 0x34, 0xC6, 0xC2, 0xC3,
        0xFB, 0x49, 0xFE, 0xE1, 0xF9, 0xDA, 0x8C, 0x50, 0x3C, 0xBE, 0x2C, 0xBB, 0x57, 0xED, 0x46, 0xB9,
        0xAD, 0x8B, 0xC6, 0xDF, 0x0E, 0xD6, 0x0F, 0xBE, 0x80, 0xB3, 0x8B, 0x1E, 0x77, 0xCF, 0xAD, 0x22,
        0xCF, 0xB7, 0x4B, 0xCF, 0xFB, 0xF0, 0x6B, 0x11, 0x45, 0x2D, 0x7A, 0x81, 0x18, 0xF2, 0x92, 0x7E,
        0x98, 0x56, 0x5D, 0x5E, 0x69, 0x72, 0x0A, 0x0D, 0x03, 0x0A, 0x85, 0xA2, 0x85, 0x9C, 0xCB, 0xFB,
        0x56, 0x6E, 0x8F, 0x44, 0xBB, 0x8F, 0x02, 0x22, 0x68, 0x63, 0x97, 0xBC, 0x85, 0xBA, 0xA8, 0xF7,
        0xB5, 0x40, 0x68, 0x3C, 0x77, 0x86, 0x6F, 0x4B, 0xD7, 0x88, 0xCA, 0x8A, 0xD7, 0xCE, 0x36, 0xF0,
        0x45, 0x6E, 0xD5, 0x64, 0x79, 0x0F, 0x17, 0xFC, 0x64, 0xDD, 0x10, 0x6F, 0xF3, 0xF5, 0xE0, 0xA6,
        0xC3, 0xFB, 0x1B, 0x8C, 0x29, 0xEF, 0x8E, 0xE5, 0x34, 0xCB, 0xD1, 0x2A, 0xCE, 0x79, 0xC3, 0x9A,
        0x0D, 0x36, 0xEA, 0x01, 0xE0, 0xAA, 0x91, 0x20, 0x54, 0xF0, 0x72, 0xD8, 0x1E, 0xC7, 0x89, 0xD2
    };

    WorldPacket data(SMSG_ADDON_INFO, 4);

    for (Addons::SecureAddonInfo const& addonInfo : _addons.SecureAddons)
    {
        // fresh install, not yet created Interface\Addons\addon_name\addon_name.pub files
        uint8 infoProvided = addonInfo.Status != Addons::SecureAddonInfo::BANNED || addonInfo.HasKey;

        data << uint8(addonInfo.Status);                            // Status
        data << uint8(infoProvided);                                // InfoProvided
        if (infoProvided)
        {
            data << uint8(!addonInfo.HasKey);                       // KeyProvided
            if (!addonInfo.HasKey)                                  // if CRC is wrong, add public key (client need it)
            {
                TC_LOG_DEBUG("addon", "AddOn: {}: key missing: sending pubkey to accountID {}", addonInfo.Name, GetAccountId());

                data.append(addonPublicKey, sizeof(addonPublicKey));
            }

            data << uint32(0);                                      // Revision (from .toc), can be used by SECURE_VISIBLE to display "update available" in client addon controls
        }

        data << uint8(0);                                           // UrlProvided
        //if (usesURL)
        //    data << uint8(0);                                     // URL, client will create internet shortcut with this destination in Interface\Addons\addon_name\addon_name.url
    }

    // Send new uncached banned addons
    AddonMgr::BannedAddonList const* bannedAddons = AddonMgr::GetBannedAddons();
    uint32 lastBannedAddOnTimestamp = _addons.LastBannedAddOnTimestamp;
    if (!bannedAddons->empty() && bannedAddons->back().Timestamp < lastBannedAddOnTimestamp) // cheating attempt OR connecting to a realm with different configured banned addons, send everything
        lastBannedAddOnTimestamp = 0;

    std::size_t sizePos = data.wpos();
    uint32 bannedAddonCount = 0;
    data << uint32(0);
    auto itr = std::lower_bound(bannedAddons->begin(), bannedAddons->end(), _addons.LastBannedAddOnTimestamp, [](BannedAddon const& bannedAddon, uint32 timestamp)
    {
        return bannedAddon.Timestamp < timestamp;
    });
    for (; itr != bannedAddons->end(); ++itr)
    {
        data << uint32(itr->Id);
        data.append(itr->NameMD5);
        data.append(itr->VersionMD5);
        data << uint32(itr->Timestamp);
        data << uint32(1);  // IsBanned
        bannedAddonCount++;
    }

    data.put<uint32>(sizePos, bannedAddonCount);

    SendPacket(&data);
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

void WorldSession::InitWarden(SessionKey const& k, std::string const& os)
{
    if (os == "Win")
    {
        _warden = std::make_unique<WardenWin>();
        _warden->Init(this, k);
    }
    else if (os == "OSX")
    {
        // Disabled as it is causing the client to crash
        // _warden = std::make_unique<WardenMac>();
        // _warden->Init(this, k);
    }
}

void WorldSession::LoadPermissions()
{
    uint32 id = GetAccountId();
    uint8 secLevel = GetSecurity();

    _RBACData = new rbac::RBACData(id, _accountName, realm.Id.Realm, secLevel);
    _RBACData->LoadFromDB();
}

QueryCallback WorldSession::LoadPermissionsAsync()
{
    uint32 id = GetAccountId();
    uint8 secLevel = GetSecurity();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: {}, Name: {}, realmId: {}, secLevel: {}]",
        id, _accountName, realm.Id.Realm, secLevel);

    _RBACData = new rbac::RBACData(id, _accountName, realm.Id.Realm, secLevel);
    return _RBACData->LoadFromDBAsync();
}

class AccountInfoQueryHolderPerRealm : public CharacterDatabaseQueryHolder
{
public:
    enum
    {
        GLOBAL_ACCOUNT_DATA = 0,
        TUTORIALS,
        INSTANCE_TIMES,

        MAX_QUERIES
    };

    AccountInfoQueryHolderPerRealm() { SetSize(MAX_QUERIES); }

    bool Initialize(uint32 accountId)
    {
        bool ok = true;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_DATA);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(GLOBAL_ACCOUNT_DATA, stmt) && ok;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_TUTORIALS);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(TUTORIALS, stmt) && ok;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_INSTANCELOCKTIMES);
        stmt->setUInt32(0, accountId);
        ok = SetPreparedQuery(INSTANCE_TIMES, stmt) && ok;

        return ok;
    }
};

void WorldSession::InitializeSession()
{
    std::shared_ptr<AccountInfoQueryHolderPerRealm> realmHolder = std::make_shared<AccountInfoQueryHolderPerRealm>();
    if (!realmHolder->Initialize(GetAccountId()))
    {
        SendAuthResponse(AUTH_SYSTEM_ERROR, false);
        return;
    }

    AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(realmHolder)).AfterComplete([this](SQLQueryHolderBase const& holder)
    {
        InitializeSessionCallback(static_cast<AccountInfoQueryHolderPerRealm const&>(holder));
    });
}

void WorldSession::InitializeSessionCallback(CharacterDatabaseQueryHolder const& realmHolder)
{
    LoadAccountData(realmHolder.GetPreparedResult(AccountInfoQueryHolderPerRealm::GLOBAL_ACCOUNT_DATA), GLOBAL_CACHE_MASK);
    LoadTutorialsData(realmHolder.GetPreparedResult(AccountInfoQueryHolderPerRealm::TUTORIALS));
    LoadInstanceTimeRestrictions(realmHolder.GetPreparedResult(AccountInfoQueryHolderPerRealm::INSTANCE_TIMES));

    if (!m_inQueue)
        SendAuthResponse(AUTH_OK, true);
    else
        SendAuthWaitQueue(0);

    SetInQueue(false);
    ResetTimeOutTime(false);

    SendAddonsInfo();
    SendClientCacheVersion(sWorld->getIntConfig(CONFIG_CLIENTCACHE_VERSION));
    SendTutorialsData();
}

rbac::RBACData* WorldSession::GetRBACData() const
{
    return _RBACData;
}

bool WorldSession::HasPermission(uint32 permission)
{
    if (!_RBACData)
        LoadPermissions();

    bool hasPermission = _RBACData->HasPermission(permission);
    TC_LOG_DEBUG("rbac", "WorldSession::HasPermission [AccountId: {}, Name: {}, realmId: {}]",
                   _RBACData->GetId(), _RBACData->GetName(), realm.Id.Realm);

    return hasPermission;
}

void WorldSession::InvalidateRBACData()
{
    TC_LOG_DEBUG("rbac", "WorldSession::Invalidaterbac::RBACData [AccountId: {}, Name: {}, realmId: {}]",
                   _RBACData->GetId(), _RBACData->GetName(), realm.Id.Realm);
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
        case CMSG_NAME_QUERY:                           //   0               1
        case CMSG_PET_NAME_QUERY:                       //   0               1
        case CMSG_NPC_TEXT_QUERY:                       //   0               1
        case CMSG_ATTACK_STOP:                          //   0               1
        case CMSG_QUERY_QUESTS_COMPLETED:               //   0               1
        case CMSG_QUERY_TIME:                           //   0               1
        case CMSG_CORPSE_MAP_POSITION_QUERY:            //   0               1
        case CMSG_MOVE_TIME_SKIPPED:                    //   0               1
        case MSG_QUERY_NEXT_MAIL_TIME:                  //   0               1
        case CMSG_SET_SHEATHED:                         //   0               1
        case MSG_RAID_TARGET_UPDATE:                    //   0               1
        case CMSG_PLAYER_LOGOUT:                        //   0               1
        case CMSG_LOGOUT_REQUEST:                       //   0               1
        case CMSG_PET_RENAME:                           //   0               1
        case CMSG_QUESTGIVER_CANCEL:                    //   0               1
        case CMSG_QUESTGIVER_REQUEST_REWARD:            //   0               1
        case CMSG_COMPLETE_CINEMATIC:                   //   0               1
        case CMSG_BANKER_ACTIVATE:                      //   0               1
        case CMSG_BUY_BANK_SLOT:                        //   0               1
        case CMSG_OPT_OUT_OF_LOOT:                      //   0               1
        case CMSG_DUEL_ACCEPTED:                        //   0               1
        case CMSG_DUEL_CANCELLED:                       //   0               1
        case CMSG_CALENDAR_COMPLAIN:                    //   0               1
        case CMSG_QUEST_QUERY:                          //   0               1.5
        case CMSG_ITEM_QUERY_SINGLE:                    //   0               1.5
        case CMSG_ITEM_NAME_QUERY:                      //   0               1.5
        case CMSG_GAMEOBJECT_QUERY:                     //   0               1.5
        case CMSG_CREATURE_QUERY:                       //   0               1.5
        case CMSG_QUESTGIVER_STATUS_QUERY:              //   0               1.5
        case CMSG_GUILD_QUERY:                          //   0               1.5
        case CMSG_ARENA_TEAM_QUERY:                     //   0               1.5
        case CMSG_TAXINODE_STATUS_QUERY:                //   0               1.5
        case CMSG_TAXIQUERYAVAILABLENODES:              //   0               1.5
        case CMSG_QUESTGIVER_QUERY_QUEST:               //   0               1.5
        case CMSG_PAGE_TEXT_QUERY:                      //   0               1.5
        case MSG_QUERY_GUILD_BANK_TEXT:                 //   0               1.5
        case MSG_CORPSE_QUERY:                          //   0               1.5
        case MSG_MOVE_SET_FACING:                       //   0               1.5
        case CMSG_REQUEST_PARTY_MEMBER_STATS:           //   0               1.5
        case CMSG_QUESTGIVER_COMPLETE_QUEST:            //   0               1.5
        case CMSG_SET_ACTION_BUTTON:                    //   0               1.5
        case CMSG_RESET_INSTANCES:                      //   0               1.5
        case CMSG_HEARTH_AND_RESURRECT:                 //   0               1.5
        case CMSG_TOGGLE_PVP:                           //   0               1.5
        case CMSG_PET_ABANDON:                          //   0               1.5
        case CMSG_ACTIVATETAXIEXPRESS:                  //   0               1.5
        case CMSG_ACTIVATETAXI:                         //   0               1.5
        case CMSG_SELF_RES:                             //   0               1.5
        case CMSG_UNLEARN_SKILL:                        //   0               1.5
        case CMSG_EQUIPMENT_SET_SAVE:                   //   0               1.5
        case CMSG_DELETEEQUIPMENT_SET:                  //   0               1.5
        case CMSG_DISMISS_CRITTER:                      //   0               1.5
        case CMSG_REPOP_REQUEST:                        //   0               1.5
        case CMSG_GROUP_INVITE:                         //   0               1.5
        case CMSG_GROUP_DECLINE:                        //   0               1.5
        case CMSG_GROUP_ACCEPT:                         //   0               1.5
        case CMSG_GROUP_UNINVITE_GUID:                  //   0               1.5
        case CMSG_GROUP_UNINVITE:                       //   0               1.5
        case CMSG_GROUP_DISBAND:                        //   0               1.5
        case CMSG_BATTLEMASTER_JOIN_ARENA:              //   0               1.5
        case CMSG_LEAVE_BATTLEFIELD:                    //   0               1.5
        case MSG_GUILD_BANK_LOG_QUERY:                  //   0               2
        case CMSG_LOGOUT_CANCEL:                        //   0               2
        case CMSG_REALM_SPLIT:                          //   0               2
        case CMSG_ALTER_APPEARANCE:                     //   0               2
        case CMSG_QUEST_CONFIRM_ACCEPT:                 //   0               2
        case MSG_GUILD_EVENT_LOG_QUERY:                 //   0               2.5
        case CMSG_READY_FOR_ACCOUNT_DATA_TIMES:         //   0               2.5
        case CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY:     //   0               2.5
        case CMSG_BEGIN_TRADE:                          //   0               2.5
        case CMSG_INITIATE_TRADE:                       //   0               3
        case CMSG_MESSAGECHAT:                          //   0               3.5
        case CMSG_INSPECT:                              //   0               3.5
        case CMSG_AREA_SPIRIT_HEALER_QUERY:             // not profiled
        case CMSG_STANDSTATECHANGE:                     // not profiled
        case MSG_RANDOM_ROLL:                           // not profiled
        case CMSG_TIME_SYNC_RESP:                       // not profiled
        case CMSG_TRAINER_BUY_SPELL:                    // not profiled
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:           // not profiled
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:          // not profiled
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     // not profiled
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      // not profiled
        case CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK:        // not profiled
        case CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   // not profiled
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:          // not profiled
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:           // not profiled
        case CMSG_FORCE_PITCH_RATE_CHANGE_ACK:          // not profiled
        {
            // "0" is a magic number meaning there's no limit for the opcode.
            // All the opcodes above must cause little CPU usage and no sync/async database queries at all
            maxPacketCounterAllowed = 0;
            break;
        }

        case CMSG_QUESTGIVER_ACCEPT_QUEST:              //   0               4
        case CMSG_QUESTLOG_REMOVE_QUEST:                //   0               4
        case CMSG_QUESTGIVER_CHOOSE_REWARD:             //   0               4
        case CMSG_CONTACT_LIST:                         //   0               5
        case CMSG_LEARN_PREVIEW_TALENTS:                //   0               6
        case CMSG_AUTOBANK_ITEM:                        //   0               6
        case CMSG_AUTOSTORE_BANK_ITEM:                  //   0               6
        case CMSG_WHO:                                  //   0               7
        case CMSG_PLAYER_VEHICLE_ENTER:                 //   0               8
        case CMSG_LEARN_PREVIEW_TALENTS_PET:            // not profiled
        case MSG_MOVE_HEARTBEAT:
        {
            maxPacketCounterAllowed = 200;
            break;
        }

        case CMSG_GUILD_SET_PUBLIC_NOTE:                //   1               2         1 async db query
        case CMSG_GUILD_SET_OFFICER_NOTE:               //   1               2         1 async db query
        case CMSG_SET_CONTACT_NOTES:                    //   1               2.5       1 async db query
        case CMSG_CALENDAR_GET_CALENDAR:                //   0               1.5       medium upload bandwidth usage
        case CMSG_GUILD_BANK_QUERY_TAB:                 //   0               3.5       medium upload bandwidth usage
        case CMSG_QUERY_INSPECT_ACHIEVEMENTS:           //   0              13         high upload bandwidth usage
        case CMSG_GAMEOBJ_REPORT_USE:                   // not profiled
        case CMSG_GAMEOBJ_USE:                          // not profiled
        case MSG_PETITION_DECLINE:                      // not profiled
        {
            maxPacketCounterAllowed = 50;
            break;
        }

        case CMSG_QUEST_POI_QUERY:                      //   0              25         very high upload bandwidth usage
        {
            maxPacketCounterAllowed = MAX_QUEST_LOG_SIZE;
            break;
        }

        case CMSG_GM_REPORT_LAG:                        //   1               3         1 async db query
        case CMSG_SPELLCLICK:                           // not profiled
        case CMSG_REMOVE_GLYPH:                         // not profiled
        case CMSG_DISMISS_CONTROLLED_VEHICLE:           // not profiled
        {
            maxPacketCounterAllowed = 20;
            break;
        }

        case CMSG_PETITION_SIGN:                        //   9               4         2 sync 1 async db queries
        case CMSG_TURN_IN_PETITION:                     //   8               5.5       2 sync db query
        case CMSG_GROUP_CHANGE_SUB_GROUP:               //   6               5         1 sync 1 async db queries
        case CMSG_PETITION_QUERY:                       //   4               3.5       1 sync db query
        case CMSG_CHAR_RACE_CHANGE:                     //   5               4         1 sync db query
        case CMSG_CHAR_CUSTOMIZE:                       //   5               5         1 sync db query
        case CMSG_CHAR_FACTION_CHANGE:                  //   5               5         1 sync db query
        case CMSG_CHAR_DELETE:                          //   4               4         1 sync db query
        case CMSG_DEL_FRIEND:                           //   7               5         1 async db query
        case CMSG_ADD_FRIEND:                           //   6               4         1 async db query
        case CMSG_CHAR_RENAME:                          //   5               3         1 async db query
        case CMSG_GMSURVEY_SUBMIT:                      //   2               3         1 async db query
        case CMSG_BUG:                                  //   1               1         1 async db query
        case CMSG_GROUP_SET_LEADER:                     //   1               2         1 async db query
        case CMSG_GROUP_RAID_CONVERT:                   //   1               5         1 async db query
        case CMSG_GROUP_ASSISTANT_LEADER:               //   1               2         1 async db query
        case CMSG_PETITION_BUY:                         // not profiled                1 sync 1 async db queries
        case CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE:   // not profiled
        case CMSG_REQUEST_VEHICLE_PREV_SEAT:            // not profiled
        case CMSG_REQUEST_VEHICLE_NEXT_SEAT:            // not profiled
        case CMSG_REQUEST_VEHICLE_SWITCH_SEAT:          // not profiled
        case CMSG_REQUEST_VEHICLE_EXIT:                 // not profiled
        case CMSG_CONTROLLER_EJECT_PASSENGER:           // not profiled
        case CMSG_ITEM_REFUND:                          // not profiled
        case CMSG_SOCKET_GEMS:                          // not profiled
        case CMSG_WRAP_ITEM:                            // not profiled
        case CMSG_REPORT_PVP_AFK:                       // not profiled
        {
            maxPacketCounterAllowed = 10;
            break;
        }

        case CMSG_CHAR_CREATE:                          //   7               5         3 async db queries
        case CMSG_CHAR_ENUM:                            //  22               3         2 async db queries
        case CMSG_GMTICKET_CREATE:                      //   1              25         1 async db query
        case CMSG_GMTICKET_UPDATETEXT:                  //   0              15         1 async db query
        case CMSG_GMTICKET_DELETETICKET:                //   1              25         1 async db query
        case CMSG_GMRESPONSE_RESOLVE:                   //   1              25         1 async db query
        case CMSG_CALENDAR_ADD_EVENT:                   //  21              10         2 async db query
        case CMSG_CALENDAR_UPDATE_EVENT:                // not profiled
        case CMSG_CALENDAR_REMOVE_EVENT:                // not profiled
        case CMSG_CALENDAR_COPY_EVENT:                  // not profiled
        case CMSG_CALENDAR_EVENT_INVITE:                // not profiled
        case CMSG_CALENDAR_EVENT_SIGNUP:                // not profiled
        case CMSG_CALENDAR_EVENT_RSVP:                  // not profiled
        case CMSG_CALENDAR_EVENT_REMOVE_INVITE:         // not profiled
        case CMSG_CALENDAR_EVENT_MODERATOR_STATUS:      // not profiled
        case CMSG_ARENA_TEAM_INVITE:                    // not profiled
        case CMSG_ARENA_TEAM_ACCEPT:                    // not profiled
        case CMSG_ARENA_TEAM_DECLINE:                   // not profiled
        case CMSG_ARENA_TEAM_LEAVE:                     // not profiled
        case CMSG_ARENA_TEAM_DISBAND:                   // not profiled
        case CMSG_ARENA_TEAM_REMOVE:                    // not profiled
        case CMSG_ARENA_TEAM_LEADER:                    // not profiled
        case CMSG_LOOT_METHOD:                          // not profiled
        case CMSG_GUILD_INVITE:                         // not profiled
        case CMSG_GUILD_ACCEPT:                         // not profiled
        case CMSG_GUILD_DECLINE:                        // not profiled
        case CMSG_GUILD_LEAVE:                          // not profiled
        case CMSG_GUILD_DISBAND:                        // not profiled
        case CMSG_GUILD_LEADER:                         // not profiled
        case CMSG_GUILD_MOTD:                           // not profiled
        case CMSG_GUILD_RANK:                           // not profiled
        case CMSG_GUILD_ADD_RANK:                       // not profiled
        case CMSG_GUILD_DEL_RANK:                       // not profiled
        case CMSG_GUILD_INFO_TEXT:                      // not profiled
        case CMSG_GUILD_BANK_DEPOSIT_MONEY:             // not profiled
        case CMSG_GUILD_BANK_WITHDRAW_MONEY:            // not profiled
        case CMSG_GUILD_BANK_BUY_TAB:                   // not profiled
        case CMSG_GUILD_BANK_UPDATE_TAB:                // not profiled
        case CMSG_SET_GUILD_BANK_TEXT:                  // not profiled
        case MSG_SAVE_GUILD_EMBLEM:                     // not profiled
        case MSG_PETITION_RENAME:                       // not profiled
        case MSG_TALENT_WIPE_CONFIRM:                   // not profiled
        case MSG_SET_DUNGEON_DIFFICULTY:                // not profiled
        case MSG_SET_RAID_DIFFICULTY:                   // not profiled
        case MSG_PARTY_ASSIGNMENT:                      // not profiled
        case MSG_RAID_READY_CHECK:                      // not profiled
        {
            maxPacketCounterAllowed = 3;
            break;
        }

        case CMSG_ITEM_REFUND_INFO:                     // not profiled
        {
            maxPacketCounterAllowed = PLAYER_SLOTS_COUNT;
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
    WorldPacket data(SMSG_TIME_SYNC_REQ, 4);
    data << uint32(_timeSyncNextCounter);
    SendPacket(&data);

    _pendingTimeSyncRequests[_timeSyncNextCounter] = getMSTime();

    // Schedule next sync in 10 sec (except for the 2 first packets, which are spaced by only 5s)
    _timeSyncTimer = _timeSyncNextCounter == 0 ? 5000 : 10000;
    _timeSyncNextCounter++;
}

bool WorldSession::IsRightUnitBeingMoved(ObjectGuid guid)
{
    GameClient* client = GetGameClient();

    // the client is attempting to tamper movement data
    // edit: this wouldn't happen in retail but it does in TC, even with a legitimate client.
    if (!client->GetActivelyMovedUnit() || client->GetActivelyMovedUnit()->GetGUID() != guid)
    {
        TC_LOG_DEBUG("entities.unit", "Attempt at tampering movement data by Player {}", _player->GetName());
        return false;
    }

    // This can happen if a legitimate client has lost control of a unit but hasn't received SMSG_CONTROL_UPDATE before
    // sending this packet yet. The server should silently ignore all MOVE messages coming from the client as soon
    // as control over that unit is revoked (through a 'SMSG_CONTROL_UPDATE allowMove=false' message).
    if (!client->IsAllowedToMove(guid))
    {
        TC_LOG_DEBUG("entities.unit", "Bad or outdated movement data by Player {}", _player->GetName());
        return false;
    }

    return true;
}
