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

#ifndef TRINITYCORE_TALENT_PACKETS_H
#define TRINITYCORE_TALENT_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include "PacketUtilities.h"
#include "SharedDefines.h"
#include <variant>

namespace WorldPackets::Talent
{
struct TalentEntry
{
    uint32 TalentID = 0;
    int8 Rank = 0;
};

struct TalentGroupInfo
{
    std::vector<TalentEntry> Talents;
    std::array<uint16, MAX_GLYPH_SLOT_INDEX> GlyphIDs;
};

struct TalentInfoUpdate
{
    uint32 UnspentTalentPoints = 0;
    uint8 ActiveGroup = 0;
    std::vector<TalentGroupInfo> TalentGroups;
};

struct PetTalentInfoUpdate
{
    uint32 UnspentTalentPoints = 0;
    std::vector<TalentEntry> Talents;
};

class UpdateTalentData final : public ServerPacket
{
public:
    explicit UpdateTalentData() : ServerPacket(SMSG_TALENTS_INFO, 50) { }

    WorldPacket const* Write() override;

    std::variant<TalentInfoUpdate, PetTalentInfoUpdate> Info;
};

struct LearnTalentEntry
{
    uint32 TalentID = 0;
    uint32 Rank = 0;
};

class LearnTalent final : public ClientPacket
{
public:
    explicit LearnTalent(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_TALENT, std::move(packet)) { }

    void Read() override;

    LearnTalentEntry Talent;
};

class LearnPreviewTalents final : public ClientPacket
{
public:
    explicit LearnPreviewTalents(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PREVIEW_TALENTS, std::move(packet)) { }

    void Read() override;

    Array<LearnTalentEntry, 150> Talents;
};

class RespecWipeConfirm final : public ServerPacket
{
public:
    explicit RespecWipeConfirm() : ServerPacket(MSG_TALENT_WIPE_CONFIRM, 8 + 4) { }

    WorldPacket const* Write() override;

    ObjectGuid RespecMaster;
    uint32 Cost = 0;
};

class ConfirmRespecWipe final : public ClientPacket
{
public:
    explicit ConfirmRespecWipe(WorldPacket&& packet) : ClientPacket(MSG_TALENT_WIPE_CONFIRM, std::move(packet)) { }

    void Read() override;

    ObjectGuid RespecMaster;
};

class TalentsInvoluntarilyReset final : public ServerPacket
{
public:
    explicit TalentsInvoluntarilyReset(bool isPetTalents) : ServerPacket(SMSG_TALENTS_INVOLUNTARILY_RESET, 1), IsPetTalents(isPetTalents ? 1 : 0) { }

    WorldPacket const* Write() override;

    uint8 IsPetTalents = 0;
};

ByteBuffer& operator<<(ByteBuffer& data, TalentInfoUpdate const& talentInfo);
}

#endif // TRINITYCORE_TALENT_PACKETS_H
