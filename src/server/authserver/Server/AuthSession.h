/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AsyncCallbackProcessor.h"
#include "Common.h"
#include "CryptoHash.h"
#include "DatabaseEnvFwd.h"
#include "DeadlineTimer.h"
#include "Duration.h"
#include "Optional.h"
#include "Socket.h"
#include "SRP6.h"
#include <boost/asio/ip/tcp.hpp>
#include <span>

using boost::asio::ip::tcp;

class AuthHandlerTable;
class ByteBuffer;

enum AuthStatus
{
    STATUS_CHALLENGE = 0,
    STATUS_LOGON_PROOF,
    STATUS_RECONNECT_PROOF,
    STATUS_AUTHED,
    STATUS_WAITING_FOR_REALM_LIST,
    STATUS_XFER,
    STATUS_CLOSED
};

struct AccountInfo
{
    void LoadResult(Field* fields);

    uint32 Id = 0;
    std::string Login;
    bool IsLockedToIP = false;
    std::string LockCountry;
    std::string LastIP;
    uint32 FailedLogins = 0;
    bool IsBanned = false;
    bool IsPermanenetlyBanned = false;
    AccountTypes SecurityLevel = SEC_PLAYER;
};

class AuthSession final : public Trinity::Net::Socket<>
{
    using AuthSocket = Socket;

public:
    AuthSession(Trinity::Net::IoContextTcpSocket&& socket);

    void Start() override;
    bool Update() override;

    void SendPacket(ByteBuffer& packet);

    Trinity::Net::SocketReadCallbackResult ReadHandler() override;

    void QueueQuery(QueryCallback&& queryCallback);

private:
    friend AuthHandlerTable;
    bool HandleLogonChallenge();
    bool HandleLogonProof();
    bool HandleReconnectChallenge();
    bool HandleReconnectProof();
    bool HandleRealmList();
    bool HandleXferAccept();
    bool HandleXferResume();
    bool HandleXferCancel();

    void LogonChallengeCallback(PreparedQueryResult result);
    void ReconnectChallengeCallback(PreparedQueryResult result);
    void RealmListCallback(PreparedQueryResult result);

    bool VerifyVersion(std::span<uint8 const> a, Trinity::Crypto::SHA1::Digest const& versionProof, bool isReconnect);
    void SetTimeout();

    Optional<Trinity::Crypto::SRP6> _srp6;
    SessionKey _sessionKey = {};
    std::array<uint8, 16> _reconnectProof = {};

    Trinity::Asio::DeadlineTimer _timeout;
    AuthStatus _status;
    AccountInfo _accountInfo;
    Optional<std::vector<uint8>> _totpSecret;
    LocaleConstant _locale;
    uint32 _os;
    std::string_view _ipCountry;
    uint16 _build;
    uint8 _expversion;
    Minutes _timezoneOffset;

    QueryCallbackProcessor _queryProcessor;
};

#endif
