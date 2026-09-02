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
 * Chain Lightning repeat timer requires to be revisited
 * The way he casts shocks is quite tricky, requires research and proper implementation. He can cast all 4 shocks in a row with 1 sec
   delay between shocks in normal (sniff) and heroic (video). At the same time he can cast shocks with bigger delays(too short sniff).
   Looks like he can't cast same shock more than once per 'wave'. Looks like shocks are always shuffled before using. Elementals casts
   serverside spells on spawn and on death but looks like on-death spells has nothing to do with shocks. Maybe on-spawn does
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
    SPELL_FROST_SHOCK           = 12548,
    SPELL_FROST_SHOCK_H         = 21401,
    SPELL_FLAME_SHOCK           = 15039,
    SPELL_FLAME_SHOCK_H         = 15616,
    SPELL_SHADOW_SHOCK          = 33620,
    SPELL_SHADOW_SHOCK_H        = 38136,
    SPELL_ARCANE_SHOCK          = 33534,
    SPELL_ARCANE_SHOCK_H        = 38135,

    SPELL_CHAIN_LIGHTNING       = 15659,
    SPELL_CHAIN_LIGHTNING_H     = 15305,

    SPELL_SUMMON_ELEMENTALS     = 33595,

    SPELL_SUMMON_SYTH_FIRE      = 33537,
    SPELL_SUMMON_SYTH_ARCANE    = 33538,
    SPELL_SUMMON_SYTH_FROST     = 33539,
    SPELL_SUMMON_SYTH_SHADOW    = 33540
};

enum SythEvents
{
    EVENT_FROST_SHOCK           = 1,
    EVENT_FLAME_SHOCK,
    EVENT_SHADOW_SHOCK,
    EVENT_ARCANE_SHOCK,
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

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_FROST_SHOCK, 6s);
        events.ScheduleEvent(EVENT_FLAME_SHOCK, 2s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 8s);
        events.ScheduleEvent(EVENT_ARCANE_SHOCK, 4s);
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 8s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            summoned->AI()->AttackStart(target);

        summons.Summon(summoned);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SUMMON_ELEMENTALS)
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

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        if (Creature* lakka = me->FindNearestCreature(NPC_LAKKA, 500.0f, true))
            lakka->AI()->Talk(SAY_LAKKA_FREE);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_FROST_SHOCK:
                DoCastVictim(DUNGEON_MODE(SPELL_FROST_SHOCK, SPELL_FROST_SHOCK_H));
                events.Repeat(10s, 15s);
                break;
            case EVENT_FLAME_SHOCK:
                DoCastVictim(DUNGEON_MODE(SPELL_FLAME_SHOCK, SPELL_FLAME_SHOCK_H));
                events.Repeat(10s, 15s);
                break;
            case EVENT_SHADOW_SHOCK:
                DoCastVictim(DUNGEON_MODE(SPELL_SHADOW_SHOCK, SPELL_SHADOW_SHOCK_H));
                events.Repeat(10s, 15s);
                break;
            case EVENT_ARCANE_SHOCK:
                DoCastVictim(DUNGEON_MODE(SPELL_ARCANE_SHOCK, SPELL_ARCANE_SHOCK_H));
                events.Repeat(10s, 15s);
                break;
            case EVENT_CHAIN_LIGHTNING:
                DoCastVictim(DUNGEON_MODE(SPELL_CHAIN_LIGHTNING, SPELL_CHAIN_LIGHTNING_H));
                events.Repeat(20s, 35s);
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
        caster->CastSpell(nullptr, SPELL_SUMMON_SYTH_ARCANE, true);
        caster->CastSpell(nullptr, SPELL_SUMMON_SYTH_FIRE, true);
        caster->CastSpell(nullptr, SPELL_SUMMON_SYTH_FROST, true);
        caster->CastSpell(nullptr, SPELL_SUMMON_SYTH_SHADOW, true);
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
