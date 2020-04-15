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

#ifndef Session_h__
#define Session_h__

#include "AsyncCallbackProcessor.h"
#include "Packets.h"
#include "BattlenetPacketCrypt.h"
#include "Socket.h"
#include "BigNumber.h"
#include "QueryResult.h"
#include "MPSCQueue.h"
#include <memory>
#include <boost/asio/ip/tcp.hpp>

struct Realm;
using boost::asio::ip::tcp;

namespace Battlenet
{
    struct PacketHeader;
    class BitStream;

    enum ModuleType
    {
        MODULE_PASSWORD,
        MODULE_TOKEN,
        MODULE_THUMBPRINT,
        MODULE_SELECT_GAME_ACCOUNT,
        MODULE_RISK_FINGERPRINT,
        MODULE_RESUME,

        MODULE_COUNT
    };

    enum class BufferSizes : uint32
    {
        SRP_6_V = 0x80,
        SRP_6_S = 0x20,
        Read = 0x4000
    };

    struct AccountInfo
    {
        void LoadResult(Field* fields);

        uint32 Id;
        std::string Login;
        bool IsLockedToIP;
        std::string LockCountry;
        std::string LastIP;
        uint32 FailedLogins;
        bool IsBanned;
        bool IsPermanentlyBanned;
    };

    struct GameAccountInfo
    {
        void LoadResult(Field* fields);

        uint32 Id;
        std::string Name;
        std::string DisplayName;
        bool IsBanned;
        bool IsPermanentlyBanned;
        AccountTypes SecurityLevel;
    };

    class Session : public Socket<Session>
    {
        typedef Socket<Session> BattlenetSocket;

    public:
        explicit Session(tcp::socket&& socket);
        ~Session();

        void LogUnhandledPacket(PacketHeader const& header);

        // Authentication
        void HandleLogonRequest(Authentication::LogonRequest const& logonRequest);
        void HandleResumeRequest(Authentication::ResumeRequest const& resumeRequest);
        void HandleProofResponse(Authentication::ProofResponse const& proofResponse);

        // Connection
        void HandlePing(Connection::Ping const& ping);
        void HandleEnableEncryption(Connection::EnableEncryption& enableEncryption);
        void HandleLogoutRequest(Connection::LogoutRequest const& logoutRequest);
        void HandleConnectionClosing(Connection::ConnectionClosing const& connectionClosing);

        // WoWRealm
        void HandleListSubscribeRequest(WoWRealm::ListSubscribeRequest const& listSubscribeRequest);
        void HandleListUnsubscribe(WoWRealm::ListUnsubscribe const& listUnsubscribe);
        void HandleJoinRequestV2(WoWRealm::JoinRequestV2 const& joinRequest);

        // Friends
        void HandleSocialNetworkCheckConnected(Friends::SocialNetworkCheckConnected const& socialNetworkCheckConnected);

        // Cache
        void HandleGetStreamItemsRequest(Cache::GetStreamItemsRequest const& getStreamItemsRequest);

        void Start() override;
        bool Update() override;

        void UpdateRealms(std::vector<Realm const*>& realms, std::vector<RealmHandle>& deletedRealms);

        uint32 GetAccountId() const { return _accountInfo->Id; }
        uint32 GetGameAccountId() const { return _gameAccountInfo->Id; }

        bool IsToonOnline() const { return _toonOnline; }
        void SetToonOnline(bool online) { _toonOnline = online; }

        bool IsSubscribedToRealmListUpdates() const { return _subscribedToRealmListUpdates; }

        void AsyncWrite(ServerPacket* packet);

    protected:
        void ReadHandler() override;

    private:
        void _SetVSFields(std::string const& rI);

        typedef bool(Session::*ModuleHandler)(BitStream* dataStream, ServerPacket** response);
        static ModuleHandler const ModuleHandlers[MODULE_COUNT];

        void CheckIpCallback(PreparedQueryResult result);
        void HandleLogonRequestCallback(PreparedQueryResult result);
        void HandleResumeRequestCallback(PreparedQueryResult result);
        void HandleListSubscribeRequestCallback(PreparedQueryResult result);

        bool HandlePasswordModule(BitStream* dataStream, ServerPacket** response);
        bool HandleSelectGameAccountModule(BitStream* dataStream, ServerPacket** response);
        bool HandleRiskFingerprintModule(BitStream* dataStream, ServerPacket** response);
        bool HandleResumeModule(BitStream* dataStream, ServerPacket** response);
        bool UnhandledModule(BitStream* dataStream, ServerPacket** response);

        WoWRealm::ListUpdate* BuildListUpdate(Realm const* realm) const;
        std::string GetClientInfo() const;

        AccountInfo* _accountInfo;
        GameAccountInfo* _gameAccountInfo;      // Points at selected game account (inside _gameAccounts)
        std::vector<GameAccountInfo> _gameAccounts;

        std::string _locale;
        std::string _os;
        uint32 _build;

        std::string _ipCountry;

        BigNumber N;
        BigNumber g;
        BigNumber k;

        BigNumber I;
        BigNumber s;
        BigNumber v;

        BigNumber b;
        BigNumber B;
        BigNumber K;    // session key

        BigNumber _reconnectProof;

        std::queue<ModuleType> _modulesWaitingForData;

        struct EncryptableBuffer
        {
            MessageBuffer Buffer;
            bool Encrypt;
        };

        MPSCQueue<EncryptableBuffer> _bufferQueue;

        PacketCrypt _crypt;
        bool _authed;
        bool _subscribedToRealmListUpdates;
        bool _toonOnline;

        QueryCallbackProcessor _queryProcessor;
    };

}

#endif // Session_h__
