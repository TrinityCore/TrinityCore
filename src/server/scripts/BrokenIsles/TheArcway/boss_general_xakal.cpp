#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "the_arcway.h"

enum Spells
{
    // General Xakal
    SPELL_FEL_FISSURE           = 197776,
    SPELL_FEL_FISSURE_SUMMON    = 197765,
    SPELL_FEL_FISSURE_RUNE      = 197542,
    SPELL_FEL_FISSURE_SPIKE     = 197573,
    SPELL_FEL_ERUPTION          = 197579,
    SPELL_WICKED_SLAM           = 197810,
    SPELL_SHADOW_SLASH          = 212030,
    SPELL_SHADOW_SLASH_DMG      = 212071,
    SPELL_WAKE_OF_SHADOW        = 220441,
    SPELL_WAKE_OF_SHADOW_DMG    = 220443,
    SPELL_SHATTER               = 197814,

    // Dread Felbat
    SPELL_BOMBARDMENT_MISSILE   = 197787,
    SPELL_BOMBARDMENT_AURA      = 197786,
    SPELL_THIRST_BLOOD          = 220533,
};

enum Events
{
    EVENT_FEL_FISSURE   = 1,
    EVENT_WICKED_SLAM   = 2,
    EVENT_SHADOW_SLASH  = 3,
    EVENT_CALL_BATS     = 4,
    EVENT_RESTORE_STATE = 5,
    EVENT_BOMBARDMENT   = 6,

    EVENT_THIRST_BLOOD  = 7,
};

enum Adds
{
    NPC_FISSURE         = 100342,
    NPC_DREAD_FELBAT    = 100393,
};

enum Says
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_FEL_FISSURE = 2,
    SAY_SHADOW_SLASH= 3,
    SAY_FEL_BATS    = 4,
    SAY_KILL        = 5,
    SAY_WIPE        = 6,
    SAY_DEAD        = 7,
};

enum Actions 
{
    ACTION_RUNE_ACTIVATED   = 1,
    ACTION_BAT_ATTACK       = 2,
};


using Vector3d = G3D::Vector3;

const Position BatCenterPos = { 3319.334f, 4522.911f, 633.228f };

class boss_general_xakal : public CreatureScript
{
    public:
        boss_general_xakal() : CreatureScript("boss_general_xakal")
        {}

        struct boss_general_xakal_AI : public BossAI
        {
            boss_general_xakal_AI(Creature* creature) : BossAI(creature, DATA_GENERAL_XAKAL)
            {}

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_FISSURE)
                    summon->CastSpell(summon, SPELL_FEL_FISSURE_RUNE, true);
                else if (summon->GetEntry() == NPC_DREAD_FELBAT)
                    summon->GetMotionMaster()->MoveRandom(25.f);

                BossAI::JustSummoned(summon);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                me->RemoveAllAreaTriggers();
                BossAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /**/) override
            {
                me->RemoveAllAreaTriggers();
                Talk(SAY_DEAD);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                for (uint8 i = 0; i < 20; ++i)
                    DoSummon(NPC_DREAD_FELBAT, BatCenterPos, 5000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);

                events.ScheduleEvent(EVENT_FEL_FISSURE, Seconds(5));
                events.ScheduleEvent(EVENT_WICKED_SLAM, Seconds(55));
                events.ScheduleEvent(EVENT_SHADOW_SLASH, Seconds(13));
                events.ScheduleEvent(EVENT_BOMBARDMENT, Seconds(10));
                events.ScheduleEvent(EVENT_CALL_BATS, Seconds(30));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId) 
                {
                    case EVENT_FEL_FISSURE:
                    {
                        Talk(SAY_FEL_FISSURE);
                        DoCastAOE(SPELL_FEL_FISSURE);
                        
                        events.ScheduleEvent(EVENT_FEL_FISSURE, Seconds(11));
                        break;
                    }

                    case EVENT_WICKED_SLAM:
                    {
                        DoCast(SPELL_WICKED_SLAM);
                        events.ScheduleEvent(EVENT_WICKED_SLAM, Seconds(30));
                        break;
                    }

                    case EVENT_SHADOW_SLASH:
                    {
                        Talk(SAY_SHADOW_SLASH);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,0, true))
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->StopMoving();
                            DoCast(target, SPELL_SHADOW_SLASH);
                            events.ScheduleEvent(EVENT_RESTORE_STATE, Seconds(2));
                        }

                        events.ScheduleEvent(EVENT_SHADOW_SLASH, Seconds(11));
                        break;
                    }

                    case EVENT_RESTORE_STATE:
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    }

                    case EVENT_BOMBARDMENT:
                    {
                        uint32 bats = urand(1, 2);
                        uint8 activatedBats = 0;

                        for (auto & it : summons)
                        {
                            if (auto* bat = ObjectAccessor::GetCreature(*me, it))
                            {
                                if (bat->GetEntry() == NPC_DREAD_FELBAT)
                                {
                                    bat->CastSpell(bat, SPELL_BOMBARDMENT_AURA, true);
                                    activatedBats++;

                                    if (activatedBats >= bats)
                                        break;
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_CALL_BATS, Seconds(15));
                        break;
                    }

                    case EVENT_CALL_BATS:
                    {
                        Talk(SAY_FEL_BATS);
                        uint8 activatedBats = 0;

                        for (auto & it : summons)
                        {
                            if (auto* bat = ObjectAccessor::GetCreature(*me, it))
                            {
                                if (bat->GetEntry() == NPC_DREAD_FELBAT)
                                {
                                    bat->GetAI()->DoAction(ACTION_BAT_ATTACK);
                                    activatedBats++;
                                    if (activatedBats >= 2)
                                        break;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_CALL_BATS, Seconds(30));
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_general_xakal_AI(creature);
        }
};

class npc_arc_fissure : public CreatureScript
{
    public:
        npc_arc_fissure() : CreatureScript("npc_arc_fissure")
        {}

        struct npc_arc_fissure_AI : public ScriptedAI
        {
            npc_arc_fissure_AI(Creature* creature) : ScriptedAI(creature)
            {
                _activated = false;
            }

            void CheckTargetNear()
            {
                for (auto & it : me->GetMap()->GetPlayers())
                {
                    if (auto* player = it.GetSource())
                    {
                        DoCast(me, SPELL_FEL_ERUPTION, true);
                        _timerCheck = 0;
                        break;
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_RUNE_ACTIVATED)
                    _activated = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!_activated)
                    return;
                
                _timerCheck += diff;

                if (_timerCheck >= 3500)
                {
                    _timerCheck = 0;
                    CheckTargetNear();
                }
            }

            private:
                bool _activated;
                uint32 _timerCheck;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_arc_fissure_AI(creature);
        }
};

class npc_arc_dread_felbat : public CreatureScript
{
    public:
        npc_arc_dread_felbat() : CreatureScript("npc_arc_dread_felbat")
        {}

        struct npc_arc_dread_felbat_AI : public ScriptedAI
        {
            explicit npc_arc_dread_felbat_AI(Creature* creature) : ScriptedAI(creature)
            {
                _isInLand = false;
                me->SetReactState(REACT_PASSIVE);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == CHASE_MOTION_TYPE && !_isInLand)
                {
                    _isInLand = true;
                    me->SetCanFly(false);
                    me->SetDisableGravity(false);
                    _events.ScheduleEvent(EVENT_THIRST_BLOOD, Seconds(10));
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_BAT_ATTACK)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        me->GetMotionMaster()->MoveChase(target);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_THIRST_BLOOD)
                    {
                        DoCastVictim(SPELL_THIRST_BLOOD);
                        _events.ScheduleEvent(EVENT_THIRST_BLOOD, Seconds(15));
                    }
                }

                if (_isInLand)
                    DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                bool _isInLand;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_arc_dread_felbat_AI(creature);
        }
};

class spell_arc_bombardment : public SpellScriptLoader
{
    public:
        spell_arc_bombardment() : SpellScriptLoader("spell_arc_bombardment")
        {}

        class spell_arc_bombardment_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_arc_bombardment_AuraScript);

                bool Load() override
                {
                    _counter = 0;
                    return true;
                }

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    _counter++;

                    if (_counter < 5)
                        return;

                    if (Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        GetCaster()->CastSpell(target, SPELL_BOMBARDMENT_MISSILE, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_arc_bombardment_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }

                private:
                    uint8 _counter;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_arc_bombardment_AuraScript();
        }
};

class spell_xakal_fel_fissure : public SpellScriptLoader
{
    public:
        spell_xakal_fel_fissure() : SpellScriptLoader("spell_xakal_fel_fissure")
        {}

        class spell_xakal_fel_fissure_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_xakal_fel_fissure_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;
                    
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FEL_FISSURE_SUMMON, true);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_xakal_fel_fissure_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_xakal_fel_fissure_SpellScript();
        }
};

class at_arc_fel_fissure : public AreaTriggerEntityScript
{
    public:
        at_arc_fel_fissure() : AreaTriggerEntityScript("at_arc_fel_fissure")
        {}

        struct at_arc_fel_fissure_AI : public AreaTriggerAI
        {
            at_arc_fel_fissure_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
            }

            void OnInitialize()
            {
                _borned = false;
                _activated = false;
                _timerBorn = 0;
               // _caster = at->GetCaster();
            }

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;
                
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;
                
                if (!_borned)
                    return;

                if (!_activated)
                {
                    _activated = true;
                    _caster->CastSpell(_caster, SPELL_FEL_FISSURE_SPIKE, true);
                    _caster->GetAI()->DoAction(ACTION_RUNE_ACTIVATED);
                    _caster->CastSpell(_caster, SPELL_FEL_ERUPTION, true);
                    //at->Remove();
                }
            }

            void OnUpdate(uint32 diff) override
            {
                if (_borned)
                    return;

                _timerBorn += diff;

                if (_timerBorn >= 5 * IN_MILLISECONDS && !_borned)
                    _borned = true;
            }

            private:
                uint32 _timerBorn;
                bool _activated;
                bool _borned;
                Unit* _caster;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_fel_fissure_AI(at);
        }
};

class at_arc_wake_of_shadow : public AreaTriggerEntityScript
{
    public:
        at_arc_wake_of_shadow() : AreaTriggerEntityScript("at_arc_wake_of_shadow")
        {}

        struct at_arc_wake_of_shadow_AI : public AreaTriggerAI
        {
            at_arc_wake_of_shadow_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;
                
                if (unit->GetTypeId() != TYPEID_PLAYER)
                    return;
                
                unit->CastSpell(unit, SPELL_WAKE_OF_SHADOW_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (!target)
                    return;
                
                if (target->GetTypeId() != TYPEID_PLAYER)
                    return;
                
                target->RemoveAurasDueToSpell(SPELL_WAKE_OF_SHADOW_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_wake_of_shadow_AI(at);
        }
};

void AddSC_boss_general_xakal()
{
    new boss_general_xakal();
    new npc_arc_fissure();
    new npc_arc_dread_felbat();
    new spell_xakal_fel_fissure();
    new spell_arc_bombardment();
    new at_arc_wake_of_shadow();
    new at_arc_fel_fissure();
}
