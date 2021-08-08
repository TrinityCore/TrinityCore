/*
    http://uwow.biz
    Rogue: Kingslayers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "Kingslayers.h"
#include "GameObjectAI.h"

// 107979 108015
class npc_garona_halforcen : public CreatureScript
{
public:
    npc_garona_halforcen() : CreatureScript("npc_garona_halforcen") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 42504 || quest->GetQuestId() == 42627)
        { //49470 30966
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2381, player, NULL, *player))
                delete conversation;
            player->SetScenarioId(1123);
            player->TeleportTo(1620, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_garona_halforcenAI(creature);
    }

    struct npc_garona_halforcenAI : ScriptedAI
    {
        npc_garona_halforcenAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
        }

        bool introDone;

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetEntry() != 108015)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetExactDist2d(who) >= 20.0f)
                return;

            if (introDone)
                return;

            introDone = true;
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2361, who, NULL, *who))
                delete conversation;

            me->GetMotionMaster()->MovePoint(0, -9091.40f, 414.15f, 92.11f);
            me->RemoveAura(132653);

            me->AddDelayedEvent(15000, [this, who]() -> void
            {
                std::list<Creature*> adds;
                GetCreatureListWithEntryInGrid(adds, me, 98094, 70.0f);
                GetCreatureListWithEntryInGrid(adds, me, 108058, 70.0f);
                if (!adds.empty())
                    for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                    {
                        (*itr)->GetMotionMaster()->MovePoint(0, -8996.06f, 487.59f, 96.62f);
                        (*itr)->SetWalk(true);
                        (*itr)->DespawnOrUnsummon(6000);
                    }

                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2377, who, NULL, *who))
                    delete conversation;
            });

            me->AddDelayedEvent(30000, [this, who]() -> void
            {
                me->GetMotionMaster()->MovePoint(0, -9074.46f, 427.19f, 92.07f);
                me->SetWalk(true);
                me->DespawnOrUnsummon(4000);
                if (who)
                {
                    who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51418);
                    who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52672);
                }
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2384, who, NULL, *who))
                    delete conversation;

            });
        }

    };
};


// 108058 108059 108057 108056 108054 108107 108149 109966 108435 108399 108376 108177
class npc_kingslayers_small_events : public CreatureScript
{
public:
    npc_kingslayers_small_events() : CreatureScript("npc_kingslayers_small_events") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kingslayers_small_eventsAI(creature);
    }

    struct npc_kingslayers_small_eventsAI : ScriptedAI
    {
        npc_kingslayers_small_eventsAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            me->SetReactState(REACT_AGGRESSIVE);
            check = false;
            timer = 1000;
        }

        bool introDone;
        uint32 timer;
        bool check;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            {
                if (me->getVictim())
                    return;

                if (me->canStartAttack(who, false) && me->GetExactDist2d(who) <= 5.0f)
                    AttackStart(who);
            }

            if (!me->isMoving() && me->GetExactDist2d(who) <= 15.0f)
            {
                if (me->GetExactDist2d(who) <= 3.0f)
                    me->SetFacingToObject(who);
                else
                    me->SetOrientation(me->GetHomePosition().GetOrientation());
            }
            if (introDone)
                return;
            if (me->GetEntry() == 108399 && me->GetExactDist2d(who) <= 130.0f)
            {
                introDone = true;
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2483, who, NULL, *who))
                    delete conversation;

                me->AddDelayedEvent(5000, [this]() -> void
                {
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2476, me, NULL, *me))
                        delete conversation;
                    me->GetMotionMaster()->MovePoint(0, -8527.94f, 442.00f, 106.01f);

                });
                return;
            }

            if (me->GetExactDist2d(who) >= 14.0f)
                return;

            if (me->GetEntry() == 108054)
            {
                if (who->GetPositionZ() < 100.0f)
                    return;
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2395, who, NULL, *who))
                    delete conversation;
            }

            introDone = true;
            if (me->GetEntry() == 108057)
            {
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2384, who, NULL, *who))
                    delete conversation;
            }
            else if (me->GetEntry() == 108056)
            {
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2394, who, NULL, *who))
                    delete conversation;
            }
            else if (me->GetEntry() == 108107)
            {
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), (urand(1, 2) == 1 ? 2392 : 2408), who, NULL, *who))
                    delete conversation;
            }
            else if (me->GetEntry() == 108149)
            {
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2407, who, NULL, *who))
                    delete conversation;
            }
            else
            {
                if (urand(1, 2) == 2)
                    Talk(0);
            }
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            if (me->GetEntry() == 108177 && !check)
            {
                if (timer <= diff)
                {
                    if (Player* pl = me->FindNearestPlayer(15.0f))
                    {
                        check = true;
                        pl->AddAura(227061, pl);
                        pl->CastSpell(pl, 227061);
                    }
                    timer = 1000;
                }
                else
                    timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    };
};


// 214645
class spell_kingslayers_smoke_bomb : public SpellScriptLoader
{
public:
    spell_kingslayers_smoke_bomb() : SpellScriptLoader("spell_kingslayers_smoke_bomb") { }

    class spell_kingslayers_smoke_bomb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_kingslayers_smoke_bomb_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;
                if (caster->GetMapId() != 1620 || caster->GetAreaId() != 8228)
                    return;
                if (caster->GetExactDist2d(-8822.94f, 657.59f) >= 13.0f)
                    return;

                caster->CastSpell(caster, 214683);
                caster->CastSpell(caster, 214734);
                caster->ToPlayer()->PlayDirectSound(15003, NULL);

                if (Creature* targ = caster->FindNearestCreature(108057, 70.0f, true))
                {
                    targ->GetMotionMaster()->Clear();
                    targ->GetMotionMaster()->MovePoint(0, -8844.79f, 647.28f, 96.65f);
                }

                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2412, caster, NULL, *caster))
                    delete conversation;


                std::list<Creature*> adds;
                GetCreatureListWithEntryInGrid(adds, caster, 108159, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108155, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108178, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108158, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108177, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108161, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108179, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108157, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108160, 30.0f);
                GetCreatureListWithEntryInGrid(adds, caster, 108107, 30.0f);
                if (!adds.empty())
                    for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                    {
                        (*itr)->SetWalk(false);
                        (*itr)->CastSpell((*itr), 214304);
                        (*itr)->GetMotionMaster()->MoveRandom(3.0f);
                    }
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_kingslayers_smoke_bomb_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_kingslayers_smoke_bomb_SpellScript();
    }
};

// 251053
class go_kingslayers_door : public GameObjectScript
{
public:
    go_kingslayers_door() : GameObjectScript("go_kingslayers_door") { }

    struct go_kingslayers_doorAI : public GameObjectAI
    {
        go_kingslayers_doorAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            //           if (InstanceScript *script = player->GetInstanceScript())
            {
                //     if (script->getScenarionStep() == 5)
                {
                    if (Creature* garona = player->FindNearestCreature(108214, 60.0f, true))
                    {
                        garona->GetMotionMaster()->MovePoint(0, -8625.50f, 415.93f, 103.7f);
                        garona->RemoveAura(132653);
                    }
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51549);
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51654);
                }
            }
            return true;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_kingslayers_doorAI(go);
    }
};

// 108218
class npc_sister_althea_ebonlocke : public CreatureScript
{
public:
    npc_sister_althea_ebonlocke() : CreatureScript("npc_sister_althea_ebonlocke") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sister_althea_ebonlockeAI(creature);
    }

    struct npc_sister_althea_ebonlockeAI : ScriptedAI
    {
        npc_sister_althea_ebonlockeAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            introDone2 = false;
            checkdies = false;
            SetCanSeeEvenInPassiveMode(true);
        }

        bool introDone, introDone2, checkdies;
        uint32 timerforcheck;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 3000); // convers
            events.RescheduleEvent(EVENT_5, 27000); // 202839
            events.RescheduleEvent(EVENT_6, 15000); // 203109
            events.RescheduleEvent(EVENT_7, 25000); // 207673
            me->SetHomePosition(me->GetPosition());
            if (Creature* garona = me->FindNearestCreature(108214, 60.0f, true))
                garona->AI()->AttackStart(me);
        }

        void JustDied(Unit* who) override
        {
            if (Player* pl = me->FindNearestPlayer(100.0f))
                pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51613);
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2431, who, NULL, *who))
                delete conversation;

            if (Creature* garona = me->FindNearestCreature(108214, 60.0f, true))
            {
                garona->AddDelayedEvent(5000, [garona]() -> void
                {
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2432, garona, NULL, *garona))
                        delete conversation;
                    garona->DespawnOrUnsummon(5000);

                });
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetExactDist2d(who) <= 55.0f)
                if (!introDone)
                {
                    who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51549);
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2422, who, NULL, *who))
                        delete conversation;
                    introDone = true;
                }
            if (me->GetExactDist2d(who) <= 35.0f)
                if (!introDone2)
                {
                    introDone2 = true;
                    Conversation* conversation = new Conversation;
                    if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2424, who, NULL, *who))
                        delete conversation;

                    if (Creature* garona = me->FindNearestCreature(108214, 60.0f, true))
                    {
                        std::list<Creature*> adds;
                        GetCreatureListWithEntryInGrid(adds, me, 108216, 30.0f);
                        GetCreatureListWithEntryInGrid(adds, me, 108217, 30.0f);
                        if (!adds.empty())
                            for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                            {
                                (*itr)->AI()->AttackStart(garona);
                            }
                        timerforcheck = 1000;
                        checkdies = true;
                    }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkdies)
                if (timerforcheck <= diff)
                {
                    if (!me->FindNearestCreature(108216, 40.0f, true) && !me->FindNearestCreature(108217, 40.0f, true))
                    {
                        checkdies = false;
                        me->GetMotionMaster()->MoveJump(-8614.58f, 403.17f, 102.92f, 5, 5);
                        me->RemoveAura(214873);
                        if (Player* pl = me->FindNearestPlayer(50.0f))
                        {
                            me->AI()->AttackStart(pl);
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2425, pl, NULL, *pl))
                                delete conversation;
                        }
                    }
                    else
                        timerforcheck = 1000;
                }
                else
                    timerforcheck -= diff;

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
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2426, me, NULL, *me))
                            delete conversation;
                        events.RescheduleEvent(EVENT_2, 6000);
                    }
                    break;
                    case EVENT_2:
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2428, me, NULL, *me))
                            delete conversation;
                        events.RescheduleEvent(EVENT_3, 3000);
                    }
                    break;
                    case EVENT_3:
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2429, me, NULL, *me))
                            delete conversation;
                        events.RescheduleEvent(EVENT_4, 5000);
                    }
                    break;
                    case EVENT_4:
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2430, me, NULL, *me))
                            delete conversation;
                    }
                    break;
                    case EVENT_5:
                        DoCast(202839);
                        events.RescheduleEvent(EVENT_5, 27000); // 202839
                        break;
                    case EVENT_6:
                        DoCast(203109);
                        events.RescheduleEvent(EVENT_6, 15000); // 203109
                        break;
                    case EVENT_7:
                        DoCast(207673);
                        events.RescheduleEvent(EVENT_7, 25000); // 207673
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 107831
class npc_merlis_malagan : public CreatureScript
{
public:
    npc_merlis_malagan() : CreatureScript("npc_merlis_malagan") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_merlis_malaganAI(creature);
    }

    struct npc_merlis_malaganAI : ScriptedAI
    {
        npc_merlis_malaganAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            introDone = false;
            timer = 1000;
            SetCanSeeEvenInPassiveMode(true);
        }

        bool introDone;
        uint32 timer;
        uint32 convid;
        EventMap events;
        SummonList summons;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
        }

        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 5000); // 15 218359 + 218356 + summon
            events.RescheduleEvent(EVENT_3, 25000);
            convid = 2442;
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            DoZoneInCombat(summon, 150.0f);
        }

        void JustDied(Unit* who) override
        {
            summons.DespawnAll();
            if (Creature* oldgarona = me->FindNearestCreature(108222, 60.0f, true))
                oldgarona->DespawnOrUnsummon();
            if (Creature* garona = me->SummonCreature(108222, -8310.60f, 284.40f, 156.83f))
            {
                garona->AI()->DoAction(true);
                garona->SetVisible(true);
            }
            if (Player* pl = who->ToPlayer())
            {
                pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51615);
            }
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2448, who, NULL, *who))
                delete conversation;

            std::list<Creature*> adds;
            GetCreatureListWithEntryInGrid(adds, me, 108397, 70.0f);
            if (!adds.empty())
                for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                {
                    (*itr)->DespawnOrUnsummon();
                }
        }

        /* void MoveInLineOfSight(Unit* who)
         {

             if (who->GetTypeId() != TYPEID_PLAYER)
                 return;

             if ((me->GetExactDist2d(who) <= 67.0f) && !introDone)
             {
                 introDone = true;
                 Conversation* conversation = new Conversation;
                 if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2484, who, NULL, *who))
                     delete conversation;

                 who->AddDelayedEvent(5000, [who]() -> void
                 {
                     who->CastSpell(who, 214942);
                     if(Creature* add = who->FindNearestCreature(108333, 50.0f))
                         add->DespawnOrUnsummon();
                     if(Creature* add = who->FindNearestCreature(64367, 50.0f))
                         add->DespawnOrUnsummon();
                     who->ToPlayer()->TeleportTo(1620, -8342.62f, 271.15f, 155.34f, 0.0f);
                     who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51614);
                 });
             }

         } */

        void UpdateAI(uint32 diff) override
        {
            if (!introDone)
            {
                if (timer <= diff)
                {
                    if (Player* who = me->FindNearestPlayer(70.0f))
                    {
                        introDone = true;
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2484, who, NULL, *who))
                            delete conversation;

                        who->AddDelayedEvent(5000, [who]() -> void
                        {
                            who->CastSpell(who, 214942);
                            if (Creature* add = who->FindNearestCreature(108333, 50.0f))
                                add->DespawnOrUnsummon();
                            if (Creature* add = who->FindNearestCreature(64367, 50.0f))
                                add->DespawnOrUnsummon();
                            who->ToPlayer()->TeleportTo(1620, -8342.62f, 271.15f, 155.34f, 0.0f);
                            who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51614);
                        });
                    }

                    timer = 1000;
                }
                else
                    timer -= diff;
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
                        DoCast(218359);
                        events.RescheduleEvent(EVENT_1, 18000);
                        events.RescheduleEvent(EVENT_2, 4000);
                        if (convid != 2448)
                        {
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), convid, me, NULL, *me))
                                delete conversation;
                            ++convid;
                        }
                        break;
                    case EVENT_2:
                        DoCast(218356);
                        if (convid != 2448)
                        {
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), convid, me, NULL, *me))
                                delete conversation;
                            ++convid;
                        }
                        break;
                    case EVENT_3:
                        for (int i = 0; i < 6; ++i)
                        {
                            if (Creature* add = me->SummonCreature(108324, -8315.46f, 293.38f, 159.24f))
                            {
                                add->GetMotionMaster()->MoveJump(me->GetPositionX() + irand(-5, 5), me->GetPositionY() + irand(-5, 5), me->GetPositionZ(), 5, 5);
                                add->CastSpell(add, 158342);
                            }
                            if (convid != 2448)
                            {
                                Conversation* conversation = new Conversation;
                                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), convid, me, NULL, *me))
                                    delete conversation;
                                ++convid;
                            }
                        }
                        events.RescheduleEvent(EVENT_3, 25000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 108222
class npc_garona_halforcen_outro : public CreatureScript
{
public:
    npc_garona_halforcen_outro() : CreatureScript("npc_garona_halforcen_outro") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_garona_halforcen_outroAI(creature);
    }

    struct npc_garona_halforcen_outroAI : ScriptedAI
    {
        npc_garona_halforcen_outroAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
            SetCanSeeEvenInPassiveMode(true);
            me->SetVisible(true);
        }

        bool introDone;
        uint32 convid;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void DoAction(int32 const action) override
        {
            me->RemoveAura(214940);
            me->GetMotionMaster()->MovePoint(0, -8316.88f, 283.96f, 156.83f);
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2449, me, NULL, *me))
                delete conversation;
            events.RescheduleEvent(EVENT_1, 23000);
        }

        void UpdateAI(uint32 diff) override
        {

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2450, me, NULL, *me))
                            delete conversation;
                        events.RescheduleEvent(EVENT_2, 11000);
                    }
                    break;
                    case EVENT_2:
                        me->SummonCreature(108325, -8318.08f, 283.807f, 156.916f, 6.26344f);
                        me->SummonGameObject(251107, -8318.08f, 283.807f, 156.833f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, DAY);
                        me->GetMotionMaster()->MovePoint(0, -8312.67f, 284.65f, 156.83f);
                        break;
                }
            }
        }

    };
};

// 251107
class go_the_kingslayers : public GameObjectScript
{
public:
    go_the_kingslayers() : GameObjectScript("go_the_kingslayers") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target/* && state == GO_ACTIVATED*/)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 51616);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1123, 1);
                // if (Creature* trigger = go->FindNearestCreature(108325, 20.0f))
                    // trigger->DespawnOrUnsummon();

                target->ToPlayer()->KilledMonsterCredit(114508);
                target->ToPlayer()->KilledMonsterCredit(48548);
                target->ToPlayer()->KilledMonsterCredit(48528);
                if (Creature* outro = target->SummonCreature(108367, -8345.60f, 267.80f, 155.34f, 0.69f))
                {
                    outro->AddDelayedEvent(7000, [outro, target]() -> void
                    {
                        outro->GetMotionMaster()->MovePoint(0, -8334.08f, 277.72f, 156.83f);
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2452, target, NULL, *target))
                            delete conversation;
                    });

                    outro->AddDelayedEvent(13000, [outro, target]() -> void
                    {
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 2453, target, NULL, *target))
                            delete conversation;
                    });

                    outro->AddDelayedEvent(27000, [outro]() -> void
                    {
                        outro->GetMotionMaster()->MovePoint(0, -8332.05f, 274.51f, 156.83f);
                        if (GameObject* doors = outro->FindNearestGameObject(251106, 60.0f))
                            doors->SetPhaseMask(2, true); // hide

                        if (Creature* garona = outro->FindNearestCreature(108222, 70.0f, true))
                        {
                            garona->GetMotionMaster()->MovePoint(0, -8426.63f, 213.47f, 155.34f);
                            garona->DespawnOrUnsummon(15000);
                        }
                    });
                }
                
                if (!target->ToPlayer()->HasItemCount(128870, 1))
                {
                    target->ToPlayer()->AddItem(128870, 1);
                    target->CastSpell(target, 215112, true);  // on loot
                }
            }
        }
    }
};

void AddSC_Kingslayers()
{
    new npc_garona_halforcen();
    new npc_kingslayers_small_events();

    new spell_kingslayers_smoke_bomb();
    new go_kingslayers_door();
    new npc_sister_althea_ebonlocke();
    new npc_merlis_malagan();
    new npc_garona_halforcen_outro();
    new go_the_kingslayers();
};
