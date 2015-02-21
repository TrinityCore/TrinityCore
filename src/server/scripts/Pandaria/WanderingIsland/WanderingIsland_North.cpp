#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"

class mob_master_shang_xi : public CreatureScript
{
    public:
        mob_master_shang_xi() : CreatureScript("mob_master_shang_xi") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == 29408) // La lecon du parchemin brulant
            {
                creature->AddAura(114610, creature);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            }

            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_master_shang_xi_AI(creature);
        }

        struct mob_master_shang_xi_AI : public ScriptedAI
        {
            mob_master_shang_xi_AI(Creature* creature) : ScriptedAI(creature)
            {
                checkPlayersTime = 2000;
            }

            uint32 checkPlayersTime;

            void SpellHit(Unit* caster, const SpellInfo* pSpell)
            {
                if (pSpell->Id == 114746) // Attraper la flamme
                {
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (caster->ToPlayer()->GetQuestStatus(29408) == QUEST_STATUS_INCOMPLETE)
                        {
                            me->CastSpell(caster, 114611, true);
                            me->RemoveAurasDueToSpell(114610);
                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (checkPlayersTime <= diff)
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 5.0f);

                    bool playerWithQuestNear = false;

                    for (auto player: playerList)
                        if (player->GetQuestStatus(29408) == QUEST_STATUS_INCOMPLETE)
                            if (!player->HasItemCount(80212))// Flamme du maitre
                                playerWithQuestNear = true;

                    if (playerWithQuestNear && !me->HasAura(114610))
                    {
                        me->AddAura(114610, me);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    }
                    else if (!playerWithQuestNear && me->HasAura(114610))
                    {
                        me->RemoveAurasDueToSpell(114610);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    }

                    checkPlayersTime = 2000;
                }
                else
                    checkPlayersTime -= diff;
            }
        };
};

class go_wandering_weapon_rack : public GameObjectScript
{
public:
    go_wandering_weapon_rack() : GameObjectScript("go_wandering_weapon_rack") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(30027) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(73209))
        {
            player->AddItem(73209, 1);
        }
        else if (player->GetQuestStatus(30033) == QUEST_STATUS_INCOMPLETE && (!player->HasItemCount(76392) || !player->HasItemCount(76390)))
        {
            player->AddItem(76392, 1);
            player->AddItem(76390, 1);
        }
        else if (player->GetQuestStatus(30034) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(73211))
        {
            player->AddItem(73211, 1);
        }
        else if (player->GetQuestStatus(30035) == QUEST_STATUS_INCOMPLETE && (!player->HasItemCount(76393) || !player->HasItemCount(73207)))
        {
            player->AddItem(76393, 1);
            player->AddItem(73207, 1);
        }
        else if (player->GetQuestStatus(30036) == QUEST_STATUS_INCOMPLETE && (!player->HasItemCount(73212) || !player->HasItemCount(73208)))
        {
            player->AddItem(73212, 1);
            player->AddItem(73208, 1);
        }
        else if (player->GetQuestStatus(30037) == QUEST_STATUS_INCOMPLETE && (!player->HasItemCount(73213) || !player->HasItemCount(76391)))
        {
            player->AddItem(73213, 1);
            player->AddItem(76391, 1);
        }
        else if (player->GetQuestStatus(30038) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(73210))
        {
            player->AddItem(73210, 1);
        }

        return true;
    }
};

class mob_training_target : public CreatureScript
{
public:
    mob_training_target() : CreatureScript("mob_training_target") { }
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_training_targetAI(creature);
    }
    
    struct mob_training_targetAI : public ScriptedAI
    {
    	mob_training_targetAI(Creature* creature) : ScriptedAI(creature) {}
    	
        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat()
        {
            return;
        }
    };
};

class mob_tushui_trainee : public CreatureScript
{
    public:
        mob_tushui_trainee() : CreatureScript("mob_tushui_trainee") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_tushui_trainee_AI(creature);
        }

        struct mob_tushui_trainee_AI : public ScriptedAI
        {
            mob_tushui_trainee_AI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                me->SetReactState(REACT_DEFENSIVE);
                me->setFaction(2357);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (me->HealthBelowPctDamaged(5, damage))
                {
                    if(attacker && attacker->GetTypeId() == TYPEID_PLAYER)
                        attacker->ToPlayer()->KilledMonsterCredit(54586, 0);
                    me->CombatStop();
                    me->SetFullHealth();
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    me->setFaction(35);
                    me->DespawnOrUnsummon(3000);
                    damage = 0;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

class boss_jaomin_ro : public CreatureScript
{
public:
    boss_jaomin_ro() : CreatureScript("boss_jaomin_ro") { }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jaomin_roAI(creature);
    }
    
    struct boss_jaomin_roAI : public ScriptedAI
    {
        boss_jaomin_roAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->SetDisplayId(39755);
            me->setFaction(14); //mechant!
        }

        enum eEvents
        {
            EVENT_JAOMIN_JUMP   = 1,
            EVENT_HIT_CIRCLE    = 2,
            EVENT_FALCON        = 3,
            EVENT_RESET         = 4,
            EVENT_CHECK_AREA    = 5,
        };
        
        EventMap events;
        bool isInFalcon;

        void EnterCombat(Unit* unit)
        {
            Talk(0);
            events.ScheduleEvent(EVENT_JAOMIN_JUMP, 1000);
            events.ScheduleEvent(EVENT_HIT_CIRCLE, 2000);
            events.ScheduleEvent(EVENT_CHECK_AREA, 2500);
        }
        
        void Reset()
        {
            isInFalcon = false;
            me->SetReactState(REACT_DEFENSIVE);
            me->SetDisplayId(39755);
            me->setFaction(2357); //mechant!
            me->CombatStop(true);

            me->GetMotionMaster()->MovePoint(1, 1380.35f, 3170.68f, 136.93f);
        }
        
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (me->HealthBelowPctDamaged(30, damage) && !isInFalcon)
            {
                isInFalcon = true;
                me->SetDisplayId(39796); //faucon
                events.ScheduleEvent(EVENT_FALCON, 1000);
                events.CancelEvent(EVENT_JAOMIN_JUMP);
                events.CancelEvent(EVENT_HIT_CIRCLE);
            }

            if (me->HealthBelowPctDamaged(5, damage))
            {
                me->SetDisplayId(39755);

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 10.0f);
                for (auto player: playerList)
                    player->KilledMonsterCredit(me->GetEntry(), 0);

                me->CombatStop();
                me->setFaction(35);
                me->SetFullHealth();
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                events.Reset();
                events.ScheduleEvent(EVENT_RESET, 5000);
                damage = 0;
            }

            if (damage > me->GetHealth())
                damage = 0;
        }
        
        void UpdateAI(const uint32 diff)
        {            
            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_JAOMIN_JUMP: //on monte
                        if (me->getVictim())
                            me->CastSpell(me->getVictim(), 108938, true);
                        events.ScheduleEvent(EVENT_JAOMIN_JUMP, 30000);
                        break;
                    case EVENT_HIT_CIRCLE: //baffe
                        if (me->getVictim())
                            me->CastSpell(me->getVictim(), 119301, true);

                        events.ScheduleEvent(EVENT_HIT_CIRCLE, 3000);
                        break;
                    case EVENT_FALCON: //attaque du faucon
                        if (me->getVictim())
                            me->CastSpell(me->getVictim(), 108935, true);

                        events.ScheduleEvent(EVENT_FALCON, 4000);
                        break;
                    case EVENT_RESET: //remechant
                        Reset();
                    	break;
                    case EVENT_CHECK_AREA:
                        if (me->GetAreaId() != 5843) // Grotte Paisible
                            Reset();
                        break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
    };
};

class mob_attacker_dimwind : public CreatureScript
{
public:
    mob_attacker_dimwind() : CreatureScript("mob_attacker_dimwind") { }
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_attacker_dimwindAI(creature);
    }
    
    struct mob_attacker_dimwindAI : public ScriptedAI
    {
    	mob_attacker_dimwindAI(Creature* creature) : ScriptedAI(creature) {}
    	
        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if(me->GetHealthPct() < 90 && pDoneBy && pDoneBy->ToCreature() && pDoneBy->ToCreature()->GetEntry() == 54785)
                uiDamage = 0;
        }
    };
};

class mob_min_dimwind : public CreatureScript
{
public:
    mob_min_dimwind() : CreatureScript("mob_min_dimwind") { }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_min_dimwindAI(creature);
    }
    
    struct mob_min_dimwindAI : public ScriptedAI
    {
        EventMap events;
        uint64 guidMob[4];

        enum eEvents
        {
            EVENT_CHECK_MOBS    = 1,
            EVENT_RESET         = 2
        };
        
        mob_min_dimwindAI(Creature* creature) : ScriptedAI(creature)
        {
            for(int i = 0; i < 4; i++)
                guidMob[i] = 0;

            ResetMobs();
            me->HandleEmoteCommand(EMOTE_STATE_READY2H);
        }
        
        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if(me->GetHealthPct() < 25 && pDoneBy && pDoneBy->ToCreature() && pDoneBy->ToCreature()->GetEntry() == 54130)
                uiDamage = 0;
        }
        
        
        bool VerifyMobs()
        {
            bool HasRemainingAttacker = false;
            for(int i = 0; i < 4; i++)
            {
                if(guidMob[i])
                {
                    if (Unit* unit = sObjectAccessor->FindUnit(guidMob[i]))
                    {
                        if(unit->isAlive())
                            HasRemainingAttacker = true;
                    }
                    else
                        guidMob[i] = 0;
                }
            }

            return !HasRemainingAttacker;
        }
        
        void ResetMobs()
        {
            events.ScheduleEvent(EVENT_CHECK_MOBS, 1000);
            me->HandleEmoteCommand(EMOTE_STATE_READY2H);

            for(int i = 0; i < 4; i++)
            {
                if(guidMob[i])
                    if (Unit* unit = sObjectAccessor->FindUnit(guidMob[i]))
                        if (unit->ToCreature())
                            unit->ToCreature()->DespawnOrUnsummon();

                guidMob[i] = 0;

                if(TempSummon* temp = me->SummonCreature(54130, me->GetPositionX()-3+rand()%6, me->GetPositionY() + 4 + rand()%4, me->GetPositionZ()+2, 3.3f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                {
                    guidMob[i] = temp->GetGUID();
                    
                    temp->SetFacingToObject(me);
                    temp->HandleEmoteCommand(EMOTE_STATE_READY2H);
                    
                    temp->GetMotionMaster()->Clear(false);
                    temp->GetMotionMaster()->MoveChase(me);
                    temp->Attack(me, true);
                    temp->getThreatManager().addThreat(me, 250.0f);
                }
            }
        }
        
        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_MOBS:
                    {
                        if(VerifyMobs()) //plus de mobs, win!
                        {
                    	    me->HandleEmoteCommand(EMOTE_STATE_STAND);
                    	    me->MonsterYell("Thank you!", LANG_UNIVERSAL, 0);
                        
                            std::list<Player*> PlayerList;
                            GetPlayerListInGrid(PlayerList, me, 20.0f);
                            for (auto player: PlayerList)
                                player->KilledMonsterCredit(54855, 0);
                        
                            events.ScheduleEvent(EVENT_RESET, 30000);
                        }
                        else
                            events.ScheduleEvent(EVENT_CHECK_MOBS, 1000);

                        break;
                    }
                    case EVENT_RESET:
                    {
                        ResetMobs();
                    }
                }
            }
        }
    };
};

class mob_aysa_lake_escort : public CreatureScript
{
public:
    mob_aysa_lake_escort() : CreatureScript("mob_aysa_lake_escort") { }

    struct mob_aysa_lake_escortAI : public npc_escortAI
    {        
        mob_aysa_lake_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;

        void Reset()
        {
            IntroTimer = 2500;
        }

        void MovementInform(uint32 uiType, uint32 uiId)
        {
            npc_escortAI::MovementInform(uiType, uiId);

            if (uiType != POINT_MOTION_TYPE && uiType != EFFECT_MOTION_TYPE)
                return;

            switch (uiId)
            {
                case 10:
                    me->GetMotionMaster()->MoveJump(1227.11f, 3489.73f, 100.37f, 10, 20, 11);
                    break;
                case 11:
                    me->GetMotionMaster()->MoveJump(1236.68f, 3456.68f, 102.58f, 10, 20, 12);
                    break;
                case 12:
                    Start(false, true);
                    break;
                default:
                    break;
            }
        }

        void WaypointReached(uint32 waypointId)
        {
            if (waypointId == 4)
                me->DespawnOrUnsummon(500);
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    me->MonsterYell("Follow me!", LANG_UNIVERSAL, 0);
                    IntroTimer = 0;
                    me->GetMotionMaster()->MoveJump(1216.78f, 3499.44f, 91.15f, 10, 20, 10);
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_aysa_lake_escortAI(creature);
    }
    
};

class mob_aysa : public CreatureScript
{
public:
    mob_aysa() : CreatureScript("mob_aysa") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 29414) // La voie des tushui
            if (Creature* tempSummon = creature->SummonCreature(56661, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
                tempSummon->SetPhaseMask(1, true);

        return true;
    }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_aysaAI(creature);
    }
    
    struct mob_aysaAI : public ScriptedAI
    {
    	EventMap events;
        std::list<Player*> playersInvolved;
        TempSummon* lifei;
        bool inCombat;
        uint32 timer;
        
        mob_aysaAI(Creature* creature) : ScriptedAI(creature)
        {
            events.ScheduleEvent(1, 600); //Begin script
            inCombat = false;
            timer = 0;
            lifei = NULL;
            me->SetReactState(REACT_DEFENSIVE);
            me->setFaction(2263);
        }

        enum eEvents
        {
            EVENT_START         = 1,
            EVENT_SPAWN_MOBS    = 2,
            EVENT_PROGRESS      = 3,
            EVENT_END           = 4,
        };
        
        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if(me->HealthBelowPctDamaged(5, uiDamage))
            {
                if(lifei)
                {
                    lifei->UnSummon();
                    lifei = NULL;
                }
                
                uiDamage = 0;
                me->MonsterSay("I can't meditate!", LANG_UNIVERSAL, 0);
                me->SetFullHealth();
                me->SetReactState(REACT_DEFENSIVE);
                
                std::list<Creature*> unitlist;
                GetCreatureListWithEntryInGrid(unitlist, me, 59637, 50.0f);
                for (auto creature: unitlist)
                    me->Kill(creature);
                	
                events.ScheduleEvent(EVENT_START, 20000);
                events.CancelEvent(EVENT_SPAWN_MOBS);
                events.CancelEvent(EVENT_PROGRESS);
                events.CancelEvent(EVENT_END);
            }
        }
        
        void updatePlayerList()
        {
            playersInvolved.clear();
            
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 20.0f);

            for (auto player: PlayerList)
                if(player->GetQuestStatus(29414) == QUEST_STATUS_INCOMPLETE)
                    playersInvolved.push_back(player);
        }
        
        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_START: //Begin script if playersInvolved is not empty
                    {
                    	updatePlayerList();
                        if(playersInvolved.empty())
                            events.ScheduleEvent(1, 600);
                        else
                        {
                            me->MonsterSay("Keep those creatures at bay while I meditate. We'll soon have the answers we seek...", LANG_UNIVERSAL, 0);
                            me->SetReactState(REACT_PASSIVE);
                            timer = 0;
                            events.ScheduleEvent(EVENT_SPAWN_MOBS, 5000); //spawn mobs
                            events.ScheduleEvent(EVENT_PROGRESS, 1000); //update time
                            events.ScheduleEvent(EVENT_END, 90000); //end quest
                        }
                        break;
                    }
                    case EVENT_SPAWN_MOBS: //Spawn 3 mobs
                    {
                        updatePlayerList();
                        for(int i = 0; i < std::max((int)playersInvolved.size()*3,3); i++)
                        {
                            if(TempSummon* temp = me->SummonCreature(59637, 1144.55f, 3435.65f, 104.97f, 3.3f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
                            {
                                if (temp->AI())
                                    temp->AI()->AttackStart(me);

			                    temp->AddThreat(me, 250.0f);
                                temp->GetMotionMaster()->Clear();
                                temp->GetMotionMaster()->MoveChase(me);
                            }
                        }
                        events.ScheduleEvent(EVENT_SPAWN_MOBS, 20000); //spawn mobs
                        break;
                    }
                    case EVENT_PROGRESS: //update energy
                    {
                        timer++;
                        
                        if(timer == 25 && !lifei)
                        {
                            if (lifei = me->SummonCreature(54856, 1130.162231f, 3435.905518f, 105.496597f, 0.0f,TEMPSUMMON_MANUAL_DESPAWN))
                                lifei->MonsterSay("The way of the Tushui... enlightenment through patience and mediation... the principled life", LANG_UNIVERSAL, 0);
                        }
                        
                        if(timer == 30)
                            if (lifei)
                                lifei->MonsterSay("It is good to see you again, Aysa. You've come with respect, and so I shall give you the answers you seek.", LANG_UNIVERSAL, 0);
                        
                        if(timer == 42)
                            if (lifei)
                                lifei->MonsterSay("Huo, the spirit of fire, is known for his hunger. He wants for tinder to eat. He needs the caress of the wind to rouse him.", LANG_UNIVERSAL, 0);
                        
                        if(timer == 54)
                            if (lifei)
                                lifei->MonsterSay("If you find these things and bring them to his cave, on the far side of Wu-Song Village, you will face a challenge within.", LANG_UNIVERSAL, 0);
                        
                        if(timer == 66)
                            if (lifei)
                                lifei->MonsterSay("Overcome that challenge, and you shall be graced by Huo's presence. Rekindle his flame, and if your spirit is pure, he shall follow you.", LANG_UNIVERSAL, 0);
                        
                        if(timer == 78)
                            if (lifei)
                                lifei->MonsterSay("Go, children. We shall meet again very soon.", LANG_UNIVERSAL, 0);
                        
                        if(timer == 85)
                        {
                            if (lifei)
                                lifei->UnSummon();

                            lifei = NULL;
                        }
                        
                        updatePlayerList();
                        for (auto player: playersInvolved)
                        {
                            if(!player->HasAura(116421))
                                player->CastSpell(player, 116421);

                            player->ModifyPower(POWER_ALTERNATE_POWER, timer/25);
                            player->SetMaxPower(POWER_ALTERNATE_POWER, 90);
                        }

                        events.ScheduleEvent(EVENT_PROGRESS, 1000);
                        break;
                    }
                    case EVENT_END: //script end
                    {
                        if(lifei)
                        {
                            lifei->UnSummon();
                            lifei = NULL;
                        }
                        events.ScheduleEvent(EVENT_START, 10000);
                        events.CancelEvent(EVENT_SPAWN_MOBS);
                        events.CancelEvent(EVENT_PROGRESS);
                        me->MonsterSay("And so our path lays before us. Speak to Master Shang Xi, he will tell you what comes next.", LANG_UNIVERSAL, 0);
                        updatePlayerList();
                        me->SetReactState(REACT_DEFENSIVE);
                        for(auto player: playersInvolved)
                        {
                            player->KilledMonsterCredit(54856, 0);
                            player->RemoveAura(116421);
                        }
                        break;
                    }
                }
            }
        }
    };
};

class boss_living_air : public CreatureScript
{
public:
    boss_living_air() : CreatureScript("boss_living_air") { }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_living_airAI(creature);
    }
    
    struct boss_living_airAI : public ScriptedAI
    {
        boss_living_airAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_AGGRESSIVE);
        }
        
        EventMap events;
        
        void EnterCombat(Unit* unit)
        {
            events.ScheduleEvent(1, 3000);
            events.ScheduleEvent(2, 5000);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case 1:
                    	me->CastSpell(me->getVictim(), 108693);
                    	break;
                    case 2:
                    	me->CastSpell(me->getVictim(), 73212);
                    	events.ScheduleEvent(2, 5000);
                    	break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
    };
};

#define QUEST_PARCHEMIN_VOLANT  29421

class boss_li_fei : public CreatureScript
{
public:
    boss_li_fei() : CreatureScript("boss_li_fei") {}

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_PARCHEMIN_VOLANT) // La lecon du parchemin brulant
        {
            if (Creature* tempSummon = creature->SummonCreature(54856, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
            {
                tempSummon->SetPhaseMask(1024, true);
                tempSummon->AI()->AttackStart(player);
                tempSummon->AI()->SetGUID(player->GetGUID());
            }
        }

        return true;
    }
};

class boss_li_fei_fight : public CreatureScript
{
public:
    boss_li_fei_fight() : CreatureScript("boss_li_fei_fight") { }
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_li_fei_fightAI(creature);
    }
    
    struct boss_li_fei_fightAI : public ScriptedAI
    {
        EventMap events;
        std::list<Player*> playersInvolved;
        uint64 playerGuid;

        boss_li_fei_fightAI(Creature* creature) : ScriptedAI(creature)
        {}

        enum eEvents
        {
            EVENT_CHECK_PLAYER      = 1,
            EVENT_FEET_OF_FURY      = 2,
            EVENT_SHADOW_KICK       = 3,
            EVENT_SHADOW_KICK_STUN  = 4,
        };

        void Reset()
        {
            // This particular entry is also spawned on an other event
            if (me->GetAreaId() != 5849) // Cavern areaid
                return;

            playerGuid = 0;
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            me->setFaction(16);
            events.ScheduleEvent(EVENT_CHECK_PLAYER, 2500);
            events.ScheduleEvent(EVENT_FEET_OF_FURY, 5000);
            events.ScheduleEvent(EVENT_SHADOW_KICK,  1000);
        }

        void SetGUID(uint64 guid, int32 /*type*/)
        {
            playerGuid = guid;
        }
        
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (me->HealthBelowPctDamaged(10, damage))
            {
                damage = 0;
                me->setFaction(35);
                me->CombatStop();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    player->KilledMonsterCredit(54734, 0);
            }
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
            {
                victim->ToPlayer()->SetQuestStatus(QUEST_PARCHEMIN_VOLANT, QUEST_STATUS_FAILED);

                if (victim->GetGUID() == playerGuid)
                    me->DespawnOrUnsummon(3000);
            }
        }
        
        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CHECK_PLAYER:
                    {
                        bool checkPassed = true;
                        Player* player = ObjectAccessor::FindPlayer(playerGuid);

                        if (!player)
                        {
                            me->DespawnOrUnsummon(1000);
                            playerGuid = 0;
                            break;
                        }

                        if (!player->isAlive())
                        {
                            me->DespawnOrUnsummon(1000);
                            playerGuid = 0;
                            break;
                        }
                        
                        if (player->GetQuestStatus(QUEST_PARCHEMIN_VOLANT) != QUEST_STATUS_INCOMPLETE)
                        {
                            me->DespawnOrUnsummon(1000);
                            playerGuid = 0;
                            break;
                        }

                        events.ScheduleEvent(EVENT_CHECK_PLAYER, 2500);
                        break;
                    }
                    case EVENT_FEET_OF_FURY:
                        if(me->getVictim())
                    	    me->CastSpell(me->getVictim(), 108958);

                        events.ScheduleEvent(EVENT_FEET_OF_FURY, 5000);
                    	break;
                    case EVENT_SHADOW_KICK:
                        if(me->getVictim())
                    	    me->CastSpell(me->getVictim(), 108936);

                    	events.ScheduleEvent(EVENT_SHADOW_KICK_STUN, 2500);
                    	events.ScheduleEvent(EVENT_SHADOW_KICK, 30000);
                    	break;
                    case 4:
                        if(me->getVictim())
                    	    me->CastSpell(me->getVictim(), 108944);
                    	break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
    };
};

// Huo Benediction - 102630
class spell_huo_benediction: public SpellScriptLoader
{
    public:
        spell_huo_benediction() : SpellScriptLoader("spell_huo_benediction") { }

        class spell_huo_benediction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_huo_benediction_AuraScript);
            
            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                std::list<Creature*> huoList;
                GetCreatureListWithEntryInGrid(huoList, target, 54958, 20.0f);

                for (auto huo: huoList)
                    if (huo->ToTempSummon())
                        if (huo->ToTempSummon()->GetOwnerGUID() == target->GetGUID())
                            return;

                // A partir d'ici on sait que le joueur n'a pas encore de Huo
                if (TempSummon* tempHuo = target->SummonCreature(54958, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 0, target->GetGUID()))
                {
                    tempHuo->SetOwnerGUID(target->GetGUID());
                    tempHuo->GetMotionMaster()->MoveFollow(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                }
            }

            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                std::list<Creature*> huoList;
                GetCreatureListWithEntryInGrid(huoList, target, 54958, 20.0f);

                for (auto huo: huoList)
                    if (huo->ToTempSummon())
                        if (huo->ToTempSummon()->GetOwnerGUID() == target->GetGUID())
                            huo->DespawnOrUnsummon();
            }

            void Register()
            {
                OnEffectApply  += AuraEffectApplyFn (spell_huo_benediction_AuraScript::OnApply,  EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_huo_benediction_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_huo_benediction_AuraScript();
        }
};

class AreaTrigger_at_temple_entrance : public AreaTriggerScript
{
    public:
        AreaTrigger_at_temple_entrance() : AreaTriggerScript("AreaTrigger_at_temple_entrance")
        {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (player->GetQuestStatus(29423) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(61128, 0);

                std::list<Creature*> huoList;
                GetCreatureListWithEntryInGrid(huoList, player, 54958, 20.0f);

                for (auto huo: huoList)
                {
                    if (huo->ToTempSummon())
                    {
                        if (huo->ToTempSummon()->GetOwnerGUID() == player->GetGUID())
                        {
                            huo->GetMotionMaster()->Clear();
                            huo->GetMotionMaster()->MovePoint(1, 950.0f, 3601.0f, 203.0f);
                            huo->DespawnOrUnsummon(5000);
                        }
                    }
                }
            }

            return true;
        }
};

void AddSC_WanderingIsland_North()
{
    new mob_master_shang_xi();
    new go_wandering_weapon_rack();
    new mob_training_target();
    new mob_tushui_trainee();
    new boss_jaomin_ro();
    new mob_attacker_dimwind();
    new mob_min_dimwind();
    new mob_aysa_lake_escort();
    new mob_aysa();
    new boss_living_air();
    new boss_li_fei();
    new boss_li_fei_fight();
    new spell_huo_benediction();
    new AreaTrigger_at_temple_entrance();
}
