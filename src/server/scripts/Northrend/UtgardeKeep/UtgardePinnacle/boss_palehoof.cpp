/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "utgarde_pinnacle.h"

enum Spells
{
    // Palehoof
    SPELL_ARCING_SMASH          = 48260,
    SPELL_IMPALE                = 48261,
    SPELL_IMPALE_H              = 59268,
    SPELL_WITHERING_ROAR        = 48256,
    SPELL_WITHERING_ROAR_H      = 59267,
    SPELL_FREEZE                = 16245,
    // Orb - World Trigger
    SPELL_ORB_VISUAL            = 48044,
    SPELL_ORB_CHANNEL           = 48048,
    SPELL_AWAKEN_SUBBOSS        = 47669,
    SPELL_AWAKEN_GORTOK         = 47670,
    // Ravenous Furbolg
    SPELL_CHAIN_LIGHTNING       = 48140,
    SPELL_CHAIN_LIGHTNING_H     = 59273,
    SPELL_CRAZED                = 48139,
    SPELL_CRAZED_TAUNT          = 48147,
    SPELL_TERRIFYING_ROAR       = 48144,
    // Frenzied Worgen
    SPELL_MORTAL_WOUND          = 48137,
    SPELL_MORTAL_WOUND_H        = 59265,
    SPELL_ENRAGE_1              = 48138,
    SPELL_ENRAGE_2              = 48142,
    // Ferocious Rhino
    SPELL_GORE                  = 48130,
    SPELL_GORE_2                = 59264,
    SPELL_GRIEVOUS_WOUND        = 48105,
    SPELL_GRIEVOUS_WOUND_H      = 59263,
    SPELL_STOMP                 = 48131,
    // Massive Jormungar
    SPELL_ACID_SPIT             = 48132,
    SPELL_ACID_SPLATTER         = 48136,
    SPELL_ACID_SPLATTER_H       = 59272,
    SPELL_POISON_BREATH         = 48133,
    SPELL_POISON_BREATH_H       = 59271
};

enum Events
{
    EVENT_ARCING_SMASH = 1,
    EVENT_IMPALE,
    EVENT_WITHERING_ROAR,
    EVENT_CRAZED,
    EVENT_CHAIN_LIGHTNING,
    EVENT_TERRIFYING_ROAR,
    EVENT_MORTAL_WOUND,
    EVENT_MORTAL_WOUND_2,
    EVENT_ENRAGE,
    EVENT_ENRAGE_2,
    EVENT_GORE,
    EVENT_GRIEVOUS_WOUND,
    EVENT_STOMP,
    EVENT_ACID_SPIT,
    EVENT_ACID_SPLATTER,
    EVENT_POISON_BREATH
};

enum Says
{
    SAY_AGGRO            = 0,
    SAY_SLAY             = 1,
    PALEHOOF_SOUND_DEATH = 13467
};

Position const OrbPositions[2] =
{
    { 238.6077f, -460.7103f, 112.5671f },
    { 279.26f,   -452.1f,    110.0f    }
};

enum Misc
{
    ACTION_NEXT_PHASE       = 1,
    ACTION_START_FIGHT      = 2,
    ACTION_START_ENCOUNTER  = 3,
    POSITION_FLY            = 0,
    POSITION_FINAL          = 1,
    SUMMON_MINIBOSSES_GROUP = 1
};

class WormAttackEvent : public BasicEvent
{
public:
    WormAttackEvent(TempSummon* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->SetReactState(REACT_AGGRESSIVE);
        _owner->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
        _owner->AI()->DoZoneInCombat();
        return true;
    }

private:
    TempSummon* _owner;
};

class OrbFinalPositionEvent : public BasicEvent
{
public:
    OrbFinalPositionEvent(Creature* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->CastSpell(_owner, SPELL_AWAKEN_SUBBOSS, { SPELLVALUE_MAX_TARGETS, 1 });
        return true;
    }

private:
    Creature* _owner;
};

class OrbAirPositionEvent : public BasicEvent
{
public:
    OrbAirPositionEvent(Creature* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->SetWalk(true);
        _owner->GetMotionMaster()->MovePoint(0, OrbPositions[POSITION_FLY]);
        return true;
    }

private:
    Creature* _owner;
};

class OrbFlyEvent : public BasicEvent
{
public:
    OrbFlyEvent(Creature* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->SetWalk(false);
        _owner->GetMotionMaster()->MovePoint(0, OrbPositions[POSITION_FINAL]);
        _owner->m_Events.AddEvent(new OrbFinalPositionEvent(_owner), _owner->m_Events.CalculateTime(10000));
        return true;
    }

private:
    Creature* _owner;
};

class CombatStartEvent : public BasicEvent
{
public:
    CombatStartEvent(Unit* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->GetAI()->DoAction(ACTION_START_FIGHT);
        return true;
    }

private:
    Unit* _owner;
};

class boss_palehoof : public CreatureScript
{
public:
    boss_palehoof() : CreatureScript("boss_palehoof") { }

    struct boss_palehoofAI : public BossAI
    {
        boss_palehoofAI(Creature* creature) : BossAI(creature, DATA_GORTOK_PALEHOOF), _dungeonMode(DUNGEON_MODE(2, 4)), _encountersCount(0) { }

        void Reset() override
        {
            _Reset();
            _orb.Clear();
            me->SummonCreatureGroup(SUMMON_MINIBOSSES_GROUP);
            _encountersCount = 0;

            if (GameObject* go = instance->GetGameObject(DATA_GORTOK_PALEHOOF_SPHERE))
            {
                go->SetGoState(GO_STATE_READY);
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            BossAI::JustSummoned(summon);

            if (summon->GetEntry() == NPC_PALEHOOF_ORB)
                _orb = summon->GetGUID();
        }

        void JustEngagedWith (Unit* /*who*/) override
        {
            _JustEngagedWith();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_ARCING_SMASH, 7s);
            events.ScheduleEvent(EVENT_IMPALE, 11s);
            events.ScheduleEvent(EVENT_WITHERING_ROAR, 12s);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_ARCING_SMASH:
                    DoCastVictim(SPELL_ARCING_SMASH);
                    events.Repeat(Seconds(7));
                    break;
                case EVENT_IMPALE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_IMPALE);
                    events.Repeat(Seconds(10), Seconds(15));
                    break;
                case EVENT_WITHERING_ROAR:
                    DoCastSelf(SPELL_WITHERING_ROAR);
                    events.Repeat(Seconds(11));
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            instance->SetBossState(DATA_GORTOK_PALEHOOF, DONE);
            DoPlaySoundToSet(me, PALEHOOF_SOUND_DEATH);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            summons.DespawnAll();
            _DespawnAtEvade();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_NEXT_PHASE:
                {
                    Creature* orb = ObjectAccessor::GetCreature(*me, _orb);
                    if (!orb)
                        return;

                    _encountersCount++;
                    if (_encountersCount == _dungeonMode)
                        orb->CastSpell(orb, SPELL_AWAKEN_GORTOK, true);
                    else
                        orb->CastSpell(orb, SPELL_AWAKEN_SUBBOSS, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    break;
                }
                case ACTION_START_FIGHT:
                    me->RemoveAurasDueToSpell(SPELL_FREEZE);
                    me->SetImmuneToPC(false);
                    DoZoneInCombat();
                    if (Creature* orb = ObjectAccessor::GetCreature(*me, _orb))
                        orb->DespawnOrUnsummon(1000);
                    break;
                case ACTION_START_ENCOUNTER:
                    if (Creature* orb = ObjectAccessor::GetCreature(*me, _orb))
                    {
                        orb->CastSpell(orb, SPELL_ORB_VISUAL, true);
                        orb->m_Events.AddEvent(new OrbAirPositionEvent(orb), orb->m_Events.CalculateTime(3000));
                        orb->m_Events.AddEvent(new OrbFlyEvent(orb), orb->m_Events.CalculateTime(6000));
                    }
                    break;
                default:
                    break;
            }
        }

        private:
            uint8 _dungeonMode;
            uint8 _encountersCount;
            ObjectGuid _orb;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_palehoofAI>(creature);
    }
};

struct PalehoofMinionsBossAI : public BossAI
{
    PalehoofMinionsBossAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId) { }

    void Reset() override
    {
        me->SetCombatPulseDelay(0);
        events.Reset();
        DoCastSelf(SPELL_FREEZE, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        ScheduleTasks();
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_START_FIGHT)
        {
            me->RemoveAurasDueToSpell(SPELL_FREEZE);
            me->SetImmuneToPC(false);
            DoZoneInCombat();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* palehoof = instance->GetCreature(DATA_GORTOK_PALEHOOF))
            palehoof->AI()->DoAction(ACTION_NEXT_PHASE);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* palehoof = instance->GetCreature(DATA_GORTOK_PALEHOOF))
            palehoof->AI()->EnterEvadeMode(why);
    }
};

class boss_ravenous_furbolg : public CreatureScript
{
public:
    boss_ravenous_furbolg() : CreatureScript("boss_ravenous_furbolg") { }

    struct boss_ravenous_furbolgAI : public PalehoofMinionsBossAI
    {
        boss_ravenous_furbolgAI(Creature* creature) : PalehoofMinionsBossAI(creature, DATA_RAVENOUS_FURBOLG) { }

        void ScheduleTasks() override
        {
            events.ScheduleEvent(EVENT_CRAZED, 10s);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 12s);
            events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 22s);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_CRAZED:
                    DoCastSelf(SPELL_CRAZED);
                    events.Repeat(Seconds(20), Seconds(25));
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    DoCastVictim(SPELL_CHAIN_LIGHTNING);
                    events.Repeat(Seconds(11));
                    break;
                case EVENT_TERRIFYING_ROAR:
                    DoCastSelf(SPELL_TERRIFYING_ROAR);
                    events.Repeat(Seconds(18));
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_ravenous_furbolgAI>(creature);
    }
};

class boss_frenzied_worgen : public CreatureScript
{
public:
    boss_frenzied_worgen() : CreatureScript("boss_frenzied_worgen") { }

    struct boss_frenzied_worgenAI : public PalehoofMinionsBossAI
    {
        boss_frenzied_worgenAI(Creature* creature) : PalehoofMinionsBossAI(creature, DATA_FRENZIED_WORGEN) { }

        void ScheduleTasks() override
        {
            events.ScheduleEvent(EVENT_MORTAL_WOUND, 6s);
            events.ScheduleEvent(EVENT_ENRAGE, 16s);
            events.ScheduleEvent(EVENT_ENRAGE_2, Minutes(1) + Seconds(30));
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(Seconds(6));
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE_1);
                    events.Repeat(Seconds(25));
                    break;
                case EVENT_ENRAGE_2:
                    DoCastSelf(SPELL_ENRAGE_2);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_frenzied_worgenAI>(creature);
    }
};

class boss_ferocious_rhino : public CreatureScript
{
public:
    boss_ferocious_rhino() : CreatureScript("boss_ferocious_rhino") { }

    struct boss_ferocious_rhinoAI : public PalehoofMinionsBossAI
    {
        boss_ferocious_rhinoAI(Creature* creature) : PalehoofMinionsBossAI(creature, DATA_FEROCIOUS_RHINO) { }

        void ScheduleTasks() override
        {
            events.ScheduleEvent(EVENT_GORE, 10s);
            events.ScheduleEvent(EVENT_GRIEVOUS_WOUND, 12s);
            events.ScheduleEvent(EVENT_STOMP, 5s);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_GORE:
                    DoCastVictim(SPELL_GORE);
                    events.Repeat(Seconds(19));
                    break;
                case EVENT_GRIEVOUS_WOUND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_GRIEVOUS_WOUND);
                    events.Repeat(Seconds(18));
                    break;
                case EVENT_STOMP:
                    DoCastSelf(SPELL_STOMP);
                    events.Repeat(Seconds(10), Seconds(15));
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_ferocious_rhinoAI>(creature);
    }
};

class boss_massive_jormungar : public CreatureScript
{
public:
    boss_massive_jormungar() : CreatureScript("boss_massive_jormungar") { }

    struct boss_massive_jormungarAI : public PalehoofMinionsBossAI
    {
        boss_massive_jormungarAI(Creature* creature) : PalehoofMinionsBossAI(creature, DATA_MASSIVE_JORMUNGAR) { }

        void ScheduleTasks() override
        {
            events.ScheduleEvent(EVENT_ACID_SPIT, 6s);
            events.ScheduleEvent(EVENT_ACID_SPLATTER, 16s);
            events.ScheduleEvent(EVENT_POISON_BREATH, 13s);
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_JORMUNGAR_WORM)
            {
                summon->m_Events.AddEvent(new WormAttackEvent(summon->ToTempSummon()), summon->m_Events.CalculateTime(2000));
                summon->GetMotionMaster()->MoveRandom(5.0f);
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_ACID_SPIT:
                    DoCastVictim(SPELL_ACID_SPIT);
                    events.Repeat(Seconds(7));
                    break;
                case EVENT_ACID_SPLATTER:
                    DoCastSelf(SPELL_ACID_SPLATTER);
                    events.Repeat(Seconds(16));
                    break;
                case EVENT_POISON_BREATH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_POISON_BREATH);
                    events.Repeat(Seconds(14));
                    break;
                default:
                    break;
            }
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            summons.DespawnAll();
            PalehoofMinionsBossAI::EnterEvadeMode(why);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUtgardePinnacleAI<boss_massive_jormungarAI>(creature);
    }
};

class go_palehoof_sphere : public GameObjectScript
{
public:
    go_palehoof_sphere() : GameObjectScript("go_palehoof_sphere") { }

    struct go_palehoof_sphereAI : public GameObjectAI
    {
        go_palehoof_sphereAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool GossipHello(Player* /*player*/) override
        {
            if (Creature* palehoof = instance->GetCreature(DATA_GORTOK_PALEHOOF))
            {
                if (palehoof->IsAlive() && instance->GetBossState(DATA_GORTOK_PALEHOOF) != DONE)
                {
                    me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    me->SetGoState(GO_STATE_ACTIVE);
                    palehoof->AI()->DoAction(ACTION_START_ENCOUNTER);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetUtgardePinnacleAI<go_palehoof_sphereAI>(go);
    }
};

//  48139 - Crazed
class spell_palehoof_crazed : public SpellScriptLoader
{
    public:
        spell_palehoof_crazed() : SpellScriptLoader("spell_palehoof_crazed") { }

        class spell_palehoof_crazed_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_palehoof_crazed_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_CRAZED_TAUNT);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_palehoof_crazed_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_palehoof_crazed_AuraScript();
        }
};

class spell_palehoof_crazed_effect : public SpellScriptLoader
{
    public: spell_palehoof_crazed_effect() : SpellScriptLoader("spell_palehoof_crazed_effect") { }

        class spell_palehoof_crazed_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_palehoof_crazed_effect_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_CRAZED_TAUNT });
            }

            void HandleScriptEffect(SpellEffIndex /* effIndex */)
            {
                GetHitUnit()->CastSpell(GetCaster(), SPELL_CRAZED_TAUNT, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_palehoof_crazed_effect_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_palehoof_crazed_effect_SpellScript();
        }
};

// 47669 - Awaken Subbos
class spell_palehoof_awaken_subboss : public SpellScriptLoader
{
    public:
        spell_palehoof_awaken_subboss() : SpellScriptLoader("spell_palehoof_awaken_subboss") { }

        class spell_palehoof_awaken_subboss_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_palehoof_awaken_subboss_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ORB_CHANNEL });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                GetCaster()->CastSpell(target, SPELL_ORB_CHANNEL);
                target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                target->m_Events.AddEvent(new CombatStartEvent(target), target->m_Events.CalculateTime(8500));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_palehoof_awaken_subboss_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_palehoof_awaken_subboss_SpellScript();
        }
};

// 47670 - Awaken Gortok
class spell_palehoof_awaken_gortok : public SpellScriptLoader
{
    public:
        spell_palehoof_awaken_gortok() : SpellScriptLoader("spell_palehoof_awaken_gortok") { }

        class spell_palehoof_awaken_gortok_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_palehoof_awaken_gortok_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                target->m_Events.AddEvent(new CombatStartEvent(target), target->m_Events.CalculateTime(8000));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_palehoof_awaken_gortok_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_palehoof_awaken_gortok_SpellScript();
        }
};

void AddSC_boss_palehoof()
{
    new boss_palehoof();
    new boss_ravenous_furbolg();
    new boss_frenzied_worgen();
    new boss_ferocious_rhino();
    new boss_massive_jormungar();
    new go_palehoof_sphere();
    new spell_palehoof_crazed();
    new spell_palehoof_crazed_effect();
    new spell_palehoof_awaken_subboss();
    new spell_palehoof_awaken_gortok();
}
