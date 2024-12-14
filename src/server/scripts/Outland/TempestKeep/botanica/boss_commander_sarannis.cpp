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
#include "SpellInfo.h"
#include "SpellScript.h"
#include "the_botanica.h"

enum Texts
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_ARCANE_DEVASTATION         = 2,
    EMOTE_SUMMON                   = 3,
    SAY_SUMMON                     = 4,
    SAY_DEATH                      = 5
};

enum Spells
{
    SPELL_ARCANE_RESONANCE         = 34794,
    SPELL_ARCANE_DEVASTATION       = 34799,

    SPELL_SUMMON_REINFORCEMENTS    = 34803,
    SPELL_SUMMON_MENDER_1          = 34810,
    SPELL_SUMMON_RESERVIST_1       = 34817,
    SPELL_SUMMON_RESERVIST_2       = 34818,
    SPELL_SUMMON_RESERVIST_3       = 34819
};

enum Events
{
    EVENT_ARCANE_DEVASTATION       = 1,
    EVENT_SUMMON_REINFORCEMENTS
};

uint32 const SummonReinforcementsSpells[] =
{
    SPELL_SUMMON_MENDER_1, SPELL_SUMMON_RESERVIST_1, SPELL_SUMMON_RESERVIST_2, SPELL_SUMMON_RESERVIST_3
};

struct boss_commander_sarannis : public BossAI
{
    boss_commander_sarannis(Creature* creature) : BossAI(creature, DATA_COMMANDER_SARANNIS), _summoned(false) { }

    void Reset() override
    {
        _Reset();
        _summoned = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        // This is definitely just timed, not scheduled instantly when victim has specific amount of stacks of Arcane Resonance
        events.ScheduleEvent(EVENT_ARCANE_DEVASTATION, RAND(10s, 15s, 20s, 25s, 30s, 35s));
        // Timed in heroic (repeatable), on HP PTC in normal (not repeatable)
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON_REINFORCEMENTS, 1min);
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

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_summoned && me->HealthBelowPctDamaged(55, damage) && !IsHeroic())
        {
            _summoned = true;
            events.ScheduleEvent(EVENT_SUMMON_REINFORCEMENTS, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SUMMON_REINFORCEMENTS)
            Talk(SAY_SUMMON);
    }

    // Do not despawn them
    void JustSummoned(Creature* summon) override
    {
        if (me->IsEngaged())
            DoZoneInCombat(summon);
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
                case EVENT_ARCANE_DEVASTATION:
                    // Not always?
                    Talk(SAY_ARCANE_DEVASTATION);
                    // She can cast it if victim has only one stack of Arcane Resonance but can she cast it if victim has no stacks?
                    DoCastVictim(SPELL_ARCANE_DEVASTATION);
                    events.Repeat(RAND(10s, 15s, 20s, 25s, 30s, 35s));
                    break;
                case EVENT_SUMMON_REINFORCEMENTS:
                    Talk(EMOTE_SUMMON);
                    DoCastSelf(SPELL_SUMMON_REINFORCEMENTS);
                    if (IsHeroic())
                        events.Repeat(1min);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _summoned;
};

// 34799 - Arcane Devastation
class spell_commander_sarannis_arcane_devastation : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ARCANE_RESONANCE });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_ARCANE_RESONANCE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_commander_sarannis_arcane_devastation::AfterApply, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 34803 - Summon Reinforcements
class spell_commander_sarannis_summon_reinforcements : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonReinforcementsSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        for (uint32 spells : SummonReinforcementsSpells)
            caster->CastSpell(caster, spells, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_commander_sarannis_summon_reinforcements::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_commander_sarannis()
{
    RegisterBotanicaCreatureAI(boss_commander_sarannis);
    RegisterSpellScript(spell_commander_sarannis_arcane_devastation);
    RegisterSpellScript(spell_commander_sarannis_summon_reinforcements);
}
