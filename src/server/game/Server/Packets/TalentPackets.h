/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TalentPackets_h__
#define TalentPackets_h__

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace Talent
    {
        struct TalentGroupInfo
        {
            uint32 SpecID;
            std::vector<uint16> TalentIDs;
            uint16 GlyphIDs[MAX_GLYPH_SLOT_INDEX];
        };

        struct TalentInfoUpdate
        {
            uint8 ActiveGroup;
            std::vector<TalentGroupInfo> TalentGroups;
        };

        class UpdateTalentData final : public ServerPacket
        {
        public:
            UpdateTalentData() : ServerPacket(SMSG_UPDATE_TALENT_DATA, 2+4+4+4+12) { }

            WorldPacket const* Write() override;

            TalentInfoUpdate Info;
        };

        class SetSpecialization final : public ClientPacket
        {
        public:
            SetSpecialization(WorldPacket&& packet) : ClientPacket(CMSG_SET_SPECIALIZATION, std::move(packet)) { }

            void Read() override;

            uint32 SpecGroupIndex = 0;
        };

        class LearnTalents final : public ClientPacket
        {
        public:
            LearnTalents(WorldPacket&& packet) : ClientPacket(std::move(packet))
            {
                ASSERT(packet.GetOpcode() == CMSG_LEARN_TALENTS);
            }

            void Read() override;
            std::vector<uint16> Talents;

        };
    }
}

#endif // TalentPackets_h__
