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

#include "shadowfang_keep.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"

enum Spells
{
    // Baron Ashbury
    SPELL_ASPHYXIATE                = 93423,
    SPELL_ASPHYXIATE_ROOT           = 93422,
    SPELL_ASPHYXIATE_DAMAGE         = 93424,
    SPELL_STAY_OF_EXECUTION         = 93468,
    SPELL_STAY_OF_EXECUTION_HC      = 93705,
    SPELL_PAIN_AND_SUFFERING        = 93581,
    SPELL_PAIN_AND_SUFFERING_DUMMY  = 93605,
    SPELL_WRACKING_PAIN             = 93720,
    SPELL_DARK_ARCHANGEL            = 93757,
    SPELL_CALAMITY_CHANNEL          = 93812,

    // Wings
    SPELL_RIDE_VEHICLE_HARDCODED    = 46598,
    SPELL_CALAMITY_AURA             = 93766,
};

enum Texts
{
    SAY_AGGRO           = 1,
    SAY_ASPHYXIATE      = 2,
    SAY_ANNOUNCE_STAY   = 3,
    SAY_STAY_EXECUTION  = 4,
    SAY_ARCHANGEL       = 5,
    SAY_DEATH           = 6,
};

enum Events
{
    EVENT_ASPHYXIATE = 1,
    EVENT_STAY_OF_EXECUTION,
    EVENT_PAIN_AND_SUFFERING,
    EVENT_WRACKING_PAIN,
    EVENT_DARK_ARCHANGEL,
    EVENT_APPLY_IMMUNITY,
    EVENT_DISABLE_ACHIEVEMENT,
};

enum AchievementData
{
    DATA_PARDON_DENIED = 1,
};

class boss_baron_ashbury : public CreatureScript
{
public:
    boss_baron_ashbury() : CreatureScript("boss_baron_ashbury") { }

    struct boss_baron_ashburyAI : public BossAI
    {
        boss_baron_ashburyAI(Creature* creature) : BossAI(creature, DATA_BARON_ASHBURY)
        {
        }

        void Reset() override
        {
            _Reset();
            _isArchangel = false;
            _canAttack = true;
            _pardonDenied = true;
            me->SetReactState(REACT_PASSIVE);
            MakeInterruptable(false);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_ASPHYXIATE, Seconds(20));
            events.ScheduleEvent(EVENT_PAIN_AND_SUFFERING, Seconds(5) + Milliseconds(500));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_WRACKING_PAIN, Seconds(14));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WRACKING_PAIN);
            Talk(SAY_DEATH);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            instance->SetBossState(DATA_BARON_ASHBURY, FAIL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WRACKING_PAIN);
            MakeInterruptable(false);
            me->SetReactState(REACT_PASSIVE);
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (me->HealthBelowPct(25) && !_isArchangel && IsHeroic())
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DARK_ARCHANGEL, Milliseconds(1));
                _isArchangel = true;
            }
        }

        void OnSpellCastInterrupt(SpellInfo const* spell) override
        {
            MakeInterruptable(false);
            events.CancelEvent(EVENT_APPLY_IMMUNITY);

            if (spell->Id == SPELL_STAY_OF_EXECUTION_HC && _pardonDenied)
                events.CancelEvent(EVENT_DISABLE_ACHIEVEMENT);
        }

        void MakeInterruptable(bool apply)
        {
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, !apply);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, !apply);
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_PARDON_DENIED:
                    return _pardonDenied;
                default:
                    break;
            }
            return 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ASPHYXIATE:
                        Talk(SAY_ASPHYXIATE);
                        DoCastAOE(SPELL_ASPHYXIATE);
                        events.ScheduleEvent(EVENT_STAY_OF_EXECUTION, Seconds(7));
                        _canAttack = false;
                        break;
                    case EVENT_STAY_OF_EXECUTION:
                        if (IsHeroic())
                        {
                            MakeInterruptable(true);
                            events.ScheduleEvent(EVENT_APPLY_IMMUNITY, Seconds(8));
                            events.ScheduleEvent(EVENT_DISABLE_ACHIEVEMENT, Seconds(8));
                        }
                        Talk(SAY_STAY_EXECUTION);
                        Talk(SAY_ANNOUNCE_STAY);
                        DoCastAOE(SPELL_STAY_OF_EXECUTION);
                        events.ScheduleEvent(EVENT_ASPHYXIATE, Seconds(45));
                        _canAttack = true;
                        break;
                    case EVENT_PAIN_AND_SUFFERING:
                        MakeInterruptable(true);
                        me->StopMoving();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_PAIN_AND_SUFFERING);

                        events.ScheduleEvent(EVENT_APPLY_IMMUNITY, IsHeroic() ? Seconds(6) : Seconds(8));
                        events.Repeat(Seconds(26) + Milliseconds(500));
                        break;
                    case EVENT_WRACKING_PAIN:
                        DoCastAOE(SPELL_WRACKING_PAIN);
                        events.Repeat(Seconds(26) + Milliseconds(500));
                        break;
                    case EVENT_DARK_ARCHANGEL:
                        Talk(SAY_ARCHANGEL);
                        me->CastStop();
                        DoCastAOE(SPELL_DARK_ARCHANGEL);
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        MakeInterruptable(false);
                        if (Creature* wings = DoSummon(NPC_ASHBURY_WINGS, me->GetPosition(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                            wings->CastSpell(me, SPELL_RIDE_VEHICLE_HARDCODED);
                        break;
                    case EVENT_APPLY_IMMUNITY:
                        MakeInterruptable(true);
                        break;
                    case EVENT_DISABLE_ACHIEVEMENT:
                        _pardonDenied = false;
                        break;
                    default:
                        break;
                }
            }
            if (_canAttack)
                DoMeleeAttackIfReady();
        }

    private:
        bool _isArchangel;
        bool _canAttack;
        bool _pardonDenied;
    };
    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetShadowfangKeepAI<boss_baron_ashburyAI>(creature);
    }
};

class spell_sfk_asphyxiate : public SpellScriptLoader
{
public:
    spell_sfk_asphyxiate() : SpellScriptLoader("spell_sfk_asphyxiate") { }

    class spell_sfk_asphyxiate_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sfk_asphyxiate_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ASPHYXIATE_ROOT });
        }

        void HandleTriggerSpell(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetTarget())
                {
                    uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_2].TriggerSpell;
                    uint64 damage = target->GetMaxHealth() / GetSpellInfo()->GetMaxTicks();

                    if (damage > target->GetHealth())
                        damage = target->GetHealth() - 1;

                    if (!target->HasAura(SPELL_ASPHYXIATE_ROOT))
                        target->CastSpell(target, SPELL_ASPHYXIATE_ROOT, true);

                    target->CastCustomSpell(triggerSpell, SPELLVALUE_BASE_POINT0, damage, target, true, nullptr, aurEff, caster->GetGUID());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sfk_asphyxiate_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sfk_asphyxiate_AuraScript();
    }
};

class spell_sfk_pain_and_suffering : public SpellScriptLoader
{
    public:
        spell_sfk_pain_and_suffering() : SpellScriptLoader("spell_sfk_pain_and_suffering") { }

        class spell_sfk_pain_and_suffering_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sfk_pain_and_suffering_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PAIN_AND_SUFFERING_DUMMY });
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                    if (InstanceScript* instance = owner->GetInstanceScript())
                        if (Creature* ashbury = instance->GetCreature(DATA_BARON_ASHBURY))
                            owner->CastSpell(ashbury, SPELL_PAIN_AND_SUFFERING_DUMMY, true);

                uint64 damage = aurEff->GetBaseAmount() * aurEff->GetTickNumber();
                GetEffect(EFFECT_0)->ChangeAmount(damage);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sfk_pain_and_suffering_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sfk_pain_and_suffering_AuraScript();
        }
};

class achievement_pardon_denied : public AchievementCriteriaScript
{
public:
    achievement_pardon_denied() : AchievementCriteriaScript("achievement_pardon_denied") { }

    bool OnCheck(Player* /*source*/, Unit* target)
    {
        if (!target)
            return false;

        if (target->GetMap()->IsHeroic())
            return target->GetAI()->GetData(DATA_PARDON_DENIED);

        return false;
    }
};

void AddSC_boss_baron_ashbury()
{
    new boss_baron_ashbury();
    new spell_sfk_asphyxiate();
    new spell_sfk_pain_and_suffering();
    new achievement_pardon_denied();
}
