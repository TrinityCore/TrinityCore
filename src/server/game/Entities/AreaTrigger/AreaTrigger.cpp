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
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Spline.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"
#include "ZoneScript.h"
#include "advstd.h"
#include <bit>

AreaTrigger::AreaTrigger() : WorldObject(false), MapObject(), _spawnId(0), _aurEff(nullptr),
    _duration(0), _totalDuration(0), _verticesUpdatePreviousOrientation(std::numeric_limits<float>::infinity()),
    _isRemoved(false), _reachedDestination(true), _lastSplineIndex(0),
    _areaTriggerCreateProperties(nullptr), _areaTriggerTemplate(nullptr)
{
    m_objectType |= TYPEMASK_AREATRIGGER;
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

    Object::_Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), GetTemplate() ? GetTemplate()->Id.Id : 0, GetMap()->GenerateLowGuid<HighGuid::AreaTrigger>()));

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
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), GetCreateProperties()->TimeToTargetScale != 0 ? GetCreateProperties()->TimeToTargetScale : *m_areaTriggerData->Duration);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::BoundsRadius2D), GetCreateProperties()->Shape.GetMaxSearchRadius());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), GetCreateProperties()->DecalPropertiesId);
    if (IsServerSide())
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), 24); // Blue decal, for .debug areatrigger visibility

    SetScaleCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), 1.0f);

    if (caster)
    {
        if (Player const* modOwner = caster->GetSpellModOwner())
        {
            float multiplier = 1.0f;
            int32 flat = 0;
            modOwner->GetSpellModValues(spellInfo, SpellModOp::Radius, spell, *m_areaTriggerData->BoundsRadius2D, &flat, &multiplier);
            if (multiplier != 1.0f)
            {
                ScaleCurveData overrideScale;
                overrideScale.Curve = multiplier;
                SetScaleCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), overrideScale);
            }
        }
    }

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimationDataID), GetCreateProperties()->AnimId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimKitID), GetCreateProperties()->AnimKitId);
    if (GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::VisualAnimIsDecay))
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::IsDecay), true);

    AreaTriggerFieldFlags fieldFlags = [flags = GetCreateProperties()->Flags]()
    {
        AreaTriggerFieldFlags fieldFlags = AreaTriggerFieldFlags::None;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation))
            fieldFlags |= AreaTriggerFieldFlags::AbsoluteOrientation;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasDynamicShape))
            fieldFlags |= AreaTriggerFieldFlags::DynamicShape;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAttached))
            fieldFlags |= AreaTriggerFieldFlags::Attached;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasFaceMovementDir))
            fieldFlags |= AreaTriggerFieldFlags::FaceMovementDir;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasFollowsTerrain))
            fieldFlags |= AreaTriggerFieldFlags::FollowsTerrain;
        if (flags.HasFlag(AreaTriggerCreatePropertiesFlag::AlwaysExterior))
            fieldFlags |= AreaTriggerFieldFlags::AlwaysExterior;
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

    if (target && HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached))
        m_movementInfo.transport.guid = target->GetGUID();

    if (!IsStaticSpawn())
        UpdatePositionData();

    UpdateShape();

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
            this->SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::None));
        else
            static_assert(Trinity::dependant_false_v<MovementType>, "Unsupported movement type");
    }, GetCreateProperties()->Movement);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::Facing), _stationaryPosition.GetOrientation());

    // movement on transport of areatriggers on unit is handled by themself
    TransportBase* transport = nullptr;
    if (caster)
    {
        transport = m_movementInfo.transport.guid.IsEmpty() ? caster->GetTransport() : nullptr;
        if (transport)
        {
            float x, y, z, o;
            pos.GetPosition(x, y, z, o);
            transport->CalculatePassengerOffset(x, y, z, &o);
            m_movementInfo.transport.pos.Relocate(x, y, z, o);

            // This object must be added to transport before adding to map for the client to properly display it
            transport->AddPassenger(this);
        }
    }

    AI_Initialize();

    // Relocate areatriggers with circular movement again
    if (HasOrbit())
        Relocate(CalculateOrbitPosition());

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

    _ai->OnCreate(spell ? spell : nullptr);

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
    {
        // "If" order matter here, Orbit > Attached > Splines
        if (HasOverridePosition())
        {
            UpdateOverridePosition();
        }
        else if (HasOrbit())
        {
            UpdateOrbitPosition();
        }
        else if (HasAreaTriggerFlag(AreaTriggerFieldFlags::Attached))
        {
            if (Unit* target = GetTarget())
            {
                float orientation = 0.0f;
                if (m_areaTriggerData->FacingCurveId)
                    orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetProgress());

                if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
                    orientation += target->GetOrientation();

                GetMap()->AreaTriggerRelocation(this, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), orientation);
            }
        }
        else if (HasSplines())
        {
            UpdateSplinePosition(*_spline);
        }
        else
        {
            if (m_areaTriggerData->FacingCurveId)
            {
                float orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetProgress());
                if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
                    orientation += m_areaTriggerData->Facing;

                SetOrientation(orientation);
            }

            UpdateShape();
        }
    }

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
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), overrideScale);
}

void AreaTrigger::SetOverrideScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), points, startTimeOffset, interpolation);
}

void AreaTrigger::ClearOverrideScaleCurve()
{
    ClearScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve));
}

void AreaTrigger::SetExtraScaleCurve(float extraScale)
{
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), extraScale);
}

void AreaTrigger::SetExtraScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), points, startTimeOffset, interpolation);
}

void AreaTrigger::ClearExtraScaleCurve()
{
    ClearScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve));
}

void AreaTrigger::SetOverrideMoveCurve(float x, float y, float z)
{
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX), x);
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY), y);
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ), z);
}

void AreaTrigger::SetOverrideMoveCurve(std::array<DBCPosition2D, 2> const& xCurvePoints, std::array<DBCPosition2D, 2> const& yCurvePoints,
    std::array<DBCPosition2D, 2> const& zCurvePoints, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX), xCurvePoints, startTimeOffset, interpolation);
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY), yCurvePoints, startTimeOffset, interpolation);
    SetScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ), zCurvePoints, startTimeOffset, interpolation);
}

void AreaTrigger::ClearOverrideMoveCurve()
{
    ClearScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveX));
    ClearScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveY));
    ClearScaleCurve(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OverrideMoveCurveZ));
}

void AreaTrigger::SetSpellVisual(SpellCastVisual const& visual)
{
    auto spellVisualMutator = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::SpellVisual);

    SetUpdateFieldValue(spellVisualMutator.ModifyValue(&UF::SpellCastVisual::SpellXSpellVisualID), visual.SpellXSpellVisualID);
    SetUpdateFieldValue(spellVisualMutator.ModifyValue(&UF::SpellCastVisual::ScriptVisualID), visual.ScriptVisualID);
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
        scale *= std::max(GetScaleCurveValue(*m_areaTriggerData->OverrideScaleCurve, m_areaTriggerData->TimeToTargetScale), 0.000001f);
    else if (m_areaTriggerData->ScaleCurveId)
        scale *= std::max(sDB2Manager.GetCurveValueAt(m_areaTriggerData->ScaleCurveId, GetScaleCurveProgress(*m_areaTriggerData->OverrideScaleCurve, m_areaTriggerData->TimeToTargetScale)), 0.000001f);

    scale *= std::max(GetScaleCurveValue(*m_areaTriggerData->ExtraScaleCurve, m_areaTriggerData->TimeToTargetExtraScale), 0.000001f);

    return scale;
}

float AreaTrigger::GetProgress() const
{
    if (_totalDuration <= 0)
        return 1.0f;

    return std::clamp(float(GetTimeSinceCreated()) / float(GetTotalDuration()), 0.0f, 1.0f);
}

float AreaTrigger::GetScaleCurveProgress(UF::ScaleCurve const& scaleCurve, uint32 timeTo) const
{
    if (!timeTo)
        return 0.0f;

    return std::clamp(float(GetTimeSinceCreated() - scaleCurve.StartTimeOffset) / float(timeTo), 0.0f, 1.0f);
}

float AreaTrigger::GetScaleCurveValueAtProgress(UF::ScaleCurve const& scaleCurve, float x) const
{
    ASSERT(*scaleCurve.OverrideActive, "ScaleCurve must be active to evaluate it");

    // unpack ParameterCurve
    if (*scaleCurve.ParameterCurve & 1u)
        return advstd::bit_cast<float>(*scaleCurve.ParameterCurve & ~1u);

    std::array<DBCPosition2D, 2> points;
    for (std::size_t i = 0; i < scaleCurve.Points.size(); ++i)
        points[i] = { .X = scaleCurve.Points[i].Pos.GetPositionX(), .Y = scaleCurve.Points[i].Pos.GetPositionY() };

    CurveInterpolationMode mode = CurveInterpolationMode(*scaleCurve.ParameterCurve >> 1 & 0x7);
    std::size_t pointCount = *scaleCurve.ParameterCurve >> 24 & 0xFF;

    return sDB2Manager.GetCurveValueAt(mode, std::span(points.begin(), pointCount), x);
}

float AreaTrigger::GetScaleCurveValue(UF::ScaleCurve const& scaleCurve, uint32 timeTo) const
{
    return GetScaleCurveValueAtProgress(scaleCurve, GetScaleCurveProgress(scaleCurve, timeTo));
}

void AreaTrigger::SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, float constantValue)
{
    ScaleCurveData curveTemplate;
    curveTemplate.Curve = constantValue;
    SetScaleCurve(scaleCurveMutator, curveTemplate);
}

void AreaTrigger::SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, std::array<DBCPosition2D, 2> const& points,
    Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    ScaleCurveData curveTemplate;
    curveTemplate.StartTimeOffset = startTimeOffset.value_or(GetTimeSinceCreated());
    curveTemplate.Mode = interpolation;
    curveTemplate.Curve = points;

    SetScaleCurve(scaleCurveMutator, curveTemplate);
}

void AreaTrigger::ClearScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator)
{
    SetScaleCurve(scaleCurveMutator, {});
}

void AreaTrigger::SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, Optional<ScaleCurveData> const& curve)
{
    if (!curve)
    {
        SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::OverrideActive), false);
        return;
    }

    SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::OverrideActive), true);
    SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::StartTimeOffset), curve->StartTimeOffset);

    Position point;
    // ParameterCurve packing information
    // (not_using_points & 1) | ((interpolation_mode & 0x7) << 1) | ((first_point_offset & 0xFFFFF) << 4) | ((point_count & 0xFF) << 24)
    //   if not_using_points is set then the entire field is simply read as a float (ignoring that lowest bit)

    if (float const* simpleFloat = std::get_if<float>(&curve->Curve))
    {
        uint32 packedCurve = advstd::bit_cast<uint32>(*simpleFloat);
        packedCurve |= 1;

        SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::ParameterCurve), packedCurve);

        // clear points
        for (std::size_t i = 0; i < UF::size<decltype(UF::ScaleCurve::Points)>(); ++i)
            SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::Points, i), point);
    }
    else if (ScaleCurveData::Points const* curvePoints = std::get_if<ScaleCurveData::Points>(&curve->Curve))
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
        SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::ParameterCurve), packedCurve);

        for (std::size_t i = 0; i < curvePoints->size(); ++i)
        {
            point.Relocate((*curvePoints)[i].X, (*curvePoints)[i].Y);
            SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::Points, i), point);
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
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(sphere.Radius, sphere.RadiusTarget, progress) * scale;

    SearchUnits(targetList, radius, true);
}

void AreaTrigger::SearchUnitInBox(UF::AreaTriggerBox const& box, std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsX = G3D::lerp(box.Extents->Pos.GetPositionX(), box.ExtentsTarget->Pos.GetPositionX(), progress) * scale;
    float extentsY = G3D::lerp(box.Extents->Pos.GetPositionY(), box.ExtentsTarget->Pos.GetPositionY(), progress) * scale;
    float extentsZ = G3D::lerp(box.Extents->Pos.GetPositionZ(), box.ExtentsTarget->Pos.GetPositionZ(), progress) * scale;
    float radius = std::sqrt(extentsX * extentsX + extentsY * extentsY);

    SearchUnits(targetList, radius, false);

    Position const& boxCenter = GetPosition();
    Trinity::Containers::EraseIf(targetList, [boxCenter, extentsX, extentsY, extentsZ](Unit const* unit) -> bool
    {
        return !unit->IsWithinBox(boxCenter, extentsX, extentsY, extentsZ / 2);
    });
}

void AreaTrigger::SearchUnitInPolygon(UF::AreaTriggerPolygon const& polygon, std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float height = G3D::lerp(polygon.Height, polygon.HeightTarget, progress);
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, GetMaxSearchRadius(), false);

    Trinity::Containers::EraseIf(targetList, [this, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ
            || !unit->IsInPolygon2D(*this, _polygonVertices);
    });
}

void AreaTrigger::SearchUnitInCylinder(UF::AreaTriggerCylinder const& cylinder, std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(cylinder.Radius, cylinder.RadiusTarget, progress) * scale;
    float height = G3D::lerp(cylinder.Height, cylinder.HeightTarget, progress);
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::HeightIgnoresScale))
        height *= scale;

    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, radius, false);

    Trinity::Containers::EraseIf(targetList, [minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::SearchUnitInDisk(UF::AreaTriggerDisk const& disk, std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float innerRadius = G3D::lerp(disk.InnerRadius, disk.InnerRadiusTarget, progress) * scale;
    float outerRadius = G3D::lerp(disk.OuterRadius, disk.OuterRadiusTarget, progress) * scale;
    float height = G3D::lerp(disk.Height, disk.HeightTarget, progress);
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::HeightIgnoresScale))
        height *= scale;

    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, outerRadius, false);

    Trinity::Containers::EraseIf(targetList, [this, innerRadius, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->IsInDist2d(this, innerRadius) || unit->GetPositionZ() < minZ || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::SearchUnitInBoundedPlane(UF::AreaTriggerBoundedPlane const& boundedPlane, std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (m_areaTriggerData->MorphCurveId)
        progress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsX = G3D::lerp(boundedPlane.Extents->Pos.GetPositionX(), boundedPlane.ExtentsTarget->Pos.GetPositionX(), progress) * scale;
    float extentsY = G3D::lerp(boundedPlane.Extents->Pos.GetPositionY(), boundedPlane.ExtentsTarget->Pos.GetPositionY(), progress) * scale;
    float radius = std::sqrt(extentsX * extentsX + extentsY * extentsY);

    SearchUnits(targetList, radius, false);

    Position const& boxCenter = GetPosition();
    Trinity::Containers::EraseIf(targetList, [boxCenter, extentsX, extentsY](Unit const* unit) -> bool
    {
        return !unit->IsWithinBox(boxCenter, extentsX, extentsY, MAP_SIZE);
    });
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

    if (canTriggerOnExit)
        _ai->OnUnitExit(unit, exitMode);

    unit->ExitAreaTrigger(this);
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
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::Extents), shapeData.Extents);
            SetUpdateFieldValue(boundedPlane.ModifyValue(&UF::AreaTriggerBoundedPlane::ExtentsTarget), shapeData.ExtentsTarget);
        }
        else
            static_assert(Trinity::dependant_false_v<ShapeType>, "Unsupported shape type");
    }, shape.Data);
}

float AreaTrigger::GetMaxSearchRadius() const
{
    return *m_areaTriggerData->BoundsRadius2D * CalcCurrentScale();
}

void AreaTrigger::UpdatePolygonVertices()
{
    UF::AreaTriggerPolygon const* shape = m_areaTriggerData->ShapeData.Get<UF::AreaTriggerPolygon>();
    float newOrientation = GetOrientation();

    // No need to recalculate, orientation didn't change
    if (G3D::fuzzyEq(_verticesUpdatePreviousOrientation, newOrientation) && shape->VerticesTarget.empty())
        return;

    _polygonVertices.assign(shape->Vertices.begin(), shape->Vertices.end());
    if (!shape->VerticesTarget.empty())
    {
        float progress = GetProgress();
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

    float angleSin = std::sin(newOrientation);
    float angleCos = std::cos(newOrientation);

    // This is needed to rotate the vertices, following orientation
    for (Position& vertice : _polygonVertices)
    {
        float x = vertice.GetPositionX() * angleCos - vertice.GetPositionY() * angleSin;
        float y = vertice.GetPositionY() * angleCos + vertice.GetPositionX() * angleSin;
        vertice.Relocate(x, y);
    }

    _verticesUpdatePreviousOrientation = newOrientation;
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

    std::unique_ptr<Movement::Spline<float>> spline = std::make_unique<::Movement::Spline<float>>();
    spline->init_spline(splinePoints.data(), splinePoints.size(), ::Movement::SplineBase::ModeLinear, _stationaryPosition.GetOrientation());
    spline->initLengths();

    float speed = overrideSpeed.value_or(GetCreateProperties()->Speed);
    if (speed <= 0.0f)
        speed = 1.0f;

    uint32 timeToTarget = (speedIsTimeInSeconds.value_or(GetCreateProperties()->SpeedIsTime)
        ? speed
        : spline->length() / speed) * static_cast<float>(IN_MILLISECONDS);

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::MovementStartTime), GameTime::GetGameTimeMS());

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::Spline));
    auto pathData = areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathData, UF::VariantCase<UF::AreaTriggerSplineCalculator>);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerSplineCalculator::Catmullrom), spline->getPointCount() >= 4);
    auto points = pathData.ModifyValue(&UF::AreaTriggerSplineCalculator::Points);
    ClearDynamicUpdateFieldValues(points);
    for (G3D::Vector3 const& point : spline->getPoints())
        AddDynamicUpdateFieldValue(points) = Vector3ToPosition(point);

    _reachedDestination = false;
    _spline = std::move(spline);
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

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathType), int32(AreaTriggerPathType::Orbit));
    auto pathData = areaTriggerData.ModifyValue(&UF::AreaTriggerData::PathData, UF::VariantCase<UF::AreaTriggerOrbit>);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::CounterClockwise), orbit.CounterClockwise);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::Center), orbit.Center.value_or(Position()));
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::Radius), orbit.Radius);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::InitialAngle), orbit.InitialAngle);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::BlendFromRadius), orbit.BlendFromRadius);
    SetUpdateFieldValue(pathData.ModifyValue(&UF::AreaTriggerOrbit::ExtraTimeForBlending), orbit.ExtraTimeForBlending);
}

Position const* AreaTrigger::GetOrbitCenterPosition() const
{
    UF::AreaTriggerOrbit const* orbit = m_areaTriggerData->PathData.Get<UF::AreaTriggerOrbit>();
    if (!orbit)
        return nullptr;

    if (!m_areaTriggerData->OrbitPathTarget->IsEmpty())
        if (WorldObject* center = ObjectAccessor::GetWorldObject(*this, *m_areaTriggerData->OrbitPathTarget))
            return center;

    return &orbit->Center->Pos;
}

Position AreaTrigger::CalculateOrbitPosition() const
{
    Position const* centerPos = GetOrbitCenterPosition();
    if (!centerPos)
        return GetPosition();

    UF::AreaTriggerOrbit const& cmi = *m_areaTriggerData->PathData.Get<UF::AreaTriggerOrbit>();

    // AreaTrigger make exactly "Duration / TimeToTarget" loops during his life time
    float pathProgress = float(GetElapsedTimeForMovement() + *cmi.ExtraTimeForBlending) / float(GetTimeToTarget());
    if (m_areaTriggerData->MoveCurveId)
        pathProgress = sDB2Manager.GetCurveValueAt(m_areaTriggerData->MoveCurveId, pathProgress);

    // We already made one circle and can't loop
    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::CanLoop))
        pathProgress = std::min(1.f, pathProgress);

    float radius = cmi.Radius;
    if (pathProgress <= 1.0f && G3D::fuzzyNe(cmi.BlendFromRadius, radius))
    {
        float blendCurve = (cmi.BlendFromRadius - radius) / radius;
        RoundToInterval(blendCurve, 1.f, 4.f);
        float blendProgress = std::min(1.f, pathProgress / blendCurve * 0.63661975f);
        radius = G3D::lerp(cmi.BlendFromRadius, radius, blendProgress);
    }

    // Adapt Path progress depending of circle direction
    if (!cmi.CounterClockwise)
        pathProgress *= -1;

    float angle = cmi.InitialAngle + 2.f * float(M_PI) * pathProgress;
    float x = centerPos->GetPositionX() + (radius * std::cos(angle));
    float y = centerPos->GetPositionY() + (radius * std::sin(angle));
    float z = centerPos->GetPositionZ() + *m_areaTriggerData->ZOffset;

    float orientation = 0.0f;
    if (m_areaTriggerData->FacingCurveId)
        orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetProgress());

    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
    {
        orientation += angle;
        orientation += cmi.CounterClockwise ? float(M_PI_4) : -float(M_PI_4);
    }

    return { x, y, z, orientation };
}

void AreaTrigger::UpdateOrbitPosition()
{
    Position pos = CalculateOrbitPosition();

    GetMap()->AreaTriggerRelocation(this, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
#ifdef TRINITY_DEBUG
    DebugVisualizePosition();
#endif
}

void AreaTrigger::UpdateSplinePosition(Movement::Spline<float>& spline)
{
    if (_reachedDestination)
        return;

    if (GetElapsedTimeForMovement() >= GetTimeToTarget())
    {
        _reachedDestination = true;
        _lastSplineIndex = int32(spline.last());

        G3D::Vector3 lastSplinePosition = spline.getPoint(_lastSplineIndex);
        GetMap()->AreaTriggerRelocation(this, lastSplinePosition.x, lastSplinePosition.y, lastSplinePosition.z, GetOrientation());
#ifdef TRINITY_DEBUG
        DebugVisualizePosition();
#endif

        _ai->OnSplineIndexReached(_lastSplineIndex);
        _ai->OnDestinationReached();
        return;
    }

    float currentTimePercent = float(GetElapsedTimeForMovement()) / float(GetTimeToTarget());

    if (currentTimePercent <= 0.f)
        return;

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
    spline.computeIndex(currentTimePercent, lastPositionIndex, percentFromLastPoint);

    G3D::Vector3 currentPosition;
    spline.evaluate_percent(lastPositionIndex, percentFromLastPoint, currentPosition);

    float orientation = _stationaryPosition.GetOrientation();
    if (m_areaTriggerData->FacingCurveId)
        orientation += sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetProgress());

    if (!HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation) && HasAreaTriggerFlag(AreaTriggerFieldFlags::FaceMovementDir))
    {
        G3D::Vector3 derivative;
        spline.evaluate_derivative(lastPositionIndex, percentFromLastPoint, derivative);
        if (derivative.x != 0.0f || derivative.y != 0.0f)
            orientation += std::atan2(derivative.y, derivative.x);
    }

    GetMap()->AreaTriggerRelocation(this, currentPosition.x, currentPosition.y, currentPosition.z, orientation);
#ifdef TRINITY_DEBUG
    DebugVisualizePosition();
#endif

    if (_lastSplineIndex != lastPositionIndex)
    {
        _lastSplineIndex = lastPositionIndex;
        _ai->OnSplineIndexReached(_lastSplineIndex);
    }
}

void AreaTrigger::UpdateOverridePosition()
{
    float progress = GetScaleCurveProgress(*m_areaTriggerData->OverrideMoveCurveX, m_areaTriggerData->TimeToTargetPos);

    float x = GetScaleCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveX, progress);
    float y = GetScaleCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveY, progress);
    float z = GetScaleCurveValueAtProgress(*m_areaTriggerData->OverrideMoveCurveZ, progress);
    float orientation = GetOrientation();

    if (m_areaTriggerData->FacingCurveId)
    {
        orientation = sDB2Manager.GetCurveValueAt(m_areaTriggerData->FacingCurveId, GetProgress());
        if (HasAreaTriggerFlag(AreaTriggerFieldFlags::AbsoluteOrientation))
            orientation += m_areaTriggerData->Facing;
    }

    GetMap()->AreaTriggerRelocation(this, x, y, z, orientation);
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
                player->SummonCreature(1, *this, TEMPSUMMON_TIMED_DESPAWN, Milliseconds(GetTimeToTarget()));
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

void AreaTrigger::BuildValuesCreate(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const
{
    m_objectData->WriteCreate(*data, flags, this, target);
    m_areaTriggerData->WriteCreate(*data, flags, this, target);
}

void AreaTrigger::BuildValuesUpdate(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const
{
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_AREATRIGGER))
        m_areaTriggerData->WriteUpdate(*data, flags, this, target);
}

void AreaTrigger::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::AreaTriggerData::Mask const& requestedAreaTriggerMask, Player const* target) const
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
    BuildEntityFragmentsForValuesUpdateForPlayerWithMask(&buffer, flags);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_AREATRIGGER])
        m_areaTriggerData->WriteUpdate(buffer, requestedAreaTriggerMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void AreaTrigger::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), AreaTriggerMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void AreaTrigger::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&AreaTrigger::m_areaTriggerData);
    Object::ClearUpdateMask(remove);
}
