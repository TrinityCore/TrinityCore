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

    KILL_CREDIT_FERRY_DOCK_VISITED      = 124588,
    KILL_CREDIT_COUNTING_HOUSE_VISITED  = 124586,
    KILL_CREDIT_SNUG_HARBOR_INN_VISITED = 124768,
    KILL_CREDIT_FLIGHT_MASTER_VISITED   = 124587,

    OBJECTIVE_FERRY_DOCK_VISITED        = 291081,
    OBJECTIVE_COUNTING_HOUSE_VISITED    = 291079,
    OBJECTIVE_SNUG_HARBOR_INN_VISITED   = 291080,
    OBJECTIVE_FLIGHT_MASTER_VISITED     = 291171,

    NPC_SUMMONED_KULTIRAN_GUARD         = 124630,

    CONVO_ACTOR_KULTIRAN_GUARD          = 59582,

    POINT_KULTIRAN_GUARD                = 1,
    POINT_KULTIRAN_GUARD_FLIGHT_MASTER  = 2,

    SPELL_HUB_TOUR_CONVO_FERRY          = 247669,
    SPELL_HUB_TOUR_CONVO_BANK           = 247749,
    SPELL_HUB_TOUR_CONVO_INN            = 247894,
    SPELL_HUB_TOUR_CONVO_FLIGHT_MASTER  = 247753
};

// 124630 - Taelia
struct npc_taelia_get_your_bearings : public ScriptedAI
{
    npc_taelia_get_your_bearings(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        // might be handled by SummonProperties
        if (Player* player = summoner->ToPlayer())
            me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_KULTIRAN_GUARD)
        {
            if (Unit* summoner = me->GetOwner())
                me->SetFacingToObject(summoner);
        }
    }
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
// XX - Boralus - Get your Bearings (Bank)
// XX - Boralus - Get your Bearings (Inn)
// XX - Boralus - Get your Bearings (Flightmaster)
template<uint32 QuestId, uint32 ObjectiveId, uint32 SpellId>
struct at_boralus_get_your_bearings : AreaTriggerAI
{
    at_boralus_get_your_bearings(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QuestId) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QuestId, ObjectiveId))
            return;

        player->CastSpell(nullptr, SpellId, false);
    }
};

// 5362 - Conversation - Get your Bearings (Ferry)
class conversation_boralus_hub_tour : public ConversationScript
{
public:
    conversation_boralus_hub_tour(char const* scriptName) : ConversationScript(scriptName) { }

    enum ConversationFerryData
    {
        EVENT_TAELIA_CREDIT   = 1
    };

    virtual Position const& GetGuardMovePosition() = 0;
    virtual uint32 GetKillCreditId() = 0;

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePoint(POINT_KULTIRAN_GUARD, GetGuardMovePosition());

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_TAELIA_CREDIT, conversation->GetLastLineEndTime(privateOwnerLocale));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_TAELIA_CREDIT:
            {
                Player* player = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
                if (!player)
                    break;

                Creature* kultiranGuard = player->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = player->GetGUID() });
                if (!kultiranGuard)
                    break;

                player->KilledMonsterCredit(GetKillCreditId());
                kultiranGuard->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            }
            default:
                break;
        }
    }
private:
    EventMap _events;
};

Position const TaeliaFerryPos = { 1039.5955f, -598.00653f, 1.458778f };

// 5362 - Conversation - Get your Bearings (Ferry)
class conversation_boralus_hub_tour_ferry : public conversation_boralus_hub_tour
{
public:
    conversation_boralus_hub_tour_ferry() : conversation_boralus_hub_tour("conversation_boralus_hub_tour_ferry") { }

    Position const& GetGuardMovePosition()
    {
        return TaeliaFerryPos;
    }

    uint32 GetKillCreditId()
    {
        return KILL_CREDIT_FERRY_DOCK_VISITED;
    }
};

Position const TaeliaBankPos = { 1118.7385f, -622.4115f, 17.76035f };

// 5365 - Conversation Get your Bearings (Counting House)
class conversation_boralus_hub_tour_counting_house : public conversation_boralus_hub_tour
{
public:
    conversation_boralus_hub_tour_counting_house() : conversation_boralus_hub_tour("conversation_boralus_hub_tour_counting_house") { }

    Position const& GetGuardMovePosition()
    {
        return TaeliaBankPos;
    }

    uint32 GetKillCreditId()
    {
        return KILL_CREDIT_COUNTING_HOUSE_VISITED;
    }
};

Position const TaeliaInnPos = { 1177.39f, -587.682f, 31.557224f };

// 5375 - Conversation Get your Bearings (Harbor Inn)
class conversation_boralus_hub_tour_harbor_inn : public conversation_boralus_hub_tour
{
public:
    conversation_boralus_hub_tour_harbor_inn() : conversation_boralus_hub_tour("conversation_boralus_hub_tour_harbor_inn") { }

    Position const& GetGuardMovePosition()
    {
        return TaeliaInnPos;
    }

    uint32 GetKillCreditId()
    {
        return KILL_CREDIT_SNUG_HARBOR_INN_VISITED;
    }
};

Position const TaeliaFlightMasterPos = { 1149.82f, -471.071f, 30.503826f };

// 5366 - Conversation Get your Bearings (Flight Master)
class conversation_boralus_hub_tour_flight_master : public conversation_boralus_hub_tour
{
public:
    conversation_boralus_hub_tour_flight_master() : conversation_boralus_hub_tour("conversation_boralus_hub_tour_flight_master") { }

    Position const& GetGuardMovePosition()
    {
        return TaeliaFlightMasterPos;
    }

    uint32 GetKillCreditId()
    {
        return KILL_CREDIT_FLIGHT_MASTER_VISITED;
    }
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
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FERRY_DOCK_VISITED, SPELL_HUB_TOUR_CONVO_FERRY>>("at_boralus_get_your_bearings_ferry");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_COUNTING_HOUSE_VISITED, SPELL_HUB_TOUR_CONVO_BANK>>("at_boralus_get_your_bearings_counting_house");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_SNUG_HARBOR_INN_VISITED, SPELL_HUB_TOUR_CONVO_INN>>("at_boralus_get_your_bearings_inn");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FLIGHT_MASTER_VISITED, SPELL_HUB_TOUR_CONVO_FLIGHT_MASTER>>("at_boralus_get_your_bearings_flight_master");
}
