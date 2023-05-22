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

#include "ScriptSystem.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SplineChain.h"

SystemMgr::SystemMgr() = default;
SystemMgr::~SystemMgr() = default;

SystemMgr* SystemMgr::instance()
{
    static SystemMgr instance;
    return &instance;
}

void SystemMgr::LoadScriptSplineChains()
{
    uint32 oldMSTime = getMSTime();

    m_mSplineChainsMap.clear();

    //                                                   0      1        2         3                 4            5
    QueryResult resultMeta = WorldDatabase.Query("SELECT entry, chainId, splineId, expectedDuration, msUntilNext, velocity FROM script_spline_chain_meta ORDER BY entry asc, chainId asc, splineId asc");
    //                                                 0      1        2         3     4  5  6
    QueryResult resultWP = WorldDatabase.Query("SELECT entry, chainId, splineId, wpId, x, y, z FROM script_spline_chain_waypoints ORDER BY entry asc, chainId asc, splineId asc, wpId asc");
    if (!resultMeta || !resultWP)
    {
        TC_LOG_INFO("server.loading", ">> Loaded spline chain data for 0 chains, consisting of 0 splines with 0 waypoints. DB tables `script_spline_chain_meta` and `script_spline_chain_waypoints` are empty.");
    }
    else
    {
        uint32 chainCount = 0, splineCount = 0, wpCount = 0;
        do
        {
            Field* fieldsMeta = resultMeta->Fetch();
            uint32 entry = fieldsMeta[0].GetUInt32();
            uint16 chainId = fieldsMeta[1].GetUInt16();
            uint8 splineId = fieldsMeta[2].GetUInt8();
            std::vector<SplineChainLink>& chain = m_mSplineChainsMap[{entry, chainId}];

            if (splineId != chain.size())
            {
                TC_LOG_WARN("server.loading", "Creature #{}: Chain {} has orphaned spline {}, skipped.", entry, chainId, splineId);
                continue;
            }

            uint32 expectedDuration = fieldsMeta[3].GetUInt32();
            uint32 msUntilNext = fieldsMeta[4].GetUInt32();
            float velocity = fieldsMeta[5].GetFloat();
            chain.emplace_back(expectedDuration, msUntilNext, velocity);

            if (splineId == 0)
                ++chainCount;
            ++splineCount;
        } while (resultMeta->NextRow());

        do
        {
            Field* fieldsWP = resultWP->Fetch();
            uint32 entry = fieldsWP[0].GetUInt32();
            uint16 chainId = fieldsWP[1].GetUInt16();
            uint8 splineId = fieldsWP[2].GetUInt8(), wpId = fieldsWP[3].GetUInt8();
            float posX = fieldsWP[4].GetFloat(), posY = fieldsWP[5].GetFloat(), posZ = fieldsWP[6].GetFloat();
            auto it = m_mSplineChainsMap.find({entry,chainId});
            if (it == m_mSplineChainsMap.end())
            {
                TC_LOG_WARN("server.loading", "Creature #{} has waypoint data for spline chain {}. No such chain exists - entry skipped.", entry, chainId);
                continue;
            }
            std::vector<SplineChainLink>& chain = it->second;
            if (splineId >= chain.size())
            {
                TC_LOG_WARN("server.loading", "Creature #{} has waypoint data for spline ({},{}). The specified chain does not have a spline with this index - entry skipped.", entry, chainId, splineId);
                continue;
            }
            SplineChainLink& spline = chain[splineId];
            if (wpId != spline.Points.size())
            {
                TC_LOG_WARN("server.loading", "Creature #{} has orphaned waypoint data in spline ({},{}) at index {}. Skipped.", entry, chainId, splineId, wpId);
                continue;
            }
            spline.Points.emplace_back(posX, posY, posZ);
            ++wpCount;
        } while (resultWP->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded spline chain data for {} chains, consisting of {} splines with {} waypoints in {} ms", chainCount, splineCount, wpCount, GetMSTimeDiffToNow(oldMSTime));
    }
}

std::vector<SplineChainLink> const* SystemMgr::GetSplineChain(uint32 entry, uint16 chainId) const
{
    auto it = m_mSplineChainsMap.find({ entry, chainId });
    if (it != m_mSplineChainsMap.end())
        return &it->second;
    return nullptr;
}

std::vector<SplineChainLink> const* SystemMgr::GetSplineChain(Creature const* who, uint16 id) const
{
    return GetSplineChain(who->GetEntry(), id);
}
