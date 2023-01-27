/*
    http://uwow.biz
    Invasion Azsuna
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"

// 119454 119483
class npc_invasion_azsuna_misc : public CreatureScript
{
public:
    npc_invasion_azsuna_misc() : CreatureScript("npc_invasion_azsuna_misc") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_miscAI(creature);
    }
    
    struct npc_invasion_azsuna_miscAI : ScriptedAI
    {
        npc_invasion_azsuna_miscAI(Creature* creature) : ScriptedAI(creature) {}
        
        void OnSpellClick(Unit* clicker) override
        {
            if (!clicker->IsPlayer())
                return;
            
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            
            uint32 criteria = 0;
            
            switch(me->GetEntry())
            {
                case 119483:
                    criteria = 56889;
                    break;
                case 119454:
                    criteria = 56895;
                    break;
            }
            if (criteria)
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56889);
            me->DespawnOrUnsummon(10);

        }
    };
};

// 119456 119459
class npc_invasion_azsuna_dragons : public CreatureScript
{
public:
    npc_invasion_azsuna_dragons() : CreatureScript("npc_invasion_azsuna_dragons") {}

    struct npc_invasion_azsuna_dragonsAI : ScriptedAI
    {
        npc_invasion_azsuna_dragonsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            _introDone = false;
        }
        
        bool _introDone;

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* clicker) override
        {
            if (me->GetEntry() == 119459)
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56885);
            else
                clicker->CastSpell(me, 52391, true); //Ride Veh
        }
        
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            SetFlyMode(true);
            if (who->IsPlayer())
            {                
                me->GetMotionMaster()->MovePath(10993803, false);
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56891);
            }
        }
        
        void MoveInLineOfSight(Unit* who) override
        {  
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;
            
            if (!_introDone)
                if (InstanceScript *script = me->GetInstanceScript())
                    if (script->getScenarionStep() == 1)
                        if (me->IsWithinDistInMap(who, 5.0f) && !who->IsOnVehicle())
                        {
                            _introDone = true;
                            who->ToPlayer()->CastSpell(me, 52391, true); //Ride Veh
                        }
        }
        
        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;

            if (me->GetVehicleKit())
            {
                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                    passenger->CreateConversation(4590);
                    passenger->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56892);
                    passenger->AddAura(55001, passenger);
                    me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_dragonsAI(creature);
    }
};


// 119633
class npc_invasion_azsuna_bes : public CreatureScript
{
public:
    npc_invasion_azsuna_bes() : CreatureScript("npc_invasion_azsuna_bes") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_besAI(creature);
    }
    
    struct npc_invasion_azsuna_besAI : ScriptedAI
    {
        npc_invasion_azsuna_besAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
            me->SetReactState(REACT_PASSIVE);
        }
        
        bool _introDone;
        
        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            me->AddDelayedEvent(3000, [this] () -> void
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(1, 1436.24f +irand(-2, 2), 6172.45f + irand(-2, 2), 1.71f);
                me->CastSpell(me, 237720);
            });
        }
        
        void EnterCombat(Unit* who) override
        {
            _introDone = true;
            DoCast(237716);
            me->Kill(me);
        }
    
        void MoveInLineOfSight(Unit* who) override
        {  
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 4.0f))
            {
                _introDone = true;
               DoCast(237716);
               me->Kill(me);
            }
        }
        
        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != POINT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                _introDone = true;
                DoCast(237716);
                me->Kill(me);
            }
        }

    };
};

// 119453
class npc_invasion_azsuna_acstris : public CreatureScript
{
public:
    npc_invasion_azsuna_acstris() : CreatureScript("npc_invasion_azsuna_acstris") { }
        
    struct npc_invasion_azsuna_acstrisAI : ScriptedAI
    {
        npc_invasion_azsuna_acstrisAI(Creature* creature) : ScriptedAI(creature) 
        {
            ResummonAdds = true;
            TimerAdds = urand(1000, 3000);
        }
        
        EventMap events;
        bool ResummonAdds;
        uint32 TimerAdds;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            ResummonAdds = false;
            events.RescheduleEvent(EVENT_1, 3000); // 234497
        }
        
        void JustDied(Unit* who) override
        {
            if (Player* pl = me->FindNearestPlayer(50.0f))
            {
                pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56893);
                pl->CreateConversation(4591);
            }
        }
    
        void UpdateAI(uint32 diff) override
        {
            if (ResummonAdds)
            {
                if (TimerAdds <= diff)
                {
                    me->SummonCreature(119633, 1444.47f + irand(-2, 2), 6090.65f +irand(-2, 2), 480.33f);
                    TimerAdds = urand(1000, 3000);
                }
                else
                    TimerAdds -= diff;
            }
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
                        DoCast(234497);
                        events.RescheduleEvent(EVENT_1, 3000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_azsuna_acstrisAI(creature);
    }
};


void AddSC_InvasionAzsuna()
{
    new npc_invasion_azsuna_misc();
    new npc_invasion_azsuna_dragons();
    new npc_invasion_azsuna_bes();
    new npc_invasion_azsuna_acstris();
};