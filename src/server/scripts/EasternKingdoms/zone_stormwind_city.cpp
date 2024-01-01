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
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum TidesOfWarData
{
    QUEST_TIDES_OF_WAR                      = 46727,

    QUEST_OBJECTIVE_ATTEND_COUNCIL          = 337817,

    MOVIE_POST_TIDES_OF_WAR                 = 858,

    NPC_JAINA_TIDES_OF_WAR                  = 120590,
    NPC_ANDUIN_TIDES_OF_WAR                 = 120756,
    NPC_VISION_OF_SAILORS_MEMORY            = 139645,

    SPELL_JAINA_ARCANE_CHANNEL              = 54219,
    SPELL_CONVO_POST_MOVIE_TIDES_OF_WAR     = 281343,

    CONVERSATION_START_COUNCIL_TIDES_OF_WAR = 4857,

    PATH_JAINA_VISION_START                 = 12059000,
    PATH_JAINA_VISION_FINISH                = 12059001
};

enum NationOfKulTirasData
{
    QUEST_NATION_OF_KULTIRAS            = 46728,
    QUEST_NATION_OF_KULTIRAS_NPE        = 59641,
    QUEST_OUT_LIKE_FLYNN                = 47098,
    QUEST_DAUGHTER_OF_THE_SEA           = 51341,

    SAY_JAINA_LEAVE_COUNCIL             = 0,

    SPELL_JAINA_TELEPORT                = 40163,
    SPELL_SKIP_KULTIRAS_INTRO           = 279998,
    SPELL_SKIP_TOLDAGOR_TELEPORT        = 247285,

    CONVERSATION_JAINA_LEAVE_COUNCIL    = 4896,

    ACTION_JAINA_LEAVE_COUNCIL          = 1,

    GOSSIP_MENU_NATION_OF_KULTIRAS      = 22328,

    GOSSIP_OPTION_START_KULTIRAS_INTRO  = 0,
    GOSSIP_OPTION_SKIP_KULTIRAS_INTRO   = 1
};

// 55 - Stormwind Keep - Tides of War
struct at_stormwind_keep_tides_of_war : AreaTriggerAI
{
    at_stormwind_keep_tides_of_war(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_TIDES_OF_WAR) != QUEST_STATUS_INCOMPLETE)
            return;

        // @TODO: cooldown after generic impl

        Conversation::CreateConversation(CONVERSATION_START_COUNCIL_TIDES_OF_WAR, unit, unit->GetPosition(), unit->GetGUID(), nullptr, false);
    }
};

Position const VisionOfSailorsMemoryPosition = { -8384.131f, 324.383f, 148.443f, 1.559973f };

// 4857 - Conversation
class conversation_start_council_tides_of_war : public ConversationScript
{
public:
    conversation_start_council_tides_of_war() : ConversationScript("conversation_start_council_tides_of_war") { }

    enum Events
    {
        EVENT_JAINA_WALK            = 1,
        EVENT_KILL_CREDIT
    };

    enum ConversatonData
    {
        CONVO_ACTOR_JAINA           = 467,

        CONVO_LINE_JAINA_WALK       = 19485,
        CONVO_LINE_JAINA_CREDIT     = 19486,
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* jainaObject = GetClosestCreatureWithOptions(creator, 30.0f, { .CreatureId = NPC_JAINA_TIDES_OF_WAR, .IgnorePhases = true });
        if (!jainaObject)
            return;

        TempSummon* jainaClone = jainaObject->SummonPersonalClone(jainaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!jainaClone)
            return;

        conversation->AddActor(CONVO_ACTOR_JAINA, 3, jainaClone->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        if (Milliseconds const* jainaWalkStartTime = conversation->GetLineStartTime(privateOwnerLocale, CONVO_LINE_JAINA_WALK))
            _events.ScheduleEvent(EVENT_JAINA_WALK, *jainaWalkStartTime);

        _events.ScheduleEvent(EVENT_KILL_CREDIT, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_JAINA_CREDIT));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_JAINA_WALK:
            {
                Creature* jainaClone = conversation->GetActorCreature(3);
                if (!jainaClone)
                    break;

                jainaClone->GetMotionMaster()->MovePath(PATH_JAINA_VISION_START, false);
                break;
            }
            case EVENT_KILL_CREDIT:
            {
                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    break;

                Player* player = privateObjectOwner->ToPlayer();
                if (!player)
                    break;

                player->KilledMonsterCredit(NPC_ANDUIN_TIDES_OF_WAR);
                privateObjectOwner->SummonCreature(NPC_VISION_OF_SAILORS_MEMORY, VisionOfSailorsMemoryPosition, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, privateObjectOwner->GetGUID());
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// 120590 - Jaina Proudmoore
struct npc_jaina_proudmoore_tides_of_war : public ScriptedAI
{
    npc_jaina_proudmoore_tides_of_war(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        if (menuId == GOSSIP_MENU_NATION_OF_KULTIRAS)
        {
            if (gossipListId == GOSSIP_OPTION_START_KULTIRAS_INTRO)
            {
                CloseGossipMenuFor(player);
                // @TODO: script start of TolDagor intro
            }
            else if (gossipListId == GOSSIP_OPTION_SKIP_KULTIRAS_INTRO)
            {
                CloseGossipMenuFor(player);
                player->CastSpell(nullptr, SPELL_SKIP_KULTIRAS_INTRO, false);
            }
        }
        return true;
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_JAINA_VISION_START)
        {
            me->SetFacingTo(5.1164f);
            DoCastAOE(SPELL_JAINA_ARCANE_CHANNEL);

            _scheduler.Schedule(14s, [this](TaskContext /*context*/)
            {
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                me->GetMotionMaster()->MovePath(PATH_JAINA_VISION_FINISH, false);
            });
        }
        else if (pathId == PATH_JAINA_VISION_FINISH)
            me->DespawnOrUnsummon();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_JAINA_LEAVE_COUNCIL)
        {
            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                Talk(SAY_JAINA_LEAVE_COUNCIL, me);
                task.Schedule(4s, [this](TaskContext task)
                {
                    DoCastSelf(SPELL_JAINA_TELEPORT);
                    task.Schedule(2s, [this](TaskContext /*task*/)
                    {
                        Unit* privateObjectOwner = ObjectAccessor::GetUnit(*me, me->GetPrivateObjectOwner());
                        if (!privateObjectOwner)
                            return;

                        Conversation::CreateConversation(CONVERSATION_JAINA_LEAVE_COUNCIL, privateObjectOwner, *privateObjectOwner, privateObjectOwner->GetGUID(), nullptr, true);
                        me->DespawnOrUnsummon();
                    });
                });
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 858 - Movie
class player_conv_after_movie_tides_of_war : public PlayerScript
{
public:
    player_conv_after_movie_tides_of_war() : PlayerScript("player_conv_after_movie_tides_of_war") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if (movieId == MOVIE_POST_TIDES_OF_WAR)
        {
            Creature* jainaClone = GetClosestCreatureWithOptions(player, 30.0f, { .CreatureId = NPC_JAINA_TIDES_OF_WAR, .IgnorePhases = true, .PrivateObjectOwnerGuid = player->GetGUID() });
            if (!jainaClone)
                return;

            jainaClone->DespawnOrUnsummon();
            player->CastSpell(player, SPELL_CONVO_POST_MOVIE_TIDES_OF_WAR, true);
        }
    }
};

// 284807 - Despawn
class spell_despawn_sailor_memory : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitUnit()->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_despawn_sailor_memory::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 120756 - Anduin Wrynn
struct npc_anduin_wrynn_nation_of_kultiras : public ScriptedAI
{
    npc_anduin_wrynn_nation_of_kultiras(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_NATION_OF_KULTIRAS)
        {
            PhasingHandler::OnConditionChange(player);

            Creature* jainaObject = GetClosestCreatureWithOptions(player, 15.0f, { .CreatureId = NPC_JAINA_TIDES_OF_WAR, .IgnorePhases = true });
            if (!jainaObject)
                return;

            TempSummon* jainaClone = jainaObject->SummonPersonalClone(jainaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player->ToPlayer());
            if (!jainaClone)
                return;

            jainaClone->AI()->DoAction(ACTION_JAINA_LEAVE_COUNCIL);
        }
    }
};

// 279998 - Kul Tiras: Skip Intro
class spell_kultiras_skip_intro : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->CastSpell(nullptr, SPELL_SKIP_TOLDAGOR_TELEPORT, false);
            player->SkipQuests({ QUEST_NATION_OF_KULTIRAS, QUEST_NATION_OF_KULTIRAS_NPE, QUEST_OUT_LIKE_FLYNN, QUEST_DAUGHTER_OF_THE_SEA });
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kultiras_skip_intro::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_stormwind_city()
{
    // Creature
    RegisterCreatureAI(npc_jaina_proudmoore_tides_of_war);
    RegisterCreatureAI(npc_anduin_wrynn_nation_of_kultiras);

    // Conversation
    new conversation_start_council_tides_of_war();

    // PlayerScript
    new player_conv_after_movie_tides_of_war();

    // AreaTrigger
    RegisterAreaTriggerAI(at_stormwind_keep_tides_of_war);

    // Spells
    RegisterSpellScript(spell_despawn_sailor_memory);
    RegisterSpellScript(spell_kultiras_skip_intro);
}
