/*
    http://uwow.biz
    Shaman: Sharasdal
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

Position const sumpos[3] =
{
    {-44.86f, 802.57f, 797.15f, 0.0f},
    {-44.72f, 796.29f, 797.30f, 0.0f},
    {-44.97f, 808.61f, 797.33f, 0.0f}
};


// 102826
class npc_erunak_stonespeaker : public CreatureScript
{
public:
    npc_erunak_stonespeaker() : CreatureScript("npc_erunak_stonespeaker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_erunak_stonespeakerAI(creature);
    }

    struct npc_erunak_stonespeakerAI : ScriptedAI
    {
        npc_erunak_stonespeakerAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            wait_heal = false;
            firstbattle = false;
        }

        EventMap events;
        bool _introDone, wait_heal, firstbattle;
        FunctionProcessor _functions;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 4000); // 209912
            events.RescheduleEvent(EVENT_2, 34000); // 209913
            events.RescheduleEvent(EVENT_3, 29000); // 79890
            events.RescheduleEvent(EVENT_4, 10000); // 162074
        }

        void EnterEvadeMode() override
        {
            // need to activate it ONLY if creature isn't stunned
            _functions.AddFunction([this]() -> void
            {
                if (firstbattle)
                {
                    firstbattle = false;
                    me->CreateConversation(1693);
                    me->AddDelayedEvent(5000, [this]() -> void
                    {
                        if (Creature* grash = me->FindNearestCreature(105298, 70.0f, true))
                            grash->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                    });
                }
            }, _functions.CalculateTime(1000));
        }

        void HealReceived(Unit* who, uint32& /*addhealth*/) override
        {
            if (wait_heal)
            {
                if (me->GetHealthPct() >= 40)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    me->RemoveAura(208093);
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
                    me->AddAura(208093, me);
                    Talk(7);
                    Talk(8);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                InstanceScript *script = me->GetInstanceScript();

                if (!script)
                    return;

                if (script->getScenarionStep() <= 2)
                {
                    switch (id)
                    {
                        case 2:
                            Talk(3);
                            break;
                        case 5:
                            Talk(4);
                            break;
                        case 8:
                        {
                            if (Player* targ = me->FindNearestPlayer(100.0f))
                                targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49957);
                            if (Creature* adel = me->FindNearestCreature(104853, 70.0f, true))
                            {
                                adel->AI()->Talk(0);
                                adel->AddDelayedEvent(5000, [adel]() -> void
                                {
                                    adel->AI()->Talk(1);
                                });
                            }
                        }
                        break;
                        case 9:
                            me->CreateConversation(1707);
                            break;
                    }
                }
                else if (script->getScenarionStep() == 3)
                {
                    if (id == 5)
                    {
                        DoCast(83810);
                        if (Player* pl = me->FindNearestPlayer(100.0f))
                            pl->CastSpell(pl, 208580);
                    }
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetPositionZ() >= 795.0f && !_introDone && me->IsWithinDistInMap(who, 20.0f))
            {
                _introDone = true;
                if (Creature* garsh = me->FindNearestCreature(105298, 30.0f, true))
                {
                    garsh->AI()->Talk(8);
                    garsh->GetMotionMaster()->MovePath(10993811, false);
                }
                me->GetMotionMaster()->MovePath(10993811, false, irand(-5, 5), irand(-5, 5));
                if (Creature* adel = me->FindNearestCreature(104853, 30.0f, true))
                {
                    adel->AI()->Talk(8);
                    adel->GetMotionMaster()->MovePath(10993811, false, irand(-5, 5), irand(-5, 5));
                }
                me->AddDelayedEvent(5000, [this]() -> void
                {
                    me->CreateConversation(1868);
                });

            }
            else if (!_introDone && me->IsWithinDistInMap(who, 20.0f))
            {
                _introDone = true;
                who->ToPlayer()->KilledMonsterCredit(105805);
                me->AddDelayedEvent(3000, [this]() -> void
                {
                    Talk(0);
                    if (Creature* targ = me->FindNearestCreature(102792, 70.0f, true))
                        me->AI()->AttackStart(targ);
                });
                firstbattle = true;
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
                        DoCast(209912);
                        events.RescheduleEvent(EVENT_1, 4000); // 209912
                        break;
                    case EVENT_2:
                        DoCast(209913);
                        events.RescheduleEvent(EVENT_2, 34000); // 209913
                        break;
                    case EVENT_3:
                        DoCast(79890);
                        events.RescheduleEvent(EVENT_3, 29000); // 79890
                        break;
                    case EVENT_4:
                        DoCast(162074);
                        events.RescheduleEvent(EVENT_4, 10000); // 162074
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 105298
class npc_grash : public CreatureScript
{
public:
    npc_grash() : CreatureScript("npc_grash") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript *script = player->GetInstanceScript();

        if (!script)
            return true;

        switch (script->getScenarionStep())
        {
            case 0:
            case 1:
                player->ADD_GOSSIP_ITEM_DB(19509, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(28831, creature->GetGUID());
                break;
            case 2:
                player->ADD_GOSSIP_ITEM_DB(19483, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(28782, creature->GetGUID());
                break;
            case 4:
                player->ADD_GOSSIP_ITEM_DB(19467, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(28747, creature->GetGUID());
                break;
        }
        player->ADD_GOSSIP_ITEM(0, "", GOSSIP_SENDER_MAIN, 0);
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        InstanceScript *script = player->GetInstanceScript();

        if (!script)
            return true;

        switch (script->getScenarionStep())
        {
            case 0:
            case 1:
                creature->AI()->DoAction(1);
                player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50161);
                break;
            case 2:
                creature->AI()->DoAction(2);
                break;
            case 4:
                player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49819);
                creature->GetMotionMaster()->MovePoint(1, -17.96f, 802.05f, 807.66f);
                break;
        }
        player->CLOSE_GOSSIP_MENU();
        creature->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 0); // госсип
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_grashAI(creature);
    }

    struct npc_grashAI : ScriptedAI
    {
        npc_grashAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            _introDone1 = false;
            wait_heal = false;
        }

        EventMap events;
        bool _introDone, _introDone1, wait_heal;
        FunctionProcessor _functions;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 5000); // 209904
            events.RescheduleEvent(EVENT_2, 13000); // 209895
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
                        me->GetMotionMaster()->MovePath(10993808, false); // 3
                        if (Creature* erunak = me->FindNearestCreature(102826, 70.0f))
                        {
                            erunak->AI()->Talk(2);
                            erunak->GetMotionMaster()->MovePath(10993809, false); // 2 5 9
                        }
                    }, _functions.CalculateTime(1000));
                    break;
                }
                case 2:
                {
                    _functions.AddFunction([this]() -> void
                    {
                        me->GetMotionMaster()->MovePath(10993810, false);  // 0 3
                        if (Creature* erunak = me->FindNearestCreature(102826, 70.0f))
                        {
                            erunak->AI()->Talk(9);
                            erunak->GetMotionMaster()->MovePath(10993810, false, irand(-5, 5), irand(-5, 5));
                        }
                        if (Creature* adel = me->FindNearestCreature(104853, 70.0f))
                            adel->GetMotionMaster()->MovePath(10993810, false, irand(-5, 5), irand(-5, 5));
                    }, _functions.CalculateTime(1000));
                    break;
                }
                case 3:
                {
                    _functions.AddFunction([this]() -> void
                    {
                        me->GetMotionMaster()->MovePoint(0, -44.47f, 802.39f, 797.16f);
                        if (Creature* erunak = me->FindNearestCreature(102826, 40.0f, true))
                            erunak->GetMotionMaster()->MovePoint(0, -18.62f, 808.39f, 807.72f);
                        if (Creature* adel = me->FindNearestCreature(104853, 40.0f, true))
                            adel->GetMotionMaster()->MovePoint(1, -19.61f, 796.32f, 807.65f);
                    }, _functions.CalculateTime(1000));
                    break;
                }
            }
        }

        void HealReceived(Unit* who, uint32& /*addhealth*/) override
        {
            if (!_introDone && me->GetPositionZ() <= 795.0f)
            {
                if (me->GetHealthPct() >= 90)
                {
                    _introDone = true;
                    if (Player* targ = me->FindNearestPlayer(100.0f))
                    {
                        targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49815);
                        targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49900);
                        targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50161);
                    }
                }
            }

            if (!_introDone1)
            {
                if (me->GetHealthPct() >= 50)
                {
                    _introDone1 = true;
                    Talk(0);
                    me->AddDelayedEvent(3000, [this]() -> void
                    {
                        if (Creature* targ = me->FindNearestCreature(102826, 70.0f, true))
                            targ->AI()->Talk(1);
                    });
                }
            }

            if (wait_heal)
            {
                if (me->GetHealthPct() >= 40)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    me->RemoveAura(208093);
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
                    me->AddAura(208093, me);
                    Talk(1);
                    Talk(2);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 3 || id == 0)
                {
                    DoCast(209904);
                    if (GameObject* go = me->FindNearestGameObject(248514, 5.0f))
                        if (InstanceScript* inst = me->GetInstanceScript())
                            inst->HandleGameObject(go->GetGUID(), true);

                    if (Player* targ = me->FindNearestPlayer(100.0f))
                        targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49817);
                }
            }
            else if (type == POINT_MOTION_TYPE)
            {
                if (id == 1)
                {
                    DoCast(209904);
                    if (GameObject* go = me->FindNearestGameObject(248514, 5.0f))
                        if (InstanceScript* inst = me->GetInstanceScript())
                            inst->HandleGameObject(go->GetGUID(), true);
                    if (Creature* lady = me->FindNearestCreature(104856, 90.0f, true))
                    {
                        AttackStart(lady);
                        if (Creature* erunak = me->FindNearestCreature(102826, 40.0f, true))
                            erunak->AI()->AttackStart(lady);
                        if (Creature* adel = me->FindNearestCreature(104853, 40.0f, true))
                            adel->AI()->AttackStart(lady);
                    }
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

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(209904);
                        events.RescheduleEvent(EVENT_1, 5000); // 209904
                        break;
                    case EVENT_2:
                        DoCast(209895);
                        events.RescheduleEvent(EVENT_2, 13000); // 20989
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 104853
class npc_adel_waterspeaker : public CreatureScript
{
public:
    npc_adel_waterspeaker() : CreatureScript("npc_adel_waterspeaker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_adel_waterspeakerAI(creature);
    }

    struct npc_adel_waterspeakerAI : ScriptedAI
    {
        npc_adel_waterspeakerAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            wait_heal = false;
            if (me->GetPositionZ() >= 795.0f)
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        EventMap events;
        bool _introDone, wait_heal;
        FunctionProcessor _functions;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 10000); // 51876
            events.RescheduleEvent(EVENT_2, 11000); // 209914
        }


        void HealReceived(Unit* who, uint32& /*addhealth*/) override
        {
            if (wait_heal)
            {
                if (me->GetHealthPct() >= 40)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    me->RemoveAura(208093);
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
                    me->AddAura(208093, me);
                    Talk(2);
                    Talk(3);
                    me->AddUnitState(UNIT_STATE_STUNNED);
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == POINT_MOTION_TYPE)
            {
                if (id == 1)
                {
                    // Talk()
                    if (Creature* garsh = me->FindNearestCreature(105298, 50.0f, true))
                    {
                        garsh->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // gossip
                    }
                }
            }
        }

        void OnSpellClick(Unit* clicker) override
        {
            me->AddDelayedEvent(7000, [this, clicker]() -> void
            {
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49816);
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49957);
                me->SetByteValue(UNIT_FIELD_BYTES_1, 0, 0);
                me->SetAnimKitId(0);
                me->HandleEmoteCommand(53);
                me->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 0); // spell click
                if (Creature* garsh = me->FindNearestCreature(105298, 70.0f, true))
                {
                    garsh->AI()->Talk(5);
                    garsh->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // gossip
                }
            });
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
                        DoCast(51876);
                        events.RescheduleEvent(EVENT_1, 10000); // 51876
                        break;
                    case EVENT_2:
                        DoCast(209914);
                        events.RescheduleEvent(EVENT_2, 11000); // 209914
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};



// 102839
class npc_kraliss : public CreatureScript
{
public:
    npc_kraliss() : CreatureScript("npc_kraliss") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kralissAI(creature);
    }

    struct npc_kralissAI : ScriptedAI
    {
        npc_kralissAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 18000); // 209748 с m_Functions
            events.RescheduleEvent(EVENT_2, 20000); // 209764 на рандома. Через спелл хит 209755, который делает рывок и 209757
        }

        void JustDied(Unit* who) override
        {
            if (Player* targ = me->FindNearestPlayer(100.0f))
                targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50240);
        }

        void SpellHitTarget(Unit* who, SpellInfo const* spell) override
        {
            if (spell->Id == 20508)
                me->CastSpell(who, 209757);
            else if (spell->Id == 209755)
                me->CastSpell(who, 209757);
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
                        Talk(0);
                        me->AddDelayedEvent(1000, [this]() -> void
                        {
                            DoCast(209748);
                        });
                        events.RescheduleEvent(EVENT_1, 18000); // 209748 с m_Functions
                        break;
                    case EVENT_2:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(pTarget, 209764);
                            me->CastSpell(pTarget, 209755);
                        }
                        events.RescheduleEvent(EVENT_2, 20000); // 209764 на рандома. Через спелл хит 209755, который делает рывок и 209757
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 104856
class npc_lady_zitrin : public CreatureScript
{
public:
    npc_lady_zitrin() : CreatureScript("npc_lady_zitrin") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lady_zitrinAI(creature);
    }

    struct npc_lady_zitrinAI : ScriptedAI
    {
        npc_lady_zitrinAI(Creature* creature) : ScriptedAI(creature)
        {
            if (me->GetPositionX() <= -15.0f)
                intro = true;
            else
                intro = false;
            _introDone = false;
            introtimer = 2000;
        }

        uint32 introtimer;
        EventMap events;
        bool _introDone, intro;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 2500); // 209919
            events.RescheduleEvent(EVENT_2, 16000); // 209707
            events.RescheduleEvent(EVENT_3, 28000); // 209934 // add
            events.RescheduleEvent(EVENT_4, 25000); // 209983 + script
        }

        void JustDied(Unit* who) override
        {
            if (Player* targ = me->FindNearestPlayer(100.0f))
                targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50397);
            who->CreateConversation(1923);
        }


        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetPositionX() <= -15.0f && !_introDone && me->IsWithinDistInMap(who, 40.0f))
            {
                _introDone = true;
                intro = false;
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50314);
                me->GetMotionMaster()->MovePoint(0, 10.37f, 803.32f, 806.75f);
                if (Creature* garsh = me->FindNearestCreature(105298, 200.0f, true))
                    garsh->AI()->DoAction(3);
                me->DespawnOrUnsummon(1000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (intro)
            {
                if (introtimer <= diff)
                {
                    uint8 rand = urand(0, 2);
                    if (Creature* add = me->SummonCreature(105251, sumpos[rand].GetPositionX(), sumpos[rand].GetPositionY(), sumpos[rand].GetPositionZ(), 0.0f))
                    {
                        add->GetMotionMaster()->MovePoint(1, -148.25f, 802.57f, 796.49f);
                        add->CastSpell(add, 209132);
                    }
                    introtimer = 6000;
                }
                else
                    introtimer -= diff;
            }
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
                        DoCast(209919);
                        events.RescheduleEvent(EVENT_1, 2500); // 209919
                        break;
                    case EVENT_2:
                        DoCast(209707);
                        events.RescheduleEvent(EVENT_2, 16000); // 209707
                        break;
                    case EVENT_3:
                        DoCast(209934);
                        events.RescheduleEvent(EVENT_3, 28000); // 209934 // add
                        break;
                    case EVENT_4:
                        if (Creature* garsh = me->FindNearestCreature(105298, 40.0f, true))
                        {
                            Talk(2);
                            me->CastSpell(garsh, 209983);
                            garsh->AI()->Talk(9);
                        }
                        events.RescheduleEvent(EVENT_4, 25000); // 209983 + script
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 105251
class npc_sharasdal_waterwall : public CreatureScript
{
public:
    npc_sharasdal_waterwall() : CreatureScript("npc_sharasdal_waterwall") {}

    struct npc_sharasdal_waterwallAI : ScriptedAI
    {
        npc_sharasdal_waterwallAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override {}

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (me->GetVehicleKit())
            {
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon(100);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sharasdal_waterwallAI(creature);
    }
};

// 249342
class go_art_sharasdal : public GameObjectScript
{
public:
    go_art_sharasdal() : GameObjectScript("go_art_sharasdal") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49820);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1066, 1);
                if (Creature* trigger = go->FindNearestCreature(105787, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128911, 1))
                    target->ToPlayer()->AddItem(128911, 1);
                go->Delete();

                target->CastSpell(target, 209684, true);

                target->ToPlayer()->KilledMonsterCredit(105787);
            }
        }
    }
};

void AddSC_Sharasdal()
{
    new npc_erunak_stonespeaker();
    new npc_grash();
    new npc_adel_waterspeaker();
    new npc_kraliss();
    new npc_lady_zitrin();
    new npc_sharasdal_waterwall();
    new go_art_sharasdal();
};