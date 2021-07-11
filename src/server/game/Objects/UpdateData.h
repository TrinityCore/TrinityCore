/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __UPDATEDATA_H
#define __UPDATEDATA_H

#include "ByteBuffer.h"
#include "ObjectGuid.h"

class WorldPacket;
class WorldSession;
class WorldObject;

enum ObjectUpdateType
{
    UPDATETYPE_VALUES               = 0,
    UPDATETYPE_MOVEMENT             = 1,
    UPDATETYPE_CREATE_OBJECT        = 2,
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    UPDATETYPE_CREATE_OBJECT2       = 3,
#endif
    UPDATETYPE_OUT_OF_RANGE_OBJECTS,
    UPDATETYPE_NEAR_OBJECTS
};

// checked for 1.12.1
enum ObjectUpdateFlags
{
    UPDATEFLAG_NONE             = 0x0000,
    UPDATEFLAG_SELF             = 0x0001,
    UPDATEFLAG_TRANSPORT        = 0x0002,
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    UPDATEFLAG_MELEE_ATTACKING  = 0x0004,
    UPDATEFLAG_HIGHGUID         = 0x0008,
    UPDATEFLAG_ALL              = 0x0010,
    UPDATEFLAG_LIVING           = 0x0020,
    UPDATEFLAG_HAS_POSITION     = 0x0040
#endif
};

class UpdatePacket
{
    public:
        UpdatePacket() : blockCount(0) {}
        ByteBuffer data;
        uint32 blockCount;
};

class PacketCompressor
{
    public:
        static void Compress(void* dst, uint32* dst_size, void* src, int src_size);
};

class UpdateData
{
    public:
        UpdateData();
        ~UpdateData();

        void AddOutOfRangeGUID(ObjectGuidSet& guids);
        void AddOutOfRangeGUID(ObjectGuid const& guid);
        void AddUpdateBlock(ByteBuffer const& block);
        void Send(WorldSession* session, bool hasTransport = false);
        bool BuildPacket(WorldPacket* packet, bool hasTransport = false);
        bool BuildPacket(WorldPacket* packet, UpdatePacket const* updPacket, bool hasTransport = false);
        bool HasData() { return !m_datas.empty() || !m_outOfRangeGUIDs.empty(); }
        void Clear();

        ObjectGuidSet const& GetOutOfRangeGUIDs() const { return m_outOfRangeGUIDs; }

    protected:
        ObjectGuidSet m_outOfRangeGUIDs;
        std::list<UpdatePacket> m_datas;
};

class MovementData
{
    public:
        MovementData(WorldObject* owner = nullptr) : _buffer(100), _owner(owner) {}
        ~MovementData() {}
        void AddPacket(WorldPacket& data);
        void SetUnitSpeed(uint32 opcode, ObjectGuid const& unit, float value);
        void SetSplineOpcode(uint32 opcode, ObjectGuid const& unit);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        bool BuildPacket(WorldPacket& data);
#endif
    protected:
        ByteBuffer _buffer;
        WorldObject* _owner; // If not null, we dont compress data
};

#endif
