/*
    http://uwow.biz
    Priest: Tuure
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

Position const tppos[2] =
{
    {12.00f, 1189.50f, -45.98f, 0.0f},
    {58.69f, 1212.91f, -39.64f, 0.0f}
};

// 106134
class npc_vindicator_boros : public CreatureScript
{
public:
    npc_vindicator_boros() : CreatureScript("npc_vindicator_boros") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vindicator_borosAI(creature);
    }

    struct npc_vindicator_borosAI : ScriptedAI
    {
        npc_vindicator_borosAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            _introHealDone = false;
            firstfighting = false;
            wait_heal = false;
            firstwp = false;
            secondwp = false;
        }

        EventMap events;
        bool _introDone, _introHealDone, firstfighting, wait_heal, firstwp, secondwp;
        FunctionProcessor _functions;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 4000);
            events.RescheduleEvent(EVENT_2, 9000);
        }

        void EnterEvadeMode() override
        {
            // need to activate it ONLY if creature isn't stunned
            _functions.AddFunction([this]() -> void
            {
                if (firstfighting)
                {
                    firstfighting = false;
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50562);
                    me->CreateConversation(2009);

                    me->AddDelayedEvent(16000, [this]() -> void
                    {
                        if (Creature* targ = me->FindNearestCreature(106221, 40.0f, true))
                            targ->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    });
                }
            }, _functions.CalculateTime(1000));
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case 1:
                {
                    // need to activate it ONLY if creature isn't stunned
                    _functions.AddFunction([this]() -> void
                    {
                        if (Creature* jeims = me->FindNearestCreature(106137, 20.0f, true))
                        {
                            jeims->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE, MOTION_SLOT_IDLE);
                            jeims->AI()->Talk(0);
                        }
                        me->GetMotionMaster()->MovePath(9859002, false);
                        firstwp = true;
                        me->CreateConversation(2039);
                    }, _functions.CalculateTime(1000));
                    break;
                }
                case 2:
                {
                    // need to activate it ONLY if creature isn't stunned
                    _functions.AddFunction([this]() -> void
                    {
                        me->GetMotionMaster()->MovePoint(3, 69.05f, 1220.01f, -39.70f);
                    }, _functions.CalculateTime(1000));
                    break;
                }
            }
        }

        void HealReceived(Unit* who, uint32& /*addhealth*/) override
        {
            if (!_introHealDone)
                if (me->GetHealthPct() >= 95)
                {
                    _introHealDone = true;
                    Talk(2);
                    me->SetByteValue(UNIT_FIELD_BYTES_1, 0, 0);
                    me->SetAnimKitId(0);
                    me->GetMotionMaster()->MovePoint(1, -13.92f, 1175.70f, -66.31f);
                    if (Player* pl = who->ToPlayer())
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50563);
                }

            if (wait_heal)
            {
                if (me->GetHealthPct() >= 40)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    me->RemoveAura(204237);
                    wait_heal = false;
                }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!wait_heal)
                {
                    wait_heal = true;
                    me->AddAura(204237, me);
                    Talk(10);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (firstwp)
                {
                    if (id == 6)
                        me->CreateConversation(2007);
                    if (id == 10)
                        if (Player* pl = me->FindNearestPlayer(100.0f))
                        {
                            pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50831);
                            firstwp = false;
                        }
                }
                if (secondwp)
                {
                    if (id == 7)
                    {
                        if (Creature* jeims = me->FindNearestCreature(106137, 60.0f, true))
                            jeims->AI()->Talk(2);
                        // need to activate it ONLY if creature isn't stunned
                        _functions.AddFunction([this]() -> void
                        {
                            if (Creature* targ = me->FindNearestCreature(106318, 100.0f, true))
                                AttackStart(targ);
                        }, _functions.CalculateTime(4000));
                    }
                }
            }
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 1:
                        me->AddDelayedEvent(2000, [this]() -> void
                        {
                            DoCast(212629);
                            Talk(3);
                            if (GameObject* go = me->FindNearestGameObject(249469, 30.0f))
                                if (InstanceScript* inst = me->GetInstanceScript())
                                    inst->HandleGameObject(go->GetGUID(), true);
                            if (Creature* jeims = me->FindNearestCreature(106137, 100.0f, true))
                                if (Creature* targ = jeims->FindNearestCreature(106201, 40.0f, true))
                                    jeims->AI()->AttackStart(targ);

                        });

                        me->AddDelayedEvent(3000, [this]() -> void
                        {
                            me->GetMotionMaster()->MovePoint(2, 34.70f, 1201.05f, -65.06f);
                        });
                        break;
                    case 2:
                        Talk(4);
                        me->GetMotionMaster()->MoveJump(58.20f, 1214.60f, -74.35f, 10, 10);
                        if (Creature* targ = me->FindNearestCreature(106201, 60.0f, true))
                            AttackStart(targ);
                        firstfighting = true;
                        break;
                    case 3:
                        me->CreateConversation(2015);
                        // need to activate it ONLY if creature isn't stunned
                        _functions.AddFunction([this]() -> void
                        {
                            secondwp = true;
                            me->GetMotionMaster()->MovePath(9859003, false);
                            if (Creature* jeims = me->FindNearestCreature(106137, 70.0f, true))
                                jeims->AI()->Talk(1);
                        }, _functions.CalculateTime(8000));
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
                Talk(0, who->GetGUID());
                me->AddDelayedEvent(4000, [this]() -> void
                {
                    Talk(1);
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED)) // need for this
                return;

            _functions.Update(diff);

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(211455);
                        events.RescheduleEvent(EVENT_1, 4000);
                        break;
                    case EVENT_2:
                        DoCast(210371);
                        events.RescheduleEvent(EVENT_2, 9000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 106137 106253
class npc_tuure_small_events : public CreatureScript
{
public:
    npc_tuure_small_events() : CreatureScript("npc_tuure_small_events") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tuure_small_eventsAI(creature);
    }

    struct npc_tuure_small_eventsAI : ScriptedAI
    {
        npc_tuure_small_eventsAI(Creature* creature) : ScriptedAI(creature)
        {
            wait_heal = false;
        }

        EventMap events;
        bool wait_heal;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (me->GetEntry() == 106253)
            {
                events.RescheduleEvent(EVENT_1, 4000); // 210477
                events.RescheduleEvent(EVENT_2, 11000); // 210478
                events.RescheduleEvent(EVENT_3, 15000); // 210479
            }
        }


        void HealReceived(Unit* who, uint32& /*addhealth*/) override
        {
            if (wait_heal)
            {
                if (me->GetHealthPct() >= 40)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    me->RemoveAura(204237);
                    wait_heal = false;
                }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!wait_heal)
                {
                    wait_heal = true;
                    me->AddAura(204237, me);
                    Talk(10);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED)) // need for this
                return;

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(210477);
                        events.RescheduleEvent(EVENT_1, 4000); // 210477
                        break;
                    case EVENT_2:
                        DoCast(210478);
                        events.RescheduleEvent(EVENT_2, 11000); // 210478
                        break;
                    case EVENT_3:
                        DoCast(210479);
                        events.RescheduleEvent(EVENT_3, 15000); // 210479
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


enum Phases
{
    PHASE_COMBAT = 1,
    PHASE_REPHASE = 2
};

// 106107
class npc_capitan_naranot : public CreatureScript
{
public:
    npc_capitan_naranot() : CreatureScript("npc_capitan_naranot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_capitan_naranotAI(creature);
    }

    struct npc_capitan_naranotAI : ScriptedAI
    {
        npc_capitan_naranotAI(Creature* creature) : ScriptedAI(creature)
        {
            me->setFaction(35);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        EventMap events;
        uint8 point;

        void Reset() override
        {
            events.Reset();
            me->SetReactState(REACT_DEFENSIVE);
        }

        void EnterCombat(Unit* who) override
        {
            Talk(1);
            point = 1;
            me->SetReactState(REACT_DEFENSIVE);
            events.SetPhase(PHASE_COMBAT);
            events.RescheduleEvent(EVENT_1, 8000, 0, PHASE_COMBAT); // 211480
         //   events.RescheduleEvent(EVENT_2, 25000, 0, PHASE_COMBAT); // rephase 211186 + 211190    
            if (Creature* targ = me->FindNearestCreature(106134, 100.0f, true))
                targ->AI()->AttackStart(me);
        }

        void JustDied(Unit* who) override
        {
            if (Creature* boros = me->FindNearestCreature(106134, 120.0f, true))
                boros->AI()->DoAction(2);
            if (Player* pl = me->FindNearestPlayer(100.0f))
                pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50634);
        }
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(211480);
                        events.RescheduleEvent(EVENT_1, 8000, 0, PHASE_COMBAT); // 211480
                        break;
                    case EVENT_2:
                    {
                        DoCast(211186);
                        std::list<Creature*> adds;
                        GetCreatureListWithEntryInGrid(adds, me, 106563, 10.0f);
                        if (!adds.empty())
                            for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                            {
                                (*itr)->CastSpell((*itr), 211194);
                            }

                        if (point >= 2)
                            point = 0;

                        me->SetReactState(REACT_PASSIVE);
                        me->CastSpell(tppos[point].GetPositionX(), tppos[point].GetPositionY(), tppos[point].GetPositionZ(), 211190);
                        me->GetMotionMaster()->MoveJump(tppos[point].GetPositionX(), tppos[point].GetPositionY(), tppos[point++].GetPositionZ(), 15, 15);
                        events.RescheduleEvent(EVENT_2, 25000, 0, PHASE_COMBAT); // rephase 211186 + 211190  
                        events.SetPhase(PHASE_REPHASE);
                        events.RescheduleEvent(EVENT_3, 2000, 0, PHASE_REPHASE);
                        break;
                    }
                    case EVENT_3:
                        if (Player* pl = me->FindNearestPlayer(100.0f, true))
                        {
                            me->CastSpell(pl, 211208);
                            if (me->GetDistance2d(pl) <= 20.0f)
                            {
                                me->SetReactState(REACT_DEFENSIVE);
                                events.SetPhase(PHASE_COMBAT);
                            }
                        }
                        events.RescheduleEvent(EVENT_4, 4000, 0, PHASE_REPHASE);
                        break;

                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 106318
class npc_lady_kalindria : public CreatureScript
{
public:
    npc_lady_kalindria() : CreatureScript("npc_lady_kalindria") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lady_kalindriaAI(creature);
    }

    struct npc_lady_kalindriaAI : ScriptedAI
    {
        npc_lady_kalindriaAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        EventMap events;
        SummonList summons;

        bool outro, outro_event, outro_event1;

        void Reset() override
        {
            events.Reset();
            outro = false;
            outro_event = false;
            outro_event1 = false;
            summons.DespawnAll();
        }

        void EnterCombat(Unit* who) override
        {
            Talk(0);
            events.RescheduleEvent(EVENT_1, 2000); //211185
            events.RescheduleEvent(EVENT_2, 13000); //211380 + script for summon (17)
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void DamageTaken(Unit* who, uint32& damage, DamageEffectType dmgType) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!outro)
                {
                    Talk(4);
                    outro = true;
                    me->StopAttack();
                    DoCast(210715);
                    ObjectGuid targetGUID = who->GetGUID();
                    me->AddDelayedEvent(3000, [this, targetGUID]() -> void
                    {
                        if (!me)
                            return;

                        if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                            target->Kill(me);
                    });

                    events.Reset();
                    // event
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50695);

                    std::list<Creature*> adds;
                    GetCreatureListWithEntryInGrid(adds, me, 106134, 50.0f);
                    GetCreatureListWithEntryInGrid(adds, me, 106137, 50.0f);
                    GetCreatureListWithEntryInGrid(adds, me, 106253, 50.0f);
                    if (!adds.empty())
                        for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                        {
                            (*itr)->ClearUnitState(UNIT_STATE_STUNNED);
                            (*itr)->CastSpell((*itr), 210807);
                        }
                    me->CreateConversation(2015);
                }
            }

            if (!outro_event && me->HealthBelowPct(13))
            {
                outro_event = true;
                Talk(1);
                events.RescheduleEvent(EVENT_3, 10);
            }

            if (!outro_event1 && me->HealthBelowPct(9))
            {
                outro_event1 = true;
                Talk(3);
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (spell->Id == 210703)
                target->AddUnitState(UNIT_STATE_STUNNED);
        }


        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(211185);
                        events.RescheduleEvent(EVENT_1, 2500); //211185
                        break;
                    case EVENT_2:
                        if (Player* pl = me->FindNearestPlayer(100.0f, true))
                        {
                            DoCast(211380);
                            for (uint8 i = 0; i < urand(15, 18); ++i)
                            {
                                if (Creature* add = me->SummonCreature(106606, pl->GetPositionX() + irand(-7, 7), pl->GetPositionY() + irand(-7, 7), pl->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 25000))
                                {
                                    add->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                    add->AI()->AttackStart(pl);
                                }
                            }
                        }
                        events.RescheduleEvent(EVENT_2, 34000); //211380 + script for summon (17)
                        break;
                    case EVENT_3:
                        DoCast(210703);
                        if (Player* pl = me->FindNearestPlayer(100.0f, true))
                            AttackStart(pl);
                        me->AddDelayedEvent(3000, [this]() -> void
                        {
                            Talk(2);
                        });
                        break;
                }
            }
            // DoMeleeAttackIfReady();
        }
    };
};

// 249693
class go_tuure_crate : public GameObjectScript
{
public:
    go_tuure_crate() : GameObjectScript("go_tuure_crate") { }

    struct go_tuure_crateAI : public GameObjectAI
    {
        go_tuure_crateAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50633);
            if (Creature* boja = player->FindNearestCreature(106253, 60.0f, true))
            {
                boja->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                boja->AI()->Talk(0);
                if (Creature* boros = boja->FindNearestCreature(106134, 70.0f, true))
                    boja->GetMotionMaster()->MoveFollow(boros, PET_FOLLOW_DIST, -PET_FOLLOW_ANGLE, MOTION_SLOT_IDLE);

                if (Creature* capitan = boja->FindNearestCreature(106107, 70.0f, true))
                {
                    capitan->AI()->Talk(0);
                    capitan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    capitan->SetReactState(REACT_DEFENSIVE);
                    capitan->setFaction(2102);
                }
            }
            go->Delete();
            return true;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_tuure_crateAI(go);
    }
};

// 249705
class go_art_tuure : public GameObjectScript
{
public:
    go_art_tuure() : GameObjectScript("go_art_tuure") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50679);
                if (Creature* trigger = go->FindNearestCreature(106326, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128825, 1))
                    target->ToPlayer()->AddItem(128825, 1);

                target->CastSpell(target, 210733, true);

                target->AddDelayedEvent(14000, [target]() -> void
                {
                    target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50702);
                    target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1085, 1);
                    target->CastSpell(target, 210818);
                });
            }
        }
    }
};

void AddSC_Tuure()
{
    new npc_vindicator_boros();
    new npc_tuure_small_events();
    new npc_capitan_naranot();
    new npc_lady_kalindria();
    new go_tuure_crate();
    new go_art_tuure();
};
