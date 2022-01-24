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

#ifndef AchievementPackets_h__
#define AchievementPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Achievement
    {
        class CriteriaUpdate final : public ServerPacket
        {
        public:
            CriteriaUpdate() : ServerPacket(SMSG_CRITERIA_UPDATE, 33) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            uint64 Quantity = 0;
            uint32 CurrentTime = 0;
            int32 Flags = 0;
            int32 CriteriaID = 0;
            uint32 ElapsedTime = 0;
            uint32 CreationTime = 0;
        };
    }
}

#endif // AchievementPackets_h__
