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

AreaTrigger::AreaTrigger() : WorldObject(false), MapObject(), _spawnId(0), _aurEff(nullptr), _maxSearchRadius(0.0f),
    _duration(0), _totalDuration(0), _timeSinceCreated(0), _previousCheckOrientation(std::numeric_limits<float>::infinity()),
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
        _isRemoved = true;

        if (Unit* caster = GetCaster())
            caster->_UnregisterAreaTrigger(this);

        // Handle removal of all units, calling OnUnitExit & deleting auras if needed
        HandleUnitEnterExit({});

        _ai->OnRemove();

        WorldObject::RemoveFromWorld();

        if (_spawnId)
            Trinity::Containers::MultimapErasePair(GetMap()->GetAreaTriggerBySpawnIdStore(), _spawnId, this);
        GetMap()->GetObjectsStore().Remove<AreaTrigger>(GetGUID());
    }
}

bool AreaTrigger::Create(uint32 areaTriggerCreatePropertiesId, Unit* caster, Unit* target, SpellInfo const* spell, Position const& pos, int32 duration, SpellCastVisual spellVisual, ObjectGuid const& castId, AuraEffect const* aurEff)
{
    _targetGuid = target ? target->GetGUID() : ObjectGuid::Empty;
    _aurEff = aurEff;

    SetMap(caster->GetMap());
    Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (areaTriggerCreatePropertiesId %u) not created. Invalid coordinates (X: %f Y: %f)", areaTriggerCreatePropertiesId, GetPositionX(), GetPositionY());
        return false;
    }

    _areaTriggerCreateProperties = sAreaTriggerDataStore->GetAreaTriggerCreateProperties(areaTriggerCreatePropertiesId);
    if (!_areaTriggerCreateProperties)
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (areaTriggerCreatePropertiesId %u) not created. Invalid areatrigger create properties id (%u)", areaTriggerCreatePropertiesId, areaTriggerCreatePropertiesId);
        return false;
    }

    _areaTriggerTemplate = _areaTriggerCreateProperties->Template;

    Object::_Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), GetTemplate() ? GetTemplate()->Id.Id : 0, caster->GetMap()->GenerateLowGuid<HighGuid::AreaTrigger>()));

    if (GetTemplate())
        SetEntry(GetTemplate()->Id.Id);

    SetDuration(duration);

    SetObjectScale(1.0f);

    _shape = GetCreateProperties()->Shape;
    _maxSearchRadius = GetCreateProperties()->GetMaxSearchRadius();

    auto areaTriggerData = m_values.ModifyValue(&AreaTrigger::m_areaTriggerData);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::Caster), caster->GetGUID());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::CreatingEffectGUID), castId);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellID), spell->Id);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellForVisuals), spell->Id);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellVisual).ModifyValue(&UF::SpellCastVisual::SpellXSpellVisualID), spellVisual.SpellXSpellVisualID);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::SpellVisual).ModifyValue(&UF::SpellCastVisual::ScriptVisualID), spellVisual.ScriptVisualID);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), GetCreateProperties()->TimeToTargetScale != 0 ? GetCreateProperties()->TimeToTargetScale : *m_areaTriggerData->Duration);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::BoundsRadius2D), GetMaxSearchRadius());
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::DecalPropertiesID), GetCreateProperties()->DecalPropertiesId);

    if (GetCreateProperties()->ExtraScale.Data.Structured.StartTimeOffset)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::StartTimeOffset), GetCreateProperties()->ExtraScale.Data.Structured.StartTimeOffset);
    if (GetCreateProperties()->ExtraScale.Data.Structured.Points[0] || GetCreateProperties()->ExtraScale.Data.Structured.Points[1])
    {
        Position point(GetCreateProperties()->ExtraScale.Data.Structured.Points[0], GetCreateProperties()->ExtraScale.Data.Structured.Points[1]);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::Points, 0), point);
    }
    if (GetCreateProperties()->ExtraScale.Data.Structured.Points[2] || GetCreateProperties()->ExtraScale.Data.Structured.Points[3])
    {
        Position point(GetCreateProperties()->ExtraScale.Data.Structured.Points[2], GetCreateProperties()->ExtraScale.Data.Structured.Points[3]);
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::Points, 1), point);
    }
    if (GetCreateProperties()->ExtraScale.Data.Raw[5])
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::ParameterCurve), GetCreateProperties()->ExtraScale.Data.Raw[5]);
    if (GetCreateProperties()->ExtraScale.Data.Structured.OverrideActive)
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::ExtraScaleCurve).ModifyValue(&UF::ScaleCurve::OverrideActive), GetCreateProperties()->ExtraScale.Data.Structured.OverrideActive);

    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimationDataID), GetCreateProperties()->AnimId);
    SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::AnimKitID), GetCreateProperties()->AnimKitId);
    if (GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_UNK3))
        SetUpdateFieldValue(areaTriggerData.ModifyValue(&UF::AreaTriggerData::VisualAnim).ModifyValue(&UF::VisualAnim::Field_C), true);

    PhasingHandler::InheritPhaseShift(this, caster);

    if (target && GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
    {
        m_movementInfo.transport.guid = target->GetGUID();
    }

    UpdatePositionData();
    SetZoneScript();

    UpdateShape();

    uint32 timeToTarget = GetCreateProperties()->TimeToTarget != 0 ? GetCreateProperties()->TimeToTarget : *m_areaTriggerData->Duration;

    if (GetCreateProperties()->OrbitInfo)
    {
        AreaTriggerOrbitInfo orbit = *GetCreateProperties()->OrbitInfo;
        if (target && GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
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
    TransportBase* transport = m_movementInfo.transport.guid.IsEmpty() ? caster->GetTransport() : nullptr;
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
    if (HasOrbit())
        Relocate(CalculateOrbitPosition());

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

AreaTrigger* AreaTrigger::CreateAreaTrigger(uint32 areaTriggerCreatePropertiesId, Unit* caster, Unit* target, SpellInfo const* spell, Position const& pos, int32 duration, SpellCastVisual spellVisual, ObjectGuid const& castId /*= ObjectGuid::Empty*/, AuraEffect const* aurEff /*= nullptr*/)
{
    AreaTrigger* at = new AreaTrigger();
    if (!at->Create(areaTriggerCreatePropertiesId, caster, target, spell, pos, duration, spellVisual, castId, aurEff))
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

    AreaTriggerSpawn const* position = sAreaTriggerDataStore->GetAreaTriggerSpawn(spawnId);
    if (!position)
        return false;

    AreaTriggerTemplate const* areaTriggerTemplate = sAreaTriggerDataStore->GetAreaTriggerTemplate(position->Id);
    if (!areaTriggerTemplate)
        return false;

    return CreateServer(map, areaTriggerTemplate, *position);
}

bool AreaTrigger::CreateServer(Map* map, AreaTriggerTemplate const* areaTriggerTemplate, AreaTriggerSpawn const& position)
{
    SetMap(map);
    Relocate(position.spawnPoint);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.areatrigger", "AreaTriggerServer (id %u) not created. Invalid coordinates (X: %f Y: %f)",
            areaTriggerTemplate->Id.Id, GetPositionX(), GetPositionY());
        return false;
    }

    _areaTriggerTemplate = areaTriggerTemplate;

    Object::_Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), areaTriggerTemplate->Id.Id, GetMap()->GenerateLowGuid<HighGuid::AreaTrigger>()));

    SetEntry(areaTriggerTemplate->Id.Id);

    SetObjectScale(1.0f);

    _shape = position.Shape;
    _maxSearchRadius = _shape.GetMaxSearchRadius();

    if (position.phaseUseFlags || position.phaseId || position.phaseGroup)
        PhasingHandler::InitDbPhaseShift(GetPhaseShift(), position.phaseUseFlags, position.phaseId, position.phaseGroup);

    UpdateShape();

    AI_Initialize();

    _ai->OnCreate();

    return true;
}

void AreaTrigger::Update(uint32 diff)
{
    WorldObject::Update(diff);
    _timeSinceCreated += diff;

    if (!IsServerSide())
    {
        // "If" order matter here, Orbit > Attached > Splines
        if (HasOrbit())
        {
            UpdateOrbitPosition(diff);
        }
        else if (GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_ATTACHED))
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
    DoWithSuppressingObjectUpdates([&]()
    {
        SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::Duration), _duration);
        const_cast<UF::AreaTriggerData&>(*m_areaTriggerData).ClearChanged(&UF::AreaTriggerData::Duration);
    });
}

float AreaTrigger::GetProgress() const
{
    return GetTimeSinceCreated() < GetTimeToTargetScale() ? float(GetTimeSinceCreated()) / float(GetTimeToTargetScale()) : 1.0f;
}

void AreaTrigger::UpdateTargetList()
{
    std::vector<Unit*> targetList;

    switch (_shape.Type)
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
        case AREATRIGGER_TYPE_DISK:
            SearchUnitInDisk(targetList);
            break;
        default:
            break;
    }

    if (GetTemplate())
    {
        if (ConditionContainer const* conditions = sConditionMgr->GetConditionsForAreaTrigger(GetTemplate()->Id.Id, GetTemplate()->Id.IsServerSide))
        {
            targetList.erase(std::remove_if(targetList.begin(), targetList.end(), [conditions](Unit* target)
            {
                return !sConditionMgr->IsObjectMeetToConditions(target, *conditions);
            }), targetList.end());
        }
    }

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnits(std::vector<Unit*>& targetList, float radius, bool check3D)
{
    Trinity::AnyUnitInObjectRangeCheck check(this, radius, check3D);
    if (IsServerSide())
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
    float radius = _shape.SphereDatas.Radius;
    if (GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_DYNAMIC_SHAPE))
    {
        if (GetCreateProperties()->MorphCurveId)
        {
            radius = G3D::lerp(_shape.SphereDatas.Radius,
                _shape.SphereDatas.RadiusTarget,
                sDB2Manager.GetCurveValueAt(GetCreateProperties()->MorphCurveId, GetProgress()));
        }
    }

    SearchUnits(targetList, radius, true);
}

void AreaTrigger::SearchUnitInBox(std::vector<Unit*>& targetList)
{
    SearchUnits(targetList, GetMaxSearchRadius(), false);

    Position const& boxCenter = GetPosition();
    float extentsX = _shape.BoxDatas.Extents[0];
    float extentsY = _shape.BoxDatas.Extents[1];
    float extentsZ = _shape.BoxDatas.Extents[2];

    targetList.erase(std::remove_if(targetList.begin(), targetList.end(), [boxCenter, extentsX, extentsY, extentsZ](Unit* unit) -> bool
    {
        return !unit->IsWithinBox(boxCenter, extentsX, extentsY, extentsZ);
    }), targetList.end());
}

void AreaTrigger::SearchUnitInPolygon(std::vector<Unit*>& targetList)
{
    SearchUnits(targetList, GetMaxSearchRadius(), false);

    float height = _shape.PolygonDatas.Height;
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    targetList.erase(std::remove_if(targetList.begin(), targetList.end(), [this, minZ, maxZ](Unit* unit) -> bool
    {
        return !CheckIsInPolygon2D(unit)
            || unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    }), targetList.end());
}

void AreaTrigger::SearchUnitInCylinder(std::vector<Unit*>& targetList)
{
    SearchUnits(targetList, GetMaxSearchRadius(), false);

    float height = _shape.CylinderDatas.Height;
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    targetList.erase(std::remove_if(targetList.begin(), targetList.end(), [minZ, maxZ](Unit* unit) -> bool
    {
        return unit->GetPositionZ() < minZ
            || unit->GetPositionZ() > maxZ;
    }), targetList.end());
}

void AreaTrigger::SearchUnitInDisk(std::vector<Unit*>& targetList)
{
    SearchUnits(targetList, GetMaxSearchRadius(), false);

    float innerRadius = _shape.DiskDatas.InnerRadius;
    float height = _shape.DiskDatas.Height;
    float minZ = GetPositionZ() - height;
    float maxZ = GetPositionZ() + height;

    targetList.erase(std::remove_if(targetList.begin(), targetList.end(), [this, innerRadius, minZ, maxZ](Unit const* unit) -> bool
    {
        return unit->IsInDist2d(this, innerRadius) ||  unit->GetPositionZ() < minZ || unit->GetPositionZ() > maxZ;
    }), targetList.end());
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
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_ENTERED, GetEntry());

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
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_LEFT, GetEntry());

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
        return ASSERT_NOTNULL(sAreaTriggerDataStore->GetAreaTriggerSpawn(_spawnId))->scriptId;

    if (GetCreateProperties())
        return GetCreateProperties()->ScriptId;

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

void AreaTrigger::UpdatePolygonOrientation()
{
    float newOrientation = GetOrientation();

    // No need to recalculate, orientation didn't change
    if (G3D::fuzzyEq(_previousCheckOrientation, newOrientation))
        return;

    _polygonVertices.assign(GetCreateProperties()->PolygonVertices.begin(), GetCreateProperties()->PolygonVertices.end());

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
    if (_shape.IsPolygon())
        UpdatePolygonOrientation();
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
    Unit* caster = IsServerSide() ? unit : GetCaster();

    if (caster && GetTemplate())
    {
        for (AreaTriggerAction const& action : GetTemplate()->Actions)
        {
            if (IsServerSide() || UnitFitToActionRequirement(unit, caster, action))
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
                            if (Player* player = caster->ToPlayer())
                                player->TeleportTo(safeLoc->Loc);
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

    AreaTriggerOrbitInfo const& cmi = *_orbitInfo;

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

    if (GetCreateProperties()->MoveCurveId)
    {
        float progress = sDB2Manager.GetCurveValueAt(GetCreateProperties()->MoveCurveId, currentTimePercent);
        if (progress < 0.f || progress > 1.f)
        {
            TC_LOG_ERROR("entities.areatrigger", "AreaTrigger (Id: %u, AreaTriggerCreatePropertiesId: %u) has wrong progress (%f) caused by curve calculation (MoveCurveId: %u)",
                GetEntry(), GetCreateProperties()->Id, progress, GetCreateProperties()->MorphCurveId);
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
    if (GetTemplate() && GetTemplate()->HasFlag(AREATRIGGER_FLAG_HAS_FACE_MOVEMENT_DIR))
    {
        G3D::Vector3 const& nextPoint = _spline->getPoint(lastPositionIndex + 1);
        orientation = GetAbsoluteAngle(nextPoint.x, nextPoint.y);
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
