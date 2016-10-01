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

#include "AuthSession.h"
#include "Log.h"
#include "AuthCodes.h"
#include "Database/DatabaseEnv.h"
#include "SHA1.h"
#include "TOTP.h"
#include "openssl/crypto.h"
#include "Configuration/Config.h"
#include "RealmList.h"
#include <boost/lexical_cast.hpp>

using boost::asio::ip::tcp;

enum eAuthCmd
{
    AUTH_LOGON_CHALLENGE = 0x00,
    AUTH_LOGON_PROOF = 0x01,
    AUTH_RECONNECT_CHALLENGE = 0x02,
    AUTH_RECONNECT_PROOF = 0x03,
    REALM_LIST = 0x10,
    XFER_INITIATE = 0x30,
    XFER_DATA = 0x31,
    XFER_ACCEPT = 0x32,
    XFER_RESUME = 0x33,
    XFER_CANCEL = 0x34
};

#pragma pack(push, 1)

typedef struct AUTH_LOGON_CHALLENGE_C
{
    uint8   cmd;
    uint8   error;
    uint16  size;
    uint8   gamename[4];
    uint8   version1;
    uint8   version2;
    uint8   version3;
    uint16  build;
    uint8   platform[4];
    uint8   os[4];
    uint8   country[4];
    uint32  timezone_bias;
    uint32  ip;
    uint8   I_len;
    uint8   I[1];
} sAuthLogonChallenge_C;

typedef struct AUTH_LOGON_PROOF_C
{
    uint8   cmd;
    uint8   A[32];
    uint8   M1[20];
    uint8   crc_hash[20];
    uint8   number_of_keys;
    uint8   securityFlags;
} sAuthLogonProof_C;

typedef struct AUTH_LOGON_PROOF_S
{
    uint8   cmd;
    uint8   error;
    uint8   M2[20];
    uint32  AccountFlags;
    uint32  SurveyId;
    uint16  unk3;
} sAuthLogonProof_S;

typedef struct AUTH_LOGON_PROOF_S_OLD
{
    uint8   cmd;
    uint8   error;
    uint8   M2[20];
    uint32  unk2;
} sAuthLogonProof_S_Old;

typedef struct AUTH_RECONNECT_PROOF_C
{
    uint8   cmd;
    uint8   R1[16];
    uint8   R2[20];
    uint8   R3[20];
    uint8   number_of_keys;
} sAuthReconnectProof_C;

#pragma pack(pop)

enum class BufferSizes : uint32
{
    SRP_6_V = 0x20,
    SRP_6_S = 0x20,
};

#define MAX_ACCEPTED_CHALLENGE_SIZE (sizeof(AUTH_LOGON_CHALLENGE_C) + 16)

#define AUTH_LOGON_CHALLENGE_INITIAL_SIZE 4
#define REALM_LIST_PACKET_SIZE 5

std::unordered_map<uint8, AuthHandler> AuthSession::InitHandlers()
{
    std::unordered_map<uint8, AuthHandler> handlers;

    handlers[AUTH_LOGON_CHALLENGE]     = { STATUS_CONNECTED, AUTH_LOGON_CHALLENGE_INITIAL_SIZE, &AuthSession::HandleLogonChallenge };
    handlers[AUTH_LOGON_PROOF]         = { STATUS_CONNECTED, sizeof(AUTH_LOGON_PROOF_C),        &AuthSession::HandleLogonProof };
    handlers[AUTH_RECONNECT_CHALLENGE] = { STATUS_CONNECTED, AUTH_LOGON_CHALLENGE_INITIAL_SIZE, &AuthSession::HandleReconnectChallenge };
    handlers[AUTH_RECONNECT_PROOF]     = { STATUS_CONNECTED, sizeof(AUTH_RECONNECT_PROOF_C),    &AuthSession::HandleReconnectProof };
    handlers[REALM_LIST]               = { STATUS_AUTHED,    REALM_LIST_PACKET_SIZE,            &AuthSession::HandleRealmList };

    return handlers;
}

std::unordered_map<uint8, AuthHandler> const Handlers = AuthSession::InitHandlers();

void AccountInfo::LoadResult(Field* fields)
{
    //          0           1         2               3          4                5                                                             6
    //SELECT a.id, a.username, a.locked, a.lock_country, a.last_ip, a.failed_logins, ab.unbandate > UNIX_TIMESTAMP() OR ab.unbandate = ab.bandate,
    //                               7           8            9               10   11   12
    //       ab.unbandate = ab.bandate, aa.gmlevel, a.token_key, a.sha_pass_hash, a.v, a.s
    //FROM account a LEFT JOIN account_access aa ON a.id = aa.id LEFT JOIN account_banned ab ON ab.id = a.id AND ab.active = 1 WHERE a.username = ?

    Id = fields[0].GetUInt32();
    Login = fields[1].GetString();
    IsLockedToIP = fields[2].GetBool();
    LockCountry = fields[3].GetString();
    LastIP = fields[4].GetString();
    FailedLogins = fields[5].GetUInt32();
    IsBanned = fields[6].GetUInt64() != 0;
    IsPermanenetlyBanned = fields[7].GetUInt64() != 0;
    SecurityLevel = AccountTypes(fields[8].GetUInt8());

    // Use our own uppercasing of the account name instead of using UPPER() in mysql query
    // This is how the account was created in the first place and changing it now would result in breaking
    // login for all accounts having accented characters in their name
    Utf8ToUpperOnlyLatin(Login);
}

AuthSession::AuthSession(tcp::socket&& socket) : Socket(std::move(socket)),
_sentChallenge(false), _sentProof(false),
_status(STATUS_CONNECTED), _build(0), _expversion(0)
{
    N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
    g.SetDword(7);
}

void AuthSession::Start()
{
    std::string ip_address = GetRemoteIpAddress().to_string();
    TC_LOG_TRACE("session", "Accepted connection from %s", ip_address.c_str());

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_INFO);
    stmt->setString(0, ip_address);
    stmt->setUInt32(1, inet_addr(ip_address.c_str()));

    _queryCallback = std::bind(&AuthSession::CheckIpCallback, this, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
}

bool AuthSession::Update()
{
    if (!AuthSocket::Update())
        return false;

    if (_queryFuture.valid() && _queryFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        auto callback = _queryCallback;
        _queryCallback = nullptr;
        callback(_queryFuture.get());
    }

    return true;
}

void AuthSession::CheckIpCallback(PreparedQueryResult result)
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
            ByteBuffer pkt;
            pkt << uint8(AUTH_LOGON_CHALLENGE);
            pkt << uint8(0x00);
            pkt << uint8(WOW_FAIL_BANNED);
            SendPacket(pkt);
            TC_LOG_DEBUG("session", "[AuthSession::CheckIpCallback] Banned ip '%s:%d' tries to login!", GetRemoteIpAddress().to_string().c_str(), GetRemotePort());
            return;
        }
    }

    AsyncRead();
}

void AuthSession::ReadHandler()
{
    MessageBuffer& packet = GetReadBuffer();
    while (packet.GetActiveSize())
    {
        uint8 cmd = packet.GetReadPointer()[0];
        auto itr = Handlers.find(cmd);
        if (itr == Handlers.end())
        {
            // well we dont handle this, lets just ignore it
            packet.Reset();
            break;
        }

        if (_status != itr->second.status)
        {
            CloseSocket();
            return;
        }

        uint16 size = uint16(itr->second.packetSize);
        if (packet.GetActiveSize() < size)
            break;

        if (cmd == AUTH_LOGON_CHALLENGE || cmd == AUTH_RECONNECT_CHALLENGE)
        {
            sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(packet.GetReadPointer());
            size += challenge->size;
            if (size > MAX_ACCEPTED_CHALLENGE_SIZE)
            {
                CloseSocket();
                return;
            }
        }

        if (packet.GetActiveSize() < size)
            break;

        if (!(*this.*itr->second.handler)())
        {
            CloseSocket();
            return;
        }

        packet.ReadCompleted(size);
    }

    AsyncRead();
}

void AuthSession::SendPacket(ByteBuffer& packet)
{
    if (!IsOpen())
        return;

    if (!packet.empty())
    {
        MessageBuffer buffer;
        buffer.Write(packet.contents(), packet.size());
        QueuePacket(std::move(buffer));
    }
}

bool AuthSession::HandleLogonChallenge()
{
    if (_sentChallenge)
        return false;

    _sentChallenge = true;

    sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(GetReadBuffer().GetReadPointer());
    if (challenge->size - (sizeof(sAuthLogonChallenge_C) - AUTH_LOGON_CHALLENGE_INITIAL_SIZE - 1) != challenge->I_len)
        return false;

    std::string login((const char*)challenge->I, challenge->I_len);
    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] '%s'", login.c_str());

    if (_queryCallback)
    {
        ByteBuffer pkt;
        pkt << uint8(AUTH_LOGON_CHALLENGE);
        pkt << uint8(0x00);
        pkt << uint8(WOW_FAIL_DB_BUSY);
        SendPacket(pkt);

        TC_LOG_DEBUG("server.authserver", "[AuthChallenge] %s attempted to log too quick after previous attempt!", login.c_str());
        return true;
    }

    _build = challenge->build;
    _expversion = uint8(AuthHelper::IsPostBCAcceptedClientBuild(_build) ? POST_BC_EXP_FLAG : (AuthHelper::IsPreBCAcceptedClientBuild(_build) ? PRE_BC_EXP_FLAG : NO_VALID_EXP_FLAG));
    std::array<char, 5> os;
    os.fill('\0');
    memcpy(os.data(), challenge->os, sizeof(challenge->os));
    _os = os.data();

    // Restore string order as its byte order is reversed
    std::reverse(_os.begin(), _os.end());

    _localizationName.resize(4);
    for (int i = 0; i < 4; ++i)
        _localizationName[i] = challenge->country[4 - i - 1];

    // Get the account details from the account table
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGONCHALLENGE);
    stmt->setString(0, login);

    _queryCallback = std::bind(&AuthSession::LogonChallengeCallback, this, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
    return true;
}

void AuthSession::LogonChallengeCallback(PreparedQueryResult result)
{
    ByteBuffer pkt;
    pkt << uint8(AUTH_LOGON_CHALLENGE);
    pkt << uint8(0x00);

    if (!result)
    {
        pkt << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
        SendPacket(pkt);
        return;
    }

    Field* fields = result->Fetch();

    _accountInfo.LoadResult(fields);

    std::string ipAddress = GetRemoteIpAddress().to_string();
    uint16 port = GetRemotePort();

    // If the IP is 'locked', check that the player comes indeed from the correct IP address
    if (_accountInfo.IsLockedToIP)
    {
        TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is locked to IP - '%s' is logging in from '%s'", _accountInfo.Login.c_str(), _accountInfo.LastIP.c_str(), ipAddress.c_str());
        if (_accountInfo.LastIP != ipAddress)
        {
            pkt << uint8(WOW_FAIL_LOCKED_ENFORCED);
            SendPacket(pkt);
            return;
        }
    }
    else
    {
        TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is not locked to ip", _accountInfo.Login.c_str());
        if (_accountInfo.LockCountry.empty() || _accountInfo.LockCountry == "00")
            TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is not locked to country", _accountInfo.Login.c_str());
        else if (!_accountInfo.LockCountry.empty() && !_ipCountry.empty())
        {
            TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is locked to country: '%s' Player country is '%s'", _accountInfo.Login.c_str(), _accountInfo.LockCountry.c_str(), _ipCountry.c_str());
            if (_ipCountry != _accountInfo.LockCountry)
            {
                pkt << uint8(WOW_FAIL_UNLOCKABLE_LOCK);
                SendPacket(pkt);
                return;
            }
        }
    }

    // If the account is banned, reject the logon attempt
    if (_accountInfo.IsBanned)
    {
        if (_accountInfo.IsPermanenetlyBanned)
        {
            pkt << uint8(WOW_FAIL_BANNED);
            SendPacket(pkt);
            TC_LOG_INFO("server.authserver.banned", "'%s:%d' [AuthChallenge] Banned account %s tried to login!", ipAddress.c_str(), port, _accountInfo.Login.c_str());
            return;
        }
        else
        {
            pkt << uint8(WOW_FAIL_SUSPENDED);
            SendPacket(pkt);
            TC_LOG_INFO("server.authserver.banned", "'%s:%d' [AuthChallenge] Temporarily banned account %s tried to login!", ipAddress.c_str(), port, _accountInfo.Login.c_str());
            return;
        }
    }

    // Get the password from the account table, upper it, and make the SRP6 calculation
    std::string rI = fields[10].GetString();

    // Don't calculate (v, s) if there are already some in the database
    std::string databaseV = fields[11].GetString();
    std::string databaseS = fields[12].GetString();

    TC_LOG_DEBUG("network", "database authentication values: v='%s' s='%s'", databaseV.c_str(), databaseS.c_str());

    // multiply with 2 since bytes are stored as hexstring
    if (databaseV.size() != size_t(BufferSizes::SRP_6_V) * 2 || databaseS.size() != size_t(BufferSizes::SRP_6_S) * 2)
        SetVSFields(rI);
    else
    {
        s.SetHexStr(databaseS.c_str());
        v.SetHexStr(databaseV.c_str());
    }

    b.SetRand(19 * 8);
    BigNumber gmod = g.ModExp(b, N);
    B = ((v * 3) + gmod) % N;

    ASSERT(gmod.GetNumBytes() <= 32);

    BigNumber unk3;
    unk3.SetRand(16 * 8);

    // Fill the response packet with the result
    if (AuthHelper::IsAcceptedClientBuild(_build))
        pkt << uint8(WOW_SUCCESS);
    else
        pkt << uint8(WOW_FAIL_VERSION_INVALID);

    // B may be calculated < 32B so we force minimal length to 32B
    pkt.append(B.AsByteArray(32).get(), 32);      // 32 bytes
    pkt << uint8(1);
    pkt.append(g.AsByteArray(1).get(), 1);
    pkt << uint8(32);
    pkt.append(N.AsByteArray(32).get(), 32);
    pkt.append(s.AsByteArray(int32(BufferSizes::SRP_6_S)).get(), size_t(BufferSizes::SRP_6_S));   // 32 bytes
    pkt.append(unk3.AsByteArray(16).get(), 16);
    uint8 securityFlags = 0;

    // Check if token is used
    _tokenKey = fields[9].GetString();
    if (!_tokenKey.empty())
        securityFlags = 4;

    pkt << uint8(securityFlags);            // security flags (0x0...0x04)

    if (securityFlags & 0x01)               // PIN input
    {
        pkt << uint32(0);
        pkt << uint64(0) << uint64(0);      // 16 bytes hash?
    }

    if (securityFlags & 0x02)               // Matrix input
    {
        pkt << uint8(0);
        pkt << uint8(0);
        pkt << uint8(0);
        pkt << uint8(0);
        pkt << uint64(0);
    }

    if (securityFlags & 0x04)               // Security token input
        pkt << uint8(1);

    TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] account %s is using '%s' locale (%u)",
        ipAddress.c_str(), port, _accountInfo.Login.c_str(), _localizationName.c_str(), GetLocaleByName(_localizationName));

    SendPacket(pkt);
}

// Logon Proof command handler
bool AuthSession::HandleLogonProof()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleLogonProof");
    if (_sentProof)
        return false;

    _sentProof = true;

    // Read the packet
    sAuthLogonProof_C *logonProof = reinterpret_cast<sAuthLogonProof_C*>(GetReadBuffer().GetReadPointer());

    // If the client has no valid version
    if (_expversion == NO_VALID_EXP_FLAG)
    {
        // Check if we have the appropriate patch on the disk
        TC_LOG_DEBUG("network", "Client with invalid version, patching is not implemented");
        return false;
    }

    // Continue the SRP6 calculation based on data received from the client
    BigNumber A;

    A.SetBinary(logonProof->A, 32);

    // SRP safeguard: abort if A == 0
    if (A.IsZero())
    {
        return false;
    }

    SHA1Hash sha;
    sha.UpdateBigNumbers(&A, &B, NULL);
    sha.Finalize();
    BigNumber u;
    u.SetBinary(sha.GetDigest(), 20);
    BigNumber S = (A * (v.ModExp(u, N))).ModExp(b, N);

    uint8 t[32];
    uint8 t1[16];
    uint8 vK[40];
    memcpy(t, S.AsByteArray(32).get(), 32);

    for (int i = 0; i < 16; ++i)
        t1[i] = t[i * 2];

    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();

    for (int i = 0; i < 20; ++i)
        vK[i * 2] = sha.GetDigest()[i];

    for (int i = 0; i < 16; ++i)
        t1[i] = t[i * 2 + 1];

    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();

    for (int i = 0; i < 20; ++i)
        vK[i * 2 + 1] = sha.GetDigest()[i];

    K.SetBinary(vK, 40);

    uint8 hash[20];

    sha.Initialize();
    sha.UpdateBigNumbers(&N, NULL);
    sha.Finalize();
    memcpy(hash, sha.GetDigest(), 20);
    sha.Initialize();
    sha.UpdateBigNumbers(&g, NULL);
    sha.Finalize();

    for (int i = 0; i < 20; ++i)
        hash[i] ^= sha.GetDigest()[i];

    BigNumber t3;
    t3.SetBinary(hash, 20);

    sha.Initialize();
    sha.UpdateData(_accountInfo.Login);
    sha.Finalize();
    uint8 t4[SHA_DIGEST_LENGTH];
    memcpy(t4, sha.GetDigest(), SHA_DIGEST_LENGTH);

    sha.Initialize();
    sha.UpdateBigNumbers(&t3, NULL);
    sha.UpdateData(t4, SHA_DIGEST_LENGTH);
    sha.UpdateBigNumbers(&s, &A, &B, &K, NULL);
    sha.Finalize();
    BigNumber M;
    M.SetBinary(sha.GetDigest(), sha.GetLength());

    // Check if SRP6 results match (password is correct), else send an error
    if (!memcmp(M.AsByteArray(sha.GetLength()).get(), logonProof->M1, 20))
    {
        TC_LOG_DEBUG("server.authserver", "'%s:%d' User '%s' successfully authenticated", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountInfo.Login.c_str());

        // Update the sessionkey, last_ip, last login time and reset number of failed logins in the account table for this account
        // No SQL injection (escaped user name) and IP address as received by socket

        PreparedStatement *stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LOGONPROOF);
        stmt->setString(0, K.AsHexStr());
        stmt->setString(1, GetRemoteIpAddress().to_string().c_str());
        stmt->setUInt32(2, GetLocaleByName(_localizationName));
        stmt->setString(3, _os);
        stmt->setString(4, _accountInfo.Login);
        LoginDatabase.DirectExecute(stmt);

        // Finish SRP6 and send the final result to the client
        sha.Initialize();
        sha.UpdateBigNumbers(&A, &M, &K, NULL);
        sha.Finalize();

        // Check auth token
        if ((logonProof->securityFlags & 0x04) || !_tokenKey.empty())
        {
            uint8 size = *(GetReadBuffer().GetReadPointer() + sizeof(sAuthLogonProof_C));
            std::string token(reinterpret_cast<char*>(GetReadBuffer().GetReadPointer() + sizeof(sAuthLogonProof_C) + sizeof(size)), size);
            GetReadBuffer().ReadCompleted(sizeof(size) + size);
            uint32 validToken = TOTP::GenerateToken(_tokenKey.c_str());
            _tokenKey.clear();
            uint32 incomingToken = atoi(token.c_str());
            if (validToken != incomingToken)
            {
                ByteBuffer packet;
                packet << uint8(AUTH_LOGON_PROOF);
                packet << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
                packet << uint8(3);
                packet << uint8(0);
                SendPacket(packet);
                return true;
            }
        }

        ByteBuffer packet;
        if (_expversion & POST_BC_EXP_FLAG)                 // 2.x and 3.x clients
        {
            sAuthLogonProof_S proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            proof.AccountFlags = 0x00800000;    // 0x01 = GM, 0x08 = Trial, 0x00800000 = Pro pass (arena tournament)
            proof.SurveyId = 0;
            proof.unk3 = 0;

            packet.resize(sizeof(proof));
            std::memcpy(packet.contents(), &proof, sizeof(proof));
        }
        else
        {
            sAuthLogonProof_S_Old proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            proof.unk2 = 0x00;

            packet.resize(sizeof(proof));
            std::memcpy(packet.contents(), &proof, sizeof(proof));
        }

        SendPacket(packet);
        _status = STATUS_AUTHED;
    }
    else
    {
        ByteBuffer packet;
        packet << uint8(AUTH_LOGON_PROOF);
        packet << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
        packet << uint8(3);
        packet << uint8(0);
        SendPacket(packet);

        TC_LOG_INFO("server.authserver.hack", "'%s:%d' [AuthChallenge] account %s tried to login with invalid password!",
            GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountInfo.Login.c_str());

        uint32 MaxWrongPassCount = sConfigMgr->GetIntDefault("WrongPass.MaxCount", 0);

        // We can not include the failed account login hook. However, this is a workaround to still log this.
        if (sConfigMgr->GetBoolDefault("WrongPass.Logging", false))
        {
            PreparedStatement* logstmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_FALP_IP_LOGGING);
            logstmt->setUInt32(0, _accountInfo.Id);
            logstmt->setString(1, GetRemoteIpAddress().to_string());
            logstmt->setString(2, "Logged on failed AccountLogin due wrong password");

            LoginDatabase.Execute(logstmt);
        }

        if (MaxWrongPassCount > 0)
        {
            //Increment number of failed logins by one and if it reaches the limit temporarily ban that account or IP
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_FAILEDLOGINS);
            stmt->setString(0, _accountInfo.Login);
            LoginDatabase.Execute(stmt);

            if (++_accountInfo.FailedLogins >= MaxWrongPassCount)
            {
                uint32 WrongPassBanTime = sConfigMgr->GetIntDefault("WrongPass.BanTime", 600);
                bool WrongPassBanType = sConfigMgr->GetBoolDefault("WrongPass.BanType", false);

                if (WrongPassBanType)
                {
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT_AUTO_BANNED);
                    stmt->setUInt32(0, _accountInfo.Id);
                    stmt->setUInt32(1, WrongPassBanTime);
                    LoginDatabase.Execute(stmt);

                    TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] account %s got banned for '%u' seconds because it failed to authenticate '%u' times",
                        GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _accountInfo.Login.c_str(), WrongPassBanTime, _accountInfo.FailedLogins);
                }
                else
                {
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_IP_AUTO_BANNED);
                    stmt->setString(0, GetRemoteIpAddress().to_string());
                    stmt->setUInt32(1, WrongPassBanTime);
                    LoginDatabase.Execute(stmt);

                    TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] IP got banned for '%u' seconds because account %s failed to authenticate '%u' times",
                        GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), WrongPassBanTime, _accountInfo.Login.c_str(), _accountInfo.FailedLogins);
                }
            }
        }
    }

    return true;
}

bool AuthSession::HandleReconnectChallenge()
{
    if (_sentChallenge)
        return false;

    _sentChallenge = true;

    sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(GetReadBuffer().GetReadPointer());
    if (challenge->size - (sizeof(sAuthLogonChallenge_C) - AUTH_LOGON_CHALLENGE_INITIAL_SIZE - 1) != challenge->I_len)
        return false;

    std::string login((const char*)challenge->I, challenge->I_len);
    TC_LOG_DEBUG("server.authserver", "[ReconnectChallenge] '%s'", login.c_str());

    if (_queryCallback)
    {
        ByteBuffer pkt;
        pkt << uint8(AUTH_RECONNECT_CHALLENGE);
        pkt << uint8(WOW_FAIL_DB_BUSY);
        SendPacket(pkt);

        TC_LOG_DEBUG("server.authserver", "[ReconnectChallenge] %s attempted to log too quick after previous attempt!", login.c_str());
        return true;
    }

    _build = challenge->build;
    _expversion = uint8(AuthHelper::IsPostBCAcceptedClientBuild(_build) ? POST_BC_EXP_FLAG : (AuthHelper::IsPreBCAcceptedClientBuild(_build) ? PRE_BC_EXP_FLAG : NO_VALID_EXP_FLAG));
    std::array<char, 5> os;
    os.fill('\0');
    memcpy(os.data(), challenge->os, sizeof(challenge->os));
    _os = os.data();

    // Restore string order as its byte order is reversed
    std::reverse(_os.begin(), _os.end());

    _localizationName.resize(4);
    for (int i = 0; i < 4; ++i)
        _localizationName[i] = challenge->country[4 - i - 1];

    // Get the account details from the account table
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_RECONNECTCHALLENGE);
    stmt->setString(0, login);

    _queryCallback = std::bind(&AuthSession::ReconnectChallengeCallback, this, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
    return true;
}

void AuthSession::ReconnectChallengeCallback(PreparedQueryResult result)
{
    ByteBuffer pkt;
    pkt << uint8(AUTH_RECONNECT_CHALLENGE);

    if (!result)
    {
        pkt << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
        SendPacket(pkt);
        return;
    }

    Field* fields = result->Fetch();

    _accountInfo.LoadResult(fields);
    K.SetHexStr(fields[9].GetCString());
    _reconnectProof.SetRand(16 * 8);

    pkt << uint8(WOW_SUCCESS);
    pkt.append(_reconnectProof.AsByteArray(16).get(), 16);  // 16 bytes random
    pkt << uint64(0x00) << uint64(0x00);                    // 16 bytes zeros

    SendPacket(pkt);
}

bool AuthSession::HandleReconnectProof()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleReconnectProof");
    if (_sentProof)
        return false;

    _sentProof = true;

    sAuthReconnectProof_C *reconnectProof = reinterpret_cast<sAuthReconnectProof_C*>(GetReadBuffer().GetReadPointer());

    if (_accountInfo.Login.empty() || !_reconnectProof.GetNumBytes() || !K.GetNumBytes())
        return false;

    BigNumber t1;
    t1.SetBinary(reconnectProof->R1, 16);

    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(_accountInfo.Login);
    sha.UpdateBigNumbers(&t1, &_reconnectProof, &K, NULL);
    sha.Finalize();

    if (!memcmp(sha.GetDigest(), reconnectProof->R2, SHA_DIGEST_LENGTH))
    {
        // Sending response
        ByteBuffer pkt;
        pkt << uint8(AUTH_RECONNECT_PROOF);
        pkt << uint8(0x00);
        pkt << uint16(0x00);                               // 2 bytes zeros
        SendPacket(pkt);
        _status = STATUS_AUTHED;
        return true;
    }
    else
    {
        TC_LOG_ERROR("server.authserver.hack", "'%s:%d' [ERROR] user %s tried to login, but session is invalid.", GetRemoteIpAddress().to_string().c_str(),
            GetRemotePort(), _accountInfo.Login.c_str());
        return false;
    }
}

bool AuthSession::HandleRealmList()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleRealmList");

    if (_queryCallback)
    {
        TC_LOG_DEBUG("server.authserver", "[RealmList] %s attempted to get realmlist too quick after previous attempt!", _accountInfo.Login.c_str());
        return false;
    }

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALM_CHARACTER_COUNTS);
    stmt->setUInt32(0, _accountInfo.Id);

    _queryCallback = std::bind(&AuthSession::RealmListCallback, this, std::placeholders::_1);
    _queryFuture = LoginDatabase.AsyncQuery(stmt);
    return true;
}

void AuthSession::RealmListCallback(PreparedQueryResult result)
{
    std::map<uint32, uint8> characterCounts;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            characterCounts[fields[0].GetUInt32()] = fields[1].GetUInt8();
        } while (result->NextRow());
    }

    // Circle through realms in the RealmList and construct the return packet (including # of user characters in each realm)
    ByteBuffer pkt;

    size_t RealmListSize = 0;
    for (RealmList::RealmMap::value_type const& i : sRealmList->GetRealms())
    {
        const Realm &realm = i.second;
        // don't work with realms which not compatible with the client
        bool okBuild = ((_expversion & POST_BC_EXP_FLAG) && realm.Build == _build) || ((_expversion & PRE_BC_EXP_FLAG) && !AuthHelper::IsPreBCAcceptedClientBuild(realm.Build));

        // No SQL injection. id of realm is controlled by the database.
        uint32 flag = realm.Flags;
        RealmBuildInfo const* buildInfo = AuthHelper::GetBuildInfo(realm.Build);
        if (!okBuild)
        {
            if (!buildInfo)
                continue;

            flag |= REALM_FLAG_OFFLINE | REALM_FLAG_SPECIFYBUILD;   // tell the client what build the realm is for
        }

        if (!buildInfo)
            flag &= ~REALM_FLAG_SPECIFYBUILD;

        std::string name = realm.Name;
        if (_expversion & PRE_BC_EXP_FLAG && flag & REALM_FLAG_SPECIFYBUILD)
        {
            std::ostringstream ss;
            ss << name << " (" << buildInfo->MajorVersion << '.' << buildInfo->MinorVersion << '.' << buildInfo->BugfixVersion << ')';
            name = ss.str();
        }

        uint8 lock = (realm.AllowedSecurityLevel > _accountInfo.SecurityLevel) ? 1 : 0;

        pkt << uint8(realm.Type);                           // realm type
        if (_expversion & POST_BC_EXP_FLAG)                 // only 2.x and 3.x clients
            pkt << uint8(lock);                             // if 1, then realm locked
        pkt << uint8(flag);                                 // RealmFlags
        pkt << name;
        pkt << boost::lexical_cast<std::string>(realm.GetAddressForClient(GetRemoteIpAddress()));
        pkt << float(realm.PopulationLevel);
        pkt << uint8(characterCounts[realm.Id.Realm]);
        pkt << uint8(realm.Timezone);                       // realm category
        if (_expversion & POST_BC_EXP_FLAG)                 // 2.x and 3.x clients
            pkt << uint8(realm.Id.Realm);
        else
            pkt << uint8(0x0);                              // 1.12.1 and 1.12.2 clients

        if (_expversion & POST_BC_EXP_FLAG && flag & REALM_FLAG_SPECIFYBUILD)
        {
            pkt << uint8(buildInfo->MajorVersion);
            pkt << uint8(buildInfo->MinorVersion);
            pkt << uint8(buildInfo->BugfixVersion);
            pkt << uint16(buildInfo->Build);
        }

        ++RealmListSize;
    }

    if (_expversion & POST_BC_EXP_FLAG)                     // 2.x and 3.x clients
    {
        pkt << uint8(0x10);
        pkt << uint8(0x00);
    }
    else                                                    // 1.12.1 and 1.12.2 clients
    {
        pkt << uint8(0x00);
        pkt << uint8(0x02);
    }

    // make a ByteBuffer which stores the RealmList's size
    ByteBuffer RealmListSizeBuffer;
    RealmListSizeBuffer << uint32(0);
    if (_expversion & POST_BC_EXP_FLAG)                     // only 2.x and 3.x clients
        RealmListSizeBuffer << uint16(RealmListSize);
    else
        RealmListSizeBuffer << uint32(RealmListSize);

    ByteBuffer hdr;
    hdr << uint8(REALM_LIST);
    hdr << uint16(pkt.size() + RealmListSizeBuffer.size());
    hdr.append(RealmListSizeBuffer);                        // append RealmList's size buffer
    hdr.append(pkt);                                        // append realms in the realmlist
    SendPacket(hdr);
}

// Make the SRP6 calculation from hash in dB
void AuthSession::SetVSFields(const std::string& rI)
{
    s.SetRand(int32(BufferSizes::SRP_6_S) * 8);

    BigNumber I;
    I.SetHexStr(rI.c_str());

    // In case of leading zeros in the rI hash, restore them
    uint8 mDigest[SHA_DIGEST_LENGTH];
    memcpy(mDigest, I.AsByteArray(SHA_DIGEST_LENGTH).get(), SHA_DIGEST_LENGTH);

    std::reverse(mDigest, mDigest + SHA_DIGEST_LENGTH);

    SHA1Hash sha;
    sha.UpdateData(s.AsByteArray(uint32(BufferSizes::SRP_6_S)).get(), (uint32(BufferSizes::SRP_6_S)));
    sha.UpdateData(mDigest, SHA_DIGEST_LENGTH);
    sha.Finalize();
    BigNumber x;
    x.SetBinary(sha.GetDigest(), sha.GetLength());
    v = g.ModExp(x, N);

    // No SQL injection (username escaped)
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_VS);
    stmt->setString(0, v.AsHexStr());
    stmt->setString(1, s.AsHexStr());
    stmt->setString(2, _accountInfo.Login);
    LoginDatabase.Execute(stmt);
}
