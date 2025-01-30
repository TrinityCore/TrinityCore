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
#include "GridNotifiers.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum LordKazzakSpells
{
    SPELL_MARK_OF_KAZZAK_SELECTOR  = 243737,
    SPELL_MARK_OF_KAZZAK_PERIODIC  = 243723,
    SPELL_MARK_OF_KAZZAK_DAMAGE    = 243725,
    SPELL_MARK_OF_KAZZAK_EXPLOSION = 243726,
    SPELL_VOID_BOLT                = 243713,
    SPELL_THUNDERCLAP              = 243715,
    SPELL_SHADOW_BOLT_VOLLEY       = 243712,
    SPELL_FRENZY                   = 156598
};

enum LordKazzakTexts
{
    SAY_AGGRO       = 0,
    SAY_KILL        = 1,
    SAY_FRENZY      = 2
};

enum LordKazzakEvents
{
    EVENT_MARK_OF_KAZZAK = 1,
    EVENT_VOID_BOLT,
    EVENT_THUNDERCLAP,
    EVENT_SHADOW_BOLT_VOLLEY
};

// 121818 - Lord Kazzak
struct boss_lord_kazzak_anniversary : public WorldBossAI
{
    boss_lord_kazzak_anniversary(Creature* creature) : WorldBossAI(creature), _frenzyTriggered(false) { }

    void JustAppeared() override
    {
        Talk(SAY_FRENZY);
    }

    void Reset() override
    {
        WorldBossAI::Reset();
        _frenzyTriggered = false;
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_KILL, victim);
    }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 9s);
        events.ScheduleEvent(EVENT_VOID_BOLT, 16400ms);
        events.ScheduleEvent(EVENT_THUNDERCLAP, 11s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 1min + 50s, 1min + 55s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
    {
        if (!_frenzyTriggered && me->HealthBelowPctDamaged(30, damage))
        {
            _frenzyTriggered = true;
            Talk(SAY_FRENZY);
            DoCastSelf(SPELL_FRENZY);
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
                case EVENT_MARK_OF_KAZZAK:
                {
                    DoCast(SPELL_MARK_OF_KAZZAK_SELECTOR);
                    events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 21s, 23s);
                    break;
                }
                case EVENT_VOID_BOLT:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_VOID_BOLT);
                    events.ScheduleEvent(EVENT_VOID_BOLT, 20s, 23s);
                    break;
                }
                case EVENT_THUNDERCLAP:
                {
                    DoCast(SPELL_THUNDERCLAP);
                    events.ScheduleEvent(EVENT_THUNDERCLAP, 25700ms);
                    break;
                }
                case EVENT_SHADOW_BOLT_VOLLEY:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_SHADOW_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 1min + 50s, 1min + 55s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _frenzyTriggered;
};

// 243737 - Mark of Kazzak
class spell_lord_kazzak_mark_of_kazzak_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZZAK_PERIODIC });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MARK_OF_KAZZAK_PERIODIC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_kazzak_mark_of_kazzak_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 243723 - Mark of Kazzak
class spell_lord_kazzak_mark_of_kazzak_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZZAK_DAMAGE, SPELL_MARK_OF_KAZZAK_EXPLOSION });
    }

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetTarget(), SPELL_MARK_OF_KAZZAK_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
        }
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetTarget(), SPELL_MARK_OF_KAZZAK_EXPLOSION, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff,
                .CustomArg = GetTarget()->GetGUID()
            });
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lord_kazzak_mark_of_kazzak_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_lord_kazzak_mark_of_kazzak_periodic::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 243726 - Mark of Kazzak
class spell_lord_kazzak_mark_of_kazzak_explosion : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        ObjectGuid const* explosionTargetGUID = std::any_cast<ObjectGuid>(&GetSpell()->m_customArg);
        if (!explosionTargetGUID)
            return;

        targets.remove_if([explosionTargetGUID](WorldObject const* target) -> bool
        {
            return target->GetGUID() == *explosionTargetGUID;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lord_kazzak_mark_of_kazzak_explosion::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 243715 - Thunderclap
class spell_lord_kazzak_thunderclap : public SpellScript
{
    void HandleAfterHit() const
    {
        if (Aura* aura = GetHitAura())
            aura->SetStackAmount(static_cast<uint8>(GetSpellInfo()->StackAmount));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_lord_kazzak_thunderclap::HandleAfterHit);
    }
};

// 243715 - Thunderclap
class spell_lord_kazzak_thunderclap_aura : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lord_kazzak_thunderclap_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_lord_kazzak_anniversary()
{
    RegisterCreatureAI(boss_lord_kazzak_anniversary);
    RegisterSpellScript(spell_lord_kazzak_mark_of_kazzak_selector);
    RegisterSpellScript(spell_lord_kazzak_mark_of_kazzak_periodic);
    RegisterSpellScript(spell_lord_kazzak_mark_of_kazzak_explosion);
    RegisterSpellAndAuraScriptPair(spell_lord_kazzak_thunderclap, spell_lord_kazzak_thunderclap_aura);
}
