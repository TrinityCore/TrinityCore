/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef ReferAFriendPackets_h__
#define ReferAFriendPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace RaF
    {
        class AcceptLevelGrant final : public ClientPacket
        {
        public:
            AcceptLevelGrant(WorldPacket&& packet) : ClientPacket(CMSG_ACCEPT_LEVEL_GRANT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Granter;
        };

        class GrantLevel final : public ClientPacket
        {
        public:
            GrantLevel(WorldPacket&& packet) : ClientPacket(CMSG_GRANT_LEVEL, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
        };

        class ProposeLevelGrant final : public ServerPacket
        {
        public:
            ProposeLevelGrant() : ServerPacket(SMSG_PROPOSE_LEVEL_GRANT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Sender;
        };

        class ReferAFriendFailure final : public ServerPacket
        {
        public:
            ReferAFriendFailure() : ServerPacket(SMSG_REFER_A_FRIEND_FAILURE, 1 + 4) { }

            WorldPacket const* Write() override;

            std::string Str;
            int32 Reason = 0;
        };
    }
}

#endif // ReferAFriendPackets_h__
