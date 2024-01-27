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
#include "SpellInfo.h"
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

enum TheOldKnightData
{
    QUEST_THE_OLD_KNIGHT                    = 46729,

    NPC_CYRUS_CRESTFALL                     = 122370,
    NPC_GENN_GREYMANE                       = 120788,
    NPC_GREYGUARD                           = 120599,

    GOSSIP_MENU_CYRUS_SHAKING_HANDS         = 22543,
    GOSSIP_OPTION_CYRUS_SHAKING_HANDS       = 0,

    CONVO_ACCEPT_OLD_KNIGHT_QUEST           = 9556,
    CONVO_CYRUS_MEETS_GENN_IN_OFFICE        = 8062,
    CONVO_CYRUS_SHAKING_HAND                = 7653,

    CONVO_ACTOR_CYRUS_CRESTFAL              = 59635,

    OBJECTIVE_ENTER_HARBORMASTERS_OFFICE    = 335127,

    KILLCREDIT_SPEAK_WITH_CYRUS_OLD_KNIGHT  = 137009,
    KILLCREDIT_HEAR_CYRUS_TALE_OLD_KNIGHT   = 137877,

    PATH_KULTIRAN_GUARD_ENTER_OFFICE        = 12463000,
    PATH_KULTIRAN_GUARD_AFTER_SCENE_OFFICE  = 12463001,
    PATH_CYRUS_CRESTFAL_AFTER_SCENE_OFFICE  = 12237000,
    PATH_GENN_GREYMANE_AFTER_SCENE_OFFICE   = 12078800,
    PATH_GREYGUARD_TWO_AFTER_SCENE_OFFICE   = 12059900,
    PATH_GREYGUARD_ONE_AFTER_SCENE_OFFICE   = 12059901,

    SPELL_ENTER_HARBOR_MASTERS_OFFICE       = 268759,
    SPELL_FIND_CYRUS_OBJECTIVE_COMPLETE     = 269054,
    SPELL_CLIENT_SCENE_CYRUS_AND_GENN       = 271234
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

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_OLD_KNIGHT)
            Conversation::CreateConversation(CONVO_ACCEPT_OLD_KNIGHT_QUEST, player, *player, player->GetGUID(), nullptr, false);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_FIND_CYRUS_OBJECTIVE_COMPLETE)
            return;

        me->GetMotionMaster()->MovePath(PATH_KULTIRAN_GUARD_AFTER_SCENE_OFFICE, false);
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

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_KULTIRAN_GUARD_AFTER_SCENE_OFFICE)
            me->DespawnOrUnsummon();
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

// 9556 - Conversation The Old Knight (accept Quest)
class conversation_boralus_accept_old_knight : public ConversationScript
{
public:
    conversation_boralus_accept_old_knight() : ConversationScript("conversation_boralus_accept_old_knight") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }
};

// XX - Boralus The Old Knight (Enter the Harbormasters Office)
struct at_boralus_old_knight_enter_harbormasters_office : AreaTriggerAI
{
    at_boralus_old_knight_enter_harbormasters_office(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_THE_OLD_KNIGHT) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_THE_OLD_KNIGHT, OBJECTIVE_ENTER_HARBORMASTERS_OFFICE))
            return;

        player->CastSpell(nullptr, SPELL_ENTER_HARBOR_MASTERS_OFFICE, false);
    }
};

// 7605 - Conversation The Old Knight (Enter the Harbormasters Office)
class conversation_boralus_enter_harbormaster_office : public ConversationScript
{
public:
    conversation_boralus_enter_harbormaster_office() : ConversationScript("conversation_boralus_enter_harbormaster_office") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* kultiranGuard = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_KULTIRAN_GUARD, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!kultiranGuard)
            return;

        kultiranGuard->GetMotionMaster()->Clear();
        kultiranGuard->GetMotionMaster()->MovePath(PATH_KULTIRAN_GUARD_ENTER_OFFICE, false);

        conversation->AddActor(CONVO_ACTOR_KULTIRAN_GUARD, 0, kultiranGuard->GetGUID());
        conversation->Start();
    }
};

// XX - Boralus The Old Knight (Genn Greymane arrives Boralus)
struct at_boralus_old_knight_genn_arrives_boralus : AreaTriggerAI
{
    at_boralus_old_knight_genn_arrives_boralus(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_THE_OLD_KNIGHT) != QUEST_STATUS_INCOMPLETE || player->GetQuestObjectiveData(QUEST_THE_OLD_KNIGHT, OBJECTIVE_ENTER_HARBORMASTERS_OFFICE))
            return;

        player->CastSpell(nullptr, SPELL_CLIENT_SCENE_CYRUS_AND_GENN, false);
    }
};

// 1960 - Client Scene: Cyrus and Genn
class scene_boralus_client_scene_cyrus_and_genn : public SceneScript
{
public:
    scene_boralus_client_scene_cyrus_and_genn() : SceneScript("scene_boralus_client_scene_cyrus_and_genn") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_FIND_CYRUS_OBJECTIVE_COMPLETE, true);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_FIND_CYRUS_OBJECTIVE_COMPLETE, true);
    }
};

Position const TaeliaTeleportOfficePos = { 1054.29f, -469.776f, 11.7166f, 3.065999f };

// 269054 - Find Cyrus Objective Complete
class spell_boralus_find_cyrus_objective_complete : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitUnit()->ToPlayer())
        {
            player->KilledMonsterCredit(NPC_CYRUS_CRESTFALL);
            Conversation::CreateConversation(CONVO_CYRUS_MEETS_GENN_IN_OFFICE, player, *player, player->GetGUID(), nullptr, false);
        }
        else
        {
            if (GetHitUnit()->GetEntry() != NPC_SUMMONED_KULTIRAN_GUARD)
                return;

            GetHitUnit()->NearTeleportTo(TaeliaTeleportOfficePos);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_boralus_find_cyrus_objective_complete::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

Position const CyrusOfficePos = { 1056.310f, -470.567f, 11.656f, 5.80610f };
Position const GennOfficePos = { 1052.689f, -470.200f, 11.692f, 0.24838f };
Position const GreyguardOneOfficePos = { 1044.979f, -468.523f, 8.386f, 6.03047f };
Position const GreyguardTwoOfficePos = { 1042.359f, -467.738f, 8.386f, 6.04665f };

// 8062 - Conversation
class conversation_boralus_cyrus_meets_genn : public ConversationScript
{
public:
    conversation_boralus_cyrus_meets_genn() : ConversationScript("conversation_boralus_cyrus_meets_genn") { }

    enum OldKnightsConversationData
    {
        CONVO_LINE_CYRUS_AND_GENN_DESPAWN   = 18298,

        EVENT_OLD_KNIGHTS_CLONE_DESPAWN     = 1
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* cyrusObject = GetClosestCreatureWithOptions(creator, 30.0f, { .CreatureId = NPC_CYRUS_CRESTFALL, .IgnorePhases = true });
        Creature* gennObject = GetClosestCreatureWithOptions(creator, 30.0f, { .CreatureId = NPC_GENN_GREYMANE, .IgnorePhases = true });
        Creature* greyguardOneObject = GetClosestCreatureWithOptions(creator, 30.0f, { .CreatureId = NPC_GREYGUARD, .StringId = "GreyguardOne", .IgnorePhases = true });
        Creature* greyguardTwoObject = GetClosestCreatureWithOptions(creator, 30.0f, { .CreatureId = NPC_GREYGUARD, .StringId = "GreyguardTwo", .IgnorePhases = true });
        if (!cyrusObject || !gennObject || !greyguardOneObject || !greyguardTwoObject)
            return;

        TempSummon* cyrusClone = cyrusObject->SummonPersonalClone(CyrusOfficePos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* gennClone = gennObject->SummonPersonalClone(GennOfficePos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* greyguardOneClone = greyguardOneObject->SummonPersonalClone(GreyguardOneOfficePos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        TempSummon* greyguardTwoClone = greyguardTwoObject->SummonPersonalClone(GreyguardTwoOfficePos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!cyrusClone || !gennClone || !greyguardOneClone || !greyguardTwoClone)
            return;

        _gennCloneGUID = gennClone->GetGUID();

        cyrusClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
        gennClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        cyrusClone->GetMotionMaster()->MovePath(PATH_CYRUS_CRESTFAL_AFTER_SCENE_OFFICE, false);
        gennClone->GetMotionMaster()->MovePath(PATH_GENN_GREYMANE_AFTER_SCENE_OFFICE, false);
        greyguardOneClone->GetMotionMaster()->MovePath(PATH_GREYGUARD_ONE_AFTER_SCENE_OFFICE, false);
        greyguardTwoClone->GetMotionMaster()->MovePath(PATH_GREYGUARD_TWO_AFTER_SCENE_OFFICE, false);

        conversation->AddActor(CONVO_ACTOR_CYRUS_CRESTFAL, 0, cyrusClone->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_OLD_KNIGHTS_CLONE_DESPAWN, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_CYRUS_AND_GENN_DESPAWN));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_OLD_KNIGHTS_CLONE_DESPAWN:
            {
                Creature* cyrusClone = conversation->GetActorCreature(0);
                if (!cyrusClone)
                    break;

                Unit* privateObjectOwner = ObjectAccessor::GetUnit(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    return;

                if (Creature* gennClone = ObjectAccessor::GetCreature(*conversation, _gennCloneGUID))
                    gennClone->DespawnOrUnsummon();

                cyrusClone->DespawnOrUnsummon();
                PhasingHandler::OnConditionChange(privateObjectOwner);
                break;
            }
            default:
                break;
        }
    }

private:
    ObjectGuid _gennCloneGUID;
    EventMap _events;
};

// 122370 - Cyrus Crestfall
struct npc_cyrus_crestfall_old_knight : public ScriptedAI
{
    npc_cyrus_crestfall_old_knight(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        // Quest 46729 - The Old Knight
        if (menuId == GOSSIP_MENU_CYRUS_SHAKING_HANDS && gossipListId == GOSSIP_OPTION_CYRUS_SHAKING_HANDS)
        {
            CloseGossipMenuFor(player);
            player->KilledMonsterCredit(KILLCREDIT_SPEAK_WITH_CYRUS_OLD_KNIGHT);
            Conversation::CreateConversation(CONVO_CYRUS_SHAKING_HAND, player, *player, player->GetGUID(), nullptr, false);
        }
        return true;
    }
};

Position const CyrusMoveToOfficeFirePos = { 1075.257f, -487.25696f, 9.812291f };
Position const CyrusStaticOfficePos = { 1071.428f, -486.312f, 9.783f, 3.4995f };

// 7653 - Conversation
class conversation_cyrus_crestfall_shaking_hands : public ConversationScript
{
public:
    conversation_cyrus_crestfall_shaking_hands() : ConversationScript("conversation_cyrus_crestfall_shaking_hands") { }

    enum ShakingHandsConversationData
    {
        CONVO_LINE_CYRUS_START_WALK_TO_FIRE     = 17416,
        CONVO_LINE_CYRUS_CHANGE_FACING_GENN     = 17419,
        CONVO_LINE_CYRUS_MOVE_BACK_TO_GENN      = 17421,
        CONVO_LINE_CYRUS_DESPAWN_CLONE_OFFICE   = 17423,

        EVENT_CYRUS_START_WALK_TO_FIRE          = 1,
        EVENT_CYRUS_CHANGE_FACING_GENN          = 2,
        EVENT_CYRUS_MOVE_BACK_TO_GENN           = 3,
        EVENT_CYRUS_DESPAWN_CLONE_OFFICE        = 4,

        POINT_CYRUS_MOVE_TO_OFFICE_FIRE         = 1,
        POINT_CYRUS_MOVE_BACK_TO_GENN           = 2
    };

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        Creature* cyrusObject = GetClosestCreatureWithOptions(creator, 10.0f, { .CreatureId = NPC_CYRUS_CRESTFALL, .IgnorePhases = true });
        if (!cyrusObject)
            return;

        TempSummon* cyrusClone = cyrusObject->SummonPersonalClone(cyrusObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());
        if (!cyrusClone)
            return;

        cyrusClone->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));

        conversation->AddActor(CONVO_ACTOR_CYRUS_CRESTFAL, 1, cyrusClone->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        _events.ScheduleEvent(EVENT_CYRUS_START_WALK_TO_FIRE, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_CYRUS_START_WALK_TO_FIRE));
        _events.ScheduleEvent(EVENT_CYRUS_CHANGE_FACING_GENN, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_CYRUS_CHANGE_FACING_GENN));
        _events.ScheduleEvent(EVENT_CYRUS_MOVE_BACK_TO_GENN, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_CYRUS_MOVE_BACK_TO_GENN));
        _events.ScheduleEvent(EVENT_CYRUS_DESPAWN_CLONE_OFFICE, conversation->GetLineEndTime(privateOwnerLocale, CONVO_LINE_CYRUS_DESPAWN_CLONE_OFFICE));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_CYRUS_START_WALK_TO_FIRE:
            {
                Creature* cyrusClone = conversation->GetActorCreature(1);
                if (!cyrusClone)
                    break;

                cyrusClone->SetWalk(true);
                cyrusClone->GetMotionMaster()->MovePoint(POINT_CYRUS_MOVE_TO_OFFICE_FIRE, CyrusMoveToOfficeFirePos);
                break;
            }
            case EVENT_CYRUS_CHANGE_FACING_GENN:
            {
                Creature* cyrusClone = conversation->GetActorCreature(1);
                if (!cyrusClone)
                    break;

                cyrusClone->SetFacingTo(3.49956f);
                break;
            }
            case EVENT_CYRUS_MOVE_BACK_TO_GENN:
            {
                Creature* cyrusClone = conversation->GetActorCreature(1);
                if (!cyrusClone)
                    break;

                Player* privateObjectOwner = ObjectAccessor::GetPlayer(*conversation, conversation->GetPrivateObjectOwner());
                if (!privateObjectOwner)
                    return;

                cyrusClone->SetWalk(true);
                cyrusClone->GetMotionMaster()->MovePoint(POINT_CYRUS_MOVE_BACK_TO_GENN, CyrusStaticOfficePos);
                privateObjectOwner->KilledMonsterCredit(KILLCREDIT_HEAR_CYRUS_TALE_OLD_KNIGHT);
                break;
            }
            case EVENT_CYRUS_DESPAWN_CLONE_OFFICE:
            {
                Creature* cyrusClone = conversation->GetActorCreature(1);
                if (!cyrusClone)
                    break;

                cyrusClone->DespawnOrUnsummon();
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
    RegisterCreatureAI(npc_cyrus_crestfall_old_knight);

    // Conversation
    new conversation_boralus_hub_tour_00();
    new conversation_boralus_hub_tour_ferry();
    new conversation_boralus_hub_tour_counting_house();
    new conversation_boralus_hub_tour_harbor_inn();
    new conversation_boralus_hub_tour_flight_master();
    new conversation_boralus_accept_old_knight();
    new conversation_boralus_enter_harbormaster_office();
    new conversation_boralus_cyrus_meets_genn();
    new conversation_cyrus_crestfall_shaking_hands();

    // Scene
    new scene_boralus_client_scene_cyrus_and_genn();

    // AreaTrigger
    RegisterAreaTriggerAI(at_boralus_old_knight_enter_harbormasters_office);
    RegisterAreaTriggerAI(at_boralus_old_knight_genn_arrives_boralus);

    // AreaTrigger Template
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FERRY_DOCK_VISITED, SPELL_HUB_TOUR_CONVO_FERRY>>("at_boralus_get_your_bearings_ferry");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_COUNTING_HOUSE_VISITED, SPELL_HUB_TOUR_CONVO_BANK>>("at_boralus_get_your_bearings_counting_house");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_SNUG_HARBOR_INN_VISITED, SPELL_HUB_TOUR_CONVO_INN>>("at_boralus_get_your_bearings_inn");
    new GenericAreaTriggerEntityScript<at_boralus_get_your_bearings<QUEST_GET_YOUR_BEARINGS, OBJECTIVE_FLIGHT_MASTER_VISITED, SPELL_HUB_TOUR_CONVO_FLIGHT_MASTER>>("at_boralus_get_your_bearings_flight_master");

    // Spells
    RegisterSpellScript(spell_boralus_find_cyrus_objective_complete);
}
