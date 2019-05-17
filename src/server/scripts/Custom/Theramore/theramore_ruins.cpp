#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "Creature.h"
#include "TemporarySummon.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GridNotifiersImpl.h"
#include "theramore_ruins.h"

class npc_jaina_ruins : public CreatureScript
{
    public:
    npc_jaina_ruins() : CreatureScript("npc_jaina_ruins") {}

    struct npc_jaina_ruinsAI : public ScriptedAI
    {
        npc_jaina_ruinsAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            canSayIntro = false;
            canSayEnd = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (canSayIntro && canSayEnd)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();
            if (player && me->IsWithinDist(who, 6.f))
            {
                if (!canSayIntro && player->GetQuestStatus(QUEST_RETURN_TO_THERAMORE) == QUEST_STATUS_COMPLETE)
                {
                    Talk(SAY_IRIS_1);
                    me->SetWalk(true);
                    me->SetSheath(SHEATH_STATE_UNARMED);
                    me->SetFacingToObject(player);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                    canSayIntro = true;
                }

                if (!canSayEnd && player->GetQuestStatus(QUEST_DESTROY_THE_DESTROYER) == QUEST_STATUS_COMPLETE)
                {
                    canSayEnd = true;
                    events.ScheduleEvent(EVENT_IRIS_4, 3s);
                }
            }
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_RETURN_TO_THERAMORE:
                    SetData(EVENT_START_RETURN, 1U);
                    break;
            }
        }

        void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LIMIT_THE_NUKE:
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, EMOTE_ONESHOT_NONE);
                    me->RemoveAllAuras();
                    break;

                case QUEST_RETURN_TO_THERAMORE:
                    SetData(EVENT_START_IRIS, 1U);
                    break;
            }
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetSheath(SHEATH_STATE_UNARMED);

            switch (id)
            {
                case EVENT_START_RETURN:
                    events.ScheduleEvent(EVENT_RETURN_1, 2s);
                    break;

                case EVENT_START_IRIS:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    FillPlayersContainer();
                    events.ScheduleEvent(EVENT_IRIS_1, 2s);
                    break;

                default:
                    break;
            }
        }

        void Reset() override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
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
                    // Event - Return to Theramore
                    #pragma region THERAMORE

                    case EVENT_RETURN_1:
                        Talk(SAY_RETURN_1);
                        events.ScheduleEvent(EVENT_RETURN_2, 6s);
                        break;

                    case EVENT_RETURN_2:
                        me->GetMotionMaster()->MovePoint(0, -2674.73f, -4775.04f, 13.90f, true, 2.67f);
                        events.ScheduleEvent(EVENT_RETURN_3, 3s);
                        events.ScheduleEvent(EVENT_RETURN_4, 1s);
                        break;

                    case EVENT_RETURN_3:
                        Talk(SAY_RETURN_2);
                        break;

                    case EVENT_RETURN_4:
                        if (kalecgos = me->SummonCreature(NPC_KALECGOS_DRAGON, -2648.70f, -4653.49f, 80.96f, 0.f, TEMPSUMMON_MANUAL_DESPAWN))
                            kalecgos->GetMotionMaster()->MovePoint(0, -2687.44f, -4768.39f, 14.10f, false, 5.72f);
                        events.ScheduleEvent(EVENT_RETURN_5, 7s);
                        break;

                    case EVENT_RETURN_5:
                        kalecgos->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_LAND);
                        events.ScheduleEvent(EVENT_RETURN_6, 2s);
                        break;

                    case EVENT_RETURN_6:
                        kalecgos->DespawnOrUnsummon();
                        if (kalecgos = me->SummonCreature(NPC_KALECGOS, -2687.44f, -4768.39f, 13.90f, 5.72f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            kalecgos->SetWalk(true);
                            kalecgos->GetMotionMaster()->MovePoint(0, -2678.95f, -4772.81f, 14.08f);
                            kalecgos->AI()->Talk(SAY_RETURN_3);
                        }
                        events.ScheduleEvent(EVENT_RETURN_7, 4s);
                        break;

                    case EVENT_RETURN_7:
                        Talk(SAY_RETURN_4);
                        events.ScheduleEvent(EVENT_RETURN_8, 4s);
                        break;

                    case EVENT_RETURN_8:
                        kalecgos->AI()->Talk(SAY_RETURN_5);
                        events.ScheduleEvent(EVENT_RETURN_9, 1s);
                        break;

                    case EVENT_RETURN_9:
                        Talk(SAY_RETURN_6);
                        events.ScheduleEvent(EVENT_RETURN_10, 4s);
                        break;

                    case EVENT_RETURN_10:
                        kalecgos->AI()->Talk(SAY_RETURN_7);
                        events.ScheduleEvent(EVENT_RETURN_11, 6s);
                        break;

                    case EVENT_RETURN_11:
                        Talk(SAY_RETURN_8);
                        events.ScheduleEvent(EVENT_RETURN_12, 4s);
                        break;

                    case EVENT_RETURN_12:
                        if (Player * player = me->SelectNearestPlayer(50.f))
                        {
                            Talk(SAY_RETURN_9);
                            me->SetFacingToObject(player);
                        }
                        events.ScheduleEvent(EVENT_RETURN_13, 4s);
                        break;

                    case EVENT_RETURN_13:
                        me->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                        if (Player * player = me->SelectNearestPlayer(50.f))
                            player->CastSpell(player, SPELL_POWER_BALL_VISUAL);
                        events.ScheduleEvent(EVENT_RETURN_14, 1s);
                        break;

                    case EVENT_RETURN_14:
                        if (Player * player = me->SelectNearestPlayer(50.f))
                        {
                            player->CompleteQuest(QUEST_RETURN_TO_THERAMORE);
                            player->SetPhaseMask(1, true);
                            player->TeleportTo(725, -3755.96f, -4479.34f, 0.018f, 0.25f);
                        }
                        break;

                    #pragma endregion

                    // Event - Protect the artefact
                    #pragma region ARTEFACT

                    case EVENT_IRIS_1:
                        me->GetMotionMaster()->MovePoint(0, -3710.42f, -4468.33f, -20.67f, true, 0.02f);
                        events.ScheduleEvent(EVENT_IRIS_2, 8s);
                        break;

                    case EVENT_IRIS_2:
                        Talk(SAY_IRIS_2);
                        events.ScheduleEvent(EVENT_IRIS_3, 10s);
                        break;

                    case EVENT_IRIS_3:
                    {
                        Quest const* quest = sObjectMgr->GetQuestTemplate(QUEST_DESTROY_THE_DESTROYER);
                        for (Player* player : players)
                        {
                            if (player->CanAddQuest(quest, true))
                                player->AddQuestAndCheckCompletion(quest, me);
                        }

                        if (Creature * dummy = me->SummonCreature(NPC_INVISIBLE_STALKER, -3698.69f, -4467.94f, -20.87f, 3.55f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            me->CastSpell(dummy, SPELL_CANALISATION);
                            channelTarget = dummy;
                        }

                        break;
                    }

                    case EVENT_IRIS_4:
                    {
                        Quest const* destroyTheDestroyer = sObjectMgr->GetQuestTemplate(QUEST_DESTROY_THE_DESTROYER);
                        Quest const* protectTheArtefact = sObjectMgr->GetQuestTemplate(QUEST_PROTECT_THE_ARTEFACT);
                        for (Player* player : players)
                        {
                            player->RewardQuest(destroyTheDestroyer, 0, me);
                            if (player->CanAddQuest(protectTheArtefact, true))
                                player->AddQuestAndCheckCompletion(protectTheArtefact, me);
                        }

                        Talk(SAY_IRIS_3);
                        events.ScheduleEvent(EVENT_IRIS_5, 3s);
                        break;
                    }

                    case EVENT_IRIS_5:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                        me->CastSpell(me, 62849, true); 
                        for (uint8 i = 0; i < 2; ++i)
                            elementals[i] = me->SummonCreature(NPC_WATER_ELEMENTAL, ElementalsPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                        events.ScheduleEvent(EVENT_IRIS_6, 1s);
                        break;

                    case EVENT_IRIS_6:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_IRIS_7, 2s);
                        break;

                    case EVENT_IRIS_7:
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            elementals[i]->GetMotionMaster()->MovePoint(0, ElementalsPos[i + 2], false, ElementalsPos[i + 2].GetOrientation());
                            elementals[i]->SetHomePosition(ElementalsPos[i + 2]);
                        }
                        events.ScheduleEvent(EVENT_IRIS_8, 5s);
                        break;

                    case EVENT_IRIS_8:
                        for (int i = 0; i < 12; ++i)
                        {
                            uint32 entry = Soldiers[i].entry;
                            if (!entry)
                                entry = RAND(NPC_ROK_NAH_GRUNT, NPC_ROK_NAH_SOLDIER, NPC_ROK_NAH_HAG, NPC_ROK_NAH_FELCASTER, NPC_ROK_NAH_LOA_SINGER);

                            if (Creature * temp = me->SummonCreature(entry, Soldiers[i].position, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                temp->SetReactState(REACT_PASSIVE);

                                if (entry == NPC_WARLORD_ROK_NAH)
                                    warlord = temp;
                                else
                                    soldiers.push_back(temp);
                            }
                        }
                        events.ScheduleEvent(EVENT_IRIS_9, 2s);
                        break;

                    case EVENT_IRIS_9:
                        warlord->AI()->Talk(SAY_IRIS_4);
                        events.ScheduleEvent(EVENT_IRIS_10, 7s);
                        break;

                    case EVENT_IRIS_10:
                        Talk(SAY_IRIS_5);
                        events.ScheduleEvent(EVENT_IRIS_11, 9s);
                        break;

                    case EVENT_IRIS_11:
                        warlord->AI()->Talk(SAY_IRIS_6);
                        events.ScheduleEvent(EVENT_IRIS_12, 6s);
                        break;

                    case EVENT_IRIS_12:
                        Talk(SAY_IRIS_7);
                        events.ScheduleEvent(EVENT_IRIS_13, 9s);
                        break;

                    case EVENT_IRIS_13:
                        warlord->AI()->Talk(SAY_IRIS_8);
                        events.ScheduleEvent(EVENT_IRIS_14, 3s);
                        break;

                    case EVENT_IRIS_14:
                    {
                        warlord->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        warlord->SetReactState(REACT_AGGRESSIVE);
                        warlord->Attack(players[0], true);
                        warlord->GetMotionMaster()->MoveChase(players[0], 1.f);

                        for (Creature* soldier : soldiers)
                        {
                            soldier->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            soldier->SetReactState(REACT_AGGRESSIVE);
                            soldier->Attack(players[0], true);

                            if (soldier->GetPositionY() <= -4468.18f)
                            {
                                soldier->Attack(elementals[1], true);
                                soldier->GetMotionMaster()->MoveChase(elementals[1], 1.f);
                            }
                            else
                            {
                                soldier->Attack(elementals[0], true);
                                soldier->GetMotionMaster()->MoveChase(elementals[0], 1.f);
                            }
                        }

                        events.ScheduleEvent(EVENT_IRIS_15, 5s);
                        break;
                    }

                    case EVENT_IRIS_15:
                    {
                        if (warlord->GetHealthPct() <= 10.f || players[0]->GetHealthPct() <= 30.f)
                        {
                            players[0]->ResurrectPlayer(50.f);
                            players[0]->SetFullHealth();

                            warlord->RemoveAllAuras();
                            warlord->SetImmuneToAll(true);
                            
                            events.CancelEvent(EVENT_IRIS_15);
                            events.ScheduleEvent(EVENT_IRIS_16, 1s);
                        }
                        else
                            events.RescheduleEvent(EVENT_IRIS_15, 1s);
                        break;
                    }

                    case EVENT_IRIS_16:
                    {
                        warlord->CombatStop(true);
                        warlord->GetMotionMaster()->Clear();
                        warlord->GetMotionMaster()->MoveIdle();
                        warlord->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        warlord->SetReactState(REACT_PASSIVE);
                        warlord->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_KNEEL);

                        channelTarget->RemoveAllAuras();
                        me->RemoveAllAuras();

                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
                        me->CastSpell(me, SPELL_ICE_NOVA, args);

                        for (Creature* soldier : soldiers)
                        {
                            if (!soldier->IsAlive())
                                continue;

                            soldier->KillSelf();
                        }

                        for (Player* player : players)
                            player->CompleteQuest(QUEST_PROTECT_THE_ARTEFACT);

                        events.ScheduleEvent(EVENT_IRIS_17, 2s);
                        break;
                    }

                    case EVENT_IRIS_17:
                        if (GameObject * temp = GetClosestGameObjectWithEntry(me, 190561, 100))
                        {
                            float distanceToTravel = me->GetExactDist2d(temp->GetPosition()) - 1.5f;
                            float angle = me->GetAbsoluteAngle(temp);
                            float destx = me->GetPositionX() + distanceToTravel * cosf(angle);
                            float desty = me->GetPositionY() + distanceToTravel * sinf(angle);

                            me->GetMotionMaster()->MovePoint(0, destx, desty, temp->GetPositionZ());
                            mirror = temp;
                        }
                        events.ScheduleEvent(EVENT_IRIS_18, 7s);
                        break;

                    case EVENT_IRIS_18:
                        me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_KNEEL);
                        events.ScheduleEvent(EVENT_IRIS_19, 4s);
                        break;

                    case EVENT_IRIS_19:
                    {
                        mirror->Delete();
                        me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);
                        events.ScheduleEvent(EVENT_IRIS_20, 2s);
                        break;
                    }

                    case EVENT_IRIS_20:
                    {
                        float distanceToTravel = me->GetExactDist2d(warlord->GetPosition()) - 1.5f;
                        float angle = me->GetAbsoluteAngle(warlord);
                        float destx = me->GetPositionX() + distanceToTravel * cosf(angle);
                        float desty = me->GetPositionY() + distanceToTravel * sinf(angle);

                        me->GetMotionMaster()->MovePoint(0, destx, desty, warlord->GetPositionZ());

                        events.ScheduleEvent(EVENT_IRIS_21, ((distanceToTravel / me->GetSpeed(MOVE_WALK)) + 2) * IN_MILLISECONDS);
                        break;
                    }

                    case EVENT_IRIS_21:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                        warlord->KillSelf();
                        events.ScheduleEvent(EVENT_IRIS_22, 2s);
                        break;

                    case EVENT_IRIS_22:
                        Talk(SAY_IRIS_9);
                        me->SetFacingToObject(players[0]);
                        events.ScheduleEvent(EVENT_IRIS_23, 8s);
                        break;

                    case EVENT_IRIS_23:
                        Talk(SAY_IRIS_10);
                        events.ScheduleEvent(EVENT_IRIS_24, 8s);
                        break;

                    case EVENT_IRIS_24:
                        elementals[0]->DespawnOrUnsummon();
                        elementals[1]->DespawnOrUnsummon();
                        me->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                        events.ScheduleEvent(EVENT_IRIS_25, 1830);
                        break;

                    case EVENT_IRIS_25:
                        me->SetVisible(false);
                        me->SummonGameObject(195139, me->GetPosition(), QuaternionData(), 0);
                        break;

                    #pragma endregion

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        std::vector<Player*> players;
        std::vector<Creature*> soldiers;
        Creature* kalecgos;
        Creature* warlord;
        Creature* channelTarget;
        Creature* elementals[2];
        GameObject* mirror;
        bool canSayIntro, canSayEnd;

        void FillPlayersContainer()
        {
            if (!players.empty())
                players.clear();

            Map::PlayerList const& allPlayers = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = allPlayers.begin(); itr != allPlayers.end(); ++itr)
            {
                if (Player * player = itr->GetSource()->ToPlayer())
                    players.push_back(player);
            }
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_jaina_ruinsAI(creature);
    }
};

void AddSC_theramore_ruins()
{
    new npc_jaina_ruins();
}
