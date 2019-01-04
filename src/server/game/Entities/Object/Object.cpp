/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Object.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "Chat.h"
#include "CinematicMgr.h"
#include "Common.h"
#include "Creature.h"
#include "DynamicTree.h"
#include "GameTime.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Item.h"
#include "Log.h"
#include "MapManager.h"
#include "MovementPacketBuilder.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvPMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "SharedDefines.h"
#include "SpellAuraEffects.h"
#include "TargetedMovementGenerator.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "UpdateMask.h"
#include "Util.h"
#include "Vehicle.h"
#include "VMapFactory.h"
#include "WaypointMovementGenerator.h"
#include "World.h"
#include "WorldPacket.h"

constexpr float VisibilityDistances[AsUnderlyingType(VisibilityDistanceType::Max)] =
{
    DEFAULT_VISIBILITY_DISTANCE,
    VISIBILITY_DISTANCE_TINY,
    VISIBILITY_DISTANCE_SMALL,
    VISIBILITY_DISTANCE_LARGE,
    VISIBILITY_DISTANCE_GIGANTIC,
    MAX_VISIBILITY_DISTANCE
};

Object::Object() : m_PackGUID(sizeof(uint64)+1)
{
    m_objectTypeId      = TYPEID_OBJECT;
    m_objectType        = TYPEMASK_OBJECT;
    m_updateFlag        = UPDATEFLAG_NONE;

    m_uint32Values      = nullptr;
    m_valuesCount       = 0;
    _fieldNotifyFlags   = UF_FLAG_DYNAMIC;

    m_inWorld           = false;
    m_isNewObject       = false;
    m_objectUpdated     = false;
}

WorldObject::~WorldObject()
{
    // this may happen because there are many !create/delete
    if (IsWorldObject() && m_currMap)
    {
        if (GetTypeId() == TYPEID_CORPSE)
        {
            TC_LOG_FATAL("misc", "WorldObject::~WorldObject Corpse Type: %d (%s) deleted but still in map!!",
                ToCorpse()->GetType(), GetGUID().ToString().c_str());
            ABORT();
        }
        ResetMap();
    }
}

Object::~Object()
{
    if (IsInWorld())
    {
        TC_LOG_FATAL("misc", "Object::~Object %s deleted but still in world!!", GetGUID().ToString().c_str());
        if (isType(TYPEMASK_ITEM))
            TC_LOG_FATAL("misc", "Item slot %u", ((Item*)this)->GetSlot());
        ABORT();
    }

    if (m_objectUpdated)
    {
        TC_LOG_FATAL("misc", "Object::~Object %s deleted but still in update list!!", GetGUID().ToString().c_str());
        ABORT();
    }

    delete [] m_uint32Values;
    m_uint32Values = nullptr;
}

void Object::_InitValues()
{
    m_uint32Values = new uint32[m_valuesCount];
    memset(m_uint32Values, 0, m_valuesCount*sizeof(uint32));

    _changesMask.SetCount(m_valuesCount);

    m_objectUpdated = false;
}

void Object::_Create(ObjectGuid::LowType guidlow, uint32 entry, HighGuid guidhigh)
{
    if (!m_uint32Values) _InitValues();

    ObjectGuid guid(guidhigh, entry, guidlow);
    SetGuidValue(OBJECT_FIELD_GUID, guid);
    SetUInt16Value(OBJECT_FIELD_TYPE, 0, m_objectType);
    m_PackGUID.Set(guid);
}

std::string Object::_ConcatFields(uint16 startIndex, uint16 size) const
{
    std::ostringstream ss;
    for (uint16 index = 0; index < size; ++index)
        ss << GetUInt32Value(index + startIndex) << ' ';
    return ss.str();
}

void Object::AddToWorld()
{
    if (m_inWorld)
        return;

    ASSERT(m_uint32Values);

    m_inWorld = true;

    // synchronize values mirror with values array (changes will send in updatecreate opcode any way
    ASSERT(!m_objectUpdated);
    ClearUpdateMask(false);
}

void Object::RemoveFromWorld()
{
    if (!m_inWorld)
        return;

    m_inWorld = false;

    // if we remove from world then sending changes not required
    ClearUpdateMask(true);
}

void Object::BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    if (!target)
        return;

    uint8  updateType = m_isNewObject ? UPDATETYPE_CREATE_OBJECT2 : UPDATETYPE_CREATE_OBJECT;
    uint16 flags      = m_updateFlag;

    /** lower flag1 **/
    if (target == this)                                      // building packet for yourself
        flags |= UPDATEFLAG_SELF;

    if (WorldObject const* worldObject = dynamic_cast<WorldObject const*>(this))
    {
        if (!(flags & UPDATEFLAG_LIVING))
            if (!worldObject->m_movementInfo.transport.guid.IsEmpty())
                flags |= UPDATEFLAG_STATIONARY_POSITION;

        if (worldObject->GetAIAnimKitId() || worldObject->GetMovementAnimKitId() || worldObject->GetMeleeAnimKitId())
            flags |= UPDATEFLAG_ANIMKITS;

        if (!worldObject->m_movementInfo.transport.guid.IsEmpty() && (ToGameObject() || ToDynObject()))
            flags |= UPDATEFLAG_GO_TRANSPORT_POSITION;
    }

    if (flags & UPDATEFLAG_STATIONARY_POSITION)
    {
        if (isType(TYPEMASK_GAMEOBJECT))
        {
            switch (ToGameObject()->GetGoType())
            {
                case GAMEOBJECT_TYPE_TRANSPORT:
                    flags |= UPDATEFLAG_TRANSPORT;
                    break;
                default:
                    break;
            }
        }

        if (isType(TYPEMASK_UNIT))
        {
            if (ToUnit()->GetVictim())
                flags |= UPDATEFLAG_HAS_TARGET;
        }
    }

    ByteBuffer buf(500);
    buf << uint8(updateType);
    buf << GetPackGUID();
    buf << uint8(m_objectTypeId);

    BuildMovementUpdate(&buf, flags);
    BuildValuesUpdate(updateType, &buf, target);
    data->AddUpdateBlock(buf);
}

void Object::SendUpdateToPlayer(Player* player)
{
    // send create update to player
    UpdateData upd(player->GetMapId());
    WorldPacket packet;

    if (player->HaveAtClient(this))
        BuildValuesUpdateBlockForPlayer(&upd, player);
    else
        BuildCreateUpdateBlockForPlayer(&upd, player);
    upd.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Object::SendUpdateToSet()
{
    if (Unit* unit = ToUnit())
    {
        std::list<Player*> players;
        unit->GetPlayerListInGrid(players, unit->GetVisibilityRange());
        for (auto itr = players.begin(); itr != players.end(); itr++)
        {
            UpdateData upd((*itr)->GetMapId());
            WorldPacket packet;
            if ((*itr)->HaveAtClient(this))
                BuildValuesUpdateBlockForPlayer(&upd, (*itr));
            upd.BuildPacket(&packet);
            (*itr)->GetSession()->SendPacket(&packet);
        }
    }
}

void Object::BuildValuesUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    ByteBuffer buf(500);

    buf << uint8(UPDATETYPE_VALUES);
    buf << GetPackGUID();

    BuildValuesUpdate(UPDATETYPE_VALUES, &buf, target);

    data->AddUpdateBlock(buf);
}

void Object::BuildOutOfRangeUpdateBlock(UpdateData* data) const
{
    data->AddOutOfRangeGUID(GetGUID());
}

void Object::DestroyForPlayer(Player* target) const
{
    ASSERT(target);

    UpdateData updateData(target->GetMapId());
    BuildOutOfRangeUpdateBlock(&updateData);
    WorldPacket packet;
    updateData.BuildPacket(&packet);
    target->SendDirectMessage(&packet);
}

int32 Object::GetInt32Value(uint16 index) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    return m_int32Values[index];
}

uint32 Object::GetUInt32Value(uint16 index) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    return m_uint32Values[index];
}

uint64 Object::GetUInt64Value(uint16 index) const
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, false));
    return *((uint64*)&(m_uint32Values[index]));
}

float Object::GetFloatValue(uint16 index) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    return m_floatValues[index];
}

uint8 Object::GetByteValue(uint16 index, uint8 offset) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    ASSERT(offset < 4);
    return *(((uint8*)&m_uint32Values[index])+offset);
}

uint16 Object::GetUInt16Value(uint16 index, uint8 offset) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    ASSERT(offset < 2);
    return *(((uint16*)&m_uint32Values[index])+offset);
}

ObjectGuid Object::GetGuidValue(uint16 index) const
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, false));
    return *((ObjectGuid*)&(m_uint32Values[index]));
}

void Object::BuildMovementUpdate(ByteBuffer* data, uint16 flags) const
{
    Unit const* self = nullptr;
    ObjectGuid guid = GetGUID();
    uint32 movementFlags = 0;
    uint16 movementFlagsExtra = 0;

    bool hasTransportTime2 = false;
    bool hasVehicleId = false;
    bool hasFallDirection = false;
    bool hasFallData = false;
    bool hasPitch = false;
    bool hasSpline = false;
    bool hasSplineElevation = false;
    bool hasAIAnimKit = false;
    bool hasMovementAnimKit = false;
    bool hasMeleeAnimKit = false;

    uint32 stopFrameCount = 0;
    if (GameObject const* go = ToGameObject())
        if (go->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
            stopFrameCount = go->GetGOValue()->Transport.StopFrames->size();

    // Bit content
    data->WriteBit(0);
    data->WriteBit(0);
    data->WriteBit(flags & UPDATEFLAG_ROTATION);
    data->WriteBit(flags & UPDATEFLAG_ANIMKITS);
    data->WriteBit(flags & UPDATEFLAG_HAS_TARGET);
    data->WriteBit(flags & UPDATEFLAG_SELF);
    data->WriteBit(flags & UPDATEFLAG_VEHICLE);
    data->WriteBit(flags & UPDATEFLAG_LIVING);
    data->WriteBits(stopFrameCount, 24);
    data->WriteBit(0);
    data->WriteBit(flags & UPDATEFLAG_GO_TRANSPORT_POSITION);
    data->WriteBit(flags & UPDATEFLAG_STATIONARY_POSITION);
    data->WriteBit(flags & UPDATEFLAG_UNK5);
    data->WriteBit(0);
    data->WriteBit(flags & UPDATEFLAG_TRANSPORT);

    if (flags & UPDATEFLAG_LIVING)
    {
        self = ToUnit();
        movementFlags = self->m_movementInfo.GetMovementFlags();
        movementFlagsExtra = self->m_movementInfo.GetExtraMovementFlags();
        hasSpline = self->IsSplineEnabled();

        hasTransportTime2 = self->m_movementInfo.transport.guid != 0 && self->m_movementInfo.transport.time2 != 0;
        hasVehicleId = false;
        hasPitch = self->HasUnitMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || self->HasExtraUnitMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING);
        hasFallDirection = self->HasUnitMovementFlag(MOVEMENTFLAG_FALLING);
        hasFallData = hasFallDirection || self->m_movementInfo.jump.fallTime != 0;
        hasSplineElevation = self->HasUnitMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);

        if (GetTypeId() == TYPEID_UNIT)
            movementFlags &= MOVEMENTFLAG_MASK_CREATURE_ALLOWED;

        data->WriteBit(!movementFlags);
        data->WriteBit(G3D::fuzzyEq(self->GetOrientation(), 0.0f));             // Has Orientation
        data->WriteBit(guid[7]);
        data->WriteBit(guid[3]);
        data->WriteBit(guid[2]);
        if (movementFlags)
            data->WriteBits(movementFlags, 30);

        data->WriteBit(hasSpline && GetTypeId() == TYPEID_PLAYER);              // Has spline (from MovementInfo)
        data->WriteBit(!hasPitch);                                              // Has pitch
        data->WriteBit(hasSpline);                                              // Has spline data (independent)
        data->WriteBit(hasFallData);                                            // Has fall data
        data->WriteBit(!hasSplineElevation);                                    // Has spline elevation
        data->WriteBit(guid[5]);
        data->WriteBit(self->m_movementInfo.transport.guid);                    // Has transport data
        data->WriteBit(0);                                                      // Is missing time

        if (self->m_movementInfo.transport.guid)
        {
            ObjectGuid transGuid = self->m_movementInfo.transport.guid;

            data->WriteBit(transGuid[1]);
            data->WriteBit(hasTransportTime2);                             // Has transport time 2
            data->WriteBit(transGuid[4]);
            data->WriteBit(transGuid[0]);
            data->WriteBit(transGuid[6]);
            data->WriteBit(hasVehicleId);                                  // Has transport time 3
            data->WriteBit(transGuid[7]);
            data->WriteBit(transGuid[5]);
            data->WriteBit(transGuid[3]);
            data->WriteBit(transGuid[2]);
        }

        data->WriteBit(guid[4]);

        if (hasSpline)
            Movement::PacketBuilder::WriteCreateBits(*self->movespline, *data);

        data->WriteBit(guid[6]);
        if (hasFallData)
            data->WriteBit(hasFallDirection);

        data->WriteBit(guid[0]);
        data->WriteBit(guid[1]);
        data->WriteBit(0);
        data->WriteBit(!movementFlagsExtra);
        if (movementFlagsExtra)
            data->WriteBits(movementFlagsExtra, 12);
    }

    if (flags & UPDATEFLAG_GO_TRANSPORT_POSITION)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        ObjectGuid transGuid = self->m_movementInfo.transport.guid;
        data->WriteBit(transGuid[5]);
        data->WriteBit(0);                                                      // Has GO transport time 3
        data->WriteBit(transGuid[0]);
        data->WriteBit(transGuid[3]);
        data->WriteBit(transGuid[6]);
        data->WriteBit(transGuid[1]);
        data->WriteBit(transGuid[4]);
        data->WriteBit(transGuid[2]);
        data->WriteBit(0);                                                      // Has GO transport time 2
        data->WriteBit(transGuid[7]);
    }

    if (flags & UPDATEFLAG_HAS_TARGET)
    {
        ObjectGuid victimGuid = self->GetVictim()->GetGUID();   // checked in BuildCreateUpdateBlockForPlayer
        data->WriteBit(victimGuid[2]);
        data->WriteBit(victimGuid[7]);
        data->WriteBit(victimGuid[0]);
        data->WriteBit(victimGuid[4]);
        data->WriteBit(victimGuid[5]);
        data->WriteBit(victimGuid[6]);
        data->WriteBit(victimGuid[1]);
        data->WriteBit(victimGuid[3]);
    }

    if (flags & UPDATEFLAG_ANIMKITS)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        hasAIAnimKit = self->GetAIAnimKitId();
        data->WriteBit(!hasAIAnimKit);
        hasMovementAnimKit = self->GetMovementAnimKitId();
        data->WriteBit(!hasMovementAnimKit);
        hasMeleeAnimKit = self->GetMeleeAnimKitId();
        data->WriteBit(!hasMeleeAnimKit);
    }

    data->FlushBits();

    // Data
    if (GameObject const* go = ToGameObject())
        for (uint32 i = 0; i < stopFrameCount; ++i)
            *data << uint32(go->GetGOValue()->Transport.StopFrames->at(i));

    if (flags & UPDATEFLAG_LIVING)
    {
        data->WriteByteSeq(guid[4]);
        *data << self->GetSpeed(MOVE_RUN_BACK);

        if (hasFallData)
        {
            if (hasFallDirection)
            {
                *data << float(self->m_movementInfo.jump.xyspeed);
                *data << float(self->m_movementInfo.jump.sinAngle);
                *data << float(self->m_movementInfo.jump.cosAngle);
            }

            *data << uint32(self->m_movementInfo.jump.fallTime);
            *data << float(self->m_movementInfo.jump.zspeed);
        }

        *data << self->GetSpeed(MOVE_SWIM_BACK);
        if (hasSplineElevation)
            *data << float(self->m_movementInfo.splineElevation);

        if (hasSpline)
            Movement::PacketBuilder::WriteCreateData(*self->movespline, *data);

        *data << float(self->GetPositionZMinusOffset());
        data->WriteByteSeq(guid[5]);

        if (self->m_movementInfo.transport.guid)
        {
            ObjectGuid transGuid = self->m_movementInfo.transport.guid;

            data->WriteByteSeq(transGuid[5]);
            data->WriteByteSeq(transGuid[7]);
            *data << uint32(self->GetTransTime());
            *data << float(self->GetTransOffsetO());
            if (hasTransportTime2)
                *data << uint32(self->m_movementInfo.transport.time2);

            *data << float(self->GetTransOffsetY());
            *data << float(self->GetTransOffsetX());
            data->WriteByteSeq(transGuid[3]);
            *data << float(self->GetTransOffsetZ());
            data->WriteByteSeq(transGuid[0]);
            if (hasVehicleId)
                *data << uint32(self->m_movementInfo.transport.vehicleId);

            *data << int8(self->GetTransSeat());
            data->WriteByteSeq(transGuid[1]);
            data->WriteByteSeq(transGuid[6]);
            data->WriteByteSeq(transGuid[2]);
            data->WriteByteSeq(transGuid[4]);
        }

        *data << float(self->GetPositionX());
        *data << self->GetSpeed(MOVE_PITCH_RATE);
        data->WriteByteSeq(guid[3]);
        data->WriteByteSeq(guid[0]);
        *data << self->GetSpeed(MOVE_SWIM);
        *data << float(self->GetPositionY());
        data->WriteByteSeq(guid[7]);
        data->WriteByteSeq(guid[1]);
        data->WriteByteSeq(guid[2]);
        *data << self->GetSpeed(MOVE_WALK);

        //if (true)   // Has time, controlled by bit just after HasTransport
        *data << uint32(GameTime::GetGameTimeMS());

        *data << self->GetSpeed(MOVE_TURN_RATE);
        data->WriteByteSeq(guid[6]);
        *data << self->GetSpeed(MOVE_FLIGHT);
        if (!G3D::fuzzyEq(self->GetOrientation(), 0.0f))
            *data << float(self->GetOrientation());

        *data << self->GetSpeed(MOVE_RUN);
        if (hasPitch)
            *data << float(self->m_movementInfo.pitch);

        *data << self->GetSpeed(MOVE_FLIGHT_BACK);
    }

    if (flags & UPDATEFLAG_VEHICLE)
    {
        *data << float(self->GetTransport() ? self->GetTransOffsetO() : self->GetOrientation());
        *data << uint32(self->GetVehicleKit()->GetVehicleInfo()->m_ID);
    }

    if (flags & UPDATEFLAG_GO_TRANSPORT_POSITION)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        ObjectGuid transGuid = self->m_movementInfo.transport.guid;

        data->WriteByteSeq(transGuid[0]);
        data->WriteByteSeq(transGuid[5]);
        if (hasVehicleId)
            *data << uint32(self->m_movementInfo.transport.vehicleId);

        data->WriteByteSeq(transGuid[3]);
        *data << float(self->GetTransOffsetX());
        data->WriteByteSeq(transGuid[4]);
        data->WriteByteSeq(transGuid[6]);
        data->WriteByteSeq(transGuid[1]);
        *data << uint32(self->GetTransTime());
        *data << float(self->GetTransOffsetY());
        data->WriteByteSeq(transGuid[2]);
        data->WriteByteSeq(transGuid[7]);
        *data << float(self->GetTransOffsetZ());
        *data << int8(self->GetTransSeat());
        *data << float(self->GetTransOffsetO());
        if (hasTransportTime2)
            *data << uint32(self->m_movementInfo.transport.time2);
    }

    if (flags & UPDATEFLAG_ROTATION)
        *data << uint64(ToGameObject()->GetPackedWorldRotation());

    if (flags & UPDATEFLAG_UNK5)
    {
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << uint8(0);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
        *data << float(0.0f);
    }

    if (flags & UPDATEFLAG_STATIONARY_POSITION)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << float(self->GetStationaryO());
        *data << float(self->GetStationaryX());
        *data << float(self->GetStationaryY());
        *data << float(self->GetStationaryZ());
    }

    if (flags & UPDATEFLAG_HAS_TARGET)
    {
        ObjectGuid victimGuid = self->GetVictim()->GetGUID();   // checked in BuildCreateUpdateBlockForPlayer
        data->WriteByteSeq(victimGuid[4]);
        data->WriteByteSeq(victimGuid[0]);
        data->WriteByteSeq(victimGuid[3]);
        data->WriteByteSeq(victimGuid[5]);
        data->WriteByteSeq(victimGuid[7]);
        data->WriteByteSeq(victimGuid[6]);
        data->WriteByteSeq(victimGuid[2]);
        data->WriteByteSeq(victimGuid[1]);
    }

    if (flags & UPDATEFLAG_ANIMKITS)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        if (hasAIAnimKit)
            *data << uint16(self->GetAIAnimKitId());
        if (hasMovementAnimKit)
            *data << uint16(self->GetMovementAnimKitId());
        if (hasMeleeAnimKit)
            *data << uint16(self->GetMeleeAnimKitId());
    }

    if (flags & UPDATEFLAG_TRANSPORT)
    {
        if (GameObject const* go = ToGameObject())
        {
            if (go->IsDynTransport())
                *data << uint32(go->ToTransport()->GetPathProgress());
            else
                *data << uint32(getMSTime());
        }
    }
}

void Object::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    ByteBuffer fieldBuffer;
    UpdateMask updateMask;
    updateMask.SetCount(m_valuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetUpdateFieldData(target, flags);
    ASSERT(flags);

    for (uint16 index = 0; index < m_valuesCount; ++index)
    {
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _changesMask.GetBit(index) : m_uint32Values[index]) && (flags[index] & visibleFlag)))
        {
            updateMask.SetBit(index);
            fieldBuffer << m_uint32Values[index];
        }
    }

    *data << uint8(updateMask.GetBlockCount());
    updateMask.AppendToPacket(data);
    data->append(fieldBuffer);
}

void Object::AddToObjectUpdateIfNeeded()
{
    if (m_inWorld && !m_objectUpdated)
    {
        AddToObjectUpdate();
        m_objectUpdated = true;
    }
}

void Object::ClearUpdateMask(bool remove)
{
    _changesMask.Clear();

    if (m_objectUpdated)
    {
        if (remove)
            RemoveFromObjectUpdate();

        m_objectUpdated = false;
    }
}

void Object::BuildFieldsUpdate(Player* player, UpdateDataMapType& data_map) const
{
    UpdateDataMapType::iterator iter = data_map.find(player);

    if (iter == data_map.end())
    {
        std::pair<UpdateDataMapType::iterator, bool> p = data_map.emplace(player, UpdateData(player->GetMapId()));
        ASSERT(p.second);
        iter = p.first;
    }

    BuildValuesUpdateBlockForPlayer(&iter->second, iter->first);
}

uint32 Object::GetUpdateFieldData(Player const* target, uint32*& flags) const
{
    uint32 visibleFlag = UF_FLAG_PUBLIC;

    if (target == this)
        visibleFlag |= UF_FLAG_PRIVATE;

    switch (GetTypeId())
    {
        case TYPEID_ITEM:
        case TYPEID_CONTAINER:
            flags = ItemUpdateFieldFlags;
            if (((Item const*)this)->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER | UF_FLAG_ITEM_OWNER;
            break;
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
        {
            Player* plr = ToUnit()->GetCharmerOrOwnerPlayerOrPlayerItself();
            flags = UnitUpdateFieldFlags;
            if (ToUnit()->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER;

            if (HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_SPECIALINFO))
                if (ToUnit()->HasAuraTypeWithCaster(SPELL_AURA_EMPATHY, target->GetGUID()))
                    visibleFlag |= UF_FLAG_SPECIAL_INFO;

            if (plr && plr->IsInSameRaidWith(target))
                visibleFlag |= UF_FLAG_PARTY_MEMBER;
            break;
        }
        case TYPEID_GAMEOBJECT:
            flags = GameObjectUpdateFieldFlags;
            if (ToGameObject()->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER;
            break;
        case TYPEID_DYNAMICOBJECT:
            flags = DynamicObjectUpdateFieldFlags;
            if (ToDynObject()->GetCasterGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER;
            break;
        case TYPEID_CORPSE:
            flags = CorpseUpdateFieldFlags;
            if (ToCorpse()->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER;
            break;
        case TYPEID_AREATRIGGER:
            flags = AreaTriggerUpdateFieldFlags;
            break;
        case TYPEID_OBJECT:
            break;
    }

    return visibleFlag;
}

void Object::_LoadIntoDataField(std::string const& data, uint32 startOffset, uint32 count)
{
    if (data.empty())
        return;

    Tokenizer tokens(data, ' ', count);

    if (tokens.size() != count)
        return;

    for (uint32 index = 0; index < count; ++index)
    {
        m_uint32Values[startOffset + index] = atoul(tokens[index]);
        _changesMask.SetBit(startOffset + index);
    }
}

void Object::SetInt32Value(uint16 index, int32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_int32Values[index] != value)
    {
        m_int32Values[index] = value;
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetUInt32Value(uint16 index, uint32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_uint32Values[index] != value)
    {
        m_uint32Values[index] = value;
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::UpdateUInt32Value(uint16 index, uint32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    m_uint32Values[index] = value;
    _changesMask.SetBit(index);
}

void Object::SetUInt64Value(uint16 index, uint64 value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (*((uint64*)&(m_uint32Values[index])) != value)
    {
        m_uint32Values[index] = PAIR64_LOPART(value);
        m_uint32Values[index + 1] = PAIR64_HIPART(value);
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        AddToObjectUpdateIfNeeded();
    }
}

bool Object::AddGuidValue(uint16 index, ObjectGuid value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (value && !*((ObjectGuid*)&(m_uint32Values[index])))
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        AddToObjectUpdateIfNeeded();

        return true;
    }

    return false;
}

bool Object::RemoveGuidValue(uint16 index, ObjectGuid value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (value && *((ObjectGuid*)&(m_uint32Values[index])) == value)
    {
        m_uint32Values[index] = 0;
        m_uint32Values[index + 1] = 0;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        AddToObjectUpdateIfNeeded();

        return true;
    }

    return false;
}

void Object::SetFloatValue(uint16 index, float value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_floatValues[index] != value)
    {
        m_floatValues[index] = value;
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetByteValue(uint16 index, uint8 offset, uint8 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (offset > 3)
    {
        TC_LOG_ERROR("misc", "Object::SetByteValue: wrong offset %u", offset);
        return;
    }

    if (uint8(m_uint32Values[index] >> (offset * 8)) != value)
    {
        m_uint32Values[index] &= ~uint32(uint32(0xFF) << (offset * 8));
        m_uint32Values[index] |= uint32(uint32(value) << (offset * 8));
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetUInt16Value(uint16 index, uint8 offset, uint16 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (offset > 1)
    {
        TC_LOG_ERROR("misc", "Object::SetUInt16Value: wrong offset %u", offset);
        return;
    }

    if (uint16(m_uint32Values[index] >> (offset * 16)) != value)
    {
        m_uint32Values[index] &= ~uint32(uint32(0xFFFF) << (offset * 16));
        m_uint32Values[index] |= uint32(uint32(value) << (offset * 16));
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetGuidValue(uint16 index, ObjectGuid value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (*((ObjectGuid*)&(m_uint32Values[index])) != value)
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetStatFloatValue(uint16 index, float value)
{
    if (value < 0)
        value = 0.0f;

    SetFloatValue(index, value);
}

void Object::SetStatInt32Value(uint16 index, int32 value)
{
    if (value < 0)
        value = 0;

    SetUInt32Value(index, uint32(value));
}

void Object::ApplyModUInt32Value(uint16 index, int32 val, bool apply)
{
    int32 cur = GetUInt32Value(index);
    cur += (apply ? val : -val);
    if (cur < 0)
        cur = 0;
    SetUInt32Value(index, cur);
}

void Object::ApplyModInt32Value(uint16 index, int32 val, bool apply)
{
    int32 cur = GetInt32Value(index);
    cur += (apply ? val : -val);
    SetInt32Value(index, cur);
}

void Object::ApplyModSignedFloatValue(uint16 index, float  val, bool apply)
{
    float cur = GetFloatValue(index);
    cur += (apply ? val : -val);
    SetFloatValue(index, cur);
}

void Object::ApplyPercentModFloatValue(uint16 index, float val, bool apply)
{
    float value = GetFloatValue(index);
    ApplyPercentModFloatVar(value, val, apply);
    SetFloatValue(index, value);
}

void Object::ApplyModPositiveFloatValue(uint16 index, float  val, bool apply)
{
    float cur = GetFloatValue(index);
    cur += (apply ? val : -val);
    if (cur < 0)
        cur = 0;
    SetFloatValue(index, cur);
}

void Object::SetFlag(uint16 index, uint32 newFlag)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));
    uint32 oldval = m_uint32Values[index];
    uint32 newval = oldval | newFlag;

    if (oldval != newval)
    {
        m_uint32Values[index] = newval;
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::RemoveFlag(uint16 index, uint32 oldFlag)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));
    ASSERT(m_uint32Values);

    uint32 oldval = m_uint32Values[index];
    uint32 newval = oldval & ~oldFlag;

    if (oldval != newval)
    {
        m_uint32Values[index] = newval;
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::ToggleFlag(uint16 index, uint32 flag)
{
    if (HasFlag(index, flag))
        RemoveFlag(index, flag);
    else
        SetFlag(index, flag);
}

bool Object::HasFlag(uint16 index, uint32 flag) const
{
    if (index >= m_valuesCount && !PrintIndexError(index, false))
        return false;

    return (m_uint32Values[index] & flag) != 0;
}

void Object::ApplyModFlag(uint16 index, uint32 flag, bool apply)
{
    if (apply) SetFlag(index, flag); else RemoveFlag(index, flag);
}

void Object::SetByteFlag(uint16 index, uint8 offset, uint8 newFlag)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (offset > 3)
    {
        TC_LOG_ERROR("misc", "Object::SetByteFlag: wrong offset %u", offset);
        return;
    }

    if (!(uint8(m_uint32Values[index] >> (offset * 8)) & newFlag))
    {
        m_uint32Values[index] |= uint32(uint32(newFlag) << (offset * 8));
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::RemoveByteFlag(uint16 index, uint8 offset, uint8 oldFlag)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (offset > 3)
    {
        TC_LOG_ERROR("misc", "Object::RemoveByteFlag: wrong offset %u", offset);
        return;
    }

    if (uint8(m_uint32Values[index] >> (offset * 8)) & oldFlag)
    {
        m_uint32Values[index] &= ~uint32(uint32(oldFlag) << (offset * 8));
        _changesMask.SetBit(index);

        AddToObjectUpdateIfNeeded();
    }
}

void Object::ToggleByteFlag(uint16 index, uint8 offset, uint8 flag)
{
    if (HasByteFlag(index, offset, flag))
        RemoveByteFlag(index, offset, flag);
    else
        SetByteFlag(index, offset, flag);
}

bool Object::HasByteFlag(uint16 index, uint8 offset, uint8 flag) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    ASSERT(offset < 4);
    return (((uint8*)&m_uint32Values[index])[offset] & flag) != 0;
}

void Object::ApplyModByteFlag(uint16 index, uint8 offset, uint8 flag, bool apply)
{
    if (apply) SetByteFlag(index, offset, flag); else RemoveByteFlag(index, offset, flag);
}

void Object::SetFlag64(uint16 index, uint64 newFlag)
{
    uint64 oldval = GetUInt64Value(index);
    uint64 newval = oldval | newFlag;
    SetUInt64Value(index, newval);
}

void Object::RemoveFlag64(uint16 index, uint64 oldFlag)
{
    uint64 oldval = GetUInt64Value(index);
    uint64 newval = oldval & ~oldFlag;
    SetUInt64Value(index, newval);
}

void Object::ToggleFlag64(uint16 index, uint64 flag)
{
    if (HasFlag64(index, flag))
        RemoveFlag64(index, flag);
    else
        SetFlag64(index, flag);
}

bool Object::HasFlag64(uint16 index, uint64 flag) const
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, false));
    return (GetUInt64Value(index) & flag) != 0;
}

void Object::ApplyModFlag64(uint16 index, uint64 flag, bool apply)
{
    if (apply) SetFlag64(index, flag); else RemoveFlag64(index, flag);
}

bool Object::PrintIndexError(uint32 index, bool set) const
{
    TC_LOG_ERROR("misc", "Attempt to %s non-existing value field: %u (count: %u) for object typeid: %u type mask: %u", (set ? "set value to" : "get value from"), index, m_valuesCount, GetTypeId(), m_objectType);

    // ASSERT must fail after function call
    return false;
}

void MovementInfo::OutDebug()
{
    TC_LOG_DEBUG("misc", "MOVEMENT INFO");
    TC_LOG_DEBUG("misc", "%s", guid.ToString().c_str());
    TC_LOG_DEBUG("misc", "flags %u", flags);
    TC_LOG_DEBUG("misc", "flags2 %u", flags2);
    TC_LOG_DEBUG("misc", "time %u current time " UI64FMTD "", flags2, uint64(::time(nullptr)));
    TC_LOG_DEBUG("misc", "position: `%s`", pos.ToString().c_str());
    if (transport.guid)
    {
        TC_LOG_DEBUG("misc", "TRANSPORT:");
        TC_LOG_DEBUG("misc", "%s", transport.guid.ToString().c_str());
        TC_LOG_DEBUG("misc", "position: `%s`", transport.pos.ToString().c_str());
        TC_LOG_DEBUG("misc", "seat: %i", transport.seat);
        TC_LOG_DEBUG("misc", "time: %u", transport.time);
        if (flags2 & MOVEMENTFLAG2_INTERPOLATED_MOVEMENT)
            TC_LOG_DEBUG("misc", "time2: %u", transport.time2);
        if (transport.vehicleId)
            TC_LOG_INFO("misc", "vehicleId: %u", transport.vehicleId);
    }

    if ((flags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        TC_LOG_DEBUG("misc", "pitch: %f", pitch);

    if (flags & MOVEMENTFLAG_FALLING || jump.fallTime)
    {
        TC_LOG_INFO("misc", "fallTime: %u j_zspeed: %f", jump.fallTime, jump.zspeed);
        if (flags & MOVEMENTFLAG_FALLING)
        TC_LOG_DEBUG("misc", "j_zspeed: %f j_sinAngle: %f j_cosAngle: %f j_xyspeed: %f", jump.zspeed, jump.sinAngle, jump.cosAngle, jump.xyspeed);
    }

    if (flags & MOVEMENTFLAG_SPLINE_ELEVATION)
        TC_LOG_DEBUG("misc", "splineElevation: %f", splineElevation);
}

WorldObject::WorldObject(bool isWorldObject) : WorldLocation(), LastUsedScriptID(0),
m_name(""), m_isActive(false), m_isFarVisible(false), m_isWorldObject(isWorldObject), m_zoneScript(nullptr),
m_transport(nullptr), m_zoneId(0), m_areaId(0), m_staticFloorZ(VMAP_INVALID_HEIGHT), m_currMap(nullptr), m_InstanceId(0),
m_phaseMask(PHASEMASK_NORMAL), _dbPhase(0), m_notifyflags(0), m_executed_notifies(0),
m_aiAnimKitId(0), m_movementAnimKitId(0), m_meleeAnimKitId(0)
{
    m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE | GHOST_VISIBILITY_GHOST);
    m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);
}

void WorldObject::SetWorldObject(bool on)
{
    if (!IsInWorld())
        return;

    GetMap()->AddObjectToSwitchList(this, on);
}

bool WorldObject::IsWorldObject() const
{
    if (m_isWorldObject)
        return true;

    if (ToCreature() && ToCreature()->m_isTempWorldObject)
        return true;

    return false;
}

void WorldObject::setActive(bool on)
{
    if (m_isActive == on)
        return;

    if (GetTypeId() == TYPEID_PLAYER)
        return;

    m_isActive = on;

    if (!IsInWorld())
        return;

    Map* map = FindMap();
    if (!map)
        return;

    if (on)
    {
        if (GetTypeId() == TYPEID_UNIT)
            map->AddToActive(this->ToCreature());
        else if (GetTypeId() == TYPEID_DYNAMICOBJECT)
            map->AddToActive((DynamicObject*)this);
    }
    else
    {
        if (GetTypeId() == TYPEID_UNIT)
            map->RemoveFromActive(this->ToCreature());
        else if (GetTypeId() == TYPEID_DYNAMICOBJECT)
            map->RemoveFromActive((DynamicObject*)this);
    }
}

void WorldObject::SetFarVisible(bool on)
{
    if (GetTypeId() == TYPEID_PLAYER)
        return;

    m_isFarVisible = on;
}

void WorldObject::SetVisibilityDistanceOverride(VisibilityDistanceType type)
{
    ASSERT(type < VisibilityDistanceType::Max);
    if (GetTypeId() == TYPEID_PLAYER)
        return;

    m_visibilityDistanceOverride = VisibilityDistances[AsUnderlyingType(type)];
}

void WorldObject::CleanupsBeforeDelete(bool /*finalCleanup*/)
{
    if (IsInWorld())
        RemoveFromWorld();

    if (Transport* transport = GetTransport())
        transport->RemovePassenger(this);
}

void WorldObject::_Create(ObjectGuid::LowType guidlow, HighGuid guidhigh, uint32 phaseMask)
{
    Object::_Create(guidlow, 0, guidhigh);
    m_phaseMask = phaseMask;
}

void WorldObject::UpdatePositionData()
{
    PositionFullTerrainStatus data;
    GetMap()->GetFullTerrainStatusForPosition(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ(), data);
    ProcessPositionDataChanged(data);
}

void WorldObject::ProcessPositionDataChanged(PositionFullTerrainStatus const& data)
{
    m_zoneId = m_areaId = data.areaId;
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(m_areaId))
        if (area->zone)
            m_zoneId = area->zone;
    m_outdoors = data.outdoors;
    m_staticFloorZ = data.floorZ;
}

void WorldObject::AddToWorld()
{
    Object::AddToWorld();
    GetMap()->GetZoneAndAreaId(GetPhaseShift(), m_zoneId, m_areaId, GetPositionX(), GetPositionY(), GetPositionZ());
}
void WorldObject::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    DestroyForNearbyPlayers();

    Object::RemoveFromWorld();
}

InstanceScript* WorldObject::GetInstanceScript() const
{
    Map* map = GetMap();
    return map->IsDungeon() ? ((InstanceMap*)map)->GetInstanceScript() : nullptr;
}

float WorldObject::GetDistanceZ(const WorldObject* obj) const
{
    float dz = std::fabs(GetPositionZ() - obj->GetPositionZ());
    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float dist = dz - sizefactor;
    return (dist > 0 ? dist : 0);
}

bool WorldObject::_IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D) const
{
    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float maxdist = dist2compare + sizefactor;

    if (GetTransport() && obj->GetTransport() && obj->GetTransport()->GetGUID().GetCounter() == GetTransport()->GetGUID().GetCounter())
    {
        float dtx = m_movementInfo.transport.pos.m_positionX - obj->m_movementInfo.transport.pos.m_positionX;
        float dty = m_movementInfo.transport.pos.m_positionY - obj->m_movementInfo.transport.pos.m_positionY;
        float disttsq = dtx * dtx + dty * dty;
        if (is3D)
        {
            float dtz = m_movementInfo.transport.pos.m_positionZ - obj->m_movementInfo.transport.pos.m_positionZ;
            disttsq += dtz * dtz;
        }
        return disttsq < (maxdist * maxdist);
    }

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float distsq = dx*dx + dy*dy;
    if (is3D)
    {
        float dz = GetPositionZ() - obj->GetPositionZ();
        distsq += dz*dz;
    }

    return distsq < maxdist * maxdist;
}

float WorldObject::GetDistance(const WorldObject* obj) const
{
    float d = GetExactDist(obj) - GetCombatReach() - obj->GetCombatReach();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance(const Position &pos) const
{
    float d = GetExactDist(&pos) - GetCombatReach();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance(float x, float y, float z) const
{
    float d = GetExactDist(x, y, z) - GetCombatReach();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance2d(const WorldObject* obj) const
{
    float d = GetExactDist2d(obj) - GetCombatReach() - obj->GetCombatReach();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance2d(float x, float y) const
{
    float d = GetExactDist2d(x, y) - GetCombatReach();
    return d > 0.0f ? d : 0.0f;
}

bool WorldObject::IsSelfOrInSameMap(const WorldObject* obj) const
{
    if (this == obj)
        return true;
    return IsInMap(obj);
}

bool WorldObject::IsInMap(const WorldObject* obj) const
{
    if (obj)
        return IsInWorld() && obj->IsInWorld() && (GetMap() == obj->GetMap());
    return false;
}

bool WorldObject::IsWithinDist3d(float x, float y, float z, float dist) const
{
    return IsInDist(x, y, z, dist);
}

bool WorldObject::IsWithinDist3d(const Position* pos, float dist) const
{
    return IsInDist(pos, dist);
}

bool WorldObject::IsWithinDist2d(float x, float y, float dist) const
{
    return IsInDist2d(x, y, dist);
}

bool WorldObject::IsWithinDist2d(const Position* pos, float dist) const
{
    return IsInDist2d(pos, dist);
}

bool WorldObject::IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D /*= true*/) const
{
    return obj && _IsWithinDist(obj, dist2compare, is3D);
}

bool WorldObject::IsWithinDistInMap(WorldObject const* obj, float dist2compare, bool is3D /*= true*/) const
{
    return obj && IsInMap(obj) && IsInPhase(obj) && _IsWithinDist(obj, dist2compare, is3D);
}

Position WorldObject::GetHitSpherePointFor(Position const& dest) const
{
    G3D::Vector3 vThis(GetPositionX(), GetPositionY(), GetPositionZ());
    G3D::Vector3 vObj(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
    G3D::Vector3 contactPoint = vThis + (vObj - vThis).directionOrZero() * std::min(dest.GetExactDist(GetPosition()), GetCombatReach());

    return Position(contactPoint.x, contactPoint.y, contactPoint.z, GetAngle(contactPoint.x, contactPoint.y));
}

bool WorldObject::IsWithinLOS(float ox, float oy, float oz, LineOfSightChecks checks, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if (IsInWorld())
    {
        float x, y, z;
        if (GetTypeId() == TYPEID_PLAYER)
            GetPosition(x, y, z);
        else
            GetHitSpherePointFor({ ox, oy, oz }, x, y, z);

        return GetMap()->isInLineOfSight(GetPhaseShift(), x, y, z + 2.0f, ox, oy, oz + 2.0f, checks, ignoreFlags);
    }

    return true;
}

bool WorldObject::IsWithinLOSInMap(const WorldObject* obj, LineOfSightChecks checks, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if (!IsInMap(obj))
        return false;

    float x, y, z;
    if (obj->GetTypeId() == TYPEID_PLAYER)
        obj->GetPosition(x, y, z);
    else
        obj->GetHitSpherePointFor(GetPosition(), x, y, z);

    return IsWithinLOS(x, y, z, checks, ignoreFlags);
}

void WorldObject::GetHitSpherePointFor(Position const& dest, float& x, float& y, float& z) const
{
    Position pos = GetHitSpherePointFor(dest);
    x = pos.GetPositionX();
    y = pos.GetPositionY();
    z = pos.GetPositionZ();
}

bool WorldObject::GetDistanceOrder(WorldObject const* obj1, WorldObject const* obj2, bool is3D /* = true */) const
{
    float dx1 = GetPositionX() - obj1->GetPositionX();
    float dy1 = GetPositionY() - obj1->GetPositionY();
    float distsq1 = dx1*dx1 + dy1*dy1;
    if (is3D)
    {
        float dz1 = GetPositionZ() - obj1->GetPositionZ();
        distsq1 += dz1*dz1;
    }

    float dx2 = GetPositionX() - obj2->GetPositionX();
    float dy2 = GetPositionY() - obj2->GetPositionY();
    float distsq2 = dx2*dx2 + dy2*dy2;
    if (is3D)
    {
        float dz2 = GetPositionZ() - obj2->GetPositionZ();
        distsq2 += dz2*dz2;
    }

    return distsq1 < distsq2;
}

bool WorldObject::IsInRange(WorldObject const* obj, float minRange, float maxRange, bool is3D /* = true */) const
{
    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float distsq = dx*dx + dy*dy;
    if (is3D)
    {
        float dz = GetPositionZ() - obj->GetPositionZ();
        distsq += dz*dz;
    }

    float sizefactor = GetCombatReach() + obj->GetCombatReach();

    // check only for real range
    if (minRange > 0.0f)
    {
        float mindist = minRange + sizefactor;
        if (distsq < mindist * mindist)
            return false;
    }

    float maxdist = maxRange + sizefactor;
    return distsq < maxdist * maxdist;
}

bool WorldObject::IsInRange2d(float x, float y, float minRange, float maxRange) const
{
    float dx = GetPositionX() - x;
    float dy = GetPositionY() - y;
    float distsq = dx*dx + dy*dy;

    float sizefactor = GetCombatReach();

    // check only for real range
    if (minRange > 0.0f)
    {
        float mindist = minRange + sizefactor;
        if (distsq < mindist * mindist)
            return false;
    }

    float maxdist = maxRange + sizefactor;
    return distsq < maxdist * maxdist;
}

bool WorldObject::IsInRange3d(float x, float y, float z, float minRange, float maxRange) const
{
    float dx = GetPositionX() - x;
    float dy = GetPositionY() - y;
    float dz = GetPositionZ() - z;
    float distsq = dx*dx + dy*dy + dz*dz;

    float sizefactor = GetCombatReach();

    // check only for real range
    if (minRange > 0.0f)
    {
        float mindist = minRange + sizefactor;
        if (distsq < mindist * mindist)
            return false;
    }

    float maxdist = maxRange + sizefactor;
    return distsq < maxdist * maxdist;
}

bool WorldObject::IsInBetween(Position const& pos1, Position const& pos2, float size) const
{
    float dist = GetExactDist2d(pos1);

    // not using sqrt() for performance
    if ((dist * dist) >= pos1.GetExactDist2dSq(pos2))
        return false;

    if (!size)
        size = GetCombatReach() / 2;

    float angle = pos1.GetAngle(pos2);

    // not using sqrt() for performance
    return (size * size) >= GetExactDist2dSq(pos1.GetPositionX() + std::cos(angle) * dist, pos1.GetPositionY() + std::sin(angle) * dist);
}

bool WorldObject::isInFront(WorldObject const* target,  float arc) const
{
    return HasInArc(arc, target);
}

bool WorldObject::isInBack(WorldObject const* target, float arc) const
{
    return !HasInArc(2 * float(M_PI) - arc, target);
}

void WorldObject::GetRandomPoint(const Position &pos, float distance, float &rand_x, float &rand_y, float &rand_z) const
{
    if (!distance)
    {
        pos.GetPosition(rand_x, rand_y, rand_z);
        return;
    }

    // angle to face `obj` to `this`
    float angle = (float)rand_norm()*static_cast<float>(2*M_PI);
    float new_dist = (float)rand_norm() + (float)rand_norm();
    new_dist = distance * (new_dist > 1 ? new_dist - 2 : new_dist);

    rand_x = pos.m_positionX + new_dist * std::cos(angle);
    rand_y = pos.m_positionY + new_dist * std::sin(angle);
    rand_z = pos.m_positionZ;

    Trinity::NormalizeMapCoord(rand_x);
    Trinity::NormalizeMapCoord(rand_y);
    UpdateGroundPositionZ(rand_x, rand_y, rand_z);            // update to LOS height if available
}

Position WorldObject::GetRandomPoint(const Position &srcPos, float distance) const
{
    float x, y, z;
    GetRandomPoint(srcPos, distance, x, y, z);
    return Position(x, y, z, GetOrientation());
}

void WorldObject::UpdateGroundPositionZ(float x, float y, float &z) const
{
    float new_z = GetMap()->GetHeight(GetPhaseShift(), x, y, z + 2.0f, true);
    if (new_z > INVALID_HEIGHT)
        z = new_z + 0.05f;                                   // just to be sure that we are not a few pixel under the surface
}

void WorldObject::UpdateAllowedPositionZ(float x, float y, float &z) const
{
    // TODO: Allow transports to be part of dynamic vmap tree
    if (GetTransport())
        return;

    switch (GetTypeId())
    {
        case TYPEID_UNIT:
        {
            // non fly unit don't must be in air
            // non swim unit must be at ground (mostly speedup, because it don't must be in water and water level check less fast
            if (!ToCreature()->CanFly())
            {
                bool canSwim = ToCreature()->CanSwim();
                float ground_z = z;
                float max_z = canSwim
                    ? GetMap()->GetWaterOrGroundLevel(GetPhaseShift(), x, y, z, &ground_z, !ToUnit()->HasAuraType(SPELL_AURA_WATER_WALK))
                    : ((ground_z = GetMap()->GetHeight(GetPhaseShift(), x, y, z, true)));
                if (max_z > INVALID_HEIGHT)
                {
                    if (z > max_z)
                        z = max_z;
                    else if (z < ground_z)
                        z = ground_z;
                }
            }
            else
            {
                float ground_z = GetMap()->GetHeight(GetPhaseShift(), x, y, z, true);
                if (z < ground_z)
                    z = ground_z;
            }
            break;
        }
        case TYPEID_PLAYER:
        {
            // for server controlled moves playr work same as creature (but it can always swim)
            if (!ToPlayer()->CanFly())
            {
                float ground_z = z;
                float max_z = GetMap()->GetWaterOrGroundLevel(GetPhaseShift(), x, y, z, &ground_z, !ToUnit()->HasAuraType(SPELL_AURA_WATER_WALK));
                if (max_z > INVALID_HEIGHT)
                {
                    if (z > max_z)
                        z = max_z;
                    else if (z < ground_z)
                        z = ground_z;
                }
            }
            else
            {
                float ground_z = GetMap()->GetHeight(GetPhaseShift(), x, y, z, true);
                if (z < ground_z)
                    z = ground_z;
            }
            break;
        }
        default:
        {
            float ground_z = GetMap()->GetHeight(GetPhaseShift(), x, y, z, true);
            if (ground_z > INVALID_HEIGHT)
                z = ground_z;
            break;
        }
    }
}

float WorldObject::GetGridActivationRange() const
{
    if (isActiveObject())
    {
        if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetCinematicMgr()->IsOnCinematic())
            return std::max(DEFAULT_VISIBILITY_INSTANCE, GetMap()->GetVisibilityRange());

        return GetMap()->GetVisibilityRange();
    }

    if (Creature const* thisCreature = ToCreature())
        return thisCreature->m_SightDistance;

    return 0.0f;
}

float WorldObject::GetVisibilityRange() const
{
    if (IsVisibilityOverriden() && !ToPlayer())
        return *m_visibilityDistanceOverride;
    else if (IsFarVisible() && !ToPlayer())
        return MAX_VISIBILITY_DISTANCE;
    else
        return GetMap()->GetVisibilityRange();
}

float WorldObject::GetSightRange(const WorldObject* target) const
{
    if (ToUnit())
    {
        if (ToPlayer())
        {
            if (target && target->IsVisibilityOverriden() && !target->ToPlayer())
                return *target->m_visibilityDistanceOverride;
            else if (target && target->IsFarVisible() && !target->ToPlayer())
                return MAX_VISIBILITY_DISTANCE;
            else if (ToPlayer()->GetCinematicMgr()->IsOnCinematic())
                return DEFAULT_VISIBILITY_INSTANCE;
            else
                return GetMap()->GetVisibilityRange();
        }
        else if (ToCreature())
            return ToCreature()->m_SightDistance;
        else
            return SIGHT_RANGE_UNIT;
    }

    if (ToDynObject() && isActiveObject())
        return GetMap()->GetVisibilityRange();

    return 0.0f;
}

bool WorldObject::CanSeeOrDetect(WorldObject const* obj, bool ignoreStealth, bool distanceCheck, bool checkAlert) const
{
    if (this == obj)
        return true;

    if (obj->IsNeverVisible() || CanNeverSee(obj))
        return false;

    if (obj->IsAlwaysVisibleFor(this) || CanAlwaysSee(obj))
        return true;

    bool corpseVisibility = false;
    if (distanceCheck)
    {
        bool corpseCheck = false;
        if (Player const* thisPlayer = ToPlayer())
        {
            if (thisPlayer->isDead() && thisPlayer->GetHealth() > 0 && // Cheap way to check for ghost state
                !(obj->m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GHOST) & m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GHOST) & GHOST_VISIBILITY_GHOST))
            {
                if (Corpse* corpse = thisPlayer->GetCorpse())
                {
                    corpseCheck = true;
                    if (corpse->IsWithinDist(thisPlayer, GetSightRange(obj), false))
                        if (corpse->IsWithinDist(obj, GetSightRange(obj), false))
                            corpseVisibility = true;
                }
            }

            if (Unit const* target = obj->ToUnit())
            {
                // Don't allow to detect vehicle accessories if you can't see vehicle
                if (Unit const* vehicle = target->GetVehicleBase())
                    if (!thisPlayer->HaveAtClient(vehicle))
                        return false;
            }
        }

        WorldObject const* viewpoint = this;
        if (Player const* player = this->ToPlayer())
        {
            viewpoint = player->GetViewpoint();

            if (Creature const* creature = obj->ToCreature())
                if (TempSummon const* tempSummon = creature->ToTempSummon())
                    if (tempSummon->IsVisibleBySummonerOnly() && GetGUID() != tempSummon->GetSummonerGUID())
                        return false;
        }

        if (!viewpoint)
            viewpoint = this;

        if (!corpseCheck && !viewpoint->IsWithinDist(obj, GetSightRange(obj), false))
            return false;
    }

    // GM visibility off or hidden NPC
    if (!obj->m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GM))
    {
        // Stop checking other things for GMs
        if (m_serverSideVisibilityDetect.GetValue(SERVERSIDE_VISIBILITY_GM))
            return true;
    }
    else
        return m_serverSideVisibilityDetect.GetValue(SERVERSIDE_VISIBILITY_GM) >= obj->m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GM);

    // Ghost players, Spirit Healers, and some other NPCs
    if (!corpseVisibility && !(obj->m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GHOST) & m_serverSideVisibilityDetect.GetValue(SERVERSIDE_VISIBILITY_GHOST)))
    {
        // Alive players can see dead players in some cases, but other objects can't do that
        if (Player const* thisPlayer = ToPlayer())
        {
            if (Player const* objPlayer = obj->ToPlayer())
            {
                if (thisPlayer->GetTeam() != objPlayer->GetTeam() || !thisPlayer->IsGroupVisibleFor(objPlayer))
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }

    if (obj->IsInvisibleDueToDespawn())
        return false;

    if (!CanDetect(obj, ignoreStealth, checkAlert))
        return false;

    return true;
}

bool WorldObject::CanNeverSee(WorldObject const* obj) const
{
    return GetMap() != obj->GetMap() || !IsInPhase(obj);
}

bool WorldObject::CanDetect(WorldObject const* obj, bool ignoreStealth, bool checkAlert) const
{
    const WorldObject* seer = this;

    // Pets don't have detection, they use the detection of their masters
    if (Unit const* thisUnit = ToUnit())
        if (Unit* controller = thisUnit->GetCharmerOrOwner())
            seer = controller;

    if (obj->IsAlwaysDetectableFor(seer))
        return true;

    if (!ignoreStealth && !seer->CanDetectInvisibilityOf(obj))
        return false;

    if (!ignoreStealth && !seer->CanDetectStealthOf(obj, checkAlert))
        return false;

    return true;
}

bool WorldObject::CanDetectInvisibilityOf(WorldObject const* obj) const
{
    uint32 mask = obj->m_invisibility.GetFlags() & m_invisibilityDetect.GetFlags();

    // Check for not detected types
    if (mask != obj->m_invisibility.GetFlags())
        return false;

    for (uint32 i = 0; i < TOTAL_INVISIBILITY_TYPES; ++i)
    {
        if (!(mask & (1 << i)))
            continue;

        int32 objInvisibilityValue = obj->m_invisibility.GetValue(InvisibilityType(i));
        int32 ownInvisibilityDetectValue = m_invisibilityDetect.GetValue(InvisibilityType(i));

        // Too low value to detect
        if (ownInvisibilityDetectValue < objInvisibilityValue)
            return false;
    }

    return true;
}

bool WorldObject::CanDetectStealthOf(WorldObject const* obj, bool checkAlert) const
{
    // Combat reach is the minimal distance (both in front and behind),
    //   and it is also used in the range calculation.
    // One stealth point increases the visibility range by 0.3 yard.

    if (!obj->m_stealth.GetFlags())
        return true;

    float distance = GetExactDist(obj);
    float combatReach = 0.0f;

    Unit const* unit = ToUnit();
    if (unit)
        combatReach = unit->GetCombatReach();

    if (distance < combatReach)
        return true;

    if (!HasInArc(float(M_PI), obj))
        return false;

    GameObject const* go = obj->ToGameObject();
    for (uint32 i = 0; i < TOTAL_STEALTH_TYPES; ++i)
    {
        if (!(obj->m_stealth.GetFlags() & (1 << i)))
            continue;

        if (unit && unit->HasAuraTypeWithMiscvalue(SPELL_AURA_DETECT_STEALTH, i))
            return true;

        // Starting points
        int32 detectionValue = 30;

        // Level difference: 5 point / level, starting from level 1.
        // There may be spells for this and the starting points too, but
        // not in the DBCs of the client.
        detectionValue += int32(getLevelForTarget(obj) - 1) * 5;

        // Apply modifiers
        detectionValue += m_stealthDetect.GetValue(StealthType(i));
        if (go)
            if (Unit* owner = go->GetOwner())
                detectionValue -= int32(owner->getLevelForTarget(this) - 1) * 5;

        detectionValue -= obj->m_stealth.GetValue(StealthType(i));

        // Calculate max distance
        float visibilityRange = float(detectionValue) * 0.3f + combatReach;

        // If this unit is an NPC then player detect range doesn't apply
        if (unit && unit->GetTypeId() == TYPEID_PLAYER && visibilityRange > MAX_PLAYER_STEALTH_DETECT_RANGE)
            visibilityRange = MAX_PLAYER_STEALTH_DETECT_RANGE;

        // When checking for alert state, look 8% further, and then 1.5 yards more than that.
        if (checkAlert)
            visibilityRange += (visibilityRange * 0.08f) + 1.5f;

        // If checking for alert, and creature's visibility range is greater than aggro distance, No alert
        Unit const* tunit = obj->ToUnit();
        if (checkAlert && unit && unit->ToCreature() && visibilityRange >= unit->ToCreature()->GetAttackDistance(tunit) + unit->ToCreature()->m_CombatDistance)
            return false;

        if (distance > visibilityRange)
            return false;
    }

    return true;
}

void Object::ForceValuesUpdateAtIndex(uint32 i)
{
    _changesMask.SetBit(i);
    AddToObjectUpdateIfNeeded();
}

void WorldObject::SendMessageToSet(WorldPacket* data, bool self)
{
    if (IsInWorld())
        SendMessageToSetInRange(data, GetVisibilityRange(), self);
}

void WorldObject::SendMessageToSetInRange(WorldPacket* data, float dist, bool /*self*/)
{
    Trinity::MessageDistDeliverer notifier(this, data, dist);
    Cell::VisitWorldObjects(this, notifier, dist);
}

void WorldObject::SendMessageToSet(WorldPacket* data, Player const* skipped_rcvr)
{
    Trinity::MessageDistDeliverer notifier(this, data, GetVisibilityRange(), false, skipped_rcvr);
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
}

void WorldObject::SetMap(Map* map)
{
    ASSERT(map);
    ASSERT(!IsInWorld());
    if (m_currMap == map) // command add npc: first create, than loadfromdb
        return;
    if (m_currMap)
    {
        TC_LOG_FATAL("misc", "WorldObject::SetMap: obj %u new map %u %u, old map %u %u", (uint32)GetTypeId(), map->GetId(), map->GetInstanceId(), m_currMap->GetId(), m_currMap->GetInstanceId());
        ABORT();
    }
    m_currMap = map;
    m_mapId = map->GetId();
    m_InstanceId = map->GetInstanceId();
    if (IsWorldObject())
        m_currMap->AddWorldObject(this);
}

void WorldObject::ResetMap()
{
    ASSERT(m_currMap);
    ASSERT(!IsInWorld());
    if (IsWorldObject())
        m_currMap->RemoveWorldObject(this);
    m_currMap = nullptr;
    //maybe not for corpse
    //m_mapId = 0;
    //m_InstanceId = 0;
}

Map const* WorldObject::GetBaseMap() const
{
    ASSERT(m_currMap);
    return m_currMap->GetParent();
}

void WorldObject::AddObjectToRemoveList()
{
    ASSERT(m_uint32Values);

    Map* map = FindMap();
    if (!map)
    {
        TC_LOG_ERROR("misc", "Object (TypeId: %u Entry: %u GUID: %u) at attempt add to move list not have valid map (Id: %u).", GetTypeId(), GetEntry(), GetGUID().GetCounter(), GetMapId());
        return;
    }

    map->AddObjectToRemoveList(this);
}

TempSummon* Map::SummonCreature(uint32 entry, Position const& pos, SummonPropertiesEntry const* properties /*= NULL*/, uint32 duration /*= 0*/, Unit* summoner /*= NULL*/, uint32 spellId /*= 0*/, uint32 vehId /*= 0*/, bool visibleBySummonerOnly /*= false*/)
{
    uint32 mask = UNIT_MASK_SUMMON;
    if (properties)
    {
        switch (properties->Category)
        {
            case SUMMON_CATEGORY_PET:
                mask = UNIT_MASK_GUARDIAN;
                break;
            case SUMMON_CATEGORY_PUPPET:
                mask = UNIT_MASK_PUPPET;
                break;
            case SUMMON_CATEGORY_VEHICLE:
                mask = UNIT_MASK_MINION;
                break;
            case SUMMON_CATEGORY_WILD:
            case SUMMON_CATEGORY_ALLY:
            case SUMMON_CATEGORY_UNK:
            {
                switch (properties->Type)
                {
                    case SUMMON_TYPE_MINION:
                    case SUMMON_TYPE_GUARDIAN:
                    case SUMMON_TYPE_GUARDIAN2:
                        mask = UNIT_MASK_GUARDIAN;
                        break;
                    case SUMMON_TYPE_TOTEM:
                    case SUMMON_TYPE_LIGHTWELL:
                        mask = UNIT_MASK_TOTEM;
                        break;
                    case SUMMON_TYPE_VEHICLE:
                    case SUMMON_TYPE_VEHICLE2:
                        mask = UNIT_MASK_SUMMON;
                        break;
                    case SUMMON_TYPE_MINIPET:
                        mask = UNIT_MASK_MINION;
                        break;
                    default:
                        if (properties->Flags & 512) // Mirror Image, Summon Gargoyle
                            mask = UNIT_MASK_GUARDIAN;
                    break;
                }
                break;
            }
            default:
                return nullptr;
        }
    }

    TempSummon* summon = nullptr;
    switch (mask)
    {
        case UNIT_MASK_SUMMON:
            summon = new TempSummon(properties, summoner, false);
            break;
        case UNIT_MASK_GUARDIAN:
            summon = new Guardian(properties, summoner, false);
            break;
        case UNIT_MASK_PUPPET:
            summon = new Puppet(properties, summoner);
            break;
        case UNIT_MASK_TOTEM:
            summon = new Totem(properties, summoner);
            break;
        case UNIT_MASK_MINION:
            summon = new Minion(properties, summoner, false);
            break;
    }

    if (!summon->Create(GenerateLowGuid<HighGuid::Unit>(), this, 0, entry, pos, nullptr, vehId, true))
    {
        delete summon;
        return nullptr;
    }

    if (summon->GetTransGUID().IsEmpty() && summoner)
    {
        if (Transport* transport = summoner->GetTransport())
        {
            float x, y, z, o;
            pos.GetPosition(x, y, z, o);
            transport->CalculatePassengerOffset(x, y, z, &o);
            summon->m_movementInfo.transport.pos.Relocate(x, y, z, o);

            transport->AddPassenger(summon);
        }
    }

    // Set the summon to the summoner's phase
    if (summoner)
        PhasingHandler::InheritPhaseShift(summon, summoner);

    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);

    summon->SetHomePosition(pos);

    summon->InitStats(duration);

    summon->SetVisibleBySummonerOnly(visibleBySummonerOnly);

    AddToMap(summon->ToCreature());
    summon->InitSummon();

    // call MoveInLineOfSight for nearby creatures
    Trinity::AIRelocationNotifier notifier(*summon);
    Cell::VisitAllObjects(summon, notifier, GetVisibilityRange());

    return summon;
}

/**
* Summons group of creatures.
*
* @param group Id of group to summon.
* @param list  List to store pointers to summoned creatures.
*/

void Map::SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list /*= nullptr*/)
{
    std::vector<TempSummonData> const* data = sObjectMgr->GetSummonGroup(GetId(), SUMMONER_TYPE_MAP, group);
    if (!data)
        return;

    for (std::vector<TempSummonData>::const_iterator itr = data->begin(); itr != data->end(); ++itr)
        if (TempSummon* summon = SummonCreature(itr->entry, itr->pos, nullptr, itr->time))
            if (list)
                list->push_back(summon);
}

void WorldObject::SetZoneScript()
{
    if (Map* map = FindMap())
    {
        if (map->IsDungeon())
            m_zoneScript = (ZoneScript*)((InstanceMap*)map)->GetInstanceScript();
        else if (!map->IsBattlegroundOrArena())
        {
            if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(GetZoneId()))
                m_zoneScript = bf;
            else
                m_zoneScript = sOutdoorPvPMgr->GetZoneScript(GetZoneId());
        }
    }
}

void WorldObject::ClearZoneScript()
{
    m_zoneScript = nullptr;
}

TempSummon* WorldObject::SummonCreature(uint32 entry, Position const& pos, TempSummonType despawnType /*= TEMPSUMMON_MANUAL_DESPAWN*/, uint32 despawnTime /*= 0*/, uint32 vehId /*= 0*/, bool visibleBySummonerOnly /*= false*/)
{
    if (Map* map = FindMap())
    {
        if (TempSummon* summon = map->SummonCreature(entry, pos, nullptr, despawnTime, ToUnit(), 0, vehId, visibleBySummonerOnly))
        {
            summon->SetTempSummonType(despawnType);
            return summon;
        }
    }

    return nullptr;
}

TempSummon* WorldObject::SummonCreature(uint32 id, float x, float y, float z, float o /*= 0*/, TempSummonType despawnType /*= TEMPSUMMON_MANUAL_DESPAWN*/, uint32 despawnTime /*= 0*/, bool visibleBySummonerOnly /*= false*/)
{
    if (!x && !y && !z)
        GetClosePoint(x, y, z, GetCombatReach());
    if (!o)
        o = GetOrientation();
    return SummonCreature(id, { x, y, z, o }, despawnType, despawnTime, 0, visibleBySummonerOnly);
}

GameObject* WorldObject::SummonGameObject(uint32 entry, Position const& pos, QuaternionData const& rot, uint32 respawnTime, GOSummonType summonType)
{
    if (!IsInWorld())
        return nullptr;

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject template %u not found in database!", entry);
        return nullptr;
    }

    Map* map = GetMap();
    GameObject* go = nullptr;
    if (goinfo->type == GAMEOBJECT_TYPE_TRANSPORT)
    {
        go = new Transport();
        if (!go->Create(map->GenerateLowGuid<HighGuid::Transport>(), entry, map, GetPhaseMask(), pos, rot, 255, GO_STATE_READY))
        {
            delete go;
            return nullptr;
        }
    }
    else
    {
        go = new GameObject();
        if (!go->Create(map->GenerateLowGuid<HighGuid::GameObject>(), entry, map, GetPhaseMask(), pos, rot, 255, GO_STATE_READY))
        {
            delete go;
            return nullptr;
        }
    }

    PhasingHandler::InheritPhaseShift(go, this);

    go->SetRespawnTime(respawnTime);
    if (GetTypeId() == TYPEID_PLAYER || (GetTypeId() == TYPEID_UNIT && summonType == GO_SUMMON_TIMED_OR_CORPSE_DESPAWN)) //not sure how to handle this
        ToUnit()->AddGameObject(go);
    else
        go->SetSpawnedByDefault(false);

    Transport* transport = GetTransGUID().IsEmpty() ? GetTransport() : nullptr;
    if (transport)
    {
        float x, y, z, o;
        go->GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        go->m_movementInfo.transport.pos.Relocate(x, y, z, o);

        transport->AddPassenger(go);
    }

    map->AddToMap(go);
    return go;
}

GameObject* WorldObject::SummonGameObject(uint32 entry, float x, float y, float z, float ang, QuaternionData const& rot, uint32 respawnTime)
{
    if (!x && !y && !z)
    {
        GetClosePoint(x, y, z, GetCombatReach());
        ang = GetOrientation();
    }

    Position pos(x, y, z, ang);
    return SummonGameObject(entry, pos, rot, respawnTime);
}

Creature* WorldObject::SummonTrigger(float x, float y, float z, float ang, uint32 duration, CreatureAI* (*GetAI)(Creature*))
{
    TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;
    Creature* summon = SummonCreature(WORLD_TRIGGER, x, y, z, ang, summonType, duration);
    if (!summon)
        return nullptr;

    //summon->SetName(GetName());
    if (GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT)
    {
        summon->SetFaction(((Unit*)this)->GetFaction());
        summon->SetLevel(((Unit*)this)->getLevel());
    }

    if (GetAI)
        summon->AIM_Initialize(GetAI(summon));
    return summon;
}

/**
* Summons group of creatures. Should be called only by instances of Creature and GameObject classes.
*
* @param group Id of group to summon.
* @param list  List to store pointers to summoned creatures.
*/
void WorldObject::SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list /*= nullptr*/)
{
    ASSERT((GetTypeId() == TYPEID_GAMEOBJECT || GetTypeId() == TYPEID_UNIT) && "Only GOs and creatures can summon npc groups!");

    std::vector<TempSummonData> const* data = sObjectMgr->GetSummonGroup(GetEntry(), GetTypeId() == TYPEID_GAMEOBJECT ? SUMMONER_TYPE_GAMEOBJECT : SUMMONER_TYPE_CREATURE, group);
    if (!data)
    {
        TC_LOG_WARN("scripts", "%s (%s) tried to summon non-existing summon group %u.", GetName().c_str(), GetGUID().ToString().c_str(), group);
        return;
    }

    for (std::vector<TempSummonData>::const_iterator itr = data->begin(); itr != data->end(); ++itr)
        if (TempSummon* summon = SummonCreature(itr->entry, itr->pos, itr->type, itr->time))
            if (list)
                list->push_back(summon);
}

Creature* WorldObject::FindNearestCreature(uint32 entry, float range, bool alive) const
{
    Creature* creature = nullptr;
    Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck checker(*this, entry, alive, range);
    Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(this, creature, checker);
    Cell::VisitAllObjects(this, searcher, range);
    return creature;
}

GameObject* WorldObject::FindNearestGameObject(uint32 entry, float range) const
{
    GameObject* go = nullptr;
    Trinity::NearestGameObjectEntryInObjectRangeCheck checker(*this, entry, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectEntryInObjectRangeCheck> searcher(this, go, checker);
    Cell::VisitGridObjects(this, searcher, range);
    return go;
}

GameObject* WorldObject::FindNearestGameObjectOfType(GameobjectTypes type, float range) const
{
    GameObject* go = nullptr;
    Trinity::NearestGameObjectTypeInObjectRangeCheck checker(*this, type, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectTypeInObjectRangeCheck> searcher(this, go, checker);
    Cell::VisitGridObjects(this, searcher, range);
    return go;
}

Player* WorldObject::SelectNearestPlayer(float distance) const
{
    Player* target = nullptr;

    Trinity::NearestPlayerInObjectRangeCheck checker(this, distance);
    Trinity::PlayerLastSearcher<Trinity::NearestPlayerInObjectRangeCheck> searcher(this, target, checker);
    Cell::VisitWorldObjects(this, searcher, distance);

    return target;
}

template <typename Container>
void WorldObject::GetGameObjectListWithEntryInGrid(Container& gameObjectContainer, uint32 entry, float maxSearchRange /*= 250.0f*/) const
{
    Trinity::AllGameObjectsWithEntryInRange check(this, entry, maxSearchRange);
    Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInRange> searcher(this, gameObjectContainer, check);
    Cell::VisitGridObjects(this, searcher, maxSearchRange);
}

template <typename Container>
void WorldObject::GetCreatureListWithEntryInGrid(Container& creatureContainer, uint32 entry, float maxSearchRange /*= 250.0f*/) const
{
    Trinity::AllCreaturesOfEntryInRange check(this, entry, maxSearchRange);
    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(this, creatureContainer, check);
    Cell::VisitGridObjects(this, searcher, maxSearchRange);
}

template <typename Container>
void WorldObject::GetPlayerListInGrid(Container& playerContainer, float maxSearchRange) const
{
    Trinity::AnyPlayerInObjectRangeCheck checker(this, maxSearchRange);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(this, playerContainer, checker);
    Cell::VisitWorldObjects(this, searcher, maxSearchRange);
}

void WorldObject::GetNearPoint2D(float &x, float &y, float distance2d, float absAngle) const
{
    x = GetPositionX() + (GetCombatReach() + distance2d) * std::cos(absAngle);
    y = GetPositionY() + (GetCombatReach() + distance2d) * std::sin(absAngle);

    Trinity::NormalizeMapCoord(x);
    Trinity::NormalizeMapCoord(y);
}

void WorldObject::GetNearPoint(WorldObject const* /*searcher*/, float &x, float &y, float &z, float searcher_size, float distance2d, float absAngle) const
{
    GetNearPoint2D(x, y, distance2d+searcher_size, absAngle);
    z = GetPositionZ();
    // Should "searcher" be used instead of "this" when updating z coordinate ?
    UpdateAllowedPositionZ(x, y, z);

    // if detection disabled, return first point
    if (!sWorld->getBoolConfig(CONFIG_DETECT_POS_COLLISION))
        return;

    // return if the point is already in LoS
    if (IsWithinLOS(x, y, z))
        return;

    // remember first point
    float first_x = x;
    float first_y = y;
    float first_z = z;

    // loop in a circle to look for a point in LoS using small steps
    for (float angle = float(M_PI) / 8; angle < float(M_PI) * 2; angle += float(M_PI) / 8)
    {
        GetNearPoint2D(x, y, distance2d + searcher_size, absAngle + angle);
        z = GetPositionZ();
        UpdateAllowedPositionZ(x, y, z);
        if (IsWithinLOS(x, y, z))
            return;
    }

    // still not in LoS, give up and return first position found
    x = first_x;
    y = first_y;
    z = first_z;
}

void WorldObject::GetClosePoint(float &x, float &y, float &z, float size, float distance2d /*= 0*/, float angle /*= 0*/) const
{
    // angle calculated from current orientation
    GetNearPoint(nullptr, x, y, z, size, distance2d, GetOrientation() + angle);
}

Position WorldObject::GetNearPosition(float dist, float angle)
{
    Position pos = GetPosition();
    MovePosition(pos, dist, angle);
    return pos;
}

Position WorldObject::GetFirstCollisionPosition(float dist, float angle)
{
    Position pos = GetPosition();
    MovePositionToFirstCollision(pos, dist, angle);
    return pos;
}

Position WorldObject::GetRandomNearPosition(float radius)
{
    Position pos = GetPosition();
    MovePosition(pos, radius * (float)rand_norm(), (float)rand_norm() * static_cast<float>(2 * M_PI));
    return pos;
}

void WorldObject::GetContactPoint(const WorldObject* obj, float &x, float &y, float &z, float distance2d /*= CONTACT_DISTANCE*/) const
{
    // angle to face `obj` to `this` using distance includes size of `obj`
    GetNearPoint(obj, x, y, z, obj->GetCombatReach(), distance2d, GetAngle(obj));
}

void WorldObject::MovePosition(Position &pos, float dist, float angle)
{
    angle += GetOrientation();
    float destx, desty, destz, ground, floor;
    destx = pos.m_positionX + dist * std::cos(angle);
    desty = pos.m_positionY + dist * std::sin(angle);

    // Prevent invalid coordinates here, position is unchanged
    if (!Trinity::IsValidMapCoord(destx, desty, pos.m_positionZ))
    {
        TC_LOG_FATAL("misc", "WorldObject::MovePosition: Object (TypeId: %u Entry: %u GUID: %u) has invalid coordinates X: %f and Y: %f were passed!",
            GetTypeId(), GetEntry(), GetGUID().GetCounter(), destx, desty);
        return;
    }

    ground = GetMap()->GetHeight(GetPhaseShift(), destx, desty, MAX_HEIGHT, true);
    floor = GetMap()->GetHeight(GetPhaseShift(), destx, desty, pos.m_positionZ, true);
    destz = std::fabs(ground - pos.m_positionZ) <= std::fabs(floor - pos.m_positionZ) ? ground : floor;

    float step = dist/10.0f;

    for (uint8 j = 0; j < 10; ++j)
    {
        // do not allow too big z changes
        if (std::fabs(pos.m_positionZ - destz) > 6)
        {
            destx -= step * std::cos(angle);
            desty -= step * std::sin(angle);
            ground = GetMap()->GetHeight(GetPhaseShift(), destx, desty, MAX_HEIGHT, true);
            floor = GetMap()->GetHeight(GetPhaseShift(), destx, desty, pos.m_positionZ, true);
            destz = std::fabs(ground - pos.m_positionZ) <= std::fabs(floor - pos.m_positionZ) ? ground : floor;
        }
        // we have correct destz now
        else
        {
            pos.Relocate(destx, desty, destz);
            break;
        }
    }

    Trinity::NormalizeMapCoord(pos.m_positionX);
    Trinity::NormalizeMapCoord(pos.m_positionY);
    UpdateGroundPositionZ(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
    pos.SetOrientation(GetOrientation());
}

// @todo: replace with WorldObject::UpdateAllowedPositionZ
float NormalizeZforCollision(WorldObject* obj, float x, float y, float z)
{
    float ground = obj->GetMap()->GetHeight(obj->GetPhaseShift(), x, y, MAX_HEIGHT, true);
    float floor = obj->GetMap()->GetHeight(obj->GetPhaseShift(), x, y, z + 2.0f, true);
    float helper = std::fabs(ground - z) <= std::fabs(floor - z) ? ground : floor;
    if (z > helper) // must be above ground
    {
        if (Unit* unit = obj->ToUnit())
        {
            if (unit->CanFly())
                return z;
        }
        LiquidData liquid_status;
        ZLiquidStatus res = obj->GetMap()->GetLiquidStatus(obj->GetPhaseShift(), x, y, z, MAP_ALL_LIQUIDS, &liquid_status);
        if (res && liquid_status.level > helper) // water must be above ground
        {
            if (liquid_status.level > z) // z is underwater
                return z;
            else
                return std::fabs(liquid_status.level - z) <= std::fabs(helper - z) ? liquid_status.level : helper;
        }
    }
    return helper;
}

void WorldObject::MovePositionToFirstCollision(Position &pos, float dist, float angle)
{
    angle += GetOrientation();
    float destx, desty, destz;
    destx = pos.m_positionX + dist * std::cos(angle);
    desty = pos.m_positionY + dist * std::sin(angle);

    // Prevent invalid coordinates here, position is unchanged
    if (!Trinity::IsValidMapCoord(destx, desty))
    {
        TC_LOG_FATAL("misc", "WorldObject::MovePositionToFirstCollision invalid coordinates X: %f and Y: %f were passed!", destx, desty);
        return;
    }

    destz = NormalizeZforCollision(this, destx, desty, pos.GetPositionZ());
    bool col = VMAP::VMapFactory::createOrGetVMapManager()->getObjectHitPos(PhasingHandler::GetTerrainMapId(GetPhaseShift(), GetMap(), pos.m_positionX, pos.m_positionY),
        pos.m_positionX, pos.m_positionY, pos.m_positionZ + 0.5f, destx, desty, destz + 0.5f, destx, desty, destz, -0.5f);

    // collision occured
    if (col)
    {
        // move back a bit
        destx -= CONTACT_DISTANCE * std::cos(angle);
        desty -= CONTACT_DISTANCE * std::sin(angle);
        dist = std::sqrt((pos.m_positionX - destx)*(pos.m_positionX - destx) + (pos.m_positionY - desty)*(pos.m_positionY - desty));
    }

    // check dynamic collision
    col = GetMap()->getObjectHitPos(GetPhaseShift(), pos.m_positionX, pos.m_positionY, pos.m_positionZ + 0.5f, destx, desty, destz + 0.5f, destx, desty, destz, -0.5f);

    // Collided with a gameobject
    if (col)
    {
        destx -= CONTACT_DISTANCE * std::cos(angle);
        desty -= CONTACT_DISTANCE * std::sin(angle);
        dist = std::sqrt((pos.m_positionX - destx)*(pos.m_positionX - destx) + (pos.m_positionY - desty)*(pos.m_positionY - desty));
    }

    float step = dist / 10.0f;

    for (uint8 j = 0; j < 10; ++j)
    {
        // do not allow too big z changes
        if (std::fabs(pos.m_positionZ - destz) > 6.0f)
        {
            destx -= step * std::cos(angle);
            desty -= step * std::sin(angle);
            destz = NormalizeZforCollision(this, destx, desty, pos.GetPositionZ());
        }
        // we have correct destz now
        else
        {
            pos.Relocate(destx, desty, destz);
            break;
        }
    }

    Trinity::NormalizeMapCoord(pos.m_positionX);
    Trinity::NormalizeMapCoord(pos.m_positionY);
    pos.m_positionZ = NormalizeZforCollision(this, destx, desty, pos.GetPositionZ());
    pos.SetOrientation(GetOrientation());
}

void WorldObject::SetPhaseMask(uint32 newPhaseMask, bool update)
{
    m_phaseMask = newPhaseMask;

    if (update && IsInWorld())
        UpdateObjectVisibility();
}

void WorldObject::PlayDistanceSound(uint32 sound_id, Player* target /*= nullptr*/)
{
    WorldPacket data(SMSG_PLAY_OBJECT_SOUND, 4 + 8);
    data << uint32(sound_id);
    data << uint64(GetGUID());
    if (target)
        target->SendDirectMessage(&data);
    else
        SendMessageToSet(&data, true);
}

void WorldObject::PlayDirectSound(uint32 sound_id, Player* target /*= nullptr*/)
{
    WorldPacket data(SMSG_PLAY_SOUND, 4 + 8);
    data << uint32(sound_id);
    data << uint64(GetGUID());
    if (target)
        target->SendDirectMessage(&data);
    else
        SendMessageToSet(&data, true);
}

void WorldObject::PlayDirectMusic(uint32 music_id, Player* target /*= nullptr*/)
{
    WorldPacket data(SMSG_PLAY_MUSIC, 4);
    data << uint32(music_id);
    if (target)
        target->SendDirectMessage(&data);
    else
        SendMessageToSet(&data, true);
}

void WorldObject::DestroyForNearbyPlayers()
{
    if (!IsInWorld())
        return;

    std::list<Player*> targets;
    Trinity::AnyPlayerInObjectRangeCheck check(this, GetVisibilityRange(), false);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(this, targets, check);
    Cell::VisitWorldObjects(this, searcher, GetVisibilityRange());
    for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
    {
        Player* player = (*iter);

        if (player == this)
            continue;

        if (!player->HaveAtClient(this))
            continue;

        if (isType(TYPEMASK_UNIT) && ToUnit()->GetCharmerGUID() == player->GetGUID()) /// @todo this is for puppet
            continue;

        DestroyForPlayer(player); // at remove from world (destroy) show kill animation
        player->m_clientGUIDs.erase(GetGUID());
    }
}

void WorldObject::UpdateObjectVisibility(bool /*forced*/)
{
    //updates object's visibility for nearby players
    Trinity::VisibleChangesNotifier notifier(*this);
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
}

struct WorldObjectChangeAccumulator
{
    UpdateDataMapType& i_updateDatas;
    WorldObject& i_object;
    GuidSet plr_list;
    WorldObjectChangeAccumulator(WorldObject &obj, UpdateDataMapType &d) : i_updateDatas(d), i_object(obj) { }
    void Visit(PlayerMapType &m)
    {
        Player* source = nullptr;
        for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            source = iter->GetSource();

            BuildPacket(source);

            if (!source->GetSharedVisionList().empty())
            {
                SharedVisionList::const_iterator it = source->GetSharedVisionList().begin();
                for (; it != source->GetSharedVisionList().end(); ++it)
                    BuildPacket(*it);
            }
        }
    }

    void Visit(CreatureMapType &m)
    {
        Creature* source = nullptr;
        for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            source = iter->GetSource();
            if (!source->GetSharedVisionList().empty())
            {
                SharedVisionList::const_iterator it = source->GetSharedVisionList().begin();
                for (; it != source->GetSharedVisionList().end(); ++it)
                    BuildPacket(*it);
            }
        }
    }

    void Visit(DynamicObjectMapType &m)
    {
        DynamicObject* source = nullptr;
        for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            source = iter->GetSource();
            ObjectGuid guid = source->GetCasterGUID();

            if (guid.IsPlayer())
            {
                //Caster may be nullptr if DynObj is in removelist
                if (Player* caster = ObjectAccessor::FindPlayer(guid))
                    if (caster->GetGuidValue(PLAYER_FARSIGHT) == source->GetGUID())
                        BuildPacket(caster);
            }
        }
    }

    void BuildPacket(Player* player)
    {
        // Only send update once to a player
        if (plr_list.find(player->GetGUID()) == plr_list.end() && player->HaveAtClient(&i_object))
        {
            i_object.BuildFieldsUpdate(player, i_updateDatas);
            plr_list.insert(player->GetGUID());
        }
    }

    template<class SKIP> void Visit(GridRefManager<SKIP> &) { }
};

void WorldObject::BuildUpdate(UpdateDataMapType& data_map)
{
    WorldObjectChangeAccumulator notifier(*this, data_map);
    //we must build packets for all visible players
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());

    ClearUpdateMask(false);
}

void WorldObject::AddToObjectUpdate()
{
    GetMap()->AddUpdateObject(this);
}

void WorldObject::RemoveFromObjectUpdate()
{
    GetMap()->RemoveUpdateObject(this);
}

ObjectGuid WorldObject::GetTransGUID() const
{
    if (GetTransport())
        return GetTransport()->GetGUID();
    return ObjectGuid::Empty;
}

MapTransport* WorldObject::GetMapTransport() const
{
    if (GetTransport())
        return GetTransport()->ToMapTransport();

    return nullptr;
}

float WorldObject::GetFloorZ() const
{
    if (!IsInWorld())
        return m_staticFloorZ;
    return std::max<float>(m_staticFloorZ, GetMap()->GetGameObjectFloor(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ()));
}

template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::list<GameObject*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::deque<GameObject*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::vector<GameObject*>&, uint32, float) const;

template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::list<Creature*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::deque<Creature*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::vector<Creature*>&, uint32, float) const;

template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::list<Player*>&, float) const;
template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::deque<Player*>&, float) const;
template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::vector<Player*>&, float) const;

void WorldObject::SetAIAnimKitId(uint16 animKitId)
{
    if (m_aiAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    m_aiAnimKitId = animKitId;

    WorldPacket data(SMSG_SET_AI_ANIM_KIT, 8 + 2);
    data << GetPackGUID();
    data << uint16(animKitId);
    SendMessageToSet(&data, true);
}

void WorldObject::SetMovementAnimKitId(uint16 animKitId)
{
    if (m_movementAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    m_movementAnimKitId = animKitId;

    WorldPacket data(SMSG_SET_MOVEMENT_ANIM_KIT, 8 + 2);
    data << GetPackGUID();
    data << uint16(animKitId);
    SendMessageToSet(&data, true);
}

void WorldObject::SetMeleeAnimKitId(uint16 animKitId)
{
    if (m_meleeAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    m_meleeAnimKitId = animKitId;

    WorldPacket data(SMSG_SET_MELEE_ANIM_KIT, 8 + 2);
    data << GetPackGUID();
    data << uint16(animKitId);
    SendMessageToSet(&data, true);
}
