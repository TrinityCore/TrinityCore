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

#include "ArchaeologyPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Archaeology::ResearchHistory const& researchHistory)
{
    data << int32(researchHistory.ProjectID);
    data << int32(researchHistory.CompletionCount);
    data << uint32(researchHistory.FirstCompleted);

    return data;
}

WorldPacket const* WorldPackets::Archaeology::SetupResearchHistory::Write()
{
    _worldPacket.WriteBits(History.size(), 22);
    _worldPacket.FlushBits();

    for (WorldPackets::Archaeology::ResearchHistory const& history : History)
        _worldPacket << history;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Archaeology::ResearchComplete::Write()
{
    _worldPacket << Research.FirstCompleted;
    _worldPacket << Research.CompletionCount;
    _worldPacket << Research.ProjectID;

    return &_worldPacket;
}
