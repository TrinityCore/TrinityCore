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

#ifndef TRINITYCORE_CLIENT_CONFIG_PACKETS_H
#define TRINITYCORE_CLIENT_CONFIG_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include <span>

struct BannedAddon;
struct SecureAddonInfo;

namespace WorldPackets
{
    namespace ClientConfig
    {
        class AddonInfo final : public ServerPacket
        {
            static std::array<uint8, 256> const PublicKey;

        public:
            explicit AddonInfo() : ServerPacket(SMSG_ADDON_INFO) { }

            WorldPacket const* Write() override;

            std::span<SecureAddonInfo const> Addons;
            std::span<BannedAddon const> BannedAddons;
        };

        class ClientCacheVersion final : public ServerPacket
        {
        public:
            explicit ClientCacheVersion() : ServerPacket(SMSG_CLIENTCACHE_VERSION, 4) { }

            WorldPacket const* Write() override;

            uint32 CacheVersion = 0;
        };

        class RequestAccountData final : public ClientPacket
        {
        public:
            explicit RequestAccountData(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_ACCOUNT_DATA, std::move(packet)) { }

            void Read() override;

            int32 DataType = 0; ///< @see enum AccountDataType
        };

        class UpdateAccountData final : public ServerPacket
        {
        public:
            explicit UpdateAccountData() : ServerPacket(SMSG_UPDATE_ACCOUNT_DATA) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint32 Time    = 0; ///< UnixTime
            uint32 Size    = 0; ///< decompressed size
            int32 DataType = 0; ///< @see enum AccountDataType
            std::vector<uint8> CompressedData;
        };

        class UserClientUpdateAccountData final : public ClientPacket
        {
        public:
            explicit UserClientUpdateAccountData(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_ACCOUNT_DATA, std::move(packet)) { }

            void Read() override;

            uint32 Time    = 0; ///< UnixTime
            uint32 Size    = 0; ///< decompressed size
            int32 DataType = 0; ///< @see enum AccountDataType
            std::span<uint8 const> CompressedData;
        };

        class UpdateAccountDataComplete final : public ServerPacket
        {
        public:
            explicit UpdateAccountDataComplete() : ServerPacket(SMSG_UPDATE_ACCOUNT_DATA_COMPLETE, 4 + 4) { }

            WorldPacket const* Write() override;

            int32 DataType = 0; ///< @see enum AccountDataType
            int32 Result = 0;
        };
    }
}

#endif // TRINITYCORE_CLIENT_CONFIG_PACKETS_H
