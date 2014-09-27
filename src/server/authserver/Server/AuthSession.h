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

#ifndef __AUTHSESSION_H__
#define __AUTHSESSION_H__

#include "Common.h"
#include "ByteBuffer.h"
#include "Socket.h"
#include "BigNumber.h"
#include <memory>
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;

struct AuthHandler;

class AuthSession : public Socket<AuthSession>
{
public:
    static std::unordered_map<uint8, AuthHandler> InitHandlers();

    AuthSession(tcp::socket&& socket) : Socket(std::move(socket)),
        _isAuthenticated(false), _build(0), _expversion(0), _accountSecurityLevel(SEC_PLAYER)
    {
        N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
        g.SetDword(7);
    }

    void Start() override
    {
        AsyncRead();
    }

    void SendPacket(ByteBuffer& packet);

protected:
    void ReadHandler() override;

private:
    bool HandleLogonChallenge();
    bool HandleLogonProof();
    bool HandleReconnectChallenge();
    bool HandleReconnectProof();
    bool HandleRealmList();

    //data transfer handle for patch
    bool HandleXferResume();
    bool HandleXferCancel();
    bool HandleXferAccept();

    void SetVSFields(const std::string& rI);

    BigNumber N, s, g, v;
    BigNumber b, B;
    BigNumber K;
    BigNumber _reconnectProof;

    bool _isAuthenticated;
    std::string _tokenKey;
    std::string _login;
    std::string _localizationName;
    std::string _os;
    uint16 _build;
    uint8 _expversion;

    AccountTypes _accountSecurityLevel;
};

#pragma pack(push, 1)

struct AuthHandler
{
    uint32 status;
    size_t packetSize;
    bool (AuthSession::*handler)();
};

#pragma pack(pop)

#endif
