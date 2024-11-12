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
ByteBuffer& operator>>(ByteBuffer& data, TalentInfo& talent)
{
    data >> talent.TalentID;
    data >> talent.Rank;
    return data;
}

WorldPacket const* UpdateTalentData::Write()
{
    _worldPacket << Info;

    return &_worldPacket;
}

void LearnTalent::Read()
{
    _worldPacket >> TalentID;
    _worldPacket >> Rank;
}

WorldPacket const* RespecWipeConfirm::Write()
{
    _worldPacket << int8(RespecType);
    _worldPacket << uint32(Cost);
    _worldPacket << RespecMaster;
    return &_worldPacket;
}

void ConfirmRespecWipe::Read()
{
    _worldPacket >> RespecMaster;
    _worldPacket >> RespecType;
}

WorldPacket const* LearnTalentFailed::Write()
{
    _worldPacket.WriteBits(Reason, 4);
    _worldPacket << int32(SpellID);
    _worldPacket << uint32(Talents.size());
    if (!Talents.empty())
        _worldPacket.append(Talents.data(), Talents.size());

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GlyphBinding const& glyphBinding)
{
    data << uint32(glyphBinding.SpellID);
    data << uint16(glyphBinding.GlyphID);
    return data;
}

WorldPacket const* ActiveGlyphs::Write()
{
    _worldPacket << uint32(Glyphs.size());
    for (GlyphBinding const& glyph : Glyphs)
        _worldPacket << glyph;

    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void LearnPreviewTalents::Read()
{
    Talents.resize(_worldPacket.read<uint32>());
    _worldPacket >> TabIndex;

    for (TalentInfo& talent : Talents)
        _worldPacket >> talent;
}

void SetPrimaryTalentTree::Read()
{
    _worldPacket >> TabIndex;
}

ByteBuffer& operator<<(ByteBuffer& data, TalentInfoUpdate const& talentInfoUpdate)
{
    data << uint32(talentInfoUpdate.UnspentTalentPoints);
    data << uint8(talentInfoUpdate.ActiveGroup);
    data << uint32(talentInfoUpdate.TalentGroups.size());

    for (TalentGroupInfo const& talentGroupInfo : talentInfoUpdate.TalentGroups)
        data << talentGroupInfo;

    data << Bits<1>(talentInfoUpdate.IsPetTalents);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TalentGroupInfo const& talentGroupInfo)
{
    data << uint8(talentGroupInfo.Talents.size());
    data << uint32(talentGroupInfo.Talents.size());

    data << uint8(talentGroupInfo.Glyphs.size());
    data << uint32(talentGroupInfo.Glyphs.size());

    data << uint8(talentGroupInfo.SpecID);
    data << uint32(talentGroupInfo.PrimarySpecialization);

    for (TalentInfo const& talent : talentGroupInfo.Talents)
        data << talent;

    data.append(talentGroupInfo.Glyphs.data(), talentGroupInfo.Glyphs.size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TalentInfo const& talentInfo)
{
    data << uint32(talentInfo.TalentID);
    data << uint32(talentInfo.Rank);
    return data;
}
}
