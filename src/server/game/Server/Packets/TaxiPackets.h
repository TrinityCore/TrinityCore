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

#ifndef TaxiPackets_h__
#define TaxiPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "DBCEnums.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Taxi
    {
        class TaxiNodeStatusQuery final : public ClientPacket
        {
        public:
            TaxiNodeStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_NODE_STATUS_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid UnitGUID;
        };

        class TaxiNodeStatus final : public ServerPacket
        {
        public:
            TaxiNodeStatus() : ServerPacket(SMSG_TAXI_NODE_STATUS, 16 + 1) { }

            WorldPacket const* Write() override;

            uint8 Status = 0; // replace with TaxiStatus enum
            ObjectGuid Unit;
        };

        struct ShowTaxiNodesWindowInfo
        {
            ObjectGuid UnitGUID;
            int32 CurrentNode = 0;
        };

        class ShowTaxiNodes final : public ServerPacket
        {
        public:
            ShowTaxiNodes() : ServerPacket(SMSG_SHOW_TAXI_NODES) { }

            WorldPacket const* Write() override;

            Optional<ShowTaxiNodesWindowInfo> WindowInfo;
            TaxiMask const* CanLandNodes = nullptr; // Nodes known by player
            TaxiMask const* CanUseNodes = nullptr;  // Nodes available for use - this can temporarily disable a known node
        };

        class EnableTaxiNode final : public ClientPacket
        {
        public:
            EnableTaxiNode(WorldPacket&& packet) : ClientPacket(CMSG_ENABLE_TAXI_NODE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class TaxiQueryAvailableNodes final : public ClientPacket
        {
        public:
            TaxiQueryAvailableNodes(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_QUERY_AVAILABLE_NODES, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class ActivateTaxi final : public ClientPacket
        {
        public:
            ActivateTaxi(WorldPacket&& packet) : ClientPacket(CMSG_ACTIVATE_TAXI, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vendor;
            uint32 Node = 0;
            uint32 GroundMountID = 0;
            uint32 FlyingMountID = 0;
        };

        class NewTaxiPath final : public ServerPacket
        {
        public:
            NewTaxiPath() : ServerPacket(SMSG_NEW_TAXI_PATH, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class ActivateTaxiReply final : public ServerPacket
        {
        public:
            ActivateTaxiReply() : ServerPacket(SMSG_ACTIVATE_TAXI_REPLY, 4) { }

            WorldPacket const* Write() override;

            uint8 Reply = 0;
        };

        class TaxiRequestEarlyLanding final : public ClientPacket
        {
        public:
            TaxiRequestEarlyLanding(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_REQUEST_EARLY_LANDING, std::move(packet)) { }

            void Read() override { }
        };
    }
}

#endif // TaxiPackets_h__
