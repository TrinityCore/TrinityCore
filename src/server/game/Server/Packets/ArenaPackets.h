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

#ifndef ArenaPackets_h__
#define ArenaPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Arena
    {
        class PvpSeason final : public ServerPacket
        {
        public:
            PvpSeason() : ServerPacket(SMSG_PVP_SEASON, 4 + 4 + 4 + 4 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            int32 Unk0 = 0;
            int32 Unk1 = 0;
            int32 CurrentArenaSeason = 0;
            int32 PreviousArenaSeason = 0;
            int32 CurrentArenaUsesTeams = 0;
            int32 PreviousArenaUsesTeams = 0;
            int32 Unk6 = 0;
            bool Unk7 = 0;
            bool Unk8 = 0;
            bool Unk9 = 0;
        };
    }
}

#endif // ArenaPackets_h__
