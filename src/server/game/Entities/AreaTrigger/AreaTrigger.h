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

#ifndef TRINITYCORE_AREATRIGGER_H
#define TRINITYCORE_AREATRIGGER_H

#include "MoveSplineInitArgs.h"
#include "Object.h"
#include "Position.h"
#include "Spline.h"

class AreaTriggerTemplate;
class AreaTriggerMiscTemplate;
class SpellInfo;
class Unit;
struct AreaTriggerPolygonVertice;

class TC_GAME_API AreaTrigger : public WorldObject, public GridObject<AreaTrigger>, public MapObject
{
    public:
        AreaTrigger();
        ~AreaTrigger();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool CreateAreaTrigger(uint32 triggerEntry, Unit* caster, Unit* target, SpellInfo const* spell, Position const& pos, int32 duration, uint32 spellXSpellVisualId, ObjectGuid const& castId = ObjectGuid::Empty);
        void Update(uint32 p_time) override;
        void Remove();
        bool IsRemoved() const { return _isRemoved; }
        uint32 GetSpellId() const { return GetUInt32Value(AREATRIGGER_SPELLID); }
        uint32 GetTimeSinceCreated() const { return _timeSinceCreated; }
        uint32 GetTimeToTarget() const { return GetUInt32Value(AREATRIGGER_TIME_TO_TARGET); }
        int32 GetDuration() const { return _duration; }
        int32 GetTotalDuration() const { return _totalDuration; }
        void SetDuration(int32 newDuration);
        void Delay(int32 delaytime) { SetDuration(GetDuration() - delaytime); }

        void SearchUnitInSphere();
        void SearchUnitInBox();
        void SearchUnitInPolygon();
        void SearchUnitInCylinder();
        void HandleUnitEnterExit(std::list<Unit*> targetList);

        GuidUnorderedSet const& GetInsideUnits() const { return _insideUnits; }

        AreaTriggerMiscTemplate const* GetMiscTemplate() const { return _areaTriggerMiscTemplate; }
        AreaTriggerTemplate const* GetTemplate() const;
        uint32 GetScriptId() const;

        ObjectGuid const& GetCasterGuid() const { return GetGuidValue(AREATRIGGER_CASTER); }
        Unit* GetCaster() const;
        Unit* GetTarget() const;

        void InitSplineOffsets(::Movement::PointsArray splinePoints);
        void InitSplines(::Movement::PointsArray const& splinePoints);
        bool HasSplines() const { return !_spline.empty(); }
        ::Movement::Spline<int32> const& GetSpline() const { return _spline; }
        uint32 GetElapsedTimeForMovement() const { return GetTimeSinceCreated(); } /// @todo: fix me

        bool CheckIsInPolygon2D(Position* pos) const;

    protected:
        void _UpdateDuration(int32 newDuration);

        void AddAuras(Unit* unit);
        void RemoveAuras(Unit* unit);
        bool UnitFitToAuraRequirement(Unit* unit, AreaTriggerAuraTypes targetType) const;

        void UpdatePolygonOrientation();
        void UpdateSplinePosition();

        ObjectGuid _targetGuid;

        int32 _duration;
        int32 _totalDuration;
        uint32 _timeSinceCreated;
        float _previousCheckOrientation;
        bool _isRemoved;

        std::vector<AreaTriggerPolygonVertice> _polygonVertices;
        ::Movement::Spline<int32> _spline;

        bool _reachedDestination;
        int32 _lastSplineIndex;

        AreaTriggerMiscTemplate const* _areaTriggerMiscTemplate;
        GuidUnorderedSet _insideUnits;
};

#endif
