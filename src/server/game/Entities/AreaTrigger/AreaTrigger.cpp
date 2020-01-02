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
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Language.h"
#include "Log.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Spline.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"
#include <G3D/AABox.h>

AreaTrigger::AreaTrigger() : WorldObject(false), MapObject(), _aurEff(nullptr),
    _duration(0), _totalDuration(0), _timeSinceCreated(0), _previousCheckOrientation(std::numeric_limits<float>::infinity()),
    _isRemoved(false), _reachedDestination(true), _lastSplineIndex(0), _movementTime(0),
    _areaTriggerMiscTemplate(nullptr), _ai()
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
        GetMap()->GetObjectsStore().Insert<AreaTrigger>(GetGUID(), this);
        WorldObject::AddToWorld();
    }
}

void AreaTrigger::RemoveFromWorld()
{
    ///- Remove the AreaTrigger from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        _isRemoved = true;

        if (Unit* caster = GetCaster())
            caster->_UnregisterAreaTrigger(this);

        // Handle removal of all units, calling OnUnitExit & deleting auras if needed
        HandleUnitEnterExit({});

        _ai->OnRemove();

        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<AreaTrigger>(GetGUID());
    }
}

bool AreaTrigger::Create(uint32 spellMiscId, Unit* caster, Unit* target, SpellInfo const* spell, Position const& pos, int32 duration, uint32 spellXSpellVisualId, ObjectGuid const& castId, AuraEffect const* aurEff)
{
    _targetGuid = target ? target->GetGUID() : ObjectGuid::Empty;
    _aurEff = aurEff;

    SetMap(caster->GetMap());
    Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (spellMiscId %u) not created. Invalid coordinates (X: %f Y: %f)", spellMiscId, GetPositionX(), GetPositionY());
        return false;
    }

    _areaTriggerMiscTemplate = sAreaTriggerDataStore->GetAreaTriggerMiscTemplate(spellMiscId);
    if (!_areaTriggerMiscTemplate)
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (spellMiscId %u) not created. Invalid areatrigger miscid (%u)", spellMiscId, spellMiscId);
        return false;
    }

    Object::_Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), GetTemplate()->Id, caster->GetMap()->GenerateLowGuid<HighGuid::AreaTrigger>()));

    SetEntry(GetTemplate()->Id);
    SetDuration(duration);

    SetObjectScale(1.0f);

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::Caster), caster->GetGUID());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::CreatingEffectGUID), castId);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellID), spell->Id);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellForVisuals), spell->Id);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellXSpellVisualID), spellXSpellVisualId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), GetMiscTemplate()->TimeToTargetScale != 0 ? GetMiscTemplate()->TimeToTargetScale : *m_areaTriggerData->Duration);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::BoundsRadius2D), GetTemplate()->MaxSearchRadius);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), GetMiscTemplate()->DecalPropertiesId);

    if (GetMiscTemplate()->ExtraScale.Data.Structured.StartTimeOffset)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::StartTimeOffset), GetMiscTemplate()->ExtraScale.Data.Structured.StartTimeOffset);
    if (GetMiscTemplate()->ExtraScale.Data.Structured.Points[0] || GetMiscTemplate()->ExtraScale.Data.Structured.Points[1])
    {
        Position point(GetMiscTemplate()->ExtraScale.Data.Structured.Points[0], GetMiscTemplate()->ExtraScale.Data.Structured.Points[1]);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::Points, 0), point);
    }
    if (GetMiscTemplate()->ExtraScale.Data.Structured.Points[2] || GetMiscTemplate()->ExtraScale.Data.Structured.Points[3])
    {
        Position point(GetMiscTemplate()->ExtraScale.Data.Structured.Points[2], GetMiscTemplate()->ExtraScale.Data.Structured.Points[3]);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::Points, 1), point);
    }
    if (GetMiscTemplate()->ExtraScale.Data.Raw[5])
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::ParameterCurve), GetMiscTemplate()->ExtraScale.Data.Raw[5]);
    if (GetMiscTemplate()->ExtraScale.Data.Structured.OverrideActive)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::OverrideActive), GetMiscTemplate()->ExtraScale.Data.Structured.OverrideActive);

    PhasingHandler::InheritPhaseShift(this, caster);

    if (target && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
    {
        m_movementInfo.transport.guid = target->GetGUID();
    }

    UpdateShape();

    uint32 timeToTarget = GetMiscTemplate()->TimeToTarget != 0 ? GetMiscTemplate()->TimeToTarget : *m_areaTriggerData->Duration;

    if (GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_CIRCULAR_MOVEMENT))
    {
        AreaTriggerCircularMovementInfo cmi = GetMiscTemplate()->CircularMovementInfo;
        if (target && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
            cmi.PathTarget = target->GetGUID();
        else
            cmi.Center = pos;

        InitCircularMovement(cmi, timeToTarget);
    }
    else if (GetMiscTemplate()->HasSplines())
    {
        InitSplineOffsets(GetMiscTemplate()->SplinePoints, timeToTarget);
    }

    // movement on transport of areatriggers on unit is handled by themself
    Transport* transport = m_movementInfo.transport.guid.IsEmpty() ? caster->GetTransport() : nullptr;
    if (transport)
    {
        float x, y, z, o;
        pos.GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        m_movementInfo.transport.pos.Relocate(x, y, z, o);

        // This object must be added to transport before adding to map for the client to properly display it
        transport->AddPassenger(this);
    }

    AI_Initialize();

    // Relocate areatriggers with circular movement again
    if (HasCircularMovement())
        Relocate(CalculateCircularMovementPosition());

    if (!GetMap()->AddToMap(this))
    {
        // Returning false will cause the object to be deleted - remove from transport
        if (transport)
            transport->RemovePassenger(this);
        return false;
    }

    caster->_RegisterAreaTrigger(this);

    _ai->OnCreate();

    return true;
}

AreaTrigger* AreaTrigger::CreateAreaTrigger(uint32 spellMiscId, Unit* caster, Unit* target, SpellInfo const* spell, Position const& pos, int32 duration, uint32 spellXSpellVisualId, ObjectGuid const& castId /*= ObjectGuid::Empty*/, AuraEffect const* aurEff /*= nullptr*/)
{
    AreaTrigger* at = new AreaTrigger();
    if (!at->Create(spellMiscId, caster, target, spell, pos, duration, spellXSpellVisualId, castId, aurEff))
    {
        delete at;
        return nullptr;
    }

    return at;
}

void AreaTrigger::Update(uint32 diff)
{
    WorldObject::Update(diff);
    _timeSinceCreated += diff;

    // "If" order matter here, Circular Movement > Attached > Splines
    if (HasCircularMovement())
    {
        UpdateCircularMovementPosition(diff);
    }
    else if (GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
    {
        if (Unit* target = GetTarget())
            GetMap()->AreaTriggerRelocation(this, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
    }
    else
        UpdateSplinePosition(diff);

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
    SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::Duration), _duration);
    const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::Duration);
}

float AreaTrigger::GetProgress() const
{
    return GetTimeSinceCreated() < GetTimeToTargetScale() ? float(GetTimeSinceCreated()) / float(GetTimeToTargetScale()) : 1.0f;
}

void AreaTrigger::UpdateTargetList()
{
    std::list<Unit*> targetList;

    switch (GetTemplate()->Type)
    {
        case AREATRIGGER_TYPE_SPHERE:
            SearchUnitInSphere(targetList);
            break;
        case AREATRIGGER_TYPE_BOX:
            SearchUnitInBox(targetList);
            break;
        case AREATRIGGER_TYPE_POLYGON:
            SearchUnitInPolygon(targetList);
            break;
        case AREATRIGGER_TYPE_CYLINDER:
            SearchUnitInCylinder(targetList);
            break;
        default:
            break;
    }

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnitInSphere(std::list<Unit*>& targetList)
{
    float radius = GetTemplate()->SphereDatas.Radius;
    if (GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_DYNAMIC_SHAPE))
    {
        if (GetMiscTemplate()->MorphCurveId)
        {
            radius = G3D::lerp(GetTemplate()->SphereDatas.Radius,
                GetTemplate()->SphereDatas.RadiusTarget,
                sDB2Manager.GetCurveValueAt(GetMiscTemplate()->MorphCurveId, GetProgress()));
        }
    }

    Trinity::AnyUnitInObjectRangeCheck check(this, radius);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    Cell::VisitAllObjects(this, searcher, GetTemplate()->MaxSearchRadius);
}

void AreaTrigger::SearchUnitInBox(std::list<Unit*>& targetList)
{
    float extentsX = GetTemplate()->BoxDatas.Extents[0];
    float extentsY = GetTemplate()->BoxDatas.Extents[1];
    float extentsZ = GetTemplate()->BoxDatas.Extents[2];

    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    Cell::VisitAllObjects(this, searcher, GetTemplate()->MaxSearchRadius);

    float halfExtentsX = extentsX / 2.0f;
    float halfExtentsY = extentsY / 2.0f;
    float halfExtentsZ = extentsZ / 2.0f;

    float minX = GetPositionX() - halfExtentsX;
    float maxX = GetPositionX() + halfExtentsX;

    float minY = GetPositionY() - halfExtentsY;
    float maxY = GetPositionY() + halfExtentsY;

    float minZ = GetPositionZ() - halfExtentsZ;
    float maxZ = GetPositionZ() + halfExtentsZ;

    G3D::AABox const box({ minX, minY, minZ }, { maxX, maxY, maxZ });

    targetList.remove_if([&box](Unit* unit) -> bool
    {
        return !box.contains({ unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ() });
    });
}

void AreaTrigger::SearchUnitInPolygon(std::list<Unit*>& targetList)
{
    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    Cell::VisitAllObjects(this, searcher, GetTemplate()->MaxSearchRadius);

    float height = GetTemplate()->PolygonDatas.Height;
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    targetList.remove_if([this, minZ, maxZ](Unit* unit) -> bool
    {
        return !CheckIsInPolygon2D(unit)
            || unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::SearchUnitInCylinder(std::list<Unit*>& targetList)
{
    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    Cell::VisitAllObjects(this, searcher, GetTemplate()->MaxSearchRadius);

    float height = GetTemplate()->CylinderDatas.Height;
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    targetList.remove_if([minZ, maxZ](Unit* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    });
}

void AreaTrigger::HandleUnitEnterExit(std::list<Unit*> const& newTargetList)
{
    GuidUnorderedSet exitUnits = _insideUnits;
    _insideUnits.clear();

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
            if (player->isDebugAreaTriggers)
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTERED, GetTemplate()->Id);

        DoActions(unit);

        _ai->OnUnitEnter(unit);
    }

    for (ObjectGuid const& exitUnitGuid : exitUnits)
    {
        if (Unit* leavingUnit = ObjectAccessor::GetUnit(*this, exitUnitGuid))
        {
            if (Player* player = leavingUnit->ToPlayer())
                if (player->isDebugAreaTriggers)
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_LEFT, GetTemplate()->Id);

            UndoActions(leavingUnit);

            _ai->OnUnitExit(leavingUnit);
        }
    }
}

AreaTriggerTemplate const* AreaTrigger::GetTemplate() const
{
    return _areaTriggerMiscTemplate->Template;
}

uint32 AreaTrigger::GetScriptId() const
{
    return GetTemplate()->ScriptId;
}

Unit* AreaTrigger::GetCaster() const
{
    return ObjectAccessor::GetUnit(*this, GetCasterGuid());
}

Unit* AreaTrigger::GetTarget() const
{
    return ObjectAccessor::GetUnit(*this, _targetGuid);
}

void AreaTrigger::UpdatePolygonOrientation()
{
    float newOrientation = GetOrientation();

    // No need to recalculate, orientation didn't change
    if (G3D::fuzzyEq(_previousCheckOrientation, newOrientation))
        return;

    _polygonVertices.assign(GetTemplate()->PolygonVertices.begin(), GetTemplate()->PolygonVertices.end());

    float angleSin = std::sin(newOrientation);
    float angleCos = std::cos(newOrientation);

    // This is needed to rotate the vertices, following orientation
    for (Position& vertice : _polygonVertices)
    {
        float x = vertice.GetPositionX() * angleCos - vertice.GetPositionY() * angleSin;
        float y = vertice.GetPositionY() * angleCos + vertice.GetPositionX() * angleSin;
        vertice.Relocate(x, y);
    }

    _previousCheckOrientation = newOrientation;
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

void AreaTrigger::UpdateShape()
{
    if (GetTemplate()->IsPolygon())
        UpdatePolygonOrientation();
}

bool UnitFitToActionRequirement(Unit* unit, Unit* caster, AreaTriggerAction const& action)
{
    switch (action.TargetType)
    {
        case AREATRIGGER_ACTION_USER_FRIEND:
        {
            return caster->_IsValidAssistTarget(unit, sSpellMgr->GetSpellInfo(action.Param));
        }
        case AREATRIGGER_ACTION_USER_ENEMY:
        {
            return caster->_IsValidAttackTarget(unit, sSpellMgr->GetSpellInfo(action.Param));
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
    if (Unit* caster = GetCaster())
    {
        for (AreaTriggerAction const& action : GetTemplate()->Actions)
        {
            if (UnitFitToActionRequirement(unit, caster, action))
            {
                switch (action.ActionType)
                {
                    case AREATRIGGER_ACTION_CAST:
                        caster->CastSpell(unit, action.Param, true);
                        break;
                    case AREATRIGGER_ACTION_ADDAURA:
                        caster->AddAura(action.Param, unit);
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

    _spline = Trinity::make_unique<::Movement::Spline<int32>>();
    _spline->init_spline(&splinePoints[0], splinePoints.size(), ::Movement::SplineBase::ModeLinear);
    _spline->initLengths();

    // should be sent in object create packets only
    SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
    const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::TimeToTarget);

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
        reshape.AreaTriggerSpline = boost::in_place();
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

void AreaTrigger::InitCircularMovement(AreaTriggerCircularMovementInfo const& cmi, uint32 timeToTarget)
{
    // Circular movement requires either a center position or an attached unit
    ASSERT(cmi.Center.is_initialized() || cmi.PathTarget.is_initialized());

    // should be sent in object create packets only
    SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget);
    const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::TimeToTarget);

    _circularMovementInfo = cmi;

    _circularMovementInfo->TimeToTarget = timeToTarget;
    _circularMovementInfo->ElapsedTimeForMovement = 0;

    if (IsInWorld())
    {
        WorldPackets::AreaTrigger::AreaTriggerRePath reshape;
        reshape.TriggerGUID = GetGUID();
        reshape.AreaTriggerCircularMovement = _circularMovementInfo;

        SendMessageToSet(reshape.Write(), true);
    }
}

bool AreaTrigger::HasCircularMovement() const
{
    return _circularMovementInfo.is_initialized();
}

Position const* AreaTrigger::GetCircularMovementCenterPosition() const
{
    if (!_circularMovementInfo.is_initialized())
        return nullptr;

    if (_circularMovementInfo->PathTarget.is_initialized())
        if (WorldObject* center = ObjectAccessor::GetWorldObject(*this, *_circularMovementInfo->PathTarget))
            return center;

    if (_circularMovementInfo->Center.is_initialized())
        return &_circularMovementInfo->Center->Pos;

    return nullptr;
}

Position AreaTrigger::CalculateCircularMovementPosition() const
{
    Position const* centerPos = GetCircularMovementCenterPosition();
    if (!centerPos)
        return GetPosition();

    AreaTriggerCircularMovementInfo const& cmi = *_circularMovementInfo;

    // AreaTrigger make exactly "Duration / TimeToTarget" loops during his life time
    float pathProgress = float(cmi.ElapsedTimeForMovement) / float(cmi.TimeToTarget);

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

    return { x, y, z, angle };
}

void AreaTrigger::UpdateCircularMovementPosition(uint32 /*diff*/)
{
    if (_circularMovementInfo->StartDelay > GetElapsedTimeForMovement())
        return;

    _circularMovementInfo->ElapsedTimeForMovement = GetElapsedTimeForMovement() - _circularMovementInfo->StartDelay;

    Position pos = CalculateCircularMovementPosition();

    GetMap()->AreaTriggerRelocation(this, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
#ifdef TRINITY_DEBUG
    DebugVisualizePosition();
#endif
}

void AreaTrigger::UpdateSplinePosition(uint32 diff)
{
    if (_reachedDestination)
        return;

    if (!HasSplines())
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

    if (GetMiscTemplate()->MoveCurveId)
    {
        float progress = sDB2Manager.GetCurveValueAt(GetMiscTemplate()->MoveCurveId, currentTimePercent);
        if (progress < 0.f || progress > 1.f)
        {
            TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (Id: %u, SpellMiscId: %u) has wrong progress (%f) caused by curve calculation (MoveCurveId: %u)",
                GetTemplate()->Id, GetMiscTemplate()->MiscId, progress, GetMiscTemplate()->MorphCurveId);
        }
        else
            currentTimePercent = progress;
    }

    int lastPositionIndex = 0;
    float percentFromLastPoint = 0;
    _spline->computeIndex(currentTimePercent, lastPositionIndex, percentFromLastPoint);

    G3D::Vector3 currentPosition;
    _spline->evaluate_percent(lastPositionIndex, percentFromLastPoint, currentPosition);

    float orientation = GetOrientation();
    if (GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_FACE_MOVEMENT_DIR))
    {
        G3D::Vector3 const& nextPoint = _spline->getPoint(lastPositionIndex + 1);
        orientation = GetAngle(nextPoint.x, nextPoint.y);
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

void AreaTrigger::DebugVisualizePosition()
{
    if (Unit* caster = GetCaster())
        if (Player* player = caster->ToPlayer())
            if (player->isDebugAreaTriggers)
                player->SummonCreature(1, *this, TEMPSUMMON_TIMED_DESPAWN, GetTimeToTarget());
}

void AreaTrigger::AI_Initialize()
{
    AI_Destroy();
    AreaTriggerAI* ai = sScriptMgr->GetAreaTriggerAI(this);
    if (!ai)
        ai = new NullAreaTriggerAI(this);

    _ai.reset(ai);
    _ai->OnInitialize();
}

void AreaTrigger::AI_Destroy()
{
    _ai.reset();
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

void AreaTrigger::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&AreaTrigger::m_areaTriggerData);
    Object::ClearUpdateMask(remove);
}
