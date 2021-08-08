/*
    http://uwow.biz
    Monk: Intro Scenario
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"


// 97778
class npc_master_hait : public CreatureScript
{
public:
    npc_master_hait() : CreatureScript("npc_master_hait") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_master_haitAI(creature);
    }

    struct npc_master_haitAI : ScriptedAI
    {
        npc_master_haitAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == 1 && data == 1)
            {
                if (Player* pl = me->FindNearestPlayer(100.0f))
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46868);
                Talk(5);
                if (Creature* chuan = me->FindNearestCreature(98001, 40.0f, true))
                {
                    chuan->AddDelayedEvent(2000, [chuan]() -> void
                    {
                        chuan->AI()->Talk(3);
                    });

                    chuan->AddDelayedEvent(4000, [chuan]() -> void
                    {
                        chuan->AI()->Talk(4);
                    });

                    chuan->AddDelayedEvent(7000, [chuan]() -> void
                    {
                        chuan->AI()->Talk(5);
                    });
                }

                me->AddDelayedEvent(10000, [this]() -> void
                {
                    Talk(6);
                    me->GetMotionMaster()->MovePoint(1, 3805.70f, 1833.99f, 949.62f);
                });
            }
        }
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == POINT_MOTION_TYPE)
            {
                if (id == 1)
                {
                    Talk(7);
                    me->AddDelayedEvent(3000, [this]() -> void
                    {
                        Talk(8);
                    });

                    me->AddDelayedEvent(6000, [this]() -> void
                    {
                        if (Player* pl = me->FindNearestPlayer(40.0f))
                            Talk(9, pl->GetGUID());
                    });
                }
            }
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 5)
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        Talk(14, pl->GetGUID());
                if (id == 8)
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                    {
                        Talk(15, pl->GetGUID());
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46951);
                    }
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == 1)
            {
                me->AddDelayedEvent(1000, [this]() -> void
                {
                    if (Player* pl = me->FindNearestPlayer(40.0f))
                        Talk(0, pl->GetGUID());
                });

                me->AddDelayedEvent(4000, [this]() -> void
                {
                    Talk(1);
                });

                me->AddDelayedEvent(7000, [this]() -> void
                {
                    Talk(2);
                });

                me->AddDelayedEvent(10000, [this]() -> void
                {
                    Talk(3);
                    me->CastSpell(me, 193053);
                    if (Creature* chuan = me->FindNearestCreature(98001, 40.0f, true))
                    {
                        chuan->SetWalk(true);
                        chuan->GetMotionMaster()->MovePoint(0, 3812.82f, 1810.81f, 950.99f);
                        if (GameObject* door = chuan->FindNearestGameObject(244682, 40.0f))
                            door->UseDoorOrButton(0, false, chuan);

                        if (Creature* demon = chuan->FindNearestCreature(98011, 90.0f, true))
                        {
                            demon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                            demon->GetMotionMaster()->MovePoint(0, 3812.91f, 1812.55f, 950.99f);
                            demon->AddDelayedEvent(20000, [demon, chuan]() -> void
                            {
                                chuan->CastSpell(demon, 227140); // veh
                                demon->CastSpell(3825.61f, 1770.73f, 950.98f, 193268);
                            });

                            chuan->AddDelayedEvent(23000, [this, demon, chuan]() -> void
                            {
                                if (demon->GetVehicleKit())
                                    demon->GetVehicleKit()->RemoveAllPassengers();
                                chuan->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                chuan->CastSpell(chuan, 185627);
                                Talk(4);
                                demon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                                demon->AI()->AttackStart(me);
                            });
                        }

                        chuan->AddDelayedEvent(8000, [chuan]() -> void
                        {
                            chuan->AI()->Talk(0);
                        });

                        chuan->AddDelayedEvent(15000, [chuan]() -> void
                        {
                            chuan->AI()->Talk(1);
                        });
                    }
                });
            }
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (!clicker)
                return;

            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            clicker->ToPlayer()->KilledMonsterCredit(98514);
            clicker->ToPlayer()->KilledMonsterCredit(97778);
            DoAction(1);
        }


        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };
};

// 97774
class npc_nine_czi : public CreatureScript
{
public:
    npc_nine_czi() : CreatureScript("npc_nine_czi") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nine_cziAI(creature);
    }

    struct npc_nine_cziAI : ScriptedAI
    {
        npc_nine_cziAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        bool _introDone;

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == POINT_MOTION_TYPE)
            {
                Talk(5);
                me->AddDelayedEvent(4000, [this]() -> void
                {
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        Talk(6, pl->GetGUID());
                    me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    DoCast(193721);
                });
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 30.0f) && me->GetPositionY() >= 1736.0f)
            {
                _introDone = true;
                Talk(1);
            }

            if (!_introDone && me->IsWithinDistInMap(who, 7.0f) && me->GetPositionY() <= 1736.0f)
            {
                _introDone = true;
                if (Player* pl = me->FindNearestPlayer(100.0f))
                {
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46902);
                    Talk(7, pl->GetGUID());

                    me->AddDelayedEvent(4000, [this, pl]() -> void
                    {
                        Talk(8, pl->GetGUID());
                        me->DespawnOrUnsummon(3000);
                    });
                }
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == 1 && data == 1)
            {
                DoCast(193248);
                Talk(3);
                me->GetMotionMaster()->MoveJump(3814.16f, 2009.03f, 935.15f, 5, 5);
                me->AddDelayedEvent(3000, [this]() -> void
                {
                    Talk(4);
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46734);
                });

                me->AddDelayedEvent(7000, [this]() -> void
                {
                    me->GetMotionMaster()->MovePoint(1, 3848.98f, 1945.78f, 931.85f);
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };
};

// 103148
class npc_monk_chen_porter : public CreatureScript
{
public:
    npc_monk_chen_porter() : CreatureScript("npc_monk_chen_porter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_monk_chen_porterAI(creature);
    }

    struct npc_monk_chen_porterAI : ScriptedAI
    {
        npc_monk_chen_porterAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
        }

        bool _introDone;

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 2)
                    Talk(6);
                if (id == 4)
                    if (Creature* hait = me->FindNearestCreature(97778, 150.0f, true))
                        hait->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                if (id == 5)
                {
                    Talk(7);
                    if (Player* pl = me->FindNearestPlayer(100.0f))
                        pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46947);

                    me->AddDelayedEvent(3000, [this]() -> void
                    {
                        if (Creature* hait = me->FindNearestCreature(97778, 50.0f, true))
                            hait->AI()->Talk(10);
                    });

                    if (Player* pl = me->FindNearestPlayer(100.0f))
                    {
                        me->AddDelayedEvent(7000, [this, pl]() -> void
                        {
                            Talk(8, pl->GetGUID());
                        });

                        me->AddDelayedEvent(11000, [this, pl]() -> void
                        {
                            if (Creature* hait = me->FindNearestCreature(97778, 50.0f, true))
                                hait->AI()->Talk(11, pl->GetGUID());
                        });

                        me->AddDelayedEvent(15000, [this, pl]() -> void
                        {
                            if (Creature* hait = me->FindNearestCreature(97778, 50.0f, true))
                            {
                                hait->AI()->Talk(12, pl->GetGUID());
                            }
                        });

                        me->AddDelayedEvent(15000, [this, pl]() -> void
                        {
                            if (Creature* hait = me->FindNearestCreature(97778, 50.0f, true))
                            {
                                hait->AI()->Talk(13, pl->GetGUID());
                                hait->GetMotionMaster()->MovePath(9859006, false); // 5 8
                            }
                        });
                    }

                    me->AddDelayedEvent(16000, [this]() -> void
                    {
                        me->GetMotionMaster()->MovePoint(0, 3837.48f, 1729.83f, 946.42f);
                    });
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 50.0f) && who->GetPositionZ() <= 928.9f)
            {
                _introDone = true;
                Talk(2);
                if (Creature* morvat = me->FindNearestCreature(97811, 30.0f, true))
                    AttackStart(morvat);
            }

        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == 1 && data == 1)
            {
                Talk(3);
                if (Player* pl = me->FindNearestPlayer(100))
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46956);
                me->AddDelayedEvent(4000, [this]() -> void
                {
                    Talk(4);
                });

                me->AddDelayedEvent(5000, [this]() -> void
                {
                    std::list<Creature*> adds;
                    GetCreatureListWithEntryInGrid(adds, me, 98074, 70.0f);
                    if (!adds.empty())
                        for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                        {
                            (*itr)->GetMotionMaster()->MoveFollow(me, urand(1, 4), -PET_FOLLOW_ANGLE, MOTION_SLOT_IDLE);
                            (*itr)->AI()->Talk(0);
                        }
                });

                me->AddDelayedEvent(8000, [this]() -> void
                {
                    if (Player* pl = me->FindNearestPlayer(100))
                        Talk(5, pl->GetGUID());
                    if (Creature* li = me->FindNearestCreature(98074, 50.0f, true))
                        li->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE, MOTION_SLOT_IDLE);
                    me->GetMotionMaster()->MovePath(9859005, false); // 2 5
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (!UpdateVictim())
                return;


            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_monk_intro_scenario()
{
    new npc_master_hait();
    new npc_nine_czi();
    new npc_monk_chen_porter();
};
