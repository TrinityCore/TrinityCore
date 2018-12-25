/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_PAIN_AND_SUFFERING        = 93581,
    SPELL_PAIN_AND_SUFFERING_DUMMY  = 93605,
    SPELL_WRACKING_PAIN             = 93720,
    SPELL_DARK_ARCHANGEL_FORM       = 93757,
    SPELL_CALAMITY                  = 93812
};

#define SPELL_STAY_OF_EXECUTION RAID_MODE<uint32>(93468, 93705)

enum Texts
{
    // Baron Ashbury
    SAY_AGGRO                       = 1,
    SAY_ASPHYXIATE                  = 2,
    SAY_ANNOUNCE_STAY_OF_EXECUTION  = 3,
    SAY_STAY_OF_EXECUTION           = 4,
    SAY_ARCHANGEL_FORM              = 5,
    SAY_DEATH                       = 6
};

enum Events
{
    // Baron Ashbury
    EVENT_ASPHYXIATE = 1,
    EVENT_STAY_OF_EXECUTION,
    EVENT_PAIN_AND_SUFFERING,
    EVENT_WRACKING_PAIN,
    EVENT_DARK_ARCHANGEL_FORM,
    EVENT_DISABLE_ACHIEVEMENT,
    EVENT_APPLY_INTERRUPT_IMMUNITY
};

enum AchievementData
{
    DATA_PARDON_DENIED = 1
};

struct boss_baron_ashbury : public BossAI
{
    boss_baron_ashbury(Creature* creature) : BossAI(creature, DATA_BARON_ASHBURY)
    {
        Initialize();
    }

    void Initialize()
    {
        _phaseTwoTriggered = false;
        _isInArchangelForm = false;
        _canAttack = true;
        _pardonDenied = true;
    }

    void Reset() override
    {
        _Reset();
        _phaseTwoTriggered = false;
        _isInArchangelForm = false;
        _canAttack = true;
        _pardonDenied = true;
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.ScheduleEvent(EVENT_ASPHYXIATE, 20s);
        events.ScheduleEvent(EVENT_PAIN_AND_SUFFERING, 5s + 500ms);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_WRACKING_PAIN, 14s);
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
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WRACKING_PAIN);
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(25, damage) && !_phaseTwoTriggered && IsHeroic())
        {
            events.CancelEvent(EVENT_PAIN_AND_SUFFERING);
            events.CancelEvent(EVENT_ASPHYXIATE);
            events.CancelEvent(EVENT_STAY_OF_EXECUTION);
            events.CancelEvent(EVENT_APPLY_INTERRUPT_IMMUNITY);
            events.ScheduleEvent(EVENT_DARK_ARCHANGEL_FORM, 1ms);
            _phaseTwoTriggered = true;
        }
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        me->MakeInterruptable(false);
        events.CancelEvent(EVENT_APPLY_INTERRUPT_IMMUNITY);

        if (spell->Id == SPELL_STAY_OF_EXECUTION && IsHeroic())
            events.CancelEvent(EVENT_DISABLE_ACHIEVEMENT);
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_STAY_OF_EXECUTION && !IsHeroic())
        {
            me->MakeInterruptable(false);
            events.CancelEvent(EVENT_APPLY_INTERRUPT_IMMUNITY);
        }
        else if (spell->Id == SPELL_DARK_ARCHANGEL_FORM)
            _isInArchangelForm = true;
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

        if (me->HasUnitState(UNIT_STATE_CASTING) && !_isInArchangelForm)
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ASPHYXIATE:
                    Talk(SAY_ASPHYXIATE);
                    DoCastAOE(SPELL_ASPHYXIATE);
                    events.ScheduleEvent(EVENT_STAY_OF_EXECUTION, 7s);
                    _canAttack = false;
                    break;
                case EVENT_STAY_OF_EXECUTION:
                    me->StopMoving();
                    me->MakeInterruptable(true);
                    Talk(SAY_STAY_OF_EXECUTION);
                    Talk(SAY_ANNOUNCE_STAY_OF_EXECUTION);
                    DoCastAOE(SPELL_STAY_OF_EXECUTION);
                    events.ScheduleEvent(EVENT_ASPHYXIATE, 45s);
                    _canAttack = true;
                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_DISABLE_ACHIEVEMENT, 8s);
                        events.ScheduleEvent(EVENT_APPLY_INTERRUPT_IMMUNITY, 8s);
                    }
                    break;
                case EVENT_PAIN_AND_SUFFERING:
                    me->MakeInterruptable(true);
                    me->StopMoving();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    {
                        DoCast(target, SPELL_PAIN_AND_SUFFERING);
                        events.ScheduleEvent(EVENT_APPLY_INTERRUPT_IMMUNITY, 6s);
                    }
                    events.Repeat(26s + 500ms);
                    break;
                case EVENT_WRACKING_PAIN:
                    DoCastAOE(SPELL_WRACKING_PAIN, true);
                    events.Repeat(26s + 500ms);
                    break;
                case EVENT_DARK_ARCHANGEL_FORM:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->MakeInterruptable(false);
                    Talk(SAY_ARCHANGEL_FORM);
                    DoCastAOE(SPELL_DARK_ARCHANGEL_FORM);
                    break;
                case EVENT_DISABLE_ACHIEVEMENT:
                    _pardonDenied = false;
                    break;
                case EVENT_APPLY_INTERRUPT_IMMUNITY:
                    me->MakeInterruptable(false);
                    break;
                default:
                    break;
            }
        }
        if (_canAttack)
            DoMeleeAttackIfReady();
    }
private:
    bool _phaseTwoTriggered;
    bool _isInArchangelForm;
    bool _canAttack;
    bool _pardonDenied;
};

class spell_ashbury_asphyxiate : public AuraScript
{
    PrepareAuraScript(spell_ashbury_asphyxiate);

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

                if (damage >= target->GetHealth())
                    damage = target->GetHealth() - 1;

                if (!target->HasAura(SPELL_ASPHYXIATE_ROOT))
                    target->CastSpell(target, SPELL_ASPHYXIATE_ROOT, true);

                target->CastCustomSpell(triggerSpell, SPELLVALUE_BASE_POINT0, damage, target, true, nullptr, aurEff, caster->GetGUID());
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ashbury_asphyxiate::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_ashbury_pain_and_suffering : public AuraScript
{
    PrepareAuraScript(spell_ashbury_pain_and_suffering);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PAIN_AND_SUFFERING_DUMMY });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* owner = GetTarget())
            if (Unit* caster = GetCaster())
               owner->CastSpell(caster, SPELL_PAIN_AND_SUFFERING_DUMMY, true);

        uint64 damage = aurEff->GetBaseAmount() * aurEff->GetTickNumber();
        GetEffect(EFFECT_0)->ChangeAmount(damage);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ashbury_pain_and_suffering::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class spell_ashbury_dark_archangel_form : public AuraScript
{
    PrepareAuraScript(spell_ashbury_dark_archangel_form);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CALAMITY });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
            target->CastSpell(target, SPELL_CALAMITY, true);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_ashbury_dark_archangel_form::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
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
    RegisterShadowfangKeepCreatureAI(boss_baron_ashbury);
    RegisterAuraScript(spell_ashbury_asphyxiate);
    RegisterAuraScript(spell_ashbury_pain_and_suffering);
    RegisterAuraScript(spell_ashbury_dark_archangel_form);
    new achievement_pardon_denied();
}
