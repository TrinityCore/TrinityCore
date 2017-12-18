/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "lost_city_of_the_tolvir.h"

enum Texts
{
    SAY_UNLEASHED       = 0,
    SAY_AGGRO           = 1,
    SAY_WAILING_WINDS   = 2,
    SAY_SLAY            = 3,
    SAY_DEATH           = 4
};

enum Spells
{
    // Siamat
    SPELL_STATIC_SHOCK_1            = 84546,
    SPELL_STATIC_SHOCK_2            = 84555,
    SPELL_STATIC_SHOCK_3            = 84556,
    SPELL_STORM_BOLT                = 73564,
    SPELL_DEFLECTING_WINDS          = 84589,
    SPELL_WAILING_WINDS             = 83066,
    SPELL_WAILING_WINDS_DAMAGE      = 83094,
    SPELL_CLOUD_BURST               = 83790,
    SPELL_CALL_OF_SKY               = 84956,
    SPELL_STORM_BOLT_PHASE_2        = 91853,
    SPELL_ABSORB_STORMS             = 83151,

    // Servant of Siamat
    SPELL_MOD_SCALE                 = 59632,
    SPELL_THUNDER_CRASH             = 84521,
    SPELL_LIGHTNING_NOVA            = 84544,
    SPELL_LIGHTNING_CHARGE          = 91872,

    // Minion of Siamat
    SPELL_DEPLETION                 = 84550,
    SPELL_CHAIN_LIGHTNING           = 83455,
    SPELL_TEMPEST_STORM_SUMMON      = 83414,
    SPELL_TEMPEST_STORM_TRANSFORM   = 83170
};

enum Events
{
    // Siamat
    EVENT_TALK_UNLEASHED = 1,
    EVENT_STATIC_SHOCK,
    EVENT_DEFLECTING_WINDS,
    EVENT_STORM_BOLT,
    EVENT_CLOUD_BURST,
    EVENT_CALL_OF_SKY,
    EVENT_WAILING_WINDS,
    EVENT_ABSORB_STORMS,
    EVENT_CHASE_PLAYER,

    // Servant of Siamat
    EVENT_REMOVE_SCALE_AURA,
    EVENT_SEND_ENCOUNTER_FRAME,
    EVENT_ATTACK_PLAYER,
    EVENT_THUNDER_CRASH,
    EVENT_LIGHTNING_NOVA,
    EVENT_LIGHTNING_CHARGE,
    EVENT_KILL_SELF,

    // Minion of Siamat
    EVENT_CHAIN_LIGHTNING,

    // Tempest Storm
    EVENT_MOVE_ARROUND
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_1         = 2,
    PHASE_2         = 3
};

enum Actions
{
    ACTION_UNLEASHED = 1
};

class boss_siamat : public CreatureScript
{
    public:
        boss_siamat() : CreatureScript("boss_siamat") { }

        struct boss_siamatAI : public BossAI
        {
            boss_siamatAI(Creature* creature) : BossAI(creature, DATA_SIAMAT)
            {
                Initialize();
            }

            void Initialize()
            {
                _lastStaticShockSpellID = 0;
                _deadServants = 0;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                SetCombatMovement(false);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.SetPhase(PHASE_1);
                events.ScheduleEvent(EVENT_STATIC_SHOCK, 1, 0, PHASE_1);
                events.ScheduleEvent(EVENT_DEFLECTING_WINDS, Seconds(6), 0, PHASE_1);
                events.ScheduleEvent(EVENT_STORM_BOLT, Seconds(1), 0, PHASE_1);
                events.ScheduleEvent(EVENT_CLOUD_BURST, Seconds(13), PHASE_1);
                events.ScheduleEvent(EVENT_CALL_OF_SKY, Seconds(13));
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
                DespawnServants();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                DespawnServants();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_UNLEASHED:
                        events.SetPhase(PHASE_INTRO);
                        events.ScheduleEvent(EVENT_TALK_UNLEASHED, Seconds(15));
                        break;
                    default:
                        break;
                }
            }

            void DespawnServants()
            {
                for (uint8 i = 0; i < 3; i++)
                {
                    if (Creature* servant = instance->GetCreature(DATA_SERVANT_OF_SIAMAT_1 + i))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, servant);
                        servant->DespawnOrUnsummon(Milliseconds(100));
                    }
                }
            }

            void JustSummoned(Creature* summon) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_SERVANT_OF_SIAMAT_1:
                    case NPC_SERVANT_OF_SIAMAT_2:
                    case NPC_SERVANT_OF_SIAMAT_3:
                        break;
                    case NPC_CLOUD_BURST:
                        // needed to prevent that weird imp model showing up that is NOT
                        // inside the db but still shows up for some reason
                        summon->SetDisplayId(summon->GetCreatureTemplate()->Modelid2);
                        break;
                    default:
                        summons.Summon(summon);
                        break;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_SERVANT_OF_SIAMAT_1:
                    case NPC_SERVANT_OF_SIAMAT_2:
                    case NPC_SERVANT_OF_SIAMAT_3:
                        _deadServants++;
                        if (_deadServants == 3)
                        {
                            events.CancelEvent(EVENT_STORM_BOLT);
                            events.CancelEvent(EVENT_CLOUD_BURST);
                            events.SetPhase(PHASE_2);
                            events.ScheduleEvent(EVENT_WAILING_WINDS, 1, 0, PHASE_2);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_TALK_UNLEASHED:
                            Talk(SAY_UNLEASHED);
                            break;
                        case EVENT_STATIC_SHOCK:
                            if (_lastStaticShockSpellID == 0)
                            {
                                DoCastAOE(SPELL_STATIC_SHOCK_1);
                                _lastStaticShockSpellID = SPELL_STATIC_SHOCK_1;
                                events.Repeat(Seconds(45));
                            }
                            else if (_lastStaticShockSpellID == SPELL_STATIC_SHOCK_1)
                            {
                                DoCastAOE(SPELL_STATIC_SHOCK_2);
                                _lastStaticShockSpellID = SPELL_STATIC_SHOCK_2;
                                events.Repeat(Seconds(45));
                            }
                            else if (_lastStaticShockSpellID == SPELL_STATIC_SHOCK_2)
                                DoCastAOE(SPELL_STATIC_SHOCK_3);
                            break;
                        case EVENT_DEFLECTING_WINDS:
                            DoCastSelf(SPELL_DEFLECTING_WINDS);
                            break;
                        case EVENT_STORM_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                                DoCast(target, events.IsInPhase(PHASE_1) ? SPELL_STORM_BOLT : SPELL_STORM_BOLT_PHASE_2);

                            events.Repeat(events.IsInPhase(PHASE_1) ? Seconds(2) + Milliseconds(200) : Seconds(22));
                            break;
                        case EVENT_CLOUD_BURST:
                            // Why do we need a specific target here when we have TARGET_UNIT_SRC_AREA_ENEMY as target???
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                                DoCast(target, SPELL_CLOUD_BURST, true);
                            events.Repeat(Seconds(27));
                            break;
                        case EVENT_WAILING_WINDS:
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                            Talk(SAY_WAILING_WINDS);
                            me->RemoveAurasDueToSpell(SPELL_DEFLECTING_WINDS);
                            DoCastAOE(SPELL_WAILING_WINDS);
                            events.ScheduleEvent(EVENT_CHASE_PLAYER, Seconds(6));
                            events.ScheduleEvent(EVENT_STORM_BOLT, Seconds(19));
                            events.ScheduleEvent(EVENT_ABSORB_STORMS, Seconds(14));
                            break;
                        case EVENT_CALL_OF_SKY:
                            DoCastAOE(SPELL_CALL_OF_SKY, true);
                            events.Repeat(Seconds(32));
                            break;
                        case EVENT_ABSORB_STORMS:
                            if (me->FindNearestCreature(NPC_MINION_OF_SIAMAT_STORM, 50.0f, true))
                                DoCastAOE(SPELL_ABSORB_STORMS);
                            events.Repeat(Seconds(32));
                            break;
                        case EVENT_CHASE_PLAYER:
                            SetCombatMovement(true);
                            if (me->GetVictim())
                                me->GetMotionMaster()->MoveChase(me->GetVictim());
                            break;
                        default:
                            break;
                    }
                }
                if (events.IsInPhase(PHASE_2))
                    DoMeleeAttackIfReady();
            }
        private:
            uint32 _lastStaticShockSpellID;
            uint8 _deadServants;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<boss_siamatAI>(creature);
        }
};

class npc_siamat_servant_of_siamat : public CreatureScript
{
    public:
        npc_siamat_servant_of_siamat() :  CreatureScript("npc_siamat_servant_of_siamat") { }

        struct npc_siamat_servant_of_siamatAI : public ScriptedAI
        {
            npc_siamat_servant_of_siamatAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                _chargeTriggered = false;
                _events.SetPhase(PHASE_INTRO);

                if (_instance->GetBossState(DATA_SIAMAT) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
                else
                    _events.ScheduleEvent(EVENT_SEND_ENCOUNTER_FRAME, Seconds(1));
            }


            void EnterCombat(Unit* /*who*/) override
            {
                _events.SetPhase(PHASE_1);
                _events.ScheduleEvent(EVENT_THUNDER_CRASH, Seconds(11));
                _events.ScheduleEvent(EVENT_LIGHTNING_NOVA, Seconds(13));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon(Seconds(5));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPct(4) && !_chargeTriggered)
                {
                    if (IsHeroic())
                    {
                        _chargeTriggered = true;
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_LIGHTNING_CHARGE, 1);
                    }
                }

                if (IsHeroic())
                    if (damage >= me->GetHealth())
                        damage = me->GetHealth() - 1;
            }


            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_INTRO))
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_SEND_ENCOUNTER_FRAME:
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                            _events.ScheduleEvent(EVENT_REMOVE_SCALE_AURA, Seconds(1));
                            break;
                        case EVENT_REMOVE_SCALE_AURA:
                            me->RemoveAurasDueToSpell(SPELL_MOD_SCALE);
                            _events.ScheduleEvent(EVENT_ATTACK_PLAYER, Seconds(2));
                            break;
                        case EVENT_ATTACK_PLAYER:
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoZoneInCombat();
                            break;
                        case EVENT_THUNDER_CRASH:
                            DoCastSelf(SPELL_THUNDER_CRASH);
                            break;
                        case EVENT_LIGHTNING_NOVA:
                            DoCastAOE(SPELL_LIGHTNING_NOVA, true);
                            break;
                        case EVENT_LIGHTNING_CHARGE:
                            DoCastAOE(SPELL_LIGHTNING_CHARGE);
                            _events.ScheduleEvent(EVENT_KILL_SELF, Seconds(2) + Milliseconds(100));
                            break;
                        case EVENT_KILL_SELF:
                            me->KillSelf();
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
            bool _chargeTriggered;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<npc_siamat_servant_of_siamatAI>(creature);
        }
};

class npc_siamat_minion_of_siamat : public CreatureScript
{
    public:
        npc_siamat_minion_of_siamat() :  CreatureScript("npc_siamat_minion_of_siamat") { }

        struct npc_siamat_minion_of_siamatAI : public ScriptedAI
        {
            npc_siamat_minion_of_siamatAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            // Yes, we need to place it in here. Reset() is still too "late"
            void InitializeAI() override
            {
                me->SetReactState(REACT_PASSIVE);
                _transformed = false;
                _events.SetPhase(PHASE_INTRO);
                _events.ScheduleEvent(EVENT_REMOVE_SCALE_AURA, Seconds(1));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.SetPhase(PHASE_1);
                _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, Seconds(3));
            }

            void JustSummoned(Creature* summon) override
            {
                if (Creature* siamat = _instance->GetCreature(DATA_SIAMAT))
                    siamat->AI()->JustSummoned(summon);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPct(5) && !_transformed)
                {
                    _events.Reset();
                    me->AttackStop();
                    me->CastStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_TEMPEST_STORM_SUMMON, true);
                    DoCastSelf(SPELL_TEMPEST_STORM_TRANSFORM);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->DespawnOrUnsummon(Seconds(4));
                    _transformed = true;
                }

                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_INTRO))
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_REMOVE_SCALE_AURA:
                            me->RemoveAurasDueToSpell(SPELL_MOD_SCALE);
                            DoCastSelf(SPELL_DEPLETION, true);
                            _events.ScheduleEvent(EVENT_ATTACK_PLAYER, Seconds(1) + Milliseconds(500));
                            break;
                        case EVENT_ATTACK_PLAYER:
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoZoneInCombat();
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            _events.Repeat(Seconds(1) + Milliseconds(500));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
            bool _transformed;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siamat_minion_of_siamatAI(creature);
        }
};

class spell_siamat_thunder_crash : public SpellScriptLoader
{
    public:
        spell_siamat_thunder_crash() : SpellScriptLoader("spell_siamat_thunder_crash") { }

        class spell_siamat_thunder_crash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_siamat_thunder_crash_AuraScript);

            void HandleTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (Unit* victim = caster->GetVictim())
                        caster->CastSpell(victim, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_siamat_thunder_crash_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

    AuraScript* GetAuraScript() const
    {
        return new spell_siamat_thunder_crash_AuraScript();
    }
};

class spell_siamat_wailing_winds : public SpellScriptLoader
{
    public:
        spell_siamat_wailing_winds() : SpellScriptLoader("spell_siamat_wailing_winds") { }

        class spell_siamat_wailing_winds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_siamat_wailing_winds_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, SPELL_WAILING_WINDS_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_siamat_wailing_winds_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_siamat_wailing_winds_AuraScript();
        }
};

class spell_siamat_wailing_winds_player : public SpellScriptLoader
{
public:
    spell_siamat_wailing_winds_player() : SpellScriptLoader("spell_siamat_wailing_winds_player") { }

    class spell_siamat_wailing_winds_player_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_siamat_wailing_winds_player_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            if (GetCaster())
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* siamat = instance->GetCreature(DATA_SIAMAT))
                        siamat->CastSpell(siamat, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_siamat_wailing_winds_player_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_siamat_wailing_winds_player_AuraScript();
    }
};

class spell_siamat_wailing_winds_knockback : public SpellScriptLoader
{
public:
    spell_siamat_wailing_winds_knockback() : SpellScriptLoader("spell_siamat_wailing_winds_knockback") { }

    class spell_siamat_wailing_winds_knockback_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_siamat_wailing_winds_knockback_SpellScript);

        void EffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* victim = GetHitUnit())
                {
                    float distance = caster->GetDistance2d(caster) * 2;
                    float ori = frand(0.0f, float(M_PI * 2));
                    float randX = victim->GetPositionX() + cos(ori) * distance;
                    float randY = victim->GetPositionY() + sin(ori) * distance;
                    float baseSpeed = float(GetSpellInfo()->Effects[EFFECT_1].BasePoints);

                    victim->KnockbackFrom(randX, randY, CalculatePct(baseSpeed - distance, 15), 9.0f);
                };
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_siamat_wailing_winds_knockback_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_siamat_wailing_winds_knockback_SpellScript();
    }
};

class spell_siamat_cloud_burst : public SpellScriptLoader
{
public:
    spell_siamat_cloud_burst() : SpellScriptLoader("spell_siamat_cloud_burst") { }

    class spell_siamat_cloud_burst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_siamat_cloud_burst_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siamat_cloud_burst_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_siamat_cloud_burst_SpellScript();
    }
};

class spell_siamat_gathered_storms : public SpellScriptLoader
{
public:
    spell_siamat_gathered_storms() : SpellScriptLoader("spell_siamat_gathered_storms") { }

    class spell_siamat_gathered_storms_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_siamat_gathered_storms_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 2);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siamat_gathered_storms_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_siamat_gathered_storms_SpellScript();
    }
};

class spell_siamat_absorb_storms : public SpellScriptLoader
{
    public:
        spell_siamat_absorb_storms() : SpellScriptLoader("spell_siamat_absorb_storms") { }

        class spell_siamat_absorb_storms_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_siamat_absorb_storms_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_siamat_absorb_storms_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        class spell_siamat_absorb_storms_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siamat_absorb_storms_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    caster->SetFacingToObject(GetHitUnit());
                    if (GetHitUnit()->GetTypeId() == TYPEID_UNIT)
                        GetHitUnit()->ToCreature()->DespawnOrUnsummon(Seconds(3) + Milliseconds(100));
                }
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }


            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_siamat_absorb_storms_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siamat_absorb_storms_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_siamat_absorb_storms_AuraScript();
        }

        SpellScript* GetSpellScript() const
        {
            return new spell_siamat_absorb_storms_SpellScript();
        }
};

void AddSC_boss_siamat()
{
    new boss_siamat();
    new npc_siamat_servant_of_siamat();
    new npc_siamat_minion_of_siamat();
    new spell_siamat_thunder_crash();
    new spell_siamat_wailing_winds();
    new spell_siamat_wailing_winds_player();
    new spell_siamat_wailing_winds_knockback();
    new spell_siamat_cloud_burst();
    new spell_siamat_gathered_storms();
    new spell_siamat_absorb_storms();
}
