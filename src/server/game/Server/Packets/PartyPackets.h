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

#ifndef PartyPackets_h__
#define PartyPackets_h__

#include "Packet.h"

class Player;

namespace WorldPackets
{
    namespace Party
    {
        class PartyInviteClient final : public ClientPacket
        {
        public:
            PartyInviteClient(WorldPacket&& packet) : ClientPacket(CMSG_GROUP_INVITE, std::move(packet)) { }

            void Read() override;

            uint32 ProposedRoles = 0;
            std::string TargetName;
        };

        class PartyInvite final : public ServerPacket
        {
        public:
            PartyInvite() : ServerPacket(SMSG_GROUP_INVITE, 55) { }

            WorldPacket const* Write() override;

            void Initialize(Player const* inviter, uint32 proposedRoles, bool canAccept);

            bool CanAccept = false;

            // Inviter
            std::string InviterName;

            // Lfg
            uint32 ProposedRoles = 0;
            uint32 LfgCompletedMask = 0;
            std::vector<uint32> LfgSlots;
        };
    }
}

#endif // PartyPackets_h__
