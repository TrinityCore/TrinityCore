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

#ifndef TRINITYCORE_AREATRIGGER_H
#define TRINITYCORE_AREATRIGGER_H

#include "Object.h"
#include "GridObject.h"
#include "MapObject.h"
#include "AreaTriggerTemplate.h"

class AuraEffect;
class AreaTriggerAI;
class SpellInfo;
class Unit;

namespace G3D
{
    class Vector2;
    class Vector3;
}
namespace Movement
{
    template<typename length_type>
    class Spline;
}

class TC_GAME_API AreaTrigger final : public WorldObject, public GridObject<AreaTrigger>, public MapObject
{
    public:
        AreaTrigger();
        ~AreaTrigger();

    protected:
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
        void ClearUpdateMask(bool remove) override;

    public:
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
            UF::AreaTriggerData::Mask const& requestedAreaTriggerMask, Player const* target) const;

        struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
        {
            explicit ValuesUpdateForPlayerWithMaskSender(AreaTrigger const* owner) : Owner(owner) { }

            AreaTrigger const* Owner;
            UF::ObjectData::Base ObjectMask;
            UF::AreaTriggerData::Base AreaTriggerMask;

            void operator()(Player const* player) const;
        };

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void AI_Initialize();
        void AI_Destroy();

        AreaTriggerAI* AI() { return _ai.get(); }

        bool IsCustom() const { return _areaTriggerTemplate->Id.IsCustom; }
        bool IsServerSide() const { return _areaTriggerTemplate->Flags.HasFlag(AreaTriggerFlag::IsServerSide); }
        bool IsStaticSpawn() const { return _spawnId != 0; }

        bool IsNeverVisibleFor(WorldObject const* seer, bool allowServersideObjects = false) const override;

        float GetStationaryX() const override { return _stationaryPosition.GetPositionX(); }
        float GetStationaryY() const override { return _stationaryPosition.GetPositionY(); }
        float GetStationaryZ() const override { return _stationaryPosition.GetPositionZ(); }
        float GetStationaryO() const override { return _stationaryPosition.GetOrientation(); }
        void RelocateStationaryPosition(Position const& pos) { _stationaryPosition.Relocate(pos); }
        void PlaySpellVisual(uint32 spellVisualId) const;

    private:
        bool Create(AreaTriggerCreatePropertiesId areaTriggerCreatePropertiesId, Map* map, Position const& pos, int32 duration, AreaTriggerSpawn const* spawnData = nullptr, Unit* caster = nullptr, Unit* target = nullptr, SpellCastVisual spellVisual = { 0, 0 }, SpellInfo const* spellInfo = nullptr, Spell* spell = nullptr, AuraEffect const* aurEff = nullptr);

    public:
        static AreaTrigger* CreateAreaTrigger(AreaTriggerCreatePropertiesId areaTriggerCreatePropertiesId, Position const& pos, int32 duration, Unit* caster, Unit* target, SpellCastVisual spellVisual = { 0, 0 }, SpellInfo const* spellInfo = nullptr, Spell* spell = nullptr, AuraEffect const* aurEff = nullptr);
        static ObjectGuid CreateNewMovementForceId(Map* map, uint32 areaTriggerId);
        bool LoadFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool allowDuplicate);

        void Update(uint32 diff) override;
        void Remove();
        bool IsRemoved() const { return _isRemoved; }
        uint32 GetSpellId() const { return m_areaTriggerData->SpellID; }
        AuraEffect const* GetAuraEffect() const { return _aurEff; }
        uint32 GetTimeSinceCreated() const { return _timeSinceCreated; }

        void SetHeightIgnoresScale(bool heightIgnoresScale) { SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::HeightIgnoresScale), heightIgnoresScale); }

        void SetOverrideScaleCurve(float overrideScale);
        void SetOverrideScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset = {}, CurveInterpolationMode interpolation = CurveInterpolationMode::Linear);
        void ClearOverrideScaleCurve();

        void SetExtraScaleCurve(float extraScale);
        void SetExtraScaleCurve(std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset = {}, CurveInterpolationMode interpolation = CurveInterpolationMode::Linear);
        void ClearExtraScaleCurve();

        void SetOverrideMoveCurve(float x, float y, float z);
        void SetOverrideMoveCurve(std::array<DBCPosition2D, 2> const& xCurvePoints, std::array<DBCPosition2D, 2> const& yCurvePoints, std::array<DBCPosition2D, 2> const& zCurvePoints,
            Optional<uint32> startTimeOffset = {}, CurveInterpolationMode interpolation = CurveInterpolationMode::Linear);
        void ClearOverrideMoveCurve();

        uint32 GetTimeToTarget() const { return m_areaTriggerData->TimeToTarget; }
        void SetTimeToTarget(uint32 timeToTarget) { SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTarget), timeToTarget); }

        uint32 GetTimeToTargetScale() const { return m_areaTriggerData->TimeToTargetScale; }
        void SetTimeToTargetScale(uint32 timeToTargetScale) { SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTargetScale), timeToTargetScale); }

        uint32 GetTimeToTargetExtraScale() const { return m_areaTriggerData->TimeToTargetExtraScale; }
        void SetTimeToTargetExtraScale(uint32 timeToTargetExtraScale) { SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTargetExtraScale), timeToTargetExtraScale); }

        uint32 GetTimeToTargetPos() const { return m_areaTriggerData->TimeToTargetPos; }
        void SetTimeToTargetPos(uint32 timeToTargetPos) { SetUpdateFieldValue(m_values.ModifyValue(&AreaTrigger::m_areaTriggerData).ModifyValue(&UF::AreaTriggerData::TimeToTargetPos), timeToTargetPos); }

        int32 GetDuration() const { return _duration; }
        int32 GetTotalDuration() const { return _totalDuration; }
        void SetDuration(int32 newDuration);
        void Delay(int32 delaytime) { SetDuration(GetDuration() - delaytime); }

        GuidUnorderedSet const& GetInsideUnits() const { return _insideUnits; }

        AreaTriggerCreateProperties const* GetCreateProperties() const { return _areaTriggerCreateProperties; }
        AreaTriggerTemplate const* GetTemplate() const;
        uint32 GetScriptId() const;

        ObjectGuid GetCreatorGUID() const override { return GetCasterGuid(); }
        ObjectGuid GetOwnerGUID() const override { return GetCasterGuid(); }
        ObjectGuid const& GetCasterGuid() const { return m_areaTriggerData->Caster; }
        Unit* GetCaster() const;
        Unit* GetTarget() const;

        uint32 GetFaction() const override;

        AreaTriggerShapeInfo const& GetShape() const { return _shape; }
        float GetMaxSearchRadius() const;
        Position const& GetRollPitchYaw() const { return _rollPitchYaw; }
        Position const& GetTargetRollPitchYaw() const { return _targetRollPitchYaw; }
        void InitSplineOffsets(std::vector<Position> const& offsets, uint32 timeToTarget);
        void InitSplines(std::vector<G3D::Vector3> splinePoints, uint32 timeToTarget);
        bool HasSplines() const;
        ::Movement::Spline<int32> const& GetSpline() const { return *_spline; }
        uint32 GetElapsedTimeForMovement() const { return GetTimeSinceCreated(); } /// @todo: research the right value, in sniffs both timers are nearly identical

        void InitOrbit(AreaTriggerOrbitInfo const& orbit, uint32 timeToTarget);
        bool HasOrbit() const;
        Optional<AreaTriggerOrbitInfo> const& GetOrbit() const { return _orbitInfo; }

        bool HasOverridePosition() const;

        void UpdateShape();

        UF::UpdateField<UF::AreaTriggerData, 0, TYPEID_AREATRIGGER> m_areaTriggerData;

    protected:
        void _UpdateDuration(int32 newDuration);

        float CalcCurrentScale() const;

        float GetProgress() const;

        float GetScaleCurveProgress(UF::ScaleCurve const& scaleCurve, uint32 timeTo) const;
        float GetScaleCurveValueAtProgress(UF::ScaleCurve const& scaleCurve, float x) const;
        float GetScaleCurveValue(UF::ScaleCurve const& scaleCurve, uint32 timeTo) const;
        void SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, float constantValue);
        void SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, std::array<DBCPosition2D, 2> const& points, Optional<uint32> startTimeOffset, CurveInterpolationMode interpolation);
        void ClearScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator);
        void SetScaleCurve(UF::MutableFieldReference<UF::ScaleCurve, false> scaleCurveMutator, Optional<AreaTriggerScaleCurveTemplate> const& curve);

        void UpdateTargetList();
        void SearchUnits(std::vector<Unit*>& targetList, float radius, bool check3D);
        void SearchUnitInSphere(std::vector<Unit*>& targetList);
        void SearchUnitInBox(std::vector<Unit*>& targetList);
        void SearchUnitInPolygon(std::vector<Unit*>& targetList);
        void SearchUnitInCylinder(std::vector<Unit*>& targetList);
        void SearchUnitInDisk(std::vector<Unit*>& targetList);
        void SearchUnitInBoundedPlane(std::vector<Unit*>& targetList);
        void HandleUnitEnterExit(std::vector<Unit*> const& targetList);

        void DoActions(Unit* unit);
        void UndoActions(Unit* unit);

        void UpdatePolygonVertices();
        void UpdateOrbitPosition(uint32 diff);
        void UpdateSplinePosition(uint32 diff);
        void UpdateOverridePosition();

        Position const* GetOrbitCenterPosition() const;
        Position CalculateOrbitPosition() const;

        void DebugVisualizePosition(); // Debug purpose only

        ObjectGuid::LowType _spawnId;

        ObjectGuid _targetGuid;

        AuraEffect const* _aurEff;

        Position _stationaryPosition;
        AreaTriggerShapeInfo _shape;
        int32 _duration;
        int32 _totalDuration;
        uint32 _timeSinceCreated;
        float _verticesUpdatePreviousOrientation;
        bool _isRemoved;

        Position _rollPitchYaw;
        Position _targetRollPitchYaw;
        std::vector<Position> _polygonVertices;
        std::unique_ptr<::Movement::Spline<int32>> _spline;

        bool _reachedDestination;
        int32 _lastSplineIndex;
        uint32 _movementTime;

        Optional<AreaTriggerOrbitInfo> _orbitInfo;

        AreaTriggerCreateProperties const* _areaTriggerCreateProperties;
        AreaTriggerTemplate const* _areaTriggerTemplate;
        GuidUnorderedSet _insideUnits;

        std::unique_ptr<AreaTriggerAI> _ai;
};

#endif
