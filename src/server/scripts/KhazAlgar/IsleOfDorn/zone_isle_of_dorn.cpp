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

#include "Containers.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum PreciousGemsData
{
    NPC_NATALIA_PEARCES_FREYWOLD            = 223637,
    NPC_NATALIA_PEARCES_INSIDE_BASALTEOUS   = 223924,

    CONVO_ACTOR_NATALIA_FREYWOLD            = 99047,
    CONVO_ACTOR_NATALIA_BASALTEOUS_CAVE     = 99215,

    PATH_NATALIA_CLONE_FREYWOLD             = 22363700,
    PATH_NATALIA_CLONE_BASALTEOUS_CAVE      = 22392400
};

// 25586 - Conversation
class conversation_natalia_pearces_accept_precious_gems : public ConversationAI
{
public:
    conversation_natalia_pearces_accept_precious_gems(Conversation* conversation) : ConversationAI(conversation) { }

    enum ConversationPreciousGemsIntro
    {
        EVENT_NATALIA_START_INTRO_PATH  = 1
    };

    void OnCreate(Unit* creator) override
    {
        Creature* nataliaObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_NATALIA_PEARCES_FREYWOLD, .IgnorePhases = true });
        if (!nataliaObject)
            return;

        TempSummon* nataliaClone = nataliaObject->SummonPersonalClone(nataliaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!nataliaClone)
            return;

        nataliaClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        conversation->AddActor(CONVO_ACTOR_NATALIA_FREYWOLD, 0, nataliaClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([this]()
        {
            Creature* nataliaClone = conversation->GetActorCreature(0);
            if (!nataliaClone)
                return;

            nataliaClone->GetMotionMaster()->MovePath(PATH_NATALIA_CLONE_FREYWOLD, false);
        }, conversation->GetLastLineEndTime(privateOwnerLocale));
    }
};

constexpr Position NataliaSpawnPos = { 568.539f, -1205.899f, 2.48101f, 1.82973f };

// 25590 - Conversation
class conversation_natalia_pearces_complete_precious_gems : public ConversationAI
{
public:
    conversation_natalia_pearces_complete_precious_gems(Conversation* conversation) : ConversationAI(conversation) { }

    void OnCreate(Unit* creator) override
    {
        Creature* nataliaObject = GetClosestCreatureWithOptions(creator, 60.0f, { .CreatureId = NPC_NATALIA_PEARCES_INSIDE_BASALTEOUS, .IgnorePhases = true });
        if (!nataliaObject)
            return;

        TempSummon* nataliaClone = nataliaObject->SummonPersonalClone(NataliaSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!nataliaClone)
            return;

        nataliaClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
        nataliaClone->SetUnitFlag(UnitFlags(UNIT_FLAG_UNINTERACTIBLE));
        nataliaClone->GetMotionMaster()->MovePath(PATH_NATALIA_CLONE_BASALTEOUS_CAVE, false);

        conversation->AddActor(CONVO_ACTOR_NATALIA_BASALTEOUS_CAVE, 0, nataliaClone->GetGUID());
        conversation->Start();
    }
};

void AddSC_zone_isle_of_dorn()
{
    // Conversation
    RegisterConversationAI(conversation_natalia_pearces_accept_precious_gems);
    RegisterConversationAI(conversation_natalia_pearces_complete_precious_gems);
}
