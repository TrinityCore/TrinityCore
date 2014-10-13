/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectGuid.h"
#include "World.h"
#include "ObjectMgr.h"
#include <sstream>
#include <iomanip>

ObjectGuid const ObjectGuid::Empty = ObjectGuid();

std::string const ObjectGuid::ToString() const
{
    std::ostringstream str;
    str << "GUID Full: 0x" << std::hex << std::setw(16) << std::setfill('0') << _guid << std::dec;
    str << " Type: " << GetTypeName();
    if (_highGuid->HasEntry())
        str << (IsPet() ? " Pet number: " : " Entry: ") << GetEntry() << " ";

    str << " Low: " << GetCounter();
    return str.str();
}

template<HighGuid high>
uint32 ObjectGuidGenerator<high>::Generate()
{
    if (_nextGuid >= _type->MaxCounter() - 1)
    {
        TC_LOG_ERROR("", "%s guid overflow!! Can't continue, shutting down server. ", _type->TypeName());
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _nextGuid++;
}

ByteBuffer& operator<<(ByteBuffer& buf, ObjectGuid const& guid)
{
    buf << uint64(guid.GetRawValue());
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, ObjectGuid& guid)
{
    guid.Set(buf.read<uint64>());
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, PackedGuid const& guid)
{
    buf.append(guid._packedGuid);
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, PackedGuidReader const& guid)
{
    buf.readPackGUID(*reinterpret_cast<uint64*>(guid.GuidPtr));
    return buf;
}

template uint32 ObjectGuidGenerator<HIGHGUID_ITEM>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_PLAYER>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_GAMEOBJECT>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_TRANSPORT>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_UNIT>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_PET>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_VEHICLE>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_DYNAMICOBJECT>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_CORPSE>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_INSTANCE>::Generate();
template uint32 ObjectGuidGenerator<HIGHGUID_GROUP>::Generate();
