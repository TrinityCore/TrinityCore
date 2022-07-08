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
#include "Timer.h"
#include <cmath>

bool operator==(AreaTriggerId const& left, AreaTriggerId const& right)
{
    return left.Id == right.Id && left.IsServerSide == right.IsServerSide;
}

namespace std
{
    template <>
    struct hash<AreaTriggerId>
    {
        std::size_t operator()(AreaTriggerId const& value) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, value.Id);
            Trinity::hash_combine(hashVal, value.IsServerSide);
            return hashVal;
        }
    };
}

namespace
{
    std::unordered_map<std::pair<uint32/*mapId*/, uint32/*cell_id*/>, std::set<ObjectGuid::LowType>> _areaTriggerSpawnsByLocation;
    std::unordered_map<ObjectGuid::LowType, AreaTriggerSpawn> _areaTriggerSpawnsBySpawnId;
    std::unordered_map<AreaTriggerId, AreaTriggerTemplate> _areaTriggerTemplateStore;
    std::unordered_map<uint32, AreaTriggerCreateProperties> _areaTriggerCreateProperties;
}

void AreaTriggerDataStore::LoadAreaTriggerTemplates()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesByCreateProperties;
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesTargetByCreateProperties;
    std::unordered_map<uint32, std::vector<Position>> splinesByCreateProperties;
    std::unordered_map<AreaTriggerId, std::vector<AreaTriggerAction>> actionsByAreaTrigger;

    //                                                            0              1             2           3            4
    if (QueryResult templateActions = WorldDatabase.Query("SELECT AreaTriggerId, IsServerSide, ActionType, ActionParam, TargetType FROM `areatrigger_template_actions`"))
    {
        do
        {
            Field* templateActionFields = templateActions->Fetch();
            AreaTriggerId areaTriggerId = { templateActionFields[0].GetUInt32(), templateActionFields[1].GetUInt8() == 1 };

            AreaTriggerAction action;
            action.Param       = templateActionFields[3].GetUInt32();
            uint32 actionType  = templateActionFields[2].GetUInt32();
            uint32 targetType  = templateActionFields[4].GetUInt32();

            if (actionType >= AREATRIGGER_ACTION_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid ActionType (%u,%u) for AreaTriggerId %u and Param %u",
                    actionType, areaTriggerId.Id, uint32(areaTriggerId.IsServerSide), action.Param);
                continue;
            }

            if (targetType >= AREATRIGGER_ACTION_USER_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid TargetType (%u,%u) for AreaTriggerId %u and Param %u",
                    targetType, areaTriggerId.Id, uint32(areaTriggerId.IsServerSide), action.Param);
                continue;
            }

            if (actionType == AREATRIGGER_ACTION_TELEPORT)
            {
                if (!sObjectMgr->GetWorldSafeLoc(action.Param))
                {
                    TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid entry (%u,%u) with TargetType=Teleport and Param (%u) not a valid world safe loc entry",
                        areaTriggerId.Id, uint32(areaTriggerId.IsServerSide), action.Param);
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

    //                                                     0                              1    2         3         4               5
    if (QueryResult vertices = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, Idx, VerticeX, VerticeY, VerticeTargetX, VerticeTargetY FROM `areatrigger_create_properties_polygon_vertex` ORDER BY `AreaTriggerCreatePropertiesId`, `Idx`"))
    {
        do
        {
            Field* verticeFields = vertices->Fetch();
            uint32 areaTriggerCreatePropertiesId = verticeFields[0].GetUInt32();

            verticesByCreateProperties[areaTriggerCreatePropertiesId].emplace_back(verticeFields[2].GetFloat(), verticeFields[3].GetFloat());

            if (!verticeFields[4].IsNull() && !verticeFields[5].IsNull())
                verticesTargetByCreateProperties[areaTriggerCreatePropertiesId].emplace_back(verticeFields[4].GetFloat(), verticeFields[5].GetFloat());
            else if (verticeFields[4].IsNull() != verticeFields[5].IsNull())
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_polygon_vertex` has listed invalid target vertices (AreaTriggerCreatePropertiesId: %u, Index: %u).", areaTriggerCreatePropertiesId, verticeFields[1].GetUInt32());
        }
        while (vertices->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger polygon vertices. DB table `areatrigger_create_properties_polygon_vertex` is empty.");
    }

    //                                                    0                              1  2  3
    if (QueryResult splines = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, X, Y, Z FROM `areatrigger_create_properties_spline_point` ORDER BY `AreaTriggerCreatePropertiesId`, `Idx`"))
    {
        do
        {
            Field* splineFields = splines->Fetch();
            uint32 areaTriggerCreatePropertiesId = splineFields[0].GetUInt32();
            splinesByCreateProperties[areaTriggerCreatePropertiesId].emplace_back(splineFields[1].GetFloat(), splineFields[2].GetFloat(), splineFields[3].GetFloat());
        }
        while (splines->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger splines. DB table `areatrigger_create_properties_spline_point` is empty.");
    }

    //                                                      0   1             2
    if (QueryResult templates = WorldDatabase.Query("SELECT Id, IsServerSide, Flags FROM `areatrigger_template`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            AreaTriggerTemplate areaTriggerTemplate;
            areaTriggerTemplate.Id.Id = fields[0].GetUInt32();
            areaTriggerTemplate.Id.IsServerSide = fields[1].GetUInt8() == 1;
            areaTriggerTemplate.Flags = fields[2].GetUInt32();

            if (areaTriggerTemplate.Id.IsServerSide && areaTriggerTemplate.Flags != 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template` has listed server-side areatrigger (Id: %u, IsServerSide: %u) with non-zero flags",
                    areaTriggerTemplate.Id.Id, uint32(areaTriggerTemplate.Id.IsServerSide));
                continue;
            }

            areaTriggerTemplate.Actions = std::move(actionsByAreaTrigger[areaTriggerTemplate.Id]);

            _areaTriggerTemplateStore[areaTriggerTemplate.Id] = areaTriggerTemplate;
        }
        while (templates->NextRow());
    }

    //                                                                        0   1              2            3             4             5              6       7          8                  9             10
    if (QueryResult areatriggerCreateProperties = WorldDatabase.Query("SELECT Id, AreaTriggerId, MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, AnimId, AnimKitId, DecalPropertiesId, TimeToTarget, TimeToTargetScale, "
    //   11     12          13          14          15          16          17          18          19          20
        "Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName FROM `areatrigger_create_properties`"))
    {
        do
        {
            AreaTriggerCreateProperties createProperties;

            Field* fields = areatriggerCreateProperties->Fetch();
            createProperties.Id                    = fields[0].GetUInt32();

            uint32 areatriggerId                   = fields[1].GetUInt32();
            createProperties.Template              = GetAreaTriggerTemplate({ areatriggerId, false });

            uint8 shape = fields[11].GetUInt8();

            if (areatriggerId && !createProperties.Template)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` references invalid AreaTriggerId %u for AreaTriggerCreatePropertiesId %u", areatriggerId, createProperties.Id);
                continue;
            }

            if (shape >= AREATRIGGER_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed areatrigger create properties %u with invalid shape %u.",
                    createProperties.Id, uint32(shape));
                continue;
            }

#define VALIDATE_AND_SET_CURVE(Curve, Value) \
            createProperties.Curve = Value; \
            if (createProperties.Curve && !sCurveStore.LookupEntry(createProperties.Curve)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties` has listed areatrigger (AreaTriggerCreatePropertiesId: %u, Id: %u) with invalid " #Curve " (%u), set to 0!", \
                    createProperties.Id, areatriggerId, createProperties.Curve); \
                createProperties.Curve = 0; \
            }

            VALIDATE_AND_SET_CURVE(MoveCurveId,   fields[2].GetUInt32());
            VALIDATE_AND_SET_CURVE(ScaleCurveId,  fields[3].GetUInt32());
            VALIDATE_AND_SET_CURVE(MorphCurveId,  fields[4].GetUInt32());
            VALIDATE_AND_SET_CURVE(FacingCurveId, fields[5].GetUInt32());

#undef VALIDATE_AND_SET_CURVE

            createProperties.AnimId                = fields[6].GetInt32();
            createProperties.AnimKitId             = fields[7].GetInt32();

            createProperties.DecalPropertiesId     = fields[8].GetUInt32();

            createProperties.TimeToTarget          = fields[9].GetUInt32();
            createProperties.TimeToTargetScale     = fields[10].GetUInt32();

            createProperties.Shape.Type = static_cast<AreaTriggerTypes>(shape);
            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                createProperties.Shape.DefaultDatas.Data[i] = fields[12 + i].GetFloat();

            createProperties.ScriptId = sObjectMgr->GetScriptId(fields[20].GetString());

            if (shape == AREATRIGGER_TYPE_POLYGON)
                if (createProperties.Shape.PolygonDatas.Height <= 0.0f)
                    createProperties.Shape.PolygonDatas.Height = 1.0f;

            createProperties.PolygonVertices       = std::move(verticesByCreateProperties[createProperties.Id]);
            createProperties.PolygonVerticesTarget = std::move(verticesTargetByCreateProperties[createProperties.Id]);
            createProperties.SplinePoints          = std::move(splinesByCreateProperties[createProperties.Id]);

            _areaTriggerCreateProperties[createProperties.Id] = createProperties;
        }
        while (areatriggerCreateProperties->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger create properties. DB table `areatrigger_create_properties` is empty.");
    }

    //                                                                  0                              1           2             3                4             5        6                 7
    if (QueryResult circularMovementInfos = WorldDatabase.Query("SELECT AreaTriggerCreatePropertiesId, StartDelay, CircleRadius, BlendFromRadius, InitialAngle, ZOffset, CounterClockwise, CanLoop FROM `areatrigger_create_properties_orbit`"))
    {
        do
        {
            Field* circularMovementInfoFields = circularMovementInfos->Fetch();
            uint32 areaTriggerCreatePropertiesId = circularMovementInfoFields[0].GetUInt32();

            AreaTriggerCreateProperties* createProperties = Trinity::Containers::MapGetValuePtr(_areaTriggerCreateProperties, areaTriggerCreatePropertiesId);
            if (!createProperties)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_orbit` reference invalid AreaTriggerCreatePropertiesId %u", areaTriggerCreatePropertiesId);
                continue;
            }

            createProperties->OrbitInfo.emplace();

            createProperties->OrbitInfo->StartDelay       = circularMovementInfoFields[1].GetUInt32();

#define VALIDATE_AND_SET_FLOAT(Float, Value) \
            createProperties->OrbitInfo->Float = Value; \
            if (!std::isfinite(createProperties->OrbitInfo->Float)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_create_properties_orbit` has listed areatrigger (AreaTriggerCreatePropertiesId: %u) with invalid " #Float " (%f), set to 0!", \
                    areaTriggerCreatePropertiesId, createProperties->OrbitInfo->Float); \
                createProperties->OrbitInfo->Float = 0.0f; \
            }

            VALIDATE_AND_SET_FLOAT(Radius,          circularMovementInfoFields[2].GetFloat());
            VALIDATE_AND_SET_FLOAT(BlendFromRadius, circularMovementInfoFields[3].GetFloat());
            VALIDATE_AND_SET_FLOAT(InitialAngle,    circularMovementInfoFields[4].GetFloat());
            VALIDATE_AND_SET_FLOAT(ZOffset,         circularMovementInfoFields[5].GetFloat());

#undef VALIDATE_AND_SET_FLOAT

            createProperties->OrbitInfo->CounterClockwise = circularMovementInfoFields[6].GetBool();
            createProperties->OrbitInfo->CanLoop          = circularMovementInfoFields[7].GetBool();
        }
        while (circularMovementInfos->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates circular movement infos. DB table `areatrigger_create_properties_orbit` is empty.");
    }

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " spell areatrigger templates in %u ms.", _areaTriggerTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AreaTriggerDataStore::LoadAreaTriggerSpawns()
{
    uint32 oldMSTime = getMSTime();
    // Load area trigger positions (to put them on the server)
    //                                                      0        1              2             3      4     5     6     7            8              9        10
    if (QueryResult templates = WorldDatabase.Query("SELECT SpawnId, AreaTriggerId, IsServerSide, MapId, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup, "
    //   11     12          13          14          15          16          17          18          19          20
        "Shape, ShapeData0, ShapeData1, ShapeData2, ShapeData3, ShapeData4, ShapeData5, ShapeData6, ShapeData7, ScriptName FROM `areatrigger`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            ObjectGuid::LowType spawnId = fields[0].GetUInt64();
            AreaTriggerId areaTriggerid = { fields[1].GetUInt32(), fields[2].GetUInt8() == 1 };
            WorldLocation location(fields[3].GetUInt32(), fields[4].GetFloat(), fields[5].GetFloat(), fields[6].GetFloat(), fields[7].GetFloat());
            uint8 shape = fields[11].GetUInt8();

            if (!GetAreaTriggerTemplate(areaTriggerid))
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed areatrigger that doesn't exist: Id: %u, IsServerSide: %u for SpawnId " UI64FMTD,
                    areaTriggerid.Id, uint32(areaTriggerid.IsServerSide), spawnId);
                continue;
            }

            if (!MapManager::IsValidMapCoord(location))
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed an invalid position: SpawnId: " UI64FMTD ", MapId %u, Position {%s}",
                    spawnId, location.GetMapId(), location.ToString().c_str());
                continue;
            }

            if (shape >= AREATRIGGER_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger` has listed areatrigger SpawnId: " UI64FMTD " with invalid shape %u.",
                    spawnId, uint32(shape));
                continue;
            }

            AreaTriggerSpawn& spawn = _areaTriggerSpawnsBySpawnId[spawnId];
            spawn.spawnId = spawnId;
            spawn.mapId = location.GetMapId();
            spawn.Id = areaTriggerid;
            spawn.spawnPoint.Relocate(location);

            spawn.phaseUseFlags = fields[8].GetUInt8();
            spawn.phaseId = fields[9].GetUInt32();
            spawn.phaseGroup = fields[10].GetUInt32();

            spawn.Shape.Type = static_cast<AreaTriggerTypes>(shape);
            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                spawn.Shape.DefaultDatas.Data[i] = fields[12 + i].GetFloat();

            spawn.scriptId = sObjectMgr->GetScriptId(fields[20].GetString());
            spawn.spawnGroupData = sObjectMgr->GetLegacySpawnGroup();

            // Add the trigger to a map::cell map, which is later used by GridLoader to query
            CellCoord cellCoord = Trinity::ComputeCellCoord(spawn.spawnPoint.GetPositionX(), spawn.spawnPoint.GetPositionY());
            _areaTriggerSpawnsByLocation[{ spawn.mapId, cellCoord.GetId() }].insert(spawnId);
        } while (templates->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " areatrigger spawns in %u ms.", _areaTriggerSpawnsBySpawnId.size(), GetMSTimeDiffToNow(oldMSTime));
}

AreaTriggerTemplate const* AreaTriggerDataStore::GetAreaTriggerTemplate(AreaTriggerId const& areaTriggerId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerTemplateStore, areaTriggerId);
}

AreaTriggerCreateProperties const* AreaTriggerDataStore::GetAreaTriggerCreateProperties(uint32 areaTriggerCreatePropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerCreateProperties, areaTriggerCreatePropertiesId);
}

std::set<ObjectGuid::LowType> const* AreaTriggerDataStore::GetAreaTriggersForMapAndCell(uint32 mapId, uint32 cellId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerSpawnsByLocation, { mapId, cellId });
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
