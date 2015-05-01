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
    }
}

#endif // InstancePackets_h__
