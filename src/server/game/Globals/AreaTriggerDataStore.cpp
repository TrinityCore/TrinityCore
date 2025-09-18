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

#include "AreaTriggerDataStore.h"
#include "AreaTriggerTemplate.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "MapManager.h"
#include "MapUtils.h"
#include "ObjectMgr.h"
#include "QueryResultStructured.h"
#include "SpellMgr.h"
#include "Timer.h"
#include "Types.h"
#include <cmath>

template <>
struct std::hash<AreaTriggerId>
{
    std::size_t operator()(AreaTriggerId const& value) const noexcept
    {
        size_t hashVal = 0;
        Trinity::hash_combine(hashVal, value.Id);
        Trinity::hash_combine(hashVal, value.IsCustom);
        return hashVal;
    }
};

namespace
{
    typedef std::unordered_map<uint32/*cell_id*/, std::set<ObjectGuid::LowType>> AtCellObjectGuidsMap;
    typedef std::unordered_map<std::pair<uint32 /*mapId*/, Difficulty>, AtCellObjectGuidsMap> AtMapObjectGuids;

    AtMapObjectGuids _areaTriggerSpawnsByLocation;
    std::unordered_map<ObjectGuid::LowType, AreaTriggerSpawn> _areaTriggerSpawnsBySpawnId;
    std::unordered_map<AreaTriggerId, AreaTriggerTemplate> _areaTriggerTemplateStore;
    std::unordered_map<AreaTriggerCreatePropertiesId, AreaTriggerCreateProperties> _areaTriggerCreateProperties;
}

void AreaTriggerDataStore::LoadAreaTriggerTemplates()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<AreaTriggerCreatePropertiesId, std::vector<TaggedPosition<Position::XY>>> verticesByCreateProperties;
    std::unordered_map<AreaTriggerCreatePropertiesId, std::vector<TaggedPosition<Position::XY>>> verticesTargetByCreateProperties;
    std::unordered_map<AreaTriggerCreatePropertiesId, std::vector<Position>> splinesByCreateProperties;
    std::unordered_map<AreaTriggerId, std::vector<AreaTriggerAction>> actionsByAreaTrigger;

    //                                                            0              1         2           3            4
    if (QueryResult templateActions = WorldDatabase.Query("SELECT AreaTriggerId, IsCustom, ActionType, ActionParam, TargetType FROM `areatrigger_template_actions`"))
    {
        do
        {
            Field* templateActionFields = templateActions->Fetch();
            AreaTriggerId areaTriggerId = { templateActionFields[0].GetUInt32(), templateActionFields[1].GetBool()};

            AreaTriggerAction action;
            action.Param       = templateActionFields[3].GetUInt32();
            uint32 actionType  = templateActionFields[2].GetUInt32();
            uint32 targetType  = templateActionFields[4].GetUInt32();

            if (actionType >= AREATRIGGER_ACTION_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid ActionType {} for AreaTriggerId ({},{}) and Param {}",
                    actionType, areaTriggerId.Id, uint32(areaTriggerId.IsCustom), action.Param);
                continue;
            }

            if (targetType >= AREATRIGGER_ACTION_USER_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid TargetType {} for AreaTriggerId ({},{}) and Param {}",
                    targetType, areaTriggerId.Id, uint32(areaTriggerId.IsCustom), action.Param);
                continue;
            }

            if (actionType == AREATRIGGER_ACTION_TELEPORT)
            {
                if (!sObjectMgr->GetWorldSafeLoc(action.Param))
                {
                    TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid entry for AreaTriggerId ({},{}) with TargetType=Teleport and Param ({}) not a valid world safe loc entry",
                        areaTriggerId.Id, uint32(areaTriggerId.IsCustom), action.Param);
                    continue;
                }
            }

            action.TargetType = AreaTriggerActionUserTypes(targetType);
            action.ActionType = AreaTriggerActionTypes(actionType);

            actionsByAreaTrigger[areaTriggerId].push_back(action);
        }
        while (templateActions->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates actions. DB table `areatrigger_template_actions` is empty.");
    }

    //                                                     0                              1         2    3         4         5               6
    if (QueryResult vertices = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, IsCustom, Idx, VerticeX, VerticeY, VerticeTargetX, VerticeTargetY FROM `areatrigger_create_properties_polygon_vertex` ORDER BY `AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`"))
    {
        do
        {
            Field* verticeFields = vertices->Fetch();
            AreaTriggerCreatePropertiesId createPropertiesId = { verticeFields[0].GetUInt32(), verticeFields[1].GetBool() };

            verticesByCreateProperties[createPropertiesId].emplace_back(verticeFields[3].GetFloat(), verticeFields[4].GetFloat());

            if (!verticeFields[5].IsNull() && !verticeFields[6].IsNull())
                verticesTargetByCreateProperties[createPropertiesId].emplace_back(verticeFields[5].GetFloat(), verticeFields[6].GetFloat());
            else if (verticeFields[5].IsNull() != verticeFields[6].IsNull())
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_polygon_vertex` has listed invalid target vertices (AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {}), Index: {}).",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), verticeFields[1].GetUInt32());
        }
        while (vertices->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger polygon vertices. DB table `areatrigger_create_properties_polygon_vertex` is empty.");
    }

    //                                                    0                              1         2  3, 4
    if (QueryResult splines = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, IsCustom, X, Y, Z FROM `areatrigger_create_properties_spline_point` ORDER BY `AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`"))
    {
        do
        {
            Field* splineFields = splines->Fetch();
            AreaTriggerCreatePropertiesId createPropertiesId = { splineFields[0].GetUInt32(), splineFields[1].GetBool() };
            splinesByCreateProperties[createPropertiesId].emplace_back(splineFields[2].GetFloat(), splineFields[3].GetFloat(), splineFields[4].GetFloat());
        }
        while (splines->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger splines. DB table `areatrigger_create_properties_spline_point` is empty.");
    }

    //                                                      0   1         2      3            4
    if (QueryResult templates = WorldDatabase.Query("SELECT Id, IsCustom, Flags, ActionSetId, ActionSetFlags FROM `areatrigger_template`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            AreaTriggerTemplate areaTriggerTemplate;
            areaTriggerTemplate.Id.Id = fields[0].GetUInt32();
            areaTriggerTemplate.Id.IsCustom = fields[1].GetBool();
            areaTriggerTemplate.Flags = AreaTriggerFlag(fields[2].GetUInt32());
            areaTriggerTemplate.ActionSetId = fields[3].GetUInt32();
            areaTriggerTemplate.ActionSetFlags = AreaTriggerActionSetFlag(fields[4].GetUInt32());
            areaTriggerTemplate.Actions = std::move(actionsByAreaTrigger[areaTriggerTemplate.Id]);

            _areaTriggerTemplateStore[areaTriggerTemplate.Id] = areaTriggerTemplate;
        }
        while (templates->NextRow());
    }

    if (QueryResult areatriggerCreateProperties = WorldDatabase.Query("SELECT Id, IsCustom, AreaTriggerId, IsAreatriggerCustom, Flags, "
        "MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, AnimId, AnimKitId, DecalPropertiesId, SpellForVisuals, TimeToTargetScale, Speed, SpeedIsTime, "
        "Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName FROM `areatrigger_create_properties`"))
    {
        do
        {
            DEFINE_FIELD_ACCESSOR_CACHE_ANONYMOUS(ResultSet, (Id)(IsCustom)(AreaTriggerId)(IsAreatriggerCustom)(Flags)
                (MoveCurveId)(ScaleCurveId)(MorphCurveId)(FacingCurveId)(AnimId)(AnimKitId)(DecalPropertiesId)(SpellForVisuals)(TimeToTargetScale)(Speed)(SpeedIsTime)
                (Shape)(ShapeData0)(ShapeData1)(ShapeData2)(ShapeData3)(ShapeData4)(ShapeData5)(ShapeData6)(ShapeData7)(ScriptName)
            ) fields { *areatriggerCreateProperties };

            AreaTriggerCreatePropertiesId createPropertiesId = { fields.Id().GetUInt32(), fields.IsCustom().GetBool() };

            AreaTriggerId areaTriggerId            = { fields.AreaTriggerId().GetUInt32(), fields.IsAreatriggerCustom().GetBool() };
            AreaTriggerTemplate const* areaTriggerTemplate = GetAreaTriggerTemplate(areaTriggerId);

            AreaTriggerShapeType shape = AreaTriggerShapeType(fields.Shape().GetUInt8());

            if (areaTriggerId.Id && !areaTriggerTemplate)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` references invalid AreaTrigger (Id: {}, IsCustom: {}) for AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {})",
                    areaTriggerId.Id, uint32(areaTriggerId.IsCustom), createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (shape == AreaTriggerShapeType::Unk || shape >= AreaTriggerShapeType::Max)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with invalid shape {}.",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), uint32(shape));
                continue;
            }

            AreaTriggerCreateProperties& createProperties = _areaTriggerCreateProperties[createPropertiesId];
            createProperties.Id = createPropertiesId;
            createProperties.Template = areaTriggerTemplate;
            createProperties.Flags = AreaTriggerCreatePropertiesFlag(fields.Flags().GetUInt32());

#define VALIDATE_AND_SET_CURVE(Curve, Value) \
            createProperties.Curve = Value; \
            if (createProperties.Curve && !sCurveStore.HasRecord(createProperties.Curve)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed AreaTrigger (Id: {}, IsCustom: {}) for AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with invalid " #Curve " ({}), set to 0!", \
                    areaTriggerId.Id, uint32(areaTriggerId.IsCustom), createPropertiesId.Id, uint32(createPropertiesId.IsCustom), createProperties.Curve); \
                createProperties.Curve = 0; \
            }

            VALIDATE_AND_SET_CURVE(MoveCurveId,   fields.MoveCurveId().GetUInt32());
            VALIDATE_AND_SET_CURVE(ScaleCurveId,  fields.ScaleCurveId().GetUInt32());
            VALIDATE_AND_SET_CURVE(MorphCurveId,  fields.MorphCurveId().GetUInt32());
            VALIDATE_AND_SET_CURVE(FacingCurveId, fields.FacingCurveId().GetUInt32());

#undef VALIDATE_AND_SET_CURVE

            createProperties.AnimId                = fields.AnimId().GetInt32();
            createProperties.AnimKitId             = fields.AnimKitId().GetInt32();

            createProperties.DecalPropertiesId     = fields.DecalPropertiesId().GetUInt32();
            createProperties.SpellForVisuals       = fields.SpellForVisuals().GetInt32OrNull();

            if (createProperties.SpellForVisuals)
            {
                if (!sSpellMgr->GetSpellInfo(*createProperties.SpellForVisuals, DIFFICULTY_NONE))
                {
                    TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with invalid SpellForVisual {}, set to none.", createPropertiesId.Id, uint32(createPropertiesId.IsCustom), *createProperties.SpellForVisuals);
                    createProperties.SpellForVisuals.reset();
                }
            }

            createProperties.TimeToTargetScale     = fields.TimeToTargetScale().GetUInt32();
            createProperties.Speed                 = fields.Speed().GetFloat();
            createProperties.SpeedIsTime           = fields.SpeedIsTime().GetBool();

            std::array<float, MAX_AREATRIGGER_ENTITY_DATA> shapeData =
            {
                fields.ShapeData0().GetFloat(), fields.ShapeData1().GetFloat(), fields.ShapeData2().GetFloat(), fields.ShapeData3().GetFloat(),
                fields.ShapeData4().GetFloat(), fields.ShapeData5().GetFloat(), fields.ShapeData6().GetFloat(), fields.ShapeData7().GetFloat()
            };

            switch (shape)
            {
                case AreaTriggerShapeType::Sphere:
                    createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::Sphere>(shapeData);
                    break;
                case AreaTriggerShapeType::Box:
                    createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::Box>(shapeData);
                    break;
                case AreaTriggerShapeType::Polygon:
                {
                    AreaTriggerShapeInfo::Polygon& polygon = createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::Polygon>(shapeData);
                    if (polygon.Height <= 0.0f)
                    {
                        polygon.Height = 1.0f;
                        if (polygon.HeightTarget <= 0.0f)
                            polygon.HeightTarget = 1.0f;
                    }
                    if (std::vector<TaggedPosition<Position::XY>>* vertices = Trinity::Containers::MapGetValuePtr(verticesByCreateProperties, createProperties.Id))
                        polygon.PolygonVertices = std::move(*vertices);
                    if (std::vector<TaggedPosition<Position::XY>>* vertices = Trinity::Containers::MapGetValuePtr(verticesTargetByCreateProperties, createProperties.Id))
                        polygon.PolygonVerticesTarget = std::move(*vertices);
                    if (!polygon.PolygonVerticesTarget.empty() && polygon.PolygonVertices.size() != polygon.PolygonVerticesTarget.size())
                    {
                        TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_polygon_vertex` has invalid target vertices, either all or none vertices must have a corresponding target vertex (AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})).",
                            createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                        polygon.PolygonVerticesTarget.clear();
                    }
                    break;
                }
                case AreaTriggerShapeType::Cylinder:
                    createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::Cylinder>(shapeData);
                    break;
                case AreaTriggerShapeType::Disk:
                    createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::Disk>(shapeData);
                    break;
                case AreaTriggerShapeType::BoundedPlane:
                    createProperties.Shape.Data.emplace<AreaTriggerShapeInfo::BoundedPlane>(shapeData);
                    break;
                default:
                    break;
            }

            createProperties.ScriptId = sObjectMgr->GetScriptId(fields.ScriptName().GetStringView());

            if (std::vector<Position>* spline = Trinity::Containers::MapGetValuePtr(splinesByCreateProperties, createProperties.Id))
                createProperties.Movement = std::move(*spline);
        }
        while (areatriggerCreateProperties->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger create properties. DB table `areatrigger_create_properties` is empty.");
    }

    //                                                                  0                              1         2                     3             4                5             6        7                 8
    if (QueryResult circularMovementInfos = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, IsCustom, ExtraTimeForBlending, CircleRadius, BlendFromRadius, InitialAngle, ZOffset, CounterClockwise, CanLoop FROM `areatrigger_create_properties_orbit`"))
    {
        do
        {
            Field* circularMovementInfoFields = circularMovementInfos->Fetch();
            AreaTriggerCreatePropertiesId createPropertiesId = { circularMovementInfoFields[0].GetUInt32(), circularMovementInfoFields[1].GetBool() };

            AreaTriggerCreateProperties* createProperties = Trinity::Containers::MapGetValuePtr(_areaTriggerCreateProperties, createPropertiesId);
            if (!createProperties)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_orbit` reference invalid AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})", createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            AreaTriggerOrbitInfo& orbit = createProperties->Movement.emplace<AreaTriggerOrbitInfo>();

            orbit.ExtraTimeForBlending = circularMovementInfoFields[2].GetInt32();

#define VALIDATE_AND_SET_FLOAT(Float, Value) \
            orbit.Float = Value; \
            if (!std::isfinite(orbit.Float)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_orbit` has listed areatrigger (AreaTriggerCreatePropertiesId: {}, IsCustom: {}) with invalid " #Float " ({}), set to 0!", \
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), orbit.Float); \
                orbit.Float = 0.0f; \
            }

            VALIDATE_AND_SET_FLOAT(Radius,          circularMovementInfoFields[3].GetFloat());
            VALIDATE_AND_SET_FLOAT(BlendFromRadius, circularMovementInfoFields[4].GetFloat());
            VALIDATE_AND_SET_FLOAT(InitialAngle,    circularMovementInfoFields[5].GetFloat());
            VALIDATE_AND_SET_FLOAT(ZOffset,         circularMovementInfoFields[6].GetFloat());

#undef VALIDATE_AND_SET_FLOAT

            orbit.CounterClockwise = circularMovementInfoFields[7].GetBool();
            orbit.CanLoop          = circularMovementInfoFields[8].GetBool();
        }
        while (circularMovementInfos->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates circular movement infos. DB table `areatrigger_create_properties_orbit` is empty.");
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} spell areatrigger templates in {} ms.", _areaTriggerTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AreaTriggerDataStore::LoadAreaTriggerSpawns()
{
    // build single time for check spawnmask
    std::unordered_map<uint32, std::set<Difficulty>> spawnMasks;
    for (MapDifficultyEntry const* mapDifficulty : sMapDifficultyStore)
        spawnMasks[mapDifficulty->MapID].insert(Difficulty(mapDifficulty->DifficultyID));

    uint32 oldMSTime = getMSTime();
    //                                                      0        1                              2         3      4                  5     6     7     8            9              10       11          12
    if (QueryResult templates = WorldDatabase.Query("SELECT SpawnId, AreaTriggerCreatePropertiesId, IsCustom, MapId, SpawnDifficulties, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup, ScriptName FROM `areatrigger`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            ObjectGuid::LowType spawnId = fields[0].GetUInt64();
            AreaTriggerCreatePropertiesId createPropertiesId = { fields[1].GetUInt32(), fields[2].GetBool() };
            WorldLocation location(fields[3].GetUInt32(), fields[5].GetFloat(), fields[6].GetFloat(), fields[7].GetFloat(), fields[8].GetFloat());

            AreaTriggerCreateProperties const* createProperties =  GetAreaTriggerCreateProperties(createPropertiesId);
            if (!createProperties)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) that doesn't exist for SpawnId {}",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), spawnId);
                continue;
            }

            if (createProperties->Flags != AreaTriggerCreatePropertiesFlag::None)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with non - zero flags",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (createProperties->ScaleCurveId || createProperties->MorphCurveId || createProperties->FacingCurveId || createProperties->MoveCurveId)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with curve values",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (createProperties->TimeToTargetScale)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with time to target values",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (!std::holds_alternative<std::monostate>(createProperties->Movement))
            {
                std::string_view movementType = std::visit([&]<typename MovementType>(MovementType const&)
                {
                    if constexpr (std::is_same_v<MovementType, AreaTriggerCreateProperties::SplineInfo>)
                        return "spline"sv;
                    else if constexpr (std::is_same_v<MovementType, AreaTriggerOrbitInfo>)
                        return "orbit"sv;
                    else if constexpr (std::is_same_v<MovementType, std::monostate>)
                        return ""sv;
                    else
                        static_assert(Trinity::dependant_false_v<MovementType>, "Unsupported movement type");
                }, createProperties->Movement);

                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with {}",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), movementType);
                continue;
            }

            if (!MapManager::IsValidMapCoord(location))
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed an invalid position: SpawnId: {}, MapId {}, Position {{}}",
                    spawnId, location.GetMapId(), location.ToString());
                continue;
            }

            std::vector<Difficulty> difficulties = sObjectMgr->ParseSpawnDifficulties(fields[4].GetStringView(), "areatrigger", spawnId, location.GetMapId(), spawnMasks[location.GetMapId()]);
            if (difficulties.empty())
            {
                TC_LOG_DEBUG("sql.sql", "Table `areatrigger` has areatrigger (GUID: {}) that is not spawned in any difficulty, skipped.", spawnId);
                continue;
            }

            AreaTriggerSpawn& spawn = _areaTriggerSpawnsBySpawnId[spawnId];
            spawn.spawnId = spawnId;
            spawn.mapId = location.GetMapId();
            spawn.Id = createPropertiesId;
            spawn.spawnPoint.Relocate(location);

            spawn.phaseUseFlags = fields[9].GetUInt8();
            spawn.phaseId = fields[10].GetUInt32();
            spawn.phaseGroup = fields[11].GetUInt32();

            spawn.scriptId = sObjectMgr->GetScriptId(fields[12].GetStringView());
            spawn.spawnGroupData = sObjectMgr->GetLegacySpawnGroup();

            // Add the trigger to a map::cell map, which is later used by GridLoader to query
            CellCoord cellCoord = Trinity::ComputeCellCoord(spawn.spawnPoint.GetPositionX(), spawn.spawnPoint.GetPositionY());
            for (Difficulty difficulty : difficulties)
                _areaTriggerSpawnsByLocation[{ spawn.mapId, difficulty }][cellCoord.GetId()].insert(spawnId);
        } while (templates->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} areatrigger spawns in {} ms.", _areaTriggerSpawnsBySpawnId.size(), GetMSTimeDiffToNow(oldMSTime));
}

AreaTriggerTemplate const* AreaTriggerDataStore::GetAreaTriggerTemplate(AreaTriggerId const& areaTriggerId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerTemplateStore, areaTriggerId);
}

AreaTriggerCreateProperties const* AreaTriggerDataStore::GetAreaTriggerCreateProperties(AreaTriggerCreatePropertiesId const& areaTriggerCreatePropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerCreateProperties, areaTriggerCreatePropertiesId);
}

std::set<ObjectGuid::LowType> const* AreaTriggerDataStore::GetAreaTriggersForMapAndCell(uint32 mapId, Difficulty difficulty, uint32 cellId) const
{
    if (auto* atForMapAndDifficulty = Trinity::Containers::MapGetValuePtr(_areaTriggerSpawnsByLocation, { mapId, difficulty }))
        return Trinity::Containers::MapGetValuePtr(*atForMapAndDifficulty, cellId);

    return nullptr;
}

AreaTriggerSpawn const* AreaTriggerDataStore::GetAreaTriggerSpawn(ObjectGuid::LowType spawnId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerSpawnsBySpawnId, spawnId);
}

AreaTriggerDataStore* AreaTriggerDataStore::Instance()
{
    static AreaTriggerDataStore instance;
    return &instance;
}
