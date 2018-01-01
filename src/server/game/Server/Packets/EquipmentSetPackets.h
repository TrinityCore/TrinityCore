/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#pragma once

#include "Packet.h"
#include "EquipementSet.h"
#include "ItemPacketsCommon.h"

namespace WorldPackets
{
    namespace EquipmentSet
    {
        class EquipmentSetID final : public ServerPacket
        {
        public:
            EquipmentSetID() : ServerPacket(SMSG_EQUIPMENT_SET_ID, 8 + 4) { }

            WorldPacket const* Write() override;

            uint64 GUID  = 0; ///< Set Identifier
            int32 Type = 0;
            uint32 SetID = 0; ///< Index
        };

        class LoadEquipmentSet final : public ServerPacket
        {
        public:
            LoadEquipmentSet() : ServerPacket(SMSG_LOAD_EQUIPMENT_SET, 4) { }

            WorldPacket const* Write() override;

            std::vector<EquipmentSetInfo::EquipmentSetData const*> SetData;
        };

        class SaveEquipmentSet final : public ClientPacket
        {
        public:
            SaveEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_SAVE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            EquipmentSetInfo::EquipmentSetData Set;
        };

        class DeleteEquipmentSet final : public ClientPacket
        {
        public:
            DeleteEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_DELETE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            uint64 ID = 0;
        };

        class UseEquipmentSet final : public ClientPacket
        {
        public:
            UseEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_USE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            struct EquipmentSetItem
            {
                ObjectGuid Item;
                uint8 ContainerSlot     = 0;
                uint8 Slot              = 0;
            };

            WorldPackets::Item::InvUpdate Inv;
            EquipmentSetItem Items[EQUIPEMENT_SET_SLOTS];
            uint64 GUID = 0; ///< Set Identifier
        };

        class UseEquipmentSetResult final : public ServerPacket
        {
        public:
            UseEquipmentSetResult() : ServerPacket(SMSG_USE_EQUIPMENT_SET_RESULT, 1) { }

            WorldPacket const* Write() override;

            uint64 GUID = 0; ///< Set Identifier
            uint8 Reason = 0;
        };
    }
}
