/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup realmd
*/

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "ByteBuffer.h"
#include "Configuration/Config.h"
#include "Log.h"
#include "RealmList.h"
#include "AuthSocket.h"
#include "AuthCodes.h"
#include <openssl/md5.h>
#include "SHA1.h"
//#include "Util.h" -- for commented utf8ToUpperOnlyLatin

#define ChunkSize 2048

enum eAuthCmd
{
    //AUTH_NO_CMD                 = 0xFF,
    AUTH_LOGON_CHALLENGE        = 0x00,
    AUTH_LOGON_PROOF            = 0x01,
    AUTH_RECONNECT_CHALLENGE    = 0x02,
    AUTH_RECONNECT_PROOF        = 0x03,
    //update srv =4
    REALM_LIST                  = 0x10,
    XFER_INITIATE               = 0x30,
    XFER_DATA                   = 0x31,
    XFER_ACCEPT                 = 0x32,
    XFER_RESUME                 = 0x33,
    XFER_CANCEL                 = 0x34
};

enum eStatus
{
    STATUS_CONNECTED = 0,
    STATUS_AUTHED
};

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push,N), also any gcc version not support it at some paltform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

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
    uint8   securityFlags;                                  // 0x00-0x04
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
    //uint32  unk1;
    uint32  unk2;
    //uint16  unk3;
} sAuthLogonProof_S_Old;

typedef struct AUTH_RECONNECT_PROOF_C
{
    uint8   cmd;
    uint8   R1[16];
    uint8   R2[20];
    uint8   R3[20];
    uint8   number_of_keys;
} sAuthReconnectProof_C;

typedef struct XFER_INIT
{
    uint8 cmd;                                              // XFER_INITIATE
    uint8 fileNameLen;                                      // strlen(fileName);
    uint8 fileName[5];                                      // fileName[fileNameLen]
    uint64 file_size;                                       // file size (bytes)
    uint8 md5[MD5_DIGEST_LENGTH];                           // MD5
} XFER_INIT;

typedef struct XFER_DATA
{
    uint8 opcode;
    uint16 data_size;
    uint8 data[ChunkSize];
} XFER_DATA_STRUCT;

typedef struct AuthHandler
{
    eAuthCmd cmd;
    uint32 status;
    bool (AuthSocket::*handler)(void);
} AuthHandler;

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some paltform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

/// Launch a thread to transfer a patch to the client
class PatcherRunnable: public ACE_Based::Runnable
{
    public:
        PatcherRunnable(class AuthSocket *);
        void run();

    private:
        AuthSocket * mySocket;
};

typedef struct PATCH_INFO
{
    uint8 md5[MD5_DIGEST_LENGTH];
} PATCH_INFO;

/// Caches MD5 hash of client patches present on the server
class Patcher
{
    public:
        typedef std::map<std::string, PATCH_INFO*> Patches;
        ~Patcher();
        Patcher();
        Patches::const_iterator begin() const { return _patches.begin(); }
        Patches::const_iterator end() const { return _patches.end(); }
        void LoadPatchMD5(char*);
        bool GetHash(char * pat,uint8 mymd5[16]);

    private:
        void LoadPatchesInfo();
        Patches _patches;
};

const AuthHandler table[] =
{
    { AUTH_LOGON_CHALLENGE,     STATUS_CONNECTED, &AuthSocket::_HandleLogonChallenge    },
    { AUTH_LOGON_PROOF,         STATUS_CONNECTED, &AuthSocket::_HandleLogonProof        },
    { AUTH_RECONNECT_CHALLENGE, STATUS_CONNECTED, &AuthSocket::_HandleReconnectChallenge},
    { AUTH_RECONNECT_PROOF,     STATUS_CONNECTED, &AuthSocket::_HandleReconnectProof    },
    { REALM_LIST,               STATUS_AUTHED,    &AuthSocket::_HandleRealmList         },
    { XFER_ACCEPT,              STATUS_CONNECTED, &AuthSocket::_HandleXferAccept        },
    { XFER_RESUME,              STATUS_CONNECTED, &AuthSocket::_HandleXferResume        },
    { XFER_CANCEL,              STATUS_CONNECTED, &AuthSocket::_HandleXferCancel        }
};

#define AUTH_TOTAL_COMMANDS sizeof(table)/sizeof(AuthHandler)

///Holds the MD5 hash of client patches present on the server
Patcher PatchesCache;

/// Constructor - set the N and g values for SRP6
AuthSocket::AuthSocket(RealmSocket& socket) : socket_(socket)
{
    N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
    g.SetDword(7);
    _authed = false;
    _accountSecurityLevel = SEC_PLAYER;
}

/// Close patch file descriptor before leaving
AuthSocket::~AuthSocket(void)
{
}

/// Accept the connection and set the s random value for SRP6
void AuthSocket::OnAccept(void)
{
    sLog.outBasic("Accepting connection from '%s'", socket().get_remote_address().c_str());
}

void AuthSocket::OnClose(void)
{
    sLog.outDebug("AuthSocket::OnClose");
}

/// Read the packet from the client
void AuthSocket::OnRead()
{
    uint8 _cmd;
    while (1)
    {
        if (!socket().recv_soft((char *)&_cmd, 1))
            return;

        size_t i;

        ///- Circle through known commands and call the correct command handler
        for (i = 0; i < AUTH_TOTAL_COMMANDS; ++i)
        {
            if ((uint8)table[i].cmd == _cmd &&
                (table[i].status == STATUS_CONNECTED ||
                (_authed && table[i].status == STATUS_AUTHED)))
            {
                sLog.outStaticDebug("[Auth] got data for cmd %u recv length %u", (uint32)_cmd, (uint32)socket().recv_len());

                if (!(*this.*table[i].handler)())
                {
                    sLog.outStaticDebug("Command handler failed for cmd %u recv length %u", (uint32)_cmd, (uint32)socket().recv_len());
                    return;
                }
                break;
            }
        }

        // Report unknown packets in the error log
        if (i == AUTH_TOTAL_COMMANDS)
        {
            sLog.outError("[Auth] got unknown packet from '%s'", socket().get_remote_address().c_str());
            socket().shutdown();
            return;
        }
    }
}

/// Make the SRP6 calculation from hash in dB
void AuthSocket::_SetVSFields(const std::string& rI)
{
    s.SetRand(s_BYTE_SIZE * 8);

    BigNumber I;
    I.SetHexStr(rI.c_str());

    // In case of leading zeros in the rI hash, restore them
    uint8 mDigest[SHA_DIGEST_LENGTH];
    memset(mDigest, 0, SHA_DIGEST_LENGTH);
    if (I.GetNumBytes() <= SHA_DIGEST_LENGTH)
        memcpy(mDigest, I.AsByteArray(), I.GetNumBytes());

    std::reverse(mDigest, mDigest + SHA_DIGEST_LENGTH);

    SHA1Hash sha;
    sha.UpdateData(s.AsByteArray(), s.GetNumBytes());
    sha.UpdateData(mDigest, SHA_DIGEST_LENGTH);
    sha.Finalize();
    BigNumber x;
    x.SetBinary(sha.GetDigest(), sha.GetLength());
    v = g.ModExp(x, N);
    // No SQL injection (username escaped)
    const char *v_hex, *s_hex;
    v_hex = v.AsHexStr();
    s_hex = s.AsHexStr();

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_VS);
    stmt->setString(0, v_hex);
    stmt->setString(1, s_hex);
    stmt->setString(2, _safelogin);
    LoginDatabase.Execute(stmt);

    OPENSSL_free((void*)v_hex);
    OPENSSL_free((void*)s_hex);
}

/// Logon Challenge command handler
bool AuthSocket::_HandleLogonChallenge()
{
    sLog.outStaticDebug("Entering _HandleLogonChallenge");
    if (socket().recv_len() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    socket().recv((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    sLog.outStaticDebug("[AuthChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (socket().recv_len() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    ///- Read the remaining of the packet
    socket().recv((char *)&buf[4], remaining);
    sLog.outStaticDebug("[AuthChallenge] got full packet, %#04x bytes", ch->size);
    sLog.outStaticDebug("[AuthChallenge] name(%d): '%s'", ch->I_len, ch->I);

    // BigEndian code, nop in little endian case
    // size already converted
    EndianConvert(*((uint32*)(&ch->gamename[0])));
    EndianConvert(ch->build);
    EndianConvert(*((uint32*)(&ch->platform[0])));
    EndianConvert(*((uint32*)(&ch->os[0])));
    EndianConvert(*((uint32*)(&ch->country[0])));
    EndianConvert(ch->timezone_bias);
    EndianConvert(ch->ip);

    ByteBuffer pkt;

    _login = (const char*)ch->I;
    _build = ch->build;
    _expversion = (AuthHelper::IsPostBCAcceptedClientBuild(_build) ? POST_BC_EXP_FLAG : NO_VALID_EXP_FLAG) + (AuthHelper::IsPreBCAcceptedClientBuild(_build) ? PRE_BC_EXP_FLAG : NO_VALID_EXP_FLAG);

    ///- Normalize account name
    //utf8ToUpperOnlyLatin(_login); -- client already send account in expected form

    //Escape the user login to avoid further SQL injection
    //Memory will be freed on AuthSocket object destruction
    _safelogin = _login;
    LoginDatabase.escape_string(_safelogin);

    _build = ch->build;

    pkt << (uint8) AUTH_LOGON_CHALLENGE;
    pkt << (uint8) 0x00;

    ///- Verify that this IP is not in the ip_banned table
    // No SQL injection possible (paste the IP address as passed by the socket)
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate<=UNIX_TIMESTAMP() AND unbandate<>bandate");

    std::string address(socket().get_remote_address().c_str());
    LoginDatabase.escape_string(address);
    QueryResult result = LoginDatabase.PQuery("SELECT * FROM ip_banned WHERE ip = '%s'",address.c_str());
    if (result)
    {
        pkt << (uint8)WOW_FAIL_BANNED;
        sLog.outBasic("[AuthChallenge] Banned ip %s tries to login!", address.c_str ());
    }
    else
    {
        ///- Get the account details from the account table
        // No SQL injection (escaped user name)
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_LOGONCHALLENGE);
        stmt->setString(0, _safelogin.c_str());

        PreparedQueryResult res2 = LoginDatabase.Query(stmt);
        if (res2)
        {
            ///- If the IP is 'locked', check that the player comes indeed from the correct IP address
            bool locked = false;
            if (res2->GetUInt8(2) == 1)            // if ip is locked
            {
                sLog.outStaticDebug("[AuthChallenge] Account '%s' is locked to IP - '%s'", _login.c_str(), res2->GetString(3));
                sLog.outStaticDebug("[AuthChallenge] Player address is '%s'", socket().get_remote_address().c_str());
                if (strcmp(res2->GetString(3).c_str(),socket().get_remote_address().c_str()))
                {
                    sLog.outStaticDebug("[AuthChallenge] Account IP differs");
                    pkt << (uint8) WOW_FAIL_SUSPENDED;
                    locked=true;
                }
                else
                    sLog.outStaticDebug("[AuthChallenge] Account IP matches");
            }
            else
                sLog.outStaticDebug("[AuthChallenge] Account '%s' is not locked to ip", _login.c_str());

            if (!locked)
            {
                //set expired bans to inactive
                LoginDatabase.Execute("UPDATE account_banned SET active = 0 WHERE unbandate<=UNIX_TIMESTAMP() AND unbandate<>bandate");
                ///- If the account is banned, reject the logon attempt
                QueryResult banresult = LoginDatabase.PQuery("SELECT bandate,unbandate FROM account_banned WHERE id = %u AND active = 1", res2->GetUInt32(1));
                if (banresult)
                {
                    if ((*banresult)[0].GetUInt64() == (*banresult)[1].GetUInt64())
                    {
                        pkt << (uint8) WOW_FAIL_BANNED;
                        sLog.outBasic("[AuthChallenge] Banned account %s tries to login!",_login.c_str ());
                    }
                    else
                    {
                        pkt << (uint8) WOW_FAIL_SUSPENDED;
                        sLog.outBasic("[AuthChallenge] Temporarily banned account %s tries to login!",_login.c_str ());
                    }
                }
                else
                {
                    ///- Get the password from the account table, upper it, and make the SRP6 calculation
                    std::string rI = res2->GetString(1);

                    ///- Don't calculate (v, s) if there are already some in the database
                    std::string databaseV = res2->GetString(5);
                    std::string databaseS = res2->GetString(6);

                    sLog.outDebug("database authentication values: v='%s' s='%s'", databaseV.c_str(), databaseS.c_str());

                    // multiply with 2, bytes are stored as hexstring
                    if (databaseV.size() != s_BYTE_SIZE*2 || databaseS.size() != s_BYTE_SIZE*2)
                        _SetVSFields(rI);
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

                    ///- Fill the response packet with the result
                    pkt << uint8(WOW_SUCCESS);

                    // B may be calculated < 32B so we force minimal length to 32B
                    pkt.append(B.AsByteArray(32), 32);      // 32 bytes
                    pkt << uint8(1);
                    pkt.append(g.AsByteArray(), 1);
                    pkt << uint8(32);
                    pkt.append(N.AsByteArray(32), 32);
                    pkt.append(s.AsByteArray(), s.GetNumBytes());   // 32 bytes
                    pkt.append(unk3.AsByteArray(16), 16);
                    uint8 securityFlags = 0;
                    pkt << uint8(securityFlags);            // security flags (0x0...0x04)

                    if (securityFlags & 0x01)                // PIN input
                    {
                        pkt << uint32(0);
                        pkt << uint64(0) << uint64(0);      // 16 bytes hash?
                    }

                    if (securityFlags & 0x02)                // Matrix input
                    {
                        pkt << uint8(0);
                        pkt << uint8(0);
                        pkt << uint8(0);
                        pkt << uint8(0);
                        pkt << uint64(0);
                    }

                    if (securityFlags & 0x04)                // Security token input
                        pkt << uint8(1);

                    uint8 secLevel = res2->GetUInt8(4);
                    _accountSecurityLevel = secLevel <= SEC_ADMINISTRATOR ? AccountTypes(secLevel) : SEC_ADMINISTRATOR;

                    _localizationName.resize(4);
                    for (int i = 0; i < 4; ++i)
                        _localizationName[i] = ch->country[4-i-1];

                    sLog.outBasic("[AuthChallenge] account %s is using '%c%c%c%c' locale (%u)", _login.c_str (), ch->country[3], ch->country[2], ch->country[1], ch->country[0], GetLocaleByName(_localizationName));
                }
            }
        }
        else                                            //no account
        {
            pkt<< (uint8) WOW_FAIL_UNKNOWN_ACCOUNT;
        }
    }

    socket().send((char const*)pkt.contents(), pkt.size());
    return true;
}

/// Logon Proof command handler
bool AuthSocket::_HandleLogonProof()
{
    sLog.outStaticDebug("Entering _HandleLogonProof");
    ///- Read the packet
    sAuthLogonProof_C lp;

    if (!socket().recv((char *)&lp, sizeof(sAuthLogonProof_C)))
        return false;

    /// <ul><li> If the client has no valid version
    if (_expversion == NO_VALID_EXP_FLAG)
    {
        ///- Check if we have the appropriate patch on the disk

        sLog.outDebug("Client with invalid version, patching is not implemented");
        socket().shutdown();
        return true;
    }
    /// </ul>

    ///- Continue the SRP6 calculation based on data received from the client
    BigNumber A;

    A.SetBinary(lp.A, 32);

    // SRP safeguard: abort if A==0
    if (A.isZero())
    {
        socket().shutdown();
        return true;
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
    memcpy(t, S.AsByteArray(32), 32);
    for (int i = 0; i < 16; ++i)
    {
        t1[i] = t[i * 2];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; ++i)
    {
        vK[i * 2] = sha.GetDigest()[i];
    }
    for (int i = 0; i < 16; ++i)
    {
        t1[i] = t[i * 2 + 1];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; ++i)
    {
        vK[i * 2 + 1] = sha.GetDigest()[i];
    }
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
    {
        hash[i] ^= sha.GetDigest()[i];
    }
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
    M.SetBinary(sha.GetDigest(), 20);

    ///- Check if SRP6 results match (password is correct), else send an error
    if (!memcmp(M.AsByteArray(), lp.M1, 20))
    {
        sLog.outBasic("User '%s' successfully authenticated", _login.c_str());

        ///- Update the sessionkey, last_ip, last login time and reset number of failed logins in the account table for this account
        // No SQL injection (escaped user name) and IP address as received by socket
        const char* K_hex = K.AsHexStr();
        
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_LOGONPROOF);
        stmt->setString(0, K_hex);
        stmt->setString(1, socket().get_remote_address().c_str());
        stmt->setUInt32(2, GetLocaleByName(_localizationName));
        stmt->setString(3, _safelogin);
        LoginDatabase.Execute(stmt);

        OPENSSL_free((void*)K_hex);

        ///- Finish SRP6 and send the final result to the client
        sha.Initialize();
        sha.UpdateBigNumbers(&A, &M, &K, NULL);
        sha.Finalize();

        if (_expversion & POST_BC_EXP_FLAG)//2.4.3 and 3.1.3 clients (10146 is Chinese build for 3.1.3)
        {
            sAuthLogonProof_S proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            proof.unk1 = 0x00800000;
            proof.unk2 = 0x00;
            proof.unk3 = 0x00;
            socket().send((char *)&proof, sizeof(proof));
        }
        else
        {
            sAuthLogonProof_S_Old proof;
            memcpy(proof.M2, sha.GetDigest(), 20);
            proof.cmd = AUTH_LOGON_PROOF;
            proof.error = 0;
            //proof.unk1 = 0x00800000;
            proof.unk2 = 0x00;
            //proof.unk3 = 0x00;
            socket().send((char *)&proof, sizeof(proof));
        }

        ///- Set _authed to true!
        _authed = true;
    }
    else
    {
        char data[4]= { AUTH_LOGON_PROOF, WOW_FAIL_INCORRECT_PASSWORD, 3, 0};
        socket().send(data, sizeof(data));
        sLog.outBasic("[AuthChallenge] account %s tried to login with wrong password!",_login.c_str ());

        uint32 MaxWrongPassCount = sConfig.GetIntDefault("WrongPass.MaxCount", 0);
        if (MaxWrongPassCount > 0)
        {
            //Increment number of failed logins by one and if it reaches the limit temporarily ban that account or IP
            LoginDatabase.PExecute("UPDATE account SET failed_logins = failed_logins + 1 WHERE username = '%s'",_safelogin.c_str());

            if (QueryResult loginfail = LoginDatabase.PQuery("SELECT id, failed_logins FROM account WHERE username = '%s'", _safelogin.c_str()))
            {
                Field* fields = loginfail->Fetch();
                uint32 failed_logins = fields[1].GetUInt32();

                if (failed_logins >= MaxWrongPassCount)
                {
                    uint32 WrongPassBanTime = sConfig.GetIntDefault("WrongPass.BanTime", 600);
                    bool WrongPassBanType = sConfig.GetBoolDefault("WrongPass.BanType", false);

                    if (WrongPassBanType)
                    {
                        uint32 acc_id = fields[0].GetUInt32();
                        LoginDatabase.PExecute("INSERT INTO account_banned VALUES ('%u',UNIX_TIMESTAMP(),UNIX_TIMESTAMP()+'%u','Trinity realmd','Failed login autoban',1)",
                            acc_id, WrongPassBanTime);
                        sLog.outBasic("[AuthChallenge] account %s got banned for '%u' seconds because it failed to authenticate '%u' times",
                            _login.c_str(), WrongPassBanTime, failed_logins);
                    }
                    else
                    {
                        std::string current_ip(socket().get_remote_address().c_str());
                        LoginDatabase.escape_string(current_ip);
                        LoginDatabase.PExecute("INSERT INTO ip_banned VALUES ('%s',UNIX_TIMESTAMP(),UNIX_TIMESTAMP()+'%u','Trinity realmd','Failed login autoban')",
                            current_ip.c_str(), WrongPassBanTime);
                        sLog.outBasic("[AuthChallenge] IP %s got banned for '%u' seconds because account %s failed to authenticate '%u' times",
                            current_ip.c_str(), WrongPassBanTime, _login.c_str(), failed_logins);
                    }
                }
            }
        }
    }

    return true;
}

/// Reconnect Challenge command handler
bool AuthSocket::_HandleReconnectChallenge()
{
    sLog.outStaticDebug("Entering _HandleReconnectChallenge");
    if (socket().recv_len() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    socket().recv((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    sLog.outStaticDebug("[ReconnectChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (socket().recv_len() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    ///- Read the remaining of the packet
    socket().recv((char *)&buf[4], remaining);
    sLog.outStaticDebug("[ReconnectChallenge] got full packet, %#04x bytes", ch->size);
    sLog.outStaticDebug("[ReconnectChallenge] name(%d): '%s'", ch->I_len, ch->I);

    _login = (const char*)ch->I;
    _safelogin = _login;

    QueryResult result = LoginDatabase.PQuery ("SELECT sessionkey FROM account WHERE username = '%s'", _safelogin.c_str ());

    // Stop if the account is not found
    if (!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find his session key in the database.", _login.c_str());
        socket().shutdown();
        return false;
    }

    Field* fields = result->Fetch ();
    K.SetHexStr (fields[0].GetString ());

    ///- Sending response
    ByteBuffer pkt;
    pkt << (uint8)  AUTH_RECONNECT_CHALLENGE;
    pkt << (uint8)  0x00;
    _reconnectProof.SetRand(16 * 8);
    pkt.append(_reconnectProof.AsByteArray(16), 16);             // 16 bytes random
    pkt << (uint64) 0x00 << (uint64) 0x00;                  // 16 bytes zeros
    socket().send((char const*)pkt.contents(), pkt.size());
    return true;
}

/// Reconnect Proof command handler
bool AuthSocket::_HandleReconnectProof()
{
    sLog.outStaticDebug("Entering _HandleReconnectProof");
    ///- Read the packet
    sAuthReconnectProof_C lp;
    if (!socket().recv((char *)&lp, sizeof(sAuthReconnectProof_C)))
        return false;

    if (_login.empty() || !_reconnectProof.GetNumBytes() || !K.GetNumBytes())
        return false;

    BigNumber t1;
    t1.SetBinary(lp.R1, 16);

    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(_login);
    sha.UpdateBigNumbers(&t1, &_reconnectProof, &K, NULL);
    sha.Finalize();

    if (!memcmp(sha.GetDigest(), lp.R2, SHA_DIGEST_LENGTH))
    {
        ///- Sending response
        ByteBuffer pkt;
        pkt << (uint8)  AUTH_RECONNECT_PROOF;
        pkt << (uint8)  0x00;
        pkt << (uint16) 0x00;                               // 2 bytes zeros
        socket().send((char const*)pkt.contents(), pkt.size());

        ///- Set _authed to true!
        _authed = true;

        return true;
    }
    else
    {
        sLog.outError("[ERROR] user %s tried to login, but session invalid.", _login.c_str());
        socket().shutdown();
        return false;
    }
}

/// %Realm List command handler
bool AuthSocket::_HandleRealmList()
{
    sLog.outStaticDebug("Entering _HandleRealmList");
    if (socket().recv_len() < 5)
        return false;

    socket().recv_skip(5);

    ///- Get the user id (else close the connection)
    // No SQL injection (escaped user name)

    QueryResult result = LoginDatabase.PQuery("SELECT id FROM account WHERE username = '%s'",_safelogin.c_str());
    if (!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find him in the database.",_login.c_str());
        socket().shutdown();
        return false;
    }

    uint32 id = (*result)[0].GetUInt32();

    ///- Update realm list if need
    sRealmList->UpdateIfNeed();

    ///- Circle through realms in the RealmList and construct the return packet (including # of user characters in each realm)
    ByteBuffer pkt;

    size_t RealmListSize = 0;
    for (RealmList::RealmMap::const_iterator i = sRealmList->begin(); i != sRealmList->end(); ++i)
    {
        // don't work with realms which not compatible with the client
        if (_expversion & POST_BC_EXP_FLAG) // 2.4.3 and 3.1.3 cliens
        {
            if (i->second.gamebuild != _build)
                continue;
        }
        else if (_expversion & PRE_BC_EXP_FLAG) // 1.12.1 and 1.12.2 clients are compatible with eachother
        {
            if (!AuthHelper::IsPreBCAcceptedClientBuild(i->second.gamebuild))
                continue;
        }

        uint8 AmountOfCharacters;

        // No SQL injection. id of realm is controlled by the database.
        result = LoginDatabase.PQuery("SELECT numchars FROM realmcharacters WHERE realmid = '%d' AND acctid='%u'",i->second.m_ID,id);
        if (result)
        {
            Field *fields = result->Fetch();
            AmountOfCharacters = fields[0].GetUInt8();
        }
        else
            AmountOfCharacters = 0;

        uint8 lock = (i->second.allowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;

        pkt << i->second.icon;                             // realm type
        if ( _expversion & POST_BC_EXP_FLAG )//only 2.4.3 and 3.1.3 cliens
            pkt << lock;                                       // if 1, then realm locked
        pkt << i->second.color;                            // if 2, then realm is offline
        pkt << i->first;
        pkt << i->second.address;
        pkt << i->second.populationLevel;
        pkt << AmountOfCharacters;
        pkt << i->second.timezone;                          // realm category
        if ( _expversion & POST_BC_EXP_FLAG )//2.4.3 and 3.1.3 clients
            pkt << (uint8) 0x2C;                                // unk, may be realm number/id?
        else
            pkt << (uint8) 0x0; //1.12.1 and 1.12.2 clients

        ++RealmListSize;
    }

    if ( _expversion & POST_BC_EXP_FLAG )//2.4.3 and 3.1.3 cliens
    {
        pkt << (uint8) 0x10;
        pkt << (uint8) 0x00;
    }else{//1.12.1 and 1.12.2 clients
        pkt << (uint8) 0x00;
        pkt << (uint8) 0x02;
    }

    // make a ByteBuffer which stores the RealmList's size
    ByteBuffer RealmListSizeBuffer;
    RealmListSizeBuffer << (uint32)0;
    if (_expversion & POST_BC_EXP_FLAG) // only 2.4.3 and 3.1.3 cliens
        RealmListSizeBuffer << (uint16)RealmListSize;
    else
        RealmListSizeBuffer << (uint32)RealmListSize;

    ByteBuffer hdr;
    hdr << (uint8) REALM_LIST;
    hdr << (uint16)(pkt.size() + RealmListSizeBuffer.size());
    hdr.append(RealmListSizeBuffer);    // append RealmList's size buffer
    hdr.append(pkt);                    // append realms in the realmlist

    socket().send((char const*)hdr.contents(), hdr.size());

    return true;
}

/// Resume patch transfer
bool AuthSocket::_HandleXferResume()
{
    sLog.outStaticDebug("Entering _HandleXferResume");
    ///- Check packet length and patch existence
    if (socket().recv_len() < 9 || !pPatch)
    {
        sLog.outError("Error while resuming patch transfer (wrong packet)");
        return false;
    }

    ///- Launch a PatcherRunnable thread starting at given patch file offset
    uint64 start;
    socket().recv_skip(1);
    socket().recv((char*)&start,sizeof(start));
    fseek(pPatch, long(start), 0);

    ACE_Based::Thread u(new PatcherRunnable(this));
    return true;
}

/// Cancel patch transfer
bool AuthSocket::_HandleXferCancel()
{
    sLog.outStaticDebug("Entering _HandleXferCancel");

    ///- Close and delete the socket
    socket().recv_skip(1);                                         //clear input buffer

    socket().shutdown();

    return true;
}

/// Accept patch transfer
bool AuthSocket::_HandleXferAccept()
{
    sLog.outStaticDebug("Entering _HandleXferAccept");

    ///- Check packet length and patch existence
    if (!pPatch)
    {
        sLog.outError("Error while accepting patch transfer (wrong packet)");
        return false;
    }

    ///- Launch a PatcherRunnable thread, starting at the beginning of the patch file
    socket().recv_skip(1);                                         // clear input buffer
    fseek(pPatch, 0, 0);

    ACE_Based::Thread u(new PatcherRunnable(this));
    return true;
}

PatcherRunnable::PatcherRunnable(class AuthSocket * as)
{
    mySocket = as;
}

/// Send content of patch file to the client
void PatcherRunnable::run()
{
}

/// Preload MD5 hashes of existing patch files on server
#ifndef _WIN32
#include <dirent.h>
#include <errno.h>
void Patcher::LoadPatchesInfo()
{
    DIR * dirp;
    //int errno;
    struct dirent * dp;
    dirp = opendir("./patches/");
    if (!dirp)
        return;
    while (dirp)
    {
        errno = 0;
        if ((dp = readdir(dirp)) != NULL)
        {
            int l = strlen(dp->d_name);
            if (l < 8)
                continue;
            if (!memcmp(&dp->d_name[l-4],".mpq",4))
                LoadPatchMD5(dp->d_name);
        }
        else
        {
            if (errno != 0)
            {
                closedir(dirp);
                return;
            }
            break;
        }
    }

    if (dirp)
        closedir(dirp);
}

#else
void Patcher::LoadPatchesInfo()
{
    WIN32_FIND_DATA fil;
    HANDLE hFil=FindFirstFile("./patches/*.mpq", &fil);
    if (hFil == INVALID_HANDLE_VALUE)
        return;                                             // no patches were found

    do
    {
        LoadPatchMD5(fil.cFileName);
    }
    while(FindNextFile(hFil, &fil));
}
#endif

/// Calculate and store MD5 hash for a given patch file
void Patcher::LoadPatchMD5(char * szFileName)
{
    ///- Try to open the patch file
    std::string path = "./patches/";
    path += szFileName;
    FILE *pPatch = fopen(path.c_str(), "rb");
    sLog.outDebug("Loading patch info from %s\n", path.c_str());
    if (!pPatch)
    {
        sLog.outError("Error loading patch %s\n", path.c_str());
        return;
    }

    ///- Calculate the MD5 hash
    MD5_CTX ctx;
    MD5_Init(&ctx);
    uint8* buf = new uint8[512*1024];

    while (!feof(pPatch))
    {
        size_t read = fread(buf, 1, 512*1024, pPatch);
        MD5_Update(&ctx, buf, read);
    }
    delete [] buf;
    fclose(pPatch);

    ///- Store the result in the internal patch hash map
    _patches[path] = new PATCH_INFO;
    MD5_Final((uint8 *)&_patches[path]->md5, &ctx);
}

/// Get cached MD5 hash for a given patch file
bool Patcher::GetHash(char * pat, uint8 mymd5[16])
{
    for (Patches::iterator i = _patches.begin(); i != _patches.end(); ++i)
        if (!stricmp(pat, i->first.c_str()))
    {
        memcpy(mymd5, i->second->md5, 16);
        return true;
    }

    return false;
}

/// Launch the patch hashing mechanism on object creation
Patcher::Patcher()
{
    LoadPatchesInfo();
}

/// Empty and delete the patch map on termination
Patcher::~Patcher()
{
    for (Patches::iterator i = _patches.begin(); i != _patches.end(); ++i)
        delete i->second;
}
