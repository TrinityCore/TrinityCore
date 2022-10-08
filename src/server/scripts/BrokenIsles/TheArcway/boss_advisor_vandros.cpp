#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "the_arcway.h"

enum Spells
{
    SPELL_CHRONO_SHARDS         = 203881,
    SPELL_SUMMON_CHRONO_SHARD   = 203254,
    SPELL_CHRONO_SHARD_PULSE    = 203835,
    SPELL_CHRONO_SHARD_SPAWN    = 203823,
    SPELL_ACCELERATING_BLAST    = 203176,
    SPELL_FORCE_BOMB            = 202974,
    SPELL_FORCE_BOMB_AREA       = 202975,
    SPELL_FORCE_DETONATION      = 203087,
    SPELL_FORCE_NOVA_AREA       = 203090,
    SPELL_FORCE_NOVA_DMG        = 203139,
    SPELL_TIME_SPLIT            = 203833,
    SPELL_BANISH_IN_TIME        = 203882,
    SPELL_BANISH_IN_TIME_AURA   = 203914, // Visual Effect on Screen
    SPELL_BANISH_IN_TIME_TELE   = 203883,
    SPELL_LOST_IN_TIME          = 203935,
    SPELL_UNSTABLE_MANA         = 220871,
    SPELL_UNSTABLE_MANA_DMG     = 220872,

    SPELL_TIME_LOCK             = 203957,
    SPELL_BREACH_DMG            = 203954,
};

enum Events
{
    EVENT_CHRONO_SHARDS         = 1,
    EVENT_ACCELERATING_BLAST    = 2,
    EVENT_FORCE_BOMB            = 3,
    EVENT_UNSTABLE_MANA         = 4,
    EVENT_BANISH_IN_TIME        = 5,

    EVENT_TIME_LOCK             = 6,
};

enum Says
{
    SAY_INTRO           = 0,
    SAY_INTRO_2         = 1,
    SAY_AGGRO           = 2,
    SAY_CHRONO          = 3,
    SAY_BANISH          = 4,
    SAY_REACH_SUCCESFUL = 5,
    SAY_KILL            = 6,
    SAY_WIPE            = 7,
    SAY_DEATH           = 8,
};

Position VandrosTeleportLocations [] = 
{
    { 3144.530f, 4662.319f, 574.185f, 1.41f }, // Naltira Room
    { 3319.854f, 4522.469f, 570.788f, 1.53f }, // Xakal Room
    { 3155.316f, 5102.332f, 623.203f, 5.22f }, // Ivanyr Room
    { 3147.322f, 4887.054f, 617.710f, 0.20f }, // Corstilax Room
};

uint32 ROOM_POSITION = 0;
constexpr uint32 DATA_LOST_IN_TIME = 1;
//constexpr uint32 LOST_IN_TIME_PHASE = 290;

class boss_advisor_vandros : public CreatureScript
{
    public:
        boss_advisor_vandros() : CreatureScript("boss_advisor_vandros")
        {}

        struct boss_advisor_vandros_AI : public BossAI
        {
            explicit boss_advisor_vandros_AI(Creature* creature) : BossAI(creature, DATA_ADVISOR_VANDROS)
            {
                _lostInTime = false;
            }

            uint32 GetData(uint32 id) const override
            {
                if (id == DATA_LOST_IN_TIME)
                    return _reachSuccesful ? 0 : 1;

                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }
            
            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                me->SetReactState(REACT_AGGRESSIVE);
                _JustReachedHome();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }
            
            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Talk(SAY_DEATH);
                _JustDied();
            }

            void EnterCombat(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                Talk(SAY_AGGRO);
                _lostInTime = false;
                _EnterCombat();
                events.ScheduleEvent(EVENT_FORCE_BOMB, Seconds(30));
                events.ScheduleEvent(EVENT_CHRONO_SHARDS, Seconds(10));
                events.ScheduleEvent(EVENT_ACCELERATING_BLAST, Seconds(3));
            }

            void DamageTaken(Unit* /**/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(50) && !_lostInTime)
                {
                    _lostInTime = true;
                    _reachSuccesful = false;
                    ROOM_POSITION = urand(0,3);
                    events.DelayEvents(5000);
                    events.ScheduleEvent(EVENT_BANISH_IN_TIME, 100);
                }
            }

            void SpellHit(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;
                
                if (spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST) && me->HasAura(SPELL_BANISH_IN_TIME))
                {
                    _reachSuccesful = true;
                    Talk(SAY_REACH_SUCCESFUL);
                    me->CastStop();
                    me->SetReactState(REACT_AGGRESSIVE);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANISH_IN_TIME_AURA);
                    events.ScheduleEvent(EVENT_UNSTABLE_MANA, Seconds(15));
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_BANISH_IN_TIME:
                    {
                        Talk(SAY_BANISH);
                        me->CastSpell(me, SPELL_BANISH_IN_TIME, false);
                        break;
                    }

                    case EVENT_ACCELERATING_BLAST:
                    {
                        DoCastVictim(SPELL_ACCELERATING_BLAST);
                        events.ScheduleEvent(EVENT_ACCELERATING_BLAST, Seconds(7));
                        break;
                    }

                    case EVENT_CHRONO_SHARDS:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_CHRONO);

                        for (uint32 i = 3; i > 0; --i)
                        {
                            if (i % 2 == 0)
                                DoCast(me, SPELL_CHRONO_SHARDS, true);
                            else
                                DoCast(me, SPELL_SUMMON_CHRONO_SHARD, true);
                        }

                        events.ScheduleEvent(EVENT_CHRONO_SHARDS, Seconds(12));
                        break;
                    }

                    case EVENT_FORCE_BOMB:
                    {
                        DoCast(me, SPELL_FORCE_BOMB);
                        events.ScheduleEvent(EVENT_FORCE_BOMB, Seconds(30));
                        break;
                    }

                    case EVENT_UNSTABLE_MANA:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_UNSTABLE_MANA);
                        
                        events.ScheduleEvent(EVENT_UNSTABLE_MANA, Seconds(40));
                        break;
                    }

                    default : break;
                }
            }

            private:
                bool _lostInTime;
                bool _reachSuccesful;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_advisor_vandros_AI(creature);
        }
};

class npc_arc_chrono_shard : public CreatureScript
{
    public:
        npc_arc_chrono_shard() : CreatureScript("npc_arc_chrono_shard")
        {}

        struct npc_arc_chrono_shard_AI : public ScriptedAI
        {
            explicit npc_arc_chrono_shard_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->CastSpell(me, SPELL_CHRONO_SHARD_SPAWN, true);
            }
            
            void IsSummonedBy(Unit* /**/) override
            {
                me->CastSpell(me, SPELL_CHRONO_SHARD_PULSE, true);
                me->GetMotionMaster()->MovePoint(0, me->GetRandomNearPosition(25));
                _timerExplotion = 0;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == 0)
                    me->AddUnitState(UNIT_STATE_ROOT);
            }

            void UpdateAI(uint32 diff) override
            {
                _timerExplotion += diff;

                if (_timerExplotion >= 8 * IN_MILLISECONDS)
                {
                    _timerExplotion = 0;
                    DoCast(me, SPELL_TIME_SPLIT, true);
                    me->DespawnOrUnsummon(4000);
                }
            }

            private:
                uint32 _timerExplotion;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_arc_chrono_shard_AI(creature);
        }
};

class npc_arc_timeless_wraith : public CreatureScript
{
    public:
        npc_arc_timeless_wraith() : CreatureScript("npc_arc_timeless_wraith")
        {}

        struct npc_arc_timeless_wraith_AI : public ScriptedAI
        {
            explicit npc_arc_timeless_wraith_AI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset() override
            {
                //me->SetInPhase(2, true, true);
                _events.Reset();
            }

            void EnterCombat(Unit* victim) override
            {
                if (!victim)
                    return;

                if (!victim->HasAura(SPELL_BANISH_IN_TIME_AURA))
                    return;
                
                DoZoneInCombat();
                DoCast(victim, SPELL_TIME_LOCK);
                _events.ScheduleEvent(EVENT_TIME_LOCK, Seconds(2));
            }

            bool CanAIAttack(Unit const* target) const override
            {
                if (!target)
                    return false;
                
                if (!target->HasAura(SPELL_BANISH_IN_TIME_AURA))
                    return false;
                
                return true;
            }

            void SpellHit(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;
                
                if (spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST) && me->HasUnitState(UNIT_STATE_CASTING))
                    _events.RescheduleEvent(EVENT_TIME_LOCK, Seconds(5));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_TIME_LOCK)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_TIME_LOCK, false);
                        
                        _events.ScheduleEvent(EVENT_TIME_LOCK, Seconds(8));
                    }
                }
                
                DoMeleeAttackIfReady();
            };

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_arc_timeless_wraith_AI(creature);
        }
};

class spell_vandros_force_bomb : public SpellScriptLoader
{
    public:
        spell_vandros_force_bomb() : SpellScriptLoader("spell_vandros_force_bomb")
        {}

        class spell_force_bomb_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_force_bomb_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;
                    
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FORCE_BOMB_AREA, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_force_bomb_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_force_bomb_SpellScript();
        }
};

class spell_vandros_unstable_mana : public SpellScriptLoader
{
    public:
        spell_vandros_unstable_mana() : SpellScriptLoader("spell_vandros_unstable_mana")
        {}

        class spell_unstable_mana_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_unstable_mana_AuraScript);
        
                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;
                    
                    Unit*&& owner = GetUnitOwner();

                    owner->CastSpell(owner, SPELL_UNSTABLE_MANA_DMG, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_unstable_mana_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_unstable_mana_AuraScript();
        }
};

class spell_vandros_banish_in_time : public SpellScriptLoader
{
    public:
        spell_vandros_banish_in_time() : SpellScriptLoader("spell_vandros_banish_in_time")
        {}

        class spell_banish_in_time_SpellScript : public SpellScript
        {
            public:
              PrepareSpellScript(spell_banish_in_time_SpellScript);

                void HandleBeforeCast()
                {
                    for (auto & it : GetCaster()->GetMap()->GetPlayers())
                    {
                        if (Player* player = it.GetSource())
                            player->CastSpell(player, SPELL_BANISH_IN_TIME_AURA, true);
                    }

                    //GetCaster()->SetInPhase(2, true, true);
                }

                void Register() override
                {
                    BeforeCast += SpellCastFn(spell_banish_in_time_SpellScript::HandleBeforeCast);
                }
        };

        class spell_banish_in_time_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_banish_in_time_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (GetCaster()->GetAI()->GetData(DATA_LOST_IN_TIME) == 1)
                    {
                        InstanceScript* instance = GetCaster()->GetInstanceScript();

                        if (instance)
                            instance->DoCastSpellOnPlayers(SPELL_LOST_IN_TIME);
                    }
                    //GetCaster()->SetInPhase(2, true, false);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_banish_in_time_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_banish_in_time_AuraScript();
        }

        SpellScript* GetSpellScript() const override
        {
            return new spell_banish_in_time_SpellScript();
        }
        
};

class spell_vandros_banish_in_time_buff : public SpellScriptLoader
{
    public:
        spell_vandros_banish_in_time_buff() : SpellScriptLoader("spell_vandros_banish_in_time_buff")
        {}

        class spell_banish_in_time_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_banish_in_time_AuraScript);

                void HandleOnApply(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;
                    
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BANISH_IN_TIME_TELE, true);
                    //GetUnitOwner()->SetInPhase(2, true, true);
                }

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    //GetUnitOwner()->SetInPhase(2, true, false);
                }

                void Register() override
                {
                    OnEffectApply += AuraEffectApplyFn(spell_banish_in_time_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
                    OnEffectRemove += AuraEffectRemoveFn(spell_banish_in_time_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_banish_in_time_AuraScript();
        }
};

class spell_vandros_banish_in_time_tele : public SpellScriptLoader
{
    public:
        spell_vandros_banish_in_time_tele() : SpellScriptLoader("spell_vandros_banish_in_time_tele")
        {
        }
        
        class spell_banish_in_time_tele_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_banish_in_time_tele_SpellScript);

                void HandleTeleport()
                {
                    WorldLocation pos;

                    pos.Relocate(VandrosTeleportLocations[ROOM_POSITION]);
                    
                    SetExplTargetDest(pos);
                }

                void Register() override
                {
                    BeforeCast += SpellCastFn(spell_banish_in_time_tele_SpellScript::HandleTeleport);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_banish_in_time_tele_SpellScript();
        }
};

class spell_arc_breach : public SpellScriptLoader
{
    public:
        spell_arc_breach() : SpellScriptLoader("spell_arc_breach")
        {}

        class spell_arc_breach_AuraScript :  public AuraScript
        {
            public:
                PrepareAuraScript(spell_arc_breach_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;
                    
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BREACH_DMG, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_arc_breach_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_arc_breach_AuraScript();
        }
};

class at_arc_force_bomb : public AreaTriggerEntityScript
{
    public:
        at_arc_force_bomb() : AreaTriggerEntityScript("at_arc_force_bomb")
        {}

        struct at_arc_force_bomb_AI : public AreaTriggerAI
        {
            explicit at_arc_force_bomb_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerForce = 0;
            }

            void OnUpdate(uint32 diff) override
            {
                _timerForce += diff;

                if (_timerForce >= 4000)
                {
                    _timerForce = 0;
                    at->GetCaster()->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_FORCE_NOVA_AREA, true);
                    at->GetCaster()->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_FORCE_DETONATION, true);
                }
            }

            private:
                uint32 _timerForce;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_force_bomb_AI(at);
        }
};

class at_arc_force_nova : public AreaTriggerEntityScript
{
    public:
        at_arc_force_nova() : AreaTriggerEntityScript("at_arc_force_nova")
        {}

        struct at_arc_force_nova_AI : public AreaTriggerAI
        {
            explicit at_arc_force_nova_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerForce = 0;
                _radius = 10.f;
            }

            void OnUpdate(uint32 diff) override
            {
                _timerForce += diff;

                if (_timerForce >= 500)
                {
                    _timerForce = 0;
                    
                    for (auto & it : at->GetMap()->GetPlayers())
                    {
                        Player* ptr = it.GetSource();

                        if (!ptr)
                            continue;
                        
                        float dist = ptr->GetDistance2d(at);
                        
                        if (std::fabs(dist - _radius) <= 3.f)
                            OnUnitEnter(ptr);
                        else
                            OnUnitExit(ptr);
                    }
                    _radius += 4.f;
                }
            }
            
            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    //float dist = target->GetDistance2d(at);
                    target->CastSpell(target, SPELL_FORCE_NOVA_DMG, true);
                }
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_FORCE_NOVA_DMG);
            }

            private:
                uint32 _timerForce;
                float _radius;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_force_nova_AI(at);
        }
};

void AddSC_boss_advisor_vandros()
{
    new boss_advisor_vandros();
    new npc_arc_chrono_shard();
    new npc_arc_timeless_wraith();
    new at_arc_force_bomb();
    new at_arc_force_nova();
    new spell_vandros_force_bomb();
    new spell_vandros_banish_in_time();
    new spell_vandros_banish_in_time_buff();
    new spell_vandros_banish_in_time_tele();
    new spell_vandros_unstable_mana();
    new spell_arc_breach();
}
