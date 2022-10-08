/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "karazhan_legion.h"

enum Spells
{
    // Nightbane
    SPELL_IGNITE_SOUL                       = 228796,
    SPELL_IGNITE_SOUL_DMG                   = 228800,
    SPELL_CHARRED_EARTH                     = 228862,
    SPELL_CHARRED_EARTH_MISSILE             = 228806,
    SPELL_CHARRED_EARTH_DMG                 = 228808,
    SPELL_CHARRED_EARTH_AURA                = 228863,
    SPELL_BURNING_BONES                     = 228829,
    SPELL_BURNING_BONES_SUMMON              = 228830,
    SPELL_CONCENTRATED_POWER                = 228790,
    SPELL_RAIN_OF_BONES                     = 228839,
    SPELL_BELLOWING_ROAR                    = 228837,
    SPELL_CINDER_BREATH                     = 228785,
    SPELL_INFERNAL_POWER                    = 228792,
    SPELL_REVERBERATING_SHADOWS             = 229307,
    SPELL_TAIL_SWEEP                        = 228787,

    // Restless Bone
    SPELL_BONE_SHRAPNEL                     = 228833,

    // Bonecurse
    SPELL_ABSORB_VITALITY                   = 228835,
    SPELL_JAGGED_SHARDS                     = 228834
};

enum Events
{
    // Nightbane
    EVENT_IGNITE_SOUL                       = 1,
    EVENT_CHARRED_EARTH                     = 2,
    EVENT_CINDER_BREATH                     = 3,
    EVENT_CONCENTRATED_POWER                = 4,
    EVENT_BURNING_BONES                     = 5,
    EVENT_ENTER_AIR_PHASE                   = 6,
    EVENT_ENTER_GROUND_PHASE                = 7,
    EVENT_REVERBERATING_SHADOWS             = 8,
    EVENT_BELLOWING_ROAR                    = 9,
    EVENT_INFERNAL_POWER                    = 10,
    EVENT_TAIL_SWEEP                        = 11,
    EVENT_RESTLESS_BONES                    = 12,

    // Bonecurse Golem
    EVENT_ABSORB_VITALITY                   = 13,
    EVENT_JAGGED_SHARDS                     = 14
};

enum Adds
{
    NPC_RESTLESS_BONES                      = 114906,
    NPC_BONECURSE_GOLEM                     = 114903
};

enum Says
{
    SAY_AGGRO                               = 0,
    SAY_IGNITE_SOUL                         = 1,
    SAY_AIR_PHASE                           = 2,
    SAY_PHASE_3                             = 3,
    SAY_BELLOWING_ROAR                      = 4,
    SAY_KILL                                = 5,
    SAY_WIPE                                = 6,
    SAY_DEATH                               = 7,
    SAY_INTRO                               = 8,
    SAY_INTRO_2                             = 9
};

constexpr uint32 POINT_AIR_PHASE            = 1;
constexpr uint32 POINT_GROUND_PHASE         = 2;
constexpr uint32 GROUND_PHASE               = 1;
constexpr uint32 AIR_PHASE                  = 2;
constexpr uint32 ACTION_NIGHTBANE_READY     = 1;

class boss_new_nightbane : public CreatureScript
{
    public:
        boss_new_nightbane() : CreatureScript("boss_new_nightbane") { }

        struct boss_new_nightbane_AI : public BossAI
        {
            explicit boss_new_nightbane_AI(Creature* me) : BossAI(me, DATA_NIGHTBANE) { }

            void Reset() override
            {
                if (instance->GetData(DATA_NIGHTBANE_EVENT) == DONE)
                    DoAction(ACTION_NIGHTBANE_READY);
                else
                {
                    me->SetVisible(false);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                }

                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);

                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                _secondPhase = false;
                events.ScheduleEvent(EVENT_CINDER_BREATH, 8s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_CHARRED_EARTH, 15s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_REVERBERATING_SHADOWS, 12s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_IGNITE_SOUL, 20s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_INFERNAL_POWER, 22s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_BURNING_BONES, 30s, GROUND_PHASE);
                events.ScheduleEvent(EVENT_TAIL_SWEEP, 40s, GROUND_PHASE);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_NIGHTBANE_READY)
                {
                    me->SetVisible(true);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    Talk(SAY_INTRO);
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /**/) override
            {
                if (summon && summon->GetEntry() == NPC_BONECURSE_GOLEM)
                {
                    me->RemoveAurasDueToSpell(SPELL_CHARRED_EARTH_AURA);
                    events.CancelEventGroup(AIR_PHASE);
                    events.ScheduleEvent(EVENT_ENTER_GROUND_PHASE, 100ms);
                }
            }

            void DamageTaken(Unit* /**/, uint32 & /**/) override
            {
                if (me->HealthBelowPct(50) && !_secondPhase)
                {
                    _secondPhase = true;
                    events.ScheduleEvent(EVENT_ENTER_AIR_PHASE, 100ms);
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (me->HasReactState(REACT_PASSIVE))
                    me->GetMotionMaster()->MoveLand(5, me->GetPosition());

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_SHARDS);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                me->RemoveAllAreaTriggers();
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_AGGRESSIVE);
                CreatureAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_SHARDS);
                Talk(SAY_DEATH);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE)
                {
                    if (id == POINT_AIR_PHASE)
                    {
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                        DoCastSelf(SPELL_CHARRED_EARTH_AURA, true);
                        DoCastSelf(SPELL_RAIN_OF_BONES);
                        events.ScheduleEvent(EVENT_RESTLESS_BONES, 8s, 12s, AIR_PHASE);
                    }
                    else if (POINT_GROUND_PHASE)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                        events.ScheduleEvent(EVENT_CINDER_BREATH, 8s);
                        events.ScheduleEvent(EVENT_CONCENTRATED_POWER, 15s, 18s);
                        events.ScheduleEvent(EVENT_INFERNAL_POWER, 30s);
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 20s);
                        events.ScheduleEvent(EVENT_IGNITE_SOUL, 20s, 25s);
                        events.ScheduleEvent(EVENT_CHARRED_EARTH, 15s);
                        events.ScheduleEvent(EVENT_REVERBERATING_SHADOWS, 12s);
                    }
                }
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_ENTER_AIR_PHASE:
                    {
                        Talk(SAY_AIR_PHASE);
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        events.CancelEventGroup(GROUND_PHASE);
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        Position pos = me->GetPosition();
                        pos.m_positionZ += 15.f;
                        me->GetMotionMaster()->MoveTakeoff(POINT_AIR_PHASE, pos);
                        break;
                    }

                    case EVENT_ENTER_GROUND_PHASE:
                    {
                        Talk(SAY_PHASE_3);
                        Position pos = me->GetPosition();
                        pos.m_positionZ -= 15.f;
                        me->GetMotionMaster()->MoveLand(POINT_GROUND_PHASE, pos);
                        break;
                    }

                    case EVENT_RESTLESS_BONES:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->SummonCreature(NPC_RESTLESS_BONES, target->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 5000);

                        events.ScheduleEvent(EVENT_RESTLESS_BONES, 8s, 12s, AIR_PHASE);
                        break;
                    }

                    case EVENT_BELLOWING_ROAR:
                    {
                        Talk(SAY_BELLOWING_ROAR);
                        DoCastSelf(SPELL_BELLOWING_ROAR);
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 45s);
                        break;
                    }

                    case EVENT_TAIL_SWEEP:
                    {
                        DoCastSelf(SPELL_TAIL_SWEEP);
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, 40s);
                        break;
                    }

                    case EVENT_REVERBERATING_SHADOWS:
                    {
                        DoCast(me, SPELL_REVERBERATING_SHADOWS);
                        events.ScheduleEvent(EVENT_REVERBERATING_SHADOWS, 12s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_CONCENTRATED_POWER:
                    {
                        DoCastSelf(SPELL_CONCENTRATED_POWER);
                        events.ScheduleEvent(EVENT_CONCENTRATED_POWER, 40s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_INFERNAL_POWER:
                    {
                        DoCastSelf(SPELL_INFERNAL_POWER);
                        events.ScheduleEvent(EVENT_INFERNAL_POWER, 30s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_CINDER_BREATH:
                    {
                        DoCastVictim(SPELL_CINDER_BREATH);
                        events.ScheduleEvent(EVENT_CINDER_BREATH, 23s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_BURNING_BONES:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true));

                        if (target)
                            me->CastCustomSpell(SPELL_BURNING_BONES, SPELLVALUE_AURA_STACK, 5, target, true);
                        else
                            me->CastCustomSpell(SPELL_BURNING_BONES, SPELLVALUE_AURA_STACK, 5, me->GetVictim(), true);

                        events.ScheduleEvent(EVENT_BURNING_BONES, 20s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_IGNITE_SOUL:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_IGNITE_SOUL);

                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true));

                        if (target)
                            DoCast(target, SPELL_IGNITE_SOUL);
                        else
                            DoCastVictim(SPELL_IGNITE_SOUL);

                        events.ScheduleEvent(EVENT_IGNITE_SOUL, 25s, GROUND_PHASE);
                        break;
                    }

                    case EVENT_CHARRED_EARTH:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_CHARRED_EARTH);

                        events.ScheduleEvent(EVENT_CHARRED_EARTH, 20s, GROUND_PHASE);
                        break;
                    }
                }
            }

            private:
                bool _secondPhase;
        };

        CreatureAI* GetAI(Creature* me) const override
        {
            return new boss_new_nightbane_AI(me);
        }
};

class npc_kara_bonecurse : public CreatureScript
{
    public:
        npc_kara_bonecurse() : CreatureScript("npc_kara_bonecurse") { }

        struct npc_kara_bonecurse_AI : public ScriptedAI
        {
            explicit npc_kara_bonecurse_AI(Creature* me) : ScriptedAI(me) { }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /**/)
            {
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_ABSORB_VITALITY, 20s);
                _events.ScheduleEvent(EVENT_JAGGED_SHARDS, 8s, 12s);
            }

            void ExecuteEvent(uint32 eventId)
            {
                if (eventId == EVENT_ABSORB_VITALITY)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_ABSORB_VITALITY);

                    _events.ScheduleEvent(EVENT_ABSORB_VITALITY, 20s);
                }
                else if (eventId == EVENT_JAGGED_SHARDS)
                {
                    DoCastAOE(SPELL_JAGGED_SHARDS, true);
                    _events.ScheduleEvent(EVENT_JAGGED_SHARDS, 8s, 12s);
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
                    ExecuteEvent(eventId);
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;

        };

        CreatureAI* GetAI(Creature* me) const override
        {
            return new npc_kara_bonecurse_AI(me);
        }
};

class npc_kara_restless_bones : public CreatureScript
{
    public:
        npc_kara_restless_bones() : CreatureScript("npc_kara_restless_bones") { }

        struct npc_kara_restless_bones_AI : public ScriptedAI
        {
            explicit npc_kara_restless_bones_AI(Creature* me) : ScriptedAI(me) { }

            void JustDied(Unit* /**/) override
            {
                DoCastSelf(SPELL_BONE_SHRAPNEL, true);
            }
        };

        CreatureAI* GetAI(Creature* me) const override
        {
            return new npc_kara_restless_bones_AI(me);
        }
};

class spell_nightbane_charred_earth : public SpellScriptLoader
{
    public:
        spell_nightbane_charred_earth() : SpellScriptLoader("spell_nightbane_charred_earth") { }

        class spell_charred_earth_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_charred_earth_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_CHARRED_EARTH_MISSILE, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_charred_earth_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_charred_earth_SpellScript();
        }
};

class spell_nightbane_ignite_soul : public SpellScriptLoader
{
    public:
        spell_nightbane_ignite_soul() : SpellScriptLoader("spell_nightbane_ignite_soul") { }

        class spell_ignite_soul_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_ignite_soul_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes)
                {
                    if (!GetUnitOwner())
                        return;

                    Unit* && owner = GetUnitOwner();
                    owner->CastCustomSpell(SPELL_IGNITE_SOUL_DMG, SPELLVALUE_BASE_POINT0, owner->GetHealth(), owner, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_ignite_soul_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ignite_soul_AuraScript();
        }
};

class spell_nightbane_burning_bones : public SpellScriptLoader
{
    public:
        spell_nightbane_burning_bones() : SpellScriptLoader("spell_nightbane_burning_bones") { }

        class spell_burning_bones_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_burning_bones_AuraScript);

                bool Load() override
                {
                    _counter = 0;
                    return true;
                }

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    if (++_counter % 2 == 0 && GetStackAmount() > 1)
                        ModStackAmount(-1);
                }

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    Unit* && owner = GetUnitOwner();

                    uint8 stacks = GetStackAmount();
                    for (uint8 i = 0; i < stacks; ++i)
                        owner->CastSpell(owner, SPELL_BURNING_BONES_SUMMON, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_burning_bones_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_burning_bones_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                }

            private:
                uint8 _counter;

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_burning_bones_AuraScript();
        }
};

class spell_kara_absorb_vitality : public SpellScriptLoader
{
    public:
        spell_kara_absorb_vitality() : SpellScriptLoader("spell_kara_absorb_vitality") { }

        class spell_absorb_vitality_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_absorb_vitality_AuraScript);

                bool Load() override
                {
                    _healthAbsorbed = 0;
                    return true;
                }

                void HandlePeriodic(AuraEffect const* aurEff)
                {
                    if (!aurEff)
                        return;

                    GetCaster()->ModifyHealth(aurEff->GetAmount() * 5);
                }

                void HandleOnAbsorb(AuraEffect* aurEff, DamageInfo& /**/, uint32& absorbAmount)
                {
                    _healthAbsorbed += absorbAmount;

                    if (_healthAbsorbed >= uint32(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints))
                        GetUnitOwner()->RemoveAura(aurEff->GetBase());
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_absorb_vitality_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_LEECH);
                    AfterEffectAbsorb += AuraEffectAbsorbFn(spell_absorb_vitality_AuraScript::HandleOnAbsorb, EFFECT_1);
                }

                private:
                    uint32 _healthAbsorbed;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_absorb_vitality_AuraScript();
        }
};

class at_kara_charred_earth : public AreaTriggerEntityScript
{
    public:
        at_kara_charred_earth() : AreaTriggerEntityScript("at_kara_charred_earth") { }

        struct at_kara_charred_earth_AI : public AreaTriggerAI
        {
            explicit at_kara_charred_earth_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_CHARRED_EARTH_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_CHARRED_EARTH_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_charred_earth_AI(at);
        }
};

void AddSC_boss_nightbane_karazhan_legion()
{
    new boss_new_nightbane();
    new npc_kara_bonecurse();
    new npc_kara_restless_bones();
    new spell_nightbane_ignite_soul();
    new spell_nightbane_burning_bones();
    new spell_nightbane_charred_earth();
    new spell_kara_absorb_vitality();
    new at_kara_charred_earth();
}
