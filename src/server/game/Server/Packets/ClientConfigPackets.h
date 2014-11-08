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

#ifndef TRINITYCORE_CLIENT_CONFIG_PACKETS_H
#define TRINITYCORE_CLIENT_CONFIG_PACKETS_H

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
    }
}

#endif // TRINITYCORE_CLIENT_CONFIG_PACKETS_H
