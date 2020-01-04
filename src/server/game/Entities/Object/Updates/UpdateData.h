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

#ifndef __UPDATEDATA_H
#define __UPDATEDATA_H

#include "Define.h"
#include "ByteBuffer.h"
#include "ObjectGuid.h"
#include <set>

class WorldPacket;

enum OBJECT_UPDATE_TYPE
{
    UPDATETYPE_VALUES               = 0,
    UPDATETYPE_CREATE_OBJECT        = 1,
    UPDATETYPE_CREATE_OBJECT2       = 2,
    UPDATETYPE_OUT_OF_RANGE_OBJECTS = 3,
};

enum OBJECT_UPDATE_FLAGS
{
    UPDATEFLAG_NONE                  = 0x00000,
    UPDATEFLAG_SELF                  = 0x00001,
    UPDATEFLAG_TRANSPORT             = 0x00002,
    UPDATEFLAG_HAS_TARGET            = 0x00004,
    UPDATEFLAG_UNKNOWN               = 0x00008,
    UPDATEFLAG_LOWGUID               = 0x00010,
    UPDATEFLAG_LIVING                = 0x00020,
    UPDATEFLAG_STATIONARY_POSITION   = 0x00040,
    UPDATEFLAG_VEHICLE               = 0x00080,
    UPDATEFLAG_GO_TRANSPORT_POSITION = 0x00100,
    UPDATEFLAG_ROTATION              = 0x00200,
    UPDATEFLAG_UNK3                  = 0x00400,
    UPDATEFLAG_ANIMKITS              = 0x00800,
    UPDATEFLAG_AREATRIGGER           = 0x01000,
    UPDATEFLAG_UNK6                  = 0x02000,
    UPDATEFLAG_PLAY_HOVER_ANIM       = 0x04000,
    UPDATEFLAG_SUPPRESSED_GREETINGS  = 0x08000,
    UPDATEFLAG_NO_BIRTH_ANIM         = 0x10000,
    UPDATEFLAG_ENABLE_PORTALS        = 0x20000,
};

class UpdateData
{
    public:
        UpdateData(uint16 map);
        UpdateData(UpdateData&& right) : m_map(right.m_map), m_blockCount(right.m_blockCount),
            m_outOfRangeGUIDs(std::move(right.m_outOfRangeGUIDs)),
            m_data(std::move(right.m_data))
        {
        }

        void AddOutOfRangeGUID(GuidSet& guids);
        void AddOutOfRangeGUID(ObjectGuid guid);
        void AddUpdateBlock(const ByteBuffer &block);
        bool BuildPacket(WorldPacket* packet);
        bool HasData() const { return m_blockCount > 0 || !m_outOfRangeGUIDs.empty(); }
        void Clear();

        GuidSet const& GetOutOfRangeGUIDs() const { return m_outOfRangeGUIDs; }

    protected:
        uint16 m_map;
        uint32 m_blockCount;
        GuidSet m_outOfRangeGUIDs;
        ByteBuffer m_data;

        UpdateData(UpdateData const& right) = delete;
        UpdateData& operator=(UpdateData const& right) = delete;
};
#endif
