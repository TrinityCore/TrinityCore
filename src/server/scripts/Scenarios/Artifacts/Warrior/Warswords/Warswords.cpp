/*
    http://uwow.biz
    Warrior: Warswords
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

// 245188
class go_mystic_bonfire : public GameObjectScript
{
public:
    go_mystic_bonfire() : GameObjectScript("go_mystic_bonfire") { }

    struct go_mystic_bonfireAI : public GameObjectAI
    {
        go_mystic_bonfireAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            if (InstanceScript* script = go->GetInstanceScript())
                if (script->getScenarionStep() == 0)
                {
                    // player->CastSpell(player, 198513);
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47272);
                    // delete smoge
                    std::list<GameObject*> goList;
                    go->GetGameObjectListWithEntryInGrid(goList, 244751, 45.0f);
                    if (!goList.empty())
                        for (std::list<GameObject*>::const_iterator itr = goList.begin(); itr != goList.end(); ++itr)
                            (*itr)->SetPhaseMask(4, true);
                    return true;
                }
            return false;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_mystic_bonfireAI(go);
    }
};

// 244940
class go_prison_runestone : public GameObjectScript
{
public:
    go_prison_runestone() : GameObjectScript("go_prison_runestone") { }

    struct go_prison_runestoneAI : public GameObjectAI
    {
        go_prison_runestoneAI(GameObject* go) : GameObjectAI(go)
        {
            check = false;
        }

        bool check;

        bool GossipHello(Player* player) override
        {
            if (check)
                return false;

            if (InstanceScript* script = go->GetInstanceScript())
                if (script->getScenarionStep() == 3)
                {
                    check = true;
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46970);
                    std::list<Creature*> adds;
                    GetCreatureListWithEntryInGrid(adds, player, 98524, 10.0f);
                    if (!adds.empty())
                        for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                            (*itr)->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, 10);
                    return true;
                }
            return false;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_prison_runestoneAI(go);
    }
};

// 98007
class npc_vigfus_bladewind : public CreatureScript
{
public:
    npc_vigfus_bladewind() : CreatureScript("npc_vigfus_bladewind") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vigfus_bladewindAI(creature);
    }

    struct npc_vigfus_bladewindAI : ScriptedAI
    {
        npc_vigfus_bladewindAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

        EventMap events;
        SummonList summons;
        uint32 count_adds;
        bool phase, check_first_rephase;

        void Reset() override
        {
            phase = false;
            check_first_rephase = false;

            events.Reset();
            summons.DespawnAll();
            count_adds = 0;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* who) override
        {
            Talk(0);
            events.RescheduleEvent(EVENT_1, 7000); // 195574
            events.RescheduleEvent(EVENT_2, 10000); // 195575 23 + after 195996
            events.RescheduleEvent(EVENT_3, 13000); // 195996
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->CastSpell(summon, 197852);
            summon->GetMotionMaster()->MoveRandom(10.0f);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == 99609)
            {
                count_adds++;
                if (count_adds >= 2)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_AGGRESSIVE);
                    count_adds = 0;
                    me->RemoveAura(195996);
                }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (check_first_rephase)
            {
                check_first_rephase = false;
                Talk(7);
                me->RemoveAura(128264);
                std::list<Creature*> adds;
                GetCreatureListWithEntryInGrid(adds, me, 98795, 30.0f);
                if (!adds.empty())
                    for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                    {
                        (*itr)->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        (*itr)->AI()->AttackStart(attacker);
                    }
                me->GetMotionMaster()->MovePoint(2, 3514.32f, 1800.86f, 0.6f);
                me->DespawnOrUnsummon(7000);
            }

            if (me->HealthBelowPct(50) && !phase)
            {
                Talk(5);
                phase = true;
                if (Player* pl = me->FindNearestPlayer(100.0f))
                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46982);
                me->StopAttack();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                me->GetMotionMaster()->MovePoint(1, 3444.66f, 1703.69f, 0.43f);
                events.Reset();
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                DoCast(128264);
                check_first_rephase = true;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
            }
        }


        void UpdateAI(uint32 diff) override
        {

            if (!UpdateVictim())
                return;

            if (me->HasAura(195996))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(195574);
                        events.RescheduleEvent(EVENT_1, 11000); // 195574
                        break;
                    case EVENT_2:
                        DoCast(195575);
                        events.RescheduleEvent(EVENT_2, 23000); // 195575 23 + after 195996
                        break;
                    case EVENT_3:
                        DoCast(195996);
                        me->StopAttack();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        me->SetReactState(REACT_PASSIVE);
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            me->SummonCreature(99609, me->GetPositionX() + irand(-5, 5), me->GetPositionY() + irand(-5, 5), me->GetPositionZ(), 0);
                        }
                        events.RescheduleEvent(EVENT_3, 51000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


// 98602
class npc_vigfus_bladewind_last : public CreatureScript
{
public:
    npc_vigfus_bladewind_last() : CreatureScript("npc_vigfus_bladewind_last") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vigfus_bladewind_lastAI(creature);
    }

    struct npc_vigfus_bladewind_lastAI : ScriptedAI
    {
        npc_vigfus_bladewind_lastAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            introDone = false;
        }

        EventMap events;
        SummonList summons;
        uint32 count_adds;

        bool phase1, phase2, introDone;

        void Reset() override
        {
            phase1 = false;
            phase2 = false;
            events.Reset();
            summons.DespawnAll();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);
            count_adds = 0;
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 7000); // 195574
            events.RescheduleEvent(EVENT_2, 10000); // 195575 23 + after 195996
            events.RescheduleEvent(EVENT_3, 13000); // 195996
            events.RescheduleEvent(EVENT_4, 54000); // 196135
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->CastSpell(summon, 197852);
            summon->GetMotionMaster()->MoveRandom(10.0f);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == 99609)
            {
                count_adds++;
                if (count_adds >= 2)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveAura(195996);
                    count_adds = 0;
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetExactDist2d(who) <= 40.0f)
                if (!introDone)
                {
                    who->CreateConversation(843);
                    introDone = true;
                    if (Creature* targ = me->FindNearestCreature(99043, 100.0f, true))
                        targ->CastSpell(targ, 195062);
                    me->AddDelayedEvent(8000, [this]() -> void
                    {
                        me->RemoveAura(205424);
                        if (Player* pl = me->FindNearestPlayer(100.0f, true))
                            AttackStart(pl);
                    });
                }
        }

        void JustDied(Unit* who) override
        {
            Talk(2);
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46987);
                who->CreateConversation(848);
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (me->HealthBelowPct(15) && !phase1)
            {
                Talk(0);
                phase1 = true;
            }

            if (me->HealthBelowPct(7) && !phase2)
            {
                Talk(1);
                phase2 = true;
                me->StopAttack();
                me->GetMotionMaster()->MovePoint(0, 3515.14f, 1800.60f, 0.54f);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasAura(195996))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(195574);
                        events.RescheduleEvent(EVENT_1, 11000); // 195574
                        break;
                    case EVENT_2:
                        DoCast(195575);
                        events.RescheduleEvent(EVENT_2, 23000); // 195575 23 + after 195996
                        break;
                    case EVENT_3:
                        DoCast(195996);
                        me->StopAttack();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        me->SetReactState(REACT_PASSIVE);
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            me->SummonCreature(99609, me->GetPositionX() + irand(-5, 5), me->GetPositionY() + irand(-5, 5), me->GetPositionZ(), 0);
                        }
                        events.RescheduleEvent(EVENT_3, 51000);
                        break;
                    case EVENT_4:
                        DoCast(196135);
                        events.RescheduleEvent(EVENT_4, 53000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 248832
class go_art_warswords : public GameObjectScript
{
public:
    go_art_warswords() : GameObjectScript("go_art_warswords") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47017);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 944, 1);
                if (Creature* trigger = go->FindNearestCreature(98678, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128908, 1))
                {
                    target->ToPlayer()->AddItem(128908, 1);
                    target->CastSpell(target, 205443, true);
                }

                target->ToPlayer()->KilledMonsterCredit(98033);
                target->CreateConversation(849);
                target->AddDelayedEvent(12000, [target]() -> void
                {
                    target->CastSpell(target, 192085);
                    target->ToPlayer()->KilledMonsterCredit(103739);
                });
            }
        }
    }
};

void AddSC_Warswords()
{
    new go_mystic_bonfire();
    new go_prison_runestone();

    new npc_vigfus_bladewind();
    new npc_vigfus_bladewind_last();

    new go_art_warswords();
};