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

#ifndef TalentPackets_h__
#define TalentPackets_h__

#include "Packet.h"
#include "DBCEnums.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"

namespace WorldPackets
{
    namespace Talent
    {
        struct PvPTalent
        {
            uint16 PvPTalentID = 0;
            uint8 Slot = 0;
        };

        struct TalentInfo
        {
            uint32 TalentID = 0;
            uint8 Rank = 0;
        };

        struct TalentGroupInfo
        {
            int32 SpecID = 0;
            std::vector<TalentInfo> Talents;
            std::vector<uint16> GlyphIDs;
        };

        class UpdateTalentData final : public ServerPacket
        {
        public:
            UpdateTalentData() : ServerPacket(SMSG_UPDATE_TALENT_DATA, 4 + 1 + 1 + 2 + 2 + 2 + 2 + 2 + 2) { }

            WorldPacket const* Write() override;

            uint32 UnspentTalentPoints = 0;
            uint8 ActiveGroup = 0;
            bool IsPetTalents = false;
            std::vector<TalentGroupInfo> TalentGroupInfos;
        };

        class LearnTalents final : public ClientPacket
        {
        public:
            LearnTalents(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_TALENTS, std::move(packet)) { }

            void Read() override;
            Array<uint16, MAX_TALENT_TIERS> Talents;
        };

        class RespecWipeConfirm final : public ServerPacket
        {
        public:
            RespecWipeConfirm() : ServerPacket(SMSG_RESPEC_WIPE_CONFIRM, 16 + 4 +1) { }

            WorldPacket const* Write() override;

            ObjectGuid RespecMaster;
            uint32 Cost = 0;
            int8 RespecType = 0;
        };

        class ConfirmRespecWipe final : public ClientPacket
        {
        public:
            ConfirmRespecWipe(WorldPacket&& packet) : ClientPacket(CMSG_CONFIRM_RESPEC_WIPE, std::move(packet)) { }

            void Read() override;

            ObjectGuid RespecMaster;
            uint8 RespecType = 0;
        };

        class LearnTalentFailed final : public ServerPacket
        {
        public:
            LearnTalentFailed() : ServerPacket(SMSG_LEARN_TALENT_FAILED, 1 + 4 + 4 + 2 * MAX_TALENT_TIERS) { }

            WorldPacket const* Write() override;

            uint32 Reason = 0;
            int32 SpellID = 0;
            std::vector<uint16> Talents;
        };

        struct GlyphBinding
        {
            GlyphBinding(uint32 spellId = 0, uint16 glyphId = 0) : SpellID(spellId), GlyphID(glyphId) { }

            uint32 SpellID;
            uint16 GlyphID;
        };

        class ActiveGlyphs final : public ServerPacket
        {
        public:
            ActiveGlyphs() : ServerPacket(SMSG_ACTIVE_GLYPHS) { }

            WorldPacket const* Write() override;

            std::vector<GlyphBinding> Glyphs;
            bool IsFullUpdate = false;
        };

        class LearnPvpTalents final : public ClientPacket
        {
        public:
            LearnPvpTalents(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PVP_TALENTS, std::move(packet)) { }

            void Read() override;

            Array<PvPTalent, 4> Talents;
        };

        class LearnPvpTalentFailed final : public ServerPacket
        {
        public:
            LearnPvpTalentFailed() : ServerPacket(SMSG_LEARN_PVP_TALENT_FAILED, 1 + 4 + 4 + (2 + 1)) { }

            WorldPacket const* Write() override;

            uint32 Reason = 0;
            int32 SpellID = 0;
            std::vector<PvPTalent> Talents;
        };

        class LearnTalent final : public ClientPacket
        {
        public:
            LearnTalent(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_TALENT, std::move(packet)) { }

            void Read() override;

            int32 TalentID = 0;
            uint16 RequestedRank = 0;
        };

        class LearnPreviewTalents final : public ClientPacket
        {
        public:
            LearnPreviewTalents(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PREVIEW_TALENTS, std::move(packet)) { }

            void Read() override;

            Array<TalentInfo, 60> Talents;
        };

        class RemoveGlyph final : public ClientPacket
        {
        public:
            RemoveGlyph(WorldPacket&& packet) : ClientPacket(CMSG_REMOVE_GLYPH, std::move(packet)) { }

            void Read() override;

            uint8 GlyphSlot = 0;
        };
    }
}

#endif // TalentPackets_h__
