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
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Timer.h"
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

    //                                                      0   1         2
    if (QueryResult templates = WorldDatabase.Query("SELECT Id, IsCustom, Flags FROM `areatrigger_template`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            AreaTriggerTemplate areaTriggerTemplate;
            areaTriggerTemplate.Id.Id = fields[0].GetUInt32();
            areaTriggerTemplate.Id.IsCustom = fields[1].GetBool();
            areaTriggerTemplate.Flags = AreaTriggerFlag(fields[2].GetUInt32());
            areaTriggerTemplate.Actions = std::move(actionsByAreaTrigger[areaTriggerTemplate.Id]);

            _areaTriggerTemplateStore[areaTriggerTemplate.Id] = areaTriggerTemplate;
        }
        while (templates->NextRow());
    }

    //                                                                        0   1         2              3                    4
    if (QueryResult areatriggerCreateProperties = WorldDatabase.Query("SELECT Id, IsCustom, AreaTriggerId, IsAreatriggerCustom, Flags, "
    //   5            6             7             8              9       10         11                 12            13
        "MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, AnimId, AnimKitId, DecalPropertiesId, TimeToTarget, TimeToTargetScale, "
    //   14     15          16          17          18          19          20          21          22          23
        "Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName FROM `areatrigger_create_properties`"))
    {
        do
        {
            AreaTriggerCreateProperties createProperties;

            Field* fields = areatriggerCreateProperties->Fetch();
            AreaTriggerCreatePropertiesId createPropertiesId = { fields[0].GetUInt32(), fields[1].GetBool() };
            createProperties.Id = createPropertiesId;

            AreaTriggerId areaTriggerId            = { fields[2].GetUInt32(), fields[3].GetBool() };
            createProperties.Template              = GetAreaTriggerTemplate(areaTriggerId);

            createProperties.Flags = AreaTriggerCreatePropertiesFlag(fields[4].GetUInt32());

            AreaTriggerShapeType shape = AreaTriggerShapeType(fields[14].GetUInt8());

            if (areaTriggerId.Id && !createProperties.Template)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` references invalid AreaTrigger (Id: {}, IsCustom: {}) for AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {})",
                    areaTriggerId.Id, uint32(areaTriggerId.IsCustom), createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (shape >= AreaTriggerShapeType::Max)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with invalid shape {}.",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), uint32(shape));
                continue;
            }

#define VALIDATE_AND_SET_CURVE(Curve, Value) \
            createProperties.Curve = Value; \
            if (createProperties.Curve && !sCurveStore.LookupEntry(createProperties.Curve)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed AreaTrigger (Id: {}, IsCustom: {}) for AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with invalid " #Curve " ({}), set to 0!", \
                    areaTriggerId.Id, uint32(areaTriggerId.IsCustom), createPropertiesId.Id, uint32(createPropertiesId.IsCustom), createProperties.Curve); \
                createProperties.Curve = 0; \
            }

            VALIDATE_AND_SET_CURVE(MoveCurveId,   fields[5].GetUInt32());
            VALIDATE_AND_SET_CURVE(ScaleCurveId,  fields[6].GetUInt32());
            VALIDATE_AND_SET_CURVE(MorphCurveId,  fields[7].GetUInt32());
            VALIDATE_AND_SET_CURVE(FacingCurveId, fields[8].GetUInt32());

#undef VALIDATE_AND_SET_CURVE

            createProperties.AnimId                = fields[9].GetInt32();
            createProperties.AnimKitId             = fields[10].GetInt32();

            createProperties.DecalPropertiesId     = fields[11].GetUInt32();

            createProperties.TimeToTarget          = fields[12].GetUInt32();
            createProperties.TimeToTargetScale     = fields[13].GetUInt32();

            createProperties.Shape.Type = static_cast<AreaTriggerShapeType>(shape);
            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                createProperties.Shape.DefaultDatas.Data[i] = fields[15 + i].GetFloat();

            createProperties.ScriptId = sObjectMgr->GetScriptId(fields[23].GetString());

            if (shape == AreaTriggerShapeType::Polygon)
            {
                if (createProperties.Shape.PolygonDatas.Height <= 0.0f)
                {
                    createProperties.Shape.PolygonDatas.Height = 1.0f;
                    if (createProperties.Shape.PolygonDatas.HeightTarget <= 0.0f)
                        createProperties.Shape.PolygonDatas.HeightTarget = 1.0f;
                }
            }

            createProperties.Shape.PolygonVertices       = std::move(verticesByCreateProperties[createProperties.Id]);
            createProperties.Shape.PolygonVerticesTarget = std::move(verticesTargetByCreateProperties[createProperties.Id]);
            if (!createProperties.Shape.PolygonVerticesTarget.empty() && createProperties.Shape.PolygonVertices.size() != createProperties.Shape.PolygonVerticesTarget.size())
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_polygon_vertex` has invalid target vertices, either all or none vertices must have a corresponding target vertex (AreaTriggerCreatePropertiesId: (Id: {}, IsCustom: {})).",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                createProperties.Shape.PolygonVerticesTarget.clear();
            }

            createProperties.SplinePoints          = std::move(splinesByCreateProperties[createProperties.Id]);

            _areaTriggerCreateProperties[createProperties.Id] = createProperties;
        }
        while (areatriggerCreateProperties->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger create properties. DB table `areatrigger_create_properties` is empty.");
    }

    //                                                                  0                              1         2           3             4                5             6        7                 8
    if (QueryResult circularMovementInfos = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, IsCustom, StartDelay, CircleRadius, BlendFromRadius, InitialAngle, ZOffset, CounterClockwise, CanLoop FROM `areatrigger_create_properties_orbit`"))
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

            createProperties->OrbitInfo.emplace();

            createProperties->OrbitInfo->StartDelay       = circularMovementInfoFields[2].GetUInt32();

#define VALIDATE_AND_SET_FLOAT(Float, Value) \
            createProperties->OrbitInfo->Float = Value; \
            if (!std::isfinite(createProperties->OrbitInfo->Float)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_orbit` has listed areatrigger (AreaTriggerCreatePropertiesId: {}, IsCustom: {}) with invalid " #Float " ({}), set to 0!", \
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom), createProperties->OrbitInfo->Float); \
                createProperties->OrbitInfo->Float = 0.0f; \
            }

            VALIDATE_AND_SET_FLOAT(Radius,          circularMovementInfoFields[3].GetFloat());
            VALIDATE_AND_SET_FLOAT(BlendFromRadius, circularMovementInfoFields[4].GetFloat());
            VALIDATE_AND_SET_FLOAT(InitialAngle,    circularMovementInfoFields[5].GetFloat());
            VALIDATE_AND_SET_FLOAT(ZOffset,         circularMovementInfoFields[6].GetFloat());

#undef VALIDATE_AND_SET_FLOAT

            createProperties->OrbitInfo->CounterClockwise = circularMovementInfoFields[7].GetBool();
            createProperties->OrbitInfo->CanLoop          = circularMovementInfoFields[8].GetBool();
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
    //                                                      0        1                              2         3      4                  5     6     7     8            9              10       11          12               13
    if (QueryResult templates = WorldDatabase.Query("SELECT SpawnId, AreaTriggerCreatePropertiesId, IsCustom, MapId, SpawnDifficulties, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup, SpellForVisuals, ScriptName FROM `areatrigger`"))
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
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) that doesn't exist for SpawnId " UI64FMTD,
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

            if (createProperties->TimeToTarget || createProperties->TimeToTargetScale || createProperties->FacingCurveId || createProperties->MoveCurveId)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with time to target values",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (createProperties->OrbitInfo)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with orbit info",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
                continue;
            }

            if (createProperties->HasSplines())
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed AreaTriggerCreatePropertiesId (Id: {}, IsCustom: {}) with splines",
                    createPropertiesId.Id, uint32(createPropertiesId.IsCustom));
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

            if (!fields[12].IsNull())
            {
                spawn.SpellForVisuals = fields[12].GetInt32();
                if (!sSpellMgr->GetSpellInfo(spawn.SpellForVisuals.value(), DIFFICULTY_NONE))
                {
                    TC_LOG_ERROR("sql.sql", "Table `areatrigger` has areatrigger (GUID: {}) with invalid SpellForVisual {}, set to none.", spawnId, *spawn.SpellForVisuals);
                    spawn.SpellForVisuals.reset();
                }
            }

            spawn.scriptId = sObjectMgr->GetScriptId(fields[13].GetString());
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
