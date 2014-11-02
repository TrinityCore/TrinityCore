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

#include "Object.h"
#include "Common.h"
#include "SharedDefines.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "Creature.h"
#include "Player.h"
#include "Vehicle.h"
#include "ObjectMgr.h"
#include "UpdateData.h"
#include "UpdateMask.h"
#include "Util.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Log.h"
#include "Transport.h"
#include "TargetedMovementGenerator.h"
#include "WaypointMovementGenerator.h"
#include "VMapFactory.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellAuraEffects.h"
#include "UpdateFieldFlags.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "OutdoorPvPMgr.h"
#include "MovementPacketBuilder.h"
#include "DynamicTree.h"
#include "Unit.h"
#include "Group.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "Chat.h"

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
            ASSERT(false);
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
        ASSERT(false);
        RemoveFromWorld();
    }

    if (m_objectUpdated)
    {
        TC_LOG_FATAL("misc", "Object::~Object %s deleted but still in update list!!", GetGUID().ToString().c_str());
        ASSERT(false);
        sObjectAccessor->RemoveUpdateObject(this);
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
    memset(m_uint32Values, 0, m_valuesCount*sizeof(uint32));

    _changesMask.SetCount(m_valuesCount);

    _dynamicChangesMask.SetCount(_dynamicValuesCount);
    if (_dynamicValuesCount)
    {
        _dynamicValues = new std::vector<uint32>[_dynamicValuesCount];
        _dynamicChangesArrayMask = new UpdateMask[_dynamicValuesCount];
    }

    m_objectUpdated = false;
}

void Object::_Create(ObjectGuid const& guid)
{
    if (!m_uint32Values) _InitValues();

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
    ClearUpdateMask(true);
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
    {
        if (unit->GetVictim())
            flags |= UPDATEFLAG_HAS_TARGET;

        if (unit->GetAIAnimKitId() || unit->GetMovementAnimKitId() || unit->GetMeleeAnimKitId())
            flags |= UPDATEFLAG_ANIMKITS;
    }

    ByteBuffer buf(0x400);
    buf << uint8(updateType);
    buf << GetPackGUID();
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

    BuildCreateUpdateBlockForPlayer(&upd, player);
    upd.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void Object::BuildValuesUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    ByteBuffer buf(500);

    buf << uint8(UPDATETYPE_VALUES);
    buf << GetPackGUID();

    BuildValuesUpdate(UPDATETYPE_VALUES, &buf, target);
    BuildDynamicValuesUpdate(UPDATETYPE_VALUES, &buf, target);

    data->AddUpdateBlock(buf);
}

void Object::BuildOutOfRangeUpdateBlock(UpdateData* data) const
{
    data->AddOutOfRangeGUID(GetGUID());
}

void Object::DestroyForPlayer(Player* target, bool onDeath) const
{
    ASSERT(target);

    if (isType(TYPEMASK_UNIT) || isType(TYPEMASK_PLAYER))
    {
        if (Battleground* bg = target->GetBattleground())
        {
            if (bg->isArena())
            {
                WorldPacket data(SMSG_ARENA_UNIT_DESTROYED, 8);
                data << GetGUID();
                target->GetSession()->SendPacket(&data);
            }
        }
    }

    WorldPacket data(SMSG_DESTROY_OBJECT, 8 + 1);
    data << GetGUID();
    //! If the following bool is true, the client will call "void CGUnit_C::OnDeath()" for this object.
    //! OnDeath() does for eg trigger death animation and interrupts certain spells/missiles/auras/sounds...
    data << uint8(onDeath ? 1 : 0);
    target->GetSession()->SendPacket(&data);
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
    bool IsSuppressingGreetings = false;
    bool HasMovementUpdate = flags & UPDATEFLAG_LIVING;
    bool HasMovementTransport = flags & UPDATEFLAG_GO_TRANSPORT_POSITION;
    bool Stationary = flags & UPDATEFLAG_STATIONARY_POSITION;
    bool CombatVictim = flags & UPDATEFLAG_HAS_TARGET;
    bool ServerTime = flags & UPDATEFLAG_TRANSPORT;
    bool VehicleCreate = flags & UPDATEFLAG_VEHICLE;
    bool AnimKitCreate = flags & UPDATEFLAG_ANIMKITS;
    bool Rotation = flags & UPDATEFLAG_ROTATION;
    bool HasAreaTrigger = false;
    bool HasGameObject = false;
    bool ThisIsYou = flags & UPDATEFLAG_SELF;
    bool ReplaceActive = false;
    bool SceneObjCreate = false;
    bool ScenePendingInstances = false;
    uint32 PauseTimesCount = 0;
    if (GameObject const* go = ToGameObject())
        if (go->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
            PauseTimesCount = go->GetGOValue()->Transport.StopFrames->size();

    data->WriteBit(NoBirthAnim);
    data->WriteBit(EnablePortals); 
    data->WriteBit(PlayHoverAnim);
    data->WriteBit(IsSuppressingGreetings);
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
    data->WriteBit(ThisIsYou);
    data->WriteBit(ReplaceActive);
    data->WriteBit(SceneObjCreate);
    data->WriteBit(ScenePendingInstances);
    *data << uint32(PauseTimesCount);

    if (HasMovementUpdate)
    {
        Unit const* unit = ToUnit();
        bool HasFallDirection = unit->HasUnitMovementFlag(MOVEMENTFLAG_FALLING);
        bool HasFall = HasFallDirection || unit->m_movementInfo.jump.fallTime != 0;
        bool HasSpline = unit->IsSplineEnabled();

        *data << GetPackGUID();                                         // MoverGUID

        *data << uint32(unit->m_movementInfo.time);                     // MoveIndex
        *data << float(unit->GetPositionX());
        *data << float(unit->GetPositionY());
        *data << float(unit->GetPositionZ());
        *data << float(unit->GetOrientation());

        *data << float(unit->m_movementInfo.pitch);                     // Pitch
        *data << float(unit->m_movementInfo.splineElevation);           // StepUpStartElevation

        uint32 removeMovementForcesCount = 0;
        *data << uint32(removeMovementForcesCount);                     // Count of RemoveForcesIDs
        *data << uint32(0);                                             // Unknown

        //for (uint32 i = 0; i < removeMovementForcesCount; ++i)
        //    *data << ObjectGuid(RemoveForcesIDs);

        data->WriteBits(unit->GetUnitMovementFlags(), 30);
        data->WriteBits(unit->GetExtraUnitMovementFlags(), 15);
        data->WriteBit(!unit->m_movementInfo.transport.guid.IsEmpty()); // HasTransport
        data->WriteBit(HasFall);                                        // HasFall
        data->WriteBit(HasSpline);                                      // HasSpline - marks that the unit uses spline movement
        data->WriteBit(0);                                              // HeightChangeFailed
        data->WriteBit(0);                                              // RemoteTimeValid

        if (!unit->m_movementInfo.transport.guid.IsEmpty())
        {
            *data << unit->m_movementInfo.transport.guid;                     // Transport Guid
            *data << float(unit->GetTransOffsetX());
            *data << float(unit->GetTransOffsetY());
            *data << float(unit->GetTransOffsetZ());
            *data << float(unit->GetTransOffsetO());
            *data << int8(unit->m_movementInfo.transport.seat);               // VehicleSeatIndex
            *data << uint32(unit->m_movementInfo.transport.time);             // MoveTime

            data->WriteBit(unit->m_movementInfo.transport.prevTime != 0);
            data->WriteBit(unit->m_movementInfo.transport.vehicleId != 0);

            if (unit->m_movementInfo.transport.prevTime)
                *data << uint32(unit->m_movementInfo.transport.prevTime);     // PrevMoveTime

            if (unit->m_movementInfo.transport.vehicleId)
                *data << uint32(unit->m_movementInfo.transport.vehicleId);    // VehicleRecID
        }

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

        uint32 MovementForceCount = 0;
        *data << uint32(MovementForceCount);

        //for (uint32 i = 0; i < MovementForceCount; ++i)
        //{
        //    *data << ObjectGuid(ID);
        //    *data << Vector3(Direction);
        //    *data << int32(TransportID);
        //    *data << float(Magnitude);
        //    *data << uint8(Type);
        //}

        // HasMovementSpline - marks that spline data is present in packet
        if (data->WriteBit(HasSpline))
            Movement::PacketBuilder::WriteCreate(*unit->movespline, *data);
    }

    if (HasMovementTransport)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << self->m_movementInfo.transport.guid;                   // Transport Guid
        *data << float(self->GetTransOffsetX());
        *data << float(self->GetTransOffsetY());
        *data << float(self->GetTransOffsetZ());
        *data << float(self->GetTransOffsetO());
        *data << int8(self->m_movementInfo.transport.seat);             // VehicleSeatIndex
        *data << uint32(self->m_movementInfo.transport.time);           // MoveTime

        data->WriteBit(self->m_movementInfo.transport.prevTime != 0);
        data->WriteBit(self->m_movementInfo.transport.vehicleId != 0);

        if (self->m_movementInfo.transport.prevTime)
            *data << uint32(self->m_movementInfo.transport.prevTime);   // PrevMoveTime

        if (self->m_movementInfo.transport.vehicleId)
            *data << uint32(self->m_movementInfo.transport.vehicleId);  // VehicleRecID
    }

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
        *data << uint32(unit->GetVehicleKit()->GetVehicleInfo()->m_ID); // RecID
        *data << float(unit->GetOrientation());                         // InitialRawFacing
    }

    if (AnimKitCreate)
    {
        Unit const* unit = ToUnit();
        *data << uint16(unit->GetAIAnimKitId());                        // AiID
        *data << uint16(unit->GetMovementAnimKitId());                  // MovementID
        *data << uint16(unit->GetMeleeAnimKitId());                     // MeleeID
    }

    if (Rotation)
        *data << uint64(ToGameObject()->GetRotation());                 // Rotation

    //if (AreaTrigger)
    //{
    //    packet.ReadInt32("ElapsedMs", index);

    //    packet.ReadVector3("RollPitchYaw1", index);

    //    packet.ResetBitReader();

    //    var HasAbsoluteOrientation = packet.ReadBit("HasAbsoluteOrientation", index);
    //    var HasDynamicShape = packet.ReadBit("HasDynamicShape", index);
    //    var HasAttached = packet.ReadBit("HasAttached", index);
    //    var HasFaceMovementDir = packet.ReadBit("HasFaceMovementDir", index);
    //    var HasFollowsTerrain = packet.ReadBit("HasFollowsTerrain", index);
    //    var HasTargetRollPitchYaw = packet.ReadBit("HasTargetRollPitchYaw", index);
    //    var HasScaleCurveID = packet.ReadBit("HasScaleCurveID", index);
    //    var HasMorphCurveID = packet.ReadBit("HasMorphCurveID", index);
    //    var HasFacingCurveID = packet.ReadBit("HasFacingCurveID", index);
    //    var HasMoveCurveID = packet.ReadBit("HasMoveCurveID", index);
    //    var HasAreaTriggerSphere = packet.ReadBit("HasAreaTriggerSphere", index);
    //    var HasAreaTriggerBox = packet.ReadBit("HasAreaTriggerBox", index);
    //    var HasAreaTriggerPolygon = packet.ReadBit("HasAreaTriggerPolygon", index);
    //    var HasAreaTriggerCylinder = packet.ReadBit("HasAreaTriggerCylinder", index);
    //    var HasAreaTriggerSpline = packet.ReadBit("HasAreaTriggerSpline", index);

    //    if (HasTargetRollPitchYaw)
    //        packet.ReadVector3("TargetRollPitchYaw", index);

    //    if (HasScaleCurveID)
    //        packet.ReadInt32("ScaleCurveID, index");

    //    if (HasMorphCurveID)
    //        packet.ReadInt32("MorphCurveID", index);

    //    if (HasFacingCurveID)
    //        packet.ReadInt32("FacingCurveID", index);

    //    if (HasMoveCurveID)
    //        packet.ReadInt32("MoveCurveID", index);

    //    if (HasAreaTriggerSphere)
    //    {
    //        packet.ReadSingle("Radius", index);
    //        packet.ReadSingle("RadiusTarget", index);
    //    }

    //    if (HasAreaTriggerBox)
    //    {
    //        packet.ReadVector3("Extents", index);
    //        packet.ReadVector3("ExtentsTarget", index);
    //    }

    //    if (HasAreaTriggerPolygon)
    //    {
    //        var VerticesCount = packet.ReadInt32("VerticesCount", index);
    //        var VerticesTargetCount = packet.ReadInt32("VerticesTargetCount", index);
    //        packet.ReadSingle("Height", index);
    //        packet.ReadSingle("HeightTarget", index);

    //        for (var i = 0; i < VerticesCount; ++i)
    //            packet.ReadVector2("Vertices", index, i);

    //        for (var i = 0; i < VerticesTargetCount; ++i)
    //            packet.ReadVector2("VerticesTarget", index, i);
    //    }

    //    if (HasAreaTriggerCylinder)
    //    {
    //        packet.ReadSingle("Radius", index);
    //        packet.ReadSingle("RadiusTarget", index);
    //        packet.ReadSingle("Height", index);
    //        packet.ReadSingle("HeightTarget", index);
    //        packet.ReadSingle("Float4", index);
    //        packet.ReadSingle("Float5", index);
    //    }

    //    if (HasAreaTriggerSpline)
    //    {
    //        packet.ReadInt32("TimeToTarget", index);
    //        packet.ReadInt32("ElapsedTimeForMovement", index);
    //        var int8 = packet.ReadInt32("VerticesCount", index);

    //        for (var i = 0; i < int8; ++i)
    //            packet.ReadVector3("Points", index, i);
    //    }
    //}

    //if (GameObject)
    //{
    //    packet.ReadInt32("WorldEffectID", index);

    //    packet.ResetBitReader();

    //    var bit8 = packet.ReadBit("bit8", index);
    //    if (bit8)
    //        packet.ReadInt32("Int1", index);
    //}

    //if (SceneObjCreate)
    //{
    //    packet.ResetBitReader();

    //    var CliSceneLocalScriptData = packet.ReadBit("CliSceneLocalScriptData", index);
    //    var PetBattleFullUpdate = packet.ReadBit("PetBattleFullUpdate", index);

    //    if (CliSceneLocalScriptData)
    //    {
    //        packet.ResetBitReader();
    //        var DataLength = packet.ReadBits(7);
    //        packet.ReadWoWString("Data", DataLength, index);
    //    }

    //    if (PetBattleFullUpdate)
    //    {
    //        for (var i = 0; i < 2; ++i)
    //        {
    //            packet.ReadPackedGuid128("CharacterID", index, i);

    //            packet.ReadInt32("TrapAbilityID", index, i);
    //            packet.ReadInt32("TrapStatus", index, i);

    //            packet.ReadInt16("RoundTimeSecs", index, i);

    //            packet.ReadByte("FrontPet", index, i);
    //            packet.ReadByte("InputFlags", index, i);

    //            packet.ResetBitReader();

    //            var PetBattlePetUpdateCount = packet.ReadBits("PetBattlePetUpdateCount", 2, index, i);

    //            for (var j = 0; j < PetBattlePetUpdateCount; ++j)
    //            {
    //                packet.ReadPackedGuid128("BattlePetGUID", index, i, j);

    //                packet.ReadInt32("SpeciesID", index, i, j);
    //                packet.ReadInt32("DisplayID", index, i, j);
    //                packet.ReadInt32("CollarID", index, i, j);

    //                packet.ReadInt16("Level", index, i, j);
    //                packet.ReadInt16("Xp", index, i, j);


    //                packet.ReadInt32("CurHealth", index, i, j);
    //                packet.ReadInt32("MaxHealth", index, i, j);
    //                packet.ReadInt32("Power", index, i, j);
    //                packet.ReadInt32("Speed", index, i, j);
    //                packet.ReadInt32("NpcTeamMemberID", index, i, j);

    //                packet.ReadInt16("BreedQuality", index, i, j);
    //                packet.ReadInt16("StatusFlags", index, i, j);

    //                packet.ReadByte("Slot", index, i, j);

    //                var PetBattleActiveAbility = packet.ReadInt32("PetBattleActiveAbility", index, i, j);
    //                var PetBattleActiveAura = packet.ReadInt32("PetBattleActiveAura", index, i, j);
    //                var PetBattleActiveState = packet.ReadInt32("PetBattleActiveState", index, i, j);

    //                for (var k = 0; k < PetBattleActiveAbility; ++k)
    //                {
    //                    packet.ReadInt32("AbilityID", index, i, j, k);
    //                    packet.ReadInt16("CooldownRemaining", index, i, j, k);
    //                    packet.ReadInt16("LockdownRemaining", index, i, j, k);
    //                    packet.ReadByte("AbilityIndex", index, i, j, k);
    //                    packet.ReadByte("Pboid", index, i, j, k);
    //                }

    //                for (var k = 0; k < PetBattleActiveAura; ++k)
    //                {
    //                    packet.ReadInt32("AbilityID", index, i, j, k);
    //                    packet.ReadInt32("InstanceID", index, i, j, k);
    //                    packet.ReadInt32("RoundsRemaining", index, i, j, k);
    //                    packet.ReadInt32("CurrentRound", index, i, j, k);
    //                    packet.ReadByte("CasterPBOID", index, i, j, k);
    //                }

    //                for (var k = 0; k < PetBattleActiveState; ++k)
    //                {
    //                    packet.ReadInt32("StateID", index, i, j, k);
    //                    packet.ReadInt32("StateValue", index, i, j, k);
    //                }

    //                packet.ResetBitReader();
    //                var bits57 = packet.ReadBits(7);
    //                packet.ReadWoWString("CustomName", bits57, index, i, j);
    //            }
    //        }

    //        for (var i = 0; i < 3; ++i)
    //        {
    //            var PetBattleActiveAura = packet.ReadInt32("PetBattleActiveAura", index, i);
    //            var PetBattleActiveState = packet.ReadInt32("PetBattleActiveState", index, i);

    //            for (var j = 0; j < PetBattleActiveAura; ++j)
    //            {
    //                packet.ReadInt32("AbilityID", index, i, j);
    //                packet.ReadInt32("InstanceID", index, i, j);
    //                packet.ReadInt32("RoundsRemaining", index, i, j);
    //                packet.ReadInt32("CurrentRound", index, i, j);
    //                packet.ReadByte("CasterPBOID", index, i, j);
    //            }

    //            for (var j = 0; j < PetBattleActiveState; ++j)
    //            {
    //                packet.ReadInt32("StateID", index, i, j);
    //                packet.ReadInt32("StateValue", index, i, j);
    //            }
    //        }

    //        packet.ReadInt16("WaitingForFrontPetsMaxSecs", index);
    //        packet.ReadInt16("PvpMaxRoundTime", index);

    //        packet.ReadInt32("CurRound", index);
    //        packet.ReadInt32("NpcCreatureID", index);
    //        packet.ReadInt32("NpcDisplayID", index);

    //        packet.ReadByte("CurPetBattleState");
    //        packet.ReadByte("ForfeitPenalty");

    //        packet.ReadPackedGuid128("InitialWildPetGUID");

    //        packet.ReadBit("IsPVP");
    //        packet.ReadBit("CanAwardXP");
    //    }
    //}

    //if (ScenePendingInstances)
    //{
    //    var SceneInstanceIDs = packet.ReadInt32("SceneInstanceIDsCount");

    //    for (var i = 0; i < SceneInstanceIDs; ++i)
    //        packet.ReadInt32("SceneInstanceIDs", index, i);
    //}

    if (GameObject const* go = ToGameObject())
        for (uint32 i = 0; i < PauseTimesCount; ++i)
            *data << uint32(go->GetGOValue()->Transport.StopFrames->at(i));

    data->FlushBits();
}

void Object::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    ByteBuffer fieldBuffer;
    UpdateMask updateMask;
    updateMask.SetCount(m_valuesCount);

    uint32* flags = NULL;
    uint32 visibleFlag = GetUpdateFieldData(target, flags);

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

void Object::BuildDynamicValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    ByteBuffer fieldBuffer;
    UpdateMask updateMask;
    updateMask.SetCount(_dynamicValuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetDynamicUpdateFieldData(target, flags);

    for (uint16 index = 0; index < _dynamicValuesCount; ++index)
    {
        ByteBuffer buffer;
        std::vector<uint32> const& values = _dynamicValues[index];
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _dynamicChangesMask.GetBit(index) : !values.empty()) && (flags[index] & visibleFlag)))
        {
            updateMask.SetBit(index);

            UpdateMask arrayMask;
            arrayMask.SetCount(values.size());
            for (std::size_t v = 0; v < values.size(); ++v)
            {
                if (updateType != UPDATETYPE_VALUES || _dynamicChangesArrayMask[index].GetBit(v))
                {
                    arrayMask.SetBit(v);
                    buffer << uint32(values[v]);
                }
            }

            fieldBuffer << uint8(arrayMask.GetBlockCount());
            arrayMask.AppendToPacket(&fieldBuffer);
            fieldBuffer.append(buffer);
        }
    }

    *data << uint8(updateMask.GetBlockCount());
    updateMask.AppendToPacket(data);
    data->append(fieldBuffer);
}

void Object::ClearUpdateMask(bool remove)
{
    _changesMask.Clear();
    _dynamicChangesMask.Clear();
    for (uint32 i = 0; i < _dynamicValuesCount; ++i)
        _dynamicChangesArrayMask[i].Clear();

    if (m_objectUpdated)
    {
        if (remove)
            sObjectAccessor->RemoveUpdateObject(this);
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
        case TYPEID_OBJECT:
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
        m_uint32Values[startOffset + index] = atol(tokens[index]);
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
    }
}

void Object::SetUInt32Value(uint16 index, uint32 value)
{
    ASSERT(index < m_valuesCount || PrintIndexError(index, true));

    if (m_uint32Values[index] != value)
    {
        m_uint32Values[index] = value;
        _changesMask.SetBit(index);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
    }
}

bool Object::AddGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (!value.IsEmpty() && ((ObjectGuid*)&(m_uint32Values[index]))->IsEmpty())
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }

        return true;
    }

    return false;
}

bool Object::RemoveGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (!value.IsEmpty() && *((ObjectGuid*)&(m_uint32Values[index])) == value)
    {
        m_uint32Values[index] = 0;
        m_uint32Values[index + 1] = 0;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }

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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
    }
}

void Object::SetGuidValue(uint16 index, ObjectGuid const& value)
{
    ASSERT(index + 1 < m_valuesCount || PrintIndexError(index, true));
    if (*((ObjectGuid*)&(m_uint32Values[index])) != value)
    {
        *((ObjectGuid*)&(m_uint32Values[index])) = value;
        _changesMask.SetBit(index);
        _changesMask.SetBit(index + 1);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
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

void Object::AddDynamicValue(uint16 index, uint32 value)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    std::vector<uint32>& values = _dynamicValues[index];
    UpdateMask& mask = _dynamicChangesArrayMask[index];

    _dynamicChangesMask.SetBit(index);
    if (values.size() >= values.capacity())
        values.reserve(values.capacity() + 32);

    values.push_back(value);
    if (mask.GetCount() < values.size())
        mask.AddBlock();

    mask.SetBit(values.size());

    if (m_inWorld && !m_objectUpdated)
    {
        sObjectAccessor->AddUpdateObject(this);
        m_objectUpdated = true;
    }
}

void Object::RemoveDynamicValue(uint16 index, uint32 /*value*/)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));
    /// TODO: Research if this is actually needed
}

void Object::ClearDynamicValue(uint16 index)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    if (!_dynamicValues[index].empty())
    {
        _dynamicValues[index].clear();
        _dynamicChangesMask.SetBit(index);
        _dynamicChangesArrayMask[index].SetCount(0);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
    }
}

void Object::SetDynamicValue(uint16 index, uint8 offset, uint32 value)
{
    ASSERT(index < _dynamicValuesCount || PrintIndexError(index, false));

    std::vector<uint32>& values = _dynamicValues[index];

    ASSERT(offset < values.size());

    if (values[offset] != value)
    {
        values[offset] = value;
        _dynamicChangesMask.SetBit(index);
        _dynamicChangesArrayMask[index].SetBit(offset);

        if (m_inWorld && !m_objectUpdated)
        {
            sObjectAccessor->AddUpdateObject(this);
            m_objectUpdated = true;
        }
    }
}

bool Object::PrintIndexError(uint32 index, bool set) const
{
    TC_LOG_ERROR("misc", "Attempt %s non-existed value field: %u (count: %u) for object typeid: %u type mask: %u", (set ? "set value to" : "get value from"), index, m_valuesCount, GetTypeId(), m_objectType);

    // ASSERT must fail after function call
    return false;
}

bool Position::operator==(Position const &a)
{
    return (G3D::fuzzyEq(a.m_positionX, m_positionX) &&
            G3D::fuzzyEq(a.m_positionY, m_positionY) &&
            G3D::fuzzyEq(a.m_positionZ, m_positionZ) &&
            G3D::fuzzyEq(a.m_orientation, m_orientation));
}

bool Position::HasInLine(WorldObject const* target, float width) const
{
    if (!HasInArc(float(M_PI), target))
        return false;
    width += target->GetObjectSize();
    float angle = GetRelativeAngle(target);
    return std::fabs(std::sin(angle)) * GetExactDist2d(target->GetPositionX(), target->GetPositionY()) < width;
}

std::string Position::ToString() const
{
    std::stringstream sstr;
    sstr << "X: " << m_positionX << " Y: " << m_positionY << " Z: " << m_positionZ << " O: " << m_orientation;
    return sstr.str();
}

ByteBuffer& operator>>(ByteBuffer& buf, Position::PositionXYZOStreamer const& streamer)
{
    float x, y, z, o;
    buf >> x >> y >> z >> o;
    streamer.m_pos->Relocate(x, y, z, o);
    return buf;
}
ByteBuffer& operator<<(ByteBuffer& buf, Position::PositionXYZStreamer const& streamer)
{
    float x, y, z;
    streamer.m_pos->GetPosition(x, y, z);
    buf << x << y << z;
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, Position::PositionXYZStreamer const& streamer)
{
    float x, y, z;
    buf >> x >> y >> z;
    streamer.m_pos->Relocate(x, y, z);
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, Position::PositionXYZOStreamer const& streamer)
{
    float x, y, z, o;
    streamer.m_pos->GetPosition(x, y, z, o);
    buf << x << y << z << o;
    return buf;
}

void MovementInfo::OutDebug()
{
    TC_LOG_INFO("misc", "MOVEMENT INFO");
    TC_LOG_INFO("misc", "%s", guid.ToString().c_str());
    TC_LOG_INFO("misc", "flags %s (%u)", Movement::MovementFlags_ToString(flags).c_str(), flags);
    TC_LOG_INFO("misc", "flags2 %s (%u)", Movement::MovementFlagsExtra_ToString(flags2).c_str(), flags2);
    TC_LOG_INFO("misc", "time %u current time %u", time, getMSTime());
    TC_LOG_INFO("misc", "position: `%s`", pos.ToString().c_str());
    if (!transport.guid.IsEmpty())
    {
        TC_LOG_INFO("misc", "TRANSPORT:");
        TC_LOG_INFO("misc", "%s", transport.guid.ToString().c_str());
        TC_LOG_INFO("misc", "position: `%s`", transport.pos.ToString().c_str());
        TC_LOG_INFO("misc", "seat: %i", transport.seat);
        TC_LOG_INFO("misc", "time: %u", transport.time);
        if (flags2 & MOVEMENTFLAG2_INTERPOLATED_MOVEMENT)
            TC_LOG_INFO("misc", "prevTime: %u", transport.prevTime);
        if (transport.vehicleId)
            TC_LOG_INFO("misc", "vehicleId: %u", transport.vehicleId);
    }

    if ((flags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        TC_LOG_INFO("misc", "pitch: %f", pitch);

    if (flags & MOVEMENTFLAG_FALLING || jump.fallTime)
    {
        TC_LOG_INFO("misc", "fallTime: %u j_zspeed: %f", jump.fallTime, jump.zspeed);
        if (flags & MOVEMENTFLAG_FALLING)
            TC_LOG_INFO("misc", "j_sinAngle: %f j_cosAngle: %f j_xyspeed: %f", jump.sinAngle, jump.cosAngle, jump.xyspeed);
    }

    if (flags & MOVEMENTFLAG_SPLINE_ELEVATION)
        TC_LOG_INFO("misc", "splineElevation: %f", splineElevation);
}

WorldObject::WorldObject(bool isWorldObject) : WorldLocation(), LastUsedScriptID(0),
m_name(""), m_isActive(false), m_isWorldObject(isWorldObject), m_zoneScript(NULL),
m_transport(NULL), m_currMap(NULL), m_InstanceId(0),
m_phaseMask(PHASEMASK_NORMAL), m_notifyflags(0), m_executed_notifies(0)
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
    return GetBaseMap()->GetZoneId(m_positionX, m_positionY, m_positionZ);
}

uint32 WorldObject::GetAreaId() const
{
    return GetBaseMap()->GetAreaId(m_positionX, m_positionY, m_positionZ);
}

void WorldObject::GetZoneAndAreaId(uint32& zoneid, uint32& areaid) const
{
    GetBaseMap()->GetZoneAndAreaId(zoneid, areaid, m_positionX, m_positionY, m_positionZ);
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

    float ox, oy, oz;
    obj->GetPosition(ox, oy, oz);
    return IsWithinLOS(ox, oy, oz);
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
        return GetMap()->isInLineOfSight(GetPositionX(), GetPositionY(), GetPositionZ()+2.f, ox, oy, oz+2.f, GetPhaseMask());

    return true;
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

void Position::RelocateOffset(const Position & offset)
{
    m_positionX = GetPositionX() + (offset.GetPositionX() * std::cos(GetOrientation()) + offset.GetPositionY() * std::sin(GetOrientation() + float(M_PI)));
    m_positionY = GetPositionY() + (offset.GetPositionY() * std::cos(GetOrientation()) + offset.GetPositionX() * std::sin(GetOrientation()));
    m_positionZ = GetPositionZ() + offset.GetPositionZ();
    SetOrientation(GetOrientation() + offset.GetOrientation());
}

void Position::GetPositionOffsetTo(const Position & endPos, Position & retOffset) const
{
    float dx = endPos.GetPositionX() - GetPositionX();
    float dy = endPos.GetPositionY() - GetPositionY();

    retOffset.m_positionX = dx * std::cos(GetOrientation()) + dy * std::sin(GetOrientation());
    retOffset.m_positionY = dy * std::cos(GetOrientation()) - dx * std::sin(GetOrientation());
    retOffset.m_positionZ = endPos.GetPositionZ() - GetPositionZ();
    retOffset.SetOrientation(endPos.GetOrientation() - GetOrientation());
}

Position Position::GetPositionWithOffset(Position const& offset) const
{
    Position ret(*this);
    ret.RelocateOffset(offset);
    return ret;
}

float Position::GetAngle(const Position* obj) const
{
    if (!obj)
        return 0;

    return GetAngle(obj->GetPositionX(), obj->GetPositionY());
}

// Return angle in range 0..2*pi
float Position::GetAngle(const float x, const float y) const
{
    float dx = x - GetPositionX();
    float dy = y - GetPositionY();

    float ang = std::atan2(dy, dx);
    ang = (ang >= 0) ? ang : 2 * float(M_PI) + ang;
    return ang;
}

void Position::GetSinCos(const float x, const float y, float &vsin, float &vcos) const
{
    float dx = GetPositionX() - x;
    float dy = GetPositionY() - y;

    if (std::fabs(dx) < 0.001f && std::fabs(dy) < 0.001f)
    {
        float angle = (float)rand_norm()*static_cast<float>(2*M_PI);
        vcos = std::cos(angle);
        vsin = std::sin(angle);
    }
    else
    {
        float dist = std::sqrt((dx*dx) + (dy*dy));
        vcos = dx / dist;
        vsin = dy / dist;
    }
}

bool Position::HasInArc(float arc, const Position* obj, float border) const
{
    // always have self in arc
    if (obj == this)
        return true;

    // move arc to range 0.. 2*pi
    arc = NormalizeOrientation(arc);

    float angle = GetAngle(obj);
    angle -= m_orientation;

    // move angle to range -pi ... +pi
    angle = NormalizeOrientation(angle);
    if (angle > float(M_PI))
        angle -= 2.0f * float(M_PI);

    float lborder = -1 * (arc/border);                        // in range -pi..0
    float rborder = (arc/border);                             // in range 0..pi
    return ((angle >= lborder) && (angle <= rborder));
}

bool WorldObject::IsInBetween(const WorldObject* obj1, const WorldObject* obj2, float size) const
{
    if (!obj1 || !obj2)
        return false;

    float dist = GetExactDist2d(obj1->GetPositionX(), obj1->GetPositionY());

    // not using sqrt() for performance
    if ((dist * dist) >= obj1->GetExactDist2dSq(obj2->GetPositionX(), obj2->GetPositionY()))
        return false;

    if (!size)
        size = GetObjectSize() / 2;

    float angle = obj1->GetAngle(obj2);

    // not using sqrt() for performance
    return (size * size) >= GetExactDist2dSq(obj1->GetPositionX() + std::cos(angle) * dist, obj1->GetPositionY() + std::sin(angle) * dist);
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
    float new_dist = (float)rand_norm()*static_cast<float>(distance);

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
    float new_z = GetMap()->GetHeight(GetPhaseMask(), x, y, z + 2.0f, true);
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
                    ? GetMap()->GetWaterOrGroundLevel(x, y, z, &ground_z, !ToUnit()->HasAuraType(SPELL_AURA_WATER_WALK))
                    : ((ground_z = GetMap()->GetHeight(GetPhaseMask(), x, y, z, true)));
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
                float ground_z = GetMap()->GetHeight(GetPhaseMask(), x, y, z, true);
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
                float max_z = GetMap()->GetWaterOrGroundLevel(x, y, z, &ground_z, !ToUnit()->HasAuraType(SPELL_AURA_WATER_WALK));
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
                float ground_z = GetMap()->GetHeight(GetPhaseMask(), x, y, z, true);
                if (z < ground_z)
                    z = ground_z;
            }
            break;
        }
        default:
        {
            float ground_z = GetMap()->GetHeight(GetPhaseMask(), x, y, z, true);
            if (ground_z > INVALID_HEIGHT)
                z = ground_z;
            break;
        }
    }
}

bool Position::IsPositionValid() const
{
    return Trinity::IsValidMapCoord(m_positionX, m_positionY, m_positionZ, m_orientation);
}

float WorldObject::GetGridActivationRange() const
{
    if (ToPlayer())
        return GetMap()->GetVisibilityRange();
    else if (ToCreature())
        return ToCreature()->m_SightDistance;
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
            else
                return GetMap()->GetVisibilityRange();
        }
        else if (ToCreature())
            return ToCreature()->m_SightDistance;
        else
            return SIGHT_RANGE_UNIT;
    }

    return 0.0f;
}

bool WorldObject::CanSeeOrDetect(WorldObject const* obj, bool ignoreStealth, bool distanceCheck) const
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

    if (!CanDetect(obj, ignoreStealth))
        return false;

    return true;
}

bool WorldObject::CanNeverSee(WorldObject const* obj) const
{
    return GetMap() != obj->GetMap() || !IsInPhase(obj);
}

bool WorldObject::CanDetect(WorldObject const* obj, bool ignoreStealth) const
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

    if (!ignoreStealth && !seer->CanDetectStealthOf(obj))
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

bool WorldObject::CanDetectStealthOf(WorldObject const* obj) const
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
        detectionValue += int32(getLevelForTarget(obj) - 1) * 5;

        // Apply modifiers
        detectionValue += m_stealthDetect.GetValue(StealthType(i));
        if (go)
            if (Unit* owner = go->GetOwner())
                detectionValue -= int32(owner->getLevelForTarget(this) - 1) * 5;

        detectionValue -= obj->m_stealth.GetValue(StealthType(i));

        // Calculate max distance
        float visibilityRange = float(detectionValue) * 0.3f + combatReach;

        if (visibilityRange > MAX_PLAYER_STEALTH_DETECT_RANGE)
            visibilityRange = MAX_PLAYER_STEALTH_DETECT_RANGE;

        if (distance > visibilityRange)
            return false;
    }

    return true;
}

void Object::ForceValuesUpdateAtIndex(uint32 i)
{
    _changesMask.SetBit(i);
    if (m_inWorld && !m_objectUpdated)
    {
        sObjectAccessor->AddUpdateObject(this);
        m_objectUpdated = true;
    }
}

void WorldObject::SendMessageToSet(WorldPacket* data, bool self)
{
    if (IsInWorld())
        SendMessageToSetInRange(data, GetVisibilityRange(), self);
}

void WorldObject::SendMessageToSetInRange(WorldPacket* data, float dist, bool /*self*/)
{
    Trinity::MessageDistDeliverer notifier(this, data, dist);
    VisitNearbyWorldObject(dist, notifier);
}

void WorldObject::SendMessageToSet(WorldPacket* data, Player const* skipped_rcvr)
{
    Trinity::MessageDistDeliverer notifier(this, data, GetVisibilityRange(), false, skipped_rcvr);
    VisitNearbyWorldObject(GetVisibilityRange(), notifier);
}

void WorldObject::SendObjectDeSpawnAnim(ObjectGuid guid)
{
    WorldPacket data(SMSG_GAMEOBJECT_DESPAWN_ANIM, 8);
    data << guid;
    SendMessageToSet(&data, true);
}

void WorldObject::SetMap(Map* map)
{
    ASSERT(map);
    ASSERT(!IsInWorld() || GetTypeId() == TYPEID_CORPSE);
    if (m_currMap == map) // command add npc: first create, than loadfromdb
        return;
    if (m_currMap)
    {
        TC_LOG_FATAL("misc", "WorldObject::SetMap: obj %u new map %u %u, old map %u %u", (uint32)GetTypeId(), map->GetId(), map->GetInstanceId(), m_currMap->GetId(), m_currMap->GetInstanceId());
        ASSERT(false);
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
                return NULL;
        }
    }

    std::set<uint32> phases;
    if (summoner)
        phases = summoner->GetPhases();

    TempSummon* summon = NULL;
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

    if (!summon->Create(sObjectMgr->GetGenerator<HighGuid::Creature>()->Generate(), this, 0, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), nullptr, vehId))
    {
        delete summon;
        return NULL;
    }

    // Set the summon to the summoner's phase
    for (auto phaseId : phases)
        summon->SetInPhase(phaseId, false, true);

    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);

    summon->SetHomePosition(pos);

    summon->InitStats(duration);
    AddToMap(summon->ToCreature());
    summon->InitSummon();

    //ObjectAccessor::UpdateObjectVisibility(summon);

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

TempSummon* WorldObject::SummonCreature(uint32 entry, const Position &pos, TempSummonType spwtype, uint32 duration, uint32 /*vehId*/) const
{
    if (Map* map = FindMap())
    {
        if (TempSummon* summon = map->SummonCreature(entry, pos, NULL, duration, isType(TYPEMASK_UNIT) ? (Unit*)this : NULL))
        {
            summon->SetTempSummonType(spwtype);
            return summon;
        }
    }

    return NULL;
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

GameObject* WorldObject::SummonGameObject(uint32 entry, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime)
{
    if (!IsInWorld())
        return NULL;

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject template %u not found in database!", entry);
        return NULL;
    }

    Map* map = GetMap();
    GameObject* go = new GameObject();
    if (!go->Create(sObjectMgr->GetGenerator<HighGuid::GameObject>()->Generate(), entry, map, GetPhaseMask(), x, y, z, ang, rotation0, rotation1, rotation2, rotation3, 100, GO_STATE_READY))
    {
        delete go;
        return NULL;
    }

    for (auto phase : GetPhases())
        go->SetInPhase(phase, false, true);

    go->SetRespawnTime(respawnTime);
    if (GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT) //not sure how to handle this
        ToUnit()->AddGameObject(go);
    else
        go->SetSpawnedByDefault(false);

    map->AddToMap(go);
    return go;
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
        return;

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
    VisitNearbyObject(range, searcher);
    return creature;
}

GameObject* WorldObject::FindNearestGameObject(uint32 entry, float range) const
{
    GameObject* go = NULL;
    Trinity::NearestGameObjectEntryInObjectRangeCheck checker(*this, entry, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectEntryInObjectRangeCheck> searcher(this, go, checker);
    VisitNearbyGridObject(range, searcher);
    return go;
}

GameObject* WorldObject::FindNearestGameObjectOfType(GameobjectTypes type, float range) const
{
    GameObject* go = NULL;
    Trinity::NearestGameObjectTypeInObjectRangeCheck checker(*this, type, range);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectTypeInObjectRangeCheck> searcher(this, go, checker);
    VisitNearbyGridObject(range, searcher);
    return go;
}

void WorldObject::GetGameObjectListWithEntryInGrid(std::list<GameObject*>& gameobjectList, uint32 entry, float maxSearchRange) const
{
    CellCoord pair(Trinity::ComputeCellCoord(this->GetPositionX(), this->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    Trinity::AllGameObjectsWithEntryInRange check(this, entry, maxSearchRange);
    Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInRange> searcher(this, gameobjectList, check);
    TypeContainerVisitor<Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInRange>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(this->GetMap()), *this, maxSearchRange);
}

void WorldObject::GetCreatureListWithEntryInGrid(std::list<Creature*>& creatureList, uint32 entry, float maxSearchRange) const
{
    CellCoord pair(Trinity::ComputeCellCoord(this->GetPositionX(), this->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    Trinity::AllCreaturesOfEntryInRange check(this, entry, maxSearchRange);
    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(this, creatureList, check);
    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(this->GetMap()), *this, maxSearchRange);
}

/*
namespace Trinity
{
    class NearUsedPosDo
    {
        public:
            NearUsedPosDo(WorldObject const& obj, WorldObject const* searcher, float angle, ObjectPosSelector& selector)
                : i_object(obj), i_searcher(searcher), i_angle(angle), i_selector(selector) { }

            void operator()(Corpse*) const { }
            void operator()(DynamicObject*) const { }

            void operator()(Creature* c) const
            {
                // skip self or target
                if (c == i_searcher || c == &i_object)
                    return;

                float x, y, z;

                if (!c->IsAlive() || c->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DISTRACTED) ||
                    !c->GetMotionMaster()->GetDestination(x, y, z))
                {
                    x = c->GetPositionX();
                    y = c->GetPositionY();
                }

                add(c, x, y);
            }

            template<class T>
                void operator()(T* u) const
            {
                // skip self or target
                if (u == i_searcher || u == &i_object)
                    return;

                float x, y;

                x = u->GetPositionX();
                y = u->GetPositionY();

                add(u, x, y);
            }

            // we must add used pos that can fill places around center
            void add(WorldObject* u, float x, float y) const
            {
                // u is too nearest/far away to i_object
                if (!i_object.IsInRange2d(x, y, i_selector.m_dist - i_selector.m_size, i_selector.m_dist + i_selector.m_size))
                    return;

                float angle = i_object.GetAngle(u)-i_angle;

                // move angle to range -pi ... +pi
                while (angle > M_PI)
                    angle -= 2.0f * M_PI;
                while (angle < -M_PI)
                    angle += 2.0f * M_PI;

                // dist include size of u
                float dist2d = i_object.GetDistance2d(x, y);
                i_selector.AddUsedPos(u->GetObjectSize(), angle, dist2d + i_object.GetObjectSize());
            }
        private:
            WorldObject const& i_object;
            WorldObject const* i_searcher;
            float              i_angle;
            ObjectPosSelector& i_selector;
    };
}                                                           // namespace Trinity
*/

//===================================================================================================

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

    ground = GetMap()->GetHeight(GetPhaseMask(), destx, desty, MAX_HEIGHT, true);
    floor = GetMap()->GetHeight(GetPhaseMask(), destx, desty, pos.m_positionZ, true);
    destz = std::fabs(ground - pos.m_positionZ) <= std::fabs(floor - pos.m_positionZ) ? ground : floor;

    float step = dist/10.0f;

    for (uint8 j = 0; j < 10; ++j)
    {
        // do not allow too big z changes
        if (std::fabs(pos.m_positionZ - destz) > 6)
        {
            destx -= step * std::cos(angle);
            desty -= step * std::sin(angle);
            ground = GetMap()->GetHeight(GetPhaseMask(), destx, desty, MAX_HEIGHT, true);
            floor = GetMap()->GetHeight(GetPhaseMask(), destx, desty, pos.m_positionZ, true);
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
    float ground = obj->GetMap()->GetHeight(obj->GetPhaseMask(), x, y, MAX_HEIGHT, true);
    float floor = obj->GetMap()->GetHeight(obj->GetPhaseMask(), x, y, z + 2.0f, true);
    float helper = std::fabs(ground - z) <= std::fabs(floor - z) ? ground : floor;
    if (z > helper) // must be above ground
    {
        if (Unit* unit = obj->ToUnit())
        {
            if (unit->CanFly())
                return z;
        }
        LiquidData liquid_status;
        ZLiquidStatus res = obj->GetMap()->getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, &liquid_status);
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
    bool col = VMAP::VMapFactory::createOrGetVMapManager()->getObjectHitPos(GetMapId(), pos.m_positionX, pos.m_positionY, pos.m_positionZ + 0.5f, destx, desty, destz + 0.5f, destx, desty, destz, -0.5f);

    // collision occured
    if (col)
    {
        // move back a bit
        destx -= CONTACT_DISTANCE * std::cos(angle);
        desty -= CONTACT_DISTANCE * std::sin(angle);
        dist = std::sqrt((pos.m_positionX - destx)*(pos.m_positionX - destx) + (pos.m_positionY - desty)*(pos.m_positionY - desty));
    }

    // check dynamic collision
    col = GetMap()->getObjectHitPos(GetPhaseMask(), pos.m_positionX, pos.m_positionY, pos.m_positionZ + 0.5f, destx, desty, destz + 0.5f, destx, desty, destz, -0.5f);

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

void WorldObject::SetInPhase(uint32 id, bool update, bool apply)
{
    if (apply)
        _phases.insert(id);
    else
        _phases.erase(id);

    if (update && IsInWorld())
        UpdateObjectVisibility();
}

bool WorldObject::IsInPhase(WorldObject const* obj) const
{
    // PhaseId 169 is the default fallback phase
    if (_phases.empty() && obj->GetPhases().empty())
        return true;

    if (_phases.empty() && obj->IsInPhase(169))
        return true;

    if (obj->GetPhases().empty() && IsInPhase(169))
        return true;

    return Trinity::Containers::Intersects(_phases.begin(), _phases.end(), obj->GetPhases().begin(), obj->GetPhases().end());
}

bool WorldObject::InSamePhase(WorldObject const* obj) const
{
    return IsInPhase(obj);
    // return InSamePhase(obj->GetPhaseMask());
}

void WorldObject::PlayDistanceSound(uint32 sound_id, Player* target /*= NULL*/)
{
    WorldPacket data(SMSG_PLAY_OBJECT_SOUND, 4 + 8);
    data << uint32(sound_id);
    data << GetGUID();
    if (target)
        target->SendDirectMessage(&data);
    else
        SendMessageToSet(&data, true);
}

void WorldObject::PlayDirectSound(uint32 sound_id, Player* target /*= NULL*/)
{
    WorldPacket data(SMSG_PLAY_SOUND, 4 + 8);
    data << uint32(sound_id);
    data << GetGUID();
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
    VisitNearbyWorldObject(GetVisibilityRange(), searcher);
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
    VisitNearbyWorldObject(GetVisibilityRange(), notifier);
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
    CellCoord p = Trinity::ComputeCellCoord(GetPositionX(), GetPositionY());
    Cell cell(p);
    cell.SetNoCreate();
    WorldObjectChangeAccumulator notifier(*this, data_map);
    TypeContainerVisitor<WorldObjectChangeAccumulator, WorldTypeMapContainer > player_notifier(notifier);
    Map& map = *GetMap();
    //we must build packets for all visible players
    cell.Visit(p, player_notifier, map, *this, GetVisibilityRange());

    ClearUpdateMask(false);
}

ObjectGuid WorldObject::GetTransGUID() const
{
    if (GetTransport())
        return GetTransport()->GetGUID();
    return ObjectGuid::Empty;
}
