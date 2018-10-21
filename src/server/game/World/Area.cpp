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

Area::Area(AreaTableEntry const* areaTableEntry) : m_areaTableEntry(areaTableEntry)
{
    // Calculate parent & zone at creation
    m_parent = sAreaMgr->GetArea(GetEntry()->ParentAreaID);

    m_zone = m_parent ? m_parent : this;
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
