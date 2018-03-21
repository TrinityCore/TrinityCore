/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScenarioMgr.h"
#include "ScenarioPackets.h"
#include "WorldSession.h"

void WorldSession::HandleQueryScenarioPOI(WorldPackets::Scenario::QueryScenarioPOI& queryScenarioPOI)
{
    WorldPackets::Scenario::ScenarioPOIs response;

    // Read criteria tree ids and add the in a unordered_set so we don't send POIs for the same criteria tree multiple times
    std::unordered_set<int32> criteriaTreeIds;
    for (size_t i = 0; i < queryScenarioPOI.MissingScenarioPOIs.size(); ++i)
        criteriaTreeIds.insert(queryScenarioPOI.MissingScenarioPOIs[i]); // CriteriaTreeID

    for (int32 criteriaTreeId : criteriaTreeIds)
    {
        if (ScenarioPOIVector const* poiVector = sScenarioMgr->GetScenarioPOIs(criteriaTreeId))
        {
            WorldPackets::Scenario::ScenarioPOIData scenarioPOIData;
            scenarioPOIData.CriteriaTreeID = criteriaTreeId;
            scenarioPOIData.ScenarioPOIs = poiVector;
            response.ScenarioPOIDataStats.push_back(scenarioPOIData);
        }
    }

    SendPacket(response.Write());
}
