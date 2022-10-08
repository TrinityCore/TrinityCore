/*
    http://uwow.biz
    Invasion Stormheim
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "CreatureTextMgr.h"
#include "QuestData.h"

// 116867
class npc_invasion_stormheim_vetir : public CreatureScript
{
public:
    npc_invasion_stormheim_vetir() : CreatureScript("npc_invasion_stormheim_vetir") {}

    struct npc_invasion_stormheim_vetirAI : npc_escortAI
    {
        npc_invasion_stormheim_vetirAI(Creature* creature) : npc_escortAI(creature)
        {
            PlayerOn = false;
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 timerforcheck;
        bool PlayerOn;
        

        void OnCharmed(bool /*apply*/) override
        {

        }
        
        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }
        
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->IsPlayer())                
            {
                if (Player* player = who->ToPlayer())
                {
                    PlayerOn = true;
                    Start(false, true, player->GetGUID());  // 10993813
                }
            }
        }
        
        void WaypointReached(uint32 i) override
        {
            switch(i)
            {
                case 20:
                    if (Unit* unit = me->GetAnyOwner())
                        if (Player* player = unit->ToPlayer())
                        {
                            if (Vehicle* vehicle = me->GetVehicleKit())
                                vehicle->RemoveAllPassengers();
                            me->DespawnOrUnsummon(1000);
                            player->AddDelayedEvent(1000, [player] {

                                player->TeleportTo(1220, 4951.40f, 380.97f, 74.63f, 4.13f, TELE_TO_SEAMLESS);
                                player->CastSpell(player, 232864);
                            });
                        }
                  break;
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (PlayerOn)
            {
                if (Player* player = GetPlayerForEscort())
                    player->SetClientControl(me, 0);
                PlayerOn = false;
            }
             
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_stormheim_vetirAI(creature);
    }
};

// 118566
class npc_invasion_stormheim_aleksis : public CreatureScript
{
public:
    npc_invasion_stormheim_aleksis() : CreatureScript("npc_invasion_stormheim_aleksis") { }
        
    struct npc_invasion_stormheim_aleksisAI : ScriptedAI
    {
        npc_invasion_stormheim_aleksisAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            events.RescheduleEvent(EVENT_1, 6000); // 242729
            events.RescheduleEvent(EVENT_2, 15000); // 235784 (start outro)
            Talk(0);
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
                        DoCast(242729);
                        Talk(1);
                        break;
                    case EVENT_2:
                        DoCast(235784);
                        Talk(2);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
                        me->AddDelayedEvent(5000, [this] () -> void
                        {
                            Talk(3);
                            const std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
                            for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                                if (Player* player = (*itr)->getTarget()->ToPlayer())
                                {
                                    player->AddAura(235096, player);
                                    player->AddDelayedEvent(18000, [player] () -> void
                                    {
                                        player->KilledMonsterCredit(118566);
                                        player->CreateConversation(4193);
                                    });
                                }
                        });
                        
                        me->AddDelayedEvent(9000, [this] () -> void
                        {
                            Talk(3);
                        });
                        
                        me->DespawnOrUnsummon(10000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_stormheim_aleksisAI(creature);
    }
};

// 119197, 119198, 119196
class npc_invasion_stormheim_dragons : public CreatureScript
{
public:
    npc_invasion_stormheim_dragons() : CreatureScript("npc_invasion_stormheim_dragons") {}

    struct npc_invasion_stormheim_dragonsAI : ScriptedAI
    {
        npc_invasion_stormheim_dragonsAI(Creature* creature) : ScriptedAI(creature)
        {
            timerforcheck  = 1000;
            check = false;
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 timerforcheck;
        bool check;
        
        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }
        
        void OnCharmed(bool /*apply*/) override
        {

        }
        
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->IsPlayer())                
            {
                if (Player* player = who->ToPlayer())
                {
                    me->AddDelayedEvent(2000, [this, player] () -> void
                    {
                        player->SetClientControl(me, false);                        
                        me->AddDelayedEvent(3000, [this] () -> void
                        {
                            me->GetMotionMaster()->MovePath((urand(1, 2) == 1 ? 10993814 : 10993815), true, irand(-20, 20), irand(-20, 20));
                        });
                    });
                }
            }
        }
        
        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;
            
            if (!check)
                return;

            if (me->GetVehicleKit() && pointId == 12)
            {
                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                    passenger->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56604);
                    passenger->AddAura(55001, passenger);
                    me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon(500);
                }
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!check)
            {
                if (timerforcheck <= diff)
                {
                    if (me->GetAnyOwner())
                        if (InstanceScript* instance = me->GetInstanceScript())
                            if (instance->getScenarionStep() == 2)
                            {
                                check = true;
                                me->GetMotionMaster()->MovePath(10993816, false);
                            }
                           
                    timerforcheck = 1000;
                }
                else
                    timerforcheck -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_stormheim_dragonsAI(creature);
    }
};

// 239285 241681 239255
class spell_invasion_teleport_misc : public SpellScriptLoader
{
    public:
        spell_invasion_teleport_misc() : SpellScriptLoader("spell_invasion_teleport_misc") { }

        class spell_invasion_teleport_misc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_invasion_teleport_misc_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* pCaster = GetCaster()->ToPlayer())
                {
                    switch(GetSpellInfo()->Id)
                    {
                        case 239285: // Azsuna
                            pCaster->TeleportTo(1220, 11.0f, 6734.76f, 55.58f, 3.17f);
                            break;
                        case 241681: // HM
                            pCaster->TeleportTo(1220, 4268.68f, 4563.80f, 670.46f, 0.0f);
                            break;
                        case 239255: // Stormheim
                            pCaster->TeleportTo(1220, 2414.27f, 872.90f, 253.03f, 3.9f);
                            break;
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_invasion_teleport_misc_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_ACTIVATE_SCENE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_invasion_teleport_misc_AuraScript();
        }
};


void AddSC_InvasionStormheim()
{
    new npc_invasion_stormheim_vetir();
    new npc_invasion_stormheim_aleksis();
    new npc_invasion_stormheim_dragons();
    new spell_invasion_teleport_misc();
};