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
        class AzeriteXpGain final : public ServerPacket
        {
        public:
            AzeriteXpGain() : ServerPacket(SMSG_AZERITE_XP_GAIN, 16 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid ItemGUID;
            uint64 XP = 0;
        };

        class AzeriteEssenceForgeOpened final : public ServerPacket
        {
        public:
            AzeriteEssenceForgeOpened() : ServerPacket(SMSG_AZERITE_ESSENCE_FORGE_OPENED, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid ForgeGUID;
        };

        class AzeriteEssenceForgeClose final : public ServerPacket
        {
        public:
            AzeriteEssenceForgeClose() : ServerPacket(SMSG_AZERITE_ESSENCE_FORGE_CLOSE, 0) { }

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

        class AzeriteEssenceSelectionResult final : public ServerPacket
        {
        public:
            AzeriteEssenceSelectionResult() : ServerPacket(SMSG_AZERITE_ESSENCE_SELECTION_RESULT, 0) { }

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

        class TC_GAME_API AzeriteEmpoweredItemEquippedStatusChanged final : public ServerPacket
        {
        public:
            AzeriteEmpoweredItemEquippedStatusChanged() : ServerPacket(SMSG_AZERITE_EMPOWERED_ITEM_EQUIPPED_STATUS_CHANGED, 1) { }

            WorldPacket const* Write() override;

            bool IsHeartEquipped = false;
        };

        class AzeriteEmpoweredItemRespecOpen final : public ServerPacket
        {
        public:
            AzeriteEmpoweredItemRespecOpen(ObjectGuid npcGuid) : ServerPacket(SMSG_AZERITE_EMPOWERED_ITEM_RESPEC_OPEN, 1), NpcGUID(npcGuid) { }

            WorldPacket const* Write() override;

            ObjectGuid NpcGUID;
        };
    }
}

#endif // AzeriteItemPackets_h__
