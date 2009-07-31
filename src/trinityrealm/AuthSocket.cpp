/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
#include "Config/ConfigEnv.h"
#include "Log.h"
#include "RealmList.h"
#include "AuthSocket.h"
#include "AuthCodes.h"
#include <openssl/md5.h>
#include "Auth/Sha1.h"
//#include "Util.h" -- for commented utf8ToUpperOnlyLatin

extern RealmList m_realmList;

extern DatabaseType loginDatabase;

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
#if defined( __GNUC__ )
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

//typedef sAuthLogonChallenge_C sAuthReconnectChallenge_C;
/*
typedef struct
{
    uint8   cmd;
    uint8   error;
    uint8   unk2;
    uint8   B[32];
    uint8   g_len;
    uint8   g[1];
    uint8   N_len;
    uint8   N[32];
    uint8   s[32];
    uint8   unk3[16];
} sAuthLogonChallenge_S;
*/

typedef struct AUTH_LOGON_PROOF_C
{
    uint8   cmd;
    uint8   A[32];
    uint8   M1[20];
    uint8   crc_hash[20];
    uint8   number_of_keys;
    uint8   unk;                                            // Added in 1.12.x client branch
} sAuthLogonProof_C;
/*
typedef struct
{
    uint16  unk1;
    uint32  unk2;
    uint8   unk3[4];
    uint16  unk4[20];
}  sAuthLogonProofKey_C;
*/
typedef struct AUTH_LOGON_PROOF_S
{
    uint8   cmd;
    uint8   error;
    uint8   M2[20];
    uint32  unk1;
    uint32  unk2;
    uint16  unk3;
} sAuthLogonProof_S;

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
}XFER_INIT;

typedef struct XFER_DATA
{
    uint8 opcode;
    uint16 data_size;
    uint8 data[ChunkSize];
}XFER_DATA_STRUCT;

typedef struct AuthHandler
{
    eAuthCmd cmd;
    uint32 status;
    bool (AuthSocket::*handler)(void);
}AuthHandler;

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some paltform
#if defined( __GNUC__ )
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
}PATCH_INFO;

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
AuthSocket::AuthSocket(ISocketHandler &h) : TcpSocket(h)
{
    N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
    g.SetDword(7);
    _authed = false;
    pPatch = NULL;

    _accountSecurityLevel = SEC_PLAYER;
}

/// Close patch file descriptor before leaving
AuthSocket::~AuthSocket()
{
    ACE_Guard<ACE_Thread_Mutex> g(patcherLock);

    if(pPatch)
        fclose(pPatch);
}

/// Accept the connection and set the s random value for SRP6
void AuthSocket::OnAccept()
{
    sLog.outBasic("Accepting connection from '%s:%d'",
        GetRemoteAddress().c_str(), GetRemotePort());

    s.SetRand(s_BYTE_SIZE * 8);
}

/// Read the packet from the client
void AuthSocket::OnRead()
{
    ///- Read the packet
    TcpSocket::OnRead();
    uint8 _cmd;
    while (1)
    {
        if (!ibuf.GetLength())
            return;

        ///- Get the command out of it
        ibuf.SoftRead((char *)&_cmd, 1);                    // UQ1: No longer exists in new net code ???
        //ibuf.Read((char *)&_cmd, 1);
        /*char *command = (char *)malloc(1);

        ibuf.Read(command, 1);

        _cmd = (uint8)command;*/
        //      assert(0);
        size_t i;

        ///- Circle through known commands and call the correct command handler
        for (i=0;i<AUTH_TOTAL_COMMANDS; i++)
        {
            if ((uint8)table[i].cmd == _cmd &&
                (table[i].status == STATUS_CONNECTED ||
                (_authed && table[i].status == STATUS_AUTHED)))
            {
                DEBUG_LOG("[Auth] got data for cmd %u ibuf length %u", (uint32)_cmd, ibuf.GetLength());

                if (!(*this.*table[i].handler)())
                {
                    DEBUG_LOG("Command handler failed for cmd %u ibuf length %u", (uint32)_cmd, ibuf.GetLength());
                    return;
                }
                break;
            }
        }

        ///- Report unknown commands in the debug log
        if (i==AUTH_TOTAL_COMMANDS)
        {
            DEBUG_LOG("[Auth] got unknown packet %u", (uint32)_cmd);
            return;
        }
    }
}

/// Make the SRP6 calculation from hash in dB
void AuthSocket::_SetVSFields(const std::string& rI)
{
    BigNumber I;
    I.SetHexStr(rI.c_str());

    //In case of leading zeroes in the rI hash, restore them
    uint8 mDigest[SHA_DIGEST_LENGTH];
    memset(mDigest,0,SHA_DIGEST_LENGTH);
    if (I.GetNumBytes() <= SHA_DIGEST_LENGTH)
        memcpy(mDigest,I.AsByteArray(),I.GetNumBytes());

    std::reverse(mDigest,mDigest+SHA_DIGEST_LENGTH);

    Sha1Hash sha;
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
    loginDatabase.PExecute("UPDATE account SET v = '%s', s = '%s' WHERE username = '%s'",v_hex,s_hex, _safelogin.c_str() );
    OPENSSL_free((void*)v_hex);
    OPENSSL_free((void*)s_hex);
}

/// Logon Challenge command handler
bool AuthSocket::_HandleLogonChallenge()
{
    DEBUG_LOG("Entering _HandleLogonChallenge");
    if (ibuf.GetLength() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    ibuf.Read((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    DEBUG_LOG("[AuthChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (ibuf.GetLength() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    // BigEndian code, nop in little endian case
    // size already converted
    EndianConvert(*((uint32*)(&ch->gamename[0])));
    EndianConvert(ch->build);
    EndianConvert(*((uint32*)(&ch->platform[0])));
    EndianConvert(*((uint32*)(&ch->os[0])));
    EndianConvert(*((uint32*)(&ch->country[0])));
    EndianConvert(ch->timezone_bias);
    EndianConvert(ch->ip);

    ///- Read the remaining of the packet
    ibuf.Read((char *)&buf[4], remaining);
    DEBUG_LOG("[AuthChallenge] got full packet, %#04x bytes", ch->size);
    DEBUG_LOG("[AuthChallenge] name(%d): '%s'", ch->I_len, ch->I);

    ByteBuffer pkt;

    _login = (const char*)ch->I;
    _build = ch->build;

    ///- Normalize account name
    //utf8ToUpperOnlyLatin(_login); -- client already send account in expected form

    //Escape the user login to avoid further SQL injection
    //Memory will be freed on AuthSocket object destruction
    _safelogin=_login;
    loginDatabase.escape_string(_safelogin);

    pkt << (uint8) AUTH_LOGON_CHALLENGE;
    pkt << (uint8) 0x00;

    ///- Verify that this IP is not in the ip_banned table
    // No SQL injection possible (paste the IP address as passed by the socket)
    loginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate<=UNIX_TIMESTAMP() AND unbandate<>bandate");

    std::string address = GetRemoteAddress();
    loginDatabase.escape_string(address);
    QueryResult *result = loginDatabase.PQuery(  "SELECT * FROM ip_banned WHERE ip = '%s'",address.c_str());
    if(result)
    {
        pkt << (uint8)REALM_AUTH_ACCOUNT_BANNED;
        sLog.outBasic("[AuthChallenge] Banned ip %s tries to login!",GetRemoteAddress().c_str ());
        delete result;
    }
    else
    {
        ///- Get the account details from the account table
        // No SQL injection (escaped user name)

        result = loginDatabase.PQuery("SELECT sha_pass_hash,id,locked,last_ip,gmlevel FROM account WHERE username = '%s'",_safelogin.c_str ());
        if( result )
        {
            ///- If the IP is 'locked', check that the player comes indeed from the correct IP address
            bool locked = false;
            if((*result)[2].GetUInt8() == 1)            // if ip is locked
            {
                DEBUG_LOG("[AuthChallenge] Account '%s' is locked to IP - '%s'", _login.c_str(), (*result)[3].GetString());
                DEBUG_LOG("[AuthChallenge] Player address is '%s'", GetRemoteAddress().c_str());
                if ( strcmp((*result)[3].GetString(),GetRemoteAddress().c_str()) )
                {
                    DEBUG_LOG("[AuthChallenge] Account IP differs");
                    pkt << (uint8) REALM_AUTH_ACCOUNT_FREEZED;
                    locked=true;
                }
                else
                {
                    DEBUG_LOG("[AuthChallenge] Account IP matches");
                }
            }
            else
            {
                DEBUG_LOG("[AuthChallenge] Account '%s' is not locked to ip", _login.c_str());
            }

            if (!locked)
            {
                //set expired bans to inactive
                loginDatabase.Execute("UPDATE account_banned SET active = 0 WHERE unbandate<=UNIX_TIMESTAMP() AND unbandate<>bandate");
                ///- If the account is banned, reject the logon attempt
                QueryResult *banresult = loginDatabase.PQuery("SELECT bandate,unbandate FROM account_banned WHERE id = %u AND active = 1", (*result)[1].GetUInt32());
                if(banresult)
                {
                    if((*banresult)[0].GetUInt64() == (*banresult)[1].GetUInt64())
                    {
                        pkt << (uint8) REALM_AUTH_ACCOUNT_BANNED;
                        sLog.outBasic("[AuthChallenge] Banned account %s tries to login!",_login.c_str ());
                    }
                    else
                    {
                        pkt << (uint8) REALM_AUTH_ACCOUNT_FREEZED;
                        sLog.outBasic("[AuthChallenge] Temporarily banned account %s tries to login!",_login.c_str ());
                    }

                    delete banresult;
                }
                else
                {
                    ///- Get the password from the account table, upper it, and make the SRP6 calculation
                    std::string rI = (*result)[0].GetCppString();
                    _SetVSFields(rI);

                    b.SetRand(19 * 8);
                    BigNumber gmod=g.ModExp(b, N);
                    B = ((v * 3) + gmod) % N;

                    ASSERT(gmod.GetNumBytes() <= 32);

                    BigNumber unk3;
                    unk3.SetRand(16*8);

                    ///- Fill the response packet with the result
                    pkt << (uint8)REALM_AUTH_SUCCESS;

                    // B may be calculated < 32B so we force minnimal length to 32B
                    pkt.append(B.AsByteArray(32), 32);   // 32 bytes
                    pkt << (uint8)1;
                    pkt.append(g.AsByteArray(), 1);
                    pkt << (uint8)32;
                    pkt.append(N.AsByteArray(), 32);
                    pkt.append(s.AsByteArray(), s.GetNumBytes());   // 32 bytes
                    pkt.append(unk3.AsByteArray(), 16);
                    pkt << (uint8)0;                    // Added in 1.12.x client branch

                    uint8 secLevel = (*result)[4].GetUInt8();
                    _accountSecurityLevel = secLevel <= SEC_ADMINISTRATOR ? AccountTypes(secLevel) : SEC_ADMINISTRATOR;

                    _localizationName.resize(4);
                    for(int i = 0; i <4; ++i)
                        _localizationName[i] = ch->country[4-i-1];

                    sLog.outBasic("[AuthChallenge] account %s is using '%c%c%c%c' locale (%u)", _login.c_str (), ch->country[3],ch->country[2],ch->country[1],ch->country[0], GetLocaleByName(_localizationName));
                }
            }
            delete result;
        }
        else                                            //no account
        {
            pkt<< (uint8) REALM_AUTH_NO_MATCH;
        }
    }
    SendBuf((char const*)pkt.contents(), pkt.size());
    return true;
}

/// Logon Proof command handler
bool AuthSocket::_HandleLogonProof()
{
    DEBUG_LOG("Entering _HandleLogonProof");
    ///- Read the packet
    if (ibuf.GetLength() < sizeof(sAuthLogonProof_C))
        return false;
    sAuthLogonProof_C lp;
    ibuf.Read((char *)&lp, sizeof(sAuthLogonProof_C));

    ///- Check if the client has one of the expected version numbers
    bool valid_version=false;
    int accepted_versions[]=EXPECTED_TRINITY_CLIENT_BUILD;
    for(int i=0;accepted_versions[i];i++)
    {
        if(_build==accepted_versions[i])
        {
            valid_version=true;
            break;
        }
    }

    /// <ul><li> If the client has no valid version
    if(!valid_version)
    {
        ///- Check if we have the apropriate patch on the disk

        // 24 = len("./patches/65535enGB.mpq")+1
        char tmp[24];
        // No buffer overflow (fixed length of arguments)
        sprintf(tmp,"./patches/%d%s.mpq",_build, _localizationName.c_str());
        // This will be closed at the destruction of the AuthSocket (client deconnection)
        FILE *pFile=fopen(tmp,"rb");

        if(!pFile)
        {
            ByteBuffer pkt;
            pkt << (uint8) AUTH_LOGON_CHALLENGE;
            pkt << (uint8) 0x00;
            pkt << (uint8) REALM_AUTH_WRONG_BUILD_NUMBER;
            DEBUG_LOG("[AuthChallenge] %u is not a valid client version!", _build);
            DEBUG_LOG("[AuthChallenge] Patch %s not found",tmp);
            SendBuf((char const*)pkt.contents(), pkt.size());
            return true;
        }
        else                                                // have patch
        {
            pPatch=pFile;
            XFER_INIT xferh;

            ///- Get the MD5 hash of the patch file (get it from preloaded Patcher cache or calculate it)
            if(PatchesCache.GetHash(tmp,(uint8*)&xferh.md5))
            {
                DEBUG_LOG("\n[AuthChallenge] Found precached patch info for patch %s",tmp);
            }
            else
            {                                               //calculate patch md5
                printf("\n[AuthChallenge] Patch info for %s was not cached.",tmp);
                PatchesCache.LoadPatchMD5(tmp);
                PatchesCache.GetHash(tmp,(uint8*)&xferh.md5);
            }

            ///- Send a packet to the client with the file length and MD5 hash
            uint8 data[2]={AUTH_LOGON_PROOF,REALM_AUTH_UPDATE_CLIENT};
            SendBuf((const char*)data,sizeof(data));

            memcpy(&xferh,"0\x05Patch",7);
            xferh.cmd=XFER_INITIATE;
            fseek(pPatch,0,SEEK_END);
            xferh.file_size=ftell(pPatch);

            SendBuf((const char*)&xferh,sizeof(xferh));
            return true;
        }
    }
    /// </ul>

    ///- Continue the SRP6 calculation based on data received from the client
    BigNumber A;
    A.SetBinary(lp.A, 32);

    Sha1Hash sha;
    sha.UpdateBigNumbers(&A, &B, NULL);
    sha.Finalize();
    BigNumber u;
    u.SetBinary(sha.GetDigest(), 20);
    BigNumber S = (A * (v.ModExp(u, N))).ModExp(b, N);

    uint8 t[32];
    uint8 t1[16];
    uint8 vK[40];
    memcpy(t, S.AsByteArray(), 32);
    for (int i = 0; i < 16; i++)
    {
        t1[i] = t[i*2];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; i++)
    {
        vK[i*2] = sha.GetDigest()[i];
    }
    for (int i = 0; i < 16; i++)
    {
        t1[i] = t[i*2+1];
    }
    sha.Initialize();
    sha.UpdateData(t1, 16);
    sha.Finalize();
    for (int i = 0; i < 20; i++)
    {
        vK[i*2+1] = sha.GetDigest()[i];
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
    for (int i = 0; i < 20; i++)
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
        loginDatabase.PExecute("UPDATE account SET sessionkey = '%s', last_ip = '%s', last_login = NOW(), locale = '%u', failed_logins = 0 WHERE username = '%s'", K_hex, GetRemoteAddress().c_str(), GetLocaleByName(_localizationName), _safelogin.c_str() );
        OPENSSL_free((void*)K_hex);

        ///- Finish SRP6 and send the final result to the client
        sha.Initialize();
        sha.UpdateBigNumbers(&A, &M, &K, NULL);
        sha.Finalize();

        sAuthLogonProof_S proof;
        memcpy(proof.M2, sha.GetDigest(), 20);
        proof.cmd = AUTH_LOGON_PROOF;
        proof.error = 0;
        proof.unk1 = 0x00800000;
        proof.unk2 = 0x00;
        proof.unk3 = 0x00;

        SendBuf((char *)&proof, sizeof(proof));

        ///- Set _authed to true!
        _authed = true;
    }
    else
    {
        char data[4]={AUTH_LOGON_PROOF,REALM_AUTH_NO_MATCH,3,0};
        SendBuf(data,sizeof(data));
        sLog.outBasic("[AuthChallenge] account %s tried to login with wrong password!",_login.c_str ());

        uint32 MaxWrongPassCount = sConfig.GetIntDefault("WrongPass.MaxCount", 0);
        if(MaxWrongPassCount > 0)
        {
            //Increment number of failed logins by one and if it reaches the limit temporarily ban that account or IP
            loginDatabase.PExecute("UPDATE account SET failed_logins = failed_logins + 1 WHERE username = '%s'",_safelogin.c_str());

            if(QueryResult *loginfail = loginDatabase.PQuery("SELECT id, failed_logins FROM account WHERE username = '%s'", _safelogin.c_str()))
            {
                Field* fields = loginfail->Fetch();
                uint32 failed_logins = fields[1].GetUInt32();

                if( failed_logins >= MaxWrongPassCount )
                {
                    uint32 WrongPassBanTime = sConfig.GetIntDefault("WrongPass.BanTime", 600);
                    bool WrongPassBanType = sConfig.GetBoolDefault("WrongPass.BanType", false);

                    if(WrongPassBanType)
                    {
                        uint32 acc_id = fields[0].GetUInt32();
                        loginDatabase.PExecute("INSERT INTO account_banned VALUES ('%u',UNIX_TIMESTAMP(),UNIX_TIMESTAMP()+'%u','Trinity realmd','Failed login autoban',1)",
                            acc_id, WrongPassBanTime);
                        sLog.outBasic("[AuthChallenge] account %s got banned for '%u' seconds because it failed to authenticate '%u' times",
                            _login.c_str(), WrongPassBanTime, failed_logins);
                    }
                    else
                    {
                        std::string current_ip = GetRemoteAddress();
                        loginDatabase.escape_string(current_ip);
                        loginDatabase.PExecute("INSERT INTO ip_banned VALUES ('%s',UNIX_TIMESTAMP(),UNIX_TIMESTAMP()+'%u','Trinity realmd','Failed login autoban')",
                            current_ip.c_str(), WrongPassBanTime);
                        sLog.outBasic("[AuthChallenge] IP %s got banned for '%u' seconds because account %s failed to authenticate '%u' times",
                            current_ip.c_str(), WrongPassBanTime, _login.c_str(), failed_logins);
                    }
                }
                delete loginfail;
            }
        }
    }
    return true;
}

/// Reconnect Challenge command handler
bool AuthSocket::_HandleReconnectChallenge()
{
    DEBUG_LOG("Entering _HandleReconnectChallenge");
    if (ibuf.GetLength() < sizeof(sAuthLogonChallenge_C))
        return false;

    ///- Read the first 4 bytes (header) to get the length of the remaining of the packet
    std::vector<uint8> buf;
    buf.resize(4);

    ibuf.Read((char *)&buf[0], 4);

    EndianConvert(*((uint16*)(buf[0])));
    uint16 remaining = ((sAuthLogonChallenge_C *)&buf[0])->size;
    DEBUG_LOG("[ReconnectChallenge] got header, body is %#04x bytes", remaining);

    if ((remaining < sizeof(sAuthLogonChallenge_C) - buf.size()) || (ibuf.GetLength() < remaining))
        return false;

    //No big fear of memory outage (size is int16, i.e. < 65536)
    buf.resize(remaining + buf.size() + 1);
    buf[buf.size() - 1] = 0;
    sAuthLogonChallenge_C *ch = (sAuthLogonChallenge_C*)&buf[0];

    ///- Read the remaining of the packet
    ibuf.Read((char *)&buf[4], remaining);
    DEBUG_LOG("[ReconnectChallenge] got full packet, %#04x bytes", ch->size);
    DEBUG_LOG("[ReconnectChallenge] name(%d): '%s'", ch->I_len, ch->I);

    _login = (const char*)ch->I;
    _safelogin = _login;

    QueryResult *result = loginDatabase.PQuery ("SELECT sessionkey FROM account WHERE username = '%s'", _safelogin.c_str ());

    // Stop if the account is not found
    if (!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find his session key in the database.", _login.c_str());
        SetCloseAndDelete();
        return false;
    }

    Field* fields = result->Fetch ();
    K.SetHexStr (fields[0].GetString ());
    delete result;

    ///- Sending response
    ByteBuffer pkt;
    pkt << (uint8)  AUTH_RECONNECT_CHALLENGE;
    pkt << (uint8)  0x00;
    _reconnectProof.SetRand(16*8);
    pkt.append(_reconnectProof.AsByteBuffer());             // 16 bytes random
    pkt << (uint64) 0x00 << (uint64) 0x00;                  // 16 bytes zeros
    SendBuf((char const*)pkt.contents(), pkt.size());
    return true;
}

/// Reconnect Proof command handler
bool AuthSocket::_HandleReconnectProof()
{
    DEBUG_LOG("Entering _HandleReconnectProof");
    ///- Read the packet
    if (ibuf.GetLength() < sizeof(sAuthReconnectProof_C))
        return false;
    if (_login.empty() || !_reconnectProof.GetNumBytes() || !K.GetNumBytes())
        return false;
    sAuthReconnectProof_C lp;
    ibuf.Read((char *)&lp, sizeof(sAuthReconnectProof_C));

    BigNumber t1;
    t1.SetBinary(lp.R1, 16);

    Sha1Hash sha;
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
        SendBuf((char const*)pkt.contents(), pkt.size());

        ///- Set _authed to true!
        _authed = true;

        return true;
    }
    else
    {
        sLog.outError("[ERROR] user %s tried to login, but session invalid.", _login.c_str());
        SetCloseAndDelete();
        return false;
    }
}

/// %Realm List command handler
bool AuthSocket::_HandleRealmList()
{
    DEBUG_LOG("Entering _HandleRealmList");
    if (ibuf.GetLength() < 5)
        return false;

    ibuf.Remove(5);

    ///- Get the user id (else close the connection)
    // No SQL injection (escaped user name)

    QueryResult *result = loginDatabase.PQuery("SELECT id,sha_pass_hash FROM account WHERE username = '%s'",_safelogin.c_str());
    if(!result)
    {
        sLog.outError("[ERROR] user %s tried to login and we cannot find him in the database.",_login.c_str());
        SetCloseAndDelete();
        return false;
    }

    uint32 id = (*result)[0].GetUInt32();
    std::string rI = (*result)[1].GetCppString();
    delete result;

    ///- Update realm list if need
    m_realmList.UpdateIfNeed();

    ///- Circle through realms in the RealmList and construct the return packet (including # of user characters in each realm)
    ByteBuffer pkt;
    pkt << (uint32) 0;
    pkt << (uint16) m_realmList.size();
    RealmList::RealmMap::const_iterator i;
    for( i = m_realmList.begin(); i != m_realmList.end(); i++ )
    {
        uint8 AmountOfCharacters;

        // No SQL injection. id of realm is controlled by the database.
        result = loginDatabase.PQuery( "SELECT numchars FROM realmcharacters WHERE realmid = '%d' AND acctid='%u'",i->second.m_ID,id);
        if( result )
        {
            Field *fields = result->Fetch();
            AmountOfCharacters = fields[0].GetUInt8();
            delete result;
        }
        else
            AmountOfCharacters = 0;

        uint8 lock = (i->second.allowedSecurityLevel > _accountSecurityLevel) ? 1 : 0;

        pkt << i->second.icon;                             // realm type
        pkt << lock;                                       // if 1, then realm locked
        pkt << i->second.color;                            // if 2, then realm is offline
        pkt << i->first;
        pkt << i->second.address;
        pkt << i->second.populationLevel;
        pkt << AmountOfCharacters;
        pkt << i->second.timezone;                          // realm category
        pkt << (uint8) 0x2C;                                // unk, may be realm number/id?
    }
    pkt << (uint8) 0x10;
    pkt << (uint8) 0x00;

    ByteBuffer hdr;
    hdr << (uint8) REALM_LIST;
    hdr << (uint16)pkt.size();
    hdr.append(pkt);

    SendBuf((char const*)hdr.contents(), hdr.size());

    // Set check field before possible relogin to realm
    _SetVSFields(rI);
    return true;
}

/// Resume patch transfer
bool AuthSocket::_HandleXferResume()
{
    DEBUG_LOG("Entering _HandleXferResume");
    ///- Check packet length and patch existence
    if (ibuf.GetLength()<9 || !pPatch)
    {
        sLog.outError("Error while resuming patch transfer (wrong packet)");
        return false;
    }

    ///- Launch a PatcherRunnable thread starting at given patch file offset
    uint64 start;
    ibuf.Remove(1);
    ibuf.Read((char*)&start,sizeof(start));
    fseek(pPatch,start,0);

    ACE_Based::Thread u(*new PatcherRunnable(this));
    return true;
}

/// Cancel patch transfer
bool AuthSocket::_HandleXferCancel()
{
    DEBUG_LOG("Entering _HandleXferCancel");

    ///- Close and delete the socket
    ibuf.Remove(1);                                         //clear input buffer

    SetCloseAndDelete();

    return true;
}

/// Accept patch transfer
bool AuthSocket::_HandleXferAccept()
{
    DEBUG_LOG("Entering _HandleXferAccept");

    ///- Check packet length and patch existence
    if (!pPatch)
    {
        sLog.outError("Error while accepting patch transfer (wrong packet)");
        return false;
    }

    ///- Launch a PatcherRunnable thread, starting at the begining of the patch file
    ibuf.Remove(1);                                         //clear input buffer
    fseek(pPatch,0,0);

    ACE_Based::Thread u(*new PatcherRunnable(this));
    return true;
}

/// Check if there is lag on the connection to the client
bool AuthSocket::IsLag()
{
    return (TCP_BUFSIZE_READ-GetOutputLength()< 2*ChunkSize);
}

PatcherRunnable::PatcherRunnable(class AuthSocket * as)
{
    mySocket=as;
}

/// Send content of patch file to the client
void PatcherRunnable::run()
{
    ACE_Guard<ACE_Thread_Mutex> g(mySocket->patcherLock);

    XFER_DATA_STRUCT xfdata;
    xfdata.opcode = XFER_DATA;

    while(!feof(mySocket->pPatch) && mySocket->Ready())
    {
        ///- Wait until output buffer is reasonably empty
        while(mySocket->Ready() && mySocket->IsLag())
        {
        ACE_Based::Thread::Sleep(1);
        }
        ///- And send content of the patch file to the client
        xfdata.data_size=fread(&xfdata.data,1,ChunkSize,mySocket->pPatch);
        mySocket->SendBuf((const char*)&xfdata,xfdata.data_size +(sizeof(XFER_DATA_STRUCT)-ChunkSize));
    }
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
    if(!dirp)
        return;
    while (dirp)
    {
        errno = 0;
        if ((dp = readdir(dirp)) != NULL)
        {
            int l=strlen(dp->d_name);
            if(l<8)continue;
            if(!memcmp(&dp->d_name[l-4],".mpq",4))
                LoadPatchMD5(dp->d_name);
        }
        else
        {
            if(errno != 0)
            {
                closedir(dirp);
                return;
            }
            break;
        }
    }

    if(dirp)
        closedir(dirp);
}

#else
void Patcher::LoadPatchesInfo()
{
    WIN32_FIND_DATA fil;
    HANDLE hFil=FindFirstFile("./patches/*.mpq",&fil);
    if(hFil==INVALID_HANDLE_VALUE)
        return;                                             //no patches were found

    do
    {
        LoadPatchMD5(fil.cFileName);
    }
    while(FindNextFile(hFil,&fil));
}
#endif

/// Calculate and store MD5 hash for a given patch file
void Patcher::LoadPatchMD5(char * szFileName)
{
    ///- Try to open the patch file
    std::string path = "./patches/";
    path += szFileName;
    FILE * pPatch=fopen(path.c_str(),"rb");
    sLog.outDebug("Loading patch info from %s\n",path.c_str());
    if(!pPatch)
    {
        sLog.outError("Error loading patch %s\n",path.c_str());
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
    MD5_Final((uint8 *)&_patches[path]->md5 , &ctx);
}

/// Get cached MD5 hash for a given patch file
bool Patcher::GetHash(char * pat,uint8 mymd5[16])
{
    for( Patches::iterator i = _patches.begin(); i != _patches.end(); i++ )
        if(!stricmp(pat,i->first.c_str () ))
    {
        memcpy(mymd5,i->second->md5,16);
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
    for(Patches::iterator i = _patches.begin(); i != _patches.end(); i++ )
        delete i->second;
}
