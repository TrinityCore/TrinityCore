#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MoveSplineInit.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "thenighthold.h"
#include "CreatureAIImpl.h"
#include "Log.h"
#include "Object.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "MotionMaster.h"


enum Texts
{
    SAY_PHASE1_END  = 0,
    SAY_ACTIVATE    = 1, 
    SAY_NORTHREND = 2, // not use
    SAY_START     = 3, //new
    SAY_START2    = 4,
    SAY_PHASE1    = 5,
    SAY_PHASE1_1  = 6
};
enum Spells
{
    //putrid sludge
    SPELL_VILE_SLURGE       = 223528,
    SPELL_SLIME_POOL        = 223601,
    SPELL_SLUDGE_CRAWL      = 223511,
    SPELL_SLOP_BURST        = 214181,

    //Slizeron
    SPELL_DEATH_STATE       = 223721,
    SPELL_SLUDGE_ELUPTION   = 223955,

    //Trillax
    SPELL_DEATH_COSMETIC       = 223945,
    SPELL_ARCANE_SEEPAGE_PRC   = 206482,
    SPELL_ARCANE_SEEPAGE       = 206484,
    SPELL_ARCANE_SEEPAGE_DMG   = 206488,
};

enum Events
{
    EVENT_PHASE_0             = 1,
    EVENT_PHASE_1             = 2,
    EVENT_PHASE_1_START       = 3,
    EVENT_PHASE_1_TEXT        = 4,
    EVENT_PHASE_1_END         = 5,

    EVENT_SLUDGE              = 1,
    EVENT_SLOP_BURST          = 2,
    EVENT_ACTIVATE            = 3,

    EVENT_SLIME_POOL          = 1,

};

class boss_trilliax : public CreatureScript {
public:
    boss_trilliax() : CreatureScript("boss_trilliax") { }

    struct boss_trilliaxAI : public BossAI {
        boss_trilliaxAI(Creature* creature) : BossAI(creature, BOSS_TRILLIAX)
        {
        }

        uint8 curID;
        EventMap events;

        void EnterCombat(Unit* who) override
        {
            Talk(SAY_ACTIVATE);
            DoZoneInCombat();
            _EnterCombat();
            DoCast(SPELL_ARCANE_SEEPAGE_PRC);
        }

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_PHASE_0, 1000);
            me->SetHealth(me->GetMaxHealth());
            me->GetMotionMaster()->MoveTargetedHome();
            _Reset();

            if (!me->FindNearestCreature(112255, 100, true))
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAurasDueToSpell(SPELL_DEATH_COSMETIC);
            }
            else
                DoCast(SPELL_DEATH_COSMETIC);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void DoAction(int32 param)
        {
            if (param == 1)
            {
                events.ScheduleEvent(EVENT_PHASE_1_END, 5000);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->AI()->Talk(SAY_ACTIVATE);
                me->RemoveAurasDueToSpell(SPELL_DEATH_COSMETIC);
            }
        }

        void KilledUnit(Unit* who)
        {
            //if (who->ToPlayer())
            //   Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsInCombat())
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->IsInCombat())
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PHASE_0:
                {
                    if (me->SelectNearestPlayer(70.f))
                    {
                        if (me->FindNearestCreature(112255, 100, true))
                        {
                            Talk(SAY_START);
                            events.ScheduleEvent(EVENT_PHASE_1, 10000);
                        }
                        else
                            events.ScheduleEvent(EVENT_PHASE_0, 1000);
                    }
                    else
                        events.ScheduleEvent(EVENT_PHASE_0, 1000);
                    break;
                }
                case EVENT_PHASE_1:
                {
                    Talk(SAY_START2);
                    events.ScheduleEvent(EVENT_PHASE_1_START, 10000);
                    break;
                }
                case EVENT_PHASE_1_START:
                {
                    Talk(SAY_PHASE1);
                    events.ScheduleEvent(EVENT_PHASE_1_TEXT, 10000);
                    break;
                }
                case EVENT_PHASE_1_TEXT:
                {
                    Talk(SAY_PHASE1_1);
                    break;
                }
                case EVENT_PHASE_1_END:
                {
                    Talk(SAY_PHASE1_END);
                    me->RemoveAurasDueToSpell(SPELL_DEATH_COSMETIC);
                    break;
                }
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            //Talk(SAY_DEATH);
            _JustDied();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<boss_trilliaxAI>(creature);
    }
};

class npc_putrid_sludge : public CreatureScript {
public:
    npc_putrid_sludge() : CreatureScript("npc_putrid_sludge") { }

    struct npc_putrid_sludgeAI : public ScriptedAI {
        npc_putrid_sludgeAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void EnterCombat(Unit* who) override
        {
            DoCast(SPELL_VILE_SLURGE);
            events.ScheduleEvent(EVENT_SLUDGE, urand(5000, 7000));
            events.ScheduleEvent(EVENT_SLOP_BURST, 10000);
        }

        void Reset() override
        {
            events.Reset();
            me->SetHealth(me->GetMaxHealth());
            me->GetMotionMaster()->MoveTargetedHome();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void KilledUnit(Unit* who)
        {
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
                case EVENT_SLUDGE:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(target, SPELL_SLUDGE_CRAWL, false);
                    events.ScheduleEvent(EVENT_SLUDGE, 20000);
                    break;
                }
                case EVENT_SLOP_BURST:
                {
                    DoCast(SPELL_SLOP_BURST);
                    events.ScheduleEvent(EVENT_SLOP_BURST, 20000);
                    break;
                }
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            DoCast(SPELL_SLIME_POOL);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_putrid_sludgeAI>(creature);
    }
};

// 112293
class npc_tr_slime_pool : public CreatureScript {
public:
    npc_tr_slime_pool() : CreatureScript("npc_tr_slime_pool") { }

    struct npc_tr_slime_poolAI : public ScriptedAI {
        npc_tr_slime_poolAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        EventMap events;

        void EnterCombat(Unit* who) override
        {
           
        }

        void Reset() override
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->SetWalk(true);
            me->GetMotionMaster()->MovePoint(1, 454.637f, 3307.993f, -225.69f);
            DoCast(223574); // visual
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
            case 1:
                if (Creature * cre = me->FindNearestCreature(112255, 100, true))
                {
                    uint32 count = _instance->GetData(DATA_SLIME_POOL);
                    if (count >= 0)
                    {
                        count++;
                        _instance->SetData(DATA_SLIME_POOL, count);
                        if (count >= 8)
                        {
                            cre->AI()->DoAction(1);
                        }
                    }
                }
                break;
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void KilledUnit(Unit* who)
        {
        }

        void JustDied(Unit* killer) override
        {
        }

    private:
        InstanceScript * _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_tr_slime_poolAI>(creature);
    }
};

class npc_sludgerax : public CreatureScript {
public:
    npc_sludgerax() : CreatureScript("npc_sludgerax") { }

    struct npc_sludgeraxAI : public ScriptedAI {
        npc_sludgeraxAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        EventMap events;

        void EnterCombat(Unit* who) override
        {
           
        }

        void Reset() override
        {
            events.Reset();
            me->SetHealth(me->GetMaxHealth());
            me->GetMotionMaster()->MoveTargetedHome();

            DoCast(223710);
            DoCast(223721);
            if (uint32 count = _instance->GetData(DATA_SLIME_POOL))
            {
                if (count >= 8)
                {
                    me->AI()->DoAction(1);
                }
            }

        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();

            _EnterEvadeMode();
        }

        void DoAction(int32 param)
        {
            if (param == 1)
            {
                events.ScheduleEvent(EVENT_ACTIVATE, 1000);
            }
        }

        void KilledUnit(Unit* who)
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsInCombat())
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->IsInCombat())
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SLUDGE:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(target, SPELL_SLUDGE_CRAWL, false);
                    events.ScheduleEvent(EVENT_SLUDGE, 20000);
                    break;
                }
                case EVENT_SLOP_BURST:
                {
                    DoCast(SPELL_SLOP_BURST);
                    events.ScheduleEvent(EVENT_SLOP_BURST, 20000);
                    break;
                }
                case EVENT_ACTIVATE:
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(SPELL_DEATH_STATE);
                    break;
                }
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            DoCast(SPELL_SLUDGE_ELUPTION);
            if (auto trillax = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATAGUID_TRILLAX)))
            {
                trillax->AI()->DoAction(1);
            }

        }
    private:
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_sludgeraxAI>(creature);
    }
};

//206482
class spell_gen_arcane_seepage : public SpellScriptLoader
{
public:
    spell_gen_arcane_seepage() : SpellScriptLoader("spell_gen_arcane_seepage") {}

    class spell_gen_arcane_seepage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_arcane_seepage_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_ARCANE_SEEPAGE))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_ARCANE_SEEPAGE, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_gen_arcane_seepage_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gen_arcane_seepage_AuraScript();
    }
};

class areatrigger_gen_arcane_seepage : public AreaTriggerEntityScript
{
public:
    areatrigger_gen_arcane_seepage() : AreaTriggerEntityScript("areatrigger_gen_arcane_seepage") { }

    struct areatrigger_gen_arcane_seepageAI : AreaTriggerAI
    {
        areatrigger_gen_arcane_seepageAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_ARCANE_SEEPAGE_DMG);
            Unit* caster = at->GetCaster();
            if (!caster || !unit || !spellInfo)
                return;

            if (!caster->IsValidAttackTarget(unit) || unit->IsImmunedToSpell(spellInfo, caster))
                return;

            if (!unit->HasAura(spellInfo->Id, caster->GetGUID()))
                caster->AddAura(spellInfo->Id, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (!caster || !unit)
                return;

            if (!caster->IsValidAttackTarget(unit))
                return;

            if (unit->HasAura(SPELL_ARCANE_SEEPAGE_DMG, caster->GetGUID()))
                unit->RemoveAura(SPELL_ARCANE_SEEPAGE_DMG, caster->GetGUID());
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_gen_arcane_seepageAI(areatrigger);
    }
};

void AddSC_boss_trilliax()
{
    new boss_trilliax();
    new npc_putrid_sludge();
    new npc_tr_slime_pool();
    new npc_sludgerax();
    new spell_gen_arcane_seepage();
    new areatrigger_gen_arcane_seepage();
}
