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

#include "NamedPointMgr.h"
#include "Database/DatabaseEnv.h"
#include "Object.h"
#include "Log.h"

NamedPointMgr* NamedPointMgr::Instance()
{
    static NamedPointMgr instance;
    return &instance;
}

void NamedPointMgr::LoadNamedPoints()
{
    uint32 oldMSTime = getMSTime();

    _namedPoints.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_NAMED_POINT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 named points. DB table `named_point` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        NamedPoint point;

        point.Id          = fields[0].GetUInt32();
        point.PositionX   = fields[1].GetFloat();
        point.PositionY   = fields[2].GetFloat();
        point.PositionZ   = fields[3].GetFloat();
        point.Orientation = fields[4].GetFloat();
        point.StringId    = fields[5].GetString();
        point.Name        = fields[6].GetString();

        _namedPoints[point.Id] = point;

        ++count;
    } 
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} named points in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

const NamedPoint* NamedPointMgr::GetNamedPoint(uint32 id) const
{
    auto it = _namedPoints.find(id);
    if (it != _namedPoints.end())
        return &it->second;

    return nullptr;
}

const NamedPoint* NamedPointMgr::FindNearestNamedPoint(float x, float y, float z, const std::string& stringId, float maxRange) const
{
    const NamedPoint* nearestPoint = nullptr;
    float minDist = maxRange;

    for (auto const& pair : _namedPoints)
    {
        const NamedPoint& point = pair.second;
        if (point.StringId != stringId)
            continue;

        float dist = std::sqrt((point.PositionX - x) * (point.PositionX - x) + 
                               (point.PositionY - y) * (point.PositionY - y) + 
                               (point.PositionZ - z) * (point.PositionZ - z));

        if (dist < minDist)
        {
            minDist = dist;
            nearestPoint = &point;
        }
    }

    return nearestPoint;
}

const NamedPoint* NamedPointMgr::FindNearestNamedPoint(WorldObject const* searcher, const std::string& stringId, float maxRange) const
{
    if (!searcher)
        return nullptr;

    return FindNearestNamedPoint(searcher->GetPositionX(), searcher->GetPositionY(), searcher->GetPositionZ(), stringId, maxRange);
}
