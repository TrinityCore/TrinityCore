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

#include <boost/asio/write.hpp>
#include <boost/asio/read_until.hpp>
#include <memory>
#include "WorldTcpSession.h"
#include "ServerPktHeader.h"
#include "BigNumber.h"
#include "Opcodes.h"
#include "ScriptMgr.h"
#include "SHA1.h"

using boost::asio::ip::tcp;
using boost::asio::streambuf;

WorldTcpSession::WorldTcpSession(tcp::socket socket)
    : _socket(std::move(socket)), _authSeed(static_cast<uint32>(rand32())), _worldSession(nullptr)
{
}

void WorldTcpSession::Start()
{
    AsyncReadHeader();
    HandleSendAuthSession();
}

void WorldTcpSession::HandleSendAuthSession()
{
    WorldPacket packet(SMSG_AUTH_CHALLENGE, 37);
    packet << uint32(1);                                    // 1...31
    packet << uint32(_authSeed);

    BigNumber seed1;
    seed1.SetRand(16 * 8);
    packet.append(seed1.AsByteArray(16).get(), 16);               // new encryption seeds

    BigNumber seed2;
    seed2.SetRand(16 * 8);
    packet.append(seed2.AsByteArray(16).get(), 16);               // new encryption seeds
    
    AsyncWrite(packet);
}


void WorldTcpSession::AsyncReadHeader()
{
    auto self(shared_from_this());
    _socket.async_read_some(boost::asio::buffer(_readBuffer, sizeof(ClientPktHeader)), [this, self](boost::system::error_code error, size_t transferedBytes)
    {
        if (!error && transferedBytes == sizeof(ClientPktHeader))
        {
            ClientPktHeader* header = (ClientPktHeader*)&_readBuffer;

            if (_worldSession)
                _authCrypt.DecryptRecv((uint8*)header, sizeof(ClientPktHeader));

            EndianConvertReverse(header->size);
            EndianConvert(header->cmd);

            AsyncReadData(header->size - sizeof(header->cmd));
        }
        else
        {
            _socket.close();
        }
    });
}

void WorldTcpSession::AsyncReadData(size_t dataSize)
{
    auto self(shared_from_this());
    _socket.async_read_some(boost::asio::buffer(&_readBuffer[sizeof(ClientPktHeader)], dataSize), [this, dataSize, self](boost::system::error_code error, size_t transferedBytes)
    {
        if (!error && transferedBytes == dataSize)
        {
            ClientPktHeader* header = (ClientPktHeader*)&_readBuffer;

            header->size -= sizeof(header->cmd);

            uint16 opcode = (uint16)header->cmd;

            std::string opcodeName = GetOpcodeNameForLogging(opcode);

            WorldPacket packet(opcode, header->size);

            if (header->size > 0)
            {
                packet.resize(header->size);

                std::memcpy(packet.contents(), &_readBuffer[sizeof(ClientPktHeader)], header->size);
            }

            switch (opcode)
            {
                case CMSG_PING:
                    //return HandlePing(*new_pct);
                    break;
                case CMSG_AUTH_SESSION:
                    if (_worldSession)
                    {
                        TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming: received duplicate CMSG_AUTH_SESSION from %s", _worldSession->GetPlayerInfo().c_str());
                        break;
                    }

                    sScriptMgr->OnPacketReceive(shared_from_this(), packet);
                    HandleAuthSession(packet);
                    break;
                case CMSG_KEEP_ALIVE:
                    TC_LOG_DEBUG("network", "%s", opcodeName.c_str());
                    sScriptMgr->OnPacketReceive(shared_from_this(), packet);
                    break;
                default:
                {
                    //ACE_GUARD_RETURN(LockType, Guard, m_SessionLock, -1);

                    if (!_worldSession)
                    {
                        TC_LOG_ERROR("network.opcode", "ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                        break;
                    }

                    // Our Idle timer will reset on any non PING opcodes.
                    // Catches people idling on the login screen and any lingering ingame connections.
                    _worldSession->ResetTimeOutTime();

                    // Copy the packet to the heap before enqueuing
                    _worldSession->QueuePacket(new WorldPacket(packet));
                    break;
                }
            }

            AsyncReadHeader();
        }
        else
        {
            _socket.close();
        }
    });
}

void WorldTcpSession::AsyncWrite(WorldPacket const& packet)
{
    ServerPktHeader header(packet.size() + 2, packet.GetOpcode());
    _authCrypt.EncryptSend((uint8*)header.header, header.getHeaderLength());

    auto data = new char[header.getHeaderLength() + packet.size()];
    std::memcpy(data, (char*)header.header, header.getHeaderLength());
    
    if (!packet.empty())
        std::memcpy(data + header.getHeaderLength(), (char const*)packet.contents(), packet.size());
    
    std::shared_ptr<char> buffer(data, [=](char* _b)
    {
        delete[] _b;
    });

    boost::asio::async_write(_socket, boost::asio::buffer(buffer.get(), header.getHeaderLength() + packet.size()), [this, buffer](boost::system::error_code error, std::size_t /*length*/)
    {
        if (error)
        {
            _socket.close();
        }
    });
}

void WorldTcpSession::HandleAuthSession(WorldPacket& recvPacket)
{
    uint8 digest[20];
    uint32 clientSeed;
    uint8 security;
    uint32 id;
    LocaleConstant locale;
    std::string account;
    SHA1Hash sha;
    uint32 clientBuild;
    uint32 unk2, unk3, unk5, unk6, unk7;
    uint64 unk4;
    WorldPacket packet, SendAddonPacked;
    BigNumber k;
    bool wardenActive = sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED);

    if (sWorld->IsClosed())
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: World closed, denying client (%s).", GetRemoteIpAddress().c_str());
        return;
    }

    // Read the content of the packet
    recvPacket >> clientBuild;
    recvPacket >> unk2;
    recvPacket >> account;
    recvPacket >> unk3;
    recvPacket >> clientSeed;
    recvPacket >> unk5 >> unk6 >> unk7;
    recvPacket >> unk4;
    recvPacket.read(digest, 20);

    TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: client %u, unk2 %u, account %s, unk3 %u, clientseed %u",
        clientBuild,
        unk2,
        account.c_str(),
        unk3,
        clientSeed);

    // Get the account information from the realmd database
    //         0           1        2       3          4         5       6          7   8
    // SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os FROM account WHERE username = ?
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME);

    stmt->setString(0, account);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Stop if the account is not found
    if (!result)
    {
        // We can not log here, as we do not know the account. Thus, no accountId.
        SendAuthResponseError(AUTH_UNKNOWN_ACCOUNT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (unknown account).");
        return;
    }

    Field* fields = result->Fetch();

    uint8 expansion = fields[4].GetUInt8();
    uint32 world_expansion = sWorld->getIntConfig(CONFIG_EXPANSION);
    if (expansion > world_expansion)
        expansion = world_expansion;

    // For hook purposes, we get Remoteaddress at this point.
    std::string address = GetRemoteIpAddress();

    // As we don't know if attempted login process by ip works, we update last_attempt_ip right away
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_ATTEMPT_IP);

    stmt->setString(0, address);
    stmt->setString(1, account);

    LoginDatabase.Execute(stmt);
    // This also allows to check for possible "hack" attempts on account

    // id has to be fetched at this point, so that first actual account response that fails can be logged
    id = fields[0].GetUInt32();

    ///- Re-check ip locking (same check as in realmd).
    if (fields[3].GetUInt8() == 1) // if ip is locked
    {
        if (strcmp(fields[2].GetCString(), address.c_str()))
        {
            SendAuthResponseError(AUTH_FAILED);
            TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account IP differs. Original IP: %s, new IP: %s).", fields[2].GetCString(), address.c_str());
            // We could log on hook only instead of an additional db log, however action logger is config based. Better keep DB logging as well
            sScriptMgr->OnFailedAccountLogin(id);
            return;
        }
    }

    k.SetHexStr(fields[1].GetCString());

    int64 mutetime = fields[5].GetInt64();
    //! Negative mutetime indicates amount of seconds to be muted effective on next login - which is now.
    if (mutetime < 0)
    {
        mutetime = time(NULL) + llabs(mutetime);

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME_LOGIN);

        stmt->setInt64(0, mutetime);
        stmt->setUInt32(1, id);

        LoginDatabase.Execute(stmt);
    }

    locale = LocaleConstant(fields[6].GetUInt8());
    if (locale >= TOTAL_LOCALES)
        locale = LOCALE_enUS;

    uint32 recruiter = fields[7].GetUInt32();
    std::string os = fields[8].GetString();

    // Must be done before WorldSession is created
    if (wardenActive && os != "Win" && os != "OSX")
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Client %s attempted to log in using invalid client OS (%s).", address.c_str(), os.c_str());
        return;
    }

    // Checks gmlevel per Realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);

    stmt->setUInt32(0, id);
    stmt->setInt32(1, int32(realmID));

    result = LoginDatabase.Query(stmt);

    if (!result)
        security = 0;
    else
    {
        fields = result->Fetch();
        security = fields[0].GetUInt8();
    }

    // Re-check account ban (same check as in realmd)
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BANS);

    stmt->setUInt32(0, id);
    stmt->setString(1, address);

    PreparedQueryResult banresult = LoginDatabase.Query(stmt);

    if (banresult) // if account banned
    {
        SendAuthResponseError(AUTH_BANNED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account banned).");
        sScriptMgr->OnFailedAccountLogin(id);
        return;
    }

    // Check locked state for server
    AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
    TC_LOG_DEBUG("network", "Allowed Level: %u Player Level %u", allowedAccountType, AccountTypes(security));
    if (allowedAccountType > SEC_PLAYER && AccountTypes(security) < allowedAccountType)
    {
        SendAuthResponseError(AUTH_UNAVAILABLE);
        TC_LOG_INFO("network", "WorldSocket::HandleAuthSession: User tries to login but his security level is not enough");
        sScriptMgr->OnFailedAccountLogin(id);
        return;
    }

    // Check that Key and account name are the same on client and server
    uint32 t = 0;

    sha.UpdateData(account);
    sha.UpdateData((uint8*)&t, 4);
    sha.UpdateData((uint8*)&clientSeed, 4);
    sha.UpdateData((uint8*)&_authSeed, 4);
    sha.UpdateBigNumbers(&k, NULL);
    sha.Finalize();

    if (memcmp(sha.GetDigest(), digest, 20))
    {
        SendAuthResponseError(AUTH_FAILED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Authentication failed for account: %u ('%s') address: %s", id, account.c_str(), address.c_str());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Client '%s' authenticated successfully from %s.",
        account.c_str(),
        address.c_str());

    // Check if this user is by any chance a recruiter
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_RECRUITER);

    stmt->setUInt32(0, id);

    result = LoginDatabase.Query(stmt);

    bool isRecruiter = false;
    if (result)
        isRecruiter = true;

    // Update the last_ip in the database as it was successful for login
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_IP);

    stmt->setString(0, address);
    stmt->setString(1, account);

    LoginDatabase.Execute(stmt);

    // NOTE ATM the socket is single-threaded, have this in mind ...
    _worldSession = new WorldSession(id, shared_from_this(), AccountTypes(security), expansion, mutetime, locale, recruiter, isRecruiter);

    _authCrypt.Init(&k);

    _worldSession->LoadGlobalAccountData();
    _worldSession->LoadTutorialsData();
    _worldSession->ReadAddonsInfo(recvPacket);
    _worldSession->LoadPermissions();

    // At this point, we can safely hook a successful login
    sScriptMgr->OnAccountLogin(id);

    // Initialize Warden system only if it is enabled by config
    if (wardenActive)
        _worldSession->InitWarden(&k, os);

    sWorld->AddSession(_worldSession);
}

void WorldTcpSession::SendAuthResponseError(uint8 code)
{
    WorldPacket packet(SMSG_AUTH_RESPONSE, 1);
    packet << uint8(code);

    AsyncWrite(packet);
}
