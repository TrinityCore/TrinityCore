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

/*
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "hellfire_ramparts.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum OmorTexts
{
    SAY_SUMMON                       = 0,
    SAY_KNOCK                        = 1,
    SAY_AGGRO                        = 2,
    SAY_SLAY                         = 3,
    SAY_DEATH                        = 4,
    EMOTE_SHIELD                     = 5
};

enum OmorSpells
{
    // Combat
    SPELL_SHADOW_BOLT                = 30686,
    SPELL_TREACHEROUS_AURA           = 30695,
    SPELL_SUMMON_FIENDISH_HOUND      = 30707,
    SPELL_ORBITAL_STRIKE_TARGET      = 35642,
    SPELL_DEMONIC_SHIELD             = 31901,

    // Scripts
    SPELL_ORBITAL_STRIKE_WHIP        = 32185,
    SPELL_ORBITAL_STRIKE_KNOCK       = 30637
};

enum OmorEvents
{
    EVENT_SHADOW_BOLT                = 1,
    EVENT_TREACHEROUS_AURA,
    EVENT_SUMMON_FIENDISH_HOUND,
    EVENT_ORBITAL_STRIKE_TARGET,
    EVENT_DEMONIC_SHIELD
};

// 17308 - Omor the Unscarred
struct boss_omor_the_unscarred : public BossAI
{
    boss_omor_the_unscarred(Creature* creature) : BossAI(creature, DATA_OMOR_THE_UNSCARRED), _demonicShieldUsed(false) { }

    void Reset() override
    {
        _Reset();

        _demonicShieldUsed = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SHADOW_BOLT, 0s);
        events.ScheduleEvent(EVENT_TREACHEROUS_AURA, 16s, 23s);
        events.ScheduleEvent(EVENT_SUMMON_FIENDISH_HOUND, 20s, 23s);
        events.ScheduleEvent(EVENT_ORBITAL_STRIKE_TARGET, 25s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 100.0f);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SUMMON_FIENDISH_HOUND:
                if (roll_chance_i(30))
                    Talk(SAY_SUMMON);
                break;
            case SPELL_DEMONIC_SHIELD:
                Talk(EMOTE_SHIELD);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_demonicShieldUsed && me->HealthBelowPctDamaged(20, damage))
        {
            _demonicShieldUsed = true;
            events.ScheduleEvent(EVENT_DEMONIC_SHIELD, 0s);
        }
    }

    void JustSummoned(Creature* summoned) override
    {
        // Engage but don't despawn hounds
        if (me->IsEngaged())
            DoZoneInCombat(summoned);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                        events.Repeat(6s, 10s);
                    else
                        events.Repeat(3s, 4s);
                    break;
                case EVENT_TREACHEROUS_AURA:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_TREACHEROUS_AURA);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_SUMMON_FIENDISH_HOUND:
                    DoCastSelf(SPELL_SUMMON_FIENDISH_HOUND);
                    events.Repeat(20s, 26s);
                    break;
                case EVENT_ORBITAL_STRIKE_TARGET:
                    DoCastSelf(SPELL_ORBITAL_STRIKE_TARGET);
                    events.Repeat(23s, 30s);
                    break;
                case EVENT_DEMONIC_SHIELD:
                    DoCastSelf(SPELL_DEMONIC_SHIELD);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _demonicShieldUsed;
};

// 35642 - Orbital Strike Target
class spell_omor_the_unscarred_orbital_strike_target : public SpellScript
{
    PrepareSpellScript(spell_omor_the_unscarred_orbital_strike_target);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ORBITAL_STRIKE_WHIP, SPELL_ORBITAL_STRIKE_KNOCK });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() <= 1)
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject const* target)
        {
            return caster->GetExactDist2d(target) > 20.0f;
        });

        Trinity::Containers::RandomResize(targets, 1);
        _canContinue = true;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!_canContinue)
            return;

        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(caster, SPELL_ORBITAL_STRIKE_WHIP, true);
        caster->CastSpell(target, SPELL_ORBITAL_STRIKE_KNOCK, true);

        if (Creature* creature = caster->ToCreature())
            creature->AI()->Talk(SAY_KNOCK, target);

        if (caster->CanHaveThreatList())
            caster->GetThreatManager().ModifyThreatByPercent(target, -100);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omor_the_unscarred_orbital_strike_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_omor_the_unscarred_orbital_strike_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    bool _canContinue = false;
};

// 32185 - Orbital Strike
class spell_omor_the_unscarred_orbital_strike_whip : public AuraScript
{
    PrepareAuraScript(spell_omor_the_unscarred_orbital_strike_whip);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (Creature* creature = GetTarget()->ToCreature())
        {
            for (ThreatReference const* ref : creature->GetThreatManager().GetUnsortedThreatList())
            {
                Unit* victim = ref->GetVictim();
                if (victim->IsPlayer() && victim->IsFalling())
                    creature->CastSpell(victim, aurEff->GetSpellEffectInfo().TriggerSpell, aurEff);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_omor_the_unscarred_orbital_strike_whip::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_omor_the_unscarred()
{
    RegisterHellfireRampartsCreatureAI(boss_omor_the_unscarred);
    RegisterSpellScript(spell_omor_the_unscarred_orbital_strike_target);
    RegisterSpellScript(spell_omor_the_unscarred_orbital_strike_whip);
}
