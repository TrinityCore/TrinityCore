/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

class Unit;
class SpellInfo;

struct ConversationActorTemplate
{
    uint32 Id;
    uint32 CreatureId;
    uint32 CreatureModelId;
};

struct ConversationDynamicFieldActor
{
    ConversationDynamicFieldActor() : Type(0), Padding(0)
    {
        memset(Raw.Data, 0, sizeof(Raw.Data));
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

struct ConversationLineTemplate
{
    uint32 Id;          // Link to ConversationLine.db2
    uint32 StartTime;   // Time in ms after conversation creation the line is displayed
    uint32 UiCameraID;  // Link to UiCamera.db2
    uint32 ActorIdx;    // Index from conversation_actors
};

struct ConversationTemplate
{
    uint32 Id;
    uint32 FirstLineId;     // Link to ConversationLine.db2
    uint32 LastLineEndTime; // Time in ms after conversation creation the last line fades out

    std::vector<ConversationActorTemplate const*> Actors;
    std::vector<ConversationLineTemplate const*> Lines;
};

class TC_GAME_API Conversation : public WorldObject, public GridObject<Conversation>
{
    public:
        Conversation();
        ~Conversation();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void Update(uint32 diff) override;
        void Remove();
        int32 GetDuration() const { return _duration; }

        bool CreateConversation(uint32 conversationEntry, Unit* creator, Position const& pos, SpellInfo const* spellInfo = nullptr);
        void AddActor(ObjectGuid const& actorGuid, int16 actorIdx = -1);

        ObjectGuid const& GetCreatorGuid() const { return _creatorGuid; }

        float GetStationaryX() const override { return _stationaryPosition.GetPositionX(); }
        float GetStationaryY() const override { return _stationaryPosition.GetPositionY(); }
        float GetStationaryZ() const override { return _stationaryPosition.GetPositionZ(); }
        float GetStationaryO() const override { return _stationaryPosition.GetOrientation(); }
        void RelocateStationaryPosition(Position const& pos) { _stationaryPosition.Relocate(pos); }

    private:
        Position _stationaryPosition;
        ObjectGuid _creatorGuid;
        uint32 _duration;
};
#endif
