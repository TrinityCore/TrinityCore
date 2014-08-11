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

enum eStatus
{
    STATUS_CONNECTED = 0,
    STATUS_AUTHED
};

#pragma pack(push, 1)

typedef struct AUTH_LOGON_CHALLENGE_C
{
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
    uint32  unk1;
    uint32  unk2;
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

#define REALM_LIST_PACKET_SIZE 4
#define XFER_ACCEPT_SIZE 0
#define XFER_RESUME_SIZE 8
#define XFER_CANCEL_SIZE 0

std::unordered_map<uint8, AuthHandler> AuthSession::InitHandlers()
{
    std::unordered_map<uint8, AuthHandler> handlers;

    handlers[AUTH_LOGON_CHALLENGE]     = { STATUS_CONNECTED, sizeof(AUTH_LOGON_CHALLENGE_C), &AuthSession::HandleLogonChallenge };
    handlers[AUTH_LOGON_PROOF]         = { STATUS_CONNECTED, sizeof(AUTH_LOGON_PROOF_C),     &AuthSession::HandleLogonProof };
    handlers[AUTH_RECONNECT_CHALLENGE] = { STATUS_CONNECTED, sizeof(AUTH_LOGON_CHALLENGE_C), &AuthSession::HandleReconnectChallenge };
    handlers[AUTH_RECONNECT_PROOF]     = { STATUS_CONNECTED, sizeof(AUTH_RECONNECT_PROOF_C), &AuthSession::HandleReconnectProof };
    handlers[REALM_LIST]               = { STATUS_AUTHED,    REALM_LIST_PACKET_SIZE,         &AuthSession::HandleRealmList };
    handlers[XFER_ACCEPT]              = { STATUS_AUTHED,    XFER_ACCEPT_SIZE,               &AuthSession::HandleXferAccept };
    handlers[XFER_RESUME]              = { STATUS_AUTHED,    XFER_RESUME_SIZE,               &AuthSession::HandleXferResume };
    handlers[XFER_CANCEL]              = { STATUS_AUTHED,    XFER_CANCEL_SIZE,               &AuthSession::HandleXferCancel };

    return handlers;
}

std::unordered_map<uint8, AuthHandler> const Handlers = AuthSession::InitHandlers();

void AuthSession::ReadHeaderHandler()
{
    uint8 cmd = GetHeaderBuffer()[0];
    auto itr = Handlers.find(cmd);
    if (itr != Handlers.end())
    {
        // Handle dynamic size packet
        if (cmd == AUTH_LOGON_CHALLENGE || cmd == AUTH_RECONNECT_CHALLENGE)
        {
            ReadData(sizeof(uint8) + sizeof(uint16)); //error + size
            sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(GetDataBuffer());

            AsyncReadData(challenge->size);
        }
        else
            AsyncReadData(itr->second.packetSize);
    }
    else
        CloseSocket();
}

void AuthSession::ReadDataHandler()
{
    if (!(*this.*Handlers.at(GetHeaderBuffer()[0]).handler)())
    {
        CloseSocket();
        return;
    }

    AsyncReadHeader();
}

void AuthSession::AsyncWrite(ByteBuffer& packet)
{
    if (!IsOpen())
        return;

    std::lock_guard<std::mutex> guard(_writeLock);

    bool needsWriteStart = _writeQueue.empty();

    _writeQueue.push(std::move(packet));

    if (needsWriteStart)
        AuthSocket::AsyncWrite(_writeQueue.front());
}

bool AuthSession::HandleLogonChallenge()
{
    sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(GetDataBuffer());

    //TC_LOG_DEBUG("server.authserver", "[AuthChallenge] got full packet, %#04x bytes", challenge->size);
    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] name(%d): '%s'", challenge->I_len, challenge->I);

    ByteBuffer pkt;

    _login.assign((const char*)challenge->I, challenge->I_len);
    _build = challenge->build;
    _expversion = uint8(AuthHelper::IsPostBCAcceptedClientBuild(_build) ? POST_BC_EXP_FLAG : (AuthHelper::IsPreBCAcceptedClientBuild(_build) ? PRE_BC_EXP_FLAG : NO_VALID_EXP_FLAG));
    _os = (const char*)challenge->os;

    if (_os.size() > 4)
        return false;

    // Restore string order as its byte order is reversed
    std::reverse(_os.begin(), _os.end());

    pkt << uint8(AUTH_LOGON_CHALLENGE);
    pkt << uint8(0x00);

    // Verify that this IP is not in the ip_banned table
    LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));

    std::string ipAddress = GetRemoteIpAddress().to_string();
    uint16 port = GetRemotePort();

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_BANNED);
    stmt->setString(0, ipAddress);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (result)
    {
        pkt << uint8(WOW_FAIL_BANNED);
        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] Banned ip tries to login!", ipAddress.c_str(), port);
    }
    else
    {
        // Get the account details from the account table
        // No SQL injection (prepared statement)
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGONCHALLENGE);
        stmt->setString(0, _login);

        PreparedQueryResult res2 = LoginDatabase.Query(stmt);
        if (res2)
        {
            Field* fields = res2->Fetch();

            // If the IP is 'locked', check that the player comes indeed from the correct IP address
            bool locked = false;
            if (fields[2].GetUInt8() == 1)                  // if ip is locked
            {
                TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is locked to IP - '%s'", _login.c_str(), fields[4].GetCString());
                TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Player address is '%s'", ipAddress.c_str());

                if (strcmp(fields[4].GetCString(), ipAddress.c_str()) != 0)
                {
                    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account IP differs");
                    pkt << uint8(WOW_FAIL_LOCKED_ENFORCED);
                    locked = true;
                }
                else
                    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account IP matches");
            }
            else
            {
                TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is not locked to ip", _login.c_str());
                std::string accountCountry = fields[3].GetString();
                if (accountCountry.empty() || accountCountry == "00")
                    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is not locked to country", _login.c_str());
                else if (!accountCountry.empty())
                {
                    uint32 ip = inet_addr(ipAddress.c_str());
                    EndianConvertReverse(ip);

                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGON_COUNTRY);
                    stmt->setUInt32(0, ip);
                    if (PreparedQueryResult sessionCountryQuery = LoginDatabase.Query(stmt))
                    {
                        std::string loginCountry = (*sessionCountryQuery)[0].GetString();
                        TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account '%s' is locked to country: '%s' Player country is '%s'", _login.c_str(),
                            accountCountry.c_str(), loginCountry.c_str());

                        if (loginCountry != accountCountry)
                        {
                            TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account country differs.");
                            pkt << uint8(WOW_FAIL_UNLOCKABLE_LOCK);
                            locked = true;
                        }
                        else
                            TC_LOG_DEBUG("server.authserver", "[AuthChallenge] Account country matches");
                    }
                    else
                        TC_LOG_DEBUG("server.authserver", "[AuthChallenge] IP2NATION Table empty");
                }
            }

            if (!locked)
            {
                //set expired bans to inactive
                LoginDatabase.DirectExecute(LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS));

                // If the account is banned, reject the logon attempt
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BANNED);
                stmt->setUInt32(0, fields[1].GetUInt32());
                PreparedQueryResult banresult = LoginDatabase.Query(stmt);
                if (banresult)
                {
                    if ((*banresult)[0].GetUInt32() == (*banresult)[1].GetUInt32())
                    {
                        pkt << uint8(WOW_FAIL_BANNED);
                        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] Banned account %s tried to login!", ipAddress.c_str(),
                            port, _login.c_str());
                    }
                    else
                    {
                        pkt << uint8(WOW_FAIL_SUSPENDED);
                        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] Temporarily banned account %s tried to login!",
                            ipAddress.c_str(), port, _login.c_str());
                    }
                }
                else
                {
                    // Get the password from the account table, upper it, and make the SRP6 calculation
                    std::string rI = fields[0].GetString();

                    // Don't calculate (v, s) if there are already some in the database
                    std::string databaseV = fields[6].GetString();
                    std::string databaseS = fields[7].GetString();

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
                    if (fields[9].GetUInt32() && AuthHelper::IsBuildSupportingBattlenet(_build))
                        pkt << uint8(WOW_FAIL_USE_BATTLENET);
                    else if (AuthHelper::IsAcceptedClientBuild(_build))
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
                    _tokenKey = fields[8].GetString();
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

                    uint8 secLevel = fields[5].GetUInt8();
                    _accountSecurityLevel = secLevel <= SEC_ADMINISTRATOR ? AccountTypes(secLevel) : SEC_ADMINISTRATOR;

                    _localizationName.resize(4);
                    for (int i = 0; i < 4; ++i)
                        _localizationName[i] = challenge->country[4 - i - 1];

                    TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] account %s is using '%c%c%c%c' locale (%u)",
                        ipAddress.c_str(), port, _login.c_str(),
                        challenge->country[3], challenge->country[2], challenge->country[1], challenge->country[0],
                        GetLocaleByName(_localizationName)
                        );
                }
            }
        }
        else                                                //no account
            pkt << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
    }

    AsyncWrite(pkt);
    return true;
}

// Logon Proof command handler
bool AuthSession::HandleLogonProof()
{

    TC_LOG_DEBUG("server.authserver", "Entering _HandleLogonProof");
    // Read the packet
    sAuthLogonProof_C *logonProof = reinterpret_cast<sAuthLogonProof_C*>(GetDataBuffer());

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
    if (A.isZero())
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
    sha.UpdateData(_login);
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
        TC_LOG_DEBUG("server.authserver", "'%s:%d' User '%s' successfully authenticated", GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _login.c_str());

        // Update the sessionkey, last_ip, last login time and reset number of failed logins in the account table for this account
        PreparedStatement *stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LOGONPROOF);
        stmt->setString(0, K.AsHexStr());
        stmt->setString(1, GetRemoteIpAddress().to_string().c_str());
        stmt->setUInt32(2, GetLocaleByName(_localizationName));
        stmt->setString(3, _os);
        stmt->setString(4, _login);
        LoginDatabase.DirectExecute(stmt);

        // Finish SRP6 and send the final result to the client
        sha.Initialize();
        sha.UpdateBigNumbers(&A, &M, &K, NULL);
        sha.Finalize();

        // Check auth token
        if ((logonProof->securityFlags & 0x04) || !_tokenKey.empty())
        {
            ReadData(1);
            uint8 size = *(GetDataBuffer() + sizeof(sAuthLogonProof_C));
            ReadData(size);
            std::string token(reinterpret_cast<char*>(GetDataBuffer() + sizeof(sAuthLogonProof_C) + sizeof(size)), size);
            uint32 validToken = TOTP::GenerateToken(_tokenKey.c_str());
            uint32 incomingToken = atoi(token.c_str());
            if (validToken != incomingToken)
            {
                ByteBuffer packet;
                packet << uint8(AUTH_LOGON_PROOF);
                packet << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
                packet << uint8(3);
                packet << uint8(0);
                AsyncWrite(packet);
                return false;
            }
        }

        ByteBuffer packet;
        if (_expversion & POST_BC_EXP_FLAG)                 // 2.x and 3.x clients
        {
            sAuthLogonProof_S proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            proof.unk1 = GAMEACCOUNT_FLAG_PROPASS_LOCK;
            proof.unk2 = 0x00;          // SurveyId
            proof.unk3 = 0x00;

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

        AsyncWrite(packet);
        _isAuthenticated = true;
    }
    else
    {
        ByteBuffer packet;
        packet << uint8(AUTH_LOGON_PROOF);
        packet << uint8(WOW_FAIL_UNKNOWN_ACCOUNT);
        packet << uint8(3);
        packet << uint8(0);
        AsyncWrite(packet);

        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] account %s tried to login with invalid password!",
            GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _login.c_str());

        uint32 MaxWrongPassCount = sConfigMgr->GetIntDefault("WrongPass.MaxCount", 0);

        // We can not include the failed account login hook. However, this is a workaround to still log this.
        if (sConfigMgr->GetBoolDefault("Wrong.Password.Login.Logging", false))
        {
            PreparedStatement* logstmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_FALP_IP_LOGGING);
            logstmt->setString(0, _login);
            logstmt->setString(1, GetRemoteIpAddress().to_string());
            logstmt->setString(2, "Logged on failed AccountLogin due wrong password");

            LoginDatabase.Execute(logstmt);
        }

        if (MaxWrongPassCount > 0)
        {
            //Increment number of failed logins by one and if it reaches the limit temporarily ban that account or IP
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_FAILEDLOGINS);
            stmt->setString(0, _login);
            LoginDatabase.Execute(stmt);

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_FAILEDLOGINS);
            stmt->setString(0, _login);

            if (PreparedQueryResult loginfail = LoginDatabase.Query(stmt))
            {
                uint32 failed_logins = (*loginfail)[1].GetUInt32();

                if (failed_logins >= MaxWrongPassCount)
                {
                    uint32 WrongPassBanTime = sConfigMgr->GetIntDefault("WrongPass.BanTime", 600);
                    bool WrongPassBanType = sConfigMgr->GetBoolDefault("WrongPass.BanType", false);

                    if (WrongPassBanType)
                    {
                        uint32 acc_id = (*loginfail)[0].GetUInt32();
                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT_AUTO_BANNED);
                        stmt->setUInt32(0, acc_id);
                        stmt->setUInt32(1, WrongPassBanTime);
                        LoginDatabase.Execute(stmt);

                        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] account %s got banned for '%u' seconds because it failed to authenticate '%u' times",
                            GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _login.c_str(), WrongPassBanTime, failed_logins);
                    }
                    else
                    {
                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_IP_AUTO_BANNED);
                        stmt->setString(0, GetRemoteIpAddress().to_string());
                        stmt->setUInt32(1, WrongPassBanTime);
                        LoginDatabase.Execute(stmt);

                        TC_LOG_DEBUG("server.authserver", "'%s:%d' [AuthChallenge] IP got banned for '%u' seconds because account %s failed to authenticate '%u' times",
                            GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), WrongPassBanTime, _login.c_str(), failed_logins);
                    }
                }
            }
        }
    }

    return true;
}

bool AuthSession::HandleReconnectChallenge()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleReconnectChallenge");
    sAuthLogonChallenge_C* challenge = reinterpret_cast<sAuthLogonChallenge_C*>(GetDataBuffer());

    //TC_LOG_DEBUG("server.authserver", "[AuthChallenge] got full packet, %#04x bytes", challenge->size);
    TC_LOG_DEBUG("server.authserver", "[AuthChallenge] name(%d): '%s'", challenge->I_len, challenge->I);

    _login.assign((const char*)challenge->I, challenge->I_len);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_SESSIONKEY);
    stmt->setString(0, _login);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Stop if the account is not found
    if (!result)
    {
        TC_LOG_ERROR("server.authserver", "'%s:%d' [ERROR] user %s tried to login and we cannot find his session key in the database.",
            GetRemoteIpAddress().to_string().c_str(), GetRemotePort(), _login.c_str());
        return false;
    }

    // Reinitialize build, expansion and the account securitylevel
    _build = challenge->build;
    _expversion = uint8(AuthHelper::IsPostBCAcceptedClientBuild(_build) ? POST_BC_EXP_FLAG : (AuthHelper::IsPreBCAcceptedClientBuild(_build) ? PRE_BC_EXP_FLAG : NO_VALID_EXP_FLAG));
    _os = (const char*)challenge->os;

    if (_os.size() > 4)
        return false;

    // Restore string order as its byte order is reversed
    std::reverse(_os.begin(), _os.end());

    Field* fields = result->Fetch();
    uint8 secLevel = fields[2].GetUInt8();
    _accountSecurityLevel = secLevel <= SEC_ADMINISTRATOR ? AccountTypes(secLevel) : SEC_ADMINISTRATOR;

    K.SetHexStr((*result)[0].GetCString());

    // Sending response
    ByteBuffer pkt;
    pkt << uint8(AUTH_RECONNECT_CHALLENGE);
    pkt << uint8(0x00);
    _reconnectProof.SetRand(16 * 8);
    pkt.append(_reconnectProof.AsByteArray(16).get(), 16);        // 16 bytes random
    pkt << uint64(0x00) << uint64(0x00);                    // 16 bytes zeros

    AsyncWrite(pkt);

    return true;
}
bool AuthSession::HandleReconnectProof()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleReconnectProof");
    sAuthReconnectProof_C *reconnectProof = reinterpret_cast<sAuthReconnectProof_C*>(GetDataBuffer());

    if (_login.empty() || !_reconnectProof.GetNumBytes() || !K.GetNumBytes())
        return false;

    BigNumber t1;
    t1.SetBinary(reconnectProof->R1, 16);

    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(_login);
    sha.UpdateBigNumbers(&t1, &_reconnectProof, &K, NULL);
    sha.Finalize();

    if (!memcmp(sha.GetDigest(), reconnectProof->R2, SHA_DIGEST_LENGTH))
    {
        // Sending response
        ByteBuffer pkt;
        pkt << uint8(AUTH_RECONNECT_PROOF);
        pkt << uint8(0x00);
        pkt << uint16(0x00);                               // 2 bytes zeros
        AsyncWrite(pkt);
        _isAuthenticated = true;
        return true;
    }
    else
    {
        TC_LOG_ERROR("server.authserver", "'%s:%d' [ERROR] user %s tried to login, but session is invalid.", GetRemoteIpAddress().to_string().c_str(),
            GetRemotePort(), _login.c_str());
        return false;
    }
}

bool AuthSession::HandleRealmList()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleRealmList");

    // Get the user id (else close the connection)
    // No SQL injection (prepared statement)
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ID_BY_NAME);
    stmt->setString(0, _login);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_ERROR("server.authserver", "'%s:%d' [ERROR] user %s tried to login but we cannot find him in the database.", GetRemoteIpAddress().to_string().c_str(),
            GetRemotePort(), _login.c_str());
        return false;
    }

    Field* fields = result->Fetch();
    uint32 id = fields[0].GetUInt32();

    // Update realm list if need
    sRealmList->UpdateIfNeed();

    // Circle through realms in the RealmList and construct the return packet (including # of user characters in each realm)
    ByteBuffer pkt;

    size_t RealmListSize = 0;
    for (RealmList::RealmMap::const_iterator i = sRealmList->begin(); i != sRealmList->end(); ++i)
    {
        const Realm &realm = i->second;
        // don't work with realms which not compatible with the client
        bool okBuild = ((_expversion & POST_BC_EXP_FLAG) && realm.gamebuild == _build) || ((_expversion & PRE_BC_EXP_FLAG) && !AuthHelper::IsPreBCAcceptedClientBuild(realm.gamebuild));

        // No SQL injection. id of realm is controlled by the database.
        uint32 flag = realm.flag;
        RealmBuildInfo const* buildInfo = AuthHelper::GetBuildInfo(realm.gamebuild);
        if (!okBuild)
        {
            if (!buildInfo)
                continue;

            flag |= REALM_FLAG_OFFLINE | REALM_FLAG_SPECIFYBUILD;   // tell the client what build the realm is for
        }

        if (!buildInfo)
            flag &= ~REALM_FLAG_SPECIFYBUILD;

        std::string name = i->first;
        if (_expversion & PRE_BC_EXP_FLAG && flag & REALM_FLAG_SPECIFYBUILD)
        {
            std::ostringstream ss;
            ss << name << " (" << buildInfo->MajorVersion << '.' << buildInfo->MinorVersion << '.' << buildInfo->BugfixVersion << ')';
            name = ss.str();
        }

        uint8 lock = (realm.allowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;

        uint8 AmountOfCharacters = 0;
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_NUM_CHARS_ON_REALM);
        stmt->setUInt32(0, realm.m_ID);
        stmt->setUInt32(1, id);
        result = LoginDatabase.Query(stmt);
        if (result)
            AmountOfCharacters = (*result)[0].GetUInt8();

        pkt << realm.icon;                                  // realm type
        if (_expversion & POST_BC_EXP_FLAG)                 // only 2.x and 3.x clients
            pkt << lock;                                    // if 1, then realm locked
        pkt << uint8(flag);                                 // RealmFlags
        pkt << name;
        pkt << boost::lexical_cast<std::string>(realm.GetAddressForClient(GetRemoteIpAddress()));
        pkt << realm.populationLevel;
        pkt << AmountOfCharacters;
        pkt << realm.timezone;                              // realm category
        if (_expversion & POST_BC_EXP_FLAG)                 // 2.x and 3.x clients
            pkt << uint8(realm.m_ID);
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
    AsyncWrite(hdr);
    return true;
}

// Resume patch transfer
bool AuthSession::HandleXferResume()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleXferResume");
    //uint8
    //uint64
    return true;
}

// Cancel patch transfer
bool AuthSession::HandleXferCancel()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleXferCancel");
    //uint8
    return false;
}

// Accept patch transfer
bool AuthSession::HandleXferAccept()
{
    TC_LOG_DEBUG("server.authserver", "Entering _HandleXferAccept");
    //uint8
    return true;
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

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_VS);
    stmt->setString(0, v.AsHexStr());
    stmt->setString(1, s.AsHexStr());
    stmt->setString(2, _login);
    LoginDatabase.Execute(stmt);
}
