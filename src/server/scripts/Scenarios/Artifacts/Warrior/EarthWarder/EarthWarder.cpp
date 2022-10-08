/*
    http://uwow.biz
    Warrior: EarthWarder
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

Position const trashPos[12] =
{
    {4723.45f, 387.95f, -37.10f, 4.66f},
    {4708.64f, 308.05f, -37.10f, 1.42f},
    //
    {4696.31f, 303.57f, -36.15f, 1.57f},
    {4715.72f, 397.23f, -36.15f, 4.53f},
    //
    {4731.75f, 311.36f, -36.15f, 2.18f},
    //
    {4721.45f, 306.58f, -36.15f, 2.09f},
    {4741.29f, 319.75f, -36.15f, 2.37f},
    //
    {4750.02f, 365.74f, -36.13f, 3.91f},
    {4736.81f, 385.62f, -36.14f, 3.99f},
    {4747.12f, 377.10f, -36.15f, 3.90f},

    {4703.47f, 397.29f, -36.13f, 4.56f},
    {4685.47f, 308.99f, -36.12f, 1.24f}
};

// 96468
class npc_hrutnir : public CreatureScript
{
public:
    npc_hrutnir() : CreatureScript("npc_hrutnir") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        creature->GetMotionMaster()->MovePoint(7, 4720.80f, 347.91f, -37.71f);
        player->CLOSE_GOSSIP_MENU();
        creature->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 0); // госсип
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hrutnirAI(creature);
    }

    struct npc_hrutnirAI : ScriptedAI
    {
        npc_hrutnirAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            firstfighting = false;
            secondfighting = false;
            thirdfighting = false;
            fourfighting = false;
            // me->SetReactState(REACT_DEFENSIVE);
        }

        EventMap events;
        bool _introDone, firstfighting, secondfighting, thirdfighting, fourfighting;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 6000); // 57846
            events.RescheduleEvent(EVENT_2, 18000); // 32736
            events.RescheduleEvent(EVENT_3, 20000); // 13730
            events.RescheduleEvent(EVENT_4, 24000); // 9080
            if (who && who->GetEntry() == 96034)
            {
                events.RescheduleEvent(EVENT_5, 25000); // 79871
                events.RescheduleEvent(EVENT_6, 29000); // 191882
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage = 0;
        }

        void EnterEvadeMode() override
        {
            if (firstfighting) // start
            {
                firstfighting = false;
                Talk(3);
                me->AddDelayedEvent(5000, [this]() -> void
                {
                    Talk(4);
                    me->GetMotionMaster()->MovePath(9859004, false);
                });
            }
            if (secondfighting) // demons
            {
                // secondfighting = false;
                Talk(5);
                me->GetMotionMaster()->MovePoint(2, 4809.14f, 164.68f, -11.20f);
                if (Player* pl = me->FindNearestPlayer(100.0f))
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46289);
            }
            if (thirdfighting) // electrify balls
            {
                thirdfighting = false;
                me->GetMotionMaster()->MovePoint(4, 4824.81f, 246.52f, -24.29f);
            }
            if (fourfighting)
            {
                fourfighting = false;
                Talk(11);
                me->GetMotionMaster()->MovePoint(5, 4822.31f, 328.56f, -30.14f);
            }
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetEntry() == 96443)
            {
                thirdfighting = false;
                me->GetMotionMaster()->MovePoint(4, 4824.81f, 246.52f, -24.29f);
            }
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case 1:
                    fourfighting = true;
                    if (Creature* targ = me->FindNearestCreature(94813, 40.0f, true))
                        AttackStart(targ);
                    Talk(10);
                    break;
                case 2:
                    Talk(14);
                    me->StopAttack();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->GetMotionMaster()->MovePoint(6, 4763.73f, 340.87f, -37.19f);
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 6)
                {
                    Talk(18);
                    me->AddDelayedEvent(5000, [this]() -> void
                    {
                        if (Creature* targ = me->FindNearestCreature(94714, 85.0f, true))
                        {
                            targ->AI()->Talk(5);
                            AttackStart(targ);
                            secondfighting = true;
                            std::list<Creature*> adds;
                            GetCreatureListWithEntryInGrid(adds, targ, 96571, 50.0f);
                            if (!adds.empty())
                                for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                                {
                                    (*itr)->Kill((*itr));
                                    (*itr)->DespawnOrUnsummon(1000);
                                }
                        }
                    });
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46288);
                }
            }
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 1:
                        DoCast(193571);
                        Talk(2);
                        if (Creature* targ = me->FindNearestCreature(96571, 30.0f, true))
                        {
                            AttackStart(targ);
                            firstfighting = true;
                        }
                        break;
                    case 2:
                        if (GameObject* go = me->FindNearestGameObject(243522, 30.0f))
                            if (InstanceScript* inst = me->GetInstanceScript())
                                inst->HandleGameObject(go->GetGUID(), true);
                        secondfighting = false;
                        me->AddDelayedEvent(4000, [this]() -> void
                        {
                            Talk(19);
                            Talk(6);
                            if (Creature* targ = me->FindNearestCreature(96443, 70.0f, true))
                                AttackStart(targ);
                            thirdfighting = true;
                        });
                        break;
                    case 3:
                        Talk(19);
                        Talk(6);
                        if (Creature* targ = me->FindNearestCreature(96443, 70.0f, true))
                            AttackStart(targ);
                        thirdfighting = true;
                        break;
                    case 4:
                        Talk(7);
                        Talk(8);
                        me->AddDelayedEvent(15000, [this]() -> void
                        {
                            Talk(9);
                        });
                        break;
                    case 5:
                        Talk(12);
                        me->AddDelayedEvent(2000, [this]() -> void
                        {
                            Talk(13);
                        });
                        break;
                    case 6:
                        Talk(15);
                        me->AddDelayedEvent(6500, [this]() -> void
                        {
                            Talk(16);
                            me->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                            me->SetReactState(REACT_DEFENSIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        });
                        break;
                    case 7:
                        me->CreateConversation(497);
                        me->AddDelayedEvent(6000, [this]() -> void
                        {
                            if (Creature* boss = me->FindNearestCreature(96034, 60.0f, true))
                                boss->AI()->DoAction(true);
                        });
                        break;
                    default:
                        break;
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 20.0f))
            {
                _introDone = true;
                Talk(0);
                me->AddDelayedEvent(5000, [this]() -> void
                {
                    Talk(1);
                    me->GetMotionMaster()->MovePoint(1, 4864.44f, -33.53f, 48.68f);
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(57846);
                        events.RescheduleEvent(EVENT_1, 6000); // 57846
                        break;
                    case EVENT_2:
                        DoCast(32736);
                        events.RescheduleEvent(EVENT_2, 18000); // 32736
                        break;
                    case EVENT_3:
                        DoCast(13730);
                        events.RescheduleEvent(EVENT_3, 20000); // 13730
                        break;
                    case EVENT_4:
                        DoCast(9080);
                        events.RescheduleEvent(EVENT_4, 24000); // 9080
                        break;
                    case EVENT_5:
                        DoCast(79871);
                        break;
                    case EVENT_6:
                        DoCast(191882);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 96034
class npc_magnar_icebreaker : public CreatureScript
{
public:
    npc_magnar_icebreaker() : CreatureScript("npc_magnar_icebreaker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magnar_icebreakerAI(creature);
    }

    struct npc_magnar_icebreakerAI : ScriptedAI
    {
        npc_magnar_icebreakerAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            wave = 1;
            count_dies = 0;
            first_phase = true;
        }

        SummonList summons;
        std::list<ObjectGuid> trashList;

        EventMap events;
        bool stop_combat;
        bool first_phase;
        uint8 wave;
        uint8 count_dies;

        void Reset() override
        {
            events.Reset();
            stop_combat = false;
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 7000); // 191883
            events.RescheduleEvent(EVENT_2, 14000); // 191885
            events.RescheduleEvent(EVENT_3, 15000); // 128749
            events.RescheduleEvent(EVENT_4, 33000); // event
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
            {
                if (!first_phase)
                {
                    me->RemoveAura(128749);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->setFaction(35);
                    me->CreateConversation(504);
                    // me->AddDelayedEvent(6000, [this]() -> void
                    // {
                        if (Player* pl = me->FindNearestPlayer(100.0f))
                            pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 45784);
                        me->DespawnOrUnsummon(6000);
                    // });
                }
                damage = 0;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            trashList.push_back(summon->GetGUID());
            summon->SetReactState(REACT_PASSIVE);
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            summons.Despawn(summon);
            trashList.remove(summon->GetGUID());
            count_dies--;
            if (count_dies == 0)
            {
                LaunchEventWave(wave);
                wave++;
            }
        }


        void DoAction(int32 const action) override
        {
            trashList.clear();
            SummonTrash();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_DEFENSIVE);
            me->setFaction(14);
            me->GetMotionMaster()->MoveJump(4714.82f, 349.11f, -37.77f, 5, 5);
            if (Creature* targ = me->FindNearestCreature(96468, 70.0f, true))
            {
                AttackStart(targ);
                EnterCombat(targ);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (stop_combat)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(191883);
                        events.RescheduleEvent(EVENT_1, 15000); // 191883
                        break;
                    case EVENT_2:
                        DoCast(191885);
                        events.RescheduleEvent(EVENT_2, 15000); // 191885
                        break;
                    case EVENT_3:
                        DoCast(128749);
                        events.RescheduleEvent(EVENT_3, 15000); // 128749
                        break;
                    case EVENT_4:
                        me->RemoveAura(128749);
                        me->StopAttack();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        stop_combat = true;
                        if (Creature* targ = me->FindNearestCreature(96468, 100.0f, true))
                            targ->AttackStop();
                        me->GetMotionMaster()->MoveJump(4686.67f, 354.12f, -27.10f, 5, 5);
                        LaunchEventWave(wave);
                        wave++;
                        events.RescheduleEvent(EVENT_5, 1000);
                        break;
                    case EVENT_5:
                        me->CreateConversation(498);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void LaunchEventWave(uint32 wave)
        {
            uint8 count = 0;
            bool end = false;
            switch (wave)
            {
                case 1:
                    count = 2;
                    break;
                case 2:
                    count = 2;
                    break;
                case 3:
                    count = 1;
                    break;
                case 4:
                    count = 2;
                    break;
                case 5:
                    count = 3;
                    end = true;
                    break;
                case 6:
                {
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46427);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_DEFENSIVE);
                    first_phase = false;
                    stop_combat = false;
                    return;
                }
                default:
                    return;
            }

            count_dies = count;

            for (auto trashGuid : trashList)
            {
                if (!count)
                    break;
                if (Creature* summon = me->GetMap()->GetCreature(trashGuid))
                {
                    summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    summon->SetReactState(REACT_DEFENSIVE);
                    summon->RemoveAura(191821);
                    if (Creature* targ = summon->FindNearestCreature(96468, 100.0f, true))
                    {
                        summon->AI()->AttackStart(targ);
                        targ->AI()->AttackStart(summon);
                    }
                    count--;
                }
            }

            if (end == false)
                return;

            for (auto trashGuid : trashList)
            {
                if (Creature* summon = me->GetMap()->GetCreature(trashGuid))
                {
                    summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    if (Creature* targ = summon->FindNearestCreature(64367, 30.0f, true))
                        summon->GetMotionMaster()->MoveJump(targ->GetPositionX(), targ->GetPositionY(), targ->GetPositionZ(), 5, 5);
                    summon->CastSpell(summon, 191032);
                }
            }
            trashList.clear();
            me->SetHealth(me->CountPctFromMaxHealth(80));
        }

        void SummonTrash()
        {
            for (uint8 i = 0; i < 4; ++i)
                me->SummonCreature(97123, trashPos[i]);
            me->SummonCreature(94707, trashPos[4]);
            for (uint8 i = 5; i < 9; ++i)
                me->SummonCreature(97123, trashPos[i]);
            me->SummonCreature(94707, trashPos[9]);

            me->SummonCreature(94813, trashPos[10]);
            me->SummonCreature(94813, trashPos[11]);
        }

    };
};

// 248831
class go_art_earthwarder : public GameObjectScript
{
public:
    go_art_earthwarder() : GameObjectScript("go_art_earthwarder") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 45785);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 909, 1);
                if (Creature* trigger = go->FindNearestCreature(94854, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128289, 1))
                    target->ToPlayer()->AddItem(128289, 1);

                target->CastSpell(target, 205340, true);

                target->ToPlayer()->KilledMonsterCredit(94851);

                target->AddDelayedEvent(12000, [target]() -> void
                {
                    target->CastSpell(target, 192085);
                    target->ToPlayer()->KilledMonsterCredit(103739);
                });
            }
        }
    }
};

void AddSC_EarthWarder()
{
    new npc_hrutnir();
    new npc_magnar_icebreaker();
    new go_art_earthwarder();
};
