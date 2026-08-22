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
 * Timers requires to be revisited
 * Bridge event is NYI
 */

#include "ScriptMgr.h"
#include "mechanar.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellInfo.h"

enum PathaleonTexts
{
    SAY_SPAWN                          = 0,
    SAY_AGGRO                          = 1,
    SAY_SLAY                           = 2,
    SAY_SUMMON                         = 3,
    SAY_DOMINATION                     = 4,
    SAY_ENRAGE                         = 5,
    SAY_DEATH                          = 6
};

enum PathaleonSpells
{
    // Pathaleon - Initial
    SPELL_ETHEREAL_TELEPORT            = 34427,

    // Pathaleon - Combat
    SPELL_SUMMON_NETHER_WRAITHS        = 35284,
    SPELL_MANA_TAP                     = 36021,
    SPELL_ARCANE_TORRENT               = 36022,
    SPELL_DOMINATION                   = 35280,
    SPELL_ARCANE_EXPLOSION             = 15453,

    SPELL_SUICIDE                      = 35301,
    SPELL_FRENZY                       = 36992,

    // Nether Wraith
    SPELL_ARCANE_BOLT                  = 20720,
    SPELL_NETHER_EXPLOSION             = 35058,

    // Scripts
    SPELL_SUMMON_NETHER_WRAITH_LEFT    = 35285,
    SPELL_SUMMON_NETHER_WRAITH_FRONT   = 35287,
    SPELL_SUMMON_NETHER_WRAITH_BACK    = 35288
};

enum PathaleonEvents
{
    EVENT_SUMMON                       = 1,
    EVENT_MANA_TAP,
    EVENT_ARCANE_TORRENT,
    EVENT_DOMINATION,
    EVENT_ARCANE_EXPLOSION,
    EVENT_SUICIDE,
    EVENT_FRENZY
};

// 19220 - Pathaleon the Calculator
struct boss_pathaleon_the_calculator : public BossAI
{
    boss_pathaleon_the_calculator(Creature* creature) : BossAI(creature, DATA_PATHALEON_THE_CALCULATOR), _frenzied(false) { }

    void JustAppeared() override
    {
        Talk(SAY_SPAWN);
        DoCastSelf(SPELL_ETHEREAL_TELEPORT);
        me->SetEmoteState(EMOTE_STATE_READY1H);
    }

    void Reset() override
    {
        _Reset();
        _frenzied = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SUMMON, 20s);
        events.ScheduleEvent(EVENT_MANA_TAP, 10s, 20s);
        events.ScheduleEvent(EVENT_ARCANE_TORRENT, 15s, 35s);
        events.ScheduleEvent(EVENT_DOMINATION, 10s, 20s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 20s, 30s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SUMMON_NETHER_WRAITHS:
                Talk(SAY_SUMMON);
                break;
            case SPELL_DOMINATION:
                Talk(SAY_DOMINATION);
                break;
            case SPELL_FRENZY:
                Talk(SAY_ENRAGE);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_frenzied && me->HealthBelowPctDamaged(20, damage))
        {
            _frenzied = true;
            events.ScheduleEvent(EVENT_SUICIDE, 0s);
            events.ScheduleEvent(EVENT_FRENZY, 0s);
        }
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
                case EVENT_SUMMON:
                    DoCastSelf(SPELL_SUMMON_NETHER_WRAITHS);
                    events.Repeat(50s);
                    break;
                case EVENT_MANA_TAP:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, [](Unit const* unit) { return unit && unit->GetPowerType() == POWER_MANA; }))
                        DoCast(target, SPELL_MANA_TAP);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_ARCANE_TORRENT:
                    DoCastSelf(SPELL_ARCANE_TORRENT);
                    events.Repeat(40s, 50s);
                    break;
                case EVENT_DOMINATION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                        DoCast(target, SPELL_DOMINATION);
                    events.Repeat(30s, 50s);
                    break;
                case EVENT_ARCANE_EXPLOSION:
                    DoCastSelf(SPELL_ARCANE_EXPLOSION);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_SUICIDE:
                    DoCastSelf(SPELL_SUICIDE);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
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
    bool _frenzied;
};

// 21062 - Nether Wraith
struct npc_nether_wraith : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetCorpseDelay(15, true);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(0s, 10s, [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_ARCANE_BOLT);
            task.Repeat(5s, 10s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_NETHER_EXPLOSION);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 35284 - Summon Nether Wraiths
class spell_pathaleon_summon_nether_wraiths : public SpellScript
{
    PrepareSpellScript(spell_pathaleon_summon_nether_wraiths);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_NETHER_WRAITH_LEFT,
            SPELL_SUMMON_NETHER_WRAITH_FRONT,
            SPELL_SUMMON_NETHER_WRAITH_BACK
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(nullptr, SPELL_SUMMON_NETHER_WRAITH_LEFT, true);
        caster->CastSpell(nullptr, SPELL_SUMMON_NETHER_WRAITH_FRONT, true);
        caster->CastSpell(nullptr, SPELL_SUMMON_NETHER_WRAITH_BACK, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_pathaleon_summon_nether_wraiths::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_pathaleon_the_calculator()
{
    RegisterMechanarCreatureAI(boss_pathaleon_the_calculator);
    RegisterMechanarCreatureAI(npc_nether_wraith);
    RegisterSpellScript(spell_pathaleon_summon_nether_wraiths);
}
