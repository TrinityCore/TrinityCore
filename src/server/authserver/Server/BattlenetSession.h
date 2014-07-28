/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _BATTLENETSOCKET_H
#define _BATTLENETSOCKET_H

#include "BattlenetPackets.h"
#include "BattlenetPacketCrypt.h"
#include "Socket.h"
#include "BigNumber.h"
#include <memory>
#include <boost/asio/ip/tcp.hpp>

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

    class Session : public Socket<Session, ServerPacket*>
    {
        typedef Socket<Session, ServerPacket*> BattlenetSocket;

    public:
        explicit Session(tcp::socket&& socket);
        ~Session();

        typedef bool(Session::*PacketHandler)(PacketHeader& socket, BitStream& packet);

        // Auth
        bool HandleAuthChallenge(PacketHeader& header, BitStream& packet);
        bool HandleAuthReconnect(PacketHeader& header, BitStream& packet);
        bool HandleAuthProofResponse(PacketHeader& header, BitStream& packet);

        // Creep
        bool HandlePing(PacketHeader& header, BitStream& packet);
        bool HandleEnableEncryption(PacketHeader& header, BitStream& packet);
        bool HandleDisconnect(PacketHeader& header, BitStream& packet);

        // WoW
        bool HandleRealmUpdateSubscribe(PacketHeader& header, BitStream& packet);
        bool HandleRealmJoinRequest(PacketHeader& header, BitStream& packet);

        void Start() override;

        void AsyncWrite(ServerPacket* packet);

    protected:
        void ReadHeaderHandler(boost::system::error_code error, size_t transferedBytes) override;
        void ReadDataHandler(boost::system::error_code /*error*/, size_t /*transferedBytes*/) override { }

    private:
        void _SetVSFields(std::string const& rI);

        typedef bool(Session::*ModuleHandler)(BitStream* dataStream, ServerPacket** response);
        static ModuleHandler const ModuleHandlers[MODULE_COUNT];

        bool HandlePasswordModule(BitStream* dataStream, ServerPacket** response);
        bool HandleSelectGameAccountModule(BitStream* dataStream, ServerPacket** response);
        bool HandleRiskFingerprintModule(BitStream* dataStream, ServerPacket** response);
        bool HandleResumeModule(BitStream* dataStream, ServerPacket** response);
        bool UnhandledModule(BitStream* dataStream, ServerPacket** response);

        uint32 _accountId;
        std::string _accountName;
        std::string _locale;
        std::string _os;
        uint32 _build;
        uint32 _gameAccountId;
        uint8 _gameAccountIndex;
        AccountTypes _accountSecurityLevel;

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

        PacketCrypt _crypt;
        bool _authed;
    };

}

#endif // _BATTLENETSOCKET_H
