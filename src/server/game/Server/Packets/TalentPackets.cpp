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

#include "TalentPackets.h"

WorldPacket const* WorldPackets::Talent::UpdateTalentData::Write()
{
    _worldPacket.WriteBits (Info.TalentGroups.size(), 19);

    for (auto& talentGroupInfo : Info.TalentGroups)
    {
        _worldPacket.WriteBits (talentGroupInfo.TalentIDs.size(), 23);
    }

    for (auto& talentGroupInfo : Info.TalentGroups)
    {
        for (uint16 talentID : talentGroupInfo.TalentIDs)
            _worldPacket << uint16 (talentID);

        for (uint32 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
            _worldPacket << uint16 (talentGroupInfo.GlyphIDs[i]);

        _worldPacket << talentGroupInfo.SpecID;
    }

    _worldPacket << uint8 (Info.ActiveGroup);

    return &_worldPacket;
}

void WorldPackets::Talent::SetSpecialization::Read()
{
    _worldPacket >> SpecGroupIndex;
}


void WorldPackets::Talent::LearnTalents::Read()
{
    uint32 count;
    _worldPacket >> count;

    for (uint32 i = 0; i < count; ++i)
    {
        uint16 talent;
        _worldPacket >> talent;
        Talents.push_back(talent);
    }
}