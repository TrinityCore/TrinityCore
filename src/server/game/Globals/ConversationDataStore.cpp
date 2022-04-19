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

#include "ConversationDataStore.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Timer.h"

namespace
{
    std::unordered_map<uint32, ConversationTemplate>       _conversationTemplateStore;
    std::unordered_map<uint32, ConversationLineTemplate>   _conversationLineTemplateStore;
}

void ConversationDataStore::LoadConversationTemplates()
{
    _conversationLineTemplateStore.clear();
    _conversationTemplateStore.clear();

    std::unordered_map<uint32, std::vector<ConversationActorTemplate>> actorsByConversation;

    if (QueryResult lineTemplates = WorldDatabase.Query("SELECT Id, UiCameraID, ActorIdx, Flags FROM conversation_line_template"))
    {
        uint32 oldMSTime = getMSTime();

        do
        {
            Field* fields = lineTemplates->Fetch();

            uint32 id = fields[0].GetUInt32();

            if (!sConversationLineStore.LookupEntry(id))
            {
                TC_LOG_ERROR("sql.sql", "Table `conversation_line_template` has template for non existing ConversationLine (ID: %u), skipped", id);
                continue;
            }

            ConversationLineTemplate& conversationLine = _conversationLineTemplateStore[id];
            conversationLine.Id         = id;
            conversationLine.UiCameraID = fields[1].GetUInt32();
            conversationLine.ActorIdx   = fields[2].GetUInt8();
            conversationLine.Flags      = fields[3].GetUInt8();
        }
        while (lineTemplates->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " Conversation line templates in %u ms", _conversationLineTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Conversation line templates. DB table `conversation_line_template` is empty.");
    }

    if (QueryResult actors = WorldDatabase.Query("SELECT ConversationId, ConversationActorId, ConversationActorGuid, Idx, CreatureId, CreatureDisplayInfoId, NoActorObject, ActivePlayerObject FROM conversation_actors"))
    {
        uint32 oldMSTime = getMSTime();
        uint32 count = 0;

        struct ConversationActorDbRow
        {
            uint32 ConversationId = 0;
            uint32 ActorIndex = 0;

            ObjectGuid::LowType SpawnId = 0;
            uint32 CreatureId = 0;
            uint32 CreatureDisplayInfoId = 0;

            bool operator()(ConversationActorWorldObjectTemplate& worldObject) const
            {
                if (!sObjectMgr->GetCreatureData(SpawnId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` references an invalid creature guid (GUID: " UI64FMTD ") for Conversation %u and Idx %u, skipped.", SpawnId, ConversationId, ActorIndex);
                    return false;
                }

                if (CreatureId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with ConversationActorGuid cannot have CreatureId (%u). Conversation %u and Idx %u.", CreatureId, ConversationId, ActorIndex);

                if (CreatureDisplayInfoId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with ConversationActorGuid cannot have CreatureDisplayInfoId (%u). Conversation %u and Idx %u.", CreatureDisplayInfoId, ConversationId, ActorIndex);

                worldObject.SpawnId = SpawnId;
                return true;
            }

            bool operator()(ConversationActorNoObjectTemplate& noObject) const
            {
                if (!sObjectMgr->GetCreatureTemplate(CreatureId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` references an invalid creature id (%u) for Conversation %u and Idx %u, skipped.", CreatureId, ConversationId, ActorIndex);
                    return false;
                }

                if (CreatureDisplayInfoId && !sCreatureDisplayInfoStore.LookupEntry(CreatureDisplayInfoId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` references an invalid creature display id (%u) for Conversation %u and Idx %u, skipped.", CreatureDisplayInfoId, ConversationId, ActorIndex);
                    return false;
                }

                if (SpawnId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with NoActorObject cannot have ConversationActorGuid (" UI64FMTD "). Conversation %u and Idx %u.", SpawnId, ConversationId, ActorIndex);

                noObject.CreatureId = CreatureId;
                noObject.CreatureDisplayInfoId = CreatureDisplayInfoId;
                return true;
            }

            bool operator()([[maybe_unused]] ConversationActorActivePlayerTemplate& activePlayer) const
            {
                if (SpawnId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with ActivePlayerObject cannot have ConversationActorGuid (" UI64FMTD "). Conversation %u and Idx %u.", SpawnId, ConversationId, ActorIndex);

                if (CreatureId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with ActivePlayerObject cannot have CreatureId (%u). Conversation %u and Idx %u.", CreatureId, ConversationId, ActorIndex);

                if (CreatureDisplayInfoId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with ActivePlayerObject cannot have CreatureDisplayInfoId (%u). Conversation %u and Idx %u.", CreatureDisplayInfoId, ConversationId, ActorIndex);

                return true;
            }

            bool operator()(ConversationActorTalkingHeadTemplate& talkingHead) const
            {
                if (!sObjectMgr->GetCreatureTemplate(CreatureId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` references an invalid creature id (%u) for Conversation %u and Idx %u, skipped.", CreatureId, ConversationId, ActorIndex);
                    return false;
                }

                if (CreatureDisplayInfoId && !sCreatureDisplayInfoStore.LookupEntry(CreatureDisplayInfoId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` references an invalid creature display id (%u) for Conversation %u and Idx %u, skipped.", CreatureDisplayInfoId, ConversationId, ActorIndex);
                    return false;
                }

                if (SpawnId)
                    TC_LOG_ERROR("sql.sql", "Table `conversation_actors` with TalkingHead cannot have ConversationActorGuid (" UI64FMTD "). Conversation %u and Idx %u.", SpawnId, ConversationId, ActorIndex);

                talkingHead.CreatureId = CreatureId;
                talkingHead.CreatureDisplayInfoId = CreatureDisplayInfoId;
                return true;
            }
        };

        do
        {
            Field* fields = actors->Fetch();

            ConversationActorDbRow data;
            ConversationActorTemplate actor;
            data.ConversationId           = fields[0].GetUInt32();
            actor.Id                      = fields[1].GetUInt32();
            data.SpawnId                  = fields[2].GetUInt64();
            data.ActorIndex = actor.Index = fields[3].GetUInt16();
            data.CreatureId               = fields[4].GetUInt32();
            data.CreatureDisplayInfoId    = fields[5].GetUInt32();
            bool noActorObject            = fields[6].GetUInt8() == 1;
            bool activePlayerObject       = fields[7].GetUInt8() == 1;

            if (activePlayerObject)
                actor.Data.emplace<ConversationActorActivePlayerTemplate>();
            else if (noActorObject)
                actor.Data.emplace<ConversationActorNoObjectTemplate>();
            else if (data.SpawnId)
                actor.Data.emplace<ConversationActorWorldObjectTemplate>();
            else
                actor.Data.emplace<ConversationActorTalkingHeadTemplate>();

            bool valid = std::visit(data, actor.Data);
            if (!valid)
                continue;

            actorsByConversation[data.ConversationId].push_back(actor);
            ++count;
        } while (actors->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u Conversation actors in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Conversation actors. DB table `conversation_actors` is empty.");
    }

    if (QueryResult templates = WorldDatabase.Query("SELECT Id, FirstLineId, TextureKitId, ScriptName FROM conversation_template"))
    {
        uint32 oldMSTime = getMSTime();

        do
        {
            Field* fields = templates->Fetch();

            ConversationTemplate conversationTemplate;
            conversationTemplate.Id                 = fields[0].GetUInt32();
            conversationTemplate.FirstLineId        = fields[1].GetUInt32();
            conversationTemplate.TextureKitId       = fields[2].GetUInt32();
            conversationTemplate.ScriptId           = sObjectMgr->GetScriptId(fields[3].GetString());

            conversationTemplate.Actors = std::move(actorsByConversation[conversationTemplate.Id]);

            ConversationLineEntry const* currentConversationLine = sConversationLineStore.LookupEntry(conversationTemplate.FirstLineId);
            if (!currentConversationLine)
                TC_LOG_ERROR("sql.sql", "Table `conversation_template` references an invalid line (ID: %u) for Conversation %u, skipped", conversationTemplate.FirstLineId, conversationTemplate.Id);

            while (currentConversationLine != nullptr)
            {
                if (ConversationLineTemplate const* conversationLineTemplate = Trinity::Containers::MapGetValuePtr(_conversationLineTemplateStore, currentConversationLine->ID))
                    conversationTemplate.Lines.push_back(conversationLineTemplate);
                else
                    TC_LOG_ERROR("sql.sql", "Table `conversation_line_template` has missing template for line (ID: %u) in Conversation %u, skipped", currentConversationLine->ID, conversationTemplate.Id);

                if (!currentConversationLine->NextConversationLineID)
                    break;

                currentConversationLine = sConversationLineStore.AssertEntry(currentConversationLine->NextConversationLineID);
            }

            _conversationTemplateStore[conversationTemplate.Id] = std::move(conversationTemplate);
        }
        while (templates->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " Conversation templates in %u ms", _conversationTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Conversation templates. DB table `conversation_template` is empty.");
    }
}

ConversationTemplate const* ConversationDataStore::GetConversationTemplate(uint32 conversationId) const
{
    return Trinity::Containers::MapGetValuePtr(_conversationTemplateStore, conversationId);
}

ConversationLineTemplate const* ConversationDataStore::GetConversationLineTemplate(uint32 conversationLineId) const
{
    return Trinity::Containers::MapGetValuePtr(_conversationLineTemplateStore, conversationLineId);
}

ConversationDataStore* ConversationDataStore::Instance()
{
    static ConversationDataStore instance;
    return &instance;
}
