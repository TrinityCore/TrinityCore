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
#include "Containers.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ruins_of_ahnqiraj.h"

enum MoamTexts
{
    EMOTE_AGGRO                 = 0,
    EMOTE_MANA_FULL             = 1,
    EMOTE_ENERGIZE              = 2
};

enum MoamSpells
{
    // Combat
    SPELL_TRAMPLE               = 15550,
    SPELL_DRAIN_MANA            = 25676,
    SPELL_ARCANE_ERUPTION       = 25672,
    SPELL_SUMMON_MANA_FIENDS    = 25684,
    SPELL_ENERGIZE              = 25685,

    // Misc
    SPELL_ZERO_MANA_FULL_HEALTH = 23777,
    SPELL_DROP_OBSIDIAN         = 27630,

    // Scripts
    SPELL_SUMMON_MANA_FIEND_1   = 25681,
    SPELL_SUMMON_MANA_FIEND_2   = 25682,
    SPELL_SUMMON_MANA_FIEND_3   = 25683,
    SPELL_DRAIN_MANA_EFFECT     = 25671,
    SPELL_DRAIN_MANA_VISUAL     = 26639
};

enum MoamEvents
{
    EVENT_TRAMPLE               = 1,
    EVENT_DRAIN_MANA,
    EVENT_STONE_PHASE,
    EVENT_ARCANE_ERUPTION
};

enum MoamMisc
{
    MAX_MANA_FIENDS             = 3
};

// 15340 - Moam
struct boss_moam : public BossAI
{
    boss_moam(Creature* creature) : BossAI(creature, DATA_MOAM), _deadManaFiendCount(0) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ZERO_MANA_FULL_HEALTH);
    }

    void Reset() override
    {
        _Reset();
        _deadManaFiendCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(EMOTE_AGGRO);

        events.ScheduleEvent(EVENT_TRAMPLE, 10s, 25s);
        events.ScheduleEvent(EVENT_DRAIN_MANA, 6s);
        events.ScheduleEvent(EVENT_STONE_PHASE, 90s);
        events.ScheduleEvent(EVENT_ARCANE_ERUPTION, 1s);
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        _deadManaFiendCount++;

        if (_deadManaFiendCount == MAX_MANA_FIENDS)
        {
            me->RemoveAurasDueToSpell(SPELL_ENERGIZE);
            _deadManaFiendCount = 0;
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_ARCANE_ERUPTION:
                // Is there a spell for that? Maybe Zero Mana/Full Health but with a check to prevent setting full health if creature is in combat?
                me->SetPower(POWER_MANA, 0);
                Talk(EMOTE_MANA_FULL);
                break;
            case SPELL_SUMMON_MANA_FIENDS:
                DoCastSelf(SPELL_ENERGIZE);
                Talk(EMOTE_ENERGIZE);
                break;
            default:
                break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_ZERO_MANA_FULL_HEALTH);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastSelf(SPELL_DROP_OBSIDIAN, true);
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
                case EVENT_TRAMPLE:
                    DoCastSelf(SPELL_TRAMPLE);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_DRAIN_MANA:
                    DoCastSelf(SPELL_DRAIN_MANA);
                    events.Repeat(6s);
                    break;
                case EVENT_STONE_PHASE:
                    _deadManaFiendCount = 0;
                    DoCastSelf(SPELL_SUMMON_MANA_FIENDS);
                    events.Repeat(130s);
                    break;
                case EVENT_ARCANE_ERUPTION:
                    if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                        DoCastSelf(SPELL_ARCANE_ERUPTION);
                    events.Repeat(1s);
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
    uint8 _deadManaFiendCount;
};

// 25684 - Summon Mana Fiends
class spell_moam_summon_mana_fiends : public SpellScript
{
    PrepareSpellScript(spell_moam_summon_mana_fiends);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_MANA_FIEND_1,
            SPELL_SUMMON_MANA_FIEND_2,
            SPELL_SUMMON_MANA_FIEND_3
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_MANA_FIEND_1, true);
        caster->CastSpell(caster, SPELL_SUMMON_MANA_FIEND_2, true);
        caster->CastSpell(caster, SPELL_SUMMON_MANA_FIEND_3, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_moam_summon_mana_fiends::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 25685 - Energize
class spell_moam_energize : public AuraScript
{
    PrepareAuraScript(spell_moam_energize);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (GetTarget()->GetPower(POWER_MANA) == GetTarget()->GetMaxPower(POWER_MANA))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_moam_energize::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

// 25676 - Drain Mana
class spell_moam_drain_mana : public SpellScript
{
    PrepareSpellScript(spell_moam_drain_mana);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAIN_MANA_EFFECT });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, [](WorldObject* target)
        {
            return target->IsPlayer() && target->ToPlayer()->GetPowerType() == POWER_MANA;
        }, 6);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRAIN_MANA_EFFECT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_moam_drain_mana::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_moam_drain_mana::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 25671 - Drain Mana
// 25755 - Drain Mana
class spell_moam_drain_mana_effect : public SpellScript
{
    PrepareSpellScript(spell_moam_drain_mana_effect);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAIN_MANA_VISUAL });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_DRAIN_MANA_VISUAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_moam_drain_mana_effect::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_moam()
{
    RegisterAQ20CreatureAI(boss_moam);
    RegisterSpellScript(spell_moam_summon_mana_fiends);
    RegisterSpellScript(spell_moam_energize);
    RegisterSpellScript(spell_moam_drain_mana);
    RegisterSpellScript(spell_moam_drain_mana_effect);
}
