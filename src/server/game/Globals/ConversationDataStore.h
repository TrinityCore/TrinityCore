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

#ifndef ConversationDataStore_h__
#define ConversationDataStore_h__

#include "Define.h"
#include "ObjectGuid.h"

#include <vector>

enum ConversationLineFlags
{
    CONVERSATION_LINE_FLAG_NOTIFY_STARTED = 0x1 // Client will send CMSG_CONVERSATION_LINE_STARTED when it runs this line
};

struct ConversationActorTemplate
{
    uint32 Id;
    uint32 CreatureId;
    uint32 CreatureModelId;
};

#pragma pack(push, 1)
struct ConversationLineTemplate
{
    uint32 Id;          // Link to ConversationLine.db2
    uint32 StartTime;   // Time in ms after conversation creation the line is displayed
    uint32 UiCameraID;  // Link to UiCamera.db2
    uint8 ActorIdx;     // Index from conversation_actors
    uint8 Flags;
    uint16 Padding;
};
#pragma pack(pop)

struct ConversationTemplate
{
    uint32 Id;
    uint32 FirstLineId;     // Link to ConversationLine.db2
    uint32 LastLineEndTime; // Time in ms after conversation creation the last line fades out
    uint32 TextureKitId;    // Background texture

    std::vector<ConversationActorTemplate const*> Actors;
    std::vector<ObjectGuid::LowType> ActorGuids;
    std::vector<ConversationLineTemplate const*> Lines;

    uint32 ScriptId;
};

class TC_GAME_API ConversationDataStore
{
public:
    void LoadConversationTemplates();

    ConversationTemplate const* GetConversationTemplate(uint32 conversationId) const;

    static ConversationDataStore* Instance();
};

#define sConversationDataStore ConversationDataStore::Instance()

#endif // ConversationDataStore_h__
