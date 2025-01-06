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

#ifndef TRINITY_CONVERSATIONAI_H
#define TRINITY_CONVERSATIONAI_H

#include "Define.h"
#include "ObjectGuid.h"

class Conversation;
class Unit;
class Player;

class TC_GAME_API ConversationAI
{
        uint32 _scriptId;

    protected:
        Conversation* const conversation;
    public:
        explicit ConversationAI(Conversation* c, uint32 scriptId = {});
        virtual ~ConversationAI();

        // Called when the Conversation has just been initialized, just before added to map
        virtual void OnInitialize() {}

        // Called when Conversation is created but not added to Map yet.
        virtual void OnCreate([[maybe_unused]] Unit* creator) { }

        // Called when Conversation is started
        virtual void OnStart() { }

        // Called when player sends CMSG_CONVERSATION_LINE_STARTED with valid conversation guid
        virtual void OnLineStarted([[maybe_unused]] uint32 lineId, [[maybe_unused]] Player* sender) { }

        // Called for each update tick
        virtual void OnUpdate([[maybe_unused]] uint32 diff) { }

        // Called when the Conversation is removed
        virtual void OnRemove() { }

        // Pass parameters between AI
        virtual void DoAction([[maybe_unused]] int32 param) { }
        virtual uint32 GetData([[maybe_unused]] uint32 id) const { return 0; }
        virtual void SetData([[maybe_unused]] uint32 id, [[maybe_unused]] uint32 value) { }
        virtual void SetGUID([[maybe_unused]] ObjectGuid const& guid, [[maybe_unused]] int32 id) { }
        virtual ObjectGuid GetGUID([[maybe_unused]] int32 id) const { return ObjectGuid::Empty; }

        // Gets the id of the AI (script id)
        uint32 GetId() const { return _scriptId; }
};

class NullConversationAI final : public ConversationAI
{
    public:
        using ConversationAI::ConversationAI;
};

#endif
