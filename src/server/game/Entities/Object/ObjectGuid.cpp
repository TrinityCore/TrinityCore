/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Hash.h"
#include "Log.h"
#include "World.h"
#include <sstream>
#include <iomanip>

ObjectGuid const ObjectGuid::Empty = ObjectGuid();

char const* ObjectGuid::GetTypeName(HighGuid high)
{
    switch (high)
    {
        case HighGuid::Item:         return "Item";
        case HighGuid::Player:       return "Player";
        case HighGuid::GameObject:   return "Gameobject";
        case HighGuid::Transport:    return "Transport";
        case HighGuid::Unit:         return "Creature";
        case HighGuid::Pet:          return "Pet";
        case HighGuid::Vehicle:      return "Vehicle";
        case HighGuid::DynamicObject: return "DynObject";
        case HighGuid::Corpse:       return "Corpse";
        case HighGuid::Mo_Transport: return "MoTransport";
        case HighGuid::Instance:     return "InstanceID";
        case HighGuid::Group:        return "Group";
        default:
            return "<unknown>";
    }
}

std::string ObjectGuid::ToString() const
{
    std::ostringstream str;
    str << "GUID Full: 0x" << std::hex << std::setw(16) << std::setfill('0') << _guid << std::dec;
    str << " Type: " << GetTypeName();
    if (HasEntry())
        str << (IsPet() ? " Pet number: " : " Entry: ") << GetEntry() << " ";

    str << " Low: " << GetCounter();
    return str.str();
}

ObjectGuid ObjectGuid::Global(HighGuid type, LowType counter)
{
    return ObjectGuid(type, counter);
}

ObjectGuid ObjectGuid::MapSpecific(HighGuid type, uint32 entry, LowType counter)
{
    return ObjectGuid(type, entry, counter);
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
    buf.readPackGUID(reinterpret_cast<uint64&>(guid.Guid));
    return buf;
}

void ObjectGuidGeneratorBase::HandleCounterOverflow(HighGuid high)
{
    TC_LOG_ERROR("misc", "%s guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(high));
    World::StopNow(ERROR_EXIT_CODE);
}

void ObjectGuidGeneratorBase::CheckGuidTrigger(ObjectGuid::LowType guidlow)
{
    if (!sWorld->IsGuidAlert() && guidlow > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDALERTLEVEL))
        sWorld->TriggerGuidAlert();
    else if (!sWorld->IsGuidWarning() && guidlow > sWorld->getIntConfig(CONFIG_RESPAWN_GUIDWARNLEVEL))
        sWorld->TriggerGuidWarning();
}

#define GUID_TRAIT_INSTANTIATE_GUID( HIGH_GUID ) \
    template class TC_GAME_API ObjectGuidGenerator< HIGH_GUID >;

GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Container)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Player)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::GameObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Transport)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Unit)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Pet)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Vehicle)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::DynamicObject)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Mo_Transport)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Instance)
GUID_TRAIT_INSTANTIATE_GUID(HighGuid::Group)
