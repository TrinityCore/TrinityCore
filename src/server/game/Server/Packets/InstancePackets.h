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

        class UpdateInstanceOwnership final : public ServerPacket
        {
        public:
            UpdateInstanceOwnership() : ServerPacket(SMSG_UPDATE_INSTANCE_OWNERSHIP, 4) { }

            WorldPacket const* Write() override;

            int32 IOwnInstance = 0; // Used to control whether "Reset all instances" button appears on the UI - Script_CanShowResetInstances()
                                    // but it has been deperecated in favor of simply checking group leader, being inside an instance or using dungeon finder
        };

        struct InstanceLock
        {
            uint64 InstanceID = 0u;
            uint32 MapID = 0u;
            uint32 Difficulty = 0u;
            int32 TimeRemaining = 0;
            uint32 CompletedMask = 0u;
            bool Heroic = false;
            bool Locked = false;
            bool Extended = false;
        };

        class InstanceInfo final : public ServerPacket
        {
        public:
            InstanceInfo() : ServerPacket(SMSG_INSTANCE_INFO, 4) { }

            WorldPacket const* Write() override;

            std::vector<InstanceLock> LockList;
        };

        class RaidInstanceMessage final : public ServerPacket
        {
        public:
            RaidInstanceMessage() : ServerPacket(SMSG_RAID_INSTANCE_MESSAGE, 1 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            bool Locked = false;
            bool Extended = false;
            uint8 Type = 0;
            uint32 MapID = 0;
            uint32 Difficulty = 0;
            int32 TimeLeft = 0;
        };

        class PendingRaidLock final : public ServerPacket
        {
        public:
            PendingRaidLock() : ServerPacket(SMSG_PENDING_RAID_LOCK, 4 + 4 + 1 + 1) { }

            WorldPacket const* Write() override;

            int32 TimeUntilLock = 0;
            uint32 CompletedMask = 0;
            bool Extending = false;
            bool WarningOnly = false;
        };

        class InstanceSaveCreated final : public ServerPacket
        {
        public:
            InstanceSaveCreated() : ServerPacket(SMSG_INSTANCE_SAVE_CREATED, 4) { }

            WorldPacket const* Write() override;

            bool Gm = false;
        };

        class RaidGroupOnly final : public ServerPacket
        {
        public:
            RaidGroupOnly() : ServerPacket(SMSG_RAID_GROUP_ONLY, 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 Reason = 0;
            int32 Delay = 0;
        };

        class UpdateInstanceEncounterUnit final : public ServerPacket
        {
        public:
            UpdateInstanceEncounterUnit() : ServerPacket(SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT, 4 + 8 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 Type = 0;
            ObjectGuid Unit;
            uint8 Param1 = 0;
            uint8 Param2 = 0;
        };

        class UpdateDungeonEncounterForLoot final : public ServerPacket
        {
        public:
            UpdateDungeonEncounterForLoot() : ServerPacket(SMSG_UPDATE_DUNGEON_ENCOUNTER_FOR_LOOT, 0) { }

            WorldPacket const* Write() override;
        };
    }
}

#endif // InstancePackets_h__
