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

#ifndef ReferAFriendPackets_h__
#define ReferAFriendPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace RaF
    {
        class RecruitAFriendFailure final : public ServerPacket
        {
        public:
            RecruitAFriendFailure() : ServerPacket(SMSG_RECRUIT_A_FRIEND_FAILURE, 1 + 4) { }

            WorldPacket const* Write() override;

            std::string Str;
            int32 Reason = 0;
        };
    }
}

#endif // ReferAFriendPackets_h__
