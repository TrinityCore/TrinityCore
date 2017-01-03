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

#include "AreaTriggerDataStore.h"
#include "AreaTriggerTemplate.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "MoveSplineInitArgs.h"
#include "ObjectMgr.h"
#include "Timer.h"

namespace
{
    std::unordered_map<uint32, AreaTriggerTemplate> _areaTriggerTemplateStore;
    std::unordered_map<uint32, AreaTriggerMiscTemplate> _areaTriggerTemplateSpellMisc;
}

void AreaTriggerDataStore::LoadAreaTriggerTemplates()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<uint32, std::vector<AreaTriggerPolygonVertice>> verticeByAreatrigger;
    std::unordered_map<uint32, Movement::PointsArray> splineByMoveCurve;
    std::unordered_map<uint32, std::vector<AreaTriggerAuras>> aurasByAreatrigger;

    if (QueryResult templateAuras = WorldDatabase.Query("SELECT AreaTriggerId, AuraId, TargetType, CastType FROM `areatrigger_template_auras`"))
    {
        do
        {
            Field* templateAurasFields = templateAuras->Fetch();
            uint32 areatriggerId = templateAurasFields[0].GetUInt32();

            AreaTriggerAuras aura;
            aura.AuraId         = templateAurasFields[1].GetUInt32();
            uint32 targetType   = templateAurasFields[2].GetUInt32();
            uint32 castType     = templateAurasFields[3].GetUInt32();

            if (targetType >= AREATRIGGER_AURA_USER_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_auras` has invalid TargetType (%u) for AreaTriggerId %u and AuraId %u", targetType, areatriggerId, aura.AuraId);
                continue;
            }

            if (castType >= AREATRIGGER_AURA_CASTTYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template_auras` has invalid CastType (%u) for AreaTriggerId %u and AuraId %u", castType, areatriggerId, aura.AuraId);
                continue;
            }

            aura.TargetType = AreaTriggerAuraTypes(targetType);
            aura.CastType   = AreaTriggerAuraCastTypes(castType);

            aurasByAreatrigger[areatriggerId].push_back(aura);
        }
        while (templateAuras->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates auras. DB table `areatrigger_template_auras` is empty.");
    }

    if (QueryResult vertices = WorldDatabase.Query("SELECT AreaTriggerId, VerticeX, VerticeY, VerticeTargetX, VerticeTargetY FROM `areatrigger_template_polygon_vertices` ORDER BY `AreaTriggerId`, `Idx`"))
    {
        do
        {
            Field* verticeFields = vertices->Fetch();
            uint32 areatriggerId = verticeFields[0].GetUInt32();

            AreaTriggerPolygonVertice vertice;
            vertice.VerticeX        = verticeFields[1].GetFloat();
            vertice.VerticeY        = verticeFields[2].GetFloat();
            vertice.VerticeTargetX  = verticeFields[3].GetFloat();
            vertice.VerticeTargetY  = verticeFields[4].GetFloat();

            verticeByAreatrigger[areatriggerId].push_back(vertice);
        }
        while (vertices->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates polygon vertices. DB table `areatrigger_template_polygon_vertices` is empty.");
    }

    if (QueryResult splines = WorldDatabase.Query("SELECT MoveCurveId, SplineX, SplineY, SplineZ FROM `areatrigger_template_splines` ORDER BY `MoveCurveId`, `Idx`"))
    {
        do
        {
            Field* splineFields = splines->Fetch();
            uint32 moveCurveId = splineFields[0].GetUInt32();

            G3D::Vector3 spline;
            spline.x = splineFields[1].GetFloat();
            spline.y = splineFields[2].GetFloat();
            spline.z = splineFields[3].GetFloat();

            splineByMoveCurve[moveCurveId].push_back(spline);
        } while (splines->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 AreaTrigger templates splines. DB table `areatrigger_template_splines` is empty.");
    }

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
                TC_LOG_ERROR("sql.sql", "Table `areatrigger_template` have areatrigger (Id: %u) with invalid type %u.", areaTriggerTemplate.Id, type);
                continue;
            }

            areaTriggerTemplate.Type = static_cast<AreaTriggerTypes>(type);
            areaTriggerTemplate.Flags = fields[2].GetUInt32();

            for (uint8 i = 0; i < MAX_AREATRIGGER_ENTITY_DATA; ++i)
                areaTriggerTemplate.DefaultDatas.Data[i] = fields[3 + i].GetFloat();

            areaTriggerTemplate.ScriptId = sObjectMgr->GetScriptId(fields[9].GetString());
            areaTriggerTemplate.PolygonVertices = std::move(verticeByAreatrigger[areaTriggerTemplate.Id]);
            areaTriggerTemplate.Auras = std::move(aurasByAreatrigger[areaTriggerTemplate.Id]);

            areaTriggerTemplate.InitMaxSearchRadius();
            _areaTriggerTemplateStore[areaTriggerTemplate.Id] = areaTriggerTemplate;

        } while (templates->NextRow());
    }

    if (QueryResult areatriggerSpellMiscs = WorldDatabase.Query("SELECT SpellMiscId, AreatriggerId, MoveCurveId, ScaleCurveId, MorphCurveId, FacingCurveId, TimeToTarget, TimeToTargetScale FROM `spell_areatrigger`"))
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

            miscTemplate.MoveCurveId        = areatriggerSpellMiscFields[2].GetUInt32();
            miscTemplate.ScaleCurveId       = areatriggerSpellMiscFields[3].GetUInt32();
            miscTemplate.MorphCurveId       = areatriggerSpellMiscFields[4].GetUInt32();
            miscTemplate.FacingCurveId      = areatriggerSpellMiscFields[5].GetUInt32();
            miscTemplate.TimeToTarget       = areatriggerSpellMiscFields[6].GetUInt32();
            miscTemplate.TimeToTargetScale  = areatriggerSpellMiscFields[7].GetUInt32();

            if (miscTemplate.MoveCurveId)
                miscTemplate.SplinePoints = splineByMoveCurve[miscTemplate.MoveCurveId];

            _areaTriggerTemplateSpellMisc[miscTemplate.MiscId] = miscTemplate;
        } while (areatriggerSpellMiscs->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Spell AreaTrigger templates. DB table `spell_areatrigger` is empty.");
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
