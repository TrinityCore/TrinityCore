/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Area.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "PoolMgr.h"
#include "ZoneScript.h"

AreaMgr* AreaMgr::instance()
{
    static AreaMgr instance;
    return &instance;
}

Area* AreaMgr::GetArea(uint32 areaId)
{
    if (!areaId)
        return nullptr;

    auto itr = m_areas.find(areaId);
    if (itr != m_areas.end())
        return itr->second;

    if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId))
    {
        Area* area = new Area(areaEntry);
        m_areas[areaEntry->ID] = area;
        return area;
    }

    return nullptr;
}

void AreaMgr::FillGatheringNodePools()
{
    for (auto areaItr : m_areas)
        areaItr.second->FillGatheringNodePool();
}

Area::Area(AreaTableEntry const* areaTableEntry) : m_areaTableEntry(areaTableEntry)
{
    m_zoneScript = sScriptMgr->GetZoneScript(sObjectMgr->GetScriptIdForZone(GetId()));

    // Calculate parent & zone at creation
    m_parent = sAreaMgr->GetArea(GetEntry()->ParentAreaID);

    m_zone = m_parent ? m_parent: this;
    while (m_zone && !m_zone->IsZone())
        m_zone = sAreaMgr->GetArea(m_zone->GetEntry()->ParentAreaID);
}

std::vector<Area*> Area::GetTree()
{
    Area* area = this;
    std::vector<Area*> areas;
    while (area)
    {
        areas.push_back(area);
        area = sAreaMgr->GetArea(area->GetEntry()->ParentAreaID);
    }

    return areas;
}

ZoneScript* Area::GetZoneScript()
{
    if (m_zoneScript)
        return m_zoneScript;

    if (Area* parent = GetParent())
        return parent->GetZoneScript();

    return nullptr;
}

void Area::AddGatheringNode(ObjectGuid::LowType guid, GameObjectTemplate const* gInfo, Position gobPosition)
{
    LockEntry const* lockInfo = sLockStore.LookupEntry(gInfo->GetLockId());
    if (!lockInfo)
        return;

    uint8 type = lockInfo->HasHerbalism() ? 1 : 2;
    gobPosition.m_positionX -= fmod(gobPosition.m_positionX, 5);
    gobPosition.m_positionY -= fmod(gobPosition.m_positionY, 5);
    gobPosition.m_positionZ -= fmod(gobPosition.m_positionZ, 5);
    size_t positionHash = std::hash<std::string>()(gobPosition.ToString());

    m_gatheringNodes[type][positionHash].push_back(guid);
}

void Area::FillGatheringNodePool()
{
    for (auto typeItr : m_gatheringNodes)
    {
        // Mother Pool Id format : type (TAAAAA Where T = Type and AAAAA = AreaId)
        uint32 motherPoolId = typeItr.first * 100000 + GetId();

        // We spawn 50% of zone available spots
        sPoolMgr->AddPoolTemplate(motherPoolId, typeItr.second.size() / 2);

        // Mother Pool Id format : type (TAAAAAPPPP where PPPP = sub pool id)
        uint32 const subPoolBaseId = motherPoolId * 10000;
        uint32 subPoolCounter = 0;

        for (auto ceiledPositionItr : typeItr.second)
        {
            uint32 const subPoolId = subPoolBaseId + subPoolCounter++;

            sPoolMgr->AddPoolTemplate(subPoolId, 1);
            sPoolMgr->AddPoolToPool(motherPoolId, subPoolId, 0);

            for (ObjectGuid::LowType guid : ceiledPositionItr.second)
                sPoolMgr->AddGameObjectToPool(subPoolId, guid, 0);
        }

        sPoolMgr->SpawnPool(motherPoolId);
    }

    // Free now unused memory
    m_gatheringNodes.clear();
}
