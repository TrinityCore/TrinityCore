/*
    http://uwow.biz
    Monk: Sheylun
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"


// 101881
class npc_tazhan_chu : public CreatureScript
{
public:
    npc_tazhan_chu() : CreatureScript("npc_tazhan_chu") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {

        player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48494);
        creature->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 0); // госсип
        creature->GetMotionMaster()->MovePoint(0, -1019.15f, -2795.95f, 38.91f);
        if (Creature* mob = creature->FindNearestCreature(101882, 107.0f, true))
        {
            mob->GetMotionMaster()->MovePoint(0, -1019.15f, -2795.95f, 38.91f);
            mob->AI()->Talk(4);
            mob->CastSpell(mob, 60958);
        }

        if (Creature* mob = creature->FindNearestCreature(101885, 107.0f, true))
            mob->GetMotionMaster()->MovePoint(0, -1019.15f, -2795.95f, 38.91f);

        if (Creature* mob = creature->FindNearestCreature(101883, 107.0f, true))
            mob->GetMotionMaster()->MovePoint(0, -1019.15f, -2795.95f, 38.91f);

        if (GameObject* go = creature->FindNearestGameObject(246464, 100.0f))
            go->SetPhaseMask(2, true);
        player->CLOSE_GOSSIP_MENU();
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tazhan_chuAI(creature);
    }

    struct npc_tazhan_chuAI : ScriptedAI
    {
        npc_tazhan_chuAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            _introHealDone = false;
            wait_heal = false;
            countgossip = 0;
            me->SetReactState(REACT_AGGRESSIVE);
        }

        EventMap events;
        bool _introDone, _introHealDone, wait_heal;
        FunctionProcessor _functions;
        uint8 countgossip;

        void Reset() override
        {
            events.Reset();
            me->SetWalk(false);
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 7000); // 203859
            events.RescheduleEvent(EVENT_2, 17000); // 203854
            events.RescheduleEvent(EVENT_3, 19000); // 203858
            events.RescheduleEvent(EVENT_4, 23000); // 202517
        }

        void DoAction(int32 const action) override
        {
            if (action == 1)
                countgossip++;

            if (countgossip == 3)
                me->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            damage = damage * 2;
        }

        void SetData(uint32 type, uint32 id) override
        {
            if (type == 1 && id == 1)
            {
                _functions.AddFunction([this]() -> void
                {
                    if (Creature* mob = me->FindNearestCreature(101882, 107.0f, true))
                        mob->AI()->DoAction(true);
                    if (Creature* mob = me->FindNearestCreature(102063, 107.0f, true))
                        mob->AI()->DoAction(true);
                    if (Creature* mob = me->FindNearestCreature(101885, 107.0f, true))
                        mob->AI()->DoAction(true);
                    if (Creature* mob = me->FindNearestCreature(101883, 107.0f, true))
                        mob->AI()->DoAction(true);
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48383);

                    Talk(8);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(3, -1018.74f, -2994.68f, 12.30f);
                }, _functions.CalculateTime(1000));

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
                    if (Player* pl = who->ToPlayer())
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48371);
                    me->GetMotionMaster()->MovePoint(1, -1020.62f, -3135.73f, 26.91f);
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
            damage /= 2;
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!wait_heal)
                {
                    wait_heal = true;
                    me->AddAura(204237, me);
                    Talk(11);
                    Talk(12);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 1:
                    {
                        Talk(3);
                        DoCast(202053);

                        me->AddDelayedEvent(4000, [this]() -> void
                        {
                            std::list<GameObject*> gob;
                            GetGameObjectListWithEntryInGrid(gob, me, 246321, 35.0f);
                            if (!gob.empty())
                                for (std::list<GameObject*>::iterator itr = gob.begin(); itr != gob.end(); ++itr)
                                    (*itr)->SetPhaseMask(2, true); // hide   
                            Talk(4);
                            me->GetMotionMaster()->MovePoint(2, -1017.80f, -3048.89f, 12.82f);
                        });
                        break;
                    }
                    case 2:
                    {
                        Talk(5);
                        break;
                    }
                    case 3:
                    {
                        Talk(9);
                        if (GameObject* go = me->FindNearestGameObject(246395, 50.0f))
                            go->SetPhaseMask(2, true); // hide
                        _functions.AddFunction([this]() -> void
                        {
                            me->GetMotionMaster()->MovePoint(4, -1017.72f, -2933.42f, 19.48f);
                        }, _functions.CalculateTime(1000));
                        break;
                    }
                    case 4:
                    {
                        Talk(10);
                        if (Creature* mob = me->FindNearestCreature(101882, 107.0f, true))
                            mob->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                        if (Creature* mob = me->FindNearestCreature(101885, 107.0f, true))
                            mob->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                        if (Creature* mob = me->FindNearestCreature(101883, 107.0f, true))
                            mob->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                        break;
                    }
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

            if (me->HasAura(204779))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(203859);
                        events.RescheduleEvent(EVENT_1, 7000); // 203859
                        break;
                    case EVENT_2:
                        DoCast(203854);
                        events.RescheduleEvent(EVENT_2, 17000); // 203854
                        break;
                    case EVENT_3:
                        DoCast(203858);
                        events.RescheduleEvent(EVENT_3, 19000); // 203858
                        break;
                    case EVENT_4:
                        DoCast(202517);
                        events.RescheduleEvent(EVENT_4, 23000); // 202517
                        break;

                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 101882, 102063, 101885, 101883
class npc_sheylun_small_events : public CreatureScript
{
public:
    npc_sheylun_small_events() : CreatureScript("npc_sheylun_small_events") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {

        uint32 criteria = 0;
        switch (creature->GetEntry())
        {
            case 101882: //fay
                criteria = 48446;
                break;
            case 101883: //birdman
                criteria = 48447;
                break;
            case 101885: //Taoshi
                criteria = 48448;
                break;
        }
        if (criteria)
        {
            player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, criteria);
            creature->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 0); // госсип
            if (Creature* chu = creature->FindNearestCreature(101881, 100.0f, true))
                chu->AI()->DoAction(1);
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sheylun_small_eventsAI(creature);
    }

    struct npc_sheylun_small_eventsAI : ScriptedAI
    {
        npc_sheylun_small_eventsAI(Creature* creature) : ScriptedAI(creature)
        {
            wait_heal = false;
            // me->SetReactState(REACT_AGGRESSIVE);
        }

        EventMap events;
        bool wait_heal;
        FunctionProcessor _functions;

        void Reset() override
        {
            events.Reset();
            if (me->GetEntry() == 101882)
                DoCast(203836);
            if (me->GetEntry() == 101885)
                DoCast(204624);
            if (me->GetEntry() == 101883)
                DoCast(204593);
        }

        void EnterCombat(Unit* who) override
        {
            if (me->GetEntry() == 101882)
            {
                events.RescheduleEvent(EVENT_1, 5000); // 203832
                events.RescheduleEvent(EVENT_2, 11000); // 203831
            }
            if (me->GetEntry() == 101885)
            {
                events.RescheduleEvent(EVENT_3, 10000); // 203869
                events.RescheduleEvent(EVENT_4, 22000); // 203867
                events.RescheduleEvent(EVENT_5, 2600); // 203865
            }
            if (me->GetEntry() == 101883)
            {
                events.RescheduleEvent(EVENT_6, 2500); // 131995
                events.RescheduleEvent(EVENT_7, 3500); // 80016 31
            }
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            damage = damage * 2;
        }

        void DoAction(int32 const action) override
        {

            if (Creature* tazhan = me->FindNearestCreature(101881, 100.0f))
                me->GetMotionMaster()->MoveFollow(tazhan, urand(1, 4), (urand(1, 2) == 2 ? PET_FOLLOW_ANGLE : -PET_FOLLOW_ANGLE), MOTION_SLOT_IDLE);

            switch (me->GetEntry())
            {
                case 101882: //fay
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48380);
                    break;
                case 101883: //birdman
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48381);
                    break;
                case 101885: //Taoshi
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48382);
                    break;
            }

        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
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
                    Talk(0);
                    Talk(1);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED)) // need for this
                return;

            _functions.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasAura(204779))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(203832);
                        events.RescheduleEvent(EVENT_1, 5000); // 203832
                        break;
                    case EVENT_2:
                        DoCast(203831);
                        events.RescheduleEvent(EVENT_2, 11000); // 203831
                        break;
                    case EVENT_3:
                        DoCast(203869);
                        events.RescheduleEvent(EVENT_3, 10000); // 203869
                        break;
                    case EVENT_4:
                        DoCast(203867);
                        events.RescheduleEvent(EVENT_4, 22000); // 203867
                        break;
                    case EVENT_5:
                        DoCast(203865);
                        events.RescheduleEvent(EVENT_5, 2600); // 203865
                        break;
                    case EVENT_6:
                        DoCast(131995);
                        events.RescheduleEvent(EVENT_6, 2500); // 131995
                        break;
                    case EVENT_7:
                        DoCast(80016);
                        events.RescheduleEvent(EVENT_7, 31000); // 80016 31
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 246351
class go_sheylun_crate : public GameObjectScript
{
public:
    go_sheylun_crate() : GameObjectScript("go_sheylun_crate") { }

    struct go_sheylun_crateAI : public GameObjectAI
    {
        go_sheylun_crateAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            if (Creature* mob = go->FindNearestCreature(101882, 7.0f, true))
                mob->AI()->DoAction(true);
            if (Creature* mob = go->FindNearestCreature(102063, 7.0f, true))
                mob->AI()->DoAction(true);
            if (Creature* mob = go->FindNearestCreature(101885, 7.0f, true))
                mob->AI()->DoAction(true);
            if (Creature* mob = go->FindNearestCreature(101883, 7.0f, true))
                mob->AI()->DoAction(true);
            go->Delete();
            return true;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_sheylun_crateAI(go);
    }
};


// 101887
class npc_aspersiy : public CreatureScript
{
public:
    npc_aspersiy() : CreatureScript("npc_aspersiy") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aspersiyAI(creature);
    }

    struct npc_aspersiyAI : public Scripted_NoMovementAI
    {
        npc_aspersiyAI(Creature* creature) : Scripted_NoMovementAI(creature), summons(me) {}

        EventMap events;
        SummonList summons;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 21000); // 204779
            events.RescheduleEvent(EVENT_2, 35000); // 204773  21
            events.RescheduleEvent(EVENT_3, 36000); // 43 summons
            if (Creature* tazhan = me->FindNearestCreature(101881, 100.0f, true))
                tazhan->AI()->AttackStart(me);
            if (Creature* mob = me->FindNearestCreature(101882, 100.0f, true))
                mob->AI()->AttackStart(me);
            if (Creature* mob = me->FindNearestCreature(101885, 100.0f, true))
                mob->AI()->AttackStart(me);
            if (Creature* mob = me->FindNearestCreature(101883, 100.0f, true))
                mob->AI()->AttackStart(me);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void JustDied(Unit* who) override
        {
            if (Player* pl = me->FindNearestPlayer(100.0f))
            {
                pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48495);

                pl->AddDelayedEvent(2000, [pl]() -> void
                {
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48646);

                    if (!pl->HasItemCount(128937, 1))
                        pl->AddItem(128937, 1);

                    pl->CastSpell(pl, 202435, true);

                    pl->AddDelayedEvent(14000, [pl]() -> void
                    {
                        pl->KilledMonsterCredit(101880);
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1007, 1);
                        pl->CastSpell(pl, 194151);
                    });
                });
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage *= 2;
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
                        if (me->getVictim()->GetTypeId() == TYPEID_PLAYER)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 60.0f, false))
                                me->CastSpell(target, 204779);
                            else
                                DoCast(204779);
                        events.RescheduleEvent(EVENT_1, 21000); // 204779
                        break;
                    case EVENT_2:
                        DoCast(204773);
                        events.RescheduleEvent(EVENT_2, 21000); // 204773  21
                        break;
                    case EVENT_3:
                        for (uint8 i = 0; i < urand(7, 8); ++i)
                            me->SummonCreature(103466, me->GetPositionX() + irand(-5, 5), me->GetPositionY() + irand(-5, 5), me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                        events.RescheduleEvent(EVENT_3, 43000); // 43 summons
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 256913
class go_art_sheylun : public GameObjectScript
{
public:
    go_art_sheylun() : GameObjectScript("go_art_sheylun") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48646);
                if (Creature* trigger = go->FindNearestCreature(102479, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128937, 1))
                    target->ToPlayer()->AddItem(128937, 1);

                target->CastSpell(target, 202435, true);

                target->AddDelayedEvent(14000, [target]() -> void
                {
                    target->ToPlayer()->KilledMonsterCredit(101880);
                    target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1007, 1);
                    target->CastSpell(target, 194151);
                });
            }
        }
    }
};

void AddSC_Sheylun()
{
    new npc_tazhan_chu();
    new npc_sheylun_small_events();
    new go_sheylun_crate();
    new npc_aspersiy();
    new go_art_sheylun();
};
