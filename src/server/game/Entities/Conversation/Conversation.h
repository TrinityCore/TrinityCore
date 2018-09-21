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

#ifndef TRINITYCORE_CONVERSATION_H
#define TRINITYCORE_CONVERSATION_H

#include "Object.h"
#include "ConversationDataStore.h"
#include <cstring>

class Unit;
class SpellInfo;

#pragma pack(push, 1)
struct ConversationDynamicFieldActor
{
    ConversationDynamicFieldActor() : Type(0), Padding(0)
    {
        memset(Raw.Data, 0, sizeof(Raw.Data));
    }

    bool IsEmpty() const
    {
        return ActorGuid.IsEmpty(); // this one is good enough
    }

    enum ActorType
    {
        WorldObjectActor = 0,
        CreatureActor = 1
    };

    union
    {
        ObjectGuid ActorGuid;

        ConversationActorTemplate ActorTemplate;

        struct
        {
            uint32 Data[4];
        } Raw;
    };

    uint32 Type;
    uint32 Padding;
};
#pragma pack(pop)

class TC_GAME_API Conversation : public WorldObject, public GridObject<Conversation>
{
    public:
        Conversation();
        ~Conversation();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool IsNeverVisibleFor(WorldObject const* seer) const override;

        void Update(uint32 diff) override;
        void Remove();
        int32 GetDuration() const { return _duration; }

        static Conversation* CreateConversation(uint32 conversationEntry, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo = nullptr);
        bool Create(ObjectGuid::LowType lowGuid, uint32 conversationEntry, Map* map, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo = nullptr);
        void AddActor(ObjectGuid const& actorGuid, uint16 actorIdx);
        void AddParticipant(ObjectGuid const& participantGuid);

        ObjectGuid const& GetCreatorGuid() const { return _creatorGuid; }

        float GetStationaryX() const override { return _stationaryPosition.GetPositionX(); }
        float GetStationaryY() const override { return _stationaryPosition.GetPositionY(); }
        float GetStationaryZ() const override { return _stationaryPosition.GetPositionZ(); }
        float GetStationaryO() const override { return _stationaryPosition.GetOrientation(); }
        void RelocateStationaryPosition(Position const& pos) { _stationaryPosition.Relocate(pos); }

        uint32 GetScriptId() const;

    private:
        Position _stationaryPosition;
        ObjectGuid _creatorGuid;
        uint32 _duration;
        GuidUnorderedSet _participants;
};

#endif // TRINITYCORE_CONVERSATION_H
