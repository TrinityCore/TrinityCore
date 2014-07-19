/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "AuthCodes.h"
#include "BattlenetBitStream.h"
#include "BattlenetSession.h"
#include "Database/DatabaseEnv.h"
#include "HmacHash.h"
#include "Log.h"
#include "RealmList.h"
#include "SHA256.h"
#include <map>
#include <boost/asio/write.hpp>

std::map<Battlenet::PacketHeader, Battlenet::Session::PacketHandler> InitHandlers()
{
    std::map<Battlenet::PacketHeader, Battlenet::Session::PacketHandler> handlers;

    handlers[Battlenet::PacketHeader(Battlenet::CMSG_AUTH_CHALLENGE, Battlenet::AUTHENTICATION)] = &Battlenet::Session::HandleAuthChallenge;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_AUTH_RECONNECT, Battlenet::AUTHENTICATION)] = &Battlenet::Session::HandleAuthReconnect;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_AUTH_PROOF_RESPONSE, Battlenet::AUTHENTICATION)] = &Battlenet::Session::HandleAuthProofResponse;

    handlers[Battlenet::PacketHeader(Battlenet::CMSG_PING, Battlenet::CONNECTION)] = &Battlenet::Session::HandlePing;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_ENABLE_ENCRYPTION, Battlenet::CONNECTION)] = &Battlenet::Session::HandleEnableEncryption;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_DISCONNECT, Battlenet::CONNECTION)] = &Battlenet::Session::HandleDisconnect;

    handlers[Battlenet::PacketHeader(Battlenet::CMSG_REALM_UPDATE_SUBSCRIBE, Battlenet::WOW)] = &Battlenet::Session::HandleRealmUpdateSubscribe;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_JOIN_REQUEST, Battlenet::WOW)] = &Battlenet::Session::HandleRealmJoinRequest;

    return handlers;
}

std::map<Battlenet::PacketHeader, Battlenet::Session::PacketHandler> Handlers = InitHandlers();

Battlenet::Session::ModuleHandler const Battlenet::Session::ModuleHandlers[MODULE_COUNT] =
{
    &Battlenet::Session::HandlePasswordModule,
    &Battlenet::Session::UnhandledModule,
    &Battlenet::Session::UnhandledModule,
    &Battlenet::Session::HandleSelectGameAccountModule,
    &Battlenet::Session::HandleRiskFingerprintModule,
    &Battlenet::Session::HandleResumeModule,
};

Battlenet::Session::Session(tcp::socket&& socket) : _socket(std::move(socket)), _accountId(0), _accountName(), _locale(),
    _os(), _build(0), _gameAccountId(0), _gameAccountIndex(0), _accountSecurityLevel(SEC_PLAYER), I(), s(), v(), b(), B(), K(),
    _reconnectProof(), _crypt(), _authed(false)
{
    static uint8 const N_Bytes[] =
    {
        0xAB, 0x24, 0x43, 0x63, 0xA9, 0xC2, 0xA6, 0xC3, 0x3B, 0x37, 0xE4, 0x61, 0x84, 0x25, 0x9F, 0x8B,
        0x3F, 0xCB, 0x8A, 0x85, 0x27, 0xFC, 0x3D, 0x87, 0xBE, 0xA0, 0x54, 0xD2, 0x38, 0x5D, 0x12, 0xB7,
        0x61, 0x44, 0x2E, 0x83, 0xFA, 0xC2, 0x21, 0xD9, 0x10, 0x9F, 0xC1, 0x9F, 0xEA, 0x50, 0xE3, 0x09,
        0xA6, 0xE5, 0x5E, 0x23, 0xA7, 0x77, 0xEB, 0x00, 0xC7, 0xBA, 0xBF, 0xF8, 0x55, 0x8A, 0x0E, 0x80,
        0x2B, 0x14, 0x1A, 0xA2, 0xD4, 0x43, 0xA9, 0xD4, 0xAF, 0xAD, 0xB5, 0xE1, 0xF5, 0xAC, 0xA6, 0x13,
        0x1C, 0x69, 0x78, 0x64, 0x0B, 0x7B, 0xAF, 0x9C, 0xC5, 0x50, 0x31, 0x8A, 0x23, 0x08, 0x01, 0xA1,
        0xF5, 0xFE, 0x31, 0x32, 0x7F, 0xE2, 0x05, 0x82, 0xD6, 0x0B, 0xED, 0x4D, 0x55, 0x32, 0x41, 0x94,
        0x29, 0x6F, 0x55, 0x7D, 0xE3, 0x0F, 0x77, 0x19, 0xE5, 0x6C, 0x30, 0xEB, 0xDE, 0xF6, 0xA7, 0x86
    };

    N.SetBinary(N_Bytes, sizeof(N_Bytes));
    g.SetDword(2);

    SHA256Hash sha;
    sha.UpdateBigNumbers(&N, &g, NULL);
    sha.Finalize();
    k.SetBinary(sha.GetDigest(), sha.GetLength());
}

Battlenet::Session::~Session()
{
    TC_LOG_TRACE("server.battlenet", "Battlenet::Session::OnClose");
}

void Battlenet::Session::_SetVSFields(std::string const& pstr)
{
    s.SetRand(uint32(BufferSizes::SRP_6_S) * 8);

    BigNumber p;
    p.SetHexStr(pstr.c_str());

    SHA256Hash sha;
    sha.UpdateBigNumbers(&s, &p, NULL);
    sha.Finalize();
    BigNumber x;
    x.SetBinary(sha.GetDigest(), sha.GetLength());
    v = g.ModExp(x, N);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_VS_FIELDS);
    stmt->setString(0, v.AsHexStr());
    stmt->setString(1, s.AsHexStr());
    stmt->setString(2, _accountName);

    LoginDatabase.Execute(stmt);
}

bool Battlenet::Session::HandleAuthChallenge(PacketHeader& header, BitStream& packet)
{
    // Verify that this IP is not in the ip_banned table
    LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));

    std::string const& ip_address = GetRemoteAddress();
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_BANNED);
    stmt->setString(0, ip_address);
    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(LOGIN_BANNED);
        AsyncWrite(complete);
        TC_LOG_DEBUG("server.battlenet", "[Battlenet::AuthChallenge] Banned ip '%s:%d' tries to login!", ip_address.c_str(), GetRemotePort());
        return true;
    }

    AuthChallenge info(header, packet);
    info.Read();

    if (info.Program != "WoW")
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_INVALID_PROGRAM);
        AsyncWrite(complete);
        return true;
    }

    if (!sBattlenetMgr->HasPlatform(info.Platform))
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_INVALID_OS);
        AsyncWrite(complete);
        return true;
    }

    if (!sBattlenetMgr->HasPlatform(info.Locale))
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_UNSUPPORTED_LANGUAGE);
        AsyncWrite(complete);
        return true;
    }

    for (Component const& component : info.Components)
    {
        if (!sBattlenetMgr->HasComponent(&component))
        {
            AuthComplete* complete = new AuthComplete();
            if (!sBattlenetMgr->HasProgram(component.Program))
                complete->SetAuthResult(AUTH_INVALID_PROGRAM);
            else if (!sBattlenetMgr->HasPlatform(component.Platform))
                complete->SetAuthResult(AUTH_INVALID_OS);
            else
            {
                if (component.Program != "WoW" || AuthHelper::IsBuildSupportingBattlenet(component.Build))
                    complete->SetAuthResult(AUTH_REGION_BAD_VERSION);
                else
                    complete->SetAuthResult(AUTH_USE_GRUNT_LOGON);
            }

            AsyncWrite(complete);
            return true;
        }

        if (component.Platform == "base")
            _build = component.Build;
    }

    _accountName = info.Login;
    _locale = info.Locale;
    _os = info.Platform;

    Utf8ToUpperOnlyLatin(_accountName);
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_INFO);
    stmt->setString(0, _accountName);

    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        AsyncWrite(complete);
        return true;
    }

    Field* fields = result->Fetch();

    _accountId = fields[1].GetUInt32();

    // If the IP is 'locked', check that the player comes indeed from the correct IP address
    if (fields[2].GetUInt8() == 1)                  // if ip is locked
    {
        TC_LOG_DEBUG("server.battlenet", "[Battlenet::AuthChallenge] Account '%s' is locked to IP - '%s' is logging in from '%s'", _accountName.c_str(), fields[4].GetCString(), ip_address.c_str());

        if (strcmp(fields[4].GetCString(), ip_address.c_str()) != 0)
        {
            AuthComplete* complete = new AuthComplete();
            complete->SetAuthResult(AUTH_ACCOUNT_LOCKED);
            AsyncWrite(complete);
            return true;
        }
    }
    else
    {
        TC_LOG_DEBUG("server.battlenet", "[Battlenet::AuthChallenge] Account '%s' is not locked to ip", _accountName.c_str());
        std::string accountCountry = fields[3].GetString();
        if (accountCountry.empty() || accountCountry == "00")
            TC_LOG_DEBUG("server.battlenet", "[Battlenet::AuthChallenge] Account '%s' is not locked to country", _accountName.c_str());
        else if (!accountCountry.empty())
        {
            uint32 ip = inet_addr(ip_address.c_str());
            EndianConvertReverse(ip);

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGON_COUNTRY);
            stmt->setUInt32(0, ip);
            if (PreparedQueryResult sessionCountryQuery = LoginDatabase.Query(stmt))
            {
                std::string loginCountry = (*sessionCountryQuery)[0].GetString();
                TC_LOG_DEBUG("server.battlenet", "[Battlenet::AuthChallenge] Account '%s' is locked to country: '%s' Player country is '%s'", _accountName.c_str(), accountCountry.c_str(), loginCountry.c_str());
                if (loginCountry != accountCountry)
                {
                    AuthComplete* complete = new AuthComplete();
                    complete->SetAuthResult(AUTH_ACCOUNT_LOCKED);
                    AsyncWrite(complete);
                    return true;
                }
            }
        }
    }

    //set expired bans to inactive
    LoginDatabase.DirectExecute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_EXPIRED_BANS));

    // If the account is banned, reject the logon attempt
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACTIVE_ACCOUNT_BAN);
    stmt->setUInt32(0, _accountId);
    PreparedQueryResult banresult = LoginDatabase.Query(stmt);
    if (banresult)
    {
        Field* fields = banresult->Fetch();
        if (fields[0].GetUInt32() == fields[1].GetUInt32())
        {
            AuthComplete* complete = new AuthComplete();
            complete->SetAuthResult(LOGIN_BANNED);
            AsyncWrite(complete);
            TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::AuthChallenge] Banned account %s tried to login!", ip_address.c_str(), GetRemotePort(), _accountName.c_str());
            return true;
        }
        else
        {
            AuthComplete* complete = new AuthComplete();
            complete->SetAuthResult(LOGIN_SUSPENDED);
            AsyncWrite(complete);
            TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::AuthChallenge] Temporarily banned account %s tried to login!", ip_address.c_str(), GetRemotePort(), _accountName.c_str());
            return true;
        }
    }

    SHA256Hash sha;
    sha.UpdateData(_accountName);
    sha.Finalize();

    I.SetBinary(sha.GetDigest(), sha.GetLength());

    ModuleInfo* password = sBattlenetMgr->CreateModule(_os, "Password");
    ModuleInfo* thumbprint = sBattlenetMgr->CreateModule(_os, "Thumbprint");

    std::string pStr = fields[0].GetString();

    std::string databaseV = fields[5].GetString();
    std::string databaseS = fields[6].GetString();

    if (databaseV.size() != size_t(BufferSizes::SRP_6_V) * 2 || databaseS.size() != size_t(BufferSizes::SRP_6_S) * 2)
        _SetVSFields(pStr);
    else
    {
        s.SetHexStr(databaseS.c_str());
        v.SetHexStr(databaseV.c_str());
    }

    b.SetRand(128 * 8);
    B = ((v * k) + g.ModExp(b, N)) % N;
    BigNumber unk;
    unk.SetRand(128 * 8);

    BitStream passwordData;
    uint8 state = 0;
    passwordData.WriteBytes(&state, 1);
    passwordData.WriteBytes(I.AsByteArray(32).get(), 32);
    passwordData.WriteBytes(s.AsByteArray(32).get(), 32);
    passwordData.WriteBytes(B.AsByteArray(128).get(), 128);
    passwordData.WriteBytes(unk.AsByteArray(128).get(), 128);

    password->DataSize = passwordData.GetSize();
    password->Data = new uint8[password->DataSize];
    memcpy(password->Data, passwordData.GetBuffer(), password->DataSize);

    _modulesWaitingForData.push(MODULE_PASSWORD);

    ProofRequest* request = new ProofRequest();
    request->Modules.push_back(password);
    // if has authenticator, send Token module
    request->Modules.push_back(thumbprint);
    AsyncWrite(request);
    return true;
}

bool Battlenet::Session::HandleAuthReconnect(PacketHeader& header, BitStream& packet)
{
    AuthResumeInfo reconnect(header, packet);
    reconnect.Read();

    TC_LOG_DEBUG("server.battlenet", "%s", reconnect.ToString().c_str());

    _accountName = reconnect.Login;
    _locale = reconnect.Locale;
    _os = reconnect.Platform;
    auto baseComponent = std::find_if(reconnect.Components.begin(), reconnect.Components.end(), [](Component const& c) { return c.Program == "base"; });
    if (baseComponent != reconnect.Components.end())
        _build = baseComponent->Build;

    uint8 accountIndex = atol(reconnect.GameAccountName.substr(reconnect.GameAccountName.find_last_of('#') + 1).c_str());

    Utf8ToUpperOnlyLatin(_accountName);
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_RECONNECT_INFO);
    stmt->setString(0, _accountName);
    stmt->setUInt8(1, accountIndex);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        AuthResume* resume = new AuthResume();
        resume->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        AsyncWrite(resume);
        return false;
    }

    Field* fields = result->Fetch();

    _accountId = fields[0].GetUInt32();
    K.SetHexStr(fields[1].GetString().c_str());
    _gameAccountId = fields[2].GetUInt32();
    _gameAccountIndex = accountIndex;

    ModuleInfo* thumbprint = sBattlenetMgr->CreateModule(_os, "Thumbprint");
    ModuleInfo* resume = sBattlenetMgr->CreateModule(_os, "Resume");
    BitStream resumeData;
    uint8 state = 0;
    _reconnectProof.SetRand(16 * 8);

    resumeData.WriteBytes(&state, 1);
    resumeData.WriteBytes(_reconnectProof.AsByteArray().get(), 16);

    resume->DataSize = resumeData.GetSize();
    resume->Data = new uint8[resume->DataSize];
    memcpy(resume->Data, resumeData.GetBuffer(), resume->DataSize);

    _modulesWaitingForData.push(MODULE_RESUME);

    ProofRequest* request = new ProofRequest();
    request->Modules.push_back(thumbprint);
    request->Modules.push_back(resume);
    AsyncWrite(request);
    return true;
}

bool Battlenet::Session::HandleAuthProofResponse(PacketHeader& header, BitStream& packet)
{
    ProofResponse proof(header, packet);
    proof.Read();

    if (_modulesWaitingForData.size() < proof.Modules.size())
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        AsyncWrite(complete);
        return true;
    }

    ServerPacket* response = nullptr;
    for (size_t i = 0; i < proof.Modules.size(); ++i)
    {
        if (!(this->*(ModuleHandlers[_modulesWaitingForData.front()]))(proof.Modules[i], &response))
            break;

        _modulesWaitingForData.pop();
    }

    if (!response)
    {
        response = new AuthComplete();
        static_cast<AuthComplete*>(response)->SetAuthResult(AUTH_INTERNAL_ERROR);
    }

    AsyncWrite(response);
    return true;
}

bool Battlenet::Session::HandlePing(PacketHeader& /*header*/, BitStream& /*packet*/)
{
    AsyncWrite(new Pong());
    return true;
}

bool Battlenet::Session::HandleEnableEncryption(PacketHeader& /*header*/, BitStream& /*packet*/)
{
    _crypt.Init(&K);
    return true;
}

bool Battlenet::Session::HandleDisconnect(PacketHeader& /*header*/, BitStream& /*packet*/)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_SESSION_KEY);
    stmt->setString(0, "");
    stmt->setBool(1, false);
    stmt->setUInt32(2, _accountId);
    LoginDatabase.Execute(stmt);
    return true;
}

bool Battlenet::Session::HandleRealmUpdateSubscribe(PacketHeader& /*header*/, BitStream& /*packet*/)
{
    sRealmList.UpdateIfNeed();

    RealmCharacterCounts* counts = new RealmCharacterCounts();

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS);
    stmt->setUInt32(0, _gameAccountId);

    if (PreparedQueryResult countResult = LoginDatabase.Query(stmt))
    {
        do
        {
            Field* fields = countResult->Fetch();
            uint32 build = fields[4].GetUInt32();
            counts->CharacterCounts.push_back({ { fields[2].GetUInt8(), fields[3].GetUInt8(), fields[1].GetUInt32(), (_build != build ? build : 0) }, fields[0].GetUInt8() });
        } while (countResult->NextRow());
    }

    for (RealmList::RealmMap::const_iterator i = sRealmList.begin(); i != sRealmList.end(); ++i)
    {
        Realm const& realm = i->second;

        uint32 flag = realm.flag;
        RealmBuildInfo const* buildInfo = AuthHelper::GetBuildInfo(realm.gamebuild);
        if (realm.gamebuild != _build)
        {
            if (!buildInfo)
                continue;

            flag |= REALM_FLAG_OFFLINE | REALM_FLAG_SPECIFYBUILD;   // tell the client what build the realm is for
        }

        if (!buildInfo)
            flag &= ~REALM_FLAG_SPECIFYBUILD;

        RealmUpdate* update = new RealmUpdate();
        update->Timezone = realm.timezone;
        update->Population = realm.populationLevel;
        update->Lock = (realm.allowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;
        update->Type = realm.icon;
        update->Name = realm.name;

        if (flag & REALM_FLAG_SPECIFYBUILD)
        {
            std::ostringstream version;
            version << buildInfo->MajorVersion << '.' << buildInfo->MinorVersion << '.' << buildInfo->BugfixVersion << '.' << buildInfo->Build;

            update->Version = version.str();
            update->Address = realm.GetAddressForClient(_socket.remote_endpoint().address());
            update->Build = buildInfo->Build;
        }

        update->Flags = flag;
        update->Region = realm.Region;
        update->Battlegroup = realm.Battlegroup;
        update->Index = realm.m_ID;

        counts->RealmData.push_back(update);
    }

    counts->RealmData.push_back(new RealmUpdateComplete());

    AsyncWrite(counts);
    return true;
}

bool Battlenet::Session::HandleRealmJoinRequest(PacketHeader& header, BitStream& packet)
{
    RealmJoinRequest join(header, packet);
    join.Read();

    RealmJoinResult* result = new RealmJoinResult();
    Realm const* realm = sRealmList.GetRealm(join.Realm);
    if (!realm || realm->flag & (REALM_FLAG_INVALID | REALM_FLAG_OFFLINE))
    {
        AsyncWrite(result);
        return true;
    }

    result->ServerSeed = uint32(rand32());

    uint8 sessionKey[40];
    HmacSha1 hmac(K.GetNumBytes(), K.AsByteArray().get());
    hmac.UpdateData((uint8*)"WoW\0", 4);
    hmac.UpdateData((uint8*)&join.ClientSeed, 4);
    hmac.UpdateData((uint8*)&result->ServerSeed, 4);
    hmac.Finalize();

    memcpy(sessionKey, hmac.GetDigest(), hmac.GetLength());

    HmacSha1 hmac2(K.GetNumBytes(), K.AsByteArray().get());
    hmac2.UpdateData((uint8*)"WoW\0", 4);
    hmac2.UpdateData((uint8*)&result->ServerSeed, 4);
    hmac2.UpdateData((uint8*)&join.ClientSeed, 4);
    hmac2.Finalize();

    memcpy(sessionKey + hmac.GetLength(), hmac2.GetDigest(), hmac2.GetLength());

    LoginDatabase.DirectPExecute("UPDATE account SET sessionkey = '%s', last_ip = '%s', last_login = NOW(), locale = %u, failed_logins = 0, os = '%s' WHERE id = %u",
        ByteArrayToHexStr(sessionKey, 40, true).c_str(), GetRemoteAddress().c_str(), GetLocaleByName(_locale), _os.c_str(), _gameAccountId);

    result->IPv4.emplace_back(realm->ExternalAddress, realm->port);
    if (realm->ExternalAddress != realm->LocalAddress)
        result->IPv4.emplace_back(realm->LocalAddress, realm->port);

    AsyncWrite(result);
    return true;
}

void Battlenet::Session::AsyncRead()
{
    auto self(shared_from_this());

    _socket.async_read_some(boost::asio::buffer(_readBuffer, size_t(BufferSizes::Read)), [this, self](boost::system::error_code error, size_t transferedBytes)
    {
        if (error)
        {
            _socket.close();
            return;
        }

        BitStream packet(transferedBytes);
        std::memcpy(packet.GetBuffer(), _readBuffer, transferedBytes);
        _crypt.DecryptRecv(packet.GetBuffer(), transferedBytes);

        while (!packet.IsRead())
        {
            try
            {
                PacketHeader header;
                header.Opcode = packet.Read<uint32>(6);
                if (packet.Read<bool>(1))
                    header.Channel = packet.Read<int32>(4);

                if (header.Channel != AUTHENTICATION && !_authed)
                {
                    TC_LOG_DEBUG("server.battlenet", "Battlenet::Session::AsyncRead Received not allowed packet %s", header.ToString().c_str());
                    _socket.close();
                    return;
                }

                TC_LOG_TRACE("server.battlenet", "Battlenet::Session::AsyncRead %s", header.ToString().c_str());
                std::map<PacketHeader, PacketHandler>::const_iterator itr = Handlers.find(header);
                if (itr != Handlers.end())
                {
                    if ((this->*(itr->second))(header, packet))
                        break;
                }
                else
                {
                    TC_LOG_DEBUG("server.battlenet", "Battlenet::Session::AsyncRead Unhandled opcode %s", header.ToString().c_str());
                    break;
                }

                packet.AlignToNextByte();
            }
            catch (BitStreamPositionException const& e)
            {
                TC_LOG_ERROR("server.battlenet", "Battlenet::Session::AsyncRead Exception: %s", e.what());
                _socket.close();
                return;
            }
        }

        AsyncRead();
    });
}

void Battlenet::Session::Start()
{
    TC_LOG_TRACE("server.battlenet", "Battlenet::Session::Start");
    AsyncRead();
}

void Battlenet::Session::AsyncWrite(ServerPacket* packet)
{
    TC_LOG_TRACE("server.battlenet", "Battlenet::Session::AsyncWrite %s", packet->ToString().c_str());

    packet->Write();

    _crypt.EncryptSend(const_cast<uint8*>(packet->GetData()), packet->GetSize());

    auto self(shared_from_this());

    boost::asio::async_write(_socket, boost::asio::buffer(packet->GetData(), packet->GetSize()), [this, self, packet](boost::system::error_code error, std::size_t /*length*/)
    {
        if (error)
            _socket.close();

        delete packet;
    });
}

inline void ReplaceResponse(Battlenet::ServerPacket** oldResponse, Battlenet::ServerPacket* newResponse)
{
    if (*oldResponse)
        delete *oldResponse;

    *oldResponse = newResponse;
}

bool Battlenet::Session::HandlePasswordModule(BitStream* dataStream, ServerPacket** response)
{
    if (dataStream->GetSize() != 1 + 128 + 32 + 128)
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, complete);
        return false;
    }

    if (dataStream->Read<uint8>(8) != 2)                // State
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, complete);
        return false;
    }


    BigNumber A, clientM1, clientChallenge;
    A.SetBinary(dataStream->ReadBytes(128).get(), 128);
    clientM1.SetBinary(dataStream->ReadBytes(32).get(), 32);
    clientChallenge.SetBinary(dataStream->ReadBytes(128).get(), 128);

    if (A.isZero())
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, complete);
        return false;
    }

    SHA256Hash sha;
    sha.UpdateBigNumbers(&A, &B, NULL);
    sha.Finalize();

    BigNumber u;
    u.SetBinary(sha.GetDigest(), sha.GetLength());

    BigNumber S = ((A * v.ModExp(u, N)) % N).ModExp(b, N);

    uint8 S_bytes[128];
    memcpy(S_bytes, S.AsByteArray(128).get(), 128);

    uint8 part1[64];
    uint8 part2[64];

    for (int i = 0; i < 64; ++i)
    {
        part1[i] = S_bytes[i * 2];
        part2[i] = S_bytes[i * 2 + 1];
    }

    SHA256Hash part1sha, part2sha;
    part1sha.UpdateData(part1, 64);
    part1sha.Finalize();
    part2sha.UpdateData(part2, 64);
    part2sha.Finalize();

    uint8 sessionKey[SHA256_DIGEST_LENGTH * 2];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        sessionKey[i * 2] = part1sha.GetDigest()[i];
        sessionKey[i * 2 + 1] = part2sha.GetDigest()[i];
    }

    K.SetBinary(sessionKey, SHA256_DIGEST_LENGTH * 2);

    BigNumber M1;

    uint8 hash[SHA256_DIGEST_LENGTH];
    sha.Initialize();
    sha.UpdateBigNumbers(&N, NULL);
    sha.Finalize();
    memcpy(hash, sha.GetDigest(), sha.GetLength());

    sha.Initialize();
    sha.UpdateBigNumbers(&g, NULL);
    sha.Finalize();

    for (int i = 0; i < sha.GetLength(); ++i)
        hash[i] ^= sha.GetDigest()[i];

    SHA256Hash shaI;
    shaI.UpdateData(ByteArrayToHexStr(I.AsByteArray().get(), 32));
    shaI.Finalize();

    // Concat all variables for M1 hash
    sha.Initialize();
    sha.UpdateData(hash, SHA256_DIGEST_LENGTH);
    sha.UpdateData(shaI.GetDigest(), shaI.GetLength());
    sha.UpdateBigNumbers(&s, &A, &B, &K, NULL);
    sha.Finalize();

    M1.SetBinary(sha.GetDigest(), sha.GetLength());

    if (memcmp(M1.AsByteArray().get(), clientM1.AsByteArray().get(), 32))
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        ReplaceResponse(response, complete);
        return false;
    }

    uint64 numAccounts = 0;
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNTS);
    stmt->setUInt32(0, _accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (result)
        numAccounts = result->GetRowCount();

    if (!numAccounts)
    {
        AuthComplete* noAccounts = new AuthComplete();
        noAccounts->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, noAccounts);
        return false;
    }

    Field* fields = result->Fetch();

    //set expired game account bans to inactive
    LoginDatabase.DirectExecute(LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS));

    BigNumber M;
    sha.Initialize();
    sha.UpdateBigNumbers(&A, &M1, &K, NULL);
    sha.Finalize();
    M.SetBinary(sha.GetDigest(), sha.GetLength());

    BigNumber serverProof;
    serverProof.SetRand(128 * 8); // just send garbage, server signature check is patched out in client

    BitStream stream;
    ModuleInfo* password = sBattlenetMgr->CreateModule(_os, "Password");
    uint8 state = 3;

    stream.WriteBytes(&state, 1);
    stream.WriteBytes(M.AsByteArray(32).get(), 32);
    stream.WriteBytes(serverProof.AsByteArray(128).get(), 128);

    password->DataSize = stream.GetSize();
    password->Data = new uint8[password->DataSize];
    memcpy(password->Data, stream.GetBuffer(), password->DataSize);

    ProofRequest* request = new ProofRequest();
    request->Modules.push_back(password);
    if (numAccounts > 1)
    {
        BitStream accounts;
        state = 0;
        accounts.WriteBytes(&state, 1);
        accounts.Write(numAccounts, 8);
        do
        {
            fields = result->Fetch();
            std::ostringstream name;
            name << "WoW" << uint32(fields[0].GetUInt8());
            accounts.Write(2, 8);
            accounts.WriteString(name.str(), 8);
        } while (result->NextRow());

        ModuleInfo* selectGameAccount = sBattlenetMgr->CreateModule(_os, "SelectGameAccount");
        selectGameAccount->DataSize = accounts.GetSize();
        selectGameAccount->Data = new uint8[selectGameAccount->DataSize];
        memcpy(selectGameAccount->Data, accounts.GetBuffer(), selectGameAccount->DataSize);
        request->Modules.push_back(selectGameAccount);
        _modulesWaitingForData.push(MODULE_SELECT_GAME_ACCOUNT);
    }
    else
    {
        if (fields[4].GetBool())
        {
            delete request;

            AuthComplete* complete = new AuthComplete();
            if (fields[2].GetUInt32() == fields[3].GetUInt32())
            {
                complete->SetAuthResult(LOGIN_BANNED);
                TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::AuthChallenge] Banned account %s tried to login!", GetRemoteAddress().c_str(), GetRemotePort(), _accountName.c_str());
            }
            else
            {
                complete->SetAuthResult(LOGIN_SUSPENDED);
                TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::AuthChallenge] Temporarily banned account %s tried to login!", GetRemoteAddress().c_str(), GetRemotePort(), _accountName.c_str());
            }

            ReplaceResponse(response, complete);
            return false;
        }

        _gameAccountId = fields[1].GetUInt32();
        _gameAccountIndex = fields[0].GetUInt8();

        request->Modules.push_back(sBattlenetMgr->CreateModule(_os, "RiskFingerprint"));
        _modulesWaitingForData.push(MODULE_RISK_FINGERPRINT);
    }

    ReplaceResponse(response, request);
    return true;
}

bool Battlenet::Session::HandleSelectGameAccountModule(BitStream* dataStream, ServerPacket** response)
{
    if (dataStream->Read<uint8>(8) != 1)
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, complete);
        return false;
    }

    dataStream->Read<uint8>(8);
    std::string account = dataStream->ReadString(8);
    if (account.length() < 4)
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, complete);
        return false;
    }

    uint8 accountIndex = atol(account.substr(3).c_str());

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT);
    stmt->setUInt8(0, accountIndex);
    stmt->setUInt32(1, _accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        AuthComplete* complete = new AuthComplete();
        complete->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, complete);
        return false;
    }

    Field* fields = result->Fetch();
    if (fields[3].GetBool())
    {
        AuthComplete* complete = new AuthComplete();
        if (fields[1].GetUInt32() == fields[2].GetUInt32())
        {
            complete->SetAuthResult(LOGIN_BANNED);
            TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::SelectGameAccount] Banned account %s tried to login!", GetRemoteAddress().c_str(), GetRemotePort(), _accountName.c_str());
        }
        else
        {
            complete->SetAuthResult(LOGIN_SUSPENDED);
            TC_LOG_DEBUG("server.battlenet", "'%s:%d' [Battlenet::SelectGameAccount] Temporarily banned account %s tried to login!", GetRemoteAddress().c_str(), GetRemotePort(), _accountName.c_str());
        }

        ReplaceResponse(response, complete);
        return false;
    }

    _gameAccountId = fields[0].GetUInt32();
    _gameAccountIndex = accountIndex;

    ProofRequest* request = new ProofRequest();
    request->Modules.push_back(sBattlenetMgr->CreateModule(_os, "RiskFingerprint"));
    ReplaceResponse(response, request);

    _modulesWaitingForData.push(MODULE_RISK_FINGERPRINT);
    return true;
}

bool Battlenet::Session::HandleRiskFingerprintModule(BitStream* dataStream, ServerPacket** response)
{
    AuthComplete* complete = new AuthComplete();
    if (dataStream->Read<uint8>(8) == 1)
    {
        std::ostringstream str;
        str << _accountId << "#" << uint32(_gameAccountIndex);

        complete->AccountId = _accountId;
        complete->GameAccountName = str.str();
        complete->GameAccountFlags = GAMEACCOUNT_FLAG_PROPASS_LOCK;

        SQLTransaction trans = LoginDatabase.BeginTransaction();

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_LAST_LOGIN_INFO);
        stmt->setString(0, GetRemoteAddress());
        stmt->setUInt8(1, GetLocaleByName(_locale));
        stmt->setString(2, _os);
        stmt->setUInt32(3, _accountId);
        trans->Append(stmt);

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_SESSION_KEY);
        stmt->setString(0, K.AsHexStr());
        stmt->setBool(1, true);
        stmt->setUInt32(2, _accountId);
        trans->Append(stmt);

        LoginDatabase.CommitTransaction(trans);

        _authed = true;
    }
    else
        complete->SetAuthResult(AUTH_BAD_VERSION_HASH);

    ReplaceResponse(response, complete);
    return true;
}

bool Battlenet::Session::HandleResumeModule(BitStream* dataStream, ServerPacket** response)
{
    if (dataStream->Read<uint8>(8) != 1)
    {
        AuthResume* complete = new AuthResume();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, complete);
        return false;
    }

    static uint8 const ResumeClient = 0;
    static uint8 const ResumeServer = 1;

    std::unique_ptr<uint8[]> clientChallenge = dataStream->ReadBytes(16);
    std::unique_ptr<uint8[]> clientProof = dataStream->ReadBytes(32);
    std::unique_ptr<uint8[]> serverChallenge = _reconnectProof.AsByteArray();
    std::unique_ptr<uint8[]> sessionKey = K.AsByteArray();

    HmacSha256 clientPart(64, sessionKey.get());
    clientPart.UpdateData(&ResumeClient, 1);
    clientPart.UpdateData(clientChallenge.get(), 16);
    clientPart.UpdateData(serverChallenge.get(), 16);
    clientPart.Finalize();

    HmacSha256 serverPart(64, sessionKey.get());
    serverPart.UpdateData(&ResumeServer, 1);
    serverPart.UpdateData(serverChallenge.get(), 16);
    serverPart.UpdateData(clientChallenge.get(), 16);
    serverPart.Finalize();

    uint8 newSessionKey[64];
    memcpy(&newSessionKey[0], clientPart.GetDigest(), clientPart.GetLength());
    memcpy(&newSessionKey[32], serverPart.GetDigest(), serverPart.GetLength());

    K.SetBinary(newSessionKey, 64);

    HmacSha256 proof(64, newSessionKey);
    proof.UpdateData(&ResumeClient, 1);
    proof.UpdateData(clientChallenge.get(), 16);
    proof.UpdateData(serverChallenge.get(), 16);
    proof.Finalize();

    if (memcmp(proof.GetDigest(), clientProof.get(), serverPart.GetLength()))
    {
        TC_LOG_DEBUG("server.battlenet", "[Battlenet::Resume] Invalid proof!");
        AuthResume* result = new AuthResume();
        result->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        ReplaceResponse(response, result);
        return false;
    }

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_SESSION_KEY);
    stmt->setString(0, K.AsHexStr());
    stmt->setBool(1, true);
    stmt->setUInt32(2, _accountId);
    LoginDatabase.Execute(stmt);

    HmacSha256 serverProof(64, newSessionKey);
    serverProof.UpdateData(&ResumeServer, 1);
    serverProof.UpdateData(serverChallenge.get(), 16);
    serverProof.UpdateData(clientChallenge.get(), 16);
    serverProof.Finalize();

    ModuleInfo* resume = sBattlenetMgr->CreateModule(_os, "Resume");

    BitStream resumeData;
    uint8 state = 2;
    resumeData.WriteBytes(&state, 1);
    resumeData.WriteBytes(serverProof.GetDigest(), serverProof.GetLength());

    resume->DataSize = resumeData.GetSize();
    resume->Data = new uint8[resume->DataSize];
    memcpy(resume->Data, resumeData.GetBuffer(), resume->DataSize);

    AuthResume* result = new AuthResume();
    result->Modules.push_back(resume);
    ReplaceResponse(response, result);
    _authed = true;
    return true;
}

bool Battlenet::Session::UnhandledModule(BitStream* /*dataStream*/, ServerPacket** response)
{
    AuthComplete* complete = new AuthComplete();
    complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
    ReplaceResponse(response, complete);
    return false;
}
