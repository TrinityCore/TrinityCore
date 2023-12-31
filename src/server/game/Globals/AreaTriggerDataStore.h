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

#ifndef AreaTriggerDataStore_h__
#define AreaTriggerDataStore_h__

#include "Define.h"
#include "ObjectGuid.h"
#include <set>

class AreaTriggerTemplate;
class AreaTriggerCreateProperties;
enum Difficulty : uint8;
struct AreaTriggerId;
struct AreaTriggerSpawn;

typedef AreaTriggerId AreaTriggerCreatePropertiesId;

class TC_GAME_API AreaTriggerDataStore
{
public:
    void LoadAreaTriggerTemplates();
    void LoadAreaTriggerSpawns();

    std::set<ObjectGuid::LowType> const* GetAreaTriggersForMapAndCell(uint32 mapId, Difficulty difficulty, uint32 cellId) const;
    AreaTriggerSpawn const* GetAreaTriggerSpawn(ObjectGuid::LowType spawnId) const;
    AreaTriggerTemplate const* GetAreaTriggerTemplate(AreaTriggerId const& areaTriggerId) const;
    AreaTriggerCreateProperties const* GetAreaTriggerCreateProperties(AreaTriggerCreatePropertiesId const& areaTriggerCreatePropertiesId) const;

    static AreaTriggerDataStore* Instance();
};

#define sAreaTriggerDataStore AreaTriggerDataStore::Instance()

#endif // AreaTriggerDataStore_h__
