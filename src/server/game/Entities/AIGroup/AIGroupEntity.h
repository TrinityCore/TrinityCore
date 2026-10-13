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

#ifndef TRINITYCORE_AI_GROUP_ENTITY_H
#define TRINITYCORE_AI_GROUP_ENTITY_H

#include "AIGroupScript.h"
#include "Object.h"
#include <vector>

class Creature;
class Map;

class TC_GAME_API AIGroup
{
    public:
        AIGroup();
        ~AIGroup() = default;

        bool Create(Creature* mainMember);
        void Update(uint32 diff);
        void SetMap(Map* map) { _map = map; }
        Map* GetMap() const { return _map; }

        ObjectGuid GetOwnerGUID() const { return ObjectGuid::Empty; }
        ObjectGuid::LowType GetMainMemberGuid() const { return _mainMemberGuid; }
        uint32 GetTriggersId() const { return _triggersId; }
        uint32 GetCurrentActionSet() const { return _currentActionSet; }
        AIGroupScript* GetScript() { return &_script; }
        void SetTriggersId(uint32 triggersId);
        std::vector<WorldObject*> GetMembers(AIGroupUnit unit, AIGroupMgr::ObjectTypeMask typeMask) const;

        void SetCurrentActionSet(uint32 actionSetId);

    private:
        ObjectGuid::LowType _mainMemberGuid = 0;
        uint32 _triggersId = 0;
        uint32 _currentActionSet = 0;
        Map* _map = nullptr;
        AIGroupScript _script;
};

#endif