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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum ToGhostlandsData
{
    NPC_SUMMONED_HIGH_ELF_RANGER        = 130919,

    QUEST_TO_GHOSTLANDS                 = 49787,

    CONVO_SANCTUM_OF_THE_MOON           = 6467,
    CONVO_SANCTUM_OF_THE_MOON_FOLLOWUP  = 6634,
    CONVO_ANDILIEN_ESTATE               = 6469,
    CONVO_ANDILIEN_ESTATE_FOLLOWUP      = 6479,
    CONVO_DAWNSPAIR_SPIRE               = 6470,
    CONVO_DAWNSPAIR_SPIRE_UP            = 6637,
    CONVO_DAWNSPAIR_SPIRE_FOLLOWUP      = 6471,

    CONVO_ACTOR_HIGH_ELF_RANGER         = 61831
};

// 6468 - Conversation
class conversation_high_elf_ranger_to_ghostlands : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* highElfRanger = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_HIGH_ELF_RANGER, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!highElfRanger)
            return;

        conversation->AddActor(CONVO_ACTOR_HIGH_ELF_RANGER, 0, highElfRanger->GetGUID());
        conversation->Start();
    }
};

// 6478 - Conversation
// 6635 - Conversation
template<uint32 ConversationId>
class conversation_ghostlands_start_convo_on_end : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnStart() override
    {
        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            Conversation::CreateConversation(ConversationId, player, *player, player->GetGUID(), nullptr, true);
        }, conversation->GetLastLineEndTime(conversation->GetPrivateObjectOwnerLocale()));
    }
};

// 6636 - Conversation
class conversation_dawnspair_spire_to_ghostlands : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    static constexpr Position AlleriaMoveToBookPosition = { 7835.05f, -7913.11f, 308.2204f };

    enum DawnspairSpireConvoData
    {
        POINT_ALLERIA_MOVE_TO_BOOK = 1
    };

    void OnCreate(Unit* creator) override
    {
        Creature* highElfRanger = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_HIGH_ELF_RANGER, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!highElfRanger)
            return;

        TempSummon* alleriaClone = highElfRanger->SummonPersonalClone(highElfRanger->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer()); // despawn on map change, quest remove, logout
        if (!alleriaClone)
            return;

        alleriaClone->GetMotionMaster()->MovePoint(POINT_ALLERIA_MOVE_TO_BOOK, AlleriaMoveToBookPosition, true, {}, {}, MovementWalkRunSpeedSelectionMode::ForceWalk);
    }

    void OnStart() override
    {
        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            Conversation::CreateConversation(CONVO_DAWNSPAIR_SPIRE_FOLLOWUP, player, *player, player->GetGUID(), nullptr, true);
        }, conversation->GetLastLineEndTime(conversation->GetPrivateObjectOwnerLocale()));
    }
};

// 6471 - Conversation
class conversation_dawnspair_spire_followup_to_ghostlands : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    static constexpr Position AlleriaOpenRiftPosition = { 7832.54f, -7913.34f, 308.2204f };

    enum DawnspairSpireFollowupConvoData
    {
        POINT_ALLERIA_OPEN_PORTAL = 2
    };

    void OnCreate(Unit* creator) override
    {
        Creature* alleriaClone = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_HIGH_ELF_RANGER, .IgnorePhases = true, .PrivateObjectOwnerGuid = creator->GetGUID() });
        if (!alleriaClone)
            return;

        conversation->AddActor(CONVO_ACTOR_HIGH_ELF_RANGER, 0, alleriaClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Creature* alleriaClone = conversation->GetActorCreature(0);
            if (!alleriaClone)
                return;

            alleriaClone->GetMotionMaster()->MovePoint(POINT_ALLERIA_OPEN_PORTAL, AlleriaOpenRiftPosition, true, {}, {}, MovementWalkRunSpeedSelectionMode::ForceWalk);

        }, conversation->GetLastLineEndTime(conversation->GetPrivateObjectOwnerLocale()));
    }
};

// 100 - Ghostlands - Sanctum of the Moon
// 101 - Ghostlands - Andilien Estate
// 102 - Ghostlands - Dawnspair Spire
// 103 - Ghostlands - Dawnspair Spire second floor
template<uint32 QuestId, uint32 ConversationId>
struct at_ghostlands_conversation_to_ghostlands : AreaTriggerAI
{
    at_ghostlands_conversation_to_ghostlands(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QuestId) != QUEST_STATUS_INCOMPLETE)
            return;

        Conversation::CreateConversation(ConversationId, player, *player, player->GetGUID(), nullptr, true);
    }
};

void AddSC_ghostlands()
{
    // Conversation
    RegisterConversationAI(conversation_high_elf_ranger_to_ghostlands);
    RegisterConversationAI(conversation_dawnspair_spire_to_ghostlands);
    RegisterConversationAI(conversation_dawnspair_spire_followup_to_ghostlands);

    // Conversation Template
    new GenericConversationScript<conversation_ghostlands_start_convo_on_end<CONVO_SANCTUM_OF_THE_MOON_FOLLOWUP>>("conversation_sanctum_of_the_moon_to_ghostlands");
    new GenericConversationScript<conversation_ghostlands_start_convo_on_end<CONVO_ANDILIEN_ESTATE_FOLLOWUP>>("conversation_andilien_estate_to_ghostlands");

    // Areatrigger Template
    new GenericAreaTriggerEntityScript<at_ghostlands_conversation_to_ghostlands<QUEST_TO_GHOSTLANDS, CONVO_SANCTUM_OF_THE_MOON>>("at_ghostlands_sanctum_of_the_moon_conversation");
    new GenericAreaTriggerEntityScript<at_ghostlands_conversation_to_ghostlands<QUEST_TO_GHOSTLANDS, CONVO_ANDILIEN_ESTATE>>("at_ghostlands_andilien_estate_conversation");
    new GenericAreaTriggerEntityScript<at_ghostlands_conversation_to_ghostlands<QUEST_TO_GHOSTLANDS, CONVO_DAWNSPAIR_SPIRE>>("at_ghostlands_dawnspair_spire_conversation");
    new GenericAreaTriggerEntityScript<at_ghostlands_conversation_to_ghostlands<QUEST_TO_GHOSTLANDS, CONVO_DAWNSPAIR_SPIRE_UP>>("at_ghostlands_dawnspair_spire_second_floor_conversation");
}
