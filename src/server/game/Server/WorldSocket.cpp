/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "AuthenticationPackets.h"
#include "BattlenetRpcErrorCodes.h"
#include "BigNumber.h"
#include "CharacterPackets.h"
#include "HmacHash.h"
#include "Opcodes.h"
#include "PacketLog.h"
#include "ScriptMgr.h"
#include "SessionKeyGeneration.h"
#include "SHA256.h"
#include "World.h"

#include <zlib.h>
#include <memory>

#pragma pack(push, 1)

struct CompressedWorldPacket
{
    uint32 UncompressedSize;
    uint32 UncompressedAdler;
    uint32 CompressedAdler;
};

class EncryptablePacket : public WorldPacket
{
public:
    EncryptablePacket(WorldPacket const& packet, bool encrypt) : WorldPacket(packet), _encrypt(encrypt) { }

    bool NeedsEncryption() const { return _encrypt; }

private:
    bool _encrypt;
};

#pragma pack(pop)

using boost::asio::ip::tcp;

uint32 const WorldSocket::ConnectionInitializeMagic = 0xF5EB1CE;
std::string const WorldSocket::ServerConnectionInitialize("WORLD OF WARCRAFT CONNECTION - SERVER TO CLIENT");
std::string const WorldSocket::ClientConnectionInitialize("WORLD OF WARCRAFT CONNECTION - CLIENT TO SERVER", 48);
uint32 const WorldSocket::MinSizeForCompression = 0x400;

uint32 const SizeOfClientHeader[2] = { sizeof(uint16) + sizeof(uint16), sizeof(uint32) + sizeof(uint16) };
uint32 const SizeOfServerHeader[2] = { sizeof(uint16) + sizeof(uint16), sizeof(uint32) + sizeof(uint16) };

uint8 const WorldSocket::AuthCheckSeed[16] = { 0xC5, 0xC6, 0x98, 0x95, 0x76, 0x3F, 0x1D, 0xCD, 0xB6, 0xA1, 0x37, 0x28, 0xB3, 0x12, 0xFF, 0x8A };
uint8 const WorldSocket::SessionKeySeed[16] = { 0x58, 0xCB, 0xCF, 0x40, 0xFE, 0x2E, 0xCE, 0xA6, 0x5A, 0x90, 0xB8, 0x01, 0x68, 0x6C, 0x28, 0x0B };
uint8 const WorldSocket::ContinuedSessionSeed[16] = { 0x16, 0xAD, 0x0C, 0xD4, 0x46, 0xF9, 0x4F, 0xB2, 0xEF, 0x7D, 0xEA, 0x2A, 0x17, 0x66, 0x4D, 0x2F };

WorldSocket::WorldSocket(tcp::socket&& socket) : Socket(std::move(socket)),
    _type(CONNECTION_TYPE_REALM), _OverSpeedPings(0),
    _worldSession(nullptr), _authed(false), _compressionStream(nullptr)
{
    _serverChallenge.SetRand(8 * 16);
    _headerBuffer.Resize(SizeOfClientHeader[0]);
}

WorldSocket::~WorldSocket()
{
    if (_compressionStream)
    {
        deflateEnd(_compressionStream);
        delete _compressionStream;
    }
}

void WorldSocket::Start()
{
    std::string ip_address = GetRemoteIpAddress().to_string();
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_INFO);
    stmt->setString(0, ip_address);
    stmt->setUInt32(1, inet_addr(ip_address.c_str()));

    _queryCallback = std::bind(&WorldSocket::CheckIpCallback, this, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
}

void WorldSocket::CheckIpCallback(PreparedQueryResult result)
{
    if (result)
    {
        bool banned = false;
        do
        {
            Field* fields = result->Fetch();
            if (fields[0].GetUInt64() != 0)
                banned = true;

            if (!fields[1].GetString().empty())
                _ipCountry = fields[1].GetString();

        } while (result->NextRow());

        if (banned)
        {
            TC_LOG_ERROR("network", "WorldSocket::CheckIpCallback: Sent Auth Response (IP %s banned).", GetRemoteIpAddress().to_string().c_str());
            DelayedCloseSocket();
            return;
        }
    }

    _packetBuffer.Resize(4 + 2 + ClientConnectionInitialize.length());

    AsyncReadWithCallback(&WorldSocket::InitializeHandler);

    MessageBuffer initializer;
    ServerPktHeader header;
    header.Setup.Size = ServerConnectionInitialize.size();
    initializer.Write(&ConnectionInitializeMagic, sizeof(ConnectionInitializeMagic));
    initializer.Write(&header, sizeof(header.Setup.Size));
    initializer.Write(ServerConnectionInitialize.c_str(), ServerConnectionInitialize.length());

    // - io_service.run thread, safe.
    QueuePacket(std::move(initializer));
}

void WorldSocket::InitializeHandler(boost::system::error_code error, std::size_t transferedBytes)
{
    if (error)
    {
        CloseSocket();
        return;
    }

    GetReadBuffer().WriteCompleted(transferedBytes);

    MessageBuffer& packet = GetReadBuffer();
    if (packet.GetActiveSize() > 0)
    {
        if (_packetBuffer.GetRemainingSpace() > 0)
        {
            // need to receive the header
            std::size_t readHeaderSize = std::min(packet.GetActiveSize(), _packetBuffer.GetRemainingSpace());
            _packetBuffer.Write(packet.GetReadPointer(), readHeaderSize);
            packet.ReadCompleted(readHeaderSize);

            if (_packetBuffer.GetRemainingSpace() > 0)
            {
                // Couldn't receive the whole header this time.
                ASSERT(packet.GetActiveSize() == 0);
                AsyncReadWithCallback(&WorldSocket::InitializeHandler);
                return;
            }

            uint32 magic;
            uint16 length;
            ByteBuffer buffer(std::move(_packetBuffer));

            buffer >> magic;
            buffer >> length;
            std::string initializer = buffer.ReadString(length);
            if (magic != ConnectionInitializeMagic || initializer != ClientConnectionInitialize)
            {
                CloseSocket();
                return;
            }

            _compressionStream = new z_stream();
            _compressionStream->zalloc = (alloc_func)NULL;
            _compressionStream->zfree = (free_func)NULL;
            _compressionStream->opaque = (voidpf)NULL;
            _compressionStream->avail_in = 0;
            _compressionStream->next_in = NULL;
            int32 z_res = deflateInit2(_compressionStream, sWorld->getIntConfig(CONFIG_COMPRESSION), Z_DEFLATED, -15, 8, Z_DEFAULT_STRATEGY);
            if (z_res != Z_OK)
            {
                CloseSocket();
                TC_LOG_ERROR("network", "Can't initialize packet compression (zlib: deflateInit) Error code: %i (%s)", z_res, zError(z_res));
                return;
            }

            _packetBuffer.Reset();
            HandleSendAuthSession();
            AsyncRead();
            return;
        }
    }

    AsyncReadWithCallback(&WorldSocket::InitializeHandler);
}

bool WorldSocket::Update()
{
    EncryptablePacket* queued;
    MessageBuffer buffer;
    while (_bufferQueue.Dequeue(queued))
    {
        uint32 sizeOfHeader = SizeOfServerHeader[queued->NeedsEncryption()];
        uint32 packetSize = queued->size();
        if (packetSize > MinSizeForCompression && queued->NeedsEncryption())
            packetSize = compressBound(packetSize) + sizeof(CompressedWorldPacket);

        if (buffer.GetRemainingSpace() < packetSize + sizeOfHeader)
        {
            QueuePacket(std::move(buffer));
            buffer.Resize(4096);
        }

        if (buffer.GetRemainingSpace() >= packetSize + sizeOfHeader)
            WritePacketToBuffer(*queued, buffer);
        else    // single packet larger than 4096 bytes
        {
            MessageBuffer packetBuffer(packetSize + sizeOfHeader);
            WritePacketToBuffer(*queued, packetBuffer);
            QueuePacket(std::move(packetBuffer));
        }

        delete queued;
    }

    if (buffer.GetActiveSize() > 0)
        QueuePacket(std::move(buffer));

    if (!BaseSocket::Update())
        return false;

    if (_queryFuture.valid() && _queryFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        auto callback = _queryCallback;
        _queryCallback = nullptr;
        callback(_queryFuture.get());
    }

    return true;
}

void WorldSocket::HandleSendAuthSession()
{
    _encryptSeed.SetRand(16 * 8);
    _decryptSeed.SetRand(16 * 8);

    WorldPackets::Auth::AuthChallenge challenge;
    memcpy(challenge.Challenge.data(), _serverChallenge.AsByteArray(16).get(), 16);
    memcpy(&challenge.DosChallenge[0], _encryptSeed.AsByteArray(16).get(), 16);
    memcpy(&challenge.DosChallenge[4], _decryptSeed.AsByteArray(16).get(), 16);
    challenge.DosZeroBits = 1;

    SendPacketAndLogOpcode(*challenge.Write());
}

void WorldSocket::OnClose()
{
    {
        std::lock_guard<std::mutex> sessionGuard(_worldSessionLock);
        _worldSession = nullptr;
    }
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
            {
                CloseSocket();
                return;
            }
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
        ReadDataHandlerResult result = ReadDataHandler();
        _headerBuffer.Reset();
        if (result != ReadDataHandlerResult::Ok)
        {
            if (result != ReadDataHandlerResult::WaitingForQuery)
                CloseSocket();

            return;
        }
    }

    AsyncRead();
}

void WorldSocket::ExtractOpcodeAndSize(ClientPktHeader const* header, uint32& opcode, uint32& size) const
{
    if (_authCrypt.IsInitialized())
    {
        opcode = header->Normal.Command;
        size = header->Normal.Size - 2;
    }
    else
    {
        opcode = header->Setup.Command;
        size = header->Setup.Size - 2;
    }
}

void WorldSocket::SetWorldSession(WorldSession* session)
{
    std::lock_guard<std::mutex> sessionGuard(_worldSessionLock);
    _worldSession = session;
    _authed = true;
}

bool WorldSocket::ReadHeaderHandler()
{
    ASSERT(_headerBuffer.GetActiveSize() == SizeOfClientHeader[_authCrypt.IsInitialized()], "Header size " SZFMTD " different than expected %u", _headerBuffer.GetActiveSize(), SizeOfClientHeader[_authCrypt.IsInitialized()]);

    _authCrypt.DecryptRecv(_headerBuffer.GetReadPointer(), 4);

    ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());
    uint32 opcode;
    uint32 size;

    ExtractOpcodeAndSize(header, opcode, size);

    if (!ClientPktHeader::IsValidSize(size) || !ClientPktHeader::IsValidOpcode(opcode))
    {
        TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client %s sent malformed packet (size: %u, cmd: %u)",
            GetRemoteIpAddress().to_string().c_str(), size, opcode);
        return false;
    }

    _packetBuffer.Resize(size);
    return true;
}

WorldSocket::ReadDataHandlerResult WorldSocket::ReadDataHandler()
{
    ClientPktHeader* header = reinterpret_cast<ClientPktHeader*>(_headerBuffer.GetReadPointer());
    uint32 cmd;
    uint32 size;

    ExtractOpcodeAndSize(header, cmd, size);

    OpcodeClient opcode = static_cast<OpcodeClient>(cmd);

    WorldPacket packet(opcode, std::move(_packetBuffer), GetConnectionType());

    if (sPacketLog->CanLogPacket())
        sPacketLog->LogPacket(packet, CLIENT_TO_SERVER, GetRemoteIpAddress(), GetRemotePort(), GetConnectionType());

    std::unique_lock<std::mutex> sessionGuard(_worldSessionLock, std::defer_lock);

    switch (opcode)
    {
        case CMSG_PING:
            LogOpcodeText(opcode, sessionGuard);
            return HandlePing(packet) ? ReadDataHandlerResult::Ok : ReadDataHandlerResult::Error;
        case CMSG_AUTH_SESSION:
        {
            LogOpcodeText(opcode, sessionGuard);
            if (_authed)
            {
                // locking just to safely log offending user is probably overkill but we are disconnecting him anyway
                if (sessionGuard.try_lock())
                    TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming: received duplicate CMSG_AUTH_SESSION from %s", _worldSession->GetPlayerInfo().c_str());
                return ReadDataHandlerResult::Error;
            }

            std::shared_ptr<WorldPackets::Auth::AuthSession> authSession = std::make_shared<WorldPackets::Auth::AuthSession>(std::move(packet));
            authSession->Read();
            HandleAuthSession(authSession);
            return ReadDataHandlerResult::WaitingForQuery;
        }
        case CMSG_AUTH_CONTINUED_SESSION:
        {
            LogOpcodeText(opcode, sessionGuard);
            if (_authed)
            {
                // locking just to safely log offending user is probably overkill but we are disconnecting him anyway
                if (sessionGuard.try_lock())
                    TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming: received duplicate CMSG_AUTH_CONTINUED_SESSION from %s", _worldSession->GetPlayerInfo().c_str());
                return ReadDataHandlerResult::Error;
            }

            std::shared_ptr<WorldPackets::Auth::AuthContinuedSession> authSession = std::make_shared<WorldPackets::Auth::AuthContinuedSession>(std::move(packet));
            authSession->Read();
            HandleAuthContinuedSession(authSession);
            return ReadDataHandlerResult::WaitingForQuery;
        }
        case CMSG_KEEP_ALIVE:
            LogOpcodeText(opcode, sessionGuard);
            break;
        case CMSG_LOG_DISCONNECT:
            LogOpcodeText(opcode, sessionGuard);
            packet.rfinish();   // contains uint32 disconnectReason;
            break;
        case CMSG_ENABLE_NAGLE:
            LogOpcodeText(opcode, sessionGuard);
            SetNoDelay(false);
            break;
        case CMSG_CONNECT_TO_FAILED:
        {
            sessionGuard.lock();

            LogOpcodeText(opcode, sessionGuard);
            WorldPackets::Auth::ConnectToFailed connectToFailed(std::move(packet));
            connectToFailed.Read();
            HandleConnectToFailed(connectToFailed);
            break;
        }
        default:
        {
            sessionGuard.lock();

            LogOpcodeText(opcode, sessionGuard);

            if (!_worldSession)
            {
                TC_LOG_ERROR("network.opcode", "ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                return ReadDataHandlerResult::Error;
            }

            OpcodeHandler const* handler = opcodeTable[opcode];
            if (!handler)
            {
                TC_LOG_ERROR("network.opcode", "No defined handler for opcode %s sent by %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(packet.GetOpcode())).c_str(), _worldSession->GetPlayerInfo().c_str());
                break;
            }

            // Our Idle timer will reset on any non PING opcodes.
            // Catches people idling on the login screen and any lingering ingame connections.
            _worldSession->ResetTimeOutTime();

            // Copy the packet to the heap before enqueuing
            _worldSession->QueuePacket(new WorldPacket(std::move(packet)));
            break;
        }
    }

    return ReadDataHandlerResult::Ok;
}

void WorldSocket::LogOpcodeText(OpcodeClient opcode, std::unique_lock<std::mutex> const& guard) const
{
    if (!guard)
    {
        TC_LOG_TRACE("network.opcode", "C->S: %s %s", GetRemoteIpAddress().to_string().c_str(), GetOpcodeNameForLogging(opcode).c_str());
    }
    else
    {
        TC_LOG_TRACE("network.opcode", "C->S: %s %s", (_worldSession ? _worldSession->GetPlayerInfo() : GetRemoteIpAddress().to_string()).c_str(),
            GetOpcodeNameForLogging(opcode).c_str());
    }
}

void WorldSocket::SendPacketAndLogOpcode(WorldPacket const& packet)
{
    TC_LOG_TRACE("network.opcode", "S->C: %s %s", GetRemoteIpAddress().to_string().c_str(), GetOpcodeNameForLogging(static_cast<OpcodeServer>(packet.GetOpcode())).c_str());
    SendPacket(packet);
}

void WorldSocket::SendPacket(WorldPacket const& packet)
{
    if (!IsOpen())
        return;

    if (sPacketLog->CanLogPacket())
        sPacketLog->LogPacket(packet, SERVER_TO_CLIENT, GetRemoteIpAddress(), GetRemotePort(), GetConnectionType());

    _bufferQueue.Enqueue(new EncryptablePacket(packet, _authCrypt.IsInitialized()));
}

void WorldSocket::WritePacketToBuffer(EncryptablePacket const& packet, MessageBuffer& buffer)
{
    ServerPktHeader header;
    uint32 sizeOfHeader = SizeOfServerHeader[packet.NeedsEncryption()];
    uint32 opcode = packet.GetOpcode();
    uint32 packetSize = packet.size();

    // Reserve space for buffer
    uint8* headerPos = buffer.GetWritePointer();
    buffer.WriteCompleted(sizeOfHeader);

    if (packetSize > MinSizeForCompression && packet.NeedsEncryption())
    {
        CompressedWorldPacket cmp;
        cmp.UncompressedSize = packetSize + 2;
        cmp.UncompressedAdler = adler32(adler32(0x9827D8F1, (Bytef*)&opcode, 2), packet.contents(), packetSize);

        // Reserve space for compression info - uncompressed size and checksums
        uint8* compressionInfo = buffer.GetWritePointer();
        buffer.WriteCompleted(sizeof(CompressedWorldPacket));

        uint32 compressedSize = CompressPacket(buffer.GetWritePointer(), packet);

        cmp.CompressedAdler = adler32(0x9827D8F1, buffer.GetWritePointer(), compressedSize);

        memcpy(compressionInfo, &cmp, sizeof(CompressedWorldPacket));
        buffer.WriteCompleted(compressedSize);
        packetSize = compressedSize + sizeof(CompressedWorldPacket);

        opcode = SMSG_COMPRESSED_PACKET;
    }
    else if (!packet.empty())
        buffer.Write(packet.contents(), packet.size());

    packetSize += 2 /*opcode*/;

    if (packet.NeedsEncryption())
    {
        header.Normal.Size = packetSize;
        header.Normal.Command = opcode;
        _authCrypt.EncryptSend((uint8*)&header, 4);
    }
    else
    {
        header.Setup.Size = packetSize;
        header.Setup.Command = opcode;
    }

    memcpy(headerPos, &header, sizeOfHeader);
}

uint32 WorldSocket::CompressPacket(uint8* buffer, WorldPacket const& packet)
{
    uint32 opcode = packet.GetOpcode();
    uint32 bufferSize = deflateBound(_compressionStream, packet.size() + sizeof(uint16));

    _compressionStream->next_out = buffer;
    _compressionStream->avail_out = bufferSize;
    _compressionStream->next_in = (Bytef*)&opcode;
    _compressionStream->avail_in = sizeof(uint16);

    int32 z_res = deflate(_compressionStream, Z_NO_FLUSH);
    if (z_res != Z_OK)
    {
        TC_LOG_ERROR("network", "Can't compress packet opcode (zlib: deflate) Error code: %i (%s, msg: %s)", z_res, zError(z_res), _compressionStream->msg);
        return 0;
    }

    _compressionStream->next_in = (Bytef*)packet.contents();
    _compressionStream->avail_in = packet.size();

    z_res = deflate(_compressionStream, Z_SYNC_FLUSH);
    if (z_res != Z_OK)
    {
        TC_LOG_ERROR("network", "Can't compress packet data (zlib: deflate) Error code: %i (%s, msg: %s)", z_res, zError(z_res), _compressionStream->msg);
        return 0;
    }

    return bufferSize - _compressionStream->avail_out;
}

struct AccountInfo
{
    struct
    {
        uint32 Id;
        bool IsLockedToIP;
        std::string LastIP;
        std::string LockCountry;
        LocaleConstant Locale;
        bool IsBanned;

    } BattleNet;

    struct
    {
        uint32 Id;
        BigNumber SessionKey;
        uint8 Expansion;
        int64 MuteTime;
        uint32 Recruiter;
        std::string OS;
        bool IsRectuiter;
        AccountTypes Security;
        bool IsBanned;
    } Game;

    bool IsBanned() const { return BattleNet.IsBanned || Game.IsBanned; }

    explicit AccountInfo(Field* fields)
    {
        //           0             1           2          3                4            5           6          7            8     9     10          11
        // SELECT a.id, a.sessionkey, ba.last_ip, ba.locked, ba.lock_country, a.expansion, a.mutetime, ba.locale, a.recruiter, a.os, ba.id, aa.gmLevel,
        //                                                              12                                                            13    14
        // bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate, ab.unbandate > UNIX_TIMESTAMP() OR ab.unbandate = ab.bandate, r.id
        // FROM account a LEFT JOIN battlenet_accounts ba ON a.battlenet_account = ba.id LEFT JOIN account_access aa ON a.id = aa.id AND aa.RealmID IN (-1, ?)
        // LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id LEFT JOIN account_banned ab ON a.id = ab.id LEFT JOIN account r ON a.id = r.recruiter
        // WHERE a.username = ? ORDER BY aa.RealmID DESC LIMIT 1
        Game.Id = fields[0].GetUInt32();
        Game.SessionKey.SetHexStr(fields[1].GetCString());
        BattleNet.LastIP = fields[2].GetString();
        BattleNet.IsLockedToIP = fields[3].GetBool();
        BattleNet.LockCountry = fields[4].GetString();
        Game.Expansion = fields[5].GetUInt8();
        Game.MuteTime = fields[6].GetInt64();
        BattleNet.Locale = LocaleConstant(fields[7].GetUInt8());
        Game.Recruiter = fields[8].GetUInt32();
        Game.OS = fields[9].GetString();
        BattleNet.Id = fields[10].GetUInt32();
        Game.Security = AccountTypes(fields[11].GetUInt8());
        BattleNet.IsBanned = fields[12].GetUInt64() != 0;
        Game.IsBanned = fields[13].GetUInt64() != 0;
        Game.IsRectuiter = fields[14].GetUInt32() != 0;

        uint32 world_expansion = sWorld->getIntConfig(CONFIG_EXPANSION);
        if (Game.Expansion > world_expansion)
            Game.Expansion = world_expansion;

        if (BattleNet.Locale >= TOTAL_LOCALES)
            BattleNet.Locale = LOCALE_enUS;
    }
};

void WorldSocket::HandleAuthSession(std::shared_ptr<WorldPackets::Auth::AuthSession> authSession)
{
    // Client switches packet headers after sending CMSG_AUTH_SESSION
    _headerBuffer.Resize(SizeOfClientHeader[1]);

    // Get the account information from the auth database
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME);
    stmt->setInt32(0, int32(realm.Id.Realm));
    stmt->setString(1, authSession->RealmJoinTicket);

    _queryCallback = std::bind(&WorldSocket::HandleAuthSessionCallback, this, authSession, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
}

void WorldSocket::HandleAuthSessionCallback(std::shared_ptr<WorldPackets::Auth::AuthSession> authSession, PreparedQueryResult result)
{
    // Stop if the account is not found
    if (!result)
    {
        // We can not log here, as we do not know the account. Thus, no accountId.
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (unknown account).");
        DelayedCloseSocket();
        return;
    }

    AccountInfo account(result->Fetch());

    // For hook purposes, we get Remoteaddress at this point.
    std::string address = GetRemoteIpAddress().to_string();

    HmacSha256 hmac(SHA256_DIGEST_LENGTH, account.Game.SessionKey.AsByteArray(SHA256_DIGEST_LENGTH).get());
    hmac.UpdateData(authSession->LocalChallenge.data(), authSession->LocalChallenge.size());
    hmac.UpdateData(_serverChallenge.AsByteArray(16).get(), 16);
    hmac.UpdateData(AuthCheckSeed, 16);
    hmac.Finalize();

    // Check that Key and account name are the same on client and server
    if (memcmp(hmac.GetDigest(), authSession->Digest.data(), authSession->Digest.size()) != 0)
    {
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Authentication failed for account: %u ('%s') address: %s", account.Game.Id, authSession->RealmJoinTicket.c_str(), address.c_str());
        DelayedCloseSocket();
        return;
    }

    HmacSha256 sessionKeyHmac(SHA256_DIGEST_LENGTH, account.Game.SessionKey.AsByteArray(SHA256_DIGEST_LENGTH).get());
    sessionKeyHmac.UpdateData(_serverChallenge.AsByteArray(16).get(), 16);
    sessionKeyHmac.UpdateData(authSession->LocalChallenge.data(), authSession->LocalChallenge.size());
    sessionKeyHmac.UpdateData(SessionKeySeed, 16);
    sessionKeyHmac.Finalize();

    uint8 sessionKey[40];
    SessionKeyGenerator<SHA256Hash> sessionKeyGenerator(sessionKeyHmac.GetDigest(), sessionKeyHmac.GetLength());
    sessionKeyGenerator.Generate(sessionKey, 40);

    BigNumber K;
    K.SetBinary(sessionKey, 40);

    _authCrypt.Init(&K);

    // As we don't know if attempted login process by ip works, we update last_attempt_ip right away
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_ATTEMPT_IP);
    stmt->setString(0, address);
    stmt->setString(1, authSession->RealmJoinTicket);
    LoginDatabase.Execute(stmt);
    // This also allows to check for possible "hack" attempts on account

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_INFO_CONTINUED_SESSION);
    stmt->setString(0, K.AsHexStr());
    stmt->setUInt32(1, account.Game.Id);
    LoginDatabase.Execute(stmt);

    // First reject the connection if packet contains invalid data or realm state doesn't allow logging in
    if (sWorld->IsClosed())
    {
        SendAuthResponseError(ERROR_DENIED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: World closed, denying client (%s).", GetRemoteIpAddress().to_string().c_str());
        DelayedCloseSocket();
        return;
    }

    if (authSession->RealmID != realm.Id.Realm)
    {
        SendAuthResponseError(ERROR_DENIED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Client %s requested connecting with realm id %u but this realm has id %u set in config.",
            GetRemoteIpAddress().to_string().c_str(), authSession->RealmID, realm.Id.Realm);
        DelayedCloseSocket();
        return;
    }

    // Must be done before WorldSession is created
    bool wardenActive = sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED);
    if (wardenActive && account.Game.OS != "Win" && account.Game.OS != "Wn64" && account.Game.OS != "Mc64")
    {
        SendAuthResponseError(ERROR_DENIED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Client %s attempted to log in using invalid client OS (%s).", address.c_str(), account.Game.OS.c_str());
        DelayedCloseSocket();
        return;
    }

    ///- Re-check ip locking (same check as in auth).
    if (account.BattleNet.IsLockedToIP)
    {
        if (account.BattleNet.LastIP != address)
        {
            SendAuthResponseError(ERROR_DENIED);
            TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account IP differs. Original IP: %s, new IP: %s).", account.BattleNet.LastIP.c_str(), address.c_str());
            // We could log on hook only instead of an additional db log, however action logger is config based. Better keep DB logging as well
            sScriptMgr->OnFailedAccountLogin(account.Game.Id);
            DelayedCloseSocket();
            return;
        }
    }
    else if (!account.BattleNet.LockCountry.empty() && account.BattleNet.LockCountry != "00" && !_ipCountry.empty())
    {
        if (account.BattleNet.LockCountry != _ipCountry)
        {
            SendAuthResponseError(ERROR_DENIED);
            TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account country differs. Original country: %s, new country: %s).", account.BattleNet.LockCountry.c_str(), _ipCountry.c_str());
            // We could log on hook only instead of an additional db log, however action logger is config based. Better keep DB logging as well
            sScriptMgr->OnFailedAccountLogin(account.Game.Id);
            DelayedCloseSocket();
            return;
        }
    }

    int64 mutetime = account.Game.MuteTime;
    //! Negative mutetime indicates amount of seconds to be muted effective on next login - which is now.
    if (mutetime < 0)
    {
        mutetime = time(NULL) + llabs(mutetime);

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME_LOGIN);
        stmt->setInt64(0, mutetime);
        stmt->setUInt32(1, account.Game.Id);
        LoginDatabase.Execute(stmt);
    }

    if (account.IsBanned())
    {
        SendAuthResponseError(ERROR_DENIED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account banned).");
        sScriptMgr->OnFailedAccountLogin(account.Game.Id);
        DelayedCloseSocket();
        return;
    }

    // Check locked state for server
    AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
    TC_LOG_DEBUG("network", "Allowed Level: %u Player Level %u", allowedAccountType, account.Game.Security);
    if (allowedAccountType > SEC_PLAYER && account.Game.Security < allowedAccountType)
    {
        SendAuthResponseError(ERROR_DENIED);
        TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: User tries to login but his security level is not enough");
        sScriptMgr->OnFailedAccountLogin(account.Game.Id);
        DelayedCloseSocket();
        return;
    }

    TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Client '%s' authenticated successfully from %s.", authSession->RealmJoinTicket.c_str(), address.c_str());

    // Update the last_ip in the database as it was successful for login
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_IP);

    stmt->setString(0, address);
    stmt->setString(1, authSession->RealmJoinTicket);

    LoginDatabase.Execute(stmt);

    // At this point, we can safely hook a successful login
    sScriptMgr->OnAccountLogin(account.Game.Id);

    _authed = true;
    _worldSession = new WorldSession(account.Game.Id, std::move(authSession->RealmJoinTicket), account.BattleNet.Id, shared_from_this(), account.Game.Security,
        account.Game.Expansion, mutetime, account.Game.OS, account.BattleNet.Locale, account.Game.Recruiter, account.Game.IsRectuiter);
    _worldSession->ReadAddonsInfo(authSession->AddonInfo);

    // Initialize Warden system only if it is enabled by config
    if (wardenActive)
        _worldSession->InitWarden(&account.Game.SessionKey);

    _queryCallback = std::bind(&WorldSocket::LoadSessionPermissionsCallback, this, std::placeholders::_1);
    _queryFuture = _worldSession->LoadPermissionsAsync();
    AsyncRead();
}

void WorldSocket::LoadSessionPermissionsCallback(PreparedQueryResult result)
{
    // RBAC must be loaded before adding session to check for skip queue permission
    _worldSession->GetRBACData()->LoadFromDBCallback(result);

    sWorld->AddSession(_worldSession);
}

void WorldSocket::HandleAuthContinuedSession(std::shared_ptr<WorldPackets::Auth::AuthContinuedSession> authSession)
{
    WorldSession::ConnectToKey key;
    key.Raw = authSession->Key;

    _type = ConnectionType(key.Fields.ConnectionType);
    if (_type != CONNECTION_TYPE_INSTANCE)
    {
        SendAuthResponseError(ERROR_DENIED);
        DelayedCloseSocket();
        return;
    }

    // Client switches packet headers after sending CMSG_AUTH_CONTINUED_SESSION
    _headerBuffer.Resize(SizeOfClientHeader[1]);

    uint32 accountId = uint32(key.Fields.AccountId);
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO_CONTINUED_SESSION);
    stmt->setUInt32(0, accountId);

    _queryCallback = std::bind(&WorldSocket::HandleAuthContinuedSessionCallback, this, authSession, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
}

void WorldSocket::HandleAuthContinuedSessionCallback(std::shared_ptr<WorldPackets::Auth::AuthContinuedSession> authSession, PreparedQueryResult result)
{
    if (!result)
    {
        SendAuthResponseError(ERROR_DENIED);
        DelayedCloseSocket();
        return;
    }

    WorldSession::ConnectToKey key;
    key.Raw = authSession->Key;

    uint32 accountId = uint32(key.Fields.AccountId);
    Field* fields = result->Fetch();
    std::string login = fields[0].GetString();
    BigNumber k;
    k.SetHexStr(fields[1].GetCString());

    _authCrypt.Init(&k, _encryptSeed.AsByteArray().get(), _decryptSeed.AsByteArray().get());

    HmacSha256 hmac(40, k.AsByteArray(40).get());
    hmac.UpdateData(reinterpret_cast<uint8 const*>(&authSession->Key), sizeof(authSession->Key));
    hmac.UpdateData(authSession->LocalChallenge.data(), authSession->LocalChallenge.size());
    hmac.UpdateData(_serverChallenge.AsByteArray(16).get(), 16);
    hmac.UpdateData(ContinuedSessionSeed, 16);
    hmac.Finalize();

    if (memcmp(hmac.GetDigest(), authSession->Digest.data(), authSession->Digest.size()))
    {
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthContinuedSession: Authentication failed for account: %u ('%s') address: %s", accountId, login.c_str(), GetRemoteIpAddress().to_string().c_str());
        DelayedCloseSocket();
        return;
    }

    sWorld->AddInstanceSocket(shared_from_this(), authSession->Key);
    AsyncRead();
}

void WorldSocket::HandleConnectToFailed(WorldPackets::Auth::ConnectToFailed& connectToFailed)
{
    if (_worldSession)
    {
        if (_worldSession->PlayerLoading())
        {
            switch (connectToFailed.Serial)
            {
                case WorldPackets::Auth::ConnectToSerial::WorldAttempt1:
                    _worldSession->SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt2);
                    break;
                case WorldPackets::Auth::ConnectToSerial::WorldAttempt2:
                    _worldSession->SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt3);
                    break;
                case WorldPackets::Auth::ConnectToSerial::WorldAttempt3:
                    _worldSession->SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt4);
                    break;
                case WorldPackets::Auth::ConnectToSerial::WorldAttempt4:
                    _worldSession->SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt5);
                    break;
                case WorldPackets::Auth::ConnectToSerial::WorldAttempt5:
                {
                    TC_LOG_ERROR("network", "%s failed to connect 5 times to world socket, aborting login", _worldSession->GetPlayerInfo().c_str());
                    _worldSession->AbortLogin(WorldPackets::Character::LoginFailureReason::NoWorld);
                    break;
                }
                default:
                    return;
            }
        }
        //else
        //{
        //    transfer_aborted when/if we get map node redirection
        //    SendPacketAndLogOpcode(*WorldPackets::Auth::ResumeComms().Write());
        //}
    }
}

void WorldSocket::SendAuthResponseError(uint32 code)
{
    WorldPackets::Auth::AuthResponse response;
    response.Result = code;
    SendPacketAndLogOpcode(*response.Write());
}

bool WorldSocket::HandlePing(WorldPacket& recvPacket)
{
    using namespace std::chrono;

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
                std::unique_lock<std::mutex> sessionGuard(_worldSessionLock);

                if (_worldSession && !_worldSession->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_OVERSPEED_PING))
                {
                    TC_LOG_ERROR("network", "WorldSocket::HandlePing: %s kicked for over-speed pings (address: %s)",
                        _worldSession->GetPlayerInfo().c_str(), GetRemoteIpAddress().to_string().c_str());

                    return false;
                }
            }
        }
        else
            _OverSpeedPings = 0;
    }

    {
        std::lock_guard<std::mutex> sessionGuard(_worldSessionLock);

        if (_worldSession)
        {
            _worldSession->SetLatency(latency);
            _worldSession->ResetClientTimeDelay();
        }
        else
        {
            TC_LOG_ERROR("network", "WorldSocket::HandlePing: peer sent CMSG_PING, but is not authenticated or got recently kicked, address = %s", GetRemoteIpAddress().to_string().c_str());
            return false;
        }
    }

    WorldPacket packet(SMSG_PONG, 4);
    packet << ping;
    SendPacketAndLogOpcode(packet);
    return true;
}
