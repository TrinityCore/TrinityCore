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

#ifndef TRINITYCORE_SESSION_H
#define TRINITYCORE_SESSION_H

#include "AsyncCallbackProcessor.h"
#include "ClientBuildInfo.h"
#include "DatabaseEnvFwd.h"
#include "Duration.h"
#include "Hash.h"
#include "Realm.h"
#include "Socket.h"
#include "SslStream.h"
#include <memory>

namespace google::protobuf
{
class Message;
}

namespace pb = google::protobuf;

namespace Battlenet
{
    struct LastPlayedCharacterInfo
    {
        Battlenet::RealmHandle RealmId;
        std::string CharacterName;
        uint64 CharacterGUID;
        uint32 LastPlayedTime;
    };

    struct GameAccountInfo
    {
        void LoadResult(Field const* fields);

        uint32 Id;
        std::string Name;
        std::string DisplayName;
        time_t BanDate;
        time_t UnbanDate;
        bool IsBanned;
        bool IsPermanenetlyBanned;
        AccountTypes SecurityLevel;

        std::unordered_map<uint32 /*realmAddress*/, uint8> CharacterCounts;
        std::unordered_map<std::string /*subRegion*/, LastPlayedCharacterInfo, Trinity::TransparentHash<std::string_view>, std::equal_to<>> LastPlayedCharacters;
    };

    struct AccountInfo
    {
        void LoadResult(PreparedQueryResult result);

        uint32 Id;
        std::string Login;
        bool IsLockedToIP;
        std::string LockCountry;
        std::string LastIP;
        uint32 LoginTicketExpiry;
        bool IsBanned;
        bool IsPermanenetlyBanned;

        std::unordered_map<uint32, GameAccountInfo> GameAccounts;
    };

    class Session final : public std::enable_shared_from_this<Session>
    {
    public:
        explicit Session(Trinity::Net::IoContextTcpSocket&& socket);
        ~Session();

        void Start();
        bool Update();
        boost::asio::ip::address const& GetRemoteIpAddress() const { return _socket->GetRemoteIpAddress(); }
        bool IsOpen() const { return _socket->IsOpen(); }
        void CloseSocket() { return _socket->CloseSocket(); }
        void DelayedCloseSocket() { return _socket->DelayedCloseSocket(); }

        bool IsAuthed() const { return _authed; }

        uint32 GetSessionId() const { return _sessionId; }
        SystemTimePoint GetCreationTime() const { return _creationTime; }
        void SetClientInstanceId(std::string const& ciid) { _clientInstanceId = ciid; }

        uint32 GetAccountId() const { return _accountInfo->Id; }
        AccountInfo const* GetAccountInfo() const { return _accountInfo.get(); }

        uint32 GetGameAccountId() const { return _gameAccountInfo->Id; }
        GameAccountInfo const* GetGameAccountInfo() const { return _gameAccountInfo; }
        GameAccountInfo const* GetGameAccountInfo(uint32 gameAccountId) const;
        LastPlayedCharacterInfo const* GetLastPlayedCharacter(std::string_view subRegion) const;

        std::string const& GetLocale() const { return _locale; }
        std::string const& GetOS() const { return _os; }
        uint32 GetBuild() const { return _build; }
        ClientBuild::VariantId GetBuildVariant() const { return _buildVariant; }
        Minutes GetTimezoneOffset() const { return _timezoneOffset; }
        std::array<uint8, 32> GetClientSecret() const { return _clientSecret; }

        void SendResponse(uint32 token, pb::Message const* response);
        void SendResponse(uint32 token, uint32 status);

        void SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request, std::function<void(MessageBuffer)> callback);
        void SendRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request);

        void QueueQuery(QueryCallback&& queryCallback);

        void OnLogon(std::string_view platform, std::string_view locale, uint32 applicationVersion, Minutes timezoneOffset);
        void OnLogonSuccess(std::shared_ptr<AccountInfo> accountInfo, std::string_view ipCountry);
        void SetClientInfo(uint32 gameAccountId, ClientBuild::VariantId buildVariant, std::array<uint8, 32> const& clientSecret);

        std::string GetClientInfo() const;

        Trinity::Net::SocketReadCallbackResult ReadHandler();

    protected:
        bool ReadHeaderLengthHandler();
        bool ReadHeaderHandler();
        bool ReadDataHandler();

    private:
        void AsyncWrite(MessageBuffer* packet);

        using Socket = Trinity::Net::Socket<Trinity::Net::SslStream<>>;

        static std::shared_ptr<Socket> CreateSocket(Trinity::Net::IoContextTcpSocket&& socket);
        std::shared_ptr<Socket> _socket;

        enum class PacketReadState
        {
            HeaderLength,
            Header,
            Data,
        };

        PacketReadState _packetReadState;
        MessageBuffer _packetBuffer;

        uint32 const _sessionId;
        SystemTimePoint const _creationTime;
        std::string _clientInstanceId;

        std::shared_ptr<AccountInfo> _accountInfo;
        GameAccountInfo const* _gameAccountInfo;          // Points at selected game account (inside _gameAccounts)

        std::string _locale;
        std::string _os;
        uint32 _build;
        ClientBuild::VariantId _buildVariant;
        Minutes _timezoneOffset;

        std::string _ipCountry;

        std::array<uint8, 32> _clientSecret;

        bool _authed;

        QueryCallbackProcessor _queryProcessor;

        std::unordered_map<uint32, std::function<void(MessageBuffer)>> _responseCallbacks;
        uint32 _requestToken;
    };
}

#endif // TRINITYCORE_SESSION_H
