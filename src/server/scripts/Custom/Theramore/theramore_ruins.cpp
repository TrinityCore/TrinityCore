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
            if (me->GetMapId() != 725)
                return;

            if (canSayIntro && canSayEnd)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();
            if (player && me->IsWithinDist(who, 6.f))
            {
                if (!canSayIntro && player->GetQuestStatus(QUEST_RETURN_TO_THERAMORE) == QUEST_STATUS_COMPLETE)
                {
                    canSayIntro = true;
                    SetData(EVENT_START_IRIS, 1U);
                }

                if (!canSayEnd && player->GetQuestStatus(QUEST_DESTROY_THE_DESTROYER) == QUEST_STATUS_COMPLETE)
                {
                    canSayEnd = true;
                    events.ScheduleEvent(EVENT_IRIS_4, 1s);
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
                    me->SetStandState(UNIT_STAND_STATE_STAND);
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
                    Talk(SAY_IRIS_1);
                    kinndy = GetClosestCreatureWithEntry(me, NPC_KINNDY_SPARKSHINE, 5.f);
                    arcanic = GetClosestCreatureWithEntry(me, NPC_ARCANIC_FORM, 5.f);
                    FillPlayersContainer();
                    events.ScheduleEvent(EVENT_IRIS_1, 5s);
                    break;

                default:
                    break;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, 0s);
            events.ScheduleEvent(CASTING_FROSTBOLT, 3s);
            events.ScheduleEvent(CASTING_FROST_RUNE_1, 20s);

            //events.ScheduleEvent(CASTING_ARCANIC_VOLLEY, 0s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                DoStartMovement(who, 20.f);
                SetCombatMovement(false);
            }
        }

        void Reset() override
        {
            if (me->GetMapId() != 1)
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            // Combat
            if (!UpdateVictim())
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Event - Return to Theramore
                        #pragma region THERAMORE

                        case EVENT_RETURN_1:
                            me->GetMotionMaster()->MovePoint(0, -2690.53f, -4765.79f, 13.76f, true, 2.03f);
                            events.ScheduleEvent(EVENT_RETURN_2, 6s);
                            break;

                        case EVENT_RETURN_2:
                            if (Creature * portal = me->SummonCreature(NPC_INVISIBLE_STALKER, -2678.14f, -4774.18f, 14.16f, 2.55f, TEMPSUMMON_TIMED_DESPAWN, 20000))
                            {
                                portal->AddAura(SPELL_OPENED_PORTAL, portal);
                                if (kalecgos = portal->SummonCreature(NPC_KALECGOS, -2678.14f, -4774.18f, 14.16f, 2.55f, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    kalecgos->SetWalk(true);
                                    kalecgos->GetMotionMaster()->MovePoint(0, -2685.95f, -4768.93f, 13.94f, true, 2.55f);
                                }
                            }
                            events.ScheduleEvent(EVENT_RETURN_3, 4s);
                            break;

                        case EVENT_RETURN_3:
                            me->SetFacingToObject(kalecgos);
                            kalecgos->AI()->Talk(SAY_RETURN_1);
                            events.ScheduleEvent(EVENT_RETURN_4, 1s);
                            break;

                        case EVENT_RETURN_4:
                            Talk(SAY_RETURN_2);
                            events.ScheduleEvent(EVENT_RETURN_5, 7s);
                            break;

                        case EVENT_RETURN_5:
                            Talk(SAY_RETURN_3);
                            events.ScheduleEvent(EVENT_RETURN_6, 11s);
                            break;

                        case EVENT_RETURN_6:
                            kalecgos->AI()->Talk(SAY_RETURN_4);
                            events.ScheduleEvent(EVENT_RETURN_7, 15s);
                            break;

                        case EVENT_RETURN_7:
                            Talk(SAY_RETURN_5);
                            events.ScheduleEvent(EVENT_RETURN_8, 6s);
                            break;

                        case EVENT_RETURN_8:
                            kalecgos->AI()->Talk(SAY_RETURN_6);
                            events.ScheduleEvent(EVENT_RETURN_9, 4s);
                            break;

                        case EVENT_RETURN_9:
                            Talk(SAY_RETURN_7);
                            events.ScheduleEvent(EVENT_RETURN_10, 15s);
                            break;

                        case EVENT_RETURN_10:
                            kalecgos->AI()->Talk(SAY_RETURN_8);
                            events.ScheduleEvent(EVENT_RETURN_11, 5s);
                            break;

                        case EVENT_RETURN_11:
                            Talk(SAY_RETURN_9);
                            events.ScheduleEvent(EVENT_RETURN_12, 4s);
                            break;

                        case EVENT_RETURN_12:
                            kalecgos->AI()->Talk(SAY_RETURN_10);
                            events.ScheduleEvent(EVENT_RETURN_13, 7s);
                            break;

                        case EVENT_RETURN_13:
                            kalecgos->AI()->Talk(SAY_RETURN_11);
                            events.ScheduleEvent(EVENT_RETURN_14, 15s);
                            break;

                        case EVENT_RETURN_14:
                            Talk(SAY_RETURN_12);
                            events.ScheduleEvent(EVENT_RETURN_15, 14s);
                            break;

                        case EVENT_RETURN_15:
                            me->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                            events.ScheduleEvent(EVENT_RETURN_16, 1s);
                            break;

                        case EVENT_RETURN_16:
                            me->SetVisible(false);
                            if (Player * player = me->SelectNearestPlayer(50.f))
                            {
                                kalecgos->AI()->Talk(SAY_RETURN_13);
                                kalecgos->SetFacingToObject(player);
                            }
                            events.ScheduleEvent(EVENT_RETURN_17, 3s);
                            break;

                        case EVENT_RETURN_17:
                            kalecgos->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            if (Player * player = me->SelectNearestPlayer(50.f))
                                player->CastSpell(me, SPELL_POWER_BALL_VISUAL);
                            events.ScheduleEvent(EVENT_RETURN_18, 1s);
                            break;

                        case EVENT_RETURN_18:
                            kalecgos->DespawnOrUnsummon(3s);
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
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            kinndy->SetVisible(false);
                            events.ScheduleEvent(EVENT_IRIS_2, 2s);
                            break;

                        case EVENT_IRIS_2:
                            arcanic->SetVisible(false);
                            me->SetFacingToObject(players[0]);
                            events.ScheduleEvent(EVENT_IRIS_3, 5s);
                            break;

                        case EVENT_IRIS_3:
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
                                    {
                                        me->SetFacingToObject(temp);
                                        me->SetSheath(SHEATH_STATE_MELEE);
                                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);

                                        warlord = temp;
                                    }
                                    else
                                        soldiers.push_back(temp);
                                }
                            }
                            events.ScheduleEvent(EVENT_IRIS_4, 5s);
                            break;

                        case EVENT_IRIS_4:
                            for (Creature* soldier : soldiers)
                            {
                                if (soldier->GetPositionY() > -4468.18f)
                                {
                                    me->Attack(soldier, false);

                                    soldier->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    soldier->SetReactState(REACT_AGGRESSIVE);
                                    soldier->Attack(me, true);
                                    soldier->GetMotionMaster()->MoveChase(me, 1.f);
                                }
                            }
                            events.ScheduleEvent(EVENT_IRIS_5, 5s);
                            break;

                        #pragma endregion

                        default:
                            break;
                    }
                }
            }
            else
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_FIREBALL:
                            DoCastVictim(SPELL_FIREBALL);
                            events.RescheduleEvent(SPELL_FIREBALL, 1542);
                            break;

                        case CASTING_FROSTBOLT:
                            DoCastVictim(SPELL_FROSTBOLT);
                            events.RescheduleEvent(CASTING_FROSTBOLT, 3s, 5s);
                            break;

                        case CASTING_FROST_RUNE_1:
                        {
                            me->PlayDirectSound(28139);
                            me->AddUnitState(UNIT_STATE_ROOT);

                            for (const ThreatReference* threatRef : me->GetThreatManager().GetUnsortedThreatList())
                            {
                                Unit* target = threatRef->GetVictim();

                                float angle = float(rand_norm() * 2 * M_PI);
                                float dist = frand(1, 4);

                                target->NearTeleportTo(warlord->GetPositionX() + cos(angle) * dist, warlord->GetPositionY() + sin(angle) * dist, warlord->GetPositionZ(), angle);
                                target->CastSpell(target, SPELL_POWER_BALL_VISUAL);
                                target->AddAura(SPELL_JAINAS_CALL, target);
                                target->AddUnitState(UNIT_STATE_ROOT);
                            }

                            events.ScheduleEvent(CASTING_FROST_RUNE_2, 3s);
                            break;
                        }

                        case CASTING_FROST_RUNE_2:

                            break;

                        case CASTING_ARCANIC_VOLLEY:
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        }

        private:
        EventMap events;
        std::vector<Player*> players;
        std::vector<Creature*> soldiers;
        Creature* kalecgos;
        Creature* warlord;
        Creature* kinndy;
        Creature* arcanic;
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
