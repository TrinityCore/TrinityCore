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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <ace/Message_Block.h>
#include <ace/OS_NS_string.h>
#include <ace/OS_NS_unistd.h>
#include <ace/os_include/arpa/os_inet.h>
#include <ace/os_include/netinet/os_tcp.h>
#include <ace/os_include/sys/os_types.h>
#include <ace/os_include/sys/os_socket.h>
#include <ace/OS_NS_string.h>
#include <ace/Reactor.h>
#include <ace/Auto_Ptr.h>

#include "WorldSocket.h"
#include "Common.h"

#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "SharedDefines.h"
#include "ByteBuffer.h"
#include "Opcodes.h"
#include "Database/DatabaseEnv.h"
#include "BigNumber.h"
#include "SHA1.h"
#include "WorldSession.h"
#include "WorldSocketMgr.h"
#include "Log.h"
#include "WorldLog.h"

#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

struct ServerPktHeader
{
    /**
     * size is the length of the payload _plus_ the length of the opcode
     */
    ServerPktHeader(uint32 size, uint16 cmd) : size(size)
    {
        uint8 headerIndex=0;
        if (isLargePacket())
        {
            sLog.outDebug("initializing large server to client packet. Size: %u, cmd: %u", size, cmd);
            header[headerIndex++] = 0x80|(0xFF &(size>>16));
        }
        header[headerIndex++] = 0xFF &(size>>8);
        header[headerIndex++] = 0xFF &size;

        header[headerIndex++] = 0xFF & cmd;
        header[headerIndex++] = 0xFF & (cmd>>8);
    }

    uint8 getHeaderLength()
    {
        // cmd = 2 bytes, size= 2||3bytes
        return 2+(isLargePacket()?3:2);
    }

    bool isLargePacket()
    {
        return size > 0x7FFF;
    }

    const uint32 size;
    uint8 header[5];
};

struct ClientPktHeader
{
    uint16 size;
    uint32 cmd;
};

#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

WorldSocket::WorldSocket (void) :
WorldHandler(),
m_Session(0),
m_RecvWPct(0),
m_RecvPct(),
m_Header(sizeof (ClientPktHeader)),
m_OutBuffer(0),
m_OutBufferSize(65536),
m_OutActive(false),
m_Seed(static_cast<uint32> (rand32())),
m_OverSpeedPings(0),
m_LastPingTime(ACE_Time_Value::zero)
{
    reference_counting_policy().value (ACE_Event_Handler::Reference_Counting_Policy::ENABLED);
    
    msg_queue()->high_water_mark(8*1024*1024);
    msg_queue()->low_water_mark(8*1024*1024);
}

WorldSocket::~WorldSocket (void)
{
    if (m_RecvWPct)
        delete m_RecvWPct;

    if (m_OutBuffer)
        m_OutBuffer->release();

    closing_ = true;

    peer().close();
}

bool WorldSocket::IsClosed (void) const
{
    return closing_;
}

void WorldSocket::CloseSocket (void)
{
    {
        ACE_GUARD (LockType, Guard, m_OutBufferLock);

        if (closing_)
            return;

        closing_ = true;
        peer().close_writer();
    }

    {
        ACE_GUARD (LockType, Guard, m_SessionLock);

        m_Session = NULL;
    }
}

const std::string& WorldSocket::GetRemoteAddress (void) const
{
    return m_Address;
}

int WorldSocket::SendPacket (const WorldPacket& pct)
{
    ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);

    if (closing_)
        return -1;

    // Dump outgoing packet.
    if (sWorldLog.LogWorld())
    {
        sWorldLog.outTimestampLog ("SERVER:\nSOCKET: %u\nLENGTH: %u\nOPCODE: %s (0x%.4X)\nDATA:\n",
                     (uint32) get_handle(),
                     pct.size(),
                     LookupOpcodeName (pct.GetOpcode()),
                     pct.GetOpcode());

        uint32 p = 0;
        while (p < pct.size())
        {
            for (uint32 j = 0; j < 16 && p < pct.size(); j++)
                sWorldLog.outLog("%.2X ", const_cast<WorldPacket&>(pct)[p++]);

            sWorldLog.outLog("\n");
        }
        sWorldLog.outLog("\n");
    }

    ServerPktHeader header(pct.size()+2, pct.GetOpcode());
    m_Crypt.EncryptSend ((uint8*)header.header, header.getHeaderLength());

    if (m_OutBuffer->space() >= pct.size() + header.getHeaderLength() && msg_queue()->is_empty())
    {
        // Put the packet on the buffer.
        if (m_OutBuffer->copy((char*) header.header, header.getHeaderLength()) == -1)
            ACE_ASSERT (false);

        if (!pct.empty())
            if (m_OutBuffer->copy((char*) pct.contents(), pct.size()) == -1)
                ACE_ASSERT (false);
    }
    else
    {
        // Enqueue the packet.
        ACE_Message_Block* mb;

        ACE_NEW_RETURN(mb, ACE_Message_Block(pct.size() + header.getHeaderLength()), -1);

        mb->copy((char*) header.header, header.getHeaderLength());

        if (!pct.empty())
            mb->copy((const char*)pct.contents(), pct.size());

        if (msg_queue()->enqueue_tail(mb,(ACE_Time_Value*)&ACE_Time_Value::zero) == -1)
        {
            sLog.outError("WorldSocket::SendPacket enqueue_tail failed");
            mb->release();
            return -1;
        }
    }

    return 0;
}

long WorldSocket::AddReference (void)
{
    return static_cast<long> (add_reference());
}

long WorldSocket::RemoveReference (void)
{
    return static_cast<long> (remove_reference());
}

int WorldSocket::open (void *a)
{
    ACE_UNUSED_ARG (a);

    // Prevent double call to this func.
    if (m_OutBuffer)
        return -1;

    // This will also prevent the socket from being Updated
    // while we are initializing it.
    m_OutActive = true;

    // Hook for the manager.
    if (sWorldSocketMgr->OnSocketOpen(this) == -1)
        return -1;

    // Allocate the buffer.
    ACE_NEW_RETURN (m_OutBuffer, ACE_Message_Block (m_OutBufferSize), -1);

    // Store peer address.
    ACE_INET_Addr remote_addr;

    if (peer().get_remote_addr(remote_addr) == -1)
    {
        sLog.outError ("WorldSocket::open: peer().get_remote_addr errno = %s", ACE_OS::strerror (errno));
        return -1;
    }

    m_Address = remote_addr.get_host_addr();
    
    // Send startup packet.
    WorldPacket packet (SMSG_AUTH_CHALLENGE, 24);
    packet << uint32(1);                                    // 1...31
    packet << m_Seed;

    BigNumber seed1;
    seed1.SetRand(16 * 8);
    packet.append(seed1.AsByteArray(16), 16);               // new encryption seeds

    BigNumber seed2;
    seed2.SetRand(16 * 8);
    packet.append(seed2.AsByteArray(16), 16);               // new encryption seeds

    if (SendPacket(packet) == -1)
        return -1;
    
    // Register with ACE Reactor
    if (reactor()->register_handler(this, ACE_Event_Handler::READ_MASK | ACE_Event_Handler::WRITE_MASK) == -1)
    {
        sLog.outError ("WorldSocket::open: unable to register client handler errno = %s", ACE_OS::strerror (errno));
        return -1;
    }
    
    // reactor takes care of the socket from now on
    remove_reference();

    return 0;
}

int WorldSocket::close (int)
{
    shutdown();

    closing_ = true;

    remove_reference();

    return 0;
}

int WorldSocket::handle_input (ACE_HANDLE)
{
    if (closing_)
        return -1;

    switch (handle_input_missing_data())
    {
        case -1 :
        {
            if ((errno == EWOULDBLOCK) ||
                (errno == EAGAIN))
            {
                return Update();                           // interesting line ,isn't it ?
            }

            DEBUG_LOG("WorldSocket::handle_input: Peer error closing connection errno = %s", ACE_OS::strerror (errno));

            errno = ECONNRESET;
            return -1;
        }
        case 0:
        {
            DEBUG_LOG("WorldSocket::handle_input: Peer has closed connection");

            errno = ECONNRESET;
            return -1;
        }
        case 1:
            return 1;
        default:
            return Update();                               // another interesting line ;)
    }

    ACE_NOTREACHED(return -1);
}

int WorldSocket::handle_output (ACE_HANDLE)
{
    ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);

    if (closing_)
        return -1;

    size_t send_len = m_OutBuffer->length();

    if (send_len == 0)
        return handle_output_queue(Guard);

#ifdef MSG_NOSIGNAL
    ssize_t n = peer().send (m_OutBuffer->rd_ptr(), send_len, MSG_NOSIGNAL);
#else
    ssize_t n = peer().send (m_OutBuffer->rd_ptr(), send_len);
#endif // MSG_NOSIGNAL

    if (n == 0)
        return -1;
    else if (n == -1)
    {
        if (errno == EWOULDBLOCK || errno == EAGAIN)
            return schedule_wakeup_output (Guard);

        return -1;
    }
    else if (n < (ssize_t)send_len) //now n > 0
    {
        m_OutBuffer->rd_ptr (static_cast<size_t> (n));

        // move the data to the base of the buffer
        m_OutBuffer->crunch();

        return schedule_wakeup_output (Guard);
    }
    else //now n == send_len
    {
        m_OutBuffer->reset();

        return handle_output_queue (Guard);
    }

    ACE_NOTREACHED (return 0);
}

int WorldSocket::handle_output_queue (GuardType& g)
{
    if (msg_queue()->is_empty())
        return cancel_wakeup_output(g);

    ACE_Message_Block *mblk;

    if (msg_queue()->dequeue_head(mblk, (ACE_Time_Value*)&ACE_Time_Value::zero) == -1)
    {
        sLog.outError("WorldSocket::handle_output_queue dequeue_head");
        return -1;
    }

    const size_t send_len = mblk->length();

#ifdef MSG_NOSIGNAL
    ssize_t n = peer().send (mblk->rd_ptr(), send_len, MSG_NOSIGNAL);
#else
    ssize_t n = peer().send (mblk->rd_ptr(), send_len);
#endif // MSG_NOSIGNAL

    if (n == 0)
    {
        mblk->release();

        return -1;
    }
    else if (n == -1)
    {
        if (errno == EWOULDBLOCK || errno == EAGAIN)
        {
            msg_queue()->enqueue_head(mblk, (ACE_Time_Value*) &ACE_Time_Value::zero);
            return schedule_wakeup_output (g);
        }

        mblk->release();
        return -1;
    }
    else if (n < (ssize_t)send_len) //now n > 0
    {
        mblk->rd_ptr(static_cast<size_t> (n));

        if (msg_queue()->enqueue_head(mblk, (ACE_Time_Value*) &ACE_Time_Value::zero) == -1)
        {
            sLog.outError("WorldSocket::handle_output_queue enqueue_head");
            mblk->release();
            return -1;
        }

        return schedule_wakeup_output (g);
    }
    else //now n == send_len
    {
        mblk->release();

        return msg_queue()->is_empty() ? cancel_wakeup_output(g) : ACE_Event_Handler::WRITE_MASK;
    }

    ACE_NOTREACHED(return -1);
}

int WorldSocket::handle_close (ACE_HANDLE h, ACE_Reactor_Mask)
{
    // Critical section
    {
        ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);

        closing_ = true;

        if (h == ACE_INVALID_HANDLE)
            peer().close_writer();
    }

    // Critical section
    {
        ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

        m_Session = NULL;
    }

    return 0;
}

int WorldSocket::Update (void)
{
    if (closing_)
        return -1;

    if (m_OutActive || (m_OutBuffer->length() == 0 && msg_queue()->is_empty()))
        return 0;

    int ret;
    do
        ret = handle_output (get_handle());
    while (ret > 0);

    return ret;
}

int WorldSocket::handle_input_header (void)
{
    ACE_ASSERT (m_RecvWPct == NULL);

    ACE_ASSERT (m_Header.length() == sizeof(ClientPktHeader));

    m_Crypt.DecryptRecv ((uint8*) m_Header.rd_ptr(), sizeof(ClientPktHeader));

    ClientPktHeader& header = *((ClientPktHeader*) m_Header.rd_ptr());

    EndianConvertReverse(header.size);
    EndianConvert(header.cmd);

    if ((header.size < 4) || (header.size > 10240) || (header.cmd  > 10240))
    {
        sLog.outError ("WorldSocket::handle_input_header: client sent malformed packet size = %d , cmd = %d",
                       header.size, header.cmd);

        errno = EINVAL;
        return -1;
    }

    header.size -= 4;

    ACE_NEW_RETURN (m_RecvWPct, WorldPacket ((uint16) header.cmd, header.size), -1);

    if (header.size > 0)
    {
        m_RecvWPct->resize (header.size);
        m_RecvPct.base ((char*) m_RecvWPct->contents(), m_RecvWPct->size());
    }
    else
    {
        ACE_ASSERT(m_RecvPct.space() == 0);
    }

    return 0;
}

int WorldSocket::handle_input_payload (void)
{
    // set errno properly here on error !!!
    // now have a header and payload

    ACE_ASSERT (m_RecvPct.space() == 0);
    ACE_ASSERT (m_Header.space() == 0);
    ACE_ASSERT (m_RecvWPct != NULL);

    const int ret = ProcessIncoming (m_RecvWPct);

    m_RecvPct.base (NULL, 0);
    m_RecvPct.reset();
    m_RecvWPct = NULL;

    m_Header.reset();

    if (ret == -1)
        errno = EINVAL;

    return ret;
}

int WorldSocket::handle_input_missing_data (void)
{
    char buf [4096];

    ACE_Data_Block db (sizeof (buf),
                        ACE_Message_Block::MB_DATA,
                        buf,
                        0,
                        0,
                        ACE_Message_Block::DONT_DELETE,
                        0);

    ACE_Message_Block message_block(&db,
                                    ACE_Message_Block::DONT_DELETE,
                                    0);

    const size_t recv_size = message_block.space();

    const ssize_t n = peer().recv (message_block.wr_ptr(),
                                          recv_size);

    if (n <= 0)
        return n;

    message_block.wr_ptr (n);

    while (message_block.length() > 0)
    {
        if (m_Header.space() > 0)
        {
            //need to receive the header
            const size_t to_header = (message_block.length() > m_Header.space() ? m_Header.space() : message_block.length());
            m_Header.copy (message_block.rd_ptr(), to_header);
            message_block.rd_ptr (to_header);

            if (m_Header.space() > 0)
            {
                // Couldn't receive the whole header this time.
                ACE_ASSERT (message_block.length() == 0);
                errno = EWOULDBLOCK;
                return -1;
            }

            // We just received nice new header
            if (handle_input_header() == -1)
            {
                ACE_ASSERT ((errno != EWOULDBLOCK) && (errno != EAGAIN));
                return -1;
            }
        }

        // Its possible on some error situations that this happens
        // for example on closing when epoll receives more chunked data and stuff
        // hope this is not hack ,as proper m_RecvWPct is asserted around
        if (!m_RecvWPct)
        {
            sLog.outError ("Forcing close on input m_RecvWPct = NULL");
            errno = EINVAL;
            return -1;
        }

        // We have full read header, now check the data payload
        if (m_RecvPct.space() > 0)
        {
            //need more data in the payload
            const size_t to_data = (message_block.length() > m_RecvPct.space() ? m_RecvPct.space() : message_block.length());
            m_RecvPct.copy (message_block.rd_ptr(), to_data);
            message_block.rd_ptr (to_data);

            if (m_RecvPct.space() > 0)
            {
                // Couldn't receive the whole data this time.
                ACE_ASSERT (message_block.length() == 0);
                errno = EWOULDBLOCK;
                return -1;
            }
        }

        //just received fresh new payload
        if (handle_input_payload() == -1)
        {
            ACE_ASSERT ((errno != EWOULDBLOCK) && (errno != EAGAIN));
            return -1;
        }
    }

    return n == recv_size ? 1 : 2;
}

int WorldSocket::cancel_wakeup_output (GuardType& g)
{
    if (!m_OutActive)
        return 0;

    m_OutActive = false;

    g.release();

    if (reactor()->cancel_wakeup
        (this, ACE_Event_Handler::WRITE_MASK) == -1)
    {
        // would be good to store errno from reactor with errno guard
        sLog.outError ("WorldSocket::cancel_wakeup_output");
        return -1;
    }

    return 0;
}

int WorldSocket::schedule_wakeup_output (GuardType& g)
{
    if (m_OutActive)
        return 0;

    m_OutActive = true;

    g.release();

    if (reactor()->schedule_wakeup
        (this, ACE_Event_Handler::WRITE_MASK) == -1)
    {
        sLog.outError ("WorldSocket::schedule_wakeup_output");
        return -1;
    }

    return 0;
}

int WorldSocket::ProcessIncoming (WorldPacket* new_pct)
{
    ACE_ASSERT (new_pct);

    // manage memory ;)
    ACE_Auto_Ptr<WorldPacket> aptr (new_pct);

    const ACE_UINT16 opcode = new_pct->GetOpcode();

    if (closing_)
        return -1;

    // Dump received packet.
    if (sWorldLog.LogWorld())
    {
        sWorldLog.outTimestampLog ("CLIENT:\nSOCKET: %u\nLENGTH: %u\nOPCODE: %s (0x%.4X)\nDATA:\n",
                     (uint32) get_handle(),
                     new_pct->size(),
                     LookupOpcodeName (new_pct->GetOpcode()),
                     new_pct->GetOpcode());

        uint32 p = 0;
        while (p < new_pct->size())
        {
            for (uint32 j = 0; j < 16 && p < new_pct->size(); j++)
                sWorldLog.outLog ("%.2X ", (*new_pct)[p++]);

            sWorldLog.outLog ("\n");
        }
        sWorldLog.outLog ("\n");
    }

    try {
        switch(opcode)
        {
            case CMSG_PING:
                return HandlePing (*new_pct);
            case CMSG_AUTH_SESSION:
                if (m_Session)
                {
                    sLog.outError ("WorldSocket::ProcessIncoming: Player send CMSG_AUTH_SESSION again");
                    return -1;
                }

                return HandleAuthSession (*new_pct);
            case CMSG_KEEP_ALIVE:
                DEBUG_LOG ("CMSG_KEEP_ALIVE ,size: %d", new_pct->size());

                return 0;
            default:
            {
                ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

                if (m_Session != NULL)
                {
                    // Our Idle timer will reset on any non PING opcodes.
                    // Catches people idling on the login screen and any lingering ingame connections.
                    m_Session->ResetTimeOutTime();
                    
                    // OK ,give the packet to WorldSession
                    aptr.release();
                    // WARNINIG here we call it with locks held.
                    // Its possible to cause deadlock if QueuePacket calls back
                    m_Session->QueuePacket (new_pct);
                    return 0;
                }
                else
                {
                    sLog.outError ("WorldSocket::ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                    return -1;
                }
            }
        }
    }
    catch(ByteBufferException &)
    {
        sLog.outError("WorldSocket::ProcessIncoming ByteBufferException occured while parsing an instant handled packet (opcode: %u) from client %s, accountid=%i. Disconnected client.",
                opcode, GetRemoteAddress().c_str(), m_Session?m_Session->GetAccountId():-1);
        if (sLog.IsOutDebug())
        {
            sLog.outDebug("Dumping error causing packet:");
            new_pct->hexlike();
        }

        return -1;
    }

    ACE_NOTREACHED (return 0);
}

int WorldSocket::HandleAuthSession (WorldPacket& recvPacket)
{
    // NOTE: ATM the socket is singlethread, have this in mind ...
    uint8 digest[20];
    uint32 clientSeed;
    uint32 unk2, unk3;
    uint64 unk4;
    uint32 BuiltNumberClient;
    uint32 id, security;
    //uint8 expansion = 0;
    LocaleConstant locale;
    std::string account;
    Sha1Hash sha1;
    BigNumber v, s, g, N;
    WorldPacket packet, SendAddonPacked;

    BigNumber K;

    if (sWorld.IsClosed())
    {
        packet.Initialize(SMSG_AUTH_RESPONSE, 1);
        packet << uint8(AUTH_REJECT);
        SendPacket (packet);

        sLog.outError ("WorldSocket::HandleAuthSession: World closed, denying client (%s).", m_Session->GetRemoteAddress().c_str());
        return -1;
    }

    // Read the content of the packet
    recvPacket >> BuiltNumberClient;                        // for now no use
    recvPacket >> unk2;
    recvPacket >> account;
    recvPacket >> unk3;
    recvPacket >> clientSeed;
    recvPacket >> unk4;
    recvPacket.read (digest, 20);

    DEBUG_LOG ("WorldSocket::HandleAuthSession: client %u, unk2 %u, account %s, unk3 %u, clientseed %u",
                BuiltNumberClient,
                unk2,
                account.c_str(),
                unk3,
                clientSeed);

    // Get the account information from the realmd database
    std::string safe_account = account; // Duplicate, else will screw the SHA hash verification below
    LoginDatabase.escape_string (safe_account);
    // No SQL injection, username escaped.

    QueryResult_AutoPtr result =
          LoginDatabase.PQuery ("SELECT "
                                "id, "                      //0
                                "sessionkey, "              //1
                                "last_ip, "                 //2
                                "locked, "                  //3
                                "v, "                       //4
                                "s, "                       //5
                                "expansion, "               //6
                                "mutetime, "                //7
                                "locale "                   //8
                                "FROM account "
                                "WHERE username = '%s'",
                                safe_account.c_str());

    // Stop if the account is not found
    if (!result)
    {
        packet.Initialize (SMSG_AUTH_RESPONSE, 1);
        packet << uint8 (AUTH_UNKNOWN_ACCOUNT);

        SendPacket (packet);

        sLog.outError ("WorldSocket::HandleAuthSession: Sent Auth Response (unknown account).");
        return -1;
    }

    Field* fields = result->Fetch();

    uint8 expansion = fields[6].GetUInt8();
    uint32 world_expansion = sWorld.getConfig(CONFIG_EXPANSION);
    if (expansion > world_expansion)
        expansion = world_expansion;
    //expansion = ((sWorld.getConfig(CONFIG_EXPANSION) > fields[6].GetUInt8()) ? fields[6].GetUInt8() : sWorld.getConfig(CONFIG_EXPANSION));

    N.SetHexStr ("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
    g.SetDword (7);

    v.SetHexStr(fields[4].GetString());
    s.SetHexStr (fields[5].GetString());

    const char* sStr = s.AsHexStr();                       //Must be freed by OPENSSL_free()
    const char* vStr = v.AsHexStr();                       //Must be freed by OPENSSL_free()

    DEBUG_LOG ("WorldSocket::HandleAuthSession: (s,v) check s: %s v: %s",
                sStr,
                vStr);

    OPENSSL_free ((void*) sStr);
    OPENSSL_free ((void*) vStr);

    ///- Re-check ip locking (same check as in realmd).
    if (fields[3].GetUInt8() == 1) // if ip is locked
    {
        if (strcmp (fields[2].GetString(), GetRemoteAddress().c_str()))
        {
            packet.Initialize (SMSG_AUTH_RESPONSE, 1);
            packet << uint8 (AUTH_FAILED);
            SendPacket (packet);

            sLog.outBasic ("WorldSocket::HandleAuthSession: Sent Auth Response (Account IP differs).");
            return -1;
        }
    }

    id = fields[0].GetUInt32();
    /*
    if (security > SEC_ADMINISTRATOR)                        // prevent invalid security settings in DB
        security = SEC_ADMINISTRATOR;
        */

    K.SetHexStr (fields[1].GetString());

    time_t mutetime = time_t (fields[7].GetUInt64());

    locale = LocaleConstant (fields[8].GetUInt8());
    if (locale >= MAX_LOCALE)
        locale = LOCALE_enUS;

    // Checks gmlevel per Realm
    result =
        LoginDatabase.PQuery ("SELECT "
                              "RealmID, "            //0
                              "gmlevel "             //1
                              "FROM account_access "
                              "WHERE id = '%d'"
                              " AND (RealmID = '%d'"
                              " OR RealmID = '-1')",
                              id, realmID);
    if (!result)
        security = 0;
    else
    {
        fields = result->Fetch();
        security = fields[1].GetInt32();
    }

    // Re-check account ban (same check as in realmd)
    QueryResult_AutoPtr banresult =
          LoginDatabase.PQuery ("SELECT 1 FROM account_banned WHERE id = %u AND active = 1 "
                                "UNION "
                                "SELECT 1 FROM ip_banned WHERE ip = '%s'",
                                id, GetRemoteAddress().c_str());

    if (banresult) // if account banned
    {
        packet.Initialize (SMSG_AUTH_RESPONSE, 1);
        packet << uint8 (AUTH_BANNED);
        SendPacket (packet);

        sLog.outError ("WorldSocket::HandleAuthSession: Sent Auth Response (Account banned).");
        return -1;
    }

    // Check locked state for server
    sWorld.UpdateAllowedSecurity();
    AccountTypes allowedAccountType = sWorld.GetPlayerSecurityLimit();
    sLog.outDebug("Allowed Level: %u Player Level %u", allowedAccountType, AccountTypes(security));
    if (allowedAccountType > SEC_PLAYER && AccountTypes(security) < allowedAccountType)
    {
        WorldPacket Packet (SMSG_AUTH_RESPONSE, 1);
        Packet << uint8 (AUTH_UNAVAILABLE);

        SendPacket (packet);

        sLog.outDetail ("WorldSocket::HandleAuthSession: User tries to login but his security level is not enough");
        return -1;
    }

    // Check that Key and account name are the same on client and server
    Sha1Hash sha;

    uint32 t = 0;
    uint32 seed = m_Seed;

    sha.UpdateData (account);
    sha.UpdateData ((uint8 *) & t, 4);
    sha.UpdateData ((uint8 *) & clientSeed, 4);
    sha.UpdateData ((uint8 *) & seed, 4);
    sha.UpdateBigNumbers (&K, NULL);
    sha.Finalize();

    if (memcmp (sha.GetDigest(), digest, 20))
    {
        packet.Initialize (SMSG_AUTH_RESPONSE, 1);
        packet << uint8 (AUTH_FAILED);

        SendPacket (packet);

        sLog.outError ("WorldSocket::HandleAuthSession: Sent Auth Response (authentification failed).");
        return -1;
    }

    std::string address = GetRemoteAddress();

    DEBUG_LOG ("WorldSocket::HandleAuthSession: Client '%s' authenticated successfully from %s.",
                account.c_str(),
                address.c_str());

    // Update the last_ip in the database
    // No SQL injection, username escaped.
    LoginDatabase.escape_string (address);

    LoginDatabase.PExecute ("UPDATE account "
                            "SET last_ip = '%s' "
                            "WHERE username = '%s'",
                            address.c_str(),
                            safe_account.c_str());

    // NOTE ATM the socket is single-threaded, have this in mind ...
    ACE_NEW_RETURN (m_Session, WorldSession (id, this, AccountTypes(security), expansion, mutetime, locale), -1);

    m_Crypt.Init(&K);

    m_Session->LoadGlobalAccountData();
    m_Session->LoadTutorialsData();
    m_Session->ReadAddonsInfo(recvPacket);

    // Sleep this Network thread for 
    uint32 sleepTime = sWorld.getConfig(CONFIG_SESSION_ADD_DELAY);
    ACE_OS::sleep (ACE_Time_Value (0, sleepTime));

    sWorld.AddSession (m_Session);

    return 0;
}

int WorldSocket::HandlePing (WorldPacket& recvPacket)
{
    uint32 ping;
    uint32 latency;

    // Get the ping packet content
    recvPacket >> ping;
    recvPacket >> latency;

    if (m_LastPingTime == ACE_Time_Value::zero)
        m_LastPingTime = ACE_OS::gettimeofday(); // for 1st ping
    else
    {
        ACE_Time_Value cur_time = ACE_OS::gettimeofday();
        ACE_Time_Value diff_time (cur_time);
        diff_time -= m_LastPingTime;
        m_LastPingTime = cur_time;

        if (diff_time < ACE_Time_Value (27))
        {
            ++m_OverSpeedPings;

            uint32 max_count = sWorld.getConfig (CONFIG_MAX_OVERSPEED_PINGS);

            if (max_count && m_OverSpeedPings > max_count)
            {
                ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

                if (m_Session && m_Session->GetSecurity() == SEC_PLAYER)
                {
                    sLog.outError  ("WorldSocket::HandlePing: Player kicked for "
                                    "over-speed pings address = %s",
                                    GetRemoteAddress().c_str());

                    return -1;
                }
            }
        }
        else
            m_OverSpeedPings = 0;
    }

    // critical section
    {
        ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

        if (m_Session)
            m_Session->SetLatency (latency);
        else
        {
            sLog.outError ("WorldSocket::HandlePing: peer sent CMSG_PING, "
                            "but is not authenticated or got recently kicked,"
                            " address = %s",
                            GetRemoteAddress().c_str());
             return -1;
        }
    }

    WorldPacket packet (SMSG_PONG, 4);
    packet << ping;
    return SendPacket (packet);
}
