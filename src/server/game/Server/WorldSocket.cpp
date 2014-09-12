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

#include "WorldSocket.h"
#include "BigNumber.h"
#include "Opcodes.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SHA1.h"
#include "PacketLog.h"
#include "BattlenetAccountMgr.h"
#include <memory>

using boost::asio::ip::tcp;

std::string const WorldSocket::ServerConnectionInitialize("WORLD OF WARCRAFT CONNECTION - SERVER TO CLIENT");

std::string const WorldSocket::ClientConnectionInitialize("WORLD OF WARCRAFT CONNECTION - CLIENT TO SERVER");


WorldSocket::WorldSocket(tcp::socket&& socket)
    : Socket(std::move(socket)), _authSeed(rand32()), _OverSpeedPings(0), _worldSession(nullptr), _initialized(false)
{
    _headerBuffer.Resize(sizeof(ClientPktHeader));
}

void WorldSocket::Start()
{
    AsyncRead();

    MessageBuffer initializer;
    ServerPktHeader header(ServerConnectionInitialize.size(), 0);
    initializer.Write(header.header, header.getHeaderLength() - 2);
    initializer.Write((void*)ServerConnectionInitialize.c_str(), ServerConnectionInitialize.length());

    std::unique_lock<std::mutex> dummy(_writeLock, std::defer_lock);
    QueuePacket(std::move(initializer), dummy);
}

void WorldSocket::HandleSendAuthSession()
{
    WorldPacket packet(SMSG_AUTH_CHALLENGE, 37);
    BigNumber seed1;
    seed1.SetRand(16 * 8);
    packet.append(seed1.AsByteArray(16).get(), 16);               // new encryption seeds

    BigNumber seed2;
    seed2.SetRand(16 * 8);
    packet.append(seed2.AsByteArray(16).get(), 16);               // new encryption seeds

    packet << uint32(_authSeed);
    packet << uint8(1);
    SendPacket(packet);
}

void WorldSocket::ReadHandler()
{
    if (!IsOpen())
        return;

    MessageBuffer& packet = GetReadBuffer();
    while (packet.GetActiveSize() > 0)
    {
        if (_headerBuffer.GetRemainingSpace() > 0)
        {
            // need to receive the header
            std::size_t readHeaderSize = std::min(packet.GetActiveSize(), _headerBuffer.GetRemainingSpace());
            _headerBuffer.Write(packet.GetReadPointer(), readHeaderSize);
            packet.ReadCompleted(readHeaderSize);

            if (_headerBuffer.GetRemainingSpace() > 0)
            {
                // Couldn't receive the whole header this time.
                ASSERT(packet.GetActiveSize() == 0);
                break;
            }

            // We just received nice new header
            if (!ReadHeaderHandler())
                return;
        }

        // We have full read header, now check the data payload
        if (_packetBuffer.GetRemainingSpace() > 0)
        {
            // need more data in the payload
            std::size_t readDataSize = std::min(packet.GetActiveSize(), _packetBuffer.GetRemainingSpace());
            _packetBuffer.Write(packet.GetReadPointer(), readDataSize);
            packet.ReadCompleted(readDataSize);

            if (_packetBuffer.GetRemainingSpace() > 0)
            {
                // Couldn't receive the whole data this time.
                ASSERT(packet.GetActiveSize() == 0);
                break;
            }
        }

        // just received fresh new payload
        if (!ReadDataHandler())
            return;

        _headerBuffer.Reset();
    }

    AsyncRead();
}

bool WorldSocket::ReadHeaderHandler()
{
    ASSERT(_headerBuffer.GetActiveSize() == sizeof(ClientPktHeader));

    _authCrypt.DecryptRecv(_headerBuffer.GetReadPointer(), sizeof(ClientPktHeader));

    ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());
    EndianConvertReverse(header->size);
    EndianConvert(header->cmd);

    if (!header->IsValidSize() || !header->IsValidOpcode())
    {
        if (_worldSession)
        {
            Player* player = _worldSession->GetPlayer();
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client (account: %u, char [GUID: %u, name: %s]) sent malformed packet (size: %hu, cmd: %u)",
                _worldSession->GetAccountId(), player ? player->GetGUIDLow() : 0, player ? player->GetName().c_str() : "<none>", header->size, header->cmd);
        }
        else
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client %s sent malformed packet (size: %hu, cmd: %u)",
                GetRemoteIpAddress().to_string().c_str(), header->size, header->cmd);

        CloseSocket();
        return false;
    }

    header->size -= sizeof(header->cmd);
    _packetBuffer.Resize(header->size);
    return true;
}

bool WorldSocket::ReadDataHandler()
{
    if (_initialized)
    {
        ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());

        Opcodes opcode = PacketFilter::DropHighBytes(Opcodes(header->cmd));

        std::string opcodeName = GetOpcodeNameForLogging(opcode);

        WorldPacket packet(opcode, std::move(_packetBuffer));

        if (sPacketLog->CanLogPacket())
            sPacketLog->LogPacket(packet, CLIENT_TO_SERVER, GetRemoteIpAddress(), GetRemotePort());

        TC_LOG_TRACE("network.opcode", "C->S: %s %s", (_worldSession ? _worldSession->GetPlayerInfo() : GetRemoteIpAddress().to_string()).c_str(), opcodeName.c_str());

        switch (opcode)
        {
            case CMSG_PING:
                HandlePing(packet);
                break;
            case CMSG_AUTH_SESSION:
                if (_worldSession)
                {
                    TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming: received duplicate CMSG_AUTH_SESSION from %s", _worldSession->GetPlayerInfo().c_str());
                    break;
                }

                HandleAuthSession(packet);
                break;
            case CMSG_KEEP_ALIVE:
                TC_LOG_DEBUG("network", "%s", opcodeName.c_str());
                sScriptMgr->OnPacketReceive(_worldSession, packet);
                break;
            case CMSG_LOG_DISCONNECT:
                packet.rfinish();   // contains uint32 disconnectReason;
                TC_LOG_DEBUG("network", "%s", opcodeName.c_str());
                sScriptMgr->OnPacketReceive(_worldSession, packet);
                return true;
            case CMSG_ENABLE_NAGLE:
            {
                TC_LOG_DEBUG("network", "%s", opcodeName.c_str());
                sScriptMgr->OnPacketReceive(_worldSession, packet);
                if (_worldSession)
                    _worldSession->HandleEnableNagleAlgorithm();
                break;
            }
            default:
            {
                if (!_worldSession)
                {
                    TC_LOG_ERROR("network.opcode", "ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                    CloseSocket();
                    return false;
                }

                // Our Idle timer will reset on any non PING opcodes.
                // Catches people idling on the login screen and any lingering ingame connections.
                _worldSession->ResetTimeOutTime();

                // Copy the packet to the heap before enqueuing
                _worldSession->QueuePacket(new WorldPacket(std::move(packet)));
                break;
            }
        }
    }
    else
    {
        ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());

        std::string initializer(reinterpret_cast<char const*>(_packetBuffer.GetReadPointer()), header->size);
        if (initializer != ClientConnectionInitialize)
        {
            CloseSocket();
            return false;
        }

        _initialized = true;
        HandleSendAuthSession();
    }

    return true;
}

void WorldSocket::SendPacket(WorldPacket& packet)
{
    if (!IsOpen())
        return;

    if (sPacketLog->CanLogPacket())
        sPacketLog->LogPacket(packet, SERVER_TO_CLIENT, GetRemoteIpAddress(), GetRemotePort());

    if (_worldSession && packet.size() > 0x400 && !packet.IsCompressed())
        packet.Compress(_worldSession->GetCompressionStream());

    TC_LOG_TRACE("network.opcode", "S->C: %s %s", (_worldSession ? _worldSession->GetPlayerInfo() : GetRemoteIpAddress().to_string()).c_str(), GetOpcodeNameForLogging(packet.GetOpcode()).c_str());

    ServerPktHeader header(packet.size() + 2, packet.GetOpcode());

    std::unique_lock<std::mutex> guard(_writeLock);

    _authCrypt.EncryptSend(header.header, header.getHeaderLength());

#ifndef BOOST_ASIO_HAS_IOCP
    if (_writeQueue.empty() && _writeBuffer.GetRemainingSpace() >= header.getHeaderLength() + packet.size())
    {
        _writeBuffer.Write(header.header, header.getHeaderLength());
        if (!packet.empty())
            _writeBuffer.Write(packet.contents(), packet.size());
    }
    else
#endif
    {
        MessageBuffer buffer(header.getHeaderLength() + packet.size());
        buffer.Write(header.header, header.getHeaderLength());
        if (!packet.empty())
            buffer.Write(packet.contents(), packet.size());

        QueuePacket(std::move(buffer), guard);
    }
}

void WorldSocket::HandleAuthSession(WorldPacket& recvPacket)
{
    uint8 digest[20];
    uint32 clientSeed;
    uint8 security;
    uint16 clientBuild;
    uint32 id;
    uint32 addonSize;
    LocaleConstant locale;
    std::string account;
    SHA1Hash sha;
    BigNumber k;
    bool wardenActive = sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED);
    WorldPacket addonsData;
    uint8 loginServerType;
    uint32 realmIndex;

    recvPacket.read_skip<uint32>(); // ServerId - Used for GRUNT only
    recvPacket.read_skip<uint32>(); // Battlegroup
    recvPacket >> loginServerType;
    recvPacket >> digest[10];
    recvPacket >> digest[18];
    recvPacket >> digest[12];
    recvPacket >> digest[5];
    recvPacket.read_skip<uint64>();
    recvPacket >> digest[15];
    recvPacket >> digest[9];
    recvPacket >> digest[19];
    recvPacket >> digest[4];
    recvPacket >> digest[7];
    recvPacket >> digest[16];
    recvPacket >> digest[3];
    recvPacket >> clientBuild;
    recvPacket >> digest[8];
    recvPacket >> realmIndex;
    recvPacket.read_skip<uint8>();
    recvPacket >> digest[17];
    recvPacket >> digest[6];
    recvPacket >> digest[0];
    recvPacket >> digest[1];
    recvPacket >> digest[11];
    recvPacket >> clientSeed;
    recvPacket >> digest[2];
    recvPacket.read_skip<uint32>(); // Region
    recvPacket >> digest[14];
    recvPacket >> digest[13];

    recvPacket >> addonSize;

    if (addonSize)
    {
        addonsData.resize(addonSize);
        recvPacket.read((uint8*)addonsData.contents(), addonSize);
    }

    recvPacket.ReadBit();           // UseIPv6
    uint32 accountNameLength = recvPacket.ReadBits(12);
    account = recvPacket.ReadString(accountNameLength);

    // Get the account information from the auth database
    //         0           1        2       3          4         5       6          7   8                  9
    // SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os, battlenet_account FROM account WHERE username = ?
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME);
    stmt->setString(0, account);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Stop if the account is not found
    if (!result)
    {
        // We can not log here, as we do not know the account. Thus, no accountId.
        SendAuthResponseError(AUTH_UNKNOWN_ACCOUNT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (unknown account).");
        DelayedCloseSocket();
        return;
    }

    Field* fields = result->Fetch();

    uint8 expansion = fields[4].GetUInt8();
    uint32 world_expansion = sWorld->getIntConfig(CONFIG_EXPANSION);
    if (expansion > world_expansion)
        expansion = world_expansion;

    // For hook purposes, we get Remoteaddress at this point.
    std::string address = GetRemoteIpAddress().to_string();

    // As we don't know if attempted login process by ip works, we update last_attempt_ip right away
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_ATTEMPT_IP);

    stmt->setString(0, address);
    stmt->setString(1, account);

    LoginDatabase.Execute(stmt);
    // This also allows to check for possible "hack" attempts on account

    // id has to be fetched at this point, so that first actual account response that fails can be logged
    id = fields[0].GetUInt32();

    k.SetHexStr(fields[1].GetCString());

    // even if auth credentials are bad, try using the session key we have - client cannot read auth response error without it
    _authCrypt.Init(&k);

    // First reject the connection if packet contains invalid data or realm state doesn't allow logging in
    if (sWorld->IsClosed())
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: World closed, denying client (%s).", GetRemoteIpAddress().to_string().c_str());
        DelayedCloseSocket();
        return;
    }

    if (realmIndex != realmID)
    {
        SendAuthResponseError(REALM_LIST_REALM_NOT_FOUND);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (bad realm).");
        DelayedCloseSocket();
        return;
    }

    std::string os = fields[8].GetString();

    // Must be done before WorldSession is created
    if (wardenActive && os != "Win" && os != "OSX")
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Client %s attempted to log in using invalid client OS (%s).", address.c_str(), os.c_str());
        DelayedCloseSocket();
        return;
    }

    // Check that Key and account name are the same on client and server
    uint32 t = 0;

    sha.UpdateData(account);
    sha.UpdateData((uint8*)&t, 4);
    sha.UpdateData((uint8*)&clientSeed, 4);
    sha.UpdateData((uint8*)&_authSeed, 4);
    sha.UpdateBigNumbers(&k, NULL);
    sha.Finalize();

    if (memcmp(sha.GetDigest(), digest, 20))
    {
        SendAuthResponseError(AUTH_FAILED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Authentication failed for account: %u ('%s') address: %s", id, account.c_str(), address.c_str());
        DelayedCloseSocket();
        return;
    }

    ///- Re-check ip locking (same check as in auth).
    if (fields[3].GetUInt8() == 1) // if ip is locked
    {
        if (strcmp(fields[2].GetCString(), address.c_str()))
        {
            SendAuthResponseError(AUTH_FAILED);
            TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account IP differs. Original IP: %s, new IP: %s).", fields[2].GetCString(), address.c_str());
            // We could log on hook only instead of an additional db log, however action logger is config based. Better keep DB logging as well
            sScriptMgr->OnFailedAccountLogin(id);
            DelayedCloseSocket();
            return;
        }
    }

    int64 mutetime = fields[5].GetInt64();
    //! Negative mutetime indicates amount of seconds to be muted effective on next login - which is now.
    if (mutetime < 0)
    {
        mutetime = time(NULL) + llabs(mutetime);

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME_LOGIN);

        stmt->setInt64(0, mutetime);
        stmt->setUInt32(1, id);

        LoginDatabase.Execute(stmt);
    }

    locale = LocaleConstant(fields[6].GetUInt8());
    if (locale >= TOTAL_LOCALES)
        locale = LOCALE_enUS;

    uint32 recruiter = fields[7].GetUInt32();

    uint32 battlenetAccountId = 0;
    if (loginServerType == 1)
        battlenetAccountId = fields[9].GetUInt32();

    // Checks gmlevel per Realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);

    stmt->setUInt32(0, id);
    stmt->setInt32(1, int32(realmID));

    result = LoginDatabase.Query(stmt);

    if (!result)
        security = 0;
    else
    {
        fields = result->Fetch();
        security = fields[0].GetUInt8();
    }

    // Re-check account ban (same check as in auth)
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BANS);

    stmt->setUInt32(0, id);
    stmt->setString(1, address);

    PreparedQueryResult banresult = LoginDatabase.Query(stmt);

    if (banresult) // if account banned
    {
        SendAuthResponseError(AUTH_BANNED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account banned).");
        sScriptMgr->OnFailedAccountLogin(id);
        DelayedCloseSocket();
        return;
    }

    // Check locked state for server
    AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
    TC_LOG_DEBUG("network", "Allowed Level: %u Player Level %u", allowedAccountType, AccountTypes(security));
    if (allowedAccountType > SEC_PLAYER && AccountTypes(security) < allowedAccountType)
    {
        SendAuthResponseError(AUTH_UNAVAILABLE);
        TC_LOG_INFO("network", "WorldSocket::HandleAuthSession: User tries to login but his security level is not enough");
        sScriptMgr->OnFailedAccountLogin(id);
        DelayedCloseSocket();
        return;
    }

    TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Client '%s' authenticated successfully from %s.",
        account.c_str(),
        address.c_str());

    // Check if this user is by any chance a recruiter
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_RECRUITER);

    stmt->setUInt32(0, id);

    result = LoginDatabase.Query(stmt);

    bool isRecruiter = false;
    if (result)
        isRecruiter = true;

    // Update the last_ip in the database as it was successful for login
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_IP);

    stmt->setString(0, address);
    stmt->setString(1, account);

    LoginDatabase.Execute(stmt);

    // At this point, we can safely hook a successful login
    sScriptMgr->OnAccountLogin(id);

    _worldSession = new WorldSession(id, battlenetAccountId, shared_from_this(), AccountTypes(security), expansion, mutetime, locale, recruiter, isRecruiter);
    _worldSession->LoadGlobalAccountData();
    _worldSession->LoadTutorialsData();
    _worldSession->ReadAddonsInfo(addonsData);
    _worldSession->LoadPermissions();

    // Initialize Warden system only if it is enabled by config
    if (wardenActive)
        _worldSession->InitWarden(&k, os);

    sWorld->AddSession(_worldSession);
}

void WorldSocket::SendAuthResponseError(uint8 code)
{
    WorldPacket packet(SMSG_AUTH_RESPONSE, 1);
    packet.WriteBit(0); // has queue info
    packet.WriteBit(0); // has account info
    packet << uint8(code);

    SendPacket(packet);
}

void WorldSocket::HandlePing(WorldPacket& recvPacket)
{
    uint32 ping;
    uint32 latency;

    // Get the ping packet content
    recvPacket >> latency;
    recvPacket >> ping;

    if (_LastPingTime == steady_clock::time_point())
    {
        _LastPingTime = steady_clock::now();
    }
    else
    {
        steady_clock::time_point now = steady_clock::now();

        steady_clock::duration diff = now - _LastPingTime;

        _LastPingTime = now;

        if (diff < seconds(27))
        {
            ++_OverSpeedPings;

            uint32 maxAllowed = sWorld->getIntConfig(CONFIG_MAX_OVERSPEED_PINGS);

            if (maxAllowed && _OverSpeedPings > maxAllowed)
            {
                if (_worldSession && !_worldSession->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_OVERSPEED_PING))
                {
                    TC_LOG_ERROR("network", "WorldSocket::HandlePing: %s kicked for over-speed pings (address: %s)",
                        _worldSession->GetPlayerInfo().c_str(), GetRemoteIpAddress().to_string().c_str());

                    CloseSocket();
                    return;
                }
            }
        }
        else
            _OverSpeedPings = 0;
    }

    if (_worldSession)
    {
        _worldSession->SetLatency(latency);
        _worldSession->ResetClientTimeDelay();
    }
    else
    {
        TC_LOG_ERROR("network", "WorldSocket::HandlePing: peer sent CMSG_PING, but is not authenticated or got recently kicked, address = %s", GetRemoteIpAddress().to_string().c_str());

        CloseSocket();
        return;
    }

    WorldPacket packet(SMSG_PONG, 4);
    packet << ping;
    return SendPacket(packet);
}
