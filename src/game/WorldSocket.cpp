/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
    \ingroup u2w
*/

#include "Common.h"
#include "Log.h"
#include "Opcodes.h"
#include "Database/DatabaseEnv.h"
#include "Auth/Sha1.h"
#include "WorldPacket.h"
#include "WorldSocket.h"
#include "WorldSession.h"
#include "World.h"
#include "WorldSocketMgr.h"
#include "Policies/SingletonImp.h"
#include "WorldLog.h"
#include "AddonHandler.h"
#include "sockets/Utility.h"
#include "Util.h"

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push,N), also any gcc version not support it at some platform
#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

/// Client Packet Header
struct ClientPktHeader
{
    uint16 size;
    uint32 cmd;
};

/// Server Packet Header
struct ServerPktHeader
{
    uint16 size;
    uint16 cmd;
};

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some platform
#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif

#define SOCKET_CHECK_PACKET_SIZE(P,S) if((P).size() < (S)) return SizeError((P),(S));

/// WorldSocket construction and initialization.
WorldSocket::WorldSocket(ISocketHandler &sh): TcpSocket(sh), _cmd(0), _remaining(0), _session(NULL)
{
    _seed = static_cast<uint32>(rand32());
    m_LastPingMSTime = 0;                                   // first time it will counted as overspeed maybe, but this is not important
    m_OverSpeedPings = 0;

    if (sWorld.getConfig(CONFIG_TCP_NO_DELAY))
        SetTcpNodelay(true);
}

/// WorldSocket destructor
WorldSocket::~WorldSocket()
{
    if(_session)
        _session->SetSocket(0);

    WorldPacket *packet;

    ///- Go through the to-be-sent queue and delete remaining packets
    while(!_sendQueue.empty())
    {
        packet = _sendQueue.next();
        delete packet;
    }
}

/// Copy the packet to the to-be-sent queue
void WorldSocket::SendPacket(WorldPacket const* packet)
{
    WorldPacket *pck = new WorldPacket(*packet);
    ASSERT(pck);
    _sendQueue.add(pck);
}

/// On client connection
void WorldSocket::OnAccept()
{
    ///- Add the current socket to the list of sockets to be managed (WorldSocketMgr)
    sWorldSocketMgr.AddSocket(this);
    Utility::ResolveLocal();

    ///- Send a AUTH_CHALLENGE packet
    WorldPacket packet( SMSG_AUTH_CHALLENGE, 4 );
    packet << _seed;

    SendPacket(&packet);
}

/// Read the client transmitted data
void WorldSocket::OnRead()
{
    TcpSocket::OnRead();

    while(1)
    {
        ///- Read the packet header and decipher it (if needed)
        if (!_remaining)
        {
            if (ibuf.GetLength() < 6)
                break;

            ClientPktHeader hdr;

            ibuf.Read((char *)&hdr, 6);
            _crypt.DecryptRecv((uint8 *)&hdr, 6);

            _remaining = ntohs(hdr.size) - 4;
            _cmd = hdr.cmd;
        }

        if (ibuf.GetLength() < _remaining)
            break;

        ///- Read the remaining of the packet
        WorldPacket packet((uint16)_cmd, _remaining);

        packet.resize(_remaining);
        if(_remaining) ibuf.Read((char*)packet.contents(), _remaining);
        _remaining = 0;

        ///- If log of world packets is enable, log the incoming packet
        if( sWorldLog.LogWorld() )
        {
            sWorldLog.Log("CLIENT:\nSOCKET: %u\nLENGTH: %u\nOPCODE: %s (0x%.4X)\nDATA:\n",
                (uint32)GetSocket(),
                packet.size(),
                LookupOpcodeName(packet.GetOpcode()),
                packet.GetOpcode());

            uint32 p = 0;
            while (p < packet.size())
            {
                for (uint32 j = 0; j < 16 && p < packet.size(); j++)
                    sWorldLog.Log("%.2X ", packet[p++]);
                sWorldLog.Log("\n");
            }
            sWorldLog.Log("\n\n");
        }

        ///- If the packet is PING, KEEP_ALIVE or AUTH_SESSION, handle immediately
        switch (_cmd)
        {
            case CMSG_KEEP_ALIVE:
                break;                                      // just ignore, network connectivity timeout preventing
            case CMSG_PING:
            {
                _HandlePing(packet);
                break;
            }
            case CMSG_AUTH_SESSION:
            {
                _HandleAuthSession(packet);
                break;
            }
            default:
            {
                ///- Else, put it in the world session queue for this user (need to be already authenticated)
                if (_session)
                    _session->QueuePacket(packet);
                else
                    sLog.outDetail("Received out of place packet with cmdid 0x%.4X", _cmd);
                break;
            }
        }
    }
}

/// On socket closing
void WorldSocket::CloseSocket()
{
    ///- Set CloseAndDelete flag for TcpSocket class
    SetCloseAndDelete(true);

    ///- Set _session to NULL. Prevent crashes
    _session = NULL;
}

/// On socket deleting
void WorldSocket::OnDelete()
{
    ///- Stop sending remaining data through this socket
    if (_session)
    {
        _session->SetSocket(NULL);
        // Session deleted from World session list at socket==0, This is only back reference from socket to session.
        _session = NULL;
    }

    ///- Remove the socket from the WorldSocketMgr list
    sWorldSocketMgr.RemoveSocket(this);

    ///- Removes socket from player queue
    sWorld.RemoveQueuedPlayer(this);
}

/// Handle the client authentication packet
void WorldSocket::_HandleAuthSession(WorldPacket& recvPacket)
{
    uint8 digest[20];
    uint32 clientSeed;
    uint32 unk2;
    uint32 BuiltNumberClient;
    uint32 id, security;
    bool tbc = false;
    std::string account;
    Sha1Hash sha1;
    BigNumber v, s, g, N, x, I;
    WorldPacket packet, SendAddonPacked;

    BigNumber K;

    SOCKET_CHECK_PACKET_SIZE(recvPacket,4+4+1+4+20);

    ///- Read the content of the packet
    recvPacket >> BuiltNumberClient;                        // for now no use
    recvPacket >> unk2;
    recvPacket >> account;

    // recheck size
    SOCKET_CHECK_PACKET_SIZE(recvPacket,4+4+(account.size()+1)+4+20);

    recvPacket >> clientSeed;
    recvPacket.read(digest, 20);

    sLog.outDebug("Auth: client %u, unk2 %u, account %s, clientseed %u", BuiltNumberClient, unk2, account.c_str(), clientSeed);

    ///- Normalize account name
    //utf8ToUpperOnlyLatin(account); -- client already send account in expected form

    ///- Get the account information from the realmd database
    std::string safe_account = account;                     // Duplicate, else will screw the SHA hash verification below
    loginDatabase.escape_string(safe_account);
    //No SQL injection, username escaped.
    //                                                 0   1        2           3        4       5              6  7  8    9         10
    QueryResult *result = loginDatabase.PQuery("SELECT id, gmlevel, sessionkey, last_ip, locked, sha_pass_hash, v, s, tbc, mutetime, locale FROM account WHERE username = '%s'", safe_account.c_str());

    ///- Stop if the account is not found
    if ( !result )
    {
        packet.Initialize( SMSG_AUTH_RESPONSE, 1 );
        packet << uint8( AUTH_UNKNOWN_ACCOUNT );
        SendPacket( &packet );
        sLog.outDetail( "SOCKET: Sent Auth Response (unknown account)." );
        return;
    }

    Field* fields = result->Fetch();

    tbc = fields[8].GetUInt8() && sWorld.getConfig(CONFIG_EXPANSION) > 0;

    N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
    g.SetDword(7);
    I.SetHexStr(fields[5].GetString());

    //In case of leading zeros in the I hash, restore them
    uint8 mDigest[SHA_DIGEST_LENGTH];
    memset(mDigest,0,SHA_DIGEST_LENGTH);
    if (I.GetNumBytes() <= SHA_DIGEST_LENGTH)
        memcpy(mDigest,I.AsByteArray(),I.GetNumBytes());

    std::reverse(mDigest,mDigest+SHA_DIGEST_LENGTH);

    s.SetHexStr(fields[7].GetString());
    sha1.UpdateData(s.AsByteArray(), s.GetNumBytes());
    sha1.UpdateData(mDigest, SHA_DIGEST_LENGTH);
    sha1.Finalize();
    x.SetBinary(sha1.GetDigest(), sha1.GetLength());
    v = g.ModExp(x, N);

    const char* sStr = s.AsHexStr();                        //Must be freed by OPENSSL_free()
    const char* vStr = v.AsHexStr();                        //Must be freed by OPENSSL_free()
    const char* vold = fields[6].GetString();
    sLog.outDebug("SOCKET: (s,v) check s: %s v_old: %s v_new: %s", sStr, vold, vStr );
    loginDatabase.PExecute("UPDATE account SET v = '0', s = '0' WHERE username = '%s'", safe_account.c_str());
    if ( !vold || strcmp( vStr, vold ) )
    {
        packet.Initialize( SMSG_AUTH_RESPONSE, 1 );
        packet << uint8( AUTH_UNKNOWN_ACCOUNT );
        SendPacket( &packet );
        sLog.outDetail( "SOCKET: User not logged.");
        delete result;
        OPENSSL_free((void*)sStr);
        OPENSSL_free((void*)vStr);
        return;
    }
    OPENSSL_free((void*)sStr);
    OPENSSL_free((void*)vStr);

    ///- Re-check ip locking (same check as in realmd).
    if(fields[4].GetUInt8() == 1)                           // if ip is locked
    {
        if ( strcmp(fields[3].GetString(),GetRemoteAddress().c_str()) )
        {
            packet.Initialize( SMSG_AUTH_RESPONSE, 1 );
            packet << uint8( AUTH_FAILED );
            SendPacket( &packet );

            sLog.outDetail( "SOCKET: Sent Auth Response (Account IP differs)." );
            delete result;
            return;
        }
    }

    id = fields[0].GetUInt32();
    security = fields[1].GetUInt16();
    K.SetHexStr(fields[2].GetString());
    time_t mutetime = time_t(fields[9].GetUInt64());

    LocaleConstant locale = LocaleConstant(fields[10].GetUInt8());
    if (locale>=MAX_LOCALE)
        locale=LOCALE_enUS;

    delete result;

    ///- Re-check account ban (same check as in realmd) /// TO DO: why on earth do 2 checks for same thing?
    QueryResult *banresult = loginDatabase.PQuery("SELECT bandate,unbandate FROM account_banned WHERE id = '%u' AND active = 1", id);
    if(banresult)                                           // if account banned
    {
        packet.Initialize( SMSG_AUTH_RESPONSE, 1 );
        packet << uint8( AUTH_BANNED );
        SendPacket( &packet );

        sLog.outDetail( "SOCKET: Sent Auth Response (Account banned)." );
        delete banresult;
        return;
    }

    ///- Check locked state for server
    AccountTypes allowedAccountType = sWorld.GetPlayerSecurityLimit();
    if( allowedAccountType > SEC_PLAYER && security < allowedAccountType)
    {
        WorldPacket Packet(SMSG_AUTH_RESPONSE, 1);
        Packet << uint8(AUTH_UNAVAILABLE);
        SendPacket(&Packet);
        return;
    }

    ///- kick already loaded player with same account (if any) and remove session
    ///- if player is in loading and want to load again, return
    if(!sWorld.RemoveSession(id))
    {
        return;
    }

    ///- Check that Key and account name are the same on client and server
    Sha1Hash sha;

    uint32 t = 0;
    uint32 seed = _seed;

    sha.UpdateData(account);
    sha.UpdateData((uint8 *)&t, 4);
    sha.UpdateData((uint8 *)&clientSeed, 4);
    sha.UpdateData((uint8 *)&seed, 4);
    sha.UpdateBigNumbers(&K, NULL);
    sha.Finalize();

    if (memcmp(sha.GetDigest(), digest, 20))
    {
        packet.Initialize( SMSG_AUTH_RESPONSE, 1 );
        packet << uint8( AUTH_FAILED );
        SendPacket( &packet );

        sLog.outDetail( "SOCKET: Sent Auth Response (authentication failed)." );
        return;
    }

    ///- Initialize the encryption with the Key
    _crypt.SetKey(&K);
    _crypt.Init();

    ///- Send 'Auth is ok'
    packet.Initialize( SMSG_AUTH_RESPONSE, 1+4+1+4+1 );
    packet << uint8( AUTH_OK );
    packet << uint32(0);                                    // unknown random value...
    packet << uint8(0);                                     // can be 0 and 2
    packet << uint32(0);                                    // const 0
    packet << uint8(tbc ? 1 : 0);                           // 0 - normal, 1 - TBC, must be set in database manually for each account
    SendPacket(&packet);

    ///- Create a new WorldSession for the player and add it to the World
    _session = new WorldSession(id, this,security,tbc,mutetime,locale);
    sWorld.AddSession(_session);

    if(sLog.IsOutDebug())                                   // optimize disabled debug output
    {
        sLog.outDebug( "SOCKET: Client '%s' authenticated successfully.", account.c_str() );
        sLog.outDebug( "Account: '%s' Logged in from IP %s.", account.c_str(), GetRemoteAddress().c_str());
    }

    ///- Update the last_ip in the database
    //No SQL injection, username escaped.
    std::string address = GetRemoteAddress();
    loginDatabase.escape_string(address);
    loginDatabase.PExecute("UPDATE account SET last_ip = '%s' WHERE username = '%s'",address.c_str(), safe_account.c_str());

    // do small delay (10ms) at accepting successful authed connection to prevent dropping packets by client
    // don't must harm anyone (let login ~100 accounts in 1 sec ;) )
    #ifdef WIN32
    Sleep(10);
    #else
    ZThread::Thread::sleep(10);
    #endif

    ///- Check that we do not exceed the maximum number of online players in the realm
    uint32 Sessions  = sWorld.GetActiveAndQueuedSessionCount();
    uint32 pLimit    = sWorld.GetPlayerAmountLimit();
    uint32 QueueSize = sWorld.GetQueueSize();               //number of players in the queue
    bool   inQueue   = false;
    --Sessions;                                             //so we don't count the user trying to login as a session and queue the socket that we are using

    if( pLimit >  0 && Sessions >= pLimit && security == SEC_PLAYER )
    {
        sWorld.AddQueuedPlayer(this);
        SendAuthWaitQue(sWorld.GetQueuePos(this));
        sWorld.UpdateMaxSessionCounters();
        sLog.outDetail( "PlayerQueue: %s is in Queue Position (%u).",safe_account.c_str(),++QueueSize);
        inQueue = true;
    }

    ///- Create and send the Addon packet
    if(sAddOnHandler.BuildAddonPacket(&recvPacket, &SendAddonPacked))
        SendPacket(&SendAddonPacked);

    if(inQueue)
        return;

    sWorld.UpdateMaxSessionCounters();

    // Updates the population
    if (pLimit > 0)
    {
        float popu = sWorld.GetActiveSessionCount();        //updated number of users on the server
        popu /= pLimit;
        popu *= 2;
        loginDatabase.PExecute("UPDATE realmlist SET population = '%f' WHERE id = '%d'",popu,realmID);
        sLog.outDetail( "Server Population (%f).",popu);
    }

    return;
}

/// Handle the Ping packet
void WorldSocket::_HandlePing(WorldPacket& recvPacket)
{
    uint32 ping;
    uint32 latency;

    CHECK_PACKET_SIZE(recvPacket,8);

    ///- Get the ping packet content
    recvPacket >> ping;
    recvPacket >> latency;

    if (_session )
        _session->SetLatency(latency);

    ///- check ping speed for players
    if(_session && _session->GetSecurity() == SEC_PLAYER)
    {
        uint32 cur_mstime = getMSTime();

        // can overflow and start from 0
        uint32 diff_mstime = getMSTimeDiff(m_LastPingMSTime,cur_mstime);
        m_LastPingMSTime = cur_mstime;
        if(diff_mstime < 27000)                             // should be 30000 (=30 secs), add little tolerance
        {
            ++m_OverSpeedPings;

            uint32 max_count = sWorld.getConfig(CONFIG_MAX_OVERSPEED_PINGS);
            if(max_count && m_OverSpeedPings > max_count)
            {
                sLog.outBasic("Player %s from account id %u kicked for overspeed ping packets from client (non-playable connection lags or cheating) ",_session->GetPlayerName(),_session->GetAccountId());
                _session->KickPlayer();
                return;
            }
        }
        else
            m_OverSpeedPings = 0;

    }

    ///- And put the pong answer in the to-be-sent queue
    WorldPacket packet( SMSG_PONG, 4 );
    packet << ping;
    SendPacket(&packet);

    return;
}

/// Handle the update order for the socket
void WorldSocket::SendSinglePacket()
{
    WorldPacket *packet;
    ServerPktHeader hdr;

    ///- If we have packet to send
    if (!_sendQueue.empty())
    {
        packet = _sendQueue.next();

        hdr.size = ntohs((uint16)packet->size() + 2);
        hdr.cmd = packet->GetOpcode();

        if( sWorldLog.LogWorld() )
        {
            sWorldLog.Log("SERVER:\nSOCKET: %u\nLENGTH: %u\nOPCODE: %s (0x%.4X)\nDATA:\n",
                (uint32)GetSocket(),
                packet->size(),
                LookupOpcodeName(packet->GetOpcode()),
                packet->GetOpcode());

            uint32 p = 0;
            while (p < packet->size())
            {
                for (uint32 j = 0; j < 16 && p < packet->size(); j++)
                    sWorldLog.Log("%.2X ", (*packet)[p++]);

                sWorldLog.Log("\n");
            }

            sWorldLog.Log("\n\n");
        }

        ///- Encrypt (if needed) the header
        _crypt.EncryptSend((uint8*)&hdr, 4);

        ///- Send the header and body to the client
        TcpSocket::SendBuf((char*)&hdr, 4);
        if(!packet->empty()) TcpSocket::SendBuf((char*)packet->contents(), packet->size());

        delete packet;
    }
}

void WorldSocket::Update(time_t diff)
{
    const uint32 SEND_PACKETS_MAX = 100;
    const uint32 SEND_BUFFER_SIZE = 1024;

    uint8 sendBuffer[SEND_BUFFER_SIZE];

    while (!_sendQueue.empty())
    {
        bool haveBigPacket = false;
        uint32 bufferSize = 0;

        ///- While we have packets to send
        for (uint32 packetCount = 0; (packetCount < SEND_PACKETS_MAX) && !_sendQueue.empty(); packetCount++)
        {
            ServerPktHeader *hdr = (ServerPktHeader*)&sendBuffer[bufferSize];

            // check merge possibility.
            WorldPacket *front = _sendQueue.front();
            uint32 packetSize = front->size();

            if ((sizeof(*hdr) + packetSize) > SEND_BUFFER_SIZE)
            {
                haveBigPacket = true;
                break;
            }

            if ((bufferSize + sizeof(*hdr) + packetSize) > sizeof(sendBuffer))
                break;

            // can be merged
            WorldPacket *packet = _sendQueue.next();

            hdr->size = ntohs((uint16)packetSize + 2);
            hdr->cmd = packet->GetOpcode();

            if( sWorldLog.LogWorld() )
            {
                sWorldLog.Log("SERVER:\nSOCKET: %u\nLENGTH: %u\nOPCODE: %s (0x%.4X)\nDATA:\n",
                    (uint32)GetSocket(),
                    packetSize,
                    LookupOpcodeName(packet->GetOpcode()),
                    packet->GetOpcode());

                uint32 p = 0;
                while (p < packetSize)
                {
                    for (uint32 j = 0; j < 16 && p < packetSize; j++)
                        sWorldLog.Log("%.2X ", (*packet)[p++]);

                    sWorldLog.Log("\n");
                }

                sWorldLog.Log("\n\n");
            }

            ///- Encrypt (if needed) the header
            _crypt.EncryptSend((uint8*)hdr, sizeof(*hdr));
            bufferSize += sizeof(*hdr);

            if (packetSize)
            {
                memcpy(&sendBuffer[bufferSize], packet->contents(), packetSize);
                bufferSize += packetSize;
            }

            ///- Send the header and body to the client
            delete packet;
        }

        // send merged packets
        if (bufferSize) TcpSocket::SendBuf((char*)sendBuffer, bufferSize);
        // send too big non-merged packet
        if (haveBigPacket) SendSinglePacket();
    }
}

/// Handle the authentication waiting queue (to be completed)
void WorldSocket::SendAuthWaitQue(uint32 position)
{
    if(position == 0)
    {
        WorldPacket packet( SMSG_AUTH_RESPONSE, 1 );
        packet << uint8( AUTH_OK );
        SendPacket(&packet);
    }
    else
    {
        WorldPacket packet( SMSG_AUTH_RESPONSE, 5 );
        packet << uint8( AUTH_WAIT_QUEUE );
        packet << uint32 (position);                        //amount of players in queue
        SendPacket(&packet);
    }
}

void WorldSocket::SizeError(WorldPacket const& packet, uint32 size) const
{
    sLog.outError("Client send packet %s (%u) with size %u but expected %u (attempt crash server?), skipped",
        LookupOpcodeName(packet.GetOpcode()),packet.GetOpcode(),packet.size(),size);
}
