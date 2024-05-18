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
#include "GridNotifiersImpl.h"
#include "Language.h"
#include "Log.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
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
    _duration(0), _totalDuration(0), _timeSinceCreated(0), _verticesUpdatePreviousOrientation(std::numeric_limits<float>::infinity()),
    _isRemoved(false), _reachedDestination(true), _lastSplineIndex(0), _movementTime(0),
    _areaTriggerCreateProperties(nullptr), _areaTriggerTemplate(nullptr)
{
    m_objectType |= TYPEMASK_AREATRIGGER;
    m_objectTypeId = TYPEID_AREATRIGGER;

    m_updateFlag.Stationary = true;
    m_updateFlag.AreaTrigger = true;
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

        GetMap()->GetObjectsStore().Insert<AreaTrigger>(GetGUID(), this);
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
        HandleUnitEnterExit({});

        WorldObject::RemoveFromWorld();

        if (IsStaticSpawn())
            Trinity::Containers::MultimapErasePair(GetMap()->GetAreaTriggerBySpawnIdStore(), _spawnId, this);
        GetMap()->GetObjectsStore().Remove<AreaTrigger>(GetGUID());
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

    _shape = GetCreateProperties()->Shape;

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
            spellVisual.SpellXSpellVisualID = spellForVisuals->GetSpellXSpellVisualId();
    }
    if (spellForVisuals)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellForVisuals), spellForVisuals->Id);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellXSpellVisualID), spellVisual.SpellXSpellVisualID);
    if (!IsStaticSpawn())
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), GetCreateProperties()->TimeToTargetScale != 0 ? GetCreateProperties()->TimeToTargetScale : *m_areaTriggerData->Duration);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::BoundsRadius2D), GetCreateProperties()->Shape.GetMaxSearchRadius());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), GetCreateProperties()->DecalPropertiesId);
    if (IsServerSide())
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), 24); // Blue decal, for .debug areatrigger visibility

    AreaTriggerScaleCurveTemplate const extraScaleCurve = IsStaticSpawn() ? AreaTriggerScaleCurveTemplate() : *GetCreateProperties()->ExtraScale;
    SetScaleCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve), extraScaleCurve);

    if (caster)
    {
        if (Player const* modOwner = caster->GetSpellModOwner())
        {
            float multiplier = 1.0f;
            int32 flat = 0;
            modOwner->GetSpellModValues(spellInfo, SpellModOp::Radius, spell, *m_areaTriggerData->BoundsRadius2D, &flat, &multiplier);
            if (multiplier != 1.0f)
            {
                AreaTriggerScaleCurveTemplate overrideScale;
                overrideScale.Curve = multiplier;
                SetScaleCurve(areaTriggerData.ModifyValue(&UF::AreaTriggerData::OverrideScaleCurve), overrideScale);
            }
        }
    }

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimationDataID), GetCreateProperties()->AnimId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimKitID), GetCreateProperties()->AnimKitId);
    if (GetCreateProperties() && GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::Unk3))
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::Field_C), true);

    if (caster)
        PhasingHandler::InheritPhaseShift(this, caster);
    else if (IsStaticSpawn() && spawnData)
    {
        if (spawnData->phaseUseFlags || spawnData->phaseId || spawnData->phaseGroup)
            PhasingHandler::InitDbPhaseShift(GetPhaseShift(), spawnData->phaseUseFlags, spawnData->phaseId, spawnData->phaseGroup);
    }

    if (target && GetCreateProperties() && GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAttached))
        m_movementInfo.transport.guid = target->GetGUID();

    if (!IsStaticSpawn())
        UpdatePositionData();

    UpdateShape();

    uint32 timeToTarget = GetCreateProperties()->TimeToTarget != 0 ? GetCreateProperties()->TimeToTarget : *m_areaTriggerData->Duration;

    if (GetCreateProperties()->OrbitInfo)
    {
        AreaTriggerOrbitInfo orbit = *GetCreateProperties()->OrbitInfo;
        if (target && GetCreateProperties() && GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAttached))
            orbit.PathTarget = target->GetGUID();
        else
            orbit.Center = pos;

        InitOrbit(orbit, timeToTarget);
    }
    else if (GetCreateProperties()->HasSplines())
    {
        InitSplineOffsets(GetCreateProperties()->SplinePoints, timeToTarget);
    }

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
    _timeSinceCreated += diff;

    if (!IsStaticSpawn())
    {
        // "If" order matter here, Orbit > Attached > Splines
        if (HasOverridePosition())
        {
            UpdateOverridePosition();
        }
        else if (HasOrbit())
        {
            UpdateOrbitPosition(diff);
        }
        else if (GetCreateProperties() && GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAttached))
        {
            if (Unit* target = GetTarget())
            {
                float orientation = 0.0f;
                if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
                    if (createProperties->FacingCurveId)
                        orientation = sDB2Manager.GetCurveValueAt(createProperties->FacingCurveId, GetProgress());

                if (!GetCreateProperties() || !GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation))
                    orientation += target->GetOrientation();

                GetMap()->AreaTriggerRelocation(this, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), orientation);
            }
        }
        else if (HasSplines())
        {
            UpdateSplinePosition(diff);
        }
        else
        {
            if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
            {
                if (createProperties->FacingCurveId)
                {
                    float orientation = sDB2Manager.GetCurveValueAt(createProperties->FacingCurveId, GetProgress());
                    if (!GetCreateProperties() || !GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation))
                        orientation += GetStationaryO();

                    SetOrientation(orientation);
                }
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
    else if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->ScaleCurveId)
            scale *= std::max(sDB2Manager.GetCurveValueAt(createProperties->ScaleCurveId, GetScaleCurveProgress(*m_areaTriggerData->OverrideScaleCurve, m_areaTriggerData->TimeToTargetScale)), 0.000001f);

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
    AreaTriggerScaleCurveTemplate curveTemplate;
    curveTemplate.Curve = constantValue;
    SetScaleCurve(scaleCurveMutator, curveTemplate);
}

void AreaTrigger::SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, std::array<DBCPosition2D, 2> const& points,
    Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation)
{
    AreaTriggerScaleCurvePointsTemplate curve;
    curve.Mode = interpolation;
    curve.Points = points;

    AreaTriggerScaleCurveTemplate curveTemplate;
    curveTemplate.StartTimeOffset = startTimeOffset.value_or(GetTimeSinceCreated());
    curveTemplate.Curve = curve;

    SetScaleCurve(scaleCurveMutator, curveTemplate);
}

void AreaTrigger::ClearScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator)
{
    SetScaleCurve(scaleCurveMutator, {});
}

void AreaTrigger::SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, Optional<AreaTriggerScaleCurveTemplate> const& curve)
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
    else if (AreaTriggerScaleCurvePointsTemplate const* curvePoints = std::get_if<AreaTriggerScaleCurvePointsTemplate>(&curve->Curve))
    {
        CurveInterpolationMode mode = curvePoints->Mode;
        if (curvePoints->Points[1].X < curvePoints->Points[0].X)
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

        for (std::size_t i = 0; i < curvePoints->Points.size(); ++i)
        {
            point.Relocate(curvePoints->Points[i].X, curvePoints->Points[i].Y);
            SetUpdateFieldValue(scaleCurveMutator.ModifyValue(&UF::ScaleCurve::Points, i), point);
        }
    }
}

void AreaTrigger::UpdateTargetList()
{
    std::vector<Unit*> targetList;

    switch (_shape.Type)
    {
        case AreaTriggerShapeType::Sphere:
            SearchUnitInSphere(targetList);
            break;
        case AreaTriggerShapeType::Box:
            SearchUnitInBox(targetList);
            break;
        case AreaTriggerShapeType::Polygon:
            SearchUnitInPolygon(targetList);
            break;
        case AreaTriggerShapeType::Cylinder:
            SearchUnitInCylinder(targetList);
            break;
        case AreaTriggerShapeType::Disk:
            SearchUnitInDisk(targetList);
            break;
        case AreaTriggerShapeType::BoundedPlane:
            SearchUnitInBoundedPlane(targetList);
            break;
        default:
            break;
    }

    if (GetTemplate())
    {
        if (ConditionContainer const* conditions = sConditionMgr->GetConditionsForAreaTrigger(GetTemplate()->Id.Id, GetTemplate()->Id.IsCustom))
        {
            Trinity::Containers::EraseIf(targetList, [conditions](Unit const* target)
            {
                return !sConditionMgr->IsObjectMeetToConditions(target, *conditions);
            });
        }
    }

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnits(std::vector<Unit*>& targetList, float radius, bool check3D)
{
    Trinity::AnyUnitInObjectRangeCheck check(this, radius, check3D);
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

void AreaTrigger::SearchUnitInSphere(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(_shape.SphereDatas.Radius, _shape.SphereDatas.RadiusTarget, progress) * scale;

    SearchUnits(targetList, radius, true);
}

void AreaTrigger::SearchUnitInBox(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsX = G3D::lerp(_shape.BoxDatas.Extents[0], _shape.BoxDatas.ExtentsTarget[0], progress) * scale;
    float extentsY = G3D::lerp(_shape.BoxDatas.Extents[1], _shape.BoxDatas.ExtentsTarget[1], progress) * scale;
    float extentsZ = G3D::lerp(_shape.BoxDatas.Extents[2], _shape.BoxDatas.ExtentsTarget[2], progress) * scale;
    float radius = std::sqrt(extentsX * extentsX + extentsY * extentsY);

    SearchUnits(targetList, radius, false);

    Position const& boxCenter = GetPosition();
    Trinity::Containers::EraseIf(targetList, [boxCenter, extentsX, extentsY, extentsZ](Unit const* unit) -> bool
    {
        return !unit->IsWithinBox(boxCenter, extentsX, extentsY, extentsZ / 2);
    });
}

void AreaTrigger::SearchUnitInPolygon(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float height = G3D::lerp(_shape.PolygonDatas.Height, _shape.PolygonDatas.HeightTarget, progress);
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, GetMaxSearchRadius(), false);

    Trinity::Containers::EraseIf(targetList, [this, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ
            || !CheckIsInPolygon2D(unit);
    });
}

void AreaTrigger::SearchUnitInCylinder(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float radius = G3D::lerp(_shape.CylinderDatas.Radius, _shape.CylinderDatas.RadiusTarget, progress) * scale;
    float height = G3D::lerp(_shape.CylinderDatas.Height, _shape.CylinderDatas.HeightTarget, progress) * scale;

    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, radius, false);

    Trinity::Containers::EraseIf(targetList, [minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::SearchUnitInDisk(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float innerRadius = G3D::lerp(_shape.DiskDatas.InnerRadius, _shape.DiskDatas.InnerRadiusTarget, progress) * scale;
    float outerRadius = G3D::lerp(_shape.DiskDatas.OuterRadius, _shape.DiskDatas.OuterRadiusTarget, progress) * scale;
    float height = G3D::lerp(_shape.DiskDatas.Height, _shape.DiskDatas.HeightTarget, progress) * scale;

    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    SearchUnits(targetList, outerRadius, false);

    Trinity::Containers::EraseIf(targetList, [this, innerRadius, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->IsInDist2d(this, innerRadius) || unit->GetPositionZ() < minZ || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::SearchUnitInBoundedPlane(std::vector<Unit*>& targetList)
{
    float progress = GetProgress();
    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

    float scale = CalcCurrentScale();
    float extentsX = G3D::lerp(_shape.BoundedPlaneDatas.Extents[0], _shape.BoundedPlaneDatas.ExtentsTarget[0], progress) * scale;
    float extentsY = G3D::lerp(_shape.BoundedPlaneDatas.Extents[1], _shape.BoundedPlaneDatas.ExtentsTarget[1], progress) * scale;
    float radius = std::sqrt(extentsX * extentsX + extentsY * extentsY);

    SearchUnits(targetList, radius, false);

    Position const& boxCenter = GetPosition();
    Trinity::Containers::EraseIf(targetList, [boxCenter, extentsX, extentsY](Unit const* unit) -> bool
    {
        return !unit->IsWithinBox(boxCenter, extentsX, extentsY, MAP_SIZE);
    });
}

void AreaTrigger::HandleUnitEnterExit(std::vector<Unit*> const& newTargetList)
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
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->isDebugAreaTriggers)
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTITY_ENTERED, GetEntry(), IsCustom(), IsStaticSpawn(), _spawnId);

            player->UpdateQuestObjectiveProgress(QUEST_OBJECTIVE_AREA_TRIGGER_ENTER, GetEntry(), 1);
        }

        DoActions(unit);

        _ai->OnUnitEnter(unit);
    }

    for (ObjectGuid const& exitUnitGuid : exitUnits)
    {
        if (Unit* leavingUnit = ObjectAccessor::GetUnit(*this, exitUnitGuid))
        {
            if (Player* player = leavingUnit->ToPlayer())
            {
                if (player->isDebugAreaTriggers)
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTITY_LEFT, GetEntry(), IsCustom(), IsStaticSpawn(), _spawnId);

                player->UpdateQuestObjectiveProgress(QUEST_OBJECTIVE_AREA_TRIGGER_EXIT, GetEntry(), 1);
            }

            UndoActions(leavingUnit);

            _ai->OnUnitExit(leavingUnit);
        }
    }
}

AreaTriggerTemplate const* AreaTrigger::GetTemplate() const
{
    return _areaTriggerTemplate;
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

float AreaTrigger::GetMaxSearchRadius() const
{
    return *m_areaTriggerData->BoundsRadius2D * CalcCurrentScale();
}

void AreaTrigger::UpdatePolygonVertices()
{
    AreaTriggerCreateProperties const* createProperties = GetCreateProperties();
    AreaTriggerShapeInfo const& shape = GetShape();
    float newOrientation = GetOrientation();

    // No need to recalculate, orientation didn't change
    if (G3D::fuzzyEq(_verticesUpdatePreviousOrientation, newOrientation) && shape.PolygonVerticesTarget.empty())
        return;

    _polygonVertices.assign(shape.PolygonVertices.begin(), shape.PolygonVertices.end());
    if (!shape.PolygonVerticesTarget.empty())
    {
        float progress = GetProgress();
        if (createProperties->MorphCurveId)
            progress = sDB2Manager.GetCurveValueAt(createProperties->MorphCurveId, progress);

        for (std::size_t i = 0; i < _polygonVertices.size(); ++i)
        {
            Position& vertex = _polygonVertices[i];
            Position const& vertexTarget = shape.PolygonVerticesTarget[i].Pos;

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

bool AreaTrigger::CheckIsInPolygon2D(Position const* pos) const
{
    float testX = pos->GetPositionX();
    float testY = pos->GetPositionY();

    //this method uses the ray tracing algorithm to determine if the point is in the polygon
    bool locatedInPolygon = false;

    for (std::size_t vertex = 0; vertex < _polygonVertices.size(); ++vertex)
    {
        std::size_t nextVertex;

        //repeat loop for all sets of points
        if (vertex == (_polygonVertices.size() - 1))
        {
            //if i is the last vertex, let j be the first vertex
            nextVertex = 0;
        }
        else
        {
            //for all-else, let j=(i+1)th vertex
            nextVertex = vertex + 1;
        }

        float vertX_i = GetPositionX() + _polygonVertices[vertex].GetPositionX();
        float vertY_i = GetPositionY() + _polygonVertices[vertex].GetPositionY();
        float vertX_j = GetPositionX() + _polygonVertices[nextVertex].GetPositionX();
        float vertY_j = GetPositionY() + _polygonVertices[nextVertex].GetPositionY();

        // following statement checks if testPoint.Y is below Y-coord of i-th vertex
        bool belowLowY = vertY_i > testY;
        // following statement checks if testPoint.Y is below Y-coord of i+1-th vertex
        bool belowHighY = vertY_j > testY;

        /* following statement is true if testPoint.Y satisfies either (only one is possible)
        -->(i).Y < testPoint.Y < (i+1).Y        OR
        -->(i).Y > testPoint.Y > (i+1).Y

        (Note)
        Both of the conditions indicate that a point is located within the edges of the Y-th coordinate
        of the (i)-th and the (i+1)- th vertices of the polygon. If neither of the above
        conditions is satisfied, then it is assured that a semi-infinite horizontal line draw
        to the right from the testpoint will NOT cross the line that connects vertices i and i+1
        of the polygon
        */
        bool withinYsEdges = belowLowY != belowHighY;

        if (withinYsEdges)
        {
            // this is the slope of the line that connects vertices i and i+1 of the polygon
            float slopeOfLine = (vertX_j - vertX_i) / (vertY_j - vertY_i);

            // this looks up the x-coord of a point lying on the above line, given its y-coord
            float pointOnLine = (slopeOfLine* (testY - vertY_i)) + vertX_i;

            //checks to see if x-coord of testPoint is smaller than the point on the line with the same y-coord
            bool isLeftToLine = testX < pointOnLine;

            if (isLeftToLine)
            {
                //this statement changes true to false (and vice-versa)
                locatedInPolygon = !locatedInPolygon;
            }//end if (isLeftToLine)
        }//end if (withinYsEdges
    }

    return locatedInPolygon;
}

bool AreaTrigger::HasOverridePosition() const
{
    return m_areaTriggerData->OverrideMoveCurveX->OverrideActive
        && m_areaTriggerData->OverrideMoveCurveY->OverrideActive
        && m_areaTriggerData->OverrideMoveCurveZ->OverrideActive;
}

void AreaTrigger::UpdateShape()
{
    if (_shape.IsPolygon())
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
        for (AreaTriggerAction const& action : GetTemplate()->Actions)
            if (action.ActionType == AREATRIGGER_ACTION_CAST || action.ActionType == AREATRIGGER_ACTION_ADDAURA)
                unit->RemoveAurasDueToSpell(action.Param, GetCasterGuid());
}

void AreaTrigger::InitSplineOffsets(std::vector<Position> const& offsets, uint32 timeToTarget)
{
    float angleSin = std::sin(GetOrientation());
    float angleCos = std::cos(GetOrientation());

    // This is needed to rotate the spline, following caster orientation
    std::vector<G3D::Vector3> rotatedPoints;
    rotatedPoints.reserve(offsets.size());
    for (Position const& offset : offsets)
    {
        float x = GetPositionX() + (offset.GetPositionX() * angleCos - offset.GetPositionY() * angleSin);
        float y = GetPositionY() + (offset.GetPositionY() * angleCos + offset.GetPositionX() * angleSin);
        float z = GetPositionZ();

        UpdateAllowedPositionZ(x, y, z);
        z += offset.GetPositionZ();

        rotatedPoints.emplace_back(x, y, z);
    }

    InitSplines(std::move(rotatedPoints), timeToTarget);
}

void AreaTrigger::InitSplines(std::vector<G3D::Vector3> splinePoints, uint32 timeToTarget)
{
    if (splinePoints.size() < 2)
        return;

    _movementTime = 0;

    _spline = std::make_unique<::Movement::Spline<int32>>();
    _spline->init_spline(&splinePoints[0], splinePoints.size(), ::Movement::SplineBase::ModeLinear);
    _spline->initLengths();

    // should be sent in object create packets only
    DoWithSuppressingObjectUpdates([&]()
    {
        SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
        const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::TimeToTarget);
    });

    if (IsInWorld())
    {
        if (_reachedDestination)
        {
            WorldPackets::AreaTrigger::AreaTriggerRePath reshape;
            reshape.TriggerGUID = GetGUID();
            SendMessageToSet(reshape.Write(), true);
        }

        WorldPackets::AreaTrigger::AreaTriggerRePath reshape;
        reshape.TriggerGUID = GetGUID();
        reshape.AreaTriggerSpline.emplace();
        reshape.AreaTriggerSpline->ElapsedTimeForMovement = GetElapsedTimeForMovement();
        reshape.AreaTriggerSpline->TimeToTarget = timeToTarget;
        for (G3D::Vector3 const& vec : splinePoints)
            reshape.AreaTriggerSpline->Points.emplace_back(vec.x, vec.y, vec.z);

        SendMessageToSet(reshape.Write(), true);
    }

    _reachedDestination = false;
}

bool AreaTrigger::HasSplines() const
{
    return bool(_spline);
}

void AreaTrigger::InitOrbit(AreaTriggerOrbitInfo const& orbit, uint32 timeToTarget)
{
    // Circular movement requires either a center position or an attached unit
    ASSERT(orbit.Center.has_value() || orbit.PathTarget.has_value());

    // should be sent in object create packets only
    DoWithSuppressingObjectUpdates([&]()
    {
        SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
        const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::TimeToTarget);
    });

    SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::OrbitPathTarget), orbit.PathTarget.value_or(ObjectGuid::Empty));

    _orbitInfo = orbit;

    _orbitInfo->TimeToTarget = timeToTarget;
    _orbitInfo->ElapsedTimeForMovement = 0;

    if (IsInWorld())
    {
        WorldPackets::AreaTrigger::AreaTriggerRePath reshape;
        reshape.TriggerGUID = GetGUID();
        reshape.AreaTriggerOrbit = _orbitInfo;

        SendMessageToSet(reshape.Write(), true);
    }
}

bool AreaTrigger::HasOrbit() const
{
    return _orbitInfo.has_value();
}

Position const* AreaTrigger::GetOrbitCenterPosition() const
{
    if (!_orbitInfo)
        return nullptr;

    if (_orbitInfo->PathTarget)
        if (WorldObject* center = ObjectAccessor::GetWorldObject(*this, *_orbitInfo->PathTarget))
            return center;

    if (_orbitInfo->Center)
        return &_orbitInfo->Center->Pos;

    return nullptr;
}

Position AreaTrigger::CalculateOrbitPosition() const
{
    Position const* centerPos = GetOrbitCenterPosition();
    if (!centerPos)
        return GetPosition();

    AreaTriggerCreateProperties const* createProperties = GetCreateProperties();
    AreaTriggerOrbitInfo const& cmi = *_orbitInfo;

    // AreaTrigger make exactly "Duration / TimeToTarget" loops during his life time
    float pathProgress = float(cmi.ElapsedTimeForMovement) / float(cmi.TimeToTarget);
    if (createProperties && createProperties->MoveCurveId)
        pathProgress = sDB2Manager.GetCurveValueAt(createProperties->MoveCurveId, pathProgress);

    // We already made one circle and can't loop
    if (!cmi.CanLoop)
        pathProgress = std::min(1.f, pathProgress);

    float radius = cmi.Radius;
    if (G3D::fuzzyNe(cmi.BlendFromRadius, radius))
    {
        float blendCurve = (cmi.BlendFromRadius - radius) / radius;
        // 4.f Defines four quarters
        blendCurve = RoundToInterval(blendCurve, 1.f, 4.f) / 4.f;
        float blendProgress = std::min(1.f, pathProgress / blendCurve);
        radius = G3D::lerp(cmi.BlendFromRadius, cmi.Radius, blendProgress);
    }

    // Adapt Path progress depending of circle direction
    if (!cmi.CounterClockwise)
        pathProgress *= -1;

    float angle = cmi.InitialAngle + 2.f * float(M_PI) * pathProgress;
    float x = centerPos->GetPositionX() + (radius * std::cos(angle));
    float y = centerPos->GetPositionY() + (radius * std::sin(angle));
    float z = centerPos->GetPositionZ() + cmi.ZOffset;

    float orientation = 0.0f;
    if (createProperties && createProperties->FacingCurveId)
        orientation = sDB2Manager.GetCurveValueAt(createProperties->FacingCurveId, GetProgress());

    if (!GetCreateProperties() || !GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation))
    {
        orientation += angle;
        orientation += cmi.CounterClockwise ? float(M_PI_4) : -float(M_PI_4);
    }

    return { x, y, z, orientation };
}

void AreaTrigger::UpdateOrbitPosition(uint32 /*diff*/)
{
    if (_orbitInfo->StartDelay > GetElapsedTimeForMovement())
        return;

    _orbitInfo->ElapsedTimeForMovement = GetElapsedTimeForMovement() - _orbitInfo->StartDelay;

    Position pos = CalculateOrbitPosition();

    GetMap()->AreaTriggerRelocation(this, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
#ifdef TRINITY_DEBUG
    DebugVisualizePosition();
#endif
}

void AreaTrigger::UpdateSplinePosition(uint32 diff)
{
    if (_reachedDestination)
        return;

    _movementTime += diff;

    if (_movementTime >= GetTimeToTarget())
    {
        _reachedDestination = true;
        _lastSplineIndex = int32(_spline->last());

        G3D::Vector3 lastSplinePosition = _spline->getPoint(_lastSplineIndex);
        GetMap()->AreaTriggerRelocation(this, lastSplinePosition.x, lastSplinePosition.y, lastSplinePosition.z, GetOrientation());
#ifdef TRINITY_DEBUG
        DebugVisualizePosition();
#endif

        _ai->OnSplineIndexReached(_lastSplineIndex);
        _ai->OnDestinationReached();
        return;
    }

    float currentTimePercent = float(_movementTime) / float(GetTimeToTarget());

    if (currentTimePercent <= 0.f)
        return;

    AreaTriggerCreateProperties const* createProperties = GetCreateProperties();
    if (createProperties && createProperties->MoveCurveId)
    {
        float progress = sDB2Manager.GetCurveValueAt(createProperties->MoveCurveId, currentTimePercent);
        if (progress < 0.f || progress > 1.f)
        {
            TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (Id: {}, AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})) has wrong progress ({}) caused by curve calculation (MoveCurveId: {})",
                GetEntry(), createProperties->Id.Id, uint32(createProperties->Id.IsCustom), progress, createProperties->MoveCurveId);
        }
        else
            currentTimePercent = progress;
    }

    int lastPositionIndex = 0;
    float percentFromLastPoint = 0;
    _spline->computeIndex(currentTimePercent, lastPositionIndex, percentFromLastPoint);

    G3D::Vector3 currentPosition;
    _spline->evaluate_percent(lastPositionIndex, percentFromLastPoint, currentPosition);

    float orientation = GetStationaryO();
    if (createProperties && createProperties->FacingCurveId)
        orientation += sDB2Manager.GetCurveValueAt(createProperties->FacingCurveId, GetProgress());

    if (GetCreateProperties() && !GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation) && GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasFaceMovementDir))
    {
        G3D::Vector3 derivative;
        _spline->evaluate_derivative(lastPositionIndex, percentFromLastPoint, derivative);
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

    if (AreaTriggerCreateProperties const* createProperties = GetCreateProperties())
    {
        if (createProperties->FacingCurveId)
        {
            orientation = sDB2Manager.GetCurveValueAt(createProperties->FacingCurveId, GetProgress());
            if (!GetCreateProperties() || !GetCreateProperties()->Flags.HasFlag(AreaTriggerCreatePropertiesFlag::HasAbsoluteOrientation))
                orientation += GetStationaryO();
        }
    }

    GetMap()->AreaTriggerRelocation(this, x, y, z, orientation);
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

void AreaTrigger::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_areaTriggerData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AreaTrigger::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_AREATRIGGER))
        m_areaTriggerData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AreaTrigger::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::AreaTriggerData::Mask const& requestedAreaTriggerMask, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    if (requestedAreaTriggerMask.IsAnySet())
        valuesMask.Set(TYPEID_AREATRIGGER);

    ByteBuffer& buffer = PrepareValuesUpdateBuffer(data);
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
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
