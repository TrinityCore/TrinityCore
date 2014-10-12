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
#include "BitStream.h"
#include "PacketManager.h"
#include "SessionManager.h"
#include "Database/DatabaseEnv.h"
#include "HmacHash.h"
#include "Log.h"
#include "RealmList.h"
#include "SHA256.h"
#include <map>

Battlenet::Session::ModuleHandler const Battlenet::Session::ModuleHandlers[MODULE_COUNT] =
{
    &Battlenet::Session::HandlePasswordModule,
    &Battlenet::Session::UnhandledModule,
    &Battlenet::Session::UnhandledModule,
    &Battlenet::Session::HandleSelectGameAccountModule,
    &Battlenet::Session::HandleRiskFingerprintModule,
    &Battlenet::Session::HandleResumeModule,
};

Battlenet::Session::Session(tcp::socket&& socket) : Socket(std::move(socket)), _accountId(0), _accountName(), _locale(),
    _os(), _build(0), _gameAccountId(0), _gameAccountName(), _accountSecurityLevel(SEC_PLAYER), I(), s(), v(), b(), B(), K(),
    _reconnectProof(), _crypt(), _authed(false), _subscribedToRealmListUpdates(false)
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
    sSessionMgr.RemoveSession(this);
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

void Battlenet::Session::LogUnhandledPacket(PacketHeader const& header)
{
    TC_LOG_DEBUG("session.packets", "%s Received unhandled packet %s", GetClientInfo().c_str(), sPacketManager.GetClientPacketName(header));
}

void Battlenet::Session::HandleLogonRequest(Authentication::LogonRequest const& logonRequest)
{
    // Verify that this IP is not in the ip_banned table
    LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));

    std::string ip_address = GetRemoteIpAddress().to_string();
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_BANNED);
    stmt->setString(0, ip_address);
    if (PreparedQueryResult result = LoginDatabase.Query(stmt))
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(LOGIN_BANNED);
        AsyncWrite(logonResponse);
        TC_LOG_DEBUG("session", "[Battlenet::LogonRequest] Banned ip '%s:%d' tries to login!", ip_address.c_str(), GetRemotePort());
        return;
    }

    if (logonRequest.Program != "WoW")
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_INVALID_PROGRAM);
        AsyncWrite(logonResponse);
        return;
    }

    if (!sComponentMgr->HasPlatform(logonRequest.Platform))
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_INVALID_OS);
        AsyncWrite(logonResponse);
        return;
    }

    if (!sComponentMgr->HasPlatform(logonRequest.Locale))
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_UNSUPPORTED_LANGUAGE);
        AsyncWrite(logonResponse);
        return;
    }

    for (Component const& component : logonRequest.Components)
    {
        if (!sComponentMgr->HasComponent(&component))
        {
            Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
            if (!sComponentMgr->HasProgram(component.Program))
                logonResponse->SetAuthResult(AUTH_INVALID_PROGRAM);
            else if (!sComponentMgr->HasPlatform(component.Platform))
                logonResponse->SetAuthResult(AUTH_INVALID_OS);
            else
            {
                if (component.Program != "WoW" || AuthHelper::IsBuildSupportingBattlenet(component.Build))
                    logonResponse->SetAuthResult(AUTH_REGION_BAD_VERSION);
                else
                    logonResponse->SetAuthResult(AUTH_USE_GRUNT_LOGON);
            }

            AsyncWrite(logonResponse);
            return;
        }

        if (component.Platform == "base")
            _build = component.Build;
    }

    _accountName = logonRequest.Login;
    _locale = logonRequest.Locale;
    _os = logonRequest.Platform;

    Utf8ToUpperOnlyLatin(_accountName);
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_INFO);
    stmt->setString(0, _accountName);

    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        AsyncWrite(logonResponse);
        return;
    }

    Field* fields = result->Fetch();

    _accountId = fields[1].GetUInt32();

    // If the IP is 'locked', check that the player comes indeed from the correct IP address
    if (fields[2].GetUInt8() == 1)                  // if ip is locked
    {
        TC_LOG_DEBUG("session", "[Battlenet::LogonRequest] Account '%s' is locked to IP - '%s' is logging in from '%s'", _accountName.c_str(), fields[4].GetCString(), ip_address.c_str());

        if (strcmp(fields[4].GetCString(), ip_address.c_str()) != 0)
        {
            Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
            logonResponse->SetAuthResult(AUTH_ACCOUNT_LOCKED);
            AsyncWrite(logonResponse);
            return;
        }
    }
    else
    {
        TC_LOG_DEBUG("session", "[Battlenet::LogonRequest] Account '%s' is not locked to ip", _accountName.c_str());
        std::string accountCountry = fields[3].GetString();
        if (accountCountry.empty() || accountCountry == "00")
            TC_LOG_DEBUG("session", "[Battlenet::LogonRequest] Account '%s' is not locked to country", _accountName.c_str());
        else if (!accountCountry.empty())
        {
            uint32 ip = inet_addr(ip_address.c_str());
            EndianConvertReverse(ip);

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGON_COUNTRY);
            stmt->setUInt32(0, ip);
            if (PreparedQueryResult sessionCountryQuery = LoginDatabase.Query(stmt))
            {
                std::string loginCountry = (*sessionCountryQuery)[0].GetString();
                TC_LOG_DEBUG("session", "[Battlenet::LogonRequest] Account '%s' is locked to country: '%s' Player country is '%s'", _accountName.c_str(), accountCountry.c_str(), loginCountry.c_str());
                if (loginCountry != accountCountry)
                {
                    Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
                    logonResponse->SetAuthResult(AUTH_ACCOUNT_LOCKED);
                    AsyncWrite(logonResponse);
                    return;
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
            Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
            logonResponse->SetAuthResult(LOGIN_BANNED);
            AsyncWrite(logonResponse);
            TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::LogonRequest] Banned account %s tried to login!", ip_address.c_str(), GetRemotePort(), _accountName.c_str());
            return;
        }
        else
        {
            Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
            logonResponse->SetAuthResult(LOGIN_SUSPENDED);
            AsyncWrite(logonResponse);
            TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::LogonRequest] Temporarily banned account %s tried to login!", ip_address.c_str(), GetRemotePort(), _accountName.c_str());
            return;
        }
    }

    SHA256Hash sha;
    sha.UpdateData(_accountName);
    sha.Finalize();

    I.SetBinary(sha.GetDigest(), sha.GetLength());

    ModuleInfo* password = sModuleMgr->CreateModule(_os, "Password");
    ModuleInfo* thumbprint = sModuleMgr->CreateModule(_os, "Thumbprint");

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

    Authentication::ProofRequest* proofRequest = new Authentication::ProofRequest();
    proofRequest->Modules.push_back(password);
    // if has authenticator, send Token module
    proofRequest->Modules.push_back(thumbprint);
    AsyncWrite(proofRequest);
}

void Battlenet::Session::HandleResumeRequest(Authentication::ResumeRequest const& resumeRequest)
{
    _accountName = resumeRequest.Login;
    _locale = resumeRequest.Locale;
    _os = resumeRequest.Platform;
    auto baseComponent = std::find_if(resumeRequest.Components.begin(), resumeRequest.Components.end(), [](Component const& c) { return c.Program == "base"; });
    if (baseComponent != resumeRequest.Components.end())
        _build = baseComponent->Build;

    Utf8ToUpperOnlyLatin(_accountName);
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_RECONNECT_INFO);
    stmt->setString(0, _accountName);
    stmt->setString(1, resumeRequest.GameAccountName);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        Authentication::ResumeResponse* resumeResponse = new Authentication::ResumeResponse();
        resumeResponse->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        AsyncWrite(resumeResponse);
        return;
    }

    Field* fields = result->Fetch();

    _accountId = fields[0].GetUInt32();
    K.SetHexStr(fields[1].GetString().c_str());
    _gameAccountId = fields[2].GetUInt32();
    _gameAccountName = resumeRequest.GameAccountName;

    ModuleInfo* thumbprint = sModuleMgr->CreateModule(_os, "Thumbprint");
    ModuleInfo* resume = sModuleMgr->CreateModule(_os, "Resume");
    BitStream resumeData;
    uint8 state = 0;
    _reconnectProof.SetRand(16 * 8);

    resumeData.WriteBytes(&state, 1);
    resumeData.WriteBytes(_reconnectProof.AsByteArray().get(), 16);

    resume->DataSize = resumeData.GetSize();
    resume->Data = new uint8[resume->DataSize];
    memcpy(resume->Data, resumeData.GetBuffer(), resume->DataSize);

    _modulesWaitingForData.push(MODULE_RESUME);

    Authentication::ProofRequest* proofRequest = new Authentication::ProofRequest();
    proofRequest->Modules.push_back(thumbprint);
    proofRequest->Modules.push_back(resume);
    AsyncWrite(proofRequest);
}

void Battlenet::Session::HandleProofResponse(Authentication::ProofResponse const& proofResponse)
{
    if (_modulesWaitingForData.size() < proofResponse.Modules.size())
    {
        Authentication::LogonResponse* complete = new Authentication::LogonResponse();
        complete->SetAuthResult(AUTH_CORRUPTED_MODULE);
        AsyncWrite(complete);
        return;
    }

    ServerPacket* response = nullptr;
    for (size_t i = 0; i < proofResponse.Modules.size(); ++i)
    {
        if (!(this->*(ModuleHandlers[_modulesWaitingForData.front()]))(proofResponse.Modules[i], &response))
            break;

        _modulesWaitingForData.pop();
    }

    if (!response)
    {
        response = new Authentication::LogonResponse();
        static_cast<Authentication::LogonResponse*>(response)->SetAuthResult(AUTH_INTERNAL_ERROR);
    }

    AsyncWrite(response);
    return;
}

void Battlenet::Session::HandlePing(Connection::Ping const& /*ping*/)
{
    AsyncWrite(new Connection::Pong());
}

void Battlenet::Session::HandleEnableEncryption(Connection::EnableEncryption const& /*enableEncryption*/)
{
    _crypt.Init(&K);
}

void Battlenet::Session::HandleLogoutRequest(Connection::LogoutRequest const& /*logoutRequest*/)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_SESSION_KEY);
    stmt->setString(0, "");
    stmt->setBool(1, false);
    stmt->setUInt32(2, _accountId);
    LoginDatabase.Execute(stmt);
}

void Battlenet::Session::HandleConnectionClosing(Connection::ConnectionClosing const& /*connectionClosing*/)
{
}

void Battlenet::Session::HandleListSubscribeRequest(WoWRealm::ListSubscribeRequest const& /*listSubscribeRequest*/)
{
    WoWRealm::ListSubscribeResponse* listSubscribeResponse = new WoWRealm::ListSubscribeResponse();

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS);
    stmt->setUInt32(0, _gameAccountId);

    if (PreparedQueryResult countResult = LoginDatabase.Query(stmt))
    {
        do
        {
            Field* fields = countResult->Fetch();
            uint32 build = fields[4].GetUInt32();
            listSubscribeResponse->CharacterCounts.push_back({ RealmId(fields[2].GetUInt8(), fields[3].GetUInt8(), fields[1].GetUInt32(), (_build != build ? build : 0)), fields[0].GetUInt8() });
        } while (countResult->NextRow());
    }

    for (RealmList::RealmMap::value_type const& i : sRealmList->GetRealms())
        listSubscribeResponse->RealmData.push_back(BuildListUpdate(&i.second));

    listSubscribeResponse->RealmData.push_back(new WoWRealm::ListComplete());

    AsyncWrite(listSubscribeResponse);
    _subscribedToRealmListUpdates = true;
}

void Battlenet::Session::HandleListUnsubscribe(WoWRealm::ListUnsubscribe const& /*listUnsubscribe*/)
{
    _subscribedToRealmListUpdates = false;
}

void Battlenet::Session::HandleJoinRequestV2(WoWRealm::JoinRequestV2 const& joinRequest)
{
    WoWRealm::JoinResponseV2* joinResponse = new WoWRealm::JoinResponseV2();
    Realm const* realm = sRealmList->GetRealm(joinRequest.Realm);
    if (!realm || realm->Flags & (REALM_FLAG_INVALID | REALM_FLAG_OFFLINE))
    {
        joinResponse->Response = WoWRealm::JoinResponseV2::FAILURE;
        AsyncWrite(joinResponse);
        return;
    }

    joinResponse->ServerSeed = uint32(rand32());

    uint8 sessionKey[40];
    HmacSha1 hmac(K.GetNumBytes(), K.AsByteArray().get());
    hmac.UpdateData((uint8*)"WoW\0", 4);
    hmac.UpdateData((uint8*)&joinRequest.ClientSeed, 4);
    hmac.UpdateData((uint8*)&joinResponse->ServerSeed, 4);
    hmac.Finalize();

    memcpy(sessionKey, hmac.GetDigest(), hmac.GetLength());

    HmacSha1 hmac2(K.GetNumBytes(), K.AsByteArray().get());
    hmac2.UpdateData((uint8*)"WoW\0", 4);
    hmac2.UpdateData((uint8*)&joinResponse->ServerSeed, 4);
    hmac2.UpdateData((uint8*)&joinRequest.ClientSeed, 4);
    hmac2.Finalize();

    memcpy(sessionKey + hmac.GetLength(), hmac2.GetDigest(), hmac2.GetLength());

    LoginDatabase.DirectPExecute("UPDATE account SET sessionkey = '%s', last_ip = '%s', last_login = NOW(), locale = %u, failed_logins = 0, os = '%s' WHERE id = %u",
        ByteArrayToHexStr(sessionKey, 40, true).c_str(), GetRemoteIpAddress().to_string().c_str(), GetLocaleByName(_locale), _os.c_str(), _gameAccountId);

    joinResponse->IPv4.emplace_back(realm->ExternalAddress, realm->Port);
    if (realm->ExternalAddress != realm->LocalAddress)
        joinResponse->IPv4.emplace_back(realm->LocalAddress, realm->Port);

    AsyncWrite(joinResponse);
}

void Battlenet::Session::HandleSocialNetworkCheckConnected(Friends::SocialNetworkCheckConnected const& socialNetworkCheckConnected)
{
    Friends::SocialNetworkCheckConnectedResult* socialNetworkCheckConnectedResult = new Friends::SocialNetworkCheckConnectedResult();
    socialNetworkCheckConnectedResult->SocialNetworkId = socialNetworkCheckConnected.SocialNetworkId;
    AsyncWrite(socialNetworkCheckConnectedResult);
}

inline std::string PacketToStringHelper(Battlenet::ClientPacket const* packet)
{
    if (sLog->ShouldLog("session.packets", LOG_LEVEL_TRACE))
        return packet->ToString();

    return sPacketManager.GetClientPacketName(packet->GetHeader());
}

inline std::string PacketToStringHelper(Battlenet::ServerPacket const* packet)
{
    if (sLog->ShouldLog("session.packets", LOG_LEVEL_TRACE))
        return packet->ToString();

    return sPacketManager.GetServerPacketName(packet->GetHeader());
}

void Battlenet::Session::ReadHandler()
{
    BitStream stream(std::move(GetReadBuffer()));
    _crypt.DecryptRecv(stream.GetBuffer(), stream.GetSize());

    while (!stream.IsRead())
    {
        try
        {
            PacketHeader header;
            header.Opcode = stream.Read<uint32>(6);
            if (stream.Read<bool>(1))
                header.Channel = stream.Read<int32>(4);

            if (header.Channel != AUTHENTICATION && !_authed)
            {
                TC_LOG_DEBUG("session.packets", "%s Received not allowed %s. Client has not authed yet.", GetClientInfo().c_str(), header.ToString().c_str());
                CloseSocket();
                return;
            }

            if (ClientPacket* packet = sPacketManager.CreateClientPacket(header, stream))
            {
                if (sPacketManager.IsHandled(header))
                    TC_LOG_DEBUG("session.packets", "%s Received %s", GetClientInfo().c_str(), PacketToStringHelper(packet).c_str());

                packet->CallHandler(this);
                delete packet;
            }
            else if (sPacketManager.GetClientPacketName(header))
            {
                LogUnhandledPacket(header);
                break;
            }
            else
            {
                TC_LOG_DEBUG("session.packets", "%s Received unknown %s", GetClientInfo().c_str(), header.ToString().c_str());
                break;
            }

            stream.AlignToNextByte();
        }
        catch (BitStreamPositionException const& e)
        {
            TC_LOG_ERROR("session.packets", "%s Exception thrown during packet processing %s", GetClientInfo().c_str(), e.what());
            CloseSocket();
            return;
        }
    }

    GetReadBuffer().Resize(size_t(BufferSizes::Read));
    AsyncRead();
}

void Battlenet::Session::Start()
{
    TC_LOG_TRACE("session", "Accepted connection from %s", GetRemoteIpAddress().to_string().c_str());
    AsyncRead();
}

void Battlenet::Session::AsyncWrite(ServerPacket* packet)
{
    if (!IsOpen())
    {
        delete packet;
        return;
    }

    TC_LOG_DEBUG("session.packets", "%s Sending %s", GetClientInfo().c_str(), PacketToStringHelper(packet).c_str());

    packet->Write();

    MessageBuffer buffer;
    buffer.Write(packet->GetData(), packet->GetSize());
    delete packet;

    std::unique_lock<std::mutex> guard(_writeLock);

    _crypt.EncryptSend(buffer.GetReadPointer(), buffer.GetActiveSize());

    QueuePacket(std::move(buffer), guard);
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
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, logonResponse);
        return false;
    }

    if (dataStream->Read<uint8>(8) != 2)                // State
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, logonResponse);
        return false;
    }


    BigNumber A, clientM1, clientChallenge;
    A.SetBinary(dataStream->ReadBytes(128).get(), 128);
    clientM1.SetBinary(dataStream->ReadBytes(32).get(), 32);
    clientChallenge.SetBinary(dataStream->ReadBytes(128).get(), 128);

    if (A.isZero())
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, logonResponse);
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
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_FAILED_LOGINS);
        stmt->setString(0, _accountName);
        LoginDatabase.Execute(stmt);

        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        ReplaceResponse(response, logonResponse);
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
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, logonResponse);
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
    ModuleInfo* password = sModuleMgr->CreateModule(_os, "Password");
    uint8 state = 3;

    stream.WriteBytes(&state, 1);
    stream.WriteBytes(M.AsByteArray(32).get(), 32);
    stream.WriteBytes(serverProof.AsByteArray(128).get(), 128);

    password->DataSize = stream.GetSize();
    password->Data = new uint8[password->DataSize];
    memcpy(password->Data, stream.GetBuffer(), password->DataSize);

    Authentication::ProofRequest* proofRequest = new Authentication::ProofRequest();
    proofRequest->Modules.push_back(password);
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
            std::string originalName = fields[1].GetString();
            if (originalName.find('#') != std::string::npos)
                name << "WoW" << uint32(fields[0].GetUInt8());
            else
                name << originalName;

            accounts.Write(2, 8);
            accounts.WriteString(name.str(), 8);
        } while (result->NextRow());

        ModuleInfo* selectGameAccount = sModuleMgr->CreateModule(_os, "SelectGameAccount");
        selectGameAccount->DataSize = accounts.GetSize();
        selectGameAccount->Data = new uint8[selectGameAccount->DataSize];
        memcpy(selectGameAccount->Data, accounts.GetBuffer(), selectGameAccount->DataSize);
        proofRequest->Modules.push_back(selectGameAccount);
        _modulesWaitingForData.push(MODULE_SELECT_GAME_ACCOUNT);
    }
    else
    {
        if (fields[4].GetBool())
        {
            delete proofRequest;

            Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
            if (fields[2].GetUInt32() == fields[3].GetUInt32())
            {
                logonResponse->SetAuthResult(LOGIN_BANNED);
                TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::Password] Banned account %s tried to login!", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountName.c_str());
            }
            else
            {
                logonResponse->SetAuthResult(LOGIN_SUSPENDED);
                TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::Password] Temporarily banned account %s tried to login!", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountName.c_str());
            }

            ReplaceResponse(response, logonResponse);
            return false;
        }

        _gameAccountId = fields[0].GetUInt32();
        _gameAccountName = fields[1].GetString();

        proofRequest->Modules.push_back(sModuleMgr->CreateModule(_os, "RiskFingerprint"));
        _modulesWaitingForData.push(MODULE_RISK_FINGERPRINT);
    }

    ReplaceResponse(response, proofRequest);
    return true;
}

bool Battlenet::Session::HandleSelectGameAccountModule(BitStream* dataStream, ServerPacket** response)
{
    if (dataStream->Read<uint8>(8) != 1)
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, logonResponse);
        return false;
    }

    dataStream->Read<uint8>(8);
    std::string account = dataStream->ReadString(8);
    if (account.empty())
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        logonResponse->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, logonResponse);
        return false;
    }

    PreparedStatement* stmt;
    if (account.substr(0, 3) != "WoW")
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT);
        stmt->setString(0, account);
    }
    else
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_UNNAMED);
        stmt->setUInt8(0, atol(account.substr(3).c_str()));
    }

    stmt->setUInt32(1, _accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        Authentication::LogonResponse* complete = new Authentication::LogonResponse();
        complete->SetAuthResult(LOGIN_NO_GAME_ACCOUNT);
        ReplaceResponse(response, complete);
        return false;
    }

    Field* fields = result->Fetch();
    if (fields[4].GetBool())
    {
        Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
        if (fields[2].GetUInt32() == fields[3].GetUInt32())
        {
            logonResponse->SetAuthResult(LOGIN_BANNED);
            TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::SelectGameAccount] Banned account %s tried to login!", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountName.c_str());
        }
        else
        {
            logonResponse->SetAuthResult(LOGIN_SUSPENDED);
            TC_LOG_DEBUG("session", "'%s:%d' [Battlenet::SelectGameAccount] Temporarily banned account %s tried to login!", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountName.c_str());
        }

        ReplaceResponse(response, logonResponse);
        return false;
    }

    _gameAccountId = fields[0].GetUInt32();
    _gameAccountName = fields[1].GetString();

    Authentication::ProofRequest* proofRequest = new Authentication::ProofRequest();
    proofRequest->Modules.push_back(sModuleMgr->CreateModule(_os, "RiskFingerprint"));
    ReplaceResponse(response, proofRequest);

    _modulesWaitingForData.push(MODULE_RISK_FINGERPRINT);
    return true;
}

bool Battlenet::Session::HandleRiskFingerprintModule(BitStream* dataStream, ServerPacket** response)
{
    Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
    if (dataStream->Read<uint8>(8) == 1)
    {
        logonResponse->AccountId = _accountId;
        logonResponse->GameAccountName = _gameAccountName;
        logonResponse->GameAccountFlags = GAMEACCOUNT_FLAG_PROPASS_LOCK;
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_FAILED_LOGINS);
        stmt->setUInt32(0, _accountId);
        if (PreparedQueryResult failedLoginsResult = LoginDatabase.Query(stmt))
            logonResponse->FailedLogins = (*failedLoginsResult)[0].GetUInt32();

        SQLTransaction trans = LoginDatabase.BeginTransaction();

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_LAST_LOGIN_INFO);
        stmt->setString(0, GetRemoteIpAddress().to_string());
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
        sSessionMgr.AddSession(this);
    }
    else
        logonResponse->SetAuthResult(AUTH_BAD_VERSION_HASH);

    ReplaceResponse(response, logonResponse);
    return true;
}

bool Battlenet::Session::HandleResumeModule(BitStream* dataStream, ServerPacket** response)
{
    if (dataStream->Read<uint8>(8) != 1)
    {
        Authentication::ResumeResponse* resumeResponse = new Authentication::ResumeResponse();
        resumeResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
        ReplaceResponse(response, resumeResponse);
        return false;
    }

    static uint8 const ResumeClient = 0;
    static uint8 const ResumeServer = 1;

    std::unique_ptr<uint8[]> clientChallenge = dataStream->ReadBytes(16);
    std::unique_ptr<uint8[]> clientProof = dataStream->ReadBytes(32);
    std::unique_ptr<uint8[]> serverChallenge = _reconnectProof.AsByteArray(16);
    std::unique_ptr<uint8[]> sessionKey = K.AsByteArray(64);

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
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_FAILED_LOGINS);
        stmt->setString(0, _accountName);
        LoginDatabase.Execute(stmt);

        TC_LOG_DEBUG("session", "[Battlenet::Resume] Invalid proof!");
        Authentication::ResumeResponse* resumeResponse = new Authentication::ResumeResponse();
        resumeResponse->SetAuthResult(AUTH_UNKNOWN_ACCOUNT);
        ReplaceResponse(response, resumeResponse);
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

    ModuleInfo* resume = sModuleMgr->CreateModule(_os, "Resume");

    BitStream resumeData;
    uint8 state = 2;
    resumeData.WriteBytes(&state, 1);
    resumeData.WriteBytes(serverProof.GetDigest(), serverProof.GetLength());

    resume->DataSize = resumeData.GetSize();
    resume->Data = new uint8[resume->DataSize];
    memcpy(resume->Data, resumeData.GetBuffer(), resume->DataSize);

    Authentication::ResumeResponse* resumeResponse = new Authentication::ResumeResponse();
    resumeResponse->Modules.push_back(resume);
    ReplaceResponse(response, resumeResponse);
    _authed = true;
    sSessionMgr.AddSession(this);
    return true;
}

bool Battlenet::Session::UnhandledModule(BitStream* /*dataStream*/, ServerPacket** response)
{
    TC_LOG_ERROR("session.packets", "Unhandled module.");
    Authentication::LogonResponse* logonResponse = new Authentication::LogonResponse();
    logonResponse->SetAuthResult(AUTH_CORRUPTED_MODULE);
    ReplaceResponse(response, logonResponse);
    return false;
}

void Battlenet::Session::UpdateRealms(std::vector<Realm const*>& realms, std::vector<RealmId>& deletedRealms)
{
    for (Realm const* realm : realms)
        AsyncWrite(BuildListUpdate(realm));

    for (RealmId& deleted : deletedRealms)
    {
        WoWRealm::ListUpdate* listUpdate = new WoWRealm::ListUpdate();
        listUpdate->UpdateState = WoWRealm::ListUpdate::DELETED;
        listUpdate->Id = deleted;
        AsyncWrite(listUpdate);
    }
}

Battlenet::WoWRealm::ListUpdate* Battlenet::Session::BuildListUpdate(Realm const* realm) const
{
    uint32 flag = realm->Flags & ~REALM_FLAG_SPECIFYBUILD;
    RealmBuildInfo const* buildInfo = AuthHelper::GetBuildInfo(realm->Id.Build);
    if (realm->Id.Build != _build)
    {
        flag |= REALM_FLAG_INVALID;
        if (buildInfo)
            flag |= REALM_FLAG_SPECIFYBUILD;   // tell the client what build the realm is for
    }

    WoWRealm::ListUpdate* listUpdate = new WoWRealm::ListUpdate();
    listUpdate->Timezone = realm->Timezone;
    listUpdate->Population = realm->PopulationLevel;
    listUpdate->Lock = (realm->AllowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;
    listUpdate->Type = realm->Type;
    listUpdate->Name = realm->Name;

    if (flag & REALM_FLAG_SPECIFYBUILD)
    {
        std::ostringstream version;
        version << buildInfo->MajorVersion << '.' << buildInfo->MinorVersion << '.' << buildInfo->BugfixVersion << '.' << buildInfo->Build;

        listUpdate->Version = version.str();
        listUpdate->Address = realm->GetAddressForClient(GetRemoteIpAddress());
    }

    listUpdate->Flags = flag;
    listUpdate->Id = realm->Id;
    return listUpdate;
}

std::string Battlenet::Session::GetClientInfo() const
{
    std::ostringstream stream;
    stream << '[' << GetRemoteIpAddress() << ':' << GetRemotePort();
    if (!_accountName.empty())
        stream << ", Account: " << _accountName;

    if (!_gameAccountName.empty())
        stream << ", Game account: " << _gameAccountName;

    stream << ']';

    return stream.str();
}
