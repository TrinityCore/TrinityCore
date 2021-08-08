/*
    http://uwow.biz
    Rogue: Dreadblades
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "Dreadblades.h"

// 102120
class npc_admiral_tethys : public CreatureScript
{
public:
    npc_admiral_tethys() : CreatureScript("npc_admiral_tethys") { }
    
    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 40849) 
            sCreatureTextMgr->SendChat(creature, TEXT_GENERIC_0, player->GetGUID());
        return true;
    }
    
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        if (player->GetQuestStatus(40849) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, 202180);  //scene
            player->SetScenarioId(1012);
            player->CastSpell(player, 201475); // to scenario
        }            

        return true;
    }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_admiral_tethysAI(creature);
    }
    
    struct npc_admiral_tethysAI : ScriptedAI
    {
        npc_admiral_tethysAI(Creature* creature) : ScriptedAI(creature) 
        {
            timer = 30000;
        }
        
        GuidSet m_player_for_event;
        uint32 timer;
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !me->IsWithinDistInMap(who, 30.0f))
                return;
            
            if (who->ToPlayer()->GetQuestStatus(40847) == QUEST_STATUS_INCOMPLETE)
            {
                GuidSet::iterator itr = m_player_for_event.find(who->GetGUID());
                if (itr != m_player_for_event.end())
                    return;

                m_player_for_event.insert(who->GetGUID());
                who->ToPlayer()->CompleteQuest(40847);
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if(timer <= diff)  
            {
                m_player_for_event.clear();
                timer = 30000;
            } else
                timer -= diff;
        }
    };
};

// 102179 102212
class npc_admiral_tethys_scenario : public CreatureScript
{
public:
    npc_admiral_tethys_scenario() : CreatureScript("npc_admiral_tethys_scenario") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_admiral_tethys_scenarioAI(creature);
    }
    
    struct npc_admiral_tethys_scenarioAI : ScriptedAI
    {
        npc_admiral_tethys_scenarioAI(Creature* creature) : ScriptedAI(creature) 
        { 
            intro = false;
        }
        
        bool intro;
        EventMap events;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !me->IsWithinDistInMap(who, 30.0f))
                return;
            if (me->GetEntry() != 102179)
                return;
            
            if (intro)
                return;
            
            intro = true;
            events.RescheduleEvent(EVENT_2, 5000);
        }
        
        void IsSummonedBy(Unit* summoner) override
        {
            if (me->GetEntry() != 102212)
                return;
            events.RescheduleEvent(EVENT_1, 3000);
        }
        
        void UpdateAI (uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        {
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1122, me, NULL, *me))
                                delete conversation;
                            me->GetMotionMaster()->MovePoint(0, -1210.06f, 5803.85f, 19.17f);
                        }
                        break;   
                   case EVENT_2:
                        {
                            Conversation* conversation1 = new Conversation;
                            if (!conversation1->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1114, me, NULL, *me))
                                delete conversation1;
                            me->SetByteValue(UNIT_FIELD_BYTES_1, 0, 0);
                            me->SetAnimKitId(0);
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(0, -1306.90f, 5875.40f, 17.20f);
                        }
                        break;
                }
            }
        }
    };
};

// 102185
class npc_first_helper_degauz: public CreatureScript
{
public:
    npc_first_helper_degauz() : CreatureScript("npc_first_helper_degauz") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_first_helper_degauzAI(creature);
    }
    
    struct npc_first_helper_degauzAI : ScriptedAI
    {
        npc_first_helper_degauzAI(Creature* creature) : ScriptedAI(creature) 
        { 
            intro = false;
            healthPct = 90;
        }
        
        bool intro;
        EventMap events;
        uint32 healthPct;
        
        void Reset() override
        {
            events.Reset();
            healthPct = 90;
        }
        
        void EnterCombat(Unit* who) override
        {
            Talk(1);
            healthPct = 90;
            events.RescheduleEvent(EVENT_1, 5000);
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !me->IsWithinDistInMap(who, 30.0f))
                return;
            
            if (intro)
                return;
            
            intro = true;
            Talk(0);
        }
        
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
                return;
            
            if (me->HealthBelowPct(healthPct) && healthPct >= 30)
            {
                switch(healthPct)
                {
                    case 90:
                        Talk(2);
                        break;
                    case 60:
                        Talk(3);
                        DoCast(208007);
                        break;
                    case 30:
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_PASSIVE);
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1121, attacker, NULL, *attacker))
                            delete conversation;
                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePoint(0, -1180.69f, 5868.85f, 1.83f);
                        me->DespawnOrUnsummon(10000);
                        me->RemoveAura(208007);
                        std::list<Creature*> adds;
                        GetCreatureListWithEntryInGrid(adds, me, 102192, 100.0f);
                        GetCreatureListWithEntryInGrid(adds, me, 102227, 100.0f);
                        GetCreatureListWithEntryInGrid(adds, me, 102194, 100.0f);
                        if (!adds.empty())
                        for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                        {
                            (*itr)->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            (*itr)->SetWalk(false);
                            (*itr)->GetMotionMaster()->MovePoint(0, -1180.69f, 5868.85f, 1.83f);
                            (*itr)->SetReactState(REACT_PASSIVE);
                            (*itr)->DespawnOrUnsummon(10000);
                          
                        }
                        me->SummonCreature(102212, -1215.19f, 5805.68f, 19.41f, 5.68f);
                        me->SummonCreature(102181, -1200.68f, 5822.54f, 10.81f, 1.85f);
                        me->SummonCreature(102180, -1193.33f, 5828.64f, 5.50f, 1.41f);
                        events.Reset();
                        attacker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48449);
                        break;
                }
                healthPct -= 30;
            }
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
                        DoCast(208005);
                        events.RescheduleEvent(EVENT_1, urand(9000, 12000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// 102192 102194 102249
class npc_small_events_dreadblades: public CreatureScript
{
public:
    npc_small_events_dreadblades() : CreatureScript("npc_small_events_dreadblades") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_small_events_dreadbladesAI(creature);
    }
    
    struct npc_small_events_dreadbladesAI : ScriptedAI
    {
        npc_small_events_dreadbladesAI(Creature* creature) : ScriptedAI(creature) 
        { 
            intro = false;
            eventcheck = false;
        }
        
        bool intro;
        bool eventcheck;
        uint32 eventtimer;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !me->IsWithinDistInMap(who, 30.0f))
                return;
            
            if (intro)
                return;
            
            intro = true;
            if (me->GetEntry() == 102355)
            {
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1387, who, NULL, *who))
                    delete conversation;
                return;
            }
            if (me->GetEntry() != 102249)
            {
                uint8 chance = urand(1, 3);
                if (chance == 3) // random
                    Talk(0);
            }
            else
            {
                Talk(0, who->GetGUID());
                me->SetFacingToObject(who);
                eventtimer = 6000;
                eventcheck = true;
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48489);
            }
        } 
        
        void UpdateAI(uint32 diff) override
        {
            if (eventcheck)
            {
                if (eventtimer <= diff)
                {
                    eventcheck = false;
                    Talk(1);
                    if(Creature* face = me->FindNearestCreature(102256, 50.0f, true))
                        me->SetFacingToObject(face);
                    if(Creature* boss = me->FindNearestCreature(102239, 50.0f, true))
                        boss->AI()->DoAction(1);
                    me->DespawnOrUnsummon(5000);
                }
                else
                    eventtimer -= diff;
            }
        }
    };
};

// 102239
class npc_lord_brinebeard: public CreatureScript
{
public:
    npc_lord_brinebeard() : CreatureScript("npc_lord_brinebeard") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lord_brinebeardAI(creature);
    }
    
    struct npc_lord_brinebeardAI : ScriptedAI
    {
        npc_lord_brinebeardAI(Creature* creature) : ScriptedAI(creature) 
        { 
            intro = false;
            outro = false;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetReactState(REACT_PASSIVE);
        }
        
        bool intro;
        bool outro;
        uint32 eventtimer;
        uint8 eventphase;
        EventMap events;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            Talk(1);
            events.RescheduleEvent(EVENT_1, 1000);
            events.RescheduleEvent(EVENT_2, 15000);
        }
        
        void JustDied(Unit* who) override
        {
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1147, who, NULL, *who))
                delete conversation;
        }
        
        void DoAction(const int32 action) override
        {
            if (action == 1)
            {
                intro = true;
                eventtimer = 5000;
                eventphase = 1;
            }
        }
        
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
                return;
            
            if (me->HealthBelowPct(30) && !outro)
            {
                outro = true;
                attacker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48531);
                if (Creature* trigger = me->FindNearestCreature(95464, 150.0f))
                {
                    trigger->CastSpell(me, 202211); // visual die
                    events.RescheduleEvent(EVENT_3, 3000);
                }
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (intro)
            {
                if (eventtimer <= diff)
                {
                    if (eventphase == 1)
                    {
                        if(Creature* sayer = me->FindNearestCreature(102256, 50.0f, true))
                        {
                            sayer->AI()->Talk(0);
                            sayer->RemoveAura(201893);
                            sayer->RemoveAura(201896);
                            sayer->SetWalk(true);
                            sayer->GetMotionMaster()->MovePoint(0, -1141.28f, 6110.18f, 43.83f);
                        }
                        me->SetByteValue(UNIT_FIELD_BYTES_1, 0, 0);
                        me->SetAnimKitId(0);
                        me->HandleEmoteCommand(53);
                  //      me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, 53);
                    }
                    else if (eventphase == 2)
                    {
                        if(Creature* sayer = me->FindNearestCreature(102256, 50.0f, true))
                        {
                            sayer->AI()->Talk(1);
                            me->SetFacingToObject(sayer);
                            me->HandleEmoteCommand(36);
                            me->AI()->AttackStart(sayer);
                            sayer->Kill(sayer);
                        }
                    }
                    else if (eventphase == 3)
                    {
                        intro = false;
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit* target = me->FindNearestPlayer(100.0f))
                            me->AI()->AttackStart(target);
                    }
                    eventphase++;
                    eventtimer = 5000;
                }
                else
                    eventtimer -= diff;
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
                    case EVENT_1: // hack for spell
                        if (me->HasAura(201876))
                        {
                            if (me->isMoving())
                                me->CastSpell(me, 201874);
                            else if(me->HasAura(201874))
                                me->RemoveAuraFromStack(201874);
                        }
                        events.RescheduleEvent(EVENT_1, 3000);
                        break;
                    case EVENT_2:
                        if (Creature* trigger = me->FindNearestCreature(95464, 150.0f))
                        {
                            Position pos;
                            me->GetNearPosition(pos, 40.0f, 0);
                            trigger->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 201871, true);
                            trigger->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 201856, true);
                        }
                        events.RescheduleEvent(EVENT_2, 30000);
                        break;
                    case EVENT_3:
                        Conversation* conversation = new Conversation;
                        if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1145, me, NULL, *me))
                            delete conversation;  
                        me->Kill(me);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// 102300
class npc_raging_current: public CreatureScript
{
public:
    npc_raging_current() : CreatureScript("npc_raging_current") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_raging_currentAI(creature);
    }
    
    struct npc_raging_currentAI : ScriptedAI
    {
        npc_raging_currentAI(Creature* creature) : ScriptedAI(creature) { }
       
        EventMap events;
        void Reset() override
        {
            events.Reset();
            events.RescheduleEvent(EVENT_1, 1000);
            events.RescheduleEvent(EVENT_2, 1000);
        }
        
        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        me->CastSpell(me, 201992);
                        me->GetMotionMaster()->MoveRotate(20000, ROTATE_DIRECTION_RIGHT);
                        events.RescheduleEvent(EVENT_1, 20000);
                        break;
                    case EVENT_2:
                        if (!me->FindNearestCreature(102298, 22.0f, true))
                        {
                            me->Kill(me);
                            Conversation* conversation = new Conversation;
                            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1160, me, NULL, *me))
                                delete conversation;
                        }
                        else
                            events.RescheduleEvent(EVENT_2, 1000);
                        break;
                }
            }
        }
    };
};

// 102293
class npc_dread_admiral_eliza: public CreatureScript
{
public:
    npc_dread_admiral_eliza() : CreatureScript("npc_dread_admiral_eliza") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dread_admiral_elizaAI(creature);
    }
    
    struct npc_dread_admiral_elizaAI : ScriptedAI
    {
        npc_dread_admiral_elizaAI(Creature* creature) : ScriptedAI(creature) 
        { 
            intro = false;
        }
        
        bool intro;
        bool outro;
        EventMap events;
        
        void Reset() override
        {
            events.Reset();
            outro = false;
        }
        
        void EnterCombat(Unit* who) override
        {
            Talk(0);
            events.RescheduleEvent(EVENT_1, 10000);
        }
        
        void JustDied(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48582);
            Talk(4);
            if (auto blades = me->SummonCreature(112817, -1353.04f, 6307.06f, 8.60f, 1.99f))
                blades->SetDisplayId(72343);

            me->SummonGameObject(254087, -1353.04f, 6307.06f, 8.60f, 1.99f, 0.0f, 0.0f, 0.0f, 0.0f, DAY);
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER || !me->IsWithinDistInMap(who, 50.0f))
                return;
            
            if (intro)
                return;
            
            intro = true;
            Conversation* conversation = new Conversation;
            if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1178, who, NULL, *who))
                delete conversation;
            if (Creature* trigger = me->FindNearestCreature(102317, 50.0f))
            {
                trigger->CastSpell(trigger, 202018);
                trigger->DespawnOrUnsummon(4000);
            }
            me->RemoveAura(202013);
            who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48538);
        }
        
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            if (me->HealthBelowPct(30) && !outro)
            {
                outro = true;
                DoCast(202033);
                Talk(3);
            }
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
                        DoCast(208226);
                        Talk(1);
                        events.RescheduleEvent(EVENT_1, 25000);
                        break;
                    case EVENT_2:
                        DoCast(208245);
                        events.RescheduleEvent(EVENT_3, 3000);
                        events.RescheduleEvent(EVENT_4, 5000);
                        break;
                    case EVENT_3:
                        DoCast(208244);
                        Talk(2);
                        break;
                    case EVENT_4:
                        DoCast(208225);
                        if (me->HasAura(208245))
                            events.RescheduleEvent(EVENT_4, 4000);
                        else
                            events.RescheduleEvent(EVENT_5, 4000);
                        break;
                   case EVENT_5:
                        DoCast(208224);
                        events.RescheduleEvent(EVENT_5, urand(12000, 15000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// 254087
class go_scenario_dreadblades : public GameObjectScript
{
public:
    go_scenario_dreadblades() : GameObjectScript("go_scenario_dreadblades") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                if (target->ToPlayer()->HasItemCount(128872, 1))
                {
                    target->ToPlayer()->AddItem(128872, 1);
                    target->CastSpell(target, 202040, true);  // on loot
                }
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 48553);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 1012, 1);
                if (Creature* trigger = go->FindNearestCreature(112817, 20.0f))
                    trigger->DespawnOrUnsummon();

                target->ToPlayer()->GetPhaseMgr().SetCustomPhase(1);
                if (Creature* trigget = go->SummonCreature(102357, -1162.16f, 6124.12f, 53.38f, 2.87f))
                {
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                if (Creature* trigget = go->SummonCreature(102356, -1167.68f, 6112.83f, 50.97f, 2.59f))
                {
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                if (Creature* trigget = go->SummonCreature(102355, -1169.81f, 6130.16f, 49.72f, 3.01f))
                {
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                if (Creature* trigget = go->SummonCreature(102352, -1177.02f, 6124.60f, 44.78f, 2.78f))
                {
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1721, target, NULL, *target))
                    delete conversation;
            }
        }
    }
};

// 102354
class npc_bloodsail_gryphon : public CreatureScript
{
public:
    npc_bloodsail_gryphon() : CreatureScript("npc_bloodsail_gryphon") {}

    struct npc_bloodsail_gryphonAI : ScriptedAI
    {
        npc_bloodsail_gryphonAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                me->GetMotionMaster()->MovePoint(0, -1157.28f, 6113.77f, 69.04f);
                Conversation* conversation = new Conversation;
                if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 1188, who, NULL, *who))
                    delete conversation;
            }
        }
        

        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != POINT_MOTION_TYPE)
                return;

            if (pointId == 0 && me->GetAnyOwner())
            {
                if (Player* owner = me->GetAnyOwner()->ToPlayer())
                {
                    owner->CastSpell(owner, 217082, true);
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bloodsail_gryphonAI(creature);
    }
};

void AddSC_Dreadblades()
{
    new npc_admiral_tethys();
    new npc_admiral_tethys_scenario();
    new npc_first_helper_degauz();
    new npc_small_events_dreadblades();
    new npc_lord_brinebeard();
    new npc_raging_current();
    new npc_dread_admiral_eliza();
    new go_scenario_dreadblades();
    new npc_bloodsail_gryphon();
};