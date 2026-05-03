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
}
namespace Conversations
{
    namespace Actors
    {
        static constexpr uint32 OrweynaActorFairbreezeVillage = 105442;
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
}

void AddSC_harandar_chapter_1_of_caves_and_cradles()
{
    using namespace Scripts::QuelThalas::Harandar::Chapter1;

    // Conversation
    RegisterConversationAI(conversation_the_root_cause_open_portal);
}
