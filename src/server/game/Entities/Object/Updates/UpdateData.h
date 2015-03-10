/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
    UPDATEFLAG_NONE                  = 0x0000,
    UPDATEFLAG_SELF                  = 0x0001,
    UPDATEFLAG_TRANSPORT             = 0x0002,
    UPDATEFLAG_HAS_TARGET            = 0x0004,
    UPDATEFLAG_LIVING                = 0x0008,
    UPDATEFLAG_STATIONARY_POSITION   = 0x0010,
    UPDATEFLAG_VEHICLE               = 0x0020,
    UPDATEFLAG_TRANSPORT_POSITION    = 0x0040,
    UPDATEFLAG_ROTATION              = 0x0080,
    UPDATEFLAG_ANIMKITS              = 0x0100,
    //UPDATEFLAG_AREATRIGGER           = 0x0200,
    //UPDATEFLAG_GAMEOBJECT            = 0x0400,
    //UPDATEFLAG_REPLACE_ACTIVE        = 0x0800,
    //UPDATEFLAG_NO_BIRTH_ANIM         = 0x1000,
    //UPDATEFLAG_ENABLE_PORTALS        = 0x2000,
    //UPDATEFLAG_PLAY_HOVER_ANIM       = 0x4000,
    //UPDATEFLAG_IS_SUPPRESSING_GREETINGS = 0x8000
    //UPDATEFLAG_SCENEOBJECT           = 0x10000,
    //UPDATEFLAG_SCENE_PENDING_INSTANCE = 0x20000
};

class UpdateData
{
    public:
        UpdateData(uint32 map);
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
        uint32 m_map;
        uint32 m_blockCount;
        GuidSet m_outOfRangeGUIDs;
        ByteBuffer m_data;

        UpdateData(UpdateData const& right) = delete;
        UpdateData& operator=(UpdateData const& right) = delete;
};
#endif

