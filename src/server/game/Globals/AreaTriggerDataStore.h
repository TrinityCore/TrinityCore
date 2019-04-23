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

#ifndef AreaTriggerDataStore_h__
#define AreaTriggerDataStore_h__

#include "Define.h"

class AreaTriggerTemplate;
class AreaTriggerMiscTemplate;

struct AreaTriggerData
{
    uint32 id;
    float position_x;
    float position_y;
    float position_z;
    uint32 map_id;
    uint64 spawn_mask;
    uint32 scriptId;
    ObjectGuid::LowType guid;
};

class TC_GAME_API AreaTriggerDataStore
{
public:
    typedef std::list<AreaTriggerData> AreaTriggerDataList;
    typedef std::unordered_map<uint32, AreaTriggerDataList> AreaTriggerDataContainer;

    void LoadAreaTriggerTemplates();
    void LoadAreaTriggers();

    AreaTriggerTemplate const* GetAreaTriggerTemplate(uint32 areaTriggerId) const;
    AreaTriggerMiscTemplate const* GetAreaTriggerMiscTemplate(uint32 spellMiscValue) const;
    AreaTriggerDataList const* GetStaticAreaTriggersByMap(uint32 map_id) const;

    static AreaTriggerDataStore* Instance();

private:
    AreaTriggerDataContainer _areaTriggerData;
};

#define sAreaTriggerDataStore AreaTriggerDataStore::Instance()

#endif // AreaTriggerDataStore_h__
