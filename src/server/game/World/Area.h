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

#ifndef _AREA_H
#define _AREA_H

#include "DB2Structure.h"
#include "Position.h"
#include "ZoneScript.h"

class Area;
class ZoneScript;

struct GameObjectTemplate;

class TC_GAME_API AreaMgr
{
public:
    static AreaMgr* instance();

    Area* GetArea(uint32 areaId);

    void FillGatheringNodePools();

private:
    std::map<uint32, Area*> m_areas;
};

#define sAreaMgr AreaMgr::instance()

class TC_GAME_API Area
{
public:
    Area(AreaTableEntry const* areaTableEntry);

    AreaTableEntry const* GetEntry() const { return m_areaTableEntry; }
    uint32 GetId() const { return GetEntry()->ID; }

    bool IsArea() const { return m_areaTableEntry->Flags[0] & AREA_FLAG_SUB_ZONE; }
    bool IsZone() const { return !IsArea(); }

    Area* GetParent() { return m_parent; }
    Area* GetZone() { return m_zone; }
    std::vector<Area*> GetTree();

    ZoneScript* GetZoneScript();

    void AddGatheringNode(ObjectGuid::LowType guid, GameObjectTemplate const* gInfo, Position gobPosition);
    void FillGatheringNodePool();

private:
    AreaTableEntry const* m_areaTableEntry;
    ZoneScript* m_zoneScript;

    std::unordered_map<uint8, std::unordered_map<size_t, std::vector<ObjectGuid::LowType>>> m_gatheringNodes;

    Area* m_parent;
    Area* m_zone;
};

#endif
