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
#include "WorldPacket.h"
#include "Opcodes.h"

UpdateData::UpdateData(uint32 map) : m_map(map), m_blockCount(0) { }

void UpdateData::AddDestroyObject(ObjectGuid guid)
{
    m_destroyGUIDs.insert(guid);
}

void UpdateData::AddOutOfRangeGUID(GuidSet& guids)
{
    m_outOfRangeGUIDs.insert(guids.begin(), guids.end());
}

void UpdateData::AddOutOfRangeGUID(ObjectGuid guid)
{
    m_outOfRangeGUIDs.insert(guid);
}

void UpdateData::AddUpdateBlock(ByteBuffer const& block)
{
    m_data.append(block);
    ++m_blockCount;
}

bool UpdateData::BuildPacket(WorldPacket* packet)
{
    ASSERT(packet->empty());                                // shouldn't happen
    packet->Initialize(SMSG_UPDATE_OBJECT, 4 + 2 + 1 + (2 + 4 + 17 * (m_destroyGUIDs.size() + m_outOfRangeGUIDs.size())) + m_data.wpos());

    *packet << uint32(m_blockCount);
    *packet << uint16(m_map);

    if (packet->WriteBit(!m_outOfRangeGUIDs.empty() || !m_destroyGUIDs.empty()))
    {
        *packet << uint16(m_destroyGUIDs.size());
        *packet << uint32(m_destroyGUIDs.size() + m_outOfRangeGUIDs.size());

        for (ObjectGuid const& destroyGuid : m_destroyGUIDs)
            *packet << destroyGuid;

        for (ObjectGuid const& outOfRangeGuid : m_outOfRangeGUIDs)
            *packet << outOfRangeGuid;
    }

    *packet << uint32(m_data.size());
    packet->append(m_data);
    return true;
}

void UpdateData::Clear()
{
    m_data.clear();
    m_destroyGUIDs.clear();
    m_outOfRangeGUIDs.clear();
    m_blockCount = 0;
    m_map = 0;
}
