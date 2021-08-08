/*
    http://uwow.biz
    Invasion Valshara
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"

// 117838
class npc_crushfist : public CreatureScript
{
public:
    npc_crushfist() : CreatureScript("npc_crushfist") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_crushfistAI(creature);
    }
    
    struct npc_crushfistAI : ScriptedAI
    {
        npc_crushfistAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
        }
        
        EventMap events;
        bool _introDone;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 4000); // 234473 + 17
            events.RescheduleEvent(EVENT_2, 8000); // 234446 + 15
        }
        
        void EnterEvadeMode() override
        {
            _introDone = false;
        }
        
        void MoveInLineOfSight(Unit* who) override
        {  
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;
            
            
            if (!_introDone && me->IsWithinDistInMap(who, 75.0f))
            {
                _introDone = true;
                me->GetMotionMaster()->MoveJump(3215.36f, 7862.98f, 0.39f, 10, 10);
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
                        DoCast(234473);
                        events.RescheduleEvent(EVENT_1, 17000); // 234473 + 17
                        break;
                    case EVENT_2:
                        DoCast(234446);
                        events.RescheduleEvent(EVENT_2, 16000); // 234446 + 15
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 117833
class npc_benefit_akrazar : public CreatureScript
{
public:
    npc_benefit_akrazar() : CreatureScript("npc_benefit_akrazar") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_benefit_akrazarAI(creature);
    }
    
    struct npc_benefit_akrazarAI : ScriptedAI
    {
        npc_benefit_akrazarAI(Creature* creature) : ScriptedAI(creature)
        {
            _introDone = false;
        }
        
        EventMap events;
        bool _introDone;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 12000); // 234694 + 23
            events.RescheduleEvent(EVENT_2, 16000); // 235048 + 16 (todo)
        }
        
        
        void MoveInLineOfSight(Unit* who) override
        {  
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;
            
            
            if (!_introDone && me->IsWithinDistInMap(who, 35.0f))
            {
                _introDone = true;
                who->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56399);
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
                        DoCast(234694);
                        events.RescheduleEvent(EVENT_1, 23000); // 234694 + 23
                        break;
                    case EVENT_2:
                        DoCast(235048);
                        events.RescheduleEvent(EVENT_2, 16000); // 235048 + 16 (todo)
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
};

// 118687
class npc_invasion_valshara_gryph : public CreatureScript
{
public:
    npc_invasion_valshara_gryph() : CreatureScript("npc_invasion_valshara_gryph") {}

    struct npc_invasion_valshara_gryphAI : ScriptedAI
    {
        npc_invasion_valshara_gryphAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}
        
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            SetFlyMode(true);
            if (who->IsPlayer())
            {                
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (instance->getScenarionStep() == 6)
                        me->GetMotionMaster()->MovePath(9859007, false);
                    else if (instance->getScenarionStep() == 8)
                        me->GetMotionMaster()->MovePath(9859008, false);
            }
        }
        
        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;
            
            if (InstanceScript* instance = me->GetInstanceScript())
                if (instance->getScenarionStep() == 8)
                {
                    if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                    {
                        passenger->CastSpell(passenger, 241651);
                        passenger->AddDelayedEvent(5000, [passenger]() -> void
                        {
                            passenger->ToPlayer()->TeleportTo(1220, 2281.60f, 6596.24f, 137.58f, 0.0f);
                        }); 
                    }
                    return;
                }
            
            if (me->GetVehicleKit() && pointId == 10)
            {
                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                    if (passenger->IsPlayer())
                        passenger->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56400);
                    passenger->CreateConversation(4984);
                    passenger->AddAura(55001, passenger);
                    me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon(500);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_valshara_gryphAI(creature);
    }
};

class player_scripts_for_inv_val : public PlayerScript
{
    public:
        player_scripts_for_inv_val() : PlayerScript("player_scripts_for_inv_val") 
        {
            checktimer = 1000;
        }
        uint32 checktimer;
        std::set<ObjectGuid> playersJust{};
        
        void OnUpdate(Player* player, uint32 diff) override
        {
            if (playersJust.find(player->GetGUID()) == playersJust.end())
            {
                if (checktimer <= diff)
                {
                    if (player)
                        if (player->GetMapId() == 1704)
                            if (InstanceScript* instance = player->GetInstanceScript())
                                if (instance->getScenarionStep() == 8)
                                    if (player->GetPositionZ() <= 232.90f)
                                        if (Creature* gryphon = player->SummonCreature(118687, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0.0f))
                                        {   
                                            player->CastSpell(gryphon, 46598);
                                            playersJust.insert(player->GetGUID());
                                        }
                    checktimer = 1000;
                }
                else
                    checktimer -= diff;
            }
        }

};

void AddSC_InvasionValshara()
{
    new npc_crushfist();
    new npc_benefit_akrazar();
    new npc_invasion_valshara_gryph();
    new player_scripts_for_inv_val();
};