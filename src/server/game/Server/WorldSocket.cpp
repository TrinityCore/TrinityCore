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

uint32 const SizeOfClientHeader[2][2] =
{
    { 2, 0 },
    { 6, 4 }
};

uint32 const SizeOfServerHeader[2] = { sizeof(uint16) + sizeof(uint32), sizeof(uint32) };

WorldSocket::WorldSocket(tcp::socket&& socket)
    : Socket(std::move(socket)), _authSeed(rand32()), _OverSpeedPings(0), _worldSession(nullptr), _initialized(false)
{
    _headerBuffer.Resize(SizeOfClientHeader[0][0]);
}

void WorldSocket::Start()
{
    AsyncRead();

    MessageBuffer initializer;
    ServerPktHeader header;
    header.Setup.Size = ServerConnectionInitialize.size();
    initializer.Write(&header, sizeof(header.Setup.Size));
    initializer.Write(ServerConnectionInitialize.c_str(), ServerConnectionInitialize.length());

    std::unique_lock<std::mutex> dummy(_writeLock, std::defer_lock);
    QueuePacket(std::move(initializer), dummy);
}

void WorldSocket::HandleSendAuthSession()
{
    WorldPacket packet(SMSG_AUTH_CHALLENGE, 37);
    packet << uint32(_authSeed);

    BigNumber seed1;
    seed1.SetRand(16 * 8);
    packet.append(seed1.AsByteArray(16).get(), 16);               // new encryption seeds

    BigNumber seed2;
    seed2.SetRand(16 * 8);
    packet.append(seed2.AsByteArray(16).get(), 16);               // new encryption seeds

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

void WorldSocket::ExtractOpcodeAndSize(ClientPktHeader const* header, uint32& opcode, uint32& size) const
{
    if (_authCrypt.IsInitialized())
    {
        opcode = header->Normal.Command;
        size = header->Normal.Size;
    }
    else
    {
        opcode = header->Setup.Command;
        size = header->Setup.Size;
        if (_initialized)
            size -= 4;
    }
}

bool WorldSocket::ReadHeaderHandler()
{
    ASSERT(_headerBuffer.GetActiveSize() == SizeOfClientHeader[_initialized][_authCrypt.IsInitialized()], "Header size %u different than expected %u", _headerBuffer.GetActiveSize(), SizeOfClientHeader[_initialized][_authCrypt.IsInitialized()]);

    _authCrypt.DecryptRecv(_headerBuffer.GetReadPointer(), _headerBuffer.GetActiveSize());

    ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());
    uint32 opcode;
    uint32 size;

    ExtractOpcodeAndSize(header, opcode, size);

    if (!ClientPktHeader::IsValidSize(size) || (_initialized && !ClientPktHeader::IsValidOpcode(opcode)))
    {
        if (_worldSession)
        {
            Player* player = _worldSession->GetPlayer();
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client (account: %u, char [%s, name: %s]) sent malformed packet (size: %hu, cmd: %u)",
                _worldSession->GetAccountId(), player ? player->GetGUID().ToString().c_str() : "GUID: Empty", player ? player->GetName().c_str() : "<none>", size, opcode);
        }
        else
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client %s sent malformed packet (size: %hu, cmd: %u)",
                GetRemoteIpAddress().to_string().c_str(), size, opcode);

        CloseSocket();
        return false;
    }

    _packetBuffer.Resize(size);
    return true;
}

bool WorldSocket::ReadDataHandler()
{
    if (_initialized)
    {
        ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());
        uint32 cmd;
        uint32 size;

        ExtractOpcodeAndSize(header, cmd, size);

        Opcodes opcode = Opcodes(cmd);

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
            /*
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
            */
            default:
            {
                if (!_worldSession)
                {
                    TC_LOG_ERROR("network.opcode", "ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                    CloseSocket();
                    return false;
                }

                // prevent invalid memory access/crash with custom opcodes
                if (opcode >= NUM_OPCODE_HANDLERS)
                {
                    CloseSocket();
                    return false;
                }

                OpcodeHandler const* handler = opcodeTable[opcode];
                if (!handler)
                {
                    TC_LOG_ERROR("network.opcode", "No defined handler for opcode %s sent by %s", GetOpcodeNameForLogging(packet.GetOpcode()).c_str(), _worldSession->GetPlayerInfo().c_str());
                    return true;
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
        std::string initializer(reinterpret_cast<char const*>(_packetBuffer.GetReadPointer()), std::min(_packetBuffer.GetActiveSize(), ClientConnectionInitialize.length()));
        if (initializer != ClientConnectionInitialize)
        {
            CloseSocket();
            return false;
        }

        _initialized = true;
        _headerBuffer.Resize(SizeOfClientHeader[1][0]);
        _packetBuffer.Reset();
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

    std::unique_lock<std::mutex> guard(_writeLock);

    ServerPktHeader header;
    uint32 sizeOfHeader = SizeOfServerHeader[_authCrypt.IsInitialized()];
    if (_authCrypt.IsInitialized())
    {
        header.Normal.Size = packet.size();
        header.Normal.Command = packet.GetOpcode();
        _authCrypt.EncryptSend((uint8*)&header, sizeOfHeader);
    }
    else
    {
        header.Setup.Size = packet.size() + 4;
        header.Setup.Command = packet.GetOpcode();
    }

#ifndef TC_SOCKET_USE_IOCP
    if (_writeQueue.empty() && _writeBuffer.GetRemainingSpace() >= sizeOfHeader + packet.size())
    {
        _writeBuffer.Write((uint8*)&header, sizeOfHeader);
        if (!packet.empty())
            _writeBuffer.Write(packet.contents(), packet.size());
    }
    else
#endif
    {
        MessageBuffer buffer(sizeOfHeader + packet.size());
        buffer.Write((uint8*)&header, sizeOfHeader);
        if (!packet.empty())
            buffer.Write(packet.contents(), packet.size());

        QueuePacket(std::move(buffer), guard);
    }
}

void WorldSocket::HandleAuthSession(WorldPacket& recvPacket)
{
    uint8 digest[SHA_DIGEST_LENGTH];
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

    recvPacket.read_skip<uint32>(); // Grunt - ServerId
    recvPacket >> clientBuild;
    recvPacket.read_skip<uint32>(); // Region
    recvPacket.read_skip<uint32>(); // Battlegroup
    recvPacket >> realmIndex;
    recvPacket >> loginServerType;  // could be swapped with other uint8 (both always 1)
    recvPacket.read_skip<uint8>();
    recvPacket >> clientSeed;
    recvPacket.read_skip<uint64>(); // DosResponse

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        recvPacket >> digest[i];

    uint32 accountNameLength = recvPacket.ReadBits(11);
    account = recvPacket.ReadString(accountNameLength);
    recvPacket.ReadBit();           // UseIPv6
    recvPacket >> addonSize;

    if (addonSize)
    {
        addonsData.resize(addonSize);
        recvPacket.read((uint8*)addonsData.contents(), addonSize);
    }

    // Get the account information from the auth database
    //         0           1        2       3          4         5       6          7   8
    // SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os FROM account WHERE username = ?
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
    _headerBuffer.Resize(SizeOfClientHeader[1][1]);

    // First reject the connection if packet contains invalid data or realm state doesn't allow logging in
    if (sWorld->IsClosed())
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: World closed, denying client (%s).", GetRemoteIpAddress().to_string().c_str());
        DelayedCloseSocket();
        return;
    }

    if (realmIndex != realmHandle.Index)
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

    if (memcmp(sha.GetDigest(), digest, SHA_DIGEST_LENGTH) != 0)
    {
        SendAuthResponseError(AUTH_FAILED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Authentication failed for account: %u ('%s') address: %s", id, account.c_str(), address.c_str());
        DelayedCloseSocket();
        return;
    }

    ///- Re-check ip locking (same check as in auth).
    if (fields[3].GetUInt8() == 1) // if ip is locked
    {
        if (strcmp(fields[2].GetCString(), address.c_str()) != 0)
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
        battlenetAccountId = Battlenet::AccountMgr::GetIdByGameAccount(id);

    // Checks gmlevel per Realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);

    stmt->setUInt32(0, id);
    stmt->setInt32(1, int32(realmHandle.Index));

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
    WorldPacket packet(SMSG_AUTH_RESPONSE, 2);
    packet << uint8(code);
    packet.WriteBit(0); // has account info
    packet.WriteBit(0); // has queue info

    packet.FlushBits();
    SendPacket(packet);
}

void WorldSocket::HandlePing(WorldPacket& recvPacket)
{
    uint32 ping;
    uint32 latency;

    // Get the ping packet content
    recvPacket >> ping;
    recvPacket >> latency;

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
