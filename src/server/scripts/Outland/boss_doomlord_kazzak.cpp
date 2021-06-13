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
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_SURPREME    = 2,
    SAY_KILL        = 3,
    SAY_DEATH       = 4,
    EMOTE_FRENZY    = 5,
    SAY_RAND        = 6
};

enum Spells
{
    SPELL_SHADOW_VOLLEY             = 32963,
    SPELL_CLEAVE                    = 31779,
    SPELL_THUNDERCLAP               = 36706,
    SPELL_VOID_BOLT                 = 39329,
    SPELL_MARK_OF_KAZZAK            = 32960,
    SPELL_MARK_OF_KAZZAK_DAMAGE     = 32961,
    SPELL_ENRAGE                    = 32964,
    SPELL_CAPTURE_SOUL              = 32966,
    SPELL_TWISTED_REFLECTION        = 21063,
    SPELL_TWISTED_REFLECTION_HEAL   = 21064,
    SPELL_BERSERK                   = 32965,
};

enum Events
{
    EVENT_SHADOW_VOLLEY         = 1,
    EVENT_CLEAVE                = 2,
    EVENT_THUNDERCLAP           = 3,
    EVENT_VOID_BOLT             = 4,
    EVENT_MARK_OF_KAZZAK        = 5,
    EVENT_ENRAGE                = 6,
    EVENT_TWISTED_REFLECTION    = 7,
    EVENT_BERSERK               = 8
};

struct boss_doomlord_kazzak : public ScriptedAI
{
    boss_doomlord_kazzak(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 6s, 10s);
        _events.ScheduleEvent(EVENT_CLEAVE, 7s);
        _events.ScheduleEvent(EVENT_THUNDERCLAP, 14s, 18s);
        _events.ScheduleEvent(EVENT_VOID_BOLT, 30s);
        _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 25s);
        _events.ScheduleEvent(EVENT_ENRAGE, 1min);
        _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 33s);
        _events.ScheduleEvent(EVENT_BERSERK, 3min);
    }

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* victim) override
    {
        // When Kazzak kills a player (not pets/totems), he regens some health
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        DoCast(me, SPELL_CAPTURE_SOUL);

        Talk(SAY_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        // Return since we have no target
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_VOLLEY:
                    DoCastVictim(SPELL_SHADOW_VOLLEY);
                    _events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 4s, 6s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.ScheduleEvent(EVENT_CLEAVE, 8s, 12s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastVictim(SPELL_THUNDERCLAP);
                    _events.ScheduleEvent(EVENT_THUNDERCLAP, 10s, 14s);
                    break;
                case EVENT_VOID_BOLT:
                    DoCastVictim(SPELL_VOID_BOLT);
                    _events.ScheduleEvent(EVENT_VOID_BOLT, 15s, 18s);
                    break;
                case EVENT_MARK_OF_KAZZAK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_MARK_OF_KAZZAK);
                    _events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 20s);
                    break;
                case EVENT_ENRAGE:
                    Talk(EMOTE_FRENZY);
                    DoCast(me, SPELL_ENRAGE);
                    _events.ScheduleEvent(EVENT_ENRAGE, 30s);
                    break;
                case EVENT_TWISTED_REFLECTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_TWISTED_REFLECTION);
                    _events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15s);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

// 32960 - Mark of Kazzak
class spell_mark_of_kazzak : public AuraScript
{
    PrepareAuraScript(spell_mark_of_kazzak);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZZAK_DAMAGE });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* owner = GetUnitOwner())
            amount = CalculatePct(owner->GetPower(POWER_MANA), 5);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (target->GetPower(POWER_MANA) == 0)
        {
            target->CastSpell(target, SPELL_MARK_OF_KAZZAK_DAMAGE, aurEff);
            // Remove aura
            SetDuration(0);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mark_of_kazzak::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_kazzak::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
    }
};

// 21063 - Twisted Reflection
class spell_twisted_reflection : public AuraScript
{
    PrepareAuraScript(spell_twisted_reflection);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TWISTED_REFLECTION_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        eventInfo.GetActionTarget()->CastSpell(eventInfo.GetActor(), SPELL_TWISTED_REFLECTION_HEAL, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_twisted_reflection::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_boss_doomlordkazzak()
{
    RegisterCreatureAI(boss_doomlord_kazzak);
    RegisterSpellScript(spell_mark_of_kazzak);
    RegisterSpellScript(spell_twisted_reflection);
}
