/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef InstancePackets_h__
#define InstancePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Instance
    {
        class UpdateLastInstance final : public ServerPacket
        {
        public:
            UpdateLastInstance() : ServerPacket(SMSG_UPDATE_LAST_INSTANCE, 4) { }

            WorldPacket const* Write() override;

            uint32 MapID = 0;
        };

        // This packet is no longer sent - it is only here for documentation purposes
        class UpdateInstanceOwnership final : public ServerPacket
        {
        public:
            UpdateInstanceOwnership() : ServerPacket(SMSG_UPDATE_INSTANCE_OWNERSHIP, 4) { }

            WorldPacket const* Write() override;

            int32 IOwnInstance = 0; // Used to control whether "Reset all instances" button appears on the UI - Script_CanShowResetInstances()
                                    // but it has been deperecated in favor of simply checking group leader, being inside an instance or using dungeon finder
        };

        struct InstanceLockInfos
        {
            uint64 InstanceID = 0u;
            uint32 MapID = 0u;
            uint32 DifficultyID = 0u;
            int32 TimeRemaining = 0;
            uint32 CompletedMask = 0u;

            bool Locked = false;
            bool Extended = false;
        };

        class InstanceInfo final : public ServerPacket
        {
        public:
            InstanceInfo() : ServerPacket(SMSG_INSTANCE_INFO, 4) { }

            WorldPacket const* Write() override;

            std::vector<InstanceLockInfos> LockList;
        };

        class ResetInstances final : public ClientPacket
        {
        public:
            ResetInstances(WorldPacket&& packet) : ClientPacket(CMSG_RESET_INSTANCES, std::move(packet)) { }

            void Read() override { }
        };

        class InstanceReset final : public ServerPacket
        {
        public:
            InstanceReset() : ServerPacket(SMSG_INSTANCE_RESET, 4) { }

            WorldPacket const* Write() override;

            uint32 MapID = 0;
        };

        class InstanceResetFailed final : public ServerPacket
        {
        public:
            InstanceResetFailed() : ServerPacket(SMSG_INSTANCE_RESET_FAILED, 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 MapID = 0;
            uint8 ResetFailedReason = 0;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Instance::InstanceLockInfos const& lockInfos);

#endif // InstancePackets_h__
