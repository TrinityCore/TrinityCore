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

#ifndef TRINITYCORE_UPDATE_DATA_H
#define TRINITYCORE_UPDATE_DATA_H

#include "ByteBuffer.h"
#include "Define.h"
#include "FlatSet.h"
#include "ObjectGuid.h"

class WorldPacket;

enum OBJECT_UPDATE_TYPE
{
    UPDATETYPE_VALUES               = 0,
    UPDATETYPE_CREATE_OBJECT        = 1,
    UPDATETYPE_CREATE_OBJECT2       = 2,
    UPDATETYPE_OUT_OF_RANGE_OBJECTS = 3,
};

class UpdateData
{
    public:
        UpdateData(uint32 map);
        UpdateData(UpdateData&& right) noexcept;
        UpdateData& operator=(UpdateData&& right) noexcept;
        ~UpdateData();

        void AddDestroyObject(ObjectGuid guid);
        void AddOutOfRangeGUID(ObjectGuid guid);
        void AddUpdateBlock() { ++m_blockCount; }
        ByteBuffer& GetBuffer() { return m_data; }
        bool BuildPacket(WorldPacket* packet);
        bool HasData() const { return m_blockCount > 0 || !m_outOfRangeGUIDs.empty() || !m_destroyGUIDs.empty(); }
        void Clear();

    protected:
        uint32 m_map;
        uint32 m_blockCount;
        Trinity::Containers::FlatSet<ObjectGuid> m_destroyGUIDs;
        Trinity::Containers::FlatSet<ObjectGuid> m_outOfRangeGUIDs;
        ByteBuffer m_data;

        UpdateData(UpdateData const& right) = delete;
        UpdateData& operator=(UpdateData const& right) = delete;
};

#endif // TRINITYCORE_UPDATE_DATA_H
