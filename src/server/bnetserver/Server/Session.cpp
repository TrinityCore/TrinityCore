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

#include "Session.h"
#include "ByteConverter.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "IpBanCheckConnectionInitializer.h"
#include "MapUtils.h"
#include "Memory.h"
#include "QueryCallback.h"
#include "ServiceDispatcher.h"
#include "SessionManager.h"
#include "SslContext.h"
#include "rpc_types.pb.h"

void Battlenet::AccountInfo::LoadResult(PreparedQueryResult result)
{
    // ba.id, ba.email, ba.locked, ba.lock_country, ba.last_ip, ba.LoginTicketExpiry, bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate, bab.unbandate = bab.bandate FROM battlenet_accounts ba LEFT JOIN battlenet_account_bans bab WHERE email = ?
    Field* fields = result->Fetch();
    Id = fields[0].GetUInt32();
    Login = fields[1].GetString();
    IsLockedToIP = fields[2].GetBool();
    LockCountry = fields[3].GetString();
    LastIP = fields[4].GetString();
    LoginTicketExpiry = fields[5].GetUInt32();
    IsBanned = fields[6].GetUInt64() != 0;
    IsPermanenetlyBanned = fields[7].GetUInt64() != 0;

    static constexpr uint32 GameAccountFieldsOffset = 8;

    do
    {
        GameAccounts[result->Fetch()[GameAccountFieldsOffset].GetUInt32()].LoadResult(result->Fetch() + GameAccountFieldsOffset);

    } while (result->NextRow());
}

void Battlenet::GameAccountInfo::LoadResult(Field const* fields)
{
    // a.id, a.username, ab.bandate, ab.unbandate, ab.unbandate = ab.bandate, aa.SecurityLevel
    Id = fields[0].GetUInt32();
    Name = fields[1].GetString();
    BanDate = fields[2].GetUInt32();
    UnbanDate = fields[3].GetUInt32();
    IsPermanenetlyBanned = fields[4].GetUInt32() != 0;
    IsBanned = IsPermanenetlyBanned || UnbanDate > time(nullptr);
    SecurityLevel = AccountTypes(fields[5].GetUInt8());

    std::size_t hashPos = Name.find('#');
    if (hashPos != std::string::npos)
        DisplayName = std::string("WoW") + Name.substr(hashPos + 1);
    else
        DisplayName = Name;
}

constexpr std::size_t PacketHeaderLengthSize = sizeof(uint16);

Battlenet::Session::Session(Trinity::Net::IoContextTcpSocket&& socket) : _socket(CreateSocket(std::move(socket))),
    _packetReadState(PacketReadState::HeaderLength), _packetBuffer(PacketHeaderLengthSize),
    _sessionId(++sSessionMgr.SessionIdGenerator), _creationTime(SystemTimePoint::clock::now()),
    _accountInfo(new AccountInfo()), _gameAccountInfo(nullptr), _locale(),
    _os(), _build(0), _buildVariant(), _timezoneOffset(0min), _ipCountry(), _clientSecret(), _authed(false), _requestToken(0)
{
}

Battlenet::Session::~Session() = default;

std::shared_ptr<Battlenet::Session::Socket> Battlenet::Session::CreateSocket(Trinity::Net::IoContextTcpSocket&& socket)
{
    return std::make_shared<Socket>(std::move(socket), SslContext::instance());
}

void Battlenet::Session::Start()
{
    TC_LOG_TRACE("session", "{} Accepted connection", GetClientInfo());

    // build initializer chain
    std::array<std::shared_ptr<Trinity::Net::SocketConnectionInitializer>, 3> initializers =
    { {
        std::make_shared<Trinity::Net::IpBanCheckConnectionInitializer<Session>>(this),
        std::make_shared<Trinity::Net::SslHandshakeConnectionInitializer<Socket>>(_socket.get()),
        std::make_shared<Trinity::Net::ReadConnectionInitializer<Socket, Session>>(_socket.get(), this),
    } };

    Trinity::Net::SocketConnectionInitializer::SetupChain(initializers)->Start();
}

bool Battlenet::Session::Update()
{
    if (!_socket->Update())
        return false;

    _queryProcessor.ProcessReadyCallbacks();

    return true;
}

Battlenet::GameAccountInfo const* Battlenet::Session::GetGameAccountInfo(uint32 gameAccountId) const
{
    if (!_accountInfo)
        return nullptr;

    return Trinity::Containers::MapGetValuePtr(_accountInfo->GameAccounts, gameAccountId);
}

void Battlenet::Session::AsyncWrite(MessageBuffer* packet)
{
    if (!_socket->IsOpen())
        return;

    _socket->QueuePacket(std::move(*packet));
}

void Battlenet::Session::SendResponse(uint32 token, pb::Message const* response)
{
    bgs::protocol::Header header;
    header.set_token(token);
    header.set_service_id(0xFE);
    header.set_size(response->ByteSize());
    header.set_allocated_ciid(&_clientInstanceId);

    auto ciidGuard = Trinity::make_unique_ptr_with_deleter<&bgs::protocol::Header::release_ciid>(&header);

    uint16 headerSize = header.ByteSize();
    EndianConvertReverse(headerSize);

    MessageBuffer packet(sizeof(headerSize) + header.GetCachedSize() + response->GetCachedSize());
    packet.Write(&headerSize, sizeof(headerSize));
    uint8* ptr = packet.GetWritePointer();
    packet.WriteCompleted(header.GetCachedSize());
    header.SerializePartialToArray(ptr, header.GetCachedSize());
    ptr = packet.GetWritePointer();
    packet.WriteCompleted(response->GetCachedSize());
    response->SerializeToArray(ptr, response->GetCachedSize());

    AsyncWrite(&packet);
}

void Battlenet::Session::SendResponse(uint32 token, uint32 status)
{
    bgs::protocol::Header header;
    header.set_token(token);
    header.set_status(status);
    header.set_service_id(0xFE);
    header.set_allocated_ciid(&_clientInstanceId);

    auto ciidGuard = Trinity::make_unique_ptr_with_deleter<&bgs::protocol::Header::release_ciid>(&header);

    uint16 headerSize = header.ByteSize();
    EndianConvertReverse(headerSize);

    MessageBuffer packet(sizeof(headerSize) + header.GetCachedSize());
    packet.Write(&headerSize, sizeof(headerSize));
    uint8* ptr = packet.GetWritePointer();
    packet.WriteCompleted(header.GetCachedSize());
    header.SerializeToArray(ptr, header.GetCachedSize());

    AsyncWrite(&packet);
}

void Battlenet::Session::SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request, std::function<void(MessageBuffer)> callback)
{
    _responseCallbacks[_requestToken] = std::move(callback);
    SendRequest(serviceHash, methodId, request);
}

void Battlenet::Session::SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request)
{
    bgs::protocol::Header header;
    header.set_service_id(0);
    header.set_service_hash(serviceHash);
    header.set_method_id(methodId);
    header.set_size(request->ByteSize());
    header.set_token(_requestToken++);
    header.set_allocated_ciid(&_clientInstanceId);

    auto ciidGuard = Trinity::make_unique_ptr_with_deleter<&bgs::protocol::Header::release_ciid>(&header);

    uint16 headerSize = header.ByteSize();
    EndianConvertReverse(headerSize);

    MessageBuffer packet(sizeof(headerSize) + header.GetCachedSize() + request->GetCachedSize());
    packet.Write(&headerSize, sizeof(headerSize));
    uint8* ptr = packet.GetWritePointer();
    packet.WriteCompleted(header.GetCachedSize());
    header.SerializeToArray(ptr, header.GetCachedSize());
    ptr = packet.GetWritePointer();
    packet.WriteCompleted(request->GetCachedSize());
    request->SerializeToArray(ptr, request->GetCachedSize());

    AsyncWrite(&packet);
}

void Battlenet::Session::QueueQuery(QueryCallback&& queryCallback)
{
    _queryProcessor.AddCallback(std::move(queryCallback));
}

void Battlenet::Session::OnLogon(std::string_view platform, std::string_view locale, uint32 applicationVersion, Minutes timezoneOffset)
{
    _locale = locale;
    _os = platform;
    _build = applicationVersion;

    _timezoneOffset = timezoneOffset;
}

void Battlenet::Session::OnLogonSuccess(std::shared_ptr<AccountInfo> accountInfo, std::string_view ipCountry)
{
    _accountInfo = std::move(accountInfo);
    _ipCountry = ipCountry;
    _authed = true;
}

void Battlenet::Session::SetClientInfo(uint32 gameAccountId, ClientBuild::VariantId buildVariant, std::array<uint8, 32> const& clientSecret)
{
    _gameAccountInfo = GetGameAccountInfo(gameAccountId);
    _buildVariant = buildVariant;
    _clientSecret = clientSecret;
}

Battlenet::LastPlayedCharacterInfo const* Battlenet::Session::GetLastPlayedCharacter(std::string_view subRegion) const
{
    auto itr = _gameAccountInfo->LastPlayedCharacters.find(subRegion);
    return itr != _gameAccountInfo->LastPlayedCharacters.end() ? &itr->second : nullptr;
}

template<bool(Battlenet::Session::*processMethod)()>
static inline Optional<Trinity::Net::SocketReadCallbackResult> PartialProcessPacket(Battlenet::Session* session, MessageBuffer& inputBuffer, MessageBuffer& buffer)
{
    // We have full read header, now check the data payload
    if (buffer.GetRemainingSpace() > 0)
    {
        // need more data in the payload
        std::size_t readDataSize = std::min(inputBuffer.GetActiveSize(), buffer.GetRemainingSpace());
        buffer.Write(inputBuffer.GetReadPointer(), readDataSize);
        inputBuffer.ReadCompleted(readDataSize);
    }

    if (buffer.GetRemainingSpace() > 0)
    {
        // Couldn't receive the whole data this time.
        ASSERT(inputBuffer.GetActiveSize() == 0);
        return Trinity::Net::SocketReadCallbackResult::KeepReading;
    }

    // just received fresh new payload
    if (!(session->*processMethod)())
    {
        session->CloseSocket();
        return Trinity::Net::SocketReadCallbackResult::Stop;
    }

    return { }; // go to next state
}

Trinity::Net::SocketReadCallbackResult Battlenet::Session::ReadHandler()
{
    MessageBuffer& packet = _socket->GetReadBuffer();
    while (packet.GetActiveSize() > 0)
    {
        switch (_packetReadState)
        {
            case PacketReadState::HeaderLength:
                if (Optional<Trinity::Net::SocketReadCallbackResult> partialResult = PartialProcessPacket<&Session::ReadHeaderLengthHandler>(this, packet, _packetBuffer))
                    return *partialResult;
                [[fallthrough]];
            case PacketReadState::Header:
                if (Optional<Trinity::Net::SocketReadCallbackResult> partialResult = PartialProcessPacket<&Session::ReadHeaderHandler>(this, packet, _packetBuffer))
                    return *partialResult;
                [[fallthrough]];
            case PacketReadState::Data:
                if (Optional<Trinity::Net::SocketReadCallbackResult> partialResult = PartialProcessPacket<&Session::ReadDataHandler>(this, packet, _packetBuffer))
                    return *partialResult;
                break;
        }
    }

    return Trinity::Net::SocketReadCallbackResult::KeepReading;
}

bool Battlenet::Session::ReadHeaderLengthHandler()
{
    uint16 len = *reinterpret_cast<uint16*>(_packetBuffer.GetReadPointer());
    _packetBuffer.ReadCompleted(PacketHeaderLengthSize);

    EndianConvertReverse(len);

    _packetReadState = PacketReadState::Header;
    _packetBuffer.Resize(_packetBuffer.GetBufferSize() + len);
    return true;
}

bool Battlenet::Session::ReadHeaderHandler()
{
    bgs::protocol::Header header;
    if (!header.ParseFromArray(_packetBuffer.GetReadPointer(), _packetBuffer.GetActiveSize()))
        return false;

    _packetBuffer.ReadCompleted(_packetBuffer.GetActiveSize());

    _packetReadState = PacketReadState::Data;
    _packetBuffer.Resize(_packetBuffer.GetBufferSize() + header.size());
    return true;
}

bool Battlenet::Session::ReadDataHandler()
{
    bgs::protocol::Header header;
    bool parseSuccess = header.ParseFromArray(_packetBuffer.GetBasePointer() + PacketHeaderLengthSize, _packetBuffer.GetReadPointer() - _packetBuffer.GetBasePointer() - PacketHeaderLengthSize);
    ASSERT(parseSuccess);

    if (header.service_id() != 0xFE)
    {
        sServiceDispatcher.Dispatch(this, header.service_hash(), header.token(), header.method_id(), std::move(_packetBuffer));
    }
    else
    {
        if (auto responseCallback = _responseCallbacks.extract(header.token()))
            responseCallback.mapped()(std::move(_packetBuffer));
        else
            _packetBuffer.Reset();
    }

    _packetReadState = PacketReadState::HeaderLength;
    _packetBuffer.Resize(PacketHeaderLengthSize);
    return true;
}

std::string Battlenet::Session::GetClientInfo() const
{
    std::ostringstream stream;
    stream << '[' << _socket->GetRemoteIpAddress() << ':' << _socket->GetRemotePort();
    if (_accountInfo && !_accountInfo->Login.empty())
        stream << ", Account: " << _accountInfo->Login;

    if (_gameAccountInfo)
        stream << ", Game account: " << _gameAccountInfo->Name;

    stream << ']';

    return std::move(stream).str();
}
