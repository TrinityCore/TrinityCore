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
#include "PacketOperators.h"

namespace WorldPackets::Talent
{
ByteBuffer& operator>>(ByteBuffer& data, PvPTalent& pvpTalent)
{
    data >> pvpTalent.PvPTalentID;
    data >> pvpTalent.Slot;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PvPTalent const& pvpTalent)
{
    data << uint16(pvpTalent.PvPTalentID);
    data << uint8(pvpTalent.Slot);

    return data;
}

WorldPacket const* UpdateTalentData::Write()
{
    _worldPacket << uint8(Info.ActiveGroup);
    _worldPacket << uint32(Info.PrimarySpecialization);
    _worldPacket << Size<uint32>(Info.TalentGroups);

    for (TalentGroupInfo& talentGroupInfo : Info.TalentGroups)
    {
        _worldPacket << uint32(talentGroupInfo.SpecID);
        _worldPacket << Size<uint32>(talentGroupInfo.TalentIDs);
        _worldPacket << Size<uint32>(talentGroupInfo.PvPTalents);

        for (uint16 talent : talentGroupInfo.TalentIDs)
            _worldPacket << uint16(talent);

        for (PvPTalent talent : talentGroupInfo.PvPTalents)
            _worldPacket << talent;
    }

    return &_worldPacket;
}

void LearnTalents::Read()
{
    _worldPacket >> BitsSize<6>(Talents);
    for (uint16& talent : Talents)
        _worldPacket >> talent;
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
    _worldPacket << Bits<4>(Reason);
    _worldPacket << int32(SpellID);
    _worldPacket << Size<uint32>(Talents);
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
    _worldPacket << Size<uint32>(Glyphs);
    for (GlyphBinding const& glyph : Glyphs)
        _worldPacket << glyph;

    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void LearnPvpTalents::Read()
{
    _worldPacket >> Size<uint32>(Talents);
    for (PvPTalent& pvpTalent : Talents)
        _worldPacket >> pvpTalent;
}

WorldPacket const* LearnPvpTalentFailed::Write()
{
    _worldPacket << Bits<4>(Reason);
    _worldPacket << int32(SpellID);
    _worldPacket << Size<uint32>(Talents);
    for (PvPTalent pvpTalent : Talents)
        _worldPacket << pvpTalent;

    return &_worldPacket;
}
}
