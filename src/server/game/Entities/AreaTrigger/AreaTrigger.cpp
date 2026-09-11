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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerDataStore.h"
#include "AreaTriggerPackets.h"
#include "CellImpl.h"
#include "Chat.h"
#include "Containers.h"
#include "CreatureAISelector.h"
#include "DB2Stores.h"
#include "G3DPosition.hpp"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Language.h"
#include "Log.h"
#include "MapUtils.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RestMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Spline.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"
#include "ZoneScript.h"
#include "advstd.h"
#include <G3D/AABox.h>
#include <G3D/Box.h>
#include <G3D/CollisionDetection.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Cylinder.h>
#include <G3D/Quat.h>
#include <bit>

enum class MovementUpdateResult
{
    None,
    Moved,
    Arrived
};

struct AreaTrigger::MovementUpdateWorldResult
{
    MovementUpdateResult Status;
    ::Position Position;
    G3D::Quat Rotation;
};

struct AreaTrigger::MovementUpdateLocalResult
{
    MovementUpdateResult Status;
    G3D::Vector3 Position;
    G3D::Vector3 Rotation;
};

AreaTrigger::AreaTrigger() : WorldObject(false), MapObject(), _spawnId(0), _aurEff(nullptr),
    _duration(0), _totalDuration(0), _verticesUpdatePreviousRotation(),
    _isRemoved(false), _reachedDestination(true),
    _areaTriggerCreateProperties(nullptr), _areaTriggerTemplate(nullptr)
{
    m_objectTypeId = TYPEID_AREATRIGGER;

    m_updateFlag.Stationary = true;

    m_entityFragments.Add(WowCS::EntityFragment::Tag_AreaTrigger, false);
}

AreaTrigger::~AreaTrigger()
{
}

void AreaTrigger::AddToWorld()
{
    ///- Register the AreaTrigger for guid lookup and for caster
    if (!IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnAreaTriggerCreate(this);

        GetMap()->GetObjectsStore().Insert<AreaTrigger>(this);
        if (_spawnId)
            GetMap()->GetAreaTriggerBySpawnIdStore().insert(std::make_pair(_spawnId, this));

        WorldObject::AddToWorld();
    }
}

void AreaTrigger::RemoveFromWorld()
{
    ///- Remove the AreaTrigger from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnAreaTriggerRemove(this);

        _isRemoved = true;

        if (Unit* caster = GetCaster())
            caster->_UnregisterAreaTrigger(this);

        _ai->OnRemove();

        // Handle removal of all units, calling OnUnitExit & deleting auras if needed
        HandleUnitEnterExit({}, AreaTriggerExitReason::ByExpire);

        WorldObject::RemoveFromWorld();

        if (IsStaticSpawn())
            Trinity::Containers::MultimapErasePair(GetMap()->GetAreaTriggerBySpawnIdStore(), _spawnId, this);
        GetMap()->GetObjectsStore().Remove<AreaTrigger>(this);
    }
}

void AreaTrigger::PlaySpellVisual(uint32 spellVisualId) const
{
    WorldPackets::AreaTrigger::AreaTriggerPlaySpellVisual packet;
    packet.AreaTriggerGUID = GetGUID();
    packet.SpellVisualID = spellVisualId;
    SendMessageToSet(packet.Write(), false);
}

bool AreaTrigger::Create(AreaTriggerCreatePropertiesId areaTriggerCreatePropertiesId, Map* map, Position const& pos, int32 duration, AreaTriggerSpawn const* spawnData /*= nullptr*/, Unit* caster /*= nullptr*/, Unit* target /*= nullptr*/, SpellCastVisual spellVisual /*= { 0, 0 }*/, SpellInfo const* spellInfo /*= nullptr*/, Spell* spell /*= nullptr*/, AuraEffect const* aurEff /*= nullptr*/)
{
    _targetGuid = target ? target->GetGUID() : ObjectGuid::Empty;
    _aurEff = aurEff;

    SetMap(map);
    Relocate(pos);
    RelocateStationaryPosition(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})) not created. Invalid coordinates (X: {} Y: {})", areaTriggerCreatePropertiesId.Id, uint32(areaTriggerCreatePropertiesId.IsCustom), GetPositionX(), GetPositionY());
        return false;
    }

    _areaTriggerCreateProperties = sAreaTriggerDataStore->GetAreaTriggerCreateProperties(areaTriggerCreatePropertiesId);
    if (!_areaTriggerCreateProperties)
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})) not created. Invalid areatrigger create properties id", areaTriggerCreatePropertiesId.Id, uint32(areaTriggerCreatePropertiesId.IsCustom));
        return false;
    }

    SetZoneScript();

    _areaTriggerTemplate = _areaTriggerCreateProperties->Template;

    _Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), GetTemplate() ? GetTemplate()->Id.Id : 0, GetMap()->GenerateLowGuid<HighGuid::AreaTrigger>()));

    if (GetTemplate())
        SetEntry(GetTemplate()->Id.Id);

    SetObjectScale(1.0f);
    SetDuration(duration);

    SetShape(GetCreateProperties()->Shape);

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    if (caster)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::Caster), caster->GetGUID());
    if (spell)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::CreatingEffectGUID), spell->m_castId);
    if (spellInfo && !IsStaticSpawn())
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellID), spellInfo->Id);

    SpellInfo const* spellForVisuals = spellInfo;
    if (GetCreateProperties()->SpellForVisuals)
    {
        spellForVisuals = sSpellMgr->GetSpellInfo(*GetCreateProperties()->SpellForVisuals, DIFFICULTY_NONE);

        if (spellForVisuals)
            spellVisual.SpellXSpellVisualID = caster ? caster->GetCastSpellXSpellVisualId(spellForVisuals) : spellForVisuals->GetSpellXSpellVisualId();
    }
    if (spellForVisuals)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellForVisuals), spellForVisuals->Id);

    SetSpellVisual(spellVisual);
    if (!IsStaticSpawn())
    {
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), GetCreateProperties()->TimeToTargetScale != 0 ? GetCreateProperties()->TimeToTargetScale : *m_areaTriggerData->Duration);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetPos), *m_areaTriggerData->Duration);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetShape), *m_areaTriggerData->Duration);
    }
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::BoundsRadius2D), GetCreateProperties()->Shape.GetMaxSearchRadius());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), GetCreateProperties()->DecalPropertiesId);
    if (IsServerSide())
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), 24); // Blue decal, for .debug areatrigger visibility

    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), 1.0f);

    if (caster && spellInfo)
    {
        if (Player const* modOwner = caster->GetSpellModOwner())
        {
            float multiplier = 1.0f;
            int32 flat = 0;
            modOwner->GetSpellModValues(spellInfo, SpellModOp::Radius, spell, *m_areaTriggerData->BoundsRadius2D, &flat, &multiplier);
            if (multiplier != 1.0f)
            {
                OverrideCurveData overrideScale;
                overrideScale.Curve = multiplier;
                SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), overrideScale);
            }
        }
    }

    auto visualAnim = areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim);
    if (GetCreateProperties()->AnimId != -1)
        SetUpdateFieldValue(visualAnim.ModifyValue(&UF::VisualAnim::AnimationDataID, 0), GetCreateProperties()->AnimId);
    SetUpdateFieldValue(visualAnim.ModifyValue(&UF::VisualAnim::AnimKitID), GetCreateProperties()->AnimKitId);
    if (GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::VisualAnimIsDecay))
        SetUpdateFieldValue(visualAnim.ModifyValue(&UF::VisualAnim::IsDecay), true);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PositionalSoundKitID), GetCreateProperties()->PositionalSoundKitId);

    AreaTriggerFieldFlags fieldFlags = [flags = GetCreateProperties()->Flags]()
    {
        AreaTriggerFieldFlags fieldFlags = AreaTriggerFieldFlags::None;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::AbsoluteOrientation))
            fieldFlags |= AreaTriggerFieldFlags::AbsoluteOrientation;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::FaceMovementDir))
            fieldFlags |= AreaTriggerFieldFlags::FaceMovementDir;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::FollowsTerrain))
            fieldFlags |= AreaTriggerFieldFlags::FollowsTerrain;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::AlwaysExterior))
            fieldFlags |= AreaTriggerFieldFlags::AlwaysExterior;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::UsesUnitRawFacing))
            fieldFlags |= AreaTriggerFieldFlags::UsesUnitRawFacing;
        return fieldFlags;
    }();
    ReplaceAllAreaTriggerFlags(fieldFlags);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MovementStartTime), GameTime::GetGameTimeMS());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::CreationTime), GameTime::GetGameTimeMS());

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ScaleCurveId), GetCreateProperties()->ScaleCurveId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::FacingCurveId), GetCreateProperties()->FacingCurveId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MorphCurveId), GetCreateProperties()->MorphCurveId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MoveCurveId), GetCreateProperties()->MoveCurveId);

    if (caster)
        PhasingHandler::InheritPhaseShift(this, caster);
    else if (IsStaticSpawn() && spawnData)
    {
        if (spawnData->phaseUseFlags || spawnData->phaseId || spawnData->phaseGroup)
            PhasingHandler::InitDbPhaseShift(GetPhaseShift(), spawnData->phaseUseFlags, spawnData->phaseId, spawnData->phaseGroup);
    }

    if (target && aurEff)
    {
        SetAreaTriggerFlag(AreaTriggerFieldFlags::Attached);
        m_movementInfo.transport.guid = target->GetGUID();
        m_updateFlag.MovementTransport = true;
    }

    // movement on transport of areatriggers on unit is handled by themself
    TransportBase* transport = nullptr;
    if (caster)
    {
        transport = m_movementInfo.transport.guid.IsEmpty() ? caster->GetTransport() : nullptr;
        if (transport)
        {
            // This object must be added to transport before adding to map for the client to properly display it
            transport->AddPassenger(this, transport->GetPositionOffsetTo(pos));
        }
    }

    if (!IsStaticSpawn())
        UpdatePositionData();

    std::visit([&]<typename MovementType>(MovementType const& movement)
    {
        if constexpr (std::is_same_v<MovementType, AreaTriggerOrbitInfo>)
        {
            AreaTriggerOrbitInfo orbit = movement;
            if (target && HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached))
                orbit.PathTarget = target->GetGUID();
            else
                orbit.Center = pos;

            this->InitOrbit(orbit);
        }
        else if constexpr (std::is_same_v<MovementType, AreaTriggerCreateProperties::SplineInfo>)
            this->InitSplineOffsets(movement);
        else if constexpr (std::is_same_v<MovementType, std::monostate>)
            this->SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::Stationary));
        else
            static_assert(Trinity::dependant_false_v<MovementType>, "Unsupported movement type");
    }, GetCreateProperties()->Movement);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::Facing), _stationaryPosition.GetOrientation());

    SetRollPitchYaw(GetCreateProperties()->RollPitchYaw, GetCreateProperties()->TargetRollPitchYaw);

    AI_Initialize();

    UpdateDynamicShapeFlag();

    // Calculate initial position and rotation
    {
        auto [_, movedPos, movedRot] = CalculateWorldPositionAndRotation();
        Relocate(movedPos);
        _rotation = { movedRot.x, movedRot.y, movedRot.z, movedRot.w };
    }

    UpdateShape();

    if (!IsStaticSpawn())
    {
        if (!GetMap()->AddToMap(this))
        {
            // Returning false will cause the object to be deleted - remove from transport
            if (transport)
                transport->RemovePassenger(this);
            return false;
        }
    }

    if (caster)
        caster->_RegisterAreaTrigger(this);

    _ai->OnCreate(spell);

    return true;
}

AreaTrigger* AreaTrigger::CreateAreaTrigger(AreaTriggerCreatePropertiesId areaTriggerCreatePropertiesId, Position const& pos, int32 duration, Unit * caster, Unit * target, SpellCastVisual spellVisual /*= { 0, 0 }*/, SpellInfo const* spellInfo /*= nullptr*/, Spell* spell /*= nullptr*/, AuraEffect const* aurEff /*= nullptr*/)
{
    AreaTrigger* at = new AreaTrigger();
    if (!at->Create(areaTriggerCreatePropertiesId, caster->GetMap(), pos, duration, nullptr, caster, target, spellVisual, spellInfo, spell, aurEff))
    {
        delete at;
        return nullptr;
    }

    return at;
}

ObjectGuid AreaTrigger::CreateNewMovementForceId(Map* map, uint32 areaTriggerId)
{
    return ObjectGuid::Create<HighGuid::AreaTrigger>(map->GetId(), areaTriggerId, map->GenerateLowGuid<HighGuid::AreaTrigger>());
}

bool AreaTrigger::LoadFromDB(ObjectGuid::LowType spawnId, Map* map, bool /*addToMap*/, bool /*allowDuplicate*/)
{
    _spawnId = spawnId;

    AreaTriggerSpawn const* spawnData = sAreaTriggerDataStore->GetAreaTriggerSpawn(spawnId);
    if (!spawnData)
        return false;

    AreaTriggerCreateProperties const* createProperties = sAreaTriggerDataStore->GetAreaTriggerCreateProperties(spawnData->Id);
    if (!createProperties)
        return false;

    return Create(spawnData->Id, map, spawnData->spawnPoint, -1, spawnData);
}

void AreaTrigger::Update(uint32 diff)
{
    WorldObject::Update(diff);

    if (!IsStaticSpawn())
        UpdatePositionAndRotation();

    if (GetDuration() != -1)
    {
        if (GetDuration() > int32(diff))
            _UpdateDuration(_duration - diff);
        else
        {
            Remove(); // expired
            return;
        }
    }

    _ai->OnUpdate(diff);

    UpdateTargetList();
}

void AreaTrigger::Remove()
{
    if (IsInWorld())
    {
        AddObjectToRemoveList(); // calls RemoveFromWorld
    }
}

uint32 AreaTrigger::GetTimeSinceCreated() const
{
    uint32 now = GameTime::GetGameTimeMS();
    if (now >= *m_areaTriggerData->CreationTime)
        return now - *m_areaTriggerData->CreationTime;
    return 0;
}

void AreaTrigger::SetOverrideScaleCurve(float overrideScale)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), overrideScale);
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetOverrideScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), points, startTimeOffset, interpolation);
    SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
}

void AreaTrigger::ClearOverrideScaleCurve()
{
    ClearOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve));
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetExtraScaleCurve(float extraScale)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), extraScale);
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetExtraScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), points, startTimeOffset, interpolation);
    SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
}

void AreaTrigger::ClearExtraScaleCurve()
{
    ClearOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve));
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetOverrideMoveCurve(float x, float y, float z)
{
    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX), x);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY), y);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ), z);
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetOverrideMoveCurve(std::array<DBCPosition2D, 2> const& xCurvePoints, std::array<DBCPosition2D, 2> const& yCurvePoints,
    std::array<DBCPosition2D, 2> const& zCurvePoints, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX), xCurvePoints, startTimeOffset, interpolation);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY), yCurvePoints, startTimeOffset, interpolation);
    SetOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ), zCurvePoints, startTimeOffset, interpolation);
    SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
}

void AreaTrigger::ClearOverrideMoveCurve()
{
    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    ClearOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX));
    ClearOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY));
    ClearOverrideCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ));
    UpdateDynamicShapeFlag();
}

void AreaTrigger::SetOverrideShapeCurve(float overrideShape)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideShapeCurve), overrideShape);
}

void AreaTrigger::SetOverrideShapeCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideShapeCurve), points, startTimeOffset, interpolation);
}

void AreaTrigger::ClearOverrideShapeCurve()
{
    ClearOverrideCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideShapeCurve));
}

void AreaTrigger::SetSpellVisual(SpellCastVisual const& visual)
{
    auto spellVisualMutator = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::SpellVisual);

    SetUpdateFieldValue(spellVisualMutator.ModifyValue(&UF::SpellCastVisual::SpellXSpellVisualID), visual.SpellXSpellVisualID);
    SetUpdateFieldValue(spellVisualMutator.ModifyValue(&UF::SpellCastVisual::ScriptVisualID), visual.ScriptVisualID);
}

void AreaTrigger::SetRollPitchYaw(float roll, float pitch, float yaw,
    Optional<float> targetRoll, Optional<float> targetPitch, Optional<float> targetYaw)
{
    TaggedPosition<Position::XYZ> rollPitchYaw = { roll, pitch, yaw };
    Optional<TaggedPosition<Position::XYZ>> targetRollPitchYaw;

    if (targetRoll && targetPitch && targetYaw)
        targetRollPitchYaw.emplace(*targetRoll, *targetPitch, *targetYaw);

    SetRollPitchYaw(rollPitchYaw, targetRollPitchYaw);
}

void AreaTrigger::SetRollPitchYaw(TaggedPosition<Position::XYZ> const& rollPitchYaw, Optional<TaggedPosition<Position::XYZ>> const& targetRollPitchYaw)
{
    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::RollPitchYaw), rollPitchYaw);
    if (targetRollPitchYaw)
    {
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TargetRollPitchYaw, 0), *targetRollPitchYaw);
        SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
    }
    else
    {
        RemoveOptionalUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TargetRollPitchYaw));
        UpdateDynamicShapeFlag();
    }
}

void AreaTrigger::SetDuration(int32 newDuration)
{
    _duration = newDuration;
    _totalDuration = newDuration;

    // negative duration (permanent areatrigger) sent as 0
    SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::Duration), std::max(newDuration, 0));
}

void AreaTrigger::_UpdateDuration(int32 newDuration)
{
    _duration = newDuration;

    // should be sent in object create packets only
    DoWithSuppressingObjectUpdates([&]()
    {
        SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::Duration), _duration);
        const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::Duration);
    });
}

float AreaTrigger::CalcCurrentScale() const
{
    float scale = 1.0f;
    if (m_areaTriggerData->OverrideScaleCurve->OverrideActive)
        scale *= std::max(GetOverrideCurveValue(*m_areaTriggerData->OverrideScaleCurve, m_areaTriggerData->TimeToTargetScale), 0.000001f);
    else if (m_areaTriggerData->ScaleCurveId)
        scale *= std::max(sDB2Manager.GetCurveValueAt(m_areaTriggerData->ScaleCurveId, GetScaleProgress()), 0.000001f);

    scale *= std::max(GetOverrideCurveValue(*m_areaTriggerData->ExtraScaleCurve, m_areaTriggerData->TimeToTargetExtraScale), 0.000001f);

    return scale;
}

float AreaTrigger::GetOverrideCurveProgress(UF::OverrideCurve const& overrideCurve, uint32 timeTo) const
{
    if (!timeTo)
        return 0.0f;

    return std::clamp(float(GetTimeSinceCreated() - overrideCurve.StartTimeOffset) / float(timeTo), 0.0f, 1.0f);
}

float AreaTrigger::GetOverrideCurveValueAtProgress(UF::OverrideCurve const& overrideCurve, float x) const
{
    ASSERT(*overrideCurve.OverrideActive, "OverrideCurve must be active to evaluate it");

    // unpack ParameterCurve
    if (*overrideCurve.ParameterCurve & 1u)
        return advstd::bit_cast<float>(*overrideCurve.ParameterCurve & ~1u);

    std::array<DBCPosition2D, 2> points;
    for (std::size_t i = 0; i < overrideCurve.Points.size(); ++i)
        points[i] = { .X = overrideCurve.Points[i].Pos.GetPositionX(), .Y = overrideCurve.Points[i].Pos.GetPositionY() };

    CurveInterpolationMode mode = CurveInterpolationMode(*overrideCurve.ParameterCurve >> 1 & 0xF);
    std::size_t pointCount = *overrideCurve.ParameterCurve >> 24 & 0xFF;

    return sDB2Manager.GetCurveValueAt(mode, std::span(points.begin(), pointCount), x);
}

float AreaTrigger::GetOverrideCurveValue(UF::OverrideCurve const& overrideCurve, uint32 timeTo) const
{
    return GetOverrideCurveValueAtProgress(overrideCurve, GetOverrideCurveProgress(overrideCurve, timeTo));
}

void AreaTrigger::SetOverrideCurve(UF::MutableFieldReference<UF::OverrideCurve, false> overrideCurveMutator, float constantValue)
{
    OverrideCurveData curveTemplate;
    curveTemplate.Curve = constantValue;
    SetOverrideCurve(overrideCurveMutator, curveTemplate);
}

void AreaTrigger::SetOverrideCurve(UF::MutableFieldReference<UF::OverrideCurve, false> overrideCurveMutator, std::array<DBCPosition2D, 2> const& points,
    Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    OverrideCurveData curveTemplate;
    curveTemplate.StartTimeOffset = startTimeOffset.value_or(GetTimeSinceCreated());
    curveTemplate.Mode = interpolation;
    curveTemplate.Curve = points;

    SetOverrideCurve(overrideCurveMutator, curveTemplate);
}

void AreaTrigger::ClearOverrideCurve(UF::MutableFieldReference<UF::OverrideCurve, false> overrideCurveMutator)
{
    SetOverrideCurve(overrideCurveMutator, {});
}

void AreaTrigger::SetOverrideCurve(UF::MutableFieldReference<UF::OverrideCurve, false> overrideCurveMutator, Optional<OverrideCurveData> const& curve)
{
    if (!curve)
    {
        SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::OverrideActive), false);
        return;
    }

    SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::OverrideActive), true);
    SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::StartTimeOffset), curve->StartTimeOffset);

    TaggedPosition<Position::XY> point;
    // ParameterCurve packing information
    // (not_using_points & 1) | ((interpolation_mode & 0xF) << 1) | ((first_point_offset & 0x7FFFF) << 5) | ((point_count & 0xFF) << 24)
    //   if not_using_points is set then the entire field is simply read as a float (ignoring that lowest bit)

    if (float const* simpleFloat = std::get_if<float>(&curve->Curve))
    {
        uint32 packedCurve = advstd::bit_cast<uint32>(*simpleFloat);
        packedCurve |= 1;

        SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::ParameterCurve), packedCurve);

        // clear points
        for (std::size_t i = 0; i < UF::size<decltype(UF::OverrideCurve::Points)>(); ++i)
            SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::Points, i), point);
    }
    else if (OverrideCurveData::Points const* curvePoints = std::get_if<OverrideCurveData::Points>(&curve->Curve))
    {
        CurveInterpolationMode mode = curve->Mode;
        if ((*curvePoints)[1].X < (*curvePoints)[0].X)
            mode = CurveInterpolationMode::Constant;

        switch (mode)
        {
            case CurveInterpolationMode::CatmullRom:
                // catmullrom requires at least 4 points, impossible here
                mode = CurveInterpolationMode::Cosine;
                break;
            case CurveInterpolationMode::Bezier3:
            case CurveInterpolationMode::Bezier4:
            case CurveInterpolationMode::Bezier:
                // bezier requires more than 2 points, impossible here
                mode = CurveInterpolationMode::Linear;
                break;
            default:
                break;
        }

        uint32 pointCount = 2;
        if (mode == CurveInterpolationMode::Constant)
            pointCount = 1;

        uint32 packedCurve = (uint32(mode) << 1) | (pointCount << 24);
        SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::ParameterCurve), packedCurve);

        for (std::size_t i = 0; i < curvePoints->size(); ++i)
        {
            point.Pos.Relocate((*curvePoints)[i].X, (*curvePoints)[i].Y);
            SetUpdateFieldValue(overrideCurveMutator.ModifyValue(&UF::OverrideCurve::Points, i), point);
        }
    }
}

void AreaTrigger::UpdateTargetList()
{
    std::vector<Unit*> targetList;

    m_areaTriggerData->ShapeData.Visit([&]<typename ShapeType>(ShapeType const& shape)
    {
        if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerSphere>)
            this->SearchUnitInSphere(shape, targetList);
        else if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerBox>)
            this->SearchUnitInBox(shape, targetList);
        else if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerPolygon>)
            this->SearchUnitInPolygon(shape, targetList);
        else if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerCylinder>)
            this->SearchUnitInCylinder(shape, targetList);
        else if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerDisk>)
            this->SearchUnitInDisk(shape, targetList);
        else if constexpr (std::is_same_v<ShapeType, UF::AreaTriggerBoundedPlane>)
            this->SearchUnitInBoundedPlane(shape, targetList);
    });

    if (GetTemplate())
    {
        ConditionContainer const* conditions = sConditionMgr->GetConditionsForAreaTrigger(GetTemplate()->Id.Id, GetTemplate()->Id.IsCustom);
        Trinity::Containers::EraseIf(targetList, [this, conditions](Unit const* target)
        {
            if (GetCasterGuid() == target->GetGUID())
            {
                if (HasActionSetFlag(AreaTriggerActionSetFlag::NotTriggeredbyCaster))
                    return true;
            }
            else
            {
                if (HasActionSetFlag(AreaTriggerActionSetFlag::OnlyTriggeredByCaster))
                    return true;

                if (HasActionSetFlag(AreaTriggerActionSetFlag::CreatorsPartyOnly))
                {
                    Unit* caster = GetCaster();
                    if (!caster)
                        return true;

                    if (!caster->IsInRaidWith(target))
                        return true;
                }
            }

            if (Player const* player = target->ToPlayer())
            {
                switch (player->getDeathState())
                {
                    case DEAD:
                        if (!HasActionSetFlag(AreaTriggerActionSetFlag::AllowWhileGhost))
                            return true;
                        break;
                    case CORPSE:
                        if (!HasActionSetFlag(AreaTriggerActionSetFlag::AllowWhileDead))
                            return true;
                        break;
                    default:
                        break;
                }
            }

            if (!HasActionSetFlag(AreaTriggerActionSetFlag::CanAffectUninteractible) && target->IsUninteractible())
                return true;

            if (conditions)
                return !sConditionMgr->IsObjectMeetToConditions(target, *conditions);

            return false;
        });
    }

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnits(std::vector<Unit*>& targetList, float radius, bool check3D)
{
    Trinity::AnyUnitInObjectRangeCheck check(this, radius, check3D, false);
    if (IsStaticSpawn())
    {
        Trinity::PlayerListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
        Cell::VisitWorldObjects(this, searcher, GetMaxSearchRadius());
    }
    else
    {
        Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
        Cell::VisitAllObjects(this, searcher, GetMaxSearchRadius());
    }
}

void AreaTrigger::SearchUnitInSphere(UF::AreaTriggerSphere const& sphere, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(sphere.Radius, sphere.RadiusTarget, progress) * scale;

    SearchUnits(targetList, radius, true);

    Trinity::Containers::EraseIf(targetList, [this, radius](Unit const* unit) -> bool
    {
        return !unit->IsWithinDist(this, radius);
    });
}

void AreaTrigger::SearchUnitInBox(UF::AreaTriggerBox const& box, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsX = G3D::lerp(box.Extents->Pos.GetPositionX(), box.ExtentsTarget->Pos.GetPositionX(), progress) * scale;
    float extentsY = G3D::lerp(box.Extents->Pos.GetPositionY(), box.ExtentsTarget->Pos.GetPositionY(), progress) * scale;
    float extentsZ = G3D::lerp(box.Extents->Pos.GetPositionZ(), box.ExtentsTarget->Pos.GetPositionZ(), progress) * scale;
    float radius = std::sqrt(extentsX * extentsX + extentsY * extentsY + extentsZ * extentsZ);

    SearchUnits(targetList, radius, false);

    if (targetList.empty())
        return;

    G3D::Box rotatedBox = G3D::CoordinateFrame(G3D::Quat(_rotation.x, _rotation.y, _rotation.z, _rotation.w), PositionToVector3(GetPosition()))
        .toWorldSpace(G3D::AABox({ -extentsX, -extentsY, -extentsZ / 2 }, { extentsX, extentsY, extentsZ / 2 }));

    Trinity::Containers::EraseIf(targetList, [&rotatedBox](Unit const* unit) -> bool
    {
        return !rotatedBox.contains(PositionToVector3(*unit));
    });

#ifdef TRINITY_DEBUG
    // DebugVisualizeShape
    if (Player* caster = Object::ToPlayer(GetCaster()); caster && caster->isDebugAreaTriggers)
        for (int32 corner = 0; corner < 8; ++corner)
            caster->SummonCreature(1, Vector3ToPosition(rotatedBox.corner(corner)), TEMPSUMMON_TIMED_DESPAWN, 50ms);
#endif
}

void AreaTrigger::SearchUnitInPolygon(UF::AreaTriggerPolygon const& polygon, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float height = G3D::lerp(polygon.Height, polygon.HeightTarget, progress);
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, GetMaxSearchRadius(), false);

    if (targetList.empty())
        return;

    Trinity::Containers::EraseIf(targetList, [this, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ
            || !unit->IsInPolygon2D(*this, _polygonVertices);
    });

#ifdef TRINITY_DEBUG
    // DebugVisualizeShape
    if (Player* caster = Object::ToPlayer(GetCaster()); caster && caster->isDebugAreaTriggers)
    {
        for (Position const& vertex : _polygonVertices)
        {
            G3D::Vector3 pos = PositionToVector3(GetPosition()) + PositionToVector3(vertex);
            caster->SummonCreature(1, Vector3ToPosition(pos + G3D::Vector3(0, 0, -height)), TEMPSUMMON_TIMED_DESPAWN, 50ms);
            caster->SummonCreature(1, Vector3ToPosition(pos + G3D::Vector3(0, 0, +height)), TEMPSUMMON_TIMED_DESPAWN, 50ms);
        }
    }
#endif
}

void AreaTrigger::SearchUnitInCylinder(UF::AreaTriggerCylinder const& cylinder, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(cylinder.Radius, cylinder.RadiusTarget, progress) * scale;
    float height = G3D::lerp(cylinder.Height, cylinder.HeightTarget, progress);
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::HeightIgnoresScale))
        height *= scale;

    float zOffset = G3D::lerp(cylinder.LocationZOffset, cylinder.LocationZOffsetTarget, progress) * scale;

    SearchUnits(targetList, std::sqrt(radius * radius + height * height), false);

    if (targetList.empty())
        return;

    G3D::Cylinder rotatedCylinder = G3D::CoordinateFrame(G3D::Quat(_rotation.x, _rotation.y, _rotation.z, _rotation.w), PositionToVector3(GetPosition()))
        .toWorldSpace(G3D::Cylinder(
            { 0.0f, 0.0f, 0.0f + zOffset },
            { 0.0f, 0.0f, 0.0f + zOffset + height },
            radius));

    Trinity::Containers::EraseIf(targetList, [&rotatedCylinder](Unit const* unit) -> bool
    {
        return !rotatedCylinder.contains(PositionToVector3(*unit));
    });

#ifdef TRINITY_DEBUG
    // DebugVisualizeShape
    if (Player* caster = Object::ToPlayer(GetCaster()); caster && caster->isDebugAreaTriggers)
        for (int32 end = 0; end < 2; ++end)
            caster->SummonCreature(1, Vector3ToPosition(rotatedCylinder.point(end)), TEMPSUMMON_TIMED_DESPAWN, 50ms);
#endif
}

void AreaTrigger::SearchUnitInDisk(UF::AreaTriggerDisk const& disk, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float innerRadius = G3D::lerp(disk.InnerRadius, disk.InnerRadiusTarget, progress) * scale;
    float outerRadius = G3D::lerp(disk.OuterRadius, disk.OuterRadiusTarget, progress) * scale;
    float height = G3D::lerp(disk.Height, disk.HeightTarget, progress);
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::HeightIgnoresScale))
        height *= scale;

    float zOffset = G3D::lerp(disk.LocationZOffset, disk.LocationZOffsetTarget, progress) * scale;

    SearchUnits(targetList, std::sqrt(outerRadius * outerRadius + height * height), false);

    if (targetList.empty())
        return;

    G3D::Cylinder innerCylinder = G3D::CoordinateFrame(G3D::Quat(_rotation.x, _rotation.y, _rotation.z, _rotation.w), PositionToVector3(GetPosition()))
        .toWorldSpace(G3D::Cylinder(
            { 0.0f, 0.0f, 0.0f + zOffset },
            { 0.0f, 0.0f, 0.0f + zOffset + height },
            innerRadius));

    G3D::Cylinder outerCylinder(innerCylinder.point(0), innerCylinder.point(1), outerRadius);

    Trinity::Containers::EraseIf(targetList, [&innerCylinder, &outerCylinder](Unit const* unit) -> bool
    {
        G3D::Vector3 position = PositionToVector3(*unit);
        return innerCylinder.contains(position) || !outerCylinder.contains(position);
    });

#ifdef TRINITY_DEBUG
    // DebugVisualizeShape
    if (Player* caster = Object::ToPlayer(GetCaster()); caster && caster->isDebugAreaTriggers)
        for (int32 end = 0; end < 2; ++end)
            caster->SummonCreature(1, Vector3ToPosition(innerCylinder.point(end)), TEMPSUMMON_TIMED_DESPAWN, 50ms);
#endif
}

void AreaTrigger::SearchUnitInBoundedPlane(UF::AreaTriggerBoundedPlane const& boundedPlane, std::vector<Unit*>& targetList)
{
    float progress = GetShapeProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsY = G3D::lerp(boundedPlane.ExtentsY, boundedPlane.ExtentsTargetY, progress) * scale;
    float extentsZ = G3D::lerp(boundedPlane.ExtentsZ, boundedPlane.ExtentsTargetZ, progress) * scale;
    float radius = std::sqrt(extentsY * extentsY + extentsZ * extentsZ);

    SearchUnits(targetList, radius, false);

    if (targetList.empty())
        return;

    G3D::CoordinateFrame coordinateFrame = G3D::CoordinateFrame(G3D::Quat(_rotation.x, _rotation.y, _rotation.z, _rotation.w), PositionToVector3(GetPosition()));

    G3D::Vector3 corners[4] =
    {
        coordinateFrame.pointToWorldSpace(G3D::Vector3(0.0f, -extentsY, -extentsZ)),
        coordinateFrame.pointToWorldSpace(G3D::Vector3(0.0f,  extentsY, -extentsZ)),
        coordinateFrame.pointToWorldSpace(G3D::Vector3(0.0f, -extentsY,  extentsZ)),
        coordinateFrame.pointToWorldSpace(G3D::Vector3(0.0f,  extentsY,  extentsZ))
    };

    Trinity::Containers::EraseIf(targetList, [&corners](Unit const* unit) -> bool
    {
        G3D::Vector3 closestPoint = G3D::CollisionDetection::closestPointToRectangle(corners[0], corners[1], corners[2], corners[3], PositionToVector3(*unit));
        return !unit->IsInDist(closestPoint.x, closestPoint.y, closestPoint.z, unit->GetCombatReach());
    });

#ifdef TRINITY_DEBUG
    // DebugVisualizeShape
    if (Player* caster = Object::ToPlayer(GetCaster()); caster && caster->isDebugAreaTriggers)
        for (G3D::Vector3 const& corner : corners)
            caster->SummonCreature(1, Vector3ToPosition(corner), TEMPSUMMON_TIMED_DESPAWN, 50ms);
#endif
}

void AreaTrigger::HandleUnitEnterExit(std::vector<Unit*> const& newTargetList, AreaTriggerExitReason exitMode)
{
    GuidUnorderedSet exitUnits(std::move(_insideUnits));

    std::vector<Unit*> enteringUnits;

    for (Unit* unit : newTargetList)
    {
        if (exitUnits.erase(unit->GetGUID()) == 0) // erase(key_type) returns number of elements erased
            enteringUnits.push_back(unit);

        _insideUnits.insert(unit->GetGUID());
    }

    // Handle after _insideUnits have been reinserted so we can use GetInsideUnits() in hooks
    for (Unit* unit : enteringUnits)
        HandleUnitEnter(unit);

    for (ObjectGuid const& exitUnitGuid : exitUnits)
        if (Unit* leavingUnit = ObjectAccessor::GetUnit(*this, exitUnitGuid))
            HandleUnitExitInternal(leavingUnit, exitMode);

    UpdateHasPlayersFlag();

    if (IsStaticSpawn())
        setActive(!_insideUnits.empty());
}

void AreaTrigger::HandleUnitEnter(Unit* unit)
{
    if (Player* player = unit->ToPlayer())
    {
        if (player->isDebugAreaTriggers)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTITY_ENTERED, GetEntry(), IsCustom(), IsStaticSpawn(), _spawnId);

        player->UpdateQuestObjectiveProgress(QUEST_OBJECTIVE_AREA_TRIGGER_ENTER, GetEntry(), 1);

        if (GetTemplate()->ActionSetId)
            player->UpdateCriteria(CriteriaType::EnterAreaTriggerWithActionSet, GetTemplate()->ActionSetId);
    }

    DoActions(unit);

    _ai->OnUnitEnter(unit);

    // OnUnitEnter script can despawn this areatrigger or teleport player to a different map
    if (!IsInWorld() || !IsInMap(unit))
        return;

    // Register areatrigger in Unit after actions/scripts to allow them to determine
    // if the unit is in one or more areatriggers with the same id
    // without forcing every script to have additional logic excluding this areatrigger
    unit->EnterAreaTrigger(this);
}

void AreaTrigger::HandleUnitExitInternal(Unit* unit, AreaTriggerExitReason exitMode)
{
    bool canTriggerOnExit = exitMode != AreaTriggerExitReason::ByExpire || !HasActionSetFlag(AreaTriggerActionSetFlag::DontRunOnLeaveWhenExpiring);

    if (Player* player = unit->ToPlayer())
    {
        if (player->isDebugAreaTriggers)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTITY_LEFT, GetEntry(), IsCustom(), IsStaticSpawn(), _spawnId);

        if (canTriggerOnExit)
        {
            player->UpdateQuestObjectiveProgress(QUEST_OBJECTIVE_AREA_TRIGGER_EXIT, GetEntry(), 1);

            if (GetTemplate()->ActionSetId)
                player->UpdateCriteria(CriteriaType::LeaveAreaTriggerWithActionSet, GetTemplate()->ActionSetId);
        }
    }

    UndoActions(unit);

    // OnUnitExit script can teleport player to another map, causing it to attempt to exit the areatrigger again (from Unit::ExitAllAreaTriggers)
    unit->ExitAreaTrigger(this);

    if (canTriggerOnExit)
        _ai->OnUnitExit(unit, exitMode);
}

void AreaTrigger::HandleUnitExit(Unit* unit)
{
    _insideUnits.erase(unit->GetGUID());

    HandleUnitExitInternal(unit);

    UpdateHasPlayersFlag();
}

uint32 AreaTrigger::GetScriptId() const
{
    if (_spawnId)
    {
        if (AreaTriggerSpawn const* spawn = ASSERT_NOTNULL(sAreaTriggerDataStore->GetAreaTriggerSpawn(_spawnId)))
        {
            if (spawn->scriptId)
                return spawn->scriptId;
        }
    }

    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        return createProperties->ScriptId;

    return 0;
}

Unit* AreaTrigger::GetCaster() const
{
    return ObjectAccessor::GetUnit(*this, GetCasterGuid());
}

Unit* AreaTrigger::GetTarget() const
{
    return ObjectAccessor::GetUnit(*this, _targetGuid);
}

uint32 AreaTrigger::GetFaction() const
{
    if (Unit const* caster = GetCaster())
        return caster->GetFaction();

    return 0;
}

void AreaTrigger::SetShape(AreaTriggerShapeInfo const& shape)
{
    std::visit([this]<typename ShapeType>(ShapeType const& shapeData)
    {
        auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);

        if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::Sphere>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 0);
            auto sphere = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerSphere>);
            SetUpdateFieldValue(sphere.ModifyValue(&UF::AreaTriggerSphere::Radius), shapeData.Radius);
            SetUpdateFieldValue(sphere.ModifyValue(&UF::AreaTriggerSphere::RadiusTarget), shapeData.RadiusTarget);
        }
        else if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::Box>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 1);
            auto box = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerBox>);
            SetUpdateFieldValue(box.ModifyValue(&UF::AreaTriggerBox::Extents), shapeData.Extents);
            SetUpdateFieldValue(box.ModifyValue(&UF::AreaTriggerBox::ExtentsTarget), shapeData.ExtentsTarget);
        }
        else if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::Polygon>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 3);
            auto polygon = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerPolygon>);
            auto vertices = polygon.ModifyValue(&UF::AreaTriggerPolygon::Vertices);
            ClearDynamicUpdateFieldValues(vertices);
            for (TaggedPosition<XY> const& vertex : shapeData.PolygonVertices)
                AddDynamicUpdateFieldValue(vertices) = vertex;
            auto verticesTarget = polygon.ModifyValue(&UF::AreaTriggerPolygon::VerticesTarget);
            ClearDynamicUpdateFieldValues(verticesTarget);
            for (TaggedPosition<XY> const& vertex : shapeData.PolygonVerticesTarget)
                AddDynamicUpdateFieldValue(verticesTarget) = vertex;
            SetUpdateFieldValue(polygon.ModifyValue(&UF::AreaTriggerPolygon::Height), shapeData.Height);
            SetUpdateFieldValue(polygon.ModifyValue(&UF::AreaTriggerPolygon::HeightTarget), shapeData.HeightTarget);
        }
        else if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::Cylinder>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 4);
            auto cylinder = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerCylinder>);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::Radius), shapeData.Radius);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::RadiusTarget), shapeData.RadiusTarget);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::Height), shapeData.Height);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::HeightTarget), shapeData.HeightTarget);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::LocationZOffset), shapeData.LocationZOffset);
            SetUpdateFieldValue(cylinder.ModifyValue(&UF::AreaTriggerCylinder::LocationZOffsetTarget), shapeData.LocationZOffsetTarget);
        }
        else if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::Disk>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 7);
            auto disk = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerDisk>);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::InnerRadius), shapeData.InnerRadius);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::InnerRadiusTarget), shapeData.InnerRadiusTarget);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::OuterRadius), shapeData.OuterRadius);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::OuterRadiusTarget), shapeData.OuterRadiusTarget);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::Height), shapeData.Height);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::HeightTarget), shapeData.HeightTarget);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::LocationZOffset), shapeData.LocationZOffset);
            SetUpdateFieldValue(disk.ModifyValue(&UF::AreaTriggerDisk::LocationZOffsetTarget), shapeData.LocationZOffsetTarget);
        }
        else if constexpr (std::is_same_v<ShapeType, AreaTriggerShapeInfo::BoundedPlane>)
        {
            SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeType), 8);
            auto boundedPlane = areaTriggerData.ModifyValue(&UF::AreaTriggerData::ShapeData, UF::VariantCase<UF::AreaTriggerBoundedPlane>);
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::ExtentsY), shapeData.ExtentsY);
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::ExtentsZ), shapeData.ExtentsZ);
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::ExtentsTargetY), shapeData.ExtentsTargetY);
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::ExtentsTargetZ), shapeData.ExtentsTargetZ);
        }
        else
            static_assert(Trinity::dependant_false_v<ShapeType>, "Unsupported shape type");
    }, shape.Data);

    if (IsInWorld())
        UpdateDynamicShapeFlag();
}

float AreaTrigger::GetMaxSearchRadius() const
{
    return *m_areaTriggerData->BoundsRadius2D * CalcCurrentScale();
}

void AreaTrigger::UpdatePolygonVertices()
{
    UF::AreaTriggerPolygon const* shape = m_areaTriggerData->ShapeData.Get<UF::AreaTriggerPolygon>();

    // No need to recalculate, orientation didn't change
    if (_verticesUpdatePreviousRotation == _rotation && shape->VerticesTarget.empty())
        return;

    _polygonVertices.assign(shape->Vertices.begin(), shape->Vertices.end());
    if (!shape->VerticesTarget.empty())
    {
        float progress = GetShapeProgress();
        if (m_areaTriggerData->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

        for (std::size_t i = 0; i < _polygonVertices.size(); ++i)
        {
            Position& vertex = _polygonVertices[i];
            Position const& vertexTarget = shape->VerticesTarget[i].Pos;

            vertex.m_positionX = G3D::lerp(vertex.GetPositionX(), vertexTarget.GetPositionX(), progress);
            vertex.m_positionY = G3D::lerp(vertex.GetPositionY(), vertexTarget.GetPositionY(), progress);
        }
    }

    G3D::Matrix3 rotationMatrix(G3D::Quat(_rotation.x, _rotation.y, _rotation.z, _rotation.w));

    // This is needed to rotate the vertices, following orientation
    for (Position& vertice : _polygonVertices)
    {
        G3D::Vector3 transformed = rotationMatrix * PositionToVector3(vertice);
        vertice.Relocate(transformed.x, transformed.y);
    }

    _verticesUpdatePreviousRotation = _rotation;
}

bool AreaTrigger::HasOverridePosition() const
{
    return m_areaTriggerData->OverrideMoveCurveX->OverrideActive
        && m_areaTriggerData->OverrideMoveCurveY->OverrideActive
        && m_areaTriggerData->OverrideMoveCurveZ->OverrideActive;
}

void AreaTrigger::UpdateShape()
{
    if (m_areaTriggerData->ShapeData.Is<UF::AreaTriggerPolygon>())
        UpdatePolygonVertices();
}

bool UnitFitToActionRequirement(Unit* unit, Unit* caster, AreaTriggerAction const& action)
{
    switch (action.TargetType)
    {
        case AREATRIGGER_ACTION_USER_FRIEND:
        {
            return caster->IsValidAssistTarget(unit, sSpellMgr->GetSpellInfo(action.Param, caster->GetMap()->GetDifficultyID()));
        }
        case AREATRIGGER_ACTION_USER_ENEMY:
        {
            return caster->IsValidAttackTarget(unit, sSpellMgr->GetSpellInfo(action.Param, caster->GetMap()->GetDifficultyID()));
        }
        case AREATRIGGER_ACTION_USER_RAID:
        {
            return caster->IsInRaidWith(unit);
        }
        case AREATRIGGER_ACTION_USER_PARTY:
        {
            return caster->IsInPartyWith(unit);
        }
        case AREATRIGGER_ACTION_USER_CASTER:
        {
            return unit->GetGUID() == caster->GetGUID();
        }
        case AREATRIGGER_ACTION_USER_ANY:
        default:
            break;
    }

    return true;
}

void AreaTrigger::DoActions(Unit* unit)
{
    Unit* caster = IsStaticSpawn() ? unit : GetCaster();

    if (caster && GetTemplate())
    {
        for (AreaTriggerAction const& action : GetTemplate()->Actions)
        {
            if (IsStaticSpawn() || UnitFitToActionRequirement(unit, caster, action))
            {
                switch (action.ActionType)
                {
                    case AREATRIGGER_ACTION_CAST:
                        caster->CastSpell(unit, action.Param, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                            .SetOriginalCastId(m_areaTriggerData->CreatingEffectGUID->IsCast() ? *m_areaTriggerData->CreatingEffectGUID : ObjectGuid::Empty));
                        break;
                    case AREATRIGGER_ACTION_ADDAURA:
                        caster->AddAura(action.Param, unit);
                        break;
                    case AREATRIGGER_ACTION_TELEPORT:
                    {
                        if (WorldSafeLocsEntry const* safeLoc = sObjectMgr->GetWorldSafeLoc(action.Param))
                        {
                            if (Player* player = caster->ToPlayer())
                            {
                                if (player->GetMapId() != safeLoc->Loc.GetMapId())
                                {
                                    if (WorldSafeLocsEntry const* instanceEntrance = player->GetInstanceEntrance(safeLoc->Loc.GetMapId()))
                                        safeLoc = instanceEntrance;
                                }
                                player->TeleportTo(safeLoc->Loc);
                            }
                        }
                        break;
                    }
                    case AREATRIGGER_ACTION_TAVERN:
                        if (Player* player = caster->ToPlayer())
                        {
                            player->GetRestMgr().SetInnTrigger(InnAreaTrigger{ .IsDBC = false });
                            player->GetRestMgr().SetRestFlag(REST_FLAG_IN_TAVERN);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void AreaTrigger::UndoActions(Unit* unit)
{
    if (GetTemplate())
    {
        for (AreaTriggerAction const& action : GetTemplate()->Actions)
        {
            switch (action.ActionType)
            {
                case AREATRIGGER_ACTION_CAST:
                    [[fallthrough]];
                case AREATRIGGER_ACTION_ADDAURA:
                    unit->RemoveAurasDueToSpell(action.Param, GetCasterGuid());
                    break;
                case AREATRIGGER_ACTION_TAVERN:
                    if (Player* player = unit->ToPlayer())
                        player->GetRestMgr().SetInnTrigger(std::nullopt);
                    break;
                default:
                    break;
            }
        }
    }
}

void AreaTrigger::UpdatePositionAndRotation()
{
    auto [movementUpdateResult, newPosition, newRotation] = CalculateWorldPositionAndRotation();

    if (HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached))
        if (Unit* target = GetTarget())
            RelocateStationaryPosition(target->GetPosition());

    Position oldPosition = GetPosition();
    QuaternionData oldRotation = std::exchange(_rotation, { newRotation.x, newRotation.y, newRotation.z, newRotation.w });

    if (newPosition != oldPosition)
    {
        GetMap()->AreaTriggerRelocation(this, newPosition.GetPositionX(), newPosition.GetPositionY(), newPosition.GetPositionZ(), newPosition.GetOrientation());
    }
    else
    {
        SetOrientation(newPosition.GetOrientation());
        if (oldRotation != _rotation)
            UpdateShape();
    }

#ifdef TRINITY_DEBUG
    if (movementUpdateResult != MovementUpdateResult::None)
        DebugVisualizePosition();
#endif

    if (movementUpdateResult == MovementUpdateResult::Arrived)
    {
        if (!_reachedDestination)
            _ai->OnDestinationReached();

        _reachedDestination = true;
    }
}

AreaTrigger::MovementUpdateWorldResult AreaTrigger::CalculateWorldPositionAndRotation() const
{
    auto [status, localPosition, localRotation] = CalculateLocalPositionAndRotation();
    MovementUpdateWorldResult worldResult {
        .Status = status,
        .Position = Vector3ToPosition(localPosition),
        .Rotation = G3D::Quat::fromYPRAngles(localRotation.z, localRotation.y, localRotation.x)
    };

    if (HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached))
    {
        if (Unit* target = GetTarget())
        {
            worldResult.Position = target->GetPositionWithOffset(worldResult.Position);

            if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
                worldResult.Rotation = G3D::Quat::fromAxisAngleRotation(G3D::Vector3::unitZ(), target->GetOrientation()) * worldResult.Rotation;

            if (worldResult.Status == MovementUpdateResult::None)
                worldResult.Status = MovementUpdateResult::Moved;
        }
    }
    else if (TransportBase const* transport = GetTransport())
    {
        worldResult.Position = transport->GetPositionWithOffset(worldResult.Position);

        if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
            worldResult.Rotation = G3D::Quat::fromAxisAngleRotation(G3D::Vector3::unitZ(), transport->GetTransportOrientation()) * worldResult.Rotation;
    }
    else
        worldResult.Position = GetMovementOrigin().GetPositionWithOffset(worldResult.Position);

    worldResult.Rotation.toYPRAngles(localRotation.z, localRotation.y, localRotation.x);
    worldResult.Position.SetOrientation(localRotation.z);

    return worldResult;
}

struct AreaTriggerPositionAndRotationCalcVisitor
{
    AreaTrigger::MovementUpdateLocalResult operator()(UF::AreaTriggerSplineCalculator const&) const { return at->CalculateLocalSplinePositionAndRotation(); }
    AreaTrigger::MovementUpdateLocalResult operator()(UF::AreaTriggerOrbit const& orbit) const { return at->CalculateLocalOrbitPositionAndRotation(orbit); }
    AreaTrigger::MovementUpdateLocalResult operator()(std::monostate) const { return at->CalculateLocalStationaryPositionAndRotation(); }
    AreaTrigger::MovementUpdateLocalResult operator()(UF::AreaTriggerMovementScript const& /*script*/) const { ASSERT(false, "AreaTriggerMovementScript is not implemented"); }

    AreaTrigger const* at;
};

AreaTrigger::MovementUpdateLocalResult AreaTrigger::CalculateLocalPositionAndRotation() const
{
    MovementUpdateLocalResult result = m_areaTriggerData->PathData.Visit(AreaTriggerPositionAndRotationCalcVisitor{ this });

    if (m_areaTriggerData->TargetRollPitchYaw.has_value())
    {
        float progress = GetShapeProgress();
        if (m_areaTriggerData->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

        result.Rotation += PositionToVector3(m_areaTriggerData->RollPitchYaw->Pos)
            .lerp(PositionToVector3(m_areaTriggerData->TargetRollPitchYaw->Pos), progress);
    }
    else
        result.Rotation += PositionToVector3(m_areaTriggerData->RollPitchYaw->Pos);

    if (HasOverridePosition())
    {
        result.Status = MovementUpdateResult::Moved;

        float progress = GetOverridePosProgress();
        result.Position.x = GetOverrideCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveX, progress);
        result.Position.y = GetOverrideCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveY, progress);
        result.Position.z = GetOverrideCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveZ, progress);

        if (m_movementInfo.transport.guid.IsEmpty())
            result.Position = PositionToVector3(GetMovementOrigin().GetPositionOffsetTo(Vector3ToPosition(result.Position)));
    }

    return result;
}

void AreaTrigger::InitSplineOffsets(std::vector<Position> const& offsets, Optional<float> overrideSpeed /*= {}*/, Optional<bool> speedIsTimeInSeconds /*= {}*/)
{
    float angleSin = std::sin(GetOrientation());
    float angleCos = std::cos(GetOrientation());

    // This is needed to rotate the spline, following caster orientation
    std::vector<G3D::Vector3> rotatedPoints;
    rotatedPoints.resize(offsets.size());
    for (std::size_t i = 0; i < offsets.size(); ++i)
    {
        Position const& offset = offsets[i];
        rotatedPoints[i].x = GetPositionX() + (offset.GetPositionX() * angleCos - offset.GetPositionY() * angleSin);
        rotatedPoints[i].y = GetPositionY() + (offset.GetPositionY() * angleCos + offset.GetPositionX() * angleSin);
        rotatedPoints[i].z = GetPositionZ();

        UpdateAllowedPositionZ(rotatedPoints[i].x, rotatedPoints[i].y, rotatedPoints[i].z);
        rotatedPoints[i].z += offset.GetPositionZ();
    }

    InitSplines(rotatedPoints, overrideSpeed, speedIsTimeInSeconds);
}

void AreaTrigger::InitSplines(std::vector<G3D::Vector3> const& splinePoints, Optional<float> overrideSpeed /*= {}*/, Optional<bool> speedIsTimeInSeconds /*= {}*/)
{
    if (splinePoints.size() < 2)
        return;

    _spline = std::make_unique<::Movement::Spline<float>>();
    _reachedDestination = false;

    std::vector<G3D::Vector3> offsets(splinePoints.size());
    for (std::size_t i = 0; i < splinePoints.size(); ++i)
        offsets[i] = PositionToVector3(GetStationaryPosition().GetPositionOffsetTo(Vector3ToPosition(splinePoints[i])));

    _spline->init_spline(offsets.data(), offsets.size(), offsets.size() > 2 ? ::Movement::SplineBase::ModeCatmullrom : ::Movement::SplineBase::ModeLinear, _stationaryPosition.GetOrientation());
    _spline->initLengths();

    float speed = overrideSpeed.value_or(GetCreateProperties()->Speed);
    if (speed <= 0.0f)
        speed = 1.0f;

    uint32 timeToTarget = (speedIsTimeInSeconds.value_or(GetCreateProperties()->SpeedIsTime)
        ? speed
        : _spline->length() / speed) * static_cast<float>(IN_MILLISECONDS);

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MovementStartTime), GameTime::GetGameTimeMS());

    SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::Spline));
    auto pathData = areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathData, UF::VariantCase<UF::AreaTriggerSplineCalculator>);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerSplineCalculator::Linear), _spline->mode() == ::Movement::SplineBase::ModeLinear);
    auto points = pathData.ModifyValue(&UF::AreaTriggerSplineCalculator::Points);

    ClearDynamicUpdateFieldValues(points);
    if (m_movementInfo.transport.guid.IsEmpty())
    {
        for (G3D::Vector3 const& point : _spline->getPoints())
            AddDynamicUpdateFieldValue(points) = GetStationaryPosition().GetPositionWithOffset(Vector3ToPosition(point));
    }
    else
    {
        for (G3D::Vector3 const& point : _spline->getPoints())
            AddDynamicUpdateFieldValue(points) = Vector3ToPosition(point);
    }
}

uint32 AreaTrigger::GetElapsedTimeForMovement() const
{
    uint32 now = GameTime::GetGameTimeMS();
    if (now >= *m_areaTriggerData->MovementStartTime)
        return now - *m_areaTriggerData->MovementStartTime;
    return 0;
}

void AreaTrigger::InitOrbit(AreaTriggerOrbitInfo const& orbit, Optional<float> overrideSpeed /*= {}*/, Optional<bool> speedIsTimeInSeconds /*= {}*/)
{
    // Circular movement requires either a center position or an attached unit
    ASSERT(orbit.Center.has_value() || orbit.PathTarget.has_value());

    float speed = overrideSpeed.value_or(GetCreateProperties()->Speed);
    if (speed <= 0.0f)
        speed = 1.0f;

    uint32 timeToTarget = (speedIsTimeInSeconds.value_or(GetCreateProperties()->SpeedIsTime)
        ? speed
        : static_cast<uint32>(orbit.Radius * 2.0f * static_cast<float>(M_PI) / speed)) * static_cast<float>(IN_MILLISECONDS);

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MovementStartTime), GameTime::GetGameTimeMS());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OrbitPathTarget), orbit.PathTarget.value_or(ObjectGuid::Empty));
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ZOffset), orbit.ZOffset);
    if (orbit.CanLoop)
        SetAreaTriggerFlag(AreaTriggerFieldFlags::CanLoop);
    else
        RemoveAreaTriggerFlag(AreaTriggerFieldFlags::CanLoop);

    SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::Orbit));
    auto pathData = areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathData, UF::VariantCase<UF::AreaTriggerOrbit>);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::CounterClockwise), orbit.CounterClockwise);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::Radius), orbit.Radius);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::InitialAngle), orbit.InitialAngle);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::BlendFromRadius), orbit.BlendFromRadius);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::ExtraTimeForBlending), orbit.ExtraTimeForBlending);

    Position center = orbit.Center.value_or(Position());
    if (orbit.Center)
        if (WorldObject const* attachedTo = ObjectAccessor::GetWorldObject(*this, m_movementInfo.transport.guid))
            center = attachedTo->GetPositionOffsetTo(*orbit.Center);

    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::Center), center);
}

AreaTrigger::MovementUpdateLocalResult AreaTrigger::CalculateLocalSplinePositionAndRotation() const
{
    float currentTimePercent = std::clamp(float(GetElapsedTimeForMovement()) / float(GetTimeToTarget()), 0.0f, 1.0f);
    bool reachedDestination = currentTimePercent >= 1.0f;

    if (m_areaTriggerData->MoveCurveId)
    {
        float progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MoveCurveId, currentTimePercent);
        if (progress < 0.f || progress > 1.f)
        {
            AreaTriggerCreateProperties const* createProperties = GetCreateProperties();
            TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (Id: {}, AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})) has wrong progress ({}) caused by curve calculation (MoveCurveId: {})",
                GetEntry(), createProperties->Id.Id, uint32(createProperties->Id.IsCustom), progress, *m_areaTriggerData->MoveCurveId);
        }
        else
            currentTimePercent = progress;
    }

    int32 lastPositionIndex = 0;
    float percentFromLastPoint = 0;
    _spline->computeIndex(currentTimePercent, lastPositionIndex, percentFromLastPoint);

    G3D::Vector3 currentPosition;
    _spline->evaluate_percent(lastPositionIndex, percentFromLastPoint, currentPosition);

    float orientation = 0.0f;
    if (m_areaTriggerData->FacingCurveId)
        orientation += sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetShapeProgress());

    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
    {
        G3D::Vector3 derivative;
        _spline->evaluate_derivative(lastPositionIndex, percentFromLastPoint, derivative);
        if (derivative.x != 0.0f || derivative.y != 0.0f)
            orientation += std::atan2(derivative.y, derivative.x);
    }

    return {
        .Status = reachedDestination ? MovementUpdateResult::Arrived : MovementUpdateResult::Moved,
        .Position = currentPosition,
        .Rotation = G3D::Vector3(0.0f, 0.0f, orientation)
    };
}

AreaTrigger::MovementUpdateLocalResult AreaTrigger::CalculateLocalOrbitPositionAndRotation(UF::AreaTriggerOrbit const& orbit) const
{
    uint32 movementTime = GetElapsedTimeForMovement();
    uint32 timeToTarget = GetTimeToTarget() + orbit.ExtraTimeForBlending;
    bool firstLoop = true;
    if (HasAreaTriggerFlag(AreaTriggerFieldFlags::CanLoop) && timeToTarget)
    {
        // remove ExtraTimeForBlending if not on first loop
        if (movementTime > timeToTarget)
        {
            timeToTarget -= orbit.ExtraTimeForBlending;
            movementTime = (movementTime - orbit.ExtraTimeForBlending) % timeToTarget;
            firstLoop = false;
        }
    }

    float pathProgress = float(movementTime) / float(timeToTarget);
    if (m_areaTriggerData->MoveCurveId)
        pathProgress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MoveCurveId, pathProgress);

    // We already made one circle and can't loop
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::CanLoop))
        pathProgress = std::min(1.f, pathProgress);

    float radius = orbit.Radius;
    if (firstLoop && G3D::fuzzyNe(orbit.BlendFromRadius, radius))
    {
        float blendCurve = std::clamp((orbit.BlendFromRadius - radius) / radius, 1.0f, 4.0f);
        float blendProgress = std::clamp(std::abs(4.0f * pathProgress / blendCurve), 0.0f, 1.0f);
        radius = G3D::lerp(orbit.BlendFromRadius, radius, blendProgress);
    }

    float angle = 2.0f * float(M_PI) * pathProgress;

    // Adapt angle depending of circle direction
    if (!orbit.CounterClockwise)
        angle *= -1;

    angle += orbit.InitialAngle;

    G3D::Vector3 position =
    {
        radius * std::cos(angle),
        radius * std::sin(angle),
        m_areaTriggerData->ZOffset
    };

    float orientation = 0.0f;
    if (m_areaTriggerData->FacingCurveId)
        orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetShapeProgress());

    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
    {
        orientation += angle;
        orientation += orbit.CounterClockwise ? float(M_PI_4) : -float(M_PI_4);
    }

    return {
        .Status = MovementUpdateResult::Moved,
        .Position = position,
        .Rotation = G3D::Vector3(0.0f, 0.0f, orientation)
    };
}

AreaTrigger::MovementUpdateLocalResult AreaTrigger::CalculateLocalStationaryPositionAndRotation() const
{
    float orientation = 0.0f;
    if (m_areaTriggerData->FacingCurveId)
        orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetShapeProgress());

    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
        orientation += *m_areaTriggerData->Facing;

    return {
        .Status = MovementUpdateResult::None,
        .Position = G3D::Vector3::zero(),
        .Rotation = G3D::Vector3(0.0f, 0.0f, orientation)
    };
}

struct AreaTriggerMovementOriginVisitor
{
    Position const& operator()(UF::AreaTriggerSplineCalculator const&) const { return at->GetStationaryPosition(); }
    Position const& operator()(UF::AreaTriggerOrbit const& orbit) const
    {
        if (!at->m_areaTriggerData->OrbitPathTarget->IsEmpty())
        {
            if (WorldObject const* pathTarget = ObjectAccessor::GetWorldObject(*at, *at->m_areaTriggerData->OrbitPathTarget))
                return *pathTarget;
            return at->GetStationaryPosition();
        }

        return orbit.Center->Pos;
    }
    Position const& operator()(std::monostate) const { return at->GetStationaryPosition(); }
    Position const& operator()(UF::AreaTriggerMovementScript const& script) const { return script.Center->Pos; }

    AreaTrigger const* at;
};

Position const& AreaTrigger::GetMovementOrigin() const
{
    return m_areaTriggerData->PathData.Visit(AreaTriggerMovementOriginVisitor{ this });
}

void AreaTrigger::UpdateDynamicShapeFlag()
{
    if (AreaTriggerPathType(*m_areaTriggerData->PathType) != AreaTriggerPathType::Stationary
        || HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached)
        || (*m_areaTriggerData->OverrideScaleCurve->OverrideActive && !(*m_areaTriggerData->OverrideScaleCurve->ParameterCurve & 1))
        || *m_areaTriggerData->ScaleCurveId
        || (*m_areaTriggerData->ExtraScaleCurve->OverrideActive && !(*m_areaTriggerData->ExtraScaleCurve->ParameterCurve & 1))
        || (HasOverridePosition()
            && (!(*m_areaTriggerData->OverrideMoveCurveX->ParameterCurve & 1)
                || !(*m_areaTriggerData->OverrideMoveCurveY->ParameterCurve & 1)
                || !(*m_areaTriggerData->OverrideMoveCurveZ->ParameterCurve & 1)))
        || (m_areaTriggerData->TargetRollPitchYaw.has_value() && *m_areaTriggerData->RollPitchYaw != *m_areaTriggerData->TargetRollPitchYaw)
        || GetCreateProperties()->Shape.IsDynamic())
        SetAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
    else
        RemoveAreaTriggerFlag(AreaTriggerFieldFlags::DynamicShape);
}

void AreaTrigger::UpdateHasPlayersFlag()
{
    if (std::ranges::any_of(_insideUnits, [](ObjectGuid const& guid) { return guid.IsPlayer(); }))
        SetAreaTriggerFlag(AreaTriggerFieldFlags::HasPlayers);
    else
        RemoveAreaTriggerFlag(AreaTriggerFieldFlags::HasPlayers);
}

void AreaTrigger::DebugVisualizePosition()
{
    if (Unit* caster = GetCaster())
        if (Player* player = caster->ToPlayer())
            if (player->isDebugAreaTriggers)
                player->SummonCreature(1, *this, TEMPSUMMON_TIMED_DESPAWN, 250ms);
}

void AreaTrigger::AI_Initialize()
{
    AI_Destroy();
    _ai.reset(FactorySelector::SelectAreaTriggerAI(this));
    _ai->OnInitialize();
}

void AreaTrigger::AI_Destroy()
{
    _ai.reset();
}

bool AreaTrigger::IsNeverVisibleFor(WorldObject const* seer, bool allowServersideObjects) const
{
    if (WorldObject::IsNeverVisibleFor(seer, allowServersideObjects))
        return true;

    if (IsServerSide() && !allowServersideObjects)
    {
        if (Player const* seerPlayer = seer->ToPlayer())
            return !seerPlayer->isDebugAreaTriggers;

        return true;
    }

    return false;
}

void AreaTrigger::BuildValuesCreate(UF::UpdateFieldFlag flags, ByteBuffer& data, Player const* target) const
{
    m_objectData->WriteCreate(flags, data, target, this);
    m_areaTriggerData->WriteCreate(flags, data, target, this);
}

void AreaTrigger::BuildValuesUpdate(UF::UpdateFieldFlag flags, ByteBuffer& data, Player const* target) const
{
    data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(flags, data, target, this);

    if (m_values.HasChanged(TYPEID_AREATRIGGER))
        m_areaTriggerData->WriteUpdate(flags, data, target, this);
}

void AreaTrigger::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::AreaTriggerData::Mask const& requestedAreaTriggerMask, Player const* target, bool ignoreNestedChangesMask) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    if (requestedAreaTriggerMask.IsAnySet())
        valuesMask.Set(TYPEID_AREATRIGGER);

    ByteBuffer& buffer = PrepareValuesUpdateBuffer(data);
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    BuildEntityFragmentsForValuesUpdateForPlayerWithMask(buffer, flags);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(requestedObjectMask, buffer, target, this, ignoreNestedChangesMask);

    if (valuesMask[TYPEID_AREATRIGGER])
        m_areaTriggerData->WriteUpdate(requestedAreaTriggerMask, buffer, target, this, ignoreNestedChangesMask);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void AreaTrigger::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), AreaTriggerMask.GetChangesMask(), player, IgnoreNestedChangesMask);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void AreaTrigger::ClearValuesChangesMask()
{
    m_values.ClearChangesMask(&AreaTrigger::m_areaTriggerData);
    WorldObject::ClearValuesChangesMask();
}
