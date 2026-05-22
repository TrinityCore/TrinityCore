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

#include "Conversation.h"
#include "ConversationAI.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

namespace Scripts::QuelThalas::Harandar::Chapter1
{
namespace Creatures
{
    static constexpr uint32 OrweynaFairbreezeVillage = 236704;
    static constexpr uint32 HalduronFairbreezeVillage = 240715;
    static constexpr uint32 OrweynaAmirdrassilRoots = 239522;
    static constexpr uint32 HalduronAmirdrassilRoots = 237858;
    static constexpr uint32 KupaalAmirdrassilRoots = 237209;
}
namespace Conversations
{
    namespace Actors
    {
        static constexpr uint32 OrweynaActorFairbreezeVillage = 105442;
        static constexpr uint32 OrweynaActorAmirdrassilRoots = 105508;
        static constexpr uint32 HalduronActorAmirdrassilRoots = 107891;
    }
    namespace Lines
    {
        static constexpr uint32 TheRootCauseStart = 78289;
    }
}
namespace Paths
{
    static constexpr uint32 OrweynaStartPathToPortal = 23670400;
    static constexpr uint32 HalduronStartPathToPortal = 24071500;
    static constexpr uint32 OrweynaPathToHarathir = 23952201;
    static constexpr uint32 HalduronPathToHarathir = 23785801;
    static constexpr uint32 KupaalPathToHarathir = 23720900;
}

// 28444 - Conversation
class conversation_the_root_cause_open_portal : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* orweynaObject = creator->FindNearestCreatureWithOptions(30.0f, { .CreatureId = Creatures::OrweynaFairbreezeVillage, .IgnorePhases = true });
        if (!orweynaObject)
            return;

        Creature* halduronObject = creator->FindNearestCreatureWithOptions(30.0f, { .CreatureId = Creatures::HalduronFairbreezeVillage, .IgnorePhases = true });
        if (!halduronObject)
            return;

        TempSummon* orweynaClone = orweynaObject->SummonPersonalClone(orweynaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!orweynaClone)
            return;

        TempSummon* halduronClone = halduronObject->SummonPersonalClone(halduronObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!halduronClone)
            return;

        orweynaClone->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        halduronClone->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

        conversation->AddActor(Conversations::Actors::OrweynaActorFairbreezeVillage, 0, orweynaClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            if (Creature* orweynaClone = conversation->GetActorCreature(0))
                orweynaClone->GetMotionMaster()->MovePath(Paths::OrweynaStartPathToPortal, false);

        }, conversation->GetLineEndTime(privateOwnerLocale, Conversations::Lines::TheRootCauseStart));

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            Creature* halduronClone = player->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::HalduronFairbreezeVillage, .IgnorePhases = true, .PrivateObjectOwnerGuid = player->GetGUID() });
            if (!halduronClone)
                return;

            halduronClone->GetMotionMaster()->MovePath(Paths::HalduronStartPathToPortal, false);
        }, conversation->GetLineEndTime(privateOwnerLocale, Conversations::Lines::TheRootCauseStart) +3s);
    }
};

constexpr Position OrweynaCaveCloneSpawnPos = { -177.722f, -2148.79f, 1176.92f, 3.8025f };
constexpr Position HalduronCaveCloneSpawnPos = { -174.458f, -2152.74f, 1177.08f, 1.10846f };

// 29720 - Conversation
class conversation_to_harathir_follow_orweyna : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* orweynaObject = creator->FindNearestCreatureWithOptions(120.0f, { .CreatureId = Creatures::OrweynaAmirdrassilRoots, .StringId = "CloneTarget", .IgnorePhases = true });
        if (!orweynaObject)
            return;

        Creature* halduronObject = creator->FindNearestCreatureWithOptions(120.0f, { .CreatureId = Creatures::HalduronAmirdrassilRoots, .StringId = "CloneTarget", .IgnorePhases = true });
        if (!halduronObject)
            return;

        TempSummon* orweynaClone = orweynaObject->SummonPersonalClone(OrweynaCaveCloneSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!orweynaClone)
            return;

        TempSummon* halduronClone = halduronObject->SummonPersonalClone(HalduronCaveCloneSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!halduronClone)
            return;

        orweynaClone->SetScriptStringId("Cave");
        halduronClone->SetScriptStringId("Cave");
        orweynaClone->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        orweynaClone->SetUninteractible(true);
        halduronClone->SetUninteractible(true);

        conversation->AddActor(Conversations::Actors::OrweynaActorAmirdrassilRoots, 0, orweynaClone->GetGUID());
        conversation->AddActor(Conversations::Actors::HalduronActorAmirdrassilRoots, 1, halduronClone->GetGUID());
        conversation->Start();
    }
};

// 29598 - Conversation
class conversation_to_harathir_talk_to_kupaal : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* orweynaObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::OrweynaAmirdrassilRoots, .StringId = "CloneTarget", .IgnorePhases = true });
        if (!orweynaObject)
            return;

        Creature* halduronObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::HalduronAmirdrassilRoots, .StringId = "CloneTarget", .IgnorePhases = true });
        if (!halduronObject)
            return;

        Creature* kupaalObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::KupaalAmirdrassilRoots, .StringId = "CloneTarget", .IgnorePhases = true });
        if (!halduronObject)
            return;

        TempSummon* orweynaClone = orweynaObject->SummonPersonalClone(orweynaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!orweynaClone)
            return;

        TempSummon* halduronClone = halduronObject->SummonPersonalClone(halduronObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!halduronClone)
            return;

        TempSummon* kupaalClone = kupaalObject->SummonPersonalClone(kupaalObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!orweynaClone)
            return;

        conversation->AddActor(Conversations::Actors::OrweynaActorAmirdrassilRoots, 0, orweynaClone->GetGUID());
        conversation->AddActor(Conversations::Actors::HalduronActorAmirdrassilRoots, 1, kupaalClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            Creature* halduronClone = player->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::HalduronAmirdrassilRoots, .IgnorePhases = true, .PrivateObjectOwnerGuid = player->GetGUID() });
            if (!halduronClone)
                return;

            if (Creature* orweynaClone = conversation->GetActorCreature(0))
                orweynaClone->GetMotionMaster()->MovePath(Paths::OrweynaPathToHarathir, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, {}, true, 1000ms);

            if (Creature* kupaalClone = conversation->GetActorCreature(1))
                kupaalClone->GetMotionMaster()->MovePath(Paths::KupaalPathToHarathir, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, {}, true, 1000ms);

            halduronClone->GetMotionMaster()->MovePath(Paths::HalduronPathToHarathir, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, {}, true, 1000ms);

        }, conversation->GetLastLineEndTime(conversation->GetPrivateObjectOwnerLocale()));
    }
};
}

void AddSC_harandar_chapter_1_of_caves_and_cradles()
{
    using namespace Scripts::QuelThalas::Harandar::Chapter1;

    // Conversation
    RegisterConversationAI(conversation_the_root_cause_open_portal);
    RegisterConversationAI(conversation_to_harathir_follow_orweyna);
    RegisterConversationAI(conversation_to_harathir_talk_to_kupaal);
}
