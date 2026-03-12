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

#include "TalentPackets.h"

namespace WorldPackets::Talent
{
ByteBuffer& operator<<(ByteBuffer& data, TalentEntry const& talentEntry)
{
    data << uint32(talentEntry.TalentID);
    data << int8(talentEntry.Rank);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TalentGroupInfo const& talentGroup)
{
    data << uint8(talentGroup.Talents.size());

    for (TalentEntry const& talentEntry : talentGroup.Talents)
        data << talentEntry;

    data << uint8(talentGroup.GlyphIDs.size());

    for (uint16 glyphID : talentGroup.GlyphIDs)
        data << uint16(glyphID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TalentInfoUpdate const& talentInfo)
{
    data << uint32(talentInfo.UnspentTalentPoints);
    data << uint8(talentInfo.TalentGroups.size());
    data << uint8(talentInfo.ActiveGroup);

    for (TalentGroupInfo const& talentGroup : talentInfo.TalentGroups)
        data << talentGroup;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PetTalentInfoUpdate const& petTalentInfo)
{
    data << uint32(petTalentInfo.UnspentTalentPoints);
    data << uint8(petTalentInfo.Talents.size());

    for (TalentEntry const& talentEntry : petTalentInfo.Talents)
        data << talentEntry;

    return data;
}

WorldPacket const* UpdateTalentData::Write()
{
    _worldPacket << uint8(Info.index());

    switch (Info.index())
    {
        case 0:
            _worldPacket << std::get<0>(Info);
            break;
        case 1:
            _worldPacket << std::get<1>(Info);
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPacket const* RespecWipeConfirm::Write()
{
    _worldPacket << RespecMaster;
    _worldPacket << uint32(Cost);

    return &_worldPacket;
}

void ConfirmRespecWipe::Read()
{
    _worldPacket >> RespecMaster;
}

WorldPacket const* InvoluntarilyReset::Write()
{
    _worldPacket << uint8(IsPetTalents);

    return &_worldPacket;
}
}
