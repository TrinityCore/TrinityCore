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
#include "AreaTriggerTemplate.h"
#include "BattlefieldMgr.h"
#include "CellImpl.h"
#include "CinematicMgr.h"
#include "Common.h"
#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "InstanceScenario.h"
#include "Item.h"
#include "Log.h"
#include "MiscPackets.h"
#include "MovementPackets.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "SharedDefines.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "Util.h"
#include "VMapFactory.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldSession.h"
#include <G3D/Vector3.h>

Object::Object()
{
    m_objectTypeId      = TYPEID_OBJECT;
    m_objectType        = TYPEMASK_OBJECT;
    m_updateFlag        = UPDATEFLAG_NONE;

    m_uint32Values      = nullptr;
    _dynamicValues      = nullptr;
    _dynamicChangesArrayMask = nullptr;
    m_valuesCount       = 0;
    _dynamicValuesCount = 0;
    _fieldNotifyFlags   = UF_FLAG_DYNAMIC;

    m_inWorld           = false;
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

    delete[] m_uint32Values;
    m_uint32Values = nullptr;

    delete[] _dynamicValues;
    _dynamicValues = nullptr;

    delete[] _dynamicChangesArrayMask;
    _dynamicChangesArrayMask = nullptr;
}

void Object::_InitValues()
{
    m_uint32Values = new uint32[m_valuesCount];
    memset(m_uint32Values, 0, m_valuesCount * sizeof(uint32));

    _changesMask.resize(m_valuesCount);
    _dynamicChangesMask.resize(_dynamicValuesCount);
    if (_dynamicValuesCount)
    {
        _dynamicValues = new std::vector<uint32>[_dynamicValuesCount];
        _dynamicChangesArrayMask = new std::vector<uint8>[_dynamicValuesCount];
    }

    m_objectUpdated = false;
}

void Object::_Create(ObjectGuid const& guid)
{
    if (!m_uint32Values) _InitValues();

    SetGuidValue(OBJECT_FIELD_GUID, guid);
    SetUInt16Value(OBJECT_FIELD_TYPE, 0, m_objectType);
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

    uint8  updateType = UPDATETYPE_CREATE_OBJECT;
    uint32 flags      = m_updateFlag;

    /** lower flag1 **/
    if (target == this)                                      // building packet for yourself
        flags |= UPDATEFLAG_SELF;

    switch (GetGUID().GetHigh())
    {
        case HighGuid::Player:
        case HighGuid::Pet:
        case HighGuid::Corpse:
        case HighGuid::DynamicObject:
        case HighGuid::AreaTrigger:
        case HighGuid::Conversation:
            updateType = UPDATETYPE_CREATE_OBJECT2;
            break;
        case HighGuid::Creature:
        case HighGuid::Vehicle:
        {
            if (TempSummon const* summon = ToUnit()->ToTempSummon())
                if (summon->GetSummonerGUID().IsPlayer())
                    updateType = UPDATETYPE_CREATE_OBJECT2;

            break;
        }
        case HighGuid::GameObject:
        {
            if (ToGameObject()->GetOwnerGUID().IsPlayer())
                updateType = UPDATETYPE_CREATE_OBJECT2;
            break;
        }
        default:
            break;
    }

    if (WorldObject const* worldObject = dynamic_cast<WorldObject const*>(this))
    {
        if (!(flags & UPDATEFLAG_LIVING))
            if (!worldObject->m_movementInfo.transport.guid.IsEmpty())
                flags |= UPDATEFLAG_TRANSPORT_POSITION;

        if (worldObject->GetAIAnimKitId() || worldObject->GetMovementAnimKitId() || worldObject->GetMeleeAnimKitId())
            flags |= UPDATEFLAG_ANIMKITS;
    }

    if (flags & UPDATEFLAG_STATIONARY_POSITION)
    {
        // UPDATETYPE_CREATE_OBJECT2 for some gameobject types...
        if (isType(TYPEMASK_GAMEOBJECT))
        {
            switch (ToGameObject()->GetGoType())
            {
                case GAMEOBJECT_TYPE_TRAP:
                case GAMEOBJECT_TYPE_DUEL_ARBITER:
                case GAMEOBJECT_TYPE_FLAGSTAND:
                case GAMEOBJECT_TYPE_FLAGDROP:
                    updateType = UPDATETYPE_CREATE_OBJECT2;
                    break;
                default:
                    break;
            }
        }
    }

    if (Unit const* unit = ToUnit())
        if (unit->GetVictim())
            flags |= UPDATEFLAG_HAS_TARGET;

    ByteBuffer buf(0x400);
    buf << uint8(updateType);
    buf << GetGUID();
    buf << uint8(m_objectTypeId);

    BuildMovementUpdate(&buf, flags);
    BuildValuesUpdate(updateType, &buf, target);
    BuildDynamicValuesUpdate(updateType, &buf, target);
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

void Object::BuildValuesUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    ByteBuffer buf(500);

    buf << uint8(UPDATETYPE_VALUES);
    buf << GetGUID();

    BuildValuesUpdate(UPDATETYPE_VALUES, &buf, target);
    BuildDynamicValuesUpdate(UPDATETYPE_VALUES, &buf, target);

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

ObjectGuid const& Object::GetGuidValue(uint16 index) const
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, false));
    return *((ObjectGuid*)&(m_uint32Values[index]));
}

void Object::BuildMovementUpdate(ByteBuffer* data, uint32 flags) const
{
    bool NoBirthAnim = false;
    bool EnablePortals = false;
    bool PlayHoverAnim = false;
    bool HasMovementUpdate = (flags & UPDATEFLAG_LIVING) != 0;
    bool HasMovementTransport = (flags & UPDATEFLAG_TRANSPORT_POSITION) != 0;
    bool Stationary = (flags & UPDATEFLAG_STATIONARY_POSITION) != 0;
    bool CombatVictim = (flags & UPDATEFLAG_HAS_TARGET) != 0;
    bool ServerTime = (flags & UPDATEFLAG_TRANSPORT) != 0;
    bool VehicleCreate = (flags & UPDATEFLAG_VEHICLE) != 0;
    bool AnimKitCreate = (flags & UPDATEFLAG_ANIMKITS) != 0;
    bool Rotation = (flags & UPDATEFLAG_ROTATION) != 0;
    bool HasAreaTrigger = (flags & UPDATEFLAG_AREATRIGGER) != 0;
    bool HasGameObject = (flags & UPDATEFLAG_GAMEOBJECT) != 0;
    bool ThisIsYou = (flags & UPDATEFLAG_SELF) != 0;
    bool SmoothPhasing = false;
    bool SceneObjCreate = false;
    bool PlayerCreateData = GetTypeId() == TYPEID_PLAYER && ToUnit()->GetPowerIndex(POWER_RUNES) != MAX_POWERS;
    std::vector<uint32> const* PauseTimes = nullptr;
    uint32 PauseTimesCount = 0;
    if (GameObject const* go = ToGameObject())
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
        {
            PauseTimes = go->GetGOValue()->Transport.StopFrames;
            PauseTimesCount = PauseTimes->size();
        }
    }

    data->WriteBit(NoBirthAnim);
    data->WriteBit(EnablePortals);
    data->WriteBit(PlayHoverAnim);
    data->WriteBit(HasMovementUpdate);
    data->WriteBit(HasMovementTransport);
    data->WriteBit(Stationary);
    data->WriteBit(CombatVictim);
    data->WriteBit(ServerTime);
    data->WriteBit(VehicleCreate);
    data->WriteBit(AnimKitCreate);
    data->WriteBit(Rotation);
    data->WriteBit(HasAreaTrigger);
    data->WriteBit(HasGameObject);
    data->WriteBit(SmoothPhasing);
    data->WriteBit(ThisIsYou);
    data->WriteBit(SceneObjCreate);
    data->WriteBit(PlayerCreateData);
    data->FlushBits();

    if (HasMovementUpdate)
    {
        Unit const* unit = ToUnit();
        bool HasFallDirection = unit->HasUnitMovementFlag(MOVEMENTFLAG_FALLING);
        bool HasFall = HasFallDirection || unit->m_movementInfo.jump.fallTime != 0;
        bool HasSpline = unit->IsSplineEnabled();

        *data << GetGUID();                                             // MoverGUID

        *data << uint32(unit->m_movementInfo.time);                     // MoveTime
        *data << float(unit->GetPositionX());
        *data << float(unit->GetPositionY());
        *data << float(unit->GetPositionZ());
        *data << float(unit->GetOrientation());

        *data << float(unit->m_movementInfo.pitch);                     // Pitch
        *data << float(unit->m_movementInfo.splineElevation);           // StepUpStartElevation

        *data << uint32(0);                                             // RemoveForcesIDs.size()
        *data << uint32(0);                                             // MoveIndex

        //for (std::size_t i = 0; i < RemoveForcesIDs.size(); ++i)
        //    *data << ObjectGuid(RemoveForcesIDs);

        data->WriteBits(unit->GetUnitMovementFlags(), 30);
        data->WriteBits(unit->GetExtraUnitMovementFlags(), 18);
        data->WriteBit(!unit->m_movementInfo.transport.guid.IsEmpty()); // HasTransport
        data->WriteBit(HasFall);                                        // HasFall
        data->WriteBit(HasSpline);                                      // HasSpline - marks that the unit uses spline movement
        data->WriteBit(0);                                              // HeightChangeFailed
        data->WriteBit(0);                                              // RemoteTimeValid

        if (!unit->m_movementInfo.transport.guid.IsEmpty())
            *data << unit->m_movementInfo.transport;

        if (HasFall)
        {
            *data << uint32(unit->m_movementInfo.jump.fallTime);              // Time
            *data << float(unit->m_movementInfo.jump.zspeed);                 // JumpVelocity

            if (data->WriteBit(HasFallDirection))
            {
                *data << float(unit->m_movementInfo.jump.sinAngle);           // Direction
                *data << float(unit->m_movementInfo.jump.cosAngle);
                *data << float(unit->m_movementInfo.jump.xyspeed);            // Speed
            }
        }

        *data << float(unit->GetSpeed(MOVE_WALK));
        *data << float(unit->GetSpeed(MOVE_RUN));
        *data << float(unit->GetSpeed(MOVE_RUN_BACK));
        *data << float(unit->GetSpeed(MOVE_SWIM));
        *data << float(unit->GetSpeed(MOVE_SWIM_BACK));
        *data << float(unit->GetSpeed(MOVE_FLIGHT));
        *data << float(unit->GetSpeed(MOVE_FLIGHT_BACK));
        *data << float(unit->GetSpeed(MOVE_TURN_RATE));
        *data << float(unit->GetSpeed(MOVE_PITCH_RATE));

        *data << uint32(0);                                                   // unit->m_movementInfo.forces.size()

        data->WriteBit(HasSpline);
        data->FlushBits();

        //for (std::size_t i = 0; i < unit->m_movementInfo.forces.size(); ++i)
        //{
        //    *data << ObjectGuid(ID);
        //    *data << Vector3(Origin);
        //    *data << Vector3(Direction);
        //    *data << uint32(TransportID);
        //    *data << float(Magnitude);
        //    data->WriteBits(Type, 2);
        //}

        if (HasSpline)
            WorldPackets::Movement::CommonMovement::WriteCreateObjectSplineDataBlock(*unit->movespline, *data);
    }

    *data << uint32(PauseTimesCount);

    if (Stationary)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << float(self->GetStationaryX());
        *data << float(self->GetStationaryY());
        *data << float(self->GetStationaryZ());
        *data << float(self->GetStationaryO());
    }

    if (CombatVictim)
        *data << ToUnit()->GetVictim()->GetGUID();                      // CombatVictim

    if (ServerTime)
    {
        GameObject const* go = ToGameObject();
        /** @TODO Use IsTransport() to also handle type 11 (TRANSPORT)
            Currently grid objects are not updated if there are no nearby players,
            this causes clients to receive different PathProgress
            resulting in players seeing the object in a different position
        */
        if (go && go->ToTransport())                                    // ServerTime
            *data << uint32(go->GetGOValue()->Transport.PathProgress);
        else
            *data << uint32(getMSTime());
    }

    if (VehicleCreate)
    {
        Unit const* unit = ToUnit();
        *data << uint32(unit->GetVehicleKit()->GetVehicleInfo()->ID); // RecID
        *data << float(unit->GetOrientation());                         // InitialRawFacing
    }

    if (AnimKitCreate)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << uint16(self->GetAIAnimKitId());                        // AiID
        *data << uint16(self->GetMovementAnimKitId());                  // MovementID
        *data << uint16(self->GetMeleeAnimKitId());                     // MeleeID
    }

    if (Rotation)
        *data << uint64(ToGameObject()->GetPackedWorldRotation());      // Rotation

    if (PauseTimesCount)
        data->append(PauseTimes->data(), PauseTimes->size());

    if (HasMovementTransport)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << self->m_movementInfo.transport;
    }

    if (HasAreaTrigger)
    {
        AreaTrigger const* areaTrigger = ToAreaTrigger();
        AreaTriggerMiscTemplate const* areaTriggerMiscTemplate = areaTrigger->GetMiscTemplate();
        AreaTriggerTemplate const* areaTriggerTemplate = areaTrigger->GetTemplate();

        *data << uint32(areaTrigger->GetTimeSinceCreated());

        *data << areaTrigger->GetRollPitchYaw().PositionXYZStream();

        bool hasAbsoluteOrientation = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_ABSOLUTE_ORIENTATION);
        bool hasDynamicShape        = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_DYNAMIC_SHAPE);
        bool hasAttached            = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED);
        bool hasFaceMovementDir     = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_FACE_MOVEMENT_DIR);
        bool hasFollowsTerrain      = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_FOLLOWS_TERRAIN);
        bool hasUnk1                = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_UNK1);
        bool hasTargetRollPitchYaw  = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_HAS_TARGET_ROLL_PITCH_YAW);
        bool hasScaleCurveID        = areaTriggerMiscTemplate->ScaleCurveId != 0;
        bool hasMorphCurveID        = areaTriggerMiscTemplate->MorphCurveId != 0;
        bool hasFacingCurveID       = areaTriggerMiscTemplate->FacingCurveId != 0;
        bool hasMoveCurveID         = areaTriggerMiscTemplate->MoveCurveId != 0;
        bool hasUnk2                = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_UNK2);
        bool hasUnk3                = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_UNK3);
        bool hasUnk4                = areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_UNK4);
        bool hasAreaTriggerSphere   = areaTriggerTemplate->IsSphere();
        bool hasAreaTriggerBox      = areaTriggerTemplate->IsBox();
        bool hasAreaTriggerPolygon  = areaTriggerTemplate->IsPolygon();
        bool hasAreaTriggerCylinder = areaTriggerTemplate->IsCylinder();
        bool hasAreaTriggerSpline   = areaTrigger->HasSplines();
        bool hasAreaTriggerUnkType  = false; // areaTriggerTemplate->HasFlag(AREATRIGGER_FLAG_UNK5);

        data->WriteBit(hasAbsoluteOrientation);
        data->WriteBit(hasDynamicShape);
        data->WriteBit(hasAttached);
        data->WriteBit(hasFaceMovementDir);
        data->WriteBit(hasFollowsTerrain);
        data->WriteBit(hasUnk1);
        data->WriteBit(hasTargetRollPitchYaw);
        data->WriteBit(hasScaleCurveID);
        data->WriteBit(hasMorphCurveID);
        data->WriteBit(hasFacingCurveID);
        data->WriteBit(hasMoveCurveID);
        data->WriteBit(hasUnk2);
        data->WriteBit(hasUnk3);
        data->WriteBit(hasUnk4);
        data->WriteBit(hasAreaTriggerSphere);
        data->WriteBit(hasAreaTriggerBox);
        data->WriteBit(hasAreaTriggerPolygon);
        data->WriteBit(hasAreaTriggerCylinder);
        data->WriteBit(hasAreaTriggerSpline);
        data->WriteBit(hasAreaTriggerUnkType);

        if (hasUnk3)
            data->WriteBit(0);

        data->FlushBits();

        if (hasAreaTriggerSpline)
        {
            *data << uint32(areaTrigger->GetTimeToTarget());
            *data << uint32(areaTrigger->GetElapsedTimeForMovement());

            WorldPackets::Movement::CommonMovement::WriteCreateObjectAreaTriggerSpline(areaTrigger->GetSpline(), *data);
        }

        if (hasTargetRollPitchYaw)
            *data << areaTrigger->GetTargetRollPitchYaw().PositionXYZStream();

        if (hasScaleCurveID)
            *data << uint32(areaTriggerMiscTemplate->ScaleCurveId);

        if (hasMorphCurveID)
            *data << uint32(areaTriggerMiscTemplate->MorphCurveId);

        if (hasFacingCurveID)
            *data << uint32(areaTriggerMiscTemplate->FacingCurveId);

        if (hasMoveCurveID)
            *data << uint32(areaTriggerMiscTemplate->MoveCurveId);

        if (hasUnk2)
            *data << int32(0);

        if (hasUnk4)
            *data << uint32(0);

        if (hasAreaTriggerSphere)
        {
            *data << float(areaTriggerTemplate->SphereDatas.Radius);
            *data << float(areaTriggerTemplate->SphereDatas.RadiusTarget);
        }

        if (hasAreaTriggerBox)
        {
            *data << float(areaTriggerTemplate->BoxDatas.Extents[0]);
            *data << float(areaTriggerTemplate->BoxDatas.Extents[1]);
            *data << float(areaTriggerTemplate->BoxDatas.Extents[2]);
            *data << float(areaTriggerTemplate->BoxDatas.ExtentsTarget[0]);
            *data << float(areaTriggerTemplate->BoxDatas.ExtentsTarget[1]);
            *data << float(areaTriggerTemplate->BoxDatas.ExtentsTarget[2]);
        }

        if (hasAreaTriggerPolygon)
        {
            *data << int32(areaTriggerTemplate->PolygonVertices.size());
            *data << int32(areaTriggerTemplate->PolygonVerticesTarget.size());
            *data << float(areaTriggerTemplate->PolygonDatas.Height);
            *data << float(areaTriggerTemplate->PolygonDatas.HeightTarget);

            for (TaggedPosition<Position::XY> const& vertice : areaTriggerTemplate->PolygonVertices)
                *data << vertice;

            for (TaggedPosition<Position::XY> const& vertice : areaTriggerTemplate->PolygonVerticesTarget)
                *data << vertice;
        }

        if (hasAreaTriggerCylinder)
        {
            *data << float(areaTriggerTemplate->CylinderDatas.Radius);
            *data << float(areaTriggerTemplate->CylinderDatas.RadiusTarget);
            *data << float(areaTriggerTemplate->CylinderDatas.Height);
            *data << float(areaTriggerTemplate->CylinderDatas.HeightTarget);
            *data << float(areaTriggerTemplate->CylinderDatas.LocationZOffset);
            *data << float(areaTriggerTemplate->CylinderDatas.LocationZOffsetTarget);
        }

        if (hasAreaTriggerUnkType)
        {
            /*packet.ResetBitReader();
            var unk1 = packet.ReadBit("AreaTriggerUnk1");
            var hasCenter = packet.ReadBit("HasCenter", index);
            packet.ReadBit("Unk bit 703 1", index);
            packet.ReadBit("Unk bit 703 2", index);

            packet.ReadUInt32();
            packet.ReadInt32();
            packet.ReadUInt32();
            packet.ReadSingle("Radius", index);
            packet.ReadSingle("BlendFromRadius", index);
            packet.ReadSingle("InitialAngel", index);
            packet.ReadSingle("ZOffset", index);

            if (unk1)
                packet.ReadPackedGuid128("AreaTriggerUnkGUID", index);

            if (hasCenter)
                packet.ReadVector3("Center", index);*/
        }
    }

    if (HasGameObject)
    {
        bool bit8 = false;
        uint32 Int1 = 0;

        GameObject const* gameObject = ToGameObject();

        *data << uint32(gameObject->GetWorldEffectID());

        data->WriteBit(bit8);
        data->FlushBits();
        if (bit8)
            *data << uint32(Int1);
    }

    //if (SmoothPhasing)
    //{
    //    data->WriteBit(ReplaceActive);
    //    data->WriteBit(HasReplaceObject);
    //    data->FlushBits();
    //    if (HasReplaceObject)
    //        *data << ObjectGuid(ReplaceObject);
    //}

    //if (SceneObjCreate)
    //{
    //    data->WriteBit(HasLocalScriptData);
    //    data->WriteBit(HasPetBattleFullUpdate);
    //    data->FlushBits();

    //    if (HasLocalScriptData)
    //    {
    //        data->WriteBits(Data.length(), 7);
    //        data->FlushBits();
    //        data->WriteString(Data);
    //    }

    //    if (HasPetBattleFullUpdate)
    //    {
    //        for (std::size_t i = 0; i < 2; ++i)
    //        {
    //            *data << ObjectGuid(Players[i].CharacterID);
    //            *data << int32(Players[i].TrapAbilityID);
    //            *data << int32(Players[i].TrapStatus);
    //            *data << uint16(Players[i].RoundTimeSecs);
    //            *data << int8(Players[i].FrontPet);
    //            *data << uint8(Players[i].InputFlags);

    //            data->WriteBits(Players[i].Pets.size(), 2);
    //            data->FlushBits();
    //            for (std::size_t j = 0; j < Players[i].Pets.size(); ++j)
    //            {
    //                *data << ObjectGuid(Players[i].Pets[j].BattlePetGUID);
    //                *data << int32(Players[i].Pets[j].SpeciesID);
    //                *data << int32(Players[i].Pets[j].DisplayID);
    //                *data << int32(Players[i].Pets[j].CollarID);
    //                *data << int16(Players[i].Pets[j].Level);
    //                *data << int16(Players[i].Pets[j].Xp);
    //                *data << int32(Players[i].Pets[j].CurHealth);
    //                *data << int32(Players[i].Pets[j].MaxHealth);
    //                *data << int32(Players[i].Pets[j].Power);
    //                *data << int32(Players[i].Pets[j].Speed);
    //                *data << int32(Players[i].Pets[j].NpcTeamMemberID);
    //                *data << uint16(Players[i].Pets[j].BreedQuality);
    //                *data << uint16(Players[i].Pets[j].StatusFlags);
    //                *data << int8(Players[i].Pets[j].Slot);

    //                *data << uint32(Players[i].Pets[j].Abilities.size());
    //                *data << uint32(Players[i].Pets[j].Auras.size());
    //                *data << uint32(Players[i].Pets[j].States.size());
    //                for (std::size_t k = 0; k < Players[i].Pets[j].Abilities.size(); ++k)
    //                {
    //                    *data << int32(Players[i].Pets[j].Abilities[k].AbilityID);
    //                    *data << int16(Players[i].Pets[j].Abilities[k].CooldownRemaining);
    //                    *data << int16(Players[i].Pets[j].Abilities[k].LockdownRemaining);
    //                    *data << int8(Players[i].Pets[j].Abilities[k].AbilityIndex);
    //                    *data << uint8(Players[i].Pets[j].Abilities[k].Pboid);
    //                }

    //                for (std::size_t k = 0; k < Players[i].Pets[j].Auras.size(); ++k)
    //                {
    //                    *data << int32(Players[i].Pets[j].Auras[k].AbilityID);
    //                    *data << uint32(Players[i].Pets[j].Auras[k].InstanceID);
    //                    *data << int32(Players[i].Pets[j].Auras[k].RoundsRemaining);
    //                    *data << int32(Players[i].Pets[j].Auras[k].CurrentRound);
    //                    *data << uint8(Players[i].Pets[j].Auras[k].CasterPBOID);
    //                }

    //                for (std::size_t k = 0; k < Players[i].Pets[j].States.size(); ++k)
    //                {
    //                    *data << uint32(Players[i].Pets[j].States[k].StateID);
    //                    *data << int32(Players[i].Pets[j].States[k].StateValue);
    //                }

    //                data->WriteBits(Players[i].Pets[j].CustomName.length(), 7);
    //                data->FlushBits();
    //                data->WriteString(Players[i].Pets[j].CustomName);
    //            }
    //        }

    //        for (std::size_t i = 0; i < 3; ++i)
    //        {
    //            *data << uint32(Enviros[j].Auras.size());
    //            *data << uint32(Enviros[j].States.size());
    //            for (std::size_t j = 0; j < Enviros[j].Auras.size(); ++j)
    //            {
    //                *data << int32(Enviros[j].Auras[j].AbilityID);
    //                *data << uint32(Enviros[j].Auras[j].InstanceID);
    //                *data << int32(Enviros[j].Auras[j].RoundsRemaining);
    //                *data << int32(Enviros[j].Auras[j].CurrentRound);
    //                *data << uint8(Enviros[j].Auras[j].CasterPBOID);
    //            }

    //            for (std::size_t j = 0; j < Enviros[j].States.size(); ++j)
    //            {
    //                *data << uint32(Enviros[i].States[j].StateID);
    //                *data << int32(Enviros[i].States[j].StateValue);
    //            }
    //        }

    //        *data << uint16(WaitingForFrontPetsMaxSecs);
    //        *data << uint16(PvpMaxRoundTime);
    //        *data << int32(CurRound);
    //        *data << uint32(NpcCreatureID);
    //        *data << uint32(NpcDisplayID);
    //        *data << int8(CurPetBattleState);
    //        *data << uint8(ForfeitPenalty);
    //        *data << ObjectGuid(InitialWildPetGUID);
    //        data->WriteBit(IsPVP);
    //        data->WriteBit(CanAwardXP);
    //        data->FlushBits();
    //    }
    //}

    if (PlayerCreateData)
    {
        bool HasSceneInstanceIDs = false;
        bool HasRuneState = ToUnit()->GetPowerIndex(POWER_RUNES) != MAX_POWERS;

        data->WriteBit(HasSceneInstanceIDs);
        data->WriteBit(HasRuneState);
        data->FlushBits();
        //if (HasSceneInstanceIDs)
        //{
        //    *data << uint32(SceneInstanceIDs.size());
        //    for (std::size_t i = 0; i < SceneInstanceIDs.size(); ++i)
        //        *data << uint32(SceneInstanceIDs[i]);
        //}
        if (HasRuneState)
        {
            Player const* player = ToPlayer();
            float baseCd = float(player->GetRuneBaseCooldown());
            uint32 maxRunes = uint32(player->GetMaxPower(POWER_RUNES));

            *data << uint8((1 << maxRunes) - 1);
            *data << uint8(player->GetRunesState());
            *data << uint32(maxRunes);
            for (uint32 i = 0; i < maxRunes; ++i)
                *data << uint8((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255);
        }
    }
}

void Object::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    std::size_t blockCount = UpdateMask::GetBlockCount(m_valuesCount);

    uint32* flags = NULL;
    uint32 visibleFlag = GetUpdateFieldData(target, flags);
    ASSERT(flags);

    *data << uint8(blockCount);
    std::size_t maskPos = data->wpos();
    data->resize(data->size() + blockCount * sizeof(UpdateMask::BlockType));

    for (uint16 index = 0; index < m_valuesCount; ++index)
    {
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _changesMask[index] : m_uint32Values[index]) && (flags[index] & visibleFlag)))
        {
            UpdateMask::SetUpdateBit(data->contents() + maskPos, index);
            *data << m_uint32Values[index];
        }
    }
}

void Object::BuildDynamicValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    std::size_t blockCount = UpdateMask::GetBlockCount(_dynamicValuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetDynamicUpdateFieldData(target, flags);

    *data << uint8(blockCount);
    std::size_t maskPos = data->wpos();
    data->resize(data->size() + blockCount * sizeof(UpdateMask::BlockType));

    for (uint16 index = 0; index < _dynamicValuesCount; ++index)
    {
        std::vector<uint32> const& values = _dynamicValues[index];
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _dynamicChangesMask[index] != UpdateMask::UNCHANGED : !values.empty()) && (flags[index] & visibleFlag)))
        {
            UpdateMask::SetUpdateBit(data->contents() + maskPos, index);

            std::size_t arrayBlockCount = UpdateMask::GetBlockCount(values.size());
            *data << uint16(UpdateMask::EncodeDynamicFieldChangeType(arrayBlockCount, _dynamicChangesMask[index], updateType));
            if (_dynamicChangesMask[index] == UpdateMask::VALUE_AND_SIZE_CHANGED && updateType == UPDATETYPE_VALUES)
                *data << uint32(values.size());

            std::size_t arrayMaskPos = data->wpos();
            data->resize(data->size() + arrayBlockCount * sizeof(UpdateMask::BlockType));
            for (std::size_t v = 0; v < values.size(); ++v)
            {
                if (updateType != UPDATETYPE_VALUES || _dynamicChangesArrayMask[index][v])
                {
                    UpdateMask::SetUpdateBit(data->contents() + arrayMaskPos, v);
                    *data << uint32(values[v]);
                }
            }
        }
    }
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
    memset(_changesMask.data(), 0, _changesMask.size());
    _dynamicChangesMask.assign(_dynamicChangesMask.size(), UpdateMask::UNCHANGED);
    for (uint32 i = 0; i < _dynamicValuesCount; ++i)
        memset(_dynamicChangesArrayMask[i].data(), 0, _dynamicChangesArrayMask[i].size());

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

            if (HasFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_SPECIALINFO))
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
        case TYPEID_SCENEOBJECT:
            flags = SceneObjectUpdateFieldFlags;
            break;
        case TYPEID_CONVERSATION:
            flags = ConversationUpdateFieldFlags;
            break;
        case TYPEID_OBJECT:
            ABORT();
            break;
    }

    return visibleFlag;
}

uint32 Object::GetDynamicUpdateFieldData(Player const* target, uint32*& flags) const
{
    uint32 visibleFlag = UF_FLAG_PUBLIC;

    if (target == this)
        visibleFlag |= UF_FLAG_PRIVATE;

    switch (GetTypeId())
    {
        case TYPEID_ITEM:
        case TYPEID_CONTAINER:
            flags = ItemDynamicUpdateFieldFlags;
            if (((Item const*)this)->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER | UF_FLAG_ITEM_OWNER;
            break;
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
        {
            Player* plr = ToUnit()->GetCharmerOrOwnerPlayerOrPlayerItself();
            flags = UnitDynamicUpdateFieldFlags;
            if (ToUnit()->GetOwnerGUID() == target->GetGUID())
                visibleFlag |= UF_FLAG_OWNER;

            if (HasFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_SPECIALINFO))
                if (ToUnit()->HasAuraTypeWithCaster(SPELL_AURA_EMPATHY, target->GetGUID()))
                    visibleFlag |= UF_FLAG_SPECIAL_INFO;

            if (plr && plr->IsInSameRaidWith(target))
                visibleFlag |= UF_FLAG_PARTY_MEMBER;
            break;
        }
        case TYPEID_GAMEOBJECT:
            flags = GameObjectDynamicUpdateFieldFlags;
            break;
        case TYPEID_CONVERSATION:
            flags = ConversationDynamicUpdateFieldFlags;

            if (ToConversation()->GetCreatorGuid() == target->GetGUID())
                visibleFlag |= UF_FLAG_0x100;
            break;
        default:
            flags = nullptr;
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
        _changesMask[startOffset + index] = 1;
    }
}

void Object::SetInt32Value(uint16 index, int32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_int32Values[index] != value)
    {
        m_int32Values[index] = value;
        _changesMask[index] = 1;

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetUInt32Value(uint16 index, uint32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_uint32Values[index] != value)
    {
        m_uint32Values[index] = value;
        _changesMask[index] = 1;

        AddToObjectUpdateIfNeeded();
    }
}

void Object::UpdateUInt32Value(uint16 index, uint32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    m_uint32Values[index] = value;
    _changesMask[index] = 1;
}

void Object::SetUInt64Value(uint16 index, uint64 value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (*((uint64*)&(m_uint32Values[index])) != value)
    {
        m_uint32Values[index] = PAIR64_LOPART(value);
        m_uint32Values[index + 1] = PAIR64_HIPART(value);
        _changesMask[index] = 1;
        _changesMask[index + 1] = 1;

        AddToObjectUpdateIfNeeded();
    }
}

bool Object::AddGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 3 < m_valuesCount || PrintIndexError(index, true));
    if (!value.IsEmpty() && ((ObjectGuid*)&(m_uint32Values[index]))->IsEmpty())
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask[index] = 1;
        _changesMask[index + 1] = 1;
        _changesMask[index + 2] = 1;
        _changesMask[index + 3] = 1;

        AddToObjectUpdateIfNeeded();
        return true;
    }

    return false;
}

bool Object::RemoveGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 3 < m_valuesCount || PrintIndexError(index, true));
    if (!value.IsEmpty() && *((ObjectGuid*)&(m_uint32Values[index])) == value)
    {
        ((ObjectGuid*)&(m_uint32Values[index]))->Clear();
        _changesMask[index] = 1;
        _changesMask[index + 1] = 1;
        _changesMask[index + 2] = 1;
        _changesMask[index + 3] = 1;

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
        _changesMask[index] = 1;

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
        _changesMask[index] = 1;

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
        _changesMask[index] = 1;

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 3 < m_valuesCount || PrintIndexError(index, true));
    if (*((ObjectGuid*)&(m_uint32Values[index])) != value)
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask[index] = 1;
        _changesMask[index + 1] = 1;
        _changesMask[index + 2] = 1;
        _changesMask[index + 3] = 1;

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

void Object::ApplyModUInt16Value(uint16 index, uint8 offset, int16 val, bool apply)
{
    int16 cur = GetUInt16Value(index, offset);
    cur += (apply ? val : -val);
    if (cur < 0)
        cur = 0;
    SetUInt16Value(index, offset, cur);
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
        _changesMask[index] = 1;

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
        _changesMask[index] = 1;

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
        _changesMask[index] = 1;

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
        _changesMask[index] = 1;

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

std::vector<uint32> const& Object::GetDynamicValues(uint16 index) const
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));
    return _dynamicValues[index];
}

uint32 Object::GetDynamicValue(uint16 index, uint16 offset) const
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));
    if (offset >= _dynamicValues[index].size())
        return 0;
    return _dynamicValues[index][offset];
}

void Object::AddDynamicValue(uint16 index, uint32 value)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));
    SetDynamicValue(index, _dynamicValues[index].size(), value);
}

void Object::RemoveDynamicValue(uint16 index, uint32 value)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    // TODO: Research if this is blizzlike to just set value to 0
    std::vector<uint32>& values = _dynamicValues[index];
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (values[i] == value)
        {
            values[i] = 0;
            _dynamicChangesMask[index] = UpdateMask::VALUE_CHANGED;
            _dynamicChangesArrayMask[index][i] = 1;

            AddToObjectUpdateIfNeeded();
        }
    }
}

void Object::ClearDynamicValue(uint16 index)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    if (!_dynamicValues[index].empty())
    {
        _dynamicValues[index].clear();
        _dynamicChangesMask[index] = UpdateMask::VALUE_AND_SIZE_CHANGED;
        _dynamicChangesArrayMask[index].clear();

        AddToObjectUpdateIfNeeded();
    }
}

void Object::SetDynamicValue(uint16 index, uint16 offset, uint32 value)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    UpdateMask::DynamicFieldChangeType changeType = UpdateMask::VALUE_CHANGED;
    std::vector<uint32>& values = _dynamicValues[index];
    if (values.size() <= offset)
    {
        values.resize(offset + 1);
        changeType = UpdateMask::VALUE_AND_SIZE_CHANGED;
    }

    if (_dynamicChangesArrayMask[index].size() <= offset)
        _dynamicChangesArrayMask[index].resize((offset / 32 + 1) * 32);

    if (values[offset] != value || changeType == UpdateMask::VALUE_AND_SIZE_CHANGED)
    {
        values[offset] = value;
        _dynamicChangesMask[index] = changeType;
        _dynamicChangesArrayMask[index][offset] = 1;

        AddToObjectUpdateIfNeeded();
    }
}

bool Object::PrintIndexError(uint32 index, bool set) const
{
    TC_LOG_ERROR("misc", "Attempt %s non-existed value field: %u (count: %u) for object typeid: %u type mask: %u", (set ? "set value to" : "get value from"), index, m_valuesCount, GetTypeId(), m_objectType);

    // ASSERT must fail after function call
    return false;
}

void MovementInfo::OutDebug()
{
    TC_LOG_DEBUG("misc", "MOVEMENT INFO");
    TC_LOG_DEBUG("misc", "%s", guid.ToString().c_str());
    TC_LOG_DEBUG("misc", "flags %s (%u)", Movement::MovementFlags_ToString(flags).c_str(), flags);
    TC_LOG_DEBUG("misc", "flags2 %s (%u)", Movement::MovementFlagsExtra_ToString(flags2).c_str(), flags2);
    TC_LOG_DEBUG("misc", "time %u current time %u", time, getMSTime());
    TC_LOG_DEBUG("misc", "position: `%s`", pos.ToString().c_str());
    if (!transport.guid.IsEmpty())
    {
        TC_LOG_DEBUG("misc", "TRANSPORT:");
        TC_LOG_DEBUG("misc", "%s", transport.guid.ToString().c_str());
        TC_LOG_DEBUG("misc", "position: `%s`", transport.pos.ToString().c_str());
        TC_LOG_DEBUG("misc", "seat: %i", transport.seat);
        TC_LOG_DEBUG("misc", "time: %u", transport.time);
        if (transport.prevTime)
            TC_LOG_DEBUG("misc", "prevTime: %u", transport.prevTime);
        if (transport.vehicleId)
            TC_LOG_DEBUG("misc", "vehicleId: %u", transport.vehicleId);
    }

    if ((flags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        TC_LOG_DEBUG("misc", "pitch: %f", pitch);

    if (flags & MOVEMENTFLAG_FALLING || jump.fallTime)
    {
        TC_LOG_DEBUG("misc", "fallTime: %u j_zspeed: %f", jump.fallTime, jump.zspeed);
        if (flags & MOVEMENTFLAG_FALLING)
            TC_LOG_DEBUG("misc", "j_sinAngle: %f j_cosAngle: %f j_xyspeed: %f", jump.sinAngle, jump.cosAngle, jump.xyspeed);
    }

    if (flags & MOVEMENTFLAG_SPLINE_ELEVATION)
        TC_LOG_DEBUG("misc", "splineElevation: %f", splineElevation);
}

WorldObject::WorldObject(bool isWorldObject) : WorldLocation(), LastUsedScriptID(0),
m_name(""), m_isActive(false), m_isWorldObject(isWorldObject), m_zoneScript(NULL),
m_transport(NULL), m_currMap(NULL), m_InstanceId(0),
_dbPhase(0), m_notifyflags(0), m_executed_notifies(0)
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

void WorldObject::CleanupsBeforeDelete(bool /*finalCleanup*/)
{
    if (IsInWorld())
        RemoveFromWorld();

    if (Transport* transport = GetTransport())
        transport->RemovePassenger(this);
}

void WorldObject::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    DestroyForNearbyPlayers();

    Object::RemoveFromWorld();
}

uint32 WorldObject::GetZoneId() const
{
    return GetMap()->GetZoneId(GetPhaseShift(), m_positionX, m_positionY, m_positionZ);
}

uint32 WorldObject::GetAreaId() const
{
    return GetMap()->GetAreaId(GetPhaseShift(), m_positionX, m_positionY, m_positionZ);
}

void WorldObject::GetZoneAndAreaId(uint32& zoneid, uint32& areaid) const
{
    GetMap()->GetZoneAndAreaId(GetPhaseShift(), zoneid, areaid, m_positionX, m_positionY, m_positionZ);
}

InstanceScript* WorldObject::GetInstanceScript()
{
    Map* map = GetMap();
    return map->IsDungeon() ? ((InstanceMap*)map)->GetInstanceScript() : NULL;
}

float WorldObject::GetDistanceZ(const WorldObject* obj) const
{
    float dz = std::fabs(GetPositionZ() - obj->GetPositionZ());
    float sizefactor = GetObjectSize() + obj->GetObjectSize();
    float dist = dz - sizefactor;
    return (dist > 0 ? dist : 0);
}

bool WorldObject::_IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D) const
{
    float sizefactor = GetObjectSize() + obj->GetObjectSize();
    float maxdist = dist2compare + sizefactor;

    if (GetTransport() && obj->GetTransport() && obj->GetTransport()->GetGUID() == GetTransport()->GetGUID())
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

bool WorldObject::IsWithinLOSInMap(const WorldObject* obj) const
{
    if (!IsInMap(obj))
        return false;

    float x, y, z;
    if (obj->GetTypeId() == TYPEID_PLAYER)
        obj->GetPosition(x, y, z);
    else
        obj->GetHitSpherePointFor(GetPosition(), x, y, z);

    return IsWithinLOS(x, y, z);
}

float WorldObject::GetDistance(const WorldObject* obj) const
{
    float d = GetExactDist(obj) - GetObjectSize() - obj->GetObjectSize();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance(const Position &pos) const
{
    float d = GetExactDist(&pos) - GetObjectSize();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance(float x, float y, float z) const
{
    float d = GetExactDist(x, y, z) - GetObjectSize();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance2d(const WorldObject* obj) const
{
    float d = GetExactDist2d(obj) - GetObjectSize() - obj->GetObjectSize();
    return d > 0.0f ? d : 0.0f;
}

float WorldObject::GetDistance2d(float x, float y) const
{
    float d = GetExactDist2d(x, y) - GetObjectSize();
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
    return IsInDist(x, y, z, dist + GetObjectSize());
}

bool WorldObject::IsWithinDist3d(const Position* pos, float dist) const
{
    return IsInDist(pos, dist + GetObjectSize());
}

bool WorldObject::IsWithinDist2d(float x, float y, float dist) const
{
    return IsInDist2d(x, y, dist + GetObjectSize());
}

bool WorldObject::IsWithinDist2d(const Position* pos, float dist) const
{
    return IsInDist2d(pos, dist + GetObjectSize());
}

bool WorldObject::IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D /*= true*/) const
{
    return obj && _IsWithinDist(obj, dist2compare, is3D);
}

bool WorldObject::IsWithinDistInMap(WorldObject const* obj, float dist2compare, bool is3D /*= true*/) const
{
    return obj && IsInMap(obj) && IsInPhase(obj) && _IsWithinDist(obj, dist2compare, is3D);
}

bool WorldObject::IsWithinLOS(float ox, float oy, float oz) const
{
    /*float x, y, z;
    GetPosition(x, y, z);
    VMAP::IVMapManager* vMapManager = VMAP::VMapFactory::createOrGetVMapManager();
    return vMapManager->isInLineOfSight(GetMapId(), x, y, z+2.0f, ox, oy, oz+2.0f);*/
    if (IsInWorld())
    {
        float x, y, z;
        if (GetTypeId() == TYPEID_PLAYER)
            GetPosition(x, y, z);
        else
            GetHitSpherePointFor({ ox, oy, oz }, x, y, z);

        return GetMap()->isInLineOfSight(GetPhaseShift(), x, y, z + 2.0f, ox, oy, oz + 2.0f);
    }

    return true;
}

Position WorldObject::GetHitSpherePointFor(Position const& dest) const
{
    G3D::Vector3 vThis(GetPositionX(), GetPositionY(), GetPositionZ());
    G3D::Vector3 vObj(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
    G3D::Vector3 contactPoint = vThis + (vObj - vThis).directionOrZero() * GetObjectSize();

    return Position(contactPoint.x, contactPoint.y, contactPoint.z, GetAngle(contactPoint.x, contactPoint.y));
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

    float sizefactor = GetObjectSize() + obj->GetObjectSize();

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

    float sizefactor = GetObjectSize();

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

    float sizefactor = GetObjectSize();

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
        size = GetObjectSize() / 2;

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
    if (ToPlayer())
    {
        if (ToPlayer()->GetCinematicMgr()->IsOnCinematic())
            return DEFAULT_VISIBILITY_INSTANCE;
        return GetMap()->GetVisibilityRange();
    }
    else if (ToCreature())
        return ToCreature()->m_SightDistance;
    else if (ToDynObject())
    {
        if (isActiveObject())
            return GetMap()->GetVisibilityRange();
        else
            return 0.0f;
    }
    else
        return 0.0f;
}

float WorldObject::GetVisibilityRange() const
{
    if (isActiveObject() && !ToPlayer())
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
            if (target && target->isActiveObject() && !target->ToPlayer())
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
    {
        return GetMap()->GetVisibilityRange();
    }

    return 0.0f;
}

bool WorldObject::CanSeeOrDetect(WorldObject const* obj, bool ignoreStealth, bool distanceCheck, bool checkAlert) const
{
    if (this == obj)
        return true;

    if (obj->IsNeverVisibleFor(this) || CanNeverSee(obj))
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
        }

        WorldObject const* viewpoint = this;
        if (Player const* player = this->ToPlayer())
            viewpoint = player->GetViewpoint();

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

    GameObject const* go = ToGameObject();
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
        detectionValue += int32(GetLevelForTarget(obj) - 1) * 5;

        // Apply modifiers
        detectionValue += m_stealthDetect.GetValue(StealthType(i));
        if (go)
            if (Unit* owner = go->GetOwner())
                detectionValue -= int32(owner->GetLevelForTarget(this) - 1) * 5;

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
    _changesMask[i] = 1;
    AddToObjectUpdateIfNeeded();
}

void WorldObject::SendMessageToSet(WorldPacket const* data, bool self) const
{
    if (IsInWorld())
        SendMessageToSetInRange(data, GetVisibilityRange(), self);
}

void WorldObject::SendMessageToSetInRange(WorldPacket const* data, float dist, bool /*self*/) const
{
    Trinity::MessageDistDeliverer notifier(this, data, dist);
    Cell::VisitWorldObjects(this, notifier, dist);
}

void WorldObject::SendMessageToSet(WorldPacket const* data, Player const* skipped_rcvr) const
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
    m_currMap = NULL;
    //maybe not for corpse
    //m_mapId = 0;
    //m_InstanceId = 0;
}

void WorldObject::AddObjectToRemoveList()
{
    ASSERT(m_uint32Values);

    Map* map = FindMap();
    if (!map)
    {
        TC_LOG_ERROR("misc", "Object (Entry: %u %s) at attempt add to move list not have valid map (Id: %u).", GetEntry(), GetGUID().ToString().c_str(), GetMapId());
        return;
    }

    map->AddObjectToRemoveList(this);
}

TempSummon* Map::SummonCreature(uint32 entry, Position const& pos, SummonPropertiesEntry const* properties /*= NULL*/, uint32 duration /*= 0*/, Unit* summoner /*= NULL*/, uint32 spellId /*= 0*/, uint32 vehId /*= 0*/)
{
    uint32 mask = UNIT_MASK_SUMMON;
    if (properties)
    {
        switch (properties->Control)
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
                switch (properties->Title)
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

    if (!summon->Create(GenerateLowGuid<HighGuid::Creature>(), this, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), nullptr, vehId))
    {
        delete summon;
        return nullptr;
    }

    // Set the summon to the summoner's phase
    if (summoner)
        PhasingHandler::InheritPhaseShift(summon, summoner);

    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);

    summon->SetHomePosition(pos);

    summon->InitStats(duration);
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

void Map::SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list /*= NULL*/)
{
    std::vector<TempSummonData> const* data = sObjectMgr->GetSummonGroup(GetId(), SUMMONER_TYPE_MAP, group);
    if (!data)
        return;

    for (std::vector<TempSummonData>::const_iterator itr = data->begin(); itr != data->end(); ++itr)
        if (TempSummon* summon = SummonCreature(itr->entry, itr->pos, NULL, itr->time))
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

Scenario* WorldObject::GetScenario() const
{
    if (IsInWorld())
        if (InstanceMap* instanceMap = GetMap()->ToInstanceMap())
            return instanceMap->GetInstanceScenario();

    return nullptr;
}

TempSummon* WorldObject::SummonCreature(uint32 entry, Position const& pos, TempSummonType spwtype /*= TEMPSUMMON_MANUAL_DESPAWN*/, uint32 duration /*= 0*/, uint32 /*vehId = 0*/) const
{
    if (Map* map = FindMap())
    {
        if (TempSummon* summon = map->SummonCreature(entry, pos, NULL, duration, isType(TYPEMASK_UNIT) ? (Unit*)this : NULL))
        {
            summon->SetTempSummonType(spwtype);
            return summon;
        }
    }

    return nullptr;
}

TempSummon* WorldObject::SummonCreature(uint32 id, float x, float y, float z, float ang /*= 0*/, TempSummonType spwtype /*= TEMPSUMMON_MANUAL_DESPAWN*/, uint32 despwtime /*= 0*/) const
{
    if (!x && !y && !z)
    {
        GetClosePoint(x, y, z, GetObjectSize());
        ang = GetOrientation();
    }

    Position pos;
    pos.Relocate(x, y, z, ang);
    return SummonCreature(id, pos, spwtype, despwtime, 0);
}

GameObject* WorldObject::SummonGameObject(uint32 entry, Position const& pos, QuaternionData const& rot, uint32 respawnTime)
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
    GameObject* go = GameObject::CreateGameObject(entry, map, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return nullptr;

    PhasingHandler::InheritPhaseShift(go, this);

    go->SetRespawnTime(respawnTime);
    if (GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT) //not sure how to handle this
        ToUnit()->AddGameObject(go);
    else
        go->SetSpawnedByDefault(false);

    map->AddToMap(go);
    return go;
}

GameObject* WorldObject::SummonGameObject(uint32 entry, float x, float y, float z, float ang, QuaternionData const& rot, uint32 respawnTime)
{
    if (!x && !y && !z)
    {
        GetClosePoint(x, y, z, GetObjectSize());
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
        return NULL;

    //summon->SetName(GetName());
    if (GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT)
    {
        summon->setFaction(((Unit*)this)->getFaction());
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
void WorldObject::SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list /*= NULL*/)
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
    Creature* creature = NULL;
    Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck checker(*this, entry, alive, range);
    Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(this, creature, checker);
    Cell::VisitAllObjects(this, searcher, range);
    return creature;
}

GameObject* WorldObject::FindNearestGameObject(uint32 entry, float range) const
{
    GameObject* go = NULL;
    Trinity::NearestGameObjectEntryInObjectRangeCheck checker(*this, entry, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectEntryInObjectRangeCheck> searcher(this, go, checker);
    Cell::VisitGridObjects(this, searcher, range);
    return go;
}

GameObject* WorldObject::FindNearestGameObjectOfType(GameobjectTypes type, float range) const
{
    GameObject* go = NULL;
    Trinity::NearestGameObjectTypeInObjectRangeCheck checker(*this, type, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectTypeInObjectRangeCheck> searcher(this, go, checker);
    Cell::VisitGridObjects(this, searcher, range);
    return go;
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
    x = GetPositionX() + (GetObjectSize() + distance2d) * std::cos(absAngle);
    y = GetPositionY() + (GetObjectSize() + distance2d) * std::sin(absAngle);

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
    GetNearPoint(NULL, x, y, z, size, distance2d, GetOrientation() + angle);
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
    GetNearPoint(obj, x, y, z, obj->GetObjectSize(), distance2d, GetAngle(obj));
}

float WorldObject::GetObjectSize() const
{
    return (m_valuesCount > UNIT_FIELD_COMBATREACH) ? m_floatValues[UNIT_FIELD_COMBATREACH] : DEFAULT_WORLD_OBJECT_SIZE;
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
        TC_LOG_FATAL("misc", "WorldObject::MovePosition: Object (Entry: %u %s) has invalid coordinates X: %f and Y: %f were passed!",
            GetEntry(), GetGUID().ToString().c_str(), destx, desty);
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
        ZLiquidStatus res = obj->GetMap()->getLiquidStatus(obj->GetPhaseShift(), x, y, z, MAP_ALL_LIQUIDS, &liquid_status);
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

void WorldObject::PlayDistanceSound(uint32 soundId, Player* target /*= nullptr*/)
{
    if (target)
        target->SendDirectMessage(WorldPackets::Misc::PlaySpeakerbotSound(GetGUID(), soundId).Write());
    else
        SendMessageToSet(WorldPackets::Misc::PlaySpeakerbotSound(GetGUID(), soundId).Write(), true);
}

void WorldObject::PlayDirectSound(uint32 soundId, Player* target /*= nullptr*/)
{
    if (target)
        target->SendDirectMessage(WorldPackets::Misc::PlaySound(GetGUID(), soundId).Write());
    else
        SendMessageToSet(WorldPackets::Misc::PlaySound(GetGUID(), soundId).Write(), true);
}

void WorldObject::PlayDirectMusic(uint32 musicId, Player* target /*= nullptr*/)
{
    if (target)
        target->SendDirectMessage(WorldPackets::Misc::PlayMusic(musicId).Write());
    else
        SendMessageToSet(WorldPackets::Misc::PlayMusic(musicId).Write(), true);
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

        DestroyForPlayer(player);
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
        Player* source = NULL;
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
        Creature* source = NULL;
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
        DynamicObject* source = NULL;
        for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            source = iter->GetSource();
            ObjectGuid guid = source->GetCasterGUID();

            if (guid.IsPlayer())
            {
                //Caster may be NULL if DynObj is in removelist
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

template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::list<GameObject*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::deque<GameObject*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetGameObjectListWithEntryInGrid(std::vector<GameObject*>&, uint32, float) const;

template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::list<Creature*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::deque<Creature*>&, uint32, float) const;
template TC_GAME_API void WorldObject::GetCreatureListWithEntryInGrid(std::vector<Creature*>&, uint32, float) const;

template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::list<Player*>&, float) const;
template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::deque<Player*>&, float) const;
template TC_GAME_API void WorldObject::GetPlayerListInGrid(std::vector<Player*>&, float) const;
