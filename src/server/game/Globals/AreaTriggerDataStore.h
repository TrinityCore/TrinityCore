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
class AreaTriggerMiscTemplate;
struct AreaTriggerServerPosition;

class TC_GAME_API AreaTriggerDataStore
{
public:
    void LoadAreaTriggerTemplates();

    std::set<ObjectGuid::LowType> const* GetAreaTriggersForMapAndCell(uint32 mapId, uint32 cellId) const;
    AreaTriggerServerPosition const* GetAreaTriggerServerPosition(uint32 spawnId) const;
    AreaTriggerTemplate const* GetAreaTriggerServerTemplate(uint32 id) const;
    AreaTriggerTemplate const* GetAreaTriggerTemplate(uint32 areaTriggerId) const;
    AreaTriggerMiscTemplate const* GetAreaTriggerMiscTemplate(uint32 spellMiscValue) const;

    static AreaTriggerDataStore* Instance();
};

#define sAreaTriggerDataStore AreaTriggerDataStore::Instance()

#endif // AreaTriggerDataStore_h__
