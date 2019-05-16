#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "Player.h"
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
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_RETURN_TO_THERAMORE:
                    SetData(EVENT_START_RETURN, 1U);
                    break;

                case QUEST_PROTECT_THE_ARTEFACT:
                    SetData(EVENT_START_IRIS, 1U);
                    break;
            }
        }

        void QuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_LIMIT_THE_NUKE:
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, EMOTE_ONESHOT_NONE);
                    me->RemoveAllAuras();
                    break;

                case QUEST_RETURN_TO_THERAMORE:
                    Talk(SAY_IRIS_1);
                    FillPlayersContainer();
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
                    me->SetWalk(true);
                    events.ScheduleEvent(EVENT_IRIS_1, 1s);
                    break;

                default:
                    break;
            }
        }

        void Reset() override
        {
			
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
                        Talk(SAY_IRIS_2);
                        events.ScheduleEvent(EVENT_IRIS_2, 7s);
                        break;

                    case EVENT_IRIS_2:
                        Talk(SAY_IRIS_3);
                        events.ScheduleEvent(EVENT_IRIS_3, 3s);
                        break;

                    case EVENT_IRIS_3:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                        me->CastSpell(me, 62849, true); 
                        for (uint8 i = 0; i < 2; ++i)
                            me->SummonCreature(NPC_WATER_ELEMENTAL, ElementalsPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                        events.ScheduleEvent(EVENT_IRIS_4, 1s);
                        break;

                    case EVENT_IRIS_4:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        events.ScheduleEvent(EVENT_IRIS_5, 2s);
                        break;

                    case EVENT_IRIS_5:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        if (Creature * dummy = me->SummonCreature(NPC_INVISIBLE_STALKER, -3695.10f, -4466.88f, -21.0f, 3.442f, TEMPSUMMON_MANUAL_DESPAWN))
                            me->CastSpell(dummy, SPELL_CANALISATION);
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
        Creature* kalecgos;

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
