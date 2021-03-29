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
    std::unordered_map<uint32, AreaTriggerSpawn> _areaTriggerSpawnsBySpawnId;
    std::unordered_map<AreaTriggerId, AreaTriggerTemplate> _areaTriggerTemplateStore;
    std::unordered_map<uint32, AreaTriggerMiscTemplate> _areaTriggerTemplateSpellMisc;
}

void AreaTriggerDataStore::LoadAreaTriggerTemplates()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesByAreaTrigger;
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesTargetByAreaTrigger;
    std::unordered_map<uint32, std::vector<Position>> splinesBySpellMisc;
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

    //                                                     0              1    2         3         4               5
    if (QueryResult vertices = WorldDatabase.Query("SELECT AreaTriggerId, Idx, VerticeX, VerticeY, VerticeTargetX, VerticeTargetY FROM `areatrigger_template_polygon_vertices` ORDER BY `AreaTriggerId`, `Idx`"))
    {
        do
        {
            Field* verticeFields = vertices->Fetch();
            uint32 areaTriggerId = verticeFields[0].GetUInt32();

            verticesByAreaTrigger[areaTriggerId].emplace_back(verticeFields[2].GetFloat(), verticeFields[3].GetFloat());

            if (!verticeFields[4].IsNull() && !verticeFields[5].IsNull())
                verticesTargetByAreaTrigger[areaTriggerId].emplace_back(verticeFields[4].GetFloat(), verticeFields[5].GetFloat());
            else if (verticeFields[4].IsNull() != verticeFields[5].IsNull())
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_polygon_vertices` has listed invalid target vertices (AreaTrigger: %u, Index: %u).", areaTriggerId, verticeFields[1].GetUInt32());
        }
        while (vertices->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates polygon vertices. DB table `areatrigger_template_polygon_vertices` is empty.");
    }

    //                                                    0            1  2  3
    if (QueryResult splines = WorldDatabase.Query("SELECT SpellMiscId, X, Y, Z FROM `spell_areatrigger_splines` ORDER BY `SpellMiscId`, `Idx`"))
    {
        do
        {
            Field* splineFields = splines->Fetch();
            uint32 spellMiscId = splineFields[0].GetUInt32();
            splinesBySpellMisc[spellMiscId].emplace_back(splineFields[1].GetFloat(), splineFields[2].GetFloat(), splineFields[3].GetFloat());
        }
        while (splines->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates splines. DB table `spell_areatrigger_splines` is empty.");
    }

    //                                                      0   1             2     3      4      5      6      7      8      9      10
    if (QueryResult templates = WorldDatabase.Query("SELECT Id, IsServerSide, Type, Flags, Data0, Data1, Data2, Data3, Data4, Data5, ScriptName FROM `areatrigger_template`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            AreaTriggerTemplate areaTriggerTemplate;
            areaTriggerTemplate.Id.Id = fields[0].GetUInt32();
            areaTriggerTemplate.Id.IsServerSide = fields[1].GetUInt8() == 1;
            uint8 type = fields[2].GetUInt8();

            if (type >= AREATRIGGER_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template` has listed areatrigger (Id: %u, IsServerSide: %u) with invalid type %u.",
                    areaTriggerTemplate.Id.Id, uint32(areaTriggerTemplate.Id.IsServerSide), type);
                continue;
            }

            areaTriggerTemplate.Type = static_cast<AreaTriggerTypes>(type);
            areaTriggerTemplate.Flags = fields[3].GetUInt32();

            if (areaTriggerTemplate.Id.IsServerSide && areaTriggerTemplate.Flags != 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template` has listed server-side areatrigger (Id: %u, IsServerSide: %u) with non-zero flags",
                    areaTriggerTemplate.Id.Id, uint32(areaTriggerTemplate.Id.IsServerSide));
                continue;
            }

            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                areaTriggerTemplate.DefaultDatas.Data[i] = fields[4 + i].GetFloat();

            areaTriggerTemplate.ScriptId = sObjectMgr->GetScriptId(fields[10].GetString());
            if (!areaTriggerTemplate.Id.IsServerSide)
            {
                areaTriggerTemplate.PolygonVertices = std::move(verticesByAreaTrigger[areaTriggerTemplate.Id.Id]);
                areaTriggerTemplate.PolygonVerticesTarget = std::move(verticesTargetByAreaTrigger[areaTriggerTemplate.Id.Id]);
            }
            areaTriggerTemplate.Actions = std::move(actionsByAreaTrigger[areaTriggerTemplate.Id]);

            areaTriggerTemplate.InitMaxSearchRadius();
            _areaTriggerTemplateStore[areaTriggerTemplate.Id] = areaTriggerTemplate;
        }
        while (templates->NextRow());
    }

    //                                                                  0            1              2            3             4             5              6       7          8                  9             10
    if (QueryResult areatriggerSpellMiscs = WorldDatabase.Query("SELECT SpellMiscId, AreaTriggerId, MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, AnimId, AnimKitId, DecalPropertiesId, TimeToTarget, TimeToTargetScale FROM `spell_areatrigger`"))
    {
        do
        {
            AreaTriggerMiscTemplate miscTemplate;

            Field* areatriggerSpellMiscFields = areatriggerSpellMiscs->Fetch();
            miscTemplate.MiscId             = areatriggerSpellMiscFields[0].GetUInt32();

            uint32 areatriggerId            = areatriggerSpellMiscFields[1].GetUInt32();
            miscTemplate.Template           = GetAreaTriggerTemplate({ areatriggerId, false });

            if (!miscTemplate.Template)
            {
                TC_LOG_ERROR("sql.sql", "Table `spell_areatrigger` reference invalid AreaTriggerId %u for miscId %u", areatriggerId, miscTemplate.MiscId);
                continue;
            }

#define VALIDATE_AND_SET_CURVE(Curve, Value) \
            miscTemplate.Curve = Value; \
            if (miscTemplate.Curve && !sCurveStore.LookupEntry(miscTemplate.Curve)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `spell_areatrigger` has listed areatrigger (MiscId: %u, Id: %u) with invalid " #Curve " (%u), set to 0!", \
                    miscTemplate.MiscId, areatriggerId, miscTemplate.Curve); \
                miscTemplate.Curve = 0; \
            }

            VALIDATE_AND_SET_CURVE(MoveCurveId,   areatriggerSpellMiscFields[2].GetUInt32());
            VALIDATE_AND_SET_CURVE(ScaleCurveId,  areatriggerSpellMiscFields[3].GetUInt32());
            VALIDATE_AND_SET_CURVE(MorphCurveId,  areatriggerSpellMiscFields[4].GetUInt32());
            VALIDATE_AND_SET_CURVE(FacingCurveId, areatriggerSpellMiscFields[5].GetUInt32());

#undef VALIDATE_AND_SET_CURVE

            miscTemplate.AnimId = areatriggerSpellMiscFields[6].GetInt32();
            miscTemplate.AnimKitId = areatriggerSpellMiscFields[7].GetInt32();

            miscTemplate.DecalPropertiesId = areatriggerSpellMiscFields[8].GetUInt32();

            miscTemplate.TimeToTarget       = areatriggerSpellMiscFields[9].GetUInt32();
            miscTemplate.TimeToTargetScale  = areatriggerSpellMiscFields[10].GetUInt32();

            miscTemplate.SplinePoints = std::move(splinesBySpellMisc[miscTemplate.MiscId]);

            _areaTriggerTemplateSpellMisc[miscTemplate.MiscId] = miscTemplate;
        }
        while (areatriggerSpellMiscs->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Spell AreaTrigger templates. DB table `spell_areatrigger` is empty.");
    }

    //                                                                  0            1           2             3                4             5        6                 7
    if (QueryResult circularMovementInfos = WorldDatabase.Query("SELECT SpellMiscId, StartDelay, CircleRadius, BlendFromRadius, InitialAngle, ZOffset, CounterClockwise, CanLoop FROM `spell_areatrigger_circular` ORDER BY `SpellMiscId`"))
    {
        do
        {
            Field* circularMovementInfoFields = circularMovementInfos->Fetch();
            uint32 spellMiscId = circularMovementInfoFields[0].GetUInt32();

            auto atSpellMiscItr = _areaTriggerTemplateSpellMisc.find(spellMiscId);
            if (atSpellMiscItr == _areaTriggerTemplateSpellMisc.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `spell_areatrigger_circular` reference invalid SpellMiscId %u", spellMiscId);
                continue;
            }

            AreaTriggerOrbitInfo& orbitInfo = atSpellMiscItr->second.OrbitInfo;

            orbitInfo.StartDelay                    = circularMovementInfoFields[1].GetUInt32();

#define VALIDATE_AND_SET_FLOAT(Float, Value) \
            orbitInfo.Float = Value; \
            if (!std::isfinite(orbitInfo.Float)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `spell_areatrigger_circular` has listed areatrigger (MiscId: %u) with invalid " #Float " (%f), set to 0!", \
                    spellMiscId, orbitInfo.Float); \
                orbitInfo.Float = 0.0f; \
            }

            VALIDATE_AND_SET_FLOAT(Radius,          circularMovementInfoFields[2].GetFloat());
            VALIDATE_AND_SET_FLOAT(BlendFromRadius, circularMovementInfoFields[3].GetFloat());
            VALIDATE_AND_SET_FLOAT(InitialAngle,    circularMovementInfoFields[4].GetFloat());
            VALIDATE_AND_SET_FLOAT(ZOffset,         circularMovementInfoFields[5].GetFloat());

#undef VALIDATE_AND_SET_FLOAT

            orbitInfo.CounterClockwise              = circularMovementInfoFields[6].GetBool();
            orbitInfo.CanLoop                       = circularMovementInfoFields[7].GetBool();
        }
        while (circularMovementInfos->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates circular movement infos. DB table `spell_areatrigger_circular` is empty.");
    }

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " spell areatrigger templates in %u ms.", _areaTriggerTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AreaTriggerDataStore::LoadAreaTriggerSpawns()
{
    uint32 oldMSTime = getMSTime();
    // Load area trigger positions (to put them on the server)
    //                                                      0        1              2             3      4     5     6     7            8              9        10
    if (QueryResult templates = WorldDatabase.Query("SELECT SpawnId, AreaTriggerId, IsServerSide, MapId, PosX, PosY, PosZ, Orientation, PhaseUseFlags, PhaseId, PhaseGroup FROM `areatrigger`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            ObjectGuid::LowType spawnId = fields[0].GetUInt64();
            AreaTriggerId areaTriggerid = { fields[1].GetUInt32(), fields[2].GetUInt8() == 1 };
            WorldLocation location(fields[3].GetUInt32(), fields[4].GetFloat(), fields[5].GetFloat(), fields[6].GetFloat(), fields[7].GetFloat());

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

            AreaTriggerSpawn spawn;
            spawn.SpawnId = spawnId;
            spawn.Id = areaTriggerid;
            spawn.Location.WorldRelocate(location);

            spawn.PhaseUseFlags = fields[8].GetUInt8();
            spawn.PhaseId = fields[9].GetUInt32();
            spawn.PhaseGroup = fields[10].GetUInt32();

            // Add the trigger to a map::cell map, which is later used by GridLoader to query
            CellCoord cellCoord = Trinity::ComputeCellCoord(spawn.Location.GetPositionX(), spawn.Location.GetPositionY());
            _areaTriggerSpawnsByLocation[{ spawn.Location.GetMapId(), cellCoord.GetId() }].insert(spawnId);

            // add the position to the map
            _areaTriggerSpawnsBySpawnId[spawnId] = spawn;
        } while (templates->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " areatrigger spawns in %u ms.", _areaTriggerSpawnsBySpawnId.size(), GetMSTimeDiffToNow(oldMSTime));
}

AreaTriggerTemplate const* AreaTriggerDataStore::GetAreaTriggerTemplate(AreaTriggerId const& areaTriggerId) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerTemplateStore, areaTriggerId);
}

AreaTriggerMiscTemplate const* AreaTriggerDataStore::GetAreaTriggerMiscTemplate(uint32 spellMiscValue) const
{
    return Trinity::Containers::MapGetValuePtr(_areaTriggerTemplateSpellMisc, spellMiscValue);
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
