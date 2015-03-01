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

/** \file
    \ingroup u2w
*/

#include "WorldSocket.h"
#include <zlib.h>
#include "Config.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "AccountMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Player.h"
#include "Vehicle.h"
#include "ObjectMgr.h"
#include "GuildMgr.h"
#include "Group.h"
#include "Guild.h"
#include "World.h"
#include "ObjectAccessor.h"
#include "BattlegroundMgr.h"
#include "OutdoorPvPMgr.h"
#include "MapManager.h"
#include "SocialMgr.h"
#include "zlib.h"
#include "ScriptMgr.h"
#include "Transport.h"
#include "WardenWin.h"
#include "WardenMac.h"
#include "BattlenetServerManager.h"
#include "AuthenticationPackets.h"
#include "CharacterPackets.h"
#include "ClientConfigPackets.h"
#include "MiscPackets.h"
#include "ChatPackets.h"

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
WorldSession::WorldSession(uint32 id, uint32 battlenetAccountId, std::shared_ptr<WorldSocket> sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter):
    m_muteTime(mute_time),
    m_timeOutTime(0),
    AntiDOS(this),
    m_GUIDLow(UI64LIT(0)),
    _player(NULL),
    _security(sec),
    _accountId(id),
    _battlenetAccountId(battlenetAccountId),
    m_expansion(expansion),
    _warden(NULL),
    _logoutTime(0),
    m_inQueue(false),
    m_playerLogout(false),
    m_playerRecentlyLogout(false),
    m_playerSave(false),
    m_sessionDbcLocale(sWorld->GetAvailableDbcLocale(locale)),
    m_sessionDbLocaleIndex(locale),
    m_latency(0),
    m_clientTimeDelay(0),
    _tutorialsChanged(false),
    _filterAddonMessages(false),
    recruiterId(recruiter),
    isRecruiter(isARecruiter),
    _RBACData(NULL),
    expireTime(60000), // 1 min after socket loss, session is deleted
    forceExit(false),
    m_currentBankerGUID()
{
    memset(_tutorials, 0, sizeof(_tutorials));

    if (sock)
    {
        m_Address = sock->GetRemoteIpAddress().to_string();
        ResetTimeOutTime();
        LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = %u;", GetAccountId());     // One-time query
    }

    m_Socket[CONNECTION_TYPE_REALM] = sock;

    InitializeQueryCallbackParameters();
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

    delete _warden;
    delete _RBACData;

    ///- empty incoming packet queue
    WorldPacket* packet = NULL;
    while (_recvQueue.next(packet))
        delete packet;

    LoginDatabase.PExecute("UPDATE account SET online = 0 WHERE id = %u;", GetAccountId());     // One-time query
}

std::string const & WorldSession::GetPlayerName() const
{
    return _player != NULL ? _player->GetName() : DefaultPlayerName;
}

std::string WorldSession::GetPlayerInfo() const
{
    std::ostringstream ss;

    ss << "[Player: " << GetPlayerName() << " (";
    if (_player)
        ss << _player->GetGUID().ToString() << ", ";
    else if (!m_playerLoading.IsEmpty())
        ss << "Logging in: " << m_playerLoading.ToString() << ", ";

    ss << "Account: " << GetAccountId() << ")]";

    return ss.str();
}

/// Send a packet to the client
void WorldSession::SendPacket(WorldPacket const* packet, bool forced /*= false*/)
{
    if (packet->GetOpcode() == NULL_OPCODE)
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of NULL_OPCODE to %s", GetPlayerInfo().c_str());
        return;
    }
    else if (packet->GetOpcode() == UNKNOWN_OPCODE)
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of UNKNOWN_OPCODE to %s", GetPlayerInfo().c_str());
        return;
    }

    ServerOpcodeHandler const* handler = opcodeTable[static_cast<OpcodeServer>(packet->GetOpcode())];

    if (!handler)
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of opcode %u with non existing handler to %s", packet->GetOpcode(), GetPlayerInfo().c_str());
        return;
    }

    // Default connection index defined in Opcodes.cpp table
    ConnectionType conIdx = handler->ConnectionIndex;

    // Override connection index
    if (packet->GetConnection() != CONNECTION_TYPE_DEFAULT)
    {
        if (packet->GetConnection() != CONNECTION_TYPE_INSTANCE && IsInstanceOnlyOpcode(packet->GetOpcode()))
        {
            TC_LOG_ERROR("network.opcode", "Prevented sending of instance only opcode %u with connection type %u to %s", packet->GetOpcode(), packet->GetConnection(), GetPlayerInfo().c_str());
            return;
        }

        conIdx = packet->GetConnection();
    }

    if (!m_Socket[conIdx])
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of %s to non existent socket %u to %s", GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())).c_str(), conIdx, GetPlayerInfo().c_str());
        return;
    }

    if (!forced)
    {
        if (handler->Status == STATUS_UNHANDLED)
        {
            TC_LOG_ERROR("network.opcode", "Prevented sending disabled opcode %s to %s", GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())).c_str(), GetPlayerInfo().c_str());
            return;
        }
    }

#ifdef TRINITY_DEBUG
    // Code for network use statistic
    static uint64 sendPacketCount = 0;
    static uint64 sendPacketBytes = 0;

    static time_t firstTime = time(NULL);
    static time_t lastTime = firstTime;                     // next 60 secs start time

    static uint64 sendLastPacketCount = 0;
    static uint64 sendLastPacketBytes = 0;

    time_t cur_time = time(NULL);

    if ((cur_time - lastTime) < 60)
    {
        sendPacketCount+=1;
        sendPacketBytes+=packet->size();

        sendLastPacketCount+=1;
        sendLastPacketBytes+=packet->size();
    }
    else
    {
        uint64 minTime = uint64(cur_time - lastTime);
        uint64 fullTime = uint64(lastTime - firstTime);
        TC_LOG_INFO("misc", "Send all time packets count: " UI64FMTD " bytes: " UI64FMTD " avr.count/sec: %f avr.bytes/sec: %f time: %u", sendPacketCount, sendPacketBytes, float(sendPacketCount)/fullTime, float(sendPacketBytes)/fullTime, uint32(fullTime));
        TC_LOG_INFO("misc", "Send last min packets count: " UI64FMTD " bytes: " UI64FMTD " avr.count/sec: %f avr.bytes/sec: %f", sendLastPacketCount, sendLastPacketBytes, float(sendLastPacketCount)/minTime, float(sendLastPacketBytes)/minTime);

        lastTime = cur_time;
        sendLastPacketCount = 1;
        sendLastPacketBytes = packet->wpos();               // wpos is real written size
    }
#endif                                                      // !TRINITY_DEBUG

    sScriptMgr->OnPacketSend(this, *packet);

    m_Socket[conIdx]->SendPacket(*packet);
}

/// Add an incoming packet to the queue
void WorldSession::QueuePacket(WorldPacket* new_packet)
{
    _recvQueue.add(new_packet);
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnexpectedOpcode(WorldPacket* packet, const char* status, const char *reason)
{
    TC_LOG_ERROR("network.opcode", "Received unexpected opcode %s Status: %s Reason: %s from %s",
        GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str(), status, reason, GetPlayerInfo().c_str());
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnprocessedTail(WorldPacket* packet)
{
    if (!sLog->ShouldLog("network.opcode", LOG_LEVEL_TRACE) || packet->rpos() >= packet->wpos())
        return;

    TC_LOG_TRACE("network.opcode", "Unprocessed tail data (read stop at %u from %u) Opcode %s from %s",
        uint32(packet->rpos()), uint32(packet->wpos()), GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str(), GetPlayerInfo().c_str());
    packet->print_storage();
}

/// Update the WorldSession (triggered by World update)
bool WorldSession::Update(uint32 diff, PacketFilter& updater)
{
    /// Update Timeout timer.
    UpdateTimeOutTime(diff);

    ///- Before we process anything:
    /// If necessary, kick the player from the character select screen
    if (IsConnectionIdle())
        m_Socket[CONNECTION_TYPE_REALM]->CloseSocket();

    ///- Retrieve packets from the receive queue and call the appropriate handlers
    /// not process packets if socket already closed
    WorldPacket* packet = NULL;
    //! Delete packet after processing by default
    bool deletePacket = true;
    //! To prevent infinite loop
    WorldPacket* firstDelayedPacket = NULL;
    //! If _recvQueue.peek() == firstDelayedPacket it means that in this Update call, we've processed all
    //! *properly timed* packets, and we're now at the part of the queue where we find
    //! delayed packets that were re-enqueued due to improper timing. To prevent an infinite
    //! loop caused by re-enqueueing the same packets over and over again, we stop updating this session
    //! and continue updating others. The re-enqueued packets will be handled in the next Update call for this session.
    uint32 processedPackets = 0;
    time_t currentTime = time(NULL);

    while (m_Socket[CONNECTION_TYPE_REALM] && !_recvQueue.empty() && _recvQueue.peek(true) != firstDelayedPacket && _recvQueue.next(packet, updater))
    {
        ClientOpcodeHandler const* opHandle = opcodeTable[static_cast<OpcodeClient>(packet->GetOpcode())];
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
                            //! Prevent infinite loop
                            if (!firstDelayedPacket)
                                firstDelayedPacket = packet;
                            //! Because checking a bool is faster than reallocating memory
                            deletePacket = false;
                            QueuePacket(packet);
                            //! Log
                                TC_LOG_DEBUG("network", "Re-enqueueing packet with opcode %s with with status STATUS_LOGGEDIN. "
                                    "Player is currently not in world yet.", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str());
                        }
                    }
                    else if (_player->IsInWorld() && AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                        LogUnprocessedTail(packet);
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
                    break;
                case STATUS_TRANSFER:
                    if (!_player)
                        LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player has not logged in yet");
                    else if (_player->IsInWorld())
                        LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player is still in world");
                    else if(AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
                        LogUnprocessedTail(packet);
                    }
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
                    break;
                case STATUS_NEVER:
                        TC_LOG_ERROR("network.opcode", "Received not allowed opcode %s from %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str()
                            , GetPlayerInfo().c_str());
                    break;
                case STATUS_UNHANDLED:
                        TC_LOG_ERROR("network.opcode", "Received not handled opcode %s from %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str()
                            , GetPlayerInfo().c_str());
                    break;
            }
        }
        catch (ByteBufferException const&)
        {
            TC_LOG_ERROR("network", "WorldSession::Update ByteBufferException occured while parsing a packet (opcode: %u) from client %s, accountid=%i. Skipped packet.",
                    packet->GetOpcode(), GetRemoteAddress().c_str(), GetAccountId());
            packet->hexlike();
        }

        if (deletePacket)
            delete packet;

        deletePacket = true;

#define MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE 100
        processedPackets++;

        //process only a max amout of packets in 1 Update() call.
        //Any leftover will be processed in next update
        if (processedPackets > MAX_PROCESSED_PACKETS_IN_SAME_WORLDSESSION_UPDATE)
            break;
    }

    if (m_Socket[CONNECTION_TYPE_REALM] && m_Socket[CONNECTION_TYPE_REALM]->IsOpen() && _warden)
        _warden->Update();

    ProcessQueryCallbacks();

    //check if we are safe to proceed with logout
    //logout procedure should happen only in World::UpdateSessions() method!!!
    if (updater.ProcessLogout())
    {
        time_t currTime = time(NULL);
        ///- If necessary, log the player out
        if (ShouldLogOut(currTime) && m_playerLoading.IsEmpty())
            LogoutPlayer(true);

        if (m_Socket[CONNECTION_TYPE_REALM] && GetPlayer() && _warden)
            _warden->Update();

        ///- Cleanup socket pointer if need
        if ((m_Socket[CONNECTION_TYPE_REALM] && !m_Socket[CONNECTION_TYPE_REALM]->IsOpen()) ||
            (m_Socket[CONNECTION_TYPE_INSTANCE] && !m_Socket[CONNECTION_TYPE_INSTANCE]->IsOpen()))
        {
            expireTime -= expireTime > diff ? diff : expireTime;
            if (expireTime < diff || forceExit || !GetPlayer())
            {
                m_Socket[CONNECTION_TYPE_REALM].reset();
                m_Socket[CONNECTION_TYPE_INSTANCE].reset();
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
        HandleMoveWorldportAckOpcode();

    m_playerLogout = true;
    m_playerSave = save;

    if (_player)
    {
        ObjectGuid lguid = _player->GetLootGUID();
        if (!lguid.IsEmpty())
            DoLootRelease(lguid);

        ///- If the player just died before logging out, make him appear as a ghost
        if (_player->GetDeathTimer())
        {
            _player->getHostileRefManager().deleteReferences();
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
                _player->RemoveBattlegroundQueueId(bgQueueTypeId);
                BattlegroundQueue& queue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
                queue.RemovePlayer(_player->GetGUID(), true);
            }
        }

        // Repop at GraveYard or other player far teleport will prevent saving player because of not present map
        // Teleport player immediately for correct player save
        while (_player->IsBeingTeleportedFar())
            HandleMoveWorldportAckOpcode();

        ///- If the player is in a guild, update the guild roster and broadcast a logout message to other guild members
        if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
            guild->HandleMemberLogout(this);

        ///- Remove pet
        _player->RemovePet(NULL, PET_SAVE_AS_CURRENT, true);

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
                _player->SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (j * 4), ObjectGuid::Empty);
                _player->SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);
                _player->SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, 0);
            }
            _player->SaveToDB();
        }

        ///- Leave all channels before player delete...
        _player->CleanupChannels();

        ///- If the player is in a group (or invited), remove him. If the group if then only 1 person, disband the group.
        _player->UninviteFromGroup();

        // remove player from the group if he is:
        // a) in group; b) not in raid group; c) logging out normally (not being kicked or disconnected)
        if (_player->GetGroup() && !_player->GetGroup()->isRaidGroup() && m_Socket[CONNECTION_TYPE_REALM])
            _player->RemoveFromGroup();

        //! Send update to group and reset stored max enchanting level
        if (_player->GetGroup())
        {
            _player->GetGroup()->SendUpdate();
            _player->GetGroup()->ResetMaxEnchantingLevel();
        }

        //! Broadcast a logout message to the player's friends
        sSocialMgr->SendFriendStatus(_player, FRIEND_OFFLINE, _player->GetGUID(), true);
        _player->RemoveSocial();

        //! Call script hook before deletion
        sScriptMgr->OnPlayerLogout(_player);

        //! Remove the player from the world
        // the player may not be in the world when logging out
        // e.g if he got disconnected during a transfer to another map
        // calls to GetMap in this case may cause crashes
        _player->CleanupsBeforeDelete();
        TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Logout Character:[%s] (%s) Level: %d",
            GetAccountId(), GetRemoteAddress().c_str(), _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), _player->getLevel());

        sBattlenetServer.SendChangeToonOnlineState(GetBattlenetAccountId(), GetAccountId(), _player->GetGUID(), _player->GetName(), false);

        if (Map* _map = _player->FindMap())
            _map->RemovePlayerFromMap(_player, true);

        SetPlayer(NULL); //! Pointer already deleted during RemovePlayerFromMap

        //! Send the 'logout complete' packet to the client
        //! Client will respond by sending 3x CMSG_CANCEL_TRADE, which we currently dont handle
        SendPacket(WorldPackets::Character::LogoutComplete().Write());
        TC_LOG_DEBUG("network", "SESSION: Sent SMSG_LOGOUT_COMPLETE Message");

        //! Since each account can only have one online character at any given time, ensure all characters for active account are marked as offline
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ACCOUNT_ONLINE);
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
void WorldSession::KickPlayer()
{
    for (uint8 i = 0; i < 2; ++i)
    {
        if (m_Socket[i])
        {
            m_Socket[i]->CloseSocket();
            forceExit = true;
        }
    }
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

char const* WorldSession::GetTrinityString(uint32 entry) const
{
    return sObjectMgr->GetTrinityString(entry, GetSessionDbLocaleIndex());
}

void WorldSession::Handle_NULL(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received unhandled opcode %s from %s"
        , GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvPacket.GetOpcode())).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_EarlyProccess(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received opcode %s that must be processed in WorldSocket::OnRead from %s"
        , GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvPacket.GetOpcode())).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_ServerSide(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received server-side opcode %s from %s"
        , GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvPacket.GetOpcode())).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::SendConnectToInstance(WorldPackets::Auth::ConnectToSerial serial)
{
    boost::system::error_code ignored_error;
    boost::asio::ip::tcp::endpoint instanceAddress = realm.GetAddressForClient(boost::asio::ip::address::from_string(GetRemoteAddress(), ignored_error));
    instanceAddress.port(sWorld->getIntConfig(CONFIG_PORT_INSTANCE));

    WorldPackets::Auth::ConnectTo connectTo;
    connectTo.Key = MAKE_PAIR64(GetAccountId(), CONNECTION_TYPE_INSTANCE);
    connectTo.Serial = serial;
    connectTo.Payload.Where = instanceAddress;
    connectTo.Con = CONNECTION_TYPE_INSTANCE;

    SendPacket(connectTo.Write());
}

void WorldSession::LoadGlobalAccountData()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_DATA);
    stmt->setUInt32(0, GetAccountId());
    LoadAccountData(CharacterDatabase.Query(stmt), GLOBAL_CACHE_MASK);
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
            TC_LOG_ERROR("misc", "Table `%s` have invalid account data type (%u), ignore.",
                mask == GLOBAL_CACHE_MASK ? "account_data" : "character_account_data", type);
            continue;
        }

        if ((mask & (1 << type)) == 0)
        {
            TC_LOG_ERROR("misc", "Table `%s` have non appropriate for table  account data type (%u), ignore.",
                mask == GLOBAL_CACHE_MASK ? "account_data" : "character_account_data", type);
            continue;
        }

        _accountData[type].Time = time_t(fields[1].GetUInt32());
        _accountData[type].Data = fields[2].GetString();
    }
    while (result->NextRow());
}

void WorldSession::SetAccountData(AccountDataType type, uint32 time, std::string const& data)
{
    if ((1 << type) & GLOBAL_CACHE_MASK)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_ACCOUNT_DATA);
        stmt->setUInt32(0, GetAccountId());
        stmt->setUInt8(1, type);
        stmt->setUInt32(2, time);
        stmt->setString(3, data);
        CharacterDatabase.Execute(stmt);
    }
    else
    {
        // _player can be NULL and packet received after logout but m_GUID still store correct guid
        if (!m_GUIDLow)
            return;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_PLAYER_ACCOUNT_DATA);
        stmt->setUInt64(0, m_GUIDLow);
        stmt->setUInt8(1, type);
        stmt->setUInt32(2, time);
        stmt->setString(3, data);
        CharacterDatabase.Execute(stmt);
    }

    _accountData[type].Time = time_t(time);
    _accountData[type].Data = data;
}

void WorldSession::LoadTutorialsData()
{
    memset(_tutorials, 0, sizeof(uint32) * MAX_ACCOUNT_TUTORIAL_VALUES);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_TUTORIALS);
    stmt->setUInt32(0, GetAccountId());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
            _tutorials[i] = (*result)[i].GetUInt32();

    _tutorialsChanged = false;
}

void WorldSession::SendTutorialsData()
{
    WorldPackets::Misc::TutorialFlags packet;
    memcpy(packet.TutorialData, _tutorials, sizeof(_tutorials));
    SendPacket(packet.Write());
}

void WorldSession::SaveTutorialsData(SQLTransaction& trans)
{
    if (!_tutorialsChanged)
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_HAS_TUTORIALS);
    stmt->setUInt32(0, GetAccountId());
    bool hasTutorials = bool(CharacterDatabase.Query(stmt));
    // Modify data in DB
    stmt = CharacterDatabase.GetPreparedStatement(hasTutorials ? CHAR_UPD_TUTORIALS : CHAR_INS_TUTORIALS);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        stmt->setUInt32(i, _tutorials[i]);
    stmt->setUInt32(MAX_ACCOUNT_TUTORIAL_VALUES, GetAccountId());
    trans->Append(stmt);

    _tutorialsChanged = false;
}

void WorldSession::ReadAddonsInfo(ByteBuffer& data)
{
    if (data.rpos() + 4 > data.size())
        return;

    uint32 size;
    data >> size;

    if (!size)
        return;

    if (size > 0xFFFFF)
    {
        TC_LOG_ERROR("misc", "WorldSession::ReadAddonsInfo addon info too big, size %u", size);
        return;
    }

    uLongf uSize = size;

    uint32 pos = data.rpos();

    ByteBuffer addonInfo;
    addonInfo.resize(size);

    m_addonsList.clear();

    if (uncompress(addonInfo.contents(), &uSize, data.contents() + pos, data.size() - pos) == Z_OK)
    {
        uint32 addonsCount;
        addonInfo >> addonsCount;                         // addons count

        for (uint32 i = 0; i < addonsCount; ++i)
        {
            std::string addonName;
            uint8 enabled;
            uint32 crc, unk1;

            // check next addon data format correctness
            if (addonInfo.rpos() + 1 > addonInfo.size())
                return;

            addonInfo >> addonName;

            addonInfo >> enabled >> crc >> unk1;

            TC_LOG_INFO("misc", "ADDON: Name: %s, Enabled: 0x%x, CRC: 0x%x, Unknown2: 0x%x", addonName.c_str(), enabled, crc, unk1);

            AddonInfo addon(addonName, enabled, crc, 2, true);

            SavedAddon const* savedAddon = AddonMgr::GetAddonInfo(addonName);
            if (savedAddon)
            {
                if (addon.CRC != savedAddon->CRC)
                    TC_LOG_INFO("misc", "ADDON: %s was known, but didn't match known CRC (0x%x)!", addon.Name.c_str(), savedAddon->CRC);
                else
                    TC_LOG_INFO("misc", "ADDON: %s was known, CRC is correct (0x%x)", addon.Name.c_str(), savedAddon->CRC);
            }
            else
            {
                AddonMgr::SaveAddon(addon);

                TC_LOG_INFO("misc", "ADDON: %s (0x%x) was not known, saving...", addon.Name.c_str(), addon.CRC);
            }

            /// @todo Find out when to not use CRC/pubkey, and other possible states.
            m_addonsList.push_back(addon);
        }

        uint32 currentTime;
        addonInfo >> currentTime;
        TC_LOG_DEBUG("network", "ADDON: CurrentTime: %u", currentTime);
    }
    else
        TC_LOG_ERROR("misc", "Addon packet uncompress error!");
}

void WorldSession::SendAddonsInfo()
{
    WorldPackets::ClientConfig::AddonInfo addonInfo;
    addonInfo.Addons = &m_addonsList;
    addonInfo.BannedAddons = AddonMgr::GetBannedAddons();
    SendPacket(addonInfo.Write());
}

bool WorldSession::IsAddonRegistered(const std::string& prefix) const
{
    if (!_filterAddonMessages) // if we have hit the softcap (64) nothing should be filtered
        return true;

    if (_registeredAddonPrefixes.empty())
        return false;

    std::vector<std::string>::const_iterator itr = std::find(_registeredAddonPrefixes.begin(), _registeredAddonPrefixes.end(), prefix);
    return itr != _registeredAddonPrefixes.end();
}

void WorldSession::HandleUnregisterAddonPrefixesOpcode(WorldPacket& /*recvPacket*/) // empty packet
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_UNREGISTER_ALL_ADDON_PREFIXES");

    _registeredAddonPrefixes.clear();
}

void WorldSession::HandleAddonRegisteredPrefixesOpcode(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_ADDON_REGISTERED_PREFIXES");

    // This is always sent after CMSG_UNREGISTER_ALL_ADDON_PREFIXES

    uint32 count = recvPacket.ReadBits(25);

    if (count > REGISTERED_ADDON_PREFIX_SOFTCAP)
    {
        // if we have hit the softcap (64) nothing should be filtered
        _filterAddonMessages = false;
        recvPacket.rfinish();
        return;
    }

    std::vector<uint8> lengths(count);
    for (uint32 i = 0; i < count; ++i)
        lengths[i] = recvPacket.ReadBits(5);

    for (uint32 i = 0; i < count; ++i)
        _registeredAddonPrefixes.push_back(recvPacket.ReadString(lengths[i]));

    if (_registeredAddonPrefixes.size() > REGISTERED_ADDON_PREFIX_SOFTCAP) // shouldn't happen
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

void WorldSession::InitializeQueryCallbackParameters()
{
    // Callback parameters that have pointers in them should be properly
    // initialized to nullptr here.
}

void WorldSession::ProcessQueryCallbacks()
{
    PreparedQueryResult result;

    //! HandleCharEnumOpcode and HandleCharUndeleteEnumOpcode
    if (_charEnumCallback.IsReady())
    {
        _charEnumCallback.GetResult(result);

        if (_charEnumCallback.GetParam())
            HandleCharUndeleteEnum(result);
        else
            HandleCharEnum(result);

        _charEnumCallback.FreeResult();
    }

    //! HandleCharCreateOpcode
    if (_charCreateCallback.IsReady())
    {
        _charCreateCallback.GetResult(result);
        HandleCharCreateCallback(result, _charCreateCallback.GetParam().get());
    }

    //! HandleCharCustomizeOpcode
    if (_charCustomizeCallback.IsReady())
    {
        _charCustomizeCallback.GetResult(result);
        HandleCharCustomizeCallback(result, _charCustomizeCallback.GetParam().get());
        _charCustomizeCallback.Reset();
    }

    //! HandleCharRaceOrFactionChangeOpcode
    if (_charFactionChangeCallback.IsReady())
    {
        _charFactionChangeCallback.GetResult(result);
        HandleCharRaceOrFactionChangeCallback(result, _charFactionChangeCallback.GetParam().get());
        _charFactionChangeCallback.Reset();
    }

    //! HandlePlayerLoginOpcode
    if (_charLoginCallback.valid() && _charLoginCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        SQLQueryHolder* param = _charLoginCallback.get();
        HandlePlayerLogin((LoginQueryHolder*)param);
    }

    //! HandleAddFriendOpcode
    if (_addFriendCallback.IsReady())
    {
        std::string param = _addFriendCallback.GetParam();
        _addFriendCallback.GetResult(result);
        HandleAddFriendOpcodeCallBack(result, param);
        _addFriendCallback.FreeResult();
    }

    //- HandleCharRenameOpcode
    if (_charRenameCallback.IsReady())
    {
        _charRenameCallback.GetResult(result);
        HandleCharRenameCallBack(result, _charRenameCallback.GetParam().get());
        _charRenameCallback.Reset();
    }

    /// HandleUndeleteCooldownStatusOpcode
    /// wait until no char undelete is in progress
    if (!_charUndeleteCallback.GetStage() && _undeleteCooldownStatusCallback.IsReady())
    {
        _undeleteCooldownStatusCallback.GetResult(result);
        HandleUndeleteCooldownStatusCallback(result);
    }

    /// HandleCharUndeleteOpcode
    if (_charUndeleteCallback.IsReady())
    {
        _charUndeleteCallback.GetResult(result);
        HandleCharUndeleteCallback(result, _charUndeleteCallback.GetParam().get());
    }

    //- HandleCharAddIgnoreOpcode
    if (_addIgnoreCallback.valid() && _addIgnoreCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        result = _addIgnoreCallback.get();
        HandleAddIgnoreOpcodeCallBack(result);
    }

    //- SendStabledPet
    if (_sendStabledPetCallback.IsReady())
    {
        ObjectGuid param = _sendStabledPetCallback.GetParam();
        _sendStabledPetCallback.GetResult(result);
        SendStablePetCallback(result, param);
        _sendStabledPetCallback.FreeResult();
    }

    //- HandleStablePet
    if (_stablePetCallback.valid() && _stablePetCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        result = _stablePetCallback.get();
        HandleStablePetCallback(result);
    }

    //- HandleUnstablePet
    if (_unstablePetCallback.IsReady())
    {
        uint32 param = _unstablePetCallback.GetParam();
        _unstablePetCallback.GetResult(result);
        HandleUnstablePetCallback(result, param);
        _unstablePetCallback.FreeResult();
    }

    //- HandleStableSwapPet
    if (_stableSwapCallback.IsReady())
    {
        uint32 param = _stableSwapCallback.GetParam();
        _stableSwapCallback.GetResult(result);
        HandleStableSwapPetCallback(result, param);
        _stableSwapCallback.FreeResult();
    }
}

void WorldSession::InitWarden(BigNumber* k, std::string const& os)
{
    if (os == "Win")
    {
        _warden = new WardenWin();
        _warden->Init(this, k);
    }
    else if (os == "OSX")
    {
        // Disabled as it is causing the client to crash
        // _warden = new WardenMac();
        // _warden->Init(this, k);
    }
}

void WorldSession::LoadPermissions()
{
    uint32 id = GetAccountId();
    std::string name;
    AccountMgr::GetName(id, name);
    uint8 secLevel = GetSecurity();

    _RBACData = new rbac::RBACData(id, name, realmHandle.Index, secLevel);
    _RBACData->LoadFromDB();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: %u, Name: %s, realmId: %d, secLevel: %u]",
                   id, name.c_str(), realmHandle.Index, secLevel);
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
    TC_LOG_DEBUG("rbac", "WorldSession::HasPermission [AccountId: %u, Name: %s, realmId: %d]",
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realmHandle.Index);

    return hasPermission;
}

void WorldSession::InvalidateRBACData()
{
    TC_LOG_DEBUG("rbac", "WorldSession::Invalidaterbac::RBACData [AccountId: %u, Name: %s, realmId: %d]",
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realmHandle.Index);
    delete _RBACData;
    _RBACData = NULL;
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

    TC_LOG_WARN("network", "AntiDOS: Account %u, IP: %s, Ping: %u, Character: %s, flooding packet (opc: %s (0x%X), count: %u)",
        Session->GetAccountId(), Session->GetRemoteAddress().c_str(), Session->GetLatency(), Session->GetPlayerName().c_str(),
        opcodeTable[static_cast<OpcodeClient>(p.GetOpcode())]->Name, p.GetOpcode(), packetCounter.amountCounter);

    switch (_policy)
    {
        case POLICY_LOG:
            return true;
        case POLICY_KICK:
        {
            TC_LOG_INFO("network", "AntiDOS: Player kicked!");
            Session->KickPlayer();
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
            TC_LOG_INFO("network", "AntiDOS: Player automatically banned for %u seconds.", duration);
            Session->KickPlayer();
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
    {/*
        // CPU usage sending 2000 packets/second on a 3.70 GHz 4 cores on Win x64
        //                                              [% CPU mysqld]   [%CPU worldserver RelWithDebInfo]
        case CMSG_PLAYER_LOGIN:                         //   0               0.5
        case CMSG_NAME_QUERY:                           //   0               1
        case CMSG_PET_NAME_QUERY:                       //   0               1
        case CMSG_NPC_TEXT_QUERY:                       //   0               1
        case CMSG_ATTACKSTOP:                           //   0               1
        //case CMSG_QUERY_TIME:                           //   0               1
        //case CMSG_CORPSE_MAP_POSITION_QUERY:            //   0               1
        case CMSG_MOVE_TIME_SKIPPED:                    //   0               1
        //case MSG_QUERY_NEXT_MAIL_TIME:                  //   0               1
        case CMSG_SET_SHEATHED:                         //   0               1
        //case MSG_RAID_TARGET_UPDATE:                    //   0               1
        case CMSG_LOGOUT_REQUEST:                       //   0               1
        //case CMSG_PET_RENAME:                           //   0               1
        case CMSG_QUESTGIVER_REQUEST_REWARD:            //   0               1
        //case CMSG_COMPLETE_CINEMATIC:                   //   0               1
        case CMSG_BANKER_ACTIVATE:                      //   0               1
        case CMSG_BUY_BANK_SLOT:                        //   0               1
        //case CMSG_OPT_OUT_OF_LOOT:                      //   0               1
        case CMSG_DUEL_RESPONSE:                        //   0               1
        //case CMSG_CALENDAR_COMPLAIN:                    //   0               1
        case CMSG_QUEST_QUERY:                          //   0               1.5
        case CMSG_GAMEOBJECT_QUERY:                     //   0               1.5
        case CMSG_CREATURE_QUERY:                       //   0               1.5
        case CMSG_QUESTGIVER_STATUS_QUERY:              //   0               1.5
        case CMSG_GUILD_QUERY:                          //   0               1.5
        //case CMSG_ARENA_TEAM_QUERY:                     //   0               1.5
        case CMSG_TAXI_NODE_STATUS_QUERY:               //   0               1.5
        //case CMSG_TAXI_QUERY_AVAILABLE_NODES:              //   0               1.5
        case CMSG_QUESTGIVER_QUERY_QUEST:               //   0               1.5
        case CMSG_PAGE_TEXT_QUERY:                      //   0               1.5
        //case CMSG_GUILD_BANK_QUERY_TEXT:                //   0               1.5
        //case MSG_CORPSE_QUERY:                          //   0               1.5
        case CMSG_MOVE_SET_FACING:                      //   0               1.5
        //case CMSG_REQUEST_PARTY_MEMBER_STATS:           //   0               1.5
        case CMSG_QUESTGIVER_COMPLETE_QUEST:            //   0               1.5
        case CMSG_SET_ACTION_BUTTON:                    //   0               1.5
        case CMSG_RESET_INSTANCES:                      //   0               1.5
        case CMSG_HEARTH_AND_RESURRECT:                 //   0               1.5
        case CMSG_TOGGLE_PVP:                           //   0               1.5
        case CMSG_PET_ABANDON:                          //   0               1.5
        case CMSG_ACTIVATE_TAXI_EXPRESS:                //   0               1.5
        case CMSG_ACTIVATE_TAXI:                        //   0               1.5
        case CMSG_SELF_RES:                             //   0               1.5
        case CMSG_UNLEARN_SKILL:                        //   0               1.5
        case CMSG_EQUIPMENT_SET_SAVE:                   //   0               1.5
        case CMSG_DELETE_EQUIPMENT_SET:                 //   0               1.5
        //case CMSG_DISMISS_CRITTER:                      //   0               1.5
        case CMSG_REPOP_REQUEST:                        //   0               1.5
        //case CMSG_GROUP_INVITE:                         //   0               1.5
        //case CMSG_GROUP_INVITE_RESPONSE:                //   0               1.5
        //case CMSG_GROUP_UNINVITE_GUID:                  //   0               1.5
        //case CMSG_GROUP_DISBAND:                        //   0               1.5
        case CMSG_BATTLEMASTER_JOIN_ARENA:              //   0               1.5
        case CMSG_BATTLEFIELD_LEAVE:                    //   0               1.5
        case CMSG_GUILD_BANK_LOG_QUERY:                 //   0               2
        case CMSG_LOGOUT_CANCEL:                        //   0               2
        case CMSG_ALTER_APPEARANCE:                     //   0               2
        //case CMSG_QUEST_CONFIRM_ACCEPT:                 //   0               2
        case CMSG_GUILD_EVENT_LOG_QUERY:                //   0               2.5
        case CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY:     //   0               2.5
        //case CMSG_BEGIN_TRADE:                          //   0               2.5
        //case CMSG_INITIATE_TRADE:                       //   0               3
        case CMSG_MESSAGECHAT_ADDON_GUILD:              //   0               3.5
        case CMSG_MESSAGECHAT_ADDON_OFFICER:            //   0               3.5
        case CMSG_MESSAGECHAT_ADDON_PARTY:              //   0               3.5
        case CMSG_MESSAGECHAT_ADDON_RAID:               //   0               3.5
        case CMSG_MESSAGECHAT_ADDON_WHISPER:            //   0               3.5
        case CMSG_MESSAGECHAT_AFK:                      //   0               3.5
        case CMSG_MESSAGECHAT_CHANNEL:                  //   0               3.5
        case CMSG_MESSAGECHAT_DND:                      //   0               3.5
        case CMSG_MESSAGECHAT_EMOTE:                    //   0               3.5
        case CMSG_MESSAGECHAT_GUILD:                    //   0               3.5
        case CMSG_MESSAGECHAT_OFFICER:                  //   0               3.5
        case CMSG_MESSAGECHAT_PARTY:                    //   0               3.5
        case CMSG_MESSAGECHAT_RAID:                     //   0               3.5
        case CMSG_MESSAGECHAT_RAID_WARNING:             //   0               3.5
        case CMSG_MESSAGECHAT_SAY:                      //   0               3.5
        case CMSG_MESSAGECHAT_WHISPER:                  //   0               3.5
        case CMSG_MESSAGECHAT_YELL:                     //   0               3.5
        case CMSG_INSPECT:                              //   0               3.5
        //case CMSG_AREA_SPIRIT_HEALER_QUERY:             // not profiled
        case CMSG_STAND_STATE_CHANGE:                     // not profiled
        case CMSG_RANDOM_ROLL:                          // not profiled
        case CMSG_TIME_SYNC_RESPONSE:                   // not profiled
        case CMSG_TRAINER_BUY_SPELL:                    // not profiled
        {
            // "0" is a magic number meaning there's no limit for the opcode.
            // All the opcodes above must cause little CPU usage and no sync/async database queries at all
            maxPacketCounterAllowed = 0;
            break;
        }

        case CMSG_QUESTGIVER_ACCEPT_QUEST:              //   0               4
        //case CMSG_QUESTLOG_REMOVE_QUEST:                //   0               4
        case CMSG_QUESTGIVER_CHOOSE_REWARD:             //   0               4
        //case CMSG_SEND_CONTACT_LIST:                    //   0               5
        case CMSG_AUTOBANK_ITEM:                        //   0               6
        case CMSG_AUTOSTORE_BANK_ITEM:                  //   0               6
        case CMSG_WHO:                                  //   0               7
        //case CMSG_PLAYER_VEHICLE_ENTER:                 //   0               8
        case CMSG_MOVE_HEARTBEAT:
        {
            maxPacketCounterAllowed = 200;
            break;
        }

        //case CMSG_GUILD_SET_NOTE:                       //   1               2         1 async db query
        //case CMSG_SET_CONTACT_NOTES:                    //   1               2.5       1 async db query
        //case CMSG_CALENDAR_GET:                         //   0               1.5       medium upload bandwidth usage
        case CMSG_GUILD_BANK_QUERY_TAB:                 //   0               3.5       medium upload bandwidth usage
        //case CMSG_QUERY_INSPECT_ACHIEVEMENTS:           //   0              13         high upload bandwidth usage
        case CMSG_GAMEOBJ_REPORT_USE:                   // not profiled
        case CMSG_GAMEOBJ_USE:                          // not profiled
        //case MSG_PETITION_DECLINE:                      // not profiled
        {
            maxPacketCounterAllowed = 50;
            break;
        }

        case CMSG_QUEST_POI_QUERY:                      //   0              25         very high upload bandwidth usage
        {
            maxPacketCounterAllowed = MAX_QUEST_LOG_SIZE;
            break;
        }

        //case CMSG_GM_REPORT_LAG:                        //   1               3         1 async db query
        case CMSG_SPELLCLICK:                           // not profiled
        //case CMSG_DISMISS_CONTROLLED_VEHICLE:           // not profiled
        {
            maxPacketCounterAllowed = 20;
            break;
        }

        //case CMSG_PETITION_SIGN:                        //   9               4         2 sync 1 async db queries
        //case CMSG_TURN_IN_PETITION:                     //   8               5.5       2 sync db query
        //case CMSG_GROUP_CHANGE_SUB_GROUP:               //   6               5         1 sync 1 async db queries
        //case CMSG_PETITION_QUERY:                       //   4               3.5       1 sync db query
        case CMSG_CHAR_CUSTOMIZE:                       //   5               5         1 sync db query
        case CMSG_CHAR_RACE_OR_FACTION_CHANGE:          //   5               5         1 sync db query
        case CMSG_CHAR_DELETE:                          //   4               4         1 sync db query
        case CMSG_DEL_FRIEND:                           //   7               5         1 async db query
        case CMSG_ADD_FRIEND:                           //   6               4         1 async db query
        case CMSG_CHAR_RENAME:                          //   5               3         1 async db query
        //case CMSG_GMSURVEY_SUBMIT:                      //   2               3         1 async db query
        //case CMSG_BUG:                                  //   1               1         1 async db query
        //case CMSG_GROUP_SET_LEADER:                     //   1               2         1 async db query
        //case CMSG_GROUP_RAID_CONVERT:                   //   1               5         1 async db query
        //case CMSG_GROUP_ASSISTANT_LEADER:               //   1               2         1 async db query
        //case CMSG_CALENDAR_ADD_EVENT:                   //  21              10         2 async db query
        //case CMSG_PETITION_BUY:                         // not profiled                1 sync 1 async db queries
        //case CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE:   // not profiled
        //case CMSG_REQUEST_VEHICLE_PREV_SEAT:            // not profiled
        //case CMSG_REQUEST_VEHICLE_NEXT_SEAT:            // not profiled
        //case CMSG_REQUEST_VEHICLE_SWITCH_SEAT:          // not profiled
        //case CMSG_REQUEST_VEHICLE_EXIT:                 // not profiled
        //case CMSG_EJECT_PASSENGER:                      // not profiled
        //case CMSG_ITEM_REFUND:                          // not profiled
        case CMSG_SOCKET_GEMS:                          // not profiled
        //case CMSG_WRAP_ITEM:                            // not profiled
        //case CMSG_REPORT_PVP_AFK:                       // not profiled
        {
            maxPacketCounterAllowed = 10;
            break;
        }

        case CMSG_CHAR_CREATE:                          //   7               5         3 async db queries
        case CMSG_CHAR_ENUM:                            //  22               3         2 async db queries
        //case CMSG_GM_TICKET_CREATE:                     //   1              25         1 async db query
        //case CMSG_GM_TICKET_UPDATETEXT:                 //   0              15         1 async db query
        //case CMSG_GM_TICKET_DELETETICKET:               //   1              25         1 async db query
        //case CMSG_GM_TICKET_RESPONSE_RESOLVE:           //   1              25         1 async db query
        //case CMSG_CALENDAR_UPDATE_EVENT:                // not profiled
        //case CMSG_CALENDAR_REMOVE_EVENT:                // not profiled
        //case CMSG_CALENDAR_COPY_EVENT:                  // not profiled
        //case CMSG_CALENDAR_EVENT_INVITE:                // not profiled
        //case CMSG_CALENDAR_EVENT_SIGNUP:                // not profiled
        //case CMSG_CALENDAR_EVENT_RSVP:                  // not profiled
        //case CMSG_CALENDAR_EVENT_REMOVE_INVITE:         // not profiled
        //case CMSG_CALENDAR_EVENT_MODERATOR_STATUS:      // not profiled
        //case CMSG_ARENA_TEAM_INVITE:                    // not profiled
        //case CMSG_ARENA_TEAM_ACCEPT:                    // not profiled
        //case CMSG_ARENA_TEAM_DECLINE:                   // not profiled
        //case CMSG_ARENA_TEAM_LEAVE:                     // not profiled
        //case CMSG_ARENA_TEAM_DISBAND:                   // not profiled
        //case CMSG_ARENA_TEAM_REMOVE:                    // not profiled
        //case CMSG_ARENA_TEAM_LEADER:                    // not profiled
        case CMSG_LOOT_METHOD:                          // not profiled
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
        //case CMSG_SET_GUILD_BANK_TEXT:                  // not profiled
        case CMSG_SAVE_GUILD_EMBLEM:                    // not profiled
        //case MSG_PETITION_RENAME:                       // not profiled
        //case MSG_TALENT_WIPE_CONFIRM:                   // not profiled
        case CMSG_SET_DUNGEON_DIFFICULTY:               // not profiled
        case CMSG_SET_RAID_DIFFICULTY:                  // not profiled
        //case MSG_PARTY_ASSIGNMENT:                      // not profiled
        //case CMSG_DO_READY_CHECK:                       // not profiled
        {
            maxPacketCounterAllowed = 3;
            break;
        }

        case CMSG_GET_ITEM_PURCHASE_DATA:               // not profiled
        {
            maxPacketCounterAllowed = PLAYER_SLOTS_COUNT;
            break;
        }*/
        default:
        {
            maxPacketCounterAllowed = 100;
            break;
        }
    }

    return maxPacketCounterAllowed;
}
