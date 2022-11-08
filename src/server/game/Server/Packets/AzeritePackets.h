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

#ifndef AzeriteItemPackets_h__
#define AzeriteItemPackets_h__

#include "Packet.h"
#include "ItemDefines.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Azerite
    {
        class PlayerAzeriteItemGains final : public ServerPacket
        {
        public:
            PlayerAzeriteItemGains() : ServerPacket(SMSG_PLAYER_AZERITE_ITEM_GAINS, 16 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid ItemGUID;
            uint64 XP = 0;
        };

        class OpenHeartForge final : public ServerPacket
        {
        public:
            OpenHeartForge() : ServerPacket(SMSG_OPEN_HEART_FORGE, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid ForgeGUID;
        };

        class CloseHeartForge final : public ServerPacket
        {
        public:
            CloseHeartForge() : ServerPacket(SMSG_CLOSE_HEART_FORGE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AzeriteEssenceUnlockMilestone final : public ClientPacket
        {
        public:
            AzeriteEssenceUnlockMilestone(WorldPacket&& packet) : ClientPacket(CMSG_AZERITE_ESSENCE_UNLOCK_MILESTONE, std::move(packet)) { }

            void Read() override;

            int32 AzeriteItemMilestonePowerID = 0;
        };

        class AzeriteEssenceActivateEssence final : public ClientPacket
        {
        public:
            AzeriteEssenceActivateEssence(WorldPacket&& packet) : ClientPacket(CMSG_AZERITE_ESSENCE_ACTIVATE_ESSENCE, std::move(packet)) { }

            void Read() override;

            int32 AzeriteEssenceID = 0;
            uint8 Slot = 0;
        };

        class ActivateEssenceFailed final : public ServerPacket
        {
        public:
            ActivateEssenceFailed() : ServerPacket(SMSG_ACTIVATE_ESSENCE_FAILED, 1 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            AzeriteEssenceActivateResult Reason = AzeriteEssenceActivateResult::None;
            int32 Arg = 0;
            int32 AzeriteEssenceID = 0;
            Optional<uint8> Slot;
        };

        class AzeriteEmpoweredItemViewed final : public ClientPacket
        {
        public:
            AzeriteEmpoweredItemViewed(WorldPacket&& packet) : ClientPacket(CMSG_AZERITE_EMPOWERED_ITEM_VIEWED, std::move(packet)) { }

            void Read() override;

            ObjectGuid ItemGUID;
        };

        class AzeriteEmpoweredItemSelectPower final : public ClientPacket
        {
        public:
            AzeriteEmpoweredItemSelectPower(WorldPacket&& packet) : ClientPacket(CMSG_AZERITE_EMPOWERED_ITEM_SELECT_POWER, std::move(packet)) { }

            void Read() override;

            int32 Tier = 0;
            int32 AzeritePowerID = 0;
            uint8 ContainerSlot = 0;
            uint8 Slot = 0;
        };

        class TC_GAME_API PlayerAzeriteItemEquippedStatusChanged final : public ServerPacket
        {
        public:
            PlayerAzeriteItemEquippedStatusChanged() : ServerPacket(SMSG_PLAYER_AZERITE_ITEM_EQUIPPED_STATUS_CHANGED, 1) { }

            WorldPacket const* Write() override;

            bool IsHeartEquipped = false;
        };

        class AzeriteRespecNPC final : public ServerPacket
        {
        public:
            AzeriteRespecNPC(ObjectGuid npcGuid) : ServerPacket(SMSG_AZERITE_RESPEC_NPC, 1), NpcGUID(npcGuid) { }

            WorldPacket const* Write() override;

            ObjectGuid NpcGUID;
        };
    }
}

#endif // AzeriteItemPackets_h__
