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
#include "SpellScript.h"
#include "TemporarySummon.h"

enum GetYourBearingsData
{
    QUEST_GET_YOUR_BEARINGS             = 47099,

    OBJECTIVE_FERRY_DOCK_VISITED        = 124588,
    OBJECTIVE_COUNTING_HOUSE_VISITED    = 124586,
    OBJECTIVE_SNUG_HARBOR_INN_VISITED   = 124768,
    OBJECTIVE_FLIGHT_MASTER_VISITED     = 124587,

    NPC_SUMMONED_KULTIRAN_GUARD         = 124630,

    EVENT_TAELIA_SET_FACING             = 1,

    CONVO_ACTOR_KULTIRAN_GUARD          = 59582,

    POINT_KULTIRAN_GUARD                = 1,
    POINT_KULTIRAN_GUARD_FLIGHT_MASTER  = 2,

    SPELL_HUB_TOUR_CONVO_FERRY          = 247669,
    SPELL_HUB_TOUR_CONVO_BANK           = 247749,
    SPELL_HUB_TOUR_CONVO_INN            = 247894,
    SPELL_HUB_TOUR_CONVO_FLIGHT_MASTER  = 247753
};

// 124630 - (summon) Taelia
struct npc_taelia_get_your_bearings : public ScriptedAI
{
    npc_taelia_get_your_bearings(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
            me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_KULTIRAN_GUARD)
            _events.ScheduleEvent(EVENT_TAELIA_SET_FACING, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TAELIA_SET_FACING:
                {
                    if (Unit* summoner = me->GetOwner())
                    {
                        me->SetFacingToObject(summoner);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 5360 - Conversation
class conversation_boralus_hub_tour_00 : public ConversationScript
{
public:
    conversation_boralus_hub_tour_00() : ConversationScript("conversation_boralus_hub_tour_00") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }
};

// XX - Boralus - Get your Bearings (Ferry)
struct at_boralus_get_your_bearings_ferry : AreaTriggerAI
{
    at_boralus_get_your_bearings_ferry(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FERRY_DOCK_VISITED))
            return;

        player->CastSpell(nullptr, SPELL_HUB_TOUR_CONVO_FERRY, false);
    }
};

Position const TaeliaFerryPos = { 1039.5955f, -598.00653f, 1.458778f };

// 5362 - Conversation - Get your Bearings (Ferry)
class conversation_boralus_hub_tour_ferry : public ConversationScript
{
public:
    conversation_boralus_hub_tour_ferry() : ConversationScript("conversation_boralus_hub_tour_ferry") { }

    enum ConversationFerryData
    {
        EVENT_TAELIA_FERRY_CREDIT   = 1
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePoint(POINT_KULTIRAN_GUARD, TaeliaFerryPos);

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_TAELIA_FERRY_CREDIT, conversation->GetLastLineEndTime(privateOwnerLocale));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_TAELIA_FERRY_CREDIT:
            {
                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    break;

                Creature* kultiranGuard = privateObjectOwner->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = privateObjectOwner->GetGUID() });
                if (!kultiranGuard)
                    break;

                privateObjectOwner->ToPlayer()->KilledMonsterCredit(OBJECTIVE_FERRY_DOCK_VISITED);
                kultiranGuard->GetMotionMaster()->MoveFollow(privateObjectOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            }
            default:
                break;
        }
    }
private:
    EventMap _events;
};

// XX - Boralus - Get your Bearings (Counting House)
struct at_boralus_get_your_bearings_counting_house : AreaTriggerAI
{
    at_boralus_get_your_bearings_counting_house(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_GET_YOUR_BEARINGS, OBJECTIVE_COUNTING_HOUSE_VISITED))
            return;

        player->CastSpell(nullptr, SPELL_HUB_TOUR_CONVO_BANK, false);
    }
};

Position const TaeliaBankPos = { 1118.7385f, -622.4115f, 17.76035f };

// 5365 - Conversation Get your Bearings (Counting House)
class conversation_boralus_hub_tour_counting_house : public ConversationScript
{
public:
    conversation_boralus_hub_tour_counting_house() : ConversationScript("conversation_boralus_hub_tour_counting_house") { }

    enum ConversationBankData
    {
        EVENT_TAELIA_BANK_CREDIT    = 1
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePoint(POINT_KULTIRAN_GUARD, TaeliaBankPos);

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_TAELIA_BANK_CREDIT, conversation->GetLastLineEndTime(privateOwnerLocale));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_TAELIA_BANK_CREDIT:
            {
                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    break;

                Creature* kultiranGuard = privateObjectOwner->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = privateObjectOwner->GetGUID() });
                if (!kultiranGuard)
                    break;

                privateObjectOwner->ToPlayer()->KilledMonsterCredit(OBJECTIVE_COUNTING_HOUSE_VISITED);
                kultiranGuard->GetMotionMaster()->MoveFollow(privateObjectOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// XX - Boralus Get your Bearings (Harbor Inn)
struct at_boralus_get_your_bearings_inn : AreaTriggerAI
{
    at_boralus_get_your_bearings_inn(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_GET_YOUR_BEARINGS, OBJECTIVE_SNUG_HARBOR_INN_VISITED))
            return;

        player->CastSpell(nullptr, SPELL_HUB_TOUR_CONVO_INN, false);
    }
};

Position const TaeliaInnPos = { 1177.39f, -587.682f, 31.557224f };

// 5375 - Conversation Get your Bearings (Harbor Inn)
class conversation_boralus_hub_tour_harbor_inn : public ConversationScript
{
public:
    conversation_boralus_hub_tour_harbor_inn() : ConversationScript("conversation_boralus_hub_tour_harbor_inn") { }

    enum ConversationInnData
    {
        CONVO_LINE_INN_CREDIT   = 17269,

        EVENT_TAELIA_INN_CREDIT = 1
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePoint(POINT_KULTIRAN_GUARD, TaeliaInnPos);

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_TAELIA_INN_CREDIT, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_INN_CREDIT));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_TAELIA_INN_CREDIT:
            {
                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    break;

                Creature* kultiranGuard = privateObjectOwner->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = privateObjectOwner->GetGUID() });
                if (!kultiranGuard)
                    break;

                privateObjectOwner->ToPlayer()->KilledMonsterCredit(OBJECTIVE_SNUG_HARBOR_INN_VISITED);
                kultiranGuard->GetMotionMaster()->MoveFollow(privateObjectOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// XX - Boralus Get your Bearings (Flight Master)
struct at_boralus_get_your_bearings_flight_master : AreaTriggerAI
{
    at_boralus_get_your_bearings_flight_master(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FLIGHT_MASTER_VISITED))
            return;

        player->CastSpell(nullptr, SPELL_HUB_TOUR_CONVO_FLIGHT_MASTER, false);
    }
};

Position const TaeliaFlightMasterPos = { 1149.82f, -471.071f, 30.503826f };

// 5366 - Conversation Get your Bearings (Flight Master)
class conversation_boralus_hub_tour_flight_master : public ConversationScript
{
public:
    conversation_boralus_hub_tour_flight_master() : ConversationScript("conversation_boralus_hub_tour_flight_master") { }

    enum ConversationInnData
    {
        CONVO_LINE_FLIGHT_MASTER_CREDIT     = 17271,

        EVENT_TAELIA_FLIGHT_MASTER_CREDIT   = 1
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePoint(POINT_KULTIRAN_GUARD_FLIGHT_MASTER, TaeliaFlightMasterPos);

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_TAELIA_FLIGHT_MASTER_CREDIT, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_FLIGHT_MASTER_CREDIT));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_TAELIA_FLIGHT_MASTER_CREDIT:
            {
                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    break;

                Creature* kultiranGuard = privateObjectOwner->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = privateObjectOwner->GetGUID() });
                if (!kultiranGuard)
                    break;

                privateObjectOwner->ToPlayer()->KilledMonsterCredit(OBJECTIVE_FLIGHT_MASTER_VISITED);
                kultiranGuard->GetMotionMaster()->MoveFollow(privateObjectOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_zone_boralus()
{
    // Creature
    RegisterCreatureAI(npc_taelia_get_your_bearings);

    // Conversation
    new conversation_boralus_hub_tour_00();
    new conversation_boralus_hub_tour_ferry();
    new conversation_boralus_hub_tour_counting_house();
    new conversation_boralus_hub_tour_harbor_inn();
    new conversation_boralus_hub_tour_flight_master();

    // AreaTrigger
    RegisterAreaTriggerAI(at_boralus_get_your_bearings_ferry);
    RegisterAreaTriggerAI(at_boralus_get_your_bearings_counting_house);
    RegisterAreaTriggerAI(at_boralus_get_your_bearings_inn);
    RegisterAreaTriggerAI(at_boralus_get_your_bearings_flight_master);
}
