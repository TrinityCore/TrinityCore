
#include "iron_docks.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_WAR_HORN                  = 170909,
    SPELL_CANNON_BARRAGE            = 168511, // casted 3 seconds after the horn

    SPELL_CANNON_BARRAGE_DUMMY      = 168927,
    SPELL_GRONN_SMASH               = 168227,
    SPELL_GRONN_SMASH_2             = 168167,

    SPELL_CANNON_BARRAGE_CHANNEL    = 168929,
    SPELL_CANNON_BARRAGE_TRIGGERED  = 168390,
    SPELL_CHECK_FOR_PLAYERS         = 169071,
    SPELL_BACKDRAFT_TRIGGER         = 169131,

    // Cannon
    SPELL_TRIGGER_CANNON_BARRAGE    = 168129,
    SPELL_CANNON_BARRAGE_SHOOT      = 168384,

    // Backdraft
    SPELL_BACKDRAFT                 = 169129,
};

enum Events
{
    // Skulloc
    EVENT_GRONN_SMASH = 1,
    EVENT_MOVE_HOME,
    EVENT_CANNON_BARRAGE,
    EVENT_BACKDRAFT,
    
    // Koramar
    EVENT_TALK_GAUNTLET_1,
    EVENT_TALK_GAUNTLET_2,
    EVENT_TALK_GAUNTLET_3,
};

enum Phases
{
    PHASE_INTRO = 1,
    PHASE_COMBAT,
};

enum Texts
{
    // Skulloc
    SAY_ANNOUNCE_BARRAGE = 0,

    // Koramar
    // Zoggosh
    SAY_GAUNTLET_1      = 0,
    SAY_GAUNTLET_2      = 1,
};

enum Movepoints
{
    POINT_CANNON_BARRAGE = 1,
};

class BarrageCheck
{
public:
    BarrageCheck(Unit* caster) : caster(caster) { }

    bool operator()(WorldObject* object)
    {
        return (object->GetTypeId() == TYPEID_PLAYER && object->IsWithinLOSInMap(caster));
    }
private:
    Unit* caster;
};

class boss_skulloc : public CreatureScript
{
public:
    boss_skulloc() : CreatureScript("boss_skulloc") { }

    struct boss_skullocAI : public BossAI
    {
        boss_skullocAI(Creature* creature) : BossAI(creature, DATA_SKULLOC)
        {
        }

        void Reset() override
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            _EnterCombat();
            events.ScheduleEvent(EVENT_GRONN_SMASH, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustDied();
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_SKULLOC, FAIL);
            me->GetMotionMaster()->MoveTargetedHome();
            summons.DespawnAll();
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
                case POINT_CANNON_BARRAGE:
                    events.ScheduleEvent(EVENT_CANNON_BARRAGE, 1);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GRONN_SMASH:
                        DoCast(me, SPELL_CANNON_BARRAGE_DUMMY, true);
                        DoCast(me, SPELL_GRONN_SMASH);
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        Talk(SAY_ANNOUNCE_BARRAGE);
                        events.ScheduleEvent(EVENT_MOVE_HOME, 1000);
                        break;
                    case EVENT_MOVE_HOME:
                        me->GetMotionMaster()->MovePoint(POINT_CANNON_BARRAGE, me->GetHomePosition(), true);
                        break;
                    case EVENT_CANNON_BARRAGE:
                        me->SetFacingTo(me->GetHomePosition().GetOrientation());
                        DoCast(me, SPELL_CANNON_BARRAGE_CHANNEL);
                        events.ScheduleEvent(EVENT_BACKDRAFT, 10500);
                        break;
                    case EVENT_BACKDRAFT:
                        DoCastAOE(SPELL_BACKDRAFT_TRIGGER, true);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_skullocAI>(creature);
    }
};

class boss_koramar : public CreatureScript
{
public:
    boss_koramar() : CreatureScript("boss_koramar") { }

    struct boss_koramarAI : public BossAI
    {
        boss_koramarAI(Creature* creature) : BossAI(creature, DATA_KORAMAR)
        {
        }

        void Reset() override
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustDied();
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->GetMotionMaster()->MoveTargetedHome();
            summons.DespawnAll();
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_GAUNTLET_1:
                    break;
                case ACTION_GAUNTLET_2:
                    events.SetPhase(PHASE_INTRO);
                    Talk(SAY_GAUNTLET_2);
                    events.ScheduleEvent(EVENT_TALK_GAUNTLET_2, 6000);
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !(events.IsInPhase(PHASE_INTRO)))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK_GAUNTLET_2:
                        if (Creature* zoggosh = me->FindNearestCreature(BOSS_ZOGGOSH, 50.0f, true))
                            zoggosh->AI()->Talk(SAY_GAUNTLET_2);
                        events.SetPhase(PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_koramarAI>(creature);
    }
};

class spell_skulloc_gronn_smash : public SpellScriptLoader
{
public:
    spell_skulloc_gronn_smash() : SpellScriptLoader("spell_skulloc_gronn_smash") { }

    class spell_skulloc_gronn_smash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skulloc_gronn_smash_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                target->CastSpell(target, SPELL_GRONN_SMASH_2, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_skulloc_gronn_smash_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_skulloc_gronn_smash_SpellScript();
    }
};

class spell_skulloc_cannon_barrage_channel_aura : public SpellScriptLoader
{
public:
    spell_skulloc_cannon_barrage_channel_aura() : SpellScriptLoader("spell_skulloc_cannon_barrage_channel_aura") { }

    class spell_skulloc_cannon_barrage_channel_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skulloc_cannon_barrage_channel_aura_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* cannon1 = caster->GetVehicleKit()->GetPassenger(0))
                    cannon1->CastSpell(cannon1, SPELL_TRIGGER_CANNON_BARRAGE);

                if (Unit* cannon2 = caster->GetVehicleKit()->GetPassenger(1))
                    cannon2->CastSpell(cannon2, SPELL_TRIGGER_CANNON_BARRAGE);
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature())
                    caster->ToCreature()->SetReactState(REACT_AGGRESSIVE);
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature())
                    caster->ToCreature()->AI()->DoCastAOE(SPELL_CANNON_BARRAGE_TRIGGERED);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_skulloc_cannon_barrage_channel_aura_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectApplyFn(spell_skulloc_cannon_barrage_channel_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skulloc_cannon_barrage_channel_aura_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_skulloc_cannon_barrage_channel_aura_AuraScript();
    }
};

class spell_skulloc_cannon_barrage_cannon_aura : public SpellScriptLoader
{
public:
    spell_skulloc_cannon_barrage_cannon_aura() : SpellScriptLoader("spell_skulloc_cannon_barrage_cannon_aura") { }

    class spell_skulloc_cannon_barrage_cannon_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skulloc_cannon_barrage_cannon_aura_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                float ori = caster->GetOrientation() + frand(-0.30f, 0.30f);
                float x = caster->GetPositionX();
                float y = caster->GetPositionY();
                float z = caster->GetPositionZ();
                float dist = frand(40.0f, 150.0f);

                float newY = y + sin(ori) * dist;
                float newX = x + cos(ori) * dist;

                caster->CastSpell(newX, newY, z, SPELL_CANNON_BARRAGE_SHOOT, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skulloc_cannon_barrage_cannon_aura_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_skulloc_cannon_barrage_cannon_aura_AuraScript();
    }
};

class spell_skulloc_backdraft_dummy : public SpellScriptLoader
{
public:
    spell_skulloc_backdraft_dummy() : SpellScriptLoader("spell_skulloc_backdraft_dummy") { }

    class spell_skulloc_backdraft_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skulloc_backdraft_dummy_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                target->CastSpell(target, SPELL_BACKDRAFT);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_skulloc_backdraft_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_skulloc_backdraft_dummy_SpellScript();
    }
};

class spell_skulloc_cannon_barrage_aoe : public SpellScriptLoader
{
public:
    spell_skulloc_cannon_barrage_aoe() : SpellScriptLoader("spell_skulloc_cannon_barrage_aoe") { }

    class spell_skulloc_cannon_barrage_aoe_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skulloc_cannon_barrage_aoe_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            targets.remove_if(BarrageCheck(GetCaster()));
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skulloc_cannon_barrage_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skulloc_cannon_barrage_aoe_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_skulloc_cannon_barrage_aoe_SpellScript();
    }
};

void AddSC_boss_skulloc()
{
    new boss_skulloc();
    new boss_koramar();
    new spell_skulloc_gronn_smash();
    new spell_skulloc_cannon_barrage_channel_aura();
    new spell_skulloc_cannon_barrage_cannon_aura();
    new spell_skulloc_backdraft_dummy();
    new spell_skulloc_cannon_barrage_aoe();
}
