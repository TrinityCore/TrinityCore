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
#include "SpellScript.h"
#include "SpellInfo.h"
#include "sethekk_halls.h"

enum SythTexts
{
    SAY_SUMMON                  = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum SythSpells
{
    SPELL_FROST_SHOCK           = 21401,
    SPELL_FLAME_SHOCK           = 34354,
    SPELL_SHADOW_SHOCK          = 30138,
    SPELL_ARCANE_SHOCK          = 37132,

    SPELL_CHAIN_LIGHTNING       = 15659,

    SPELL_SUMMON_ELEMENTALS     = 33595,

    SPELL_SUMMON_SYTH_FIRE      = 33537,
    SPELL_SUMMON_SYTH_ARCANE    = 33538,
    SPELL_SUMMON_SYTH_FROST     = 33539,
    SPELL_SUMMON_SYTH_SHADOW    = 33540
};

enum SythEvents
{
    EVENT_FLAME_SHOCK           = 1,
    EVENT_ARCANE_SHOCK,
    EVENT_FROST_SHOCK,
    EVENT_SHADOW_SHOCK,
    EVENT_CHAIN_LIGHTNING,
    EVENT_SUMMON
};

enum SythMisc
{
    NPC_LAKKA                   = 18956,
    SAY_LAKKA_FREE              = 1
};

enum SythPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_90,
    PHASE_HEALTH_55,
    PHASE_HEALTH_10
};

// 18472 - Darkweaver Syth
struct boss_darkweaver_syth : public BossAI
{
    boss_darkweaver_syth(Creature* creature) : BossAI(creature, DATA_DARKWEAVER_SYTH), _phase(PHASE_NONE) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_FLAME_SHOCK, 2s);
        events.ScheduleEvent(EVENT_ARCANE_SHOCK, 4s);
        events.ScheduleEvent(EVENT_FROST_SHOCK, 6s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 8s);
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 10s, 15s);

        Talk(SAY_AGGRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        if (Creature* lakka = me->FindNearestCreature(NPC_LAKKA, 500.0f, true))
            lakka->AI()->Talk(SAY_LAKKA_FREE);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            summoned->AI()->AttackStart(target);

        summons.Summon(summoned);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SUMMON_ELEMENTALS)
            Talk(SAY_SUMMON);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_90 && me->HealthBelowPctDamaged(90, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }

        if (_phase < PHASE_HEALTH_55 && me->HealthBelowPctDamaged(55, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }

        if (_phase < PHASE_HEALTH_10 && me->HealthBelowPctDamaged(10, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_FLAME_SHOCK:
                DoCastVictim(SPELL_FLAME_SHOCK);
                events.Repeat(10s, 15s);
                break;
            case EVENT_ARCANE_SHOCK:
                DoCastVictim(SPELL_ARCANE_SHOCK);
                events.Repeat(10s, 15s);
                break;
            case EVENT_FROST_SHOCK:
                DoCastVictim(SPELL_FROST_SHOCK);
                events.Repeat(10s, 15s);
                break;
            case EVENT_SHADOW_SHOCK:
                DoCastVictim(SPELL_SHADOW_SHOCK);
                events.Repeat(10s, 15s);
                break;
            case EVENT_CHAIN_LIGHTNING:
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                events.Repeat(25s);
                break;
            case EVENT_SUMMON:
                DoCastSelf(SPELL_SUMMON_ELEMENTALS);
                break;
            default:
                break;
        }
    }

private:
    uint8 _phase;
};

// 33595 - Summon Elementals
class spell_darkweaver_syth_summon_elementals : public SpellScript
{
    PrepareSpellScript(spell_darkweaver_syth_summon_elementals);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_SYTH_ARCANE,
            SPELL_SUMMON_SYTH_FIRE,
            SPELL_SUMMON_SYTH_FROST,
            SPELL_SUMMON_SYTH_SHADOW
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_SYTH_ARCANE, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
        caster->CastSpell(caster, SPELL_SUMMON_SYTH_FIRE, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
        caster->CastSpell(caster, SPELL_SUMMON_SYTH_FROST, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
        caster->CastSpell(caster, SPELL_SUMMON_SYTH_SHADOW, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_darkweaver_syth_summon_elementals::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_darkweaver_syth()
{
    RegisterSethekkHallsCreatureAI(boss_darkweaver_syth);
    RegisterSpellScript(spell_darkweaver_syth_summon_elementals);
}
