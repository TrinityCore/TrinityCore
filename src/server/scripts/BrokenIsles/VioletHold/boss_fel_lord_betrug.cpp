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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"
#include "SpellHistory.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "violet_hold_assault.h"
#include <G3D/Vector3.h>
#include <G3D/Triangle.h>
#include <G3D/Plane.h>
#include <G3D/CollisionDetection.h>

enum Spells
{
    SPELL_FEL_SLASH                 = 203641,
    SPELL_EXECUTION                 = 202361,
    SPELL_EXECUTION_ROOTED          = 205265,
    SPELL_EXECUTION_AURA            = 205233,
    SPELL_CHAOTIC_ENERGY            = 203622,
    SPELL_CHAOTIC_ENERGY_MISSILE    = 203618,
    SPELL_CHAOTIC_ENERGY_DMG        = 203619,
    SPELL_MIGHTY_SLASH              = 202328,
    SPELL_MIGHTY_SLASH_JUMP_EXEC    = 202339,
    SPELL_MIGHTY_SLASH_JUMP_INITIAL = 202340,
    SPELL_MIGHTY_SLASH_JUMP_BELTRUG = 202343,
    SPELL_SEED_OF_DESTRUCTION       = 210879,
    SPELL_WAKE_OF_DESTRUCTION       = 210913,
    SPELL_WAKE_OF_DESTRUCTION_DMG   = 210916,
    SPELL_STASIS_CRYSTAL_SUMMON     = 205230,
    SPELL_STASIS_CRYSTAL_VISUAL     = 205225,
    SPELL_STASIS_CRYSTAL_VEC_RIGHT  = 205226,
    SPELL_STASIS_CRYSTAL_VEC_LEFT   = 205346,
};

enum Events
{
    EVENT_FEL_SLASH             = 1,
    EVENT_SEED_OF_DESTRUCTION   = 2,
    EVENT_MIGHTY_SLASH          = 3,
    EVENT_CHAOTIC_ENERGY        = 4,
    EVENT_EXECUTION             = 5,

    EVENT_RESTORE_STATE         = 6,
    EVENT_BORN                  = 7,
};

enum Adds
{
    NPC_STASIS_CRYSTAL  = 103672,
};

enum Says
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_EXECUTION   = 2,
    SAY_KILL        = 3,
    SAY_EXEC_WARN   = 4,
    SAY_WIPE        = 5,
    SAY_DEAD        = 6,
};

enum Actions
{
    ACTION_EXECUTE          = 1,
    ACTION_EXECUTED_FINISHED = 2,
};

const Position BeltrugExecutionPos  = { 4682.18f, 4014.705f, 91.88149f, 3.086201f };
const Position ExecutionPlayerPos   = { 4673.836f, 4015.167f, 91.80103f, 6.213372f};
const Position RoomInitialPos       = { 4588.694f, 4017.831f, 83.48485f, 3.240514f};

const Position CrystalStasisPos[2] =
{
    { 4673.836f, 4011.167f, 91.78947f, 4.712389f },
    { 4673.836f, 4019.167f, 91.93404f, 1.570796f },
};

class boss_fel_lord_betrug : public CreatureScript
{
    public:
        boss_fel_lord_betrug() : CreatureScript("boss_fel_lord_betrug")
        {}

        struct boss_fel_lord_betrug_AI : public BossAI
        {
            boss_fel_lord_betrug_AI(Creature* creature) : BossAI(creature, DATA_BELTRUG)
            {}

            void Reset() override
            {
                _Reset();
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(reason);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_EXECUTE)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    DoCast(me, SPELL_MIGHTY_SLASH_JUMP_BELTRUG, true);
                    events.ScheduleEvent(EVENT_EXECUTION, 1500);
                }
                else if (action == ACTION_EXECUTED_FINISHED)
                {
                    events.ScheduleEvent(EVENT_RESTORE_STATE, IN_MILLISECONDS);
                }
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEAD);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_FEL_SLASH, Seconds(10));
                events.ScheduleEvent(EVENT_MIGHTY_SLASH, Seconds(30));
                events.ScheduleEvent(EVENT_CHAOTIC_ENERGY, Seconds(15));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SEED_OF_DESTRUCTION, Seconds(15));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                me->GetSpellHistory()->ResetAllCooldowns();

                switch (eventId)
                {
                    case EVENT_RESTORE_STATE:
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    }

                    case EVENT_EXECUTION:
                    {
                        me->SetFacingTo(BeltrugExecutionPos.GetOrientation());
                        Talk(SAY_EXECUTION);
                        Talk(SAY_EXEC_WARN);
                        DoCast(me, SPELL_EXECUTION);
                        break;
                    }
                    case EVENT_FEL_SLASH:
                    {
                        DoCastVictim(SPELL_FEL_SLASH);
                        events.ScheduleEvent(EVENT_FEL_SLASH, Seconds(10));
                        break;
                    }

                    case EVENT_CHAOTIC_ENERGY:
                    {
                        DoCast(me, SPELL_CHAOTIC_ENERGY);
                        events.ScheduleEvent(EVENT_CHAOTIC_ENERGY, Seconds(16));
                        break;
                    }

                    case EVENT_MIGHTY_SLASH:
                    {
                        DoCast(me, SPELL_MIGHTY_SLASH);
                        events.DelayEvents(Seconds(20));
                        events.ScheduleEvent(EVENT_MIGHTY_SLASH, Seconds(60));
                        break;
                    }

                    case EVENT_SEED_OF_DESTRUCTION:
                    {
                        DoCast(me, SPELL_SEED_OF_DESTRUCTION);
                        events.ScheduleEvent(EVENT_SEED_OF_DESTRUCTION, Seconds(22));
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_fel_lord_betrug_AI(creature);
        }
};

class npc_vha_stasis_crystal : public CreatureScript
{
    public:
        npc_vha_stasis_crystal() : CreatureScript("npc_vha_stasis_crystal")
        {}

        struct npc_vha_stasis_crystal_AI : public ScriptedAI
        {
            npc_vha_stasis_crystal_AI(Creature* creature) : ScriptedAI(creature)
            {
                _summoner = nullptr;
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                _summoner = summoner;

                DoCast(me, SPELL_STASIS_CRYSTAL_VISUAL, true);
                _events.ScheduleEvent(EVENT_BORN, Seconds(1));
            }

            void DamageTaken(Unit* attacker, uint32 & damage) override
            {
                if (!attacker || !_summoner)
                    return;

                if (_summoner->GetGUID() == attacker->GetGUID())
                    damage = 0;
            }

            void JustDied(Unit* /**/) override
            {
                if (!_summoner)
                    return;

                if (!_summoner->HasAura(SPELL_STASIS_CRYSTAL_VEC_RIGHT))
                    _summoner->RemoveAurasDueToSpell(SPELL_EXECUTION_AURA);

                me->DespawnOrUnsummon(IN_MILLISECONDS);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_BORN)
                    DoCast(me, SPELL_STASIS_CRYSTAL_VEC_RIGHT);
            }

            private:
                EventMap _events;
                Unit* _summoner;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_stasis_crystal_AI(creature);
        }
};

class spell_betrug_chaotic_energy : public SpellScriptLoader
{
    public:
        spell_betrug_chaotic_energy() : SpellScriptLoader("spell_betrug_chaotic_energy")
        {}

        class spell_chaotic_energy_SpellScript : public SpellScript
        {
            public:

                PrepareSpellScript(spell_chaotic_energy_SpellScript);

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if(PlayerFilter());
                }

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_CHAOTIC_ENERGY_MISSILE, true);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_chaotic_energy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chaotic_energy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_chaotic_energy_SpellScript();
        }
};

class spell_betrug_mighty_slash : public SpellScriptLoader
{
    public:
        spell_betrug_mighty_slash() : SpellScriptLoader("spell_betrug_mighty_slash")
        {}

        class spell_mighty_slash_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_mighty_slash_SpellScript);

                bool Load() override
                {
                    _executeTarget = nullptr;
                    return true;
                }

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if(PlayerFilter());

                    if (targets.empty())
                        return;

                    _executeTarget = Trinity::Containers::SelectRandomContainerElement(targets)->ToUnit();
                }

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    if (_executeTarget && _executeTarget->GetGUID() == GetHitUnit()->GetGUID())
                    {
                        GetCaster()->GetAI()->DoAction(ACTION_EXECUTE);

                        _executeTarget->CastStop();
                        _executeTarget->CastSpell(_executeTarget, SPELL_MIGHTY_SLASH_JUMP_EXEC, true);

                        for (uint8 i = 0; i < 2; ++i)
                            _executeTarget->SummonCreature(NPC_STASIS_CRYSTAL, CrystalStasisPos[i], TEMPSUMMON_TIMED_DESPAWN, 40 * IN_MILLISECONDS);

                    }
                    else
                        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_MIGHTY_SLASH_JUMP_INITIAL, true);
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mighty_slash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                    OnEffectHitTarget += SpellEffectFn(spell_mighty_slash_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }

                private:
                    Unit* _executeTarget;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mighty_slash_SpellScript();
        }
};

class spell_betrug_mighty_slash_jump : public SpellScriptLoader
{
    public:
        spell_betrug_mighty_slash_jump() : SpellScriptLoader("spell_betrug_mighty_slash_jump")
        {}

        class spell_mighty_slash_jump_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_mighty_slash_jump_SpellScript);

                void HandleBeforeCast()
                {
                    if (!GetCaster())
                        return;

                    WorldLocation pos;

                    if (GetSpellInfo()->Id == SPELL_MIGHTY_SLASH_JUMP_EXEC)
                        pos.Relocate(ExecutionPlayerPos);
                    else if (GetSpellInfo()->Id == SPELL_MIGHTY_SLASH_JUMP_INITIAL)
                        pos.Relocate(RoomInitialPos);
                    else if (GetSpellInfo()->Id == SPELL_MIGHTY_SLASH_JUMP_BELTRUG)
                        pos.Relocate(BeltrugExecutionPos);

                    SetExplTargetDest(pos);
                }

                void Register() override
                {
                    BeforeCast += SpellCastFn(spell_mighty_slash_jump_SpellScript::HandleBeforeCast);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mighty_slash_jump_SpellScript();
        }
};

class spell_betrug_execution : public SpellScriptLoader
{
    public:
        spell_betrug_execution() : SpellScriptLoader("spell_betrug_execution")
        {}

        class spell_execution_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_execution_SpellScript);

                void HandleScript(SpellEffIndex /**/)
                {
                    if (!GetCaster())
                        return;

                    GetCaster()->GetAI()->DoAction(ACTION_EXECUTED_FINISHED);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_execution_SpellScript::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_execution_SpellScript();
        }
};

class spell_betrug_seed_of_destruction : public SpellScriptLoader
{
    public:
        spell_betrug_seed_of_destruction() : SpellScriptLoader("spell_betrug_seed_of_destruction")
        {}

        class spell_seed_of_destruction_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_seed_of_destruction_AuraScript);

                void HandleOnPeriodic(AuraEffect const*)
                {
                    if (!GetUnitOwner() || !GetCaster())
                        return;

                    Unit* caster = GetCaster();
                    Unit* owner = GetUnitOwner();
                    Position pos = owner->GetPosition();
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_WAKE_OF_DESTRUCTION);

                    for (uint8 i = 0; i < 4; ++i)
                    {
                        SpellCastTargets targets;
                        targets.SetDst(pos.m_positionX, pos.m_positionY, pos.m_positionZ, pos.GetOrientation());

                        if (spellInfo)
                            caster->CastSpell(targets, spellInfo, nullptr, TRIGGERED_NONE, nullptr, nullptr, ObjectGuid::Empty);

                        pos.SetOrientation(pos.GetOrientation() + (float(M_PI)/2.0f));
                    }
                }

                void Register()
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_seed_of_destruction_AuraScript::HandleOnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_seed_of_destruction_AuraScript();
        }
};

class at_vha_wake_of_destruction : public AreaTriggerEntityScript
{
    public:
        at_vha_wake_of_destruction() : AreaTriggerEntityScript("at_vha_wake_of_destruction")
        {}

        struct at_vha_wake_of_destruction_AI : public AreaTriggerAI
        {
            at_vha_wake_of_destruction_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void SetupSpline()
            {
                if (!at->GetCaster())
                    return;

                std::vector<G3D::Vector3> points;
                float dist = 100.f;

                G3D::Vector3 src = { at->GetPositionX(), at->GetPositionY(), at->GetPositionZ() };
                G3D::Vector3 tgt;

                tgt.x = src.x + (dist * cosf(at->GetOrientation()));
                tgt.y = src.y + (dist * sinf(at->GetOrientation()));
                tgt.z = src.z;

                float dx = (tgt.x - src.x);
                float dy = (tgt.y - src.y);

                for (uint32 i = 0; i < 100; ++i)
                {
                    src.x += (dx/dist);
                    src.y += (dy/dist);

                    points.push_back(src);
                }

                at->InitSplines(points, at->GetDuration()/1.8);
            }

            void OnInitialize() override
            {
                _attack = false;
                _timerAttack = 0;
                SetupSpline();
            }

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER && _attack)
                    at->GetCaster()->CastSpell(unit, SPELL_WAKE_OF_DESTRUCTION_DMG, true);
            }

            void OnUpdate(uint32 diff) override
            {
                if (_attack)
                    return;

                _timerAttack += diff;

                if (_timerAttack >= 500)
                    _attack = true;

            }

            private:
                uint32 _timerAttack;
                bool _attack;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_vha_wake_of_destruction_AI(at);
        }
};

void AddSC_boss_fel_lord_betrug()
{
    new boss_fel_lord_betrug();
    new npc_vha_stasis_crystal();
    new spell_betrug_chaotic_energy();
    new spell_betrug_execution();
    new spell_betrug_mighty_slash();
    new spell_betrug_mighty_slash_jump();
    new spell_betrug_seed_of_destruction();
    new at_vha_wake_of_destruction();
}
