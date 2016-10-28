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

#include "Object.h"
#include "ObjectAccessor.h"
#include "Position.h"
#include "AreaTriggerTemplate.h"

class Unit;
class SpellInfo;

class TC_GAME_API AreaTrigger : public WorldObject, public GridObject<AreaTrigger>, public MapObject
{
    public:
        AreaTrigger();
        ~AreaTrigger();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool CreateAreaTrigger(ObjectGuid::LowType guidlow, uint32 triggerEntry, Unit* caster, SpellInfo const* spell, Position const& pos, uint32 spellXSpellVisualId);
        void Update(uint32 p_time) override;
        void Remove();
        uint32 GetSpellId() const { return GetUInt32Value(AREATRIGGER_SPELLID); }
        uint32 GetTimeSinceCreated() const { return _timeSinceCreated; }
        int32 GetDuration() const { return _duration; }
        int32 GetTotalDuration() const { return _totalDuration; }
        void SetDuration(int32 newDuration) { _duration = newDuration; _totalDuration = newDuration; ComputeSplineDistances(); }
        void Delay(int32 delaytime) { SetDuration(GetDuration() - delaytime); }

        void SearchUnitInSphere();
        void SearchUnitInBox();
        void SearchUnitInPolygon();
        void SearchUnitInCylinder();
        void HandleUnitEnterExit(std::list<Unit*> targetList);

        GuidUnorderedSet const& GetInsideUnits() const { return _insideUnits; }

        AreaTriggerMiscTemplate const* GetMiscTemplate() const { return _areaTriggerMiscTemplate; }
        AreaTriggerTemplate const* GetTemplate() const { return _areaTriggerMiscTemplate->Template; }
        uint32 GetScriptId() const { return GetTemplate()->ScriptId; }
        Unit* GetCaster() const { return ObjectAccessor::GetUnit(*this, _casterGuid); }

        std::vector<Position> const GetSplines() const { return _splines; }

        bool CheckIsInPolygon2D(Position* pos) const;

    protected:
        void AddAuras(Unit* unit);
        void RemoveAuras(Unit* unit);
        bool UnitFitToAuraRequirement(Unit* unit, AreaTriggerAuraTypes targetType) const;

        void ComputeSplineDistances();
        void UpdateSplinePosition();

        ObjectGuid _casterGuid;

        int32 _duration;
        int32 _totalDuration;
        uint32 _spellXSpellVisualId;
        uint32 _timeSinceCreated;

        std::vector<AreaTriggerPolygonVertice> _polygonVertices;
        std::vector<Position> _splines;

        float _totalDistance;
        std::vector<float> _distanceToPoints;
        bool _reachedDestination;

        AreaTriggerMiscTemplate const* _areaTriggerMiscTemplate;
        GuidUnorderedSet _insideUnits;
};

#endif
