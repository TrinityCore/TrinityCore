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

#include "UpdateData.h"
#include "Errors.h"
#include "Opcodes.h"
#include "World.h"
#include "WorldPacket.h"

UpdateData::UpdateData(uint16 map) : m_map(map), m_blockCount(0) { }

void UpdateData::AddOutOfRangeGUID(GuidSet& guids)
{
    m_outOfRangeGUIDs.insert(guids.begin(), guids.end());
}

void UpdateData::AddOutOfRangeGUID(ObjectGuid guid)
{
    m_outOfRangeGUIDs.insert(guid);
}

void UpdateData::AddUpdateBlock(const ByteBuffer &block)
{
    m_data.append(block);
    ++m_blockCount;
}

bool UpdateData::BuildPacket(WorldPacket* packet)
{
    ASSERT(packet->empty());                                // shouldn't happen
    packet->Initialize(SMSG_UPDATE_OBJECT, 2 + 4 + (m_outOfRangeGUIDs.empty() ? 0 : 1 + 4 + 9 * m_outOfRangeGUIDs.size()) + m_data.wpos());

    *packet << uint16(m_map);
    *packet << uint32(m_blockCount + (m_outOfRangeGUIDs.empty() ? 0 : 1));

    if (!m_outOfRangeGUIDs.empty())
    {
        *packet << uint8(UPDATETYPE_OUT_OF_RANGE_OBJECTS);
        *packet << uint32(m_outOfRangeGUIDs.size());

        for (GuidSet::const_iterator i = m_outOfRangeGUIDs.begin(); i != m_outOfRangeGUIDs.end(); ++i)
            *packet << i->WriteAsPacked();
    }

    packet->append(m_data);
    return true;
}

void UpdateData::Clear()
{
    m_data.clear();
    m_outOfRangeGUIDs.clear();
    m_blockCount = 0;
    m_map = 0;
}
