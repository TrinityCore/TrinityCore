/*
    http://uwow.biz
    Rogue: Devourer
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

// 105464
class npc_valzuun : public CreatureScript
{
public:
    npc_valzuun() : CreatureScript("npc_valzuun") { }

    bool OnQuestAccept(Player* player, Creature* me, Quest const* quest) override
    {
        if (quest->GetQuestId() == 41924)
        {
            player->SetScenarioId(1078);
            if (Creature* targ = me->SummonCreature(105488, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
            {
                ObjectGuid guid = player->GetGUID();
                targ->AddPlayerInPersonnalVisibilityList(guid);
                targ->AddDelayedEvent(1000, [targ]() -> void
                {
                    targ->AI()->Talk(0);
                    targ->SetWalk(true);
                    targ->GetMotionMaster()->MovePoint(0, -848.85f, 4405.71f, 716.94f);
                });

                targ->AddDelayedEvent(4000, [targ]() -> void
                {
                    targ->AI()->Talk(1);
                    targ->CastSpell(targ, 209056);
                });

                targ->AddDelayedEvent(11500, [targ, guid]() -> void
                {
                    targ->AI()->Talk(2);
                    targ->GetMotionMaster()->MovePoint(0, -851.50f, 4403.76f, 716.94f);
                    if (GameObject* go = targ->SummonGameObject(248901, -846.23f, 4409.01f, 716.97f, 1.8675f, 0.0f, 0.0f, 0.0f, 0.0f, 300))
                        go->AddPlayerInPersonnalVisibilityList(guid);
                    targ->DespawnOrUnsummon(3000);
                });
            }
        }

        return true;
    }

};

// 105537 105539 105538 105541
class npc_devourer_small_events : public CreatureScript
{
public:
    npc_devourer_small_events() : CreatureScript("npc_devourer_small_events") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_devourer_small_eventsAI(creature);
    }

    struct npc_devourer_small_eventsAI : ScriptedAI
    {
        npc_devourer_small_eventsAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            SetCanSeeEvenInPassiveMode(true);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        bool introDone;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            {
                if (me->getVictim())
                    return;

                if (me->canStartAttack(who, false) && me->GetExactDist2d(who) <= 6.0f)
                    AttackStart(who);
            }

            if (me->GetExactDist2d(who) >= 15.0f)
                return;

            if (!me->isMoving())
            {
                if (me->GetExactDist2d(who) <= 7.0f)
                    me->SetFacingToObject(who);
                else
                    me->SetOrientation(me->GetHomePosition().GetOrientation());
            }
            if (introDone)
                return;

            if (me->GetEntry() != 105538)
                Talk(0);
            introDone = true;
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    };
};


// 105536 first
class npc_akaari_shadowgore : public CreatureScript
{
public:
    npc_akaari_shadowgore() : CreatureScript("npc_akaari_shadowgore") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_akaari_shadowgoreAI(creature);
    }

    struct npc_akaari_shadowgoreAI : ScriptedAI
    {
        npc_akaari_shadowgoreAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            SetCanSeeEvenInPassiveMode(true);
        }

        bool introDone;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            Talk(0);
            events.RescheduleEvent(EVENT_1, 12000); // Clons 209231 and talk 
        }


        void MoveInLineOfSight(Unit* who) override
        {

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetExactDist2d(who) <= 25.0f)
                if (!introDone)
                {
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1864, who, NULL, *who))
                        delete conversation;
                    introDone = true;
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
                        Talk(1);
                        DoCast(209231);
                        events.RescheduleEvent(EVENT_2, 11000);
                        break;
                    case EVENT_2:
                        Talk(2);
                        DoCast(209238);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        if (Creature* targ = me->SummonCreature(105540, me->GetPositionX() + 3.0f, me->GetPositionY() + 3.0f, me->GetPositionZ()))
                        {
                            targ->CastSpell(targ, 189170);
                            me->AddDelayedEvent(5000, [this, targ]() -> void
                            {
                                Talk(3);
                                if (Player* pl = me->FindNearestPlayer(40.0f))
                                    targ->CastSpell(pl, 209264);
                            });

                            if (Player* pl = me->FindNearestPlayer(40.0f))
                            {
                                pl->AddDelayedEvent(10000, [pl]() -> void
                                {
                                    pl->TeleportTo(1607, 1847.77f, 1259.92f, 57.09f, 0.0f);
                                    pl->CastSpell(pl, 211686); // disarm
                                    pl->CastSpell(pl, 211684); // stun
                                    pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50261);
                                });
                            }
                            targ->DespawnOrUnsummon(9000);

                            me->DespawnOrUnsummon(10000);

                        }
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 249809 248992 249390
class go_devourer_misc : public GameObjectScript
{
public:
    go_devourer_misc() : GameObjectScript("go_devourer_misc") { }

    struct go_devourer_miscAI : public GameObjectAI
    {
        go_devourer_miscAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            if (player->HasItemCount(136802, 1))
            {
                uint32 criteria = 0;
                switch (go->GetEntry())
                {
                    case 249809:
                        criteria = 50908;
                        player->RemoveAura(211684);
                        break;
                    case 249390:
                        criteria = 50536;
                        break;
                }
                if (criteria != 0)
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, criteria);

                go->SetPhaseMask(4, true); // hide
                if (go->GetEntry() == 249390)
                {
                    if (GameObject* doors = go->FindNearestGameObject(249391, 10.0f))
                        doors->SetPhaseMask(4, true);
                    player->DestroyItemCount(136802, 1, true); // last go. del quest item ?

                    std::list<Creature*> adds;
                    GetCreatureListWithEntryInGrid(adds, player, 105538, 90.0f);
                    GetCreatureListWithEntryInGrid(adds, player, 105537, 90.0f);
                    if (!adds.empty())
                        for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                        {
                            if ((*itr)->HasAura(209349))
                            {
                                (*itr)->GetMotionMaster()->MoveRandom(15.0f);
                                (*itr)->DespawnOrUnsummon(5000);
                                if ((*itr)->GetEntry() == 105538)
                                    (*itr)->AI()->Talk(0);

                            }
                        }
                }
                return true;
            }
            return false;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_devourer_miscAI(go);
    }
};

// 105542
class npc_devourer_zirus : public CreatureScript
{
public:
    npc_devourer_zirus() : CreatureScript("npc_devourer_zirus") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_devourer_zirusAI(creature);
    }

    struct npc_devourer_zirusAI : ScriptedAI
    {
        npc_devourer_zirusAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            introDone = false;
            SetCanSeeEvenInPassiveMode(true);
        }

        bool introDone;
        EventMap events;
        SummonList summons;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 8000); // 194519 
            events.RescheduleEvent(EVENT_2, 11000);
        }

        void JustDied(Unit* who) override
        {
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1890, who, NULL, *who))
                delete conversation;
            if (who->GetTypeId() == TYPEID_PLAYER)
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50298);

            std::list<GameObject*> doors;
            GetGameObjectListWithEntryInGrid(doors, me, 248983, 100.0f);
            GetGameObjectListWithEntryInGrid(doors, me, 248984, 100.0f);
            GetGameObjectListWithEntryInGrid(doors, me, 248910, 100.0f);
            GetGameObjectListWithEntryInGrid(doors, me, 249028, 100.0f);
            if (!doors.empty())
                for (std::list<GameObject*>::iterator itr = doors.begin(); itr != doors.end(); ++itr)
                {
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
                    (*itr)->SetPhaseMask(4, true);
                }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->CastSpell(summon, 210161, false);
            summon->GetMotionMaster()->MoveRotate(20000, ROTATE_DIRECTION_RIGHT);
        }

        void MoveInLineOfSight(Unit* who) override
        {

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetExactDist2d(who) <= 25.0f)
                if (!introDone)
                {
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1884, who, NULL, *who))
                        delete conversation;
                    introDone = true;
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
                        DoCast(194519);
                        events.RescheduleEvent(EVENT_1, 8000);
                        break;
                    case EVENT_2:
                        float radius = 5.0f; // растояние от кастера
                        float coneAngle = 0.0f; // угол куда поставится моб с АТ
                        Position position;
                        me->GetNearPosition(position, radius, coneAngle);
                        me->CastSpell(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ(), 210157, true);
                        coneAngle = 2.0f; // угол куда поставится моб с АТ
                        me->GetNearPosition(position, radius, coneAngle);
                        me->CastSpell(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ(), 210157, true);
                        coneAngle = 4.0f; // угол куда поставится моб с АТ
                        me->GetNearPosition(position, radius, coneAngle);
                        me->CastSpell(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ(), 210157, true);
                        events.RescheduleEvent(EVENT_2, 11000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 105660 second
class npc_akaari_shadowgore_last : public CreatureScript
{
public:
    npc_akaari_shadowgore_last() : CreatureScript("npc_akaari_shadowgore_last") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_akaari_shadowgore_lastAI(creature);
    }

    struct npc_akaari_shadowgore_lastAI : ScriptedAI
    {
        npc_akaari_shadowgore_lastAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            SetCanSeeEvenInPassiveMode(true);
            convers = 1943;
            instance = me->GetInstanceScript();
            checktimer = 1000;
        }

        InstanceScript* instance;
        bool introDone;
        EventMap events;
        uint32 convers;
        uint32 checktimer;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 42000);
            events.RescheduleEvent(EVENT_2, 11000);
            events.RescheduleEvent(EVENT_3, 14000);
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1942, who, NULL, *who))
                delete conversation;
            convers = 1943;
        }

        void JustDied(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1947, who, NULL, *who))
                delete conversation;

            who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50300);
        }

        /* void MoveInLineOfSight(Unit* who)
         {

             if (who->GetTypeId() != TYPEID_PLAYER)
                 return;

             if (me->GetExactDist2d(who) <= 25.0f)
                 if(!introDone)
                 {
                     who->CastSpell(who, 209626);
                     who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50404);
                     who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50299);
                     introDone = true;
                 }
         }
         */
        void UpdateAI(uint32 diff) override
        {
            if (instance->getScenarionStep() == 4)
            {
                if (!introDone)
                {
                    if (checktimer <= diff)
                    {
                        if (Player* pl = me->FindNearestPlayer(25.0f, true))
                        {
                            if (pl->GetPositionZ() < 91.0f)
                                return;

                            pl->CastSpell(pl, 209626);
                            pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50404);
                            pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50299);
                            introDone = true;
                        }
                        checktimer = 1000;
                    }
                    else checktimer -= diff;
                }
            }

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
                        DoCast(206866);
                        events.RescheduleEvent(EVENT_1, 42000);
                        break;
                    case EVENT_2:
                        DoCast(224990);
                        events.RescheduleEvent(EVENT_2, 11000);
                        break;
                    case EVENT_3:
                        DoCast(209233);
                        convers++;
                        if (convers < 1947)
                        {
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), convers, me, NULL, *me))
                                delete conversation;
                        }
                        events.RescheduleEvent(EVENT_3, 14000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};


//249347
class go_art_devourer : public GameObjectScript
{
public:
    go_art_devourer() : GameObjectScript("go_art_devourer") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50301); //Step 4
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1078, 1);
                if (Creature* trigger = go->FindNearestCreature(105843, 10.0f))
                    trigger->DespawnOrUnsummon(1000);

                if (!target->ToPlayer()->HasItemCount(128476, 1))
                {
                    target->ToPlayer()->AddItem(128476, 1);
                    target->CastSpell(target, 209816, true);
                }

                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1948, target, NULL, *target))
                    delete conversation;
            }
        }
    }
};


void AddSC_Devourer()
{
    new npc_valzuun();
    new npc_devourer_small_events();
    new npc_akaari_shadowgore();
    new go_devourer_misc();
    new npc_devourer_zirus();
    new npc_akaari_shadowgore_last();

    new go_art_devourer();
};
