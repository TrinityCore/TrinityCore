/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "CellImpl.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "Unit.h"
#include "UpdateData.h"
#include "ScriptMgr.h"

AreaTrigger::AreaTrigger() : WorldObject(false), _duration(0), _spellXSpellVisualId(0), _timeSinceCreated(0), _areaTriggerTemplate(nullptr)
{
    m_objectType |= TYPEMASK_AREATRIGGER;
    m_objectTypeId = TYPEID_AREATRIGGER;

    m_updateFlag = UPDATEFLAG_STATIONARY_POSITION | UPDATEFLAG_AREATRIGGER;

    m_valuesCount = AREATRIGGER_END;
    _dynamicValuesCount = AREATRIGGER_DYNAMIC_END;
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
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<AreaTrigger>(GetGUID());
    }
}

bool AreaTrigger::CreateAreaTrigger(ObjectGuid::LowType guidlow, uint32 triggerEntry, Unit* caster, SpellInfo const* spell, Position const& pos, uint32 spellXSpellVisualId)
{
    _casterGuid = caster->GetGUID();

    _spellXSpellVisualId = spellXSpellVisualId;
    SetMap(caster->GetMap());
    Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("misc", "AreaTrigger (spell %u) not created. Invalid coordinates (X: %f Y: %f)", spell->Id, GetPositionX(), GetPositionY());
        return false;
    }

    _areaTriggerTemplate = sObjectMgr->GetAreaTriggerTemplate(triggerEntry);

    Object::_Create(ObjectGuid::Create<HighGuid::AreaTrigger>(GetMapId(), triggerEntry, guidlow));
    SetPhaseMask(caster->GetPhaseMask(), false);

    SetEntry(triggerEntry);
    SetDuration(spell->GetDuration());

    SetUInt32Value(AREATRIGGER_DURATION, spell->GetDuration());

    SetObjectScale(1);

    SetGuidValue(AREATRIGGER_CASTER, caster->GetGUID());
    SetUInt32Value(AREATRIGGER_SPELLID, spell->Id);
    SetUInt32Value(AREATRIGGER_SPELL_X_SPELL_VISUAL_ID, spellXSpellVisualId);
    SetUInt32Value(AREATRIGGER_DURATION, spell->GetDuration());
    SetUInt32Value(AREATRIGGER_TIME_TO_TARGET_SCALE, GetTemplate()->TimeToTargetScale != 0 ? GetTemplate()->TimeToTargetScale : spell->GetDuration());

    switch (GetTemplate()->GetType())
    {
        case AREATRIGGER_TYPE_SPHERE:
            SetFloatValue(AREATRIGGER_BOUNDS_RADIUS_2D, GetTemplate()->SphereDatas.Radius);
            break;
        case AREATRIGGER_TYPE_CYLINDER:
            SetFloatValue(AREATRIGGER_BOUNDS_RADIUS_2D, GetTemplate()->CylinderDatas.Radius);
            break;
        default:
            break;
    }

    CopyPhaseFrom(caster);

    if (GetTemplate()->IsPolygon())
    {
        _polygonVertices = GetTemplate()->PolygonVertices;

        float angleSin = std::sin(GetOrientation());
        float angleCos = std::cos(GetOrientation());

        // This is needed to rotate the vertices, following caster orientation
        for (AreaTriggerPolygonVertice& vertice : _polygonVertices)
        {
            float tempX = vertice.VerticeX;
            float tempY = vertice.VerticeY;

            vertice.VerticeX = tempX * angleCos - tempY * angleSin;
            vertice.VerticeY = tempX * angleSin + tempY * angleCos;
        }
    }

    if (!GetMap()->AddToMap(this))
        return false;

    caster->_RegisterAreaTrigger(this);

    sScriptMgr->OnAreaTriggerEntityCreate(this);

    return true;
}

void AreaTrigger::Update(uint32 p_time)
{
    if (GetDuration() > int32(p_time))
        _duration -= p_time;
    else
        Remove(); // expired

    WorldObject::Update(p_time);
    _timeSinceCreated += p_time;

    sScriptMgr->OnAreaTriggerEntityUpdate(this, p_time);

    switch (GetTemplate()->GetType())
    {
        case AREATRIGGER_TYPE_SPHERE:
            SearchUnitInSphere();
            break;
        case AREATRIGGER_TYPE_BOX:
            SearchUnitInBox();
            break;
        case AREATRIGGER_TYPE_POLYGON:
            SearchUnitInPolygon();
            break;
        case AREATRIGGER_TYPE_CYLINDER:
            SearchUnitInCylinder();
            break;
        default:
            break;
    }
}

void AreaTrigger::Remove()
{
    if (IsInWorld())
    {
        if (Unit* caster = GetCaster())
            caster->_UnregisterAreaTrigger(this);

        for (ObjectGuid insideUnitGuid : _insideUnits)
            if (Unit* leavingUnit = ObjectAccessor::GetUnit(*this, insideUnitGuid))
                sScriptMgr->OnAreaTriggerEntityUnitExit(this, leavingUnit);

        sScriptMgr->OnAreaTriggerEntityRemove(this);

        RemoveFromWorld();
        AddObjectToRemoveList();
    }
}

void AreaTrigger::SearchUnitInSphere()
{
    std::list<Unit*> targetList;

    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    VisitNearbyObject(GetTemplate()->MaxSearchRadius, searcher);

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnitInBox()
{
    float extentsX = GetTemplate()->BoxDatas.Extents[0];
    float extentsY = GetTemplate()->BoxDatas.Extents[1];
    float extentsZ = GetTemplate()->BoxDatas.Extents[2];

    std::list<Unit*> targetList;

    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    VisitNearbyObject(GetTemplate()->MaxSearchRadius, searcher);

    float halfExtentsX = extentsX / 2.0;
    float halfExtentsY = extentsY / 2.0;
    float halfExtentsZ = extentsZ / 2.0;

    float minX = GetPositionX() - halfExtentsX;
    float maxX = GetPositionX() + halfExtentsX;

    float minY = GetPositionY() - halfExtentsY;
    float maxY = GetPositionY() + halfExtentsY;

    float minZ = GetPositionZ() - halfExtentsZ;
    float maxZ = GetPositionZ() + halfExtentsZ;

    G3D::AABox box({ minX, minY, minZ }, { maxX, maxY, maxZ });

    targetList.remove_if([this, box](Unit* unit) -> bool
    {
        return !box.contains({ unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ() });
    });

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnitInPolygon()
{
    std::list<Unit*> targetList;

    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    VisitNearbyObject(GetTemplate()->MaxSearchRadius, searcher);

    float height = GetTemplate()->PolygonDatas.Height;

    targetList.remove_if([this, height](Unit* unit) -> bool
    {
        float minZ = GetPositionZ() - height;
        float maxZ = GetPositionZ() + height;

        return  !CheckIsInPolygon2D(unit) ||
                unit->GetPositionZ() < minZ ||
                unit->GetPositionZ() > maxZ;
    });

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::SearchUnitInCylinder()
{
    float height = GetTemplate()->CylinderDatas.Height;

    std::list<Unit*> targetList;

    Trinity::AnyUnitInObjectRangeCheck check(this, GetTemplate()->MaxSearchRadius, false);
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targetList, check);
    VisitNearbyObject(GetTemplate()->MaxSearchRadius, searcher);

    targetList.remove_if([this, height](Unit* unit) -> bool
    {
        float minZ = GetPositionZ() - height;
        float maxZ = GetPositionZ() + height;

        return unit->GetPositionZ() < minZ || unit->GetPositionZ() > maxZ;
    });

    HandleUnitEnterExit(targetList);
}

void AreaTrigger::HandleUnitEnterExit(std::list<Unit*> newTargetList)
{
    GuidUnorderedSet exitUnits = _insideUnits;
    _insideUnits.clear();

    for (Unit* unit : newTargetList)
    {
        if (exitUnits.erase(unit->GetGUID()) == 0) // erase(key_type) returns number of elements erased
        {
            if (Player* player = unit->ToPlayer())
                if (player->isDebugAreaTriggers)
                    ChatHandler(player->GetSession()).PSendSysMessage("You entered areatrigger %u", GetTemplate()->Id);

            AddAuras(unit);
            sScriptMgr->OnAreaTriggerEntityUnitEnter(this, unit);
        }

        _insideUnits.insert(unit->GetGUID());
    }

    for (ObjectGuid const& exitUnitGuid : exitUnits)
    {
        if (Unit* leavingUnit = ObjectAccessor::GetUnit(*this, exitUnitGuid))
        {
            if (Player* player = leavingUnit->ToPlayer())
                if (player->isDebugAreaTriggers)
                    ChatHandler(player->GetSession()).PSendSysMessage("You exited areatrigger %u", GetTemplate()->Id);

            RemoveAuras(leavingUnit);
            sScriptMgr->OnAreaTriggerEntityUnitExit(this, leavingUnit);
        }
    }
}

bool AreaTrigger::CheckIsInPolygon2D(Position* pos) const
{
    float testX = pos->GetPositionX();
    float testY = pos->GetPositionY();

    //this method uses the ray tracing algorithm to determine if the point is in the polygon
    int nPoints = _polygonVertices.size();
    bool locatedInPolygon = false;

    for (int i = 0; i < nPoints; ++i)
    {
        int j = -999;

        //repeat loop for all sets of points
        if (i == (nPoints - 1))
        {
            //if i is the last vertex, let j be the first vertex
            j = 0;
        }
        else
        {
            //for all-else, let j=(i+1)th vertex
            j = i + 1;
        }

        float vertY_i = GetPositionY() + (float)_polygonVertices[i].VerticeY;
        float vertX_i = GetPositionX() + (float)_polygonVertices[i].VerticeX;
        float vertY_j = GetPositionY() + (float)_polygonVertices[j].VerticeY;
        float vertX_j = GetPositionX() + (float)_polygonVertices[j].VerticeX;

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

void AreaTrigger::AddAuras(Unit* unit)
{
    for (AreaTriggerAuras aura : GetTemplate()->Auras)
    {
        if (UnitFitToAuraRequirement(unit, aura.TargetType))
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*this, _casterGuid))
            {
                if (aura.CastType == AREATRIGGER_AURA_CAST)
                    caster->CastSpell(unit, aura.AuraId, true);
                else
                    caster->AddAura(aura.AuraId, unit);
            }
        }
    }
}

void AreaTrigger::RemoveAuras(Unit* unit)
{
    for (AreaTriggerAuras aura : GetTemplate()->Auras)
    {
        unit->RemoveAurasDueToSpell(aura.AuraId, _casterGuid);
    }
}

bool AreaTrigger::UnitFitToAuraRequirement(Unit* unit, AreaTriggerAuraTypes targetType) const
{
    switch (targetType)
    {
        case AREATRIGGER_AURA_USER_ANY:
        default:
        {
            break;
        }
        case AREATRIGGER_AURA_USER_FRIEND:
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*this, _casterGuid))
                return caster->IsFriendlyTo(unit);

            return false;
        }
        case AREATRIGGER_AURA_USER_ENEMY:
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*this, _casterGuid))
                return !caster->IsFriendlyTo(unit);

            return false;
        }
        case AREATRIGGER_AURA_USER_RAID:
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*this, _casterGuid))
                if (Player* casterPlayer = caster->ToPlayer())
                    if (Player* targetPlayer = unit->ToPlayer())
                        return casterPlayer->IsInSameRaidWith(targetPlayer);

            return false;
        }
        case AREATRIGGER_AURA_USER_PARTY:
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*this, _casterGuid))
                if (Player* casterPlayer = caster->ToPlayer())
                    if (Player* targetPlayer = unit->ToPlayer())
                        return casterPlayer->IsInSameGroupWith(targetPlayer);

            return false;
        }
    }

    return true;
}
