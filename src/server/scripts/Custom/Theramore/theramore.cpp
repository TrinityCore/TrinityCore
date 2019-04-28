#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "theramore.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Weather.h"
#include "GridNotifiersImpl.h"
#include <iostream>

class npc_jaina_theramore : public CreatureScript
{
    public:
    npc_jaina_theramore() : CreatureScript("npc_jaina_theramore") {}

    struct npc_jaina_theramoreAI : public ScriptedAI
    {
        npc_jaina_theramoreAI(Creature* creature) : ScriptedAI(creature)
        {
            sayInCombatTimer = 0;
            fireballTimer = 0;
            blizzardTimer = 0;
            playerShaker = false;
            firesCount = 0;
            warnNpcCount = 0;
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LOOKING_FOR_THE_ARTEFACT:
                    SetData(EVENT_START_CONVO, 0);
                    break;
            }
        }

        void QuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LOOKING_FOR_THE_ARTEFACT:
                    SetData(EVENT_END_CONVO, 0);
                    break;
            }
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetSheath(SHEATH_STATE_UNARMED);

            switch (id)
            {
                case EVENT_START_CONVO:
                {
                    kalecgos = me->FindNearestCreature(NPC_KALECGOS, 15.f);
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    kinndy->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                    events.SetPhase(PHASE_CONVO);
                    events.ScheduleEvent(EVENT_CONVO_1, 2s, 0, PHASE_CONVO);
                    break;
                }

                case EVENT_END_CONVO:
                    events.ScheduleEvent(EVENT_CONVO_25, 2s, 0, PHASE_CONVO);
                    break;

                case EVENT_START_WARN:
                {
                    events.SetPhase(PHASE_WARN);
                    events.ScheduleEvent(EVENT_WARN_1, 2s, 0, PHASE_WARN);
                    break;
                }

                case EVENT_START_BATTLE:
                {
                    tervosh = me->FindNearestCreature(NPC_ARCHMAGE_TERVOSH, 15.f);
                    kinndy = me->FindNearestCreature(NPC_KINNDY_SPARKSHINE, 15.f);
                    aden = me->FindNearestCreature(NPC_LIEUTENANT_ADEN, 2000.f);

                    kalecgos = me->FindNearestCreature(NPC_KALECGOS, 15.f);
                    if (kalecgos)
                        kalecgos->SetVisible(false);

                    // First get all creatures.
                    Trinity::AllFriendlyCreaturesInGrid creature_check(me);
                    Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(me, civils, creature_check);
                    Cell::VisitGridObjects(me, creature_searcher, 2000.f);

                    events.SetPhase(PHASE_PRE_BATTLE);
                    events.ScheduleEvent(EVENT_SHAKER, 2s, 0, PHASE_PRE_BATTLE);
                    events.ScheduleEvent(EVENT_PRE_BATTLE_1, 2s, 0, PHASE_PRE_BATTLE);
                    break;
                }
            }
        }

        void Reset() override
        {
            me->RemoveAllAuras();

            sayInCombatTimer = .5f;
            fireballTimer = .5f;
            blizzardTimer = urand(3500, 5000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Event - Convo
                    #pragma region EVENT_CONVO

                    case EVENT_CONVO_1:
                        Talk(SAY_CONVO_1);
                        events.ScheduleEvent(EVENT_CONVO_2, 11s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_2:
                        kinndy->AI()->Talk(SAY_CONVO_2);
                        events.ScheduleEvent(EVENT_CONVO_3, 10s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_3:
                        Talk(SAY_CONVO_3);
                        events.ScheduleEvent(EVENT_CONVO_4, 12s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_4:
                        kinndy->AI()->Talk(SAY_CONVO_4);
                        events.ScheduleEvent(EVENT_CONVO_5, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_5:
                        Talk(SAY_CONVO_5);
                        events.ScheduleEvent(EVENT_CONVO_6, 8s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_6:
                        tervosh->AI()->Talk(SAY_CONVO_6);
                        events.ScheduleEvent(EVENT_CONVO_7, 8s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_7:
                        kalecgos->AI()->Talk(SAY_CONVO_7);
                        events.ScheduleEvent(EVENT_CONVO_8, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_8:
                        kalecgos->AI()->Talk(SAY_CONVO_8);
                        events.ScheduleEvent(EVENT_CONVO_9, 9s, 0, PHASE_CONVO);
                        events.ScheduleEvent(EVENT_CONVO_10, 10s, 0, PHASE_CONVO);
                        events.ScheduleEvent(EVENT_CONVO_11, 14s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_9:
                        kinndy->AI()->Talk(SAY_CONVO_9_BIS);
                        break;

                    case EVENT_CONVO_10:
                        tervosh->AI()->Talk(SAY_CONVO_9);
                        break;

                    case EVENT_CONVO_11:
                        Talk(SAY_CONVO_10);
                        events.ScheduleEvent(EVENT_CONVO_12, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_12:
                        kalecgos->AI()->Talk(SAY_CONVO_11);
                        events.ScheduleEvent(EVENT_CONVO_13, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_13:
                        Talk(SAY_CONVO_12);
                        events.ScheduleEvent(EVENT_CONVO_14, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_14:
                       kinndy->AI()->Talk(SAY_CONVO_13);
                        events.ScheduleEvent(EVENT_CONVO_15, 6s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_15:
                        kalecgos->AI()->Talk(SAY_CONVO_14);
                        events.ScheduleEvent(EVENT_CONVO_16, 7s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_16:
                        Talk(SAY_CONVO_15);
                        events.ScheduleEvent(EVENT_CONVO_17, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_17:
                        kalecgos->AI()->Talk(SAY_CONVO_16);
                        events.ScheduleEvent(EVENT_CONVO_18, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_18:
                        kalecgos->AI()->Talk(SAY_CONVO_17);
                        kalecgos->SetWalk(true);
                        events.ScheduleEvent(EVENT_CONVO_19, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_19:
                        kalecgos->GetMotionMaster()->MovePoint(1, -3746.48f, -4437.71f, 30.55f, false);
                        events.ScheduleEvent(EVENT_CONVO_20, 2s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_20:
                        kalecgos->GetMotionMaster()->MovePoint(2, -3717.99f, -4411.30f, 24.37f, false);
                        events.ScheduleEvent(EVENT_CONVO_21, 18s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_21:
                        kalecgos->SetVisible(false);
                        kalecgos = me->SummonCreature(NPC_KALECGOS_DRAGON, kalecgos->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                        kalecgos->SetWalk(false);
                        kalecgos->SetDisableGravity(true);
                        kalecgos->SetFacingTo(5.99f);
                        events.ScheduleEvent(EVENT_CONVO_22, 2s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_22:
                        initTervosh = tervosh->GetPosition();
                        initKinndy = kinndy->GetPosition();
                        kalecgos->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        kalecgos->UpdatePosition({ kalecgos->GetPositionX(), kalecgos->GetPositionY(), kalecgos->GetPositionZ() + 10.0f, me->GetOrientation() });
                        events.ScheduleEvent(EVENT_CONVO_23, 4s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_23:
                        kalecgos->GetMotionMaster()->MovePoint(4, -3546.51f, -4352.54f, 74.02f, false);
                        tervosh->SetWalk(true);
                        kinndy->SetWalk(true);
                        tervosh->GetMotionMaster()->MovePoint(0, -3762.35f, -4453.38f, 37.99f);
                        kinndy->GetMotionMaster()->MovePoint(0, -3764.64f, -4438.99f, 35.21f, true, 0.67f);
                        events.ScheduleEvent(EVENT_CONVO_24, 10s, 0, PHASE_CONVO);
                        break;

                    case EVENT_CONVO_24:
                    {
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player * player = itr->GetSource()->ToPlayer())
                                player->AreaExploredOrEventHappens(QUEST_LOOKING_FOR_THE_ARTEFACT);
                        }

                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        kalecgos->DespawnOrUnsummon();
                        tervosh->SetVisible(false);
                        break;
                    }

                    case EVENT_CONVO_25:
                    {
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        if (GameObject * chair = me->FindNearestGameObject(GOB_LOW_CHAIR, 20.f))
                        {
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(0, -3759.73f, -4446.66f, 30.55f, true, 0.38f);
                        }
                        events.ScheduleEvent(EVENT_CONVO_26, 15s, 0, PHASE_CONVO);
                        break;
                    }

                    case EVENT_CONVO_26:
                        SetData(EVENT_START_WARN, 0);
                        break;

                    #pragma endregion

                    // Event - Warn
                    #pragma region EVENT_WARN

                    case EVENT_WARN_1:
                    {
                        if (warnNpcCount >= 4)
                        {
                            events.ScheduleEvent(EVENT_WARN_2, 3s, 0, PHASE_WARN);
                            break;
                        }

                        uint32 entry = (uint32)WarnLocation[warnNpcCount][0];
                        if (Creature * c = me->SummonCreature(entry, WarnLocation[warnNpcCount][1], WarnLocation[warnNpcCount][2], WarnLocation[warnNpcCount][3], WarnLocation[warnNpcCount][4], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            switch (entry)
                            {
                                case NPC_PAINED:
                                    c->SetSheath(SHEATH_STATE_UNARMED);
                                    pained = c;
                                    break;

                                case NPC_MYSTERIOUS_TAUREN:
                                    perith = c;
                                    break;

                                case NPC_ZEALOUS_THERAMORE_GUARD:
                                    zealous = c;
                                    break;

                                case NPC_THERAMORE_GUARD:
                                    guard = c;
                                    break;
                            }

                            c->SetWalk(true);
                            c->GetMotionMaster()->MovePoint(0, WarnDestination[warnNpcCount], false, WarnDestination[warnNpcCount].GetOrientation());

                            warnNpcCount++;

                            events.ScheduleEvent(EVENT_WARN_1, 1s, 0, PHASE_WARN);
                        }

                        break;
                    }

                    case EVENT_WARN_2:
                        pained->AI()->Talk(SAY_WARN_1);
                        pained->SetFacingTo(3.64f);
                        events.ScheduleEvent(EVENT_WARN_3, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_3:
                        Talk(SAY_WARN_2);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->GetMotionMaster()->MovePoint(0, -3750.87f, -4439.72f, 30.55f, true, 0.58f);
                        events.ScheduleEvent(EVENT_WARN_4, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_4:
                        pained->AI()->Talk(SAY_WARN_3);
                        events.ScheduleEvent(EVENT_WARN_5, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_5:
                        pained->AI()->Talk(SAY_WARN_4);
                        events.ScheduleEvent(EVENT_WARN_6, 7s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_6:
                        Talk(SAY_WARN_5);
                        events.ScheduleEvent(EVENT_WARN_7, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_7:
                        pained->AI()->Talk(SAY_WARN_6);
                        events.ScheduleEvent(EVENT_WARN_8, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_8:
                        pained->GetMotionMaster()->MoveCloserAndStop(0, me, 1.0f);
                        events.ScheduleEvent(EVENT_WARN_9, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_9:
                        pained->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_10, 1s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_10:
                        pained->AI()->Talk(SAY_WARN_7);
                        pained->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_WARN_11, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_11:
                        pained->SetTarget(ObjectGuid::Empty);
                        pained->GetMotionMaster()->MovePoint(0, -3746.31f, -4433.00f, 30.55f, false, 4.23f);
                        events.ScheduleEvent(EVENT_WARN_12, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_12:
                        Talk(SAY_WARN_8);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_13, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_13:
                        Talk(SAY_WARN_9);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->SetFacingToObject(perith);
                        events.ScheduleEvent(EVENT_WARN_14, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_14:
                        pained->AI()->Talk(SAY_WARN_10);
                        perith->GetMotionMaster()->MovePoint(0, -3747.11f, -4438.24f, 30.55f, false, 3.94f);
                        events.ScheduleEvent(EVENT_WARN_15, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_15:
                        Talk(SAY_WARN_11);
                        events.ScheduleEvent(EVENT_WARN_16, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_16:
                        me->SetFacingToObject(zealous);
                        perith->SetFacingToObject(me);
                        zealous->AI()->Talk(0);
                        zealous->GetMotionMaster()->MovePoint(0, -3743.01f, -4433.78f, 30.55f, false, 3.93f);
                        events.ScheduleEvent(EVENT_WARN_17, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_17:
                        Talk(SAY_WARN_13);
                        events.ScheduleEvent(EVENT_WARN_18, 7s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_18:
                        zealous->GetMotionMaster()->MovePoint(0, -3731.17f, -4420.68f, 30.44f, false);
                        guard->GetMotionMaster()->MovePoint(0, -3729.32f, -4422.18f, 30.44f, false);
                        me->SetFacingToObject(perith);
                        perith->UpdateEntry(NPC_PERITH_STORMHOOF);
                        perith->AI()->Talk(SAY_WARN_14);
                        events.ScheduleEvent(EVENT_WARN_19, 6s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_19:
                        Talk(SAY_WARN_15);
                        zealous->DespawnOrUnsummon();
                        guard->DespawnOrUnsummon();
                        events.ScheduleEvent(EVENT_WARN_20, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_20:
                        perith->AI()->Talk(SAY_WARN_16);
                        events.ScheduleEvent(EVENT_WARN_21, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_21:
                        perith->AI()->Talk(SAY_WARN_17);
                        events.ScheduleEvent(EVENT_WARN_22, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_22:
                        perith->AI()->Talk(SAY_WARN_18);
                        events.ScheduleEvent(EVENT_WARN_23, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_23:
                        Talk(SAY_WARN_19);
                        events.ScheduleEvent(EVENT_WARN_24, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_24:
                        perith->AI()->Talk(SAY_WARN_20);
                        events.ScheduleEvent(EVENT_WARN_25, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_25:
                        Talk(SAY_WARN_21);
                        events.ScheduleEvent(EVENT_WARN_26, 2s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_26:
                        perith->AI()->Talk(SAY_WARN_22);
                        events.ScheduleEvent(EVENT_WARN_27, 12s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_27:
                        perith->AI()->Talk(SAY_WARN_23);
                        events.ScheduleEvent(EVENT_WARN_28, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_28:
                        Talk(SAY_WARN_24);
                        events.ScheduleEvent(EVENT_WARN_29, 10s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_29:
                        perith->AI()->Talk(SAY_WARN_25);
                        events.ScheduleEvent(EVENT_WARN_30, 11s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_30:
                        Talk(SAY_WARN_26);
                        me->SetWalk(true);
                        events.ScheduleEvent(EVENT_WARN_31, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_31:
                        me->GetMotionMaster()->MovePoint(0, -3756.04f, -4437.71f, 30.55f, false, 2.08f);
                        events.ScheduleEvent(EVENT_WARN_32, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_32:
                        Talk(SAY_WARN_27);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_USE_STANDING);
                        events.ScheduleEvent(EVENT_WARN_33, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_33:
                        Talk(SAY_WARN_28);
                        me->GetMotionMaster()->MovePoint(0, -3750.87f, -4439.72f, 30.55f, false, 0.97f);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_WARN_34, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_34:
                        me->SetFacingToObject(perith);
                        perith->AI()->Talk(SAY_WARN_29);
                        events.ScheduleEvent(EVENT_WARN_35, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_35:
                        perith->AI()->Talk(SAY_WARN_30);
                        events.ScheduleEvent(EVENT_WARN_36, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_36:
                        Talk(SAY_WARN_31);
                        events.ScheduleEvent(EVENT_WARN_37, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_37:
                        perith->AI()->Talk(SAY_WARN_32);
                        events.ScheduleEvent(EVENT_WARN_38, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_38:
                        Talk(SAY_WARN_33);
                        events.ScheduleEvent(EVENT_WARN_39, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_39:
                        perith->AI()->Talk(SAY_WARN_34);
                        events.ScheduleEvent(EVENT_WARN_40, 4s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_40:
                        perith->GetMotionMaster()->MovePoint(0, -3731.33f, -4422.18f, 30.47f);
                        events.ScheduleEvent(EVENT_WARN_41, 8s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_41:
                        perith->DespawnOrUnsummon();
                        me->SetFacingToObject(pained);
                        Talk(SAY_WARN_35);
                        events.ScheduleEvent(EVENT_WARN_42, 5s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_42:
                        pained->GetMotionMaster()->MoveCloserAndStop(0, me, 5.0f);
                        pained->AI()->Talk(SAY_WARN_36);
                        events.ScheduleEvent(EVENT_WARN_43, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_43:
                        Talk(SAY_WARN_37);
                        events.ScheduleEvent(EVENT_WARN_44, 3s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_44:
                        pained->GetMotionMaster()->MoveCloserAndStop(0, tervosh, 5.0f);
                        events.ScheduleEvent(EVENT_WARN_45, 16s, 0, PHASE_WARN);
                        break;

                    case EVENT_WARN_45:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFacingTo(6.26f);
                        tervosh->SetVisible(true);
                        tervosh->GetMotionMaster()->MovePoint(0, initTervosh, true, initTervosh.GetOrientation());
                        kinndy->GetMotionMaster()->MovePoint(0, initKinndy, true, initKinndy.GetOrientation());
                        kinndy->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;

                    #pragma endregion

                    // Event - Pre Battle
                    #pragma region EVENT_PRE_BATTLE

                    case EVENT_SHAKER:
                    {
                        if (!playerShaker)
                        {
                            Map::PlayerList const& players = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                if (Player * player = itr->GetSource()->ToPlayer())
                                    player->CastSpell(player, 42910);
                            }

                            aden->AI()->Talk(SAY_EVENT_SHAKER);

                            std::list<GameObject*> theramoreGates;
                            GetGameObjectListWithEntryInGrid(theramoreGates, me, GOB_THERAMORE_GATE, 2000.f);
                            for (GameObject* gate : theramoreGates)
                                gate->UseDoorOrButton();

                            playerShaker = true;
                        }

                        uint32 sound = RAND(14340, 14341, 14338);
                        me->PlayDirectSound(sound);
                        events.ScheduleEvent(EVENT_SHAKER, urand(500, 1000), 0, PHASE_CONVO);
                        break;
                    }

                    case EVENT_PRE_BATTLE_1:
                    {
                        for (int i = 0; i < 35; ++i)
                        {
                            me->SummonGameObject(GOB_FIRE_THERAMORE, FireLocation[i][0], FireLocation[i][1], FireLocation[i][2], FireLocation[i][3], QuaternionData(), 0);
                            if (Creature * fx = me->SummonCreature(NPC_INVISIBLE_STALKER, FireLocation[i][0], FireLocation[i][1], FireLocation[i][2], 0.f, TEMPSUMMON_TIMED_DESPAWN, 5000))
                                fx->CastSpell(fx, 70444);
                        }

                        for (Creature* civil : civils)
                        {
                            switch (civil->GetEntry())
                            {
                                case 100025:
                                    civil->SetVisible(false);
                                    break;

                                case 100012:
                                    civil->StopMoving();
                                    civil->GetMotionMaster()->MoveIdle();
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                                    break;

                                case 34776:
                                    if (civil->GetSpawnId() == 1022775)
                                    {
                                        civil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        civil->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                                        civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                                        civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM);
                                    }
                                    break;

                                case 4941:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    break;

                                case 4899:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3698.03f, -4353.46f, 11.45f, true, 1.78f);
                                    break;

                                case 4900:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3699.53f, -4356.35f, 11.41f, true, 1.78f);
                                    break;

                                case 4898:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3700.21f, -4351.08f, 11.41f, true, 1.86f);
                                    break;

                                case 4897:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3824.76f, -4443.74f, 12.66f, true, 3.24f);
                                    break;

                                case 11052:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                                    civil->GetMotionMaster()->MovePoint(0, -3826.36f, -4441.66f, 12.25f, true, 3.51f);
                                    break;

                                case 5405:
                                case 4888:
                                case 4885:
                                case 10047:
                                case 12375:
                                case 12376:
                                case 24005:
                                case 24006:
                                case 24007:
                                    civil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    civil->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                                    civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                                    civil->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM);
                                    break;

                                case 4886:
                                    civil->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                                    if (Creature * c = civil->FindNearestCreature(4888, 18.f))
                                    {
                                        civil->GetMotionMaster()->MoveFollow(c, 1.0f, 0.f);
                                        civil->SetTarget(c->GetGUID());
                                    }
                                    break;
                            }
                        }

                        me->PlayDirectSound(15003);
                        me->GetMap()->SetZoneWeather(ZONE_THERAMORE_ISLE, WEATHER_STATE_FOG, 1.0f);
                        aden->NearTeleportTo(-3712.64f, -4396.56f, 19.19f, 4.39f);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_2, 1s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_2:
                        Talk(SAY_PRE_BATTLE_1);
                        me->GetMotionMaster()->MovePoint(0, -3723.35f, -4414.69f, 26.38f);
                        tervosh->GetMotionMaster()->MovePoint(0, -3730.29f, -4423.91f, 30.48f);
                        kinndy->GetMotionMaster()->MovePoint(0, -3732.69f, -4421.54f, 30.48f);
                        aden->GetMotionMaster()->MovePoint(0, -3718.83f, -4409.31f, 24.10f);
                        events.CancelEvent(EVENT_SHAKER);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_3, 3s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_3:
                        aden->AI()->Talk(SAY_PRE_BATTLE_2);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_4, 6s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_4:
                        Talk(SAY_PRE_BATTLE_3);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_5, 4s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_5:
                    {
                        if (GameObject * portal = me->SummonGameObject(201797, -3712.38f, -4420.67f, 25.67f, 0.f, QuaternionData(), 5))
                        {
                            portalGUID = portal->GetGUID();
                            me->SetFacingToObject(portal);
                        }
                        events.ScheduleEvent(EVENT_PRE_BATTLE_6, 800, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_6:
                    {
                        for (uint8 i = 0; i < 6; ++i)
                        {
                            uint32 entry = (uint32)ArchmagesLocation[i][0];

                            if (Creature * c = me->SummonCreature(entry,
                                ArchmagesLocation[i][1], ArchmagesLocation[i][2], ArchmagesLocation[i][3], ArchmagesLocation[i][4],
                                TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                switch (entry)
                                {
                                    case NPC_RHONIN:
                                        rhonin = c;
                                        c->AI()->Talk(SAY_PRE_BATTLE_4);
                                        me->SetFacingToObject(c);
                                        kinndy->SetFacingToObject(c);
                                        tervosh->SetFacingToObject(c);
                                        aden->SetFacingToObject(c);
                                        break;

                                    case NPC_THALEN_SONGWEAVER:
                                        thalen = c;
                                        break;

                                    case NPC_VEREESA_WINDRUNNER:
                                        vereesa = c;
                                        break;

                                    default:
                                        break;
                                }

                                archmagesGUID[i] = c->GetGUID();
                                c->SetSheath(SHEATH_STATE_UNARMED);
                                c->CastSpell(c, SPELL_TELEPORT);
                                c->SetTarget(me->GetGUID());
                            }
                        }
                        events.ScheduleEvent(EVENT_PRE_BATTLE_7, 3s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_7:
                        Talk(SAY_PRE_BATTLE_5);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_8, 11s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_8:
                        Talk(SAY_PRE_BATTLE_6);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_9, 9s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_9:
                        thalen->AI()->Talk(SAY_PRE_BATTLE_7);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_10, 7s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_10:
                        Talk(SAY_PRE_BATTLE_8);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_11, 3s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_11:
                        Talk(SAY_PRE_BATTLE_9);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_12, 7s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_12:
                        rhonin->AI()->Talk(SAY_PRE_BATTLE_10);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_13, 2s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_13:
                        Talk(SAY_PRE_BATTLE_11);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_14, 5s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_14:
                        vereesa->AI()->Talk(SAY_PRE_BATTLE_12);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_15, 5s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_15:
                        Talk(SAY_PRE_BATTLE_13);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_16, 8s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_16:
                        if (Player * player = me->SelectNearestPlayer(50.f))
                        {
                            Talk(SAY_PRE_BATTLE_14);
                            me->SetFacingToObject(player);
                        }
                        events.ScheduleEvent(EVENT_PRE_BATTLE_17, 5s, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_17:
                        me->CastSpell(me, 7077);
                        events.ScheduleEvent(EVENT_PRE_BATTLE_18, 1400, 0, PHASE_PRE_BATTLE);
                        break;

                    case EVENT_PRE_BATTLE_18:
                    {
                        DoCastSelf(SPELL_TELEPORT);

                        kinndy->CastSpell(kinndy, SPELL_TELEPORT);
                        tervosh->CastSpell(tervosh, SPELL_TELEPORT);
                        aden->CastSpell(aden, SPELL_TELEPORT);

                        for (uint32 i = 0; i < 6; ++i)
                        {
                            if (Creature * c = ObjectAccessor::GetCreature(*me, archmagesGUID[i]))
                                c->CastSpell(c, SPELL_TELEPORT);
                        }

                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player * player = itr->GetSource()->ToPlayer())
                                player->CastSpell(player, SPELL_TELEPORT);
                        }

                        events.ScheduleEvent(EVENT_PRE_BATTLE_19, 1500, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_19:
                    {
                        me->SetSheath(SHEATH_STATE_MELEE);

                        Relocate(aden, -3669.01f, -4381.60f, 9.56f, 0.69f);
                        Relocate(me, -3658.39f, -4372.87f, 9.35f, 0.69f);
                        Relocate(kinndy, -3666.15f, -4519.95f, 10.03f, 2.44f);
                        Relocate(tervosh, -3808.72f, -4541.01f, 10.68f, 3.09f);

                        for (int i = 0; i < 6; ++i)
                        {
                            if (Creature * c = ObjectAccessor::GetCreature(*me, archmagesGUID[i]))
                            {
                                c->SetSheath(SHEATH_STATE_MELEE);
                                c->SetTarget(ObjectGuid::Empty);
                                Relocate(c, ArchmagesRelocate[i][0], ArchmagesRelocate[i][1], ArchmagesRelocate[i][2], ArchmagesRelocate[i][3]);

                                uint32 entry = c->GetEntry();
                                switch (entry)
                                {
                                    case NPC_AMARA_LEESON:
                                    case NPC_THALEN_SONGWEAVER:
                                        c->CastSpell(c, 39550);
                                        break;

                                    default:
                                        break;
                                }
                            }
                        }

                        if (Creature * c = me->SummonCreature(NPC_INVISIBLE_STALKER, -3646.48f, -4362.23f, 9.57f, 0.70f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            c->AddAura(70573, c);
                            c->SetObjectScale(3.0f);
                        }

                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player * player = itr->GetSource()->ToPlayer())
                            {
                                float angle = rand_norm() * 2 * M_PI;
                                float dist = urand(1, 4);
                                player->NearTeleportTo(-3661.96f + cos(angle) * dist, -4374.06f + sin(angle) * dist, 9.35f, 0.72f);
                            }
                        }

                        events.ScheduleEvent(EVENT_PRE_BATTLE_20, 4s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_20:
                    {
                        //if (Creature * waves = me->SummonCreature(NPC_WAVES_INVOKER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN))
                            //waves->AI()->SetData(1, 1);

                        me->GetGameObjectListWithEntryInGrid(fires, GOB_FIRE_THERAMORE, 18.f);
                        firesCount = fires.size();
                        events.ScheduleEvent(EVENT_PRE_BATTLE_21, 1s, 0, PHASE_PRE_BATTLE);
                        break;
                    }

                    case EVENT_PRE_BATTLE_21:
                    {
                        me->SetFacingTo(0.70f);

                        if (fires.empty() || firesCount <= 0)
                            break;

                        if (GameObject * fire = fires.at(firesCount - 1))
                        {
                            if (Creature * c = me->SummonCreature(NPC_INVISIBLE_STALKER, *fire, TEMPSUMMON_DEAD_DESPAWN))
                            {
                                c->SetFaction(14);
                                c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                c->SetReactState(REACT_PASSIVE);
                                c->CastSpell(c, 62849);
                                me->SetFacingToObject(c);
                                DoCast(c, 54261);
                                fire->Delete();
                                firesCount--;
                                events.ScheduleEvent(EVENT_PRE_BATTLE_21, 2s, 0, PHASE_PRE_BATTLE);
                            }
                        }

                        break;
                    }

                    #pragma endregion

                    default:
                        break;
                }
            }

            // Combat
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // Blizzard
            if (blizzardTimer <= diff)
            {
                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_BLIZZARD);
                blizzardTimer = urand(6000, 15000);
            }
            else blizzardTimer -= diff;

            // Boule de Feu
            if (fireballTimer <= diff)
            {
                DoCastVictim(SPELL_FIREBALL);
                fireballTimer = urand(3600, 5000);
            }
            else fireballTimer -= diff;

            // Parle en combat
            if (sayInCombatTimer <= diff)
            {
                me->PlayDirectSound(28140);
                sayInCombatTimer = urand(24000, 65000);
            }
            else sayInCombatTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:
        Creature* kalecgos;
        Creature* tervosh;
        Creature* kinndy;
        Creature* aden;
        Creature* thalen;
        Creature* rhonin;
        Creature* vereesa;
        Creature* pained;
        Creature* perith;
        Creature* zealous;
        Creature* guard;
        ObjectGuid archmagesGUID[6];
        ObjectGuid portalGUID;
        EventMap events;
        std::vector<GameObject*> fires;
        std::list<Creature*> civils;
        bool playerShaker;
        uint8 firesCount;
        uint8 warnNpcCount;
        Position initTervosh;
        Position initKinndy;

        uint32 sayInCombatTimer, fireballTimer, blizzardTimer;

        void Relocate(Creature* c, float x, float y, float z, float orientation)
        {
            const Position pos{ x, y, z, orientation };
            c->NearTeleportTo(pos);
            c->SetHomePosition(pos);
            c->Respawn();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_jaina_theramoreAI(creature);
    }
};

void AddSC_theramore()
{
    new npc_jaina_theramore();
}
