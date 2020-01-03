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

#ifndef WorldStatePackets_h__
#define WorldStatePackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates final : public ServerPacket
        {
        public:
            struct WorldStateInfo
            {
                WorldStateInfo(int32 variableID, int32 value) : VariableID(variableID), Value(value) { }

                int32 VariableID;
                int32 Value;
            };

            InitWorldStates();

            WorldPacket const* Write() override;

            int32 MapID = 0;
            int32 ZoneID = 0;
            int32 AreaID = 0;

            std::vector<WorldStateInfo> Worldstates;
        };

        class UpdateWorldState final : public ServerPacket
        {
        public:
            UpdateWorldState() : ServerPacket(SMSG_UPDATE_WORLD_STATE, 4 + 4) { }

            WorldPacket const* Write() override;

            int32 VariableID = 0;
            int32 Value = 0;
        };
    }
}

#endif // WorldStatePackets_h__
