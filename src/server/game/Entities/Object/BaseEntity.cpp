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

#include "BaseEntity.h"
#include "Conversation.h"
#include "DB2Structure.h"
#include "Errors.h"
#include "GameTime.h"
#include "Log.h"
#include "MovementPackets.h"
#include "Player.h"
#include "SmoothPhasing.h"
#include "Transport.h"
#include "UpdateData.h"
#include "Vehicle.h"

BaseEntity::BaseEntity() = default;

BaseEntity::~BaseEntity()
{
    if (IsInWorld())
    {
        TC_LOG_FATAL("misc", "BaseEntity::~BaseEntity {} deleted but still in world!!", GetGUID());
        ABORT();
    }

    if (m_objectUpdated)
    {
        TC_LOG_FATAL("misc", "BaseEntity::~BaseEntity {} deleted but still in update list!!", GetGUID());
        ABORT();
    }
}

void BaseEntity::AddToWorld()
{
    if (m_inWorld)
        return;

    m_inWorld = true;

    // synchronize values mirror with values array (changes will send in updatecreate opcode any way
    ASSERT(!m_objectUpdated);
    ClearUpdateMask(false);
}

void BaseEntity::RemoveFromWorld()
{
    if (!m_inWorld)
        return;

    m_inWorld = false;

    // if we remove from world then sending changes not required
    ClearUpdateMask(true);
}

void BaseEntity::BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    if (!target)
        return;

    uint8 updateType = m_isNewObject ? UPDATETYPE_CREATE_OBJECT2 : UPDATETYPE_CREATE_OBJECT;
    uint8 objectType = m_objectTypeId;
    CreateObjectBits flags = m_updateFlag;

    if (target == this)                                      // building packet for yourself
    {
        flags.ThisIsYou = true;
        flags.ActivePlayer = true;
        objectType = TYPEID_ACTIVE_PLAYER;
    }

    if (IsWorldObject())
    {
        WorldObject const* worldObject = static_cast<WorldObject const*>(this);
        if (worldObject->GetSmoothPhasing() && worldObject->GetSmoothPhasing()->GetInfoForSeer(target->GetGUID()))
            flags.SmoothPhasing = true;
    }

    ByteBuffer& buf = data->GetBuffer();
    buf << uint8(updateType);
    buf << GetGUID();
    buf << uint8(objectType);

    BuildMovementUpdate(&buf, flags, target);

    UF::UpdateFieldFlag fieldFlags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = buf.wpos();
    buf << uint32(0);
    buf << uint8(fieldFlags);
    BuildEntityFragments(&buf, m_entityFragments.GetIds());

    for (std::size_t i = 0; i < m_entityFragments.UpdateableCount; ++i)
    {
        WowCS::EntityFragment fragmentId = m_entityFragments.Updateable.Ids[i];
        if (WowCS::IsIndirectFragment(fragmentId))
            buf << uint8(1);  // IndirectFragmentActive

        m_entityFragments.Updateable.SerializeCreate[i](this, buf, fieldFlags, target);
    }

    buf.put<uint32>(sizePos, buf.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void BaseEntity::SendUpdateToPlayer(Player* player) const
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

void BaseEntity::BuildValuesUpdateBlockForPlayer(UpdateData* data, Player const* target) const
{
    ByteBuffer& buf = PrepareValuesUpdateBuffer(data);

    EnumFlag<UF::UpdateFieldFlag> fieldFlags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = buf.wpos();
    buf << uint32(0);
    buf << uint8(fieldFlags.HasFlag(UF::UpdateFieldFlag::Owner));
    buf << uint8(m_entityFragments.IdsChanged);
    if (m_entityFragments.IdsChanged)
    {
        buf << uint8(WowCS::EntityFragmentSerializationType::Full);
        BuildEntityFragments(&buf, m_entityFragments.GetIds());
    }
    buf << uint8(m_entityFragments.ContentsChangedMask);

    for (std::size_t i = 0; i < m_entityFragments.UpdateableCount; ++i)
    {
        if (!(m_entityFragments.ContentsChangedMask & m_entityFragments.Updateable.Masks[i]))
            continue;

        m_entityFragments.Updateable.SerializeUpdate[i](this, buf, fieldFlags, target);
    }

    buf.put<uint32>(sizePos, buf.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

inline void BaseEntity::BuildEntityFragments(ByteBuffer* data, std::span<WowCS::EntityFragment const> fragments)
{
    data->append(fragments.data(), fragments.size());
    *data << uint8(WowCS::EntityFragment::End);
}

void BaseEntity::BuildDestroyUpdateBlock(UpdateData* data) const
{
    data->AddDestroyObject(GetGUID());
}

void BaseEntity::BuildOutOfRangeUpdateBlock(UpdateData* data) const
{
    data->AddOutOfRangeGUID(GetGUID());
}

ByteBuffer& BaseEntity::PrepareValuesUpdateBuffer(UpdateData* data) const
{
    ByteBuffer& buffer = data->GetBuffer();
    buffer << uint8(UPDATETYPE_VALUES);
    buffer << GetGUID();
    return buffer;
}

void BaseEntity::DestroyForPlayer(Player const* target) const
{
    ASSERT(target);

    UpdateData updateData(target->GetMapId());
    BuildDestroyUpdateBlock(&updateData);
    WorldPacket packet;
    updateData.BuildPacket(&packet);
    target->SendDirectMessage(&packet);
}

void BaseEntity::SendOutOfRangeForPlayer(Player const* target) const
{
    ASSERT(target);

    UpdateData updateData(target->GetMapId());
    BuildOutOfRangeUpdateBlock(&updateData);
    WorldPacket packet;
    updateData.BuildPacket(&packet);
    target->SendDirectMessage(&packet);
}

void BaseEntity::BuildMovementUpdate(ByteBuffer* data, CreateObjectBits flags, Player const* target) const
{
    std::span<uint32 const> PauseTimes;
    if (IsGameObject())
        PauseTimes = static_cast<GameObject const*>(this)->GetPauseTimes();

    data->WriteBit(flags.HasEntityPosition);
    data->WriteBit(flags.NoBirthAnim);
    data->WriteBit(flags.EnablePortals);
    data->WriteBit(flags.PlayHoverAnim);
    data->WriteBit(flags.ThisIsYou);
    data->WriteBit(flags.MovementUpdate);
    data->WriteBit(flags.MovementTransport);
    data->WriteBit(flags.Stationary);
    data->WriteBit(flags.CombatVictim);
    data->WriteBit(flags.ServerTime);
    data->WriteBit(flags.Vehicle);
    data->WriteBit(flags.AnimKit);
    data->WriteBit(flags.Rotation);
    data->WriteBit(flags.GameObject);
    data->WriteBit(flags.SmoothPhasing);
    data->WriteBit(flags.SceneObject);
    data->WriteBit(flags.ActivePlayer);
    data->WriteBit(flags.Conversation);
    data->WriteBit(flags.Room);
    data->WriteBit(flags.Decor);
    data->WriteBit(flags.MeshObject);
    data->FlushBits();

    if (flags.MovementUpdate)
    {
        Unit const* unit = static_cast<Unit const*>(this);
        bool HasFallDirection = unit->HasUnitMovementFlag(MOVEMENTFLAG_FALLING);
        bool HasFall = HasFallDirection || unit->m_movementInfo.jump.fallTime != 0;
        bool HasSpline = unit->IsSplineEnabled();
        bool HasInertia = unit->m_movementInfo.inertia.has_value();
        bool HasAdvFlying = unit->m_movementInfo.advFlying.has_value();
        bool HasDriveStatus = unit->m_movementInfo.driveStatus.has_value();
        bool HasStandingOnGameObjectGUID = unit->m_movementInfo.standingOnGameObjectGUID.has_value();

        *data << GetGUID();                                             // MoverGUID

        *data << uint32(unit->GetUnitMovementFlags());
        *data << uint32(unit->GetExtraUnitMovementFlags());
        *data << uint32(unit->GetExtraUnitMovementFlags2());

        *data << uint32(unit->m_movementInfo.time);                     // MoveTime
        *data << float(unit->GetPositionX());
        *data << float(unit->GetPositionY());
        *data << float(unit->GetPositionZ());
        *data << float(unit->GetOrientation());

        *data << float(unit->m_movementInfo.pitch);                     // Pitch
        *data << float(unit->m_movementInfo.stepUpStartElevation);      // StepUpStartElevation

        *data << uint32(0);                                             // RemoveForcesIDs.size()
        *data << uint32(0);                                             // MoveIndex

        *data << float(unit->m_movementInfo.gravityModifier);

        //for (std::size_t i = 0; i < RemoveForcesIDs.size(); ++i)
        //    *data << ObjectGuid(RemoveForcesIDs);

        data->WriteBit(HasStandingOnGameObjectGUID);                    // HasStandingOnGameObjectGUID
        data->WriteBit(!unit->m_movementInfo.transport.guid.IsEmpty()); // HasTransport
        data->WriteBit(HasFall);                                        // HasFall
        data->WriteBit(HasSpline);                                      // HasSpline - marks that the unit uses spline movement
        data->WriteBit(false);                                          // HeightChangeFailed
        data->WriteBit(false);                                          // RemoteTimeValid
        data->WriteBit(HasInertia);                                     // HasInertia
        data->WriteBit(HasAdvFlying);                                   // HasAdvFlying
        data->WriteBit(HasDriveStatus);                                 // HasDriveStatus
        data->FlushBits();

        if (!unit->m_movementInfo.transport.guid.IsEmpty())
            *data << unit->m_movementInfo.transport;

        if (HasStandingOnGameObjectGUID)
            *data << *unit->m_movementInfo.standingOnGameObjectGUID;

        if (HasInertia)
        {
            *data << unit->m_movementInfo.inertia->id;
            *data << unit->m_movementInfo.inertia->force.PositionXYZStream();
            *data << uint32(unit->m_movementInfo.inertia->lifetime);
        }

        if (HasAdvFlying)
        {
            *data << float(unit->m_movementInfo.advFlying->forwardVelocity);
            *data << float(unit->m_movementInfo.advFlying->upVelocity);
        }

        if (HasFall)
        {
            *data << uint32(unit->m_movementInfo.jump.fallTime);        // Time
            *data << float(unit->m_movementInfo.jump.zspeed);           // JumpVelocity

            if (data->WriteBit(HasFallDirection))
            {
                *data << float(unit->m_movementInfo.jump.sinAngle);     // Direction
                *data << float(unit->m_movementInfo.jump.cosAngle);
                *data << float(unit->m_movementInfo.jump.xyspeed);      // Speed
            }
        }

        if (HasDriveStatus)
        {
            *data << float(unit->m_movementInfo.driveStatus->speed);
            *data << float(unit->m_movementInfo.driveStatus->movementAngle);
            data->WriteBit(unit->m_movementInfo.driveStatus->accelerating);
            data->WriteBit(unit->m_movementInfo.driveStatus->drifting);
            data->FlushBits();
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

        if (MovementForces const* movementForces = unit->GetMovementForces())
        {
            *data << uint32(movementForces->GetForces()->size());
            *data << float(movementForces->GetModMagnitude());          // MovementForcesModMagnitude
        }
        else
        {
            *data << uint32(0);
            *data << float(1.0f);                                       // MovementForcesModMagnitude
        }

        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_AIR_FRICTION));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_MAX_VEL));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_LIFT_COEFFICIENT));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_DOUBLE_JUMP_VEL_MOD));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_GLIDE_START_MIN_HEIGHT));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_ADD_IMPULSE_MAX_SPEED));
        *data << float(unit->GetAdvFlyingSpeedMin(ADV_FLYING_BANKING_RATE));
        *data << float(unit->GetAdvFlyingSpeedMax(ADV_FLYING_BANKING_RATE));
        *data << float(unit->GetAdvFlyingSpeedMin(ADV_FLYING_PITCHING_RATE_DOWN));
        *data << float(unit->GetAdvFlyingSpeedMax(ADV_FLYING_PITCHING_RATE_DOWN));
        *data << float(unit->GetAdvFlyingSpeedMin(ADV_FLYING_PITCHING_RATE_UP));
        *data << float(unit->GetAdvFlyingSpeedMax(ADV_FLYING_PITCHING_RATE_UP));
        *data << float(unit->GetAdvFlyingSpeedMin(ADV_FLYING_TURN_VELOCITY_THRESHOLD));
        *data << float(unit->GetAdvFlyingSpeedMax(ADV_FLYING_TURN_VELOCITY_THRESHOLD));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_SURFACE_FRICTION));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_OVER_MAX_DECELERATION));
        *data << float(unit->GetAdvFlyingSpeed(ADV_FLYING_LAUNCH_SPEED_COEFFICIENT));

        data->WriteBit(HasSpline);
        data->FlushBits();

        if (MovementForces const* movementForces = unit->GetMovementForces())
            for (MovementForce const& force : *movementForces->GetForces())
                WorldPackets::Movement::CommonMovement::WriteMovementForceWithDirection(force, *data, unit);

        if (HasSpline)
            WorldPackets::Movement::CommonMovement::WriteCreateObjectSplineDataBlock(*unit->movespline, *data);
    }

    *data << uint32(PauseTimes.size());

    if (flags.Stationary)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << self->GetStationaryPosition().PositionXYZOStream();
    }

    if (flags.CombatVictim)
    {
        Unit const* unit = static_cast<Unit const*>(this);
        *data << unit->GetVictim()->GetGUID();                          // CombatVictim
    }

    if (flags.ServerTime)
        *data << uint32(GameTime::GetGameTimeMS());

    if (flags.Vehicle)
    {
        Unit const* unit = static_cast<Unit const*>(this);
        *data << uint32(unit->GetVehicleKit()->GetVehicleInfo()->ID);   // RecID
        *data << float(unit->GetOrientation());                         // InitialRawFacing
    }

    if (flags.AnimKit)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << uint16(self->GetAIAnimKitId());                        // AiID
        *data << uint16(self->GetMovementAnimKitId());                  // MovementID
        *data << uint16(self->GetMeleeAnimKitId());                     // MeleeID
    }

    if (flags.Rotation)
    {
        GameObject const* gameObject = static_cast<GameObject const*>(this);
        *data << uint64(gameObject->GetPackedLocalRotation());          // Rotation
    }

    //if (flags.Room)
    //    *data << ObjectGuid(HouseGUID);

    //if (flags.Decor)
    //    *data << ObjectGuid(RoomGUID);

    //if (flags.MeshObject)
    //{
    //    *data << ObjectGuid(AttachParentGUID);
    //    *data << TaggedPosition<Position::XYZ>(PositionLocalSpace);
    //    *data << QuaternionData(RotationLocalSpace);
    //    *data << float(ScaleLocalSpace);
    //    *data << uint8(AttachmentFlags);
    //}

    if (!PauseTimes.empty())
        data->append(PauseTimes.data(), PauseTimes.size());

    if (flags.MovementTransport)
    {
        WorldObject const* self = static_cast<WorldObject const*>(this);
        *data << self->m_movementInfo.transport;
    }

    if (flags.GameObject)
    {
        GameObject const* gameObject = static_cast<GameObject const*>(this);

        bool bit8 = false;
        bool isTransport = gameObject->GetGOInfo()->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT;

        *data << uint32(gameObject->GetWorldEffectID());

        data->WriteBit(bit8);
        data->WriteBit(isTransport);
        data->WriteBit(gameObject->GetPathProgressForClient().has_value());
        data->FlushBits();
        if (isTransport)
        {
            Transport const* transport = static_cast<Transport const*>(gameObject);
            uint32 period = transport->GetTransportPeriod();

            *data << uint32((((int64(transport->GetTimer()) - int64(GameTime::GetGameTimeMS())) % period) + period) % period);  // TimeOffset
            *data << uint32(transport->GetNextStopTimestamp().value_or(0));
            data->WriteBit(transport->GetNextStopTimestamp().has_value());
            data->WriteBit(transport->IsStopped());
            data->WriteBit(false);
            data->FlushBits();
        }

        if (bit8)
            *data << uint32(0);

        if (gameObject->GetPathProgressForClient())
            *data << float(*gameObject->GetPathProgressForClient());
    }

    if (flags.SmoothPhasing)
    {
        SmoothPhasingInfo const* smoothPhasingInfo = static_cast<WorldObject const*>(this)->GetSmoothPhasing()->GetInfoForSeer(target->GetGUID());
        ASSERT(smoothPhasingInfo);

        data->WriteBit(smoothPhasingInfo->ReplaceActive);
        data->WriteBit(smoothPhasingInfo->StopAnimKits);
        data->WriteBit(smoothPhasingInfo->ReplaceObject.has_value());
        data->FlushBits();
        if (smoothPhasingInfo->ReplaceObject)
            *data << *smoothPhasingInfo->ReplaceObject;
    }

    if (flags.SceneObject)
    {
        data->WriteBit(false);                                          // HasLocalScriptData
        data->WriteBit(false);                                          // HasPetBattleFullUpdate
        data->FlushBits();

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
    //                *data << int32(Players[i].Pets[j].CreatureID);
    //                *data << int32(Players[i].Pets[j].DisplayID);
    //                *data << int16(Players[i].Pets[j].Level);
    //                *data << int16(Players[i].Pets[j].Xp);
    //                *data << int32(Players[i].Pets[j].CurHealth);
    //                *data << int32(Players[i].Pets[j].MaxHealth);
    //                *data << int32(Players[i].Pets[j].Power);
    //                *data << int32(Players[i].Pets[j].Speed);
    //                *data << int32(Players[i].Pets[j].NpcTeamMemberID);
    //                *data << uint8(Players[i].Pets[j].BreedQuality);
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
    }

    if (flags.ActivePlayer)
    {
        Player const* player = static_cast<Player const*>(this);

        bool HasSceneInstanceIDs = !player->GetSceneMgr().GetSceneTemplateByInstanceMap().empty();
        bool HasRuneState = player->GetPowerIndex(POWER_RUNES) != MAX_POWERS;

        data->WriteBit(HasSceneInstanceIDs);
        data->WriteBit(HasRuneState);
        data->FlushBits();
        if (HasSceneInstanceIDs)
        {
            *data << uint32(player->GetSceneMgr().GetSceneTemplateByInstanceMap().size());
            for (auto const& [sceneInstanceId, _] : player->GetSceneMgr().GetSceneTemplateByInstanceMap())
                *data << uint32(sceneInstanceId);
        }
        if (HasRuneState)
        {
            float baseCd = float(player->GetRuneBaseCooldown());
            uint32 maxRunes = uint32(player->GetMaxPower(POWER_RUNES));

            *data << uint8((1 << maxRunes) - 1);
            *data << uint8(player->GetRunesState());
            *data << uint32(maxRunes);
            for (uint32 i = 0; i < maxRunes; ++i)
                *data << uint8((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255);
        }
    }

    if (flags.Conversation)
    {
        Conversation const* self = static_cast<Conversation const*>(this);
        if (data->WriteBit(self->GetTextureKitId() != 0))
            *data << uint32(self->GetTextureKitId());

        data->FlushBits();
    }
}

UF::UpdateFieldFlag BaseEntity::GetUpdateFieldFlagsFor(Player const* /*target*/) const
{
    return UF::UpdateFieldFlag::None;
}

void BaseEntity::AddToObjectUpdateIfNeeded()
{
    if (m_inWorld && !m_objectUpdated)
        m_objectUpdated = AddToObjectUpdate();
}

void BaseEntity::ClearUpdateMask(bool remove)
{
    m_entityFragments.IdsChanged = false;

    if (m_objectUpdated)
    {
        if (remove)
            RemoveFromObjectUpdate();
        m_objectUpdated = false;
    }
}

void BaseEntity::BuildUpdateChangesMask()
{
    for (std::size_t i = 0; i < m_entityFragments.UpdateableCount; ++i)
    {
        if (m_entityFragments.Updateable.IsChanged[i](this))
            m_entityFragments.ContentsChangedMask |= m_entityFragments.Updateable.Masks[i];
        else
            m_entityFragments.ContentsChangedMask &= ~m_entityFragments.Updateable.Masks[i];
    }
}

void BaseEntity::BuildFieldsUpdate(Player* player, UpdateDataMapType& data_map) const
{
    UpdateDataMapType::iterator iter = data_map.emplace(player, player->GetMapId()).first;
    BuildValuesUpdateBlockForPlayer(&iter->second, iter->first);
}

std::string BaseEntity::GetDebugInfo() const
{
    return Trinity::StringFormat("{}", GetGUID());
}
