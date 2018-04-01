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

#ifndef TRINITYCORE_SCENEOBJECT_H
#define TRINITYCORE_SCENEOBJECT_H

#include "Object.h"
#include <cstring>

class Unit;
class SpellInfo;

class TC_GAME_API SceneObject : public WorldObject, public GridObject<SceneObject>
{
    public:
        SceneObject();
        ~SceneObject();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool IsNeverVisibleFor(WorldObject const* seer) const override;

        void Update(uint32 diff) override;
        void Remove();
        int32 GetDuration() const { return _duration; }

        static SceneObject* CreateScene(uint32 sceneId, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo = nullptr);
        bool Create(ObjectGuid::LowType lowGuid, uint32 sceneId, Map* map, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo = nullptr);
        void AddParticipant(ObjectGuid const& participantGuid);

        ObjectGuid const& GetCreatorGuid() const { return _creatorGuid; }

        uint32 GetScriptId() const;

    private:
        ObjectGuid _creatorGuid;
        uint32 _duration;
        GuidUnorderedSet _participants;
};

#endif // TRINITYCORE_SCENEOBJECT_H
