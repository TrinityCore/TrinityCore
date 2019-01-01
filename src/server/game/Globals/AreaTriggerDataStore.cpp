/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Timer.h"
#include <cmath>

namespace
{
    std::unordered_map<uint32, AreaTriggerTemplate> _areaTriggerTemplateStore;
    std::unordered_map<uint32, AreaTriggerMiscTemplate> _areaTriggerTemplateSpellMisc;
}

void AreaTriggerDataStore::LoadAreaTriggerTemplates()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesByAreaTrigger;
    std::unordered_map<uint32, std::vector<TaggedPosition<Position::XY>>> verticesTargetByAreaTrigger;
    std::unordered_map<uint32, std::vector<Position>> splinesBySpellMisc;
    std::unordered_map<uint32, std::vector<AreaTriggerAction>> actionsByAreaTrigger;

    //                                                            0              1           2            3
    if (QueryResult templateActions = WorldDatabase.Query("SELECT AreaTriggerId, ActionType, ActionParam, TargetType FROM `areatrigger_template_actions`"))
    {
        do
        {
            Field* templateActionFields = templateActions->Fetch();
            uint32 areaTriggerId = templateActionFields[0].GetUInt32();

            AreaTriggerAction action;
            action.Param       = templateActionFields[2].GetUInt32();
            uint32 actionType  = templateActionFields[1].GetUInt32();
            uint32 targetType  = templateActionFields[3].GetUInt32();

            if (actionType >= AREATRIGGER_ACTION_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid ActionType (%u) for AreaTriggerId %u and Param %u", actionType, areaTriggerId, action.Param);
                continue;
            }

            if (targetType >= AREATRIGGER_ACTION_USER_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_actions` has invalid TargetType (%u) for AreaTriggerId %u and Param %u", targetType, areaTriggerId, action.Param);
                continue;
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

    //                                                      0   1     2      3      4      5      6      7      8      9
    if (QueryResult templates = WorldDatabase.Query("SELECT Id, Type, Flags, Data0, Data1, Data2, Data3, Data4, Data5, ScriptName FROM `areatrigger_template`"))
    {
        do
        {
            Field* fields = templates->Fetch();

            AreaTriggerTemplate areaTriggerTemplate;
            areaTriggerTemplate.Id = fields[0].GetUInt32();
            uint8 type = fields[1].GetUInt8();

            if (type >= AREATRIGGER_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template` has listed areatrigger (Id: %u) with invalid type %u.", areaTriggerTemplate.Id, type);
                continue;
            }

            areaTriggerTemplate.Type = static_cast<AreaTriggerTypes>(type);
            areaTriggerTemplate.Flags = fields[2].GetUInt32();

            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                areaTriggerTemplate.DefaultDatas.Data[i] = fields[3 + i].GetFloat();

            areaTriggerTemplate.ScriptId = sObjectMgr->GetScriptId(fields[9].GetString());
            areaTriggerTemplate.PolygonVertices = std::move(verticesByAreaTrigger[areaTriggerTemplate.Id]);
            areaTriggerTemplate.PolygonVerticesTarget = std::move(verticesTargetByAreaTrigger[areaTriggerTemplate.Id]);
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
            miscTemplate.Template           = GetAreaTriggerTemplate(areatriggerId);

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

            AreaTriggerCircularMovementInfo& circularMovementInfo = atSpellMiscItr->second.CircularMovementInfo;

            circularMovementInfo.StartDelay         = circularMovementInfoFields[1].GetUInt32();

#define VALIDATE_AND_SET_FLOAT(Float, Value) \
            circularMovementInfo.Float = Value; \
            if (!std::isfinite(circularMovementInfo.Float)) \
            { \
                TC_LOG_ERROR("sql.sql", "Table `spell_areatrigger_circular` has listed areatrigger (MiscId: %u) with invalid " #Float " (%f), set to 0!", \
                    spellMiscId, circularMovementInfo.Float); \
                circularMovementInfo.Float = 0.0f; \
            }

            VALIDATE_AND_SET_FLOAT(Radius,          circularMovementInfoFields[2].GetFloat());
            VALIDATE_AND_SET_FLOAT(BlendFromRadius, circularMovementInfoFields[3].GetFloat());
            VALIDATE_AND_SET_FLOAT(InitialAngle,    circularMovementInfoFields[4].GetFloat());
            VALIDATE_AND_SET_FLOAT(ZOffset,         circularMovementInfoFields[5].GetFloat());

#undef VALIDATE_AND_SET_FLOAT

            circularMovementInfo.CounterClockwise   = circularMovementInfoFields[6].GetBool();
            circularMovementInfo.CanLoop            = circularMovementInfoFields[7].GetBool();
        }
        while (circularMovementInfos->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates circular movement infos. DB table `spell_areatrigger_circular` is empty.");
    }

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " spell areatrigger templates in %u ms.", _areaTriggerTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

AreaTriggerTemplate const* AreaTriggerDataStore::GetAreaTriggerTemplate(uint32 areaTriggerId) const
{
    auto itr = _areaTriggerTemplateStore.find(areaTriggerId);
    if (itr != _areaTriggerTemplateStore.end())
        return &itr->second;

    return nullptr;
}

AreaTriggerMiscTemplate const* AreaTriggerDataStore::GetAreaTriggerMiscTemplate(uint32 spellMiscValue) const
{
    auto itr = _areaTriggerTemplateSpellMisc.find(spellMiscValue);
    if (itr != _areaTriggerTemplateSpellMisc.end())
        return &itr->second;

    return nullptr;
}

AreaTriggerDataStore* AreaTriggerDataStore::Instance()
{
    static AreaTriggerDataStore instance;
    return &instance;
}
