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
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "IpAddress.h"
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
#include "Realm.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "WardenWin.h"
#include "World.h"
#include "WorldSocket.h"

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
    std::string os, LocaleConstant locale, uint32 recruiter, bool isARecruiter):
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
    _os(os),
    _battlenetRequestToken(0),
    _warden(nullptr),
    _logoutTime(0),
    m_inQueue(false),
    m_playerLogout(false),
    m_playerRecentlyLogout(false),
    m_playerSave(false),
    m_sessionDbcLocale(sWorld->GetAvailableDbcLocale(locale)),
    m_sessionDbLocaleIndex(locale),
    m_latency(0),
    m_clientTimeDelay(0),
    _tutorialsChanged(TUTORIALS_FLAG_NONE),
    _filterAddonMessages(false),
    recruiterId(recruiter),
    isRecruiter(isARecruiter),
    _RBACData(nullptr),
    expireTime(60000), // 1 min after socket loss, session is deleted
    forceExit(false),
    m_currentBankerGUID(),
    _battlePetMgr(std::make_unique<BattlePetMgr>(this)),
    _collectionMgr(std::make_unique<CollectionMgr>(this))
{
    memset(_tutorials, 0, sizeof(_tutorials));

    if (sock)
    {
        m_Address = sock->GetRemoteIpAddress().to_string();
        ResetTimeOutTime(false);
        LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = %u;", GetAccountId());     // One-time query
    }

    m_Socket[CONNECTION_TYPE_REALM] = sock;
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

    delete _warden;
    delete _RBACData;

    ///- empty incoming packet queue
    WorldPacket* packet = nullptr;
    while (_recvQueue.next(packet))
        delete packet;

    LoginDatabase.PExecute("UPDATE account SET online = 0 WHERE id = %u;", GetAccountId());     // One-time query
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
    std::ostringstream ss;

    ss << "[Player: ";
    if (!m_playerLoading.IsEmpty())
        ss << "Logging in: " << m_playerLoading.ToString() << ", ";
    else if (_player)
        ss << _player->GetName() << ' ' << _player->GetGUID().ToString() << ", ";

    ss << "Account: " << GetAccountId() << "]";

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
            TC_LOG_ERROR("network.opcode", "Prevented sending of instance only opcode %u with connection type %u to %s", packet->GetOpcode(), uint32(packet->GetConnection()), GetPlayerInfo().c_str());
            return;
        }

        conIdx = packet->GetConnection();
    }

    if (!m_Socket[conIdx])
    {
        TC_LOG_ERROR("network.opcode", "Prevented sending of %s to non existent socket %u to %s", GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())).c_str(), uint32(conIdx), GetPlayerInfo().c_str());
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
        TC_LOG_DEBUG("misc", "Send all time packets count: " UI64FMTD " bytes: " UI64FMTD " avr.count/sec: %f avr.bytes/sec: %f time: %u", sendPacketCount, sendPacketBytes, float(sendPacketCount)/fullTime, float(sendPacketBytes)/fullTime, uint32(fullTime));
        TC_LOG_DEBUG("misc", "Send last min packets count: " UI64FMTD " bytes: " UI64FMTD " avr.count/sec: %f avr.bytes/sec: %f", sendLastPacketCount, sendLastPacketBytes, float(sendLastPacketCount)/minTime, float(sendLastPacketBytes)/minTime);

        lastTime = cur_time;
        sendLastPacketCount = 1;
        sendLastPacketBytes = packet->wpos();               // wpos is real written size
    }
#endif                                                      // !TRINITY_DEBUG

    sScriptMgr->OnPacketSend(this, *packet);

    TC_LOG_TRACE("network.opcode", "S->C: %s %s", GetPlayerInfo().c_str(), GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet->GetOpcode())).c_str());
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
    TC_LOG_ERROR("network.opcode", "Received unexpected opcode %s Status: %s Reason: %s from %s",
        GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str(), status, reason, GetPlayerInfo().c_str());
}

/// Logging helper for unexpected opcodes
void WorldSession::LogUnprocessedTail(WorldPacket const* packet)
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

    while (m_Socket[CONNECTION_TYPE_REALM] && _recvQueue.next(packet, updater))
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
                            requeuePackets.push_back(packet);
                            deletePacket = false;
                            TC_LOG_DEBUG("network", "Re-enqueueing packet with opcode %s with with status STATUS_LOGGEDIN. "
                                "Player is currently not in world yet.", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str());
                        }
                    }
                    else if (_player->IsInWorld() && AntiDOS.EvaluateOpcode(*packet, currentTime))
                    {
                        sScriptMgr->OnPacketReceive(this, *packet);
                        opHandle->Call(this, *packet);
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
        catch (WorldPackets::PacketArrayMaxCapacityException const& pamce)
        {
            TC_LOG_ERROR("network", "PacketArrayMaxCapacityException: %s while parsing %s from %s.",
                pamce.what(), GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet->GetOpcode())).c_str(), GetPlayerInfo().c_str());
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

    TC_METRIC_VALUE("processed_packets", processedPackets);

    _recvQueue.readd(requeuePackets.begin(), requeuePackets.end());

    if (m_Socket[CONNECTION_TYPE_REALM] && m_Socket[CONNECTION_TYPE_REALM]->IsOpen() && _warden)
        _warden->Update();

    ProcessQueryCallbacks();

    //check if we are safe to proceed with logout
    //logout procedure should happen only in World::UpdateSessions() method!!!
    if (updater.ProcessUnsafe())
    {
        ///- If necessary, log the player out
        if (ShouldLogOut(currentTime) && m_playerLoading.IsEmpty())
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
            _player->TeleportTo(_player->m_homebindMapId, _player->m_homebindX, _player->m_homebindY, _player->m_homebindZ, _player->GetOrientation());

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

        TC_METRIC_EVENT("player_events", "Logout", _player->GetName());

        //! Remove the player from the world
        // the player may not be in the world when logging out
        // e.g if he got disconnected during a transfer to another map
        // calls to GetMap in this case may cause crashes
        _player->CleanupsBeforeDelete();
        TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Logout Character:[%s] (%s) Level: %d, XP: %u/%u (%u left)",
            GetAccountId(), GetRemoteAddress().c_str(), _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), _player->getLevel(),
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
    TC_LOG_ERROR("network.opcode", "Received unhandled opcode %s from %s", GetOpcodeNameForLogging(null.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::Handle_EarlyProccess(WorldPackets::Null& null)
{
    TC_LOG_ERROR("network.opcode", "Received opcode %s that must be processed in WorldSocket::OnRead from %s"
        , GetOpcodeNameForLogging(null.GetOpcode()).c_str(), GetPlayerInfo().c_str());
}

void WorldSession::SendConnectToInstance(WorldPackets::Auth::ConnectToSerial serial)
{
    boost::system::error_code ignored_error;
    boost::asio::ip::address instanceAddress = realm.GetAddressForClient(Trinity::Net::make_address(GetRemoteAddress(), ignored_error));

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

void WorldSession::SaveTutorialsData(CharacterDatabaseTransaction& trans)
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

bool WorldSession::IsAddonRegistered(const std::string& prefix) const
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

    if (_realmAccountLoginCallback.valid() && _realmAccountLoginCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready &&
        _accountLoginCallback.valid() && _accountLoginCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        InitializeSessionCallback(static_cast<LoginDatabaseQueryHolder*>(_realmAccountLoginCallback.get()),
            static_cast<CharacterDatabaseQueryHolder*>(_accountLoginCallback.get()));

    //! HandlePlayerLoginOpcode
    if (_charLoginCallback.valid() && _charLoginCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        HandlePlayerLogin(reinterpret_cast<LoginQueryHolder*>(_charLoginCallback.get()));

    if (_charEnumCallback.valid() && _charEnumCallback.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        HandleCharEnum(static_cast<CharacterDatabaseQueryHolder*>(_charEnumCallback.get()));
}

TransactionCallback& WorldSession::AddTransactionCallback(TransactionCallback&& callback)
{
    return _transactionCallbacks.AddCallback(std::move(callback));
}

bool WorldSession::CanAccessAlliedRaces() const
{
    return GetAccountExpansion() >= EXPANSION_BATTLE_FOR_AZEROTH;
}

void WorldSession::InitWarden(SessionKey const& k)
{
    if (_os == "Win")
    {
        _warden = new WardenWin();
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

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: %u, Name: %s, realmId: %d, secLevel: %u]",
        id, _accountName.c_str(), realm.Id.Realm, secLevel);

    _RBACData = new rbac::RBACData(id, _accountName, realm.Id.Realm, secLevel);
    _RBACData->LoadFromDB();
}

QueryCallback WorldSession::LoadPermissionsAsync()
{
    uint32 id = GetAccountId();
    uint8 secLevel = GetSecurity();

    TC_LOG_DEBUG("rbac", "WorldSession::LoadPermissions [AccountId: %u, Name: %s, realmId: %d, secLevel: %u]",
        id, _accountName.c_str(), realm.Id.Realm, secLevel);

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

        return ok;
    }
};

void WorldSession::InitializeSession()
{
    AccountInfoQueryHolderPerRealm* realmHolder = new AccountInfoQueryHolderPerRealm();
    if (!realmHolder->Initialize(GetAccountId(), GetBattlenetAccountId()))
    {
        delete realmHolder;
        SendAuthResponse(ERROR_INTERNAL, false);
        return;
    }

    AccountInfoQueryHolder* holder = new AccountInfoQueryHolder();
    if (!holder->Initialize(GetAccountId(), GetBattlenetAccountId()))
    {
        delete realmHolder;
        delete holder;
        SendAuthResponse(ERROR_INTERNAL, false);
        return;
    }

    _realmAccountLoginCallback = CharacterDatabase.DelayQueryHolder(realmHolder);
    _accountLoginCallback = LoginDatabase.DelayQueryHolder(holder);
}

void WorldSession::InitializeSessionCallback(LoginDatabaseQueryHolder* realmHolder, CharacterDatabaseQueryHolder* holder)
{
    LoadAccountData(realmHolder->GetPreparedResult(AccountInfoQueryHolderPerRealm::GLOBAL_ACCOUNT_DATA), GLOBAL_CACHE_MASK);
    LoadTutorialsData(realmHolder->GetPreparedResult(AccountInfoQueryHolderPerRealm::TUTORIALS));
    _collectionMgr->LoadAccountToys(holder->GetPreparedResult(AccountInfoQueryHolder::GLOBAL_ACCOUNT_TOYS));
    _collectionMgr->LoadAccountHeirlooms(holder->GetPreparedResult(AccountInfoQueryHolder::GLOBAL_ACCOUNT_HEIRLOOMS));
    _collectionMgr->LoadAccountMounts(holder->GetPreparedResult(AccountInfoQueryHolder::MOUNTS));
    _collectionMgr->LoadAccountItemAppearances(holder->GetPreparedResult(AccountInfoQueryHolder::ITEM_APPEARANCES), holder->GetPreparedResult(AccountInfoQueryHolder::ITEM_FAVORITE_APPEARANCES));

    if (!m_inQueue)
        SendAuthResponse(ERROR_OK, false);
    else
        SendAuthWaitQue(0);

    SetInQueue(false);
    ResetTimeOutTime(false);

    SendSetTimeZoneInformation();
    SendFeatureSystemStatusGlueScreen();
    SendClientCacheVersion(sWorld->getIntConfig(CONFIG_CLIENTCACHE_VERSION));
    SendAvailableHotfixes();
    SendTutorialsData();

    if (PreparedQueryResult characterCountsResult = holder->GetPreparedResult(AccountInfoQueryHolder::GLOBAL_REALM_CHARACTER_COUNTS))
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

    _battlePetMgr->LoadFromDB(holder->GetPreparedResult(AccountInfoQueryHolder::BATTLE_PETS),
                              holder->GetPreparedResult(AccountInfoQueryHolder::BATTLE_PET_SLOTS));

    delete realmHolder;
    delete holder;
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
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realm.Id.Realm);

    return hasPermission;
}

void WorldSession::InvalidateRBACData()
{
    TC_LOG_DEBUG("rbac", "WorldSession::Invalidaterbac::RBACData [AccountId: %u, Name: %s, realmId: %d]",
                   _RBACData->GetId(), _RBACData->GetName().c_str(), realm.Id.Realm);
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

    TC_LOG_WARN("network", "AntiDOS: Account %u, IP: %s, Ping: %u, Character: %s, flooding packet (opc: %s (0x%X), count: %u)",
        Session->GetAccountId(), Session->GetRemoteAddress().c_str(), Session->GetLatency(), Session->GetPlayerName().c_str(),
        opcodeTable[static_cast<OpcodeClient>(p.GetOpcode())]->Name, p.GetOpcode(), packetCounter.amountCounter);

    switch (_policy)
    {
        case POLICY_LOG:
            return true;
        case POLICY_KICK:
        {
            TC_LOG_WARN("network", "AntiDOS: Player kicked!");
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
            TC_LOG_WARN("network", "AntiDOS: Player automatically banned for %u seconds.", duration);
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
    {
        // CPU usage sending 2000 packets/second on a 3.70 GHz 4 cores on Win x64
        //                                              [% CPU mysqld]   [%CPU worldserver RelWithDebInfo]
        case CMSG_PLAYER_LOGIN:                         //   0               0.5
        case CMSG_QUERY_PLAYER_NAME:                    //   0               1
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
        case CMSG_REQUEST_PARTY_MEMBER_STATS:           //   0               1.5
        case CMSG_QUEST_GIVER_COMPLETE_QUEST:           //   0               1.5
        case CMSG_SET_ACTION_BUTTON:                    //   0               1.5
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
        case CMSG_CALENDAR_ADD_EVENT:                   //  21              10         2 async db query
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
