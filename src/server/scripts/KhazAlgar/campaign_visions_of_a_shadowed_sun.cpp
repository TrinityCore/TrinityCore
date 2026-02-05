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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"

namespace Scripts::KhazAlgar::CampaignsVisionsOfAShadowedSun
{

namespace Creatures
{
    static constexpr uint32 VereesaWindrunnerOztanIsle = 231042;
    static constexpr uint32 AratorOztanIsle = 231039;
}

namespace Mounts
{
    static constexpr uint32 VereesaWindrunnerMount = 69274;
    static constexpr uint32 AratorMount = 14584;
}

namespace Paths
{
    static constexpr uint32 VereesaOztanIslePath = 23104200;
    static constexpr uint32 AratorOztanIslePath = 23103900;
}

namespace Actions
{
    static constexpr uint32 ActionSkipConversation = 1;
}

namespace Gossips
{
    namespace MenuIds
    {
        static constexpr uint32 GossipVereesaOztanIsle = 37102;
    }

    namespace Options
    {
        static constexpr uint32 OptionListenToVereesasTale = 0;
        static constexpr uint32 OptionSkipListenToVereesasTale = 1;
    }
}

namespace Conversations
{
    namespace Ids
    {
        static constexpr uint32 ConversationVereesasTale = 27493;
    }

    namespace Actors
    {
        static constexpr uint32 VereesaActorOztanIsle = 102984;
        static constexpr uint32 AratorActorOztanIsle = 102985;
    }

    namespace Lines
    {
        static constexpr uint32 VereesaOztanIsleSetFacing = 75392;
    }
}

// 231042 - Vereesa Windrunner
struct npc_vereesa_windrunner_oztan_isle : public ScriptedAI
{
    npc_vereesa_windrunner_oztan_isle(Creature* creature) : ScriptedAI(creature) {}

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        if (menuId == Gossips::MenuIds::GossipVereesaOztanIsle && gossipListId == Gossips::Options::OptionListenToVereesasTale)
        {
            CloseGossipMenuFor(player);

            Conversation::CreateConversation(Conversations::Ids::ConversationVereesasTale, player, *player, player->GetGUID(), nullptr, false);
        }
        else if (menuId == Gossips::MenuIds::GossipVereesaOztanIsle && gossipListId == Gossips::Options::OptionSkipListenToVereesasTale)
        {
            CloseGossipMenuFor(player);

            Creature* clone = me->SummonPersonalClone(me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
            if (!clone)
                return true;

            clone->AI()->DoAction(Actions::ActionSkipConversation);
        }
        return true;
    }
};

// 231042 - Vereesa Windrunner
struct npc_vereesa_windrunner_oztan_isle_private : public ScriptedAI
{
    npc_vereesa_windrunner_oztan_isle_private(Creature* creature) : ScriptedAI(creature) {}

    void DoAction(int32 action) override
    {
        if (action == Actions::ActionSkipConversation)
        {
            Player* player = me->GetDemonCreatorPlayer();
            if (!player)
                return;

            Creature* aratorObject = me->FindNearestCreatureWithOptions(10.0f, { .CreatureId = Creatures::AratorOztanIsle, .IgnorePhases = true });
            if (!aratorObject)
                return;

            Creature* aratorClone = aratorObject->SummonPersonalClone(aratorObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
            if (!aratorClone)
                return;

            me->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
            aratorClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

            _scheduler.Schedule(1s, [this, aratorGuid = aratorClone->GetGUID()](TaskContext task)
            {
                Creature* aratorClone = ObjectAccessor::GetCreature(*me, aratorGuid);
                if (!aratorClone)
                    return;

                me->SetMountDisplayId(Mounts::VereesaWindrunnerMount);
                aratorClone->SetMountDisplayId(Mounts::AratorMount);
                task.Schedule(2s, [this, aratorGuid](TaskContext /*task*/)
                {
                    Creature* aratorClone = ObjectAccessor::GetCreature(*me, aratorGuid);
                    if (!aratorClone)
                        return;

                    me->GetMotionMaster()->MovePath(Paths::VereesaOztanIslePath, false);
                    aratorClone->GetMotionMaster()->MovePath(Paths::AratorOztanIslePath, false);
                });
            });
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        Player* player = me->GetDemonCreatorPlayer();
        if (!player)
            return;

        if (pathId == Paths::VereesaOztanIslePath)
        {
            player->KilledMonsterCredit(Creatures::VereesaWindrunnerOztanIsle);
            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
};

CreatureAI* VereesaWindrunnerOztanIsleAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_vereesa_windrunner_oztan_isle_private(creature);
    return new npc_vereesa_windrunner_oztan_isle(creature);
};

// 27493 - Conversation: Vereesas Tale
class conversation_vereesas_tale : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* vereesaObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = Creatures::VereesaWindrunnerOztanIsle, .IgnorePhases = true });
        if (!vereesaObject)
            return;

        Creature* aratorObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = Creatures::AratorOztanIsle, .IgnorePhases = true });
        if (!aratorObject)
            return;

        TempSummon* vereesaClone = vereesaObject->SummonPersonalClone(vereesaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!vereesaClone)
            return;

        TempSummon* aratorClone = aratorObject->SummonPersonalClone(aratorObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!aratorClone)
            return;

        vereesaClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
        aratorClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        conversation->AddActor(Conversations::Actors::VereesaActorOztanIsle, 0, vereesaClone->GetGUID());
        conversation->AddActor(Conversations::Actors::AratorActorOztanIsle, 1, aratorClone->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            if (Creature* vereesaClone = conversation->GetActorCreature(0))
                vereesaClone->SetFacingToObject(player);

        }, conversation->GetLineEndTime(privateOwnerLocale, Conversations::Lines::VereesaOztanIsleSetFacing));

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            if (Creature* vereesaClone = conversation->GetActorCreature(0))
                vereesaClone->SetMountDisplayId(Mounts::VereesaWindrunnerMount);

            if (Creature* aratorClone = conversation->GetActorCreature(1))
                aratorClone->SetMountDisplayId(Mounts::AratorMount);

        }, conversation->GetLastLineEndTime(privateOwnerLocale));

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
            if (!player)
                return;

            if (Creature* vereesaClone = conversation->GetActorCreature(0))
                vereesaClone->GetMotionMaster()->MovePath(Paths::VereesaOztanIslePath, false);

            if (Creature* aratorClone = conversation->GetActorCreature(1))
                aratorClone->GetMotionMaster()->MovePath(Paths::AratorOztanIslePath, false);

        }, conversation->GetLastLineEndTime(privateOwnerLocale) + 2s);
    }
};
}

void AddSC_campaign_visions_of_a_shadowed_sun()
{
    using namespace Scripts::KhazAlgar::CampaignsVisionsOfAShadowedSun;

    // AISelector
    new FactoryCreatureScript<CreatureAI, &VereesaWindrunnerOztanIsleAISelector>("npc_vereesa_windrunner_oztan_isle");

    // Conversation
    RegisterConversationAI(conversation_vereesas_tale);
}
