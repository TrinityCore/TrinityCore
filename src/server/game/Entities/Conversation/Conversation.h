/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectAccessor.h"

class Unit;
class SpellInfo;

struct ConversationActorTemplate
{
    uint32 Id;
    uint32 CreatureId;
    uint32 Unk1;
    uint32 Unk2;
    uint32 Unk3;
    uint32 Unk4;
};

struct ConversationLineTemplate
{
    uint32 Id;      // Link to ConversationLine.db2
    uint32 Unk1;
    uint32 Unk2;
    uint32 Unk3;
};

struct ConversationTemplate
{
    uint32 Id;
    uint32 LastLineDuration;

    std::vector<ConversationActorTemplate> Actors;
    std::vector<ConversationLineTemplate> Lines;
};

class TC_GAME_API Conversation : public WorldObject, public GridObject<Conversation>
{
    public:
        Conversation();
        ~Conversation();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void Update(uint32 p_time) override;
        void Remove();
        int32 GetDuration() const { return _duration; }

        bool CreateConversation(ObjectGuid::LowType guidlow, uint32 triggerEntry, Unit* caster, Position const& pos);

        ObjectGuid GetCasterGuid() const { return _casterGuid; }

    private:
        ObjectGuid _casterGuid;
        uint32 _duration;
};
#endif
