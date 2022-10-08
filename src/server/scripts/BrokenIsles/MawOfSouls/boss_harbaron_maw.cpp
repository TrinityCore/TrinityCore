/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "SpellAuras.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellHistory.h"
#include "AreaTrigger.h"
#include "SpellMgr.h"
#include "maw_of_souls.h"

enum Spells
{
    // Harbaron
    SPELL_FRAGMENT                      = 194325,
    SPELL_FRAGMENT_CHANNELED_TRIGGER    = 194327,
    SPELL_FRAGMENT_STUN                 = 198551,
    SPELL_SUMMON_SHACKLED_SERVITOR      = 194231,
    SPELL_NETHER_RIP                    = 194668,
    SPELL_NETHER_RIP_MISSILE            = 199457,
    SPELL_NETHER_RIP_AREA_DMG           = 194235,
    SPELL_COSMIC_SCYTHE                 = 194216,
    SPELL_COSMIC_SCYTHE_DMG             = 194218,
    SPELL_COSMIC_SCYTHE_VISUAL          = 198580,

    // Shackled Servitor
    SPELL_GHOST_VISUAL                  = 188272,
    SPELL_VOID_SNAP                     = 194266,

    // Soul Fragment
    SPELL_FRAGMENT_AURA_SOUL            = 194344,
    SPELL_FRAGMENT_DMG                  = 194375,
    SPELL_FRAGMENT_CLONE_IMAGE          = 194345,
    SPELL_FRAGMENT_MOD_SIZE             = 194381,

};

enum Events
{
    EVENT_FRAGMENT          = 1,
    EVENT_COSMIC_SCYHTE     = 2,
    EVENT_NETHER_RIP        = 3,
    EVENT_SHACKLED_SERVITOR = 4,

    EVENT_VOID_SNAP         = 5,
    EVENT_CONTINUE_MOVE     = 6,
    EVENT_BORN              = 7,

};

enum Says
{
    SAY_INTRO   = 0,
    SAY_AGGRO   = 1,
    SAY_SPIRIT  = 2,
    SAY_SOUL    = 3,
    SAY_KILL    = 4,
    SAY_DEATH   = 5,
};

enum Adds
{
    NPC_SHACKLED_SERVITOR   = 98693,
    NPC_SOUL_FRAGMENT       = 98761,
    NPC_COSMIC_SCYTHE       = 98989,
};

enum DataTypes
{
    DATA_FRAGMENT_SOUL = 1,
};

struct NonMeleeTargetSelector : public std::unary_function<Unit*, bool>
{
    public:
        NonMeleeTargetSelector(Unit* source, bool playerOnly = true) : _source(source), _playerOnly(playerOnly) { }
        bool operator()(Unit const* target) const
        {
             if (!target)
                return false;

            if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
                return false;

            return !_source->IsWithinMeleeRange(target);
        }

    private:
        Unit* _source;
        bool _playerOnly;
};

class boss_harbaron : public CreatureScript
{
    public:
        boss_harbaron() : CreatureScript("boss_harbaron")
        {}

        struct boss_harbaron_AI : public BossAI
        {
            boss_harbaron_AI(Creature* creature) : BossAI(creature, DATA_HARBARON)
            {}

            void Reset()
            {
                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_FRAGMENT, Seconds(19));
                events.ScheduleEvent(EVENT_COSMIC_SCYHTE, Seconds(3));
                events.ScheduleEvent(EVENT_SHACKLED_SERVITOR, Seconds(7));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_NETHER_RIP, Seconds(12));
            }

            ObjectGuid GetGUID(int32 id) const override
            {
                if (id == DATA_FRAGMENT_SOUL)
                    return _targetSoulGuid;

                return ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_FRAGMENT_SOUL)
                    _targetSoulGuid = guid;
            }

            void SetData(uint32 id, uint32 value) override
            {
                if (id == DATA_FRAGMENT_SOUL)
                    _fragmentsDead = value;
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FRAGMENT_CHANNELED_TRIGGER);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(reason);
            }

            void JustReachedHome() override
            {
                _JustReachedHome();
            }

            void SummonedCreatureDies(Creature* summon, Unit* /**/) override
            {
                if (!summon)
                    return;

                if (summon->GetEntry() == NPC_SOUL_FRAGMENT)
                {
                    _fragmentsDead--;

                    if (_fragmentsDead == 0)
                    {
                        if (Unit* target = ObjectAccessor::GetPlayer(*me, _targetSoulGuid))
                            target->RemoveAurasDueToSpell(SPELL_FRAGMENT_CHANNELED_TRIGGER);
                    }
                }
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                me->GetSpellHistory()->ResetAllCooldowns();
                switch (eventId)
                {
                    case EVENT_FRAGMENT:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true));

                        if (!target)
                            DoCastVictim(SPELL_FRAGMENT);
                        else
                            DoCast(target, SPELL_FRAGMENT);

                        Talk(SAY_SOUL);
                        events.ScheduleEvent(EVENT_FRAGMENT, Seconds(30));
                        break;
                    }

                    case EVENT_COSMIC_SCYHTE:
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        {
                            me->SetFacingToObject(target);
                            DoCast(target, SPELL_COSMIC_SCYTHE);
                        }

                        events.ScheduleEvent(EVENT_COSMIC_SCYHTE, Seconds(10));
                        break;
                    }

                    case EVENT_SHACKLED_SERVITOR:
                    {
                        Talk(SAY_SPIRIT);
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonMeleeTargetSelector(me, true));

                        if (target)
                            DoCast(target, SPELL_SUMMON_SHACKLED_SERVITOR);
                        else
                            DoCastVictim(SPELL_SUMMON_SHACKLED_SERVITOR);

                        events.ScheduleEvent(EVENT_SHACKLED_SERVITOR, Seconds(23));
                        break;
                    }

                    case EVENT_NETHER_RIP:
                    {
                        DoCast(me, SPELL_NETHER_RIP);
                        events.ScheduleEvent(EVENT_NETHER_RIP, Seconds(14));
                        break;
                    }

                    default : break;
                }
            }

            private:
                int8 _fragmentsDead;
                ObjectGuid _targetSoulGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_harbaron_AI(creature);
        }
};

class npc_mos_shackled_servitor : public CreatureScript
{
    public:
        npc_mos_shackled_servitor() : CreatureScript("npc_mos_shackled_servitor")
        {}

        struct npc_mos_shackled_servitor_AI : public ScriptedAI
        {
            npc_mos_shackled_servitor_AI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset()
            {
                DoCast(me, SPELL_GHOST_VISUAL, true);
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void EnterCombat(Unit* /**/) override
            {
                DoCast(me, SPELL_VOID_SNAP);
                _events.ScheduleEvent(EVENT_VOID_SNAP, Seconds(6));
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_VOID_SNAP)
                    {
                        DoCast(me, SPELL_VOID_SNAP);
                        _events.ScheduleEvent(EVENT_VOID_SNAP, Seconds(6));
                    }
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_mos_shackled_servitor_AI(creature);
        };
};

class npc_mos_soul_fragment : public CreatureScript
{
    public:
        npc_mos_soul_fragment() : CreatureScript("npc_mos_soul_fragment")
        {}

        struct npc_mos_soul_fragment_AI : public ScriptedAI
        {
            npc_mos_soul_fragment_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetWalk(true);
                _pos = me->GetNearPosition(25.0f, 0);
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetWalk(true);
                DoCast(me, SPELL_FRAGMENT_AURA_SOUL, true);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                _events.ScheduleEvent(EVENT_BORN, Seconds(5));
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == 0 && type == POINT_MOTION_TYPE)
                    me->GetMotionMaster()->MoveRandom(25.0f);
            }

            void SpellHit(Unit*, SpellInfo const* spell) override
            {
                if (!spell)
                    return;

                uint32 mechanic = spell->Mechanic;

                if (mechanic == MECHANIC_STUN || mechanic == MECHANIC_FEAR || mechanic == MECHANIC_ROOT || mechanic == MECHANIC_DISORIENTED)
                {
                    me->GetMotionMaster()->Clear();
                    me->StopMoving();
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                    _events.ScheduleEvent(EVENT_CONTINUE_MOVE, spell->GetMaxDuration() + 200);
                }
            }

            ObjectGuid GetGUID(int32 id) const override
            {
                if (id == DATA_FRAGMENT_SOUL)
                    return _targetGuid;

                return ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_FRAGMENT_SOUL)
                    _targetGuid = guid;
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_BORN)
                        me->GetMotionMaster()->MovePoint(0, _pos);
                    else if (eventId == EVENT_CONTINUE_MOVE)
                    {
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                        me->GetMotionMaster()->MoveRandom(25.0f);
                    }
                }
            }

            private:
                EventMap _events;
                Position _pos;
                ObjectGuid _targetGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_mos_soul_fragment_AI(creature);
        }
};

class npc_mos_cosmic_scythe : public CreatureScript
{
    public:
        npc_mos_cosmic_scythe() : CreatureScript("npc_mos_cosmic_scythe")
        {}

        struct npc_mos_cosmic_scythe_AI : public ScriptedAI
        {
            npc_mos_cosmic_scythe_AI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _timerCast = 0;
            }

            void UpdateAI(uint32 diff) override
            {
                _timerCast += diff;

                if (_timerCast >= 1000)
                {
                    _timerCast = 0;
                    DoCast(me, SPELL_COSMIC_SCYTHE_DMG, true);
                }
            }

            private:
                uint32 _timerCast;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_mos_cosmic_scythe_AI(creature);
        }
};

class at_mos_nether_rip : public AreaTriggerEntityScript
{
    public:
        at_mos_nether_rip() : AreaTriggerEntityScript("at_mos_nether_rip")
        {}

        struct at_mos_nether_rip_AI : public AreaTriggerAI
        {
            at_mos_nether_rip_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;

                if (target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_NETHER_RIP_AREA_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (!target)
                    return;

                if (target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_NETHER_RIP_AREA_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_mos_nether_rip_AI(at);
        }
};

class spell_harbaron_nether_rip : public SpellScriptLoader
{
    public:
        spell_harbaron_nether_rip() : SpellScriptLoader("spell_harbaron_nether_rip")
        {}

        class spell_harbaron_nether_rip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_harbaron_nether_rip_AuraScript);

            bool Load() override
            {
                _target = nullptr;
                _targetTwo = nullptr;
                return true;
            }

            void HandlePeriodic(AuraEffect const* /**/)
            {
                if (!GetUnitOwner())
                    return;

                Unit* owner = GetUnitOwner();

                if (!_target)
                {
                    _target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true);

                    if (_target)
                        owner->CastSpell(_target, SPELL_NETHER_RIP_MISSILE, true);
                }
                else
                {
                    _targetTwo = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, ([&] (Unit* player)
                    {
                        return player->GetEntry() != _target->GetEntry();
                    }));

                    if (_targetTwo)
                        owner->CastSpell(_targetTwo, SPELL_NETHER_RIP_MISSILE, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_harbaron_nether_rip_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

            private:
                Unit* _target;
                Unit* _targetTwo;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_harbaron_nether_rip_AuraScript();
        }
};

class spell_harbaron_cosmic_scythe : public SpellScriptLoader
{
    public:
        spell_harbaron_cosmic_scythe() : SpellScriptLoader("spell_harbaron_cosmic_scythe")
        {}

        class spell_harbaron_cosmic_scythe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_harbaron_cosmic_scythe_SpellScript);

            void HandleSummon()
            {
                if (!GetCaster())
                    return;

                Unit* caster = GetCaster();

                Creature* scythe = caster->SummonCreature(NPC_COSMIC_SCYTHE, caster->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 3 * IN_MILLISECONDS);

                if (scythe)
                {
                    scythe->CastSpell(scythe, SPELL_COSMIC_SCYTHE_VISUAL, true);

                    Position pos = scythe->GetNearPosition(100.f, 0);

                    scythe->GetMotionMaster()->MovePoint(0, pos);
                }
            }

            void HandleAfterCast()
            {
                if (GetCaster() && GetCaster()->ToCreature())
                    GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_harbaron_cosmic_scythe_SpellScript::HandleSummon);
                AfterCast += SpellCastFn(spell_harbaron_cosmic_scythe_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_harbaron_cosmic_scythe_SpellScript();
        }
};

class spell_harbaron_fragment : public SpellScriptLoader
{
    public:
        spell_harbaron_fragment() : SpellScriptLoader("spell_harbaron_fragment")
        {}

        class spell_harbaron_fragment_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_harbaron_fragment_SpellScript);

                void HandleSummons(SpellEffIndex /**/)
                {
                    if (!GetHitUnit() || !GetCaster())
                        return;

                    Unit* caster = GetCaster();
                    Unit* target = GetHitUnit();

                    Position pos = target->GetPosition();

                    uint8 souls = urand(2,3);

                    caster->GetAI()->SetGUID(target->GetGUID(), DATA_FRAGMENT_SOUL);
                    caster->GetAI()->SetData(DATA_FRAGMENT_SOUL, souls);

                    for (uint8 i = 0; i < souls; ++i)
                    {
                        pos.SetOrientation(pos.GetOrientation() + float(M_PI)/4.0f);
                        Creature* soul = caster->SummonCreature(NPC_SOUL_FRAGMENT, pos, TEMPSUMMON_TIMED_DESPAWN, 120 * IN_MILLISECONDS);

                        if (soul)
                        {
                            target->CastSpell(soul, SPELL_FRAGMENT_CLONE_IMAGE, true);
                            soul->CastSpell(soul, SPELL_FRAGMENT_MOD_SIZE, true);
                            soul->GetAI()->SetGUID(target->GetGUID(), DATA_FRAGMENT_SOUL);
                        }
                    }
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_harbaron_fragment_SpellScript::HandleSummons, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_harbaron_fragment_SpellScript();
        }
};

class spell_harbaron_fragment_dmg : public SpellScriptLoader
{
    public:
        spell_harbaron_fragment_dmg() : SpellScriptLoader("spell_harbaron_fragment_dmg")
        {}

        class spell_harbaron_fragment_dmg_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_harbaron_fragment_dmg_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetCaster())
                        return;

                    Unit* caster = GetCaster();
                    Unit* target = ObjectAccessor::GetPlayer(*caster, caster->GetAI()->GetGUID(DATA_FRAGMENT_SOUL));

                    if (target)
                        caster->CastSpell(target, SPELL_FRAGMENT_DMG, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_harbaron_fragment_dmg_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_harbaron_fragment_dmg_AuraScript();
        }
};

class spell_mos_void_snap : public SpellScript
{
public:
    PrepareSpellScript(spell_mos_void_snap);

    void CalculateDamage(SpellEffIndex)
    {
        if (!GetCaster())
            return;

        Aura* snap = GetCaster()->GetAura(SPELL_VOID_SNAP);

        if (snap)
            SetHitDamage(GetEffectInfo(EFFECT_0)->BasePoints * (1.0f + (snap->GetStackAmount() * 0.15f)));
    }

    void Register()
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_mos_void_snap::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_boss_harbaron_maw()
{
    new boss_harbaron();
    new npc_mos_shackled_servitor();
    new npc_mos_cosmic_scythe();
    new npc_mos_soul_fragment();
    new at_mos_nether_rip();
    new spell_harbaron_nether_rip();
    new spell_harbaron_cosmic_scythe();
    new spell_harbaron_fragment();
    new spell_harbaron_fragment_dmg();
    RegisterSpellScript(spell_mos_void_snap);
}
