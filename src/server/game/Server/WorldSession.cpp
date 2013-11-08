/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "WorldSocket.h"                                    // must be first to make ACE happy with ACE includes in it
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

namespace {

std::string const DefaultPlayerName = "<none>";

} // namespace

bool MapSessionFilter::Process(WorldPacket* packet)
{
    OpcodeHandler const& opHandle = opcodeTable[packet->GetOpcode()];

    //let's check if our opcode can be really processed in Map::Update()
    if (opHandle.packetProcessing == PROCESS_INPLACE)
        return true;

    //we do not process thread-unsafe packets
    if (opHandle.packetProcessing == PROCESS_THREADUNSAFE)
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
    OpcodeHandler const& opHandle = opcodeTable[packet->GetOpcode()];
    //check if packet handler is supposed to be safe
    if (opHandle.packetProcessing == PROCESS_INPLACE)
        return true;

    //thread-unsafe packets should be processed in World::UpdateSessions()
    if (opHandle.packetProcessing == PROCESS_THREADUNSAFE)
        return true;

    //no player attached? -> our client! ^^
    Player* player = m_pSession->GetPlayer();
    if (!player)
        return true;

    //lets process all packets for non-in-the-world player
    return (player->IsInWorld() == false);
}

/// WorldSession constructor
WorldSession::WorldSession(uint32 id, WorldSocket* sock, AccountTypes sec, uint8 expansion, time_t mute_time, LocaleConstant locale, uint32 recruiter, bool isARecruiter):
    m_muteTime(mute_time),
    m_timeOutTime(0),
    AntiDOS(this),
    _player(NULL),
    m_Socket(sock),
    _security(sec),
    _accountId(id),
    m_expansion(expansion),
    _warden(NULL),
    _logoutTime(0),
    m_inQueue(false),
    m_playerLoading(false),
    m_playerLogout(false),
    m_playerRecentlyLogout(false),
    m_playerSave(false),
    m_sessionDbcLocale(sWorld->GetAvailableDbcLocale(locale)),
    m_sessionDbLocaleIndex(locale),
    m_latency(0),
    m_clientTimeDelay(0),
    m_TutorialsChanged(false),
    recruiterId(recruiter),
    isRecruiter(isARecruiter),
    timeLastWhoCommand(0),
    _RBACData(NULL)
{
    if (sock)
    {
        m_Address = sock->GetRemoteAddress();
        sock->AddReference();
        ResetTimeOutTime();
        LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = %u;", GetAccountId());     // One-time query
    }

    InitializeQueryCallbackParameters();
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
        m_Socket->RemoveReference();
        m_Socket = NULL;
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

    ss << "[Player: " << GetPlayerName()
       << " (Guid: " << (_player != NULL ? _player->GetGUID() : 0)
       << ", Account: " << GetAccountId() << ")]";

    return ss.str();
}

/// Get player guid if available. Use for logging purposes only
uint32 WorldSession::GetGuidLow() const
{
    return GetPlayer() ? GetPlayer()->GetGUIDLow() : 0;
}

/// Send a packet to the client
void WorldSession::SendPacket(WorldPacket const* packet)
{
    if (!m_Socket)
        return;

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

    if (m_Socket->SendPacket(*packet) == -1)
        m_Socket->CloseSocket();
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
        GetOpcodeNameForLogging(packet->GetOpcode()).c_str(), status, reason, GetPlayerInfo().c_str());
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnprocessedTail(WorldPacket* packet)
{
    if (!sLog->ShouldLog("network.opcode", LOG_LEVEL_TRACE) || packet->rpos() >= packet->wpos())
        return;

    TC_LOG_TRACE("network.opcode", "Unprocessed tail data (read stop at %u from %u) Opcode %s from %s",
        uint32(packet->rpos()), uint32(packet->wpos()), GetOpcodeNameForLogging(packet->GetOpcode()).c_str(), GetPlayerInfo().c_str());
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
        m_Socket->CloseSocket();

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

    while (m_Socket && !m_Socket->IsClosed() &&
            !_recvQueue.empty() && _recvQueue.peek(true) != firstDelayedPacket &&
            _recvQueue.next(packet, updater))
    {
        if (!AntiDOS.EvaluateOpcode(*packet))
        {
            KickPlayer();
        }
        else if (packet->GetOpcode() >= NUM_MSG_TYPES)
        {
            TC_LOG_ERROR("network.opcode", "Received non-existed opcode %s from %s", GetOpcodeNameForLogging(packet->GetOpcode()).c_str()
                            , GetPlayerInfo().c_str());
            sScriptMgr->OnUnknownPacketReceive(m_Socket, WorldPacket(*packet));
        }
        else
        {
            OpcodeHandler &opHandle = opcodeTable[packet->GetOpcode()];
            try
            {
                switch (opHandle.status)
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
                                    "Player is currently not in world yet.", GetOpcodeNameForLogging(packet->GetOpcode()).c_str());
                            }
                        }
                        else if (_player->IsInWorld())
                        {
                            sScriptMgr->OnPacketReceive(m_Socket, WorldPacket(*packet));
                            (this->*opHandle.handler)(*packet);
                            LogUnprocessedTail(packet);
                        }
                        // lag can cause STATUS_LOGGEDIN opcodes to arrive after the player started a transfer
                        break;
                    case STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT:
                        if (!_player && !m_playerRecentlyLogout && !m_playerLogout) // There's a short delay between _player = null and m_playerRecentlyLogout = true during logout
                            LogUnexpectedOpcode(packet, "STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT",
                                "the player has not logged in yet and not recently logout");
                        else
                        {
                            // not expected _player or must checked in packet handler
                            sScriptMgr->OnPacketReceive(m_Socket, WorldPacket(*packet));
                            (this->*opHandle.handler)(*packet);
                            LogUnprocessedTail(packet);
                        }
                        break;
                    case STATUS_TRANSFER:
                        if (!_player)
                            LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player has not logged in yet");
                        else if (_player->IsInWorld())
                            LogUnexpectedOpcode(packet, "STATUS_TRANSFER", "the player is still in world");
                        else
                        {
                            sScriptMgr->OnPacketReceive(m_Socket, WorldPacket(*packet));
                            (this->*opHandle.handler)(*packet);
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

                        sScriptMgr->OnPacketReceive(m_Socket, WorldPacket(*packet));
                        (this->*opHandle.handler)(*packet);
                        LogUnprocessedTail(packet);
                        break;
                    case STATUS_NEVER:
                        TC_LOG_ERROR("network.opcode", "Received not allowed opcode %s from %s", GetOpcodeNameForLogging(packet->GetOpcode()).c_str()
                            , GetPlayerInfo().c_str());
                        break;
                    case STATUS_UNHANDLED:
                        TC_LOG_DEBUG("network.opcode", "Received not handled opcode %s from %s", GetOpcodeNameForLogging(packet->GetOpcode()).c_str()
                            , GetPlayerInfo().c_str());
                        break;
                }
            }
            catch (ByteBufferException const&)
            {
                TC_LOG_ERROR("misc", "WorldSession::Update ByteBufferException occured while parsing a packet (opcode: %u) from client %s, accountid=%i. Skipped packet.",
                        packet->GetOpcode(), GetRemoteAddress().c_str(), GetAccountId());
                packet->hexlike();
            }
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

    if (m_Socket && !m_Socket->IsClosed() && _warden)
        _warden->Update();

    ProcessQueryCallbacks();

    //check if we are safe to proceed with logout
    //logout procedure should happen only in World::UpdateSessions() method!!!
    if (updater.ProcessLogout())
    {
        time_t currTime = time(NULL);
        ///- If necessary, log the player out
        if (ShouldLogOut(currTime) && !m_playerLoading)
            LogoutPlayer(true);

        if (m_Socket && GetPlayer() && _warden)
            _warden->Update();

        ///- Cleanup socket pointer if need
        if (m_Socket && m_Socket->IsClosed())
        {
            m_Socket->RemoveReference();
            m_Socket = NULL;
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
        HandleMoveWorldportAckOpcode();

    m_playerLogout = true;
    m_playerSave = save;

    if (_player)
    {
        if (uint64 lguid = _player->GetLootGUID())
            DoLootRelease(lguid);

        ///- If the player just died before logging out, make him appear as a ghost
        //FIXME: logout must be delayed in case lost connection with client in time of combat
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
                _player->SetUInt64Value(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), 0);
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
        if (_player->GetGroup() && !_player->GetGroup()->isRaidGroup() && m_Socket)
            _player->RemoveFromGroup();

        //! Send update to group and reset stored max enchanting level
        if (_player->GetGroup())
        {
            _player->GetGroup()->SendUpdate();
            _player->GetGroup()->ResetMaxEnchantingLevel();
        }

        //! Broadcast a logout message to the player's friends
        sSocialMgr->SendFriendStatus(_player, FRIEND_OFFLINE, _player->GetGUIDLow(), true);
        sSocialMgr->RemovePlayerSocial(_player->GetGUIDLow());

        //! Call script hook before deletion
        sScriptMgr->OnPlayerLogout(_player);

        //! Remove the player from the world
        // the player may not be in the world when logging out
        // e.g if he got disconnected during a transfer to another map
        // calls to GetMap in this case may cause crashes
        _player->CleanupsBeforeDelete();
        TC_LOG_INFO("entities.player.character", "Account: %d (IP: %s) Logout Character:[%s] (GUID: %u) Level: %d",
            GetAccountId(), GetRemoteAddress().c_str(), _player->GetName().c_str(), _player->GetGUIDLow(), _player->getLevel());
        if (Map* _map = _player->FindMap())
            _map->RemovePlayerFromMap(_player, true);

        SetPlayer(NULL); //! Pointer already deleted during RemovePlayerFromMap

        //! Send the 'logout complete' packet to the client
        //! Client will respond by sending 3x CMSG_CANCEL_TRADE, which we currently dont handle
        WorldPacket data(SMSG_LOGOUT_COMPLETE, 0);
        SendPacket(&data);
        TC_LOG_DEBUG("network", "SESSION: Sent SMSG_LOGOUT_COMPLETE Message");

        //! Since each account can only have one online character at any given time, ensure all characters for active account are marked as offline
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ACCOUNT_ONLINE);
        stmt->setUInt32(0, GetAccountId());
        CharacterDatabase.Execute(stmt);
    }

    m_playerLogout = false;
    m_playerSave = false;
    m_playerRecentlyLogout = true;
    AntiDOS.AllowOpcode(CMSG_CHAR_ENUM, true);
    LogoutRequest(0);
}

/// Kick a player out of the World
void WorldSession::KickPlayer()
{
    if (m_Socket)
        m_Socket->CloseSocket();
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

const char *WorldSession::GetTrinityString(int32 entry) const
{
    return sObjectMgr->GetTrinityString(entry, GetSessionDbLocaleIndex());
}

void WorldSession::Handle_NULL(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received unhandled opcode %s from %s"
        , GetOpcodeNameForLogging(recvPacket.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_EarlyProccess(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received opcode %s that must be processed in WorldSocket::OnRead from %s"
        , GetOpcodeNameForLogging(recvPacket.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_ServerSide(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received server-side opcode %s from %s"
        , GetOpcodeNameForLogging(recvPacket.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_Deprecated(WorldPacket& recvPacket)
{
    TC_LOG_ERROR("network.opcode", "Received deprecated opcode %s from %s"
        , GetOpcodeNameForLogging(recvPacket.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::SendAuthWaitQue(uint32 position)
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
            m_accountData[i] = AccountData();

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

        m_accountData[type].Time = time_t(fields[1].GetUInt32());
        m_accountData[type].Data = fields[2].GetString();
    }
    while (result->NextRow());
}

void WorldSession::SetAccountData(AccountDataType type, time_t tm, std::string const& data)
{
    uint32 id = 0;
    uint32 index = 0;
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(index);
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
    data << uint32(time(NULL));                             // Server time
    data << uint8(1);
    data << uint32(mask);                                   // type mask
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        if (mask & (1 << i))
            data << uint32(GetAccountData(AccountDataType(i))->Time);// also unix time
    SendPacket(&data);
}

void WorldSession::LoadTutorialsData()
{
    memset(m_Tutorials, 0, sizeof(uint32) * MAX_ACCOUNT_TUTORIAL_VALUES);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_TUTORIALS);
    stmt->setUInt32(0, GetAccountId());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
            m_Tutorials[i] = (*result)[i].GetUInt32();

    m_TutorialsChanged = false;
}

void WorldSession::SendTutorialsData()
{
    WorldPacket data(SMSG_TUTORIAL_FLAGS, 4 * MAX_ACCOUNT_TUTORIAL_VALUES);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        data << m_Tutorials[i];
    SendPacket(&data);
}

void WorldSession::SaveTutorialsData(SQLTransaction &trans)
{
    if (!m_TutorialsChanged)
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_HAS_TUTORIALS);
    stmt->setUInt32(0, GetAccountId());
    bool hasTutorials = !CharacterDatabase.Query(stmt).null();
    // Modify data in DB
    stmt = CharacterDatabase.GetPreparedStatement(hasTutorials ? CHAR_UPD_TUTORIALS : CHAR_INS_TUTORIALS);
    for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
        stmt->setUInt32(i, m_Tutorials[i]);
    stmt->setUInt32(MAX_ACCOUNT_TUTORIAL_VALUES, GetAccountId());
    trans->Append(stmt);

    m_TutorialsChanged = false;
}

void WorldSession::ReadMovementInfo(WorldPacket &data, MovementInfo* mi)
{
    data >> mi->flags;
    data >> mi->flags2;
    data >> mi->time;
    data >> mi->pos.PositionXYZOStream();

    if (mi->HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        data.readPackGUID(mi->transport.guid);

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
            TC_LOG_DEBUG("entities.unit", "WorldSession::ReadMovementInfo: Violation of MovementFlags found (%s). " \
                "MovementFlags: %u, MovementFlags2: %u for player GUID: %u. Mask %u will be removed.", \
                STRINGIZE(check), mi->GetMovementFlags(), mi->GetExtraMovementFlags(), GetPlayer()->GetGUIDLow(), maskToRemove); \
            mi->RemoveMovementFlag((maskToRemove)); \
        } \
    }
    #else
    #define REMOVE_VIOLATING_FLAGS(check, maskToRemove) \
        if (check) \
            mi->RemoveMovementFlag((maskToRemove));
    #endif


    /*! This must be a packet spoofing attempt. MOVEMENTFLAG_ROOT sent from the client is not valid
        in conjunction with any of the moving movement flags such as MOVEMENTFLAG_FORWARD.
        It will freeze clients that receive this player's movement info.
    */
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ROOT),
        MOVEMENTFLAG_ROOT);

    //! Cannot hover without SPELL_AURA_HOVER
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_HOVER) && !GetPlayer()->HasAuraType(SPELL_AURA_HOVER),
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

    //! Cannot walk on water without SPELL_AURA_WATER_WALK
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_WATERWALKING) && !GetPlayer()->HasAuraType(SPELL_AURA_WATER_WALK),
        MOVEMENTFLAG_WATERWALKING);

    //! Cannot feather fall without SPELL_AURA_FEATHER_FALL
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FALLING_SLOW) && !GetPlayer()->HasAuraType(SPELL_AURA_FEATHER_FALL),
        MOVEMENTFLAG_FALLING_SLOW);

    /*! Cannot fly if no fly auras present. Exception is being a GM.
        Note that we check for account level instead of Player::IsGameMaster() because in some
        situations it may be feasable to use .gm fly on as a GM without having .gm on,
        e.g. aerial combat.
    */

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY) && GetSecurity() == SEC_PLAYER &&
        !GetPlayer()->m_mover->HasAuraType(SPELL_AURA_FLY) &&
        !GetPlayer()->m_mover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED),
        MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY);

    //! Cannot fly and fall at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_DISABLE_GRAVITY) && mi->HasMovementFlag(MOVEMENTFLAG_FALLING),
        MOVEMENTFLAG_FALLING);

    #undef REMOVE_VIOLATING_FLAGS
}

void WorldSession::WriteMovementInfo(WorldPacket* data, MovementInfo* mi)
{
    data->appendPackGUID(mi->guid);

    *data << mi->flags;
    *data << mi->flags2;
    *data << mi->time;
    *data << mi->pos.PositionXYZOStream();

    if (mi->HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
       data->appendPackGUID(mi->transport.guid);

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

void WorldSession::ReadAddonsInfo(WorldPacket &data)
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
    uint8 addonPublicKey[256] =
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

    for (AddonsList::iterator itr = m_addonsList.begin(); itr != m_addonsList.end(); ++itr)
    {
        data << uint8(itr->State);

        uint8 crcpub = itr->UsePublicKeyOrCRC;
        data << uint8(crcpub);
        if (crcpub)
        {
            uint8 usepk = (itr->CRC != STANDARD_ADDON_CRC); // If addon is Standard addon CRC
            data << uint8(usepk);
            if (usepk)                                      // if CRC is wrong, add public key (client need it)
            {
                TC_LOG_INFO("misc", "ADDON: CRC (0x%x) for addon %s is wrong (does not match expected 0x%x), sending pubkey",
                    itr->CRC, itr->Name.c_str(), STANDARD_ADDON_CRC);

                data.append(addonPublicKey, sizeof(addonPublicKey));
            }

            data << uint32(0);                              /// @todo Find out the meaning of this.
        }

        data << uint8(0);       // uses URL
        //if (usesURL)
        //    data << uint8(0); // URL
    }

    m_addonsList.clear();

    AddonMgr::BannedAddonList const* bannedAddons = AddonMgr::GetBannedAddons();
    data << uint32(bannedAddons->size());
    for (AddonMgr::BannedAddonList::const_iterator itr = bannedAddons->begin(); itr != bannedAddons->end(); ++itr)
    {
        data << uint32(itr->Id);
        data.append(itr->NameMD5, sizeof(itr->NameMD5));
        data.append(itr->VersionMD5, sizeof(itr->VersionMD5));
        data << uint32(itr->Timestamp);
        data << uint32(1);  // IsBanned
    }

    SendPacket(&data);
}

void WorldSession::SetPlayer(Player* player)
{
    _player = player;

    // set m_GUID that can be used while player loggined and later until m_playerRecentlyLogout not reset
    if (_player)
        m_GUIDLow = _player->GetGUIDLow();
}

void WorldSession::InitializeQueryCallbackParameters()
{
    // Callback parameters that have pointers in them should be properly
    // initialized to NULL here.
    _charCreateCallback.SetParam(NULL);
}

void WorldSession::ProcessQueryCallbacks()
{
    PreparedQueryResult result;

    //! HandleCharEnumOpcode
    if (_charEnumCallback.ready())
    {
        _charEnumCallback.get(result);
        HandleCharEnum(result);
        _charEnumCallback.cancel();
    }

    if (_charCreateCallback.IsReady())
    {
        _charCreateCallback.GetResult(result);
        HandleCharCreateCallback(result, _charCreateCallback.GetParam());
        // Don't call FreeResult() here, the callback handler will do that depending on the events in the callback chain
    }

    //! HandlePlayerLoginOpcode
    if (_charLoginCallback.ready())
    {
        SQLQueryHolder* param;
        _charLoginCallback.get(param);
        HandlePlayerLogin((LoginQueryHolder*)param);
        _charLoginCallback.cancel();
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
        std::string param = _charRenameCallback.GetParam();
        _charRenameCallback.GetResult(result);
        HandleChangePlayerNameOpcodeCallBack(result, param);
        _charRenameCallback.FreeResult();
    }

    //- HandleCharAddIgnoreOpcode
    if (_addIgnoreCallback.ready())
    {
        _addIgnoreCallback.get(result);
        HandleAddIgnoreOpcodeCallBack(result);
        _addIgnoreCallback.cancel();
    }

    //- SendStabledPet
    if (_sendStabledPetCallback.IsReady())
    {
        uint64 param = _sendStabledPetCallback.GetParam();
        _sendStabledPetCallback.GetResult(result);
        SendStablePetCallback(result, param);
        _sendStabledPetCallback.FreeResult();
    }

    //- HandleStablePet
    if (_stablePetCallback.ready())
    {
        _stablePetCallback.get(result);
        HandleStablePetCallback(result);
        _stablePetCallback.cancel();
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

    _RBACData = new rbac::RBACData(id, name, realmID, secLevel);
    _RBACData->LoadFromDB();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: %u, Name: %s, realmId: %d, secLevel: %u]",
                   id, name.c_str(), realmID, secLevel);
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
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realmID);

    return hasPermission;
}

void WorldSession::InvalidateRBACData()
{
    TC_LOG_DEBUG("rbac", "WorldSession::Invalidaterbac::RBACData [AccountId: %u, Name: %s, realmId: %d]",
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realmID);
    delete _RBACData;
    _RBACData = NULL;
}

bool WorldSession::DosProtection::EvaluateOpcode(WorldPacket& p) const
{
    if (IsOpcodeAllowed(p.GetOpcode()))
        return true;

    // Opcode not allowed, let the punishment begin
    TC_LOG_INFO("network", "AntiDOS: Account %u, IP: %s, sent unacceptable packet (opc: %u, size: %u)",
        Session->GetAccountId(), Session->GetRemoteAddress().c_str(), p.GetOpcode(), (uint32)p.size());

    switch (_policy)
    {
        case POLICY_LOG:
            return true;
        case POLICY_KICK:
            TC_LOG_INFO("network", "AntiDOS: Player kicked!");
            return false;
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

            return false;
        }
        default: // invalid policy
            return true;
    }
}
