/*
    http://uwow.biz
    Demon Hunter Specialization: Vengeance
    To-Do: Last Boss (i havent sniffs)
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"
#include "DH_vengeance_art_scenario.h"

// 99299 99230
class npc_illidari_fel_bat : public CreatureScript
{
public:
    npc_illidari_fel_bat() : CreatureScript("npc_illidari_fel_bat") {}

    struct npc_illidari_fel_batAI : ScriptedAI
    {
        npc_illidari_fel_batAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply && me->GetMapId() == 1220)
                me->GetMotionMaster()->MovePoint(0, -842.92f, 4139.79f, 755.60f);
            if (apply && me->GetMapId() == 1500)
                me->GetMotionMaster()->MovePoint(0, -2748.92f, -284.44f, 128.20f);
        }
        

        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != POINT_MOTION_TYPE)
                return;

            if (pointId == 0 && me->GetAnyOwner())
            {
                if (Player* owner = me->GetAnyOwner()->ToPlayer())
                {
                    if (me->GetMapId() == 1220)
                    {
                        owner->SetScenarioId(961);
                        me->CastSpell(me, 195237, true);
                    }
                    if (me->GetMapId() == 1500)
                    {
                        owner->CastSpell(owner, 208341, true);
                    }
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_illidari_fel_batAI(creature);
    }
};

// 98882
class npc_allari_souleater : public CreatureScript
{
public:
    npc_allari_souleater() : CreatureScript("npc_allari_souleater") {}

    struct npc_allari_souleaterAI : ScriptedAI
    {
        npc_allari_souleaterAI(Creature* creature) : ScriptedAI(creature) 
        {
            introDone = false;
        }

        bool introDone;
        
        void Reset() override {}
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if ((me->GetDistance(who) < 50.0f) && !introDone)
            {
                introDone = true;
                who->CastSpell(who, 207870); // convers
            }
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (me->isSummon())
                return;
            
            if (Player* player = clicker->ToPlayer())
            {
                player->CastSpell(player, 207941); // convers
                me->setStandStateValue(0 & 0xFF);  // снимаем анимацию и прибивку
                me->SetByteValue(UNIT_FIELD_BYTES_1, 1, 0);
                me->SetStandVisValue(uint8(0 >> 16) & 0xFF);
                me->SetMiscStandValue(uint8((0 >> 24) & 0xFF));
                
                if (InstanceScript* instance = clicker->GetInstanceScript())
                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47077); //Step 0 - complete
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_allari_souleaterAI(creature);
    }
};

class go_portal_fel_soul : public GameObjectScript
{
public:
    go_portal_fel_soul() : GameObjectScript("go_portal_fel_soul") { }

    struct go_portal_fel_soulAI : public GameObjectAI
    {
        go_portal_fel_soulAI(GameObject* go) : GameObjectAI(go) {}

        bool GossipHello(Player* player) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->getScenarionStep() == DATA_STAGE_2)
                {
                    if (go->GetEntry() == FEL_PORTAL_1)
                    {
                        if (Creature* akvesh = go->FindNearestCreature(NPC_AKVESH, 50.0f, true))
                            akvesh->AI()->AttackStart(player);
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47138); //Step 1
                    }
                    if (go->GetEntry() == FEL_PORTAL_2)
                    {
                        player->CastSpell(player, 208360);
                        player->CastSpell(player, 208374);
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49925); //Step 1
                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49910); //Step 1
                    }
                    go->SetGoState(GO_STATE_READY);
                }
                return true;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_portal_fel_soulAI(go);
    }
};

// 105095 105094
class npc_saera_and_taraar : public CreatureScript
{
public:
    npc_saera_and_taraar() : CreatureScript("npc_saera_and_taraar") {}

    struct npc_saera_and_taraarAI : ScriptedAI
    {
        npc_saera_and_taraarAI(Creature* creature) : ScriptedAI(creature) 
        {
            introDone = false;
        }

        bool introDone;
        EventMap events;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetEntry() == NPC_SAERA)
                if ((me->GetDistance(who) < 60.0f) && !introDone)
                {
                    introDone = true;
                    who->CastSpell(who, 208383); // convers
                }
        }
        
        void EnterCombat(Unit* who) override
        {
            if (me->GetEntry() == NPC_SAERA)
                who->CastSpell(who, 208388); // convers
            events.RescheduleEvent(EVENT_1, 4000);
            DoCast(215835); // deal damage
        }
        
        void JustDied(Unit* who) override
        {
            Talk(0);
            if (InstanceScript* instance = who->GetInstanceScript())
            {
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49959);
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49960);
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49961);
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
                        if (me->GetEntry() == NPC_SAERA)
                            DoCast(215885);
                        if (me->GetEntry() == NPC_TARAAR)
                            DoCast(215852);
                        events.RescheduleEvent(EVENT_1, urand(6000, 9000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_saera_and_taraarAI(creature);
    }
};

// 99046
class npc_gorgonnash : public CreatureScript
{
public:
    npc_gorgonnash() : CreatureScript("npc_gorgonnash") {}

    struct npc_gorgonnashAI : ScriptedAI
    {
        npc_gorgonnashAI(Creature* creature) : ScriptedAI(creature), summons(me)  
        {
            introDone = false;
            firstcast = false;
            firstattack = false;
            me->SetVisible(false);
            timercheck = 3000;
        }

        bool introDone;
        bool firstcast;
        bool firstattack;
        EventMap events;
        uint32 timercheck;
        SummonList summons;
        
        void Reset() override
        {
            firstcast = false;
            events.Reset();
            summons.DespawnAll();
        }
        
        void JustSummoned(Creature* summon) override
        { 
            summons.Summon(summon);
        }
        
        void EnterCombat(Unit* who) override
        {
            if (!firstattack)
            {
                firstattack = true;
                if (Creature* allari = me->SummonCreature(98882, -2711.21f, -43.92f, 47.48f, 3.92f))
                {
                    allari->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    allari->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    allari->AI()->AttackStart(me);
                }
            }
            events.RescheduleEvent(EVENT_1, 6000); // 215925
            events.RescheduleEvent(EVENT_2, 10000); // add  not repeat
            events.RescheduleEvent(EVENT_3, 7000); // not repeat
        }
        
        void JustDied(Unit* who) override
        {
            DoCast(208395); // convers
            if (InstanceScript* instance = who->GetInstanceScript())
            {
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47079);
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!introDone)
            {
                if(timercheck <= diff)
                {
                    if (InstanceScript* instance = me->GetInstanceScript())
                    {
                        if (instance->getScenarionStep() == DATA_STAGE_4)
                        {
                            introDone = true;
                            me->SetVisible(true);
                            DoCast(208389);
                            me->GetMotionMaster()->MovePoint(0, -2761.63f, -79.27f, 46.63f);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        }
                        else
                            timercheck = 3000;
                    }else
                        timercheck = 3000;
                }
                else
                    timercheck -= diff;
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
                        if(!firstcast)
                        {
                            DoCast(208391); // convers
                            firstcast = true;
                        }
                        DoCast(215925); 
                        events.RescheduleEvent(EVENT_1, urand(6000, 11000));
                        break;
                    case EVENT_2:
                        for(int i = 0; i < 2; ++i)
                        {
                            if (Creature* inf = me->SummonCreature(105103, -2745.88f + irand(-10, 10), -69.15f + irand(-10, 10), 47.0f, 3.6f))
                                inf->CastSpell(inf, 185302); 
                        }
                        break;
                    case EVENT_3:
                        if(Player* pl = me->FindNearestPlayer(50.0f))
                            pl->SetAuraStack(215978, pl, 5);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gorgonnashAI(creature);
    }
};

// 215978
class spell_creeping_doom : public SpellScriptLoader
{
    public:
        spell_creeping_doom() : SpellScriptLoader("spell_creeping_doom") { }

        class spell_creeping_doom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_creeping_doom_AuraScript);

            void OnPeriodic(AuraEffect const*aurEff)
            {
                if (!GetTarget())
                    return;
                
                if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
                {
                    if (Aura * aur = GetTarget()->GetAura(215978))
                    {
                        if (GetTarget()->isMoving())
                            GetTarget()->RemoveAuraFromStack(215978);
                    }
                }
                
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_creeping_doom_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_creeping_doom_AuraScript();
        }
};

// 245119
class go_245119 : public GameObjectScript
{
public:
    go_245119() : GameObjectScript("go_245119") { }

    struct go_245119AI : public GameObjectAI
    {
        go_245119AI(GameObject* go) : GameObjectAI(go)
        {
            check = false;
            timer = 0;
            firstcheck = false;
        }

        bool check;
        bool firstcheck;
        uint32 timer;
        Player* ow;
        
        void UpdateAI(uint32 diff) override
        {
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->getScenarionStep() == DATA_STAGE_5)
                {
                    std::list<Player*> list;
                    list.clear();
                    go->GetPlayerListInGrid(list, 10.0f);
                    if (!list.empty())
                    {
                       for (std::list<Player*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                       {
                           if(!firstcheck)
                           {
                               firstcheck = true;
                               if (Creature* sayer = go->FindNearestCreature(95899, 100.0f))    
                                    sCreatureTextMgr->SendChat(sayer, TEXT_GENERIC_0, (*itr)->GetGUID());
                           }
                           
                           if ((*itr)->HasAura(188501))
                           {
                               instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49972);
                               go->SetLootState(GO_READY);
                               go->UseDoorOrButton(10000, false, (*itr));
                           }
                       }
                    }
                }
            }
        }
        
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_245119AI(go);
    }
};

// 99184
class npc_caria_felsoul : public CreatureScript
{
public:
    npc_caria_felsoul() : CreatureScript("npc_caria_felsoul") {}

    struct npc_caria_felsoulAI : ScriptedAI
    {
        npc_caria_felsoulAI(Creature* creature) : ScriptedAI(creature) 
        {
            introDone = false;
            introDone2 = false;
        }

        bool introDone;
        bool introDone2;

        EventMap events;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance2d(-2791.93f, -264.09f) <= 5.0f && !introDone)
            {
                if ((me->GetDistance(who) < 50.0f) && !introDone)
                {
                    introDone = true;
                    who->CastSpell(who, 208459); // convers
                    me->GetMotionMaster()->MoveJump(-2748.06f, -328.11f, 38.42f, 10, 15);
                }
            }
            if (me->GetDistance2d(-2748.06f, -328.11f) <= 5.0f && !introDone2)
            {
                if ((me->GetDistance(who) < 53.0f) && !introDone)
                {
                    introDone2 = true;
                    who->CastSpell(who, 208460); // convers
                }
            }
            
        }
        
        void EnterCombat(Unit* who) override
        {
            // events
        }
        
        void JustDied(Unit* who) override
        {
            DoCast(208475); // convers
            // me->SummonGameObject(248785, -2748.406f, -328.1875f, 38.34308f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, DAY);
        //    me->SummonCreature(105155, -2748.406f, -328.1875f, 38.34308f, 1.93f);
            if (InstanceScript* instance = who->GetInstanceScript())
                    instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 47080); //Step last - complete
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
                        
                       // events.RescheduleEvent(EVENT_1, urand(6000, 11000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_caria_felsoulAI(creature);
    }
};

//248785
class go_bs_the_aldrachi_warblades : public GameObjectScript
{
public:
    go_bs_the_aldrachi_warblades() : GameObjectScript("go_bs_the_aldrachi_warblades") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* target) override
    {
        if (target && state == GO_ACTIVATED)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                if (!target->ToPlayer()->HasItemCount(128832, 1))
                {
                    target->ToPlayer()->AddItem(128832, 1);
                    target->CastSpell(target, 208300, true);  // on loot
                }
                
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49999);
                target->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_SCENARIO, 961, 1);
                if (Creature* trigger = go->FindNearestCreature(105155, 20.0f))
                    trigger->DespawnOrUnsummon();

                target->ToPlayer()->KilledMonsterCredit(99250);
                target->ToPlayer()->CompleteQuest(41863);
                if (Creature* trigget = target->SummonCreature(99229, -2726.35f, -307.24f, 30.97f, 3.11f))
                {
                  //  target->ToPlayer()->SetPhaseMask(1, true);
                    target->ToPlayer()->GetPhaseMgr().SetCustomPhase(1);
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                if (Creature* trigget = target->SummonCreature(99227, -2734.72f, -304.77f, 30.97f, 3.19f))
                {
                    target->ToPlayer()->GetPhaseMgr().SetCustomPhase(1);
                    trigget->AddPlayerInPersonnalVisibilityList(target->GetGUID());
                    trigget->SetPhaseMask(1, true);
                }
                
            }
        }
    }
};


void AddSC_DH_vengeance_art_scenario()
{
    new npc_illidari_fel_bat();
    new npc_allari_souleater();
    new go_portal_fel_soul();
    new npc_saera_and_taraar();
    new npc_gorgonnash();
    new spell_creeping_doom();
    new go_245119();
    new npc_caria_felsoul();
    new go_bs_the_aldrachi_warblades();
};